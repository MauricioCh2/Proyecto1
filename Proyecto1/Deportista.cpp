#include "Deportista.h"
Deportista::Deportista() {}
Deportista::Deportista(string ced, string nom, string tel, Fecha* f) {
	_cedula = ced;
	_nombre = nom;
	_telefono = tel;
	this->_ptrFecha;

}
Deportista::~Deportista() {

}
void Deportista::setCedula(string ced) { _cedula = ced; }
void Deportista::setNombre(string nom) { _nombre = nom; }
void Deportista::setTelefono(string tel) { _telefono = tel; }
void Deportista::setFecha(Fecha* fecha) { _ptrFecha = fecha; }
string Deportista::getNombre() { return _nombre; }
string Deportista::getCedula() { return _cedula; }
string Deportista::getTelefono() { return _telefono; }
Fecha* Deportista::getFecha() { return _ptrFecha; }