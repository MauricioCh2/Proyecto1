
#include "Archivos.h"

Archivos::Archivos(Gym* g)
{
	this->_gym = g;
	lisAux = new ListaT<Deportista>;
}

Archivos::~Archivos()
{
	delete _gym;
}
//Guardar datos------------------------------------------------------
bool Archivos::guardarDatos()
{
	bool ver = true;
	guardarCursos();
	guardarGrupos();
	guadarExpediente();
	return ver;
}


bool Archivos::guardarCursos()
{
	bool ver = false;
	ofstream cursos;
	cursos.open("../ListaCursos.txt", ios::out | ios::trunc);
	if (cursos.fail()) {
		imprimirString("Error al abrir :("); 
		return ver;
	}
	_gym->guardarCursos(cursos);
	cursos.close();
	return ver;
}
bool Archivos::guardarGrupos()
{
	bool ver = false;
	ofstream grupos;
	grupos.open("../ListaGrupos.txt", ios::out | ios::trunc);
	if (grupos.fail()) {
		imprimirString("Error al abrir :(");

		return ver;
	}
	_gym->guardarGrupos(grupos);
	grupos.close();
	return ver;
}
bool Archivos::guadarExpediente()
{
	bool ver = false; 
	ofstream expediente;
	expediente.open("../ListaExpediente.txt", ios::out | ios::trunc);
	if (expediente.fail()) {
		imprimirString("Error al abrir :(");

		return ver;
	}
	_gym->guardarExpedientes(expediente);
	expediente.close();
	return ver;
}
//Cargar datos------------------------------------------------------
bool Archivos::cargarDatos()
{
	bool ver = true;
	if (not cargarExpediente()) { ver = false; }
	if (not cargarCursos()) { ver = false; }
	if (not cargarGrupos()) { ver = false; }
	

	return ver;
}


bool Archivos::cargarCursos()
{
	ifstream f_Curso("../ListaCursos.txt");
	string codCurso = "", nombreCur = "", nivel = "", ScanGrupos = "", descripcion = "";
	int canGrupos = 0;
	Curso* curAux = NULL;
	while (f_Curso.good()) {
		getline(f_Curso, codCurso, '\t');
		getline(f_Curso, nombreCur, '\t');
		getline(f_Curso, nivel, '\t');
		getline(f_Curso, ScanGrupos, '\t');
		getline(f_Curso, descripcion, '\n');
		if (!codCurso.empty() && !nombreCur.empty() && !nivel.empty() && !ScanGrupos.empty() && !descripcion.empty()) {
			canGrupos = stoi(ScanGrupos);
			curAux = new Curso(codCurso, nombreCur, nivel, canGrupos, descripcion);
			_gym->ingresarCursos(curAux);
		}
		else { return false; }
	}
	f_Curso.close();
	return true;
	
}

bool Archivos::cargarGrupos()
{
	ifstream f_Grupo("../ListaGrupos.txt");
	string cedInstruc = "", nomInstruc = "", ScupMax = "", sFechaIn = "", SsemDur = "", SdiaSem = "", ShoraIn = "", SminIn = "", ShoraFin = "", SminFin = "", codigoCur = "";
	int cupMax = 0, semDur = 0;
	char diaSem;
	int horaIn = 0, minIn = 0, horaFin = 0, minFin = 0;
	Fecha* fecha = NULL;
	Grupo* grupAux = NULL;
	string id;
	
	while (f_Grupo.good()) {
		getline(f_Grupo, cedInstruc, '\t');
		getline(f_Grupo, nomInstruc, '\t');
		getline(f_Grupo, ScupMax, '\t');
		getline(f_Grupo, sFechaIn, '\t');
		getline(f_Grupo, SsemDur, '\t');
		getline(f_Grupo, SdiaSem, '\t');
		getline(f_Grupo, ShoraIn, '\t');
		getline(f_Grupo, SminIn, '\t');
		getline(f_Grupo, ShoraFin, '\t');
		getline(f_Grupo, SminFin, '\t');
		getline(f_Grupo, codigoCur, '/');
		if (!cedInstruc.empty() && !nomInstruc.empty() && !ScupMax.empty() && !sFechaIn.empty() && !SsemDur.empty() && !SdiaSem.empty() && !ShoraIn.empty() && !SminIn.empty() && !ShoraFin.empty() && !SminFin.empty()) {
			cupMax = stoi(ScupMax);
			semDur = stoi(SsemDur);
			horaIn = stoi(ShoraIn);
			minIn = stoi(SminFin);
			horaFin = stoi(ShoraFin);
			minIn = stoi(SminFin);
			diaSem = SdiaSem.at(0);//busca el caracter numero 0 del string el cual es el char que se necesia
			fecha = validarFechaA(sFechaIn);
			grupAux = new Grupo(cedInstruc, nomInstruc, cupMax, fecha, semDur, diaSem, horaIn, minIn, horaFin, minFin);
			_gym->ingresarGrupo(codigoCur, grupAux);

			getline(f_Grupo, id, '\n');
			if(!id.empty()) {
				ListaT<stringMOD>* lisIdCli = new ListaT<stringMOD>;
				stringMOD* IDcurso = NULL;
				
					stringstream cursIDs(id);
					while (getline(cursIDs, id, '\t')) {
						IDcurso = new stringMOD(id);
						lisIdCli->insertarElem(IDcurso);
					}
					int conD = 0;
					int conID = 0;
					
					if (lisAux != NULL) {
						conD = lisAux->contador();
					}
					conID = lisIdCli->contador();
					for (int con = 1; con <= conD; con++) {
						for (int con2 = 1; con2 <= conID; con2++) {
							if (lisAux->contadorEspecifico(con)->getIdent() == lisIdCli->contadorEspecifico(con2)->getIdent()) {
								grupAux->ingresarDeportista(lisAux->contadorEspecifico(con));
							}
							
						}
					}
			}

		}
			

	}
	f_Grupo.close();
	return false;
}

bool Archivos::cargarExpediente()// deportistas
{
	ifstream f_Expediente("../ListaExpediente.txt");

	string  nombre, telefono;
	string Scedula, Ssex, ShorasEn, ScanPartIron, ScanTriGana, StemP, Sestatura, SmasaMuscu, Speso, SporGrasaC, SfechaN;
	Fecha* fechN = NULL;
	const char* sex;
	int cedula, horasEn, canPartIron, canTriGana;
	double temP, estatura, masaMuscu, peso, porGrasaC;
	string cursos;
	string IdeCursos;
	string grupos;
	string IdeGrupos;
	Deportista* deportista = NULL;
	Expediente* expe = NULL;
	stringMOD* IDcurso = NULL;
	stringMOD* IDgrupo = NULL;
	int canC = 0;
	int canG = 0;
	int dia = 0;
	int mes = 0;
	int annio = 0;
	string Sdia, Smes, Sannio;
	Fecha* fechaR = NULL;
	while (f_Expediente.good()) {
		getline(f_Expediente, Scedula, '\t');
		getline(f_Expediente, nombre, '\t');
		getline(f_Expediente, telefono, '\t');
		getline(f_Expediente, SfechaN, '\t');
		getline(f_Expediente, ShorasEn, '\t');
		getline(f_Expediente, StemP, '\t');
		getline(f_Expediente, Ssex, '\t');
		getline(f_Expediente, Sestatura, '\t');
		getline(f_Expediente, SmasaMuscu, '\t');
		getline(f_Expediente, Speso, '\t');
		getline(f_Expediente, SporGrasaC, '\t');
		getline(f_Expediente, ScanTriGana, '\t');
		getline(f_Expediente, ScanPartIron, '-');
		if (!Scedula.empty() && !nombre.empty() && !SfechaN.empty() && !ShorasEn.empty() && !StemP.empty() && !Ssex.empty() && !Sestatura.empty() && !SmasaMuscu.empty() && !Speso.empty() && !SporGrasaC.empty() && !ScanTriGana.empty() && !ScanPartIron.empty())
		{
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
			fechN = validarFechaA(SfechaN);
			string fecha = "";
			deportista = new Triatlonista(cedula, nombre, telefono, fechN, horasEn, temP, *sex, estatura, masaMuscu, peso, porGrasaC, canTriGana, canPartIron);
			lisAux->insertarElem(deportista);
			expe = new Expediente(cedula, nombre, telefono, fechN, horasEn, temP, *sex, estatura, masaMuscu, peso, porGrasaC, canTriGana, canPartIron);
			_gym->getListaExpediente()->insertarElem(expe);
			getline(f_Expediente, fecha, '\n');
			if (!fecha.empty()) {
				ListaT<Fecha>* lisFecha = new ListaT<Fecha>;
				Fecha* IDcurso = NULL;

				stringstream cursIDs(fecha);
				while (getline(cursIDs, fecha, '\t')) {
					stringstream fech(fecha);
					getline(fech, Sdia, '/');
					getline(fech, Smes, '/');
					getline(fech, Sannio, '\n');
					if (!fecha.empty()) {
						dia = stoi(Sdia);
						mes = stoi(Smes);
						annio = stoi(Sannio);
						fechaR = new Fecha(dia,mes,annio);
						lisFecha->insertarDultimo(fechaR);
						deportista->setFechaDeultimoPago(fechaR);
						expe->setLisFecha(lisFecha);
					}
				}
			}

			
		}
		else { return false; }

	

	}


	f_Expediente.close();
	return false;
}
//hola que tal 
