//#include "CardTwelve.h"
//CardTwelve::CardTwelve(const CellPosition& pos):Card(pos)
//{
//	cardNumber = 12;
//}
//
//void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
//{
//	Output *pOut = pGrid->GetOutput();
//	Input* pIn = pGrid->GetInput();
//	// checks the ownership of current player to a card 9,10 or 11 using isOwner function
//	// gets the most expensive card that the current player owns
//	// gets least player with coins using MinWalletPlayer funvction
//	// moves the ownership from current player to least player
//	Card::Apply(pGrid, pPlayer);
//	int card_num=-1;
//	int maximum=-1;
//	Player* leastp = pGrid->MinWalletPlayer(); //getting player with least wallet value
//	if (CardNine::isOwner(pPlayer))
//	{
//		//checking that the current player owns this station or not
//		if (CardNine::GetPrice() > maximum)
//		{
//			//maximinzing on the stations price owned by the player  
//			maximum = CardNine::GetPrice();
//			card_num = 9;
//		}
//	}
//	if (CardTen::isOwner(pPlayer))
//	{
//		if (CardTen::GetPrice() > maximum)
//		{
//			maximum = CardTen::GetPrice();
//			card_num = 10;
//		}
//	}
//	if (CardEleven::isOwner(pPlayer))
//	{
//		if (CardEleven::GetPrice() > maximum)
//		{
//			maximum = CardEleven::GetPrice();
//			card_num = 11;
//		}
//	}
//	if (card_num == -1)
//	{
//		//in case no station owned by player
//		pOut->PrintMessage("No station ownership by player to move, click anywhere to continue");
//		pIn->GetCellClicked();
//		pOut->ClearStatusBar();
//		return;
//	}
//	switch (card_num)
//	{
//	case 9:
//		CardNine::set_owner(leastp);
//		break;
//	case 10:
//		CardTen::set_owner(leastp);
//		break;
//	case 11:
//		CardEleven::set_owner(leastp);
//		break;
//	}
//}
