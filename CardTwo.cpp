#include "CardTwo.h"
#include <iostream>
#include "Ladder.h"

using namespace std;

CardTwo::CardTwo(const CellPosition &pos) : Card(pos) // set the cell position of the card
{
	CardCount++;
    cardNumber = 2;
}
void CardTwo::Save(ofstream& OutFile, Object_Type obj)
{
	if (obj != card)
		return;
	Card::Save(OutFile, obj);
	OutFile << endl;
}
Card* CardTwo::PasteCard()
{
    CardTwo* copy = new CardTwo(0);
    return copy;
}
Card* CardTwo::CopyCard()
{
    CardTwo* copy = new CardTwo(0);
    CardCount--;
    return copy;
}
void CardTwo::Apply(Grid *pGrid, Player *pPlayer)
{
    Card::Apply(pGrid, pPlayer);
    pGrid->PrintErrorMessage("You have reached card two. You will jump to the nearest ladder ahead of you");
    CellPosition playerCellPosition = pPlayer->GetCell()->GetCellPosition();
    Ladder *pLadder = pGrid->GetNextLadder(playerCellPosition);

    if (pLadder)
    {
        CellPosition LadderStartCell = pLadder->GetPosition();
        pGrid->UpdatePlayerCell(pPlayer, LadderStartCell);
        pLadder->Apply(pGrid, pPlayer);
    }
}
CardTwo::~CardTwo()
{
	CardCount--;
}
