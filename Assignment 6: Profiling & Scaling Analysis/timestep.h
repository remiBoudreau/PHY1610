// timestep.h
#ifndef TIMESTEPH
#define TIMESTEPH

// Take a single time step of ants on a table
// Paramaters
//   table_size          size of the (square) table (in)
//   number_of_ants      two-dimensional array containing the number of ants on the table on each point in a grid (inout)
//   crawl_direction     two-dimensional array with the direction (in radians) in which the ants will move in each grid point (in)
//   new_number_of_ants  internal work array, same size and type as number_of_ants (out, but not to be used)
// All arrays must already have been allocated.  Upon return, the number_of_ants will have been updated 
void timestep(int table_size, int** number_of_ants, float** crawl_direction, int** new_number_of_ants);

#endif
