/*
Assignment no.: 5
Filename: timestep.cc
Author: Jean-Michel Boudreau
Description: Function for timesteps. Continues until error reaches tolerance in
X, Y and Z and display reults to user
*/

// Include directives
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <cmath>
#include "timestep.h"

// Function for single timestep.
double timestep(gsl_odeiv2_driver * d, double y[], double tolerance)
{ 
  // Set timestep counter
  int i = 0;
  // Initial and final time
  double t = 0.0, t1 = 100.0, ti;
  // Declare variables
  double y_prior[3] = {0.0, 0.0, 0.0}, error_x, error_y, error_z;
  // Perform timesteps until error reaches tolerance
  do { 
    // Increase timestep by 1
    i++;
    // Current time step
    ti = i * t1 / 100.0;
    int status = gsl_odeiv2_driver_apply (d, &t, ti, y);
    // Stop if error has occured
    if (status != GSL_SUCCESS) {
      printf ("error, return value=%d\n", status);
    break;
    }
    // Get absolute errors in X, Y and Z
    error_x = std::abs((y[0] - y_prior[0])/y[0]);
    error_y = std::abs((y[1] - y_prior[1])/y[1]);
    error_z = std::abs((y[2] - y_prior[2])/y[2]);
    // Get values for next iteration
    y_prior[0] = y[0];
    y_prior[1] = y[1];
    y_prior[2] = y[2];
  } while(error_x > tolerance or error_y > tolerance or error_z > tolerance);
  // Display equilbrium concentrations to user after errors have converged to tolerance
  printf("The equilibrium concentrations converged to X = %.6f, Y = %.6f, and Z = %.6f, after %g units of time with a tolerance of %g\n", 
          y[0], y[1], y[2], ti, tolerance);
}