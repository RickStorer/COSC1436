#include <iostream>

using namespace std;

#include <stdlib.h>
#include "Functions.h"

void main()
{
	int NumToSort;
	int i;
	int ArrayToSort[20];


	cout << "\t\tInteger Sorter" << endl;
	cout << "How many integers would you like to have sorted? The max is 20: ";
	NumToSort = ReadInteger();

	//Filling the array
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
	cout << "The numbers to be sorted are: ";
	for (i = 0; i < NumToSort; i++)
		cout << (i + 1) << ":" << ArrayToSort[i] << ", ";
	cout << "\n";


	system("pause");
}