#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"


int informe_publicacionFinal(Cliente* arrayC,int limiteC,Publicacion* arrayP,int limiteP)
{
    int rubro, mayor, menor, cantidadActivas;

    if(!getValidInt("\nIngrese Rubro: ", "\nSolo Numeros de 0 a 100!", &rubro,0,100,3)){
        cantidadActivas=publicacion_contarAcivasPorRubro(arrayP,limiteP,rubro);
        if(rubro>0){
            printf("\nEl rubro %d tiene %d publicaciones activas.\n",rubro,cantidadActivas);
        }
    }
    publicacion_rubroMayorMenor(arrayP,limiteP,&mayor,&menor);
    printf("\nRubro con mas publicaciones activas: %d", mayor);
    printf("\nRubro con menos publicaciones activas: %d", menor);

    return 0;
}


int informe_clienteFinal(Cliente* arrayC,int limiteC,Publicacion* arrayP,int limiteP)
{
    int retorno = -1;
    int i, activas, pausadas, total, maxActivas=0, maxPausadas=0, maxTotal=0, indexTotal, indexPausadas, indexActivas;

    if(limiteC > 0 && arrayC != NULL && limiteP > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty){
                activas = publicacion_contarAcivasPorCliente(arrayP,limiteP,arrayC[i].idCliente);
                pausadas = publicacion_contarPausadasPorCliente(arrayP,limiteP,arrayC[i].idCliente);
                total = publicacion_contarTotalPorCliente(arrayP,limiteP,arrayC[i].idCliente);

                if (total > maxTotal){
                    maxTotal=total;
                    indexTotal=i;
                }
                if (pausadas > maxPausadas){
                    maxPausadas=pausadas;
                    indexPausadas=i;
                }
                if (activas > maxActivas){
                    maxActivas=activas;
                    indexActivas=i;
                }
            }
        }
        printf("\nMas avisos activos: ");
        if(maxActivas>0){
            printf("%s %s - Cuit: %s - ID: %d - Cantidad: %d",arrayC[indexActivas].nombre,arrayC[indexActivas].apellido,arrayC[indexActivas].cuit,arrayC[indexActivas].idCliente,maxActivas);
        }else{
            printf("No hay publicaciones!");
        }
        printf("\nMas avisos pausados: ");

        if(maxPausadas>0){
            printf("%s %s - Cuit: %s - ID: %d - Cantidad: %d",arrayC[indexPausadas].nombre,arrayC[indexPausadas].apellido,arrayC[indexPausadas].cuit,arrayC[indexPausadas].idCliente,maxPausadas);
        }else{
            printf("No hay publicaciones!");
        }
        printf("\nMas avisos totales: ");

        if(maxTotal>0){
            printf("%s %s - Cuit: %s - ID: %d - Cantidad: %d",arrayC[indexTotal].nombre,arrayC[indexTotal].apellido,arrayC[indexTotal].cuit,arrayC[indexTotal].idCliente,maxTotal);
        }else{
            printf("No hay publicaciones!");
        }
        printf("\n");
    }
    return retorno;
}

int informe_imprimirPublicacion(Cliente* arrayC,int limiteC,Publicacion* arrayP,int limiteP)
{
    int retorno = -1;
    int i, indexCliente;
    int flag=0;

    if(limiteC > 0 && arrayC != NULL && limiteP > 0 && arrayP != NULL)
    {
        retorno = -2;
        for(i=0;i<limiteP;i++)
        {
            if(!arrayP[i].isEmpty)
            {
                indexCliente=cliente_buscarPorId(arrayC,limiteC,arrayP[i].idCliente);
                printf("\nDescripcion: %s - Rubro: %d - ID: %d - Cuit Cliente: %s",arrayP[i].descripcion,arrayP[i].rubro,arrayP[i].idPublicacion,arrayC[indexCliente].cuit);
                flag=1;
            }
        }
        if(!flag){
            printf("\nID sin publicaciones!");
            retorno = 1;
        }
        printf("\n");
    }
    return retorno;
}

int informe_imprimirCliente(Cliente* arrayC,int limiteC,Publicacion* arrayP,int limiteP)
{
    int retorno = -1;
    int i, cantidadPublicaciones;
    int flag=0;

    if(limiteC > 0 && arrayC != NULL && limiteP > 0 && arrayP != NULL)
    {
        retorno = -2;
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty)
            {
                retorno = 0;
                cantidadPublicaciones = publicacion_contarAcivasPorCliente(arrayP,limiteP,arrayC[i].idCliente);
                printf("\n%s %s - Cuit %s - ID: %d - Publicaciones Activas: %d",arrayC[i].nombre,arrayC[i].apellido,arrayC[i].cuit,arrayC[i].idCliente,cantidadPublicaciones);
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

