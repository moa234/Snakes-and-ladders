#include "Cell.h"

#include "Grid.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include "Snake.h"

Cell::Cell(const CellPosition & pos) : position(pos)
{
	// initializes the data members (position & pGameObject)
	pGameObject = NULL;
}

Cell::Cell(int v, int h) : position(v, h)
{
	// initializes the data members (position & pGameObject)
	pGameObject = NULL;
}


// ======= Setters and Getters Functions ======= 


CellPosition Cell::GetCellPosition() const
{
	return position;
}

bool Cell::SetGameObject(GameObject * pGObj)
{
	if (pGameObject != NULL && pGObj != NULL) // already contains one
		return false; // do NOT add it and return false

	pGameObject = pGObj;
	return true;
}

GameObject * Cell::GetGameObject() const
{
	return pGameObject;
}

Ladder * Cell::HasLadder() const
{
	return dynamic_cast<Ladder *>(pGameObject);
}

Player* Cell::HasPlayer(Player* p1, Player* p2, Player* p3, Player* p4) const
{
	int pos1 = p1->GetCell()->GetCellPosition().GetCellNum();
	int pos2 = p2->GetCell()->GetCellPosition().GetCellNum();
	int pos3 = p3->GetCell()->GetCellPosition().GetCellNum();
	int pos4 = p4->GetCell()->GetCellPosition().GetCellNum();

	if (pos1 == this->GetCellPosition().GetCellNum())
	{
		return p1;
	}
	else if (pos2 == this->GetCellPosition().GetCellNum())
	{
		return p2;
	}
	else if (pos3 == this->GetCellPosition().GetCellNum())
	{
		return p3;
	}
	else if (pos4 == this->GetCellPosition().GetCellNum())
	{
		return p4;
	}
	return NULL;
}

Snake * Cell::HasSnake() const
{

	///TODO: Implement the following function like HasLadder() function
	return dynamic_cast<Snake*>(pGameObject); // THIS LINE SHOULD CHANGED WITH YOUR IMPLEMENTATION
}

Card * Cell::HasCard() const
{

	///TODO: Implement the following function like HasLadder() function

	return dynamic_cast<Card*>(pGameObject);

}


// ======= Drawing Functions ======= 

void Cell::DrawCellOrCard(Output* pOut) const
{
	// Checks if there is a Card on the cell
	/*if (HasCard())
	{
		cout << "ok" << endl;
	}
	else
	{
		cout << "no" << endl;
	}*/
	if (HasCard()) // means if not NULL
		pGameObject->Draw(pOut); // draw the card then
	else
		pOut->DrawCell(position, -1); // draw empty cell (no card -1)
}

// separate from the above function because ladders/snakes should be drawn AFTER All Cells are drawn
void Cell::DrawLadderOrSnake(Output* pOut) const
{
	if (HasLadder() || HasSnake())
		pGameObject->Draw(pOut); // draw it either ladder or snake

}
