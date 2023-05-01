#include "Gym.h"
Gym::Gym() {
	_nombre = " ";
	_lisCliente = new ListaT<Deportista>;
	_lisCurso = new ListaT<Curso>;
}
//Administracion---------------------------------------------------------
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
//Cursos------------------------------------------------------------------
void Gym::ingresarCursos(Curso* c) {
	_lisCurso->insertarElem(c);
}
string Gym::imprimirListaCursos() {
	return _lisCurso->toString();
}

string Gym::imprimirListaEspe(string s)
{
	return _lisCurso->encontrarEsp(s)->toString();
}

string Gym::imprimirListadoCursos()
{
	return _lisCurso->Listar();

}

ListaT<Curso>* Gym::getListaCurso() {
	return _lisCurso;
}
//Grupos--------------------------------------------------------

void Gym::ingresarGrupo(Grupo*)
{
}
//Clientes----------------------------------------------------------------
void Gym::ingresarListaClientes(Deportista* d) {
	_lisCliente->insertarElem(d);
}

string Gym::imprimirListaClientes()
{
	return _lisCliente->toString();
}

ListaT<Deportista>* Gym::getListaDepor()
{
	return _lisCliente;
}

