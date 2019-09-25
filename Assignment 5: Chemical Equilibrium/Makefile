# Makefile for Chemical Equilirbium Solving

# Define MACROS
CXX = g++
CXXSTD = -std=c++11
LDLIBS=`pkg-config --cflags --libs gsl`

# Define phony targets
.PHONY: all clean uninstall

# Compile all chem_eq programs
all: 
	$(MAKE) -C ./chem_eq_polynomial all
	$(MAKE) -C ./chem_eq_3-d_root all
	$(MAKE) -C ./chem_eq_ODE all

# Remove temporarily needed .o files
clean:
	$(MAKE) -C ./chem_eq_3-d_root clean
	$(MAKE) -C ./chem_eq_ODE clean

uninstall:
	$(MAKE) -C ./chem_eq_polynomial uninstall
	$(MAKE) -C ./chem_eq_3-d_root uninstall
	$(MAKE) -C ./chem_eq_ODE uninstall