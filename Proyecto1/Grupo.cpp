#include "Grupo.h"
Grupo::Grupo(string ced, string nom, int cupM, Fecha* fech, int dur, char diaSem, int horaIn, int minIn, int horFin, int minFin) {
	_cedInstructor = ced;
	_nomInstructor;
	_cupMax = cupM;
	_fechaInicio = fech;
	_semDuracion = dur;
	//Horarios
	_diaSemana = diaSem;
	_horaInicio = horaIn;
	_minInicio = minIn;

	_horaFinaliza = horFin;
	_minFinaliza = minFin;

	_nombreCurso = "Sin Definir";
	_connumGrupo++;

	//Lista triatlonistas
	_lisDepor = new ListaT<Deportista>;

}
Grupo:: ~Grupo() {
	
	/*for (int i = 0; i < _can; i++) {
		if (_VClientes[i] != NULL)
			delete _VClientes[i];
	}
	delete[] _VClientes;*/
}
string Grupo::toString() {
	stringstream s;
	s << "----------------------------------------" << endl;
	s << "Nombre del curso:......." << _nombreCurso << endl;
	s << "Numero del grupo:......." << _connumGrupo << endl;
	s << "Cedula del instructor:.." << _cedInstructor << endl;
	s << "Instructor asignado:...." << _nomInstructor << endl;
	s << "Cupo maximo:............" << _cupMax << endl;
	//s << ": " << _fechaInicio << endl; cantidad de matriculados 
	s << "Semanas de duracion...: " << _semDuracion << endl;
	s << "Dia:................... ";
	switch (_diaSemana) {
	case 'l':
		s << "Lunes" << endl;
		break;
	case 'm':
		s << "Martes" << endl;
		break;
	case 'k':
		s << "Miercoles" << endl;
		break;
	case 'j':
		s << "Jueves" << endl;
		break;
	case 'v':
		s << "Viernes" << endl;
		break;
	case 's':
		s << "Sabado" << endl;
		break;
	case 'd':
		s << "Domingo" << endl;
		break;
	}
	s << "Horario: " << _horaInicio << ":" << _minInicio << "-" << _horaFinaliza << ":" << _minFinaliza << endl;

	return s.str();
}
string Grupo::Listar()
{
	stringstream s;
	s << _connumGrupo<< "\t" << _diaSemana << "\t" << _horaInicio << ":" << _minInicio << "-" << _horaFinaliza <<":" << _minFinaliza << "\t" << _cupMax << endl;
	return s.str();
}

//Gets------------------------------------------
string Grupo::getCedInstructor()
{

	return _cedInstructor;
}

string Grupo::getNomInstructor()
{
	return _nomInstructor;
}

int Grupo::getCupMax()
{
	return _cupMax;
}

Fecha* Grupo::getFechaInicio()
{
	return _fechaInicio;
}

int Grupo::getSemDuracion()
{
	return _semDuracion;
}

char Grupo::getDiaSemana()
{
	return _diaSemana;
}

int Grupo::getHoraInicio()
{
	return _horaInicio;
}

int Grupo::getMinInicio()
{
	return _minInicio;
}

int Grupo::getHoraFinaliza()
{
	return _horaFinaliza;
}

int Grupo::getMinFinaliza()
{
	return _minFinaliza;
}

string Grupo::getNombreCurso()
{
	return _nombreCurso;
}

int Grupo::getConnumGrupo()
{
	return _connumGrupo;
}

ListaT<Deportista>* Grupo::getListaDepor()
{
	return _lisDepor;
}

void Grupo::setCedInstructor(string a)
{
	_cedInstructor = a;
}

void Grupo::setNomInstructo(string a)
{
	 _nomInstructor = a;
}

void Grupo::setcupMax(int a)
{
	_cupMax = a;
}

void Grupo::setFechaInicio(Fecha* a)
{
	_fechaInicio = a;
}

void Grupo::setSemDuracion(int a)
{
	_semDuracion = a;
}
void Grupo::setDiaSem(char a)
{
	_diaSemana = a;
}

void Grupo::setHoraInicio(int a)
{
	_horaInicio = a;
}

void Grupo::setMinutoInicio(int a)
{
	_minInicio = a;
}

void Grupo::setHoraFinal(int a)
{
	_minFinaliza = a;
}

void Grupo::setMinutoFinal(int a)
{
	_minFinaliza = a;
}

void Grupo::setNombreCurso()
{
	//_nombreCurso 
}
//Lista------------------------------------------
void Grupo::ingresarDeportista(Deportista* de) {
	_lisDepor->insertarElem(de);
}
Deportista* Grupo::operator[](int k) {
	return _lisDepor->contadorEspecifico(k);
}
string Grupo::getIdent()
{
	string numGrup = to_string(_connumGrupo);

	return numGrup;
}