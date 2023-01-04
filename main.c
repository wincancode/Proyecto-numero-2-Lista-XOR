#include <stdio.h>
#include "xlist.h"




int main() {

    List* L = crearLista();
    int opcion = -1;

    printf("\nEste programa permite trabajar con una unica lista a la vez.\n");

    while (opcion != 13)
    {

        int elemento = 0;
        printf("\n\nIngrese la operacion a realizar.");
        printf("\n1. Inicializar la lista");
        printf("\n2. Verificar si la lista esta vacia");
        printf("\n3. Insertar un elemento al inicio de la lista");
        printf("\n4. Insertar un elemento al final de la lista");
        printf("\n5. Insertar un elemento en la lista de forma ordenada");
        printf("\n6. Buscar un elemento en la lista");
        printf("\n7. Sacar un elemento al inicio de la lista");
        printf("\n8. Sacar un elemento al final de la lista");
        printf("\n9. Sacar la primera ocurrencia de un elemento");
        printf("\n10. Listar de inicio a fin");
        printf("\n11. Listar de fin a inicio");
        printf("\n12. Obtener la cantidad de elementos de la lista");
        printf("\n13. Salir del programa\n");


        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: {
            Inicializar(L);
            break;
        }

        case 2: {
            if (esVacia(L))
                printf("La lista esta vacia");
            else
                printf("La lista no esta vacia");

            break;
        }

        case 3: {
            printf("\nIngrese el elemento que desea insertar.\n");

            scanf("%d", &elemento);

            if (insertarPrincipio(L, elemento) == 1)
                printf("Se logro insertar el elemento");
            else
                printf("No se logro insertar el elemento.");
            break;
        }

        case 4: {
            printf("\nIngrese el elemento que desea insertar.\n");

            scanf("%d", &elemento);

            if (insertarFinal(L, elemento) == 1)
                printf("Se logro insertar el elemento");
            else
                printf("No se logro insertar el elemento.");
            break;
        }

        case 5: {
            printf("\nIngrese el elemento que desea insertar.\n");

            scanf("%d", &elemento);

            if (insertarOrden(L, elemento) == 1)
                printf("Se logro insertar el elemento");
            else
                printf("No se logro insertar el elemento.");
            break;
        }

        case 6: {
            printf("\nIngrese el elemento a buscar\n");
            scanf("%d", &elemento);
            if (buscar(L, elemento))
                printf("el elemento se encontro");
            else
                printf("el elemento no se encontro");
            break;
        }

        case 7: {
            if (sacarPrincipio(L, &elemento))
                printf("el elemento al inicio de la lista fue: %d.", elemento);
            else
                printf("No se pudo sacar el elemento al inicio de la lista.");
            break;
        }

        case 8: {
            if (sacarFinal(L, &elemento))
                printf("el elemento al final de la lista fue: %d.", elemento);
            else
                printf("No se pudo sacar el elemento al final de la lista.");
            break;
        }

        case 9: {
            printf("\nIngrese el elemento a sacar.\n");
            scanf("%d", &elemento);
            if (sacarPrimeraOcurrencia(L, elemento))
                printf("\nSe logro sacar la primera ocurrencia del elemento.");
            else
                printf("\nNo se logro sacar la primera ocurrencia del elemento.");
            break;
        }

        case 10: {
            listarInicioAFinal(L);
            break;
        }

        case 11: {
            listarFinalAInicio(L);
            break;
        }

        case 12: {
            printf("\nLa lista tiene: %d elementos", cantidadElementos(L));
            break;
        }

        case 13: {
            printf("\nGracias por utilizar el programa!");
            break;
        }

        default: {
            printf("\n Ha ingresado una opcion no valida.");
            break;
        }
        }
    }

}