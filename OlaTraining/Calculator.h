#pragma once
#include <iostream>


class Calculator {

public:
	int getNumber();
	char getArithmeticOperator();
	void calculateResult( int );
	void displayAnswer( );

private:
	int result{ 0 };

};