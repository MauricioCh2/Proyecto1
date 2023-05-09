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
void Gym::ingresarClienteAGrupos(string n, string cod, Deportista* dep ) // n = numGrup, cod =codigo 
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

void Gym::guardarCursos(ofstream& c)
{
	Curso* curso = NULL;
	Iterador<Curso>* iter;
	Iterador<Curso>* iter2;

	iter = _lisCurso->begin();
	iter2 = _lisCurso->end();

	for (; iter->getPNodo() != iter2->getPNodo(); iter->operator++()) {
		if (iter != NULL) {
			curso = iter-> operator*();
			c << curso->getIdent() << "\t"
				<< curso->getNombreDcurso() << "\t"
				<< curso->getNivel() << "\t"
				<< to_string(curso->getCanGrup()) << "\t"
				<< curso->getDescripcion() << endl;
		}
	}
	
}

void Gym::guardarGrupos(ofstream& g)
{
	Grupo* grup;
	Iterador<Grupo>* it;
	Iterador<Grupo>* it2;

	ListaT<Grupo>* lisG = new ListaT<Grupo>;
	int canC = 0;
	int canG = 0;
	int canD = 0;
	int con = 0;
	if (_lisCurso!= NULL) {
		canC = _lisCurso->contador();
		while (canC != 0) {

			canG = _lisCurso->contadorEspecifico(canC)->getListaGrupos()->contador();
			while (canG != 0) {
				lisG->insertarElem(_lisCurso->contadorEspecifico(canC)->getListaGrupos()->contadorEspecifico(canG));
				canG--;
			}

			canC--;
		}
	}
	it = lisG->begin();
	it2 = lisG->end();
	
	for (; it->getPNodo() != it2->getPNodo(); it->operator++()) {

	//for (it = lisG->begin(); it != lisG->end(); it->operator++()) {
		grup = it-> operator*();
		g << grup->getCedInstructor() << "\t"
			<< grup->getNomInstructor() << "\t"
			<< to_string(grup->getCupMax()) << "\t"
			<< grup->getFechaInicio()->toString() << "\t"
			<< grup->getSemDuracion() << "\t"
			<< string(1,grup->getDiaSemana()) << "\t" // convierte char a strings

			<< to_string(grup->getHoraInicio()) << "\t"
			<< to_string(grup->getMinInicio()) << "\t"
			<< to_string(grup->getHoraFinaliza()) << "\t"
			<< to_string(grup->getMinFinaliza()) << "\t"
			<< grup->getCodCursoPertenece() << "/";
		if (grup->getListaDepor()==NULL) {
			g << endl;
		}
		else {
			 canC = 0;
			 canG = 0;
			 canD = 0;
			 con = 1;
			canD = grup->getListaDepor()->contador();
			while (con <= canD) {
				g << grup->getListaDepor()->contadorEspecifico(con)->getIdent() << "\t";
				con++;
			}
			g << endl;
		}
		
	}
}

void Gym::guardarExpedientes(ofstream& e )
{
	
	
	Expediente* exp;
	Iterador<Expediente>* it;
	Iterador<Expediente>* it2;
	string id = "";
	it = _lisExpediente->begin();
	it2 = _lisExpediente->end();
	int conF = 0;
	for (; it->getPNodo() != it2->getPNodo(); it->operator++()) {
		exp = it->operator*();
		//Deportista//Cliente
		e << exp->getIdent() << "\t"
			<< exp->getNombre() << "\t"
			<< exp->getTelefono() << "\t"
			<< exp->getFechaNacimiento()->toString() << "\t"
			<< exp->getHorasDeEntrenamiento() << "\t"
			<< to_string(exp->getTempPromedio()) << "\t"
			<< string(1, exp->getSexo()) << "\t"
			<< to_string(exp->getEstatura()) << "\t"
			<< to_string(exp->getMasaMuscular()) << "\t"
			<< to_string(exp->getPeso()) << "\t"
			<< to_string(exp->getPorcGrasaCorporal()) << "\t"
			<< to_string(exp->getCanTriatGanador()) << "\t"
			<< to_string(exp->getCanPartIronMan()) << "-";
		//falta fechas
		//Expediente
		conF = exp->getlisFecha()->contador();
		while (conF>0) {
			e << exp->getlisFecha()->contadorEspecifico(conF)->toString()<<"\t";
			conF--;
		}
		e << endl;
		/*contC = exp->getlisCursosIdent()->contador();
		while (contC!=0) {
			e<<exp->getlisCursosIdent()->contadorEspecifico(contC)->getIdent()<< "\t";
			contC--;
		}
		e << "/";
		contG = exp->getlisGruposIdent()->contador();
		while (contG!=0) {
			e << exp->getlisGruposIdent()->contadorEspecifico(contG)->getIdent() << "\t";
			contG--;
		}
		e << endl; */
		//es probable que falten mas cosas como una posible lista de fechas
	}
}

