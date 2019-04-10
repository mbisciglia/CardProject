#pragma once
#include <iostream>
#include "card.h"
#include <vector>
#include <string>

using namespace std;

class pokerEvaluator
{
public:
    pokerEvaluator(vector <Card> hand); 

    void sortHand();   

    string getBestHand();

private:
vector <Card> hand;
};
