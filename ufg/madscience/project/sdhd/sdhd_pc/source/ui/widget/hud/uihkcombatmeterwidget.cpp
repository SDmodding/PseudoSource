// File Line: 55
// RVA: 0x613720
void __fastcall UFG::UIHKCombatMeterWidget::Update(UFG::UIHKCombatMeterWidget *this, UFG::UIScreen *screen)
{
  bool mCombatActive; // r14
  float mCombatMeterValue; // xmm6_4
  float mChargedFacePercent; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  UFG::GameStatTracker *v9; // rax
  UFG::GameStatTracker *v10; // rax
  UFG::GameStatTracker *v11; // rax
  float Stat; // xmm7_4
  UFG::GameStatTracker *v13; // rax
  float v14; // xmm1_4
  bool v15; // si
  signed __int16 m_Flags; // dx
  UFG::GameStatTracker *v17; // rax
  UFG::GameStatTracker *v18; // rax
  float v19; // xmm0_4
  Scaleform::GFx::Movie *v20; // rcx
  bool v21; // zf
  float v22; // xmm3_4
  bool v23; // cl
  Scaleform::GFx::Movie *v24; // rcx
  Scaleform::GFx::Movie *pObject; // rcx

  mCombatActive = this->mCombatActive;
  mCombatMeterValue = this->mCombatMeterValue;
  if ( UFG::UIHKTweakables::UseFakeCombatValues )
  {
    mChargedFacePercent = this->mChargedFacePercent;
    this->mCombatMeterValue = (float)UFG::UIHKTweakables::FakeCombatMeterValue;
    this->mCombatActive = UFG::UIHKTweakables::CombatActive;
    v7 = (float)UFG::UIHKTweakables::FakeCombatChargeValue;
    if ( (float)UFG::UIHKTweakables::FakeCombatChargeValue > (float)(100 * this->mPipCount) )
      v7 = (float)(100 * this->mPipCount);
    v8 = v7 * 0.2;
    this->mChargedFacePercent = v8;
    this->mChanged |= (float)(v8 - mChargedFacePercent) > 0.001;
    UFG::UIHKCombatMeterWidget::SetCombatAction(this);
  }
  else
  {
    v9 = UFG::GameStatTracker::Instance();
    this->mCombatMeterValue = UFG::GameStatTracker::GetStat(v9, Face);
    this->mCombatActive = UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(
                            UFG::LocalPlayerIsInCombatManager::s_pInstance,
                            0);
  }
  v10 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::GetStat(v10, Standing);
  v11 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v11, PlayerFaceMeterBuff_Activated);
  UFG::UIHKCombatMeterWidget::UpdatePipCount(this, this->mCombatMeterValue);
  v13 = UFG::GameStatTracker::Instance();
  v14 = (float)(int)UFG::GameStatTracker::GetStat(v13, Standing);
  UFG::UIHKCombatMeterWidget::mEnabled = v14 >= 1000.0;
  v15 = UFG::UIHKCombatMeterWidget::m_bScriptWantVisible && v14 >= 1000.0;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::FaceMeterComponent::_TypeUID);
    else
      UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::FaceMeterComponent::_TypeUID);
  }
  if ( this->mState )
  {
    switch ( this->mState )
    {
      case STATE_ROOT_MENU:
        UFG::UIHKCombatMeterWidget::Flash_Update(this, screen, mCombatMeterValue, this->mCombatMeterValue);
        pObject = screen->mRenderable->m_movie.pObject;
        if ( pObject )
          Scaleform::GFx::Movie::Invoke(pObject, "CombatMeter_Intro", 0i64, 0i64, 0);
        this->mState = STATE_PHONE_CONTACTS;
        break;
      case STATE_TEXT_INBOX:
        if ( !v15 )
        {
LABEL_29:
          v20 = screen->mRenderable->m_movie.pObject;
          if ( v20 )
            Scaleform::GFx::Movie::Invoke(v20, "CombatMeter_Outro", 0i64, 0i64, 0);
          this->mState = STATE_OUTGOING_CALL;
          return;
        }
        if ( this->mShouldHighlight )
        {
          this->mShouldHighlight = 0;
          UFG::UIHKCombatMeterWidget::Flash_UIHighlight_Init(this, screen);
        }
        if ( Stat > 0.0 )
        {
          v21 = !this->mPreserveBuffStartingDuration;
          this->mState = STATE_INCOMING_CALL;
          if ( v21 )
          {
            this->mBuffStartingMeter = mCombatMeterValue;
            this->mBuffStartingDuration = Stat;
          }
        }
        v21 = this->mCombatActive == mCombatActive;
        v22 = this->mCombatMeterValue;
        this->mPreserveBuffStartingDuration = 0;
        this->mChanged |= !v21;
        v23 = v22 != mCombatMeterValue || this->mChanged;
        v21 = !this->mPingCombatActionFlag;
        this->mChanged = v23;
        if ( v21 )
        {
          if ( v23 )
          {
            UFG::UIHKCombatMeterWidget::Flash_Update(this, screen, mCombatMeterValue, v22);
            this->mChanged = 0;
          }
        }
        else
        {
          this->mPingCombatActionFlag = 0;
          v24 = screen->mRenderable->m_movie.pObject;
          if ( v24 )
            Scaleform::GFx::Movie::Invoke(v24, "pingFaceCombatAction", 0i64, 0i64, 0);
        }
        break;
      case STATE_INCOMING_CALL:
        if ( v15 )
        {
          v17 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::GetStat(v17, Standing);
          v18 = UFG::GameStatTracker::Instance();
          v19 = UFG::GameStatTracker::GetStat(v18, PlayerFaceMeterBuff_Activated);
          if ( v19 < 0.000099999997 )
            this->mState = STATE_TEXT_INBOX;
          if ( this->mBuffStartingDuration <= 0.0 )
            this->mBuffStartingDuration = 1.0;
          UFG::UIHKCombatMeterWidget::Flash_Update(
            this,
            screen,
            mCombatMeterValue,
            (float)(v19 * this->mBuffStartingMeter) / this->mBuffStartingDuration);
          return;
        }
        goto LABEL_29;
      default:
        return;
    }
  }
  else if ( v15 )
  {
    this->mState = STATE_ROOT_MENU;
  }
}

// File Line: 296
// RVA: 0x5F3AF0
void __fastcall UFG::UIHKCombatMeterWidget::PipsUsed(UFG::UIHKCombatMeterWidget *this, int numPips)
{
  bool v2; // sf
  int mPipCount; // eax

  v2 = this->mPipCount - numPips < 0;
  this->mPipCount -= numPips;
  mPipCount = this->mPipCount;
  if ( v2 )
    mPipCount = 0;
  this->mChanged = 1;
  this->mPipCount = mPipCount;
}

// File Line: 307
// RVA: 0x6056C0
void __fastcall UFG::UIHKCombatMeterWidget::SetCombatCharge(UFG::UIHKCombatMeterWidget *this, float charge)
{
  float mChargedFacePercent; // xmm2_4
  float v3; // xmm1_4

  mChargedFacePercent = this->mChargedFacePercent;
  if ( charge > (float)(100 * this->mPipCount) )
    charge = (float)(100 * this->mPipCount);
  v3 = charge * 0.2;
  this->mChargedFacePercent = v3;
  this->mChanged |= (float)(v3 - mChargedFacePercent) > 0.001;
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
  float mChargedFacePercent; // xmm0_4

  mChargedFacePercent = this->mChargedFacePercent;
  if ( mChargedFacePercent >= 20.0 && mChargedFacePercent < 40.0 )
  {
    this->mCombatAction = COMBAT_INTIMIDATE;
    return;
  }
  if ( mChargedFacePercent >= 40.0 && mChargedFacePercent < 60.0 )
  {
    this->mCombatAction = COMBAT_HEALTH_REGEN;
    return;
  }
  if ( mChargedFacePercent >= 60.0 && mChargedFacePercent < 80.0 )
  {
    this->mCombatAction = COMBAT_GROUP_INTIMIDATE;
    return;
  }
  if ( mChargedFacePercent < 80.0 )
  {
    if ( mChargedFacePercent < 100.0 )
      return;
  }
  else if ( mChargedFacePercent < 100.0 )
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
  int mPipCount; // edx
  __m128 mCombatMeterValue_low; // xmm1
  int v4; // r8d
  int v5; // r8d

  mPipCount = this->mPipCount;
  mCombatMeterValue_low = (__m128)LODWORD(this->mCombatMeterValue);
  mCombatMeterValue_low.m128_f32[0] = mCombatMeterValue_low.m128_f32[0] * 0.0099999998;
  v4 = (int)mCombatMeterValue_low.m128_f32[0];
  if ( (int)mCombatMeterValue_low.m128_f32[0] != 0x80000000 && (float)v4 != mCombatMeterValue_low.m128_f32[0] )
    mCombatMeterValue_low.m128_f32[0] = (float)(v4
                                              - (_mm_movemask_ps(_mm_unpacklo_ps(mCombatMeterValue_low, mCombatMeterValue_low)) & 1));
  v5 = (int)mCombatMeterValue_low.m128_f32[0];
  if ( (int)mCombatMeterValue_low.m128_f32[0] <= mPipCount )
  {
    if ( mPipCount - v5 < 2 )
    {
      if ( this->mCombatMeterValue == 0.0 )
        this->mPipCount = 0;
      this->mChanged |= this->mPipCount != mPipCount;
    }
    else
    {
      this->mPipCount = mPipCount - 1;
      this->mChanged |= mPipCount - 1 != mPipCount;
    }
  }
  else
  {
    this->mPipCount = v5;
    this->mChanged |= v5 != mPipCount;
  }
}

// File Line: 417
// RVA: 0x5E52E0
void __fastcall UFG::UIHKCombatMeterWidget::Flash_UIHighlight_Init(
        UFG::UIHKCombatMeterWidget *this,
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
    ptr.mValue.pString = "mcCombatMeter";
    if ( (v6 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v5 + 16i64))(v5, v4, v7);
      v5 = 0i64;
    }
    v6 = 6;
    v7 = "mcCombatMeter_highlight";
    Scaleform::GFx::Movie::Invoke(pObject, "UIHighlight_Init", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 432
// RVA: 0x5E5670
void __fastcall UFG::UIHKCombatMeterWidget::Flash_Update(
        UFG::UIHKCombatMeterWidget *this,
        UFG::UIScreen *screen,
        float oldCombatValue,
        float combatMeterValue)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+28h] [rbp-71h] BYREF
  char v6[16]; // [rsp+58h] [rbp-41h] BYREF
  __int64 v7; // [rsp+68h] [rbp-31h]
  int v8; // [rsp+70h] [rbp-29h]
  double v9; // [rsp+78h] [rbp-21h]
  char v10[16]; // [rsp+88h] [rbp-11h] BYREF
  __int64 v11; // [rsp+98h] [rbp-1h]
  int v12; // [rsp+A0h] [rbp+7h]
  __int64 v13; // [rsp+A8h] [rbp+Fh]
  __int64 v14; // [rsp+B8h] [rbp+1Fh]
  char v15; // [rsp+118h] [rbp+7Fh]

  v14 = -2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
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
    ptr.mValue.NValue = oldCombatValue;
    if ( (v8 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, v6, COERCE_DOUBLE(*(_QWORD *)&v9));
      v7 = 0i64;
    }
    v8 = 5;
    v9 = combatMeterValue;
    if ( (v12 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, v10, v13);
      v11 = 0i64;
    }
    v12 = 2;
    LOBYTE(v13) = v15;
    Scaleform::GFx::Movie::Invoke(pObject, "CombatMeter_Update", 0i64, &ptr, 3u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

