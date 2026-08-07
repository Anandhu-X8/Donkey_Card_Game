#pragma once
#include <vector>

struct Card
{
    int rank;
    int suit;
    Card()=default;
    Card(int s, int r) // suit is first
    {
        rank=r;
        suit =s;
    }
};

using IntMatrix = std::vector<std::vector<int>>;
using IntVector = std::vector<int>;


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