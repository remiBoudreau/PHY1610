# Makefile for C++_and_Modularization
CXX=g++
CXXFLAGS= -std=c++11
LDFLAGS=
LDLIBS=

.PHONY: all clean

# Compile lissajous binary
all: lissajous

lissajous:main_driver.o functions.o
	${CXX} ${CXXFLAGS} main_driver.o functions.o -o lissajous 

# Compile main_driver
main_driver.o: main_driver.cc
	${CXX} ${CXXFLAGS} -c main_driver.cc -o main_driver.o

# Compile functions
functions.o: functions.cc functions.h
	${CXX} ${CXXFLAGS} -c functions.cc -o functions.o

# To compile a fresh version of lissajous
clean:
	rm -f *.o lissajous lissajous.txt
