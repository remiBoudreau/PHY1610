/*
Assignment no.:	1  
Filename: driver.cc
Author: Jean-Michel Boudreau
Description: Calculates two values, 'x' and 'y', for each value in array 't' 
specified by all doubles in the range from t_ini to t_fin in steps of t_stp.
*/

#include <iostream>
#include <cmath>
#include "functions.h"

using namespace std;

int main() {
	// Initialize parameters
	int t_ini =-5; 
	int t_fin = 5; 
	double t_stp = 0.005;
	const int t_len = (t_fin - t_ini)/t_stp + 1;

	// Create dynamically allocated array
	double *t = new double [t_len];
	double *x = new double [t_len];
	double *y = new double [t_len];
	double s;

	// Calculate t, x and y for each time point and print values seperated
	// by spaces
	for (int i = 0; i < t_len; i++) {
		t[i] = i*t_stp - 5; 
		x[i] = f(t[i]);
		y[i] = g(t[i]);
		std::cout << t[i] << " " << x[i] << " " << y[i] << std::endl;
	}

	// Deallocate memory for arrays
	delete [] t;
	delete [] x;
	delete [] y;
	return 0;
}
