#pragma once
#include <iostream>
#include<sstream>
#include "Fecha.h"
using namespace std;

//RECIVIR----------------------
int recivirInt();
string recivirString();
char recivirChar();
//puede que lo cambiemos a char*
double recivirDouble();
bool recivirBool();
//IMPRIMIR---------------------
void imprimirString(string);
void imprimirInt(int);
void imprimirChar(char);
void imprimirDouble(double);
//VALIDACIONES-----------------
	//preguuntar si cada uno de estos tiene que ir en una clase / .h y cpp separados
Fecha* validarFecha();
int validarDia(string);
int validarMes(string);
int validarAnnio(string);


char validarDia(char);
int validarHora(string);
int validarMinuto(string);
//podriamos hacer uno para guardar e imprimir vectores pero no se si sera util asi qu de momnto no
//Otros
void enter();
void limpiarPantalla();
void limpiar();