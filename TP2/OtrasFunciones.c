#include "OtrasFunciones.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000



int menuOpciones()
{
    int eleccion;
    printf("      EMPLEADOS      \n\n");
    printf("***Menu de opciones***\n\n");
    printf("1- ATLAS: Ingresar empleado.\n");
    printf("2- MODIFICAR: Modificar empleado.\n");
    printf("3- BAJA: Eliminar empleado.\n");
    printf("4- INFORMAR:\n");
    printf("\tListado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("\tTotal y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
    printf("5- SALIR\n\n");

    printf("Ingresar opcion:");
    scanf("%d", &eleccion);

    while(eleccion <1 || eleccion >5)
        {
            printf("Opcion Invalida!");
            fflush(stdin);
            getchar();
            printf("Ingresar opcion:");
            scanf("%d", &eleccion);
        }

    return eleccion;
}


int emptyId(Employee personas[], int len)
{
    int index = -1;

    for(int i=0; i<len; i++)
    {
        if(personas[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int modifyEmployee(Employee personas[], int len, int id)
{
    int error = -1;
    Employee auxMod;
    int respuesta;
        if(personas != NULL && len >0)
     {
         error = 0;
         printf("Que dato desea modificar?\n1- Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Volver al menu\n");
         scanf("%d", &respuesta);
         switch(respuesta)
         {
         case 1:
            {
                printf("Ingrese nombre nuevo: ");
                fflush(stdin);
                gets(auxMod.name);
                strcpy(personas[id].name, auxMod.name);
                break;
            }
         case 2:
            {
                printf("Ingrese Apellido nuevo: ");
                fflush(stdin);
                gets(auxMod.lastName);
                strcpy(personas[id].lastName, auxMod.lastName);
                break;
            }
         case 3:
            {
                auxMod.salary = validarSalario();
                personas[id].salary = auxMod.salary;
                break;
            }
         case 4:
            {
                auxMod.sector = validarSector();
                personas[id].sector = auxMod.sector;
                break;
            }
         case 5:
            {
                error = 1;
                system("cls");
            }

         }

     }

    return error;
}

int informEmployee(Employee personas[], int len)
{
    int error = -1;
    float totalSalarios = 0;
    int cantSalarios = 0;
    float promedioSalarios;
    int superiorSalarios = 0;
    for(int i=0; i<len; i++)
    {
        if(personas[i].isEmpty == 0)
        {
            totalSalarios = totalSalarios + personas[i].salary;
            cantSalarios = cantSalarios + 1;
            error = 0;
        }
    }
    promedioSalarios = totalSalarios/cantSalarios;
    for(int i=0; i<len; i++)
    {
        if(personas[i].isEmpty == 0 && personas[i].salary > promedioSalarios)
        {
            superiorSalarios = superiorSalarios + 1;
        }
    }
    printf("\nTotal salarios: %2.f\n", totalSalarios);
    printf("Promedio de los salarios: %2.f\n", promedioSalarios);
    printf("Empleados que superan el salario promedio: %d\n", superiorSalarios);
    return error;
}

int empleadoCargado(Employee personas[], int len) //Verifica si hay algun empleado cargado
{
    int index = -1;

    for(int i=0; i<len; i++)
    {
        if(personas[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        system("cls");
        printf("ID\t NOMBRE\t\t APELLIDO\t SALARIO\t SECTOR\n");
        printf("--------------------------------------------------------------------\n\n");
        printf("Aun no se han cargado empleados.");
        fflush(stdin);
        getchar();
        system("cls");
    }
    return index;
}

int printEmpleado(Employee personas)
{
    printf("%d\t%s\t\t%s\t\t%2.f\t\t%d\n", personas.id, personas.name, personas.lastName, personas.salary, personas.sector);
 return 0;
}

int validarSector()
{
    int ingresoSec;
    printf("Ingrese sector (1 al 100): ");
    fflush(stdin);
    scanf("%d", &ingresoSec);
    while(ingresoSec<1 || ingresoSec>100)
    {
        printf("Sector invalido!\n");
        fflush(stdin);
        getchar();
        printf("Vuelva a ingresar el sector (1 al 100): ");
        scanf("%d", &ingresoSec);

    }
    return ingresoSec;
}

float validarSalario()
{
    float ingreso;
    printf("Ingresar salario: ");
    fflush(stdin);
    scanf("%f", &ingreso);
    while(ingreso<0)
          {
            printf("Salario invalido!\n");
            fflush(stdin);
            getchar();
            printf("Vuelva a ingresar el salario: ");
            fflush(stdin);
            scanf("%f", &ingreso);

          }
    return ingreso;
}
