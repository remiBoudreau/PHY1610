# Makefile for the modularized ants code
CXX=g++
CXXFLAGS=-O1 -g -pg -gstabs
LDFLAGS=-g -pg -gstabs
LDLIBS=

.PHONY: all clean integratedtest clearingtime

all: integratedtest

# original
ants-orig.o: ants-orig.cc
	${CXX} -c ${CXXFLAGS} -o ants-orig.o ants-orig.cc
ants-orig: ants-orig.o
	${CXX} ${LDFLAGS} -o ants-orig ants-orig.o ${LDLIBS}

# modularized
ants.o: ants.cc timestep.h output.h initialization.h allocation.h
	${CXX} -c ${CXXFLAGS} -o ants.o ants.cc
timestep.o: timestep.cc timestep.h
	${CXX} -c ${CXXFLAGS} -o timestep.o timestep.cc
output.o: output.cc output.h
	${CXX} -c ${CXXFLAGS} -o output.o output.cc
initialization.o: initialization.cc initialization.h
	${CXX} -c ${CXXFLAGS} -o initialization.o initialization.cc
allocation.o: allocation.cc allocation.h
	${CXX} -c ${CXXFLAGS} -o allocation.o allocation.cc

ants: ants.o timestep.o output.o initialization.o allocation.o
	${CXX} ${LDFLAGS} -o ants ants.o timestep.o output.o initialization.o allocation.o ${LDLIBS}

#  to start clean and fresh
clean:
	rm -f ants.o ants-orig.o timestep.o output.o initialization.o allocation.o

# check if modularized code is same as unmodularized code by
# compariong their output
integratedtest: ants-orig.out ants.out
	@diff ants-orig.out ants.out && echo "Integrated test PASSED"
ants-orig.out: ants-orig
	./ants-orig > ants-orig.out
ants.out: ants
	./ants > ants.out

