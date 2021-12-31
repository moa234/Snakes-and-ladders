#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	valid = 1;
}

bool AddLadderAction::occupied[100];

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    
	

	///TODO: Make the needed validations on the read parameters

	if (startPos.GetCellNum() >= endPos.GetCellNum())
	{
		//error
		valid = 0;
		pGrid->PrintErrorMessage("Error: Start cell cannot exceed end cell! Click to continue ...");
	}
	else if (startPos.HCell() != endPos.HCell())
	{
		//error
		valid = 0;
		pGrid->PrintErrorMessage("Error: start cell and endcell cannot be in a different column! Click to continue ...");
	}
	else if (dynamic_cast<Snake*>(pGrid->CurrentCellObject(endPos)) != NULL)
	{
		pGrid->PrintErrorMessage("Error: endcell cannot contain snake! Click to continue ...");
	}
	for (int i = startPos.GetCellNum(); i <= endPos.GetCellNum(); i = i + 11)
	{
		if (occupied[i] == 1)
		{
			valid = 0;
			pGrid->PrintErrorMessage("Error: ladders cannot overlap! Click to continue ...");
			break;
		}
	}
	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{

	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	
	if (!valid)
	{
		return;
	}
	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);
	if (added)
	{
		for (int i = startPos.GetCellNum(); i <= endPos.GetCellNum(); i = i + 11)
		{
			occupied[i] = 1;
		}
	}
	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		delete pLadder;
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
