#include <iostream>
#include "Calculator.h"

int getNumber() {
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


char getArithmeticOperator() {
	char arithmeticOperator;
	std::cin >> arithmeticOperator;

	return arithmeticOperator;
}


char checkArithmeticOperator() {                    //function that validates the operator entered
	std::cout << "Enter operator";
	char A{ getArithmeticOperator() };						// get the operator and store it in variable A
	switch (A) {											// check if the entered operator matches + - * / and if not ask them to try again (using recursion)
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
		checkArithmeticOperator();
	}

	return A; // return the operator being used
}


int calculateResult(int result, int count) {                                         //function calculates the result of mathematic calculation
	int arithmeticResult;						// the result of the calculation
	char checkArithmeticOperator();				// declaration of arithmetic operator
	int getNumber();							// declaration of getnumber


	int inputA;									//first number
	char arithmeticOperator;					//operator
	int inputB;									//second number

	if (count == 0) {				
		//check if this is the first time a calculation is being done
		//calculates the equation of the first 2 numbers

		inputA = getNumber();											
		arithmeticOperator = checkArithmeticOperator();
		inputB = getNumber() ;

		if (arithmeticOperator == '+') {                    //checks what the arithmetic operator entered is and calculates accordingly 
			arithmeticResult = (inputA + inputB);
		}
		else if (arithmeticOperator == '-') {
			arithmeticResult = (inputA - inputB);
		}
		else if (arithmeticOperator == '*') {
			arithmeticResult = (inputA * inputB);
		}
		else if (arithmeticOperator == '/') {
			arithmeticResult = (inputA / inputB);
		}
	}
	else {

		arithmeticOperator = checkArithmeticOperator();				//else if this isnt the first calculation, only take the next number
		inputB =  getNumber() ;

		if (arithmeticOperator == '+') {                    //checks what the arithmetic operator entered is and calculates accordingly 
			arithmeticResult = (result + inputB);
		}
		else if (arithmeticOperator == '-') {
			arithmeticResult = (result - inputB);
		}
		else if (arithmeticOperator == '*') {
			arithmeticResult = (result * inputB);
		}
		else if (arithmeticOperator == '/') {
			arithmeticResult = (result / inputB);
		}
	}

	return arithmeticResult;                            //return the result of the calculation
}


void displayAnswer(int answer) {

	std::cout << "Your answer is: " << answer << '\n';

}