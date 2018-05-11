#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "utn.h"
#define QTY 10
#define QTYP 20

int main()
{
    Cliente arrayCliente[QTY];
    Publicacion arrayPublicacion[QTY];
    int menu;
    int auxiliarId;

    publicacion_init(arrayPublicacion,QTY);
    cliente_init(arrayCliente,QTY);

    cliente_altaForzada(arrayCliente,QTY,"Salvador","Pedrozo","4225241658");
    cliente_altaForzada(arrayCliente,QTY,"Gustavo","Ramirez","3124562515");
    cliente_altaForzada(arrayCliente,QTY,"Yesica","More","5155685486");

    publicacion_altaForzada(arrayPublicacion,QTYP,"VENDO AUTOS",2,arrayCliente,QTY,0);
    publicacion_altaForzada(arrayPublicacion,QTYP,"COMPRO AUTOS",2,arrayCliente,QTY,0);
    publicacion_altaForzada(arrayPublicacion,QTYP,"VENDO CASAS",1,arrayCliente,QTY,1);
    publicacion_altaForzada(arrayPublicacion,QTYP,"VENDO ROPA",1,arrayCliente,QTY,2);


    do
    {
        getValidInt("\n1.Alta de Cliente\n2.Modicicar datos de Cliente\n3.Baja de Cliente\n4.Publicar\n5.Pausar Publicacion\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                printf("\nALTA CLIENTE:");
                cliente_alta(arrayCliente,QTY);
                break;
            case 2:
                printf("\nMODIFICAR DATOS CLIENTE:");
                cliente_mostrar(arrayCliente,QTY);
                getValidInt("\nIngrese ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                cliente_modificacionCase(arrayCliente,QTY,auxiliarId);
                break;
            case 3:
                printf("\nBAJA CLIENTE:");
                cliente_mostrar(arrayCliente,QTY);
                getValidInt("\nIngrese ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                if (!publicacion_listarPorCliente(arrayPublicacion,QTYP,auxiliarId))
                {
                    if(getChar("\nDesea confirmar la baja del cliente y sus publicaciones (s/n): ")=='s'){
                    cliente_baja(arrayCliente,QTY,auxiliarId);
                    publicacion_BajaCliente(arrayPublicacion,QTYP,auxiliarId);
                    printf("\nBaja Exitosa");
                    }else{
                        printf("\nOperacion Cancelada\n");
                    }
                }
                break;
            case 4:
                printf("\nPUBLICAR:");
                cliente_mostrar(arrayCliente,QTY);
                getValidInt("\nIngrese ID de Cliente: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                publicacion_alta(arrayPublicacion,QTYP,arrayCliente,QTY,auxiliarId);
                break;
            case 5:
                printf("\nPAUSAR PUBLICACION:");
                publicacion_Listar(arrayPublicacion,QTYP);
                getValidInt("\nIngrese ID de Publicacion: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                publicacion_listarPorCliente(arrayPublicacion,QTYP,auxiliarId);

                break;
            case 6:
                printf("\nMOSTRAR DEBUG:");

                break;
        }

    }while(menu != 9);

    return 0;
}
