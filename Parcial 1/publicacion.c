#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#define PAUSA 2

static int buscarLugarLibre(Publicacion* array,int limite);
static int proximoId();

int publicacion_pausa(Publicacion* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicacion_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = PAUSA;
    }else{
        printf("\nID no encontrado!");
    }
    return retorno;
}
int publicacion_BajaCliente(Publicacion* array,int limite, int idCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente == idCliente)
            {
                retorno=0;
                publicacion_baja(array,limite,array[i].idPublicacion);
            }
        }
    }
    return retorno;
}

int publicacion_altaForzada(Publicacion* array,int limite,char* descripcion, int rubro, Cliente* arrayC,int limiteC, int idCliente)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0 && !arrayC[idCliente].isEmpty)
        {
            retorno = 0;
            strcpy(array[i].descripcion,descripcion);
            array[i].rubro = rubro;
            array[i].idCliente =  idCliente;
            //------------------------------
            //------------------------------
            array[i].idPublicacion = proximoId();
            array[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

int publicacion_init(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int publicacion_buscarPorId(Publicacion* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idPublicacion == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_baja(Publicacion* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicacion_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }else{
        printf("\nID no encontrado!");
    }
    return retorno;
}

int publicacion_Listar(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                retorno=0;
                printf("\nDescripcion: %s - Rubro %d - ID: %d", array[i].descripcion,array[i].rubro,array[i].idPublicacion);

            }
        }
    }
    return retorno;
}
int publicacion_listarPorCliente(Publicacion* array,int limite,int idCliente)
{
    int retorno = -1;
    int i;
    int flag=0;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;

        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente == idCliente)
            {
               printf("\nDescripcion: %s - Rubro: %d - ID: %d",array[i].descripcion,array[i].rubro,array[i].idPublicacion);
               flag=1;
            }
        }
        if(!flag){
            printf("\nID sin publicaciones!");
            retorno = 1;
        }
    }
    return retorno;
}
int publicacion_devolverIdCliente(Publicacion* array,int limite,int idPublicacion,int*indexCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion == idPublicacion)
            {
                *indexCliente = array[i].idCliente;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_alta(Publicacion* array,int limite, Cliente* arrayC, int limiteC,int idCliente)
{
    int retorno = -1;
    char descripcion[65];
    int rubro;
    int id;
    int indice;

    if(limite > 0 && array != NULL && limiteC > 0 && arrayC != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0 && !arrayC[idCliente].isEmpty)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidInt("\nIngrese Numero de Rubro: ", "\nError! Caracteres no validos", &rubro,0,999999,2))
            {
                if(!getValidString("\nIngrese Descripcion: ","\nError! Caracteres no validos","\nSe excedio de caracteres", descripcion,64,2))
                {
                    retorno = 0;
                    strcpy(array[indice].descripcion,descripcion);
                    array[indice].rubro = rubro;
                    array[indice].idPublicacion = id;
                    array[indice].isEmpty = OCUPADO;
                    array[indice].idCliente = idCliente;
                    printf("\nPublicacion exitosa con el ID: %d", id);
                }
            }
        }else{
            printf("\nID no encontrado!\n");
        }
    }
    return retorno;
}

static int buscarLugarLibre(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}













