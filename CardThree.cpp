#include "CardThree.h"


CardThree::CardThree(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	CardCount++;
	cardNumber = 3; 
}
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{ 
	Card::Apply(pGrid, pPlayer);// output card num...

	Output* pOut = pGrid->GetOutput();
	pGrid->PrintErrorMessage("You won an extra dice roll! click to continue" );
	pPlayer->SetDoNotPlay(-1);
	//pGrid->Replay();
	pOut->ClearStatusBar();
	/*
	ActionType ActType=;
	ApplicationManager AppManager;
	AppManager.ExecuteAction(ActType);
	AppManager.UpdateInterface();
	*/

}

Card* CardThree::PasteCard(CellPosition newPos)
{
	Card* copy = new CardThree(newPos);
	*copy = *this;
	return copy;
}
void CardThree::Save(ofstream& OutFile, Object_Type obj)
{
	if (obj != card)
		return;
	Card::Save(OutFile, obj);
	OutFile  << endl;
}

CardThree::~CardThree(void)
{
	CardCount--;
}