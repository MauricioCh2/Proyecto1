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
	bool ver = false;
	ofstream cursos;
	cursos.open("../ListaCursos.txt", ios::out | ios::trunc);
	if (cursos.fail()) {
		cout<<"Error al abrir :("; 
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
		cout << "Error al abrir :(";
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
		cout << "Error al abrir :(";
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

bool Archivos::cargarDeportistas()
{
	ifstream f_Deportistas("../ListaDeportista.txt");
	string  nombre, telefono;
	string Scedula,Ssex, ShorasEn, ScanPartIron, ScanTriGana, StemP, Sestatura, SmasaMuscu, Speso, SporGrasaC, SfechaN;
	Fecha* fechN = NULL;
	const char* sex;
	int cedula, horasEn, canPartIron, canTriGana;
	double temP, estatura, masaMuscu, peso, porGrasaC;
	Deportista* Deportista = NULL;

	while (f_Deportistas.good()) {
		getline(f_Deportistas, Scedula, '\t');
		getline(f_Deportistas, nombre, '\t');
		getline(f_Deportistas, SfechaN, '\t');
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
					int con = 1;
					int con2 = 1;
					if (lisAux != NULL) {
						conD = lisAux->contador();
					}
					conID = lisIdCli->contador();
					while (conD != con) {
						while (conID != con2) {
							if (lisAux->contadorEspecifico(con2)->getIdent() == lisIdCli->contadorEspecifico(conID)->getIdent()) {
								grupAux->ingresarDeportista(lisAux->contadorEspecifico(con2));
							}
							con2++;
						}

						con++;
					}
			}

		}
			

	}
	f_Grupo.close();
	return false;
}

bool Archivos::cargarExpediente()
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
	stringMOD* IDcurso = NULL;
	stringMOD* IDgrupo = NULL;
	int canC = 0;
	int canG = 0;
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
		getline(f_Expediente, ScanPartIron, '\n');
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

			deportista = new Triatlonista(cedula, nombre, telefono, fechN, horasEn, temP, *sex, estatura, masaMuscu, peso, porGrasaC, canTriGana, canPartIron);
			lisAux->insertarElem(deportista);
		}
		else { return false; }

		/*getline(f_Expediente, cursos, '/');
		stringstream cursosS(cursos);
		ListaT<stringMOD>* lisCursos = new ListaT<stringMOD>;
		while (getline(cursosS, IdeCursos, '\t')) {
			IDcurso = new stringMOD(IdeCursos);
			lisCursos->insertarElem(IDcurso);
		}
		getline(f_Expediente, grupos, '\n');
		stringstream gruposS(grupos);
		ListaT<stringMOD>* lisGrupos = new ListaT<stringMOD>;
		while (getline(gruposS, IdeGrupos, '\t')) {
			IDgrupo = new stringMOD(IdeGrupos);
			lisGrupos->insertarElem(IDgrupo);
		}
		lisAux->insertarElem(deportista);*/
		

		//Forma de jp-------------------------------------------
		//stringMOD* c1 = NULL;
		//stringMOD* c2 = NULL;
		//stringMOD* c3 = NULL;
		//stringMOD* c4 = NULL;

		//c1 = lisCursos->contadorEspecifico(1);
		//c2 = lisCursos->contadorEspecifico(2);
		//c3 = lisCursos->contadorEspecifico(3);
		//c4 = lisCursos->contadorEspecifico(4);

		//stringMOD* g1 = NULL;
		//stringMOD* g2 = NULL;
		//stringMOD* g3 = NULL;
		//stringMOD* g4 = NULL;
		//g1 = lisGrupos->contadorEspecifico(1);
		//g2 = lisGrupos->contadorEspecifico(2);
		//g3 = lisGrupos->contadorEspecifico(3);
		//g4 = lisGrupos->contadorEspecifico(4);
		///*_gym->ingresarClienteAGrupos(c1->getIdent(), g1->getIdent(), Deportista);
		//_gym->ingresarClienteAGrupos(c2->getIdent(), g2->getIdent(), Deportista);
		//_gym->ingresarClienteAGrupos(c3->getIdent(), g3->getIdent(), Deportista);
		//_gym->ingresarClienteAGrupos(c4->getIdent(), g4->getIdent(), Deportista);*/




		//Iterador<stringMOD>* iterC = NULL;
		//Iterador<stringMOD>* iterC2 = NULL;
		//Iterador<Grupo>* iterGrup = NULL;
		//Iterador<Grupo>* iterGrup2 = NULL;
		//int contc = 1;
		//iterC = lisCursos->begin();
		//iterC2 = lisCursos->end();
		//for (; iterC->getPNodo() != iterC2->getPNodo(); iterC->operator++()) {
		//	if (lisCursos->contadorEspecifico(contc)->getIdent()==iterC->operator*()->getIdent()) {
		//		iterGrup = _gym->getListaCurso()->encontrarEsp(iterC->operator*()->getIdent())->getListaGrupos()->begin();
		//		iterGrup2 = _gym->getListaCurso()->encontrarEsp(iterC->operator*()->getIdent())->getListaGrupos()->end();
		//		for (; iterGrup->getPNodo() != iterGrup2->getPNodo(); iterGrup->operator++()) {
		//			if (lisGrupos->contadorEspecifico(contc)->getIdent() == iterGrup->operator*()->getIdent()) {
		//				iterGrup->operator*()->ingresarDeportista(deportista);
		//			}

		//		}
		//		lisGrupos->eliminarEspe(iterGrup->operator*()->getIdent());
		//	}
		//	contc++;
		//	if (contc==4) {
		//		break;
		//	}
		//}
		
		/*canC = lisCursos->contador();
		string cur;
		string  g;
		while (canC!=0) {
			
			cur = lisCursos->contadorEspecifico(canC)->getIdent();
			canG = lisGrupos->contador();
			if (lisCursos->contadorEspecifico(canG)!=NULL) {
				while (canG != 0) {
					g = lisGrupos->contadorEspecifico(canG)->getIdent();
					_gym->ingresarClienteAGrupos(cur,g, Deportista);
					canG--;
				}
				canC--;
			}
		}*/
		
		//no se si aqui hace falta un throw

	}


	f_Expediente.close();
	return false;
}
