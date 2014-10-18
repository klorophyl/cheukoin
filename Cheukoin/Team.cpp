#include "Team.h"

using namespace std;

Team::Team()
    : _name("Thomas Mollard")
    , _score(0)
{
}

Team::Team(string name)
    : _name(name)
    , _score(0)
{
}

Team::~Team()
{
}

void Team::addPlayer(Player const& player)
{
    if (_players.size() > 1) {
    }
    else {
        _players.push_back(player);
    }
}

void Team::addTrick(Trick const& trick)
{
    _wonTricks.push_back(trick);
}

void Team::setScore(int const& newScore)
{
    _score = newScore;
}

void Team::addPoints(int const& score)
{
    _score += score;
}

int Team::getScore()
{
    return _score;
}

vector<Trick> Team::getTricks()
{
    return _wonTricks;
}

std::vector<Player> Team::getPlayers() const
{
    return _players;
}

bool Team::isTeamDealing()
{
    bool dealing = false;
    for (auto p : _players) {
        if (p.isDealer()) {
            dealing = true;
        }
    }
    return dealing;
}