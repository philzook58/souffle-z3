libz3stubs.so: z3stubs.cpp
	g++ -c -fPIC -o z3stubs.o -std=c++17 z3stubs.cpp -I/usr/local/include -I/home/philip/Documents/prolog/souffle/src/include
	g++ -shared -o libz3stubs.so z3stubs.o

all: libz3stubs.so
