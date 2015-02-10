#ifndef NXPhysicsList_h
#define NXPhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

class G4VPhysicsConstructor;

class NXPhysicsList: public G4VUserPhysicsList
{
    public:
        NXPhysicsList();
        ~NXPhysicsList();

    protected:
        // Construct particle and physics
        void ConstructParticle();
        void ConstructProcess();
        void SetCuts();


    protected:
        // these methods Construct particles 
        void ConstructBosons();
        void ConstructLeptons();
        void ConstructBaryons();

protected:
        // these methods Construct physics processes and register them
        void ConstructEM();
private:
	G4VPhysicsConstructor* physics;
};

#endif


