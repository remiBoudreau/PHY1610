/*
Assignment no.: 5
Filename: root_finder.h
Author: Jean-Michel Boudreau
Description: Declares the function used in root_finder.cc
*/

// Preprocessor Guard
#ifndef ROOT_FINDER_H
#define ROOT_FINDER_H

// Declare function for determining roots of multidimensional equation.
int root_finder(int iter, int status, gsl_multiroot_fsolver * s);

// Terminate directive ifndef
#endif
