#pragma once
#include "player.hh"
#include "deck.hh"

class Game
{
private:
    Player *players;
    Deck *deck;
    uint8_t player_count;
    uint8_t bank;
    bool rotary;
public:
    Game(Player *players_, uint8_t player_count_, bool rotary_);
    Game();
    void Play();
    void Flush();
    friend std::ostream& operator<<(std::ostream& os, const Game& g);
};