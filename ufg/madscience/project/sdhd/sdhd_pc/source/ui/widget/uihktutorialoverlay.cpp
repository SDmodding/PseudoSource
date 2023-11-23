// File Line: 30
// RVA: 0x5CD950
void __fastcall UFG::UIHKTutorialOverlay::~UIHKTutorialOverlay(UFG::UIHKTutorialOverlay *this)
{
  this->vfptr = (UFG::UIHKTutorialOverlayVtbl *)&UFG::UIHKTutorialOverlay::`vftable;
  UFG::qString::~qString(&this->m_BodyTxt);
  UFG::qString::~qString(&this->m_TitleTxt);
}

// File Line: 39
// RVA: 0x63B200
void __fastcall UFG::UIHKTutorialOverlay::show(
        UFG::UIHKTutorialOverlay *this,
        const char *titleTxt,
        const char *bodyTxt)
{
  UFG::UIHKTutorialOverlay::eState v5; // eax
  UFG::qSymbol log_type; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_log_type; // [rsp+50h] [rbp+18h]

  UFG::qString::Set(&this->m_TitleTxt, titleTxt);
  UFG::qString::Set(&this->m_BodyTxt, bodyTxt);
  this->m_bShowMsg = 1;
  v5 = STATE_ROOT_MENU;
  if ( this->m_eState == STATE_PHONE_CONTACTS )
    v5 = STATE_TEXT_INBOX;
  this->m_eState = v5;
  if ( bodyTxt )
  {
    p_log_type = &log_type;
    log_type.mUID = qSymbol_GameLogType_Hint_20.mUID;
    if ( (_S15_5 & 1) == 0 )
    {
      _S15_5 |= 1u;
      glManager.vfptr = (UFG::GameLogManagerVtbl *)&UFG::GameLogManager::`vftable;
      atexit(UFG::GameLogManager::getInstance_::_2_::_dynamic_atexit_destructor_for__glManager__);
    }
    UFG::GameLogManager::LogItem(&glManager, &log_type.mUID, bodyTxt);
  }
}

// File Line: 60
// RVA: 0x62FC30
void __fastcall UFG::UIHKTutorialOverlay::hide(UFG::UIHKTutorialOverlay *this)
{
  UFG::UIHKTutorialOverlay::eState m_eState; // eax

  m_eState = this->m_eState;
  if ( m_eState == STATE_PHONE_CONTACTS )
  {
    this->m_eState = STATE_TEXT_INBOX;
  }
  else if ( m_eState == STATE_ROOT_MENU )
  {
    this->m_bShowMsg = 0;
    this->m_eState = STATE_IDLE;
  }
}

// File Line: 82
// RVA: 0x62E980
char __fastcall UFG::UIHKTutorialOverlay::handleMessage(
        UFG::UIHKTutorialOverlay *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  if ( msgId != UI_HASH_TUTORIAL_OVERLAY_OUTRO_DONE_20 )
    return 0;
  if ( this->m_eState == STATE_INCOMING_CALL )
  {
    this->m_eState = this->m_bShowMsg;
    Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "Set_Subtitle_Position2", 0i64, 0i64, 0);
  }
  return 1;
}

// File Line: 108
// RVA: 0x640DE0
void __fastcall UFG::UIHKTutorialOverlay::update(UFG::UIHKTutorialOverlay *this, UFG::UIScreen *screen, float elapsed)
{
  const char *v5; // rsi
  const char *v6; // r14
  Scaleform::GFx::Movie *pObject; // rbp
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-78h] BYREF
  char v9[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v10; // [rsp+80h] [rbp-38h]
  int v11; // [rsp+88h] [rbp-30h]
  const char *v12; // [rsp+90h] [rbp-28h]

  if ( screen )
  {
    if ( this->m_eState == STATE_ROOT_MENU )
    {
      v5 = UFG::UI::LocalizeText(this->m_TitleTxt.mData);
      v6 = UFG::UI::LocalizeText(this->m_BodyTxt.mData);
      pObject = screen->mRenderable->m_movie.pObject;
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue.pString = v5;
      if ( (v11 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v10 + 16i64))(v10, v9, v12);
        v10 = 0i64;
      }
      v11 = 6;
      v12 = v6;
      Scaleform::GFx::Movie::Invoke(pObject, "TutorialPopup_Show", 0i64, &ptr, 2u);
      Scaleform::GFx::Movie::Invoke(pObject, "Set_Subtitle_Position1", 0i64, 0i64, 0);
      this->m_bShowMsg = 0;
      this->m_eState = STATE_PHONE_CONTACTS;
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
    else if ( this->m_eState == STATE_TEXT_INBOX )
    {
      Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "TutorialPopup_Hide", 0i64, 0i64, 0);
      this->m_eState = STATE_INCOMING_CALL;
    }
  }
}

