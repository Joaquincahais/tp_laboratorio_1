#include "ArrayEmployees.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000



int initEmployees(Employee personas[], int len)
{
    int error = 1;
 if(personas != NULL && len >0)
 {
     for(int i =0; i<len; i++)
     {
         personas[i].isEmpty = 1;
     }
     error = 0;
 }
 return error;
}



int addEmployee(Employee personas[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int error;
    int indexLibre;
    indexLibre = emptyId(personas, TAM);
    Employee nuevoEmpleado;
    if(personas != NULL && len >0)
    {

        nuevoEmpleado.isEmpty = 0;
        nuevoEmpleado.id = id;
        strcpy(nuevoEmpleado.name, name);
        strcpy(nuevoEmpleado.lastName, lastName);
        nuevoEmpleado.salary = salary;
        nuevoEmpleado.sector = sector;

        personas[indexLibre] = nuevoEmpleado;
        error = 0;
    }
     else
     {
        error = -1;
     }

 return error;
}




int printEmployees(Employee personas[], int length)
{
    int error =0;
    printf("ID\t NOMBRE\t\t APELLIDO\t SALARIO\t SECTOR\n");
    printf("--------------------------------------------------------------------\n\n");
 for(int i=0; i<length; i++)
    {
        if(personas[i].isEmpty == 0)
        {
            printEmpleado(personas[i]);
            error = 1;
        }
    }
 return error;
}

int findEmployeeById(Employee personas[], int len, int id)
{
 int resp = -1;
 for(int i=0; i<len; i++)
 {
     if(personas[i].id == id && personas[i].isEmpty ==0)
     {

        printEmpleado(personas[i]);
        resp = i;
     }
 }
 return resp;
}


int removeEmployee(Employee personas[], int len, int id)
{
    int error = -1;
        if(personas != NULL && len >0)
     {
         personas[id].isEmpty = 1;
         error = 0;
     }

    return error;
}

int sortEmployees(Employee personas[], int len, int order)
{
    int error = -1;
    Employee auxPersona;
 if(personas != NULL && len >0)
 {
     for(int i=0; i<len-1; i++)
     {
         for(int j=0; j<len; j++)
         {
            if((strcmp(personas[i].lastName, personas[j].lastName) < 0  ) && order == 0)
            {
                auxPersona = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersona;
            }

         }
     }
     error = 0;
 }
 return error;
}


