#ifndef PLANE_H
#define PLANE_H

enum Plane	{
			InvalidPlane = -1,
			PlaneAlfa,
			PlaneBravo,

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
void	PlaneInit	(bool &, PlaneInfo &);
void	PartyArrival(Party &, Plane, PlaneInfo &, PlaneInfo &);

#endif
