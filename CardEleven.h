#pragma once
#include "Card.h"
class CardEleven :public Card
{
    CellPosition CP;
    static int Purchase_Price;
    static int Fees_Pay;
    static Player* owner;
    static bool isSet;
public:
   CardEleven(const CellPosition& pos);
   static int GetPurchasePrice();
   static void SetPurchasePrice(static int Purchase_Price);
   static int GetFeesPrice();
   static void SetFeesPrice(static int Fees_Pay);
   static void SetOwner(Player *Owner);
   static bool isOwner(const Player* Check_Owner); // checks that the send player is the owner of the card or not
   static Player* GetOwner();
    virtual void ReadCardParameters(Grid* pGrid);
    virtual void Apply(Grid* pGrid, Player* pPlayer);
    virtual ~CardEleven();
};
Player* CardEleven::owner = NULL;
