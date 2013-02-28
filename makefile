RDIR = ./
SDIR = ./src
IDIR = ./inc
LDIR = ./lib

TARGET = rain
LIBS = -lm -lGL -lGLU -lglut -lGLU -lGLEW -lglfw
CC = g++
CFLAGS = -g -Wall -ansi -pedantic-errors -I$(IDIR) 

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst $(SDIR)/%.cpp, $(SDIR)/%.o, $(wildcard $(SDIR)/*.cpp))
HEADERS = $(wildcard $(IDIR)/*.h)

all: 

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@
	
clean:
	-rm -f $(SDIR)/*.o
	
valgrind:
	valgrind -v --tool=memcheck --leak-check=full --show-reachable=yes ./$(TARGET)

