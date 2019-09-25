/*
Assignment no.:	5
Filename: system_equations.h
Author: Jean-Michel Boudreau
Description: Declare the system of ODE's as a function as requierd by GSL
library's odeiv2 
*/

// Preprocessor Guards
#ifndef SYSTEM_EQUATIONS_H
#define SYSTEM_EQUATIONS_H

// Declare the function to initialize the system of ODE's
int system(double t, const double y[], double f[], void *params);

// Terminate directive ifndef
#endif