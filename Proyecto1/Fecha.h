#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class Fecha {
private:
	int dia;
	int mes;
	int ano;
public:
	Fecha(int, int, int);
	virtual ~Fecha();
	int getDia();
	void setDia(int);
	int getMes();
	void setMes(int);
	int getAno();
	void setAno(int);
	string toString();
	string getIdent();
	bool operator < (const Fecha&)const;
};