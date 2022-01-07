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
	if (!CutCell.IsValidCell())
	{
		pGrid->PrintErrorMessage("invalid cell to cut! click to continue. . . . . .");
		return;
	}
	
	Card* card = pGrid->CurrentCellCard(CutCell);
	if (card)
	{
		card = card->CopyCard();
	}
	else
	{
		pGrid->PrintErrorMessage("there is no card to cut");
		return;
	}
	Card* clipboard = pGrid->GetClipboard();
	if (clipboard)
	{
		deleteClipboard(clipboard);
	}
	pGrid->SetClipboard(card);
	pGrid->RemoveObjectFromCell(CutCell);
}
	 
void CutCard::deleteClipboard(Card* pcard)
{
	pcard->IncrementCardCount();
	delete pcard;
}
CutCard::~CutCard(){}
