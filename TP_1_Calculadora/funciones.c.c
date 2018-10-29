#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief pide un numero enteros
 *
 * \param de pide el numero con un mensaje
 * \param numUno es el numero ingresado por el usuario
 * \return devuelve el numero escaneado por teclado
 *
 */
float pedirNumero(char* mensaje)
{
    float numero;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &numero);

    return numero;
}

/** \brief suma dos numeros enteros
 *
 * \param numUno es el primer factor
 * \param numDos es el segundo factor
 * \return devuelve el resultado de la suma
 *
 */
int sumar(int numUno, int numDos)
{
    int resultado;

    resultado = numUno+numDos;

    return resultado;
}

/** \brief resta dos numeros enteros
 *
 * \param numUno es el primer factor
 * \param numDos es el segundo factor
 * \return devuelve el resultado de la resta
 *
 */
int restar(int numUno, int numDos)
{
    int resultado;

    resultado = numUno-numDos;

    return resultado;
}

/** \brief divide dos numeros enteros
 *
 * \param numUno es el primer factor
 * \param numDos es el segundo factor
 * \return devuelve el resultado de la division
 *
 */
float dividir(int numUno, int numDos)
{
    float resultado;

    resultado = (float)numUno/numDos;

    return resultado;
}

/** \brief multiplica dos numeros enteros
 *
 * \param numUno es el primer factor
 * \param numDos es el segundo factor
 * \return devuelve el resultado de la multiplicacion
 *
 */
long multiplicar(int numUno, int numDos)
{
    long resultado;

    resultado = (long)numUno*numDos;

    return resultado;
}

/** \brief factorial de un numero entero
 *
 * \param numUno es el numero a operar
 * \return devuelve el resultado de factorial
 *
 */
double factorial(int numUno)
{
    double resultado = (double)numUno;
    int i;

    for(i=1; i<numUno; i++)
    {
        resultado=resultado*i;
    }

    return resultado;
}
