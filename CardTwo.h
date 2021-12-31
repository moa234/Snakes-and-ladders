#pragma once

#include "Card.h"

class CardTwo :	public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardTwo(const CellPosition & pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	
	virtual ~CardTwo(); // A Virtual Destructor
};
