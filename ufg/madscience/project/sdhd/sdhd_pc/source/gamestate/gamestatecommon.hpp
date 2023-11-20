// File Line: 62
// RVA: 0x405DB0
void __fastcall GameStateHKBase::~GameStateHKBase(GameStateHKBase *this)
{
  GameStateHKBase *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::GameStateVtbl *)&GameStateHKBase::`vftable;
  this->vfptr = (UFG::GameStateVtbl *)&UFG::GameState::`vftable;
  UFG::qString::~qString(&this->mGameStateUserDataStr);
  UFG::qString::~qString(&v1->mGameStateName);
}

