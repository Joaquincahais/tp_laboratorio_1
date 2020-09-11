#include "factorial.h"


int calcularFactorialA(int num1)
{
    int factorialA = 1;

    if(num1<0)
    {
        return 0;
    }
    else
    {
        if(num1>16)
        {
            return -1;
        }
        else
        {
           for(int i=1; i<=num1; i++)
        {
            factorialA = factorialA*i;
        }
        return factorialA;
        }

    }

}


