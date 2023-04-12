build: create_dir src/main.cpp ppm.o float3.o ray.o camera.o scene.o 
	g++ -g src/main.cpp lib/*.o -Iinclude -o app.out

ppm.o: src/ppm.cpp include/ppm.h
	g++ -g -c src/ppm.cpp	-Iinclude -o lib/ppm.o

float3.o: src/float3.cpp include/float3.h
	g++ -g -c src/float3.cpp -Iinclude -o lib/float3.o

ray.o: src/ray.cpp include/ray.h
	g++ -g -c src/ray.cpp -Iinclude -o lib/ray.o
	
camera.o: src/camera.cpp include/camera.h
	g++ -g -c src/camera.cpp -Iinclude -o lib/camera.o

scene.o: src/scene.cpp include/scene.h
	g++ -g -c src/scene.cpp -Iinclude -o lib/scene.o


clean:
	rm -rf lib
	rm -f output.ppm
	rm -f app.out

create_dir:
	mkdir -p lib