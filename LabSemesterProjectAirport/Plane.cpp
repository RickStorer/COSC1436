#include <string.h>
#include <iostream>

using namespace std;
#include "Plane.h"
#include "ReadString.h"
#include "ReadInteger.h"

char * PlaneNames [] =	{
						"Alfa",
						"Bravo",
						"lounge"
						};
	

Plane GetPlane ()
	{
	char *		PlaneName;
	Plane		WhichPlane;
	
	PlaneName = ReadString ();				// get back a dynamic string of characters from ReadString
	for (WhichPlane = PlaneAlfa; WhichPlane < NumPlanes; WhichPlane = (Plane) (WhichPlane + 1))
		if (_strcmpi (PlaneName, PlaneNames [WhichPlane]) == 0)	// find which command we just read
				{
				delete [] PlaneName;		
				return WhichPlane;
				}
			else;
	delete [] PlaneName;					
	return InvalidPlane;
	}

void FlyPlane (Plane WhichPlane, PlaneInfo & P, PlaneInfo & L)
	{
	int i;
	int x;
	int y;

	do	{
		cout << "Plane " << PlaneNames[WhichPlane] << " has delivered parties: ";
		for	(i = 0; i < P.NumParties; i++)						// print the names of all parties on the plane
		{									
			cout << P.Parties[i].Name;
			if (i == (P.NumParties - 1))
				cout << "." << endl;
			else
				cout << ", ";
			delete [] P.Parties[i].Name;						// delete each of the names
		}
		P.NumEmptySeats = P.NumSeats;							// reset number of empty seats and number of parties
		P.NumParties = 0;
		for (i = 0, x = 0; i < L.NumParties; i++)				// move people from lounge onto plane
			{
			if (L.Parties[i].Which == WhichPlane)
				{
				if (L.Parties[i].Size <= P.NumEmptySeats)
					{
					P.Parties[x] = L.Parties[i];
					cout << "The party for '" << L.Parties[i].Name << "' has boarded " << PlaneNames[WhichPlane] << " from the lounge." << endl;
					L.NumEmptySeats += L.Parties[i].Size;
					for (y = (i + 1); y < L.NumParties; y++)
						{
						L.Parties[y - 1] = L.Parties[y];
						}
					i--;
					P.NumEmptySeats -= P.Parties[x].Size;
					P.NumParties++;
					L.NumParties--;
					x++;
					}
				else;
				}
			else;
			}
		} while (P.NumEmptySeats == 0);
	}

void PlaneInit(bool & Init, Plane WhichPlane, PlaneInfo & P)
{
	Init = true;
	do {
		P.NumSeats = ReadInteger();
		if (P.NumSeats < 1)
			cout << "The Number of seats in a plane must be at least 1.\nEnter number of seats for " << PlaneNames[WhichPlane] << ": ";
		else;
	} while (P.NumSeats < 1);
	P.NumEmptySeats = P.NumSeats;
	P.NumParties = 0;
	P.Parties = new Party[P.NumSeats];
}

void PartyArrival(Party & Arrival, Plane WhichPlane, PlaneInfo & P, PlaneInfo & L)
{
	if (Arrival.Size < 1)
		{
		cout << "Arriving party size must be at least 1. Please re-enter commmand." << endl;
		return;
		}
	else
		if (Arrival.Size > P.NumSeats)										// can the party ever fit on the plane
			{
			cout << PlaneNames[WhichPlane] << " is too small to contain the party for '" << Arrival.Name << "' so they will be turned away." << endl;		//		no, turn party away
			return;
			}
		else																//		else they could possibly fit
			if (Arrival.Size <= P.NumEmptySeats)							//			are there enough empty seats now?
				{
				cout << "The party for '" << Arrival.Name << "' has boarded " << PlaneNames[WhichPlane] << "." << endl;
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
					cout << "The party for '" << Arrival.Name << "' is currently unable to fit on " << PlaneNames[WhichPlane] << " and has been seated in the lounge." << endl;
					L.NumEmptySeats -= Arrival.Size;
					L.Parties[L.NumParties] = Arrival;						//							yes, move party into lounge
					L.NumParties++;
					return;
					}
				else														//							no, turn party away
					cout << "The party for '" << Arrival.Name << "' is currently unable to fit on " << PlaneNames[WhichPlane] << " or in the lounge and will be turned away." << endl;
}

void ShutdownPlane(Plane WhichPlane, PlaneInfo & P, PlaneInfo & L)
{
	while (P.NumEmptySeats != P.NumSeats)
		FlyPlane(WhichPlane, P, L);
		delete [] P.Parties;							// clean up the dynamic array holding parties for each plane
}