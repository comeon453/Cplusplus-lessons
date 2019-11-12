#pragma once
#include <iostream>

class BankAccount {

public:
	BankAccount(int accountNumber, float balance); //constructor
	void updateBankBalance(float);    // update the bank balance with how much has been spent
	int getBankBalance();
	int getMonthlySpent();
	void displayBalance();



private:
	int _bankAccountNumber;
	float _balance;
	int _totalMonthlySpend{ 0 };

};


