#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 3


int main()
{
    int proximoId = 00001;
    int respBaja;
    char salir='s';
    char seguir;
    int flag=0;

    ePersona lista[TAM];

    do
    {
        switch(menu())
        {
        case 1:
            if(flag == 0)
            {
                if(!inicializarEmpleados(lista,TAM))
                {
                    printf("Inicializacion exitosa!!!\n\n");
                }
                else
                {
                    printf("Fallo al inicializar..\n\n");
                }

                mostrarEmpleados(lista, TAM);
                for(int i = 0; i<TAM; i++)
                {
                    if( altaEmpleados(lista,TAM,proximoId) == 0)
                    {
                        proximoId++;
                        printf("\n\nAlta exitosa!!!\n");
                    }
                    else
                    {
                        printf("\n\nNo se pudo realizar el alta...\n");
                    }

                    mostrarEmpleados(lista, TAM);
                }
            flag=1;
            }
            break;
        case 2:
            if(flag==1)
            {
                modificarEmpleado(lista,TAM);
                mostrarEmpleados(lista, TAM);
            }
            else
            {
                printf("Primero debe cargar los empleados para modificar\n");
            }
            break;
        case 3:
            if(flag == 1)
            {
                respBaja = bajaEmpleado(lista,TAM);

                if(respBaja==0)
                {
                    printf("Se realizo la baja con exito!!!\n");
                }
                else
                {
                    if(respBaja == 1)
                    {
                        printf("Problemas al intentar dar de baja reintente por favor\n");
                    }
                    else if(respBaja == 2)
                    {
                        printf("El usuario cancelo la baja\n");
                    }

                }

                mostrarEmpleados(lista, TAM);
            }
            else
            {
                printf("Primero debe cargar empleados para poder dar de baja\n");
            }
            break;
        case 4:
            if(flag == 1)
            {
                promedioEmpleados(lista,TAM);
            }
            else
            {
                printf("Primero debe cargar empleados para poder dar de mostrar ordenado\n");
            }
            break;
        case 5:
            printf("Desea salir ingrese s(si)/n(no)?: ");
            fflush(stdin);
            scanf("%c",&seguir);
            while(seguir!='s' && seguir!='n')
            {
                printf("ERROR!!!por favor ingrese s(si)/n(no)?: ");
                fflush(stdin);
                scanf("%c",&seguir);
            }
            if(seguir=='s')
            {
                salir='n';
            }
            break;
        }
    }
    while(salir=='s');
    return 0;
}
