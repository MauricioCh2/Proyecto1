#include "Ciclista.h"
Ciclista::Ciclista(int horasEntr, double tePromedio) {
	this->_horasEntrenam = horasEntr;
	this->_temPromedio = tePromedio;
}
Ciclista:: ~Ciclista() {

}
void Ciclista::setHorasEntre(int horas) { _horasEntrenam = horas; }
void Ciclista::setTempPro(double temp) { _temPromedio = temp; }
int Ciclista::getHorasEntrenamiento() { return _horasEntrenam; }
double Ciclista::getTempProm() { return _temPromedio; }

string Ciclista::toString() {
	stringstream s;
	s << "\t" << "Horas entrnadas" << "................." << this->_horasEntrenam << endl;
	s << "\t" << "Temperatura promedio" << "............" << this->_temPromedio << endl;
	return s.str();
}
