#include <iostream.>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include <conio.h>

//function to make the dice rolls random
void InitDice()
	{
	srand(time(0));
	}

//Function that gets the random number for the die
int ThrowDie()
	{
	int Die;

	Die = rand();
	Die = (Die % 6) + 1;
	return Die;
	}

//Win function
double Win(double & maxbet, double bet)
	{
	maxbet += bet;
	cout << "You won! Your bet is being added to your total making your new total $" << maxbet << "\n" << endl;
	return maxbet;
	}

//Loss function
double Lose(double & maxbet, double bet)
	{
	maxbet -= bet;
	cout << "You lost. Your bet is being subtracted from your total making your new total $" << maxbet << "\n" << endl;
	if (maxbet == 0)
		{
		cout << "You have run out of money. The game will now close. Better Luck next time.\n" << endl;
		system("pause");
		exit(0);
		}
	else;
	return maxbet;
	}

//Function that lets the user roll the dice
int DiceRoll(int & DiceTotal)
{
			int		d1;
			int		d2;
	
	cout << "Press any key to roll the dice.";
	do {
		if (_getch())
			{
			break;
			}
		else;
	} while (true);

	d1 = ThrowDie();
	d2 = ThrowDie();
	DiceTotal = d1 + d2;
	cout << "\nYou have rolled a " << d1 << " and a " << d2 << " for a total roll of " << DiceTotal << endl;
	return DiceTotal;
}

//Function to ask the user if they wish to continue
void KeepGoing()
{
	char YoN;

	for (;;)
		{
		cout << "Would you like to continue playing? Enter Y for yes to continue playing or N for no to exit the game: ";
		cin >> YoN;
		if ((YoN == 'Y') || (YoN == 'y'))
		{
			cout << "You have chosen to keep playing.\n" << endl;
			return;
		}
		else
			if ((YoN == 'N') || (YoN == 'n'))
			{
				cout << "You have chosen to stop playing the game will now exit." << endl;
				system("pause");
				exit(0);
			}
			else
				cout << "You have selected an invalid option. Try again." << endl;
		}
}