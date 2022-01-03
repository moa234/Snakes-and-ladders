#include "CopyCard.h"
#include "Grid.h"

CopyCard::CopyCard(ApplicationManager* pApp): Action(pApp) {}

 void CopyCard::ReadActionParameters()
 {
	Grid *pGrid;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the source cell to copy");
	Input* pIn = pGrid->GetInput();
	CopiedCell = pIn->GetCellClicked();
	pOut->ClearStatusBar();
 }
 void	CopyCard:: Execute() 
 {
	 Grid *pGrid;
	 Card * card;
	 Cell c(CopiedCell);
	 card=c.HasCard();
	 pGrid->SetClipboard(card);
 }
CopyCard::~CopyCard() {}