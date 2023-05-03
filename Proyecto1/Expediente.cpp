#include "Expediente.h"

Expediente::Expediente()
{
}
Expediente::Expediente(int ced, string nombre, string tel, Fecha* fech, int horasEntre, double temProm, char sexo, double est, double masaMuscu, double peso, double IMC, int triaGan, int partIronMan,Fecha* ultimoPago)
{
	_cedula=ced;//Cuite los ptr,s porque no son punteros lo que van a almacenar
	_nombre= nombre;
	_telefono= tel;
	_ptrFechadeNaci= fech;
	_sexo= sexo;
	_estatura= est;
	_masaMuscular= masaMuscu;
	_peso= peso;
	_IMC= IMC;
	_horasEntrenam= horasEntre;
	_temPromedio= temProm;

	//_lisCursosIdent = new ListaT<string>;
	//_lisGruposIdent = new ListaT<string>;

	Fecha* _fechaDultimopago;
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
	/*stringstream s;
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
	s << "Cantidad de Triatones ganadas " << _cantTriatGanador << endl;
	s << "----------------------------------------------------------------" << endl;
	if (ListaDpagos->listaVacia() == true) {
		s << "La ultima fecha de un pago registardo es:" << ListaDpagos->toString() << endl;
	}
	return s.str();*/
	return "";
}
//Ciclista----------------------------------------
int Expediente::getHorasDeEntrenamiento() { return _horasEntrenam; }
int Expediente::getTempPromedio() { return _temPromedio; }
void Expediente::setHorasDeEntrenamiento(int i)
{
	_horasEntrenam=i;
}
void Expediente::setTempPromedio(int t)
{
	_temPromedio=t;
}
//Corredor----------------------------------------
char Expediente::getSexo() { return _sexo; }
double Expediente::getEstatura() { return _estatura; }
void Expediente::setSexo(char c)
{
	_sexo=c;
}
void Expediente::setEstatura(double d)
{
	_estatura=d;
}
//Nadado------------------------------------------
double Expediente::getMasaMuscular() { return _masaMuscular; }
double Expediente::getPeso() { return _peso; }
double Expediente::getPorcGrasaCorporal() { return _IMC; }
void Expediente::setMasaMuscular(double d)
{
	_masaMuscular=d;
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
