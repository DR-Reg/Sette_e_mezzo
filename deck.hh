#pragma once
#include "cards.hh"
#include <stdlib.h>

class Deck
{
private:
    Card *cards[40];
public:
    Deck();
    Card *pop();
    
    static void Shuffle(Card **cards_arr, int max_iter);
    static void BuildDeck(Card **cards_arr);
};