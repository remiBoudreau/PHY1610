# Makefile for Modularization, Make and Arrays
# Makefile for C++ and Modularization

# Define MACROS
CXX = g++
CXXSTD = -std=c++11
LDFLAGS=
LDLIBS=

# Define phony targets
.PHONY: all clean

all: ants

# Compile ants binary
ants: ants_main.o ants_init.o ants_timestep.o ants_update.o
	${CXX} ${CXXSTD} ants_main.o ants_init.o ants_timestep.o ants_update.o -o ants 

# Compile ants_main object file
ants_main.o: ants_main.cc ants.h
	${CXX} ${CXXSTD} -c ants_main.cc -o ants_main.o

# compile ants_init object file
ants_init.o: ants_init.cc ants.h
	${CXX} ${CXXSTD} -c ants_init.cc -o ants_init.o

# Compile ants_timestep object file
ants_timestep.o: 
	${CXX} ${CXXSTD} -c ants_timestep.cc -o ants_timestep.o

# Compile ants_update object file
ants_update.o:
	${CXX} ${CXXSTD} -c ants_update.cc -o ants_update.o

# Remove files for compiling a fresh version of ants
clean: 
	rm *.o ants
