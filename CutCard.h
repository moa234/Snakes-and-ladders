#pragma once
#include "Action.h"
class CutCard:public Action
{
		CellPosition CutCell;
public:
	CutCard(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ; 
	void deleteClipboard(Card* pcard);
	virtual ~CutCard();
};

