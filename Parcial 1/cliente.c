#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Cliente* array,int limite);
static int proximoId();

int cliente_mostrarPorId(Cliente* array,int limite,int idCliente)
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
               printf("\%s %s - Cuit %s - ID: %d ",array[i].nombre,array[i].apellido,array[i].cuit,array[i].idCliente);
               flag=1;
            }
        }
        if(!flag){
            printf("\nNo hay datos ingresados!");
        }
    }
    return retorno;
}
int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido,char* cuit)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,apellido);
            strcpy(array[i].cuit,cuit);
            //------------------------------
            //------------------------------*/
            array[i].idCliente = proximoId();
            array[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

int cliente_init(Cliente* array,int limite)
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

int cliente_buscarPorId(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idCliente == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_baja(Cliente* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    char continuar;
    if(limite > 0 && array != NULL){
        indice = cliente_buscarPorId(array,limite,id);
        if(indice >= 0){
            printf("\nDesea bajar al usuario '%s'?  (s/n) ",array[indice].nombre);
            fflush(stdin);
            scanf("%c", &continuar);
            if(continuar=='s'){
                array[indice].isEmpty = LIBRE;
                retorno = 0;
            }else{
                printf("\nOperacion Cancelada\n");
            }
        }else{
            printf("\nID No encontrado!\n");
        }
    }
    return retorno;
}

int cliente_mostrar(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    int flag=0;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\n%s %s - Cuit %s - ID: %d ",array[i].nombre,array[i].apellido,array[i].cuit,array[i].idCliente);
               flag=1;
            }
        }
        if(!flag){
            printf("\nNo hay datos ingresados!");
        }
        printf("\n");
    }
    return retorno;
}

int cliente_mostrarDebug(Cliente* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d",array[i].nombre,array[i].idCliente,array[i].isEmpty);
        }
    }
    return retorno;
}

int cliente_alta(Cliente* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int id;
    int indice;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("\nIngrese Nombre: ","\nError! Caracteres no validos","\nSe excedio de caracteres", nombre,50,2))
            {
                if(!getValidString("Ingrese Apellido: ","\nError! Caracteres no validos","\nSe excedio de caracteres", apellido,50,2))
                {
                    if(getStringNumeros("Ingrese Cuit: ", cuit))
                    {
                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].apellido,apellido);
                        strcpy(array[indice].cuit,cuit);
                        array[indice].idCliente = id;
                        array[indice].isEmpty = OCUPADO;
                        printf("\nSe ha dado de alta con el ID: %d\n", array[indice].idCliente);
                    }
                }
            }
        }
    }
    return retorno;
}

int cliente_modificacion(Cliente* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];

    if(limite > 0 && array != NULL)
    {
        indice = cliente_buscarPorId(array,limite,id);
        if(indice >= 0)
        {
            retorno = -2;
            if(!getValidString("\nIngrese nuevo Nombre: ","\nError! Caracteres no validos","\nSe excedio de caracteres", nombre,50,2))
            {
                retorno = 0;
                if (getChar("\nDesea guardar esta modificacion? (s/n): ")=='s'){
                    strcpy(array[indice].nombre,nombre);
                }else{
                    printf("\nOperacion Cancelada!");
                }
            }
        }else{
            printf("\nID no encontrado");
        }

    }
    return retorno;
}

static int buscarLugarLibre(Cliente* array,int limite)
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

int cliente_modificacionCase(Cliente* array,int sizeArray,int id)
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int indice;
    char continuar;
    int modificar;
    int retorno=-1;



    if(sizeArray > 0 && array != NULL)
    {
        indice = cliente_buscarPorId(array,sizeArray,id);
        if(indice >= 0)
        {
            retorno = -2;
            printf("\nDesea modificar al usuario '%s'?  (s/n) ",array[indice].nombre);
            fflush(stdin);
            scanf("%c", &continuar);
            if(continuar=='s'){
                retorno=0;
                getValidInt("\nIngrese la opcion que desea modificar: \n1. Modificar nombre y apellido. \n2. Modificar Cuit. \n", "\nIngrese una opcion correcta!",&modificar,1,2,2);
                switch(modificar)
                {
                    case 1:
                        if(!getValidString("Ingrese Nombre: ","\nError! Caracteres no validos","\nSe excedio de caracteres", nombre,50,2) &&
                           !getValidString("Ingrese Apellido: ","\nError! Caracteres no validos","\nSe excedio de caracteres", apellido,50,2)){
                            if(getChar("\nDesea guardar esta modificacion? (s/n): ")=='s'){
                                strcpy(array[indice].nombre, nombre);
                                strcpy(array[indice].apellido, apellido);
                                printf("\nOperacion Exitosa");
                            }else{
                                printf("\nOperacion cancelada!");
                            }
                        }
                        break;
                    case 2:
                        getString("Ingrese su nuevo Cuit: ", cuit);
                        if(getChar("\nDesea guardar esta modificacion? (s/n): ")=='s'){
                            strcpy(array[indice].cuit, cuit);
                            printf("\nOperacion Exitosa");
                        }else{
                            printf("\nOperacion cancelada!");
                        }
                        break;
                }//switch(modificar)
            }else{
                printf("\nOperacion cancelada");
            }//if(continuar=='s')
        }else{
            printf("\nID no encontrado\n");
        }// if(indice >= 0)
    }//if(sizeArray > 0 && array != NULL)
    return retorno;
}

int cliente_ordenar(Cliente* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Cliente auxiliar;

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
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                    {
                        auxiliar = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                    //if((array[i].idCliente>array[i+1].idCliente && !orden) || (array[i].idCliente<array[i+1].idCliente && orden)) //<------------
                }
            }
        }while(flagSwap);
    }
    return retorno;
}









































