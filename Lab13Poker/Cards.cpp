#include <iostream>

using namespace std;

#include <stdlib.h>
#include <time.h>
#include "Cards.h"

char * SuitNames[] =	{
						"Hearts",
						"Diamonds",
						"Clubs",
						"Spades"
						};

char * ValueNames [] =	{
						"Two",
						"Three",
						"Four",
						"Five",
						"Six",
						"Seven",
						"Eight",
						"Nine",
						"Ten",
						"Jack",
						"Queen",
						"King",
						"Ace"
						};

void InitDeck (Card Deck [])
	{
	int		i;
	Suits	S;
	Values	V;

	srand (time (0));	// set the seed for the random number generator

	i = 0;
	for (S = Hearts; S <= Spades; S = (Suits) (S + 1))
		for (V = Two; V <= Ace; V = (Values) (V + 1))
			{
			Deck [i].Suit	= S;
			Deck [i].Value	= V;
			i++;
			}
	}

void ShowCard (const Card & C)	// passing structures by reference is generally more efficient
	{
	cout << "Card is the " << ValueNames [C.Value] << " of " << SuitNames [C.Suit] << endl;
	}

void ShowDeck (const Card Deck [])
	{
	int		i;

	for (i = 0; i < 52; i++)
		ShowCard (Deck [i]);
	}

void Shuffle (Card Deck [])
	{
	int		i;
	int		SwapLocation;
	Card	TempCard;

	for (i = 0; i < 52; i++)
		{
		SwapLocation		= rand () % 52;
		TempCard			= Deck [i];
		Deck [i]			= Deck [SwapLocation];
		Deck [SwapLocation]	= TempCard;
		}
	}

void DealCards (Hand Hands [], Card Deck [])
{
	int i;
	int h = 0;
	int c = 0;

	for (i = 0; i < 20; i++)
		{
		if (h > 3)
			{
			h = 0;
			c++;
			}
		else;
		Hands[h].Cards[c] = Deck[i];
		h++;
		}
}

void ShowHands(Hand Hands[])
{
	int h;
	int c;

	for (h = 0; h < 4; h++)
	{
		cout << "Hand " << (h + 1) << " contains: ";
		for (c = 0; c < 5; c++)
		{
			cout << ValueNames[Hands[h].Cards[c].Value] << " of " << SuitNames[Hands[h].Cards[c].Suit];
			if (c < 4)
				cout << ", ";
			else;
		}
		cout << endl;
	}

}

void SortHands(Hand Hands[])
{
	int		i;
	int		h;
	int		NumCards;
	bool	Sorted;
	Card	Temp;

	for (h = 0; h < 4; h++)
		{
		NumCards = 5;
		do {
			NumCards--;
			Sorted = true;
			for (i = 0; i < NumCards; i++)
				if (Hands[h].Cards[i].Value > Hands[h].Cards[i + 1].Value)
				{
					Temp = Hands[h].Cards[i];
					Hands[h].Cards[i] = Hands[h].Cards[i + 1];
					Hands[h].Cards[i + 1] = Temp;
					Sorted = false;
				}
				else;
			} while (!Sorted);
		}
}

void DetermineHand (Hand Hands [])
{
	int h;

	for (h = 0; h < 4; h++)
	{
		do{
			if (((((Hands[h].Cards[0].Value + 1) == (Hands[h].Cards[1].Value)) && ((Hands[h].Cards[1].Value + 1) == (Hands[h].Cards[2].Value)) && ((Hands[h].Cards[2].Value + 1) == (Hands[h].Cards[3].Value)) && ((Hands[h].Cards[3].Value + 1) == (Hands[h].Cards[4].Value))) ||
				(((Hands[h].Cards[0].Value) == 0) && ((Hands[h].Cards[1].Value) == 1) && ((Hands[h].Cards[2].Value) == 2) && ((Hands[h].Cards[3].Value) == 3) && ((Hands[h].Cards[4].Value) == 12))) &&
				(((Hands[h].Cards[0].Suit) == (Hands[h].Cards[1].Suit)) && ((Hands[h].Cards[0].Suit) == (Hands[h].Cards[2].Suit)) && ((Hands[h].Cards[0].Suit) == (Hands[h].Cards[3].Suit)) && ((Hands[h].Cards[0].Suit) == (Hands[h].Cards[4].Suit))))
				{
				cout << "Hand " << h + 1 << " is a Straight Flush." << endl;
				break;
				}
			else;
			if (((Hands[h].Cards[0].Value == Hands[h].Cards[1].Value) && (Hands[h].Cards[1].Value == Hands[h].Cards[2].Value) && (Hands[h].Cards[2].Value == Hands[h].Cards[3].Value)) || 
				((Hands[h].Cards[1].Value == Hands[h].Cards[2].Value) && (Hands[h].Cards[2].Value == Hands[h].Cards[3].Value) && (Hands[h].Cards[3].Value == Hands[h].Cards[4].Value)))
				{
				cout << "Hand " << h + 1 << " is Four of a Kind." << endl;
				break;
				}
			else;
			if (((Hands[h].Cards[0].Value == Hands[h].Cards[1].Value) && (Hands[h].Cards[1].Value == Hands[h].Cards[2].Value) && (Hands[h].Cards[3].Value == Hands[h].Cards[4].Value)) ||
				((Hands[h].Cards[0].Value == Hands[h].Cards[1].Value) && (Hands[h].Cards[2].Value == Hands[h].Cards[3].Value) && (Hands[h].Cards[3].Value == Hands[h].Cards[4].Value)))
				{
				cout << "Hand " << h + 1 << " is a Full House." << endl;
				break;
				}
			else;
			if (((Hands[h].Cards[0].Suit) == (Hands[h].Cards[1].Suit)) && ((Hands[h].Cards[0].Suit) == (Hands[h].Cards[2].Suit)) && ((Hands[h].Cards[0].Suit) == (Hands[h].Cards[3].Suit)) && ((Hands[h].Cards[0].Suit) == (Hands[h].Cards[4].Suit)))
				{
				cout << "Hand " << h + 1 << " is a Flush." << endl;
				break;
				}
			else;
			if ((((Hands[h].Cards[0].Value + 1) == (Hands[h].Cards[1].Value)) && ((Hands[h].Cards[1].Value + 1) == (Hands[h].Cards[2].Value)) && ((Hands[h].Cards[2].Value + 1) == (Hands[h].Cards[3].Value)) && ((Hands[h].Cards[3].Value + 1) == (Hands[h].Cards[4].Value))) ||
				(((Hands[h].Cards[0].Value) == 0) && ((Hands[h].Cards[1].Value) == 1) && ((Hands[h].Cards[2].Value) == 2) && ((Hands[h].Cards[3].Value) == 3) && ((Hands[h].Cards[4].Value) == 12)))
				{
				cout << "Hand " << h + 1 << " is a Straight." << endl;
				break;
				}
			else;
			if (((Hands[h].Cards[0].Value == Hands[h].Cards[1].Value) && (Hands[h].Cards[1].Value == Hands[h].Cards[2].Value)) ||
				((Hands[h].Cards[1].Value == Hands[h].Cards[2].Value) && (Hands[h].Cards[2].Value == Hands[h].Cards[3].Value)) ||
				((Hands[h].Cards[2].Value == Hands[h].Cards[3].Value) && (Hands[h].Cards[3].Value == Hands[h].Cards[4].Value)))
				{
				cout << "Hand " << h + 1 << " is Three of a Kind." << endl;
				break;
				}
			else;
			if (((Hands[h].Cards[0].Value == Hands[h].Cards[1].Value) && (Hands[h].Cards[2].Value == Hands[h].Cards[3].Value)) ||
				((Hands[h].Cards[0].Value == Hands[h].Cards[1].Value) && (Hands[h].Cards[3].Value == Hands[h].Cards[4].Value)) ||
				((Hands[h].Cards[1].Value == Hands[h].Cards[2].Value) && (Hands[h].Cards[3].Value == Hands[h].Cards[4].Value)))
			{
				cout << "Hand " << h + 1 << " is Two Pair." << endl;
				break;
			}
			else;
			if ((Hands[h].Cards[0].Value == Hands[h].Cards[1].Value) || (Hands[h].Cards[1].Value == Hands[h].Cards[2].Value) || (Hands[h].Cards[2].Value == Hands[h].Cards[3].Value) || (Hands[h].Cards[3].Value == Hands[h].Cards[4].Value))
			{
				cout << "Hand " << h + 1 << " is One Pair." << endl;
				break;
			}
			else;
			cout << "Hand " << h + 1 << " is a High Card of " << ValueNames [Hands[h].Cards[4].Value] << "." << endl;
			break;
		}while (true);
	}
}