FLAGS = -g -c --std=c++17

all:
	mkdir -p obj
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o obj/producto.o
	g++ $(FLAGS) src/tienda.cpp -o obj/tienda.o
	g++ -shared -o bin/libTienda.so obj/producto.o obj/tienda.o
	mkdir -p bin/include
	cp src/producto.h src/tienda.h ./bin/include

test:
	mkdir -p bin
	g++ $(FLAGS) src/producto.cpp -o bin/producto.o
	g++ $(FLAGS) src/tienda.cpp -o bin/tienda.o
	g++ $(FLAGS) tests/tienda_test.cpp -o bin/tienda_test.o
	g++ $(FLAGS) tests/producto_test.cpp -o bin/producto_test.o
	g++ -g -o bin/tests bin/producto.o bin/tienda.o bin/tienda_test.o bin/producto_test.o -lgtest -lgtest_main -lpthread 

clean:
	rm -Rf bin
	rm -Rf obj