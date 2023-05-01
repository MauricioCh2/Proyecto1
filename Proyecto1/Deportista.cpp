#include "Deportista.h"
Deportista::Deportista() {}
Deportista::Deportista(int ced, string nom, string tel, Fecha* f) {
	_cedula = ced;
	_nombre = nom;
	_telefono = tel;
	this->_ptrFecha = f;

}
Deportista::~Deportista() {

}
void Deportista::setCedula(int ced) { _cedula = ced; }
void Deportista::setNombre(string nom) { _nombre = nom; }
void Deportista::setTelefono(string tel) { _telefono = tel; }
void Deportista::setFechaNacimiento(Fecha* fecha) { _ptrFecha = fecha; }
string Deportista::getNombre() { return _nombre; }
int Deportista::getCedula() { return _cedula; }
string Deportista::getIdent() { 
	string ident = to_string(_cedula);
	return ident;
}

string Deportista::getTelefono() { return _telefono; }
Fecha* Deportista::getFechaNacimiento() { return _ptrFecha; }