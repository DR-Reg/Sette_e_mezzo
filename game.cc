#include "game.hh"

Game::Game(Player *players_, uint8_t player_count_, bool rotary_)
{
    /* Keep pointer to malloced players elsewhere so can then compare with pointer in who */
    players = players_;
    player_count = player_count_;
    deck = new Deck();
    bank = 0;
    rotary = rotary_;
}

Game::Game() {}

void Game::Play()
{
    /* Plays one round of the game: goes through each player after the 'bank' and then gives bank to next person */
    uint8_t bustCount = 0;
    for (uint8_t i = 1; i < player_count; i++)
    {
        uint8_t currPlayer = bank + i;
        PlayerDecision pd;
        do {
            pd = players[currPlayer].Draw(deck->pop());
        } while (pd.type == Hit);
    }

    bank = (bank + rotary) % player_count; /* Give bank to next person if specified w/ rotary bank + mod*/
}

void Game::Flush()
{
    for (uint8_t i = 1; i < player_count; i++)
        players[i].Flush();
}


std::ostream& operator<<(std::ostream& os, const Game& g)
{
    os << "Game(" << std::endl;
    for (uint8_t i = 0; i < g.player_count; i++)
    {
        os << '\t' << g.players[i];
        if (g.bank == i) os << " (bank)";
        os << std::endl;
    }
    os << ')';
    return os;
}