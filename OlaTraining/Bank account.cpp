#include <iostream>
#include "Bank account.h"

BankAccount::BankAccount(int accountNumber, float balance)   // constructor - gets the account balance and number from the user and assigns them
{
	_bankAccountNumber = accountNumber;
	_balance = balance;
}

void BankAccount::updateBankBalance(float spent) // update the account balance with how much spent 
{
	_balance = _balance - spent;
	_totalMonthlySpend = spent;
}

int BankAccount::getBankBalance() //gets account balance
{
	return _balance;
}

int BankAccount::getMonthlySpent() //gets account balance
{
	return _totalMonthlySpend;
}

void BankAccount::displayBalance()
{
	if (_balance < 0) {
		std::cout << "You have overspent, please deposit to avoid charges!" << "\n";
	}


	std::cout << "Your balance is £" << _balance << "\n";

}



