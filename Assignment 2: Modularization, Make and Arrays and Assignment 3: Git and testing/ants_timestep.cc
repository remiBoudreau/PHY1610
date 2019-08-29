/*
Assignment no.: 2/3
Filename: ants_timestep.cc
Author: Jean-Michel Boudreau
Description: Functions for time propogation and reporting total number of ants
left on table
*/

// Include directives
#include <cmath>
#include "ants_timestep.h"

// Calculate reminaing ants on table
void ants_at_t(int table_size, int **new_number_of_ants, float \
**crawl_direction, int **number_of_ants) {

	// Clear number of ants at time 't'
	for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            	new_number_of_ants[i][j] = 0;
        }
    } 

    // Determine ants at each gridpoint on table after timestep
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
    	    int di = 1.9*sin(crawl_direction[i][j]);
            int dj = 1.9*cos(crawl_direction[i][j]);
            int i2 = i + di;
            int j2 = j + dj;
            // Place ants on new table only if ant is within bounds of table
            if (i2 >= 0 and i2 < table_size and j2 >= 0 and j2 < table_size) {
                new_number_of_ants[i2][j2] += number_of_ants[i][j];
            } 
        }
    }

    // Update the number of ants at each gridpoint on table
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            number_of_ants[i][j] = new_number_of_ants[i][j];
        }
    }
}
