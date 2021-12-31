#include "InputDiceValue.h"
# include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the dice value:");

	dicevalue = pIn->GetInteger(pOut); // read dice number from the user

	if (dicevalue > 6 || dicevalue < 0)
	{
		dicevalue = 0;
		pGrid->PrintErrorMessage("Invalid dice value! click to continue ...");
	}
}

void InputDiceValue::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->GetCurrentPlayer()->Move(pGrid, dicevalue);
	pGrid->AdvanceCurrentPlayer();
	pGrid->GetOutput()->ClearStatusBar();
	
}

InputDiceValue::~InputDiceValue()
{
}
