#include "Fecha.h"

Fecha::Fecha(int d, int m, int a)
{
	dia = d;
	mes = m;
	ano = a;
}

Fecha::~Fecha()
{
}

int Fecha::getDia()
{
	return dia;
}

void Fecha::setDia(int d)
{
	dia = d;
}

int Fecha::getMes()
{
	return mes;
}

void Fecha::setMes(int m)
{
	mes = m;
}

int Fecha::getAno()
{
	return ano;
}

void Fecha::setAno(int a)
{
	ano = a;
}

string Fecha::toString()
{
	stringstream s;
	s << dia << "/" << mes << "/" << ano << endl;
	return s.str();
}

string Fecha::getIdent()
{
	throw new string("buenas tardes");
	return "";
}
