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
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <cassert>



class Derivative{
public:
	Derivative(int num_of_der_in, std::string der_in)
		:num_of_der(num_of_der_in), der(der_in) {}
		

	// EFFECTS: Takes the derivative of the object in question once
	std::string take_derivative_once(){
		std::string new_der;

		// Counts the amount of +/- that aren't used in exponents
		int add_sub_counter = 0;
		std::vector<int> loc_of_plus_or_minus;
		for(unsigned int i = 0; i < der.length(); ++i){
			std::string comp = std::string(&der[i]);
			// If a + or - is used outside of exponents
			if((comp == "+" || comp == "-") && (std::string(&der[i-1]) != "^" || (std::string(&der[i-1]) != "(" && std::string(&der[i-2]) != "^"))){
				++add_sub_counter; 
				loc_of_plus_or_minus.push_back(i);
			}
		}


		// Ensures that the deivative is done in case that a + or - is never inputted
		if(loc_of_plus_or_minus.size() == 0){ loc_of_plus_or_minus.push_back(0); }

		// For the inner for loop in order to give the last +/- a chance to run
		loc_of_plus_or_minus.push_back(loc_of_plus_or_minus.size());

		// Takes the derivative, seperating terms by the + and -
		for(unsigned int i = 0; i < loc_of_plus_or_minus.size() - 1; ++i){
			std::string term_der;
			std::string variable;
			bool is_variable = false;
			double coefficient = 0;
			double exponent = 0;
			int j = loc_of_plus_or_minus[i];

			// Travels through the term itself through every item
			for(int end = loc_of_plus_or_minus[i+1]; (end - j) > 0; ++j){ 
				std::string comp = std::string(&der[j]);
	
				if(comp == "^"){
					++j;
					if(std::string(&der[j]) == "("){
						int length_of_paren = 0;
						int plus_minus_counter_exp = 0;
						while(std::string(&der[j]) != ")"){
							++length_of_paren;
							++j;
						}

						char* ptr = &der[j - length_of_paren];
						
						exponent += strtod(ptr, &ptr);
						for(int index = 0; index < plus_minus_counter_exp; ++index){
							char* temp_ptr1 = ptr;
							char* temp_ptr2 = ptr;
							++temp_ptr1;
							++++temp_ptr2;

							if(*ptr == ' ' && temp_ptr1[0] == '-' && temp_ptr2[0] == ' '){
								++++ptr;
								exponent -= strtod(ptr, &ptr);
							}
							else{
								exponent += strtod(ptr, &ptr);
							}
						}
					}
					else{
						exponent = strtod(&der[j], NULL);
					}	
				}
				
				else if(isdigit(comp[0]) || comp == "." || comp == "-" || comp == "+"){
					char* ptr;
					coefficient = strtod(comp.c_str(), &ptr);
					int length_of_dub = ptr - &der[j] - 1;
					j += length_of_dub;
				}
				
				else if(isalpha(der[j])){
					variable = comp;
					is_variable = true;
				}

			}	
			if(is_variable){
				double new_coef = coefficient * exponent;
				double new_exp = exponent - 1;
				std::string new_coef_str = std::to_string(new_coef);
				std::string new_exp_str = std::to_string(new_exp);
				term_der = new_coef_str + variable + "^(" + new_exp_str + ") + "; 
				new_der += term_der;
			}
		}
		return new_der;
	}
	
	

	// EFFECTS: Takes the amount of derivatives as required
	std::string take_derivative(){
		std::string output;
		for(int i = 0; i < num_of_der; ++i){
			output = take_derivative();
		}
		return output;
	}



private:
	int num_of_der;
	std::string der;

};




class Integral{
public:
	Integral(int num_of_inte_in, std::string inte_in)
		:num_of_inte(num_of_inte_in), inte(inte_in) {}

	std::string take_integral(){
		
		
		std::string poop = "FEATURE NOT YET ADDED";
		return poop;
	}


private:
	int num_of_inte;
	std::string inte;

};







// REQUIRES: The number of times the derivative or intergral was done, the object of derivation or integration, the correct
//			 derivative or integral, and whether it was a derivative or integral being done
// EFFECTS:  Function for the output of a dericative, mostly designed in order to get the correct suffix
void output_for_calc(int num, std::string thing_being_calced, std::string output, std::string type_of_calc){
	std::cout << "\n";

	// After 20, the last digit determins the suffix
	// NOTE: DOES NOT ACCOUNT FOR CORRECT SUFFIXES AFTER 110
	if(num > 20){
		if(num % 10 == 1){
			std::cout << "The " << num << "st " << type_of_calc << " of " << thing_being_calced << " is " << output << ".\n";
		}

		else if(num % 10 == 2){
			std::cout << "The " << num << "nd " << type_of_calc << " of " << thing_being_calced << " is " << output << ".\n";
		}

		else if(num % 10 == 3){
			std::cout << "The " << num << "rd " << type_of_calc << " of " << thing_being_calced << " is " << output << ".\n";
		}

		else{
			std::cout << "The " << num << "th " << type_of_calc << " of " << thing_being_calced << " is " << output << ".\n";
		}
	}

	else if(num == 1){
		std::cout << "The 1st " << type_of_calc << " of " << thing_being_calced << " is " << output << ".\n";
	}

	else if(num == 2){
		std::cout << "The 2nd " << type_of_calc << " of " << thing_being_calced << " is " << output << ".\n";
	}

	else if(num == 3){
		std::cout << "The 3rd " << type_of_calc << " of " << thing_being_calced << " is " << output << ".\n";
	}

	else{
		std::cout << "The " << num << "th " << type_of_calc << " of " << thing_being_calced << " is " << output << ".\n";
	}
			
	std::cout << "\n\n";
}
			






#endif
