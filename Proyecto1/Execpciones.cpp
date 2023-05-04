#include "Execpciones.h"

ErrorV::ErrorV(char m)
{
	motivo = m;
}

const char* ErrorV::what() const throw()
{
	switch (motivo) {
		case 'c': return "ERROR DE char";
		case 'i': return "ERROR DE int";
		case 'd': return "ERROR DE double";
		case 's': return "ERROR DE string";
		case 'z': return "ERROR digite unicamente valores numericos";
		case 'f': return "ERROR DE Fecha";
		case 'G': return "ERROR DE CUPO";
		case 'I': return "ERROR DE int";
		case 'D': return "ERROR DE double";
		case 'S': return "ERROR DE string";
		case 'F': return "ERROR DE Fecha";
		case 'h': return "ERROR DE hora";
		case 'm': return "ERROR DE minuto";
		case 'y': return "ERROR DE Dia";
		default: return "ERROR DESCONOSIDO";
	}
}
