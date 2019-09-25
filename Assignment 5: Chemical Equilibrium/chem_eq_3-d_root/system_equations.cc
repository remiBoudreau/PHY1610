/*
Assignment no.: 5
Filename: system_equations.cc
Author: Jean-Michel Boudreau
Description: Function for defining system of equations required by 
gsl_multiroot_function from GSL library
*/

// Include Directives
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include "rparams.h"
#include "system_equations.h"

// Function for defining system of equations
int system_f (const gsl_vector * x, void *params, gsl_vector * f) {
  // Define parameters from data structure for use w/ GSL hybrid solver
  double k1 = ((struct rparams *) params)->k1;
  double k2 = ((struct rparams *) params)->k2;
  double c1 = ((struct rparams *) params)->c1;
  double c2 = ((struct rparams *) params)->c2;
  // Define initial conditions for use w/ GSL hybrid sovler
  const double x0 = gsl_vector_get (x, 0);
  const double y0 = gsl_vector_get (x, 1);
  const double z0 = gsl_vector_get (x, 2);
  // Define system of equations with initial conditions
  const double q0 = x0 - 2*y0 - c1;
  const double q1 = x0 + z0 - c2;
  const double q2 = k1*x0*x0*y0 - k2*z0*z0;
  // Set system of equations to vector of equations 'f'
  gsl_vector_set (f, 0, q0);
  gsl_vector_set (f, 1, q1);
  gsl_vector_set (f, 2, q2);
  // Return that it was successful to status
  return GSL_SUCCESS;
}