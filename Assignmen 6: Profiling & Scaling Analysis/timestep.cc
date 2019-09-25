// timestep.cc
// implementation of timestep.h 
#include "timestep.h"
#include <cmath>

void timestep(int table_size, int** number_of_ants, float** crawl_direction, int** new_number_of_ants)
{
    // Take a single time step of ants on a table
    // Paramaters
    //   table_size          size of the (square) table (in)
    //   number_of_ants      two-dimensional array containing the number of ants on the table on each point in a grid (inout)
    //   crawl_direction     two-dimensional array with the direction (in radians) in which the ants will move in each grid point (in)
    //   new_number_of_ants  internal work array, same size and type as number_of_ants (out, but not to be used)
    // All arrays must already have been allocated.  Upon return, the number_of_ants will have been updated 

    // ants move onto new_number_of_ants
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            new_number_of_ants[i][j] = 0.0;
        }
    }
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            int di = 1.9*sin(crawl_direction[i][j]);
            int dj = 1.9*cos(crawl_direction[i][j]);
            int i2 = i + di;
            int j2 = j + dj;
            // put only on new table if not off table
            if (i2>=0 and i2<table_size and j2>=0 and j2<table_size) {
                new_number_of_ants[i2][j2] += number_of_ants[i][j];
            } 
        }
    }
    // update
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            number_of_ants[i][j] = new_number_of_ants[i][j];
        }
    }
}
