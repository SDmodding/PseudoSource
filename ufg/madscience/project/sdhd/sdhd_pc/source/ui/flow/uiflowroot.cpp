// File Line: 24
// RVA: 0x61F1D0
bool __fastcall UFG::UIFlowRoot::canChangeState(
        UFG::UIFlowRoot *this,
        UFG::UIFlow::eState old_state,
        UFG::UIFlow::eState new_state)
{
  int v3; // edx
  int v4; // edx
  int v5; // edx

  if ( old_state == STATE_INVALID )
    return new_state == (STATE_COMPLETE|0x8);
  v3 = old_state - 2;
  if ( !v3 )
    return new_state == 12;
  v4 = v3 - 9;
  if ( !v4 )
    return new_state == STATE_DANGER;
  v5 = v4 - 1;
  if ( v5 )
  {
    if ( v5 != 1 )
      return 0;
    return new_state == (STATE_COMPLETE|0x8);
  }
  return new_state == (STATE_ANIMATE_COMPLETE|0x8) || new_state == STATE_DANGER;
}

// File Line: 50
// RVA: 0x620E50
void __fastcall UFG::UIFlowRoot::handleEnterState(
        UFG::UIFlowRoot *this,
        UFG::UIFlow::eState old_state,
        UFG::UIFlow::eState new_state)
{
  int v4; // r8d
  int v5; // r8d
  UFG::UIFlowInGame *v6; // rax
  UFG::UIFlowFrontEnd *v7; // rax

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
        UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "OpeningCredits");
        UFG::UIHKScreenHud::ResetWidgets();
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateUnloadGame_13);
        UFG::UIScreenManagerBase::queuePopAllScreens(UFG::UIScreenManager::s_instance);
        this->vfptr->changeState(this, STATE_COMPLETE|0x8);
      }
    }
    else
    {
      v6 = UFG::LazyInitGet<UFG::UIFlowInGame>::get();
      this->m_child_flow = v6;
      v6->vfptr->changeState(v6, (UFG::UIFlow::eState)16i64);
    }
  }
  else
  {
    v7 = UFG::LazyInitGet<UFG::UIFlowFrontEnd>::get();
    this->m_child_flow = v7;
    v7->vfptr->changeState(v7, NUM_STATES|0x8);
  }
}

// File Line: 93
// RVA: 0x620F40
void __fastcall UFG::UIFlowRoot::handleExitState(
        UFG::UIFlowRoot *this,
        UFG::UIFlow::eState old_state,
        __int64 new_state)
{
  if ( (unsigned int)(old_state - 11) <= 1 )
  {
    ((void (__fastcall *)(UFG::UIFlow *, __int64, __int64))this->m_child_flow->UFG::UIFlow::vfptr->changeState)(
      this->m_child_flow,
      3i64,
      new_state);
    this->m_child_flow = 0i64;
  }
}

// File Line: 122
// RVA: 0x620570
char __fastcall UFG::UIFlowRoot::flowHandleMessage(UFG::UIFlowRoot *this, unsigned int msg_id, UFG::UIMessage *msg)
{
  UFG::GameState *GameStateObj; // rax
  char result; // al
  UFG::UIFlow *m_child_flow; // rcx

  if ( !UFG::LazyInitGet<UFG::UIFXManager>::m_instance )
    UFG::LazyInitGet<UFG::UIFXManager>::m_instance = (UFG::UIFXManager *)UFG::qMemoryPool::Allocate(
                                                                           &gScaleformMemoryPool,
                                                                           1ui64,
                                                                           "UIFXManager",
                                                                           0i64,
                                                                           1u);
  if ( msg_id == UI_HASH_LOAD_GAME_30 )
  {
    if ( this->vfptr->changeState(this, STATE_DANGER)
      && !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_13) )
    {
      GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, uidGameStateLoadGame_13);
      if ( GameStateObj )
        UFG::qString::Set(&GameStateObj->mGameStateUserDataStr, *(const char **)&msg[1].m_commandType);
    }
    return 1;
  }
  else
  {
    result = 0;
    m_child_flow = this->m_child_flow;
    if ( (!m_child_flow || (result = m_child_flow->vfptr->flowHandleMessage(m_child_flow, msg_id, msg)) == 0)
      && msg_id == UI_HASH_REQUEST_STATE_CHANGE_30 )
    {
      return this->vfptr->changeState(this, (UFG::UIFlow::eState)msg[1].vfptr);
    }
  }
  return result;
}

