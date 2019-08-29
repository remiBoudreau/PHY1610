/*
Assignment no.: 2/3
Filename: ants_update.cc
Author: Jean-Michel Boudreau
Description: Counts the number of ants remaining on the table and returns value to driver
*/

// Include directives
#include <iostream>
#include "ants_update.h"

// Count number of ants reminaing on table
void total_at_t(int **number_of_ants, int table_size, int t) {
    // Clear total number of ants variable
    int total = 0;

    // Sum number of ants at each gridpoint
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            total += number_of_ants[i][j];
        }
     }

    // Report total number of ants at time 't'
    std::cout << t + 1 << " " << total << std::endl;
    
}
