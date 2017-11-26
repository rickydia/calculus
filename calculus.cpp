/* calculus.cpp
 *
 * Created by Ricky Diaz Gomez
 * rickydia@umich.edu
 *
 * Started on the 12th of June, 2017 at 12:50 PM
 * Last edited on the 26th of November, 2017 at 12:00 AM
 *
 */


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "calculusHelper.h"


int main(){
	// Runs until user enters "q" or "quit"
	std::cout << "This program takes the derivative of polynomials. \n\n";
	while(true){
		// Prompts user for action
		std::string input;
		std::cout << "Please enter what you would like to do: \n\n";
		std::cout << "\t\t\td - derivative\n";
		std::cout << "\t\t\th - help\n";
		std::cout << "\t\t\tq - quit \n\n";
		std::cout << "Decision: ";
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
			//std::cin.ignore(1000, '\n');
			std::cin >> std::ws;
			getline(std::cin, der);
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
			derivative.output_for_calc(num_of_der, orig_der, output, "derivative");
		}

		else if(input == "h" || input == "help"){
			std::cout << "\n\nHello! This program is designed to take the derivative of any polynomial you choose to input.\n";
			std::cout << "The correct format for entering a derivative is:\n\n";
			std::cout << "\t\t[coefficient][variable]^[exponent]\n\n";
			std::cout << "NOTE:\n";
			std::cout << "\tIf the coefficient you desire to input is 1, you can leave it empty.\n";
			std::cout << "\tIf there is no variable, then the derivative is 0, but you can check anyways by leaving the variable location empty.\n";
			std::cout << "\tIf there is no exponent, you can leave out the '^' and leave the exponent location empty.\n\n\n";
		}
			
	}

	return 0;
}


