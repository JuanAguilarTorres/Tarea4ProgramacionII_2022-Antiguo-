FLAGS = -g -c --std=c++17

all:
	mkdir -p bin
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoAsalariado.cpp -o bin/empleadoAsalariado.o
	g++ $(FLAGS) src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o
	cp ./personas.txt ./bin/personas.txt
	cp ./nomina.txt ./bin/nomina.txt
	cp ./horastrabajadas.txt ./bin/horastrabajadas.txt
	g++ -g -o bin/tarea2 bin/empleado.o bin/empleadoAsalariado.o bin/empleadoPorHoras.o bin/planilla.o bin/main.o

test:
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ $(FLAGS) tests/tienda_test.cpp -o bin/tienda_test.o
	g++ $(FLAGS) tests/producto_test.cpp -o bin/producto_test.o
	g++ -g -o bin/tests bin/producto.o bin/tienda.o bin/tienda_test.o bin/producto_test.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
