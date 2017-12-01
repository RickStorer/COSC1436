#ifndef PLANE_H
#define PLANE_H

enum Plane	{
			InvalidPlane = -1,
			PlaneAlfa,
			PlaneBravo,
			PlaneLounge,

			NumPlanes
			};

struct Party
	{
	char *	Name;
	Plane	Which;
	int		Size;
	};

struct PlaneInfo
	{
	int			NumSeats;
	int			NumEmptySeats;
	int			NumParties;
	Party *		Parties;
	};

Plane	GetPlane	();
void	FlyPlane	(Plane, PlaneInfo &, PlaneInfo &);
void	PlaneInit	(bool &, Plane, PlaneInfo &);
void	PartyArrival(Party &, Plane, PlaneInfo &, PlaneInfo &);
void	ShutdownPlane(Plane, PlaneInfo &, PlaneInfo &);

#endif
