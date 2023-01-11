#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "xlist.h"

typedef struct node node;

typedef struct List List;

inline node* XOR(node* a, node* b) {
    return (node*)((uintptr_t)a ^ (uintptr_t)b);
}

List* crearLista(void) {
    List* L;

    //Se asigna la memoria a la vez que se verifica si se ha logrado realizar la propia asignación, enviando un error en caso contrario.
    if ((L = (List*)malloc(sizeof(List))) == NULL) {
        printf("\nError en malloc\n");
        return NULL;
    }

    L->head = L->end = NULL;

    return L;
}

int Inicializar(List* L) {
    if (esVacia(L)) return 1;

    //se recorre la lista liberando cada uno de los nodos hasta que exista solo un nodo. 
    while (L->head->xnext) {

        node* OldHead = L->head;

        L->head = L->head->xnext;

        L->head->xnext = XOR(OldHead, L->head->xnext);

        free(OldHead);
    }

    //Se libera el nodo restante y se igualan los punteros a cabeza y cola a nulo.
    free(L->head);

    L->end = L->head = NULL;

    return 1;
}

inline int esVacia(List* L) {
    return L->head ? 0 : 1;
}

int insertarPrincipio(List* L, int e) {
    node* NewNode;

    //Se asigna memoria a NewNode
    if ((NewNode = (node*)malloc(sizeof(node))) == NULL) {
        printf("\nError en  malloc.\n");
        return 0;
    }

    NewNode->data = e;

    //Se da que el nodo Xnext de NewNode sera la anterior cabeza. En caso de que no exista cabeza, se apuntara a nulo, como es de esperarse.
    NewNode->xnext = L->head;

    //Si existia una cabeza anterior, se corrige su Xnext al correspondiente al agregarle un nodo anterior. 
    if (L->head) {
        L->head->xnext = XOR(NewNode, L->head->xnext);
    }
    else { //Si no existe cabeza anterior, entonces el nuevo nodo sera el unico, y el final tambien debe de apuntar a el.
        L->end = NewNode;
    }

    //Finalmente la cabeza de la lista apunta al nuevo nodo.
    L->head = NewNode;

    return 1;
}

int insertarFinal(List* L, int e) {
    node* NewNode;

    //Un codigo similar en esencia al de InsertarPrincipio.

    if ((NewNode = (node*)malloc(sizeof(node))) == NULL)
        return 0;

    NewNode->data = e;

    NewNode->xnext = L->end;

    if (L->end) {
        L->end->xnext = XOR(NewNode, L->end->xnext);
    }
    else {
        L->head = NewNode;
    }
    L->end = NewNode;

    return 1;
}

int insertarOrden(List* L, int e) {

    if (esVacia(L) || e <= L->head->data)
        return insertarPrincipio(L, e);
    if (e >= L->end->data)
        return insertarFinal(L, e);


    node* NewNode;

    if ((NewNode = (node*)malloc(sizeof(node))) == NULL)
        return 0;

    NewNode->data = e;

    //Se inicia desde el nodo siguiente a la cabeza, al haberse verificado ya que no se debe ingresar en la propia cabeza.
    node* Actual = L->head->xnext;
    node* Prev = L->head;
    node* next;

    while (Actual) {

        //Una vez se encuentra la posicion en la que se debe ingresar el valor, se reorganizan los punteros para permitir ingresar el elemento.
        if (Actual->data >= e) {

            Prev->xnext = XOR(XOR(Prev->xnext, Actual), NewNode);

            Actual->xnext = XOR(XOR(Actual->xnext, Prev), NewNode);

            NewNode->xnext = XOR(Actual, Prev);

            return 1;
        }

        next = XOR(Actual->xnext, Prev);
        Prev = Actual;
        Actual = next;
    }
}

int buscar(List* L, int e) {
    if (esVacia(L)) return 0;

    node* Actual = L->head;
    node* Prev = NULL;
    node* next;
    int i = 0;
    //Unicamente se recorre la lista hasta encontrar el elemento.
    while (Actual) {
        i++;
        if (Actual->data == e) {
            printf("\nEl elemento se encuentra en la posicion %d\n", i);
            return 1;
        }
        next = XOR(Actual->xnext, Prev);
        Prev = Actual;
        Actual = next;
    }

    return 0;
}

int sacarPrincipio(List* L, int* e) {
    if (esVacia(L)) return 0;

    (*e) = L->head->data;

    //Se verifica si existe un unico nodo.
    if (L->head == L->end) {
        free(L->head);
        L->head = L->end = NULL;
        return 1;
    }

    //Se reacomodan los punteros para hacer que el siguiente a la cabeza sea la nueva cabeza.
    node* OldHead = L->head;

    L->head = L->head->xnext;

    L->head->xnext = XOR(OldHead, L->head->xnext);

    free(OldHead);

    return 1;
}

int sacarFinal(List* L, int* e) {
    if (esVacia(L)) return 0;

    //Misma estrategia a la utilizada en SacarPrincipio.
                                                            
    (*e) = L->end->data;

    if (L->head == L->end) {
        free(L->end);
        L->head = L->end = NULL;
        return 1;
    }

    node* OldEnd = L->end;

    L->end = L->end->xnext;

    L->end->xnext = XOR(OldEnd, L->end->xnext);

    free(OldEnd);

    return 1;
}

int sacarPrimeraOcurrencia(List* L, int e) {
    if (esVacia(L)) return 0;

    //Se verifica si el nodo a sacar se encuentra en la cabeza.
    if (L->head->data == e) {
        return sacarPrincipio(L, &e);
    }

    node* Actual = L->head;
    node* Prev = NULL;
    node* next;

    while (Actual) {
        if (Actual->data == e) {

            //Se obtiene el nodo siguiente al actual y se reacomodan los nodos para aislar y liberar el que se debe sacar.
            node* NextNodeAux = XOR(Actual->xnext, Prev);

            Prev->xnext = XOR(XOR(Prev->xnext, Actual), NextNodeAux);

            if (NextNodeAux)
                NextNodeAux->xnext = XOR(XOR(NextNodeAux->xnext, Actual), Prev);
            else
                L->end = Prev;

            free(Actual);
            return 1;
        }

        next = XOR(Actual->xnext, Prev);
        Prev = Actual;
        Actual = next;
    }

    return 0;
}

inline void PrintListAux(node* Actual) {
    printf("\n");

    printf("NULL");

    if (Actual == NULL) {
        printf("\n");
        return;
    }

    node* Prev = NULL;
    node* next;

    printf(" <- ");

    while (Actual) {
        printf(" [%d] -", Actual->data);
        next = XOR(Actual->xnext, Prev);
        Prev = Actual;
        Actual = next;
    }

    printf("> NULL");
    printf("\n");
}

void listarInicioAFinal(List* L) {
    PrintListAux(L->head);
}

void listarFinalAInicio(List* L) {
    PrintListAux(L->end);
}

int  cantidadElementos(List* L) {
    if (esVacia(L)) return 0;

    node* Actual = L->head;
    node* Prev = NULL;
    node* next;
    int cantidad = 0;

    while (Actual) {
        cantidad++;
        next = XOR(Actual->xnext, Prev);
        Prev = Actual;
        Actual = next;
    }

    return cantidad;
}


