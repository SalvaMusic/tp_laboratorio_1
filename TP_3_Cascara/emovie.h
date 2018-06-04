#ifndef EMOVIE_H_INCLUDED
#define EMOVIE_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[500];
    int idEMovie;
}EMovie;


#endif // EMOVIE_H_INCLUDED
EMovie* eMovie_new();
EMovie* eMovie_newParametros(char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen,int id);
int eMovie_setParametros(char* titulo,char* genero,int* duracion,char* descripcion,int* puntaje,char* linkImagen);
int eMovie_agregarPelicula(EMovie** arrayEMovie, int* ocupado);
int eMovie_mostrarPeliculas(EMovie** arrayEMovie, int ocupado);
int eMovie_bajarPelicula(EMovie** arrayEMovie, int *ocupado, int id);
int eMovie_modificarPelicula(EMovie** arrayEMovie, int *ocupado, int id);
int eMovie_setDuracion(EMovie* this,int duracion);
int eMovie_getDuracion(EMovie* this,int* duracion);
int eMovie_setPuntaje(EMovie* this,int puntaje);
int eMovie_getPuntaje(EMovie* this,int* puntaje);
int eMovie_setTitulo(EMovie* this, char* titulo);
int eMovie_getTitulo(EMovie* this, char* titulo);
int eMovie_setGenero(EMovie* this, char* genero);
int eMovie_getGenero(EMovie* this, char* genero);
int eMovie_setDescripcion(EMovie* this, char* descripcion);
int eMovie_getDescripcion(EMovie* this, char* descripcion);
int eMovie_setLinkImagen(EMovie* this, char* linkImagen);
int eMovie_getLinkImagen(EMovie* this, char* linkImagen);
int eMovie_getId(EMovie* this, int* id);
