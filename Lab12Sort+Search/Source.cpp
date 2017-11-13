#include <iostream>
#include <stdlib.h>
#include "Functions.h"

using namespace std;

void main()
{
	char **	Names = new char *[20];
	int		NumNames;

	cout << "\tName Sort and Search" << endl;
	cout << "You may enter up to 20 names to have sorted and search through. Press enter with no name entered to continue." << endl;
	EnterNames(Names);
	cout << Names[0] << endl;
	system("pause");
}