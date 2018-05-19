#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define LIBRE 1
#define OCUPADO 0

void ePersona_init(ePersona personas[], int limite)
{
    int i;
    if(limite > 0 && personas != NULL)
    {
        for(i = 0; i < limite; i++)
        {
            personas[i].estado = LIBRE;
        }
    }
}

int ePersona_buscarLugarLibre(ePersona personas[], int limite)
{
    int retorno;
    int i;
    if(limite > 0 && personas != NULL)
    {
        retorno = -2;
        for(i = 0; i < limite; i++)
        {
            if(personas[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void ePersona_alta(ePersona personas[], int limite)
{
    int indice;
    if(limite > 0 && personas != NULL)
    {
        indice = ePersona_buscarLugarLibre(personas, limite);
        if(indice >= 0)
        {
            printf("\nIngrese el nombre: ");
            fflush(stdin);
            gets(personas[indice].nombre);
            printf("\nIngrese la edad: ");
            scanf("%d", &personas[indice].edad);
            printf("\nIngrese el DNI: ");
            scanf("%d", &personas[indice].dni);
            personas[indice].estado = OCUPADO;
        }
        else
        {
            printf("\n\nNo se pueden cargar mas personas.\n\n");
        }
    }
}

void ePersona_mostrarListado(ePersona personas[], int limite)
{
    int i;
    if(limite > 0 && personas != NULL)
    {
        printf("Nombre\t\tEdad\t\tDNI\n");
        for(i = 0; i < limite; i++)
        {
            if(personas[i].estado == OCUPADO)
            {
                printf("%s", personas[i].nombre);
                printf(" ");
                printf("\t%d", personas[i].edad);
                printf(" ");
                printf("\t\t%d\n", personas[i].dni);
            }
        }
    }
}

void ePersona_borrar(ePersona personas[], int limite)
{
    int i;
    int dni;
    int flag = 0;
    char resp;
    ePersona_mostrarListado(personas, limite);
    printf("\nIngrese DNI de la persona a borrar: ");
    scanf("%d", &dni);
    for(i = 0; i < limite; i++)
    {
        if(personas[i].dni == dni)
        {
            flag = -1;
            printf("\nDesea dar de baja a %s, DNI: %d?", personas[i].nombre, personas[i].dni);
            printf("\nIngrese 's' para confirmar, o presione cualquier otra tecla para cancelar: ");
            fflush(stdin);
            scanf("%c", &resp);
            if(resp == 's')
            {
                personas[i].estado = LIBRE;
                printf("\nLa baja se ha realizado correctamente.\n");
            }
            else
            {
                printf("\nLa baja ha sido cancelada.\n");
            }
        }
    }
    if(i == limite && flag == 0)
        {
            printf("\nLa persona ingresada no existe\n");
        }
}

void ePersona_ordenar(ePersona personas[],int limite)
{
    char name[50];
    int age;
    int documento;
    int i;
    int j;
    for(i = 0; i < limite - 1; i++)
    {
        for(j = i + 1; j < limite; j++)
        {
            if(personas[i].estado == OCUPADO && personas[j].estado == OCUPADO)
            {
                if(strcmp(personas[i].nombre, personas[j].nombre) > 0)
                {
                    strcpy(name, personas[i].nombre);
                    strcpy(personas[i].nombre, personas[j].nombre);
                    strcpy(personas[j].nombre, name);
                    age = personas[i].edad;
                    personas[i].edad = personas[j].edad;
                    personas[j].edad = age;
                    documento = personas[i].dni;
                    personas[i].dni = personas[j].dni;
                    personas[j].dni = documento;
                }
            }
        }
    }
    ePersona_mostrarListado(personas, limite);
}

void ePersona_GraficoEdades(ePersona personas[],int limite)
{
    int i;
    int menor = 0;
    int medio = 0;
    int mayor = 0;
    for(i = 0; i < limite; i++)
    {
        if(personas[i].estado != LIBRE)
        {
            if(personas[i].edad <= 18)
            {
                menor++;
            }
            else if(personas[i].edad > 18 && personas[i].edad < 35)
            {
                medio++;
            }
            else
            {
                mayor++;
            }
        }
    }
    if(menor != 0 || medio != 0 || mayor != 0)
    {
        printf("Grafico de edades: \n\n");
        for(i = limite; i >= 0; i--)
        {
            if((menor - i) > 0)
            {
                printf(" *  |");
            }
            else
            {
                printf("    |");
            }
            if((medio-i) > 0)
            {
                printf("   *   |");
            }
            else
            {
                printf("       |");
            }
            if((mayor - i) > 0)
            {
                printf("  *");
            }
            printf("\n");
        }
        printf("<18   19-35   >35\n");
    }
    else
    {
        printf("Grafico de edades: \n");
        printf("No se han cargado personas.\n");
    }
}
