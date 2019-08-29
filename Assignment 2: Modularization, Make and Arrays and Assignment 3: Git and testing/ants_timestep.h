/*
Assignment no.:	2/3
Filename: ants_timestep.h
Author: Jean-Michel Boudreau
Description: Declares the functions used in ants_timestep.cc
*/

// Preprocessor guard
#ifndef ANTS_TIMESTEP_H
#define ANTS_TIMESTEP_H

// Delcare function for counting reminaing ants on table at every time point
void ants_at_t(int table_size, int **new_number_of_ants, \
	float **crawl_direction, int **number_of_ants);

// Terminate directive ifndef
#endif