//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "NXPrimaryGeneratorAction.hh"
#include "NXUserDetectorConstruction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NXPrimaryGeneratorAction::NXPrimaryGeneratorAction( NXUserDetectorConstruction* myDC) :
    myDetector(myDC)
{
    G4int n_particle = 1;
    particleGun = new G4ParticleGun(n_particle);

    // default particle

    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particleTable->FindParticle("proton");

    particleGun->SetParticleDefinition(particle);
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
    particleGun->SetParticleEnergy(3.0*GeV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

NXPrimaryGeneratorAction::~NXPrimaryGeneratorAction()
{
    delete particleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void NXPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{ 
    G4double position = -0.5*(myDetector->GetWorldFullLength());
    particleGun->SetParticlePosition(G4ThreeVector(0.*cm,0.*cm,position));

    particleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
