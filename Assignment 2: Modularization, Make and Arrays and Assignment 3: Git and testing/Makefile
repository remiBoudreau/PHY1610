# Makefile for Modularization, Make and Arrays/Git and Testing

# Define MACROS
CXX = g++
CXXSTD = -std=c++11
LDFLAGS=
LDLIBS=

# Define phony targets
.PHONY: all clean integratedtest

all: ants

# Check outputs betweeen modular and nonmodular code
integratedtest: ants ants_original
	./ants > ants.out; \
	./ants_original > ants_original.out; \
	diff -s ants.out ants_original.out > ants_integratedtest.out

# Check output of single timestep to ensure ants are not spontaneously
# generated following a timestep
unittest: ants_timestep.o
	${CXX} ${CXXSTD} -g -c  unittest.cc
	${CXX} ${CXXSTD} -g -o  unittest unittest.o ants_timestep.o \
	-lboost_unit_test_framework
	./unittest --log_level=all

# Compile ants binary from modular code
ants: ants_main.o ants_init.o ants_timestep.o ants_update.o
	${CXX} ${CXXSTD} ants_main.o ants_init.o ants_timestep.o ants_update.o -o ants 

# Compile ants_main object file
ants_main.o: ants_main.cc ants_init.h ants_timestep.h ants_update.h
	${CXX} ${CXXSTD} -c ants_main.cc -o ants_main.o

# compile ants_init object file
ants_init.o: ants_init.cc ants_init.h
	${CXX} ${CXXSTD} -c ants_init.cc -o ants_init.o

# Compile ants_timestep object file
ants_timestep.o: ants_timestep.cc ants_timestep.h
	${CXX} ${CXXSTD} -c ants_timestep.cc -o ants_timestep.o

# Compile ants_update object file
ants_update.o: ants_update.cc ants_update.h
	${CXX} ${CXXSTD} -c ants_update.cc -o ants_update.o

# Compile ants binary from nonmodular code
ants_original: ants_original.cc
		${CXX} ${CXXSTD} ants_original.cc -o ants_original 

# Remove files for compiling a fresh version of ants
clean: 
	rm -f *.o *.out ants ants_original unittest
