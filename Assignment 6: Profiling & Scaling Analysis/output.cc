// output.cc
// implementation of output.h
#include "output.h"
#include <iostream>

// report (currectly only the total number of ants)
int output(int t, int table_size, int** number_of_ants) {
    // report ants on a grid(currectly only the total number of ants)
    // parameters:
    //    t               the number of the time step to output (in)
    //    table_size      the gridsize in each dimension (in)
    //    number_of_ants  two-dimensional array of table_size x table_size which holds the number of ants on each grid point (in)
    // returns: number of ants
    int total_ants = 0;
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            total_ants += number_of_ants[i][j];
        }
    }
    std::cout << t+1 << " " << total_ants << std::endl;
    return total_ants;
}
