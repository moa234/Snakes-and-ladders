#pragma once
#include "card.h"
class CardEight :
	public Card
{
		int Bail; // the wallet value to decrease from the player if he chose to
public:

	CardEight(const CellPosition & pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void ReadCardParameters(Grid * pGrid);

	~CardEight(void);

};
