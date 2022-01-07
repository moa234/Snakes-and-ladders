#pragma once

#include "Card.h"

class CardTwo :	public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardTwo(const CellPosition & pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	virtual void Save(ofstream& OutFile, Object_Type obj);
	virtual	Card* PasteCard();
	virtual ~CardTwo(); // A Virtual Destructor
};
