#ifndef __Cheukoin_Bot__
#define __Cheukoin_Bot__

#include <map>
#include <string>
#include "Player.h"

class Bot : public Player {
public:
    Bot();
    ~Bot();

    void play();
    Card chooseCard();
    void guessHands();

private:
    std::vector<Card> _remainingCardsInGame;
    std::vector<Card> _remainingAssets;
    std::map<Card, std::map<Player, float> > _cardProbability;
};

#endif