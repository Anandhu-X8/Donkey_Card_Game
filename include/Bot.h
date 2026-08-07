#pragma once

#include "types.h"
#include <vector>

class Bot
{
    public:
    //constructor
    Bot() = default;

    // virtual is used to give priority to child object over parent one
    //deconstructor
    virtual ~Bot() = default;

    //main function to be called by engine; =0 gives responsibility of definition to child
    virtual Card makeAction(const Observation& obs, const Legal& legal)=0;

};

//bot.cpp is unnecessary. 
