#include "tienda.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <exception>
#include "excepcionEliminarIncorrecto.h"
#include "excepcionAgregarDuplicado.h"
#include "excepcionEditarIncorrecto.h"

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
    int nuevoId = nuevoProducto->obtenerId();

    for (Producto *producto : this->productos)
    {
        if (nuevoId == producto->obtenerId()){
            throw excepcionAgregarDuplicado();
        }
    }

    this->productos.push_back(nuevoProducto);
}

void Tienda::agregarProducto(int id, string nombre, int existencias)
{
    Producto *nuevoProducto = new Producto(id, nombre, existencias);

    int nuevoId = nuevoProducto->obtenerId();

    for (Producto *producto : this->productos)
    {
        if (nuevoId == producto->obtenerId()){
            throw excepcionAgregarDuplicado();
        }
    }

    this->productos.push_back(nuevoProducto);
}

void Tienda::eliminarProducto(int id)
{  
    int indice = 0;
    bool encontrado = false;
    for (Producto *producto : this->productos)
    {
        if (id == producto->obtenerId()){
            delete producto;
            productos.erase(productos.begin() + indice);
            encontrado = true;
        }
        
        indice ++;
    }
    
    if (encontrado != true)
    {
        throw excepcionEliminarIncorrecto();
    }
}

void Tienda::editarProducto(int id, string nombre, int existencias)
{
    try
    {
        this->eliminarProducto(id);
        this->agregarProducto(id, nombre, existencias);

    }
    catch(excepcionEliminarIncorrecto)
    {
        throw excepcionEditarIncorrecto();
    }
}

string Tienda::tiendaAString()
{
    string consulta = "";
    std::stringstream consultaStream;    

    consultaStream << this->nombre << ", Sitio: " << this->sitioWeb << ", Ubicación: " << this->localizacion << ", número: " << this->telefono << ", Productos: " << std::endl;

    for (Producto *producto : this->productos)
    {
        consultaStream << producto << endl;
    }
    
    consulta = consultaStream.str();
    return consulta;
    
}

vector<Producto *> Tienda::consultarProductos()
{
    return this->productos;
}

void Tienda::GuardarEnStreamBinario(ostream *streamSalida)
{
    
    streamSalida->write((char *)this, 71);

    for (Producto *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void Tienda::CargarDesdeStreamBinario(istream *streamEntrada)
{
    // Calcule cantidad de registros
    streamEntrada->seekg( 0, std::ios::end );
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = ((cantidadBytesEnArchivo - 71) / sizeof(Producto));

    //Leer la tienda
    streamEntrada->seekg( 0, std::ios::beg ); // Empezar desde el principio del archivo
    streamEntrada->read((char *)this, 71);

    // Leer cada producto
    streamEntrada->seekg(71, std::ios::beg ); // Empezar desde el principio de los productos
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto)); // variable para guardar y cuántos bytes leo

        this->agregarProducto(producto);
    }
    
}

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << tienda->nombre << ", Sitio: " << tienda->sitioWeb << ", Ubicación: " << tienda->localizacion << ", número: " << tienda->telefono << ", Productos: " << std::endl;

    for (Producto *producto : tienda->productos)
    {
        o << producto << endl;
    }
    
    return o;
}