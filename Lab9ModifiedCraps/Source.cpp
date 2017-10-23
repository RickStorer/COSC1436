//**************************************************************************
// 
// DESCRIPTION: Programming exercise nine - COSC 1436.S01 – Lab 9
// CLASS:		COSC 1436.S01 
// AUTHOR:		Roderick Storer
// DATE:		Oct 2017 
// 
//**************************************************************************

#include <iostream>

using namespace std;

#include <stdlib.h>
#include <conio.h>
#include "Functions.h"

void main()
{
	double	Bet;
	double	MaxBet = 50;
	int		d1;
	int		d2;
	int		dt;
	int		point;
	bool	ContPlay;
	cout << "\t\tModified Craps" << endl;

	InitDice();

	cout << "This will be a game of craps that is slightly modified. The Rules are as follows:" << endl;
	cout << "You will start with $50. You will place a bet then throw the dice. If the total of the dice roll is 7 or 11" << endl;
	cout << "you instantly win and your bet is added to your total money. If the total of the dice roll is 2, 3, or 12" << endl;
	cout << "you instantly lose and your bet is subtracted from your total money. If the total of the dice roll is" << endl;
	cout << "anything else that number becomes your 'point' and you will roll again. You will continue to roll until" << endl;
	cout << "you roll either your 'point' or a 7. If you roll your 'point' you win and your bet is added to your total." << endl;
	cout << "If you roll a 7 you lose and your bet is subtracted from your total. You will then have the option to stop" << endl;
	cout << "playing or continue until you run out of money.\n" << endl;

	do {
		cout << "Place your bet (xx.xx): ";
		cin >> Bet;
		if (Bet > MaxBet)
		{
			cout << "You cannot bet more money than you have. Try again." << endl;
			continue;
		}
		else
			if (Bet < 00.01)
			{
				cout << "You must bet at least one cent. Try again." << endl;
				continue;
			}
			else;
		
			
			cout << "You bet $" << Bet << endl;
			DiceRoll(dt);
			if ((dt == 7) || (dt == 11))
				{
				Win(MaxBet, Bet);
				KeepGoing();
				continue;
				}
			else
				if ((dt == 2) || (dt == 3) || (dt == 12))
					{
					Lose(MaxBet, Bet);
					KeepGoing();
					continue;
					}
				else
					{
					point = dt;
					cout << point << " has become your 'point'. You must roll a " << point << " to win. If you roll a 7 you lose." << endl;
					}
			while (true)
				{
				DiceRoll(dt);
				if (dt == point)
				{
					Win(MaxBet, Bet);
					break;
				}
				else
					if (dt == 7)
					{
						Lose(MaxBet, Bet);
						break;
					}
					else;		
				}
			KeepGoing();
		} while (true);

	system("pause");
}