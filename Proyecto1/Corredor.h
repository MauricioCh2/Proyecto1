#pragma once
#include "Deportista.h"
class Corredor : public Deportista {
protected:
	char _sexo;
	double _estatura;
public:
	Corredor(int, string, string, Fecha*, char, double);
	virtual ~Corredor();
	void setSexo(char);
	void setEstatura(double);
	char getSexo();
	double getEstatura();
	virtual string toString();

	//MVP para clonar
	//Ciclista----------------------------------------
	virtual int getHorasDeEntrenamiento() = 0;
	virtual int getTempPromedio() = 0;
	virtual void setHorasDeEntrenamiento(int) = 0;
	virtual void setTempPromedio(int) = 0;
	//Corredor----------------------------------------
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
	virtual string imprimirPAGOS(int) = 0;
};