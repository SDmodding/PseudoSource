// File Line: 46
// RVA: 0x6140B0
void __fastcall UFG::UIHKHealthMeterWidget::Update(UFG::UIHKHealthMeterWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHKHealthMeterWidget *v3; // rdi
  UFG::UIScreen *v4; // rsi
  unsigned __int16 v5; // r8
  float *v6; // rcx
  UFG::SimComponent *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm6_4
  float v12; // xmm1_4
  float v13; // xmm6_4
  float v14; // xmm1_4
  bool v15; // al
  bool v16; // zf
  float v17; // xmm2_4
  bool v18; // bl

  if ( screen )
  {
    v3 = this;
    v4 = screen;
    if ( LocalPlayer )
    {
      v5 = LocalPlayer->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = (float *)LocalPlayer->m_Components.p[6].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                 UFG::HealthComponent::_TypeUID);
        else
          v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                  UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                      (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                      UFG::HealthComponent::_TypeUID);
        v6 = (float *)v7;
      }
      else
      {
        v6 = (float *)LocalPlayer->m_Components.p[6].m_pComponent;
      }
      if ( v6 )
      {
        v8 = (float)(signed int)v6[24];
        v9 = (float)(signed int)v6[23];
        v10 = (float)(signed int)v6[21];
        if ( v8 == 0.0 )
          v8 = *(float *)&FLOAT_1_0;
        if ( v9 == 0.0 )
          v9 = *(float *)&FLOAT_1_0;
        if ( UFG::UIHKTweakables::UseFakeHealthValue )
          v10 = (float)UFG::UIHKTweakables::FakeHealthValue;
        v11 = v10 * 100.0;
        v12 = v11;
        v13 = v11 / v8;
        v14 = v12 / v9;
        v15 = COERCE_FLOAT(COERCE_UNSIGNED_INT(v3->mHealthPercentOfMaxPossible - v13) & _xmm) > 0.0099999998;
        v16 = (v15 || v3->mChanged) == 0;
        v3->mChanged |= v15;
        if ( !v16 )
        {
          v3->mHealthPercentOfMaxPossible = v13;
          v17 = v14 - v3->mHealthPercent;
          v3->mChanged = 0;
          v3->mHealthPercent = v14;
          UFG::UIHKHealthMeterWidget::Flash_UpdateFullscreenFX(v4, v14, v17);
          v18 = UFG::UIHKHealthMeterWidget::gVisible;
          UFG::UIHKHealthMeterWidget::Flash_SetVisible(v3, v4, UFG::UIHKHealthMeterWidget::gVisible);
          if ( v18 )
          {
            UFG::UIHKHealthMeterWidget::Flash_UpdateHealthMeter(v4, v13);
            v16 = v3->mShouldHighlight == 0;
            v3->mIsFirstUpdate = 0;
            if ( !v16 )
            {
              v3->mShouldHighlight = 0;
              UFG::UIHKHealthMeterWidget::Flash_UIHighlight_Init(v3, v4);
            }
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
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Number;
    pargs.mValue.NValue = (float)(health * 2.0);
    Scaleform::GFx::Movie::Invoke(v2, "updateHealthMeter", 0i64, &pargs, 1u);
    if ( UFG::UIHKTweakables::ToggleHealthBarHide )
      Scaleform::GFx::Movie::Invoke(v2, "showHideHealthMeter", 0i64, 0i64, 0);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 180
// RVA: 0x5E5B00
void __fastcall UFG::UIHKHealthMeterWidget::Flash_UpdateFullscreenFX(UFG::UIScreen *screen, float health, float deltaHealth)
{
  char v3; // [rsp+28h] [rbp-48h]
  __int64 v4; // [rsp+38h] [rbp-38h]
  unsigned int v5; // [rsp+40h] [rbp-30h]
  double v6; // [rsp+48h] [rbp-28h]

  if ( screen->mRenderable->m_movie.pObject && deltaHealth <= 9.0 )
  {
    v4 = 0i64;
    v5 = 0;
    if ( health >= 200.0 )
    {
      if ( (v5 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v4 + 16i64))(
          v4,
          &v3,
          COERCE_DOUBLE(*(_QWORD *)&v6));
        v4 = 0i64;
      }
      v5 = 2;
      LOBYTE(v6) = 0;
    }
    else
    {
      if ( (v5 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v4 + 16i64))(
          v4,
          &v3,
          COERCE_DOUBLE(*(_QWORD *)&v6));
        v4 = 0i64;
      }
      v5 = 5;
      v6 = health;
    }
    if ( (v5 >> 6) & 1 )
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v4 + 16i64))(v4, &v3, COERCE_DOUBLE(*(_QWORD *)&v6));
  }
}

// File Line: 222
// RVA: 0x5E5410
void __fastcall UFG::UIHKHealthMeterWidget::Flash_UIHighlight_Init(UFG::UIHKHealthMeterWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rbx
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v4; // [rsp+50h] [rbp-58h]
  unsigned int v5; // [rsp+58h] [rbp-50h]
  const char *v6; // [rsp+60h] [rbp-48h]
  char v7; // [rsp+70h] [rbp-38h]
  __int64 v8; // [rsp+80h] [rbp-28h]
  unsigned int v9; // [rsp+88h] [rbp-20h]
  const char *v10; // [rsp+90h] [rbp-18h]

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v5 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v4 + 16i64))(v4, &ptr, v6);
      v4 = 0i64;
    }
    v5 = 6;
    v6 = "mc_HealthBar";
    if ( (v9 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v8 + 16i64))(v8, &v7, v10);
      v8 = 0i64;
    }
    v9 = 6;
    v10 = "mc_HealthBar_highlight";
    Scaleform::GFx::Movie::Invoke(v2, "UIHighlight_Init", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 237
// RVA: 0x5E1A40
void __fastcall UFG::UIHKHealthMeterWidget::Flash_SetVisible(UFG::UIHKHealthMeterWidget *this, UFG::UIScreen *screen, bool visible)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = visible;
    Scaleform::GFx::Movie::SetVariable(v3, "mc_HealthBar._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

