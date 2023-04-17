build: create_dir src/main.cpp ppm.o scene.o 
	g++ -g src/main.cpp lib/*.o -Iinclude -o app.out

ppm.o: src/ppm.cpp include/ppm.h
	g++ -g -c src/ppm.cpp	-Iinclude -o lib/ppm.o

scene.o: src/scene.cpp include/scene.h
	g++ -g -c src/scene.cpp -Iinclude -o lib/scene.o


clean:
	rm -rf lib
	rm -f output.ppm
	rm -f app.out

create_dir:
	mkdir -p lib