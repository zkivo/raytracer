build: create_dir src/main.cpp ppm.o float3.o
	g++ src/main.cpp lib/ppm.o -Iinclude -o app.out

ppm.o: src/ppm.cpp
	g++ -c src/ppm.cpp	-Iinclude -o lib/ppm.o

float3.o: src/float3.cpp
	g++ -c src/float3.cpp -Iinclude -o lib/float3.o

clean:
	rm -rf lib
	rm -f output.ppm
	rm -f app.out

create_dir:
	mkdir lib