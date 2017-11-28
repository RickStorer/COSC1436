#include <iostream>

using namespace std;

#include "ReadInteger.h"
#include "ReadString.h"

int ReadInteger ()
	{
	char		c;
	int			Num;

	Num	= 0;
	SkipSpaces ();
	while ((c = cin.get ()) != '\n')
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
						Num = (Num * 10) + (c - '0');
						break;
			default:
						cout << '\a';
			}
		}
	return Num;
	}
