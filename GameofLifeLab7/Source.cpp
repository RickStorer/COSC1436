#include <iostream>

using namespace std;

#include <stdlib.h>
#include <conio.h>
#include <memory.h>
#include <time.h>

void main()
{
	const	int		NumRows (60);
	const	int		NumCols (60);
	const	time_t	WaitTime(3);

			bool	Board [NumRows + 2] [NumCols + 2];
			bool	Next [NumRows + 2] [NumCols + 2];

			time_t	CurrTime;

			int		Generation;
			int		NumNeighbors;
			int		Col;
			int		Row;
			int		x;
			int		y;


			memset (Board, false, ((NumRows + 2) * (NumCols + 2) * sizeof (bool)));

			cout << "Welcome to the game of life.\nThe game will be set up on a 60 x 60 board.\nTo get started you will need to select which cells on the board are alive.\n\nOnce you are satisfied with your entries set the row and column to -1,-1 to begin.\n" << endl;
			cout << "Select a row: ";
			cin >> x;
			cout << "Select a column: ";
			cin >> y;
			if ((x == -1) && (y == -1))
					cout << "At least one cell must be alive to begin." << endl;
				else;
			if ((x < 1) || (x > 60) || (y < 1) || (y > 60))
					cout << "Each row and colum must be a value from 1 to 60. Please try again.\n" << endl;
				else
					{
					Board[x][y] = true;
					cout << x << "," << y << " is alive.\n" << endl;
					}
			for (; ; )
				{
				cout << "Select another row: ";
				cin >> x;
				cout << "Select another column: ";
				cin >> y;
				if ((x == -1) && (y == -1))
						{
						cout << "\nThe game of life will begin shortly. ";
						CurrTime = time(0);
						while (time(0) < (CurrTime + WaitTime));
						system("cls");
						break;
						}
					else;
				if ((x < 1) || (x > 60) || (y < 1) || (y > 60))
						cout << "Each row and colum must be a value from 1 to 60. Please try again.\n" << endl;
					else
						{
						Board[x][y] = true;
						cout << x << "," << y << " is alive.\n" << endl;
						}
				}
			for (Generation = 0; ; Generation++)
				{
				cout << "\n\tGeneration: " << Generation << "\tPress any key to end the program." << endl;
				for (Row = 1; Row <= NumRows; Row++)
					{
					for (Col = 1; Col <= NumCols; Col++)
						cout << (Board [Row] [Col] ? '*' : ' ');
					cout << endl;
					}
				//Checking every cell
				for (Row = 1; Row <= NumRows; Row++)
					for (Col = 1; Col <= NumCols; Col++)
						{ //Counting neighbors for each cell
						NumNeighbors = 0;
						if (Board[Row][Col - 1])
								NumNeighbors++;
							else;
						if (Board[Row - 1][Col])
								NumNeighbors++;
							else; 
						if (Board[Row][Col + 1])
								NumNeighbors++;
							else; 
						if (Board[Row + 1][Col])
								NumNeighbors++;
							else; 
						if (Board[Row - 1][Col - 1])
								NumNeighbors++;
							else; 
						if (Board[Row + 1][Col + 1])
								NumNeighbors++;
							else; 
						if (Board[Row + 1][Col - 1])
								NumNeighbors++;
							else; 
						if (Board[Row - 1][Col + 1])
								NumNeighbors++;
							else;

						// Rules 
						if (NumNeighbors > 3) // Dies of overcrowding
								Next[Row][Col] = false;
							else;
						if (NumNeighbors < 2) // Dies of lonliness
								Next[Row][Col] = false;
							else;
						if (NumNeighbors == 3) //Becomes alive
								Next[Row][Col] = true;
							else;
						if (NumNeighbors == 2) //Nothing changes
								Next[Row][Col] = Board[Row][Col];
							else;
						}

				for (Row = 1; Row <= NumRows; Row++)
					for (Col = 1; Col <= NumCols; Col++)
						Board[Row][Col] = Next[Row][Col];

				if (_kbhit())
						break;
					else;
				CurrTime = time(0);
				while (time(0) < (CurrTime + WaitTime));
				system("cls");
				}

	system("pause");
}