//**************************************************************************
// 
// DESCRIPTION: Programming exercise project - COSC 1436.S01 � Project
// CLASS:		COSC 1436.S01 
// AUTHOR:		Roderick Storer
// DATE:		Dec 2017 
// 
//**************************************************************************

#include <iostream>

using namespace std;

#include <stdlib.h>

#include "Commands.h"
#include "Plane.h"
#include "ReadInteger.h"
#include "ReadString.h"

void main()
{
	Party		ArrivingParty;
	PlaneInfo	Alfa;
	PlaneInfo	Bravo;
	PlaneInfo	Lounge;
	bool		AlfaInit	= false;
	bool		BravoInit	= false;
	bool		LoungeInit	= false;


	do {
		cout << "> ";

		switch (GetCmd(AlfaInit, BravoInit, LoungeInit))
		{
		case CmdAlfa:
			PlaneInit(AlfaInit, PlaneAlfa, Alfa);
			break;
		case CmdBravo:
			PlaneInit(BravoInit, PlaneBravo, Bravo);
			break;
		case CmdLounge:
			PlaneInit(LoungeInit, PlaneLounge, Lounge);
			break;
		case CmdFly:
			switch (GetPlane())
			{
			case PlaneAlfa:
				FlyPlane(PlaneAlfa, Alfa, Lounge);
				break;
			case PlaneBravo:
				FlyPlane(PlaneBravo, Bravo, Lounge);
				break;
			case InvalidPlane:
				cout << "You have entered an invalid plane name. Please re-enter commmand." << endl;
				break;
			default:
				cout << "Internal error 303, please contact customer support." << endl;
				exit(0);
			}
			break;
		case CmdArrive:
			ArrivingParty.Which = GetPlane();					//	Get which plane we want on
			ArrivingParty.Name = ReadString();					//	get party name
			ArrivingParty.Size = ReadInteger();					//	get size of party
			switch (ArrivingParty.Which)
			{
			case PlaneAlfa:
				PartyArrival(ArrivingParty, PlaneAlfa, Alfa, Lounge);
				break;
			case PlaneBravo:
				PartyArrival(ArrivingParty, PlaneBravo, Bravo, Lounge);
				break;
			case InvalidPlane:
				cout << "You have entered an invalid plane name. Please re-enter commmand." << endl;
				break;
			default:
				cout << "Internal error 202, please contact customer support." << endl;
				exit(0);
			}
			break;
		case CmdShutdown:
			cout << "Performing shutdown." << endl;
			ShutdownPlane(PlaneAlfa, Alfa, Lounge);
			ShutdownPlane(PlaneBravo, Bravo, Lounge);
			delete [] Lounge.Parties;
			cout << "Shutdown complete." << endl;
			system ("pause");
			exit (0);
		case InvalidCmd:
			cout << "Invalid Command, Please re-enter commmand." << endl;
			break;
		case DuplicateCmd:
			cout << "That command has already been entered and may only be entered once. Please try again." << endl;
			break;
		case MustInitCmds:
			cout << "You must enter the Alfa, Bravo, and Lounge commands first." << endl;
			break;
		default:
			cout << "Internal error 101, please contact customer support." << endl;
			exit(0);
		}
	} while (true);

	system("pause");
}
