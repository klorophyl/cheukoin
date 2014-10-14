#ifndef __Cheukoin_Card__
#define __Cheukoin_Card__

#include <math.h>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Game.h"
#include "ResourcePath.h"

class Card {
public:
    Card(Suit suit, Value value);
    ~Card();

    std::shared_ptr<sf::Sprite> sprite;
    std::shared_ptr<sf::Texture> texture;

    Value getValue() const;
    Suit getSuit() const;
    sf::Texture getTexture() const;

    void draw() const;

    void flip();
    void moveTo(float x, float y);

private:
    Suit _suit;
    Value _value;
    sf::Vector2u _size;

    std::string _getFilename();
};

bool operator==(Card const& a, Card const& b);
bool operator!=(Card const& a, Card const& b);

std::ostream& operator<<(std::ostream& os, const Card& card);

#endif