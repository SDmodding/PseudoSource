// File Line: 30
// RVA: 0x5CD950
void __fastcall UFG::UIHKTutorialOverlay::~UIHKTutorialOverlay(UFG::UIHKTutorialOverlay *this)
{
  UFG::UIHKTutorialOverlay *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::UIHKTutorialOverlayVtbl *)&UFG::UIHKTutorialOverlay::`vftable';
  UFG::qString::~qString(&this->m_BodyTxt);
  UFG::qString::~qString(&v1->m_TitleTxt);
}

// File Line: 39
// RVA: 0x63B200
void __fastcall UFG::UIHKTutorialOverlay::show(UFG::UIHKTutorialOverlay *this, const char *titleTxt, const char *bodyTxt)
{
  const char *v3; // rdi
  UFG::UIHKTutorialOverlay *v4; // rbx
  signed int v5; // eax
  UFG::qSymbol log_type; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v7; // [rsp+50h] [rbp+18h]

  v3 = bodyTxt;
  v4 = this;
  UFG::qString::Set(&this->m_TitleTxt, titleTxt);
  UFG::qString::Set(&v4->m_BodyTxt, v3);
  v4->m_bShowMsg = 1;
  v5 = 1;
  if ( v4->m_eState == 2 )
    v5 = 3;
  v4->m_eState = v5;
  if ( v3 )
  {
    v7 = &log_type;
    log_type.mUID = qSymbol_GameLogType_Hint_20.mUID;
    if ( !(_S15_5 & 1) )
    {
      _S15_5 |= 1u;
      glManager.vfptr = (UFG::GameLogManagerVtbl *)&UFG::GameLogManager::`vftable';
      atexit(UFG::GameLogManager::getInstance_::_2_::_dynamic_atexit_destructor_for__glManager__);
    }
    UFG::GameLogManager::LogItem(&glManager, (__int64)&log_type, v3);
  }
}

// File Line: 60
// RVA: 0x62FC30
void __fastcall UFG::UIHKTutorialOverlay::hide(UFG::UIHKTutorialOverlay *this)
{
  UFG::UIHKTutorialOverlay::eState v1; // eax

  v1 = this->m_eState;
  if ( v1 == 2 )
  {
    this->m_eState = 3;
  }
  else if ( v1 == 1 )
  {
    this->m_bShowMsg = 0;
    this->m_eState = 0;
  }
}

// File Line: 82
// RVA: 0x62E980
char __fastcall UFG::UIHKTutorialOverlay::handleMessage(UFG::UIHKTutorialOverlay *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  if ( msgId != UI_HASH_TUTORIAL_OVERLAY_OUTRO_DONE_20 )
    return 0;
  if ( this->m_eState == 4 )
  {
    this->m_eState = this->m_bShowMsg != 0;
    Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "Set_Subtitle_Position2", 0i64, 0i64, 0);
  }
  return 1;
}

// File Line: 108
// RVA: 0x640DE0
void __fastcall UFG::UIHKTutorialOverlay::update(UFG::UIHKTutorialOverlay *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rdi
  UFG::UIHKTutorialOverlay *v4; // rbx
  const char *v5; // rsi
  const char *v6; // r14
  Scaleform::GFx::Movie *v7; // rbp
  char ptr; // [rsp+40h] [rbp-78h]
  __int64 v9; // [rsp+50h] [rbp-68h]
  unsigned int v10; // [rsp+58h] [rbp-60h]
  const char *v11; // [rsp+60h] [rbp-58h]
  char v12; // [rsp+70h] [rbp-48h]
  __int64 v13; // [rsp+80h] [rbp-38h]
  unsigned int v14; // [rsp+88h] [rbp-30h]
  const char *v15; // [rsp+90h] [rbp-28h]

  if ( screen )
  {
    v3 = screen;
    v4 = this;
    if ( this->m_eState == 1 )
    {
      v5 = UFG::UI::LocalizeText(this->m_TitleTxt.mData);
      v6 = UFG::UI::LocalizeText(v4->m_BodyTxt.mData);
      v7 = v3->mRenderable->m_movie.pObject;
      `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v10 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, &ptr, v11);
        v9 = 0i64;
      }
      v10 = 6;
      v11 = v5;
      if ( (v14 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
        v13 = 0i64;
      }
      v14 = 6;
      v15 = v6;
      Scaleform::GFx::Movie::Invoke(v7, "TutorialPopup_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      Scaleform::GFx::Movie::Invoke(v7, "Set_Subtitle_Position1", 0i64, 0i64, 0);
      v4->m_bShowMsg = 0;
      v4->m_eState = 2;
      `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
    else if ( this->m_eState == 3 )
    {
      Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "TutorialPopup_Hide", 0i64, 0i64, 0);
      v4->m_eState = 4;
    }
  }
}

