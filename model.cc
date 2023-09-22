#include <iostream>
#include <ctime>
#include <cstdlib>
#include "game.hh"
#include "player.hh"
/*
    For now test strategies for bank and not bank
    w/o bank rotation.

    Then can get into how change for n larger
*/
#define PLAYERS 2

Player players[PLAYERS];
Game game;

int main(void)
{
    // srand(time(NULL));
    game = Game(&players[0], PLAYERS, false);
    std::cout << game << std::endl;
    for (int i = 0; i < 10; i++)
    {
        game.Play();
        std::cout << game << std::endl;
        game.Flush();
    }
    return 0;
}