#include "CardFive.h"
#include <iostream>

using namespace std;
CardFive::CardFive(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	CardCount++;
	cardNumber = 5; 
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
}


void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
		
 Card::Apply(pGrid, pPlayer);
	int diceValueRolled = pPlayer->GetRolledDiceNum();

	CellPosition playerCellPosition = pPlayer->GetCell()->GetCellPosition();
	playerCellPosition.AddCellNum(-1 * diceValueRolled);
	pGrid->UpdatePlayerCell(pPlayer, playerCellPosition);
 GameObject* Object = pGrid->CurrentCellObject(playerCellPosition);
	 if (Object) //if the  player moved to cell contains an object
	 {
		 Object->Apply(pGrid,pPlayer); //apply the effect of this object
	 }
}

void CardFive::Save(ofstream& OutFile, Object_Type obj)
{
	if (obj != card)
		return;
	Card::Save(OutFile, obj);
	OutFile << endl;
}

CardFive::~CardFive(){
	CardCount--;
}



