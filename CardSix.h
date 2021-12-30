#pragma once
#include "card.h"
class CardSix : public Card
{
	CellPosition CP;  // the position that the player will move to 

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardSix which is: cell position to move to

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardSix on the passed Player
													// if there is a gameobject its effect will be implemented
													  
	virtual ~CardSix(); // A Virtual Destructor
};
