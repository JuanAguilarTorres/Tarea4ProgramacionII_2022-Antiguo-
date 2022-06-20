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
	g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
	g++ $(FLAGS) src/empleadoAsalariado.cpp -o bin/empleadoAsalariado.o
	g++ $(FLAGS) src/empleadoPorHoras.cpp -o bin/empleadoPorHoras.o
	g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
	g++ $(FLAGS) tests/empleadoAsalariado_tests.cpp -o bin/empleadoAsalariado_tests.o
	g++ $(FLAGS) tests/empleadoPorHoras_tests.cpp -o bin/empleadoPorHoras_tests.o
	g++ $(FLAGS) tests/planilla_tests.cpp -o bin/planilla_tests.o
	g++ -g -o bin/tests bin/empleado.o bin/empleadoAsalariado.o bin/empleadoPorHoras.o bin/planilla.o bin/empleadoAsalariado_tests.o bin/empleadoPorHoras_tests.o bin/planilla_tests.o -lgtest -lgtest_main -lpthread


clean:
	rm -Rf bin
