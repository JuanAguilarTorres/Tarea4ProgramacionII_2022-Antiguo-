#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/tienda.h"

using namespace std;

namespace
{
    TEST(Tienda_Test, agregar_Producto_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto1 = new Producto(1,"Detergente", 5);
        Tienda *tiendaActual = new Tienda("TiendaA", "Tienda.com", "50m Norte", "12345678");
        
        // Act - ejecute la operación
        tiendaActual->agregarProducto(producto1);
        tiendaActual->agregarProducto(2,"Cereal", 10);

        std::ostringstream streamActual;

        streamActual << tiendaActual;

        std::string esperado = "TiendaA, Sitio: Tienda.com, Ubicación: 50m Norte, número: 12345678, Productos: \n[1] - Detergente, Cantidad: 5\n[2] - Cereal, Cantidad: 10\n";
        std::string actual = streamActual.str();

        delete tiendaActual;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

    }

    TEST(Tienda_Test, eliminar_Producto_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto1 = new Producto(1,"Detergente", 5);
        Tienda *tiendaEsperado = new Tienda("TiendaA", "Tienda.com", "50m Norte", "12345678");
        Tienda *tiendaActual = new Tienda("TiendaA", "Tienda.com", "50m Norte", "12345678");
        
        // Act - ejecute la operación
        tiendaActual->agregarProducto(producto1);
        tiendaActual->eliminarProducto(1);

        std::ostringstream streamEsperado;
        std::ostringstream streamActual;

        streamEsperado << tiendaEsperado;
        streamActual << tiendaActual;

        std::string esperado = streamEsperado.str();
        std::string actual = streamActual.str();

        delete tiendaEsperado;
        delete tiendaActual;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

    }

    TEST(Tienda_Test, editar_Producto_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaActual = new Tienda("TiendaA", "Tienda.com", "50m Norte", "12345678");
        
        // Act - ejecute la operación
        tiendaActual->agregarProducto(1,"Detergente", 5);
        tiendaActual->editarProducto(1,"Pasta", 10);

        std::ostringstream streamActual;

        streamActual << tiendaActual;

        std::string esperado = "TiendaA, Sitio: Tienda.com, Ubicación: 50m Norte, número: 12345678, Productos: \n[1] - Pasta, Cantidad: 10\n";
        std::string actual = streamActual.str();

        delete tiendaActual;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);

    }

    TEST(Tienda_Test, consulta_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaActual = new Tienda("TiendaA", "Tienda.com", "50m Norte", "12345678");

        // Act - ejecute la operación
        tiendaActual->agregarProducto(1,"Pasta", 10);

        string esperado = "TiendaA, Sitio: Tienda.com, Ubicación: 50m Norte, número: 12345678, Productos: \n[1] - Pasta, Cantidad: 10\n";
        string actual = tiendaActual->consultarProductos();

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Tienda_Test, escribir_Leer_Binario_Tienda_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda("TiendaA", "Tienda.com", "50m Norte", "12345678");

        Producto *producto1 = new Producto(1, "Cereal", 5);
        tiendaEsperada->agregarProducto(producto1);

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
        streamSalidaTiendaLeida << tiendaLeida;

        ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        delete tiendaLeida;
        delete tiendaEsperada;

        string esperado = "TiendaA, Sitio: Tienda.com, Ubicación: 50m Norte, número: 12345678, Productos: \n[1] - Cereal, Cantidad: 5\n"; 
        string salidaTiendaEsperada = streamSalidaTiendaEsperada.str();

        // Primero, validar la salida de la Tienda esperada sea correcta
        EXPECT_EQ(esperado, salidaTiendaEsperada);

        string salidaTiendaLeidaDeArchivo = streamSalidaTiendaLeida.str();
        EXPECT_EQ(esperado, salidaTiendaLeidaDeArchivo);
    }
}

