#include "CutCard.h"
#include "Grid.h"
#include "Card.h"

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
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	Card* card = pGrid->CurrentCellCard(CutCell)->PasteCard();
	pGrid->SetClipboard(card);

	 const CellPosition cc(CutCell);
	 pGrid->RemoveObjectFromCell(cc);
}
	 
CutCard::~CutCard(){}
