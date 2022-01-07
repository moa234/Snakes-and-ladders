#pragma once
#include "Action.h"
class CopyCard: public Action
{
	CellPosition CopiedCell;
public:
	CopyCard(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	void deleteClipboard(Card* pcard);
	virtual ~CopyCard();  
};