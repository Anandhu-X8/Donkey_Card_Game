#include "bots/RandomBot.h"
#include <random>

/*
note that the bot doesn't have to do any checking
it is all done by the engine. the bot simply has to choose a card among the legal ones given (by engine)
*/

Card RandomBot::chooseRandom(const IntMatrix& legal)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<std::pair<int,int>> ones;
    for(int suit=0; suit<4; suit++)
    {
        for(int rank=0; rank<13; rank++)
        {
            if(legal[suit][rank]==1)
            {
                ones.emplace_back(suit,rank); // to make it a pair
            }
        }
    }

    // now a random card form ones
    std::uniform_int_distribution<> dist(0, ones.size()-1);
    auto choice=ones[dist(gen)];
    Card card(choice.first, choice.second); // suit first
    return card;
}
// actually choose a card
Card RandomBot::makeAction(const Observation& obs, const IntMatrix& legal)
{
    Card choice = chooseRandom(legal);
    return choice;
}
