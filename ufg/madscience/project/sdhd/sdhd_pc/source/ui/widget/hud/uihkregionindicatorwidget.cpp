// File Line: 46
// RVA: 0x616850
void __fastcall UFG::UIHKRegionIndicatorWidget::Update(
        UFG::UIHKRegionIndicatorWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  UFG::UITween *v5; // rdi
  char v6; // bl
  float mOutroTimer; // xmm0_4
  char v8; // bp
  float v9; // xmm0_4
  UFG::allocator::free_link *v10; // rsi
  UFG::UITween *v11; // rax
  UFG::UITween *v12; // rsi
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *p_m_activeTweens; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *mPrev; // rax
  UFG::UIHKInfoPopupWidget::eState mState; // ecx
  char v16; // al
  bool v17; // si
  UFG::TimeOfDayManager *Instance; // rax
  UFG::allocator::free_link *v19; // rsi
  UFG::UITween *v20; // rax
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *v21; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v22; // rax
  UFG::qString path; // [rsp+40h] [rbp-58h] BYREF

  v5 = 0i64;
  v6 = 0;
  mOutroTimer = this->mOutroTimer;
  v8 = 1;
  if ( mOutroTimer > 0.0 )
  {
    v9 = mOutroTimer - elapsed;
    this->mOutroTimer = v9;
    if ( v9 <= 0.0 )
    {
      v10 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
      if ( v10 )
      {
        UFG::qString::qString(&path, "mc_regionIndicator");
        v6 = 1;
        UFG::UITween::UITween((UFG::UITween *)v10, screen->mRenderable->m_movie.pObject, &path, 0.0, TWEEN_LINEAR);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      if ( (v6 & 1) != 0 )
      {
        v6 &= ~1u;
        UFG::qString::~qString(&path);
      }
      UFG::UITween::SetRange(v12, ALPHA, 100.0, 0.0);
      p_m_activeTweens = &UFG::UIScreenManager::s_instance->m_activeTweens;
      mPrev = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
      mPrev->mNext = v12;
      v12->mPrev = mPrev;
      v12->mNext = &p_m_activeTweens->mNode;
      p_m_activeTweens->mNode.mPrev = v12;
    }
  }
  if ( !UFG::UIHKScreenHud::InfoPopup
    || (mState = UFG::UIHKScreenHud::InfoPopup->mState) == STATE_IDLE
    || (v16 = 0, mState == STATE_OUTGOING_CALL) )
  {
    v16 = 1;
  }
  if ( UFG::UIHKScreenHud::HintText && UFG::UIHKScreenHud::HintText->m_eState )
    v8 = 0;
  v17 = v8 & v16 & this->mVisible;
  if ( this->mIsVisible != v17 )
    UFG::UIHKRegionIndicatorWidget::Flash_SetVisible(this, screen, v17);
  if ( v17 && this->mChanged )
  {
    this->mChanged = 0;
    this->mZone = UFG::GameStatAction::World::sCurrentZone;
    Instance = UFG::TimeOfDayManager::GetInstance();
    UFG::UIHKRegionIndicatorWidget::Flash_Show(this, screen, this->mZone, Instance->m_SecondsSinceMidnight);
    v19 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
    if ( v19 )
    {
      UFG::qString::qString(&path, "mc_regionIndicator");
      v6 |= 2u;
      UFG::UITween::UITween((UFG::UITween *)v19, screen->mRenderable->m_movie.pObject, &path, 0.0, TWEEN_LINEAR);
      v5 = v20;
    }
    if ( (v6 & 2) != 0 )
      UFG::qString::~qString(&path);
    UFG::UITween::SetRange(v5, ALPHA, 0.0, 100.0);
    v21 = &UFG::UIScreenManager::s_instance->m_activeTweens;
    v22 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
    v22->mNext = v5;
    v5->mPrev = v22;
    v5->mNext = &v21->mNode;
    v21->mNode.mPrev = v5;
    this->mOutroTimer = 6.0;
  }
}

// File Line: 161
// RVA: 0x5E9890
void __fastcall UFG::UIHKRegionIndicatorWidget::GetTimeString(float time, UFG::qString *timeStr)
{
  unsigned int v3; // ebx
  unsigned int v4; // r14d
  const char *v5; // rsi
  unsigned int v6; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v8; // rdi
  UFG::qString result; // [rsp+38h] [rbp-30h] BYREF

  v3 = (int)(float)(time * 0.00027777778);
  v4 = (int)(float)((float)(time - (float)((float)(int)v3 * 3600.0)) * 0.016666668);
  v5 = "AM";
  if ( v3 > 0xC )
  {
    v3 -= 12;
    v5 = "PM";
  }
  v6 = UFG::qStringHashUpper32("HUD_TIME_FORMAT", -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator || (v8 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v6)) == 0i64 )
    v8 = "HUD_TIME_FORMAT";
  UFG::qString::FormatEx(&result, "%2u:%02u %s", v3, v4, v5);
  UFG::qString::Format(timeStr, v8, result.mData);
  UFG::qString::~qString(&result);
}

// File Line: 180
// RVA: 0x5E1DF0
void __fastcall UFG::UIHKRegionIndicatorWidget::Flash_SetVisible(
        UFG::UIHKRegionIndicatorWidget *this,
        UFG::UIScreen *screen,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rsi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = visible;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_regionIndicator._visible", &value, 1i64);
    this->mIsVisible = visible;
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 194
// RVA: 0x5E36F0
void __fastcall UFG::UIHKRegionIndicatorWidget::Flash_Show(
        UFG::UIHKRegionIndicatorWidget *this,
        UFG::UIScreen *screen,
        unsigned int zone,
        float time)
{
  Scaleform::GFx::Movie *pObject; // rsi
  const char *v5; // rbx
  const char *v6; // rdi
  char *mData; // rbx
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-79h] BYREF
  char v9[16]; // [rsp+58h] [rbp-49h] BYREF
  __int64 v10; // [rsp+68h] [rbp-39h]
  int v11; // [rsp+70h] [rbp-31h]
  const char *v12; // [rsp+78h] [rbp-29h]
  char v13[16]; // [rsp+88h] [rbp-19h] BYREF
  __int64 v14; // [rsp+98h] [rbp-9h]
  int v15; // [rsp+A0h] [rbp-1h]
  char *v16; // [rsp+A8h] [rbp+7h]
  __int64 v17; // [rsp+B8h] [rbp+17h]
  UFG::qString timeStr; // [rsp+C0h] [rbp+1Fh] BYREF

  if ( screen )
  {
    v17 = -2i64;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( zone == UFG::ZoneTag::smNorthPoint )
    {
      v5 = "$COMMON_NORTH_POINT";
      v6 = "NP";
    }
    else if ( zone == UFG::ZoneTag::smAberdeen )
    {
      v5 = "$COMMON_ABERDEEN";
      v6 = "AB";
    }
    else if ( zone == UFG::ZoneTag::smKennedyTown )
    {
      v5 = "$COMMON_KENNEDY_TOWN";
      v6 = "KT";
    }
    else
    {
      if ( zone != UFG::ZoneTag::smCentral )
        return;
      v5 = "$COMMON_CENTRAL";
      v6 = "CT";
    }
    UFG::qString::qString(&timeStr);
    UFG::UIHKRegionIndicatorWidget::GetTimeString(time, &timeStr);
    `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
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
    mData = timeStr.mData;
    if ( (v15 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v14 + 16i64))(v14, v13, v16);
      v14 = 0i64;
    }
    v15 = 6;
    v16 = mData;
    Scaleform::GFx::Movie::Invoke(pObject, "ShowRegion", 0i64, &ptr, 3u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&timeStr);
  }
}

