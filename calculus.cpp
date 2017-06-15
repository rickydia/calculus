/* Calculus.cpp
 *
 * Created by Ricky Diaz Gomez
 * rickydia@umich.edu
 *
 * Started on the 12th of June, 2017 at 12:50 PM
 * Last edited on the 13th of June, 2017 at 1:22 PM
 *
 */


#include "calculus.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>



//int main(int argc, char* argv[]){
	//if(argc == 1){
		//std::cout << "CHECK USAGE FOR SPECIFIC TYPE BY TYPING: ./calculus [d - derivative, i - integral, s - sum]" << std::endl;
		//std::cout << "PROGRAM TERMINATED." << std::endl;
	//}

	//if(std::string(argv[1]) == "d"){
		//if(argc != 4){
			//std::cout << "USAGE FOR DERIVATIVES: ./calculus d [NUMBER OF TIMES THE DERIVATIVE WILL BE TAKEN] [OBJECT OF DERIVATION]" << std::endl;
			//std::cout << "PROGRAM TERMINIATED." << std::endl;
		//}
		
		//Derivative derivative( atoi(argv[2]), argv[3] );
		
		//derivative.take_derivative();
	//}

	//if(std::string(argv[1]) == "i"){
		//if(argc != 3 && argc != 5){
			//std::cout << "USAGE FOR INTERGALS: ./calculus i (POSSIBLE BOTTOM LIMIT OF INTEGRATION) (POSSIBLE TOP LIMIT OF INTEGRATION) [OBJECT OF INTEGRATION]" << std::endl;
			//std::cout << "PROGRAM NOT YET IMPLEMENTED." << std::endl;
			//std::cout << "PROGRAM TERMINATED." << std::endl;
		//}
		
	//}

	//if(std::string(argv[1]) == "s"){
		//if(argc != 5){
			//std::cout << "USAGE FOR SUMS: ./calculus s [BOTTOM LIMIT OF SUM] [TOP LIMIT OF SUM] [OBJECT OF SUMMATION]" << std::endl;
			//std::cout << "PROGRAM NOT YET IMPLEMENTED." << std::endl;
			//std::cout << "PROGRAM TERMINATED." << std::endl;
		//}
		
	//}
	
//}

void output_for_der(int num_of_der, std::string der);

int main(){
	while(true){
		std::cout << "Please enter what you would like to do: \n" << std::endl;
		std::cout << "d - derivative" << std::endl;
		std::cout << "i - integral" << std::endl;
		std::cout << "s - sum" << std::endl;
		std::cout << "q - quit \n" << std::endl;
		std::string input;
		std::cin >> input;
		
		if(input == "q" || input == "quit"){
			break;
		}

		else if(input == "d" || input == "derivative"){
			std::cout << "Please enter the object of derivation: ";
			std::string der;
			std::cin >> der;
			
			std::cout << "Please enter the amount of times the derivative should be taken: ";
			int num_of_der = 0;
			std::cin >> num_of_der;

			Derivative derivative(num_of_der, der);
			std::string output;
			output = derivative.take_derivative();

		}
			
	}

	return 0;
}

void output_for_der(int num_of_der, std::string der, std::string output){
	if(num_of_der == 1){
		std::cout << "The 1st derivative of " << der << " is " << output << "." << std::endl;
	}

	else if(num_of_der == 2){
		std::cout << "The 2nd derivative of " << der << " is " << output << "." << std::endl;
	}

	else if(num_of_der == 3){
		std::cout << "The 3rd derivative of " << der << " is " << output << "." << std::endl;
	}

	else if(num_of_der >= 21){
		if(true){
			std::cout << "The " << num_of_der << "st derivative of " << der << " is " << output << "." << std::endl;
		}

		else if(true){
			std::cout << "The " << num_of_der << "nd derivative of " << der << " is " << output << "." << std::endl;
		}

		else if(true){
			std::cout << "The " << num_of_der << "rd derivative of " << der << " is " << output << "." << std::endl;
		}

		else{
			std::cout << "The " << num_of_der << "th derivative of " << der << " is " << output << "." << std::endl;
		}
	}

	else{
		std::cout << "The " << num_of_der << "th derivative of " << der << " is " << output << "." << std::endl;
	}
			
			
}
			





