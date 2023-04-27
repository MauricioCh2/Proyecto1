#include "Gym.h"
Gym::Gym() {
	_nombre = " ";
	_lisCliente = new ListaT<Deportista>;
	_lisCurso = new ListaT <Curso>;
}

ListaT<Deportista>* Gym::getListaDep()
{
	return _lisCliente;
}

string Gym::getNombreDgym()
{
	return _nombre;
}

int Gym::getMensualidadDgym()
{
	return _mensualidad;
}
void Gym::setNombreDgym(string g)
{
	_nombre = g;
}
void Gym::setMensualidadDgym(int m)
{
	_mensualidad = m;
}
void Gym::ingresarListaClientes(Deportista* d) {
	_lisCliente->insertarElem(*d);
}

string Gym::imprimirListaClientes()
{
	return _lisCliente->toString();
}