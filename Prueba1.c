#include <stdio.h>
#include "xlist.h"


int main() {
    List* L = crearLista();
    Inicializar(L);
    listarFinalAInicio(L);


    for (int i = 1; i < 9; i++)
    {
        insertarFinal(L, i);
    }
    insertarPrincipio(L, 0);



    listarFinalAInicio(L);
    printf("\n\n");
    listarInicioAFinal(L);

    printf("\n\n");

    printf("cantidad de elementos: %d\n", cantidadElementos(L));

    printf("\n\n");

    int inicio;
    sacarPrincipio(L, &inicio);
    printf("Inicio: %d\n", inicio);
    listarInicioAFinal(L);

    printf("\n\n");

    int final;
    sacarFinal(L, &final);
    printf("Final: %d\n", final);
    listarInicioAFinal(L);

    printf("\n\n");

    Inicializar(L);
    listarInicioAFinal(L);

    for (int i = 1; i < 9; i++)
    {
        insertarFinal(L, i);
    }
    insertarPrincipio(L, 0);


    printf("\n\n");
    listarInicioAFinal(L);
    printf("Buscar numero 3: %d\n", buscar(L, 3));
    printf("Buscar numero 100: %d\n", buscar(L, 100));
    printf("Buscar numero 8: %d\n", buscar(L, 8));
    printf("Buscar numero 0: %d\n", buscar(L, 0));


    printf("\n\n");

    printf("\nsacar elemento 5");
    sacarPrimeraOcurrencia(L, 5);
    listarInicioAFinal(L);
    listarFinalAInicio(L);

    printf("\nsacar elemento 0");
    sacarPrimeraOcurrencia(L, 0);
    listarInicioAFinal(L);
    listarFinalAInicio(L);

    printf("\nsacar elemento 8");
    sacarPrimeraOcurrencia(L, 8);
    listarInicioAFinal(L);
    listarFinalAInicio(L);


    printf("\n\n");
    printf("\ninsertar ordenado 4");
    insertarOrden(L, 4);
    listarInicioAFinal(L);
    listarFinalAInicio(L);
    
    printf("\ninsertar ordenado 5");
    insertarOrden(L, 5);
    listarInicioAFinal(L);
    listarFinalAInicio(L);

    printf("\ninsertar ordenado 8");
    insertarOrden(L, 8);
    listarInicioAFinal(L);
    listarFinalAInicio(L);

    printf("\ninsertar ordenado 20");
    insertarOrden(L, 20);
    listarInicioAFinal(L);
    listarFinalAInicio(L);

    printf("\ninsertar ordenado -2");
    insertarOrden(L, -2);
    listarInicioAFinal(L);
    listarFinalAInicio(L);

    printf("\ninsertar ordenado -1");
    insertarOrden(L, -1);
    listarInicioAFinal(L);
    listarFinalAInicio(L);
}