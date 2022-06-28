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

void Tienda::agregarProducto(Producto *nuevoProducto)
{
    this->productos.push_back(nuevoProducto);
}

void Tienda::agregarProducto(int id, string nombre, int existencias)
{
    Producto *nuevoProducto = new Producto(id, nombre, existencias);
    this->productos.push_back(nuevoProducto);
}

void Tienda::eliminarProducto(int id)
{  
    int indice = 0;
    for (Producto *producto : this->productos)
    {
        if (id == producto->obtenerId()){
            delete producto;
            productos.erase(productos.begin() + indice);
        }
        
        indice ++;
    }
    
}

void Tienda::editarProducto(int id, string nombre, int existencias)
{
    this->eliminarProducto(id);
    this->agregarProducto(id, nombre, existencias);
}

void Tienda::GuardarEnStreamBinario(ostream *streamSalida)
{
    for (Producto *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(producto));
    }
}

void Tienda::CargarProductoPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicionProducto)
{
    streamEntrada->seekg(sizeof(Producto) * posicionProducto);

    Producto *producto = new Producto();
    streamEntrada->read((char *)producto, sizeof(Producto));

    this->agregarProducto(producto);
}

void Tienda::CargarDesdeStreamBinario(istream *streamEntrada)
{
    // Calcule cantidad de registros
    streamEntrada->seekg( 0, std::ios::end );
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = cantidadBytesEnArchivo / sizeof(Producto);

    // Leer cada producto
    streamEntrada->seekg( 0, std::ios::beg ); // Empezar desde el principio del archivo
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto)); // variable para guardar y cuántos bytes leo

        this->agregarProducto(producto);
    }
    
}

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << tienda->nombre << ", Sitio: " << tienda->sitioWeb << ", Ubicación: " << tienda->localizacion << ", número: " << tienda->telefono << ", Productos: " << std::endl; //Pendiente

    for (Producto *producto : tienda->productos)
    {
        o << producto << endl;
    }
    
    return o;
}