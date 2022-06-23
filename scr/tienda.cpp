#include "tienda.h"
#include <iostream>
#include <cstring>

Tienda::Tienda(string nombre, string sitioWeb, string localizacion, string telefono)
{
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->sitioWeb, sitioWeb.c_str());
    strcpy(this->localizacion, localizacion.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Tienda::Tienda()
{

}

Tienda::~Tienda()
{
    for (Producto *producto : this->productos)
    {
        delete producto;
    }
}