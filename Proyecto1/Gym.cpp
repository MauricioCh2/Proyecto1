#include "Gym.h"
Gym::Gym() {
	_nombre = " ";
	_fechaHoy = new Fecha(0,0,0);
	_lisCliente = new ListaT<Deportista>;
	_lisCurso = new ListaT<Curso>;
	_lisExpediente = new ListaT<Expediente>;
	
}
Gym::Gym(Fecha* f) {
	_nombre = " ";
	_fechaHoy = f;
	_lisCliente = new ListaT<Deportista>;
	_lisCurso = new ListaT<Curso>;
	_lisExpediente = new ListaT<Expediente>;


}
Fecha* Gym::getFecha()
{
	return _fechaHoy;
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
bool Gym::verDisponivilidadCursos(string c) {
	return _lisCurso->encontrarEsp(c)->verficarEspacio();
}

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
bool Gym::verDisponivilidadGrupos(string c, string g) {
	return _lisCurso->encontrarEsp(c)->getListaGrupos()->encontrarEsp(g)->verficarEspacio();
}
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
void Gym::ingresarClienteAGrupos(string n, string cod, Deportista* dep )
{
	
	Curso* cur = _lisCurso->encontrarEsp(cod);
	cur->getListaGrupos()->encontrarEsp(n)->ingresarDeportista(dep);
	
}
string Gym::imprimirClientesDeUnGrupo(string cod, string n)
{
	return _lisCurso->encontrarEsp(cod)->getListaGrupos()->encontrarEsp(n)->imprimirDeportistas();
}
//Clientes----------------------------------------------------------------
string Gym::imprimirListadoDeClientesDUnGrupo(string cur, string grup)
{
	ListaT<Grupo>* lisG = new ListaT<Grupo>;
	//podria terminar el metodo de verifiar espacio
	lisG = _lisCurso->encontrarEsp(cur)->getListaGrupos();

	return lisG->encontrarEsp(grup)->getListaDepor()->Listar();
}

string Gym::imprimirListaClientes()
{
	return getListaDepor()->toString();
}

//string Gym::imprimirListadoDeportistas()
//{
//	return _lisCliente->Listar();
//}

ListaT<Grupo>* Gym::getListaDgruposDcurso(string c)
{
	return _lisCurso->encontrarEsp(c)->getListaGrupos();
}
void Gym::cancelarMatricula(string cur, string grup, string ced) {
	_lisCurso->encontrarEsp(cur)->getListaGrupos()->encontrarEsp(grup)->getListaDepor()->eliminarEspe(ced);
}
ListaT<Deportista>* Gym::getListaDepor()
{
	int canC = 0;
	int canG = 0;
	int canD = 0;
	ListaT<Grupo>* AuxGrup = new ListaT<Grupo>;
	ListaT<Deportista>* AuxDep = new ListaT <Deportista>;
	canC = _lisCurso->contador();
	while (canC != 0) {

		canG = _lisCurso->contadorEspecifico(canC)->getListaGrupos()->contador();
		while (canG!=0) {
			canD = _lisCurso->contadorEspecifico(canC)->getListaGrupos()->contadorEspecifico(canG)->getListaDepor()->contador();
			while (canD != 0) {
				AuxDep->insertarElem(_lisCurso->contadorEspecifico(canC)->getListaGrupos()->contadorEspecifico(canG)->getListaDepor()->contadorEspecifico(canD));
				canD--;
			}
			canG--;
		}
		
		canC--;
	}
	_lisCliente = AuxDep;
	return _lisCliente;
}
ListaT<Expediente>* Gym::getListaExpediente()
{
	return _lisExpediente;
}

