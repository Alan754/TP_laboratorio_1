#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000


int menu()
{
    int opcion;


    printf("-------Inicie carga de empleados-------\n\n");

    printf("1. Alta \n");
    printf("2. Modificar \n");
    printf("3. Baja \n");
    printf("4. Informar \n");
    printf("5. Salir \n");

    printf("Por favor elija una opcion: \n");
    fflush(stdin);
    scanf("%d",&opcion);
    while(opcion<1 || opcion>5)
    {
        printf("ERROR!!!por favor elijha una opcion: \n");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    return opcion;
}

int inicializarEmpleados(ePersona empleados[],int tam)
{
    int error = 1;

    if(empleados != NULL && tam > 0 )
    {
        for(int i = 0; i < tam; i++)
        {
            empleados[i].isEmpty = 1;
        }

        error = 0;

    }
    return error;
}

int mostrarEmpleados(ePersona empleados[],int tam)
{
    int flag = 0;
    int error = 1;
    if(empleados != NULL && tam > 0 )
    {
        printf("\n  ID  NOMBRE  APELLIDO  SECTOR  SALARIO  \n");
        printf("-----------------------------------------  \n");

        for(int i = 0; i < tam; i++)
        {
            if(empleados[i].isEmpty == 0)
            {
                mostrarEmpleado(empleados[i]);

                flag = 1;
            }
        }

        if(!flag)
        {
            printf("\n No hay empleados en la lista\n\n");
        }
        else
        {
            printf("\n\n");
        }

        error = 0;
    }
    return error;
}
int mostrarEmpleado(ePersona unEmpleado)
{
    printf("%2d    %4s  %4s  %4d      %.2f  \n",unEmpleado.id, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sector, unEmpleado.salario );

    return 0;

}

int altaEmpleados(ePersona empleados[], int tam, int id)
{
    int error = 1;
    ePersona nuevoEmpleado;
    int indice;
    if(empleados != NULL && tam > 0 && id > 0 )
    {
        indice = buscarLibre(empleados, tam);
        if(indice == -1)
        {
            printf(" Lo siento sistema completo!!! \n");
        }
        else
        {
            nuevoEmpleado.id = id;
            nuevoEmpleado.isEmpty = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);
            printf("Ingrese sector: ");
            scanf("%d", &nuevoEmpleado.sector);
            printf("Ingrese sueldo: ");
            scanf("%f", &nuevoEmpleado.salario);
            while(nuevoEmpleado.salario < 0)
            {
                printf("ERROR!!!Reingrese sueldo: ");
                scanf("%f", &nuevoEmpleado.salario);
            }

            empleados[indice] = nuevoEmpleado;

            error =0;

        }
    }
    return error;
}
int buscarLibre(ePersona empleados[],int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            indice=i;
            break;
        }

    }
    return indice;
}

int buscarEmpleado(ePersona empleados[], int tam, int id)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(empleados[i].id == id && empleados[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int bajaEmpleado(ePersona empleados[],int tam)
{
    system("cls");
    int error = 1;
    int indice;
    int id;
    char confirma;

    if(empleados != NULL && tam > 0 && id> 0 )
    {
        system("cls");
        printf("-----Baja de empleado-----\n\n");
        mostrarEmpleados(empleados,tam);
        printf("Ingrese legajo: ");
        scanf("%d", &id);

        indice=buscarEmpleado(empleados, tam, id);

        if( indice == -1)
        {
            printf("No hay ningun empleado con el id ingresado\n\n");
        }
        else
        {
            mostrarEmpleado(empleados[indice]);
            printf("Confirma baja s(si)/n(no) ?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                empleados[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
    return error;
}

int modificarEmpleado(ePersona empleados[],int tam)
{
    int error = 1;
    int indice;
    int id;
    int opcion;
    ePersona nuevaModificacion;
    char confirma;
    printf("\n\n---Sistema de bajas---\n\n");
    mostrarEmpleados(empleados,tam);

    printf("Ingrese id: ");
    scanf("%d",&id);
    if(empleados !=NULL && tam > 0 && id > 0)
    {


        indice=buscarEmpleado(empleados,tam,id);


        if(indice == -1)
        {
            printf("No existe el id \n");
        }
        else
        {
            mostrarEmpleados(empleados,tam);

            nuevaModificacion=empleados[indice];
            printf("Que desea modificar?\n");
            printf("1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese nombre a modificar: ");
                fflush(stdin);
                gets(nuevaModificacion.nombre);
                break;

            case 2:
                printf("Ingrese apellido a modificar: ");
                fflush(stdin);
                gets(nuevaModificacion.apellido);
                break;

            case 3:
                printf("\nIngrese el salario a modificar: \n ");
                scanf("%f",&nuevaModificacion.salario);
                break;

            case 4:
                printf("Ingrese sector a modificar: ");
                scanf("%d",&nuevaModificacion.sector);
                break;
            }
            printf("\nDesea efectuar el cambio? s(si)/n(no)?\n");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                empleados[indice].salario=nuevaModificacion.salario;
                empleados[indice].sector=nuevaModificacion.sector;
                strcpy(empleados [indice].nombre,nuevaModificacion.nombre);
                strcpy(empleados [indice].apellido,nuevaModificacion.apellido);
                error=0;
            }
            else
            {
                error =2;
            }
        }
    }
    return error;
}

int promedioEmpleados(ePersona listaEmpleado[], int tam)
{
    float PromedioSalario;
    float SalarioTotal = 0;
    int contador = 0;
    int SuperaPromedio = 0;
    int i;
    int indice = -1;

    if(listaEmpleado != NULL && tam >= 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(listaEmpleado[i].isEmpty == 0)
            {
                contador++;
                SalarioTotal = SalarioTotal + listaEmpleado[i].salario;
            }

        }

        PromedioSalario = SalarioTotal / (float)contador;
        for(i = 0; i < tam; i++)
        {
            if(listaEmpleado[i].isEmpty == 0 && listaEmpleado[i].salario > PromedioSalario)
            {
                SuperaPromedio++;
            }
        }
        printf("\nTotal de salarios: %.2f\nPromedio de salarios: %.2f\n", SalarioTotal, PromedioSalario);
        printf("\nCantidad de empleados que superan el salario promedio: %d \n", SuperaPromedio);
        indice = 0;
    }

    return indice;
}


void ordenarEmpleadosApellido(ePersona listaEmpleado[],int cant, int criterio)
{
    int i;
    int j;
    ePersona auxEmpleado;
    // printf("Lista de empleados ordenados por salario y legajo");
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {
            if(strcmp(listaEmpleado[i].apellido,listaEmpleado[j].apellido)>0 && criterio==0)
            {
                auxEmpleado=listaEmpleado[i];
                listaEmpleado[i]=listaEmpleado[j];
                listaEmpleado[j]=auxEmpleado;
            }
            /*else if(strcmp(listaEmpleado[i].lastName,listaEmpleado[j].lastName)<0 && criterio==1)
            {
                 auxEmpleado=listaEmpleado[i];
                listaEmpleado[i]=listaEmpleado[j];
                listaEmpleado[j]=auxEmpleado;
            }*/
        }
    }
}
