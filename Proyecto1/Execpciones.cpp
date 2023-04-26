#include "Execpciones.h"

ErrorV::ErrorV(int m)
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
		case 'f': return "ERROR DE Fecha";
		case 'C': return "ERROR DE char";
		case 'I': return "ERROR DE int";
		case 'D': return "ERROR DE double";
		case 'S': return "ERROR DE string";
		case 'F': return "ERROR DE Fecha";
		default: return "ERROR DESCONOSIDO";
	}
}
