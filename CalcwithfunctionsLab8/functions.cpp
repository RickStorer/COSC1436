#include "functions.h"
#include <conio.h>

// Add, Subtract, Multiply, Divide
double Add (double a, double b)
{
	return a + b;
}

double Sub (double a, double b)
{
	return a - b;
}

double Mult (double a, double b)
{
	return a * b;
}

double Div (double a, double b)
{
	return a / b;
}

// Read number
double ReadInteger()
{
	char		c;
	bool		IsNeg;
	int			Num;
	int			NumCharsEntered;

	IsNeg = false;
	Num = 0;
	NumCharsEntered = 0;
	while ((c = _getch()) != '\r')
	{
		switch (c)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			_putch(c);
			Num = (Num * 10) + (c - '0');
			NumCharsEntered++;
			break;
		case '-':
			if (NumCharsEntered == 0)
			{
				IsNeg = true;
				_putch('-');
				NumCharsEntered++;
			}
			else
				_putch('\a');
			break;
		case '\b':
			if (NumCharsEntered > 0)
			{
				_putch('\b');
				_putch(' ');
				_putch('\b');
				Num = Num / 10;
				NumCharsEntered--;
				if (NumCharsEntered == 0)
					IsNeg = false;
				else;
			}
			else
				_putch('\a');
			break;
		default:
			_putch('\a');
		}
	}
	_putch('\n');
	if (IsNeg)
		Num = -Num;
	else;
	return Num;
}