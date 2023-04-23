#include "Gym.h"
Gym:: Gym() {
	_lisCliente = new ListaT<Deportista>;
}
void Gym::ingresarListaClientes(Deportista* d) {
	_lisCliente->insertarElem(*d);
}
