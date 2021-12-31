#include "AddSnake.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"

AddSnake::AddSnake(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	valid = 1;
}

bool AddSnake::occupied[100];

AddSnake::~AddSnake()
{
}

void AddSnake::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();




	///TODO: Make the needed validations on the read parameters

	if (startPos.GetCellNum() <= endPos.GetCellNum())
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
	else if (dynamic_cast<Ladder*>(pGrid->CurrentCellObject(endPos)) != NULL)
	{
		pGrid->PrintErrorMessage("Error: endcell cannot contain ladder! Click to continue ...");
	}
	for (int i = startPos.GetCellNum(); i <= endPos.GetCellNum(); i = i + 11)
	{
		if (occupied[i] == 1)
		{
			valid = 0;
			pGrid->PrintErrorMessage("Error: snakes cannot overlap! Click to continue ...");
			break;
		}
	}


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnake::Execute()
{

	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	if (!valid)
	{
		return;
	}
	// Create a Snake object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);
	if (added)
	{
		for (int i = startPos.GetCellNum(); i <= endPos.GetCellNum(); i = i + 11)
		{
			occupied[i] = 1;
		}
	}
	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		delete pSnake;
	}
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddSnake

}
