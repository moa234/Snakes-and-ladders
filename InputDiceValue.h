#pragma once
#include "Action.h"
class InputDiceValue : public Action
{
	int dicevalue;
public:

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValue();
};

