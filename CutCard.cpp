#include "CutCard.h"
#include "Grid.h"

CutCard::CutCard(ApplicationManager* pApp):Action(pApp) {}

void CutCard::ReadActionParameters()
 {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the source cell to Cut");
	Input* pIn = pGrid->GetInput();
	CutCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
 }
void CutCard::Execute() 
{
	Grid* pGrid = pManager->GetGrid();
	 Card * card1;
	 Cell c(CutCell);
	 card1=c.HasCard();
	 pGrid->SetClipboard(card1);
	 const CellPosition cc(CutCell);
	 pGrid->RemoveObjectFromCell(cc);
}
	 
CutCard::~CutCard(){}
