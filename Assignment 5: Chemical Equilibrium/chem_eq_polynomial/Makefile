# Makefile for chem_eq_polynomial

# Define MACROS
CXX = g++
CXXSTD = -std=c++11
LDLIBS=`pkg-config --cflags --libs gsl`

# Define phony targets
.PHONY: all clean uninstall

all: chem_eq_polynomial

# Compile the chem_eq_polynomial binary
chem_eq_polynomial: chem_eq_polynomial.cc
	${CXX} chem_eq_polynomial.cc ${LDLIBS} -o chem_eq_polynomial

# Remove program
uninstall:
	rm -f *o chem_eq_polynomial

