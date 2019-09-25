// output.h

#ifndef OUTPUTH
#define OUTPUTH

// report ants on a grid(currectly only the total number of ants)
// parameters:
//    t               the number of the time step to output (in)
//    table_size      the gridsize in each dimension (in)
//    number_of_ants  two-dimensional array of table_size x table_size which holds the number of ants on each grid point (in)
// returns the number of ants
int output(int t, int table_size, int** number_of_ants);

#endif
