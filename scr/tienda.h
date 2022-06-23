#ifndef TIENDA_H
#define TIENDA_H

#include "producto.h"
#include <vector>
#include <iostream>


using namespace std;

class Tienda {

    vector<Producto *> productos;
    char nombre[15];         //15
    char sitioWeb[24];       //24
    char localizacion[24];   //24
    char telefono[8];        //8

    public:
    Tienda(string nombre, string sitioWeb, string localizacion, string telefono);
    Tienda();
    ~Tienda();
    void AgregarProducto(Producto *nuevoProducto);
    void GuardarEnStreamBinario(ostream *streamSalida);
    void CargarDesdeStreamBinario(istream *streamEntrada);
    void CargarProductoPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicionProducto);

    friend ostream& operator << (ostream &o, const Tienda *Tienda);
};

#endif