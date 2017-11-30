#include <iostream>
using namespace std;
#include <string.h>
#include "Commands.h"
#include "ReadString.h"

char * CommandNames	[] =	{
							"Alfa",
							"Bravo",
							"Lounge",
							"Fly",
							"Arrive",
							"Shutdown"
							};

Commands GetCmd (bool AlfaInit, bool BravoInit, bool LoungeInit)
	{
	char *		Cmd;
	Commands	WhichCmd;
	
	
	Cmd = ReadString ();	// get back a dynamic string of characters from ReadString
	for (WhichCmd = CmdAlfa; WhichCmd < NumCmds; WhichCmd = (Commands) (WhichCmd + 1))
		if (_strcmpi(Cmd, CommandNames[WhichCmd]) == 0)	// find which command we just read
			{
			if (((_strcmpi(Cmd, CommandNames[0]) == 0) && (AlfaInit)) || ((_strcmpi(Cmd, CommandNames[1]) == 0) && (BravoInit)) || ((_strcmpi(Cmd, CommandNames[2]) == 0) && (LoungeInit)))
				return DuplicateCmd;
			if (((_strcmpi(Cmd, CommandNames[0]) == 0) || (_strcmpi(Cmd, CommandNames[1]) == 0) || (_strcmpi(Cmd, CommandNames[2]) == 0)) || (AlfaInit && BravoInit && LoungeInit))
				{
				delete[] Cmd;		// need to make sure we clean up dynamic memory
				return WhichCmd;
				}
				else
					{
					delete[] Cmd;
					return MustInitCmds;
					}

			}
			else;
	delete [] Cmd;		// need to make sure we clean up dynamic memory
	return InvalidCmd;
	}