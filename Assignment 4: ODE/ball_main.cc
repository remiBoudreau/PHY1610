/* 
Assignment no.: 4
Filename: ball_main.cc
Author: Jean-Michel Boudreau
Description: This program solves a 6-Dimensional ODE for the motion of a ball 
bouncing on a table via a Runge-Kutta 5 scheme with a relative accuracy of 1e-5
implemented using the boost library, with the following equations to describe 
the state of the system:
 			 
 	dx/dt = u
 	dy/dt = v
 	dz/dt = z
 	du/dt = 0
 	dv/dt = 0
 	dw/dt = (B*exp(-C*((Y[2]) - A*cos(2*pi*t/T))) - g)/m;

 where the position in cartesian coordinates is (x, y, z) and the
 speed in the x-, y- and z- directions are u, v and w, respectively.
*/

// Include built-in include files
#include <iostream>
#include <vector>
// Include boost library's odeint for RK5 scheme and functionality for ODE int. 
#include <boost/numeric/odeint.hpp>
// Include header files
#include "ball_class.h"
#include "ball_output.h"

// Use namespace of boost library for ODE integration
using namespace boost::numeric::odeint;

int main() {
	// Parameters for EOM. Doubles used in case parameters require values that 
	// are not of type int
	const double m = 1; 	// mass
	const double A = 0.25;	// amplitude of vertical motion
	const double T = 2;		// period of vertical motion
	const double g = 10;	// gravitational force
	const double B = 10;	// parameters for the force exterted on ball at  
	const double C = 2;		// vertical position 'z' 

	// Parameters for time step. Doubles used in case parameters require values
	// that are not of type int
	const double t_ini = 0;		// absolute initial time
	const double t_fin = 30;	// absolute final time
	const int t_pts = 1000;		// number of time points
	double t_ini_step;			// initial time for each step
	double t_fin_step;			// initial time for each step
	double dt = (t_fin - t_ini)/(t_pts - 1); // step size, t=0 included, -1

	// Define integration scheme as a 5th order Runge-Kutta method with 4th 
	// order error estimation and coefficients introduced by Cash and Karp,
	// with relative accuracy of 1e-5
	typedef runge_kutta_cash_karp54<state> RK5_stepper;
	double abs_err = 1e-5, rel_err = 1e-5;

	// Initial conditions for position (x, y, z) and velocity (u, v, w)
	state Y(6);	// state vector 'Y'
	Y[0] = 0.0;	// 'x'
	Y[1] = 0.0;	// 'y'
	Y[2] = 10.0;// 'z'
	Y[3] = 1.0; // 'u'
	Y[4] = 0.0; // 'v'
	Y[5] = 0.0; // 'w'

	// Create an instance of class ball, 'some_ball' using init. parameters
	ball some_ball(m, A, T, g, B, C);

	// Label columns of output file
	std::cout << "t x y z  u v w" << std::endl; // output state to user
	
	// Output initial time and state of system to user
	output(t_ini, Y);

	// Propogate system forward in time
	for (double i = 0; i < t_pts - 1; i++) {
		// initial and final times for this step
		t_ini_step = t_ini + i*dt;
		t_fin_step = t_ini + (i + 1)*dt;
		// Integrate the system of ODE's via RK5 scheme with accracy defined above
		integrate_adaptive(make_controlled<RK5_stepper> (abs_err, rel_err), some_ball, Y, t_ini_step, t_fin_step, dt); 
		// Output current time and state of system to user
		output(t_fin_step, Y);
	}
	// Return status of program as successful
	return 0;
}