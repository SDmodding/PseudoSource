// File Line: 131
// RVA: 0x517470
void __fastcall UFG::FireModeInfo::FireModeInfo(UFG::FireModeInfo *this)
{
  unsigned int v2; // edi
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  AMD_HD3D *mUID; // rcx
  UFG::qArray<UFG::qWiseSymbol,0> *p_mSoundbankIds; // r14
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::qWiseSymbol *p; // rcx
  UFG::qWiseSymbol *v14; // rbx

  *(_QWORD *)&this->mSimObjectWeaponType = 0i64;
  v2 = 1;
  this->mAmmoClipCapacity = 1;
  this->mAmmoTotalCapacity = 1;
  *(_QWORD *)&this->mRateOfFire = 1036831949i64;
  *(_QWORD *)&this->mHardLockReticleSizeMax = 0i64;
  *(_QWORD *)&this->mReticleSizeMax = 0i64;
  *(_QWORD *)&this->mRangedDistance = 1065353216i64;
  this->mAngularInaccuracyRadMax = 0.0;
  this->mProjectileSpeed = -1.0;
  this->mProjectileSpeedAI = -1.0;
  *(_QWORD *)&this->mProjectileGravity = 0i64;
  this->mSlowModeRateOfFireMultiplier = 1.0;
  this->mSlowModeRateOfFireMultiplierAI = 1.0;
  this->mSlowModeProjectileSpeedMultiplier = 1.0;
  this->mSlowModeProjectileSpeedMultiplierAI = 1.0;
  this->mSlowModeProjectileDamageMultiplier = 1.0;
  this->mSlowModeProjectileDamageMultiplierAI = 1.0;
  this->mProjectilePhysicsImpulse = 50.0;
  *(_QWORD *)&this->mThrownSpeed = -1082130432i64;
  this->mProjectileSpawnBoneID = 0;
  this->mExplosionType.mUID = -1;
  *(_QWORD *)&this->mBulletLifeSpan = 0x40000000i64;
  *(_QWORD *)&this->mBulletTypeID = 0i64;
  this->mBulletPerShot = 0;
  this->mHardLockDamageMultiplier = 1.0;
  *(_QWORD *)&this->mDamageMultiplier = 1065353216i64;
  this->mPropDamage = 0.0;
  *(_QWORD *)&this->mProjectileReaction = 1i64;
  *(_QWORD *)&this->mAccuracyOnTargetChanged = 0i64;
  this->m_fAccuracyRateMultiplier = 1.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mMinAngularVelocityWhenThrown.x = UFG::qVector3::msZero.x;
  this->mMinAngularVelocityWhenThrown.y = y;
  this->mMinAngularVelocityWhenThrown.z = z;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  this->mMaxAngularVelocityWhenThrown.x = UFG::qVector3::msZero.x;
  this->mMaxAngularVelocityWhenThrown.y = v5;
  this->mMaxAngularVelocityWhenThrown.z = v6;
  *(_QWORD *)&this->mStartingMaxAmmoCount = 0i64;
  *(_QWORD *)&this->mAIOnDeathDropMaxAmmoCount = 0i64;
  this->mTracerBeamSettingsHandle = 0i64;
  this->mTracerBeamAISettingsHandle = 0i64;
  this->mTracerBeamTrailSettingsHandle = 0i64;
  this->mTracerBeamTrailAISettingsHandle = 0i64;
  mUID = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  this->mAudioWeaponType.mUID = (unsigned int)mUID;
  _(mUID);
  this->mAudioWeaponIsLooping = 0;
  p_mSoundbankIds = &this->mSoundbankIds;
  this->mSoundbankIds.p = 0i64;
  *(_QWORD *)&this->mSoundbankIds.size = 0i64;
  *(_QWORD *)&this->mAimYawPerSRad = 0i64;
  *(_QWORD *)&this->mAimMaxInputSpeedPerS = 0i64;
  this->mAimInputMappingOutput.size = 0;
  this->mAimInputMapping.nData = 0;
  this->mAimInputMapping.fDomain = 0i64;
  this->mAimInputMapping.tRange = 0i64;
  this->mAimFlickTransitionRadPerS = -1.0;
  this->mAimSubtargetTransitionRadPerS = -1.0;
  this->mAimFreeAimTransitionRadPerS = -1.0;
  *(_QWORD *)&this->mAimFovOffset = 0i64;
  *(_QWORD *)&this->mRecoilKickupMax = 0i64;
  this->mRecoilKickupRateAttack = 120.0;
  *(_QWORD *)&this->mRecoilKickupRateDecay = 1123024896i64;
  this->mRecoilKickbackSpeed = 0.0;
  *(_QWORD *)&this->mRecoilKickbackDur = 1036831949i64;
  *(_QWORD *)&this->mMaxDisiredDistance = 0i64;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->mAimOriginOffset.x = UFG::qVector3::msZero.x;
  this->mAimOriginOffset.y = v9;
  this->mAimOriginOffset.z = v10;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  this->mThrownWeaponSpinAxis.x = UFG::qVector3::msZero.x;
  this->mThrownWeaponSpinAxis.y = v11;
  this->mThrownWeaponSpinAxis.z = v12;
  p = this->mSoundbankIds.p;
  if ( p )
  {
    v14 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))UFG::qWiseSymbol::~qWiseSymbol);
    operator delete[](v14);
  }
  this->mSoundbankIds.p = 0i64;
  *(_QWORD *)&p_mSoundbankIds->size = 0i64;
  do
    v2 *= 2;
  while ( v2 < 3 );
  if ( v2 <= 4 )
    v2 = 4;
  if ( v2 - 3 > 0x10000 )
    v2 = 65539;
  UFG::qArray<UFG::qWiseSymbol,0>::Reallocate(&this->mSoundbankIds, v2, "Initialize to 3 slots");
  p_mSoundbankIds->size = 3;
}

// File Line: 238
// RVA: 0x51A1A0
void __fastcall UFG::WeaponTypeInfo::WeaponTypeInfo(UFG::WeaponTypeInfo *this)
{
  this->mPropertySetSymbol.mUID = -1;
  this->mNumFireModes = 0;
  this->mFireModes[0] = 0i64;
  this->mFireModes[1] = 0i64;
}

// File Line: 276
// RVA: 0x51F760
UFG::ComponentIDDesc *__fastcall UFG::SimObjectWeaponPropertiesComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  int v3; // [rsp+20h] [rbp-18h]

  if ( !UFG::SimObjectWeaponPropertiesComponent::_DescInit )
  {
    v0 = UFG::SimObjectPropertiesComponent::AccessComponentDesc();
    ++UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren));
    LOWORD(v3) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc.mBaseTypeIndex = v3;
    UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc.mChildren = 0;
    UFG::SimObjectWeaponPropertiesComponent::_DescInit = 1;
    UFG::SimObjectWeaponPropertiesComponent::_TypeUID = v1 | ((unsigned __int16)v3 << 25);
    UFG::SimObjectWeaponPropertiesComponent::_SimObjectWeaponPropertiesComponentTypeUID = v1 | ((unsigned __int16)v3 << 25);
  }
  return &UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc;
}

// File Line: 334
// RVA: 0x4666C0
UFG::qSymbol *__fastcall UFG::SimObjectWeaponPropertiesComponent::GetExplosionType(
        UFG::SimObjectWeaponPropertiesComponent *this,
        UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mExplosionType;
  return result;
}

// File Line: 438
// RVA: 0x4A7300
UFG::qSymbol *__fastcall UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(
        UFG::SimObjectWeaponPropertiesComponent *this,
        UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rax

  v2 = result;
  result->mUID = this->mWeaponTypeInfo->mPropertySetSymbol.mUID;
  return v2;
}

// File Line: 441
// RVA: 0x525F80
float __fastcall UFG::SimObjectWeaponPropertiesComponent::DetermineRateOfFire(
        UFG::SimObjectWeaponPropertiesComponent *this,
        const bool bAI)
{
  float mRateOfFire; // xmm6_4
  UFG::FireModeInfo *v5; // rcx
  float mSlowModeRateOfFireMultiplierAI; // xmm0_4

  mRateOfFire = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mRateOfFire;
  if ( UFG::Metrics::IsTimeScaled(&UFG::Metrics::msInstance) )
  {
    v5 = this->mWeaponTypeInfo->mFireModes[this->mFireMode];
    if ( bAI )
      mSlowModeRateOfFireMultiplierAI = v5->mSlowModeRateOfFireMultiplierAI;
    else
      mSlowModeRateOfFireMultiplierAI = v5->mSlowModeRateOfFireMultiplier;
    return mRateOfFire * mSlowModeRateOfFireMultiplierAI;
  }
  return mRateOfFire;
}

// File Line: 453
// RVA: 0x525EE0
float __fastcall UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileSpeed(
        UFG::SimObjectWeaponPropertiesComponent *this,
        const bool bAI)
{
  float mProjectileSpeedAI; // xmm6_4
  UFG::FireModeInfo *v5; // rcx
  float mSlowModeProjectileSpeedMultiplierAI; // xmm0_4

  if ( bAI )
    mProjectileSpeedAI = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpeedAI;
  else
    mProjectileSpeedAI = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpeed;
  if ( UFG::Metrics::IsTimeScaled(&UFG::Metrics::msInstance) )
  {
    v5 = this->mWeaponTypeInfo->mFireModes[this->mFireMode];
    if ( bAI )
      mSlowModeProjectileSpeedMultiplierAI = v5->mSlowModeProjectileSpeedMultiplierAI;
    else
      mSlowModeProjectileSpeedMultiplierAI = v5->mSlowModeProjectileSpeedMultiplier;
    return mProjectileSpeedAI * mSlowModeProjectileSpeedMultiplierAI;
  }
  return mProjectileSpeedAI;
}

// File Line: 464
// RVA: 0x525E70
float __fastcall UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileDamage(
        UFG::SimObjectWeaponPropertiesComponent *this,
        const bool bAI)
{
  UFG::FireModeInfo *v4; // rcx

  if ( !UFG::Metrics::IsTimeScaled(&UFG::Metrics::msInstance) )
    return *(float *)&FLOAT_1_0;
  v4 = this->mWeaponTypeInfo->mFireModes[this->mFireMode];
  if ( bAI )
    return v4->mSlowModeProjectileDamageMultiplierAI;
  else
    return v4->mSlowModeProjectileDamageMultiplier;
}

