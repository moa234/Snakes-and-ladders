#include "DeleteGameObject.h"
#include "Grid.h"

DeleteGameObject::DeleteGameObject(ApplicationManager *pApp) : Action(pApp)
{
    pManager = pApp;
}

void DeleteGameObject::ReadActionParameters()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();
    pOut->PrintMessage("Delete game object: Select the game object you want to delete. If it is a ladder or a snake, please click on its starting cell...");
    startPosition = pIn->GetCellClicked();
    pOut->ClearStatusBar();
};

void DeleteGameObject::Execute()
{
    ReadActionParameters();
    Cell selectedCell = Cell(startPosition);

    Ladder* pLadder = selectedCell.HasLadder();
    Snake* pSnek = selectedCell.HasSnake();
    Card* pCard = selectedCell.HasCard();

    if(pLadder) {
        delete pLadder;
        return;
    }
    if(pSnek) {
        delete pSnek;
        return;
    }
    if(pCard) {
        delete pCard;
        return;
    }

}