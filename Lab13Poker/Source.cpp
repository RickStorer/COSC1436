//**************************************************************************
// 
// DESCRIPTION: Programming exercise thirteen - COSC 1436.S01 – Lab 13
// CLASS:		COSC 1436.S01 
// AUTHOR:		Roderick Storer
// DATE:		Nov 2017 
// 
//**************************************************************************

#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Cards.h"

void main()
{
	Card	C1;
	Card	Deck[52];
	Hand	Hands[4];

	InitDeck(Deck);
	Shuffle(Deck);
	DealCards(Hands, Deck);
	SortHands(Hands);
	ShowHands(Hands);
	cout << endl;
	DetermineHand(Hands);

		system("pause");
}