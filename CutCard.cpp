#include "CutCard.h"
#include "Grid.h"

CutCard::CutCard(ApplicationManager* pApp):Action(pApp) {}

void CutCard::ReadActionParameters()
 {
	Grid *pGrid;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the source cell to Cut");
	Input* pIn;
	CutCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
 }
void CutCard::Execute() 
{
	 Grid *pGrid;
	 Card * card;
	 Cell c(CutCell);
	 card=c.HasCard();
	 pGrid->SetClipboard(card);
	 const CellPosition cc(CutCell);
	 pGrid->RemoveObjectFromCell(cc);
}
	 
CutCard::~CutCard(){}
