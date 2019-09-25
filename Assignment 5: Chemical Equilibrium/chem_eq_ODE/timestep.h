/*
Assignment no.: 5
Filename: timestep.h
Author: Jean-Michel Boudreau
Description: Declares function for single timestep for the system of ODE's
*/

// Preprocessor Guard
#ifndef ODETIMESTEP_H
#define ODETIMESTEP_H

 // Declare function for timesteps until error reaches tolerance in X, Y and Z and display reults to user
double  timestep(gsl_odeiv2_driver * d, double y[], double tolerance);

// Terminate directive ifndef
#endif