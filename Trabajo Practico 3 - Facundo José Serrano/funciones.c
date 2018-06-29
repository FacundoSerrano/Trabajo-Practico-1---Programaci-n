#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int construct_bFile(FILE * pFile)
{
    int code = 1;
    pFile = fopen("binario.bin", "wb");
    if(pFile == NULL)
    {
        code = 0;
    }

    fclose(pFile);
    return code;
}


int addMovie()
{
    FILE* pFile;
    eMovie* movie;
    int retorno = 0;
    movie = (eMovie*)malloc(sizeof(eMovie));
    printf("Ingrese el titulo de la pelicula a agregar, o presione 0 para cancelar.\n");
    fflush(stdin);
    gets(movie->titulo);

    if(!strcmp(movie->titulo, "0"))
    {
        free(movie);
        return retorno;
    }

    printf("Ingrese el genero de la pelicula a agregar, o presione 0 para cancelar.\n");
    fflush(stdin);
    gets(movie->genero);

    if(!strcmp(movie->genero, "0"))
    {
        free(movie);
        return retorno;
    }

    printf("Ingrese la duracion de la pelicula a agregar, o presione 0 para cancelar.\n");
    scanf("%d", &movie->duracion);

    if(movie->duracion == 0)
    {
        free(movie);
        return retorno;
    }

    printf("Ingrese la calificacion de la pelicula a agregar, o presione 0 para cancelar.\n");
    scanf("%d", &movie->calificacion);

    if (movie->calificacion == 0)

    {
        free(movie);
        return retorno;
    }

    printf("Ingrese una descripcion de la pelicula a agregar, o presione 0 para cancelar.\n");
    fflush(stdin);
    gets(movie->descripcion);

    if (!strcmp(movie->descripcion, "0"))
    {
        free(movie);
        return retorno;
    }

    printf("Ingrese el link de la imagen de la pelicula a agregar, o presione 0 para cancelar.\n");
    fflush(stdin);
    gets(movie->linkImage);

    if(!strcmp(movie->linkImage, "0"))
    {
        free(movie);
        return retorno;
    }

    pFile = fopen("binario.bin", "ab");
    fwrite(movie, sizeof(eMovie), 1, pFile);
    fclose(pFile);
    free(movie);
    retorno = 1;

    return retorno;
}

int deleteMovie()
{
    int opcion;
    int i = 1;
    int e = 1;
    int u = 0;
    int retorno = 1;
    int end = 0;

    FILE* pFile;
    FILE* tempFile;
    eMovie* movie;
    movie = (eMovie*)malloc(sizeof(eMovie));

    while(i != 0)
    {
        pFile = fopen("binario.bin","rb");
        fseek(pFile, 0, SEEK_END);
        end = ftell(pFile);
        rewind(pFile);
        i = 0;
        while(ftell(pFile) != end)
        {
            fread(movie, sizeof(eMovie), 1, pFile);
            i++;
            printf("-%d\t-Titulo: %s\t-Genero: %s\t-Duracion: %d\t-Calificacion: %d\n-Descripcion: %s\n", i, movie->titulo, movie->genero, movie->duracion, movie->calificacion, movie->descripcion);
        }



        printf("Ingrese el numero de la pelicula que desea borrar, o presione 0 si quiere salir.");
        scanf("%d", &e);
        if(e != 0)
        {
            rewind(pFile);
            for(u = 1; u <= e; u++)
            {
                fseek(pFile,sizeof(eMovie),SEEK_CUR);
            }
            fread(movie, sizeof(eMovie), 1, pFile);
            printf("Esta seguro de que desea borrar %s?\n1-Si.\n2-No, deseo borrar otra pelicula.\n3-No, no deseo borrar ninguna pelicula.", movie->titulo);
            u = 0;
            while(u < 1 || u > 3)
            {
                scanf("%d", &u);
                switch(u)
                {
                    case 1:
                        fseek(pFile, 0, SEEK_END);
                        end = ftell(pFile);
                        fseek(pFile, 0, SEEK_SET);
                        i = 1;
                        tempFile = fopen("temporario.bin", "wb");

                        while(ftell(pFile) < end)
                        {
                            if(i != e)
                            {
                                fread(movie, sizeof(eMovie), 1, pFile);
                                fwrite(movie, sizeof(eMovie), 1, tempFile);
                            }
                            else
                            {
                                fseek(pFile,sizeof(eMovie),SEEK_CUR);
                            }

                            i++;
                        }
                            if(i == 2)
                            {
                                retorno = 0;
                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin", "binario.bin");
                            i = 0;
                            break;

                        case 2:
                            i = 1;
                            break;

                        case 3:
                            i = 0;
                            fclose(pFile);
                            break;

                        default:
                            printf("Ingrese un numero valido");
                }
            }
        }
        else
        {
            i = 0;
            fclose(pFile);
        }
    }
    free(movie);

    return retorno;
}


void modifyMovie()
{
    int opcion;
    int i = 1;
    int e = 1;
    int u = 0;
    int retorno = 1;
    FILE* pFile;
    FILE* tempFile;
    eMovie* movie;
    char auxChar1[20];
    char auxChar2[100];
    int auxInt;
    int end;
    movie = (eMovie*)malloc(sizeof(eMovie));

    while(i != 0)
    {
        pFile = fopen("binario.bin", "rb");
        fseek(pFile,0,SEEK_END);
        end = ftell(pFile);
        rewind(pFile);
        i = 0;

        while(ftell(pFile) != end)
        {
            fread(movie, sizeof(eMovie), 1, pFile);
            i++;
            printf("-%d\t-Titulo: %s\t-Genero: %s\t-Duracion: %d\t-Calificacion: %d\n-Descripcion: %s\n", i, movie->titulo, movie->genero, movie->duracion, movie->calificacion, movie->descripcion);
        }

        printf("Ingrese el numero de la pelicula que desea modificar, o presione 0 si quiere salir.");
        scanf("%d", &e);

        if(e != 0)
        {
            for(u = 0; u <= e; u++)
            {
                fseek(pFile,(sizeof(eMovie)), SEEK_SET);
            }
            fread(movie, sizeof(eMovie), 1, pFile);
            printf("-Titulo: %s\t-Genero: %s\t-Duracion: %d\t-Calificacion: %d\n-Descripcion: %s\nLink imagen:%s\n", movie->titulo, movie->genero, movie->duracion, movie->calificacion, movie->descripcion, movie->linkImage);
            printf("Seleccione el campo a modificar \n1-Titulo\n2-Genero\n3-Duracion\n4-Calificacion\n5-Descripcion\n6-Link imagen\n7-Modificar otra pelicula\n8-Salir\n", movie->titulo, movie->genero, movie->duracion, movie->calificacion, movie->descripcion, movie->linkImage);
            u = 0;

            while(u < 1 || u > 8)
            {
                scanf("%d", &u);
                switch(u)
                {
                    case 1:
                        printf("\nIngrese un nuevo titulo\n");
                        fflush(stdin);
                        gets(auxChar1);
                        fseek(pFile, 0, SEEK_END);
                        end = ftell(pFile);
                        rewind(pFile);
                        tempFile=fopen("temporario.bin", "wb");
                        i = 1;

                        while(ftell(pFile) != end)
                        {
                            if(i != e)
                            {
                                fread(movie, sizeof(eMovie), 1, pFile);
                                fwrite(movie, sizeof(eMovie), 1, tempFile);
                            }
                            else
                            {
                                fread(movie, sizeof(eMovie), 1, pFile);
                                strcpy(movie->titulo, auxChar1);
                                printf("%s", movie->titulo);
                                fwrite(movie, sizeof(eMovie), 1, tempFile);
                            }

                            i++;
                            }

                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea continuar modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d", &i);
                            if(i == 2)
                            {
                                i = 0;
                            }
                            break;

                        case 2:
                            printf("Ingrese un nuevo genero\n");
                            fflush(stdin);
                            gets(auxChar1);
                            fseek(pFile, 0, SEEK_END);
                            end = ftell(pFile);
                            rewind(pFile);
                            tempFile = fopen("temporario.bin", "wb");
                            i = 1;

                            while(ftell(pFile) != end)
                            {
                                free(movie);
                                movie = (eMovie*)malloc(sizeof(eMovie));
                                if(i != e)
                                {
                                    fread(movie, sizeof(eMovie), 1, pFile);
                                    fwrite(movie, sizeof(eMovie), 1, tempFile);
                                }
                                else
                                {
                                    fread(movie,sizeof(eMovie),1,pFile);
                                    strcpy(movie->genero,auxChar1);
                                    fwrite(movie,sizeof(eMovie),1,tempFile);
                                }

                                i++;
                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin", "binario.bin");
                            printf("Desea continuar modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d", &i);
                            if(i == 2)
                            {
                                i = 0;
                            }
                            break;

                        case 3:
                            printf("\nIngrese la nueva duracion\n");
                            fflush(stdin);
                            scanf("%d",&auxInt);
                            fseek(pFile, 0, SEEK_END);
                            end = ftell(pFile);
                            rewind(pFile);
                            tempFile = fopen("temporario.bin", "wb");
                            i = 1;
                            while(ftell(pFile) != end)
                            {
                                if(i != e)
                                {
                                    fread(movie, sizeof(eMovie), 1, pFile);
                                    fwrite(movie, sizeof(eMovie), 1, tempFile);
                                }
                                else
                                {
                                    fread(movie, sizeof(eMovie), 1, pFile);
                                    movie->duracion = auxInt;
                                    fwrite(movie, sizeof(eMovie), 1, tempFile);
                                }

                                i++;
                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea continuar modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d", &i);
                            if(i == 2)
                            {
                                i = 0;
                            }
                            break;

                        case 4:
                            printf("\nIngrese una nueva calificacion\n");
                            fflush(stdin);
                            scanf("%d", &auxInt);
                            fseek(pFile, 0, SEEK_END);
                            end = ftell(pFile);
                            rewind(pFile);
                            tempFile = fopen("temporario.bin", "wb");
                            i = 1;
                            while(ftell(pFile) != end)
                            {
                                if(i != e)
                                {
                                    fread(movie, sizeof(eMovie), 1, pFile);
                                    fwrite(movie, sizeof(eMovie), 1, tempFile);
                                }
                                else
                                {
                                    fread(movie, sizeof(eMovie), 1, pFile);
                                    movie->calificacion = auxInt;
                                    fwrite(movie, sizeof(eMovie), 1, tempFile);
                                }

                                i++;
                            }

                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin","binario.bin");
                            printf("Desea continuar modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d", &i);
                            if(i == 2)
                            {
                                i = 0;
                            }
                            break;

                        case 5:
                            printf("\nIngrese una nueva descripcion\n");
                            fflush(stdin);
                            gets(auxChar2);
                            fseek(pFile, 0, SEEK_END);
                            end = ftell(pFile);
                            rewind(pFile);
                            tempFile = fopen("temporario.bin", "wb");
                            i = 1;
                            while(ftell(pFile) != end)
                            {
                                if(i != e)
                                {
                                    fread(movie, sizeof(eMovie), 1, pFile);
                                    fwrite(movie, sizeof(eMovie), 1, tempFile);
                                }
                                else
                                {
                                    fread(movie,sizeof(eMovie), 1, pFile);
                                    strcpy(movie->descripcion, auxChar2);
                                    fwrite(movie,sizeof(eMovie), 1, tempFile);
                                }

                                i++;
                            }
                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin", "binario.bin");
                            printf("Desea continuar modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d", &i);
                            if(i == 2)
                            {
                                i = 0;
                            }
                            break;

                        case 6:
                            printf("\nIngrese un nuevo link de imagen\n");
                            fflush(stdin);
                            gets(auxChar2);
                            fseek(pFile,0,SEEK_END);
                            end = ftell(pFile);
                            rewind(pFile);
                            tempFile = fopen("temporario.bin", "wb");
                            i = 1;
                            while(ftell(pFile) != end)
                            {
                                if(i != e)
                                {
                                    fread(movie, sizeof(eMovie), 1, pFile);
                                    fwrite(movie, sizeof(eMovie), 1, tempFile);

                                }
                                else
                                {
                                    fread(movie, sizeof(eMovie), 1, pFile);
                                    strcpy(movie->linkImage, auxChar2);
                                    fwrite(movie, sizeof(eMovie), 1, tempFile);
                                }

                                i++;
                            }

                            fclose(pFile);
                            fclose(tempFile);
                            remove("binario.bin");
                            rename("temporario.bin", "binario.bin");
                            printf("Desea continuar modificando la pelicula?\n1-Si\n2-No\n");
                            scanf("%d", &i);
                            if(i == 2)
                            {
                                i = 0;
                            }
                            break;

                        case 7:
                            i = 1;
                            break;

                        case 8:
                            i = 0;
                            break;

                        default:
                            printf("\nIngrese un numero valido\n");
                    }
            }
        }
        else
        {
            i = 0;
        }
    }
    free(movie);
}

void genSite()
{
    FILE* pFile;
    FILE* htmlFile;
    eMovie* movie;
    int end;
    pFile = fopen("binario.bin", "rb");
    movie = (eMovie*)malloc(sizeof(eMovie));
    htmlFile = fopen("index.html", "w");

    fseek(pFile, 0, SEEK_END);
    end = ftell(pFile);
    rewind(pFile);
    fprintf(htmlFile, "<!DOCTYPE html>"
  "<!-- Template by Quackit.com -->"
  "<html lang='en'>"
  "<head>"
  "  <meta charset='utf-8'>"
  "  <meta http-equiv='X-UA-Compatible' content='IE=edge'>"
  "  <meta name='viewport' content='width=device-width, initial-scale=1'>"
  "  <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
  "  <title>Lista peliculas</title>"
  "  <!-- Bootstrap Core CSS -->"
  "  <link href='css/bootstrap.min.css' rel='stylesheet'>"
  "  <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
  " <link href='css/custom.css' rel='stylesheet'>"
  "  <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
  "  <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
  "  <!--[if lt IE 9]>"
  " <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
  "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
  "<![endif]-->"
  "</head>"
  "<body>"
  "<div class='container'>"
  "<div class='row'>");

    while(ftell(pFile) != end)
    {
        fread(movie, sizeof(eMovie), 1, pFile);
        fprintf(htmlFile, "<!-- Repetir esto para todas las peliculas -->\n");
        fprintf(htmlFile, "<article class='col-md-4 article-intro'>\n<a href='#'>\n");
        fprintf(htmlFile, "<img class='img-responsive img-rounded' src='%s' alt=''>\n </a>\n  <h3>\n  <a href='#'>%s</a>\n  </h3>\n<ul>\n", movie->linkImage, movie->titulo);
        fprintf(htmlFile, "<li>Género:%s</li>\n<li>Calificacion:%d</li>\n<li>Duración:%d min</li>\n</ul>\n",movie->genero, movie->calificacion, movie->duracion);
        fprintf(htmlFile, "<p>%s</p>\n </article>\n<!-- Repetir esto para cada pelicula -->", movie->descripcion);
    }
       fprintf(htmlFile, "</div>"
  "<!-- /.row -->"
  "</div>"
  "<!-- /.container -->"
  "<!-- jQuery -->"
  "<script src='js/jquery-1.11.3.min.js'></script>"
  "<!-- Bootstrap Core JavaScript -->"
  "<script src='js/bootstrap.min.js'></script>"
  "<!-- IE10 viewport bug workaround -->"
  "<script src='js/ie10-viewport-bug-workaround.js'></script>"
  "<!-- Placeholder Images -->"
  "<script src='js/holder.min.js'></script>"
  "</body>"
  "</html>");
    fclose(pFile);
    fclose(htmlFile);
}

