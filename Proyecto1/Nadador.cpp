#include "Nadador.h"
Nadador::Nadador(double imc, double peso, double masaMuscular) {
	this->_IMC = imc;
	this->_peso = peso;
	this->_masaMuscular = masaMuscular;

}
Nadador:: ~Nadador() {

}
void Nadador::setMasaMuscular(double masa) { _masaMuscular = masa; }
void Nadador::setPeso(double peso) { _peso = peso; }
void Nadador::setIMC(double IMC) { _IMC = IMC; }
double Nadador::getMasaMuscular() { return _masaMuscular; }
double Nadador::getPeso() { return _peso; }
double Nadador::getIMC() { return _IMC; }
string Nadador::toString() {
	stringstream s;
	s << "\t\t" << this->_IMC << endl;
	s << "\t\t" << this->_masaMuscular << endl;
	s << "\t\t" << this->_peso << endl;
	return s.str();

}
