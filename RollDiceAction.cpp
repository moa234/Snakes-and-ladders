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
	if (currentplayer->GetDoNotPlay() > 0)
	{
		
		currentplayer->SetDoNotPlay((currentplayer->GetDoNotPlay()) - 1);
		currentplayer->Move(pManager->GetGrid(), 0);

		pGrid->AdvanceCurrentPlayer();
		return;
	}

	srand((int)time(NULL));
	int diceNumber = 1 + rand() % 6; 
	currentplayer->SetRolledDiceNum(diceNumber);
	currentplayer->Move(pManager->GetGrid(), diceNumber);

	if (currentplayer->GetDoNotPlay() ==-1)
	{
		currentplayer->SetDoNotPlay(0);
		return;
	}

	pGrid->AdvanceCurrentPlayer();

}

RollDiceAction::~RollDiceAction()
{
}
