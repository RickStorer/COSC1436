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

			memset (Board, false, ((NumRows + 2) * (NumCols + 2) * sizeof (bool)));

			for (Generation = 0; ; Generation++)
				{
				cout << "\tGeneration: " << Generation << endl;
				for (Row = 1; Row <= NumRows; Row++)
					{
					for (Col = 1; Col <= NumCols; Col++)
						cout << (Board [Row] [Col] ? '*' : ' ');
					cout << endl;
					}
				CurrTime = time(0);
				while (time(0) < (CurrTime + WaitTime));
				system("cls");
				}

	system("pause");
}