#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char titulo[20];
    char genero[20];
    char descripcion[100];
    char linkImage[100];
    int duracion;
    int calificacion;
}eMovie;


/**
 *  Agrega una pelicula al archivo
 *  @param estructura a agregar al archivo
 *  @return retorna 1 o 0 dependiendo de si pudo agregar la pelicula
 */
int addMovie(void);


/**
 *  Borra una pelicula del archivo
 *  @return retorna 1 o 0 dependiendo de si quedan peliculas por eliminar
 */
int deleteMovie(void);


/**
 *  Modifica una pelicula del archivo
 */
void modifyMovie(void);


/**
 *  Genera un archivo .html a con las peliculas creadas en el archivo
 *  @param lista de peliculas a agregar en el archivo
 *  @param nombre del archivo.
 */
void genSite();


/**
 *  Genera un archivo a utilizar
 *  @param lista de peliculas a agregar en el archivo.
 *  @return retorna 1 o 0 dependiendo de si logra crear el archivo
 */
int construct_bFile(FILE *);


#endif // FUNCIONES_H_INCLUDED
