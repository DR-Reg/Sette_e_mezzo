#include "player.hh"

Player::Player()
{
    card_count = 0;
}

PlayerDecision Player::Draw(Card *card)
{
    cards[card_count] = new Card(*card);
    card_count++;

    float score = GetScore();
    if (score > 7.5)
        return { score, GoBust };
    else if (score >= 4.5)
        return { score, Stand };

    // TODO: play.../ calculate if gone bust
    return { score, Hit };
}

void Player::Flush()
{
    card_count = 0;
}

float Player::GetScore() const
{
    float score = 0;
    for (uint8_t i = 0; i < card_count; i++)
        score += cards[i]->GetValue();
    return score;
}

const Card **Player::GetHand() const
{
    // addr of first -> point as arr contig
    return (const Card **)(&cards[0]);
}

uint8_t Player::GetCardCount() const
{
    return card_count;
}

std::ostream& operator<<(std::ostream& os, const Player& p)
{
    os << "Player(" << p.GetScore() << ',';
    const Card **cs = p.GetHand();
    uint8_t ccount = p.GetCardCount();
    for (uint8_t i = 0; i < ccount - 1; i++)
        os << *cs[i] << ", ";
    if (ccount > 0)
        os << *cs[ccount - 1];
    os << ')';
    return os;
}