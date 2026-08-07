#pragma once
#include <memory>
#include "types.h"
#include "bot.h"

class Player
{
    //class need private and public, 
    //In private , ID, pointer to bot, hand, and next pointer for incrementing
    private:
    int ID;
    IntMatrix hand;
    std::unique_ptr<Bot> controller;
    static int nextID;

    //In public, 
    Player(std::unique_ptr<Bot> bot);
    ~Player()=default;
    Card makeAction(const Observation& obs, const Legal& legal);
    void addCard(const Card& card);
    void removeCard(const Card& card);
    int getId() const;
    //additionally a getter function for get hand
    const IntMatrix& getHand() const;
};