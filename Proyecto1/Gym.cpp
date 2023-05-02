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

void Gym::ingresarGrupo(string c,Grupo* g)
{
	_lisCurso->encontrarEsp(c)->ingresarGrupo(g);
}
string Gym::imprimirListadoGrupo(string c)
{
	return _lisCurso->encontrarEsp(c)->getListaGrupos()->Listar();
}
int Gym::PruebaCantGrupos(string c)
{
	return _lisCurso->encontrarEsp(c)->getListaGrupos()->contador();
}
string Gym::reporteGrupoEspe(string cur, string grup)
{
	ListaT<Grupo>* lisG = new ListaT<Grupo>;
	//podria terminar el metodo de verifiar espacio
	lisG=_lisCurso->encontrarEsp(cur)->getListaGrupos();
	
	return lisG->encontrarEsp(grup)->toString();
}
void Gym::ingresarClienteAGrupos(string n, string cod, string ced )
{
	
	Deportista* dep = _lisCliente->encontrarEsp(ced);
	Curso* cur = _lisCurso->encontrarEsp(cod);
	cur->getListaGrupos()->encontrarEsp(n)->ingresarDeportista(dep);
	
}
//Clientes----------------------------------------------------------------
void Gym::ingresarListaClientes(Deportista* d) {
	_lisCliente->insertarElem(d);
}

string Gym::imprimirListaClientes()
{
	return _lisCliente->toString();
}

ListaT<Grupo>* Gym::getListaDgruposDcurso(string c)
{
	return _lisCurso->encontrarEsp(c)->getListaGrupos();
}

ListaT<Deportista>* Gym::getListaDepor()
{
	return _lisCliente;
}

