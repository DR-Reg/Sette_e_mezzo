#include "cards.hh"

Card::Card(Suit s, CardFace f)
{
    suit = s;
    face = f;
    value = Card::GetValue(f);
}

float Card::GetValue(CardFace f)
{
    switch (f)
    {
        case Ace:
        case Two:
        case Three:
        case Four:
        case Five:
        case Six:
        case Seven:
            return f + 1;
        case Knave:
            return 0.5;
        case Knight:
            return 0.5;
        case King:
            return 0.5;
    }
}
float Card::GetValue()
{
    return Card::GetValue(face);
}
std::string Card::GetFace(CardFace f)
{
    switch (f)
    {
        case Ace:
            return "Ace";
        case Two:
        case Three:
        case Four:
        case Five:
        case Six:
        case Seven:
            return std::string(1, (char)(f + 49));
        case Knave:
            return "Knave";
        case Knight:
            return "Knight";
        case King:
            return "King";
        default:
            return "Unknown";
    }
}

std::string Card::GetSuit(Suit s)
{
    switch (s)
    {
        case Swords: return "Swords";
        case Cups: return "Cups";
        case Coins: return "Coins";
        case Batons: return "Batons";
        default: return "Unkown";
    }
}
CardFace Card::GetFace()
{
    return face;
}
Suit Card::GetSuit()
{
    return suit;
}
Card::Card(Card &c)
{
    face = c.face;
    suit = c.suit;
    value = c.value;
}

std::ostream& operator<<(std::ostream& os, const Card& c)
{
    os << Card::GetFace(c.face) << " of " << Card::GetSuit(c.suit);
    return os;
}