#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardSix.h"

#include <iostream>
using namespace std;
AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	
	// 2- Read the "cardNumber" parameter and set its data member
	
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member

	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the card number:");
	int cnum= pIn->GetInteger(pOut);
	while (cnum < 1 || cnum>12) //validating that the card number is between 1 and 12
	{
		pOut->PrintMessage("Wrong card number please enter card number between 1 and 12");
		cnum = pIn->GetInteger(pOut);
	}
	cardNumber = cnum;
	pOut->PrintMessage("Select card postion on the grid"); //taking from the user the cell position from the grid to set the card cell position with
	CellPosition CP = pIn->GetCellClicked();
	pOut->PrintMessage("You have selected cell number " + to_string(CP.GetCellNum()) + " are you sure(y/n)? ");
	string answer = pIn->GetString(pOut);
	while (answer == "n" || answer == "N") //double check on user input
	{
		pOut->PrintMessage("Re-select card postion on the grid");
		CP = pIn->GetCellClicked();
		pOut->PrintMessage("You have selected cell number " + to_string(CP.GetCellNum()) + " are you sure(y/n)? ");
		answer = pIn->GetString(pOut);
	}
	cardPosition = CP;

	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	ReadActionParameters();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	/*case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;*/
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	/*case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;
	case 9:
		pCard = new CardNine(cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	case 12:
		pCard = new CardTwelve(cardPosition);
		break;
*/



	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)

	if (pCard)
	{
		Grid* pGrid = pManager->GetGrid();
		pCard->ReadCardParameters(pGrid);
		bool added = pGrid->AddObjectToCell(pCard);
		if (!added)
		{
			pGrid->PrintErrorMessage("Error: This cell already has a card! Click to continue ...");
			delete pGrid;// there is no need to continue storing the Card because it will already not be added 
		}
		// A- We get a pointer to the Grid from the ApplicationManager

		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

		// C- Add the card object to the GameObject of its Cell:

		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
