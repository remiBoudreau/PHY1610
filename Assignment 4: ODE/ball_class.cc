/*
Assignment no.: 4
Filename: ball_class.cc
Author: Jean-Michel Boudreau
Description: Creates instance of 'ball' and its members and function for ODE
integration.
*/

// Include built-in include files
#include <iostream>
#include <cmath>
#include <vector>
// Include header file
#include "ball_class.h"

// Define pi
const double pi = 3.14159265358979323846264338327950288;

// Initialize ball 
ball::ball(double m_init, double A_init, double T_init, double g_init \
	, double B_init, double C_init) {
	m = m_init;
	A = A_init;
	T = T_init;
	g = g_init;
	B = B_init;
	C = C_init;
}

// Function for ODE integration
void ball::operator()(const state &Y, state &dYdt, const double t) {
    dYdt[0] = Y[3]; // dx/dt = u
    dYdt[1] = Y[4]; // dx/dt = v
    dYdt[2] = Y[5]; // dx/dt = w
    dYdt[3] = 0;	// du/dt = 0
    dYdt[4] = 0;	// dv/dt = 0
    dYdt[5] = (B*exp(-C*((Y[2]) - A*cos(2*pi*t/T))) - g)/m; // dw/dt
}