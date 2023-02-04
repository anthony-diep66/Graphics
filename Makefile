
a: testing.o render.o image.o
	g++ testing.o render.o image.o -o a

image.o: image.o
	g++ -c image.cpp

render.o: render.cpp 
	g++ -c render.cpp

testing.o: testing.cpp
	g++ -c testing.cpp

clean:
	rm *.o *.exe 