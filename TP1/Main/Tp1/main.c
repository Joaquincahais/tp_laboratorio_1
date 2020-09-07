#include <stdio.h>
#include <stdlib.h>
#include "suma.h"
#include "resta.h"
#include "division.h"
#include "factorial.h"
#include "factorialB.h"

int main()
{
    int opcion=0;
    int num1;
    int num2;
    int bandera1=0;
    int bandera2=0;
    int sumaFinal;
    float restaFinal;
    float divisionFinal;
    int multiplicacionFinal;
    int factorialFinalA;
    int factorialFinalB;

    while(opcion!=5)
    {
        system("cls");
        printf("***Menu de opciones:***\n\n");
        if(bandera1==0)
        {
            printf("1- Ingresar 1er operando (A='Aun no se ingreso')\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%i)\n",num1);
        }
        if(bandera2==0)
        {
            printf("2- Ingresar 2do operando (B='Aun no se ingreso')\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%i)\n", num2);
        }
        printf("3- Calcular todas las operaciones:\n\ta) Calcular la suma (A+B)\n\tb) Calcular la resta (A-B)\n\tc) Calcular la division (A/B)\n\td) Calcular la multiplicacion (A*B)\n\te) Calcular el factorial (A!)\n");
        printf("4- Informar resultados:\n\ta) 'El resultado de A+B es: r'\n\tb) 'El resultado de A-B es: r'\n\tc) 'El resultado de A/B es: r' o 'No es posible dividir por cero'\n\td) 'El resultado de A*B es: r'\n\te) 'El factorial de A es: r1 y El factorial de B es: r2'\n");
        printf("5- Salir\n\n");
        printf("Elegir opcion:\n");
        scanf("%i",&opcion);
        while(opcion<1 || opcion>5)
        {
            printf("Opcion no valida!\n");
            printf("Elegir opcion:\n");
            scanf("%i",&opcion);
        }
        switch(opcion)
        {
            case 1:
                {
                    printf("Ingresar 1er operando:");
                    scanf("%i", &num1);
                    bandera1=1;
                    break;
                }
            case 2:
                {
                    printf("Ingresar 2do operando:");
                    scanf("%i", &num2);
                    bandera2=1;
                    break;
                }
            case 3:
                {
                    if(bandera1==0 || bandera2==0)
                    {
                        system("cls");
                        if(bandera1==0)
                        {
                            printf("No se ingreso el 1er operando\n");
                        }
                        if(bandera2==0)
                        {
                            printf("No se ingreso el 2do operando\n");
                        }
                        printf("Presione una tecla para volver al menu...");
                        fflush(stdin);
                        getchar();
                    }
                    else
                    {
                        sumaFinal = calcularSuma(num1, num2);
                        restaFinal = calcularResta(num1, num2);
                        divisionFinal = calcularDivision(num1, num2);
                        multiplicacionFinal = calcularMultiplicacion(num1, num2);
                        factorialFinalA = calcularFactorialA(num1);
                        factorialFinalB = calcularFactorialB(num2);
                        system("cls");
                        printf("Calculado!\nPresione una tecla para volver al menu...");
                        fflush(stdin);
                        getchar();

                    }


                break;
                }
            case 4:
                {
                    if(bandera1==0 || bandera2==0)
                    {
                        system("cls");
                        if(bandera1==0)
                        {
                            printf("No se ingreso el 1er operando\n");
                        }
                        if(bandera2==0)
                        {
                            printf("No se ingreso el 2do operando\n");
                        }
                        printf("Presione una tecla para volver al menu...");
                        fflush(stdin);
                        getchar();
                    }
                    else
                    {
                      system("cls");
                      printf("Suma = %i\n", sumaFinal);
                      printf("Resta = %.2f\n", restaFinal);
                      printf("Division = %.2f\n", divisionFinal);
                      printf("Multiplicacion = %i\n", multiplicacionFinal);
                      printf("Factoriales: A = %i / B = %i\n\n", factorialFinalA, factorialFinalB);
                      printf("Presione una tecla para volver al menu...");
                      fflush(stdin);
                      getchar();
                    }
                break;
                }

        }
    }


    return 0;
}


/**  \brief calcula la suma de dos flotantes
*
* \param primer flotante a sumar
* \param segundo flotante a sumar
* \return resultado de la suma
*
*/


