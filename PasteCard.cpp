#include "PasteCard.h"
#include "Grid.h"


PasteCard::PasteCard(ApplicationManager* pApp): Action(pApp) {}


void PasteCard:: ReadActionParameters()
{
	Grid* pGrid=pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the destination cell");
	Input* pIn = pGrid->GetInput();
	PasteCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();

}


void PasteCard::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Card * card;
	 Cell c(PasteCell);
	card= pGrid->GetClipboard();
 }










PasteCard::~PasteCard(){}
