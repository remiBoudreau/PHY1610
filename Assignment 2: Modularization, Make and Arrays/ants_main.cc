/*
Assignment no.:	2
Filename: ants_main.cc
Author: Jean-Michel Boudreau
Description: Simulates ants walking on a table. The direction in which they 
walk depends on where they are on the table, and they can fall of the edge. 
The program prints the number of ants left on the table after every time step.
*/

// Include directives
#include <iostream>
#include "ants.h"

// Driver
int main() {
    // Ants walk on a table
    int table_size = 70; // number of rows/columns in square array 
    int time_steps = 100; // number of time steps with time step = 1
    int total_ants = 10000; // initial number of ants
    int **new_number_of_ants = new int *[table_size];
    for (int i = 0; i < table_size; i++) {
        new_number_of_ants[i] = new int[table_size];
    }

    // Randomly place ants on table with a direction for each point
    float **crawl_direction = crawl_direction_init(table_size);
    int **number_of_ants = ants_on_table_init(table_size, total_ants);

    // Report total number of ants initially
    std::cout << 0 << " " << total_ants << std::endl;

    // Propogate time
    for (int i = 0; i < time_steps; i++) {
        // Update the number of ants on table at time 't'
        ants_at_t(table_size, new_number_of_ants, crawl_direction, \
            number_of_ants);
        total_at_t(number_of_ants, table_size, i);
    }

    // Deallocate dynamic arrays
    for (int i = 0; i < table_size; i++) {
        delete[] crawl_direction[i]; 
        delete[] number_of_ants[i]; 
        delete[] new_number_of_ants[i];
    }   
    
    delete [] crawl_direction;
    delete [] number_of_ants;
    delete[] new_number_of_ants;
    
    // Return status of program as successful
    return 0;
}             
