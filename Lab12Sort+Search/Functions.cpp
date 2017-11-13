#include "Functions.h"
#include <iostream>
#include <memory.h>
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

char** EnterNames(char ** Names)
{
	bool	Done = false;
	char *	pLine;
	int		NumNames;

	for (NumNames = 1; NumNames < 21; NumNames++)
	{
			cout << "Enter name " << NumNames << ": ";
			pLine = ReadLine();
			cout << pLine << endl;
			Done = strcmp(pLine, "\0") == 0;
			Names[NumNames - 1] = pLine;
			cout << Names[NumNames - 1] << endl;
			delete[] pLine;
			if (Done)
				return Names;
			else;
	}
	return Names;
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