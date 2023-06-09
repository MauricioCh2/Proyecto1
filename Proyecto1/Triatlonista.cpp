#include "Triatlonista.h"
Triatlonista::Triatlonista(int ced, string nombre, string tel, Fecha* fech, int horasEntre, double temProm, char sexo, double est, double masaMuscu, double peso, double IMC, int triaGan, int partIronMan) :
	Corredor(sexo, est)  {
	//Deportista 
	_cedula = ced;
	_nombre = nombre;
	_telefono = tel;
	_ptrFecha = fech,
	//Ciclista
	_ptrCiclista = new Ciclista(horasEntre, temProm);
	//Nadador
	_ptrNad = new Nadador(masaMuscu, peso, IMC);
	this->_cantPartIronMan = partIronMan;
	this->_cantTriatGanador = triaGan;
	this->_ptrFecha = fech;
	this->ListaDpagos = new ListaT<Fecha>;
	iter1 = NULL;
	iter2 = NULL;
}
Triatlonista:: ~Triatlonista() {
	delete _ptrNad;
	delete _ptrCiclista;

}
string Triatlonista::Listar()
{
	stringstream s;
	s << _cedula << "\t" << _nombre << "\t" << _telefono << "\t" << "canGrupos" << endl;
	return s.str();
}
string Triatlonista::toString() {
	stringstream s;
	s << "------------------------------CLIENTE---------------------------" << endl;
	s << "\t" << "Cedula:" << ".........................." << _cedula << endl;
	s << "\t" << "Nombre:" << ".........................." << _nombre << endl;
	s << "\t" << "Telefono:" << "........................" << _telefono << endl;
	s << "\t" << "Fecha Nacimiento:" << "................" << _ptrFecha->toString()<<endl;
	s << _ptrCiclista->toString();
	s << "\t" << "Sexo:" << "............................" << _sexo << endl;
	s << "\t" << "Estatura:" << "........................" << _estatura << endl;
	s << _ptrNad->toString();
	s << "\t" << "Cantidad de participaciones\n\t en el iron man:" << "................." << _cantPartIronMan << endl;
	s << "\t" << "Cantidad de Triatones ganadas:........." << _cantTriatGanador << endl;
	s << "----------------------------------------------------------------" << endl;
	if (ListaDpagos->listaVacia() != true) {
		s << "La ultima fecha de un pago registardo es:\n " << ListaDpagos->toString() << endl;
	}
	return s.str();
}

//Deportista--------------------------------------
string Triatlonista::getNombre() { return _nombre; }
int Triatlonista::getCedula() { return _cedula; }
string Triatlonista::getTelefono() { return _telefono; }
//Ciclista----------------------------------------
int Triatlonista::getHorasDeEntrenamiento() { return _ptrCiclista->getHorasEntrenamiento(); }
int Triatlonista::getTempPromedio() { return _ptrCiclista->getTempProm(); }
void Triatlonista::setHorasDeEntrenamiento(int i)
{
	_ptrCiclista->setHorasEntre(i);
}
void Triatlonista::setTempPromedio(int t)
{
	_ptrCiclista->setTempPro(t);
}
//Corredor----------------------------------------
char Triatlonista::getSexo() { return _sexo; }
double Triatlonista::getEstatura() { return _estatura; }
void Triatlonista::setSexo(char c)
{
	Corredor::setSexo(c);
}
void Triatlonista::setEstatura(double d)
{
	Corredor::setEstatura(d);
}
//Nadado------------------------------------------
double Triatlonista::getMasaMuscular() { return _ptrNad->getMasaMuscular(); }
double Triatlonista::getPeso() { return _ptrNad->getPeso(); }
double Triatlonista::getPorcGrasaCorporal() {return _ptrNad->getIMC();}
void Triatlonista::setMasaMuscular(double d)
{
	_ptrNad->setMasaMuscular(d);
}
void Triatlonista::setPeso(double d)
{
	_ptrNad->setPeso(d);
}
void Triatlonista::setPorcGrasaCorporal(double d)
{
	_ptrNad->setIMC(d);
}
//Triatlonista------------------------------------
int Triatlonista::getCanPartIronMan() { return _cantPartIronMan; }
int Triatlonista::getCanTriatGanador() { return _cantTriatGanador; }
void Triatlonista::setCanPartIronMan(int canIron) { _cantPartIronMan = canIron; }
void Triatlonista::setCanTriatGanador(int canGanadas) { _cantTriatGanador = canGanadas; }

Fecha* Triatlonista::getFechaDeultimoPago()
{
	Nodo<Fecha>* aux = ListaDpagos->getPriemero();
	if (ListaDpagos->listaVacia() == true) {
		return NULL;
	}

	while(aux->getSig() != NULL) {
		aux = aux->getSig();
	}
	return aux->getInfo();
}
void Triatlonista::setFechaDeultimoPago(Fecha* f)
{
	this->ListaDpagos->insertarElem(f);
}
string Triatlonista::imprimirPAGOS(int k)///Pratica con itre
{
	this->iter1 = this->ListaDpagos->begin();
	this->iter2 = this->ListaDpagos->end();

	if (this->ListaDpagos->listaVacia() == false) {
		stringstream s;
		s << "-------(Fechas de Pagos)----------" << endl;
		for (; this->iter1->getPNodo() != this->iter2->getPNodo(); this->iter1->operator++()) {
			s << iter1->operator*()->toString()<< endl;
		}
		s << "----------------------------------" << endl;
		s << "-------(Montos Canscelados)-------" << endl;
		for (int i = 0; i < this->ListaDpagos->contador(); i++) {
			s << "$Cancelado: " << k << endl;
		}
		s << "----------------------------------" << endl;
		return s.str();
	}
	return "Lista de Pagos inexsistente {Cliente Iactivo}";
	delete iter1;
	delete iter2;
}




