// File Line: 22
// RVA: 0x13F280
void __fastcall UFG::GameState::GameState(UFG::GameState *this, const char *name, unsigned int uid)
{
  this->vfptr = (UFG::GameStateVtbl *)&UFG::GameState::`vftable;
  UFG::qString::qString(&this->mGameStateName, name);
  this->mGameStateUID = uid;
  this->mGameStateUserDataInt = 0;
  UFG::qString::qString(&this->mGameStateUserDataStr, &customCaption);
  this->mMode = 0;
  this->mInitialPass = 1;
}

// File Line: 31
// RVA: 0x13F2E0
void __fastcall UFG::GameState::OnEnter(UFG::GameState *this, float fRealTimeDelta)
{
  this->mInitialPass = 0;
}

