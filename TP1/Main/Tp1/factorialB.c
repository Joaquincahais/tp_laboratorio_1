#include "factorialB.h"


int calcularFactorialB(int num2)
{
    int factorialB=1;

     for(int e=1; e<=num2; e++)
    {
        factorialB = factorialB*e;
    }

    return factorialB;

}
