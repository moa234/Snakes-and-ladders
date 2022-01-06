#include "CardTwo.h"
#include <iostream>
#include "Ladder.h"

using namespace std;

CardTwo::CardTwo(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	CardCount++;
	cardNumber = 2; 
}

void CardTwo::Save(ofstream& OutFile, Object_Type obj)
{
	if (obj != card)
		return;
	Card::Save(OutFile, obj);
	OutFile << endl;
}

CardTwo::~CardTwo()
{
	CardCount--;
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);

	CellPosition playerCellPosition = pPlayer->GetCell()->GetCellPosition();

	Ladder* pLadder = pGrid->GetNextLadder(playerCellPosition);

	if (pLadder) {
		pLadder->Apply(pGrid, pPlayer);
	}
}
