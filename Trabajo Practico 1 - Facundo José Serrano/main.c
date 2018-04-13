#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <stdbool.h>

int main()
{
    float operando1 = 88;
    float operando2 = 89;
    bool flag1 = false;
    bool flag2 = false;
    int opcion;

    do
    {
        opcion = fmenu(operando1, operando2, flag1, flag2);

        switch(opcion)
        {
            case 1:
                operando1 = foperando1();
                flag1 = true;
            break;

            case 2:
                operando2 = foperando2();
                flag2 = true;
            break;

            case 3:
                fsuma(operando1, operando2, flag1, flag2);
            break;

            case 4:
                fresta(operando1, operando2, flag1, flag2);
            break;

            case 5:
                fdivision(operando1, operando2, flag1, flag2);
            break;

            case 6:
                fmultiplicacion(operando1, operando2, flag1, flag2);
            break;

            case 7:
                ffactorial(operando1, flag1);
            break;

            case 8:
                fsuma(operando1, operando2, flag1, flag2);
                fresta(operando1, operando2, flag1, flag2);
                fdivision(operando1, operando2, flag1, flag2);
                fmultiplicacion(operando1,operando2, flag1, flag2);
                ffactorial(operando1, flag1);
            break;

            default:
                printf("\nDebe ingresar una opcion\n");
                opcion = 9;
            break;
        }
    }
    while (opcion != 9);
}
