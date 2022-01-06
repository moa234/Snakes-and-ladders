#pragma once
#include "Card.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
class CardTwelve :
    public Card
{
    CellPosition CP;
public:
    CardTwelve(const CellPosition& pos);
    virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, Object_Type obj);
    ~CardTwelve();
};

