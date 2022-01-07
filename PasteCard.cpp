#include "PasteCard.h"
#include "Grid.h"
#include"GameObject.h"
#include "Card.h"

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
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Card * cardp = pGrid->GetClipboard()->PasteCard();
	if (cardp)
	{
		cardp->SetCardPos(PasteCell);
		bool added = pGrid->AddObjectToCell(cardp);
		if (!added)
		{
			pGrid->PrintErrorMessage("Cell contains an object, can't paste ! Click to continue. . . . .");
			this->Execute();
		}
	}
	//cardp->SetCardPos(PasteCell);
	//bool x=pGrid->AddObjectToCell(pGobj);
 }
/*
pCard->ReadCardParameters(pGrid);
bool added = pGrid->AddObjectToCell(pCard);
*/
PasteCard::~PasteCard(){}
