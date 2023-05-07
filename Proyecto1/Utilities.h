#pragma once
#include <iostream>
#include<sstream>
#include "Fecha.h"
#include "Execpciones.h"
using namespace std;

//RECIVIR----------------------
int recivirInt();
string recivirString();
string recivirStringN();
string recivirGetLine();
char recivirChar();
//puede que lo cambiemos a char*
double recivirDouble();
bool recivirBool();
//IMPRIMIR---------------------
void imprimirString(string);
void imprimirString2(string);
void imprimirInt(int);
void imprimirInt2(int);
void imprimirChar(char);
void imprimirDouble(double);
//VALIDACIONES-----------------
	//preguuntar si cada uno de estos tiene que ir en una clase / .h y cpp separados
Fecha* validarFecha();
Fecha* validarFechaA(string); //validacion exclusiva para archivos
int validarDia(string);
int validarMes(string);
int validarAnnio(string);
char validarDia();
int validarHora(string);
int validarMinuto(string);
//podriamos hacer uno para guardar e imprimir vectores pero no se si sera util asi qu de momnto no
//Otros
void enter();
void limpiarPantalla();
void limpiar();
void ignorarCin();
