#include "PasteCard.h"
#include "Grid.h"


PasteCard::PasteCard(ApplicationManager* pApp): Action(pApp) {}


void PasteCard:: ReadActionParameters()
{
	Grid *pGrid;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the destination cell");
	Input* pIn = pGrid->GetInput();
	PasteCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();

}


void PasteCard::Execute()
{
	 Grid *pGrid;
	 Card * card;
	 Cell c(PasteCell);
	card= pGrid->GetClipboard();
 }










PasteCard::~PasteCard(){}
