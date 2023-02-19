CC=g++
CFLAGS=-Wall -Wextra
TARGET=a
TEST_TARGET=test

CPP_FILES=image.cpp main.cpp ray.cpp render.cpp
TEST_CPP_FILES=testing.cpp

OBJECTS=$(CPP_FILES:.cpp=.o)
TEST_OBJECTS=$(TEST_CPP_FILES:.cpp=.o)

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

$(TEST_TARGET): $(TEST_OBJECTS) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJECTS) $(OBJECTS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: run clean 

run: $(TARGET)
	./$(TARGET) > image.ppm 

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJECTS) $(TEST_OBJECTS) image.ppm
