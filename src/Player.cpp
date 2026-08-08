#include "Player.h"
int Player::nextID=0;
Player::Player(std::unique_ptr<Bot> bot)
:
 ID(nextID++),
 controller(std::move(bot))
{}
Card Player::makeAction(const Observation& obs, const Legal& legal)
{
    return controller->makeAction(obs, legal);
}
void Player::addCard(const Card& card)
{
    int suit=card.suit;
    int rank=card.rank;
    hand[suit][rank]=1;
}
void Player::addCards(const CardVector& pile)
{
    for(auto card: pile)
    {
        addCard(card);
    }
}
void Player::removeCard(const Card& card)
{
    int suit=card.suit;
    int rank=card.rank;
    hand[suit][rank]=0;
}
int Player::getId() const
{
    return ID;
}
const IntMatrix& Player::getHand() const
{
    return hand;
}
