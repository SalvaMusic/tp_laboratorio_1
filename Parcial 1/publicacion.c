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

int publicacion_reanudar(Publicacion* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicacion_buscarPorId(array,limite,id);

    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = OCUPADO;
    }else{
        printf("\nID no encontrado!");
    }
    return retorno;
}

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

        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty || array[i].isEmpty == 2 && array[i].idCliente == idCliente)
            {
                array[i].isEmpty = LIBRE;
                retorno=0;
            }
        }

    return retorno;
}

int publicacion_altaForzada(Publicacion* array,int limite,char* descripcion, int rubro, int estado, Cliente* arrayC,int limiteC, int idCliente)
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
            array[i].isEmpty = estado;
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
            if((array[i].isEmpty == OCUPADO || array[i].isEmpty == PAUSA) && array[i].idPublicacion == id)
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

int publicacion_listarPausadas(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    int flag=1;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == 2)
            {
                retorno=0;
                printf("\nDescripcion: %s - Rubro %d - ID: %d", array[i].descripcion,array[i].rubro,array[i].idPublicacion);
                flag=0;
            }
        }
        printf("\n");
        if (flag){
            printf("\nNo hay publicaciones Pausadas!\n");
            retorno = 1;
        }
    }
    return retorno;
}

int publicacion_listarActivas(Publicacion* array,int limite)
{
    int retorno = -1;
    int i;
    int flag=1;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                retorno=0;
                printf("\nDescripcion: %s - Rubro %d - ID: %d", array[i].descripcion,array[i].rubro,array[i].idPublicacion);
                flag=0;
            }
        }
        printf("\n");
        if (flag){
            printf("\nNo hay publicaciones Activas!\n");
            retorno = 1;
        }
    }
    return retorno;
}

int publicacion_contarTotalPorCliente(Publicacion* array,int limite,int idCliente)
{
    int retorno = -1;
    int i, cantidadPublicaciones=0;
    int flag=0;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if((!array[i].isEmpty || array[i].isEmpty == 2) && array[i].idCliente == idCliente){
                cantidadPublicaciones++;
                flag=1;
                retorno=cantidadPublicaciones;
            }
        }
        if(!flag){
            retorno = 0;
        }
    }
    return retorno;
}

int publicacion_contarPausadasPorCliente(Publicacion* array,int limite,int idCliente)
{
    int retorno = -1;
    int i, cantidadPublicaciones=0;
    int flag=0;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == 2 && array[i].idCliente == idCliente){
                cantidadPublicaciones++;
                flag=1;
                retorno=cantidadPublicaciones;
            }
        }
        if(!flag){
            retorno = 0;
        }
    }
    return retorno;
}

int publicacion_contarAcivasPorCliente(Publicacion* array,int limite,int idCliente)
{
    int retorno = -1;
    int i, cantidadPublicaciones=0;
    int flag=0;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente == idCliente){
                cantidadPublicaciones++;
                flag=1;
                retorno=cantidadPublicaciones;
            }
        }
        if(!flag){
            retorno = 0;
        }
    }
    return retorno;
}

int publicacion_ordenarRubro(Publicacion* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Publicacion auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                {
                    if((array[i].rubro>array[i+1].rubro && !orden) || (array[i].rubro<array[i+1].rubro && orden)) //<------------
                    {
                        auxiliar = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int publicacion_rubroMayorMenor(Publicacion* array,int limite,int *mayor, int *menor)
{
    int retorno = -1;
    int i, contPublicaciones=0, maxPublicaciones=0, minPublicaciones=0,ultimoRubro=-1;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty){
                if(array[i].rubro == ultimoRubro){
                    contPublicaciones++;
                }else{
                    ultimoRubro=array[i].rubro;
                    contPublicaciones=1;
                }
                if(contPublicaciones>maxPublicaciones){
                    maxPublicaciones=contPublicaciones;
                    *mayor=array[i].rubro;
                }else if(contPublicaciones<minPublicaciones){
                    minPublicaciones=contPublicaciones;
                    *menor=array[i].rubro;
                }
            }
        }
    }
    return retorno;

}

int publicacion_contarAcivasPorRubro(Publicacion* array,int limite,int rubro)
{
    int retorno = -1;
    int i, cantidadPublicaciones=0;
    int flag=0;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].rubro == rubro){
                cantidadPublicaciones++;
                flag=1;
                retorno=cantidadPublicaciones;
            }
        }
        if(!flag){
            retorno = 0;
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

int publicacion_devolverIdCliente(Publicacion* array,int limite,int idPublicacion,int *idCliente)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if((!array[i].isEmpty || array[i].isEmpty == 2) && array[i].idPublicacion == idPublicacion)
            {
                *idCliente = array[i].idCliente;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_devolverEstado(Publicacion* array,int limite,int idPublicacion)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPublicacion == idPublicacion){
                retorno = 0;
                break;
            }else if (array[i].isEmpty == PAUSA && array[i].idPublicacion == idPublicacion){
                retorno = 1;
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













