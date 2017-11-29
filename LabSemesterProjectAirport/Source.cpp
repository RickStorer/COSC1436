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

	//	initialize the planes and the lounge
	
	//	get a command
	//	depending on which command, we may read in different information

	//	remember that Alfa, Bravo, and Lounge commands must be done before any other commands
	//	and those commands are only done once in the program
	do {
		cout << "> ";

		switch (GetCmd(AlfaInit, BravoInit, LoungeInit))
		{
		case CmdAlfa:
			PlaneInit(AlfaInit, Alfa);
			break;
		case CmdBravo:
			PlaneInit(BravoInit, Bravo);
			break;
		case CmdLounge:
			PlaneInit(LoungeInit, Lounge);
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
				cout << "You have entered an invalid plane name. Try again." << endl;
				break;
			default:
				cout << "Internal error 303, please contact customer support" << endl;
				exit(0);
			}
			break;
		case CmdArrive:
			ArrivingParty.Which = GetPlane();		//	Get which plane we want on
			ArrivingParty.Name = ReadString();	//	get party name
			ArrivingParty.Size = ReadInteger();	//	get size of party
			switch (ArrivingParty.Which)
			{
			case PlaneAlfa:
				// can the party ever fit on the plane
				//			no, turn party away
				//		else they could possibly fit
				//			are there enough empty seats now?
				//					yes, put party on plane
				//					is the plane full?
				//							yes, fly plane (we will write a function for this)
				//						else 
				//							plane is not full, so nothing else to do now
				//				else
				//					party does not fit now, can they fit in the lounge?
				//							yes, move party into lounge
				//							no, turn party away
			case PlaneBravo:
			case InvalidPlane:
				// information is not correct
			default:
				cout << "Internal error 202, please contact customer support" << endl;
				exit(0);
			}
			break;
		case CmdShutdown:
			while (Alfa.NumEmptySeats != 0)
				// FlyPlane (Alfa);
				// do same loop for Bravo
				// make sure we clean up the dynamic array holding parties for each plane
				break;
		case InvalidCmd:
			cout << "Invalid Command, please re-enter" << endl;
			break;
		case DuplicateCmd:
			cout << "That command has already been entered and may only be entered once. Please try again." << endl;
			break;
		case MustInitCmds:
			cout << "You must enter the Alfa, Bravo, and Lounge commands first." << endl;
			break;
		default:
			cout << "Internal error 101, please contact customer support" << endl;
			exit(0);
		}
	} while (true);

	system("pause");
}
