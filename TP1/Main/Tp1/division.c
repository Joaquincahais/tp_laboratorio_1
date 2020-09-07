#include "division.h"

float calcularDivision(int num1, int num2)
{
    float division;
    division = (float) num1/num2;
    if(num2==0)
    {
        return 0;
    }
    else
    {
       return division;
    }

}
