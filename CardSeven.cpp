#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) :Card(pos), firstCell(1)
{
	cardNumber = 7;
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	
	if (pGrid->GetNextPlayer(position))
	{
		pGrid->UpdatePlayerCell(pGrid->GetNextPlayer(position), firstCell);
	}
}

CardSeven::~CardSeven()
{
}
