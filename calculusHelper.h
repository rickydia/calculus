#pragma once

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
#include <stdio.h>
#include <cstdlib>
#include <cstdio>
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

std::string Derivative::take_derivative_once(){
		std::string new_der;

		// Counts the amount of plus/minus signs that aren't used in exponents
		int add_sub_counter = 0;
		std::vector<int> loc_of_plus_or_minus;
		for(unsigned int i = 0; i < der.length(); ++i){
			std::string comp_first(1, der[i]);

			std::string comp_minus_one;
			// In case of accessing items out of scope, try and catch
			try{
				der.at(i-1);
				comp_minus_one.assign(1, der[i-1]); 
			}
			catch(const std::out_of_range& oor){}

			std::string comp_minus_two;
			try{
				der.at(i-2);
				comp_minus_two.assign(1, der[i-2]);
			}
			catch(const std::out_of_range& oor){}

			std::string comp_minus_three; 
			try{
				der.at(i-3);
				comp_minus_three.assign(1, der[i-3]);
			}
			catch(const std::out_of_range& oor){}

			// If a plus/minus sign is used outside of exponents
			if((comp_first == "+" || comp_first == "-") && !(comp_minus_one == "^" || (comp_minus_one == "(" && (comp_minus_two == "^" || (comp_minus_two == " " && comp_minus_three == "^"))))){
				++add_sub_counter; 
				loc_of_plus_or_minus.push_back(i);
			}
		}


		// If in a multiple term derivative, tests to see if the very first term doesn't have a plus/minus sign, so it wouldn't have shown up
		std::string test(1, der[0]);
		if(test != "-" && test != "+"){ 
			std::vector<int>::iterator it = loc_of_plus_or_minus.begin();
			loc_of_plus_or_minus.insert(it, 0); 
		}

		// Ensures that the deivative is done in case that a + or - is never inputted
		if(loc_of_plus_or_minus.size() == 0){ loc_of_plus_or_minus.push_back(0); }
		

		// For the inner for loop in order to give the last +/- a chance to run
		loc_of_plus_or_minus.push_back(der.size());


		// Takes the derivative, seperating terms by the plus/minus signs
		for(unsigned int i = 0; i < loc_of_plus_or_minus.size() - 1; ++i){
			std::string term_der;
			std::string variable;
			bool is_variable = false;
			bool already_visited_coef = false;
			double coefficient = 1;
			double exponent = 1;
			int j = loc_of_plus_or_minus[i];

			// Travels through the term itself through every item
			for(int end = loc_of_plus_or_minus[i+1]; (end - j) >= 0; ++j){ 
				// comp is a string with the remainder of der indexed at j
				std::string comp = std::string(&der[j]);
				// comp_first is the very first character of comp
				std::string comp_first(1, comp[0]);
				
				if(comp_first == "^"){
					++j;

					// comp_second is only the second character of comp
					std::string comp_second(1, der[j]);
					// If the exponent is within parentheses, enters
					if(comp_second == "("){
						int length_of_paren = 0;
						int plus_minus_counter_exp = 0;
						std::string comp_third(1, der[j]);
						// Iterates until it finds the second parenthesis
						while(comp_third != ")"){
							// Counts how many plus/minus signs are within the parenthesis
							if(comp_third == "+" || comp_third == "-"){
								++plus_minus_counter_exp;
							}
							++length_of_paren;
							++j;
							comp_third = der[j];
						}

						// Creates a pointer to the first character after the first parenthesis
						char* ptr = &der[j - length_of_paren + 1];
						// Gets the exponent
						double temp_exp = strtod(ptr, &ptr);
						
						// Initially multiplies the exponent(1) by the first double strtod retrieves
						exponent *= temp_exp;
						// Iterates the amount of plus/minus signs were within the exponent parentheses
						for(int index = 0; index < plus_minus_counter_exp; ++index){
							char* temp_ptr1 = ptr;
							char* temp_ptr2 = ptr;
							++temp_ptr1;
							++++temp_ptr2;

							// In order to catch ^(a + b) or ^(a - b), which shouldn't ever happen due to the removing
							// of white space when reading in der in the .cpp file
							if(*ptr == ' ' && temp_ptr1[0] == '-' && temp_ptr2[0] == ' '){
								++++ptr;
								exponent -= strtod(ptr, &ptr);
							}
							// Calculates the final exponent
							else{
								exponent += strtod(ptr, &ptr);
							}
						}
					}
					// Otherwise, no parentheses, so simply retrieves the next number to be the exponent
					else{
						std::string expStr;
						if(der[j] == '.'){
							expStr += der[j];
							++j;
						}
						while( (isdigit(der[j]) || der[j] == '.') && (end - j ) >= 0 ){
							expStr += der[j];
							++j;
						}
						exponent = stod(expStr);
					}	
				}
				
				// If comp_first is a number, ., -, or + sign, enters
				else if((isdigit(comp[0]) || comp_first == "." || comp_first == "-" || comp_first == "+") && already_visited_coef == false){
					// Gets the coefficient
					coefficient = strtod(comp.c_str(), NULL);
					// Made in case of something like the der of -x because strtod returns 0 instead of a -1
					if(coefficient == 0 && comp_first == "-"){
						std::string comp_second(1, comp[1]);
						// In case if someone tries something like -0
						if(!(comp_first == "-" && comp_second == "0")){
							coefficient = -1;
						}
					}
					// So that it won't enter again within this term
					already_visited_coef = true;
				}
				
				// If comp_first is a alphabetic character
				else if(isalpha(comp[0])){
					variable = comp_first;
					is_variable = true;
				}

			}	
			// If there was a variable within the term, enters
			if(is_variable){
				// Depending on whether the new_der already has a term or not, changes the way term_der is set up
				// in order to make the output more appealing

				// If exponent is 1, removes the variable
				if(exponent == 1){
					if(new_der == ""){
						term_der = std::to_string(coefficient);
						new_der += term_der;
					}
					else if(coefficient < 0){
						term_der = " - " + std::to_string(coefficient * (-1));
						new_der += term_der;
					}
					else{
						term_der = " + " + std::to_string(coefficient);
					}
				}
				// If exponent is 0 for whatever reason, derivative is 0
				else if(exponent == 0){
					if(new_der == ""){
						term_der = "0";
						new_der += term_der;
					}
					else{
						term_der = " + 0";
						new_der += term_der;
					}
				}
				// Other it's a normal term, sets up term_der and adds it to the new_der
				else{
					double new_coef = coefficient * exponent;
					double new_exp = exponent - 1;
					std::string new_coef_str = std::to_string(new_coef);
					std::string new_exp_str = std::to_string(new_exp);
					if(new_der == ""){
						term_der = new_coef_str + variable + "^(" + new_exp_str + ")";
					}
					else if(new_coef < 0){
						new_coef *= -1;
						new_coef_str = std::to_string(new_coef);
						term_der = " - " + new_coef_str + variable + "^(" + new_exp_str + ")";
					}
					else{
						term_der = " + " + new_coef_str + variable + "^(" + new_exp_str + ")";
					}

					new_der += term_der;
				}
			}
			// If there wasn't a variable, derivative is 0, enters
			else{
				if(new_der == ""){
					new_der += "0";
				}
				else{
					term_der = " + 0";
					new_der += term_der;
				}
			}
		}
		return new_der;

}


std::string Derivative::take_derivative(){
	std::string output;
		for(int i = 0; i < num_of_der; ++i){
			output = take_derivative_once();
			der = output;
		}
		return output;
}


void Derivative::output_for_calc(int num, std::string thing_being_calced, std::string output, std::string type_of_calc){
	std::cout << '\n';

	// After 20, the last digit determins the suffix
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

