#pragma once
#include "Action.h"
class NewGame: public Action
{
public:
	NewGame(ApplicationManager* pApp);
	virtual void Execute() ;  
	virtual void ReadActionParameters();
	virtual ~NewGame();  
};