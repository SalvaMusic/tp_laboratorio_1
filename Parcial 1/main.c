#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "cliente.h"
#include "utn.h"
#include "informe.h"
#define QTY 100
#define QTYP 1000

int main()
{
    Cliente arrayCliente[QTY];
    Publicacion arrayPublicacion[QTYP];
    int menu;
    int auxiliarId;
    int idCliente;

    publicacion_init(arrayPublicacion,QTYP);
    cliente_init(arrayCliente,QTY);

    cliente_altaForzada(arrayCliente,QTY,"Salvador","Pedrozo","4225241658");
    cliente_altaForzada(arrayCliente,QTY,"Gustavo","Ramirez","3124562515");
    cliente_altaForzada(arrayCliente,QTY,"Yesica","More","5155685486");

    publicacion_altaForzada(arrayPublicacion,QTYP,"VENDO AUTOS",2,0,arrayCliente,QTY,0);
    publicacion_altaForzada(arrayPublicacion,QTYP,"COMPRO AUTOS",2,2,arrayCliente,QTY,1);
    publicacion_altaForzada(arrayPublicacion,QTYP,"VENDO CASAS",1,0,arrayCliente,QTY,1);
    publicacion_altaForzada(arrayPublicacion,QTYP,"VENDO ROPA",1,0,arrayCliente,QTY,2);

    do
    {
        getValidInt("\n1.Alta de Cliente\n2.Modicicar datos de Cliente\n3.Baja de Cliente\n4.Publicar\n5.Pausar Publicacion\n6.Reanudar Publicacion\n7.Imprimir Clientes\n8.Imprimir Publicaciones\n9.Informar Clientes\n10.Informar Publicaciones\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                printf("\n\tALTA CLIENTE:");
                cliente_alta(arrayCliente,QTY);
                break;
            case 2:
                printf("\n\tMODIFICAR DATOS CLIENTE:");
                cliente_mostrar(arrayCliente,QTY);
                if (!getValidInt("\nIngrese ID: ","\nNumero invalido\n",&auxiliarId,0,200,2)){
                    cliente_modificacionCase(arrayCliente,QTY,auxiliarId);
                }
                break;
            case 3:
                printf("\n\tBAJA CLIENTE:");
                cliente_mostrar(arrayCliente,QTY);
                if (!getValidInt("\nIngrese ID: ","\nNumero invalido\n",&auxiliarId,0,200,2)){
                    if(!cliente_baja(arrayCliente,QTY,auxiliarId)){
                        publicacion_BajaCliente(arrayPublicacion,QTYP,auxiliarId);
                        printf("\nBaja Exitosa");
                    }
                }else{
                    printf("\nOperacion Cancelada\n");
                }
                break;
            case 4:
                printf("\n\tPUBLICAR:\n");
                cliente_mostrar(arrayCliente,QTY);
                if (!getValidInt("\nIngrese ID de Cliente: ","\nNumero invalido\n",&auxiliarId,0,200,2)){
                    publicacion_alta(arrayPublicacion,QTYP,arrayCliente,QTY,auxiliarId);
                }
                break;
            case 5:
                printf("\n\tPAUSAR PUBLICACION:");
                printf("\nPUBLICACIONES ACTIVAS:\n");
                if (!publicacion_listarActivas(arrayPublicacion,QTYP)){
                    if(!getValidInt("\nIngrese ID de Publicacion: ","\nNumero invalido\n",&auxiliarId,0,200,2)){
                        if(!publicacion_devolverIdCliente(arrayPublicacion,QTYP,auxiliarId,&idCliente) && !publicacion_devolverEstado(arrayPublicacion,QTYP,auxiliarId)){
                            cliente_mostrarPorId(arrayCliente,QTY,idCliente);
                            if(getChar("\nDesea confirmar la pausa de la publicacion (s/n): ")=='s'){
                                publicacion_pausa(arrayPublicacion,QTYP,auxiliarId);
                                printf("\nPublicacion en estado 'PAUSADA'!\n");
                            }else{
                                printf("\nOperacion Cancelada!\n");
                            }
                        }else{
                            printf("\nID No encontrado!\n");
                        }
                    }
                }
                break;
            case 6:
                printf("\n\tREANUDAR PUBLICACION:");
                printf("\nPUBLICACIONES PAUSADAS:\n");
                if (!publicacion_listarPausadas(arrayPublicacion,QTYP)){
                    if(!getValidInt("\nIngrese ID de Publicacion: ","\nNumero invalido\n",&auxiliarId,0,200,2)){
                        if(!publicacion_devolverIdCliente(arrayPublicacion,QTYP,auxiliarId,&idCliente) && publicacion_devolverEstado(arrayPublicacion,QTYP,auxiliarId)){
                            cliente_mostrarPorId(arrayCliente,QTY,idCliente);
                            if(getChar("\nDesea confirmar la reanudacion de la publicacion (s/n): ")=='s'){
                                publicacion_reanudar(arrayPublicacion,QTYP,auxiliarId);
                                printf("\nPublicacion en estado 'ACTIVA'!\n");
                            }else{
                                printf("\nOperacion Cancelada!\n");
                            }
                        }else{
                            printf("\nID No encontrado!\n");
                        }
                    }
                }
                case 7:
                printf("\n\tIMPRIMIR CLIENTES:\n");
                informe_imprimirCliente(arrayCliente,QTY,arrayPublicacion,QTYP);
                break;
                case 8:
                printf("\n\tIMPRIMIR PUBLICACIONES:\n");
                informe_imprimirPublicacion(arrayCliente,QTY,arrayPublicacion,QTYP);
                break;
                case 9:
                printf("\n\tINFORMAR CLIENTES:\n");
                informe_clienteFinal(arrayCliente,QTY,arrayPublicacion,QTYP);
                break;
                case 10:
                printf("\n\tINFORMAR PUBLICACIONES:\n");
                informe_publicacionFinal(arrayCliente,QTY,arrayPublicacion,QTYP);
                break;
        }

    }while(menu != 11);

    return 0;
}
