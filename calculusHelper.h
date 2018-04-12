#ifndef CALCULUSHELPER_H
#define CALCULUSHELPER_H

/* calculusHelper.h
 *
 * Created by Ricky Diaz Gomez
 * rickydia@umich.edu
 *
 * Started on the 12th of June, 2017 at 12:50 PM
 * Last edited on the 26th of November, 2017 at 12:00 AM
 *
 */

#include <iostream>
#include <string>
#include <vector>



class Derivative{
public:
	Derivative(int num_of_der_in, std::string der_in)
		:num_of_der(num_of_der_in), der(der_in) {}


	// EFFECTS: Takes the amount of derivatives as required
	std::string take_derivative();


	// REQUIRES: The number of times the derivative was done, the object of derivation, the correct
	//			 derivative, and whether it was a derivative being done(able to be adapted if I later
	//			 choose to add integrals to my program
	// EFFECTS:  Function for the output, mostly designed in order to get the correct suffix
	// NOTE:     DOES NOT ACCOUNT FOR CORRECT SUFFIXES AFTER 110 DERIVATIVES
	void output_for_calc(int num, std::string thing_being_calced, std::string output, std::string type_of_calc);


private:
	int num_of_der;
	std::string der;

	// EFFECTS: Takes the derivative of the object in question once
	std::string take_derivative_once();
};

#endif
