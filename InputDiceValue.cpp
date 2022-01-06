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
	pOut->ClearStatusBar();
}

void InputDiceValue::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Player* currentplayer = pGrid->GetCurrentPlayer();

	
	if (currentplayer->GetDoNotPlay() > 0)
	{

		currentplayer->SetDoNotPlay((currentplayer->GetDoNotPlay()) - 1);
		currentplayer->Move(pManager->GetGrid(), 0);

		pGrid->AdvanceCurrentPlayer();
		return;
	}

	currentplayer->SetRolledDiceNum(dicevalue);
	currentplayer->Move(pManager->GetGrid(), dicevalue);

	if (currentplayer->GetDoNotPlay() == -1)
	{
		currentplayer->SetDoNotPlay(0);
		return;
	}
	pGrid->AdvanceCurrentPlayer();
}

InputDiceValue::~InputDiceValue()
{
}
