#include <string>
#include "Bid.h"
#include "Hand.h"

class Player {
public:
    Player();
    ~Player();

    void playCard(Card card);
    Bid makeBid(int amount, std::string asset);

    std::string getName();
    void setName(std::string name);
    Hand getHand();
    void setHand(Hand hand);
    Bid getBid();
    void setBid(Bid bid);

private:
    std::string _name;
    Hand _hand;
    Bid _bid;
};
