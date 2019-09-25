# Makefile for chem_eq_ODE

# Define MACROS
CXX = g++
CXXSTD = -std=c++11
LDLIBS=`pkg-config --cflags --libs gsl`

all: chem_eq_ODE

# Compile the chem_eq_ODE binary
chem_eq_ODE: chem_eq_ODE.o system_equations.o timestep.o
	${CXX} chem_eq_ODE.o system_equations.o timestep.o ${LDLIBS} -o chem_eq_ODE

# Compile the chem_eq_ODE object file
chem_eq_ODE.o: chem_eq_ODE.cc
	${CXX} ${CXXSTD} -c chem_eq_ODE.cc ${LDLIBS} -o chem_eq_ODE.o

# Compile the timestep object file
timestep.o: timestep.h timestep.cc
	${CXX} ${CXXSTD} -c timestep.cc ${LDLIBS} -o timestep.o

# Compile the system_equations object file
system_equations.o: rparams.h system_equations.h system_equations.cc
	${CXX} ${CXXSTD} -c system_equations.cc ${LDLIBS} -o system_equations.o

# Remove temporarily-required object files
clean:
	rm -f *.o

# Remove program
uninstall:
	rm -f chem_eq_ODE