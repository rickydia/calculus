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
#include <stdio.h>
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
			std::cin.ignore(1000, '\n');
			std::getline(std::cin, der);
			std::string orig_der = der;
			for(unsigned int i = 0; i < der.length(); ++i){ 
				if(der[i] == ' '){ der.erase(i, 1); }
			}
			
			int num_of_der = 0;
			std::cout << "Please enter the amount of times the derivative should be taken: ";
			std::cin >> num_of_der;

			// Creates a derivative object
			Derivative derivative(num_of_der, der);
			std::string output;
			// Takes a derivative and stores it to "object"
			output = derivative.take_derivative();
			// Outputs the derivative to the user
			output_for_calc(num_of_der, orig_der, output, "derivative");
		}

		// If user wants to take the integral
		else if(input == "i" || input == "integral"){
			std::string inte;
			std::cout << "Please enter the object of integration: ";
			//std::cin.ignore();
			getline(std::cin, inte);
			std::string orig_inte = inte;
			for(unsigned int i = 0; i < inte.length(); ++i){ 
				if(inte[i] == ' '){ inte.erase(i, 1); }
			}

			int num_of_inte = 0;
			std::cout << "Please enter the amount of times the integral should be taken: ";
			std::cin >> num_of_inte;

			// Creates a integral object
			Integral integral(num_of_inte, inte);
			std::string output;
			// Takes the integral and stores it to "object"
			output = integral.take_integral();
			// Outputs the integral to the user
			output_for_calc(num_of_inte, orig_inte, output, "integral");
		}
			
	}

	return 0;
}


