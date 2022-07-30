CXX := gcc
CXXFLAGS := -g -lm
TARGET := equation	

all:	build run

run:	
	./$(TARGET)

build: 
	$(CXX) main.cpp functions.cpp -o $(TARGET) $(CXXFLAGS)
	$(CXX) tests.cpp functions.cpp -o test $(CXXFLAGS)

