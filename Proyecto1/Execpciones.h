#pragma once
#include <iostream>
#include <string>

using namespace std;

class ErrorV  {
private:
	char motivo;
public:
	ErrorV(char m);
	const char* what()const throw();

};

