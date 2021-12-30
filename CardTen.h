#pragma once
#include "Card.h"
class CardTen :
    public Card
{
    int Purchase_Price;
    int Fees_Pay;
    const Player* owner;
public:
    CardTen();
    int GetPrice(int);
    void set_owner(Player* pPlayer);
    virtual void ReadCardParameters(Grid* pGrid);
    virtual void Apply(Grid* pGrid, Player* pPlayer);
    virtual ~CardTen();
};

