#include <iostream>
#include <stdlib.h>
#include "Functions.h"
#include "ReadInteger.h"

using namespace std;

void main()
{
	char **	pNamesArray = new char *[20];
	int		NumNames;
	bool	EndProgram;

	cout << "\tName Sort and Search" << endl;
	cout << "You may enter up to 20 names to have sorted and search through." << endl;

	do {
		cout << "How many names would you like to sort and be able to search through? ";
		NumNames = ReadInteger();
		if ((NumNames < 1) || (NumNames > 20))
			cout << "The number must be 1-20. Please try again." << endl;
		} while ((NumNames < 1) || (NumNames > 20));
	pNamesArray = new char *[NumNames];

	EnterNames(pNamesArray,NumNames);
	Sort(pNamesArray, NumNames);
	cout << "Here is your list of sorted names: ";
	DisplayNames(pNamesArray, NumNames);
	cout << "You can now search the list of names you provided. Leave the search field blank and press enter to exit." << endl;
	do {
		EndProgram = BinarySearch(pNamesArray, NumNames);
	} while (EndProgram != true);
	delete[] pNamesArray;
	cout << "You have selected to end the program." << endl;
	system("pause");
}