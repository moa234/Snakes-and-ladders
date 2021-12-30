#pragma once
#include "Action.h"
class InputDiceValue : public Action
{
	int dicevalue;
public:

	InputDiceValue(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValue();
};

