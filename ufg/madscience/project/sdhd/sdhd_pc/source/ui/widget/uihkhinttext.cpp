// File Line: 46
// RVA: 0x5C43A0
void __fastcall UFG::UIHKHintText::UIHKHintText(UFG::UIHKHintText *this)
{
  UFG::UIHKHintText *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::UIHKHintTextVtbl *)&UFG::UIHKHintText::`vftable;
  this->m_eState = 0;
  this->m_bShowMsg = 0;
  this->m_Suppress = 0;
  UFG::qString::qString(&this->m_sHintTxt, &customWorldMapCaption);
  UFG::qString::qString(&v1->m_sOnlineDisconnectMessage);
  v1->m_bUseTimer = 0;
  v1->m_fDisplayTime = 0.0;
  v1->m_bRepeatMsg = 0;
  *(_QWORD *)&v1->m_fRepeatTime = 0i64;
  *(_QWORD *)&v1->m_fTimerRepeat = 0i64;
  *(_WORD *)&v1->m_queueOnlineDisconnectMessage = 0;
}

// File Line: 63
// RVA: 0x63AFD0
void __fastcall UFG::UIHKHintText::show(UFG::UIHKHintText *this, const char *text, float displayTime, bool repeat, float repeatTime)
{
  bool v5; // bp
  const char *v6; // rbx
  UFG::UIHKHintText *v7; // rdi
  const char *v8; // rsi
  const char *v9; // rax
  unsigned int v10; // eax
  UFG::UIGfxTranslator *v11; // rcx
  signed int v12; // eax
  unsigned int v13; // eax
  UFG::UIGfxTranslator *v14; // rcx
  unsigned int v15; // eax
  unsigned int v16; // edi
  UFG::GameLogManager::cGameLogCircularArray *v17; // rax
  UFG::GameLogManager::cGameLogCircularArray *v18; // rbx
  UFG::qString v19; // [rsp+28h] [rbp-50h]
  UFG::GameLogManager::sGameLogEntry obj; // [rsp+80h] [rbp+8h]
  float v21; // [rsp+98h] [rbp+20h]

  v5 = repeat;
  v6 = text;
  v7 = this;
  v8 = text;
  if ( text )
  {
    if ( *text == 36 )
      v8 = text + 1;
    v10 = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
    v11 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v11
      || (v9 = (const char *)v11->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, v10)) == 0i64 )
    {
      v9 = v8;
    }
  }
  else
  {
    v9 = 0i64;
  }
  UFG::qString::qString(&v19, v9);
  UFG::qString::Set(&v7->m_sHintTxt, v19.mData);
  v7->m_bShowMsg = 1;
  v7->m_bUseTimer = displayTime > 0.0;
  v7->m_fDisplayTime = displayTime;
  v7->m_bRepeatMsg = v5;
  v7->m_fRepeatTime = repeatTime;
  *(_QWORD *)&v7->m_fTimerDisplay = 0i64;
  v7->m_fHintReminderTimeout = 0.0;
  if ( !v7->m_Suppress )
  {
    v12 = 2;
    if ( v7->m_eState == 3 )
      v12 = 4;
    v7->m_eState = v12;
  }
  if ( v6 )
  {
    obj = (UFG::GameLogManager::sGameLogEntry)&v21;
    v21 = *(float *)&qSymbol_GameLogType_Hint_20.mUID;
    if ( !(_S15_5 & 1) )
    {
      _S15_5 |= 1u;
      glManager.vfptr = (UFG::GameLogManagerVtbl *)&UFG::GameLogManager::`vftable;
      atexit(UFG::GameLogManager::getInstance_::_2_::_dynamic_atexit_destructor_for__glManager__);
    }
    if ( (signed int)UFG::qStringLength(v6) >= 1 )
    {
      if ( *v6 == 36 )
        ++v6;
      v13 = UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
      v14 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v14 )
      {
        if ( v14->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, v13) )
        {
          obj = (UFG::GameLogManager::sGameLogEntry)&repeatTime;
          repeatTime = v21;
          v15 = UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
          v16 = v15;
          if ( v15 != UI_HASH_E_COMBAT_TRAIN_TITLE
            && v15 != UI_HASH_COMMON_TRC_PS3_PSN_SIGNED_OUT
            && v15 != UI_HASH_COMMON_TRC_PS3_ETHERNET_CABLE_UNPLUGGED )
          {
            v17 = UFG::GameLogManager::GetDataArray(&glManager);
            v18 = v17;
            if ( v17 )
            {
              if ( (unsigned int)UFG::GameLogManager::cGameLogCircularArray::Count(v17) >= 0x64 )
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
  bool v1; // zf
  UFG::UIHKHintText::eState v2; // eax

  v1 = this->m_isShowingOnlineDisconnect == 1;
  this->m_bShowMsg = 0;
  this->m_bUseTimer = 0;
  this->m_bRepeatMsg = 0;
  if ( v1 )
    this->m_isShowingOnlineDisconnect = 0;
  v2 = this->m_eState;
  if ( v2 == 3 )
  {
    this->m_eState = 4;
  }
  else if ( !((v2 - 2) & 0xFFFFFFFB) )
  {
    this->m_eState = 0;
  }
}

// File Line: 182
// RVA: 0x63B8C0
void __fastcall UFG::UIHKHintText::unsuppress(UFG::UIHKHintText *this)
{
  unsigned int v1; // eax
  unsigned int v2; // eax

  v1 = this->m_Suppress;
  if ( v1 )
  {
    v2 = v1 - 1;
    this->m_Suppress = v2;
    if ( !v2 )
    {
      if ( this->m_bUseTimer && this->m_fDisplayTime < this->m_fTimerDisplay )
      {
        if ( this->m_bRepeatMsg )
        {
          this->m_fTimerRepeat = 0.0;
          this->m_eState = 6;
        }
        else
        {
          this->m_eState = 0;
        }
      }
      else
      {
        this->m_eState = this->m_bShowMsg != 0 ? 2 : 0;
      }
    }
  }
}

// File Line: 212
// RVA: 0x5EB970
void __fastcall UFG::UIHKHintText::HandleScreenInit(UFG::UIHKHintText *this, UFG::UIScreen *screen)
{
  UFG::UIHKHintText::eState v2; // eax
  UFG::UIHKHintText *v3; // rbx
  UFG::OnlineManager *v4; // rax

  v2 = this->m_eState;
  v3 = this;
  if ( v2 == 2 )
  {
    if ( this->m_queueOnlineDisconnectMessage == 1 )
    {
      v4 = UFG::OnlineManager::Instance();
      if ( UFG::OnlineManager::IsNetworkSignedIn(v4) == 1 )
      {
        v3->m_queueOnlineDisconnectMessage = 0;
        v3->m_eState = 0;
      }
    }
  }
  else if ( v2 == 3 )
  {
    this->m_eState = 2;
  }
  else if ( (unsigned int)(v2 - 4) <= 1 )
  {
    this->m_eState = 0;
  }
}

// File Line: 251
// RVA: 0x5EAA80
char __fastcall UFG::UIHKHintText::HandleMessage(UFG::UIHKHintText *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  unsigned int v4; // eax
  UFG::UIHKScreenGlobalOverlay *v5; // rcx
  Scaleform::GFx::Movie *v6; // rcx
  char result; // al
  UFG::UIHKHintText::eState v8; // eax

  if ( msgId == UI_HASH_HINT_TEXT_OUTRO_DONE_20 )
  {
    if ( this->m_eState == 5 )
    {
      v4 = this->m_Suppress;
      if ( v4 )
      {
        this->m_eState = 1;
      }
      else if ( this->m_bShowMsg )
      {
        this->m_fTimerDisplay = 0.0;
        this->m_eState = 2;
      }
      else if ( this->m_bUseTimer && this->m_bRepeatMsg )
      {
        this->m_fTimerRepeat = 0.0;
        this->m_eState = 6;
      }
      else
      {
        this->m_eState = 0;
      }
      if ( v4 < 1 )
      {
        v5 = &gGlobalOverlaySentinel;
        if ( UFG::UIHKScreenGlobalOverlay::mThis )
          v5 = UFG::UIHKScreenGlobalOverlay::mThis;
        v6 = v5->mRenderable->m_movie.pObject;
        if ( v6 )
          Scaleform::GFx::Movie::Invoke(v6, "CalcSubtitlePosition", 0i64, 0i64);
      }
    }
    result = 1;
  }
  else if ( msgId == UI_HASH_PAUSE_SCREEN_INIT_20 )
  {
    v8 = this->m_eState;
    if ( v8 == 3 )
    {
      ++this->m_Suppress;
      this->m_eState = 4;
      this->m_bShowMsg = 1;
      result = 0;
    }
    else
    {
      if ( v8 != 4 )
        this->m_eState = 1;
      ++this->m_Suppress;
      result = 0;
    }
  }
  else
  {
    if ( msgId == UI_HASH_PAUSE_SCREEN_EXIT_20 )
      UFG::UIHKHintText::unsuppress(this);
    result = 0;
  }
  return result;
}

// File Line: 299
// RVA: 0x6146B0
void __usercall UFG::UIHKHintText::Update(UFG::UIHKHintText *this@<rcx>, UFG::UIScreen *screen@<rdx>, float elapsed@<xmm2>, __int64 a4@<rdi>)
{
  UFG::UIScreen *v4; // rdi
  UFG::UIHKHintText *v5; // rbx
  UFG::UIHKHintText::eState v6; // eax
  UFG::UIHKInfoPopupWidget::eState v7; // edx
  UFG::GameStatTracker *v8; // rax
  const char *v9; // rsi
  Scaleform::GFx::Movie *v10; // rbp
  UFG::UIHKScreenGlobalOverlay *v11; // rcx
  Scaleform::GFx::Movie *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]
  __int64 v17; // [rsp+70h] [rbp-8h]

  if ( screen )
  {
    v17 = a4;
    v4 = screen;
    v5 = this;
    v6 = this->m_eState;
    if ( (v6 & 0xFFFFFFFA || v6 == 1)
      && UFG::UIHKScreenHud::InfoPopup
      && (v7 = UFG::UIHKScreenHud::InfoPopup->mState) != 0
      && v7 != 5 )
    {
      this->m_eState = 6;
      this->m_fTimerRepeat = this->m_fRepeatTime;
    }
    else
    {
      switch ( v6 )
      {
        case 0:
          if ( this->m_queueOnlineDisconnectMessage == 1 )
          {
            UFG::UIHKHintText::show(this, this->m_sOnlineDisconnectMessage.mData, 10.0, 0, 0.0);
            v5->m_queueOnlineDisconnectMessage = 0;
          }
          break;
        case 1:
          this->m_fTimerDisplay = elapsed + this->m_fTimerDisplay;
          break;
        case 2:
          v8 = UFG::GameStatTracker::Instance();
          if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v8, GameHints) )
          {
            v9 = UFG::UI::LocalizeText(v5->m_sHintTxt.mData);
            v10 = v4->mRenderable->m_movie.pObject;
            pargs.pObjectInterface = 0i64;
            pargs.Type = 6;
            *(_QWORD *)&pargs.mValue.NValue = v9;
            Scaleform::GFx::Movie::Invoke(v10, "HintText_Show", 0i64, &pargs, 1u);
            v11 = &gGlobalOverlaySentinel;
            if ( UFG::UIHKScreenGlobalOverlay::mThis )
              v11 = UFG::UIHKScreenGlobalOverlay::mThis;
            v12 = v11->mRenderable->m_movie.pObject;
            if ( v12 )
              Scaleform::GFx::Movie::Invoke(v12, "CalcSubtitlePosition", 0i64, 0i64);
            v5->m_bShowMsg = 0;
            v5->m_eState = 3;
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0xC7346121,
                0i64,
                0,
                0i64);
            if ( ((unsigned int)pargs.Type >> 6) & 1 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
                pargs.pObjectInterface,
                &pargs,
                *(_QWORD *)&pargs.mValue.NValue);
              pargs.pObjectInterface = 0i64;
            }
            pargs.Type = 0;
          }
          break;
        case 3:
          v13 = elapsed + this->m_fTimerDisplay;
          this->m_fTimerDisplay = v13;
          if ( this->m_bUseTimer && v13 > this->m_fDisplayTime )
          {
            this->m_eState = 4;
          }
          else
          {
            v14 = this->m_fHintReminderTimeout - elapsed;
            this->m_fHintReminderTimeout = v14;
            if ( v14 <= 0.0 )
            {
              this->m_fHintReminderTimeout = UFG::UIHKHintText::g_fHintReminderPeriod;
              Scaleform::GFx::Movie::Invoke(
                v4->mRenderable->m_movie.pObject,
                "InfoFlasher_ShowHintReminder",
                0i64,
                0i64,
                0);
            }
          }
          break;
        case 4:
          Scaleform::GFx::Movie::Invoke(v4->mRenderable->m_movie.pObject, "HintText_Hide", 0i64, 0i64, 0);
          v5->m_eState = 5;
          break;
        case 6:
          v15 = elapsed + this->m_fTimerRepeat;
          this->m_fTimerRepeat = v15;
          if ( v15 > this->m_fRepeatTime )
          {
            this->m_fTimerDisplay = 0.0;
            this->m_eState = 2;
          }
          break;
        default:
          return;
      }
    }
  }
}

