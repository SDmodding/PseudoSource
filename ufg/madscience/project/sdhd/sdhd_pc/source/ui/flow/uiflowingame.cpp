// File Line: 22
// RVA: 0x61F0B0
bool __fastcall UFG::UIFlowInGame::canChangeState(
        UFG::UIFlowInGame *this,
        UFG::UIFlow::eState old_state,
        unsigned int new_state)
{
  bool result; // al
  int v4; // eax
  int v5; // eax

  if ( new_state == 3 )
    return 1;
  switch ( old_state )
  {
    case 0:
      return new_state - 16 <= 1;
    case 2:
      if ( ((new_state - 17) & 0xFFFFFFFC) == 0 && new_state != 19 )
        goto LABEL_12;
      goto LABEL_9;
    case 3:
      return new_state == 16;
    case 16:
      return new_state == 17;
    case 17:
      if ( new_state > 0x16 )
        goto LABEL_9;
      v4 = 4980740;
      if ( !_bittest(&v4, new_state) )
        goto LABEL_9;
LABEL_12:
      result = 1;
      break;
    case 18:
      if ( new_state <= 0x16 && (v5 = 4718596, _bittest(&v5, new_state)) )
        result = 1;
      else
LABEL_9:
        result = 0;
      break;
    case 19:
    case 22:
      result = new_state == 17 || new_state == 2;
      break;
    case 20:
      result = new_state == 21;
      break;
    case 21:
      result = new_state == 20;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 77
// RVA: 0x620E10
void __fastcall UFG::UIFlowInGame::handleEnterState(
        UFG::UIFlowInGame *this,
        UFG::UIFlow::eState old_state,
        UFG::UIFlow::eState new_state)
{
  UFG::UIScreenTextureManager *v3; // rax

  if ( new_state == 17 )
  {
    v3 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v3, "Hud", 0i64);
  }
  else if ( new_state == (STATE_COMPLETE|0x10) )
  {
    UFG::UI::PauseGame("PauseMenu");
  }
}

// File Line: 96
// RVA: 0x620F30
void __fastcall UFG::UIFlowInGame::handleExitState(
        UFG::UIFlowInGame *this,
        UFG::UIFlow::eState old_state,
        UFG::UIFlow::eState new_state)
{
  if ( old_state == 17 )
    UFG::UIHKScreenHud::Pop();
}

// File Line: 109
// RVA: 0x6203D0
bool __fastcall UFG::UIFlowInGame::flowHandleMessage(UFG::UIFlowInGame *this, unsigned int msg_id, UFG::UIMessage *msg)
{
  UFG::UIFlow::eState m_state; // eax
  char v7; // bp
  bool v8; // di
  char v9; // al
  unsigned __int8 v10; // di
  NISManager *Instance; // rax

  m_state = this->m_state;
  if ( m_state >= 17 )
  {
    if ( m_state <= 18 )
    {
      if ( msg_id == UI_HASH_BUTTON_START_PRESSED_30 )
      {
        v7 = 1;
        v8 = UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance) == 0i64;
        if ( !UFG::UIHKScreenGlobalOverlay::mThis
          || (v9 = 0, !UFG::UIHKScreenGlobalOverlay::mThis->m_skookum_dialog_active) )
        {
          v9 = 1;
        }
        v10 = v9 & v8;
        Instance = NISManager::GetInstance();
        if ( Instance && Instance->mState )
          v7 = 0;
        if ( ((UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN) & (unsigned __int8)v7 & (UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") == 0i64) & v10) != 0 )
          return this->vfptr->changeState(this, STATE_COMPLETE|0x10);
      }
      else if ( msg_id == UI_HASH_SCREEN_PUSHED_30
             && !(unsigned int)UFG::qStringCompare(*(const char **)&msg[1].m_commandType, "LevelComplete", -1) )
      {
        this->vfptr->changeState(this, NUM_STATES|0x10);
        this->m_screen_id = msg[1].m_messageId;
      }
    }
    else if ( m_state == (STATE_COMPLETE|0x10) )
    {
      if ( msg_id == UI_HASH_GAME_UNPAUSE_20 )
      {
        this->vfptr->changeState(this, 17i64);
        return 0;
      }
    }
    else if ( m_state == (STATE_ANIMATE_COMPLETE|0x10) )
    {
      if ( msg_id == UI_HASH_GAME_UNPAUSE_20 )
      {
        this->vfptr->changeState(this, 20i64);
        return 0;
      }
    }
    else if ( m_state == (NUM_STATES|0x10)
           && msg_id == UI_HASH_SCREEN_POPPED_30
           && LODWORD(msg[1].vfptr) == this->m_screen_id )
    {
      UFG::UI::QuitGame(0i64);
      return 0;
    }
  }
  return 0;
}

