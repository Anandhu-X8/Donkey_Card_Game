#pragma once
#include "../Bot.h"

class LowBot : public Bot
{
    public:
    //constructor
    LowBot() = default;

    //deconstructor
    virtual ~LowBot() = default;

    virtual Card makeAction(const Observation& obs, const IntMatrix& legal) override;
};