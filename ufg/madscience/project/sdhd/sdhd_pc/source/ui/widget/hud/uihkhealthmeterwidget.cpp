// File Line: 46
// RVA: 0x6140B0
void __fastcall UFG::UIHKHealthMeterWidget::Update(
        UFG::UIHKHealthMeterWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  signed __int16 m_Flags; // r8
  float *m_pComponent; // rcx
  UFG::SimComponent *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  bool v14; // al
  bool v15; // zf
  float v16; // xmm2_4
  bool v17; // bl

  if ( screen && LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (float *)LocalPlayer->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::HealthComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::HealthComponent::_TypeUID);
      m_pComponent = (float *)v7;
    }
    else
    {
      m_pComponent = (float *)LocalPlayer->m_Components.p[6].m_pComponent;
    }
    if ( m_pComponent )
    {
      v8 = (float)(int)m_pComponent[24];
      v9 = (float)(int)m_pComponent[23];
      v10 = (float)(int)m_pComponent[21];
      if ( v8 == 0.0 )
        v8 = *(float *)&FLOAT_1_0;
      if ( v9 == 0.0 )
        v9 = *(float *)&FLOAT_1_0;
      if ( UFG::UIHKTweakables::UseFakeHealthValue )
        v10 = (float)UFG::UIHKTweakables::FakeHealthValue;
      v11 = v10 * 100.0;
      v12 = (float)(v10 * 100.0) / v8;
      v13 = v11 / v9;
      v14 = COERCE_FLOAT(COERCE_UNSIGNED_INT(this->mHealthPercentOfMaxPossible - v12) & _xmm) > 0.0099999998;
      v15 = !v14 && !this->mChanged;
      this->mChanged |= v14;
      if ( !v15 )
      {
        this->mHealthPercentOfMaxPossible = v12;
        v16 = v13 - this->mHealthPercent;
        this->mChanged = 0;
        this->mHealthPercent = v13;
        UFG::UIHKHealthMeterWidget::Flash_UpdateFullscreenFX(screen, v13, v16);
        v17 = UFG::UIHKHealthMeterWidget::gVisible;
        UFG::UIHKHealthMeterWidget::Flash_SetVisible(this, screen, UFG::UIHKHealthMeterWidget::gVisible);
        if ( v17 )
        {
          UFG::UIHKHealthMeterWidget::Flash_UpdateHealthMeter(screen, v12);
          v15 = !this->mShouldHighlight;
          this->mIsFirstUpdate = 0;
          if ( !v15 )
          {
            this->mShouldHighlight = 0;
            UFG::UIHKHealthMeterWidget::Flash_UIHighlight_Init(this, screen);
          }
        }
      }
    }
  }
}

// File Line: 161
// RVA: 0x5E5BF0
void __fastcall UFG::UIHKHealthMeterWidget::Flash_UpdateHealthMeter(UFG::UIScreen *screen, float health)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (float)(health * 2.0);
    Scaleform::GFx::Movie::Invoke(pObject, "updateHealthMeter", 0i64, &pargs, 1u);
    if ( UFG::UIHKTweakables::ToggleHealthBarHide )
      Scaleform::GFx::Movie::Invoke(pObject, "showHideHealthMeter", 0i64, 0i64, 0);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 180
// RVA: 0x5E5B00
void __fastcall UFG::UIHKHealthMeterWidget::Flash_UpdateFullscreenFX(
        UFG::UIScreen *screen,
        float health,
        float deltaHealth)
{
  ;
}

// File Line: 222
// RVA: 0x5E5410
void __fastcall UFG::UIHKHealthMeterWidget::Flash_UIHighlight_Init(
        UFG::UIHKHealthMeterWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v4[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v5; // [rsp+80h] [rbp-28h]
  int v6; // [rsp+88h] [rbp-20h]
  const char *v7; // [rsp+90h] [rbp-18h]

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
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
    ptr.mValue.pString = "mc_HealthBar";
    if ( (v6 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v5 + 16i64))(v5, v4, v7);
      v5 = 0i64;
    }
    v6 = 6;
    v7 = "mc_HealthBar_highlight";
    Scaleform::GFx::Movie::Invoke(pObject, "UIHighlight_Init", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 237
// RVA: 0x5E1A40
void __fastcall UFG::UIHKHealthMeterWidget::Flash_SetVisible(
        UFG::UIHKHealthMeterWidget *this,
        UFG::UIScreen *screen,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = visible;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_HealthBar._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

