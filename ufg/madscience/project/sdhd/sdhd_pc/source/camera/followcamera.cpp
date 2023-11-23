// File Line: 82
// RVA: 0x14C1C00
hkSeekableStreamReader *UFG::_dynamic_initializer_for__TweakableOverrideParameters__()
{
  hkSeekableStreamReader *v0; // rbx
  int i; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &TweakableOverrideParameters;
  for ( i = 105; i >= 0; --i )
  {
    result = Assembly::GetRCX(v0);
    v0 = (hkSeekableStreamReader *)((char *)v0 + 316);
  }
  return result;
}

// File Line: 83
// RVA: 0x14C1C40
__int64 UFG::_dynamic_initializer_for__TweakableOverrideSymbols__()
{
  `eh vector constructor iterator(
    (char *)TweakableOverrideSymbols,
    4ui64,
    106,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__TweakableOverrideSymbols__);
}

// File Line: 89
// RVA: 0x14C8A40
__int64 UFG::_dynamic_initializer_for__gEventMountVehicle__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gEventMountVehicle, "EVT_MOUNT_VEHICLE", "\tCharacter gets on vehicle.\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gEventMountVehicle__);
}

// File Line: 90
// RVA: 0x14C89E0
__int64 UFG::_dynamic_initializer_for__gEventDisMountVehicle__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gEventDisMountVehicle, "EVT_DISMOUNT_VEHICLE", "\tCharacter gets off vehicle.\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gEventDisMountVehicle__);
}

// File Line: 91
// RVA: 0x14C8A70
__int64 UFG::_dynamic_initializer_for__gEventMountVehicleCamera__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gEventMountVehicleCamera,
    "EVT_MOUNT_VEHICLE_CAMERA",
    "\tCharacter gets on vehicle.\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gEventMountVehicleCamera__);
}

// File Line: 92
// RVA: 0x14C8A10
__int64 UFG::_dynamic_initializer_for__gEventDisMountVehicleCamera__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gEventDisMountVehicleCamera,
    "EVT_DISMOUNT_VEHICLE_CAMERA",
    "\tCharacter gets off vehicle.\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gEventDisMountVehicleCamera__);
}

// File Line: 93
// RVA: 0x14C89B0
__int64 UFG::_dynamic_initializer_for__gEventCameraZooming__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gEventCameraZooming,
    "EVT_CAMERA_ZOOMING",
    "\tThe camera is performing a zoom in or out operation\n");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gEventCameraZooming__);
}

// File Line: 119
// RVA: 0x14BFF20
__int64 dynamic_initializer_for__UFG::FollowCameraComponent::s_FollowCameraComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::FollowCameraComponent::s_FollowCameraComponentList__);
}

// File Line: 120
// RVA: 0x3C3E70
const char *__fastcall UFG::FollowCameraComponent::GetTypeName(UFG::FollowCameraComponent *this)
{
  return "FollowCameraComponent";
}

// File Line: 123
// RVA: 0x14BFD50
__int64 dynamic_initializer_for__UFG::FollowCameraComponent::mContextParameterSymbols__()
{
  `eh vector constructor iterator(
    (char *)UFG::FollowCameraComponent::mContextParameterSymbols,
    4ui64,
    15,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::FollowCameraComponent::mContextParameterSymbols__);
}

// File Line: 334
// RVA: 0x14BFD20
const char *dynamic_initializer_for__UFG::FollowCameraComponent::mContextParameterNames__()
{
  const char *result; // rax

  result = UFG::FollowCameraComponent::mDefaultOverrideName;
  qword_142072F58 = (__int64)UFG::FollowCameraComponent::mDefaultOverrideName;
  qword_142072F60 = (__int64)UFG::FollowCameraComponent::mDefaultOverrideName;
  qword_142072F68 = (__int64)UFG::FollowCameraComponent::mDefaultOverrideName;
  qword_142072F70 = (__int64)UFG::FollowCameraComponent::mDefaultOverrideName;
  return result;
}

// File Line: 344
// RVA: 0x3BB3B0
void __fastcall UFG::FollowCameraComponent::FollowCameraComponent(
        UFG::FollowCameraComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *mPrev; // rax
  float *p_z; // rax
  __int64 v5; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm4_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float w; // xmm3_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm3_4
  float mTweakFov; // xmm2_4
  float p0; // xmm1_4
  float mTweakEyeDurationV; // xmm2_4
  float mTweakEyeDurationH; // xmm0_4
  float v58; // xmm1_4
  float v59; // xmm1_4
  float v60; // xmm2_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  float v66; // xmm2_4
  float mTweakLookDurationV; // xmm1_4
  float mTweakLookDurationH; // xmm0_4
  float v69; // xmm2_4
  float v70; // xmm1_4
  float v71; // xmm2_4
  float v72; // xmm1_4
  float v73; // xmm2_4
  float v74; // xmm1_4
  float v75; // xmm2_4
  float v76; // xmm1_4
  float v77; // xmm2_4
  float mTweakVelocityDuration; // xmm0_4
  float v79; // xmm2_4
  float v80; // xmm1_4
  float v81; // xmm1_4
  float v82; // xmm2_4
  float v83; // xmm1_4
  float v84; // xmm2_4
  float v85; // xmm1_4
  float v86; // xmm2_4
  float v87; // xmm1_4
  float v88; // xmm2_4
  float v89; // xmm1_4
  float v90; // xmm2_4
  float v91; // xmm2_4
  float v92; // xmm0_4
  float v93; // xmm1_4
  float v94; // xmm1_4
  float v95; // xmm2_4
  float v96; // xmm1_4
  float v97; // xmm2_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  float v100; // xmm1_4
  float v101; // xmm2_4
  float v102; // xmm1_4
  float v103; // xmm0_4
  float v104; // xmm2_4
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm1_4
  float v108; // xmm2_4
  float v109; // xmm1_4
  float v110; // xmm2_4
  float v111; // xmm1_4
  float v112; // xmm2_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  fastdelegate::detail::GenericClass *RCX; // rax
  fastdelegate::detail::GenericClass *v116; // rax
  fastdelegate::detail::GenericClass *v117; // rax
  fastdelegate::detail::GenericClass *v118; // rax
  UFG::qVector3 v119; // [rsp+10h] [rbp-21h] BYREF
  UFG::qVector3 v120; // [rsp+20h] [rbp-11h] BYREF
  UFG::qVector3 v121; // [rsp+30h] [rbp-1h] BYREF
  fastdelegate::FastDelegate1<UFG::Event *,void> v122[5]; // [rsp+40h] [rbp+Fh] BYREF

  UFG::GameCameraComponent::GameCameraComponent(this, name_uid);
  this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mPrev = &this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>;
  this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mNext = &this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FollowCameraComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>(&this->mTarget);
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->mEnemyTarget);
  this->mFov.mDuration = 0.0099999998;
  this->mEye.mDuration.x = 0.0099999998;
  this->mEye.mDuration.y = 0.0099999998;
  this->mEye.mDuration.z = 0.0099999998;
  this->mLook.mDuration.x = 0.0099999998;
  this->mLook.mDuration.y = 0.0099999998;
  this->mLook.mDuration.z = 0.0099999998;
  this->mVelocity.mDuration.x = 0.0099999998;
  this->mVelocity.mDuration.y = 0.0099999998;
  this->mVelocity.mDuration.z = 0.0099999998;
  this->mOffsetLook.mDuration.x = 0.0099999998;
  this->mOffsetLook.mDuration.y = 0.0099999998;
  this->mOffsetLook.mDuration.z = 0.0099999998;
  this->mOffsetEye.mDuration.x = 0.0099999998;
  this->mOffsetEye.mDuration.y = 0.0099999998;
  this->mOffsetEye.mDuration.z = 0.0099999998;
  this->mRecoilEye.mDuration.x = 0.0099999998;
  this->mRecoilEye.mDuration.y = 0.0099999998;
  this->mRecoilEye.mDuration.z = 0.0099999998;
  this->mEyeNoise.bCircular = 0;
  v121.x = 0.5;
  v121.y = 0.5;
  v121.z = 0.5;
  v122[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)0x3F8000003F800000i64;
  LODWORD(v122[0].m_Closure.m_pFunction) = 1065353216;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetParameters(
    &this->mEyeNoise,
    6,
    (UFG::qVector3 *)v122,
    &v121,
    &v120,
    &v119);
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::qNoise<UFG::qVector3,UFG::qVector3>(&this->mLookNoise);
  this->mHorizCompTargetSpeedWindowMaxTimespan = 1.0;
  *(_QWORD *)&this->mHorizCompTargetSpeedWindow.m_MaxTimespan = 0i64;
  this->mHorizCompTargetSpeedWindow.m_BufferSize = 0;
  this->mHorizCompTargetSpeedWindow.m_pBuffer = 0i64;
  this->mHorizCompTargetSpeedWindow.m_pMemoryPool = 0i64;
  *(_QWORD *)&this->mHorizCompTargetSpeedWindow.m_StartIndex = 0i64;
  this->mHorizCompTargetSpeedWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->mHorizCompTargetSpeedWindow.m_RunningSum, 0, 4u);
  UFG::qAverageWindow<float>::SetMaxTimespan(
    &this->mHorizCompTargetSpeedWindow,
    COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
    30.0);
  this->mHorizCompOffset.mDuration = 0.0099999998;
  this->mAimEye.mDuration.x = 0.0099999998;
  this->mAimEye.mDuration.y = 0.0099999998;
  this->mAimEye.mDuration.z = 0.0099999998;
  this->mAimLook.mDuration.x = 0.0099999998;
  this->mAimLook.mDuration.y = 0.0099999998;
  this->mAimLook.mDuration.z = 0.0099999998;
  mPrev = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mPrev;
  UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>;
  this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mNext = (UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList;
  UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mPrev = &this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>;
  UFG::SimComponent::AddType(this, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID, "FollowCameraComponent");
  gTransitionString[0] = 0;
  this->mNumMeleeAttackers = 0;
  p_z = &this->mMeleeAttackerPositions[0].z;
  v5 = 16i64;
  do
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    *(p_z - 2) = UFG::qVector3::msZero.x;
    *(p_z - 1) = y;
    *p_z = z;
    p_z += 3;
    --v5;
  }
  while ( v5 );
  this->mDofFarFocalDist = 20.0;
  this->mEyeNoise.tRangeMin.x = -0.1;
  this->mEyeNoise.tRangeMin.y = -0.1;
  this->mEyeNoise.tRangeMin.z = -0.1;
  this->mEyeNoise.tRangeMax.x = 0.1;
  this->mEyeNoise.tRangeMax.y = 0.1;
  this->mEyeNoise.tRangeMax.z = 0.1;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&this->mEyeNoise);
  this->mLookNoise.tRangeMin.x = -0.2;
  this->mLookNoise.tRangeMin.y = -0.2;
  this->mLookNoise.tRangeMin.z = -0.2;
  this->mLookNoise.tRangeMax.x = 0.2;
  this->mLookNoise.tRangeMax.y = 0.2;
  this->mLookNoise.tRangeMax.z = 0.2;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&this->mLookNoise);
  v8 = UFG::qVector3::msDirUp.y;
  v9 = UFG::qVector3::msDirUp.z;
  this->mUpFrom.x = UFG::qVector3::msDirUp.x;
  this->mUpFrom.y = v8;
  this->mUpFrom.z = v9;
  UFG::qAverageWindow<float>::SetTimespan(
    &this->mHorizCompTargetSpeedWindow,
    COERCE_DOUBLE((unsigned __int64)LODWORD(UFG::FollowCameraComponent::rHorizCompSpeedWindowTimespan)),
    30.0);
  this->mHorizCompTargetSpeedSubmittedTimespan = UFG::FollowCameraComponent::rHorizCompSpeedWindowTimespan;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  this->mAimOrigin.x = UFG::qVector3::msZero.x;
  this->mAimOrigin.y = v10;
  this->mAimOrigin.z = v11;
  this->mSafeRadius = 0.0;
  v12 = UFG::FollowCameraComponent::rOffsetLookDuration;
  if ( UFG::FollowCameraComponent::rOffsetLookDuration <= 0.0099999998 )
    v13 = FLOAT_0_0099999998;
  else
    v13 = UFG::FollowCameraComponent::rOffsetLookDuration;
  if ( UFG::FollowCameraComponent::rOffsetLookDuration <= 0.0099999998 )
    v14 = FLOAT_0_0099999998;
  else
    v14 = UFG::FollowCameraComponent::rOffsetLookDuration;
  if ( UFG::FollowCameraComponent::rOffsetLookDuration <= 0.0099999998 )
    v12 = FLOAT_0_0099999998;
  this->mOffsetLook.mDuration.x = v12;
  this->mOffsetLook.mDuration.y = v14;
  this->mOffsetLook.mDuration.z = v13;
  *(_QWORD *)&this->mOffsetLook.mParameter.x = 0i64;
  this->mOffsetLook.mParameter.z = 0.0;
  v15 = UFG::qVector3::msZero.y;
  v16 = UFG::qVector3::msZero.z;
  this->mOffsetLook.v0.x = UFG::qVector3::msZero.x;
  this->mOffsetLook.v0.y = v15;
  this->mOffsetLook.v0.z = v16;
  v17 = UFG::qVector3::msZero.y;
  v18 = UFG::qVector3::msZero.z;
  this->mOffsetLook.v1.x = UFG::qVector3::msZero.x;
  this->mOffsetLook.v1.y = v17;
  this->mOffsetLook.v1.z = v18;
  v19 = UFG::qVector3::msZero.y;
  v20 = UFG::qVector3::msZero.z;
  this->mOffsetLook.p0.x = UFG::qVector3::msZero.x;
  this->mOffsetLook.p0.y = v19;
  this->mOffsetLook.p0.z = v20;
  v21 = UFG::qVector3::msZero.y;
  v22 = UFG::qVector3::msZero.z;
  this->mOffsetLook.p1.x = UFG::qVector3::msZero.x;
  this->mOffsetLook.p1.y = v21;
  this->mOffsetLook.p1.z = v22;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetLook);
  v23 = UFG::FollowCameraComponent::rOffsetEyeDuration;
  if ( UFG::FollowCameraComponent::rOffsetEyeDuration <= 0.0099999998 )
    v24 = FLOAT_0_0099999998;
  else
    v24 = UFG::FollowCameraComponent::rOffsetEyeDuration;
  if ( UFG::FollowCameraComponent::rOffsetEyeDuration <= 0.0099999998 )
    v25 = FLOAT_0_0099999998;
  else
    v25 = UFG::FollowCameraComponent::rOffsetEyeDuration;
  if ( UFG::FollowCameraComponent::rOffsetEyeDuration <= 0.0099999998 )
    v23 = FLOAT_0_0099999998;
  this->mOffsetEye.mDuration.x = v23;
  this->mOffsetEye.mDuration.y = v25;
  this->mOffsetEye.mDuration.z = v24;
  *(_QWORD *)&this->mOffsetEye.mParameter.x = 0i64;
  this->mOffsetEye.mParameter.z = 0.0;
  v26 = UFG::qVector3::msZero.y;
  v27 = UFG::qVector3::msZero.z;
  this->mOffsetEye.v0.x = UFG::qVector3::msZero.x;
  this->mOffsetEye.v0.y = v26;
  this->mOffsetEye.v0.z = v27;
  v28 = UFG::qVector3::msZero.y;
  v29 = UFG::qVector3::msZero.z;
  this->mOffsetEye.v1.x = UFG::qVector3::msZero.x;
  this->mOffsetEye.v1.y = v28;
  this->mOffsetEye.v1.z = v29;
  v30 = UFG::qVector3::msZero.y;
  v31 = UFG::qVector3::msZero.z;
  this->mOffsetEye.p0.x = UFG::qVector3::msZero.x;
  this->mOffsetEye.p0.y = v30;
  this->mOffsetEye.p0.z = v31;
  v32 = UFG::qVector3::msZero.y;
  v33 = UFG::qVector3::msZero.z;
  this->mOffsetEye.p1.x = UFG::qVector3::msZero.x;
  this->mOffsetEye.p1.y = v32;
  this->mOffsetEye.p1.z = v33;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetEye);
  this->mMaxRadiusOverrideEnabled = 0;
  this->mMaxRadiusOverrideParam = 0.0;
  this->mMaxRadiusOverride = 5.0;
  this->mRiseOverrideEnabled = 0;
  this->mRiseOverrideParam = 0.0;
  this->mRiseOverride = 2.0;
  *(_WORD *)&this->mAutoFrameEnabled = 1;
  this->mAutoFrameFarthestAttackerDist = 0.0;
  this->mAutoFrameSnapNextAttackerDist = 0;
  *(_QWORD *)&this->mRecoilAngle = 0i64;
  v34 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v35 = FLOAT_0_0099999998;
  else
    v35 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v36 = FLOAT_0_0099999998;
  else
    v36 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v34 = FLOAT_0_0099999998;
  this->mRecoilEye.mDuration.x = v34;
  this->mRecoilEye.mDuration.y = v36;
  this->mRecoilEye.mDuration.z = v35;
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  v37 = UFG::qVector3::msZero.y;
  v38 = UFG::qVector3::msZero.z;
  this->mRecoilEye.v0.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.v0.y = v37;
  this->mRecoilEye.v0.z = v38;
  v39 = UFG::qVector3::msZero.y;
  v40 = UFG::qVector3::msZero.z;
  this->mRecoilEye.v1.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.v1.y = v39;
  this->mRecoilEye.v1.z = v40;
  v41 = UFG::qVector3::msZero.y;
  v42 = UFG::qVector3::msZero.z;
  this->mRecoilEye.p0.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.p0.y = v41;
  this->mRecoilEye.p0.z = v42;
  v43 = UFG::qVector3::msZero.y;
  v44 = UFG::qVector3::msZero.z;
  this->mRecoilEye.p1.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.p1.y = v43;
  this->mRecoilEye.p1.z = v44;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  v45 = UFG::FollowCameraComponent::rHorizCompDurationAttack;
  if ( UFG::FollowCameraComponent::rHorizCompDurationAttack <= 0.0099999998 )
    v45 = FLOAT_0_0099999998;
  this->mHorizCompOffset.mDuration = v45;
  this->mHorizCompOffset.mParameter = 0.0;
  *(_QWORD *)&this->mHorizCompOffset.v0 = 0i64;
  *(_QWORD *)&this->mHorizCompOffset.p0 = 0i64;
  if ( v45 <= 0.0099999998 )
    v45 = FLOAT_0_0099999998;
  this->mHorizCompOffset.A = (float)(v45 * 0.0) / (float)((float)(v45 * v45) * v45);
  this->mHorizCompOffset.B = COERCE_FLOAT(COERCE_UNSIGNED_INT(v45 * 0.0) ^ _xmm[0]) / (float)(v45 * v45);
  *(_QWORD *)&this->mHorizCompOffset.C = 0i64;
  this->mTransitionTimeOverride = -1.0;
  this->mTransitionParamRateEye = 1.0;
  *(_QWORD *)&this->mTransitionParamRateOrient = 1065353216i64;
  this->mTransitionParamOrient = 0.0;
  this->mTransitionParamRateSuppEye = 1.0;
  *(_QWORD *)&this->mTransitionParamRateSuppLook = 1065353216i64;
  *(_QWORD *)&this->mTransitionParamSuppLook = 0i64;
  this->mTransitionSupplimentaryDuration = 0.0;
  v46 = UFG::qVector3::msZero.y;
  v47 = UFG::qVector3::msZero.z;
  this->mTransitionFromEye.x = UFG::qVector3::msZero.x;
  this->mTransitionFromEye.y = v46;
  this->mTransitionFromEye.z = v47;
  v48 = UFG::qQuaternion::msUnity.y;
  v49 = UFG::qQuaternion::msUnity.z;
  w = UFG::qQuaternion::msUnity.w;
  this->mTransitionFromOri.x = UFG::qQuaternion::msUnity.x;
  this->mTransitionFromOri.y = v48;
  this->mTransitionFromOri.z = v49;
  this->mTransitionFromOri.w = w;
  this->mTransitionFromLen = 0.0;
  v51 = UFG::qVector4::msUnity.y;
  v52 = UFG::qVector4::msUnity.z;
  v53 = UFG::qVector4::msUnity.w;
  this->mCharacterSpacePos.x = UFG::qVector4::msUnity.x;
  this->mCharacterSpacePos.y = v51;
  this->mCharacterSpacePos.z = v52;
  this->mCharacterSpacePos.w = v53;
  this->mEnableCharacterSpaceSmoothing = 0;
  this->mTimeShouldBeInVehicleCamButAreNot = 0.0;
  this->mMouseBoom.x = 0.0;
  this->mMouseBoom.y = -1.0;
  this->mMouseBoom.z = 0.0;
  this->mMouseBoomSet = 0;
  UFG::qMemSet(&this->mOldParams, 0, 0x13Cu);
  UFG::qMemSet(&this->mBlendedParams, 0, 0x13Cu);
  UFG::FollowCameraComponent::LoadContextParameters(this);
  UFG::FollowCameraComponent::SetContext(this, eFOLLOW_CONTEXT_WALK, 1);
  *(_QWORD *)&this->mFov.mDuration = 1065353216i64;
  *(_QWORD *)&this->mFov.v0 = 0i64;
  this->mFov.p0 = this->mBlendedParams.mTweakFov;
  mTweakFov = this->mBlendedParams.mTweakFov;
  this->mFov.p1 = mTweakFov;
  p0 = this->mFov.p0;
  this->mFov.A = (float)(p0 - mTweakFov) * 2.0;
  this->mFov.B = (float)(mTweakFov - p0) * 3.0;
  this->mFov.C = 0.0;
  this->mFov.D = p0;
  mTweakEyeDurationV = this->mBlendedParams.mTweakEyeDurationV;
  mTweakEyeDurationH = this->mBlendedParams.mTweakEyeDurationH;
  if ( mTweakEyeDurationV <= 0.0099999998 )
    mTweakEyeDurationV = FLOAT_0_0099999998;
  if ( mTweakEyeDurationH <= 0.0099999998 )
    v58 = FLOAT_0_0099999998;
  else
    v58 = this->mBlendedParams.mTweakEyeDurationH;
  if ( mTweakEyeDurationH <= 0.0099999998 )
    mTweakEyeDurationH = FLOAT_0_0099999998;
  this->mEye.mDuration.x = mTweakEyeDurationH;
  this->mEye.mDuration.y = v58;
  this->mEye.mDuration.z = mTweakEyeDurationV;
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  v59 = UFG::qVector3::msZero.y;
  v60 = UFG::qVector3::msZero.z;
  this->mEye.v0.x = UFG::qVector3::msZero.x;
  this->mEye.v0.y = v59;
  this->mEye.v0.z = v60;
  v61 = UFG::qVector3::msZero.y;
  v62 = UFG::qVector3::msZero.z;
  this->mEye.v1.x = UFG::qVector3::msZero.x;
  this->mEye.v1.y = v61;
  this->mEye.v1.z = v62;
  v63 = UFG::qVector3::msZero.y;
  v64 = UFG::qVector3::msZero.z;
  this->mEye.p0.x = UFG::qVector3::msZero.x;
  this->mEye.p0.y = v63;
  this->mEye.p0.z = v64;
  v65 = UFG::qVector3::msZero.y;
  v66 = UFG::qVector3::msZero.z;
  this->mEye.p1.x = UFG::qVector3::msZero.x;
  this->mEye.p1.y = v65;
  this->mEye.p1.z = v66;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  mTweakLookDurationV = this->mBlendedParams.mTweakLookDurationV;
  mTweakLookDurationH = this->mBlendedParams.mTweakLookDurationH;
  if ( mTweakLookDurationV <= 0.0099999998 )
    mTweakLookDurationV = FLOAT_0_0099999998;
  if ( mTweakLookDurationH <= 0.0099999998 )
    v69 = FLOAT_0_0099999998;
  else
    v69 = this->mBlendedParams.mTweakLookDurationH;
  if ( mTweakLookDurationH <= 0.0099999998 )
    mTweakLookDurationH = FLOAT_0_0099999998;
  this->mLook.mDuration.x = mTweakLookDurationH;
  this->mLook.mDuration.y = v69;
  this->mLook.mDuration.z = mTweakLookDurationV;
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  v70 = UFG::qVector3::msZero.y;
  v71 = UFG::qVector3::msZero.z;
  this->mLook.v0.x = UFG::qVector3::msZero.x;
  this->mLook.v0.y = v70;
  this->mLook.v0.z = v71;
  v72 = UFG::qVector3::msZero.y;
  v73 = UFG::qVector3::msZero.z;
  this->mLook.v1.x = UFG::qVector3::msZero.x;
  this->mLook.v1.y = v72;
  this->mLook.v1.z = v73;
  v74 = UFG::qVector3::msZero.y;
  v75 = UFG::qVector3::msZero.z;
  this->mLook.p0.x = UFG::qVector3::msZero.x;
  this->mLook.p0.y = v74;
  this->mLook.p0.z = v75;
  v76 = UFG::qVector3::msZero.y;
  v77 = UFG::qVector3::msZero.z;
  this->mLook.p1.x = UFG::qVector3::msZero.x;
  this->mLook.p1.y = v76;
  this->mLook.p1.z = v77;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  mTweakVelocityDuration = this->mBlendedParams.mTweakVelocityDuration;
  if ( mTweakVelocityDuration <= 0.0099999998 )
    v79 = FLOAT_0_0099999998;
  else
    v79 = this->mBlendedParams.mTweakVelocityDuration;
  if ( mTweakVelocityDuration <= 0.0099999998 )
    v80 = FLOAT_0_0099999998;
  else
    v80 = this->mBlendedParams.mTweakVelocityDuration;
  if ( mTweakVelocityDuration <= 0.0099999998 )
    mTweakVelocityDuration = FLOAT_0_0099999998;
  this->mVelocity.mDuration.x = mTweakVelocityDuration;
  this->mVelocity.mDuration.y = v80;
  this->mVelocity.mDuration.z = v79;
  *(_QWORD *)&this->mVelocity.mParameter.x = 0i64;
  this->mVelocity.mParameter.z = 0.0;
  v81 = UFG::qVector3::msZero.y;
  v82 = UFG::qVector3::msZero.z;
  this->mVelocity.v0.x = UFG::qVector3::msZero.x;
  this->mVelocity.v0.y = v81;
  this->mVelocity.v0.z = v82;
  v83 = UFG::qVector3::msZero.y;
  v84 = UFG::qVector3::msZero.z;
  this->mVelocity.v1.x = UFG::qVector3::msZero.x;
  this->mVelocity.v1.y = v83;
  this->mVelocity.v1.z = v84;
  v85 = UFG::qVector3::msZero.y;
  v86 = UFG::qVector3::msZero.z;
  this->mVelocity.p0.x = UFG::qVector3::msZero.x;
  this->mVelocity.p0.y = v85;
  this->mVelocity.p0.z = v86;
  v87 = UFG::qVector3::msZero.y;
  v88 = UFG::qVector3::msZero.z;
  this->mVelocity.p1.x = UFG::qVector3::msZero.x;
  this->mVelocity.p1.y = v87;
  this->mVelocity.p1.z = v88;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mVelocity);
  *(_QWORD *)&this->mBlend = 0i64;
  *(_DWORD *)&this->mSnapNext = 16843008;
  *(_DWORD *)&this->mFreeAiming = 0x1000000;
  this->bUpdateFromAimComp = 0;
  this->mOrbitSquish = 1.0;
  this->mHeightAboveGround = 1.0;
  this->mLatitudeMin = -0.94247788;
  v89 = this->mCamera.mTransformation.v2.y;
  v90 = this->mCamera.mTransformation.v2.z;
  this->mControllerForward.x = this->mCamera.mTransformation.v2.x;
  this->mControllerForward.y = v89;
  this->mControllerForward.z = v90;
  *(_QWORD *)&this->mPassThroughTimer1 = 0i64;
  *(_QWORD *)&this->mGotoRiseElaspedTime = 0i64;
  *(_QWORD *)&this->mGotoRiseRate = 0i64;
  this->mGotoAngleCollisionQueued = 0;
  *(_QWORD *)&this->mGotoAngleCollisionQueuedWallDist = 1056964608i64;
  this->mGotoAngleLocalSpace = 1;
  *(_QWORD *)&this->mGotoAnglePatience = 0i64;
  *(_QWORD *)&this->mGotoAngle = 0i64;
  *(_QWORD *)&this->mGotoRadiusPatience = 0i64;
  this->mGotoRadius = 0.0;
  this->mConstrainYaw = 0;
  *(_QWORD *)&this->mConstrainYawMin = 0i64;
  this->mConstrainYawRate = 0.0;
  this->bAimUseEyeLook = 0;
  this->rAimParameter = 0.0;
  v91 = this->mBlendedParams.mTweakEyeDurationV;
  v92 = this->mBlendedParams.mTweakEyeDurationH;
  if ( v91 <= 0.0099999998 )
    v91 = FLOAT_0_0099999998;
  if ( v92 <= 0.0099999998 )
    v93 = FLOAT_0_0099999998;
  else
    v93 = this->mBlendedParams.mTweakEyeDurationH;
  if ( v92 <= 0.0099999998 )
    v92 = FLOAT_0_0099999998;
  this->mAimEye.mDuration.x = v92;
  this->mAimEye.mDuration.y = v93;
  this->mAimEye.mDuration.z = v91;
  *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
  this->mAimEye.mParameter.z = 0.0;
  v94 = UFG::qVector3::msZero.y;
  v95 = UFG::qVector3::msZero.z;
  this->mAimEye.v0.x = UFG::qVector3::msZero.x;
  this->mAimEye.v0.y = v94;
  this->mAimEye.v0.z = v95;
  v96 = UFG::qVector3::msZero.y;
  v97 = UFG::qVector3::msZero.z;
  this->mAimEye.v1.x = UFG::qVector3::msZero.x;
  this->mAimEye.v1.y = v96;
  this->mAimEye.v1.z = v97;
  v98 = UFG::qVector3::msZero.y;
  v99 = UFG::qVector3::msZero.z;
  this->mAimEye.p0.x = UFG::qVector3::msZero.x;
  this->mAimEye.p0.y = v98;
  this->mAimEye.p0.z = v99;
  v100 = UFG::qVector3::msZero.y;
  v101 = UFG::qVector3::msZero.z;
  this->mAimEye.p1.x = UFG::qVector3::msZero.x;
  this->mAimEye.p1.y = v100;
  this->mAimEye.p1.z = v101;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
  v102 = this->mBlendedParams.mTweakLookDurationV;
  v103 = this->mBlendedParams.mTweakLookDurationH;
  if ( v102 <= 0.0099999998 )
    v102 = FLOAT_0_0099999998;
  if ( v103 <= 0.0099999998 )
    v104 = FLOAT_0_0099999998;
  else
    v104 = this->mBlendedParams.mTweakLookDurationH;
  if ( v103 <= 0.0099999998 )
    v103 = FLOAT_0_0099999998;
  this->mAimLook.mDuration.x = v103;
  this->mAimLook.mDuration.y = v104;
  this->mAimLook.mDuration.z = v102;
  *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
  this->mAimLook.mParameter.z = 0.0;
  v105 = UFG::qVector3::msZero.y;
  v106 = UFG::qVector3::msZero.z;
  this->mAimLook.v0.x = UFG::qVector3::msZero.x;
  this->mAimLook.v0.y = v105;
  this->mAimLook.v0.z = v106;
  v107 = UFG::qVector3::msZero.y;
  v108 = UFG::qVector3::msZero.z;
  this->mAimLook.v1.x = UFG::qVector3::msZero.x;
  this->mAimLook.v1.y = v107;
  this->mAimLook.v1.z = v108;
  v109 = UFG::qVector3::msZero.y;
  v110 = UFG::qVector3::msZero.z;
  this->mAimLook.p0.x = UFG::qVector3::msZero.x;
  this->mAimLook.p0.y = v109;
  this->mAimLook.p0.z = v110;
  v111 = UFG::qVector3::msZero.y;
  v112 = UFG::qVector3::msZero.z;
  this->mAimLook.p1.x = UFG::qVector3::msZero.x;
  this->mAimLook.p1.y = v111;
  this->mAimLook.p1.z = v112;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
  *(_QWORD *)&this->mAimDurationSupplimentary = 0i64;
  this->mMouseBucketY = 0.0;
  v113 = UFG::qVector3::msZero.y;
  v114 = UFG::qVector3::msZero.z;
  this->mAimDeadZoneCentre.x = UFG::qVector3::msZero.x;
  this->mAimDeadZoneCentre.y = v113;
  this->mAimDeadZoneCentre.z = v114;
  this->mAimDeadZoneRadius = -1.0;
  this->mAimDeadZoneTimer = 0.0;
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v122[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::FollowCameraComponent::FollowCameraEventHandler;
  v122[0].m_Closure.m_pthis = RCX;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, v122, 0x4B543385u, 0i64, 0);
  v116 = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v122[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::FollowCameraComponent::FollowCameraEventHandler;
  v122[0].m_Closure.m_pthis = v116;
  UFG::EventDispatcher::Register(&UFG::EventDispatcher::mInstance, v122, 0xB7295A22, 0i64, 0);
  v117 = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v122[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::FollowCameraComponent::FollowCameraEventHandler;
  v122[0].m_Closure.m_pthis = v117;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    v122,
    UFG::gEventMountVehicleCamera.mUID,
    UFG::gEventMountVehicleCamera.mName,
    0);
  v118 = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v122[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::FollowCameraComponent::FollowCameraEventHandler;
  v122[0].m_Closure.m_pthis = v118;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    v122,
    UFG::gEventDisMountVehicleCamera.mUID,
    UFG::gEventDisMountVehicleCamera.mName,
    0);
  UFG::FollowCameraComponent::Snap(this);
  ++UFG::FollowCameraComponent::mNumFollowCameraInstances;
}

// File Line: 504
// RVA: 0x3BDD30
void __fastcall UFG::FollowCameraComponent::~FollowCameraComponent(UFG::FollowCameraComponent *this)
{
  fastdelegate::detail::GenericClass *RCX; // rax
  fastdelegate::detail::GenericClass *v3; // rax
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v4; // rbx
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *mPrev; // rcx
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *mNext; // rax
  UFG::qMemoryPool *m_pMemoryPool; // rcx
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v8; // rcx
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v9; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v10[2]; // [rsp+28h] [rbp-20h] BYREF

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FollowCameraComponent::`vftable;
  --UFG::FollowCameraComponent::mNumFollowCameraInstances;
  v10[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::FollowCameraComponent::FollowCameraEventHandler;
  v10[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v10, 0x4B543385u);
  v10[0].m_Closure.m_pthis = 0i64;
  v10[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::FollowCameraComponent::FollowCameraEventHandler;
  v10[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v10, 0xB7295A22);
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v10[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::FollowCameraComponent::FollowCameraEventHandler;
  v10[0].m_Closure.m_pthis = RCX;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v10, UFG::gEventMountVehicleCamera.mUID);
  v3 = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v10[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::FollowCameraComponent::FollowCameraEventHandler;
  v10[0].m_Closure.m_pthis = v3;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, v10, UFG::gEventDisMountVehicleCamera.mUID);
  if ( this == UFG::FollowCameraComponent::s_FollowCameraComponentpCurrentIterator )
    UFG::FollowCameraComponent::s_FollowCameraComponentpCurrentIterator = (UFG::FollowCameraComponent *)&this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mPrev[-78];
  v4 = &this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>;
  mPrev = this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mPrev;
  mNext = this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mPrev = &this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>;
  this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mNext = &this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>;
  m_pMemoryPool = this->mHorizCompTargetSpeedWindow.m_pMemoryPool;
  if ( m_pMemoryPool )
    UFG::qMemoryPool::Free(m_pMemoryPool, (char *)this->mHorizCompTargetSpeedWindow.m_pBuffer);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mEnemyTarget);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mTarget);
  v8 = v4->mPrev;
  v9 = this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v4->mPrev = v4;
  this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>::mNext = &this->UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent>;
  UFG::GameCameraComponent::~GameCameraComponent(this);
}

// File Line: 525
// RVA: 0x3CC950
void __fastcall UFG::FollowCameraComponent::SetForceSnapOnEvent(bool enable)
{
  gForceSnapOnEvent = enable;
}

// File Line: 532
// RVA: 0x3C5550
bool __fastcall UFG::FollowCameraComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentFollowCamera);
}

// File Line: 538
// RVA: 0x3C8140
UFG::FollowCameraComponent *__fastcall UFG::FollowCameraComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *scene_object_properties)
{
  unsigned int m_NameUID; // ebx
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h] BYREF

  m_NameUID = scene_object_properties->m_NameUID;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x21C0ui64, "FollowCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::FollowCameraComponent::FollowCameraComponent((UFG::FollowCameraComponent *)v4, m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, scene_object_properties->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return (UFG::FollowCameraComponent *)v6;
}

// File Line: 547
// RVA: 0x3C5B10
void __fastcall UFG::FollowCameraComponent::InitBlendedParams(UFG::FollowCameraComponent *this)
{
  __int64 mContext; // rcx
  bool v3; // zf

  UFG::FollowCameraComponent::FollowParams::operator=(&this->mOldParams, &this->mBlendedParams);
  mContext = this->mContext;
  v3 = !this->mBlendedParams.mTweakBlendDurations;
  this->mBlendedParams.mSrcOrientation = this->mContextParameters[mContext].mSrcOrientation;
  this->mBlendedParams.mSrcPosition = this->mContextParameters[mContext].mSrcPosition;
  if ( v3 )
  {
    this->mBlendedParams.mTweakLookDurationH = this->mContextParameters[mContext].mTweakLookDurationH;
    this->mBlendedParams.mTweakLookDurationV = this->mContextParameters[mContext].mTweakLookDurationV;
    this->mBlendedParams.mTweakEyeDurationH = this->mContextParameters[mContext].mTweakEyeDurationH;
    this->mBlendedParams.mTweakEyeDurationV = this->mContextParameters[mContext].mTweakEyeDurationV;
    this->mBlendedParams.mTweakFovDuration = this->mContextParameters[mContext].mTweakFovDuration;
  }
  if ( !this->mOldParams.mTweakUseSyncBase )
    this->mBlendedParams.mTweakBaseOffset.z = this->mContextParameters[mContext].mTweakBaseOffset.z;
  this->mBlendedParams.mTweakUseSyncBase = this->mContextParameters[mContext].mTweakUseSyncBase;
  this->mBlendedParams.mUseInitRise = this->mContextParameters[mContext].mUseInitRise;
  this->mBlendedParams.mInitRise = this->mContextParameters[mContext].mInitRise;
  this->mBlendedParams.mInitRiseRate = this->mContextParameters[mContext].mInitRiseRate;
  this->mBlendedParams.mInitRisePatience = this->mContextParameters[mContext].mInitRisePatience;
  this->mBlendedParams.mUseInitRadius = this->mContextParameters[mContext].mUseInitRadius;
  this->mBlendedParams.mInitRadius = this->mContextParameters[mContext].mInitRadius;
  this->mBlendedParams.mInitRadiusRate = this->mContextParameters[mContext].mInitRadiusRate;
  this->mBlendedParams.mInitRadiusPatience = this->mContextParameters[mContext].mInitRadiusPatience;
  this->mBlendedParams.mYawConstrainRate = this->mContextParameters[mContext].mYawConstrainRate;
  this->mBlendedParams.mUseInitAngle = this->mContextParameters[mContext].mUseInitAngle;
  this->mBlendedParams.mInitAngle = this->mContextParameters[mContext].mInitAngle;
  this->mBlendedParams.mInitAngleRate = this->mContextParameters[mContext].mInitAngleRate;
  this->mBlendedParams.mInitAnglePatience = this->mContextParameters[mContext].mInitAnglePatience;
  this->mBlendedParams.mInitAngleWorldSpace = this->mContextParameters[mContext].mInitAngleWorldSpace;
  this->mBlendedParams.mInitAngleUseSecond = this->mContextParameters[mContext].mInitAngleUseSecond;
  this->mBlendedParams.mInitAngleSecond = this->mContextParameters[mContext].mInitAngleSecond;
  this->mBlendedParams.mYawRestrict = this->mContextParameters[mContext].mYawRestrict;
  this->mBlendedParams.mYawMin = this->mContextParameters[mContext].mYawMin;
  this->mBlendedParams.mYawMax = this->mContextParameters[mContext].mYawMax;
  this->mBlendedParams.mUseLookUpDown = this->mContextParameters[mContext].mUseLookUpDown;
  this->mBlendedParams.mHorizCompUseDirection = this->mContextParameters[mContext].mHorizCompUseDirection;
  this->mBlendedParams.mHorizCompSpeedWindowTimespan = this->mContextParameters[mContext].mHorizCompSpeedWindowTimespan;
  this->mBlendedParams.mDesaturation = this->mContextParameters[mContext].mDesaturation;
  this->mBlendedParams.mDamageMultiplier = this->mContextParameters[mContext].mDamageMultiplier;
  this->mBlendedParams.mMotionblurMagnitude = this->mContextParameters[mContext].mMotionblurMagnitude;
  this->mBlendedParams.mUseDofParameters = this->mContextParameters[mContext].mUseDofParameters;
}

// File Line: 606
// RVA: 0x3D87C0
void __fastcall UFG::FollowCameraComponent::UpdateBlendedParams(UFG::FollowCameraComponent *this, float dt)
{
  float mBlend; // xmm0_4
  float v3; // xmm7_4
  float v4; // xmm0_4
  __int64 mContext; // rax
  float mTweakFov; // xmm1_4
  __int64 v7; // rdx
  bool v8; // zf
  float y; // xmm5_4
  float z; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm3_4
  __int64 v15; // rax
  float v16; // xmm5_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  __int64 v19; // rax
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // xmm2_4
  __int64 v23; // rax

  mBlend = this->mBlend;
  v3 = 0.0;
  if ( mBlend <= 0.0 )
  {
    UFG::FollowCameraComponent::FollowParams::operator=(
      &this->mBlendedParams,
      &this->mContextParameters[this->mContext]);
  }
  else
  {
    v4 = mBlend - (float)(dt * this->mBlendRate);
    if ( v4 >= 0.0 )
      v3 = v4;
    mContext = this->mContext;
    mTweakFov = this->mOldParams.mTweakFov;
    this->mBlend = v3;
    v7 = mContext;
    this->mBlendedParams.mTweakFov = (float)((float)(mTweakFov - this->mContextParameters[mContext].mTweakFov) * v3)
                                   + this->mContextParameters[mContext].mTweakFov;
    this->mBlendedParams.mTweakFovMax = (float)((float)(this->mOldParams.mTweakFovMax
                                                      - this->mContextParameters[mContext].mTweakFovMax)
                                              * v3)
                                      + this->mContextParameters[mContext].mTweakFovMax;
    this->mBlendedParams.mTweakOrbitDownRadius = (float)((float)(this->mOldParams.mTweakOrbitDownRadius
                                                               - this->mContextParameters[mContext].mTweakOrbitDownRadius)
                                                       * v3)
                                               + this->mContextParameters[mContext].mTweakOrbitDownRadius;
    this->mBlendedParams.mTweakEyeRise = (float)((float)(this->mOldParams.mTweakEyeRise
                                                       - this->mContextParameters[mContext].mTweakEyeRise)
                                               * v3)
                                       + this->mContextParameters[mContext].mTweakEyeRise;
    this->mBlendedParams.mTweakOrbitSpeed = (float)((float)(this->mOldParams.mTweakOrbitSpeed
                                                          - this->mContextParameters[mContext].mTweakOrbitSpeed)
                                                  * v3)
                                          + this->mContextParameters[mContext].mTweakOrbitSpeed;
    this->mBlendedParams.mTweakLatitudeMin = (float)((float)(this->mOldParams.mTweakLatitudeMin
                                                           - this->mContextParameters[mContext].mTweakLatitudeMin)
                                                   * v3)
                                           + this->mContextParameters[mContext].mTweakLatitudeMin;
    this->mBlendedParams.mTweakLatitudeMax = (float)((float)(this->mOldParams.mTweakLatitudeMax
                                                           - this->mContextParameters[mContext].mTweakLatitudeMax)
                                                   * v3)
                                           + this->mContextParameters[mContext].mTweakLatitudeMax;
    this->mBlendedParams.mTweakRadiusMin = (float)((float)(this->mOldParams.mTweakRadiusMin
                                                         - this->mContextParameters[mContext].mTweakRadiusMin)
                                                 * v3)
                                         + this->mContextParameters[mContext].mTweakRadiusMin;
    this->mBlendedParams.mTweakRadiusMax = (float)((float)(this->mOldParams.mTweakRadiusMax
                                                         - this->mContextParameters[mContext].mTweakRadiusMax)
                                                 * v3)
                                         + this->mContextParameters[mContext].mTweakRadiusMax;
    this->mBlendedParams.mTweakVaultLow = (float)((float)(this->mOldParams.mTweakVaultLow
                                                        - this->mContextParameters[mContext].mTweakVaultLow)
                                                * v3)
                                        + this->mContextParameters[mContext].mTweakVaultLow;
    this->mBlendedParams.mTweakNoiseFrequency = (float)((float)(this->mOldParams.mTweakNoiseFrequency
                                                              - this->mContextParameters[mContext].mTweakNoiseFrequency)
                                                      * v3)
                                              + this->mContextParameters[mContext].mTweakNoiseFrequency;
    this->mBlendedParams.mTweakAimWobbleRadiusMin = (float)((float)(this->mOldParams.mTweakAimWobbleRadiusMin
                                                                  - this->mContextParameters[mContext].mTweakAimWobbleRadiusMin)
                                                          * v3)
                                                  + this->mContextParameters[mContext].mTweakAimWobbleRadiusMin;
    v8 = !this->mBlendedParams.mTweakBlendDurations;
    this->mBlendedParams.mTweakAimWobbleRadiusMax = (float)((float)(this->mOldParams.mTweakAimWobbleRadiusMax
                                                                  - this->mContextParameters[mContext].mTweakAimWobbleRadiusMax)
                                                          * v3)
                                                  + this->mContextParameters[mContext].mTweakAimWobbleRadiusMax;
    this->mBlendedParams.mTweakAimWobbleRadiusPeriod = (float)((float)(this->mOldParams.mTweakAimWobbleRadiusPeriod
                                                                     - this->mContextParameters[mContext].mTweakAimWobbleRadiusPeriod)
                                                             * v3)
                                                     + this->mContextParameters[mContext].mTweakAimWobbleRadiusPeriod;
    this->mBlendedParams.mTweakAimWobbleFreq = (float)((float)(this->mOldParams.mTweakAimWobbleFreq
                                                             - this->mContextParameters[mContext].mTweakAimWobbleFreq)
                                                     * v3)
                                             + this->mContextParameters[mContext].mTweakAimWobbleFreq;
    this->mBlendedParams.mTweakAimWobbleAxisWeight = (float)((float)(this->mOldParams.mTweakAimWobbleAxisWeight
                                                                   - this->mContextParameters[mContext].mTweakAimWobbleAxisWeight)
                                                           * v3)
                                                   + this->mContextParameters[mContext].mTweakAimWobbleAxisWeight;
    this->mBlendedParams.mTweakNoiseEyeMagnitude = (float)((float)(this->mOldParams.mTweakNoiseEyeMagnitude
                                                                 - this->mContextParameters[mContext].mTweakNoiseEyeMagnitude)
                                                         * v3)
                                                 + this->mContextParameters[mContext].mTweakNoiseEyeMagnitude;
    this->mBlendedParams.mTweakNoiseLookMagnitude = (float)((float)(this->mOldParams.mTweakNoiseLookMagnitude
                                                                  - this->mContextParameters[mContext].mTweakNoiseLookMagnitude)
                                                          * v3)
                                                  + this->mContextParameters[mContext].mTweakNoiseLookMagnitude;
    this->mBlendedParams.mTweakAimRadius = (float)((float)(this->mOldParams.mTweakAimRadius
                                                         - this->mContextParameters[mContext].mTweakAimRadius)
                                                 * v3)
                                         + this->mContextParameters[mContext].mTweakAimRadius;
    this->mBlendedParams.mTweakFocusRadius = (float)((float)(this->mOldParams.mTweakFocusRadius
                                                           - this->mContextParameters[mContext].mTweakFocusRadius)
                                                   * v3)
                                           + this->mContextParameters[mContext].mTweakFocusRadius;
    this->mBlendedParams.mTweakTargetedDistance = (float)((float)(this->mOldParams.mTweakTargetedDistance
                                                                - this->mContextParameters[mContext].mTweakTargetedDistance)
                                                        * v3)
                                                + this->mContextParameters[mContext].mTweakTargetedDistance;
    this->mBlendedParams.mTweakVelocityDuration = (float)((float)(this->mOldParams.mTweakVelocityDuration
                                                                - this->mContextParameters[mContext].mTweakVelocityDuration)
                                                        * v3)
                                                + this->mContextParameters[mContext].mTweakVelocityDuration;
    if ( !v8 )
    {
      this->mBlendedParams.mTweakLookDurationH = (float)((float)(this->mOldParams.mTweakLookDurationH
                                                               - this->mContextParameters[v7].mTweakLookDurationH)
                                                       * v3)
                                               + this->mContextParameters[v7].mTweakLookDurationH;
      this->mBlendedParams.mTweakLookDurationV = (float)((float)(this->mOldParams.mTweakLookDurationV
                                                               - this->mContextParameters[v7].mTweakLookDurationV)
                                                       * v3)
                                               + this->mContextParameters[v7].mTweakLookDurationV;
      this->mBlendedParams.mTweakEyeDurationH = (float)((float)(this->mOldParams.mTweakEyeDurationH
                                                              - this->mContextParameters[v7].mTweakEyeDurationH)
                                                      * v3)
                                              + this->mContextParameters[v7].mTweakEyeDurationH;
      this->mBlendedParams.mTweakEyeDurationV = (float)((float)(this->mOldParams.mTweakEyeDurationV
                                                              - this->mContextParameters[v7].mTweakEyeDurationV)
                                                      * v3)
                                              + this->mContextParameters[v7].mTweakEyeDurationV;
      this->mBlendedParams.mTweakFovDuration = (float)((float)(this->mOldParams.mTweakFovDuration
                                                             - this->mContextParameters[v7].mTweakFovDuration)
                                                     * v3)
                                             + this->mContextParameters[v7].mTweakFovDuration;
      this->mBlendedParams.mHorizCompDurationAttack = (float)((float)(this->mOldParams.mHorizCompDurationAttack
                                                                    - this->mContextParameters[v7].mHorizCompDurationAttack)
                                                            * v3)
                                                    + this->mContextParameters[v7].mHorizCompDurationAttack;
      this->mBlendedParams.mHorizCompDurationDecay = (float)((float)(this->mOldParams.mHorizCompDurationDecay
                                                                   - this->mContextParameters[v7].mHorizCompDurationDecay)
                                                           * v3)
                                                   + this->mContextParameters[v7].mHorizCompDurationDecay;
    }
    this->mBlendedParams.mHorizCompOffsetScale = (float)((float)(this->mOldParams.mHorizCompOffsetScale
                                                               - this->mContextParameters[v7].mHorizCompOffsetScale)
                                                       * v3)
                                               + this->mContextParameters[v7].mHorizCompOffsetScale;
    this->mBlendedParams.mHorizCompSpeedMin = (float)((float)(this->mOldParams.mHorizCompSpeedMin
                                                            - this->mContextParameters[v7].mHorizCompSpeedMin)
                                                    * v3)
                                            + this->mContextParameters[v7].mHorizCompSpeedMin;
    this->mBlendedParams.mHorizCompSpeedMax = (float)((float)(this->mOldParams.mHorizCompSpeedMax
                                                            - this->mContextParameters[v7].mHorizCompSpeedMax)
                                                    * v3)
                                            + this->mContextParameters[v7].mHorizCompSpeedMax;
    y = this->mContextParameters[v7].mTweakLookOffset.y;
    z = this->mContextParameters[v7].mTweakLookOffset.z;
    v11 = v3 * (float)(this->mOldParams.mTweakLookOffset.y - y);
    v12 = this->mContextParameters[v7].mTweakLookOffset.x
        + (float)(v3 * (float)(this->mOldParams.mTweakLookOffset.x - this->mContextParameters[v7].mTweakLookOffset.x));
    v13 = v3 * (float)(this->mOldParams.mTweakLookOffset.z - z);
    this->mBlendedParams.mTweakLookOffset.x = v12;
    this->mBlendedParams.mTweakLookOffset.y = y + v11;
    this->mBlendedParams.mTweakLookOffset.z = z + v13;
    v14 = this->mBlend;
    v15 = this->mContext;
    v16 = (float)((float)(this->mOldParams.mTweakCamThru.y - this->mContextParameters[v15].mTweakCamThru.y) * v14)
        + this->mContextParameters[v15].mTweakCamThru.y;
    v17 = (float)((float)(this->mOldParams.mTweakCamThru.z - this->mContextParameters[v15].mTweakCamThru.z) * v14)
        + this->mContextParameters[v15].mTweakCamThru.z;
    this->mBlendedParams.mTweakCamThru.x = (float)((float)(this->mOldParams.mTweakCamThru.x
                                                         - this->mContextParameters[v15].mTweakCamThru.x)
                                                 * v14)
                                         + this->mContextParameters[v15].mTweakCamThru.x;
    this->mBlendedParams.mTweakCamThru.y = v16;
    this->mBlendedParams.mTweakCamThru.z = v17;
    v18 = this->mBlend;
    v19 = this->mContext;
    v20 = (float)((float)(this->mOldParams.mTweakAimThru.y - this->mContextParameters[v19].mTweakAimThru.y) * v18)
        + this->mContextParameters[v19].mTweakAimThru.y;
    v21 = (float)((float)(this->mOldParams.mTweakAimThru.z - this->mContextParameters[v19].mTweakAimThru.z) * v18)
        + this->mContextParameters[v19].mTweakAimThru.z;
    this->mBlendedParams.mTweakAimThru.x = (float)((float)(this->mOldParams.mTweakAimThru.x
                                                         - this->mContextParameters[v19].mTweakAimThru.x)
                                                 * v18)
                                         + this->mContextParameters[v19].mTweakAimThru.x;
    this->mBlendedParams.mTweakAimThru.y = v20;
    this->mBlendedParams.mTweakAimThru.z = v21;
    v22 = this->mBlend;
    v23 = this->mContext;
    v8 = !this->mOldParams.mTweakUseSyncBase;
    this->mBlendedParams.mTweakBaseOffset.x = (float)((float)(this->mOldParams.mTweakBaseOffset.x
                                                            - this->mContextParameters[v23].mTweakBaseOffset.x)
                                                    * v22)
                                            + this->mContextParameters[v23].mTweakBaseOffset.x;
    this->mBlendedParams.mTweakBaseOffset.y = (float)((float)(this->mOldParams.mTweakBaseOffset.y
                                                            - this->mContextParameters[v23].mTweakBaseOffset.y)
                                                    * v22)
                                            + this->mContextParameters[v23].mTweakBaseOffset.y;
    if ( !v8 )
      this->mBlendedParams.mTweakBaseOffset.z = (float)((float)(this->mOldParams.mTweakBaseOffset.z
                                                              - this->mContextParameters[v23].mTweakBaseOffset.z)
                                                      * v22)
                                              + this->mContextParameters[v23].mTweakBaseOffset.z;
    this->mBlendedParams.mTweakSmoothRatePos = (float)((float)(this->mOldParams.mTweakSmoothRatePos
                                                             - this->mContextParameters[v23].mTweakSmoothRatePos)
                                                     * v22)
                                             + this->mContextParameters[v23].mTweakSmoothRatePos;
    this->mBlendedParams.mTweakSmoothRateRot = (float)((float)(this->mOldParams.mTweakSmoothRateRot
                                                             - this->mContextParameters[v23].mTweakSmoothRateRot)
                                                     * v22)
                                             + this->mContextParameters[v23].mTweakSmoothRateRot;
    this->mBlendedParams.mDesaturation = (float)((float)(this->mOldParams.mDesaturation
                                                       - this->mContextParameters[v23].mDesaturation)
                                               * v22)
                                       + this->mContextParameters[v23].mDesaturation;
    this->mBlendedParams.mDamageMultiplier = (float)((float)(this->mOldParams.mDamageMultiplier
                                                           - this->mContextParameters[v23].mDamageMultiplier)
                                                   * v22)
                                           + this->mContextParameters[v23].mDamageMultiplier;
    this->mBlendedParams.mMotionblurMagnitude = (float)((float)(this->mOldParams.mMotionblurMagnitude
                                                              - this->mContextParameters[v23].mMotionblurMagnitude)
                                                      * v22)
                                              + this->mContextParameters[v23].mMotionblurMagnitude;
    this->mBlendedParams.mDofInFocusRange = (float)((float)(this->mOldParams.mDofInFocusRange
                                                          - this->mContextParameters[v23].mDofInFocusRange)
                                                  * v22)
                                          + this->mContextParameters[v23].mDofInFocusRange;
    this->mBlendedParams.mDofNearRange = (float)((float)(this->mOldParams.mDofNearRange
                                                       - this->mContextParameters[v23].mDofNearRange)
                                               * v22)
                                       + this->mContextParameters[v23].mDofNearRange;
    this->mBlendedParams.mDofNearBlurRadius = (float)((float)(this->mOldParams.mDofNearBlurRadius
                                                            - this->mContextParameters[v23].mDofNearBlurRadius)
                                                    * v22)
                                            + this->mContextParameters[v23].mDofNearBlurRadius;
    this->mBlendedParams.mDofFarRange = (float)((float)(this->mOldParams.mDofFarRange
                                                      - this->mContextParameters[v23].mDofFarRange)
                                              * v22)
                                      + this->mContextParameters[v23].mDofFarRange;
    this->mBlendedParams.mDofFarBlurRadius = (float)((float)(this->mOldParams.mDofFarBlurRadius
                                                           - this->mContextParameters[v23].mDofFarBlurRadius)
                                                   * v22)
                                           + this->mContextParameters[v23].mDofFarBlurRadius;
    this->mBlendedParams.mCollisionRise = (float)((float)(this->mOldParams.mCollisionRise
                                                        - this->mContextParameters[v23].mCollisionRise)
                                                * v22)
                                        + this->mContextParameters[v23].mCollisionRise;
  }
}sionRise
           

// File Line: 1205
// RVA: 0x3DE0F0
void __fastcall UFG::FollowCameraComponent::UpdateTweaker(UFG::FollowCameraComponent *this, float delta_sec)
{
  float mTweakRadiusMax; // xmm2_4
  bool v5; // zf
  float v6; // xmm10_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float mTweakVelocityDuration; // xmm3_4
  UFG::HomerCubic<UFG::qVector3> *p_mVelocity; // rcx
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *p_mAimEye; // rcx
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *p_mAimLook; // rcx
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float mTransitionSupplimentaryDuration; // xmm8_4
  float v40; // xmm7_4
  float v41; // xmm8_4
  float v42; // xmm3_4
  float v43; // xmm4_4
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rsi
  float v45; // xmm9_4
  float v46; // xmm7_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rbx
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  UFG::HomerCubic<float> *p_mFov; // rcx
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm7_4
  float v60; // xmm2_4
  float v61; // xmm1_4
  float v62; // xmm8_4
  float v63; // xmm7_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm2_4
  float v69; // xmm2_4
  float v70; // xmm1_4
  float v71; // xmm0_4
  float v72; // xmm0_4
  float mTweakLatitudeMin; // xmm7_4
  float v74; // xmm6_4
  float v75; // xmm0_4
  float v76; // xmm3_4

  mTweakRadiusMax = this->mBlendedParams.mTweakRadiusMax;
  if ( mTweakRadiusMax <= (float)(this->mBlendedParams.mTweakRadiusMin + 0.1) )
    mTweakRadiusMax = this->mBlendedParams.mTweakRadiusMin + 0.1;
  v5 = !this->mMaxRadiusOverrideEnabled;
  v6 = *(float *)&FLOAT_1_0;
  this->mBlendedParams.mTweakRadiusMax = mTweakRadiusMax;
  if ( v5 )
    v7 = 0.0;
  else
    v7 = *(float *)&FLOAT_1_0;
  UFG::qApproach(
    &this->mMaxRadiusOverrideParam,
    v7,
    UFG::FollowCameraComponent::rMaxRadiusOverrideApproachRate,
    delta_sec);
  if ( this->mRiseOverrideEnabled )
    v8 = *(float *)&FLOAT_1_0;
  else
    v8 = 0.0;
  UFG::qApproach(&this->mRiseOverrideParam, v8, UFG::FollowCameraComponent::rRiseOverrideApproachRate, delta_sec);
  this->rAimWobbleRadiusMin = this->mBlendedParams.mTweakAimWobbleRadiusMin;
  this->rAimWobbleRadiusMax = this->mBlendedParams.mTweakAimWobbleRadiusMax;
  this->rAimWobbleRadiusPeriod = this->mBlendedParams.mTweakAimWobbleRadiusPeriod;
  this->rAimWobbleFreq = this->mBlendedParams.mTweakAimWobbleFreq;
  this->rAimWobbleAxisWeight = this->mBlendedParams.mTweakAimWobbleAxisWeight;
  if ( (unsigned int)(this->mContext - 5) > 1 )
  {
    this->mFov.p1 = this->mBlendedParams.mTweakFov;
    UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
    this->mFov.mParameter = 0.0;
  }
  mTweakVelocityDuration = this->mBlendedParams.mTweakVelocityDuration;
  p_mVelocity = &this->mVelocity;
  v11 = this->mVelocity.mParameter.y / this->mVelocity.mDuration.y;
  v12 = this->mVelocity.mParameter.z / this->mVelocity.mDuration.z;
  v13 = this->mVelocity.mParameter.x / this->mVelocity.mDuration.x;
  this->mVelocity.mParameter.y = v11;
  this->mVelocity.mParameter.z = v12;
  this->mVelocity.mParameter.x = v13;
  if ( mTweakVelocityDuration <= 0.0099999998 )
    v14 = FLOAT_0_0099999998;
  else
    v14 = mTweakVelocityDuration;
  if ( mTweakVelocityDuration <= 0.0099999998 )
    v15 = FLOAT_0_0099999998;
  else
    v15 = mTweakVelocityDuration;
  if ( mTweakVelocityDuration <= 0.0099999998 )
    mTweakVelocityDuration = FLOAT_0_0099999998;
  this->mVelocity.mDuration.y = v15;
  p_mVelocity->mDuration.x = mTweakVelocityDuration;
  this->mVelocity.mDuration.z = v14;
  v16 = v14 * this->mVelocity.mParameter.z;
  this->mVelocity.mParameter.x = mTweakVelocityDuration * this->mVelocity.mParameter.x;
  this->mVelocity.mParameter.z = v16;
  this->mVelocity.mParameter.y = v15 * v11;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mVelocity);
  p_mAimEye = &this->mAimEye;
  v18 = this->mAimEye.mParameter.y / this->mAimEye.mDuration.y;
  v19 = this->mAimEye.mParameter.z / this->mAimEye.mDuration.z;
  v20 = this->mAimEye.mParameter.x / this->mAimEye.mDuration.x;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v21 = UFG::FollowCameraComponent::rAimDurationMouse + this->mAimDurationSupplimentary;
    this->mAimEye.mParameter.x = v20;
    this->mAimEye.mParameter.y = v18;
    this->mAimEye.mParameter.z = v19;
    if ( v21 <= 0.0099999998 )
      v22 = FLOAT_0_0099999998;
    else
      v22 = v21;
    if ( v21 <= 0.0099999998 )
      v23 = FLOAT_0_0099999998;
    else
      v23 = v21;
    if ( v21 <= 0.0099999998 )
      v21 = FLOAT_0_0099999998;
    this->mAimEye.mDuration.y = v23;
    p_mAimEye->mDuration.x = v21;
    this->mAimEye.mDuration.z = v22;
    v24 = v22 * this->mAimEye.mParameter.z;
    this->mAimEye.mParameter.x = v21 * this->mAimEye.mParameter.x;
    this->mAimEye.mParameter.z = v24;
    this->mAimEye.mParameter.y = v23 * v18;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mAimEye);
    p_mAimLook = &this->mAimLook;
    v26 = this->mAimLook.mParameter.y / this->mAimLook.mDuration.y;
    v27 = this->mAimLook.mParameter.z / this->mAimLook.mDuration.z;
    v28 = UFG::FollowCameraComponent::rAimDurationMouse + this->mAimDurationSupplimentary;
    v29 = this->mAimLook.mParameter.x / this->mAimLook.mDuration.x;
    this->mAimLook.mParameter.y = v26;
    this->mAimLook.mParameter.z = v27;
    this->mAimLook.mParameter.x = v29;
    if ( v28 > 0.0099999998 )
    {
      v30 = v28;
      goto LABEL_41;
    }
  }
  else
  {
    v31 = UFG::FollowCameraComponent::rAimDuration + this->mAimDurationSupplimentary;
    this->mAimEye.mParameter.x = v20;
    this->mAimEye.mParameter.y = v18;
    this->mAimEye.mParameter.z = v19;
    if ( v31 <= 0.0099999998 )
      v32 = FLOAT_0_0099999998;
    else
      v32 = v31;
    if ( v31 <= 0.0099999998 )
      v33 = FLOAT_0_0099999998;
    else
      v33 = v31;
    if ( v31 <= 0.0099999998 )
      v31 = FLOAT_0_0099999998;
    this->mAimEye.mDuration.y = v33;
    p_mAimEye->mDuration.x = v31;
    this->mAimEye.mDuration.z = v32;
    v34 = v32 * this->mAimEye.mParameter.z;
    this->mAimEye.mParameter.x = v31 * this->mAimEye.mParameter.x;
    this->mAimEye.mParameter.z = v34;
    this->mAimEye.mParameter.y = v33 * v18;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mAimEye);
    p_mAimLook = &this->mAimLook;
    v26 = this->mAimLook.mParameter.y / this->mAimLook.mDuration.y;
    v35 = this->mAimLook.mParameter.z / this->mAimLook.mDuration.z;
    v28 = UFG::FollowCameraComponent::rAimDuration + this->mAimDurationSupplimentary;
    v36 = this->mAimLook.mParameter.x / this->mAimLook.mDuration.x;
    this->mAimLook.mParameter.y = v26;
    this->mAimLook.mParameter.z = v35;
    this->mAimLook.mParameter.x = v36;
    if ( v28 > 0.0099999998 )
    {
      v30 = v28;
      goto LABEL_41;
    }
  }
  v30 = FLOAT_0_0099999998;
LABEL_41:
  if ( v28 <= 0.0099999998 )
    v37 = FLOAT_0_0099999998;
  else
    v37 = v28;
  if ( v28 <= 0.0099999998 )
    v28 = FLOAT_0_0099999998;
  p_mAimLook->mDuration.x = v28;
  p_mAimLook->mDuration.y = v37;
  p_mAimLook->mDuration.z = v30;
  v38 = v30 * p_mAimLook->mParameter.z;
  p_mAimLook->mParameter.x = v28 * p_mAimLook->mParameter.x;
  p_mAimLook->mParameter.y = v37 * v26;
  p_mAimLook->mParameter.z = v38;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mAimLook);
  mTransitionSupplimentaryDuration = this->mTransitionSupplimentaryDuration;
  v40 = mTransitionSupplimentaryDuration * this->mTransitionParamSuppLook;
  v41 = mTransitionSupplimentaryDuration * this->mTransitionParamSuppEye;
  v42 = v41 + this->mBlendedParams.mTweakEyeDurationH;
  v43 = v41 + this->mBlendedParams.mTweakEyeDurationV;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController
    && this->mGotoRadiusPatience <= 0.0
    && this->mGotoAnglePatience <= 0.0
    && this->mGotoRisePatience <= 0.0 )
  {
    v42 = UFG::FollowCameraComponent::rEyeDurationMouse + v41;
    v43 = UFG::FollowCameraComponent::rEyeDurationMouse + v41;
  }
  p_mEye = &this->mEye;
  v45 = v40 + this->mBlendedParams.mTweakLookDurationH;
  v46 = v40 + this->mBlendedParams.mTweakLookDurationV;
  v47 = this->mEye.mParameter.y / this->mEye.mDuration.y;
  v48 = this->mEye.mParameter.z / this->mEye.mDuration.z;
  v49 = this->mEye.mParameter.x / this->mEye.mDuration.x;
  this->mEye.mParameter.y = v47;
  this->mEye.mParameter.x = v49;
  this->mEye.mParameter.z = v48;
  if ( v43 <= 0.0099999998 )
    v43 = FLOAT_0_0099999998;
  if ( v42 <= 0.0099999998 )
    v50 = FLOAT_0_0099999998;
  else
    v50 = v42;
  if ( v42 <= 0.0099999998 )
    v42 = FLOAT_0_0099999998;
  this->mEye.mDuration.y = v50;
  this->mEye.mDuration.z = v43;
  p_mEye->mDuration.x = v42;
  this->mEye.mParameter.x = v42 * this->mEye.mParameter.x;
  this->mEye.mParameter.y = v50 * v47;
  this->mEye.mParameter.z = v43 * v48;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  p_mLook = &this->mLook;
  v52 = this->mLook.mParameter.y / this->mLook.mDuration.y;
  v53 = this->mLook.mParameter.z / this->mLook.mDuration.z;
  v54 = this->mLook.mParameter.x / this->mLook.mDuration.x;
  this->mLook.mParameter.y = v52;
  this->mLook.mParameter.z = v53;
  this->mLook.mParameter.x = v54;
  if ( v46 <= 0.0099999998 )
    v46 = FLOAT_0_0099999998;
  if ( v45 <= 0.0099999998 )
    v55 = FLOAT_0_0099999998;
  else
    v55 = v45;
  if ( v45 <= 0.0099999998 )
    v45 = FLOAT_0_0099999998;
  this->mLook.mDuration.y = v55;
  this->mLook.mDuration.z = v46;
  p_mLook->mDuration.x = v45;
  this->mLook.mParameter.x = v45 * this->mLook.mParameter.x;
  this->mLook.mParameter.y = v55 * v52;
  this->mLook.mParameter.z = v46 * v53;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  p_mFov = &this->mFov;
  v57 = v41 + this->mBlendedParams.mTweakFovDuration;
  v58 = this->mFov.mParameter / this->mFov.mDuration;
  this->mFov.mParameter = v58;
  if ( v57 <= 0.0099999998 )
    v57 = FLOAT_0_0099999998;
  p_mFov->mDuration = v57;
  this->mFov.mParameter = v57 * v58;
  UFG::HomerCubic<float>::MakeCoeffs(p_mFov);
  if ( (unsigned int)(this->mType - 2) <= 1 )
  {
    v59 = v41;
    v60 = this->mEye.mParameter.y / this->mEye.mDuration.y;
    v61 = this->mEye.mParameter.z / this->mEye.mDuration.z;
    v62 = v41 + this->mBlendedParams.mTweakLookDurationV;
    v63 = v59 + this->mBlendedParams.mTweakLookDurationH;
    this->mEye.mParameter.x = this->mEye.mParameter.x / p_mEye->mDuration.x;
    this->mEye.mParameter.y = v60;
    this->mEye.mParameter.z = v61;
    if ( v62 <= 0.0099999998 )
      v64 = FLOAT_0_0099999998;
    else
      v64 = v62;
    if ( v63 <= 0.0099999998 )
      v65 = FLOAT_0_0099999998;
    else
      v65 = v63;
    if ( v63 <= 0.0099999998 )
      v66 = FLOAT_0_0099999998;
    else
      v66 = v63;
    p_mEye->mDuration.x = v66;
    this->mEye.mDuration.y = v65;
    this->mEye.mDuration.z = v64;
    v67 = v65 * this->mEye.mParameter.y;
    v68 = v64 * this->mEye.mParameter.z;
    this->mEye.mParameter.x = v66 * this->mEye.mParameter.x;
    this->mEye.mParameter.y = v67;
    this->mEye.mParameter.z = v68;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
    v69 = this->mLook.mParameter.y / this->mLook.mDuration.y;
    v70 = this->mLook.mParameter.z / this->mLook.mDuration.z;
    v71 = this->mLook.mParameter.x / p_mLook->mDuration.x;
    this->mLook.mParameter.y = v69;
    this->mLook.mParameter.z = v70;
    this->mLook.mParameter.x = v71;
    if ( v62 <= 0.0099999998 )
      v62 = FLOAT_0_0099999998;
    if ( v63 <= 0.0099999998 )
      v72 = FLOAT_0_0099999998;
    else
      v72 = v63;
    if ( v63 <= 0.0099999998 )
      v63 = FLOAT_0_0099999998;
    this->mLook.mDuration.y = v72;
    this->mLook.mDuration.z = v62;
    p_mLook->mDuration.x = v63;
    this->mLook.mParameter.x = v63 * this->mLook.mParameter.x;
    this->mLook.mParameter.y = v72 * v69;
    this->mLook.mParameter.z = v62 * v70;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  }
  if ( this->mTarget.m_pSimComponent )
  {
    mTweakLatitudeMin = this->mBlendedParams.mTweakLatitudeMin;
    v74 = sinf(mTweakLatitudeMin);
    v75 = cosf(mTweakLatitudeMin);
    v76 = (float)(this->mMaxRadiusOverrideParam * this->mMaxRadiusOverride)
        + (float)((float)(1.0 - this->mMaxRadiusOverrideParam) * this->mBlendedParams.mTweakRadiusMax);
    if ( v76 < 0.1 )
      v76 = FLOAT_0_1;
    if ( (float)(this->mBlendedParams.mTweakOrbitDownRadius / v76) <= 1.0 )
      v6 = this->mBlendedParams.mTweakOrbitDownRadius / v76;
    this->mOrbitSquish = v6;
    if ( v6 < 0.1 )
      this->mOrbitSquish = 0.1;
    if ( v74 >= 0.0 )
      this->mLatitudeMin = mTweakLatitudeMin;
    else
      this->mLatitudeMin = atan2f(v74 / this->mOrbitSquish, v75);
  }
}

// File Line: 1299
// RVA: 0x3CAFF0
void __fastcall UFG::FollowCameraComponent::SetCurrent(UFG::FollowCameraComponent *this, bool current)
{
  this->mCurrent = current;
  if ( current )
  {
    this->mGotoAngleLocalSpace = 1;
    *(_QWORD *)&this->mGotoRiseElaspedTime = 0i64;
    *(_QWORD *)&this->mGotoRadiusElaspedTime = 0i64;
    this->mGotoAngleElaspedTime = 0.0;
    this->mGotoAnglePatience = 0.0;
    this->mMouseBoomSet = 0;
  }
}

// File Line: 1328
// RVA: 0x3CDCE0
void __fastcall UFG::FollowCameraComponent::Snap(UFG::FollowCameraComponent *this)
{
  UFG::HomerCubic<float> *p_mFov; // rbx
  float y; // xmm0_4
  float z; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4

  p_mFov = &this->mFov;
  *(_QWORD *)&this->mBlend = 0i64;
  this->mAimDurationSupplimentary = 0.0;
  this->mFov.p0 = this->mFov.p1;
  this->mFov.v0 = this->mFov.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  p_mFov->mParameter = 0.0;
  y = this->mEye.p1.y;
  z = this->mEye.p1.z;
  this->mEye.p0.x = this->mEye.p1.x;
  this->mEye.p0.y = y;
  this->mEye.p0.z = z;
  v5 = this->mEye.v1.y;
  v6 = this->mEye.v1.z;
  this->mEye.v0.x = this->mEye.v1.x;
  this->mEye.v0.y = v5;
  this->mEye.v0.z = v6;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  v7 = this->mLook.p1.y;
  v8 = this->mLook.p1.z;
  this->mLook.p0.x = this->mLook.p1.x;
  this->mLook.p0.y = v7;
  this->mLook.p0.z = v8;
  v9 = this->mLook.v1.y;
  v10 = this->mLook.v1.z;
  this->mLook.v0.x = this->mLook.v1.x;
  this->mLook.v0.y = v9;
  this->mLook.v0.z = v10;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  v11 = this->mVelocity.p1.y;
  v12 = this->mVelocity.p1.z;
  this->mVelocity.p0.x = this->mVelocity.p1.x;
  this->mVelocity.p0.y = v11;
  this->mVelocity.p0.z = v12;
  v13 = this->mVelocity.v1.y;
  v14 = this->mVelocity.v1.z;
  this->mVelocity.v0.x = this->mVelocity.v1.x;
  this->mVelocity.v0.y = v13;
  this->mVelocity.v0.z = v14;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mVelocity);
  *(_QWORD *)&this->mVelocity.mParameter.x = 0i64;
  this->mVelocity.mParameter.z = 0.0;
  v15 = this->mOffsetLook.p1.y;
  v16 = this->mOffsetLook.p1.z;
  this->mOffsetLook.p0.x = this->mOffsetLook.p1.x;
  this->mOffsetLook.p0.y = v15;
  this->mOffsetLook.p0.z = v16;
  v17 = this->mOffsetLook.v1.y;
  v18 = this->mOffsetLook.v1.z;
  this->mOffsetLook.v0.x = this->mOffsetLook.v1.x;
  this->mOffsetLook.v0.y = v17;
  this->mOffsetLook.v0.z = v18;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetLook);
  *(_QWORD *)&this->mOffsetLook.mParameter.x = 0i64;
  this->mOffsetLook.mParameter.z = 0.0;
  v19 = this->mOffsetEye.p1.y;
  v20 = this->mOffsetEye.p1.z;
  this->mOffsetEye.p0.x = this->mOffsetEye.p1.x;
  this->mOffsetEye.p0.y = v19;
  this->mOffsetEye.p0.z = v20;
  v21 = this->mOffsetEye.v1.y;
  v22 = this->mOffsetEye.v1.z;
  this->mOffsetEye.v0.x = this->mOffsetEye.v1.x;
  this->mOffsetEye.v0.y = v21;
  this->mOffsetEye.v0.z = v22;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetEye);
  *(_QWORD *)&this->mOffsetEye.mParameter.x = 0i64;
  this->mOffsetEye.mParameter.z = 0.0;
  v23 = *(float *)&FLOAT_1_0;
  if ( this->mMaxRadiusOverrideEnabled )
    v24 = *(float *)&FLOAT_1_0;
  else
    v24 = 0.0;
  this->mMaxRadiusOverrideParam = v24;
  if ( this->mRiseOverrideEnabled )
    v25 = *(float *)&FLOAT_1_0;
  else
    v25 = 0.0;
  this->mRiseOverrideParam = v25;
  *(_QWORD *)&this->mRecoilAngle = 0i64;
  v26 = UFG::qVector3::msZero.y;
  v27 = UFG::qVector3::msZero.z;
  this->mRecoilEye.p1.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.p1.y = v26;
  this->mRecoilEye.p1.z = v27;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  v28 = this->mRecoilEye.p1.y;
  v29 = this->mRecoilEye.p1.z;
  this->mRecoilEye.p0.x = this->mRecoilEye.p1.x;
  this->mRecoilEye.p0.y = v28;
  this->mRecoilEye.p0.z = v29;
  v30 = this->mRecoilEye.v1.y;
  v31 = this->mRecoilEye.v1.z;
  this->mRecoilEye.v0.x = this->mRecoilEye.v1.x;
  this->mRecoilEye.v0.y = v30;
  this->mRecoilEye.v0.z = v31;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  *(_QWORD *)&this->mHorizCompTargetSpeedWindow.m_StartIndex = 0i64;
  this->mHorizCompTargetSpeedWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->mHorizCompTargetSpeedWindow.m_RunningSum, 0, 4u);
  this->mHorizCompOffset.p0 = this->mHorizCompOffset.p1;
  this->mHorizCompOffset.v0 = this->mHorizCompOffset.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mHorizCompOffset);
  this->mHorizCompOffset.mParameter = 0.0;
  v32 = UFG::qVector3::msDirUp.y;
  v33 = UFG::qVector3::msDirUp.z;
  this->mUpFrom.x = UFG::qVector3::msDirUp.x;
  this->mUpFrom.y = v32;
  this->mUpFrom.z = v33;
  if ( !this->bAimUseEyeLook )
    v23 = 0.0;
  this->rAimParameter = v23;
  v34 = this->mAimEye.p1.y;
  v35 = this->mAimEye.p1.z;
  this->mAimEye.p0.x = this->mAimEye.p1.x;
  this->mAimEye.p0.y = v34;
  this->mAimEye.p0.z = v35;
  v36 = this->mAimEye.v1.y;
  v37 = this->mAimEye.v1.z;
  this->mAimEye.v0.x = this->mAimEye.v1.x;
  this->mAimEye.v0.y = v36;
  this->mAimEye.v0.z = v37;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
  *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
  this->mAimEye.mParameter.z = 0.0;
  v38 = this->mAimLook.p1.y;
  v39 = this->mAimLook.p1.z;
  this->mAimLook.p0.x = this->mAimLook.p1.x;
  this->mAimLook.p0.y = v38;
  this->mAimLook.p0.z = v39;
  v40 = this->mAimLook.v1.y;
  v41 = this->mAimLook.v1.z;
  this->mAimLook.v0.x = this->mAimLook.v1.x;
  this->mAimLook.v0.y = v40;
  this->mAimLook.v0.z = v41;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
  *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
  this->mAimLook.mParameter.z = 0.0;
  *(_QWORD *)&this->mTransitionParamEye = 0i64;
  *(_QWORD *)&this->mTransitionParamSuppEye = 0i64;
}

// File Line: 1362
// RVA: 0x3CE2A0
void __fastcall UFG::FollowCameraComponent::SnapCurrent(UFG::FollowCameraComponent *this)
{
  UFG::HomerCubic<float> *p_mFov; // rbx
  float p0; // eax
  float x; // eax
  float z; // xmm1_4
  float y; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // eax

  p_mFov = &this->mFov;
  *(_QWORD *)&this->mBlend = 0i64;
  this->mAimDurationSupplimentary = 0.0;
  p0 = this->mFov.p0;
  *(_QWORD *)&this->mFov.v0 = 0i64;
  this->mFov.p1 = p0;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  p_mFov->mParameter = 0.0;
  x = this->mEye.p0.x;
  z = this->mEye.p0.z;
  this->mEye.p1.y = this->mEye.p0.y;
  this->mEye.p1.z = z;
  this->mEye.p1.x = x;
  *(_QWORD *)&this->mEye.v0.x = 0i64;
  *(_QWORD *)&this->mEye.v0.z = 0i64;
  *(_QWORD *)&this->mEye.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  y = this->mLook.p0.y;
  v7 = this->mLook.p0.z;
  this->mLook.p1.x = this->mLook.p0.x;
  this->mLook.p1.y = y;
  this->mLook.p1.z = v7;
  *(_QWORD *)&this->mLook.v0.x = 0i64;
  *(_QWORD *)&this->mLook.v0.z = 0i64;
  *(_QWORD *)&this->mLook.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  v8 = this->mVelocity.p0.y;
  v9 = this->mVelocity.p0.z;
  this->mVelocity.p1.x = this->mVelocity.p0.x;
  this->mVelocity.p1.y = v8;
  this->mVelocity.p1.z = v9;
  *(_QWORD *)&this->mVelocity.v0.x = 0i64;
  *(_QWORD *)&this->mVelocity.v0.z = 0i64;
  *(_QWORD *)&this->mVelocity.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mVelocity);
  *(_QWORD *)&this->mVelocity.mParameter.x = 0i64;
  this->mVelocity.mParameter.z = 0.0;
  v10 = this->mOffsetLook.p0.x;
  v11 = this->mOffsetLook.p0.z;
  this->mOffsetLook.p1.y = this->mOffsetLook.p0.y;
  this->mOffsetLook.p1.z = v11;
  this->mOffsetLook.p1.x = v10;
  *(_QWORD *)&this->mOffsetLook.v0.x = 0i64;
  *(_QWORD *)&this->mOffsetLook.v0.z = 0i64;
  *(_QWORD *)&this->mOffsetLook.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetLook);
  *(_QWORD *)&this->mOffsetLook.mParameter.x = 0i64;
  this->mOffsetLook.mParameter.z = 0.0;
  v12 = this->mOffsetEye.p0.y;
  v13 = this->mOffsetEye.p0.z;
  this->mOffsetEye.p1.x = this->mOffsetEye.p0.x;
  this->mOffsetEye.p1.y = v12;
  this->mOffsetEye.p1.z = v13;
  *(_QWORD *)&this->mOffsetEye.v0.x = 0i64;
  *(_QWORD *)&this->mOffsetEye.v0.z = 0i64;
  *(_QWORD *)&this->mOffsetEye.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetEye);
  *(_QWORD *)&this->mOffsetEye.mParameter.x = 0i64;
  this->mOffsetEye.mParameter.z = 0.0;
  this->mRecoilAngle = this->mRecoilAngleDesired;
  v14 = this->mRecoilEye.p0.y;
  v15 = this->mRecoilEye.p0.z;
  this->mRecoilEye.p1.x = this->mRecoilEye.p0.x;
  this->mRecoilEye.p1.y = v14;
  this->mRecoilEye.p1.z = v15;
  *(_QWORD *)&this->mRecoilEye.v0.x = 0i64;
  *(_QWORD *)&this->mRecoilEye.v0.z = 0i64;
  *(_QWORD *)&this->mRecoilEye.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  *(_QWORD *)&this->mHorizCompTargetSpeedWindow.m_StartIndex = 0i64;
  this->mHorizCompTargetSpeedWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->mHorizCompTargetSpeedWindow.m_RunningSum, 0, 4u);
  v16 = this->mHorizCompOffset.p0;
  *(_QWORD *)&this->mHorizCompOffset.v0 = 0i64;
  this->mHorizCompOffset.p1 = v16;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mHorizCompOffset);
  this->mHorizCompOffset.mParameter = 0.0;
}

// File Line: 1381
// RVA: 0x3C5FD0
void __fastcall UFG::FollowCameraComponent::LoadContextParameters(
        UFG::FollowCameraComponent *this,
        UFG::FollowCameraComponent::FollowParams *context_parameters,
        UFG::qSymbol *context_symbol)
{
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertySet *v5; // rdi
  UFG::qSymbol *v6; // rax
  UFG::qSymbol *v7; // rax
  float *v8; // rax
  UFG::FollowCameraComponent::FollowParams *v9; // rcx
  float mTweakFov; // xmm0_4
  UFG::qSymbol tag; // [rsp+58h] [rbp+20h] BYREF

  PropertySet = UFG::PropertySetManager::GetPropertySet(context_symbol);
  v5 = PropertySet;
  if ( PropertySet )
  {
    context_parameters->mTweakFov = *UFG::qPropertySet::Get<float>(
                                       PropertySet,
                                       (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_Fov,
                                       DEPTH_RECURSE);
    context_parameters->mTweakOrbitDownRadius = *UFG::qPropertySet::Get<float>(
                                                   v5,
                                                   (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_OrbitDownRadius,
                                                   DEPTH_RECURSE);
    context_parameters->mTweakEyeRise = *UFG::qPropertySet::Get<float>(
                                           v5,
                                           (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_EyeRise,
                                           DEPTH_RECURSE);
    context_parameters->mTweakVelocityDuration = *UFG::qPropertySet::Get<float>(
                                                    v5,
                                                    (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_VelocityDuration,
                                                    DEPTH_RECURSE);
    context_parameters->mTweakLookDurationH = *UFG::qPropertySet::Get<float>(
                                                 v5,
                                                 (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_LookDurationH,
                                                 DEPTH_RECURSE);
    context_parameters->mTweakLookDurationV = *UFG::qPropertySet::Get<float>(
                                                 v5,
                                                 (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_LookDurationV,
                                                 DEPTH_RECURSE);
    context_parameters->mTweakEyeDurationH = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_EyeDurationH,
                                                DEPTH_RECURSE);
    context_parameters->mTweakEyeDurationV = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_EyeDurationV,
                                                DEPTH_RECURSE);
    context_parameters->mTweakFovDuration = *UFG::qPropertySet::Get<float>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_FovDuration,
                                               DEPTH_RECURSE);
    context_parameters->mTweakOrbitSpeed = *UFG::qPropertySet::Get<float>(
                                              v5,
                                              (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_OrbitSpeed,
                                              DEPTH_RECURSE);
    context_parameters->mTweakRadiusMin = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_RadiusMin,
                                             DEPTH_RECURSE);
    context_parameters->mTweakRadiusMax = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_RadiusMax,
                                             DEPTH_RECURSE);
    context_parameters->mTweakLatitudeMin = *UFG::qPropertySet::Get<float>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_LatitudeMin,
                                               DEPTH_RECURSE);
    context_parameters->mTweakLatitudeMax = *UFG::qPropertySet::Get<float>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_LatitudeMax,
                                               DEPTH_RECURSE);
    context_parameters->mTweakVaultLow = *UFG::qPropertySet::Get<float>(
                                            v5,
                                            (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_HighVaultHeight,
                                            DEPTH_RECURSE);
    context_parameters->mTweakLookOffset.x = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_LookOffsetX,
                                                DEPTH_RECURSE);
    context_parameters->mTweakLookOffset.y = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_LookOffsetY,
                                                DEPTH_RECURSE);
    context_parameters->mTweakLookOffset.z = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_LookOffsetZ,
                                                DEPTH_RECURSE);
    context_parameters->mTweakCamThru.x = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_CamThruX,
                                             DEPTH_RECURSE);
    context_parameters->mTweakCamThru.y = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_CamThruY,
                                             DEPTH_RECURSE);
    context_parameters->mTweakCamThru.z = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_CamThruZ,
                                             DEPTH_RECURSE);
    context_parameters->mTweakAimThru.x = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimThruX,
                                             DEPTH_RECURSE);
    context_parameters->mTweakAimThru.y = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimThruY,
                                             DEPTH_RECURSE);
    context_parameters->mTweakAimThru.z = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimThruZ,
                                             DEPTH_RECURSE);
    context_parameters->mTweakBaseOffset.x = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_BaseOffsetX,
                                                DEPTH_RECURSE);
    context_parameters->mTweakBaseOffset.y = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_BaseOffsetY,
                                                DEPTH_RECURSE);
    context_parameters->mTweakBaseOffset.z = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_BaseOffsetZ,
                                                DEPTH_RECURSE);
    context_parameters->mTweakSmoothRatePos = *UFG::qPropertySet::Get<float>(
                                                 v5,
                                                 (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_SmoothRatePos,
                                                 DEPTH_RECURSE);
    context_parameters->mTweakSmoothRateRot = *UFG::qPropertySet::Get<float>(
                                                 v5,
                                                 (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_SmoothRateRot,
                                                 DEPTH_RECURSE);
    context_parameters->mTweakAimRadius = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimRadius,
                                             DEPTH_RECURSE);
    context_parameters->mTweakFocusRadius = *UFG::qPropertySet::Get<float>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_FocusRadius,
                                               DEPTH_RECURSE);
    context_parameters->mTweakTargetedDistance = *UFG::qPropertySet::Get<float>(
                                                    v5,
                                                    (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_TargetedDistance,
                                                    DEPTH_RECURSE);
    context_parameters->mSrcOrientation = SrcTransform_Default;
    v6 = UFG::qPropertySet::Get<UFG::qSymbol>(
           v5,
           (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_Orientation,
           DEPTH_RECURSE);
    if ( v6 )
    {
      tag.mUID = v6->mUID;
      context_parameters->mSrcOrientation = UFG::CharacterSubjectComponent::GetTransformType((UFG::qSymbol)&tag);
    }
    context_parameters->mSrcPosition = SrcTransform_Default;
    v7 = UFG::qPropertySet::Get<UFG::qSymbol>(
           v5,
           (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_Position,
           DEPTH_RECURSE);
    if ( v7 )
    {
      tag.mUID = v7->mUID;
      context_parameters->mSrcPosition = UFG::CharacterSubjectComponent::GetTransformType((UFG::qSymbol)&tag);
    }
    context_parameters->mTweakBlendDurations = *UFG::qPropertySet::Get<bool>(
                                                  v5,
                                                  (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_BlendDurations,
                                                  DEPTH_RECURSE);
    context_parameters->mTweakUseSyncBase = *UFG::qPropertySet::Get<bool>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_UseSyncBase,
                                               DEPTH_RECURSE);
    context_parameters->mUseDofParameters = *UFG::qPropertySet::Get<bool>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_UseDofParameters,
                                               DEPTH_RECURSE);
    context_parameters->mDofInFocusRange = *UFG::qPropertySet::Get<float>(
                                              v5,
                                              (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_Dof,
                                              DEPTH_RECURSE);
    context_parameters->mDofNearRange = *UFG::qPropertySet::Get<float>(
                                           v5,
                                           (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_DofNearRange,
                                           DEPTH_RECURSE);
    context_parameters->mDofNearBlurRadius = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_DofNearBlur,
                                                DEPTH_RECURSE);
    context_parameters->mDofFarRange = *UFG::qPropertySet::Get<float>(
                                          v5,
                                          (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_DofFarRange,
                                          DEPTH_RECURSE);
    context_parameters->mDofFarBlurRadius = *UFG::qPropertySet::Get<float>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_DofFarBlur,
                                               DEPTH_RECURSE);
    context_parameters->mCollisionRise = *UFG::qPropertySet::Get<float>(
                                            v5,
                                            (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_CollisionRise,
                                            DEPTH_RECURSE);
    context_parameters->mTweakNoiseFrequency = *UFG::qPropertySet::Get<float>(
                                                  v5,
                                                  (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_NoiseFrequency,
                                                  DEPTH_RECURSE);
    context_parameters->mTweakNoiseEyeMagnitude = *UFG::qPropertySet::Get<float>(
                                                     v5,
                                                     (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_NoiseEyeMagnitude,
                                                     DEPTH_RECURSE);
    context_parameters->mTweakNoiseLookMagnitude = *UFG::qPropertySet::Get<float>(
                                                      v5,
                                                      (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_NoiseLookMagnitude,
                                                      DEPTH_RECURSE);
    context_parameters->mTweakAimWobbleRadiusMin = *UFG::qPropertySet::Get<float>(
                                                      v5,
                                                      (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimWobbleRadiusMin,
                                                      DEPTH_RECURSE);
    context_parameters->mTweakAimWobbleRadiusMax = *UFG::qPropertySet::Get<float>(
                                                      v5,
                                                      (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimWobbleRadiusMax,
                                                      DEPTH_RECURSE);
    context_parameters->mTweakAimWobbleRadiusPeriod = *UFG::qPropertySet::Get<float>(
                                                         v5,
                                                         (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimWobbleRadiusPeriod,
                                                         DEPTH_RECURSE);
    context_parameters->mTweakAimWobbleFreq = *UFG::qPropertySet::Get<float>(
                                                 v5,
                                                 (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimWobbleFreq,
                                                 DEPTH_RECURSE);
    context_parameters->mTweakAimWobbleAxisWeight = *UFG::qPropertySet::Get<float>(
                                                       v5,
                                                       (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimWobbleAxisWeight,
                                                       DEPTH_RECURSE);
    context_parameters->mUseInitRise = *UFG::qPropertySet::Get<bool>(
                                          v5,
                                          (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_UseInitRise,
                                          DEPTH_RECURSE);
    context_parameters->mInitRise = *UFG::qPropertySet::Get<float>(
                                       v5,
                                       (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitRise,
                                       DEPTH_RECURSE);
    context_parameters->mInitRiseRate = *UFG::qPropertySet::Get<float>(
                                           v5,
                                           (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitRiseRate,
                                           DEPTH_RECURSE);
    context_parameters->mInitRisePatience = *UFG::qPropertySet::Get<float>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitRisePatience,
                                               DEPTH_RECURSE);
    context_parameters->mUseInitRadius = *UFG::qPropertySet::Get<bool>(
                                            v5,
                                            (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_UseInitRadius,
                                            DEPTH_RECURSE);
    context_parameters->mInitRadius = *UFG::qPropertySet::Get<float>(
                                         v5,
                                         (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitRadius,
                                         DEPTH_RECURSE);
    context_parameters->mInitRadiusRate = *UFG::qPropertySet::Get<float>(
                                             v5,
                                             (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitRadiusRate,
                                             DEPTH_RECURSE);
    context_parameters->mInitRadiusPatience = *UFG::qPropertySet::Get<float>(
                                                 v5,
                                                 (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitRadiusPatience,
                                                 DEPTH_RECURSE);
    context_parameters->mUseInitAngle = *UFG::qPropertySet::Get<bool>(
                                           v5,
                                           (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_UseInitAngle,
                                           DEPTH_RECURSE);
    context_parameters->mInitAngle = *UFG::qPropertySet::Get<float>(
                                        v5,
                                        (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitAngle,
                                        DEPTH_RECURSE);
    context_parameters->mInitAngleRate = *UFG::qPropertySet::Get<float>(
                                            v5,
                                            (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitAngleRate,
                                            DEPTH_RECURSE);
    context_parameters->mInitAnglePatience = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitAnglePatience,
                                                DEPTH_RECURSE);
    context_parameters->mInitAngleWorldSpace = *UFG::qPropertySet::Get<bool>(
                                                  v5,
                                                  (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitAngleWorldSpace,
                                                  DEPTH_RECURSE);
    context_parameters->mInitAngleUseSecond = *UFG::qPropertySet::Get<bool>(
                                                 v5,
                                                 (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitAngleUseSecond,
                                                 DEPTH_RECURSE);
    context_parameters->mInitAngleSecond = *UFG::qPropertySet::Get<float>(
                                              v5,
                                              (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_InitAngleSecond,
                                              DEPTH_RECURSE);
    context_parameters->mYawRestrict = *UFG::qPropertySet::Get<bool>(
                                          v5,
                                          (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_YawRestrict,
                                          DEPTH_RECURSE);
    context_parameters->mYawConstrainRate = *UFG::qPropertySet::Get<float>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_YawConstrainRate,
                                               DEPTH_RECURSE);
    context_parameters->mYawMin = *UFG::qPropertySet::Get<float>(
                                     v5,
                                     (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_YawMin,
                                     DEPTH_RECURSE);
    context_parameters->mYawMax = *UFG::qPropertySet::Get<float>(
                                     v5,
                                     (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_YawMax,
                                     DEPTH_RECURSE);
    context_parameters->mUseLookUpDown = *UFG::qPropertySet::Get<bool>(
                                            v5,
                                            (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_UseLookUpDown,
                                            DEPTH_RECURSE);
    context_parameters->mHorizCompUseDirection = *UFG::qPropertySet::Get<bool>(
                                                    v5,
                                                    (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_HorizCompUseDirection,
                                                    DEPTH_RECURSE);
    context_parameters->mHorizCompOffsetScale = *UFG::qPropertySet::Get<float>(
                                                   v5,
                                                   (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_HorizCompOffsetScale,
                                                   DEPTH_RECURSE);
    context_parameters->mHorizCompSpeedWindowTimespan = *UFG::qPropertySet::Get<float>(
                                                           v5,
                                                           (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_HorizCompSpeedWindowTimespan,
                                                           DEPTH_RECURSE);
    context_parameters->mHorizCompSpeedMin = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_HorizCompSpeedMin,
                                                DEPTH_RECURSE);
    context_parameters->mHorizCompSpeedMax = *UFG::qPropertySet::Get<float>(
                                                v5,
                                                (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_HorizCompSpeedMax,
                                                DEPTH_RECURSE);
    context_parameters->mHorizCompDurationAttack = *UFG::qPropertySet::Get<float>(
                                                      v5,
                                                      (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_HorizCompDurationAttack,
                                                      DEPTH_RECURSE);
    context_parameters->mHorizCompDurationDecay = *UFG::qPropertySet::Get<float>(
                                                     v5,
                                                     (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_HorizCompDurationDecay,
                                                     DEPTH_RECURSE);
    context_parameters->mDesaturation = *UFG::qPropertySet::Get<float>(
                                           v5,
                                           (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_Desaturation,
                                           DEPTH_RECURSE);
    context_parameters->mDamageMultiplier = *UFG::qPropertySet::Get<float>(
                                               v5,
                                               (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_DamageMultiplier,
                                               DEPTH_RECURSE);
    context_parameters->mMotionblurMagnitude = *UFG::qPropertySet::Get<float>(
                                                  v5,
                                                  (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_MotionblurMagnitude,
                                                  DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<float>(v5, (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_FovMax, DEPTH_RECURSE);
    v9 = context_parameters;
    if ( v8 )
      v9 = (UFG::FollowCameraComponent::FollowParams *)v8;
    mTweakFov = context_parameters->mTweakFov;
    if ( context_parameters->mTweakFov <= v9->mTweakFov )
      mTweakFov = v9->mTweakFov;
    context_parameters->mTweakFovMax = mTweakFov;
  }
}

// File Line: 1499
// RVA: 0x3C6960
void __fastcall UFG::FollowCameraComponent::LoadContextParameters(UFG::FollowCameraComponent *this)
{
  int v2; // ebx
  __int64 v3; // rdi
  __int64 v4; // r8
  UFG::qString *v5; // rax
  UFG::qSymbol *v6; // rbx
  const char **v7; // rdi
  UFG::FollowCameraComponent::FollowParams *v8; // rsi
  __int64 v9; // rbp
  UFG::qString *v10; // rax
  UFG::qString result; // [rsp+28h] [rbp-50h] BYREF
  UFG::qSymbol context_symbol; // [rsp+88h] [rbp+10h] BYREF
  UFG::qSymbol v13; // [rsp+90h] [rbp+18h] BYREF
  UFG::qSymbol *p_context_symbol; // [rsp+98h] [rbp+20h]

  v2 = 0;
  v3 = 0i64;
  p_context_symbol = &context_symbol;
  do
  {
    v4 = v3;
    if ( v2 == 11 || v2 == 12 || v2 == 13 || v2 == 14 )
    {
      v4 = 0i64;
      if ( v3 )
        UFG::FollowCameraComponent::mContextParameterNames[v3] = UFG::FollowCameraComponent::mDefaultOverrideName;
    }
    v5 = UFG::qString::FormatEx(&result, "Cameras-%s", UFG::FollowCameraComponent::mContextParameterNames[v4]);
    UFG::qSymbol::create_from_string(&v13, v5->mData);
    UFG::qString::~qString(&result);
    context_symbol.mUID = v13.mUID;
    UFG::FollowCameraComponent::LoadContextParameters(this, &this->mContextParameters[v2], &context_symbol);
    UFG::FollowCameraComponent::mContextParameterSymbols[v3] = v13;
    ++v2;
    ++v3;
  }
  while ( v2 < 15 );
  p_context_symbol = &context_symbol;
  v6 = TweakableOverrideSymbols;
  v7 = TweakableOverrideNames;
  v8 = (UFG::FollowCameraComponent::FollowParams *)&TweakableOverrideParameters;
  v9 = 106i64;
  do
  {
    v10 = UFG::qString::FormatEx(&result, "Cameras-%s", *v7);
    UFG::qSymbol::create_from_string(&v13, v10->mData);
    UFG::qString::~qString(&result);
    context_symbol.mUID = v13.mUID;
    UFG::FollowCameraComponent::LoadContextParameters(this, v8, &context_symbol);
    v6->mUID = v13.mUID;
    ++v8;
    ++v7;
    ++v6;
    --v9;
  }
  while ( v9 );
}

// File Line: 1547
// RVA: 0x3C97A0
void __fastcall UFG::FollowCameraComponent::SetAimDeadZone(UFG::FollowCameraComponent *this, float fraction_fov)
{
  float v3; // xmm0_4
  __m128 y_low; // xmm3

  v3 = ((float (__fastcall *)(UFG::FollowCameraComponent *))this->vfptr[19].__vecDelDtor)(this);
  y_low = (__m128)LODWORD(this->mAimDeadZoneCentre.y);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->mEye.p0.y)
                                    * (float)(y_low.m128_f32[0] - this->mEye.p0.y))
                            + (float)((float)(this->mAimDeadZoneCentre.x - this->mEye.p0.x)
                                    * (float)(this->mAimDeadZoneCentre.x - this->mEye.p0.x)))
                    + (float)((float)(this->mAimDeadZoneCentre.z - this->mEye.p0.z)
                            * (float)(this->mAimDeadZoneCentre.z - this->mEye.p0.z));
  this->mAimDeadZoneRadius = _mm_sqrt_ps(y_low).m128_f32[0] * tanf(v3 * fraction_fov);
}

// File Line: 1564
// RVA: 0x3C9FA0
void __fastcall UFG::FollowCameraComponent::SetContext(
        UFG::FollowCameraComponent *this,
        UFG::FollowCameraContext context,
        char force_set)
{
  char size; // r13
  __int64 v4; // rbx
  __int32 v6; // ebp
  bool v7; // si
  char v8; // r15
  UFG::CharacterSubjectComponent *m_pSimComponent; // rcx
  int mTypeOverrideFreeman; // r8d
  __int64 v11; // r14
  UFG::qPropertySet *PropertySet; // r12
  UFG::FollowCameraContext mContext; // edx
  UFG::FollowCameraType mType; // eax
  unsigned int *p; // rbx
  char v16; // cl
  const char **v17; // rsi
  UFG::qSymbol *v18; // rbx
  hkSeekableStreamReader *v19; // rbp
  __int64 v20; // r15
  float v21; // xmm6_4
  unsigned __int32 v22; // eax
  float v23; // xmm13_4
  bool v24; // zf
  UFG::qString *v25; // rax
  float mTransitionTimeOverride; // xmm0_4
  bool v27; // dl
  __int64 v28; // rcx
  float v29; // xmm3_4
  float v30; // xmm5_4
  __int64 v31; // rax
  float v32; // xmm3_4
  float v33; // xmm5_4
  __int64 v34; // rax
  float v35; // xmm3_4
  float v36; // xmm5_4
  __int64 v37; // rax
  float v38; // xmm3_4
  float v39; // xmm5_4
  float v40; // xmm6_4
  float v41; // xmm8_4
  float v42; // xmm0_4
  __int128 x_low; // xmm9
  __int128 v44; // xmm7
  float v45; // xmm6_4
  float v46; // xmm1_4
  float v47; // xmm12_4
  __m128 v48; // xmm8
  float v49; // xmm12_4
  __m128 v50; // xmm11
  float v51; // xmm14_4
  float v52; // xmm12_4
  __m128 v53; // xmm1
  float mLatitudeMin; // xmm6_4
  float v55; // xmm8_4
  float v56; // xmm3_4
  float v57; // xmm9_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v62; // xmm4_4
  float v63; // xmm3_4
  __m128 v64; // xmm2
  __m128 v65; // xmm5
  float v66; // xmm1_4
  float v67; // xmm2_4
  float v68; // xmm6_4
  Render::DebugDrawContext *v69; // rbx
  UFG::CharacterSubjectComponent::SrcTransform mSrcPosition; // ecx
  __m128 v71; // xmm1
  float v72; // xmm0_4
  float mTweakEyeRise; // xmm3_4
  float v74; // xmm2_4
  float v75; // xmm0_4
  float mInitRadius; // xmm0_4
  bool mUseInitAngle; // si
  bool v78; // dl
  float v79; // xmm1_4
  bool v80; // al
  float x; // xmm8_4
  float v82; // xmm9_4
  float v83; // xmm6_4
  float v84; // xmm7_4
  UFG::qString v85; // [rsp+40h] [rbp-128h] BYREF
  UFG::qString v86; // [rsp+68h] [rbp-100h] BYREF
  UFG::qSymbol propSetName; // [rsp+170h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+178h] [rbp+10h] BYREF
  UFG::qArray<unsigned long,0> context_symbol; // [rsp+180h] [rbp+18h] BYREF

  LOBYTE(context_symbol.size) = force_set;
  size = force_set;
  v4 = context;
  v6 = (unsigned int)(context - 4) <= 3 || context == eFOLLOW_CONTEXT_OVERRIDE_AIM;
  v7 = this->mContext != context;
  v8 = 0;
  if ( this->mTarget.m_pSimComponent )
  {
    m_pSimComponent = (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent;
    mTypeOverrideFreeman = m_pSimComponent->mTypeOverrideFreeman;
    if ( mTypeOverrideFreeman != -1 && context != eFOLLOW_CONTEXT_AIM_PHONE )
    {
      v6 = m_pSimComponent->mTypeOverrideFreeman;
      UFG::CharacterSubjectComponent::GetContextOverride(m_pSimComponent, &result, mTypeOverrideFreeman);
      if ( v7 || result.mUID != UFG::FollowCameraComponent::mContextParameterSymbols[v4].mUID )
        v7 = 1;
      UFG::FollowCameraComponent::mContextParameterSymbols[v4] = result;
      v8 = 1;
    }
  }
  if ( (unsigned int)(v4 - 11) <= 1 )
  {
    UFG::CharacterSubjectComponent::GetContextOverride(
      (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
      &result,
      v6);
    if ( v7 || result.mUID != UFG::FollowCameraComponent::mContextParameterSymbols[v4].mUID )
      v7 = 1;
    UFG::FollowCameraComponent::mContextParameterSymbols[v4] = result;
    v8 = 1;
  }
  if ( size || v7 )
  {
    v11 = v4;
    propSetName.mUID = UFG::FollowCameraComponent::mContextParameterSymbols[v4].mUID;
    PropertySet = UFG::PropertySetManager::GetPropertySet(&propSetName);
    if ( PropertySet )
    {
      mContext = this->mContext;
      LOBYTE(result.mUID) = (unsigned int)(mContext - 5) <= 1;
      mType = v6;
      if ( !size )
        mType = this->mType;
      this->mPreviousType = mType;
      if ( size )
        mContext = (int)v4;
      this->mPreviousContext = mContext;
      this->mType = v6;
      this->mContext = v4;
      p = (unsigned int *)UFG::FollowCameraComponent::mContextParameterNames[mContext];
      context_symbol.p = p;
      if ( v8 )
      {
        v16 = 0;
        v17 = TweakableOverrideNames;
        v18 = TweakableOverrideSymbols;
        v19 = &TweakableOverrideParameters;
        v20 = 106i64;
        do
        {
          if ( propSetName.mUID == v18->mUID )
          {
            UFG::qMemCopy(&this->mContextParameters[v11], v19, 0x13Cu);
            UFG::FollowCameraComponent::mContextParameterNames[v11] = *v17;
            v16 = 1;
          }
          v19 = (hkSeekableStreamReader *)((char *)v19 + 316);
          ++v18;
          ++v17;
          --v20;
        }
        while ( v20 );
        size = context_symbol.size;
        if ( !v16 )
        {
          context_symbol.size = (unsigned int)UFG::FollowCameraComponent::mContextParameterSymbols[0];
          UFG::FollowCameraComponent::LoadContextParameters(
            this,
            &this->mContextParameters[v11],
            (UFG::qSymbol *)&context_symbol);
          UFG::FollowCameraComponent::mContextParameterNames[v11] = UFG::FollowCameraComponent::mDefaultOverrideName;
        }
        p = context_symbol.p;
      }
      UFG::FollowCameraComponent::InitBlendedParams(this);
      UFG::FollowCameraComponent::UpdateTweaker(this, 0.0);
      UFG::FollowCameraComponent::Rotate(this, 0.0, 0.0);
      v21 = 0.0;
      v22 = this->mContext - 5;
      v23 = *(float *)&FLOAT_1_0;
      v24 = LOBYTE(result.mUID) == v22 <= 1;
      this->mSnapNext = LOBYTE(result.mUID) ^ (v22 <= 1);
      if ( !v24 )
        goto LABEL_53;
      UFG::qString::qString(&v86, "TransitionFrom");
      UFG::operator+(&v85, v25, (const char *)p);
      UFG::qString::~qString(&v86);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&context_symbol, v85.mData);
      if ( UFG::qPropertySet::PropertyExists(PropertySet, &context_symbol, DEPTH_RECURSE) )
      {
        v21 = *UFG::qPropertySet::Get<float>(PropertySet, &context_symbol, DEPTH_RECURSE);
        UFG::qSPrintf(gTransitionString, 127, "Transition From %s: %f", (const char *)p, v21);
      }
      else if ( UFG::qPropertySet::PropertyExists(
                  PropertySet,
                  (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_TransitionTime,
                  DEPTH_RECURSE) )
      {
        v21 = *UFG::qPropertySet::Get<float>(
                 PropertySet,
                 (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_TransitionTime,
                 DEPTH_RECURSE);
        UFG::qSPrintf(gTransitionString, 127, "Transition Time: %f", v21);
      }
      mTransitionTimeOverride = this->mTransitionTimeOverride;
      if ( mTransitionTimeOverride != -1.0 && v21 != 0.0 )
      {
        v21 = this->mTransitionTimeOverride;
        this->mTransitionTimeOverride = -1.0;
        UFG::qSPrintf(gTransitionString, 127, "Transition Time Override: %f", mTransitionTimeOverride);
      }
      if ( UFG::gTweakOverrideTransitionTimeEnable )
        v21 = UFG::gTweakOverrideTransitionTime;
      UFG::qString::~qString(&v85);
      if ( v21 > 0.0 )
      {
        this->mBlend = 1.0;
        if ( v21 <= 0.001 )
          v21 = FLOAT_0_001;
        this->mBlendRate = 1.0 / v21;
        if ( (_S9_8 & 1) == 0 )
        {
          _S9_8 |= 1u;
          UFG::qSymbol::create_from_string(&contextSymbolLeap, "Cameras-FollowCameraLeap");
          atexit(UFG::FollowCameraComponent::SetContext_::_44_::_dynamic_atexit_destructor_for__contextSymbolLeap__);
        }
        v27 = UFG::qStringFind((const char *)p, "POI") != 0i64;
        v28 = this->mContext;
        if ( this->mType != eFOLLOW_CAMERA_TYPE_AIM
          && propSetName.mUID != contextSymbolLeap.mUID
          && (!v27 || this->mOldParams.mSrcPosition != this->mContextParameters[v28].mSrcPosition) )
        {
          v29 = this->mOldParams.mTweakCamThru.y
              - (float)(this->mOldParams.mTweakCamThru.y - this->mContextParameters[v28].mTweakCamThru.y);
          v30 = this->mOldParams.mTweakCamThru.z
              - (float)(this->mOldParams.mTweakCamThru.z - this->mContextParameters[v28].mTweakCamThru.z);
          this->mOldParams.mTweakCamThru.x = this->mOldParams.mTweakCamThru.x
                                           - (float)(this->mOldParams.mTweakCamThru.x
                                                   - this->mContextParameters[v28].mTweakCamThru.x);
          this->mOldParams.mTweakCamThru.y = v29;
          this->mOldParams.mTweakCamThru.z = v30;
          v31 = this->mContext;
          v32 = this->mOldParams.mTweakLookOffset.y
              - (float)(this->mOldParams.mTweakLookOffset.y - this->mContextParameters[v31].mTweakLookOffset.y);
          v33 = this->mOldParams.mTweakLookOffset.z
              - (float)(this->mOldParams.mTweakLookOffset.z - this->mContextParameters[v31].mTweakLookOffset.z);
          this->mOldParams.mTweakLookOffset.x = this->mOldParams.mTweakLookOffset.x
                                              - (float)(this->mOldParams.mTweakLookOffset.x
                                                      - this->mContextParameters[v31].mTweakLookOffset.x);
          this->mOldParams.mTweakLookOffset.y = v32;
          this->mOldParams.mTweakLookOffset.z = v33;
          v34 = this->mContext;
          v35 = this->mOldParams.mTweakAimThru.y
              - (float)(this->mOldParams.mTweakAimThru.y - this->mContextParameters[v34].mTweakAimThru.y);
          v36 = this->mOldParams.mTweakAimThru.z
              - (float)(this->mOldParams.mTweakAimThru.z - this->mContextParameters[v34].mTweakAimThru.z);
          this->mOldParams.mTweakAimThru.x = this->mOldParams.mTweakAimThru.x
                                           - (float)(this->mOldParams.mTweakAimThru.x
                                                   - this->mContextParameters[v34].mTweakAimThru.x);
          this->mOldParams.mTweakAimThru.y = v35;
          this->mOldParams.mTweakAimThru.z = v36;
          v37 = this->mContext;
          v38 = this->mOldParams.mTweakBaseOffset.y
              - (float)(this->mOldParams.mTweakBaseOffset.y - this->mContextParameters[v37].mTweakBaseOffset.y);
          v39 = this->mOldParams.mTweakBaseOffset.z
              - (float)(this->mOldParams.mTweakBaseOffset.z - this->mContextParameters[v37].mTweakBaseOffset.z);
          this->mOldParams.mTweakBaseOffset.x = this->mOldParams.mTweakBaseOffset.x
                                              - (float)(this->mOldParams.mTweakBaseOffset.x
                                                      - this->mContextParameters[v37].mTweakBaseOffset.x);
          this->mOldParams.mTweakBaseOffset.y = v38;
          this->mOldParams.mTweakBaseOffset.z = v39;
        }
      }
      else
      {
LABEL_53:
        *(_QWORD *)&this->mBlend = 0i64;
        UFG::FollowCameraComponent::FollowParams::operator=(
          &this->mBlendedParams,
          &this->mContextParameters[this->mContext]);
        this->mSnapNext = 1;
        UFG::qSPrintf(gTransitionString, 127, "Transition Snap");
      }
      if ( size )
      {
        UFG::FollowCameraComponent::FollowParams::operator=(
          &this->mBlendedParams,
          &this->mContextParameters[this->mContext]);
        UFG::FollowCameraComponent::FollowParams::operator=(&this->mOldParams, &this->mBlendedParams);
      }
      if ( this->mType == eFOLLOW_CAMERA_TYPE_TOW && (unsigned int)(this->mPreviousType - 1) <= 1 )
      {
        this->mMouseBoomSet = 0;
        v40 = atan2f(
                COERCE_FLOAT(LODWORD(this->mControllerForward.y) ^ _xmm[0]),
                COERCE_FLOAT(LODWORD(this->mControllerForward.x) ^ _xmm[0]));
        v41 = sinf(v40);
        v42 = cosf(v40);
        x_low = LODWORD(this->mBlendedParams.mTweakCamThru.x);
        v44 = x_low;
        v45 = (float)((float)(this->mBlendedParams.mTweakCamThru.x * v41) + this->mTargetWorld.v3.y)
            + (float)(this->mBlendedParams.mTweakCamThru.y * v42);
        *(float *)&x_low = (float)((float)(*(float *)&x_low * v42) + this->mTargetWorld.v3.x)
                         + (float)(COERCE_FLOAT(LODWORD(v41) ^ _xmm[0]) * this->mBlendedParams.mTweakCamThru.y);
        *(float *)&v44 = (float)((float)((float)(*(float *)&v44 * 0.0) + this->mTargetWorld.v3.z)
                               + (float)(this->mBlendedParams.mTweakCamThru.y * 0.0))
                       + this->mBlendedParams.mTweakCamThru.z;
        v46 = (float)((float)(1.0 - this->mMaxRadiusOverrideParam) * this->mBlendedParams.mTweakRadiusMax)
            + (float)(this->mMaxRadiusOverrideParam * this->mMaxRadiusOverride);
        v48 = (__m128)v44;
        v48.m128_f32[0] = *(float *)&v44 + (float)((float)(this->mAimEye.p1.z - this->mAimLook.p1.z) * v46);
        v47 = v45 + (float)((float)(this->mAimEye.p1.y - this->mAimLook.p1.y) * v46);
        v50 = (__m128)x_low;
        v50.m128_f32[0] = *(float *)&x_low + (float)((float)(this->mAimEye.p1.x - this->mAimLook.p1.x) * v46);
        LODWORD(this->mLook.p1.x) = x_low;
        this->mLook.p1.y = v45;
        LODWORD(this->mLook.p1.z) = v44;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
        *(_QWORD *)&this->mLook.mParameter.x = 0i64;
        this->mLook.mParameter.z = 0.0;
        v48.m128_f32[0] = v48.m128_f32[0] - *(float *)&v44;
        v49 = v47 - v45;
        v50.m128_f32[0] = v50.m128_f32[0] - *(float *)&x_low;
        if ( v48.m128_f32[0] < 0.0 )
          v48.m128_f32[0] = v48.m128_f32[0] / this->mOrbitSquish;
        v51 = atan2f(v49, v50.m128_f32[0]);
        v52 = v49 * v49;
        v50.m128_f32[0] = v50.m128_f32[0] * v50.m128_f32[0];
        v53 = v50;
        v53.m128_f32[0] = v50.m128_f32[0] + v52;
        mLatitudeMin = atan2f(v48.m128_f32[0], _mm_sqrt_ps(v53).m128_f32[0])
                     + UFG::FollowCameraComponent::rAimReturnPitch;
        if ( mLatitudeMin <= this->mLatitudeMin )
          mLatitudeMin = this->mLatitudeMin;
        if ( mLatitudeMin >= this->mBlendedParams.mTweakLatitudeMax )
          mLatitudeMin = this->mBlendedParams.mTweakLatitudeMax;
        v48.m128_f32[0] = (float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v50.m128_f32[0] + v52);
        sinf(mLatitudeMin);
        cosf(mLatitudeMin);
        sinf(v51);
        v55 = mLatitudeMin * _mm_sqrt_ps(v48).m128_f32[0];
        v56 = v55 * cosf(v51);
        v57 = v55 * v51;
        if ( v55 < 0.0 )
          v55 = v55 * this->mOrbitSquish;
        v58 = this->mLook.p1.z + v55;
        v59 = this->mLook.p1.y + v57;
        this->mEye.p1.x = this->mLook.p1.x + v56;
        this->mEye.p1.y = v59;
        this->mEye.p1.z = v58;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
        *(_QWORD *)&this->mEye.mParameter.x = 0i64;
        this->mEye.mParameter.z = 0.0;
        y = UFG::qVector3::msZero.y;
        z = UFG::qVector3::msZero.z;
        this->mVelocity.p1.x = UFG::qVector3::msZero.x;
        this->mVelocity.p1.y = y;
        this->mVelocity.p1.z = z;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mVelocity);
        *(_QWORD *)&this->mVelocity.mParameter.x = 0i64;
        this->mVelocity.mParameter.z = 0.0;
        v64 = (__m128)LODWORD(this->mEye.p1.x);
        v62 = this->mEye.p1.z - this->mLook.p1.z;
        v63 = this->mEye.p1.y - this->mLook.p1.y;
        v64.m128_f32[0] = v64.m128_f32[0] - this->mLook.p1.x;
        v65 = v64;
        v65.m128_f32[0] = (float)((float)(v64.m128_f32[0] * v64.m128_f32[0]) + (float)(v63 * v63)) + (float)(v62 * v62);
        if ( v65.m128_f32[0] == 0.0 )
          v66 = 0.0;
        else
          v66 = 1.0 / _mm_sqrt_ps(v65).m128_f32[0];
        this->mControllerForward.x = v64.m128_f32[0] * v66;
        this->mControllerForward.y = v63 * v66;
        this->mControllerForward.z = v62 * v66;
        if ( this->mPreviousContext == eFOLLOW_CONTEXT_AIM_SNIPER )
          this->mSnapNext = 1;
      }
      UFG::FollowCameraComponent::UpdateLocalWorld(this, 0.0);
      if ( this->mTarget.m_pSimComponent && this->mSnapNext )
      {
        v67 = (float)((float)((float)(this->mBlendedParams.mTweakCamThru.y * this->mTargetWorld.v1.y)
                            + (float)(this->mBlendedParams.mTweakCamThru.x * this->mTargetWorld.v0.y))
                    + (float)(this->mBlendedParams.mTweakCamThru.z * this->mTargetWorld.v2.y))
            + this->mTargetWorld.v3.y;
        v68 = (float)((float)((float)(this->mBlendedParams.mTweakCamThru.y * this->mTargetWorld.v1.z)
                            + (float)(this->mBlendedParams.mTweakCamThru.x * this->mTargetWorld.v0.z))
                    + (float)(this->mBlendedParams.mTweakCamThru.z * this->mTargetWorld.v2.z))
            + this->mTargetWorld.v3.z;
        this->mLook.p1.x = (float)((float)((float)(this->mBlendedParams.mTweakCamThru.y * this->mTargetWorld.v1.x)
                                         + (float)(this->mBlendedParams.mTweakCamThru.x * this->mTargetWorld.v0.x))
                                 + (float)(this->mBlendedParams.mTweakCamThru.z * this->mTargetWorld.v2.x))
                         + this->mTargetWorld.v3.x;
        this->mLook.p1.y = v67;
        this->mLook.p1.z = v68;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
        *(_QWORD *)&this->mLook.mParameter.x = 0i64;
        this->mLook.mParameter.z = 0.0;
      }
      v69 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      if ( !this->mBlendedParams.mUseInitRise )
        goto LABEL_96;
      this->mGotoRiseElaspedTime = 0.0;
      this->mGotoRisePatience = this->mBlendedParams.mInitRisePatience;
      this->mGotoRiseRate = this->mBlendedParams.mInitRiseRate;
      if ( !this->mAutoFrameActive
        || this->mBlendedParams.mSrcOrientation == SrcTransform_POI
        || (mSrcPosition = this->mBlendedParams.mSrcPosition, mSrcPosition == SrcTransform_POI) )
      {
        this->mGotoRise = this->mBlendedParams.mInitRise;
LABEL_94:
        if ( UFG::bCameraDebugText )
        {
          Render::DebugDrawContext::DrawTextA(
            v69,
            640,
            464,
            &UFG::qColour::White,
            "Init EyeRise: %f",
            this->mBlendedParams.mInitRise);
          Render::DebugDrawContext::DrawTextA(
            v69,
            640,
            476,
            &UFG::qColour::White,
            "AutoFramed InitRise: %f",
            this->mRiseOverride);
        }
LABEL_96:
        if ( this->mBlendedParams.mUseInitRadius )
        {
          this->mGotoRadiusElaspedTime = 0.0;
          this->mGotoRadiusPatience = this->mBlendedParams.mInitRadiusPatience;
          this->mGotoRadiusRate = this->mBlendedParams.mInitRadiusRate;
          mInitRadius = this->mBlendedParams.mInitRadius;
          this->mGotoRadius = mInitRadius;
          if ( UFG::bCameraDebugText )
            Render::DebugDrawContext::DrawTextA(v69, 640, 488, &UFG::qColour::White, "Goto InitRadius:%f", mInitRadius);
        }
        mUseInitAngle = this->mBlendedParams.mUseInitAngle;
        if ( (_S9_8 & 2) == 0 )
        {
          _S9_8 |= 2u;
          UFG::qSymbol::create_from_string(&contextSymbolSprint, "Cameras-FollowCameraSprint");
          atexit(UFG::FollowCameraComponent::SetContext_::_88_::_dynamic_atexit_destructor_for__contextSymbolSprint__);
        }
        v78 = this->mType == eFOLLOW_CAMERA_TYPE_TOW
           && UFG::FollowCameraComponent::mContextParameterSymbols[this->mContext].mUID == contextSymbolSprint.mUID;
        if ( (!UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController || !v78)
          && mUseInitAngle )
        {
          this->mGotoAngleElaspedTime = 0.0;
          this->mGotoAnglePatience = this->mBlendedParams.mInitAnglePatience;
          this->mGotoAngleRate = (float)(this->mBlendedParams.mInitAngleRate * 3.1415927) * 0.0055555557;
          v79 = (float)(this->mBlendedParams.mInitAngle * 3.1415927) * 0.0055555557;
          this->mGotoAngle = v79;
          v80 = !this->mBlendedParams.mInitAngleWorldSpace;
          this->mGotoAngleLocalSpace = v80;
          if ( this->mBlendedParams.mInitAngleUseSecond )
            this->mGotoAngle = UFG::FollowCameraComponent::GetClosestAngle(
                                 this,
                                 v79,
                                 (float)(this->mBlendedParams.mInitAngleSecond * 3.1415927) * 0.0055555557,
                                 !v80,
                                 0);
          if ( UFG::bCameraDebugText )
            Render::DebugDrawContext::DrawTextA(
              v69,
              640,
              500,
              &UFG::qColour::White,
              "Goto InitAngle:%f",
              this->mGotoAngle);
        }
        if ( this->mType != eFOLLOW_CAMERA_TYPE_AIM )
          goto LABEL_116;
        if ( this->mPreviousType != eFOLLOW_CAMERA_TYPE_AIM )
        {
          x = this->mBlendedParams.mTweakBaseOffset.x;
          v82 = this->mBlendedParams.mTweakBaseOffset.y;
          v83 = this->mOldParams.mTweakBaseOffset.x;
          v84 = this->mOldParams.mTweakBaseOffset.y;
          UFG::FollowCameraComponent::FollowParams::operator=(
            &this->mBlendedParams,
            &this->mContextParameters[this->mContext]);
          UFG::FollowCameraComponent::FollowParams::operator=(&this->mOldParams, &this->mBlendedParams);
          this->mBlendedParams.mTweakBaseOffset.x = x;
          this->mBlendedParams.mTweakBaseOffset.y = v82;
          this->mOldParams.mTweakBaseOffset.x = v83;
          this->mOldParams.mTweakBaseOffset.y = v84;
        }
        if ( this->mType != eFOLLOW_CAMERA_TYPE_AIM )
        {
LABEL_116:
          if ( this->mPreviousType == eFOLLOW_CAMERA_TYPE_AIM )
            this->bAimUseEyeLook = 0;
        }
        this->mFov.p1 = this->mBlendedParams.mTweakFov;
        UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
        this->mFov.mParameter = 0.0;
        return;
      }
      v71 = (__m128)LODWORD(this->mEye.p0.x);
      v72 = this->mEye.p0.y - this->mLook.p0.y;
      v71.m128_f32[0] = (float)((float)(v71.m128_f32[0] - this->mLook.p0.x) * (float)(v71.m128_f32[0] - this->mLook.p0.x))
                      + (float)(v72 * v72);
      v74 = (float)(_mm_sqrt_ps(v71).m128_f32[0] - this->mBlendedParams.mTweakRadiusMax)
          / (float)(UFG::FollowCameraComponent::rAutoFrameMinRadius - this->mBlendedParams.mTweakRadiusMax);
      if ( v74 <= 0.0 )
      {
        v74 = 0.0;
      }
      else if ( v74 >= 1.0 )
      {
LABEL_83:
        mTweakEyeRise = this->mContextParameters[this->mContext].mTweakEyeRise;
        v75 = (float)((float)(UFG::FollowCameraComponent::rAutoFrameMinEyeRise - mTweakEyeRise) * v23) + mTweakEyeRise;
        switch ( mSrcPosition )
        {
          case SrcTransform_FocusCreaturePelvis:
          case SrcTransform_Pelvis:
            v75 = v75 + 0.80000001;
            break;
          case SrcTransform_Camera:
          case SrcTransform_FocusCreatureCambone:
            v75 = v75 + 1.2;
            break;
          case SrcTransform_Head:
          case SrcTransform_FocusCreatureHead:
            v75 = v75 + 2.0;
            break;
        }
        this->mGotoRise = v75;
        goto LABEL_94;
      }
      v23 = v74;
      goto LABEL_83;
    }
  }
}
        goto LABEL_94;
      }
      v23 = v74;
      goto LABEL_83;
    }
  }
}

// File Line: 1899
// RVA: 0x3CEE00
void __fastcall UFG::FollowCameraComponent::TransitionFromBlendOrientation(
        UFG::FollowCameraComponent *this,
        UFG::BaseCameraComponent *fromCamera,
        float eyeRateMin,
        float eyeRateMax,
        float orientRateMin,
        float orientRateMax)
{
  float z; // xmm7_4
  __m128 y_low; // xmm10
  __int128 z_low; // xmm11
  float v11; // xmm15_4
  __int128 v13; // xmm12
  __m128 v14; // xmm13
  __m128 v15; // xmm2
  float v16; // xmm8_4
  float v17; // xmm0_4
  __int128 v18; // xmm14
  float v19; // xmm7_4
  __m128 v20; // xmm2
  float v21; // xmm1_4
  float v22; // xmm11_4
  __m128 x_low; // xmm5
  float v24; // xmm4_4
  float v25; // xmm13_4
  __m128 v26; // xmm2
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm11_4
  __int128 v31; // xmm3
  float v32; // xmm4_4
  __m128 v33; // xmm2
  float v34; // xmm4_4
  __m128 v35; // xmm5
  float v36; // xmm1_4
  float v37; // xmm5_4
  __m128 v38; // xmm11
  float v39; // xmm2_4
  __m128 v40; // xmm4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm8_4
  float v44; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float v46; // [rsp+20h] [rbp-128h]
  unsigned int v47; // [rsp+28h] [rbp-120h] BYREF
  float v48; // [rsp+2Ch] [rbp-11Ch]
  float v49; // [rsp+30h] [rbp-118h]
  char v50[24]; // [rsp+38h] [rbp-110h] BYREF
  UFG::qMatrix44 mat; // [rsp+50h] [rbp-F8h] BYREF
  float x; // [rsp+150h] [rbp+8h]
  float y; // [rsp+158h] [rbp+10h]
  float v55; // [rsp+168h] [rbp+20h]

  z = fromCamera->mEyeCurr.z;
  x = fromCamera->mLookCurr.x;
  y = fromCamera->mLookCurr.y;
  y_low = (__m128)LODWORD(fromCamera->mEyeCurr.y);
  z_low = LODWORD(fromCamera->mLookCurr.z);
  v55 = z;
  v11 = fromCamera->mEyeCurr.x;
  v46 = fromCamera->mLookCurr.z;
  v13 = LODWORD(x);
  v14 = (__m128)LODWORD(y);
  *(float *)&v13 = x - v11;
  v14.m128_f32[0] = y - y_low.m128_f32[0];
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, unsigned int *))fromCamera->vfptr[25].__vecDelDtor)(
    fromCamera,
    v50,
    &v47);
  v15 = (__m128)v47;
  v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v48 * v48)) + (float)(v49 * v49);
  LODWORD(v16) = _mm_sqrt_ps(v15).m128_u32[0];
  ((void (__fastcall *)(UFG::FollowCameraComponent *))this->vfptr[15].__vecDelDtor)(this);
  UFG::FollowCameraComponent::Snap(this);
  v17 = atan2f(
          COERCE_FLOAT(COERCE_UNSIGNED_INT(y - y_low.m128_f32[0]) ^ _xmm[0]),
          COERCE_FLOAT(COERCE_UNSIGNED_INT(x - v11) ^ _xmm[0]));
  UFG::FollowCameraComponent::GotoAngleSnap(this, v17, 1);
  v18 = z_low;
  v20 = v14;
  this->mTransitionFromEye.z = z;
  this->mTransitionFromEye.x = v11;
  LODWORD(this->mTransitionFromEye.y) = y_low.m128_i32[0];
  *(float *)&v18 = *(float *)&z_low - z;
  v19 = *(float *)&FLOAT_1_0;
  v20.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(*(float *)&v13 * *(float *)&v13))
                  + (float)(*(float *)&v18 * *(float *)&v18);
  if ( v20.m128_f32[0] == 0.0 )
    v21 = 0.0;
  else
    v21 = 1.0 / _mm_sqrt_ps(v20).m128_f32[0];
  v22 = fromCamera->mCamera.mTransformation.v1.y;
  x_low = (__m128)LODWORD(fromCamera->mCamera.mTransformation.v1.x);
  v24 = fromCamera->mCamera.mTransformation.v1.z;
  *(float *)&v13 = *(float *)&v13 * v21;
  v25 = v14.m128_f32[0] * v21;
  *(float *)&v18 = *(float *)&v18 * v21;
  mat.v0.w = 0.0;
  v26 = x_low;
  LODWORD(mat.v0.x) = v13;
  mat.v0.y = v25;
  LODWORD(mat.v0.z) = v18;
  v26.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v22 * v22)) + (float)(v24 * v24);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
  v28 = x_low.m128_f32[0] * v27;
  v29 = v24 * v27;
  v30 = v22 * v27;
  v31 = v18;
  v33 = (__m128)v13;
  v33.m128_f32[0] = *(float *)&v13 * v29;
  *(float *)&v31 = (float)(*(float *)&v18 * v30) - (float)(v25 * v29);
  v32 = v25 * v28;
  v33.m128_f32[0] = v33.m128_f32[0] - (float)(*(float *)&v18 * v28);
  v35 = v33;
  v34 = v32 - (float)(*(float *)&v13 * v30);
  v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(*(float *)&v31 * *(float *)&v31))
                  + (float)(v34 * v34);
  if ( v35.m128_f32[0] == 0.0 )
    v36 = 0.0;
  else
    v36 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
  *(float *)&v31 = *(float *)&v31 * v36;
  mat.v1.w = 0.0;
  mat.v1.z = v34 * v36;
  mat.v1.y = v33.m128_f32[0] * v36;
  LODWORD(mat.v1.x) = v31;
  v38 = (__m128)v31;
  v37 = (float)((float)(v34 * v36) * v25) - (float)((float)(v33.m128_f32[0] * v36) * *(float *)&v18);
  v38.m128_f32[0] = (float)(*(float *)&v31 * *(float *)&v18) - (float)((float)(v34 * v36) * *(float *)&v13);
  v39 = (float)((float)(v33.m128_f32[0] * v36) * *(float *)&v13) - (float)(*(float *)&v31 * v25);
  v40 = v38;
  v40.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0]) + (float)(v37 * v37)) + (float)(v39 * v39);
  if ( v40.m128_f32[0] == 0.0 )
    v41 = 0.0;
  else
    v41 = 1.0 / _mm_sqrt_ps(v40).m128_f32[0];
  mat.v3.x = v11;
  LODWORD(mat.v3.y) = y_low.m128_i32[0];
  mat.v2.w = 0.0;
  mat.v3.w = 1.0;
  mat.v2.y = v38.m128_f32[0] * v41;
  mat.v2.x = v37 * v41;
  mat.v3.z = v55;
  mat.v2.z = v39 * v41;
  UFG::qQuaternion::Set(&this->mTransitionFromOri, &mat);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                            + (float)((float)(v11 - x) * (float)(v11 - x)))
                    + (float)((float)(v55 - v46) * (float)(v55 - v46));
  LODWORD(this->mTransitionFromLen) = _mm_sqrt_ps(y_low).m128_u32[0];
  v42 = (float)(v16 - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin)
      / (float)(UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
              - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin);
  if ( v42 <= 0.0 )
  {
    v42 = 0.0;
  }
  else if ( v42 >= 1.0 )
  {
    v42 = *(float *)&FLOAT_1_0;
  }
  this->mTransitionParamRateEye = (float)((float)(eyeRateMax - eyeRateMin) * v42) + eyeRateMin;
  v43 = (float)(v16 - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin)
      / (float)(UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
              - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin);
  if ( v43 <= 0.0 )
  {
    v43 = 0.0;
    goto LABEL_21;
  }
  if ( v43 < 1.0 )
LABEL_21:
    v19 = v43;
  this->mTransitionParamRateOrient = (float)((float)(orientRateMax - orientRateMin) * v19) + orientRateMin;
  if ( UFG::FollowCameraComponent::bTransitionToFollowOverride )
  {
    this->mTransitionParamRateEye = UFG::FollowCameraComponent::rTransitionToFollowEyeRateOverride;
    this->mTransitionParamRateOrient = UFG::FollowCameraComponent::rTransitionToFollowOrientRateOverride;
  }
  this->mTransitionParamEye = 1.0;
  this->mTransitionParamOrient = 1.0;
  ((void (__fastcall *)(UFG::BaseCameraComponent *))fromCamera->vfptr[19].__vecDelDtor)(fromCamera);
  v44 = ((float (__fastcall *)(UFG::BaseCameraComponent *))fromCamera->vfptr[19].__vecDelDtor)(fromCamera);
  vfptr = fromCamera->vfptr;
  if ( v44 <= 3.1415927 )
    v44 = (float)(((float (__fastcall *)(UFG::BaseCameraComponent *))vfptr[19].__vecDelDtor)(fromCamera) * 180.0)
        * 0.31830987;
  else
    ((void (__fastcall *)(UFG::BaseCameraComponent *))vfptr[19].__vecDelDtor)(fromCamera);
  this->mFov.p1 = v44;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  this->mFov.p0 = this->mFov.p1;
  this->mFov.v0 = this->mFov.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  ((void (__fastcall *)(UFG::FollowCameraComponent *))this->vfptr[15].__vecDelDtor)(this);
}

// File Line: 1950
// RVA: 0x3CF390
void __fastcall UFG::FollowCameraComponent::TransitionFromSuppDuration(
        UFG::FollowCameraComponent *this,
        UFG::BaseCameraComponent *fromCamera,
        bool withVelocity)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rbx
  UFG::HomerCubic<UFG::qVector3> *v8; // rcx
  float x; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  __m128 v21; // xmm2
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v28; // rax
  float v29; // xmm0_4
  unsigned int v30; // [rsp+20h] [rbp-28h] BYREF
  float v31; // [rsp+24h] [rbp-24h]
  float v32; // [rsp+28h] [rbp-20h]
  char v33[24]; // [rsp+30h] [rbp-18h] BYREF

  y = fromCamera->mEyeCurr.y;
  z = fromCamera->mEyeCurr.z;
  p_mEye = &this->mEye;
  v8 = &this->mEye;
  if ( UFG::FollowCameraComponent::bTransitionToFollowOverride )
    withVelocity = UFG::FollowCameraComponent::bTransitionToFollowUseVelOverride;
  p_mEye->p1.x = fromCamera->mEyeCurr.x;
  p_mEye->p1.y = y;
  p_mEye->p1.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v8);
  *(_QWORD *)&p_mEye->mParameter.x = 0i64;
  p_mEye->mParameter.z = 0.0;
  x = p_mEye->p1.x;
  v11 = p_mEye->p1.z;
  p_mEye->p0.y = p_mEye->p1.y;
  p_mEye->p0.z = v11;
  p_mEye->p0.x = x;
  v12 = p_mEye->v1.y;
  v13 = p_mEye->v1.z;
  p_mEye->v0.x = p_mEye->v1.x;
  p_mEye->v0.y = v12;
  p_mEye->v0.z = v13;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mEye);
  *(_QWORD *)&p_mEye->mParameter.x = 0i64;
  p_mEye->mParameter.z = 0.0;
  v14 = fromCamera->mLookCurr.y;
  v15 = fromCamera->mLookCurr.z;
  this->mLook.p1.x = fromCamera->mLookCurr.x;
  this->mLook.p1.y = v14;
  this->mLook.p1.z = v15;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  v16 = this->mLook.p1.y;
  v17 = this->mLook.p1.z;
  this->mLook.p0.x = this->mLook.p1.x;
  this->mLook.p0.y = v16;
  this->mLook.p0.z = v17;
  v18 = this->mLook.v1.y;
  v19 = this->mLook.v1.z;
  this->mLook.v0.x = this->mLook.v1.x;
  this->mLook.v0.y = v18;
  this->mLook.v0.z = v19;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  vfptr = fromCamera->vfptr;
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, unsigned int *))vfptr[25].__vecDelDtor)(
    fromCamera,
    v33,
    &v30);
  v21 = (__m128)v30;
  v21.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v31 * v31)) + (float)(v32 * v32);
  v22 = _mm_sqrt_ps(v21).m128_f32[0];
  v23 = (float)(v22 - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin)
      / (float)(UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
              - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin);
  v24 = *(float *)&FLOAT_1_0;
  if ( v23 <= 0.0 )
  {
    v23 = 0.0;
  }
  else if ( v23 >= 1.0 )
  {
    v23 = *(float *)&FLOAT_1_0;
  }
  this->mTransitionParamRateSuppEye = (float)((float)(UFG::FollowCameraComponent::rTransitionToFollowParamRateMax
                                                    - UFG::FollowCameraComponent::rTransitionToFollowParamRateMin)
                                            * v23)
                                    + UFG::FollowCameraComponent::rTransitionToFollowParamRateMin;
  v25 = (float)(v22 - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin)
      / (float)(UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
              - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin);
  if ( v25 <= 0.0 )
  {
    v25 = 0.0;
    goto LABEL_11;
  }
  if ( v25 < 1.0 )
LABEL_11:
    v24 = v25;
  v26 = (float)((float)(UFG::FollowCameraComponent::rTransitionToFollowParamRateMax
                      - UFG::FollowCameraComponent::rTransitionToFollowParamRateMin)
              * v24)
      + UFG::FollowCameraComponent::rTransitionToFollowParamRateMin;
  this->mTransitionParamSuppEye = 1.0;
  this->mTransitionParamSuppLook = 1.0;
  this->mTransitionParamRateSuppLook = v26;
  UFG::BaseCameraComponent::TransitionFrom(this, fromCamera, withVelocity);
  ((void (__fastcall *)(UFG::BaseCameraComponent *))fromCamera->vfptr[19].__vecDelDtor)(fromCamera);
  v27 = ((float (__fastcall *)(UFG::BaseCameraComponent *))fromCamera->vfptr[19].__vecDelDtor)(fromCamera);
  v28 = fromCamera->vfptr;
  if ( v27 <= 3.1415927 )
    v27 = (float)(((float (__fastcall *)(UFG::BaseCameraComponent *))v28[19].__vecDelDtor)(fromCamera) * 180.0)
        * 0.31830987;
  else
    ((void (__fastcall *)(UFG::BaseCameraComponent *))v28[19].__vecDelDtor)(fromCamera);
  this->mFov.p1 = v27;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  this->mFov.v1 = 0.0;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  if ( UFG::SimComponent::IsType(fromCamera, UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID) )
  {
    this->mTransitionTimeOverride = UFG::FollowCameraComponent::rTransitionTimeFromAnimated;
  }
  else if ( UFG::SimComponent::IsType(fromCamera, UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID) )
  {
    this->mTransitionTimeOverride = UFG::FollowCameraComponent::rTransitionTimeFromProgression;
  }
  else
  {
    this->mTransitionTimeOverride = -1.0;
  }
  this->mTransitionSupplimentaryDuration = UFG::FollowCameraComponent::rTransitionToFollowSupplimentaryDuration;
  if ( UFG::SimComponent::IsType(fromCamera, UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID)
    || UFG::SimComponent::IsType(fromCamera, UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID) )
  {
    v29 = UFG::FollowCameraComponent::rTransitionToFollowSupplimentaryDurationFromNIS;
    goto LABEL_26;
  }
  if ( this->mTarget.m_pSimComponent
    && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[48].__vecDelDtor)(this->mTarget.m_pSimComponent) )
  {
    v29 = UFG::FollowCameraComponent::rTransitionToFollowSupplimentaryDurationActionHijack;
LABEL_26:
    this->mTransitionSupplimentaryDuration = v29;
  }
}

// File Line: 2010
// RVA: 0x3C2250
void __fastcall UFG::FollowCameraComponent::FollowCameraEventHandler(UFG::FollowCameraComponent *this, UFG::Event *e)
{
  unsigned int m_EventUID; // eax
  UFG::SimObjectGame *m_pSimObject; // rcx
  UFG::BaseCameraComponent *v6; // r14
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::Director *v9; // rax
  unsigned int v10; // eax
  signed __int16 v11; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool v13; // bl
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  __int64 v28; // r8
  UFG::SimObjectGame *v29; // rcx
  UFG::BaseCameraComponent *v30; // rdi
  UFG::SimComponent *v31; // rbx
  __int16 v32; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v34; // rcx
  __int16 v35; // dx
  UFG::SimComponent *v36; // rax
  bool v37; // r14
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::TargetingSystemBaseComponent *TargetingSystem; // rax
  UFG::TargetingMap *m_pTargetingMap; // rcx
  UFG::TargetingSimObject *m_pTargets; // rdx
  __int64 v42; // rax
  UFG::SimObject *m_pPointer; // rbp
  UFG::Director *v44; // rax

  m_EventUID = e->m_EventUID;
  if ( UFG::gEventDisMountVehicleCamera.mUID == m_EventUID )
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::ChaseCameraComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ChaseCameraComponent::_TypeUID);
      v6 = (UFG::BaseCameraComponent *)ComponentOfTypeHK;
    }
    else
    {
      v6 = 0i64;
    }
    if ( this->mTarget.m_pSimComponent->m_pSimObject == (UFG::SimObject *)e[1].mNext
      && v6
      && ((unsigned __int8 (__fastcall *)(UFG::BaseCameraComponent *))v6->vfptr[21].__vecDelDtor)(v6) )
    {
      v9 = UFG::Director::Get();
      UFG::Director::SetCurrentCamera(v9, this);
      UFG::GameCameraComponent::mNoRotationTimer = FLOAT_0_75;
      v10 = _S10_4;
      if ( (_S10_4 & 1) == 0 )
      {
        _S10_4 |= 1u;
        HASH_DismountShoot.mUID = UFG::qStringHashUpper32("DismountShoot", -1);
        v10 = _S10_4;
      }
      if ( (v10 & 2) == 0 )
      {
        _S10_4 = v10 | 2;
        mostUsedIndex_DismountShoot = GetMostUsedIndex(HASH_DismountShoot.mUID);
      }
      v13 = 0;
      if ( LocalPlayer )
      {
        v11 = LocalPlayer->m_Flags;
        if ( (v11 & 0x4000) != 0 )
        {
          m_pComponent = LocalPlayer->m_Components.p[7].m_pComponent;
        }
        else if ( v11 >= 0 )
        {
          if ( (v11 & 0x2000) != 0 )
            m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
          else
            m_pComponent = (v11 & 0x1000) != 0
                         ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::ActionTreeComponent::_TypeUID)
                         : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::ActionTreeComponent::_TypeUID);
        }
        else
        {
          m_pComponent = LocalPlayer->m_Components.p[7].m_pComponent;
        }
        if ( m_pComponent
          && ActionController::IsPlaying(
               (ActionController *)&m_pComponent[3],
               &HASH_DismountShoot,
               mostUsedIndex_DismountShoot,
               1) )
        {
          v13 = 1;
        }
      }
      if ( this->mTarget.m_pSimComponent
        && ((float (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[28].__vecDelDtor)(this->mTarget.m_pSimComponent) < 8.0
        || v13 )
      {
        UFG::FollowCameraComponent::TransitionFromBlendOrientation(
          this,
          v6,
          UFG::FollowCameraComponent::rTransitionToFollowParamRateMin,
          UFG::FollowCameraComponent::rTransitionToFollowParamRateMax,
          UFG::FollowCameraComponent::rTransitionToFollowParamRateMin,
          UFG::FollowCameraComponent::rTransitionToFollowParamRateMax,
          1);
      }
      else
      {
        x = v6->mEyeCurr.x;
        y = v6->mEyeCurr.y;
        z = v6->mEyeCurr.z;
        v17 = v6->mLookCurr.x;
        v18 = v6->mLookCurr.y;
        v19 = v6->mLookCurr.z;
        this->mAimOrigin.x = v17;
        this->mAimOrigin.y = v18;
        this->mAimOrigin.z = v19;
        this->mAimEye.p1.x = x;
        this->mAimEye.p1.y = y;
        this->mAimEye.p1.z = z;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
        *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
        this->mAimEye.mParameter.z = 0.0;
        v20 = this->mAimEye.p1.y;
        v21 = this->mAimEye.p1.z;
        this->mAimEye.p0.x = this->mAimEye.p1.x;
        this->mAimEye.p0.y = v20;
        this->mAimEye.p0.z = v21;
        v22 = this->mAimEye.v1.y;
        v23 = this->mAimEye.v1.z;
        this->mAimEye.v0.x = this->mAimEye.v1.x;
        this->mAimEye.v0.y = v22;
        this->mAimEye.v0.z = v23;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
        *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
        this->mAimEye.mParameter.z = 0.0;
        this->mAimLook.p1.x = v17;
        this->mAimLook.p1.y = v18;
        this->mAimLook.p1.z = v19;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
        *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
        this->mAimLook.mParameter.z = 0.0;
        v24 = this->mAimLook.p1.y;
        v25 = this->mAimLook.p1.z;
        this->mAimLook.p0.x = this->mAimLook.p1.x;
        this->mAimLook.p0.y = v24;
        this->mAimLook.p0.z = v25;
        v26 = this->mAimLook.v1.y;
        v27 = this->mAimLook.v1.z;
        this->mAimLook.v0.x = this->mAimLook.v1.x;
        this->mAimLook.v0.y = v26;
        this->mAimLook.v0.z = v27;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
        *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
        this->mAimLook.mParameter.z = 0.0;
        LOBYTE(v28) = 1;
        ((void (__fastcall *)(UFG::FollowCameraComponent *, UFG::BaseCameraComponent *, __int64))this->vfptr[43].__vecDelDtor)(
          this,
          v6,
          v28);
      }
    }
  }
  else if ( UFG::gEventMountVehicleCamera.mUID == m_EventUID )
  {
    v29 = (UFG::SimObjectGame *)this->m_pSimObject;
    v30 = 0i64;
    if ( v29 )
    {
      v32 = v29->m_Flags;
      if ( (v32 & 0x4000) != 0 || v32 < 0 || (v32 & 0x2000) != 0 || (v32 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::ChaseCameraComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v29, UFG::ChaseCameraComponent::_TypeUID);
      v31 = ComponentOfType;
    }
    else
    {
      v31 = 0i64;
    }
    v34 = (UFG::SimObjectGame *)this->m_pSimObject;
    v37 = 0;
    if ( v34 )
    {
      v35 = v34->m_Flags;
      if ( (v35 & 0x4000) != 0 || v35 < 0 || (v35 & 0x2000) != 0 || (v35 & 0x1000) != 0 )
        v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v34, UFG::ScriptCameraComponent::_TypeUID);
      else
        v36 = UFG::SimObject::GetComponentOfType(v34, UFG::ScriptCameraComponent::_TypeUID);
      v30 = (UFG::BaseCameraComponent *)v36;
      if ( v36 )
      {
        if ( ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v36->vfptr[21].__vecDelDtor)(v36) )
          v37 = 1;
      }
    }
    m_pSimComponent = this->mTarget.m_pSimComponent;
    if ( m_pSimComponent->m_pSimObject == (UFG::SimObject *)e[1].mNext )
    {
      if ( v31 )
      {
        TargetingSystem = UFG::CharacterSubjectComponent::GetTargetingSystem((UFG::CharacterSubjectComponent *)m_pSimComponent);
        if ( TargetingSystem )
        {
          if ( (m_pTargetingMap = TargetingSystem->m_pTargetingMap,
                m_pTargets = TargetingSystem->m_pTargets,
                v42 = (unsigned __int8)m_pTargetingMap->m_Map.p[44],
                (m_pPointer = m_pTargets[v42].m_pTarget.m_pPointer) != 0i64)
            && m_pTargets[v42].m_bLock
            || (m_pPointer = m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[28]].m_pTarget.m_pPointer) != 0i64 )
          {
            if ( ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v31->vfptr[21].__vecDelDtor)(v31) )
            {
              if ( m_pPointer != (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))v31->vfptr[17].__vecDelDtor)(v31) )
                UFG::ChaseCameraComponent::TransitionTarget((UFG::ChaseCameraComponent *)v31, m_pPointer);
            }
            else
            {
              v44 = UFG::Director::Get();
              UFG::Director::SetCurrentCamera(v44, (UFG::BaseCameraComponent *)v31);
              UFG::GameCameraComponent::mNoRotationTimer = FLOAT_0_75;
              v31->vfptr[16].__vecDelDtor(v31, (unsigned int)m_pPointer);
              if ( gForceSnapOnEvent )
              {
                ((void (__fastcall *)(UFG::SimComponent *))v31->vfptr[15].__vecDelDtor)(v31);
                ((void (__fastcall *)(UFG::SimComponent *))v31->vfptr[31].__vecDelDtor)(v31);
                ((void (__fastcall *)(UFG::SimComponent *))v31->vfptr[15].__vecDelDtor)(v31);
                if ( BYTE4(v31[45].m_pSimObject) )
                {
                  *(_DWORD *)&v31[46].m_Flags = 1065353216;
                  BYTE4(v31[45].m_pSimObject) = 0;
                  BYTE1(v31[45].m_TypeUID) = 1;
                }
                if ( BYTE5(v31[45].m_pSimObject) )
                {
                  *(_DWORD *)(&v31[46].m_SimObjIndex + 1) = 1065353216;
                  BYTE5(v31[45].m_pSimObject) = 0;
                }
              }
              else if ( v37 )
              {
                UFG::ChaseCameraComponent::TransitionFromBlendOrientation((UFG::ChaseCameraComponent *)v31, v30);
              }
              else
              {
                UFG::ChaseCameraComponent::TransitionFromBlendOrientation((UFG::ChaseCameraComponent *)v31, this);
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 2111
// RVA: 0x3C3500
void __fastcall UFG::FollowCameraComponent::GetFovRadians(
        UFG::FollowCameraComponent *this,
        float *fov,
        float *fov_velocity)
{
  *fov_velocity = this->mFov.v0 * 0.017453292;
  *fov = this->mFov.p0 * 0.017453292;
}

// File Line: 2119
// RVA: 0x3CC9C0
void __fastcall UFG::FollowCameraComponent::SetFovRadians(
        UFG::FollowCameraComponent *this,
        float fov,
        float fov_velocity)
{
  UFG::HomerCubic<float> *p_mFov; // rbx

  p_mFov = &this->mFov;
  this->mFov.v0 = fov_velocity * 57.295776;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  p_mFov->mParameter = 0.0;
  p_mFov->p0 = fov * 57.295776;
  UFG::HomerCubic<float>::MakeCoeffs(p_mFov);
  p_mFov->mParameter = 0.0;
}

// File Line: 2127
// RVA: 0x3C3370
void __fastcall UFG::FollowCameraComponent::GetEyeWorld(
        UFG::FollowCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  y = this->mEye.p0.y;
  z = this->mEye.p0.z;
  position->x = this->mEye.p0.x;
  position->y = y;
  position->z = z;
  v5 = this->mEye.v0.y;
  v6 = this->mEye.v0.z;
  velocity->x = this->mEye.v0.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 2137
// RVA: 0x3C3840
void __fastcall UFG::FollowCameraComponent::GetLookWorld(
        UFG::FollowCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  y = this->mLook.p0.y;
  z = this->mLook.p0.z;
  position->x = this->mLook.p0.x;
  position->y = y;
  position->z = z;
  v5 = this->mLook.v0.y;
  v6 = this->mLook.v0.z;
  velocity->x = this->mLook.v0.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 2147
// RVA: 0x3CC7B0
void __fastcall UFG::FollowCameraComponent::SetEyeWorld(
        UFG::FollowCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rcx
  float z; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float x; // xmm7_4
  float y; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm2_4

  p_mEye = &this->mEye;
  z = p_mEye->mDuration.z;
  v5 = velocity->x - UFG::qVector3::msZero.x;
  v6 = velocity->y - UFG::qVector3::msZero.y;
  v7 = velocity->z - UFG::qVector3::msZero.z;
  x = position->x;
  y = position->y;
  v10 = position->z;
  v11 = p_mEye->mDuration.x;
  v12 = p_mEye->mDuration.y;
  if ( z <= 0.0099999998 )
    z = FLOAT_0_0099999998;
  if ( v12 <= 0.0099999998 )
    v12 = FLOAT_0_0099999998;
  if ( v11 <= 0.0099999998 )
    v11 = FLOAT_0_0099999998;
  p_mEye->mDuration.x = v11;
  p_mEye->mDuration.y = v12;
  p_mEye->mDuration.z = z;
  *(_QWORD *)&p_mEye->mParameter.x = 0i64;
  p_mEye->mParameter.z = 0.0;
  p_mEye->v0.x = v5;
  p_mEye->v0.y = v6;
  p_mEye->v0.z = v7;
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  p_mEye->v1.x = UFG::qVector3::msZero.x;
  p_mEye->v1.y = v13;
  p_mEye->v1.z = v14;
  p_mEye->p0.x = x;
  p_mEye->p0.y = y;
  p_mEye->p0.z = v10;
  p_mEye->p1.x = x;
  p_mEye->p1.y = y;
  p_mEye->p1.z = v10;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mEye);
}

// File Line: 2157
// RVA: 0x3CCE60
void __fastcall UFG::FollowCameraComponent::SetLookWorld(
        UFG::FollowCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  float x; // eax
  float z; // xmm1_4

  p_mLook = &this->mLook;
  v5 = velocity->y - UFG::qVector3::msZero.y;
  v6 = velocity->z - UFG::qVector3::msZero.z;
  this->mLook.v0.x = velocity->x - UFG::qVector3::msZero.x;
  this->mLook.v0.y = v5;
  this->mLook.v0.z = v6;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
  x = position->x;
  z = position->z;
  p_mLook->p0.y = position->y;
  p_mLook->p0.z = z;
  p_mLook->p0.x = x;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
}

// File Line: 2166
// RVA: 0x3C7660
void __fastcall UFG::FollowCameraComponent::NewTargetPosition(
        UFG::FollowCameraComponent *this,
        UFG::qVector3 *position,
        float angle)
{
  float mInitAngle; // xmm0_4
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  __int128 y_low; // xmm8
  float v10; // xmm3_4
  float x; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm9_4
  __int128 v14; // xmm10
  float v15; // xmm0_4
  float v16; // xmm8_4
  float z; // xmm2_4
  float v18; // xmm11_4
  __int128 v19; // xmm12
  float y; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  __m128 v23; // xmm3
  float v24; // xmm4_4
  __m128 v25; // xmm5
  float v26; // xmm1_4

  if ( this->mBlendedParams.mUseInitAngle )
    mInitAngle = this->mBlendedParams.mInitAngle;
  else
    mInitAngle = 0.0;
  v6 = angle - (float)((float)(mInitAngle * 3.1415927) * 0.0055555557);
  v7 = sinf(v6);
  v8 = cosf(v6);
  y_low = LODWORD(this->mBlendedParams.mTweakCamThru.y);
  v10 = v8;
  x = this->mBlendedParams.mTweakCamThru.x;
  v12 = (float)(x * 0.0) + position->z;
  v14 = y_low;
  v13 = (float)(COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]) * *(float *)&y_low) + (float)((float)(x * v10) + position->x);
  *(float *)&v14 = (float)(*(float *)&y_low * v10) + (float)((float)(x * v7) + position->y);
  v15 = this->mBlendedParams.mTweakRadiusMin + 0.0099999998;
  v19 = v14;
  v16 = (float)((float)(*(float *)&y_low * 0.0) + v12) + this->mBlendedParams.mTweakCamThru.z;
  z = UFG::qVector3::msZero.z;
  v18 = v13 - (float)(v15 * v10);
  *(float *)&v19 = *(float *)&v14 - (float)(v15 * v7);
  y = UFG::qVector3::msZero.y;
  v21 = (float)(v16 - (float)(v15 * 0.0)) + this->mBlendedParams.mInitRise;
  this->mVelocity.p1.x = UFG::qVector3::msZero.x;
  this->mVelocity.p1.y = y;
  this->mVelocity.p1.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mVelocity);
  v23 = (__m128)v19;
  *(_QWORD *)&this->mVelocity.mParameter.x = 0i64;
  v22 = v18 - v13;
  v23.m128_f32[0] = *(float *)&v19 - *(float *)&v14;
  v24 = v21 - v16;
  this->mVelocity.mParameter.z = 0.0;
  v25 = v23;
  v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22)) + (float)(v24 * v24);
  if ( v25.m128_f32[0] == 0.0 )
    v26 = 0.0;
  else
    v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
  this->mControllerForward.x = v22 * v26;
  this->mControllerForward.y = v23.m128_f32[0] * v26;
  this->mControllerForward.z = v24 * v26;
  this->mLook.p1.x = v13;
  LODWORD(this->mLook.p1.y) = v14;
  this->mLook.p1.z = v16;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  this->mEye.p1.x = v18;
  LODWORD(this->mEye.p1.y) = v19;
  this->mEye.p1.z = v21;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  UFG::FollowCameraComponent::Rotate(this, 0.0, 0.0);
}

// File Line: 2189
// RVA: 0x3C8890
void __fastcall UFG::FollowCameraComponent::Reset(UFG::FollowCameraComponent *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::AimingPlayerComponent *ComponentOfTypeHK; // rbx
  UFG::qVector3 *v8; // rax

  this->mEnableCharacterSpaceSmoothing = 0;
  UFG::FollowCameraComponent::ResetFromTarget(this, 1);
  this->mAllowCanOccludeCamera = 1;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mCollisionLookOffset.x = UFG::qVector3::msZero.x;
  this->mCollisionLookOffset.y = y;
  this->mCollisionLookOffset.z = z;
  UFG::BaseCameraComponent::Reset(this);
  m_pSimComponent = this->mTarget.m_pSimComponent;
  this->mMouseBoomSet = 0;
  if ( m_pSimComponent && (m_pSimObject = (UFG::SimObjectCharacter *)m_pSimComponent->m_pSimObject) != 0i64 )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(m_pSimObject);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pSimObject,
                                                          UFG::AimingPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::AimingPlayerComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  if ( ComponentOfTypeHK )
  {
    v8 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)(this->mTarget.m_pSimComponent);
    UFG::AimingPlayerComponent::SetFreeAimIntention(ComponentOfTypeHK, v8);
    ((void (__fastcall *)(UFG::UpdateInterface *))ComponentOfTypeHK->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr->Update)(&ComponentOfTypeHK->UFG::UpdateInterface);
    this->mSnapNext = 1;
  }
}

// File Line: 2208
// RVA: 0x3C8E00
void __fastcall UFG::FollowCameraComponent::ResetFromTarget(UFG::FollowCameraComponent *this, bool snap)
{
  float v2; // xmm0_4
  float z; // xmm9_4
  float x; // xmm7_4
  float y; // xmm8_4
  UFG::CharacterSubjectComponent *m_pSimComponent; // rcx
  __int64 v9; // rax
  UFG::SimComponent *v10; // rbx
  float v11; // xmm6_4
  __int64 v12; // rax
  UFG::RegionComponent *v13; // rcx
  UFG::qVector3 pos; // [rsp+20h] [rbp-58h] BYREF

  this->mAimDurationSupplimentary = 0.0;
  v2 = 0.0;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  y = UFG::qVector3::msZero.y;
  this->mEnableCharacterSpaceSmoothing = 0;
  this->mMouseBoomSet = 0;
  m_pSimComponent = (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent;
  pos.x = x;
  pos.y = y;
  pos.z = z;
  if ( m_pSimComponent )
  {
    UFG::CharacterSubjectComponent::Update(m_pSimComponent, 0.0);
    v9 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)(this->mTarget.m_pSimComponent);
    x = *(float *)v9;
    y = *(float *)(v9 + 4);
    z = *(float *)(v9 + 8);
    UFG::CharacterSubjectComponent::GetTransformTypePosition(
      (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
      &pos,
      this->mBlendedParams.mSrcPosition,
      1);
    v10 = this->mTarget.m_pSimComponent;
    v11 = *(float *)((__int64 (__fastcall *)(UFG::SimComponent *))v10->vfptr[16].__vecDelDtor)(v10);
    v12 = ((__int64 (__fastcall *)(UFG::SimComponent *))v10->vfptr[16].__vecDelDtor)(v10);
    v2 = atan2f(*(float *)(v12 + 4), v11);
  }
  UFG::FollowCameraComponent::NewTargetPosition(this, &pos, v2);
  this->mVelocity.p1.x = x;
  this->mVelocity.p1.y = y;
  this->mVelocity.p1.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mVelocity);
  *(_QWORD *)&this->mVelocity.mParameter.x = 0i64;
  this->mVelocity.mParameter.z = 0.0;
  if ( snap )
  {
    UFG::BaseCameraComponent::Reset(this);
    UFG::FollowCameraComponent::Snap(this);
  }
  v13 = (UFG::RegionComponent *)this->mTarget.m_pSimComponent;
  this->bResetFromTarget = !v13 || !UFG::RegionComponent::GetXformNode(v13);
}

// File Line: 2241
// RVA: 0x3CD570
void __fastcall UFG::FollowCameraComponent::SetTarget(
        UFG::FollowCameraComponent *this,
        UFG::SimObjectCharacter *target)
{
  UFG::CharacterSubjectComponent *ComponentOfType; // rax
  signed __int16 m_Flags; // cx
  unsigned int v6; // edx
  UFG::SimObjectGame *v7; // rcx
  bool v8; // zf

  if ( target )
  {
    m_Flags = target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(target);
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
      {
        v6 = UFG::CharacterSubjectComponent::_TypeUID;
        v7 = target;
      }
      else
      {
        v6 = UFG::CharacterSubjectComponent::_TypeUID;
        v8 = (m_Flags & 0x1000) == 0;
        v7 = target;
        if ( v8 )
        {
          ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                target,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
          goto LABEL_11;
        }
      }
      ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, v6);
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
LABEL_11:
  UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>::Set(&this->mTarget, ComponentOfType);
  UFG::FollowCameraComponent::ResetFromTarget(this, 1);
}

// File Line: 2248
// RVA: 0x3CCF80
void __fastcall UFG::FollowCameraComponent::SetOverrideMaxRadius(UFG::FollowCameraComponent *this, float maxRadius)
{
  float mTweakRadiusMax; // xmm0_4

  if ( maxRadius <= 0.0 )
    maxRadius = 0.0;
  mTweakRadiusMax = this->mBlendedParams.mTweakRadiusMax;
  this->mMaxRadiusOverrideEnabled = 1;
  if ( maxRadius >= mTweakRadiusMax )
    this->mMaxRadiusOverride = mTweakRadiusMax;
  else
    this->mMaxRadiusOverride = maxRadius;
}

// File Line: 2256
// RVA: 0x3CCFC0
void __fastcall UFG::FollowCameraComponent::SetOverrideRise(UFG::FollowCameraComponent *this, float rise)
{
  float mTweakEyeRise; // xmm0_4

  mTweakEyeRise = this->mBlendedParams.mTweakEyeRise;
  this->mRiseOverrideEnabled = 1;
  if ( rise <= mTweakEyeRise )
    this->mRiseOverride = rise;
  else
    this->mRiseOverride = mTweakEyeRise;
}

// File Line: 2266
// RVA: 0x3D3660
void __fastcall UFG::FollowCameraComponent::Update(UFG::FollowCameraComponent *this, float delta_sec)
{
  float v2; // xmm14_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float mTransitionParamOrient; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float mTransitionParamSuppEye; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float mTransitionParamSuppLook; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  bool v15; // zf
  int mResetNext; // eax
  __int64 v17; // rax
  float v18; // xmm0_4
  float v19; // xmm1_4
  int v20; // esi
  double v21; // xmm6_8
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  __int64 v25; // rax
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  float p1; // xmm0_4
  char v29; // cl
  bool v30; // cf
  float mHorizCompDurationAttack; // xmm0_4
  float mHorizCompDurationDecay; // xmm1_4
  UFG::HomerCubic<float> *p_mHorizCompOffset; // rcx
  float *v34; // rax
  float mParameter; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float mPassThroughTimer1; // xmm0_4
  float v39; // xmm0_4
  float mPassThroughTimer2; // xmm0_4
  float v41; // xmm0_4
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *m_pPointer; // rax
  bool v46; // cl
  float mRecoilAngleDesired; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm6_4
  __int64 v50; // rdx
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm1_4
  float v56; // eax
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // eax
  float v60; // xmm1_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm3_4
  __m128 y_low; // xmm4
  float v69; // xmm1_4
  float v70; // xmm5_4
  float v71; // xmm8_4
  float v72; // xmm9_4
  float v73; // xmm15_4
  float v74; // xmm6_4
  float v75; // xmm7_4
  __m128 v76; // xmm2
  float v77; // xmm1_4
  float mRecoilAngle; // xmm2_4
  float v79; // xmm15_4
  float v80; // xmm6_4
  float v81; // xmm7_4
  float mTransitionParamDutch; // xmm4_4
  __m128 v83; // xmm9
  float v84; // xmm3_4
  float v85; // xmm4_4
  float v86; // xmm15_4
  float v87; // xmm3_4
  __m128 v88; // xmm2
  float v89; // xmm1_4
  float v90; // xmm7_4
  float v91; // xmm8_4
  float v92; // xmm6_4
  float v93; // xmm2_4
  float v94; // xmm4_4
  float v95; // xmm3_4
  float v96; // xmm8_4
  float v97; // xmm7_4
  float v98; // xmm15_4
  float v99; // xmm8_4
  float v100; // xmm1_4
  float v101; // xmm0_4
  __m128 v102; // xmm2
  float v103; // xmm4_4
  float v104; // xmm15_4
  float v105; // xmm4_4
  __m128 v106; // xmm3
  float v107; // xmm3_4
  float v108; // xmm11_4
  float v109; // xmm7_4
  float v110; // xmm8_4
  float v111; // xmm3_4
  float v112; // xmm15_4
  float v113; // xmm7_4
  float v114; // xmm8_4
  __m128 v115; // xmm10
  __m128 v116; // xmm2
  float v117; // xmm1_4
  float v118; // xmm6_4
  float v119; // xmm1_4
  float v120; // xmm6_4
  float v121; // xmm5_4
  float v122; // xmm6_4
  __m128 v123; // xmm4
  float v124; // xmm0_4
  __m128 v125; // xmm4
  __m128 v126; // xmm1
  float v127; // xmm6_4
  float v128; // xmm5_4
  __m128 v129; // xmm9
  __m128 v130; // xmm2
  float v131; // xmm3_4
  __m128 v132; // xmm2
  float v133; // xmm4_4
  __m128 v134; // xmm5
  float v135; // xmm6_4
  float v136; // xmm6_4
  unsigned int v137; // xmm1_4
  __m128 v138; // xmm2
  float v139; // xmm3_4
  float v140; // xmm7_4
  float v141; // xmm8_4
  float v142; // xmm3_4
  float v143; // xmm7_4
  float v144; // xmm8_4
  __m128 v145; // xmm2
  float v146; // xmm1_4
  float v147; // xmm5_4
  float v148; // xmm1_4
  float v149; // xmm5_4
  float v150; // xmm6_4
  float v151; // xmm5_4
  __m128 v152; // xmm4
  float v153; // xmm0_4
  __m128 v154; // xmm4
  __m128 v155; // xmm1
  float v156; // xmm5_4
  float v157; // xmm6_4
  __m128 v158; // xmm9
  __m128 v159; // xmm2
  float v160; // xmm3_4
  float v161; // xmm2_4
  float v162; // xmm1_4
  float v163; // xmm0_4
  float v164; // xmm3_4
  float v165; // xmm6_4
  float v166; // xmm1_4
  bool v167; // al
  float mDesaturation; // xmm0_4
  float mMotionblurMagnitude; // eax
  UFG::SimObjectCharacter *v170; // rcx
  __int16 v171; // dx
  UFG::AimingPlayerComponent *ComponentOfType; // rbx
  UFG::SimObjectCVBase *v173; // rcx
  __int16 v174; // dx
  UFG::TargetingSystemPedPlayerComponent *v175; // rdx
  bool v176; // r8
  UFG::SimObject *v177; // rdx
  UFG::SimObject *v178; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  float v180; // xmm0_4
  float v181; // xmm0_4
  float mTweakNoiseFrequency; // xmm1_4
  float v183; // xmm7_4
  float v184; // xmm6_4
  float v185; // xmm1_4
  UFG::qVector3 *Value; // rax
  float v187; // xmm1_4
  float v188; // xmm0_4
  UFG::qVector3 *v189; // rax
  float v190; // xmm1_4
  float v191; // xmm0_4
  UFG::SimComponent *m_pSimComponent; // rcx
  float v193; // xmm7_4
  float v194; // xmm9_4
  float v195; // xmm8_4
  float *v196; // rax
  float v197; // xmm3_4
  float v198; // xmm2_4
  UFG::SimComponent *v199; // rbx
  __int64 v200; // rax
  float v201; // xmm0_4
  float v202; // xmm1_4
  float v203; // xmm0_4
  float v204; // xmm1_4
  float v205; // xmm2_4
  float v206; // xmm0_4
  UFG::SimObjectCharacter *v207; // rcx
  UFG::AimingPlayerComponent *v208; // rax
  __int16 v209; // dx
  float v210; // xmm1_4
  float v211; // xmm0_4
  float v212; // xmm2_4
  float *v213; // rax
  float v214; // xmm4_4
  float v215; // xmm3_4
  float v216; // xmm5_4
  float v217; // xmm4_4
  float v218; // xmm3_4
  float v219; // xmm5_4
  float v220; // xmm6_4
  float v221; // xmm4_4
  float v222; // xmm5_4
  float v223; // xmm1_4
  float v224; // xmm3_4
  float v225; // xmm7_4
  __m128 v226; // xmm2
  float v227; // xmm8_4
  __m128 v228; // xmm6
  float v229; // xmm1_4
  float v230; // xmm5_4
  float v231; // xmm4_4
  unsigned int v232; // xmm0_4
  __m128 v233; // xmm2
  float v234; // xmm3_4
  float v235; // xmm7_4
  float v236; // xmm8_4
  float v237; // xmm3_4
  float v238; // xmm7_4
  float v239; // xmm8_4
  __m128 v240; // xmm2
  float v241; // xmm1_4
  float v242; // xmm6_4
  float v243; // xmm1_4
  float v244; // xmm6_4
  float v245; // xmm5_4
  float v246; // xmm6_4
  __m128 v247; // xmm4
  float v248; // xmm0_4
  __m128 v249; // xmm4
  __m128 v250; // xmm1
  float v251; // xmm6_4
  float v252; // xmm5_4
  __m128 v253; // xmm9
  __m128 v254; // xmm2
  float v255; // xmm3_4
  float mTransitionParamEye; // xmm5_4
  float v257; // xmm4_4
  float v258; // xmm2_4
  float v259; // xmm1_4
  float v260; // xmm3_4
  float v261; // xmm0_4
  float v262; // xmm5_4
  float v263; // xmm0_4
  float v264; // xmm6_4
  UFG::qMatrix44 *Matrix; // rax
  __m128 v266; // xmm4
  UFG::qVector4 v267; // xmm5
  UFG::qVector4 v268; // xmm3
  UFG::qVector4 v269; // xmm1
  float ExtraWideAspectCorrectedFOV; // xmm7_4
  float v271; // xmm6_4
  float DisplayAspectRatio; // xmm0_4
  float v273; // xmm0_4
  float v274; // xmm8_4
  float *p_z; // rbx
  float *v276; // rax
  float v277; // xmm3_4
  __m128 v278; // xmm6
  float v279; // xmm7_4
  __m128 v280; // xmm2
  float v281; // xmm5_4
  double v282; // xmm0_8
  float v283; // xmm6_4
  double v284; // xmm0_8
  float v285; // xmm7_4
  float v286; // xmm7_4
  __int64 v287; // rax
  __m128 v288; // xmm2
  float v289; // xmm1_4
  float v290; // xmm1_4
  float v291; // xmm2_4
  float mAutoFrameFarthestAttackerDist; // xmm1_4
  float mTweakEyeRise; // xmm4_4
  float v294; // xmm1_4
  __m128 v295; // xmm2
  float v296; // xmm0_4
  float v297; // xmm7_4
  float v298; // xmm8_4
  float v299; // xmm9_4
  __int64 v300; // rax
  __m128 v301; // xmm5
  float v302; // xmm13_4
  __m128 v303; // xmm1
  float v304; // xmm10_4
  float v305; // xmm0_4
  float mDofFarFocalDist; // xmm4_4
  float v307; // xmm6_4
  float v308; // xmm0_4
  __m128 v309; // xmm3
  __m128 v310; // xmm2
  __m128 v311; // xmm1
  float v312; // xmm0_4
  __int64 mNumMeleeAttackers; // rcx
  float *v314; // rax
  __m128 v315; // xmm3
  __m128 v316; // xmm2
  __m128 v317; // xmm1
  float v318; // xmm0_4
  float v319; // xmm0_4
  UFG::qVector3 desEye; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 desLook; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 duration; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qVector3 look; // [rsp+70h] [rbp-90h] BYREF
  float v324; // [rsp+80h] [rbp-80h]
  __int64 v325; // [rsp+84h] [rbp-7Ch]
  float v326; // [rsp+8Ch] [rbp-74h]
  float v327; // [rsp+90h] [rbp-70h]
  UFG::qVector3 v328; // [rsp+98h] [rbp-68h] BYREF
  UFG::qVector3 axis; // [rsp+A8h] [rbp-58h] BYREF
  UFG::qMatrix44 m; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qVector3 v331; // [rsp+100h] [rbp+0h] BYREF
  UFG::qVector3 t; // [rsp+110h] [rbp+10h] BYREF
  UFG::qMatrix44 v333; // [rsp+120h] [rbp+20h] BYREF
  UFG::qMatrix44 mat; // [rsp+160h] [rbp+60h] BYREF
  UFG::qMatrix44 v335; // [rsp+1A0h] [rbp+A0h] BYREF
  UFG::qMatrix44 dest; // [rsp+1E0h] [rbp+E0h] BYREF
  UFG::qVector3 eye; // [rsp+220h] [rbp+120h] BYREF
  UFG::qQuaternion v338; // [rsp+230h] [rbp+130h] BYREF
  UFG::qQuaternion b; // [rsp+240h] [rbp+140h] BYREF
  UFG::qQuaternion result; // [rsp+250h] [rbp+150h] BYREF
  UFG::qQuaternion a; // [rsp+260h] [rbp+160h] BYREF
  UFG::qQuaternion v342; // [rsp+270h] [rbp+170h] BYREF
  UFG::qMatrix44 v343; // [rsp+280h] [rbp+180h] BYREF
  float v344; // [rsp+3B0h] [rbp+2B0h] BYREF
  float v345; // [rsp+3B8h] [rbp+2B8h] BYREF

  v2 = delta_sec;
  if ( UFG::Metrics::msInstance.mSimTimeDelta > 0.0 )
  {
    UFG::FollowCameraComponent::SafetyDetectInconsistentCameraMode(this, UFG::Metrics::msInstance.mSimTimeDelta);
    if ( (!UFG::gFlowController.mCurrentState
       || !UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED))
      && this->mActive )
    {
      v4 = this->mTransitionParamEye - (float)(delta_sec * this->mTransitionParamRateEye);
      v5 = v4;
      this->mTransitionParamEye = v4;
      if ( v4 <= 0.0 )
      {
        v5 = 0.0;
      }
      else if ( v4 >= 1.0 )
      {
        v5 = *(float *)&FLOAT_1_0;
      }
      mTransitionParamOrient = this->mTransitionParamOrient;
      this->mTransitionParamEye = v5;
      v7 = mTransitionParamOrient - (float)(v2 * this->mTransitionParamRateOrient);
      v8 = v7;
      this->mTransitionParamOrient = v7;
      if ( v7 <= 0.0 )
      {
        v8 = 0.0;
      }
      else if ( v7 >= 1.0 )
      {
        v8 = *(float *)&FLOAT_1_0;
      }
      mTransitionParamSuppEye = this->mTransitionParamSuppEye;
      this->mTransitionParamOrient = v8;
      v10 = mTransitionParamSuppEye - (float)(v2 * this->mTransitionParamRateSuppEye);
      v11 = v10;
      this->mTransitionParamSuppEye = v10;
      if ( v10 <= 0.0 )
      {
        v11 = 0.0;
      }
      else if ( v10 >= 1.0 )
      {
        v11 = *(float *)&FLOAT_1_0;
      }
      mTransitionParamSuppLook = this->mTransitionParamSuppLook;
      this->mTransitionParamSuppEye = v11;
      v13 = mTransitionParamSuppLook - (float)(v2 * this->mTransitionParamRateSuppLook);
      v14 = v13;
      this->mTransitionParamSuppLook = v13;
      if ( v13 <= 0.0 )
      {
        v14 = 0.0;
      }
      else if ( v13 >= 1.0 )
      {
        v14 = *(float *)&FLOAT_1_0;
      }
      v15 = this->mTarget.m_pSimComponent == 0i64;
      this->mTransitionParamSuppLook = v14;
      if ( !v15 )
        goto LABEL_281;
      if ( LocalPlayer )
        ((void (__fastcall *)(UFG::FollowCameraComponent *))this->vfptr[16].__vecDelDtor)(this);
      if ( this->mTarget.m_pSimComponent )
      {
LABEL_281:
        if ( this->bResetFromTarget )
          UFG::FollowCameraComponent::ResetFromTarget(this, 1);
        if ( v2 > 0.050000001 )
          v2 = FLOAT_0_050000001;
        if ( !this->bUpdateFromAimComp )
        {
          if ( !this->mResetNext )
            ((void (__fastcall *)(UFG::FollowCameraComponent *))this->vfptr[14].__vecDelDtor)(this);
          mResetNext = this->mResetNext;
          if ( mResetNext >= 0 )
            this->mResetNext = mResetNext - 1;
        }
        UFG::GameCameraComponent::Update(this, v2);
        UFG::FollowCameraComponent::UpdateBlendedParams(this, v2);
        UFG::FollowCameraComponent::UpdateTweaker(this, v2);
        v17 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)(this->mTarget.m_pSimComponent);
        v18 = *(float *)(v17 + 4);
        v19 = *(float *)(v17 + 8);
        this->mVelocity.p1.x = *(float *)v17;
        this->mVelocity.p1.y = v18;
        this->mVelocity.p1.z = v19;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mVelocity);
        v20 = 0;
        *(_QWORD *)&this->mVelocity.mParameter.x = 0i64;
        this->mVelocity.mParameter.z = 0.0;
        UFG::HomerCubic<UFG::qVector3>::Update(&this->mVelocity, v2);
        if ( UFG::FollowCameraComponent::bHorizCompUseTweakables )
          *(_QWORD *)&v21 = LODWORD(UFG::FollowCameraComponent::rHorizCompSpeedWindowTimespan);
        else
          *(_QWORD *)&v21 = LODWORD(this->mBlendedParams.mHorizCompSpeedWindowTimespan);
        if ( *(float *)&v21 != this->mHorizCompTargetSpeedSubmittedTimespan )
        {
          UFG::qAverageWindow<float>::SetTimespan(&this->mHorizCompTargetSpeedWindow, v21, 30.0);
          this->mHorizCompTargetSpeedSubmittedTimespan = *(float *)&v21;
        }
        if ( v2 > 0.0 )
        {
          x = this->mCamera.mTransformation.v0.x;
          y = this->mCamera.mTransformation.v0.y;
          z = this->mCamera.mTransformation.v0.z;
          v25 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)(this->mTarget.m_pSimComponent);
          v26 = (__m128)*(unsigned int *)(v25 + 4);
          v26.m128_f32[0] = (float)((float)((float)(v26.m128_f32[0] * y) + (float)(*(float *)v25 * x))
                                  + (float)(*(float *)(v25 + 8) * z))
                          / (float)((float)((float)(y * y) + (float)(x * x)) + (float)(z * z));
          v27 = v26;
          v27.m128_f32[0] = (float)((float)((float)(v27.m128_f32[0] * y) * (float)(v27.m128_f32[0] * y))
                                  + (float)((float)(v26.m128_f32[0] * x) * (float)(v26.m128_f32[0] * x)))
                          + (float)((float)(v26.m128_f32[0] * z) * (float)(v26.m128_f32[0] * z));
          UFG::qAverageWindow<float>::AddValue(&this->mHorizCompTargetSpeedWindow, _mm_sqrt_ps(v27).m128_f32[0], v2);
        }
        p1 = this->mHorizCompOffset.p1;
        v29 = 0;
        v30 = p1 < 0.0;
        if ( p1 > 0.0 )
        {
          if ( p1 > this->mHorizCompOffset.p0 )
          {
LABEL_46:
            v29 = 1;
LABEL_47:
            if ( UFG::FollowCameraComponent::bHorizCompUseTweakables )
            {
              mHorizCompDurationAttack = UFG::FollowCameraComponent::rHorizCompDurationAttack;
              mHorizCompDurationDecay = UFG::FollowCameraComponent::rHorizCompDurationDecay;
            }
            else
            {
              mHorizCompDurationAttack = this->mBlendedParams.mHorizCompDurationAttack;
              mHorizCompDurationDecay = this->mBlendedParams.mHorizCompDurationDecay;
            }
            v15 = v29 == 0;
            p_mHorizCompOffset = &this->mHorizCompOffset;
            v344 = mHorizCompDurationAttack;
            v34 = &v344;
            mParameter = this->mHorizCompOffset.mParameter;
            v345 = mHorizCompDurationDecay;
            if ( v15 )
              v34 = &v345;
            v36 = mParameter / p_mHorizCompOffset->mDuration;
            v37 = *v34;
            this->mHorizCompOffset.mParameter = v36;
            if ( v37 <= 0.0099999998 )
              v37 = FLOAT_0_0099999998;
            p_mHorizCompOffset->mDuration = v37;
            this->mHorizCompOffset.mParameter = v37 * v36;
            UFG::HomerCubic<float>::MakeCoeffs(p_mHorizCompOffset);
            UFG::FollowCameraComponent::UpdateLocalWorld(this, v2);
            mPassThroughTimer1 = this->mPassThroughTimer1;
            if ( mPassThroughTimer1 > 0.0 )
            {
              v39 = mPassThroughTimer1 - v2;
              this->mPassThroughTimer1 = v39;
              if ( v39 <= 0.0 )
                this->pSimObjectPassThru1 = 0i64;
            }
            mPassThroughTimer2 = this->mPassThroughTimer2;
            if ( mPassThroughTimer2 > 0.0 )
            {
              v41 = mPassThroughTimer2 - v2;
              this->mPassThroughTimer2 = v41;
              if ( v41 <= 0.0 )
                this->pSimObjectPassThru2 = 0i64;
            }
            UFG::FollowCameraComponent::UpdateControllers(this, v2);
            if ( this->mSnapNext )
            {
              this->mSnapNext = 0;
              UFG::FollowCameraComponent::Snap(this);
            }
            duration.x = UFG::FollowCameraComponent::rOffsetLookDuration;
            duration.y = UFG::FollowCameraComponent::rOffsetLookDuration;
            duration.z = UFG::FollowCameraComponent::rOffsetLookDuration;
            UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mOffsetLook, &duration);
            duration.x = UFG::FollowCameraComponent::rOffsetEyeDuration;
            duration.y = UFG::FollowCameraComponent::rOffsetEyeDuration;
            duration.z = UFG::FollowCameraComponent::rOffsetEyeDuration;
            UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mOffsetEye, &duration);
            if ( this->mTarget.m_pSimComponent
              && (m_pSimObject = (UFG::SimObjectCVBase *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
            {
              m_Flags = m_pSimObject->m_Flags;
              if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
              {
                ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(m_pSimObject);
              }
              else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              {
                ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                m_pSimObject,
                                                                                UFG::TargetingSystemPedPlayerComponent::_TypeUID);
              }
              else
              {
                ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                                m_pSimObject,
                                                                                UFG::TargetingSystemPedPlayerComponent::_TypeUID);
              }
            }
            else
            {
              ComponentOfTypeHK = 0i64;
            }
            if ( ComponentOfTypeHK )
              m_pPointer = ComponentOfTypeHK->m_pEquippedSOWPC.m_pPointer;
            else
              m_pPointer = 0i64;
            v46 = UFG::tbRecoilUseTweakables || !m_pPointer;
            mRecoilAngleDesired = this->mRecoilAngleDesired;
            if ( v46 )
            {
              if ( mRecoilAngleDesired <= 0.0 )
                v48 = UFG::trRecoilKickupRateDecay;
              else
                v48 = UFG::trRecoilKickupRateAttack;
              v49 = UFG::trRecoilKickbackDur;
            }
            else
            {
              v50 = *((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                    + HIDWORD(m_pPointer[2].m_pSimObject));
              v48 = *(float *)(v50 + 428);
              v49 = *(float *)(v50 + 444);
            }
            if ( UFG::qApproach(&this->mRecoilAngle, mRecoilAngleDesired, (float)(v48 * 3.1415927) * 0.0055555557, v2) )
            {
              if ( this->mRecoilAngleDesired > 0.0 )
                this->mRecoilAngleDesired = 0.0;
              if ( this->mRecoilAngleDesired == 0.0 && this->mRecoilAngle > 0.0 )
                UFG::GameCameraComponent::ResetAimWobble(this);
            }
            duration.x = v49;
            duration.y = v49;
            duration.z = v49;
            UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mRecoilEye, &duration);
            UFG::HomerCubic<UFG::qVector3>::Update(&this->mLook, v2);
            UFG::HomerCubic<UFG::qVector3>::Update(&this->mEye, v2);
            UFG::HomerCubic<float>::Update(&this->mFov, v2);
            UFG::HomerCubic<UFG::qVector3>::Update(&this->mOffsetLook, v2);
            UFG::HomerCubic<UFG::qVector3>::Update(&this->mOffsetEye, v2);
            UFG::HomerCubic<UFG::qVector3>::Update(&this->mRecoilEye, v2);
            UFG::HomerCubic<float>::Update(&this->mHorizCompOffset, v2);
            UFG::HomerCubic<UFG::qVector3>::Update(&this->mAimEye, v2);
            UFG::HomerCubic<UFG::qVector3>::Update(&this->mAimLook, v2);
            if ( this->rAimParameter > 0.0 && !this->bAimUseEyeLook )
            {
              v51 = this->mOffsetLook.p1.y;
              v52 = this->mOffsetLook.p1.z;
              this->mOffsetLook.p0.x = this->mOffsetLook.p1.x;
              this->mOffsetLook.p0.y = v51;
              this->mOffsetLook.p0.z = v52;
              v53 = this->mOffsetLook.v1.y;
              v54 = this->mOffsetLook.v1.z;
              this->mOffsetLook.v0.x = this->mOffsetLook.v1.x;
              this->mOffsetLook.v0.y = v53;
              this->mOffsetLook.v0.z = v54;
              UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetLook);
              *(_QWORD *)&this->mOffsetLook.mParameter.x = 0i64;
              this->mOffsetLook.mParameter.z = 0.0;
              v55 = this->mOffsetEye.p1.z;
              v56 = this->mOffsetEye.p1.x;
              this->mOffsetEye.p0.y = this->mOffsetEye.p1.y;
              this->mOffsetEye.p0.z = v55;
              this->mOffsetEye.p0.x = v56;
              v57 = this->mOffsetEye.v1.y;
              v58 = this->mOffsetEye.v1.z;
              this->mOffsetEye.v0.x = this->mOffsetEye.v1.x;
              this->mOffsetEye.v0.y = v57;
              this->mOffsetEye.v0.z = v58;
              UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetEye);
              *(_QWORD *)&this->mOffsetEye.mParameter.x = 0i64;
              this->mOffsetEye.mParameter.z = 0.0;
              v59 = this->mLook.p1.x;
              v60 = this->mLook.p1.z;
              this->mLook.p0.y = this->mLook.p1.y;
              this->mLook.p0.z = v60;
              this->mLook.p0.x = v59;
              v61 = this->mLook.v1.y;
              v62 = this->mLook.v1.z;
              this->mLook.v0.x = this->mLook.v1.x;
              this->mLook.v0.y = v61;
              this->mLook.v0.z = v62;
              UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
              *(_QWORD *)&this->mLook.mParameter.x = 0i64;
              this->mLook.mParameter.z = 0.0;
              v63 = this->mEye.p1.y;
              v64 = this->mEye.p1.z;
              this->mEye.p0.x = this->mEye.p1.x;
              this->mEye.p0.y = v63;
              this->mEye.p0.z = v64;
              v65 = this->mEye.v1.y;
              v66 = this->mEye.v1.z;
              this->mEye.v0.x = this->mEye.v1.x;
              this->mEye.v0.y = v65;
              this->mEye.v0.z = v66;
              UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
              *(_QWORD *)&this->mEye.mParameter.x = 0i64;
              this->mEye.mParameter.z = 0.0;
            }
            y_low = (__m128)LODWORD(this->mLook.p1.y);
            v67 = this->mLook.p1.x - this->mEye.p1.x;
            y_low.m128_f32[0] = y_low.m128_f32[0] - this->mEye.p1.y;
            v76 = y_low;
            v69 = (float)(this->mLook.p1.z - this->mEye.p1.z) * (float)(this->mLook.p1.z - this->mEye.p1.z);
            v70 = this->mEye.p0.x + this->mRecoilEye.p0.x;
            v71 = this->mEye.p0.y + this->mRecoilEye.p0.y;
            v72 = this->mEye.p0.z + this->mRecoilEye.p0.z;
            v73 = this->mLook.p0.x;
            v74 = this->mLook.p0.y;
            v75 = this->mLook.p0.z;
            desEye.x = v70;
            desEye.y = v71;
            v76.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v67 * v67)) + v69;
            desEye.z = v72;
            desLook.x = v73;
            desLook.y = v74;
            desLook.z = v75;
            if ( v76.m128_f32[0] == 0.0 )
              v77 = 0.0;
            else
              v77 = 1.0 / _mm_sqrt_ps(v76).m128_f32[0];
            mRecoilAngle = this->mRecoilAngle;
            axis.z = 0.0;
            v79 = v73 - v70;
            v80 = v74 - v71;
            v81 = v75 - v72;
            *((float *)&v325 + 1) = v67 * v77;
            *(float *)&v325 = y_low.m128_f32[0] * v77;
            axis.x = y_low.m128_f32[0] * v77;
            LODWORD(axis.y) = COERCE_UNSIGNED_INT(v67 * v77) ^ _xmm[0];
            UFG::qRotationMatrixAxis(&dest, &axis, COERCE_FLOAT(LODWORD(mRecoilAngle) ^ _xmm[0]));
            mTransitionParamDutch = this->mTransitionParamDutch;
            v83 = (__m128)LODWORD(mTransitionParamDutch);
            v83.m128_f32[0] = (float)(mTransitionParamDutch * this->mUpFrom.y) + UFG::qVector3::msDirUp.y;
            v88 = v83;
            v324 = desEye.x
                 + (float)((float)((float)((float)(v79 * dest.v0.x) + (float)(v80 * dest.v1.x))
                                 + (float)(v81 * dest.v2.x))
                         + dest.v3.x);
            v345 = (float)((float)((float)((float)(v79 * dest.v0.y) + (float)(v80 * dest.v1.y))
                                 + (float)(v81 * dest.v2.y))
                         + dest.v3.y)
                 + desEye.y;
            v84 = mTransitionParamDutch;
            v85 = (float)(mTransitionParamDutch * this->mUpFrom.z) + UFG::qVector3::msDirUp.z;
            v86 = (float)((float)((float)((float)(v79 * dest.v0.z) + (float)(v80 * dest.v1.z)) + (float)(v81 * dest.v2.z))
                        + dest.v3.z)
                + desEye.z;
            v87 = (float)(v84 * this->mUpFrom.x) + UFG::qVector3::msDirUp.x;
            v88.m128_f32[0] = (float)((float)(v83.m128_f32[0] * v83.m128_f32[0]) + (float)(v87 * v87))
                            + (float)(v85 * v85);
            if ( v88.m128_f32[0] == 0.0 )
              v89 = 0.0;
            else
              v89 = 1.0 / _mm_sqrt_ps(v88).m128_f32[0];
            v90 = this->mOffsetLook.p0.z;
            v91 = this->mOffsetLook.p0.x;
            v92 = this->mOffsetLook.p0.y + this->mHorizCompOffset.p0;
            v326 = v87 * v89;
            v327 = v89 * v85;
            v344 = v83.m128_f32[0] * v89;
            v93 = (float)((float)(v91 * *((float *)&v325 + 1)) + (float)(v92 * axis.x))
                + (float)(v90 * (float)(v87 * v89));
            v94 = this->mOffsetEye.p0.y;
            v95 = (float)((float)(v91 * *(float *)&v325) + (float)(v92 * axis.y))
                + (float)(v90 * (float)(v83.m128_f32[0] * v89));
            v324 = v324 + v93;
            v96 = (float)((float)(v91 * 0.0) + (float)(v92 * axis.z)) + (float)(v90 * v327);
            v97 = this->mOffsetEye.p0.z;
            desLook.x = v324;
            v98 = v86 + v96;
            v99 = this->mOffsetEye.p0.x;
            desLook.z = v98;
            v345 = v345 + v95;
            desLook.y = v345;
            v100 = desEye.y
                 + (float)((float)((float)(v99 * *(float *)&v325) + (float)(v94 * axis.y))
                         + (float)(v97 * (float)(v83.m128_f32[0] * v89)));
            desEye.y = v100;
            v101 = desEye.x
                 + (float)((float)((float)(v99 * *((float *)&v325 + 1)) + (float)(v94 * axis.x)) + (float)(v97 * v326));
            desEye.z = desEye.z + (float)((float)((float)(v99 * 0.0) + (float)(v94 * axis.z)) + (float)(v97 * v327));
            desEye.x = v101;
            if ( this->bAimUseEyeLook )
            {
              v102 = (__m128)LODWORD(v345);
              v103 = v324;
              this->rAimParameter = 1.0;
            }
            else
            {
              UFG::qApproach(&this->rAimParameter, 0.0, UFG::FollowCameraComponent::rAimTransitionRateOut, v2);
              v98 = desLook.z;
              v102 = (__m128)LODWORD(desLook.y);
              v103 = desLook.x;
              v101 = desEye.x;
              v100 = desEye.y;
            }
            v104 = v98 - desEye.z;
            v102.m128_f32[0] = v102.m128_f32[0] - v100;
            v105 = v103 - v101;
            v106 = v102;
            v106.m128_f32[0] = (float)((float)(v102.m128_f32[0] * v102.m128_f32[0]) + (float)(v105 * v105))
                             + (float)(v104 * v104);
            if ( v106.m128_f32[0] == 0.0 )
              v107 = 0.0;
            else
              v107 = 1.0 / _mm_sqrt_ps(v106).m128_f32[0];
            v108 = v327;
            v109 = v107;
            v110 = v107;
            v111 = v107 * v104;
            v112 = v326;
            mat.v0.w = 0.0;
            v113 = v109 * v105;
            v114 = v110 * v102.m128_f32[0];
            mat.v0.z = v111;
            v115 = (__m128)LODWORD(v344);
            mat.v0.x = v113;
            mat.v0.y = v114;
            v115.m128_f32[0] = (float)((float)(v115.m128_f32[0] * v115.m128_f32[0]) + (float)(v112 * v112))
                             + (float)(v108 * v108);
            if ( v115.m128_f32[0] == 0.0 )
            {
              v116 = 0i64;
            }
            else
            {
              v116 = (__m128)(unsigned int)FLOAT_1_0;
              v116.m128_f32[0] = 1.0 / _mm_sqrt_ps(v115).m128_f32[0];
            }
            v117 = v116.m128_f32[0];
            v118 = v116.m128_f32[0];
            v116.m128_f32[0] = v116.m128_f32[0] * v327;
            v119 = v117 * v344;
            v120 = v118 * v326;
            v121 = (float)(v119 * v111) - (float)(v116.m128_f32[0] * v114);
            v116.m128_f32[0] = (float)(v116.m128_f32[0] * v113) - (float)(v120 * v111);
            v122 = (float)(v120 * v114) - (float)(v119 * v113);
            v123 = v116;
            v123.m128_f32[0] = (float)((float)(v116.m128_f32[0] * v116.m128_f32[0]) + (float)(v121 * v121))
                             + (float)(v122 * v122);
            if ( v123.m128_f32[0] == 0.0 )
            {
              v125 = 0i64;
            }
            else
            {
              v124 = _mm_sqrt_ps(v123).m128_f32[0];
              v125 = (__m128)(unsigned int)FLOAT_1_0;
              v125.m128_f32[0] = 1.0 / v124;
            }
            v126 = v125;
            mat.v1.w = 0.0;
            v126.m128_f32[0] = v125.m128_f32[0] * v121;
            v129 = v126;
            mat.v1.x = v125.m128_f32[0] * v121;
            mat.v1.z = v125.m128_f32[0] * v122;
            mat.v1.y = v125.m128_f32[0] * v116.m128_f32[0];
            v127 = (float)((float)(v125.m128_f32[0] * v122) * v114)
                 - (float)((float)(v125.m128_f32[0] * v116.m128_f32[0]) * v111);
            v128 = (float)((float)(v125.m128_f32[0] * v116.m128_f32[0]) * v113)
                 - (float)((float)(v125.m128_f32[0] * v121) * v114);
            v129.m128_f32[0] = (float)(v126.m128_f32[0] * v111) - (float)(mat.v1.z * v113);
            v130 = v129;
            v130.m128_f32[0] = (float)((float)(v129.m128_f32[0] * v129.m128_f32[0]) + (float)(v127 * v127))
                             + (float)(v128 * v128);
            if ( v130.m128_f32[0] == 0.0 )
              v131 = 0.0;
            else
              v131 = 1.0 / _mm_sqrt_ps(v130).m128_f32[0];
            mat.v2.w = 0.0;
            mat.v3.w = 1.0;
            mat.v2.z = v131 * v128;
            mat.v2.y = v131 * v129.m128_f32[0];
            mat.v2.x = v131 * v127;
            mat.v3.x = desEye.x;
            mat.v3.y = desEye.y;
            mat.v3.z = desEye.z;
            UFG::qQuaternion::Set(&a, &mat);
            v132 = (__m128)LODWORD(desEye.y);
            v134 = (__m128)LODWORD(this->mAimLook.p0.y);
            v133 = this->mAimLook.p0.x - this->mAimEye.p0.x;
            v134.m128_f32[0] = v134.m128_f32[0] - this->mAimEye.p0.y;
            v135 = this->mAimLook.p0.z;
            v325 = *(_QWORD *)&desEye.y;
            v136 = v135 - this->mAimEye.p0.z;
            v345 = desEye.x;
            v132.m128_f32[0] = (float)((float)((float)(desEye.y - desLook.y) * (float)(desEye.y - desLook.y))
                                     + (float)((float)(desEye.x - desLook.x) * (float)(desEye.x - desLook.x)))
                             + (float)((float)(desEye.z - desLook.z) * (float)(desEye.z - desLook.z));
            v137 = _mm_sqrt_ps(v132).m128_u32[0];
            v138 = v134;
            v324 = *(float *)&v137;
            v138.m128_f32[0] = (float)((float)(v134.m128_f32[0] * v134.m128_f32[0]) + (float)(v133 * v133))
                             + (float)(v136 * v136);
            if ( v138.m128_f32[0] == 0.0 )
              v139 = 0.0;
            else
              v139 = 1.0 / _mm_sqrt_ps(v138).m128_f32[0];
            v140 = v139;
            v141 = v139;
            v142 = v139 * v136;
            v335.v0.w = 0.0;
            v143 = v140 * v133;
            v144 = v141 * v134.m128_f32[0];
            v335.v0.z = v142;
            v335.v0.x = v143;
            v335.v0.y = v144;
            if ( v115.m128_f32[0] == 0.0 )
            {
              v145 = 0i64;
            }
            else
            {
              v145 = (__m128)(unsigned int)FLOAT_1_0;
              v145.m128_f32[0] = 1.0 / _mm_sqrt_ps(v115).m128_f32[0];
            }
            v146 = v145.m128_f32[0];
            v147 = v145.m128_f32[0];
            v145.m128_f32[0] = v145.m128_f32[0] * v108;
            v148 = v146 * v344;
            v149 = v147 * v112;
            v150 = (float)(v148 * v142) - (float)(v145.m128_f32[0] * v144);
            v145.m128_f32[0] = (float)(v145.m128_f32[0] * v143) - (float)(v149 * v142);
            v151 = (float)(v149 * v144) - (float)(v148 * v143);
            v152 = v145;
            v152.m128_f32[0] = (float)((float)(v145.m128_f32[0] * v145.m128_f32[0]) + (float)(v150 * v150))
                             + (float)(v151 * v151);
            if ( v152.m128_f32[0] == 0.0 )
            {
              v154 = 0i64;
            }
            else
            {
              v153 = _mm_sqrt_ps(v152).m128_f32[0];
              v154 = (__m128)(unsigned int)FLOAT_1_0;
              v154.m128_f32[0] = 1.0 / v153;
            }
            v155 = v154;
            v335.v1.w = 0.0;
            v155.m128_f32[0] = v154.m128_f32[0] * v150;
            v158 = v155;
            v335.v1.x = v154.m128_f32[0] * v150;
            v335.v1.z = v154.m128_f32[0] * v151;
            v335.v1.y = v154.m128_f32[0] * v145.m128_f32[0];
            v156 = (float)((float)(v154.m128_f32[0] * v151) * v144)
                 - (float)((float)(v154.m128_f32[0] * v145.m128_f32[0]) * v142);
            v157 = (float)((float)(v154.m128_f32[0] * v145.m128_f32[0]) * v143)
                 - (float)((float)(v154.m128_f32[0] * v150) * v144);
            v158.m128_f32[0] = (float)(v155.m128_f32[0] * v142) - (float)(v335.v1.z * v143);
            v159 = v158;
            v159.m128_f32[0] = (float)((float)(v158.m128_f32[0] * v158.m128_f32[0]) + (float)(v156 * v156))
                             + (float)(v157 * v157);
            if ( v159.m128_f32[0] == 0.0 )
              v160 = 0.0;
            else
              v160 = 1.0 / _mm_sqrt_ps(v159).m128_f32[0];
            v161 = this->mAimEye.p0.z;
            v335.v2.w = 0.0;
            v335.v3.z = v161;
            v335.v2.z = v160 * v157;
            v335.v3.w = 1.0;
            v335.v2.x = v160 * v156;
            v162 = this->mAimEye.p0.y;
            v335.v2.y = v160 * v158.m128_f32[0];
            v163 = this->mAimEye.p0.x;
            v335.v3.y = v162;
            v335.v3.x = v163;
            UFG::qQuaternion::Set(&b, &v335);
            v164 = (float)(sinf((float)(this->rAimParameter * 3.1415927) - 1.5707964) + 1.0) * 0.5;
            v165 = v164 * this->mAimEye.p0.z;
            v166 = (float)((float)(1.0 - v164) * *(float *)&v325) + (float)(v164 * this->mAimEye.p0.y);
            t.x = (float)((float)(1.0 - v164) * v345) + (float)(v164 * this->mAimEye.p0.x);
            t.y = v166;
            t.z = (float)((float)(1.0 - v164) * *((float *)&v325 + 1)) + v165;
            UFG::qSlerp(&result, &a, &b, v164, qAngularPath_Shortest);
            UFG::qQuaternion::GetMatrix(&result, &v343, &t);
            desEye.x = v343.v3.x;
            *(_QWORD *)&desEye.y = *(_QWORD *)&v343.v3.y;
            desLook.x = (float)(v324 * v343.v0.x) + v343.v3.x;
            desLook.y = (float)(v324 * v343.v0.y) + v343.v3.y;
            desLook.z = (float)(v324 * v343.v0.z) + v343.v3.z;
            v167 = UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0);
            if ( this->bAllowDesaturation && v167 )
              mDesaturation = this->mBlendedParams.mDesaturation;
            else
              mDesaturation = 0.0;
            mMotionblurMagnitude = this->mBlendedParams.mMotionblurMagnitude;
            this->mCamera.mDesaturation = mDesaturation;
            this->mCamera.mMotionBlur = mMotionblurMagnitude;
            if ( this->mTarget.m_pSimComponent
              && (v170 = (UFG::SimObjectCharacter *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
            {
              v171 = v170->m_Flags;
              if ( (v171 & 0x4000) != 0 )
              {
                ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v170);
              }
              else if ( v171 < 0 || (v171 & 0x2000) != 0 || (v171 & 0x1000) != 0 )
              {
                ComponentOfType = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v170,
                                                                  UFG::AimingPlayerComponent::_TypeUID);
              }
              else
              {
                ComponentOfType = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v170,
                                                                  UFG::AimingPlayerComponent::_TypeUID);
              }
            }
            else
            {
              ComponentOfType = 0i64;
            }
            if ( this->mTarget.m_pSimComponent
              && (v173 = (UFG::SimObjectCVBase *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
            {
              v174 = v173->m_Flags;
              if ( (v174 & 0x4000) != 0 || v174 < 0 )
              {
                v175 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v173);
              }
              else if ( (v174 & 0x2000) != 0 || (v174 & 0x1000) != 0 )
              {
                v175 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v173,
                                                                   UFG::TargetingSystemPedPlayerComponent::_TypeUID);
              }
              else
              {
                v175 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                   v173,
                                                                   UFG::TargetingSystemPedPlayerComponent::_TypeUID);
              }
            }
            else
            {
              v175 = 0i64;
            }
            if ( v175 )
            {
              v176 = v175->m_eFocusMode == eFOCUS_MODE_LOCKED;
              if ( v175->m_eFocusMode == eFOCUS_MODE_LOCKED )
              {
                v177 = v175->m_pTargets[(unsigned __int8)v175->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
LABEL_157:
                if ( ComponentOfType )
                  v178 = ComponentOfType->m_FreeAimSimObject.m_pPointer;
                else
                  v178 = 0i64;
                if ( v176 )
                  v178 = v177;
                if ( v178 )
                  m_pTransformNodeComponent = v178->m_pTransformNodeComponent;
                else
                  m_pTransformNodeComponent = 0i64;
                v180 = ((float (__fastcall *)(UFG::FollowCameraComponent *, UFG::SimObject *))this->vfptr[19].__vecDelDtor)(
                         this,
                         v177);
                v181 = tanf(v180 * 0.5);
                duration.x = desLook.x;
                mTweakNoiseFrequency = this->mBlendedParams.mTweakNoiseFrequency;
                duration.y = desLook.y;
                look.x = mTweakNoiseFrequency;
                look.y = mTweakNoiseFrequency;
                v183 = (float)(v181 * 1.3) * this->mBlendedParams.mTweakNoiseEyeMagnitude;
                v184 = (float)(v181 * 1.3) * this->mBlendedParams.mTweakNoiseLookMagnitude;
                duration.z = desLook.z;
                look.z = mTweakNoiseFrequency;
                UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetFrequency(&this->mLookNoise, &look, &duration);
                look.x = desEye.x;
                look.y = desEye.y;
                v185 = this->mBlendedParams.mTweakNoiseFrequency;
                look.z = desEye.z;
                duration.x = v185;
                duration.y = v185;
                duration.z = v185;
                UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetFrequency(&this->mEyeNoise, &duration, &look);
                look.x = v184;
                look.y = v184;
                look.z = v184;
                LODWORD(duration.x) = LODWORD(v184) ^ _xmm[0];
                LODWORD(duration.y) = LODWORD(v184) ^ _xmm[0];
                LODWORD(duration.z) = LODWORD(v184) ^ _xmm[0];
                UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&this->mLookNoise, &duration, &look);
                look.x = v183;
                look.y = v183;
                look.z = v183;
                LODWORD(duration.x) = LODWORD(v183) ^ _xmm[0];
                LODWORD(duration.y) = LODWORD(v183) ^ _xmm[0];
                LODWORD(duration.z) = LODWORD(v183) ^ _xmm[0];
                UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&this->mEyeNoise, &duration, &look);
                if ( this->mBlendedParams.mTweakNoiseLookMagnitude != 0.0 )
                {
                  look = desEye;
                  Value = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(&this->mEyeNoise, &duration, &look);
                  v187 = desEye.z + Value->z;
                  v188 = desEye.x + Value->x;
                  desEye.y = desEye.y + Value->y;
                  desEye.z = v187;
                  desEye.x = v188;
                }
                if ( this->mBlendedParams.mTweakNoiseEyeMagnitude != 0.0 )
                {
                  look = desLook;
                  v189 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(&this->mEyeNoise, &duration, &look);
                  v190 = desLook.z + v189->z;
                  v191 = desLook.x + v189->x;
                  desLook.y = desLook.y + v189->y;
                  desLook.z = v190;
                  desLook.x = v191;
                }
                if ( UFG::bHeadCamera )
                {
                  UFG::CharacterSubjectComponent::GetHeadTransform(
                    (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
                    &m);
                  m_pSimComponent = this->mTarget.m_pSimComponent;
                  v193 = (float)(1.0 - UFG::fHeadCameraLookBlend)
                       * (float)((float)((float)((float)(m.v1.x * 0.1) + (float)(m.v0.x * 0.0)) + (float)(m.v2.x * 0.0))
                               + m.v3.x);
                  desEye.y = (float)((float)((float)(m.v1.y * 0.1) + (float)(m.v0.y * 0.0)) + (float)(m.v2.y * 0.0))
                           + m.v3.y;
                  desEye.x = (float)((float)((float)(m.v1.x * 0.1) + (float)(m.v0.x * 0.0)) + (float)(m.v2.x * 0.0))
                           + m.v3.x;
                  v194 = desEye.y * (float)(1.0 - UFG::fHeadCameraLookBlend);
                  desEye.z = (float)((float)((float)(m.v1.z * 0.1) + (float)(m.v0.z * 0.0)) + (float)(m.v2.z * 0.0))
                           + m.v3.z;
                  v195 = desEye.z * (float)(1.0 - UFG::fHeadCameraLookBlend);
                  v196 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[16].__vecDelDtor)(m_pSimComponent);
                  v197 = (float)((float)((float)((float)(m.v1.y * UFG::fHeadCameraLookBlend)
                                               + (float)(m.v0.y * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                       + (float)(m.v2.y * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                               + (float)(m.v3.y * UFG::fHeadCameraLookBlend))
                       + (float)(v194 + v196[1]);
                  v198 = (float)((float)((float)((float)(m.v1.z * UFG::fHeadCameraLookBlend)
                                               + (float)(m.v0.z * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                       + (float)(m.v2.z * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                               + (float)(m.v3.z * UFG::fHeadCameraLookBlend))
                       + (float)(v195 + v196[2]);
                  desLook.x = (float)((float)((float)((float)(m.v1.x * UFG::fHeadCameraLookBlend)
                                                    + (float)(m.v0.x * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                            + (float)(m.v2.x * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                    + (float)(m.v3.x * UFG::fHeadCameraLookBlend))
                            + (float)(v193 + *v196);
                  desLook.y = v197;
                  desLook.z = v198;
                }
                v199 = this->mTarget.m_pSimComponent;
                if ( BYTE6(v199[15].m_SafePointerList.mNode.mNext) )
                  UFG::CharacterSubjectComponent::UpdatePelvis((UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent);
                v200 = ((__int64 (__fastcall *)(UFG::SimComponent *))v199->vfptr[26].__vecDelDtor)(v199);
                this->mCollisionTargetPointsNum = 2;
                v201 = *(float *)(v200 + 4);
                v202 = *(float *)(v200 + 8);
                this->mCollisionTargetPoints[0].x = *(float *)v200;
                this->mCollisionTargetPoints[0].y = v201;
                this->mCollisionTargetPoints[0].z = v202;
                v203 = *(float *)&v199[15].vfptr;
                v204 = *((float *)&v199[15].vfptr + 1);
                this->mCollisionTargetPoints[1].x = *((float *)&v199[14].m_BoundComponentHandles.mNode.mNext + 1);
                this->mCollisionTargetPoints[1].y = v203;
                this->mCollisionTargetPoints[1].z = v204;
                v205 = UFG::FollowCameraComponent::mFollowCollisionPlateau;
                v15 = this->mType == eFOLLOW_CAMERA_TYPE_AIM;
                v206 = UFG::FollowCameraComponent::mFollowCollisionBlend;
                this->mCollisionRise = this->mBlendedParams.mCollisionRise;
                this->mCollisionPlateau = v205;
                this->mPushInOverrideRate = 0.0;
                this->mCollisionBlend = v206;
                if ( v15 )
                {
                  if ( this->mBlendedParams.mTweakUseSyncBase )
                  {
                    v207 = (UFG::SimObjectCharacter *)this->mTarget.m_pSimComponent->m_pSimObject;
                    if ( v207 )
                    {
                      v209 = v207->m_Flags;
                      if ( (v209 & 0x4000) != 0 )
                      {
                        v208 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v207);
                      }
                      else if ( v209 < 0 || (v209 & 0x2000) != 0 || (v209 & 0x1000) != 0 )
                      {
                        v208 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v207,
                                                               UFG::AimingPlayerComponent::_TypeUID);
                      }
                      else
                      {
                        v208 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                               v207,
                                                               UFG::AimingPlayerComponent::_TypeUID);
                      }
                    }
                    else
                    {
                      v208 = 0i64;
                    }
                    v210 = v208->m_vFreeAimBaseOffset.x;
                    v211 = v208->m_vFreeAimBaseOffset.y;
                    v212 = v208->m_vFreeAimBaseOffset.z;
                  }
                  else
                  {
                    v213 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[26].__vecDelDtor)(this->mTarget.m_pSimComponent);
                    v210 = *v213;
                    v211 = v213[1];
                    v212 = v213[2];
                  }
                  v214 = desLook.y;
                  v215 = desLook.x;
                  v216 = desLook.z;
                  this->mCollisionRise = 0.0;
                  this->mCollisionBlend = 0.69999999;
                  this->mCollisionPlateau = 0.69999999;
                  v217 = v214 - desEye.y;
                  v218 = v215 - desEye.x;
                  v219 = v216 - desEye.z;
                  v220 = (float)((float)((float)(v217 * (float)(v211 - desEye.y))
                                       + (float)(v218 * (float)(v210 - desEye.x)))
                               + (float)(v219 * (float)(v212 - desEye.z)))
                       / (float)((float)((float)(v217 * v217) + (float)(v218 * v218)) + (float)(v219 * v219));
                  desLook.z = desEye.z + (float)(v220 * v219);
                  desLook.x = desEye.x + (float)(v220 * v218);
                  desLook.y = desEye.y + (float)(v220 * v217);
                }
                this->mAlternateLookValid = 0;
                UFG::CharacterSubjectComponent::GetRigidBodyPosition(
                  (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
                  &v331);
                v221 = desLook.z;
                v222 = desLook.x;
                v228 = (__m128)LODWORD(desLook.y);
                v223 = v331.y;
                v224 = desEye.x;
                v225 = desEye.y;
                v226 = (__m128)LODWORD(desEye.y);
                v227 = desEye.z;
                v226.m128_f32[0] = (float)(desEye.y - desLook.y) * (float)(desEye.y - desLook.y);
                this->mAlternateLook.x = v331.x;
                this->mAlternateLook.y = v223;
                v228.m128_f32[0] = v228.m128_f32[0] - v225;
                v229 = v224 - v222;
                v230 = v222 - v224;
                this->mAlternateLook.z = v221;
                v331.z = v221;
                this->mAlternateLookValid = 1;
                v226.m128_f32[0] = (float)(v226.m128_f32[0] + (float)(v229 * v229))
                                 + (float)((float)(v227 - v221) * (float)(v227 - v221));
                v231 = v221 - v227;
                v232 = _mm_sqrt_ps(v226).m128_u32[0];
                v233 = v228;
                v345 = *(float *)&v232;
                v233.m128_f32[0] = (float)((float)(v228.m128_f32[0] * v228.m128_f32[0]) + (float)(v230 * v230))
                                 + (float)(v231 * v231);
                if ( v233.m128_f32[0] == 0.0 )
                  v234 = 0.0;
                else
                  v234 = 1.0 / _mm_sqrt_ps(v233).m128_f32[0];
                v235 = v234;
                v236 = v234;
                v237 = v234 * v231;
                v333.v0.w = 0.0;
                v238 = v235 * v230;
                v239 = v236 * v228.m128_f32[0];
                v333.v0.z = v237;
                v333.v0.x = v238;
                v333.v0.y = v239;
                if ( v115.m128_f32[0] == 0.0 )
                {
                  v240 = 0i64;
                }
                else
                {
                  v240 = (__m128)(unsigned int)FLOAT_1_0;
                  v240.m128_f32[0] = 1.0 / _mm_sqrt_ps(v115).m128_f32[0];
                }
                v241 = v240.m128_f32[0];
                v242 = v240.m128_f32[0];
                v240.m128_f32[0] = v240.m128_f32[0] * v327;
                v243 = v241 * v344;
                v244 = v242 * v326;
                v245 = (float)(v243 * v237) - (float)(v240.m128_f32[0] * v239);
                v240.m128_f32[0] = (float)(v240.m128_f32[0] * v238) - (float)(v244 * v237);
                v246 = (float)(v244 * v239) - (float)(v243 * v238);
                v247 = v240;
                v247.m128_f32[0] = (float)((float)(v240.m128_f32[0] * v240.m128_f32[0]) + (float)(v245 * v245))
                                 + (float)(v246 * v246);
                if ( v247.m128_f32[0] == 0.0 )
                {
                  v249 = 0i64;
                }
                else
                {
                  v248 = _mm_sqrt_ps(v247).m128_f32[0];
                  v249 = (__m128)(unsigned int)FLOAT_1_0;
                  v249.m128_f32[0] = 1.0 / v248;
                }
                v250 = v249;
                v333.v1.w = 0.0;
                v250.m128_f32[0] = v249.m128_f32[0] * v245;
                v253 = v250;
                v333.v1.x = v249.m128_f32[0] * v245;
                v333.v1.z = v249.m128_f32[0] * v246;
                v333.v1.y = v249.m128_f32[0] * v240.m128_f32[0];
                v251 = (float)((float)(v249.m128_f32[0] * v246) * v239)
                     - (float)((float)(v249.m128_f32[0] * v240.m128_f32[0]) * v237);
                v252 = (float)((float)(v249.m128_f32[0] * v240.m128_f32[0]) * v238)
                     - (float)((float)(v249.m128_f32[0] * v245) * v239);
                v253.m128_f32[0] = (float)(v250.m128_f32[0] * v237) - (float)(v333.v1.z * v238);
                v254 = v253;
                v254.m128_f32[0] = (float)((float)(v253.m128_f32[0] * v253.m128_f32[0]) + (float)(v251 * v251))
                                 + (float)(v252 * v252);
                if ( v254.m128_f32[0] == 0.0 )
                  v255 = 0.0;
                else
                  v255 = 1.0 / _mm_sqrt_ps(v254).m128_f32[0];
                v333.v2.w = 0.0;
                v333.v2.z = v255 * v252;
                v333.v3.w = 1.0;
                v333.v2.x = v255 * v251;
                v333.v2.y = v255 * v253.m128_f32[0];
                *(_QWORD *)&v333.v3.y = *(_QWORD *)&desEye.y;
                v333.v3.x = desEye.x;
                UFG::qQuaternion::Set(&v342, &v333);
                mTransitionParamEye = this->mTransitionParamEye;
                v257 = desEye.z * (float)(1.0 - mTransitionParamEye);
                v258 = desEye.x * (float)(1.0 - mTransitionParamEye);
                v259 = (float)(mTransitionParamEye * this->mTransitionFromEye.y)
                     + (float)(desEye.y * (float)(1.0 - mTransitionParamEye));
                v260 = this->mTransitionParamOrient;
                v261 = mTransitionParamEye * this->mTransitionFromEye.x;
                v262 = mTransitionParamEye * this->mTransitionFromEye.z;
                v328.y = v259;
                v328.x = v261 + v258;
                v328.z = v262 + v257;
                UFG::qSlerp(&v338, &v342, &this->mTransitionFromOri, v260, qAngularPath_Shortest);
                v263 = this->mTransitionParamEye;
                desEye.y = v328.y;
                v264 = (float)((float)(1.0 - v263) * v345) + (float)(v263 * this->mTransitionFromLen);
                desEye.x = v328.x;
                desEye.z = v328.z;
                Matrix = UFG::qQuaternion::GetMatrix(&v338, &m, &v328);
                v266 = (__m128)Matrix->v2;
                v267 = Matrix->v0;
                v268 = Matrix->v1;
                v269 = Matrix->v3;
                LODWORD(duration.y) = _mm_shuffle_ps(v266, v266, 85).m128_u32[0];
                v333.v1 = v268;
                v333.v2 = (UFG::qVector4)v266;
                v333.v0 = v267;
                v333.v3 = v269;
                LODWORD(duration.x) = v266.m128_i32[0];
                LODWORD(duration.z) = _mm_shuffle_ps(v266, v266, 170).m128_u32[0];
                desLook.x = desEye.x + (float)(v264 * v267.x);
                desLook.y = desEye.y + (float)(v264 * _mm_shuffle_ps((__m128)v267, (__m128)v267, 85).m128_f32[0]);
                desLook.z = desEye.z + (float)(v264 * _mm_shuffle_ps((__m128)v267, (__m128)v267, 170).m128_f32[0]);
                UFG::GameCameraComponent::SetDesiredEyeLookUp(this, v2, &desEye, &desLook, &duration, 1, &eye, &look);
                ExtraWideAspectCorrectedFOV = (float)(this->mFov.p0 * 3.1415927) * 0.0055555557;
                if ( !Render::GetRenderFeatures()->mForceLetterBox )
                  ExtraWideAspectCorrectedFOV = Render::GetExtraWideAspectCorrectedFOV(ExtraWideAspectCorrectedFOV);
                v271 = UFG::GameCameraComponent::ComputeNearOffset(this, &eye, &look, ExtraWideAspectCorrectedFOV)
                     + UFG::gCameraDefaultNear;
                DisplayAspectRatio = Render::GetDisplayAspectRatio();
                UFG::Camera::SetViewProjection(
                  &this->mCamera,
                  ExtraWideAspectCorrectedFOV,
                  DisplayAspectRatio,
                  v271,
                  UFG::gCameraDefaultFar,
                  0.0,
                  0.0,
                  1);
                this->mPushInOverrideRate = 0.0;
                UFG::Camera::ApplyDutch(&this->mCamera, UFG::GameCameraComponent::mDutchDyn.p0);
                if ( this->mGotoAngleCollisionQueued && this->mInCollision )
                {
                  v273 = this->mEyeCurr.z - this->mLookCurr.z;
                  if ( (float)((float)((float)((float)(this->mEyeCurr.y - this->mLookCurr.y)
                                             * (float)(this->mEyeCurr.y - this->mLookCurr.y))
                                     + (float)((float)(this->mEyeCurr.x - this->mLookCurr.x)
                                             * (float)(this->mEyeCurr.x - this->mLookCurr.x)))
                             + (float)(v273 * v273)) < (float)(UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius
                                                             * UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius) )
                    UFG::FollowCameraComponent::GotoAngleCollision(
                      this,
                      this->mGotoAngleCollisionQueuedWallDist,
                      &desEye,
                      &desLook,
                      &duration);
                }
                this->mGotoAngleCollisionQueued = 0;
                UFG::FollowCameraComponent::DetermineMeleeAttackerPositions(this);
                if ( this->mNumMeleeAttackers <= 0
                  || this->mBlendedParams.mSrcOrientation == SrcTransform_POI
                  || this->mBlendedParams.mSrcPosition == SrcTransform_POI )
                {
                  if ( this->mAutoFrameActive )
                  {
                    this->mAutoFrameActive = 0;
                    this->mMaxRadiusOverrideEnabled = 0;
                    this->mRiseOverrideEnabled = 0;
                  }
                }
                else
                {
                  v274 = 0.0;
                  p_z = &this->mMeleeAttackerPositions[0].z;
                  do
                  {
                    v276 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
                    v278 = (__m128)*((unsigned int *)p_z - 1);
                    v277 = *(p_z - 2) - *v276;
                    v278.m128_f32[0] = v278.m128_f32[0] - v276[1];
                    v280 = v278;
                    v279 = *p_z - v276[2];
                    v280.m128_f32[0] = (float)((float)(v278.m128_f32[0] * v278.m128_f32[0]) + (float)(v277 * v277))
                                     + (float)(v279 * v279);
                    if ( v280.m128_f32[0] == 0.0 )
                      v281 = 0.0;
                    else
                      v281 = 1.0 / _mm_sqrt_ps(v280).m128_f32[0];
                    *(_QWORD *)&v282 = LODWORD(this->mCamera.mTransformation.v2.y) ^ (unsigned __int64)(unsigned int)_xmm[0];
                    *(float *)&v282 = (float)((float)(*(float *)&v282 * (float)(v281 * v278.m128_f32[0]))
                                            + (float)(COERCE_FLOAT(LODWORD(this->mCamera.mTransformation.v2.x) ^ _xmm[0])
                                                    * (float)(v281 * v277)))
                                    + (float)(COERCE_FLOAT(LODWORD(this->mCamera.mTransformation.v2.z) ^ _xmm[0])
                                            * (float)(v281 * v279));
                    v283 = (float)(UFG::FollowCameraComponent::rAutoFrameOffsetAngleStart * 3.1415927) * 0.0055555557;
                    v284 = UFG::qACos(v282);
                    v285 = (float)(*(float *)&v284 - v283) / (float)(3.1415927 - v283);
                    if ( v285 <= 0.0 )
                    {
                      v285 = 0.0;
                    }
                    else if ( v285 >= 1.0 )
                    {
                      v285 = *(float *)&FLOAT_1_0;
                    }
                    v286 = v285 * UFG::FollowCameraComponent::rAutoFrameFarthestDistOffset;
                    v287 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
                    v288 = (__m128)*(unsigned int *)(v287 + 4);
                    v288.m128_f32[0] = (float)((float)((float)(v288.m128_f32[0] - *(p_z - 1))
                                                     * (float)(v288.m128_f32[0] - *(p_z - 1)))
                                             + (float)((float)(*(float *)v287 - *(p_z - 2))
                                                     * (float)(*(float *)v287 - *(p_z - 2))))
                                     + (float)((float)(*(float *)(v287 + 8) - *p_z)
                                             * (float)(*(float *)(v287 + 8) - *p_z));
                    v289 = _mm_sqrt_ps(v288).m128_f32[0];
                    if ( v289 > UFG::FollowCameraComponent::rAutoFrameFarthestDistClamp )
                      v289 = UFG::FollowCameraComponent::rAutoFrameFarthestDistClamp;
                    v290 = v289 + v286;
                    if ( v290 > v274 )
                      v274 = v290;
                    ++v20;
                    p_z += 3;
                  }
                  while ( v20 < this->mNumMeleeAttackers );
                  if ( !this->mAutoFrameActive )
                    this->mAutoFrameFarthestAttackerDist = UFG::FollowCameraComponent::rAutoFrameFarthestDistClamp;
                  if ( v274 <= this->mAutoFrameFarthestAttackerDist )
                    v291 = UFG::FollowCameraComponent::rAutoFrameFarthestDistShrinkRate;
                  else
                    v291 = UFG::FollowCameraComponent::rAutoFrameFarthestDistGrowRate;
                  UFG::qApproach(&this->mAutoFrameFarthestAttackerDist, v274, v291, v2);
                  if ( this->mAutoFrameSnapNextAttackerDist )
                    this->mAutoFrameFarthestAttackerDist = v274;
                  mAutoFrameFarthestAttackerDist = this->mAutoFrameFarthestAttackerDist;
                  if ( mAutoFrameFarthestAttackerDist <= UFG::FollowCameraComponent::rAutoFrameMinRadius )
                    mAutoFrameFarthestAttackerDist = UFG::FollowCameraComponent::rAutoFrameMinRadius;
                  UFG::FollowCameraComponent::SetOverrideMaxRadius(this, mAutoFrameFarthestAttackerDist);
                  v295 = (__m128)LODWORD(desEye.y);
                  mTweakEyeRise = this->mBlendedParams.mTweakEyeRise;
                  v294 = mTweakEyeRise;
                  v295.m128_f32[0] = desEye.y - desLook.y;
                  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                      this->mBlendedParams.mTweakRadiusMax
                                    - UFG::FollowCameraComponent::rAutoFrameMinRadius) & _xmm) > 0.00000011920929 )
                  {
                    v295.m128_f32[0] = (float)(v295.m128_f32[0] * v295.m128_f32[0])
                                     + (float)((float)(desEye.x - desLook.x) * (float)(desEye.x - desLook.x));
                    v296 = (float)(_mm_sqrt_ps(v295).m128_f32[0] - this->mBlendedParams.mTweakRadiusMax)
                         / (float)(UFG::FollowCameraComponent::rAutoFrameMinRadius - this->mBlendedParams.mTweakRadiusMax);
                    if ( v296 <= 0.0 )
                    {
                      v296 = 0.0;
                    }
                    else if ( v296 >= 1.0 )
                    {
                      v296 = *(float *)&FLOAT_1_0;
                    }
                    v294 = (float)((float)(UFG::FollowCameraComponent::rAutoFrameMinEyeRise - mTweakEyeRise) * v296)
                         + mTweakEyeRise;
                  }
                  if ( v294 >= this->mBlendedParams.mTweakEyeRise )
                    v294 = this->mBlendedParams.mTweakEyeRise;
                  if ( v294 > mTweakEyeRise )
                    v294 = this->mBlendedParams.mTweakEyeRise;
                  this->mRiseOverride = v294;
                  this->mRiseOverrideEnabled = 1;
                  this->mAutoFrameActive = 1;
                }
                if ( this->mBlendedParams.mUseDofParameters )
                {
                  v297 = this->mLookCurr.x - this->mEyeCurr.x;
                  v298 = this->mLookCurr.y - this->mEyeCurr.y;
                  v299 = this->mLookCurr.z - this->mEyeCurr.z;
                  v300 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[26].__vecDelDtor)(this->mTarget.m_pSimComponent);
                  v301 = (__m128)*(unsigned int *)(v300 + 4);
                  v302 = 1.0 / (float)((float)((float)(v298 * v298) + (float)(v297 * v297)) + (float)(v299 * v299));
                  v301.m128_f32[0] = (float)((float)((float)((float)(v301.m128_f32[0] - this->mEyeCurr.y) * v298)
                                                   + (float)((float)(*(float *)v300 - this->mEyeCurr.x) * v297))
                                           + (float)((float)(*(float *)(v300 + 8) - this->mEyeCurr.z) * v299))
                                   * v302;
                  v303 = v301;
                  v303.m128_f32[0] = (float)((float)((float)(v303.m128_f32[0] * v298) * (float)(v303.m128_f32[0] * v298))
                                           + (float)((float)(v301.m128_f32[0] * v297) * (float)(v301.m128_f32[0] * v297)))
                                   + (float)((float)(v301.m128_f32[0] * v299) * (float)(v301.m128_f32[0] * v299));
                  v304 = _mm_sqrt_ps(v303).m128_f32[0];
                  v305 = v304;
                  if ( v304 < UFG::trDofMinimumFocusDistanceAllTargets )
                    v305 = UFG::trDofMinimumFocusDistanceAllTargets;
                  UFG::GameCameraComponent::mDofFocusObjectDistNear = v305;
                  UFG::GameCameraComponent::mDofFocusObjectDistFar = v305;
                  mDofFarFocalDist = this->mDofFarFocalDist;
                  v307 = v304;
                  if ( v304 >= mDofFarFocalDist )
                    v308 = UFG::FollowCameraComponent::mDofNormalFarDistGrowRate;
                  else
                    v308 = UFG::FollowCameraComponent::mDofNormalFarDistShrinkRate;
                  if ( m_pTransformNodeComponent && (this->mFreeAiming || this->mSoftLocked || this->mFocusLocked) )
                  {
                    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                    v309 = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
                    v309.m128_f32[0] = (float)((float)((float)(v309.m128_f32[0] - this->mEyeCurr.y) * v298)
                                             + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x
                                                             - this->mEyeCurr.x)
                                                     * v297))
                                     + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - this->mEyeCurr.z)
                                             * v299);
                    v310 = v309;
                    v310.m128_f32[0] = v309.m128_f32[0] * v302;
                    v311 = v310;
                    v311.m128_f32[0] = (float)((float)((float)(v311.m128_f32[0] * v298)
                                                     * (float)(v311.m128_f32[0] * v298))
                                             + (float)((float)((float)(v309.m128_f32[0] * v302) * v297)
                                                     * (float)((float)(v309.m128_f32[0] * v302) * v297)))
                                     + (float)((float)((float)(v309.m128_f32[0] * v302) * v299)
                                             * (float)((float)(v309.m128_f32[0] * v302) * v299));
                    v312 = _mm_sqrt_ps(v311).m128_f32[0];
                    if ( v312 > v304 && v309.m128_f32[0] > 0.0 )
                      v307 = v312;
                    mDofFarFocalDist = this->mDofFarFocalDist;
                    if ( v307 >= mDofFarFocalDist )
                      v308 = UFG::FollowCameraComponent::mDofAimingFarDistGrowRate;
                    else
                      v308 = UFG::FollowCameraComponent::mDofAimingFarDistShrinkRate;
                  }
                  else
                  {
                    mNumMeleeAttackers = (unsigned int)this->mNumMeleeAttackers;
                    if ( (int)mNumMeleeAttackers >= 1 )
                    {
                      v314 = &this->mMeleeAttackerPositions[0].z;
                      do
                      {
                        v315 = (__m128)*((unsigned int *)v314 - 1);
                        v315.m128_f32[0] = (float)((float)((float)(v315.m128_f32[0] - this->mEyeCurr.y) * v298)
                                                 + (float)((float)(*(v314 - 2) - this->mEyeCurr.x) * v297))
                                         + (float)((float)(*v314 - this->mEyeCurr.z) * v299);
                        v316 = v315;
                        v316.m128_f32[0] = v315.m128_f32[0] * v302;
                        v317 = v316;
                        v317.m128_f32[0] = (float)((float)((float)(v317.m128_f32[0] * v298)
                                                         * (float)(v317.m128_f32[0] * v298))
                                                 + (float)((float)((float)(v315.m128_f32[0] * v302) * v297)
                                                         * (float)((float)(v315.m128_f32[0] * v302) * v297)))
                                         + (float)((float)((float)(v315.m128_f32[0] * v302) * v299)
                                                 * (float)((float)(v315.m128_f32[0] * v302) * v299));
                        v318 = _mm_sqrt_ps(v317).m128_f32[0];
                        if ( v318 > v307 && v315.m128_f32[0] > 0.0 )
                          v307 = v318;
                        if ( v307 >= mDofFarFocalDist )
                          v308 = UFG::FollowCameraComponent::mDofMeleeFarDistGrowRate;
                        else
                          v308 = UFG::FollowCameraComponent::mDofMeleeFarDistShrinkRate;
                        v314 += 3;
                        --mNumMeleeAttackers;
                      }
                      while ( mNumMeleeAttackers );
                    }
                  }
                  UFG::qApproach(
                    &this->mDofFarFocalDist,
                    v307,
                    COERCE_FLOAT(COERCE_UNSIGNED_INT(mDofFarFocalDist - v307) & _xmm) * v308,
                    v2);
                  v319 = this->mDofFarFocalDist;
                  if ( v319 > v304 )
                  {
                    if ( v319 < UFG::trDofMinimumFocusDistanceAllTargets )
                      v319 = UFG::trDofMinimumFocusDistanceAllTargets;
                    if ( v319 >= UFG::GameCameraComponent::mDofFocusObjectDistNear )
                    {
                      if ( v319 > UFG::GameCameraComponent::mDofFocusObjectDistFar )
                        UFG::GameCameraComponent::mDofFocusObjectDistFar = v319;
                    }
                    else
                    {
                      UFG::GameCameraComponent::mDofFocusObjectDistNear = v319;
                    }
                  }
                }
                if ( this->mBlendedParams.mUseDofParameters )
                  UFG::GameCameraComponent::UpdateDof(
                    this,
                    v2,
                    this->mBlendedParams.mDofInFocusRange,
                    this->mBlendedParams.mDofNearRange,
                    this->mBlendedParams.mDofNearBlurRadius,
                    this->mBlendedParams.mDofFarRange,
                    this->mBlendedParams.mDofFarBlurRadius);
                else
                  UFG::GameCameraComponent::UpdateDof(this, v2, &this->mCamera.mDepthOfFieldFocus, 0);
                return;
              }
            }
            else
            {
              v176 = 0;
            }
            v177 = 0i64;
            goto LABEL_157;
          }
          v30 = p1 < 0.0;
        }
        if ( !v30 || p1 >= this->mHorizCompOffset.p0 )
          goto LABEL_47;
        goto LABEL_46;
      }
    }
  }
}

// File Line: 2871
// RVA: 0x3C9160
void __fastcall UFG::FollowCameraComponent::Rotate(
        UFG::FollowCameraComponent *this,
        float delta_latitude,
        float delta_longitude)
{
  float z; // xmm12_4
  float x; // xmm10_4
  float y; // xmm11_4
  __m128 z_low; // xmm6
  __m128 x_low; // xmm7
  float v9; // xmm9_4
  float v10; // xmm0_4
  float v11; // xmm9_4
  float v12; // xmm13_4
  __m128 v13; // xmm0
  float v14; // xmm13_4
  float mLatitudeMin; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rbx

  z_low = (__m128)LODWORD(this->mEye.p1.z);
  x_low = (__m128)LODWORD(this->mEye.p1.x);
  z = this->mLook.p1.z;
  x = this->mLook.p1.x;
  y = this->mLook.p1.y;
  z_low.m128_f32[0] = z_low.m128_f32[0] - z;
  x_low.m128_f32[0] = x_low.m128_f32[0] - x;
  v9 = this->mEye.p1.y - y;
  if ( z_low.m128_f32[0] < 0.0 )
    z_low.m128_f32[0] = z_low.m128_f32[0] / this->mOrbitSquish;
  v10 = atan2f(v9, x_low.m128_f32[0]);
  x_low.m128_f32[0] = x_low.m128_f32[0] * x_low.m128_f32[0];
  v11 = v9 * v9;
  v12 = v10;
  v13 = x_low;
  v13.m128_f32[0] = x_low.m128_f32[0] + v11;
  v14 = v12 + delta_longitude;
  mLatitudeMin = atan2f(z_low.m128_f32[0], _mm_sqrt_ps(v13).m128_f32[0]) + delta_latitude;
  if ( mLatitudeMin <= this->mLatitudeMin )
    mLatitudeMin = this->mLatitudeMin;
  if ( mLatitudeMin >= this->mBlendedParams.mTweakLatitudeMax )
    mLatitudeMin = this->mBlendedParams.mTweakLatitudeMax;
  z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(x_low.m128_f32[0] + v11);
  v16 = _mm_sqrt_ps(z_low).m128_f32[0];
  v17 = cosf(mLatitudeMin);
  v18 = sinf(mLatitudeMin) * v16;
  v19 = v17 * v16;
  v20 = cosf(v14) * v19;
  v21 = sinf(v14) * v19;
  if ( v18 < 0.0 )
    v18 = v18 * this->mOrbitSquish;
  p_mEye = &this->mEye;
  p_mEye->p1.x = x + v20;
  p_mEye->p1.y = y + v21;
  p_mEye->p1.z = z + v18;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mEye);
  *(_QWORD *)&p_mEye->mParameter.x = 0i64;
  p_mEye->mParameter.z = 0.0;
}

// File Line: 2896
// RVA: 0x3D81A0
void __fastcall UFG::FollowCameraComponent::UpdateAimOrigin(UFG::FollowCameraComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  float v3; // xmm0_4
  float v4; // xmm1_4

  m_pSimComponent = this->mTarget.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( BYTE5(m_pSimComponent[15].m_SafePointerList.mNode.mNext) )
      UFG::CharacterSubjectComponent::UpdateCambone((UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent);
    v3 = *((float *)&m_pSimComponent[14].m_BoundComponentHandles.mNode.mPrev + 1);
    v4 = *(float *)&m_pSimComponent[14].m_BoundComponentHandles.mNode.mNext;
    this->mAimOrigin.x = *(float *)&m_pSimComponent[14].m_BoundComponentHandles.mNode.mPrev;
    this->mAimOrigin.y = v3;
    this->mAimOrigin.z = v4;
  }
}

// File Line: 2903
// RVA: 0x3DCE60
void __fastcall UFG::FollowCameraComponent::UpdateLocalWorld(UFG::FollowCameraComponent *this, float dt)
{
  UFG::FollowCameraComponent *v2; // rdi
  UFG::qVector4 v3; // xmm2
  UFG::CharacterSubjectComponent::SrcTransform mSrcPosition; // r8d
  UFG::SimComponent *m_pSimComponent; // rcx
  __int64 v6; // rax
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float x; // xmm9_4
  float v14; // xmm0_4
  float y; // xmm6_4
  float z; // xmm7_4
  float w; // xmm8_4
  float v18; // xmm4_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm9_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  float v28; // xmm8_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  UFG::CharacterSubjectComponent *v33; // rcx
  float LockedElevation; // xmm0_4
  float v35; // xmm1_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-89h] BYREF
  UFG::qVector4 pos; // [rsp+60h] [rbp-49h] BYREF
  UFG::qMatrix44 d; // [rsp+70h] [rbp-39h] BYREF

  v2 = this;
  if ( this->mTarget.m_pSimComponent )
  {
    UFG::CharacterSubjectComponent::GetTransformTypeOrientation(
      (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
      &this->mTargetWorld,
      this->mBlendedParams.mSrcOrientation);
    mSrcPosition = v2->mBlendedParams.mSrcPosition;
    if ( (unsigned int)(mSrcPosition - 8) > 2 )
    {
      if ( v2->mBlend <= 0.0 )
        v2->mEnableCharacterSpaceSmoothing = 0;
    }
    else
    {
      v2->mEnableCharacterSpaceSmoothing = 1;
    }
    if ( UFG::FollowCameraComponent::bCharacterSpaceBoneSmoothing && v2->mEnableCharacterSpaceSmoothing )
    {
      UFG::CharacterSubjectComponent::GetTransformTypePosition(
        (UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent,
        &pos,
        mSrcPosition,
        1);
      m_pSimComponent = v2->mTarget.m_pSimComponent;
      m = UFG::qMatrix44::msIdentity;
      v6 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
      v7 = *(float *)(v6 + 56);
      v8 = *(float *)(v6 + 60);
      v9 = *(float *)(v6 + 48);
      m.v3.y = *(float *)(v6 + 52);
      m.v3.z = v7;
      m.v3.x = v9;
      m.v3.w = v8;
      UFG::qInverseAffine(&d, &m);
      v10 = (float)((float)((float)(d.v1.x * pos.y) + (float)(d.v0.x * pos.x)) + (float)(d.v2.x * pos.z))
          + (float)(d.v3.x * pos.w);
      v11 = (float)((float)((float)(d.v1.y * pos.y) + (float)(d.v0.y * pos.x)) + (float)(d.v2.y * pos.z))
          + (float)(d.v3.y * pos.w);
      v12 = (float)((float)((float)(d.v1.z * pos.y) + (float)(d.v0.z * pos.x)) + (float)(d.v2.z * pos.z))
          + (float)(d.v3.z * pos.w);
      UFG::qApproach(
        &v2->mCharacterSpacePos.x,
        v10,
        COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->mCharacterSpacePos.x - v10) & _xmm)
      * UFG::FollowCameraComponent::rCharacterSpaceSmoothingRate,
        dt);
      UFG::qApproach(
        &v2->mCharacterSpacePos.y,
        v11,
        COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->mCharacterSpacePos.y - v11) & _xmm)
      * UFG::FollowCameraComponent::rCharacterSpaceSmoothingRate,
        dt);
      UFG::qApproach(
        &v2->mCharacterSpacePos.z,
        v12,
        COERCE_FLOAT(COERCE_UNSIGNED_INT(v2->mCharacterSpacePos.z - v12) & _xmm)
      * UFG::FollowCameraComponent::rCharacterSpaceSmoothingRate,
        dt);
      x = m.v0.x;
      v14 = m.v1.x;
      v2->mCharacterSpacePos.w = 1.0;
      y = v2->mCharacterSpacePos.y;
      z = v2->mCharacterSpacePos.z;
      w = v2->mCharacterSpacePos.w;
      v18 = m.v0.y * v2->mCharacterSpacePos.x;
      v19 = m.v0.z * v2->mCharacterSpacePos.x;
      v20 = m.v0.w * v2->mCharacterSpacePos.x;
      v21 = (float)((float)((float)(x * v2->mCharacterSpacePos.x) + (float)(v14 * y)) + (float)(m.v2.x * z))
          + (float)(w * m.v3.x);
      v22 = m.v2.y * z;
      v23 = m.v1.y * y;
      v2->mTargetWorld.v3.x = v21;
      v24 = (float)(v18 + v23) + v22;
      v25 = m.v2.z * z;
      v26 = v19 + (float)(m.v1.z * y);
      v2->mTargetWorld.v3.y = v24 + (float)(w * m.v3.y);
      v27 = w;
      v28 = w * m.v3.w;
      v29 = v26 + v25;
      v30 = m.v2.w * z;
      v31 = v29 + (float)(v27 * m.v3.z);
      v32 = m.v1.w * y;
      v2->mTargetWorld.v3.z = v31;
      v2->mTargetWorld.v3.w = (float)((float)(v20 + v32) + v30) + v28;
    }
    else
    {
      UFG::CharacterSubjectComponent::GetTransformTypePosition(
        (UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent,
        &v2->mTargetWorld.v3,
        mSrcPosition,
        1);
    }
    v33 = (UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent;
    if ( v33->bElevationLock )
    {
      LockedElevation = UFG::CharacterSubjectComponent::GetLockedElevation(v33, v2->mBlendedParams.mSrcPosition);
      v35 = v2->mTargetWorld.v3.z;
      if ( v35 >= LockedElevation )
        v35 = LockedElevation;
      v2->mTargetWorld.v3.z = v35;
    }
    this = v2;
  }
  else
  {
    v3 = 0i64;
    v3.x = (float)1;
    this->mTargetWorld.v0 = v3;
    this->mTargetWorld.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 81);
    this->mTargetWorld.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 69);
    this->mTargetWorld.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 21);
  }
  UFG::FollowCameraComponent::UpdateAimOrigin(this);
}

// File Line: 2986
// RVA: 0x3C5170
void __fastcall UFG::FollowCameraComponent::GunRecoil(
        UFG::FollowCameraComponent *this,
        float scaleKickup,
        float scaleKickback,
        float scaleSpeed)
{
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *m_pPointer; // rdx
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm6_4
  float v14; // xmm0_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm9_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm9_4
  float y; // xmm1_4
  float z; // xmm2_4
  int v24; // xmm8_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm8_4
  float v28; // xmm1_4
  float v29; // xmm0_4

  if ( this->mTarget.m_pSimComponent
    && (m_pSimObject = (UFG::SimObjectCVBase *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(m_pSimObject);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      m_pSimObject,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                      m_pSimObject,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  if ( ComponentOfTypeHK )
    m_pPointer = ComponentOfTypeHK->m_pEquippedSOWPC.m_pPointer;
  else
    m_pPointer = 0i64;
  if ( UFG::tbRecoilUseTweakables || !m_pPointer )
  {
    v11 = FLOAT_3_1415927;
    v12 = FLOAT_0_0055555557;
    v13 = (float)(UFG::trRecoilKickupMin * 3.1415927) * 0.0055555557;
    if ( UFG::tbRecoilUseTweakables )
      goto LABEL_20;
  }
  else
  {
    v11 = FLOAT_3_1415927;
    v12 = FLOAT_0_0055555557;
    v13 = (float)(*(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                             + HIDWORD(m_pPointer[2].m_pSimObject))
                           + 416i64)
                * 3.1415927)
        * 0.0055555557;
  }
  if ( !m_pPointer )
  {
LABEL_20:
    v14 = (float)(UFG::trRecoilKickupMax * v11) * v12;
    if ( UFG::tbRecoilUseTweakables )
      goto LABEL_23;
    goto LABEL_21;
  }
  v14 = (float)(*(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                           + HIDWORD(m_pPointer[2].m_pSimObject))
                         + 420i64)
              * v11)
      * v12;
LABEL_21:
  if ( m_pPointer )
  {
    v15 = (float)(*(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                             + HIDWORD(m_pPointer[2].m_pSimObject))
                           + 424i64)
                * v11)
        * v12;
    goto LABEL_24;
  }
LABEL_23:
  v15 = (float)(UFG::trRecoilKickupOffset * v11) * v12;
  if ( UFG::tbRecoilUseTweakables )
  {
LABEL_26:
    v16 = UFG::trRecoilKickback;
    goto LABEL_27;
  }
LABEL_24:
  if ( !m_pPointer )
    goto LABEL_26;
  v16 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                   + HIDWORD(m_pPointer[2].m_pSimObject))
                 + 436i64);
LABEL_27:
  if ( UFG::tbRecoilUseTweakables || !m_pPointer )
    v17 = UFG::trRecoilKickbackSpeed;
  else
    v17 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                     + HIDWORD(m_pPointer[2].m_pSimObject))
                   + 440i64);
  if ( v14 >= v13 )
    v13 = UFG::qRandom(v14 - v13, (unsigned int *)&UFG::qDefaultSeed) + v13;
  v18 = v13 * scaleKickup;
  v19 = v15 * scaleKickup;
  v20 = (float)(v16 * 0.001) * scaleKickback;
  v21 = v17 * scaleSpeed;
  if ( (this->mFreeAiming || this->mSoftLocked) && (unsigned int)(this->mContext - 5) <= 1 )
  {
    v20 = v20 * UFG::trRecoilZoomScale;
    v18 = v18 * UFG::trRecoilZoomScale;
    v19 = v19 * UFG::trRecoilZoomScale;
  }
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mRecoilEye.p1.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.p1.y = y;
  this->mRecoilEye.p1.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  v24 = LODWORD(v20) ^ _xmm[0];
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  this->mRecoilAngle = v18;
  this->mRecoilAngleDesired = v18 + v19;
  v25 = *(float *)&v24 * this->mCamera.mTransformation.v2.x;
  v26 = *(float *)&v24 * this->mCamera.mTransformation.v2.y;
  v27 = *(float *)&v24 * this->mCamera.mTransformation.v2.z;
  this->mRecoilEye.p0.x = v25;
  this->mRecoilEye.p0.y = v26;
  this->mRecoilEye.p0.z = v27;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  v28 = COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * this->mCamera.mTransformation.v2.x;
  v29 = COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * this->mCamera.mTransformation.v2.y;
  this->mRecoilEye.v0.z = COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * this->mCamera.mTransformation.v2.z;
  this->mRecoilEye.v0.x = v28;
  this->mRecoilEye.v0.y = v29;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
}

// File Line: 3030
// RVA: 0x3C5F40
bool __fastcall UFG::FollowCameraComponent::IsMotionTowardsPlayer(UFG::FollowCameraComponent *this)
{
  return this->mType != eFOLLOW_CAMERA_TYPE_AIM
      && COERCE_FLOAT(LODWORD(this->mBlendedParams.mTweakLookOffset.y) & _xmm) > 0.000099999997;
}

// File Line: 3040
// RVA: 0x3C38E0
float __fastcall UFG::FollowCameraComponent::GetMotionCorrection(UFG::FollowCameraComponent *this)
{
  if ( (_S11_3 & 1) == 0 )
  {
    _S11_3 |= 1u;
    UFG::qSymbol::create_from_string(&contextSymbol, "Cameras-FollowCameraSprintWGun");
    atexit(UFG::FollowCameraComponent::GetMotionCorrection_::_2_::_dynamic_atexit_destructor_for__contextSymbol__);
  }
  if ( this->mType || UFG::FollowCameraComponent::mContextParameterSymbols[this->mContext].mUID != contextSymbol.mUID )
    return 0.0;
  else
    return correction;
}

// File Line: 3054
// RVA: 0x3C43D0
void __fastcall UFG::FollowCameraComponent::GotoAngle(
        UFG::FollowCameraComponent *this,
        float angle,
        float rate,
        float patience,
        bool worldSpace)
{
  this->mGotoAngle = angle;
  this->mGotoAngleRate = rate;
  this->mGotoAngleElaspedTime = 0.0;
  this->mGotoAngleLocalSpace = !worldSpace;
  this->mGotoAnglePatience = patience;
}

// File Line: 3064
// RVA: 0x3C4980
void __fastcall UFG::FollowCameraComponent::GotoAngleCollisionQueue(UFG::FollowCameraComponent *this, float wallDist)
{
  this->mGotoAngleCollisionQueuedWallDist = wallDist;
  this->mGotoAngleCollisionQueued = 1;
}

// File Line: 3071
// RVA: 0x3C4410
void __fastcall UFG::FollowCameraComponent::GotoAngleCollision(
        UFG::FollowCameraComponent *this,
        float wallDist,
        UFG::qVector3 *eye,
        UFG::qVector3 *look,
        UFG::qVector3 *up)
{
  bool mInCollision; // dl
  UFG::qVector3 *p_mCollisionContactPosition; // rcx
  UFG::qVector3 *p_mCollisionSurfaceNormal; // rax
  float x; // xmm11_4
  __m128 y_low; // xmm12
  float z; // xmm13_4
  __m128 v14; // xmm2
  float y; // xmm9_4
  float v16; // xmm8_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm6_4
  float v20; // xmm10_4
  __m128 x_low; // xmm7
  float v22; // xmm15_4
  __m128 v23; // xmm4
  float v24; // xmm5_4
  float v25; // xmm6_4
  __m128 v26; // xmm2
  float v27; // xmm0_4
  float v28; // xmm5_4
  float v29; // xmm6_4
  char v30; // al
  char v31; // r14
  char v32; // al
  float v33; // xmm7_4
  float v34; // xmm6_4
  UFG::qVector3 *p_rayEnd; // rax
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm9_4
  float v42; // xmm11_4
  UFG::qVector3 rayEnd; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qVector3 v44; // [rsp+30h] [rbp-D0h] BYREF
  float v45; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 rayStart; // [rsp+48h] [rbp-B8h] BYREF
  UFG::RayCastData data; // [rsp+60h] [rbp-A0h] BYREF
  UFG::RayCastData v48; // [rsp+140h] [rbp+40h] BYREF
  float v49; // [rsp+2F0h] [rbp+1F0h]

  mInCollision = this->mInCollision;
  p_mCollisionContactPosition = &UFG::qVector3::msZero;
  p_mCollisionSurfaceNormal = &this->mCollisionSurfaceNormal;
  if ( !mInCollision )
    p_mCollisionSurfaceNormal = &UFG::qVector3::msZero;
  x = p_mCollisionSurfaceNormal->x;
  y_low = (__m128)LODWORD(p_mCollisionSurfaceNormal->y);
  z = p_mCollisionSurfaceNormal->z;
  v14 = y_low;
  v14.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(z * z);
  if ( _mm_sqrt_ps(v14).m128_f32[0] >= 0.001 )
  {
    if ( mInCollision )
      p_mCollisionContactPosition = &this->mCollisionContactPosition;
    y = look->y;
    v16 = look->z;
    v17 = up->z;
    v18 = (float)((float)(COERCE_FLOAT(y_low.m128_i32[0] ^ _xmm[0]) * (float)(p_mCollisionContactPosition->y - y))
                + (float)(COERCE_FLOAT(LODWORD(x) ^ _xmm[0]) * (float)(p_mCollisionContactPosition->x - look->x)))
        + (float)(COERCE_FLOAT(LODWORD(z) ^ _xmm[0]) * (float)(p_mCollisionContactPosition->z - v16));
    v19 = up->y;
    v20 = look->x + (float)(COERCE_FLOAT(LODWORD(x) ^ _xmm[0]) * v18);
    x_low = (__m128)LODWORD(up->x);
    v45 = (float)(z * wallDist) + (float)(v16 + (float)(COERCE_FLOAT(LODWORD(z) ^ _xmm[0]) * v18));
    rayStart.z = v45;
    v49 = (float)(y_low.m128_f32[0] * wallDist) + (float)(y + (float)(COERCE_FLOAT(y_low.m128_i32[0] ^ _xmm[0]) * v18));
    rayStart.y = v49;
    v22 = (float)(x * wallDist) + v20;
    rayStart.x = v22;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v19 * y_low.m128_f32[0]) + (float)(x_low.m128_f32[0] * x)) + (float)(v17 * z)) & _xmm) <= 0.99984771 )
    {
      v23 = x_low;
      v24 = (float)(v17 * y_low.m128_f32[0]) - (float)(v19 * z);
      data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      data.mInput.m_filterInfo = 0;
      v23.m128_f32[0] = (float)(x_low.m128_f32[0] * z) - (float)(v17 * x);
      v25 = (float)(v19 * x) - (float)(x_low.m128_f32[0] * y_low.m128_f32[0]);
      v26 = v23;
      data.mInput.m_userData = 0i64;
      data.mOutput.m_hitFraction = 1.0;
      data.mOutput.m_extraInfo = -1;
      v26.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v24 * v24)) + (float)(v25 * v25);
      data.mOutput.m_shapeKeyIndex = 0;
      data.mOutput.m_shapeKeys[0] = -1;
      data.mOutput.m_rootCollidable = 0i64;
      v27 = _mm_sqrt_ps(v26).m128_f32[0];
      data.mDebugName = "FollowCameraComponent";
      data.mCollisionModelName.mUID = -1;
      v28 = v24 * (float)(UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius / v27);
      v23.m128_f32[0] = v23.m128_f32[0] * (float)(UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius / v27);
      v29 = v25 * (float)(UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius / v27);
      rayEnd.x = v28 + v22;
      rayEnd.y = v23.m128_f32[0] + v49;
      v44.x = v22 - v28;
      v44.z = v45 - v29;
      rayEnd.z = v29 + v45;
      v44.y = v49 - v23.m128_f32[0];
      UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x12u);
      v30 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      v48.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      v48.mInput.m_filterInfo = 0;
      v48.mInput.m_userData = 0i64;
      v48.mOutput.m_hitFraction = 1.0;
      v48.mOutput.m_extraInfo = -1;
      v31 = v30;
      v48.mOutput.m_shapeKeyIndex = 0;
      v48.mOutput.m_shapeKeys[0] = -1;
      v48.mOutput.m_rootCollidable = 0i64;
      v48.mDebugName = "FollowCameraComponent";
      v48.mCollisionModelName.mUID = -1;
      UFG::RayCastData::Init(&v48, &rayStart, &v44, 0x12u);
      v32 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v48);
      if ( v31 )
      {
        if ( v32 )
          return;
      }
      else if ( !v32 )
      {
        v39 = look->y;
        v40 = look->z;
        v41 = rayEnd.y - v39;
        v42 = v44.y - v39;
        v33 = UFG::FollowCameraComponent::rGotoAngleCollisionPatience;
        v34 = UFG::FollowCameraComponent::rGotoAngleCollisionRate;
        if ( (float)((float)((float)((float)(eye->y - v39) * (float)(rayEnd.y - v39))
                           + (float)((float)(eye->x - look->x) * (float)(rayEnd.x - look->x)))
                   + (float)((float)(eye->z - v40) * (float)(rayEnd.z - v40))) <= (float)((float)((float)((float)(eye->y - v39) * (float)(v44.y - v39))
                                                                                                + (float)((float)(eye->x - look->x) * (float)(v44.x - look->x)))
                                                                                        + (float)((float)(eye->z - v40)
                                                                                                * (float)(v44.z - v40))) )
        {
          v36 = v44.x - look->x;
          v37 = v42;
        }
        else
        {
          v36 = rayEnd.x - look->x;
          v37 = v41;
        }
LABEL_12:
        v38 = atan2f(v37, v36);
        this->mGotoAngleRate = v34;
        this->mGotoAnglePatience = v33;
        this->mGotoAngleLocalSpace = 0;
        this->mGotoAngleElaspedTime = 0.0;
        this->mGotoAngle = v38;
        return;
      }
      v33 = UFG::FollowCameraComponent::rGotoAngleCollisionPatience;
      v34 = UFG::FollowCameraComponent::rGotoAngleCollisionRate;
      p_rayEnd = &v44;
      if ( !v31 )
        p_rayEnd = &rayEnd;
      v36 = p_rayEnd->x - look->x;
      v37 = p_rayEnd->y - look->y;
      goto LABEL_12;
    }
  }
}

// File Line: 3132
// RVA: 0x3C4D90
void __fastcall UFG::FollowCameraComponent::GotoRise(
        UFG::FollowCameraComponent *this,
        float rise,
        float rate,
        float patience)
{
  this->mGotoRise = rise;
  this->mGotoRiseRate = rate;
  this->mGotoRisePatience = patience;
  this->mGotoRiseElaspedTime = 0.0;
}

// File Line: 3141
// RVA: 0x3C4D60
void __fastcall UFG::FollowCameraComponent::GotoRadius(
        UFG::FollowCameraComponent *this,
        float radius,
        float rate,
        float patience)
{
  this->mGotoRadius = radius;
  this->mGotoRadiusRate = rate;
  this->mGotoRadiusPatience = patience;
  this->mGotoRadiusElaspedTime = 0.0;
}

// File Line: 3150
// RVA: 0x3C4B80
void __fastcall UFG::FollowCameraComponent::GotoAngleSnap(
        UFG::FollowCameraComponent *this,
        float radians,
        bool worldSpace)
{
  UFG::AimingPlayerComponent *v3; // rdi
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::AimingPlayerComponent *ComponentOfTypeHK; // rax
  float v10; // xmm7_4
  UFG::SimComponent *v11; // rbx
  float v12; // xmm6_4
  float v13; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  UFG::qVector3 vDirection; // [rsp+20h] [rbp-48h] BYREF

  v3 = 0i64;
  this->mGotoAngleRate = 10000.0;
  this->mGotoAnglePatience = 0.1;
  this->mGotoAngleElaspedTime = 0.0;
  this->mGotoAngle = radians;
  this->mMouseBoomSet = 0;
  this->mGotoAngleLocalSpace = !worldSpace;
  m_pSimComponent = this->mTarget.m_pSimComponent;
  if ( m_pSimComponent )
  {
    m_pSimObject = (UFG::SimObjectCharacter *)m_pSimComponent->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(m_pSimObject);
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pSimObject,
                                                            UFG::AimingPlayerComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pSimObject,
                                                            UFG::AimingPlayerComponent::_TypeUID);
      }
      v3 = ComponentOfTypeHK;
    }
  }
  if ( v3 )
  {
    if ( worldSpace )
    {
      v10 = radians + 3.1415927;
    }
    else
    {
      v11 = this->mTarget.m_pSimComponent;
      v12 = *(float *)((__int64 (__fastcall *)(UFG::SimComponent *))v11->vfptr[16].__vecDelDtor)(v11);
      v13 = *(float *)(((__int64 (__fastcall *)(UFG::SimComponent *))v11->vfptr[16].__vecDelDtor)(v11) + 4);
      v10 = atan2f(v13, v12) + radians;
    }
    for ( ; v10 > 3.1415927; v10 = v10 + -6.2831855 )
      ;
    for ( ; v10 < -3.1415927; v10 = v10 + 6.2831855 )
      ;
    vDirection.x = cosf(v10);
    vDirection.z = 0.0;
    vDirection.y = sinf(v10);
    UFG::AimingPlayerComponent::SetFreeAimIntention(v3, &vDirection);
    ((void (__fastcall *)(UFG::UpdateInterface *))v3->UFG::AimingBaseComponent::UFG::UpdateInterface::vfptr->Update)(&v3->UFG::UpdateInterface);
  }
  vfptr = this->vfptr;
  this->mSnapNext = 1;
  ((void (__fastcall *)(UFG::FollowCameraComponent *))vfptr[15].__vecDelDtor)(this);
}

// File Line: 3174
// RVA: 0x3C4DC0
void __fastcall UFG::FollowCameraComponent::GotoRiseSnap(UFG::FollowCameraComponent *this, float rise)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax

  vfptr = this->vfptr;
  this->mGotoRise = rise;
  this->mMouseBoomSet = 0;
  this->mGotoRiseRate = 10000.0;
  this->mGotoRisePatience = 0.1;
  this->mGotoRiseElaspedTime = 0.0;
  this->mSnapNext = 1;
  ((void (*)(void))vfptr[15].__vecDelDtor)();
}

// File Line: 3186
// RVA: 0x3D90A0
void __fastcall UFG::FollowCameraComponent::UpdateControllers(UFG::FollowCameraComponent *this, float dt)
{
  Render::DebugDrawContext *Context; // rsi
  float v4; // xmm8_4
  float v5; // xmm6_4
  float v6; // xmm10_4
  float v7; // xmm13_4
  float x; // xmm14_4
  __int128 y_low; // xmm15
  float z; // xmm3_4
  float v11; // xmm7_4
  float v12; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  __m128 x_low; // xmm10
  float v17; // xmm3_4
  __m128 v18; // xmm2
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm1_4
  __m128 v23; // xmm1
  float v24; // xmm3_4
  __m128 v25; // xmm1
  UFG::qVector3 *p_centre; // rax
  float v27; // xmm7_4
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rbx
  UFG::SimComponent *m_pPointer; // r12
  float y; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  UFG::RebindingComponentHandle<UFG::CameraSubject,0> *p_mEnemyTarget; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rax
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::AimingPlayerComponent *ComponentOfTypeHK; // r13
  UFG::SimObjectCVBase *v42; // rcx
  __int16 v43; // dx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfType; // r14
  bool v45; // al
  bool v46; // al
  bool v47; // al
  UFG::SimObjectGame *v48; // rax
  __int16 v49; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool v51; // zf
  UFG::SimObject *v52; // rax
  __int64 v53; // rcx
  float v54; // xmm15_4
  int v55; // xmm10_4
  UFG::SimComponent *m_pSimComponent; // rax
  char v57; // al
  __int64 v58; // rbx
  UFG::InputActionData *v59; // rax
  bool v60; // al
  float v61; // xmm7_4
  __int64 mContext; // rax
  float mTweakRadiusMin; // xmm1_4
  float mTweakRadiusMax; // xmm2_4
  float mTweakOrbitSpeed; // xmm0_4
  UFG::InputActionData *v66; // rax
  float v67; // xmm12_4
  UFG::InputActionData *v68; // rax
  float v69; // xmm6_4
  char v70; // al
  UFG::allocator::free_link *v71; // rax
  UFG::Event *v72; // rdx
  unsigned int mUID; // ecx
  UFG::allocator::free_link *v74; // rax
  UFG::SimObjectGame *v75; // rbx
  UFG::TargetingMap *m_pTargetingMap; // rcx
  UFG::TargetingSimObject *m_pTargets; // rdx
  __int64 v78; // rax
  bool mFreeAiming; // r8
  UFG::CameraSubject *v80; // rax
  __int16 v81; // cx
  double v82; // xmm0_8
  float v83; // xmm6_4
  __int64 v84; // rax
  float v85; // xmm6_4
  float v86; // xmm0_4
  Render::DebugDrawContext *v87; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v88; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v89; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v90; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v91; // rax
  __int64 v92; // r10
  __int64 v93; // rax
  bool v94; // r9
  float *p_x; // rax
  float v96; // xmm7_4
  float v97; // xmm10_4
  float v98; // xmm11_4
  __m128 v99; // xmm2
  unsigned int v100; // xmm6_4
  __int64 v101; // rax
  bool v102; // r8
  __int64 v103; // rax
  bool v104; // al
  UFG::qSymbol *v105; // rax
  float mAimDeadZoneRadius; // xmm3_4
  float mAimDeadZoneTimer; // xmm0_4
  float v108; // xmm1_4
  float v109; // xmm10_4
  float v110; // xmm11_4
  float v111; // xmm12_4
  float v112; // xmm0_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  __m128 v115; // xmm5
  float v116; // xmm4_4
  float v117; // xmm2_4
  float v118; // xmm4_4
  float v119; // xmm6_4
  float v120; // xmm1_4
  float v121; // xmm4_4
  float v122; // xmm5_4
  float v123; // xmm1_4
  float v124; // xmm7_4
  float v125; // xmm6_4
  float v126; // xmm10_4
  float v127; // xmm1_4
  float v128; // xmm2_4
  float v129; // xmm1_4
  float v130; // xmm2_4
  float v131; // xmm1_4
  float v132; // xmm2_4
  float v133; // xmm1_4
  float v134; // xmm2_4
  UFG::qSymbol *ContextOverride; // rax
  char m_TypeUID; // cl
  bool v137; // al
  int v138; // edx
  float v139; // xmm6_4
  float v140; // xmm1_4
  float v141; // xmm2_4
  float v142; // xmm0_4
  float v143; // xmm1_4
  float v144; // xmm0_4
  float v145; // xmm1_4
  float v146; // xmm3_4
  float v147; // xmm1_4
  float v148; // xmm0_4
  float v149; // xmm13_4
  char v150; // r12
  bool v151; // r14
  __int64 v152; // r13
  UFG::Controller *v153; // rax
  UFG::Controller *v154; // rsi
  bool v155; // bl
  UFG::UIScreen *Screen; // rsi
  UFG::InputActionData *v157; // rax
  float mAxisPositionX; // xmm11_4
  UFG::GameStatTracker *v159; // rax
  float v160; // xmm0_4
  float v161; // xmm11_4
  UFG::InputActionData *v162; // rax
  float mAxisPositionY; // xmm12_4
  UFG::GameStatTracker *v164; // rax
  float v165; // xmm0_4
  float v166; // xmm12_4
  float *p_mMouseBucketX; // rsi
  float *p_mMouseBucketY; // rbx
  float v169; // xmm0_4
  float mMouseBucketX; // xmm7_4
  float v171; // xmm7_4
  float v172; // xmm10_4
  float v173; // xmm10_4
  UFG::GameStatTracker *v174; // rax
  float Stat; // xmm6_4
  UFG::GameStatTracker *v176; // rax
  float v177; // xmm0_4
  float v178; // xmm7_4
  float v179; // xmm10_4
  Render::DebugDrawContext *v180; // r13
  UFG::InputActionData *v181; // rax
  UFG::GameStatTracker *v182; // rax
  float v183; // xmm7_4
  UFG::InputActionData *v184; // rax
  float v185; // xmm0_4
  float v186; // xmm7_4
  UFG::GameStatTracker *v187; // rax
  float v188; // xmm0_4
  UFG::InputActionData *v189; // rax
  float v190; // xmm6_4
  float v191; // xmm6_4
  float v192; // xmm11_4
  float v193; // xmm10_4
  float v194; // xmm11_4
  float v195; // xmm7_4
  UFG::GameStatTracker *v196; // rax
  float v197; // xmm6_4
  UFG::GameStatTracker *v198; // rax
  float v199; // xmm0_4
  float v200; // xmm13_4
  float v201; // xmm12_4
  float v202; // xmm11_4
  float v203; // xmm10_4
  float v204; // xmm7_4
  float v205; // xmm6_4
  UFG::GameStatTracker *v206; // rax
  bool v207; // al
  float v208; // xmm3_4
  float v209; // xmm4_4
  float v210; // xmm5_4
  __m128 v211; // xmm2
  float v212; // xmm0_4
  float v213; // xmm1_4
  float v214; // xmm6_4
  float v215; // xmm6_4
  float v216; // xmm0_4
  float v217; // xmm0_4
  float mTweakFovMax; // xmm1_4
  float v219; // xmm1_4
  float v220; // xmm2_4
  float v221; // xmm1_4
  float v222; // xmm2_4
  float v223; // xmm7_4
  float v224; // xmm0_4
  float v225; // xmm0_4
  float v226; // xmm6_4
  __int64 v227; // rax
  bool v228; // si
  bool v229; // al
  float v230; // xmm1_4
  float v231; // xmm0_4
  float v232; // xmm1_4
  float v233; // xmm0_4
  float v234; // xmm5_4
  float v235; // xmm4_4
  float v236; // xmm3_4
  float v237; // xmm2_4
  float v238; // xmm6_4
  float v239; // xmm10_4
  float v240; // xmm10_4
  float v241; // xmm5_4
  float v242; // xmm5_4
  float v243; // xmm4_4
  float v244; // xmm4_4
  float v245; // xmm1_4
  float v246; // xmm1_4
  float v247; // xmm0_4
  float v248; // xmm6_4
  float v249; // xmm2_4
  float v250; // xmm3_4
  float v251; // xmm7_4
  float v252; // xmm0_4
  float p1; // xmm11_4
  float v254; // xmm11_4
  bool v255; // bl
  bool mHorizCompUseDirection; // cl
  UFG::InputActionData *v257; // rdx
  float v258; // xmm2_4
  float *v259; // rax
  float v260; // xmm2_4
  __m128 v261; // xmm3
  float v262; // xmm1_4
  float v263; // xmm6_4
  float v264; // xmm6_4
  float mHorizCompSpeedMin; // xmm10_4
  float mHorizCompSpeedMax; // xmm7_4
  float v267; // xmm0_4
  float mHorizCompOffsetScale; // xmm0_4
  UFG::qVector3 centre; // [rsp+40h] [rbp-80h] BYREF
  char v270; // [rsp+50h] [rbp-70h]
  UFG::qVector3 v271; // [rsp+58h] [rbp-68h] BYREF
  UFG::qVector3 position; // [rsp+68h] [rbp-58h] BYREF
  int v273; // [rsp+78h] [rbp-48h]
  float v274; // [rsp+7Ch] [rbp-44h]
  float constrainYaw[2]; // [rsp+140h] [rbp+80h] BYREF
  float dta; // [rsp+148h] [rbp+88h]
  UFG::qSymbol result; // [rsp+150h] [rbp+90h] BYREF
  char v278; // [rsp+158h] [rbp+98h]

  *(_QWORD *)&centre.x = -2i64;
  if ( !this->mControllersEnabled || !this->mTarget.m_pSimComponent )
    return;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  *(_QWORD *)&position.x = Context;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  LODWORD(v7) = LODWORD(this->mBlendedParams.mTweakCamThru.y) & _xmm;
  x = this->mLook.p1.x;
  y_low = LODWORD(this->mLook.p1.y);
  constrainYaw[0] = this->mLook.p1.z;
  z = constrainYaw[0];
  v11 = (float)((float)((float)(this->mTargetWorld.v1.x + this->mTargetWorld.v0.x) * 0.0)
              + (float)(this->mBlendedParams.mTweakCamThru.z * this->mTargetWorld.v2.x))
      + this->mTargetWorld.v3.x;
  v12 = (float)((float)((float)(this->mTargetWorld.v1.y + this->mTargetWorld.v0.y) * 0.0)
              + (float)(this->mBlendedParams.mTweakCamThru.z * this->mTargetWorld.v2.y))
      + this->mTargetWorld.v3.y;
  v13 = (float)((float)((float)(this->mTargetWorld.v1.z + this->mTargetWorld.v0.z) * 0.0)
              + (float)(this->mBlendedParams.mTweakCamThru.z * this->mTargetWorld.v2.z))
      + this->mTargetWorld.v3.z;
  if ( (float)((float)((float)((float)(*(float *)&y_low - v12) * (float)(*(float *)&y_low - v12))
                     + (float)((float)(x - v11) * (float)(x - v11)))
             + (float)((float)(constrainYaw[0] - v13) * (float)(constrainYaw[0] - v13))) <= (float)(v7 * v7) )
  {
    v27 = 0.0;
  }
  else
  {
    x_low = (__m128)LODWORD(this->mControllerForward.x);
    v14 = (float)(this->mControllerForward.y * 0.0) - (float)(this->mControllerForward.x * 0.0);
    v15 = this->mControllerForward.z * 0.0;
    x_low.m128_f32[0] = x_low.m128_f32[0] - v15;
    v17 = v15 - this->mControllerForward.y;
    v18 = x_low;
    v18.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v17 * v17)) + (float)(v14 * v14);
    if ( v18.m128_f32[0] == 0.0 )
      v19 = 0.0;
    else
      v19 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
    v20 = (float)(v19 * v14) * v7;
    v21 = (float)(v19 * x_low.m128_f32[0]) * v7;
    v22 = (float)(v19 * v17) * v7;
    centre.x = v11 - v22;
    centre.y = v12 - v21;
    centre.z = v13 - v20;
    v271.x = v11 + v22;
    v271.y = v21 + v12;
    v271.z = v20 + v13;
    v23 = (__m128)y_low;
    v23.m128_f32[0] = (float)((float)((float)(*(float *)&y_low - centre.y) * (float)(*(float *)&y_low - centre.y))
                            + (float)((float)(x - centre.x) * (float)(x - centre.x)))
                    + (float)((float)(constrainYaw[0] - centre.z) * (float)(constrainYaw[0] - centre.z));
    v24 = _mm_sqrt_ps(v23).m128_f32[0];
    v25 = (__m128)y_low;
    v25.m128_f32[0] = (float)((float)((float)(*(float *)&y_low - v271.y) * (float)(*(float *)&y_low - v271.y))
                            + (float)((float)(x - v271.x) * (float)(x - v271.x)))
                    + (float)((float)(constrainYaw[0] - v271.z) * (float)(constrainYaw[0] - v271.z));
    p_centre = &v271;
    if ( v24 <= _mm_sqrt_ps(v25).m128_f32[0] )
      p_centre = &centre;
    v27 = p_centre->z - constrainYaw[0];
    v6 = p_centre->y - *(float *)&y_low;
    v5 = p_centre->x - x;
    x = p_centre->x;
    *(float *)&y_low = p_centre->y;
    z = p_centre->z;
  }
  p_mLook = &this->mLook;
  this->mLook.p1.x = x;
  LODWORD(this->mLook.p1.y) = y_low;
  this->mLook.p1.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  m_pPointer = 0i64;
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  y = UFG::qVector3::msZero.y;
  v31 = UFG::qVector3::msZero.z;
  this->mEye.v1.x = UFG::qVector3::msZero.x;
  this->mEye.v1.y = y;
  this->mEye.v1.z = v31;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  if ( this->mBlend > 0.0 )
  {
    v32 = this->mEye.p1.z;
    v33 = this->mEye.p1.y + v6;
    this->mEye.p1.x = this->mEye.p1.x + v5;
    this->mEye.p1.y = v33;
    this->mEye.p1.z = v32 + v27;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
    *(_QWORD *)&this->mEye.mParameter.x = 0i64;
    this->mEye.mParameter.z = 0.0;
  }
  if ( UFG::bCameraDebugText )
  {
    if ( UFG::CharacterSubjectComponent::IsAirborne((UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent) )
      Render::DebugDrawContext::DrawTextA(Context, 40, 252, &UFG::qColour::White, "Airborne");
    if ( UFG::CharacterSubjectComponent::IsOnGround((UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent) )
      Render::DebugDrawContext::DrawTextA(Context, 40, 252, &UFG::qColour::White, "On Ground");
    if ( BYTE1(this->mTarget.m_pSimComponent[10].m_TypeUID) )
      Render::DebugDrawContext::DrawTextA(Context, 40, 276, &UFG::qColour::White, "Falling Attack");
    if ( LOBYTE(this->mTarget.m_pSimComponent[9].m_BoundComponentHandles.mNode.mPrev) )
      Render::DebugDrawContext::DrawTextA(Context, 40, 264, &UFG::qColour::White, "Elevation Locked");
  }
  p_mEnemyTarget = &this->mEnemyTarget;
  if ( this->mEnemyTarget.m_pSimComponent )
  {
    mPrev = p_mEnemyTarget->mPrev;
    mNext = this->mEnemyTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mEnemyTarget.m_pSimComponent = 0i64;
LABEL_28:
    this->mEnemyTarget.m_pSimObject = 0i64;
    this->mEnemyTarget.mNext = &this->mEnemyTarget;
    p_mEnemyTarget->mPrev = p_mEnemyTarget;
    goto LABEL_29;
  }
  if ( this->mEnemyTarget.m_pSimObject )
  {
    v37 = p_mEnemyTarget->mPrev;
    if ( p_mEnemyTarget->mPrev != p_mEnemyTarget || this->mEnemyTarget.mNext != &this->mEnemyTarget )
    {
      v38 = this->mEnemyTarget.mNext;
      v37->mNext = v38;
      v38->mPrev = v37;
      goto LABEL_28;
    }
  }
LABEL_29:
  this->mEnemyTarget.m_Changed = 1;
  this->mEnemyTarget.m_TypeUID = UFG::CameraSubject::_TypeUID;
  v270 = 1;
  v273 = UFG::gActiveControllerNum;
  if ( this->mTarget.m_pSimComponent
    && (m_pSimObject = (UFG::SimObjectCharacter *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(m_pSimObject);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pSimObject,
                                                          UFG::AimingPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::AimingPlayerComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  if ( this->mTarget.m_pSimComponent
    && (v42 = (UFG::SimObjectCVBase *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
  {
    v43 = v42->m_Flags;
    if ( (v43 & 0x4000) != 0 || v43 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v42);
    }
    else if ( (v43 & 0x2000) != 0 || (v43 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v42,
                                                                    UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                    v42,
                                                                    UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
  if ( ComponentOfType )
    v45 = (unsigned int)(ComponentOfType->m_eFocusMode - 3) <= 1;
  else
    v45 = 0;
  this->mFreeAiming = v45;
  if ( ComponentOfType )
    v46 = ComponentOfType->m_eFocusMode == eFOCUS_MODE_LOCKED_SOFT;
  else
    v46 = 0;
  this->mSoftLocked = v46;
  if ( ComponentOfType )
    v47 = (unsigned int)(ComponentOfType->m_eFocusMode - 1) <= 1;
  else
    v47 = 0;
  this->mFocusLocked = v47;
  v48 = (UFG::SimObjectGame *)((__int64 (__fastcall *)(UFG::FollowCameraComponent *))this->vfptr[17].__vecDelDtor)(this);
  if ( v48 )
  {
    v49 = v48->m_Flags;
    if ( (v49 & 0x4000) != 0 )
    {
      m_pComponent = v48->m_Components.p[7].m_pComponent;
    }
    else if ( v49 >= 0 )
    {
      if ( (v49 & 0x2000) != 0 )
      {
        m_pComponent = v48->m_Components.p[6].m_pComponent;
      }
      else if ( (v49 & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v48, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(v48, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = v48->m_Components.p[7].m_pComponent;
    }
    *(_QWORD *)&v271.x = m_pComponent;
  }
  else
  {
    *(_QWORD *)&v271.x = 0i64;
  }
  if ( !ComponentOfType
    || (m_pPointer = ComponentOfType->m_pEquippedSOWPC.m_pPointer) == 0i64
    || (v51 = *(_DWORD *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                          + HIDWORD(m_pPointer[2].m_pSimObject))
                        + 100i64) == UFG::gNullQSymbolUC.mUID,
        LOBYTE(result.mUID) = 1,
        v51) )
  {
    LOBYTE(result.mUID) = 0;
  }
  v274 = 0.0;
  if ( ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[48].__vecDelDtor)(this->mTarget.m_pSimComponent) )
  {
    v52 = 0i64;
    if ( ComponentOfType )
    {
      v53 = (__int64)&ComponentOfType->m_pTargets[(unsigned __int8)ComponentOfType->m_pTargetingMap->m_Map.p[44]];
      v52 = *(UFG::SimObject **)(v53 + 40);
      if ( v52 && *(_BYTE *)(v53 + 49) )
        this->mPassThroughTimer2 = 1.0;
      else
        v52 = 0i64;
    }
    this->pSimObjectPassThru2 = v52;
  }
  if ( !UFG::CharacterSubjectComponent::IsAirborne((UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent)
    || (v51 = LOBYTE(this->mTarget.m_pSimComponent[9].m_BoundComponentHandles.mNode.mPrev) == 0,
        LOBYTE(constrainYaw[0]) = 0,
        !v51) )
  {
    LOBYTE(constrainYaw[0]) = 1;
  }
  v54 = FLOAT_N1_0;
  v55 = _xmm[0];
  if ( !this->mFocusLocked && !this->mFreeAiming
    || (m_pSimComponent = this->mTarget.m_pSimComponent, *(_DWORD *)(&m_pSimComponent[12].m_SimObjIndex + 1) != -1)
    && *(_DWORD *)(&m_pSimComponent[12].m_SimObjIndex + 1) != 1 )
  {
    v57 = 0;
    goto LABEL_92;
  }
  v57 = 1;
  if ( this->mFreeAiming )
  {
LABEL_92:
    v278 = 1;
    if ( !v57 )
    {
      v67 = dta;
      goto LABEL_221;
    }
    goto LABEL_93;
  }
  v278 = 0;
LABEL_93:
  if ( (unsigned int)(this->mContext - 5) > 1 )
  {
    v67 = dta;
  }
  else
  {
    v58 = v273;
    v59 = UFG::ActionDef_CamHoldBreath.mDataPerController[v273];
    v60 = v59 && v59->mActionTrue;
    UFG::GameCameraComponent::SetHoldingBreathInput(this, v60);
    v61 = 0.0;
    mContext = this->mContext;
    mTweakRadiusMin = this->mContextParameters[mContext].mTweakRadiusMin;
    mTweakRadiusMax = this->mContextParameters[mContext].mTweakRadiusMax;
    mTweakOrbitSpeed = this->mContextParameters[mContext].mTweakOrbitSpeed;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      mTweakOrbitSpeed = mTweakOrbitSpeed * UFG::FollowCameraComponent::rAimZoomWheelMultiplier;
    v66 = UFG::ActionDef_CamZoomIn.mDataPerController[v58];
    if ( v66 && v66->mActionTrue )
    {
      v67 = dta;
      LODWORD(v61) = COERCE_UNSIGNED_INT(mTweakOrbitSpeed * dta) ^ _xmm[0];
    }
    else
    {
      v68 = UFG::ActionDef_CamZoomOut.mDataPerController[v58];
      v67 = dta;
      if ( v68 && v68->mActionTrue )
        v61 = mTweakOrbitSpeed * dta;
    }
    v69 = (float)((float)(1.0 - this->mTransitionParamEye) * v61) + this->mFov.p1;
    v70 = 0;
    if ( v69 <= mTweakRadiusMin || v69 >= mTweakRadiusMax )
      v70 = 1;
    if ( v69 <= mTweakRadiusMin )
      v69 = mTweakRadiusMin;
    if ( v69 >= mTweakRadiusMax )
      v69 = mTweakRadiusMax;
    if ( v61 != 0.0 && !v70 )
    {
      v71 = UFG::qMalloc(0x38ui64, "ZoomCamEvent", 0i64);
      v72 = (UFG::Event *)v71;
      *(_QWORD *)&centre.x = v71;
      if ( v71 )
      {
        mUID = UFG::gEventCameraZooming.mUID;
        v74 = v71 + 1;
        v74->mNext = v74;
        v74[1].mNext = v74;
        v72->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
        v72->m_EventUID = mUID;
        v72->m_NamePTR = 0i64;
      }
      else
      {
        v72 = 0i64;
      }
      v72->mUserData0 = v61 >= 0.0;
      v72->mUserData1 = this->mContext != eFOLLOW_CONTEXT_AIM_SNIPER;
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v72);
    }
    this->mFov.p1 = v69;
    UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
    this->mFov.mParameter = 0.0;
  }
  v75 = 0i64;
  if ( ComponentOfType )
  {
    if ( ((m_pTargetingMap = ComponentOfType->m_pTargetingMap,
           m_pTargets = ComponentOfType->m_pTargets,
           v78 = (unsigned __int8)m_pTargetingMap->m_Map.p[50],
           (v75 = (UFG::SimObjectGame *)m_pTargets[v78].m_pTarget.m_pPointer) == 0i64)
       || !m_pTargets[v78].m_bLock)
      && (v75 = (UFG::SimObjectGame *)m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[23]].m_pTarget.m_pPointer) == 0i64
      || UFG::IsHostage(v75) )
    {
      v75 = (UFG::SimObjectGame *)ComponentOfType->m_pTargets[(unsigned __int8)ComponentOfType->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
    }
  }
  if ( ComponentOfTypeHK
    && ((mFreeAiming = this->mFreeAiming, (unsigned int)(this->mContext - 5) <= 1) && !mFreeAiming || mFreeAiming) )
  {
    v87 = *(Render::DebugDrawContext **)&position.x;
  }
  else
  {
    if ( v75 )
    {
      v81 = v75->m_Flags;
      if ( (v81 & 0x4000) != 0 )
      {
        v80 = (UFG::CameraSubject *)v75->m_Components.p[37].m_pComponent;
      }
      else if ( v81 >= 0 )
      {
        if ( (v81 & 0x2000) != 0 || (v81 & 0x1000) != 0 )
          v80 = (UFG::CameraSubject *)UFG::SimObjectGame::GetComponentOfTypeHK(v75, UFG::CameraSubject::_TypeUID);
        else
          v80 = (UFG::CameraSubject *)UFG::SimObject::GetComponentOfType(v75, UFG::CameraSubject::_TypeUID);
      }
      else
      {
        v80 = (UFG::CameraSubject *)v75->m_Components.p[31].m_pComponent;
      }
    }
    else
    {
      v80 = 0i64;
    }
    UFG::RebindingComponentHandle<UFG::CameraSubject,0>::Set(&this->mEnemyTarget, v80);
    if ( !this->mEnemyTarget.m_pSimComponent )
      goto LABEL_220;
    v82 = ((double (__fastcall *)(UFG::SimComponent *))this->mEnemyTarget.m_pSimComponent->vfptr[22].__vecDelDtor)(this->mEnemyTarget.m_pSimComponent);
    v83 = *(float *)&v82 * ratio_of_height;
    v84 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mEnemyTarget.m_pSimComponent->vfptr[27].__vecDelDtor)(this->mEnemyTarget.m_pSimComponent);
    v85 = v83 + *(float *)(v84 + 8);
    v86 = *(float *)(v84 + 4);
    v87 = *(Render::DebugDrawContext **)&position.x;
    if ( UFG::bCameraDebugDraw )
    {
      centre.x = *(float *)v84;
      centre.y = v86;
      centre.z = v85;
      Render::DebugDrawContext::DrawSphere(
        *(Render::DebugDrawContext **)&position.x,
        &centre,
        1.0,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
    }
    mFreeAiming = this->mFreeAiming;
    if ( !mFreeAiming && !this->mSoftLocked )
    {
      if ( this->mEnemyTarget.m_pSimComponent )
      {
        v88 = p_mEnemyTarget->mPrev;
        v89 = this->mEnemyTarget.mNext;
        v88->mNext = v89;
        v89->mPrev = v88;
        this->mEnemyTarget.m_pSimComponent = 0i64;
      }
      else
      {
        if ( !this->mEnemyTarget.m_pSimObject )
          goto LABEL_153;
        v90 = p_mEnemyTarget->mPrev;
        if ( p_mEnemyTarget->mPrev == p_mEnemyTarget && this->mEnemyTarget.mNext == &this->mEnemyTarget )
          goto LABEL_153;
        v91 = this->mEnemyTarget.mNext;
        v90->mNext = v91;
        v91->mPrev = v90;
      }
      this->mEnemyTarget.m_pSimObject = 0i64;
      this->mEnemyTarget.mNext = &this->mEnemyTarget;
      p_mEnemyTarget->mPrev = p_mEnemyTarget;
LABEL_153:
      this->mEnemyTarget.m_Changed = 1;
      this->mEnemyTarget.m_TypeUID = UFG::CameraSubject::_TypeUID;
LABEL_220:
      p_mLook = &this->mLook;
LABEL_221:
      ContextOverride = UFG::CharacterSubjectComponent::GetContextOverride(
                          (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
                          (UFG::qSymbol *)&centre,
                          0);
      if ( UFG::PropertySetManager::FindPropertySet(ContextOverride) )
      {
        UFG::FollowCameraComponent::SetContext(this, eFOLLOW_CONTEXT_OVERRIDE_TOW, 0);
      }
      else
      {
        m_TypeUID = this->mTarget.m_pSimComponent[10].m_TypeUID;
        v137 = !LOBYTE(result.mUID) && this->bAllowTargeted && this->mAutoFrameActive;
        v138 = m_TypeUID != 0;
        if ( LOBYTE(result.mUID) )
        {
          v138 = (m_TypeUID != 0) + 9;
        }
        else if ( v137 )
        {
          v138 = 8;
        }
        UFG::FollowCameraComponent::SetContext(this, (UFG::FollowCameraContext)v138, 0);
      }
      v139 = this->mVelocity.p0.z;
      if ( (LOBYTE(this->mTarget.m_pSimComponent[10].m_TypeUID)
         || UFG::CharacterSubjectComponent::IsWalking((UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent)
         || UFG::CharacterSubjectComponent::IsJogging((UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent))
        && !LOBYTE(this->mTarget.m_pSimComponent[9].m_BoundComponentHandles.mNode.mPrev) )
      {
        v140 = UFG::FollowCameraComponent::rEyeRiseFallVelocityMin;
        if ( v139 > UFG::FollowCameraComponent::rEyeRiseFallVelocityMin )
          v140 = v139;
        if ( v140 >= UFG::FollowCameraComponent::rEyeRiseFallVelocityMax )
          v140 = UFG::FollowCameraComponent::rEyeRiseFallVelocityMax;
        v141 = this->mEye.p1.y;
        if ( v139 <= 0.0 )
          v142 = UFG::FollowCameraComponent::rEyeFallFromVelocityRatio;
        else
          v142 = UFG::FollowCameraComponent::rEyeRiseFromVelocityRatio;
        v143 = this->mEye.p1.z + (float)((float)(v142 * v67) * v140);
        this->mEye.p1.x = this->mEye.p1.x;
        this->mEye.p1.y = v141;
        this->mEye.p1.z = v143;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
        this->mEye.mParameter.z = 0.0;
        *(_QWORD *)&this->mEye.mParameter.x = 0i64;
      }
      v144 = 0.0;
      if ( BYTE1(this->mTarget.m_pSimComponent[10].m_TypeUID) )
      {
        v144 = (float)((float)(v139 - -0.40000001) * 1.9999999) - 1.8;
        v145 = FLOAT_N1_8;
        if ( v144 > -1.8 )
        {
          if ( v144 >= -1.0 )
            v144 = FLOAT_N1_0;
          goto LABEL_254;
        }
      }
      else
      {
        if ( LOBYTE(constrainYaw[0]) )
        {
LABEL_254:
          v146 = this->mLook.p1.y;
          v147 = this->mLook.p1.z + v144;
          v148 = this->mTargetWorld.v3.z;
          if ( v148 <= v147 )
            v148 = v147;
          p_mLook->p1.x = this->mLook.p1.x;
          p_mLook->p1.y = v146;
          p_mLook->p1.z = v148;
          UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
          *(_QWORD *)&p_mLook->mParameter.x = 0i64;
          p_mLook->mParameter.z = 0.0;
          goto LABEL_257;
        }
        v144 = (float)((float)(v139 - -2.0) * 0.30000001) - 0.60000002;
        v145 = FLOAT_N0_60000002;
        if ( v144 > -0.60000002 )
        {
          if ( v144 >= 0.0 )
            v144 = 0.0;
          goto LABEL_254;
        }
      }
      v144 = v145;
      goto LABEL_254;
    }
  }
  v92 = *(_QWORD *)&v271.x;
  v94 = 0;
  if ( *(_QWORD *)&v271.x )
  {
    v93 = *(_QWORD *)(*(_QWORD *)&v271.x + 8 * ((__int64)(int)gActionRequest_CameraZoom.m_EnumValue >> 6) + 712);
    if ( _bittest64(&v93, gActionRequest_CameraZoom.m_EnumValue & 0x3F) )
      v94 = 1;
  }
  this->mSniperEnabled = v94;
  if ( mFreeAiming || (p_x = &ComponentOfTypeHK->m_vAimPosition.x, this->mSoftLocked) )
    p_x = &ComponentOfTypeHK->m_vAimIntentionTargetPosition.x;
  v96 = *p_x;
  v97 = p_x[1];
  v98 = p_x[2];
  v99 = (__m128)LODWORD(this->mTargetWorld.v3.y);
  v99.m128_f32[0] = (float)((float)((float)((float)(v99.m128_f32[0] - v97) * (float)(v99.m128_f32[0] - v97))
                                  + (float)((float)(this->mTargetWorld.v3.x - v96)
                                          * (float)(this->mTargetWorld.v3.x - v96)))
                          + (float)((float)(this->mTargetWorld.v3.z - v98) * (float)(this->mTargetWorld.v3.z - v98)))
                  + (float)((float)(this->mTargetWorld.v3.w - 1.0) * (float)(this->mTargetWorld.v3.w - 1.0));
  v100 = _mm_sqrt_ps(v99).m128_u32[0];
  v102 = 0;
  if ( v92 )
  {
    v101 = *(_QWORD *)(v92 + 8 * ((__int64)(int)gActionRequest_UseCover.m_EnumValue >> 6) + 712);
    if ( _bittest64(&v101, gActionRequest_UseCover.m_EnumValue & 0x3F) )
      v102 = 1;
  }
  v104 = 0;
  if ( v92 )
  {
    v103 = *(_QWORD *)(v92 + 8 * ((__int64)(int)gActionRequest_CoverPopout.m_EnumValue >> 6) + 712);
    if ( _bittest64(&v103, gActionRequest_CoverPopout.m_EnumValue & 0x3F) )
      v104 = 1;
  }
  if ( !v102 || v104 )
  {
    if ( m_pPointer )
      v274 = *(float *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                        + HIDWORD(m_pPointer[2].m_pSimObject))
                      + 412i64);
    else
      v274 = 0.0;
  }
  if ( !m_pPointer )
    goto LABEL_184;
  if ( *(_BYTE *)(*((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext
                  + HIDWORD(m_pPointer[2].m_pSimObject))
                + 119i64)
    && v94 )
  {
    UFG::FollowCameraComponent::SetContext(this, eFOLLOW_CONTEXT_AIM_SNIPER, 0);
    if ( UFG::bCameraDebugText )
      Render::DebugDrawContext::DrawTextA(v87, 40, 324, &UFG::qColour::White, "Sniper target distance %f", v100);
    goto LABEL_192;
  }
  if ( BYTE5(m_pPointer[3].m_SafePointerList.mNode.mPrev) && v94 )
  {
    UFG::FollowCameraComponent::SetContext(this, eFOLLOW_CONTEXT_AIM_PHONE, 0);
    if ( UFG::bCameraDebugText )
      Render::DebugDrawContext::DrawTextA(v87, 40, 324, &UFG::qColour::White, "Phone Camera target distance %f", v100);
  }
  else
  {
LABEL_184:
    v105 = UFG::CharacterSubjectComponent::GetContextOverride(
             (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
             &result,
             1);
    if ( UFG::PropertySetManager::FindPropertySet(v105) )
    {
      UFG::FollowCameraComponent::SetContext(this, eFOLLOW_CONTEXT_OVERRIDE_AIM, 0);
      if ( UFG::bCameraDebugText )
        Render::DebugDrawContext::DrawTextA(v87, 40, 324, &UFG::qColour::White, "Aiming Override %f", v100);
    }
    else if ( LOBYTE(constrainYaw[0]) )
    {
      UFG::FollowCameraComponent::SetContext(this, eFOLLOW_CONTEXT_AIM, 0);
      if ( UFG::bCameraDebugText )
        Render::DebugDrawContext::DrawTextA(v87, 40, 324, &UFG::qColour::White, "Aiming %f", v100);
    }
    else
    {
      UFG::FollowCameraComponent::SetContext(this, eFOLLOW_CONTEXT_AIM_AIRBORNE, 0);
      if ( UFG::bCameraDebugText )
        Render::DebugDrawContext::DrawTextA(v87, 40, 324, &UFG::qColour::White, "Aiming Airborne %f", v100);
    }
  }
LABEL_192:
  if ( this->mType == eFOLLOW_CAMERA_TYPE_AIM && this->mPreviousType != eFOLLOW_CAMERA_TYPE_AIM && this->mBlend > 0.0 )
  {
    centre.x = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.y = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.z = UFG::FollowCameraComponent::rAimTransitionDurIn;
    UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mAimEye, &centre);
    centre.x = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.y = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.z = UFG::FollowCameraComponent::rAimTransitionDurIn;
    UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mAimLook, &centre);
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      centre.x = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.y = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.z = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mAimEye, &centre);
      centre.x = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.y = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.z = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mAimLook, &centre);
    }
  }
  if ( !UFG::bAimDeadZone )
    goto LABEL_205;
  mAimDeadZoneRadius = this->mAimDeadZoneRadius;
  if ( mAimDeadZoneRadius < 0.0
    || (float)(mAimDeadZoneRadius * mAimDeadZoneRadius) < (float)((float)((float)((float)(v97
                                                                                        - this->mAimDeadZoneCentre.y)
                                                                                * (float)(v97
                                                                                        - this->mAimDeadZoneCentre.y))
                                                                        + (float)((float)(v96
                                                                                        - this->mAimDeadZoneCentre.x)
                                                                                * (float)(v96
                                                                                        - this->mAimDeadZoneCentre.x)))
                                                                + (float)((float)(v98 - this->mAimDeadZoneCentre.z)
                                                                        * (float)(v98 - this->mAimDeadZoneCentre.z))) )
  {
    this->mAimDeadZoneCentre.x = v96;
    this->mAimDeadZoneCentre.y = v97;
    this->mAimDeadZoneCentre.z = v98;
    this->mAimDeadZoneTimer = 0.0;
    v108 = FLOAT_0_0020000001;
  }
  else
  {
    mAimDeadZoneTimer = this->mAimDeadZoneTimer;
    if ( mAimDeadZoneTimer < 0.5 )
    {
      this->mAimDeadZoneTimer = mAimDeadZoneTimer + v67;
      goto LABEL_205;
    }
    v108 = FLOAT_0_1;
  }
  UFG::FollowCameraComponent::SetAimDeadZone(this, v108);
LABEL_205:
  v109 = ComponentOfTypeHK->m_vFreeAimOrigin.x;
  v110 = ComponentOfTypeHK->m_vFreeAimOrigin.y;
  v111 = ComponentOfTypeHK->m_vFreeAimOrigin.z;
  this->mAimEye.p1.x = v109;
  this->mAimEye.p1.y = v110;
  this->mAimEye.p1.z = v111;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
  *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
  this->mAimEye.mParameter.z = 0.0;
  this->mEye.p1.x = v109;
  this->mEye.p1.y = v110;
  this->mEye.p1.z = v111;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  if ( this->mFreeAiming || this->mSoftLocked )
  {
    v114 = ComponentOfTypeHK->m_vFreeAimIntention.z + ComponentOfTypeHK->m_vFreeAimOrigin.z;
    v113 = ComponentOfTypeHK->m_vFreeAimIntention.y + ComponentOfTypeHK->m_vFreeAimOrigin.y;
    v112 = ComponentOfTypeHK->m_vFreeAimOrigin.x + ComponentOfTypeHK->m_vFreeAimIntention.x;
  }
  else
  {
    v112 = ComponentOfTypeHK->m_vAimPosition.x;
    v113 = ComponentOfTypeHK->m_vAimPosition.y;
    v114 = ComponentOfTypeHK->m_vAimPosition.z;
  }
  centre.z = v114;
  centre.y = v113;
  centre.x = v112;
  v115 = (__m128)LODWORD(v113);
  v116 = v114;
  v117 = this->mBlendedParams.mTweakRadiusMax;
  if ( v117 >= 1.0 )
  {
    if ( v117 >= 10.0 )
      v117 = FLOAT_10_0;
  }
  else
  {
    v117 = *(float *)&FLOAT_1_0;
  }
  v118 = v116 - v111;
  v115.m128_f32[0] = v113 - v110;
  v119 = v112 - v109;
  if ( (float)((float)((float)(v115.m128_f32[0] * v115.m128_f32[0]) + (float)(v119 * v119)) + (float)(v118 * v118)) == 0.0 )
    v120 = 0.0;
  else
    v120 = 1.0 / _mm_sqrt_ps(v115).m128_f32[0];
  v121 = v118 * v120;
  v122 = v115.m128_f32[0] * v120;
  v123 = v120 * v119;
  v124 = (float)(v117 * v121) + v111;
  v125 = (float)(v117 * v122) + v110;
  v126 = v109 + (float)(v117 * v123);
  this->mAimLook.p1.x = v126;
  this->mAimLook.p1.y = v125;
  this->mAimLook.p1.z = v124;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
  *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
  this->mAimLook.mParameter.z = 0.0;
  this->mLook.p1.x = v126;
  this->mLook.p1.y = v125;
  this->mLook.p1.z = v124;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  v270 = 0;
  if ( !this->bAimUseEyeLook )
  {
    v127 = this->mAimEye.p1.y;
    v128 = this->mAimEye.p1.z;
    this->mAimEye.p0.x = this->mAimEye.p1.x;
    this->mAimEye.p0.y = v127;
    this->mAimEye.p0.z = v128;
    v129 = this->mAimEye.v1.y;
    v130 = this->mAimEye.v1.z;
    this->mAimEye.v0.x = this->mAimEye.v1.x;
    this->mAimEye.v0.y = v129;
    this->mAimEye.v0.z = v130;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
    *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
    this->mAimEye.mParameter.z = 0.0;
    v131 = this->mAimLook.p1.y;
    v132 = this->mAimLook.p1.z;
    this->mAimLook.p0.x = this->mAimLook.p1.x;
    this->mAimLook.p0.y = v131;
    this->mAimLook.p0.z = v132;
    v133 = this->mAimLook.v1.y;
    v134 = this->mAimLook.v1.z;
    this->mAimLook.v0.x = this->mAimLook.v1.x;
    this->mAimLook.v0.y = v133;
    this->mAimLook.v0.z = v134;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
    *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
    this->mAimLook.mParameter.z = 0.0;
  }
  this->bAimUseEyeLook = 1;
  v55 = _xmm[0];
LABEL_257:
  LOBYTE(constrainYaw[0]) = 0;
  v149 = dta;
  UFG::FollowCameraComponent::UpdateGotos(this, dta, (bool *)constrainYaw);
  v150 = 0;
  v151 = 0;
  if ( v278 )
  {
    v152 = v273;
    v153 = UFG::InputSystem::AcquireController(UFG::gInputSystem, v273);
    v154 = v153;
    if ( v153 && v153->m_IsKeyboardController )
    {
      v150 = 1;
      v155 = 0;
      if ( UFG::UI::InMinigame() )
        v155 = (v154->m_SubModes & 4) != 0;
      Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "DialogBox");
      if ( (!UFG::UI::InMinigame() || v155) && !Screen )
      {
        v157 = UFG::ActionDef_Mouse.mDataPerController[v152];
        if ( v157 )
          mAxisPositionX = v157->mAxisPositionX;
        else
          mAxisPositionX = 0.0;
        v159 = UFG::GameStatTracker::Instance();
        if ( UFG::GameStatTracker::GetStat(v159, XAxisInverted) )
          v160 = FLOAT_N1_0;
        else
          v160 = *(float *)&FLOAT_1_0;
        v161 = mAxisPositionX * v160;
        v162 = UFG::ActionDef_Mouse.mDataPerController[v152];
        if ( v162 )
          mAxisPositionY = v162->mAxisPositionY;
        else
          mAxisPositionY = 0.0;
        v164 = UFG::GameStatTracker::Instance();
        if ( UFG::GameStatTracker::GetStat(v164, YAxisInverted) )
          v165 = FLOAT_N1_0;
        else
          v165 = *(float *)&FLOAT_1_0;
        v166 = mAxisPositionY * v165;
        p_mMouseBucketX = &this->mMouseBucketX;
        this->mMouseBucketX = (float)(v161 * 0.033333335) + this->mMouseBucketX;
        p_mMouseBucketY = &this->mMouseBucketY;
        v169 = (float)(v166 * 0.033333335) + this->mMouseBucketY;
        this->mMouseBucketY = v169;
        mMouseBucketX = this->mMouseBucketX;
        if ( mMouseBucketX <= COERCE_FLOAT(LODWORD(UFG::FollowCameraComponent::mMouseBucketCapacityX) ^ v55) )
          LODWORD(mMouseBucketX) = LODWORD(UFG::FollowCameraComponent::mMouseBucketCapacityX) ^ v55;
        if ( mMouseBucketX >= UFG::FollowCameraComponent::mMouseBucketCapacityX )
          mMouseBucketX = UFG::FollowCameraComponent::mMouseBucketCapacityX;
        *p_mMouseBucketX = mMouseBucketX;
        if ( v169 <= COERCE_FLOAT(LODWORD(UFG::FollowCameraComponent::mMouseBucketCapacityY) ^ v55) )
          LODWORD(v169) = LODWORD(UFG::FollowCameraComponent::mMouseBucketCapacityY) ^ v55;
        if ( v169 >= UFG::FollowCameraComponent::mMouseBucketCapacityY )
          v169 = UFG::FollowCameraComponent::mMouseBucketCapacityY;
        *p_mMouseBucketY = v169;
        UFG::qApproach(&this->mMouseBucketX, 0.0, UFG::FollowCameraComponent::mMouseBucketBleedRateX * 30.0, v149);
        v171 = mMouseBucketX - *p_mMouseBucketX;
        v172 = *p_mMouseBucketY;
        UFG::qApproach(&this->mMouseBucketY, 0.0, UFG::FollowCameraComponent::mMouseBucketBleedRateY * 30.0, v149);
        v173 = v172 - *p_mMouseBucketY;
        v151 = v171 != 0.0 || v173 != 0.0;
        v174 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v174, CameraSpeedYaw);
        v176 = UFG::GameStatTracker::Instance();
        v177 = UFG::GameStatTracker::GetStat(v176, CameraSpeedPitch);
        v178 = v171
             * (float)((float)((float)(UFG::FollowCameraComponent::rMouseSpeedScaleHMax
                                     - UFG::FollowCameraComponent::rMouseSpeedScaleHMin)
                             * Stat)
                     + UFG::FollowCameraComponent::rMouseSpeedScaleHMin);
        v179 = v173
             * (float)((float)((float)(UFG::FollowCameraComponent::rMouseSpeedScaleVMax
                                     - UFG::FollowCameraComponent::rMouseSpeedScaleVMin)
                             * v177)
                     + UFG::FollowCameraComponent::rMouseSpeedScaleVMin);
        if ( UFG::GameCameraComponent::mNoRotationTimer > 0.0 )
        {
          v178 = 0.0;
          v179 = 0.0;
        }
        if ( UFG::bCameraDebugText )
        {
          v180 = *(Render::DebugDrawContext **)&position.x;
          Render::DebugDrawContext::DrawTextA(
            *(Render::DebugDrawContext **)&position.x,
            300,
            324,
            &UFG::qColour::White,
            "Dx: %f  Dy:%f  ",
            v161,
            v166);
          Render::DebugDrawContext::DrawTextA(
            v180,
            300,
            336,
            &UFG::qColour::White,
            "Mx: %f  My:%f  ",
            *p_mMouseBucketX,
            *p_mMouseBucketY);
          Render::DebugDrawContext::DrawTextA(
            v180,
            300,
            348,
            &UFG::qColour::White,
            "dnx: %f  dny:%f  dt: %f",
            v178,
            v179,
            v149);
        }
        UFG::FollowCameraComponent::Rotate(this, v179, COERCE_FLOAT(LODWORD(v178) ^ _xmm[0]));
      }
    }
    else
    {
      v181 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v152];
      if ( v181 && v181->mActionTrue )
      {
        v182 = UFG::GameStatTracker::Instance();
        if ( UFG::GameStatTracker::GetStat(v182, YAxisInverted) )
          v183 = FLOAT_N1_0;
        else
          v183 = *(float *)&FLOAT_1_0;
        v184 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v152];
        if ( v184 )
          v185 = v184->mAxisPositionY;
        else
          v185 = 0.0;
        v186 = v183 * v185;
        v187 = UFG::GameStatTracker::Instance();
        if ( UFG::GameStatTracker::GetStat(v187, XAxisInverted) )
          v188 = FLOAT_N1_0;
        else
          v188 = *(float *)&FLOAT_1_0;
        v189 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v152];
        if ( v189 )
          v190 = v189->mAxisPositionX;
        else
          v190 = 0.0;
        v191 = COERCE_FLOAT(LODWORD(v190) ^ v55) * v188;
        if ( v186 <= 0.0 )
        {
          if ( v186 >= 0.0 )
            v192 = 0.0;
          else
            v192 = FLOAT_N1_0;
        }
        else
        {
          v192 = *(float *)&FLOAT_1_0;
        }
        v193 = powf(COERCE_FLOAT(LODWORD(v186) & _xmm), 2.0) * v192;
        if ( v191 <= 0.0 )
        {
          if ( v191 >= 0.0 )
            v194 = 0.0;
          else
            v194 = FLOAT_N1_0;
        }
        else
        {
          v194 = *(float *)&FLOAT_1_0;
        }
        v195 = powf(COERCE_FLOAT(LODWORD(v191) & _xmm), 2.0) * v194;
        if ( UFG::GameCameraComponent::mNoRotationTimer > 0.0 )
        {
          v195 = 0.0;
          v193 = 0.0;
        }
        if ( (float)(COERCE_FLOAT(LODWORD(v193) & _xmm) + COERCE_FLOAT(LODWORD(v195) & _xmm)) > 0.001 )
        {
          v196 = UFG::GameStatTracker::Instance();
          v197 = (float)((float)((float)((float)(UFG::FollowCameraComponent::rOptionsFactorSpeedYawMax
                                               - UFG::FollowCameraComponent::rOptionsFactorSpeedYawMin)
                                       * UFG::GameStatTracker::GetStat(v196, CameraSpeedYaw))
                               + UFG::FollowCameraComponent::rOptionsFactorSpeedYawMin)
                       * this->mBlendedParams.mTweakOrbitSpeed)
               * (float)(v195 * v149);
          if ( LOBYTE(constrainYaw[0]) )
            v197 = 0.0;
          v198 = UFG::GameStatTracker::Instance();
          v199 = UFG::GameStatTracker::GetStat(v198, CameraSpeedPitch);
          UFG::FollowCameraComponent::Rotate(
            this,
            (float)((float)((float)((float)(UFG::FollowCameraComponent::rOptionsFactorSpeedPitchMax
                                          - UFG::FollowCameraComponent::rOptionsFactorSpeedPitchMin)
                                  * v199)
                          + UFG::FollowCameraComponent::rOptionsFactorSpeedPitchMin)
                  * this->mBlendedParams.mTweakOrbitSpeed)
          * (float)(v193 * v149),
            v197);
        }
      }
    }
  }
  if ( v270 )
  {
    v200 = this->mLook.p1.x;
    v201 = this->mLook.p1.y;
    v202 = this->mLook.p1.z;
    v203 = this->mEye.p1.z - v202;
    v204 = this->mEye.p1.y - v201;
    v205 = this->mEye.p1.x - v200;
    centre.x = v205;
    centre.y = v204;
    centre.z = v203;
    v206 = UFG::GameStatTracker::Instance();
    if ( UFG::GameStatTracker::GetStat(v206, CameraFreeLook) )
    {
      if ( !this->mMouseBoomSet || v151 )
      {
        this->mMouseBoom.x = v205;
        this->mMouseBoom.y = v204;
        this->mMouseBoom.z = v203;
        this->mMouseBoomSet = 1;
      }
      if ( v150 && this->mGotoRadiusPatience <= 0.0 && this->mGotoAnglePatience <= 0.0 && this->mGotoRisePatience <= 0.0 )
      {
        v205 = this->mMouseBoom.x;
        v204 = this->mMouseBoom.y;
        v203 = this->mMouseBoom.z;
        centre.x = v205;
        centre.y = v204;
        centre.z = v203;
      }
    }
    v207 = UFG::FollowCameraComponent::BoomClamp(this, &centre);
    v208 = centre.y;
    v209 = centre.x;
    v210 = centre.z;
    if ( (float)((float)((float)(v204 * centre.y) + (float)(v205 * centre.x)) + (float)(v203 * centre.z)) < 0.0 )
    {
      v209 = v205;
      v208 = v204;
      v210 = v203;
      v207 = 0;
    }
    if ( v150 || v207 )
    {
      this->mEye.p1.x = v200 + v209;
      this->mEye.p1.y = v201 + v208;
      this->mEye.p1.z = v202 + v210;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
      *(_QWORD *)&this->mEye.mParameter.x = 0i64;
      this->mEye.mParameter.z = 0.0;
    }
  }
  v211 = (__m128)LODWORD(this->mEye.p1.x);
  v212 = this->mEye.p1.z - this->mLook.p1.z;
  v213 = this->mEye.p1.y - this->mLook.p1.y;
  v211.m128_f32[0] = v211.m128_f32[0] - this->mLook.p1.x;
  LODWORD(this->mControllerForward.x) = v211.m128_i32[0];
  this->mControllerForward.y = v213;
  this->mControllerForward.z = v212;
  v211.m128_f32[0] = (float)((float)(v211.m128_f32[0] * v211.m128_f32[0]) + (float)(v213 * v213))
                   + (float)(this->mControllerForward.z * this->mControllerForward.z);
  v214 = _mm_sqrt_ps(v211).m128_f32[0];
  this->mControllerForward.x = (float)(1.0 / v214) * this->mControllerForward.x;
  this->mControllerForward.y = (float)(1.0 / v214) * this->mControllerForward.y;
  this->mControllerForward.z = (float)(1.0 / v214) * this->mControllerForward.z;
  if ( (unsigned int)(this->mContext - 5) > 1 )
  {
    v215 = v214 * 0.625;
    if ( v215 > 1.0 )
      v215 = *(float *)&FLOAT_1_0;
    v216 = tanf((float)((float)(this->mFov.p1 * 3.1415927) * 0.0055555557) * 0.5);
    v217 = (float)((float)(atan2f(v216 / v215, 1.0) * 2.0) * 180.0) * 0.31830987;
    mTweakFovMax = this->mBlendedParams.mTweakFovMax;
    if ( mTweakFovMax >= v217 )
      mTweakFovMax = v217;
    this->mFov.p1 = mTweakFovMax;
    UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
    this->mFov.mParameter = 0.0;
  }
  v219 = this->mBlendedParams.mTweakLookOffset.y;
  v220 = this->mBlendedParams.mTweakLookOffset.z;
  this->mOffsetLook.p1.x = this->mBlendedParams.mTweakLookOffset.x;
  this->mOffsetLook.p1.y = v219;
  this->mOffsetLook.p1.z = v220;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetLook);
  *(_QWORD *)&this->mOffsetLook.mParameter.x = 0i64;
  this->mOffsetLook.mParameter.z = 0.0;
  v221 = UFG::qVector3::msZero.y;
  v222 = UFG::qVector3::msZero.z;
  this->mOffsetEye.p1.x = UFG::qVector3::msZero.x;
  this->mOffsetEye.p1.y = v221;
  this->mOffsetEye.p1.z = v222;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mOffsetEye);
  *(_QWORD *)&this->mOffsetEye.mParameter.x = 0i64;
  this->mOffsetEye.mParameter.z = 0.0;
  v223 = (float)((float)(UFG::qVector3::msAxisZ.y * COERCE_FLOAT(LODWORD(this->mControllerForward.y) ^ _xmm[0]))
               + (float)(UFG::qVector3::msAxisZ.x * COERCE_FLOAT(LODWORD(this->mControllerForward.x) ^ _xmm[0])))
       + (float)(UFG::qVector3::msAxisZ.z * COERCE_FLOAT(LODWORD(this->mControllerForward.z) ^ _xmm[0]));
  if ( v223 <= -1.0 )
  {
    v224 = FLOAT_N1_0;
  }
  else
  {
    v224 = (float)((float)(UFG::qVector3::msAxisZ.y * COERCE_FLOAT(LODWORD(this->mControllerForward.y) ^ _xmm[0]))
                 + (float)(UFG::qVector3::msAxisZ.x * COERCE_FLOAT(LODWORD(this->mControllerForward.x) ^ _xmm[0])))
         + (float)(UFG::qVector3::msAxisZ.z * COERCE_FLOAT(LODWORD(this->mControllerForward.z) ^ _xmm[0]));
    if ( v223 >= 1.0 )
      v224 = *(float *)&FLOAT_1_0;
  }
  v225 = acosf(v224);
  v226 = v225;
  if ( UFG::bCameraDebugText )
    Render::DebugDrawContext::DrawTextA(
      *(Render::DebugDrawContext **)&position.x,
      40,
      106,
      &UFG::qColour::White,
      "Lookup Angle: %f\n",
      (float)((float)(v225 * 180.0) * 0.31830987));
  v228 = 0;
  if ( *(_QWORD *)&v271.x )
  {
    v227 = *(_QWORD *)(*(_QWORD *)&v271.x + 8 * ((__int64)(int)gActionRequest_UseCover.m_EnumValue >> 6) + 712);
    if ( _bittest64(&v227, gActionRequest_UseCover.m_EnumValue & 0x3F) )
      v228 = 1;
  }
  if ( (_S12_2 & 1) == 0 )
  {
    _S12_2 |= 1u;
    UFG::qSymbol::create_from_string(&contextSymbolSwim, "Cameras-FollowCameraSwim");
    atexit(UFG::FollowCameraComponent::UpdateControllers_::_236_::_dynamic_atexit_destructor_for__contextSymbolSwim__);
  }
  v229 = this->mType == eFOLLOW_CAMERA_TYPE_TOW
      && UFG::FollowCameraComponent::mContextParameterSymbols[this->mContext].mUID == contextSymbolSwim.mUID;
  if ( v223 <= 0.0 )
    v230 = UFG::FollowCameraComponent::rLookdownGlobalAngleStart;
  else
    v230 = UFG::FollowCameraComponent::rLookupGlobalAngleStart;
  if ( v228 )
  {
    if ( v223 <= 0.0 )
    {
      v230 = UFG::FollowCameraComponent::rLookdownCoverAngleStart;
      goto LABEL_374;
    }
    v230 = UFG::FollowCameraComponent::rLookupCoverAngleStart;
  }
  else if ( v229 )
  {
    if ( v223 <= 0.0 )
    {
      v230 = UFG::FollowCameraComponent::rLookdownSwimAngleStart;
      goto LABEL_374;
    }
    v230 = UFG::FollowCameraComponent::rLookupSwimAngleStart;
  }
  if ( v223 > 0.0 )
  {
    v231 = UFG::FollowCameraComponent::rLookupGlobalAngleEnd;
    goto LABEL_375;
  }
LABEL_374:
  v231 = UFG::FollowCameraComponent::rLookdownGlobalAngleEnd;
LABEL_375:
  if ( v228 )
  {
    if ( v223 <= 0.0 )
      v231 = UFG::FollowCameraComponent::rLookdownCoverAngleEnd;
    else
      v231 = UFG::FollowCameraComponent::rLookupCoverAngleEnd;
  }
  else if ( v229 )
  {
    if ( v223 <= 0.0 )
      v231 = UFG::FollowCameraComponent::rLookdownSwimAngleEnd;
    else
      v231 = UFG::FollowCameraComponent::rLookupSwimAngleEnd;
  }
  v232 = (float)(v230 * 3.1415927) * 0.0055555557;
  v233 = (float)(v231 * 3.1415927) * 0.0055555557;
  if ( v223 <= 0.0 )
    v234 = UFG::FollowCameraComponent::rLookdownGlobalLookHeightOffset;
  else
    v234 = UFG::FollowCameraComponent::rLookupGlobalLookHeightOffset;
  if ( v228 )
  {
    if ( v223 <= 0.0 )
    {
      v234 = UFG::FollowCameraComponent::rLookdownCoverLookHeightOffset;
      goto LABEL_396;
    }
    v234 = UFG::FollowCameraComponent::rLookupCoverLookHeightOffset;
  }
  else if ( v229 )
  {
    if ( v223 <= 0.0 )
    {
      v234 = UFG::FollowCameraComponent::rLookdownSwimLookHeightOffset;
      goto LABEL_396;
    }
    v234 = UFG::FollowCameraComponent::rLookupSwimLookHeightOffset;
  }
  if ( v223 > 0.0 )
  {
    v235 = UFG::FollowCameraComponent::rLookupGlobalEyeHeightOffset;
    goto LABEL_397;
  }
LABEL_396:
  v235 = UFG::FollowCameraComponent::rLookdownGlobalEyeHeightOffset;
LABEL_397:
  if ( v228 )
  {
    if ( v223 <= 0.0 )
    {
      v235 = UFG::FollowCameraComponent::rLookdownCoverEyeHeightOffset;
      goto LABEL_407;
    }
    v235 = UFG::FollowCameraComponent::rLookupCoverEyeHeightOffset;
  }
  else if ( v229 )
  {
    if ( v223 <= 0.0 )
    {
      v235 = UFG::FollowCameraComponent::rLookdownSwimEyeHeightOffset;
      goto LABEL_407;
    }
    v235 = UFG::FollowCameraComponent::rLookupSwimEyeHeightOffset;
  }
  if ( v223 > 0.0 )
  {
    v236 = UFG::FollowCameraComponent::rLookupGlobalLookForwardOffset;
    goto LABEL_408;
  }
LABEL_407:
  v236 = UFG::FollowCameraComponent::rLookdownGlobalLookForwardOffset;
LABEL_408:
  if ( v228 )
  {
    if ( v223 > 0.0 )
    {
      v236 = UFG::FollowCameraComponent::rLookupCoverLookForwardOffset;
      goto LABEL_416;
    }
    v236 = UFG::FollowCameraComponent::rLookdownCoverLookForwardOffset;
LABEL_418:
    v237 = UFG::FollowCameraComponent::rLookdownGlobalEyeForwardOffset;
    goto LABEL_419;
  }
  if ( v229 )
  {
    if ( v223 <= 0.0 )
    {
      v236 = UFG::FollowCameraComponent::rLookdownSwimLookForwardOffset;
      goto LABEL_418;
    }
    v236 = UFG::FollowCameraComponent::rLookupSwimLookForwardOffset;
  }
LABEL_416:
  if ( v223 <= 0.0 )
    goto LABEL_418;
  v237 = UFG::FollowCameraComponent::rLookupGlobalEyeForwardOffset;
LABEL_419:
  if ( v228 )
  {
    if ( v223 <= 0.0 )
      v237 = UFG::FollowCameraComponent::rLookdownCoverEyeForwardOffset;
    else
      v237 = UFG::FollowCameraComponent::rLookupCoverEyeForwardOffset;
  }
  else if ( v229 )
  {
    if ( v223 <= 0.0 )
      v237 = UFG::FollowCameraComponent::rLookdownSwimEyeForwardOffset;
    else
      v237 = UFG::FollowCameraComponent::rLookupSwimEyeForwardOffset;
  }
  v238 = (float)(v226 - v232) / (float)(v233 - v232);
  if ( v238 <= 0.0 )
  {
    v239 = 0.0;
  }
  else
  {
    v239 = v238;
    if ( v238 >= 1.0 )
      v239 = *(float *)&FLOAT_1_0;
  }
  v240 = v239 * v234;
  if ( v238 <= 0.0 )
  {
    v241 = 0.0;
  }
  else
  {
    v241 = v238;
    if ( v238 >= 1.0 )
      v241 = *(float *)&FLOAT_1_0;
  }
  v242 = v241 * v235;
  if ( v238 <= 0.0 )
  {
    v243 = 0.0;
  }
  else
  {
    v243 = v238;
    if ( v238 >= 1.0 )
      v243 = *(float *)&FLOAT_1_0;
  }
  v244 = v243 * v236;
  if ( v238 <= 0.0 )
  {
    v245 = 0.0;
  }
  else
  {
    v245 = v238;
    if ( v238 >= 1.0 )
      v245 = *(float *)&FLOAT_1_0;
  }
  v246 = v245 * v237;
  if ( v223 <= 0.0 )
    v247 = UFG::FollowCameraComponent::rLookdownGlobalFOVOffset;
  else
    v247 = UFG::FollowCameraComponent::rLookupGlobalFOVOffset;
  if ( v228 )
  {
    if ( v223 <= 0.0 )
      v247 = UFG::FollowCameraComponent::rLookdownCoverFOVOffset;
    else
      v247 = UFG::FollowCameraComponent::rLookupCoverFOVOffset;
  }
  else if ( v229 )
  {
    if ( v223 <= 0.0 )
      v247 = UFG::FollowCameraComponent::rLookdownSwimFOVOffset;
    else
      v247 = UFG::FollowCameraComponent::rLookupSwimFOVOffset;
  }
  if ( v238 <= 0.0 )
  {
    v238 = 0.0;
  }
  else if ( v238 >= 1.0 )
  {
    v238 = *(float *)&FLOAT_1_0;
  }
  v248 = v238 * v247;
  v249 = this->mOffsetLook.p1.x;
  position.x = v249;
  position.y = this->mOffsetLook.p1.y;
  v250 = this->mOffsetLook.p1.z;
  position.z = v250;
  v251 = this->mOffsetEye.p1.x;
  v271.x = v251;
  v271.y = this->mOffsetEye.p1.y;
  v252 = this->mOffsetEye.p1.z;
  v271.z = v252;
  p1 = this->mFov.p1;
  if ( this->mBlendedParams.mUseLookUpDown )
  {
    position.x = v249 + v244;
    position.z = v250 + v240;
    v271.x = v251 + v246;
    v271.z = v252 + v242;
  }
  v254 = p1 + (float)((float)(1.0 - this->mTransitionParamEye) * (float)(v248 + v274));
  UFG::HomerCubic<UFG::qVector3>::SetDesiredPosition(&this->mOffsetLook, &position);
  UFG::HomerCubic<UFG::qVector3>::SetDesiredPosition(&this->mOffsetEye, &v271);
  if ( (unsigned int)(this->mContext - 5) > 1 )
  {
    this->mFov.p1 = v254;
    UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
    this->mFov.mParameter = 0.0;
  }
  v255 = UFG::FollowCameraComponent::bHorizCompUseTweakables;
  mHorizCompUseDirection = UFG::FollowCameraComponent::bHorizCompUseDirection;
  if ( !UFG::FollowCameraComponent::bHorizCompUseTweakables )
    mHorizCompUseDirection = this->mBlendedParams.mHorizCompUseDirection;
  v257 = UFG::ActionDef_LeftThumbStick.mDataPerController[v273];
  if ( v257 )
    v258 = v257->mAxisPositionX;
  else
    v258 = 0.0;
  if ( mHorizCompUseDirection )
  {
    v259 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[15].__vecDelDtor)(this->mTarget.m_pSimComponent);
    v261 = (__m128)LODWORD(this->mLook.p0.y);
    v260 = this->mLook.p0.x - this->mEye.p0.x;
    v261.m128_f32[0] = v261.m128_f32[0] - this->mEye.p0.y;
    if ( (float)((float)(v261.m128_f32[0] * v261.m128_f32[0]) + (float)(v260 * v260)) == 0.0 )
      v262 = 0.0;
    else
      v262 = 1.0 / _mm_sqrt_ps(v261).m128_f32[0];
    v258 = (float)((float)((float)(v262 * v261.m128_f32[0]) * v259[1]) + (float)((float)(v262 * v260) * *v259))
         + (float)((float)(v262 * 0.0) * v259[2]);
    v255 = UFG::FollowCameraComponent::bHorizCompUseTweakables;
  }
  v263 = (float)(COERCE_FLOAT(LODWORD(v258) & _xmm) - UFG::FollowCameraComponent::rHorizCompInputDeadZone)
       / (float)(1.0 - UFG::FollowCameraComponent::rHorizCompInputDeadZone);
  if ( v263 <= 0.0 )
  {
    v263 = 0.0;
  }
  else if ( v263 >= 1.0 )
  {
    v263 = *(float *)&FLOAT_1_0;
  }
  if ( v258 <= 0.0 )
  {
    if ( v258 >= 0.0 )
      v54 = 0.0;
  }
  else
  {
    v54 = *(float *)&FLOAT_1_0;
  }
  v264 = (float)(v263 * v263) * v54;
  if ( v255 )
  {
    mHorizCompSpeedMin = UFG::FollowCameraComponent::rHorizCompSpeedMin;
    mHorizCompSpeedMax = UFG::FollowCameraComponent::rHorizCompSpeedMax;
  }
  else
  {
    mHorizCompSpeedMin = this->mBlendedParams.mHorizCompSpeedMin;
    mHorizCompSpeedMax = this->mBlendedParams.mHorizCompSpeedMax;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(mHorizCompSpeedMin - mHorizCompSpeedMax) & _xmm) > 0.00000011920929 )
  {
    v267 = (float)(UFG::qAverageWindow<float>::GetAverage(&this->mHorizCompTargetSpeedWindow) - mHorizCompSpeedMin)
         / (float)(mHorizCompSpeedMax - mHorizCompSpeedMin);
    if ( v267 > 0.0 )
    {
      v4 = v267;
      if ( v267 >= 1.0 )
        v4 = *(float *)&FLOAT_1_0;
    }
  }
  if ( v255 )
    mHorizCompOffsetScale = UFG::FollowCameraComponent::rHorizCompOffsetScale;
  else
    mHorizCompOffsetScale = this->mBlendedParams.mHorizCompOffsetScale;
  this->mHorizCompOffset.p1 = (float)(mHorizCompOffsetScale * v264) * v4;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mHorizCompOffset);
  this->mHorizCompOffset.mParameter = 0.0;
}260) * *v259))
         + (float)((float)(v262 * 0.0) * v259[2]);
    v255 = UFG::FollowCameraComponent::bHorizCompUseTweakables;
  }
  v263 = (float)(COERCE_FLOAT(LODWORD(v258) & _xmm) - UFG::FollowCameraComponent::rHorizCompInputDeadZone)
       / (float)(1.0 - UFG::FollowCameraComponent::rHorizCompInputDeadZone);
  if ( v263 <= 0.0 )
  {
    v263 = 0.0;
  }
  else if ( v263 >= 1.0 )
  {
    v263 = *(float *)&FLOAT_1_0;
  }
  if ( v258 <= 0.0 )
  {
    if ( v258 >= 0.0 )
      v54 = 0.0;
  }
  else
  {
    v54 = *(float *)&FLOAT_1_0;
  }
  v264 = (float)(v263 * v263) * v54;
  if ( v255 )
  {
    mHorizCompSpeedMin = UFG::FollowCameraComponent::rHorizCompSpeedMin;
    mHorizCompSpeedMax = UFG::FollowCameraComponent::rHorizCompSpeedMax;
  }
  else
  {
    mHorizCompSpeedMin = this->mBlendedParams.mHorizCompSpeedMin;
    mHorizCompSpeedMax = this->mBlendedParams.mHorizCompSpeedMax;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(mHorizCompSpeedMin - mHorizCompSpeedMax) & _xmm) > 0.00000011920929 )
  {
    v267 = (float)(UFG::qAverageWindow<float>::GetAverage(&this->mHorizCompTargetSpeedWindow) - mHorizCom

// File Line: 3965
// RVA: 0x3DC1B0
void __fastcall UFG::FollowCameraComponent::UpdateGotos(UFG::FollowCameraComponent *this, float dt, bool *constrainYaw)
{
  bool mSnapNext; // r12
  float *p_mGotoRise; // rbx
  float *p_mGotoRadiusPatience; // r14
  bool *p_mGotoAngleLocalSpace; // r13
  bool v9; // zf
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  __m128 y_low; // xmm3
  float v14; // xmm6_4
  __m128 v15; // xmm4
  float v16; // xmm1_4
  float i; // xmm0_4
  float v18; // xmm0_4
  float mGotoAngle; // xmm0_4
  float x; // xmm11_4
  float y; // xmm12_4
  float z; // xmm6_4
  __int64 v23; // rax
  float v24; // xmm0_4
  float v25; // xmm0_4
  int v26; // xmm15_4
  float v27; // xmm14_4
  float v28; // xmm15_4
  float v29; // xmm13_4
  float v30; // xmm6_4
  __m128 v31; // xmm11
  float v32; // xmm12_4
  __m128 v33; // xmm1
  float mGotoRadius; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  char v37; // al
  char *v38; // rsi
  char v39; // bl
  float v40; // xmm11_4
  float v41; // xmm13_4
  float v42; // xmm14_4
  float v43; // xmm1_4
  float v44; // xmm12_4
  __m128 v45; // xmm6
  float v46; // xmm3_4
  __m128 v47; // xmm4
  __m128 v48; // xmm2
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm14_4
  float mGotoAngleRate; // xmm6_4
  float v56; // xmm0_4
  float v57; // xmm6_4
  float v58; // xmm0_4
  float v59; // xmm12_4
  char v60; // al
  char v61; // r14
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfTypeHK; // rbx
  UFG::SimObjectCharacter *v65; // rcx
  __int16 v66; // dx
  UFG::AimingPlayerComponent *ComponentOfType; // rsi
  float j; // xmm6_4
  float v69; // xmm0_4
  float v70; // xmm6_4
  float v71; // xmm7_4
  float v72; // xmm0_4
  float v73; // xmm1_4
  float v74; // xmm14_4
  float v75; // xmm2_4
  float v76; // xmm14_4
  float v77; // xmm12_4
  float value; // [rsp+50h] [rbp-70h] BYREF
  bool farthestAngle; // [rsp+54h] [rbp-6Ch] BYREF
  float yawConstraintRate; // [rsp+58h] [rbp-68h] BYREF
  float angleB; // [rsp+5Ch] [rbp-64h] BYREF
  float v82; // [rsp+60h] [rbp-60h]
  float angle; // [rsp+64h] [rbp-5Ch] BYREF
  float v84; // [rsp+68h] [rbp-58h]
  float v85; // [rsp+6Ch] [rbp-54h]
  UFG::qVector3 vDirection; // [rsp+70h] [rbp-50h] BYREF
  bool angleAdditive; // [rsp+130h] [rbp+70h] BYREF
  float delta_sec; // [rsp+138h] [rbp+78h]
  float v89[2]; // [rsp+140h] [rbp+80h] BYREF
  bool useSecond; // [rsp+148h] [rbp+88h] BYREF

  angleAdditive = 0;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  mSnapNext = this->mSnapNext;
  p_mGotoRise = &this->mGotoRise;
  if ( UFG::CharacterSubjectComponent::GetAndClearGotoRise(
         (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
         &this->mGotoRise,
         &this->mGotoRiseRate,
         &this->mGotoRisePatience) )
  {
    this->mGotoRiseElaspedTime = 0.0;
    mSnapNext = 0;
  }
  p_mGotoRadiusPatience = &this->mGotoRadiusPatience;
  if ( UFG::CharacterSubjectComponent::GetAndClearGotoRadius(
         (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
         &this->mGotoRadius,
         &this->mGotoRadiusRate,
         &this->mGotoRadiusPatience) )
  {
    this->mGotoRadiusElaspedTime = 0.0;
    mSnapNext = 0;
  }
  p_mGotoAngleLocalSpace = &this->mGotoAngleLocalSpace;
  if ( UFG::CharacterSubjectComponent::GetAndClearGotoAngle(
         (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
         &angle,
         &this->mGotoAngleRate,
         &this->mGotoAnglePatience,
         &this->mGotoAngleLocalSpace,
         &useSecond,
         &angleB,
         &farthestAngle,
         &angleAdditive) )
  {
    v9 = !useSecond;
    v10 = angle;
    this->mGotoAngleElaspedTime = 0.0;
    this->mGotoAngle = v10;
    if ( !v9 )
      this->mGotoAngle = UFG::FollowCameraComponent::GetClosestAngle(
                           this,
                           v10,
                           angleB,
                           !*p_mGotoAngleLocalSpace,
                           farthestAngle);
    mSnapNext = 0;
  }
  if ( angleAdditive )
  {
    v11 = atan2f(
            COERCE_FLOAT(LODWORD(this->mTargetWorld.v0.y) ^ _xmm[0]),
            COERCE_FLOAT(LODWORD(this->mTargetWorld.v0.x) ^ _xmm[0]));
    y_low = (__m128)LODWORD(this->mEye.p0.y);
    v12 = this->mEye.p0.x - this->mLook.p0.x;
    y_low.m128_f32[0] = y_low.m128_f32[0] - this->mLook.p0.y;
    v14 = v11;
    v15 = y_low;
    v15.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v12 * v12))
                    + (float)((float)(this->mEye.p0.z - this->mLook.p0.z) * (float)(this->mEye.p0.z - this->mLook.p0.z));
    if ( v15.m128_f32[0] == 0.0 )
      v16 = 0.0;
    else
      v16 = 1.0 / _mm_sqrt_ps(v15).m128_f32[0];
    i = atan2f(y_low.m128_f32[0] * v16, v12 * v16);
    if ( *p_mGotoAngleLocalSpace )
    {
      for ( i = i - v14; i > 3.1415927; i = i + -6.2831855 )
        ;
      for ( ; i < -3.1415927; i = i + 6.2831855 )
        ;
    }
    v18 = i + this->mGotoAngle;
    this->mGotoAngle = v18;
    if ( v18 > 3.1415927 )
    {
      do
        v18 = v18 + -6.2831855;
      while ( v18 > 3.1415927 );
      this->mGotoAngle = v18;
    }
    mGotoAngle = this->mGotoAngle;
    if ( mGotoAngle < -3.1415927 )
    {
      do
        mGotoAngle = mGotoAngle + 6.2831855;
      while ( mGotoAngle < -3.1415927 );
      this->mGotoAngle = mGotoAngle;
    }
  }
  if ( this->mGotoRisePatience > 0.0 )
  {
    x = this->mEye.p1.x;
    y = this->mEye.p1.y;
    z = this->mEye.p1.z;
    value = z
          - *(float *)(((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent)
                     + 8);
    if ( mSnapNext )
      value = *p_mGotoRise;
    else
      UFG::qApproach(&value, *p_mGotoRise, this->mGotoRiseRate, dt);
    v23 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
    v24 = value + *(float *)(v23 + 8);
    this->mEye.p1.x = x;
    this->mEye.p1.y = y;
    this->mEye.p1.z = v24;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
    *(_QWORD *)&this->mEye.mParameter.x = 0i64;
    this->mEye.mParameter.z = 0.0;
    v25 = dt + this->mGotoRiseElaspedTime;
    this->mGotoRiseElaspedTime = v25;
    if ( mSnapNext || v25 > this->mGotoRisePatience )
      *(_QWORD *)&this->mGotoRiseElaspedTime = 0i64;
  }
  v26 = _xmm;
  if ( *p_mGotoRadiusPatience > 0.0 )
  {
    v31 = (__m128)LODWORD(this->mEye.p1.y);
    v27 = this->mLook.p1.x;
    v28 = this->mLook.p1.y;
    v29 = this->mLook.p1.z;
    v30 = this->mEye.p1.x - v27;
    v31.m128_f32[0] = v31.m128_f32[0] - v28;
    v32 = this->mEye.p1.z - v29;
    v33 = v31;
    v33.m128_f32[0] = (float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30);
    LODWORD(yawConstraintRate) = _mm_sqrt_ps(v33).m128_u32[0];
    value = yawConstraintRate;
    if ( mSnapNext )
    {
      mGotoRadius = this->mGotoRadius;
      value = mGotoRadius;
    }
    else
    {
      UFG::qApproach(&value, this->mGotoRadius, this->mGotoRadiusRate, delta_sec);
      mGotoRadius = value;
    }
    v35 = mGotoRadius / yawConstraintRate;
    this->mEye.p1.z = v29 + v32;
    this->mEye.p1.x = (float)(v30 * v35) + v27;
    this->mEye.p1.y = (float)(v31.m128_f32[0] * v35) + v28;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
    *(_QWORD *)&this->mEye.mParameter.x = 0i64;
    this->mEye.mParameter.z = 0.0;
    v26 = _xmm;
    v36 = delta_sec + this->mGotoRadiusElaspedTime;
    this->mGotoRadiusElaspedTime = v36;
    if ( mSnapNext
      || COERCE_FLOAT(COERCE_UNSIGNED_INT(value - this->mGotoRadius) & _xmm) < 0.059999999
      || v36 > *p_mGotoRadiusPatience )
    {
      this->mGotoRadiusElaspedTime = 0.0;
      *p_mGotoRadiusPatience = 0.0;
    }
  }
  value = 0.0;
  yawConstraintRate = 0.0;
  v37 = UFG::FollowCameraComponent::NeedConstrainYaw(this, &value, &yawConstraintRate);
  v38 = *(char **)v89;
  **(_BYTE **)v89 = v37;
  if ( this->mGotoAnglePatience > this->mGotoAngleElaspedTime )
    *v38 = 0;
  if ( this->mGotoAnglePatience > 0.0 || *v38 )
  {
    v39 = *v38;
    v40 = this->mGotoAngle;
    if ( *v38 )
      v40 = value;
    if ( *p_mGotoAngleLocalSpace || v39 )
      v40 = v40 + (float)(atan2f(this->mTargetWorld.v0.y, this->mTargetWorld.v0.x) + 3.1415927);
    v47 = (__m128)LODWORD(this->mEye.p0.y);
    v41 = this->mLook.p0.x;
    v42 = this->mLook.p0.y;
    v43 = this->mEye.p0.z - this->mLook.p0.z;
    v44 = this->mEye.p1.x;
    v45 = (__m128)LODWORD(this->mEye.p1.y);
    v46 = this->mEye.p0.x - v41;
    v47.m128_f32[0] = v47.m128_f32[0] - v42;
    value = this->mEye.p1.z;
    v48 = v47;
    v48.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v46 * v46)) + (float)(v43 * v43);
    v49 = 0.0;
    if ( v48.m128_f32[0] != 0.0 )
      v49 = 1.0 / _mm_sqrt_ps(v48).m128_f32[0];
    v50 = atan2f(v47.m128_f32[0] * v49, v46 * v49);
    v51 = this->mLook.p1.y;
    v52 = v50;
    v85 = this->mLook.p1.x;
    v82 = v51;
    v53 = this->mLook.p1.z;
    v45.m128_f32[0] = (float)((float)(v45.m128_f32[0] - v42) * (float)(v45.m128_f32[0] - v42))
                    + (float)((float)(v44 - v41) * (float)(v44 - v41));
    LODWORD(v54) = _mm_sqrt_ps(v45).m128_u32[0];
    v89[0] = v50;
    v84 = v53;
    value = value - v53;
    if ( v39 )
      mGotoAngleRate = yawConstraintRate;
    else
      mGotoAngleRate = this->mGotoAngleRate;
    if ( UFG::FollowCameraComponent::bGotoAngleProportionalRateEnabled && !v39 )
    {
      v56 = v40 - v50;
      if ( (float)(v40 - v52) > 3.1415927 )
      {
        do
          v56 = v56 + -6.2831855;
        while ( v56 > 3.1415927 );
      }
      for ( ; v56 < -3.1415927; v56 = v56 + 6.2831855 )
        ;
      v57 = mGotoAngleRate
          * (float)(COERCE_FLOAT(LODWORD(v56) & v26) * UFG::FollowCameraComponent::rGotoAngleProportionalRateFactor);
      v58 = this->mGotoAngleElaspedTime / UFG::FollowCameraComponent::rGotoAngleProportionalRateBlendInDur;
      if ( v58 <= 0.0 )
      {
        v58 = 0.0;
      }
      else if ( v58 >= 1.0 )
      {
        v58 = *(float *)&FLOAT_1_0;
      }
      mGotoAngleRate = v57 * (float)((float)(sinf((float)(v58 * 3.1415927) - 1.5707964) + 1.0) * 0.5);
      if ( mGotoAngleRate < UFG::FollowCameraComponent::rGotoAngleProportionalRateMin )
        mGotoAngleRate = UFG::FollowCameraComponent::rGotoAngleProportionalRateMin;
    }
    v59 = delta_sec;
    v60 = UFG::qApproachAngle(v89, v40, mGotoAngleRate, delta_sec);
    v61 = v60;
    if ( UFG::FollowCameraComponent::rGotoAngleEarlyExitTimeMin > this->mGotoAngleElaspedTime )
    {
      v61 = v60;
      if ( !*v38 )
        v61 = 0;
    }
    if ( mSnapNext )
    {
      v89[0] = v40;
      v61 = 1;
    }
    if ( this->mTarget.m_pSimComponent
      && (m_pSimObject = (UFG::SimObjectCVBase *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(m_pSimObject);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        m_pSimObject,
                                                                        UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                        m_pSimObject,
                                                                        UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfTypeHK = 0i64;
    }
    if ( this->mTarget.m_pSimComponent
      && (v65 = (UFG::SimObjectCharacter *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
    {
      v66 = v65->m_Flags;
      if ( (v66 & 0x4000) != 0 )
      {
        ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v65);
      }
      else if ( v66 < 0 || (v66 & 0x2000) != 0 || (v66 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v65,
                                                          UFG::AimingPlayerComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                          v65,
                                                          UFG::AimingPlayerComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = 0i64;
    }
    if ( ComponentOfType && ComponentOfTypeHK && !ComponentOfTypeHK->m_bIsAimingActive )
    {
      for ( j = v89[0] + 3.1415927; j > 3.1415927; j = j + -6.2831855 )
        ;
      for ( ; j < -3.1415927; j = j + 6.2831855 )
        ;
      vDirection.x = cosf(j);
      v69 = sinf(j);
      vDirection.z = 0.0;
      vDirection.y = v69;
      UFG::AimingPlayerComponent::SetFreeAimIntention(ComponentOfType, &vDirection);
    }
    v70 = v89[0];
    v71 = cosf(v89[0]);
    v72 = sinf(v70) * v54;
    v73 = v85 + (float)(v71 * v54);
    v74 = (float)(v54 * 0.0) + v84;
    v75 = v82 + v72;
    this->mEye.p1.x = v73;
    v76 = v74 + value;
    this->mEye.p1.y = v75;
    this->mEye.p1.z = v76;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
    *(_QWORD *)&this->mEye.mParameter.x = 0i64;
    this->mEye.mParameter.z = 0.0;
    v77 = v59 + this->mGotoAngleElaspedTime;
    this->mGotoAngleElaspedTime = v77;
    if ( v61 || v77 > this->mGotoAnglePatience )
    {
      this->mGotoAngleElaspedTime = 0.0;
      this->mGotoAnglePatience = 0.0;
    }
  }
}

// File Line: 4247
// RVA: 0x3C7340
char __fastcall UFG::FollowCameraComponent::NeedConstrainYaw(
        UFG::FollowCameraComponent *this,
        float *yawConstraintAngle,
        float *yawConstraintRate)
{
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  __m128 y_low; // xmm4
  __m128 v11; // xmm5
  float i; // xmm0_4
  bool mConstrainYaw; // al
  float mConstrainYawMin; // xmm8_4
  float mConstrainYawMax; // xmm7_4
  float j; // xmm2_4
  float k; // xmm1_4
  float mConstrainYawRate; // xmm0_4

  if ( !this->mBlendedParams.mYawRestrict && !this->mConstrainYaw )
    return 0;
  v7 = atan2f(
         COERCE_FLOAT(LODWORD(this->mTargetWorld.v0.y) ^ _xmm[0]),
         COERCE_FLOAT(LODWORD(this->mTargetWorld.v0.x) ^ _xmm[0]));
  y_low = (__m128)LODWORD(this->mEye.p0.y);
  v8 = 0.0;
  v9 = this->mEye.p0.x - this->mLook.p0.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->mLook.p0.y;
  v11 = y_low;
  v11.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v9 * v9))
                  + (float)((float)(this->mEye.p0.z - this->mLook.p0.z) * (float)(this->mEye.p0.z - this->mLook.p0.z));
  if ( v11.m128_f32[0] != 0.0 )
    v8 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  for ( i = atan2f(y_low.m128_f32[0] * v8, v9 * v8) - v7; i > 3.1415927; i = i + -6.2831855 )
    ;
  for ( ; i < -3.1415927; i = i + 6.2831855 )
    ;
  mConstrainYaw = this->mConstrainYaw;
  if ( mConstrainYaw )
    mConstrainYawMin = this->mConstrainYawMin;
  else
    mConstrainYawMin = (float)(this->mBlendedParams.mYawMin * 3.1415927) * 0.0055555557;
  if ( mConstrainYaw )
    mConstrainYawMax = this->mConstrainYawMax;
  else
    mConstrainYawMax = (float)(this->mBlendedParams.mYawMax * 3.1415927) * 0.0055555557;
  if ( i <= mConstrainYawMax && i >= mConstrainYawMin )
    return 0;
  for ( j = mConstrainYawMax - i; j > 3.1415927; j = j + -6.2831855 )
    ;
  for ( ; j < -3.1415927; j = j + 6.2831855 )
    ;
  for ( k = mConstrainYawMin - i; k > 3.1415927; k = k + -6.2831855 )
    ;
  for ( ; k < -3.1415927; k = k + 6.2831855 )
    ;
  if ( COERCE_FLOAT(LODWORD(k) & _xmm) >= COERCE_FLOAT(LODWORD(j) & _xmm) )
    *yawConstraintAngle = mConstrainYawMax;
  else
    *yawConstraintAngle = mConstrainYawMin;
  if ( this->mConstrainYaw )
    mConstrainYawRate = this->mConstrainYawRate;
  else
    mConstrainYawRate = (float)(this->mBlendedParams.mYawConstrainRate * 3.1415927) * 0.0055555557;
  *yawConstraintRate = mConstrainYawRate;
  return 1;
}

// File Line: 4283
// RVA: 0x3C29D0
float __fastcall UFG::FollowCameraComponent::GetClosestAngle(
        UFG::FollowCameraComponent *this,
        float angleA,
        float angleB,
        bool worldSpace,
        bool returnFarthestAngle)
{
  float v7; // xmm3_4
  __m128 y_low; // xmm4
  float v10; // xmm2_4
  __m128 v11; // xmm5
  float i; // xmm6_4
  float j; // xmm2_4
  float k; // xmm0_4
  float v15; // xmm3_4

  y_low = (__m128)LODWORD(this->mEye.p0.y);
  v7 = this->mEye.p0.x - this->mLook.p0.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->mLook.p0.y;
  v11 = y_low;
  v10 = 0.0;
  v11.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v7 * v7))
                  + (float)((float)(this->mEye.p0.z - this->mLook.p0.z) * (float)(this->mEye.p0.z - this->mLook.p0.z));
  if ( v11.m128_f32[0] != 0.0 )
    v10 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  i = atan2f(y_low.m128_f32[0] * v10, v7 * v10);
  if ( !worldSpace )
  {
    for ( i = i
            - atan2f(
                COERCE_FLOAT(LODWORD(this->mTargetWorld.v0.y) ^ _xmm[0]),
                COERCE_FLOAT(LODWORD(this->mTargetWorld.v0.x) ^ _xmm[0])); i > 3.1415927; i = i + -6.2831855 )
      ;
    for ( ; i < -3.1415927; i = i + 6.2831855 )
      ;
  }
  for ( j = angleA - i; j > 3.1415927; j = j + -6.2831855 )
    ;
  for ( ; j < -3.1415927; j = j + 6.2831855 )
    ;
  for ( k = angleB - i; k > 3.1415927; k = k + -6.2831855 )
    ;
  for ( ; k < -3.1415927; k = k + 6.2831855 )
    ;
  if ( returnFarthestAngle )
    v15 = angleB;
  else
    v15 = angleA;
  if ( COERCE_FLOAT(LODWORD(k) & _xmm) >= COERCE_FLOAT(LODWORD(j) & _xmm) )
    return v15;
  if ( returnFarthestAngle )
    return angleA;
  return angleB;
}

// File Line: 4309
// RVA: 0x3C0950
bool __fastcall UFG::FollowCameraComponent::BoomClamp(UFG::FollowCameraComponent *this, UFG::qVector3 *boom)
{
  float mTweakRadiusMin; // xmm6_4
  float v5; // xmm2_4
  float radius_down; // xmm7_4
  bool result; // al

  mTweakRadiusMin = this->mBlendedParams.mTweakRadiusMin;
  v5 = (float)((float)(1.0 - this->mMaxRadiusOverrideParam) * this->mBlendedParams.mTweakRadiusMax)
     + (float)(this->mMaxRadiusOverrideParam * this->mMaxRadiusOverride);
  if ( mTweakRadiusMin > v5 )
    mTweakRadiusMin = (float)((float)(1.0 - this->mMaxRadiusOverrideParam) * this->mBlendedParams.mTweakRadiusMax)
                    + (float)(this->mMaxRadiusOverrideParam * this->mMaxRadiusOverride);
  radius_down = mTweakRadiusMin * this->mOrbitSquish;
  result = UFG::FollowCameraComponent::BoomClamp(this, boom, v5, mTweakRadiusMin, radius_down, 0);
  if ( !result )
    return UFG::FollowCameraComponent::BoomClamp(this, boom, mTweakRadiusMin, mTweakRadiusMin, radius_down, 1);
  return result;
}

// File Line: 4325
// RVA: 0x3C0A00
_BOOL8 __fastcall UFG::FollowCameraComponent::BoomClamp(
        UFG::FollowCameraComponent *this,
        UFG::qVector3 *boom_in,
        float radius,
        float radius_up,
        float radius_down,
        bool keep_out)
{
  __int128 z_low; // xmm5
  __m128 x_low; // xmm10
  float y; // xmm11_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  float v16; // xmm3_4
  bool v17; // cf
  bool v18; // zf
  bool v19; // bl
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm0_4
  UFG::qVector3 *v23; // rax
  float z; // xmm1_4
  float v25; // xmm0_4
  UFG::qVector3 ray; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector3 boom; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-88h] BYREF

  z_low = LODWORD(boom_in->z);
  x_low = (__m128)LODWORD(boom_in->x);
  y = boom_in->y;
  boom.x = boom_in->x;
  boom.y = y;
  v11 = (float)(1.0 / radius) * radius_down;
  v12 = (float)(1.0 / radius) * radius_up;
  if ( *(float *)&z_low >= 0.0 )
    v13 = (float)(1.0 / radius) * radius_up;
  else
    v13 = (float)(1.0 / radius) * radius_down;
  *(float *)&z_low = *(float *)&z_low / v13;
  v14 = x_low;
  v14.m128_f32[0] = x_low.m128_f32[0] * x_low.m128_f32[0];
  v15 = (__m128)z_low;
  LODWORD(boom.z) = z_low;
  v15.m128_f32[0] = (float)(*(float *)&z_low * *(float *)&z_low)
                  + (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y));
  LODWORD(v16) = _mm_sqrt_ps(v15).m128_u32[0];
  if ( keep_out )
  {
    v17 = radius < v16;
    v18 = radius == v16;
  }
  else
  {
    v17 = v16 < radius;
    v18 = v16 == radius;
  }
  v19 = !v17 && !v18;
  if ( !v17 && !v18 )
  {
    if ( keep_out )
      v20 = *(float *)&FLOAT_1_0;
    else
      v20 = FLOAT_N1_0;
    v21 = (float)((float)((float)(1.0 - this->mRiseOverrideParam) * this->mBlendedParams.mTweakEyeRise)
                + (float)(this->mRiseOverrideParam * this->mRiseOverride))
        - *(float *)&z_low;
    if ( keep_out )
    {
      v14.m128_f32[0] = v14.m128_f32[0] + (float)(y * y);
      v22 = _mm_sqrt_ps(v14).m128_f32[0] * 0.5;
      if ( v21 <= COERCE_FLOAT(LODWORD(v22) ^ _xmm[0]) )
        LODWORD(v21) = LODWORD(v22) ^ _xmm[0];
      if ( v21 >= v22 )
        v21 = v22;
    }
    ray.z = v21;
    ray.x = x_low.m128_f32[0] * v20;
    ray.y = y * v20;
    v23 = UFG::FollowCameraComponent::BoomClamp(this, &result, &boom, radius, &ray);
    z = v23->z;
    v25 = v23->y;
    boom_in->x = v23->x;
    boom_in->y = v25;
    boom_in->z = z;
    if ( z >= 0.0 )
      v11 = v12;
    boom_in->z = v11 * z;
  }
  return v19;
}

// File Line: 4359
// RVA: 0x3C07C0
UFG::qVector3 *__fastcall UFG::FollowCameraComponent::BoomClamp(
        UFG::FollowCameraComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *boom,
        float radius,
        UFG::qVector3 *ray)
{
  float y; // xmm4_4
  __m128 x_low; // xmm2
  float z; // xmm5_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  float v10; // xmm7_4
  __m128 v11; // xmm11
  __m128 v12; // xmm6
  __m128 v13; // xmm12
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm3_4

  y = boom->y;
  x_low = (__m128)LODWORD(boom->x);
  z = boom->z;
  v8 = ray->y;
  v9 = ray->z;
  v11 = x_low;
  v12 = x_low;
  v10 = (float)((float)(ray->x * ray->x) + (float)(v8 * v8)) + (float)(v9 * v9);
  v11.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * ray->x) + (float)(y * v8)) + (float)(z * v9);
  v13 = v11;
  v12.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  v13.m128_f32[0] = (float)(v11.m128_f32[0] * v11.m128_f32[0])
                  - (float)((float)(v12.m128_f32[0] - (float)(radius * radius)) * v10);
  if ( v13.m128_f32[0] < 0.0 || v10 < 0.0000099999997 )
  {
    v19 = radius / _mm_sqrt_ps(v12).m128_f32[0];
    v16 = x_low.m128_f32[0] * v19;
    v17 = y * v19;
    v18 = z * v19;
  }
  else
  {
    if ( v12.m128_f32[0] > (float)(radius * radius) )
      v14 = FLOAT_N1_0;
    else
      v14 = *(float *)&FLOAT_1_0;
    v15 = (float)((float)(_mm_sqrt_ps(v13).m128_f32[0] * v14) - v11.m128_f32[0]) / v10;
    v16 = x_low.m128_f32[0] + (float)(ray->x * v15);
    v17 = y + (float)(v8 * v15);
    v18 = z + (float)(v9 * v15);
  }
  result->z = v18;
  result->y = v17;
  result->x = v16;
  return result;
}

// File Line: 4376
// RVA: 0x3C1CC0
void __fastcall UFG::FollowCameraComponent::DetermineMeleeAttackerPositions(UFG::FollowCameraComponent *this)
{
  UFG::NearbyCharacterManager *v2; // rbx
  UFG::qVector3 *v3; // rax
  UFG::SimObjectCharacter *LocalPlayer; // r12
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v5; // rdi
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v6; // r15
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *mPrev; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v8; // rsi
  UFG::TransformNodeComponent *MeshShape; // rax
  UFG::TransformNodeComponent *v10; // rbp
  float x; // xmm6_4
  float y; // xmm7_4
  float z; // xmm8_4
  float *v14; // rax
  UFG::SimComponent *CharacterOccupantComponent; // rax
  UFG::SimObjectCVBase *m_pSimObject; // rbx
  UFG::GameStatTracker *v17; // rax
  bool m_IsHostile; // bl
  unsigned int v19; // eax
  UFG::SimComponent *AIActionTreeComponent; // rax
  UFG::SimObjectGame *v21; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v24; // al
  UFG::TargetingSystemBaseComponent *TargetingSystemBaseComponent; // rax
  UFG::HealthComponent *HealthComponent; // rax
  __int64 mNumMeleeAttackers; // rcx
  __int64 v28; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *i; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v30; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v31; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *mNext; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v33; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v34; // rax
  _QWORD v35[5]; // [rsp+0h] [rbp-A8h] BYREF
  UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> list; // [rsp+28h] [rbp-80h] BYREF

  v35[4] = -2i64;
  this->mNumMeleeAttackers = 0;
  if ( this->mAutoFrameEnabled )
  {
    list.mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    v2 = UFG::NearbyCharacterManager::s_pInstance;
    v3 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
    UFG::NearbyCharacterManager::GetNearbyCharacters(v2, &list, eNEARBY_CHARACTER_FIGHTER, v3);
    LocalPlayer = UFG::GetLocalPlayer();
    v5 = list.mNode.mNext - 1;
    v6 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&v35[3];
    if ( list.mNode.mNext - 1 != v6 )
    {
      do
      {
        mPrev = v5[3].mPrev;
        if ( mPrev )
        {
          if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *))mPrev->mPrev[7].mPrev)(mPrev) )
          {
            v8 = v5[3].mPrev;
            if ( (UFG::SimObjectCharacter *)v8[2].mNext != LocalPlayer )
            {
              MeshShape = (UFG::TransformNodeComponent *)hkMemoryMeshBody::getMeshShape((hkMemoryMeshBody *)v5[3].mPrev);
              v10 = MeshShape;
              if ( v8 )
              {
                if ( MeshShape )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform(MeshShape);
                  x = v10->mWorldTransform.v3.x;
                  y = v10->mWorldTransform.v3.y;
                  z = v10->mWorldTransform.v3.z;
                  v14 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
                  if ( (float)((float)((float)((float)(v14[1] - y) * (float)(v14[1] - y))
                                     + (float)((float)(*v14 - x) * (float)(*v14 - x)))
                             + (float)((float)(v14[2] - z) * (float)(v14[2] - z))) <= 900.0 )
                  {
                    CharacterOccupantComponent = UFG::AIEntityComponent::GetCharacterOccupantComponent((UFG::AIEntityComponent *)v8);
                    if ( !CharacterOccupantComponent
                      || LODWORD(CharacterOccupantComponent[1].m_SafePointerList.mNode.mNext) != 13 )
                    {
                      m_pSimObject = (UFG::SimObjectCVBase *)v10->m_pSimObject;
                      v17 = UFG::FactionInterface::Get();
                      if ( (unsigned int)UFG::FactionInterface::GetStanding(
                                           &v17->mFactionInterface,
                                           LocalPlayer,
                                           m_pSimObject) )
                      {
                        m_IsHostile = UFG::g_AIObjectiveParams[SHIDWORD(v8[260].mPrev)].m_IsHostile;
                        v19 = _S13_2;
                        if ( (_S13_2 & 1) == 0 )
                        {
                          _S13_2 |= 1u;
                          hostileNodeId_0.mUID = UFG::qStringHashUpper32("Hostile", -1);
                          v19 = _S13_2;
                        }
                        if ( (v19 & 2) == 0 )
                        {
                          _S13_2 = v19 | 2;
                          mostUsedIndex_hostileNodeId = GetMostUsedIndex(hostileNodeId_0.mUID);
                        }
                        AIActionTreeComponent = UFG::ActiveAIEntityComponent::GetAIActionTreeComponent((UFG::ActiveAIEntityComponent *)v8);
                        if ( AIActionTreeComponent )
                          ActionController::IsPlaying(
                            (ActionController *)&AIActionTreeComponent[3].m_TypeUID,
                            &hostileNodeId_0,
                            mostUsedIndex_hostileNodeId,
                            1);
                        v21 = (UFG::SimObjectGame *)v10->m_pSimObject;
                        v24 = 0;
                        if ( v21 )
                        {
                          m_Flags = v21->m_Flags;
                          if ( (m_Flags & 0x4000) != 0
                            || m_Flags < 0
                            || (m_Flags & 0x2000) != 0
                            || (m_Flags & 0x1000) != 0 )
                          {
                            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v21,
                                                  UFG::HudComponent::_TypeUID);
                          }
                          else
                          {
                            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v21, UFG::HudComponent::_TypeUID);
                          }
                          if ( ComponentOfTypeHK && HIBYTE(ComponentOfTypeHK[3].m_Flags) )
                            v24 = 1;
                        }
                        if ( m_IsHostile || v24 )
                        {
                          TargetingSystemBaseComponent = (UFG::TargetingSystemBaseComponent *)UFG::AIEntityComponent::GetTargetingSystemBaseComponent((UFG::AIEntityComponent *)v8);
                          if ( !TargetingSystemBaseComponent
                            || !UFG::HasRangedWeaponEquippedWithAmmo(TargetingSystemBaseComponent) )
                          {
                            HealthComponent = UFG::AIEntityComponent::GetHealthComponent((UFG::AIEntityComponent *)v5[3].mPrev);
                            if ( HealthComponent )
                            {
                              if ( !HealthComponent->m_bIsKnockedOut )
                              {
                                mNumMeleeAttackers = this->mNumMeleeAttackers;
                                v28 = mNumMeleeAttackers;
                                this->mNumMeleeAttackers = mNumMeleeAttackers + 1;
                                this->mMeleeAttackerPositions[v28].x = x;
                                this->mMeleeAttackerPositions[v28].y = y;
                                this->mMeleeAttackerPositions[v28].z = z;
                                if ( this->mNumMeleeAttackers >= 16 )
                                  break;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v5 = v5[1].mNext - 1;
      }
      while ( v5 != v6 );
    }
    for ( i = list.mNode.mNext - 1; list.mNode.mNext - 1 != v6; i = list.mNode.mNext - 1 )
    {
      v30 = i + 1;
      v31 = i[1].mPrev;
      mNext = i[1].mNext;
      v31->mNext = mNext;
      mNext->mPrev = v31;
      v30->mPrev = v30;
      v30->mNext = v30;
    }
    v33 = list.mNode.mPrev;
    v34 = list.mNode.mNext;
    list.mNode.mPrev->mNext = list.mNode.mNext;
    v34->mPrev = v33;
  }
}

// File Line: 4464
// RVA: 0x3C9340
void __fastcall UFG::FollowCameraComponent::SafetyDetectInconsistentCameraMode(
        UFG::FollowCameraComponent *this,
        float dt)
{
  UFG::SimObjectCharacter *v3; // rbx
  signed __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfType; // rax
  bool v6; // si
  UFG::SimComponent *CurrentGameCamera; // rax
  UFG::SimComponent *v8; // r14
  __int64 *mPrev; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::Event *v11; // rbx
  UFG::allocator::free_link *v12; // rax
  UFG::Event *v13; // rdx
  UFG::qNode<UFG::Event,UFG::Event> *p_mNext; // rcx
  UFG::EventVtbl *mNext; // rax
  __int64 *v16; // rcx
  __int64 **v17; // rax
  __int64 *v18; // rcx
  __int64 **v19; // rax
  __int64 *v20; // [rsp+28h] [rbp-28h] BYREF
  __int64 **p_m_SafePointerList; // [rsp+30h] [rbp-20h]
  UFG::qNode<UFG::Event,UFG::Event> *v22; // [rsp+38h] [rbp-18h]

  if ( dt > 0.0 )
  {
    v3 = LocalPlayer;
    v6 = LocalPlayer
      && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
         ? (ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterOccupantComponent::_TypeUID))
         : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                LocalPlayer,
                                UFG::CharacterOccupantComponent::_TypeUID)))
        : (ComponentOfType = LocalPlayer->m_Components.p[44].m_pComponent),
          ComponentOfType)
      && LODWORD(ComponentOfType[1].m_SafePointerList.mNode.mNext) != 13;
    CurrentGameCamera = (UFG::SimComponent *)UFG::GetCurrentGameCamera();
    v8 = CurrentGameCamera;
    if ( CurrentGameCamera )
    {
      if ( !UFG::SimComponent::IsType(CurrentGameCamera, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID) )
        v6 = 0;
      LOBYTE(CurrentGameCamera) = UFG::SimComponent::IsType(v8, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID);
    }
    if ( !v6 || (_BYTE)CurrentGameCamera )
      this->mTimeShouldBeInVehicleCamButAreNot = 0.0;
    else
      this->mTimeShouldBeInVehicleCamButAreNot = dt + this->mTimeShouldBeInVehicleCamButAreNot;
    if ( UFG::FollowCameraComponent::rSafetyMaxInconsistentTime < this->mTimeShouldBeInVehicleCamButAreNot )
    {
      v20 = (__int64 *)&v20;
      p_m_SafePointerList = &v20;
      v22 = (UFG::qNode<UFG::Event,UFG::Event> *)v3;
      if ( v3 )
      {
        mPrev = (__int64 *)v3->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        mPrev[1] = (__int64)&v20;
        v20 = mPrev;
        p_m_SafePointerList = (__int64 **)&v3->m_SafePointerList;
        v3->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20;
      }
      v10 = UFG::qMalloc(0x50ui64, "CameraSafetyChangeTask", 0i64);
      v11 = (UFG::Event *)v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
        v11->m_NamePTR = "EVT_MOUNT_VEHICLE_CAMERA";
        v11->m_EventUID = UFG::qStringHash32("EVT_MOUNT_VEHICLE_CAMERA", 0xFFFFFFFF);
        v11->vfptr = (UFG::EventVtbl *)&UFG::AnimatedEvent::`vftable;
        v13 = v11 + 1;
        v11[1].vfptr = (UFG::EventVtbl *)&v11[1];
        v11[1].mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)&v11[1];
        v11[1].mNext = v22;
        if ( v22 )
        {
          p_mNext = (UFG::qNode<UFG::Event,UFG::Event> *)&v22->mNext;
          mNext = (UFG::EventVtbl *)v22->mNext;
          mNext[1].__vecDelDtor = (void *(__fastcall *)(UFG::Event *, unsigned int))v13;
          v13->vfptr = mNext;
          v11[1].mPrev = p_mNext;
          p_mNext->mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)v13;
        }
      }
      else
      {
        v11 = 0i64;
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v11);
      this->mTimeShouldBeInVehicleCamButAreNot = 0.0;
      if ( v22 )
      {
        v16 = v20;
        v17 = p_m_SafePointerList;
        v20[1] = (__int64)p_m_SafePointerList;
        *v17 = v16;
        v20 = (__int64 *)&v20;
        p_m_SafePointerList = &v20;
      }
      v18 = v20;
      v19 = p_m_SafePointerList;
      v20[1] = (__int64)p_m_SafePointerList;
      *v19 = v18;
    }
  }
}

