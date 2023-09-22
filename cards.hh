#pragma once
#include <iostream>
#include <string>

enum Suit
{
    Swords,
    Cups,
    Coins,
    Batons
};
enum CardFace
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Knave,
    Knight,
    King
};


class Card
{
private:
    Suit suit;
    float value;
    CardFace face;
public:
    Card(Suit s, CardFace f);
    Card(Card &c);
    friend std::ostream& operator<<(std::ostream& os, const Card& c);

    float GetValue();
    CardFace GetFace();
    Suit GetSuit();

    static float GetValue(CardFace f);
    static std::string GetFace(CardFace f);
    static std::string GetSuit(Suit s);
};