#pragma once
#include "card.h"
class CardFour :
	public Card
{
public:
	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, Object_Type obj);
	virtual Card* PasteCard();
	~CardFour(void);
};