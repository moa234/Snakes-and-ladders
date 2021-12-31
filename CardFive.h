#pragma once

#include "Card.h"

class CardFive : public Card {
    int roll;

public:
    CardFive(const CellPosition& pos);
    virtual void Apply(Grid* pGrid, Player* pPlayer);
    ~CardFive();

};