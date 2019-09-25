/*
Assignment no.:	5
Filename: print_state.cc
Author: Jean-Michel Boudreau
Description: Functions for displaying roots as determined by GSL's
gsl_multiroot_fsolver function during each iteration
*/

// Include directives
#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include "print_state.h"
#include "rparams.h"

// Function for displaying intermediate state of solution
int print_state (int iter, const gsl_multiroot_fsolver * s) {
	printf ("iter = %3d X = % .6f Y = % .6f Z = % .6f \n",
          iter,
          gsl_vector_get (s->x, 0), 
          gsl_vector_get (s->x, 1),
          gsl_vector_get (s->x, 2));
}