// File Line: 24
// RVA: 0x1566E70
__int64 dynamic_initializer_for__UFG::UIHKObjectiveFlasherWidget::mCaption__()
{
  UFG::qString::qString(&UFG::UIHKObjectiveFlasherWidget::mCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKObjectiveFlasherWidget::mCaption__);
}

// File Line: 25
// RVA: 0x1567200
__int64 dynamic_initializer_for__UFG::UIHKObjectiveFlasherWidget::mObjectiveType__()
{
  UFG::qString::qString(&UFG::UIHKObjectiveFlasherWidget::mObjectiveType);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKObjectiveFlasherWidget::mObjectiveType__);
}

// File Line: 27
// RVA: 0x1566EB0
__int64 dynamic_initializer_for__UFG::UIHKObjectiveFlasherWidget::mColor__()
{
  UFG::UIHKObjectiveFlasherWidget::mColor = UFG::qColour::White;
  return LODWORD(UFG::qColour::White.a);
}

// File Line: 39
// RVA: 0x616060
void __fastcall UFG::UIHKObjectiveFlasherWidget::Update(UFG::UIHKObjectiveFlasherWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHKObjectiveFlasherWidget *v3; // rbx
  bool v4; // si
  Scaleform::GFx::Movie *v5; // rbp
  const char *v6; // rax
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  if ( screen )
  {
    v2 = screen;
    v3 = this;
    v4 = UFG::UIHKObjectiveFlasherWidget::mVisible;
    if ( this->mOldVisible != UFG::UIHKObjectiveFlasherWidget::mVisible )
    {
      this->mOldVisible = UFG::UIHKObjectiveFlasherWidget::mVisible;
      v5 = screen->mRenderable->m_movie.pObject;
      if ( !v5 )
        return;
      value.pObjectInterface = 0i64;
      value.Type = 2;
      value.mValue.BValue = v4;
      Scaleform::GFx::Movie::SetVariable(v5, "mc_objective._visible", &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 0;
    }
    if ( v4 )
    {
      if ( UFG::UIHKObjectiveFlasherWidget::mState == 1 )
      {
        UFG::UIHKObjectiveFlasherWidget::mState = 2;
        v6 = UFG::UI::LocalizeText(UFG::UIHKObjectiveFlasherWidget::mCaption.mData);
        UFG::UIHKObjectiveFlasherWidget::Flash_Show(v3, v2, v6, UFG::UIHKObjectiveFlasherWidget::mObjectiveType.mData);
        UFG::UIHKObjectiveFlasherWidget::Flash_SetColor(v3, v2, &UFG::UIHKObjectiveFlasherWidget::mColor);
      }
      else if ( UFG::UIHKObjectiveFlasherWidget::mState == 3 )
      {
        UFG::UIHKObjectiveFlasherWidget::mState = 4;
        UFG::UIHKObjectiveFlasherWidget::Flash_Hide(v3, v2);
      }
      if ( UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged )
      {
        if ( !UFG::UIHKObjectiveFlasherWidget::CanShowPDAReminder(v3) )
          UFG::UIHKObjectiveFlasherWidget::Flash_HideSmartphone(v3, v2);
        UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 0;
      }
    }
  }
}

// File Line: 83
// RVA: 0x5EADE0
char __fastcall UFG::UIHKObjectiveFlasherWidget::HandleMessage(UFG::UIHKObjectiveFlasherWidget *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *v5; // rcx

  if ( msgId == UI_HASH_OBJECTIVE_FLASHER_FADE_IN_20 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x3C978AD4u,
        0i64,
        0,
        0i64);
    return 0;
  }
  if ( msgId != UI_HASH_OBJECTIVE_FLASHER_FADE_OUT_20 )
    return 0;
  UFG::UIHKObjectiveFlasherWidget::mState = 0;
  v5 = screen->mRenderable->m_movie.pObject;
  if ( v5 )
    Scaleform::GFx::Movie::Invoke(v5, "ObjectiveFlasher_Unload", 0i64, 0i64, 0);
  return 1;
}

// File Line: 125
// RVA: 0x60D180
void __fastcall UFG::UIHKObjectiveFlasherWidget::Show(const char *caption, const char *objectiveType, bool usesPDA)
{
  const char *v3; // rbx
  bool v4; // di

  v3 = objectiveType;
  v4 = usesPDA;
  UFG::UIHKObjectiveFlasherWidget::mState = 1;
  UFG::qString::Set(&UFG::UIHKObjectiveFlasherWidget::mCaption, caption);
  UFG::qString::Set(&UFG::UIHKObjectiveFlasherWidget::mObjectiveType, v3);
  UFG::UIHKObjectiveFlasherWidget::mUsesPDA = v4;
}

// File Line: 134
// RVA: 0x5D5270
void UFG::UIHKObjectiveFlasherWidget::Clear(void)
{
  UFG::UIHKObjectiveFlasherWidget::eState v0; // eax

  v0 = UFG::UIHKObjectiveFlasherWidget::mState;
  if ( UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB )
    v0 = 3;
  UFG::UIHKObjectiveFlasherWidget::mState = v0;
}

// File Line: 149
// RVA: 0x5E3410
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_Show(UFG::UIHKObjectiveFlasherWidget *this, UFG::UIScreen *screen, const char *caption, const char *objectiveType)
{
  const char *v4; // r14
  const char *v5; // rbp
  UFG::UIScreen *v6; // rbx
  UFG::UIHKObjectiveFlasherWidget *v7; // rsi
  Scaleform::GFx::Movie *v8; // rdi
  Scaleform::GFx::Movie *v9; // rcx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-78h]
  char v11; // [rsp+70h] [rbp-48h]
  __int64 v12; // [rsp+80h] [rbp-38h]
  unsigned int v13; // [rsp+88h] [rbp-30h]
  const char *v14; // [rsp+90h] [rbp-28h]

  v4 = objectiveType;
  v5 = caption;
  v6 = screen;
  v7 = this;
  v8 = screen->mRenderable->m_movie.pObject;
  if ( v8 )
  {
    `eh vector constructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v5;
    if ( (v13 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v12 + 16i64))(v12, &v11, v14);
      v12 = 0i64;
    }
    v13 = 6;
    v14 = v4;
    Scaleform::GFx::Movie::Invoke(v8, "ObjectiveFlasher_Show", 0i64, &pargs, 2u);
    if ( UFG::UIHKObjectiveFlasherWidget::mUsesPDA == 1 )
    {
      UFG::UIHKObjectiveFlasherWidget::Flash_ShowSmartphone(v7, v6);
    }
    else
    {
      v9 = v6->mRenderable->m_movie.pObject;
      if ( v9 )
      {
        UFG::UIHKObjectiveFlasherWidget::mUsesPDA = 0;
        Scaleform::GFx::Movie::Invoke(v9, "Smartphone_HideReminder", 0i64, 0i64, 0);
      }
    }
    `eh vector destructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 172
// RVA: 0x5E4D10
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_ShowSmartphone(UFG::UIHKObjectiveFlasherWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rbx
  Scaleform::GFx::Movie *v3; // rbx
  bool v4; // di
  unsigned int v5; // eax
  char ptr; // [rsp+38h] [rbp-40h]
  __int64 v7; // [rsp+48h] [rbp-30h]
  unsigned int v8; // [rsp+50h] [rbp-28h]
  __int64 v9; // [rsp+58h] [rbp-20h]

  v2 = screen;
  if ( UFG::UIHKObjectiveFlasherWidget::CanShowPDAReminder(this) )
  {
    v3 = v2->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      if ( (v8 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v7 + 16i64))(v7, &ptr, v9);
        v7 = 0i64;
      }
      v8 = 2;
      LOBYTE(v9) = v4;
      Scaleform::GFx::Movie::Invoke(v3, "Smartphone_ShowReminder", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
      UFG::UIHKObjectiveFlasherWidget::mUsesPDA = 1;
      v5 = UFG::TiDo::CalcWwiseUid("Play_alert");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v5, 0i64, 0, 0i64);
      `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 188
// RVA: 0x5DBE80
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_HideSmartphone(UFG::UIHKObjectiveFlasherWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rcx

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    UFG::UIHKObjectiveFlasherWidget::mUsesPDA = 0;
    Scaleform::GFx::Movie::Invoke(v2, "Smartphone_HideReminder", 0i64, 0i64, 0);
  }
}

// File Line: 199
// RVA: 0x5DB9A0
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_Hide(UFG::UIHKObjectiveFlasherWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx
  Scaleform::GFx::Movie *v4; // rcx

  v2 = screen;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    Scaleform::GFx::Movie::Invoke(v3, "ObjectiveFlasher_Hide", 0i64, 0i64, 0);
    v4 = v2->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      UFG::UIHKObjectiveFlasherWidget::mUsesPDA = 0;
      Scaleform::GFx::Movie::Invoke(v4, "Smartphone_HideReminder", 0i64, 0i64, 0);
    }
  }
}

// File Line: 220
// RVA: 0x5DFD00
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_SetColor(UFG::UIHKObjectiveFlasherWidget *this, UFG::UIScreen *screen, UFG::qColour *color)
{
  Scaleform::GFx::Movie *v3; // rbx
  signed int v4; // edi
  signed int v5; // esi
  signed int v6; // er14
  char ptr; // [rsp+18h] [rbp-59h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-51h]
  __int64 v9; // [rsp+28h] [rbp-49h]
  unsigned int v10; // [rsp+30h] [rbp-41h]
  double v11; // [rsp+38h] [rbp-39h]
  char v12; // [rsp+48h] [rbp-29h]
  __int64 v13; // [rsp+58h] [rbp-19h]
  unsigned int v14; // [rsp+60h] [rbp-11h]
  double v15; // [rsp+68h] [rbp-9h]
  char v16; // [rsp+78h] [rbp+7h]
  __int64 v17; // [rsp+88h] [rbp+17h]
  unsigned int v18; // [rsp+90h] [rbp+1Fh]
  double v19; // [rsp+98h] [rbp+27h]
  __int64 v20; // [rsp+A8h] [rbp+37h]

  v20 = -2i64;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    v4 = (signed int)(float)(color->r * 255.0);
    v5 = (signed int)(float)(color->g * 255.0);
    v6 = (signed int)(float)(color->b * 255.0);
    pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(
        v9,
        &ptr,
        COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = (double)(unsigned __int8)v4;
    if ( (v14 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(
        v13,
        &v12,
        COERCE_DOUBLE(*(_QWORD *)&v15));
      v13 = 0i64;
    }
    v14 = 5;
    v15 = (double)(unsigned __int8)v5;
    if ( (v18 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v17 + 16i64))(
        v17,
        &v16,
        COERCE_DOUBLE(*(_QWORD *)&v19));
      v17 = 0i64;
    }
    v18 = 5;
    v19 = (double)(unsigned __int8)v6;
    Scaleform::GFx::Movie::Invoke(v3, "ObjectiveFlasher_SetColor", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 240
// RVA: 0x5D4860
bool __fastcall UFG::UIHKObjectiveFlasherWidget::CanShowPDAReminder(UFG::UIHKObjectiveFlasherWidget *this)
{
  UFG::UIHK_PDAWidget *v1; // rcx
  UFG::ePDAStateEnum v2; // eax

  if ( !UFG::UIHKScreenHud::mInstance
    || !UFG::UIHKScreenHud::mInstance->PDA
    || UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0)
    || UFG::SimObjectUtility::IsInWater((UFG::SimObject *)&LocalPlayer->vfptr) )
  {
    return 0;
  }
  if ( UFG::UIHKScreenHud::mInstance && (v1 = UFG::UIHKScreenHud::mInstance->PDA) != 0i64 )
    v2 = v1->mState;
  else
    v2 = UFG::UIHKScreenHud::PDACache.state;
  return v2 == STATE_IDLE || (unsigned int)(v2 - 10) <= 1;
}

