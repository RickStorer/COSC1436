#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void	InitDice	();					//function to make the dice rolls random
int		ThrowDie	();					//Function that gets the random number for the die
double	Win			(double &, double); //Win function
double	Lose		(double &, double); //Loss function
int		DiceRoll	(int &);			//Function that lets the user roll the dice
void	KeepGoing	();					//Function to ask the user if they wish to continue
#endif
