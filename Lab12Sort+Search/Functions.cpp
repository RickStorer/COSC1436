#include "Functions.h"
#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;

char * ReadLine()
{
	const	int			FirstGuess(50);
	char		c;
	int			NumCharsEntered;
	char *		pLine;
	int			SlotsInLine;
	char *		pTempLine;

	NumCharsEntered = 0;
	pLine = new char[(SlotsInLine = FirstGuess) + 1];
	while ((c = cin.get()) != '\n')
	{
		pLine[NumCharsEntered++] = c;
		if (NumCharsEntered >= SlotsInLine)
		{
			pTempLine = new char[(SlotsInLine += FirstGuess) + 1];
			memcpy(pTempLine, pLine, NumCharsEntered);
			delete[] pLine;
			pLine = pTempLine;
		}
		else;
	}
	pLine[NumCharsEntered] = '\0';
	return pLine;
}

void EnterNames(char ** pNames, int NumNames)
{
	bool	Done = false;
	char *	pLine;
	int		i;

	for (i = 1; i <= NumNames; i++)
	{
			cout << "Enter name " << i << ": ";
			pLine = ReadLine();
			Done = strcmp(pLine, "\0") == 0;
			pNames[i - 1] = pLine;
			if (Done)
				break;
			else;
	}
}

void Sort(char * Names[], int NumOfNames)
{
	bool		Sorted;
	int			i;
	char	*	Temp;

	do {
		NumOfNames--;
		Sorted = true;
		for (i = 0; i < NumOfNames; i++)
			if (_strcmpi(Names[i], Names[i + 1]) > 0)
			{
				Temp = Names[i];
				Names[i] = Names[i + 1];
				Names[i + 1] = Temp;
				Sorted = false;
			}
			else;
	} while (!Sorted);
}

void DisplayNames(char * Names[], int NumOfNames)
{
	int		i;

	for (i = 0; i < NumOfNames; i++)
	{
		cout << Names[i];
		if (i < (NumOfNames - 1))
			cout << ", ";
		else
			cout << "\n\n";
	}
}

void BinarySearch(char ** Names, int NumNames)
{
	int		First;
	int		Last;
	int		Middle;
	char *	pLine;
	int		i;

	cout << "You can now search the list of names your provided. Leave the search field blank and press ennnter to exit." << endl;
	do {
		cout << "Enter a name to search for: ";
		pLine = ReadLine();
		for (i = 0; i < NumNames; i++)
			{
			First = 0;
			Last = (strlen(Names[i])) - 1;
			do {
				Middle = (First + Last) / 2;
				if (strcmp(pLine, Names[Middle]) == 0)
					{
					cout << pLine << " is in position " << Middle << endl;
					return;
					}
				else
					if (strcmp(pLine, Names[Middle]) < 0)
						Last = Middle - 1;
					else
						First = Middle + 1;
				} while (First <= Last);
			}
		cout << pLine << " is not in the list of names provided." << endl;
		} while (pLine != "\0");
}
