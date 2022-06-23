#include "producto.h"
#include <iostream>
#include <cstring>

Producto::Producto(int id, string nombre, int existencia)
{
    this->id = id;
    strcpy(this->nombre, nombre.c_str());
    this->existencia = existencia;
}

Producto::Producto()
{
    this->id = 0;
    strcpy(this->nombre, "");
    this->existencia = 0;
}


ostream& operator << (ostream &o, const Producto *empleado)
{
    o << "[" << empleado->id << "] - " << empleado->nombre << ", Cantidad:" << empleado->existencia;
    return o;
}