//**************************************************************************
// 
// DESCRIPTION: Programming exercise eleven - COSC 1436.S01 – Lab 11
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
	int NumOfNames;
	char Names[20][16];

	NumOfNames = NumOfNamesToSort();
	EnterName(Names, NumOfNames);
	cout << "\nThe list of names before sorting is: ";
	DisplayNames(Names, NumOfNames);
	Sort(Names, NumOfNames);
	cout << "\nThe list of names after sorting is: ";
	DisplayNames(Names, NumOfNames);

	system("pause");
}