#pragma once
#include <vector>

struct Card
{
    int rank;
    int suit;
    Card()=default;
    Card(int s, int r) // suit is first
    {
        suit =s;
        rank=r;
    }
};

// we need a vector of cards -> Pile
using CardVector = std::vector<Card>;

using IntMatrix = std::vector<std::vector<int>>;
using IntVector = std::vector<int>;

struct Legal
{
    IntMatrix legalcards;
    bool cut;

    Legal()=default;
    Legal(IntMatrix matrix, bool bl)
    :legalcards(matrix), cut(bl)
    {}
};
struct Observation
{
    IntMatrix RevealedInfo; // pass the public information
    Card LeadingCard;
    bool IsLeading;
    bool Cut;

    Observation()
    : RevealedInfo(4, std::vector<int>(13,0)),
    IsLeading(false),
    Cut(false)
    {}
};
