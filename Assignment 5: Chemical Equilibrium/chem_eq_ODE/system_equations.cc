/*
Assignment no.: 5
Filename: system_equations.cc
Author: Jean-Michel Boudreau
Description: Function for the system of ODE's as a function as requierd by GSL
library's odeiv2 
*/

// Include directives
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include "rparams.h"
#include "system_equations.h"

// Function for defining system of ODEs
int system(double t, const double y[], double f[], void *params) {
  // Avoid unused parameter warning 
  (void)(t); 
  // Define parameters from data structure rparam for use w/ GSL library's odeiv
  double k1 = ((struct rparams *) params)->k1;
  double k2 = ((struct rparams *) params)->k2;
  // Define system of ODEs
  f[0] = 2*k2*y[2]*y[2] - 2*k1*y[0]*y[0]*y[1];
  f[1] = k2*y[2]*y[2] - k1*y[0]*y[0]*y[1];
  f[2] = 2*k1*y[0]*y[0]*y[1] - 2*k2*y[2]*y[2];
  // Return that it was successful to status
  return GSL_SUCCESS;
}
