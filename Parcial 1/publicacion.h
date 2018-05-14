#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "cliente.h"
typedef struct
{
    char descripcion[65];
    int rubro;
    int idCliente;
    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;
#endif // PUBLICACION_H_INCLUDED

int publicacion_init(Publicacion* array,int limite);
int publicacion_buscarPorId(Publicacion* array,int limite, int id);
int publicacion_baja(Publicacion* array,int limite, int id);

int publicacion_altaForzada(Publicacion* array,int limite,char* descripcion, int rubro,int estado, Cliente* arrayC,int limiteC, int idCliente);
int publicacion_mostrar(Publicacion* array,int limite);
int publicacion_alta(Publicacion* array,int limite, Cliente* arrayC, int limiteC,int idCliente);
int publicacion_modificacionCase(Publicacion* array,int sizeArray,int id);
int publicacion_listarActivas(Publicacion* array,int limite);
int publicacion_listarPausadas(Publicacion* array,int limite);

int publicacion_listarPorCliente(Publicacion* array,int limite,int idCliente);
int publicacion_BajaCliente(Publicacion* array,int limite, int idCliente);
int publicacion_devolverIdCliente(Publicacion* array,int limite,int idPublicacion,int*indexCliente);
int publicacion_devolverEstado(Publicacion* array,int limite,int idPublicacion);

int publicacion_pausa(Publicacion* array,int limite, int id);
int publicacion_reanudar(Publicacion* array,int limite, int id);


int publicacion_ordenarNombre(Publicacion* array,int limite, int orden);
int publicacion_ordenarId(Publicacion* array,int limite, int orden);
int publicacion_ordenarImporte(Publicacion* array,int limite, int orden);






