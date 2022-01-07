
#include "card.h"
#include "ApplicationManager.h"
class CardThree :public Card
{
public:

	CardThree(const CellPosition & pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual Card* PasteCard(CellPosition newPos);
	virtual void Save(ofstream& OutFile, Object_Type obj);
	~CardThree(void);
};
