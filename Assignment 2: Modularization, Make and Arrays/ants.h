/*
Assignment no.:	2 
Filename: ants.h
Author: Jean-Michel Boudreau
Description: Declares the functions for simulating ants on a table
*/

// Preprocessor guard
#ifndef ANTS_H
#define ANTS_H

// Declare function for initializing direction field
float **crawl_direction_init(int table_size);
// Delcare function for intiializing the ants position on table
int **ants_on_table_init(int table_size, int total_ants);
// Delcare function for counting reminaing ants on table at every time point
void ants_at_t(int table_size, int **new_number_of_ants, \
	float **crawl_direction, int **number_of_ants);
// Delcare function for counting ants at every time point
void total_at_t(int **number_of_ants, int table_size, int t);

// Terminate directive ifndef
#endif