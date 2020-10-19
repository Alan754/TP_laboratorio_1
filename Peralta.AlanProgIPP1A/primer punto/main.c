#include <stdio.h>
#include <stdlib.h>


float hacerDescuento(float precio);

int main()
{
    int precio;
    printf("Ingrese precio del producto: ");
    scanf("%d",&precio);

    while(precio < 0)
    {
        printf("ERROR!!!Reingrese precio del producto: ");
        scanf("%d",&precio);

    }
    hacerDescuento(precio);


    return 0;
}

float hacerDescuento(float precio)
{

    float descuento=0.05;
    float descuentoRealizado;
    descuentoRealizado = precio-(precio*descuento);
    printf ("El precio total es: %.2f", descuentoRealizado);
    return descuentoRealizado;
}
