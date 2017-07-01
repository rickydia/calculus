#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

int main(){
	//int number = 862;
	//std::cout << number % 10 << std::endl;
	//std::vector<int> poop{0,1,2,3};





	//std::cout << poop.at(0) << std::endl;
	//std::cout << poop.at(1) << std::endl;
	//std::cout << poop.at(2) << std::endl;
	//std::cout << poop.at(3) << std::endl;









	char temp[] = " +26267 - 2727 )";
	char* temp_ptr = &temp[0];
	//++temp_pt
	//std::cout << "temp_ptr:" << *temp_ptr << std::endl;
	//char paren = '(';
	//if(*temp_ptr == paren){
		//std::cout << "enters\n";
		//++temp_ptr;
	//}

	double temp_dub = strtod(temp_ptr, &temp_ptr);
	std::cout << "temp_ptr:" << *temp_ptr << std::endl;
	char* temp_ptr2 = temp_ptr;
	std::cout << "temp_ptr2:" << temp_ptr2 << std::endl;
	++temp_ptr2;
	std::cout << "temp_ptr2:" << temp_ptr2 << std::endl;
	char* temp_ptr3 = temp_ptr2;
	++temp_ptr3;
	if(*temp_ptr == ' ' && temp_ptr2[0] == '-' && temp_ptr3[0] == ' '){
		++temp_ptr;
		++temp_ptr;
		std::cout << "enters\n";
		temp_dub -= strtod(temp_ptr, &temp_ptr);
	}
	else{
		temp_dub += strtod(temp_ptr, &temp_ptr);
	}
	std::cout << "temp string:" << temp << "     temp_dub:" << temp_dub << std::endl;


	std::cout << "Size of double: " << temp_ptr - &temp[0] << std::endl;
	int size_of = temp_ptr - &temp[0];
	char* ptr = &temp[0];
	if((ptr + size_of) == temp_ptr){
		std::cout << "YELLLLLLL" << std::endl;
	}



	int i = 0;
	int plus_minus_counter_exp = 0;
	int length_of_paren = 0;
	while(temp[i] != ')'){
		if(temp[i] == '+' || temp[i] == '-'){
			++plus_minus_counter_exp;
		}
		++length_of_paren;
		++i;
	}
	std::cout << "plus_minus_counter_exp: " << plus_minus_counter_exp << std::endl;
	std::cout << "length_of_paren: " << length_of_paren << std::endl;

	temp_ptr = &temp[0];

	double exponent = 0;
	exponent += strtod(temp_ptr, &temp_ptr);
	std::cout << "temp_ptr:" << *temp_ptr << std::endl;
	for(int index = 0; index < plus_minus_counter_exp; ++index){
		char* temp_ptr1 = temp_ptr;
		temp_ptr2 = temp_ptr;
		++temp_ptr1;
		++++temp_ptr2;
		
		std::cout << "enters" << std::endl;

		if(*temp_ptr == ' ' && temp_ptr1[0] == '-' && temp_ptr2[0] == ' '){
			std::cout << "enters if" << std::endl;
			++++temp_ptr;
			exponent -= strtod(temp_ptr, &temp_ptr);
		}
		else{
		std::cout << "enters else" << std::endl;
			exponent += strtod(temp_ptr, &temp_ptr);
		}
	}
	
	std::cout << "exponent: " << exponent << std::endl;




	/* add strings
	 * check if letter (variable)
	 * when getting the coefficient and exponent, remember to add to j so that it doesn't rechange the coef/exp
	 * see what to do about times and divide
	 * make a cout where if its like x^2 * y^3 it won't work
	 * 
	 * 
	 * digit, character, ^, (/ & *)???
	 * 
	 * exponent / and *
	 * 
	 * 
	 */
}
