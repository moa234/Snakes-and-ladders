#include "SwitchToPlayModeAction.h"
#include "Grid.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager *pApp) : Action(pApp)
{
    pManager = pApp;
}

void SwitchToPlayModeAction::Execute()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();

    pOut->CreateDesignModeToolBar();
}