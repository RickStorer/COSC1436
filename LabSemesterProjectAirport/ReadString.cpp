#include <iostream>

using namespace std;

#include <memory.h>
#include "ReadString.h"

void SkipSpaces ()
	{
	char	c;

	while (isspace (c = cin.get ()));
	cin.putback (c);	// puts back on keyboard a character we don't want to read now
						// only guaranteed to work once until you do another read
	}

char * ReadString ()
	{
	const	int			FirstGuess (50);
			char		c;
			int			NumCharsEntered;
			char *		pLine;
			int			SlotsInLine;
			char *		pTempLine;

	NumCharsEntered		= 0;
	pLine				= new char [(SlotsInLine = FirstGuess) + 1];
	SkipSpaces ();
	while (!isspace (c = cin.get ()))
		{
		pLine [NumCharsEntered++]	= c;
		if (NumCharsEntered >= SlotsInLine)
				{
				pTempLine	= new char [(SlotsInLine += FirstGuess) + 1];
				memcpy (pTempLine, pLine, NumCharsEntered);
				delete [] pLine;	// no longer need the original array I had read into
				pLine		= pTempLine;
				}
			else;
		}
	pLine [NumCharsEntered]	= '\0';		// when complete, put an end-of-string mark in the line
	return pLine;
	}
