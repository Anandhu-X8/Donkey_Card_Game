#pragma once
#include <vector>
#include <array>

struct Card
{
    int suit;
    int rank;
    Card()=default;
    Card(int s, int r) // suit is first
    {
        // card(2,9)(1,10). so onn
        suit =s;
        rank=r;
    }
};

// we need a vector of cards -> Pile
using CardVector = std::vector<Card>;

using Deck = std::array<std::array<int, 13>,4>;
using IntVector = std::vector<int>;

struct Legal
{
    Deck legalcards;
    bool cut;

    Legal()=default;
    Legal(Deck matrix, bool bl)
    :legalcards(matrix), cut(bl)
    {}
};
struct Observation
{
    Deck RevealedInfo; // pass the public information
    Card LeadingCard;
    bool IsLeading;

    Observation()
    // default cons is to just follow suit
    : RevealedInfo(4, std::vector<int>(13,0)),
    IsLeading(false)
    {}
};
