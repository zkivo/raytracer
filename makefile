build: create_dir src/main.cpp ppm.o float3.o ray.o camera.o scene.o world.o 
	g++ src/main.cpp lib/*.o -Iinclude -o app.out

ppm.o: src/ppm.cpp include/ppm.h
	g++ -c src/ppm.cpp	-Iinclude -o lib/ppm.o

float3.o: src/float3.cpp include/float3.h
	g++ -c src/float3.cpp -Iinclude -o lib/float3.o

ray.o: src/ray.cpp include/ray.h
	g++ -c src/ray.cpp -Iinclude -o lib/ray.o
	
camera.o: src/camera.cpp include/camera.h
	g++ -c src/camera.cpp -Iinclude -o lib/camera.o

scene.o: include/scene.h
	g++ -c include/scene.h -Iinclude -o lib/scene.o

world.o: include/world.h
	g++ -c include/world.h -Iinclude -o lib/world.o


clean:
	rm -rf lib
	rm -f output.ppm
	rm -f app.out

create_dir:
	mkdir -p lib