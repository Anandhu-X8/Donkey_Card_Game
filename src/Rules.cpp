#include "Rules.h"

Legal Rules::FindLegal(IntMatrix hand, Card leadcard) // if leading, no need for legality
{
    int suit = leadcard.suit;
    for (int rank =0; rank<13; rank++)
    {
        if(hand[suit][rank]==1) // there is a card to follow suit, no need to cut
        {
            for(int i_suit=0; i_suit<4; i_suit++)
            {
                if (i_suit==suit) continue;
                std::fill(hand[i_suit].begin(), hand[i_suit].end(), 0);
            }
            Legal output(hand, false);
            return output; // only returns the lead suit cards
        }
    }
    // no suit card, need to cut
    // cut = true
    Legal output(hand, true);
    return output;
}
