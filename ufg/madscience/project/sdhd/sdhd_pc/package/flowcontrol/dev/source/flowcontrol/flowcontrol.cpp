// File Line: 20
// RVA: 0x14645A0
__int64 UFG::_dynamic_initializer_for__g_NULL_GameStateObj__()
{
  UFG::GameState::GameState((UFG::GameState *)&UFG::g_NULL_GameStateObj.vfptr, "NULL", uidGameState_NULL_0);
  UFG::g_NULL_GameStateObj.vfptr = (UFG::GameStateVtbl *)&UFG::GameState_NULL::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__g_NULL_GameStateObj__);
}

// File Line: 23
// RVA: 0x13ECE0
void __fastcall UFG::FlowController::FlowController(UFG::FlowController *this)
{
  UFG::GameState **v1; // rax
  signed __int64 v2; // rdx
  UFG::qList<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory,1,0> *v3; // [rsp+28h] [rbp+10h]

  v3 = &this->mStateHistoryList;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  this->mPrevStateStack[0] = 0i64;
  this->mPrevStateStack[1] = 0i64;
  this->mPrevStateStack[2] = 0i64;
  this->mPrevStateStack[3] = 0i64;
  this->mPrevStateStack[4] = 0i64;
  v1 = this->mGameStateList;
  v2 = 3i64;
  do
  {
    *v1 = 0i64;
    v1[1] = 0i64;
    v1[2] = 0i64;
    v1 += 8;
    *(v1 - 5) = 0i64;
    *(v1 - 4) = 0i64;
    *(v1 - 3) = 0i64;
    *(v1 - 2) = 0i64;
    *(v1 - 1) = 0i64;
    --v2;
  }
  while ( v2 );
  *v1 = 0i64;
  v1[1] = 0i64;
  v1[2] = 0i64;
  v1[3] = 0i64;
  v1[4] = 0i64;
  v1[5] = 0i64;
  this->mCurrentState = (UFG::GameState *)&UFG::g_NULL_GameStateObj;
  this->mPendingState = 0i64;
  this->mAbsolutePrevState = 0i64;
  *(_QWORD *)&this->mStateStackIndex = 0i64;
  this->mPendingStateOperation = 1;
  this->mTrackStateHistory = 0;
  this->mLoadsLastLoadScreen = 0;
}

// File Line: 50
// RVA: 0x13F1D0
void __fastcall UFG::FlowController::RegisterGameState(UFG::FlowController *this, UFG::GameState *gs)
{
  unsigned int v2; // eax
  UFG::GameState **v3; // r8

  v2 = 0;
  v3 = this->mGameStateList;
  while ( *v3 )
  {
    ++v2;
    ++v3;
    if ( v2 >= 0x1E )
      return;
  }
  this->mGameStateList[v2] = gs;
}

// File Line: 74
// RVA: 0x13F130
__int64 __fastcall UFG::FlowController::GetCurrentState(UFG::FlowController *this)
{
  __int64 result; // rax

  if ( this->mCurrentState )
    result = this->mCurrentState->mGameStateUID;
  else
    result = uidGameState_NULL_0;
  return result;
}

// File Line: 87
// RVA: 0x13F150
UFG::GameState *__fastcall UFG::FlowController::GetGameStateObj(UFG::FlowController *this, const unsigned int uid)
{
  unsigned int v2; // eax
  UFG::GameState **v3; // r8

  v2 = 0;
  v3 = this->mGameStateList;
  while ( !*v3 || (*v3)->mGameStateUID != uid )
  {
    ++v2;
    ++v3;
    if ( v2 >= 0x1E )
      return 0i64;
  }
  return *v3;
}

// File Line: 102
// RVA: 0x13F180
__int64 __fastcall UFG::FlowController::GetPendingState(UFG::FlowController *this)
{
  UFG::GameState *v1; // rax
  __int64 result; // rax

  v1 = this->mPendingState;
  if ( v1 )
    result = v1->mGameStateUID;
  else
    result = uidGameState_NULL_0;
  return result;
}

// File Line: 107
// RVA: 0x13EF80
void __fastcall UFG::FlowController::DoMainLoop(UFG::FlowController *this, float fRealTimeDelta)
{
  UFG::FlowController *v2; // rbx
  UFG::FlowController::eStackOperation v3; // eax
  UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *v4; // rcx
  char *v5; // rax
  char *v6; // rdi
  UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *v7; // rcx

  v2 = this;
  if ( this->mPendingState && this->mCurrentStateStatus == 1 )
  {
    ((void (*)(void))this->mCurrentState->vfptr->OnExit)();
    v3 = v2->mPendingStateOperation;
    if ( v3 == 1 )
    {
      v2->mPrevStateStack[v2->mStateStackIndex++] = v2->mCurrentState;
    }
    else if ( v3 == 2 )
    {
      --v2->mStateStackIndex;
    }
    else
    {
      v2->mPrevStateStack[0] = v2->mCurrentState;
      v2->mStateStackIndex = 1;
    }
    v2->mAbsolutePrevState = v2->mCurrentState;
    v2->mCurrentState = v2->mPendingState;
    v2->mPendingState = 0i64;
    v2->mCurrentStateStatus = 0;
  }
  if ( v2->mCurrentStateStatus )
  {
    (*((void (**)(void))&v2->mCurrentState->vfptr->__vecDelDtor + 1))();
    ((void (*)(void))v2->mCurrentState->vfptr->OnUpdate)();
    ((void (*)(void))v2->mCurrentState->vfptr->OnPostUpdate)();
  }
  else
  {
    if ( v2->mTrackStateHistory )
    {
      v4 = v2->mStateHistoryList.mNode.mNext;
      if ( v4 )
      {
        LODWORD(v4[4].mPrev) = v2->mLoadsLastLoadScreen;
        HIDWORD(v4[3].mNext) = Illusion::gEngine.mFrameCount;
        v2->mLoadsLastLoadScreen = 0;
      }
    }
    ((void (*)(void))v2->mCurrentState->vfptr->OnEnter)();
    v2->mCurrentStateStatus = 1;
    if ( v2->mTrackStateHistory )
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
        v2->mCurrentState->mGameStateName.mData,
        v2->mCurrentState->mGameStateName.mLength,
        0i64,
        0);
      *((_DWORD *)v6 + 14) = Illusion::gEngine.mFrameCount;
      *(_QWORD *)(v6 + 60) = 0i64;
      v7 = v2->mStateHistoryList.mNode.mNext;
      v2->mStateHistoryList.mNode.mNext = (UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *)v6;
      *(_QWORD *)v6 = (char *)v2 + 328;
      *((_QWORD *)v6 + 1) = v7;
      v7->mPrev = (UFG::qNode<UFG::FlowController::StateHistory,UFG::FlowController::StateHistory> *)v6;
    }
  }
}

// File Line: 186
// RVA: 0x13F200
signed __int64 __fastcall UFG::FlowController::RequestSetNewState(UFG::FlowController *this, unsigned int gsUID)
{
  UFG::FlowController *v2; // rdi
  unsigned int v3; // eax
  UFG::GameState **v4; // r8
  UFG::GameState *v5; // rbx
  __int64 v6; // rdx

  v2 = this;
  v3 = 0;
  v4 = this->mGameStateList;
  while ( 1 )
  {
    v5 = *v4;
    if ( *v4 )
    {
      if ( v5->mGameStateUID == gsUID )
        break;
    }
    ++v3;
    ++v4;
    if ( v3 >= 0x1E )
    {
      v5 = 0i64;
      break;
    }
  }
  if ( this->mCurrentState )
    v6 = this->mCurrentState->mGameStateUID;
  else
    v6 = uidGameState_NULL_0;
  if ( !v5->vfptr->CanSwitchFrom(v5, v6) )
    return 1i64;
  v2->mPendingState = v5;
  v2->mPendingStateOperation = 0;
  return 0i64;
}

