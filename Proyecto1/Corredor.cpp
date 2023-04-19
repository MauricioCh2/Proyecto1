#include "Corredor.h"
Corredor::Corredor(string ced, string nombre, string tel, Fecha* fech, char sex, double estatura) :Deportista(ced, nombre, tel, fech) {
	this->_sexo = sex;
	this->_estatura = estatura;
}
Corredor:: ~Corredor() {

}
void Corredor::setSexo(char sex) { _sexo = sex; }
void Corredor::setEstatura(double est) { _estatura = est; }
char Corredor::getSexo() { return _sexo; }
double Corredor::getEstatura() { return _estatura; }
string Corredor::toString() {
	stringstream s;
	s << "\t\t" << this->_sexo << endl;
	s << "\t\t" << this->_estatura << endl;
	return s.str();

}
