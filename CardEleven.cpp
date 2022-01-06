#include "CardEleven.h"
CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // A Constructor takes card position
{
    CardCount++;
    cardNumber = 11;
}
bool CardEleven::SetPurchasePrice(int PP)
{
    if (PP > 0)
    {
        Purchase_Price = PP;
        return true;
    }
    return false;
}
bool CardEleven::SetFeesPrice(int FP)
{
    if (FP > 0)
    {
        Fees_Pay = FP;
        return true;
    }
    return false;
}
int CardEleven::GetPrice()
{
    return Purchase_Price;
}


void CardEleven::SetOwner(Player* Owner)
{
    owner = Owner;
}



bool CardEleven::isOwner(const Player* Check_Owner)
{
    return (owner == Check_Owner);
}



void CardEleven::Load(ifstream& Infile, Object_Type obj)
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

void CardEleven::Save(ofstream& OutFile, Object_Type obj)
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

void CardEleven::reset_is_saved()
{
    issaved = 0;
}

void CardEleven::reset_is_Set()
{
    isSet = 0;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
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

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
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
Player* CardEleven::owner = NULL;
bool CardEleven::isSet = 0;
int CardEleven::Purchase_Price = 0;
int CardEleven::Fees_Pay = 0;
bool CardEleven::issaved = 0;
CardEleven::~CardEleven() {
    CardCount--;
}