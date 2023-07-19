#include "EventAction.hh"
#include "RunAction.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"
#include "G4AnalysisManager.hh"

#include "Randomize.hh"
#include <iomanip>



EventAction::EventAction()
 : G4UserEventAction()
{}


EventAction::~EventAction()
{}


void EventAction::BeginOfEventAction(const G4Event* event)
{
  for (auto& edep : fEdep) edep = 0.;
}


void EventAction::EndOfEventAction(const G4Event* event)
{

  auto analysisManager = G4AnalysisManager::Instance();

  // Fill histogram with deposited energies
  for (unsigned int i = 0; i < fEdep.size(); i++) {
    analysisManager->FillH1(0, i, fEdep.at(i));
  }
}
