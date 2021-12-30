#pragma once
#include "Card.h"
class CardEleven :
    public Card
{
    int Purchase_Price;
    int Fees_Pay;
    const Player* owner;
public:
    CardEleven();
    int GetPrice(int);
    void set_owner(Player* pPlayer);
    virtual void ReadCardParameters(Grid* pGrid);
    virtual void Apply(Grid* pGrid, Player* pPlayer);
    virtual ~CardEleven();
};

