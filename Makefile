all: a test
test: testing.o image.o render.o
	g++ testing.o image.o render.o -o test

a: main.o render.o image.o
	g++ main.o render.o image.o -o a

image.o: image.o Graphics/image.h
	g++ -c -Iinclude image.cpp

render.o: render.cpp Graphics/render.h
	g++ -c -Iinclude render.cpp

testing.o: testing.cpp
	g++ -c testing.cpp

clean:
	rm *.o *.exe 