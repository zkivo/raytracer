ppm.o: src/ppm.cpp
	g++ -c src/ppm.cpp	-Iinclude -o lib/ppm.o

app: src/main.cpp ppm.o 
	g++ src/main.cpp lib/ppm.o -Iinclude -o app