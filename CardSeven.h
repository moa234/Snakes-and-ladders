#pragma once
#include "Card.h"
class CardSeven : public Card
{
	const CellPosition firstCell;
public:
	CardSeven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardSeven();
};

