#include "factorial.h"


int calcularFactorialA(int num1)
{
    int factorialA = 1;

    for(int i=1; i<=num1; i++)
    {
        factorialA = factorialA*i;
    }

    return factorialA;

}


