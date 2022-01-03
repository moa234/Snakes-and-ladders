#include "CardFour.h"
CardFour:: CardFour(const CellPosition& pos):Card(pos) // A Constructor takes card position
{
	cardNumber = 4;
}
 void CardFour:: Apply(Grid* pGrid, Player* pPlayer)
 {
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Congratulations!..you can't roll next turn!" );
		pPlayer->SetDoNotPlay(1);
 }
 CardFour::~CardFour(void)
{
}