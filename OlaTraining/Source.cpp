#include <iostream>
#include "Calculator.h"
#include "Bank account.h"


int calculatorResult{ 0 };
void calculator();
void bankAccount();

int main() {
	
	bankAccount();

	calculator();

	return 0;
}



void calculator() {
	std::cout << "Welcome to calc1 \n";
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


void bankAccount() {
	int accountNumber;
	float balance;
	int numberOfTransactions{ 0 };    // total number of transactions made
 	float transactionPrice{ 0 }; // the price of each transaction
	float transactionTotal{ 0 }; 

	//get the account number and balance from the user
	std::cout << "Welcome to banking 101 \n";
	std::cout << "To proceed, please specify the following \n";
	std::cout << "6 digit bank account number: ";
	std::cin >> accountNumber;
	std::cout << "Account balance: ";
	std::cin >> balance;
	   	 

	BankAccount _bankAccount(accountNumber, balance);  // create a bank account object 



	//------updating the bank account with transactions made-----//

	std::cout << "How many transactions would you like to process? \n";
	std::cin >> numberOfTransactions;

	for (int i{ 1 }; i <= numberOfTransactions; ++i) {
		std::cout << "Please enter transaction number " << i << "\n";
		std::cin >> transactionPrice;
		transactionTotal += transactionPrice;

	}

	_bankAccount.updateBankBalance(transactionTotal);
	//-----------------------------------------------------------//


}

void bankAccountMenu() {
	//display bank balance
	_bankAccount.displayBalance();

	//get and display monthly spend
	std::cout << "Monthly spend is: " << _bankAccount.getMonthlySpent() << "\n";

}



}


////Need to be able to select which function they want to use (Menu)
////