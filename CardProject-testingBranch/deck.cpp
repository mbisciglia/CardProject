#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "card.h"
#include "deck.h"

using namespace std;


Deck::Deck()
{
	for (unsigned int i = 2; i < 15; i++)
	{
		Card TempCard(i, "Hearts");
		DeckOfCards.push_back(TempCard);
	}

	for (unsigned int i = 2; i < 15; i++)
	{
		Card Tempcard(i, "Spades");
		DeckOfCards.push_back(Tempcard);
	}

	for (unsigned int i = 2; i < 15; i++)
	{
		Card Tempcard(i, "Clubs");
		DeckOfCards.push_back(Tempcard);
	}

	for (unsigned int i = 2; i < 15; i++)
	{
		Card Tempcard(i, "Diamonds");
		DeckOfCards.push_back(Tempcard);
	}
}

int Deck::getLength()
{
	return DeckOfCards.size();
}

void Deck::shuffle()
{
	random_shuffle(DeckOfCards.begin(), DeckOfCards.end() );
}

bool Deck::equal(Deck testDeck)
{
	bool retval = true;

	if (testDeck.DeckOfCards.size() != DeckOfCards.size())
	{
		retval = false;
	}
	else
	{
		for (int i = 0; i < DeckOfCards.size(); i++)
		{
			if (DeckOfCards.at(i).eqaul(testDeck.DeckOfCards.at(i)) == false)
			{
				retval = false;
				break;
			}
		}
	}

	return retval;
}

vector<Card> Deck::deal(int totalToDeal)
{
	if (DeckOfCards.size() < totalToDeal)
	{
		throw "tooFewCards";
	}
	vector<Card> returnCards;

	for (int i = 0; i < totalToDeal; i++)
	{
		returnCards.push_back(DeckOfCards.back());
		DeckOfCards.pop_back();
	}

	return returnCards;
}