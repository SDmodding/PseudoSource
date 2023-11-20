// File Line: 131
// RVA: 0x517470
void __fastcall UFG::FireModeInfo::FireModeInfo(UFG::FireModeInfo *this)
{
  UFG::FireModeInfo *v1; // rsi
  unsigned int v2; // edi
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  AMD_HD3D *v7; // rcx
  UFG::qArray<UFG::qWiseSymbol,0> *v8; // r14
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::qWiseSymbol *v13; // rcx
  UFG::qWiseSymbol *v14; // rbx

  v1 = this;
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
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->mMinAngularVelocityWhenThrown.x = UFG::qVector3::msZero.x;
  this->mMinAngularVelocityWhenThrown.y = v3;
  this->mMinAngularVelocityWhenThrown.z = v4;
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
  v7 = (AMD_HD3D *)UFG::qWiseSymbol::get_null()->mUID;
  v1->mAudioWeaponType.mUID = (unsigned int)v7;
  _(v7);
  v1->mAudioWeaponIsLooping = 0;
  v8 = &v1->mSoundbankIds;
  v8->p = 0i64;
  *(_QWORD *)&v8->size = 0i64;
  *(_QWORD *)&v1->mAimYawPerSRad = 0i64;
  *(_QWORD *)&v1->mAimMaxInputSpeedPerS = 0i64;
  v1->mAimInputMappingOutput.size = 0;
  v1->mAimInputMapping.nData = 0;
  v1->mAimInputMapping.fDomain = 0i64;
  v1->mAimInputMapping.tRange = 0i64;
  v1->mAimFlickTransitionRadPerS = -1.0;
  v1->mAimSubtargetTransitionRadPerS = -1.0;
  v1->mAimFreeAimTransitionRadPerS = -1.0;
  *(_QWORD *)&v1->mAimFovOffset = 0i64;
  *(_QWORD *)&v1->mRecoilKickupMax = 0i64;
  v1->mRecoilKickupRateAttack = 120.0;
  *(_QWORD *)&v1->mRecoilKickupRateDecay = 1123024896i64;
  v1->mRecoilKickbackSpeed = 0.0;
  *(_QWORD *)&v1->mRecoilKickbackDur = 1036831949i64;
  *(_QWORD *)&v1->mMaxDisiredDistance = 0i64;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v1->mAimOriginOffset.x = UFG::qVector3::msZero.x;
  v1->mAimOriginOffset.y = v9;
  v1->mAimOriginOffset.z = v10;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  v1->mThrownWeaponSpinAxis.x = UFG::qVector3::msZero.x;
  v1->mThrownWeaponSpinAxis.y = v11;
  v1->mThrownWeaponSpinAxis.z = v12;
  v13 = v1->mSoundbankIds.p;
  if ( v13 )
  {
    v14 = v13 - 1;
    `eh vector destructor iterator'(
      v13,
      4ui64,
      v13[-1].mUID,
      (void (__fastcall *)(void *))UFG::qWiseSymbol::~qWiseSymbol);
    operator delete[](v14);
  }
  v1->mSoundbankIds.p = 0i64;
  for ( *(_QWORD *)&v8->size = 0i64; v2 < 3; v2 *= 2 )
    ;
  if ( v2 <= 4 )
    v2 = 4;
  if ( v2 - 3 > 0x10000 )
    v2 = 65539;
  UFG::qArray<UFG::qWiseSymbol,0>::Reallocate(&v1->mSoundbankIds, v2, "Initialize to 3 slots");
  v8->size = 3;
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
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::SimObjectWeaponPropertiesComponent::_DescInit )
  {
    v0 = UFG::SimObjectPropertiesComponent::AccessComponentDesc();
    ++UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::SimObjectPropertiesComponent::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc.mChildBitMask = v1;
    UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc.mChildren = 0;
    UFG::SimObjectWeaponPropertiesComponent::_DescInit = 1;
    UFG::SimObjectWeaponPropertiesComponent::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::SimObjectWeaponPropertiesComponent::_SimObjectWeaponPropertiesComponentTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc;
}

// File Line: 334
// RVA: 0x4666C0
UFG::qSymbol *__fastcall UFG::SimObjectWeaponPropertiesComponent::GetExplosionType(UFG::SimObjectWeaponPropertiesComponent *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mExplosionType;
  return result;
}

// File Line: 438
// RVA: 0x4A7300
UFG::qSymbol *__fastcall UFG::SimObjectWeaponPropertiesComponent::GetWeaponID(UFG::SimObjectWeaponPropertiesComponent *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rax

  v2 = result;
  result->mUID = this->mWeaponTypeInfo->mPropertySetSymbol.mUID;
  return v2;
}

// File Line: 441
// RVA: 0x525F80
float __fastcall UFG::SimObjectWeaponPropertiesComponent::DetermineRateOfFire(UFG::SimObjectWeaponPropertiesComponent *this, const bool bAI)
{
  UFG::SimObjectWeaponPropertiesComponent *v2; // rbx
  bool v3; // di
  float v4; // xmm6_4
  UFG::FireModeInfo *v5; // rcx
  float v6; // xmm0_4

  v2 = this;
  v3 = bAI;
  v4 = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mRateOfFire;
  if ( UFG::Metrics::IsTimeScaled(&UFG::Metrics::msInstance) )
  {
    v5 = v2->mWeaponTypeInfo->mFireModes[v2->mFireMode];
    if ( v3 )
      v6 = v5->mSlowModeRateOfFireMultiplierAI;
    else
      v6 = v5->mSlowModeRateOfFireMultiplier;
    v4 = v4 * v6;
  }
  return v4;
}

// File Line: 453
// RVA: 0x525EE0
float __fastcall UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileSpeed(UFG::SimObjectWeaponPropertiesComponent *this, const bool bAI)
{
  bool v2; // di
  UFG::SimObjectWeaponPropertiesComponent *v3; // rbx
  float v4; // xmm6_4
  UFG::FireModeInfo *v5; // rcx
  float v6; // xmm0_4

  v2 = bAI;
  v3 = this;
  if ( bAI )
    v4 = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpeedAI;
  else
    v4 = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpeed;
  if ( UFG::Metrics::IsTimeScaled(&UFG::Metrics::msInstance) )
  {
    v5 = v3->mWeaponTypeInfo->mFireModes[v3->mFireMode];
    if ( v2 )
      v6 = v5->mSlowModeProjectileSpeedMultiplierAI;
    else
      v6 = v5->mSlowModeProjectileSpeedMultiplier;
    v4 = v4 * v6;
  }
  return v4;
}

// File Line: 464
// RVA: 0x525E70
float __fastcall UFG::SimObjectWeaponPropertiesComponent::DetermineProjectileDamage(UFG::SimObjectWeaponPropertiesComponent *this, const bool bAI)
{
  UFG::SimObjectWeaponPropertiesComponent *v2; // rbx
  bool v3; // di
  UFG::FireModeInfo *v4; // rcx
  float result; // xmm0_4

  v2 = this;
  v3 = bAI;
  if ( !UFG::Metrics::IsTimeScaled(&UFG::Metrics::msInstance) )
    return *(float *)&FLOAT_1_0;
  v4 = v2->mWeaponTypeInfo->mFireModes[v2->mFireMode];
  if ( v3 )
    result = v4->mSlowModeProjectileDamageMultiplierAI;
  else
    result = v4->mSlowModeProjectileDamageMultiplier;
  return result;
}

