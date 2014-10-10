#ifndef __Cheukoin_Hand__
#define __Cheukoin_Hand__

#include <vector>
#include "Card.h"
#include <iostream>
#include "Game.h"

class Hand {
public:
    void removeCard(Card const& card);
    void addCard(Card const& card);
    void displayCards(std::ostream& flux) const;
    std::vector<Card> getCards();
    bool isHandValid();

    Hand();
    ~Hand();

private:
    std::vector<Card> _cards;
};

std::ostream& operator<<(std::ostream& flux, Hand const& hand);

#endif