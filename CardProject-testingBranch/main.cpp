#include <iostream>
#include <set>
#include <string>

using namespace std;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "card.h"
#include "deck.h"

int main()
{
    cout << "Hello World!!!" << endl;

    Catch::Session().run();

    system("pause");

    return 0;
}

TEST_CASE("Test Cards")
{
    SECTION("Test create bad cards")
    {
        Card c1(-10, "Hearts");
        Card c2(10, "Fish");
        Card c3(-10, "Fish");

        REQUIRE(c1.getNumericValue() == 2);
        REQUIRE(c1.getSuit() == "Hearts");
        REQUIRE(c2.getNumericValue() == 10);
        REQUIRE(c2.getSuit() == "Clubs");
        REQUIRE(c3.getNumericValue() == 2);
        REQUIRE(c3.getSuit() == "Clubs");
    }

    SECTION("Test create 52 cards")
    {
        string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
        for (int i = 0; i < 4; i++)            
        {
            for (int num = 2; num <= 14; num++)
            {
                Card c(num, suits[i]);
                REQUIRE(c.getNumericValue() == num);
                REQUIRE(c.getSuit() == suits[i]);
            }
        }        
    }  
     
    SECTION("Test toString()")
    {
        Card c1(3, "Diamonds");
        Card c2(10, "Hearts");
        Card c3(14, "Spades");

        REQUIRE(c1.toString() == "3 of Diamonds");
        REQUIRE(c2.toString() == "10 of Hearts");
        REQUIRE(c3.toString() == "Ace of Spades");
    }

    SECTION("Test equivalence")
    {
        Card c1(3, "Diamonds");
        Card c2(3, "Diamonds");
        Card c3(14, "Spades");

        REQUIRE(c1.eqaul(c2) == true);
        REQUIRE(c1.eqaul(c3) == false);
    }
}

TEST_CASE("Test Deck")
{
    SECTION("Test create Deck")
    {
        Deck deck1;

        //Test Size
        REQUIRE(deck1.getLength() == 52);
    }

    SECTION("Test shuffle Deck")
    {
        Deck deck1;
        Deck deck2;

        //Shuffles deck 2
        deck2.shuffle();
        
        //Test to see if the decks are the same
        REQUIRE(deck1.equal(deck2) == false);
        //if it fails, run it again
    }

    SECTION("Test Dealing")
    {
        //remove 7 cards
        Deck deck1;
        deck1.deal(7);
        REQUIRE(deck1.getLength() == 45);

        //remove all 52 cards one at a time
        Deck deck2;
        for(int i = 0;i<52;i++){
            deck2.deal(1);
        }
        REQUIRE(deck2.getLength()==0);

        //require that an exception is thrown when there are no more cards
        REQUIRE_THROWS(deck2.deal(1));

        //check that each card removed is unique
        set<string> uniqueCards;
        Deck deck3;
        for(int i = 0;i<52;i++){
            vector<Card> cards = deck3.deal(1);
            uniqueCards.insert(cards.back().toString());
        }
        REQUIRE(uniqueCards.size()==52);
    }

    SECTION("Test Dealing 2")
    {
        for(int i = 0;i<52;i++){
            Deck deck;
            vector<Card> cards = deck.deal(i);
            REQUIRE(deck.getLength() + cards.size() == 52);

            vector<Card> leftInDeck = deck.deal(52-i);
            for(int j = 0;j<cards.size();j++){
                for(int k = 0;k<leftInDeck.size();k++){
                    REQUIRE(cards.at(j).toString()!=leftInDeck.at(k).toString());
                }
            }
        }
    }
}