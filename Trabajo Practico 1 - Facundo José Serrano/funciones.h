#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdbool.h>

int fmenu(int,int,bool,bool); //Muestra el menú y pide opción
int foperando1(); //Solicita y carga primer operando
int foperando2(); //Solicita y carga el segundo operando
void fsuma(int,int,bool,bool); //Operación y muestra de suma
void fresta(int,int,bool,bool); //Operación y muestra de resta
void fdivision(int,int,bool,bool); //Operación y muestra de división
void fmultiplicacion(int,int,bool,bool); //Operación y muestra de multiplicación
void ffactorial(int,bool); //Operación y muestra de factorial

#endif // FUNCIONES_H_INCLUDED
