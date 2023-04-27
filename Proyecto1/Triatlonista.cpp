#include "Triatlonista.h"
Triatlonista::Triatlonista(string ced, string nombre, string tel, Fecha* fech, int horasEntre, double temProm, char sexo, double est, double masaMuscu, double peso, double IMC, int triaGan, int partIronMan) :
	Corredor(ced, nombre, tel, fech, sexo, est) {
	//Ciclista
	_ptrCiclista = new Ciclista(horasEntre, temProm);
	//Nadador
	_ptrNad = new Nadador(masaMuscu, peso, IMC);
	this->_cantPartIronMan = partIronMan;
	this->_cantTriatGanador = triaGan;
}
Triatlonista:: ~Triatlonista() {
	delete _ptrNad;
	delete _ptrCiclista;

}
string Triatlonista::toString() {
	stringstream s;
	s << "------------------------------CLIENTE---------------------------" << endl;
	s << "\t" << "Cedula" << ".........................." << _cedula << endl;
	s << "\t" << "Nombre" << ".........................." << _nombre << endl;
	s << "\t" << "Telefono" << "........................" << _telefono << endl;
	s << "\t" << "Fecha Nacimiento" << "................" << _ptrFecha->toString();
	s << _ptrCiclista->toString();
	s << "\t" << "Sexo" << "............................" << _sexo << endl;
	s << "\t" << "Estatura" << "........................" << _estatura << endl;
	s << _ptrNad->toString();
	s << "\t" << "Cantidad de participaciones\n\t en el iron man" << "................." << _cantPartIronMan << endl;
	s << "\t" << "Cantidad de Triatones ganadas" << "..." << _cantTriatGanador << endl;
	s << "----------------------------------------------------------------" << endl;
	s << "Cantidad de Triatones ganadas" << _cantTriatGanador << endl;
	return s.str();
}
//Deportista--------------------------------------
string Triatlonista::getNombre() { return _nombre; }
string Triatlonista::getCedula() { return _cedula; }
string Triatlonista::getTelefono() { return _telefono; }
Fecha* Triatlonista::fechaNacimiento() { return _ptrFecha; }
//Ciclista----------------------------------------
int Triatlonista::getHorasDeEntrenamiento() { return _ptrCiclista->getHorasEntrenamiento(); }
int Triatlonista::getTempPromedio() { return _ptrCiclista->getTempProm(); }
//Corredor----------------------------------------
char Triatlonista::getSexo() { return _sexo; }
double Triatlonista::getEstatura() { return _estatura; }
//Nadado------------------------------------------
double Triatlonista::getMasaMuscular() { return _ptrNad->getMasaMuscular(); }
double Triatlonista::getPeso() { return _ptrNad->getPeso(); }
double Triatlonista::getPorcGrasaCorporal() { return _ptrNad->getIMC(); }
//Triatlonista------------------------------------
int Triatlonista::getCanPartIronMan() { return _cantPartIronMan; }
int Triatlonista::getCanTriatGanador() { return _cantTriatGanador; }
void Triatlonista::setCanPartIronMan(int canIron) { _cantPartIronMan = canIron; }
void Triatlonista::setCanTriatGanador(int canGanadas) { _cantTriatGanador = canGanadas; }

//Fecha* Triatlonista::getFecha()
//{
//	return fech;
//}
//
//void Triatlonista::setFecha(Fecha* f)
//{
//	fech = f;
//}
