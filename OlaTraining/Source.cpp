#include <iostream>
#include "Calculator.h"


int calculatorResult{ 0 };
void calculator();

int main() {
	std::cout << "Welcome to calc1 \n";


	calculator();

	return 0;
}



void calculator() {
	Calculator calculator;

	int count = 0;
	int moreCalculations{ 0 };

	while (moreCalculations != 2) {
		calculator.calculateResult(count);        // put the answer of the current calculation in a variable to be reused
		calculator.displayAnswer();	//display the calculation result

		std::cout << "Would you like to do more calculation? Press 1 for Yes and 2 for No";
		std::cin >> moreCalculations;
		while (moreCalculations != 1 && moreCalculations != 2) {
			std::cout << "Please specify between 1 and 2; 1 = Yes, 2 = No";
		}

		count += 1;
	}
	std::cout << "Thank you for using Calc1";

}