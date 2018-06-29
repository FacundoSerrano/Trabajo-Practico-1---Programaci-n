#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char continuar = 's';
    int flag = 0;
    int error;
    int opcion = 0;

    FILE * bFile;
    error = construct_bFile(bFile);

    if (error == 0)
    {
        printf("Error al crear el archivo. Contacte al administrador de su sistema");
    }
    else
    {
        while(continuar == 's')
        {
            printf("\n1- Agregar pelicula\n");
            printf("2- Borrar pelicula\n");
            printf("3- Modificar pelicula\n");
            printf("4- Crear sitio web\n");
            printf("5- Salir\n\n");

            scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    flag = addMovie();
                    break;

                case 2:
                    if(flag != 1)
                    {
                        printf("Debe existir al menos una pelicula para poder borrarla.\n");
                    }
                    else
                    {
                        flag = deleteMovie();
                    }
                    break;

                case 3:
                    if(flag != 1)
                    {
                        printf("Debe existir al menos una pelicula para poder modificarla.\n");
                    }
                    else
                    {
                        modifyMovie();
                    }
                    break;

                case 4:
                    if(flag != 1)
                    {
                        printf("Debe existir al menos una pelicula para poder generar un sitio web.\n");
                    }
                    else
                    {
                        genSite();
                    }
                    break;

                case 5:
                    continuar = 'n';
                    break;
            }
        }
    }

    return 0;
}
