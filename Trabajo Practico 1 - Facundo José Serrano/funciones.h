#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdbool.h>

int fmenu(int,int,bool,bool); //Muestra el men� y pide opci�n
int foperando1(); //Solicita y carga primer operando
int foperando2(); //Solicita y carga el segundo operando
void fsuma(int,int,bool,bool); //Operaci�n y muestra de suma
void fresta(int,int,bool,bool); //Operaci�n y muestra de resta
void fdivision(int,int,bool,bool); //Operaci�n y muestra de divisi�n
void fmultiplicacion(int,int,bool,bool); //Operaci�n y muestra de multiplicaci�n
void ffactorial(int,bool); //Operaci�n y muestra de factorial

#endif // FUNCIONES_H_INCLUDED
