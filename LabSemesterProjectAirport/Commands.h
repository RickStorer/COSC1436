#ifndef COMMANDS_H
#define COMMANDS_H

enum Commands	{
				MustInitCmds = -3,
				DuplicateCmd = -2,
				InvalidCmd = -1,
				CmdAlfa,
				CmdBravo,
				CmdLounge,
				CmdFly,
				CmdArrive,
				CmdShutdown,
				

				NumCmds
				};

Commands GetCmd (bool ,bool ,bool);

#endif
