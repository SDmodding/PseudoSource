// File Line: 24
// RVA: 0x1566E70
__int64 dynamic_initializer_for__UFG::UIHKObjectiveFlasherWidget::mCaption__()
{
  UFG::qString::qString(&UFG::UIHKObjectiveFlasherWidget::mCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKObjectiveFlasherWidget::mCaption__);
}

// File Line: 25
// RVA: 0x1567200
__int64 dynamic_initializer_for__UFG::UIHKObjectiveFlasherWidget::mObjectiveType__()
{
  UFG::qString::qString(&UFG::UIHKObjectiveFlasherWidget::mObjectiveType);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKObjectiveFlasherWidget::mObjectiveType__);
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
  bool v4; // si
  Scaleform::GFx::Movie *pObject; // rbp
  const char *v6; // rax
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  if ( screen )
  {
    v4 = UFG::UIHKObjectiveFlasherWidget::mVisible;
    if ( this->mOldVisible != UFG::UIHKObjectiveFlasherWidget::mVisible )
    {
      this->mOldVisible = UFG::UIHKObjectiveFlasherWidget::mVisible;
      pObject = screen->mRenderable->m_movie.pObject;
      if ( !pObject )
        return;
      value.pObjectInterface = 0i64;
      value.Type = VT_Boolean;
      value.mValue.BValue = v4;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_objective._visible", &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Undefined;
    }
    if ( v4 )
    {
      if ( UFG::UIHKObjectiveFlasherWidget::mState == STATE_ROOT_MENU )
      {
        UFG::UIHKObjectiveFlasherWidget::mState = STATE_PHONE_CONTACTS;
        v6 = UFG::UI::LocalizeText(UFG::UIHKObjectiveFlasherWidget::mCaption.mData);
        UFG::UIHKObjectiveFlasherWidget::Flash_Show(
          this,
          screen,
          v6,
          UFG::UIHKObjectiveFlasherWidget::mObjectiveType.mData);
        UFG::UIHKObjectiveFlasherWidget::Flash_SetColor(this, screen, &UFG::UIHKObjectiveFlasherWidget::mColor);
      }
      else if ( UFG::UIHKObjectiveFlasherWidget::mState == STATE_TEXT_INBOX )
      {
        UFG::UIHKObjectiveFlasherWidget::mState = STATE_INCOMING_CALL;
        UFG::UIHKObjectiveFlasherWidget::Flash_Hide(this, screen);
      }
      if ( UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged )
      {
        if ( !UFG::UIHKObjectiveFlasherWidget::CanShowPDAReminder(this) )
          UFG::UIHKObjectiveFlasherWidget::Flash_HideSmartphone(this, screen);
        UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 0;
      }
    }
  }
}

// File Line: 83
// RVA: 0x5EADE0
char __fastcall UFG::UIHKObjectiveFlasherWidget::HandleMessage(
        UFG::UIHKObjectiveFlasherWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // rcx

  if ( msgId == UI_HASH_OBJECTIVE_FLASHER_FADE_IN_20 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x3C978AD4u, 0i64, 0, 0i64);
    return 0;
  }
  if ( msgId != UI_HASH_OBJECTIVE_FLASHER_FADE_OUT_20 )
    return 0;
  UFG::UIHKObjectiveFlasherWidget::mState = STATE_IDLE;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "ObjectiveFlasher_Unload", 0i64, 0i64, 0);
  return 1;
}

// File Line: 125
// RVA: 0x60D180
void __fastcall UFG::UIHKObjectiveFlasherWidget::Show(const char *caption, const char *objectiveType, bool usesPDA)
{
  UFG::UIHKObjectiveFlasherWidget::mState = STATE_ROOT_MENU;
  UFG::qString::Set(&UFG::UIHKObjectiveFlasherWidget::mCaption, caption);
  UFG::qString::Set(&UFG::UIHKObjectiveFlasherWidget::mObjectiveType, objectiveType);
  UFG::UIHKObjectiveFlasherWidget::mUsesPDA = usesPDA;
}

// File Line: 134
// RVA: 0x5D5270
void UFG::UIHKObjectiveFlasherWidget::Clear(void)
{
  UFG::UIHKObjectiveFlasherWidget::eState v0; // eax

  v0 = UFG::UIHKObjectiveFlasherWidget::mState;
  if ( (UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB) != 0 )
    v0 = STATE_TEXT_INBOX;
  UFG::UIHKObjectiveFlasherWidget::mState = v0;
}

// File Line: 149
// RVA: 0x5E3410
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_Show(
        UFG::UIHKObjectiveFlasherWidget *this,
        UFG::UIScreen *screen,
        const char *caption,
        const char *objectiveType)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Movie *v9; // rcx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-78h] BYREF
  char v11[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v12; // [rsp+80h] [rbp-38h]
  int v13; // [rsp+88h] [rbp-30h]
  const char *v14; // [rsp+90h] [rbp-28h]

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = caption;
    if ( (v13 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v12 + 16i64))(v12, v11, v14);
      v12 = 0i64;
    }
    v13 = 6;
    v14 = objectiveType;
    Scaleform::GFx::Movie::Invoke(pObject, "ObjectiveFlasher_Show", 0i64, &pargs, 2u);
    if ( UFG::UIHKObjectiveFlasherWidget::mUsesPDA )
    {
      UFG::UIHKObjectiveFlasherWidget::Flash_ShowSmartphone(this, screen);
    }
    else
    {
      v9 = screen->mRenderable->m_movie.pObject;
      if ( v9 )
      {
        UFG::UIHKObjectiveFlasherWidget::mUsesPDA = 0;
        Scaleform::GFx::Movie::Invoke(v9, "Smartphone_HideReminder", 0i64, 0i64, 0);
      }
    }
    `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 172
// RVA: 0x5E4D10
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_ShowSmartphone(
        UFG::UIHKObjectiveFlasherWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  bool m_IsKeyboardController; // di
  unsigned int v5; // eax
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-40h] BYREF

  if ( UFG::UIHKObjectiveFlasherWidget::CanShowPDAReminder(this) )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Boolean;
      ptr.mValue.BValue = m_IsKeyboardController;
      Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_ShowReminder", 0i64, &ptr, 1u);
      UFG::UIHKObjectiveFlasherWidget::mUsesPDA = 1;
      v5 = UFG::TiDo::CalcWwiseUid("Play_alert");
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v5, 0i64, 0, 0i64);
      `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 188
// RVA: 0x5DBE80
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_HideSmartphone(
        UFG::UIHKObjectiveFlasherWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    UFG::UIHKObjectiveFlasherWidget::mUsesPDA = 0;
    Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_HideReminder", 0i64, 0i64, 0);
  }
}

// File Line: 199
// RVA: 0x5DB9A0
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_Hide(
        UFG::UIHKObjectiveFlasherWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx
  Scaleform::GFx::Movie *v4; // rcx

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "ObjectiveFlasher_Hide", 0i64, 0i64, 0);
    v4 = screen->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      UFG::UIHKObjectiveFlasherWidget::mUsesPDA = 0;
      Scaleform::GFx::Movie::Invoke(v4, "Smartphone_HideReminder", 0i64, 0i64, 0);
    }
  }
}

// File Line: 220
// RVA: 0x5DFD00
void __fastcall UFG::UIHKObjectiveFlasherWidget::Flash_SetColor(
        UFG::UIHKObjectiveFlasherWidget *this,
        UFG::UIScreen *screen,
        UFG::qColour *color)
{
  Scaleform::GFx::Movie *pObject; // rbx
  int v4; // edi
  int v5; // esi
  int v6; // r14d
  Scaleform::GFx::Value ptr; // [rsp+18h] [rbp-59h] BYREF
  char v8[16]; // [rsp+48h] [rbp-29h] BYREF
  __int64 v9; // [rsp+58h] [rbp-19h]
  int v10; // [rsp+60h] [rbp-11h]
  double v11; // [rsp+68h] [rbp-9h]
  char v12[16]; // [rsp+78h] [rbp+7h] BYREF
  __int64 v13; // [rsp+88h] [rbp+17h]
  int v14; // [rsp+90h] [rbp+1Fh]
  double v15; // [rsp+98h] [rbp+27h]
  __int64 v16; // [rsp+A8h] [rbp+37h]

  v16 = -2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    v4 = (int)(float)(color->r * 255.0);
    v5 = (int)(float)(color->g * 255.0);
    v6 = (int)(float)(color->b * 255.0);
    ptr.pNext = (Scaleform::GFx::Value *)Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue.NValue = (double)(unsigned __int8)v4;
    if ( (v10 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = (double)(unsigned __int8)v5;
    if ( (v14 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v13 + 16i64))(
        v13,
        v12,
        COERCE_DOUBLE(*(_QWORD *)&v15));
      v13 = 0i64;
    }
    v14 = 5;
    v15 = (double)(unsigned __int8)v6;
    Scaleform::GFx::Movie::Invoke(pObject, "ObjectiveFlasher_SetColor", 0i64, &ptr, 3u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 240
// RVA: 0x5D4860
bool __fastcall UFG::UIHKObjectiveFlasherWidget::CanShowPDAReminder(UFG::UIHKObjectiveFlasherWidget *this)
{
  UFG::UIHK_PDAWidget *PDA; // rcx
  UFG::ePDAStateEnum mState; // eax

  if ( !UFG::UIHKScreenHud::mInstance
    || !UFG::UIHKScreenHud::mInstance->PDA
    || UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0)
    || UFG::SimObjectUtility::IsInWater(LocalPlayer) )
  {
    return 0;
  }
  if ( UFG::UIHKScreenHud::mInstance && (PDA = UFG::UIHKScreenHud::mInstance->PDA) != 0i64 )
    mState = PDA->mState;
  else
    mState = UFG::UIHKScreenHud::PDACache.state;
  return mState == STATE_IDLE || (unsigned int)(mState - 10) <= 1;
}

