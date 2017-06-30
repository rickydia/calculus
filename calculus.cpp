/* Calculus.cpp
 *
 * Created by Ricky Diaz Gomez
 * rickydia@umich.edu
 *
 * Started on the 12th of June, 2017 at 12:50 PM
 *
 */


#include "calculus.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>


int main(){
	// Runs until user enters "q" or "quit"
	std::cout << "This program takes the derivative and integral of polynomials. \n\n";
	while(true){
		// Prompts user for action
		std::string input;
		std::cout << "Please enter what you would like to do: \n\n";
		std::cout << "         d - derivative\n";
		std::cout << "         i - integral\n";
		std::cout << "         q - quit \n\n";
		std::cin >> input;
		
		// Breaks out of loop if user wants to quit
		if(input == "q" || input == "quit"){
			break;
		}

		// If user wants to take the derivative
		else if(input == "d" || input == "derivative"){
			std::string der;
			std::cout << "Please enter the object of derivation: ";
			std::cin >> der;
			
			int num_of_der = 0;
			std::cout << "Please enter the amount of times the derivative should be taken: ";
			std::cin >> num_of_der;

			// Creates a derivative object
			Derivative derivative(num_of_der, der);
			std::string output;
			// Takes a derivative and stores it to "object"
			output = derivative.take_derivative();
			// Outputs the derivative to the user
			output_for_calc(num_of_der, der, output, "derivative");
		}

		// If user wants to take the integral
		else if(input == "i" || input == "integral"){
			std::string inte;
			std::cout << "Please enter the object of integration: ";
			std::cin >> inte;

			int num_of_inte = 0;
			std::cout << "Please enter the amount of times the integral should be taken: ";
			std::cin >> num_of_inte;

			// Creates a integral object
			Integral integral(num_of_inte, inte);
			std::string output;
			// Takes the integral and stores it to "object"
			output = integral.take_integral();
			// Outputs the integral to the user
			output_for_calc(num_of_inte, inte, output, "integral");
		}
			
	}

	return 0;
}


