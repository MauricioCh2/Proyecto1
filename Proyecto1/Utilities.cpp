#include "Utilities.h"
//RECIVIR----------------------
int recivirInt() {
	int i;
	bool fin = false;
	while (fin == false) {

		if (cin >> i){
			fin = true;
			return i;
		}
		else {
			throw (new ErrorV('i'));
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	return 0;

}
string recivirString() {
	string s;
	bool fin = false;
	while (fin == false) {
		if (cin >> s) {
			fin = true;
			return s;
		}
		throw new ErrorV('s');
	}
	return "";
}
char recivirChar() {
	char c;
	bool fin = false;
	while (fin==false) {
		if (cin >> c) {
			fin = true;
			return c;
		}
		throw new ErrorV('c');
	}
	return 'c';
}

//puede que lo cambiemos a char*
double recivirDouble() {
	double d;
	bool fin = false;
	while (fin == false) {

		if (cin >> d) {
			fin = true;
			return d;
		}
		else {
			throw (new ErrorV('d'));
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
	return 0;
}
//IMPRIMIR---------------------
void imprimirString(string s) {
	cout << s << endl;
}
void imprimirInt(int i) {
	cout << i << endl;
}
void imprimirChar(char c) {
	cout << c << endl;
}
void imprimirDouble(double d) {
	cout << d << endl;
}
//VALIDACIONES-----------------
Fecha* validarFecha() {
	string leer = recivirString();//1/11/11
	stringstream input_stringstream(leer);
	string dia = "";
	string mes = "";
	string annio = "";
	int d, m, a;
	getline(input_stringstream, dia, '/');
	getline(input_stringstream, mes, '/');
	getline(input_stringstream, annio, '/');
	d = validarDia(dia);
	m = validarMes(mes);
	a = validarAnnio(annio);
	Fecha* fech = new Fecha(d, m, a);


	return fech;


}

int validarDia(string s) {
	int d;
	bool fin = false;
	while (fin == false) {
		d = stoi(s);
		if (d >= 1 && d <= 31) {
			fin = true;
			return d;
		}
		else {
			throw (new ErrorV('f'));
		}
	}
	return 0;

}
int validarMes(string s) {
	int m;
	bool fin = false;
	while (fin == false) {
		m = stoi(s);
		if (m >= 1 && m <= 12) {
			fin = true;
			return m;
		}
		else {
			throw (new ErrorV('f'));
		}
	}
	return 0;
}
int validarAnnio(string s) {
	int a;
	bool fin = false;
	while (fin == false) {
		a = stoi(s);
		if (a >= 1 && a <= 31) {
			fin = true;
			return a;
		}
		else {
			throw (new ErrorV('f'));
		}
	}
	return 0;
}
char validarDia()
{
	char d;
	cin >> d;
	if (d == 'l' || d == 'm' || d == 'k' || d == 'j' || d == 'v' || d == 's' || d == 'd') {
		return d;
	}
	else {
		//throw (Excepcion 'C');
	}

}

int validarHora(string h) {
	string Shora = "";
	string Smin = "";
	int hora;
	stringstream input_stringstream(h);
	getline(input_stringstream, Shora, ':');
	getline(input_stringstream, Smin, ':');
	hora = stoi("hora");
	if (hora < 24) {
		return hora;
	}
	else {
		throw new string("ERROR: Digite una hora valida\n");
	}
}
int validarMinuto(string m) {
	string Shora = "";
	string Smin = "";
	int min;
	stringstream input_stringstream(m);
	getline(input_stringstream, Shora, ':');
	getline(input_stringstream, Smin, ':');
	min = stoi("hora");
	if (min < 60) {
		return min;
	}
	else {
		throw new string("ERROR: Digite un minuto valido\n");
	}
}
//Otros-------------------------------
void enter() {
	system("pause");
}
void limpiarPantalla() {
	system("cls");
}
void limpiar() {
	cin.clear();
	cin.ignore(1024, '\n');
}