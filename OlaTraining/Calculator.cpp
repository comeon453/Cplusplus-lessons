#include <iostream>
#include "Calculator.h"

/*testing github*/

int Calculator::getNumber() {
	int num;

	std::cout << "Insert your number";
	std::cin >> num;

	while (std::cin.fail()) {                //check if input has failed - i.e. doesnt match the variable type
		std::cout << "Invalid input, please enter a number" << std::endl;
		std::cin.clear();										//clears the stream of the invalid entries we have					  	
		std::cin.ignore(2, '\n');								//ignore the next 'n' newlines				
		
		std::cin >> num;						
	}

	return num;
}


char Calculator::getArithmeticOperator() {
	char arithmeticOperator;
	std::cout << "Enter operator";
	std::cin >> arithmeticOperator;

	switch (arithmeticOperator) {											// check if the entered operator matches + - * / and if not ask them to try again (using recursion)
	case '+':
		break;
	case '-':
		break;
	case '*':
		break;
	case '/':
		break;
	default:
		std::cout << "Please select a valid arithmetic operator i.e. +, -, * or /";
		getArithmeticOperator();
	}


	return arithmeticOperator;
}




void Calculator::calculateResult( int count) {                                         //function calculates the result of mathematic calculation
	
	int inputA;									//first number
	char arithmeticOperator;					//operator
	int inputB;									//second number

	if (count == 0) {				
		//check if this is the first time a calculation is being done
		//calculates the equation of the first 2 numbers

		inputA = getNumber();											
		arithmeticOperator = getArithmeticOperator();
		inputB = getNumber() ;

		if (arithmeticOperator == '+') {                    //checks what the arithmetic operator entered is and calculates accordingly 
			result = (inputA + inputB);
		}
		else if (arithmeticOperator == '-') {
			result = (inputA - inputB);
		}
		else if (arithmeticOperator == '*') {
			result = (inputA * inputB);
		}
		else if (arithmeticOperator == '/') {
			result = (inputA / inputB);
		}
	}
	else {

		arithmeticOperator = getArithmeticOperator();				//else if this isnt the first calculation, only take the next number
		inputB =  getNumber() ;

		if (arithmeticOperator == '+') {                    //checks what the arithmetic operator entered is and calculates accordingly 
			result = (result + inputB);
		}
		else if (arithmeticOperator == '-') {
			result = (result - inputB);
		}
		else if (arithmeticOperator == '*') {
			result = (result * inputB);
		}
		else if (arithmeticOperator == '/') {
			result = (result / inputB);
		}
	}

}


void Calculator::displayAnswer() {

	std::cout << "Your answer is: " << result << '\n';

}