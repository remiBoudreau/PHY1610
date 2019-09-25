/*
Assignment no.:	5
Filename: system_equations.h
Author: Jean-Michel Boudreau
Description: Declares the functions used in system_equations.cc
*/

// Preprocessor guard
#ifndef SYSTEM_EQUATIONS_H
#define SYSTEM_EQUATIONS_H

// Declare function for defining system of equations
int system_f (const gsl_vector * x, void *params, gsl_vector * f);

// Terminate directive ifndef
#endif
