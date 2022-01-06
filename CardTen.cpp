#include "CardTen.h"
CardTen::CardTen(const CellPosition& pos) : Card(pos) // A Constructor takes card position
{
    CardCount++;
    cardNumber = 10;
}
bool CardTen::SetPurchasePrice(int PP)
{
    if (PP > 0)
    {
        Purchase_Price = PP;
        return true;
    }
    return false;
}
bool CardTen::SetFeesPrice(int FP)
{
    if (FP > 0)
    {
        Fees_Pay = FP;
        return true;
    }
    return false;
}
int CardTen::GetPrice()
{
    return Purchase_Price;
}


void CardTen::SetOwner(Player* Owner)
{
    owner = Owner;
}



bool CardTen::isOwner(const Player* Check_Owner)
{
    return (owner == Check_Owner);
}



void CardTen::Load(ifstream& Infile, Object_Type obj)
{
    if (obj != card)
        return;
    Card::Load(Infile, obj);
    if (!isSet)
    {
        int price, fees;
        Infile >> price >> fees;
        SetPurchasePrice(price);
        SetFeesPrice(fees);
        isSet = 1;
    }
}

void CardTen::Save(ofstream& OutFile, Object_Type obj)
{
    if (obj != card)
        return;
    Card::Save(OutFile, obj);
    if (!issaved)
    {
        OutFile << Purchase_Price << " " << Fees_Pay;
        issaved = 1;
    }
    OutFile << endl;
}

void CardTen::ReadCardParameters(Grid* pGrid)
{
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();
    if (!isSet)
    {
        pOut->PrintMessage("Set the purchase price of this card: ");
        int Purchaseprice = pIn->GetInteger(pOut);
        while (!SetPurchasePrice(Purchaseprice))
        {
            pGrid->PrintErrorMessage("You must enter a positive value!, click any where to continue");
            pOut->PrintMessage("Re-Enter a positive value");
            Purchaseprice = pIn->GetInteger(pOut);
        }
        pOut->PrintMessage("Set the fees price number that a player must pay if he steps on the card");
        int Feesprice = pIn->GetInteger(pOut);
        while (!SetFeesPrice(Feesprice))
        {
            pGrid->PrintErrorMessage("You must enter a positive value!, click any where to continue");
            pOut->PrintMessage("Re-Enter a positive value");
            Feesprice = pIn->GetInteger(pOut);
        }
        isSet = true;
        pOut->ClearStatusBar();
    }
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
    Card::Apply(pGrid, pPlayer);
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();

    if (owner == NULL)
    {
        pOut->PrintMessage("Price of this card " + to_string(Purchase_Price) + " Do you want to buy this card?(yes/no)");
        string answ = pIn->GetString(pOut);

        if (answ == "yes")
        {
            if (pPlayer->GetWallet() >= Purchase_Price)
            {
                SetOwner(pPlayer);
                pPlayer->SetWallet(pPlayer->GetWallet() - Purchase_Price);
            }
            else
            {
                pOut->PrintMessage("You do not have enough money to buy this card");
            }
        }
    }
    else
    {
        if (!isOwner(pPlayer))
        {
            pOut->PrintMessage("You have to pay money for the owner of the cell");
            int walletAfterDeduction = pPlayer->GetWallet() - Fees_Pay;
            owner->SetWallet(owner->GetWallet() + Fees_Pay);
            if (walletAfterDeduction < 0)
            {
                pPlayer->SetWallet(0);
            }
            else
            {
                pPlayer->SetWallet(walletAfterDeduction);
            }
        }
    }
    pOut->ClearStatusBar();
}
Player* CardTen::owner = NULL;
bool CardTen::isSet = 0;
int CardTen::Purchase_Price = 0;
int CardTen::Fees_Pay = 0;
bool CardTen::issaved = 0;
CardTen::~CardTen() {
    CardCount--;
}