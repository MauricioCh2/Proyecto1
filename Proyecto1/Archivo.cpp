#include "Archivos.h"

Archivos::Archivos(Gym* g)
{
	this->_gym = g;
}

Archivos::~Archivos()
{
	delete _gym;
}
//Guardar datos------------------------------------------------------
bool Archivos::guardarDatos()
{
	bool ver = true;
	guardarDeportistas();
	return ver;
}

bool Archivos::guardarDeportistas()
{
	bool ver = true;
	ofstream dep;
	dep.open("../ListaDeportista.txt", ios::out | ios::trunc);
	if (dep.fail()) {
		imprimirString("Error al guardar :(");
	}
	if (dep.good()) {
		//_gym->getListaDepor()->guardarDeportistas(dep);
	}
	dep.close();
	return ver;
}
bool Archivos::guardarCursos()
{
	return false;
}
//Cargar datos------------------------------------------------------
bool Archivos::cargarDatos()
{
	bool ver = true;
	if (not cargarDeportistas()) { ver = false; }

	return ver;
}

bool Archivos::cargarDeportistas()
{
	ifstream f_Deportistas("../ListaDeportista.txt");
	string  nombre, telefono;
	string Scedula,Ssex, ShorasEn, ScanPartIron, ScanTriGana, StemP, Sestatura, SmasaMuscu, Speso, SporGrasaC;
	Fecha* fechN = NULL;
	const char* sex;
	int cedula, horasEn, canPartIron, canTriGana;
	double temP, estatura, masaMuscu, peso, porGrasaC;
	Deportista* Deportista = NULL;

	while (f_Deportistas.good()) {
		getline(f_Deportistas, Scedula, '\t');
		getline(f_Deportistas, nombre, '\t');
		//getline(f_Deportistas, fechaN, '\t');
		getline(f_Deportistas, ShorasEn, '\t');
		getline(f_Deportistas, StemP, '\t');
		getline(f_Deportistas, Ssex, '\t');
		getline(f_Deportistas, Sestatura, '\t');
		getline(f_Deportistas, SmasaMuscu, '\t');
		getline(f_Deportistas, Speso, '\t');
		getline(f_Deportistas, SporGrasaC, '\t');
		getline(f_Deportistas, ScanTriGana, '\t');
		getline(f_Deportistas, ScanPartIron, '\t');
		cedula = stoi(Scedula);
		horasEn = stoi(ShorasEn);
		temP = stod(StemP);
		estatura = stod(Sestatura);
		masaMuscu = stod(SmasaMuscu);
		peso = stod(Speso);
		porGrasaC = stod(SporGrasaC);
		canTriGana = stoi(ScanTriGana);
		canPartIron = stoi(ScanPartIron);
		sex = Ssex.c_str();



		if (!Scedula.empty() && !nombre.empty())
		{
			Deportista = new Triatlonista(cedula, nombre, telefono, NULL, horasEn, temP, *sex, estatura, masaMuscu, peso, porGrasaC, canTriGana, canPartIron);

		}
		else { return false; }
		//no se si aqui hace falta un throw

	}
	f_Deportistas.close();
	return true;
}

bool Archivos::cargarCursos()
{
	return false;
}
