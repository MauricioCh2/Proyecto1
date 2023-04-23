#include "Menu.h"
void Menu::inicio() {
	_gym = new Gym();
	bool fin = false;
	imprimirString("Bienvenido al GYM de triatlon");

	imprimirString("Digite la Fecha en formato dia/mes/annio");
	fecha = validarFecha();
	//cout<<fecha->toString()<< "prueba ";
	while (!fin) {
		llamarMenus();
	}
}

string Menu::menuPrincipal() {
	stringstream s;
	s << "	 <Menú Principal>		  " << endl
		<< "[1]Administracion General-------------" << endl
		<< "[2]Control de Deportista--------------" << endl
		<< "[3]Reportes generales-----------------" << endl
		<< "[4]Control de Grupo-------------------" << endl
		<< "[5]Control de Pagos-------------------" << endl
		<< "[5]Guardar Archivos y salir-----------" << endl
		<< "Digite una opcion: ";

	return s.str();
}

//------------------------------------------------------------------------
//Administracion General--------------------------------------------------
string Menu::menuAdministracion() {
	stringstream s;
	s << "	 <Menú Administracion>		  " << endl
		<< "[1]. Nombre del Gimnasio" << endl
		<< "[2]. Monto de mensualidad " << endl
		<< "[3]. Atras\n\n"
		<< "Digite una opcion: ";

	return s.str();

}
bool Menu::opMenuAdministracion(int op) {

	switch (op) {
	case 1:
		imprimirString("<1. Administración General > <1. Nombre del Gimnasio>  ");
		imprimirString("Ingrese el nombre del Gimnasio : _ FitnessUNA");
		_gym->setNombreDgym(" _ FitnessUNA");
		imprimirString("<Digite Enter >");
		break;
	case 2:
		imprimirString("<1. Administración General>  <2. Monto de mensualidad >  ");
		imprimirString("Ingrese el Monto de mensualidad: 25000 ");
		_gym->setMensualidadDgym(25000);
		imprimirString("<Digite Enter >");
		break;

	default:

		break;
	};
	return false;
}
//Control  Deportistas --------------------------------------------------
string Menu::menuDeportista() {
	stringstream s;
	s << "" << endl
		<< "[1]Ingreso de nuevo deportista-----------" << endl
		<< "[2]Modificacion de deportista------------" << endl
		<< "[3]Listado de deportista-----------------" << endl
		<< "[4]Detalle de deportista en especifico-" << endl
		<< "[5]Atras\n\n"
		<< "Digite una opcion: ";
	return s.str();
}
bool Menu::opMenuDeportista(int op)
{
	//Deportista
	string cedula = "";
	string nombre = "";
	string telefono = "";
	Fecha* fechaNa;
	//Ciclista
	int horasEntrenem = 0;
	double temProm = 0;
	//Corredor
	char sexo;
	double estatura = 0.0;
	//Nadador
	double masaMuscular = 0.0;
	double peso = 0.0;
	double PgrasaCorporalMC = 0.0;
	//triatlonista
	int cantPartiEnIronMan = 0;
	int canTriaGanados = 0;
	//clientes (esto puede variar)
	Deportista* cliente = NULL;
	switch (op) {
	case 1: // Ingreso nuevo deportista 
		imprimirString("<2.Control Deportistas>  <1.Ingreso nuevo deportista>");

		//deportista
		imprimirString("Cedula: ");
		cedula = recivirString();
		imprimirString("Nombre: ");
		nombre = recivirString();
		imprimirString("Telefono: ");
		telefono = recivirString();
		imprimirString("Fecha nacimiento: ");
		fechaNa = validarFecha();
		//Ciclista
		imprimirString("Horas de entrenamiento: ");
		horasEntrenem = recivirDouble();
		imprimirString("Temperatura promedio al entrenar: ");
		temProm = recivirDouble();
		//Corredor
		imprimirString("Sexo: ");
		sexo = recivirChar();
		imprimirString("Estatura: ");
		estatura = recivirDouble();
		//Nadador
		imprimirString("Porcentaje masa corporal: ");
		masaMuscular = recivirDouble();
		imprimirString("Peso: ");
		peso = recivirDouble();
		imprimirString("Porcentaje de grasa corporal: ");
		PgrasaCorporalMC = recivirDouble();
		//triatlonista
		imprimirString("Cantidad de participaciones en Iron Man");
		cantPartiEnIronMan = recivirDouble();
		imprimirString("Cantidad de triatlones ganados:");
		canTriaGanados = recivirDouble();

		system("pause");
		cliente = new Triatlonista(cedula, nombre, telefono, fechaNa, horasEntrenem, temProm, sexo, estatura, masaMuscular, peso, PgrasaCorporalMC, canTriaGanados, cantPartiEnIronMan);
		_gym->ingresarListaClientes(cliente);
		enter();
		limpiarPantalla();
		break;
	case 2: //Modificacion de deportista
		imprimirString("en dersarrollo");
		break;
	case 3: //Listado de deportistas
		imprimirString(_gym->imprimirListaClientes());
		break;
	case 4: //Detalle de deportista especificp

		break;
	case 5: //Atras
		limpiarPantalla();
		return true;
		break;
	default:

		break;
	};
	return false;
}
//Control Cursos--------------------------------------------------------------
string Menu::menuCursos()
{
	stringstream s;
	s << "MENU CLIENTES" << endl
		<< "[1].Ingreso nuevo curso" << endl
		<< "[2]. Reporte de curso específico " << endl
		<< "[3]. Modificación de curso específico " << endl
		<< "Digite una opcion: ";

	return s.str();
}
bool Menu::opMenuCursos(int op)
{
	switch (op) {
	case 1: // Ingreso nuevo grupo;
		imprimirString("Opcion en desarrollo");
		imprimirString("Opcion en desarrollo");
		break;
	case 2: //Modificacion de  grupo especifico
		imprimirString("Opcion en desarrollo");
		imprimirString("Opcion en desarrollo");
		break;
	case 3:
		imprimirString("Opcion en desarrollo");
		imprimirString("Opcion en desarrollo");
		break;
	default:
		break;
	};
	return false;
}

//mauricio
//Control de grupos-------------------------------------------------------
string Menu::menuGrupos()
{
	stringstream s;
	s << "\t<4.Control de grupos>\n";
	s << "[1]Ingreso nuevo grupo\n"
		<< "[2]Modificacion de  grupo especifico\n"
		<< "[3]Matricula en grupo especifico\n"
		<< "[4]Reporte de grupo especifico\n"
		<< "[5]Reporte deportistas matriculados en grupo\n"
		<< "[6]Cancelacion de  matricula en grupo\n"
		<< "[7]Atras\n\n"
		<< "Digite una opcion: "
		<< endl;
	return s.str();
}
bool Menu::opMenuGrupos(int op)
{
	switch (op) {
	case 1: // Ingreso nuevo grupo;
		//listar los cursos con su codigo 
		imprimirString("< 4.Control Grupos> < 1.Ingreso nuevo grupo>");
		imprimirString("Opcion en desarrollo");
		break;
	case 2: //Modificacion de  grupo especifico
		imprimirString("Opcion en desarrollo");
		imprimirString("Opcion en desarrollo");
		break;
	case 3: //matricula de grupo especifico
		imprimirString("Opcion en desarrollo");
		imprimirString("Opcion en desarrollo");

		break;
	case 4: //Reporte de grupo especifico 
		imprimirString("Opcion en desarrollo");
		imprimirString("Opcion en desarrollo");
		break;
	case 5: //Reporte deportistas matriculados en grupo
		imprimirString("Opcion en desarrollo");
		imprimirString("Opcion en desarrollo");

		break;
	case 6://Cancelacion de  matricula en grupo
		imprimirString("Opcion en desarrollo");
		imprimirString("Opcion en desarrollo");
		break;
	case 7:
		limpiarPantalla();
		return true;
		break;
	default:

		break;
	}
	return false;
}
//Control Pagos-------------------------------------------------------
string Menu::menuPagos()
{
	stringstream s;
	s << "\t<3.Control de deportistas>\n";
	s << "[1]Registro nuevo de pago\n"
		<< "[2]Reporte de pagos por deportista\n"
		<< "[3]Atras"
		<< "Digite una opcion: "
		<< endl;
	return s.str();
}

bool Menu::opMenuPagos(int op)
{
	Fecha* fechAux = NULL;
	int deportista = 0;

	switch (op) {
	case 1: // Registro nuevo de pago\n"
		imprimirString("<5.Control  Pagos> <1.Registro de nuevo  pago>");

		//listar los cursos con su codigo 
		imprimirString("Opcion en desarrollo");
		break;
	case 2: //Modificacion de  grupo especifico
		imprimirString("<5.Control  Pagos> <1.Registro de nuevo  pago>");

		imprimirString("Opcion en desarrollo");
		break;
	case 3: //Cancelar
		limpiarPantalla();
		return true;

		break;
	default:

		break;
	}
	return false;
}

bool Menu::llamarMenus() {
	int op = 0;
	int opE = 0;

	imprimirString(menuPrincipal());
	op = recivirInt();
	switch (op) {
	case 1://Administracion General 
		limpiarPantalla();
		imprimirString(menuAdministracion());
		op = recivirInt();
		opMenuCursos(op);
		break;
	case 2://Control de Deportistas
		limpiarPantalla();
		imprimirString(menuDeportista());
		op = recivirInt();
		opMenuDeportista(op);
		break;
	case 3://Control de Cursos
		limpiarPantalla();
		imprimirString(menuCursos());
		op = recivirInt();
		opMenuCursos(op);
		break;
	case 4://Control de Grupos
		limpiarPantalla();
		imprimirString(menuGrupos());
		op = recivirInt();
		opMenuGrupos(op);

		break;
	case 5://Control Pagos
		limpiarPantalla();
		imprimirString(menuPagos());
		op = recivirInt();
		opMenuPagos(op);

		break;
	case 6: //Guardar en Archivos y salir
		limpiarPantalla();
		imprimirString("Buen dia...");
		return true;
		//Completar Archivos al 100%
		//Y despues "delete()" cuando ya leyo y gurado TODO
		break;
	default:
		break;
	}
	return false;

}


