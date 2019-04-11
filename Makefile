FLAGS = -I ./include
##LIB    = ./lib/fmod/libfmodex64.so
LFLAGS = -lrt -lX11 -lGLU -lGL -lm #-lXrandr

all: mid19

mid19: mid19.cpp data.cpp data.h
	g++ mid19.cpp data.cpp -Wall -o test
clean:
	rm -f test
	rm -f *.o                       
