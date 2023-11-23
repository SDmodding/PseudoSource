// File Line: 96
// RVA: 0x536B20
void __fastcall UFG::FireModeInfo::InitFromPropertySet(UFG::FireModeInfo *this, UFG::qPropertySet *properties)
{
  float *v4; // rax
  float *v5; // rax
  float *v6; // rax
  float *v7; // rax
  int *v8; // rax
  int *v9; // rax
  unsigned int *v10; // rax
  float *v11; // rax
  bool *v12; // rax
  bool *v13; // rax
  bool *v14; // rax
  bool *v15; // rax
  UFG::qVector3 *v16; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm1_4
  float v21; // xmm2_4
  unsigned int *v22; // rax
  float *v23; // rax
  float *v24; // rax
  float *v25; // rax
  float *v26; // rax
  float *v27; // rax
  float *v28; // rax
  float *v29; // rax
  float *v30; // rax
  float *v31; // rax
  float *v32; // rax
  float *v33; // rax
  float *v34; // rax
  float *v35; // rax
  unsigned int *v36; // rax
  unsigned int *v37; // rax
  unsigned int *v38; // rax
  unsigned int *v39; // rax
  float *v40; // rax
  float *v41; // rax
  float *v42; // rax
  float *v43; // rax
  float *v44; // rax
  float *v45; // rax
  float *v46; // rax
  float *v47; // rax
  float *v48; // rax
  float *v49; // rax
  float *v50; // rax
  float *v51; // rax
  float *v52; // rax
  float *v53; // rax
  float *v54; // rax
  float *v55; // rax
  float *v56; // rax
  float *v57; // rax
  float *v58; // rax
  float *v59; // rax
  float *v60; // rax
  float *v61; // rax
  float *v62; // rax
  float *v63; // rax
  float *v64; // rax
  float *v65; // rax
  float *v66; // rax
  float *v67; // rax
  UFG::qVector3 *v68; // rax
  float v69; // xmm1_4
  float v70; // xmm2_4
  UFG::qVector3 *v71; // rax
  float v72; // xmm1_4
  float v73; // xmm2_4
  UFG::qWiseSymbol *p; // rbx
  UFG::qWiseSymbol *v75; // rax
  unsigned int v76; // r15d
  UFG::qPropertyList *v77; // rax
  UFG::qPropertyList *v78; // rdi
  unsigned int mNumElements; // r12d
  unsigned int i; // ebx
  UFG::qWiseSymbol *v81; // rax
  UFG::qWiseSymbol *v82; // rax
  bool *v83; // rax
  unsigned int *v84; // rax
  UFG::qSymbolUC *p_beamSettingsSymbol; // rcx
  int mUID; // edi
  unsigned int *v87; // rax
  UFG::qSymbolUC **v88; // rcx
  int v89; // ebx
  unsigned int *v90; // rax
  int *v91; // rcx
  int v92; // edx
  UFG::qSymbolUC *v93; // rax
  Render::BeamSettingsHandle *BeamSettingsHandle; // rax
  UFG::qSymbolUC *v95; // rax
  Render::BeamSettingsHandle *v96; // rax
  UFG::qSymbolUC *v97; // rax
  Render::BeamSettingsHandle *v98; // rax
  UFG::qSymbolUC *v99; // rax
  Render::BeamSettingsHandle *v100; // rax
  UFG::qSymbolUC *v101; // rax
  unsigned int v102; // eax
  char *v103; // rax
  char *v104; // rax
  unsigned int v105; // eax
  char *v106; // rax
  char *v107; // rax
  UFG::qSymbol *v108; // rax
  char *v109; // rax
  UFG::qSymbol *v110; // rax
  char *v111; // rax
  UFG::qSymbol *v112; // rax
  UFG::qPropertyList *v113; // rax
  UFG::qPropertyList *v114; // r14
  unsigned int v115; // edi
  char *ValuePtr; // rax
  __int64 v117; // rcx
  UFG::qPropertySet *v118; // rbx
  float *v119; // rax
  UFG::qSymbolUC *v120; // rdx
  float v121; // xmm6_4
  float *v122; // rax
  UFG::qSymbolUC **v123; // rcx
  float v124; // xmm0_4
  float *v125; // rax
  UFG::qSymbolUC beamSettingsSymbol; // [rsp+90h] [rbp+40h] BYREF
  UFG::qSymbolUC *v127; // [rsp+A0h] [rbp+50h] BYREF
  int v128; // [rsp+A8h] [rbp+58h] BYREF

  v4 = UFG::qPropertySet::Get<float>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_FlickTargetingAngularLimit,
         DEPTH_RECURSE);
  if ( v4 )
    this->mFlickTargetingAngularLimitRad = *v4;
  this->mFlickTargetingAngularLimitRad = (float)(this->mFlickTargetingAngularLimitRad * 3.1415927) * 0.0055555557;
  v5 = UFG::qPropertySet::Get<float>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_AccuracyOnTargetChanged,
         DEPTH_RECURSE);
  if ( v5 )
    this->mAccuracyOnTargetChanged = *v5;
  v6 = UFG::qPropertySet::Get<float>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_AccuracyPenaltyPerShot,
         DEPTH_RECURSE);
  if ( v6 )
    this->mAccuracyPenaltyPerShot = *v6;
  v7 = UFG::qPropertySet::Get<float>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_AccuracyRateMultiplier,
         DEPTH_RECURSE);
  if ( v7 )
    this->m_fAccuracyRateMultiplier = *v7;
  v8 = UFG::qPropertySet::Get<long>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_AmmoClipCapacity,
         DEPTH_RECURSE);
  if ( v8 )
    this->mAmmoClipCapacity = *v8;
  v9 = UFG::qPropertySet::Get<long>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_AmmoTotalCapacity,
         DEPTH_RECURSE);
  if ( v9 )
    this->mAmmoTotalCapacity = *v9;
  v10 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_BulletPerShot,
          DEPTH_RECURSE);
  if ( v10 )
    this->mBulletPerShot = *v10;
  v11 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_BulletLifeSpan,
          DEPTH_RECURSE);
  if ( v11 )
    this->mBulletLifeSpan = *v11;
  v12 = UFG::qPropertySet::Get<bool>(properties, (UFG::qArray<unsigned long,0> *)&PhysicsSym_IsAutomatic, DEPTH_RECURSE);
  if ( v12 )
    this->mIsAutomatic = *v12;
  v13 = UFG::qPropertySet::Get<bool>(properties, (UFG::qArray<unsigned long,0> *)&PhysicsSym_Stowable, DEPTH_RECURSE);
  if ( v13 )
    this->mStowable = *v13;
  v14 = UFG::qPropertySet::Get<bool>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_IsTwoHandedWeapon,
          DEPTH_RECURSE);
  if ( v14 )
    this->mIsTwoHandedWeapon = *v14;
  v15 = UFG::qPropertySet::Get<bool>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_HasSniperScope,
          DEPTH_RECURSE);
  if ( v15 )
    this->mHasSniperScope = *v15;
  v16 = UFG::qPropertySet::Get<UFG::qVector3>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_MaxAngularVelocityWhenThrown,
          DEPTH_RECURSE);
  if ( v16 )
  {
    y = v16->y;
    z = v16->z;
    this->mMaxAngularVelocityWhenThrown.x = v16->x;
    this->mMaxAngularVelocityWhenThrown.y = y;
    this->mMaxAngularVelocityWhenThrown.z = z;
  }
  v19 = UFG::qPropertySet::Get<UFG::qVector3>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_MinAngularVelocityWhenThrown,
          DEPTH_RECURSE);
  if ( v19 )
  {
    v20 = v19->y;
    v21 = v19->z;
    this->mMinAngularVelocityWhenThrown.x = v19->x;
    this->mMinAngularVelocityWhenThrown.y = v20;
    this->mMinAngularVelocityWhenThrown.z = v21;
  }
  v22 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ProjectileSpawnBoneID,
          DEPTH_RECURSE);
  if ( v22 )
    this->mProjectileSpawnBoneID = *v22;
  v23 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ProjectilePhysicsImpulse,
          DEPTH_RECURSE);
  if ( v23 )
    this->mProjectilePhysicsImpulse = *v23;
  v24 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RangedDistance,
          DEPTH_RECURSE);
  if ( v24 )
    this->mRangedDistance = *v24;
  v25 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AngularInaccuracyMax,
          DEPTH_RECURSE);
  if ( v25 )
    this->mAngularInaccuracyRadMax = *v25;
  v26 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AngularInaccuracyMin,
          DEPTH_RECURSE);
  if ( v26 )
    this->mAngularInaccuracyRadMin = *v26;
  v27 = UFG::qPropertySet::Get<float>(properties, (UFG::qArray<unsigned long,0> *)&PhysicsSym_RateOfFire, DEPTH_RECURSE);
  if ( v27 )
    this->mRateOfFire = *v27;
  v28 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_HardLockReticleSizeMin,
          DEPTH_RECURSE);
  if ( v28 )
    this->mHardLockReticleSizeMin = *v28;
  v29 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_HardLockReticleSizeMax,
          DEPTH_RECURSE);
  if ( v29 )
    this->mHardLockReticleSizeMax = *v29;
  v30 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ReticleSizeMin,
          DEPTH_RECURSE);
  if ( v30 )
    this->mReticleSizeMin = *v30;
  v31 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ReticleSizeMax,
          DEPTH_RECURSE);
  if ( v31 )
    this->mReticleSizeMax = *v31;
  v32 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ReticleSizeBlindfire,
          DEPTH_RECURSE);
  if ( v32 )
    this->mReticleSizeBlindfire = *v32;
  v33 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ThrownSpeed,
          DEPTH_RECURSE);
  if ( v33 )
    this->mThrownSpeed = *v33;
  v34 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_HardLockDamageMultiplier,
          DEPTH_RECURSE);
  if ( v34 )
    this->mHardLockDamageMultiplier = *v34;
  v35 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_DamageMultiplier,
          DEPTH_RECURSE);
  if ( v35 )
    this->mDamageMultiplier = *v35;
  v36 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_StartingMaxAmmoCount,
          DEPTH_RECURSE);
  if ( v36 )
    this->mStartingMaxAmmoCount = *v36;
  v37 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_StartingMinAmmoCount,
          DEPTH_RECURSE);
  if ( v37 )
    this->mStartingMinAmmoCount = *v37;
  v38 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AIOnDeathDropMaxAmmoCount,
          DEPTH_RECURSE);
  if ( v38 )
    this->mAIOnDeathDropMaxAmmoCount = *v38;
  v39 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AIOnDeathDropMinAmmoCount,
          DEPTH_RECURSE);
  if ( v39 )
    this->mAIOnDeathDropMinAmmoCount = *v39;
  v40 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ProjectileSpeed,
          DEPTH_RECURSE);
  if ( v40 )
    this->mProjectileSpeed = *v40;
  v41 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ProjectileSpeedAI,
          DEPTH_RECURSE);
  if ( v41 )
    this->mProjectileSpeedAI = *v41;
  v42 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ProjectileGravity,
          DEPTH_RECURSE);
  if ( v42 )
    this->mProjectileGravity = *v42;
  v43 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ArmingDistance,
          DEPTH_RECURSE);
  if ( v43 )
    this->mArmingDistance = *v43;
  v44 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_SlowModeRateOfFireMultiplier,
          DEPTH_RECURSE);
  if ( v44 )
    this->mSlowModeRateOfFireMultiplier = *v44;
  v45 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_SlowModeRateOfFireMultiplierAI,
          DEPTH_RECURSE);
  if ( v45 )
    this->mSlowModeRateOfFireMultiplierAI = *v45;
  v46 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_SlowModeProjectileSpeedMultiplier,
          DEPTH_RECURSE);
  if ( v46 )
    this->mSlowModeProjectileSpeedMultiplier = *v46;
  v47 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_SlowModeProjectileSpeedMultiplierAI,
          DEPTH_RECURSE);
  if ( v47 )
    this->mSlowModeProjectileSpeedMultiplierAI = *v47;
  v48 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_SlowModeProjectileDamageMultiplier,
          DEPTH_RECURSE);
  if ( v48 )
    this->mSlowModeProjectileDamageMultiplier = *v48;
  v49 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_SlowModeProjectileDamageMultiplierAI,
          DEPTH_RECURSE);
  if ( v49 )
    this->mSlowModeProjectileDamageMultiplierAI = *v49;
  v50 = UFG::qPropertySet::Get<float>(properties, (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimYawPerS, DEPTH_RECURSE);
  if ( v50 )
    this->mAimYawPerSRad = *v50;
  v51 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimPitchPerS,
          DEPTH_RECURSE);
  if ( v51 )
    this->mAimPitchPerSRad = *v51;
  v52 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimMaxInputSpeedPerS,
          DEPTH_RECURSE);
  if ( v52 )
    this->mAimMaxInputSpeedPerS = *v52;
  v53 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimFlickTransitionDegPerS,
          DEPTH_RECURSE);
  if ( v53 )
    this->mAimFlickTransitionRadPerS = *v53;
  v54 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimSubtargetTransitionDegPerS,
          DEPTH_RECURSE);
  if ( v54 )
    this->mAimSubtargetTransitionRadPerS = *v54;
  v55 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimFreeAimTransitionDegPerS,
          DEPTH_RECURSE);
  if ( v55 )
    this->mAimFreeAimTransitionRadPerS = *v55;
  v56 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimFovOffset,
          DEPTH_RECURSE);
  if ( v56 )
    this->mAimFovOffset = *v56;
  v57 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RecoilKickupMin,
          DEPTH_RECURSE);
  if ( v57 )
    this->mRecoilKickupMin = *v57;
  v58 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RecoilKickupMax,
          DEPTH_RECURSE);
  if ( v58 )
    this->mRecoilKickupMax = *v58;
  v59 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RecoilKickupOffset,
          DEPTH_RECURSE);
  if ( v59 )
    this->mRecoilKickupOffset = *v59;
  v60 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RecoilKickupRateAttack,
          DEPTH_RECURSE);
  if ( v60 )
    this->mRecoilKickupRateAttack = *v60;
  v61 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RecoilKickupRateDecay,
          DEPTH_RECURSE);
  if ( v61 )
    this->mRecoilKickupRateDecay = *v61;
  v62 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RecoilKickback,
          DEPTH_RECURSE);
  if ( v62 )
    this->mRecoilKickback = *v62;
  v63 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RecoilKickbackSpeed,
          DEPTH_RECURSE);
  if ( v63 )
    this->mRecoilKickbackSpeed = *v63;
  v64 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_RecoilKickbackDur,
          DEPTH_RECURSE);
  if ( v64 )
    this->mRecoilKickbackDur = *v64;
  v65 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_MinDesiredDistance,
          DEPTH_RECURSE);
  if ( v65 )
    this->mMinDesiredDistance = *v65;
  v66 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_MaxDisiredDistance,
          DEPTH_RECURSE);
  if ( v66 )
    this->mMaxDisiredDistance = *v66;
  v67 = UFG::qPropertySet::Get<float>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_DesiredDistance,
          DEPTH_RECURSE);
  if ( v67 )
    this->mDesiredDistance = *v67;
  v68 = UFG::qPropertySet::Get<UFG::qVector3>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimOriginOffset,
          DEPTH_RECURSE);
  if ( v68 )
  {
    v69 = v68->y;
    v70 = v68->z;
    this->mAimOriginOffset.x = v68->x;
    this->mAimOriginOffset.y = v69;
    this->mAimOriginOffset.z = v70;
  }
  v71 = UFG::qPropertySet::Get<UFG::qVector3>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_ThrownWeaponSpinAxis,
          DEPTH_RECURSE);
  if ( v71 )
  {
    v72 = v71->y;
    v73 = v71->z;
    this->mThrownWeaponSpinAxis.x = v71->x;
    this->mThrownWeaponSpinAxis.y = v72;
    this->mThrownWeaponSpinAxis.z = v73;
  }
  this->mAngularInaccuracyRadMin = (float)(this->mAngularInaccuracyRadMin * 3.1415927) * 0.0055555557;
  this->mAngularInaccuracyRadMax = (float)(this->mAngularInaccuracyRadMax * 3.1415927) * 0.0055555557;
  this->mAimYawPerSRad = (float)(this->mAimYawPerSRad * 3.1415927) * 0.0055555557;
  this->mAimPitchPerSRad = (float)(this->mAimPitchPerSRad * 3.1415927) * 0.0055555557;
  this->mAimFlickTransitionRadPerS = (float)(this->mAimFlickTransitionRadPerS * 3.1415927) * 0.0055555557;
  this->mAimSubtargetTransitionRadPerS = (float)(this->mAimSubtargetTransitionRadPerS * 3.1415927) * 0.0055555557;
  this->mAimFreeAimTransitionRadPerS = (float)(this->mAimFreeAimTransitionRadPerS * 3.1415927) * 0.0055555557;
  p = this->mSoundbankIds.p;
  v75 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
          properties,
          (UFG::qArray<unsigned long,0> *)&TiDoSym_SoundBank,
          DEPTH_RECURSE);
  v76 = 0;
  if ( v75 )
  {
    UFG::qWiseSymbol::operator=(p, v75);
  }
  else
  {
    v77 = UFG::qPropertySet::Get<UFG::qPropertyList>(
            properties,
            (UFG::qArray<unsigned long,0> *)&TiDoSym_SoundbankList,
            DEPTH_RECURSE);
    v78 = v77;
    if ( v77 )
    {
      mNumElements = v77->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        v81 = UFG::qPropertyList::Get<UFG::qWiseSymbol>(v78, i);
        if ( v81 )
          UFG::qWiseSymbol::operator=(&this->mSoundbankIds.p[i], v81);
      }
    }
  }
  v82 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(
          properties,
          (UFG::qArray<unsigned long,0> *)&qSymbol_AudioWeaponType,
          DEPTH_RECURSE);
  if ( v82 )
    UFG::qWiseSymbol::operator=(&this->mAudioWeaponType, v82);
  v83 = UFG::qPropertySet::Get<bool>(
          properties,
          (UFG::qArray<unsigned long,0> *)&qSymbol_AudioWeaponIsLooping,
          DEPTH_RECURSE);
  if ( v83 )
    this->mAudioWeaponIsLooping = *v83;
  beamSettingsSymbol.mUID = 0;
  LODWORD(v127) = 0;
  v128 = 0;
  v84 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_Damage,
          DEPTH_RECURSE);
  p_beamSettingsSymbol = &beamSettingsSymbol;
  if ( v84 )
    p_beamSettingsSymbol = (UFG::qSymbolUC *)v84;
  mUID = p_beamSettingsSymbol->mUID;
  v87 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_PropDamage,
          DEPTH_RECURSE);
  v88 = &v127;
  if ( v87 )
    v88 = (UFG::qSymbolUC **)v87;
  v89 = *(_DWORD *)v88;
  v90 = UFG::qPropertySet::Get<unsigned long>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_VehicleDamage,
          DEPTH_RECURSE);
  v91 = &v128;
  if ( v90 )
    v91 = (int *)v90;
  v92 = *v91;
  this->mDamage = (float)mUID * 0.0099999998;
  this->mPropDamage = (float)v89 * 0.0099999998;
  this->mVehicleDamage = (float)v92 * 0.0099999998;
  v93 = UFG::qPropertySet::Get<UFG::qSymbolUC>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_Tracer,
          DEPTH_RECURSE);
  if ( v93 )
  {
    v127 = &beamSettingsSymbol;
    beamSettingsSymbol.mUID = v93->mUID;
    BeamSettingsHandle = UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager::mInstance, &beamSettingsSymbol);
  }
  else
  {
    BeamSettingsHandle = 0i64;
  }
  this->mTracerBeamSettingsHandle = BeamSettingsHandle;
  v95 = UFG::qPropertySet::Get<UFG::qSymbolUC>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_TracerAI,
          DEPTH_RECURSE);
  if ( v95 )
  {
    v127 = &beamSettingsSymbol;
    beamSettingsSymbol.mUID = v95->mUID;
    v96 = UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager::mInstance, &beamSettingsSymbol);
  }
  else
  {
    v96 = 0i64;
  }
  this->mTracerBeamAISettingsHandle = v96;
  v97 = UFG::qPropertySet::Get<UFG::qSymbolUC>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_TracerTrail,
          DEPTH_RECURSE);
  if ( v97 )
  {
    v127 = &beamSettingsSymbol;
    beamSettingsSymbol.mUID = v97->mUID;
    v98 = UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager::mInstance, &beamSettingsSymbol);
  }
  else
  {
    v98 = 0i64;
  }
  this->mTracerBeamTrailSettingsHandle = v98;
  v99 = UFG::qPropertySet::Get<UFG::qSymbolUC>(
          properties,
          (UFG::qArray<unsigned long,0> *)&PhysicsSym_TracerTrailAI,
          DEPTH_RECURSE);
  if ( v99 )
  {
    v127 = &beamSettingsSymbol;
    beamSettingsSymbol.mUID = v99->mUID;
    v100 = UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager::mInstance, &beamSettingsSymbol);
  }
  else
  {
    v100 = 0i64;
  }
  this->mTracerBeamTrailAISettingsHandle = v100;
  v101 = UFG::qPropertySet::Get<UFG::qSymbolUC>(
           properties,
           (UFG::qArray<unsigned long,0> *)&PhysicsSym_BulletType,
           DEPTH_RECURSE);
  if ( v101 )
    v102 = v101->mUID;
  else
    v102 = UFG::qStringHashUpper32("Bullet", -1);
  this->mBulletTypeID = v102;
  v103 = UFG::qPropertySet::Get<char const *>(
           properties,
           (UFG::qArray<unsigned long,0> *)&PhysicsSym_ProjectileSpawnBoneName,
           DEPTH_RECURSE);
  this->mProjectileSpawnBoneName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&beamSettingsSymbol, v103)->mUID;
  v104 = UFG::qPropertySet::Get<char const *>(
           properties,
           (UFG::qArray<unsigned long,0> *)&PhysicsSym_BulletEffectID,
           DEPTH_RECURSE);
  if ( v104 )
    v105 = UFG::qStringHashUpper32(v104, -1);
  else
    v105 = 0;
  this->mBulletEffectID = v105;
  v106 = UFG::qPropertySet::Get<char const *>(
           properties,
           (UFG::qArray<unsigned long,0> *)&PhysicsSym_ExplosionType,
           DEPTH_RECURSE);
  if ( v106 )
    this->mExplosionType = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&beamSettingsSymbol, v106)->mUID;
  v107 = UFG::qPropertySet::Get<char const *>(
           properties,
           (UFG::qArray<unsigned long,0> *)&PhysicsSym_AmmoInventoryItem,
           DEPTH_RECURSE);
  if ( v107 )
  {
    v108 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&beamSettingsSymbol, v107);
    this->mAmmoInventoryItem = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gInventoryItemTracksEnum, v108);
  }
  v109 = UFG::qPropertySet::Get<char const *>(
           properties,
           (UFG::qArray<unsigned long,0> *)&PhysicsSym_ProjectileReaction,
           DEPTH_RECURSE);
  if ( v109 )
  {
    v110 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&beamSettingsSymbol, v109);
    this->mProjectileReaction = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gProjectileReactionEnum, v110);
  }
  v111 = UFG::qPropertySet::Get<char const *>(
           properties,
           (UFG::qArray<unsigned long,0> *)&qSymbol_simObjectWeaponType,
           DEPTH_RECURSE);
  if ( v111 )
  {
    v112 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&beamSettingsSymbol, v111);
    this->mSimObjectWeaponType = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gSimObjectWeaponTypeTrackEnum, v112);
  }
  v113 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           properties,
           (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimInputMapping,
           DEPTH_RECURSE);
  v114 = v113;
  if ( v113 )
  {
    v115 = v113->mNumElements;
    if ( v115 )
    {
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v114, 0x1Au, v76);
        if ( ValuePtr )
        {
          v117 = *(_QWORD *)ValuePtr;
          if ( *(_QWORD *)ValuePtr )
          {
            v118 = (UFG::qPropertySet *)&ValuePtr[v117];
            if ( &ValuePtr[v117] )
            {
              beamSettingsSymbol.mUID = 0;
              LODWORD(v127) = 0;
              v119 = UFG::qPropertySet::Get<float>(
                       (UFG::qPropertySet *)&ValuePtr[v117],
                       (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimInput,
                       DEPTH_RECURSE);
              v120 = &beamSettingsSymbol;
              if ( v119 )
                v120 = (UFG::qSymbolUC *)v119;
              v121 = *(float *)&v120->mUID;
              v122 = UFG::qPropertySet::Get<float>(
                       v118,
                       (UFG::qArray<unsigned long,0> *)&PhysicsSym_AimOutput,
                       DEPTH_RECURSE);
              v123 = &v127;
              if ( v122 )
                v123 = (UFG::qSymbolUC **)v122;
              v124 = *(float *)v123;
              this->mAimInputMappingInput.p[this->mAimInputMappingInput.size++] = v121;
              this->mAimInputMappingOutput.p[this->mAimInputMappingOutput.size++] = v124;
            }
          }
        }
        ++v76;
      }
      while ( v76 < v115 );
    }
    this->mAimInputMapping.nData = v115;
    this->mAimInputMapping.fDomain = this->mAimInputMappingInput.p;
    v125 = this->mAimInputMappingOutput.p;
  }
  else
  {
    this->mAimInputMapping.nData = 2;
    this->mAimInputMapping.fDomain = input_domain;
    v125 = (float *)input_domain;
  }
  this->mAimInputMapping.tRange = v125;
}

// File Line: 273
// RVA: 0x538D10
void __fastcall UFG::WeaponTypeInfo::InitFromPropertySet(UFG::WeaponTypeInfo *this, UFG::qPropertySet *properties)
{
  UFG::FireModeInfo *v4; // rbx
  unsigned int v5; // edi
  char *v6; // r14
  void *v7; // rbp
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rbp
  unsigned int mNumElements; // ecx
  unsigned int i; // edi
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rcx
  char *v15; // r14
  char *ValuePtr; // rax
  UFG::qPropertySet *v17; // rdx
  UFG::allocator::free_link *v18; // rax
  UFG::FireModeInfo *v19; // rax

  v4 = 0i64;
  if ( this->mNumFireModes )
  {
    v5 = 0;
    do
    {
      v6 = (char *)this + 8 * v5;
      v7 = (void *)*((_QWORD *)v6 + 1);
      if ( v7 )
      {
        UFG::FireModeInfo::~FireModeInfo(*((UFG::FireModeInfo **)v6 + 1));
        operator delete[](v7);
      }
      *((_QWORD *)v6 + 1) = 0i64;
      ++v5;
    }
    while ( v5 < this->mNumFireModes );
    this->mNumFireModes = 0;
  }
  this->mPropertySetSymbol.mUID = properties->mName.mUID;
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         properties,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_FireModes,
         DEPTH_RECURSE);
  v9 = v8;
  if ( v8 )
  {
    mNumElements = v8->mNumElements;
    this->mNumFireModes = mNumElements;
    for ( i = 0; i < this->mNumFireModes; ++i )
    {
      v12 = UFG::qMalloc(0x1E8ui64, "FireModeInfo", 0i64);
      if ( v12 )
      {
        UFG::FireModeInfo::FireModeInfo((UFG::FireModeInfo *)v12);
        v14 = v13;
      }
      else
      {
        v14 = 0i64;
      }
      v15 = (char *)this + 8 * i;
      *((_QWORD *)v15 + 1) = v14;
      ValuePtr = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, i);
      if ( !ValuePtr || (v17 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
        v17 = 0i64;
      UFG::FireModeInfo::InitFromPropertySet(*((UFG::FireModeInfo **)v15 + 1), v17);
    }
  }
  else
  {
    this->mNumFireModes = 1;
    v18 = UFG::qMalloc(0x1E8ui64, "FireModeInfo", 0i64);
    if ( v18 )
    {
      UFG::FireModeInfo::FireModeInfo((UFG::FireModeInfo *)v18);
      v4 = v19;
    }
    this->mFireModes[0] = v4;
    UFG::FireModeInfo::InitFromPropertySet(v4, properties);
  }
}

// File Line: 336
// RVA: 0x1544080
__int64 dynamic_initializer_for__UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList__);
}

// File Line: 337
// RVA: 0x52CB20
UFG::ComponentIDDesc *__fastcall UFG::SimObjectWeaponPropertiesComponent::GetDesc(
        UFG::SimObjectWeaponPropertiesComponent *this)
{
  return &UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc;
}

// File Line: 338
// RVA: 0x1543CE0
__int64 dynamic_initializer_for__UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos__()
{
  `eh vector constructor iterator(
    (char *)UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos,
    0x18ui64,
    120,
    (void (__fastcall *)(void *))UFG::WeaponTypeInfo::WeaponTypeInfo);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos__);
}

// File Line: 341
// RVA: 0x154C7E0
__int64 UFG::_dynamic_initializer_for__sSymbolArchetypes__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("archetypes", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolArchetypes, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSymbolArchetypes__);
}

// File Line: 342
// RVA: 0x154C960
__int64 UFG::_dynamic_initializer_for__sSymbolSubfolders__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("subfolders", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolSubfolders, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSymbolSubfolders__);
}

// File Line: 343
// RVA: 0x154C8E0
__int64 UFG::_dynamic_initializer_for__sSymbolPhysical__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("physical", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolPhysical, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSymbolPhysical__);
}

// File Line: 344
// RVA: 0x154C9A0
__int64 UFG::_dynamic_initializer_for__sSymbolWeapon__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("weapon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolWeapon, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSymbolWeapon__);
}

// File Line: 345
// RVA: 0x154C920
__int64 UFG::_dynamic_initializer_for__sSymbolProp__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("prop", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolProp, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSymbolProp__);
}

// File Line: 346
// RVA: 0x154C820
__int64 UFG::_dynamic_initializer_for__sSymbolFirearm__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("firearm", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolFirearm, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSymbolFirearm__);
}

// File Line: 347
// RVA: 0x154C8A0
__int64 UFG::_dynamic_initializer_for__sSymbolMelee__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("melee", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolMelee, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSymbolMelee__);
}

// File Line: 353
// RVA: 0x5214B0
void __fastcall UFG::SimObjectWeaponPropertiesComponent::AddWeaponTypeInfosForPropertySet(
        UFG::qPropertySet *pPropertySet)
{
  UFG::qPropertyList *v1; // rax
  unsigned int v2; // ebx
  UFG::qPropertyList *v3; // rbp
  unsigned int mNumElements; // esi
  unsigned int i; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v7; // rcx
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rbp
  unsigned int v10; // edi
  UFG::qSymbol *v11; // rax
  UFG::qPropertySet *PropertySet; // rsi
  UFG::qPropertySet *v13; // rax

  v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         pPropertySet,
         (UFG::qArray<unsigned long,0> *)&sSymbolSubfolders,
         DEPTH_RECURSE);
  v2 = 0;
  v3 = v1;
  if ( v1 )
  {
    mNumElements = v1->mNumElements;
    for ( i = 0; i < mNumElements; ++i )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v3, 0x1Au, i);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v7 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v7 = 0i64;
      UFG::SimObjectWeaponPropertiesComponent::AddWeaponTypeInfosForPropertySet(v7);
    }
  }
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         pPropertySet,
         (UFG::qArray<unsigned long,0> *)&sSymbolArchetypes,
         DEPTH_RECURSE);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8->mNumElements;
    if ( v10 )
    {
      do
      {
        v11 = UFG::qPropertyList::Get<UFG::qSymbol>(v9, v2);
        PropertySet = UFG::PropertySetManager::GetPropertySet(v11);
        v13 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                PropertySet,
                (UFG::qArray<unsigned long,0> *)&component_WeaponProperties::sPropertyName,
                DEPTH_RECURSE);
        if ( v13
          && UFG::qPropertySet::GetMemImagePtr(v13)
          && UFG::SimObjectWeaponPropertiesComponent::sNumWeaponTypeInfos < 0x78 )
        {
          UFG::WeaponTypeInfo::InitFromPropertySet(
            &UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos[UFG::SimObjectWeaponPropertiesComponent::sNumWeaponTypeInfos],
            PropertySet);
          ++UFG::SimObjectWeaponPropertiesComponent::sNumWeaponTypeInfos;
        }
        ++v2;
      }
      while ( v2 < v10 );
    }
  }
}

// File Line: 415
// RVA: 0x5500F0
void UFG::SimObjectWeaponPropertiesComponent::StaticInit(void)
{
  UFG::qSymbol *v0; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v2; // rcx
  UFG::qPropertySet *v3; // rbx
  UFG::qPropertyList *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::qPropertyList *v6; // rcx
  UFG::qPropertySet *v7; // rbx
  UFG::qPropertyList *v8; // rcx
  UFG::qPropertySet *v9; // rdi
  UFG::qPropertyList *v10; // rcx
  UFG::qPropertySet *v11; // rbx
  UFG::qSymbol symbol; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+58h] [rbp+10h] BYREF
  UFG::qSymbol *p_symbol; // [rsp+60h] [rbp+18h] BYREF
  UFG::qSymbol **p_p_symbol; // [rsp+68h] [rbp+20h]

  v0 = UFG::qSymbol::create_from_string(&result, "object-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v0);
  p_symbol = &symbol;
  symbol.mUID = sSymbolPhysical.mUID;
  v2 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&sSymbolSubfolders,
         DEPTH_RECURSE);
  v3 = UFG::FindInList(v2, &symbol);
  p_symbol = &result;
  result.mUID = sSymbolProp.mUID;
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qArray<unsigned long,0> *)&sSymbolSubfolders, DEPTH_RECURSE);
  v5 = UFG::FindInList(v4, &result);
  UFG::SimObjectWeaponPropertiesComponent::AddWeaponTypeInfosForPropertySet(v5);
  p_symbol = &result;
  result.mUID = sSymbolWeapon.mUID;
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qArray<unsigned long,0> *)&sSymbolSubfolders, DEPTH_RECURSE);
  v7 = UFG::FindInList(v6, &result);
  p_symbol = &symbol;
  symbol.mUID = sSymbolFirearm.mUID;
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v7, (UFG::qArray<unsigned long,0> *)&sSymbolSubfolders, DEPTH_RECURSE);
  v9 = UFG::FindInList(v8, &symbol);
  p_p_symbol = &p_symbol;
  LODWORD(p_symbol) = sSymbolMelee;
  v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v7,
          (UFG::qArray<unsigned long,0> *)&sSymbolSubfolders,
          DEPTH_RECURSE);
  v11 = UFG::FindInList(v10, &p_symbol);
  UFG::SimObjectWeaponPropertiesComponent::AddWeaponTypeInfosForPropertySet(v9);
  UFG::SimObjectWeaponPropertiesComponent::AddWeaponTypeInfosForPropertySet(v11);
}

// File Line: 432
// RVA: 0x154C860
__int64 UFG::_dynamic_initializer_for__sSymbolMagazineType__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MagazineType", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolMagazineType, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSymbolMagazineType__);
}

// File Line: 433
// RVA: 0x154C740
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_IsRealWeapon__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IsRealWeapon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsRealWeapon, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_IsRealWeapon__);
}

// File Line: 434
// RVA: 0x154C700
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_IsPhoneCamera__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IsPhoneCamera", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsPhoneCamera, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_IsPhoneCamera__);
}

// File Line: 435
// RVA: 0x154C6C0
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_IsBladed__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IsBladed", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsBladed, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_IsBladed__);
}

// File Line: 436
// RVA: 0x154C680
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_HudReticle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("HudReticle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_HudReticle, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_HudReticle__);
}

// File Line: 437
// RVA: 0x154C780
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_NetWorkedFireStateNode__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NetWorkedFireStateNode", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_NetWorkedFireStateNode, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_NetWorkedFireStateNode__);
}

// File Line: 452
// RVA: 0x519280
void __fastcall UFG::SimObjectWeaponPropertiesComponent::SimObjectWeaponPropertiesComponent(
        UFG::SimObjectWeaponPropertiesComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        component_WeaponProperties *data_ptr)
{
  ActionPath *p_mNetWorkedFireStateNode; // rdi
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *mPrev; // rax
  UFG::qResourceData *ParentFromIdx; // rax
  int v9; // eax
  unsigned int v10; // ecx
  UFG::WeaponTypeInfo *v11; // rdx
  UFG::qSymbol *v12; // rax
  bool *v13; // rax
  bool *p_mIsRealWeapon; // rcx
  bool *v15; // rax
  bool *p_mIsPhoneCamera; // rcx
  bool *p_mIsBladed; // rax
  UFG::qSymbol *v18; // rax
  unsigned int *p_mUID; // r14
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v20; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v21; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  char *v23; // rsi
  __int64 mOffset; // rcx
  char *v25; // rcx
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF

  UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(this, name_uid, data_ptr);
  this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>::mPrev = &this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>;
  this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>::mNext = &this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectWeaponPropertiesComponent::`vftable;
  *(_QWORD *)&this->mLastOwner = 0i64;
  this->mWeaponTypeInfo = 0i64;
  *(_QWORD *)&this->mUnloadTimeOut = 0i64;
  this->mLastBulletImpactStimulusTimer = 0.0;
  this->mAccessoriesPreloaded = 0;
  this->mMagazineType = UFG::gNullQSymbol;
  *(_WORD *)&this->mIsRealWeapon = 0;
  this->mHudReticule = 0;
  p_mNetWorkedFireStateNode = &this->mNetWorkedFireStateNode;
  this->mNetWorkedFireStateNode.mPath.mCount = 0;
  this->mNetWorkedFireStateNode.mPath.mData.mOffset = 0i64;
  mPrev = UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mPrev;
  UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>;
  this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>::mNext = (UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList;
  UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mPrev = &this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::SimObjectWeaponPropertiesComponent::_SimObjectWeaponPropertiesComponentTypeUID,
    "SimObjectWeaponPropertiesComponent");
  if ( properties )
  {
    if ( (unsigned int)UFG::qPropertySet::NumParents(properties) )
      ParentFromIdx = UFG::qPropertySet::GetParentFromIdx(properties, 0);
    else
      ParentFromIdx = (UFG::qResourceData *)properties;
    v9 = *(_DWORD *)&ParentFromIdx->mDebugName[12];
    v10 = 0;
    v11 = UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos;
    while ( v11->mPropertySetSymbol.mUID != v9 )
    {
      ++v10;
      ++v11;
      if ( v10 >= 0x78 )
        goto LABEL_10;
    }
    this->mWeaponTypeInfo = &UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos[v10];
LABEL_10:
    v12 = UFG::qPropertySet::Get<UFG::qSymbol>(
            properties,
            (UFG::qArray<unsigned long,0> *)&sSymbolMagazineType,
            DEPTH_RECURSE);
    if ( v12 )
      this->mMagazineType = (UFG::qSymbol)v12->mUID;
    v13 = UFG::qPropertySet::Get<bool>(
            properties,
            (UFG::qArray<unsigned long,0> *)&sSimObjectWeaponPropertiesComponentSymbol_IsRealWeapon,
            DEPTH_RECURSE);
    p_mIsRealWeapon = &this->mIsRealWeapon;
    if ( v13 )
      p_mIsRealWeapon = v13;
    this->mIsRealWeapon = *p_mIsRealWeapon;
    v15 = UFG::qPropertySet::Get<bool>(
            properties,
            (UFG::qArray<unsigned long,0> *)&sSimObjectWeaponPropertiesComponentSymbol_IsPhoneCamera,
            DEPTH_RECURSE);
    p_mIsPhoneCamera = &this->mIsPhoneCamera;
    if ( v15 )
      p_mIsPhoneCamera = v15;
    this->mIsPhoneCamera = *p_mIsPhoneCamera;
    p_mIsBladed = UFG::qPropertySet::Get<bool>(
                    properties,
                    (UFG::qArray<unsigned long,0> *)&sSimObjectWeaponPropertiesComponentSymbol_IsBladed,
                    DEPTH_RECURSE);
    if ( !p_mIsBladed )
      p_mIsBladed = &this->mIsBladed;
    this->mIsBladed = *p_mIsBladed;
    v18 = UFG::qPropertySet::Get<UFG::qSymbol>(
            properties,
            (UFG::qArray<unsigned long,0> *)&sSimObjectWeaponPropertiesComponentSymbol_HudReticle,
            DEPTH_RECURSE);
    p_mUID = &v18->mUID;
    if ( v18 )
    {
      UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v18);
      pTrackEnumBinding.mPrev = &pTrackEnumBinding;
      pTrackEnumBinding.mNext = &pTrackEnumBinding;
      pTrackEnumBinding.m_EnumSymbol.mUID = -1;
      pTrackEnumBinding.m_EnumSymbol.mUID = *p_mUID;
      *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
      pTrackEnumBinding.m_uEnumUID = 0;
      if ( UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size )
      {
        TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectWeaponReticleTracksEnum, &pTrackEnumBinding);
      }
      else
      {
        v20 = UFG::gSimObjectWeaponReticleTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
        UFG::gSimObjectWeaponReticleTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
        pTrackEnumBinding.mPrev = v20;
        pTrackEnumBinding.mNext = &UFG::gSimObjectWeaponReticleTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
        UFG::gSimObjectWeaponReticleTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
      }
      this->mHudReticule = pTrackEnumBinding.m_EnumValue;
      v21 = pTrackEnumBinding.mPrev;
      mNext = pTrackEnumBinding.mNext;
      pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
      mNext->mPrev = v21;
      pTrackEnumBinding.mPrev = &pTrackEnumBinding;
      pTrackEnumBinding.mNext = &pTrackEnumBinding;
    }
    v23 = UFG::qPropertySet::Get<char const *>(
            properties,
            (UFG::qArray<unsigned long,0> *)&sSimObjectWeaponPropertiesComponentSymbol_NetWorkedFireStateNode,
            DEPTH_RECURSE);
    if ( v23 )
    {
      if ( p_mNetWorkedFireStateNode->mPath.mCount >= 0 )
      {
        mOffset = this->mNetWorkedFireStateNode.mPath.mData.mOffset;
        if ( mOffset )
        {
          v25 = (char *)&p_mNetWorkedFireStateNode->mPath.mData + mOffset;
          if ( v25 )
            operator delete[](v25);
        }
        this->mNetWorkedFireStateNode.mPath.mData.mOffset = 0i64;
        p_mNetWorkedFireStateNode->mPath.mCount &= 0x80000000;
      }
      ActionPath::Append(&this->mNetWorkedFireStateNode, v23);
    }
  }
}

// File Line: 504
// RVA: 0x51C920
void __fastcall UFG::SimObjectWeaponPropertiesComponent::~SimObjectWeaponPropertiesComponent(
        UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v2; // rsi
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *mPrev; // rcx
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *mNext; // rax
  UFG::qPropertySet *PropertySet; // rbx
  UFG::ObjectResourceManager *v6; // rax
  unsigned int mSoundBankLoadedId; // edx
  __int64 i; // rbx
  ActionPath *p_mNetWorkedFireStateNode; // rbx
  __int64 mOffset; // rax
  __int64 v11; // rax
  char *v12; // rcx
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v13; // rcx
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v14; // rax
  ActionPath *result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectWeaponPropertiesComponent::`vftable;
  if ( this == UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentpCurrentIterator )
    UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentpCurrentIterator = (UFG::SimObjectWeaponPropertiesComponent *)&this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>::mPrev[-10].mNext;
  v2 = &this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>;
  mPrev = this->UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( this->mAccessoriesPreloaded )
  {
    this->mAccessoriesPreloaded = 0;
    if ( this->mMagazineType.mUID != UFG::gNullQSymbol.mUID )
    {
      PropertySet = UFG::PropertySetManager::FindPropertySet(&this->mMagazineType);
      v6 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::ReleaseCriticalResource(v6, PropertySet);
    }
  }
  mSoundBankLoadedId = this->mSoundBankLoadedId;
  if ( mSoundBankLoadedId )
  {
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, mSoundBankLoadedId);
    for ( i = 0i64;
          (unsigned int)i < this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mSoundbankIds.size;
          i = (unsigned int)(i + 1) )
    {
      UFG::TiDo::UnloadWwiseBank(&this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mSoundbankIds.p[i]);
    }
    this->mSoundBankLoadedId = 0;
    _((AMD_HD3D *)(unsigned int)result);
  }
  p_mNetWorkedFireStateNode = &this->mNetWorkedFireStateNode;
  result = &this->mNetWorkedFireStateNode;
  if ( this->mNetWorkedFireStateNode.mPath.mCount >= 0 )
  {
    mOffset = this->mNetWorkedFireStateNode.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_mNetWorkedFireStateNode->mPath.mData + mOffset) )
    {
      v11 = this->mNetWorkedFireStateNode.mPath.mData.mOffset;
      if ( v11 )
        v12 = (char *)&this->mNetWorkedFireStateNode.mPath.mData + v11;
      else
        v12 = 0i64;
      operator delete[](v12);
    }
    this->mNetWorkedFireStateNode.mPath.mData.mOffset = 0i64;
    p_mNetWorkedFireStateNode->mPath.mCount &= 0x80000000;
  }
  v13 = v2->mPrev;
  v14 = v2->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimObjectPropertiesComponent::~SimObjectPropertiesComponent(this);
}

// File Line: 527
// RVA: 0x546F90
UFG::SimObjectWeaponPropertiesComponent *__fastcall UFG::SimObjectWeaponPropertiesComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *mpConstProperties; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_WeaponProperties::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE8ui64, "SimObjectWeaponPropertiesComponent", 0i64, 1u);
  if ( v10 )
  {
    mpConstProperties = pSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSceneObj->mpConstProperties;
    UFG::SimObjectWeaponPropertiesComponent::SimObjectWeaponPropertiesComponent(
      (UFG::SimObjectWeaponPropertiesComponent *)v10,
      pSceneObj->m_NameUID,
      mpConstProperties,
      (component_WeaponProperties *)MemImagePtr);
    v6 = v12;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) == 0 )
    v15 = -1;
  else
    v15 = 4;
  UFG::SimObjectModifier::SimObjectModifier(&v16, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return (UFG::SimObjectWeaponPropertiesComponent *)v6;
}

// File Line: 543
// RVA: 0x542E50
void __fastcall UFG::SimObjectWeaponPropertiesComponent::PreloadAccessories(
        UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::qSymbol *p_mMagazineType; // rcx
  UFG::qPropertySet *PropertySet; // rbx
  UFG::ObjectResourceManager *v3; // rax

  this->mAccessoriesPreloaded = 1;
  p_mMagazineType = &this->mMagazineType;
  if ( p_mMagazineType->mUID != UFG::gNullQSymbol.mUID )
  {
    PropertySet = UFG::PropertySetManager::FindPropertySet(p_mMagazineType);
    v3 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::PreLoadCriticalResource(v3, PropertySet);
  }
}

// File Line: 557
// RVA: 0x558600
void __fastcall UFG::SimObjectWeaponPropertiesComponent::UnloadAccessories(
        UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::qSymbol *p_mMagazineType; // rcx
  UFG::qPropertySet *PropertySet; // rbx
  UFG::ObjectResourceManager *v3; // rax

  this->mAccessoriesPreloaded = 0;
  p_mMagazineType = &this->mMagazineType;
  if ( p_mMagazineType->mUID != UFG::gNullQSymbol.mUID )
  {
    PropertySet = UFG::PropertySetManager::FindPropertySet(p_mMagazineType);
    v3 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::ReleaseCriticalResource(v3, PropertySet);
  }
}

// File Line: 571
// RVA: 0x53E8E0
void __fastcall UFG::SimObjectWeaponPropertiesComponent::OnAttach(
        UFG::SimObjectWeaponPropertiesComponent *this,
        UFG::SimObject *pObject)
{
  UFG::WeaponManager *v3; // rax

  UFG::SimObjectPropertiesComponent::OnAttach(this, pObject);
  this->mLastOwner = 0;
  v3 = UFG::WeaponManager::Instance();
  UFG::WeaponManager::AddWeapon(v3, (UFG::SimObject *)this);
}

// File Line: 584
// RVA: 0x55C5A0
void __fastcall UFG::SimObjectWeaponPropertiesComponent::Update(
        UFG::SimObjectWeaponPropertiesComponent *this,
        float delta_sec)
{
  char v3; // bp
  char v4; // di
  char IsOwned; // r15
  bool v7; // r12
  char v8; // al
  UFG::SimObject *m_pSimObject; // rsi
  bool v10; // r14
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float y; // xmm1_4
  float z; // xmm2_4
  float v14; // xmm0_4
  bool v15; // si
  unsigned int i; // edi
  unsigned int j; // edi
  UFG::qVector3 v18; // [rsp+20h] [rbp-38h] BYREF

  v3 = 0;
  v4 = 0;
  this->mLastBulletImpactStimulusTimer = delta_sec + this->mLastBulletImpactStimulusTimer;
  IsOwned = UFG::SimObjectWeaponPropertiesComponent::IsOwned(this);
  v7 = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID;
  v8 = ((__int64 (*)(void))UFG::TiDo::m_pInstance->vfptr->HighSpeedMode)();
  m_pSimObject = this->m_pSimObject;
  v10 = v8 == 0;
  if ( m_pSimObject )
  {
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      if ( (UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent),
            y = m_pTransformNodeComponent->mWorldTransform.v3.y,
            z = m_pTransformNodeComponent->mWorldTransform.v3.z,
            v18.x = m_pTransformNodeComponent->mWorldTransform.v3.x,
            v18.y = y,
            v18.z = z,
            v14 = UFG::TiDo::Distance2FromListener(UFG::TiDo::m_pInstance, 0, &v18),
            this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID)
        && v14 < 8100.0
        || v14 < 100.0 )
      {
        v4 = 0;
        v3 = 1;
        if ( v14 < 100.0 )
          v4 = 1;
      }
    }
  }
  v15 = (IsOwned && v3 || v4) && (!v7 || v10);
  if ( this->mUnloadTimeOut < 3.0 )
  {
    if ( this->mSoundBankLoadedId )
      goto LABEL_29;
  }
  else if ( this->mSoundBankLoadedId )
  {
    if ( this->mAccessoriesPreloaded )
      UFG::SimObjectWeaponPropertiesComponent::UnloadAccessories(this);
    for ( i = 0; i < this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mSoundbankIds.size; ++i )
      UFG::TiDo::UnloadWwiseBank(&this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mSoundbankIds.p[i]);
    this->mSoundBankLoadedId = 0;
    goto LABEL_29;
  }
  if ( !v15 )
    goto LABEL_32;
  if ( !this->mAccessoriesPreloaded )
    UFG::SimObjectWeaponPropertiesComponent::PreloadAccessories(this);
  for ( j = 0; j < this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mSoundbankIds.size; ++j )
    UFG::TiDo::LoadWwiseBank(&this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mSoundbankIds.p[j]);
  this->mSoundBankLoadedId = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mSoundbankIds.p->mUID;
LABEL_29:
  if ( v15 )
  {
    if ( this->mSoundBankLoadedId )
      this->mUnloadTimeOut = 0.0;
    return;
  }
LABEL_32:
  if ( this->mSoundBankLoadedId )
    this->mUnloadTimeOut = delta_sec + this->mUnloadTimeOut;
}

// File Line: 663
// RVA: 0x535270
bool __fastcall UFG::SimObjectWeaponPropertiesComponent::HasAmmo(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v5; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v7; // r8d
  unsigned int v8; // r9d
  unsigned int v9; // r8d
  unsigned int v10; // r9d
  unsigned int v11; // r8d
  unsigned int v12; // r9d

  if ( this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mAmmoInventoryItem == eINVENTORY_ITEM_INVALID )
    return 0;
  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v5 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
           || (UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v5 += 16i64;
        if ( vfptr >= size )
          goto LABEL_9;
      }
LABEL_10:
      ComponentOfType = *(UFG::SimComponent **)v5;
      goto LABEL_33;
    }
    goto LABEL_9;
  }
  if ( m_Flags < 0 )
  {
    v7 = (unsigned int)m_pSimObject[1].vfptr;
    v8 = m_pSimObject->m_Components.size;
    if ( v7 < v8 )
    {
      v5 = (__int64)&m_pSimObject->m_Components.p[v7];
      while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
           || (UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v7;
        v5 += 16i64;
        if ( v7 >= v8 )
          goto LABEL_9;
      }
      goto LABEL_10;
    }
LABEL_9:
    ComponentOfType = 0i64;
    goto LABEL_33;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v9 = (unsigned int)m_pSimObject[1].vfptr;
    v10 = m_pSimObject->m_Components.size;
    if ( v9 < v10 )
    {
      v5 = (__int64)&m_pSimObject->m_Components.p[v9];
      while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
           || (UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v9;
        v5 += 16i64;
        if ( v9 >= v10 )
          goto LABEL_9;
      }
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v11 = (unsigned int)m_pSimObject[1].vfptr;
    v12 = m_pSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      v5 = (__int64)&m_pSimObject->m_Components.p[v11];
      while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
           || (UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v11;
        v5 += 16i64;
        if ( v11 >= v12 )
          goto LABEL_9;
      }
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::GunComponent::_TypeUID);
LABEL_33:
  if ( ComponentOfType )
    return *((_DWORD *)&ComponentOfType[3].m_SafePointerList.mNode.mNext
           + HIDWORD(ComponentOfType[2].m_SafePointerList.mNode.mPrev[10].mNext)
           + 1) > 0;
  return 0;
}

// File Line: 676
// RVA: 0x53B5F0
char __fastcall UFG::SimObjectWeaponPropertiesComponent::IsOwned(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v6; // rdx
  unsigned int v7; // r8d
  unsigned int v8; // r9d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
      goto LABEL_22;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      vfptr = (unsigned int)m_pSimObject[1].vfptr;
      size = m_pSimObject->m_Components.size;
      if ( vfptr < size )
      {
        v6 = (__int64)&m_pSimObject->m_Components.p[vfptr];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          v6 += 16i64;
          if ( vfptr >= size )
            goto LABEL_12;
        }
LABEL_13:
        m_pComponent = *(UFG::SimComponent **)v6;
        goto LABEL_22;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_22;
      }
      v7 = (unsigned int)m_pSimObject[1].vfptr;
      v8 = m_pSimObject->m_Components.size;
      if ( v7 < v8 )
      {
        v6 = (__int64)&m_pSimObject->m_Components.p[v7];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
        {
          ++v7;
          v6 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_12;
        }
        goto LABEL_13;
      }
    }
LABEL_12:
    m_pComponent = 0i64;
    goto LABEL_22;
  }
  m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
LABEL_22:
  if ( !m_pComponent )
    return 0;
  mPrev = m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
  if ( mPrev == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&m_pComponent[1].m_pSimObject )
    return 0;
  while ( (unsigned __int8)(LOBYTE(mPrev[3].mPrev) - 17) > 1u )
  {
    mPrev = mPrev->mNext;
    if ( mPrev == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&m_pComponent[1].m_pSimObject )
      return 0;
  }
  return 1;
}

// File Line: 697
// RVA: 0x52ABC0
bool __fastcall UFG::SimObjectWeaponPropertiesComponent::GetBooleanValue(
        UFG::SimObjectWeaponPropertiesComponent *this,
        UFG::eSimObjectWeaponBooleanEnum eSimObjectWeaponBoolean)
{
  bool result; // al

  switch ( eSimObjectWeaponBoolean )
  {
    case eSIM_OBJ_WEAPON_BOOL_IS_RANGED:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID;
      break;
    case eSIM_OBJ_WEAPON_BOOL_IS_MELEE:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID;
      break;
    case eSIM_OBJ_WEAPON_BOOL_USES_AMMO:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mAmmoInventoryItem != eINVENTORY_ITEM_INVALID;
      break;
    case eSIM_OBJ_WEAPON_BOOL_IS_THROWN:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mThrownSpeed > 0.0;
      break;
    case eSIM_OBJ_WEAPON_BOOL_IS_TWO_HANDED:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mIsTwoHandedWeapon;
      break;
    case eSIM_OBJ_WEAPON_BOOL_IS_BLADED:
      result = this->mIsBladed;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 732
// RVA: 0x52F690
__int64 __fastcall UFG::SimObjectWeaponPropertiesComponent::GetProjectileSpawnBoneID(
        UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::FireModeInfo *v2; // rsi
  UFG::SimObjectProp *m_pSimObject; // rcx
  Creature *mCreature; // rbx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *m_pComponent; // rcx
  unsigned int m_TypeUID; // edx
  unsigned int v8; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  __int64 v12; // rdx
  int BoneID; // eax

  v2 = this->mWeaponTypeInfo->mFireModes[this->mFireMode];
  if ( v2->mProjectileSpawnBoneID )
    return this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneID;
  m_pSimObject = (UFG::SimObjectProp *)this->m_pSimObject;
  mCreature = 0i64;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
      if ( !m_pComponent
        || (m_TypeUID = m_pComponent->m_TypeUID,
            ((m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0)
        || (UFG::CharacterAnimationComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
      {
LABEL_7:
        m_pComponent = 0i64;
      }
    }
    else
    {
      if ( m_Flags < 0 )
      {
        m_pComponent = (UFG::CharacterAnimationComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
        if ( m_pComponent )
        {
          v8 = m_pComponent->m_TypeUID;
          if ( ((v8 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) == 0 )
          {
            if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v8 & 0x1FFFFFF) != 0 )
              m_pComponent = 0i64;
            goto LABEL_25;
          }
        }
        goto LABEL_7;
      }
      if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(m_pSimObject);
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
        {
          mComponentTableEntryCount = m_pSimObject->mComponentTableEntryCount;
          size = m_pSimObject->m_Components.size;
          if ( mComponentTableEntryCount < size )
          {
            v12 = (__int64)&m_pSimObject->m_Components.p[mComponentTableEntryCount];
            while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                 || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF) != 0 )
            {
              ++mComponentTableEntryCount;
              v12 += 16i64;
              if ( mComponentTableEntryCount >= size )
              {
                m_pComponent = 0i64;
                goto LABEL_25;
              }
            }
            m_pComponent = *(UFG::CharacterAnimationComponent **)v12;
            goto LABEL_25;
          }
          goto LABEL_7;
        }
        ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pSimObject,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
      }
      m_pComponent = ComponentOfType;
    }
LABEL_25:
    if ( m_pComponent )
      mCreature = m_pComponent->mCreature;
  }
  if ( mCreature )
  {
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(
                 mCreature->mPose.mRigHandle.mUFGSkeleton,
                 this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneName.mUID);
    else
      BoneID = -1;
    v2->mProjectileSpawnBoneID = BoneID;
  }
  return this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneID;
}

