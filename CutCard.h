#pragma once
#include "action.h"
class CutCard:public Action
{
		CellPosition CutCell;
public:
	CutCard(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ; 
	virtual ~CutCard(); 
};

