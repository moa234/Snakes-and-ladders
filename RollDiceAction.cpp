#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
	
	Grid* pGrid = pManager->GetGrid();
	bool ended = pGrid->GetEndGame();
	if (ended)
	{
		return;
	}

	Player* currentplayer = pManager->GetGrid()->GetCurrentPlayer();

	//Checking if the player is on card 4 or 8 ;so his dice roll is cancelled
	if (currentplayer->GetDoNotPlay() > 0)
	{
		//decreasing DoNotPlay
		currentplayer->SetDoNotPlay((currentplayer->GetDoNotPlay()) - 1);

		//calling move function to increase turnCount  and setting dice roll to zero.
		currentplayer->Move(pManager->GetGrid(), 0);

		pGrid->AdvanceCurrentPlayer();
		return;
	}
	
	//if DoNotPlay=0,the player will play normally.
	srand((int)time(NULL));
	int diceNumber = 1 + rand() % 6; 
	currentplayer->SetRolledDiceNum(diceNumber);
	currentplayer->Move(pManager->GetGrid(), diceNumber);

	if (currentplayer->GetDoNotPlay() ==-1)
	{	
		currentplayer->SetDoNotPlay(0);
		
		//the player will return;thus the CurrentPlayer will not be advanced
		//(he will roll the dice again)
		return;
	}

	pGrid->AdvanceCurrentPlayer();

}

RollDiceAction::~RollDiceAction()
{
}
