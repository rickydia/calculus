/* Calculus.cpp
 *
 * Created by Ricky Diaz Gomez
 * rickydia@umich.edu
 *
 * Started on the 12th of June, 2017 at 12:50 PM
 * Last edited on the 4th of July, 2017 at 12:00 AM
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
	std::cout << "This program takes the derivative of polynomials. \n\n";
	while(true){
		// Prompts user for action
		std::string input;
		std::cout << "Please enter what you would like to do: \n\n";
		std::cout << "         d - derivative\n";
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
			// Gets the user's input
			std::cin.ignore(1000, '\n');
			std::getline(std::cin, der);
			// Saves the user input into orig_der and edits der in order to remove all white space
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
			
	}

	return 0;
}


