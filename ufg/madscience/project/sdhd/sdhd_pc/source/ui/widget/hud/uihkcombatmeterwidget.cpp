// File Line: 55
// RVA: 0x613720
void __fastcall UFG::UIHKCombatMeterWidget::Update(UFG::UIHKCombatMeterWidget *this, UFG::UIScreen *screen)
{
  bool v2; // r14
  float v3; // xmm6_4
  UFG::UIScreen *v4; // rdi
  UFG::UIHKCombatMeterWidget *v5; // rbx
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  UFG::GameStatTracker *v9; // rax
  UFG::GameStatTracker *v10; // rax
  UFG::GameStatTracker *v11; // rax
  float v12; // xmm7_4
  UFG::GameStatTracker *v13; // rax
  float v14; // xmm1_4
  bool v15; // si
  unsigned __int16 v16; // dx
  UFG::SimComponent *v17; // rax
  char v18; // bp
  UFG::GameStatTracker *v19; // rax
  UFG::GameStatTracker *v20; // rax
  float v21; // xmm0_4
  Scaleform::GFx::Movie *v22; // rcx
  bool v23; // zf
  float v24; // xmm3_4
  bool v25; // cl
  Scaleform::GFx::Movie *v26; // rcx
  Scaleform::GFx::Movie *v27; // rcx

  v2 = this->mCombatActive;
  v3 = this->mCombatMeterValue;
  v4 = screen;
  v5 = this;
  if ( UFG::UIHKTweakables::UseFakeCombatValues )
  {
    v6 = this->mChargedFacePercent;
    this->mCombatMeterValue = (float)UFG::UIHKTweakables::FakeCombatMeterValue;
    this->mCombatActive = UFG::UIHKTweakables::CombatActive;
    v7 = (float)UFG::UIHKTweakables::FakeCombatChargeValue;
    if ( (float)UFG::UIHKTweakables::FakeCombatChargeValue > (float)(100 * this->mPipCount) )
      v7 = (float)(100 * this->mPipCount);
    v8 = v7 * 0.2;
    this->mChargedFacePercent = v8;
    this->mChanged |= (float)(v8 - v6) > 0.001;
    UFG::UIHKCombatMeterWidget::SetCombatAction(this);
  }
  else
  {
    v9 = UFG::GameStatTracker::Instance();
    v5->mCombatMeterValue = UFG::GameStatTracker::GetStat(v9, Face);
    v5->mCombatActive = UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(
                          UFG::LocalPlayerIsInCombatManager::s_pInstance,
                          0);
  }
  v10 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::GetStat(v10, Standing);
  v11 = UFG::GameStatTracker::Instance();
  v12 = UFG::GameStatTracker::GetStat(v11, PlayerFaceMeterBuff_Activated);
  UFG::UIHKCombatMeterWidget::UpdatePipCount(v5, v5->mCombatMeterValue);
  v13 = UFG::GameStatTracker::Instance();
  v14 = (float)(signed int)UFG::GameStatTracker::GetStat(v13, Standing);
  UFG::UIHKCombatMeterWidget::mEnabled = v14 >= 1000.0;
  v15 = UFG::UIHKCombatMeterWidget::m_bScriptWantVisible && v14 >= 1000.0;
  if ( LocalPlayer )
  {
    v16 = LocalPlayer->m_Flags;
    if ( (v16 >> 14) & 1 )
    {
      v17 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&LocalPlayer->vfptr,
              UFG::FaceMeterComponent::_TypeUID);
    }
    else if ( (v16 & 0x8000u) == 0 )
    {
      if ( (v16 >> 13) & 1 )
        v17 = UFG::SimObjectGame::GetComponentOfTypeHK(
                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                UFG::FaceMeterComponent::_TypeUID);
      else
        v17 = (v16 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                  UFG::FaceMeterComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                         (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                         UFG::FaceMeterComponent::_TypeUID);
    }
    else
    {
      v17 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&LocalPlayer->vfptr,
              UFG::FaceMeterComponent::_TypeUID);
    }
    if ( v17 )
      v18 = BYTE1(v17[135].m_SafePointerList.mNode.mPrev);
  }
  if ( v5->mState )
  {
    switch ( v5->mState )
    {
      case 1:
        UFG::UIHKCombatMeterWidget::Flash_Update(v5, v4, v3, v5->mCombatMeterValue);
        v27 = v4->mRenderable->m_movie.pObject;
        if ( v27 )
          Scaleform::GFx::Movie::Invoke(v27, "CombatMeter_Intro", 0i64, 0i64, 0);
        v5->mState = 2;
        break;
      case 3:
        if ( !v15 )
        {
LABEL_33:
          v22 = v4->mRenderable->m_movie.pObject;
          if ( v22 )
            Scaleform::GFx::Movie::Invoke(v22, "CombatMeter_Outro", 0i64, 0i64, 0);
          v5->mState = 5;
          return;
        }
        if ( v5->mShouldHighlight )
        {
          v5->mShouldHighlight = 0;
          UFG::UIHKCombatMeterWidget::Flash_UIHighlight_Init(v5, v4);
        }
        if ( v12 > 0.0 )
        {
          v23 = v5->mPreserveBuffStartingDuration == 0;
          v5->mState = 4;
          if ( v23 )
          {
            v5->mBuffStartingMeter = v3;
            v5->mBuffStartingDuration = v12;
          }
        }
        v23 = v5->mCombatActive == v2;
        v24 = v5->mCombatMeterValue;
        v5->mPreserveBuffStartingDuration = 0;
        v5->mChanged |= !v23;
        v25 = v24 != v3 || v5->mChanged;
        v23 = v5->mPingCombatActionFlag == 0;
        v5->mChanged = v25;
        if ( v23 )
        {
          if ( v25 )
          {
            UFG::UIHKCombatMeterWidget::Flash_Update(v5, v4, v3, v24);
            v5->mChanged = 0;
          }
        }
        else
        {
          v5->mPingCombatActionFlag = 0;
          v26 = v4->mRenderable->m_movie.pObject;
          if ( v26 )
            Scaleform::GFx::Movie::Invoke(v26, "pingFaceCombatAction", 0i64, 0i64, 0);
        }
        break;
      case 4:
        if ( v15 )
        {
          v19 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::GetStat(v19, Standing);
          v20 = UFG::GameStatTracker::Instance();
          v21 = UFG::GameStatTracker::GetStat(v20, PlayerFaceMeterBuff_Activated);
          if ( v21 < 0.000099999997 )
            v5->mState = 3;
          if ( v5->mBuffStartingDuration <= 0.0 )
            v5->mBuffStartingDuration = 1.0;
          UFG::UIHKCombatMeterWidget::Flash_Update(
            v5,
            v4,
            v3,
            (float)(v21 * v5->mBuffStartingMeter) / v5->mBuffStartingDuration);
          return;
        }
        goto LABEL_33;
      default:
        return;
    }
  }
  else if ( v15 )
  {
    v5->mState = 1;
  }
}

// File Line: 296
// RVA: 0x5F3AF0
void __fastcall UFG::UIHKCombatMeterWidget::PipsUsed(UFG::UIHKCombatMeterWidget *this, int numPips)
{
  bool v2; // sf
  int v3; // eax

  v2 = this->mPipCount - numPips < 0;
  this->mPipCount -= numPips;
  v3 = this->mPipCount;
  if ( v2 )
    v3 = 0;
  this->mChanged = 1;
  this->mPipCount = v3;
}

// File Line: 307
// RVA: 0x6056C0
void __fastcall UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKCombatMeterWidget *this, float charge)
{
  float v2; // xmm2_4
  float v3; // xmm1_4

  v2 = this->mChargedFacePercent;
  if ( charge > (float)(100 * this->mPipCount) )
    charge = (float)(100 * this->mPipCount);
  v3 = charge * 0.2;
  this->mChargedFacePercent = v3;
  this->mChanged |= (float)(v3 - v2) > 0.001;
  UFG::UIHKCombatMeterWidget::SetCombatAction(this);
}

// File Line: 326
// RVA: 0x5E7190
float __fastcall UFG::UIHKCombatMeterWidget::GetCombatCharge(UFG::UIHKCombatMeterWidget *this)
{
  return this->mChargedFacePercent * 5.0;
}

// File Line: 332
// RVA: 0x605640
void __fastcall UFG::UIHKCombatMeterWidget::SetCombatAction(UFG::UIHKCombatMeterWidget *this)
{
  float v1; // xmm0_4

  v1 = this->mChargedFacePercent;
  if ( v1 >= 20.0 && v1 < 40.0 )
  {
    this->mCombatAction = COMBAT_INTIMIDATE;
    return;
  }
  if ( v1 >= 40.0 && v1 < 60.0 )
  {
    this->mCombatAction = COMBAT_HEALTH_REGEN;
    return;
  }
  if ( v1 >= 60.0 && v1 < 80.0 )
  {
    this->mCombatAction = COMBAT_GROUP_INTIMIDATE;
    return;
  }
  if ( v1 < 80.0 )
  {
    if ( v1 < 100.0 )
      return;
  }
  else if ( v1 < 100.0 )
  {
    this->mCombatAction = COMBAT_BERSERK;
    return;
  }
  this->mCombatAction = COMBAT_MARKSMAN;
}

// File Line: 357
// RVA: 0x5F3A50
void __fastcall UFG::UIHKCombatMeterWidget::PingCombatAction(UFG::UIHKCombatMeterWidget *this)
{
  this->mPingCombatActionFlag = 1;
}

// File Line: 363
// RVA: 0x61CDE0
void __fastcall UFG::UIHKCombatMeterWidget::UpdatePipCount(UFG::UIHKCombatMeterWidget *this, float combatMeterValue)
{
  int v2; // edx
  __m128 v3; // xmm1
  signed int v4; // er8
  int v5; // er8

  v2 = this->mPipCount;
  v3 = (__m128)LODWORD(this->mCombatMeterValue);
  v3.m128_f32[0] = v3.m128_f32[0] * 0.0099999998;
  v4 = (signed int)v3.m128_f32[0];
  if ( (signed int)v3.m128_f32[0] != 0x80000000 && (float)v4 != v3.m128_f32[0] )
    v3.m128_f32[0] = (float)(v4 - (_mm_movemask_ps(_mm_unpacklo_ps(v3, v3)) & 1));
  v5 = (signed int)v3.m128_f32[0];
  if ( (signed int)v3.m128_f32[0] <= v2 )
  {
    if ( v2 - v5 < 2 )
    {
      if ( this->mCombatMeterValue == 0.0 )
        this->mPipCount = 0;
      this->mChanged |= this->mPipCount != v2;
    }
    else
    {
      this->mPipCount = v2 - 1;
      this->mChanged |= v2 - 1 != v2;
    }
  }
  else
  {
    this->mPipCount = v5;
    this->mChanged |= v5 != v2;
  }
}

// File Line: 417
// RVA: 0x5E52E0
void __fastcall UFG::UIHKCombatMeterWidget::Flash_UIHighlight_Init(UFG::UIHKCombatMeterWidget *this, UFG::UIScreen *screen)
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
    v6 = "mcCombatMeter";
    if ( (v9 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v8 + 16i64))(v8, &v7, v10);
      v8 = 0i64;
    }
    v9 = 6;
    v10 = "mcCombatMeter_highlight";
    Scaleform::GFx::Movie::Invoke(v2, "UIHighlight_Init", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 432
// RVA: 0x5E5670
void __fastcall UFG::UIHKCombatMeterWidget::Flash_Update(UFG::UIHKCombatMeterWidget *this, UFG::UIScreen *screen, float oldCombatValue, float combatMeterValue)
{
  Scaleform::GFx::Movie *v4; // rbx
  char ptr; // [rsp+28h] [rbp-71h]
  __int64 v6; // [rsp+38h] [rbp-61h]
  unsigned int v7; // [rsp+40h] [rbp-59h]
  double v8; // [rsp+48h] [rbp-51h]
  char v9; // [rsp+58h] [rbp-41h]
  __int64 v10; // [rsp+68h] [rbp-31h]
  unsigned int v11; // [rsp+70h] [rbp-29h]
  double v12; // [rsp+78h] [rbp-21h]
  char v13; // [rsp+88h] [rbp-11h]
  __int64 v14; // [rsp+98h] [rbp-1h]
  unsigned int v15; // [rsp+A0h] [rbp+7h]
  __int64 v16; // [rsp+A8h] [rbp+Fh]
  __int64 v17; // [rsp+B8h] [rbp+1Fh]
  char v18; // [rsp+118h] [rbp+7Fh]

  v17 = -2i64;
  v4 = screen->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v7 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, &ptr, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = oldCombatValue;
    if ( (v11 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
        v10,
        &v9,
        COERCE_DOUBLE(*(_QWORD *)&v12));
      v10 = 0i64;
    }
    v11 = 5;
    v12 = combatMeterValue;
    if ( (v15 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v14 + 16i64))(v14, &v13, v16);
      v14 = 0i64;
    }
    v15 = 2;
    LOBYTE(v16) = v18;
    Scaleform::GFx::Movie::Invoke(v4, "CombatMeter_Update", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

