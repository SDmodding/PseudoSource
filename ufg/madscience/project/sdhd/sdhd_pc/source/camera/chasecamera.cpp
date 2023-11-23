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
  unsigned int mUID; // r8d
  int v2; // edx
  UFG::qSymbol *i; // rcx

  mUID = name->mUID;
  v2 = 0;
  for ( i = &stru_142073168; mUID != i->mUID; i += 80 )
  {
    if ( (unsigned __int64)++v2 >= 0x48 )
      return UFG::gChaseParams;
  }
  return &UFG::gChaseParams[v2];
}

// File Line: 431
// RVA: 0x14BFF00
__int64 dynamic_initializer_for__UFG::ChaseCameraComponent::s_ChaseCameraComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::ChaseCameraComponent::s_ChaseCameraComponentList__);
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
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *mPrev; // rax
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::qVector4 v17; // xmm4
  UFG::qVector4 v18; // xmm3
  __m128 v19; // xmm3
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  UFG::qVector3 v32; // [rsp+48h] [rbp-80h] BYREF
  UFG::qVector3 v33[2]; // [rsp+58h] [rbp-70h] BYREF

  UFG::GameCameraComponent::GameCameraComponent(this, name_uid);
  this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>::mPrev = &this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>;
  this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>::mNext = &this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ChaseCameraComponent::`vftable;
  this->mUp.mDuration.x = 0.0099999998;
  this->mUp.mDuration.y = 0.0099999998;
  this->mUp.mDuration.z = 0.0099999998;
  this->mFov.mDuration = 0.0099999998;
  this->mEye.mDuration.x = 0.0099999998;
  this->mEye.mDuration.y = 0.0099999998;
  this->mEye.mDuration.z = 0.0099999998;
  this->mLook.mDuration.x = 0.0099999998;
  this->mLook.mDuration.y = 0.0099999998;
  this->mLook.mDuration.z = 0.0099999998;
  this->mAimEye.mDuration.x = 0.0099999998;
  this->mAimEye.mDuration.y = 0.0099999998;
  this->mAimEye.mDuration.z = 0.0099999998;
  this->mAimLook.mDuration.x = 0.0099999998;
  this->mAimLook.mDuration.y = 0.0099999998;
  this->mAimLook.mDuration.z = 0.0099999998;
  this->mDutch.mHomerCubic.mDuration = 0.0099999998;
  this->mTargetPitch.mDuration = 0.0099999998;
  this->mRecoilEye.mDuration.x = 0.0099999998;
  this->mRecoilEye.mDuration.y = 0.0099999998;
  this->mRecoilEye.mDuration.z = 0.0099999998;
  this->mYawAngVelWindowMaxTimespan = 2.0;
  *(_QWORD *)&this->mYawAngVelWindow.m_MaxTimespan = 0i64;
  this->mYawAngVelWindow.m_BufferSize = 0;
  this->mYawAngVelWindow.m_pBuffer = 0i64;
  this->mYawAngVelWindow.m_pMemoryPool = 0i64;
  *(_QWORD *)&this->mYawAngVelWindow.m_StartIndex = 0i64;
  this->mYawAngVelWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->mYawAngVelWindow.m_RunningSum, 0, 4u);
  UFG::qAverageWindow<float>::SetMaxTimespan(
    &this->mYawAngVelWindow,
    COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_2_0)),
    30.0);
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::qNoise<UFG::qVector3,UFG::qVector3>(&this->mEyeNoise);
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::qNoise<UFG::qVector3,UFG::qVector3>(&this->mLookNoise);
  UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>(&this->mTarget);
  Render::DepthOfField::Focus::Focus(&this->mDofParameters);
  this->mPreviousParameters.mNameSymbol.mUID = -1;
  mPrev = UFG::ChaseCameraComponent::s_ChaseCameraComponentList.mNode.mPrev;
  UFG::ChaseCameraComponent::s_ChaseCameraComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>;
  this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>::mNext = (UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *)&UFG::ChaseCameraComponent::s_ChaseCameraComponentList;
  UFG::ChaseCameraComponent::s_ChaseCameraComponentList.mNode.mPrev = &this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>;
  UFG::SimComponent::AddType(this, UFG::ChaseCameraComponent::_ChaseCameraComponentTypeUID, "ChaseCameraComponent");
  strcpy((char *)&this->mUp, "333?333?333?");
  BYTE1(this->mUp.mParameter.x) = 0;
  HIWORD(this->mUp.mParameter.x) = 0;
  *(_QWORD *)&this->mUp.mParameter.y = 0i64;
  *(_QWORD *)&this->mUp.v0.x = 0i64;
  *(_QWORD *)&this->mUp.v0.z = 0i64;
  *(_QWORD *)&this->mUp.v1.y = 0i64;
  *(_QWORD *)&this->mUp.p0.x = 0i64;
  *(_QWORD *)&this->mUp.p0.z = 1065353216i64;
  this->mUp.p1.y = 0.0;
  this->mUp.p1.z = 1.0;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mUp);
  *(_QWORD *)&this->mFov.mDuration = 1060320051i64;
  *(_QWORD *)&this->mFov.v0 = 0i64;
  this->mFov.p0 = 100.0;
  this->mFov.p1 = 100.0;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  strcpy((char *)&this->mEye, "333?333?333?");
  BYTE1(this->mEye.mParameter.x) = 0;
  HIWORD(this->mEye.mParameter.x) = 0;
  *(_QWORD *)&this->mEye.mParameter.y = 0i64;
  *(_QWORD *)&this->mEye.v0.x = 0i64;
  *(_QWORD *)&this->mEye.v0.z = 0i64;
  *(_QWORD *)&this->mEye.v1.y = 0i64;
  this->mEye.p0.x = -5.0;
  this->mEye.p0.y = 0.0;
  this->mEye.p0.z = 2.0;
  this->mEye.p1.x = -5.0;
  this->mEye.p1.y = 0.0;
  this->mEye.p1.z = 2.0;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  strcpy((char *)&this->mLook, "333?333?333?");
  BYTE1(this->mLook.mParameter.x) = 0;
  HIWORD(this->mLook.mParameter.x) = 0;
  *(_QWORD *)&this->mLook.mParameter.y = 0i64;
  *(_QWORD *)&this->mLook.v0.x = 0i64;
  *(_QWORD *)&this->mLook.v0.z = 0i64;
  *(_QWORD *)&this->mLook.v1.y = 0i64;
  *(_QWORD *)&this->mLook.p0.x = 0i64;
  *(_QWORD *)&this->mLook.p0.z = 0i64;
  *(_QWORD *)&this->mLook.p1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  strcpy((char *)&this->mAimEye, "333?333?333?");
  BYTE1(this->mAimEye.mParameter.x) = 0;
  HIWORD(this->mAimEye.mParameter.x) = 0;
  *(_QWORD *)&this->mAimEye.mParameter.y = 0i64;
  *(_QWORD *)&this->mAimEye.v0.x = 0i64;
  *(_QWORD *)&this->mAimEye.v0.z = 0i64;
  *(_QWORD *)&this->mAimEye.v1.y = 0i64;
  this->mAimEye.p0.x = -5.0;
  this->mAimEye.p0.y = 0.0;
  this->mAimEye.p0.z = 2.0;
  this->mAimEye.p1.x = -5.0;
  this->mAimEye.p1.y = 0.0;
  this->mAimEye.p1.z = 2.0;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
  strcpy((char *)&this->mAimLook, "333?333?333?");
  BYTE1(this->mAimLook.mParameter.x) = 0;
  HIWORD(this->mAimLook.mParameter.x) = 0;
  *(_QWORD *)&this->mAimLook.mParameter.y = 0i64;
  *(_QWORD *)&this->mAimLook.v0.x = 0i64;
  *(_QWORD *)&this->mAimLook.v0.z = 0i64;
  *(_QWORD *)&this->mAimLook.v1.y = 0i64;
  *(_QWORD *)&this->mAimLook.p0.x = 0i64;
  *(_QWORD *)&this->mAimLook.p0.z = 0i64;
  *(_QWORD *)&this->mAimLook.p1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
  *(_QWORD *)&this->mForwardAngle = 0i64;
  UFG::HomerCubicAngular::Init(&this->mDutch, 0.0, 0.0, 0.0, 0.0, 0.30000001, 6.2831855);
  v3 = UFG::ChaseCameraComponent::mTargetPitchDuration;
  if ( UFG::ChaseCameraComponent::mTargetPitchDuration <= 0.0099999998 )
    v3 = FLOAT_0_0099999998;
  this->mTargetPitch.mDuration = v3;
  this->mTargetPitch.mParameter = 0.0;
  *(_QWORD *)&this->mTargetPitch.v0 = 0i64;
  *(_QWORD *)&this->mTargetPitch.p0 = 0i64;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mTargetPitch);
  *(_QWORD *)&this->mRecoilAngle = 0i64;
  v4 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v5 = FLOAT_0_0099999998;
  else
    v5 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v6 = FLOAT_0_0099999998;
  else
    v6 = UFG::trRecoilKickbackDur;
  if ( UFG::trRecoilKickbackDur <= 0.0099999998 )
    v4 = FLOAT_0_0099999998;
  this->mRecoilEye.mDuration.x = v4;
  this->mRecoilEye.mDuration.y = v6;
  this->mRecoilEye.mDuration.z = v5;
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mRecoilEye.v0.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.v0.y = y;
  this->mRecoilEye.v0.z = z;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->mRecoilEye.v1.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.v1.y = v9;
  this->mRecoilEye.v1.z = v10;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  this->mRecoilEye.p0.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.p0.y = v11;
  this->mRecoilEye.p0.z = v12;
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  this->mRecoilEye.p1.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.p1.y = v13;
  this->mRecoilEye.p1.z = v14;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  UFG::qAverageWindow<float>::SetTimespan(
    &this->mYawAngVelWindow,
    COERCE_DOUBLE((unsigned __int64)LODWORD(this->mYawAngVelWindowMaxTimespan)),
    30.0);
  this->mYawAngVelSubmittedTimespan = this->mYawAngVelWindowMaxTimespan;
  v32.x = 0.1;
  v32.y = 0.1;
  v32.z = 0.1;
  v33[0].x = -0.1;
  v33[0].y = -0.1;
  v33[0].z = -0.1;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&this->mEyeNoise, v33, &v32);
  v33[0].x = 0.2;
  v33[0].y = 0.2;
  v33[0].z = 0.2;
  v32.x = -0.2;
  v32.y = -0.2;
  v32.z = -0.2;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&this->mLookNoise, &v32, v33);
  this->mFovRamp.x = 0.0;
  this->mFovRamp.y = 1.0;
  this->mFovRamp.z = 100.0;
  this->mFovRamp.w = 100.0;
  this->mVelocityBlendRamp.x = 0.0;
  *(_QWORD *)&this->mVelocityBlendRamp.y = 1065353216i64;
  *(_QWORD *)&this->mVelocityBlendRamp.w = 0i64;
  *(_QWORD *)&this->mNoiseMagnitudeRamp.y = 1065353216i64;
  this->mNoiseMagnitudeRamp.w = 0.0;
  this->mSafeRadius = 0.0;
  *(_DWORD *)&this->mAllowDesaturation = 16777473;
  this->mAimOrFocus = 0;
  v15 = UFG::qVector3::msZero.y;
  v16 = UFG::qVector3::msZero.z;
  this->mFocusPos.x = UFG::qVector3::msZero.x;
  this->mFocusPos.y = v15;
  this->mFocusPos.z = v16;
  this->mTargetingSystem = 0i64;
  this->pChaseParameters = 0i64;
  UFG::ChaseCameraComponent::SetChaseParameters(this, UFG::gChaseParams);
  UFG::ChaseCameraParameters::operator=(&this->mPreviousParameters, UFG::gChaseParams);
  *(_QWORD *)&this->mShakeVector.x = 0i64;
  *(_QWORD *)&this->mShakeVector.z = 0i64;
  this->mIsLookingAround = 0;
  *(_QWORD *)&this->mLookaroundAngle = 0i64;
  *(_QWORD *)&this->mLookaroundJoyInput = 0i64;
  *(_QWORD *)&this->mLookupMouse = 0i64;
  v17 = 0i64;
  v18 = 0i64;
  v18.x = (float)1;
  this->mEyeWorld.v0 = v18;
  this->mEyeWorld.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v18, (__m128)v18, 81);
  this->mEyeWorld.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v18, (__m128)v18, 69);
  this->mEyeWorld.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v18, (__m128)v18, 21);
  v19 = 0i64;
  v19.m128_f32[0] = (float)1;
  this->mWorldEye.v0 = (UFG::qVector4)v19;
  this->mWorldEye.v1 = (UFG::qVector4)_mm_shuffle_ps(v19, v19, 81);
  this->mWorldEye.v2 = (UFG::qVector4)_mm_shuffle_ps(v19, v19, 69);
  this->mWorldEye.v3 = (UFG::qVector4)_mm_shuffle_ps(v19, v19, 21);
  v17.x = (float)1;
  this->mTargetWorld.v0 = v17;
  this->mTargetWorld.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 81);
  this->mTargetWorld.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 69);
  this->mTargetWorld.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v17, (__m128)v17, 21);
  this->mLookingBack = 0;
  this->mLookbackCorrectionAngle = 0.0;
  this->mMotionblurMagnitude = 0.15000001;
  this->mDesaturation = 0.0;
  this->mOrbitLatitudeMin = -0.053410001;
  *(_QWORD *)&this->mOrbitLatitudeMax = 1048576000i64;
  this->mInAirEyeZOffset = -2.0;
  this->mInAirLookZOffset = -1.3;
  *(_QWORD *)&this->mTransitionParamEye = 0i64;
  v20 = UFG::qVector3::msZero.y;
  v21 = UFG::qVector3::msZero.z;
  this->mTransitionFromEye.x = UFG::qVector3::msZero.x;
  this->mTransitionFromEye.y = v20;
  this->mTransitionFromEye.z = v21;
  v22 = UFG::qQuaternion::msUnity.y;
  v23 = UFG::qQuaternion::msUnity.z;
  v19.m128_i32[0] = LODWORD(UFG::qQuaternion::msUnity.w);
  this->mTransitionFromOri.x = UFG::qQuaternion::msUnity.x;
  this->mTransitionFromOri.y = v22;
  this->mTransitionFromOri.z = v23;
  LODWORD(this->mTransitionFromOri.w) = v19.m128_i32[0];
  this->mTransitionFromLen = 0.0;
  this->mDofParameters.mFocalDistance = 5.0;
  this->mDofParameters.mInFocusRange = 100.0;
  *(_QWORD *)&this->mDofParameters.mNearRange = 1084227584i64;
  *(_QWORD *)&this->mDofParameters.mFarRange = 1084227584i64;
  *(_WORD *)&this->mLockEye = 0;
  v24 = UFG::qVector3::msZero.y;
  v25 = UFG::qVector3::msZero.z;
  this->mLockEyeVel.x = UFG::qVector3::msZero.x;
  this->mLockEyeVel.y = v24;
  this->mLockEyeVel.z = v25;
  v26 = UFG::qVector3::msZero.y;
  v27 = UFG::qVector3::msZero.z;
  this->mLockLookVel.x = UFG::qVector3::msZero.x;
  this->mLockLookVel.y = v26;
  this->mLockLookVel.z = v27;
  v28 = UFG::qVector3::msZero.y;
  v29 = UFG::qVector3::msZero.z;
  this->mLockEyePos.x = UFG::qVector3::msZero.x;
  this->mLockEyePos.y = v28;
  this->mLockEyePos.z = v29;
  v30 = UFG::qVector3::msZero.y;
  v31 = UFG::qVector3::msZero.z;
  this->mLockLookPos.x = UFG::qVector3::msZero.x;
  this->mLockLookPos.y = v30;
  this->mLockLookPos.z = v31;
  *(_QWORD *)&this->mLockEyeParam = 0i64;
  *(_QWORD *)&this->mAimParam = 0i64;
  *(_QWORD *)&this->mBlendPrevious = 0i64;
  ++UFG::ChaseCameraComponent::mNumChaseCameraInstances;
}

// File Line: 755
// RVA: 0x3BDC70
void __fastcall UFG::ChaseCameraComponent::~ChaseCameraComponent(UFG::ChaseCameraComponent *this)
{
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v2; // rdi
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *mPrev; // rcx
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *mNext; // rax
  UFG::qMemoryPool *m_pMemoryPool; // rcx
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v6; // rcx
  UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent> *v7; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ChaseCameraComponent::`vftable;
  --UFG::ChaseCameraComponent::mNumChaseCameraInstances;
  if ( this == UFG::ChaseCameraComponent::s_ChaseCameraComponentpCurrentIterator )
    UFG::ChaseCameraComponent::s_ChaseCameraComponentpCurrentIterator = (UFG::ChaseCameraComponent *)&this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>::mPrev[-78];
  v2 = &this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>;
  mPrev = this->UFG::qNode<UFG::ChaseCameraComponent,UFG::ChaseCameraComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->mTarget);
  m_pMemoryPool = this->mYawAngVelWindow.m_pMemoryPool;
  if ( m_pMemoryPool )
    UFG::qMemoryPool::Free(m_pMemoryPool, (char *)this->mYawAngVelWindow.m_pBuffer);
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::GameCameraComponent::~GameCameraComponent(this);
}

// File Line: 875
// RVA: 0x3C5540
bool __fastcall UFG::ChaseCameraComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentChaseCamera);
}

// File Line: 881
// RVA: 0x3C80A0
UFG::ChaseCameraComponent *__fastcall UFG::ChaseCameraComponent::PropertiesOnActivate(
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
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xD60ui64, "ChaseCameraComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::ChaseCameraComponent::ChaseCameraComponent((UFG::ChaseCameraComponent *)v4, m_NameUID);
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
  return (UFG::ChaseCameraComponent *)v6;
}

// File Line: 890
// RVA: 0x3BFD30
void __fastcall UFG::ChaseCameraComponent::BlendParameters(
        UFG::ChaseCameraComponent *this,
        UFG::ChaseCameraParameters *dest,
        UFG::ChaseCameraParameters *a,
        UFG::ChaseCameraParameters *b,
        float blend_a)
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
float __fastcall UFG::ChaseCameraComponent::GetBlendSeconds(
        UFG::ChaseCameraComponent *this,
        UFG::ChaseCameraContext from_context,
        UFG::ChaseCameraContext to_context)
{
  int v3; // ecx
  UFG::ChaseCameraContextBlend *v4; // rax

  v3 = 18;
  v4 = &UFG::gChaseBlends[18];
  while ( from_context != v4->mFromContext || to_context != v4->mToContext )
  {
    --v4;
    --v3;
    if ( (__int64)v4 < (__int64)UFG::gChaseBlends )
      return 0.0;
  }
  return UFG::gChaseBlends[v3].mBlendSeconds;
}

// File Line: 978
// RVA: 0x3C6C70
void __fastcall UFG::MakeMonotonic(float *data, int num)
{
  __int64 v2; // r8
  __int64 v3; // r9
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
void __fastcall UFG::ChaseCameraComponent::SetChaseParameters(
        UFG::ChaseCameraComponent *this,
        UFG::ChaseCameraParameters *parameters)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float *mEyeOffsetDomain; // rcx
  float w; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
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
  float mNoiseAmplitude; // xmm7_4
  float v27; // xmm6_4
  float mNoiseDecay; // xmm0_4
  float v29; // xmm7_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  int mNoiseOctaves; // eax
  int v33; // r15d
  float v34; // xmm1_4
  float v35; // xmm0_4
  int mNoiseFrequency_low; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  int v40; // eax
  float v41; // xmm1_4
  float v42; // xmm0_4
  int v43; // xmm1_4
  bool v44; // zf
  float mAimWobbleRadiusMin; // eax
  float mAimWobbleAxisWeight; // xmm3_4
  float mAimWobbleFreq; // xmm2_4
  float mAimWobbleRadiusMax; // xmm0_4
  double v49; // xmm0_8
  UFG::qVector3 *Value; // rax
  float v51; // xmm0_4
  float v52; // xmm1_4
  UFG::qVector3 *v53; // rax
  float v54; // xmm0_4
  float v55; // xmm1_4
  UFG::LinearGraph<UFG::qVector3> v56; // [rsp+20h] [rbp-50h] BYREF
  UFG::qVector3 result; // [rsp+38h] [rbp-38h] BYREF

  y = parameters->mFovRamp.y;
  z = parameters->mFovRamp.z;
  mEyeOffsetDomain = this->mEyeOffsetDomain;
  w = parameters->mFovRamp.w;
  mEyeOffsetDomain[32] = parameters->mFovRamp.x;
  mEyeOffsetDomain[33] = y;
  mEyeOffsetDomain[34] = z;
  mEyeOffsetDomain[35] = w;
  v8 = parameters->mVelocityBlendRamp.y;
  v9 = parameters->mVelocityBlendRamp.z;
  v10 = parameters->mVelocityBlendRamp.w;
  mEyeOffsetDomain[24] = parameters->mVelocityBlendRamp.x;
  mEyeOffsetDomain[25] = v8;
  mEyeOffsetDomain[26] = v9;
  mEyeOffsetDomain[27] = v10;
  v11 = parameters->mNoiseMagnitudeRamp.y;
  v12 = parameters->mNoiseMagnitudeRamp.z;
  v13 = parameters->mNoiseMagnitudeRamp.w;
  mEyeOffsetDomain[28] = parameters->mNoiseMagnitudeRamp.x;
  mEyeOffsetDomain[29] = v11;
  mEyeOffsetDomain[30] = v12;
  mEyeOffsetDomain[31] = v13;
  *mEyeOffsetDomain = parameters->mEyeOffsetLo.w;
  this->mEyeOffsetDomain[1] = parameters->mEyeOffsetMed.w;
  this->mEyeOffsetDomain[2] = parameters->mEyeOffsetHi.w;
  this->mTargetOffsetDomain[0] = parameters->mTargetOffsetLo.w;
  this->mTargetOffsetDomain[1] = parameters->mTargetOffsetMed.w;
  this->mTargetOffsetDomain[2] = parameters->mTargetOffsetHi.w;
  UFG::MakeMonotonic(mEyeOffsetDomain, 3);
  UFG::MakeMonotonic(this->mTargetOffsetDomain, 3);
  v14 = parameters->mEyeOffsetLo.y;
  v15 = parameters->mEyeOffsetLo.z;
  this->mEyeOffsetRange[0].x = parameters->mEyeOffsetLo.x;
  this->mEyeOffsetRange[0].y = v14;
  this->mEyeOffsetRange[0].z = v15;
  v16 = parameters->mEyeOffsetMed.y;
  v17 = parameters->mEyeOffsetMed.z;
  this->mEyeOffsetRange[1].x = parameters->mEyeOffsetMed.x;
  this->mEyeOffsetRange[1].y = v16;
  this->mEyeOffsetRange[1].z = v17;
  v18 = parameters->mEyeOffsetHi.y;
  v19 = parameters->mEyeOffsetHi.z;
  this->mEyeOffsetRange[2].x = parameters->mEyeOffsetHi.x;
  this->mEyeOffsetRange[2].y = v18;
  this->mEyeOffsetRange[2].z = v19;
  v20 = parameters->mTargetOffsetLo.y;
  v21 = parameters->mTargetOffsetLo.z;
  this->mTargetOffsetRange[0].x = parameters->mTargetOffsetLo.x;
  this->mTargetOffsetRange[0].y = v20;
  this->mTargetOffsetRange[0].z = v21;
  v22 = parameters->mTargetOffsetMed.y;
  v23 = parameters->mTargetOffsetMed.z;
  this->mTargetOffsetRange[1].x = parameters->mTargetOffsetMed.x;
  this->mTargetOffsetRange[1].y = v22;
  this->mTargetOffsetRange[1].z = v23;
  v24 = parameters->mTargetOffsetHi.y;
  v25 = parameters->mTargetOffsetHi.z;
  this->mTargetOffsetRange[2].x = parameters->mTargetOffsetHi.x;
  this->mTargetOffsetRange[2].y = v24;
  this->mTargetOffsetRange[2].z = v25;
  this->mOrbitSpeed = parameters->mOrbitSpeed;
  this->mCenteringSpeedMin = parameters->mCenteringSpeedMin;
  this->mCenteringSpeedMax = parameters->mCenteringSpeedMax;
  this->mReverseSpeed = parameters->mReverseSpeed;
  this->mLurch = parameters->mLurch;
  this->mTilt = parameters->mTilt;
  this->mYawAngVelTimespan = parameters->mYawAngVelTimespan;
  this->mLookOffsetMax = parameters->mLookOffsetMax;
  this->mLookOffsetAngVelMin = parameters->mLookOffsetAngVelMin;
  this->mLookOffsetAngVelMax = parameters->mLookOffsetAngVelMax;
  this->mPitchOffsetMax = parameters->mPitchOffsetMax;
  this->mPitchOffsetLookFactorUp = parameters->mPitchOffsetLookFactorUp;
  this->mPitchOffsetLookFactorDown = parameters->mPitchOffsetLookFactorDown;
  this->mPitchOffsetEyeFactorUp = parameters->mPitchOffsetEyeFactorUp;
  this->mPitchOffsetEyeFactorDown = parameters->mPitchOffsetEyeFactorDown;
  mNoiseAmplitude = parameters->mNoiseAmplitude;
  *(float *)&v56.nData = mNoiseAmplitude;
  *((float *)&v56.nData + 1) = mNoiseAmplitude;
  *(float *)&v56.fDomain = mNoiseAmplitude;
  LODWORD(result.x) = LODWORD(mNoiseAmplitude) ^ _xmm[0];
  LODWORD(result.y) = LODWORD(mNoiseAmplitude) ^ _xmm[0];
  LODWORD(result.z) = LODWORD(mNoiseAmplitude) ^ _xmm[0];
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&this->mEyeNoise, &result, (UFG::qVector3 *)&v56);
  result.x = mNoiseAmplitude;
  result.y = mNoiseAmplitude;
  result.z = mNoiseAmplitude;
  v56.nData = LODWORD(mNoiseAmplitude) ^ _xmm[0];
  *(&v56.nData + 1) = LODWORD(mNoiseAmplitude) ^ _xmm[0];
  LODWORD(v56.fDomain) = LODWORD(mNoiseAmplitude) ^ _xmm[0];
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetRange(&this->mLookNoise, (UFG::qVector3 *)&v56, &result);
  v27 = 0.0;
  mNoiseDecay = parameters->mNoiseDecay;
  v29 = *(float *)&FLOAT_1_0;
  if ( mNoiseDecay <= 0.0 )
  {
    v30 = 0.0;
  }
  else
  {
    v30 = parameters->mNoiseDecay;
    if ( mNoiseDecay >= 1.0 )
      v30 = *(float *)&FLOAT_1_0;
  }
  if ( mNoiseDecay <= 0.0 )
  {
    v31 = 0.0;
  }
  else
  {
    v31 = parameters->mNoiseDecay;
    if ( mNoiseDecay >= 1.0 )
      v31 = *(float *)&FLOAT_1_0;
  }
  if ( mNoiseDecay <= 0.0 )
  {
    mNoiseDecay = 0.0;
  }
  else if ( mNoiseDecay >= 1.0 )
  {
    mNoiseDecay = *(float *)&FLOAT_1_0;
  }
  this->mEyeNoise.tDecay.x = mNoiseDecay;
  this->mEyeNoise.tDecay.y = v31;
  this->mEyeNoise.tDecay.z = v30;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&this->mEyeNoise);
  mNoiseOctaves = parameters->mNoiseOctaves;
  v33 = 31;
  if ( mNoiseOctaves <= 1 )
  {
    mNoiseOctaves = 1;
  }
  else if ( mNoiseOctaves >= 31 )
  {
    mNoiseOctaves = 31;
  }
  this->mEyeNoise.nOctaves = mNoiseOctaves;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&this->mEyeNoise);
  v34 = this->mEye.p0.y;
  result.x = this->mEye.p0.x;
  v35 = this->mEye.p0.z;
  result.y = v34;
  mNoiseFrequency_low = LODWORD(parameters->mNoiseFrequency);
  result.z = v35;
  v56.nData = mNoiseFrequency_low;
  *(&v56.nData + 1) = mNoiseFrequency_low;
  LODWORD(v56.fDomain) = mNoiseFrequency_low;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetFrequency(&this->mEyeNoise, (UFG::qVector3 *)&v56, &result);
  v37 = parameters->mNoiseDecay;
  if ( v37 <= 0.0 )
  {
    v38 = 0.0;
  }
  else
  {
    v38 = parameters->mNoiseDecay;
    if ( v37 >= 1.0 )
      v38 = *(float *)&FLOAT_1_0;
  }
  if ( v37 <= 0.0 )
  {
    v39 = 0.0;
  }
  else
  {
    v39 = parameters->mNoiseDecay;
    if ( v37 >= 1.0 )
      v39 = *(float *)&FLOAT_1_0;
  }
  if ( v37 <= 0.0 )
  {
    v37 = 0.0;
    goto LABEL_29;
  }
  if ( v37 < 1.0 )
LABEL_29:
    v29 = v37;
  this->mLookNoise.tDecay.x = v29;
  this->mLookNoise.tDecay.y = v39;
  this->mLookNoise.tDecay.z = v38;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&this->mLookNoise);
  v40 = parameters->mNoiseOctaves;
  if ( v40 <= 1 )
  {
    v40 = 1;
    goto LABEL_34;
  }
  if ( v40 < 31 )
LABEL_34:
    v33 = v40;
  this->mLookNoise.nOctaves = v33;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::Init(&this->mLookNoise);
  v41 = this->mLook.p0.y;
  result.x = this->mLook.p0.x;
  v42 = this->mLook.p0.z;
  result.y = v41;
  v43 = LODWORD(parameters->mNoiseFrequency);
  result.z = v42;
  v56.nData = v43;
  *(&v56.nData + 1) = v43;
  LODWORD(v56.fDomain) = v43;
  UFG::qNoise<UFG::qVector3,UFG::qVector3>::SetFrequency(&this->mLookNoise, (UFG::qVector3 *)&v56, &result);
  v44 = this->mTarget.m_pSimComponent == 0i64;
  mAimWobbleRadiusMin = parameters->mAimWobbleRadiusMin;
  mAimWobbleAxisWeight = parameters->mAimWobbleAxisWeight;
  mAimWobbleFreq = parameters->mAimWobbleFreq;
  mAimWobbleRadiusMax = parameters->mAimWobbleRadiusMax;
  this->rAimWobbleRadiusPeriod = parameters->mAimWobbleRadiusPeriod;
  this->rAimWobbleFreq = mAimWobbleFreq;
  this->rAimWobbleRadiusMin = mAimWobbleRadiusMin;
  this->rAimWobbleRadiusMax = mAimWobbleRadiusMax;
  this->rAimWobbleAxisWeight = mAimWobbleAxisWeight;
  this->mAimFreeDuration = parameters->mAimFreeDuration;
  this->mAimLockedDuration = parameters->mAimLockedDuration;
  this->mDesaturation = parameters->mDesaturation;
  this->mMotionblurMagnitude = parameters->mMotionblurMagnitude;
  this->mDofParameters.mNearRange = parameters->mDofNearRange;
  this->mDofParameters.mNearBlurRadius = parameters->mDofNearBlur;
  this->mDofParameters.mFarRange = parameters->mDofFarRange;
  this->mDofParameters.mFarBlurRadius = parameters->mDofFarBlur;
  this->mDofParameters.mInFocusRange = parameters->mDof;
  this->mOrbitLatitudeMin = parameters->mOrbitLatitudeMin;
  this->mOrbitLatitudeMax = parameters->mOrbitLatitudeMax;
  this->mOrbitHeightMinOffset = parameters->mOrbitHeightMinOffset;
  this->mInAirEyeZOffset = parameters->mInAirEyeZOffset;
  this->mInAirLookZOffset = parameters->mInAirLookZOffset;
  if ( !v44 )
  {
    v49 = ((double (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[28].__vecDelDtor)(this->mTarget.m_pSimComponent);
    v27 = *(float *)&v49;
  }
  if ( UFG::ChaseCameraComponent::bOverrideSpeedInput )
    v27 = UFG::ChaseCameraComponent::mOverrideSpeed;
  v56.nData = 3;
  v56.tRange = this->mTargetOffsetRange;
  v56.fDomain = this->mTargetOffsetDomain;
  Value = UFG::LinearGraph<UFG::qVector3>::GetValue(&v56, &result, v27);
  v51 = Value->y;
  v52 = Value->z;
  this->mTargetOffset.x = Value->x;
  this->mTargetOffset.y = v51;
  this->mTargetOffset.z = v52;
  if ( this->mUpdateEyeOffset )
  {
    v56.nData = 3;
    v56.tRange = this->mEyeOffsetRange;
    v56.fDomain = this->mEyeOffsetDomain;
    v53 = UFG::LinearGraph<UFG::qVector3>::GetValue(&v56, &result, v27);
    v54 = v53->y;
    v55 = v53->z;
    this->mEyeOffset.x = v53->x;
    this->mEyeOffset.y = v54;
    this->mEyeOffset.z = v55;
  }
}

// File Line: 1090
// RVA: 0x3C18B0
void __fastcall UFG::ChaseCameraComponent::DetermineChaseParameters(UFG::ChaseCameraComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::ChaseCameraParameters *pChaseParametersFlee; // rbx
  UFG::SimObjectCharacter *v4; // rcx
  UFG::SimObjectCharacter **v5; // rsi
  __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfTypeHK; // rax
  UFG::VehicleSubjectComponent *v8; // rcx
  bool v9; // zf
  UFG::VehicleSubjectComponent *v10; // rax
  UFG::TargetingSystemVehicleComponent *TargetingSystemVehicle; // rax
  UFG::ActionHijackProfile *m_pActionHijackProfile; // rax
  UFG::VehicleSubjectComponent *v13; // rbx
  UFG::qVector3 *v14; // rax
  int BoxSide; // r8d
  UFG::ChaseCameraParameters *pChaseParameters; // rsi
  float BlendSeconds; // xmm0_4
  float v18; // xmm0_4
  float w; // xmm0_4
  float y; // xmm6_4
  float z; // xmm7_4
  float x; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float blend_a; // xmm0_4
  UFG::ChaseCameraComponent *v31; // rcx
  UFG::ChaseCameraParameters *p_dest; // rdx
  UFG::ChaseCameraParameters dest; // [rsp+30h] [rbp-178h] BYREF

  m_pSimComponent = this->mTarget.m_pSimComponent;
  pChaseParametersFlee = UFG::gChaseParams;
  if ( m_pSimComponent )
  {
    v4 = *(UFG::SimObjectCharacter **)&m_pSimComponent[13].m_TypeUID;
    if ( v4 )
    {
      m_Flags = v4->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v4);
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v4,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                v4,
                                                                UFG::CharacterSubjectComponent::_TypeUID);
      }
      v5 = (UFG::SimObjectCharacter **)ComponentOfTypeHK;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = (UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent;
    if ( v8->bFleeing )
    {
      pChaseParametersFlee = v8->pChaseParametersFlee;
    }
    else if ( UFG::VehicleSubjectComponent::IsRacing(v8) )
    {
      pChaseParametersFlee = (UFG::ChaseCameraParameters *)this->mTarget.m_pSimComponent[14].vfptr;
    }
    else
    {
      v9 = ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[32].__vecDelDtor)(this->mTarget.m_pSimComponent) == 0;
      v10 = (UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent;
      if ( v9 )
        pChaseParametersFlee = v10->pChaseParametersPassenger;
      else
        pChaseParametersFlee = v10->pChaseParametersDrive;
    }
    if ( v5 && UFG::IsAnyLocalPlayer(v5[5]) )
    {
      TargetingSystemVehicle = UFG::VehicleSubjectComponent::GetTargetingSystemVehicle((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent);
      if ( TargetingSystemVehicle
        && (m_pActionHijackProfile = TargetingSystemVehicle->m_pActionHijackProfile) != 0i64
        && !m_pActionHijackProfile->m_bCanActionHijackClimb )
      {
        pChaseParametersFlee = (UFG::ChaseCameraParameters *)this->mTarget.m_pSimComponent[15].m_SafePointerList.mNode.mNext;
      }
      else
      {
        v13 = (UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent;
        v14 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimObjectCharacter **))(*v5)->mComponentTableEntries)(v5);
        BoxSide = UFG::VehicleSubjectComponent::GetBoxSide(v13, v14);
        if ( BoxSide )
        {
          if ( BoxSide == 1 || BoxSide == 4 )
          {
            pChaseParametersFlee = (UFG::ChaseCameraParameters *)this->mTarget.m_pSimComponent[15].vfptr;
            this->mHijackerLeft = BoxSide == 1;
          }
          else
          {
            pChaseParametersFlee = (UFG::ChaseCameraParameters *)this->mTarget.m_pSimComponent[14].m_BoundComponentHandles.mNode.mNext;
          }
        }
        else
        {
          pChaseParametersFlee = (UFG::ChaseCameraParameters *)this->mTarget.m_pSimComponent[15].m_SafePointerList.mNode.mPrev;
        }
      }
    }
    else if ( this->mAimOrFocus )
    {
      this->mSnapNext = 0;
      pChaseParametersFlee = (UFG::ChaseCameraParameters *)this->mTarget.m_pSimComponent[13].m_BoundComponentHandles.mNode.mPrev;
    }
    pChaseParameters = this->pChaseParameters;
    if ( pChaseParameters != pChaseParametersFlee )
    {
      if ( this->mSnapNext || !pChaseParameters )
      {
        *(_QWORD *)&this->mBlendPrevious = 0i64;
      }
      else
      {
        BlendSeconds = UFG::ChaseCameraComponent::GetBlendSeconds(
                         this,
                         pChaseParameters->mContext,
                         pChaseParametersFlee->mContext);
        this->mBlendSeconds = BlendSeconds;
        if ( BlendSeconds <= 0.0 )
          v18 = 0.0;
        else
          v18 = *(float *)&FLOAT_1_0;
        this->mBlendPrevious = v18;
        UFG::ChaseCameraParameters::operator=(&this->mPreviousParameters, pChaseParameters);
        w = this->mPreviousParameters.mEyeOffsetLo.w;
        y = this->mLook.p0.y;
        z = this->mLook.p0.z;
        x = this->mEye.p0.x;
        v23 = this->mEye.p0.y;
        v24 = this->mEye.p0.z;
        v25 = this->mLook.p0.x;
        this->mPreviousParameters.mEyeOffsetLo.x = x;
        this->mPreviousParameters.mEyeOffsetLo.y = v23;
        this->mPreviousParameters.mEyeOffsetLo.z = v24;
        this->mPreviousParameters.mEyeOffsetLo.w = w;
        this->mPreviousParameters.mEyeOffsetMed.w = this->mPreviousParameters.mEyeOffsetMed.w;
        this->mPreviousParameters.mEyeOffsetMed.x = x;
        this->mPreviousParameters.mEyeOffsetMed.y = v23;
        this->mPreviousParameters.mEyeOffsetMed.z = v24;
        v26 = this->mPreviousParameters.mEyeOffsetHi.w;
        this->mPreviousParameters.mEyeOffsetHi.x = x;
        this->mPreviousParameters.mEyeOffsetHi.w = v26;
        this->mPreviousParameters.mEyeOffsetHi.y = v23;
        this->mPreviousParameters.mEyeOffsetHi.z = v24;
        v27 = this->mPreviousParameters.mTargetOffsetLo.w;
        this->mPreviousParameters.mTargetOffsetLo.y = y;
        this->mPreviousParameters.mTargetOffsetLo.z = z;
        this->mPreviousParameters.mTargetOffsetLo.w = v27;
        this->mPreviousParameters.mTargetOffsetLo.x = v25;
        v28 = this->mPreviousParameters.mTargetOffsetMed.w;
        this->mPreviousParameters.mTargetOffsetMed.y = y;
        this->mPreviousParameters.mTargetOffsetMed.z = z;
        this->mPreviousParameters.mTargetOffsetMed.w = v28;
        this->mPreviousParameters.mTargetOffsetMed.x = v25;
        v29 = this->mPreviousParameters.mTargetOffsetHi.w;
        this->mPreviousParameters.mTargetOffsetHi.y = y;
        this->mPreviousParameters.mTargetOffsetHi.z = z;
        this->mPreviousParameters.mTargetOffsetHi.w = v29;
        this->mPreviousParameters.mTargetOffsetHi.x = v25;
      }
    }
  }
  blend_a = this->mBlendPrevious;
  this->pChaseParameters = pChaseParametersFlee;
  v31 = this;
  if ( blend_a <= 0.0 )
  {
    p_dest = pChaseParametersFlee;
  }
  else
  {
    dest.mNameSymbol.mUID = -1;
    UFG::ChaseCameraComponent::BlendParameters(this, &dest, &this->mPreviousParameters, pChaseParametersFlee, blend_a);
    p_dest = &dest;
    v31 = this;
  }
  UFG::ChaseCameraComponent::SetChaseParameters(v31, p_dest);
}

// File Line: 1197
// RVA: 0x3C34C0
void __fastcall UFG::ChaseCameraComponent::GetFovRadians(
        UFG::ChaseCameraComponent *this,
        float *fov,
        float *fov_velocity)
{
  *fov_velocity = (float)(this->mFov.v0 * 3.1415927) * 0.0055555557;
  *fov = (float)(this->mFov.p0 * 3.1415927) * 0.0055555557;
}

// File Line: 1203
// RVA: 0x3CC960
void __fastcall UFG::ChaseCameraComponent::SetFovRadians(
        UFG::ChaseCameraComponent *this,
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

// File Line: 1210
// RVA: 0x3CC4B0
void __fastcall UFG::ChaseCameraComponent::SetEyeWorld(
        UFG::ChaseCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  UFG::qVector3 *v6; // rax
  UFG::HomerCubic<UFG::qVector3> *p_mEye; // rcx
  float v8; // xmm7_4
  float v9; // xmm3_4
  float y; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm10_4
  float z; // xmm5_4
  float v14; // xmm4_4
  float x; // xmm2_4
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
  float v29; // [rsp+B8h] [rbp+10h]
  float v30; // [rsp+C0h] [rbp+18h]
  float v31; // [rsp+C8h] [rbp+20h]

  if ( this->mTarget.m_pSimComponent )
    v6 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)(this->mTarget.m_pSimComponent);
  else
    v6 = &UFG::qVector3::msZero;
  p_mEye = &this->mEye;
  v8 = velocity->x - v6->x;
  v9 = velocity->y - v6->y;
  y = this->mWorldEye.v1.y;
  v11 = velocity->z - v6->z;
  v12 = this->mWorldEye.v2.y;
  z = this->mWorldEye.v2.z;
  v29 = this->mWorldEye.v0.y;
  v30 = (float)((float)((float)(this->mWorldEye.v0.x * v8) + (float)(this->mWorldEye.v1.x * v9))
              + (float)(this->mWorldEye.v2.x * v11))
      + (float)(this->mWorldEye.v3.x * 0.0);
  v31 = (float)((float)((float)(v29 * v8) + (float)(y * v9)) + (float)(v12 * v11)) + (float)(this->mWorldEye.v3.y * 0.0);
  v14 = this->mWorldEye.v1.z;
  x = this->mEye.mDuration.x;
  v16 = this->mEye.mDuration.z;
  v17 = position->y;
  v28 = (float)((float)((float)((float)(velocity->y - v6->y) * v14) + (float)(this->mWorldEye.v0.z * v8))
              + (float)(v11 * z))
      + (float)(this->mWorldEye.v3.z * 0.0);
  v18 = position->z;
  v19 = this->mWorldEye.v2.x * v18;
  v20 = v12 * v18;
  v21 = (float)((float)(position->x * this->mWorldEye.v0.z) + (float)(v17 * v14)) + (float)(v18 * z);
  v22 = this->mEye.mDuration.y;
  v23 = v21 + this->mWorldEye.v3.z;
  v24 = (float)((float)((float)(this->mWorldEye.v0.x * position->x) + (float)(this->mWorldEye.v1.x * v17)) + v19)
      + this->mWorldEye.v3.x;
  v25 = (float)((float)((float)(v29 * position->x) + (float)(y * v17)) + v20) + this->mWorldEye.v3.y;
  if ( v16 <= 0.0099999998 )
    v16 = FLOAT_0_0099999998;
  if ( v22 <= 0.0099999998 )
    v22 = FLOAT_0_0099999998;
  if ( x <= 0.0099999998 )
    x = FLOAT_0_0099999998;
  p_mEye->mDuration.x = x;
  this->mEye.mDuration.y = v22;
  this->mEye.mDuration.z = v16;
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  this->mEye.v0.y = v31;
  this->mEye.v0.z = v28;
  this->mEye.v0.x = v30;
  v26 = UFG::qVector3::msZero.y;
  v27 = UFG::qVector3::msZero.z;
  this->mEye.v1.x = UFG::qVector3::msZero.x;
  this->mEye.v1.y = v26;
  this->mEye.v1.z = v27;
  this->mEye.p0.x = v24;
  this->mEye.p0.y = v25;
  this->mEye.p0.z = v23;
  this->mEye.p1.x = v24;
  this->mEye.p1.y = v25;
  this->mEye.p1.z = v23;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mEye);
}

// File Line: 1220
// RVA: 0x3CCC70
void __fastcall UFG::ChaseCameraComponent::SetLookWorld(
        UFG::ChaseCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  UFG::qMatrix44 *v6; // rdi
  UFG::qVector3 *v7; // rax
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rbx
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  float z; // xmm0_4
  float v19; // xmm5_4
  float v20; // xmm6_4

  if ( this->mTarget.m_pSimComponent )
    v6 = (UFG::qMatrix44 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[19].__vecDelDtor)(this->mTarget.m_pSimComponent);
  else
    v6 = &UFG::qMatrix44::msIdentity;
  if ( this->mTarget.m_pSimComponent )
    v7 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)(this->mTarget.m_pSimComponent);
  else
    v7 = &UFG::qVector3::msZero;
  p_mLook = &this->mLook;
  v9 = velocity->x - v7->x;
  v10 = velocity->y - v7->y;
  v11 = velocity->z - v7->z;
  v12 = (float)((float)(v9 * v6->v0.x) + (float)(v10 * v6->v1.x)) + (float)(v11 * v6->v2.x);
  v13 = v9 * v6->v0.y;
  v14 = v11 * v6->v2.y;
  v15 = (float)(v9 * v6->v0.z) + (float)(v10 * v6->v1.z);
  v16 = v11 * v6->v2.z;
  v17 = (float)((float)((float)(v10 * v6->v1.y) + v13) + v14) + (float)(v6->v3.y * 0.0);
  z = v6->v3.z;
  p_mLook->v0.x = v12 + (float)(v6->v3.x * 0.0);
  p_mLook->v0.y = v17;
  p_mLook->v0.z = (float)(v15 + v16) + (float)(z * 0.0);
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
  v19 = (float)((float)((float)(position->y * v6->v1.x) + (float)(position->x * v6->v0.x))
              + (float)(position->z * v6->v2.x))
      + v6->v3.x;
  v20 = (float)((float)((float)(position->y * v6->v1.z) + (float)(position->x * v6->v0.z))
              + (float)(position->z * v6->v2.z))
      + v6->v3.z;
  p_mLook->p0.y = (float)((float)((float)(position->x * v6->v0.y) + (float)(position->y * v6->v1.y))
                        + (float)(position->z * v6->v2.y))
                + v6->v3.y;
  p_mLook->p0.x = v19;
  p_mLook->p0.z = v20;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(p_mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
}

// File Line: 1228
// RVA: 0x3C3070
void __fastcall UFG::ChaseCameraComponent::GetEyeWorld(
        UFG::ChaseCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  float y; // xmm3_4
  float z; // xmm5_4
  float x; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm7_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float *v17; // rax
  float v18; // xmm2_4
  float v19; // xmm1_4
  float *v20; // rax
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float *v24; // rax
  float v25; // xmm3_4
  float v26; // xmm0_4
  float v27; // xmm6_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm3_4
  float v35; // xmm1_4

  if ( this->mTarget.m_pSimComponent )
  {
    y = this->mEye.p0.y;
    z = this->mEye.p0.z;
    x = this->mEye.p0.x;
    v9 = (float)((float)((float)(x * this->mEyeWorld.v0.x) + (float)(y * this->mEyeWorld.v1.x))
               + (float)(z * this->mEyeWorld.v2.x))
       + this->mEyeWorld.v3.x;
    v10 = (float)((float)((float)(y * this->mEyeWorld.v1.y) + (float)(x * this->mEyeWorld.v0.y))
                + (float)(z * this->mEyeWorld.v2.y))
        + this->mEyeWorld.v3.y;
    position->z = (float)((float)((float)(x * this->mEyeWorld.v0.z) + (float)(y * this->mEyeWorld.v1.z))
                        + (float)(z * this->mEyeWorld.v2.z))
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
    m_pSimComponent = this->mTarget.m_pSimComponent;
    vfptr = m_pSimComponent->vfptr;
    velocity->y = v13;
    velocity->z = v12 + (float)(v14 * 0.0);
    v17 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))vfptr[20].__vecDelDtor)(m_pSimComponent);
    v18 = v17[1] + velocity->y;
    v19 = v17[2] + velocity->z;
    velocity->x = *v17 + velocity->x;
    velocity->y = v18;
    velocity->z = v19;
    v20 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
    v21 = position->x - *v20;
    v22 = position->y - v20[1];
    v23 = position->z - v20[2];
    v24 = (float *)this->mTarget.m_pSimComponent;
    v25 = v24[148];
    v26 = v24[150];
    v27 = v26 * v21;
    v28 = v24[149] * v21;
    v29 = (float)(v24[149] * v23) - (float)(v26 * v22);
    v30 = v25 * v23;
    velocity->x = v29 + velocity->x;
    v31 = (float)((float)(v25 * v22) - v28) + velocity->z;
    velocity->y = (float)(v27 - v30) + velocity->y;
    velocity->z = v31;
  }
  else
  {
    v32 = UFG::qVector3::msZero.y;
    v33 = UFG::qVector3::msZero.z;
    position->x = UFG::qVector3::msZero.x;
    position->y = v32;
    position->z = v33;
    v34 = UFG::qVector3::msZero.y;
    v35 = UFG::qVector3::msZero.z;
    velocity->x = UFG::qVector3::msZero.x;
    velocity->y = v34;
    velocity->z = v35;
  }
}

// File Line: 1244
// RVA: 0x3C3620
void __fastcall UFG::ChaseCameraComponent::GetLookWorld(
        UFG::ChaseCameraComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *velocity)
{
  float *v6; // rax
  float x; // xmm2_4
  float *v8; // rbx
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm8_4
  float *v12; // rax
  UFG::SimComponent *m_pSimComponent; // rcx
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm8_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float v18; // xmm0_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm8_4
  float *v22; // rax
  float v23; // xmm6_4
  float v24; // xmm8_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4

  if ( this->mTarget.m_pSimComponent )
  {
    v6 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTarget.m_pSimComponent);
    x = this->mLook.p0.x;
    v8 = v6;
    v9 = (float)((float)(x * *v6) + (float)(this->mLook.p0.y * v6[4])) + (float)(this->mLook.p0.z * v6[8]);
    v10 = (float)((float)(x * v6[1]) + (float)(this->mLook.p0.y * v6[5])) + (float)(this->mLook.p0.z * v6[9]);
    v11 = (float)((float)(this->mLook.p0.y * v6[6]) + (float)(x * v6[2])) + (float)(this->mLook.p0.z * v6[10]);
    v12 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
    m_pSimComponent = this->mTarget.m_pSimComponent;
    v14 = v9 + *v12;
    v15 = v10 + v12[1];
    v16 = v11 + v12[2];
    vfptr = m_pSimComponent->vfptr;
    position->x = v14;
    position->y = v15;
    position->z = v16;
    v18 = this->mLook.v0.x;
    v19 = (float)((float)(v18 * *v8) + (float)(this->mLook.v0.y * v8[4])) + (float)(this->mLook.v0.z * v8[8]);
    v20 = (float)((float)(this->mLook.v0.y * v8[5]) + (float)(v18 * v8[1])) + (float)(this->mLook.v0.z * v8[9]);
    v21 = (float)((float)(this->mLook.v0.y * v8[6]) + (float)(v18 * v8[2])) + (float)(this->mLook.v0.z * v8[10]);
    v22 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))vfptr[20].__vecDelDtor)(m_pSimComponent);
    v23 = v20 + v22[1];
    v24 = v21 + v22[2];
    velocity->x = v19 + *v22;
    velocity->y = v23;
    velocity->z = v24;
  }
  else
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    position->x = UFG::qVector3::msZero.x;
    position->y = y;
    position->z = z;
    v27 = UFG::qVector3::msZero.y;
    v28 = UFG::qVector3::msZero.z;
    velocity->x = UFG::qVector3::msZero.x;
    velocity->y = v27;
    velocity->z = v28;
  }
}

// File Line: 1259
// RVA: 0x3CD9F0
void __fastcall UFG::ChaseCameraComponent::Snap(UFG::ChaseCameraComponent *this)
{
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rbx
  float x; // eax
  float z; // xmm1_4
  float y; // xmm0_4
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
  float v19; // eax
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4

  p_mLook = &this->mLook;
  this->mLookaroundAngle = this->mLookaroundAngleDesired;
  this->mForwardAngle = this->mForwardAngleDesired;
  *(_QWORD *)&this->mBlendPrevious = 0i64;
  x = this->mLook.p1.x;
  z = this->mLook.p1.z;
  this->mLook.p0.y = this->mLook.p1.y;
  this->mLook.p0.z = z;
  this->mLook.p0.x = x;
  y = this->mLook.v1.y;
  v6 = this->mLook.v1.z;
  this->mLook.v0.x = this->mLook.v1.x;
  this->mLook.v0.y = y;
  this->mLook.v0.z = v6;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
  v7 = this->mEye.p1.y;
  v8 = this->mEye.p1.z;
  this->mEye.p0.x = this->mEye.p1.x;
  this->mEye.p0.y = v7;
  this->mEye.p0.z = v8;
  v9 = this->mEye.v1.y;
  v10 = this->mEye.v1.z;
  this->mEye.v0.x = this->mEye.v1.x;
  this->mEye.v0.y = v9;
  this->mEye.v0.z = v10;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  v11 = this->mAimLook.p1.y;
  v12 = this->mAimLook.p1.z;
  this->mAimLook.p0.x = this->mAimLook.p1.x;
  this->mAimLook.p0.y = v11;
  this->mAimLook.p0.z = v12;
  v13 = this->mAimLook.v1.y;
  v14 = this->mAimLook.v1.z;
  this->mAimLook.v0.x = this->mAimLook.v1.x;
  this->mAimLook.v0.y = v13;
  this->mAimLook.v0.z = v14;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
  *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
  this->mAimLook.mParameter.z = 0.0;
  v15 = this->mAimEye.p1.y;
  v16 = this->mAimEye.p1.z;
  this->mAimEye.p0.x = this->mAimEye.p1.x;
  this->mAimEye.p0.y = v15;
  this->mAimEye.p0.z = v16;
  v17 = this->mAimEye.v1.y;
  v18 = this->mAimEye.v1.z;
  this->mAimEye.v0.x = this->mAimEye.v1.x;
  this->mAimEye.v0.y = v17;
  this->mAimEye.v0.z = v18;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
  *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
  this->mAimEye.mParameter.z = 0.0;
  this->mFov.p0 = this->mFov.p1;
  this->mFov.v0 = this->mFov.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  v19 = this->mUp.p1.x;
  v20 = this->mUp.p1.z;
  this->mUp.p0.y = this->mUp.p1.y;
  this->mUp.p0.z = v20;
  this->mUp.p0.x = v19;
  v21 = this->mUp.v1.y;
  v22 = this->mUp.v1.z;
  this->mUp.v0.x = this->mUp.v1.x;
  this->mUp.v0.y = v21;
  this->mUp.v0.z = v22;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mUp);
  *(_QWORD *)&this->mUp.mParameter.x = 0i64;
  this->mUp.mParameter.z = 0.0;
  *(_QWORD *)&this->mYawAngVelWindow.m_StartIndex = 0i64;
  this->mYawAngVelWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->mYawAngVelWindow.m_RunningSum, 0, 4u);
  this->mTargetPitch.p0 = this->mTargetPitch.p1;
  this->mTargetPitch.v0 = this->mTargetPitch.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mTargetPitch);
  this->mTargetPitch.mParameter = 0.0;
  *(_QWORD *)&this->mRecoilAngle = 0i64;
  v23 = UFG::qVector3::msZero.y;
  v24 = UFG::qVector3::msZero.z;
  this->mRecoilEye.p1.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.p1.y = v23;
  this->mRecoilEye.p1.z = v24;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  v25 = this->mRecoilEye.p1.y;
  v26 = this->mRecoilEye.p1.z;
  this->mRecoilEye.p0.x = this->mRecoilEye.p1.x;
  this->mRecoilEye.p0.y = v25;
  this->mRecoilEye.p0.z = v26;
  v27 = this->mRecoilEye.v1.y;
  v28 = this->mRecoilEye.v1.z;
  this->mRecoilEye.v0.x = this->mRecoilEye.v1.x;
  this->mRecoilEye.v0.y = v27;
  this->mRecoilEye.v0.z = v28;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  if ( this->mLockEye )
    v29 = *(float *)&FLOAT_1_0;
  else
    v29 = 0.0;
  this->mLockEyeParam = v29;
  if ( this->mLockLook )
    LODWORD(this->mLockLookParam) = (_DWORD)FLOAT_1_0;
  else
    this->mLockLookParam = 0.0;
}

// File Line: 1282
// RVA: 0x3CE090
void __fastcall UFG::ChaseCameraComponent::SnapCurrent(UFG::ChaseCameraComponent *this)
{
  float mForwardAngle; // eax
  UFG::HomerCubic<UFG::qVector3> *p_mLook; // rbx
  float x; // eax
  float z; // xmm1_4
  float y; // xmm0_4
  float v7; // xmm1_4
  float v8; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float p0; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4

  mForwardAngle = this->mForwardAngle;
  p_mLook = &this->mLook;
  *(_QWORD *)&this->mBlendPrevious = 0i64;
  this->mForwardAngleDesired = mForwardAngle;
  x = this->mLook.p0.x;
  z = this->mLook.p0.z;
  this->mLook.p1.y = this->mLook.p0.y;
  this->mLook.p1.z = z;
  this->mLook.p1.x = x;
  *(_QWORD *)&this->mLook.v0.x = 0i64;
  *(_QWORD *)&this->mLook.v0.z = 0i64;
  *(_QWORD *)&this->mLook.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&p_mLook->mParameter.x = 0i64;
  p_mLook->mParameter.z = 0.0;
  y = this->mEye.p0.y;
  v7 = this->mEye.p0.z;
  this->mEye.p1.x = this->mEye.p0.x;
  this->mEye.p1.y = y;
  this->mEye.p1.z = v7;
  *(_QWORD *)&this->mEye.v0.x = 0i64;
  *(_QWORD *)&this->mEye.v0.z = 0i64;
  *(_QWORD *)&this->mEye.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  v8 = this->mAimLook.p0.x;
  v9 = this->mAimLook.p0.z;
  this->mAimLook.p1.y = this->mAimLook.p0.y;
  this->mAimLook.p1.z = v9;
  this->mAimLook.p1.x = v8;
  *(_QWORD *)&this->mAimLook.v0.x = 0i64;
  *(_QWORD *)&this->mAimLook.v0.z = 0i64;
  *(_QWORD *)&this->mAimLook.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
  *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
  this->mAimLook.mParameter.z = 0.0;
  v10 = this->mAimEye.p0.y;
  v11 = this->mAimEye.p0.z;
  this->mAimEye.p1.x = this->mAimEye.p0.x;
  this->mAimEye.p1.y = v10;
  this->mAimEye.p1.z = v11;
  *(_QWORD *)&this->mAimEye.v0.x = 0i64;
  *(_QWORD *)&this->mAimEye.v0.z = 0i64;
  *(_QWORD *)&this->mAimEye.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
  *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
  this->mAimEye.mParameter.z = 0.0;
  p0 = this->mFov.p0;
  *(_QWORD *)&this->mFov.v0 = 0i64;
  this->mFov.p1 = p0;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  v13 = this->mUp.p0.y;
  v14 = this->mUp.p0.z;
  this->mUp.p1.x = this->mUp.p0.x;
  this->mUp.p1.y = v13;
  this->mUp.p1.z = v14;
  *(_QWORD *)&this->mUp.v0.x = 0i64;
  *(_QWORD *)&this->mUp.v0.z = 0i64;
  *(_QWORD *)&this->mUp.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mUp);
  *(_QWORD *)&this->mUp.mParameter.x = 0i64;
  this->mUp.mParameter.z = 0.0;
  *(_QWORD *)&this->mYawAngVelWindow.m_StartIndex = 0i64;
  this->mYawAngVelWindow.m_RunningSumTime = 0.0;
  UFG::qMemSet(&this->mYawAngVelWindow.m_RunningSum, 0, 4u);
  v15 = this->mTargetPitch.p0;
  *(_QWORD *)&this->mTargetPitch.v0 = 0i64;
  this->mTargetPitch.p1 = v15;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mTargetPitch);
  this->mTargetPitch.mParameter = 0.0;
  this->mRecoilAngle = this->mRecoilAngleDesired;
  v16 = this->mRecoilEye.p0.y;
  v17 = this->mRecoilEye.p0.z;
  this->mRecoilEye.p1.x = this->mRecoilEye.p0.x;
  this->mRecoilEye.p1.y = v16;
  this->mRecoilEye.p1.z = v17;
  *(_QWORD *)&this->mRecoilEye.v0.x = 0i64;
  *(_QWORD *)&this->mRecoilEye.v0.z = 0i64;
  *(_QWORD *)&this->mRecoilEye.v1.y = 0i64;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
}

// File Line: 1300
// RVA: 0x3CD470
void __fastcall UFG::ChaseCameraComponent::SetTarget(UFG::ChaseCameraComponent *this, UFG::SimObjectVehicle *target)
{
  UFG::VehicleSubjectComponent *ComponentOfTypeHK; // rax
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pSimComponent; // rcx
  __int64 v7; // rax
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1

  if ( !this->mTarget.m_pSimComponent || this->mTarget.m_pSimObject != target )
  {
    if ( !target )
    {
      ComponentOfTypeHK = 0i64;
      goto LABEL_13;
    }
    m_Flags = target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      goto LABEL_6;
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
LABEL_6:
        ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              target,
                                                              UFG::VehicleSubjectComponent::_TypeUID);
        goto LABEL_13;
      }
      ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                            target,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(target);
    }
LABEL_13:
    UFG::RebindingComponentHandle<UFG::VehicleSubjectComponent,0>::Set(&this->mTarget, ComponentOfTypeHK);
    m_pSimComponent = this->mTarget.m_pSimComponent;
    if ( m_pSimComponent )
    {
      v7 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
      v8 = *(UFG::qVector4 *)(v7 + 16);
      v9 = *(UFG::qVector4 *)(v7 + 32);
      v10 = *(UFG::qVector4 *)(v7 + 48);
      this->mTargetWorld.v0 = *(UFG::qVector4 *)v7;
      this->mTargetWorld.v1 = v8;
      this->mTargetWorld.v2 = v9;
      this->mTargetWorld.v3 = v10;
      this->pSimObjectPassThru1 = target;
    }
  }
}

// File Line: 1317
// RVA: 0x3CF730
void __fastcall UFG::ChaseCameraComponent::TransitionTarget(UFG::ChaseCameraComponent *this, UFG::SimObject *target)
{
  char v4[16]; // [rsp+20h] [rbp-48h] BYREF
  char v5[16]; // [rsp+30h] [rbp-38h] BYREF
  char v6[16]; // [rsp+40h] [rbp-28h] BYREF
  char v7[24]; // [rsp+50h] [rbp-18h] BYREF
  int v8; // [rsp+70h] [rbp+8h] BYREF
  int v9; // [rsp+80h] [rbp+18h] BYREF

  ((void (__fastcall *)(UFG::ChaseCameraComponent *, int *, int *))this->vfptr[23].__vecDelDtor)(this, &v9, &v8);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, char *, char *))this->vfptr[25].__vecDelDtor)(this, v5, v4);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, char *, char *))this->vfptr[26].__vecDelDtor)(this, v7, v6);
  this->vfptr[16].__vecDelDtor(this, (unsigned int)target);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[15].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[24].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, char *, char *))this->vfptr[27].__vecDelDtor)(this, v5, v4);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *, char *, char *))this->vfptr[28].__vecDelDtor)(this, v7, v6);
}

// File Line: 1357
// RVA: 0x3C8730
void __fastcall UFG::ChaseCameraComponent::Reset(UFG::ChaseCameraComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  __int64 v3; // rax
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1
  float z; // xmm2_4
  float x; // xmm0_4
  UFG::SimComponent *v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm0_4
  float *v12; // rax
  float v13; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax

  *(_QWORD *)&this->mAimParam = 0i64;
  *(_QWORD *)&this->mTransitionParamEye = 0i64;
  m_pSimComponent = this->mTarget.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v3 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
    v4 = *(UFG::qVector4 *)(v3 + 16);
    v5 = *(UFG::qVector4 *)(v3 + 32);
    v6 = *(UFG::qVector4 *)(v3 + 48);
    this->mTargetWorld.v0 = *(UFG::qVector4 *)v3;
    this->mTargetWorld.v1 = v4;
    this->mTargetWorld.v2 = v5;
    this->mTargetWorld.v3 = v6;
  }
  this->mAllowCanOccludeCamera = 1;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->mCollisionLookOffset.y = UFG::qVector3::msZero.y;
  this->mCollisionLookOffset.z = z;
  this->mCollisionLookOffset.x = x;
  UFG::BaseCameraComponent::Reset(this);
  this->pChaseParameters = 0i64;
  this->mUpdateEyeOffset = 1;
  *(_QWORD *)&this->mBlendPrevious = 0i64;
  this->mLookingBack = 0;
  this->mLookbackCorrectionAngle = 0.0;
  if ( this->mLockEye )
  {
    this->mLockEyeParam = 1.0;
    this->mLockEye = 0;
    this->mUpdateEyeOffset = 1;
  }
  if ( this->mLockLook )
  {
    this->mLockLookParam = 1.0;
    this->mLockLook = 0;
  }
  v9 = this->mTarget.m_pSimComponent;
  v10 = *(float *)&FLOAT_1_0;
  v11 = 0.0;
  if ( v9 )
  {
    v12 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v9->vfptr[16].__vecDelDtor)(v9);
    v10 = *v12;
    v11 = v12[1];
  }
  v13 = atan2f(v11, v10);
  vfptr = this->vfptr;
  this->mLookaroundAngleDesired = 0.0;
  this->mForwardAngleDesired = v13;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))vfptr[31].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[15].__vecDelDtor)(this);
}

// File Line: 1387
// RVA: 0x3C4990
void __fastcall UFG::ChaseCameraComponent::GotoAngleSnap(
        UFG::ChaseCameraComponent *this,
        float radians,
        bool worldSpace)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  __int64 v7; // rax
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  UFG::qVector4 v10; // xmm1
  float z; // xmm2_4
  float x; // xmm0_4
  UFG::SimComponent *v13; // rcx
  float v14; // xmm1_4
  float v15; // xmm0_4
  float *v16; // rax
  float v17; // xmm0_4
  float v18; // xmm0_4
  float mLookaroundAngleDesired; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax

  *(_QWORD *)&this->mAimParam = 0i64;
  *(_QWORD *)&this->mTransitionParamEye = 0i64;
  m_pSimComponent = this->mTarget.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v7 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[18].__vecDelDtor)(m_pSimComponent);
    v8 = *(UFG::qVector4 *)(v7 + 16);
    v9 = *(UFG::qVector4 *)(v7 + 32);
    v10 = *(UFG::qVector4 *)(v7 + 48);
    this->mTargetWorld.v0 = *(UFG::qVector4 *)v7;
    this->mTargetWorld.v1 = v8;
    this->mTargetWorld.v2 = v9;
    this->mTargetWorld.v3 = v10;
  }
  this->mAllowCanOccludeCamera = 1;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->mCollisionLookOffset.y = UFG::qVector3::msZero.y;
  this->mCollisionLookOffset.z = z;
  this->mCollisionLookOffset.x = x;
  UFG::BaseCameraComponent::Reset(this);
  this->pChaseParameters = 0i64;
  this->mUpdateEyeOffset = 1;
  *(_QWORD *)&this->mBlendPrevious = 0i64;
  this->mLookingBack = 0;
  this->mLookbackCorrectionAngle = 0.0;
  if ( this->mLockEye )
  {
    this->mLockEyeParam = 1.0;
    this->mLockEye = 0;
    this->mUpdateEyeOffset = 1;
  }
  if ( this->mLockLook )
  {
    this->mLockLookParam = 1.0;
    this->mLockLook = 0;
  }
  v13 = this->mTarget.m_pSimComponent;
  v14 = *(float *)&FLOAT_1_0;
  v15 = 0.0;
  if ( v13 )
  {
    v16 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v13->vfptr[16].__vecDelDtor)(v13);
    v14 = *v16;
    v15 = v16[1];
  }
  v17 = atan2f(v15, v14);
  this->mForwardAngleDesired = v17;
  if ( worldSpace )
    v18 = (float)(v17 + 3.1415927) - radians;
  else
    LODWORD(v18) = LODWORD(radians) ^ _xmm[0];
  this->mLookaroundAngleDesired = v18;
  if ( v18 > 3.1415927 )
  {
    do
      v18 = v18 + -6.2831855;
    while ( v18 > 3.1415927 );
    this->mLookaroundAngleDesired = v18;
  }
  mLookaroundAngleDesired = this->mLookaroundAngleDesired;
  if ( mLookaroundAngleDesired < -3.1415927 )
  {
    do
      mLookaroundAngleDesired = mLookaroundAngleDesired + 6.2831855;
    while ( mLookaroundAngleDesired < -3.1415927 );
    this->mLookaroundAngleDesired = mLookaroundAngleDesired;
  }
  vfptr = this->vfptr;
  this->mLookaroundJoyInput = 0.0;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))vfptr[31].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[15].__vecDelDtor)(this);
}

// File Line: 1426
// RVA: 0x3DD7F0
void __fastcall UFG::ChaseCameraComponent::UpdateTargeting(UFG::ChaseCameraComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  __int64 v3; // rax
  float v4; // xmm10_4
  float v5; // xmm12_4
  float *v6; // rax
  float x; // xmm10_4
  __int128 y_low; // xmm11
  float z; // xmm12_4
  UFG::TargetingSystemPedPlayerComponent *mTargetingSystem; // rcx
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::AimingPlayerComponent *ComponentOfTypeHK; // rbx
  UFG::TargetingSystemPedPlayerComponent *v14; // rcx
  UFG::qVector3 *FreeAimFocusPosition; // rax
  float y; // xmm0_4
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
  float v51; // xmm1_4
  float v52; // xmm13_4
  float v53; // xmm2_4
  float v54; // xmm8_4
  float v55; // xmm1_4
  float v56; // xmm4_4
  __m128 v57; // xmm2
  float v58; // xmm5_4
  float v59; // xmm0_4
  float v60; // xmm3_4
  float v61; // xmm13_4
  __m128 v62; // xmm9
  float v63; // xmm14_4
  float *v64; // rax
  __m128 v65; // xmm2
  float v66; // xmm7_4
  float v67; // xmm8_4
  float v68; // xmm6_4
  float v69; // xmm10_4
  float v70; // xmm12_4
  float v71; // xmm3_4
  __m128 v72; // xmm2
  float v73; // xmm8_4
  float v74; // xmm7_4
  float v75; // xmm8_4
  float v76; // xmm6_4
  float *v77; // rax
  float v78; // xmm3_4
  float v79; // xmm2_4
  float v80; // xmm7_4
  UFG::SimComponent *v81; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float *v83; // rax
  float v84; // xmm3_4
  float v85; // xmm2_4
  float v86; // xmm9_4
  float v87; // [rsp+20h] [rbp-E8h]
  float v88; // [rsp+24h] [rbp-E4h]
  UFG::qVector2 v2; // [rsp+28h] [rbp-E0h] BYREF
  UFG::qVector2 v1; // [rsp+30h] [rbp-D8h] BYREF
  UFG::qVector3 result; // [rsp+38h] [rbp-D0h] BYREF
  float v92; // [rsp+110h] [rbp+8h]
  float v93; // [rsp+110h] [rbp+8h]
  float v94; // [rsp+118h] [rbp+10h]
  float v95; // [rsp+120h] [rbp+18h]
  float v96; // [rsp+128h] [rbp+20h]

  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  m_pSimComponent = this->mTarget.m_pSimComponent;
  v3 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[16].__vecDelDtor)(m_pSimComponent);
  v4 = *(float *)v3;
  y_low = *(unsigned int *)(v3 + 4);
  v5 = *(float *)(v3 + 8);
  v6 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[17].__vecDelDtor)(m_pSimComponent);
  x = (float)(v4 * 5.0) + *v6;
  *(float *)&y_low = (float)(*(float *)&y_low * 5.0) + v6[1];
  z = (float)(v5 * 5.0) + v6[2];
  this->mFocusPos.x = x;
  LODWORD(this->mFocusPos.y) = y_low;
  this->mFocusPos.z = z;
  mTargetingSystem = this->mTargetingSystem;
  if ( mTargetingSystem && (m_pSimObject = (UFG::SimObjectCharacter *)mTargetingSystem->m_pSimObject) != 0i64 )
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
    v14 = this->mTargetingSystem;
    if ( (unsigned int)(v14->m_eFocusMode - 3) <= 1 || v14->m_eFocusMode == eFOCUS_MODE_LOCKED_SOFT )
    {
      FreeAimFocusPosition = UFG::AimingPlayerComponent::GetFreeAimFocusPosition(ComponentOfTypeHK, &result);
      x = FreeAimFocusPosition->x;
      y_low = LODWORD(FreeAimFocusPosition->y);
      z = FreeAimFocusPosition->z;
    }
    else if ( (unsigned int)(v14->m_eFocusMode - 1) <= 1 )
    {
      x = ComponentOfTypeHK->m_vAimPosition.x;
      y_low = LODWORD(ComponentOfTypeHK->m_vAimPosition.y);
      z = ComponentOfTypeHK->m_vAimPosition.z;
    }
    y = ComponentOfTypeHK->m_vAimPosition.y;
    v17 = ComponentOfTypeHK->m_vAimPosition.z;
    this->mFocusPos.x = ComponentOfTypeHK->m_vAimPosition.x;
    this->mFocusPos.y = y;
    this->mFocusPos.z = v17;
  }
  v18 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v19 = *(float *)&FLOAT_1_0;
  v23 = (__m128)y_low;
  v20 = *v18;
  v21 = z - v18[2];
  v94 = v18[1];
  v22 = 0.0;
  v95 = v18[2];
  v23.m128_f32[0] = (float)((float)((float)(*(float *)&y_low - v94) * (float)(*(float *)&y_low - v94))
                          + (float)((float)(x - v20) * (float)(x - v20)))
                  + (float)(v21 * v21);
  if ( v23.m128_f32[0] != 0.0 )
    v22 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
  v24 = v21 * v22;
  v25 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v26 = LODWORD(this->mCamera.mTransformation.v2.x) ^ _xmm[0];
  v27 = *(float *)v25;
  v2.y = *(float *)(v25 + 4);
  v28 = this->mCamera.mTransformation.v2.y;
  v2.x = v27;
  LODWORD(v1.y) = LODWORD(v28) ^ _xmm[0];
  LODWORD(v1.x) = v26;
  v29 = UFG::qAngleBetween(&v1, &v2);
  v87 = sinf(v29);
  v30 = cosf(v29);
  v31 = (float *)this->mTarget.m_pSimComponent;
  v32 = (float)(v24 - -1.0) * 0.5;
  v88 = v30 * v30;
  v96 = v31[164];
  v92 = 0.0;
  if ( v32 > 0.0 )
  {
    v92 = v32;
    if ( v32 >= 1.0 )
      v92 = *(float *)&FLOAT_1_0;
  }
  v33 = v31[165];
  v34 = (float *)(*(__int64 (**)(void))(*(_QWORD *)v31 + 152i64))();
  v35 = (float)((float)((float)(v94 * v34[4]) + (float)(v20 * *v34)) + (float)(v95 * v34[8])) + v34[12];
  v36 = (float)((float)((float)(v20 * v34[1]) + (float)(v94 * v34[5])) + (float)(v95 * v34[9])) + v34[13];
  v37 = (float)((float)((float)(v20 * v34[2]) + (float)(v94 * v34[6])) + (float)(v95 * v34[10])) + v34[14];
  v38 = (float)((float)((float)(v20 * v34[3]) + (float)(v94 * v34[7])) + (float)(v95 * v34[11])) + v34[15];
  v39 = (float)((float)((float)((float)((float)((float)(v96 * 0.40000001) - v96) * v92) + v96) * v87) + v33) + v35;
  v40 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v41 = (float)((float)((float)(v36 * v40[4]) + (float)(v39 * *v40)) + (float)(v37 * v40[8])) + (float)(v38 * v40[12]);
  v42 = x - v41;
  v43 = (float)((float)((float)(v36 * v40[5]) + (float)(v39 * v40[1])) + (float)(v37 * v40[9])) + (float)(v38 * v40[13]);
  v44 = (float)((float)((float)(v36 * v40[6]) + (float)(v39 * v40[2])) + (float)(v37 * v40[10]))
      + (float)(v38 * v40[14]);
  v45 = (__m128)y_low;
  v45.m128_f32[0] = *(float *)&y_low - v43;
  v46 = v45;
  v46.m128_f32[0] = (float)(v45.m128_f32[0] * v45.m128_f32[0]) + (float)(v42 * v42);
  if ( v46.m128_f32[0] == 0.0 )
    v47 = 0.0;
  else
    v47 = 1.0 / _mm_sqrt_ps(v46).m128_f32[0];
  v48 = (float *)this->mTarget.m_pSimComponent;
  v49 = v42 * v47;
  v45.m128_f32[0] = v45.m128_f32[0] * v47;
  v50 = v47 * 0.0;
  if ( v32 <= 0.0 )
  {
    v32 = 0.0;
  }
  else if ( v32 >= 1.0 )
  {
    goto LABEL_32;
  }
  v19 = v32;
LABEL_32:
  v93 = (float)((float)((float)(v48[161] - v48[160]) * v19) + v48[160]) + this->mTargetOffset.z;
  v51 = this->mTargetOffset.y;
  v52 = (float)(v49 - (float)(v50 * 0.0)) * v51;
  v53 = (float)((float)(v45.m128_f32[0] * 0.0) - (float)(v49 * 0.0)) * v51;
  v54 = (float)((float)(v50 * 0.0) - v45.m128_f32[0]) * v51;
  v55 = this->mTargetOffset.x;
  v45.m128_f32[0] = (float)((float)((float)(v45.m128_f32[0] * v55) + v43) + v52) + (float)(v93 * 0.0);
  v62 = v45;
  v56 = (float)((float)((float)(v50 * v55) + v44) + v53) + v93;
  v62.m128_f32[0] = v45.m128_f32[0] - *(float *)&y_low;
  v57 = v62;
  v58 = (float)((float)((float)(v49 * v55) + v41) + v54) + (float)(v93 * 0.0);
  v59 = (float)((float)(v48[205] - v48[202]) * 0.5) + v48[162];
  v57.m128_f32[0] = (float)((float)(v62.m128_f32[0] * v62.m128_f32[0]) + (float)((float)(v58 - x) * (float)(v58 - x)))
                  + (float)((float)(v56 - z) * (float)(v56 - z));
  v60 = (float)((float)((float)((float)((float)((float)(v48[204] - v48[201]) * 0.5) + v48[163]) - v59) * v88) + v59)
      / _mm_sqrt_ps(v57).m128_f32[0];
  v61 = (float)((float)(v58 - x) * v60) + v58;
  v62.m128_f32[0] = (float)((float)(v45.m128_f32[0] - *(float *)&y_low) * v60) + v45.m128_f32[0];
  v63 = (float)((float)(v56 - z) * v60) + v56;
  v64 = (float *)(*(__int64 (**)(void))(*(_QWORD *)v48 + 136i64))();
  v65 = v62;
  v66 = UFG::qVector3::msAxisX.x;
  v67 = UFG::qVector3::msAxisX.y;
  v68 = UFG::qVector3::msAxisX.z;
  v69 = x - v61;
  *(float *)&y_low = *(float *)&y_low - v62.m128_f32[0];
  v65.m128_f32[0] = (float)((float)((float)(v62.m128_f32[0] - v64[1]) * (float)(v62.m128_f32[0] - v64[1]))
                          + (float)((float)(v61 - *v64) * (float)(v61 - *v64)))
                  + (float)((float)(v63 - v64[2]) * (float)(v63 - v64[2]));
  v70 = z - v63;
  LODWORD(v71) = _mm_sqrt_ps(v65).m128_u32[0];
  v72 = (__m128)y_low;
  v72.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v69 * v69)) + (float)(v70 * v70);
  if ( v72.m128_f32[0] > 0.000099999997 && v71 > 0.000099999997 )
  {
    v73 = v71 / _mm_sqrt_ps(v72).m128_f32[0];
    v68 = v73 * v70;
    v66 = v73 * v69;
    v67 = v73 * *(float *)&y_low;
  }
  v74 = v66 + v61;
  v75 = v67 + v62.m128_f32[0];
  v76 = v68 + v63;
  v77 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[19].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v78 = (float)(v75 * v77[4]) + (float)(v74 * *v77);
  v79 = (float)((float)((float)(v74 * v77[1]) + (float)(v75 * v77[5])) + (float)(v76 * v77[9])) + v77[13];
  v80 = (float)((float)((float)(v74 * v77[2]) + (float)(v75 * v77[6])) + (float)(v76 * v77[10])) + v77[14];
  this->mAimLook.p1.x = (float)(v78 + (float)(v76 * v77[8])) + v77[12];
  this->mAimLook.p1.y = v79;
  this->mAimLook.p1.z = v80;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
  v81 = this->mTarget.m_pSimComponent;
  *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
  vfptr = v81->vfptr;
  this->mAimLook.mParameter.z = 0.0;
  v83 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))vfptr[19].__vecDelDtor)(v81);
  v84 = (float)((float)((float)(v62.m128_f32[0] * v83[4]) + (float)(v61 * *v83)) + (float)(v63 * v83[8])) + v83[12];
  v85 = (float)((float)((float)(v62.m128_f32[0] * v83[5]) + (float)(v61 * v83[1])) + (float)(v63 * v83[9])) + v83[13];
  v86 = (float)((float)((float)(v62.m128_f32[0] * v83[6]) + (float)(v61 * v83[2])) + (float)(v63 * v83[10])) + v83[14];
  this->mAimEye.p1.y = v85;
  this->mAimEye.p1.x = v84;
  this->mAimEye.p1.z = v86;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
  *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
  this->mAimEye.mParameter.z = 0.0;
}ORD *)&this->mAimEye.mParameter.x = 0i64;
  this->mAimEye.mParameter.z = 0.0;
}

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
void __fastcall UFG::ChaseCameraComponent::AutoLockUnlock(UFG::ChaseCameraComponent *this, float dt)
{
  int v3; // xmm7_4
  double v4; // xmm0_8
  float v5; // xmm15_4
  float *v6; // rax
  __m128 x_low; // xmm0
  float v8; // xmm9_4
  int v9; // xmm10_4
  float *v10; // rax
  float v11; // xmm14_4
  __m128 v12; // xmm13
  __m128 v13; // xmm6
  float v14; // xmm11_4
  float v15; // xmm0_4
  float z; // xmm3_4
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
  __m128 y_low; // xmm5
  float v40; // xmm3_4
  float v41; // xmm7_4
  __m128 v42; // xmm2
  __m128 v43; // xmm2
  float v44; // xmm7_4
  float ForwardSpeed; // xmm6_4
  float v46; // xmm0_4
  bool v47; // di
  UFG::SimComponent *m_pSimComponent; // rcx
  bool v49; // si
  float v50; // xmm6_4
  float v51; // xmm10_4
  unsigned int v52; // eax
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  bool v55; // al
  float y; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // [rsp+100h] [rbp+18h]
  float v61; // [rsp+108h] [rbp+20h]

  v3 = LODWORD(this->mEyeOffset.x) ^ _xmm[0];
  v4 = ((double (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[28].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v5 = *(float *)&v4;
  v6 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
  x_low = (__m128)LODWORD(this->mEyeCurr.x);
  x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - *v6) * (float)(x_low.m128_f32[0] - *v6))
                            + (float)((float)(this->mEyeCurr.y - v6[1]) * (float)(this->mEyeCurr.y - v6[1])))
                    + (float)((float)(this->mEyeCurr.z - v6[2]) * (float)(this->mEyeCurr.z - v6[2]));
  LODWORD(v8) = _mm_sqrt_ps(x_low).m128_u32[0];
  if ( (v5 > 3.0 || v8 > *(float *)&v3) && this->mLockLook )
  {
    this->mLockLookParam = 1.0;
    this->mLockLook = 0;
  }
  v9 = _xmm;
  if ( this->mLockEye )
  {
    v10 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
    v61 = *v10;
    v60 = v10[1];
    v12 = (__m128)LODWORD(this->mLockEyePos.x);
    v11 = this->mLockEyePos.y - v60;
    v12.m128_f32[0] = v12.m128_f32[0] - *v10;
    v13 = v12;
    v13.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11);
    if ( v13.m128_f32[0] > 0.000099999997 )
    {
      v14 = *(float *)&v3 * 0.64999998;
      if ( _mm_sqrt_ps(v13).m128_f32[0] < (float)(*(float *)&v3 * 0.64999998) )
      {
        v15 = *(float *)(((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent)
                       + 8)
            + this->mEyeOffset.z;
        z = this->mLockEyePos.z;
        if ( z <= v15 )
          z = v15;
        if ( v13.m128_f32[0] == 0.0 )
          v17 = 0.0;
        else
          v17 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
        v18 = v17 * 0.0;
        v19 = v17 * v11;
        v20 = v17 * v12.m128_f32[0];
        this->mLockEyePos.x = v61 + (float)(v20 * v14);
        this->mLockEyePos.y = v60 + (float)(v19 * v14);
        this->mLockEyePos.z = z;
        v21 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[15].__vecDelDtor)(this->mTarget.m_pSimComponent);
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
            v29 = this->mLockEyePos.y - v24;
            v30 = this->mLockEyePos.z;
            this->mLockEyePos.x = this->mLockEyePos.x - v25;
            this->mLockEyePos.y = v29;
            this->mLockEyePos.z = v30 - v28;
          }
          else
          {
            v26 = v24 + this->mLockEyePos.y;
            v27 = (float)((float)(dt * 0.0) * 6.0) + this->mLockEyePos.z;
            this->mLockEyePos.x = v25 + this->mLockEyePos.x;
            this->mLockEyePos.y = v26;
            this->mLockEyePos.z = v27;
          }
        }
      }
    }
  }
  if ( UFG::VehicleSubjectComponent::GetForwardSpeed((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent) >= this->mReverseSpeed
    || this->mAimOrFocus )
  {
    ForwardSpeed = UFG::VehicleSubjectComponent::GetForwardSpeed((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent);
    v47 = 0;
    if ( UFG::VehicleSubjectComponent::IsDoingBurnout((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent) )
    {
      v46 = this->mLockEye
          ? UFG::ChaseCameraComponent::mBurnoutSpeedThresholdOut
          : UFG::ChaseCameraComponent::mBurnoutSpeedThresholdIn;
      if ( COERCE_FLOAT(LODWORD(ForwardSpeed) & v9) < v46 )
        v47 = 1;
    }
    m_pSimComponent = this->mTarget.m_pSimComponent;
    v49 = (float)((float)(COERCE_FLOAT(m_pSimComponent[9].m_TypeUID & v9) * 180.0) * 0.31830987) > 70.0
       && UFG::VehicleSubjectComponent::IsInReverse((UFG::VehicleSubjectComponent *)m_pSimComponent);
    v50 = *(float *)&v3 * 1.3;
    if ( v47 )
      v51 = *(float *)&v3 * 1.3;
    else
      v51 = *(float *)&v3;
    v52 = _S16_0;
    if ( (_S16_0 & 1) == 0 )
    {
      _S16_0 |= 1u;
      HASH_ActionHijack.mUID = UFG::qStringHashUpper32("ActionHijack", -1);
      v52 = _S16_0;
    }
    if ( (v52 & 2) == 0 )
    {
      _S16_0 = v52 | 2;
      mostUsedIndex_ActionHijack = GetMostUsedIndex(HASH_ActionHijack.mUID);
    }
    v55 = 0;
    if ( LocalPlayer )
    {
      m_Flags = LocalPlayer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = LocalPlayer->m_Components.p[7].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
        else
          m_pComponent = (m_Flags & 0x1000) != 0
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
             &HASH_ActionHijack,
             mostUsedIndex_ActionHijack,
             0) )
      {
        v55 = 1;
      }
    }
    if ( this->mAimOrFocus || v55 )
    {
      if ( this->mLockEye )
      {
        this->mLockEyeParam = 1.0;
        this->mLockEye = 0;
        this->mUpdateEyeOffset = 1;
      }
      if ( this->mLockLook )
      {
        this->mLockLookParam = 1.0;
        this->mLockLook = 0;
      }
      if ( v55 )
        *(_QWORD *)&this->mLockEyeParam = 0i64;
    }
    else if ( v5 < 2.0 && v8 < (float)(v50 + 0.1)
           || v5 < 4.0 && v8 < *(float *)&v3
           || v5 < 5.0 && v8 < v50 && v47
           || v5 < 15.0 && v8 < v50 && v49 )
    {
      if ( this->mLookaroundAngle == 0.0 && !this->mLockEye )
      {
        y = this->mEyeVelocity.y;
        v57 = this->mEyeVelocity.z;
        this->mLockEyeVel.x = this->mEyeVelocity.x;
        this->mLockEyeVel.y = y;
        this->mLockEyeVel.z = v57;
        v58 = this->mEyeCurr.y;
        v59 = this->mEyeCurr.z;
        this->mLockEyePos.x = this->mEyeCurr.x;
        this->mLockEyePos.y = v58;
        this->mLockEyePos.z = v59;
        this->mLockEyeParam = 0.0;
        this->mLockEye = 1;
        this->mUpdateEyeOffset = 0;
      }
    }
    else if ( v8 > v51 && this->mLockEye )
    {
      this->mLockEyeParam = 1.0;
      this->mLockEye = 0;
      this->mUpdateEyeOffset = 1;
    }
  }
  else
  {
    if ( this->mLookaroundAngle == 0.0 && !this->mLockEye )
    {
      v31 = this->mEyeVelocity.y;
      v32 = this->mEyeVelocity.z;
      this->mLockEyeVel.x = this->mEyeVelocity.x;
      this->mLockEyeVel.y = v31;
      this->mLockEyeVel.z = v32;
      v33 = this->mEyeCurr.y;
      v34 = this->mEyeCurr.z;
      this->mLockEyePos.x = this->mEyeCurr.x;
      this->mLockEyePos.y = v33;
      this->mLockEyePos.z = v34;
      this->mLockEyeParam = 0.0;
      this->mLockEye = 1;
      this->mUpdateEyeOffset = 0;
    }
    v35 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
    v36 = v35[1];
    v37 = v35[2] + this->mEyeOffset.z;
    v38 = this->mLockEyePos.x - *v35;
    y_low = (__m128)LODWORD(this->mLockEyePos.y);
    y_low.m128_f32[0] = y_low.m128_f32[0] - v36;
    v40 = this->mLockEyePos.z - v37;
    v41 = *(float *)&v3 * 1.3;
    v42 = y_low;
    v42.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v38 * v38)) + (float)(v40 * v40);
    if ( _mm_sqrt_ps(v42).m128_f32[0] > v41 )
    {
      v43 = y_low;
      v43.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v38 * v38))
                      + (float)(v40 * v40);
      v44 = v41 / _mm_sqrt_ps(v43).m128_f32[0];
      this->mLockEyePos.x = *v35 + (float)(v38 * v44);
      this->mLockEyePos.y = v36 + (float)(y_low.m128_f32[0] * v44);
      this->mLockEyePos.z = (float)(v40 * v44) + v37;
    }
  }
}

// File Line: 1626
// RVA: 0x3C4E00
void __fastcall UFG::ChaseCameraComponent::GunRecoil(
        UFG::ChaseCameraComponent *this,
        float scaleKickup,
        float scaleKickback,
        float scaleSpeed)
{
  UFG::SimObjectCVBase *v7; // rcx
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
  float y; // xmm1_4
  float z; // xmm2_4
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm8_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm9_4
  float v27; // xmm1_4
  float v28; // xmm0_4

  if ( this->mTarget.m_pSimComponent
    && (v7 = *(UFG::SimObjectCVBase **)&this->mTarget.m_pSimComponent[13].m_Flags) != 0i64 )
  {
    m_Flags = v7->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v7);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v7,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v7,
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
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v20 = v13 * scaleKickup;
  this->mRecoilEye.p1.x = UFG::qVector3::msZero.x;
  this->mRecoilEye.p1.y = y;
  this->mRecoilEye.p1.z = z;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  this->mRecoilAngle = v20;
  this->mRecoilAngleDesired = (float)(v15 * scaleKickup) + v20;
  LODWORD(v21) = COERCE_UNSIGNED_INT((float)(v16 * 0.001) * scaleKickback) ^ _xmm[0];
  v22 = v21 * this->mCamera.mTransformation.v2.z;
  v23 = v21 * this->mCamera.mTransformation.v2.x;
  v24 = v21 * this->mCamera.mTransformation.v2.y;
  this->mRecoilEye.p0.z = v22;
  this->mRecoilEye.p0.x = v23;
  this->mRecoilEye.p0.y = v24;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
  LODWORD(v25) = COERCE_UNSIGNED_INT(v17 * scaleSpeed) ^ _xmm[0];
  v26 = v25 * this->mCamera.mTransformation.v2.z;
  v27 = v25 * this->mCamera.mTransformation.v2.x;
  v28 = v25 * this->mCamera.mTransformation.v2.y;
  this->mRecoilEye.v0.z = v26;
  this->mRecoilEye.v0.x = v27;
  this->mRecoilEye.v0.y = v28;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mRecoilEye);
  *(_QWORD *)&this->mRecoilEye.mParameter.x = 0i64;
  this->mRecoilEye.mParameter.z = 0.0;
}

// File Line: 1662
// RVA: 0x3C8FB0
void __fastcall UFG::ChaseCameraComponent::RestrictOrbitHeight(UFG::ChaseCameraComponent *this, UFG::qVector3 *eye)
{
  float *p_z; // rbx
  __int64 v5; // rbp
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
  float z; // xmm0_4
  float v18; // xmm0_4
  UFG::qVector3 verts; // [rsp+20h] [rbp-98h] BYREF
  float v20; // [rsp+34h] [rbp-84h]
  float v21; // [rsp+40h] [rbp-78h]
  float v22; // [rsp+4Ch] [rbp-6Ch]
  float v23; // [rsp+58h] [rbp-60h]
  float v24; // [rsp+64h] [rbp-54h]
  float v25; // [rsp+70h] [rbp-48h]
  float v26; // [rsp+7Ch] [rbp-3Ch]

  UFG::CameraSubject::GetBoxVerts((UFG::CameraSubject *)this->mTarget.m_pSimComponent, &verts, 0.0);
  p_z = &verts.z;
  v5 = 8i64;
  do
  {
    v6 = *(p_z - 2);
    v7 = *(p_z - 1);
    v8 = *p_z;
    v9 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTarget.m_pSimComponent);
    p_z += 3;
    v10 = v7 * v9[4];
    v11 = v7 * v9[5];
    v12 = v7 * v9[6];
    v13 = (float)(v10 + (float)(v6 * *v9)) + (float)(v8 * v9[8]);
    v14 = v6 * v9[1];
    v15 = v6 * v9[2];
    *(p_z - 5) = v13 + v9[12];
    v16 = (float)((float)(v12 + v15) + (float)(v8 * v9[10])) + v9[14];
    *(p_z - 4) = (float)((float)(v11 + v14) + (float)(v8 * v9[9])) + v9[13];
    *(p_z - 3) = v16;
    --v5;
  }
  while ( v5 );
  z = FLOAT_N10000_0;
  if ( verts.z > -10000.0 )
    z = verts.z;
  if ( v20 > z )
    z = v20;
  if ( v21 > z )
    z = v21;
  if ( v22 > z )
    z = v22;
  if ( v23 > z )
    z = v23;
  if ( v24 > z )
    z = v24;
  if ( v25 > z )
    z = v25;
  if ( v26 > z )
    z = v26;
  v18 = z + this->mOrbitHeightMinOffset;
  if ( v18 > eye->z )
    eye->z = v18;
}

// File Line: 1710
// RVA: 0x3C6AF0
void __fastcall UFG::ChaseCameraComponent::LockEye(UFG::ChaseCameraComponent *this, bool lock)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  if ( (this->mLookaroundAngle == 0.0 || !lock) && this->mLockEye != lock )
  {
    if ( lock )
    {
      y = this->mEyeVelocity.y;
      z = this->mEyeVelocity.z;
      this->mLockEyeVel.x = this->mEyeVelocity.x;
      this->mLockEyeVel.y = y;
      this->mLockEyeVel.z = z;
      v4 = this->mEyeCurr.y;
      v5 = this->mEyeCurr.z;
      this->mLockEyePos.x = this->mEyeCurr.x;
      this->mLockEyePos.y = v4;
      this->mLockEyePos.z = v5;
      this->mUpdateEyeOffset = !lock;
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
void __fastcall UFG::ChaseCameraComponent::Update(UFG::ChaseCameraComponent *this, float dt)
{
  char v4; // bl
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool v7; // zf
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  double v9; // xmm0_8
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float mTransitionParamOrient; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float mBlendSeconds; // xmm2_4
  UFG::SimObjectCVBase *v23; // rcx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::TargetingSystemPedPlayerComponent *mTargetingSystem; // rcx
  bool v27; // al
  float v28; // xmm1_4
  int *v29; // rax
  UFG::SimComponent *m_pSimComponent; // rcx
  float v31; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v32; // rax
  __int64 v33; // rax
  float v34; // xmm6_4
  __m128 v35; // xmm8
  float v36; // xmm7_4
  float *v37; // rax
  float v38; // xmm9_4
  float v39; // xmm11_4
  float v40; // xmm13_4
  float v41; // xmm12_4
  UFG::TargetingSystemPedPlayerComponent *v42; // rcx
  float mAimFreeDuration; // xmm7_4
  float v44; // xmm8_4
  bool v45; // cl
  UFG::ChaseCameraParameters *pChaseParameters; // rax
  double v47; // xmm1_8
  float v48; // xmm6_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  UFG::SimObjectCVBase *v53; // rcx
  __int16 v54; // dx
  UFG::TargetingSystemPedPlayerComponent *ComponentOfType; // rax
  UFG::SimComponent *m_pPointer; // rax
  bool v57; // cl
  float mRecoilAngleDesired; // xmm1_4
  float v59; // xmm2_4
  int v60; // xmm7_4
  __int64 v61; // rdx
  float v62; // xmm4_4
  float v63; // xmm2_4
  float v64; // xmm3_4
  float v65; // xmm0_4
  float *v66; // rax
  float mForwardAngle; // xmm6_4
  float v68; // xmm9_4
  float v69; // xmm11_4
  float v70; // xmm13_4
  float v71; // xmm15_4
  UFG::qVector3 *Value; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qVector3 *v75; // rax
  float v76; // xmm2_4
  float v77; // xmm0_4
  float v78; // xmm1_4
  float x; // xmm1_4
  float v80; // xmm8_4
  float w; // xmm6_4
  float v82; // xmm0_4
  float v83; // xmm0_4
  __m128 v84; // xmm1
  float v85; // xmm2_4
  float v86; // xmm4_4
  __m128 v87; // xmm5
  float v88; // xmm6_4
  __m128 v89; // xmm3
  float v90; // xmm8_4
  float v91; // xmm11_4
  float v92; // xmm13_4
  float v93; // xmm8_4
  float v94; // xmm11_4
  float v95; // xmm13_4
  double v96; // xmm0_8
  __int64 v97; // rax
  float mPitchOffsetMax; // xmm2_4
  float v99; // xmm1_4
  float v100; // xmm2_4
  float v101; // xmm0_4
  float v102; // xmm1_4
  float v103; // xmm0_4
  float v104; // xmm1_4
  float v105; // eax
  float v106; // xmm1_4
  float v107; // xmm0_4
  float v108; // xmm1_4
  float v109; // xmm6_4
  float v110; // xmm14_4
  float v111; // xmm7_4
  float *v112; // rax
  UFG::SimComponent *v113; // rcx
  float v114; // xmm2_4
  float v115; // xmm9_4
  float v116; // xmm0_4
  float v117; // xmm14_4
  float v118; // xmm9_4
  float v119; // xmm6_4
  float v120; // xmm1_4
  float v121; // xmm14_4
  float v122; // xmm7_4
  float v123; // xmm14_4
  float v124; // xmm2_4
  float v125; // xmm2_4
  __m128 y_low; // xmm14
  float *v127; // rax
  __m128 v128; // xmm2
  float v129; // xmm5_4
  float v130; // xmm6_4
  float v131; // xmm14_4
  __m128 v132; // xmm7
  float v133; // xmm9_4
  float v134; // xmm3_4
  float v135; // xmm3_4
  __m128 v136; // xmm2
  int v137; // xmm2_4
  float v138; // xmm1_4
  float v139; // xmm9_4
  float v140; // xmm7_4
  float v141; // xmm0_4
  float v142; // xmm0_4
  float v143; // xmm6_4
  float v144; // xmm9_4
  float v145; // xmm7_4
  UFG::qVector3 *v146; // rax
  float v147; // xmm1_4
  float v148; // xmm0_4
  float v149; // xmm9_4
  float v150; // xmm7_4
  UFG::qVector3 *v151; // rax
  float v152; // xmm0_4
  float v153; // xmm0_4
  float v154; // xmm1_4
  float v155; // eax
  float v156; // xmm1_4
  float v157; // xmm5_4
  float v158; // xmm3_4
  float v159; // xmm4_4
  float v160; // xmm5_4
  float v161; // xmm1_4
  float v162; // xmm2_4
  float v163; // xmm2_4
  float v164; // xmm1_4
  float v165; // xmm3_4
  __m128 v166; // xmm6
  float v167; // xmm15_4
  __m128 v168; // xmm7
  float v169; // xmm4_4
  float v170; // xmm8_4
  __m128 v171; // xmm9
  float v172; // xmm11_4
  __m128 v173; // xmm13
  float v174; // xmm14_4
  float v175; // xmm3_4
  float v176; // xmm3_4
  UFG::qMatrix44 *p_mTargetWorld; // rdx
  float v178; // xmm1_4
  __m128 v179; // xmm4
  float v180; // xmm3_4
  __m128 v181; // xmm4
  float v182; // xmm2_4
  float v183; // xmm1_4
  float v184; // xmm0_4
  float v185; // xmm2_4
  float v186; // xmm1_4
  float v187; // xmm0_4
  UFG::qVector4 v188; // xmm3
  UFG::qVector4 v189; // xmm2
  UFG::qVector4 v190; // xmm1
  UFG::SimComponent *v191; // rcx
  float v192; // xmm4_4
  float v193; // xmm5_4
  float v194; // xmm2_4
  __int128 v195; // xmm9
  float v196; // xmm7_4
  float v197; // xmm3_4
  float v198; // xmm6_4
  float v199; // xmm2_4
  float v200; // xmm2_4
  float v201; // xmm6_4
  float *v202; // rax
  float v203; // xmm11_4
  __int128 v204; // xmm13
  float v205; // xmm9_4
  float ForwardSpeed; // xmm8_4
  float v207; // xmm7_4
  float v208; // xmm8_4
  float v209; // xmm2_4
  float m_RunningSumTime; // xmm0_4
  float v211; // xmm2_4
  float v212; // xmm2_4
  float v213; // xmm1_4
  float v214; // xmm0_4
  float v215; // xmm14_4
  float v216; // xmm4_4
  float p0; // xmm1_4
  float mPitchOffsetLookFactorDown; // xmm2_4
  float mPitchOffsetEyeFactorDown; // xmm0_4
  float v220; // xmm8_4
  float *p_mLookupMouse; // rsi
  float v222; // xmm14_4
  __m128 v223; // xmm15
  float v224; // xmm3_4
  float v225; // xmm5_4
  float v226; // xmm8_4
  float v227; // xmm5_4
  float v228; // xmm7_4
  float v229; // xmm11_4
  float v230; // xmm9_4
  float v231; // xmm13_4
  float v232; // xmm0_4
  float v233; // xmm2_4
  float v234; // xmm14_4
  float v235; // xmm8_4
  float v236; // xmm1_4
  float v237; // xmm0_4
  float v238; // xmm0_4
  float v239; // xmm7_4
  UFG::qVector3 *v240; // rax
  float v241; // xmm3_4
  float v242; // xmm2_4
  UFG::qVector3 *v243; // rax
  float v244; // xmm1_4
  float v245; // xmm2_4
  float v246; // xmm7_4
  float v247; // xmm8_4
  float v248; // xmm7_4
  float v249; // xmm9_4
  float v250; // xmm14_4
  float v251; // xmm11_4
  float v252; // xmm13_4
  UFG::qMatrix44 *p_m_BoundComponentHandles; // rbx
  UFG::qVector4 *v254; // rax
  float v255; // xmm7_4
  float v256; // xmm9_4
  UFG::qVector4 *v257; // rax
  bool v258; // bl
  float v259; // xmm0_4
  float v260; // xmm1_4
  float v261; // xmm2_4
  float v262; // xmm13_4
  float mAxisPositionY; // xmm11_4
  UFG::Controller *v264; // r14
  UFG::UIScreen *Screen; // rax
  unsigned int v266; // r8d
  UFG::UIScreen *v267; // r14
  UFG::InputActionData *v268; // rcx
  UFG::GameStatTracker *v269; // rax
  float Stat; // xmm0_4
  float v271; // xmm6_4
  UFG::InputActionData *v272; // rcx
  __m128 mAxisPositionX_low; // xmm9
  float mAxisPositionX; // xmm0_4
  UFG::GameStatTracker *v275; // rax
  UFG::GameStatTracker *v276; // rax
  float v277; // xmm3_4
  float v278; // xmm0_4
  UFG::InputActionData *v279; // rcx
  __m128 v280; // xmm1
  int v281; // xmm14_4
  int v282; // xmm7_4
  int v283; // xmm8_4
  int v284; // xmm6_4
  float *v285; // rax
  UFG::GameStatTracker *v286; // rax
  float v287; // xmm7_4
  float v288; // xmm8_4
  float v289; // xmm0_4
  float v290; // xmm1_4
  float v291; // xmm2_4
  float v292; // xmm0_4
  float v293; // xmm1_4
  float v294; // xmm5_4
  float v295; // xmm2_4
  float v296; // xmm13_4
  float v297; // xmm0_4
  float v298; // xmm1_4
  float v299; // xmm6_4
  float v300; // xmm0_4
  float v301; // xmm1_4
  float v302; // xmm6_4
  float v303; // xmm2_4
  float v304; // xmm1_4
  float v305; // xmm6_4
  bool m_IsKeyboardController; // al
  bool v307; // si
  float v308; // xmm0_4
  float *p_mLookaroundJoyInput; // rbx
  float v310; // xmm0_4
  float *p_mLookaroundAngle; // rbx
  bool v312; // al
  float v313; // xmm1_4
  float v314; // xmm4_4
  float v315; // xmm2_4
  float v316; // xmm12_4
  float v317; // xmm12_4
  float v318; // xmm5_4
  float v319; // xmm6_4
  float v320; // xmm9_4
  float v321; // xmm9_4
  float v322; // xmm0_4
  float v323; // xmm1_4
  __int64 v324; // rax
  UFG::SimComponent *v325; // rcx
  float v326; // xmm1_4
  float v327; // xmm7_4
  float v328; // xmm8_4
  float v329; // xmm11_4
  float v330; // xmm0_4
  float v331; // xmm1_4
  float v332; // xmm0_4
  float v333; // xmm1_4
  float v334; // xmm0_4
  float v335; // xmm1_4
  float v336; // xmm0_4
  float v337; // xmm1_4
  float v338; // xmm0_4
  float v339; // xmm1_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v340; // rax
  float *v341; // rax
  float v342; // xmm6_4
  float v343; // xmm3_4
  float v344; // xmm4_4
  float v345; // xmm0_4
  UFG::qMatrix44 *v346; // rax
  __m128 v347; // xmm6
  UFG::qVector4 v348; // xmm1
  UFG::qVector4 v349; // xmm0
  UFG::qVector4 v350; // xmm3
  int v351; // xmm2_4
  UFG::qVector4 *v352; // rax
  float v353; // xmm3_4
  __int128 v354; // xmm4
  float v355; // xmm5_4
  float v356; // xmm13_4
  __m128 v357; // xmm14
  float v358; // xmm15_4
  float v359; // xmm8_4
  __m128 v360; // xmm12
  float v361; // xmm11_4
  __m128 v362; // xmm9
  __m128 v363; // xmm2
  float v364; // xmm1_4
  float v365; // xmm11_4
  float v366; // xmm8_4
  unsigned int v367; // xmm0_4
  __m128 v368; // xmm2
  float v369; // xmm7_4
  float v370; // xmm8_4
  float v371; // xmm6_4
  float v372; // xmm7_4
  float v373; // xmm3_4
  float v374; // xmm5_4
  float v375; // xmm11_4
  float v376; // xmm7_4
  __m128 v377; // xmm2
  float v378; // xmm0_4
  __m128 v379; // xmm2
  float v380; // xmm1_4
  float v381; // xmm12_4
  float v382; // xmm1_4
  float v383; // xmm12_4
  float v384; // xmm14_4
  float v385; // xmm12_4
  __m128 v386; // xmm8
  float v387; // xmm0_4
  __m128 v388; // xmm8
  __m128 v389; // xmm1
  float v390; // xmm12_4
  __m128 v391; // xmm14
  float v392; // xmm11_4
  __m128 v393; // xmm2
  float v394; // xmm6_4
  float v395; // xmm14_4
  float v396; // xmm15_4
  __m128 v397; // xmm2
  float v398; // xmm6_4
  __m128 v399; // xmm5
  float v400; // xmm4_4
  float v401; // xmm13_4
  __m128 v402; // xmm2
  float v403; // xmm3_4
  float v404; // xmm9_4
  float v405; // xmm8_4
  float v406; // xmm3_4
  float v407; // xmm9_4
  float v408; // xmm8_4
  __m128 v409; // xmm2
  float v410; // xmm0_4
  __m128 v411; // xmm2
  float v412; // xmm1_4
  float v413; // xmm6_4
  float v414; // xmm1_4
  float v415; // xmm6_4
  float v416; // xmm5_4
  float v417; // xmm6_4
  __m128 v418; // xmm4
  float v419; // xmm0_4
  __m128 v420; // xmm4
  __m128 v421; // xmm1
  float v422; // xmm6_4
  float v423; // xmm5_4
  __m128 v424; // xmm12
  __m128 v425; // xmm2
  float v426; // xmm11_4
  float v427; // xmm7_4
  UFG::qQuaternion *v428; // rax
  float mTransitionParamEye; // xmm5_4
  float v430; // xmm2_4
  float v431; // xmm3_4
  float v432; // xmm0_4
  float v433; // xmm1_4
  float v434; // xmm0_4
  float v435; // xmm3_4
  float v436; // xmm1_4
  float v437; // xmm0_4
  float v438; // xmm1_4
  float v439; // xmm7_4
  UFG::qMatrix44 *Matrix; // rax
  UFG::qVector4 v441; // xmm5
  __m128 v442; // xmm4
  UFG::qVector4 v443; // xmm2
  UFG::qVector4 v444; // xmm3
  float ExtraWideAspectCorrectedFOV; // xmm7_4
  float v446; // xmm6_4
  float DisplayAspectRatio; // xmm0_4
  float mDesaturation; // xmm0_4
  float mMotionblurMagnitude; // eax
  float v450; // xmm0_4
  __m128 v451; // xmm2
  UFG::qVector3 eye; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 desLook; // [rsp+50h] [rbp-B0h] BYREF
  char v454; // [rsp+60h] [rbp-A0h]
  UFG::LinearGraph<UFG::qVector3> duration; // [rsp+68h] [rbp-98h] BYREF
  float v456; // [rsp+80h] [rbp-80h]
  float v457; // [rsp+84h] [rbp-7Ch]
  UFG::qVector4 result; // [rsp+88h] [rbp-78h] BYREF
  UFG::qVector3 axis; // [rsp+98h] [rbp-68h] BYREF
  unsigned int v460; // [rsp+A8h] [rbp-58h]
  float v461; // [rsp+ACh] [rbp-54h]
  float v462; // [rsp+B0h] [rbp-50h]
  float v463; // [rsp+B4h] [rbp-4Ch]
  float v464; // [rsp+B8h] [rbp-48h]
  float v465; // [rsp+BCh] [rbp-44h]
  float v466; // [rsp+C0h] [rbp-40h]
  float v467; // [rsp+C4h] [rbp-3Ch]
  float v468; // [rsp+C8h] [rbp-38h]
  UFG::qMatrix44 dest; // [rsp+D0h] [rbp-30h] BYREF
  UFG::qVector3 t; // [rsp+110h] [rbp+10h] BYREF
  UFG::qQuaternion a; // [rsp+120h] [rbp+20h] BYREF
  UFG::qVector3 v1; // [rsp+130h] [rbp+30h] BYREF
  UFG::qMatrix44 mat; // [rsp+140h] [rbp+40h] BYREF
  UFG::qMatrix44 verts; // [rsp+180h] [rbp+80h] BYREF
  float v475; // [rsp+1C0h] [rbp+C0h]
  float v476; // [rsp+1C4h] [rbp+C4h]
  float v477; // [rsp+1C8h] [rbp+C8h]
  float v478; // [rsp+1CCh] [rbp+CCh]
  float v479; // [rsp+1D0h] [rbp+D0h]
  float v480; // [rsp+1D4h] [rbp+D4h]
  float v481; // [rsp+1D8h] [rbp+D8h]
  float v482; // [rsp+1DCh] [rbp+DCh]
  UFG::qMatrix44 v483; // [rsp+1E0h] [rbp+E0h] BYREF
  UFG::qVector3 newEye; // [rsp+220h] [rbp+120h] BYREF
  UFG::qQuaternion b; // [rsp+230h] [rbp+130h] BYREF
  UFG::qQuaternion v486; // [rsp+240h] [rbp+140h] BYREF
  UFG::qMatrix44 matrix44; // [rsp+250h] [rbp+150h] BYREF
  char v488; // [rsp+380h] [rbp+280h]
  float v489; // [rsp+380h] [rbp+280h]
  bool v490; // [rsp+388h] [rbp+288h]
  float v491; // [rsp+388h] [rbp+288h]
  float v492; // [rsp+388h] [rbp+288h]

  if ( UFG::Metrics::msInstance.mSimTimeDelta <= 0.0 )
    return;
  if ( !this->mActive )
    return;
  v4 = 1;
  if ( UFG::gFlowController.mCurrentState )
  {
    if ( UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
      return;
  }
  if ( !this->mTarget.m_pSimComponent )
    return;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v5 = this->mTransitionParam - (float)(UFG::ChaseCameraComponent::rTransitionToChaseParamRate * dt);
  this->mTransitionParam = v5;
  if ( v5 <= 0.0 )
  {
    v5 = 0.0;
    goto LABEL_10;
  }
  v6 = *(float *)&FLOAT_1_0;
  if ( v5 < 1.0 )
LABEL_10:
    v6 = v5;
  v7 = !this->mLockEye;
  this->mTransitionParam = v6;
  vfptr = this->mTarget.m_pSimComponent->vfptr;
  if ( v7 )
  {
    v13 = ((float (*)(void))vfptr[28].__vecDelDtor)();
    v10 = *(float *)&FLOAT_1_0;
    v14 = (float)(v13 - 4.0) * 0.33333334;
    if ( v14 <= 0.0 )
    {
      v14 = 0.0;
    }
    else if ( v14 >= 1.0 )
    {
      v14 = *(float *)&FLOAT_1_0;
    }
    v12 = (float)(v14 * 0.49999994) + 0.80000001;
  }
  else
  {
    v9 = ((double (*)(void))vfptr[28].__vecDelDtor)();
    v10 = *(float *)&FLOAT_1_0;
    v11 = (float)(*(float *)&v9 - 4.0) * 0.33333334;
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
  if ( !this->mLockEye )
    v10 = 0.0;
  UFG::qApproach(&this->mLockEyeParam, v10, v12, dt);
  if ( this->mLockLook )
    v15 = *(float *)&FLOAT_1_0;
  else
    v15 = 0.0;
  UFG::qApproach(&this->mLockLookParam, v15, 0.80000001, dt);
  v16 = *(float *)&FLOAT_1_0;
  v17 = this->mTransitionParamEye - dt;
  v18 = v17;
  this->mTransitionParamEye = v17;
  if ( v17 <= 0.0 )
  {
    v18 = 0.0;
  }
  else if ( v17 >= 1.0 )
  {
    v18 = *(float *)&FLOAT_1_0;
  }
  mTransitionParamOrient = this->mTransitionParamOrient;
  this->mTransitionParamEye = v18;
  v20 = mTransitionParamOrient - dt;
  v21 = v20;
  this->mTransitionParamOrient = v20;
  if ( v20 <= 0.0 )
  {
    v21 = 0.0;
    goto LABEL_35;
  }
  if ( v20 < 1.0 )
LABEL_35:
    v16 = v21;
  this->mTransitionParamOrient = v16;
  UFG::GameCameraComponent::Update(this, dt);
  mBlendSeconds = this->mBlendSeconds;
  if ( mBlendSeconds > 0.0 )
    this->mBlendPrevious = this->mBlendPrevious - (float)(dt / mBlendSeconds);
  if ( this->mBlendPrevious < 0.0 )
    *(_QWORD *)&this->mBlendPrevious = 0i64;
  v23 = *(UFG::SimObjectCVBase **)&this->mTarget.m_pSimComponent[13].m_Flags;
  if ( v23 )
  {
    m_Flags = v23->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v23);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v23,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v23,
                                                                      UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  this->mTargetingSystem = ComponentOfTypeHK;
  if ( dt > 0.0 )
    UFG::ChaseCameraComponent::AutoLockUnlock(this, dt);
  mTargetingSystem = this->mTargetingSystem;
  if ( !mTargetingSystem
    || (unsigned int)(mTargetingSystem->m_eFocusMode - 3) > 1
    && mTargetingSystem->m_eFocusMode != eFOCUS_MODE_LOCKED_SOFT )
  {
    v27 = 0;
    goto LABEL_57;
  }
  v27 = 1;
  if ( this->mAimOrFocus )
  {
LABEL_57:
    v488 = 0;
    goto LABEL_58;
  }
  v488 = 1;
LABEL_58:
  if ( !this->mAimOrFocus || v27 )
    v4 = 0;
  v454 = v4;
  this->mAimOrFocus = v27;
  if ( v27 )
    v28 = *(float *)&FLOAT_1_0;
  else
    v28 = 0.0;
  UFG::qApproach(&this->mAimParam, v28, 4.75, dt);
  if ( v4 )
    UFG::ChaseCameraComponent::GotoAngleSnap(this, 0.0, 0);
  UFG::ChaseCameraComponent::DetermineChaseParameters(this);
  v29 = (int *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[17].__vecDelDtor)(this->mTarget.m_pSimComponent);
  m_pSimComponent = this->mTarget.m_pSimComponent;
  v466 = *(float *)v29;
  v467 = *((float *)v29 + 1);
  v31 = *((float *)v29 + 2);
  v32 = m_pSimComponent->vfptr;
  v465 = v31;
  v33 = ((__int64 (__fastcall *)(UFG::SimComponent *))v32[20].__vecDelDtor)(m_pSimComponent);
  v34 = *(float *)v33;
  v35 = (__m128)*(unsigned int *)(v33 + 4);
  v36 = *(float *)(v33 + 8);
  v37 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v38 = *v37;
  v39 = v37[1];
  v35.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v34 * v34)) + (float)(v36 * v36);
  LODWORD(v40) = _mm_sqrt_ps(v35).m128_u32[0];
  v464 = v40;
  v41 = v40;
  if ( UFG::ChaseCameraComponent::bOverrideSpeedInput )
    v41 = UFG::ChaseCameraComponent::mOverrideSpeed;
  v42 = this->mTargetingSystem;
  mAimFreeDuration = FLOAT_0_40000001;
  v44 = FLOAT_0_40000001;
  v45 = v42 && ((unsigned int)(v42->m_eFocusMode - 3) <= 1 || v42->m_eFocusMode == eFOCUS_MODE_LOCKED_SOFT);
  pChaseParameters = this->pChaseParameters;
  v490 = v45;
  if ( pChaseParameters && pChaseParameters->mContext == eCHASE_CONTEXT_AIM )
  {
    if ( v45 )
      mAimFreeDuration = this->mAimFreeDuration;
    else
      mAimFreeDuration = this->mAimLockedDuration;
    v44 = mAimFreeDuration;
  }
  *(_QWORD *)&v47 = LODWORD(this->mYawAngVelTimespan);
  if ( *(float *)&v47 != this->mYawAngVelSubmittedTimespan )
  {
    UFG::qAverageWindow<float>::SetTimespan(&this->mYawAngVelWindow, v47, 30.0);
    this->mYawAngVelSubmittedTimespan = this->mYawAngVelTimespan;
  }
  v48 = UFG::ChaseCameraComponent::rTransitionToChaseEyeLookSupplimentaryDuration * this->mTransitionParam;
  *(float *)&duration.nData = v48 + v44;
  *((float *)&duration.nData + 1) = v48 + v44;
  *(float *)&duration.fDomain = v48 + v44;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mLook, (UFG::qVector3 *)&duration);
  *(float *)&duration.nData = v48 + mAimFreeDuration;
  *((float *)&duration.nData + 1) = v48 + mAimFreeDuration;
  *(float *)&duration.fDomain = v48 + mAimFreeDuration;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mEye, (UFG::qVector3 *)&duration);
  duration.nData = 1017370378;
  *(&duration.nData + 1) = 1017370378;
  LODWORD(duration.fDomain) = 1017370378;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mAimLook, (UFG::qVector3 *)&duration);
  duration.nData = 1017370378;
  *(&duration.nData + 1) = 1017370378;
  LODWORD(duration.fDomain) = 1017370378;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mAimEye, (UFG::qVector3 *)&duration);
  v49 = UFG::ChaseCameraComponent::mFovDuration + v48;
  v50 = this->mFov.mParameter / this->mFov.mDuration;
  this->mFov.mParameter = v50;
  if ( v49 <= 0.0099999998 )
    v49 = FLOAT_0_0099999998;
  this->mFov.mDuration = v49;
  this->mFov.mParameter = v49 * v50;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  duration.nData = 1065353216;
  *(&duration.nData + 1) = 1065353216;
  LODWORD(duration.fDomain) = 1065353216;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mUp, (UFG::qVector3 *)&duration);
  v51 = this->mTargetPitch.mParameter / this->mTargetPitch.mDuration;
  this->mTargetPitch.mParameter = v51;
  v52 = UFG::ChaseCameraComponent::mTargetPitchDuration;
  if ( UFG::ChaseCameraComponent::mTargetPitchDuration <= 0.0099999998 )
    v52 = FLOAT_0_0099999998;
  this->mTargetPitch.mDuration = v52;
  this->mTargetPitch.mParameter = v52 * v51;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mTargetPitch);
  if ( this->mTarget.m_pSimComponent
    && (v53 = *(UFG::SimObjectCVBase **)&this->mTarget.m_pSimComponent[13].m_Flags) != 0i64 )
  {
    v54 = v53->m_Flags;
    if ( (v54 & 0x4000) != 0 || v54 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v53);
    }
    else if ( (v54 & 0x2000) != 0 || (v54 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v53,
                                                                    UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::TargetingSystemPedPlayerComponent *)UFG::SimObject::GetComponentOfType(
                                                                    v53,
                                                                    UFG::TargetingSystemPedPlayerComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfType = 0i64;
  }
  if ( ComponentOfType )
    m_pPointer = ComponentOfType->m_pEquippedSOWPC.m_pPointer;
  else
    m_pPointer = 0i64;
  v57 = UFG::tbRecoilUseTweakables || !m_pPointer;
  mRecoilAngleDesired = this->mRecoilAngleDesired;
  if ( v57 )
  {
    if ( mRecoilAngleDesired <= 0.0 )
      v59 = UFG::trRecoilKickupRateDecay;
    else
      v59 = UFG::trRecoilKickupRateAttack;
    v60 = LODWORD(UFG::trRecoilKickbackDur);
  }
  else
  {
    v61 = *((_QWORD *)&m_pPointer[2].m_BoundComponentHandles.mNode.mPrev->mNext + HIDWORD(m_pPointer[2].m_pSimObject));
    v59 = *(float *)(v61 + 428);
    v60 = *(_DWORD *)(v61 + 444);
  }
  if ( UFG::qApproach(&this->mRecoilAngle, mRecoilAngleDesired, (float)(v59 * 3.1415927) * 0.0055555557, dt) )
  {
    if ( this->mRecoilAngleDesired > 0.0 )
      this->mRecoilAngleDesired = 0.0;
    if ( this->mRecoilAngleDesired == 0.0 && this->mRecoilAngle > 0.0 )
      UFG::GameCameraComponent::ResetAimWobble(this);
  }
  duration.nData = v60;
  *(&duration.nData + 1) = v60;
  LODWORD(duration.fDomain) = v60;
  UFG::HomerCubic<UFG::qVector3>::SetDuration(&this->mRecoilEye, (UFG::qVector3 *)&duration);
  v62 = atan2f(v39, v38);
  v63 = this->mForwardAngle - v62;
  for ( this->mForwardAngleDesired = v62; v63 > 3.1415927; v63 = v63 + -6.2831855 )
    ;
  for ( ; v63 < -3.1415927; v63 = v63 + 6.2831855 )
    ;
  v64 = (float)(v40 - this->mCenteringSpeedMin) / (float)(this->mCenteringSpeedMax - this->mCenteringSpeedMin);
  if ( v64 <= 0.0 )
  {
    v64 = 0.0;
  }
  else
  {
    v65 = *(float *)&FLOAT_1_0;
    if ( v64 >= 1.0 )
      goto LABEL_123;
  }
  v65 = v64;
LABEL_123:
  UFG::qApproachAngle(&this->mForwardAngle, v62, COERCE_FLOAT(LODWORD(v63) & _xmm) * (float)(v65 * 10.0), dt);
  NormAngle(&this->mForwardAngle);
  v66 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[14].__vecDelDtor)(this->mTarget.m_pSimComponent);
  mForwardAngle = this->mForwardAngle;
  v68 = *v66;
  v69 = v66[1];
  v70 = v66[2];
  v456 = cosf(mForwardAngle);
  v71 = sinf(mForwardAngle);
  if ( this->mUpdateEyeOffset )
  {
    duration.fDomain = this->mEyeOffsetDomain;
    duration.nData = 3;
    duration.tRange = this->mEyeOffsetRange;
    Value = UFG::LinearGraph<UFG::qVector3>::GetValue(&duration, (UFG::qVector3 *)&result, v41);
    y = Value->y;
    z = Value->z;
    this->mEyeOffset.x = Value->x;
    this->mEyeOffset.y = y;
    this->mEyeOffset.z = z;
  }
  duration.fDomain = this->mTargetOffsetDomain;
  duration.nData = 3;
  duration.tRange = this->mTargetOffsetRange;
  v75 = UFG::LinearGraph<UFG::qVector3>::GetValue(&duration, (UFG::qVector3 *)&result, v41);
  v76 = FLOAT_0_000099999997;
  v77 = v75->y;
  v78 = v75->z;
  this->mTargetOffset.x = v75->x;
  this->mTargetOffset.y = v77;
  this->mTargetOffset.z = v78;
  x = this->mFovRamp.x;
  v80 = this->mFovRamp.z;
  w = this->mFovRamp.w;
  if ( (float)(this->mFovRamp.y - x) >= 0.000099999997 )
    v76 = this->mFovRamp.y - x;
  if ( v41 <= x )
    v82 = this->mFovRamp.x;
  else
    v82 = v41;
  if ( v82 >= this->mFovRamp.y )
    v82 = this->mFovRamp.y;
  v83 = sinf((float)(v82 - x) * (float)(1.5707964 / v76));
  this->mFov.p1 = (float)((float)(w - v80) * (float)(v83 * v83)) + v80;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  v84 = (__m128)LODWORD(v456);
  v85 = 0.0;
  this->mFov.mParameter = 0.0;
  v87 = v84;
  v86 = (float)(v69 * 0.0) - (float)(v71 * v70);
  v87.m128_f32[0] = (float)(v84.m128_f32[0] * v70) - (float)(v68 * 0.0);
  v89 = v87;
  v88 = (float)(v71 * v68) - (float)(v84.m128_f32[0] * v69);
  v89.m128_f32[0] = (float)((float)(v87.m128_f32[0] * v87.m128_f32[0]) + (float)(v86 * v86)) + (float)(v88 * v88);
  if ( v89.m128_f32[0] == 0.0 )
    v90 = 0.0;
  else
    v90 = 1.0 / _mm_sqrt_ps(v89).m128_f32[0];
  v91 = v90;
  v92 = v90;
  v93 = v90 * v88;
  v94 = v91 * v86;
  v95 = v92 * v87.m128_f32[0];
  if ( !this->mIsLookingAround )
    LODWORD(v85) = COERCE_UNSIGNED_INT(v93 * UFG::gChaseWallDutch) ^ _xmm[0];
  UFG::HomerCubicAngular::SetDesiredPosition(&this->mDutch, v85);
  if ( (UFG::VehicleSubjectComponent::IsDoingWheelie((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent)
     || UFG::VehicleSubjectComponent::IsInAir((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent))
    && !this->mIsLookingAround )
  {
    LODWORD(v96) = 0;
  }
  else
  {
    v97 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)(this->mTarget.m_pSimComponent);
    v96 = UFG::qASin(COERCE_DOUBLE((unsigned __int64)*(_DWORD *)(v97 + 8)));
  }
  mPitchOffsetMax = this->mPitchOffsetMax;
  v99 = (float)(mPitchOffsetMax * -3.1415927) * 0.0055555557;
  v100 = (float)(mPitchOffsetMax * 3.1415927) * 0.0055555557;
  if ( *(float *)&v96 <= v99 )
    *(float *)&v96 = v99;
  if ( *(float *)&v96 >= v100 )
    *(float *)&v96 = v100;
  this->mTargetPitch.p1 = *(float *)&v96;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mTargetPitch);
  this->mTargetPitch.mParameter = 0.0;
  UFG::ChaseCameraComponent::UpdateTargeting(this);
  if ( v488 )
  {
    v101 = this->mAimEye.p1.y;
    v102 = this->mAimEye.p1.z;
    this->mAimEye.p0.x = this->mAimEye.p1.x;
    this->mAimEye.p0.y = v101;
    this->mAimEye.p0.z = v102;
    v103 = this->mAimEye.v1.y;
    v104 = this->mAimEye.v1.z;
    this->mAimEye.v0.x = this->mAimEye.v1.x;
    this->mAimEye.v0.y = v103;
    this->mAimEye.v0.z = v104;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimEye);
    *(_QWORD *)&this->mAimEye.mParameter.x = 0i64;
    this->mAimEye.mParameter.z = 0.0;
    v105 = this->mAimLook.p1.x;
    v106 = this->mAimLook.p1.z;
    this->mAimLook.p0.y = this->mAimLook.p1.y;
    this->mAimLook.p0.z = v106;
    this->mAimLook.p0.x = v105;
    v107 = this->mAimLook.v1.y;
    v108 = this->mAimLook.v1.z;
    this->mAimLook.v0.x = this->mAimLook.v1.x;
    this->mAimLook.v0.y = v107;
    this->mAimLook.v0.z = v108;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mAimLook);
    *(_QWORD *)&this->mAimLook.mParameter.x = 0i64;
    this->mAimLook.mParameter.z = 0.0;
  }
  UFG::HomerCubic<UFG::qVector3>::Update(&this->mAimEye, dt);
  UFG::HomerCubic<UFG::qVector3>::Update(&this->mAimLook, dt);
  v109 = this->mAimEye.p0.x + this->mRecoilEye.p0.x;
  v110 = this->mAimEye.p0.y + this->mRecoilEye.p0.y;
  v111 = this->mAimEye.p0.z + this->mRecoilEye.p0.z;
  v112 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v113 = this->mTarget.m_pSimComponent;
  v114 = v110;
  v115 = v110;
  v116 = v109;
  v117 = (float)(v110 * v112[6]) + (float)(v109 * v112[2]);
  v118 = (float)((float)((float)(v115 * v112[4]) + (float)(v109 * *v112)) + (float)(v111 * v112[8])) + v112[12];
  v119 = this->mAimLook.p0.x;
  v120 = v111 * v112[9];
  v121 = v117 + (float)(v111 * v112[10]);
  v122 = this->mAimLook.p0.z;
  v123 = v121 + v112[14];
  v124 = (float)((float)(v114 * v112[5]) + (float)(v116 * v112[1])) + v120;
  v462 = v118;
  v125 = v124 + v112[13];
  v457 = v123;
  y_low = (__m128)LODWORD(this->mAimLook.p0.y);
  v489 = v125;
  v127 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v113->vfptr[18].__vecDelDtor)(v113);
  v128 = y_low;
  v128.m128_f32[0] = y_low.m128_f32[0] * v127[5];
  v129 = (float)((float)((float)(y_low.m128_f32[0] * v127[4]) + (float)(v119 * *v127)) + (float)(v122 * v127[8]))
       + v127[12];
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * v127[6]) + (float)(v119 * v127[2]);
  v128.m128_f32[0] = v128.m128_f32[0] + (float)(v119 * v127[1]);
  v461 = v129;
  v130 = v129 - v118;
  v128.m128_f32[0] = (float)(v128.m128_f32[0] + (float)(v122 * v127[9])) + v127[13];
  v131 = (float)(y_low.m128_f32[0] + (float)(v122 * v127[10])) + v127[14];
  v132 = v128;
  v132.m128_f32[0] = v128.m128_f32[0] - v489;
  v133 = v131 - v457;
  v460 = v128.m128_u32[0];
  v463 = v131;
  v134 = FLOAT_0_000099999997;
  if ( (float)((float)((float)(v132.m128_f32[0] * v132.m128_f32[0]) + (float)(v130 * v130)) + (float)(v133 * v133)) > 0.000099999997 )
  {
    v136 = v132;
    v135 = 0.0;
    v136.m128_f32[0] = (float)((float)(v132.m128_f32[0] * v132.m128_f32[0]) + (float)(v130 * v130))
                     + (float)(v133 * v133);
    if ( v136.m128_f32[0] != 0.0 )
      v135 = 1.0 / _mm_sqrt_ps(v136).m128_f32[0];
    v137 = LODWORD(this->mRecoilAngle) ^ _xmm[0];
    LODWORD(duration.fDomain) = 0;
    *(float *)&duration.nData = v135 * v132.m128_f32[0];
    *(&duration.nData + 1) = COERCE_UNSIGNED_INT(v135 * v130) ^ _xmm[0];
    UFG::qRotationMatrixAxis(&dest, (UFG::qVector3 *)&duration, *(float *)&v137);
    v134 = FLOAT_0_000099999997;
    v461 = v462
         + (float)((float)((float)((float)(dest.v1.x * v132.m128_f32[0]) + (float)(dest.v0.x * v130))
                         + (float)(dest.v2.x * v133))
                 + dest.v3.x);
    *(float *)&v460 = (float)((float)((float)((float)(dest.v1.y * v132.m128_f32[0]) + (float)(dest.v0.y * v130))
                                    + (float)(dest.v2.y * v133))
                            + dest.v3.y)
                    + v489;
    v131 = (float)((float)((float)((float)(dest.v1.z * v132.m128_f32[0]) + (float)(dest.v0.z * v130))
                         + (float)(dest.v2.z * v133))
                 + dest.v3.z)
         + v457;
    v463 = v131;
  }
  v138 = this->mNoiseMagnitudeRamp.x;
  v139 = this->mNoiseMagnitudeRamp.z;
  v140 = this->mNoiseMagnitudeRamp.w;
  if ( (float)(this->mNoiseMagnitudeRamp.y - v138) >= v134 )
    v134 = this->mNoiseMagnitudeRamp.y - v138;
  if ( v41 <= v138 )
    v141 = this->mNoiseMagnitudeRamp.x;
  else
    v141 = v41;
  if ( v141 >= this->mNoiseMagnitudeRamp.y )
    v141 = this->mNoiseMagnitudeRamp.y;
  v142 = sinf((float)(v141 - v138) * (float)(1.5707964 / v134));
  v143 = (float)((float)(v142 * v142) * (float)(v140 - v139)) + v139;
  if ( v143 > 0.0 )
  {
    v144 = v461;
    v145 = *(float *)&v460;
    *(float *)&duration.nData = v461;
    *(&duration.nData + 1) = v460;
    *(float *)&duration.fDomain = v131;
    v146 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(
             &this->mLookNoise,
             (UFG::qVector3 *)&result,
             (UFG::qVector3 *)&duration);
    v147 = v143 * v146->y;
    v148 = v143 * v146->z;
    v461 = v144 + (float)(v143 * v146->x);
    v149 = v457;
    *(float *)&v460 = v145 + v147;
    v150 = v462;
    v463 = v131 + v148;
    *(float *)&duration.nData = v462;
    *((float *)&duration.nData + 1) = v489;
    *(float *)&duration.fDomain = v457;
    v151 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(
             &this->mEyeNoise,
             (UFG::qVector3 *)&result,
             (UFG::qVector3 *)&duration);
    v152 = v143 * v151->x;
    v489 = (float)(v143 * v151->y) + v489;
    v457 = (float)(v143 * v151->z) + v149;
    v462 = v150 + v152;
  }
  if ( UFG::VehicleSubjectComponent::IsDoingWheelie((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent)
    || UFG::ChaseCameraComponent::mWheelieOverride )
  {
    if ( this->mUpdateEyeOffset )
      this->mEyeOffset.z = UFG::ChaseCameraComponent::mWheelieEyeZOffset + this->mEyeOffset.z;
    this->mTargetOffset.z = UFG::ChaseCameraComponent::mWheelieLookZOffset + this->mTargetOffset.z;
  }
  if ( (UFG::ChaseCameraComponent::mInAirOverride
     || UFG::VehicleSubjectComponent::IsInAir((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent))
    && !UFG::VehicleSubjectComponent::IsDoingWheelie((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent)
    && *(float *)(((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[20].__vecDelDtor)(this->mTarget.m_pSimComponent)
                + 8) > -0.5 )
  {
    if ( this->mUpdateEyeOffset )
      this->mEyeOffset.z = this->mInAirEyeZOffset + this->mEyeOffset.z;
    this->mTargetOffset.z = this->mInAirLookZOffset + this->mTargetOffset.z;
  }
  if ( this->pChaseParameters == (UFG::ChaseCameraParameters *)this->mTarget.m_pSimComponent[15].vfptr
    && !this->mHijackerLeft )
  {
    this->mEyeOffset.y = this->mEyeOffset.y * -1.0;
  }
  v153 = this->mEyeOffset.y;
  v154 = this->mEyeOffset.z;
  this->mEye.p1.x = this->mEyeOffset.x;
  this->mEye.p1.y = v153;
  this->mEye.p1.z = v154;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mEye);
  *(_QWORD *)&this->mEye.mParameter.x = 0i64;
  this->mEye.mParameter.z = 0.0;
  v155 = this->mTargetOffset.x;
  v156 = this->mTargetOffset.z;
  this->mLook.p1.y = this->mTargetOffset.y;
  this->mLook.p1.z = v156;
  this->mLook.p1.x = v155;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mLook);
  *(_QWORD *)&this->mLook.mParameter.x = 0i64;
  this->mLook.mParameter.z = 0.0;
  v157 = (float)((float)((float)(v95 * 0.0) + (float)(v94 * 0.0)) + (float)(v93 * 0.0)) * 2.0;
  v158 = v157 * v93;
  v159 = v157 * v94;
  v160 = v157 * v95;
  v161 = fsqrt((float)((float)(v160 * v160) + (float)(v159 * v159)) + (float)(v158 * v158));
  if ( v161 > 1.0 )
  {
    v159 = v159 * (float)(1.0 / v161);
    v160 = v160 * (float)(1.0 / v161);
    v158 = v158 * (float)(1.0 / v161);
  }
  v162 = this->mTilt * 0.25;
  this->mUp.p1.z = (float)(v162 * v158) + 1.0;
  this->mUp.p1.x = v162 * v159;
  this->mUp.p1.y = v162 * v160;
  UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mUp);
  *(_QWORD *)&this->mUp.mParameter.x = 0i64;
  this->mUp.mParameter.z = 0.0;
  if ( this->mIsLookingAround )
  {
    *(_QWORD *)&this->mUp.p1.x = 0i64;
    this->mUp.p1.z = 1.0;
    UFG::HomerCubic<UFG::qVector3>::MakeCoeffs(&this->mUp);
    *(_QWORD *)&this->mUp.mParameter.x = 0i64;
    this->mUp.mParameter.z = 0.0;
  }
  if ( dt > 0.0 )
    UFG::qAverageWindow<float>::AddValue(
      &this->mYawAngVelWindow,
      *(float *)&this->mTarget.m_pSimComponent[9].m_TypeUID,
      dt);
  UFG::HomerCubic<UFG::qVector3>::Update(&this->mUp, dt);
  UFG::HomerCubic<float>::Update(&this->mFov, dt);
  UFG::HomerCubicAngular::Update(&this->mDutch, dt);
  v163 = this->mUp.p0.y;
  v164 = this->mUp.p0.z;
  v165 = this->mUp.p0.x;
  v166 = (__m128)LODWORD(v163);
  v168 = (__m128)LODWORD(v456);
  v166.m128_f32[0] = (float)(v163 * 0.0) - (float)(v71 * v164);
  v167 = (float)(v71 * v165) - (float)(v456 * v163);
  v171 = v166;
  v168.m128_f32[0] = (float)(v456 * v164) - (float)(v165 * 0.0);
  v169 = (float)(v168.m128_f32[0] * v164) - (float)(v167 * v163);
  v170 = (float)(v167 * v165) - (float)(v166.m128_f32[0] * v164);
  v171.m128_f32[0] = (float)(v166.m128_f32[0] * v163) - (float)(v168.m128_f32[0] * v165);
  v173 = v171;
  v172 = (float)(v170 * v167) - (float)(v171.m128_f32[0] * v168.m128_f32[0]);
  axis.x = v172;
  v173.m128_f32[0] = (float)(v171.m128_f32[0] * v166.m128_f32[0]) - (float)(v169 * v167);
  axis.y = v173.m128_f32[0];
  v174 = (float)(v169 * v168.m128_f32[0]) - (float)(v170 * v166.m128_f32[0]);
  axis.z = v174;
  v175 = (float)((float)(v170 * v170) + (float)(v169 * v169)) + (float)(v171.m128_f32[0] * v171.m128_f32[0]);
  if ( v175 == 0.0 )
    v176 = 0.0;
  else
    v176 = 1.0 / fsqrt(v175);
  p_mTargetWorld = &this->mTargetWorld;
  v178 = v176 * v169;
  v179 = v168;
  this->mTargetWorld.v0.w = 0.0;
  this->mTargetWorld.v0.z = v176 * v171.m128_f32[0];
  this->mTargetWorld.v0.y = v176 * v170;
  this->mTargetWorld.v0.x = v178;
  v179.m128_f32[0] = (float)((float)(v168.m128_f32[0] * v168.m128_f32[0]) + (float)(v166.m128_f32[0] * v166.m128_f32[0]))
                   + (float)(v167 * v167);
  if ( v179.m128_f32[0] == 0.0 )
    v180 = 0.0;
  else
    v180 = 1.0 / _mm_sqrt_ps(v179).m128_f32[0];
  v181 = v173;
  this->mTargetWorld.v1.w = 0.0;
  this->mTargetWorld.v1.z = v180 * v167;
  this->mTargetWorld.v1.y = v180 * v168.m128_f32[0];
  this->mTargetWorld.v1.x = v180 * v166.m128_f32[0];
  v181.m128_f32[0] = (float)((float)(v173.m128_f32[0] * v173.m128_f32[0]) + (float)(v172 * v172)) + (float)(v174 * v174);
  if ( v181.m128_f32[0] == 0.0 )
    v182 = 0.0;
  else
    v182 = 1.0 / _mm_sqrt_ps(v181).m128_f32[0];
  this->mTargetWorld.v2.w = 0.0;
  v183 = v182;
  v184 = v182;
  this->mTargetWorld.v2.z = v182 * v174;
  v185 = v465;
  this->mTargetWorld.v2.x = v183 * v172;
  v186 = v467;
  this->mTargetWorld.v2.y = v184 * v173.m128_f32[0];
  this->mTargetWorld.v3.w = 1.0;
  v187 = v466;
  this->mTargetWorld.v3.y = v186;
  this->mTargetWorld.v3.z = v185;
  this->mTargetWorld.v3.x = v187;
  v188 = this->mTargetWorld.v1;
  v189 = this->mTargetWorld.v2;
  v190 = this->mTargetWorld.v3;
  this->mEyeWorld.v0 = p_mTargetWorld->v0;
  this->mEyeWorld.v1 = v188;
  this->mEyeWorld.v2 = v189;
  this->mEyeWorld.v3 = v190;
  UFG::qInverseAffine(&this->mWorldEye, p_mTargetWorld);
  this->mUpdateEyeOffset = 1;
  UFG::HomerCubic<UFG::qVector3>::Update(&this->mEye, dt);
  UFG::HomerCubic<UFG::qVector3>::Update(&this->mLook, dt);
  UFG::HomerCubic<float>::Update(&this->mTargetPitch, dt);
  UFG::HomerCubic<UFG::qVector3>::Update(&this->mRecoilEye, dt);
  if ( this->mSnapNext )
  {
    this->mSnapNext = 0;
    UFG::ChaseCameraComponent::Snap(this);
  }
  v191 = this->mTarget.m_pSimComponent;
  v192 = this->mEye.p0.x + this->mRecoilEye.p0.x;
  v193 = this->mEye.p0.z + this->mRecoilEye.p0.z;
  v194 = this->mEye.p0.y + this->mRecoilEye.p0.y;
  v195 = LODWORD(this->mLook.p0.y);
  v196 = this->mLook.p0.z;
  v197 = (float)((float)(v194 * this->mEyeWorld.v1.x) + (float)(v192 * this->mEyeWorld.v0.x))
       + (float)(v193 * this->mEyeWorld.v2.x);
  v198 = (float)(v194 * this->mEyeWorld.v1.z) + (float)(v192 * this->mEyeWorld.v0.z);
  v199 = (float)(v194 * this->mEyeWorld.v1.y) + (float)(v192 * this->mEyeWorld.v0.y);
  eye.x = v197 + this->mEyeWorld.v3.x;
  v200 = (float)(v199 + (float)(v193 * this->mEyeWorld.v2.y)) + this->mEyeWorld.v3.y;
  eye.z = (float)(v198 + (float)(v193 * this->mEyeWorld.v2.z)) + this->mEyeWorld.v3.z;
  v201 = this->mLook.p0.x;
  eye.y = v200;
  v202 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v191->vfptr[18].__vecDelDtor)(v191);
  v204 = v195;
  v203 = (float)((float)((float)(*(float *)&v195 * v202[4]) + (float)(v201 * *v202)) + (float)(v196 * v202[8]))
       + v202[12];
  *(float *)&v204 = (float)((float)((float)(*(float *)&v195 * v202[5]) + (float)(v201 * v202[1]))
                          + (float)(v196 * v202[9]))
                  + v202[13];
  v205 = (float)((float)((float)(*(float *)&v195 * v202[6]) + (float)(v201 * v202[2])) + (float)(v196 * v202[10]))
       + v202[14];
  LODWORD(desLook.y) = v204;
  desLook.x = v203;
  desLook.z = v205;
  if ( UFG::ChaseCameraComponent::bOverrideSpeedInput )
  {
    ForwardSpeed = UFG::ChaseCameraComponent::mOverrideSpeed;
  }
  else
  {
    v205 = desLook.z;
    v204 = LODWORD(desLook.y);
    v203 = desLook.x;
    ForwardSpeed = UFG::VehicleSubjectComponent::GetForwardSpeed((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent);
  }
  v207 = *(float *)&FLOAT_1_0;
  v208 = COERCE_FLOAT(LODWORD(ForwardSpeed) & _xmm) / UFG::ChaseCameraComponent::mYawAngularSpeedThreshold;
  if ( v208 <= 0.0 )
  {
    v208 = 0.0;
  }
  else if ( v208 >= 1.0 )
  {
    v208 = *(float *)&FLOAT_1_0;
  }
  if ( this->mYawAngVelWindow.m_StartIndex == this->mYawAngVelWindow.m_EndIndex )
  {
    v209 = 0.0;
  }
  else
  {
    m_RunningSumTime = this->mYawAngVelWindow.m_RunningSumTime;
    if ( m_RunningSumTime > 0.0 )
      v209 = this->mYawAngVelWindow.m_RunningSum / m_RunningSumTime;
    else
      v209 = FLOAT_3_4028235e38;
  }
  v211 = (float)(COERCE_FLOAT(LODWORD(v209) & _xmm)
               - (float)((float)(this->mLookOffsetAngVelMin * 3.1415927) * 0.0055555557))
       / (float)((float)((float)(this->mLookOffsetAngVelMax * 3.1415927) * 0.0055555557)
               - (float)((float)(this->mLookOffsetAngVelMin * 3.1415927) * 0.0055555557));
  if ( v211 <= 0.0 )
  {
    v211 = 0.0;
  }
  else if ( v211 >= 1.0 )
  {
    v211 = *(float *)&FLOAT_1_0;
  }
  v212 = (float)(v211 * 3.1415927) - 1.5707964;
  if ( this->mYawAngVelWindow.m_StartIndex == this->mYawAngVelWindow.m_EndIndex )
    goto LABEL_215;
  v213 = this->mYawAngVelWindow.m_RunningSumTime;
  if ( v213 <= 0.0 || (v214 = this->mYawAngVelWindow.m_RunningSum / v213, v214 > 0.0) )
  {
    v215 = *(float *)&FLOAT_1_0;
    goto LABEL_216;
  }
  if ( v214 >= 0.0 )
  {
LABEL_215:
    v215 = 0.0;
    goto LABEL_216;
  }
  v215 = FLOAT_N1_0;
LABEL_216:
  v216 = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(sinf(v212) + 1.0) * 0.5) * v215) ^ _xmm[0])
       * (float)(v208 * this->mLookOffsetMax);
  if ( !UFG::ChaseCameraComponent::bEnableAngVelOffset || !this->mIsLookingAround )
    v216 = 0.0;
  p0 = this->mTargetPitch.p0;
  if ( p0 <= 0.0 )
    mPitchOffsetLookFactorDown = this->mPitchOffsetLookFactorDown;
  else
    mPitchOffsetLookFactorDown = this->mPitchOffsetLookFactorUp;
  v456 = COERCE_FLOAT(LODWORD(p0) & _xmm) * mPitchOffsetLookFactorDown;
  if ( p0 <= 0.0 )
    mPitchOffsetEyeFactorDown = this->mPitchOffsetEyeFactorDown;
  else
    mPitchOffsetEyeFactorDown = this->mPitchOffsetEyeFactorUp;
  v220 = COERCE_FLOAT(LODWORD(p0) & _xmm) * mPitchOffsetEyeFactorDown;
  if ( this->mIsLookingAround || this->mAimOrFocus || !UFG::ChaseCameraComponent::bEnablePitchOffset )
  {
    v456 = 0.0;
    v220 = 0.0;
  }
  v223 = (__m128)v204;
  p_mLookupMouse = &this->mLookupMouse;
  v222 = v203 - eye.x;
  v223.m128_f32[0] = *(float *)&v204 - eye.y;
  v224 = v205 - eye.z;
  v225 = 0.0;
  v226 = v220 + this->mLookupMouse;
  if ( (float)((float)((float)(v223.m128_f32[0] * v223.m128_f32[0]) + (float)(v222 * v222)) + (float)(v224 * v224)) > 0.000099999997 )
  {
    if ( (float)((float)((float)(v223.m128_f32[0] * v223.m128_f32[0]) + (float)(v222 * v222)) + (float)(v224 * v224)) == 0.0 )
      v227 = 0.0;
    else
      v227 = 1.0 / _mm_sqrt_ps(v223).m128_f32[0];
    v228 = v227;
    v225 = v227 * v223.m128_f32[0];
    v207 = v228 * v222;
  }
  v229 = v203 + (float)((float)((float)(v207 * 0.0) + (float)(v225 * v216)) + (float)(v456 * 0.0));
  desLook.x = v229;
  v230 = v205 + (float)((float)(v216 * 0.0) + v456);
  eye.z = eye.z + v226;
  v231 = *(float *)&v204
       + (float)((float)((float)(v225 * 0.0) + (float)(v216 * COERCE_FLOAT(LODWORD(v207) ^ _xmm[0])))
               + (float)(v456 * 0.0));
  desLook.z = v230;
  desLook.y = v231;
  if ( v490 )
  {
    UFG::ChaseCameraComponent::RestrictOrbitHeight(this, &eye);
    v230 = desLook.z;
    v231 = desLook.y;
    v229 = desLook.x;
  }
  v232 = FLOAT_0_000099999997;
  if ( !this->mAimOrFocus )
  {
    this->mFocusPos.x = v229;
    this->mFocusPos.y = v231;
    this->mFocusPos.z = v230;
  }
  v233 = this->mNoiseMagnitudeRamp.x;
  v234 = this->mNoiseMagnitudeRamp.z;
  v235 = this->mNoiseMagnitudeRamp.w;
  if ( (float)(this->mNoiseMagnitudeRamp.y - v233) >= 0.000099999997 )
    v232 = this->mNoiseMagnitudeRamp.y - v233;
  v236 = 1.5707964 / v232;
  if ( v41 <= v233 )
    v237 = this->mNoiseMagnitudeRamp.x;
  else
    v237 = v41;
  if ( v237 >= this->mNoiseMagnitudeRamp.y )
    v237 = this->mNoiseMagnitudeRamp.y;
  v238 = sinf((float)(v237 - v233) * v236);
  v239 = (float)((float)(v238 * v238) * (float)(v235 - v234)) + v234;
  if ( v239 > 0.0 )
  {
    *(float *)&duration.nData = v229;
    *((float *)&duration.nData + 1) = v231;
    *(float *)&duration.fDomain = v230;
    v240 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(
             &this->mLookNoise,
             (UFG::qVector3 *)&result,
             (UFG::qVector3 *)&duration);
    v241 = v239 * v240->z;
    v242 = v239 * v240->y;
    desLook.x = desLook.x + (float)(v239 * v240->x);
    desLook.z = desLook.z + v241;
    desLook.y = desLook.y + v242;
    duration.nData = LODWORD(eye.x);
    *(_QWORD *)(&duration.nData + 1) = *(_QWORD *)&eye.y;
    v243 = UFG::qNoise<UFG::qVector3,UFG::qVector3>::GetValue(
             &this->mEyeNoise,
             (UFG::qVector3 *)&result,
             (UFG::qVector3 *)&duration);
    v244 = v239 * v243->x;
    v245 = v239 * v243->y;
    v246 = v239 * v243->z;
    eye.x = eye.x + v244;
    eye.y = eye.y + v245;
    eye.z = eye.z + v246;
  }
  UFG::CameraSubject::GetBoxVerts((UFG::CameraSubject *)this->mTarget.m_pSimComponent, (UFG::qVector3 *)&verts, 0.0);
  v247 = (float)((float)((float)((float)(UFG::qVector3::msZero.z + verts.v3.z) + v476) + v479) + v482) * 0.25;
  v248 = (float)((float)((float)((float)(UFG::qVector3::msZero.x + verts.v3.x) + verts.v3.w) + v477) + v480) * 0.25;
  v249 = (float)((float)((float)((float)(UFG::qVector3::msZero.y + verts.v3.y) + v475) + v478) + v481) * 0.25;
  if ( v247 <= 0.5 )
    v250 = FLOAT_0_5;
  else
    v250 = (float)((float)((float)((float)(UFG::qVector3::msZero.z + verts.v3.z) + v476) + v479) + v482) * 0.25;
  v251 = v248 * 0.5;
  if ( (float)(v248 * 0.5) <= 0.2 )
    v251 = FLOAT_0_2;
  v252 = v251 * 0.5;
  if ( (float)(v251 * 0.5) <= 0.5 )
    v252 = FLOAT_0_5;
  if ( UFG::VehicleSubjectComponent::IsBoat((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent) )
    v250 = 0.0;
  p_m_BoundComponentHandles = (UFG::qMatrix44 *)&this->mTarget.m_pSimComponent[1].m_BoundComponentHandles;
  result.w = 1.0;
  result.y = v249;
  result.z = v247;
  result.x = v248 - 0.40000001;
  v254 = UFG::operator*((UFG::qVector4 *)&duration, &result, p_m_BoundComponentHandles);
  result.w = 1.0;
  v255 = v254->x;
  v256 = v254->y;
  v456 = v254->z;
  v465 = v255;
  v466 = v256;
  result.y = (float)((float)((float)((float)(UFG::qVector3::msZero.y + verts.v0.y) + verts.v1.x) + verts.v1.w)
                   + verts.v2.z)
           * 0.25;
  result.z = (float)((float)((float)((float)(UFG::qVector3::msZero.z + verts.v0.z) + verts.v1.y) + verts.v2.x)
                   + verts.v2.w)
           * 0.25;
  result.x = (float)((float)((float)((float)((float)(UFG::qVector3::msZero.x + verts.v0.x) + verts.v0.w) + verts.v1.z)
                           + verts.v2.y)
                   * 0.25)
           + 0.40000001;
  v257 = UFG::operator*((UFG::qVector4 *)&duration, &result, p_m_BoundComponentHandles);
  v258 = 0;
  v259 = v257->x;
  v260 = v257->y;
  v261 = v257->z;
  this->mPushInOverrideRate = 0.0;
  this->mCollisionTargetPointsNum = 2;
  this->mCollisionBlend = v252;
  this->mCollisionRise = v250;
  this->mCollisionPlateau = v251;
  this->mCollisionTargetPoints[0].x = v255;
  this->mCollisionTargetPoints[0].y = v256;
  v491 = v259;
  v262 = v259;
  v467 = v260;
  this->mCollisionTargetPoints[0].z = v456;
  this->mCollisionTargetPoints[1].x = v259;
  this->mCollisionTargetPoints[1].y = v260;
  this->mCollisionTargetPoints[1].z = v261;
  mAxisPositionY = UFG::qVector2::msZero.y;
  v468 = v261;
  v264 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  if ( UFG::UI::InMinigame() && v264 )
    v258 = (v264->m_SubModes & 4) != 0;
  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "DialogBox");
  v266 = UFG::gActiveControllerNum;
  v267 = Screen;
  if ( !UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    goto LABEL_279;
  if ( UFG::UI::InMinigame() && !v258 || v267 )
  {
    v266 = UFG::gActiveControllerNum;
LABEL_279:
    v279 = UFG::ActionDef_CamMoveHorizVert.mDataPerController[v266];
    if ( v279 )
      mAxisPositionY = v279->mAxisPositionY;
    else
      mAxisPositionY = 0.0;
    if ( v279 )
      mAxisPositionX_low = (__m128)LODWORD(v279->mAxisPositionX);
    else
      mAxisPositionX_low = 0i64;
    UFG::qApproach(&this->mLookupMouse, 0.0, COERCE_FLOAT(*(_DWORD *)p_mLookupMouse & _xmm) * lookupZeroRate, dt);
    goto LABEL_286;
  }
  v268 = UFG::ActionDef_LookBack.mDataPerController[UFG::gActiveControllerNum];
  if ( v268 && v268->mActionTrue )
    mAxisPositionY = *(float *)&FLOAT_1_0;
  v269 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v269, CameraSpeedYaw);
  mAxisPositionX_low = (__m128)LODWORD(UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax);
  v271 = 0.0;
  v272 = UFG::ActionDef_Mouse.mDataPerController[UFG::gActiveControllerNum];
  mAxisPositionX_low.m128_f32[0] = (float)((float)((float)(UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax + 1.0)
                                                 - (float)(1.0 - UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax))
                                         * Stat)
                                 + (float)(1.0 - UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax);
  if ( v272 )
    mAxisPositionX = v272->mAxisPositionX;
  else
    mAxisPositionX = 0.0;
  mAxisPositionX_low.m128_f32[0] = (float)(mAxisPositionX_low.m128_f32[0]
                                         * UFG::ChaseCameraComponent::rMouseLookaroundScale)
                                 * mAxisPositionX;
  if ( v272 )
    v271 = v272->mAxisPositionY;
  v275 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v275, YAxisInverted) )
    LODWORD(v271) ^= _xmm[0];
  v276 = UFG::GameStatTracker::Instance();
  v277 = (float)((float)((float)((float)((float)(UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax + 1.0)
                                       - (float)(1.0 - UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax))
                               * UFG::GameStatTracker::GetStat(v276, CameraSpeedPitch))
                       + (float)(1.0 - UFG::ChaseCameraComponent::rMouseOptionsPercentMinMax))
               * (float)(v271 * UFG::ChaseCameraComponent::rLookupMouseSensitivity))
       + *p_mLookupMouse;
  *p_mLookupMouse = v277;
  v278 = v277;
  if ( v277 <= UFG::ChaseCameraComponent::rLookupMouseMin )
    v278 = UFG::ChaseCameraComponent::rLookupMouseMin;
  if ( v278 >= UFG::ChaseCameraComponent::rLookupMouseMax )
    v278 = UFG::ChaseCameraComponent::rLookupMouseMax;
  *p_mLookupMouse = v278;
LABEL_286:
  if ( UFG::GameCameraComponent::mNoRotationTimer > 0.0 )
  {
    mAxisPositionX_low = (__m128)LODWORD(UFG::qVector2::msZero.x);
    mAxisPositionY = UFG::qVector2::msZero.y;
  }
  v280 = mAxisPositionX_low;
  v280.m128_f32[0] = (float)(mAxisPositionX_low.m128_f32[0] * mAxisPositionX_low.m128_f32[0])
                   + (float)(mAxisPositionY * mAxisPositionY);
  if ( _mm_sqrt_ps(v280).m128_f32[0] <= UFG::ChaseCameraComponent::rLookaroundDeadzone || this->mAimOrFocus )
  {
    mAxisPositionX_low.m128_i32[0] = LODWORD(UFG::qVector2::msZero.x);
    mAxisPositionY = UFG::qVector2::msZero.y;
  }
  if ( mAxisPositionY <= 0.69999999 )
  {
    if ( this->mLookingBack )
    {
      mAxisPositionX_low.m128_i32[0] = 0;
      this->mLookaroundJoyInput = 0.0;
    }
    v281 = _xmm[0];
    this->mLookingBack = 0;
  }
  else
  {
    v281 = _xmm[0];
    if ( !this->mLookingBack )
    {
      v282 = LODWORD(this->mCamera.mTransformation.v2.x) ^ _xmm[0];
      v283 = LODWORD(this->mCamera.mTransformation.v2.y) ^ _xmm[0];
      v284 = LODWORD(this->mCamera.mTransformation.v2.z) ^ _xmm[0];
      v285 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[16].__vecDelDtor)(this->mTarget.m_pSimComponent);
      if ( (float)((float)((float)(*(float *)&v283 * v285[1]) + (float)(*(float *)&v282 * *v285))
                 + (float)(*(float *)&v284 * v285[2])) > -0.85000002 )
        this->mLookingBack = 1;
    }
  }
  v286 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v286, XAxisInverted) )
    mAxisPositionX_low.m128_i32[0] ^= v281;
  v287 = (float)(sinf((float)(this->mLockEyeParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  v288 = (float)(sinf((float)(this->mLockLookParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( !this->mLookingBack )
  {
    if ( this->mLockEye )
    {
      v289 = (float)(1.0 - v287) * this->mLockEyeVel.x;
      v290 = (float)(1.0 - v287) * this->mLockEyeVel.y;
      v291 = (float)((float)((float)(1.0 - v287) * this->mLockEyeVel.z) * dt) + this->mLockEyePos.z;
      this->mLockEyePos.z = v291;
      v292 = (float)(v289 * dt) + this->mLockEyePos.x;
      v293 = (float)(v290 * dt) + this->mLockEyePos.y;
      this->mLockEyePos.x = v292;
      eye.x = v292;
      eye.z = v291;
      this->mLockEyePos.y = v293;
      eye.y = v293;
    }
    else
    {
      v294 = (float)(v287 * (float)(this->mLockEyePos.x - eye.x)) + eye.x;
      v295 = (float)(v287 * (float)(this->mLockEyePos.y - eye.y)) + eye.y;
      v296 = eye.z + (float)(v287 * (float)(this->mLockEyePos.z - eye.z));
      eye.x = v294;
      eye.z = v296;
      eye.y = v295;
      if ( v287 == 0.0 )
      {
        this->mLockEyePos.x = v294;
        this->mLockEyePos.y = v295;
        this->mLockEyePos.z = v296;
      }
      v262 = v491;
    }
    if ( this->mLockLook )
    {
      v297 = (float)(1.0 - v288) * this->mLockLookVel.x;
      v298 = (float)(1.0 - v288) * this->mLockLookVel.y;
      v299 = (float)((float)((float)(1.0 - v288) * this->mLockLookVel.z) * dt) + this->mLockLookPos.z;
      this->mLockLookPos.z = v299;
      v300 = (float)(v297 * dt) + this->mLockLookPos.x;
      v301 = (float)(v298 * dt) + this->mLockLookPos.y;
      this->mLockLookPos.x = v300;
      desLook.x = v300;
      desLook.z = v299;
      this->mLockLookPos.y = v301;
      desLook.y = v301;
    }
    else
    {
      v302 = (float)(v288 * (float)(this->mLockLookPos.x - desLook.x)) + desLook.x;
      v303 = (float)(v288 * (float)(this->mLockLookPos.y - desLook.y)) + desLook.y;
      v304 = (float)(v288 * (float)(this->mLockLookPos.z - desLook.z)) + desLook.z;
      desLook.x = v302;
      desLook.y = v303;
      desLook.z = v304;
      if ( v288 == 0.0 )
      {
        this->mLockLookPos.x = v302;
        this->mLockLookPos.y = v303;
        this->mLockLookPos.z = v304;
      }
    }
  }
  v305 = 0.0;
  if ( mAxisPositionY < -0.30000001 )
  {
    mAxisPositionX_low.m128_i32[0] = 0;
    v305 = (float)(mAxisPositionY + 0.30000001) * -1.4285715;
  }
  this->mLookaroundCenterTimer = dt + this->mLookaroundCenterTimer;
  if ( mAxisPositionX_low.m128_f32[0] != UFG::qVector2::msZero.x || mAxisPositionY != UFG::qVector2::msZero.y )
    this->mLookaroundCenterTimer = 0.0;
  if ( this->mTarget.m_pSimComponent
    && !UFG::VehicleSubjectComponent::IsGas((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent) )
  {
    this->mLookaroundCenterTimer = 0.0;
  }
  m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  v307 = m_IsKeyboardController
      && !this->mLockEye
      && !this->mLockLook
      && UFG::ChaseCameraComponent::rLookaroundCenterTimerMouse > this->mLookaroundCenterTimer;
  if ( m_IsKeyboardController )
    v308 = UFG::ChaseCameraComponent::rLookaroundJoyInputApproachRateMouse;
  else
    v308 = UFG::ChaseCameraComponent::rLookaroundJoyInputApproachRate;
  p_mLookaroundJoyInput = &this->mLookaroundJoyInput;
  if ( m_IsKeyboardController )
    *p_mLookaroundJoyInput = mAxisPositionX_low.m128_f32[0];
  else
    UFG::qApproach(
      &this->mLookaroundJoyInput,
      mAxisPositionX_low.m128_f32[0],
      COERCE_FLOAT(COERCE_UNSIGNED_INT(*p_mLookaroundJoyInput - mAxisPositionX_low.m128_f32[0]) & _xmm) * v308,
      dt);
  if ( this->mLookingBack )
    *p_mLookaroundJoyInput = 0.0;
  UFG::qApproach(
    &this->mLookupJoyInput,
    v305,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(this->mLookupJoyInput - v305) & _xmm)
  * UFG::ChaseCameraComponent::rLookupJoyInputApproachRate,
    dt);
  if ( !this->mAimOrFocus )
  {
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
      v310 = (float)(UFG::ChaseCameraComponent::rLookaroundRotateRateMouse * *p_mLookaroundJoyInput) * 0.016666668;
    else
      v310 = (float)(UFG::ChaseCameraComponent::rLookaroundRotateRate * *p_mLookaroundJoyInput) * dt;
    this->mLookaroundAngle = v310 + this->mLookaroundAngle;
  }
  p_mLookaroundAngle = &this->mLookaroundAngle;
  NormAngle(&this->mLookaroundAngle);
  v312 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  if ( v312 )
    v313 = UFG::ChaseCameraComponent::rLookaroundCenterRateScaleMouse;
  else
    v313 = UFG::ChaseCameraComponent::rLookaroundCenterRateScale;
  if ( v307 )
    v313 = 0.0;
  if ( v312 )
    v314 = UFG::ChaseCameraComponent::rLookaroundCenterRateMaxMouse;
  else
    v314 = UFG::ChaseCameraComponent::rLookaroundCenterRateMax;
  if ( v307 )
    v314 = FLOAT_0_0099999998;
  v315 = *(float *)&FLOAT_1_0;
  if ( this->mAimOrFocus )
  {
    v316 = FLOAT_10_0;
  }
  else
  {
    v317 = (float)(v41 - 2.0) / (float)(this->mCenteringSpeedMax - 2.0);
    if ( v317 <= 0.0 )
    {
      v317 = 0.0;
    }
    else if ( v317 >= 1.0 )
    {
      v317 = *(float *)&FLOAT_1_0;
    }
    v316 = (float)(v317 * 10.0) * v313;
  }
  if ( COERCE_FLOAT(mAxisPositionX_low.m128_i32[0] & _xmm) < 0.0099999998 )
  {
    v318 = (float)(v464 - this->mCenteringSpeedMin) / (float)(this->mCenteringSpeedMax - this->mCenteringSpeedMin);
    if ( v318 <= 0.0 )
    {
      v318 = 0.0;
    }
    else if ( v318 >= 1.0 )
    {
      goto LABEL_360;
    }
    v315 = v318;
LABEL_360:
    v316 = v314 * v315;
  }
  v319 = COERCE_FLOAT(*(_DWORD *)p_mLookaroundAngle & _xmm) * v316;
  if ( UFG::VehicleSubjectComponent::IsInReverse((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent) )
    v319 = v319 + 4.0;
  UFG::qApproachAngle(&this->mLookaroundAngle, 0.0, v319, dt);
  if ( COERCE_FLOAT(*(_DWORD *)p_mLookaroundAngle & _xmm) < 0.000099999997 )
    *p_mLookaroundAngle = 0.0;
  v320 = UFG::ChaseCameraComponent::rLookupHeight;
  this->mAlternateLookValid = 0;
  v321 = v320 * this->mLookupJoyInput;
  if ( this->mAimOrFocus || v321 > 0.0099999998 )
  {
    v322 = v467 + v466;
    v323 = v468 + v456;
    this->mAlternateLook.x = (float)(v262 + v465) * 0.5;
    this->mAlternateLook.y = v322 * 0.5;
    this->mAlternateLook.z = v323 * 0.5;
    this->mAlternateLookValid = 1;
  }
  v324 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->mTarget.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTarget.m_pSimComponent);
  v325 = this->mTarget.m_pSimComponent;
  v326 = *(float *)(v324 + 16);
  v327 = *(float *)v324;
  v328 = *(float *)(v324 + 4);
  v329 = *(float *)(v324 + 8);
  dest.v0.w = *(float *)(v324 + 12);
  v330 = *(float *)(v324 + 20);
  dest.v1.x = v326;
  v331 = *(float *)(v324 + 24);
  dest.v1.y = v330;
  v332 = *(float *)(v324 + 28);
  dest.v1.z = v331;
  v333 = *(float *)(v324 + 32);
  dest.v1.w = v332;
  dest.v2.y = *(float *)(v324 + 36);
  v334 = *(float *)(v324 + 44);
  dest.v2.x = v333;
  v335 = *(float *)(v324 + 40);
  dest.v2.w = v334;
  v336 = *(float *)(v324 + 52);
  dest.v2.z = v335;
  v337 = *(float *)(v324 + 48);
  dest.v3.y = v336;
  v338 = *(float *)(v324 + 60);
  dest.v3.x = v337;
  v339 = *(float *)(v324 + 56);
  v340 = v325->vfptr;
  dest.v0.x = v327;
  dest.v0.y = v328;
  dest.v0.z = v329;
  dest.v3.z = v339;
  dest.v3.w = v338;
  v341 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v340[20].__vecDelDtor)(v325);
  v342 = 0.0;
  v343 = v341[1];
  v344 = v341[2];
  v1.x = *v341;
  v1.y = v343;
  v1.z = v344;
  if ( (float)((float)((float)(v1.x * v1.x) + (float)(v343 * v343)) + (float)(v344 * v344)) > 36.0
    && (float)((float)((float)(v343 * v328) + (float)(v327 * v1.x)) + (float)(v344 * v329)) > 0.69999999
    && UFG::VehicleSubjectComponent::IsDoingWheelie((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent) )
  {
    *(float *)&duration.nData = v327;
    *((float *)&duration.nData + 1) = v328;
    *(float *)&duration.fDomain = v329;
    v342 = UFG::qAngleBetween(&v1, (UFG::qVector3 *)&duration);
    v345 = 0.0;
    if ( v342 <= 0.0 || (v345 = FLOAT_1_5707964, v342 >= 1.5707964) )
      v342 = v345;
  }
  UFG::qApproach(&this->mLookbackCorrectionAngle, v342, 1.8, dt);
  if ( !this->mLookingBack
    || UFG::VehicleSubjectComponent::IsDoingOneEighty((UFG::VehicleSubjectComponent *)this->mTarget.m_pSimComponent) )
  {
    v370 = eye.x - desLook.x;
    v371 = eye.y - desLook.y;
    v372 = eye.z - desLook.z;
    UFG::qRotationMatrixAxis(&dest, &axis, *p_mLookaroundAngle);
    v373 = dest.v1.x * v371;
    v354 = LODWORD(dest.v1.y);
    v361 = desLook.x;
    *(float *)&v354 = dest.v1.y * v371;
    v374 = dest.v1.z * v371;
    v360 = (__m128)LODWORD(desLook.y);
    v358 = axis.z;
    v357 = (__m128)LODWORD(axis.y);
    v356 = axis.x;
    v347 = (__m128)(unsigned int)FLOAT_1_0;
    v353 = (float)((float)(v373 + (float)(dest.v0.x * v370)) + (float)(dest.v2.x * v372)) + desLook.x;
    *(float *)&v354 = (float)((float)(*(float *)&v354 + (float)(dest.v0.y * v370)) + (float)(dest.v2.y * v372))
                    + desLook.y;
    eye.x = v353;
    LODWORD(eye.y) = v354;
    v355 = (float)((float)(v374 + (float)(dest.v0.z * v370)) + (float)(dest.v2.z * v372)) + desLook.z;
    v359 = desLook.z + v321;
    desLook.z = desLook.z + v321;
    eye.z = v355;
    if ( !this->mLockEye )
    {
      v362 = 0i64;
      if ( this->mLockEyeParam == 0.0 )
      {
        this->mLockEyePos.x = v353;
        LODWORD(this->mLockEyePos.y) = v354;
        this->mLockEyePos.z = v355;
      }
      goto LABEL_378;
    }
  }
  else
  {
    UFG::qRotationMatrixAxis(
      &matrix44,
      &UFG::qVector3::msAxisY,
      COERCE_FLOAT(LODWORD(this->mLookbackCorrectionAngle) ^ _xmm[0]));
    v346 = UFG::qMatrix44::operator*(&matrix44, &verts, &dest);
    v347 = (__m128)(unsigned int)FLOAT_1_0;
    result.w = 1.0;
    v348 = v346->v3;
    v349 = v346->v0;
    v350 = v346->v1;
    matrix44.v2 = v346->v2;
    v351 = LODWORD(this->mEyeOffsetRange[0].x) ^ _xmm[0];
    matrix44.v0 = v349;
    v349.x = this->mEyeOffsetRange[0].y;
    matrix44.v3 = v348;
    v348.x = this->mEyeOffsetRange[0].z;
    LODWORD(result.x) = v351;
    result.y = v349.x;
    result.z = v348.x;
    matrix44.v1 = v350;
    v352 = UFG::operator*((UFG::qVector4 *)&duration, &result, &matrix44);
    v353 = v352->x;
    v354 = LODWORD(v352->y);
    v355 = v352->z;
    v356 = UFG::qVector3::msDirUp.x;
    v357 = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
    v358 = UFG::qVector3::msDirUp.z;
    v359 = desLook.z;
    v360 = (__m128)LODWORD(desLook.y);
    v361 = desLook.x;
    eye.x = v352->x;
    LODWORD(eye.y) = v354;
    eye.z = v355;
    axis = UFG::qVector3::msDirUp;
  }
  v362 = 0i64;
LABEL_378:
  v363 = (__m128)v354;
  v364 = v353 - v361;
  v365 = v361 - v353;
  v363.m128_f32[0] = (float)((float)(*(float *)&v354 - v360.m128_f32[0]) * (float)(*(float *)&v354 - v360.m128_f32[0]))
                   + (float)(v364 * v364);
  v360.m128_f32[0] = v360.m128_f32[0] - *(float *)&v354;
  v363.m128_f32[0] = v363.m128_f32[0] + (float)((float)(v355 - v359) * (float)(v355 - v359));
  v366 = v359 - v355;
  v367 = _mm_sqrt_ps(v363).m128_u32[0];
  v368 = v360;
  v464 = *(float *)&v367;
  v368.m128_f32[0] = (float)((float)(v360.m128_f32[0] * v360.m128_f32[0]) + (float)(v365 * v365)) + (float)(v366 * v366);
  if ( v368.m128_f32[0] == v362.m128_f32[0] )
    v369 = v362.m128_f32[0];
  else
    v369 = v347.m128_f32[0] / _mm_sqrt_ps(v368).m128_f32[0];
  v377 = v357;
  mat.v0.w = 0.0;
  v492 = v369 * v365;
  mat.v0.x = v369 * v365;
  v375 = v369 * v360.m128_f32[0];
  v376 = v369 * v366;
  v468 = v375;
  mat.v0.y = v375;
  v377.m128_f32[0] = (float)((float)(v357.m128_f32[0] * v357.m128_f32[0]) + (float)(v356 * v356)) + (float)(v358 * v358);
  mat.v0.z = v376;
  if ( v377.m128_f32[0] == v362.m128_f32[0] )
  {
    v379 = v362;
  }
  else
  {
    v378 = _mm_sqrt_ps(v377).m128_f32[0];
    v379 = v347;
    v379.m128_f32[0] = v347.m128_f32[0] / v378;
  }
  v380 = v379.m128_f32[0];
  v381 = v379.m128_f32[0];
  v379.m128_f32[0] = v379.m128_f32[0] * v358;
  v382 = v380 * v357.m128_f32[0];
  v383 = v381 * v356;
  v384 = (float)(v382 * v376) - (float)(v379.m128_f32[0] * v375);
  v379.m128_f32[0] = (float)(v379.m128_f32[0] * v492) - (float)(v383 * v376);
  v385 = (float)(v383 * v375) - (float)(v382 * v492);
  v386 = v379;
  v386.m128_f32[0] = (float)((float)(v379.m128_f32[0] * v379.m128_f32[0]) + (float)(v384 * v384)) + (float)(v385 * v385);
  if ( v386.m128_f32[0] == v362.m128_f32[0] )
  {
    v388 = v362;
  }
  else
  {
    v387 = _mm_sqrt_ps(v386).m128_f32[0];
    v388 = v347;
    v388.m128_f32[0] = v347.m128_f32[0] / v387;
  }
  v389 = v388;
  v389.m128_f32[0] = v388.m128_f32[0] * v384;
  mat.v1.w = 0.0;
  mat.v1.z = v388.m128_f32[0] * v385;
  v391 = v389;
  LODWORD(mat.v1.x) = v389.m128_i32[0];
  mat.v1.y = v388.m128_f32[0] * v379.m128_f32[0];
  v390 = (float)((float)(v388.m128_f32[0] * v385) * v468) - (float)((float)(v388.m128_f32[0] * v379.m128_f32[0]) * v376);
  v391.m128_f32[0] = (float)(v389.m128_f32[0] * v376) - (float)(mat.v1.z * v492);
  v392 = (float)((float)(v388.m128_f32[0] * v379.m128_f32[0]) * v492) - (float)(v389.m128_f32[0] * v468);
  v393 = v391;
  v393.m128_f32[0] = (float)((float)(v391.m128_f32[0] * v391.m128_f32[0]) + (float)(v390 * v390)) + (float)(v392 * v392);
  if ( v393.m128_f32[0] == v362.m128_f32[0] )
    v394 = v362.m128_f32[0];
  else
    v394 = v347.m128_f32[0] / _mm_sqrt_ps(v393).m128_f32[0];
  mat.v3.x = v353;
  LODWORD(mat.v3.y) = v354;
  mat.v2.w = 0.0;
  mat.v3.w = 1.0;
  mat.v2.z = v394 * v392;
  mat.v3.z = v355;
  mat.v2.x = v394 * v390;
  mat.v2.y = v394 * v391.m128_f32[0];
  UFG::qQuaternion::Set(&a, &mat);
  v399 = (__m128)v460;
  v395 = v462;
  v396 = v457;
  v397 = (__m128)LODWORD(v489);
  v398 = v461 - v462;
  v397.m128_f32[0] = (float)((float)((float)(v489 - *(float *)&v460) * (float)(v489 - *(float *)&v460))
                           + (float)((float)(v462 - v461) * (float)(v462 - v461)))
                   + (float)((float)(v457 - v463) * (float)(v457 - v463));
  v399.m128_f32[0] = *(float *)&v460 - v489;
  v400 = v463 - v457;
  LODWORD(v401) = _mm_sqrt_ps(v397).m128_u32[0];
  v402 = v399;
  v402.m128_f32[0] = (float)((float)(v399.m128_f32[0] * v399.m128_f32[0]) + (float)(v398 * v398)) + (float)(v400 * v400);
  if ( v402.m128_f32[0] == 0.0 )
    v403 = 0.0;
  else
    v403 = 1.0 / _mm_sqrt_ps(v402).m128_f32[0];
  v404 = v403;
  v405 = v403;
  v406 = v403 * v400;
  v483.v0.w = 0.0;
  v407 = v404 * v399.m128_f32[0];
  v408 = v405 * v398;
  v483.v0.z = v406;
  v409 = (__m128)LODWORD(UFG::qVector3::msDirUp.y);
  v483.v0.x = v408;
  v483.v0.y = v407;
  v409.m128_f32[0] = (float)((float)(v409.m128_f32[0] * v409.m128_f32[0])
                           + (float)(UFG::qVector3::msDirUp.x * UFG::qVector3::msDirUp.x))
                   + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
  if ( v409.m128_f32[0] == 0.0 )
  {
    v411 = 0i64;
  }
  else
  {
    v410 = _mm_sqrt_ps(v409).m128_f32[0];
    v411 = (__m128)(unsigned int)FLOAT_1_0;
    v411.m128_f32[0] = 1.0 / v410;
  }
  v412 = v411.m128_f32[0];
  v413 = v411.m128_f32[0];
  v411.m128_f32[0] = v411.m128_f32[0] * UFG::qVector3::msDirUp.z;
  v414 = v412 * UFG::qVector3::msDirUp.y;
  v415 = v413 * UFG::qVector3::msDirUp.x;
  v416 = (float)(v414 * v406) - (float)(v411.m128_f32[0] * v407);
  v411.m128_f32[0] = (float)(v411.m128_f32[0] * v408) - (float)(v415 * v406);
  v417 = (float)(v415 * v407) - (float)(v414 * v408);
  v418 = v411;
  v418.m128_f32[0] = (float)((float)(v411.m128_f32[0] * v411.m128_f32[0]) + (float)(v416 * v416)) + (float)(v417 * v417);
  if ( v418.m128_f32[0] == 0.0 )
  {
    v420 = 0i64;
  }
  else
  {
    v419 = _mm_sqrt_ps(v418).m128_f32[0];
    v420 = (__m128)(unsigned int)FLOAT_1_0;
    v420.m128_f32[0] = 1.0 / v419;
  }
  v421 = v420;
  v483.v1.w = 0.0;
  v421.m128_f32[0] = v420.m128_f32[0] * v416;
  v424 = v421;
  v483.v1.x = v420.m128_f32[0] * v416;
  v483.v1.z = v420.m128_f32[0] * v417;
  v483.v1.y = v420.m128_f32[0] * v411.m128_f32[0];
  v422 = (float)((float)(v420.m128_f32[0] * v417) * v407) - (float)((float)(v420.m128_f32[0] * v411.m128_f32[0]) * v406);
  v423 = (float)((float)(v420.m128_f32[0] * v411.m128_f32[0]) * v408) - (float)((float)(v420.m128_f32[0] * v416) * v407);
  v424.m128_f32[0] = (float)(v421.m128_f32[0] * v406) - (float)(v483.v1.z * v408);
  v425 = v424;
  v425.m128_f32[0] = (float)((float)(v424.m128_f32[0] * v424.m128_f32[0]) + (float)(v422 * v422)) + (float)(v423 * v423);
  if ( v425.m128_f32[0] == 0.0 )
    v426 = 0.0;
  else
    v426 = 1.0 / _mm_sqrt_ps(v425).m128_f32[0];
  v483.v3.x = v462;
  v483.v3.z = v457;
  v483.v2.w = 0.0;
  v483.v3.w = 1.0;
  v483.v2.z = v426 * v423;
  v483.v3.y = v489;
  v483.v2.x = v426 * v422;
  v483.v2.y = v426 * v424.m128_f32[0];
  UFG::qQuaternion::Set(&b, &v483);
  v427 = (float)(sinf((float)(this->mAimParam * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  eye.x = (float)(v427 * v395) + (float)((float)(1.0 - v427) * eye.x);
  eye.y = (float)(v427 * v489) + (float)((float)(1.0 - v427) * eye.y);
  eye.z = (float)(v427 * v396) + (float)(eye.z * (float)(1.0 - v427));
  v428 = UFG::qSlerp((UFG::qQuaternion *)&result, &a, &b, v427, qAngularPath_Shortest);
  mTransitionParamEye = this->mTransitionParamEye;
  v430 = v428->z;
  v431 = v428->w;
  v432 = v428->x;
  a.y = v428->y;
  v433 = mTransitionParamEye * this->mTransitionFromEye.y;
  a.x = v432;
  a.w = v431;
  a.z = v430;
  v434 = mTransitionParamEye * this->mTransitionFromEye.x;
  v435 = this->mTransitionParamOrient;
  *(_QWORD *)&t.y = __PAIR64__(
                      (float)(mTransitionParamEye * this->mTransitionFromEye.z)
                    + (float)((float)(1.0 - mTransitionParamEye) * eye.z),
                      v433 + (float)((float)(1.0 - mTransitionParamEye) * eye.y));
  t.x = v434 + (float)((float)(1.0 - mTransitionParamEye) * eye.x);
  UFG::qSlerp(&v486, &a, &this->mTransitionFromOri, v435, qAngularPath_Shortest);
  v436 = this->mTransitionParamEye;
  v437 = 1.0 - v436;
  v438 = v436 * this->mTransitionFromLen;
  eye = t;
  v439 = (float)((float)((float)(v427 * v401) + (float)((float)(1.0 - v427) * v464)) * v437) + v438;
  Matrix = UFG::qQuaternion::GetMatrix(&v486, &verts, &t);
  v441 = Matrix->v0;
  v442 = (__m128)Matrix->v2;
  v443 = Matrix->v0;
  v444 = Matrix->v1;
  mat.v3 = Matrix->v3;
  duration.nData = v442.m128_i32[0];
  mat.v0 = v441;
  mat.v2 = (UFG::qVector4)v442;
  *(&duration.nData + 1) = _mm_shuffle_ps(v442, v442, 85).m128_u32[0];
  LODWORD(duration.fDomain) = _mm_shuffle_ps(v442, v442, 170).m128_u32[0];
  desLook.y = (float)(_mm_shuffle_ps((__m128)v441, (__m128)v441, 85).m128_f32[0] * v439) + eye.y;
  desLook.x = (float)(v443.x * v439) + eye.x;
  desLook.z = eye.z + (float)(_mm_shuffle_ps((__m128)v441, (__m128)v441, 170).m128_f32[0] * v439);
  mat.v1 = v444;
  if ( v454 )
    ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[31].__vecDelDtor)(this);
  UFG::GameCameraComponent::SetDesiredEyeLookUp(
    this,
    dt,
    &eye,
    &desLook,
    (UFG::qVector3 *)&duration,
    1,
    &newEye,
    (UFG::qVector3 *)&result);
  ExtraWideAspectCorrectedFOV = (float)(this->mFov.p0 * 3.1415927) * 0.0055555557;
  if ( !Render::GetRenderFeatures()->mForceLetterBox )
    ExtraWideAspectCorrectedFOV = Render::GetExtraWideAspectCorrectedFOV(ExtraWideAspectCorrectedFOV);
  v446 = UFG::GameCameraComponent::ComputeNearOffset(
           this,
           &newEye,
           (UFG::qVector3 *)&result,
           ExtraWideAspectCorrectedFOV)
       + UFG::gCameraDefaultNear;
  DisplayAspectRatio = Render::GetDisplayAspectRatio();
  UFG::Camera::SetViewProjection(
    &this->mCamera,
    ExtraWideAspectCorrectedFOV,
    DisplayAspectRatio,
    v446,
    UFG::gCameraDefaultFar,
    0.0,
    0.0,
    1);
  if ( this->mAllowDesaturation )
    mDesaturation = this->mDesaturation;
  else
    mDesaturation = 0.0;
  mMotionblurMagnitude = this->mMotionblurMagnitude;
  this->mCamera.mDesaturation = mDesaturation;
  this->mCamera.mMotionBlur = mMotionblurMagnitude;
  v450 = UFG::qSignedMod(COERCE_DOUBLE((unsigned __int64)LODWORD(this->mDutch.mHomerCubic.p0)), this->mDutch.mModulo);
  UFG::Camera::ApplyDutch(&this->mCamera, v450 + UFG::GameCameraComponent::mDutchDyn.p0);
  v451 = (__m128)LODWORD(this->mFocusPos.y);
  v451.m128_f32[0] = (float)((float)((float)(v451.m128_f32[0] - eye.y) * (float)(v451.m128_f32[0] - eye.y))
                           + (float)((float)(this->mFocusPos.x - eye.x) * (float)(this->mFocusPos.x - eye.x)))
                   + (float)((float)(this->mFocusPos.z - eye.z) * (float)(this->mFocusPos.z - eye.z));
  LODWORD(this->mDofParameters.mFocalDistance) = _mm_sqrt_ps(v451).m128_u32[0];
  UFG::GameCameraComponent::UpdateDof(this, dt, &this->mDofParameters, 0);
}meCameraComponent::UpdateDof(this, dt, &this->mDofParameters, 0);
}

// File Line: 2487
// RVA: 0x3CE860
void __fastcall UFG::ChaseCameraComponent::TransitionFrom(
        UFG::ChaseCameraComponent *this,
        UFG::BaseCameraComponent *fromCamera,
        bool withVelocity)
{
  this->mTransitionParam = 1.0;
  this->mLookaroundAngle = 0.0;
  UFG::BaseCameraComponent::TransitionFrom(this, fromCamera, withVelocity);
  this->mFov.p1 = (float)(((float (__fastcall *)(UFG::BaseCameraComponent *))fromCamera->vfptr[19].__vecDelDtor)(fromCamera)
                        * 180.0)
                * 0.31830987;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[31].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[15].__vecDelDtor)(this);
}

// File Line: 2498
// RVA: 0x3CE8F0
void __fastcall UFG::ChaseCameraComponent::TransitionFromBlendOrientation(
        UFG::ChaseCameraComponent *this,
        UFG::BaseCameraComponent *fromCamera)
{
  float x; // xmm15_4
  float v5; // xmm10_4
  __m128 y_low; // xmm8
  float z; // xmm11_4
  __int128 v8; // xmm4
  __int128 z_low; // xmm7
  __m128 v10; // xmm3
  float v11; // xmm1_4
  float v12; // xmm14_4
  __m128 x_low; // xmm9
  float v14; // xmm13_4
  float v15; // xmm5_4
  __m128 v16; // xmm3
  float v17; // xmm1_4
  float v18; // xmm9_4
  float v19; // xmm13_4
  float v20; // xmm14_4
  __int128 v21; // xmm12
  float v22; // xmm13_4
  __m128 v23; // xmm3
  float v24; // xmm13_4
  __m128 v25; // xmm9
  float v26; // xmm1_4
  float v27; // xmm9_4
  __m128 v28; // xmm14
  float v29; // xmm3_4
  __m128 v30; // xmm4
  float v31; // xmm2_4
  float v32; // xmm0_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  UFG::qMatrix44 mat; // [rsp+20h] [rbp-E8h] BYREF
  float y; // [rsp+110h] [rbp+8h]
  float v44; // [rsp+118h] [rbp+10h]

  ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[14].__vecDelDtor)(this);
  z_low = LODWORD(fromCamera->mLookCurr.z);
  x = fromCamera->mLookCurr.x;
  v5 = fromCamera->mEyeCurr.x;
  y_low = (__m128)LODWORD(fromCamera->mEyeCurr.y);
  v8 = LODWORD(x);
  z = fromCamera->mEyeCurr.z;
  *(float *)&v8 = x - v5;
  y = fromCamera->mLookCurr.y;
  *(float *)&z_low = *(float *)&z_low - z;
  v10 = (__m128)LODWORD(y);
  v44 = fromCamera->mLookCurr.z;
  this->mTransitionFromEye.x = v5;
  v10.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(*(float *)&v8 * *(float *)&v8))
                  + (float)(*(float *)&z_low * *(float *)&z_low);
  LODWORD(this->mTransitionFromEye.y) = y_low.m128_i32[0];
  this->mTransitionFromEye.z = z;
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = fromCamera->mCamera.mTransformation.v1.y;
  x_low = (__m128)LODWORD(fromCamera->mCamera.mTransformation.v1.x);
  v14 = fromCamera->mCamera.mTransformation.v1.z;
  *(float *)&v8 = *(float *)&v8 * v11;
  v15 = y * v11;
  *(float *)&z_low = *(float *)&z_low * v11;
  mat.v0.w = 0.0;
  v16 = x_low;
  LODWORD(mat.v0.x) = v8;
  mat.v0.y = y * v11;
  LODWORD(mat.v0.z) = z_low;
  v16.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v12 * v12)) + (float)(v14 * v14);
  if ( v16.m128_f32[0] == 0.0 )
    v17 = 0.0;
  else
    v17 = 1.0 / _mm_sqrt_ps(v16).m128_f32[0];
  v18 = x_low.m128_f32[0] * v17;
  v19 = v14 * v17;
  v20 = v12 * v17;
  v21 = z_low;
  v23 = (__m128)v8;
  v23.m128_f32[0] = *(float *)&v8 * v19;
  *(float *)&v21 = (float)(*(float *)&z_low * v20) - (float)(v15 * v19);
  v22 = v15 * v18;
  v23.m128_f32[0] = v23.m128_f32[0] - (float)(*(float *)&z_low * v18);
  v25 = v23;
  v24 = v22 - (float)(*(float *)&v8 * v20);
  v25.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(*(float *)&v21 * *(float *)&v21))
                  + (float)(v24 * v24);
  if ( v25.m128_f32[0] == 0.0 )
    v26 = 0.0;
  else
    v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
  *(float *)&v21 = *(float *)&v21 * v26;
  mat.v1.w = 0.0;
  v28 = (__m128)v21;
  mat.v1.y = v23.m128_f32[0] * v26;
  mat.v1.z = v24 * v26;
  LODWORD(mat.v1.x) = v21;
  v27 = (float)((float)(v24 * v26) * v15) - (float)((float)(v23.m128_f32[0] * v26) * *(float *)&z_low);
  v28.m128_f32[0] = (float)(*(float *)&v21 * *(float *)&z_low) - (float)((float)(v24 * v26) * *(float *)&v8);
  v29 = (float)((float)(v23.m128_f32[0] * v26) * *(float *)&v8) - (float)(*(float *)&v21 * v15);
  v30 = v28;
  v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
  if ( v30.m128_f32[0] == 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
  mat.v3.x = v5;
  LODWORD(mat.v3.y) = y_low.m128_i32[0];
  mat.v3.z = z;
  mat.v2.w = 0.0;
  mat.v3.w = 1.0;
  mat.v2.x = v27 * v31;
  mat.v2.y = v28.m128_f32[0] * v31;
  mat.v2.z = v29 * v31;
  UFG::qQuaternion::Set(&this->mTransitionFromOri, &mat);
  this->mTransitionParamEye = 1.0;
  this->mTransitionParamOrient = 1.0;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - y) * (float)(y_low.m128_f32[0] - y))
                            + (float)((float)(v5 - x) * (float)(v5 - x)))
                    + (float)((float)(z - v44) * (float)(z - v44));
  LODWORD(this->mTransitionFromLen) = _mm_sqrt_ps(y_low).m128_u32[0];
  ((void (__fastcall *)(UFG::BaseCameraComponent *))fromCamera->vfptr[19].__vecDelDtor)(fromCamera);
  v32 = ((float (__fastcall *)(UFG::BaseCameraComponent *))fromCamera->vfptr[19].__vecDelDtor)(fromCamera);
  vfptr = fromCamera->vfptr;
  if ( v32 <= 3.1415927 )
    v32 = (float)(((float (__fastcall *)(UFG::BaseCameraComponent *))vfptr[19].__vecDelDtor)(fromCamera) * 180.0)
        * 0.31830987;
  else
    ((void (__fastcall *)(UFG::BaseCameraComponent *))vfptr[19].__vecDelDtor)(fromCamera);
  this->mFov.p1 = v32;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  this->mFov.p0 = this->mFov.p1;
  this->mFov.v0 = this->mFov.v1;
  UFG::HomerCubic<float>::MakeCoeffs(&this->mFov);
  this->mFov.mParameter = 0.0;
  ((void (__fastcall *)(UFG::ChaseCameraComponent *))this->vfptr[15].__vecDelDtor)(this);
  if ( this->mLookaroundAngle == 0.0 )
  {
    if ( !this->mLockEye )
    {
      v34 = this->mEyeVelocity.y;
      v35 = this->mEyeVelocity.z;
      this->mLockEyeVel.x = this->mEyeVelocity.x;
      this->mLockEyeVel.y = v34;
      this->mLockEyeVel.z = v35;
      v36 = this->mEyeCurr.y;
      v37 = this->mEyeCurr.z;
      this->mLockEyePos.x = this->mEyeCurr.x;
      this->mLockEyePos.y = v36;
      this->mLockEyePos.z = v37;
      this->mLockEyeParam = 0.0;
      this->mLockEye = 1;
      this->mUpdateEyeOffset = 0;
    }
    if ( this->mLookaroundAngle == 0.0 && !this->mLockLook )
    {
      v38 = this->mLookVelocity.y;
      v39 = this->mLookVelocity.z;
      this->mLockLookVel.x = this->mLookVelocity.x;
      this->mLockLookVel.y = v38;
      this->mLockLookVel.z = v39;
      v40 = this->mLookCurr.y;
      v41 = this->mLookCurr.z;
      this->mLockLookPos.x = this->mLookCurr.x;
      this->mLockLookPos.y = v40;
      this->mLockLookPos.z = v41;
      this->mLockLookParam = 0.0;
      this->mLockLook = 1;
    }
  }
}

