#include <string.h>
#include <iostream>

using namespace std;
#include "Plane.h"
#include "ReadString.h"
#include "ReadInteger.h"

char * PlaneNames [] =	{
						"Alfa",
						"Bravo"
						};
	

Plane GetPlane ()
	{
	char *		PlaneName;
	Plane		WhichPlane;
	
	PlaneName = ReadString ();	// get back a dynamic string of characters from ReadString
	for (WhichPlane = PlaneAlfa; WhichPlane < NumPlanes; WhichPlane = (Plane) (WhichPlane + 1))
		if (_strcmpi (PlaneName, PlaneNames [WhichPlane]) == 0)	// find which command we just read
				{
				delete [] PlaneName;		// need to make sure we clean up dynamic memory
				return WhichPlane;
				}
			else;
	delete [] PlaneName;		// need to make sure we clean up dynamic memory
	return InvalidPlane;
	}

void FlyPlane (Plane WhichPlane, PlaneInfo & P, PlaneInfo & L)
	{
	do	{
		// print the names of all parties on the plane
		// delete each of the names
		// reset number of empty seats and number of parties
		// move people from lounge onto plane
		} while (P.NumEmptySeats == 0);
	}

void PlaneInit(bool & Init, PlaneInfo & P)
{
	Init = true;
do {
	P.NumSeats = ReadInteger();
	if (P.NumSeats < 1)
		cout << "The Number of seats in a plane must be at least 1.\nEnter number of seats: ";
} while (P.NumSeats < 1);
P.NumEmptySeats = P.NumSeats;
P.NumParties = 0;
P.Parties = new Party[P.NumSeats];
}
