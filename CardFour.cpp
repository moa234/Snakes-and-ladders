#include "CardFour.h"
CardFour:: CardFour(const CellPosition& pos):Card(pos) // A Constructor takes card position
{
	CardCount++;
	cardNumber = 4;
}
 void CardFour:: Apply(Grid* pGrid, Player* pPlayer)
 {
	Output* pOut = pGrid->GetOutput();
	pGrid->PrintErrorMessage("Congratulations!..you can't roll next turn! click to continue" );
		pPlayer->SetDoNotPlay(1);
		pOut->ClearStatusBar();
 }
 void CardFour::Save(ofstream& OutFile, Object_Type obj)
 {
	 if (obj != card)
		 return;
	 Card::Save(OutFile, obj);
	 OutFile << endl;
 }
 CardFour::~CardFour(void)
{
	 CardCount--;
}