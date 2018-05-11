#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "funciones.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(EPersona* array,int limite);
static int proximoId();

int persona_init(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].estado = LIBRE;
            array[i].edad = -1;
        }
    }
    return retorno;
}

int persona_buscarPorId(EPersona* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado == OCUPADO && array[i].idPersona == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int persona_contarEdades(EPersona* array,int limite, int* menores, int* jovenes, int* adultos, int* maximo)
{
    int i;
    int contMenores=0;
    int contJovenes=0;
    int contAdultos=0;
    int max=0;
        for (i=0;i<limite;i++)
        {
            if (array[i].estado==OCUPADO){
                if (array[i].edad<18 && array[i].edad>=0){
                    contMenores++;
                }
                else if(array[i].edad>=18 && array[i].edad<=35){
                    contJovenes++;
                }else{
                    contAdultos++;
                }
            }
        }

        if(contMenores > contJovenes && contMenores > contAdultos)
        {
            max=contMenores;
        }else if(contJovenes > contAdultos)
        {
            max=contJovenes;
        }else{
            max=contAdultos;
        }
        *menores=contMenores;
        *jovenes=contJovenes;
        *adultos=contAdultos;
        *maximo=max;
    return 0;
}

int persona_graficar(EPersona* array,int limite)
{
    int menores, jovenes, adultos, maximo,vecesMenores,vecesJovenes,vecesAdultos;
    persona_contarEdades(array,limite, &menores, &jovenes, &adultos, &maximo);
    int i;
    vecesMenores=maximo-menores;
    vecesJovenes=maximo-jovenes;
    vecesAdultos=maximo-adultos;

    printf("\n");
    for (i=0;i<maximo;i++)
    {
        if (i<vecesMenores){
            printf("   \t");
        }else {
            printf("  *\t");
        }
        if (i<vecesJovenes){
            printf("   \t");
        }else {
            printf("  *\t");
        }
        if (i<vecesAdultos){
            printf("   \t");
        }else {
            printf("  *\t");
        }
            printf("\n");
    }
        printf("  <18\t");
        printf("19-35\t");
        printf(">35 ");

    return 0;
}

int persona_baja(EPersona* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    char seguir;
    indice = persona_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        getStringLetras("\nDesea confirmar? (s/n): ", &seguir);
        if(seguir =='s')
        {
            array[indice].estado = LIBRE;
            printf("\nOperacion exitosa!\n");
        }
        else
        {
            printf("\nOperacion cancelada!\n");
        }
    }else {
        printf("\nNo se encontro el ID\n");
    }
    return retorno;
}

int persona_mostrar(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    int flag=0;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado)
            {
                printf("\nNombre: %s \t DNI: %s \t Edad: %d - Id: %d ",array[i].nombre, array[i].dni,array[i].edad,array[i].idPersona);
                flag=1;
            }
        }
        if (!flag){
            printf("No hay personas agregadas");
            retorno = -1;
        }
    }
    return retorno;
}

int persona_alta(EPersona* array,int limite)
{
    int retorno = -1;
    char nombre [50];
    int edad;
    char dni [11];
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
            if(!getValidString("\nNombre: ","\nError! Ingrese un nombre valido...","\nSe excedio de digitos", nombre,50,3))
            {
                if(!getDni("\nDNI: ","\nError! Ingrese un DNI valido...","\nSe excedio de digitos", dni,14,3))
                {
                     if(!getValidInt("\nEdad: ","\nError! Ingrese una edad valida...", &edad,0,200,3))
                    {

                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        strcpy(array[indice].dni,dni);
                        array[indice].edad = edad;
                        array[indice].idPersona = id;
                        array[indice].estado = OCUPADO;
                        printf("\nAgregada con exito!");
                    }
                }
            }
        }else{
            printf("\nNo hay espacio para agregar otra persona!\n");
        }
    }
    return retorno;
}


static int buscarLugarLibre(EPersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado == LIBRE)
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


int persona_ordenar(EPersona* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    EPersona auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].estado == OCUPADO && array[i+1].estado == OCUPADO )
                    {
                        if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
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









































