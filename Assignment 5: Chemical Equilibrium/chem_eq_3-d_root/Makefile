# Makefile for chem_eq_3-d_root

# Define MACROS
CXX = g++
CXXSTD = -std=c++11
LDLIBS=`pkg-config --cflags --libs gsl`

all: chem_eq_3-d_root

# Compile the chem_eq_3-d_root binary
chem_eq_3-d_root: chem_eq_3-d_root.o rparams.h print_state.o \
system_equations.o root_finder.o
	${CXX} chem_eq_3-d_root.o system_equations.o print_state.o root_finder.o \
	${LDLIBS} -o chem_eq_3-d_root

# Compile chem_eq_3-d_root object file
chem_eq_3-d_root.o: chem_eq_3-d_root.cc rparams.h print_state.h \
system_equations.h root_finder.h
	${CXX} ${CXXSTD} -c chem_eq_3-d_root.cc ${LDLIBS} -o chem_eq_3-d_root.o

# Compile system_equations object file
system_equations.o: system_equations.h system_equations.cc rparams.h
	${CXX} ${CXXSTD} -c system_equations.cc ${LDLIBS} -o system_equations.o	

# Compile root_finder.o object file
root_finder.o: root_finder.h root_finder.cc print_state.o
	${CXX} ${CXXSTD} -c root_finder.cc ${LDLIBS} -o root_finder.o

# Compile print_state.o object file
print_state.o: print_state.h print_state.cc
	${CXX} ${CXXSTD} -c print_state.cc ${LDLIBS} -o print_state.o

# Remove temporarily-required object files
clean:
	rm -f *.o

# Remove program
uninstall:
	rm -f chem_eq_3-d_root