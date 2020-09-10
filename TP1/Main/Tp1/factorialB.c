#include "factorialB.h"


int calcularFactorialB(int num2)
{
    int factorialB=1;

    if(num2<0)
    {
        return 0;
    }
    else
    {
        for(int e=1; e<=num2; e++)
        {
            factorialB = factorialB*e;
        }

    return factorialB;
    }

}
