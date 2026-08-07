#include "bots/RandomBot.h"

/*
note that the bot doesn't have to do any checking
it is all done by the engine. the bot simply has to choose a card among the legal ones given (by engine)
*/

Card RandomBot::chooseRandom(const IntMatrix& legal)
{
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
    std::pair<int,int> choice = ones[rand()%ones.size()];
    Card card(choice.first, choice.second); // suit first
    return card;
}
// actually choose a card
Card RandomBot::makeAction(const Observation& obs, const IntMatrix& legal)

{
    Card choice = chooseRandom(legal);
}