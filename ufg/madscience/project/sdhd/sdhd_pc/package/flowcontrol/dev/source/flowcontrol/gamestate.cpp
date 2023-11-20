// File Line: 22
// RVA: 0x13F280
void __fastcall UFG::GameState::GameState(UFG::GameState *this, const char *name, unsigned int uid)
{
  unsigned int v3; // ebx
  UFG::GameState *v4; // rdi

  v3 = uid;
  v4 = this;
  this->vfptr = (UFG::GameStateVtbl *)&UFG::GameState::`vftable;
  UFG::qString::qString(&this->mGameStateName, name);
  v4->mGameStateUID = v3;
  v4->mGameStateUserDataInt = 0;
  UFG::qString::qString(&v4->mGameStateUserDataStr, &customWorldMapCaption);
  v4->mMode = 0;
  v4->mInitialPass = 1;
}

// File Line: 31
// RVA: 0x13F2E0
void __fastcall UFG::GameState::OnEnter(UFG::GameState *this, float fRealTimeDelta)
{
  this->mInitialPass = 0;
}

