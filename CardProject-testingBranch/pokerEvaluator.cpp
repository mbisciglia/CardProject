#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "card.h"
#include "pokerEvaluator.h"

using namespace std;

pokerEvaluator::pokerEvaluator(vector<Card> hand)
{
    this->hand = hand;
}

void pokerEvaluator::sortHand()
{
    vector<Card> sorted;
}

string pokerEvaluator::getBestHand()
{
    string bestHand = "";

    int spadeCount = 0;
    int clubCount = 0;
    int diamondCount = 0;
    int heartCount = 0;

    int highVal = -1;
    int secondHighestVal = -1;
    int thirdHighestVal = -1;

    for (int i = 0; i < this->hand.size(); i++)
    {
        if (this->hand.at(i).getSuit() == "Clubs")
        {
            clubCount += 1;
        }
        if (this->hand.at(i).getSuit() == "Diamonds")
        {
            diamondCount += 1;
        }
        if (this->hand.at(i).getSuit() == "Hearts")
        {
            heartCount += 1;
        }
        if (this->hand.at(i).getSuit() == "Spades")
        {
            spadeCount += 1;
        }
        if (this->hand.at(i).getNumericValue() > highVal)
        {
            thirdHighestVal = secondHighestVal;
            secondHighestVal = highVal;
            highVal = this->hand.at(i).getNumericValue();
        }
        else if (this->hand.at(i).getNumericValue() > secondHighestVal)
        {
            thirdHighestVal = secondHighestVal;
            secondHighestVal = this->hand.at(i).getNumericValue();
        }
        else if (this->hand.at(i).getNumericValue() > thirdHighestVal)
        {
            thirdHighestVal = this->hand.at(i).getNumericValue();
        }
    }

    int highSuitVal = -1;
    int runningVal;
    int straightCount = 1;
    if (spadeCount > 4)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand.at(i).getSuit() == "Spades")
            {
                if (this->hand.at(i).getNumericValue() > highSuitVal)
                {
                    highSuitVal = this->hand.at(i).getNumericValue();
                    runningVal = highSuitVal;
                }
            }
        }
        for (int j = 0; j < this->hand.size(); j++)
        {
            for (int i = 0; i < this->hand.size(); i++)
            {
                if (this->hand.at(i).getSuit() == "Spades")
                {
                    if (this->hand.at(i).getNumericValue() == runningVal - 1)
                    {
                        runningVal = runningVal - 1;
                        straightCount = straightCount + 1;
                        if (straightCount >= 5)
                        {
                            if (highSuitVal == 13)
                            {
                                return "Royal Flush";
                            }
                            else
                            {
                                return "Straight Flush";
                            }
                        }
                        break;
                    }

                    if (i == this->hand.size() - 1)
                    {
                        straightCount = 1;
                        runningVal = 0;
                        for (int k = 0; k < this->hand.size(); k++)
                        {
                            if (this->hand.at(k).getNumericValue() > runningVal && this->hand.at(k).getNumericValue() < highSuitVal)
                            {
                                runningVal = this->hand.at(k).getNumericValue();
                            }
                        }
                        highSuitVal = runningVal;
                    }
                }
            }
        }
    }
    else if (clubCount > 4)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand.at(i).getSuit() == "Clubs")
            {
                if (this->hand.at(i).getNumericValue() > highSuitVal)
                {
                    highSuitVal = this->hand.at(i).getNumericValue();
                    runningVal = highSuitVal;
                }
            }
        }
        for (int j = 0; j < this->hand.size(); j++)
        {
            for (int i = 0; i < this->hand.size(); i++)
            {
                if (this->hand.at(i).getSuit() == "Clubs")
                {
                    if (this->hand.at(i).getNumericValue() == runningVal - 1)
                    {
                        runningVal = runningVal - 1;
                        straightCount = straightCount + 1;
                        if (straightCount >= 5)
                        {
                            if (highSuitVal == 13)
                            {
                                return "Royal Flush";
                            }
                            else
                            {
                                return "Straight Flush";
                            }
                        }
                        break;
                    }

                    if (i == this->hand.size() - 1)
                    {
                        straightCount = 1;
                        runningVal = 0;
                        for (int k = 0; k < this->hand.size(); k++)
                        {
                            if (this->hand.at(k).getNumericValue() > runningVal && this->hand.at(k).getNumericValue() < highSuitVal)
                            {
                                runningVal = this->hand.at(k).getNumericValue();
                            }
                        }
                        highSuitVal = runningVal;
                    }
                }
            }
        }
    }
    else if (diamondCount > 4)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand.at(i).getSuit() == "Diamonds")
            {
                if (this->hand.at(i).getNumericValue() > highSuitVal)
                {
                    highSuitVal = this->hand.at(i).getNumericValue();
                    runningVal = highSuitVal;
                }
            }
        }
        for (int j = 0; j < this->hand.size(); j++)
        {
            for (int i = 0; i < this->hand.size(); i++)
            {
                if (this->hand.at(i).getSuit() == "Diamonds")
                {
                    if (this->hand.at(i).getNumericValue() == runningVal - 1)
                    {
                        runningVal = runningVal - 1;
                        straightCount = straightCount + 1;
                        if (straightCount >= 5)
                        {
                            if (highSuitVal == 13)
                            {
                                return "Royal Flush";
                            }
                            else
                            {
                                return "Straight Flush";
                            }
                        }
                        break;
                    }

                    if (i == this->hand.size() - 1)
                    {
                        straightCount = 1;
                        runningVal = 0;
                        for (int k = 0; k < this->hand.size(); k++)
                        {
                            if (this->hand.at(k).getNumericValue() > runningVal && this->hand.at(k).getNumericValue() < highSuitVal)
                            {
                                runningVal = this->hand.at(k).getNumericValue();
                            }
                        }
                        highSuitVal = runningVal;
                    }
                }
            }
        }
    }
    else if (heartCount > 4)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand.at(i).getSuit() == "Hearts")
            {
                if (this->hand.at(i).getNumericValue() > highSuitVal)
                {
                    highSuitVal = this->hand.at(i).getNumericValue();
                    runningVal = highSuitVal;
                }
            }
        }
        for (int j = 0; j < this->hand.size(); j++)
        {
            for (int i = 0; i < this->hand.size(); i++)
            {
                if (this->hand.at(i).getSuit() == "Hearts")
                {
                    if (this->hand.at(i).getNumericValue() == runningVal - 1)
                    {
                        runningVal = runningVal - 1;
                        straightCount = straightCount + 1;
                        if (straightCount >= 5)
                        {
                            if (highSuitVal == 13)
                            {
                                return "Royal Flush";
                            }
                            else
                            {
                                return "Straight Flush";
                            }
                        }
                        break;
                    }

                    if (i == this->hand.size() - 1)
                    {
                        straightCount = 1;
                        runningVal = 0;
                        for (int k = 0; k < this->hand.size(); k++)
                        {
                            if (this->hand.at(k).getNumericValue() > runningVal && this->hand.at(k).getNumericValue() < highSuitVal)
                            {
                                runningVal = this->hand.at(k).getNumericValue();
                            }
                        }
                        highSuitVal = runningVal;
                    }
                }
            }
        }
    }

    /////Four of a kind
    vector<int> kindCount = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < this->hand.size(); i++)
    {
        kindCount[this->hand.at(i).getNumericValue() - 2]++;
    }
    for (int i = 0; i < 12; i++)
    {
        if (kindCount[i] >= 4)
        {
            return "Four of a Kind";
        }
    }

    //Full House
    for (int i = 0; i < 12; i++)
    {
        if (kindCount[i] == 3)
        {
            for (int j = 0; j < 12; j++)
            {
                if (kindCount[j] == 2)
                {
                    return "Full House";
                }
            }
        }
    }

    //Flush
    if (spadeCount > 4 || heartCount > 4 || diamondCount > 4 || clubCount > 4)
    {
        return "Flush";
    }

    //Straight
    highSuitVal = highVal;
    runningVal = highVal;
    straightCount = 1;
    for (int j = 0; j < this->hand.size(); j++)
    {
        for (int i = 0; i < this->hand.size(); i++)
        {
            if (this->hand.at(i).getNumericValue() == runningVal - 1)
            {
                runningVal = runningVal - 1;
                straightCount = straightCount + 1;
                if (straightCount >= 5)
                {
                    return "Straight";
                }
                break;
            }

            if (i == this->hand.size() - 1)
            {
                straightCount = 1;
                runningVal = 0;
                for (int k = 0; k < this->hand.size(); k++)
                {
                    if (this->hand.at(k).getNumericValue() > runningVal && this->hand.at(k).getNumericValue() < highSuitVal)
                    {
                        runningVal = this->hand.at(k).getNumericValue();
                    }
                }
                highSuitVal = runningVal;
            }
        }
    }


    //Three of a kind
    for(int i = 0;i<12;i++){
        if(kindCount[i]==3){
            return "Three of a Kind";
        }
    }

    //Two Pair
    for(int i = 0;i<12;i++){
        if(kindCount[i]==2){
            for(int j = 0;j<12;j++){
                if(j!=i && kindCount[j]==2){
                    return "Two Pair";
                }
            }
        }
    }

    //One Pair
    for(int i = 0;i<12;i++){
        if(kindCount[i]==2){
            return "One Pair";
        }
    }

    return "High Card";
}
