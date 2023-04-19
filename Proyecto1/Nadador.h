#pragma once
#include <iostream>
#include <sstream>
//#include "Deportista.h"
using namespace std;
class Nadador {
private:
	double _masaMuscular;
	double _peso;
	double _IMC;
public:
	Nadador(double, double, double);
	virtual ~Nadador();
	void setMasaMuscular(double);
	void setPeso(double);
	void setIMC(double);
	double getMasaMuscular();
	double getPeso();
	double getIMC();
	virtual string toString();
};