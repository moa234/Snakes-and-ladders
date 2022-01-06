#include "CopyCard.h"
#include "Grid.h"

CopyCard::CopyCard(ApplicationManager* pApp): Action(pApp) {}

 void CopyCard::ReadActionParameters()
 {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the source cell to copy");
	Input* pIn = pGrid->GetInput();
	CopiedCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
 }
 void	CopyCard:: Execute() 
 {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* card =pGrid->CurrentCellCard(CopiedCell);
	pGrid->SetClipboard(card);

	 /*Grid* pGrid = pManager->GetGrid();
	 CellPosition * card = CopiedCell;
	 pGrid->SetClipboard(card);*/
 }
CopyCard::~CopyCard() {}
