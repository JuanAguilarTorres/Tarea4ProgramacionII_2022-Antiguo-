#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/producto.h"

using namespace std;

namespace
{
    TEST(Producto_Test, obtener_Id_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto1 = new Producto(7,"Detergente", 5);

        // Act - ejecute la operación
        int actual = producto1->obtenerId();
        int esperado = 7;

        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }

    TEST(Producto_Test, operador_de_Salida_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Producto *producto1 = new Producto(1,"Detergente", 5);

        // Act - ejecute la operación

        std::ostringstream stream;
        stream << producto1;

        std::string actual = stream.str();
        std::string esperado = "[1] - Detergente, Cantidad: 5";

        delete producto1;
        // Assert - valide los resultados
        EXPECT_EQ(esperado, actual);
    }
}
    