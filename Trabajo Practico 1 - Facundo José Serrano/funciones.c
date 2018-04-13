#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

int fmenu(int operando1, int operando2, bool flag1, bool flag2)
{
    int opcion = 0;

    if(flag1 != true)
    {
        printf("\n1. Ingresar el 1er operando (A=%c)", (char)operando1);
    }
    else
    {
        printf("\n1. Ingresar el 1er operando (A=%d)", operando1);
    }
    if(flag2 != true)
    {
        printf("\n2. Ingresar el 2do operando (B=%c)", (char)operando2);
    }
    else
    {
        printf("\n1. Ingresar el 2do operando (A=%d)", operando2);
    }
    printf("\n3. Calcular la suma (A+B)");
    printf("\n4. Calcular la resta (A-B)");
    printf("\n5. Calcular la division (A/B)");
    printf("\n6. Calcular el producto (A*B)");
    printf("\n7. Calcular el factorial (A!)");
    printf("\n8. Calcular todas las operaciones");
    printf("\n9. Salir");
    printf("\n\nIngrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

int foperando1()
{
    int operando1;
    printf("\nIngrese el 1er operando: ");
    fflush(stdin);
    scanf("%d", &operando1);
    return operando1;
}

int foperando2()
{
    int operando2;
    printf("\nIngrese el 2do operando: ");
    fflush(stdin);
    scanf("%d", &operando2);
    return operando2;
}

void fsuma(int operando1, int operando2, bool flag1, bool flag2)
{
    if(flag1 != true || flag2 != true)
    {
        printf("\nPara hacer la suma debe ingresar los operandos\n");
    }
    else
    {
    printf("\nLa suma de A+B es: %d\n", (operando1 + operando2));
    }
}

void fresta(int operando1, int operando2, bool flag1, bool flag2)
{
    if(flag1 != true || flag2 != true)
    {
        printf("\nPara hacer la resta debe ingresar los operandos\n");
    }
    else
    {
    printf("\nLa resta de A-B es: %d\n", (operando1 - operando2));
    }
}

void fdivision(int operando1, int operando2, bool flag1, bool flag2)
{
    if(flag1 != true || flag2 != true)
    {
        printf("\nPara hacer la division debe ingresar los operandos\n");
    }
    else
    {
        if(operando2 == 0)
        {
            printf("No se puede dividir por 0");
        }
        else
        {
        printf("\nEl resultado de de A/B es: %.2f\n", ((float)operando1 / (float)operando2));
        }
    }
}

void fmultiplicacion(int operando1, int operando2, bool flag1, bool flag2)
{
    if(flag1 != true || flag2 != true)
    {
        printf("\nPara hacer la multiplicacion debe ingresar los operandos\n");
    }
    else
    {
    printf("\nEl producto de A*B es: %d\n", (operando1 * operando2));
    }
}

void ffactorial(int operando1, bool flag1)
{
    if(flag1 != true)
    {
        printf("\nPara hacer el factorial debe ingresar el 1er operando\n");
    }
    else
    {
        if(operando1 < 0)
        {
            printf("\nDebe ingresar un numero entero positivo\n");
        }
        else
        {
        int factorial = 1;
        int temp;
        for(temp = operando1; temp > 1; temp --)
            {
                factorial = factorial * temp;
            }
        printf("\nEl factorial de A es: %d\n", factorial);
        }
    }
}
