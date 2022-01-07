#include "CopyCard.h"
#include "Grid.h"
#include "card.h"

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
	if (!CopiedCell.IsValidCell())
	{
		pGrid->PrintErrorMessage("invalid cell to copy! click to continue. . . . . .");
		return;
	}
	Card* card = pGrid->CurrentCellCard(CopiedCell);
	if (card)
	{
		card = card->CopyCard();
	}
	else
	{
		pGrid->PrintErrorMessage("there is no card to copy");
		return;
	}
	Card* clipboard = pGrid->GetClipboard();
	if (clipboard)
	{
		deleteClipboard(clipboard);
	}
	pGrid->SetClipboard(card);

	 /*Grid* pGrid = pManager->GetGrid();
	 CellPosition * card = CopiedCell;
	 pGrid->SetClipboard(card);*/
 }

 void CopyCard::deleteClipboard(Card* pcard)
 {
	 pcard->IncrementCardCount();
	 delete pcard;
 }

CopyCard::~CopyCard() {}
