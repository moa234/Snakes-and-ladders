#include "InputDiceValue.h"
#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter a dice value between 1-6: ");

	dicevalue = pIn->GetInteger(pOut); // read dice number from the user

	while (dicevalue > 6 || dicevalue < 1)
	{
		pGrid->PrintErrorMessage("Invalid dice value! click to continue ...");
		pOut->PrintMessage("Re-enter dice value");
		dicevalue = pIn->GetInteger(pOut);
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
