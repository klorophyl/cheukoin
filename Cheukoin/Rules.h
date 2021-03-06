//
//  Rules.h
//  Cheukoin
//
//  Created by Adrien Bruchet on 08/10/14.
//  Copyright (c) 2014 Corentin. All rights reserved.
//

#ifndef __Cheukoin__Rules__
#define __Cheukoin__Rules__

#include <map>

#include "Card.h"
#include "Trick.h"
#include "Team.h"
#include "Player.h"
#include "Constants.h"
#include "Game.h"
#include "Lobby.h"

class Rules {
public:
    Rules(Suit asset); // LJ : Je ne suis pas certain du vocabulaire asset pour désigner l'atout. J'ai toujours vu le mot trump pour ça.
    ~Rules();

    bool isTrickValid(Trick trick);
    bool isTeamValid(Team team);

    static std::vector<Card> cardsForSuit(std::vector<Card> cards, Suit suit);
    inline Suit getAsset() { return _asset; };
    void setAsset(Suit asset); // LJ : Inutile, cette information est déjà passée dans le constructeur

    static const std::map<Value, int> CardValues;
    static const std::map<Value, int> CardValuesAsset;

private:
    Suit _asset;
};

#endif /* defined(__Cheukoin__Rules__) */
