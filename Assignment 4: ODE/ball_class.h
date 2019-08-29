/* 
Assignment no.: 4
Filename: ball_class.h
Author: Jean-Michel Boudreau
Description: Defines class 'ball' and its and access of its members.
*/

// Preprocessor guard
#ifndef BALL_CLASS_H
#define BALL_CLASS_H

// The type of container used to hold the state vector and the derivative of
// the state vector w.r.t. time
typedef std::vector<double> state;

// Define 'ball' class
class ball{
// Private access for data members (private by default)
	double m;
	double A;
	double T;
	double g;
	double B;
	double C;

// Public access for member functions
public:
	// Declare function for creating object of this class & assigning values
	ball(double, double, double, double, double, double);
	// Declare function for timestep using boost library's RK5 scheme 
	void operator()(const state &Y, state &dYdt, const double t);
};

// Terminate directive ifndef
#endif