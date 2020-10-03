#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "OtrasFunciones.h"
#define TAM 10




int main()
{
    Employee lista[TAM];

    int salir = 0;
    int respSalir;
    int opcionElegida;
    char nombre[51];
    char apellido[51];
    float salario;
    int sectorIng;
    int inicializacion;
    int addRespuesta;
    int idOtorgado = 999;
    int verifEmpleado;

    inicializacion = initEmployees(lista, TAM);
    if(inicializacion)
    {
        printf("Error!.\nNo se pudo inicializar el programa.\n\n");
    }
    else
    {
        printf("Programa inicializado.\n\n");
    }

    while(salir == 0)
    {
       opcionElegida = menuOpciones();

       switch(opcionElegida)
       {
           case 1:
            {


                int respuestaId;
                respuestaId = emptyId(lista, TAM);
                idOtorgado = idOtorgado +1;
                if(respuestaId == -1)
                {
                    system("cls");
                    printf("No hay espacio para agregar un nuevo empleado.\n");
                    getchar();
                    system("cls");
                }
                else
                {
                    printf("Ingrese nombre:");
                    fflush(stdin);
                    gets(nombre);
                    printf("Ingrese Apellido:");
                    fflush(stdin);
                    gets(apellido);
                    salario = validarSalario();
                    sectorIng = validarSector();

                    addRespuesta = addEmployee(lista, TAM, idOtorgado, nombre, apellido, salario, sectorIng);

                    if(addRespuesta == 0)
                    {
                    system("cls");
                    printf("Empleado agregado exitosamente!.\n\n");
                    printf("ID\t NOMBRE\t\t APELLIDO\t SALARIO\t SECTOR\n");
                    printf("--------------------------------------------------------------------\n\n");
                    printEmpleado(lista[respuestaId]);
                    fflush(stdin);
                    getchar();
                    system("cls");
                    }
                    else
                    {
                    system("cls");
                    printf("Error al agregar empleado!\n");
                    getchar();
                    system("cls");
                    }
                }
                break;

            }
            case 2:
            {

                verifEmpleado = empleadoCargado(lista, TAM);
                if(verifEmpleado != -1)//Verifica si hay algun empleado cargado
                {
                   system("cls");
                    int idEmpMod;
                    printEmployees(lista, TAM);
                    printf("\nIngrese ID del empleado a modificar: ");
                    scanf("%d", &idEmpMod);
                    int empleadoEncontrado = findEmployeeById(lista, TAM,idEmpMod);
                    if(empleadoEncontrado == -1)
                    {
                    system("cls");
                    printf("No se encuentra el empleado con ese ID!");
                    fflush(stdin);
                    getchar();
                    system("cls");
                    }

                    else
                    {
                        int respMod;
                        respMod = modifyEmployee(lista, TAM, empleadoEncontrado);
                        if(respMod == -1)
                        {
                            printf("Error al modificar el empleado;");
                            fflush(stdin);
                            getchar();
                            system("cls");
                        }
                        else if(respMod == 0)
                        {
                            printf("El empleado se modifico exitosamente!;");
                            fflush(stdin);
                            getchar();
                            system("cls");
                        }
                    }
                    }

                break;
            }

            case 3:
                {
                        verifEmpleado = empleadoCargado(lista, TAM);
                        if(verifEmpleado != -1)
                        {
                           system("cls");
                        int idEmpMod;
                        printEmployees(lista, TAM);
                        printf("\nIngrese ID de empleado a eliminar: ");
                        scanf("%d", &idEmpMod);
                        int empleadoEncontrado = findEmployeeById(lista, TAM,idEmpMod);
                        if(empleadoEncontrado == -1)
                        {
                        system("cls");
                        printf("No se encuentra el empleado con ese ID.");
                        fflush(stdin);
                        getchar();
                        system("cls");
                        }

                        else
                        {
                            char pregEliminar;
                            printf("Desea eliminar el empleado? s/n\n");
                            fflush(stdin);
                            scanf("%c", &pregEliminar);
                            if(pregEliminar == 's')
                            {
                                int resRemove;
                                resRemove = removeEmployee(lista, TAM, empleadoEncontrado);
                                if(resRemove == 0)
                                {
                                    printf("Se elimino el empleado!.");
                                    fflush(stdin);
                                    getchar();
                                    system("cls");
                                }
                                else if(resRemove == -1)
                                {
                                    printf("Error al eliminar el empleado.");
                                    fflush(stdin);
                                    getchar();
                                    system("cls");
                                }
                            }

                        }
                        }

                    break;
                }

           case 4:
            {
                verifEmpleado = empleadoCargado(lista, TAM);
                if(verifEmpleado != -1)
                {
                    int respuestaPrint;
                    int resOrden;
                    int respResultado;
                    system("cls");
                    resOrden = sortEmployees(lista, TAM, 0);
                    respuestaPrint = printEmployees(lista, TAM);
                    respResultado = informEmployee(lista, TAM);
                    if(resOrden == 0 && respuestaPrint == 1 && respResultado == 0)
                    {
                        fflush(stdin);
                        getchar();
                        system("cls");
                    }
                    else
                    {
                        system("cls");
                        printf("Error al mostrar empleados.");
                        fflush(stdin);
                        getchar();
                        system("cls");
                    }
                }

                break;

            }
           case 5:
            {

                printf("Desea salir?\n1-Si\n2-No\n");
                fflush(stdin);
                scanf("%d", &respSalir);
                if(respSalir == 1)
                {
                   salir = 1;
                }
                system("cls");

            }

     }
    }

    return 0;
}

