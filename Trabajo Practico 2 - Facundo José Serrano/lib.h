#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    char nombre[25];
    int edad;
    int dni;
    int estado;
}ePersona;

void ePersona_init(ePersona personas[], int limite);
/*
- Se utiliza para incializar el array de la estructura ePersona.
- Se pasa el vector de estructura.
- Se pasa el tama�o m�ximo del vector.
*/

int ePersona_buscarLugarLibre(ePersona personas[], int limite);
/*
- Se utiliza para buscar una posici�n del vector que est� libre.
- Se pasa el vector de estructura.
- Se pasa el tama�o m�ximo del vector.
*/

void ePersona_alta(ePersona personas[], int limite);
/*
- Se utiliza para completar los campos de una posici�n del vector de la estructura ePersona.
- Se pasa el vector de estructura.
- Se pasa el tama�o m�ximo del vector.
*/

void ePersona_mostrarListado(ePersona personas[], int limite);
/*
- Se utiliza para incializar el array de la estructura ePersona.
- Se pasa el vector de estructura.
- Se pasa el tama�o m�ximo del vector.
*/

void ePersona_borrar(ePersona personas[], int limite);
/*
- Se utiliza para hacer la baja l�gica de una posici�n del array de la estructura ePersona.
- Se pasa el vector de estructura.
- Se pasa el tama�o m�ximo del vector.
*/

void ePersona_ordenar(ePersona personas[],int limite);
/*
- Se utiliza para ordenar alfabeticamente por nombre las personas cargadas.
- Se pasa el vector de estructura.
- Se pasa el tama�o m�ximo del vector.
*/

void ePersona_GraficoEdades(ePersona personas[],int limite);
/*
- Se utiliza para hacer un gr�fico que representa la cantidad de personas de cada grupo de edad.
- Se pasa el vector de estructura.
- Se pasa el tama�o m�ximo del vector.
*/

#endif // LIB_H_INCLUDED
