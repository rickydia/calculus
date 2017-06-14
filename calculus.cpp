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



int main(int argc, char* argv[]){
	if(argc == 1){
		std::cout << "CHECK USAGE FOR SPECIFIC TYPE BY TYPING: ./calculus [d - derivative, i - integral, s - sum]" << std::endl;
		std::cout << "PROGRAM TERMINATED." << std::endl;
	}

	if(std::string(argv[1]) == "d"){
		if(argc != 3 && argc != 4){
			std::cout << "USAGE FOR DERIVATIVES: ./calculus d [NUMBER OF TIMES THE DERIVATIVE WILL BE TAKEN] [OBJECT OF DERIVATION]" << std::endl;
			std::cout << "PROGRAM TERMINIATED." << std::endl;
		}
		
		Derivative derivative( atoi(argv[2]), argv[3] );
		
		derivative.take_derivative();
	}

	if(std::string(argv[1]) == "i"){
		if(argc != 3 && argc != 4){
			std::cout << "USAGE FOR INTERGALS: ./calculus i [NUMBER OF TIMES THE INTEGRAL WILL BE TAKEN] [OBJECT OF INTEGRATION]" << std::endl;
		}
		
	}
	
}







