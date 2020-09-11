#include "alan.h"
#include <stdlib.h>
#include <stdio.h>

//ECHO POR ALAN PERALTA DNI:42872124

long long int factorialRecursiva(int num1)
{
    long long int factorial = 1;
    if( num1==0 || num1==1 )
    {
        factorial = 1;
    }
    else
    {
        factorial = num1 * factorialRecursiva(num1 - 1);
    }
    return factorial;
}

long long int factorialRecursiva2(int num2)
{
    long long int factorial = 1;
    if( num2==0 || num2==1 )
    {
        factorial = 1;
    }
    else
    {
        factorial = num2 * factorialRecursiva(num2 - 1);
    }
    return factorial;
}
/*mensaje para el probador del codigo no se puede factoriar dos numeros mayores a 20 devido a que la memoria se divide en dos
y toma 10 para uno y 10 para el otro en la zona de factoreo
*/
int multiplicacion(int num1, int num2)
{
    int resultado;
    resultado=num1*num2;
    return resultado;
}

float divicion(int num1, int num2)
{
    float resultado;
    if(num1>=1 || num2>=1)
    {
        resultado=(float)num1/num2;
    }
    else
    {
        printf("No se puede dividir por 0");
    }
    return resultado;
}

int resta(int num1, int num2)
{
    int resultado;
    resultado=num1-num2;
    return resultado;
}

int suma(int num1, int num2)
{
    int resultado;
    resultado=num1+num2;
    return resultado;
}

int menu(numero1,numero2)
{
    system("cls");
    int opcion;
    printf("        Bienvenido a calculadora    \n\n");

    printf("        ****Menu de opciones****     \n\n");

    printf("      Ingrese Las siguientes opciones     \n\n");

    printf("1. Ingrese primer operando (A=%d)\n",numero1);
    printf("2. Ingrese segundo operando (B=%d)\n",numero2);

    printf("3. Calcula todas las operaciones:\n");
    printf("     a) Calcular la suma (A+B)\n");
    printf("     b) Calcular la resta (A-B)\n");
    printf("     c) Calcular la division (A/B)\n");
    printf("     d) Calcular la multiplicacion (A*B)\n");
    printf("     e) Calcular el factorial (A!)\n");

    printf("4. Informar resultados\n");
    printf("   a)El resultado de A+B es: r\n");
    printf("   b)El resultado de A-B es: r\n");
    printf("   c)El resultado de A/B es: r o No es posible dividir por cero\n");
    printf("   d)El resultado de A*B es: r\n");
    printf("   e)El factorial de A es: r1 y El factorial de B es: r2\n");

    printf("5. Salir\n");

    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}



