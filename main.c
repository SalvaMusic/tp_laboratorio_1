#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int numeroUno;
    int numeroDos;
    int suma;
    int resta;
    long multiplicacion;
    float division;
    double factor;
    int flagUno=0;
    int flagDos=0;

    while(seguir=='s')
    {
            if(flagUno==0)
            {
                printf("\n1- Ingresar 1er operando (A=x)\n");
            }
            else
            {
                printf("\n1- Ingresar 1er operando (A=%d)\n",numeroUno);
            }
            if(flagDos==0)
            {
                printf("2- Ingresar 2do operando (B=y)\n");
            }
            else
            {
                printf("2- Ingresar 2do operando (B=%d)\n",numeroDos);
            }

            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operaciones\n");
            printf("9- Salir\n");


        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                numeroUno = pedirNumero("\nIngrese 1er operando: ");
                flagUno=1;
                break;
            case 2:
                numeroDos = pedirNumero("\nIngrese 2do operando: ");
                flagDos=1;
                break;
            case 3:
                printf("\nCalcular la suma (%d+%d)",numeroUno,numeroDos);
                suma = sumar(numeroUno,numeroDos);
                printf("\nResultado: %d\n", suma);
                break;
            case 4:
                printf("\nCalcular la resta (%d-%d)",numeroUno,numeroDos);
                resta = restar(numeroUno,numeroDos);
                printf("\nResultado: %d\n", resta);
                break;
            case 5:
                if (numeroUno > 0 && numeroDos > 0)
                {
                    printf("\nCalcular la division (%d/%d)",numeroUno,numeroDos);
                    division = dividir(numeroUno,numeroDos);
                    printf("\nResultado: %.2f\n", division);
                }
                else
                {
                    printf("\nNo se puede dividir por 0\n");
                }

                break;
            case 6:
                printf("\nCalcular la multiplicacion (%d*%d)",numeroUno,numeroDos);
                multiplicacion = multiplicar(numeroUno,numeroDos);
                printf("\nResultado: %ld\n", multiplicacion);
                break;
            case 7:
                printf("\nCalcular el factorial (%d!)",numeroUno);
                factor = factorial(numeroUno);
                printf("\nResultado: %f\n", factor);
                break;
            case 8:
                suma = sumar(numeroUno,numeroDos);
                printf("\nCalcular la suma (%d+%d) = %d",numeroUno,numeroDos,suma);

                resta = restar(numeroUno,numeroDos);
                printf("\nCalcular la resta (%d-%d) = %d",numeroUno,numeroDos,resta);

                if (numeroUno > 0 && numeroDos > 0)
                {
                    division = dividir(numeroUno,numeroDos);
                    printf("\nCalcular la division (%d/%d) = %.2f",numeroUno,numeroDos,division);
                }
                else
                {
                    printf("\nNo se puede dividir por 0");
                }

                multiplicacion = multiplicar(numeroUno,numeroDos);
                printf("\nCalcular la multiplicacion (%d*%d) = %ld",numeroUno,numeroDos, multiplicacion);

                factor = factorial(numeroUno);
                printf("\nCalcular el factorial (%d!) = %f\n",numeroUno, factor);

                break;
            case 9:
                seguir = 'n';
                break;
        }

    }

    return 0;
}
