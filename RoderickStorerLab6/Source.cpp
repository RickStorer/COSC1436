//**************************************************************************
//
// DESCRIPTION: Programming exercise six COSC 1436.S01 – Lab 6
// CLASS: COSC 1436.S01
// AUTHOR: Roderick Storer
// DATE: Sept 2017
//
//**************************************************************************

#include <iostream>

#include <cstring>

using namespace std;

#include <stdlib.h>

void main()
{
	const	int CAlength(80);

	char Cset1[CAlength + 1];
	char Cset2[CAlength + 1];
	char END[4] = "END";
	int i = 0;
	int d;
	int EntryLength;



	cout << "\t\tPalindrome Dectector" << endl;


	while (true)
	{
		cout << "Enter a line of text characters up to 80 in length counting spaces as characters or type END to exit." << endl;
		cin.getline(Cset1, CAlength + 1);
		cout << "You entered: " << Cset1 << endl;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(50000, '\n');
			cout << "You entered too many characters so your entry was cut off. Try again.\n" << endl;
			continue;
		}
		else;
		if (strcmp(Cset1, END) == 0)
		{
			cout << "Exiting program." << endl;
			system("pause");
			exit(0);
		}
		else;


		for (i = 0; Cset1[i] != (char(0)); i++)
			EntryLength = i;

		d = EntryLength;
		i = 0;

		while (i <= EntryLength)
		{
			Cset2[i] = Cset1[d];
			i++;
			d--;
		}
		Cset2[EntryLength + 1] = (char(0));
		if (_strcmpi(Cset1, Cset2) == 0)
			cout << "'" << Cset1 << "' is a palindrome.\n" << endl;
		else
			cout << "'" << Cset1 << "' is not a palindrome.\n" << endl;
	}
	system("pause");
}