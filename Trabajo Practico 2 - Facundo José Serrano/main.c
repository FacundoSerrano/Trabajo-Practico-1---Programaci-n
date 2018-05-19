#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define TAMPER 20

int main()
{
    int opcion;

    ePersona personas[TAMPER];

    ePersona_init(personas, TAMPER);

    do
    {
        printf("\nSeleccione una opcion: \n");
        printf("\n1. Agregar una persona");
        printf("\n2. Borrar una persona");
        printf("\n3. Imprimir lista ordenada por nombre");
        printf("\n4. Imprimir grafico de edades");
        printf("\n5. Salir\n\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                ePersona_alta(personas, TAMPER);
                break;
            case 2:
                ePersona_borrar(personas, TAMPER);
                break;
            case 3:
                ePersona_ordenar(personas, TAMPER);
                break;
            case 4:
                ePersona_GraficoEdades(personas, TAMPER);
                break;
        }
    }
    while(opcion != 5);
}
