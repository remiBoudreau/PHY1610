/* ants_init.cc
Functions for initializing the simulation
*/
#include <iostream>
#include <cmath>
#include "ants.h"

const double pi = 3.14159265358979323846264338327950288;

// initialize a direction field; where do the ants go at each point?
float **crawl_direction_init(int table_size) {
    //  create 2d dynamic array 
    float **crawl_direction_temp = new float *[table_size];
    for (int i = 0; i < table_size; i++) {
        crawl_direction_temp[i] = new float[table_size];
    }

    // assign direction field
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            crawl_direction_temp[i][j] = pi*(sin((2*pi*(i+j))/(4*table_size))+1);
        }
    }
    // return the direction field
    return crawl_direction_temp;
}

// "randomly" place ants on the table
int **ants_on_table_init(int table_size, int total_ants) {
    //  create 2d dynamic array
    int **number_of_ants_temp = new int *[table_size];
    for (int i = 0; i < table_size; i++) {
        number_of_ants_temp[i] = new int[table_size];
    }

    // assign 0 to each element of array; no ants on the table
    for (int i = 0;i < table_size; i++) {
        for (int j = 0;j < table_size; j++) {
            number_of_ants_temp[i][j] = 0;
        }
    }

    // add ants randomly to table    
    int n = 0;
    srand(13);
    while (n < total_ants) {
        int i = rand() % table_size;
        int j = rand() % table_size;
        number_of_ants_temp[i][j]++;
        n++;
    }

    // return the table with ants
    return number_of_ants_temp;
}