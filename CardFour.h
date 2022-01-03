#pragma once
#include "card.h"
class CardFour :
	public Card
{
public:
	CardFour(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	
	~CardFour(void);
};