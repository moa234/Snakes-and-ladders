#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) :Card(pos)
{
	CardCount++;
	cardNumber = 7;
}
const CellPosition CardSeven::firstCell(1);

void CardSeven::ReadCardParameters(Grid* pGrid)
{
}

Card* CardSeven::PasteCard()
{
	Card* copy = new CardSeven(0);
	return copy;
}

Card* CardSeven::CopyCard()
{
	CardSeven* copy = new CardSeven(0);
	CardCount--;
	return copy;
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

void CardSeven::Save(ofstream& OutFile, Object_Type obj)
{
	if (obj != card)
		return;
	Card::Save(OutFile, obj);
	OutFile << endl;
}

CardSeven::~CardSeven()
{
	CardCount--;
}
