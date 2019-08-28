# Makefile for C++ and Modularization

# Define MACROS
CXX=g++
CXXFLAGS= -std=c++11
LDFLAGS=
LDLIBS=

# Define phony targets
.PHONY: all clean

all: lissajous

# Compile lissajous binary
lissajous: main_driver.o functions.o
	${CXX} ${CXXFLAGS} main_driver.o functions.o -o lissajous 

# Compile main_driver object file
main_driver.o: main_driver.cc
	${CXX} ${CXXFLAGS} -c main_driver.cc -o main_driver.o

# Compile functions object file
functions.o: functions.cc functions.h
	${CXX} ${CXXFLAGS} -c functions.cc -o functions.o

# To compile a fresh version of lissajous
clean:
	rm -f *.o lissajous lissajous.txt
