// File Line: 82
// RVA: 0x14C1C00
hkSeekableStreamReader *UFG::_dynamic_initializer_for__TweakableOverrideParameters__()
{
  hkSeekableStreamReader *v0; // rbx
  signed int v1; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &TweakableOverrideParameters;
  v1 = 105;
  do
  {
    result = Assembly::GetRCX(v0);
    v0 = (hkSeekableStreamReader *)((char *)v0 + 316);
    --v1;
  }
  while ( v1 >= 0 );
  return result;
}

// File Line: 83
// RVA: 0x14C1C40
__int64 UFG::_dynamic_initializer_for__TweakableOverrideSymbols__()
{
  `eh vector constructor iterator'(
    TweakableOverrideSymbols,
    4ui64,
    106,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit(UFG::_dynamic_atexit_destructor_for__TweakableOverrideSymbols__);
}

// File Line: 89
// RVA: 0x14C8A40
__int64 UFG::_dynamic_initializer_for__gEventMountVehicle__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gEventMountVehicle, "EVT_MOUNT_VEHICLE", "\tCharacter gets on vehicle.\n");
  return atexit(UFG::_dynamic_atexit_destructor_for__gEventMountVehicle__);
}

// File Line: 90
// RVA: 0x14C89E0
__int64 UFG::_dynamic_initializer_for__gEventDisMountVehicle__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gEventDisMountVehicle, "EVT_DISMOUNT_VEHICLE", "\tCharacter gets off vehicle.\n");
  return atexit(UFG::_dynamic_atexit_destructor_for__gEventDisMountVehicle__);
}

// File Line: 91
// RVA: 0x14C8A70
__int64 UFG::_dynamic_initializer_for__gEventMountVehicleCamera__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gEventMountVehicleCamera,
    "EVT_MOUNT_VEHICLE_CAMERA",
    "\tCharacter gets on vehicle.\n");
  return atexit(UFG::_dynamic_atexit_destructor_for__gEventMountVehicleCamera__);
}

// File Line: 92
// RVA: 0x14C8A10
__int64 UFG::_dynamic_initializer_for__gEventDisMountVehicleCamera__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gEventDisMountVehicleCamera,
    "EVT_DISMOUNT_VEHICLE_CAMERA",
    "\tCharacter gets off vehicle.\n");
  return atexit(UFG::_dynamic_atexit_destructor_for__gEventDisMountVehicleCamera__);
}

// File Line: 93
// RVA: 0x14C89B0
__int64 UFG::_dynamic_initializer_for__gEventCameraZooming__()
{
  UFG::ChannelObj::ChannelObj(
    &UFG::gEventCameraZooming,
    "EVT_CAMERA_ZOOMING",
    "\tThe camera is performing a zoom in or out operation\n");
  return atexit(UFG::_dynamic_atexit_destructor_for__gEventCameraZooming__);
}

// File Line: 119
// RVA: 0x14BFF20
__int64 dynamic_initializer_for__UFG::FollowCameraComponent::s_FollowCameraComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::FollowCameraComponent::s_FollowCameraComponentList__);
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
  `eh vector constructor iterator'(
    UFG::FollowCameraComponent::mContextParameterSymbols,
    4ui64,
    15,
    (void (__fastcall *)(void *))BackInfo::BackInfo);
  return atexit(dynamic_atexit_destructor_for__UFG::FollowCameraComponent::mContextParameterSymbols__);
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
void __fastcall UFG::FollowCameraComponent::FollowCameraComponent(UFG::FollowCameraComponent *this, unsigned int name_uid)
{
  UFG::FollowCameraComponent *v2; // rdi
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v3; // rbx
  float *v4; // r13
  float *v5; // rsi
  float *v6; // r14
  float *v7; // r15
  signed __int64 v8; // r12
  float *v9; // r12
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v10; // rax
  float *v11; // rax
  signed __int64 v12; // rcx
  float v13; // xmm1_4
  float v14; // xmm2_4
  _DWORD *v15; // rax
  _DWORD *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm4_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm1_4
  float v61; // xmm2_4
  float v62; // xmm3_4
  float v63; // xmm2_4
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm0_4
  float v67; // xmm1_4
  signed __int64 v68; // rax
  float v69; // xmm1_4
  float v70; // xmm2_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  float v74; // xmm2_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  float v77; // xmm1_4
  float v78; // xmm0_4
  float v79; // xmm2_4
  float v80; // xmm1_4
  float v81; // xmm2_4
  float v82; // xmm1_4
  float v83; // xmm2_4
  float v84; // xmm1_4
  float v85; // xmm2_4
  float v86; // xmm1_4
  float v87; // xmm2_4
  float v88; // xmm0_4
  float v89; // xmm2_4
  float v90; // xmm1_4
  signed __int64 v91; // rax
  float v92; // xmm1_4
  float v93; // xmm2_4
  float v94; // xmm1_4
  float v95; // xmm2_4
  float v96; // xmm1_4
  float v97; // xmm2_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  float v100; // xmm1_4
  float v101; // xmm2_4
  float v102; // xmm2_4
  float v103; // xmm0_4
  float v104; // xmm1_4
  float v105; // xmm1_4
  float v106; // xmm2_4
  float v107; // xmm1_4
  float v108; // xmm2_4
  float v109; // xmm1_4
  float v110; // xmm2_4
  float v111; // xmm1_4
  float v112; // xmm2_4
  float v113; // xmm1_4
  float v114; // xmm0_4
  float v115; // xmm2_4
  signed __int64 v116; // rax
  float v117; // xmm1_4
  float v118; // xmm2_4
  float v119; // xmm1_4
  float v120; // xmm2_4
  float v121; // xmm1_4
  float v122; // xmm2_4
  float v123; // xmm1_4
  float v124; // xmm2_4
  float v125; // xmm1_4
  float v126; // xmm2_4
  hkSeekableStreamReader *v127; // rax
  hkSeekableStreamReader *v128; // rax
  hkSeekableStreamReader *v129; // rax
  hkSeekableStreamReader *v130; // rax
  int v131; // [rsp+10h] [rbp-21h]
  __int64 v132; // [rsp+20h] [rbp-11h]
  int v133; // [rsp+30h] [rbp-1h]
  int v134; // [rsp+34h] [rbp+3h]
  int v135; // [rsp+38h] [rbp+7h]
  hkSeekableStreamReader *v136; // [rsp+40h] [rbp+Fh]
  void (__fastcall *v137)(UFG::FollowCameraComponent *, UFG::Event *); // [rsp+48h] [rbp+17h]

  v2 = this;
  UFG::GameCameraComponent::GameCameraComponent((UFG::GameCameraComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FollowCameraComponent::`vftable';
  UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>(&v2->mTarget);
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&v2->mEnemyTarget);
  v2->mFov.mDuration = 0.0099999998;
  v2->mEye.mDuration.x = 0.0099999998;
  v2->mEye.mDuration.y = 0.0099999998;
  v2->mEye.mDuration.z = 0.0099999998;
  v4 = &v2->mLook.mDuration.x;
  *v4 = 0.0099999998;
  v4[1] = 0.0099999998;
  v4[2] = 0.0099999998;
  v2->mVelocity.mDuration.x = 0.0099999998;
  v2->mVelocity.mDuration.y = 0.0099999998;
  v2->mVelocity.mDuration.z = 0.0099999998;
  v5 = &v2->mOffsetLook.mDuration.x;
  *v5 = 0.0099999998;
  v5[1] = 0.0099999998;
  v5[2] = 0.0099999998;
  v6 = &v2->mOffsetEye.mDuration.x;
  *v6 = 0.0099999998;
  v6[1] = 0.0099999998;
  v6[2] = 0.0099999998;
  v7 = &v2->mRecoilEye.mDuration.x;
  *v7 = 0.0099999998;
  v7[1] = 0.0099999998;
  v7[2] = 0.0099999998;
  v2->mEyeNoise.bCircular = 0;
  v133 = 1056964608;
  v134 = 1056964608;
  v135 = 1056964608;
  v136 = (hkSeekableStreamReader *)4575657222473777152i64;
  LODWORD(v137) = 1065353216;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetParameters(
    &v2->mEyeNoise,
    6,
    (UFG::qVector3 *)&v136,
    (UFG::qVector3 *)&v133,
    (UFG::qVector3 *)&v132,
    (UFG::qVector3 *)&v131);
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::qNoise<UFG::qVector3,UFG::qVector3>(&v2->mLookNoise);
  v2->mHorizCompTargetSpeedWindowMaxTimespan = 1.0;
  v8 = (signed __int64)&v2->mHorizCompTargetSpeedWindow;
  *(_QWORD *)(v8 + 20) = 0i64;
  *(_DWORD *)(v8 + 16) = 0;
  *(_QWORD *)(v8 + 8) = 0i64;
  *(_QWORD *)v8 = 0i64;
  *(_QWORD *)(v8 + 28) = 0i64;
  *(_DWORD *)(v8 + 40) = 0;
  UFG::qMemSet(&v2->mHorizCompTargetSpeedWindow.m_RunningSum, 0, 4u);
  UFG::qAverageWindow<float>::SetMaxTimespan(&v2->mHorizCompTargetSpeedWindow, 1.0, 30.0);
  v2->mHorizCompOffset.mDuration = 0.0099999998;
  v9 = &v2->mAimEye.mDuration.x;
  *v9 = 0.0099999998;
  v9[1] = 0.0099999998;
  v9[2] = 0.0099999998;
  v2->mAimLook.mDuration.x = 0.0099999998;
  v2->mAimLook.mDuration.y = 0.0099999998;
  v2->mAimLook.mDuration.z = 0.0099999998;
  v10 = UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mPrev;
  UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *)&v2->mPrev;
  v3->mPrev = v10;
  v2->mNext = (UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *)&UFG::FollowCameraComponent::s_FollowCameraComponentList;
  UFG::FollowCameraComponent::s_FollowCameraComponentList.mNode.mPrev = (UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::FollowCameraComponent::_FollowCameraComponentTypeUID,
    "FollowCameraComponent");
  gTransitionString[0] = 0;
  v2->mNumMeleeAttackers = 0;
  v11 = &v2->mMeleeAttackerPositions[0].z;
  v12 = 16i64;
  do
  {
    v13 = UFG::qVector3::msZero.y;
    v14 = UFG::qVector3::msZero.z;
    *(v11 - 2) = UFG::qVector3::msZero.x;
    *(v11 - 1) = v13;
    *v11 = v14;
    v11 += 3;
    --v12;
  }
  while ( v12 );
  v2->mDofFarFocalDist = 20.0;
  v15 = (_DWORD *)&v2->mEyeNoise.tDecay.x;
  v15[3] = -1110651699;
  v15[4] = -1110651699;
  v15[5] = -1110651699;
  v15[6] = 1036831949;
  v15[7] = 1036831949;
  v15[8] = 1036831949;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&v2->mEyeNoise);
  v16 = (_DWORD *)&v2->mLookNoise.tDecay.x;
  v16[3] = -1102263091;
  v16[4] = -1102263091;
  v16[5] = -1102263091;
  v16[6] = 1045220557;
  v16[7] = 1045220557;
  v16[8] = 1045220557;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&v2->mLookNoise);
  v17 = UFG::qVector3::msDirUp.y;
  v18 = UFG::qVector3::msDirUp.z;
  v2->mUpFrom.x = UFG::qVector3::msDirUp.x;
  v2->mUpFrom.y = v17;
  v2->mUpFrom.z = v18;
  UFG::qAverageWindow<float>::SetTimespan(
    &v2->mHorizCompTargetSpeedWindow,
    UFG::FollowCameraComponent::rHorizCompSpeedWindowTimespan,
    30.0);
  v2->mHorizCompTargetSpeedSubmittedTimespan = UFG::FollowCameraComponent::rHorizCompSpeedWindowTimespan;
  v19 = UFG::qVector3::msZero.y;
  v20 = UFG::qVector3::msZero.z;
  v2->mAimOrigin.x = UFG::qVector3::msZero.x;
  v2->mAimOrigin.y = v19;
  v2->mAimOrigin.z = v20;
  v2->mSafeRadius = 0.0;
  v21 = UFG::FollowCameraComponent::rOffsetLookDuration;
  if ( UFG::FollowCameraComponent::rOffsetLookDuration <= 0.0099999998 )
    v22 = FLOAT_0_0099999998;
  else
    v22 = UFG::FollowCameraComponent::rOffsetLookDuration;
  if ( UFG::FollowCameraComponent::rOffsetLookDuration <= 0.0099999998 )
    v23 = FLOAT_0_0099999998;
  else
    v23 = UFG::FollowCameraComponent::rOffsetLookDuration;
  if ( UFG::FollowCameraComponent::rOffsetLookDuration <= 0.0099999998 )
    v21 = FLOAT_0_0099999998;
  *v5 = v21;
  v2->mOffsetLook.mDuration.y = v23;
  v2->mOffsetLook.mDuration.z = v22;
  *(_QWORD *)&v2->mOffsetLook.mParameter.x = 0i64;
  v2->mOffsetLook.mParameter.z = 0.0;
  v24 = UFG::qVector3::msZero.y;
  v25 = UFG::qVector3::msZero.z;
  v2->mOffsetLook.v0.x = UFG::qVector3::msZero.x;
  v2->mOffsetLook.v0.y = v24;
  v2->mOffsetLook.v0.z = v25;
  v26 = UFG::qVector3::msZero.y;
  v27 = UFG::qVector3::msZero.z;
  v2->mOffsetLook.v1.x = UFG::qVector3::msZero.x;
  v2->mOffsetLook.v1.y = v26;
  v2->mOffsetLook.v1.z = v27;
  v28 = UFG::qVector3::msZero.y;
  v29 = UFG::qVector3::msZero.z;
  v2->mOffsetLook.p0.x = UFG::qVector3::msZero.x;
  v2->mOffsetLook.p0.y = v28;
  v2->mOffsetLook.p0.z = v29;
  v30 = UFG::qVector3::msZero.y;
  v31 = UFG::qVector3::msZero.z;
  v2->mOffsetLook.p1.x = UFG::qVector3::msZero.x;
  v2->mOffsetLook.p1.y = v30;
  v2->mOffsetLook.p1.z = v31;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mOffsetLook);
  v32 = UFG::FollowCameraComponent::rOffsetEyeDuration;
  if ( UFG::FollowCameraComponent::rOffsetEyeDuration <= 0.0099999998 )
    v33 = FLOAT_0_0099999998;
  else
    v33 = UFG::FollowCameraComponent::rOffsetEyeDuration;
  if ( UFG::FollowCameraComponent::rOffsetEyeDuration <= 0.0099999998 )
    v34 = FLOAT_0_0099999998;
  else
    v34 = UFG::FollowCameraComponent::rOffsetEyeDuration;
  if ( UFG::FollowCameraComponent::rOffsetEyeDuration <= 0.0099999998 )
    v32 = FLOAT_0_0099999998;
  *v6 = v32;
  v2->mOffsetEye.mDuration.y = v34;
  v2->mOffsetEye.mDuration.z = v33;
  *(_QWORD *)&v2->mOffsetEye.mParameter.x = 0i64;
  v2->mOffsetEye.mParameter.z = 0.0;
  v35 = UFG::qVector3::msZero.y;
  v36 = UFG::qVector3::msZero.z;
  v2->mOffsetEye.v0.x = UFG::qVector3::msZero.x;
  v2->mOffsetEye.v0.y = v35;
  v2->mOffsetEye.v0.z = v36;
  v37 = UFG::qVector3::msZero.y;
  v38 = UFG::qVector3::msZero.z;
  v2->mOffsetEye.v1.x = UFG::qVector3::msZero.x;
  v2->mOffsetEye.v1.y = v37;
  v2->mOffsetEye.v1.z = v38;
  v39 = UFG::qVector3::msZero.y;
  v40 = UFG::qVector3::msZero.z;
  v2->mOffsetEye.p0.x = UFG::qVector3::msZero.x;
  v2->mOffsetEye.p0.y = v39;
  v2->mOffsetEye.p0.z = v40;
  v41 = UFG::qVector3::msZero.y;
  v42 = UFG::qVector3::msZero.z;
  v2->mOffsetEye.p1.x = UFG::qVector3::msZero.x;
  v2->mOffsetEye.p1.y = v41;
  v2->mOffsetEye.p1.z = v42;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mOffsetEye);
  v2->mMaxRadiusOverrideEnabled = 0;
  v2->mMaxRadiusOverrideParam = 0.0;
  v2->mMaxRadiusOverride = 5.0;
  v2->mRiseOverrideEnabled = 0;
  v2->mRiseOverrideParam = 0.0;
  v2->mRiseOverride = 2.0;
  *(_WORD *)&v2->mAutoFrameEnabled = 1;
  v2->mAutoFrameFarthestAttackerDist = 0.0;
  v2->mAutoFrameSnapNextAttackerDist = 0;
  *(_QWORD *)&v2->mRecoilAngle = 0i64;
  v43 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v44 = FLOAT_0_0099999998;
  else
    v44 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v45 = FLOAT_0_0099999998;
  else
    v45 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v43 = FLOAT_0_0099999998;
  *v7 = v43;
  v2->mRecoilEye.mDuration.y = v45;
  v2->mRecoilEye.mDuration.z = v44;
  *(_QWORD *)&v2->mRecoilEye.mParameter.x = 0i64;
  v2->mRecoilEye.mParameter.z = 0.0;
  v46 = UFG::qVector3::msZero.y;
  v47 = UFG::qVector3::msZero.z;
  v2->mRecoilEye.v0.x = UFG::qVector3::msZero.x;
  v2->mRecoilEye.v0.y = v46;
  v2->mRecoilEye.v0.z = v47;
  v48 = UFG::qVector3::msZero.y;
  v49 = UFG::qVector3::msZero.z;
  v2->mRecoilEye.v1.x = UFG::qVector3::msZero.x;
  v2->mRecoilEye.v1.y = v48;
  v2->mRecoilEye.v1.z = v49;
  v50 = UFG::qVector3::msZero.y;
  v51 = UFG::qVector3::msZero.z;
  v2->mRecoilEye.p0.x = UFG::qVector3::msZero.x;
  v2->mRecoilEye.p0.y = v50;
  v2->mRecoilEye.p0.z = v51;
  v52 = UFG::qVector3::msZero.y;
  v53 = UFG::qVector3::msZero.z;
  v2->mRecoilEye.p1.x = UFG::qVector3::msZero.x;
  v2->mRecoilEye.p1.y = v52;
  v2->mRecoilEye.p1.z = v53;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mRecoilEye);
  v54 = UFG::FollowCameraComponent::rHorizCompDurationAttack;
  if ( UFG::FollowCameraComponent::rHorizCompDurationAttack <= 0.0099999998 )
    v54 = FLOAT_0_0099999998;
  v2->mHorizCompOffset.mDuration = v54;
  v2->mHorizCompOffset.mParameter = 0.0;
  *(_QWORD *)&v2->mHorizCompOffset.v0 = 0i64;
  *(_QWORD *)&v2->mHorizCompOffset.p0 = 0i64;
  if ( v54 <= 0.0099999998 )
    v54 = FLOAT_0_0099999998;
  v2->mHorizCompOffset.A = (float)(v54 * 0.0) / (float)((float)(v54 * v54) * v54);
  v2->mHorizCompOffset.B = COERCE_FLOAT(COERCE_UNSIGNED_INT(v54 * 0.0) ^ _xmm[0]) / (float)(v54 * v54);
  *(_QWORD *)&v2->mHorizCompOffset.C = 0i64;
  v2->mTransitionTimeOverride = -1.0;
  v2->mTransitionParamRateEye = 1.0;
  *(_QWORD *)&v2->mTransitionParamRateOrient = 1065353216i64;
  v2->mTransitionParamOrient = 0.0;
  v2->mTransitionParamRateSuppEye = 1.0;
  *(_QWORD *)&v2->mTransitionParamRateSuppLook = 1065353216i64;
  *(_QWORD *)&v2->mTransitionParamSuppLook = 0i64;
  v2->mTransitionSupplimentaryDuration = 0.0;
  v55 = UFG::qVector3::msZero.y;
  v56 = UFG::qVector3::msZero.z;
  v2->mTransitionFromEye.x = UFG::qVector3::msZero.x;
  v2->mTransitionFromEye.y = v55;
  v2->mTransitionFromEye.z = v56;
  v57 = UFG::qQuaternion::msUnity.y;
  v58 = UFG::qQuaternion::msUnity.z;
  v59 = UFG::qQuaternion::msUnity.w;
  v2->mTransitionFromOri.x = UFG::qQuaternion::msUnity.x;
  v2->mTransitionFromOri.y = v57;
  v2->mTransitionFromOri.z = v58;
  v2->mTransitionFromOri.w = v59;
  v2->mTransitionFromLen = 0.0;
  v60 = UFG::qVector4::msUnity.y;
  v61 = UFG::qVector4::msUnity.z;
  v62 = UFG::qVector4::msUnity.w;
  v2->mCharacterSpacePos.x = UFG::qVector4::msUnity.x;
  v2->mCharacterSpacePos.y = v60;
  v2->mCharacterSpacePos.z = v61;
  v2->mCharacterSpacePos.w = v62;
  v2->mEnableCharacterSpaceSmoothing = 0;
  v2->mTimeShouldBeInVehicleCamButAreNot = 0.0;
  v2->mMouseBoom.x = 0.0;
  v2->mMouseBoom.y = -1.0;
  v2->mMouseBoom.z = 0.0;
  v2->mMouseBoomSet = 0;
  UFG::qMemSet(&v2->mOldParams, 0, 0x13Cu);
  UFG::qMemSet(&v2->mBlendedParams, 0, 0x13Cu);
  UFG::FollowCameraComponent::LoadContextParameters(v2);
  UFG::FollowCameraComponent::SetContext(v2, 0, 1);
  *(_QWORD *)&v2->mFov.mDuration = 1065353216i64;
  *(_QWORD *)&v2->mFov.v0 = 0i64;
  v2->mFov.p0 = v2->mBlendedParams.mTweakFov;
  v63 = v2->mBlendedParams.mTweakFov;
  v2->mFov.p1 = v63;
  v64 = v2->mFov.p0;
  v2->mFov.A = (float)(v2->mFov.p0 - v63) * 2.0;
  v2->mFov.B = (float)(v63 - v64) * 3.0;
  v2->mFov.C = 0.0;
  v2->mFov.D = v64;
  v65 = v2->mBlendedParams.mTweakEyeDurationV;
  v66 = v2->mBlendedParams.mTweakEyeDurationH;
  if ( v65 <= 0.0099999998 )
    v65 = FLOAT_0_0099999998;
  if ( v66 <= 0.0099999998 )
    v67 = FLOAT_0_0099999998;
  else
    v67 = v2->mBlendedParams.mTweakEyeDurationH;
  if ( v66 <= 0.0099999998 )
    v66 = FLOAT_0_0099999998;
  v68 = (signed __int64)&v2->mEye;
  *(float *)v68 = v66;
  *(float *)(v68 + 4) = v67;
  *(float *)(v68 + 8) = v65;
  *(_QWORD *)(v68 + 12) = 0i64;
  *(_DWORD *)(v68 + 20) = 0;
  v69 = UFG::qVector3::msZero.y;
  v70 = UFG::qVector3::msZero.z;
  *(float *)(v68 + 96) = UFG::qVector3::msZero.x;
  *(float *)(v68 + 100) = v69;
  *(float *)(v68 + 104) = v70;
  v71 = UFG::qVector3::msZero.y;
  v72 = UFG::qVector3::msZero.z;
  *(float *)(v68 + 108) = UFG::qVector3::msZero.x;
  *(float *)(v68 + 112) = v71;
  *(float *)(v68 + 116) = v72;
  v73 = UFG::qVector3::msZero.y;
  v74 = UFG::qVector3::msZero.z;
  *(float *)(v68 + 72) = UFG::qVector3::msZero.x;
  *(float *)(v68 + 76) = v73;
  *(float *)(v68 + 80) = v74;
  v75 = UFG::qVector3::msZero.y;
  v76 = UFG::qVector3::msZero.z;
  *(float *)(v68 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v68 + 88) = v75;
  *(float *)(v68 + 92) = v76;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
  v77 = v2->mBlendedParams.mTweakLookDurationV;
  v78 = v2->mBlendedParams.mTweakLookDurationH;
  if ( v77 <= 0.0099999998 )
    v77 = FLOAT_0_0099999998;
  if ( v78 <= 0.0099999998 )
    v79 = FLOAT_0_0099999998;
  else
    v79 = v2->mBlendedParams.mTweakLookDurationH;
  if ( v78 <= 0.0099999998 )
    v78 = FLOAT_0_0099999998;
  *v4 = v78;
  v2->mLook.mDuration.y = v79;
  v2->mLook.mDuration.z = v77;
  *(_QWORD *)&v2->mLook.mParameter.x = 0i64;
  v2->mLook.mParameter.z = 0.0;
  v80 = UFG::qVector3::msZero.y;
  v81 = UFG::qVector3::msZero.z;
  v2->mLook.v0.x = UFG::qVector3::msZero.x;
  v2->mLook.v0.y = v80;
  v2->mLook.v0.z = v81;
  v82 = UFG::qVector3::msZero.y;
  v83 = UFG::qVector3::msZero.z;
  v2->mLook.v1.x = UFG::qVector3::msZero.x;
  v2->mLook.v1.y = v82;
  v2->mLook.v1.z = v83;
  v84 = UFG::qVector3::msZero.y;
  v85 = UFG::qVector3::msZero.z;
  v2->mLook.p0.x = UFG::qVector3::msZero.x;
  v2->mLook.p0.y = v84;
  v2->mLook.p0.z = v85;
  v86 = UFG::qVector3::msZero.y;
  v87 = UFG::qVector3::msZero.z;
  v2->mLook.p1.x = UFG::qVector3::msZero.x;
  v2->mLook.p1.y = v86;
  v2->mLook.p1.z = v87;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mLook);
  v88 = v2->mBlendedParams.mTweakVelocityDuration;
  if ( v88 <= 0.0099999998 )
    v89 = FLOAT_0_0099999998;
  else
    v89 = v2->mBlendedParams.mTweakVelocityDuration;
  if ( v88 <= 0.0099999998 )
    v90 = FLOAT_0_0099999998;
  else
    v90 = v2->mBlendedParams.mTweakVelocityDuration;
  if ( v88 <= 0.0099999998 )
    v88 = FLOAT_0_0099999998;
  v91 = (signed __int64)&v2->mVelocity;
  *(float *)v91 = v88;
  *(float *)(v91 + 4) = v90;
  *(float *)(v91 + 8) = v89;
  *(_QWORD *)(v91 + 12) = 0i64;
  *(_DWORD *)(v91 + 20) = 0;
  v92 = UFG::qVector3::msZero.y;
  v93 = UFG::qVector3::msZero.z;
  *(float *)(v91 + 96) = UFG::qVector3::msZero.x;
  *(float *)(v91 + 100) = v92;
  *(float *)(v91 + 104) = v93;
  v94 = UFG::qVector3::msZero.y;
  v95 = UFG::qVector3::msZero.z;
  *(float *)(v91 + 108) = UFG::qVector3::msZero.x;
  *(float *)(v91 + 112) = v94;
  *(float *)(v91 + 116) = v95;
  v96 = UFG::qVector3::msZero.y;
  v97 = UFG::qVector3::msZero.z;
  *(float *)(v91 + 72) = UFG::qVector3::msZero.x;
  *(float *)(v91 + 76) = v96;
  *(float *)(v91 + 80) = v97;
  v98 = UFG::qVector3::msZero.y;
  v99 = UFG::qVector3::msZero.z;
  *(float *)(v91 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v91 + 88) = v98;
  *(float *)(v91 + 92) = v99;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mVelocity);
  *(_QWORD *)&v2->mBlend = 0i64;
  *(_DWORD *)&v2->mSnapNext = 16843008;
  *(_DWORD *)&v2->mFreeAiming = 0x1000000;
  v2->bUpdateFromAimComp = 0;
  v2->mOrbitSquish = 1.0;
  v2->mHeightAboveGround = 1.0;
  v2->mLatitudeMin = -0.94247788;
  v100 = v2->mCamera.mTransformation.v2.y;
  v101 = v2->mCamera.mTransformation.v2.z;
  v2->mControllerForward.x = v2->mCamera.mTransformation.v2.x;
  v2->mControllerForward.y = v100;
  v2->mControllerForward.z = v101;
  *(_QWORD *)&v2->mPassThroughTimer1 = 0i64;
  *(_QWORD *)&v2->mGotoRiseElaspedTime = 0i64;
  *(_QWORD *)&v2->mGotoRiseRate = 0i64;
  v2->mGotoAngleCollisionQueued = 0;
  *(_QWORD *)&v2->mGotoAngleCollisionQueuedWallDist = 1056964608i64;
  v2->mGotoAngleLocalSpace = 1;
  *(_QWORD *)&v2->mGotoAnglePatience = 0i64;
  *(_QWORD *)&v2->mGotoAngle = 0i64;
  *(_QWORD *)&v2->mGotoRadiusPatience = 0i64;
  v2->mGotoRadius = 0.0;
  v2->mConstrainYaw = 0;
  *(_QWORD *)&v2->mConstrainYawMin = 0i64;
  v2->mConstrainYawRate = 0.0;
  v2->bAimUseEyeLook = 0;
  v2->rAimParameter = 0.0;
  v102 = v2->mBlendedParams.mTweakEyeDurationV;
  v103 = v2->mBlendedParams.mTweakEyeDurationH;
  if ( v102 <= 0.0099999998 )
    v102 = FLOAT_0_0099999998;
  if ( v103 <= 0.0099999998 )
    v104 = FLOAT_0_0099999998;
  else
    v104 = v2->mBlendedParams.mTweakEyeDurationH;
  if ( v103 <= 0.0099999998 )
    v103 = FLOAT_0_0099999998;
  *v9 = v103;
  v2->mAimEye.mDuration.y = v104;
  v2->mAimEye.mDuration.z = v102;
  *(_QWORD *)&v2->mAimEye.mParameter.x = 0i64;
  v2->mAimEye.mParameter.z = 0.0;
  v105 = UFG::qVector3::msZero.y;
  v106 = UFG::qVector3::msZero.z;
  v2->mAimEye.v0.x = UFG::qVector3::msZero.x;
  v2->mAimEye.v0.y = v105;
  v2->mAimEye.v0.z = v106;
  v107 = UFG::qVector3::msZero.y;
  v108 = UFG::qVector3::msZero.z;
  v2->mAimEye.v1.x = UFG::qVector3::msZero.x;
  v2->mAimEye.v1.y = v107;
  v2->mAimEye.v1.z = v108;
  v109 = UFG::qVector3::msZero.y;
  v110 = UFG::qVector3::msZero.z;
  v2->mAimEye.p0.x = UFG::qVector3::msZero.x;
  v2->mAimEye.p0.y = v109;
  v2->mAimEye.p0.z = v110;
  v111 = UFG::qVector3::msZero.y;
  v112 = UFG::qVector3::msZero.z;
  v2->mAimEye.p1.x = UFG::qVector3::msZero.x;
  v2->mAimEye.p1.y = v111;
  v2->mAimEye.p1.z = v112;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimEye);
  v113 = v2->mBlendedParams.mTweakLookDurationV;
  v114 = v2->mBlendedParams.mTweakLookDurationH;
  if ( v113 <= 0.0099999998 )
    v113 = FLOAT_0_0099999998;
  if ( v114 <= 0.0099999998 )
    v115 = FLOAT_0_0099999998;
  else
    v115 = v2->mBlendedParams.mTweakLookDurationH;
  if ( v114 <= 0.0099999998 )
    v114 = FLOAT_0_0099999998;
  v116 = (signed __int64)&v2->mAimLook;
  *(float *)v116 = v114;
  *(float *)(v116 + 4) = v115;
  *(float *)(v116 + 8) = v113;
  *(_QWORD *)(v116 + 12) = 0i64;
  *(_DWORD *)(v116 + 20) = 0;
  v117 = UFG::qVector3::msZero.y;
  v118 = UFG::qVector3::msZero.z;
  *(float *)(v116 + 96) = UFG::qVector3::msZero.x;
  *(float *)(v116 + 100) = v117;
  *(float *)(v116 + 104) = v118;
  v119 = UFG::qVector3::msZero.y;
  v120 = UFG::qVector3::msZero.z;
  *(float *)(v116 + 108) = UFG::qVector3::msZero.x;
  *(float *)(v116 + 112) = v119;
  *(float *)(v116 + 116) = v120;
  v121 = UFG::qVector3::msZero.y;
  v122 = UFG::qVector3::msZero.z;
  *(float *)(v116 + 72) = UFG::qVector3::msZero.x;
  *(float *)(v116 + 76) = v121;
  *(float *)(v116 + 80) = v122;
  v123 = UFG::qVector3::msZero.y;
  v124 = UFG::qVector3::msZero.z;
  *(float *)(v116 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v116 + 88) = v123;
  *(float *)(v116 + 92) = v124;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimLook);
  *(_QWORD *)&v2->mAimDurationSupplimentary = 0i64;
  v2->mMouseBucketY = 0.0;
  v125 = UFG::qVector3::msZero.y;
  v126 = UFG::qVector3::msZero.z;
  v2->mAimDeadZoneCentre.x = UFG::qVector3::msZero.x;
  v2->mAimDeadZoneCentre.y = v125;
  v2->mAimDeadZoneCentre.z = v126;
  v2->mAimDeadZoneRadius = -1.0;
  v2->mAimDeadZoneTimer = 0.0;
  v127 = Assembly::GetRCX(v2);
  v137 = UFG::FollowCameraComponent::FollowCameraEventHandler;
  v136 = v127;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v136,
    0x4B543385u,
    0i64,
    0);
  v128 = Assembly::GetRCX(v2);
  v137 = UFG::FollowCameraComponent::FollowCameraEventHandler;
  v136 = v128;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v136,
    0xB7295A22,
    0i64,
    0);
  v129 = Assembly::GetRCX(v2);
  v137 = UFG::FollowCameraComponent::FollowCameraEventHandler;
  v136 = v129;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v136,
    UFG::gEventMountVehicleCamera.mUID,
    UFG::gEventMountVehicleCamera.mName,
    0);
  v130 = Assembly::GetRCX(v2);
  v137 = UFG::FollowCameraComponent::FollowCameraEventHandler;
  v136 = v130;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v136,
    UFG::gEventDisMountVehicleCamera.mUID,
    UFG::gEventDisMountVehicleCamera.mName,
    0);
  UFG::FollowCameraComponent::Snap(v2);
  ++UFG::FollowCameraComponent::mNumFollowCameraInstances;
}ler;
  v136 = v129;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v136,
    UFG::gEventMountVehicleCamera.mUID,
    UFG::gEventMountVehicleCamera.mName,
    0);

// File Line: 504
// RVA: 0x3BDD30
void __fastcall UFG::FollowCameraComponent::~FollowCameraComponent(UFG::FollowCameraComponent *this)
{
  UFG::FollowCameraComponent *v1; // rdi
  hkSeekableStreamReader *v2; // rax
  hkSeekableStreamReader *v3; // rax
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v4; // rbx
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v5; // rcx
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v6; // rax
  UFG::qMemoryPool *v7; // rcx
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v8; // rcx
  UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *v9; // rax
  hkSeekableStreamReader *v10; // [rsp+28h] [rbp-20h]
  void (__fastcall *v11)(UFG::FollowCameraComponent *, UFG::Event *); // [rsp+30h] [rbp-18h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::FollowCameraComponent::`vftable';
  --UFG::FollowCameraComponent::mNumFollowCameraInstances;
  v11 = UFG::FollowCameraComponent::FollowCameraEventHandler;
  v10 = Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
    0x4B543385u);
  v10 = 0i64;
  v11 = UFG::FollowCameraComponent::FollowCameraEventHandler;
  v10 = Assembly::GetRCX(v1);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
    0xB7295A22);
  v2 = Assembly::GetRCX(v1);
  v11 = UFG::FollowCameraComponent::FollowCameraEventHandler;
  v10 = v2;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
    UFG::gEventMountVehicleCamera.mUID);
  v3 = Assembly::GetRCX(v1);
  v11 = UFG::FollowCameraComponent::FollowCameraEventHandler;
  v10 = v3;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
    UFG::gEventDisMountVehicleCamera.mUID);
  if ( v1 == UFG::FollowCameraComponent::s_FollowCameraComponentpCurrentIterator )
    UFG::FollowCameraComponent::s_FollowCameraComponentpCurrentIterator = (UFG::FollowCameraComponent *)&v1->mPrev[-78];
  v4 = (UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
  v7 = v1->mHorizCompTargetSpeedWindow.m_pMemoryPool;
  if ( v7 )
    UFG::qMemoryPool::Free(v7, v1->mHorizCompTargetSpeedWindow.m_pBuffer);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mEnemyTarget);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mTarget);
  v8 = v4->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v4->mPrev = v4;
  v1->mNext = (UFG::qNode<UFG::FollowCameraComponent,UFG::FollowCameraComponent> *)&v1->mPrev;
  UFG::GameCameraComponent::~GameCameraComponent((UFG::GameCameraComponent *)&v1->vfptr);
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
  return PropertyUtils::HasComponentPropertySet(pSceneObj, (UFG::qSymbol *)&SimSymX_propset_componentFollowCamera.mUID);
}

// File Line: 538
// RVA: 0x3C8140
UFG::SimComponent *__fastcall UFG::FollowCameraComponent::PropertiesOnActivate(UFG::SceneObjectProperties *scene_object_properties)
{
  UFG::SceneObjectProperties *v1; // rdi
  unsigned int v2; // ebx
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  UFG::SimObjectModifier v8; // [rsp+38h] [rbp-30h]

  v1 = scene_object_properties;
  v2 = scene_object_properties->m_NameUID;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x21C0ui64, "FollowCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::FollowCameraComponent::FollowCameraComponent((UFG::FollowCameraComponent *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v8, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v8, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v8);
  UFG::SimObjectModifier::~SimObjectModifier(&v8);
  return v6;
}

// File Line: 547
// RVA: 0x3C5B10
void __fastcall UFG::FollowCameraComponent::InitBlendedParams(UFG::FollowCameraComponent *this)
{
  UFG::FollowCameraComponent *v1; // rbx
  signed __int64 v2; // rcx
  bool v3; // zf

  v1 = this;
  UFG::FollowCameraComponent::FollowParams::operator=(&this->mOldParams, &this->mBlendedParams);
  v2 = v1->mContext;
  v3 = v1->mBlendedParams.mTweakBlendDurations == 0;
  v1->mBlendedParams.mSrcOrientation = v1->mContextParameters[v2].mSrcOrientation;
  v1->mBlendedParams.mSrcPosition = v1->mContextParameters[v2].mSrcPosition;
  if ( v3 )
  {
    v1->mBlendedParams.mTweakLookDurationH = v1->mContextParameters[v2].mTweakLookDurationH;
    v1->mBlendedParams.mTweakLookDurationV = v1->mContextParameters[v2].mTweakLookDurationV;
    v1->mBlendedParams.mTweakEyeDurationH = v1->mContextParameters[v2].mTweakEyeDurationH;
    v1->mBlendedParams.mTweakEyeDurationV = v1->mContextParameters[v2].mTweakEyeDurationV;
    v1->mBlendedParams.mTweakFovDuration = v1->mContextParameters[v2].mTweakFovDuration;
  }
  if ( !v1->mOldParams.mTweakUseSyncBase )
    v1->mBlendedParams.mTweakBaseOffset.z = v1->mContextParameters[v2].mTweakBaseOffset.z;
  v1->mBlendedParams.mTweakUseSyncBase = v1->mContextParameters[v2].mTweakUseSyncBase;
  v1->mBlendedParams.mUseInitRise = v1->mContextParameters[v2].mUseInitRise;
  v1->mBlendedParams.mInitRise = v1->mContextParameters[v2].mInitRise;
  v1->mBlendedParams.mInitRiseRate = v1->mContextParameters[v2].mInitRiseRate;
  v1->mBlendedParams.mInitRisePatience = v1->mContextParameters[v2].mInitRisePatience;
  v1->mBlendedParams.mUseInitRadius = v1->mContextParameters[v2].mUseInitRadius;
  v1->mBlendedParams.mInitRadius = v1->mContextParameters[v2].mInitRadius;
  v1->mBlendedParams.mInitRadiusRate = v1->mContextParameters[v2].mInitRadiusRate;
  v1->mBlendedParams.mInitRadiusPatience = v1->mContextParameters[v2].mInitRadiusPatience;
  v1->mBlendedParams.mYawConstrainRate = v1->mContextParameters[v2].mYawConstrainRate;
  v1->mBlendedParams.mUseInitAngle = v1->mContextParameters[v2].mUseInitAngle;
  v1->mBlendedParams.mInitAngle = v1->mContextParameters[v2].mInitAngle;
  v1->mBlendedParams.mInitAngleRate = v1->mContextParameters[v2].mInitAngleRate;
  v1->mBlendedParams.mInitAnglePatience = v1->mContextParameters[v2].mInitAnglePatience;
  v1->mBlendedParams.mInitAngleWorldSpace = v1->mContextParameters[v2].mInitAngleWorldSpace;
  v1->mBlendedParams.mInitAngleUseSecond = v1->mContextParameters[v2].mInitAngleUseSecond;
  v1->mBlendedParams.mInitAngleSecond = v1->mContextParameters[v2].mInitAngleSecond;
  v1->mBlendedParams.mYawRestrict = v1->mContextParameters[v2].mYawRestrict;
  v1->mBlendedParams.mYawMin = v1->mContextParameters[v2].mYawMin;
  v1->mBlendedParams.mYawMax = v1->mContextParameters[v2].mYawMax;
  v1->mBlendedParams.mUseLookUpDown = v1->mContextParameters[v2].mUseLookUpDown;
  v1->mBlendedParams.mHorizCompUseDirection = v1->mContextParameters[v2].mHorizCompUseDirection;
  v1->mBlendedParams.mHorizCompSpeedWindowTimespan = v1->mContextParameters[v2].mHorizCompSpeedWindowTimespan;
  v1->mBlendedParams.mDesaturation = v1->mContextParameters[v2].mDesaturation;
  v1->mBlendedParams.mDamageMultiplier = v1->mContextParameters[v2].mDamageMultiplier;
  v1->mBlendedParams.mMotionblurMagnitude = v1->mContextParameters[v2].mMotionblurMagnitude;
  v1->mBlendedParams.mUseDofParameters = v1->mContextParameters[v2].mUseDofParameters;
}

// File Line: 606
// RVA: 0x3D87C0
void __fastcall UFG::FollowCameraComponent::UpdateBlendedParams(UFG::FollowCameraComponent *this, float dt)
{
  float v2; // xmm0_4
  float v3; // xmm7_4
  float v4; // xmm0_4
  __int64 v5; // rax
  float v6; // xmm1_4
  __int64 v7; // rdx
  bool v8; // zf
  float v9; // xmm5_4
  float v10; // xmm4_4
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

  v2 = this->mBlend;
  v3 = 0.0;
  if ( v2 <= 0.0 )
  {
    UFG::FollowCameraComponent::FollowParams::operator=(
      &this->mBlendedParams,
      &this->mContextParameters[this->mContext]);
  }
  else
  {
    v4 = v2 - (float)(dt * this->mBlendRate);
    if ( v4 >= 0.0 )
      v3 = v4;
    v5 = this->mContext;
    v6 = this->mOldParams.mTweakFov;
    this->mBlend = v3;
    v7 = v5;
    this->mBlendedParams.mTweakFov = (float)((float)(v6 - this->mContextParameters[v7].mTweakFov) * v3)
                                   + this->mContextParameters[v7].mTweakFov;
    this->mBlendedParams.mTweakFovMax = (float)((float)(this->mOldParams.mTweakFovMax
                                                      - *((float *)&this->vfptr + 79 * (v5 + 5)))
                                              * v3)
                                      + *((float *)&this->vfptr + 79 * (v5 + 5));
    this->mBlendedParams.mTweakOrbitDownRadius = (float)((float)(this->mOldParams.mTweakOrbitDownRadius
                                                               - this->mContextParameters[v7].mTweakOrbitDownRadius)
                                                       * v3)
                                               + this->mContextParameters[v7].mTweakOrbitDownRadius;
    this->mBlendedParams.mTweakEyeRise = (float)((float)(this->mOldParams.mTweakEyeRise
                                                       - this->mContextParameters[v7].mTweakEyeRise)
                                               * v3)
                                       + this->mContextParameters[v7].mTweakEyeRise;
    this->mBlendedParams.mTweakOrbitSpeed = (float)((float)(this->mOldParams.mTweakOrbitSpeed
                                                          - this->mContextParameters[v7].mTweakOrbitSpeed)
                                                  * v3)
                                          + this->mContextParameters[v7].mTweakOrbitSpeed;
    this->mBlendedParams.mTweakLatitudeMin = (float)((float)(this->mOldParams.mTweakLatitudeMin
                                                           - this->mContextParameters[v7].mTweakLatitudeMin)
                                                   * v3)
                                           + this->mContextParameters[v7].mTweakLatitudeMin;
    this->mBlendedParams.mTweakLatitudeMax = (float)((float)(this->mOldParams.mTweakLatitudeMax
                                                           - this->mContextParameters[v7].mTweakLatitudeMax)
                                                   * v3)
                                           + this->mContextParameters[v7].mTweakLatitudeMax;
    this->mBlendedParams.mTweakRadiusMin = (float)((float)(this->mOldParams.mTweakRadiusMin
                                                         - this->mContextParameters[v7].mTweakRadiusMin)
                                                 * v3)
                                         + this->mContextParameters[v7].mTweakRadiusMin;
    this->mBlendedParams.mTweakRadiusMax = (float)((float)(this->mOldParams.mTweakRadiusMax
                                                         - this->mContextParameters[v7].mTweakRadiusMax)
                                                 * v3)
                                         + this->mContextParameters[v7].mTweakRadiusMax;
    this->mBlendedParams.mTweakVaultLow = (float)((float)(this->mOldParams.mTweakVaultLow
                                                        - this->mContextParameters[v7].mTweakVaultLow)
                                                * v3)
                                        + this->mContextParameters[v7].mTweakVaultLow;
    this->mBlendedParams.mTweakNoiseFrequency = (float)((float)(this->mOldParams.mTweakNoiseFrequency
                                                              - this->mContextParameters[v7].mTweakNoiseFrequency)
                                                      * v3)
                                              + this->mContextParameters[v7].mTweakNoiseFrequency;
    this->mBlendedParams.mTweakAimWobbleRadiusMin = (float)((float)(this->mOldParams.mTweakAimWobbleRadiusMin
                                                                  - this->mContextParameters[v7].mTweakAimWobbleRadiusMin)
                                                          * v3)
                                                  + this->mContextParameters[v7].mTweakAimWobbleRadiusMin;
    v8 = this->mBlendedParams.mTweakBlendDurations == 0;
    this->mBlendedParams.mTweakAimWobbleRadiusMax = (float)((float)(this->mOldParams.mTweakAimWobbleRadiusMax
                                                                  - this->mContextParameters[v7].mTweakAimWobbleRadiusMax)
                                                          * v3)
                                                  + this->mContextParameters[v7].mTweakAimWobbleRadiusMax;
    this->mBlendedParams.mTweakAimWobbleRadiusPeriod = (float)((float)(this->mOldParams.mTweakAimWobbleRadiusPeriod
                                                                     - this->mContextParameters[v7].mTweakAimWobbleRadiusPeriod)
                                                             * v3)
                                                     + this->mContextParameters[v7].mTweakAimWobbleRadiusPeriod;
    this->mBlendedParams.mTweakAimWobbleFreq = (float)((float)(this->mOldParams.mTweakAimWobbleFreq
                                                             - this->mContextParameters[v7].mTweakAimWobbleFreq)
                                                     * v3)
                                             + this->mContextParameters[v7].mTweakAimWobbleFreq;
    this->mBlendedParams.mTweakAimWobbleAxisWeight = (float)((float)(this->mOldParams.mTweakAimWobbleAxisWeight
                                                                   - this->mContextParameters[v7].mTweakAimWobbleAxisWeight)
                                                           * v3)
                                                   + this->mContextParameters[v7].mTweakAimWobbleAxisWeight;
    this->mBlendedParams.mTweakNoiseEyeMagnitude = (float)((float)(this->mOldParams.mTweakNoiseEyeMagnitude
                                                                 - this->mContextParameters[v7].mTweakNoiseEyeMagnitude)
                                                         * v3)
                                                 + this->mContextParameters[v7].mTweakNoiseEyeMagnitude;
    this->mBlendedParams.mTweakNoiseLookMagnitude = (float)((float)(this->mOldParams.mTweakNoiseLookMagnitude
                                                                  - this->mContextParameters[v7].mTweakNoiseLookMagnitude)
                                                          * v3)
                                                  + this->mContextParameters[v7].mTweakNoiseLookMagnitude;
    this->mBlendedParams.mTweakAimRadius = (float)((float)(this->mOldParams.mTweakAimRadius
                                                         - this->mContextParameters[v7].mTweakAimRadius)
                                                 * v3)
                                         + this->mContextParameters[v7].mTweakAimRadius;
    this->mBlendedParams.mTweakFocusRadius = (float)((float)(this->mOldParams.mTweakFocusRadius
                                                           - this->mContextParameters[v7].mTweakFocusRadius)
                                                   * v3)
                                           + this->mContextParameters[v7].mTweakFocusRadius;
    this->mBlendedParams.mTweakTargetedDistance = (float)((float)(this->mOldParams.mTweakTargetedDistance
                                                                - this->mContextParameters[v7].mTweakTargetedDistance)
                                                        * v3)
                                                + this->mContextParameters[v7].mTweakTargetedDistance;
    this->mBlendedParams.mTweakVelocityDuration = (float)((float)(this->mOldParams.mTweakVelocityDuration
                                                                - this->mContextParameters[v5].mTweakVelocityDuration)
                                                        * v3)
                                                + this->mContextParameters[v5].mTweakVelocityDuration;
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
    v9 = this->mContextParameters[v7].mTweakLookOffset.y;
    v10 = this->mContextParameters[v7].mTweakLookOffset.z;
    v11 = v3 * (float)(this->mOldParams.mTweakLookOffset.y - v9);
    v12 = this->mContextParameters[v7].mTweakLookOffset.x
        + (float)(v3 * (float)(this->mOldParams.mTweakLookOffset.x - this->mContextParameters[v7].mTweakLookOffset.x));
    v13 = v3 * (float)(this->mOldParams.mTweakLookOffset.z - v10);
    this->mBlendedParams.mTweakLookOffset.x = v12;
    this->mBlendedParams.mTweakLookOffset.y = v9 + v11;
    this->mBlendedParams.mTweakLookOffset.z = v10 + v13;
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
    v8 = this->mOldParams.mTweakUseSyncBase == 0;
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
}mContextParameters[v23].mCollisionRise;
  }
}

// File Line: 1205
// RVA: 0x3DE0F0
void __fastcall UFG::FollowCameraComponent::UpdateTweaker(UFG::FollowCameraComponent *this, float delta_sec)
{
  float v2; // xmm2_4
  UFG::FollowCameraComponent *v3; // rdi
  float v4; // xmm6_4
  bool v5; // zf
  float v6; // xmm10_4
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  UFG::HomerCubic<UFG::qVector3> *v10; // rcx
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *v17; // rcx
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  UFG::HomerCubic<UFG::qVector3> *v25; // rcx
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
  float v39; // xmm8_4
  float v40; // xmm7_4
  float v41; // xmm8_4
  float v42; // xmm3_4
  float v43; // xmm4_4
  float *v44; // rsi
  float v45; // xmm9_4
  float v46; // xmm7_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  float *v51; // rbx
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  UFG::HomerCubic<float> *v56; // rcx
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
  float v73; // xmm7_4
  float v74; // xmm6_4
  float v75; // xmm0_4
  float v76; // xmm3_4

  v2 = this->mBlendedParams.mTweakRadiusMax;
  v3 = this;
  v4 = delta_sec;
  if ( v2 <= (float)(this->mBlendedParams.mTweakRadiusMin + 0.1) )
    v2 = this->mBlendedParams.mTweakRadiusMin + 0.1;
  v5 = this->mMaxRadiusOverrideEnabled == 0;
  v6 = *(float *)&FLOAT_1_0;
  this->mBlendedParams.mTweakRadiusMax = v2;
  if ( v5 )
    v7 = 0.0;
  else
    v7 = *(float *)&FLOAT_1_0;
  UFG::qApproach(&this->mMaxRadiusOverrideParam, v7, UFG::FollowCameraComponent::rMaxRadiusOverrideApproachRate, v4);
  if ( v3->mRiseOverrideEnabled )
    v8 = *(float *)&FLOAT_1_0;
  else
    v8 = 0.0;
  UFG::qApproach(&v3->mRiseOverrideParam, v8, UFG::FollowCameraComponent::rRiseOverrideApproachRate, v4);
  v3->rAimWobbleRadiusMin = v3->mBlendedParams.mTweakAimWobbleRadiusMin;
  v3->rAimWobbleRadiusMax = v3->mBlendedParams.mTweakAimWobbleRadiusMax;
  v3->rAimWobbleRadiusPeriod = v3->mBlendedParams.mTweakAimWobbleRadiusPeriod;
  v3->rAimWobbleFreq = v3->mBlendedParams.mTweakAimWobbleFreq;
  v3->rAimWobbleAxisWeight = v3->mBlendedParams.mTweakAimWobbleAxisWeight;
  if ( (unsigned int)(v3->mContext - 5) > 1 )
  {
    v3->mFov.p1 = v3->mBlendedParams.mTweakFov;
    UFG::HomerCubic<float>::MakeCoeffs(&v3->mFov);
    v3->mFov.mParameter = 0.0;
  }
  v9 = v3->mBlendedParams.mTweakVelocityDuration;
  v10 = &v3->mVelocity;
  v11 = v3->mVelocity.mParameter.y / v3->mVelocity.mDuration.y;
  v12 = v3->mVelocity.mParameter.z / v3->mVelocity.mDuration.z;
  v13 = v3->mVelocity.mParameter.x / v3->mVelocity.mDuration.x;
  v10->mParameter.y = v11;
  v10->mParameter.z = v12;
  v10->mParameter.x = v13;
  if ( v9 <= 0.0099999998 )
    v14 = FLOAT_0_0099999998;
  else
    v14 = v9;
  if ( v9 <= 0.0099999998 )
    v15 = FLOAT_0_0099999998;
  else
    v15 = v9;
  if ( v9 <= 0.0099999998 )
    v9 = FLOAT_0_0099999998;
  v3->mVelocity.mDuration.y = v15;
  v10->mDuration.x = v9;
  v3->mVelocity.mDuration.z = v14;
  v16 = v14 * v3->mVelocity.mParameter.z;
  v3->mVelocity.mParameter.x = v9 * v3->mVelocity.mParameter.x;
  v3->mVelocity.mParameter.z = v16;
  v3->mVelocity.mParameter.y = v15 * v11;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v10);
  v17 = &v3->mAimEye;
  v18 = v3->mAimEye.mParameter.y / v3->mAimEye.mDuration.y;
  v19 = v3->mAimEye.mParameter.z / v3->mAimEye.mDuration.z;
  v20 = v3->mAimEye.mParameter.x / v3->mAimEye.mDuration.x;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v21 = UFG::FollowCameraComponent::rAimDurationMouse + v3->mAimDurationSupplimentary;
    v3->mAimEye.mParameter.x = v20;
    v3->mAimEye.mParameter.y = v18;
    v3->mAimEye.mParameter.z = v19;
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
    v3->mAimEye.mDuration.y = v23;
    v17->mDuration.x = v21;
    v3->mAimEye.mDuration.z = v22;
    v24 = v22 * v3->mAimEye.mParameter.z;
    v3->mAimEye.mParameter.x = v21 * v3->mAimEye.mParameter.x;
    v3->mAimEye.mParameter.z = v24;
    v3->mAimEye.mParameter.y = v23 * v18;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v17);
    v25 = &v3->mAimLook;
    v26 = v3->mAimLook.mParameter.y / v3->mAimLook.mDuration.y;
    v27 = v3->mAimLook.mParameter.z / v3->mAimLook.mDuration.z;
    v28 = UFG::FollowCameraComponent::rAimDurationMouse + v3->mAimDurationSupplimentary;
    v29 = v3->mAimLook.mParameter.x / v3->mAimLook.mDuration.x;
    v25->mParameter.y = v26;
    v25->mParameter.z = v27;
    v25->mParameter.x = v29;
    if ( v28 > 0.0099999998 )
    {
      v30 = v28;
      goto LABEL_41;
    }
  }
  else
  {
    v31 = UFG::FollowCameraComponent::rAimDuration + v3->mAimDurationSupplimentary;
    v3->mAimEye.mParameter.x = v20;
    v3->mAimEye.mParameter.y = v18;
    v3->mAimEye.mParameter.z = v19;
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
    v3->mAimEye.mDuration.y = v33;
    v17->mDuration.x = v31;
    v3->mAimEye.mDuration.z = v32;
    v34 = v32 * v3->mAimEye.mParameter.z;
    v3->mAimEye.mParameter.x = v31 * v3->mAimEye.mParameter.x;
    v3->mAimEye.mParameter.z = v34;
    v3->mAimEye.mParameter.y = v33 * v18;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v17);
    v25 = &v3->mAimLook;
    v26 = v3->mAimLook.mParameter.y / v3->mAimLook.mDuration.y;
    v35 = v3->mAimLook.mParameter.z / v3->mAimLook.mDuration.z;
    v28 = UFG::FollowCameraComponent::rAimDuration + v3->mAimDurationSupplimentary;
    v36 = v3->mAimLook.mParameter.x / v3->mAimLook.mDuration.x;
    v25->mParameter.y = v26;
    v25->mParameter.z = v35;
    v25->mParameter.x = v36;
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
  v25->mDuration.x = v28;
  v25->mDuration.y = v37;
  v25->mDuration.z = v30;
  v38 = v30 * v25->mParameter.z;
  v25->mParameter.x = v28 * v25->mParameter.x;
  v25->mParameter.y = v37 * v26;
  v25->mParameter.z = v38;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v25);
  v39 = v3->mTransitionSupplimentaryDuration;
  v40 = v39 * v3->mTransitionParamSuppLook;
  v41 = v39 * v3->mTransitionParamSuppEye;
  v42 = v41 + v3->mBlendedParams.mTweakEyeDurationH;
  v43 = v41 + v3->mBlendedParams.mTweakEyeDurationV;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController
    && v3->mGotoRadiusPatience <= 0.0
    && v3->mGotoAnglePatience <= 0.0
    && v3->mGotoRisePatience <= 0.0 )
  {
    v42 = UFG::FollowCameraComponent::rEyeDurationMouse + v41;
    v43 = UFG::FollowCameraComponent::rEyeDurationMouse + v41;
  }
  v44 = &v3->mEye.mDuration.x;
  v45 = v40 + v3->mBlendedParams.mTweakLookDurationH;
  v46 = v40 + v3->mBlendedParams.mTweakLookDurationV;
  v47 = v3->mEye.mParameter.y / v3->mEye.mDuration.y;
  v48 = v3->mEye.mParameter.z / v3->mEye.mDuration.z;
  v49 = v3->mEye.mParameter.x / v3->mEye.mDuration.x;
  v44[4] = v47;
  v44[3] = v49;
  v44[5] = v48;
  if ( v43 <= 0.0099999998 )
    v43 = FLOAT_0_0099999998;
  if ( v42 <= 0.0099999998 )
    v50 = FLOAT_0_0099999998;
  else
    v50 = v42;
  if ( v42 <= 0.0099999998 )
    v42 = FLOAT_0_0099999998;
  v3->mEye.mDuration.y = v50;
  v3->mEye.mDuration.z = v43;
  *v44 = v42;
  v3->mEye.mParameter.x = v42 * v3->mEye.mParameter.x;
  v3->mEye.mParameter.y = v50 * v47;
  v3->mEye.mParameter.z = v43 * v48;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
  v51 = &v3->mLook.mDuration.x;
  v52 = v3->mLook.mParameter.y / v3->mLook.mDuration.y;
  v53 = v3->mLook.mParameter.z / v3->mLook.mDuration.z;
  v54 = v3->mLook.mParameter.x / v3->mLook.mDuration.x;
  v51[4] = v52;
  v51[5] = v53;
  v51[3] = v54;
  if ( v46 <= 0.0099999998 )
    v46 = FLOAT_0_0099999998;
  if ( v45 <= 0.0099999998 )
    v55 = FLOAT_0_0099999998;
  else
    v55 = v45;
  if ( v45 <= 0.0099999998 )
    v45 = FLOAT_0_0099999998;
  v3->mLook.mDuration.y = v55;
  v3->mLook.mDuration.z = v46;
  *v51 = v45;
  v3->mLook.mParameter.x = v45 * v3->mLook.mParameter.x;
  v3->mLook.mParameter.y = v55 * v52;
  v3->mLook.mParameter.z = v46 * v53;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mLook);
  v56 = &v3->mFov;
  v57 = v41 + v3->mBlendedParams.mTweakFovDuration;
  v58 = v3->mFov.mParameter / v3->mFov.mDuration;
  v3->mFov.mParameter = v58;
  if ( v57 <= 0.0099999998 )
    v57 = FLOAT_0_0099999998;
  v56->mDuration = v57;
  v3->mFov.mParameter = v57 * v58;
  UFG::HomerCubic<float>::MakeCoeffs(v56);
  if ( (unsigned int)(v3->mType - 2) <= 1 )
  {
    v59 = v41;
    v60 = v3->mEye.mParameter.y / v3->mEye.mDuration.y;
    v61 = v3->mEye.mParameter.z / v3->mEye.mDuration.z;
    v62 = v41 + v3->mBlendedParams.mTweakLookDurationV;
    v63 = v59 + v3->mBlendedParams.mTweakLookDurationH;
    v3->mEye.mParameter.x = v3->mEye.mParameter.x / *v44;
    v3->mEye.mParameter.y = v60;
    v3->mEye.mParameter.z = v61;
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
    *v44 = v66;
    v3->mEye.mDuration.y = v65;
    v3->mEye.mDuration.z = v64;
    v67 = v65 * v3->mEye.mParameter.y;
    v68 = v64 * v3->mEye.mParameter.z;
    v3->mEye.mParameter.x = v66 * v3->mEye.mParameter.x;
    v3->mEye.mParameter.y = v67;
    v3->mEye.mParameter.z = v68;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
    v69 = v3->mLook.mParameter.y / v3->mLook.mDuration.y;
    v70 = v3->mLook.mParameter.z / v3->mLook.mDuration.z;
    v71 = v3->mLook.mParameter.x / *v51;
    v3->mLook.mParameter.y = v69;
    v3->mLook.mParameter.z = v70;
    v3->mLook.mParameter.x = v71;
    if ( v62 <= 0.0099999998 )
      v62 = FLOAT_0_0099999998;
    if ( v63 <= 0.0099999998 )
      v72 = FLOAT_0_0099999998;
    else
      v72 = v63;
    if ( v63 <= 0.0099999998 )
      v63 = FLOAT_0_0099999998;
    v3->mLook.mDuration.y = v72;
    v3->mLook.mDuration.z = v62;
    *v51 = v63;
    v3->mLook.mParameter.x = v63 * v3->mLook.mParameter.x;
    v3->mLook.mParameter.y = v72 * v69;
    v3->mLook.mParameter.z = v62 * v70;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mLook);
  }
  if ( v3->mTarget.m_pSimComponent )
  {
    v73 = v3->mBlendedParams.mTweakLatitudeMin;
    v74 = sinf(v3->mBlendedParams.mTweakLatitudeMin);
    v75 = cosf(v73);
    v76 = (float)(v3->mMaxRadiusOverrideParam * v3->mMaxRadiusOverride)
        + (float)((float)(1.0 - v3->mMaxRadiusOverrideParam) * v3->mBlendedParams.mTweakRadiusMax);
    if ( v76 < 0.1 )
      v76 = FLOAT_0_1;
    if ( (float)(v3->mBlendedParams.mTweakOrbitDownRadius / v76) <= 1.0 )
      v6 = v3->mBlendedParams.mTweakOrbitDownRadius / v76;
    v3->mOrbitSquish = v6;
    if ( v6 < 0.1 )
      v3->mOrbitSquish = 0.1;
    if ( v74 >= 0.0 )
      v3->mLatitudeMin = v73;
    else
      v3->mLatitudeMin = atan2f(v74 / v3->mOrbitSquish, v75);
  }
}   v76 = FLOAT_0_1;
    if ( (float)(v3->mBlendedParams.mTweakOrbitDownRadius / v76) <=

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
  UFG::HomerCubic<float> *v1; // rbx
  UFG::FollowCameraComponent *v2; // rdi
  float *v3; // rcx
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float *v8; // rcx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float *v13; // rcx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float *v18; // rcx
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float *v23; // rcx
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm6_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  signed __int64 v32; // rcx
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  signed __int64 v38; // rcx
  float v39; // xmm1_4
  float v40; // xmm2_4
  float *v41; // rcx
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm1_4
  float *v46; // rcx
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm1_4

  v1 = &this->mFov;
  v2 = this;
  *(_QWORD *)&this->mBlend = 0i64;
  this->mAimDurationSupplimentary = 0.0;
  v1->p0 = this->mFov.p1;
  v1->v0 = this->mFov.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  v1->mParameter = 0.0;
  v3 = &v2->mEye.mDuration.x;
  v4 = v2->mEye.p1.y;
  v5 = v2->mEye.p1.z;
  v3[18] = v2->mEye.p1.x;
  v3[19] = v4;
  v3[20] = v5;
  v6 = v2->mEye.v1.y;
  v7 = v2->mEye.v1.z;
  v3[24] = v2->mEye.v1.x;
  v3[25] = v6;
  v3[26] = v7;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
  *(_QWORD *)&v2->mEye.mParameter.x = 0i64;
  v2->mEye.mParameter.z = 0.0;
  v8 = &v2->mLook.mDuration.x;
  v9 = v2->mLook.p1.y;
  v10 = v2->mLook.p1.z;
  v8[18] = v2->mLook.p1.x;
  v8[19] = v9;
  v8[20] = v10;
  v11 = v2->mLook.v1.y;
  v12 = v2->mLook.v1.z;
  v8[24] = v2->mLook.v1.x;
  v8[25] = v11;
  v8[26] = v12;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mLook);
  *(_QWORD *)&v2->mLook.mParameter.x = 0i64;
  v2->mLook.mParameter.z = 0.0;
  v13 = &v2->mVelocity.mDuration.x;
  v14 = v2->mVelocity.p1.y;
  v15 = v2->mVelocity.p1.z;
  v13[18] = v2->mVelocity.p1.x;
  v13[19] = v14;
  v13[20] = v15;
  v16 = v2->mVelocity.v1.y;
  v17 = v2->mVelocity.v1.z;
  v13[24] = v2->mVelocity.v1.x;
  v13[25] = v16;
  v13[26] = v17;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mVelocity);
  *(_QWORD *)&v2->mVelocity.mParameter.x = 0i64;
  v2->mVelocity.mParameter.z = 0.0;
  v18 = &v2->mOffsetLook.mDuration.x;
  v19 = v2->mOffsetLook.p1.y;
  v20 = v2->mOffsetLook.p1.z;
  v18[18] = v2->mOffsetLook.p1.x;
  v18[19] = v19;
  v18[20] = v20;
  v21 = v2->mOffsetLook.v1.y;
  v22 = v2->mOffsetLook.v1.z;
  v18[24] = v2->mOffsetLook.v1.x;
  v18[25] = v21;
  v18[26] = v22;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mOffsetLook);
  *(_QWORD *)&v2->mOffsetLook.mParameter.x = 0i64;
  v2->mOffsetLook.mParameter.z = 0.0;
  v23 = &v2->mOffsetEye.mDuration.x;
  v24 = v2->mOffsetEye.p1.y;
  v25 = v2->mOffsetEye.p1.z;
  v23[18] = v2->mOffsetEye.p1.x;
  v23[19] = v24;
  v23[20] = v25;
  v26 = v2->mOffsetEye.v1.y;
  v27 = v2->mOffsetEye.v1.z;
  v23[24] = v2->mOffsetEye.v1.x;
  v23[25] = v26;
  v23[26] = v27;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mOffsetEye);
  *(_QWORD *)&v2->mOffsetEye.mParameter.x = 0i64;
  v2->mOffsetEye.mParameter.z = 0.0;
  v28 = *(float *)&FLOAT_1_0;
  if ( v2->mMaxRadiusOverrideEnabled )
    v29 = *(float *)&FLOAT_1_0;
  else
    v29 = 0.0;
  v2->mMaxRadiusOverrideParam = v29;
  if ( v2->mRiseOverrideEnabled )
    v30 = *(float *)&FLOAT_1_0;
  else
    v30 = 0.0;
  v2->mRiseOverrideParam = v30;
  *(_QWORD *)&v2->mRecoilAngle = 0i64;
  v31 = UFG::qVector3::msZero.y;
  v32 = (signed __int64)&v2->mRecoilEye;
  v33 = UFG::qVector3::msZero.z;
  *(float *)(v32 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v32 + 88) = v31;
  *(float *)(v32 + 92) = v33;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mRecoilEye);
  *(_QWORD *)&v2->mRecoilEye.mParameter.x = 0i64;
  v2->mRecoilEye.mParameter.z = 0.0;
  v34 = v2->mRecoilEye.p1.y;
  v35 = v2->mRecoilEye.p1.z;
  v2->mRecoilEye.p0.x = v2->mRecoilEye.p1.x;
  v2->mRecoilEye.p0.y = v34;
  v2->mRecoilEye.p0.z = v35;
  v36 = v2->mRecoilEye.v1.y;
  v37 = v2->mRecoilEye.v1.z;
  v2->mRecoilEye.v0.x = v2->mRecoilEye.v1.x;
  v2->mRecoilEye.v0.y = v36;
  v2->mRecoilEye.v0.z = v37;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mRecoilEye);
  *(_QWORD *)&v2->mRecoilEye.mParameter.x = 0i64;
  v2->mRecoilEye.mParameter.z = 0.0;
  *(_QWORD *)&v2->mHorizCompTargetSpeedWindow.m_StartIndex = 0i64;
  v2->mHorizCompTargetSpeedWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&v2->mHorizCompTargetSpeedWindow.m_RunningSum, 0, 4u);
  v38 = (signed __int64)&v2->mHorizCompOffset;
  *(float *)(v38 + 24) = v2->mHorizCompOffset.p1;
  *(float *)(v38 + 32) = v2->mHorizCompOffset.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&v2->mHorizCompOffset);
  v2->mHorizCompOffset.mParameter = 0.0;
  v39 = UFG::qVector3::msDirUp.y;
  v40 = UFG::qVector3::msDirUp.z;
  v2->mUpFrom.x = UFG::qVector3::msDirUp.x;
  v2->mUpFrom.y = v39;
  v2->mUpFrom.z = v40;
  if ( !v2->bAimUseEyeLook )
    v28 = 0.0;
  v2->rAimParameter = v28;
  v41 = &v2->mAimEye.mDuration.x;
  v42 = v2->mAimEye.p1.y;
  v43 = v2->mAimEye.p1.z;
  v41[18] = v2->mAimEye.p1.x;
  v41[19] = v42;
  v41[20] = v43;
  v44 = v2->mAimEye.v1.y;
  v45 = v2->mAimEye.v1.z;
  v41[24] = v2->mAimEye.v1.x;
  v41[25] = v44;
  v41[26] = v45;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimEye);
  *(_QWORD *)&v2->mAimEye.mParameter.x = 0i64;
  v2->mAimEye.mParameter.z = 0.0;
  v46 = &v2->mAimLook.mDuration.x;
  v47 = v2->mAimLook.p1.y;
  v48 = v2->mAimLook.p1.z;
  v46[18] = v2->mAimLook.p1.x;
  v46[19] = v47;
  v46[20] = v48;
  v49 = v2->mAimLook.v1.y;
  v50 = v2->mAimLook.v1.z;
  v46[24] = v2->mAimLook.v1.x;
  v46[25] = v49;
  v46[26] = v50;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimLook);
  *(_QWORD *)&v2->mAimLook.mParameter.x = 0i64;
  v2->mAimLook.mParameter.z = 0.0;
  *(_QWORD *)&v2->mTransitionParamEye = 0i64;
  *(_QWORD *)&v2->mTransitionParamSuppEye = 0i64;
}

// File Line: 1362
// RVA: 0x3CE2A0
void __fastcall UFG::FollowCameraComponent::SnapCurrent(UFG::FollowCameraComponent *this)
{
  UFG::HomerCubic<float> *v1; // rbx
  UFG::FollowCameraComponent *v2; // rdi
  float v3; // eax
  float v4; // eax
  signed __int64 v5; // rcx
  float v6; // xmm1_4
  signed __int64 v7; // rcx
  float v8; // xmm0_4
  float v9; // xmm1_4
  signed __int64 v10; // rcx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // eax
  signed __int64 v14; // rcx
  float v15; // xmm1_4
  signed __int64 v16; // rcx
  float v17; // xmm0_4
  float v18; // xmm1_4
  signed __int64 v19; // rcx
  float v20; // xmm0_4
  float v21; // xmm1_4
  signed __int64 v22; // rcx
  float v23; // eax

  v1 = &this->mFov;
  v2 = this;
  *(_QWORD *)&this->mBlend = 0i64;
  this->mAimDurationSupplimentary = 0.0;
  v3 = this->mFov.p0;
  *(_QWORD *)&v1->v0 = 0i64;
  v1->p1 = v3;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  v1->mParameter = 0.0;
  v4 = v2->mEye.p0.x;
  v5 = (signed __int64)&v2->mEye;
  v6 = v2->mEye.p0.z;
  *(float *)(v5 + 88) = v2->mEye.p0.y;
  *(float *)(v5 + 92) = v6;
  *(float *)(v5 + 84) = v4;
  *(_QWORD *)(v5 + 96) = 0i64;
  *(_QWORD *)(v5 + 104) = 0i64;
  *(_QWORD *)(v5 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
  *(_QWORD *)&v2->mEye.mParameter.x = 0i64;
  v2->mEye.mParameter.z = 0.0;
  v7 = (signed __int64)&v2->mLook;
  v8 = v2->mLook.p0.y;
  v9 = v2->mLook.p0.z;
  *(float *)(v7 + 84) = v2->mLook.p0.x;
  *(float *)(v7 + 88) = v8;
  *(float *)(v7 + 92) = v9;
  *(_QWORD *)(v7 + 96) = 0i64;
  *(_QWORD *)(v7 + 104) = 0i64;
  *(_QWORD *)(v7 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mLook);
  *(_QWORD *)&v2->mLook.mParameter.x = 0i64;
  v2->mLook.mParameter.z = 0.0;
  v10 = (signed __int64)&v2->mVelocity;
  v11 = v2->mVelocity.p0.y;
  v12 = v2->mVelocity.p0.z;
  *(float *)(v10 + 84) = v2->mVelocity.p0.x;
  *(float *)(v10 + 88) = v11;
  *(float *)(v10 + 92) = v12;
  *(_QWORD *)(v10 + 96) = 0i64;
  *(_QWORD *)(v10 + 104) = 0i64;
  *(_QWORD *)(v10 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mVelocity);
  *(_QWORD *)&v2->mVelocity.mParameter.x = 0i64;
  v2->mVelocity.mParameter.z = 0.0;
  v13 = v2->mOffsetLook.p0.x;
  v14 = (signed __int64)&v2->mOffsetLook;
  v15 = v2->mOffsetLook.p0.z;
  *(float *)(v14 + 88) = v2->mOffsetLook.p0.y;
  *(float *)(v14 + 92) = v15;
  *(float *)(v14 + 84) = v13;
  *(_QWORD *)(v14 + 96) = 0i64;
  *(_QWORD *)(v14 + 104) = 0i64;
  *(_QWORD *)(v14 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mOffsetLook);
  *(_QWORD *)&v2->mOffsetLook.mParameter.x = 0i64;
  v2->mOffsetLook.mParameter.z = 0.0;
  v16 = (signed __int64)&v2->mOffsetEye;
  v17 = v2->mOffsetEye.p0.y;
  v18 = v2->mOffsetEye.p0.z;
  *(float *)(v16 + 84) = v2->mOffsetEye.p0.x;
  *(float *)(v16 + 88) = v17;
  *(float *)(v16 + 92) = v18;
  *(_QWORD *)(v16 + 96) = 0i64;
  *(_QWORD *)(v16 + 104) = 0i64;
  *(_QWORD *)(v16 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mOffsetEye);
  *(_QWORD *)&v2->mOffsetEye.mParameter.x = 0i64;
  v2->mOffsetEye.mParameter.z = 0.0;
  v2->mRecoilAngle = v2->mRecoilAngleDesired;
  v19 = (signed __int64)&v2->mRecoilEye;
  v20 = v2->mRecoilEye.p0.y;
  v21 = v2->mRecoilEye.p0.z;
  *(float *)(v19 + 84) = v2->mRecoilEye.p0.x;
  *(float *)(v19 + 88) = v20;
  *(float *)(v19 + 92) = v21;
  *(_QWORD *)(v19 + 96) = 0i64;
  *(_QWORD *)(v19 + 104) = 0i64;
  *(_QWORD *)(v19 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mRecoilEye);
  *(_QWORD *)&v2->mRecoilEye.mParameter.x = 0i64;
  v2->mRecoilEye.mParameter.z = 0.0;
  *(_QWORD *)&v2->mHorizCompTargetSpeedWindow.m_StartIndex = 0i64;
  v2->mHorizCompTargetSpeedWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&v2->mHorizCompTargetSpeedWindow.m_RunningSum, 0, 4u);
  v22 = (signed __int64)&v2->mHorizCompOffset;
  v23 = v2->mHorizCompOffset.p0;
  *(_QWORD *)(v22 + 32) = 0i64;
  *(float *)(v22 + 28) = v23;
  UFG::HomerCubic<float>::MakeCoeffs(&v2->mHorizCompOffset);
  v2->mHorizCompOffset.mParameter = 0.0;
}28) = v23;
  UFG::HomerCubic<float>::MakeCoeffs(&v2->mHorizComp

// File Line: 1381
// RVA: 0x3C5FD0
void __fastcall UFG::FollowCameraComponent::LoadContextParameters(UFG::FollowCameraComponent *this, UFG::FollowCameraComponent::FollowParams *context_parameters, __int64 context_symbol)
{
  UFG::FollowCameraComponent::FollowParams *v3; // rbx
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // rdi
  UFG::qSymbol *v6; // rax
  UFG::qSymbol *v7; // rax
  float *v8; // rax
  float *v9; // rcx
  float v10; // xmm0_4
  UFG::qSymbol tag; // [rsp+58h] [rbp+20h]

  v3 = context_parameters;
  v4 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)context_symbol);
  v5 = v4;
  if ( v4 )
  {
    v3->mTweakFov = *UFG::qPropertySet::Get<float>(v4, (UFG::qSymbol *)&CAMERA_SYMBOL_Fov.mUID, DEPTH_RECURSE);
    v3->mTweakOrbitDownRadius = *UFG::qPropertySet::Get<float>(
                                   v5,
                                   (UFG::qSymbol *)&CAMERA_SYMBOL_OrbitDownRadius.mUID,
                                   DEPTH_RECURSE);
    v3->mTweakEyeRise = *UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_EyeRise.mUID, DEPTH_RECURSE);
    v3->mTweakVelocityDuration = *UFG::qPropertySet::Get<float>(
                                    v5,
                                    (UFG::qSymbol *)&CAMERA_SYMBOL_VelocityDuration.mUID,
                                    DEPTH_RECURSE);
    v3->mTweakLookDurationH = *UFG::qPropertySet::Get<float>(
                                 v5,
                                 (UFG::qSymbol *)&CAMERA_SYMBOL_LookDurationH.mUID,
                                 DEPTH_RECURSE);
    v3->mTweakLookDurationV = *UFG::qPropertySet::Get<float>(
                                 v5,
                                 (UFG::qSymbol *)&CAMERA_SYMBOL_LookDurationV.mUID,
                                 DEPTH_RECURSE);
    v3->mTweakEyeDurationH = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_EyeDurationH.mUID,
                                DEPTH_RECURSE);
    v3->mTweakEyeDurationV = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_EyeDurationV.mUID,
                                DEPTH_RECURSE);
    v3->mTweakFovDuration = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_FovDuration.mUID,
                               DEPTH_RECURSE);
    v3->mTweakOrbitSpeed = *UFG::qPropertySet::Get<float>(
                              v5,
                              (UFG::qSymbol *)&CAMERA_SYMBOL_OrbitSpeed.mUID,
                              DEPTH_RECURSE);
    v3->mTweakRadiusMin = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_RadiusMin.mUID,
                             DEPTH_RECURSE);
    v3->mTweakRadiusMax = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_RadiusMax.mUID,
                             DEPTH_RECURSE);
    v3->mTweakLatitudeMin = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_LatitudeMin.mUID,
                               DEPTH_RECURSE);
    v3->mTweakLatitudeMax = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_LatitudeMax.mUID,
                               DEPTH_RECURSE);
    v3->mTweakVaultLow = *UFG::qPropertySet::Get<float>(
                            v5,
                            (UFG::qSymbol *)&CAMERA_SYMBOL_HighVaultHeight.mUID,
                            DEPTH_RECURSE);
    v3->mTweakLookOffset.x = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_LookOffsetX.mUID,
                                DEPTH_RECURSE);
    v3->mTweakLookOffset.y = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_LookOffsetY.mUID,
                                DEPTH_RECURSE);
    v3->mTweakLookOffset.z = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_LookOffsetZ.mUID,
                                DEPTH_RECURSE);
    v3->mTweakCamThru.x = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_CamThruX.mUID,
                             DEPTH_RECURSE);
    v3->mTweakCamThru.y = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_CamThruY.mUID,
                             DEPTH_RECURSE);
    v3->mTweakCamThru.z = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_CamThruZ.mUID,
                             DEPTH_RECURSE);
    v3->mTweakAimThru.x = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_AimThruX.mUID,
                             DEPTH_RECURSE);
    v3->mTweakAimThru.y = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_AimThruY.mUID,
                             DEPTH_RECURSE);
    v3->mTweakAimThru.z = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_AimThruZ.mUID,
                             DEPTH_RECURSE);
    v3->mTweakBaseOffset.x = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_BaseOffsetX.mUID,
                                DEPTH_RECURSE);
    v3->mTweakBaseOffset.y = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_BaseOffsetY.mUID,
                                DEPTH_RECURSE);
    v3->mTweakBaseOffset.z = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_BaseOffsetZ.mUID,
                                DEPTH_RECURSE);
    v3->mTweakSmoothRatePos = *UFG::qPropertySet::Get<float>(
                                 v5,
                                 (UFG::qSymbol *)&CAMERA_SYMBOL_SmoothRatePos.mUID,
                                 DEPTH_RECURSE);
    v3->mTweakSmoothRateRot = *UFG::qPropertySet::Get<float>(
                                 v5,
                                 (UFG::qSymbol *)&CAMERA_SYMBOL_SmoothRateRot.mUID,
                                 DEPTH_RECURSE);
    v3->mTweakAimRadius = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_AimRadius.mUID,
                             DEPTH_RECURSE);
    v3->mTweakFocusRadius = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_FocusRadius.mUID,
                               DEPTH_RECURSE);
    v3->mTweakTargetedDistance = *UFG::qPropertySet::Get<float>(
                                    v5,
                                    (UFG::qSymbol *)&CAMERA_SYMBOL_TargetedDistance.mUID,
                                    DEPTH_RECURSE);
    v3->mSrcOrientation = 0;
    v6 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_Orientation.mUID, DEPTH_RECURSE);
    if ( v6 )
    {
      tag.mUID = v6->mUID;
      v3->mSrcOrientation = UFG::CharacterSubjectComponent::GetTransformType((UFG::qSymbol)&tag);
    }
    v3->mSrcPosition = 0;
    v7 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_Position.mUID, DEPTH_RECURSE);
    if ( v7 )
    {
      tag.mUID = v7->mUID;
      v3->mSrcPosition = UFG::CharacterSubjectComponent::GetTransformType((UFG::qSymbol)&tag);
    }
    v3->mTweakBlendDurations = *UFG::qPropertySet::Get<bool>(
                                  v5,
                                  (UFG::qSymbol *)&CAMERA_SYMBOL_BlendDurations.mUID,
                                  DEPTH_RECURSE);
    v3->mTweakUseSyncBase = *UFG::qPropertySet::Get<bool>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_UseSyncBase.mUID,
                               DEPTH_RECURSE);
    v3->mUseDofParameters = *UFG::qPropertySet::Get<bool>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_UseDofParameters.mUID,
                               DEPTH_RECURSE);
    v3->mDofInFocusRange = *UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_Dof.mUID, DEPTH_RECURSE);
    v3->mDofNearRange = *UFG::qPropertySet::Get<float>(
                           v5,
                           (UFG::qSymbol *)&CAMERA_SYMBOL_DofNearRange.mUID,
                           DEPTH_RECURSE);
    v3->mDofNearBlurRadius = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_DofNearBlur.mUID,
                                DEPTH_RECURSE);
    v3->mDofFarRange = *UFG::qPropertySet::Get<float>(
                          v5,
                          (UFG::qSymbol *)&CAMERA_SYMBOL_DofFarRange.mUID,
                          DEPTH_RECURSE);
    v3->mDofFarBlurRadius = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_DofFarBlur.mUID,
                               DEPTH_RECURSE);
    v3->mCollisionRise = *UFG::qPropertySet::Get<float>(
                            v5,
                            (UFG::qSymbol *)&CAMERA_SYMBOL_CollisionRise.mUID,
                            DEPTH_RECURSE);
    v3->mTweakNoiseFrequency = *UFG::qPropertySet::Get<float>(
                                  v5,
                                  (UFG::qSymbol *)&CAMERA_SYMBOL_NoiseFrequency.mUID,
                                  DEPTH_RECURSE);
    v3->mTweakNoiseEyeMagnitude = *UFG::qPropertySet::Get<float>(
                                     v5,
                                     (UFG::qSymbol *)&CAMERA_SYMBOL_NoiseEyeMagnitude.mUID,
                                     DEPTH_RECURSE);
    v3->mTweakNoiseLookMagnitude = *UFG::qPropertySet::Get<float>(
                                      v5,
                                      (UFG::qSymbol *)&CAMERA_SYMBOL_NoiseLookMagnitude.mUID,
                                      DEPTH_RECURSE);
    v3->mTweakAimWobbleRadiusMin = *UFG::qPropertySet::Get<float>(
                                      v5,
                                      (UFG::qSymbol *)&CAMERA_SYMBOL_AimWobbleRadiusMin.mUID,
                                      DEPTH_RECURSE);
    v3->mTweakAimWobbleRadiusMax = *UFG::qPropertySet::Get<float>(
                                      v5,
                                      (UFG::qSymbol *)&CAMERA_SYMBOL_AimWobbleRadiusMax.mUID,
                                      DEPTH_RECURSE);
    v3->mTweakAimWobbleRadiusPeriod = *UFG::qPropertySet::Get<float>(
                                         v5,
                                         (UFG::qSymbol *)&CAMERA_SYMBOL_AimWobbleRadiusPeriod.mUID,
                                         DEPTH_RECURSE);
    v3->mTweakAimWobbleFreq = *UFG::qPropertySet::Get<float>(
                                 v5,
                                 (UFG::qSymbol *)&CAMERA_SYMBOL_AimWobbleFreq.mUID,
                                 DEPTH_RECURSE);
    v3->mTweakAimWobbleAxisWeight = *UFG::qPropertySet::Get<float>(
                                       v5,
                                       (UFG::qSymbol *)&CAMERA_SYMBOL_AimWobbleAxisWeight.mUID,
                                       DEPTH_RECURSE);
    v3->mUseInitRise = *UFG::qPropertySet::Get<bool>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_UseInitRise.mUID, DEPTH_RECURSE);
    v3->mInitRise = *UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_InitRise.mUID, DEPTH_RECURSE);
    v3->mInitRiseRate = *UFG::qPropertySet::Get<float>(
                           v5,
                           (UFG::qSymbol *)&CAMERA_SYMBOL_InitRiseRate.mUID,
                           DEPTH_RECURSE);
    v3->mInitRisePatience = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_InitRisePatience.mUID,
                               DEPTH_RECURSE);
    v3->mUseInitRadius = *UFG::qPropertySet::Get<bool>(
                            v5,
                            (UFG::qSymbol *)&CAMERA_SYMBOL_UseInitRadius.mUID,
                            DEPTH_RECURSE);
    v3->mInitRadius = *UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_InitRadius.mUID, DEPTH_RECURSE);
    v3->mInitRadiusRate = *UFG::qPropertySet::Get<float>(
                             v5,
                             (UFG::qSymbol *)&CAMERA_SYMBOL_InitRadiusRate.mUID,
                             DEPTH_RECURSE);
    v3->mInitRadiusPatience = *UFG::qPropertySet::Get<float>(
                                 v5,
                                 (UFG::qSymbol *)&CAMERA_SYMBOL_InitRadiusPatience.mUID,
                                 DEPTH_RECURSE);
    v3->mUseInitAngle = *UFG::qPropertySet::Get<bool>(
                           v5,
                           (UFG::qSymbol *)&CAMERA_SYMBOL_UseInitAngle.mUID,
                           DEPTH_RECURSE);
    v3->mInitAngle = *UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_InitAngle.mUID, DEPTH_RECURSE);
    v3->mInitAngleRate = *UFG::qPropertySet::Get<float>(
                            v5,
                            (UFG::qSymbol *)&CAMERA_SYMBOL_InitAngleRate.mUID,
                            DEPTH_RECURSE);
    v3->mInitAnglePatience = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_InitAnglePatience.mUID,
                                DEPTH_RECURSE);
    v3->mInitAngleWorldSpace = *UFG::qPropertySet::Get<bool>(
                                  v5,
                                  (UFG::qSymbol *)&CAMERA_SYMBOL_InitAngleWorldSpace.mUID,
                                  DEPTH_RECURSE);
    v3->mInitAngleUseSecond = *UFG::qPropertySet::Get<bool>(
                                 v5,
                                 (UFG::qSymbol *)&CAMERA_SYMBOL_InitAngleUseSecond.mUID,
                                 DEPTH_RECURSE);
    v3->mInitAngleSecond = *UFG::qPropertySet::Get<float>(
                              v5,
                              (UFG::qSymbol *)&CAMERA_SYMBOL_InitAngleSecond.mUID,
                              DEPTH_RECURSE);
    v3->mYawRestrict = *UFG::qPropertySet::Get<bool>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_YawRestrict.mUID, DEPTH_RECURSE);
    v3->mYawConstrainRate = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_YawConstrainRate.mUID,
                               DEPTH_RECURSE);
    v3->mYawMin = *UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_YawMin.mUID, DEPTH_RECURSE);
    v3->mYawMax = *UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_YawMax.mUID, DEPTH_RECURSE);
    v3->mUseLookUpDown = *UFG::qPropertySet::Get<bool>(
                            v5,
                            (UFG::qSymbol *)&CAMERA_SYMBOL_UseLookUpDown.mUID,
                            DEPTH_RECURSE);
    v3->mHorizCompUseDirection = *UFG::qPropertySet::Get<bool>(
                                    v5,
                                    (UFG::qSymbol *)&CAMERA_SYMBOL_HorizCompUseDirection.mUID,
                                    DEPTH_RECURSE);
    v3->mHorizCompOffsetScale = *UFG::qPropertySet::Get<float>(
                                   v5,
                                   (UFG::qSymbol *)&CAMERA_SYMBOL_HorizCompOffsetScale.mUID,
                                   DEPTH_RECURSE);
    v3->mHorizCompSpeedWindowTimespan = *UFG::qPropertySet::Get<float>(
                                           v5,
                                           (UFG::qSymbol *)&CAMERA_SYMBOL_HorizCompSpeedWindowTimespan.mUID,
                                           DEPTH_RECURSE);
    v3->mHorizCompSpeedMin = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_HorizCompSpeedMin.mUID,
                                DEPTH_RECURSE);
    v3->mHorizCompSpeedMax = *UFG::qPropertySet::Get<float>(
                                v5,
                                (UFG::qSymbol *)&CAMERA_SYMBOL_HorizCompSpeedMax.mUID,
                                DEPTH_RECURSE);
    v3->mHorizCompDurationAttack = *UFG::qPropertySet::Get<float>(
                                      v5,
                                      (UFG::qSymbol *)&CAMERA_SYMBOL_HorizCompDurationAttack.mUID,
                                      DEPTH_RECURSE);
    v3->mHorizCompDurationDecay = *UFG::qPropertySet::Get<float>(
                                     v5,
                                     (UFG::qSymbol *)&CAMERA_SYMBOL_HorizCompDurationDecay.mUID,
                                     DEPTH_RECURSE);
    v3->mDesaturation = *UFG::qPropertySet::Get<float>(
                           v5,
                           (UFG::qSymbol *)&CAMERA_SYMBOL_Desaturation.mUID,
                           DEPTH_RECURSE);
    v3->mDamageMultiplier = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&CAMERA_SYMBOL_DamageMultiplier.mUID,
                               DEPTH_RECURSE);
    v3->mMotionblurMagnitude = *UFG::qPropertySet::Get<float>(
                                  v5,
                                  (UFG::qSymbol *)&CAMERA_SYMBOL_MotionblurMagnitude.mUID,
                                  DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&CAMERA_SYMBOL_FovMax.mUID, DEPTH_RECURSE);
    v9 = &v3->mTweakFov;
    if ( v8 )
      v9 = v8;
    v10 = v3->mTweakFov;
    if ( v3->mTweakFov <= *v9 )
      v10 = *v9;
    v3->mTweakFovMax = v10;
  }
}

// File Line: 1499
// RVA: 0x3C6960
void __fastcall UFG::FollowCameraComponent::LoadContextParameters(UFG::FollowCameraComponent *this)
{
  UFG::FollowCameraComponent *v1; // r14
  signed int v2; // ebx
  __int64 v3; // rdi
  __int64 v4; // r8
  UFG::qString *v5; // rax
  UFG::qSymbol *v6; // rbx
  const char **v7; // rdi
  UFG::FollowCameraComponent::FollowParams *v8; // rsi
  signed __int64 v9; // rbp
  UFG::qString *v10; // rax
  UFG::qString result; // [rsp+28h] [rbp-50h]
  UFG::qSymbol context_symbol; // [rsp+88h] [rbp+10h]
  UFG::qSymbol v13; // [rsp+90h] [rbp+18h]
  UFG::qSymbol *v14; // [rsp+98h] [rbp+20h]

  v1 = this;
  v2 = 0;
  v3 = 0i64;
  v14 = &context_symbol;
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
    UFG::FollowCameraComponent::LoadContextParameters(v1, &v1->mContextParameters[v2], (__int64)&context_symbol);
    UFG::FollowCameraComponent::mContextParameterSymbols[v3] = v13;
    ++v2;
    ++v3;
  }
  while ( v2 < 15 );
  v14 = &context_symbol;
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
    UFG::FollowCameraComponent::LoadContextParameters(v1, v8, (__int64)&context_symbol);
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
void __usercall UFG::FollowCameraComponent::SetAimDeadZone(UFG::FollowCameraComponent *this@<rcx>, float fraction_fov@<xmm1>, float a3@<xmm0>)
{
  UFG::FollowCameraComponent *v3; // rbx
  __m128 v4; // xmm3

  v3 = this;
  ((void (*)(void))this->vfptr[19].__vecDelDtor)();
  v4 = (__m128)LODWORD(v3->mAimDeadZoneCentre.y);
  v4.m128_f32[0] = (float)((float)((float)(v4.m128_f32[0] - v3->mEye.p0.y) * (float)(v4.m128_f32[0] - v3->mEye.p0.y))
                         + (float)((float)(v3->mAimDeadZoneCentre.x - v3->mEye.p0.x)
                                 * (float)(v3->mAimDeadZoneCentre.x - v3->mEye.p0.x)))
                 + (float)((float)(v3->mAimDeadZoneCentre.z - v3->mEye.p0.z)
                         * (float)(v3->mAimDeadZoneCentre.z - v3->mEye.p0.z));
  v3->mAimDeadZoneRadius = COERCE_FLOAT(_mm_sqrt_ps(v4)) * tanf(a3 * fraction_fov);
}

// File Line: 1564
// RVA: 0x3C9FA0
void __fastcall UFG::FollowCameraComponent::SetContext(UFG::FollowCameraComponent *this, UFG::FollowCameraContext context, bool force_set)
{
  char v3; // r13
  __int64 v4; // rbx
  UFG::FollowCameraComponent *v5; // rdi
  int v6; // ebp
  bool v7; // si
  char v8; // r15
  UFG::CharacterSubjectComponent *v9; // rcx
  int v10; // er8
  __int64 v11; // r14
  UFG::qPropertySet *v12; // r12
  UFG::FollowCameraContext v13; // edx
  UFG::FollowCameraType v14; // eax
  char *v15; // rbx
  char v16; // cl
  const char **v17; // rsi
  UFG::qSymbol *v18; // rbx
  hkSeekableStreamReader *v19; // rbp
  signed __int64 v20; // r15
  __int128 v21; // xmm6
  unsigned int v22; // eax
  float v23; // xmm13_4
  bool v24; // zf
  UFG::qString *v25; // rax
  float v26; // xmm0_4
  bool v27; // dl
  signed __int64 v28; // rcx
  float v29; // xmm3_4
  float v30; // xmm5_4
  signed __int64 v31; // rax
  float v32; // xmm3_4
  float v33; // xmm5_4
  signed __int64 v34; // rax
  float v35; // xmm3_4
  float v36; // xmm5_4
  signed __int64 v37; // rax
  float v38; // xmm3_4
  float v39; // xmm5_4
  float v40; // xmm6_4
  float v41; // xmm8_4
  float v42; // xmm0_4
  __m128 v43; // xmm9
  __m128 v44; // xmm7
  float v45; // xmm6_4
  float v46; // xmm1_4
  float v47; // xmm12_4
  signed __int64 v48; // rbx
  __m128 v49; // xmm8
  float v50; // xmm12_4
  __m128 v51; // xmm11
  float v52; // xmm14_4
  float v53; // xmm12_4
  __m128 v54; // xmm1
  float v55; // xmm6_4
  float v56; // xmm7_4
  float v57; // xmm8_4
  float v58; // xmm9_4
  float v59; // xmm6_4
  float v60; // xmm8_4
  float v61; // xmm9_4
  float v62; // xmm3_4
  float v63; // xmm9_4
  float v64; // xmm0_4
  float v65; // xmm1_4
  float *v66; // rbx
  signed __int64 v67; // rbx
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm4_4
  float v71; // xmm3_4
  __m128 v72; // xmm2
  __m128 v73; // xmm5
  float v74; // xmm1_4
  float v75; // xmm2_4
  float v76; // xmm6_4
  float *v77; // rbx
  Render::DebugDrawContext *v78; // rbx
  UFG::CharacterSubjectComponent::SrcTransform v79; // ecx
  __m128 v80; // xmm1
  float v81; // xmm0_4
  float v82; // xmm3_4
  float v83; // xmm2_4
  float v84; // xmm0_4
  float v85; // xmm0_4
  bool v86; // si
  bool v87; // dl
  float v88; // xmm1_4
  bool v89; // al
  float v90; // xmm8_4
  float v91; // xmm9_4
  float v92; // xmm6_4
  float v93; // xmm7_4
  signed __int64 v94; // [rsp+30h] [rbp-138h]
  UFG::qSymbol *v95; // [rsp+38h] [rbp-130h]
  UFG::qString v96; // [rsp+40h] [rbp-128h]
  UFG::qString v97; // [rsp+68h] [rbp-100h]
  UFG::qSymbol propSetName; // [rsp+170h] [rbp+8h]
  UFG::qSymbol result; // [rsp+178h] [rbp+10h]
  UFG::qSymbol context_symbol; // [rsp+180h] [rbp+18h]
  char *rhs; // [rsp+188h] [rbp+20h]

  LOBYTE(context_symbol.mUID) = force_set;
  v94 = -2i64;
  v3 = force_set;
  v4 = context;
  v5 = this;
  v6 = (unsigned int)(context - 4) <= 3 || context == 12;
  v7 = this->mContext != context;
  v8 = 0;
  if ( this->mTarget.m_pSimComponent )
  {
    v9 = (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent;
    v10 = v9->mTypeOverrideFreeman;
    if ( v10 != -1 && context != 5 )
    {
      v6 = v9->mTypeOverrideFreeman;
      UFG::CharacterSubjectComponent::GetContextOverride(v9, &result, v10);
      if ( v7 || result.mUID != UFG::FollowCameraComponent::mContextParameterSymbols[v4].mUID )
        v7 = 1;
      UFG::FollowCameraComponent::mContextParameterSymbols[v4] = result;
      v8 = 1;
    }
  }
  if ( (unsigned int)(v4 - 11) <= 1 )
  {
    UFG::CharacterSubjectComponent::GetContextOverride(
      (UFG::CharacterSubjectComponent *)v5->mTarget.m_pSimComponent,
      &result,
      v6);
    if ( v7 || result.mUID != UFG::FollowCameraComponent::mContextParameterSymbols[v4].mUID )
      v7 = 1;
    UFG::FollowCameraComponent::mContextParameterSymbols[v4] = result;
    v8 = 1;
  }
  if ( v3 || v7 )
  {
    v11 = v4;
    propSetName.mUID = UFG::FollowCameraComponent::mContextParameterSymbols[v4].mUID;
    v12 = UFG::PropertySetManager::GetPropertySet(&propSetName);
    if ( v12 )
    {
      v13 = v5->mContext;
      LOBYTE(result.mUID) = (unsigned int)(v13 - 5) <= 1;
      v14 = v6;
      if ( !v3 )
        v14 = v5->mType;
      v5->mPreviousType = v14;
      if ( v3 )
        v13 = (signed int)v4;
      v5->mPreviousContext = v13;
      v5->mType = v6;
      v5->mContext = v4;
      v15 = (char *)UFG::FollowCameraComponent::mContextParameterNames[v13];
      rhs = (char *)UFG::FollowCameraComponent::mContextParameterNames[v13];
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
            UFG::qMemCopy(&v5->mContextParameters[v11], v19, 0x13Cu);
            UFG::FollowCameraComponent::mContextParameterNames[v11] = *v17;
            v16 = 1;
          }
          v19 = (hkSeekableStreamReader *)((char *)v19 + 316);
          ++v18;
          ++v17;
          --v20;
        }
        while ( v20 );
        v3 = context_symbol.mUID;
        if ( !v16 )
        {
          v95 = &context_symbol;
          context_symbol.mUID = UFG::FollowCameraComponent::mContextParameterSymbols[0].mUID;
          UFG::FollowCameraComponent::LoadContextParameters(v5, &v5->mContextParameters[v11], (__int64)&context_symbol);
          UFG::FollowCameraComponent::mContextParameterNames[v11] = UFG::FollowCameraComponent::mDefaultOverrideName;
        }
        v15 = rhs;
      }
      UFG::FollowCameraComponent::InitBlendedParams(v5);
      UFG::FollowCameraComponent::UpdateTweaker(v5, 0.0);
      UFG::FollowCameraComponent::Rotate(v5, 0.0, 0.0);
      LODWORD(v21) = 0;
      v22 = v5->mContext - 5;
      v23 = *(float *)&FLOAT_1_0;
      v24 = LOBYTE(result.mUID) == v22 <= 1;
      v5->mSnapNext = LOBYTE(result.mUID) ^ (v22 <= 1);
      if ( !v24 )
        goto LABEL_121;
      UFG::qString::qString(&v97, "TransitionFrom");
      UFG::operator+(&v96, v25, v15);
      UFG::qString::~qString(&v97);
      UFG::qSymbol::create_from_string(&context_symbol, v96.mData);
      if ( UFG::qPropertySet::PropertyExists(v12, &context_symbol, DEPTH_RECURSE) )
      {
        v21 = *(unsigned int *)UFG::qPropertySet::Get<float>(v12, &context_symbol, DEPTH_RECURSE);
        UFG::qSPrintf(gTransitionString, 127, "Transition From %s: %f", v15, *(float *)&v21);
      }
      else if ( UFG::qPropertySet::PropertyExists(
                  v12,
                  (UFG::qSymbol *)&CAMERA_SYMBOL_TransitionTime.mUID,
                  DEPTH_RECURSE) )
      {
        v21 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                                 v12,
                                 (UFG::qSymbol *)&CAMERA_SYMBOL_TransitionTime.mUID,
                                 DEPTH_RECURSE);
        UFG::qSPrintf(gTransitionString, 127, "Transition Time: %f", *(float *)&v21);
      }
      v26 = v5->mTransitionTimeOverride;
      if ( v26 != -1.0 && *(float *)&v21 != 0.0 )
      {
        *(float *)&v21 = v5->mTransitionTimeOverride;
        v5->mTransitionTimeOverride = -1.0;
        UFG::qSPrintf(gTransitionString, 127, "Transition Time Override: %f", v26);
      }
      if ( UFG::gTweakOverrideTransitionTimeEnable )
        *(float *)&v21 = UFG::gTweakOverrideTransitionTime;
      UFG::qString::~qString(&v96);
      if ( *(float *)&v21 > 0.0 )
      {
        v5->mBlend = 1.0;
        if ( *(float *)&v21 <= 0.001 )
          *(float *)&v21 = FLOAT_0_001;
        v5->mBlendRate = 1.0 / *(float *)&v21;
        if ( !(_S9_8 & 1) )
        {
          _S9_8 |= 1u;
          UFG::qSymbol::create_from_string(&contextSymbolLeap, "Cameras-FollowCameraLeap");
          atexit(UFG::FollowCameraComponent::SetContext_::_44_::_dynamic_atexit_destructor_for__contextSymbolLeap__);
        }
        v27 = UFG::qStringFind(v15, "POI") != 0i64;
        v28 = v5->mContext;
        if ( v5->mType != 1
          && propSetName.mUID != contextSymbolLeap.mUID
          && (!v27 || v5->mOldParams.mSrcPosition != v5->mContextParameters[v28].mSrcPosition) )
        {
          v29 = v5->mOldParams.mTweakCamThru.y
              - (float)(v5->mOldParams.mTweakCamThru.y - v5->mContextParameters[v28].mTweakCamThru.y);
          v30 = v5->mOldParams.mTweakCamThru.z
              - (float)(v5->mOldParams.mTweakCamThru.z - v5->mContextParameters[v28].mTweakCamThru.z);
          v5->mOldParams.mTweakCamThru.x = v5->mOldParams.mTweakCamThru.x
                                         - (float)(v5->mOldParams.mTweakCamThru.x
                                                 - v5->mContextParameters[v28].mTweakCamThru.x);
          v5->mOldParams.mTweakCamThru.y = v29;
          v5->mOldParams.mTweakCamThru.z = v30;
          v31 = v5->mContext;
          v32 = v5->mOldParams.mTweakLookOffset.y
              - (float)(v5->mOldParams.mTweakLookOffset.y - v5->mContextParameters[v31].mTweakLookOffset.y);
          v33 = v5->mOldParams.mTweakLookOffset.z
              - (float)(v5->mOldParams.mTweakLookOffset.z - v5->mContextParameters[v31].mTweakLookOffset.z);
          v5->mOldParams.mTweakLookOffset.x = v5->mOldParams.mTweakLookOffset.x
                                            - (float)(v5->mOldParams.mTweakLookOffset.x
                                                    - v5->mContextParameters[v31].mTweakLookOffset.x);
          v5->mOldParams.mTweakLookOffset.y = v32;
          v5->mOldParams.mTweakLookOffset.z = v33;
          v34 = v5->mContext;
          v35 = v5->mOldParams.mTweakAimThru.y
              - (float)(v5->mOldParams.mTweakAimThru.y - v5->mContextParameters[v34].mTweakAimThru.y);
          v36 = v5->mOldParams.mTweakAimThru.z
              - (float)(v5->mOldParams.mTweakAimThru.z - v5->mContextParameters[v34].mTweakAimThru.z);
          v5->mOldParams.mTweakAimThru.x = v5->mOldParams.mTweakAimThru.x
                                         - (float)(v5->mOldParams.mTweakAimThru.x
                                                 - v5->mContextParameters[v34].mTweakAimThru.x);
          v5->mOldParams.mTweakAimThru.y = v35;
          v5->mOldParams.mTweakAimThru.z = v36;
          v37 = v5->mContext;
          v38 = v5->mOldParams.mTweakBaseOffset.y
              - (float)(v5->mOldParams.mTweakBaseOffset.y - v5->mContextParameters[v37].mTweakBaseOffset.y);
          v39 = v5->mOldParams.mTweakBaseOffset.z
              - (float)(v5->mOldParams.mTweakBaseOffset.z - v5->mContextParameters[v37].mTweakBaseOffset.z);
          v5->mOldParams.mTweakBaseOffset.x = v5->mOldParams.mTweakBaseOffset.x
                                            - (float)(v5->mOldParams.mTweakBaseOffset.x
                                                    - v5->mContextParameters[v37].mTweakBaseOffset.x);
          v5->mOldParams.mTweakBaseOffset.y = v38;
          v5->mOldParams.mTweakBaseOffset.z = v39;
        }
      }
      else
      {
LABEL_121:
        *(_QWORD *)&v5->mBlend = 0i64;
        UFG::FollowCameraComponent::FollowParams::operator=(&v5->mBlendedParams, &v5->mContextParameters[v5->mContext]);
        v5->mSnapNext = 1;
        UFG::qSPrintf(gTransitionString, 127, "Transition Snap");
      }
      if ( v3 )
      {
        UFG::FollowCameraComponent::FollowParams::operator=(&v5->mBlendedParams, &v5->mContextParameters[v5->mContext]);
        UFG::FollowCameraComponent::FollowParams::operator=(&v5->mOldParams, &v5->mBlendedParams);
      }
      if ( v5->mType == eFOLLOW_CAMERA_TYPE_TOW && (unsigned int)(v5->mPreviousType - 1) <= 1 )
      {
        v5->mMouseBoomSet = 0;
        v40 = atan2f(
                COERCE_FLOAT(LODWORD(v5->mControllerForward.y) ^ _xmm[0]),
                COERCE_FLOAT(LODWORD(v5->mControllerForward.x) ^ _xmm[0]));
        v41 = sinf(v40);
        v42 = cosf(v40);
        v43 = (__m128)LODWORD(v5->mBlendedParams.mTweakCamThru.x);
        v44 = (__m128)LODWORD(v5->mBlendedParams.mTweakCamThru.x);
        v45 = (float)((float)(v5->mBlendedParams.mTweakCamThru.x * v41) + v5->mTargetWorld.v3.y)
            + (float)(v5->mBlendedParams.mTweakCamThru.y * v42);
        v43.m128_f32[0] = (float)((float)(v43.m128_f32[0] * v42) + v5->mTargetWorld.v3.x)
                        + (float)(COERCE_FLOAT(LODWORD(v41) ^ _xmm[0]) * v5->mBlendedParams.mTweakCamThru.y);
        v44.m128_f32[0] = (float)((float)((float)(v44.m128_f32[0] * 0.0) + v5->mTargetWorld.v3.z)
                                + (float)(v5->mBlendedParams.mTweakCamThru.y * 0.0))
                        + v5->mBlendedParams.mTweakCamThru.z;
        v46 = (float)((float)(1.0 - v5->mMaxRadiusOverrideParam) * v5->mBlendedParams.mTweakRadiusMax)
            + (float)(v5->mMaxRadiusOverrideParam * v5->mMaxRadiusOverride);
        v49 = v44;
        v49.m128_f32[0] = v44.m128_f32[0] + (float)((float)(v5->mAimEye.p1.z - v5->mAimLook.p1.z) * v46);
        v47 = v45 + (float)((float)(v5->mAimEye.p1.y - v5->mAimLook.p1.y) * v46);
        v51 = v43;
        v51.m128_f32[0] = v43.m128_f32[0] + (float)((float)(v5->mAimEye.p1.x - v5->mAimLook.p1.x) * v46);
        v48 = (signed __int64)&v5->mLook;
        *(_DWORD *)(v48 + 84) = v43.m128_i32[0];
        *(float *)(v48 + 88) = v45;
        *(_DWORD *)(v48 + 92) = v44.m128_i32[0];
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mLook);
        *(_QWORD *)&v5->mLook.mParameter.x = 0i64;
        v5->mLook.mParameter.z = 0.0;
        v49.m128_f32[0] = v49.m128_f32[0] - v44.m128_f32[0];
        v50 = v47 - v45;
        v51.m128_f32[0] = v51.m128_f32[0] - v43.m128_f32[0];
        if ( v49.m128_f32[0] < 0.0 )
          v49.m128_f32[0] = v49.m128_f32[0] / v5->mOrbitSquish;
        v52 = atan2f(v50, v51.m128_f32[0]);
        v53 = v50 * v50;
        v51.m128_f32[0] = v51.m128_f32[0] * v51.m128_f32[0];
        v54 = v51;
        v54.m128_f32[0] = v51.m128_f32[0] + v53;
        v55 = atan2f(v49.m128_f32[0], COERCE_FLOAT(_mm_sqrt_ps(v54))) + UFG::FollowCameraComponent::rAimReturnPitch;
        if ( v55 <= v5->mLatitudeMin )
          v55 = v5->mLatitudeMin;
        if ( v55 >= v5->mBlendedParams.mTweakLatitudeMax )
          v55 = v5->mBlendedParams.mTweakLatitudeMax;
        v49.m128_f32[0] = (float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v51.m128_f32[0] + v53);
        LODWORD(v56) = (unsigned __int128)_mm_sqrt_ps(v49);
        v57 = sinf(v55);
        v58 = cosf(v55);
        v59 = sinf(v52);
        v60 = v57 * v56;
        v61 = v58 * v56;
        v62 = v61 * cosf(v52);
        v63 = v61 * v59;
        if ( v60 < 0.0 )
          v60 = v60 * v5->mOrbitSquish;
        v64 = v5->mLook.p1.z + v60;
        v65 = v5->mLook.p1.y + v63;
        v66 = &v5->mEye.mDuration.x;
        v66[21] = v5->mLook.p1.x + v62;
        v66[22] = v65;
        v66[23] = v64;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mEye);
        *(_QWORD *)&v5->mEye.mParameter.x = 0i64;
        v5->mEye.mParameter.z = 0.0;
        v67 = (signed __int64)&v5->mVelocity;
        v68 = UFG::qVector3::msZero.y;
        v69 = UFG::qVector3::msZero.z;
        *(float *)(v67 + 84) = UFG::qVector3::msZero.x;
        *(float *)(v67 + 88) = v68;
        *(float *)(v67 + 92) = v69;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mVelocity);
        *(_QWORD *)&v5->mVelocity.mParameter.x = 0i64;
        v5->mVelocity.mParameter.z = 0.0;
        v72 = (__m128)LODWORD(v5->mEye.p1.x);
        v70 = v5->mEye.p1.z - v5->mLook.p1.z;
        v71 = v5->mEye.p1.y - v5->mLook.p1.y;
        v72.m128_f32[0] = v72.m128_f32[0] - v5->mLook.p1.x;
        v73 = v72;
        v73.m128_f32[0] = (float)((float)(v72.m128_f32[0] * v72.m128_f32[0]) + (float)(v71 * v71)) + (float)(v70 * v70);
        if ( v73.m128_f32[0] == 0.0 )
          v74 = 0.0;
        else
          v74 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v73));
        v5->mControllerForward.x = v72.m128_f32[0] * v74;
        v5->mControllerForward.y = v71 * v74;
        v5->mControllerForward.z = v70 * v74;
        if ( v5->mPreviousContext == 6 )
          v5->mSnapNext = 1;
      }
      UFG::FollowCameraComponent::UpdateLocalWorld(v5, 0.0);
      if ( v5->mTarget.m_pSimComponent && v5->mSnapNext )
      {
        v75 = (float)((float)((float)(v5->mBlendedParams.mTweakCamThru.y * v5->mTargetWorld.v1.y)
                            + (float)(v5->mBlendedParams.mTweakCamThru.x * v5->mTargetWorld.v0.y))
                    + (float)(v5->mBlendedParams.mTweakCamThru.z * v5->mTargetWorld.v2.y))
            + v5->mTargetWorld.v3.y;
        v76 = (float)((float)((float)(v5->mBlendedParams.mTweakCamThru.y * v5->mTargetWorld.v1.z)
                            + (float)(v5->mBlendedParams.mTweakCamThru.x * v5->mTargetWorld.v0.z))
                    + (float)(v5->mBlendedParams.mTweakCamThru.z * v5->mTargetWorld.v2.z))
            + v5->mTargetWorld.v3.z;
        v77 = &v5->mLook.mDuration.x;
        v77[21] = (float)((float)((float)(v5->mBlendedParams.mTweakCamThru.y * v5->mTargetWorld.v1.x)
                                + (float)(v5->mBlendedParams.mTweakCamThru.x * v5->mTargetWorld.v0.x))
                        + (float)(v5->mBlendedParams.mTweakCamThru.z * v5->mTargetWorld.v2.x))
                + v5->mTargetWorld.v3.x;
        v77[22] = v75;
        v77[23] = v76;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mLook);
        *(_QWORD *)&v5->mLook.mParameter.x = 0i64;
        v5->mLook.mParameter.z = 0.0;
      }
      v78 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      if ( !v5->mBlendedParams.mUseInitRise )
        goto LABEL_96;
      v5->mGotoRiseElaspedTime = 0.0;
      v5->mGotoRisePatience = v5->mBlendedParams.mInitRisePatience;
      v5->mGotoRiseRate = v5->mBlendedParams.mInitRiseRate;
      if ( !v5->mAutoFrameActive
        || v5->mBlendedParams.mSrcOrientation == 4
        || (v79 = v5->mBlendedParams.mSrcPosition, v79 == 4) )
      {
        v5->mGotoRise = v5->mBlendedParams.mInitRise;
LABEL_94:
        if ( UFG::bCameraDebugText )
        {
          Render::DebugDrawContext::DrawTextA(
            v78,
            640,
            464,
            &UFG::qColour::White,
            "Init EyeRise: %f",
            v5->mBlendedParams.mInitRise,
            -2i64,
            v95);
          Render::DebugDrawContext::DrawTextA(
            v78,
            640,
            476,
            &UFG::qColour::White,
            "AutoFramed InitRise: %f",
            v5->mRiseOverride);
        }
LABEL_96:
        if ( v5->mBlendedParams.mUseInitRadius )
        {
          v5->mGotoRadiusElaspedTime = 0.0;
          v5->mGotoRadiusPatience = v5->mBlendedParams.mInitRadiusPatience;
          v5->mGotoRadiusRate = v5->mBlendedParams.mInitRadiusRate;
          v85 = v5->mBlendedParams.mInitRadius;
          v5->mGotoRadius = v85;
          if ( UFG::bCameraDebugText )
            Render::DebugDrawContext::DrawTextA(
              v78,
              640,
              488,
              &UFG::qColour::White,
              "Goto InitRadius:%f",
              v85,
              v94,
              v95);
        }
        v86 = v5->mBlendedParams.mUseInitAngle;
        if ( !(_S9_8 & 2) )
        {
          _S9_8 |= 2u;
          UFG::qSymbol::create_from_string(&contextSymbolSprint, "Cameras-FollowCameraSprint");
          atexit(UFG::FollowCameraComponent::SetContext_::_88_::_dynamic_atexit_destructor_for__contextSymbolSprint__);
        }
        v87 = v5->mType == eFOLLOW_CAMERA_TYPE_TOW
           && UFG::FollowCameraComponent::mContextParameterSymbols[v5->mContext].mUID == contextSymbolSprint.mUID;
        if ( (!UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController || !v87) && v86 )
        {
          v5->mGotoAngleElaspedTime = 0.0;
          v5->mGotoAnglePatience = v5->mBlendedParams.mInitAnglePatience;
          v5->mGotoAngleRate = (float)(v5->mBlendedParams.mInitAngleRate * 3.1415927) * 0.0055555557;
          v88 = (float)(v5->mBlendedParams.mInitAngle * 3.1415927) * 0.0055555557;
          v5->mGotoAngle = v88;
          v89 = v5->mBlendedParams.mInitAngleWorldSpace == 0;
          v5->mGotoAngleLocalSpace = v89;
          if ( v5->mBlendedParams.mInitAngleUseSecond )
            v5->mGotoAngle = UFG::FollowCameraComponent::GetClosestAngle(
                               v5,
                               v88,
                               (float)(v5->mBlendedParams.mInitAngleSecond * 3.1415927) * 0.0055555557,
                               v89 == 0,
                               0);
          if ( UFG::bCameraDebugText )
            Render::DebugDrawContext::DrawTextA(
              v78,
              640,
              500,
              &UFG::qColour::White,
              "Goto InitAngle:%f",
              v5->mGotoAngle,
              v94,
              v95);
        }
        if ( v5->mType != 1 )
          goto LABEL_122;
        if ( v5->mPreviousType != 1 )
        {
          v90 = v5->mBlendedParams.mTweakBaseOffset.x;
          v91 = v5->mBlendedParams.mTweakBaseOffset.y;
          v92 = v5->mOldParams.mTweakBaseOffset.x;
          v93 = v5->mOldParams.mTweakBaseOffset.y;
          UFG::FollowCameraComponent::FollowParams::operator=(
            &v5->mBlendedParams,
            &v5->mContextParameters[v5->mContext]);
          UFG::FollowCameraComponent::FollowParams::operator=(&v5->mOldParams, &v5->mBlendedParams);
          v5->mBlendedParams.mTweakBaseOffset.x = v90;
          v5->mBlendedParams.mTweakBaseOffset.y = v91;
          v5->mOldParams.mTweakBaseOffset.x = v92;
          v5->mOldParams.mTweakBaseOffset.y = v93;
        }
        if ( v5->mType != 1 )
        {
LABEL_122:
          if ( v5->mPreviousType == 1 )
            v5->bAimUseEyeLook = 0;
        }
        v5->mFov.p1 = v5->mBlendedParams.mTweakFov;
        UFG::HomerCubic<float>::MakeCoeffs(&v5->mFov);
        v5->mFov.mParameter = 0.0;
        return;
      }
      v80 = (__m128)LODWORD(v5->mEye.p0.x);
      v81 = v5->mEye.p0.y - v5->mLook.p0.y;
      v80.m128_f32[0] = (float)((float)(v80.m128_f32[0] - v5->mLook.p0.x) * (float)(v80.m128_f32[0] - v5->mLook.p0.x))
                      + (float)(v81 * v81);
      v83 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v80)) - v5->mBlendedParams.mTweakRadiusMax)
          / (float)(UFG::FollowCameraComponent::rAutoFrameMinRadius - v5->mBlendedParams.mTweakRadiusMax);
      if ( v83 <= 0.0 )
      {
        v83 = 0.0;
      }
      else if ( v83 >= 1.0 )
      {
LABEL_83:
        v82 = v5->mContextParameters[v5->mContext].mTweakEyeRise;
        v84 = (float)((float)(UFG::FollowCameraComponent::rAutoFrameMinEyeRise - v82) * v23) + v82;
        switch ( v79 )
        {
          case 9:
          case 2:
            v84 = v84 + 0.80000001;
            break;
          case 1:
          case 8:
            v84 = v84 + 1.2;
            break;
          case 3:
          case 10:
            v84 = v84 + 2.0;
            break;
        }
        v5->mGotoRise = v84;
        goto LABEL_94;
      }
      v23 = v83;
      goto LABEL_83;
    }
  }
}

// File Line: 1899
// RVA: 0x3CEE00
void __fastcall UFG::FollowCameraComponent::TransitionFromBlendOrientation(UFG::FollowCameraComponent *this, UFG::BaseCameraComponent *fromCamera, float eyeRateMin, float eyeRateMax, float orientRateMin, float orientRateMax)
{
  UFG::BaseCameraComponent *v6; // rbx
  UFG::FollowCameraComponent *v7; // rdi
  float v8; // xmm7_4
  __m128 v9; // xmm10
  __int128 v10; // xmm11
  float v11; // xmm15_4
  float v12; // xmm9_4
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
  __m128 v23; // xmm5
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
  float v37; // xmm4_4
  float v38; // xmm2_4
  float v39; // xmm5_4
  __m128 v40; // xmm11
  float v41; // xmm2_4
  __m128 v42; // xmm4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm8_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v47; // rax
  float v48; // [rsp+20h] [rbp-128h]
  unsigned int v49; // [rsp+28h] [rbp-120h]
  float v50; // [rsp+2Ch] [rbp-11Ch]
  float v51; // [rsp+30h] [rbp-118h]
  char v52; // [rsp+38h] [rbp-110h]
  UFG::qMatrix44 mat; // [rsp+50h] [rbp-F8h]
  float v54; // [rsp+150h] [rbp+8h]
  float v55; // [rsp+158h] [rbp+10h]
  float v56; // [rsp+160h] [rbp+18h]
  float v57; // [rsp+168h] [rbp+20h]

  v56 = eyeRateMin;
  v6 = fromCamera;
  v7 = this;
  v8 = fromCamera->mEyeCurr.z;
  v54 = fromCamera->mLookCurr.x;
  v55 = fromCamera->mLookCurr.y;
  v9 = (__m128)LODWORD(fromCamera->mEyeCurr.y);
  v10 = LODWORD(fromCamera->mLookCurr.z);
  v57 = fromCamera->mEyeCurr.z;
  v11 = fromCamera->mEyeCurr.x;
  v48 = fromCamera->mLookCurr.z;
  v13 = LODWORD(v54);
  v14 = (__m128)LODWORD(fromCamera->mLookCurr.y);
  v12 = eyeRateMax;
  *(float *)&v13 = v54 - v11;
  v14.m128_f32[0] = v14.m128_f32[0] - v9.m128_f32[0];
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, unsigned int *))fromCamera->vfptr[25].__vecDelDtor)(
    fromCamera,
    &v52,
    &v49);
  v15 = (__m128)v49;
  v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v50 * v50)) + (float)(v51 * v51);
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v15);
  ((void (__fastcall *)(UFG::FollowCameraComponent *))v7->vfptr[15].__vecDelDtor)(v7);
  UFG::FollowCameraComponent::Snap(v7);
  v17 = atan2f(COERCE_FLOAT(v14.m128_i32[0] ^ _xmm[0]), COERCE_FLOAT(COERCE_UNSIGNED_INT(v54 - v11) ^ _xmm[0]));
  UFG::FollowCameraComponent::GotoAngleSnap(v7, v17, 1);
  v18 = v10;
  v20 = v14;
  v7->mTransitionFromEye.z = v8;
  v7->mTransitionFromEye.x = v11;
  LODWORD(v7->mTransitionFromEye.y) = v9.m128_i32[0];
  *(float *)&v18 = *(float *)&v10 - v8;
  v19 = *(float *)&FLOAT_1_0;
  v20.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(*(float *)&v13 * *(float *)&v13))
                  + (float)(*(float *)&v18 * *(float *)&v18);
  if ( v20.m128_f32[0] == 0.0 )
    v21 = 0.0;
  else
    v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
  v22 = v6->mCamera.mTransformation.v1.y;
  v23 = (__m128)LODWORD(v6->mCamera.mTransformation.v1.x);
  v24 = v6->mCamera.mTransformation.v1.z;
  *(float *)&v13 = *(float *)&v13 * v21;
  v25 = v14.m128_f32[0] * v21;
  *(float *)&v18 = *(float *)&v18 * v21;
  mat.v0.w = 0.0;
  v26 = v23;
  LODWORD(mat.v0.x) = v13;
  mat.v0.y = v25;
  LODWORD(mat.v0.z) = v18;
  v26.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v22 * v22)) + (float)(v24 * v24);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
  v28 = v23.m128_f32[0] * v27;
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
    v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
  v37 = v34 * v36;
  v38 = v33.m128_f32[0] * v36;
  *(float *)&v31 = *(float *)&v31 * v36;
  mat.v1.w = 0.0;
  mat.v1.z = v37;
  mat.v1.y = v38;
  LODWORD(mat.v1.x) = v31;
  v40 = (__m128)v31;
  v39 = (float)(v37 * v25) - (float)(v38 * *(float *)&v18);
  v40.m128_f32[0] = (float)(*(float *)&v31 * *(float *)&v18) - (float)(v37 * *(float *)&v13);
  v41 = (float)(v38 * *(float *)&v13) - (float)(*(float *)&v31 * v25);
  v42 = v40;
  v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
  if ( v42.m128_f32[0] == 0.0 )
    v43 = 0.0;
  else
    v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v42));
  mat.v3.x = v11;
  LODWORD(mat.v3.y) = v9.m128_i32[0];
  mat.v2.w = 0.0;
  mat.v3.w = 1.0;
  mat.v2.y = v40.m128_f32[0] * v43;
  mat.v2.x = v39 * v43;
  mat.v3.z = v57;
  mat.v2.z = v41 * v43;
  UFG::qQuaternion::Set(&v7->mTransitionFromOri, &mat);
  v9.m128_f32[0] = (float)((float)((float)(v9.m128_f32[0] - v55) * (float)(v9.m128_f32[0] - v55))
                         + (float)((float)(v11 - v54) * (float)(v11 - v54)))
                 + (float)((float)(v57 - v48) * (float)(v57 - v48));
  LODWORD(v7->mTransitionFromLen) = (unsigned __int128)_mm_sqrt_ps(v9);
  v44 = UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
      - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin;
  v45 = (float)(v16 - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin)
      / (float)(UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
              - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin);
  if ( v45 <= 0.0 )
  {
    v45 = 0.0;
  }
  else if ( v45 >= 1.0 )
  {
    v45 = *(float *)&FLOAT_1_0;
  }
  v7->mTransitionParamRateEye = (float)((float)(v12 - v56) * v45) + v56;
  v46 = (float)(v16 - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin)
      / (float)(UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
              - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin);
  if ( v46 <= 0.0 )
  {
    v46 = 0.0;
    goto LABEL_21;
  }
  if ( v46 < 1.0 )
LABEL_21:
    v19 = v46;
  v7->mTransitionParamRateOrient = (float)((float)(orientRateMax - orientRateMin) * v19) + orientRateMin;
  if ( UFG::FollowCameraComponent::bTransitionToFollowOverride )
  {
    v44 = UFG::FollowCameraComponent::rTransitionToFollowEyeRateOverride;
    v7->mTransitionParamRateEye = UFG::FollowCameraComponent::rTransitionToFollowEyeRateOverride;
    v7->mTransitionParamRateOrient = UFG::FollowCameraComponent::rTransitionToFollowOrientRateOverride;
  }
  v7->mTransitionParamEye = 1.0;
  v7->mTransitionParamOrient = 1.0;
  ((void (__fastcall *)(UFG::BaseCameraComponent *))v6->vfptr[19].__vecDelDtor)(v6);
  ((void (__fastcall *)(UFG::BaseCameraComponent *))v6->vfptr[19].__vecDelDtor)(v6);
  v47 = v6->vfptr;
  if ( v44 <= 3.1415927 )
  {
    ((void (__fastcall *)(UFG::BaseCameraComponent *))v47[19].__vecDelDtor)(v6);
    v44 = (float)(v44 * 180.0) * 0.31830987;
  }
  else
  {
    ((void (__fastcall *)(UFG::BaseCameraComponent *))v47[19].__vecDelDtor)(v6);
  }
  v7->mFov.p1 = v44;
  UFG::HomerCubic<float>::MakeCoeffs(&v7->mFov);
  v7->mFov.mParameter = 0.0;
  v7->mFov.p0 = v7->mFov.p1;
  v7->mFov.v0 = v7->mFov.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&v7->mFov);
  v7->mFov.mParameter = 0.0;
  ((void (__fastcall *)(UFG::FollowCameraComponent *))v7->vfptr[15].__vecDelDtor)(v7);
} 0.0;
  ((void (__fastcall *)(UFG::FollowCameraComponent *))v7->vfptr[15].__vecDelDtor)(v7);
}

// File Line: 1950
// RVA: 0x3CF390
void __fastcall UFG::FollowCameraComponent::TransitionFromSuppDuration(UFG::FollowCameraComponent *this, UFG::BaseCameraComponent *fromCamera, bool withVelocity)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  UFG::HomerCubic<UFG::qVector3> *v5; // rbx
  UFG::FollowCameraComponent *v6; // rdi
  bool v7; // bp
  UFG::HomerCubic<UFG::qVector3> *v8; // rcx
  UFG::BaseCameraComponent *v9; // rsi
  float v10; // eax
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float *v14; // rbx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v21; // rax
  __m128 v22; // xmm2
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v29; // rax
  float v30; // xmm0_4
  unsigned int v31; // [rsp+20h] [rbp-28h]
  float v32; // [rsp+24h] [rbp-24h]
  float v33; // [rsp+28h] [rbp-20h]
  char v34; // [rsp+30h] [rbp-18h]

  v3 = fromCamera->mEyeCurr.y;
  v4 = fromCamera->mEyeCurr.z;
  v5 = &this->mEye;
  v6 = this;
  v7 = withVelocity;
  v8 = &this->mEye;
  v9 = fromCamera;
  if ( UFG::FollowCameraComponent::bTransitionToFollowOverride )
    v7 = UFG::FollowCameraComponent::bTransitionToFollowUseVelOverride;
  v5->p1.x = fromCamera->mEyeCurr.x;
  v5->p1.y = v3;
  v5->p1.z = v4;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v8);
  *(_QWORD *)&v5->mParameter.x = 0i64;
  v5->mParameter.z = 0.0;
  v10 = v5->p1.x;
  v11 = v5->p1.z;
  v5->p0.y = v5->p1.y;
  v5->p0.z = v11;
  v5->p0.x = v10;
  v12 = v5->v1.y;
  v13 = v5->v1.z;
  v5->v0.x = v5->v1.x;
  v5->v0.y = v12;
  v5->v0.z = v13;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v5);
  *(_QWORD *)&v5->mParameter.x = 0i64;
  v5->mParameter.z = 0.0;
  v14 = &v6->mLook.mDuration.x;
  v15 = v9->mLookCurr.y;
  v16 = v9->mLookCurr.z;
  v14[21] = v9->mLookCurr.x;
  v14[22] = v15;
  v14[23] = v16;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v6->mLook);
  *(_QWORD *)&v6->mLook.mParameter.x = 0i64;
  v6->mLook.mParameter.z = 0.0;
  v17 = v6->mLook.p1.y;
  v18 = v6->mLook.p1.z;
  v6->mLook.p0.x = v6->mLook.p1.x;
  v6->mLook.p0.y = v17;
  v6->mLook.p0.z = v18;
  v19 = v6->mLook.v1.y;
  v20 = v6->mLook.v1.z;
  v6->mLook.v0.x = v6->mLook.v1.x;
  v6->mLook.v0.y = v19;
  v6->mLook.v0.z = v20;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v6->mLook);
  v21 = v9->vfptr;
  *(_QWORD *)&v6->mLook.mParameter.x = 0i64;
  v6->mLook.mParameter.z = 0.0;
  ((void (__fastcall *)(UFG::BaseCameraComponent *, char *, unsigned int *))v21[25].__vecDelDtor)(v9, &v34, &v31);
  v22 = (__m128)v31;
  v23 = v32 * v32;
  v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v32 * v32)) + (float)(v33 * v33);
  LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v22);
  v25 = (float)(v24 - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin)
      / (float)(UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
              - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin);
  v26 = *(float *)&FLOAT_1_0;
  if ( v25 <= 0.0 )
  {
    v25 = 0.0;
  }
  else if ( v25 >= 1.0 )
  {
    v25 = *(float *)&FLOAT_1_0;
  }
  v6->mTransitionParamRateSuppEye = (float)((float)(UFG::FollowCameraComponent::rTransitionToFollowParamRateMax
                                                  - UFG::FollowCameraComponent::rTransitionToFollowParamRateMin)
                                          * v25)
                                  + UFG::FollowCameraComponent::rTransitionToFollowParamRateMin;
  v27 = (float)(v24 - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin)
      / (float)(UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMax
              - UFG::FollowCameraComponent::rTransitionToFollowParamSpeedMin);
  if ( v27 <= 0.0 )
  {
    v27 = 0.0;
    goto LABEL_11;
  }
  if ( v27 < 1.0 )
LABEL_11:
    v26 = v27;
  v28 = (float)((float)(UFG::FollowCameraComponent::rTransitionToFollowParamRateMax
                      - UFG::FollowCameraComponent::rTransitionToFollowParamRateMin)
              * v26)
      + UFG::FollowCameraComponent::rTransitionToFollowParamRateMin;
  v6->mTransitionParamSuppEye = 1.0;
  v6->mTransitionParamSuppLook = 1.0;
  v6->mTransitionParamRateSuppLook = v28;
  UFG::BaseCameraComponent::TransitionFrom((UFG::BaseCameraComponent *)&v6->vfptr, v9, v7);
  ((void (__fastcall *)(UFG::BaseCameraComponent *))v9->vfptr[19].__vecDelDtor)(v9);
  ((void (__fastcall *)(UFG::BaseCameraComponent *))v9->vfptr[19].__vecDelDtor)(v9);
  v29 = v9->vfptr;
  if ( v23 <= 3.1415927 )
  {
    ((void (__fastcall *)(UFG::BaseCameraComponent *))v29[19].__vecDelDtor)(v9);
    v23 = (float)(v23 * 180.0) * 0.31830987;
  }
  else
  {
    ((void (__fastcall *)(UFG::BaseCameraComponent *))v29[19].__vecDelDtor)(v9);
  }
  v6->mFov.p1 = v23;
  UFG::HomerCubic<float>::MakeCoeffs(&v6->mFov);
  v6->mFov.mParameter = 0.0;
  v6->mFov.v1 = 0.0;
  UFG::HomerCubic<float>::MakeCoeffs(&v6->mFov);
  v6->mFov.mParameter = 0.0;
  if ( UFG::SimComponent::IsType(
         (UFG::SimComponent *)&v9->vfptr,
         UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID) )
  {
    v6->mTransitionTimeOverride = UFG::FollowCameraComponent::rTransitionTimeFromAnimated;
  }
  else if ( UFG::SimComponent::IsType(
              (UFG::SimComponent *)&v9->vfptr,
              UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID) )
  {
    v6->mTransitionTimeOverride = UFG::FollowCameraComponent::rTransitionTimeFromProgression;
  }
  else
  {
    v6->mTransitionTimeOverride = -1.0;
  }
  v6->mTransitionSupplimentaryDuration = UFG::FollowCameraComponent::rTransitionToFollowSupplimentaryDuration;
  if ( UFG::SimComponent::IsType(
         (UFG::SimComponent *)&v9->vfptr,
         UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID)
    || UFG::SimComponent::IsType(
         (UFG::SimComponent *)&v9->vfptr,
         UFG::ProgressionCameraComponent::_ProgressionCameraComponentTypeUID) )
  {
    v30 = UFG::FollowCameraComponent::rTransitionToFollowSupplimentaryDurationFromNIS;
    goto LABEL_26;
  }
  if ( v6->mTarget.m_pSimComponent && ((unsigned __int8 (*)(void))v6->mTarget.m_pSimComponent->vfptr[48].__vecDelDtor)() )
  {
    v30 = UFG::FollowCameraComponent::rTransitionToFollowSupplimentaryDurationActionHijack;
LABEL_26:
    v6->mTransitionSupplimentaryDuration = v30;
  }
}

// File Line: 2010
// RVA: 0x3C2250
void __fastcall UFG::FollowCameraComponent::FollowCameraEventHandler(UFG::FollowCameraComponent *this, UFG::Event *e)
{
  UFG::Event *v2; // rbp
  UFG::FollowCameraComponent *v3; // rsi
  unsigned int v4; // eax
  UFG::SimObjectGame *v5; // rcx
  UFG::SimComponent *v6; // r14
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  UFG::Director *v9; // rax
  unsigned int v10; // eax
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  bool v13; // bl
  int v14; // xmm0_4
  int v15; // xmm1_4
  int v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm7_4
  float v19; // xmm8_4
  _DWORD *v20; // rbx
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float *v25; // rbx
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  __int64 v30; // r8
  UFG::SimObjectGame *v31; // rcx
  UFG::BaseCameraComponent *v32; // rdi
  UFG::SimComponent *v33; // rbx
  unsigned __int16 v34; // dx
  UFG::SimComponent *v35; // rax
  UFG::SimObjectGame *v36; // rcx
  unsigned __int16 v37; // dx
  UFG::SimComponent *v38; // rax
  bool v39; // r14
  UFG::CharacterSubjectComponent *v40; // rcx
  UFG::TargetingSystemBaseComponent *v41; // rax
  UFG::TargetingMap *v42; // rcx
  UFG::TargetingSimObject *v43; // rdx
  signed __int64 v44; // rax
  UFG::SimObject *v45; // rbp
  UFG::Director *v46; // rax

  v2 = e;
  v3 = this;
  v4 = e->m_EventUID;
  if ( UFG::gEventDisMountVehicleCamera.mUID == v4 )
  {
    v5 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v5 )
    {
      v7 = v5->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ChaseCameraComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ChaseCameraComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ChaseCameraComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ChaseCameraComponent::_TypeUID);
        }
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::ChaseCameraComponent::_TypeUID);
      }
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    if ( v3->mTarget.m_pSimComponent->m_pSimObject == (UFG::SimObject *)v2[1].mNext
      && v6
      && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v6->vfptr[21].__vecDelDtor)(v6) )
    {
      v9 = UFG::Director::Get();
      UFG::Director::SetCurrentCamera(v9, (UFG::BaseCameraComponent *)&v3->vfptr);
      UFG::GameCameraComponent::mNoRotationTimer = FLOAT_0_75;
      v10 = _S10_4;
      if ( !(_S10_4 & 1) )
      {
        _S10_4 |= 1u;
        HASH_DismountShoot.mUID = UFG::qStringHashUpper32("DismountShoot", 0xFFFFFFFF);
        v10 = _S10_4;
      }
      if ( !(v10 & 2) )
      {
        _S10_4 = v10 | 2;
        mostUsedIndex_DismountShoot = GetMostUsedIndex(HASH_DismountShoot.mUID);
      }
      v13 = 0;
      if ( LocalPlayer )
      {
        v11 = LocalPlayer->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = LocalPlayer->m_Components.p[7].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
            v12 = LocalPlayer->m_Components.p[6].m_pComponent;
          else
            v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                      UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                              (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                              UFG::ActionTreeComponent::_TypeUID);
        }
        else
        {
          v12 = LocalPlayer->m_Components.p[7].m_pComponent;
        }
        if ( v12
          && ActionController::IsPlaying(
               (ActionController *)&v12[3],
               &HASH_DismountShoot,
               mostUsedIndex_DismountShoot,
               1) )
        {
          v13 = 1;
        }
      }
      if ( v3->mTarget.m_pSimComponent
        && (((void (*)(void))v3->mTarget.m_pSimComponent->vfptr[28].__vecDelDtor)(), 0.75 < 8.0)
        || v13 )
      {
        UFG::FollowCameraComponent::TransitionFromBlendOrientation(
          v3,
          (UFG::BaseCameraComponent *)v6,
          UFG::FollowCameraComponent::rTransitionToFollowParamRateMin,
          UFG::FollowCameraComponent::rTransitionToFollowParamRateMax,
          UFG::FollowCameraComponent::rTransitionToFollowParamRateMin,
          UFG::FollowCameraComponent::rTransitionToFollowParamRateMax,
          1);
      }
      else
      {
        v14 = HIDWORD(v6[10].m_BoundComponentHandles.mNode.mPrev);
        v15 = (int)v6[10].m_BoundComponentHandles.mNode.mNext;
        v16 = HIDWORD(v6[10].m_BoundComponentHandles.mNode.mNext);
        v17 = *(float *)&v6[11].vfptr;
        v18 = *((float *)&v6[11].vfptr + 1);
        v19 = *(float *)&v6[11].m_SafePointerList.mNode.mPrev;
        v3->mAimOrigin.x = v17;
        v3->mAimOrigin.y = v18;
        v3->mAimOrigin.z = v19;
        v20 = (_DWORD *)&v3->mAimEye.mDuration.x;
        v20[21] = v14;
        v20[22] = v15;
        v20[23] = v16;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mAimEye);
        *(_QWORD *)&v3->mAimEye.mParameter.x = 0i64;
        v3->mAimEye.mParameter.z = 0.0;
        v21 = v3->mAimEye.p1.y;
        v22 = v3->mAimEye.p1.z;
        v3->mAimEye.p0.x = v3->mAimEye.p1.x;
        v3->mAimEye.p0.y = v21;
        v3->mAimEye.p0.z = v22;
        v23 = v3->mAimEye.v1.y;
        v24 = v3->mAimEye.v1.z;
        v3->mAimEye.v0.x = v3->mAimEye.v1.x;
        v3->mAimEye.v0.y = v23;
        v3->mAimEye.v0.z = v24;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mAimEye);
        *(_QWORD *)&v3->mAimEye.mParameter.x = 0i64;
        v3->mAimEye.mParameter.z = 0.0;
        v25 = &v3->mAimLook.mDuration.x;
        v25[21] = v17;
        v25[22] = v18;
        v25[23] = v19;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mAimLook);
        *(_QWORD *)&v3->mAimLook.mParameter.x = 0i64;
        v3->mAimLook.mParameter.z = 0.0;
        v26 = v3->mAimLook.p1.y;
        v27 = v3->mAimLook.p1.z;
        v3->mAimLook.p0.x = v3->mAimLook.p1.x;
        v3->mAimLook.p0.y = v26;
        v3->mAimLook.p0.z = v27;
        v28 = v3->mAimLook.v1.y;
        v29 = v3->mAimLook.v1.z;
        v3->mAimLook.v0.x = v3->mAimLook.v1.x;
        v3->mAimLook.v0.y = v28;
        v3->mAimLook.v0.z = v29;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mAimLook);
        *(_QWORD *)&v3->mAimLook.mParameter.x = 0i64;
        v3->mAimLook.mParameter.z = 0.0;
        LOBYTE(v30) = 1;
        ((void (__fastcall *)(UFG::FollowCameraComponent *, UFG::SimComponent *, __int64))v3->vfptr[43].__vecDelDtor)(
          v3,
          v6,
          v30);
      }
    }
  }
  else if ( UFG::gEventMountVehicleCamera.mUID == v4 )
  {
    v31 = (UFG::SimObjectGame *)this->m_pSimObject;
    v32 = 0i64;
    if ( v31 )
    {
      v34 = v31->m_Flags;
      if ( (v34 >> 14) & 1 )
      {
        v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::ChaseCameraComponent::_TypeUID);
      }
      else if ( (v34 & 0x8000u) == 0 )
      {
        if ( (v34 >> 13) & 1 )
          v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::ChaseCameraComponent::_TypeUID);
        else
          v35 = (v34 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::ChaseCameraComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v31->vfptr, UFG::ChaseCameraComponent::_TypeUID);
      }
      else
      {
        v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::ChaseCameraComponent::_TypeUID);
      }
      v33 = v35;
    }
    else
    {
      v33 = 0i64;
    }
    v36 = (UFG::SimObjectGame *)v3->m_pSimObject;
    v39 = 0;
    if ( v36 )
    {
      v37 = v36->m_Flags;
      if ( (v37 >> 14) & 1 )
      {
        v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::ScriptCameraComponent::_TypeUID);
      }
      else if ( (v37 & 0x8000u) == 0 )
      {
        if ( (v37 >> 13) & 1 )
          v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::ScriptCameraComponent::_TypeUID);
        else
          v38 = (v37 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::ScriptCameraComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v36->vfptr, UFG::ScriptCameraComponent::_TypeUID);
      }
      else
      {
        v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::ScriptCameraComponent::_TypeUID);
      }
      v32 = (UFG::BaseCameraComponent *)v38;
      if ( v38 )
      {
        if ( ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v38->vfptr[21].__vecDelDtor)(v38) )
          v39 = 1;
      }
    }
    v40 = (UFG::CharacterSubjectComponent *)v3->mTarget.m_pSimComponent;
    if ( v40->m_pSimObject == (UFG::SimObject *)v2[1].mNext )
    {
      if ( v33 )
      {
        v41 = UFG::CharacterSubjectComponent::GetTargetingSystem(v40);
        if ( v41 )
        {
          if ( (v42 = v41->m_pTargetingMap,
                v43 = v41->m_pTargets,
                v44 = (unsigned __int8)v42->m_Map.p[44],
                (v45 = v43[v44].m_pTarget.m_pPointer) != 0i64)
            && v43[v44].m_bLock
            || (v45 = v43[(unsigned __int8)v42->m_Map.p[28]].m_pTarget.m_pPointer) != 0i64 )
          {
            if ( ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v33->vfptr[21].__vecDelDtor)(v33) )
            {
              if ( v45 != (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))v33->vfptr[17].__vecDelDtor)(v33) )
                UFG::ChaseCameraComponent::TransitionTarget((UFG::ChaseCameraComponent *)v33, v45);
            }
            else
            {
              v46 = UFG::Director::Get();
              UFG::Director::SetCurrentCamera(v46, (UFG::BaseCameraComponent *)v33);
              UFG::GameCameraComponent::mNoRotationTimer = FLOAT_0_75;
              v33->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v33->vfptr, (unsigned int)v45);
              if ( gForceSnapOnEvent )
              {
                ((void (__fastcall *)(UFG::SimComponent *))v33->vfptr[15].__vecDelDtor)(v33);
                ((void (__fastcall *)(UFG::SimComponent *))v33->vfptr[31].__vecDelDtor)(v33);
                ((void (__fastcall *)(UFG::SimComponent *))v33->vfptr[15].__vecDelDtor)(v33);
                if ( BYTE4(v33[45].m_pSimObject) )
                {
                  *(_DWORD *)&v33[46].m_Flags = 1065353216;
                  BYTE4(v33[45].m_pSimObject) = 0;
                  BYTE1(v33[45].m_TypeUID) = 1;
                }
                if ( BYTE5(v33[45].m_pSimObject) )
                {
                  *(_DWORD *)(&v33[46].m_SimObjIndex + 1) = 1065353216;
                  BYTE5(v33[45].m_pSimObject) = 0;
                }
              }
              else if ( v39 )
              {
                UFG::ChaseCameraComponent::TransitionFromBlendOrientation((UFG::ChaseCameraComponent *)v33, v32);
              }
              else
              {
                UFG::ChaseCameraComponent::TransitionFromBlendOrientation(
                  (UFG::ChaseCameraComponent *)v33,
                  (UFG::BaseCameraComponent *)&v3->vfptr);
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
void __fastcall UFG::FollowCameraComponent::GetFovRadians(UFG::FollowCameraComponent *this, float *fov, float *fov_velocity)
{
  *fov_velocity = this->mFov.v0 * 0.017453292;
  *fov = this->mFov.p0 * 0.017453292;
}

// File Line: 2119
// RVA: 0x3CC9C0
void __fastcall UFG::FollowCameraComponent::SetFovRadians(UFG::FollowCameraComponent *this, float fov, float fov_velocity)
{
  UFG::HomerCubic<float> *v3; // rbx

  v3 = &this->mFov;
  this->mFov.v0 = fov_velocity * 57.295776;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  v3->mParameter = 0.0;
  v3->p0 = fov * 57.295776;
  UFG::HomerCubic<float>::MakeCoeffs(v3);
  v3->mParameter = 0.0;
}

// File Line: 2127
// RVA: 0x3C3370
void __fastcall UFG::FollowCameraComponent::GetEyeWorld(UFG::FollowCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  v3 = this->mEye.p0.y;
  v4 = this->mEye.p0.z;
  position->x = this->mEye.p0.x;
  position->y = v3;
  position->z = v4;
  v5 = this->mEye.v0.y;
  v6 = this->mEye.v0.z;
  velocity->x = this->mEye.v0.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 2137
// RVA: 0x3C3840
void __fastcall UFG::FollowCameraComponent::GetLookWorld(UFG::FollowCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4

  v3 = this->mLook.p0.y;
  v4 = this->mLook.p0.z;
  position->x = this->mLook.p0.x;
  position->y = v3;
  position->z = v4;
  v5 = this->mLook.v0.y;
  v6 = this->mLook.v0.z;
  velocity->x = this->mLook.v0.x;
  velocity->y = v5;
  velocity->z = v6;
}

// File Line: 2147
// RVA: 0x3CC7B0
void __fastcall UFG::FollowCameraComponent::SetEyeWorld(UFG::FollowCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  UFG::HomerCubic<UFG::qVector3> *v3; // rcx
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm2_4

  v3 = &this->mEye;
  v4 = v3->mDuration.z;
  v5 = velocity->x - UFG::qVector3::msZero.x;
  v6 = velocity->y - UFG::qVector3::msZero.y;
  v7 = velocity->z - UFG::qVector3::msZero.z;
  v8 = position->x;
  v9 = position->y;
  v10 = position->z;
  v11 = v3->mDuration.x;
  v12 = v3->mDuration.y;
  if ( v4 <= 0.0099999998 )
    v4 = FLOAT_0_0099999998;
  if ( v12 <= 0.0099999998 )
    v12 = FLOAT_0_0099999998;
  if ( v11 <= 0.0099999998 )
    v11 = FLOAT_0_0099999998;
  v3->mDuration.x = v11;
  v3->mDuration.y = v12;
  v3->mDuration.z = v4;
  *(_QWORD *)&v3->mParameter.x = 0i64;
  v3->mParameter.z = 0.0;
  v3->v0.x = v5;
  v3->v0.y = v6;
  v3->v0.z = v7;
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  v3->v1.x = UFG::qVector3::msZero.x;
  v3->v1.y = v13;
  v3->v1.z = v14;
  v3->p0.x = v8;
  v3->p0.y = v9;
  v3->p0.z = v10;
  v3->p1.x = v8;
  v3->p1.y = v9;
  v3->p1.z = v10;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v3);
}

// File Line: 2157
// RVA: 0x3CCE60
void __fastcall UFG::FollowCameraComponent::SetLookWorld(UFG::FollowCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  UFG::HomerCubic<UFG::qVector3> *v3; // rbx
  UFG::qVector3 *v4; // rdi
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // eax
  float v8; // xmm1_4

  v3 = &this->mLook;
  v4 = position;
  v5 = velocity->y - UFG::qVector3::msZero.y;
  v6 = velocity->z - UFG::qVector3::msZero.z;
  v3->v0.x = velocity->x - UFG::qVector3::msZero.x;
  v3->v0.y = v5;
  v3->v0.z = v6;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&v3->mParameter.x = 0i64;
  v3->mParameter.z = 0.0;
  v7 = v4->x;
  v8 = v4->z;
  v3->p0.y = v4->y;
  v3->p0.z = v8;
  v3->p0.x = v7;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v3);
  *(_QWORD *)&v3->mParameter.x = 0i64;
  v3->mParameter.z = 0.0;
}

// File Line: 2166
// RVA: 0x3C7660
void __fastcall UFG::FollowCameraComponent::NewTargetPosition(UFG::FollowCameraComponent *this, UFG::qVector3 *position, float angle)
{
  UFG::qVector3 *v3; // rbx
  UFG::FollowCameraComponent *v4; // rdi
  float v5; // xmm0_4
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm0_4
  __m128 v9; // xmm8
  float v10; // xmm3_4
  signed __int64 v11; // rcx
  float v12; // xmm9_4
  __m128 v13; // xmm10
  float v14; // xmm0_4
  float v15; // xmm8_4
  float v16; // xmm2_4
  float v17; // xmm11_4
  __m128 v18; // xmm12
  float v19; // xmm1_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  __m128 v22; // xmm3
  float v23; // xmm4_4
  __m128 v24; // xmm5
  float v25; // xmm1_4
  signed __int64 v26; // rcx
  signed __int64 v27; // rcx

  v3 = position;
  v4 = this;
  if ( this->mBlendedParams.mUseInitAngle )
    v5 = this->mBlendedParams.mInitAngle;
  else
    v5 = 0.0;
  v6 = angle - (float)((float)(v5 * 3.1415927) * 0.0055555557);
  v7 = sinf(v6);
  v8 = cosf(v6);
  v9 = (__m128)LODWORD(v4->mBlendedParams.mTweakCamThru.y);
  v10 = v8;
  v13 = v9;
  v11 = (signed __int64)&v4->mVelocity;
  v12 = (float)(COERCE_FLOAT(LODWORD(v7) ^ _xmm[0]) * v9.m128_f32[0])
      + (float)((float)(v4->mBlendedParams.mTweakCamThru.x * v8) + v3->x);
  v13.m128_f32[0] = (float)(v9.m128_f32[0] * v8) + (float)((float)(v4->mBlendedParams.mTweakCamThru.x * v7) + v3->y);
  v14 = v4->mBlendedParams.mTweakRadiusMin + 0.0099999998;
  v18 = v13;
  v15 = (float)((float)(v9.m128_f32[0] * 0.0) + (float)((float)(v4->mBlendedParams.mTweakCamThru.x * 0.0) + v3->z))
      + v4->mBlendedParams.mTweakCamThru.z;
  v16 = UFG::qVector3::msZero.z;
  v17 = v12 - (float)(v14 * v10);
  v18.m128_f32[0] = v13.m128_f32[0] - (float)(v14 * v7);
  v19 = UFG::qVector3::msZero.y;
  v20 = (float)(v15 - (float)(v14 * 0.0)) + v4->mBlendedParams.mInitRise;
  *(float *)(v11 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v11 + 88) = v19;
  *(float *)(v11 + 92) = v16;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mVelocity);
  v22 = v18;
  *(_QWORD *)&v4->mVelocity.mParameter.x = 0i64;
  v21 = v17 - v12;
  v22.m128_f32[0] = v18.m128_f32[0] - v13.m128_f32[0];
  v23 = v20 - v15;
  v4->mVelocity.mParameter.z = 0.0;
  v24 = v22;
  v24.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v21 * v21)) + (float)(v23 * v23);
  if ( v24.m128_f32[0] == 0.0 )
    v25 = 0.0;
  else
    v25 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v24));
  v26 = (signed __int64)&v4->mLook;
  v4->mControllerForward.x = v21 * v25;
  v4->mControllerForward.y = v22.m128_f32[0] * v25;
  v4->mControllerForward.z = v23 * v25;
  *(float *)(v26 + 84) = v12;
  *(_DWORD *)(v26 + 88) = v13.m128_i32[0];
  *(float *)(v26 + 92) = v15;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mLook);
  *(_QWORD *)&v4->mLook.mParameter.x = 0i64;
  v4->mLook.mParameter.z = 0.0;
  v27 = (signed __int64)&v4->mEye;
  *(float *)(v27 + 84) = v17;
  *(_DWORD *)(v27 + 88) = v18.m128_i32[0];
  *(float *)(v27 + 92) = v20;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mEye);
  *(_QWORD *)&v4->mEye.mParameter.x = 0i64;
  v4->mEye.mParameter.z = 0.0;
  UFG::FollowCameraComponent::Rotate(v4, 0.0, 0.0);
}

// File Line: 2189
// RVA: 0x3C8890
void __fastcall UFG::FollowCameraComponent::Reset(UFG::FollowCameraComponent *this)
{
  UFG::FollowCameraComponent *v1; // rdi
  float v2; // xmm1_4
  float v3; // xmm2_4
  UFG::SimComponent *v4; // rcx
  UFG::SimObjectCharacter *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::AimingPlayerComponent *v7; // rbx
  UFG::qVector3 *v8; // rax

  v1 = this;
  this->mEnableCharacterSpaceSmoothing = 0;
  UFG::FollowCameraComponent::ResetFromTarget(this, 1);
  v1->mAllowCanOccludeCamera = 1;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mCollisionLookOffset.x = UFG::qVector3::msZero.x;
  v1->mCollisionLookOffset.y = v2;
  v1->mCollisionLookOffset.z = v3;
  UFG::BaseCameraComponent::Reset((UFG::BaseCameraComponent *)&v1->vfptr);
  v4 = v1->mTarget.m_pSimComponent;
  v1->mMouseBoomSet = 0;
  if ( v4 && (v5 = (UFG::SimObjectCharacter *)v4->m_pSimObject) != 0i64 )
  {
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v5);
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v5->vfptr,
                                             UFG::AimingPlayerComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v5->vfptr,
                                             UFG::AimingPlayerComponent::_TypeUID);
      }
      else
      {
        v7 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v5->vfptr,
                                             UFG::AimingPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v7 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           (UFG::SimObjectGame *)&v5->vfptr,
                                           UFG::AimingPlayerComponent::_TypeUID);
    }
  }
  else
  {
    v7 = 0i64;
  }
  if ( v7 )
  {
    v8 = (UFG::qVector3 *)((__int64 (*)(void))v1->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)();
    UFG::AimingPlayerComponent::SetFreeAimIntention(v7, v8);
    ((void (__fastcall *)(UFG::UpdateInterfaceVtbl **))v7->vfptr->Update)(&v7->vfptr);
    v1->mSnapNext = 1;
  }
}

// File Line: 2208
// RVA: 0x3C8E00
void __fastcall UFG::FollowCameraComponent::ResetFromTarget(UFG::FollowCameraComponent *this, bool snap)
{
  float v2; // xmm0_4
  UFG::FollowCameraComponent *v3; // rdi
  bool v4; // si
  float v5; // xmm9_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  UFG::CharacterSubjectComponent *v8; // rcx
  __int64 v9; // rdx
  __int64 v10; // rax
  UFG::SimComponent *v11; // rbx
  __int128 v12; // xmm6
  __int64 v13; // rax
  float *v14; // rcx
  UFG::RegionComponent *v15; // rcx
  UFG::qVector3 pos; // [rsp+20h] [rbp-58h]

  this->mAimDurationSupplimentary = 0.0;
  v2 = 0.0;
  v3 = this;
  v4 = snap;
  v5 = UFG::qVector3::msZero.z;
  v6 = UFG::qVector3::msZero.x;
  v7 = UFG::qVector3::msZero.y;
  this->mEnableCharacterSpaceSmoothing = 0;
  this->mMouseBoomSet = 0;
  v8 = (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent;
  pos.x = v6;
  pos.y = v7;
  pos.z = v5;
  if ( v8 )
  {
    UFG::CharacterSubjectComponent::Update(v8, 0.0);
    v10 = ((__int64 (__cdecl *)(UFG::SimComponent *, __int64))v3->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)(
            v3->mTarget.m_pSimComponent,
            v9);
    v6 = *(float *)v10;
    v7 = *(float *)(v10 + 4);
    v5 = *(float *)(v10 + 8);
    UFG::CharacterSubjectComponent::GetTransformTypePosition(
      (UFG::CharacterSubjectComponent *)v3->mTarget.m_pSimComponent,
      &pos,
      v3->mBlendedParams.mSrcPosition,
      1);
    v11 = v3->mTarget.m_pSimComponent;
    v12 = *(unsigned int *)((__int64 (__fastcall *)(UFG::SimComponent *))v11->vfptr[16].__vecDelDtor)(v3->mTarget.m_pSimComponent);
    v13 = ((__int64 (__fastcall *)(UFG::SimComponent *))v11->vfptr[16].__vecDelDtor)(v11);
    v2 = atan2f(*(float *)(v13 + 4), *(float *)&v12);
  }
  UFG::FollowCameraComponent::NewTargetPosition(v3, &pos, v2);
  v14 = &v3->mVelocity.mDuration.x;
  v14[21] = v6;
  v14[22] = v7;
  v14[23] = v5;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mVelocity);
  *(_QWORD *)&v3->mVelocity.mParameter.x = 0i64;
  v3->mVelocity.mParameter.z = 0.0;
  if ( v4 )
  {
    UFG::BaseCameraComponent::Reset((UFG::BaseCameraComponent *)&v3->vfptr);
    UFG::FollowCameraComponent::Snap(v3);
  }
  v15 = (UFG::RegionComponent *)v3->mTarget.m_pSimComponent;
  v3->bResetFromTarget = !v15 || !UFG::RegionComponent::GetXformNode(v15);
}

// File Line: 2241
// RVA: 0x3CD570
void __fastcall UFG::FollowCameraComponent::SetTarget(UFG::FollowCameraComponent *this, UFG::SimObject *target)
{
  UFG::SimObject *v2; // r8
  UFG::FollowCameraComponent *v3; // rbx
  UFG::CharacterSubjectComponent *v4; // rax
  unsigned __int16 v5; // cx
  unsigned int v6; // edx
  UFG::SimObjectGame *v7; // rcx
  bool v8; // zf

  v2 = target;
  v3 = this;
  if ( target )
  {
    v5 = target->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>((UFG::SimObjectCharacter *)target);
    }
    else
    {
      if ( (v5 & 0x8000u) != 0 || (v5 >> 13) & 1 )
      {
        v6 = UFG::CharacterSubjectComponent::_TypeUID;
        v7 = (UFG::SimObjectGame *)v2;
      }
      else
      {
        v6 = UFG::CharacterSubjectComponent::_TypeUID;
        v8 = ((v5 >> 12) & 1) == 0;
        v7 = (UFG::SimObjectGame *)v2;
        if ( v8 )
        {
          v4 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                   v2,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
          goto LABEL_11;
        }
      }
      v4 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v7, v6);
    }
  }
  else
  {
    v4 = 0i64;
  }
LABEL_11:
  UFG::RebindingComponentHandle<UFG::CharacterSubjectComponent,0>::Set(&v3->mTarget, v4);
  UFG::FollowCameraComponent::ResetFromTarget(v3, 1);
}

// File Line: 2248
// RVA: 0x3CCF80
void __fastcall UFG::FollowCameraComponent::SetOverrideMaxRadius(UFG::FollowCameraComponent *this, float maxRadius)
{
  float v2; // xmm0_4

  if ( maxRadius <= 0.0 )
    maxRadius = 0.0;
  v2 = this->mBlendedParams.mTweakRadiusMax;
  this->mMaxRadiusOverrideEnabled = 1;
  if ( maxRadius >= v2 )
    this->mMaxRadiusOverride = v2;
  else
    this->mMaxRadiusOverride = maxRadius;
}

// File Line: 2256
// RVA: 0x3CCFC0
void __fastcall UFG::FollowCameraComponent::SetOverrideRise(UFG::FollowCameraComponent *this, float rise)
{
  float v2; // xmm0_4

  v2 = this->mBlendedParams.mTweakEyeRise;
  this->mRiseOverrideEnabled = 1;
  if ( rise <= v2 )
    this->mRiseOverride = rise;
  else
    this->mRiseOverride = v2;
}

// File Line: 2266
// RVA: 0x3D3660
void __usercall UFG::FollowCameraComponent::Update(UFG::FollowCameraComponent *this@<rcx>, float delta_sec@<xmm1>, float *a3@<r13>)
{
  float v3; // xmm14_4
  UFG::FollowCameraComponent *v4; // rdi
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  bool v16; // zf
  int v17; // eax
  _DWORD *v18; // rax
  _DWORD *v19; // rbx
  int v20; // xmm0_4
  int v21; // xmm1_4
  int v22; // esi
  float v23; // xmm6_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm8_4
  __int64 v27; // rax
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  float v30; // xmm0_4
  char v31; // cl
  bool v32; // cf
  float v33; // xmm0_4
  float v34; // xmm1_4
  UFG::HomerCubic<float> *v35; // rcx
  float *v36; // rax
  float v37; // xmm0_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm0_4
  UFG::SimObjectCVBase *v44; // rcx
  unsigned __int16 v45; // dx
  UFG::TargetingSystemPedPlayerComponent *v46; // rax
  UFG::SimComponent *v47; // rax
  bool v48; // cl
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm6_4
  __int64 v52; // rdx
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm1_4
  float v58; // eax
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // eax
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm3_4
  __m128 v70; // xmm4
  float v71; // xmm1_4
  float v72; // xmm5_4
  float v73; // xmm8_4
  float v74; // xmm9_4
  float v75; // xmm15_4
  float v76; // xmm6_4
  float v77; // xmm7_4
  __m128 v78; // xmm2
  float v79; // xmm1_4
  float v80; // xmm2_4
  float v81; // xmm3_4
  float v82; // xmm15_4
  float v83; // xmm6_4
  float v84; // xmm7_4
  float v85; // xmm4_4
  __m128 v86; // xmm9
  float v87; // xmm3_4
  float v88; // xmm4_4
  float v89; // xmm15_4
  float v90; // xmm3_4
  __m128 v91; // xmm2
  float v92; // xmm1_4
  float v93; // xmm7_4
  float v94; // xmm8_4
  float v95; // xmm3_4
  float v96; // xmm9_4
  float v97; // xmm1_4
  float v98; // xmm2_4
  float v99; // xmm5_4
  float v100; // xmm6_4
  float v101; // xmm4_4
  float v102; // xmm7_4
  float v103; // xmm2_4
  float v104; // xmm4_4
  float v105; // xmm1_4
  float v106; // xmm0_4
  float v107; // xmm3_4
  float v108; // xmm8_4
  float v109; // xmm7_4
  float v110; // xmm15_4
  float v111; // xmm8_4
  float v112; // xmm2_4
  float v113; // xmm0_4
  float v114; // xmm1_4
  float v115; // xmm3_4
  float v116; // xmm0_4
  __m128 v117; // xmm2
  float v118; // xmm4_4
  float v119; // xmm15_4
  float v120; // xmm4_4
  __m128 v121; // xmm3
  float v122; // xmm3_4
  float v123; // xmm11_4
  float v124; // xmm7_4
  float v125; // xmm8_4
  float v126; // xmm3_4
  float v127; // xmm15_4
  float v128; // xmm7_4
  float v129; // xmm8_4
  __m128 v130; // xmm4
  __m128 v131; // xmm10
  __m128 v132; // xmm2
  float v133; // xmm1_4
  float v134; // xmm6_4
  float v135; // xmm1_4
  float v136; // xmm6_4
  float v137; // xmm5_4
  float v138; // xmm6_4
  __m128 v139; // xmm4
  float v140; // xmm0_4
  __m128 v141; // xmm4
  __m128 v142; // xmm1
  float v143; // xmm6_4
  float v144; // xmm5_4
  __m128 v145; // xmm9
  __m128 v146; // xmm2
  float v147; // xmm3_4
  __m128 v148; // xmm2
  float v149; // xmm4_4
  __m128 v150; // xmm5
  float v151; // xmm6_4
  float v152; // xmm6_4
  float v153; // xmm1_4
  __m128 v154; // xmm2
  float v155; // xmm3_4
  float v156; // xmm7_4
  float v157; // xmm8_4
  float v158; // xmm3_4
  float v159; // xmm7_4
  float v160; // xmm8_4
  __m128 v161; // xmm2
  float v162; // xmm1_4
  float v163; // xmm5_4
  float v164; // xmm1_4
  float v165; // xmm5_4
  float v166; // xmm6_4
  float v167; // xmm5_4
  __m128 v168; // xmm4
  float v169; // xmm0_4
  __m128 v170; // xmm4
  __m128 v171; // xmm1
  float v172; // xmm5_4
  float v173; // xmm6_4
  __m128 v174; // xmm9
  __m128 v175; // xmm2
  float v176; // xmm3_4
  float v177; // xmm2_4
  float v178; // xmm1_4
  float v179; // xmm0_4
  float v180; // xmm3_4
  float v181; // xmm5_4
  float v182; // xmm6_4
  bool v183; // al
  float v184; // xmm0_4
  float v185; // eax
  UFG::SimObjectCharacter *v186; // rcx
  unsigned __int16 v187; // dx
  UFG::AimingPlayerComponent *v188; // rbx
  UFG::SimObjectCVBase *v189; // rcx
  unsigned __int16 v190; // dx
  UFG::TargetingSystemPedPlayerComponent *v191; // rdx
  bool v192; // r8
  UFG::SimObject *v193; // rdx
  UFG::SimObject *v194; // rax
  UFG::TransformNodeComponent *v195; // r15
  float v196; // xmm0_4
  float v197; // xmm7_4
  float v198; // xmm6_4
  UFG::qVector3 *v199; // rax
  float v200; // xmm1_4
  float v201; // xmm0_4
  UFG::qVector3 *v202; // rax
  float v203; // xmm1_4
  float v204; // xmm0_4
  UFG::SimComponent *v205; // rcx
  float v206; // xmm7_4
  float v207; // xmm9_4
  float v208; // xmm8_4
  float *v209; // rax
  float v210; // xmm9_4
  float v211; // xmm8_4
  UFG::SimComponent *v212; // rbx
  float *v213; // rax
  float v214; // xmm0_4
  float v215; // xmm1_4
  float v216; // xmm0_4
  float v217; // xmm1_4
  float v218; // xmm2_4
  float v219; // xmm0_4
  UFG::SimObjectCharacter *v220; // rcx
  UFG::AimingPlayerComponent *v221; // rax
  unsigned __int16 v222; // dx
  float v223; // xmm1_4
  float v224; // xmm0_4
  float v225; // xmm2_4
  float *v226; // rax
  float v227; // xmm4_4
  float v228; // xmm3_4
  float v229; // xmm5_4
  float v230; // xmm4_4
  float v231; // xmm3_4
  float v232; // xmm5_4
  float v233; // xmm1_4
  float v234; // xmm4_4
  float v235; // xmm5_4
  float v236; // xmm1_4
  float v237; // xmm3_4
  float v238; // xmm7_4
  __m128 v239; // xmm2
  float v240; // xmm8_4
  __m128 v241; // xmm6
  float v242; // xmm1_4
  float v243; // xmm5_4
  float v244; // xmm4_4
  float v245; // xmm0_4
  __m128 v246; // xmm2
  float v247; // xmm3_4
  float v248; // xmm7_4
  float v249; // xmm8_4
  float v250; // xmm3_4
  float v251; // xmm7_4
  float v252; // xmm8_4
  __m128 v253; // xmm2
  float v254; // xmm1_4
  float v255; // xmm6_4
  float v256; // xmm1_4
  float v257; // xmm6_4
  float v258; // xmm5_4
  float v259; // xmm6_4
  __m128 v260; // xmm4
  float v261; // xmm0_4
  __m128 v262; // xmm4
  __m128 v263; // xmm1
  float v264; // xmm6_4
  float v265; // xmm5_4
  __m128 v266; // xmm9
  __m128 v267; // xmm2
  float v268; // xmm3_4
  float v269; // xmm5_4
  float v270; // xmm4_4
  float v271; // xmm2_4
  float v272; // xmm1_4
  float v273; // xmm3_4
  float v274; // xmm0_4
  float v275; // xmm5_4
  float v276; // xmm0_4
  float v277; // xmm6_4
  UFG::qMatrix44 *v278; // rax
  __m128 v279; // xmm4
  UFG::qVector4 v280; // xmm5
  UFG::qVector4 v281; // xmm3
  UFG::qVector4 v282; // xmm1
  float v283; // xmm7_4
  float v284; // xmm6_4
  float v285; // xmm0_4
  float v286; // xmm0_4
  int v287; // eax
  float v288; // xmm8_4
  float *v289; // rbx
  float *v290; // rax
  float v291; // xmm3_4
  __m128 v292; // xmm6
  float v293; // xmm7_4
  __m128 v294; // xmm2
  float v295; // xmm5_4
  float v296; // xmm0_4
  float v297; // xmm6_4
  float v298; // xmm7_4
  float v299; // xmm7_4
  __int64 v300; // rax
  float v301; // xmm3_4
  __m128 v302; // xmm2
  float v303; // xmm1_4
  float v304; // xmm1_4
  float v305; // xmm2_4
  float v306; // xmm1_4
  float v307; // xmm4_4
  float v308; // xmm1_4
  __m128 v309; // xmm2
  float v310; // xmm0_4
  float v311; // xmm7_4
  float v312; // xmm8_4
  float v313; // xmm9_4
  __int64 v314; // rax
  __m128 v315; // xmm5
  float v316; // xmm13_4
  __m128 v317; // xmm1
  float v318; // xmm10_4
  float v319; // xmm0_4
  float v320; // xmm4_4
  float v321; // xmm6_4
  float v322; // xmm0_4
  __m128 v323; // xmm3
  __m128 v324; // xmm2
  __m128 v325; // xmm1
  float v326; // xmm0_4
  __int64 v327; // rcx
  float *v328; // rax
  __m128 v329; // xmm3
  __m128 v330; // xmm2
  __m128 v331; // xmm1
  float v332; // xmm0_4
  float v333; // xmm0_4
  UFG::qVector3 desEye; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 desLook; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 duration; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 look; // [rsp+70h] [rbp-90h]
  float v338; // [rsp+80h] [rbp-80h]
  __int64 v339; // [rsp+84h] [rbp-7Ch]
  float v340; // [rsp+8Ch] [rbp-74h]
  float v341; // [rsp+90h] [rbp-70h]
  UFG::qVector3 v342; // [rsp+98h] [rbp-68h]
  UFG::qVector3 axis; // [rsp+A8h] [rbp-58h]
  UFG::qMatrix44 m; // [rsp+C0h] [rbp-40h]
  UFG::qVector3 v345; // [rsp+100h] [rbp+0h]
  UFG::qVector3 t; // [rsp+110h] [rbp+10h]
  UFG::qMatrix44 v347; // [rsp+120h] [rbp+20h]
  UFG::qMatrix44 mat; // [rsp+160h] [rbp+60h]
  UFG::qMatrix44 v349; // [rsp+1A0h] [rbp+A0h]
  UFG::qMatrix44 dest; // [rsp+1E0h] [rbp+E0h]
  UFG::qVector3 eye; // [rsp+220h] [rbp+120h]
  UFG::qQuaternion v352; // [rsp+230h] [rbp+130h]
  UFG::qQuaternion b; // [rsp+240h] [rbp+140h]
  UFG::qQuaternion result; // [rsp+250h] [rbp+150h]
  UFG::qQuaternion a; // [rsp+260h] [rbp+160h]
  UFG::qQuaternion v356; // [rsp+270h] [rbp+170h]
  UFG::qMatrix44 v357; // [rsp+280h] [rbp+180h]
  float v358; // [rsp+3B0h] [rbp+2B0h]
  float v359; // [rsp+3B8h] [rbp+2B8h]

  v3 = delta_sec;
  v4 = this;
  if ( UFG::Metrics::msInstance.mSimTimeDelta > 0.0 )
  {
    UFG::FollowCameraComponent::SafetyDetectInconsistentCameraMode(this, UFG::Metrics::msInstance.mSimTimeDelta);
    if ( !UFG::gFlowController.mCurrentState
      || !UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
    {
      if ( v4->mActive )
      {
        v5 = v4->mTransitionParamEye - (float)(delta_sec * v4->mTransitionParamRateEye);
        v6 = v5;
        v4->mTransitionParamEye = v5;
        if ( v5 <= 0.0 )
        {
          v6 = 0.0;
        }
        else if ( v5 >= 1.0 )
        {
          v6 = *(float *)&FLOAT_1_0;
        }
        v7 = v4->mTransitionParamOrient;
        v4->mTransitionParamEye = v6;
        v8 = v7 - (float)(v3 * v4->mTransitionParamRateOrient);
        v9 = v8;
        v4->mTransitionParamOrient = v8;
        if ( v8 <= 0.0 )
        {
          v9 = 0.0;
        }
        else if ( v8 >= 1.0 )
        {
          v9 = *(float *)&FLOAT_1_0;
        }
        v10 = v4->mTransitionParamSuppEye;
        v4->mTransitionParamOrient = v9;
        v11 = v10 - (float)(v3 * v4->mTransitionParamRateSuppEye);
        v12 = v11;
        v4->mTransitionParamSuppEye = v11;
        if ( v11 <= 0.0 )
        {
          v12 = 0.0;
        }
        else if ( v11 >= 1.0 )
        {
          v12 = *(float *)&FLOAT_1_0;
        }
        v13 = v4->mTransitionParamSuppLook;
        v4->mTransitionParamSuppEye = v12;
        v14 = v13 - (float)(v3 * v4->mTransitionParamRateSuppLook);
        v15 = v14;
        v4->mTransitionParamSuppLook = v14;
        if ( v14 <= 0.0 )
        {
          v15 = 0.0;
        }
        else if ( v14 >= 1.0 )
        {
          v15 = *(float *)&FLOAT_1_0;
        }
        v16 = v4->mTarget.m_pSimComponent == 0i64;
        v4->mTransitionParamSuppLook = v15;
        if ( !v16 )
          goto LABEL_290;
        if ( LocalPlayer )
          ((void (__fastcall *)(UFG::FollowCameraComponent *))v4->vfptr[16].__vecDelDtor)(v4);
        if ( v4->mTarget.m_pSimComponent )
        {
LABEL_290:
          if ( v4->bResetFromTarget )
            UFG::FollowCameraComponent::ResetFromTarget(v4, 1);
          if ( v3 > 0.050000001 )
            v3 = FLOAT_0_050000001;
          if ( !v4->bUpdateFromAimComp )
          {
            if ( !v4->mResetNext )
              ((void (__fastcall *)(UFG::FollowCameraComponent *))v4->vfptr[14].__vecDelDtor)(v4);
            v17 = v4->mResetNext;
            if ( v17 >= 0 )
              v4->mResetNext = v17 - 1;
          }
          UFG::GameCameraComponent::Update((UFG::GameCameraComponent *)&v4->vfptr, v3);
          UFG::FollowCameraComponent::UpdateBlendedParams(v4, v3);
          UFG::FollowCameraComponent::UpdateTweaker(v4, v3);
          v18 = (_DWORD *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)();
          v19 = (_DWORD *)&v4->mVelocity.mDuration.x;
          v20 = v18[1];
          v21 = v18[2];
          v19[21] = *v18;
          v19[22] = v20;
          v19[23] = v21;
          UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mVelocity);
          v22 = 0;
          *(_QWORD *)&v4->mVelocity.mParameter.x = 0i64;
          v4->mVelocity.mParameter.z = 0.0;
          UFG::HomerCubic<UFG::qVector3>::Update(&v4->mVelocity, v3);
          if ( UFG::FollowCameraComponent::bHorizCompUseTweakables )
            v23 = UFG::FollowCameraComponent::rHorizCompSpeedWindowTimespan;
          else
            v23 = v4->mBlendedParams.mHorizCompSpeedWindowTimespan;
          if ( v23 != v4->mHorizCompTargetSpeedSubmittedTimespan )
          {
            UFG::qAverageWindow<float>::SetTimespan(&v4->mHorizCompTargetSpeedWindow, v23, 30.0);
            v4->mHorizCompTargetSpeedSubmittedTimespan = v23;
          }
          if ( v3 > 0.0 )
          {
            v24 = v4->mCamera.mTransformation.v0.x;
            v25 = v4->mCamera.mTransformation.v0.y;
            v26 = v4->mCamera.mTransformation.v0.z;
            v27 = ((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)();
            v28 = (__m128)*(unsigned int *)(v27 + 4);
            v28.m128_f32[0] = (float)((float)((float)(v28.m128_f32[0] * v25) + (float)(*(float *)v27 * v24))
                                    + (float)(*(float *)(v27 + 8) * v26))
                            / (float)((float)((float)(v25 * v25) + (float)(v24 * v24)) + (float)(v26 * v26));
            v29 = v28;
            v29.m128_f32[0] = (float)((float)((float)(v29.m128_f32[0] * v25) * (float)(v29.m128_f32[0] * v25))
                                    + (float)((float)(v28.m128_f32[0] * v24) * (float)(v28.m128_f32[0] * v24)))
                            + (float)((float)(v28.m128_f32[0] * v26) * (float)(v28.m128_f32[0] * v26));
            UFG::qAverageWindow<float>::AddValue(&v4->mHorizCompTargetSpeedWindow, COERCE_FLOAT(_mm_sqrt_ps(v29)), v3);
          }
          v30 = v4->mHorizCompOffset.p1;
          v31 = 0;
          v32 = v30 < 0.0;
          if ( v30 > 0.0 )
          {
            if ( v30 > v4->mHorizCompOffset.p0 )
            {
LABEL_46:
              v31 = 1;
LABEL_47:
              if ( UFG::FollowCameraComponent::bHorizCompUseTweakables )
              {
                v33 = UFG::FollowCameraComponent::rHorizCompDurationAttack;
                v34 = UFG::FollowCameraComponent::rHorizCompDurationDecay;
              }
              else
              {
                v33 = v4->mBlendedParams.mHorizCompDurationAttack;
                v34 = v4->mBlendedParams.mHorizCompDurationDecay;
              }
              v16 = v31 == 0;
              v35 = &v4->mHorizCompOffset;
              v358 = v33;
              v36 = &v358;
              v37 = v4->mHorizCompOffset.mParameter;
              v359 = v34;
              if ( v16 )
                v36 = &v359;
              v38 = v37 / v35->mDuration;
              v39 = *v36;
              v4->mHorizCompOffset.mParameter = v38;
              if ( v39 <= 0.0099999998 )
                v39 = FLOAT_0_0099999998;
              v35->mDuration = v39;
              v4->mHorizCompOffset.mParameter = v39 * v38;
              UFG::HomerCubic<float>::MakeCoeffs(v35);
              UFG::FollowCameraComponent::UpdateLocalWorld(v4, v3);
              v40 = v4->mPassThroughTimer1;
              if ( v40 > 0.0 )
              {
                v41 = v40 - v3;
                v4->mPassThroughTimer1 = v41;
                if ( v41 <= 0.0 )
                  v4->pSimObjectPassThru1 = 0i64;
              }
              v42 = v4->mPassThroughTimer2;
              if ( v42 > 0.0 )
              {
                v43 = v42 - v3;
                v4->mPassThroughTimer2 = v43;
                if ( v43 <= 0.0 )
                  v4->pSimObjectPassThru2 = 0i64;
              }
              UFG::FollowCameraComponent::UpdateControllers(v4, v3);
              if ( v4->mSnapNext )
              {
                v4->mSnapNext = 0;
                UFG::FollowCameraComponent::Snap(v4);
              }
              duration.x = UFG::FollowCameraComponent::rOffsetLookDuration;
              duration.y = UFG::FollowCameraComponent::rOffsetLookDuration;
              duration.z = UFG::FollowCameraComponent::rOffsetLookDuration;
              UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mOffsetLook, &duration);
              duration.x = UFG::FollowCameraComponent::rOffsetEyeDuration;
              duration.y = UFG::FollowCameraComponent::rOffsetEyeDuration;
              duration.z = UFG::FollowCameraComponent::rOffsetEyeDuration;
              UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mOffsetEye, &duration);
              if ( v4->mTarget.m_pSimComponent
                && (v44 = (UFG::SimObjectCVBase *)v4->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
              {
                v45 = v44->m_Flags;
                if ( (v45 >> 14) & 1 )
                {
                  v46 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v44);
                }
                else if ( (v45 & 0x8000u) == 0 )
                {
                  if ( (v45 >> 13) & 1 )
                  {
                    v46 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v44->vfptr,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
                  }
                  else if ( (v45 >> 12) & 1 )
                  {
                    v46 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v44->vfptr,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
                  }
                  else
                  {
                    v46 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                      (UFG::SimObject *)&v44->vfptr,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
                  }
                }
                else
                {
                  v46 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v44);
                }
              }
              else
              {
                v46 = 0i64;
              }
              if ( v46 )
                v47 = v46->m_pEquippedSOWPC.m_pPointer;
              else
                v47 = 0i64;
              v48 = UFG::tbRecoilUseTweakables || !v47;
              v49 = v4->mRecoilAngleDesired;
              if ( v48 )
              {
                if ( v49 <= 0.0 )
                  v50 = UFG::trRecoilKickupRateDecay;
                else
                  v50 = UFG::trRecoilKickupRateAttack;
                v51 = UFG::trRecoilKickbackDur;
              }
              else
              {
                v52 = *((_QWORD *)&v47[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v47[2].m_pSimObject));
                v50 = *(float *)(v52 + 428);
                v51 = *(float *)(v52 + 444);
              }
              if ( UFG::qApproach(&v4->mRecoilAngle, v49, (float)(v50 * 3.1415927) * 0.0055555557, v3) )
              {
                if ( v4->mRecoilAngleDesired > 0.0 )
                  v4->mRecoilAngleDesired = 0.0;
                if ( 0.0 == v4->mRecoilAngleDesired && v4->mRecoilAngle > 0.0 )
                  UFG::GameCameraComponent::ResetAimWobble((UFG::GameCameraComponent *)&v4->vfptr);
              }
              duration.x = v51;
              duration.y = v51;
              duration.z = v51;
              UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mRecoilEye, &duration);
              UFG::HomerCubic<UFG::qVector3>::Update(&v4->mLook, v3);
              UFG::HomerCubic<UFG::qVector3>::Update(&v4->mEye, v3);
              UFG::HomerCubic<float>::Update(&v4->mFov, v3);
              UFG::HomerCubic<UFG::qVector3>::Update(&v4->mOffsetLook, v3);
              UFG::HomerCubic<UFG::qVector3>::Update(&v4->mOffsetEye, v3);
              UFG::HomerCubic<UFG::qVector3>::Update(&v4->mRecoilEye, v3);
              UFG::HomerCubic<float>::Update(&v4->mHorizCompOffset, v3);
              UFG::HomerCubic<UFG::qVector3>::Update(&v4->mAimEye, v3);
              UFG::HomerCubic<UFG::qVector3>::Update(&v4->mAimLook, v3);
              if ( v4->rAimParameter > 0.0 && !v4->bAimUseEyeLook )
              {
                v53 = v4->mOffsetLook.p1.y;
                v54 = v4->mOffsetLook.p1.z;
                v4->mOffsetLook.p0.x = v4->mOffsetLook.p1.x;
                v4->mOffsetLook.p0.y = v53;
                v4->mOffsetLook.p0.z = v54;
                v55 = v4->mOffsetLook.v1.y;
                v56 = v4->mOffsetLook.v1.z;
                v4->mOffsetLook.v0.x = v4->mOffsetLook.v1.x;
                v4->mOffsetLook.v0.y = v55;
                v4->mOffsetLook.v0.z = v56;
                UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mOffsetLook);
                *(_QWORD *)&v4->mOffsetLook.mParameter.x = 0i64;
                v4->mOffsetLook.mParameter.z = 0.0;
                v57 = v4->mOffsetEye.p1.z;
                v58 = v4->mOffsetEye.p1.x;
                v4->mOffsetEye.p0.y = v4->mOffsetEye.p1.y;
                v4->mOffsetEye.p0.z = v57;
                v4->mOffsetEye.p0.x = v58;
                v59 = v4->mOffsetEye.v1.y;
                v60 = v4->mOffsetEye.v1.z;
                v4->mOffsetEye.v0.x = v4->mOffsetEye.v1.x;
                v4->mOffsetEye.v0.y = v59;
                v4->mOffsetEye.v0.z = v60;
                UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mOffsetEye);
                *(_QWORD *)&v4->mOffsetEye.mParameter.x = 0i64;
                v4->mOffsetEye.mParameter.z = 0.0;
                v61 = v4->mLook.p1.x;
                v62 = v4->mLook.p1.z;
                v4->mLook.p0.y = v4->mLook.p1.y;
                v4->mLook.p0.z = v62;
                v4->mLook.p0.x = v61;
                v63 = v4->mLook.v1.y;
                v64 = v4->mLook.v1.z;
                v4->mLook.v0.x = v4->mLook.v1.x;
                v4->mLook.v0.y = v63;
                v4->mLook.v0.z = v64;
                UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mLook);
                *(_QWORD *)&v4->mLook.mParameter.x = 0i64;
                v4->mLook.mParameter.z = 0.0;
                v65 = v4->mEye.p1.y;
                v66 = v4->mEye.p1.z;
                v4->mEye.p0.x = v4->mEye.p1.x;
                v4->mEye.p0.y = v65;
                v4->mEye.p0.z = v66;
                v67 = v4->mEye.v1.y;
                v68 = v4->mEye.v1.z;
                v4->mEye.v0.x = v4->mEye.v1.x;
                v4->mEye.v0.y = v67;
                v4->mEye.v0.z = v68;
                UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mEye);
                *(_QWORD *)&v4->mEye.mParameter.x = 0i64;
                v4->mEye.mParameter.z = 0.0;
              }
              v70 = (__m128)LODWORD(v4->mLook.p1.y);
              v69 = v4->mLook.p1.x - v4->mEye.p1.x;
              v70.m128_f32[0] = v70.m128_f32[0] - v4->mEye.p1.y;
              v78 = v70;
              v71 = (float)(v4->mLook.p1.z - v4->mEye.p1.z) * (float)(v4->mLook.p1.z - v4->mEye.p1.z);
              v72 = v4->mEye.p0.x + v4->mRecoilEye.p0.x;
              v73 = v4->mEye.p0.y + v4->mRecoilEye.p0.y;
              v74 = v4->mEye.p0.z + v4->mRecoilEye.p0.z;
              v75 = v4->mLook.p0.x;
              v76 = v4->mLook.p0.y;
              v77 = v4->mLook.p0.z;
              desEye.x = v4->mEye.p0.x + v4->mRecoilEye.p0.x;
              desEye.y = v73;
              v78.m128_f32[0] = (float)((float)(v70.m128_f32[0] * v70.m128_f32[0]) + (float)(v69 * v69)) + v71;
              desEye.z = v74;
              desLook.x = v75;
              desLook.y = v76;
              desLook.z = v77;
              if ( v78.m128_f32[0] == 0.0 )
                v79 = 0.0;
              else
                v79 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v78));
              v80 = v4->mRecoilAngle;
              v81 = v69 * v79;
              axis.z = 0.0;
              v82 = v75 - v72;
              v83 = v76 - v73;
              v84 = v77 - v74;
              *((float *)&v339 + 1) = v81;
              *(float *)&v339 = v70.m128_f32[0] * v79;
              axis.x = v70.m128_f32[0] * v79;
              LODWORD(axis.y) = LODWORD(v81) ^ _xmm[0];
              UFG::qRotationMatrixAxis(&dest, &axis, COERCE_FLOAT(LODWORD(v80) ^ _xmm[0]));
              v85 = v4->mTransitionParamDutch;
              v86 = (__m128)LODWORD(v4->mTransitionParamDutch);
              v86.m128_f32[0] = (float)(v86.m128_f32[0] * v4->mUpFrom.y) + UFG::qVector3::msDirUp.y;
              v91 = v86;
              v338 = desEye.x
                   + (float)((float)((float)((float)(v82 * dest.v0.x) + (float)(v83 * dest.v1.x))
                                   + (float)(v84 * dest.v2.x))
                           + dest.v3.x);
              v359 = (float)((float)((float)((float)(v82 * dest.v0.y) + (float)(v83 * dest.v1.y))
                                   + (float)(v84 * dest.v2.y))
                           + dest.v3.y)
                   + desEye.y;
              v87 = v85;
              v88 = (float)(v85 * v4->mUpFrom.z) + UFG::qVector3::msDirUp.z;
              v89 = (float)((float)((float)((float)(v82 * dest.v0.z) + (float)(v83 * dest.v1.z))
                                  + (float)(v84 * dest.v2.z))
                          + dest.v3.z)
                  + desEye.z;
              v90 = (float)(v87 * v4->mUpFrom.x) + UFG::qVector3::msDirUp.x;
              v91.m128_f32[0] = (float)((float)(v86.m128_f32[0] * v86.m128_f32[0]) + (float)(v90 * v90))
                              + (float)(v88 * v88);
              if ( v91.m128_f32[0] == 0.0 )
                v92 = 0.0;
              else
                v92 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v91));
              v93 = v4->mOffsetLook.p0.z;
              v94 = v4->mOffsetLook.p0.x;
              v95 = v90 * v92;
              v96 = v86.m128_f32[0] * v92;
              v97 = v92 * v88;
              v98 = v4->mOffsetLook.p0.x;
              v99 = v4->mOffsetLook.p0.z;
              v100 = v4->mOffsetLook.p0.y + v4->mHorizCompOffset.p0;
              v340 = v95;
              v341 = v97;
              v101 = v93 * v95;
              v102 = v93 * v97;
              v358 = v96;
              v103 = (float)((float)(v98 * *((float *)&v339 + 1)) + (float)(v100 * axis.x)) + v101;
              v104 = v4->mOffsetEye.p0.y;
              v105 = v4->mOffsetEye.p0.y;
              v106 = v338 + v103;
              v107 = (float)((float)(v94 * *(float *)&v339) + (float)(v100 * axis.y)) + (float)(v99 * v96);
              v338 = v106;
              v108 = (float)((float)(v94 * 0.0) + (float)(v100 * axis.z)) + v102;
              v109 = v4->mOffsetEye.p0.z;
              desLook.x = v106;
              v110 = v89 + v108;
              v111 = v4->mOffsetEye.p0.x;
              v112 = v4->mOffsetEye.p0.x * *(float *)&v339;
              v113 = v359 + v107;
              desLook.z = v110;
              v359 = v113;
              desLook.y = v113;
              v114 = desEye.y + (float)((float)(v112 + (float)(v105 * axis.y)) + (float)(v109 * v96));
              v115 = (float)((float)(v111 * *((float *)&v339 + 1)) + (float)(v104 * axis.x)) + (float)(v109 * v340);
              desEye.y = v114;
              v116 = desEye.x + v115;
              desEye.z = desEye.z
                       + (float)((float)((float)(v111 * 0.0) + (float)(v104 * axis.z)) + (float)(v109 * v341));
              desEye.x = desEye.x + v115;
              if ( v4->bAimUseEyeLook )
              {
                v117 = (__m128)LODWORD(v359);
                v118 = v338;
                v4->rAimParameter = 1.0;
              }
              else
              {
                UFG::qApproach(&v4->rAimParameter, 0.0, UFG::FollowCameraComponent::rAimTransitionRateOut, v3);
                v110 = desLook.z;
                v117 = (__m128)LODWORD(desLook.y);
                v118 = desLook.x;
                v116 = desEye.x;
                v114 = desEye.y;
              }
              v119 = v110 - desEye.z;
              v117.m128_f32[0] = v117.m128_f32[0] - v114;
              v120 = v118 - v116;
              v121 = v117;
              v121.m128_f32[0] = (float)((float)(v117.m128_f32[0] * v117.m128_f32[0]) + (float)(v120 * v120))
                               + (float)(v119 * v119);
              if ( v121.m128_f32[0] == 0.0 )
                v122 = 0.0;
              else
                v122 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v121));
              v123 = v341;
              v124 = v122;
              v125 = v122;
              v126 = v122 * v119;
              v127 = v340;
              mat.v0.w = 0.0;
              v128 = v124 * v120;
              v129 = v125 * v117.m128_f32[0];
              v130 = (__m128)LODWORD(v358);
              mat.v0.z = v126;
              v131 = v130;
              mat.v0.x = v128;
              mat.v0.y = v129;
              v131.m128_f32[0] = (float)((float)(v130.m128_f32[0] * v130.m128_f32[0]) + (float)(v127 * v127))
                               + (float)(v123 * v123);
              if ( v131.m128_f32[0] == 0.0 )
              {
                v132 = 0i64;
              }
              else
              {
                v132 = (__m128)(unsigned int)FLOAT_1_0;
                v132.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v131));
              }
              v133 = v132.m128_f32[0];
              v134 = v132.m128_f32[0];
              v132.m128_f32[0] = v132.m128_f32[0] * v341;
              v135 = v133 * v358;
              v136 = v134 * v340;
              v137 = (float)(v135 * v126) - (float)(v132.m128_f32[0] * v129);
              v132.m128_f32[0] = (float)(v132.m128_f32[0] * v128) - (float)(v136 * v126);
              v138 = (float)(v136 * v129) - (float)(v135 * v128);
              v139 = v132;
              v139.m128_f32[0] = (float)((float)(v132.m128_f32[0] * v132.m128_f32[0]) + (float)(v137 * v137))
                               + (float)(v138 * v138);
              if ( v139.m128_f32[0] == 0.0 )
              {
                v141 = 0i64;
              }
              else
              {
                LODWORD(v140) = (unsigned __int128)_mm_sqrt_ps(v139);
                v141 = (__m128)(unsigned int)FLOAT_1_0;
                v141.m128_f32[0] = 1.0 / v140;
              }
              v142 = v141;
              mat.v1.w = 0.0;
              v142.m128_f32[0] = v141.m128_f32[0] * v137;
              v145 = v142;
              mat.v1.x = v141.m128_f32[0] * v137;
              mat.v1.z = v141.m128_f32[0] * v138;
              mat.v1.y = v141.m128_f32[0] * v132.m128_f32[0];
              v143 = (float)((float)(v141.m128_f32[0] * v138) * v129)
                   - (float)((float)(v141.m128_f32[0] * v132.m128_f32[0]) * v126);
              v144 = (float)((float)(v141.m128_f32[0] * v132.m128_f32[0]) * v128)
                   - (float)((float)(v141.m128_f32[0] * v137) * v129);
              v145.m128_f32[0] = (float)(v142.m128_f32[0] * v126) - (float)(mat.v1.z * v128);
              v146 = v145;
              v146.m128_f32[0] = (float)((float)(v145.m128_f32[0] * v145.m128_f32[0]) + (float)(v143 * v143))
                               + (float)(v144 * v144);
              if ( v146.m128_f32[0] == 0.0 )
                v147 = 0.0;
              else
                v147 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v146));
              mat.v2.w = 0.0;
              mat.v3.w = 1.0;
              mat.v2.z = v147 * v144;
              mat.v2.y = v147 * v145.m128_f32[0];
              mat.v2.x = v147 * v143;
              *(UFG::qVector3 *)&mat.v3.x = desEye;
              UFG::qQuaternion::Set(&a, &mat);
              v148 = (__m128)LODWORD(desEye.y);
              v150 = (__m128)LODWORD(v4->mAimLook.p0.y);
              v149 = v4->mAimLook.p0.x - v4->mAimEye.p0.x;
              v150.m128_f32[0] = v150.m128_f32[0] - v4->mAimEye.p0.y;
              v151 = v4->mAimLook.p0.z;
              v339 = *(_QWORD *)&desEye.y;
              v152 = v151 - v4->mAimEye.p0.z;
              v359 = desEye.x;
              v148.m128_f32[0] = (float)((float)((float)(desEye.y - desLook.y) * (float)(desEye.y - desLook.y))
                                       + (float)((float)(desEye.x - desLook.x) * (float)(desEye.x - desLook.x)))
                               + (float)((float)(desEye.z - desLook.z) * (float)(desEye.z - desLook.z));
              LODWORD(v153) = (unsigned __int128)_mm_sqrt_ps(v148);
              v154 = v150;
              v338 = v153;
              v154.m128_f32[0] = (float)((float)(v150.m128_f32[0] * v150.m128_f32[0]) + (float)(v149 * v149))
                               + (float)(v152 * v152);
              if ( v154.m128_f32[0] == 0.0 )
                v155 = 0.0;
              else
                v155 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v154));
              v156 = v155;
              v157 = v155;
              v158 = v155 * v152;
              v349.v0.w = 0.0;
              v159 = v156 * v149;
              v160 = v157 * v150.m128_f32[0];
              v349.v0.z = v158;
              v349.v0.x = v159;
              v349.v0.y = v160;
              if ( v131.m128_f32[0] == 0.0 )
              {
                v161 = 0i64;
              }
              else
              {
                v161 = (__m128)(unsigned int)FLOAT_1_0;
                v161.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v131));
              }
              v162 = v161.m128_f32[0];
              v163 = v161.m128_f32[0];
              v161.m128_f32[0] = v161.m128_f32[0] * v123;
              v164 = v162 * v358;
              v165 = v163 * v127;
              v166 = (float)(v164 * v158) - (float)(v161.m128_f32[0] * v160);
              v161.m128_f32[0] = (float)(v161.m128_f32[0] * v159) - (float)(v165 * v158);
              v167 = (float)(v165 * v160) - (float)(v164 * v159);
              v168 = v161;
              v168.m128_f32[0] = (float)((float)(v161.m128_f32[0] * v161.m128_f32[0]) + (float)(v166 * v166))
                               + (float)(v167 * v167);
              if ( v168.m128_f32[0] == 0.0 )
              {
                v170 = 0i64;
              }
              else
              {
                LODWORD(v169) = (unsigned __int128)_mm_sqrt_ps(v168);
                v170 = (__m128)(unsigned int)FLOAT_1_0;
                v170.m128_f32[0] = 1.0 / v169;
              }
              v171 = v170;
              v349.v1.w = 0.0;
              v171.m128_f32[0] = v170.m128_f32[0] * v166;
              v174 = v171;
              v349.v1.x = v170.m128_f32[0] * v166;
              v349.v1.z = v170.m128_f32[0] * v167;
              v349.v1.y = v170.m128_f32[0] * v161.m128_f32[0];
              v172 = (float)((float)(v170.m128_f32[0] * v167) * v160)
                   - (float)((float)(v170.m128_f32[0] * v161.m128_f32[0]) * v158);
              v173 = (float)((float)(v170.m128_f32[0] * v161.m128_f32[0]) * v159)
                   - (float)((float)(v170.m128_f32[0] * v166) * v160);
              v174.m128_f32[0] = (float)(v171.m128_f32[0] * v158) - (float)(v349.v1.z * v159);
              v175 = v174;
              v175.m128_f32[0] = (float)((float)(v174.m128_f32[0] * v174.m128_f32[0]) + (float)(v172 * v172))
                               + (float)(v173 * v173);
              if ( v175.m128_f32[0] == 0.0 )
                v176 = 0.0;
              else
                v176 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v175));
              v177 = v4->mAimEye.p0.z;
              v349.v2.w = 0.0;
              v349.v3.z = v177;
              v349.v2.z = v176 * v173;
              v349.v3.w = 1.0;
              v349.v2.x = v176 * v172;
              v178 = v4->mAimEye.p0.y;
              v349.v2.y = v176 * v174.m128_f32[0];
              v179 = v4->mAimEye.p0.x;
              v349.v3.y = v178;
              v349.v3.x = v179;
              UFG::qQuaternion::Set(&b, &v349);
              v180 = (float)(sinf((float)(v4->rAimParameter * 3.1415927) - 1.5707964) + 1.0) * 0.5;
              v181 = v180 * v4->mAimEye.p0.y;
              v182 = v180 * v4->mAimEye.p0.z;
              t.x = (float)((float)(1.0 - v180) * v359) + (float)(v180 * v4->mAimEye.p0.x);
              t.y = (float)((float)(1.0 - v180) * *(float *)&v339) + v181;
              t.z = (float)((float)(1.0 - v180) * *((float *)&v339 + 1)) + v182;
              UFG::qSlerp(&result, &a, &b, v180, 0);
              UFG::qQuaternion::GetMatrix(&result, &v357, &t);
              desEye = *(UFG::qVector3 *)&v357.v3.x;
              desLook.x = (float)(v338 * v357.v0.x) + v357.v3.x;
              desLook.y = (float)(v338 * v357.v0.y) + v357.v3.y;
              desLook.z = (float)(v338 * v357.v0.z) + v357.v3.z;
              v183 = UFG::LocalPlayerIsInCombatManager::IsInAnyCombat(UFG::LocalPlayerIsInCombatManager::s_pInstance, 0);
              if ( v4->bAllowDesaturation && v183 )
                v184 = v4->mBlendedParams.mDesaturation;
              else
                v184 = 0.0;
              v185 = v4->mBlendedParams.mMotionblurMagnitude;
              v4->mCamera.mDesaturation = v184;
              v4->mCamera.mMotionBlur = v185;
              if ( v4->mTarget.m_pSimComponent
                && (v186 = (UFG::SimObjectCharacter *)v4->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
              {
                v187 = v186->m_Flags;
                if ( (v187 >> 14) & 1 )
                {
                  v188 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v186);
                }
                else if ( (v187 & 0x8000u) == 0 )
                {
                  if ( (v187 >> 13) & 1 )
                  {
                    v188 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v186->vfptr,
                                                           UFG::AimingPlayerComponent::_TypeUID);
                  }
                  else if ( (v187 >> 12) & 1 )
                  {
                    v188 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v186->vfptr,
                                                           UFG::AimingPlayerComponent::_TypeUID);
                  }
                  else
                  {
                    v188 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)&v186->vfptr,
                                                           UFG::AimingPlayerComponent::_TypeUID);
                  }
                }
                else
                {
                  v188 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v186->vfptr,
                                                         UFG::AimingPlayerComponent::_TypeUID);
                }
              }
              else
              {
                v188 = 0i64;
              }
              if ( v4->mTarget.m_pSimComponent
                && (v189 = (UFG::SimObjectCVBase *)v4->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
              {
                v190 = v189->m_Flags;
                if ( (v190 >> 14) & 1 )
                {
                  v191 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v189);
                }
                else if ( (v190 & 0x8000u) == 0 )
                {
                  if ( (v190 >> 13) & 1 )
                  {
                    v191 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v189->vfptr,
                                                                       UFG::TargetingSystemPedPlayerComponent::_TypeUID);
                  }
                  else if ( (v190 >> 12) & 1 )
                  {
                    v191 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v189->vfptr,
                                                                       UFG::TargetingSystemPedPlayerComponent::_TypeUID);
                  }
                  else
                  {
                    v191 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                       (UFG::SimObject *)&v189->vfptr,
                                                                       UFG::TargetingSystemPedPlayerComponent::_TypeUID);
                  }
                }
                else
                {
                  v191 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v189);
                }
              }
              else
              {
                v191 = 0i64;
              }
              if ( v191 )
              {
                v192 = v191->m_eFocusMode == 1;
                if ( v191->m_eFocusMode == 1 )
                {
                  v193 = v191->m_pTargets[(unsigned __int8)v191->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
LABEL_162:
                  if ( v188 )
                    v194 = v188->m_FreeAimSimObject.m_pPointer;
                  else
                    v194 = 0i64;
                  if ( v192 )
                    v194 = v193;
                  if ( v194 )
                    v195 = v194->m_pTransformNodeComponent;
                  else
                    v195 = 0i64;
                  v4->vfptr[19].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v4->vfptr, (unsigned int)v193);
                  v196 = tanf(v184 * 0.5);
                  duration = desLook;
                  look.x = v4->mBlendedParams.mTweakNoiseFrequency;
                  look.y = look.x;
                  v197 = (float)(v196 * 1.3) * v4->mBlendedParams.mTweakNoiseEyeMagnitude;
                  v198 = (float)(v196 * 1.3) * v4->mBlendedParams.mTweakNoiseLookMagnitude;
                  look.z = look.x;
                  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetFrequency(&v4->mLookNoise, &look, &duration);
                  look = desEye;
                  duration.x = v4->mBlendedParams.mTweakNoiseFrequency;
                  duration.y = duration.x;
                  duration.z = duration.x;
                  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetFrequency(&v4->mEyeNoise, &duration, &look);
                  look.x = v198;
                  look.y = v198;
                  look.z = v198;
                  LODWORD(duration.x) = LODWORD(v198) ^ _xmm[0];
                  LODWORD(duration.y) = LODWORD(v198) ^ _xmm[0];
                  LODWORD(duration.z) = LODWORD(v198) ^ _xmm[0];
                  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&v4->mLookNoise, &duration, &look);
                  look.x = v197;
                  look.y = v197;
                  look.z = v197;
                  LODWORD(duration.x) = LODWORD(v197) ^ _xmm[0];
                  LODWORD(duration.y) = LODWORD(v197) ^ _xmm[0];
                  LODWORD(duration.z) = LODWORD(v197) ^ _xmm[0];
                  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&v4->mEyeNoise, &duration, &look);
                  if ( 0.0 != v4->mBlendedParams.mTweakNoiseLookMagnitude )
                  {
                    look = desEye;
                    v199 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(&v4->mEyeNoise, &duration, &look);
                    v200 = desEye.z + v199->z;
                    v201 = desEye.x + v199->x;
                    desEye.y = desEye.y + v199->y;
                    desEye.z = v200;
                    desEye.x = v201;
                  }
                  if ( 0.0 != v4->mBlendedParams.mTweakNoiseEyeMagnitude )
                  {
                    look = desLook;
                    v202 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(&v4->mEyeNoise, &duration, &look);
                    v203 = desLook.z + v202->z;
                    v204 = desLook.x + v202->x;
                    desLook.y = desLook.y + v202->y;
                    desLook.z = v203;
                    desLook.x = v204;
                  }
                  if ( UFG::bHeadCamera )
                  {
                    UFG::CharacterSubjectComponent::GetHeadTransform(
                      (UFG::CharacterSubjectComponent *)v4->mTarget.m_pSimComponent,
                      &m);
                    v205 = v4->mTarget.m_pSimComponent;
                    v206 = (float)(1.0 - UFG::fHeadCameraLookBlend)
                         * (float)((float)((float)((float)(m.v1.x * 0.1) + (float)(m.v0.x * 0.0)) + (float)(m.v2.x * 0.0))
                                 + m.v3.x);
                    desEye.y = (float)((float)((float)(m.v1.y * 0.1) + (float)(m.v0.y * 0.0)) + (float)(m.v2.y * 0.0))
                             + m.v3.y;
                    desEye.x = (float)((float)((float)(m.v1.x * 0.1) + (float)(m.v0.x * 0.0)) + (float)(m.v2.x * 0.0))
                             + m.v3.x;
                    v207 = desEye.y * (float)(1.0 - UFG::fHeadCameraLookBlend);
                    desEye.z = (float)((float)((float)(m.v1.z * 0.1) + (float)(m.v0.z * 0.0)) + (float)(m.v2.z * 0.0))
                             + m.v3.z;
                    v208 = desEye.z * (float)(1.0 - UFG::fHeadCameraLookBlend);
                    v209 = (float *)((__int64 (*)(void))v205->vfptr[16].__vecDelDtor)();
                    v210 = v207 + v209[1];
                    v211 = v208 + v209[2];
                    desLook.x = (float)((float)((float)((float)(m.v1.x * UFG::fHeadCameraLookBlend)
                                                      + (float)(m.v0.x * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                              + (float)(m.v2.x * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                      + (float)(m.v3.x * UFG::fHeadCameraLookBlend))
                              + (float)(v206 + *v209);
                    desLook.y = (float)((float)((float)((float)(m.v1.y * UFG::fHeadCameraLookBlend)
                                                      + (float)(m.v0.y * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                              + (float)(m.v2.y * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                      + (float)(m.v3.y * UFG::fHeadCameraLookBlend))
                              + v210;
                    desLook.z = (float)((float)((float)((float)(m.v1.z * UFG::fHeadCameraLookBlend)
                                                      + (float)(m.v0.z * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                              + (float)(m.v2.z * (float)(UFG::fHeadCameraLookBlend * 0.0)))
                                      + (float)(m.v3.z * UFG::fHeadCameraLookBlend))
                              + v211;
                  }
                  v212 = v4->mTarget.m_pSimComponent;
                  if ( BYTE6(v212[15].m_SafePointerList.mNode.mNext) )
                    UFG::CharacterSubjectComponent::UpdatePelvis((UFG::CharacterSubjectComponent *)v4->mTarget.m_pSimComponent);
                  v213 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v212->vfptr[26].__vecDelDtor)(v212);
                  v4->mCollisionTargetPointsNum = 2;
                  v214 = v213[1];
                  v215 = v213[2];
                  v4->mCollisionTargetPoints[0].x = *v213;
                  v4->mCollisionTargetPoints[0].y = v214;
                  v4->mCollisionTargetPoints[0].z = v215;
                  v216 = *(float *)&v212[15].vfptr;
                  v217 = *((float *)&v212[15].vfptr + 1);
                  v4->mCollisionTargetPoints[1].x = *((float *)&v212[14].m_BoundComponentHandles.mNode.mNext + 1);
                  v4->mCollisionTargetPoints[1].y = v216;
                  v4->mCollisionTargetPoints[1].z = v217;
                  v218 = UFG::FollowCameraComponent::mFollowCollisionPlateau;
                  v16 = v4->mType == 1;
                  v219 = UFG::FollowCameraComponent::mFollowCollisionBlend;
                  v4->mCollisionRise = v4->mBlendedParams.mCollisionRise;
                  v4->mCollisionPlateau = v218;
                  v4->mPushInOverrideRate = 0.0;
                  v4->mCollisionBlend = v219;
                  if ( v16 )
                  {
                    if ( v4->mBlendedParams.mTweakUseSyncBase )
                    {
                      v220 = (UFG::SimObjectCharacter *)v4->mTarget.m_pSimComponent->m_pSimObject;
                      if ( v220 )
                      {
                        v222 = v220->m_Flags;
                        if ( (v222 >> 14) & 1 )
                        {
                          v221 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v220);
                        }
                        else if ( (v222 & 0x8000u) == 0 )
                        {
                          if ( (v222 >> 13) & 1 )
                          {
                            v221 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v220->vfptr,
                                                                   UFG::AimingPlayerComponent::_TypeUID);
                          }
                          else if ( (v222 >> 12) & 1 )
                          {
                            v221 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v220->vfptr,
                                                                   UFG::AimingPlayerComponent::_TypeUID);
                          }
                          else
                          {
                            v221 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                   (UFG::SimObject *)&v220->vfptr,
                                                                   UFG::AimingPlayerComponent::_TypeUID);
                          }
                        }
                        else
                        {
                          v221 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v220->vfptr,
                                                                 UFG::AimingPlayerComponent::_TypeUID);
                        }
                      }
                      else
                      {
                        v221 = 0i64;
                      }
                      v223 = v221->m_vFreeAimBaseOffset.x;
                      v224 = v221->m_vFreeAimBaseOffset.y;
                      v225 = v221->m_vFreeAimBaseOffset.z;
                    }
                    else
                    {
                      v226 = (float *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[26].__vecDelDtor)();
                      v223 = *v226;
                      v224 = v226[1];
                      v225 = v226[2];
                    }
                    v227 = desLook.y;
                    v228 = desLook.x;
                    v229 = desLook.z;
                    v4->mCollisionRise = 0.0;
                    v4->mCollisionBlend = 0.69999999;
                    v4->mCollisionPlateau = 0.69999999;
                    v230 = v227 - desEye.y;
                    v231 = v228 - desEye.x;
                    v232 = v229 - desEye.z;
                    v233 = (float)((float)((float)(v230 * (float)(v224 - desEye.y))
                                         + (float)(v231 * (float)(v223 - desEye.x)))
                                 + (float)(v232 * (float)(v225 - desEye.z)))
                         / (float)((float)((float)(v230 * v230) + (float)(v231 * v231)) + (float)(v232 * v232));
                    desLook.z = desEye.z + (float)(v233 * v232);
                    desLook.x = desEye.x + (float)(v233 * v231);
                    desLook.y = desEye.y + (float)(v233 * v230);
                  }
                  v4->mAlternateLookValid = 0;
                  UFG::CharacterSubjectComponent::GetRigidBodyPosition(
                    (UFG::CharacterSubjectComponent *)v4->mTarget.m_pSimComponent,
                    &v345);
                  v234 = desLook.z;
                  v235 = desLook.x;
                  v241 = (__m128)LODWORD(desLook.y);
                  v236 = v345.y;
                  v237 = desEye.x;
                  v238 = desEye.y;
                  v239 = (__m128)LODWORD(desEye.y);
                  v240 = desEye.z;
                  v239.m128_f32[0] = (float)(desEye.y - desLook.y) * (float)(desEye.y - desLook.y);
                  v4->mAlternateLook.x = v345.x;
                  v4->mAlternateLook.y = v236;
                  v241.m128_f32[0] = v241.m128_f32[0] - v238;
                  v242 = v237 - v235;
                  v243 = v235 - v237;
                  v4->mAlternateLook.z = v234;
                  v345.z = v234;
                  v4->mAlternateLookValid = 1;
                  v239.m128_f32[0] = (float)(v239.m128_f32[0] + (float)(v242 * v242))
                                   + (float)((float)(v240 - v234) * (float)(v240 - v234));
                  v244 = v234 - v240;
                  LODWORD(v245) = (unsigned __int128)_mm_sqrt_ps(v239);
                  v246 = v241;
                  v359 = v245;
                  v246.m128_f32[0] = (float)((float)(v241.m128_f32[0] * v241.m128_f32[0]) + (float)(v243 * v243))
                                   + (float)(v244 * v244);
                  if ( v246.m128_f32[0] == 0.0 )
                    v247 = 0.0;
                  else
                    v247 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v246));
                  v248 = v247;
                  v249 = v247;
                  v250 = v247 * v244;
                  v347.v0.w = 0.0;
                  v251 = v248 * v243;
                  v252 = v249 * v241.m128_f32[0];
                  v347.v0.z = v250;
                  v347.v0.x = v251;
                  v347.v0.y = v252;
                  if ( v131.m128_f32[0] == 0.0 )
                  {
                    v253 = 0i64;
                  }
                  else
                  {
                    v253 = (__m128)(unsigned int)FLOAT_1_0;
                    v253.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v131));
                  }
                  v254 = v253.m128_f32[0];
                  v255 = v253.m128_f32[0];
                  v253.m128_f32[0] = v253.m128_f32[0] * v341;
                  v256 = v254 * v358;
                  v257 = v255 * v340;
                  v258 = (float)(v256 * v250) - (float)(v253.m128_f32[0] * v252);
                  v253.m128_f32[0] = (float)(v253.m128_f32[0] * v251) - (float)(v257 * v250);
                  v259 = (float)(v257 * v252) - (float)(v256 * v251);
                  v260 = v253;
                  v260.m128_f32[0] = (float)((float)(v253.m128_f32[0] * v253.m128_f32[0]) + (float)(v258 * v258))
                                   + (float)(v259 * v259);
                  if ( v260.m128_f32[0] == 0.0 )
                  {
                    v262 = 0i64;
                  }
                  else
                  {
                    LODWORD(v261) = (unsigned __int128)_mm_sqrt_ps(v260);
                    v262 = (__m128)(unsigned int)FLOAT_1_0;
                    v262.m128_f32[0] = 1.0 / v261;
                  }
                  v263 = v262;
                  v347.v1.w = 0.0;
                  v263.m128_f32[0] = v262.m128_f32[0] * v258;
                  v266 = v263;
                  v347.v1.x = v262.m128_f32[0] * v258;
                  v347.v1.z = v262.m128_f32[0] * v259;
                  v347.v1.y = v262.m128_f32[0] * v253.m128_f32[0];
                  v264 = (float)((float)(v262.m128_f32[0] * v259) * v252)
                       - (float)((float)(v262.m128_f32[0] * v253.m128_f32[0]) * v250);
                  v265 = (float)((float)(v262.m128_f32[0] * v253.m128_f32[0]) * v251)
                       - (float)((float)(v262.m128_f32[0] * v258) * v252);
                  v266.m128_f32[0] = (float)(v263.m128_f32[0] * v250) - (float)(v347.v1.z * v251);
                  v267 = v266;
                  v267.m128_f32[0] = (float)((float)(v266.m128_f32[0] * v266.m128_f32[0]) + (float)(v264 * v264))
                                   + (float)(v265 * v265);
                  if ( v267.m128_f32[0] == 0.0 )
                    v268 = 0.0;
                  else
                    v268 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v267));
                  v347.v2.w = 0.0;
                  v347.v2.z = v268 * v265;
                  v347.v3.w = 1.0;
                  v347.v2.x = v268 * v264;
                  v347.v2.y = v268 * v266.m128_f32[0];
                  *(UFG::qVector3 *)&v347.v3.x = desEye;
                  UFG::qQuaternion::Set(&v356, &v347);
                  v269 = v4->mTransitionParamEye;
                  v270 = desEye.z * (float)(1.0 - v269);
                  v271 = desEye.x * (float)(1.0 - v269);
                  v272 = (float)(v269 * v4->mTransitionFromEye.y) + (float)(desEye.y * (float)(1.0 - v269));
                  v273 = v4->mTransitionParamOrient;
                  v274 = v269 * v4->mTransitionFromEye.x;
                  v275 = v269 * v4->mTransitionFromEye.z;
                  v342.y = v272;
                  v342.x = v274 + v271;
                  v342.z = v275 + v270;
                  UFG::qSlerp(&v352, &v356, &v4->mTransitionFromOri, v273, 0);
                  v276 = v4->mTransitionParamEye;
                  desEye.y = v342.y;
                  v277 = (float)((float)(1.0 - v276) * v359) + (float)(v276 * v4->mTransitionFromLen);
                  desEye.x = v342.x;
                  desEye.z = v342.z;
                  v278 = UFG::qQuaternion::GetMatrix(&v352, &m, &v342);
                  v279 = (__m128)v278->v2;
                  v280 = v278->v0;
                  v281 = v278->v1;
                  v282 = v278->v3;
                  LODWORD(duration.y) = (unsigned __int128)_mm_shuffle_ps(v279, v279, 85);
                  v347.v1 = v281;
                  v347.v2 = (UFG::qVector4)v279;
                  v347.v0 = v280;
                  v347.v3 = v282;
                  LODWORD(duration.x) = v279.m128_i32[0];
                  LODWORD(duration.z) = (unsigned __int128)_mm_shuffle_ps(v279, v279, 170);
                  desLook.x = desEye.x + (float)(v277 * v280.x);
                  desLook.y = desEye.y + (float)(v277 * COERCE_FLOAT(_mm_shuffle_ps((__m128)v280, (__m128)v280, 85)));
                  desLook.z = desEye.z + (float)(v277 * COERCE_FLOAT(_mm_shuffle_ps((__m128)v280, (__m128)v280, 170)));
                  UFG::GameCameraComponent::SetDesiredEyeLookUp(
                    (UFG::GameCameraComponent *)&v4->vfptr,
                    v3,
                    &desEye,
                    &desLook,
                    a3,
                    &duration,
                    1,
                    &eye,
                    &look);
                  v283 = (float)(v4->mFov.p0 * 3.1415927) * 0.0055555557;
                  if ( !Render::GetRenderFeatures()->mForceLetterBox )
                    v283 = Render::GetExtraWideAspectCorrectedFOV(v283);
                  v284 = UFG::GameCameraComponent::ComputeNearOffset(
                           (UFG::GameCameraComponent *)&v4->vfptr,
                           &eye,
                           &look,
                           v283)
                       + UFG::gCameraDefaultNear;
                  v285 = Render::GetDisplayAspectRatio();
                  UFG::Camera::SetViewProjection(&v4->mCamera, v283, v285, v284, UFG::gCameraDefaultFar, 0.0, 0.0, 1);
                  v4->mPushInOverrideRate = 0.0;
                  UFG::Camera::ApplyDutch(&v4->mCamera, UFG::GameCameraComponent::mDutchDyn.p0);
                  if ( v4->mGotoAngleCollisionQueued )
                  {
                    if ( v4->mInCollision )
                    {
                      v286 = v4->mEyeCurr.z - v4->mLookCurr.z;
                      if ( (float)((float)((float)((float)(v4->mEyeCurr.y - v4->mLookCurr.y)
                                                 * (float)(v4->mEyeCurr.y - v4->mLookCurr.y))
                                         + (float)((float)(v4->mEyeCurr.x - v4->mLookCurr.x)
                                                 * (float)(v4->mEyeCurr.x - v4->mLookCurr.x)))
                                 + (float)(v286 * v286)) < (float)(UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius
                                                                 * UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius) )
                        UFG::FollowCameraComponent::GotoAngleCollision(
                          v4,
                          v4->mGotoAngleCollisionQueuedWallDist,
                          &desEye,
                          &desLook,
                          &duration);
                    }
                  }
                  v4->mGotoAngleCollisionQueued = 0;
                  UFG::FollowCameraComponent::DetermineMeleeAttackerPositions(v4);
                  v287 = v4->mNumMeleeAttackers;
                  if ( v287 <= 0 || v4->mBlendedParams.mSrcOrientation == 4 || v4->mBlendedParams.mSrcPosition == 4 )
                  {
                    if ( v4->mAutoFrameActive )
                    {
                      v4->mAutoFrameActive = 0;
                      v4->mMaxRadiusOverrideEnabled = 0;
                      v4->mRiseOverrideEnabled = 0;
                    }
                  }
                  else
                  {
                    v288 = 0.0;
                    if ( v287 <= 0 )
                    {
                      v301 = UFG::FollowCameraComponent::rAutoFrameFarthestDistClamp;
                    }
                    else
                    {
                      v289 = &v4->mMeleeAttackerPositions[0].z;
                      do
                      {
                        v290 = (float *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
                        v292 = (__m128)*((unsigned int *)v289 - 1);
                        v291 = *(v289 - 2) - *v290;
                        v292.m128_f32[0] = v292.m128_f32[0] - v290[1];
                        v294 = v292;
                        v293 = *v289 - v290[2];
                        v294.m128_f32[0] = (float)((float)(v292.m128_f32[0] * v292.m128_f32[0]) + (float)(v291 * v291))
                                         + (float)(v293 * v293);
                        if ( v294.m128_f32[0] == 0.0 )
                          v295 = 0.0;
                        else
                          v295 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v294));
                        v296 = (float)((float)(COERCE_FLOAT(LODWORD(v4->mCamera.mTransformation.v2.y) ^ _xmm[0])
                                             * (float)(v295 * v292.m128_f32[0]))
                                     + (float)(COERCE_FLOAT(LODWORD(v4->mCamera.mTransformation.v2.x) ^ _xmm[0])
                                             * (float)(v295 * v291)))
                             + (float)(COERCE_FLOAT(LODWORD(v4->mCamera.mTransformation.v2.z) ^ _xmm[0])
                                     * (float)(v295 * v293));
                        v297 = (float)(UFG::FollowCameraComponent::rAutoFrameOffsetAngleStart * 3.1415927)
                             * 0.0055555557;
                        UFG::qACos(v296);
                        v298 = (float)(v296 - v297) / (float)(3.1415927 - v297);
                        if ( v298 <= 0.0 )
                        {
                          v298 = 0.0;
                        }
                        else if ( v298 >= 1.0 )
                        {
                          v298 = *(float *)&FLOAT_1_0;
                        }
                        v299 = v298 * UFG::FollowCameraComponent::rAutoFrameFarthestDistOffset;
                        v300 = ((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
                        v301 = UFG::FollowCameraComponent::rAutoFrameFarthestDistClamp;
                        v302 = (__m128)*(unsigned int *)(v300 + 4);
                        v302.m128_f32[0] = (float)((float)((float)(v302.m128_f32[0] - *(v289 - 1))
                                                         * (float)(v302.m128_f32[0] - *(v289 - 1)))
                                                 + (float)((float)(*(float *)v300 - *(v289 - 2))
                                                         * (float)(*(float *)v300 - *(v289 - 2))))
                                         + (float)((float)(*(float *)(v300 + 8) - *v289)
                                                 * (float)(*(float *)(v300 + 8) - *v289));
                        LODWORD(v303) = (unsigned __int128)_mm_sqrt_ps(v302);
                        if ( v303 > UFG::FollowCameraComponent::rAutoFrameFarthestDistClamp )
                          v303 = UFG::FollowCameraComponent::rAutoFrameFarthestDistClamp;
                        v304 = v303 + v299;
                        if ( v304 > v288 )
                          v288 = v304;
                        ++v22;
                        v289 += 3;
                      }
                      while ( v22 < v4->mNumMeleeAttackers );
                    }
                    if ( !v4->mAutoFrameActive )
                      v4->mAutoFrameFarthestAttackerDist = v301;
                    if ( v288 <= v4->mAutoFrameFarthestAttackerDist )
                      v305 = UFG::FollowCameraComponent::rAutoFrameFarthestDistShrinkRate;
                    else
                      v305 = UFG::FollowCameraComponent::rAutoFrameFarthestDistGrowRate;
                    UFG::qApproach(&v4->mAutoFrameFarthestAttackerDist, v288, v305, v3);
                    if ( v4->mAutoFrameSnapNextAttackerDist )
                      v4->mAutoFrameFarthestAttackerDist = v288;
                    v306 = v4->mAutoFrameFarthestAttackerDist;
                    if ( v306 <= UFG::FollowCameraComponent::rAutoFrameMinRadius )
                      v306 = UFG::FollowCameraComponent::rAutoFrameMinRadius;
                    UFG::FollowCameraComponent::SetOverrideMaxRadius(v4, v306);
                    v309 = (__m128)LODWORD(desEye.y);
                    v307 = v4->mBlendedParams.mTweakEyeRise;
                    v308 = v4->mBlendedParams.mTweakEyeRise;
                    v309.m128_f32[0] = desEye.y - desLook.y;
                    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                        v4->mBlendedParams.mTweakRadiusMax
                                      - UFG::FollowCameraComponent::rAutoFrameMinRadius) & _xmm) > 0.00000011920929 )
                    {
                      v309.m128_f32[0] = (float)(v309.m128_f32[0] * v309.m128_f32[0])
                                       + (float)((float)(desEye.x - desLook.x) * (float)(desEye.x - desLook.x));
                      v310 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v309)) - v4->mBlendedParams.mTweakRadiusMax)
                           / (float)(UFG::FollowCameraComponent::rAutoFrameMinRadius - v4->mBlendedParams.mTweakRadiusMax);
                      if ( v310 <= 0.0 )
                      {
                        v310 = 0.0;
                      }
                      else if ( v310 >= 1.0 )
                      {
                        v310 = *(float *)&FLOAT_1_0;
                      }
                      v308 = (float)((float)(UFG::FollowCameraComponent::rAutoFrameMinEyeRise - v307) * v310) + v307;
                    }
                    if ( v308 >= v4->mBlendedParams.mTweakEyeRise )
                      v308 = v4->mBlendedParams.mTweakEyeRise;
                    if ( v308 > v307 )
                      v308 = v4->mBlendedParams.mTweakEyeRise;
                    v4->mRiseOverride = v308;
                    v4->mRiseOverrideEnabled = 1;
                    v4->mAutoFrameActive = 1;
                  }
                  if ( v4->mBlendedParams.mUseDofParameters )
                  {
                    v311 = v4->mLookCurr.x - v4->mEyeCurr.x;
                    v312 = v4->mLookCurr.y - v4->mEyeCurr.y;
                    v313 = v4->mLookCurr.z - v4->mEyeCurr.z;
                    v314 = ((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[26].__vecDelDtor)();
                    v315 = (__m128)*(unsigned int *)(v314 + 4);
                    v316 = 1.0 / (float)((float)((float)(v312 * v312) + (float)(v311 * v311)) + (float)(v313 * v313));
                    v315.m128_f32[0] = (float)((float)((float)((float)(v315.m128_f32[0] - v4->mEyeCurr.y) * v312)
                                                     + (float)((float)(*(float *)v314 - v4->mEyeCurr.x) * v311))
                                             + (float)((float)(*(float *)(v314 + 8) - v4->mEyeCurr.z) * v313))
                                     * v316;
                    v317 = v315;
                    v317.m128_f32[0] = (float)((float)((float)(v317.m128_f32[0] * v312)
                                                     * (float)(v317.m128_f32[0] * v312))
                                             + (float)((float)(v315.m128_f32[0] * v311)
                                                     * (float)(v315.m128_f32[0] * v311)))
                                     + (float)((float)(v315.m128_f32[0] * v313) * (float)(v315.m128_f32[0] * v313));
                    LODWORD(v318) = (unsigned __int128)_mm_sqrt_ps(v317);
                    v319 = v318;
                    if ( v318 < UFG::trDofMinimumFocusDistanceAllTargets )
                      v319 = UFG::trDofMinimumFocusDistanceAllTargets;
                    UFG::GameCameraComponent::mDofFocusObjectDistNear = v319;
                    UFG::GameCameraComponent::mDofFocusObjectDistFar = v319;
                    v320 = v4->mDofFarFocalDist;
                    v321 = v318;
                    if ( v318 >= v320 )
                      v322 = UFG::FollowCameraComponent::mDofNormalFarDistGrowRate;
                    else
                      v322 = UFG::FollowCameraComponent::mDofNormalFarDistShrinkRate;
                    if ( v195 && (v4->mFreeAiming || v4->mSoftLocked || v4->mFocusLocked) )
                    {
                      UFG::TransformNodeComponent::UpdateWorldTransform(v195);
                      v323 = (__m128)LODWORD(v195->mWorldTransform.v3.y);
                      v323.m128_f32[0] = (float)((float)((float)(v323.m128_f32[0] - v4->mEyeCurr.y) * v312)
                                               + (float)((float)(v195->mWorldTransform.v3.x - v4->mEyeCurr.x) * v311))
                                       + (float)((float)(v195->mWorldTransform.v3.z - v4->mEyeCurr.z) * v313);
                      v324 = v323;
                      v324.m128_f32[0] = v323.m128_f32[0] * v316;
                      v325 = v324;
                      v325.m128_f32[0] = (float)((float)((float)(v325.m128_f32[0] * v312)
                                                       * (float)(v325.m128_f32[0] * v312))
                                               + (float)((float)((float)(v323.m128_f32[0] * v316) * v311)
                                                       * (float)((float)(v323.m128_f32[0] * v316) * v311)))
                                       + (float)((float)((float)(v323.m128_f32[0] * v316) * v313)
                                               * (float)((float)(v323.m128_f32[0] * v316) * v313));
                      LODWORD(v326) = (unsigned __int128)_mm_sqrt_ps(v325);
                      if ( v326 > v318 && v323.m128_f32[0] > 0.0 )
                        v321 = v326;
                      v320 = v4->mDofFarFocalDist;
                      if ( v321 >= v320 )
                        v322 = UFG::FollowCameraComponent::mDofAimingFarDistGrowRate;
                      else
                        v322 = UFG::FollowCameraComponent::mDofAimingFarDistShrinkRate;
                    }
                    else
                    {
                      v327 = (unsigned int)v4->mNumMeleeAttackers;
                      if ( (signed int)v327 >= 1 )
                      {
                        v328 = &v4->mMeleeAttackerPositions[0].z;
                        do
                        {
                          v329 = (__m128)*((unsigned int *)v328 - 1);
                          v329.m128_f32[0] = (float)((float)((float)(v329.m128_f32[0] - v4->mEyeCurr.y) * v312)
                                                   + (float)((float)(*(v328 - 2) - v4->mEyeCurr.x) * v311))
                                           + (float)((float)(*v328 - v4->mEyeCurr.z) * v313);
                          v330 = v329;
                          v330.m128_f32[0] = v329.m128_f32[0] * v316;
                          v331 = v330;
                          v331.m128_f32[0] = (float)((float)((float)(v331.m128_f32[0] * v312)
                                                           * (float)(v331.m128_f32[0] * v312))
                                                   + (float)((float)((float)(v329.m128_f32[0] * v316) * v311)
                                                           * (float)((float)(v329.m128_f32[0] * v316) * v311)))
                                           + (float)((float)((float)(v329.m128_f32[0] * v316) * v313)
                                                   * (float)((float)(v329.m128_f32[0] * v316) * v313));
                          LODWORD(v332) = (unsigned __int128)_mm_sqrt_ps(v331);
                          if ( v332 > v321 && v329.m128_f32[0] > 0.0 )
                            v321 = v332;
                          if ( v321 >= v320 )
                            v322 = UFG::FollowCameraComponent::mDofMeleeFarDistGrowRate;
                          else
                            v322 = UFG::FollowCameraComponent::mDofMeleeFarDistShrinkRate;
                          v328 += 3;
                          --v327;
                        }
                        while ( v327 );
                      }
                    }
                    UFG::qApproach(
                      &v4->mDofFarFocalDist,
                      v321,
                      COERCE_FLOAT(COERCE_UNSIGNED_INT(v320 - v321) & _xmm) * v322,
                      v3);
                    v333 = v4->mDofFarFocalDist;
                    if ( v333 > v318 )
                    {
                      if ( v333 < UFG::trDofMinimumFocusDistanceAllTargets )
                        v333 = UFG::trDofMinimumFocusDistanceAllTargets;
                      if ( v333 >= UFG::GameCameraComponent::mDofFocusObjectDistNear )
                      {
                        if ( v333 > UFG::GameCameraComponent::mDofFocusObjectDistFar )
                          UFG::GameCameraComponent::mDofFocusObjectDistFar = v333;
                      }
                      else
                      {
                        UFG::GameCameraComponent::mDofFocusObjectDistNear = v333;
                      }
                    }
                  }
                  if ( v4->mBlendedParams.mUseDofParameters )
                    UFG::GameCameraComponent::UpdateDof(
                      (UFG::GameCameraComponent *)&v4->vfptr,
                      v3,
                      v4->mBlendedParams.mDofInFocusRange,
                      v4->mBlendedParams.mDofNearRange,
                      v4->mBlendedParams.mDofNearBlurRadius,
                      v4->mBlendedParams.mDofFarRange,
                      v4->mBlendedParams.mDofFarBlurRadius);
                  else
                    UFG::GameCameraComponent::UpdateDof(
                      (UFG::GameCameraComponent *)&v4->vfptr,
                      v3,
                      &v4->mCamera.mDepthOfFieldFocus,
                      0);
                  return;
                }
              }
              else
              {
                v192 = 0;
              }
              v193 = 0i64;
              goto LABEL_162;
            }
            v32 = v30 < 0.0;
          }
          if ( !v32 || v30 >= v4->mHorizCompOffset.p0 )
            goto LABEL_47;
          goto LABEL_46;
        }
      }
    }
  }
}s;
                      if ( v333 >= UFG::GameCameraComponent::mDofFocusObjectDistNear )
                      {
                        if ( v333 > UFG::GameCameraComponent::mDofFocusObjectDistFar )
                          UFG::GameCameraComponent::mDofFocusObjectDistFar = v333;
                      }
                      else
                      {
                        UFG:

// File Line: 2871
// RVA: 0x3C9160
void __fastcall UFG::FollowCameraComponent::Rotate(UFG::FollowCameraComponent *this, float delta_latitude, float delta_longitude)
{
  UFG::FollowCameraComponent *v3; // rbx
  float v4; // xmm12_4
  float v5; // xmm10_4
  float v6; // xmm11_4
  __m128 v7; // xmm6
  __m128 v8; // xmm7
  float v9; // xmm9_4
  float v10; // xmm0_4
  float v11; // xmm9_4
  float v12; // xmm13_4
  __m128 v13; // xmm0
  float v14; // xmm13_4
  float v15; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  signed __int64 v22; // rbx

  v7 = (__m128)LODWORD(this->mEye.p1.z);
  v8 = (__m128)LODWORD(this->mEye.p1.x);
  v3 = this;
  v4 = this->mLook.p1.z;
  v5 = this->mLook.p1.x;
  v6 = this->mLook.p1.y;
  v7.m128_f32[0] = v7.m128_f32[0] - v4;
  v8.m128_f32[0] = v8.m128_f32[0] - v5;
  v9 = this->mEye.p1.y - v6;
  if ( v7.m128_f32[0] < 0.0 )
    v7.m128_f32[0] = v7.m128_f32[0] / this->mOrbitSquish;
  v10 = atan2f(v9, v8.m128_f32[0]);
  v8.m128_f32[0] = v8.m128_f32[0] * v8.m128_f32[0];
  v11 = v9 * v9;
  v12 = v10;
  v13 = v8;
  v13.m128_f32[0] = v8.m128_f32[0] + v11;
  v14 = v12 + delta_longitude;
  v15 = atan2f(v7.m128_f32[0], COERCE_FLOAT(_mm_sqrt_ps(v13))) + delta_latitude;
  if ( v15 <= v3->mLatitudeMin )
    v15 = v3->mLatitudeMin;
  if ( v15 >= v3->mBlendedParams.mTweakLatitudeMax )
    v15 = v3->mBlendedParams.mTweakLatitudeMax;
  v7.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8.m128_f32[0] + v11);
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v7);
  v17 = cosf(v15);
  v18 = sinf(v15) * v16;
  v19 = v17 * v16;
  v20 = cosf(v14) * v19;
  v21 = sinf(v14) * v19;
  if ( v18 < 0.0 )
    v18 = v18 * v3->mOrbitSquish;
  v22 = (signed __int64)&v3->mEye;
  *(float *)(v22 + 84) = v5 + v20;
  *(float *)(v22 + 88) = v6 + v21;
  *(float *)(v22 + 92) = v4 + v18;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs((UFG::HomerCubic<UFG::qVector3> *)v22);
  *(_QWORD *)(v22 + 12) = 0i64;
  *(_DWORD *)(v22 + 20) = 0;
}

// File Line: 2896
// RVA: 0x3D81A0
void __fastcall UFG::FollowCameraComponent::UpdateAimOrigin(UFG::FollowCameraComponent *this)
{
  UFG::SimComponent *v1; // rbx
  UFG::FollowCameraComponent *v2; // rdi
  float v3; // xmm0_4
  float v4; // xmm1_4

  v1 = this->mTarget.m_pSimComponent;
  v2 = this;
  if ( v1 )
  {
    if ( BYTE5(v1[15].m_SafePointerList.mNode.mNext) )
      UFG::CharacterSubjectComponent::UpdateCambone((UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent);
    v3 = *((float *)&v1[14].m_BoundComponentHandles.mNode.mPrev + 1);
    v4 = *(float *)&v1[14].m_BoundComponentHandles.mNode.mNext;
    v2->mAimOrigin.x = *(float *)&v1[14].m_BoundComponentHandles.mNode.mPrev;
    v2->mAimOrigin.y = v3;
    v2->mAimOrigin.z = v4;
  }
}

// File Line: 2903
// RVA: 0x3DCE60
void __fastcall UFG::FollowCameraComponent::UpdateLocalWorld(UFG::FollowCameraComponent *this, float dt)
{
  UFG::FollowCameraComponent *v2; // rdi
  UFG::qVector4 v3; // xmm2
  UFG::CharacterSubjectComponent::SrcTransform v4; // er8
  UFG::SimComponent *v5; // rcx
  __int64 v6; // rax
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm8_4
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
  float v34; // xmm0_4
  float v35; // xmm1_4
  UFG::qMatrix44 m; // [rsp+20h] [rbp-89h]
  UFG::qVector4 pos; // [rsp+60h] [rbp-49h]
  UFG::qMatrix44 d; // [rsp+70h] [rbp-39h]

  v2 = this;
  if ( this->mTarget.m_pSimComponent )
  {
    UFG::CharacterSubjectComponent::GetTransformTypeOrientation(
      (UFG::CharacterSubjectComponent *)this->mTarget.m_pSimComponent,
      &this->mTargetWorld,
      this->mBlendedParams.mSrcOrientation);
    v4 = v2->mBlendedParams.mSrcPosition;
    if ( (unsigned int)(v4 - 8) > 2 )
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
        v4,
        1);
      v5 = v2->mTarget.m_pSimComponent;
      m = UFG::qMatrix44::msIdentity;
      v6 = ((__int64 (*)(void))v5->vfptr[18].__vecDelDtor)();
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
      v13 = m.v0.x;
      v14 = m.v1.x;
      v2->mCharacterSpacePos.w = 1.0;
      v15 = v2->mCharacterSpacePos.y;
      v16 = v2->mCharacterSpacePos.z;
      v17 = v2->mCharacterSpacePos.w;
      v18 = m.v0.y * v2->mCharacterSpacePos.x;
      v19 = m.v0.z * v2->mCharacterSpacePos.x;
      v20 = m.v0.w * v2->mCharacterSpacePos.x;
      v21 = (float)((float)((float)(v13 * v2->mCharacterSpacePos.x) + (float)(v14 * v15)) + (float)(m.v2.x * v16))
          + (float)(v17 * m.v3.x);
      v22 = m.v2.y * v16;
      v23 = m.v1.y * v15;
      v2->mTargetWorld.v3.x = v21;
      v24 = (float)(v18 + v23) + v22;
      v25 = m.v2.z * v16;
      v26 = v19 + (float)(m.v1.z * v15);
      v2->mTargetWorld.v3.y = v24 + (float)(v17 * m.v3.y);
      v27 = v17;
      v28 = v17 * m.v3.w;
      v29 = v26 + v25;
      v30 = m.v2.w * v16;
      v31 = v29 + (float)(v27 * m.v3.z);
      v32 = m.v1.w * v15;
      v2->mTargetWorld.v3.z = v31;
      v2->mTargetWorld.v3.w = (float)((float)(v20 + v32) + v30) + v28;
    }
    else
    {
      UFG::CharacterSubjectComponent::GetTransformTypePosition(
        (UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent,
        &v2->mTargetWorld.v3,
        v4,
        1);
    }
    v33 = (UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent;
    if ( v33->bElevationLock )
    {
      v34 = UFG::CharacterSubjectComponent::GetLockedElevation(v33, v2->mBlendedParams.mSrcPosition);
      v35 = v2->mTargetWorld.v3.z;
      if ( v35 >= v34 )
        v35 = v34;
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
void __fastcall UFG::FollowCameraComponent::GunRecoil(UFG::FollowCameraComponent *this, float scaleKickup, float scaleKickback, float scaleSpeed)
{
  UFG::FollowCameraComponent *v4; // rdi
  float v5; // xmm10_4
  float v6; // xmm12_4
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::TargetingSystemPedPlayerComponent *v9; // rax
  UFG::SimComponent *v10; // rdx
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
  float v22; // xmm1_4
  float v23; // xmm2_4
  signed __int64 v24; // rcx
  int v25; // xmm8_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm8_4
  float v29; // xmm1_4
  float v30; // xmm0_4

  v4 = this;
  v5 = scaleKickup;
  v6 = scaleKickback;
  if ( this->mTarget.m_pSimComponent
    && (v7 = (UFG::SimObjectCVBase *)this->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v7);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v7->vfptr,
                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v7->vfptr,
                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v7->vfptr,
                                                         UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v9 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v7);
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( v9 )
    v10 = v9->m_pEquippedSOWPC.m_pPointer;
  else
    v10 = 0i64;
  if ( UFG::tbRecoilUseTweakables || !v10 )
  {
    v11 = FLOAT_3_1415927;
    v12 = FLOAT_0_0055555557;
    v13 = (float)(UFG::trRecoilKickupMin * 3.1415927) * 0.0055555557;
    if ( UFG::tbRecoilUseTweakables )
      goto LABEL_22;
  }
  else
  {
    v11 = FLOAT_3_1415927;
    v12 = FLOAT_0_0055555557;
    v13 = (float)(*(float *)(*((_QWORD *)&v10[2].m_BoundComponentHandles.mNode.mPrev->mNext
                             + HIDWORD(v10[2].m_pSimObject))
                           + 416i64)
                * 3.1415927)
        * 0.0055555557;
  }
  if ( !v10 )
  {
LABEL_22:
    v14 = (float)(UFG::trRecoilKickupMax * v11) * v12;
    if ( UFG::tbRecoilUseTweakables )
      goto LABEL_25;
    goto LABEL_23;
  }
  v14 = (float)(*(float *)(*((_QWORD *)&v10[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v10[2].m_pSimObject))
                         + 420i64)
              * v11)
      * v12;
LABEL_23:
  if ( v10 )
  {
    v15 = (float)(*(float *)(*((_QWORD *)&v10[2].m_BoundComponentHandles.mNode.mPrev->mNext
                             + HIDWORD(v10[2].m_pSimObject))
                           + 424i64)
                * v11)
        * v12;
    goto LABEL_26;
  }
LABEL_25:
  v15 = (float)(UFG::trRecoilKickupOffset * v11) * v12;
  if ( UFG::tbRecoilUseTweakables )
  {
LABEL_28:
    v16 = UFG::trRecoilKickback;
    goto LABEL_29;
  }
LABEL_26:
  if ( !v10 )
    goto LABEL_28;
  v16 = *(float *)(*((_QWORD *)&v10[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v10[2].m_pSimObject))
                 + 436i64);
LABEL_29:
  if ( UFG::tbRecoilUseTweakables || !v10 )
    v17 = UFG::trRecoilKickbackSpeed;
  else
    v17 = *(float *)(*((_QWORD *)&v10[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v10[2].m_pSimObject))
                   + 440i64);
  if ( v14 >= v13 )
    v13 = UFG::qRandom(v14 - v13, &UFG::qDefaultSeed) + v13;
  v18 = v13 * v5;
  v19 = v15 * v5;
  v20 = (float)(v16 * 0.001) * v6;
  v21 = v17 * scaleSpeed;
  if ( (v4->mFreeAiming || v4->mSoftLocked) && (unsigned int)(v4->mContext - 5) <= 1 )
  {
    v20 = v20 * UFG::trRecoilZoomScale;
    v18 = v18 * UFG::trRecoilZoomScale;
    v19 = v19 * UFG::trRecoilZoomScale;
  }
  v22 = UFG::qVector3::msZero.y;
  v23 = UFG::qVector3::msZero.z;
  v24 = (signed __int64)&v4->mRecoilEye;
  *(float *)(v24 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v24 + 88) = v22;
  *(float *)(v24 + 92) = v23;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mRecoilEye);
  v25 = LODWORD(v20) ^ _xmm[0];
  *(_QWORD *)&v4->mRecoilEye.mParameter.x = 0i64;
  v4->mRecoilEye.mParameter.z = 0.0;
  v4->mRecoilAngle = v18;
  v4->mRecoilAngleDesired = v18 + v19;
  v26 = *(float *)&v25 * v4->mCamera.mTransformation.v2.x;
  v27 = *(float *)&v25 * v4->mCamera.mTransformation.v2.y;
  v28 = *(float *)&v25 * v4->mCamera.mTransformation.v2.z;
  v4->mRecoilEye.p0.x = v26;
  v4->mRecoilEye.p0.y = v27;
  v4->mRecoilEye.p0.z = v28;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mRecoilEye);
  *(_QWORD *)&v4->mRecoilEye.mParameter.x = 0i64;
  v4->mRecoilEye.mParameter.z = 0.0;
  v29 = COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * v4->mCamera.mTransformation.v2.x;
  v30 = COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * v4->mCamera.mTransformation.v2.y;
  v4->mRecoilEye.v0.z = COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * v4->mCamera.mTransformation.v2.z;
  v4->mRecoilEye.v0.x = v29;
  v4->mRecoilEye.v0.y = v30;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mRecoilEye);
  *(_QWORD *)&v4->mRecoilEye.mParameter.x = 0i64;
  v4->mRecoilEye.mParameter.z = 0.0;
}

// File Line: 3030
// RVA: 0x3C5F40
bool __fastcall UFG::FollowCameraComponent::IsMotionTowardsPlayer(UFG::FollowCameraComponent *this)
{
  return this->mType != 1 && COERCE_FLOAT(LODWORD(this->mBlendedParams.mTweakLookOffset.y) & _xmm) > 0.000099999997;
}

// File Line: 3040
// RVA: 0x3C38E0
float __fastcall UFG::FollowCameraComponent::GetMotionCorrection(UFG::FollowCameraComponent *this)
{
  UFG::FollowCameraComponent *v1; // rbx
  float result; // xmm0_4

  v1 = this;
  if ( !(_S11_3 & 1) )
  {
    _S11_3 |= 1u;
    UFG::qSymbol::create_from_string(&contextSymbol, "Cameras-FollowCameraSprintWGun");
    atexit(UFG::FollowCameraComponent::GetMotionCorrection_::_2_::_dynamic_atexit_destructor_for__contextSymbol__);
  }
  if ( v1->mType || UFG::FollowCameraComponent::mContextParameterSymbols[v1->mContext].mUID != contextSymbol.mUID )
    result = 0.0;
  else
    result = correction;
  return result;
}

// File Line: 3054
// RVA: 0x3C43D0
void __fastcall UFG::FollowCameraComponent::GotoAngle(UFG::FollowCameraComponent *this, float angle, float rate, float patience, bool worldSpace)
{
  this->mGotoAngle = angle;
  this->mGotoAngleRate = rate;
  this->mGotoAngleElaspedTime = 0.0;
  this->mGotoAngleLocalSpace = worldSpace == 0;
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
void __fastcall UFG::FollowCameraComponent::GotoAngleCollision(UFG::FollowCameraComponent *this, float wallDist, UFG::qVector3 *eye, UFG::qVector3 *look, UFG::qVector3 *up)
{
  bool v5; // dl
  UFG::FollowCameraComponent *v6; // rbx
  UFG::qVector3 *v7; // rdi
  UFG::qVector3 *v8; // rsi
  UFG::qVector3 *v9; // rcx
  UFG::qVector3 *v10; // rax
  float v11; // xmm11_4
  __m128 v12; // xmm12
  float v13; // xmm13_4
  __m128 v14; // xmm2
  float v15; // xmm9_4
  float v16; // xmm8_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm8_4
  float v21; // xmm6_4
  float v22; // xmm10_4
  float v23; // xmm2_4
  __m128 v24; // xmm7
  float v25; // xmm9_4
  float v26; // xmm15_4
  __m128 v27; // xmm4
  float v28; // xmm5_4
  float v29; // xmm6_4
  __m128 v30; // xmm2
  float v31; // xmm0_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  char v34; // al
  char v35; // r14
  char v36; // al
  float v37; // xmm7_4
  float v38; // xmm6_4
  UFG::qVector3 *v39; // rax
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm9_4
  float v46; // xmm11_4
  UFG::qVector3 rayEnd; // [rsp+20h] [rbp-E0h]
  UFG::qVector3 v48; // [rsp+30h] [rbp-D0h]
  float v49; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 rayStart; // [rsp+48h] [rbp-B8h]
  UFG::RayCastData data; // [rsp+60h] [rbp-A0h]
  UFG::RayCastData v52; // [rsp+140h] [rbp+40h]
  float v53; // [rsp+2F0h] [rbp+1F0h]

  v5 = this->mInCollision;
  v6 = this;
  v7 = look;
  v8 = eye;
  v9 = &UFG::qVector3::msZero;
  v10 = &v6->mCollisionSurfaceNormal;
  if ( !v5 )
    v10 = &UFG::qVector3::msZero;
  v11 = v10->x;
  v12 = (__m128)LODWORD(v10->y);
  v13 = v10->z;
  v14 = v12;
  v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v14)) >= 0.001 )
  {
    if ( v5 )
      v9 = &v6->mCollisionContactPosition;
    v15 = look->y;
    v16 = look->z;
    v17 = up->z;
    v18 = (float)((float)(COERCE_FLOAT(v12.m128_i32[0] ^ _xmm[0]) * (float)(v9->y - v15))
                + (float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * (float)(v9->x - look->x)))
        + (float)(COERCE_FLOAT(LODWORD(v13) ^ _xmm[0]) * (float)(v9->z - v16));
    v19 = COERCE_FLOAT(v12.m128_i32[0] ^ _xmm[0]) * v18;
    v20 = v16 + (float)(COERCE_FLOAT(LODWORD(v13) ^ _xmm[0]) * v18);
    v21 = up->y;
    v22 = look->x + (float)(COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) * v18);
    v23 = up->y;
    v24 = (__m128)LODWORD(up->x);
    v25 = v15 + v19;
    v49 = (float)(v13 * wallDist) + v20;
    rayStart.z = (float)(v13 * wallDist) + v20;
    v53 = (float)(v12.m128_f32[0] * wallDist) + v25;
    rayStart.y = (float)(v12.m128_f32[0] * wallDist) + v25;
    v26 = (float)(v11 * wallDist) + v22;
    rayStart.x = (float)(v11 * wallDist) + v22;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v23 * v12.m128_f32[0]) + (float)(v24.m128_f32[0] * v11)) + (float)(v17 * v13)) & _xmm) <= 0.99984771 )
    {
      v27 = v24;
      v28 = (float)(v17 * v12.m128_f32[0]) - (float)(v21 * v13);
      data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      data.mInput.m_filterInfo = 0;
      v27.m128_f32[0] = (float)(v24.m128_f32[0] * v13) - (float)(v17 * v11);
      v29 = (float)(v21 * v11) - (float)(v24.m128_f32[0] * v12.m128_f32[0]);
      v30 = v27;
      data.mInput.m_userData = 0i64;
      data.mOutput.m_hitFraction = 1.0;
      data.mOutput.m_extraInfo = -1;
      v30.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v28 * v28)) + (float)(v29 * v29);
      data.mOutput.m_shapeKeyIndex = 0;
      data.mOutput.m_shapeKeys[0] = -1;
      data.mOutput.m_rootCollidable = 0i64;
      LODWORD(v31) = (unsigned __int128)_mm_sqrt_ps(v30);
      data.mDebugName = "FollowCameraComponent";
      data.mCollisionModelName.mUID = -1;
      v32 = v28 * (float)(UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius / v31);
      v27.m128_f32[0] = v27.m128_f32[0] * (float)(UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius / v31);
      v33 = v29 * (float)(UFG::FollowCameraComponent::rGotoAngleCollisionMinRadius / v31);
      rayEnd.x = v32 + v26;
      rayEnd.y = v27.m128_f32[0] + v53;
      v48.x = v26 - v32;
      v48.z = v49 - v33;
      rayEnd.z = v33 + v49;
      v48.y = v53 - v27.m128_f32[0];
      UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x12u);
      v34 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
      v52.mInput.m_enableShapeCollectionFilter.m_bool = 0;
      v52.mInput.m_filterInfo = 0;
      v52.mInput.m_userData = 0i64;
      v52.mOutput.m_hitFraction = 1.0;
      v52.mOutput.m_extraInfo = -1;
      v35 = v34;
      v52.mOutput.m_shapeKeyIndex = 0;
      v52.mOutput.m_shapeKeys[0] = -1;
      v52.mOutput.m_rootCollidable = 0i64;
      v52.mDebugName = "FollowCameraComponent";
      v52.mCollisionModelName.mUID = -1;
      UFG::RayCastData::Init(&v52, &rayStart, &v48, 0x12u);
      v36 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v52);
      if ( v35 )
      {
        if ( v36 )
          return;
      }
      else if ( !v36 )
      {
        v43 = v7->y;
        v44 = v7->z;
        v45 = rayEnd.y - v43;
        v46 = v48.y - v43;
        v37 = UFG::FollowCameraComponent::rGotoAngleCollisionPatience;
        v38 = UFG::FollowCameraComponent::rGotoAngleCollisionRate;
        if ( (float)((float)((float)((float)(v8->y - v43) * (float)(rayEnd.y - v43))
                           + (float)((float)(v8->x - v7->x) * (float)(rayEnd.x - v7->x)))
                   + (float)((float)(v8->z - v44) * (float)(rayEnd.z - v44))) <= (float)((float)((float)((float)(v8->y - v43) * (float)(v48.y - v43))
                                                                                               + (float)((float)(v8->x - v7->x) * (float)(v48.x - v7->x)))
                                                                                       + (float)((float)(v8->z - v44)
                                                                                               * (float)(v48.z - v44))) )
        {
          v40 = v48.x - v7->x;
          v41 = v46;
        }
        else
        {
          v40 = rayEnd.x - v7->x;
          v41 = v45;
        }
LABEL_12:
        v42 = atan2f(v41, v40);
        v6->mGotoAngleRate = v38;
        v6->mGotoAnglePatience = v37;
        v6->mGotoAngleLocalSpace = 0;
        v6->mGotoAngleElaspedTime = 0.0;
        v6->mGotoAngle = v42;
        return;
      }
      v37 = UFG::FollowCameraComponent::rGotoAngleCollisionPatience;
      v38 = UFG::FollowCameraComponent::rGotoAngleCollisionRate;
      v39 = &v48;
      if ( !v35 )
        v39 = &rayEnd;
      v40 = v39->x - v7->x;
      v41 = v39->y - v7->y;
      goto LABEL_12;
    }
  }
}

// File Line: 3132
// RVA: 0x3C4D90
void __fastcall UFG::FollowCameraComponent::GotoRise(UFG::FollowCameraComponent *this, float rise, float rate, float patience)
{
  this->mGotoRise = rise;
  this->mGotoRiseRate = rate;
  this->mGotoRisePatience = patience;
  this->mGotoRiseElaspedTime = 0.0;
}

// File Line: 3141
// RVA: 0x3C4D60
void __fastcall UFG::FollowCameraComponent::GotoRadius(UFG::FollowCameraComponent *this, float radius, float rate, float patience)
{
  this->mGotoRadius = radius;
  this->mGotoRadiusRate = rate;
  this->mGotoRadiusPatience = patience;
  this->mGotoRadiusElaspedTime = 0.0;
}

// File Line: 3150
// RVA: 0x3C4B80
void __fastcall UFG::FollowCameraComponent::GotoAngleSnap(UFG::FollowCameraComponent *this, float radians, bool worldSpace)
{
  UFG::AimingPlayerComponent *v3; // rdi
  UFG::FollowCameraComponent *v4; // rsi
  UFG::SimComponent *v5; // rcx
  bool v6; // bl
  UFG::SimObjectCharacter *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::AimingPlayerComponent *v9; // rax
  float v10; // xmm7_4
  UFG::SimComponent *v11; // rbx
  __int128 v12; // xmm6
  __int128 v13; // xmm0
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v14; // rax
  UFG::qVector3 vDirection; // [rsp+20h] [rbp-48h]

  v3 = 0i64;
  v4 = this;
  this->mGotoAngleRate = 10000.0;
  this->mGotoAnglePatience = 0.1;
  this->mGotoAngleElaspedTime = 0.0;
  this->mGotoAngle = radians;
  this->mMouseBoomSet = 0;
  this->mGotoAngleLocalSpace = worldSpace == 0;
  v5 = this->mTarget.m_pSimComponent;
  v6 = worldSpace;
  if ( v5 )
  {
    v7 = (UFG::SimObjectCharacter *)v5->m_pSimObject;
    if ( v7 )
    {
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v7);
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v7->vfptr,
                                               UFG::AimingPlayerComponent::_TypeUID);
        }
        else if ( (v8 >> 12) & 1 )
        {
          v9 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v7->vfptr,
                                               UFG::AimingPlayerComponent::_TypeUID);
        }
        else
        {
          v9 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v7->vfptr,
                                               UFG::AimingPlayerComponent::_TypeUID);
        }
      }
      else
      {
        v9 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v7->vfptr,
                                             UFG::AimingPlayerComponent::_TypeUID);
      }
      v3 = v9;
    }
  }
  if ( v3 )
  {
    if ( v6 )
    {
      v10 = radians + 3.1415927;
    }
    else
    {
      v11 = v4->mTarget.m_pSimComponent;
      v12 = *(unsigned int *)((__int64 (__fastcall *)(UFG::SimComponent *))v11->vfptr[16].__vecDelDtor)(v11);
      v13 = *(unsigned int *)(((__int64 (__fastcall *)(UFG::SimComponent *))v11->vfptr[16].__vecDelDtor)(v11) + 4);
      v10 = atan2f(*(float *)&v13, *(float *)&v12) + radians;
    }
    for ( ; v10 > 3.1415927; v10 = v10 + -6.2831855 )
      ;
    for ( ; v10 < -3.1415927; v10 = v10 + 6.2831855 )
      ;
    vDirection.x = cosf(v10);
    vDirection.z = 0.0;
    vDirection.y = sinf(v10);
    UFG::AimingPlayerComponent::SetFreeAimIntention(v3, &vDirection);
    ((void (__fastcall *)(UFG::UpdateInterfaceVtbl **))v3->vfptr->Update)(&v3->vfptr);
  }
  v14 = v4->vfptr;
  v4->mSnapNext = 1;
  ((void (__fastcall *)(UFG::FollowCameraComponent *))v14[15].__vecDelDtor)(v4);
}

// File Line: 3174
// RVA: 0x3C4DC0
void __fastcall UFG::FollowCameraComponent::GotoRiseSnap(UFG::FollowCameraComponent *this, float rise)
{
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v2; // rax

  v2 = this->vfptr;
  this->mGotoRise = rise;
  this->mMouseBoomSet = 0;
  this->mGotoRiseRate = 10000.0;
  this->mGotoRisePatience = 0.1;
  this->mGotoRiseElaspedTime = 0.0;
  this->mSnapNext = 1;
  ((void (*)(void))v2[15].__vecDelDtor)();
}

// File Line: 3186
// RVA: 0x3D90A0
void __fastcall UFG::FollowCameraComponent::UpdateControllers(UFG::FollowCameraComponent *this, float dt)
{
  UFG::FollowCameraComponent *v2; // rdi
  Render::DebugDrawContext *v3; // rsi
  float v4; // xmm8_4
  float v5; // xmm6_4
  float v6; // xmm10_4
  float v7; // xmm13_4
  float v8; // xmm14_4
  __m128 v9; // xmm15
  float v10; // xmm3_4
  float v11; // xmm7_4
  float v12; // xmm11_4
  float v13; // xmm12_4
  float v14; // xmm4_4
  float v15; // xmm3_4
  __m128 v16; // xmm10
  float v17; // xmm3_4
  __m128 v18; // xmm2
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  float v22; // xmm1_4
  __m128 v23; // xmm1
  float v24; // xmm3_4
  __m128 v25; // xmm1
  UFG::qVector3 *v26; // rax
  float v27; // xmm7_4
  signed __int64 v28; // rbx
  UFG::SimComponent *v29; // r12
  signed __int64 v30; // r15
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  UFG::RebindingComponentHandle<UFG::CameraSubject,0> *v35; // rsi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v36; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rax
  UFG::SimObjectCharacter *v40; // rcx
  unsigned __int16 v41; // dx
  UFG::AimingPlayerComponent *v42; // r13
  UFG::SimObjectCVBase *v43; // rcx
  unsigned __int16 v44; // dx
  UFG::TargetingSystemPedPlayerComponent *v45; // r14
  bool v46; // al
  bool v47; // al
  bool v48; // al
  UFG::SimObjectGame *v49; // rax
  unsigned __int16 v50; // dx
  UFG::SimComponent *v51; // rax
  bool v52; // zf
  UFG::SimObject *v53; // rax
  signed __int64 v54; // rcx
  float v55; // xmm15_4
  int v56; // xmm10_4
  UFG::SimComponent *v57; // rax
  char v58; // al
  __int64 v59; // rbx
  UFG::InputActionData *v60; // rax
  bool v61; // al
  float v62; // xmm7_4
  signed __int64 v63; // rax
  float v64; // xmm1_4
  float v65; // xmm2_4
  UFG::InputActionData *v66; // rax
  float v67; // xmm12_4
  UFG::InputActionData *v68; // rax
  float v69; // xmm6_4
  char v70; // al
  UFG::allocator::free_link *v71; // rax
  UFG::Event *v72; // rdx
  unsigned int v73; // ecx
  UFG::allocator::free_link *v74; // rax
  UFG::SimObjectGame *v75; // rbx
  UFG::TargetingMap *v76; // rcx
  UFG::TargetingSimObject *v77; // rdx
  signed __int64 v78; // rax
  bool v79; // r8
  char v80; // cl
  UFG::CameraSubject *v81; // rax
  unsigned __int16 v82; // cx
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
  float *v95; // rax
  float v96; // xmm7_4
  float v97; // xmm10_4
  float v98; // xmm11_4
  __m128 v99; // xmm2
  double v100; // xmm0_8
  float v101; // xmm6_4
  __int64 v102; // rax
  bool v103; // r8
  __int64 v104; // rax
  bool v105; // al
  __int64 v106; // rcx
  const char *format; // rax
  UFG::qSymbol *v108; // rax
  float v109; // xmm3_4
  float v110; // xmm1_4
  float v111; // xmm10_4
  float v112; // xmm11_4
  float v113; // xmm12_4
  float *v114; // rbx
  float v115; // xmm0_4
  float v116; // xmm1_4
  float v117; // xmm2_4
  __m128 v118; // xmm5
  float v119; // xmm4_4
  float v120; // xmm2_4
  float v121; // xmm4_4
  float v122; // xmm6_4
  float v123; // xmm1_4
  float v124; // xmm4_4
  float v125; // xmm5_4
  float v126; // xmm1_4
  float v127; // xmm7_4
  float v128; // xmm6_4
  float v129; // xmm10_4
  float *v130; // rsi
  float *v131; // r14
  float v132; // xmm1_4
  float v133; // xmm2_4
  float v134; // xmm1_4
  float v135; // xmm2_4
  float v136; // xmm1_4
  float v137; // xmm2_4
  float v138; // xmm1_4
  float v139; // xmm2_4
  UFG::qSymbol *v140; // rax
  char v141; // cl
  bool v142; // al
  int v143; // edx
  float v144; // xmm6_4
  float v145; // xmm1_4
  float v146; // xmm2_4
  float v147; // xmm0_4
  float v148; // xmm1_4
  float v149; // xmm0_4
  float v150; // xmm1_4
  float v151; // xmm3_4
  float v152; // xmm1_4
  float v153; // xmm0_4
  float v154; // xmm13_4
  char v155; // r12
  bool v156; // r14
  __int64 v157; // r13
  UFG::Controller *v158; // rax
  UFG::Controller *v159; // rsi
  char v160; // bl
  UFG::UIScreen *v161; // rsi
  UFG::InputActionData *v162; // rax
  float v163; // xmm11_4
  UFG::GameStatTracker *v164; // rax
  float v165; // xmm0_4
  float v166; // xmm11_4
  UFG::InputActionData *v167; // rax
  float v168; // xmm12_4
  UFG::GameStatTracker *v169; // rax
  float v170; // xmm0_4
  float v171; // xmm12_4
  float *v172; // rsi
  float *v173; // rbx
  float v174; // xmm0_4
  float v175; // xmm7_4
  float v176; // xmm7_4
  float v177; // xmm10_4
  float v178; // xmm10_4
  UFG::GameStatTracker *v179; // rax
  float v180; // xmm6_4
  UFG::GameStatTracker *v181; // rax
  float v182; // xmm0_4
  float v183; // xmm7_4
  float v184; // xmm10_4
  Render::DebugDrawContext *v185; // r13
  UFG::InputActionData *v186; // rax
  UFG::GameStatTracker *v187; // rax
  float v188; // xmm7_4
  UFG::InputActionData *v189; // rax
  float v190; // xmm0_4
  float v191; // xmm7_4
  UFG::GameStatTracker *v192; // rax
  float v193; // xmm0_4
  UFG::InputActionData *v194; // rax
  float v195; // xmm6_4
  float v196; // xmm6_4
  float v197; // xmm11_4
  float v198; // xmm10_4
  float v199; // xmm11_4
  float v200; // xmm7_4
  UFG::GameStatTracker *v201; // rax
  float v202; // xmm6_4
  UFG::GameStatTracker *v203; // rax
  float v204; // xmm0_4
  float v205; // xmm13_4
  float v206; // xmm12_4
  float v207; // xmm11_4
  float v208; // xmm10_4
  float v209; // xmm7_4
  float v210; // xmm6_4
  UFG::GameStatTracker *v211; // rax
  bool v212; // al
  float v213; // xmm3_4
  float v214; // xmm4_4
  float v215; // xmm5_4
  __m128 v216; // xmm2
  float v217; // xmm0_4
  float v218; // xmm1_4
  float v219; // xmm6_4
  float v220; // xmm6_4
  float v221; // xmm0_4
  float v222; // xmm0_4
  float v223; // xmm1_4
  float *v224; // r14
  float v225; // xmm1_4
  float v226; // xmm2_4
  signed __int64 v227; // r15
  float v228; // xmm1_4
  float v229; // xmm2_4
  float v230; // xmm7_4
  float v231; // xmm0_4
  float v232; // xmm0_4
  float v233; // xmm6_4
  __int64 v234; // rax
  bool v235; // si
  bool v236; // al
  float v237; // xmm1_4
  float v238; // xmm0_4
  float v239; // xmm1_4
  float v240; // xmm0_4
  float v241; // xmm5_4
  float v242; // xmm4_4
  float v243; // xmm3_4
  float v244; // xmm2_4
  float v245; // xmm6_4
  float v246; // xmm10_4
  float v247; // xmm10_4
  float v248; // xmm5_4
  float v249; // xmm5_4
  float v250; // xmm4_4
  float v251; // xmm4_4
  float v252; // xmm1_4
  float v253; // xmm1_4
  float v254; // xmm0_4
  float v255; // xmm6_4
  float v256; // xmm2_4
  float v257; // xmm3_4
  float v258; // xmm7_4
  float v259; // xmm0_4
  float v260; // xmm11_4
  float v261; // xmm11_4
  bool v262; // bl
  bool v263; // cl
  UFG::InputActionData *v264; // rdx
  float v265; // xmm2_4
  float *v266; // rax
  float v267; // xmm2_4
  __m128 v268; // xmm3
  float v269; // xmm1_4
  float v270; // xmm6_4
  float v271; // xmm6_4
  float v272; // xmm10_4
  float v273; // xmm7_4
  float v274; // xmm0_4
  float v275; // xmm0_4
  UFG::qVector3 centre; // [rsp+40h] [rbp-80h]
  char v277; // [rsp+50h] [rbp-70h]
  UFG::qVector3 v278; // [rsp+58h] [rbp-68h]
  UFG::qVector3 position; // [rsp+68h] [rbp-58h]
  int v280; // [rsp+78h] [rbp-48h]
  float v281; // [rsp+7Ch] [rbp-44h]
  float constrainYaw[2]; // [rsp+140h] [rbp+80h]
  float dta; // [rsp+148h] [rbp+88h]
  UFG::qSymbol result; // [rsp+150h] [rbp+90h]
  char v285; // [rsp+158h] [rbp+98h]

  *(_QWORD *)&centre.x = -2i64;
  v2 = this;
  if ( !this->mControllersEnabled || !this->mTarget.m_pSimComponent )
    return;
  v3 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  *(_QWORD *)&position.x = v3;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  LODWORD(v7) = LODWORD(v2->mBlendedParams.mTweakCamThru.y) & _xmm;
  v8 = v2->mLook.p1.x;
  v9 = (__m128)LODWORD(v2->mLook.p1.y);
  constrainYaw[0] = v2->mLook.p1.z;
  v10 = constrainYaw[0];
  v11 = (float)((float)((float)(v2->mTargetWorld.v1.x + v2->mTargetWorld.v0.x) * 0.0)
              + (float)(v2->mBlendedParams.mTweakCamThru.z * v2->mTargetWorld.v2.x))
      + v2->mTargetWorld.v3.x;
  v12 = (float)((float)((float)(v2->mTargetWorld.v1.y + v2->mTargetWorld.v0.y) * 0.0)
              + (float)(v2->mBlendedParams.mTweakCamThru.z * v2->mTargetWorld.v2.y))
      + v2->mTargetWorld.v3.y;
  v13 = (float)((float)((float)(v2->mTargetWorld.v1.z + v2->mTargetWorld.v0.z) * 0.0)
              + (float)(v2->mBlendedParams.mTweakCamThru.z * v2->mTargetWorld.v2.z))
      + v2->mTargetWorld.v3.z;
  if ( (float)((float)((float)((float)(v9.m128_f32[0] - v12) * (float)(v9.m128_f32[0] - v12))
                     + (float)((float)(v8 - v11) * (float)(v8 - v11)))
             + (float)((float)(constrainYaw[0] - v13) * (float)(constrainYaw[0] - v13))) <= (float)(v7 * v7) )
  {
    v27 = 0.0;
  }
  else
  {
    v16 = (__m128)LODWORD(v2->mControllerForward.x);
    v14 = (float)(v2->mControllerForward.y * 0.0) - (float)(v2->mControllerForward.x * 0.0);
    v15 = v2->mControllerForward.z * 0.0;
    v16.m128_f32[0] = v16.m128_f32[0] - v15;
    v17 = v15 - v2->mControllerForward.y;
    v18 = v16;
    v18.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v17 * v17)) + (float)(v14 * v14);
    if ( v18.m128_f32[0] == 0.0 )
      v19 = 0.0;
    else
      v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
    v20 = (float)(v19 * v14) * v7;
    v21 = (float)(v19 * v16.m128_f32[0]) * v7;
    v22 = (float)(v19 * v17) * v7;
    centre.x = v11 - v22;
    centre.y = v12 - v21;
    centre.z = v13 - v20;
    v278.x = v11 + v22;
    v278.y = v21 + v12;
    v278.z = v20 + v13;
    v23 = v9;
    v23.m128_f32[0] = (float)((float)((float)(v9.m128_f32[0] - centre.y) * (float)(v9.m128_f32[0] - centre.y))
                            + (float)((float)(v8 - centre.x) * (float)(v8 - centre.x)))
                    + (float)((float)(constrainYaw[0] - centre.z) * (float)(constrainYaw[0] - centre.z));
    LODWORD(v24) = (unsigned __int128)_mm_sqrt_ps(v23);
    v25 = v9;
    v25.m128_f32[0] = (float)((float)((float)(v9.m128_f32[0] - v278.y) * (float)(v9.m128_f32[0] - v278.y))
                            + (float)((float)(v8 - v278.x) * (float)(v8 - v278.x)))
                    + (float)((float)(constrainYaw[0] - v278.z) * (float)(constrainYaw[0] - v278.z));
    v26 = &v278;
    if ( v24 <= COERCE_FLOAT(_mm_sqrt_ps(v25)) )
      v26 = &centre;
    v27 = v26->z - constrainYaw[0];
    v6 = v26->y - v9.m128_f32[0];
    v5 = v26->x - v8;
    v8 = v26->x;
    v9.m128_i32[0] = LODWORD(v26->y);
    v10 = v26->z;
  }
  v28 = (signed __int64)&v2->mLook;
  *(float *)(v28 + 84) = v8;
  *(_DWORD *)(v28 + 88) = v9.m128_i32[0];
  *(float *)(v28 + 92) = v10;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mLook);
  v29 = 0i64;
  *(_QWORD *)&v2->mLook.mParameter.x = 0i64;
  v2->mLook.mParameter.z = 0.0;
  v30 = (signed __int64)&v2->mEye;
  v31 = UFG::qVector3::msZero.y;
  v32 = UFG::qVector3::msZero.z;
  v33 = UFG::qVector3::msZero.x;
  *(float *)(v30 + 108) = UFG::qVector3::msZero.x;
  *(float *)(v30 + 112) = v31;
  *(float *)(v30 + 116) = v32;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
  *(_QWORD *)&v2->mEye.mParameter.x = 0i64;
  v2->mEye.mParameter.z = 0.0;
  if ( v2->mBlend > 0.0 )
  {
    v33 = v2->mEye.p1.z + v27;
    v34 = v2->mEye.p1.y + v6;
    v2->mEye.p1.x = v2->mEye.p1.x + v5;
    v2->mEye.p1.y = v34;
    v2->mEye.p1.z = v33;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
    *(_QWORD *)&v2->mEye.mParameter.x = 0i64;
    v2->mEye.mParameter.z = 0.0;
  }
  if ( UFG::bCameraDebugText )
  {
    if ( UFG::CharacterSubjectComponent::IsAirborne((UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent) )
      Render::DebugDrawContext::DrawTextA(v3, 40, 252, &UFG::qColour::White, "Airborne");
    if ( UFG::CharacterSubjectComponent::IsOnGround((UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent) )
      Render::DebugDrawContext::DrawTextA(v3, 40, 252, &UFG::qColour::White, "On Ground");
    if ( BYTE1(v2->mTarget.m_pSimComponent[10].m_TypeUID) )
      Render::DebugDrawContext::DrawTextA(v3, 40, 276, &UFG::qColour::White, "Falling Attack");
    if ( LOBYTE(v2->mTarget.m_pSimComponent[9].m_BoundComponentHandles.mNode.mPrev) )
      Render::DebugDrawContext::DrawTextA(v3, 40, 264, &UFG::qColour::White, "Elevation Locked");
  }
  v35 = &v2->mEnemyTarget;
  if ( v2->mEnemyTarget.m_pSimComponent )
  {
    v36 = v35->mPrev;
    v37 = v2->mEnemyTarget.mNext;
    v36->mNext = v37;
    v37->mPrev = v36;
    v2->mEnemyTarget.m_pSimComponent = 0i64;
LABEL_28:
    v2->mEnemyTarget.m_pSimObject = 0i64;
    v2->mEnemyTarget.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mEnemyTarget.mPrev;
    v35->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v35->mPrev;
    goto LABEL_29;
  }
  if ( v2->mEnemyTarget.m_pSimObject )
  {
    v38 = v35->mPrev;
    if ( (UFG::RebindingComponentHandle<UFG::CameraSubject,0> *)v35->mPrev != v35
      || (UFG::RebindingComponentHandle<UFG::CameraSubject,0> *)v2->mEnemyTarget.mNext != &v2->mEnemyTarget )
    {
      v39 = v2->mEnemyTarget.mNext;
      v38->mNext = v39;
      v39->mPrev = v38;
      goto LABEL_28;
    }
  }
LABEL_29:
  v2->mEnemyTarget.m_Changed = 1;
  v2->mEnemyTarget.m_TypeUID = UFG::CameraSubject::_TypeUID;
  v277 = 1;
  v280 = UFG::gActiveControllerNum;
  if ( v2->mTarget.m_pSimComponent
    && (v40 = (UFG::SimObjectCharacter *)v2->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
  {
    v41 = v40->m_Flags;
    if ( (v41 >> 14) & 1 )
    {
      v42 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v40);
    }
    else if ( (v41 & 0x8000u) == 0 )
    {
      if ( (v41 >> 13) & 1 )
      {
        v42 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v40->vfptr,
                                              UFG::AimingPlayerComponent::_TypeUID);
      }
      else if ( (v41 >> 12) & 1 )
      {
        v42 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v40->vfptr,
                                              UFG::AimingPlayerComponent::_TypeUID);
      }
      else
      {
        v42 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v40->vfptr,
                                              UFG::AimingPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v42 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v40->vfptr,
                                            UFG::AimingPlayerComponent::_TypeUID);
    }
  }
  else
  {
    v42 = 0i64;
  }
  if ( v2->mTarget.m_pSimComponent && (v43 = (UFG::SimObjectCVBase *)v2->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
  {
    v44 = v43->m_Flags;
    if ( (v44 >> 14) & 1 )
    {
      v45 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v43);
    }
    else if ( (v44 & 0x8000u) == 0 )
    {
      if ( (v44 >> 13) & 1 )
      {
        v45 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v43->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else if ( (v44 >> 12) & 1 )
      {
        v45 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v43->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else
      {
        v45 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v43->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v45 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v43);
    }
  }
  else
  {
    v45 = 0i64;
  }
  if ( v45 )
    v46 = (unsigned int)(v45->m_eFocusMode - 3) <= 1;
  else
    v46 = 0;
  v2->mFreeAiming = v46;
  if ( v45 )
    v47 = v45->m_eFocusMode == 2;
  else
    v47 = 0;
  v2->mSoftLocked = v47;
  if ( v45 )
    v48 = (unsigned int)(v45->m_eFocusMode - 1) <= 1;
  else
    v48 = 0;
  v2->mFocusLocked = v48;
  v49 = (UFG::SimObjectGame *)((__int64 (__fastcall *)(UFG::FollowCameraComponent *))v2->vfptr[17].__vecDelDtor)(v2);
  if ( v49 )
  {
    v50 = v49->m_Flags;
    if ( (v50 >> 14) & 1 )
    {
      v51 = v49->m_Components.p[7].m_pComponent;
    }
    else if ( (v50 & 0x8000u) == 0 )
    {
      if ( (v50 >> 13) & 1 )
      {
        v51 = v49->m_Components.p[6].m_pComponent;
      }
      else if ( (v50 >> 12) & 1 )
      {
        v51 = UFG::SimObjectGame::GetComponentOfTypeHK(v49, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v51 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v49->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v51 = v49->m_Components.p[7].m_pComponent;
    }
    *(_QWORD *)&v278.x = v51;
  }
  else
  {
    *(_QWORD *)&v278.x = 0i64;
  }
  if ( !v45
    || (v29 = v45->m_pEquippedSOWPC.m_pPointer) == 0i64
    || (v52 = *(_DWORD *)(*((_QWORD *)&v29[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v29[2].m_pSimObject))
                        + 100i64) == UFG::gNullQSymbolUC.mUID,
        LOBYTE(result.mUID) = 1,
        v52) )
  {
    LOBYTE(result.mUID) = 0;
  }
  v281 = 0.0;
  if ( ((unsigned __int8 (*)(void))v2->mTarget.m_pSimComponent->vfptr[48].__vecDelDtor)() )
  {
    v53 = 0i64;
    if ( v45 )
    {
      v54 = (signed __int64)&v45->m_pTargets[(unsigned __int8)v45->m_pTargetingMap->m_Map.p[44]];
      v53 = *(UFG::SimObject **)(v54 + 40);
      if ( v53 && *(_BYTE *)(v54 + 49) )
        v2->mPassThroughTimer2 = 1.0;
      else
        v53 = 0i64;
    }
    v2->pSimObjectPassThru2 = v53;
  }
  if ( !UFG::CharacterSubjectComponent::IsAirborne((UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent)
    || (v52 = LOBYTE(v2->mTarget.m_pSimComponent[9].m_BoundComponentHandles.mNode.mPrev) == 0,
        LOBYTE(constrainYaw[0]) = 0,
        !v52) )
  {
    LOBYTE(constrainYaw[0]) = 1;
  }
  v55 = FLOAT_N1_0;
  v56 = _xmm[0];
  if ( !v2->mFocusLocked && !v2->mFreeAiming
    || (v57 = v2->mTarget.m_pSimComponent, *(_DWORD *)(&v57[12].m_SimObjIndex + 1) != -1)
    && *(_DWORD *)(&v57[12].m_SimObjIndex + 1) != 1 )
  {
    v58 = 0;
    goto LABEL_95;
  }
  v58 = 1;
  if ( v2->mFreeAiming )
  {
LABEL_95:
    v285 = 1;
    if ( !v58 )
    {
      v67 = dta;
      goto LABEL_228;
    }
    goto LABEL_96;
  }
  v285 = 0;
LABEL_96:
  if ( (unsigned int)(v2->mContext - 5) > 1 )
  {
    v67 = dta;
  }
  else
  {
    v59 = v280;
    v60 = UFG::ActionDef_CamHoldBreath.mDataPerController[v280];
    v61 = v60 && v60->mActionTrue;
    UFG::GameCameraComponent::SetHoldingBreathInput((UFG::GameCameraComponent *)&v2->vfptr, v61);
    v62 = 0.0;
    v63 = v2->mContext;
    v64 = v2->mContextParameters[v63].mTweakRadiusMin;
    v65 = v2->mContextParameters[v63].mTweakRadiusMax;
    v33 = v2->mContextParameters[v63].mTweakOrbitSpeed;
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      v33 = v33 * UFG::FollowCameraComponent::rAimZoomWheelMultiplier;
    v66 = UFG::ActionDef_CamZoomIn.mDataPerController[v59];
    if ( v66 && v66->mActionTrue )
    {
      v67 = dta;
      LODWORD(v62) = COERCE_UNSIGNED_INT(v33 * dta) ^ _xmm[0];
    }
    else
    {
      v68 = UFG::ActionDef_CamZoomOut.mDataPerController[v59];
      v67 = dta;
      if ( v68 && v68->mActionTrue )
        v62 = v33 * dta;
    }
    v69 = (float)((float)(1.0 - v2->mTransitionParamEye) * v62) + v2->mFov.p1;
    v70 = 0;
    if ( v69 <= v64 || v69 >= v65 )
      v70 = 1;
    if ( v69 <= v64 )
      v69 = v64;
    if ( v69 >= v65 )
      v69 = v65;
    if ( v62 != 0.0 && !v70 )
    {
      v71 = UFG::qMalloc(0x38ui64, "ZoomCamEvent", 0i64);
      v72 = (UFG::Event *)v71;
      *(_QWORD *)&centre.x = v71;
      if ( v71 )
      {
        v73 = UFG::gEventCameraZooming.mUID;
        v74 = v71 + 1;
        v74->mNext = v74;
        v74[1].mNext = v74;
        v72->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
        v72->m_EventUID = v73;
        v72->m_NamePTR = 0i64;
      }
      else
      {
        v72 = 0i64;
      }
      v72->mUserData0 = v62 >= 0.0;
      v72->mUserData1 = v2->mContext != 6;
      UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v72);
    }
    v2->mFov.p1 = v69;
    UFG::HomerCubic<float>::MakeCoeffs(&v2->mFov);
    v2->mFov.mParameter = 0.0;
  }
  v75 = 0i64;
  if ( v45 )
  {
    if ( ((v76 = v45->m_pTargetingMap,
           v77 = v45->m_pTargets,
           v78 = (unsigned __int8)v76->m_Map.p[50],
           (v75 = (UFG::SimObjectGame *)v77[v78].m_pTarget.m_pPointer) == 0i64)
       || !v77[v78].m_bLock)
      && (v75 = (UFG::SimObjectGame *)v77[(unsigned __int8)v76->m_Map.p[23]].m_pTarget.m_pPointer) == 0i64
      || UFG::IsHostage((UFG::SimObject *)&v75->vfptr) )
    {
      v75 = (UFG::SimObjectGame *)v45->m_pTargets[(unsigned __int8)v45->m_pTargetingMap->m_Map.p[22]].m_pTarget.m_pPointer;
    }
  }
  if ( !v42 )
    goto LABEL_503;
  v79 = v2->mFreeAiming;
  v80 = 0;
  if ( v79 )
    v80 = 1;
  if ( (unsigned int)(v2->mContext - 5) <= 1 && !v79 || v80 )
  {
    v87 = *(Render::DebugDrawContext **)&position.x;
  }
  else
  {
LABEL_503:
    if ( v75 )
    {
      v82 = v75->m_Flags;
      if ( (v82 >> 14) & 1 )
      {
        v81 = (UFG::CameraSubject *)v75->m_Components.p[37].m_pComponent;
      }
      else if ( (v82 & 0x8000u) == 0 )
      {
        if ( (v82 >> 13) & 1 )
        {
          v81 = (UFG::CameraSubject *)UFG::SimObjectGame::GetComponentOfTypeHK(v75, UFG::CameraSubject::_TypeUID);
        }
        else if ( (v82 >> 12) & 1 )
        {
          v81 = (UFG::CameraSubject *)UFG::SimObjectGame::GetComponentOfTypeHK(v75, UFG::CameraSubject::_TypeUID);
        }
        else
        {
          v81 = (UFG::CameraSubject *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v75->vfptr,
                                        UFG::CameraSubject::_TypeUID);
        }
      }
      else
      {
        v81 = (UFG::CameraSubject *)v75->m_Components.p[31].m_pComponent;
      }
    }
    else
    {
      v81 = 0i64;
    }
    UFG::RebindingComponentHandle<UFG::CameraSubject,0>::Set(&v2->mEnemyTarget, v81);
    if ( !v2->mEnemyTarget.m_pSimComponent )
      goto LABEL_227;
    ((void (*)(void))v2->mEnemyTarget.m_pSimComponent->vfptr[22].__vecDelDtor)();
    v83 = v33 * ratio_of_height;
    v84 = ((__int64 (*)(void))v2->mEnemyTarget.m_pSimComponent->vfptr[27].__vecDelDtor)();
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
    v79 = v2->mFreeAiming;
    if ( !v79 && !v2->mSoftLocked )
    {
      if ( v2->mEnemyTarget.m_pSimComponent )
      {
        v88 = v35->mPrev;
        v89 = v2->mEnemyTarget.mNext;
        v88->mNext = v89;
        v89->mPrev = v88;
        v2->mEnemyTarget.m_pSimComponent = 0i64;
      }
      else
      {
        if ( !v2->mEnemyTarget.m_pSimObject )
          goto LABEL_159;
        v90 = v35->mPrev;
        if ( (UFG::RebindingComponentHandle<UFG::CameraSubject,0> *)v35->mPrev == v35
          && (UFG::RebindingComponentHandle<UFG::CameraSubject,0> *)v2->mEnemyTarget.mNext == &v2->mEnemyTarget )
        {
          goto LABEL_159;
        }
        v91 = v2->mEnemyTarget.mNext;
        v90->mNext = v91;
        v91->mPrev = v90;
      }
      v2->mEnemyTarget.m_pSimObject = 0i64;
      v2->mEnemyTarget.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->mEnemyTarget.mPrev;
      v35->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v35->mPrev;
LABEL_159:
      v2->mEnemyTarget.m_Changed = 1;
      v2->mEnemyTarget.m_TypeUID = UFG::CameraSubject::_TypeUID;
LABEL_227:
      v28 = (signed __int64)&v2->mLook;
LABEL_228:
      v140 = UFG::CharacterSubjectComponent::GetContextOverride(
               (UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent,
               (UFG::qSymbol *)&centre,
               0);
      if ( UFG::PropertySetManager::FindPropertySet(v140) != 0i64 )
      {
        UFG::FollowCameraComponent::SetContext(v2, eFOLLOW_CONTEXT_OVERRIDE_TOW, 0);
      }
      else
      {
        v141 = v2->mTarget.m_pSimComponent[10].m_TypeUID;
        v142 = !LOBYTE(result.mUID)
            && v2->bAllowTargeted != LOBYTE(result.mUID)
            && v2->mAutoFrameActive != LOBYTE(result.mUID);
        v143 = 0;
        if ( v141 )
          v143 = 1;
        if ( LOBYTE(result.mUID) )
        {
          v143 = (v141 != 0) + 9;
        }
        else if ( v142 )
        {
          v143 = 8;
        }
        UFG::FollowCameraComponent::SetContext(v2, (UFG::FollowCameraContext)v143, 0);
      }
      v144 = v2->mVelocity.p0.z;
      if ( (LOBYTE(v2->mTarget.m_pSimComponent[10].m_TypeUID)
         || UFG::CharacterSubjectComponent::IsWalking((UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent)
         || UFG::CharacterSubjectComponent::IsJogging((UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent))
        && !LOBYTE(v2->mTarget.m_pSimComponent[9].m_BoundComponentHandles.mNode.mPrev) )
      {
        v145 = UFG::FollowCameraComponent::rEyeRiseFallVelocityMin;
        if ( v144 > UFG::FollowCameraComponent::rEyeRiseFallVelocityMin )
          v145 = v144;
        if ( v145 >= UFG::FollowCameraComponent::rEyeRiseFallVelocityMax )
          v145 = UFG::FollowCameraComponent::rEyeRiseFallVelocityMax;
        v146 = v2->mEye.p1.y;
        if ( v144 <= 0.0 )
          v147 = UFG::FollowCameraComponent::rEyeFallFromVelocityRatio;
        else
          v147 = UFG::FollowCameraComponent::rEyeRiseFromVelocityRatio;
        v148 = v2->mEye.p1.z + (float)((float)(v147 * v67) * v145);
        v2->mEye.p1.x = v2->mEye.p1.x;
        v2->mEye.p1.y = v146;
        v2->mEye.p1.z = v148;
        UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
        v2->mEye.mParameter.z = 0.0;
        *(_QWORD *)&v2->mEye.mParameter.x = 0i64;
      }
      v149 = 0.0;
      if ( BYTE1(v2->mTarget.m_pSimComponent[10].m_TypeUID) )
      {
        v149 = (float)((float)(v144 - -0.40000001) * 1.9999999) - 1.8;
        v150 = FLOAT_N1_8;
        if ( v149 > -1.8 )
        {
          if ( v149 >= -1.0 )
            v149 = FLOAT_N1_0;
          goto LABEL_263;
        }
      }
      else
      {
        if ( LOBYTE(constrainYaw[0]) )
        {
LABEL_263:
          v151 = v2->mLook.p1.y;
          v152 = v2->mLook.p1.z + v149;
          v153 = v2->mTargetWorld.v3.z;
          if ( v153 <= v152 )
            v153 = v152;
          *(float *)(v28 + 84) = v2->mLook.p1.x;
          *(float *)(v28 + 88) = v151;
          *(float *)(v28 + 92) = v153;
          UFG::HomerCubic<UFG::qVector3>::MakeCoeffs((UFG::HomerCubic<UFG::qVector3> *)v28);
          *(_QWORD *)(v28 + 12) = 0i64;
          *(_DWORD *)(v28 + 20) = 0;
          goto LABEL_266;
        }
        v149 = (float)((float)(v144 - -2.0) * 0.30000001) - 0.60000002;
        v150 = FLOAT_N0_60000002;
        if ( v149 > -0.60000002 )
        {
          if ( v149 >= 0.0 )
            v149 = 0.0;
          goto LABEL_263;
        }
      }
      v149 = v150;
      goto LABEL_263;
    }
  }
  v92 = *(_QWORD *)&v278.x;
  v94 = 0;
  if ( *(_QWORD *)&v278.x )
  {
    v93 = *(_QWORD *)(*(_QWORD *)&v278.x
                    + 8 * ((signed __int64)(signed int)gActionRequest_CameraZoom.m_EnumValue >> 6)
                    + 712);
    if ( _bittest64(&v93, gActionRequest_CameraZoom.m_EnumValue & 0x3F) )
      v94 = 1;
  }
  v2->mSniperEnabled = v94;
  if ( v79 || (v95 = &v42->m_vAimPosition.x, v2->mSoftLocked) )
    v95 = &v42->m_vAimIntentionTargetPosition.x;
  v96 = *v95;
  v97 = v95[1];
  v98 = v95[2];
  v99 = (__m128)LODWORD(v2->mTargetWorld.v3.y);
  *(float *)&v100 = (float)(v2->mTargetWorld.v3.x - v96) * (float)(v2->mTargetWorld.v3.x - v96);
  v99.m128_f32[0] = (float)((float)((float)((float)(v99.m128_f32[0] - v97) * (float)(v99.m128_f32[0] - v97))
                                  + *(float *)&v100)
                          + (float)((float)(v2->mTargetWorld.v3.z - v98) * (float)(v2->mTargetWorld.v3.z - v98)))
                  + (float)((float)(v2->mTargetWorld.v3.w - 1.0) * (float)(v2->mTargetWorld.v3.w - 1.0));
  LODWORD(v101) = (unsigned __int128)_mm_sqrt_ps(v99);
  v103 = 0;
  if ( v92 )
  {
    v102 = *(_QWORD *)(v92 + 8 * ((signed __int64)(signed int)gActionRequest_UseCover.m_EnumValue >> 6) + 712);
    if ( _bittest64(&v102, gActionRequest_UseCover.m_EnumValue & 0x3F) )
      v103 = 1;
  }
  v105 = 0;
  if ( v92 )
  {
    v104 = *(_QWORD *)(v92 + 8 * ((signed __int64)(signed int)gActionRequest_CoverPopout.m_EnumValue >> 6) + 712);
    if ( _bittest64(&v104, gActionRequest_CoverPopout.m_EnumValue & 0x3F) )
      v105 = 1;
  }
  if ( !v103 || v105 )
  {
    if ( v29 )
    {
      v106 = *((_QWORD *)&v29[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v29[2].m_pSimObject));
      LODWORD(v100) = *(_DWORD *)(v106 + 412);
      v281 = *(float *)(v106 + 412);
    }
    else
    {
      v281 = 0.0;
    }
  }
  if ( !v29 )
    goto LABEL_504;
  if ( *(_BYTE *)(*((_QWORD *)&v29[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v29[2].m_pSimObject)) + 119i64)
    && v94 )
  {
    UFG::FollowCameraComponent::SetContext(v2, eFOLLOW_CONTEXT_AIM_SNIPER, 0);
    if ( UFG::bCameraDebugText )
    {
      format = "Sniper target distance %f";
LABEL_198:
      v100 = v101;
      Render::DebugDrawContext::DrawTextA(v87, 40, 324, &UFG::qColour::White, format, v101);
      goto LABEL_199;
    }
    goto LABEL_199;
  }
  if ( !BYTE5(v29[3].m_SafePointerList.mNode.mPrev) || !v94 )
  {
LABEL_504:
    v108 = UFG::CharacterSubjectComponent::GetContextOverride(
             (UFG::CharacterSubjectComponent *)v2->mTarget.m_pSimComponent,
             &result,
             1);
    if ( UFG::PropertySetManager::FindPropertySet(v108) != 0i64 )
    {
      UFG::FollowCameraComponent::SetContext(v2, eFOLLOW_CONTEXT_OVERRIDE_AIM, 0);
      if ( UFG::bCameraDebugText )
      {
        format = "Aiming Override %f";
        goto LABEL_198;
      }
    }
    else if ( LOBYTE(constrainYaw[0]) )
    {
      UFG::FollowCameraComponent::SetContext(v2, eFOLLOW_CONTEXT_AIM, 0);
      if ( UFG::bCameraDebugText )
      {
        format = "Aiming %f";
        goto LABEL_198;
      }
    }
    else
    {
      UFG::FollowCameraComponent::SetContext(v2, eFOLLOW_CONTEXT_AIM_AIRBORNE, 0);
      if ( UFG::bCameraDebugText )
      {
        format = "Aiming Airborne %f";
        goto LABEL_198;
      }
    }
    goto LABEL_199;
  }
  UFG::FollowCameraComponent::SetContext(v2, eFOLLOW_CONTEXT_AIM_PHONE, 0);
  if ( UFG::bCameraDebugText )
  {
    format = "Phone Camera target distance %f";
    goto LABEL_198;
  }
LABEL_199:
  if ( v2->mType == 1 && v2->mPreviousType != 1 && v2->mBlend > 0.0 )
  {
    centre.x = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.y = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.z = UFG::FollowCameraComponent::rAimTransitionDurIn;
    UFG::HomerCubic<UFG::qVector3>::SetDuration(&v2->mAimEye, &centre);
    *(float *)&v100 = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.x = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.y = UFG::FollowCameraComponent::rAimTransitionDurIn;
    centre.z = UFG::FollowCameraComponent::rAimTransitionDurIn;
    UFG::HomerCubic<UFG::qVector3>::SetDuration(&v2->mAimLook, &centre);
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      centre.x = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.y = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.z = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      UFG::HomerCubic<UFG::qVector3>::SetDuration(&v2->mAimEye, &centre);
      *(float *)&v100 = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.x = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.y = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      centre.z = UFG::FollowCameraComponent::rAimTransitionDurInMouse;
      UFG::HomerCubic<UFG::qVector3>::SetDuration(&v2->mAimLook, &centre);
    }
  }
  if ( !UFG::bAimDeadZone )
    goto LABEL_212;
  v109 = v2->mAimDeadZoneRadius;
  if ( v109 < 0.0
    || (*(float *)&v100 = (float)(v96 - v2->mAimDeadZoneCentre.x) * (float)(v96 - v2->mAimDeadZoneCentre.x),
        (float)(v109 * v109) < (float)((float)((float)((float)(v97 - v2->mAimDeadZoneCentre.y)
                                                     * (float)(v97 - v2->mAimDeadZoneCentre.y))
                                             + *(float *)&v100)
                                     + (float)((float)(v98 - v2->mAimDeadZoneCentre.z)
                                             * (float)(v98 - v2->mAimDeadZoneCentre.z)))) )
  {
    v2->mAimDeadZoneCentre.x = v96;
    v2->mAimDeadZoneCentre.y = v97;
    v2->mAimDeadZoneCentre.z = v98;
    v2->mAimDeadZoneTimer = 0.0;
    v110 = FLOAT_0_0020000001;
  }
  else
  {
    *(float *)&v100 = v2->mAimDeadZoneTimer;
    if ( *(float *)&v100 < 0.5 )
    {
      v2->mAimDeadZoneTimer = *(float *)&v100 + v67;
      goto LABEL_212;
    }
    v110 = FLOAT_0_1;
  }
  UFG::FollowCameraComponent::SetAimDeadZone(v2, v110, *(float *)&v100);
LABEL_212:
  v111 = v42->m_vFreeAimOrigin.x;
  v112 = v42->m_vFreeAimOrigin.y;
  v113 = v42->m_vFreeAimOrigin.z;
  v114 = &v2->mAimEye.mDuration.x;
  v114[21] = v111;
  v114[22] = v112;
  v114[23] = v113;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimEye);
  *(_QWORD *)&v2->mAimEye.mParameter.x = 0i64;
  v2->mAimEye.mParameter.z = 0.0;
  v2->mEye.p1.x = v111;
  v2->mEye.p1.y = v112;
  v2->mEye.p1.z = v113;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
  *(_QWORD *)&v2->mEye.mParameter.x = 0i64;
  v2->mEye.mParameter.z = 0.0;
  if ( v2->mFreeAiming || v2->mSoftLocked )
  {
    v117 = v42->m_vFreeAimIntention.z + v42->m_vFreeAimOrigin.z;
    v116 = v42->m_vFreeAimIntention.y + v42->m_vFreeAimOrigin.y;
    v115 = v42->m_vFreeAimOrigin.x + v42->m_vFreeAimIntention.x;
  }
  else
  {
    v115 = v42->m_vAimPosition.x;
    v116 = v42->m_vAimPosition.y;
    v117 = v42->m_vAimPosition.z;
  }
  centre.z = v117;
  centre.y = v116;
  centre.x = v115;
  v118 = (__m128)LODWORD(v116);
  v119 = v117;
  v120 = v2->mBlendedParams.mTweakRadiusMax;
  if ( v120 >= 1.0 )
  {
    if ( v120 >= 10.0 )
      v120 = FLOAT_10_0;
  }
  else
  {
    v120 = *(float *)&FLOAT_1_0;
  }
  v121 = v119 - v113;
  v118.m128_f32[0] = v116 - v112;
  v122 = v115 - v111;
  if ( (float)((float)((float)(v118.m128_f32[0] * v118.m128_f32[0]) + (float)(v122 * v122)) + (float)(v121 * v121)) == 0.0 )
    v123 = 0.0;
  else
    v123 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v118));
  v124 = v121 * v123;
  v125 = v118.m128_f32[0] * v123;
  v126 = v123 * v122;
  v127 = (float)(v120 * v124) + v113;
  v128 = (float)(v120 * v125) + v112;
  v129 = v111 + (float)(v120 * v126);
  v130 = &v2->mAimLook.mDuration.x;
  v130[21] = v129;
  v130[22] = v128;
  v130[23] = v127;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimLook);
  *(_QWORD *)&v2->mAimLook.mParameter.x = 0i64;
  v2->mAimLook.mParameter.z = 0.0;
  v131 = &v2->mLook.mDuration.x;
  v131[21] = v129;
  v131[22] = v128;
  v131[23] = v127;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mLook);
  *(_QWORD *)&v2->mLook.mParameter.x = 0i64;
  v2->mLook.mParameter.z = 0.0;
  v277 = 0;
  if ( !v2->bAimUseEyeLook )
  {
    v132 = v2->mAimEye.p1.y;
    v133 = v2->mAimEye.p1.z;
    v2->mAimEye.p0.x = v2->mAimEye.p1.x;
    v2->mAimEye.p0.y = v132;
    v2->mAimEye.p0.z = v133;
    v134 = v2->mAimEye.v1.y;
    v135 = v2->mAimEye.v1.z;
    v2->mAimEye.v0.x = v2->mAimEye.v1.x;
    v2->mAimEye.v0.y = v134;
    v2->mAimEye.v0.z = v135;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimEye);
    *(_QWORD *)&v2->mAimEye.mParameter.x = 0i64;
    v2->mAimEye.mParameter.z = 0.0;
    v136 = v2->mAimLook.p1.y;
    v137 = v2->mAimLook.p1.z;
    v2->mAimLook.p0.x = v2->mAimLook.p1.x;
    v2->mAimLook.p0.y = v136;
    v2->mAimLook.p0.z = v137;
    v138 = v2->mAimLook.v1.y;
    v139 = v2->mAimLook.v1.z;
    v2->mAimLook.v0.x = v2->mAimLook.v1.x;
    v2->mAimLook.v0.y = v138;
    v2->mAimLook.v0.z = v139;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimLook);
    *(_QWORD *)&v2->mAimLook.mParameter.x = 0i64;
    v2->mAimLook.mParameter.z = 0.0;
  }
  v2->bAimUseEyeLook = 1;
  v56 = _xmm[0];
LABEL_266:
  LOBYTE(constrainYaw[0]) = 0;
  v154 = dta;
  UFG::FollowCameraComponent::UpdateGotos(v2, dta, (bool *)constrainYaw);
  v155 = 0;
  v156 = 0;
  if ( v285 )
  {
    v157 = v280;
    v158 = UFG::InputSystem::AcquireController(UFG::gInputSystem, v280);
    v159 = v158;
    if ( v158 && v158->m_IsKeyboardController )
    {
      v155 = 1;
      v160 = 0;
      if ( UFG::UI::InMinigame() )
      {
        v160 = 0;
        if ( (v159->m_SubModes >> 2) & 1 )
          v160 = 1;
      }
      v161 = UFG::UIScreenManagerBase::getScreen(
               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
               "DialogBox");
      if ( (!UFG::UI::InMinigame() || v160) && !v161 )
      {
        v162 = UFG::ActionDef_Mouse.mDataPerController[v157];
        if ( v162 )
          v163 = v162->mAxisPositionX;
        else
          v163 = 0.0;
        v164 = UFG::GameStatTracker::Instance();
        if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v164, XAxisInverted) )
          v165 = FLOAT_N1_0;
        else
          v165 = *(float *)&FLOAT_1_0;
        v166 = v163 * v165;
        v167 = UFG::ActionDef_Mouse.mDataPerController[v157];
        if ( v167 )
          v168 = v167->mAxisPositionY;
        else
          v168 = 0.0;
        v169 = UFG::GameStatTracker::Instance();
        if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v169, YAxisInverted) )
          v170 = FLOAT_N1_0;
        else
          v170 = *(float *)&FLOAT_1_0;
        v171 = v168 * v170;
        v172 = &v2->mMouseBucketX;
        v2->mMouseBucketX = (float)(v166 * 0.033333335) + v2->mMouseBucketX;
        v173 = &v2->mMouseBucketY;
        v174 = (float)(v171 * 0.033333335) + v2->mMouseBucketY;
        v2->mMouseBucketY = v174;
        v175 = v2->mMouseBucketX;
        if ( v175 <= COERCE_FLOAT(LODWORD(UFG::FollowCameraComponent::mMouseBucketCapacityX) ^ v56) )
          LODWORD(v175) = LODWORD(UFG::FollowCameraComponent::mMouseBucketCapacityX) ^ v56;
        if ( v175 >= UFG::FollowCameraComponent::mMouseBucketCapacityX )
          v175 = UFG::FollowCameraComponent::mMouseBucketCapacityX;
        *v172 = v175;
        if ( v174 <= COERCE_FLOAT(LODWORD(UFG::FollowCameraComponent::mMouseBucketCapacityY) ^ v56) )
          LODWORD(v174) = LODWORD(UFG::FollowCameraComponent::mMouseBucketCapacityY) ^ v56;
        if ( v174 >= UFG::FollowCameraComponent::mMouseBucketCapacityY )
          v174 = UFG::FollowCameraComponent::mMouseBucketCapacityY;
        *v173 = v174;
        UFG::qApproach(&v2->mMouseBucketX, 0.0, UFG::FollowCameraComponent::mMouseBucketBleedRateX * 30.0, v154);
        v176 = v175 - *v172;
        v177 = *v173;
        UFG::qApproach(&v2->mMouseBucketY, 0.0, UFG::FollowCameraComponent::mMouseBucketBleedRateY * 30.0, v154);
        v178 = v177 - *v173;
        v156 = v176 != 0.0 || v178 != 0.0;
        v179 = UFG::GameStatTracker::Instance();
        v180 = UFG::GameStatTracker::GetStat(v179, CameraSpeedYaw);
        v181 = UFG::GameStatTracker::Instance();
        v182 = UFG::GameStatTracker::GetStat(v181, CameraSpeedPitch);
        v183 = v176
             * (float)((float)((float)(UFG::FollowCameraComponent::rMouseSpeedScaleHMax
                                     - UFG::FollowCameraComponent::rMouseSpeedScaleHMin)
                             * v180)
                     + UFG::FollowCameraComponent::rMouseSpeedScaleHMin);
        v184 = v178
             * (float)((float)((float)(UFG::FollowCameraComponent::rMouseSpeedScaleVMax
                                     - UFG::FollowCameraComponent::rMouseSpeedScaleVMin)
                             * v182)
                     + UFG::FollowCameraComponent::rMouseSpeedScaleVMin);
        if ( UFG::GameCameraComponent::mNoRotationTimer > 0.0 )
        {
          v183 = 0.0;
          v184 = 0.0;
        }
        if ( UFG::bCameraDebugText )
        {
          v185 = *(Render::DebugDrawContext **)&position.x;
          Render::DebugDrawContext::DrawTextA(
            *(Render::DebugDrawContext **)&position.x,
            300,
            324,
            &UFG::qColour::White,
            "Dx: %f  Dy:%f  ",
            v166,
            v171);
          Render::DebugDrawContext::DrawTextA(v185, 300, 336, &UFG::qColour::White, "Mx: %f  My:%f  ", *v172, *v173);
          Render::DebugDrawContext::DrawTextA(
            v185,
            300,
            348,
            &UFG::qColour::White,
            "dnx: %f  dny:%f  dt: %f",
            v183,
            v184,
            v154);
        }
        UFG::FollowCameraComponent::Rotate(v2, v184, COERCE_FLOAT(LODWORD(v183) ^ _xmm[0]));
      }
    }
    else
    {
      v186 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v157];
      if ( v186 && v186->mActionTrue )
      {
        v187 = UFG::GameStatTracker::Instance();
        if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v187, YAxisInverted) )
          v188 = FLOAT_N1_0;
        else
          v188 = *(float *)&FLOAT_1_0;
        v189 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v157];
        if ( v189 )
          v190 = v189->mAxisPositionY;
        else
          v190 = 0.0;
        v191 = v188 * v190;
        v192 = UFG::GameStatTracker::Instance();
        if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v192, XAxisInverted) )
          v193 = FLOAT_N1_0;
        else
          v193 = *(float *)&FLOAT_1_0;
        v194 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v157];
        if ( v194 )
          v195 = v194->mAxisPositionX;
        else
          v195 = 0.0;
        v196 = COERCE_FLOAT(LODWORD(v195) ^ v56) * v193;
        if ( v191 <= 0.0 )
        {
          if ( v191 >= 0.0 )
            v197 = 0.0;
          else
            v197 = FLOAT_N1_0;
        }
        else
        {
          v197 = *(float *)&FLOAT_1_0;
        }
        v198 = powf(COERCE_FLOAT(LODWORD(v191) & _xmm), 2.0) * v197;
        if ( v196 <= 0.0 )
        {
          if ( v196 >= 0.0 )
            v199 = 0.0;
          else
            v199 = FLOAT_N1_0;
        }
        else
        {
          v199 = *(float *)&FLOAT_1_0;
        }
        v200 = powf(COERCE_FLOAT(LODWORD(v196) & _xmm), 2.0) * v199;
        if ( UFG::GameCameraComponent::mNoRotationTimer > 0.0 )
        {
          v200 = 0.0;
          v198 = 0.0;
        }
        if ( (float)(COERCE_FLOAT(LODWORD(v198) & _xmm) + COERCE_FLOAT(LODWORD(v200) & _xmm)) > 0.001 )
        {
          v201 = UFG::GameStatTracker::Instance();
          v202 = (float)((float)((float)((float)(UFG::FollowCameraComponent::rOptionsFactorSpeedYawMax
                                               - UFG::FollowCameraComponent::rOptionsFactorSpeedYawMin)
                                       * UFG::GameStatTracker::GetStat(v201, CameraSpeedYaw))
                               + UFG::FollowCameraComponent::rOptionsFactorSpeedYawMin)
                       * v2->mBlendedParams.mTweakOrbitSpeed)
               * (float)(v200 * v154);
          if ( LOBYTE(constrainYaw[0]) )
            v202 = 0.0;
          v203 = UFG::GameStatTracker::Instance();
          v204 = UFG::GameStatTracker::GetStat(v203, CameraSpeedPitch);
          UFG::FollowCameraComponent::Rotate(
            v2,
            (float)((float)((float)((float)(UFG::FollowCameraComponent::rOptionsFactorSpeedPitchMax
                                          - UFG::FollowCameraComponent::rOptionsFactorSpeedPitchMin)
                                  * v204)
                          + UFG::FollowCameraComponent::rOptionsFactorSpeedPitchMin)
                  * v2->mBlendedParams.mTweakOrbitSpeed)
          * (float)(v198 * v154),
            v202);
        }
      }
    }
  }
  if ( v277 )
  {
    v205 = v2->mLook.p1.x;
    v206 = v2->mLook.p1.y;
    v207 = v2->mLook.p1.z;
    v208 = v2->mEye.p1.z - v207;
    v209 = v2->mEye.p1.y - v206;
    v210 = v2->mEye.p1.x - v205;
    centre.x = v2->mEye.p1.x - v205;
    centre.y = v209;
    centre.z = v208;
    v211 = UFG::GameStatTracker::Instance();
    if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v211, CameraFreeLook) )
    {
      if ( !v2->mMouseBoomSet || v156 )
      {
        v2->mMouseBoom.x = v210;
        v2->mMouseBoom.y = v209;
        v2->mMouseBoom.z = v208;
        v2->mMouseBoomSet = 1;
      }
      if ( v155 && v2->mGotoRadiusPatience <= 0.0 && v2->mGotoAnglePatience <= 0.0 && v2->mGotoRisePatience <= 0.0 )
      {
        v210 = v2->mMouseBoom.x;
        v209 = v2->mMouseBoom.y;
        v208 = v2->mMouseBoom.z;
        centre.x = v2->mMouseBoom.x;
        centre.y = v209;
        centre.z = v208;
      }
    }
    v212 = UFG::FollowCameraComponent::BoomClamp(v2, &centre);
    v213 = centre.y;
    v214 = centre.x;
    v215 = centre.z;
    if ( (float)((float)((float)(v209 * centre.y) + (float)(v210 * centre.x)) + (float)(v208 * centre.z)) < 0.0 )
    {
      v214 = v210;
      v213 = v209;
      v215 = v208;
      v212 = 0;
    }
    if ( v155 || v212 )
    {
      v2->mEye.p1.x = v205 + v214;
      v2->mEye.p1.y = v206 + v213;
      v2->mEye.p1.z = v207 + v215;
      UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
      *(_QWORD *)&v2->mEye.mParameter.x = 0i64;
      v2->mEye.mParameter.z = 0.0;
    }
  }
  v216 = (__m128)LODWORD(v2->mEye.p1.x);
  v217 = v2->mEye.p1.z - v2->mLook.p1.z;
  v218 = v2->mEye.p1.y - v2->mLook.p1.y;
  v216.m128_f32[0] = v216.m128_f32[0] - v2->mLook.p1.x;
  LODWORD(v2->mControllerForward.x) = v216.m128_i32[0];
  v2->mControllerForward.y = v218;
  v2->mControllerForward.z = v217;
  v216.m128_f32[0] = (float)((float)(v216.m128_f32[0] * v216.m128_f32[0]) + (float)(v218 * v218))
                   + (float)(v2->mControllerForward.z * v2->mControllerForward.z);
  LODWORD(v219) = (unsigned __int128)_mm_sqrt_ps(v216);
  v2->mControllerForward.x = (float)(1.0 / v219) * v2->mControllerForward.x;
  v2->mControllerForward.y = (float)(1.0 / v219) * v2->mControllerForward.y;
  v2->mControllerForward.z = (float)(1.0 / v219) * v2->mControllerForward.z;
  if ( (unsigned int)(v2->mContext - 5) > 1 )
  {
    v220 = v219 * 0.625;
    if ( v220 > 1.0 )
      v220 = *(float *)&FLOAT_1_0;
    v221 = tanf((float)((float)(v2->mFov.p1 * 3.1415927) * 0.0055555557) * 0.5);
    v222 = (float)((float)(atan2f(v221 / v220, 1.0) * 2.0) * 180.0) * 0.31830987;
    v223 = v2->mBlendedParams.mTweakFovMax;
    if ( v223 >= v222 )
      v223 = v222;
    v2->mFov.p1 = v223;
    UFG::HomerCubic<float>::MakeCoeffs(&v2->mFov);
    v2->mFov.mParameter = 0.0;
  }
  v224 = &v2->mOffsetLook.mDuration.x;
  v225 = v2->mBlendedParams.mTweakLookOffset.y;
  v226 = v2->mBlendedParams.mTweakLookOffset.z;
  v224[21] = v2->mBlendedParams.mTweakLookOffset.x;
  v224[22] = v225;
  v224[23] = v226;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mOffsetLook);
  *(_QWORD *)&v2->mOffsetLook.mParameter.x = 0i64;
  v2->mOffsetLook.mParameter.z = 0.0;
  v227 = (signed __int64)&v2->mOffsetEye;
  v228 = UFG::qVector3::msZero.y;
  v229 = UFG::qVector3::msZero.z;
  *(float *)(v227 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v227 + 88) = v228;
  *(float *)(v227 + 92) = v229;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mOffsetEye);
  *(_QWORD *)&v2->mOffsetEye.mParameter.x = 0i64;
  v2->mOffsetEye.mParameter.z = 0.0;
  v230 = (float)((float)(UFG::qVector3::msAxisZ.y * COERCE_FLOAT(LODWORD(v2->mControllerForward.y) ^ _xmm[0]))
               + (float)(UFG::qVector3::msAxisZ.x * COERCE_FLOAT(LODWORD(v2->mControllerForward.x) ^ _xmm[0])))
       + (float)(UFG::qVector3::msAxisZ.z * COERCE_FLOAT(LODWORD(v2->mControllerForward.z) ^ _xmm[0]));
  if ( v230 <= -1.0 )
  {
    v231 = FLOAT_N1_0;
  }
  else
  {
    v231 = (float)((float)(UFG::qVector3::msAxisZ.y * COERCE_FLOAT(LODWORD(v2->mControllerForward.y) ^ _xmm[0]))
                 + (float)(UFG::qVector3::msAxisZ.x * COERCE_FLOAT(LODWORD(v2->mControllerForward.x) ^ _xmm[0])))
         + (float)(UFG::qVector3::msAxisZ.z * COERCE_FLOAT(LODWORD(v2->mControllerForward.z) ^ _xmm[0]));
    if ( v230 >= 1.0 )
      v231 = *(float *)&FLOAT_1_0;
  }
  v232 = acosf(v231);
  v233 = v232;
  if ( UFG::bCameraDebugText )
    Render::DebugDrawContext::DrawTextA(
      *(Render::DebugDrawContext **)&position.x,
      40,
      106,
      &UFG::qColour::White,
      "Lookup Angle: %f\n",
      (float)((float)(v232 * 180.0) * 0.31830987));
  v235 = 0;
  if ( *(_QWORD *)&v278.x )
  {
    v234 = *(_QWORD *)(*(_QWORD *)&v278.x
                     + 8 * ((signed __int64)(signed int)gActionRequest_UseCover.m_EnumValue >> 6)
                     + 712);
    if ( _bittest64(&v234, gActionRequest_UseCover.m_EnumValue & 0x3F) )
      v235 = 1;
  }
  if ( !(_S12_2 & 1) )
  {
    _S12_2 |= 1u;
    UFG::qSymbol::create_from_string(&contextSymbolSwim, "Cameras-FollowCameraSwim");
    atexit(UFG::FollowCameraComponent::UpdateControllers_::_236_::_dynamic_atexit_destructor_for__contextSymbolSwim__);
  }
  v236 = v2->mType == eFOLLOW_CAMERA_TYPE_TOW
      && UFG::FollowCameraComponent::mContextParameterSymbols[v2->mContext].mUID == contextSymbolSwim.mUID;
  if ( v230 <= 0.0 )
    v237 = UFG::FollowCameraComponent::rLookdownGlobalAngleStart;
  else
    v237 = UFG::FollowCameraComponent::rLookupGlobalAngleStart;
  if ( v235 )
  {
    if ( v230 <= 0.0 )
    {
      v237 = UFG::FollowCameraComponent::rLookdownCoverAngleStart;
      goto LABEL_384;
    }
    v237 = UFG::FollowCameraComponent::rLookupCoverAngleStart;
  }
  else if ( v236 )
  {
    if ( v230 <= 0.0 )
    {
      v237 = UFG::FollowCameraComponent::rLookdownSwimAngleStart;
      goto LABEL_384;
    }
    v237 = UFG::FollowCameraComponent::rLookupSwimAngleStart;
  }
  if ( v230 > 0.0 )
  {
    v238 = UFG::FollowCameraComponent::rLookupGlobalAngleEnd;
    goto LABEL_385;
  }
LABEL_384:
  v238 = UFG::FollowCameraComponent::rLookdownGlobalAngleEnd;
LABEL_385:
  if ( v235 )
  {
    if ( v230 <= 0.0 )
      v238 = UFG::FollowCameraComponent::rLookdownCoverAngleEnd;
    else
      v238 = UFG::FollowCameraComponent::rLookupCoverAngleEnd;
  }
  else if ( v236 )
  {
    if ( v230 <= 0.0 )
      v238 = UFG::FollowCameraComponent::rLookdownSwimAngleEnd;
    else
      v238 = UFG::FollowCameraComponent::rLookupSwimAngleEnd;
  }
  v239 = (float)(v237 * 3.1415927) * 0.0055555557;
  v240 = (float)(v238 * 3.1415927) * 0.0055555557;
  if ( v230 <= 0.0 )
    v241 = UFG::FollowCameraComponent::rLookdownGlobalLookHeightOffset;
  else
    v241 = UFG::FollowCameraComponent::rLookupGlobalLookHeightOffset;
  if ( v235 )
  {
    if ( v230 <= 0.0 )
    {
      v241 = UFG::FollowCameraComponent::rLookdownCoverLookHeightOffset;
      goto LABEL_406;
    }
    v241 = UFG::FollowCameraComponent::rLookupCoverLookHeightOffset;
  }
  else if ( v236 )
  {
    if ( v230 <= 0.0 )
    {
      v241 = UFG::FollowCameraComponent::rLookdownSwimLookHeightOffset;
      goto LABEL_406;
    }
    v241 = UFG::FollowCameraComponent::rLookupSwimLookHeightOffset;
  }
  if ( v230 > 0.0 )
  {
    v242 = UFG::FollowCameraComponent::rLookupGlobalEyeHeightOffset;
    goto LABEL_407;
  }
LABEL_406:
  v242 = UFG::FollowCameraComponent::rLookdownGlobalEyeHeightOffset;
LABEL_407:
  if ( v235 )
  {
    if ( v230 <= 0.0 )
    {
      v242 = UFG::FollowCameraComponent::rLookdownCoverEyeHeightOffset;
      goto LABEL_417;
    }
    v242 = UFG::FollowCameraComponent::rLookupCoverEyeHeightOffset;
  }
  else if ( v236 )
  {
    if ( v230 <= 0.0 )
    {
      v242 = UFG::FollowCameraComponent::rLookdownSwimEyeHeightOffset;
      goto LABEL_417;
    }
    v242 = UFG::FollowCameraComponent::rLookupSwimEyeHeightOffset;
  }
  if ( v230 > 0.0 )
  {
    v243 = UFG::FollowCameraComponent::rLookupGlobalLookForwardOffset;
    goto LABEL_418;
  }
LABEL_417:
  v243 = UFG::FollowCameraComponent::rLookdownGlobalLookForwardOffset;
LABEL_418:
  if ( v235 )
  {
    if ( v230 > 0.0 )
    {
      v243 = UFG::FollowCameraComponent::rLookupCoverLookForwardOffset;
      goto LABEL_426;
    }
    v243 = UFG::FollowCameraComponent::rLookdownCoverLookForwardOffset;
LABEL_428:
    v244 = UFG::FollowCameraComponent::rLookdownGlobalEyeForwardOffset;
    goto LABEL_429;
  }
  if ( v236 )
  {
    if ( v230 <= 0.0 )
    {
      v243 = UFG::FollowCameraComponent::rLookdownSwimLookForwardOffset;
      goto LABEL_428;
    }
    v243 = UFG::FollowCameraComponent::rLookupSwimLookForwardOffset;
  }
LABEL_426:
  if ( v230 <= 0.0 )
    goto LABEL_428;
  v244 = UFG::FollowCameraComponent::rLookupGlobalEyeForwardOffset;
LABEL_429:
  if ( v235 )
  {
    if ( v230 <= 0.0 )
      v244 = UFG::FollowCameraComponent::rLookdownCoverEyeForwardOffset;
    else
      v244 = UFG::FollowCameraComponent::rLookupCoverEyeForwardOffset;
  }
  else if ( v236 )
  {
    if ( v230 <= 0.0 )
      v244 = UFG::FollowCameraComponent::rLookdownSwimEyeForwardOffset;
    else
      v244 = UFG::FollowCameraComponent::rLookupSwimEyeForwardOffset;
  }
  v245 = (float)(v233 - v239) / (float)(v240 - v239);
  if ( v245 <= 0.0 )
  {
    v246 = 0.0;
  }
  else
  {
    v246 = v245;
    if ( v245 >= 1.0 )
      v246 = *(float *)&FLOAT_1_0;
  }
  v247 = v246 * v241;
  if ( v245 <= 0.0 )
  {
    v248 = 0.0;
  }
  else
  {
    v248 = v245;
    if ( v245 >= 1.0 )
      v248 = *(float *)&FLOAT_1_0;
  }
  v249 = v248 * v242;
  if ( v245 <= 0.0 )
  {
    v250 = 0.0;
  }
  else
  {
    v250 = v245;
    if ( v245 >= 1.0 )
      v250 = *(float *)&FLOAT_1_0;
  }
  v251 = v250 * v243;
  if ( v245 <= 0.0 )
  {
    v252 = 0.0;
  }
  else
  {
    v252 = v245;
    if ( v245 >= 1.0 )
      v252 = *(float *)&FLOAT_1_0;
  }
  v253 = v252 * v244;
  if ( v230 <= 0.0 )
    v254 = UFG::FollowCameraComponent::rLookdownGlobalFOVOffset;
  else
    v254 = UFG::FollowCameraComponent::rLookupGlobalFOVOffset;
  if ( v235 )
  {
    if ( v230 <= 0.0 )
      v254 = UFG::FollowCameraComponent::rLookdownCoverFOVOffset;
    else
      v254 = UFG::FollowCameraComponent::rLookupCoverFOVOffset;
  }
  else if ( v236 )
  {
    if ( v230 <= 0.0 )
      v254 = UFG::FollowCameraComponent::rLookdownSwimFOVOffset;
    else
      v254 = UFG::FollowCameraComponent::rLookupSwimFOVOffset;
  }
  if ( v245 <= 0.0 )
  {
    v245 = 0.0;
  }
  else if ( v245 >= 1.0 )
  {
    v245 = *(float *)&FLOAT_1_0;
  }
  v255 = v245 * v254;
  v256 = v2->mOffsetLook.p1.x;
  position.x = v2->mOffsetLook.p1.x;
  position.y = v2->mOffsetLook.p1.y;
  v257 = v2->mOffsetLook.p1.z;
  position.z = v2->mOffsetLook.p1.z;
  v258 = v2->mOffsetEye.p1.x;
  v278.x = v2->mOffsetEye.p1.x;
  v278.y = v2->mOffsetEye.p1.y;
  v259 = v2->mOffsetEye.p1.z;
  v278.z = v2->mOffsetEye.p1.z;
  v260 = v2->mFov.p1;
  if ( v2->mBlendedParams.mUseLookUpDown )
  {
    position.x = v256 + v251;
    position.z = v257 + v247;
    v278.x = v258 + v253;
    v278.z = v259 + v249;
  }
  v261 = v260 + (float)((float)(1.0 - v2->mTransitionParamEye) * (float)(v255 + v281));
  UFG::HomerCubic<UFG::qVector3>::SetDesiredPosition(&v2->mOffsetLook, &position);
  UFG::HomerCubic<UFG::qVector3>::SetDesiredPosition(&v2->mOffsetEye, &v278);
  if ( (unsigned int)(v2->mContext - 5) > 1 )
  {
    v2->mFov.p1 = v261;
    UFG::HomerCubic<float>::MakeCoeffs(&v2->mFov);
    v2->mFov.mParameter = 0.0;
  }
  v262 = UFG::FollowCameraComponent::bHorizCompUseTweakables;
  v263 = UFG::FollowCameraComponent::bHorizCompUseDirection;
  if ( !UFG::FollowCameraComponent::bHorizCompUseTweakables )
    v263 = v2->mBlendedParams.mHorizCompUseDirection;
  v264 = UFG::ActionDef_LeftThumbStick.mDataPerController[v280];
  if ( v264 )
    v265 = v264->mAxisPositionX;
  else
    v265 = 0.0;
  if ( v263 )
  {
    v266 = (float *)((__int64 (*)(void))v2->mTarget.m_pSimComponent->vfptr[15].__vecDelDtor)();
    v268 = (__m128)LODWORD(v2->mLook.p0.y);
    v267 = v2->mLook.p0.x - v2->mEye.p0.x;
    v268.m128_f32[0] = v268.m128_f32[0] - v2->mEye.p0.y;
    if ( (float)((float)(v268.m128_f32[0] * v268.m128_f32[0]) + (float)(v267 * v267)) == 0.0 )
      v269 = 0.0;
    else
      v269 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v268));
    v265 = (float)((float)((float)(v269 * v268.m128_f32[0]) * v266[1]) + (float)((float)(v269 * v267) * *v266))
         + (float)((float)(v269 * 0.0) * v266[2]);
    v262 = UFG::FollowCameraComponent::bHorizCompUseTweakables;
  }
  v270 = (float)(COERCE_FLOAT(LODWORD(v265) & _xmm) - UFG::FollowCameraComponent::rHorizCompInputDeadZone)
       / (float)(1.0 - UFG::FollowCameraComponent::rHorizCompInputDeadZone);
  if ( v270 <= 0.0 )
  {
    v270 = 0.0;
  }
  else if ( v270 >= 1.0 )
  {
    v270 = *(float *)&FLOAT_1_0;
  }
  if ( v265 <= 0.0 )
  {
    if ( v265 >= 0.0 )
      v55 = 0.0;
  }
  else
  {
    v55 = *(float *)&FLOAT_1_0;
  }
  v271 = (float)(v270 * v270) * v55;
  if ( v262 )
  {
    v272 = UFG::FollowCameraComponent::rHorizCompSpeedMin;
    v273 = UFG::FollowCameraComponent::rHorizCompSpeedMax;
  }
  else
  {
    v272 = v2->mBlendedParams.mHorizCompSpeedMin;
    v273 = v2->mBlendedParams.mHorizCompSpeedMax;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v272 - v273) & _xmm) > 0.00000011920929 )
  {
    v274 = (float)(UFG::qAverageWindow<float>::GetAverage(&v2->mHorizCompTargetSpeedWindow) - v272)
         / (float)(v273 - v272);
    if ( v274 > 0.0 )
    {
      v4 = v274;
      if ( v274 >= 1.0 )
        v4 = *(float *)&FLOAT_1_0;
    }
  }
  if ( v262 )
    v275 = UFG::FollowCameraComponent::rHorizCompOffsetScale;
  else
    v275 = v2->mBlendedParams.mHorizCompOffsetScale;
  v2->mHorizCompOffset.p1 = (float)(v275 * v271) * v4;
  UFG::HomerCubic<float>::MakeCoeffs(&v2->mHorizCompOffset);
  v2->mHorizCompOffset.mParameter = 0.0;
}
    if ( (float)((float)(v268.m128_f32[0] * v268.m128_f32[0]) + (float)(v267 * v267)) == 0.0 )
      v269 = 0.0;
    else
      v269 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v268));
    v265 = (float)((float)((float)(v269 * v268.m128_f32[0]) * v266[1]) + (float)((float)(v269 * v267) * *v266))
         + (float)((float)(v269 * 0.0) * v266[2]);
    v262 = UFG::FollowCameraComponent::bHorizCompUseTweakables;
  }
  v270 = (float)(COERCE_FLOAT(LODWORD(v265) & _xmm) - UFG::FollowCameraComponent::rHorizCompInputDeadZone)
       / (float)(1.0 - UFG::FollowCameraComponent::rHorizCompInputDeadZone);
  if ( v270 <= 0.0 )
  {
    v270 = 0.0;
  }
  else if ( v270 >= 1.0 )
  {
    v270 = *(float *)&FLOAT_1_0;
  }
  if ( v265 <= 0.0 )
  {
    if ( v265 >= 0.0 )
      v55 = 0.0;
  }
  else
  {
    v55 = *(float *)&FLOAT_1_0;
  }
  v271 = (float)(v270 * v270) * v55;
  if ( v262 )
  {
    v272 = UFG::FollowCameraComponent::rHorizCompSpeedMin;
    v273 = UFG::FollowCameraComponent::rHorizCompSpeedMax;
  }
  else
  {
    v272 = v2->mBlendedParams.mHorizCompSpeedMin;
    v273 = v2->mBlendedParams.mHorizCompSpeedMax;
  }
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v272 - v273) & _xmm) > 0.00000011920929 )
  {
    v274 = (float)(UFG::qAverageWindow<float>::GetAverage(&v2->mHorizCompTargetSpeedWindow) - v272)
         / (float)(v273 - v272);
    if ( v274 > 0.0 )
    {
      v4 = v274;
      if ( v274 >= 1.0 )
        v4 = *(float *)&FLOAT_1_0;
    }
  }
  if ( v262 )
    v275 = UFG::FollowCameraComponent::rHorizCompOffsetScale;
  else
    v275 = v2->mBlendedParams.mHorizCompOffsetScale;
  v2->mHorizCompOffset.

// File Line: 3965
// RVA: 0x3DC1B0
void __fastcall UFG::FollowCameraComponent::UpdateGotos(UFG::FollowCameraComponent *this, float dt, bool *constrainYaw)
{
  UFG::FollowCameraComponent *v3; // rdi
  float v4; // xmm14_4
  bool v5; // r12
  float *v6; // rbx
  float *v7; // r14
  bool *v8; // r13
  bool v9; // zf
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  __m128 v13; // xmm3
  float v14; // xmm6_4
  __m128 v15; // xmm4
  float v16; // xmm1_4
  float i; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm11_4
  float v21; // xmm12_4
  float v22; // xmm6_4
  __int64 v23; // rax
  signed __int64 v24; // rcx
  float v25; // xmm0_4
  float v26; // xmm0_4
  int v27; // xmm15_4
  float v28; // xmm14_4
  float v29; // xmm15_4
  float v30; // xmm13_4
  float v31; // xmm6_4
  __m128 v32; // xmm11
  float v33; // xmm12_4
  __m128 v34; // xmm1
  float v35; // xmm0_4
  float v36; // xmm0_4
  float *v37; // rcx
  float v38; // xmm1_4
  char v39; // al
  char *v40; // rsi
  char v41; // bl
  float v42; // xmm11_4
  float v43; // xmm13_4
  float v44; // xmm14_4
  float v45; // xmm1_4
  float v46; // xmm12_4
  __m128 v47; // xmm6
  float v48; // xmm3_4
  __m128 v49; // xmm4
  __m128 v50; // xmm2
  float v51; // xmm1_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm14_4
  float v57; // xmm6_4
  float v58; // xmm0_4
  float v59; // xmm6_4
  float v60; // xmm0_4
  float v61; // xmm12_4
  char v62; // al
  char v63; // r14
  UFG::SimObjectCVBase *v64; // rcx
  unsigned __int16 v65; // dx
  UFG::TargetingSystemPedPlayerComponent *v66; // rbx
  UFG::SimObjectCharacter *v67; // rcx
  unsigned __int16 v68; // dx
  UFG::AimingPlayerComponent *v69; // rsi
  float j; // xmm6_4
  float v71; // xmm0_4
  float v72; // xmm6_4
  float v73; // xmm7_4
  float v74; // xmm0_4
  float *v75; // rcx
  float v76; // xmm1_4
  float v77; // xmm14_4
  float v78; // xmm2_4
  float v79; // xmm14_4
  float v80; // xmm12_4
  float value; // [rsp+50h] [rbp-70h]
  bool farthestAngle; // [rsp+54h] [rbp-6Ch]
  float yawConstraintRate; // [rsp+58h] [rbp-68h]
  float angleB; // [rsp+5Ch] [rbp-64h]
  float v85; // [rsp+60h] [rbp-60h]
  float angle; // [rsp+64h] [rbp-5Ch]
  float v87; // [rsp+68h] [rbp-58h]
  float v88; // [rsp+6Ch] [rbp-54h]
  UFG::qVector3 vDirection; // [rsp+70h] [rbp-50h]
  bool angleAdditive; // [rsp+130h] [rbp+70h]
  float delta_sec; // [rsp+138h] [rbp+78h]
  float v92[2]; // [rsp+140h] [rbp+80h]
  bool useSecond; // [rsp+148h] [rbp+88h]

  v3 = this;
  angleAdditive = 0;
  v4 = dt;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v5 = v3->mSnapNext;
  v6 = &v3->mGotoRise;
  if ( UFG::CharacterSubjectComponent::GetAndClearGotoRise(
         (UFG::CharacterSubjectComponent *)v3->mTarget.m_pSimComponent,
         &v3->mGotoRise,
         &v3->mGotoRiseRate,
         &v3->mGotoRisePatience) )
  {
    v3->mGotoRiseElaspedTime = 0.0;
    v5 = 0;
  }
  v7 = &v3->mGotoRadiusPatience;
  if ( UFG::CharacterSubjectComponent::GetAndClearGotoRadius(
         (UFG::CharacterSubjectComponent *)v3->mTarget.m_pSimComponent,
         &v3->mGotoRadius,
         &v3->mGotoRadiusRate,
         &v3->mGotoRadiusPatience) )
  {
    v3->mGotoRadiusElaspedTime = 0.0;
    v5 = 0;
  }
  v8 = &v3->mGotoAngleLocalSpace;
  if ( UFG::CharacterSubjectComponent::GetAndClearGotoAngle(
         (UFG::CharacterSubjectComponent *)v3->mTarget.m_pSimComponent,
         &angle,
         &v3->mGotoAngleRate,
         &v3->mGotoAnglePatience,
         &v3->mGotoAngleLocalSpace,
         &useSecond,
         &angleB,
         &farthestAngle,
         &angleAdditive) )
  {
    v9 = useSecond == 0;
    v10 = angle;
    v3->mGotoAngleElaspedTime = 0.0;
    v3->mGotoAngle = v10;
    if ( !v9 )
      v3->mGotoAngle = UFG::FollowCameraComponent::GetClosestAngle(v3, v10, angleB, *v8 == 0, farthestAngle);
    v5 = 0;
  }
  if ( angleAdditive )
  {
    v11 = atan2f(
            COERCE_FLOAT(LODWORD(v3->mTargetWorld.v0.y) ^ _xmm[0]),
            COERCE_FLOAT(LODWORD(v3->mTargetWorld.v0.x) ^ _xmm[0]));
    v13 = (__m128)LODWORD(v3->mEye.p0.y);
    v12 = v3->mEye.p0.x - v3->mLook.p0.x;
    v13.m128_f32[0] = v13.m128_f32[0] - v3->mLook.p0.y;
    v14 = v11;
    v15 = v13;
    v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12))
                    + (float)((float)(v3->mEye.p0.z - v3->mLook.p0.z) * (float)(v3->mEye.p0.z - v3->mLook.p0.z));
    if ( v15.m128_f32[0] == 0.0 )
      v16 = 0.0;
    else
      v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v15));
    i = atan2f(v13.m128_f32[0] * v16, v12 * v16);
    if ( *v8 )
    {
      for ( i = i - v14; i > 3.1415927; i = i + -6.2831855 )
        ;
      for ( ; i < -3.1415927; i = i + 6.2831855 )
        ;
    }
    v18 = i + v3->mGotoAngle;
    v3->mGotoAngle = v18;
    if ( v18 > 3.1415927 )
    {
      do
        v18 = v18 + -6.2831855;
      while ( v18 > 3.1415927 );
      v3->mGotoAngle = v18;
    }
    v19 = v3->mGotoAngle;
    if ( v19 < -3.1415927 )
    {
      do
        v19 = v19 + 6.2831855;
      while ( v19 < -3.1415927 );
      v3->mGotoAngle = v19;
    }
  }
  if ( v3->mGotoRisePatience > 0.0 )
  {
    v20 = v3->mEye.p1.x;
    v21 = v3->mEye.p1.y;
    v22 = v3->mEye.p1.z;
    value = v22 - *(float *)(((__int64 (*)(void))v3->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)() + 8);
    if ( v5 )
      value = *v6;
    else
      UFG::qApproach(&value, *v6, v3->mGotoRiseRate, v4);
    v23 = ((__int64 (*)(void))v3->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
    v24 = (signed __int64)&v3->mEye;
    v25 = value + *(float *)(v23 + 8);
    *(float *)(v24 + 84) = v20;
    *(float *)(v24 + 88) = v21;
    *(float *)(v24 + 92) = v25;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
    *(_QWORD *)&v3->mEye.mParameter.x = 0i64;
    v3->mEye.mParameter.z = 0.0;
    v26 = v4 + v3->mGotoRiseElaspedTime;
    v3->mGotoRiseElaspedTime = v26;
    if ( v5 || v26 > v3->mGotoRisePatience )
      *(_QWORD *)&v3->mGotoRiseElaspedTime = 0i64;
  }
  v27 = _xmm;
  if ( *v7 > 0.0 )
  {
    v32 = (__m128)LODWORD(v3->mEye.p1.y);
    v28 = v3->mLook.p1.x;
    v29 = v3->mLook.p1.y;
    v30 = v3->mLook.p1.z;
    v31 = v3->mEye.p1.x - v28;
    v32.m128_f32[0] = v32.m128_f32[0] - v29;
    v33 = v3->mEye.p1.z - v30;
    v34 = v32;
    v34.m128_f32[0] = (float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v31 * v31);
    LODWORD(yawConstraintRate) = (unsigned __int128)_mm_sqrt_ps(v34);
    value = yawConstraintRate;
    if ( v5 )
    {
      v35 = v3->mGotoRadius;
      value = v3->mGotoRadius;
    }
    else
    {
      UFG::qApproach(&value, v3->mGotoRadius, v3->mGotoRadiusRate, delta_sec);
      v35 = value;
    }
    v36 = v35 / yawConstraintRate;
    v37 = &v3->mEye.mDuration.x;
    v37[23] = v30 + v33;
    v37[21] = (float)(v31 * v36) + v28;
    v37[22] = (float)(v32.m128_f32[0] * v36) + v29;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
    *(_QWORD *)&v3->mEye.mParameter.x = 0i64;
    v3->mEye.mParameter.z = 0.0;
    v27 = _xmm;
    v38 = delta_sec + v3->mGotoRadiusElaspedTime;
    v3->mGotoRadiusElaspedTime = v38;
    if ( v5 || COERCE_FLOAT(COERCE_UNSIGNED_INT(value - v3->mGotoRadius) & _xmm) < 0.059999999 || v38 > *v7 )
    {
      v3->mGotoRadiusElaspedTime = 0.0;
      *v7 = 0.0;
    }
  }
  value = 0.0;
  yawConstraintRate = 0.0;
  v39 = UFG::FollowCameraComponent::NeedConstrainYaw(v3, &value, &yawConstraintRate);
  v40 = *(char **)v92;
  **(_BYTE **)v92 = v39;
  if ( v3->mGotoAnglePatience > v3->mGotoAngleElaspedTime )
    *v40 = 0;
  if ( v3->mGotoAnglePatience > 0.0 || *v40 )
  {
    v41 = *v40;
    v42 = v3->mGotoAngle;
    if ( *v40 )
      v42 = value;
    if ( *v8 || v41 )
      v42 = v42 + (float)(atan2f(v3->mTargetWorld.v0.y, v3->mTargetWorld.v0.x) + 3.1415927);
    v49 = (__m128)LODWORD(v3->mEye.p0.y);
    v43 = v3->mLook.p0.x;
    v44 = v3->mLook.p0.y;
    v45 = v3->mEye.p0.z - v3->mLook.p0.z;
    v46 = v3->mEye.p1.x;
    v47 = (__m128)LODWORD(v3->mEye.p1.y);
    v48 = v3->mEye.p0.x - v43;
    v49.m128_f32[0] = v49.m128_f32[0] - v44;
    value = v3->mEye.p1.z;
    v50 = v49;
    v50.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v48 * v48)) + (float)(v45 * v45);
    v51 = 0.0;
    if ( v50.m128_f32[0] != 0.0 )
      v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
    v52 = atan2f(v49.m128_f32[0] * v51, v48 * v51);
    v53 = v3->mLook.p1.y;
    v54 = v52;
    v88 = v3->mLook.p1.x;
    v85 = v53;
    v55 = v3->mLook.p1.z;
    v47.m128_f32[0] = (float)((float)(v47.m128_f32[0] - v44) * (float)(v47.m128_f32[0] - v44))
                    + (float)((float)(v46 - v43) * (float)(v46 - v43));
    LODWORD(v56) = (unsigned __int128)_mm_sqrt_ps(v47);
    v92[0] = v52;
    v87 = v55;
    value = value - v55;
    if ( v41 )
      v57 = yawConstraintRate;
    else
      v57 = v3->mGotoAngleRate;
    if ( UFG::FollowCameraComponent::bGotoAngleProportionalRateEnabled && !v41 )
    {
      v58 = v42 - v52;
      if ( (float)(v42 - v54) > 3.1415927 )
      {
        do
          v58 = v58 + -6.2831855;
        while ( v58 > 3.1415927 );
      }
      for ( ; v58 < -3.1415927; v58 = v58 + 6.2831855 )
        ;
      v59 = v57
          * (float)(COERCE_FLOAT(LODWORD(v58) & v27) * UFG::FollowCameraComponent::rGotoAngleProportionalRateFactor);
      v60 = v3->mGotoAngleElaspedTime / UFG::FollowCameraComponent::rGotoAngleProportionalRateBlendInDur;
      if ( v60 <= 0.0 )
      {
        v60 = 0.0;
      }
      else if ( v60 >= 1.0 )
      {
        v60 = *(float *)&FLOAT_1_0;
      }
      v57 = v59 * (float)((float)(sinf((float)(v60 * 3.1415927) - 1.5707964) + 1.0) * 0.5);
      if ( v57 < UFG::FollowCameraComponent::rGotoAngleProportionalRateMin )
        v57 = UFG::FollowCameraComponent::rGotoAngleProportionalRateMin;
    }
    v61 = delta_sec;
    v62 = UFG::qApproachAngle(v92, v42, v57, delta_sec);
    v63 = v62;
    if ( UFG::FollowCameraComponent::rGotoAngleEarlyExitTimeMin > v3->mGotoAngleElaspedTime )
    {
      v63 = v62;
      if ( !*v40 )
        v63 = 0;
    }
    if ( v5 )
    {
      v92[0] = v42;
      v63 = 1;
    }
    if ( v3->mTarget.m_pSimComponent
      && (v64 = (UFG::SimObjectCVBase *)v3->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
    {
      v65 = v64->m_Flags;
      if ( (v65 >> 14) & 1 )
      {
        v66 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v64);
      }
      else if ( (v65 & 0x8000u) == 0 )
      {
        if ( (v65 >> 13) & 1 )
        {
          v66 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v64->vfptr,
                                                            UFG::TargetingSystemPedPlayerComponent::_TypeUID);
        }
        else if ( (v65 >> 12) & 1 )
        {
          v66 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v64->vfptr,
                                                            UFG::TargetingSystemPedPlayerComponent::_TypeUID);
        }
        else
        {
          v66 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v64->vfptr,
                                                            UFG::TargetingSystemPedPlayerComponent::_TypeUID);
        }
      }
      else
      {
        v66 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v64);
      }
    }
    else
    {
      v66 = 0i64;
    }
    if ( v3->mTarget.m_pSimComponent
      && (v67 = (UFG::SimObjectCharacter *)v3->mTarget.m_pSimComponent->m_pSimObject) != 0i64 )
    {
      v68 = v67->m_Flags;
      if ( (v68 >> 14) & 1 )
      {
        v69 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v67);
      }
      else if ( (v68 & 0x8000u) == 0 )
      {
        if ( (v68 >> 13) & 1 )
        {
          v69 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v67->vfptr,
                                                UFG::AimingPlayerComponent::_TypeUID);
        }
        else if ( (v68 >> 12) & 1 )
        {
          v69 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v67->vfptr,
                                                UFG::AimingPlayerComponent::_TypeUID);
        }
        else
        {
          v69 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v67->vfptr,
                                                UFG::AimingPlayerComponent::_TypeUID);
        }
      }
      else
      {
        v69 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v67->vfptr,
                                              UFG::AimingPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v69 = 0i64;
    }
    if ( v69 && v66 && !v66->m_bIsAimingActive )
    {
      for ( j = v92[0] + 3.1415927; j > 3.1415927; j = j + -6.2831855 )
        ;
      for ( ; j < -3.1415927; j = j + 6.2831855 )
        ;
      vDirection.x = cosf(j);
      v71 = sinf(j);
      vDirection.z = 0.0;
      vDirection.y = v71;
      UFG::AimingPlayerComponent::SetFreeAimIntention(v69, &vDirection);
    }
    v72 = v92[0];
    v73 = cosf(v92[0]);
    v74 = sinf(v72) * v56;
    v75 = &v3->mEye.mDuration.x;
    v76 = v88 + (float)(v73 * v56);
    v77 = (float)(v56 * 0.0) + v87;
    v78 = v85 + v74;
    v75[21] = v76;
    v79 = v77 + value;
    v75[22] = v78;
    v75[23] = v79;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v3->mEye);
    *(_QWORD *)&v3->mEye.mParameter.x = 0i64;
    v3->mEye.mParameter.z = 0.0;
    v80 = v61 + v3->mGotoAngleElaspedTime;
    v3->mGotoAngleElaspedTime = v80;
    if ( v63 || v80 > v3->mGotoAnglePatience )
    {
      v3->mGotoAngleElaspedTime = 0.0;
      v3->mGotoAnglePatience = 0.0;
    }
  }
}

// File Line: 4247
// RVA: 0x3C7340
char __fastcall UFG::FollowCameraComponent::NeedConstrainYaw(UFG::FollowCameraComponent *this, float *yawConstraintAngle, float *yawConstraintRate)
{
  float *v3; // rsi
  float *v4; // rdi
  UFG::FollowCameraComponent *v5; // rbx
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  __m128 v10; // xmm4
  __m128 v11; // xmm5
  float i; // xmm0_4
  bool v13; // al
  float v14; // xmm8_4
  float v15; // xmm7_4
  float j; // xmm2_4
  float k; // xmm1_4
  float v18; // xmm0_4

  v3 = yawConstraintRate;
  v4 = yawConstraintAngle;
  v5 = this;
  if ( !this->mBlendedParams.mYawRestrict && !this->mConstrainYaw )
    return 0;
  v7 = atan2f(
         COERCE_FLOAT(LODWORD(this->mTargetWorld.v0.y) ^ _xmm[0]),
         COERCE_FLOAT(LODWORD(this->mTargetWorld.v0.x) ^ _xmm[0]));
  v10 = (__m128)LODWORD(v5->mEye.p0.y);
  v8 = 0.0;
  v9 = v5->mEye.p0.x - v5->mLook.p0.x;
  v10.m128_f32[0] = v10.m128_f32[0] - v5->mLook.p0.y;
  v11 = v10;
  v11.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9))
                  + (float)((float)(v5->mEye.p0.z - v5->mLook.p0.z) * (float)(v5->mEye.p0.z - v5->mLook.p0.z));
  if ( v11.m128_f32[0] != 0.0 )
    v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  for ( i = atan2f(v10.m128_f32[0] * v8, v9 * v8) - v7; i > 3.1415927; i = i + -6.2831855 )
    ;
  for ( ; i < -3.1415927; i = i + 6.2831855 )
    ;
  v13 = v5->mConstrainYaw;
  if ( v13 )
    v14 = v5->mConstrainYawMin;
  else
    v14 = (float)(v5->mBlendedParams.mYawMin * 3.1415927) * 0.0055555557;
  if ( v13 )
    v15 = v5->mConstrainYawMax;
  else
    v15 = (float)(v5->mBlendedParams.mYawMax * 3.1415927) * 0.0055555557;
  if ( i <= v15 && i >= v14 )
    return 0;
  for ( j = v15 - i; j > 3.1415927; j = j + -6.2831855 )
    ;
  for ( ; j < -3.1415927; j = j + 6.2831855 )
    ;
  for ( k = v14 - i; k > 3.1415927; k = k + -6.2831855 )
    ;
  for ( ; k < -3.1415927; k = k + 6.2831855 )
    ;
  if ( COERCE_FLOAT(LODWORD(k) & _xmm) >= COERCE_FLOAT(LODWORD(j) & _xmm) )
    *v4 = v15;
  else
    *v4 = v14;
  if ( v5->mConstrainYaw )
    v18 = v5->mConstrainYawRate;
  else
    v18 = (float)(v5->mBlendedParams.mYawConstrainRate * 3.1415927) * 0.0055555557;
  *v3 = v18;
  return 1;
}

// File Line: 4283
// RVA: 0x3C29D0
float __fastcall UFG::FollowCameraComponent::GetClosestAngle(UFG::FollowCameraComponent *this, float angleA, float angleB, bool worldSpace, bool returnFarthestAngle)
{
  bool v5; // di
  UFG::FollowCameraComponent *v6; // rbx
  float v7; // xmm3_4
  __m128 v8; // xmm4
  float v9; // xmm12_4
  float v10; // xmm2_4
  __m128 v11; // xmm5
  float i; // xmm6_4
  float j; // xmm2_4
  float k; // xmm0_4
  float v15; // xmm3_4

  v8 = (__m128)LODWORD(this->mEye.p0.y);
  v5 = worldSpace;
  v6 = this;
  v7 = this->mEye.p0.x - this->mLook.p0.x;
  v8.m128_f32[0] = v8.m128_f32[0] - this->mLook.p0.y;
  v11 = v8;
  v9 = angleB;
  v10 = 0.0;
  v11.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7 * v7))
                  + (float)((float)(this->mEye.p0.z - this->mLook.p0.z) * (float)(this->mEye.p0.z - this->mLook.p0.z));
  if ( v11.m128_f32[0] != 0.0 )
    v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  i = atan2f(v8.m128_f32[0] * v10, v7 * v10);
  if ( !v5 )
  {
    for ( i = i
            - atan2f(
                COERCE_FLOAT(LODWORD(v6->mTargetWorld.v0.y) ^ _xmm[0]),
                COERCE_FLOAT(LODWORD(v6->mTargetWorld.v0.x) ^ _xmm[0])); i > 3.1415927; i = i + -6.2831855 )
      ;
    for ( ; i < -3.1415927; i = i + 6.2831855 )
      ;
  }
  for ( j = angleA - i; j > 3.1415927; j = j + -6.2831855 )
    ;
  for ( ; j < -3.1415927; j = j + 6.2831855 )
    ;
  for ( k = v9 - i; k > 3.1415927; k = k + -6.2831855 )
    ;
  for ( ; k < -3.1415927; k = k + 6.2831855 )
    ;
  if ( returnFarthestAngle )
    v15 = v9;
  else
    v15 = angleA;
  if ( COERCE_FLOAT(LODWORD(k) & _xmm) >= COERCE_FLOAT(LODWORD(j) & _xmm) )
    return v15;
  if ( returnFarthestAngle )
    return angleA;
  return v9;
}

// File Line: 4309
// RVA: 0x3C0950
bool __fastcall UFG::FollowCameraComponent::BoomClamp(UFG::FollowCameraComponent *this, UFG::qVector3 *boom)
{
  UFG::qVector3 *v2; // rdi
  UFG::FollowCameraComponent *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm2_4
  float radius_down; // xmm7_4
  bool result; // al

  v2 = boom;
  v3 = this;
  v4 = this->mBlendedParams.mTweakRadiusMin;
  v5 = (float)((float)(1.0 - this->mMaxRadiusOverrideParam) * this->mBlendedParams.mTweakRadiusMax)
     + (float)(this->mMaxRadiusOverrideParam * this->mMaxRadiusOverride);
  if ( v4 > v5 )
    v4 = (float)((float)(1.0 - this->mMaxRadiusOverrideParam) * this->mBlendedParams.mTweakRadiusMax)
       + (float)(this->mMaxRadiusOverrideParam * this->mMaxRadiusOverride);
  radius_down = v4 * this->mOrbitSquish;
  result = UFG::FollowCameraComponent::BoomClamp(this, boom, v5, v4, v4 * this->mOrbitSquish, 0);
  if ( !result )
    result = UFG::FollowCameraComponent::BoomClamp(v3, v2, v4, v4, radius_down, 1);
  return result;
}

// File Line: 4325
// RVA: 0x3C0A00
_BOOL8 __fastcall UFG::FollowCameraComponent::BoomClamp(UFG::FollowCameraComponent *this, UFG::qVector3 *boom_in, float radius, float radius_up, float radius_down, bool keep_out)
{
  __int128 v6; // xmm5
  UFG::qVector3 *v7; // rdi
  __m128 v8; // xmm10
  float v9; // xmm11_4
  float v10; // xmm9_4
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
  float v24; // xmm1_4
  float v25; // xmm0_4
  UFG::qVector3 ray; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 boom; // [rsp+40h] [rbp-98h]
  UFG::qVector3 result; // [rsp+50h] [rbp-88h]

  v6 = LODWORD(boom_in->z);
  v7 = boom_in;
  v8 = (__m128)LODWORD(boom_in->x);
  v9 = boom_in->y;
  boom.x = boom_in->x;
  boom.y = v9;
  v10 = radius;
  v11 = (float)(1.0 / radius) * radius_down;
  v12 = (float)(1.0 / radius) * radius_up;
  if ( *(float *)&v6 >= 0.0 )
    v13 = (float)(1.0 / radius) * radius_up;
  else
    v13 = (float)(1.0 / radius) * radius_down;
  *(float *)&v6 = *(float *)&v6 / v13;
  v14 = v8;
  v14.m128_f32[0] = v8.m128_f32[0] * v8.m128_f32[0];
  v15 = (__m128)v6;
  LODWORD(boom.z) = v6;
  v15.m128_f32[0] = (float)(*(float *)&v6 * *(float *)&v6)
                  + (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v9 * v9));
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v15);
  if ( keep_out )
  {
    v17 = v10 < v16;
    v18 = v10 == v16;
  }
  else
  {
    v17 = v16 < v10;
    v18 = v16 == v10;
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
        - *(float *)&v6;
    if ( keep_out )
    {
      v14.m128_f32[0] = v14.m128_f32[0] + (float)(v9 * v9);
      v22 = COERCE_FLOAT(_mm_sqrt_ps(v14)) * 0.5;
      if ( v21 <= COERCE_FLOAT(LODWORD(v22) ^ _xmm[0]) )
        LODWORD(v21) = LODWORD(v22) ^ _xmm[0];
      if ( v21 >= v22 )
        v21 = v22;
    }
    ray.z = v21;
    ray.x = v8.m128_f32[0] * v20;
    ray.y = v9 * v20;
    v23 = UFG::FollowCameraComponent::BoomClamp(this, &result, &boom, v10, &ray);
    v24 = v23->z;
    v25 = v23->y;
    v7->x = v23->x;
    v7->y = v25;
    v7->z = v24;
    if ( v24 >= 0.0 )
      v11 = v12;
    v7->z = v11 * v24;
  }
  return v19;
}

// File Line: 4359
// RVA: 0x3C07C0
UFG::qVector3 *__fastcall UFG::FollowCameraComponent::BoomClamp(UFG::FollowCameraComponent *this, UFG::qVector3 *result, UFG::qVector3 *boom, float radius, UFG::qVector3 *ray)
{
  float v5; // xmm4_4
  __m128 v6; // xmm2
  float v7; // xmm5_4
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

  v5 = boom->y;
  v6 = (__m128)LODWORD(boom->x);
  v7 = boom->z;
  v8 = ray->y;
  v9 = ray->z;
  v11 = (__m128)LODWORD(boom->x);
  v12 = v6;
  v10 = (float)((float)(ray->x * ray->x) + (float)(v8 * v8)) + (float)(v9 * v9);
  v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] * ray->x) + (float)(boom->y * v8)) + (float)(boom->z * v9);
  v13 = v11;
  v12.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  v13.m128_f32[0] = (float)(v11.m128_f32[0] * v11.m128_f32[0])
                  - (float)((float)(v12.m128_f32[0] - (float)(radius * radius)) * v10);
  if ( v13.m128_f32[0] < 0.0 || v10 < 0.0000099999997 )
  {
    v19 = radius / COERCE_FLOAT(_mm_sqrt_ps(v12));
    v16 = v6.m128_f32[0] * v19;
    v17 = v5 * v19;
    v18 = v7 * v19;
  }
  else
  {
    if ( v12.m128_f32[0] > (float)(radius * radius) )
      v14 = FLOAT_N1_0;
    else
      v14 = *(float *)&FLOAT_1_0;
    v15 = (float)((float)(COERCE_FLOAT(_mm_sqrt_ps(v13)) * v14) - v11.m128_f32[0]) / v10;
    v16 = v6.m128_f32[0] + (float)(ray->x * v15);
    v17 = v5 + (float)(v8 * v15);
    v18 = v7 + (float)(v9 * v15);
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
  UFG::FollowCameraComponent *v1; // r14
  UFG::NearbyCharacterManager *v2; // rbx
  UFG::qVector3 *v3; // rax
  UFG::SimObjectCharacter *v4; // r12
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v5; // rdi
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v6; // r15
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v7; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v8; // rsi
  UFG::TransformNodeComponent *v9; // rax
  UFG::TransformNodeComponent *v10; // rbp
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm8_4
  float *v14; // rax
  UFG::SimComponent *v15; // rax
  UFG::SimObject *v16; // rbx
  UFG::GameStatTracker *v17; // rax
  bool v18; // bl
  unsigned int v19; // eax
  UFG::SimComponent *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::SimComponent *v23; // rax
  bool v24; // al
  UFG::TargetingSystemBaseComponent *v25; // rax
  UFG::SimComponent *v26; // rax
  signed __int64 v27; // rcx
  signed __int64 v28; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *i; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v30; // rdx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v31; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v32; // rax
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v33; // rcx
  UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *v34; // rax
  __int64 v35; // [rsp+0h] [rbp-A8h]
  __int64 v36; // [rsp+20h] [rbp-88h]
  UFG::qList<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList,0,0> list; // [rsp+28h] [rbp-80h]

  v36 = -2i64;
  v1 = this;
  this->mNumMeleeAttackers = 0;
  if ( this->mAutoFrameEnabled )
  {
    list.mNode.mPrev = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)&list;
    v2 = UFG::NearbyCharacterManager::s_pInstance;
    v3 = (UFG::qVector3 *)((__int64 (__cdecl *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
    UFG::NearbyCharacterManager::GetNearbyCharacters(v2, &list, 0, v3);
    v4 = UFG::GetLocalPlayer();
    v5 = list.mNode.mNext - 1;
    v6 = (UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *)(&v35 + 3);
    if ( list.mNode.mNext - 1 != v6 )
    {
      do
      {
        v7 = v5[3].mPrev;
        if ( v7 )
        {
          if ( ((unsigned __int8 (__cdecl *)(UFG::qNode<UFG::NearbyCharacter,UFG::NearbyCharacterLocalList> *))v7->mPrev[7].mPrev)(v7) )
          {
            v8 = v5[3].mPrev;
            if ( (UFG::SimObjectCharacter *)v8[2].mNext != v4 )
            {
              v9 = (UFG::TransformNodeComponent *)hkMemoryMeshBody::getMeshShape((hkMemoryMeshBody *)v5[3].mPrev);
              v10 = v9;
              if ( v8 )
              {
                if ( v9 )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
                  v11 = v10->mWorldTransform.v3.x;
                  v12 = v10->mWorldTransform.v3.y;
                  v13 = v10->mWorldTransform.v3.z;
                  v14 = (float *)((__int64 (__cdecl *)(UFG::SimComponent *))v1->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(v1->mTarget.m_pSimComponent);
                  if ( (float)((float)((float)((float)(v14[1] - v12) * (float)(v14[1] - v12))
                                     + (float)((float)(*v14 - v11) * (float)(*v14 - v11)))
                             + (float)((float)(v14[2] - v13) * (float)(v14[2] - v13))) <= 900.0 )
                  {
                    v15 = UFG::AIEntityComponent::GetCharacterOccupantComponent((UFG::AIEntityComponent *)v8);
                    if ( !v15 || LODWORD(v15[1].m_SafePointerList.mNode.mNext) != 13 )
                    {
                      v16 = v10->m_pSimObject;
                      v17 = UFG::FactionInterface::Get();
                      if ( (unsigned int)UFG::FactionInterface::GetStanding(
                                           &v17->mFactionInterface,
                                           (UFG::SimObject *)&v4->vfptr,
                                           v16) )
                      {
                        v18 = UFG::g_AIObjectiveParams[SHIDWORD(v8[260].mPrev)].m_IsHostile;
                        v19 = _S13_2;
                        if ( !(_S13_2 & 1) )
                        {
                          _S13_2 |= 1u;
                          hostileNodeId_0.mUID = UFG::qStringHashUpper32("Hostile", 0xFFFFFFFF);
                          v19 = _S13_2;
                        }
                        if ( !(v19 & 2) )
                        {
                          _S13_2 = v19 | 2;
                          mostUsedIndex_hostileNodeId = GetMostUsedIndex(hostileNodeId_0.mUID);
                        }
                        v20 = UFG::ActiveAIEntityComponent::GetAIActionTreeComponent((UFG::ActiveAIEntityComponent *)v8);
                        if ( v20 )
                          ActionController::IsPlaying(
                            (ActionController *)&v20[3].m_TypeUID,
                            &hostileNodeId_0,
                            mostUsedIndex_hostileNodeId,
                            1);
                        v21 = (UFG::SimObjectGame *)v10->m_pSimObject;
                        v24 = 0;
                        if ( v21 )
                        {
                          v22 = v21->m_Flags;
                          if ( (v22 >> 14) & 1 )
                          {
                            v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::HudComponent::_TypeUID);
                          }
                          else if ( (v22 & 0x8000u) == 0 )
                          {
                            if ( (v22 >> 13) & 1 )
                              v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::HudComponent::_TypeUID);
                            else
                              v23 = (v22 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v21,
                                                        UFG::HudComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                         (UFG::SimObject *)&v21->vfptr,
                                                                                         UFG::HudComponent::_TypeUID);
                          }
                          else
                          {
                            v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::HudComponent::_TypeUID);
                          }
                          if ( v23 && HIBYTE(v23[3].m_Flags) )
                            v24 = 1;
                        }
                        if ( v18 || v24 )
                        {
                          v25 = (UFG::TargetingSystemBaseComponent *)UFG::AIEntityComponent::GetTargetingSystemBaseComponent((UFG::AIEntityComponent *)v8);
                          if ( !v25 || !UFG::HasRangedWeaponEquippedWithAmmo(v25) )
                          {
                            v26 = UFG::AIEntityComponent::GetHealthComponent((UFG::AIEntityComponent *)v5[3].mPrev);
                            if ( v26 )
                            {
                              if ( !BYTE4(v26[1].m_BoundComponentHandles.mNode.mPrev) )
                              {
                                v27 = v1->mNumMeleeAttackers;
                                v28 = v27;
                                v1->mNumMeleeAttackers = v27 + 1;
                                v1->mMeleeAttackerPositions[v28].x = v11;
                                v1->mMeleeAttackerPositions[v28].y = v12;
                                v1->mMeleeAttackerPositions[v28].z = v13;
                                if ( v1->mNumMeleeAttackers >= 16 )
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
      v32 = i[1].mNext;
      v31->mNext = v32;
      v32->mPrev = v31;
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
void __fastcall UFG::FollowCameraComponent::SafetyDetectInconsistentCameraMode(UFG::FollowCameraComponent *this, float dt)
{
  UFG::FollowCameraComponent *v2; // rdi
  UFG::SimObjectCharacter *v3; // rbx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  bool v6; // si
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // r14
  __int64 *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::Event *v11; // rbx
  UFG::allocator::free_link *v12; // rax
  UFG::Event *v13; // rdx
  UFG::qNode<UFG::Event,UFG::Event> *v14; // rcx
  UFG::EventVtbl *v15; // rax
  __int64 *v16; // rcx
  __int64 **v17; // rax
  __int64 *v18; // rcx
  __int64 **v19; // rax
  __int64 *v20; // [rsp+28h] [rbp-28h]
  __int64 **v21; // [rsp+30h] [rbp-20h]
  UFG::qNode<UFG::Event,UFG::Event> *v22; // [rsp+38h] [rbp-18h]

  v2 = this;
  if ( dt > 0.0 )
  {
    v3 = LocalPlayer;
    if ( LocalPlayer
      && ((v4 = LocalPlayer->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v5 = LocalPlayer->m_Components.p[44].m_pComponent),
          v5) )
    {
      v6 = LODWORD(v5[1].m_SafePointerList.mNode.mNext) != 13;
    }
    else
    {
      v6 = 0;
    }
    v7 = UFG::GetCurrentGameCamera();
    v8 = v7;
    if ( v7 )
    {
      if ( !UFG::SimComponent::IsType(v7, UFG::FollowCameraComponent::_FollowCameraComponentTypeUID) )
        v6 = 0;
      LOBYTE(v7) = UFG::SimComponent::IsType(v8, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID);
    }
    if ( !v6 || (_BYTE)v7 )
      v2->mTimeShouldBeInVehicleCamButAreNot = 0.0;
    else
      v2->mTimeShouldBeInVehicleCamButAreNot = dt + v2->mTimeShouldBeInVehicleCamButAreNot;
    if ( UFG::FollowCameraComponent::rSafetyMaxInconsistentTime < v2->mTimeShouldBeInVehicleCamButAreNot )
    {
      v20 = (__int64 *)&v20;
      v21 = &v20;
      v22 = (UFG::qNode<UFG::Event,UFG::Event> *)v3;
      if ( v3 )
      {
        v9 = (__int64 *)v3->m_SafePointerList.mNode.mPrev;
        v9[1] = (__int64)&v20;
        v20 = v9;
        v21 = (__int64 **)&v3->m_SafePointerList;
        v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v20;
      }
      v10 = UFG::qMalloc(0x50ui64, "CameraSafetyChangeTask", 0i64);
      v11 = (UFG::Event *)v10;
      if ( v10 )
      {
        v12 = v10 + 1;
        v12->mNext = v12;
        v12[1].mNext = v12;
        v11->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
        v11->m_NamePTR = "EVT_MOUNT_VEHICLE_CAMERA";
        v11->m_EventUID = UFG::qStringHash32("EVT_MOUNT_VEHICLE_CAMERA", 0xFFFFFFFF);
        v11->vfptr = (UFG::EventVtbl *)&UFG::AnimatedEvent::`vftable';
        v13 = v11 + 1;
        v13->vfptr = (UFG::EventVtbl *)v13;
        v13->mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)v13;
        v11[1].mNext = v22;
        if ( v22 )
        {
          v14 = (UFG::qNode<UFG::Event,UFG::Event> *)((char *)v22 + 8);
          v15 = (UFG::EventVtbl *)v22->mNext;
          v15[1].__vecDelDtor = (void *(__fastcall *)(UFG::Event *, unsigned int))v13;
          v13->vfptr = v15;
          v11[1].mPrev = v14;
          v14->mPrev = (UFG::qNode<UFG::Event,UFG::Event> *)v13;
        }
      }
      else
      {
        v11 = 0i64;
      }
      UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, v11);
      v2->mTimeShouldBeInVehicleCamButAreNot = 0.0;
      if ( v22 )
      {
        v16 = v20;
        v17 = v21;
        v20[1] = (__int64)v21;
        *v17 = v16;
        v20 = (__int64 *)&v20;
        v21 = &v20;
      }
      v18 = v20;
      v19 = v21;
      v20[1] = (__int64)v21;
      *v19 = v18;
    }
  }
}

