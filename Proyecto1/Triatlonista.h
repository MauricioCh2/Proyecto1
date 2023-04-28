#pragma once
#include "Ciclista.h"
#include "Corredor.h"
#include "Nadador.h"
#include "Fecha.h"
class Triatlonista : public Corredor {
protected:
	int _cantPartIronMan;
	int _cantTriatGanador;
	Ciclista* _ptrCiclista;;
	Nadador* _ptrNad;
	Fecha* fechDeuñtimoPago;
public:
	Triatlonista(int, string, string, Fecha*, int, double, char, double, double, double, double, int, int);

	//Deportista--------------------------------------
	string getNombre();
	int getCedula();
	string getTelefono();
	Fecha* fechaNacimiento();
	//Ciclista----------------------------------------
	int getHorasDeEntrenamiento();
	int getTempPromedio();
	//Corredor----------------------------------------
	char getSexo();
	double getEstatura();
	//Nadado------------------------------------------
	double getMasaMuscular();
	double getPeso();
	double getPorcGrasaCorporal();
	//Triatlonista------------------------------------
	int getCanPartIronMan();
	int getCanTriatGanador();
	void setCanPartIronMan(int);
	void setCanTriatGanador(int);
	virtual ~Triatlonista();
	virtual string toString();
	Fecha* getFechaDeultimoPago();
	void setFechaDeultimoPago(Fecha*);

};