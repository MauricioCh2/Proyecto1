#pragma once
#include <iostream>
#include <sstream>
#include "Fecha.h"
using namespace std;

class Deportista {
protected:
	int _cedula;//Cuite los ptr,s porque no son punteros lo que van a almacenar
	string _nombre;
	string _telefono;
	Fecha* _ptrFecha;
public:
	Deportista();
	Deportista(int, string, string, Fecha*);
	virtual ~Deportista();
	virtual void setNombre(string);
	virtual void setCedula(int);
	virtual void setTelefono(string);
	virtual void setFecha(Fecha*);
	virtual string getNombre();
	virtual int getCedula();
	virtual string getTelefono();
	virtual Fecha* getFecha();
	virtual string toString() = 0;
};