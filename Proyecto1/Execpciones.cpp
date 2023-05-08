#include "Execpciones.h"

ErrorV::ErrorV(char m)
{
	motivo = m;
}

const char* ErrorV::what() const throw()
{
	switch (motivo) {
		case 'c': return "\x1B[31m ERROR DE char \x1B[37m";
		case 'i': return "\x1B[31m ERROR DE int \x1B[37m";
		case 'd': return "\x1B[31m ERROR DE double \x1B[37m";
		case 's': return "\x1B[31m ERROR DE string \x1B[37m";
		case 'z': return "\x1B[31m ERROR digite unicamente valores numericos \x1B[37m";
		case 'f': return "\x1B[31m ERROR DE Fecha \x1B[37m";
		case 'G': return "\x1B[31m ERROR DE CUPO \x1B[37m";
		case 'I': return "\x1B[31m ERROR DE int \x1B[37m";
		case 'D': return "\x1B[31m ERROR DE double \x1B[37m";
		case 'S': return "\x1B[31m ERROR DE string \x1B[37m";
		case 'F': return "\x1B[31m ERROR DE Fecha \x1B[37m";
		case 'h': return "\x1B[31m ERROR DE hora \x1B[37m";
		case 'm': return "\x1B[31m ERROR DE minuto \x1B[37m";
		case 'y': return "\x1B[31m ERROR DE Dia \x1B[37m";
		default: return "\x1B[31m ERROR DESCONOSIDO \x1B[37m";
	}
}
