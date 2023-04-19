#pragma once
#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Ciclista {
protected:
	int _horasEntrenam;
	double _temPromedio;
public:
	Ciclista(int, double);
	virtual ~Ciclista();
	void setHorasEntre(int);
	void setTempPro(double);
	int getHorasEntrenamiento();
	double getTempProm();
	virtual string toString();
};