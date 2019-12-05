#include <iostream>
#include "Calculator.h"
#include "Bank account.h"


int calculatorResult{ 0 };
void calculator();
void bankAccount();
void bankAccountMenu(BankAccount& obj);
float addTransations();

int main() {
	
	bankAccount();

//	calculator();

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



	///////BANK ACCOUNT CODE/////////
	void bankAccount() {
		int accountNumber;
		float balance;
		bool MenuListener = true;														//Variable to check if user would like to exit continue with another feature


		//get the account number and balance from the user
		std::cout << "Welcome to banking 101 \n";
		std::cout << "To proceed, please specify the following \n";
		std::cout << "6 digit bank account number: ";
		std::cin >> accountNumber;
		std::cout << "Account balance: ";
		std::cin >> balance;


		BankAccount _bankAccount(accountNumber, balance);  // create a bank account object 

		while (MenuListener == true)													//checks if the above is 0, if it isnt proceed to show user the menu
		{
			bankAccountMenu(_bankAccount);      //bank account menu



			//Show menu again and perform other tasks or exit the application

			//Ask for and validate input ***
			std::cout << "Would you like to perform other tasks?\n"
				<< "Press 0 for Yes and anything else for No";

			//get input and check what it corresponds to, then assign true or false to MenuListener
			int inputV;
			std::cin >> inputV;
			if (inputV != 0 or std::cin.fail()) {							//if 0 input isnt 0 or doesnt match input type - in this case it's not an integer
				MenuListener = false;
			}

		}


	


	}

	void bankAccountMenu(BankAccount & obj) {																// NOTE: USES PASS BY REFERENCE TO UPDATE THE ORIGINAL OBJECT OTHERWHISE (BankAccount obj) WITHOUT THE & CREATES A NEW OBJECT WHICH EXPIRES AT THE END OF THE FUNCTION
		//Give user the option to choose what they want to with the bank account

		int bankMenuItem;
		std::cout << "Using the number pad, please select one of the following: \n"
			<< "1 - Add transactions \n"
			<< "2 - Get Balance \n"
			<< "3 - Get total spend \n";
		std::cin >> bankMenuItem;																													        ////get menu option selected

		switch (bankMenuItem) {
		case 1:
			obj.updateBankBalance(addTransations());																										///if 1 is selected
			break;
		case 2:
			obj.displayBalance();																																///if 2 is selected
			break;
		case 3:
			std::cout << "Total spent is: " << obj.getMonthlySpent();																							///if 3 is selected
			break;
		default:
			std::cout << "Please chose a valid menu item \n";																								//recursion, call the function again if the wrong test is entered
			bankAccountMenu(obj);
			break;
		}

	}

	float addTransations() {

		int numberOfTransactions{ 0 };    // total number of transactions made
		float transactionPrice{ 0 }; // the price of each transaction
		float transactionTotal{ 0 };

		//------updating the bank account with transactions made-----//

		std::cout << "How many transactions would you like to process? \n";
		std::cin >> numberOfTransactions;

		for (int i{ 1 }; i <= numberOfTransactions; ++i) {
			std::cout << "Please enter transaction number " << i << "\n";
			std::cin >> transactionPrice;
			transactionTotal += transactionPrice;

		}

		return transactionTotal;
	}


/////////------------ BANK ACCOUNT CODE -------- ///////////