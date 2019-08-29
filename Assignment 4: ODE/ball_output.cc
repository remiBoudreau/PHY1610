/*
Assignment no.: 4
Filename: ball_output.cc
Author: Jean-Michel Boudreau
Description: Defines function for outputting current time and state of system
*/

// Include built-in include files
#include <iostream>
#include <vector>
// Include header file
#include "ball_output.h"

// Define function for output time and state of system at current timestep
void output(double t, state Y) {
	// Output time and state of system at current timestep to user
	std::cout << t; // output time point
	for (auto i = Y.begin(); i != Y.end(); ++i) {
		std::cout << " " << *i; // output state to user
	}
	std::cout << std::endl; // new line
}