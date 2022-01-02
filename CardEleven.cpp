#include "CardEleven.h"
CardEleven::CardEleven(const CellPosition &pos) : Card(pos) // A Constructor takes card position
{
    cardNumber = 11;
}
void CardEleven::SetPurchasePrice(static int PP)
{
    if (PP > 0)
    {
        Purchase_Price = PP;
    }
}
void CardEleven::SetFeesPrice(static int FP)
{
    if (FP > 0)
    {
        Fees_Pay = FP;
    }
}
int CardEleven::GetPurchasePrice()
{
    return Purchase_Price;
}
int CardEleven::GetFeesPrice()
{
    return Fees_Pay;
}

void CardEleven::SetOwner(Player *Owner)
{
    owner = Owner;
}

Player *CardEleven::GetOwner()
{
    return owner;
}

bool CardEleven::isOwner(const Player *Check_Owner)
{
    return (owner == Check_Owner);
}

void CardEleven::ReadCardParameters(Grid *pGrid)
{
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();
    if (!isSet)
    {
        pOut->PrintMessage("Set the purchase price of this card");
        int Purchaseprice = pIn->GetInteger(pOut);
        SetPurchasePrice(Purchaseprice);
        pOut->PrintMessage("Set the fees price number that a player must pay if he steps on the card");
        int Feesprice = pIn->GetInteger(pOut);
        SetFeesPrice(Feesprice);
        isSet = true;
        pOut->ClearStatusBar();
    }
}

void CardEleven::Apply(Grid *pGrid, Player *pPlayer)
{
    Card::Apply(pGrid, pPlayer);
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();

    if (GetOwner() == NULL)
    {
        pOut->PrintMessage("Do you want to buy this card?(yes/no)");
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
}
