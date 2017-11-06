#include <conio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <cstring>
#include "Functions.h"

int ReadInteger()
{
	char		c;
	bool		IsNeg;
	int			Num;
	int			NumCharsEntered;

	IsNeg = false;
	Num = 0;
	NumCharsEntered = 0;
	while ((c = _getch()) != '\r')
	{
		switch (c)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			_putch(c);
			Num = (Num * 10) + (c - '0');
			NumCharsEntered++;
			break;
		case '-':
			if (NumCharsEntered == 0)
			{
				IsNeg = true;
				_putch('-');
				NumCharsEntered++;
			}
			else
				_putch('\a');
			break;
		case '\b':
			if (NumCharsEntered > 0)
			{
				_putch('\b');
				_putch(' ');
				_putch('\b');
				Num = Num / 10;
				NumCharsEntered--;
				if (NumCharsEntered == 0)
					IsNeg = false;
				else;
			}
			else
				_putch('\a');
			break;
		default:
			_putch('\a');
		}
	}
	_putch('\n');
	if (IsNeg)
		Num = -Num;
	else;
	return Num;
}

int NumOfNamesToSort()
{
	int		UserInput;

	do {
		cout << "How many names would you like to have sorted? (1-20): ";
		UserInput = ReadInteger();
		if (UserInput > 20)
		{
			cout << "The number you have entered is too large. The maximum is 20. Try again.\n" << endl;
			continue;
		}
		else;
		if (UserInput < 1)
		{
			cout << "The number you have entered is too small. The minimum is 1. Try again.\n" << endl;
			continue;
		}
		else
			break;
	} while (true);
	return UserInput;
}

void EnterName(char Names[][16], int NumOfNames)
{
	int		i;
	char	Name[16];

	cout << "You will now enter " << NumOfNames << " names with a max of 15 characters each." << endl;
	for (i = 0; i < NumOfNames; i++)
	{
		cout << "Enter name " << (i + 1) << ": ";
		cin.getline(Name, 16);
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(5000, '\n');
			cout << "You entered too many characters so your entry was cut off to " << Name << endl;
		}
		strcpy_s(Names[i], 16, Name);
	}
}

void DisplayNames(char Names[][16], int NumOfNames)
{
	int		i;

	for (i = 0; i < NumOfNames; i++)
	{
		cout << Names[i];
		if (i < (NumOfNames - 1))
			cout << ", ";
		else
			cout << "\n";
	}
}

void Sort(char Names[][16], int NumOfNames)
{
	bool		Sorted;
	int			i;
	char		Temp[16];

	do {
		NumOfNames--;
		Sorted = true;
		for (i = 0; i < NumOfNames; i++)
			if (strcmp(Names[i], Names[i + 1]) > 0)
			{
				strcpy_s(Temp, 16, Names[i]);
				strcpy_s(Names[i], 16, Names[i + 1]);
				strcpy_s(Names[i + 1], 16, Temp);
				Sorted = false;
			}
			else;
	} while (!Sorted);
}