#include <iostream>
#include "Calculator.h"


int calculatorResult{ 0 };
void calculator();

int main() {

	calculator();

	return 0;
}



void calculator() {
	int count = 0;
	int moreCalculations{ 0 };

	while (moreCalculations != 2) {
		calculatorResult = (calculateResult(calculatorResult, count));        // put the answer of the current calculation in a variable to be reused
		displayAnswer(calculatorResult);	//display the calculation result

		std::cout << "Would you like to do more calculation? Press 1 for Yes and 2 for No";
		std::cin >> moreCalculations;
		count += 1;
	}
	std::cout << "Thank you for using Calc1";

}