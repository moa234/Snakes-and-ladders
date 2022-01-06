#include "OpenGrid.h"

OpenGrid::OpenGrid(ApplicationManager* pApp) :Action(pApp)
{
}
void OpenGrid::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the file name to load data from:");
	name = pIn->GetString(pOut);
	InFile.open(name+".txt");
	pOut->ClearStatusBar();
}
void OpenGrid::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	if (!InFile.is_open())
	{
		pGrid->PrintErrorMessage("The file name entered is not found, Click anywhere to continue");
		pOut->ClearStatusBar();
		return;
	}
	pGrid->ClearGrid();
	int ladderCount, SnakeCount, CardCount; //variables to store count of game objects
	if (InFile.eof())
		return;
	InFile >> ladderCount;
	for (int i = 0;i < ladderCount;i++) //loading ladder's data 
	{
		GameObject* pLadder = new Ladder(CellPosition(0),CellPosition(0)); //creating empty object
		pLadder->Load(InFile, ladder);
		pGrid->AddObjectToCell(pLadder);
	}
	if (InFile.eof())
		return;
	InFile >> SnakeCount;
	for (int i = 0;i < SnakeCount;i++)
	{
		GameObject* pSnake = new Snake(CellPosition(0), CellPosition(0)); //creating empty object
		pSnake->Load(InFile, snake);
		pGrid->AddObjectToCell(pSnake);
	}
	if (InFile.eof())
		return;
	InFile >> CardCount;
	for (int i = 0;i < CardCount;i++)
	{
		GameObject* pCard = new Card(CellPosition(0)); //creating empty object
		pCard->Load(InFile, card);
		pGrid->AddObjectToCell(pCard);
	}
	InFile.close();
	pGrid->PrintErrorMessage("Successsfully Loaded the grid, Click anywhare to continue");
	pOut->ClearStatusBar();
}

OpenGrid::~OpenGrid()
{
}
