/*
Assignment no.:	2/3
Filename: ants_init.h
Author: Jean-Michel Boudreau
Description: Declares the functions used in ants_init.cc
*/

// Preprocessor guard
#ifndef ANTS_INIT_H
#define ANTS_INIT_H

// Declare function for initializing direction field
float **crawl_direction_init(int table_size);
// Delcare function for intiializing the ants position on table
int **ants_on_table_init(int table_size, int total_ants);

// Terminate directive ifndef
#endif
