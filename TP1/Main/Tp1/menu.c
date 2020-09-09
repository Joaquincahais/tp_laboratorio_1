#include "menu.h"

int menu(int bandera1, int bandera2, int num1, int num2)
{
    int opcion=0;
    system("cls");
    printf("***Menu de opciones:***\n\n");
    if(bandera1==0)
    {
        printf("1- Ingresar 1er operando (A='Aun no se ingreso')\n");
    }
    else
    {
        printf("1- Ingresar 1er operando (A=%d)\n",num1);
    }
    if(bandera2==0)
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
    return opcion;
}
