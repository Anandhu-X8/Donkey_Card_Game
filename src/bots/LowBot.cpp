
#include "bots/LowBot.h"

Card LowBot::makeAction(const Observation& obs, const IntMatrix& legal)
{
    Card choice(-1,-1); // ideally this shouldn't be returned. engine must prevent this(finished player!)
    // print highest card from legal
    for(int rank = 0; rank<13; rank++)
    {
        for(int suit=0; suit<4; suit++)
        {
            if(legal[suit][rank]==1)
            // we found the card
            {
                choice.suit=suit;
                choice.rank=rank;
            }
        }
    }
    return choice;
}
