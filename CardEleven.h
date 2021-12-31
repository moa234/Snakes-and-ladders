#pragma once
#include "Card.h"
class CardEleven :
    public Card
{
    CellPosition CP;
    static int Purchase_Price;
    static int Fees_Pay;
    static Player* owner;
public:
    CardEleven(const CellPosition& pos);
    static int GetPrice();
    static void set_owner(Player* pPlayer);
    static bool isOwner(const Player* Check_Owner); // checks that the send player is the owner of the card or not
    virtual void ReadCardParameters(Grid* pGrid);
    virtual void Apply(Grid* pGrid, Player* pPlayer);
    virtual ~CardEleven();
};
Player* CardEleven::owner = NULL;
