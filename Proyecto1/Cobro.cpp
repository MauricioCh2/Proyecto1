#include "Cobro.h"

int Cobro::EstadoDcliente(Deportista* tri, Fecha* f)
{
	if (tri->getFechaDeultimoPago() == NULL) {
		return 3;//Inactivo
	}
	else if (tri->getFechaDeultimoPago()->getAno() == f->getAno() && tri->getFechaDeultimoPago()->getMes() > f->getMes()) {
		return 1;//Activo
	}
	else if (tri->getFechaDeultimoPago()->getAno() == f->getAno() && tri->getFechaDeultimoPago()->getMes() == f->getMes()) {
		return 1;//Activo
	}
	else if (tri->getFechaDeultimoPago()->getAno() == f->getAno() && tri->getFechaDeultimoPago()->getMes() == (f->getMes() - 1) && tri->getFechaDeultimoPago()->getDia() >= f->getDia()) {
		return 1;//Activo
	}
	return 2;//deportistas con morosidad
}

Fecha* Cobro::getFechaDeultimoPago(Deportista* tri, Fecha* f, int mensu)
{
	int mesesDmorosidad = 0;
	bool ex = false;
	int mesesApagar = 0;
	string respuesta;
	int respuestai = 0;
	int op = 0;
	Fecha* aux = new Fecha(0, 0, 0);
	if (tri->getFechaDeultimoPago() == NULL) {
		op = 3;
	}
	op = EstadoDcliente(tri, tri->getFechaDeultimoPago());
	switch (op)
	{
	case 1:
		imprimirString("---Usted esta Activo---");
		imprimirString("Cuantos meses le gustaria pagar por adelantado? { ya que su estado actual en el gimanccio es de [Activo] } ");
		do {
			try {
				mesesApagar = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		aux->setDia(tri->getFechaDeultimoPago()->getDia());
		aux->setMes(tri->getFechaDeultimoPago()->getMes() + mesesApagar);
		aux->setAno(tri->getFechaDeultimoPago()->getAno());
		while (aux->getMes() > 12) {
			aux->setMes(aux->getMes() - 12);
			aux->setAno(aux->getAno() + 1);
		}
		imprimirString2("Monto a pagar :");
		imprimirInt(mensu * mesesApagar);
		imprimirString("");
		imprimirString("Desgloce de dicho monto: ");
		imprimirInt2(mensu * mesesApagar);
		imprimirString2(" (");
		imprimirInt2(mensu);
		imprimirString2("X");
		imprimirInt2(mesesApagar);
		imprimirString2(" )");

		break;
	case 2:
		imprimirString("---Usted esta Moroso---");
		imprimirString("Usted esta Moroso por un total de meses de : ");
		mesesDmorosidad = (f->getMes() - tri->getFechaDeultimoPago()->getMes());
		imprimirInt(mesesDmorosidad);
		imprimirString("");
		imprimirString2("Nota, la mensualidad de este Gimnacio es: ");
		imprimirInt2(mensu);
		imprimirString("");
		imprimirString2("Su monto de Morosidad en colones: ");
		imprimirInt(mesesApagar * mensu);
		imprimirString("");
		imprimirString("Cuantos meses le gustaria pagar dada su deuda?");
		do {
			try {
				mesesApagar = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
		} while (ex == false);
		ex = false;
		if (mesesApagar == mesesDmorosidad) {
			aux->setDia(f->getDia());
			aux->setMes(f->getMes());
			aux->setAno(f->getAno());
		}
		aux->setDia(tri->getFechaDeultimoPago()->getDia());
		aux->setMes(tri->getFechaDeultimoPago()->getMes() + mesesApagar);
		aux->setAno(tri->getFechaDeultimoPago()->getAno());
		while (aux->getMes() > 12) {
			aux->setMes(aux->getMes() - 12);
			aux->setAno(aux->getAno() + 1);
		}
		imprimirString2("Monto a pagar :");
		imprimirInt(mensu * mesesApagar);
		imprimirString("");
		imprimirString2("Desgloce de dicho monto dados los meses que pago: ");
		imprimirInt2(mensu * mesesApagar);
		imprimirString2(" (");
		imprimirInt2(mensu);
		imprimirString2("X");
		imprimirInt2(mesesApagar);
		imprimirString2(" )");
		break;
	case 3:
		imprimirString("---Usted esta Inactivo---");
		imprimirString("Le gustaria registrase en el gym?");
		imprimirString("Si o No?");
		do {
			try {
				respuesta = recivirString();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
			if (respuesta == "SI" || respuesta == "Si" || respuesta == "si" || respuesta == "sI") {
				respuestai = 1;
			}
		} while (ex == false);
		imprimirString2("Nota, la mensualidad de este Gimnacio es: ");
		imprimirInt(mensu);
		if (respuestai == 1) {
			aux->setDia(f->getDia());
			aux->setMes(f->getMes());
			aux->setAno(f->getAno());
			imprimirString("Monto a pagar :");
			imprimirInt(mensu);
			imprimirString2("Desgloce de dicho monto dados los meses que pago:");
			imprimirInt2(mensu);
			imprimirString("(Cuenta con una plazo de un mes, antes del siguente pago)");
			imprimirString("Bienvencido al GYM :)");
		}
		break;

	default: break;
	}
	return aux;
}



