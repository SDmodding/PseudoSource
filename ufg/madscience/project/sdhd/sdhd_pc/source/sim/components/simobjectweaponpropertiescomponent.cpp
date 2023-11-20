// File Line: 96
// RVA: 0x536B20
void __fastcall UFG::FireModeInfo::InitFromPropertySet(UFG::FireModeInfo *this, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v2; // r14
  UFG::FireModeInfo *v3; // rsi
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
  float v17; // xmm1_4
  float v18; // xmm2_4
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
  UFG::qWiseSymbol *v74; // rbx
  UFG::qWiseSymbol *v75; // rax
  unsigned int v76; // er15
  UFG::qPropertyList *v77; // rax
  UFG::qPropertyList *v78; // rdi
  unsigned int v79; // er12
  unsigned int v80; // ebx
  UFG::qWiseSymbol *v81; // rax
  UFG::qWiseSymbol *v82; // rax
  bool *v83; // rax
  unsigned int *v84; // rax
  UFG::qSymbolUC *v85; // rcx
  signed int v86; // edi
  unsigned int *v87; // rax
  UFG::qSymbolUC **v88; // rcx
  signed int v89; // ebx
  unsigned int *v90; // rax
  signed int *v91; // rcx
  signed int v92; // edx
  UFG::qSymbolUC *v93; // rax
  Render::BeamSettingsHandle *v94; // rax
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
  char *v116; // rax
  __int64 v117; // rcx
  UFG::qPropertySet *v118; // rbx
  float *v119; // rax
  UFG::qSymbolUC *v120; // rdx
  unsigned int v121; // xmm6_4
  float *v122; // rax
  UFG::qSymbolUC **v123; // rcx
  float v124; // xmm0_4
  const float *v125; // rax
  UFG::qSymbolUC beamSettingsSymbol; // [rsp+90h] [rbp+40h]
  UFG::qSymbolUC *v127; // [rsp+A0h] [rbp+50h]
  int v128; // [rsp+A8h] [rbp+58h]

  v2 = properties;
  v3 = this;
  v4 = UFG::qPropertySet::Get<float>(
         properties,
         (UFG::qSymbol *)&PhysicsSym_FlickTargetingAngularLimit.mUID,
         DEPTH_RECURSE);
  if ( v4 )
    v3->mFlickTargetingAngularLimitRad = *v4;
  v3->mFlickTargetingAngularLimitRad = (float)(v3->mFlickTargetingAngularLimitRad * 3.1415927) * 0.0055555557;
  v5 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AccuracyOnTargetChanged.mUID, DEPTH_RECURSE);
  if ( v5 )
    v3->mAccuracyOnTargetChanged = *v5;
  v6 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AccuracyPenaltyPerShot.mUID, DEPTH_RECURSE);
  if ( v6 )
    v3->mAccuracyPenaltyPerShot = *v6;
  v7 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AccuracyRateMultiplier.mUID, DEPTH_RECURSE);
  if ( v7 )
    v3->m_fAccuracyRateMultiplier = *v7;
  v8 = UFG::qPropertySet::Get<long>(v2, (UFG::qSymbol *)&PhysicsSym_AmmoClipCapacity.mUID, DEPTH_RECURSE);
  if ( v8 )
    v3->mAmmoClipCapacity = *v8;
  v9 = UFG::qPropertySet::Get<long>(v2, (UFG::qSymbol *)&PhysicsSym_AmmoTotalCapacity.mUID, DEPTH_RECURSE);
  if ( v9 )
    v3->mAmmoTotalCapacity = *v9;
  v10 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&PhysicsSym_BulletPerShot.mUID, DEPTH_RECURSE);
  if ( v10 )
    v3->mBulletPerShot = *v10;
  v11 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_BulletLifeSpan.mUID, DEPTH_RECURSE);
  if ( v11 )
    v3->mBulletLifeSpan = *v11;
  v12 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&PhysicsSym_IsAutomatic.mUID, DEPTH_RECURSE);
  if ( v12 )
    v3->mIsAutomatic = *v12;
  v13 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&PhysicsSym_Stowable.mUID, DEPTH_RECURSE);
  if ( v13 )
    v3->mStowable = *v13;
  v14 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&PhysicsSym_IsTwoHandedWeapon.mUID, DEPTH_RECURSE);
  if ( v14 )
    v3->mIsTwoHandedWeapon = *v14;
  v15 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&PhysicsSym_HasSniperScope.mUID, DEPTH_RECURSE);
  if ( v15 )
    v3->mHasSniperScope = *v15;
  v16 = UFG::qPropertySet::Get<UFG::qVector3>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_MaxAngularVelocityWhenThrown.mUID,
          DEPTH_RECURSE);
  if ( v16 )
  {
    v17 = v16->y;
    v18 = v16->z;
    v3->mMaxAngularVelocityWhenThrown.x = v16->x;
    v3->mMaxAngularVelocityWhenThrown.y = v17;
    v3->mMaxAngularVelocityWhenThrown.z = v18;
  }
  v19 = UFG::qPropertySet::Get<UFG::qVector3>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_MinAngularVelocityWhenThrown.mUID,
          DEPTH_RECURSE);
  if ( v19 )
  {
    v20 = v19->y;
    v21 = v19->z;
    v3->mMinAngularVelocityWhenThrown.x = v19->x;
    v3->mMinAngularVelocityWhenThrown.y = v20;
    v3->mMinAngularVelocityWhenThrown.z = v21;
  }
  v22 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&PhysicsSym_ProjectileSpawnBoneID.mUID, DEPTH_RECURSE);
  if ( v22 )
    v3->mProjectileSpawnBoneID = *v22;
  v23 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ProjectilePhysicsImpulse.mUID, DEPTH_RECURSE);
  if ( v23 )
    v3->mProjectilePhysicsImpulse = *v23;
  v24 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RangedDistance.mUID, DEPTH_RECURSE);
  if ( v24 )
    v3->mRangedDistance = *v24;
  v25 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AngularInaccuracyMax.mUID, DEPTH_RECURSE);
  if ( v25 )
    v3->mAngularInaccuracyRadMax = *v25;
  v26 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AngularInaccuracyMin.mUID, DEPTH_RECURSE);
  if ( v26 )
    v3->mAngularInaccuracyRadMin = *v26;
  v27 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RateOfFire.mUID, DEPTH_RECURSE);
  if ( v27 )
    v3->mRateOfFire = *v27;
  v28 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_HardLockReticleSizeMin.mUID, DEPTH_RECURSE);
  if ( v28 )
    v3->mHardLockReticleSizeMin = *v28;
  v29 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_HardLockReticleSizeMax.mUID, DEPTH_RECURSE);
  if ( v29 )
    v3->mHardLockReticleSizeMax = *v29;
  v30 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ReticleSizeMin.mUID, DEPTH_RECURSE);
  if ( v30 )
    v3->mReticleSizeMin = *v30;
  v31 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ReticleSizeMax.mUID, DEPTH_RECURSE);
  if ( v31 )
    v3->mReticleSizeMax = *v31;
  v32 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ReticleSizeBlindfire.mUID, DEPTH_RECURSE);
  if ( v32 )
    v3->mReticleSizeBlindfire = *v32;
  v33 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ThrownSpeed.mUID, DEPTH_RECURSE);
  if ( v33 )
    v3->mThrownSpeed = *v33;
  v34 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_HardLockDamageMultiplier.mUID, DEPTH_RECURSE);
  if ( v34 )
    v3->mHardLockDamageMultiplier = *v34;
  v35 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_DamageMultiplier.mUID, DEPTH_RECURSE);
  if ( v35 )
    v3->mDamageMultiplier = *v35;
  v36 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&PhysicsSym_StartingMaxAmmoCount.mUID, DEPTH_RECURSE);
  if ( v36 )
    v3->mStartingMaxAmmoCount = *v36;
  v37 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&PhysicsSym_StartingMinAmmoCount.mUID, DEPTH_RECURSE);
  if ( v37 )
    v3->mStartingMinAmmoCount = *v37;
  v38 = UFG::qPropertySet::Get<unsigned long>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_AIOnDeathDropMaxAmmoCount.mUID,
          DEPTH_RECURSE);
  if ( v38 )
    v3->mAIOnDeathDropMaxAmmoCount = *v38;
  v39 = UFG::qPropertySet::Get<unsigned long>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_AIOnDeathDropMinAmmoCount.mUID,
          DEPTH_RECURSE);
  if ( v39 )
    v3->mAIOnDeathDropMinAmmoCount = *v39;
  v40 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ProjectileSpeed.mUID, DEPTH_RECURSE);
  if ( v40 )
    v3->mProjectileSpeed = *v40;
  v41 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ProjectileSpeedAI.mUID, DEPTH_RECURSE);
  if ( v41 )
    v3->mProjectileSpeedAI = *v41;
  v42 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ProjectileGravity.mUID, DEPTH_RECURSE);
  if ( v42 )
    v3->mProjectileGravity = *v42;
  v43 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_ArmingDistance.mUID, DEPTH_RECURSE);
  if ( v43 )
    v3->mArmingDistance = *v43;
  v44 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_SlowModeRateOfFireMultiplier.mUID, DEPTH_RECURSE);
  if ( v44 )
    v3->mSlowModeRateOfFireMultiplier = *v44;
  v45 = UFG::qPropertySet::Get<float>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_SlowModeRateOfFireMultiplierAI.mUID,
          DEPTH_RECURSE);
  if ( v45 )
    v3->mSlowModeRateOfFireMultiplierAI = *v45;
  v46 = UFG::qPropertySet::Get<float>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_SlowModeProjectileSpeedMultiplier.mUID,
          DEPTH_RECURSE);
  if ( v46 )
    v3->mSlowModeProjectileSpeedMultiplier = *v46;
  v47 = UFG::qPropertySet::Get<float>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_SlowModeProjectileSpeedMultiplierAI.mUID,
          DEPTH_RECURSE);
  if ( v47 )
    v3->mSlowModeProjectileSpeedMultiplierAI = *v47;
  v48 = UFG::qPropertySet::Get<float>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_SlowModeProjectileDamageMultiplier.mUID,
          DEPTH_RECURSE);
  if ( v48 )
    v3->mSlowModeProjectileDamageMultiplier = *v48;
  v49 = UFG::qPropertySet::Get<float>(
          v2,
          (UFG::qSymbol *)&PhysicsSym_SlowModeProjectileDamageMultiplierAI.mUID,
          DEPTH_RECURSE);
  if ( v49 )
    v3->mSlowModeProjectileDamageMultiplierAI = *v49;
  v50 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AimYawPerS.mUID, DEPTH_RECURSE);
  if ( v50 )
    v3->mAimYawPerSRad = *v50;
  v51 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AimPitchPerS.mUID, DEPTH_RECURSE);
  if ( v51 )
    v3->mAimPitchPerSRad = *v51;
  v52 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AimMaxInputSpeedPerS.mUID, DEPTH_RECURSE);
  if ( v52 )
    v3->mAimMaxInputSpeedPerS = *v52;
  v53 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AimFlickTransitionDegPerS.mUID, DEPTH_RECURSE);
  if ( v53 )
    v3->mAimFlickTransitionRadPerS = *v53;
  v54 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AimSubtargetTransitionDegPerS.mUID, DEPTH_RECURSE);
  if ( v54 )
    v3->mAimSubtargetTransitionRadPerS = *v54;
  v55 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AimFreeAimTransitionDegPerS.mUID, DEPTH_RECURSE);
  if ( v55 )
    v3->mAimFreeAimTransitionRadPerS = *v55;
  v56 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_AimFovOffset.mUID, DEPTH_RECURSE);
  if ( v56 )
    v3->mAimFovOffset = *v56;
  v57 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RecoilKickupMin.mUID, DEPTH_RECURSE);
  if ( v57 )
    v3->mRecoilKickupMin = *v57;
  v58 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RecoilKickupMax.mUID, DEPTH_RECURSE);
  if ( v58 )
    v3->mRecoilKickupMax = *v58;
  v59 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RecoilKickupOffset.mUID, DEPTH_RECURSE);
  if ( v59 )
    v3->mRecoilKickupOffset = *v59;
  v60 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RecoilKickupRateAttack.mUID, DEPTH_RECURSE);
  if ( v60 )
    v3->mRecoilKickupRateAttack = *v60;
  v61 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RecoilKickupRateDecay.mUID, DEPTH_RECURSE);
  if ( v61 )
    v3->mRecoilKickupRateDecay = *v61;
  v62 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RecoilKickback.mUID, DEPTH_RECURSE);
  if ( v62 )
    v3->mRecoilKickback = *v62;
  v63 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RecoilKickbackSpeed.mUID, DEPTH_RECURSE);
  if ( v63 )
    v3->mRecoilKickbackSpeed = *v63;
  v64 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_RecoilKickbackDur.mUID, DEPTH_RECURSE);
  if ( v64 )
    v3->mRecoilKickbackDur = *v64;
  v65 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_MinDesiredDistance.mUID, DEPTH_RECURSE);
  if ( v65 )
    v3->mMinDesiredDistance = *v65;
  v66 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_MaxDisiredDistance.mUID, DEPTH_RECURSE);
  if ( v66 )
    v3->mMaxDisiredDistance = *v66;
  v67 = UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&PhysicsSym_DesiredDistance.mUID, DEPTH_RECURSE);
  if ( v67 )
    v3->mDesiredDistance = *v67;
  v68 = UFG::qPropertySet::Get<UFG::qVector3>(v2, (UFG::qSymbol *)&PhysicsSym_AimOriginOffset.mUID, DEPTH_RECURSE);
  if ( v68 )
  {
    v69 = v68->y;
    v70 = v68->z;
    v3->mAimOriginOffset.x = v68->x;
    v3->mAimOriginOffset.y = v69;
    v3->mAimOriginOffset.z = v70;
  }
  v71 = UFG::qPropertySet::Get<UFG::qVector3>(v2, (UFG::qSymbol *)&PhysicsSym_ThrownWeaponSpinAxis.mUID, DEPTH_RECURSE);
  if ( v71 )
  {
    v72 = v71->y;
    v73 = v71->z;
    v3->mThrownWeaponSpinAxis.x = v71->x;
    v3->mThrownWeaponSpinAxis.y = v72;
    v3->mThrownWeaponSpinAxis.z = v73;
  }
  v3->mAngularInaccuracyRadMin = (float)(v3->mAngularInaccuracyRadMin * 3.1415927) * 0.0055555557;
  v3->mAngularInaccuracyRadMax = (float)(v3->mAngularInaccuracyRadMax * 3.1415927) * 0.0055555557;
  v3->mAimYawPerSRad = (float)(v3->mAimYawPerSRad * 3.1415927) * 0.0055555557;
  v3->mAimPitchPerSRad = (float)(v3->mAimPitchPerSRad * 3.1415927) * 0.0055555557;
  v3->mAimFlickTransitionRadPerS = (float)(v3->mAimFlickTransitionRadPerS * 3.1415927) * 0.0055555557;
  v3->mAimSubtargetTransitionRadPerS = (float)(v3->mAimSubtargetTransitionRadPerS * 3.1415927) * 0.0055555557;
  v3->mAimFreeAimTransitionRadPerS = (float)(v3->mAimFreeAimTransitionRadPerS * 3.1415927) * 0.0055555557;
  v74 = v3->mSoundbankIds.p;
  v75 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v2, (UFG::qSymbol *)&TiDoSym_SoundBank.mUID, DEPTH_RECURSE);
  v76 = 0;
  if ( v75 )
  {
    UFG::qWiseSymbol::operator=(v74, v75);
  }
  else
  {
    v77 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&TiDoSym_SoundbankList.mUID, DEPTH_RECURSE);
    v78 = v77;
    if ( v77 )
    {
      v79 = v77->mNumElements;
      v80 = 0;
      if ( v79 )
      {
        do
        {
          v81 = UFG::qPropertyList::Get<UFG::qWiseSymbol>(v78, v80);
          if ( v81 )
            UFG::qWiseSymbol::operator=(&v3->mSoundbankIds.p[v80], v81);
          ++v80;
        }
        while ( v80 < v79 );
      }
    }
  }
  v82 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(v2, (UFG::qSymbol *)&qSymbol_AudioWeaponType.mUID, DEPTH_RECURSE);
  if ( v82 )
    UFG::qWiseSymbol::operator=(&v3->mAudioWeaponType, v82);
  v83 = UFG::qPropertySet::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_AudioWeaponIsLooping.mUID, DEPTH_RECURSE);
  if ( v83 )
    v3->mAudioWeaponIsLooping = *v83;
  beamSettingsSymbol.mUID = 0;
  LODWORD(v127) = 0;
  v128 = 0;
  v84 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&PhysicsSym_Damage.mUID, DEPTH_RECURSE);
  v85 = &beamSettingsSymbol;
  if ( v84 )
    v85 = (UFG::qSymbolUC *)v84;
  v86 = v85->mUID;
  v87 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&PhysicsSym_PropDamage.mUID, DEPTH_RECURSE);
  v88 = &v127;
  if ( v87 )
    v88 = (UFG::qSymbolUC **)v87;
  v89 = *(_DWORD *)v88;
  v90 = UFG::qPropertySet::Get<unsigned long>(v2, (UFG::qSymbol *)&PhysicsSym_VehicleDamage.mUID, DEPTH_RECURSE);
  v91 = &v128;
  if ( v90 )
    v91 = (signed int *)v90;
  v92 = *v91;
  v3->mDamage = (float)v86 * 0.0099999998;
  v3->mPropDamage = (float)v89 * 0.0099999998;
  v3->mVehicleDamage = (float)v92 * 0.0099999998;
  v93 = UFG::qPropertySet::Get<UFG::qSymbolUC>(v2, (UFG::qSymbol *)&PhysicsSym_Tracer.mUID, DEPTH_RECURSE);
  if ( v93 )
  {
    v127 = &beamSettingsSymbol;
    beamSettingsSymbol.mUID = v93->mUID;
    v94 = UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager::mInstance, (__int64)&beamSettingsSymbol);
  }
  else
  {
    v94 = 0i64;
  }
  v3->mTracerBeamSettingsHandle = v94;
  v95 = UFG::qPropertySet::Get<UFG::qSymbolUC>(v2, (UFG::qSymbol *)&PhysicsSym_TracerAI.mUID, DEPTH_RECURSE);
  if ( v95 )
  {
    v127 = &beamSettingsSymbol;
    beamSettingsSymbol.mUID = v95->mUID;
    v96 = UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager::mInstance, (__int64)&beamSettingsSymbol);
  }
  else
  {
    v96 = 0i64;
  }
  v3->mTracerBeamAISettingsHandle = v96;
  v97 = UFG::qPropertySet::Get<UFG::qSymbolUC>(v2, (UFG::qSymbol *)&PhysicsSym_TracerTrail.mUID, DEPTH_RECURSE);
  if ( v97 )
  {
    v127 = &beamSettingsSymbol;
    beamSettingsSymbol.mUID = v97->mUID;
    v98 = UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager::mInstance, (__int64)&beamSettingsSymbol);
  }
  else
  {
    v98 = 0i64;
  }
  v3->mTracerBeamTrailSettingsHandle = v98;
  v99 = UFG::qPropertySet::Get<UFG::qSymbolUC>(v2, (UFG::qSymbol *)&PhysicsSym_TracerTrailAI.mUID, DEPTH_RECURSE);
  if ( v99 )
  {
    v127 = &beamSettingsSymbol;
    beamSettingsSymbol.mUID = v99->mUID;
    v100 = UFG::BulletManager::GetBeamSettingsHandle(UFG::BulletManager::mInstance, (__int64)&beamSettingsSymbol);
  }
  else
  {
    v100 = 0i64;
  }
  v3->mTracerBeamTrailAISettingsHandle = v100;
  v101 = UFG::qPropertySet::Get<UFG::qSymbolUC>(v2, (UFG::qSymbol *)&PhysicsSym_BulletType.mUID, DEPTH_RECURSE);
  if ( v101 )
    v102 = v101->mUID;
  else
    v102 = UFG::qStringHashUpper32("Bullet", 0xFFFFFFFF);
  v3->mBulletTypeID = v102;
  v103 = UFG::qPropertySet::Get<char const *>(
           v2,
           (UFG::qSymbol *)&PhysicsSym_ProjectileSpawnBoneName.mUID,
           DEPTH_RECURSE);
  v3->mProjectileSpawnBoneName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&beamSettingsSymbol, v103)->mUID;
  v104 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&PhysicsSym_BulletEffectID.mUID, DEPTH_RECURSE);
  if ( v104 )
    v105 = UFG::qStringHashUpper32(v104, 0xFFFFFFFF);
  else
    v105 = 0;
  v3->mBulletEffectID = v105;
  v106 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&PhysicsSym_ExplosionType.mUID, DEPTH_RECURSE);
  if ( v106 )
    v3->mExplosionType = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&beamSettingsSymbol, v106)->mUID;
  v107 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&PhysicsSym_AmmoInventoryItem.mUID, DEPTH_RECURSE);
  if ( v107 )
  {
    v108 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&beamSettingsSymbol, v107);
    v3->mAmmoInventoryItem = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gInventoryItemTracksEnum, v108);
  }
  v109 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&PhysicsSym_ProjectileReaction.mUID, DEPTH_RECURSE);
  if ( v109 )
  {
    v110 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&beamSettingsSymbol, v109);
    v3->mProjectileReaction = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gProjectileReactionEnum, v110);
  }
  v111 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&qSymbol_simObjectWeaponType.mUID, DEPTH_RECURSE);
  if ( v111 )
  {
    v112 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&beamSettingsSymbol, v111);
    v3->mSimObjectWeaponType = TracksEnum<unsigned long>::GetEnumFromSymbol(&UFG::gSimObjectWeaponTypeTrackEnum, v112);
  }
  v113 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&PhysicsSym_AimInputMapping.mUID, DEPTH_RECURSE);
  v114 = v113;
  if ( v113 )
  {
    v115 = v113->mNumElements;
    if ( v115 )
    {
      do
      {
        v116 = UFG::qPropertyList::GetValuePtr(v114, 0x1Au, v76);
        if ( v116 )
        {
          v117 = *(_QWORD *)v116;
          if ( *(_QWORD *)v116 )
          {
            v118 = (UFG::qPropertySet *)&v116[v117];
            if ( &v116[v117] )
            {
              beamSettingsSymbol.mUID = 0;
              LODWORD(v127) = 0;
              v119 = UFG::qPropertySet::Get<float>(
                       (UFG::qPropertySet *)&v116[v117],
                       (UFG::qSymbol *)&PhysicsSym_AimInput.mUID,
                       DEPTH_RECURSE);
              v120 = &beamSettingsSymbol;
              if ( v119 )
                v120 = (UFG::qSymbolUC *)v119;
              v121 = v120->mUID;
              v122 = UFG::qPropertySet::Get<float>(v118, (UFG::qSymbol *)&PhysicsSym_AimOutput.mUID, DEPTH_RECURSE);
              v123 = &v127;
              if ( v122 )
                v123 = (UFG::qSymbolUC **)v122;
              v124 = *(float *)v123;
              LODWORD(v3->mAimInputMappingInput.p[v3->mAimInputMappingInput.size++]) = v121;
              v3->mAimInputMappingOutput.p[v3->mAimInputMappingOutput.size++] = v124;
            }
          }
        }
        ++v76;
      }
      while ( v76 < v115 );
    }
    v3->mAimInputMapping.nData = v115;
    v3->mAimInputMapping.fDomain = v3->mAimInputMappingInput.p;
    v125 = v3->mAimInputMappingOutput.p;
  }
  else
  {
    v3->mAimInputMapping.nData = 2;
    v3->mAimInputMapping.fDomain = input_domain;
    v125 = input_domain;
  }
  v3->mAimInputMapping.tRange = v125;
}

// File Line: 273
// RVA: 0x538D10
void __fastcall UFG::WeaponTypeInfo::InitFromPropertySet(UFG::WeaponTypeInfo *this, UFG::qPropertySet *properties)
{
  UFG::qPropertySet *v2; // r15
  UFG::WeaponTypeInfo *v3; // rsi
  UFG::FireModeInfo *v4; // rbx
  unsigned int v5; // edi
  signed __int64 v6; // r14
  void *v7; // rbp
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rbp
  unsigned int v10; // ecx
  unsigned int v11; // edi
  UFG::allocator::free_link *v12; // rax
  __int64 v13; // rax
  __int64 v14; // rcx
  signed __int64 v15; // r14
  char *v16; // rax
  UFG::qPropertySet *v17; // rdx
  UFG::allocator::free_link *v18; // rax
  UFG::FireModeInfo *v19; // rax

  v2 = properties;
  v3 = this;
  v4 = 0i64;
  if ( this->mNumFireModes )
  {
    v5 = 0;
    do
    {
      v6 = (signed __int64)v3 + 8 * v5;
      v7 = *(void **)(v6 + 8);
      if ( v7 )
      {
        UFG::FireModeInfo::~FireModeInfo(*(UFG::FireModeInfo **)(v6 + 8));
        operator delete[](v7);
      }
      *(_QWORD *)(v6 + 8) = 0i64;
      ++v5;
    }
    while ( v5 < v3->mNumFireModes );
    v3->mNumFireModes = 0;
  }
  v3->mPropertySetSymbol.mUID = v2->mName.mUID;
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&PhysicsSym_FireModes.mUID, DEPTH_RECURSE);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8->mNumElements;
    v3->mNumFireModes = v10;
    v11 = 0;
    if ( v10 )
    {
      do
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
        v15 = (signed __int64)v3 + 8 * v11;
        *(_QWORD *)(v15 + 8) = v14;
        v16 = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
        if ( !v16 || (v17 = (UFG::qPropertySet *)&v16[*(_QWORD *)v16], !*(_QWORD *)v16) )
          v17 = 0i64;
        UFG::FireModeInfo::InitFromPropertySet(*(UFG::FireModeInfo **)(v15 + 8), v17);
        ++v11;
      }
      while ( v11 < v3->mNumFireModes );
    }
  }
  else
  {
    v3->mNumFireModes = 1;
    v18 = UFG::qMalloc(0x1E8ui64, "FireModeInfo", 0i64);
    if ( v18 )
    {
      UFG::FireModeInfo::FireModeInfo((UFG::FireModeInfo *)v18);
      v4 = v19;
    }
    v3->mFireModes[0] = v4;
    UFG::FireModeInfo::InitFromPropertySet(v4, v2);
  }
}

// File Line: 336
// RVA: 0x1544080
__int64 dynamic_initializer_for__UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList__);
}

// File Line: 337
// RVA: 0x52CB20
UFG::ComponentIDDesc *__fastcall UFG::SimObjectWeaponPropertiesComponent::GetDesc(UFG::SimObjectWeaponPropertiesComponent *this)
{
  return &UFG::SimObjectWeaponPropertiesComponent::_TypeIDesc;
}

// File Line: 338
// RVA: 0x1543CE0
__int64 dynamic_initializer_for__UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos__()
{
  `eh vector constructor iterator(
    UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos,
    0x18ui64,
    120,
    (void (__fastcall *)(void *))UFG::WeaponTypeInfo::WeaponTypeInfo);
  return atexit(dynamic_atexit_destructor_for__UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos__);
}

// File Line: 341
// RVA: 0x154C7E0
__int64 UFG::_dynamic_initializer_for__sSymbolArchetypes__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("archetypes", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolArchetypes, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSymbolArchetypes__);
}

// File Line: 342
// RVA: 0x154C960
__int64 UFG::_dynamic_initializer_for__sSymbolSubfolders__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("subfolders", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolSubfolders, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSymbolSubfolders__);
}

// File Line: 343
// RVA: 0x154C8E0
__int64 UFG::_dynamic_initializer_for__sSymbolPhysical__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("physical", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolPhysical, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSymbolPhysical__);
}

// File Line: 344
// RVA: 0x154C9A0
__int64 UFG::_dynamic_initializer_for__sSymbolWeapon__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("weapon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolWeapon, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSymbolWeapon__);
}

// File Line: 345
// RVA: 0x154C920
__int64 UFG::_dynamic_initializer_for__sSymbolProp__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("prop", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolProp, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSymbolProp__);
}

// File Line: 346
// RVA: 0x154C820
__int64 UFG::_dynamic_initializer_for__sSymbolFirearm__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("firearm", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolFirearm, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSymbolFirearm__);
}

// File Line: 347
// RVA: 0x154C8A0
__int64 UFG::_dynamic_initializer_for__sSymbolMelee__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("melee", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSymbolMelee, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSymbolMelee__);
}

// File Line: 353
// RVA: 0x5214B0
void __fastcall UFG::SimObjectWeaponPropertiesComponent::AddWeaponTypeInfosForPropertySet(UFG::qPropertySet *pPropertySet)
{
  UFG::qPropertyList *v1; // rax
  unsigned int v2; // ebx
  UFG::qPropertyList *v3; // rbp
  unsigned int v4; // esi
  unsigned int v5; // edi
  char *v6; // rax
  UFG::qPropertySet *v7; // rcx
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // rbp
  unsigned int v10; // edi
  UFG::qSymbol *v11; // rax
  UFG::qPropertySet *v12; // rax
  UFG::qPropertySet *v13; // rsi
  UFG::qPropertySet *v14; // rax
  UFG::qPropertySet *v15; // [rsp+30h] [rbp+8h]

  v15 = pPropertySet;
  v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(pPropertySet, (UFG::qSymbol *)&sSymbolSubfolders.mUID, DEPTH_RECURSE);
  v2 = 0;
  v3 = v1;
  if ( v1 )
  {
    v4 = v1->mNumElements;
    v5 = 0;
    if ( v4 )
    {
      do
      {
        v6 = UFG::qPropertyList::GetValuePtr(v3, 0x1Au, v5);
        if ( v6 && *(_QWORD *)v6 )
          v7 = (UFG::qPropertySet *)&v6[*(_QWORD *)v6];
        else
          v7 = 0i64;
        UFG::SimObjectWeaponPropertiesComponent::AddWeaponTypeInfosForPropertySet(v7);
        ++v5;
      }
      while ( v5 < v4 );
    }
  }
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v15, (UFG::qSymbol *)&sSymbolArchetypes.mUID, DEPTH_RECURSE);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8->mNumElements;
    if ( v10 )
    {
      do
      {
        v11 = UFG::qPropertyList::Get<UFG::qSymbol>(v9, v2);
        v12 = UFG::PropertySetManager::GetPropertySet(v11);
        v13 = v12;
        v14 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                v12,
                (UFG::qSymbol *)&component_WeaponProperties::sPropertyName.mUID,
                DEPTH_RECURSE);
        if ( v14
          && UFG::qPropertySet::GetMemImagePtr(v14)
          && UFG::SimObjectWeaponPropertiesComponent::sNumWeaponTypeInfos < 0x78 )
        {
          UFG::WeaponTypeInfo::InitFromPropertySet(
            &UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos[UFG::SimObjectWeaponPropertiesComponent::sNumWeaponTypeInfos],
            v13);
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
  UFG::qPropertySet *v1; // rax
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
  UFG::qSymbol symbol; // [rsp+50h] [rbp+8h]
  UFG::qSymbol result; // [rsp+58h] [rbp+10h]
  UFG::qSymbol *v14; // [rsp+60h] [rbp+18h]
  UFG::qSymbol **v15; // [rsp+68h] [rbp+20h]

  v0 = UFG::qSymbol::create_from_string(&result, "object-manifest");
  v1 = UFG::PropertySetManager::GetPropertySet(v0);
  v14 = &symbol;
  symbol.mUID = sSymbolPhysical.mUID;
  v2 = UFG::qPropertySet::Get<UFG::qPropertyList>(v1, (UFG::qSymbol *)&sSymbolSubfolders.mUID, DEPTH_RECURSE);
  v3 = UFG::FindInList(v2, (__int64)&symbol);
  v14 = &result;
  result.mUID = sSymbolProp.mUID;
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&sSymbolSubfolders.mUID, DEPTH_RECURSE);
  v5 = UFG::FindInList(v4, (__int64)&result);
  UFG::SimObjectWeaponPropertiesComponent::AddWeaponTypeInfosForPropertySet(v5);
  v14 = &result;
  result.mUID = sSymbolWeapon.mUID;
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, (UFG::qSymbol *)&sSymbolSubfolders.mUID, DEPTH_RECURSE);
  v7 = UFG::FindInList(v6, (__int64)&result);
  v14 = &symbol;
  symbol.mUID = sSymbolFirearm.mUID;
  v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v7, (UFG::qSymbol *)&sSymbolSubfolders.mUID, DEPTH_RECURSE);
  v9 = UFG::FindInList(v8, (__int64)&symbol);
  v15 = &v14;
  LODWORD(v14) = sSymbolMelee;
  v10 = UFG::qPropertySet::Get<UFG::qPropertyList>(v7, (UFG::qSymbol *)&sSymbolSubfolders.mUID, DEPTH_RECURSE);
  v11 = UFG::FindInList(v10, (__int64)&v14);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__sSymbolMagazineType__);
}

// File Line: 433
// RVA: 0x154C740
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_IsRealWeapon__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IsRealWeapon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsRealWeapon, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_IsRealWeapon__);
}

// File Line: 434
// RVA: 0x154C700
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_IsPhoneCamera__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IsPhoneCamera", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsPhoneCamera, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_IsPhoneCamera__);
}

// File Line: 435
// RVA: 0x154C6C0
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_IsBladed__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("IsBladed", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsBladed, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_IsBladed__);
}

// File Line: 436
// RVA: 0x154C680
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_HudReticle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("HudReticle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_HudReticle, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_HudReticle__);
}

// File Line: 437
// RVA: 0x154C780
__int64 UFG::_dynamic_initializer_for__sSimObjectWeaponPropertiesComponentSymbol_NetWorkedFireStateNode__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NetWorkedFireStateNode", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_NetWorkedFireStateNode, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sSimObjectWeaponPropertiesComponentSymbol_NetWorkedFireStateNode__);
}

// File Line: 452
// RVA: 0x519280
void __fastcall UFG::SimObjectWeaponPropertiesComponent::SimObjectWeaponPropertiesComponent(UFG::SimObjectWeaponPropertiesComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, component_WeaponProperties *data_ptr)
{
  UFG::qPropertySet *v4; // rsi
  UFG::SimObjectWeaponPropertiesComponent *v5; // rbx
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v6; // rdx
  signed __int64 v7; // rdi
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v8; // rax
  UFG::qResourceData *v9; // rax
  int v10; // eax
  unsigned int v11; // ecx
  UFG::WeaponTypeInfo *v12; // rdx
  UFG::qSymbol *v13; // rax
  bool *v14; // rax
  bool *v15; // rcx
  bool *v16; // rax
  bool *v17; // rcx
  bool *v18; // rax
  UFG::qSymbolUC *v19; // rax
  unsigned int *v20; // r14
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v21; // rax
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v22; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v23; // rax
  char *v24; // rsi
  __int64 v25; // rcx
  void *v26; // rcx
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]

  v4 = properties;
  v5 = this;
  UFG::SimObjectPropertiesComponent::SimObjectPropertiesComponent(
    (UFG::SimObjectPropertiesComponent *)&this->vfptr,
    name_uid,
    (component_SimObjectProperties *)data_ptr);
  v6 = (UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectWeaponPropertiesComponent::`vftable;
  *(_QWORD *)&v5->mLastOwner = 0i64;
  v5->mWeaponTypeInfo = 0i64;
  *(_QWORD *)&v5->mUnloadTimeOut = 0i64;
  v5->mLastBulletImpactStimulusTimer = 0.0;
  v5->mAccessoriesPreloaded = 0;
  v5->mMagazineType = UFG::gNullQSymbol;
  *(_WORD *)&v5->mIsRealWeapon = 0;
  v5->mHudReticule = 0;
  v7 = (signed __int64)&v5->mNetWorkedFireStateNode;
  *(_DWORD *)v7 = 0;
  *(_QWORD *)(v7 + 8) = 0i64;
  v8 = UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mPrev;
  UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *)&v5->mPrev;
  v6->mPrev = v8;
  v5->mNext = (UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *)&UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList;
  UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentList.mNode.mPrev = (UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::SimObjectWeaponPropertiesComponent::_SimObjectWeaponPropertiesComponentTypeUID,
    "SimObjectWeaponPropertiesComponent");
  if ( v4 )
  {
    if ( (unsigned int)UFG::qPropertySet::NumParents(v4) )
      v9 = UFG::qPropertySet::GetParentFromIdx(v4, 0);
    else
      v9 = (UFG::qResourceData *)v4;
    v10 = *(_DWORD *)&v9->mDebugName[12];
    v11 = 0;
    v12 = UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos;
    while ( v12->mPropertySetSymbol.mUID != v10 )
    {
      ++v11;
      ++v12;
      if ( v11 >= 0x78 )
        goto LABEL_10;
    }
    v5->mWeaponTypeInfo = &UFG::SimObjectWeaponPropertiesComponent::sWeaponTypeInfos[v11];
LABEL_10:
    v13 = UFG::qPropertySet::Get<UFG::qSymbol>(v4, (UFG::qSymbol *)&sSymbolMagazineType.mUID, DEPTH_RECURSE);
    if ( v13 )
      v5->mMagazineType = (UFG::qSymbol)v13->mUID;
    v14 = UFG::qPropertySet::Get<bool>(
            v4,
            (UFG::qSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsRealWeapon.mUID,
            DEPTH_RECURSE);
    v15 = &v5->mIsRealWeapon;
    if ( v14 )
      v15 = v14;
    v5->mIsRealWeapon = *v15;
    v16 = UFG::qPropertySet::Get<bool>(
            v4,
            (UFG::qSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsPhoneCamera.mUID,
            DEPTH_RECURSE);
    v17 = &v5->mIsPhoneCamera;
    if ( v16 )
      v17 = v16;
    v5->mIsPhoneCamera = *v17;
    v18 = UFG::qPropertySet::Get<bool>(
            v4,
            (UFG::qSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_IsBladed.mUID,
            DEPTH_RECURSE);
    if ( !v18 )
      v18 = &v5->mIsBladed;
    v5->mIsBladed = *v18;
    v19 = (UFG::qSymbolUC *)UFG::qPropertySet::Get<UFG::qSymbol>(
                              v4,
                              (UFG::qSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_HudReticle.mUID,
                              DEPTH_RECURSE);
    v20 = &v19->mUID;
    if ( v19 )
    {
      UFG::qSymbol::as_cstr_dbg(v19);
      pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.m_EnumSymbol.mUID = -1;
      pTrackEnumBinding.m_EnumSymbol.mUID = *v20;
      *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
      pTrackEnumBinding.m_uEnumUID = 0;
      if ( UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size )
      {
        TracksEnum<unsigned long>::ResolveBinding(&UFG::gSimObjectWeaponReticleTracksEnum, &pTrackEnumBinding);
      }
      else
      {
        v21 = UFG::gSimObjectWeaponReticleTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
        UFG::gSimObjectWeaponReticleTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
        pTrackEnumBinding.mPrev = v21;
        pTrackEnumBinding.mNext = &UFG::gSimObjectWeaponReticleTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
        UFG::gSimObjectWeaponReticleTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      }
      v5->mHudReticule = pTrackEnumBinding.m_EnumValue;
      v22 = pTrackEnumBinding.mPrev;
      v23 = pTrackEnumBinding.mNext;
      pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
      v23->mPrev = v22;
      pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
      pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    }
    v24 = UFG::qPropertySet::Get<char const *>(
            v4,
            (UFG::qSymbol *)&sSimObjectWeaponPropertiesComponentSymbol_NetWorkedFireStateNode.mUID,
            DEPTH_RECURSE);
    if ( v24 )
    {
      if ( *(_DWORD *)v7 >= 0 )
      {
        v25 = v5->mNetWorkedFireStateNode.mPath.mData.mOffset;
        if ( v25 )
        {
          v26 = (void *)(v7 + v25 + 8);
          if ( v26 )
            operator delete[](v26);
        }
        v5->mNetWorkedFireStateNode.mPath.mData.mOffset = 0i64;
        *(_DWORD *)v7 &= 0x80000000;
      }
      ActionPath::Append(&v5->mNetWorkedFireStateNode, v24);
    }
  }
}

// File Line: 504
// RVA: 0x51C920
void __fastcall UFG::SimObjectWeaponPropertiesComponent::~SimObjectWeaponPropertiesComponent(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::SimObjectWeaponPropertiesComponent *v1; // rdi
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v2; // rsi
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v3; // rcx
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v4; // rax
  UFG::qPropertySet *v5; // rbx
  UFG::ObjectResourceManager *v6; // rax
  unsigned int v7; // edx
  __int64 v8; // rbx
  ActionPath *v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rax
  char *v12; // rcx
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v13; // rcx
  UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *v14; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectWeaponPropertiesComponent::`vftable;
  if ( this == UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentpCurrentIterator )
    UFG::SimObjectWeaponPropertiesComponent::s_SimObjectWeaponPropertiesComponentpCurrentIterator = (UFG::SimObjectWeaponPropertiesComponent *)&this->mPrev[-10].mNext;
  v2 = (UFG::qNode<UFG::SimObjectWeaponPropertiesComponent,UFG::SimObjectWeaponPropertiesComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  if ( v1->mAccessoriesPreloaded )
  {
    v1->mAccessoriesPreloaded = 0;
    if ( v1->mMagazineType.mUID != UFG::gNullQSymbol.mUID )
    {
      v5 = UFG::PropertySetManager::FindPropertySet(&v1->mMagazineType);
      v6 = UFG::ObjectResourceManager::Instance();
      UFG::ObjectResourceManager::ReleaseCriticalResource(v6, v5);
    }
  }
  v7 = v1->mSoundBankLoadedId;
  if ( v7 )
  {
    UFG::qSymbol::qSymbol(&result, v7);
    v8 = 0i64;
    if ( v1->mWeaponTypeInfo->mFireModes[v1->mFireMode]->mSoundbankIds.size )
    {
      do
      {
        UFG::TiDo::UnloadWwiseBank(&v1->mWeaponTypeInfo->mFireModes[v1->mFireMode]->mSoundbankIds.p[v8]);
        v8 = (unsigned int)(v8 + 1);
      }
      while ( (unsigned int)v8 < v1->mWeaponTypeInfo->mFireModes[v1->mFireMode]->mSoundbankIds.size );
    }
    v1->mSoundBankLoadedId = 0;
    _((AMD_HD3D *)result.mUID);
  }
  v9 = &v1->mNetWorkedFireStateNode;
  *(_QWORD *)&result.mUID = (char *)v1 + 216;
  if ( v1->mNetWorkedFireStateNode.mPath.mCount >= 0 )
  {
    v10 = v1->mNetWorkedFireStateNode.mPath.mData.mOffset;
    if ( v10 && (UFG::qOffset64<ActionID *> *)((char *)&v9->mPath.mData + v10) )
    {
      v11 = v1->mNetWorkedFireStateNode.mPath.mData.mOffset;
      if ( v11 )
        v12 = (char *)&v1->mNetWorkedFireStateNode.mPath.mData + v11;
      else
        v12 = 0i64;
      operator delete[](v12);
    }
    v1->mNetWorkedFireStateNode.mPath.mData.mOffset = 0i64;
    v9->mPath.mCount &= 0x80000000;
  }
  v13 = v2->mPrev;
  v14 = v2->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimObjectPropertiesComponent::~SimObjectPropertiesComponent((UFG::SimObjectPropertiesComponent *)&v1->vfptr);
}

// File Line: 527
// RVA: 0x546F90
UFG::SimComponent *__fastcall UFG::SimObjectWeaponPropertiesComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *v11; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *v13; // rdx
  unsigned __int16 v14; // cx
  unsigned int v15; // ebx
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_WeaponProperties::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0xE8ui64, "SimObjectWeaponPropertiesComponent", 0i64, 1u);
  if ( v10 )
  {
    v11 = v3->mpWritableProperties;
    if ( !v11 )
      v11 = v3->mpConstProperties;
    UFG::SimObjectWeaponPropertiesComponent::SimObjectWeaponPropertiesComponent(
      (UFG::SimObjectWeaponPropertiesComponent *)v10,
      v3->m_NameUID,
      v11,
      (component_WeaponProperties *)v7);
    v6 = v12;
  }
  v13 = v3->m_pSimObject;
  v14 = v13->m_Flags;
  if ( (v14 >> 14) & 1 || (v14 & 0x8000u) != 0 || !((v14 >> 13) & 1) )
    v15 = -1;
  else
    v15 = 4;
  UFG::SimObjectModifier::SimObjectModifier(&v16, v13, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v6, v15);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
  return v6;
}

// File Line: 543
// RVA: 0x542E50
void __fastcall UFG::SimObjectWeaponPropertiesComponent::PreloadAccessories(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::qSymbol *v1; // rcx
  UFG::qPropertySet *v2; // rbx
  UFG::ObjectResourceManager *v3; // rax

  this->mAccessoriesPreloaded = 1;
  v1 = &this->mMagazineType;
  if ( v1->mUID != UFG::gNullQSymbol.mUID )
  {
    v2 = UFG::PropertySetManager::FindPropertySet(v1);
    v3 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::PreLoadCriticalResource(v3, v2);
  }
}

// File Line: 557
// RVA: 0x558600
void __fastcall UFG::SimObjectWeaponPropertiesComponent::UnloadAccessories(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::qSymbol *v1; // rcx
  UFG::qPropertySet *v2; // rbx
  UFG::ObjectResourceManager *v3; // rax

  this->mAccessoriesPreloaded = 0;
  v1 = &this->mMagazineType;
  if ( v1->mUID != UFG::gNullQSymbol.mUID )
  {
    v2 = UFG::PropertySetManager::FindPropertySet(v1);
    v3 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::ReleaseCriticalResource(v3, v2);
  }
}

// File Line: 571
// RVA: 0x53E8E0
void __fastcall UFG::SimObjectWeaponPropertiesComponent::OnAttach(UFG::SimObjectWeaponPropertiesComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObjectWeaponPropertiesComponent *v2; // rbx
  UFG::WeaponManager *v3; // rax

  v2 = this;
  UFG::SimObjectPropertiesComponent::OnAttach((UFG::SimObjectPropertiesComponent *)&this->vfptr, pObject);
  v2->mLastOwner = 0;
  v3 = UFG::WeaponManager::Instance();
  UFG::WeaponManager::AddWeapon(v3, v2);
}

// File Line: 584
// RVA: 0x55C5A0
void __fastcall UFG::SimObjectWeaponPropertiesComponent::Update(UFG::SimObjectWeaponPropertiesComponent *this, float delta_sec)
{
  UFG::SimObjectWeaponPropertiesComponent *v2; // rbx
  char v3; // bp
  char v4; // di
  float v5; // xmm6_4
  char v6; // r15
  bool v7; // r12
  char v8; // al
  UFG::SimObject *v9; // rsi
  bool v10; // r14
  UFG::TransformNodeComponent *v11; // rsi
  int v12; // xmm1_4
  int v13; // xmm2_4
  float v14; // xmm0_4
  bool v15; // si
  unsigned int i; // edi
  unsigned int j; // edi
  float v18; // [rsp+20h] [rbp-38h]
  int v19; // [rsp+24h] [rbp-34h]
  int v20; // [rsp+28h] [rbp-30h]

  v2 = this;
  v3 = 0;
  v4 = 0;
  v5 = delta_sec;
  this->mLastBulletImpactStimulusTimer = delta_sec + this->mLastBulletImpactStimulusTimer;
  v6 = UFG::SimObjectWeaponPropertiesComponent::IsOwned(this);
  v7 = v2->mWeaponTypeInfo->mFireModes[v2->mFireMode]->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID;
  v8 = ((__int64 (*)(void))UFG::TiDo::m_pInstance->vfptr->HighSpeedMode)();
  v9 = v2->m_pSimObject;
  v10 = v8 == 0;
  if ( v9 )
  {
    v11 = v9->m_pTransformNodeComponent;
    if ( v11 )
    {
      if ( (UFG::TransformNodeComponent::UpdateWorldTransform(v11),
            v12 = LODWORD(v11->mWorldTransform.v3.y),
            v13 = LODWORD(v11->mWorldTransform.v3.z),
            v18 = v11->mWorldTransform.v3.x,
            v19 = v12,
            v20 = v13,
            v14 = UFG::TiDo::Distance2FromListener(UFG::TiDo::m_pInstance, 0, (UFG::qVector3 *)&v18),
            v2->mWeaponTypeInfo->mFireModes[v2->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID)
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
  v15 = (v6 && v3 || v4) && (!v7 || v10);
  if ( v2->mUnloadTimeOut < 3.0 )
  {
    if ( v2->mSoundBankLoadedId )
      goto LABEL_29;
  }
  else if ( v2->mSoundBankLoadedId )
  {
    if ( v2->mAccessoriesPreloaded )
      UFG::SimObjectWeaponPropertiesComponent::UnloadAccessories(v2);
    for ( i = 0; i < v2->mWeaponTypeInfo->mFireModes[v2->mFireMode]->mSoundbankIds.size; ++i )
      UFG::TiDo::UnloadWwiseBank(&v2->mWeaponTypeInfo->mFireModes[v2->mFireMode]->mSoundbankIds.p[i]);
    v2->mSoundBankLoadedId = 0;
    goto LABEL_29;
  }
  if ( !v15 )
    goto LABEL_32;
  if ( !v2->mAccessoriesPreloaded )
    UFG::SimObjectWeaponPropertiesComponent::PreloadAccessories(v2);
  for ( j = 0; j < v2->mWeaponTypeInfo->mFireModes[v2->mFireMode]->mSoundbankIds.size; ++j )
    UFG::TiDo::LoadWwiseBank(&v2->mWeaponTypeInfo->mFireModes[v2->mFireMode]->mSoundbankIds.p[j]);
  v2->mSoundBankLoadedId = v2->mWeaponTypeInfo->mFireModes[v2->mFireMode]->mSoundbankIds.p->mUID;
LABEL_29:
  if ( v15 )
  {
    if ( v2->mSoundBankLoadedId )
      v2->mUnloadTimeOut = 0.0;
    return;
  }
LABEL_32:
  if ( v2->mSoundBankLoadedId )
    v2->mUnloadTimeOut = v5 + v2->mUnloadTimeOut;
}

// File Line: 663
// RVA: 0x535270
bool __fastcall UFG::SimObjectWeaponPropertiesComponent::HasAmmo(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::SimObject *v1; // rcx
  unsigned __int16 v2; // dx
  unsigned int v3; // er8
  unsigned int v4; // er9
  signed __int64 v5; // rdx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // er9
  unsigned int v9; // er8
  unsigned int v10; // er9
  unsigned int v11; // er8
  unsigned int v12; // er9

  if ( this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mAmmoInventoryItem == eINVENTORY_ITEM_INVALID )
    return 0;
  v1 = this->m_pSimObject;
  if ( !v1 )
    return 0;
  v2 = v1->m_Flags;
  if ( (v2 >> 14) & 1 )
  {
    v3 = (unsigned int)v1[1].vfptr;
    v4 = v1->m_Components.size;
    if ( v3 < v4 )
    {
      v5 = (signed __int64)&v1->m_Components.p[v3];
      while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
           || UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF )
      {
        ++v3;
        v5 += 16i64;
        if ( v3 >= v4 )
          goto LABEL_9;
      }
LABEL_10:
      v6 = *(UFG::SimComponent **)v5;
      goto LABEL_33;
    }
    goto LABEL_9;
  }
  if ( (v2 & 0x8000u) != 0 )
  {
    v7 = (unsigned int)v1[1].vfptr;
    v8 = v1->m_Components.size;
    if ( v7 < v8 )
    {
      v5 = (signed __int64)&v1->m_Components.p[v7];
      while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
           || UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF )
      {
        ++v7;
        v5 += 16i64;
        if ( v7 >= v8 )
          goto LABEL_9;
      }
      goto LABEL_10;
    }
LABEL_9:
    v6 = 0i64;
    goto LABEL_33;
  }
  if ( (v2 >> 13) & 1 )
  {
    v9 = (unsigned int)v1[1].vfptr;
    v10 = v1->m_Components.size;
    if ( v9 < v10 )
    {
      v5 = (signed __int64)&v1->m_Components.p[v9];
      while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
           || UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF )
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
  if ( (v2 >> 12) & 1 )
  {
    v11 = (unsigned int)v1[1].vfptr;
    v12 = v1->m_Components.size;
    if ( v11 < v12 )
    {
      v5 = (signed __int64)&v1->m_Components.p[v11];
      while ( (*(_DWORD *)(v5 + 8) & 0xFE000000) != (UFG::GunComponent::_TypeUID & 0xFE000000)
           || UFG::GunComponent::_TypeUID & ~*(_DWORD *)(v5 + 8) & 0x1FFFFFF )
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
  v6 = UFG::SimObject::GetComponentOfType(v1, UFG::GunComponent::_TypeUID);
LABEL_33:
  if ( v6 )
    return *((_DWORD *)&v6[3].m_SafePointerList.mNode.mNext + HIDWORD(v6[2].m_SafePointerList.mNode.mPrev[10].mNext) + 1) > 0;
  return 0;
}

// File Line: 676
// RVA: 0x53B5F0
char __fastcall UFG::SimObjectWeaponPropertiesComponent::IsOwned(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::SimObject *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax
  unsigned int v4; // er8
  unsigned int v5; // er9
  signed __int64 v6; // rdx
  unsigned int v7; // er8
  unsigned int v8; // er9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rcx

  v1 = this->m_pSimObject;
  if ( !v1 )
    return 0;
  v2 = v1->m_Flags;
  if ( !((v2 >> 14) & 1) )
  {
    if ( (v2 & 0x8000u) != 0 )
    {
      v3 = v1->m_Components.p[20].m_pComponent;
      goto LABEL_22;
    }
    if ( (v2 >> 13) & 1 )
    {
      v4 = (unsigned int)v1[1].vfptr;
      v5 = v1->m_Components.size;
      if ( v4 < v5 )
      {
        v6 = (signed __int64)&v1->m_Components.p[v4];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
        {
          ++v4;
          v6 += 16i64;
          if ( v4 >= v5 )
            goto LABEL_12;
        }
LABEL_13:
        v3 = *(UFG::SimComponent **)v6;
        goto LABEL_22;
      }
    }
    else
    {
      if ( !((v2 >> 12) & 1) )
      {
        v3 = UFG::SimObject::GetComponentOfType(v1, UFG::TargetingSystemBaseComponent::_TypeUID);
        goto LABEL_22;
      }
      v7 = (unsigned int)v1[1].vfptr;
      v8 = v1->m_Components.size;
      if ( v7 < v8 )
      {
        v6 = (signed __int64)&v1->m_Components.p[v7];
        while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
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
    v3 = 0i64;
    goto LABEL_22;
  }
  v3 = v1->m_Components.p[20].m_pComponent;
LABEL_22:
  if ( !v3 )
    return 0;
  v9 = v3[1].m_BoundComponentHandles.mNode.mPrev;
  if ( v9 == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3[1].m_pSimObject )
    return 0;
  while ( (unsigned __int8)(LOBYTE(v9[3].mPrev) - 17) > 1u )
  {
    v9 = v9->mNext;
    if ( v9 == (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3[1].m_pSimObject )
      return 0;
  }
  return 1;
}

// File Line: 697
// RVA: 0x52ABC0
bool __fastcall UFG::SimObjectWeaponPropertiesComponent::GetBooleanValue(UFG::SimObjectWeaponPropertiesComponent *this, UFG::eSimObjectWeaponBooleanEnum eSimObjectWeaponBoolean)
{
  bool result; // al

  switch ( eSimObjectWeaponBoolean )
  {
    case 0:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneName.mUID != UFG::gNullQSymbolUC.mUID;
      break;
    case 1:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mProjectileSpawnBoneName.mUID == UFG::gNullQSymbolUC.mUID;
      break;
    case 2:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mAmmoInventoryItem != 0;
      break;
    case 3:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mThrownSpeed > 0.0;
      break;
    case 4:
      result = this->mWeaponTypeInfo->mFireModes[this->mFireMode]->mIsTwoHandedWeapon;
      break;
    case 5:
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
__int64 __fastcall UFG::SimObjectWeaponPropertiesComponent::GetProjectileSpawnBoneID(UFG::SimObjectWeaponPropertiesComponent *this)
{
  UFG::SimObjectWeaponPropertiesComponent *v1; // rdi
  UFG::FireModeInfo *v2; // rsi
  UFG::SimObjectProp *v3; // rcx
  Creature *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::CharacterAnimationComponent *v6; // rcx
  unsigned int v7; // edx
  unsigned int v8; // edx
  UFG::CharacterAnimationComponent *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  signed int v13; // eax

  v1 = this;
  v2 = this->mWeaponTypeInfo->mFireModes[this->mFireMode];
  if ( v2->mProjectileSpawnBoneID )
    return v1->mWeaponTypeInfo->mFireModes[v1->mFireMode]->mProjectileSpawnBoneID;
  v3 = (UFG::SimObjectProp *)this->m_pSimObject;
  v4 = 0i64;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::CharacterAnimationComponent *)v3->m_Components.p[9].m_pComponent;
      if ( !v6
        || (v7 = v6->m_TypeUID, (v7 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000)
        || UFG::CharacterAnimationComponent::_TypeUID & ~v7 & 0x1FFFFFF )
      {
LABEL_7:
        v6 = 0i64;
        goto LABEL_25;
      }
    }
    else
    {
      if ( (v5 & 0x8000u) != 0 )
      {
        v6 = (UFG::CharacterAnimationComponent *)v3->m_Components.p[9].m_pComponent;
        if ( v6 )
        {
          v8 = v6->m_TypeUID;
          if ( !((v8 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) )
          {
            if ( UFG::CharacterAnimationComponent::_TypeUID & ~v8 & 0x1FFFFFF )
              v6 = 0i64;
            goto LABEL_25;
          }
        }
        goto LABEL_7;
      }
      if ( (v5 >> 13) & 1 )
      {
        v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v3);
      }
      else
      {
        if ( (v5 >> 12) & 1 )
        {
          v10 = v3->mComponentTableEntryCount;
          v11 = v3->m_Components.size;
          if ( v10 < v11 )
          {
            v12 = (signed __int64)&v3->m_Components.p[v10];
            while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                 || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
            {
              ++v10;
              v12 += 16i64;
              if ( v10 >= v11 )
              {
                v6 = 0i64;
                goto LABEL_25;
              }
            }
            v6 = *(UFG::CharacterAnimationComponent **)v12;
            goto LABEL_25;
          }
          goto LABEL_7;
        }
        v9 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      v6 = v9;
    }
LABEL_25:
    if ( v6 )
      v4 = v6->mCreature;
  }
  if ( v4 )
  {
    if ( v4->mPose.mRigHandle.mData )
      v13 = Skeleton::GetBoneID(
              v4->mPose.mRigHandle.mUFGSkeleton,
              v1->mWeaponTypeInfo->mFireModes[v1->mFireMode]->mProjectileSpawnBoneName.mUID);
    else
      v13 = -1;
    v2->mProjectileSpawnBoneID = v13;
  }
  return v1->mWeaponTypeInfo->mFireModes[v1->mFireMode]->mProjectileSpawnBoneID;
}

