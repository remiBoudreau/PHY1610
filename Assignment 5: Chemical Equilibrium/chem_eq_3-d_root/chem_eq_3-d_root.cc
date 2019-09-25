/*
Assignment no.: 5
Filename: chem_eq_3-d_root.cc
Author: Jean-Michel Boudreau
Description: Sovles for roots of system of function that represents the 
chemical kinetics of system 2X + Y = 2Z using GSL library's multiroot solver,
gsl_multiroot_fsolver
*/

// Include directives
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include "rparams.h"
#include "system_equations.h" 
#include "print_state.h"
#include "root_finder.h"

// Driver
int main (void) {
  // Define pointer to a newly allocated instance of a solver of type T for a 
  // system of n dimensions
  const gsl_multiroot_fsolver_type *T; 
  gsl_multiroot_fsolver *s;
  // Declare and initialize variables
  int status;
  int i, iter = 0;
  const int n = 3;
  // Define parameters and initial conditions for use inside driver and so that
  // they may be modified by user as desired
  double k1 = 1, k2 = 0.7, x0 = 0.5, y0 = 1, z0 = 0, c1 = x0 - 2*y0, c2 = x0 + z0;   
  // Define p as an rparams data struct
  struct rparams p = {k1, k2, c1, c2};
  // Define function, its dimentionality and the parameters
  gsl_multiroot_function f = {&system_f, n, &p};
  // Define initial conditions
  double x_init[3] = {x0, y0, z0};
  // Define pointer to gsl vector 'x' with 'n' number of elements
  gsl_vector *x = gsl_vector_alloc (n);
  // Set initial conditions in gsl vector 'x'
  gsl_vector_set (x, 0, x_init[0]);
  gsl_vector_set (x, 1, x_init[1]);
  gsl_vector_set (x, 2, x_init[2]);
  // Define solver T as hybrid solver 
  T = gsl_multiroot_fsolver_hybrids;
  // Define pointer to allocated instance of hybrid solver T with 3 dimensions
  s = gsl_multiroot_fsolver_alloc (T, 3);
  // Set solver s to use function f (i.e. system of equations) with intitial 
  // conditions stored in vector x
  gsl_multiroot_fsolver_set (s, &f, x);
  // Alert User program is running and the initial concentrations used for root
  // solving
  printf("GSL multiroot solver is running...\n");
  printf("The initial concentrations of X, Y and Z are %g, %g and %g\n",
    x0, y0, z0);
  // Minimize and display intermediate state of solution for each iteration of hybrid solver
  status = root_finder(iter, status, s);
  // Display end status of program to user
  printf ("status = %s\n", gsl_strerror (status));
  double xf = gsl_vector_get (s->x, 0);
  double yf = gsl_vector_get (s->x, 1);
  double zf = gsl_vector_get (s->x, 2);
  printf("Equilbirium Concentrations of X, Y and Z are %g, %g, and %g \n",
    xf, yf, zf);
  // Free memory associated with solver 's'
  gsl_multiroot_fsolver_free (s);
  // Free memory associated with vector 'x'
  gsl_vector_free (x);
  // Return status of program as successful
  return 0;
}