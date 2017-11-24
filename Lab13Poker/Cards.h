#ifndef CARDS
#define CARDS

enum Suits	{
			Hearts,
			Diamonds,
			Clubs,
			Spades
			};

enum Values	{
			Two,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight,
			Nine,
			Ten,
			Jack,
			Queen,
			King,
			Ace
			};

struct Card
	{
	Suits		Suit;
	Values		Value;
	};

struct Hand
{
	Card		Cards[5];
};

void InitDeck		(Card []);
void ShowCard		(const Card &);
void ShowDeck		(const Card []);
void Shuffle		(Card []);
void DealCards		(Hand [], Card []);
void ShowHands		(Hand []);
void SortHands		(Hand []);
void DetermineHand	(Hand []);

#endif
