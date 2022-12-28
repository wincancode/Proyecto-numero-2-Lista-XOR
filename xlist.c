#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "xlist.h"

typedef struct node node;

typedef struct List List;


//funcion auxiliar para realizar xor entre elementos al no poder hacerlos directamente
inline node* XOR(node* a, node* b) {
    return (node*)((uintptr_t)a ^ (uintptr_t)b);
}

List* crearLista(void) {
    List* L;

    if ((L = (List*)malloc(sizeof(List))) == NULL) {
        printf("error en malloc");
        return NULL;
    }

    L->head = L->end = NULL;

    return L;
}

int Inicializar(List* L) {
    if (esVacia(L)) return 1;

    while (L->head->xnext) {

        node* OldHead = L->head;

        L->head = L->head->xnext;

        L->head->xnext = XOR(OldHead, L->head->xnext);

        free(OldHead);
    }

    free(L->head);

    L->end = L->head = NULL;

    return 1;

}

int esVacia(List* L) {
    if (L->head == NULL)
        return 1;
    return 0;
}

int insertarPrincipio(List* L, int e) {
    node* NewNode;
    if ((NewNode = (node*)malloc(sizeof(node))) == NULL)
        return 0;

    NewNode->data = e;

    NewNode->xnext = L->head;

    if (L->head) {
        L->head->xnext = XOR(NewNode, L->head->xnext);
    }
    else {
        L->end = NewNode;
    }

    L->head = NewNode;

    return 1;
}

int insertarFinal(List* L, int e) {
    node* NewNode;
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
    if (e <= L->head->data)
        return insertarPrincipio(L, e);
    if (e >= L->end->data)
        return insertarFinal(L, e);


    node* NewNode;
    if ((NewNode = (node*)malloc(sizeof(node))) == NULL)
        return 0;

    NewNode->data = e;

    node* Actual = L->head;
    node* Prev = NULL;
    node* next;

    while (Actual) {

        if (Actual->data >= e) {
            if (Prev)
                Prev->xnext = XOR(XOR(Prev->xnext, Actual), NewNode);
            if (Actual)
                Actual->xnext = XOR(XOR(Actual->xnext, Prev), NewNode);
            if (Actual && Prev)
                NewNode->xnext = XOR(Actual, Prev);
            return 1;
        }

        next = XOR(Actual->xnext, Prev);
        Prev = Actual;
        Actual = next;
    }
}

int buscar(List* L, int e) {
    node* Actual = L->head;
    node* Prev = NULL;
    node* next;

    while (Actual) {
        if (Actual->data == e) return 1;
        next = XOR(Actual->xnext, Prev);
        Prev = Actual;
        Actual = next;
    }

    return 0;
}

int sacarPrincipio(List* L, int* e) {
    (*e) = L->head->data;
    node* OldHead = L->head;

    L->head = L->head->xnext;

    L->head->xnext = XOR(OldHead, L->head->xnext);

    free(OldHead);

    return 1;
}

int sacarFinal(List* L, int* e) {
    (*e) = L->end->data;
    node* OldEnd = L->end;

    L->end = L->end->xnext;

    L->end->xnext = XOR(OldEnd, L->end->xnext);

    free(OldEnd);

    return 1;
}

int sacarPrimeraOcurrencia(List* L, int e) {
    node* Actual = L->head;
    node* Prev = NULL;
    node* next;

    while (Actual) {
        if (Actual->data == e) {

            node* NextNodeAux = XOR(Actual->xnext, Prev);

            if (Prev)
                Prev->xnext = XOR(XOR(Prev->xnext, Actual), NextNodeAux);
            else
                L->head = NextNodeAux;

            if (NextNodeAux)
                NextNodeAux->xnext = XOR(XOR(NextNodeAux->xnext, Actual), Prev);
            else
                L->end = Prev;

            free(Actual);
            break;
        }

        next = XOR(Actual->xnext, Prev);
        Prev = Actual;
        Actual = next;
    }

    return 1;
}

inline void PrintListAux(node* Actual) {
    printf("\n");

    printf("NULL");

    if (Actual == NULL)
        return;

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


