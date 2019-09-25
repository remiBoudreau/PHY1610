/*
Assignment no.: 5
Filename: chem_eq_polynomial.cc
Author: Jean-Michel Boudreau
Description: Sovles for roots of cubic function that represents the chemical
kinetics of system 2X + Y = 2Z. Contained in one file as opposed to multiple 
(i.e. modular) as there is program is very simple and easy to understand and
therefore does not require modularization.
*/

// Include Directives
#include <stdio.h>
#include <gsl/gsl_poly.h>

// Driver
int main (void) {
// Declare variables
  double k1, k2, x0, y0, z0, c1, c2, a, b, c, x, y, z;
  gsl_complex csol[3];
   /* coefficients of 0 = k1*x^3 - (c1*k1 + 2*k2)*x^2    + 4*c2*k2*x     - 2*k2*c2*c2
                       = x^3    - (c1*k1 + 2*k2)/k1*x^2 + 4*c2*k2/k1*x  - 2*k2*c2*c2/k1
                       = x^3 + a*x^2 + b*x + c 
  */
  // Initialize rate constants
  k1 = 1;
  k2 = 0.7;
  // Initialize initial concentrations
  x0 = 0.5;
  y0 = 1;
  z0 = 0;
  c1 = x0 - 2*y0;
  c2 = x0 + z0;  
  a  = -(c1*k1 + 2*k2)/k1;
  b  = 4*c2*k2/k1;
  c  = -2*k2*c2*c2/k1;
  
  // Solve for roots of cubic function
  gsl_poly_complex_solve_cubic(a, b, c, &csol[0], &csol[1], &csol[2]);
  x = GSL_REAL(csol[2]);
  y = (x - c1)/2;
  z = (c2 - x);
  
  // Display real-part of results
  printf("Equilbirium Concentrations of X, Y and Z are %g, %g, and %g\n", \
  	x, y, z);

  // Return status of program as successful
  return(0);
}