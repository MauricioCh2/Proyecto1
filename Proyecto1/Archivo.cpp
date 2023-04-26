#include "Archivos.h"

Archivos::Archivos(Gym* g)
{
	this->_gym = g;
}

Archivos::~Archivos()
{
	delete _gym;
}
//Guardar datos------------------------------------------------------
bool Archivos::guardarDatos()
{
	bool ver = true;
	guardarDeportistas();
	return ver;
}

bool Archivos::guardarDeportistas()
{
	bool ver = true;
	ofstream dep;
	dep.open("../Deportista.txt",ios::out | ios:: trunc);
	if (dep.fail()) {
		imprimirString("Error al guardar :(");
	}
	// podria ser
	
	return ver;
}
//Cargar datos------------------------------------------------------
bool Archivos::cargarDatos()
{
	return false;
}

bool Archivos::cargarDeportistas()
{
	return false;
}
