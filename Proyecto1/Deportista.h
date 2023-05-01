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
	virtual void setFechaNacimiento(Fecha*);
	virtual string getNombre();
	virtual int getCedula();
	virtual string getIdent();
	virtual string getTelefono();
	virtual Fecha* getFechaNacimiento();
	virtual string toString() = 0;

	
	//MVP para clonar
	//Ciclista----------------------------------------
	virtual int getHorasDeEntrenamiento() = 0;
	virtual int getTempPromedio() = 0;
	virtual void setHorasDeEntrenamiento(int) = 0;
	virtual void setTempPromedio(int) = 0;
	//Corredor----------------------------------------
	virtual char getSexo() = 0;
	virtual double getEstatura() = 0;
	virtual void setSexo(char) = 0;
	virtual void setEstatura(double) = 0;
	//Nadado------------------------------------------
	virtual double getMasaMuscular() = 0;
	virtual double getPeso() = 0;
	virtual double getPorcGrasaCorporal() = 0;
	virtual void setMasaMuscular(double) = 0;
	virtual void setPeso(double) = 0;
	virtual void setPorcGrasaCorporal(double) = 0;
	//Triatlonista------------------------------------
	virtual int getCanPartIronMan() = 0;
	virtual int getCanTriatGanador() = 0;
	virtual void setCanPartIronMan(int) = 0;
	virtual void setCanTriatGanador(int) = 0;
	virtual Fecha* getFechaDeultimoPago() = 0;
	virtual void setFechaDeultimoPago(Fecha*) = 0;
};