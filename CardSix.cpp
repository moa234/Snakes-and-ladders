#include "CardSix.h"
#include "Card.h"


CardSix:: CardSix(const CellPosition& pos):Card(pos) // A Constructor takes card position
{
	cardNumber = 6;
}
 void CardSix:: ReadCardParameters(Grid* pGrid)// Reads the parameters of CardSix which is: cell position to move to
{
	 Input* pIn = pGrid->GetInput();
	 Output* pOut = pGrid->GetOutput();
	 pOut->PrintMessage("Enter cell number to move player to: ");
	 int cellnum = pIn->GetInteger(pOut);
	 while (cellnum < 0 || cellnum>99)
	 {
		 pGrid->PrintErrorMessage("Error! Please Enter Cell Number between 1 and 99! click anywhere to continue");
		 pOut->PrintMessage("Re-Enter Cell Number: ");
		 cellnum = pIn->GetInteger(pOut);
	 }
	 CP = CellPosition(cellnum);
}
 void CardSix::Apply(Grid* pGrid, Player* pPlayer) // Applies the effect of CardSix on the passed Player
												// if there is a gameobject its effect will be implemented
 {
	 pGrid->UpdatePlayerCell(pPlayer,CP);
	 GameObject* Object = pGrid->CurrentCellObject(CP);
	 if (!Object) //if the  player moved to cell contains an object
	 {
		 Object->Apply(pGrid,pPlayer); //apply the effect of this object
	 }
 }

 CardSix:: ~CardSix()
 {

  }