//
//  Lobby.cpp
//  Cheukoin
//
//  Created by Corentin on 10/16/14.
//  Copyright (c) 2014 Corentin. All rights reserved.
//

#include "Lobby.h"

using namespace std;

Lobby::Lobby(string const& name, vector<Team> const& teams)
    : _name(name)
    , _teams(teams)
{
}

void Lobby::deal()
{
    vector<Card> cards = Card::getAllCardsShuffled();

    int i = 0;
    for (Card card : cards) {
        getPlayers()[i % 4]->addCard(card);
        i++;
    }
    cout << getPlayers()[0]->getCards().size() << endl;
}

string Lobby::getName() const
{
    return _name;
}

void Lobby::setName(string const& name)
{
    _name = name;
}

vector<shared_ptr<Player>> Lobby::getPlayers()
{
    vector<shared_ptr<Player>> players = {
        _teams[0].getPlayers()[0],
        _teams[0].getPlayers()[1],
        _teams[1].getPlayers()[0],
        _teams[1].getPlayers()[1]
    };
    
    return players;
}

Lobby::~Lobby()
{
}