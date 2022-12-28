#ifndef HEAD_H_
#define HEAD_H_



typedef struct node {
    int data;
    struct node* xnext;
} node;

typedef struct List {
    node* end;
    node* head;
} List;

//funcion auxiliar para realizar xor entre elementos al no poder hacerlos directamente
node* XOR(node* a, node* b);

//Crea una lista desde cero y le asigna memoria.
List* crearLista(void);

//Inicializa una lista vacia, si tiene elementos, se eliminan todos para inicializarlo
int Inicializar(List* L);

//Devuelve 1 si esta vacia, 0 si no. 
int esVacia(List* L);

//Inserta el elemento enviado al inicio de la lista
int insertarPrincipio(List* L, int e);

//Inserta el elemento enviado al final de la lista
int insertarFinal(List* L, int e);

//Inserta el elemento enviado de forma ordenada en la lista
int insertarOrden(List* L, int e);

//Busca la primera ocurrencia del elemento recibido. Devuelve 1 si es encontrado, 0 si no.
int buscar(List* L, int e);

//Saca el primer elemento de la lista. Devuelve el valor del elemento por referencia a la direccion recibida y elimina el nodo.
int sacarPrincipio(List* L, int* e);

//Saca el ultimo elemento de la lista. Devuelve el valor del elemento por referencia a la direccion recibida y elimina el nodo.
int sacarFinal(List* L, int* e);

//Saca la primera ocurrencia del elemento en la lista. Unicamente elimina el nodo.
int sacarPrimeraOcurrencia(List* L, int e);

//Auxiliar para imprimir la lista. Recibe el valor desde el cual se desea iniciar, ya sea el final o el inicio, e imprime a partir de ahi.
void PrintListAux(node* Actual);

//Imprime la lista de inicio a fin.
void listarInicioAFinal(List* L);

//Imprime la lista de fin a inicio.
void listarFinalAInicio(List* L);

//Devuelve la cantidad de elementos de la lista.
int  cantidadElementos(List* L);




#endif
