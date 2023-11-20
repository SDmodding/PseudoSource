// File Line: 18
// RVA: 0x61F080
bool __fastcall UFG::UIFlowFrontEnd::canChangeState(UFG::UIFlowFrontEnd *this, UFG::UIFlow::eState old_state, UFG::UIFlow::eState new_state)
{
  __int32 v3; // edx

  if ( old_state )
  {
    v3 = old_state - 14;
    if ( !v3 )
      return new_state == 15;
    if ( v3 != 1 )
      return 0;
  }
  return new_state == 14;
}

// File Line: 37
// RVA: 0x620DB0
void __fastcall UFG::UIFlowFrontEnd::handleEnterState(UFG::UIFlowFrontEnd *this, UFG::UIFlow::eState old_state, UFG::UIFlow::eState new_state)
{
  UFG::UIFlowFrontEnd *v3; // rbx
  __int32 v4; // er8
  UFG::UIScreenTextureManager *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax

  v3 = this;
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
    v3->m_screen_id = -1;
  }
}

// File Line: 57
// RVA: 0x620F10
void __fastcall UFG::UIFlowFrontEnd::handleExitState(UFG::UIFlowFrontEnd *this, UFG::UIFlow::eState old_state, UFG::UIFlow::eState new_state)
{
  __int32 v3; // edx

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
bool __fastcall UFG::UIFlowFrontEnd::flowHandleMessage(UFG::UIFlowFrontEnd *this, unsigned int msg_id, UFG::UIMessage *msg)
{
  UFG::UIFlowFrontEnd *v3; // rbx
  UFG::UIMessage *v4; // rdi
  unsigned int v5; // esi
  __int32 v6; // ecx
  signed __int64 v7; // rdx
  UFG::UIFlowVtbl *v8; // rax
  UFG::UIFlow *v9; // rcx
  bool result; // al

  v3 = this;
  v4 = msg;
  v5 = msg_id;
  v6 = this->m_state - 14;
  if ( v6 )
  {
    if ( v6 != 1 )
      goto LABEL_16;
    if ( msg_id == UI_HASH_SCREEN_PUSHED_30 )
    {
      if ( !(unsigned int)UFG::qStringCompare(*(const char **)&msg[1].m_commandType, "MainMenu", -1) )
        v3->m_screen_id = v4[1].m_messageId;
      goto LABEL_16;
    }
    if ( msg_id != UI_HASH_SCREEN_POPPED_30 || LODWORD(msg[1].vfptr) != v3->m_screen_id )
      goto LABEL_16;
    v7 = 14i64;
LABEL_15:
    v8 = v3->vfptr;
    v3->m_screen_id = -1;
    v8->changeState((UFG::UIFlow *)&v3->vfptr, (UFG::UIFlow::eState)v7);
    goto LABEL_16;
  }
  if ( msg_id != UI_HASH_SCREEN_PUSHED_30 )
  {
    if ( msg_id != UI_HASH_SCREEN_POPPED_30 || LODWORD(msg[1].vfptr) != v3->m_screen_id )
      goto LABEL_16;
    v7 = 15i64;
    goto LABEL_15;
  }
  if ( !(unsigned int)UFG::qStringCompare(*(const char **)&msg[1].m_commandType, "Splash", -1) )
    v3->m_screen_id = v4[1].m_messageId;
LABEL_16:
  v9 = v3->m_child_flow;
  result = 0;
  if ( !v9 || (result = v9->vfptr->flowHandleMessage(v9, v5, v4)) == 0 )
  {
    if ( v5 == UI_HASH_REQUEST_STATE_CHANGE_30 )
      result = v3->vfptr->changeState((UFG::UIFlow *)&v3->vfptr, (UFG::UIFlow::eState)LODWORD(v4[1].vfptr));
  }
  return result;
}

