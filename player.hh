#include "cards.hh"
#include <iostream>
#include <cstdint>
#pragma once

enum PlayerDecisionType
{
    Stand,
    Hit,
    GoBust
};

struct PlayerDecision
{
    float score;
    PlayerDecisionType type;
};

class Player
{
private:
    Card *cards[40]; // never full
    uint8_t card_count;
public:
    Player();

    friend std::ostream& operator<<(std::ostream& os, const Player& c);
    PlayerDecision Draw(Card *card);
    const Card **GetHand() const;
    uint8_t GetCardCount() const;
    float GetScore() const; // -1 if bust
    void Flush();
};