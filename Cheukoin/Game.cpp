#include "Game.h"
#include "Bot.h"
#include "Team.h"
#include "Lobby.h"
#include "Player.h"
#include "Human.h"
#include "Rules.h"

using namespace std;

Game::Game(Lobby& lobby, GameMode const& mode)
    : _lobby(lobby)
    , _mode(mode)
    , _bid(Bid())
    , _currentRound(0)
    , _tricks(vector<Trick>())
    , _currentPlayer(0)
{
    _rules = make_shared<Rules>(_bid.getSuit());
}

void Game::startGame()
{
    _lobby.deal();

    // FOR TEST PURPOSE
    _bid.setAmount(120);
    _bid.setSuit(Spades);

    for (shared_ptr<Bot> bot : getBots()) {
        bot->initialize();
    }
    for (auto player : _lobby.getPlayers()) {
        player->initialize();
    }
}

void Game::play()
{
    if (_currentPlayer == 0) {
        if (_currentRound > 7) {
            cout << "Game finished!" << endl;
            return;
        }

        cout << "Playing round " << _currentRound << endl;

        Trick trick(_currentRound);
        _tricks.push_back(trick);
        _currentRound++;
    }
    _lobby.getPlayers()[_currentPlayer]->play();
    if (_lobby.getPlayers()[_currentPlayer]->getCards().size() == 8 - _currentRound) {
        _currentPlayer++;
        _currentPlayer %= 4;
    }
    for (auto bot : getBots()) {
        bot->update();
    }
}

GameMode Game::getMode()
{
    return _mode;
}

Lobby& Game::getLobby()
{
    return _lobby;
}

void Game::setBid(Bid const& bid)
{
    _bid = bid;
}

Bid Game::getBid()
{
    return _bid;
}

void Game::addTrick(Trick const& trick)
{
    _tricks.push_back(trick);
}

Trick& Game::getCurrentTrick()
{
    return _tricks.back();
}

vector<shared_ptr<Bot> > Game::getBots()
{
    vector<shared_ptr<Bot> > bots;
    for (auto player : _lobby.getPlayers()) {
        auto bot = dynamic_pointer_cast<Bot>(player);
        if (bot) {
            bots.push_back(bot);
        }
    }

    return bots;
}

void Game::draw()
{
    for (auto player : _lobby.getPlayers()) {
        player->drawCards();
    }

    if (_tricks.size() > 0) {
        _tricks.back().draw();
    }
}