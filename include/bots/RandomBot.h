#pragma once
#include "../Bot.h"
#include <random>

class RandomBot : public Bot
{
    public:
    //constructor
    RandomBot() = default;

    //deconstructor
    virtual ~RandomBot() = default;

    virtual Card makeAction(const Observation& obs, const IntMatrix& legal) override;
    Card chooseRandom(const IntMatrix& legal);
};