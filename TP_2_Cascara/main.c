#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "funciones.h"
#define QTY 20

int main()
{
    EPersona arrayPersona [QTY];
    char seguir='s';
    int opcion=0;
    int id;

    persona_init(arrayPersona,QTY);

    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        getValidInt("\nIngrese una opcion: ", "\nError! Ingrese una opcion valida\n", &opcion,1,5,3);

        switch(opcion)
        {
            case 1:
                printf("\nAGREGAR PERSONA:\n");
                persona_alta(arrayPersona,QTY);
                printf("\n");
                break;
            case 2:
                printf("\nBORRAR PERSONA:\n");
                if (!persona_mostrar(arrayPersona,QTY)){
                    getValidInt("\nIngrese el ID: ", "\nError! Ingrese un numero valido", &id,0,QTY,2);
                    persona_baja(arrayPersona,QTY,id);
                }
                printf("\n");
                break;
            case 3:
                printf("\nLISTADO DE PERSONAS:\n");
                persona_ordenar(arrayPersona,QTY,0);
                persona_mostrar(arrayPersona,QTY);
                printf("\n");
                break;
            case 4:
                printf("\nGRAFICO POR EDADES:\n");
                persona_graficar(arrayPersona,QTY);
                printf("\n");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
