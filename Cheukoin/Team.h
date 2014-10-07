#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Trick.h"

class Team
{
public:
	Team();
    Team(std::string name);
	~Team();
    void addPlayer(Player const& player);
    void addTrick (Trick const& trick);
    void setScore(int const& newScore);
    void addScore(int const& score);
    int getScore();
    std::vector<Trick> getTricks();
    
    

private:
	std::string _name;
    std::vector<Player> _players;
    int _score;
    std::vector<Trick> _wonTricks;
    

};
