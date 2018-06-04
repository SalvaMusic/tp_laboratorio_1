#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED




#endif // FUNCIONES_H_INCLUDED

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
int funciones_GenerarPaginaWeb(EMovie** arrayEMovie, int *ocupado, int total, char* path);
int funciones_cargarArchivo(EMovie** arrayEMovie, int* ocupado, int qtyMovieTotal, char* path);
int funciones_guardarArchivo(EMovie** arrayEMovie, int ocupado, char* path);
int funciones_GenerarPaginaWeb(EMovie** arrayEMovie, int *ocupado, int total, char* path);



