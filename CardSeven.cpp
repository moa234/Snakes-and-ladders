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
	Player* next = pGrid->GetNextPlayer(position);
	if (next)
	{
		CellPosition nextpos = next->GetCell()->GetCellPosition();
		for (int i = 0; i < 4; i++)
		{
			Player* another = pGrid->CheckCurrentCellPlayer(nextpos, i);
			if (another)
			{
				pGrid->UpdatePlayerCell(another,firstCell)  ;
			}
			
		}
	}
}

CardSeven::~CardSeven()
{
}
