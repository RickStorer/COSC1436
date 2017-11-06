//**************************************************************************
// 
// DESCRIPTION: Programming exercise ten - COSC 1436.S01 – Lab 10
// CLASS:		COSC 1436.S01 
// AUTHOR:		Roderick Storer
// DATE:		Nov 2017 
// 
//**************************************************************************

#include <iostream>

using namespace std;

#include <stdlib.h>
#include "Functions.h"

void main()
{
	int QtyOfNums;
	int i;
	int NumberSort[20];


	cout << "\t\tInteger Sorter" << endl;
	
	QtyOfNums = NumOfIntegersToSort();
	FillArray(NumberSort, QtyOfNums);
	cout << "The numbers to be sorted are: ";
	DisplayArray(NumberSort, QtyOfNums);
	cout << "\n";
	Sort(NumberSort, QtyOfNums);
	cout << "The numbers after sorting are: ";
	DisplayArray(NumberSort, QtyOfNums);
	cout << "\n";
	system("pause");
}