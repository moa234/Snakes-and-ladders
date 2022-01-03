#include "SaveGrid.h"

SaveGrid::SaveGrid(ApplicationManager* pApp) :Action(pApp)
{
}

void SaveGrid::ReadActionParameters()
{
	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the file name to save data into:");
	name=pIn->GetString(pOut);
	OutFile.open(name);
	pOut->ClearStatusBar();
}

void SaveGrid::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int ladderCount, SnakeCount, CardCount; //variables to store count of game objects
	ladderCount = pGrid->GetLadderCount();// storing the number of occurance
	SnakeCount = pGrid->GetSnakeCount();
	CardCount = pGrid->GetLadderCount();
	OutFile << ladderCount << endl; //printing as required file format
	pGrid->SaveAll(OutFile, ladder); //calling SaveAll in Grid to be able to Call Save of ladder objects in the cell list
	OutFile << SnakeCount << endl;
	pGrid->SaveAll(OutFile, snake);
	OutFile << CardCount << endl;
	pGrid->SaveAll(OutFile, card);
	OutFile.close();
	pGrid->PrintErrorMessage("Successsfully saved the grid, Click anywhare to continue");
}

SaveGrid::~SaveGrid()
{
}
