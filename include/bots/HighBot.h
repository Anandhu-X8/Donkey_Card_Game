#pragma once
#include "../Bot.h"

class HighBot : public Bot
{
    public:
    //constructor
    HighBot() = default;

    //deconstructor
    virtual ~HighBot() = default;

    virtual Card makeAction(const Observation& obs, const IntMatrix& legal) override;
};