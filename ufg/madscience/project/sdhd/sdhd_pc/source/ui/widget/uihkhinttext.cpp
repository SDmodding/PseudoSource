// File Line: 46
// RVA: 0x5C43A0
void __fastcall UFG::UIHKHintText::UIHKHintText(UFG::UIHKHintText *this)
{
  this->vfptr = (UFG::UIHKHintTextVtbl *)&UFG::UIHKHintText::`vftable;
  this->m_eState = STATE_IDLE;
  this->m_bShowMsg = 0;
  this->m_Suppress = 0;
  UFG::qString::qString(&this->m_sHintTxt, &customCaption);
  UFG::qString::qString(&this->m_sOnlineDisconnectMessage);
  this->m_bUseTimer = 0;
  this->m_fDisplayTime = 0.0;
  this->m_bRepeatMsg = 0;
  *(_QWORD *)&this->m_fRepeatTime = 0i64;
  *(_QWORD *)&this->m_fTimerRepeat = 0i64;
  *(_WORD *)&this->m_queueOnlineDisconnectMessage = 0;
}

// File Line: 63
// RVA: 0x63AFD0
void __fastcall UFG::UIHKHintText::show(
        UFG::UIHKHintText *this,
        const char *text,
        float displayTime,
        bool repeat,
        float repeatTime)
{
  const char *v6; // rbx
  const char *v8; // rsi
  unsigned int v9; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v11; // rax
  UFG::UIHKHintText::eState v12; // eax
  unsigned int v13; // eax
  UFG::UIGfxTranslator *v14; // rcx
  unsigned int v15; // eax
  unsigned int v16; // edi
  UFG::GameLogManager::cGameLogCircularArray *DataArray; // rax
  UFG::GameLogManager::cGameLogCircularArray *v18; // rbx
  UFG::qString v19; // [rsp+28h] [rbp-50h] BYREF
  UFG::GameLogManager::sGameLogEntry obj; // [rsp+80h] [rbp+8h] BYREF
  float v21; // [rsp+98h] [rbp+20h] BYREF

  v6 = text;
  v8 = text;
  if ( text )
  {
    if ( *text == 36 )
      v8 = text + 1;
    v9 = UFG::qStringHashUpper32(v8, -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v11 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v9)) == 0i64 )
      v11 = v8;
    UFG::qString::qString(&v19, v11);
  }
  else
  {
    UFG::qString::qString(&v19, 0i64);
  }
  UFG::qString::Set(&this->m_sHintTxt, v19.mData);
  this->m_bShowMsg = 1;
  this->m_bUseTimer = displayTime > 0.0;
  this->m_fDisplayTime = displayTime;
  this->m_bRepeatMsg = repeat;
  this->m_fRepeatTime = repeatTime;
  *(_QWORD *)&this->m_fTimerDisplay = 0i64;
  this->m_fHintReminderTimeout = 0.0;
  if ( !this->m_Suppress )
  {
    v12 = STATE_PHONE_CONTACTS;
    if ( this->m_eState == STATE_TEXT_INBOX )
      v12 = STATE_INCOMING_CALL;
    this->m_eState = v12;
  }
  if ( v6 )
  {
    obj = (UFG::GameLogManager::sGameLogEntry)&v21;
    v21 = *(float *)&qSymbol_GameLogType_Hint_20.mUID;
    if ( (_S15_5 & 1) == 0 )
    {
      _S15_5 |= 1u;
      glManager.vfptr = (UFG::GameLogManagerVtbl *)&UFG::GameLogManager::`vftable;
      atexit(UFG::GameLogManager::getInstance_::_2_::_dynamic_atexit_destructor_for__glManager__);
    }
    if ( (int)UFG::qStringLength(v6) >= 1 )
    {
      if ( *v6 == 36 )
        ++v6;
      v13 = UFG::qStringHashUpper32(v6, -1);
      v14 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v14 )
      {
        if ( v14->vfptr[5].__vecDelDtor(v14, v13) )
        {
          obj = (UFG::GameLogManager::sGameLogEntry)&repeatTime;
          repeatTime = v21;
          v15 = UFG::qStringHashUpper32(v6, -1);
          v16 = v15;
          if ( v15 != UI_HASH_E_COMBAT_TRAIN_TITLE
            && v15 != UI_HASH_COMMON_TRC_PS3_PSN_SIGNED_OUT
            && v15 != UI_HASH_COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED )
          {
            DataArray = UFG::GameLogManager::GetDataArray(&glManager);
            v18 = DataArray;
            if ( DataArray )
            {
              if ( (unsigned int)UFG::GameLogManager::cGameLogCircularArray::Count(DataArray) >= 0x64 )
                UFG::GameLogManager::cGameLogCircularArray::RemoveHead(v18);
              *(float *)&obj.type.mUID = repeatTime;
              obj.string_hash = v16;
              UFG::GameLogManager::cGameLogCircularArray::AddTail(v18, &obj);
            }
          }
        }
      }
    }
  }
  UFG::qString::~qString(&v19);
}

// File Line: 116
// RVA: 0x62FBF0
void __fastcall UFG::UIHKHintText::hide(UFG::UIHKHintText *this)
{
  bool m_isShowingOnlineDisconnect; // zf
  UFG::UIHKHintText::eState m_eState; // eax

  m_isShowingOnlineDisconnect = this->m_isShowingOnlineDisconnect;
  this->m_bShowMsg = 0;
  this->m_bUseTimer = 0;
  this->m_bRepeatMsg = 0;
  if ( m_isShowingOnlineDisconnect )
    this->m_isShowingOnlineDisconnect = 0;
  m_eState = this->m_eState;
  if ( m_eState == STATE_TEXT_INBOX )
  {
    this->m_eState = STATE_INCOMING_CALL;
  }
  else if ( ((m_eState - 2) & 0xFFFFFFFB) == 0 )
  {
    this->m_eState = STATE_IDLE;
  }
}

// File Line: 182
// RVA: 0x63B8C0
void __fastcall UFG::UIHKHintText::unsuppress(UFG::UIHKHintText *this)
{
  unsigned int m_Suppress; // eax
  unsigned int v2; // eax

  m_Suppress = this->m_Suppress;
  if ( m_Suppress )
  {
    v2 = m_Suppress - 1;
    this->m_Suppress = v2;
    if ( !v2 )
    {
      if ( this->m_bUseTimer && this->m_fDisplayTime < this->m_fTimerDisplay )
      {
        if ( this->m_bRepeatMsg )
        {
          this->m_fTimerRepeat = 0.0;
          this->m_eState = STATE_INCOMING_TEXT;
        }
        else
        {
          this->m_eState = STATE_IDLE;
        }
      }
      else
      {
        this->m_eState = this->m_bShowMsg ? STATE_PHONE_CONTACTS : STATE_IDLE;
      }
    }
  }
}

// File Line: 212
// RVA: 0x5EB970
void __fastcall UFG::UIHKHintText::HandleScreenInit(UFG::UIHKHintText *this, UFG::UIScreen *screen)
{
  UFG::UIHKHintText::eState m_eState; // eax
  UFG::OnlineManager *v4; // rax

  m_eState = this->m_eState;
  if ( m_eState == STATE_PHONE_CONTACTS )
  {
    if ( this->m_queueOnlineDisconnectMessage )
    {
      v4 = UFG::OnlineManager::Instance();
      if ( UFG::OnlineManager::IsNetworkSignedIn(v4) )
      {
        this->m_queueOnlineDisconnectMessage = 0;
        this->m_eState = STATE_IDLE;
      }
    }
  }
  else if ( m_eState == STATE_TEXT_INBOX )
  {
    this->m_eState = STATE_PHONE_CONTACTS;
  }
  else if ( (unsigned int)(m_eState - 4) <= 1 )
  {
    this->m_eState = STATE_IDLE;
  }
}

// File Line: 251
// RVA: 0x5EAA80
char __fastcall UFG::UIHKHintText::HandleMessage(
        UFG::UIHKHintText *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  unsigned int m_Suppress; // eax
  UFG::UIHKScreenGlobalOverlay *v5; // rcx
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::UIHKHintText::eState m_eState; // eax

  if ( msgId == UI_HASH_HINT_TEXT_OUTRO_DONE_20 )
  {
    if ( this->m_eState == STATE_OUTGOING_CALL )
    {
      m_Suppress = this->m_Suppress;
      if ( m_Suppress )
      {
        this->m_eState = STATE_ROOT_MENU;
      }
      else if ( this->m_bShowMsg )
      {
        this->m_fTimerDisplay = 0.0;
        this->m_eState = STATE_PHONE_CONTACTS;
      }
      else if ( this->m_bUseTimer && this->m_bRepeatMsg )
      {
        this->m_fTimerRepeat = 0.0;
        this->m_eState = STATE_INCOMING_TEXT;
      }
      else
      {
        this->m_eState = STATE_IDLE;
      }
      if ( !m_Suppress )
      {
        v5 = &gGlobalOverlaySentinel;
        if ( UFG::UIHKScreenGlobalOverlay::mThis )
          v5 = UFG::UIHKScreenGlobalOverlay::mThis;
        pObject = v5->mRenderable->m_movie.pObject;
        if ( pObject )
          Scaleform::GFx::Movie::Invoke(pObject, "CalcSubtitlePosition", 0i64, 0i64);
      }
    }
    return 1;
  }
  else if ( msgId == UI_HASH_PAUSE_SCREEN_INIT_20 )
  {
    m_eState = this->m_eState;
    if ( m_eState == STATE_TEXT_INBOX )
    {
      ++this->m_Suppress;
      this->m_eState = STATE_INCOMING_CALL;
      this->m_bShowMsg = 1;
      return 0;
    }
    else
    {
      if ( m_eState != STATE_INCOMING_CALL )
        this->m_eState = STATE_ROOT_MENU;
      ++this->m_Suppress;
      return 0;
    }
  }
  else
  {
    if ( msgId == UI_HASH_PAUSE_SCREEN_EXIT_20 )
      UFG::UIHKHintText::unsuppress(this);
    return 0;
  }
}

// File Line: 299
// RVA: 0x6146B0
void __fastcall UFG::UIHKHintText::Update(UFG::UIHKHintText *this, UFG::UIScreen *screen, float elapsed)
{
  __int64 v3; // rdi
  UFG::UIHKHintText::eState m_eState; // eax
  UFG::UIHKInfoPopupWidget::eState mState; // edx
  UFG::GameStatTracker *v8; // rax
  const char *v9; // rsi
  Scaleform::GFx::Movie *pObject; // rbp
  UFG::UIHKScreenGlobalOverlay *v11; // rcx
  Scaleform::GFx::Movie *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF
  __int64 v17; // [rsp+70h] [rbp-8h]

  if ( screen )
  {
    v17 = v3;
    m_eState = this->m_eState;
    if ( ((m_eState & 0xFFFFFFFA) != 0 || m_eState == STATE_ROOT_MENU)
      && UFG::UIHKScreenHud::InfoPopup
      && (mState = UFG::UIHKScreenHud::InfoPopup->mState) != STATE_IDLE
      && mState != STATE_OUTGOING_CALL )
    {
      this->m_eState = STATE_INCOMING_TEXT;
      this->m_fTimerRepeat = this->m_fRepeatTime;
    }
    else
    {
      switch ( m_eState )
      {
        case STATE_IDLE:
          if ( this->m_queueOnlineDisconnectMessage )
          {
            UFG::UIHKHintText::show(this, this->m_sOnlineDisconnectMessage.mData, 10.0, 0, 0.0);
            this->m_queueOnlineDisconnectMessage = 0;
          }
          break;
        case STATE_ROOT_MENU:
          this->m_fTimerDisplay = elapsed + this->m_fTimerDisplay;
          break;
        case STATE_PHONE_CONTACTS:
          v8 = UFG::GameStatTracker::Instance();
          if ( UFG::GameStatTracker::GetStat(v8, GameHints) )
          {
            v9 = UFG::UI::LocalizeText(this->m_sHintTxt.mData);
            pObject = screen->mRenderable->m_movie.pObject;
            pargs.pObjectInterface = 0i64;
            pargs.Type = VT_String;
            pargs.mValue.pString = v9;
            Scaleform::GFx::Movie::Invoke(pObject, "HintText_Show", 0i64, &pargs, 1u);
            v11 = &gGlobalOverlaySentinel;
            if ( UFG::UIHKScreenGlobalOverlay::mThis )
              v11 = UFG::UIHKScreenGlobalOverlay::mThis;
            v12 = v11->mRenderable->m_movie.pObject;
            if ( v12 )
              Scaleform::GFx::Movie::Invoke(v12, "CalcSubtitlePosition", 0i64, 0i64);
            this->m_bShowMsg = 0;
            this->m_eState = STATE_TEXT_INBOX;
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC7346121, 0i64, 0, 0i64);
            if ( (pargs.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
                pargs.pObjectInterface,
                &pargs,
                pargs.mValue);
              pargs.pObjectInterface = 0i64;
            }
            pargs.Type = VT_Undefined;
          }
          break;
        case STATE_TEXT_INBOX:
          v13 = elapsed + this->m_fTimerDisplay;
          this->m_fTimerDisplay = v13;
          if ( this->m_bUseTimer && v13 > this->m_fDisplayTime )
          {
            this->m_eState = STATE_INCOMING_CALL;
          }
          else
          {
            v14 = this->m_fHintReminderTimeout - elapsed;
            this->m_fHintReminderTimeout = v14;
            if ( v14 <= 0.0 )
            {
              this->m_fHintReminderTimeout = UFG::UIHKHintText::g_fHintReminderPeriod;
              Scaleform::GFx::Movie::Invoke(
                screen->mRenderable->m_movie.pObject,
                "InfoFlasher_ShowHintReminder",
                0i64,
                0i64,
                0);
            }
          }
          break;
        case STATE_INCOMING_CALL:
          Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "HintText_Hide", 0i64, 0i64, 0);
          this->m_eState = STATE_OUTGOING_CALL;
          break;
        case STATE_INCOMING_TEXT:
          v15 = elapsed + this->m_fTimerRepeat;
          this->m_fTimerRepeat = v15;
          if ( v15 > this->m_fRepeatTime )
          {
            this->m_fTimerDisplay = 0.0;
            this->m_eState = STATE_PHONE_CONTACTS;
          }
          break;
        default:
          return;
      }
    }
  }
}

