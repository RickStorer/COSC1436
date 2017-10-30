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
	switch (NumToSort)
	{
	case 1:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 2:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 3:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 4:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 5:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 6:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 7:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 8:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 9:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 10:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 11:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 12:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 13:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 14:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 15:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 16:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 17:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 18:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 19:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	case 20:
		for (i = 0; i < NumToSort; i++)
		{
			cout << "Enter number " << (i + 1) << ": ";
			ArrayToSort[i] = ReadInteger();
		}
		break;
	}
	cout << "The numbers to be sorted are: ";
	for (i = 0; i < NumToSort; i++)
		cout << (i + 1) << ":" << ArrayToSort[i] << ", ";
	cout << "\n";


	system("pause");
}