#include "functions.h"
#include <iostream>
using namespace std;

// Add, Subtract, Multiply, Divide
double Add (double a, double b)
{
	return a + b;
}

double Sub (double a, double b)
{
	return a - b;
}

double Mult (double a, double b)
{
	return a * b;
}

double Div (double a, double b)
{
	return a / b;
}

bool IsOpValid(const char Operators [], char & Operator)
{
	int i;
	do {
		cout << "Enter an operator (+, -, *, /, C (Clear), X (Exit)): ";
		cin >> Operator;
		for (i = 0;i <= 8;i++)
		{
			if (Operators[i] == Operator)
				return true;
			else;
			if (Operators[i] == '\0')
			{
				cout << "You have entered and invalid operator. Please try again." << endl;
				break;
			}
			else;
		}
	} while (true);
}