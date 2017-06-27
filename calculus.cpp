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


// Functions for the output of a derivative and integral
void output_for_calc(int num, std::string thing_being_calced, std::string output, std::string type_of_calc);


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



// Function for the output of a dericative, mostly designed to get the correct suffix
void output_for_calc(int num, std::string thing_being_calced, std::string output, std::string type_of_calc){
	std::cout << std::endl;

	// After 20, the last digit determins the suffix
	// NOTE: DOES NOT ACCOUNT FOR CORRECT SUFFIXES AFTER 110
	if(num > 20){
		if(num % 10 == 1){
			std::cout << "The " << num << "st " << type_of_calc << " of " << thing_being_calced << " is " << output << "." << std::endl;
		}

		else if(num % 10 == 2){
			std::cout << "The " << num << "nd " << type_of_calc << " of " << thing_being_calced << " is " << output << "." << std::endl;
		}

		else if(num % 10 == 3){
			std::cout << "The " << num << "rd " << type_of_calc << " of " << thing_being_calced << " is " << output << "." << std::endl;
		}

		else{
			std::cout << "The " << num << "th " << type_of_calc << " of " << thing_being_calced << " is " << output << "." << std::endl;
		}
	}

	else if(num == 1){
		std::cout << "The 1st " << type_of_calc << " of " << thing_being_calced << " is " << output << "." << std::endl;
	}

	else if(num == 2){
		std::cout << "The 2nd " << type_of_calc << " of " << thing_being_calced << " is " << output << "." << std::endl;
	}

	else if(num == 3){
		std::cout << "The 3rd " << type_of_calc << " of " << thing_being_calced << " is " << output << "." << std::endl;
	}

	else{
		std::cout << "The " << num << "th " << type_of_calc << " of " << thing_being_calced << " is " << output << "." << std::endl;
	}
			
	std::cout << std::endl;
	std::cout << std::endl;
}
			
