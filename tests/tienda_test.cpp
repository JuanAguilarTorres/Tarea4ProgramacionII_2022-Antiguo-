#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/tienda.h"

using namespace std;

namespace
{
    TEST(Tienda_Test, Escribir_Leer_Binario_Tienda_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("TiendaA", "Tienda.com", "50m Norte", "12345678");

        Producto *producto1 = new producto(1, "Cereal", 5);
        tiendaEsperada->AgregarProducto(producto1);

        // Act - ejecute la operación
        // Escribir un archivo de prueba
        ofstream archivoSalida;
        archivoSalida.open("archivo_test.dat", ios::out|ios::binary);

        if (!archivoSalida.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para escribir los datos";
            FAIL();
        }

        tiendaEsperada->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();

        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("archivo_test.dat", ios::in|ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo archivo_test.dat para leer los datos";
            FAIL();
        }
    
        Tienda *tiendaLeida = new Tienda();
        tiendaLeida->CargarDesdeStreamBinario(&archivoEntrada);

        ostringstream streamSalidaTiendaLeida;
        streamSalidaTiendaLeida << TiendaLeida;

        ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        delete tiendaLeida;
        delete tiendaEsperada;

        string esperado = "TiendaA. Sitio: Tienda.com, Ubicación: 50m Norte, número: 12345678. Productos: \n[1] - Cereal, Cantidad: 5\n"; 
        string salidaTiendaEsperada = streamSalidaTiendaEsperada.str();

        // Primero, validar la salida de la Tienda esperada sea correcta
        EXPECT_EQ(esperado, salidaTiendaEsperada);

        string salidaTiendaLeidaDeArchivo = streamSalidaTiendaEsperada.str();
        EXPECT_EQ(esperado, salidaTiendaLeidaDeArchivo);
    }
    
}