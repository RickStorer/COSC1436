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

void PartyArrival(Party & Arrival, Plane WhichPlane, PlaneInfo & P, PlaneInfo & L)
{
	if (Arrival.Size > P.NumSeats)										// can the party ever fit on the plane
	{
		cout << PlaneNames[WhichPlane] << " is too small to contain " << Arrival.Name << " with " << Arrival.Size << " people so they will be turned away." << endl;		//		no, turn party away
		return;
	}
	else																//		else they could possibly fit
		if (Arrival.Size <= P.NumEmptySeats)							//			are there enough empty seats now?
		{
			cout << "Party " << Arrival.Name << " with " << Arrival.Size << " people has been seated on " << PlaneNames[WhichPlane] << "." << endl;
			P.NumEmptySeats -= Arrival.Size;
			P.Parties[P.NumParties] = Arrival;							//					yes, put party on plane
			P.NumParties++;
			if (P.NumEmptySeats == 0)									//					is the plane full?
			{
				FlyPlane(WhichPlane, P, L);								//							yes, fly plane (we will write a function for this)
				return;
			}
			else														//						else 
				return;													//							plane is not full, so nothing else to do now
		}
		else															//				else
			if (Arrival.Size <= L.NumEmptySeats)						//					party does not fit now, can they fit in the lounge?
			{
				cout << "Party " << Arrival.Name << " with " << Arrival.Size << " people is currently unable to fit on " << PlaneNames[WhichPlane] << " and has been seated in the lounge." << endl;
				L.NumEmptySeats -= Arrival.Size;
				L.Parties[L.NumParties] = Arrival;						//							yes, move party into lounge
				L.NumParties++;
				return;
			}
			else															//							no, turn party away
				cout << "Party " << Arrival.Name << " with " << Arrival.Size << " people is also currently unable to fit in the lounge and will be turned away." << endl;
}