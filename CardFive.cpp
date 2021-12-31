#include "CardFive.h"
#include <iostream>

using namespace std;
CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}


void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	int diceValueRolled = pPlayer->GetRolledDiceNum();

	CellPosition playerCellPosition = pPlayer->GetCell()->GetCellPosition();
	playerCellPosition.AddCellNum(-1 * diceValueRolled);
	pGrid->UpdatePlayerCell(pPlayer, playerCellPosition);
}