// File Line: 24
// RVA: 0x61F1D0
bool __fastcall UFG::UIFlowRoot::canChangeState(UFG::UIFlowRoot *this, UFG::UIFlow::eState old_state, UFG::UIFlow::eState new_state)
{
  __int32 v3; // edx
  int v4; // edx
  int v5; // edx

  if ( old_state == STATE_INVALID )
    return new_state == 11;
  v3 = old_state - 2;
  if ( !v3 )
    return new_state == 12;
  v4 = v3 - 9;
  if ( !v4 )
    return new_state == 2;
  v5 = v4 - 1;
  if ( v5 )
  {
    if ( v5 != 1 )
      return 0;
    return new_state == 11;
  }
  return new_state == 13 || new_state == 2;
}

// File Line: 50
// RVA: 0x620E50
void __fastcall UFG::UIFlowRoot::handleEnterState(UFG::UIFlowRoot *this, UFG::UIFlow::eState old_state, UFG::UIFlow::eState new_state)
{
  UFG::UIFlowRoot *v3; // rbx
  __int32 v4; // er8
  int v5; // er8
  UFG::UIFlowInGame *v6; // rax
  UFG::UIFlowFrontEnd *v7; // rax

  v3 = this;
  v4 = new_state - 11;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        if ( UFG::UIHKPlayerObjectiveManager::mInstance )
          *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
        UFG::UIScreenManagerBase::queuePopOverlay(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "OpeningCredits");
        UFG::UIHKScreenHud::ResetWidgets();
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateUnloadGame_13);
        UFG::UIScreenManagerBase::queuePopAllScreens((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr);
        v3->vfptr->changeState((UFG::UIFlow *)&v3->vfptr, STATE_COMPLETE|0x8);
      }
    }
    else
    {
      v6 = UFG::LazyInitGet<UFG::UIFlowInGame>::get();
      v3->m_child_flow = (UFG::UIFlow *)&v6->vfptr;
      v6->vfptr->changeState((UFG::UIFlow *)&v6->vfptr, (UFG::UIFlow::eState)16i64);
    }
  }
  else
  {
    v7 = UFG::LazyInitGet<UFG::UIFlowFrontEnd>::get();
    v3->m_child_flow = (UFG::UIFlow *)&v7->vfptr;
    v7->vfptr->changeState((UFG::UIFlow *)&v7->vfptr, NUM_STATES|0x8);
  }
}

// File Line: 93
// RVA: 0x620F40
void __fastcall UFG::UIFlowRoot::handleExitState(UFG::UIFlowRoot *this, UFG::UIFlow::eState old_state, __int64 new_state)
{
  UFG::UIFlowRoot *v3; // rbx
  __int32 v4; // edx

  v3 = this;
  v4 = old_state - 11;
  if ( !v4 || v4 == 1 )
  {
    ((void (__fastcall *)(UFG::UIFlow *, signed __int64, __int64))this->m_child_flow->vfptr->changeState)(
      this->m_child_flow,
      3i64,
      new_state);
    v3->m_child_flow = 0i64;
  }
}

// File Line: 122
// RVA: 0x620570
char __fastcall UFG::UIFlowRoot::flowHandleMessage(UFG::UIFlowRoot *this, unsigned int msg_id, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // edi
  UFG::UIFlowRoot *v5; // rbx
  UFG::GameState *v6; // rax
  char result; // al
  UFG::UIFlow *v8; // rcx

  v3 = msg;
  v4 = msg_id;
  v5 = this;
  if ( !UFG::LazyInitGet<UFG::UIFXManager>::m_instance )
    UFG::LazyInitGet<UFG::UIFXManager>::m_instance = (UFG::UIFXManager *)UFG::qMemoryPool::Allocate(
                                                                           &gScaleformMemoryPool,
                                                                           1ui64,
                                                                           "UIFXManager",
                                                                           0i64,
                                                                           1u);
  if ( v4 == UI_HASH_LOAD_GAME_30 )
  {
    if ( v5->vfptr->changeState((UFG::UIFlow *)&v5->vfptr, STATE_DANGER)
      && !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_13) )
    {
      v6 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, uidGameStateLoadGame_13);
      if ( v6 )
        UFG::qString::Set(&v6->mGameStateUserDataStr, *(const char **)&v3[1].m_commandType);
    }
    result = 1;
  }
  else
  {
    result = 0;
    v8 = v5->m_child_flow;
    if ( !v8 || (result = v8->vfptr->flowHandleMessage(v8, v4, v3)) == 0 )
    {
      if ( v4 == UI_HASH_REQUEST_STATE_CHANGE_30 )
        result = v5->vfptr->changeState((UFG::UIFlow *)&v5->vfptr, (UFG::UIFlow::eState)LODWORD(v3[1].vfptr));
    }
  }
  return result;
}

