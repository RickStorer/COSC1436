#include <iostream>

using namespace std;

#include <stdlib.h>

void main()
{
	int x;
	char Op;
	int y;
	int z;


	cout << "Enter a number: ";
	cin >> x;
	cout << "Select an operator: ";
	cin >> Op;
	cout << "Select another number: ";
	cin >> y;
		switch (Op)
				{
				case '+':
					x = x + y;
					break;
				case '-':
					x = x - y;
					break;
				case '*':
					x = x * y;
					break;
				case '/':
					if (y == 0)
					{
						cout << "You cannot divide by zero. Please try again." << endl;
						break;
					}
					else
						x = x / y;
					break;
				case 'C':
					Op = 'C';
					break;
				case 'c':
					Op = 'c';
					break;
				case 'x':
					Op = 'x';
					break;
				case 'X':
					Op = 'X';
					break;
				default:
					cout << "You have entered an incorrect operator. Please try again." << endl;
				}  
	cout << x << endl;




	system("pause");
}