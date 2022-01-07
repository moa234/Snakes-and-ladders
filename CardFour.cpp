#include "CardFour.h"
CardFour:: CardFour(const CellPosition& pos):Card(pos) // A Constructor takes card position
{
	CardCount++;
	cardNumber = 4;
}
 void CardFour:: Apply(Grid* pGrid, Player* pPlayer)
 {
	Card::Apply(pGrid, pPlayer);			// output card number
	Output* pOut = pGrid->GetOutput();
	
	pGrid->PrintErrorMessage("You reached Card 4! You can't roll next turn! click to continue" );
	
	pPlayer->SetDoNotPlay(1);
	
	pOut->ClearStatusBar();
 }
 Card* CardFour::PasteCard()
 {
	 Card* copy = new CardFour(0);
	 return copy;
 }
 Card* CardFour::CopyCard()
 {
	 Card* copy = new CardFour(0);
	 CardCount--;
	 return copy;
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