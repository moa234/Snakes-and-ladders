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

	//Checking if the player is on card 4 or 8 ;so he can't move
	if (currentplayer->GetDoNotPlay() > 0)
	{
		//decreasing DoNotPlay
		currentplayer->SetDoNotPlay((currentplayer->GetDoNotPlay()) - 1);
		
		//calling move function setting dice roll to zero to increase turnCount
		currentplayer->Move(pManager->GetGrid(), 0);

		pGrid->AdvanceCurrentPlayer();
		return;
	}

	//if DoNotPlay=0,the player will play normally.
	currentplayer->SetRolledDiceNum(dicevalue);
	currentplayer->Move(pManager->GetGrid(), dicevalue);

	if (currentplayer->GetDoNotPlay() == -1)
	{
		currentplayer->SetDoNotPlay(0);
		//the player will return;thus the CurrentPlayer will not be advanced
		//(he will roll the dice again)
		return;
	}
	pGrid->AdvanceCurrentPlayer();
}

InputDiceValue::~InputDiceValue()
{
}
