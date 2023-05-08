#include "Expediente.h"

Expediente::Expediente(int ced, string nombre, string tel, Fecha* fech, int horasEntre, double temProm, char sexo, double est, double masaMuscu, double peso, double IMC, int triaGan, int partIronMan)
{
	_cedula = ced;
	_nombre = nombre;
	_telefono = tel;
	_ptrFechadeNaci = fech;
	_sexo = sexo;
	_estatura = est;
	_masaMuscular = masaMuscu;
	_peso = peso;
	_IMC = IMC;
	_horasEntrenam = horasEntre;
	_temPromedio = temProm;
	_cantPartIronMan = partIronMan;
	_cantTriatGanador = triaGan;
	_lisCursosIdent = new ListaT<stringMOD>;
	_lisGruposIdent = new ListaT<stringMOD>;

	ListaDpagos = new ListaT<Fecha>;
}
Expediente:: ~Expediente() {


}
void Expediente::setCedula(int ced) { _cedula = ced; }
void Expediente::setNombre(string nom) { _nombre = nom; }
void Expediente::setTelefono(string tel) { _telefono = tel; }
void Expediente::setFechaNacimiento(Fecha* fecha) { _ptrFechadeNaci = fecha; }
string Expediente::getIdent() {
	string ident = to_string(_cedula);
	return ident;
}
string Expediente::getNombre() { return _nombre; }
int Expediente::getCedula() { return _cedula; }
string Expediente::getTelefono() { return _telefono; }

Fecha* Expediente::getFechaNacimiento()
{
	return _ptrFechadeNaci;
}
string Expediente::toString() {
	stringstream s;
	s << "------------------------------CLIENTE---------------------------" << endl;
	s << "\t" << "Cedula" << ".........................." << this->_cedula << endl;
	s << "\t" << "Nombre" << ".........................." << this->_nombre << endl;
	s << "\t" << "Telefono" << "........................" << this->_telefono << endl;
	s << "\t" << "Fecha Nacimiento" << "................" << this->_ptrFechadeNaci << endl;;
	s << "\t" << "Horas entrnadas" << "................." << this->_horasEntrenam << endl;
	s << "\t" << "Temperatura promedio" << "............" << this->_temPromedio << endl;
	s << "\t" << "Sexo" << "............................" << this->_sexo << endl;
	s << "\t" << "Estatura" << "........................" << this->_estatura << endl;
	s << "\t" << "Indice masa muscular" << "............" << this->_masaMuscular << endl;
	s << "\t" << "Peso" << "............................" << this->_peso << endl;
	s << "\t" << "Porcentaje grasa corporal" << "......." << this->_IMC << endl;
	s << "\t" << "Cantidad de participaciones\n\t en el iron man" << "................." << this->_cantPartIronMan << endl;
	s << "\t" << "Cantidad de Triatones ganadas" << "..." << this->_cantTriatGanador << endl;
	s << "Cantidad de Triatones ganadas " << this->_cantTriatGanador << endl;
	s << "----------------------------------------------------------------" << endl;
	if (_lisCursosIdent->listaVacia() != true) {
		s << "Los codigos de los cursos que a matriculado:" << _lisCursosIdent->toString() << endl;
	}
	if (_lisGruposIdent->listaVacia() != true) {
		s << "Los codigos de los cursos de los grupos en los que se encuentar: " << _lisGruposIdent->toString() << endl;
	}
	return s.str();
}
//Ciclista----------------------------------------
int Expediente::getHorasDeEntrenamiento() { return _horasEntrenam; }
int Expediente::getTempPromedio() { return _temPromedio; }
void Expediente::setHorasDeEntrenamiento(int i)
{
	_horasEntrenam = i;
}
void Expediente::setTempPromedio(int t)
{
	_temPromedio = t;
}
//Corredor----------------------------------------
char Expediente::getSexo() { return _sexo; }
double Expediente::getEstatura() { return _estatura; }
void Expediente::setSexo(char c)
{
	_sexo = c;
}
void Expediente::setEstatura(double d)
{
	_estatura = d;
}
//Nadado------------------------------------------
double Expediente::getMasaMuscular() { return _masaMuscular; }
double Expediente::getPeso() { return _peso; }
double Expediente::getPorcGrasaCorporal() { return _IMC; }
void Expediente::setMasaMuscular(double d)
{
	_masaMuscular = d;
}
void Expediente::setPeso(double d)
{
	_peso = d;
}
void Expediente::setPorcGrasaCorporal(double d)
{
	_IMC = d;
}
//Triatlonista------------------------------------
int Expediente::getCanPartIronMan() { return _cantPartIronMan; }
int Expediente::getCanTriatGanador() { return _cantTriatGanador; }
void Expediente::setCanPartIronMan(int canIron) { _cantPartIronMan = canIron; }
void Expediente::setCanTriatGanador(int canGanadas) { _cantTriatGanador = canGanadas; }

ListaT<stringMOD>* Expediente::getlisCursosIdent()
{
	return _lisCursosIdent;
}

ListaT<stringMOD>* Expediente::getlisGruposIdent()
{
	return _lisGruposIdent;
}

ListaT<Fecha>* Expediente::getlisFecha()
{
	return ListaDpagos;
}

void Expediente::setLisFecha(ListaT<Fecha>* f)
{
	ListaDpagos = f;
}
