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
	virtual void Load(ifstream& Infile, Object_Type obj);
	virtual void Save(ofstream& OutFile, Object_Type obj);
	~CardEight(void);

};
