#include "CardEight.h"


CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	CardCount++;
	cardNumber = 8;
}
void CardEight::ReadCardParameters(Grid* pGrid)
{

	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardEight: Please enter its Bail amount...");
	int AmountEntered = pIn->GetInteger(pOut);
	Bail = AmountEntered;

	pOut->ClearStatusBar();

}
Card* CardEight::PasteCard()
{
	CardEight* copy = new CardEight(0);
	copy->Bail = this->Bail;
	return copy;
}
void CardEight::Load(ifstream& Infile, Object_Type obj)
{
	if (obj != card)
		return;
	Card::Load(Infile, obj);
	int Bval;
	Infile >> Bval;
	Bail=Bval;
}
void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);// output card num...

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You reached the prision!");
	if ((pPlayer->GetWallet()) >= Bail)
	{
		pOut->PrintMessage("Would you like to pay the bail? enter Y/N");

		string answer = pIn->GetString(pOut);
		while (answer != "n" && answer != "N" && answer != "y" && answer != "Y")
		{
			answer = pIn->GetString(pOut);
		}

		if (answer == "y" || answer == "Y")
		{
			int x = pPlayer->GetWallet();
			pPlayer->SetWallet(x - Bail);
		}
		else
		{
			pPlayer->SetDoNotPlay(3);
		}
	}
	pOut->ClearStatusBar();

}

void CardEight::Save(ofstream& OutFile, Object_Type obj)
{
	if (obj != card)
		return;
	Card::Save(OutFile, obj);
	OutFile << Bail << endl;
}

CardEight::~CardEight(void)
{
	CardCount--;
}
