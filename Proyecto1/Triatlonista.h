#pragma once
#include "Ciclista.h"
#include "Corredor.h"
#include "Nadador.h"
#include "Fecha.h"
#include <cmath>
class Triatlonista : public Corredor {
protected:
	int _cantPartIronMan;
	int _cantTriatGanador;
	Ciclista* _ptrCiclista;;
	Nadador* _ptrNad;
	ListaT<Fecha>* ListaDpagos ;
	Iterador<Fecha>* iter1 ;
	Iterador<Fecha>* iter2;

public:
	Triatlonista(int, string, string, Fecha*, int, double, char, double, double, double, double, int, int);

	//Deportista--------------------------------------
	string getNombre();
	int getCedula();
	string getTelefono();
	//Ciclista----------------------------------------
	int getHorasDeEntrenamiento();
	int getTempPromedio();
	void setHorasDeEntrenamiento(int);
	void setTempPromedio(int);
	//Corredor----------------------------------------
	char getSexo();
	double getEstatura();
	void setSexo(char);
	void setEstatura(double);
	//Nadado------------------------------------------
	double getMasaMuscular();
	double getPeso();
	double getPorcGrasaCorporal();
	void setMasaMuscular(double);
	void setPeso(double);
	void setPorcGrasaCorporal(double);
	//Triatlonista------------------------------------
	int getCanPartIronMan();
	int getCanTriatGanador();
	void setCanPartIronMan(int);
	void setCanTriatGanador(int);
	Fecha* getFechaDeultimoPago();
	void setFechaDeultimoPago(Fecha*);
	string imprimirPAGOS(int);
	virtual ~Triatlonista();
	string Listar();
	string toString();


	//MVP para clonar
	//Ciclista----------------------------------------
	//Corredor----------------------------------------
	// 
	//Nadado------------------------------------------
	//Triatlonista------------------------------------
};