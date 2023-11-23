// File Line: 20
// RVA: 0x14645A0
__int64 UFG::_dynamic_initializer_for__g_NULL_GameStateObj__()
{
  UFG::GameState::GameState(&UFG::g_NULL_GameStateObj, "NULL", uidGameState_NULL_0);
  UFG::g_NULL_GameStateObj.vfptr = (UFG::GameStateVtbl *)&UFG::GameState_NULL::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__g_NULL_GameStateObj__);
}

// File Line: 23
// RVA: 0x13ECE0
void __fastcall UFG::FlowController::FlowController(UFG::FlowController *this)
{
  UFG::GameState **mGameStateList; // rax
  __int64 v2; // rdx

  this->mStateHistoryList.mNode.mPrev = &this->mStateHistoryList.mNode;
  this->mStateHistoryList.mNode.mNext = &this->mStateHistoryList.mNode;
  this->mPrevStateStack[0] = 0i64;
  this->mPrevStateStack[1] = 0i64;
  this->mPrevStateStack[2] = 0i64;
  this->mPrevStateStack[3] = 0i64;
  this->mPrevStateStack[4] = 0i64;
  mGameStateList = this->mGameStateList;
  v2 = 3i64;
  do
  {
    *mGameStateList = 0i64;
    mGameStateList[1] = 0i64;
    mGameStateList[2] = 0i64;
    mGameStateList += 8;
    *(mGameStateList - 5) = 0i64;
    *(mGameStateList - 4) = 0i64;
    *(mGameStateList - 3) = 0i64;
    *(mGameStateList - 2) = 0i64;
    *(mGameStateList - 1) = 0i64;
    --v2;
  }
  while ( v2 );
  *mGameStateList = 0i64;
  mGameStateList[1] = 0i64;
  mGameStateList[2] = 0i64;
  mGameStateList[3] = 0i64;
  mGameStateList[4] = 0i64;
  mGameStateList[5] = 0i64;
  this->mCurrentState = &UFG::g_NULL_GameStateObj;
  this->mPendingState = 0i64;
  this->mAbsolutePrevState = 0i64;
  *(_QWORD *)&this->mStateStackIndex = 0i64;
  this->mPendingStateOperation = Push;
  this->mTrackStateHistory = 0;
  this->mLoadsLastLoadScreen = 0;
}

// File Line: 50
// RVA: 0x13F1D0
void __fastcall UFG::FlowController::RegisterGameState(UFG::FlowController *this, UFG::GameState *gs)
{
  int v2; // eax
  UFG::GameState **i; // r8

  v2 = 0;
  for ( i = this->mGameStateList; *i; ++i )
  {
    if ( (unsigned int)++v2 >= 0x1E )
      return;
  }
  this->mGameStateList[v2] = gs;
}

// File Line: 74
// RVA: 0x13F130
__int64 __fastcall UFG::FlowController::GetCurrentState(UFG::FlowController *this)
{
  if ( this->mCurrentState )
    return this->mCurrentState->mGameStateUID;
  else
    return uidGameState_NULL_0;
}

// File Line: 87
// RVA: 0x13F150
UFG::GameState *__fastcall UFG::FlowController::GetGameStateObj(UFG::FlowController *this, const unsigned int uid)
{
  int v2; // eax
  UFG::GameState **i; // r8

  v2 = 0;
  for ( i = this->mGameStateList; !*i || (*i)->mGameStateUID != uid; ++i )
  {
    if ( (unsigned int)++v2 >= 0x1E )
      return 0i64;
  }
  return *i;
}

// File Line: 102
// RVA: 0x13F180
__int64 __fastcall UFG::FlowController::GetPendingState(UFG::FlowController *this)
{
  UFG::GameState *mPendingState; // rax

  mPendingState = this->mPendingState;
  if ( mPendingState )
    return mPendingState->mGameStateUID;
  else
    return uidGameState_NULL_0;
}

// File Line: 107
// RVA: 0x13EF80
void __fastcall UFG::FlowController::DoMainLoop(UFG::FlowController *this, float fRealTimeDelta)
{
  UFG::FlowController::eStackOperation mPendingStateOperation; // eax
  UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *mNext; // rcx
  char *v5; // rax
  char *v6; // rdi
  UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *v7; // rcx

  if ( this->mPendingState && this->mCurrentStateStatus == STEADY_STATE )
  {
    ((void (__fastcall *)(UFG::GameState *))this->mCurrentState->vfptr->OnExit)(this->mCurrentState);
    mPendingStateOperation = this->mPendingStateOperation;
    if ( mPendingStateOperation == Push )
    {
      this->mPrevStateStack[this->mStateStackIndex++] = this->mCurrentState;
    }
    else if ( mPendingStateOperation == Pop )
    {
      --this->mStateStackIndex;
    }
    else
    {
      this->mPrevStateStack[0] = this->mCurrentState;
      this->mStateStackIndex = 1;
    }
    this->mAbsolutePrevState = this->mCurrentState;
    this->mCurrentState = this->mPendingState;
    this->mPendingState = 0i64;
    this->mCurrentStateStatus = INITIAL_GAME_STATE;
  }
  if ( this->mCurrentStateStatus )
  {
    (*((void (__fastcall **)(UFG::GameState *))&this->mCurrentState->vfptr->__vecDelDtor + 1))(this->mCurrentState);
    ((void (__fastcall *)(UFG::GameState *))this->mCurrentState->vfptr->OnUpdate)(this->mCurrentState);
    ((void (__fastcall *)(UFG::GameState *))this->mCurrentState->vfptr->OnPostUpdate)(this->mCurrentState);
  }
  else
  {
    if ( this->mTrackStateHistory )
    {
      mNext = this->mStateHistoryList.mNode.mNext;
      if ( mNext )
      {
        LODWORD(mNext[4].mPrev) = this->mLoadsLastLoadScreen;
        HIDWORD(mNext[3].mNext) = Illusion::gEngine.mFrameCount;
        this->mLoadsLastLoadScreen = 0;
      }
    }
    ((void (__fastcall *)(UFG::GameState *))this->mCurrentState->vfptr->OnEnter)(this->mCurrentState);
    this->mCurrentStateStatus = STEADY_STATE;
    if ( this->mTrackStateHistory )
    {
      v5 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
      v6 = v5;
      if ( v5 )
      {
        *(_QWORD *)v5 = v5;
        *((_QWORD *)v5 + 1) = v5;
        UFG::qString::qString((UFG::qString *)(v5 + 16));
      }
      else
      {
        v6 = 0i64;
      }
      UFG::qString::Set(
        (UFG::qString *)(v6 + 16),
        this->mCurrentState->mGameStateName.mData,
        this->mCurrentState->mGameStateName.mLength,
        0i64,
        0);
      *((_DWORD *)v6 + 14) = Illusion::gEngine.mFrameCount;
      *(_QWORD *)(v6 + 60) = 0i64;
      v7 = this->mStateHistoryList.mNode.mNext;
      this->mStateHistoryList.mNode.mNext = (UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *)v6;
      *(_QWORD *)v6 = &this->mStateHistoryList;
      *((_QWORD *)v6 + 1) = v7;
      v7->mPrev = (UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *)v6;
    }
  }
}

// File Line: 186
// RVA: 0x13F200
signed __int64 __fastcall UFG::FlowController::RequestSetNewState(UFG::FlowController *this, unsigned int gsUID)
{
  unsigned int v3; // eax
  UFG::GameState **mGameStateList; // r8
  UFG::GameState *v5; // rbx
  __int64 mGameStateUID; // rdx

  v3 = 0;
  mGameStateList = this->mGameStateList;
  while ( 1 )
  {
    v5 = *mGameStateList;
    if ( *mGameStateList )
    {
      if ( v5->mGameStateUID == gsUID )
        break;
    }
    ++v3;
    ++mGameStateList;
    if ( v3 >= 0x1E )
    {
      v5 = 0i64;
      break;
    }
  }
  if ( this->mCurrentState )
    mGameStateUID = this->mCurrentState->mGameStateUID;
  else
    mGameStateUID = uidGameState_NULL_0;
  if ( !v5->vfptr->CanSwitchFrom(v5, mGameStateUID) )
    return 1i64;
  this->mPendingState = v5;
  this->mPendingStateOperation = Set;
  return 0i64;
}

