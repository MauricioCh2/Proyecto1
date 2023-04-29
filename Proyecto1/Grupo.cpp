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

	//Vector triatlonistas
	_can = 0;
	_VClientes = new Deportista * [cupM];
	for (int i = 0; i < _cupMax; i++) {
		_VClientes[i] = NULL;
	}

}
Grupo:: ~Grupo() {
	for (int i = 0; i < _can; i++) {
		if (_VClientes[i] != NULL)
			delete _VClientes[i];
	}
	delete[] _VClientes;
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
//Vector------------------------------------------
void Grupo::ingresarElemento(Deportista& grupo) {
	if (_can < _cupMax) {
		_VClientes[_can++] = &grupo;
		_can++;
	}
}
Deportista* Grupo::operator[](int k) {
	return _VClientes[k];
}
//Gets------------------------------------------
string Grupo::getCedInstructor()
{
	return string();
}

string Grupo::getNomInstructor()
{
	return string();
}

int Grupo::getCupMax()
{
	return 0;
}

Fecha* Grupo::getFechaInicio()
{
	return nullptr;
}

int Grupo::getSemDuracion()
{
	return 0;
}

char Grupo::getDiaSemana()
{
	return 0;
}

int Grupo::getHoraInicio()
{
	return 0;
}

int Grupo::getMinInicio()
{
	return 0;
}

int Grupo::getHoraFinaliza()
{
	return 0;
}

int Grupo::getMinFinaliza()
{
	return 0;
}

string Grupo::getNombreCurso()
{
	return string();
}

int Grupo::getConnumGrupo()
{
	return 0;
}

Deportista* Grupo::getVectorClientes()
{
	return nullptr;
}

void Grupo::setCedInstructor(string)
{
}

void Grupo::setNomInstructo(string)
{
}

void Grupo::setcupMax(int)
{
}

void Grupo::setFechaInicio(Fecha*)
{
}

void Grupo::setSemDuracion(int)
{
}

void Grupo::setDiaSem(char)
{
}

void Grupo::setHoraInicio(int)
{
}

void Grupo::setMinutoInicio(int)
{
}

void Grupo::setHoraFinal(int)
{
}

void Grupo::setMinutoFinal(int)
{
}

void Grupo::setNombreCurso()
{
}
