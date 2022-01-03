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
				///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	
			// == Here are some guideline steps (numbered below) to implement this function ==

			// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	bool ended = pManager->GetGrid()->GetEndGame();

			// -- If not ended, do the following --:
	if (ended)
		{
			return;
		}
			// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
			// 3- Get the "current" player from pGrid

	Player* currentplayer = pManager->GetGrid()->GetCurrentPlayer();

if (currentplayer->GetDoNotPlay() == 0) //made by Abdelrahman for card 3,4,8
{
	currentplayer->SetRolledDiceNum(diceNumber);
		// 4- Move the currentPlayer using function Move of class player
	currentplayer->Move(pManager->GetGrid(), diceNumber);
}
else if (currentplayer->GetDoNotPlay() == -1)
{
		//extra dice roll
	srand((int)time(NULL));
	int diceNumber = 1 + rand() % 6; 
	currentplayer->SetRolledDiceNum(diceNumber);
	currentplayer->Move(pManager->GetGrid(), diceNumber);
		//setting DoNotPlay to 0
currentplayer->SetDoNotPlay(0);
}
else
{
int x=currentplayer->GetDoNotPlay();
currentplayer->SetDoNotPlay(x-1);
}
	
pManager->GetGrid()->AdvanceCurrentPlayer();

	// Moaaz dh comment mni hna t2reban hthtag ts2al lw feh ladder aw snake aw card ya5odha
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

	//Moaaz na kateb al hta deh mn 3andi 3alshan a3ml test fakrni aolk 3mltha leh

	// 8ayyart feeh


/*
Abdelrahman 
	I added if condition to check DoNotPlay data member 
	if =0 the player'll roll the dice normally
	if =-1 the player will roll the dice one more time
	else the DoNotPlay will be>0 so he wont roll the dice till DoNotPlay==0 
*/

/*  da el code el aslyy isA mane7taghoo4

	bool ended = pManager->GetGrid()->GetEndGame();
	if (ended)
	{
		return;
	}
	srand((int)time(NULL));
	int diceNumber = 1 + rand() % 6; 
	Player* currentplayer = pManager->GetGrid()->GetCurrentPlayer();
	currentplayer->SetRolledDiceNum(diceNumber);
	currentplayer->Move(pManager->GetGrid(), diceNumber);


*/
}

RollDiceAction::~RollDiceAction()
{
}
