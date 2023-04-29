#pragma once
#include<iostream>
#include<sstream>
#include"Deportista.h"
#include "Menu.h"

using namespace std;
class Cobro { 
public:
    static int EstadoDcliente(Deportista* tri, Fecha* f);
    static Fecha* getFechaDeultimoPago(Deportista* tri, Fecha* f);
};