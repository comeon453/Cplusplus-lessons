#pragma once
#include <iostream>

class BankAccount {

public:
	BankAccount(int accountNumber, float balance); //constructor
	void updateBankBalance(float);    // update the bank balance with how much has been spent
	float getBankBalance();
	float getMonthlySpent();
	void displayBalance();



private:
	int _bankAccountNumber;
	float _balance;
	float _totalMonthlySpend{ 0 };

};


