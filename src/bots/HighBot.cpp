#include "Bots/HighBot.h"

Card HighBot::makeAction(const Observation& obs, const IntMatrix& legal)
{
    Card choice(-1,-1); // ideally this shouldn't be returned. engine must prevent this(finished player!)
    // print highest card from legal
    for(int rank = 12; rank>=0; rank--)
    {
        for(int suit=0; suit<4; suit++)
        {
            if(legal[rank][suit]==1)
            // we found the card
            {
                choice.suit=suit;
                choice.rank=rank;
            }
        }
    }
    return choice;
}
