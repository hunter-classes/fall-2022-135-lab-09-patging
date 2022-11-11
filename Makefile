#Patrick Ging MakeFile

#executables
main: main.o funcs.o 3d-space.o
	g++ -o main -std=c++11 main.o funcs.o 

tests: tests.o funcs.o doctest.h
	g++ -o tests -std=c++11 tests.o funcs.o 3d-space.o


# .o files

3d-space.o: 3d-space.cpp coord3d.h
	g++ -c -std=c++11 3d-space.cpp

funcs.o: funcs.cpp funcs.h
	g++ -c -std=c++11 funcs.cpp

main.o: main.cpp funcs.h
	g++ -c -std=c++11 main.cpp funcs.cpp

tests.o: tests.cpp doctest.h funcs.h
	g++ -c -std=c++11 tests.cpp funcs.cpp 3d-space.cpp

#misc
clean:
	rm -f main.o funcs.o tests.o tests main 3d-space.o a.out