#include "deck.hh"

void Deck::BuildDeck(Card **cards_arr)
{
    for (int f = 0; f < 10; f++)
        for (int s = 0; s < 4; s++)
            cards_arr[f * 4 + s] = new Card((Suit)s, (CardFace)f);
}

void Deck::Shuffle(Card **cards_arr, int max_iter)
{
    for (int i = 0; i < max_iter; i++)
    {
        int ridx1 = rand() % 40;
        int ridx2 = rand() % 40;
        Card *tmp = cards_arr[ridx1];
        cards_arr[ridx1] = cards_arr[ridx2];
        cards_arr[ridx2] = tmp;
    }
}

Card *Deck::pop()
{
    for (int i = 0; i < 40; i++)
    {
        if (cards[i] != NULL)
        {
            Card *ret = cards[i];
            cards[i] = NULL;
            return ret;
        }
    }
    return NULL;
}

Deck::Deck()
{
    Deck::BuildDeck(cards);
    Deck::Shuffle(cards, 100);
}