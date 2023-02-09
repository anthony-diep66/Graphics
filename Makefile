all: a test
test: testing.o image.o render.o ray.o
	g++ testing.o image.o render.o ray.o -o test

a: main.o render.o image.o ray.o
	g++ main.o render.o image.o ray.o -o a

image.o: image.o Graphics/image.h
	g++ -c -Iinclude image.cpp

render.o: render.cpp Graphics/render.h
	g++ -c -Iinclude render.cpp

testing.o: testing.cpp
	g++ -c testing.cpp

ray.o: ray.cpp Graphics/ray.h
	g++ -c -Iinclude ray.cpp

clean:
	rm *.o *.exe 