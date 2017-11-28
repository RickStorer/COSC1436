#include <string.h>

#include "Plane.h"
#include "ReadString.h"

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
		} while (/* Plane is full */);
	}
