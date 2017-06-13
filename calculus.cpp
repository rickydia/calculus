/* Calculus.cpp
 *
 * Created by Ricky Diaz Gomez
 * rickydia@umich.edu
 *
 * Started on the 12th of June, 2017 at 12:50 PM
 * Last edited on the 12th of June, 2017 at 1:22 PM
 *
 */


#include <iostream>
#include <string>
#include <vector>
#include <cassert>



int main(int argc, char* argv[]){
	if(argc == 1){
		std::cout << "CHECK USAGE FOR SPECIFIC TYPE BY DOING: ./calculus [d - derivative, i - integral, s - sum]" << std::endl;
		std::cout << "PROGRAM TERMINATED." << std::endl;
	}

	if(std::string(argv[1]) == "d"){
		if(argc != 3 && argc != 4){
			std::cout << "USAGE FOR DERIVATIVES: ./calculus d [NUMBER OF TIMES THE DERIVATIVE WILL BE TAKEN] [OBJECT OF DERIVATION]" << std::endl;
			std::cout << "PROGRAM TERMINIATED." << std::endl;
		}

	}
	
}







