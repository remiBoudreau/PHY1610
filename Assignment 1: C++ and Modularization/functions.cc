/*
Assignment no.:	1  
Filename: functions.cc
Author: Jean-Michel Boudreau
Description: Defines functions to be used by driver.
*/

#include <cmath>
#include "functions.h"

// Define function 'f'
double f(double time) {
	return (sin(2.0*time)/(1.0 + time*time));
}

// Define function 'g'
double g(double time) {
	return (cos(3.0*time)/(1.0 + time*time));
}
