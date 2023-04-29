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
	else if (tri->getFechaDeultimoPago()->getAno() == f->getAno() && tri->getFechaDeultimoPago()->getMes() == (f->getMes() - 1) && tri->getFechaDeultimoPago()->getDia() >= this->fecha->getDia()) {
		return 1;//Activo
	}
	return 2;//deportistas con morosidad
}

Fecha* Cobro::getFechaDeultimoPago(Deportista* tri, Fecha* f)
{
	int mesesDmorosidad = 0;
	bool ex = false;
	int mesesApagar = 0;
	string respuesta;
	int respuestai = 0;
	Fecha* aux=NULL;
	switch (EstadoDcliente(tri,tri->getFechaDeultimoPago()))
	{
	case 1:
		imprimirString("Cuantos meses le gustaria pagar por adelantado {ya que su estado actual en el gimanccio es de [Activo]} ");
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
		aux = f;
		aux->setMes(f->getMes() + mesesApagar);
		break;
	case 2:
		imprimirString("Usted esta Moroso por un total de meses de : ");
		mesesDmorosidad = ( f->getMes() - tri->getFechaDeultimoPago()->getMes() );
		imprimirInt(mesesDmorosidad);
		imprimirString("Cuantos meses le gustaria pagar dada su deuda ");
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
			aux = f;
		}

		aux = f;
		aux->setMes(tri->getFechaDeultimoPago()->getMes()+ mesesApagar);
		break;
	case 3:
		imprimirString("---Usted esta Inactivo---");
		imprimirString("Le gustaria registrase en el gym?");
		imprimirString("Si o No?");
		do {
			try {
				respuesta = recivirInt();
				ex = true;
			}
			catch (ErrorV* e) {
				cout << e->what() << endl;
				limpiar();
			}
			if (respuesta == "SI" || respuesta == "Si" || respuesta == "si") {
				respuestai = 1;
			}
		} while (ex == false);

		if (respuestai==1) {
			imprimirString("Cuantos meses le gustaria pagar?");
			do {
				try {
					mesesApagar = recivirInt();
					ex = true;
				}
				catch (ErrorV* e) {
					cout << e->what() << endl;
					limpiar();
				}
			}while (ex == false);
			ex = false;
		}
			aux = f;
			aux->setMes(f->getMes() + mesesApagar);
	break;

	default: break;
	}
	return aux;
}

