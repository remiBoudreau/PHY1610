# Makefile for ODE

# Define MACROS
CXX = g++
CXXSTD = -std=c++11
LDFLAGS=
LDLIBS=

all: ball_ODE

# Compile the ball_ODE binary
ball_ODE: ball_class.o ball_output.o ball_main.o
	${CXX} ${CXXSTD} ball_class.o ball_output.o ball_main.o -o ball_ODE

# Compile ball_main object file
ball_main.o: ball_main.cc
	${CXX} ${CXXSTD} -c ball_main.cc -o ball_main.o 

# Compile ball_class object file
ball_class.o: ball_class.cc ball_class.h 
	${CXX} ${CXXSTD} -c ball_class.cc -o ball_class.o 

# Compile ball_output object file
ball_output.o: ball_output.cc ball_output.h 
	${CXX} ${CXXSTD} -c ball_output.cc -o ball_output.o 

# Remove files for compiling a fresh version of ball_ODE
clean: 
	rm -f *.o ball_ODE ball_ODE.out