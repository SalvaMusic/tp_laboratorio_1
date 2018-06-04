#include <stdio.h>
#include <stdlib.h>
#include "emovie.h"
#include "utn.h"
#include "funciones.h"
#define QTY 10


int main()
{
    EMovie* arrayPunterosEMovie [QTY];
    int qtyActualArrayPunterosEMovie = 1;
    int id;


    char seguir = 's';
    int opcion = 0;

    funciones_cargarArchivo(arrayPunterosEMovie,&qtyActualArrayPunterosEMovie,QTY,"archivoPeliculas.bin");
    arrayPunterosEMovie [0] = eMovie_newParametros("Ralph el Demoledor","Comica",101,"La vida dentro de los videojuegos",8,"http://culto.latercera.com/wp-content/uploads/2018/02/00000000000000000banner-rompe-ralph-1-900x600.jpg",0);

    while(seguir == 's')
    {
        system("cls");
        printf("\n\tTP 3 PELICULAS\n");
        getValidInt("\n1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar Pelicula\n4- Generar pagina web\n5- Salir\n\nINGRESE UNA OPCION: ","Ingrese un numero correcto!\n",&opcion,1,5,2);

        switch(opcion)
        {
            case 1:
                printf("\n\tAGREGAR PELICULA\n");
                eMovie_agregarPelicula(arrayPunterosEMovie,&qtyActualArrayPunterosEMovie);
                system("pause");
                break;
            case 2:
                printf("\n\tBORRAR PELICULA\n");
                if (!eMovie_mostrarPeliculas(arrayPunterosEMovie,qtyActualArrayPunterosEMovie))
                {
                    getValidInt("\nIngrese ID: ", "\nCaractres invalidos!\n", &id, 0, 100, 2);
                    eMovie_bajarPelicula(arrayPunterosEMovie,&qtyActualArrayPunterosEMovie,id);
                }
                system("pause");
                break;
            case 3:
                printf("\n\tMODIFICAR PELICULA\n");
                if (!eMovie_mostrarPeliculas(arrayPunterosEMovie,qtyActualArrayPunterosEMovie))
                {
                    getValidInt("\nIngrese ID: ", "\nCaractres invalidos!\n", &id, 0, 100, 2);
                    eMovie_modificarPelicula(arrayPunterosEMovie,&qtyActualArrayPunterosEMovie,id);
                }
                system("pause");
               break;
            case 4:
                printf("\n\tGENERAR PAGINA HTML\n");
                funciones_GenerarPaginaWeb(arrayPunterosEMovie,&qtyActualArrayPunterosEMovie,QTY,"Pagina Web.html");
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    funciones_guardarArchivo(arrayPunterosEMovie,qtyActualArrayPunterosEMovie,"archivoPeliculas.bin");


    return 0;
}
