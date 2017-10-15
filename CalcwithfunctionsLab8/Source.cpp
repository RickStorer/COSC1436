//**************************************************************************
//
// DESCRIPTION: Programming exercise eight COSC 1436.S01 – Lab 8
// CLASS: COSC 1436.S01
// AUTHOR: Roderick Storer
// DATE: Oct 2017
//
//**************************************************************************


#include <iostream>

using namespace std;

#include <stdlib.h>
#include "functions.h"

void main()
{
	int x;
	int y;
	char Oper;
	Oper = 1;

	cout << "\t\tCalculator" << endl;


	//read 1st number
	do {
		cout << "Enter a whole number: ";
		x = ReadInteger();
		cout << "You entered: " << x << endl;

		while ((Oper != 'x') || (Oper != 'X'))
		{
			//read an operator + 43, - 45, * 42, / 47, C 67, X 88, c 99, x 120
			cout << "Enter an operator (+, -, *, /, C (Clear), X (Exit)): ";
			cin >> Oper;
			if ((Oper == 'C') || (Oper == 'c') || (Oper == 'x') || (Oper == 'X') || (Oper == '+') || (Oper == '*') || (Oper == '-') || (Oper == '/'))
			{
				if ((Oper == 'x') || (Oper == 'X'))
					{
					cout << "\nYou have selected exit." << endl;
					system("pause");
					exit(0);
					}
				else
					if ((Oper == 'c') || (Oper == 'C'))
						{
						cout << "\nCleared\n" << endl;
						break;
						}
					else;

					//read 2nd number
					cout << "Enter another whole number: ";
					y = ReadInteger();
					cout << "You entered: " << y << endl;
					cout << endl;

					if (Oper == '+')
						x = Add (x, y);
					else
						if (Oper == '*')
							x = Mult (x, y);
						else
							if (Oper == '-')
								x = Sub (x, y);
							else
								if ((Oper == '/') && (y == 0))
								{
									cout << "You cannot divide by 0. Resetting.\n" << endl;
									break;
								}
								else
									if (Oper == '/')
										x = Div (x, y);
									else;
			}
			else
			{
				cout << "You have selected an invalid operator. Try again." << endl;
				continue;
			}
			cout << "Equals:" << x << endl;
		}

	} while ((Oper != 'x') || (Oper != 'X'));




	system("pause");
}