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


// Function for the output of a dericative
void output_for_der(int num_of_der, std::string der, std::string output);


int main(){
	// Runs until user enters "q" or "quit"
	while(true){
		// Prompts user for action
		std::string input;
		std::cout << "Please enter what you would like to do: \n" << std::endl;
		std::cout << "         d - derivative" << std::endl;
		std::cout << "         i - integral" << std::endl;
		std::cout << "         q - quit \n" << std::endl;
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
			output_for_der(num_of_der, der, output);
		}

		// If user wants to take the integral
		else if(input == "i" || input == "integral"){
			std::string inte;
			std::cout << "Please enter the object of integration: ";
			std::cin >> inte;

			int num_of_inte = 0;
			std::cout << "Please enter the amount of times the integral should be taken: ";
			std::cin >> num_of_inte;

		}
			
	}

	return 0;
}



// Function for the output of a dericative, mostly designed to get the correct suffix
void output_for_der(int num_of_der, std::string der, std::string output){
	std::cout << std::endl;

	// After 20, the last digit determins the suffix
	// NOTE: DOES NOT ACCOUNT FOR CORRECT SUFFIXES AFTER 110
	if(num_of_der > 20){
		if(num_of_der % 10 == 1){
			std::cout << "The " << num_of_der << "st derivative of " << der << " is " << output << "." << std::endl;
		}

		else if(num_of_der % 10 == 2){
			std::cout << "The " << num_of_der << "nd derivative of " << der << " is " << output << "." << std::endl;
		}

		else if(num_of_der % 10 == 3){
			std::cout << "The " << num_of_der << "rd derivative of " << der << " is " << output << "." << std::endl;
		}

		else{
			std::cout << "The " << num_of_der << "th derivative of " << der << " is " << output << "." << std::endl;
		}
	}

	else if(num_of_der == 1){
		std::cout << "The 1st derivative of " << der << " is " << output << "." << std::endl;
	}

	else if(num_of_der == 2){
		std::cout << "The 2nd derivative of " << der << " is " << output << "." << std::endl;
	}

	else if(num_of_der == 3){
		std::cout << "The 3rd derivative of " << der << " is " << output << "." << std::endl;
	}

	else{
		std::cout << "The " << num_of_der << "th derivative of " << der << " is " << output << "." << std::endl;
	}
			
	std::cout << std::endl;
	std::cout << std::endl;
}
			





