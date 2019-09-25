// initialization.cc
// implementation of initialization.h

#include "initialization.h"
#include <cstdlib>
#include <cmath>

void initialize(int total_ants, int table_size, int** number_of_ants, float** crawl_direction, unsigned long seed)
{
    // initialize number_of_ants grid with total_ants randomly placed ants. Also sets the crawl direction
    // Parameters:
    //   total_ants       the number of ants to place on the table (in)
    //   table_size       the number of points on the grid in each direction (in) 
    //   number_of_ants   two-dimensional array that will hold the number of ants on each grid point
    //   crawl_direction  two-dimensional array that will hold the angle (in radian) of the direction that ants ar each grid point will move in.
    //   seed             random seed
    // All arrays must have been allocated already.
	const double pi = 3.14159265358979323846264338327950288;
    // initialize a direction field; where do the ants go at each point?
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            crawl_direction[i][j] = pi*(sin((2*pi*(i+j))/(4*table_size))+1);
        }
    }
    // "randomly" place ants on the table
    for (int i=0;i<table_size;i++) {
        for (int j=0;j<table_size;j++) {
            number_of_ants[i][j] = 0.0;
        }
    }
    int n = 0;
    srand(seed);
    while (n < total_ants) {
        int i = rand() % table_size;
        int j = rand() % table_size;
        number_of_ants[i][j] ++;
        n ++;
    }
}
