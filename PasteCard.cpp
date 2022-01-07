#include "PasteCard.h"
#include "Grid.h"
#include"GameObject.h"
#include "Card.h"

PasteCard::PasteCard(ApplicationManager* pApp): Action(pApp) {
	Can_Add = 1;
}


void PasteCard:: ReadActionParameters()
{
	Grid* pGrid=pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the destination cell");
	Input* pIn = pGrid->GetInput();
	PasteCell = pIn->GetCellClicked();
	if (!PasteCell.IsValidCell())
	{
		pGrid->PrintErrorMessage("invalid Position to Paste! click to continue. . . . . .");
		Can_Add = 0;
		return;
	}
	if (PasteCell.GetCellNum() == 1 || PasteCell.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("You can't Paste a card in the First/Last cell, Click anywhere to continue");
		Can_Add = 0;
		return;
	}
	pOut->ClearStatusBar();

}


void PasteCard::Execute()
{
	ReadActionParameters();
	if (!Can_Add)
		return;
	Grid* pGrid = pManager->GetGrid();
	Card* cardp;
	if (cardp = pGrid->GetClipboard())
	{
		if(!pGrid->CurrentCellObject(PasteCell)) //if there is no object in the cell you can paste the card
			cardp = pGrid->GetClipboard()->PasteCard();
	}
	else
	{
		pGrid->PrintErrorMessage("There is no card to paste, click anywhere to continue");
	}
		
	if (cardp)
	{
		cardp->SetCardPos(PasteCell);
		bool added = pGrid->AddObjectToCell(cardp);
		if (!added)
		{
			pGrid->PrintErrorMessage("Cell contains an object, can't paste ! Click to continue. . . . .");
			
		}
	}
	
 }

PasteCard::~PasteCard(){}
