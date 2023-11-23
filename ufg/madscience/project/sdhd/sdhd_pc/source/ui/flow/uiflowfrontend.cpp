// File Line: 18
// RVA: 0x61F080
bool __fastcall UFG::UIFlowFrontEnd::canChangeState(
        UFG::UIFlowFrontEnd *this,
        UFG::UIFlow::eState old_state,
        UFG::UIFlow::eState new_state)
{
  int v3; // edx

  if ( old_state )
  {
    v3 = old_state - 14;
    if ( !v3 )
      return new_state == (NUM_STATES|STATE_NORMAL|0x8);
    if ( v3 != 1 )
      return 0;
  }
  return new_state == (NUM_STATES|0x8);
}

// File Line: 37
// RVA: 0x620DB0
void __fastcall UFG::UIFlowFrontEnd::handleEnterState(
        UFG::UIFlowFrontEnd *this,
        UFG::UIFlow::eState old_state,
        UFG::UIFlow::eState new_state)
{
  int v4; // r8d
  UFG::UIScreenTextureManager *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax

  v4 = new_state - 14;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v5 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueLoadAndPush(v5, "MainMenu", 0i64);
    }
  }
  else
  {
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v6, "Splash", 0i64);
    this->m_screen_id = -1;
  }
}

// File Line: 57
// RVA: 0x620F10
void __fastcall UFG::UIFlowFrontEnd::handleExitState(
        UFG::UIFlowFrontEnd *this,
        UFG::UIFlow::eState old_state,
        UFG::UIFlow::eState new_state)
{
  int v3; // edx

  v3 = old_state - 14;
  if ( v3 )
  {
    if ( v3 == 1 )
      this->m_child_flow = 0i64;
  }
  else
  {
    UFG::UI::QueuePopScreen("Splash");
  }
}

// File Line: 76
// RVA: 0x6202D0
bool __fastcall UFG::UIFlowFrontEnd::flowHandleMessage(
        UFG::UIFlowFrontEnd *this,
        unsigned int msg_id,
        UFG::UIMessage *msg)
{
  __int32 v6; // ecx
  __int64 v7; // rdx
  UFG::UIFlowVtbl *vfptr; // rax
  UFG::UIFlow *m_child_flow; // rcx
  bool result; // al

  v6 = this->m_state - 14;
  if ( v6 )
  {
    if ( v6 != 1 )
      goto LABEL_16;
    if ( msg_id == UI_HASH_SCREEN_PUSHED_30 )
    {
      if ( !(unsigned int)UFG::qStringCompare(*(const char **)&msg[1].m_commandType, "MainMenu", -1) )
        this->m_screen_id = msg[1].m_messageId;
      goto LABEL_16;
    }
    if ( msg_id != UI_HASH_SCREEN_POPPED_30 || LODWORD(msg[1].vfptr) != this->m_screen_id )
      goto LABEL_16;
    v7 = 14i64;
LABEL_15:
    vfptr = this->vfptr;
    this->m_screen_id = -1;
    vfptr->changeState(this, (UFG::UIFlow::eState)v7);
    goto LABEL_16;
  }
  if ( msg_id != UI_HASH_SCREEN_PUSHED_30 )
  {
    if ( msg_id != UI_HASH_SCREEN_POPPED_30 || LODWORD(msg[1].vfptr) != this->m_screen_id )
      goto LABEL_16;
    v7 = 15i64;
    goto LABEL_15;
  }
  if ( !(unsigned int)UFG::qStringCompare(*(const char **)&msg[1].m_commandType, "Splash", -1) )
    this->m_screen_id = msg[1].m_messageId;
LABEL_16:
  m_child_flow = this->m_child_flow;
  result = 0;
  if ( (!m_child_flow || !(result = m_child_flow->vfptr->flowHandleMessage(m_child_flow, msg_id, msg)))
    && msg_id == UI_HASH_REQUEST_STATE_CHANGE_30 )
  {
    return this->vfptr->changeState(this, (UFG::UIFlow::eState)msg[1].vfptr);
  }
  return result;
}

