#pragma once
#include "Action.h"
class PasteCard :	public Action
{
		CellPosition PasteCell;
		bool Can_Add;
public:

	PasteCard(void);

	PasteCard(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute() ; 

	~PasteCard(void);
};
