#pragma once
#pragma once
#include <iostream>
#include <sstream>
#include <sstream>
#include <string>
#include "Lista_Template.h"
#include "Fecha.h"
#include "stringMOD.h"
using namespace std;

class Expediente {
protected:
	int _cedula;//Cuite los ptr,s porque no son punteros lo que van a almacenar
	string _nombre;
	string _telefono;
	Fecha* _ptrFechadeNaci;
	char _sexo;
	double _estatura;
	double _masaMuscular;
	double _peso;
	double _IMC;
	int _horasEntrenam;
	double _temPromedio;
	int _cantPartIronMan;
	int _cantTriatGanador;
	ListaT<stringMOD>* _lisCursosIdent = NULL;
	ListaT<stringMOD>* _lisGruposIdent = NULL;

	Fecha* _fechaDultimopago;
public:
	Expediente(int, string, string, Fecha*, int, double, char, double, double, double, double, int, int, Fecha*);
	virtual ~Expediente();
	void setNombre(string);
	void setCedula(int);
	void setTelefono(string);
	void setFechaNacimiento(Fecha*);
	string getNombre();
	int getCedula();
	string getIdent();
	string getTelefono();
	Fecha* getFechaNacimiento();
	string toString();
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


	//Cursos----------------------------------------------
	ListaT<stringMOD>* getlisCursosIdent();
	//Grupos----------------------------------------------
	ListaT <stringMOD>* getlisGruposIdent();
};