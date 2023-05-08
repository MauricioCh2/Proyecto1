#pragma once
#include<iostream>
#include<sstream>
#include"Deportista.h"
#include "Menu.h"

using namespace std;
class Cobro {
public:
    static int EstadoDcliente(Deportista*, Fecha*);
    static Fecha* getFechaDeultimoPago(Deportista*, Fecha*, int);
};
