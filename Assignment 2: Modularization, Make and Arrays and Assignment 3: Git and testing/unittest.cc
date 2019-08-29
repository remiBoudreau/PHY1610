/*
Assignment no.: 3
Filename: unittest.cc
Author: Jean-Michel Boudreau
Description: Tests the 'ants_timestep' module by propogating one time step forward and 
checking whether there are more ants after 1 step
*/

// Include directives
#include <iostream>
#include <cmath>
#include "ants_timestep.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE unittest
#include <boost/test/unit_test.hpp>

// Boost Test
BOOST_AUTO_TEST_CASE(step_test)
{
	const double pi = 3.14159265358979323846264338327950288; // define pi
	int table_size = 70; // number of rows/columns in square array
	int ants_ini = 100; // number of ants prior to timestep
	int ants_fin = 0;
    //  Create 2d dynamic array 
    int **new_number_of_ants = new int *[table_size];
    for (int i = 0; i < table_size; i++) {			  
        new_number_of_ants[i] = new int[table_size];
    } 
	//  Create 2d dynamic array 
    float **crawl_direction = new float *[table_size];
    for (int i = 0; i < table_size; i++) {
        crawl_direction[i] = new float[table_size];
    }
    //  Create 2d dynamic array
    int **number_of_ants = new int *[table_size];
    for (int i = 0; i < table_size; i++) {
        number_of_ants[i] = new int[table_size];
    }
    // Assign 0 to each element of array; no ants on the table
    for (int i = 0;i < table_size; i++) {
        for (int j = 0;j < table_size; j++) {
            number_of_ants[i][j] = 0;
        }
    }
    // Add ants randomly to table    
    int n = 0;
    srand(13);
    while (n < ants_ini) {
        int i = rand() % table_size;
        int j = rand() % table_size;
        number_of_ants[i][j]++;
        n++;
    }
    // Assign direction field
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            crawl_direction[i][j] = pi*(sin((2*pi*(i+j))/(4*table_size))+1);
        }
    }
    // Propogate 1 time step; function of module being tested
    ants_at_t(table_size, new_number_of_ants, crawl_direction, \
            number_of_ants);
    // count ants
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            ants_fin += number_of_ants[i][j];
        }
     }
     // Check if there are more ants after the timestep relative to before it
     BOOST_CHECK(ants_ini >= ants_fin);
}
