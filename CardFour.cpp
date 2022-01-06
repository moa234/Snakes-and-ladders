#include "CardFour.h"
CardFour:: CardFour(const CellPosition& pos):Card(pos) // A Constructor takes card position
{
	CardCount++;
	cardNumber = 4;
}
 void CardFour:: Apply(Grid* pGrid, Player* pPlayer)
 {
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You reached Card 4...You can't roll next turn!" );
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