#include <iostream>

using namespace std;

#include <stdlib.h>

void main()
{
	int x;
	char Op;
	int y;
	int z;

	cout << "\t\tCalculator" << endl;
	while (true)
		{
		cout << "Enter a number: ";
		cin >> x;
			while (true)
			{
				cout << "Select an operator: ";
				cin >> Op;
				if ((Op == '+') || (Op == '-') || (Op == '*') || (Op == '/') || (Op == 'C') || (Op == 'c') || (Op == 'X') || (Op == 'x'))
				{
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
							cout << "You cannot divide by zero. Please try again.\n" << endl;
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
					if ((Op == '/') && (y == 0))
						break;
					else;
					cout << x << endl;
				}
				else
				{
					cout << "You have selected an invalid operator. Please start over.\n" << endl;
					break;
				}
			}
		}




	system("pause");
}