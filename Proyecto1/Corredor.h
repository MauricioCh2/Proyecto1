#pragma once
#include "Deportista.h"
class Corredor : public Deportista {
protected:
	char _sexo;
	double _estatura;
public:
	Corredor(char, double);
	virtual ~Corredor();
	void setSexo(char);
	void setEstatura(double);
	char getSexo();
	double getEstatura();
	virtual string toString();
};