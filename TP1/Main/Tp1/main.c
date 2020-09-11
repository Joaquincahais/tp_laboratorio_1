#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "suma.h"
#include "resta.h"
#include "division.h"
#include "multiplicacion.h"
#include "factorial.h"
#include "factorialB.h"

int main()
{
    int opcion;
    char salir;
    int num1;
    int num2;
    int numIngreso;
    int numIngreso2;
    int bandera1=0;
    int bandera2=0;
    int bandera3=0;
    int sumaFinal;
    int restaFinal;
    float divisionFinal;
    int multiplicacionFinal;
    int factorialFinalA;
    int factorialFinalB;

    do{

        printf("***Menu de opciones:***\n\n");
        if(bandera1==0) //Compueba no se ingreso todavia el primer numero
        {
            printf("1- Ingresar 1er operando (A='Aun no se ingreso')\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%d)\n", num1);
        }
        if(bandera2==0) //Compueba si no se ingreso todavia el segundo numero
        {
            printf("2- Ingresar 2do operando (B='Aun no se ingreso')\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%d)\n", num2);
        }
        printf("3- Calcular todas las operaciones:\n\ta) Calcular la suma (A+B)\n\tb) Calcular la resta (A-B)\n\tc) Calcular la division (A/B)\n\td) Calcular la multiplicacion (A*B)\n\te) Calcular el factorial (A!)\n");
        printf("4- Informar resultados:\n\ta) 'El resultado de A+B es: r'\n\tb) 'El resultado de A-B es: r'\n\tc) 'El resultado de A/B es: r' o 'No es posible dividir por cero'\n\td) 'El resultado de A*B es: r'\n\te) 'El factorial de A es: r1 y El factorial de B es: r2'\n");
        printf("5- Salir\n\n");
        printf("Elegir opcion:\n");
        scanf("%i",&opcion);
        while(opcion<1 || opcion>5 || opcion == isalnum(opcion)) //validacion de opciones
        {
            printf("Opcion no valida!\n");
            printf("Elegir opcion:\n");
            fflush(stdin);
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                {
                    printf("Ingresar 1er operando:");
                    fflush(stdin);
                    scanf("%d", &numIngreso);
                    while(numIngreso == isalnum(numIngreso))
                    {
                        printf("No es un numero!\n");
                        printf("Ingresar 1er operando:");
                        fflush(stdin);
                        scanf("%d", &numIngreso);
                    }
                    num1 = numIngreso;
                    bandera1=1;
                    break;
                }
            case 2:
                {
                    printf("Ingresar 2do operando:");
                    fflush(stdin);
                    scanf("%d", &numIngreso2);
                    while(numIngreso2 == isalnum(numIngreso2))
                    {
                        printf("No es un numero!\n");
                        printf("Ingresar 2do operando:");
                        fflush(stdin);
                        scanf("%d", &numIngreso2);
                    }
                    num2 = numIngreso2;
                    bandera2=1;
                    break;
                }
            case 3:
                {
                    if(bandera1==0 || bandera2==0)//Comprueba si falta ingresar alguno de los 2 operandos
                    {
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
                        //Calcula llamando a las funciones agregadas en biblioteca
                        sumaFinal = calcularSuma(num1, num2);
                        restaFinal = calcularResta(num1, num2);
                        divisionFinal = calcularDivision(num1, num2);
                        multiplicacionFinal = calcularMultiplicacion(num1, num2);
                        factorialFinalA = calcularFactorialA(num1);
                        factorialFinalB = calcularFactorialB(num2);
                        bandera3=1;
                        printf("Calculado!\nPresione una tecla para volver al menu...");
                        fflush(stdin);
                        getchar();

                    }


                break;
                }
            case 4:
                {
                    if(bandera3==0)//Comprueba si se calcularon las operaciones
                        {
                            printf("No se calcularon la operaciones!\n");
                            printf("Presione una tecla para volver al menu...");
                            fflush(stdin);
                            getchar();
                        }
                    else
                        {
                            //Imprime los resultados
                          printf("%d + %d = %d\n", num1, num2, sumaFinal);
                          printf("%d - %d = %d\n", num1, num2, restaFinal);
                          printf("%d / %d = %.2f\n", num1, num2, divisionFinal);
                          printf("%d * %d = %d\n", num1, num2, multiplicacionFinal);
                          if(factorialFinalA==0)
                          {
                              printf("%d! = No tiene\n", num1);
                          }
                          else
                          {
                              if(factorialFinalA==-1)
                              {
                                  printf("%d! = No es posible calcular el factorial de numeros mayores a 16\n", num1);
                              }
                              else
                              {
                                printf("%d! = %d\n", num1, factorialFinalA);
                              }

                          }
                          if(factorialFinalB==0)
                          {
                              printf("%d! = No tiene\n", num2);
                          }
                          else
                          {
                              if(factorialFinalB==-1)
                              {
                                  printf("%d! = No es posible calcular el factorial de numeros mayores a 16\n", num2);
                              }
                              else
                              {
                                printf("%d! = %d\n\n", num2, factorialFinalB);
                              }

                          }
                          printf("Presione una tecla para volver al menu...");
                          fflush(stdin);
                          getchar();
                        }
                    break;
                }
            case 5:
                {
                    printf("Realmente desea salir?\n's/n'");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = tolower(salir);
                }
        }
        system("cls");
    }while(salir!='s');



    return 0;
}



