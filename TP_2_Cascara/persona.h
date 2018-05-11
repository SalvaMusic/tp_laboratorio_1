#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    char dni [11];
    int idPersona;

}EPersona;

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 * Ordena alfabeticamente los nombres del array pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param limite de personas en el array.
 * @param se ingresa el orden (0 para ascendente o 1 para descendente).
 * @return un entero para verificar si pudo conctretar la tarea.
 */
int persona_ordenar(EPersona* array,int limite, int orden);

/**
 * inicia todos los espacios del array en 0 para comenzar a ingresar datos
 * @param lista el array se pasa como parametro.
 * @param limite de personas en el array.
 * @return un entero para verificar si pudo conctretar la tarea.
 */
int persona_init(EPersona* array,int limite);

/**
 * busca en todo el array el campo de la persona con el id ingresado
 * @param lista el array se pasa como parametro.
 * @param limite de personas en el array.
 * @param id por el cual se buscaran los datos.
 * @return un entero para verificar si pudo conctretar la tarea.
 */
int persona_buscarPorId(EPersona* array,int limite, int id);

/**
 * dar de baja el campo de una persona cambiando la variable estado a LIBRE
 * @param lista el array se pasa como parametro.
 * @param limite de personas en el array.
 * @param id por el cual se buscaran los datos.
 * @return un entero para verificar si pudo conctretar la tarea.
 */
int persona_baja(EPersona* array,int limite, int id);

/**
 * muestra todos los datos de las personas ingresadas en el array
 * @param lista el array se pasa como parametro.
 * @param limite de personas en el array.
 * @return un entero para verificar si pudo conctretar la tarea.
 */
int persona_mostrar(EPersona* array,int limite);

/**
 * ingresa todos los datos de una persona.
 * @param lista el array se pasa como parametro.
 * @param limite de personas en el array.
 * @return un entero para verificar si pudo conctretar la tarea.
 */
int persona_alta(EPersona* array,int limite);

/**
 * toma los datos de la funcion "persona_contarEdades", luego grafica con barras de asteriscos (*).
 * @param lista el array se pasa como parametro.
 * @param limite de personas en el array.
 * @return un entero para verificar si pudo conctretar la tarea.
 */
int persona_graficar(EPersona* array,int limite);

/**
 * divide por edades a las personas (<18, 18-35, >35).
 * @param lista el array se pasa como parametro.
 * @param limite de personas en el array.
 * @param devuelve la cantidad de personas menores de 18 años.
 * @param devuelve la cantidad de personas entre 18 y 35 años.
 * @param devuelve la cantidad de personas mayores de 35 años.
 * @param devuelve la el grupo con mayor cantidad de personas.
 * @return un entero para verificar si pudo conctretar la tarea.
 */
int persona_contarEdades(EPersona* array,int limite, int* menores, int* jovenes, int* adultos, int* maximo);

#endif // PERSONA_H_INCLUDED



