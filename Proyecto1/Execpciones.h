#pragma once
#include <iostream>
#include <string>

using namespace std;

class ErrorV  {
private:
	char motivo;
public:
	ErrorV(int m);
	const char* what()const throw();

};
//const char* ErrorV::what() const throw() {
//	switch (motivo) {
//	case 'c': return "ERROR DE char";
//	case 'i': return "ERROR DE int";
//	case 'd': return "ERROR DE double";
//	case 's': return "ERROR DE string";
//	case 'f': return "ERROR DE Fecha";
//	default: return "ERROR DESCONOSIDO";
//	}
//}
