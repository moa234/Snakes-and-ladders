#pragma once
#include "Card.h"
class CardSeven : public Card
{
	const CellPosition firstCell;
public:
	CardSeven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	virtual Card* PasteCard(CellPosition newPos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream& OutFile, Object_Type obj);

	virtual ~CardSeven();
};

