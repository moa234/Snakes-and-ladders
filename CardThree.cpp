#include "CardThree.h"


CardThree::CardThree(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; 
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{ 
	Card::Apply(pGrid, pPlayer);// output card num...

	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You won an extra dice roll!" );
	pPlayer->SetDoNotPlay(5);
	pOut->ClearStatusBar();
	/*
	ActionType ActType=;
	ApplicationManager AppManager;
	AppManager.ExecuteAction(ActType);
	AppManager.UpdateInterface();
	*/

}

CardThree::~CardThree(void)
{
}
