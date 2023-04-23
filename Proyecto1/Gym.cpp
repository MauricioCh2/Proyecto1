#include "Gym.h"
Gym::Gym() {
	_nombre = " ";
	_lisCliente = new ListaT<Deportista>;
}

string Gym::getNombreDgym()
{
	return _nombre;
}
void Gym::setNombreDgym(string g)
{
	_nombre = g;
}
int Gym::getMensualidadDgym()
{
	return _mensualidad;
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