/*
Assignment no.: 5
Filename: chem_eq_3-d_root.cc
Author: Jean-Michel Boudreau
Description: Sovles the system of ODEs that represents the chemical
kinetics of system 2X + Y = 2Z using the GSL library's odeiv2.
*/ 

// Inlcude directives
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>
#include <cmath>
#include "rparams.h"
#include "system_equations.h"
#include "timestep.h"

// Driver
int main (void) {
  // Declare and initialize variables
  double k1 = 1.0, k2 = 0.7, y_prior[3] = {0.0, 0.0, 0.0}, error_x, error_y, error_z, tolerance = 0.01;
  struct rparams p = {k1, k2};
  // Data type for general ODE system with parameters
  gsl_odeiv2_system sys = {system, NULL, 3, &p};
  // Define 'd' as pointer to instance of a driver object
  gsl_odeiv2_driver * d = 
    gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rk8pd,
          1e-6, 1e-6, 0.0);
  // Declare and initialize intial concentrations
  double x0 = 0.5, y0 = 1, z0 = 0;
  // Vector of initial conditions
  double y[3] = {x0, y0, z0};
  // Timesteps until error reaches tolerance in X, Y and Z
  timestep(d, y, tolerance);
  // Free memory associated with pointer to driver object
  gsl_odeiv2_driver_free (d);
  // Return status of program as successful
  return 0;
}
