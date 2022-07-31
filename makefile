SRC := main.cpp functions.cpp
SRC_TEST := tests.cpp functions.cpp
OBJ := $(SRC:.cpp=.o)
OBJ_TEST := $(SRC_TEST:.cpp=.o)

CXX := gcc
CXXFLAGS := -g -lm 

TARGET := equation
TARGET_TEST := test

all: out run

run:
	./$(TARGET_TEST)
	./$(TARGET)

out: $(OBJ) $(OBJ_TEST)
	$(CC) $(OBJ) -o $(TARGET) $(CXXFLAGS)
	$(CC) $(OBJ_TEST) -o $(TARGET_TEST) $(CXXFLAGS)

%.o: %.cpp
	gcc -c $< -o $@ $(CXXFLAGS)

clean: 
	rm -f $(OBJ) $(OBJ_TEST)

