#include "CardSix.h"


CardSix:: CardSix(const CellPosition& pos):Card(pos) // A Constructor takes card position
{
	cardNumber = 6;
}
 void CardSix:: ReadCardParameters(Grid* pGrid)// Reads the parameters of CardSix which is: cell position to move to
{
	 Input* pIn = pGrid->GetInput();
	 Output* pOut = pGrid->GetOutput();
	 pOut->PrintMessage("Select cell number to move player to: ");
	 CellPosition Cell_selected = pIn->GetCellClicked();
	 pOut->PrintMessage("You have selected cell number " + to_string(Cell_selected.GetCellNum()) + " are you sure(y/n)? ");
	 string answer = pIn->GetString(pOut);
	 while (answer == "n" || answer == "N") //double check on user input
	 {
		 pOut->PrintMessage("Re-select card postion on the grid");
		 Cell_selected = pIn->GetCellClicked();
		 pOut->PrintMessage("You have selected cell number " + to_string(Cell_selected.GetCellNum()) + " are you sure(y/n)? ");
		 answer = pIn->GetString(pOut);
	 }
	 CP = Cell_selected;
	 pOut->ClearStatusBar();
}
 void CardSix::Apply(Grid* pGrid, Player* pPlayer) // Applies the effect of CardSix on the passed Player
												// if there is a gameobject its effect will be implemented
 {
	 Card::Apply(pGrid, pPlayer);
	 pGrid->UpdatePlayerCell(pPlayer,CP);
	 GameObject* Object = pGrid->CurrentCellObject(CP);
	 if (Object) //if the  player moved to cell contains an object
	 {
		 Object->Apply(pGrid,pPlayer); //apply the effect of this object
	 }
 }

 CardSix:: ~CardSix()
 {

  }