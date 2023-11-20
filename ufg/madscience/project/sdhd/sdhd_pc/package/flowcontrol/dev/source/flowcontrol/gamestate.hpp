// File Line: 34
// RVA: 0x1460850
__int64 UFG::_dynamic_initializer_for__uidGameState_NULL__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GameState_NULL", 0xFFFFFFFF);
  uidGameState_NULL = result;
  return result;
}

// File Line: 49
// RVA: 0x13EE00
void __fastcall UFG::GameState::~GameState(UFG::GameState *this)
{
  UFG::GameState *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::GameStateVtbl *)&UFG::GameState::`vftable';
  UFG::qString::~qString(&this->mGameStateUserDataStr);
  UFG::qString::~qString(&v1->mGameStateName);
}

// File Line: 61
// RVA: 0x13F1A0
bool __fastcall UFG::GameState::ModeIsSet(UFG::GameState *this, UFG::eGameStateMode mode)
{
  return (mode & this->mMode) != 0;
}

// File Line: 65
// RVA: 0x13F1B0
char __fastcall UFG::GameState::ModeSet(UFG::GameState *this, UFG::eGameStateMode mode, const bool enable)
{
  char result; // al

  result = 1;
  if ( enable )
    this->mMode |= mode;
  else
    this->mMode &= ~mode;
  return result;
}

