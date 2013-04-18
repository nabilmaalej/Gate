/*----------------------
   GATE version name: gate_v6

   Copyright (C): OpenGATE Collaboration

This software is distributed under the terms
of the GNU Lesser General  Public Licence (LGPL)
See GATE/LICENSE.txt for further details
----------------------*/


/*!
  \class  GateFluenceActor
  \author simon.rit@creatis.insa-lyon.fr
 */

#include "GateConfiguration.h"

#ifndef GATEFLUENCEACTOR_HH
#define GATEFLUENCEACTOR_HH

#ifdef GATE_USE_RTK

#include "GateVImageActor.hh"
#include "GateActorManager.hh"
#include "GateMiscFunctions.hh"
#include "GateSourceMoveRandom.hh"
#include "GateFluenceActorMessenger.hh"

class GateFluenceActor : public GateVImageActor
{
 public: 
  
  //-----------------------------------------------------------------------------
  // Actor name
  virtual ~GateFluenceActor();

  FCT_FOR_AUTO_CREATOR_ACTOR(GateFluenceActor)

  //-----------------------------------------------------------------------------
  // Constructs the sensor
  virtual void Construct();

  void EnableScatterImage(bool b) { mIsScatterImageEnabled = b; }
  void EnableSourceMotionByStack(bool b) { mIsSourceMotionByStackEnabled = b; }

  virtual void BeginOfEventAction(const G4Event * e);
  virtual void UserSteppingActionInVoxel(const int index, const G4Step* step);
  virtual void UserPreTrackActionInVoxel(const int /*index*/, const G4Track* /*t*/) {}
  virtual void UserPostTrackActionInVoxel(const int /*index*/, const G4Track* /*t*/) {}

 /// Saves the data collected to the file
  virtual void SaveData();
  virtual void ResetData();

  ///Scorer related
  //virtual G4bool ProcessHits(G4Step *, G4TouchableHistory*);
  virtual void Initialize(G4HCofThisEvent*){}
  virtual void EndOfEvent(G4HCofThisEvent*){}
  void SetScatterOrderFilename(G4String name) { mScatterOrderFilename = name; }

protected:
  GateFluenceActor(G4String name, G4int depth=0);
  GateFluenceActorMessenger * pMessenger;

  bool mIsScatterImageEnabled;
  bool mIsSourceMotionByStackEnabled;
  GateImage mImageScatter;
  std::vector<GateImage *> mFluencePerOrderImages;
  G4String mScatterOrderFilename;
  int mCurrentEventFrame;
  bool mUseFrameFlag;
  int mDimension;
};

MAKE_AUTO_CREATOR_ACTOR(FluenceActor,GateFluenceActor)

#endif // GATE_USE_RTK
#endif /* end #define GATESIMULATIONSTATISTICACTOR_HH */
