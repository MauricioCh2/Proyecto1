#pragma once
#include "Ciclista.h"
#include "Corredor.h"
#include "Nadador.h"
#include "Fecha.h"
class Triatlonista : public Corredor {
protected:
	int _cantPartIronMan;
	int _cantTriatGanador;
	Ciclista* _ptrCiclista;
	//Corredor* _ptrCorredor;
	Nadador* _ptrNad;
public:
	Triatlonista(string, string, string, Fecha*, int, double, char, double, double, double, double, int, int);

	int getCanPartIronMan();
	int getCanTriatGanador();
	void setCanPartIronMan(int);
	void getCanTriatGanador(int);
	virtual ~Triatlonista();
	virtual string toString();
	/*Fecha* getFecha();
	void setFecha(Fecha*);*/

};