// File Line: 38
// RVA: 0x3C78E0
void __fastcall NormAngle(float *a)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = *a;
  if ( *a > 3.1415927 )
  {
    do
      v1 = v1 + -6.2831855;
    while ( v1 > 3.1415927 );
    *a = v1;
  }
  v2 = *a;
  if ( *a < -3.1415927 )
  {
    do
      v2 = v2 + 6.2831855;
    while ( v2 < -3.1415927 );
    *a = v2;
  }
}

// File Line: 129
// RVA: 0x3C18A0
UFG::ChaseCameraParameters *__fastcall UFG::DefaultChaseParameters()
{
  return UFG::gChaseParams;
}

// File Line: 134
// RVA: 0x3C2110
UFG::ChaseCameraParameters *__fastcall UFG::FindChaseParameters(UFG::qSymbol *name)
{
  unsigned int v1; // er8
  int v2; // edx
  UFG::qSymbol *v3; // rcx

  v1 = name->mUID;
  v2 = 0;
  v3 = &stru_142073168;
  while ( v1 != v3->mUID )
  {
    ++v2;
    v3 += 80;
    if ( (unsigned __int64)v2 >= 0x48 )
      return UFG::gChaseParams;
  }
  return &UFG::gChaseParams[v2];
}

// File Line: 431
// RVA: 0x14BFF00
__int64 dynamic_initializer_for__UFG::ChaseCameraComponent::s_ChaseCameraComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::ChaseCameraComponent::s_ChaseCameraComponentList__);
}

// File Line: 432
// RVA: 0x14BFBD0
__int64 dynamic_initializer_for__UFG::ChaseCameraComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::ChaseCameraComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::ChaseCameraComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::ChaseCameraComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::ChaseCameraComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 496
// RVA: 0x3BAA40
void __fastcall UFG::ChaseCameraComponent::ChaseCameraComponent(UFG::ChaseCameraComponent *this, unsigned int name_uid)
{
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v2; // rbx
  signed __int64 v3; // rdi
  signed __int64 v4; // rsi
  signed __int64 v5; // r14
  signed __int64 v6; // r15
  signed __int64 v7; // rbp
  signed __int64 v8; // r12
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v9; // rax
  float v10; // xmm0_4
  signed __int64 v11; // rax
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  signed __int64 v15; // rax
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm3_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  __m128 v26; // xmm4
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  int v41; // [rsp+48h] [rbp-80h]
  int v42; // [rsp+4Ch] [rbp-7Ch]
  int v43; // [rsp+50h] [rbp-78h]
  int v44; // [rsp+58h] [rbp-70h]
  int v45; // [rsp+5Ch] [rbp-6Ch]
  int v46; // [rsp+60h] [rbp-68h]
  UFG::ChaseCameraComponent *v47; // [rsp+D0h] [rbp+8h]
  UFG::qAverageWindow<float> *v48; // [rsp+E0h] [rbp+18h]

  v47 = this;
  UFG::GameCameraComponent::GameCameraComponent((UFG::GameCameraComponent *)&this->vfptr, name_uid);
  v2 = (UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *)&v47->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v47->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ChaseCameraComponent::`vftable;
  v3 = (signed __int64)&v47->mUp;
  *(_DWORD *)v3 = 1008981770;
  *(_DWORD *)(v3 + 4) = 1008981770;
  *(_DWORD *)(v3 + 8) = 1008981770;
  v4 = (signed __int64)&v47->mFov;
  *(_DWORD *)v4 = 1008981770;
  v5 = (signed __int64)&v47->mEye;
  *(_DWORD *)v5 = 1008981770;
  *(_DWORD *)(v5 + 4) = 1008981770;
  *(_DWORD *)(v5 + 8) = 1008981770;
  v6 = (signed __int64)&v47->mLook;
  *(_DWORD *)v6 = 1008981770;
  *(_DWORD *)(v6 + 4) = 1008981770;
  *(_DWORD *)(v6 + 8) = 1008981770;
  v7 = (signed __int64)&v47->mAimEye;
  *(_DWORD *)v7 = 1008981770;
  *(_DWORD *)(v7 + 4) = 1008981770;
  *(_DWORD *)(v7 + 8) = 1008981770;
  v8 = (signed __int64)&v47->mAimLook;
  *(_DWORD *)v8 = 1008981770;
  *(_DWORD *)(v8 + 4) = 1008981770;
  *(_DWORD *)(v8 + 8) = 1008981770;
  v47->mDutch.mHomerCubic.mDuration = 0.0099999998;
  v47->mTargetPitch.mDuration = 0.0099999998;
  v47->mRecoilEye.mDuration.x = 0.0099999998;
  v47->mRecoilEye.mDuration.y = 0.0099999998;
  v47->mRecoilEye.mDuration.z = 0.0099999998;
  v47->mYawAngVelWindowMaxTimespan = 2.0;
  v48 = &v47->mYawAngVelWindow;
  *(_QWORD *)&v48->m_MaxTimespan = 0i64;
  v48->m_BufferSize = 0;
  *(_OWORD *)&v48->m_pMemoryPool = 0ui64;
  *(_QWORD *)&v48->m_StartIndex = 0i64;
  v48->m_RunningSumTime = 0.0;
  UFG::qMemSet(&v47->mYawAngVelWindow.m_RunningSum, 0, 4u);
  UFG::qAverageWindow<float>::SetMaxTimespan(&v47->mYawAngVelWindow, 2.0, 30.0);
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::qNoise<UFG::qVector3,UFG::qVector3>(&v47->mEyeNoise);
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::qNoise<UFG::qVector3,UFG::qVector3>(&v47->mLookNoise);
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>(&v47->mTarget);
  Render::DepthOfField::Focus::Focus(&v47->mDofParameters);
  v47->mPreviousParameters.mNameSymbol.mUID = -1;
  v9 = UFG::ChaseCameraComponent::s_ChaseCameraComponentList.mNode.mPrev;
  UFG::ChaseCameraComponent::s_ChaseCameraComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *)&v47->mPrev;
  v2->mPrev = v9;
  v2->mNext = (UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *)&UFG::ChaseCameraComponent::s_ChaseCameraComponentList;
  UFG::ChaseCameraComponent::s_ChaseCameraComponentList.mNode.mPrev = (UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *)&v47->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v47->vfptr,
    UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID,
    "ChaseCameraComponent");
  *(_DWORD *)v3 = 1060320051;
  *(_DWORD *)(v3 + 4) = 1060320051;
  *(_QWORD *)(v3 + 8) = 1060320051i64;
  *(_QWORD *)(v3 + 16) = 0i64;
  *(_QWORD *)(v3 + 96) = 0i64;
  *(_QWORD *)(v3 + 104) = 0i64;
  *(_QWORD *)(v3 + 112) = 0i64;
  *(_QWORD *)(v3 + 72) = 0i64;
  *(_QWORD *)(v3 + 80) = 1065353216i64;
  *(_DWORD *)(v3 + 88) = 0;
  *(_DWORD *)(v3 + 92) = 1065353216;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v47->mUp);
  *(_QWORD *)v4 = 1060320051i64;
  *(_QWORD *)(v4 + 32) = 0i64;
  *(_DWORD *)(v4 + 24) = 1120403456;
  *(_DWORD *)(v4 + 28) = 1120403456;
  UFG::HomerCubic<float>::MakeCoeffs(&v47->mFov);
  *(_DWORD *)v5 = 1060320051;
  *(_DWORD *)(v5 + 4) = 1060320051;
  *(_QWORD *)(v5 + 8) = 1060320051i64;
  *(_QWORD *)(v5 + 16) = 0i64;
  *(_QWORD *)(v5 + 96) = 0i64;
  *(_QWORD *)(v5 + 104) = 0i64;
  *(_QWORD *)(v5 + 112) = 0i64;
  *(_DWORD *)(v5 + 72) = -1063256064;
  *(_DWORD *)(v5 + 76) = 0;
  *(_DWORD *)(v5 + 80) = 0x40000000;
  *(_DWORD *)(v5 + 84) = -1063256064;
  *(_DWORD *)(v5 + 88) = 0;
  *(_DWORD *)(v5 + 92) = 0x40000000;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v47->mEye);
  *(_DWORD *)v6 = 1060320051;
  *(_DWORD *)(v6 + 4) = 1060320051;
  *(_QWORD *)(v6 + 8) = 1060320051i64;
  *(_QWORD *)(v6 + 16) = 0i64;
  *(_QWORD *)(v6 + 96) = 0i64;
  *(_QWORD *)(v6 + 104) = 0i64;
  *(_QWORD *)(v6 + 112) = 0i64;
  *(_QWORD *)(v6 + 72) = 0i64;
  *(_QWORD *)(v6 + 80) = 0i64;
  *(_QWORD *)(v6 + 88) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v47->mLook);
  *(_DWORD *)v7 = 1060320051;
  *(_DWORD *)(v7 + 4) = 1060320051;
  *(_QWORD *)(v7 + 8) = 1060320051i64;
  *(_QWORD *)(v7 + 16) = 0i64;
  *(_QWORD *)(v7 + 96) = 0i64;
  *(_QWORD *)(v7 + 104) = 0i64;
  *(_QWORD *)(v7 + 112) = 0i64;
  *(_DWORD *)(v7 + 72) = -1063256064;
  *(_DWORD *)(v7 + 76) = 0;
  *(_DWORD *)(v7 + 80) = 0x40000000;
  *(_DWORD *)(v7 + 84) = -1063256064;
  *(_DWORD *)(v7 + 88) = 0;
  *(_DWORD *)(v7 + 92) = 0x40000000;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v47->mAimEye);
  *(_DWORD *)v8 = 1060320051;
  *(_DWORD *)(v8 + 4) = 1060320051;
  *(_QWORD *)(v8 + 8) = 1060320051i64;
  *(_QWORD *)(v8 + 16) = 0i64;
  *(_QWORD *)(v8 + 96) = 0i64;
  *(_QWORD *)(v8 + 104) = 0i64;
  *(_QWORD *)(v8 + 112) = 0i64;
  *(_QWORD *)(v8 + 72) = 0i64;
  *(_QWORD *)(v8 + 80) = 0i64;
  *(_QWORD *)(v8 + 88) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v47->mAimLook);
  *(_QWORD *)&v47->mForwardAngle = 0i64;
  UFG::HomerCubicAngular::Init(&v47->mDutch, 0.0, 0.0, 0.0, 0.0, 0.30000001, 6.2831855);
  v10 = UFG::ChaseCameraComponent::mTargetPitchDuration;
  if ( UFG::ChaseCameraComponent::mTargetPitchDuration <= 0.0099999998 )
    v10 = FLOAT_0_0099999998;
  v11 = (signed __int64)&v47->mTargetPitch;
  *(float *)v11 = v10;
  *(_DWORD *)(v11 + 4) = 0;
  *(_QWORD *)(v11 + 32) = 0i64;
  *(_QWORD *)(v11 + 24) = 0i64;
  UFG::HomerCubic<float>::MakeCoeffs(&v47->mTargetPitch);
  *(_QWORD *)&v47->mRecoilAngle = 0i64;
  v12 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v13 = FLOAT_0_0099999998;
  else
    v13 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v14 = FLOAT_0_0099999998;
  else
    v14 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v12 = FLOAT_0_0099999998;
  v15 = (signed __int64)&v47->mRecoilEye;
  *(float *)v15 = v12;
  *(float *)(v15 + 4) = v14;
  *(float *)(v15 + 8) = v13;
  *(_QWORD *)(v15 + 12) = 0i64;
  *(_DWORD *)(v15 + 20) = 0;
  v16 = UFG::qVector3::msZero.y;
  v17 = UFG::qVector3::msZero.z;
  *(float *)(v15 + 96) = UFG::qVector3::msZero.x;
  *(float *)(v15 + 100) = v16;
  *(float *)(v15 + 104) = v17;
  v18 = UFG::qVector3::msZero.y;
  v19 = UFG::qVector3::msZero.z;
  *(float *)(v15 + 108) = UFG::qVector3::msZero.x;
  *(float *)(v15 + 112) = v18;
  *(float *)(v15 + 116) = v19;
  v20 = UFG::qVector3::msZero.y;
  v21 = UFG::qVector3::msZero.z;
  *(float *)(v15 + 72) = UFG::qVector3::msZero.x;
  *(float *)(v15 + 76) = v20;
  *(float *)(v15 + 80) = v21;
  v22 = UFG::qVector3::msZero.y;
  v23 = UFG::qVector3::msZero.z;
  *(float *)(v15 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v15 + 88) = v22;
  *(float *)(v15 + 92) = v23;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v47->mRecoilEye);
  UFG::qAverageWindow<float>::SetTimespan(&v47->mYawAngVelWindow, v47->mYawAngVelWindowMaxTimespan, 30.0);
  v47->mYawAngVelSubmittedTimespan = v47->mYawAngVelWindowMaxTimespan;
  v41 = 1036831949;
  v42 = 1036831949;
  v43 = 1036831949;
  v44 = -1110651699;
  v45 = -1110651699;
  v46 = -1110651699;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&v47->mEyeNoise, (UFG::qVector3 *)&v44, (UFG::qVector3 *)&v41);
  v44 = 1045220557;
  v45 = 1045220557;
  v46 = 1045220557;
  v41 = -1102263091;
  v42 = -1102263091;
  v43 = -1102263091;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&v47->mLookNoise, (UFG::qVector3 *)&v41, (UFG::qVector3 *)&v44);
  v47->mFovRamp.x = 0.0;
  v47->mFovRamp.y = 1.0;
  v47->mFovRamp.z = 100.0;
  v47->mFovRamp.w = 100.0;
  v47->mVelocityBlendRamp.x = 0.0;
  *(_QWORD *)&v47->mVelocityBlendRamp.y = 1065353216i64;
  *(_QWORD *)&v47->mVelocityBlendRamp.w = 0i64;
  *(_QWORD *)&v47->mNoiseMagnitudeRamp.y = 1065353216i64;
  v47->mNoiseMagnitudeRamp.w = 0.0;
  v47->mSafeRadius = 0.0;
  *(_DWORD *)&v47->mAllowDesaturation = 16777473;
  v47->mAimOrFocus = 0;
  v24 = UFG::qVector3::msZero.y;
  v25 = UFG::qVector3::msZero.z;
  v47->mFocusPos.x = UFG::qVector3::msZero.x;
  v47->mFocusPos.y = v24;
  v47->mFocusPos.z = v25;
  v47->mTargetingSystem = 0i64;
  v47->pChaseParameters = 0i64;
  UFG::ChaseCameraComponent::SetChaseParameters(v47, UFG::gChaseParams);
  UFG::ChaseCameraParameters::operator=(&v47->mPreviousParameters, UFG::gChaseParams);
  *(_QWORD *)&v47->mShakeVector.x = 0i64;
  *(_QWORD *)&v47->mShakeVector.z = 0i64;
  v47->mIsLookingAround = 0;
  *(_QWORD *)&v47->mLookaroundAngle = 0i64;
  *(_QWORD *)&v47->mLookaroundJoyInput = 0i64;
  *(_QWORD *)&v47->mLookupMouse = 0i64;
  v26 = 0i64;
  v27 = 0i64;
  v27.m128_f32[0] = (float)1;
  v47->mEyeWorld.v0 = (UFG::qVector4)v27;
  v47->mEyeWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v27, v27, 81);
  v47->mEyeWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v27, v27, 69);
  v47->mEyeWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v27, v27, 21);
  v28 = 0i64;
  v28.m128_f32[0] = (float)1;
  v47->mWorldEye.v0 = (UFG::qVector4)v28;
  v47->mWorldEye.v1 = (UFG::qVector4)_mm_shuffle_ps(v28, v28, 81);
  v47->mWorldEye.v2 = (UFG::qVector4)_mm_shuffle_ps(v28, v28, 69);
  v47->mWorldEye.v3 = (UFG::qVector4)_mm_shuffle_ps(v28, v28, 21);
  v26.m128_f32[0] = (float)1;
  v47->mTargetWorld.v0 = (UFG::qVector4)v26;
  v47->mTargetWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v26, v26, 81);
  v47->mTargetWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v26, v26, 69);
  v47->mTargetWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v26, v26, 21);
  v47->mLookingBack = 0;
  v47->mLookbackCorrectionAngle = 0.0;
  v47->mMotionblurMagnitude = 0.15000001;
  v47->mDesaturation = 0.0;
  v47->mOrbitLatitudeMin = -0.053410001;
  *(_QWORD *)&v47->mOrbitLatitudeMax = 1048576000i64;
  v47->mInAirEyeZOffset = -2.0;
  v47->mInAirLookZOffset = -1.3;
  *(_QWORD *)&v47->mTransitionParamEye = 0i64;
  v29 = UFG::qVector3::msZero.y;
  v30 = UFG::qVector3::msZero.z;
  v47->mTransitionFromEye.x = UFG::qVector3::msZero.x;
  v47->mTransitionFromEye.y = v29;
  v47->mTransitionFromEye.z = v30;
  v31 = UFG::qQuaternion::msUnity.y;
  v32 = UFG::qQuaternion::msUnity.z;
  v28.m128_i32[0] = LODWORD(UFG::qQuaternion::msUnity.w);
  v47->mTransitionFromOri.x = UFG::qQuaternion::msUnity.x;
  v47->mTransitionFromOri.y = v31;
  v47->mTransitionFromOri.z = v32;
  LODWORD(v47->mTransitionFromOri.w) = v28.m128_i32[0];
  v47->mTransitionFromLen = 0.0;
  v47->mDofParameters.mFocalDistance = 5.0;
  v47->mDofParameters.mInFocusRange = 100.0;
  *(_QWORD *)&v47->mDofParameters.mNearRange = 1084227584i64;
  *(_QWORD *)&v47->mDofParameters.mFarRange = 1084227584i64;
  *(_WORD *)&v47->mLockEye = 0;
  v33 = UFG::qVector3::msZero.y;
  v34 = UFG::qVector3::msZero.z;
  v47->mLockEyeVel.x = UFG::qVector3::msZero.x;
  v47->mLockEyeVel.y = v33;
  v47->mLockEyeVel.z = v34;
  v35 = UFG::qVector3::msZero.y;
  v36 = UFG::qVector3::msZero.z;
  v47->mLockLookVel.x = UFG::qVector3::msZero.x;
  v47->mLockLookVel.y = v35;
  v47->mLockLookVel.z = v36;
  v37 = UFG::qVector3::msZero.y;
  v38 = UFG::qVector3::msZero.z;
  v47->mLockEyePos.x = UFG::qVector3::msZero.x;
  v47->mLockEyePos.y = v37;
  v47->mLockEyePos.z = v38;
  v39 = UFG::qVector3::msZero.y;
  v40 = UFG::qVector3::msZero.z;
  v47->mLockLookPos.x = UFG::qVector3::msZero.x;
  v47->mLockLookPos.y = v39;
  v47->mLockLookPos.z = v40;
  *(_QWORD *)&v47->mLockEyeParam = 0i64;
  *(_QWORD *)&v47->mAimParam = 0i64;
  *(_QWORD *)&v47->mBlendPrevious = 0i64;
  ++UFG::ChaseCameraComponent::mNumChaseCameraInstances;
}

// File Line: 755
// RVA: 0x3BDC70
void __fastcall UFG::ChaseCameraComponent::~ChaseCameraComponent(UFG::ChaseCameraComponent *this)
{
  UFG::ChaseCameraComponent *v1; // rbx
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v2; // rdi
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v3; // rcx
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v4; // rax
  UFG::qMemoryPool *v5; // rcx
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v6; // rcx
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v7; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ChaseCameraComponent::`vftable;
  --UFG::ChaseCameraComponent::mNumChaseCameraInstances;
  if ( this == UFG::ChaseCameraComponent::s_ChaseCameraComponentpCurrentIterator )
    UFG::ChaseCameraComponent::s_ChaseCameraComponentpCurrentIterator = (UFG::ChaseCameraComponent *)&this->mPrev[-78];
  v2 = (UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mTarget);
  v5 = v1->mYawAngVelWindow.m_pMemoryPool;
  if ( v5 )
    UFG::qMemoryPool::Free(v5, v1->mYawAngVelWindow.m_pBuffer);
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::GameCameraComponent::~GameCameraComponent((UFG::GameCameraComponent *)&v1->vfptr);
}

// File Line: 875
// RVA: 0x3C5540
bool __fastcall UFG::ChaseCameraComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(pSceneObj, (UFG::qSymbol *)&SimSymX_propset_componentChaseCamera.mUID);
}

// File Line: 881
// RVA: 0x3C80A0
UFG::SimComponent *__fastcall UFG::ChaseCameraComponent::PropertiesOnActivate(UFG::SceneObjectProperties *scene_object_properties)
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
  v4 = UFG::qMemoryPool::Allocate(v3, 0xD60ui64, "ChaseCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::ChaseCameraComponent::ChaseCameraComponent((UFG::ChaseCameraComponent *)v4, v2);
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

// File Line: 890
// RVA: 0x3BFD30
void __fastcall UFG::ChaseCameraComponent::BlendParameters(UFG::ChaseCameraComponent *this, UFG::ChaseCameraParameters *dest, UFG::ChaseCameraParameters *a, UFG::ChaseCameraParameters *b, float blend_a)
{
  float v5; // xmm8_4
  float v6; // xmm11_4
  float v7; // xmm10_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm6_4
  float v27; // xmm7_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm11_4
  float v32; // xmm10_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm2_4
  float v42; // xmm6_4
  float v43; // xmm7_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  float v47; // xmm6_4
  float v48; // xmm7_4
  float v49; // xmm0_4
  float v50; // xmm3_4
  float v51; // xmm2_4

  v5 = 1.0 - blend_a;
  v6 = 1.0 - blend_a;
  v7 = blend_a;
  if ( a->mContext == eCHASE_CONTEXT_AIM || b->mContext == eCHASE_CONTEXT_AIM )
  {
    v7 = 0.0;
    v6 = *(float *)&FLOAT_1_0;
  }
  v8 = blend_a * a->mVelocityBlendRamp.y;
  v9 = blend_a * a->mVelocityBlendRamp.x;
  v10 = (float)(blend_a * a->mVelocityBlendRamp.w) + (float)(v5 * b->mVelocityBlendRamp.w);
  v11 = v5 * b->mVelocityBlendRamp.x;
  v12 = v5 * b->mVelocityBlendRamp.y;
  dest->mVelocityBlendRamp.z = (float)(blend_a * a->mVelocityBlendRamp.z) + (float)(v5 * b->mVelocityBlendRamp.z);
  dest->mVelocityBlendRamp.w = v10;
  dest->mVelocityBlendRamp.y = v8 + v12;
  dest->mVelocityBlendRamp.x = v9 + v11;
  v13 = blend_a * a->mNoiseMagnitudeRamp.y;
  v14 = v5 * b->mNoiseMagnitudeRamp.x;
  v15 = (float)(blend_a * a->mNoiseMagnitudeRamp.w) + (float)(v5 * b->mNoiseMagnitudeRamp.w);
  v16 = v5 * b->mNoiseMagnitudeRamp.y;
  v17 = blend_a * a->mNoiseMagnitudeRamp.x;
  dest->mNoiseMagnitudeRamp.z = (float)(blend_a * a->mNoiseMagnitudeRamp.z) + (float)(v5 * b->mNoiseMagnitudeRamp.z);
  dest->mNoiseMagnitudeRamp.w = v15;
  dest->mNoiseMagnitudeRamp.y = v13 + v16;
  dest->mNoiseMagnitudeRamp.x = v17 + v14;
  dest->mNoiseAmplitude = (float)(v5 * b->mNoiseAmplitude) + (float)(blend_a * a->mNoiseAmplitude);
  dest->mNoiseFrequency = (float)(v5 * b->mNoiseFrequency) + (float)(blend_a * a->mNoiseFrequency);
  dest->mNoiseDecay = (float)(v5 * b->mNoiseDecay) + (float)(blend_a * a->mNoiseDecay);
  dest->mYawAngVelTimespan = (float)(v5 * b->mYawAngVelTimespan) + (float)(blend_a * a->mYawAngVelTimespan);
  dest->mLookOffsetMax = (float)(v5 * b->mLookOffsetMax) + (float)(blend_a * a->mLookOffsetMax);
  dest->mLookOffsetAngVelMin = (float)(v5 * b->mLookOffsetAngVelMin) + (float)(blend_a * a->mLookOffsetAngVelMin);
  dest->mLookOffsetAngVelMax = (float)(v5 * b->mLookOffsetAngVelMax) + (float)(blend_a * a->mLookOffsetAngVelMax);
  dest->mPitchOffsetMax = (float)(v5 * b->mPitchOffsetMax) + (float)(blend_a * a->mPitchOffsetMax);
  dest->mPitchOffsetLookFactorUp = (float)(v5 * b->mPitchOffsetLookFactorUp)
                                 + (float)(blend_a * a->mPitchOffsetLookFactorUp);
  dest->mPitchOffsetLookFactorDown = (float)(v5 * b->mPitchOffsetLookFactorDown)
                                   + (float)(blend_a * a->mPitchOffsetLookFactorDown);
  dest->mPitchOffsetEyeFactorUp = (float)(v5 * b->mPitchOffsetEyeFactorUp)
                                + (float)(blend_a * a->mPitchOffsetEyeFactorUp);
  dest->mPitchOffsetEyeFactorDown = (float)(v5 * b->mPitchOffsetEyeFactorDown)
                                  + (float)(blend_a * a->mPitchOffsetEyeFactorDown);
  dest->mAimWobbleRadiusMin = (float)(v5 * b->mAimWobbleRadiusMin) + (float)(blend_a * a->mAimWobbleRadiusMin);
  dest->mAimWobbleRadiusMax = (float)(v5 * b->mAimWobbleRadiusMax) + (float)(blend_a * a->mAimWobbleRadiusMax);
  dest->mAimWobbleRadiusPeriod = (float)(v5 * b->mAimWobbleRadiusPeriod) + (float)(blend_a * a->mAimWobbleRadiusPeriod);
  dest->mAimWobbleFreq = (float)(v5 * b->mAimWobbleFreq) + (float)(blend_a * a->mAimWobbleFreq);
  dest->mAimWobbleAxisWeight = (float)(v5 * b->mAimWobbleAxisWeight) + (float)(blend_a * a->mAimWobbleAxisWeight);
  dest->mAimFreeDuration = (float)(v5 * b->mAimFreeDuration) + (float)(blend_a * a->mAimFreeDuration);
  dest->mAimLockedDuration = (float)(v5 * b->mAimLockedDuration) + (float)(blend_a * a->mAimLockedDuration);
  v18 = v7 * a->mTargetOffsetLo.z;
  v19 = v7 * a->mTargetOffsetLo.w;
  v20 = (float)(v7 * a->mTargetOffsetLo.x) + (float)(v6 * b->mTargetOffsetLo.x);
  v21 = v6 * b->mTargetOffsetLo.z;
  v22 = v6 * b->mTargetOffsetLo.w;
  dest->mTargetOffsetLo.y = (float)(v7 * a->mTargetOffsetLo.y) + (float)(v6 * b->mTargetOffsetLo.y);
  dest->mTargetOffsetLo.x = v20;
  dest->mTargetOffsetLo.z = v18 + v21;
  dest->mTargetOffsetLo.w = v19 + v22;
  v23 = (float)(v7 * a->mTargetOffsetMed.x) + (float)(v6 * b->mTargetOffsetMed.x);
  v24 = v7 * a->mTargetOffsetMed.z;
  v25 = v7 * a->mTargetOffsetMed.w;
  v26 = v6 * b->mTargetOffsetMed.z;
  v27 = v6 * b->mTargetOffsetMed.w;
  dest->mTargetOffsetMed.y = (float)(v7 * a->mTargetOffsetMed.y) + (float)(v6 * b->mTargetOffsetMed.y);
  dest->mTargetOffsetMed.x = v23;
  dest->mTargetOffsetMed.z = v24 + v26;
  dest->mTargetOffsetMed.w = v25 + v27;
  v28 = (float)(v7 * a->mTargetOffsetHi.x) + (float)(v6 * b->mTargetOffsetHi.x);
  v29 = (float)(v7 * a->mTargetOffsetHi.y) + (float)(v6 * b->mTargetOffsetHi.y);
  v30 = (float)(v7 * a->mTargetOffsetHi.z) + (float)(v6 * b->mTargetOffsetHi.z);
  v31 = v6 * b->mTargetOffsetHi.w;
  v32 = v7 * a->mTargetOffsetHi.w;
  dest->mTargetOffsetHi.x = v28;
  dest->mTargetOffsetHi.y = v29;
  dest->mTargetOffsetHi.z = v30;
  dest->mTargetOffsetHi.w = v32 + v31;
  v33 = v5 * b->mEyeOffsetLo.y;
  v34 = v5 * b->mEyeOffsetLo.z;
  v35 = v5 * b->mEyeOffsetLo.w;
  v36 = blend_a * a->mEyeOffsetLo.y;
  v37 = blend_a * a->mEyeOffsetLo.z;
  v38 = blend_a * a->mEyeOffsetLo.w;
  dest->mEyeOffsetLo.x = (float)(blend_a * a->mEyeOffsetLo.x) + (float)(v5 * b->mEyeOffsetLo.x);
  dest->mEyeOffsetLo.y = v36 + v33;
  dest->mEyeOffsetLo.z = v37 + v34;
  dest->mEyeOffsetLo.w = v38 + v35;
  v39 = blend_a * a->mEyeOffsetMed.z;
  v40 = blend_a * a->mEyeOffsetMed.w;
  v41 = (float)(blend_a * a->mEyeOffsetMed.y) + (float)(v5 * b->mEyeOffsetMed.y);
  v42 = v5 * b->mEyeOffsetMed.z;
  v43 = v5 * b->mEyeOffsetMed.w;
  dest->mEyeOffsetMed.x = (float)(blend_a * a->mEyeOffsetMed.x) + (float)(v5 * b->mEyeOffsetMed.x);
  dest->mEyeOffsetMed.y = v41;
  dest->mEyeOffsetMed.z = v39 + v42;
  dest->mEyeOffsetMed.w = v40 + v43;
  v44 = blend_a * a->mEyeOffsetHi.z;
  v45 = blend_a * a->mEyeOffsetHi.w;
  v46 = (float)(blend_a * a->mEyeOffsetHi.y) + (float)(v5 * b->mEyeOffsetHi.y);
  v47 = v5 * b->mEyeOffsetHi.z;
  v48 = v5 * b->mEyeOffsetHi.w;
  dest->mEyeOffsetHi.x = (float)(blend_a * a->mEyeOffsetHi.x) + (float)(v5 * b->mEyeOffsetHi.x);
  dest->mEyeOffsetHi.y = v46;
  dest->mEyeOffsetHi.z = v44 + v47;
  dest->mEyeOffsetHi.w = v45 + v48;
  v49 = (float)(blend_a * a->mFovRamp.w) + (float)(v5 * b->mFovRamp.w);
  v50 = (float)(blend_a * a->mFovRamp.x) + (float)(v5 * b->mFovRamp.x);
  v51 = (float)(blend_a * a->mFovRamp.y) + (float)(v5 * b->mFovRamp.y);
  dest->mFovRamp.z = (float)(blend_a * a->mFovRamp.z) + (float)(v5 * b->mFovRamp.z);
  dest->mFovRamp.w = v49;
  dest->mFovRamp.y = v51;
  dest->mFovRamp.x = v50;
  dest->mCenteringSpeedMin = (float)(v5 * b->mCenteringSpeedMin) + (float)(blend_a * a->mCenteringSpeedMin);
  dest->mCenteringSpeedMax = (float)(v5 * b->mCenteringSpeedMax) + (float)(blend_a * a->mCenteringSpeedMax);
  dest->mReverseSpeed = (float)(v5 * b->mReverseSpeed) + (float)(blend_a * a->mReverseSpeed);
  dest->mDutch = (float)(v5 * b->mDutch) + (float)(blend_a * a->mDutch);
  dest->mLurch = (float)(v5 * b->mLurch) + (float)(blend_a * a->mLurch);
  dest->mTilt = (float)(v5 * b->mTilt) + (float)(blend_a * a->mTilt);
  dest->mOrbitSpeed = (float)(v5 * b->mOrbitSpeed) + (float)(blend_a * a->mOrbitSpeed);
  dest->mMotionblurMagnitude = (float)(v5 * b->mMotionblurMagnitude) + (float)(blend_a * a->mMotionblurMagnitude);
  dest->mDesaturation = (float)(v5 * b->mDesaturation) + (float)(blend_a * a->mDesaturation);
  dest->mOrbitLatitudeMin = (float)(v5 * b->mOrbitLatitudeMin) + (float)(blend_a * a->mOrbitLatitudeMin);
  dest->mOrbitLatitudeMax = (float)(v5 * b->mOrbitLatitudeMax) + (float)(blend_a * a->mOrbitLatitudeMax);
  dest->mOrbitHeightMinOffset = (float)(v5 * b->mOrbitHeightMinOffset) + (float)(blend_a * a->mOrbitHeightMinOffset);
  dest->mInAirEyeZOffset = (float)(v5 * b->mInAirEyeZOffset) + (float)(blend_a * a->mInAirEyeZOffset);
  dest->mInAirLookZOffset = (float)(v5 * b->mInAirLookZOffset) + (float)(blend_a * a->mInAirLookZOffset);
  dest->mDofNearRange = (float)(v5 * b->mDofNearRange) + (float)(blend_a * a->mDofNearRange);
  dest->mDofNearBlur = (float)(v5 * b->mDofNearBlur) + (float)(blend_a * a->mDofNearBlur);
  dest->mDofFarRange = (float)(v5 * b->mDofFarRange) + (float)(blend_a * a->mDofFarRange);
  dest->mDofFarBlur = (float)(v5 * b->mDofFarBlur) + (float)(blend_a * a->mDofFarBlur);
  dest->mDof = (float)(v5 * b->mDof) + (float)(blend_a * a->mDof);
}

// File Line: 965
// RVA: 0x3C2870
float __fastcall UFG::ChaseCameraComponent::GetBlendSeconds(UFG::ChaseCameraComponent *this, UFG::ChaseCameraContext from_context, UFG::ChaseCameraContext to_context)
{
  signed int v3; // ecx
  UFG::ChaseCameraContextBlend *v4; // rax

  v3 = 18;
  v4 = &UFG::gChaseBlends[18];
  while ( from_context != v4->mFromContext || to_context != v4->mToContext )
  {
    --v4;
    --v3;
    if ( (signed __int64)v4 < (signed __int64)UFG::gChaseBlends )
      return 0.0;
  }
  return UFG::gChaseBlends[v3].mBlendSeconds;
}

// File Line: 978
// RVA: 0x3C6C70
void __fastcall UFG::MakeMonotonic(float *data, int num)
{
  signed __int64 v2; // r8
  signed __int64 v3; // r9
  float *v4; // rax
  unsigned __int64 v5; // rdx
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4

  v2 = 1i64;
  v3 = num;
  if ( num > 1i64 )
  {
    if ( num - 1i64 >= 4 )
    {
      v4 = data + 2;
      v5 = ((unsigned __int64)(num - 5i64) >> 2) + 1;
      v2 = 4 * v5 + 1;
      do
      {
        v6 = *(v4 - 1);
        if ( v6 <= (float)(*(v4 - 2) + 0.0099999998) )
          v6 = *(v4 - 2) + 0.0099999998;
        *(v4 - 1) = v6;
        v7 = *v4;
        v8 = v6 + 0.0099999998;
        if ( *v4 <= v8 )
          v7 = v8;
        *v4 = v7;
        v9 = v4[1];
        v10 = v7 + 0.0099999998;
        if ( v9 <= v10 )
          v9 = v10;
        v4[1] = v9;
        v11 = v4[2];
        v12 = v9 + 0.0099999998;
        if ( v11 <= v12 )
          v11 = v12;
        v4[2] = v11;
        v4 += 4;
        --v5;
      }
      while ( v5 );
    }
    for ( ; v2 < v3; ++v2 )
    {
      v13 = data[v2];
      if ( v13 <= (float)(data[v2 - 1] + 0.0099999998) )
        v13 = data[v2 - 1] + 0.0099999998;
      data[v2] = v13;
    }
  }
}

// File Line: 984
// RVA: 0x3C98C0
void __fastcall UFG::ChaseCameraComponent::SetChaseParameters(UFG::ChaseCameraComponent *this, UFG::ChaseCameraParameters *parameters)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  UFG::ChaseCameraComponent *v4; // rbx
  char *v5; // rcx
  UFG::ChaseCameraParameters *v6; // rdi
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector3 *v14; // r12
  UFG::qVector3 *v15; // r13
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float v31; // xmm7_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  signed int v34; // eax
  signed int v35; // er15
  float v36; // xmm1_4
  float v37; // xmm0_4
  int v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  signed int v42; // eax
  float v43; // xmm1_4
  float v44; // xmm0_4
  int v45; // xmm1_4
  bool v46; // zf
  float v47; // eax
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm0_4
  UFG::qVector3 *v51; // rax
  float v52; // xmm0_4
  float v53; // xmm1_4
  UFG::qVector3 *v54; // rax
  float v55; // xmm0_4
  float v56; // xmm1_4
  UFG::LinearGraph<UFG::qVector3> v57; // [rsp+20h] [rbp-50h]
  UFG::qVector3 result; // [rsp+38h] [rbp-38h]

  v2 = parameters->mFovRamp.y;
  v3 = parameters->mFovRamp.z;
  v4 = this;
  v5 = (char *)this->mEyeOffsetDomain;
  v6 = parameters;
  v7 = parameters->mFovRamp.w;
  *((_DWORD *)v5 + 32) = LODWORD(parameters->mFovRamp.x);
  *((float *)v5 + 33) = v2;
  *((float *)v5 + 34) = v3;
  *((float *)v5 + 35) = v7;
  v8 = parameters->mVelocityBlendRamp.y;
  v9 = parameters->mVelocityBlendRamp.z;
  v10 = parameters->mVelocityBlendRamp.w;
  *((_DWORD *)v5 + 24) = LODWORD(parameters->mVelocityBlendRamp.x);
  *((float *)v5 + 25) = v8;
  *((float *)v5 + 26) = v9;
  *((float *)v5 + 27) = v10;
  v11 = parameters->mNoiseMagnitudeRamp.y;
  v12 = parameters->mNoiseMagnitudeRamp.z;
  v13 = parameters->mNoiseMagnitudeRamp.w;
  *((_DWORD *)v5 + 28) = LODWORD(parameters->mNoiseMagnitudeRamp.x);
  *((float *)v5 + 29) = v11;
  *((float *)v5 + 30) = v12;
  *((float *)v5 + 31) = v13;
  *(float *)v5 = parameters->mEyeOffsetLo.w;
  v4->mEyeOffsetDomain[1] = parameters->mEyeOffsetMed.w;
  v4->mEyeOffsetDomain[2] = parameters->mEyeOffsetHi.w;
  v4->mTargetOffsetDomain[0] = parameters->mTargetOffsetLo.w;
  v4->mTargetOffsetDomain[1] = parameters->mTargetOffsetMed.w;
  v4->mTargetOffsetDomain[2] = parameters->mTargetOffsetHi.w;
  UFG::MakeMonotonic((float *)v5, 3);
  UFG::MakeMonotonic(v4->mTargetOffsetDomain, 3);
  v14 = v4->mEyeOffsetRange;
  v15 = v4->mTargetOffsetRange;
  v16 = v6->mEyeOffsetLo.y;
  v17 = v6->mEyeOffsetLo.z;
  v14->x = v6->mEyeOffsetLo.x;
  v14->y = v16;
  v14->z = v17;
  v18 = v6->mEyeOffsetMed.y;
  v19 = v6->mEyeOffsetMed.z;
  v4->mEyeOffsetRange[1].x = v6->mEyeOffsetMed.x;
  v4->mEyeOffsetRange[1].y = v18;
  v4->mEyeOffsetRange[1].z = v19;
  v20 = v6->mEyeOffsetHi.y;
  v21 = v6->mEyeOffsetHi.z;
  v4->mEyeOffsetRange[2].x = v6->mEyeOffsetHi.x;
  v4->mEyeOffsetRange[2].y = v20;
  v4->mEyeOffsetRange[2].z = v21;
  v22 = v6->mTargetOffsetLo.y;
  v23 = v6->mTargetOffsetLo.z;
  v15->x = v6->mTargetOffsetLo.x;
  v15->y = v22;
  v15->z = v23;
  v24 = v6->mTargetOffsetMed.y;
  v25 = v6->mTargetOffsetMed.z;
  v4->mTargetOffsetRange[1].x = v6->mTargetOffsetMed.x;
  v4->mTargetOffsetRange[1].y = v24;
  v4->mTargetOffsetRange[1].z = v25;
  v26 = v6->mTargetOffsetHi.y;
  v27 = v6->mTargetOffsetHi.z;
  v4->mTargetOffsetRange[2].x = v6->mTargetOffsetHi.x;
  v4->mTargetOffsetRange[2].y = v26;
  v4->mTargetOffsetRange[2].z = v27;
  v4->mOrbitSpeed = v6->mOrbitSpeed;
  v4->mCenteringSpeedMin = v6->mCenteringSpeedMin;
  v4->mCenteringSpeedMax = v6->mCenteringSpeedMax;
  v4->mReverseSpeed = v6->mReverseSpeed;
  v4->mLurch = v6->mLurch;
  v4->mTilt = v6->mTilt;
  v4->mYawAngVelTimespan = v6->mYawAngVelTimespan;
  v4->mLookOffsetMax = v6->mLookOffsetMax;
  v4->mLookOffsetAngVelMin = v6->mLookOffsetAngVelMin;
  v4->mLookOffsetAngVelMax = v6->mLookOffsetAngVelMax;
  v4->mPitchOffsetMax = v6->mPitchOffsetMax;
  v4->mPitchOffsetLookFactorUp = v6->mPitchOffsetLookFactorUp;
  v4->mPitchOffsetLookFactorDown = v6->mPitchOffsetLookFactorDown;
  v4->mPitchOffsetEyeFactorUp = v6->mPitchOffsetEyeFactorUp;
  v4->mPitchOffsetEyeFactorDown = v6->mPitchOffsetEyeFactorDown;
  v28 = v6->mNoiseAmplitude;
  *(float *)&v57.nData = v28;
  *((float *)&v57.nData + 1) = v28;
  *(float *)&v57.fDomain = v28;
  LODWORD(result.x) = LODWORD(v28) ^ _xmm[0];
  LODWORD(result.y) = LODWORD(v28) ^ _xmm[0];
  LODWORD(result.z) = LODWORD(v28) ^ _xmm[0];
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&v4->mEyeNoise, &result, (UFG::qVector3 *)&v57);
  result.x = v28;
  result.y = v28;
  result.z = v28;
  v57.nData = LODWORD(v28) ^ _xmm[0];
  *(&v57.nData + 1) = LODWORD(v28) ^ _xmm[0];
  LODWORD(v57.fDomain) = LODWORD(v28) ^ _xmm[0];
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&v4->mLookNoise, (UFG::qVector3 *)&v57, &result);
  v29 = 0.0;
  v30 = v6->mNoiseDecay;
  v31 = *(float *)&FLOAT_1_0;
  if ( v30 <= 0.0 )
  {
    v32 = 0.0;
  }
  else
  {
    v32 = v6->mNoiseDecay;
    if ( v30 >= 1.0 )
      v32 = *(float *)&FLOAT_1_0;
  }
  if ( v30 <= 0.0 )
  {
    v33 = 0.0;
  }
  else
  {
    v33 = v6->mNoiseDecay;
    if ( v30 >= 1.0 )
      v33 = *(float *)&FLOAT_1_0;
  }
  if ( v30 <= 0.0 )
  {
    v30 = 0.0;
  }
  else if ( v30 >= 1.0 )
  {
    v30 = *(float *)&FLOAT_1_0;
  }
  v4->mEyeNoise.tDecay.x = v30;
  v4->mEyeNoise.tDecay.y = v33;
  v4->mEyeNoise.tDecay.z = v32;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&v4->mEyeNoise);
  v34 = v6->mNoiseOctaves;
  v35 = 31;
  if ( v34 <= 1 )
  {
    v34 = 1;
  }
  else if ( v34 >= 31 )
  {
    v34 = 31;
  }
  v4->mEyeNoise.nOctaves = v34;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&v4->mEyeNoise);
  v36 = v4->mEye.p0.y;
  result.x = v4->mEye.p0.x;
  v37 = v4->mEye.p0.z;
  result.y = v36;
  v38 = LODWORD(v6->mNoiseFrequency);
  result.z = v37;
  v57.nData = v38;
  *(&v57.nData + 1) = v38;
  LODWORD(v57.fDomain) = v38;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetFrequency(&v4->mEyeNoise, (UFG::qVector3 *)&v57, &result);
  v39 = v6->mNoiseDecay;
  if ( v39 <= 0.0 )
  {
    v40 = 0.0;
  }
  else
  {
    v40 = v6->mNoiseDecay;
    if ( v39 >= 1.0 )
      v40 = *(float *)&FLOAT_1_0;
  }
  if ( v39 <= 0.0 )
  {
    v41 = 0.0;
  }
  else
  {
    v41 = v6->mNoiseDecay;
    if ( v39 >= 1.0 )
      v41 = *(float *)&FLOAT_1_0;
  }
  if ( v39 <= 0.0 )
  {
    v39 = 0.0;
    goto LABEL_29;
  }
  if ( v39 < 1.0 )
LABEL_29:
    v31 = v39;
  v4->mLookNoise.tDecay.x = v31;
  v4->mLookNoise.tDecay.y = v41;
  v4->mLookNoise.tDecay.z = v40;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&v4->mLookNoise);
  v42 = v6->mNoiseOctaves;
  if ( v42 <= 1 )
  {
    v42 = 1;
    goto LABEL_34;
  }
  if ( v42 < 31 )
LABEL_34:
    v35 = v42;
  v4->mLookNoise.nOctaves = v35;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&v4->mLookNoise);
  v43 = v4->mLook.p0.y;
  result.x = v4->mLook.p0.x;
  v44 = v4->mLook.p0.z;
  result.y = v43;
  v45 = LODWORD(v6->mNoiseFrequency);
  result.z = v44;
  v57.nData = v45;
  *(&v57.nData + 1) = v45;
  LODWORD(v57.fDomain) = v45;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetFrequency(&v4->mLookNoise, (UFG::qVector3 *)&v57, &result);
  v46 = v4->mTarget.m_pSimComponent == 0i64;
  v47 = v6->mAimWobbleRadiusMin;
  v48 = v6->mAimWobbleAxisWeight;
  v49 = v6->mAimWobbleFreq;
  v50 = v6->mAimWobbleRadiusMax;
  v4->rAimWobbleRadiusPeriod = v6->mAimWobbleRadiusPeriod;
  v4->rAimWobbleFreq = v49;
  v4->rAimWobbleRadiusMin = v47;
  v4->rAimWobbleRadiusMax = v50;
  v4->rAimWobbleAxisWeight = v48;
  v4->mAimFreeDuration = v6->mAimFreeDuration;
  v4->mAimLockedDuration = v6->mAimLockedDuration;
  v4->mDesaturation = v6->mDesaturation;
  v4->mMotionblurMagnitude = v6->mMotionblurMagnitude;
  v4->mDofParameters.mNearRange = v6->mDofNearRange;
  v4->mDofParameters.mNearBlurRadius = v6->mDofNearBlur;
  v4->mDofParameters.mFarRange = v6->mDofFarRange;
  v4->mDofParameters.mFarBlurRadius = v6->mDofFarBlur;
  v4->mDofParameters.mInFocusRange = v6->mDof;
  v4->mOrbitLatitudeMin = v6->mOrbitLatitudeMin;
  v4->mOrbitLatitudeMax = v6->mOrbitLatitudeMax;
  v4->mOrbitHeightMinOffset = v6->mOrbitHeightMinOffset;
  v4->mInAirEyeZOffset = v6->mInAirEyeZOffset;
  v4->mInAirLookZOffset = v6->mInAirLookZOffset;
  if ( !v46 )
  {
    ((void (*)(void))v4->mTarget.m_pSimComponent->vfptr[28].__vecDelDtor)();
    v29 = v50;
  }
  if ( UFG::ChaseCameraComponent::bOverrideSpeedInput )
    v29 = UFG::ChaseCameraComponent::mOverrideSpeed;
  v57.nData = 3;
  v57.tRange = v4->mTargetOffsetRange;
  v57.fDomain = v4->mTargetOffsetDomain;
  v51 = UFG::LinearGraph<UFG::qVector3>::GetValue(&v57, &result, v29);
  v52 = v51->y;
  v53 = v51->z;
  v4->mTargetOffset.x = v51->x;
  v4->mTargetOffset.y = v52;
  v4->mTargetOffset.z = v53;
  if ( v4->mUpdateEyeOffset )
  {
    v57.nData = 3;
    v57.tRange = v4->mEyeOffsetRange;
    v57.fDomain = v4->mEyeOffsetDomain;
    v54 = UFG::LinearGraph<UFG::qVector3>::GetValue(&v57, &result, v29);
    v55 = v54->y;
    v56 = v54->z;
    v4->mEyeOffset.x = v54->x;
    v4->mEyeOffset.y = v55;
    v4->mEyeOffset.z = v56;
  }
}

// File Line: 1090
// RVA: 0x3C18B0
void __fastcall UFG::ChaseCameraComponent::DetermineChaseParameters(UFG::ChaseCameraComponent *this)
{
  UFG::ChaseCameraComponent *v1; // rdi
  UFG::SimComponent *v2; // rcx
  UFG::ChaseCameraParameters *v3; // rbx
  UFG::SimObjectCharacter *v4; // rcx
  UFG::SimObject **v5; // rsi
  unsigned __int16 v6; // dx
  UFG::CharacterSubjectComponent *v7; // rax
  UFG::VehicleSubjectComponent *v8; // rcx
  bool v9; // zf
  UFG::VehicleSubjectComponent *v10; // rax
  UFG::TargetingSystemVehicleComponent *v11; // rax
  UFG::ActionHijackProfile *v12; // rax
  UFG::VehicleSubjectComponent *v13; // rbx
  UFG::qVector3 *v14; // rax
  int v15; // er8
  UFG::ChaseCameraParameters *v16; // rsi
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float blend_a; // xmm0_4
  UFG::ChaseCameraComponent *v31; // rcx
  UFG::ChaseCameraParameters *v32; // rdx
  UFG::ChaseCameraParameters dest; // [rsp+30h] [rbp-178h]

  v1 = this;
  v2 = this->mTarget.m_pSimComponent;
  v3 = UFG::gChaseParams;
  if ( v2 )
  {
    v4 = *(UFG::SimObjectCharacter **)&v2[13].m_TypeUID;
    if ( v4 )
    {
      v6 = v4->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v4);
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
        else
        {
          v7 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v4->vfptr,
                                                   UFG::CharacterSubjectComponent::_TypeUID);
        }
      }
      else
      {
        v7 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      }
      v5 = (UFG::SimObject **)v7;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = (UFG::VehicleSubjectComponent *)v1->mTarget.m_pSimComponent;
    if ( v8->bFleeing )
    {
      v3 = v8->pChaseParametersFlee;
    }
    else if ( UFG::VehicleSubjectComponent::IsRacing(v8) )
    {
      v3 = (UFG::ChaseCameraParameters *)v1->mTarget.m_pSimComponent[14].vfptr;
    }
    else
    {
      v9 = ((unsigned __int8 (*)(void))v1->mTarget.m_pSimComponent->vfptr[32].__vecDelDtor)() == 0;
      v10 = (UFG::VehicleSubjectComponent *)v1->mTarget.m_pSimComponent;
      if ( v9 )
        v3 = v10->pChaseParametersPassenger;
      else
        v3 = v10->pChaseParametersDrive;
    }
    if ( v5 && UFG::IsAnyLocalPlayer(v5[5]) )
    {
      v11 = UFG::VehicleSubjectComponent::GetTargetingSystemVehicle((UFG::VehicleSubjectComponent *)v1->mTarget.m_pSimComponent);
      if ( v11 && (v12 = v11->m_pActionHijackProfile) != 0i64 && !v12->m_bCanActionHijackClimb )
      {
        v3 = (UFG::ChaseCameraParameters *)v1->mTarget.m_pSimComponent[15].m_SafePointerList.mNode.mNext;
      }
      else
      {
        v13 = (UFG::VehicleSubjectComponent *)v1->mTarget.m_pSimComponent;
        v14 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimObject **))(*v5)[1].m_SafePointerList.mNode.mPrev)(v5);
        v15 = UFG::VehicleSubjectComponent::GetBoxSide(v13, v14);
        if ( v15 )
        {
          if ( v15 == 1 || v15 == 4 )
          {
            v3 = (UFG::ChaseCameraParameters *)v1->mTarget.m_pSimComponent[15].vfptr;
            v1->mHijackerLeft = v15 == 1;
          }
          else
          {
            v3 = (UFG::ChaseCameraParameters *)v1->mTarget.m_pSimComponent[14].m_BoundComponentHandles.mNode.mNext;
          }
        }
        else
        {
          v3 = (UFG::ChaseCameraParameters *)v1->mTarget.m_pSimComponent[15].m_SafePointerList.mNode.mPrev;
        }
      }
    }
    else if ( v1->mAimOrFocus )
    {
      v1->mSnapNext = 0;
      v3 = (UFG::ChaseCameraParameters *)v1->mTarget.m_pSimComponent[13].m_BoundComponentHandles.mNode.mPrev;
    }
    v16 = v1->pChaseParameters;
    if ( v16 != v3 )
    {
      if ( v1->mSnapNext || !v16 )
      {
        *(_QWORD *)&v1->mBlendPrevious = 0i64;
      }
      else
      {
        v17 = UFG::ChaseCameraComponent::GetBlendSeconds(v1, v16->mContext, v3->mContext);
        v1->mBlendSeconds = v17;
        if ( v17 <= 0.0 )
          v18 = 0.0;
        else
          v18 = *(float *)&FLOAT_1_0;
        v1->mBlendPrevious = v18;
        UFG::ChaseCameraParameters::operator=(&v1->mPreviousParameters, v16);
        v19 = v1->mPreviousParameters.mEyeOffsetLo.w;
        v20 = v1->mLook.p0.y;
        v21 = v1->mLook.p0.z;
        v22 = v1->mEye.p0.x;
        v23 = v1->mEye.p0.y;
        v24 = v1->mEye.p0.z;
        v25 = v1->mLook.p0.x;
        v1->mPreviousParameters.mEyeOffsetLo.x = v22;
        v1->mPreviousParameters.mEyeOffsetLo.y = v23;
        v1->mPreviousParameters.mEyeOffsetLo.z = v24;
        v1->mPreviousParameters.mEyeOffsetLo.w = v19;
        v1->mPreviousParameters.mEyeOffsetMed.w = v1->mPreviousParameters.mEyeOffsetMed.w;
        v1->mPreviousParameters.mEyeOffsetMed.x = v22;
        v1->mPreviousParameters.mEyeOffsetMed.y = v23;
        v1->mPreviousParameters.mEyeOffsetMed.z = v24;
        v26 = v1->mPreviousParameters.mEyeOffsetHi.w;
        v1->mPreviousParameters.mEyeOffsetHi.x = v22;
        v1->mPreviousParameters.mEyeOffsetHi.w = v26;
        v1->mPreviousParameters.mEyeOffsetHi.y = v23;
        v1->mPreviousParameters.mEyeOffsetHi.z = v24;
        v27 = v1->mPreviousParameters.mTargetOffsetLo.w;
        v1->mPreviousParameters.mTargetOffsetLo.y = v20;
        v1->mPreviousParameters.mTargetOffsetLo.z = v21;
        v1->mPreviousParameters.mTargetOffsetLo.w = v27;
        v1->mPreviousParameters.mTargetOffsetLo.x = v25;
        v28 = v1->mPreviousParameters.mTargetOffsetMed.w;
        v1->mPreviousParameters.mTargetOffsetMed.y = v20;
        v1->mPreviousParameters.mTargetOffsetMed.z = v21;
        v1->mPreviousParameters.mTargetOffsetMed.w = v28;
        v1->mPreviousParameters.mTargetOffsetMed.x = v25;
        v29 = v1->mPreviousParameters.mTargetOffsetHi.w;
        v1->mPreviousParameters.mTargetOffsetHi.y = v20;
        v1->mPreviousParameters.mTargetOffsetHi.z = v21;
        v1->mPreviousParameters.mTargetOffsetHi.w = v29;
        v1->mPreviousParameters.mTargetOffsetHi.x = v25;
      }
    }
  }
  blend_a = v1->mBlendPrevious;
  v1->pChaseParameters = v3;
  v31 = v1;
  if ( blend_a <= 0.0 )
  {
    v32 = v3;
  }
  else
  {
    dest.mNameSymbol.mUID = -1;
    UFG::ChaseCameraComponent::BlendParameters(v1, &dest, &v1->mPreviousParameters, v3, blend_a);
    v32 = &dest;
    v31 = v1;
  }
  UFG::ChaseCameraComponent::SetChaseParameters(v31, v32);
}

// File Line: 1197
// RVA: 0x3C34C0
void __fastcall UFG::ChaseCameraComponent::GetFovRadians(UFG::ChaseCameraComponent *this, float *fov, float *fov_velocity)
{
  *fov_velocity = (float)(this->mFov.v0 * 3.1415927) * 0.0055555557;
  *fov = (float)(this->mFov.p0 * 3.1415927) * 0.0055555557;
}

// File Line: 1203
// RVA: 0x3CC960
void __fastcall UFG::ChaseCameraComponent::SetFovRadians(UFG::ChaseCameraComponent *this, float fov, float fov_velocity)
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

// File Line: 1210
// RVA: 0x3CC4B0
void __fastcall UFG::ChaseCameraComponent::SetEyeWorld(UFG::ChaseCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  UFG::qVector3 *v3; // rdi
  UFG::qVector3 *v4; // rsi
  UFG::ChaseCameraComponent *v5; // rbx
  UFG::qVector3 *v6; // rax
  UFG::HomerCubic<UFG::qVector3> *v7; // rcx
  float v8; // xmm7_4
  float v9; // xmm3_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm10_4
  float v13; // xmm5_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm13_4
  float v20; // xmm10_4
  float v21; // xmm7_4
  float v22; // xmm1_4
  float v23; // xmm7_4
  float v24; // xmm15_4
  float v25; // xmm8_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // [rsp+B0h] [rbp+8h]
  float v29; // [rsp+C0h] [rbp+18h]
  float v30; // [rsp+C8h] [rbp+20h]

  v3 = velocity;
  v4 = position;
  v5 = this;
  if ( this->mTarget.m_pSimComponent )
    v6 = (UFG::qVector3 *)((__int64 (*)(void))this->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)();
  else
    v6 = &UFG::qVector3::msZero;
  v7 = &v5->mEye;
  v8 = v3->x - v6->x;
  v9 = v3->y - v6->y;
  v10 = v5->mWorldEye.v1.y;
  v11 = v3->z - v6->z;
  v12 = v5->mWorldEye.v2.y;
  v13 = v5->mWorldEye.v2.z;
  v29 = (float)((float)((float)(v5->mWorldEye.v0.x * v8) + (float)(v5->mWorldEye.v1.x * v9))
              + (float)(v5->mWorldEye.v2.x * v11))
      + (float)(v5->mWorldEye.v3.x * 0.0);
  v30 = (float)((float)((float)(v5->mWorldEye.v0.y * v8) + (float)(v10 * v9)) + (float)(v12 * v11))
      + (float)(v5->mWorldEye.v3.y * 0.0);
  v14 = v5->mWorldEye.v1.z;
  v15 = v5->mEye.mDuration.x;
  v16 = v5->mEye.mDuration.z;
  v17 = v4->y;
  v28 = (float)((float)((float)((float)(v3->y - v6->y) * v14) + (float)(v5->mWorldEye.v0.z * v8)) + (float)(v11 * v13))
      + (float)(v5->mWorldEye.v3.z * 0.0);
  v18 = v4->z;
  v19 = v5->mWorldEye.v2.x * v18;
  v20 = v12 * v18;
  v21 = (float)((float)(v4->x * v5->mWorldEye.v0.z) + (float)(v17 * v14)) + (float)(v18 * v13);
  v22 = v5->mEye.mDuration.y;
  v23 = v21 + v5->mWorldEye.v3.z;
  v24 = (float)((float)((float)(v5->mWorldEye.v0.x * v4->x) + (float)(v5->mWorldEye.v1.x * v17)) + v19)
      + v5->mWorldEye.v3.x;
  v25 = (float)((float)((float)(v5->mWorldEye.v0.y * v4->x) + (float)(v10 * v17)) + v20) + v5->mWorldEye.v3.y;
  if ( v16 <= 0.0099999998 )
    v16 = FLOAT_0_0099999998;
  if ( v22 <= 0.0099999998 )
    v22 = FLOAT_0_0099999998;
  if ( v15 <= 0.0099999998 )
    v15 = FLOAT_0_0099999998;
  v7->mDuration.x = v15;
  v5->mEye.mDuration.y = v22;
  v5->mEye.mDuration.z = v16;
  *(_QWORD *)&v5->mEye.mParameter.x = 0i64;
  v5->mEye.mParameter.z = 0.0;
  v5->mEye.v0.y = v30;
  v5->mEye.v0.z = v28;
  v5->mEye.v0.x = v29;
  v26 = UFG::qVector3::msZero.y;
  v27 = UFG::qVector3::msZero.z;
  v5->mEye.v1.x = UFG::qVector3::msZero.x;
  v5->mEye.v1.y = v26;
  v5->mEye.v1.z = v27;
  v5->mEye.p0.x = v24;
  v5->mEye.p0.y = v25;
  v5->mEye.p0.z = v23;
  v5->mEye.p1.x = v24;
  v5->mEye.p1.y = v25;
  v5->mEye.p1.z = v23;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(v7);
}

// File Line: 1220
// RVA: 0x3CCC70
void __fastcall UFG::ChaseCameraComponent::SetLookWorld(UFG::ChaseCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  UFG::qVector3 *v3; // rsi
  UFG::qVector3 *v4; // rbp
  UFG::ChaseCameraComponent *v5; // rbx
  UFG::qMatrix44 *v6; // rdi
  UFG::qVector3 *v7; // rax
  signed __int64 v8; // rbx
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm5_4
  float v20; // xmm6_4

  v3 = velocity;
  v4 = position;
  v5 = this;
  if ( this->mTarget.m_pSimComponent )
    v6 = (UFG::qMatrix44 *)((__int64 (*)(void))this->mTarget.m_pSimComponent->vfptr[19].__vecDelDtor)();
  else
    v6 = &UFG::qMatrix44::msIdentity;
  if ( v5->mTarget.m_pSimComponent )
    v7 = (UFG::qVector3 *)((__int64 (*)(void))v5->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)();
  else
    v7 = &UFG::qVector3::msZero;
  v8 = (signed __int64)&v5->mLook;
  v9 = v3->x - v7->x;
  v10 = v3->y - v7->y;
  v11 = v3->z - v7->z;
  v12 = (float)((float)(v9 * v6->v0.x) + (float)(v10 * v6->v1.x)) + (float)(v11 * v6->v2.x);
  v13 = v9 * v6->v0.y;
  v14 = v11 * v6->v2.y;
  v15 = (float)(v9 * v6->v0.z) + (float)(v10 * v6->v1.z);
  v16 = v11 * v6->v2.z;
  v17 = (float)((float)((float)(v10 * v6->v1.y) + v13) + v14) + (float)(v6->v3.y * 0.0);
  v18 = v6->v3.z;
  *(float *)(v8 + 96) = v12 + (float)(v6->v3.x * 0.0);
  *(float *)(v8 + 100) = v17;
  *(float *)(v8 + 104) = (float)(v15 + v16) + (float)(v18 * 0.0);
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs((UFG::HomerCubic<UFG::qVector3> *)v8);
  *(_QWORD *)(v8 + 12) = 0i64;
  *(_DWORD *)(v8 + 20) = 0;
  v19 = (float)((float)((float)(v4->y * v6->v1.x) + (float)(v4->x * v6->v0.x)) + (float)(v4->z * v6->v2.x)) + v6->v3.x;
  v20 = (float)((float)((float)(v4->y * v6->v1.z) + (float)(v4->x * v6->v0.z)) + (float)(v4->z * v6->v2.z)) + v6->v3.z;
  *(float *)(v8 + 76) = (float)((float)((float)(v4->x * v6->v0.y) + (float)(v4->y * v6->v1.y))
                              + (float)(v4->z * v6->v2.y))
                      + v6->v3.y;
  *(float *)(v8 + 72) = v19;
  *(float *)(v8 + 80) = v20;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs((UFG::HomerCubic<UFG::qVector3> *)v8);
  *(_QWORD *)(v8 + 12) = 0i64;
  *(_DWORD *)(v8 + 20) = 0;
}

// File Line: 1228
// RVA: 0x3C3070
void __fastcall UFG::ChaseCameraComponent::GetEyeWorld(UFG::ChaseCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  UFG::qVector3 *v3; // rbx
  UFG::qVector3 *v4; // rdi
  UFG::ChaseCameraComponent *v5; // rsi
  float v6; // xmm3_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v15; // rax
  float *v16; // rax
  float v17; // xmm2_4
  float v18; // xmm1_4
  float *v19; // rax
  float v20; // xmm7_4
  float v21; // xmm5_4
  float v22; // xmm1_4
  float *v23; // rax
  float v24; // xmm6_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm1_4

  v3 = velocity;
  v4 = position;
  v5 = this;
  if ( this->mTarget.m_pSimComponent )
  {
    v6 = this->mEye.p0.y;
    v7 = this->mEye.p0.z;
    v8 = this->mEye.p0.x;
    v9 = (float)((float)((float)(this->mEye.p0.x * this->mEyeWorld.v0.x) + (float)(v6 * this->mEyeWorld.v1.x))
               + (float)(v7 * this->mEyeWorld.v2.x))
       + this->mEyeWorld.v3.x;
    v10 = (float)((float)((float)(v6 * this->mEyeWorld.v1.y) + (float)(v8 * this->mEyeWorld.v0.y))
                + (float)(v7 * this->mEyeWorld.v2.y))
        + this->mEyeWorld.v3.y;
    position->z = (float)((float)((float)(v8 * this->mEyeWorld.v0.z) + (float)(v6 * this->mEyeWorld.v1.z))
                        + (float)(v7 * this->mEyeWorld.v2.z))
                + this->mEyeWorld.v3.z;
    position->x = v9;
    position->y = v10;
    v11 = this->mEye.v0.x;
    v12 = (float)((float)(this->mEye.v0.y * this->mEyeWorld.v1.z) + (float)(v11 * this->mEyeWorld.v0.z))
        + (float)(this->mEye.v0.z * this->mEyeWorld.v2.z);
    v13 = (float)((float)((float)(v11 * this->mEyeWorld.v0.y) + (float)(this->mEye.v0.y * this->mEyeWorld.v1.y))
                + (float)(this->mEye.v0.z * this->mEyeWorld.v2.y))
        + (float)(this->mEyeWorld.v3.y * 0.0);
    v14 = this->mEyeWorld.v3.z;
    velocity->x = (float)((float)((float)(this->mEye.v0.y * this->mEyeWorld.v1.x)
                                + (float)(this->mEye.v0.x * this->mEyeWorld.v0.x))
                        + (float)(this->mEye.v0.z * this->mEyeWorld.v2.x))
                + (float)(this->mEyeWorld.v3.x * 0.0);
    v15 = this->mTarget.m_pSimComponent->vfptr;
    velocity->y = v13;
    velocity->z = v12 + (float)(v14 * 0.0);
    v16 = (float *)((__int64 (*)(void))v15[20].__vecDelDtor)();
    v17 = v16[1] + v3->y;
    v18 = v16[2] + v3->z;
    v3->x = *v16 + v3->x;
    v3->y = v17;
    v3->z = v18;
    v19 = (float *)((__int64 (*)(void))v5->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
    v20 = v4->x - *v19;
    v21 = v4->y - v19[1];
    v22 = v4->z - v19[2];
    v23 = (float *)v5->mTarget.m_pSimComponent;
    v24 = v23[150];
    v25 = v23[148];
    v26 = v23[149] * v20;
    v27 = v23[148] * v22;
    v3->x = (float)((float)(v23[149] * v22) - (float)(v23[150] * v21)) + v3->x;
    v28 = (float)((float)(v25 * v21) - v26) + v3->z;
    v3->y = (float)((float)(v24 * v20) - v27) + v3->y;
    v3->z = v28;
  }
  else
  {
    v29 = UFG::qVector3::msZero.y;
    v30 = UFG::qVector3::msZero.z;
    position->x = UFG::qVector3::msZero.x;
    position->y = v29;
    position->z = v30;
    v31 = UFG::qVector3::msZero.y;
    v32 = UFG::qVector3::msZero.z;
    velocity->x = UFG::qVector3::msZero.x;
    velocity->y = v31;
    velocity->z = v32;
  }
}

// File Line: 1244
// RVA: 0x3C3620
void __fastcall UFG::ChaseCameraComponent::GetLookWorld(UFG::ChaseCameraComponent *this, UFG::qVector3 *position, UFG::qVector3 *velocity)
{
  UFG::qVector3 *v3; // rdi
  UFG::qVector3 *v4; // rsi
  UFG::ChaseCameraComponent *v5; // rbp
  float *v6; // rax
  float v7; // xmm2_4
  float *v8; // rbx
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm8_4
  float *v12; // rax
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm8_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v16; // rax
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm8_4
  float *v20; // rax
  float v21; // xmm6_4
  float v22; // xmm8_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  float v26; // xmm1_4

  v3 = velocity;
  v4 = position;
  v5 = this;
  if ( this->mTarget.m_pSimComponent )
  {
    v6 = (float *)((__int64 (*)(void))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)();
    v7 = v5->mLook.p0.x;
    v8 = v6;
    v9 = (float)((float)(v7 * *v6) + (float)(v5->mLook.p0.y * v6[4])) + (float)(v5->mLook.p0.z * v6[8]);
    v10 = (float)((float)(v5->mLook.p0.x * v6[1]) + (float)(v5->mLook.p0.y * v6[5])) + (float)(v5->mLook.p0.z * v6[9]);
    v11 = (float)((float)(v5->mLook.p0.y * v6[6]) + (float)(v7 * v6[2])) + (float)(v5->mLook.p0.z * v6[10]);
    v12 = (float *)((__int64 (*)(void))v5->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
    v13 = v9 + *v12;
    v14 = v10 + v12[1];
    v15 = v11 + v12[2];
    v16 = v5->mTarget.m_pSimComponent->vfptr;
    v4->x = v13;
    v4->y = v14;
    v4->z = v15;
    v17 = (float)((float)(v5->mLook.v0.x * *v8) + (float)(v5->mLook.v0.y * v8[4])) + (float)(v5->mLook.v0.z * v8[8]);
    v18 = (float)((float)(v5->mLook.v0.y * v8[5]) + (float)(v5->mLook.v0.x * v8[1])) + (float)(v5->mLook.v0.z * v8[9]);
    v19 = (float)((float)(v5->mLook.v0.y * v8[6]) + (float)(v5->mLook.v0.x * v8[2])) + (float)(v5->mLook.v0.z * v8[10]);
    v20 = (float *)((__int64 (*)(void))v16[20].__vecDelDtor)();
    v21 = v18 + v20[1];
    v22 = v19 + v20[2];
    v3->x = v17 + *v20;
    v3->y = v21;
    v3->z = v22;
  }
  else
  {
    v23 = UFG::qVector3::msZero.y;
    v24 = UFG::qVector3::msZero.z;
    position->x = UFG::qVector3::msZero.x;
    position->y = v23;
    position->z = v24;
    v25 = UFG::qVector3::msZero.y;
    v26 = UFG::qVector3::msZero.z;
    velocity->x = UFG::qVector3::msZero.x;
    velocity->y = v25;
    velocity->z = v26;
  }
}

// File Line: 1259
// RVA: 0x3CD9F0
void __fastcall UFG::ChaseCameraComponent::Snap(UFG::ChaseCameraComponent *this)
{
  UFG::HomerCubic<UFG::qVector3> *v1; // rbx
  UFG::ChaseCameraComponent *v2; // rdi
  float v3; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float *v7; // rcx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float *v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float *v17; // rcx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  signed __int64 v22; // rcx
  float v23; // eax
  float *v24; // rcx
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  signed __int64 v28; // rcx
  signed __int64 v29; // rcx
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4

  v1 = &this->mLook;
  v2 = this;
  this->mLookaroundAngle = this->mLookaroundAngleDesired;
  this->mForwardAngle = this->mForwardAngleDesired;
  *(_QWORD *)&this->mBlendPrevious = 0i64;
  v3 = this->mLook.p1.x;
  v4 = this->mLook.p1.z;
  v1->p0.y = this->mLook.p1.y;
  v1->p0.z = v4;
  v1->p0.x = v3;
  v5 = this->mLook.v1.y;
  v6 = this->mLook.v1.z;
  v1->v0.x = this->mLook.v1.x;
  v1->v0.y = v5;
  v1->v0.z = v6;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&v1->mParameter.x = 0i64;
  v1->mParameter.z = 0.0;
  v7 = &v2->mEye.mDuration.x;
  v8 = v2->mEye.p1.y;
  v9 = v2->mEye.p1.z;
  v7[18] = v2->mEye.p1.x;
  v7[19] = v8;
  v7[20] = v9;
  v10 = v2->mEye.v1.y;
  v11 = v2->mEye.v1.z;
  v7[24] = v2->mEye.v1.x;
  v7[25] = v10;
  v7[26] = v11;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mEye);
  *(_QWORD *)&v2->mEye.mParameter.x = 0i64;
  v2->mEye.mParameter.z = 0.0;
  v12 = &v2->mAimLook.mDuration.x;
  v13 = v2->mAimLook.p1.y;
  v14 = v2->mAimLook.p1.z;
  v12[18] = v2->mAimLook.p1.x;
  v12[19] = v13;
  v12[20] = v14;
  v15 = v2->mAimLook.v1.y;
  v16 = v2->mAimLook.v1.z;
  v12[24] = v2->mAimLook.v1.x;
  v12[25] = v15;
  v12[26] = v16;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimLook);
  *(_QWORD *)&v2->mAimLook.mParameter.x = 0i64;
  v2->mAimLook.mParameter.z = 0.0;
  v17 = &v2->mAimEye.mDuration.x;
  v18 = v2->mAimEye.p1.y;
  v19 = v2->mAimEye.p1.z;
  v17[18] = v2->mAimEye.p1.x;
  v17[19] = v18;
  v17[20] = v19;
  v20 = v2->mAimEye.v1.y;
  v21 = v2->mAimEye.v1.z;
  v17[24] = v2->mAimEye.v1.x;
  v17[25] = v20;
  v17[26] = v21;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mAimEye);
  *(_QWORD *)&v2->mAimEye.mParameter.x = 0i64;
  v2->mAimEye.mParameter.z = 0.0;
  v22 = (signed __int64)&v2->mFov;
  *(float *)(v22 + 24) = v2->mFov.p1;
  *(float *)(v22 + 32) = v2->mFov.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&v2->mFov);
  v2->mFov.mParameter = 0.0;
  v23 = v2->mUp.p1.x;
  v24 = &v2->mUp.mDuration.x;
  v25 = v2->mUp.p1.z;
  v24[19] = v2->mUp.p1.y;
  v24[20] = v25;
  v24[18] = v23;
  v26 = v2->mUp.v1.y;
  v27 = v2->mUp.v1.z;
  v24[24] = v2->mUp.v1.x;
  v24[25] = v26;
  v24[26] = v27;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mUp);
  *(_QWORD *)&v2->mUp.mParameter.x = 0i64;
  v2->mUp.mParameter.z = 0.0;
  *(_QWORD *)&v2->mYawAngVelWindow.m_StartIndex = 0i64;
  v2->mYawAngVelWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&v2->mYawAngVelWindow.m_RunningSum, 0, 4u);
  v28 = (signed __int64)&v2->mTargetPitch;
  *(float *)(v28 + 24) = v2->mTargetPitch.p1;
  *(float *)(v28 + 32) = v2->mTargetPitch.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&v2->mTargetPitch);
  v2->mTargetPitch.mParameter = 0.0;
  *(_QWORD *)&v2->mRecoilAngle = 0i64;
  v29 = (signed __int64)&v2->mRecoilEye;
  v30 = UFG::qVector3::msZero.y;
  v31 = UFG::qVector3::msZero.z;
  *(float *)(v29 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v29 + 88) = v30;
  *(float *)(v29 + 92) = v31;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mRecoilEye);
  *(_QWORD *)&v2->mRecoilEye.mParameter.x = 0i64;
  v2->mRecoilEye.mParameter.z = 0.0;
  v32 = v2->mRecoilEye.p1.y;
  v33 = v2->mRecoilEye.p1.z;
  v2->mRecoilEye.p0.x = v2->mRecoilEye.p1.x;
  v2->mRecoilEye.p0.y = v32;
  v2->mRecoilEye.p0.z = v33;
  v34 = v2->mRecoilEye.v1.y;
  v35 = v2->mRecoilEye.v1.z;
  v2->mRecoilEye.v0.x = v2->mRecoilEye.v1.x;
  v2->mRecoilEye.v0.y = v34;
  v2->mRecoilEye.v0.z = v35;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v2->mRecoilEye);
  *(_QWORD *)&v2->mRecoilEye.mParameter.x = 0i64;
  v2->mRecoilEye.mParameter.z = 0.0;
  if ( v2->mLockEye )
    v36 = *(float *)&FLOAT_1_0;
  else
    v36 = 0.0;
  v2->mLockEyeParam = v36;
  if ( v2->mLockLook )
    LODWORD(v2->mLockLookParam) = (_DWORD)FLOAT_1_0;
  else
    v2->mLockLookParam = 0.0;
}

// File Line: 1282
// RVA: 0x3CE090
void __fastcall UFG::ChaseCameraComponent::SnapCurrent(UFG::ChaseCameraComponent *this)
{
  float v1; // eax
  UFG::HomerCubic<UFG::qVector3> *v2; // rbx
  float v3; // eax
  float v4; // xmm1_4
  UFG::ChaseCameraComponent *v5; // rdi
  signed __int64 v6; // rcx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // eax
  signed __int64 v10; // rcx
  float v11; // xmm1_4
  signed __int64 v12; // rcx
  float v13; // xmm0_4
  float v14; // xmm1_4
  signed __int64 v15; // rcx
  float v16; // eax
  signed __int64 v17; // rcx
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // eax
  signed __int64 v21; // rcx
  signed __int64 v22; // rcx
  float v23; // xmm0_4
  float v24; // xmm1_4

  v1 = this->mForwardAngle;
  v2 = &this->mLook;
  *(_QWORD *)&this->mBlendPrevious = 0i64;
  this->mForwardAngleDesired = v1;
  v3 = this->mLook.p0.x;
  v4 = this->mLook.p0.z;
  v2->p1.y = this->mLook.p0.y;
  v2->p1.z = v4;
  v2->p1.x = v3;
  v5 = this;
  *(_QWORD *)&v2->v0.x = 0i64;
  *(_QWORD *)&v2->v0.z = 0i64;
  *(_QWORD *)&v2->v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&v2->mParameter.x = 0i64;
  v2->mParameter.z = 0.0;
  v6 = (signed __int64)&v5->mEye;
  v7 = v5->mEye.p0.y;
  v8 = v5->mEye.p0.z;
  *(float *)(v6 + 84) = v5->mEye.p0.x;
  *(float *)(v6 + 88) = v7;
  *(float *)(v6 + 92) = v8;
  *(_QWORD *)(v6 + 96) = 0i64;
  *(_QWORD *)(v6 + 104) = 0i64;
  *(_QWORD *)(v6 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mEye);
  *(_QWORD *)&v5->mEye.mParameter.x = 0i64;
  v5->mEye.mParameter.z = 0.0;
  v9 = v5->mAimLook.p0.x;
  v10 = (signed __int64)&v5->mAimLook;
  v11 = v5->mAimLook.p0.z;
  *(float *)(v10 + 88) = v5->mAimLook.p0.y;
  *(float *)(v10 + 92) = v11;
  *(float *)(v10 + 84) = v9;
  *(_QWORD *)(v10 + 96) = 0i64;
  *(_QWORD *)(v10 + 104) = 0i64;
  *(_QWORD *)(v10 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mAimLook);
  *(_QWORD *)&v5->mAimLook.mParameter.x = 0i64;
  v5->mAimLook.mParameter.z = 0.0;
  v12 = (signed __int64)&v5->mAimEye;
  v13 = v5->mAimEye.p0.y;
  v14 = v5->mAimEye.p0.z;
  *(float *)(v12 + 84) = v5->mAimEye.p0.x;
  *(float *)(v12 + 88) = v13;
  *(float *)(v12 + 92) = v14;
  *(_QWORD *)(v12 + 96) = 0i64;
  *(_QWORD *)(v12 + 104) = 0i64;
  *(_QWORD *)(v12 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mAimEye);
  *(_QWORD *)&v5->mAimEye.mParameter.x = 0i64;
  v5->mAimEye.mParameter.z = 0.0;
  v15 = (signed __int64)&v5->mFov;
  v16 = v5->mFov.p0;
  *(_QWORD *)(v15 + 32) = 0i64;
  *(float *)(v15 + 28) = v16;
  UFG::HomerCubic<float>::MakeCoeffs(&v5->mFov);
  v5->mFov.mParameter = 0.0;
  v17 = (signed __int64)&v5->mUp;
  v18 = v5->mUp.p0.y;
  v19 = v5->mUp.p0.z;
  *(float *)(v17 + 84) = v5->mUp.p0.x;
  *(float *)(v17 + 88) = v18;
  *(float *)(v17 + 92) = v19;
  *(_QWORD *)(v17 + 96) = 0i64;
  *(_QWORD *)(v17 + 104) = 0i64;
  *(_QWORD *)(v17 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mUp);
  *(_QWORD *)&v5->mUp.mParameter.x = 0i64;
  v5->mUp.mParameter.z = 0.0;
  *(_QWORD *)&v5->mYawAngVelWindow.m_StartIndex = 0i64;
  v5->mYawAngVelWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&v5->mYawAngVelWindow.m_RunningSum, 0, 4u);
  v20 = v5->mTargetPitch.p0;
  v21 = (signed __int64)&v5->mTargetPitch;
  *(_QWORD *)(v21 + 32) = 0i64;
  *(float *)(v21 + 28) = v20;
  UFG::HomerCubic<float>::MakeCoeffs(&v5->mTargetPitch);
  v5->mTargetPitch.mParameter = 0.0;
  v5->mRecoilAngle = v5->mRecoilAngleDesired;
  v22 = (signed __int64)&v5->mRecoilEye;
  v23 = v5->mRecoilEye.p0.y;
  v24 = v5->mRecoilEye.p0.z;
  *(float *)(v22 + 84) = v5->mRecoilEye.p0.x;
  *(float *)(v22 + 88) = v23;
  *(float *)(v22 + 92) = v24;
  *(_QWORD *)(v22 + 96) = 0i64;
  *(_QWORD *)(v22 + 104) = 0i64;
  *(_QWORD *)(v22 + 112) = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v5->mRecoilEye);
  *(_QWORD *)&v5->mRecoilEye.mParameter.x = 0i64;
  v5->mRecoilEye.mParameter.z = 0.0;
}

// File Line: 1300
// RVA: 0x3CD470
void __fastcall UFG::ChaseCameraComponent::SetTarget(UFG::ChaseCameraComponent *this, UFG::SimObject *target)
{
  UFG::SimObject *v2; // rbx
  UFG::ChaseCameraComponent *v3; // rdi
  UFG::VehicleSubjectComponent *v4; // rax
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rcx
  UFG::qVector4 *v7; // rax
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1

  v2 = target;
  v3 = this;
  if ( !this->mTarget.m_pSimComponent || this->mTarget.m_pSimObject != target )
  {
    if ( target )
    {
      v5 = target->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)target,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)target,
                                                 UFG::VehicleSubjectComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)target,
                                                 UFG::VehicleSubjectComponent::_TypeUID);
        }
        else
        {
          v4 = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 target,
                                                 UFG::VehicleSubjectComponent::_TypeUID);
        }
      }
      else
      {
        v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>((UFG::SimObjectVehicle *)target);
      }
    }
    else
    {
      v4 = 0i64;
    }
    UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>::Set(&v3->mTarget, v4);
    v6 = v3->mTarget.m_pSimComponent;
    if ( v6 )
    {
      v7 = (UFG::qVector4 *)((__int64 (*)(void))v6->vfptr[18].__vecDelDtor)();
      v8 = v7[1];
      v9 = v7[2];
      v10 = v7[3];
      v3->mTargetWorld.v0 = *v7;
      v3->mTargetWorld.v1 = v8;
      v3->mTargetWorld.v2 = v9;
      v3->mTargetWorld.v3 = v10;
      v3->pSimObjectPassThru1 = v2;
    }
  }
}

// File Line: 1317
// RVA: 0x3CF730
void __fastcall UFG::ChaseCameraComponent::TransitionTarget(UFG::ChaseCameraComponent *this, UFG::SimObject *target)
{
  UFG::SimObject *v2; // rbx
  UFG::ChaseCameraComponent *v3; // rdi
  char v4; // [rsp+20h] [rbp-48h]
  char v5; // [rsp+30h] [rbp-38h]
  char v6; // [rsp+40h] [rbp-28h]
  char v7; // [rsp+50h] [rbp-18h]
  int v8; // [rsp+70h] [rbp+8h]
  int v9; // [rsp+80h] [rbp+18h]

  v2 = target;
  v3 = this;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, int *, int *))this->vfptr[23].__vecDelDtor)(this, &v9, &v8);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, char *, char *))v3->vfptr[25].__vecDelDtor)(v3, &v5, &v4);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, char *, char *))v3->vfptr[26].__vecDelDtor)(v3, &v7, &v6);
  v3->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, (unsigned int)v2);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v3->vfptr[15].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v3->vfptr[24].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, char *, char *))v3->vfptr[27].__vecDelDtor)(v3, &v5, &v4);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, char *, char *))v3->vfptr[28].__vecDelDtor)(v3, &v7, &v6);
}

// File Line: 1357
// RVA: 0x3C8730
void __fastcall UFG::ChaseCameraComponent::Reset(UFG::ChaseCameraComponent *this)
{
  UFG::ChaseCameraComponent *v1; // rbx
  UFG::SimComponent *v2; // rcx
  UFG::qVector4 *v3; // rax
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1
  float v7; // xmm2_4
  float v8; // xmm0_4
  UFG::SimComponent *v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float *v12; // rax
  float v13; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v14; // rax

  v1 = this;
  *(_QWORD *)&this->mAimParam = 0i64;
  *(_QWORD *)&this->mTransitionParamEye = 0i64;
  v2 = this->mTarget.m_pSimComponent;
  if ( v2 )
  {
    v3 = (UFG::qVector4 *)((__int64 (*)(void))v2->vfptr[18].__vecDelDtor)();
    v4 = v3[1];
    v5 = v3[2];
    v6 = v3[3];
    v1->mTargetWorld.v0 = *v3;
    v1->mTargetWorld.v1 = v4;
    v1->mTargetWorld.v2 = v5;
    v1->mTargetWorld.v3 = v6;
  }
  v1->mAllowCanOccludeCamera = 1;
  v7 = UFG::qVector3::msZero.z;
  v8 = UFG::qVector3::msZero.x;
  v1->mCollisionLookOffset.y = UFG::qVector3::msZero.y;
  v1->mCollisionLookOffset.z = v7;
  v1->mCollisionLookOffset.x = v8;
  UFG::BaseCameraComponent::Reset((UFG::BaseCameraComponent *)&v1->vfptr);
  v1->pChaseParameters = 0i64;
  v1->mUpdateEyeOffset = 1;
  *(_QWORD *)&v1->mBlendPrevious = 0i64;
  v1->mLookingBack = 0;
  v1->mLookbackCorrectionAngle = 0.0;
  if ( v1->mLockEye )
  {
    v1->mLockEyeParam = 1.0;
    v1->mLockEye = 0;
    v1->mUpdateEyeOffset = 1;
  }
  if ( v1->mLockLook )
  {
    v1->mLockLookParam = 1.0;
    v1->mLockLook = 0;
  }
  v9 = v1->mTarget.m_pSimComponent;
  v10 = *(float *)&FLOAT_1_0;
  v11 = 0.0;
  if ( v9 )
  {
    v12 = (float *)((__int64 (*)(void))v9->vfptr[16].__vecDelDtor)();
    v10 = *v12;
    v11 = v12[1];
  }
  v13 = atan2f(v11, v10);
  v14 = v1->vfptr;
  v1->mLookaroundAngleDesired = 0.0;
  v1->mForwardAngleDesired = v13;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v14[31].__vecDelDtor)(v1);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v1->vfptr[15].__vecDelDtor)(v1);
}

// File Line: 1387
// RVA: 0x3C4990
void __fastcall UFG::ChaseCameraComponent::GotoAngleSnap(UFG::ChaseCameraComponent *this, float radians, bool worldSpace)
{
  UFG::ChaseCameraComponent *v3; // rbx
  UFG::SimComponent *v4; // rcx
  float v5; // xmm6_4
  bool v6; // di
  UFG::qVector4 *v7; // rax
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1
  float v11; // xmm2_4
  float v12; // xmm0_4
  UFG::SimComponent *v13; // rcx
  float v14; // xmm1_4
  float v15; // xmm0_4
  float *v16; // rax
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v20; // rax

  v3 = this;
  *(_QWORD *)&this->mAimParam = 0i64;
  *(_QWORD *)&this->mTransitionParamEye = 0i64;
  v4 = this->mTarget.m_pSimComponent;
  v5 = radians;
  v6 = worldSpace;
  if ( v4 )
  {
    v7 = (UFG::qVector4 *)((__int64 (*)(void))v4->vfptr[18].__vecDelDtor)();
    v8 = v7[1];
    v9 = v7[2];
    v10 = v7[3];
    v3->mTargetWorld.v0 = *v7;
    v3->mTargetWorld.v1 = v8;
    v3->mTargetWorld.v2 = v9;
    v3->mTargetWorld.v3 = v10;
  }
  v3->mAllowCanOccludeCamera = 1;
  v11 = UFG::qVector3::msZero.z;
  v12 = UFG::qVector3::msZero.x;
  v3->mCollisionLookOffset.y = UFG::qVector3::msZero.y;
  v3->mCollisionLookOffset.z = v11;
  v3->mCollisionLookOffset.x = v12;
  UFG::BaseCameraComponent::Reset((UFG::BaseCameraComponent *)&v3->vfptr);
  v3->pChaseParameters = 0i64;
  v3->mUpdateEyeOffset = 1;
  *(_QWORD *)&v3->mBlendPrevious = 0i64;
  v3->mLookingBack = 0;
  v3->mLookbackCorrectionAngle = 0.0;
  if ( v3->mLockEye )
  {
    v3->mLockEyeParam = 1.0;
    v3->mLockEye = 0;
    v3->mUpdateEyeOffset = 1;
  }
  if ( v3->mLockLook )
  {
    v3->mLockLookParam = 1.0;
    v3->mLockLook = 0;
  }
  v13 = v3->mTarget.m_pSimComponent;
  v14 = *(float *)&FLOAT_1_0;
  v15 = 0.0;
  if ( v13 )
  {
    v16 = (float *)((__int64 (*)(void))v13->vfptr[16].__vecDelDtor)();
    v14 = *v16;
    v15 = v16[1];
  }
  v17 = atan2f(v15, v14);
  v3->mForwardAngleDesired = v17;
  if ( v6 )
    v18 = (float)(v17 + 3.1415927) - v5;
  else
    LODWORD(v18) = LODWORD(v5) ^ _xmm[0];
  v3->mLookaroundAngleDesired = v18;
  if ( v18 > 3.1415927 )
  {
    do
      v18 = v18 + -6.2831855;
    while ( v18 > 3.1415927 );
    v3->mLookaroundAngleDesired = v18;
  }
  v19 = v3->mLookaroundAngleDesired;
  if ( v19 < -3.1415927 )
  {
    do
      v19 = v19 + 6.2831855;
    while ( v19 < -3.1415927 );
    v3->mLookaroundAngleDesired = v19;
  }
  v20 = v3->vfptr;
  v3->mLookaroundJoyInput = 0.0;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v20[31].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v3->vfptr[15].__vecDelDtor)(v3);
}

// File Line: 1426
// RVA: 0x3DD7F0
void __fastcall UFG::ChaseCameraComponent::UpdateTargeting(UFG::ChaseCameraComponent *this)
{
  UFG::ChaseCameraComponent *rdi1; // rdi
  UFG::SimComponent *rbx1; // rbx
  __int64 v3; // rax
  float v4; // xmm10_4
  float v5; // xmm12_4
  float *v6; // rax
  float v7; // xmm10_4
  __int128 v8; // xmm11
  float v9; // xmm12_4
  UFG::TargetingSystemPedPlayerComponent *v10; // rcx
  UFG::SimObjectCharacter *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::AimingPlayerComponent *v13; // rbx
  UFG::TargetingSystemPedPlayerComponent *v14; // rcx
  UFG::qVector3 *v15; // rax
  float v16; // xmm0_4
  float v17; // xmm1_4
  float *v18; // rax
  float v19; // xmm14_4
  float v20; // xmm13_4
  float v21; // xmm9_4
  float v22; // xmm2_4
  __m128 v23; // xmm1
  float v24; // xmm9_4
  __int64 v25; // rax
  int v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float v30; // xmm0_4
  float *v31; // rcx
  float v32; // xmm9_4
  float v33; // xmm7_4
  float *v34; // rax
  float v35; // xmm2_4
  float v36; // xmm15_4
  float v37; // xmm8_4
  float v38; // xmm13_4
  float v39; // xmm6_4
  float *v40; // rax
  float v41; // xmm3_4
  float v42; // xmm5_4
  float v43; // xmm7_4
  float v44; // xmm15_4
  __m128 v45; // xmm6
  __m128 v46; // xmm2
  float v47; // xmm4_4
  float *v48; // rcx
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm0_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm13_4
  float v55; // xmm2_4
  float v56; // xmm8_4
  float v57; // xmm1_4
  float v58; // xmm4_4
  __m128 v59; // xmm2
  float v60; // xmm5_4
  float v61; // xmm0_4
  float v62; // xmm3_4
  float v63; // xmm13_4
  __m128 v64; // xmm9
  float v65; // xmm14_4
  float *v66; // rax
  __m128 v67; // xmm2
  float v68; // xmm7_4
  float v69; // xmm8_4
  float v70; // xmm6_4
  float v71; // xmm10_4
  float v72; // xmm12_4
  float v73; // xmm3_4
  __m128 v74; // xmm2
  float v75; // xmm6_4
  float v76; // xmm7_4
  float v77; // xmm8_4
  float v78; // xmm7_4
  float v79; // xmm8_4
  float v80; // xmm6_4
  float *v81; // rax
  float *v82; // rbx
  float v83; // xmm3_4
  float v84; // xmm2_4
  float v85; // xmm7_4
  UFG::SimComponent *v86; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v87; // rax
  float *v88; // rax
  float *v89; // rcx
  float v90; // xmm3_4
  float v91; // xmm2_4
  float v92; // xmm9_4
  float v93; // [rsp+20h] [rbp-E8h]
  float v94; // [rsp+24h] [rbp-E4h]
  UFG::qVector2 v2; // [rsp+28h] [rbp-E0h]
  UFG::qVector2 v1; // [rsp+30h] [rbp-D8h]
  UFG::qVector3 result; // [rsp+38h] [rbp-D0h]
  float v98; // [rsp+110h] [rbp+8h]
  float v99; // [rsp+110h] [rbp+8h]
  float v100; // [rsp+118h] [rbp+10h]
  float v101; // [rsp+120h] [rbp+18h]
  float v102; // [rsp+128h] [rbp+20h]

  rdi1 = this;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  rbx1 = rdi1->mTarget.m_pSimComponent;
  v3 = ((__int64 (__fastcall *)(UFG::SimComponent *))rbx1->vfptr[16].__vecDelDtor)(rdi1->mTarget.m_pSimComponent);
  v4 = *(float *)v3;
  v8 = *(unsigned int *)(v3 + 4);
  v5 = *(float *)(v3 + 8);
  v6 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))rbx1->vfptr[17].__vecDelDtor)(rbx1);
  v7 = (float)(v4 * 5.0) + *v6;
  *(float *)&v8 = (float)(*(float *)&v8 * 5.0) + v6[1];
  v9 = (float)(v5 * 5.0) + v6[2];
  rdi1->mFocusPos.x = v7;
  LODWORD(rdi1->mFocusPos.y) = v8;
  rdi1->mFocusPos.z = v9;
  v10 = rdi1->mTargetingSystem;
  if ( v10 && (v11 = (UFG::SimObjectCharacter *)v10->m_pSimObject) != 0i64 )
  {
    v12 = v11->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = UFG::SimObjectCharacter::GetComponent<UFG::AimingPlayerComponent>(v11);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v11->vfptr,
                                              UFG::AimingPlayerComponent::_TypeUID);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v13 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v11->vfptr,
                                              UFG::AimingPlayerComponent::_TypeUID);
      }
      else
      {
        v13 = (UFG::AimingPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v11->vfptr,
                                              UFG::AimingPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v13 = (UFG::AimingPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v11->vfptr,
                                            UFG::AimingPlayerComponent::_TypeUID);
    }
  }
  else
  {
    v13 = 0i64;
  }
  if ( v13 )
  {
    v14 = rdi1->mTargetingSystem;
    if ( (unsigned int)(v14->m_eFocusMode - 3) <= 1 || v14->m_eFocusMode == 2 )
    {
      v15 = UFG::AimingPlayerComponent::GetFreeAimFocusPosition(v13, &result);
      v7 = v15->x;
      v8 = LODWORD(v15->y);
      v9 = v15->z;
    }
    else if ( (unsigned int)(v14->m_eFocusMode - 1) <= 1 )
    {
      v7 = v13->m_vAimPosition.x;
      v8 = LODWORD(v13->m_vAimPosition.y);
      v9 = v13->m_vAimPosition.z;
    }
    v16 = v13->m_vAimPosition.y;
    v17 = v13->m_vAimPosition.z;
    rdi1->mFocusPos.x = v13->m_vAimPosition.x;
    rdi1->mFocusPos.y = v16;
    rdi1->mFocusPos.z = v17;
  }
  v18 = (float *)((__int64 (*)(void))rdi1->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
  v19 = *(float *)&FLOAT_1_0;
  v23 = (__m128)v8;
  v20 = *v18;
  v21 = v9 - v18[2];
  v100 = v18[1];
  v22 = 0.0;
  v101 = v18[2];
  v23.m128_f32[0] = (float)((float)((float)(*(float *)&v8 - v18[1]) * (float)(*(float *)&v8 - v18[1]))
                          + (float)((float)(v7 - v20) * (float)(v7 - v20)))
                  + (float)(v21 * v21);
  if ( v23.m128_f32[0] != 0.0 )
    v22 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
  v24 = v21 * v22;
  v25 = ((__int64 (*)(void))rdi1->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)();
  v26 = LODWORD(rdi1->mCamera.mTransformation.v2.x) ^ _xmm[0];
  v27 = *(float *)v25;
  v2.y = *(float *)(v25 + 4);
  v28 = rdi1->mCamera.mTransformation.v2.y;
  v2.x = v27;
  LODWORD(v1.y) = LODWORD(v28) ^ _xmm[0];
  LODWORD(v1.x) = v26;
  v29 = UFG::qAngleBetween(&v1, &v2);
  v93 = sinf(v29);
  v30 = cosf(v29);
  v31 = (float *)rdi1->mTarget.m_pSimComponent;
  v32 = (float)(v24 - -1.0) * 0.5;
  v94 = v30 * v30;
  v102 = v31[164];
  v98 = 0.0;
  if ( v32 > 0.0 )
  {
    v98 = v32;
    if ( v32 >= 1.0 )
      v98 = *(float *)&FLOAT_1_0;
  }
  v33 = v31[165];
  v34 = (float *)(*(__int64 (**)(void))(*(_QWORD *)v31 + 152i64))();
  v35 = (float)((float)((float)(v100 * v34[4]) + (float)(v20 * *v34)) + (float)(v101 * v34[8])) + v34[12];
  v36 = (float)((float)((float)(v20 * v34[1]) + (float)(v100 * v34[5])) + (float)(v101 * v34[9])) + v34[13];
  v37 = (float)((float)((float)(v20 * v34[2]) + (float)(v100 * v34[6])) + (float)(v101 * v34[10])) + v34[14];
  v38 = (float)((float)((float)(v20 * v34[3]) + (float)(v100 * v34[7])) + (float)(v101 * v34[11])) + v34[15];
  v39 = (float)((float)((float)((float)((float)((float)(v102 * 0.40000001) - v102) * v98) + v102) * v93) + v33) + v35;
  v40 = (float *)((__int64 (*)(void))rdi1->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)();
  v41 = (float)((float)((float)(v36 * v40[4]) + (float)(v39 * *v40)) + (float)(v37 * v40[8])) + (float)(v38 * v40[12]);
  v42 = v7 - v41;
  v43 = (float)((float)((float)(v36 * v40[5]) + (float)(v39 * v40[1])) + (float)(v37 * v40[9])) + (float)(v38 * v40[13]);
  v44 = (float)((float)((float)(v36 * v40[6]) + (float)(v39 * v40[2])) + (float)(v37 * v40[10]))
      + (float)(v38 * v40[14]);
  v45 = (__m128)v8;
  v45.m128_f32[0] = *(float *)&v8 - v43;
  v46 = v45;
  v46.m128_f32[0] = (float)(v45.m128_f32[0] * v45.m128_f32[0]) + (float)(v42 * v42);
  if ( v46.m128_f32[0] == 0.0 )
    v47 = 0.0;
  else
    v47 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v46));
  v48 = (float *)rdi1->mTarget.m_pSimComponent;
  v49 = v42 * v47;
  v45.m128_f32[0] = v45.m128_f32[0] * v47;
  v50 = v47 * 0.0;
  if ( v32 <= 0.0 )
  {
    v32 = 0.0;
  }
  else if ( v32 >= 1.0 )
  {
    goto LABEL_33;
  }
  v19 = v32;
LABEL_33:
  v51 = (float)((float)((float)(v48[161] - v48[160]) * v19) + v48[160]) + rdi1->mTargetOffset.z;
  v99 = v51;
  v52 = v51 * 0.0;
  v53 = rdi1->mTargetOffset.y;
  v54 = (float)(v49 - (float)(v50 * 0.0)) * v53;
  v55 = (float)((float)(v45.m128_f32[0] * 0.0) - (float)(v49 * 0.0)) * v53;
  v56 = (float)((float)(v50 * 0.0) - v45.m128_f32[0]) * v53;
  v57 = rdi1->mTargetOffset.x;
  v45.m128_f32[0] = (float)((float)((float)(v45.m128_f32[0] * v57) + v43) + v54) + v52;
  v64 = v45;
  v58 = (float)((float)((float)(v50 * v57) + v44) + v55) + v99;
  v64.m128_f32[0] = v45.m128_f32[0] - *(float *)&v8;
  v59 = v64;
  v60 = (float)((float)((float)(v49 * v57) + v41) + v56) + v52;
  v61 = (float)((float)(v48[205] - v48[202]) * 0.5) + v48[162];
  v59.m128_f32[0] = (float)((float)(v64.m128_f32[0] * v64.m128_f32[0]) + (float)((float)(v60 - v7) * (float)(v60 - v7)))
                  + (float)((float)(v58 - v9) * (float)(v58 - v9));
  v62 = (float)((float)((float)((float)((float)((float)(v48[204] - v48[201]) * 0.5) + v48[163]) - v61) * v94) + v61)
      / COERCE_FLOAT(_mm_sqrt_ps(v59));
  v63 = (float)((float)(v60 - v7) * v62) + v60;
  v64.m128_f32[0] = (float)((float)(v45.m128_f32[0] - *(float *)&v8) * v62) + v45.m128_f32[0];
  v65 = (float)((float)(v58 - v9) * v62) + v58;
  v66 = (float *)(*(__int64 (**)(void))(*(_QWORD *)v48 + 136i64))();
  v67 = v64;
  v68 = UFG::qVector3::msAxisX.x;
  v69 = UFG::qVector3::msAxisX.y;
  v70 = UFG::qVector3::msAxisX.z;
  v71 = v7 - v63;
  *(float *)&v8 = *(float *)&v8 - v64.m128_f32[0];
  v67.m128_f32[0] = (float)((float)((float)(v64.m128_f32[0] - v66[1]) * (float)(v64.m128_f32[0] - v66[1]))
                          + (float)((float)(v63 - *v66) * (float)(v63 - *v66)))
                  + (float)((float)(v65 - v66[2]) * (float)(v65 - v66[2]));
  v72 = v9 - v65;
  LODWORD(v73) = (unsigned __int128)_mm_sqrt_ps(v67);
  v74 = (__m128)v8;
  v74.m128_f32[0] = (float)((float)(*(float *)&v8 * *(float *)&v8) + (float)(v71 * v71)) + (float)(v72 * v72);
  if ( v74.m128_f32[0] > 0.000099999997 && v73 > 0.000099999997 )
  {
    v75 = v73 / COERCE_FLOAT(_mm_sqrt_ps(v74));
    v76 = v75;
    v77 = v75;
    v70 = v75 * v72;
    v68 = v76 * v71;
    v69 = v77 * *(float *)&v8;
  }
  v78 = v68 + v63;
  v79 = v69 + v64.m128_f32[0];
  v80 = v70 + v65;
  v81 = (float *)((__int64 (*)(void))rdi1->mTarget.m_pSimComponent->vfptr[19].__vecDelDtor)();
  v82 = &rdi1->mAimLook.mDuration.x;
  v83 = (float)(v79 * v81[4]) + (float)(v78 * *v81);
  v84 = (float)((float)((float)(v78 * v81[1]) + (float)(v79 * v81[5])) + (float)(v80 * v81[9])) + v81[13];
  v85 = (float)((float)((float)(v78 * v81[2]) + (float)(v79 * v81[6])) + (float)(v80 * v81[10])) + v81[14];
  v82[21] = (float)(v83 + (float)(v80 * v81[8])) + v81[12];
  v82[22] = v84;
  v82[23] = v85;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&rdi1->mAimLook);
  v86 = rdi1->mTarget.m_pSimComponent;
  *(_QWORD *)&rdi1->mAimLook.mParameter.x = 0i64;
  v87 = v86->vfptr;
  rdi1->mAimLook.mParameter.z = 0.0;
  v88 = (float *)((__int64 (*)(void))v87[19].__vecDelDtor)();
  v89 = &rdi1->mAimEye.mDuration.x;
  v90 = (float)((float)((float)(v64.m128_f32[0] * v88[4]) + (float)(v63 * *v88)) + (float)(v65 * v88[8])) + v88[12];
  v91 = (float)((float)((float)(v64.m128_f32[0] * v88[5]) + (float)(v63 * v88[1])) + (float)(v65 * v88[9])) + v88[13];
  v92 = (float)((float)((float)(v64.m128_f32[0] * v88[6]) + (float)(v63 * v88[2])) + (float)(v65 * v88[10])) + v88[14];
  v89[22] = v91;
  v89[21] = v90;
  v89[23] = v92;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&rdi1->mAimEye);
  *(_QWORD *)&rdi1->mAimEye.mParameter.x = 0i64;
  rdi1->mAimEye.mParameter.z = 0.0;
} v92 = (float)((float)((float)(v64.m128_f32[0] * v88[6]) + (float)(v63 * v88[2])) + (float)(v65 * v88[10])) + v88[14];
  v89[22] = v91;
  v89[21] = v90;
  v89[23] = v92;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&rdi

// File Line: 1522
// RVA: 0x3C5520
void __fastcall UFG::GameCameraComponent::HandleImpact(UFG::GameCameraComponent *this, float magnitude)
{
  float v2; // xmm0_4

  v2 = magnitude;
  if ( magnitude < 0.0 )
    v2 = 0.0;
  UFG::GameCameraComponent::AddShakeAmplitude(this, (float)(v2 * 0.0) * v2);
}

// File Line: 1528
// RVA: 0x3BF350
void __usercall UFG::ChaseCameraComponent::AutoLockUnlock(UFG::ChaseCameraComponent *this@<rcx>, float dt@<xmm1>, float a3@<xmm0>)
{
  UFG::ChaseCameraComponent *v3; // rbx
  int v4; // xmm7_4
  float v5; // xmm15_4
  float *v6; // rax
  __m128 v7; // xmm0
  float v8; // xmm9_4
  int v9; // xmm10_4
  float *v10; // rax
  float v11; // xmm14_4
  __m128 v12; // xmm13
  __m128 v13; // xmm6
  float v14; // xmm11_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm10_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm10_4
  float *v21; // rax
  float v22; // xmm5_4
  float v23; // xmm13_4
  float v24; // xmm5_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float *v35; // rax
  float v36; // xmm9_4
  float v37; // xmm6_4
  float v38; // xmm4_4
  __m128 v39; // xmm5
  float v40; // xmm3_4
  float v41; // xmm7_4
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  float v44; // xmm7_4
  float v45; // xmm6_4
  float v46; // xmm0_4
  bool v47; // di
  UFG::SimComponent *v48; // rcx
  bool v49; // si
  float v50; // xmm6_4
  float v51; // xmm10_4
  unsigned int v52; // eax
  unsigned __int16 v53; // dx
  UFG::SimComponent *v54; // rax
  bool v55; // al
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // [rsp+100h] [rbp+18h]
  float v61; // [rsp+108h] [rbp+20h]

  v3 = this;
  v4 = LODWORD(this->mEyeOffset.x) ^ _xmm[0];
  ((void (__cdecl *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[28].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v5 = a3;
  v6 = (float *)((__int64 (*)(void))v3->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
  v7 = (__m128)LODWORD(v3->mEyeCurr.x);
  v7.m128_f32[0] = (float)((float)((float)(v7.m128_f32[0] - *v6) * (float)(v7.m128_f32[0] - *v6))
                         + (float)((float)(v3->mEyeCurr.y - v6[1]) * (float)(v3->mEyeCurr.y - v6[1])))
                 + (float)((float)(v3->mEyeCurr.z - v6[2]) * (float)(v3->mEyeCurr.z - v6[2]));
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v7);
  if ( (v5 > 3.0 || v8 > *(float *)&v4) && v3->mLockLook )
  {
    v3->mLockLookParam = 1.0;
    v3->mLockLook = 0;
  }
  v9 = _xmm;
  if ( v3->mLockEye )
  {
    v10 = (float *)((__int64 (*)(void))v3->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
    v61 = *v10;
    v60 = v10[1];
    v12 = (__m128)LODWORD(v3->mLockEyePos.x);
    v11 = v3->mLockEyePos.y - v60;
    v12.m128_f32[0] = v12.m128_f32[0] - *v10;
    v13 = v12;
    v13.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11);
    if ( v13.m128_f32[0] > 0.000099999997 )
    {
      v14 = *(float *)&v4 * 0.64999998;
      if ( COERCE_FLOAT(_mm_sqrt_ps(v13)) < (float)(*(float *)&v4 * 0.64999998) )
      {
        v15 = *(float *)(((__int64 (*)(void))v3->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)() + 8)
            + v3->mEyeOffset.z;
        v16 = v3->mLockEyePos.z;
        if ( v16 <= v15 )
          v16 = v15;
        if ( v13.m128_f32[0] == 0.0 )
          v17 = 0.0;
        else
          v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v13));
        v18 = v17 * 0.0;
        v19 = v17 * v11;
        v20 = v17 * v12.m128_f32[0];
        v3->mLockEyePos.x = v61 + (float)(v20 * v14);
        v3->mLockEyePos.y = v60 + (float)(v19 * v14);
        v3->mLockEyePos.z = v16;
        v21 = (float *)((__int64 (*)(void))v3->mTarget.m_pSimComponent->vfptr[15].__vecDelDtor)();
        v22 = v21[1];
        v23 = (float)((float)(v19 * v22) + (float)(v20 * *v21)) + (float)(v18 * 0.0);
        v9 = _xmm;
        if ( COERCE_FLOAT(LODWORD(v23) & _xmm) < 0.60000002 )
        {
          v24 = (float)(v22 * dt) * 6.0;
          v25 = (float)(*v21 * dt) * 6.0;
          if ( v23 <= 0.0 )
          {
            v28 = (float)(dt * 0.0) * 6.0;
            v29 = v3->mLockEyePos.y - v24;
            v30 = v3->mLockEyePos.z;
            v3->mLockEyePos.x = v3->mLockEyePos.x - v25;
            v3->mLockEyePos.y = v29;
            v3->mLockEyePos.z = v30 - v28;
          }
          else
          {
            v26 = v24 + v3->mLockEyePos.y;
            v27 = (float)((float)(dt * 0.0) * 6.0) + v3->mLockEyePos.z;
            v3->mLockEyePos.x = v25 + v3->mLockEyePos.x;
            v3->mLockEyePos.y = v26;
            v3->mLockEyePos.z = v27;
          }
        }
      }
    }
  }
  if ( UFG::VehicleSubjectComponent::GetForwardSpeed((UFG::VehicleSubjectComponent *)v3->mTarget.m_pSimComponent) >= v3->mReverseSpeed
    || v3->mAimOrFocus )
  {
    v45 = UFG::VehicleSubjectComponent::GetForwardSpeed((UFG::VehicleSubjectComponent *)v3->mTarget.m_pSimComponent);
    v47 = 0;
    if ( UFG::VehicleSubjectComponent::IsDoingBurnout((UFG::VehicleSubjectComponent *)v3->mTarget.m_pSimComponent) )
    {
      v46 = v3->mLockEye ? UFG::ChaseCameraComponent::mBurnoutSpeedThresholdOut : UFG::ChaseCameraComponent::mBurnoutSpeedThresholdIn;
      if ( COERCE_FLOAT(LODWORD(v45) & v9) < v46 )
        v47 = 1;
    }
    v48 = v3->mTarget.m_pSimComponent;
    v49 = (float)((float)(COERCE_FLOAT(v48[9].m_TypeUID & v9) * 180.0) * 0.31830987) > 70.0
       && UFG::VehicleSubjectComponent::IsInReverse((UFG::VehicleSubjectComponent *)v48);
    v50 = *(float *)&v4 * 1.3;
    if ( v47 )
      v51 = *(float *)&v4 * 1.3;
    else
      v51 = *(float *)&v4;
    v52 = _S16_0;
    if ( !(_S16_0 & 1) )
    {
      _S16_0 |= 1u;
      HASH_ActionHijack.mUID = UFG::qStringHashUpper32("ActionHijack", 0xFFFFFFFF);
      v52 = _S16_0;
    }
    if ( !(v52 & 2) )
    {
      _S16_0 = v52 | 2;
      mostUsedIndex_ActionHijack = GetMostUsedIndex(HASH_ActionHijack.mUID);
    }
    v55 = 0;
    if ( LocalPlayer )
    {
      v53 = LocalPlayer->m_Flags;
      if ( (v53 >> 14) & 1 )
      {
        v54 = LocalPlayer->m_Components.p[7].m_pComponent;
      }
      else if ( (v53 & 0x8000u) == 0 )
      {
        if ( (v53 >> 13) & 1 )
          v54 = LocalPlayer->m_Components.p[6].m_pComponent;
        else
          v54 = (v53 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                    UFG::ActionTreeComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                            (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                            UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v54 = LocalPlayer->m_Components.p[7].m_pComponent;
      }
      if ( v54
        && ActionController::IsPlaying((ActionController *)&v54[3], &HASH_ActionHijack, mostUsedIndex_ActionHijack, 0) )
      {
        v55 = 1;
      }
    }
    if ( v3->mAimOrFocus || v55 )
    {
      if ( v3->mLockEye )
      {
        v3->mLockEyeParam = 1.0;
        v3->mLockEye = 0;
        v3->mUpdateEyeOffset = 1;
      }
      if ( v3->mLockLook )
      {
        v3->mLockLookParam = 1.0;
        v3->mLockLook = 0;
      }
      if ( v55 )
        *(_QWORD *)&v3->mLockEyeParam = 0i64;
    }
    else if ( v5 < 2.0 && v8 < (float)(v50 + 0.1)
           || v5 < 4.0 && v8 < *(float *)&v4
           || v5 < 5.0 && v8 < v50 && v47
           || v5 < 15.0 && v8 < v50 && v49 )
    {
      if ( 0.0 == v3->mLookaroundAngle && v3->mLockEye != 1 )
      {
        v56 = v3->mEyeVelocity.y;
        v57 = v3->mEyeVelocity.z;
        v3->mLockEyeVel.x = v3->mEyeVelocity.x;
        v3->mLockEyeVel.y = v56;
        v3->mLockEyeVel.z = v57;
        v58 = v3->mEyeCurr.y;
        v59 = v3->mEyeCurr.z;
        v3->mLockEyePos.x = v3->mEyeCurr.x;
        v3->mLockEyePos.y = v58;
        v3->mLockEyePos.z = v59;
        v3->mLockEyeParam = 0.0;
        v3->mLockEye = 1;
        v3->mUpdateEyeOffset = 0;
      }
    }
    else if ( v8 > v51 && v3->mLockEye )
    {
      v3->mLockEyeParam = 1.0;
      v3->mLockEye = 0;
      v3->mUpdateEyeOffset = 1;
    }
  }
  else
  {
    if ( 0.0 == v3->mLookaroundAngle && v3->mLockEye != 1 )
    {
      v31 = v3->mEyeVelocity.y;
      v32 = v3->mEyeVelocity.z;
      v3->mLockEyeVel.x = v3->mEyeVelocity.x;
      v3->mLockEyeVel.y = v31;
      v3->mLockEyeVel.z = v32;
      v33 = v3->mEyeCurr.y;
      v34 = v3->mEyeCurr.z;
      v3->mLockEyePos.x = v3->mEyeCurr.x;
      v3->mLockEyePos.y = v33;
      v3->mLockEyePos.z = v34;
      v3->mLockEyeParam = 0.0;
      v3->mLockEye = 1;
      v3->mUpdateEyeOffset = 0;
    }
    v35 = (float *)((__int64 (*)(void))v3->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
    v36 = v35[1];
    v37 = v35[2] + v3->mEyeOffset.z;
    v38 = v3->mLockEyePos.x - *v35;
    v39 = (__m128)LODWORD(v3->mLockEyePos.y);
    v39.m128_f32[0] = v39.m128_f32[0] - v36;
    v40 = v3->mLockEyePos.z - v37;
    v41 = *(float *)&v4 * 1.3;
    v42 = v39;
    v42.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38)) + (float)(v40 * v40);
    if ( COERCE_FLOAT(_mm_sqrt_ps(v42)) > v41 )
    {
      v43 = v39;
      v43.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38)) + (float)(v40 * v40);
      v44 = v41 / COERCE_FLOAT(_mm_sqrt_ps(v43));
      v3->mLockEyePos.x = *v35 + (float)(v38 * v44);
      v3->mLockEyePos.y = v36 + (float)(v39.m128_f32[0] * v44);
      v3->mLockEyePos.z = (float)(v40 * v44) + v37;
    }
  }
}

// File Line: 1626
// RVA: 0x3C4E00
void __fastcall UFG::ChaseCameraComponent::GunRecoil(UFG::ChaseCameraComponent *this, float scaleKickup, float scaleKickback, float scaleSpeed)
{
  UFG::ChaseCameraComponent *v4; // rdi
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
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm6_4
  signed __int64 v21; // rcx
  float v22; // xmm0_4
  float v23; // xmm8_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm9_4
  float v28; // xmm1_4
  float v29; // xmm0_4

  v4 = this;
  v5 = scaleKickup;
  v6 = scaleKickback;
  if ( this->mTarget.m_pSimComponent
    && (v7 = *(UFG::SimObjectCVBase **)&this->mTarget.m_pSimComponent[13].m_Flags) != 0i64 )
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
  v18 = UFG::qVector3::msZero.y;
  v19 = UFG::qVector3::msZero.z;
  v20 = v13 * v5;
  v21 = (signed __int64)&v4->mRecoilEye;
  *(float *)(v21 + 84) = UFG::qVector3::msZero.x;
  *(float *)(v21 + 88) = v18;
  *(float *)(v21 + 92) = v19;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mRecoilEye);
  *(_QWORD *)&v4->mRecoilEye.mParameter.x = 0i64;
  v4->mRecoilEye.mParameter.z = 0.0;
  v4->mRecoilAngle = v20;
  v4->mRecoilAngleDesired = (float)(v15 * v5) + v20;
  LODWORD(v22) = COERCE_UNSIGNED_INT((float)(v16 * 0.001) * v6) ^ _xmm[0];
  v23 = v22 * v4->mCamera.mTransformation.v2.z;
  v24 = v22 * v4->mCamera.mTransformation.v2.x;
  v25 = v22 * v4->mCamera.mTransformation.v2.y;
  v4->mRecoilEye.p0.z = v23;
  v4->mRecoilEye.p0.x = v24;
  v4->mRecoilEye.p0.y = v25;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mRecoilEye);
  *(_QWORD *)&v4->mRecoilEye.mParameter.x = 0i64;
  v4->mRecoilEye.mParameter.z = 0.0;
  LODWORD(v26) = COERCE_UNSIGNED_INT(v17 * scaleSpeed) ^ _xmm[0];
  v27 = v26 * v4->mCamera.mTransformation.v2.z;
  v28 = v26 * v4->mCamera.mTransformation.v2.x;
  v29 = v26 * v4->mCamera.mTransformation.v2.y;
  v4->mRecoilEye.v0.z = v27;
  v4->mRecoilEye.v0.x = v28;
  v4->mRecoilEye.v0.y = v29;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mRecoilEye);
  *(_QWORD *)&v4->mRecoilEye.mParameter.x = 0i64;
  v4->mRecoilEye.mParameter.z = 0.0;
}

// File Line: 1662
// RVA: 0x3C8FB0
void __fastcall UFG::ChaseCameraComponent::RestrictOrbitHeight(UFG::ChaseCameraComponent *this, UFG::qVector3 *eye)
{
  UFG::ChaseCameraComponent *v2; // rdi
  UFG::qVector3 *v3; // rsi
  float *v4; // rbx
  signed __int64 v5; // rbp
  float v6; // xmm6_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  float *v9; // rax
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm8_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm6_4
  float v16; // xmm8_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  UFG::qVector3 verts; // [rsp+20h] [rbp-98h]
  float v20; // [rsp+34h] [rbp-84h]
  float v21; // [rsp+40h] [rbp-78h]
  float v22; // [rsp+4Ch] [rbp-6Ch]
  float v23; // [rsp+58h] [rbp-60h]
  float v24; // [rsp+64h] [rbp-54h]
  float v25; // [rsp+70h] [rbp-48h]
  float v26; // [rsp+7Ch] [rbp-3Ch]

  v2 = this;
  v3 = eye;
  UFG::CameraSubject::GetBoxVerts((UFG::CameraSubject *)this->mTarget.m_pSimComponent, &verts, 0.0);
  v4 = &verts.z;
  v5 = 8i64;
  do
  {
    v6 = *(v4 - 2);
    v7 = *(v4 - 1);
    v8 = *v4;
    v9 = (float *)((__int64 (*)(void))v2->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)();
    v4 += 3;
    v10 = v7 * v9[4];
    v11 = v7 * v9[5];
    v12 = v7 * v9[6];
    v13 = (float)(v10 + (float)(v6 * *v9)) + (float)(v8 * v9[8]);
    v14 = v6 * v9[1];
    v15 = v6 * v9[2];
    *(v4 - 5) = v13 + v9[12];
    v16 = (float)((float)(v12 + v15) + (float)(v8 * v9[10])) + v9[14];
    *(v4 - 4) = (float)((float)(v11 + v14) + (float)(v8 * v9[9])) + v9[13];
    *(v4 - 3) = v16;
    --v5;
  }
  while ( v5 );
  v17 = FLOAT_N10000_0;
  if ( verts.z > -10000.0 )
    v17 = verts.z;
  if ( v20 > v17 )
    v17 = v20;
  if ( v21 > v17 )
    v17 = v21;
  if ( v22 > v17 )
    v17 = v22;
  if ( v23 > v17 )
    v17 = v23;
  if ( v24 > v17 )
    v17 = v24;
  if ( v25 > v17 )
    v17 = v25;
  if ( v26 > v17 )
    v17 = v26;
  v18 = v17 + v2->mOrbitHeightMinOffset;
  if ( v18 > v3->z )
    v3->z = v18;
}

// File Line: 1710
// RVA: 0x3C6AF0
void __fastcall UFG::ChaseCameraComponent::LockEye(UFG::ChaseCameraComponent *this, bool lock)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  if ( (this->mLookaroundAngle == 0.0 || !lock) && this->mLockEye != lock )
  {
    if ( lock )
    {
      v2 = this->mEyeVelocity.y;
      v3 = this->mEyeVelocity.z;
      this->mLockEyeVel.x = this->mEyeVelocity.x;
      this->mLockEyeVel.y = v2;
      this->mLockEyeVel.z = v3;
      v4 = this->mEyeCurr.y;
      v5 = this->mEyeCurr.z;
      this->mLockEyePos.x = this->mEyeCurr.x;
      this->mLockEyePos.y = v4;
      this->mLockEyePos.z = v5;
      this->mUpdateEyeOffset = lock == 0;
      this->mLockEyeParam = 0.0;
      this->mLockEye = lock;
    }
    else
    {
      this->mLockEyeParam = 1.0;
      this->mLockEye = 0;
      this->mUpdateEyeOffset = 1;
    }
  }
}

// File Line: 1758
// RVA: 0x3D0000
void __usercall UFG::ChaseCameraComponent::Update(UFG::ChaseCameraComponent *this@<rcx>, float dt@<xmm1>, __int64 a3@<r13>)
{
  float v3; // xmm10_4
  UFG::ChaseCameraComponent *v4; // rdi
  char v5; // bl
  float v6; // xmm1_4
  float v7; // xmm0_4
  bool v8; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v9; // rax
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm2_4
  UFG::SimObjectCVBase *v22; // rcx
  UFG::TargetingSystemPedPlayerComponent *v23; // rax
  unsigned __int16 v24; // dx
  UFG::TargetingSystemPedPlayerComponent *v25; // rcx
  char v26; // al
  float v27; // xmm1_4
  int *v28; // rax
  UFG::SimComponent *v29; // rcx
  float v30; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v31; // rax
  __int64 v32; // rax
  float v33; // xmm6_4
  __m128 v34; // xmm8
  float v35; // xmm7_4
  float *v36; // rax
  float v37; // xmm9_4
  float v38; // xmm11_4
  float v39; // xmm13_4
  float v40; // xmm12_4
  UFG::TargetingSystemPedPlayerComponent *v41; // rcx
  float v42; // xmm7_4
  float v43; // xmm8_4
  bool v44; // cl
  UFG::ChaseCameraParameters *v45; // rax
  float v46; // xmm1_4
  float v47; // xmm6_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  UFG::SimObjectCVBase *v52; // rcx
  unsigned __int16 v53; // dx
  UFG::TargetingSystemPedPlayerComponent *v54; // rax
  UFG::SimComponent *v55; // rax
  bool v56; // cl
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm7_4
  __int64 v60; // rdx
  float v61; // xmm4_4
  float v62; // xmm2_4
  float v63; // xmm3_4
  float v64; // xmm0_4
  float *v65; // rax
  float v66; // xmm6_4
  float v67; // xmm9_4
  float v68; // xmm11_4
  float v69; // xmm13_4
  float v70; // xmm15_4
  UFG::qVector3 *v71; // rax
  float v72; // xmm0_4
  float v73; // xmm1_4
  UFG::qVector3 *v74; // rax
  float v75; // xmm2_4
  float v76; // xmm0_4
  float v77; // xmm1_4
  float v78; // xmm1_4
  float v79; // xmm8_4
  float v80; // xmm6_4
  float v81; // xmm0_4
  float v82; // xmm0_4
  __m128 v83; // xmm1
  unsigned int v84; // xmm2_4
  float v85; // xmm4_4
  __m128 v86; // xmm5
  float v87; // xmm6_4
  __m128 v88; // xmm3
  float v89; // xmm8_4
  float v90; // xmm11_4
  float v91; // xmm13_4
  float v92; // xmm8_4
  float v93; // xmm11_4
  float v94; // xmm13_4
  __int128 v95; // xmm0
  float v96; // xmm1_4
  float v97; // xmm2_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  float v100; // xmm0_4
  float v101; // xmm1_4
  float v102; // xmm0_4
  float v103; // xmm1_4
  float v104; // eax
  float v105; // xmm1_4
  float v106; // xmm0_4
  float v107; // xmm1_4
  float v108; // xmm6_4
  float v109; // xmm14_4
  float v110; // xmm7_4
  float *v111; // rax
  UFG::SimComponent *v112; // rcx
  float v113; // xmm2_4
  float v114; // xmm9_4
  float v115; // xmm0_4
  float v116; // xmm14_4
  float v117; // xmm9_4
  float v118; // xmm6_4
  float v119; // xmm1_4
  float v120; // xmm14_4
  float v121; // xmm7_4
  float v122; // xmm14_4
  float v123; // xmm2_4
  float v124; // xmm2_4
  __m128 v125; // xmm14
  float *v126; // rax
  __m128 v127; // xmm2
  float v128; // xmm5_4
  float v129; // xmm6_4
  float v130; // xmm14_4
  __m128 v131; // xmm7
  float v132; // xmm9_4
  float v133; // xmm3_4
  float v134; // xmm3_4
  __m128 v135; // xmm2
  int v136; // xmm2_4
  float v137; // xmm1_4
  float v138; // xmm9_4
  float v139; // xmm7_4
  float v140; // xmm0_4
  float v141; // xmm0_4
  float v142; // xmm6_4
  float v143; // xmm9_4
  float v144; // xmm7_4
  UFG::qVector3 *v145; // rax
  float v146; // xmm1_4
  float v147; // xmm0_4
  float v148; // xmm9_4
  float v149; // xmm7_4
  UFG::qVector3 *v150; // rax
  float v151; // xmm0_4
  float v152; // xmm0_4
  float v153; // xmm1_4
  float *v154; // rbx
  float *v155; // rsi
  float v156; // eax
  float v157; // xmm1_4
  float v158; // xmm3_4
  float v159; // xmm4_4
  float v160; // xmm3_4
  float v161; // xmm5_4
  float v162; // xmm4_4
  float v163; // xmm1_4
  float v164; // xmm2_4
  float v165; // xmm2_4
  float v166; // xmm1_4
  float v167; // xmm3_4
  __m128 v168; // xmm6
  float v169; // xmm15_4
  __m128 v170; // xmm7
  float v171; // xmm4_4
  float v172; // xmm8_4
  __m128 v173; // xmm9
  float v174; // xmm11_4
  __m128 v175; // xmm13
  float v176; // xmm14_4
  float v177; // xmm3_4
  float v178; // xmm3_4
  signed __int64 v179; // rdx
  float v180; // xmm1_4
  __m128 v181; // xmm4
  float v182; // xmm3_4
  __m128 v183; // xmm4
  float v184; // xmm2_4
  float v185; // xmm1_4
  float v186; // xmm0_4
  float v187; // xmm2_4
  float v188; // xmm1_4
  float v189; // xmm0_4
  UFG::qVector4 v190; // xmm3
  UFG::qVector4 v191; // xmm2
  UFG::qVector4 v192; // xmm1
  UFG::SimComponent *v193; // rcx
  float v194; // xmm4_4
  float v195; // xmm5_4
  float v196; // xmm2_4
  __int128 v197; // xmm9
  float v198; // xmm7_4
  float v199; // xmm3_4
  float v200; // xmm6_4
  float v201; // xmm2_4
  float v202; // xmm2_4
  float v203; // xmm6_4
  float *v204; // rax
  float v205; // xmm11_4
  __int128 v206; // xmm13
  float v207; // xmm9_4
  float v208; // xmm8_4
  float v209; // xmm7_4
  float v210; // xmm8_4
  float v211; // xmm2_4
  float v212; // xmm0_4
  float v213; // xmm2_4
  float v214; // xmm2_4
  float v215; // xmm1_4
  float v216; // xmm0_4
  float v217; // xmm14_4
  float v218; // xmm4_4
  float v219; // xmm1_4
  float v220; // xmm2_4
  float v221; // xmm0_4
  float v222; // xmm8_4
  float *v223; // rsi
  float v224; // xmm14_4
  __m128 v225; // xmm15
  float v226; // xmm3_4
  float v227; // xmm5_4
  float v228; // xmm8_4
  __m128 v229; // xmm1
  float v230; // xmm5_4
  float v231; // xmm7_4
  float v232; // xmm11_4
  float v233; // xmm9_4
  float v234; // xmm13_4
  float v235; // xmm0_4
  float v236; // xmm2_4
  float v237; // xmm14_4
  float v238; // xmm8_4
  float v239; // xmm1_4
  float v240; // xmm0_4
  float v241; // xmm0_4
  float v242; // xmm7_4
  UFG::qVector3 *v243; // rax
  float v244; // xmm3_4
  float v245; // xmm2_4
  UFG::qVector3 *v246; // rax
  float v247; // xmm1_4
  float v248; // xmm2_4
  float v249; // xmm7_4
  float v250; // xmm8_4
  float v251; // xmm7_4
  float v252; // xmm9_4
  float v253; // xmm14_4
  float v254; // xmm11_4
  float v255; // xmm13_4
  UFG::qMatrix44 *v256; // rbx
  UFG::qVector4 *v257; // rax
  float v258; // xmm7_4
  float v259; // xmm9_4
  UFG::qVector4 *v260; // rax
  char v261; // bl
  float v262; // xmm0_4
  float v263; // xmm1_4
  float v264; // xmm2_4
  float v265; // xmm13_4
  float v266; // xmm11_4
  UFG::Controller *v267; // r14
  UFG::UIScreen *v268; // rax
  unsigned int v269; // er8
  UFG::UIScreen *v270; // r14
  UFG::InputActionData *v271; // rcx
  UFG::GameStatTracker *v272; // rax
  float v273; // xmm0_4
  float v274; // xmm6_4
  UFG::InputActionData *v275; // rcx
  __m128 v276; // xmm9
  float v277; // xmm0_4
  UFG::GameStatTracker *v278; // rax
  UFG::GameStatTracker *v279; // rax
  float v280; // xmm3_4
  float v281; // xmm0_4
  UFG::InputActionData *v282; // rcx
  __m128 v283; // xmm1
  int v284; // xmm14_4
  int v285; // xmm7_4
  int v286; // xmm8_4
  int v287; // xmm6_4
  float *v288; // rax
  UFG::GameStatTracker *v289; // rax
  float v290; // xmm7_4
  float v291; // xmm8_4
  float v292; // xmm0_4
  float v293; // xmm1_4
  float v294; // xmm2_4
  float v295; // xmm0_4
  float v296; // xmm1_4
  float v297; // xmm5_4
  float v298; // xmm0_4
  float v299; // xmm2_4
  float v300; // xmm13_4
  float v301; // xmm0_4
  float v302; // xmm1_4
  float v303; // xmm6_4
  float v304; // xmm0_4
  float v305; // xmm1_4
  float v306; // xmm0_4
  float v307; // xmm6_4
  float v308; // xmm2_4
  float v309; // xmm1_4
  float v310; // xmm6_4
  bool v311; // al
  bool v312; // si
  float v313; // xmm0_4
  float *v314; // rbx
  float v315; // xmm0_4
  float *v316; // rbx
  bool v317; // al
  float v318; // xmm1_4
  float v319; // xmm4_4
  float v320; // xmm2_4
  float v321; // xmm12_4
  float v322; // xmm12_4
  float v323; // xmm5_4
  float v324; // xmm6_4
  float v325; // xmm9_4
  float v326; // xmm9_4
  float v327; // xmm0_4
  float v328; // xmm1_4
  __int64 v329; // rax
  UFG::SimComponent *v330; // rcx
  float v331; // xmm1_4
  float v332; // xmm7_4
  float v333; // xmm8_4
  float v334; // xmm11_4
  float v335; // xmm0_4
  float v336; // xmm1_4
  float v337; // xmm0_4
  float v338; // xmm1_4
  float v339; // xmm0_4
  float v340; // xmm1_4
  float v341; // xmm0_4
  float v342; // xmm1_4
  float v343; // xmm0_4
  float v344; // xmm1_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v345; // rax
  float *v346; // rax
  float v347; // xmm6_4
  float v348; // xmm3_4
  float v349; // xmm4_4
  float v350; // xmm0_4
  UFG::qMatrix44 *v351; // rax
  __m128 v352; // xmm6
  UFG::qVector4 v353; // xmm1
  UFG::qVector4 v354; // xmm0
  UFG::qVector4 v355; // xmm3
  int v356; // xmm2_4
  UFG::qVector4 *v357; // rax
  float v358; // xmm3_4
  __int128 v359; // xmm4
  float v360; // xmm5_4
  float v361; // xmm13_4
  __m128 v362; // xmm14
  float v363; // xmm15_4
  float v364; // xmm8_4
  __m128 v365; // xmm12
  float v366; // xmm11_4
  __m128 v367; // xmm9
  __m128 v368; // xmm2
  float v369; // xmm1_4
  float v370; // xmm11_4
  float v371; // xmm8_4
  float v372; // xmm0_4
  __m128 v373; // xmm2
  float v374; // xmm7_4
  float v375; // xmm8_4
  float v376; // xmm6_4
  float v377; // xmm7_4
  float v378; // xmm3_4
  float v379; // xmm5_4
  float v380; // xmm11_4
  float v381; // xmm7_4
  __m128 v382; // xmm2
  float v383; // xmm0_4
  __m128 v384; // xmm2
  float v385; // xmm1_4
  float v386; // xmm12_4
  float v387; // xmm1_4
  float v388; // xmm12_4
  float v389; // xmm14_4
  float v390; // xmm12_4
  __m128 v391; // xmm8
  float v392; // xmm0_4
  __m128 v393; // xmm8
  __m128 v394; // xmm1
  float v395; // xmm12_4
  __m128 v396; // xmm14
  float v397; // xmm11_4
  __m128 v398; // xmm2
  float v399; // xmm6_4
  float v400; // xmm14_4
  float v401; // xmm15_4
  __m128 v402; // xmm2
  float v403; // xmm6_4
  __m128 v404; // xmm5
  float v405; // xmm4_4
  float v406; // xmm13_4
  __m128 v407; // xmm2
  float v408; // xmm3_4
  float v409; // xmm9_4
  float v410; // xmm8_4
  float v411; // xmm3_4
  __m128 v412; // xmm4
  float v413; // xmm9_4
  float v414; // xmm8_4
  __m128 v415; // xmm2
  float v416; // xmm0_4
  __m128 v417; // xmm2
  float v418; // xmm1_4
  float v419; // xmm6_4
  float v420; // xmm1_4
  float v421; // xmm6_4
  float v422; // xmm5_4
  float v423; // xmm6_4
  __m128 v424; // xmm4
  float v425; // xmm0_4
  __m128 v426; // xmm4
  __m128 v427; // xmm1
  float v428; // xmm6_4
  float v429; // xmm5_4
  __m128 v430; // xmm12
  __m128 v431; // xmm2
  float v432; // xmm11_4
  float v433; // xmm7_4
  UFG::qQuaternion *v434; // rax
  float v435; // xmm5_4
  float v436; // xmm2_4
  float v437; // xmm3_4
  float v438; // xmm0_4
  float v439; // xmm1_4
  float v440; // xmm0_4
  float v441; // xmm3_4
  float v442; // xmm1_4
  float v443; // xmm0_4
  float v444; // xmm1_4
  float v445; // xmm7_4
  UFG::qMatrix44 *v446; // rax
  float *v447; // r13
  UFG::qVector4 v448; // xmm5
  __m128 v449; // xmm4
  UFG::qVector4 v450; // xmm2
  UFG::qVector4 v451; // xmm3
  float v452; // xmm7_4
  float v453; // xmm6_4
  float v454; // xmm0_4
  float v455; // xmm0_4
  float v456; // eax
  float v457; // xmm0_4
  __m128 v458; // xmm2
  UFG::qVector3 eye; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 desLook; // [rsp+50h] [rbp-B0h]
  char v461; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 duration; // [rsp+68h] [rbp-98h]
  UFG::qVector3 *v463; // [rsp+78h] [rbp-88h]
  float v464; // [rsp+80h] [rbp-80h]
  float v465; // [rsp+84h] [rbp-7Ch]
  UFG::qVector3 result; // [rsp+88h] [rbp-78h]
  int v467; // [rsp+94h] [rbp-6Ch]
  UFG::qVector3 axis; // [rsp+98h] [rbp-68h]
  float v469; // [rsp+A8h] [rbp-58h]
  float v470; // [rsp+ACh] [rbp-54h]
  float v471; // [rsp+B0h] [rbp-50h]
  float v472; // [rsp+B4h] [rbp-4Ch]
  float v473; // [rsp+B8h] [rbp-48h]
  float v474; // [rsp+BCh] [rbp-44h]
  float v475; // [rsp+C0h] [rbp-40h]
  float v476; // [rsp+C4h] [rbp-3Ch]
  float v477; // [rsp+C8h] [rbp-38h]
  UFG::qMatrix44 dest; // [rsp+D0h] [rbp-30h]
  UFG::qVector3 t; // [rsp+110h] [rbp+10h]
  UFG::qQuaternion a; // [rsp+120h] [rbp+20h]
  UFG::qVector3 v1; // [rsp+130h] [rbp+30h]
  UFG::qMatrix44 mat; // [rsp+140h] [rbp+40h]
  UFG::qVector3 verts; // [rsp+180h] [rbp+80h]
  float v484; // [rsp+18Ch] [rbp+8Ch]
  float v485; // [rsp+190h] [rbp+90h]
  float v486; // [rsp+194h] [rbp+94h]
  float v487; // [rsp+198h] [rbp+98h]
  float v488; // [rsp+19Ch] [rbp+9Ch]
  float v489; // [rsp+1A0h] [rbp+A0h]
  float v490; // [rsp+1A4h] [rbp+A4h]
  float v491; // [rsp+1A8h] [rbp+A8h]
  float v492; // [rsp+1ACh] [rbp+ACh]
  float v493; // [rsp+1B0h] [rbp+B0h]
  float v494; // [rsp+1B4h] [rbp+B4h]
  float v495; // [rsp+1B8h] [rbp+B8h]
  float v496; // [rsp+1BCh] [rbp+BCh]
  float v497; // [rsp+1C0h] [rbp+C0h]
  float v498; // [rsp+1C4h] [rbp+C4h]
  float v499; // [rsp+1C8h] [rbp+C8h]
  float v500; // [rsp+1CCh] [rbp+CCh]
  float v501; // [rsp+1D0h] [rbp+D0h]
  float v502; // [rsp+1D4h] [rbp+D4h]
  float v503; // [rsp+1D8h] [rbp+D8h]
  float v504; // [rsp+1DCh] [rbp+DCh]
  UFG::qMatrix44 v505; // [rsp+1E0h] [rbp+E0h]
  UFG::qVector3 newEye; // [rsp+220h] [rbp+120h]
  UFG::qQuaternion b; // [rsp+230h] [rbp+130h]
  UFG::qQuaternion v508; // [rsp+240h] [rbp+140h]
  UFG::qMatrix44 matrix44; // [rsp+250h] [rbp+150h]
  float *v510; // [rsp+340h] [rbp+240h]
  char v511; // [rsp+380h] [rbp+280h]
  float v512; // [rsp+380h] [rbp+280h]
  bool v513; // [rsp+388h] [rbp+288h]
  float v514; // [rsp+388h] [rbp+288h]
  float v515; // [rsp+388h] [rbp+288h]

  v3 = dt;
  v4 = this;
  if ( UFG::Metrics::msInstance.mSimTimeDelta <= 0.0 )
    return;
  if ( !this->mActive )
    return;
  v5 = 1;
  if ( UFG::gFlowController.mCurrentState )
  {
    if ( UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
      return;
  }
  if ( !v4->mTarget.m_pSimComponent )
    return;
  v510 = (float *)a3;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v6 = v4->mTransitionParam - (float)(UFG::ChaseCameraComponent::rTransitionToChaseParamRate * dt);
  v4->mTransitionParam = v6;
  if ( v6 <= 0.0 )
  {
    v6 = 0.0;
    goto LABEL_10;
  }
  v7 = *(float *)&FLOAT_1_0;
  if ( v6 < 1.0 )
LABEL_10:
    v7 = v6;
  v8 = v4->mLockEye == 0;
  v4->mTransitionParam = v7;
  v9 = v4->mTarget.m_pSimComponent->vfptr;
  if ( v8 )
  {
    ((void (*)(void))v9[28].__vecDelDtor)();
    v10 = *(float *)&FLOAT_1_0;
    v13 = (float)(v7 - 4.0) * 0.33333334;
    if ( v13 <= 0.0 )
    {
      v13 = 0.0;
    }
    else if ( v13 >= 1.0 )
    {
      v13 = *(float *)&FLOAT_1_0;
    }
    v12 = (float)(v13 * 0.49999994) + 0.80000001;
  }
  else
  {
    ((void (*)(void))v9[28].__vecDelDtor)();
    v10 = *(float *)&FLOAT_1_0;
    v11 = (float)(v7 - 4.0) * 0.33333334;
    if ( v11 <= 0.0 )
    {
      v11 = 0.0;
    }
    else if ( v11 >= 1.0 )
    {
      v11 = *(float *)&FLOAT_1_0;
    }
    v12 = 1.7 - (float)(v11 * 1.3000001);
  }
  if ( !v4->mLockEye )
    v10 = 0.0;
  UFG::qApproach(&v4->mLockEyeParam, v10, v12, v3);
  if ( v4->mLockLook )
    v14 = *(float *)&FLOAT_1_0;
  else
    v14 = 0.0;
  UFG::qApproach(&v4->mLockLookParam, v14, 0.80000001, v3);
  v15 = *(float *)&FLOAT_1_0;
  v16 = v4->mTransitionParamEye - v3;
  v17 = v16;
  v4->mTransitionParamEye = v16;
  if ( v16 <= 0.0 )
  {
    v17 = 0.0;
  }
  else if ( v16 >= 1.0 )
  {
    v17 = *(float *)&FLOAT_1_0;
  }
  v18 = v4->mTransitionParamOrient;
  v4->mTransitionParamEye = v17;
  v19 = v18 - v3;
  v20 = v19;
  v4->mTransitionParamOrient = v19;
  if ( v19 <= 0.0 )
  {
    v20 = 0.0;
    goto LABEL_35;
  }
  if ( v19 < 1.0 )
LABEL_35:
    v15 = v20;
  v4->mTransitionParamOrient = v15;
  UFG::GameCameraComponent::Update((UFG::GameCameraComponent *)&v4->vfptr, v3);
  v21 = v4->mBlendSeconds;
  if ( v21 > 0.0 )
    v4->mBlendPrevious = v4->mBlendPrevious - (float)(v3 / v21);
  if ( v4->mBlendPrevious < 0.0 )
    *(_QWORD *)&v4->mBlendPrevious = 0i64;
  v22 = *(UFG::SimObjectCVBase **)&v4->mTarget.m_pSimComponent[13].m_Flags;
  if ( v22 )
  {
    v24 = v22->m_Flags;
    if ( (v24 >> 14) & 1 )
    {
      v23 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v22);
    }
    else if ( (v24 & 0x8000u) == 0 )
    {
      if ( (v24 >> 13) & 1 )
      {
        v23 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v22->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else if ( (v24 >> 12) & 1 )
      {
        v23 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v22->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else
      {
        v23 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v22->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v23 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v22);
    }
  }
  else
  {
    v23 = 0i64;
  }
  v4->mTargetingSystem = v23;
  if ( v3 > 0.0 )
    UFG::ChaseCameraComponent::AutoLockUnlock(v4, v3, 0.0);
  v25 = v4->mTargetingSystem;
  if ( !v25 || (unsigned int)(v25->m_eFocusMode - 3) > 1 && v25->m_eFocusMode != 2 )
  {
    v26 = 0;
    goto LABEL_59;
  }
  v26 = 1;
  if ( v4->mAimOrFocus )
  {
LABEL_59:
    v511 = 0;
    goto LABEL_60;
  }
  v511 = 1;
LABEL_60:
  if ( !v4->mAimOrFocus || v26 )
    v5 = 0;
  v461 = v5;
  v4->mAimOrFocus = v26;
  if ( v26 )
    v27 = *(float *)&FLOAT_1_0;
  else
    v27 = 0.0;
  UFG::qApproach(&v4->mAimParam, v27, 4.75, v3);
  if ( v5 )
    UFG::ChaseCameraComponent::GotoAngleSnap(v4, 0.0, 0);
  UFG::ChaseCameraComponent::DetermineChaseParameters(v4);
  v28 = (int *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)();
  v29 = v4->mTarget.m_pSimComponent;
  v475 = *(float *)v28;
  v476 = *((float *)v28 + 1);
  v30 = *((float *)v28 + 2);
  v31 = v29->vfptr;
  v474 = v30;
  v32 = ((__int64 (*)(void))v31[20].__vecDelDtor)();
  v33 = *(float *)v32;
  v34 = (__m128)*(unsigned int *)(v32 + 4);
  v35 = *(float *)(v32 + 8);
  v36 = (float *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)();
  v37 = *v36;
  v38 = v36[1];
  v34.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v33 * v33)) + (float)(v35 * v35);
  LODWORD(v39) = (unsigned __int128)_mm_sqrt_ps(v34);
  v473 = v39;
  v40 = v39;
  if ( UFG::ChaseCameraComponent::bOverrideSpeedInput )
    v40 = UFG::ChaseCameraComponent::mOverrideSpeed;
  v41 = v4->mTargetingSystem;
  v42 = FLOAT_0_40000001;
  v43 = FLOAT_0_40000001;
  v44 = v41 && ((unsigned int)(v41->m_eFocusMode - 3) <= 1 || v41->m_eFocusMode == 2);
  v45 = v4->pChaseParameters;
  v513 = v44;
  if ( v45 && v45->mContext == eCHASE_CONTEXT_AIM )
  {
    if ( v44 )
      v42 = v4->mAimFreeDuration;
    else
      v42 = v4->mAimLockedDuration;
    v43 = v42;
  }
  v46 = v4->mYawAngVelTimespan;
  if ( v46 != v4->mYawAngVelSubmittedTimespan )
  {
    UFG::qAverageWindow<float>::SetTimespan(&v4->mYawAngVelWindow, v46, 30.0);
    v4->mYawAngVelSubmittedTimespan = v4->mYawAngVelTimespan;
  }
  v47 = UFG::ChaseCameraComponent::rTransitionToChaseEyeLookSupplimentaryDuration * v4->mTransitionParam;
  duration.x = v47 + v43;
  duration.y = v47 + v43;
  duration.z = v47 + v43;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mLook, &duration);
  duration.x = v47 + v42;
  duration.y = v47 + v42;
  duration.z = v47 + v42;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mEye, &duration);
  duration.x = 0.02;
  duration.y = 0.02;
  duration.z = 0.02;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mAimLook, &duration);
  duration.x = 0.02;
  duration.y = 0.02;
  duration.z = 0.02;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mAimEye, &duration);
  v48 = UFG::ChaseCameraComponent::mFovDuration + v47;
  v49 = v4->mFov.mParameter / v4->mFov.mDuration;
  v4->mFov.mParameter = v49;
  if ( v48 <= 0.0099999998 )
    v48 = FLOAT_0_0099999998;
  v4->mFov.mDuration = v48;
  v4->mFov.mParameter = v48 * v49;
  UFG::HomerCubic<float>::MakeCoeffs(&v4->mFov);
  duration.x = 1.0;
  duration.y = 1.0;
  duration.z = 1.0;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mUp, &duration);
  v50 = v4->mTargetPitch.mParameter / v4->mTargetPitch.mDuration;
  v4->mTargetPitch.mParameter = v50;
  v51 = UFG::ChaseCameraComponent::mTargetPitchDuration;
  if ( UFG::ChaseCameraComponent::mTargetPitchDuration <= 0.0099999998 )
    v51 = FLOAT_0_0099999998;
  v4->mTargetPitch.mDuration = v51;
  v4->mTargetPitch.mParameter = v51 * v50;
  UFG::HomerCubic<float>::MakeCoeffs(&v4->mTargetPitch);
  if ( v4->mTarget.m_pSimComponent && (v52 = *(UFG::SimObjectCVBase **)&v4->mTarget.m_pSimComponent[13].m_Flags) != 0i64 )
  {
    v53 = v52->m_Flags;
    if ( (v53 >> 14) & 1 )
    {
      v54 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v52);
    }
    else if ( (v53 & 0x8000u) == 0 )
    {
      if ( (v53 >> 13) & 1 )
      {
        v54 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v52->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else if ( (v53 >> 12) & 1 )
      {
        v54 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v52->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
      else
      {
        v54 = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v52->vfptr,
                                                          UFG::TargetingSystemPedPlayerComponent::_TypeUID);
      }
    }
    else
    {
      v54 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v52);
    }
  }
  else
  {
    v54 = 0i64;
  }
  if ( v54 )
    v55 = v54->m_pEquippedSOWPC.m_pPointer;
  else
    v55 = 0i64;
  v56 = UFG::tbRecoilUseTweakables || !v55;
  v57 = v4->mRecoilAngleDesired;
  if ( v56 )
  {
    if ( v57 <= 0.0 )
      v58 = UFG::trRecoilKickupRateDecay;
    else
      v58 = UFG::trRecoilKickupRateAttack;
    v59 = UFG::trRecoilKickbackDur;
  }
  else
  {
    v60 = *((_QWORD *)&v55[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(v55[2].m_pSimObject));
    v58 = *(float *)(v60 + 428);
    v59 = *(float *)(v60 + 444);
  }
  if ( UFG::qApproach(&v4->mRecoilAngle, v57, (float)(v58 * 3.1415927) * 0.0055555557, v3) )
  {
    if ( v4->mRecoilAngleDesired > 0.0 )
      v4->mRecoilAngleDesired = 0.0;
    if ( 0.0 == v4->mRecoilAngleDesired && v4->mRecoilAngle > 0.0 )
      UFG::GameCameraComponent::ResetAimWobble((UFG::GameCameraComponent *)&v4->vfptr);
  }
  duration.x = v59;
  duration.y = v59;
  duration.z = v59;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&v4->mRecoilEye, &duration);
  v61 = atan2f(v38, v37);
  v62 = v4->mForwardAngle - v61;
  for ( v4->mForwardAngleDesired = v61; v62 > 3.1415927; v62 = v62 + -6.2831855 )
    ;
  for ( ; v62 < -3.1415927; v62 = v62 + 6.2831855 )
    ;
  v63 = (float)(v39 - v4->mCenteringSpeedMin) / (float)(v4->mCenteringSpeedMax - v4->mCenteringSpeedMin);
  if ( v63 <= 0.0 )
  {
    v63 = 0.0;
  }
  else
  {
    v64 = *(float *)&FLOAT_1_0;
    if ( v63 >= 1.0 )
      goto LABEL_127;
  }
  v64 = v63;
LABEL_127:
  UFG::qApproachAngle(&v4->mForwardAngle, v61, COERCE_FLOAT(LODWORD(v62) & _xmm) * (float)(v64 * 10.0), v3);
  NormAngle(&v4->mForwardAngle);
  v65 = (float *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[14].__vecDelDtor)();
  v66 = v4->mForwardAngle;
  v67 = *v65;
  v68 = v65[1];
  v69 = v65[2];
  v464 = cosf(v4->mForwardAngle);
  v70 = sinf(v66);
  if ( v4->mUpdateEyeOffset )
  {
    *(_QWORD *)&duration.z = (char *)v4 + 1384;
    LODWORD(duration.x) = 3;
    v463 = v4->mEyeOffsetRange;
    v71 = UFG::LinearGraph<UFG::qVector3>::GetValue((UFG::LinearGraph<UFG::qVector3> *)&duration, &result, v40);
    v72 = v71->y;
    v73 = v71->z;
    v4->mEyeOffset.x = v71->x;
    v4->mEyeOffset.y = v72;
    v4->mEyeOffset.z = v73;
  }
  *(_QWORD *)&duration.z = (char *)v4 + 1432;
  LODWORD(duration.x) = 3;
  v463 = v4->mTargetOffsetRange;
  v74 = UFG::LinearGraph<UFG::qVector3>::GetValue((UFG::LinearGraph<UFG::qVector3> *)&duration, &result, v40);
  v75 = FLOAT_0_000099999997;
  v76 = v74->y;
  v77 = v74->z;
  v4->mTargetOffset.x = v74->x;
  v4->mTargetOffset.y = v76;
  v4->mTargetOffset.z = v77;
  v78 = v4->mFovRamp.x;
  v79 = v4->mFovRamp.z;
  v80 = v4->mFovRamp.w;
  if ( (float)(v4->mFovRamp.y - v78) >= 0.000099999997 )
    v75 = v4->mFovRamp.y - v78;
  if ( v40 <= v78 )
    v81 = v4->mFovRamp.x;
  else
    v81 = v40;
  if ( v81 >= v4->mFovRamp.y )
    v81 = v4->mFovRamp.y;
  v82 = sinf((float)(v81 - v78) * (float)(1.5707964 / v75));
  v4->mFov.p1 = (float)((float)(v80 - v79) * (float)(v82 * v82)) + v79;
  UFG::HomerCubic<float>::MakeCoeffs(&v4->mFov);
  v83 = (__m128)LODWORD(v464);
  v84 = 0;
  v4->mFov.mParameter = 0.0;
  v86 = v83;
  v85 = (float)(v68 * 0.0) - (float)(v70 * v69);
  v86.m128_f32[0] = (float)(v83.m128_f32[0] * v69) - (float)(v67 * 0.0);
  v88 = v86;
  v87 = (float)(v70 * v67) - (float)(v83.m128_f32[0] * v68);
  v88.m128_f32[0] = (float)((float)(v86.m128_f32[0] * v86.m128_f32[0]) + (float)(v85 * v85)) + (float)(v87 * v87);
  if ( v88.m128_f32[0] == 0.0 )
    v89 = 0.0;
  else
    v89 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v88));
  v90 = v89;
  v91 = v89;
  v92 = v89 * v87;
  v93 = v90 * v85;
  v94 = v91 * v86.m128_f32[0];
  if ( !v4->mIsLookingAround )
    v84 = COERCE_UNSIGNED_INT(v92 * UFG::gChaseWallDutch) ^ _xmm[0];
  UFG::HomerCubicAngular::SetDesiredPosition(&v4->mDutch, *(const float *)&v84);
  if ( (UFG::VehicleSubjectComponent::IsDoingWheelie((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent)
     || UFG::VehicleSubjectComponent::IsInAir((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent))
    && !v4->mIsLookingAround )
  {
    LODWORD(v95) = 0;
  }
  else
  {
    v95 = *(unsigned int *)(((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)() + 8);
    UFG::qASin(*(float *)&v95);
  }
  v96 = v4->mPitchOffsetMax;
  v97 = v96;
  v98 = (float)(v96 * -3.1415927) * 0.0055555557;
  v99 = (float)(v97 * 3.1415927) * 0.0055555557;
  if ( *(float *)&v95 <= v98 )
    *(float *)&v95 = v98;
  if ( *(float *)&v95 >= v99 )
    *(float *)&v95 = v99;
  LODWORD(v4->mTargetPitch.p1) = v95;
  UFG::HomerCubic<float>::MakeCoeffs(&v4->mTargetPitch);
  v4->mTargetPitch.mParameter = 0.0;
  UFG::ChaseCameraComponent::UpdateTargeting(v4);
  if ( v511 )
  {
    v100 = v4->mAimEye.p1.y;
    v101 = v4->mAimEye.p1.z;
    v4->mAimEye.p0.x = v4->mAimEye.p1.x;
    v4->mAimEye.p0.y = v100;
    v4->mAimEye.p0.z = v101;
    v102 = v4->mAimEye.v1.y;
    v103 = v4->mAimEye.v1.z;
    v4->mAimEye.v0.x = v4->mAimEye.v1.x;
    v4->mAimEye.v0.y = v102;
    v4->mAimEye.v0.z = v103;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mAimEye);
    *(_QWORD *)&v4->mAimEye.mParameter.x = 0i64;
    v4->mAimEye.mParameter.z = 0.0;
    v104 = v4->mAimLook.p1.x;
    v105 = v4->mAimLook.p1.z;
    v4->mAimLook.p0.y = v4->mAimLook.p1.y;
    v4->mAimLook.p0.z = v105;
    v4->mAimLook.p0.x = v104;
    v106 = v4->mAimLook.v1.y;
    v107 = v4->mAimLook.v1.z;
    v4->mAimLook.v0.x = v4->mAimLook.v1.x;
    v4->mAimLook.v0.y = v106;
    v4->mAimLook.v0.z = v107;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mAimLook);
    *(_QWORD *)&v4->mAimLook.mParameter.x = 0i64;
    v4->mAimLook.mParameter.z = 0.0;
  }
  UFG::HomerCubic<UFG::qVector3>::Update(&v4->mAimEye, v3);
  UFG::HomerCubic<UFG::qVector3>::Update(&v4->mAimLook, v3);
  v108 = v4->mAimEye.p0.x + v4->mRecoilEye.p0.x;
  v109 = v4->mAimEye.p0.y + v4->mRecoilEye.p0.y;
  v110 = v4->mAimEye.p0.z + v4->mRecoilEye.p0.z;
  v111 = (float *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)();
  v112 = v4->mTarget.m_pSimComponent;
  v113 = v109;
  v114 = v109;
  v115 = v108;
  v116 = (float)(v109 * v111[6]) + (float)(v108 * v111[2]);
  v117 = (float)((float)((float)(v114 * v111[4]) + (float)(v108 * *v111)) + (float)(v110 * v111[8])) + v111[12];
  v118 = v4->mAimLook.p0.x;
  v119 = v110 * v111[9];
  v120 = v116 + (float)(v110 * v111[10]);
  v121 = v4->mAimLook.p0.z;
  v122 = v120 + v111[14];
  v123 = (float)((float)(v113 * v111[5]) + (float)(v115 * v111[1])) + v119;
  v471 = v117;
  v124 = v123 + v111[13];
  v465 = v122;
  v125 = (__m128)LODWORD(v4->mAimLook.p0.y);
  v512 = v124;
  v126 = (float *)((__int64 (*)(void))v112->vfptr[18].__vecDelDtor)();
  v127 = v125;
  v127.m128_f32[0] = v125.m128_f32[0] * v126[5];
  v128 = (float)((float)((float)(v125.m128_f32[0] * v126[4]) + (float)(v118 * *v126)) + (float)(v121 * v126[8]))
       + v126[12];
  v125.m128_f32[0] = (float)(v125.m128_f32[0] * v126[6]) + (float)(v118 * v126[2]);
  v127.m128_f32[0] = v127.m128_f32[0] + (float)(v118 * v126[1]);
  v470 = v128;
  v129 = v128 - v117;
  v127.m128_f32[0] = (float)(v127.m128_f32[0] + (float)(v121 * v126[9])) + v126[13];
  v130 = (float)(v125.m128_f32[0] + (float)(v121 * v126[10])) + v126[14];
  v131 = v127;
  v131.m128_f32[0] = v127.m128_f32[0] - v512;
  v132 = v130 - v465;
  v469 = v127.m128_f32[0];
  v472 = v130;
  v133 = FLOAT_0_000099999997;
  if ( (float)((float)((float)(v131.m128_f32[0] * v131.m128_f32[0]) + (float)(v129 * v129)) + (float)(v132 * v132)) > 0.000099999997 )
  {
    v135 = v131;
    v134 = 0.0;
    v135.m128_f32[0] = (float)((float)(v131.m128_f32[0] * v131.m128_f32[0]) + (float)(v129 * v129))
                     + (float)(v132 * v132);
    if ( v135.m128_f32[0] != 0.0 )
      v134 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v135));
    v136 = LODWORD(v4->mRecoilAngle) ^ _xmm[0];
    duration.z = 0.0;
    duration.x = v134 * v131.m128_f32[0];
    LODWORD(duration.y) = COERCE_UNSIGNED_INT(v134 * v129) ^ _xmm[0];
    UFG::qRotationMatrixAxis(&dest, &duration, *(float *)&v136);
    v133 = FLOAT_0_000099999997;
    v470 = v471
         + (float)((float)((float)((float)(dest.v1.x * v131.m128_f32[0]) + (float)(dest.v0.x * v129))
                         + (float)(dest.v2.x * v132))
                 + dest.v3.x);
    v469 = (float)((float)((float)((float)(dest.v1.y * v131.m128_f32[0]) + (float)(dest.v0.y * v129))
                         + (float)(dest.v2.y * v132))
                 + dest.v3.y)
         + v512;
    v130 = (float)((float)((float)((float)(dest.v1.z * v131.m128_f32[0]) + (float)(dest.v0.z * v129))
                         + (float)(dest.v2.z * v132))
                 + dest.v3.z)
         + v465;
    v472 = (float)((float)((float)((float)(dest.v1.z * v131.m128_f32[0]) + (float)(dest.v0.z * v129))
                         + (float)(dest.v2.z * v132))
                 + dest.v3.z)
         + v465;
  }
  v137 = v4->mNoiseMagnitudeRamp.x;
  v138 = v4->mNoiseMagnitudeRamp.z;
  v139 = v4->mNoiseMagnitudeRamp.w;
  if ( (float)(v4->mNoiseMagnitudeRamp.y - v137) >= v133 )
    v133 = v4->mNoiseMagnitudeRamp.y - v137;
  if ( v40 <= v137 )
    v140 = v4->mNoiseMagnitudeRamp.x;
  else
    v140 = v40;
  if ( v140 >= v4->mNoiseMagnitudeRamp.y )
    v140 = v4->mNoiseMagnitudeRamp.y;
  v141 = sinf((float)(v140 - v137) * (float)(1.5707964 / v133));
  v142 = (float)((float)(v141 * v141) * (float)(v139 - v138)) + v138;
  if ( v142 > 0.0 )
  {
    v143 = v470;
    v144 = v469;
    duration.x = v470;
    duration.y = v469;
    duration.z = v130;
    v145 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(&v4->mLookNoise, &result, &duration);
    v146 = v142 * v145->y;
    v147 = v142 * v145->z;
    v470 = v143 + (float)(v142 * v145->x);
    v148 = v465;
    v469 = v144 + v146;
    v149 = v471;
    v472 = v130 + v147;
    duration.x = v471;
    duration.y = v512;
    duration.z = v465;
    v150 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(&v4->mEyeNoise, &result, &duration);
    v151 = v142 * v150->x;
    v512 = (float)(v142 * v150->y) + v512;
    v465 = (float)(v142 * v150->z) + v148;
    v471 = v149 + v151;
  }
  if ( UFG::VehicleSubjectComponent::IsDoingWheelie((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent)
    || UFG::ChaseCameraComponent::mWheelieOverride )
  {
    if ( v4->mUpdateEyeOffset )
      v4->mEyeOffset.z = UFG::ChaseCameraComponent::mWheelieEyeZOffset + v4->mEyeOffset.z;
    v4->mTargetOffset.z = UFG::ChaseCameraComponent::mWheelieLookZOffset + v4->mTargetOffset.z;
  }
  if ( (UFG::ChaseCameraComponent::mInAirOverride
     || UFG::VehicleSubjectComponent::IsInAir((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent))
    && !UFG::VehicleSubjectComponent::IsDoingWheelie((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent)
    && *(float *)(((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)() + 8) > -0.5 )
  {
    if ( v4->mUpdateEyeOffset )
      v4->mEyeOffset.z = v4->mInAirEyeZOffset + v4->mEyeOffset.z;
    v4->mTargetOffset.z = v4->mInAirLookZOffset + v4->mTargetOffset.z;
  }
  if ( v4->pChaseParameters == (UFG::ChaseCameraParameters *)v4->mTarget.m_pSimComponent[15].vfptr && !v4->mHijackerLeft )
    v4->mEyeOffset.y = v4->mEyeOffset.y * -1.0;
  v152 = v4->mEyeOffset.y;
  v153 = v4->mEyeOffset.z;
  v154 = &v4->mEye.mDuration.x;
  v154[21] = v4->mEyeOffset.x;
  v154[22] = v152;
  v154[23] = v153;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mEye);
  v155 = &v4->mLook.mDuration.x;
  *(_QWORD *)&v4->mEye.mParameter.x = 0i64;
  v4->mEye.mParameter.z = 0.0;
  v156 = v4->mTargetOffset.x;
  v157 = v4->mTargetOffset.z;
  v155[22] = v4->mTargetOffset.y;
  v155[23] = v157;
  v155[21] = v156;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mLook);
  *(_QWORD *)&v4->mLook.mParameter.x = 0i64;
  v4->mLook.mParameter.z = 0.0;
  v158 = (float)((float)((float)(v94 * 0.0) + (float)(v93 * 0.0)) + (float)(v92 * 0.0)) * 2.0;
  v159 = v158;
  LODWORD(v160) = COERCE_UNSIGNED_INT(v158 * v92) ^ _xmm[0] ^ _xmm[0];
  LODWORD(v161) = COERCE_UNSIGNED_INT((float)((float)((float)((float)(v94 * 0.0) + (float)(v93 * 0.0))
                                                    + (float)(v92 * 0.0))
                                            * 2.0) * v94) ^ _xmm[0] ^ _xmm[0];
  LODWORD(v162) = COERCE_UNSIGNED_INT(v159 * v93) ^ _xmm[0] ^ _xmm[0];
  v163 = fsqrt((float)((float)(v161 * v161) + (float)(v162 * v162)) + (float)(v160 * v160));
  if ( v163 > 1.0 )
  {
    v162 = v162 * (float)(1.0 / v163);
    v161 = v161 * (float)(1.0 / v163);
    v160 = v160 * (float)(1.0 / v163);
  }
  v164 = v4->mTilt * 0.25;
  v4->mUp.p1.z = (float)(v164 * v160) + 1.0;
  v4->mUp.p1.x = v164 * v162;
  v4->mUp.p1.y = v164 * v161;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mUp);
  *(_QWORD *)&v4->mUp.mParameter.x = 0i64;
  v4->mUp.mParameter.z = 0.0;
  if ( v4->mIsLookingAround )
  {
    *(_QWORD *)&v4->mUp.p1.x = 0i64;
    v4->mUp.p1.z = 1.0;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&v4->mUp);
    *(_QWORD *)&v4->mUp.mParameter.x = 0i64;
    v4->mUp.mParameter.z = 0.0;
  }
  if ( v3 > 0.0 )
    UFG::qAverageWindow<float>::AddValue(&v4->mYawAngVelWindow, *(float *)&v4->mTarget.m_pSimComponent[9].m_TypeUID, v3);
  UFG::HomerCubic<UFG::qVector3>::Update(&v4->mUp, v3);
  UFG::HomerCubic<float>::Update(&v4->mFov, v3);
  UFG::HomerCubicAngular::Update(&v4->mDutch, v3);
  v165 = v4->mUp.p0.y;
  v166 = v4->mUp.p0.z;
  v167 = v4->mUp.p0.x;
  v168 = (__m128)LODWORD(v4->mUp.p0.y);
  v170 = (__m128)LODWORD(v464);
  v168.m128_f32[0] = (float)(v168.m128_f32[0] * 0.0) - (float)(v70 * v166);
  v169 = (float)(v70 * v167) - (float)(v464 * v165);
  v173 = v168;
  v170.m128_f32[0] = (float)(v464 * v166) - (float)(v4->mUp.p0.x * 0.0);
  v171 = (float)(v170.m128_f32[0] * v166) - (float)(v169 * v165);
  v172 = (float)(v169 * v167) - (float)(v168.m128_f32[0] * v166);
  v173.m128_f32[0] = (float)(v168.m128_f32[0] * v165) - (float)(v170.m128_f32[0] * v167);
  v175 = v173;
  v174 = (float)(v172 * v169) - (float)(v173.m128_f32[0] * v170.m128_f32[0]);
  axis.x = (float)(v172 * v169) - (float)(v173.m128_f32[0] * v170.m128_f32[0]);
  v175.m128_f32[0] = (float)(v173.m128_f32[0] * v168.m128_f32[0]) - (float)(v171 * v169);
  axis.y = (float)(v173.m128_f32[0] * v168.m128_f32[0]) - (float)(v171 * v169);
  v176 = (float)(v171 * v170.m128_f32[0]) - (float)(v172 * v168.m128_f32[0]);
  axis.z = (float)(v171 * v170.m128_f32[0]) - (float)(v172 * v168.m128_f32[0]);
  v177 = (float)((float)(v172 * v172) + (float)(v171 * v171)) + (float)(v173.m128_f32[0] * v173.m128_f32[0]);
  if ( v177 == 0.0 )
    v178 = 0.0;
  else
    v178 = 1.0 / fsqrt(v177);
  v179 = (signed __int64)&v4->mTargetWorld;
  v180 = v178 * v171;
  v181 = v170;
  *(_DWORD *)(v179 + 12) = 0;
  *(float *)(v179 + 8) = v178 * v173.m128_f32[0];
  *(float *)(v179 + 4) = v178 * v172;
  *(float *)v179 = v180;
  v181.m128_f32[0] = (float)((float)(v170.m128_f32[0] * v170.m128_f32[0]) + (float)(v168.m128_f32[0] * v168.m128_f32[0]))
                   + (float)(v169 * v169);
  if ( v181.m128_f32[0] == 0.0 )
    v182 = 0.0;
  else
    v182 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v181));
  v183 = v175;
  v4->mTargetWorld.v1.w = 0.0;
  v4->mTargetWorld.v1.z = v182 * v169;
  v4->mTargetWorld.v1.y = v182 * v170.m128_f32[0];
  v4->mTargetWorld.v1.x = v182 * v168.m128_f32[0];
  v183.m128_f32[0] = (float)((float)(v175.m128_f32[0] * v175.m128_f32[0]) + (float)(v174 * v174)) + (float)(v176 * v176);
  if ( v183.m128_f32[0] == 0.0 )
    v184 = 0.0;
  else
    v184 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v183));
  v4->mTargetWorld.v2.w = 0.0;
  v185 = v184;
  v186 = v184;
  v4->mTargetWorld.v2.z = v184 * v176;
  v187 = v474;
  v4->mTargetWorld.v2.x = v185 * v174;
  v188 = v476;
  v4->mTargetWorld.v2.y = v186 * v175.m128_f32[0];
  v4->mTargetWorld.v3.w = 1.0;
  v189 = v475;
  v4->mTargetWorld.v3.y = v188;
  v4->mTargetWorld.v3.z = v187;
  v4->mTargetWorld.v3.x = v189;
  v190 = v4->mTargetWorld.v1;
  v191 = v4->mTargetWorld.v2;
  v192 = v4->mTargetWorld.v3;
  v4->mEyeWorld.v0 = *(UFG::qVector4 *)v179;
  v4->mEyeWorld.v1 = v190;
  v4->mEyeWorld.v2 = v191;
  v4->mEyeWorld.v3 = v192;
  UFG::qInverseAffine(&v4->mWorldEye, (UFG::qMatrix44 *)v179);
  v4->mUpdateEyeOffset = 1;
  UFG::HomerCubic<UFG::qVector3>::Update(&v4->mEye, v3);
  UFG::HomerCubic<UFG::qVector3>::Update(&v4->mLook, v3);
  UFG::HomerCubic<float>::Update(&v4->mTargetPitch, v3);
  UFG::HomerCubic<UFG::qVector3>::Update(&v4->mRecoilEye, v3);
  if ( v4->mSnapNext )
  {
    v4->mSnapNext = 0;
    UFG::ChaseCameraComponent::Snap(v4);
  }
  v193 = v4->mTarget.m_pSimComponent;
  v194 = v4->mEye.p0.x + v4->mRecoilEye.p0.x;
  v195 = v4->mEye.p0.z + v4->mRecoilEye.p0.z;
  v196 = v4->mEye.p0.y + v4->mRecoilEye.p0.y;
  v197 = LODWORD(v4->mLook.p0.y);
  v198 = v4->mLook.p0.z;
  v199 = (float)((float)(v196 * v4->mEyeWorld.v1.x) + (float)(v194 * v4->mEyeWorld.v0.x))
       + (float)(v195 * v4->mEyeWorld.v2.x);
  v200 = (float)(v196 * v4->mEyeWorld.v1.z) + (float)(v194 * v4->mEyeWorld.v0.z);
  v201 = (float)(v196 * v4->mEyeWorld.v1.y) + (float)(v194 * v4->mEyeWorld.v0.y);
  eye.x = v199 + v4->mEyeWorld.v3.x;
  v202 = (float)(v201 + (float)(v195 * v4->mEyeWorld.v2.y)) + v4->mEyeWorld.v3.y;
  eye.z = (float)(v200 + (float)(v195 * v4->mEyeWorld.v2.z)) + v4->mEyeWorld.v3.z;
  v203 = v4->mLook.p0.x;
  eye.y = v202;
  v204 = (float *)((__int64 (*)(void))v193->vfptr[18].__vecDelDtor)();
  v206 = v197;
  v205 = (float)((float)((float)(*(float *)&v197 * v204[4]) + (float)(v203 * *v204)) + (float)(v198 * v204[8]))
       + v204[12];
  *(float *)&v206 = (float)((float)((float)(*(float *)&v197 * v204[5]) + (float)(v203 * v204[1]))
                          + (float)(v198 * v204[9]))
                  + v204[13];
  v207 = (float)((float)((float)(*(float *)&v197 * v204[6]) + (float)(v203 * v204[2])) + (float)(v198 * v204[10]))
       + v204[14];
  LODWORD(desLook.y) = v206;
  desLook.x = v205;
  desLook.z = v207;
  if ( UFG::ChaseCameraComponent::bOverrideSpeedInput )
  {
    v208 = UFG::ChaseCameraComponent::mOverrideSpeed;
  }
  else
  {
    v207 = desLook.z;
    v206 = LODWORD(desLook.y);
    v205 = desLook.x;
    v208 = UFG::VehicleSubjectComponent::GetForwardSpeed((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent);
  }
  v209 = *(float *)&FLOAT_1_0;
  v210 = COERCE_FLOAT(LODWORD(v208) & _xmm) / UFG::ChaseCameraComponent::mYawAngularSpeedThreshold;
  if ( v210 <= 0.0 )
  {
    v210 = 0.0;
  }
  else if ( v210 >= 1.0 )
  {
    v210 = *(float *)&FLOAT_1_0;
  }
  if ( v4->mYawAngVelWindow.m_StartIndex == v4->mYawAngVelWindow.m_EndIndex )
  {
    v211 = 0.0;
  }
  else
  {
    v212 = v4->mYawAngVelWindow.m_RunningSumTime;
    if ( v212 > 0.0 )
      v211 = v4->mYawAngVelWindow.m_RunningSum / v212;
    else
      v211 = FLOAT_3_4028235e38;
  }
  v213 = (float)(COERCE_FLOAT(LODWORD(v211) & _xmm)
               - (float)((float)(v4->mLookOffsetAngVelMin * 3.1415927) * 0.0055555557))
       / (float)((float)((float)(v4->mLookOffsetAngVelMax * 3.1415927) * 0.0055555557)
               - (float)((float)(v4->mLookOffsetAngVelMin * 3.1415927) * 0.0055555557));
  if ( v213 <= 0.0 )
  {
    v213 = 0.0;
  }
  else if ( v213 >= 1.0 )
  {
    v213 = *(float *)&FLOAT_1_0;
  }
  v214 = (float)(v213 * 3.1415927) - 1.5707964;
  if ( v4->mYawAngVelWindow.m_StartIndex == v4->mYawAngVelWindow.m_EndIndex )
    goto LABEL_420;
  v215 = v4->mYawAngVelWindow.m_RunningSumTime;
  if ( v215 <= 0.0 || (v216 = v4->mYawAngVelWindow.m_RunningSum / v215, v216 > 0.0) )
  {
    v217 = *(float *)&FLOAT_1_0;
    goto LABEL_220;
  }
  if ( v216 >= 0.0 )
  {
LABEL_420:
    v217 = 0.0;
    goto LABEL_220;
  }
  v217 = FLOAT_N1_0;
LABEL_220:
  v218 = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(sinf(v214) + 1.0) * 0.5) * v217) ^ _xmm[0])
       * (float)(v210 * v4->mLookOffsetMax);
  if ( !UFG::ChaseCameraComponent::bEnableAngVelOffset || !v4->mIsLookingAround )
    v218 = 0.0;
  v219 = v4->mTargetPitch.p0;
  if ( v219 <= 0.0 )
    v220 = v4->mPitchOffsetLookFactorDown;
  else
    v220 = v4->mPitchOffsetLookFactorUp;
  v464 = COERCE_FLOAT(LODWORD(v219) & _xmm) * v220;
  if ( v219 <= 0.0 )
    v221 = v4->mPitchOffsetEyeFactorDown;
  else
    v221 = v4->mPitchOffsetEyeFactorUp;
  v222 = COERCE_FLOAT(LODWORD(v219) & _xmm) * v221;
  if ( v4->mIsLookingAround || v4->mAimOrFocus || !UFG::ChaseCameraComponent::bEnablePitchOffset )
  {
    v464 = 0.0;
    v222 = 0.0;
  }
  v225 = (__m128)v206;
  v223 = &v4->mLookupMouse;
  v224 = v205 - eye.x;
  v225.m128_f32[0] = *(float *)&v206 - eye.y;
  v226 = v207 - eye.z;
  v227 = 0.0;
  v228 = v222 + v4->mLookupMouse;
  if ( (float)((float)((float)(v225.m128_f32[0] * v225.m128_f32[0]) + (float)(v224 * v224)) + (float)(v226 * v226)) > 0.000099999997 )
  {
    v229 = v225;
    v229.m128_f32[0] = (float)((float)(v225.m128_f32[0] * v225.m128_f32[0]) + (float)(v224 * v224))
                     + (float)(v226 * v226);
    if ( v229.m128_f32[0] == 0.0 )
      v230 = 0.0;
    else
      v230 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v229));
    v231 = v230;
    v227 = v230 * v225.m128_f32[0];
    v209 = v231 * v224;
  }
  v232 = v205 + (float)((float)((float)(v209 * 0.0) + (float)(v227 * v218)) + (float)(v464 * 0.0));
  desLook.x = v232;
  v233 = v207 + (float)((float)(v218 * 0.0) + v464);
  eye.z = eye.z + v228;
  v234 = *(float *)&v206
       + (float)((float)((float)(v227 * 0.0) + (float)(v218 * COERCE_FLOAT(LODWORD(v209) ^ _xmm[0])))
               + (float)(v464 * 0.0));
  desLook.z = v233;
  desLook.y = v234;
  if ( v513 )
  {
    UFG::ChaseCameraComponent::RestrictOrbitHeight(v4, &eye);
    v233 = desLook.z;
    v234 = desLook.y;
    v232 = desLook.x;
  }
  v235 = FLOAT_0_000099999997;
  if ( !v4->mAimOrFocus )
  {
    v4->mFocusPos.x = v232;
    v4->mFocusPos.y = v234;
    v4->mFocusPos.z = v233;
  }
  v236 = v4->mNoiseMagnitudeRamp.x;
  v237 = v4->mNoiseMagnitudeRamp.z;
  v238 = v4->mNoiseMagnitudeRamp.w;
  if ( (float)(v4->mNoiseMagnitudeRamp.y - v236) >= 0.000099999997 )
    v235 = v4->mNoiseMagnitudeRamp.y - v236;
  v239 = 1.5707964 / v235;
  if ( v40 <= v236 )
    v240 = v4->mNoiseMagnitudeRamp.x;
  else
    v240 = v40;
  if ( v240 >= v4->mNoiseMagnitudeRamp.y )
    v240 = v4->mNoiseMagnitudeRamp.y;
  v241 = sinf((float)(v240 - v236) * v239);
  v242 = (float)((float)(v241 * v241) * (float)(v238 - v237)) + v237;
  if ( v242 > 0.0 )
  {
    duration.x = v232;
    duration.y = v234;
    duration.z = v233;
    v243 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(&v4->mLookNoise, &result, &duration);
    v244 = v242 * v243->z;
    v245 = v242 * v243->y;
    desLook.x = desLook.x + (float)(v242 * v243->x);
    desLook.z = desLook.z + v244;
    desLook.y = desLook.y + v245;
    duration = eye;
    v246 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(&v4->mEyeNoise, &result, &duration);
    v247 = v242 * v246->x;
    v248 = v242 * v246->y;
    v249 = v242 * v246->z;
    eye.x = eye.x + v247;
    eye.y = eye.y + v248;
    eye.z = eye.z + v249;
  }
  UFG::CameraSubject::GetBoxVerts((UFG::CameraSubject *)v4->mTarget.m_pSimComponent, &verts, 0.0);
  v250 = (float)((float)((float)((float)(UFG::qVector3::msZero.z + v495) + v498) + v501) + v504) * 0.25;
  v251 = (float)((float)((float)((float)(UFG::qVector3::msZero.x + v493) + v496) + v499) + v502) * 0.25;
  v252 = (float)((float)((float)((float)(UFG::qVector3::msZero.y + v494) + v497) + v500) + v503) * 0.25;
  if ( v250 <= 0.5 )
    v253 = FLOAT_0_5;
  else
    v253 = (float)((float)((float)((float)(UFG::qVector3::msZero.z + v495) + v498) + v501) + v504) * 0.25;
  v254 = v251 * 0.5;
  if ( (float)(v251 * 0.5) <= 0.2 )
    v254 = FLOAT_0_2;
  v255 = v254 * 0.5;
  if ( (float)(v254 * 0.5) <= 0.5 )
    v255 = FLOAT_0_5;
  if ( UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent) )
    v253 = 0.0;
  v256 = (UFG::qMatrix44 *)&v4->mTarget.m_pSimComponent[1].m_BoundComponentHandles;
  v467 = 1065353216;
  result.y = v252;
  result.z = v250;
  result.x = v251 - 0.40000001;
  v257 = UFG::operator*((UFG::qVector4 *)&duration, (UFG::qVector4 *)&result, v256);
  v467 = 1065353216;
  v258 = v257->x;
  v259 = v257->y;
  v464 = v257->z;
  v474 = v258;
  v475 = v259;
  result.y = (float)((float)((float)((float)(UFG::qVector3::msZero.y + verts.y) + v485) + v488) + v491) * 0.25;
  result.z = (float)((float)((float)((float)(UFG::qVector3::msZero.z + verts.z) + v486) + v489) + v492) * 0.25;
  result.x = (float)((float)((float)((float)((float)(UFG::qVector3::msZero.x + verts.x) + v484) + v487) + v490) * 0.25)
           + 0.40000001;
  v260 = UFG::operator*((UFG::qVector4 *)&duration, (UFG::qVector4 *)&result, v256);
  v261 = 0;
  v262 = v260->x;
  v263 = v260->y;
  v264 = v260->z;
  v4->mPushInOverrideRate = 0.0;
  v4->mCollisionTargetPointsNum = 2;
  v4->mCollisionBlend = v255;
  v4->mCollisionRise = v253;
  v4->mCollisionPlateau = v254;
  v4->mCollisionTargetPoints[0].x = v258;
  v4->mCollisionTargetPoints[0].y = v259;
  v514 = v262;
  v265 = v262;
  v476 = v263;
  v4->mCollisionTargetPoints[0].z = v464;
  v4->mCollisionTargetPoints[1].x = v262;
  v4->mCollisionTargetPoints[1].y = v263;
  v4->mCollisionTargetPoints[1].z = v264;
  v266 = UFG::qVector2::msZero.y;
  v477 = v264;
  v267 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  if ( UFG::UI::InMinigame() )
  {
    if ( v267 )
    {
      v261 = 0;
      if ( (v267->m_SubModes >> 2) & 1 )
        v261 = 1;
    }
  }
  v268 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "DialogBox");
  v269 = UFG::gActiveControllerNum;
  v270 = v268;
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    goto LABEL_284;
  if ( UFG::UI::InMinigame() && !v261 || v270 )
  {
    v269 = UFG::gActiveControllerNum;
LABEL_284:
    v282 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v269];
    if ( v282 )
      v266 = v282->mAxisPositionY;
    else
      v266 = 0.0;
    if ( v282 )
      v276 = (__m128)LODWORD(v282->mAxisPositionX);
    else
      v276 = 0i64;
    UFG::qApproach(&v4->mLookupMouse, 0.0, COERCE_FLOAT(*(_DWORD *)v223 & _xmm) * lookupZeroRate, v3);
    goto LABEL_291;
  }
  v271 = UFG::ActionDef_LookBack.mDataPerController[UFG::gActiveControllerNum];
  if ( v271 && v271->mActionTrue )
    v266 = *(float *)&FLOAT_1_0;
  v272 = UFG::GameStatTracker::Instance();
  v273 = UFG::GameStatTracker::GetStat(v272, CameraSpeedYaw);
  v276 = (__m128)LODWORD(UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax);
  v274 = 0.0;
  v275 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
  v276.m128_f32[0] = (float)((float)((float)(UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax + 1.0)
                                   - (float)(1.0 - UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax))
                           * v273)
                   + (float)(1.0 - UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax);
  if ( v275 )
    v277 = v275->mAxisPositionX;
  else
    v277 = 0.0;
  v276.m128_f32[0] = (float)(v276.m128_f32[0] * UFG::ChaseCameraComponent::rMouseLookaroundScale) * v277;
  if ( v275 )
    v274 = v275->mAxisPositionY;
  v278 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v278, YAxisInverted) )
    LODWORD(v274) ^= _xmm[0];
  v279 = UFG::GameStatTracker::Instance();
  v280 = (float)((float)((float)((float)((float)(UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax + 1.0)
                                       - (float)(1.0 - UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax))
                               * UFG::GameStatTracker::GetStat(v279, CameraSpeedPitch))
                       + (float)(1.0 - UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax))
               * (float)(v274 * UFG::ChaseCameraComponent::rLookupMouseSensitivity))
       + *v223;
  *v223 = v280;
  v281 = v280;
  if ( v280 <= UFG::ChaseCameraComponent::rLookupMouseMin )
    v281 = UFG::ChaseCameraComponent::rLookupMouseMin;
  if ( v281 >= UFG::ChaseCameraComponent::rLookupMouseMax )
    v281 = UFG::ChaseCameraComponent::rLookupMouseMax;
  *v223 = v281;
LABEL_291:
  if ( UFG::GameCameraComponent::mNoRotationTimer > 0.0 )
  {
    v276 = (__m128)LODWORD(UFG::qVector2::msZero.x);
    v266 = UFG::qVector2::msZero.y;
  }
  v283 = v276;
  v283.m128_f32[0] = (float)(v276.m128_f32[0] * v276.m128_f32[0]) + (float)(v266 * v266);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v283)) <= UFG::ChaseCameraComponent::rLookaroundDeadzone || v4->mAimOrFocus )
  {
    v276.m128_i32[0] = LODWORD(UFG::qVector2::msZero.x);
    v266 = UFG::qVector2::msZero.y;
  }
  if ( v266 <= 0.69999999 )
  {
    if ( v4->mLookingBack )
    {
      v276.m128_i32[0] = 0;
      v4->mLookaroundJoyInput = 0.0;
    }
    v284 = _xmm[0];
    v4->mLookingBack = 0;
  }
  else
  {
    v284 = _xmm[0];
    if ( !v4->mLookingBack )
    {
      v285 = LODWORD(v4->mCamera.mTransformation.v2.x) ^ _xmm[0];
      v286 = LODWORD(v4->mCamera.mTransformation.v2.y) ^ _xmm[0];
      v287 = LODWORD(v4->mCamera.mTransformation.v2.z) ^ _xmm[0];
      v288 = (float *)((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)();
      if ( (float)((float)((float)(*(float *)&v286 * v288[1]) + (float)(*(float *)&v285 * *v288))
                 + (float)(*(float *)&v287 * v288[2])) > -0.85000002 )
        v4->mLookingBack = 1;
    }
  }
  v289 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v289, XAxisInverted) )
    v276.m128_i32[0] ^= v284;
  v290 = (float)(sinf((float)(v4->mLockEyeParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  v291 = (float)(sinf((float)(v4->mLockLookParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( !v4->mLookingBack )
  {
    if ( v4->mLockEye )
    {
      v292 = (float)(1.0 - v290) * v4->mLockEyeVel.x;
      v293 = (float)(1.0 - v290) * v4->mLockEyeVel.y;
      v294 = (float)((float)((float)(1.0 - v290) * v4->mLockEyeVel.z) * v3) + v4->mLockEyePos.z;
      v4->mLockEyePos.z = v294;
      v295 = (float)(v292 * v3) + v4->mLockEyePos.x;
      v296 = (float)(v293 * v3) + v4->mLockEyePos.y;
      v4->mLockEyePos.x = v295;
      eye.x = v295;
      eye.z = v294;
      v4->mLockEyePos.y = v296;
      eye.y = v296;
    }
    else
    {
      v297 = (float)(v290 * (float)(v4->mLockEyePos.x - eye.x)) + eye.x;
      v298 = v290 * (float)(v4->mLockEyePos.z - eye.z);
      v299 = (float)(v290 * (float)(v4->mLockEyePos.y - eye.y)) + eye.y;
      v300 = eye.z + v298;
      eye.x = (float)(v290 * (float)(v4->mLockEyePos.x - eye.x)) + eye.x;
      eye.z = eye.z + v298;
      eye.y = v299;
      if ( v290 == 0.0 )
      {
        v4->mLockEyePos.x = v297;
        v4->mLockEyePos.y = v299;
        v4->mLockEyePos.z = v300;
      }
      v265 = v514;
    }
    if ( v4->mLockLook )
    {
      v301 = (float)(1.0 - v291) * v4->mLockLookVel.x;
      v302 = (float)(1.0 - v291) * v4->mLockLookVel.y;
      v303 = (float)((float)((float)(1.0 - v291) * v4->mLockLookVel.z) * v3) + v4->mLockLookPos.z;
      v4->mLockLookPos.z = v303;
      v304 = (float)(v301 * v3) + v4->mLockLookPos.x;
      v305 = (float)(v302 * v3) + v4->mLockLookPos.y;
      v4->mLockLookPos.x = v304;
      desLook.x = v304;
      desLook.z = v303;
      v4->mLockLookPos.y = v305;
      desLook.y = v305;
    }
    else
    {
      v306 = v4->mLockLookPos.z - desLook.z;
      v307 = (float)(v291 * (float)(v4->mLockLookPos.x - desLook.x)) + desLook.x;
      v308 = (float)(v291 * (float)(v4->mLockLookPos.y - desLook.y)) + desLook.y;
      v309 = (float)(v291 * v306) + desLook.z;
      desLook.x = (float)(v291 * (float)(v4->mLockLookPos.x - desLook.x)) + desLook.x;
      desLook.y = v308;
      desLook.z = (float)(v291 * v306) + desLook.z;
      if ( v291 == 0.0 )
      {
        v4->mLockLookPos.x = v307;
        v4->mLockLookPos.y = v308;
        v4->mLockLookPos.z = v309;
      }
    }
  }
  v310 = 0.0;
  if ( v266 < -0.30000001 )
  {
    v276.m128_i32[0] = 0;
    v310 = (float)(v266 + 0.30000001) * -1.4285715;
  }
  v4->mLookaroundCenterTimer = v3 + v4->mLookaroundCenterTimer;
  if ( v276.m128_f32[0] != UFG::qVector2::msZero.x || v266 != UFG::qVector2::msZero.y )
    v4->mLookaroundCenterTimer = 0.0;
  if ( v4->mTarget.m_pSimComponent
    && !UFG::VehicleSubjectComponent::IsGas((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent) )
  {
    v4->mLookaroundCenterTimer = 0.0;
  }
  v311 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  v312 = v311
      && !v4->mLockEye
      && !v4->mLockLook
      && UFG::ChaseCameraComponent::rLookaroundCenterTimerMouse > v4->mLookaroundCenterTimer;
  if ( v311 )
    v313 = UFG::ChaseCameraComponent::rLookaroundJoyInputApproachRateMouse;
  else
    v313 = UFG::ChaseCameraComponent::rLookaroundJoyInputApproachRate;
  v314 = &v4->mLookaroundJoyInput;
  if ( v311 )
    *v314 = v276.m128_f32[0];
  else
    UFG::qApproach(
      &v4->mLookaroundJoyInput,
      v276.m128_f32[0],
      COERCE_FLOAT(COERCE_UNSIGNED_INT(*v314 - v276.m128_f32[0]) & _xmm) * v313,
      v3);
  if ( v4->mLookingBack )
    *v314 = 0.0;
  UFG::qApproach(
    &v4->mLookupJoyInput,
    v310,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(v4->mLookupJoyInput - v310) & _xmm)
  * UFG::ChaseCameraComponent::rLookupJoyInputApproachRate,
    v3);
  if ( !v4->mAimOrFocus )
  {
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      v315 = (float)(UFG::ChaseCameraComponent::rLookaroundRotateRateMouse * *v314) * 0.016666668;
    else
      v315 = (float)(UFG::ChaseCameraComponent::rLookaroundRotateRate * *v314) * v3;
    v4->mLookaroundAngle = v315 + v4->mLookaroundAngle;
  }
  v316 = &v4->mLookaroundAngle;
  NormAngle(&v4->mLookaroundAngle);
  v317 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  if ( v317 )
    v318 = UFG::ChaseCameraComponent::rLookaroundCenterRateScaleMouse;
  else
    v318 = UFG::ChaseCameraComponent::rLookaroundCenterRateScale;
  if ( v312 )
    v318 = 0.0;
  if ( v317 )
    v319 = UFG::ChaseCameraComponent::rLookaroundCenterRateMaxMouse;
  else
    v319 = UFG::ChaseCameraComponent::rLookaroundCenterRateMax;
  if ( v312 )
    v319 = FLOAT_0_0099999998;
  v320 = *(float *)&FLOAT_1_0;
  if ( v4->mAimOrFocus )
  {
    v321 = FLOAT_10_0;
  }
  else
  {
    v322 = (float)(v40 - 2.0) / (float)(v4->mCenteringSpeedMax - 2.0);
    if ( v322 <= 0.0 )
    {
      v322 = 0.0;
    }
    else if ( v322 >= 1.0 )
    {
      v322 = *(float *)&FLOAT_1_0;
    }
    v321 = (float)(v322 * 10.0) * v318;
  }
  if ( COERCE_FLOAT(v276.m128_i32[0] & _xmm) < 0.0099999998 )
  {
    v323 = (float)(v473 - v4->mCenteringSpeedMin) / (float)(v4->mCenteringSpeedMax - v4->mCenteringSpeedMin);
    if ( v323 <= 0.0 )
    {
      v323 = 0.0;
    }
    else if ( v323 >= 1.0 )
    {
      goto LABEL_365;
    }
    v320 = v323;
LABEL_365:
    v321 = v319 * v320;
  }
  v324 = COERCE_FLOAT(*(_DWORD *)v316 & _xmm) * v321;
  if ( UFG::VehicleSubjectComponent::IsInReverse((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent) )
    v324 = v324 + 4.0;
  UFG::qApproachAngle(&v4->mLookaroundAngle, 0.0, v324, v3);
  if ( COERCE_FLOAT(*(_DWORD *)v316 & _xmm) < 0.000099999997 )
    *v316 = 0.0;
  v325 = UFG::ChaseCameraComponent::rLookupHeight;
  v4->mAlternateLookValid = 0;
  v326 = v325 * v4->mLookupJoyInput;
  if ( v4->mAimOrFocus || v326 > 0.0099999998 )
  {
    v327 = v476 + v475;
    v328 = v477 + v464;
    v4->mAlternateLook.x = (float)(v265 + v474) * 0.5;
    v4->mAlternateLook.y = v327 * 0.5;
    v4->mAlternateLook.z = v328 * 0.5;
    v4->mAlternateLookValid = 1;
  }
  v329 = ((__int64 (*)(void))v4->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)();
  v330 = v4->mTarget.m_pSimComponent;
  v331 = *(float *)(v329 + 16);
  v332 = *(float *)v329;
  v333 = *(float *)(v329 + 4);
  v334 = *(float *)(v329 + 8);
  dest.v0.w = *(float *)(v329 + 12);
  v335 = *(float *)(v329 + 20);
  dest.v1.x = v331;
  v336 = *(float *)(v329 + 24);
  dest.v1.y = v335;
  v337 = *(float *)(v329 + 28);
  dest.v1.z = v336;
  v338 = *(float *)(v329 + 32);
  dest.v1.w = v337;
  dest.v2.y = *(float *)(v329 + 36);
  v339 = *(float *)(v329 + 44);
  dest.v2.x = v338;
  v340 = *(float *)(v329 + 40);
  dest.v2.w = v339;
  v341 = *(float *)(v329 + 52);
  dest.v2.z = v340;
  v342 = *(float *)(v329 + 48);
  dest.v3.y = v341;
  v343 = *(float *)(v329 + 60);
  dest.v3.x = v342;
  v344 = *(float *)(v329 + 56);
  v345 = v330->vfptr;
  dest.v0.x = v332;
  dest.v0.y = v333;
  dest.v0.z = v334;
  dest.v3.z = v344;
  dest.v3.w = v343;
  v346 = (float *)((__int64 (*)(void))v345[20].__vecDelDtor)();
  v347 = 0.0;
  v348 = v346[1];
  v349 = v346[2];
  v1.x = *v346;
  v1.y = v348;
  v1.z = v349;
  if ( (float)((float)((float)(v1.x * v1.x) + (float)(v348 * v348)) + (float)(v349 * v349)) > 36.0
    && (float)((float)((float)(v348 * v333) + (float)(v332 * v1.x)) + (float)(v349 * v334)) > 0.69999999
    && UFG::VehicleSubjectComponent::IsDoingWheelie((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent) )
  {
    duration.x = v332;
    duration.y = v333;
    duration.z = v334;
    v347 = UFG::qAngleBetween(&v1, &duration);
    v350 = 0.0;
    if ( v347 <= 0.0 || (v350 = FLOAT_1_5707964, v347 >= 1.5707964) )
      v347 = v350;
  }
  UFG::qApproach(&v4->mLookbackCorrectionAngle, v347, 1.8, v3);
  if ( !v4->mLookingBack
    || UFG::VehicleSubjectComponent::IsDoingOneEighty((UFG::VehicleSubjectComponent *)v4->mTarget.m_pSimComponent) )
  {
    v375 = eye.x - desLook.x;
    v376 = eye.y - desLook.y;
    v377 = eye.z - desLook.z;
    UFG::qRotationMatrixAxis(&dest, &axis, *v316);
    v378 = dest.v1.x * v376;
    v359 = LODWORD(dest.v1.y);
    v366 = desLook.x;
    *(float *)&v359 = dest.v1.y * v376;
    v379 = dest.v1.z * v376;
    v365 = (__m128)LODWORD(desLook.y);
    v363 = axis.z;
    v362 = (__m128)LODWORD(axis.y);
    v361 = axis.x;
    v352 = (__m128)(unsigned int)FLOAT_1_0;
    v358 = (float)((float)(v378 + (float)(dest.v0.x * v375)) + (float)(dest.v2.x * v377)) + desLook.x;
    *(float *)&v359 = (float)((float)(*(float *)&v359 + (float)(dest.v0.y * v375)) + (float)(dest.v2.y * v377))
                    + desLook.y;
    eye.x = v358;
    LODWORD(eye.y) = v359;
    v360 = (float)((float)(v379 + (float)(dest.v0.z * v375)) + (float)(dest.v2.z * v377)) + desLook.z;
    v364 = desLook.z + v326;
    desLook.z = desLook.z + v326;
    eye.z = v360;
    if ( !v4->mLockEye )
    {
      v367 = 0i64;
      if ( v4->mLockEyeParam == 0.0 )
      {
        v4->mLockEyePos.x = v358;
        LODWORD(v4->mLockEyePos.y) = v359;
        v4->mLockEyePos.z = v360;
      }
      goto LABEL_383;
    }
  }
  else
  {
    UFG::qRotationMatrixAxis(
      &matrix44,
      &UFG::qVector3::msAxisY,
      COERCE_FLOAT(LODWORD(v4->mLookbackCorrectionAngle) ^ _xmm[0]));
    v351 = UFG::qMatrix44::operator*(&matrix44, (UFG::qMatrix44 *)&verts, &dest);
    v352 = (__m128)(unsigned int)FLOAT_1_0;
    v467 = 1065353216;
    v353 = v351->v3;
    v354 = v351->v0;
    v355 = v351->v1;
    matrix44.v2 = v351->v2;
    v356 = LODWORD(v4->mEyeOffsetRange[0].x) ^ _xmm[0];
    matrix44.v0 = v354;
    v354.x = v4->mEyeOffsetRange[0].y;
    matrix44.v3 = v353;
    v353.x = v4->mEyeOffsetRange[0].z;
    LODWORD(result.x) = v356;
    result.y = v354.x;
    result.z = v353.x;
    matrix44.v1 = v355;
    v357 = UFG::operator*((UFG::qVector4 *)&duration, (UFG::qVector4 *)&result, &matrix44);
    v358 = v357->x;
    v359 = LODWORD(v357->y);
    v360 = v357->z;
    v361 = UFG::qVector3::msDirUp.x;
    v362 = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
    v363 = UFG::qVector3::msDirUp.z;
    v364 = desLook.z;
    v365 = (__m128)LODWORD(desLook.y);
    v366 = desLook.x;
    eye.x = v357->x;
    LODWORD(eye.y) = v359;
    eye.z = v360;
    axis = UFG::qVector3::msDirUp;
  }
  v367 = 0i64;
LABEL_383:
  v368 = (__m128)v359;
  v369 = v358 - v366;
  v370 = v366 - v358;
  v368.m128_f32[0] = (float)((float)(*(float *)&v359 - v365.m128_f32[0]) * (float)(*(float *)&v359 - v365.m128_f32[0]))
                   + (float)(v369 * v369);
  v365.m128_f32[0] = v365.m128_f32[0] - *(float *)&v359;
  v368.m128_f32[0] = v368.m128_f32[0] + (float)((float)(v360 - v364) * (float)(v360 - v364));
  v371 = v364 - v360;
  LODWORD(v372) = (unsigned __int128)_mm_sqrt_ps(v368);
  v373 = v365;
  v473 = v372;
  v373.m128_f32[0] = (float)((float)(v365.m128_f32[0] * v365.m128_f32[0]) + (float)(v370 * v370)) + (float)(v371 * v371);
  if ( v373.m128_f32[0] == v367.m128_f32[0] )
    v374 = v367.m128_f32[0];
  else
    v374 = v352.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v373));
  v382 = v362;
  mat.v0.w = 0.0;
  v515 = v374 * v370;
  mat.v0.x = v374 * v370;
  v380 = v374 * v365.m128_f32[0];
  v381 = v374 * v371;
  v477 = v380;
  mat.v0.y = v380;
  v382.m128_f32[0] = (float)((float)(v362.m128_f32[0] * v362.m128_f32[0]) + (float)(v361 * v361)) + (float)(v363 * v363);
  mat.v0.z = v381;
  if ( v382.m128_f32[0] == v367.m128_f32[0] )
  {
    v384 = v367;
  }
  else
  {
    LODWORD(v383) = (unsigned __int128)_mm_sqrt_ps(v382);
    v384 = v352;
    v384.m128_f32[0] = v352.m128_f32[0] / v383;
  }
  v385 = v384.m128_f32[0];
  v386 = v384.m128_f32[0];
  v384.m128_f32[0] = v384.m128_f32[0] * v363;
  v387 = v385 * v362.m128_f32[0];
  v388 = v386 * v361;
  v389 = (float)(v387 * v381) - (float)(v384.m128_f32[0] * v380);
  v384.m128_f32[0] = (float)(v384.m128_f32[0] * v515) - (float)(v388 * v381);
  v390 = (float)(v388 * v380) - (float)(v387 * v515);
  v391 = v384;
  v391.m128_f32[0] = (float)((float)(v384.m128_f32[0] * v384.m128_f32[0]) + (float)(v389 * v389)) + (float)(v390 * v390);
  if ( v391.m128_f32[0] == v367.m128_f32[0] )
  {
    v393 = v367;
  }
  else
  {
    LODWORD(v392) = (unsigned __int128)_mm_sqrt_ps(v391);
    v393 = v352;
    v393.m128_f32[0] = v352.m128_f32[0] / v392;
  }
  v394 = v393;
  v394.m128_f32[0] = v393.m128_f32[0] * v389;
  mat.v1.w = 0.0;
  mat.v1.z = v393.m128_f32[0] * v390;
  v396 = v394;
  LODWORD(mat.v1.x) = v394.m128_i32[0];
  mat.v1.y = v393.m128_f32[0] * v384.m128_f32[0];
  v395 = (float)((float)(v393.m128_f32[0] * v390) * v477) - (float)((float)(v393.m128_f32[0] * v384.m128_f32[0]) * v381);
  v396.m128_f32[0] = (float)(v394.m128_f32[0] * v381) - (float)(mat.v1.z * v515);
  v397 = (float)((float)(v393.m128_f32[0] * v384.m128_f32[0]) * v515) - (float)(v394.m128_f32[0] * v477);
  v398 = v396;
  v398.m128_f32[0] = (float)((float)(v396.m128_f32[0] * v396.m128_f32[0]) + (float)(v395 * v395)) + (float)(v397 * v397);
  if ( v398.m128_f32[0] == v367.m128_f32[0] )
    v399 = v367.m128_f32[0];
  else
    v399 = v352.m128_f32[0] / COERCE_FLOAT(_mm_sqrt_ps(v398));
  mat.v3.x = v358;
  LODWORD(mat.v3.y) = v359;
  mat.v2.w = 0.0;
  mat.v3.w = 1.0;
  mat.v2.z = v399 * v397;
  mat.v3.z = v360;
  mat.v2.x = v399 * v395;
  mat.v2.y = v399 * v396.m128_f32[0];
  UFG::qQuaternion::Set(&a, &mat);
  v404 = (__m128)LODWORD(v469);
  v400 = v471;
  v401 = v465;
  v402 = (__m128)LODWORD(v512);
  v403 = v470 - v471;
  v402.m128_f32[0] = (float)((float)((float)(v512 - v469) * (float)(v512 - v469))
                           + (float)((float)(v471 - v470) * (float)(v471 - v470)))
                   + (float)((float)(v465 - v472) * (float)(v465 - v472));
  v404.m128_f32[0] = v469 - v512;
  v405 = v472 - v465;
  LODWORD(v406) = (unsigned __int128)_mm_sqrt_ps(v402);
  v407 = v404;
  v407.m128_f32[0] = (float)((float)(v404.m128_f32[0] * v404.m128_f32[0]) + (float)(v403 * v403)) + (float)(v405 * v405);
  if ( v407.m128_f32[0] == 0.0 )
    v408 = 0.0;
  else
    v408 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v407));
  v409 = v408;
  v410 = v408;
  v411 = v408 * v405;
  v412 = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
  v505.v0.w = 0.0;
  v413 = v409 * v404.m128_f32[0];
  v414 = v410 * v403;
  v505.v0.z = v411;
  v415 = v412;
  v505.v0.x = v414;
  v505.v0.y = v413;
  v415.m128_f32[0] = (float)((float)(v412.m128_f32[0] * v412.m128_f32[0])
                           + (float)(UFG::qVector3::msDirUp.x * UFG::qVector3::msDirUp.x))
                   + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v415.m128_f32[0] == 0.0 )
  {
    v417 = 0i64;
  }
  else
  {
    LODWORD(v416) = (unsigned __int128)_mm_sqrt_ps(v415);
    v417 = (__m128)(unsigned int)FLOAT_1_0;
    v417.m128_f32[0] = 1.0 / v416;
  }
  v418 = v417.m128_f32[0];
  v419 = v417.m128_f32[0];
  v417.m128_f32[0] = v417.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v420 = v418 * UFG::qVector3::msDirUp.y;
  v421 = v419 * UFG::qVector3::msDirUp.x;
  v422 = (float)(v420 * v411) - (float)(v417.m128_f32[0] * v413);
  v417.m128_f32[0] = (float)(v417.m128_f32[0] * v414) - (float)(v421 * v411);
  v423 = (float)(v421 * v413) - (float)(v420 * v414);
  v424 = v417;
  v424.m128_f32[0] = (float)((float)(v417.m128_f32[0] * v417.m128_f32[0]) + (float)(v422 * v422)) + (float)(v423 * v423);
  if ( v424.m128_f32[0] == 0.0 )
  {
    v426 = 0i64;
  }
  else
  {
    LODWORD(v425) = (unsigned __int128)_mm_sqrt_ps(v424);
    v426 = (__m128)(unsigned int)FLOAT_1_0;
    v426.m128_f32[0] = 1.0 / v425;
  }
  v427 = v426;
  v505.v1.w = 0.0;
  v427.m128_f32[0] = v426.m128_f32[0] * v422;
  v430 = v427;
  v505.v1.x = v426.m128_f32[0] * v422;
  v505.v1.z = v426.m128_f32[0] * v423;
  v505.v1.y = v426.m128_f32[0] * v417.m128_f32[0];
  v428 = (float)((float)(v426.m128_f32[0] * v423) * v413) - (float)((float)(v426.m128_f32[0] * v417.m128_f32[0]) * v411);
  v429 = (float)((float)(v426.m128_f32[0] * v417.m128_f32[0]) * v414) - (float)((float)(v426.m128_f32[0] * v422) * v413);
  v430.m128_f32[0] = (float)(v427.m128_f32[0] * v411) - (float)(v505.v1.z * v414);
  v431 = v430;
  v431.m128_f32[0] = (float)((float)(v430.m128_f32[0] * v430.m128_f32[0]) + (float)(v428 * v428)) + (float)(v429 * v429);
  if ( v431.m128_f32[0] == 0.0 )
    v432 = 0.0;
  else
    v432 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v431));
  v505.v3.x = v471;
  v505.v3.z = v465;
  v505.v2.w = 0.0;
  v505.v3.w = 1.0;
  v505.v2.z = v432 * v429;
  v505.v3.y = v512;
  v505.v2.x = v432 * v428;
  v505.v2.y = v432 * v430.m128_f32[0];
  UFG::qQuaternion::Set(&b, &v505);
  v433 = (float)(sinf((float)(v4->mAimParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  eye.x = (float)(v433 * v400) + (float)((float)(1.0 - v433) * eye.x);
  eye.y = (float)(v433 * v512) + (float)((float)(1.0 - v433) * eye.y);
  eye.z = (float)(v433 * v401) + (float)(eye.z * (float)(1.0 - v433));
  v434 = UFG::qSlerp((UFG::qQuaternion *)&result, &a, &b, v433, 0);
  v435 = v4->mTransitionParamEye;
  v436 = v434->z;
  v437 = v434->w;
  v438 = v434->x;
  a.y = v434->y;
  v439 = v435 * v4->mTransitionFromEye.y;
  a.x = v438;
  a.w = v437;
  a.z = v436;
  v440 = v435 * v4->mTransitionFromEye.x;
  v441 = v4->mTransitionParamOrient;
  *(_QWORD *)&t.y = __PAIR__(
                      (float)(v435 * v4->mTransitionFromEye.z) + (float)((float)(1.0 - v435) * eye.z),
                      (float)(v439 + (float)((float)(1.0 - v435) * eye.y)));
  t.x = v440 + (float)((float)(1.0 - v435) * eye.x);
  UFG::qSlerp(&v508, &a, &v4->mTransitionFromOri, v441, 0);
  v442 = v4->mTransitionParamEye;
  v443 = 1.0 - v442;
  v444 = v442 * v4->mTransitionFromLen;
  eye = t;
  v445 = (float)((float)((float)(v433 * v406) + (float)((float)(1.0 - v433) * v473)) * v443) + v444;
  v446 = UFG::qQuaternion::GetMatrix(&v508, (UFG::qMatrix44 *)&verts, &t);
  v447 = v510;
  v448 = v446->v0;
  v449 = (__m128)v446->v2;
  v450 = v446->v0;
  v451 = v446->v1;
  mat.v3 = v446->v3;
  LODWORD(duration.x) = v449.m128_i32[0];
  mat.v0 = v448;
  mat.v2 = (UFG::qVector4)v449;
  LODWORD(duration.y) = (unsigned __int128)_mm_shuffle_ps(v449, v449, 85);
  LODWORD(duration.z) = (unsigned __int128)_mm_shuffle_ps(v449, v449, 170);
  desLook.y = (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)v448, (__m128)v448, 85)) * v445) + eye.y;
  desLook.x = (float)(v450.x * v445) + eye.x;
  desLook.z = eye.z + (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)v448, (__m128)v448, 170)) * v445);
  mat.v1 = v451;
  if ( v461 )
    ((void (__fastcall *)(UFG::ChaseCameraComponent *))v4->vfptr[31].__vecDelDtor)(v4);
  UFG::GameCameraComponent::SetDesiredEyeLookUp(
    (UFG::GameCameraComponent *)&v4->vfptr,
    v3,
    &eye,
    &desLook,
    v447,
    &duration,
    1,
    &newEye,
    &result);
  v452 = (float)(v4->mFov.p0 * 3.1415927) * 0.0055555557;
  if ( !Render::GetRenderFeatures()->mForceLetterBox )
    v452 = Render::GetExtraWideAspectCorrectedFOV(v452);
  v453 = UFG::GameCameraComponent::ComputeNearOffset((UFG::GameCameraComponent *)&v4->vfptr, &newEye, &result, v452)
       + UFG::gCameraDefaultNear;
  v454 = Render::GetDisplayAspectRatio();
  UFG::Camera::SetViewProjection(&v4->mCamera, v452, v454, v453, UFG::gCameraDefaultFar, 0.0, 0.0, 1);
  if ( v4->mAllowDesaturation )
    v455 = v4->mDesaturation;
  else
    v455 = 0.0;
  v456 = v4->mMotionblurMagnitude;
  v4->mCamera.mDesaturation = v455;
  v4->mCamera.mMotionBlur = v456;
  v457 = UFG::qSignedMod(v4->mDutch.mHomerCubic.p0, v4->mDutch.mModulo);
  UFG::Camera::ApplyDutch(&v4->mCamera, v457 + UFG::GameCameraComponent::mDutchDyn.p0);
  v458 = (__m128)LODWORD(v4->mFocusPos.y);
  v458.m128_f32[0] = (float)((float)((float)(v458.m128_f32[0] - eye.y) * (float)(v458.m128_f32[0] - eye.y))
                           + (float)((float)(v4->mFocusPos.x - eye.x) * (float)(v4->mFocusPos.x - eye.x)))
                   + (float)((float)(v4->mFocusPos.z - eye.z) * (float)(v4->mFocusPos.z - eye.z));
  LODWORD(v4->mDofParameters.mFocalDistance) = (unsigned __int128)_mm_sqrt_ps(v458);
  UFG::GameCameraComponent::UpdateDof((UFG::GameCameraComponent *)&v4->vfptr, v3, &v4->mDofParameters, 0);
}qVector4)v449;
  LODWORD(duration.y) = (unsigned __int128)_mm_shuffle_ps(v449, v449, 85);
  LODWORD(duration.z) = (unsigned __int128)_mm_shuffle_ps(v449, v449, 170);
  desLook.y = (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)v448, (__m128)v448, 85)) * v445) + eye.y;
  desLook.x = (float)(v450.x * v445) + eye.x;
  desLook.z = eye.z + (float)(COERCE_FLOAT(_mm_shuffle_ps((__m128)v448, (__m128)v448, 170)) * v445);
  mat.v1 = v451;
  if ( v461 )
    ((void (__fastcall *)(UFG::ChaseCameraComponent *))v4->vfptr[31].__vecDelDtor)(v4);
  UFG::GameCameraComponent::SetDesiredEyeLookUp(
    (UFG::GameCameraComponent *)&v4->vfptr,
    v3,
    &eye,
    &desLook,
    v447,
    &duration,
    1,
    &newEye,
    &result);
  v452 = (float)(v4->mFov.p0 * 3.1415927) * 0.0055555557;
  if ( !Render::GetRenderFeatures()->mForceLetterBox )
    v452 = Render::GetExtraWideAspectCorrectedFOV(v452);
  v453 = UFG::GameCameraComponent::ComputeNearOffset((UFG::GameCameraComponent *)&v4->vfptr, &newEye, &result, v452)
       + UFG::gCameraDefaultNear;
  v454 = Render::GetDisplayAspectRatio();
  UFG::Camera::SetViewProjection(&v4->mCamera, v452, v454, v453, UFG::gCameraDefaultFar, 0.0, 0.0, 1);
  if ( v4->mAllowDesatur

// File Line: 2487
// RVA: 0x3CE860
void __usercall UFG::ChaseCameraComponent::TransitionFrom(UFG::ChaseCameraComponent *this@<rcx>, UFG::BaseCameraComponent *fromCamera@<rdx>, bool withVelocity@<r8b>, float a4@<xmm0>)
{
  UFG::BaseCameraComponent *v4; // rdi
  UFG::ChaseCameraComponent *v5; // rsi

  v4 = fromCamera;
  v5 = this;
  this->mTransitionParam = 1.0;
  this->mLookaroundAngle = 0.0;
  UFG::BaseCameraComponent::TransitionFrom((UFG::BaseCameraComponent *)&this->vfptr, fromCamera, withVelocity);
  ((void (__fastcall *)(UFG::BaseCameraComponent *))v4->vfptr[19].__vecDelDtor)(v4);
  v5->mFov.p1 = (float)(a4 * 180.0) * 0.31830987;
  UFG::HomerCubic<float>::MakeCoeffs(&v5->mFov);
  v5->mFov.mParameter = 0.0;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v5->vfptr[31].__vecDelDtor)(v5);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v5->vfptr[15].__vecDelDtor)(v5);
}

// File Line: 2498
// RVA: 0x3CE8F0
void __fastcall UFG::ChaseCameraComponent::TransitionFromBlendOrientation(UFG::ChaseCameraComponent *this, UFG::BaseCameraComponent *fromCamera)
{
  UFG::BaseCameraComponent *v2; // rbx
  UFG::ChaseCameraComponent *v3; // rdi
  float v4; // xmm15_4
  float v5; // xmm10_4
  __m128 v6; // xmm8
  float v7; // xmm11_4
  __int128 v8; // xmm4
  __m128 v9; // xmm5
  __int128 v10; // xmm7
  __m128 v11; // xmm3
  float v12; // xmm1_4
  float v13; // xmm14_4
  __m128 v14; // xmm9
  float v15; // xmm13_4
  float v16; // xmm5_4
  __m128 v17; // xmm3
  float v18; // xmm1_4
  float v19; // xmm9_4
  float v20; // xmm13_4
  float v21; // xmm14_4
  __int128 v22; // xmm12
  float v23; // xmm13_4
  __m128 v24; // xmm3
  float v25; // xmm13_4
  __m128 v26; // xmm9
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm9_4
  __m128 v30; // xmm14
  float v31; // xmm3_4
  __m128 v32; // xmm4
  float v33; // xmm2_4
  float v34; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v35; // rax
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  UFG::qMatrix44 mat; // [rsp+20h] [rbp-E8h]
  float v45; // [rsp+110h] [rbp+8h]
  float v46; // [rsp+118h] [rbp+10h]

  v2 = fromCamera;
  v3 = this;
  ((void (*)(void))this->vfptr[14].__vecDelDtor)();
  v9 = (__m128)LODWORD(v2->mLookCurr.y);
  v10 = LODWORD(v2->mLookCurr.z);
  v4 = v2->mLookCurr.x;
  v5 = v2->mEyeCurr.x;
  v6 = (__m128)LODWORD(v2->mEyeCurr.y);
  v8 = LODWORD(v2->mLookCurr.x);
  v7 = v2->mEyeCurr.z;
  *(float *)&v8 = *(float *)&v8 - v5;
  v9.m128_f32[0] = v9.m128_f32[0] - v6.m128_f32[0];
  v45 = v2->mLookCurr.y;
  *(float *)&v10 = *(float *)&v10 - v7;
  v11 = v9;
  v46 = v2->mLookCurr.z;
  v3->mTransitionFromEye.x = v5;
  v11.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(*(float *)&v8 * *(float *)&v8))
                  + (float)(*(float *)&v10 * *(float *)&v10);
  LODWORD(v3->mTransitionFromEye.y) = v6.m128_i32[0];
  v3->mTransitionFromEye.z = v7;
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  v13 = v2->mCamera.mTransformation.v1.y;
  v14 = (__m128)LODWORD(v2->mCamera.mTransformation.v1.x);
  v15 = v2->mCamera.mTransformation.v1.z;
  *(float *)&v8 = *(float *)&v8 * v12;
  v16 = v9.m128_f32[0] * v12;
  *(float *)&v10 = *(float *)&v10 * v12;
  mat.v0.w = 0.0;
  v17 = v14;
  LODWORD(mat.v0.x) = v8;
  mat.v0.y = v16;
  LODWORD(mat.v0.z) = v10;
  v17.m128_f32[0] = (float)((float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v13 * v13)) + (float)(v15 * v15);
  if ( v17.m128_f32[0] == 0.0 )
    v18 = 0.0;
  else
    v18 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
  v19 = v14.m128_f32[0] * v18;
  v20 = v15 * v18;
  v21 = v13 * v18;
  v22 = v10;
  v24 = (__m128)v8;
  v24.m128_f32[0] = *(float *)&v8 * v20;
  *(float *)&v22 = (float)(*(float *)&v10 * v21) - (float)(v16 * v20);
  v23 = v16 * v19;
  v24.m128_f32[0] = v24.m128_f32[0] - (float)(*(float *)&v10 * v19);
  v26 = v24;
  v25 = v23 - (float)(*(float *)&v8 * v21);
  v26.m128_f32[0] = (float)((float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(*(float *)&v22 * *(float *)&v22))
                  + (float)(v25 * v25);
  if ( v26.m128_f32[0] == 0.0 )
    v27 = 0.0;
  else
    v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
  v28 = v24.m128_f32[0] * v27;
  *(float *)&v22 = *(float *)&v22 * v27;
  mat.v1.w = 0.0;
  v30 = (__m128)v22;
  mat.v1.y = v28;
  mat.v1.z = v25 * v27;
  LODWORD(mat.v1.x) = v22;
  v29 = (float)((float)(v25 * v27) * v16) - (float)(v28 * *(float *)&v10);
  v30.m128_f32[0] = (float)(*(float *)&v22 * *(float *)&v10) - (float)((float)(v25 * v27) * *(float *)&v8);
  v31 = (float)(v28 * *(float *)&v8) - (float)(*(float *)&v22 * v16);
  v32 = v30;
  v32.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v29 * v29)) + (float)(v31 * v31);
  if ( v32.m128_f32[0] == 0.0 )
    v33 = 0.0;
  else
    v33 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v32));
  mat.v3.x = v5;
  LODWORD(mat.v3.y) = v6.m128_i32[0];
  mat.v3.z = v7;
  mat.v2.w = 0.0;
  mat.v3.w = 1.0;
  mat.v2.x = v29 * v33;
  mat.v2.y = v30.m128_f32[0] * v33;
  mat.v2.z = v31 * v33;
  UFG::qQuaternion::Set(&v3->mTransitionFromOri, &mat);
  v3->mTransitionParamEye = 1.0;
  v3->mTransitionParamOrient = 1.0;
  v6.m128_f32[0] = (float)((float)((float)(v6.m128_f32[0] - v45) * (float)(v6.m128_f32[0] - v45))
                         + (float)((float)(v5 - v4) * (float)(v5 - v4)))
                 + (float)((float)(v7 - v46) * (float)(v7 - v46));
  LODWORD(v34) = (unsigned __int128)_mm_sqrt_ps(v6);
  v3->mTransitionFromLen = v34;
  ((void (__fastcall *)(UFG::BaseCameraComponent *))v2->vfptr[19].__vecDelDtor)(v2);
  ((void (__fastcall *)(UFG::BaseCameraComponent *))v2->vfptr[19].__vecDelDtor)(v2);
  v35 = v2->vfptr;
  if ( v34 <= 3.1415927 )
  {
    ((void (__fastcall *)(UFG::BaseCameraComponent *))v35[19].__vecDelDtor)(v2);
    v34 = (float)(v34 * 180.0) * 0.31830987;
  }
  else
  {
    ((void (__fastcall *)(UFG::BaseCameraComponent *))v35[19].__vecDelDtor)(v2);
  }
  v3->mFov.p1 = v34;
  UFG::HomerCubic<float>::MakeCoeffs(&v3->mFov);
  v3->mFov.mParameter = 0.0;
  v3->mFov.p0 = v3->mFov.p1;
  v3->mFov.v0 = v3->mFov.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&v3->mFov);
  v3->mFov.mParameter = 0.0;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))v3->vfptr[15].__vecDelDtor)(v3);
  if ( 0.0 == v3->mLookaroundAngle )
  {
    if ( v3->mLockEye != 1 )
    {
      v36 = v3->mEyeVelocity.y;
      v37 = v3->mEyeVelocity.z;
      v3->mLockEyeVel.x = v3->mEyeVelocity.x;
      v3->mLockEyeVel.y = v36;
      v3->mLockEyeVel.z = v37;
      v38 = v3->mEyeCurr.y;
      v39 = v3->mEyeCurr.z;
      v3->mLockEyePos.x = v3->mEyeCurr.x;
      v3->mLockEyePos.y = v38;
      v3->mLockEyePos.z = v39;
      v3->mLockEyeParam = 0.0;
      v3->mLockEye = 1;
      v3->mUpdateEyeOffset = 0;
    }
    if ( 0.0 == v3->mLookaroundAngle && v3->mLockLook != 1 )
    {
      v40 = v3->mLookVelocity.y;
      v41 = v3->mLookVelocity.z;
      v3->mLockLookVel.x = v3->mLookVelocity.x;
      v3->mLockLookVel.y = v40;
      v3->mLockLookVel.z = v41;
      v42 = v3->mLookCurr.y;
      v43 = v3->mLookCurr.z;
      v3->mLockLookPos.x = v3->mLookCurr.x;
      v3->mLockLookPos.y = v42;
      v3->mLockLookPos.z = v43;
      v3->mLockLookParam = 0.0;
      v3->mLockLook = 1;
    }
  }
}

