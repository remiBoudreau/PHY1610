/*
Assignment no.: 4
Filename: ball_output.h
Author: Jean-Michel Boudreau
Description: Declares function for outputting current time and state of system.
*/

// Preprocessor guard
#ifndef BALL_OUTPUT_H
#define BALL_OUTPUT_H

// The type of container used to hold the state vector and the derivative of
// the state vector w.r.t. time
typedef std::vector<double> state;

// Define function for output time and state of system at current timestep
void output(double t_fin_step, state Y);

// Terminate directive ifndef
#endif