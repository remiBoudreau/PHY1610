/*
Assignment no.: 5
Filename: root_finder.cc
Author: Jean-Michel Boudreau
Description: Function for determining the roots of a multidimensional equation.
Uses GSL's gsl_multiroot_fsolver_iterate
*/

// Include directives
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include "root_finder.h"
#include "print_state.h"

// Function for carrying out the root finding
int root_finder(int iter, int status, gsl_multiroot_fsolver * s) {
  // Display intermediate state of solution for each iteration of hybrid solver
  do {
      iter++;
      // Perform single iteration of solver hybrid solver
      status = gsl_multiroot_fsolver_iterate (s);
      // Display solution at current iteration
      print_state(iter, s);
      // Check if solver is stuck
      if (status)
        break;
      // Test sum of reisual values against absolute error;
      // returns GSL_CONTINUE if condition not achieved
      // (i.e. reiterates loop)
      status = gsl_multiroot_test_residual (s->f, 1e-7);
    }
  // Continue loop until sum of residual values is below threshold
  // or after 1000 iterations.
  while (status == GSL_CONTINUE && iter < 1000);
  // Return status to driver
  return(status);
}
  