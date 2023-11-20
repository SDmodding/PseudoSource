// File Line: 22
// RVA: 0x61F0B0
bool __fastcall UFG::UIFlowInGame::canChangeState(UFG::UIFlowInGame *this, UFG::UIFlow::eState old_state, UFG::UIFlow::eState new_state)
{
  bool result; // al
  signed int v4; // eax
  signed int v5; // eax

  if ( new_state == 3 )
    return 1;
  switch ( 0x40000000 )
  {
    case 0:
      return (unsigned int)(new_state - 16) <= 1;
    case 2:
      if ( !((new_state - 17) & 0xFFFFFFFC) && new_state != 19 )
        goto LABEL_12;
      goto LABEL_9;
    case 3:
      return new_state == 16;
    case 16:
      return new_state == 17;
    case 17:
      if ( (unsigned int)new_state > 0x16 )
        goto LABEL_9;
      v4 = 4980740;
      if ( !_bittest(&v4, new_state) )
        goto LABEL_9;
LABEL_12:
      result = 1;
      break;
    case 18:
      if ( (unsigned int)new_state <= 0x16 && (v5 = 4718596, _bittest(&v5, new_state)) )
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
void __fastcall UFG::UIFlowInGame::handleEnterState(UFG::UIFlowInGame *this, UFG::UIFlow::eState old_state, UFG::UIFlow::eState new_state)
{
  UFG::UIScreenTextureManager *v3; // rax

  if ( new_state == 17 )
  {
    v3 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v3, "Hud", 0i64);
  }
  else if ( new_state == 19 )
  {
    UFG::UI::PauseGame("PauseMenu");
  }
}

// File Line: 96
// RVA: 0x620F30
void __fastcall UFG::UIFlowInGame::handleExitState(UFG::UIFlowInGame *this, UFG::UIFlow::eState old_state, UFG::UIFlow::eState new_state)
{
  JUMPOUT(old_state, 17, UFG::UIHKScreenHud::Pop);
}

// File Line: 109
// RVA: 0x6203D0
bool __fastcall UFG::UIFlowInGame::flowHandleMessage(UFG::UIFlowInGame *this, unsigned int msg_id, UFG::UIMessage *msg)
{
  UFG::UIFlow::eState v3; // eax
  UFG::UIMessage *v4; // rdi
  UFG::UIFlowInGame *v5; // rbx
  char v7; // bp
  bool v8; // di
  char v9; // al
  unsigned __int8 v10; // di
  NISManager *v11; // rax

  v3 = this->m_state;
  v4 = msg;
  v5 = this;
  if ( (signed int)v3 >= 17 )
  {
    if ( (signed int)v3 <= 18 )
    {
      if ( msg_id == UI_HASH_BUTTON_START_PRESSED_30 )
      {
        v7 = 1;
        v8 = UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) == 0i64;
        if ( !UFG::UIHKScreenGlobalOverlay::mThis
          || (v9 = 0, !UFG::UIHKScreenGlobalOverlay::mThis->m_skookum_dialog_active) )
        {
          v9 = 1;
        }
        v10 = v9 & v8;
        v11 = NISManager::GetInstance();
        if ( v11 && v11->mState )
          v7 = 0;
        if ( (UFG::UIHK_NISOverlay::m_curtains.m_state == 0) & (unsigned __int8)v7 & (UFG::UIScreenManagerBase::getScreen(
                                                                                        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                                                                        "NISPause") == 0i64) & v10 )
          return v5->vfptr->changeState((UFG::UIFlow *)&v5->vfptr, STATE_COMPLETE|0x10);
      }
      else if ( msg_id == UI_HASH_SCREEN_PUSHED_30
             && !(unsigned int)UFG::qStringCompare(*(const char **)&msg[1].m_commandType, "LevelComplete", -1) )
      {
        v5->vfptr->changeState((UFG::UIFlow *)&v5->vfptr, NUM_STATES|0x10);
        v5->m_screen_id = v4[1].m_messageId;
      }
    }
    else if ( v3 == 19 )
    {
      if ( msg_id == UI_HASH_GAME_UNPAUSE_20 )
      {
        this->vfptr->changeState((UFG::UIFlow *)this, (UFG::UIFlow::eState)17i64);
        return 0;
      }
    }
    else if ( v3 == 21 )
    {
      if ( msg_id == UI_HASH_GAME_UNPAUSE_20 )
      {
        this->vfptr->changeState((UFG::UIFlow *)this, (UFG::UIFlow::eState)20i64);
        return 0;
      }
    }
    else if ( v3 == 22 && msg_id == UI_HASH_SCREEN_POPPED_30 && LODWORD(msg[1].vfptr) == this->m_screen_id )
    {
      UFG::UI::QuitGame(0i64);
      return 0;
    }
  }
  return 0;
}

