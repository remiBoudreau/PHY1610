// ants.cc
// simulate ants walking off a table
#include "initialization.h"
#include "timestep.h"
#include "output.h"
#include <cstdlib>
#include <iostream>
#include "allocation.h"

// driver program
int main(int argc, char** argv)
{
    // simulation parameters
    int table_size = 400;    // size of the table
    int time_steps = 1000;   // number of steps to take
    int total_ants = 100; // initial number of ants
    // allocate two-dim arrays (including a work array)
    int** number_of_ants = alloc_array_int(table_size,table_size);
    int** new_number_of_ants = alloc_array_int(table_size,table_size);
    float** crawl_direction = alloc_array_float(table_size, table_size);
    unsigned long seed = (argc>1)?atoi(argv[1]):13;
    // set the ants on the table
    initialize(total_ants, table_size, number_of_ants, crawl_direction, seed);
    // report
    output(-1, table_size, number_of_ants);
    // run time steps
    for (int t = 0; t < time_steps; t++) {
        timestep(table_size, number_of_ants, crawl_direction, new_number_of_ants);
        if (output(t, table_size, number_of_ants) == 0)
           break;
    }
    // release memory
    dealloc_array_int(number_of_ants);
    dealloc_array_int(new_number_of_ants);
    dealloc_array_float(crawl_direction);
    return 0;
}             
