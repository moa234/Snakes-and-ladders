#include "NewGame.h"
#include "Grid.h"
NewGame::NewGame(ApplicationManager* pApp):Action(pApp) {}
void NewGame::Execute() 
{
	 Grid *pGrid;
	 pGrid->ClearGrid;//Restarts players' positions, wallets,turn returns to player 0
} 
NewGame::~NewGame(){}
