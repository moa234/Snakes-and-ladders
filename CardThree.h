
#include "card.h"
#include "ApplicationManager.h"
class CardThree :public Card
{
public:

	CardThree(const CellPosition & pos);
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	~CardThree(void);
};
