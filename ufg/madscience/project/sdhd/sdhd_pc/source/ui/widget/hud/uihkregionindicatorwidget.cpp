// File Line: 46
// RVA: 0x616850
void __fastcall UFG::UIHKRegionIndicatorWidget::Update(UFG::UIHKRegionIndicatorWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // r15
  UFG::UIHKRegionIndicatorWidget *v4; // r14
  UFG::UITween *v5; // rdi
  char v6; // bl
  float v7; // xmm0_4
  char v8; // bp
  float v9; // xmm0_4
  UFG::allocator::free_link *v10; // rsi
  UFG::UITween *v11; // rax
  UFG::UITween *v12; // rsi
  UFG::qNode<UFG::UITween,UFG::UITween> *v13; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v14; // rax
  UFG::UIHKInfoPopupWidget::eState v15; // ecx
  char v16; // al
  char v17; // si
  UFG::TimeOfDayManager *v18; // rax
  UFG::allocator::free_link *v19; // rsi
  UFG::UITween *v20; // rax
  UFG::qNode<UFG::UITween,UFG::UITween> *v21; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v22; // rax
  UFG::qString path; // [rsp+40h] [rbp-58h]

  v3 = screen;
  v4 = this;
  v5 = 0i64;
  v6 = 0;
  v7 = this->mOutroTimer;
  v8 = 1;
  if ( v7 > 0.0 )
  {
    v9 = v7 - elapsed;
    this->mOutroTimer = v9;
    if ( v9 <= 0.0 )
    {
      v10 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
      if ( v10 )
      {
        UFG::qString::qString(&path, "mc_regionIndicator");
        v6 = 1;
        UFG::UITween::UITween((UFG::UITween *)v10, v3->mRenderable->m_movie.pObject, &path, 0.0, 0);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      if ( v6 & 1 )
      {
        v6 &= 0xFEu;
        UFG::qString::~qString(&path);
      }
      UFG::UITween::SetRange(v12, ALPHA, 100.0, 0.0);
      v13 = &UFG::UIScreenManager::s_instance->m_activeTweens.mNode;
      v14 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
      v14->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v12->mPrev;
      v12->mPrev = v14;
      v12->mNext = v13;
      v13->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v12->mPrev;
    }
  }
  if ( !UFG::UIHKScreenHud::InfoPopup || (v15 = UFG::UIHKScreenHud::InfoPopup->mState) == 0 || (v16 = 0, v15 == 5) )
    v16 = 1;
  if ( UFG::UIHKScreenHud::HintText && UFG::UIHKScreenHud::HintText->m_eState )
    v8 = 0;
  v17 = v8 & v16 & v4->mVisible;
  if ( v4->mIsVisible != v17 )
    UFG::UIHKRegionIndicatorWidget::Flash_SetVisible(v4, v3, v17);
  if ( v17 && v4->mChanged )
  {
    v4->mChanged = 0;
    v4->mZone = UFG::GameStatAction::World::sCurrentZone;
    v18 = UFG::TimeOfDayManager::GetInstance();
    UFG::UIHKRegionIndicatorWidget::Flash_Show(v4, v3, v4->mZone, v18->m_SecondsSinceMidnight);
    v19 = UFG::qMalloc(0x3E0ui64, UFG::gGlobalNewName, 0i64);
    if ( v19 )
    {
      UFG::qString::qString(&path, "mc_regionIndicator");
      v6 |= 2u;
      UFG::UITween::UITween((UFG::UITween *)v19, v3->mRenderable->m_movie.pObject, &path, 0.0, 0);
      v5 = v20;
    }
    if ( v6 & 2 )
      UFG::qString::~qString(&path);
    UFG::UITween::SetRange(v5, ALPHA, 0.0, 100.0);
    v21 = &UFG::UIScreenManager::s_instance->m_activeTweens.mNode;
    v22 = UFG::UIScreenManager::s_instance->m_activeTweens.mNode.mPrev;
    v22->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v5->mPrev;
    v5->mPrev = v22;
    v5->mNext = v21;
    v21->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v5->mPrev;
    v4->mOutroTimer = 6.0;
  }
}

// File Line: 161
// RVA: 0x5E9890
void __fastcall UFG::UIHKRegionIndicatorWidget::GetTimeString(float time, UFG::qString *timeStr)
{
  UFG::qString *v2; // rbp
  unsigned int v3; // ebx
  unsigned int v4; // er14
  const char *v5; // rsi
  unsigned int v6; // eax
  UFG::UIGfxTranslator *v7; // rcx
  const char *v8; // rdi
  UFG::qString result; // [rsp+38h] [rbp-30h]

  v2 = timeStr;
  v3 = (signed int)(float)(time * 0.00027777778);
  v4 = (signed int)(float)((float)(time - (float)((float)(signed int)v3 * 3600.0)) * 0.016666668);
  v5 = "AM";
  if ( v3 > 0xC )
  {
    v3 -= 12;
    v5 = "PM";
  }
  v6 = UFG::qStringHashUpper32("HUD_TIME_FORMAT", 0xFFFFFFFF);
  v7 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v7 || (v8 = (const char *)v7->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, v6)) == 0i64 )
    v8 = "HUD_TIME_FORMAT";
  UFG::qString::FormatEx(&result, "%2u:%02u %s", v3, v4, v5);
  UFG::qString::Format(v2, v8, result.mData);
  UFG::qString::~qString(&result);
}

// File Line: 180
// RVA: 0x5E1DF0
void __fastcall UFG::UIHKRegionIndicatorWidget::Flash_SetVisible(UFG::UIHKRegionIndicatorWidget *this, UFG::UIScreen *screen, bool visible)
{
  bool v3; // bl
  UFG::UIHKRegionIndicatorWidget *v4; // rdi
  Scaleform::GFx::Movie *v5; // rsi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  if ( screen )
  {
    v3 = visible;
    v4 = this;
    v5 = screen->mRenderable->m_movie.pObject;
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = visible;
    Scaleform::GFx::Movie::SetVariable(v5, "mc_regionIndicator._visible", &value, 1i64);
    v4->mIsVisible = v3;
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 194
// RVA: 0x5E36F0
void __fastcall UFG::UIHKRegionIndicatorWidget::Flash_Show(UFG::UIHKRegionIndicatorWidget *this, UFG::UIScreen *screen, unsigned int zone, float time)
{
  Scaleform::GFx::Movie *v4; // rsi
  const char *v5; // rbx
  const char *v6; // rdi
  char *v7; // rbx
  char ptr; // [rsp+28h] [rbp-79h]
  __int64 v9; // [rsp+38h] [rbp-69h]
  unsigned int v10; // [rsp+40h] [rbp-61h]
  const char *v11; // [rsp+48h] [rbp-59h]
  char v12; // [rsp+58h] [rbp-49h]
  __int64 v13; // [rsp+68h] [rbp-39h]
  unsigned int v14; // [rsp+70h] [rbp-31h]
  const char *v15; // [rsp+78h] [rbp-29h]
  char v16; // [rsp+88h] [rbp-19h]
  __int64 v17; // [rsp+98h] [rbp-9h]
  unsigned int v18; // [rsp+A0h] [rbp-1h]
  char *v19; // [rsp+A8h] [rbp+7h]
  __int64 v20; // [rsp+B8h] [rbp+17h]
  UFG::qString timeStr; // [rsp+C0h] [rbp+1Fh]

  if ( screen )
  {
    v20 = -2i64;
    v4 = screen->mRenderable->m_movie.pObject;
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
    v7 = timeStr.mData;
    if ( (v18 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v17 + 16i64))(v17, &v16, v19);
      v17 = 0i64;
    }
    v18 = 6;
    v19 = v7;
    Scaleform::GFx::Movie::Invoke(v4, "ShowRegion", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&timeStr);
  }
}

