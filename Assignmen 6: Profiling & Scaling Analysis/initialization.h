// initialization.h
// Initializes ants randomly on a two-dimensional square grid, and assigns a crawl direction in rsadians at each grid point
#ifndef INITIALIZATIONH
#define INITIALIZATIONH

// initialize number_of_ants grid with total_ants randomly placed ants. Also sets the crawl direction
// Parameters:
//   total_ants       the number of ants to place on the table (in)
//   table_size       the number of points on the grid in each direction (in) 
//   number_of_ants   two-dimensional array that will hold the number of ants on each grid point
//   crawl_direction  two-dimensional array that will hold the angle (in radian) of the direction that ants ar each grid point will move in.
//   seed             random seed
// All arrays must have been allocated already.
void initialize(int total_ants, int table_size, int** number_of_ants, float** crawl_direction, unsigned long seed);

#endif
