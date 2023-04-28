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

}
Grupo:: ~Grupo() {

}
string Grupo::toString() {
	stringstream s;
	s << "----------------------------------------" << endl;
	s << "Nombre del curso:......." << _nombreCurso << endl;
	s << "Numero del grupo:......." << _connumGrupo << endl;
	s << "Cedula del instructor:.." << _cedInstructor << endl;
	s << "Instructor asignado:...." << _nomInstructor << endl;
	s << "Cupo maximo: " << _cupMax << endl;
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
