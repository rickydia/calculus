#ifndef CALCULUS_H
#define CALCULUS_H

/* Calculus.h
 *
 * Created by Ricky Diaz Gomez
 * rickydia@umich.edu
 *
 * Started on the 12th of June, 2017 at 12:50 PM
 * Last edited on the 13th of June, 2017 at 1:22 PM
 *
 */


#include <iostream>
#include <string>
#include <vector>
#include <cassert>


class Calculus{
private:
	
};




class Derivative : Calculus{
public:
	Derivative(int num_of_der_in, std::string der_in)
		:num_of_der(num_of_der_in), der(der_in) {}
		
	std::string take_derivative(){
		//int obj_len = der;
		
		std::string poop = "POOP";
		return poop;
	}
	
	
private:
	int num_of_der;
	std::string der;

};


#endif
