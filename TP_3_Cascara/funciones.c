#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emovie.h"
#include "utn.h"
#include "funciones.h"

int funciones_cargarArchivo(EMovie** arrayEMovie, int* ocupado, int qtyMovieTotal, char* path)
{

    int retorno = -1;
    FILE* pFile;
    EMovie* auxiliarEMovie = eMovie_new();
    pFile = fopen(path,"rb");
    if(pFile != NULL && arrayEMovie != NULL && qtyMovieTotal > 0 && *ocupado >= 0 &&  qtyMovieTotal > *ocupado)
    {
        retorno = 0;
       fread(auxiliarEMovie, sizeof(EMovie), 1, pFile);
        while(!feof(pFile))
        {
                arrayEMovie[*ocupado] = eMovie_newParametros(auxiliarEMovie->titulo, auxiliarEMovie->genero, auxiliarEMovie->duracion,
                                                               auxiliarEMovie->descripcion, auxiliarEMovie->puntaje, auxiliarEMovie->linkImagen, auxiliarEMovie->idEMovie);

                if(fread(auxiliarEMovie, sizeof(EMovie), 1, pFile))
                    (*ocupado)++;

        }
        fclose(pFile);
        retorno = 0;

    }
    fclose(pFile);
    return retorno;
}


int funciones_guardarArchivo(EMovie** arrayEMovie, int ocupado, char* path)
{
    FILE *pFile;
    int retorno = -1;
    pFile = fopen(path, "wb");
    if(pFile != NULL)
    {
        retorno = 0;
        fwrite(arrayEMovie,sizeof(EMovie), ocupado,pFile);
    }
    fclose(pFile);
    return retorno;
}

int funciones_GenerarPaginaWeb(EMovie** arrayEMovie, int *ocupado, int total, char* path)
{
    int retorno = -1;
    int i;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];

    FILE* pFile;
    pFile = fopen(path,"w");

    if(pFile != NULL && arrayEMovie != NULL && total > 0 && *ocupado >= 0 &&  total > *ocupado)
    {
        retorno = 0;

        for(i=0;i<*ocupado;i++)
        {
            eMovie_getTitulo(arrayEMovie[i], titulo);
            eMovie_getGenero(arrayEMovie[i], genero);
            eMovie_getDescripcion(arrayEMovie[i], descripcion);
            eMovie_getDuracion(arrayEMovie[i], &duracion);
            eMovie_getPuntaje(arrayEMovie[i], &puntaje);
            eMovie_getLinkImagen(arrayEMovie[i], linkImagen);
            fprintf(pFile,"<article class='col-md-4 article-intro'>\
            <a href='#'>\
            <img class='img-responsive img-rounded' src='%s'\
            alt=''>\
            </a>\
            <h3>\
            <a href='#'>%s</a>\
            </h3>\
            <ul>\
            <li>Genero: %s</li>\
            <li>Puntaje: %d</li>\
            <li>Duracion: %d</li>\
            </ul>\
            <p>%s</p>\
            </article>",linkImagen,titulo,genero,puntaje,duracion,descripcion);
        }

    }
    fclose(pFile);
    return retorno;
}
