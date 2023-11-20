// File Line: 112
// RVA: 0x14BFE00
void dynamic_initializer_for__UFG::GameCameraComponent::mDofOverrideParams__()
{
  UFG::GameCameraComponent::mDofOverrideParams[0] = 0;
  byte_1423CF710 = 0;
}

// File Line: 113
// RVA: 0x3C3E80
const char *__fastcall UFG::GameCameraComponent::GetTypeName(UFG::GameCameraComponent *this)
{
  return "GameCameraComponent";
}

// File Line: 120
// RVA: 0x14BFD90
__int64 dynamic_initializer_for__UFG::GameCameraComponent::mDofFocusDist__()
{
  float v0; // xmm4_4

  v0 = UFG::trDofFocusDistanceDurationGrow;
  if ( UFG::trDofFocusDistanceDurationGrow <= 0.0099999998 )
    v0 = FLOAT_0_0099999998;
  UFG::GameCameraComponent::mDofFocusDist.mDuration = v0;
  if ( v0 <= 0.0099999998 )
    v0 = FLOAT_0_0099999998;
  UFG::GameCameraComponent::mDofFocusDist.A = (float)(v0 * 0.0) / (float)((float)(v0 * v0) * v0);
  UFG::GameCameraComponent::mDofFocusDist.B = COERCE_FLOAT(COERCE_UNSIGNED_INT(v0 * 0.0) ^ _xmm[0]) / (float)(v0 * v0);
  return atexit(dynamic_atexit_destructor_for__UFG::GameCameraComponent::mDofFocusDist__);
}

// File Line: 154
// RVA: 0x14BFE20
__int64 dynamic_initializer_for__UFG::GameCameraComponent::mDynamicDofParams__()
{
  `eh vector constructor iterator(
    &UFG::GameCameraComponent::mDynamicDofParams,
    0x4Cui64,
    6,
    (void (__fastcall *)(void *))UFG::GameCameraComponent::DynamicDofParam::DynamicDofParam);
  return atexit(dynamic_atexit_destructor_for__UFG::GameCameraComponent::mDynamicDofParams__);
}

// File Line: 155
// RVA: 0x14BFE10
__int64 dynamic_initializer_for__UFG::GameCameraComponent::mDutchDyn__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::GameCameraComponent::mDutchDyn__);
}

// File Line: 159
// RVA: 0x3BC3F0
void __fastcall UFG::GameCameraComponent::GameCameraComponent(UFG::GameCameraComponent *this, unsigned int name_uid)
{
  UFG::GameCameraComponent *v2; // rdi
  float *v3; // rsi
  signed int v4; // ebx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::allocator::free_link *v11; // rax
  UFG::ShapeCasterCollector *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::ShapeCasterCollector *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  __int64 v22; // rax
  float v23; // xmm8_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  __int64 v26; // rax
  float v27; // xmm7_4
  float v28; // xmm1_4
  float v29; // xmm1_4
  signed int v30; // esi
  char *v31; // r14
  char *v32; // rsi
  int v33; // [rsp+30h] [rbp-A8h]
  int v34; // [rsp+34h] [rbp-A4h]
  int v35; // [rsp+38h] [rbp-A0h]
  int v36; // [rsp+40h] [rbp-98h]
  int v37; // [rsp+44h] [rbp-94h]
  int v38; // [rsp+48h] [rbp-90h]
  int v39; // [rsp+50h] [rbp-88h]
  int v40; // [rsp+54h] [rbp-84h]
  int v41; // [rsp+58h] [rbp-80h]
  __int64 v42; // [rsp+60h] [rbp-78h]
  char dest; // [rsp+70h] [rbp-68h]
  char v44; // [rsp+548h] [rbp+470h]
  UFG::allocator::free_link *v45; // [rsp+AB8h] [rbp+9E0h]

  v42 = -2i64;
  v2 = this;
  UFG::BaseCameraComponent::BaseCameraComponent((UFG::BaseCameraComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameCameraComponent::`vftable;
  v3 = &v2->mDofNoise.tDecay;
  UFG::qNoise<float,float>::qNoise<float,float>(&v2->mDofNoise);
  v2->mEyeImpactNoise.bCircular = 0;
  v39 = 1065353216;
  v40 = 1065353216;
  v41 = 1065353216;
  v33 = -1082130432;
  v34 = -1082130432;
  v35 = -1082130432;
  v36 = 1056964608;
  v37 = 1056964608;
  v38 = 1056964608;
  UFG::qNoise<UFG::qVector3,float>::SetParameters(
    &v2->mEyeImpactNoise,
    6,
    1.0,
    (UFG::qVector3 *)&v36,
    (UFG::qVector3 *)&v33,
    (UFG::qVector3 *)&v39);
  UFG::qNoise<UFG::qVector3,float>::qNoise<UFG::qVector3,float>(&v2->mLookImpactNoise);
  v2->cAimWobbleRadius.mDuration = 0.0099999998;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::GameCameraComponent::_GameCameraComponentTypeUID,
    "GameCameraComponent");
  v2->mResetNext = -1;
  *(_WORD *)&v2->mInCollision = 0;
  v4 = 0;
  v2->mPushInOverrideRate = 0.0;
  v5 = UFG::qVector3::msAxisZ.y;
  v6 = UFG::qVector3::msAxisZ.z;
  v2->mCollisionSurfaceNormal.x = UFG::qVector3::msAxisZ.x;
  v2->mCollisionSurfaceNormal.y = v5;
  v2->mCollisionSurfaceNormal.z = v6;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  v2->mCollisionContactPosition.x = UFG::qVector3::msZero.x;
  v2->mCollisionContactPosition.y = v7;
  v2->mCollisionContactPosition.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v2->mCollisionLookOffset.x = UFG::qVector3::msZero.x;
  v2->mCollisionLookOffset.y = v9;
  v2->mCollisionLookOffset.z = v10;
  *(_QWORD *)&v2->mSafeRadius = 1065353216i64;
  v2->mCollisionBlend = 0.69999999;
  *(_QWORD *)&v2->mCollisionPlateau = 1060320051i64;
  UFG::qMemSet(v2->mCollisionTargetPoints, 0, 4u);
  v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
  v45 = v11;
  if ( v11 )
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)v11,
      UFG::trCollisionTargetPointCastingRadius,
      0x12u,
      0);
  else
    v12 = 0i64;
  v2->pCollisionCollectorTargetPoints = v12;
  v13 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
  v45 = v13;
  if ( v13 )
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)v13,
      UFG::trCollisionCastingRadius,
      0x12u,
      0);
  else
    v14 = 0i64;
  v2->pCollisionCollector = v14;
  v2->mCollisionTargetPointCastingRadiusSubmitted = UFG::trCollisionTargetPointCastingRadius;
  v2->mCollisionCastingRadiusSubmitted = UFG::trCollisionCastingRadius;
  v2->mAlternateLookValid = 0;
  v15 = UFG::qVector3::msZero.y;
  v16 = UFG::qVector3::msZero.z;
  v2->mAlternateLook.x = UFG::qVector3::msZero.x;
  v2->mAlternateLook.y = v15;
  v2->mAlternateLook.z = v16;
  v2->mEyePushValid = 0;
  *(_QWORD *)&v2->mEyePushPercent = 0i64;
  v2->mAllowCanOccludeCamera = 1;
  v17 = UFG::qVector3::msZero.y;
  v18 = UFG::qVector3::msZero.z;
  v2->mCandidateEye.x = UFG::qVector3::msZero.x;
  v2->mCandidateEye.y = v17;
  v2->mCandidateEye.z = v18;
  v2->pSimObjectPassThru1 = 0i64;
  v2->pSimObjectPassThru2 = 0i64;
  *(_QWORD *)&v2->mDofNoiseTimer = 0i64;
  v2->mDofNoiseAmplitudeDecay = 2.0;
  v2->mDofNoise.tRangeMin = -1.0;
  v2->mDofNoise.tRangeMax = 1.0;
  v19 = 0.0;
  v20 = 0.0;
  v21 = *(float *)&FLOAT_1_0;
  v22 = (unsigned int)v2->mDofNoise.nOctaves;
  if ( (signed int)v22 > 0 )
  {
    do
    {
      v20 = v20 + v21;
      v21 = v21 * *v3;
      --v22;
    }
    while ( v22 );
  }
  v2->mDofNoise.tAmplitude = 1.0 / v20;
  v23 = FLOAT_0_000099999997;
  if ( COERCE_FLOAT((unsigned int)FLOAT_1_0 & _xmm) <= 0.000099999997 )
    v24 = FLOAT_0_000099999997;
  else
    LODWORD(v24) = (unsigned int)FLOAT_1_0 & _xmm;
  v2->mDofNoise.tOffset = (float)((float)(1.0 / v24) * v2->mDofNoise.tFrequency) * v2->mDofNoise.tOffset;
  LODWORD(v2->mDofNoise.tFrequency) = (unsigned int)FLOAT_1_0 & _xmm;
  v25 = *(float *)&FLOAT_1_0;
  v26 = (unsigned int)v2->mDofNoise.nOctaves;
  if ( (signed int)v26 > 0 )
  {
    do
    {
      v19 = v19 + v25;
      v25 = v25 * *v3;
      --v26;
    }
    while ( v26 );
  }
  v2->mDofNoise.tAmplitude = 1.0 / v19;
  LODWORD(v27) = LODWORD(FLOAT_15_0) & _xmm;
  if ( COERCE_FLOAT(LODWORD(FLOAT_15_0) & _xmm) <= 0.000099999997 )
    v28 = FLOAT_0_000099999997;
  else
    LODWORD(v28) = LODWORD(FLOAT_15_0) & _xmm;
  v2->mEyeImpactNoise.tOffset = (float)((float)(1.0 / v28) * v2->mEyeImpactNoise.tFrequency)
                              * v2->mEyeImpactNoise.tOffset;
  v2->mEyeImpactNoise.tFrequency = v27;
  UFG::qNoise<UFG::qVector3,float>::Init(&v2->mEyeImpactNoise);
  if ( v27 > 0.000099999997 )
    LODWORD(v23) = LODWORD(FLOAT_15_0) & _xmm;
  v2->mLookImpactNoise.tOffset = (float)((float)(1.0 / v23) * v2->mLookImpactNoise.tFrequency)
                               * v2->mLookImpactNoise.tOffset;
  v2->mLookImpactNoise.tFrequency = v27;
  UFG::qNoise<UFG::qVector3,float>::Init(&v2->mLookImpactNoise);
  v36 = 1045220557;
  v37 = 1045220557;
  v38 = 1045220557;
  v33 = -1102263091;
  v34 = -1102263091;
  v35 = -1102263091;
  UFG::qNoise<UFG::qVector3,float>::SetRange(&v2->mEyeImpactNoise, (UFG::qVector3 *)&v33, (UFG::qVector3 *)&v36);
  v36 = 1036831949;
  v37 = 1036831949;
  v38 = 1036831949;
  v33 = -1110651699;
  v34 = -1110651699;
  v35 = -1110651699;
  UFG::qNoise<UFG::qVector3,float>::SetRange(&v2->mLookImpactNoise, (UFG::qVector3 *)&v33, (UFG::qVector3 *)&v36);
  v29 = UFG::qVector2::msZero.y;
  v2->mAimWobble.x = UFG::qVector2::msZero.x;
  v2->mAimWobble.y = v29;
  *(_QWORD *)&v2->cAimWobbleRadius.mDuration = 1065353216i64;
  *(_QWORD *)&v2->cAimWobbleRadius.v0 = 0i64;
  *(_QWORD *)&v2->cAimWobbleRadius.p0 = 0i64;
  UFG::HomerCubic<float>::MakeCoeffs(&v2->cAimWobbleRadius);
  UFG::GameCameraComponent::ResetAimWobble(v2);
  *(_QWORD *)&v2->mImpactShakeSeed = 0i64;
  v2->mImpactShakeAmplitude = 0.0;
  v2->mImpactShakeAmplitudeDecay = 8.0;
  *(_QWORD *)&UFG::GameCameraComponent::mDynamicDofParams.mDuration = 1065353216i64;
  *(_QWORD *)&UFG::GameCameraComponent::mDynamicDofParams.v0 = 0i64;
  UFG::GameCameraComponent::mDynamicDofParams.p0 = 5.0;
  UFG::GameCameraComponent::mDynamicDofParams.p1 = 5.0;
  UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDynamicDofParams);
  qword_1423D7C88 = 1065353216i64;
  xmmword_1423D7C90 = _xmm;
  byte_1423D7CA0 = 0;
  qword_1423D7CA4 = 1065353216i64;
  *(_QWORD *)&stru_1423D7CAC.mDuration = 1065353216i64;
  *(_QWORD *)&stru_1423D7CAC.v0 = 0i64;
  stru_1423D7CAC.p0 = 100.0;
  stru_1423D7CAC.p1 = 100.0;
  UFG::HomerCubic<float>::MakeCoeffs(&stru_1423D7CAC);
  qword_1423D7CD4 = 1065353216i64;
  qword_1423D7CDC = 1120403456i64;
  dword_1423D7CE4 = 0;
  dword_1423D7CE8 = 1120403456;
  byte_1423D7CEC = 0;
  unk_1423D7CF0 = _xmm;
  *(_QWORD *)&stru_1423D7CF8.v0 = 0i64;
  *(_QWORD *)&stru_1423D7CF8.p0 = 0i64;
  UFG::HomerCubic<float>::MakeCoeffs(&stru_1423D7CF8);
  xmmword_1423D7D20 = _xmm;
  qword_1423D7D30 = 0i64;
  byte_1423D7D38 = 0;
  qword_1423D7D3C = 1065353216i64;
  *(_QWORD *)&stru_1423D7D44.mDuration = 1065353216i64;
  *(_QWORD *)&stru_1423D7D44.v0 = 0i64;
  *(_QWORD *)&stru_1423D7D44.p0 = 0i64;
  UFG::HomerCubic<float>::MakeCoeffs(&stru_1423D7D44);
  dword_1423D7D6C = 1065353216;
  xmmword_1423D7D70 = 0i64;
  dword_1423D7D80 = 0;
  byte_1423D7D84 = 0;
  qword_1423D7D88 = 1065353216i64;
  *(_QWORD *)&stru_1423D7D90.mDuration = 1065353216i64;
  *(_QWORD *)&stru_1423D7D90.v0 = 0i64;
  stru_1423D7D90.p0 = 5.0;
  stru_1423D7D90.p1 = 5.0;
  UFG::HomerCubic<float>::MakeCoeffs(&stru_1423D7D90);
  qword_1423D7DB8 = 1065353216i64;
  xmmword_1423D7DC0 = _xmm;
  byte_1423D7DD0 = 0;
  qword_1423D7DD4 = 1065353216i64;
  *(_QWORD *)&stru_1423D7DDC.mDuration = 1065353216i64;
  *(_QWORD *)&stru_1423D7DDC.v0 = 0i64;
  stru_1423D7DDC.p0 = 5.0;
  stru_1423D7DDC.p1 = 5.0;
  UFG::HomerCubic<float>::MakeCoeffs(&stru_1423D7DDC);
  qword_1423D7E04 = 1065353216i64;
  qword_1423D7E0C = 1084227584i64;
  dword_1423D7E14 = 0;
  dword_1423D7E18 = 1084227584;
  byte_1423D7E1C = 0;
  qword_1423D7E20 = 1065353216i64;
  UFG::GameCameraComponent::ResetDutch(1);
  v30 = 0;
  v31 = &dest;
  do
  {
    UFG::qSPrintf(v31, "\\Camera\\Damage FX\\Damage %d", (unsigned int)v30++);
    v31 += 256;
  }
  while ( v30 < 5 );
  v32 = &v44;
  do
  {
    UFG::qSPrintf(v32, "\\Camera\\Damage FX\\DOF Noise %d", (unsigned int)v4++);
    v32 += 256;
  }
  while ( v4 < 5 );
}

// File Line: 320
// RVA: 0x3BDEC0
void __fastcall UFG::GameCameraComponent::~GameCameraComponent(UFG::GameCameraComponent *this)
{
  UFG::GameCameraComponent *v1; // rbx
  UFG::ShapeCasterCollector *v2; // rcx
  UFG::ShapeCasterCollector *v3; // rcx
  UFG::BaseCameraComponent *v4; // rcx
  UFG::Director *v5; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameCameraComponent::`vftable;
  if ( this->mActive )
    this->mActive = 0;
  v2 = this->pCollisionCollector;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v3 = v1->pCollisionCollectorTargetPoints;
  if ( v3 )
    v3->vfptr->__vecDelDtor(v3, 1u);
  v4 = UFG::Director::Get()->mCurrentCamera;
  if ( v4 )
    v4 = (UFG::BaseCameraComponent *)((char *)v4 + 80);
  if ( v4 == (UFG::BaseCameraComponent *)&v1->mCamera )
  {
    v5 = UFG::Director::Get();
    UFG::Director::SetCurrentCamera(v5, 0i64);
  }
  UFG::BaseCameraComponent::~BaseCameraComponent((UFG::BaseCameraComponent *)&v1->vfptr);
}

// File Line: 343
// RVA: 0x3C89C0
void __fastcall UFG::GameCameraComponent::Reset(UFG::GameCameraComponent *this)
{
  float v1; // xmm2_4
  float v2; // xmm0_4

  this->mAllowCanOccludeCamera = 1;
  v1 = UFG::qVector3::msZero.z;
  v2 = UFG::qVector3::msZero.x;
  this->mCollisionLookOffset.y = UFG::qVector3::msZero.y;
  this->mCollisionLookOffset.z = v1;
  this->mCollisionLookOffset.x = v2;
  UFG::BaseCameraComponent::Reset((UFG::BaseCameraComponent *)&this->vfptr);
}

// File Line: 351
// RVA: 0x3C9790
void __fastcall UFG::GameCameraComponent::SetActive(UFG::GameCameraComponent *this, bool active)
{
  if ( this->mActive != active )
    this->mActive = active;
}

// File Line: 358
// RVA: 0x3C9F80
void __fastcall UFG::GameCameraComponent::SetCollisionIgnoreCharacters(bool enable)
{
  UFG::GameCameraComponent::mCollisionIgnoreAllCharacters = enable;
}

// File Line: 364
// RVA: 0x3C9F90
void __fastcall UFG::GameCameraComponent::SetCollisionIgnoreVehicles(bool enable)
{
  UFG::GameCameraComponent::mCollisionIgnoreAllVehicles = enable;
}

// File Line: 386
// RVA: 0x3C8A00
void __fastcall UFG::GameCameraComponent::ResetAimWobble(UFG::GameCameraComponent *this)
{
  UFG::HomerCubic<float> *v1; // rbx
  float v2; // xmm0_4
  float v3; // xmm1_4

  this->rAimWobbleRadiusMin = 0.0020000001;
  this->rAimWobbleRadiusMax = 0.003;
  this->rAimWobbleRadiusPeriod = 5.5;
  this->rAimWobbleFreq = 2.2;
  this->rAimWobbleAxisWeight = 0.27500001;
  *(_WORD *)&this->bAimWobbleHoldingBreathInput = 0;
  this->rAimWobbleHoldBreathMultiplier = 1.0;
  v1 = &this->cAimWobbleRadius;
  *(_QWORD *)&this->rAimWobbleOverallScale = 0i64;
  *(_QWORD *)&this->rAimWobbleHoldBreathElapsedTime = 0i64;
  v2 = this->cAimWobbleRadius.mParameter / this->cAimWobbleRadius.mDuration;
  this->cAimWobbleRadius.mParameter = v2;
  v3 = this->rAimWobbleRadiusPeriod;
  if ( v3 <= 0.0099999998 )
    v3 = FLOAT_0_0099999998;
  v1->mDuration = v3;
  this->cAimWobbleRadius.mParameter = v3 * v2;
  UFG::HomerCubic<float>::MakeCoeffs(&this->cAimWobbleRadius);
  v1->p1 = 0.0;
  UFG::HomerCubic<float>::MakeCoeffs(v1);
  v1->mParameter = 0.0;
  v1->p0 = v1->p1;
  v1->v0 = v1->v1;
  UFG::HomerCubic<float>::MakeCoeffs(v1);
  v1->mParameter = 0.0;
}

// File Line: 408
// RVA: 0x3D5E00
void __fastcall UFG::GameCameraComponent::Update(UFG::GameCameraComponent *this, float delta_seconds)
{
  UFG::GameCameraComponent *v2; // rbx
  float v3; // xmm2_4
  float v4; // xmm2_4
  float v5; // xmm9_4
  UFG::ShapeCasterCollector *v6; // rdi
  UFG::ShapeCasterCollector *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::ShapeCasterCollector *v9; // rax
  UFG::ShapeCasterCollector *v10; // rcx
  UFG::allocator::free_link *v11; // rax
  UFG::ShapeCasterCollector *v12; // rax
  float v13; // xmm15_4
  float v14; // xmm13_4
  float v15; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm11_4
  float v18; // xmm12_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm14_4
  float v24; // xmm2_4
  float v25; // xmm9_4
  float v26; // xmm0_4
  float v27; // xmm6_4
  float v28; // xmm3_4
  float v29; // [rsp+F0h] [rbp+8h]
  float v30; // [rsp+100h] [rbp+18h]

  v2 = this;
  UFG::BaseCameraComponent::Update((UFG::BaseCameraComponent *)&this->vfptr, delta_seconds);
  v3 = 1.0 - (float)(delta_seconds * v2->mImpactShakeAmplitudeDecay);
  if ( v3 < 0.0 )
    v3 = 0.0;
  v4 = v3 * v2->mImpactShakeAmplitude;
  v2->mImpactShakeAmplitude = v4;
  v5 = FLOAT_0_0099999998;
  if ( v4 > 0.0099999998 )
    v2->mImpactShakeTimer = delta_seconds + v2->mImpactShakeTimer;
  UFG::GameCameraComponent::mNoRotationTimer = UFG::GameCameraComponent::mNoRotationTimer - delta_seconds;
  if ( UFG::GameCameraComponent::mNoRotationTimer < 0.0 )
    UFG::GameCameraComponent::mNoRotationTimer = 0.0;
  UFG::GameCameraComponent::UpdateAimWobble(v2, delta_seconds);
  v6 = 0i64;
  if ( UFG::trCollisionTargetPointCastingRadius != v2->mCollisionTargetPointCastingRadiusSubmitted )
  {
    v7 = v2->pCollisionCollectorTargetPoints;
    if ( v7 )
      v7->vfptr->__vecDelDtor(v7, 1u);
    v8 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
    if ( v8 )
      UFG::ShapeCasterCollector::ShapeCasterCollector(
        (UFG::ShapeCasterCollector *)v8,
        UFG::trCollisionTargetPointCastingRadius,
        0x12u,
        0);
    else
      v9 = 0i64;
    v2->pCollisionCollectorTargetPoints = v9;
    v2->mCollisionTargetPointCastingRadiusSubmitted = UFG::trCollisionTargetPointCastingRadius;
  }
  if ( UFG::trCollisionCastingRadius != v2->mCollisionCastingRadiusSubmitted )
  {
    v10 = v2->pCollisionCollector;
    if ( v10 )
      v10->vfptr->__vecDelDtor(v10, 1u);
    v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
    if ( v11 )
    {
      UFG::ShapeCasterCollector::ShapeCasterCollector(
        (UFG::ShapeCasterCollector *)v11,
        UFG::trCollisionCastingRadius,
        0x12u,
        0);
      v6 = v12;
    }
    v2->pCollisionCollector = v6;
    v2->mCollisionCastingRadiusSubmitted = UFG::trCollisionCastingRadius;
  }
  v13 = UFG::GameCameraComponent::mDynamicDutchDurHigh;
  v14 = UFG::GameCameraComponent::mDynamicDutchDurDevHigh;
  v15 = UFG::GameCameraComponent::mDynamicDutchValHigh;
  v16 = UFG::GameCameraComponent::mDynamicDutchValDevHigh;
  v29 = UFG::GameCameraComponent::mDynamicDutchDurLow;
  v30 = UFG::GameCameraComponent::mDynamicDutchDurDevLow;
  v17 = UFG::GameCameraComponent::mDynamicDutchValLow;
  v18 = UFG::GameCameraComponent::mDynamicDutchValDevLow;
  if ( UFG::GameCameraComponent::mDynamicDutchTweak )
  {
    v13 = UFG::GameCameraComponent::mDynamicDutchTweakDurHigh;
    v14 = UFG::GameCameraComponent::mDynamicDutchTweakDurDevHigh;
    v15 = (float)(UFG::GameCameraComponent::mDynamicDutchTweakValHigh * 3.1415927) * 0.0055555557;
    v16 = (float)(UFG::GameCameraComponent::mDynamicDutchTweakValDevHigh * 3.1415927) * 0.0055555557;
    v29 = UFG::GameCameraComponent::mDynamicDutchTweakDurLow;
    v30 = UFG::GameCameraComponent::mDynamicDutchTweakDurDevLow;
    v17 = (float)(UFG::GameCameraComponent::mDynamicDutchTweakValLow * 3.1415927) * 0.0055555557;
    v18 = (float)(UFG::GameCameraComponent::mDynamicDutchTweakValDevLow * 3.1415927) * 0.0055555557;
  }
  if ( UFG::GameCameraComponent::mDynamicDutch )
  {
    v19 = UFG::GameCameraComponent::mDutchDyn.mParameter / UFG::GameCameraComponent::mDutchDyn.mDuration;
    v20 = UFG::GameCameraComponent::mDynamicDutchTransitionDuration;
    if ( UFG::GameCameraComponent::mDynamicDutchTransitionDuration <= 0.0099999998 )
      v20 = FLOAT_0_0099999998;
    UFG::GameCameraComponent::mDutchDyn.mDuration = v20;
    v21 = v19 * v20;
    UFG::GameCameraComponent::mDutchDyn.mParameter = v21;
    if ( v20 > 0.0099999998 )
      v5 = v20;
    v22 = (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.v1 + UFG::GameCameraComponent::mDutchDyn.v0) * v5)
                + (float)((float)(UFG::GameCameraComponent::mDutchDyn.p0 - UFG::GameCameraComponent::mDutchDyn.p1) * 2.0))
        / (float)((float)(v5 * v5) * v5);
    UFG::GameCameraComponent::mDutchDyn.A = (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.v1
                                                                  + UFG::GameCameraComponent::mDutchDyn.v0)
                                                          * v5)
                                                  + (float)((float)(UFG::GameCameraComponent::mDutchDyn.p0
                                                                  - UFG::GameCameraComponent::mDutchDyn.p1)
                                                          * 2.0))
                                          / (float)((float)(v5 * v5) * v5);
    v23 = (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.p1 - UFG::GameCameraComponent::mDutchDyn.p0) * 3.0)
                - (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.v0 * 2.0)
                                + UFG::GameCameraComponent::mDutchDyn.v1)
                        * v5))
        / (float)(v5 * v5);
    UFG::GameCameraComponent::mDutchDyn.B = (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.p1
                                                                  - UFG::GameCameraComponent::mDutchDyn.p0)
                                                          * 3.0)
                                                  - (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.v0 * 2.0)
                                                                  + UFG::GameCameraComponent::mDutchDyn.v1)
                                                          * v5))
                                          / (float)(v5 * v5);
    v24 = UFG::GameCameraComponent::mDutchDyn.v0;
    UFG::GameCameraComponent::mDutchDyn.C = UFG::GameCameraComponent::mDutchDyn.v0;
    UFG::GameCameraComponent::mDutchDyn.D = UFG::GameCameraComponent::mDutchDyn.p0;
    UFG::GameCameraComponent::mDynamicDutchCurElapsed = UFG::GameCameraComponent::mDynamicDutchCurElapsed
                                                      + delta_seconds;
    if ( UFG::GameCameraComponent::mDynamicDutchCurElapsed <= UFG::GameCameraComponent::mDynamicDutchCurDuration )
    {
      v25 = FLOAT_2_0;
      v27 = UFG::GameCameraComponent::mDutchDyn.p0;
    }
    else
    {
      UFG::GameCameraComponent::mDynamicDutchCurIsHigh = UFG::GameCameraComponent::mDynamicDutchCurIsHigh == 0;
      if ( !UFG::GameCameraComponent::mDynamicDutchCurIsHigh )
      {
        v13 = v29;
        v14 = v30;
      }
      v25 = FLOAT_2_0;
      v26 = UFG::qRandom(v14 * 2.0, &UFG::qDefaultSeed);
      UFG::GameCameraComponent::mDynamicDutchCurElapsed = 0.0;
      UFG::GameCameraComponent::mDynamicDutchCurDuration = (float)(v26 - v14) + v13;
      if ( !UFG::GameCameraComponent::mDynamicDutchCurIsHigh )
      {
        v15 = v17;
        v16 = v18;
      }
      UFG::GameCameraComponent::mDutchDyn.p1 = (float)(UFG::qRandom(v16 * 2.0, &UFG::qDefaultSeed) - v16) + v15;
      UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDutchDyn);
      v21 = 0.0;
      v27 = UFG::GameCameraComponent::mDutchDyn.D;
      v24 = UFG::GameCameraComponent::mDutchDyn.C;
      v23 = UFG::GameCameraComponent::mDutchDyn.B;
      v22 = UFG::GameCameraComponent::mDutchDyn.A;
      v20 = UFG::GameCameraComponent::mDutchDyn.mDuration;
    }
    v28 = v21 + delta_seconds;
    if ( v28 <= 0.0 )
      v28 = 0.0;
    if ( v28 >= v20 )
      v28 = v20;
    UFG::GameCameraComponent::mDutchDyn.mParameter = v28;
    UFG::GameCameraComponent::mDutchDyn.v0 = (float)((float)((float)((float)(v22 * 3.0) * v28) + (float)(v23 * v25))
                                                   * v28)
                                           + v24;
    UFG::GameCameraComponent::mDutchDyn.p0 = (float)((float)((float)((float)((float)(v22 * v28) + v23) * v28) + v24)
                                                   * v28)
                                           + v27;
  }
}

// File Line: 486
// RVA: 0x3C8D20
void __fastcall UFG::GameCameraComponent::ResetDutch(bool snap)
{
  UFG::GameCameraComponent::mDynamicDutch = 0;
  UFG::GameCameraComponent::mDynamicDutchDurHigh = 1.0;
  UFG::GameCameraComponent::mDynamicDutchDurDevHigh = 0.0;
  UFG::GameCameraComponent::mDynamicDutchValHigh = 0.0;
  UFG::GameCameraComponent::mDynamicDutchValDevHigh = 0.0;
  UFG::GameCameraComponent::mDynamicDutchDurLow = 1.0;
  UFG::GameCameraComponent::mDynamicDutchDurDevLow = 0.0;
  UFG::GameCameraComponent::mDynamicDutchValLow = 0.0;
  UFG::GameCameraComponent::mDynamicDutchValDevLow = 0.0;
  UFG::GameCameraComponent::mDynamicDutchCurIsHigh = 0;
  UFG::GameCameraComponent::mDynamicDutchCurDuration = 1.0;
  UFG::GameCameraComponent::mDynamicDutchCurElapsed = 0.0;
  if ( snap )
  {
    *(_QWORD *)&UFG::GameCameraComponent::mDutchDyn.mDuration = 1065353216i64;
    *(_QWORD *)&UFG::GameCameraComponent::mDutchDyn.v0 = 0i64;
    *(_QWORD *)&UFG::GameCameraComponent::mDutchDyn.p0 = 0i64;
    *(_QWORD *)&UFG::GameCameraComponent::mDutchDyn.A = 0i64;
    *(_QWORD *)&UFG::GameCameraComponent::mDutchDyn.C = 0i64;
  }
  else
  {
    UFG::GameCameraComponent::mDutchDyn.p1 = 0.0;
    UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDutchDyn);
    UFG::GameCameraComponent::mDutchDyn.mParameter = 0.0;
  }
}

// File Line: 506
// RVA: 0x3CC280
void __fastcall UFG::GameCameraComponent::SetDutch(float angle, bool snap)
{
  bool v2; // bl

  v2 = snap;
  UFG::GameCameraComponent::mDynamicDutch = 0;
  UFG::GameCameraComponent::mDutchDyn.p1 = angle;
  UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDutchDyn);
  UFG::GameCameraComponent::mDutchDyn.mParameter = 0.0;
  if ( v2 )
  {
    UFG::GameCameraComponent::mDutchDyn.p0 = UFG::GameCameraComponent::mDutchDyn.p1;
    UFG::GameCameraComponent::mDutchDyn.v0 = UFG::GameCameraComponent::mDutchDyn.v1;
    UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDutchDyn);
    UFG::GameCameraComponent::mDutchDyn.mParameter = 0.0;
  }
  UFG::GameCameraComponent::mDynamicDutchValHigh = angle;
  UFG::GameCameraComponent::mDynamicDutchValLow = angle;
  UFG::GameCameraComponent::mDynamicDutchDurDevHigh = 0.0;
  UFG::GameCameraComponent::mDynamicDutchValDevHigh = 0.0;
  UFG::GameCameraComponent::mDynamicDutchDurLow = 0.0;
  UFG::GameCameraComponent::mDynamicDutchDurDevLow = 0.0;
  UFG::GameCameraComponent::mDynamicDutchValDevLow = 0.0;
  LODWORD(UFG::GameCameraComponent::mDynamicDutchDurHigh) = (_DWORD)FLOAT_1_0;
}

// File Line: 528
// RVA: 0x3CC3A0
void __fastcall UFG::GameCameraComponent::SetDynamicDutch(float dur_high, float dur_dev_high, float ang_high, float ang_dev_high, float dur_low, float dur_dev_low, float ang_low, float ang_dev_low)
{
  UFG::GameCameraComponent::mDynamicDutchDurHigh = dur_high;
  UFG::GameCameraComponent::mDynamicDutchDurDevHigh = dur_dev_high;
  UFG::GameCameraComponent::mDynamicDutch = 1;
  UFG::GameCameraComponent::mDynamicDutchDurLow = dur_low;
  UFG::GameCameraComponent::mDynamicDutchDurDevLow = dur_dev_low;
  UFG::GameCameraComponent::mDynamicDutchValLow = ang_low;
  UFG::GameCameraComponent::mDynamicDutchValDevLow = ang_dev_low;
  UFG::GameCameraComponent::mDynamicDutchValHigh = ang_high;
  UFG::GameCameraComponent::mDynamicDutchValDevHigh = ang_dev_high;
}

// File Line: 542
// RVA: 0x3CCBD0
void __fastcall UFG::GameCameraComponent::SetHoldingBreathInput(UFG::GameCameraComponent *this, bool enable)
{
  bool v2; // al
  float v3; // xmm1_4
  float v4; // xmm1_4

  v2 = this->bAimWobbleHoldingBreathInput;
  if ( enable != v2 )
  {
    if ( !enable || UFG::rtAimWobbleBreathRequiredTime >= this->rAimWobbleBreathElapsedTime || v2 )
    {
      if ( this->bAimWobbleHoldingBreath )
      {
        v3 = this->rAimWobbleHoldBreathElapsedTime;
        this->bAimWobbleHoldingBreath = 0;
        v4 = v3 / UFG::rtAimWobbleHoldBreathMaxTime;
        if ( v4 <= 0.0 )
        {
          v4 = 0.0;
        }
        else if ( v4 >= 1.0 )
        {
          v4 = *(float *)&FLOAT_1_0;
        }
        this->rAimWobbleHoldBreathMultiplier = (float)((float)(UFG::rtAimWobbleMaxBreathMultiplier - 1.0) * v4) + 1.0;
      }
      this->bAimWobbleHoldingBreathInput = enable;
    }
    else
    {
      this->bAimWobbleHoldingBreath = 1;
      this->bAimWobbleHoldingBreathInput = enable;
    }
  }
}

// File Line: 565
// RVA: 0x3D8210
void __fastcall UFG::GameCameraComponent::UpdateAimWobble(UFG::GameCameraComponent *this, float dt)
{
  bool v2; // zf
  UFG::GameCameraComponent *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float *v11; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm11_4
  float v17; // xmm10_4
  float v18; // xmm10_4
  float v19; // xmm6_4
  float v20; // xmm8_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4

  v2 = this->bAimWobbleHoldingBreath == 0;
  v3 = this;
  this->rAimWobbleElapsedTime = dt + this->rAimWobbleElapsedTime;
  v4 = dt;
  if ( v2 )
  {
    v6 = dt + this->rAimWobbleBreathElapsedTime;
    this->rAimWobbleHoldBreathElapsedTime = 0.0;
    this->rAimWobbleBreathElapsedTime = v6;
  }
  else
  {
    v5 = dt + this->rAimWobbleHoldBreathElapsedTime;
    this->rAimWobbleBreathElapsedTime = 0.0;
    this->rAimWobbleHoldBreathElapsedTime = v5;
  }
  v7 = this->rAimWobbleHoldBreathElapsedTime;
  v8 = 0.0;
  if ( v7 > UFG::rtAimWobbleHoldBreathMaxTime )
  {
    this->bAimWobbleHoldingBreath = 0;
    v9 = v7 / UFG::rtAimWobbleHoldBreathMaxTime;
    if ( v9 <= 0.0 )
    {
      v9 = 0.0;
    }
    else if ( v9 >= 1.0 )
    {
      v9 = *(float *)&FLOAT_1_0;
    }
    this->rAimWobbleHoldBreathMultiplier = (float)((float)(UFG::rtAimWobbleMaxBreathMultiplier - 1.0) * v9) + 1.0;
  }
  UFG::qApproach(&this->rAimWobbleHoldBreathMultiplier, 1.0, UFG::rtAimWobbleMaxBreathDecayRate, v4);
  if ( v3->bAimWobbleHoldingBreath )
  {
    v10 = UFG::trAimWobbleHoldBreathRate;
  }
  else
  {
    v10 = UFG::trAimWobbleReleaseBreathRate;
    v8 = *(float *)&FLOAT_1_0;
  }
  UFG::qApproach(&v3->rAimWobbleOverallScale, v8, v10, v4);
  v11 = &UFG::trAimWobbleRadiusPeriod;
  if ( !UFG::tbAimWobbleUseTweakables )
    v11 = &v3->rAimWobbleRadiusPeriod;
  v12 = v3->cAimWobbleRadius.mParameter / v3->cAimWobbleRadius.mDuration;
  v3->cAimWobbleRadius.mParameter = v12;
  v13 = *v11;
  if ( *v11 <= 0.0099999998 )
    v13 = FLOAT_0_0099999998;
  v3->cAimWobbleRadius.mDuration = v13;
  v3->cAimWobbleRadius.mParameter = v13 * v12;
  UFG::HomerCubic<float>::MakeCoeffs(&v3->cAimWobbleRadius);
  UFG::HomerCubic<float>::Update(&v3->cAimWobbleRadius, v4);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v3->cAimWobbleRadius.p1 - v3->cAimWobbleRadius.p0) & _xmm) < 0.0000099999997 )
  {
    if ( UFG::tbAimWobbleUseTweakables )
    {
      v14 = UFG::trAimWobbleRadiusMin;
      v15 = UFG::trAimWobbleRadiusMax;
    }
    else
    {
      v14 = v3->rAimWobbleRadiusMin;
      v15 = v3->rAimWobbleRadiusMax;
    }
    v3->cAimWobbleRadius.p1 = UFG::qRandom(v15 - v14, &UFG::qDefaultSeed) + v14;
    UFG::HomerCubic<float>::MakeCoeffs(&v3->cAimWobbleRadius);
    v3->cAimWobbleRadius.mParameter = 0.0;
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::GameCameraComponent *))v3->vfptr[37].__vecDelDtor)(v3) )
  {
    if ( UFG::tbAimWobbleUseTweakables )
    {
      v16 = UFG::trAimWobbleAxisWeight;
      v17 = UFG::trAimWobbleFreq;
    }
    else
    {
      v16 = v3->rAimWobbleAxisWeight;
      v17 = v3->rAimWobbleFreq;
    }
    v18 = v17 * v3->rAimWobbleElapsedTime;
    v19 = v3->cAimWobbleRadius.p0;
    v20 = (float)(sinf(v18) * (float)((float)(1.0 - v16) * v19)) * v3->rAimWobbleHoldBreathMultiplier;
    v21 = (float)(cosf(v18) * (float)(v19 * v16)) * v3->rAimWobbleHoldBreathMultiplier;
    v3->mAimWobble.y = v20;
    v3->mAimWobble.x = v21;
    v22 = v3->rAimWobbleOverallScale;
    v3->mAimWobble.y = v22 * v20;
    v3->mAimWobble.x = v22 * v21;
  }
  else
  {
    v23 = UFG::qVector2::msZero.y;
    v3->mAimWobble.x = UFG::qVector2::msZero.x;
    v3->mAimWobble.y = v23;
  }
}

// File Line: 623
// RVA: 0x3BF110
void __fastcall UFG::GameCameraComponent::AddShakeAmplitude(UFG::GameCameraComponent *this, float shake)
{
  UFG::GameCameraComponent *v2; // rdi
  UFG::GameCameraComponent *v3; // rax
  UFG::SimComponent *v4; // rbx

  v2 = this;
  v3 = UFG::GetCurrentGameCamera();
  v4 = (UFG::SimComponent *)&v3->vfptr;
  if ( (!v3
     || !UFG::SimComponent::IsType(
           (UFG::SimComponent *)&v3->vfptr,
           UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID)
     && !UFG::SimComponent::IsType(v4, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID))
    && shake > v2->mImpactShakeAmplitude )
  {
    v2->mImpactShakeAmplitude = shake;
    v2->mImpactShakeTimer = UFG::qRandom(511.0, &UFG::qDefaultSeed);
    v2->mImpactShakeSeed = UFG::qRandom(511.0, &UFG::qDefaultSeed) + 511.0;
  }
}

// File Line: 645
// RVA: 0x3C5510
void __fastcall UFG::GameCameraComponent::HandleDamage(UFG::GameCameraComponent *this, float damage)
{
  UFG::RenderWorld::DamagePostEffect_OnDamage(damage);
}

// File Line: 660
// RVA: 0x3BFB40
void __fastcall UFG::GameCameraComponent::BeginDOFOverride(float focalRange, float nearRange, float farRange, float nearBlur, float farBlur, UFG::GameCameraComponent::DOFOverridePriority priority)
{
  signed __int64 v6; // rcx

  v6 = 3i64 * (signed int)priority;
  UFG::GameCameraComponent::mDofOverrideParams[8 * v6] = 1;
  *(float *)&UFG::GameCameraComponent::mDofOverrideParams[8 * v6 + 4] = focalRange;
  *(float *)&UFG::GameCameraComponent::mDofOverrideParams[8 * v6 + 8] = nearRange;
  *(float *)&UFG::GameCameraComponent::mDofOverrideParams[8 * v6 + 20] = farBlur;
  *(float *)&UFG::GameCameraComponent::mDofOverrideParams[8 * v6 + 12] = farRange;
  *(float *)&UFG::GameCameraComponent::mDofOverrideParams[8 * v6 + 16] = nearBlur;
}

// File Line: 673
// RVA: 0x3C20F0
void __fastcall UFG::GameCameraComponent::EndDOFOverride(UFG::GameCameraComponent::DOFOverridePriority priority)
{
  UFG::GameCameraComponent::mDofOverrideParams[24 * priority] = 0;
}

// File Line: 748
// RVA: 0x3DC0D0
void __fastcall UFG::GameCameraComponent::UpdateDof(UFG::GameCameraComponent *this, float dt, float inFocusRange, float nearRange, float nearBlurRadius, float farRange, float farBlurRadius)
{
  UFG::GameCameraComponent *v7; // rbx
  float v8; // xmm7_4
  float v9; // xmm6_4
  Render::DepthOfField::Focus desDofParameters; // [rsp+20h] [rbp-68h]

  v7 = this;
  v8 = (float)(UFG::GameCameraComponent::mDofFocusObjectDistFar + UFG::GameCameraComponent::mDofFocusObjectDistNear)
     * 0.5;
  v9 = (float)((float)(inFocusRange * 0.5) + UFG::GameCameraComponent::mDofFocusObjectDistFar)
     - (float)(UFG::GameCameraComponent::mDofFocusObjectDistNear - (float)(inFocusRange * 0.5));
  Render::DepthOfField::Focus::Focus(&desDofParameters);
  desDofParameters.mFocalDistance = v8;
  desDofParameters.mNearBlurRadius = nearBlurRadius;
  desDofParameters.mFarRange = farRange;
  desDofParameters.mFarBlurRadius = farBlurRadius;
  desDofParameters.mInFocusRange = v9;
  desDofParameters.mNearRange = nearRange;
  UFG::GameCameraComponent::UpdateDof(v7, dt, &desDofParameters, 0);
}

// File Line: 770
// RVA: 0x3DB660
void __fastcall UFG::GameCameraComponent::UpdateDof(UFG::GameCameraComponent *this, float dt, Render::DepthOfField::Focus *desDofParameters, bool snap)
{
  UFG::GameCameraComponent *v4; // rsi
  bool v5; // r14
  Render::DepthOfField::Focus *v6; // rbx
  float v7; // xmm12_4
  float v8; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm13_4
  float v13; // xmm6_4
  float v14; // xmm8_4
  float *v15; // rbx
  signed __int64 v16; // rbp
  float v17; // xmm0_4
  float v18; // xmm0_4
  bool v19; // cf
  bool v20; // zf
  bool v21; // al
  float v22; // xmm8_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  int v27; // xmm0_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm4_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm8_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm3_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  int v41; // ecx
  _BYTE *v42; // rax
  float *v43; // rax
  float *v44; // rax
  float v45; // xmm3_4
  float v46; // xmm5_4
  float v47; // xmm3_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm4_4
  float v51; // xmm0_4
  float v52; // xmm6_4
  float v53; // xmm14_4
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm1_4
  float v57; // xmm1_4
  float v58; // xmm6_4
  Render::DepthOfField::Focus focus; // [rsp+20h] [rbp-D8h]

  v4 = this;
  UFG::GameCameraComponent::mDofFocusDist.p1 = desDofParameters->mFocalDistance;
  v5 = snap;
  v6 = desDofParameters;
  v7 = dt;
  UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDofFocusDist);
  UFG::GameCameraComponent::mDofFocusDist.mParameter = 0.0;
  v8 = v6->mInFocusRange;
  v9 = v6->mNearRange;
  v10 = v6->mNearBlurRadius;
  v11 = v6->mFarRange;
  v12 = v6->mFarBlurRadius;
  v13 = FLOAT_0_0099999998;
  if ( UFG::GameCameraComponent::mDynamicDOF )
  {
    v14 = UFG::GameCameraComponent::mDynamicDOFTransitionDuration;
    v15 = &UFG::GameCameraComponent::mDynamicDofParams.mParameter;
    v16 = 6i64;
    do
    {
      *v15 = *v15 / *(v15 - 1);
      if ( v14 <= v13 )
        v17 = v13;
      else
        v17 = v14;
      *(v15 - 1) = v17;
      *v15 = v17 * *v15;
      UFG::HomerCubic<float>::MakeCoeffs((UFG::HomerCubic<float> *)(v15 - 1));
      v18 = dt + v15[17];
      v19 = v18 < v15[16];
      v20 = v18 == v15[16];
      v15[17] = v18;
      if ( !v19 && !v20 )
      {
        v21 = *((_BYTE *)v15 + 60) == 0;
        *((_BYTE *)v15 + 60) = v21;
        if ( v21 )
        {
          v22 = v15[9];
          v23 = v15[10];
        }
        else
        {
          v22 = v15[12];
          v23 = v15[13];
        }
        v24 = UFG::qRandom(v23 * 2.0, &UFG::qDefaultSeed);
        v15[17] = 0.0;
        v25 = v24 - v23;
        v13 = FLOAT_0_0099999998;
        v26 = v25 + v22;
        v14 = UFG::GameCameraComponent::mDynamicDOFTransitionDuration;
        v15[16] = v26;
      }
      if ( *((_BYTE *)v15 + 60) )
        v27 = *((_DWORD *)v15 + 11);
      else
        v27 = *((_DWORD *)v15 + 14);
      *((_DWORD *)v15 + 6) = v27;
      UFG::HomerCubic<float>::MakeCoeffs((UFG::HomerCubic<float> *)(v15 - 1));
      *v15 = 0.0;
      v15 += 19;
      --v16;
    }
    while ( v16 );
    v28 = UFG::GameCameraComponent::mDynamicDofParams.mParameter + dt;
    if ( (float)(UFG::GameCameraComponent::mDynamicDofParams.mParameter + dt) <= 0.0 )
      v28 = 0.0;
    if ( v28 >= UFG::GameCameraComponent::mDynamicDofParams.mDuration )
      v28 = UFG::GameCameraComponent::mDynamicDofParams.mDuration;
    UFG::GameCameraComponent::mDynamicDofParams.mParameter = v28;
    v29 = (float)((float)((float)(UFG::GameCameraComponent::mDynamicDofParams.A * 3.0) * v28)
                + (float)(UFG::GameCameraComponent::mDynamicDofParams.B * 2.0))
        * v28;
    v30 = (float)((float)((float)((float)((float)(UFG::GameCameraComponent::mDynamicDofParams.A * v28)
                                        + UFG::GameCameraComponent::mDynamicDofParams.B)
                                * v28)
                        + UFG::GameCameraComponent::mDynamicDofParams.C)
                * v28)
        + UFG::GameCameraComponent::mDynamicDofParams.D;
    v31 = stru_1423D7CAC.mParameter + dt;
    UFG::GameCameraComponent::mDynamicDofParams.v0 = v29 + UFG::GameCameraComponent::mDynamicDofParams.C;
    UFG::GameCameraComponent::mDynamicDofParams.p0 = v30;
    if ( (float)(stru_1423D7CAC.mParameter + dt) <= 0.0 )
      v31 = 0.0;
    if ( v31 >= stru_1423D7CAC.mDuration )
      v31 = stru_1423D7CAC.mDuration;
    stru_1423D7CAC.mParameter = v31;
    v32 = (float)((float)((float)(stru_1423D7CAC.A * 3.0) * v31) + (float)(stru_1423D7CAC.B * 2.0)) * v31;
    v33 = (float)((float)((float)((float)((float)(stru_1423D7CAC.A * v31) + stru_1423D7CAC.B) * v31) + stru_1423D7CAC.C)
                * v31)
        + stru_1423D7CAC.D;
    v34 = stru_1423D7CF8.mParameter + dt;
    stru_1423D7CAC.v0 = v32 + stru_1423D7CAC.C;
    stru_1423D7CAC.p0 = v33;
    if ( (float)(stru_1423D7CF8.mParameter + dt) <= 0.0 )
      v34 = 0.0;
    if ( v34 >= stru_1423D7CF8.mDuration )
      v34 = stru_1423D7CF8.mDuration;
    stru_1423D7CF8.mParameter = v34;
    v35 = (float)((float)((float)(stru_1423D7CF8.A * 3.0) * v34) + (float)(stru_1423D7CF8.B * 2.0)) * v34;
    v9 = (float)((float)((float)((float)((float)(stru_1423D7CF8.A * v34) + stru_1423D7CF8.B) * v34) + stru_1423D7CF8.C)
               * v34)
       + stru_1423D7CF8.D;
    v36 = stru_1423D7D44.mParameter + dt;
    stru_1423D7CF8.v0 = v35 + stru_1423D7CF8.C;
    stru_1423D7CF8.p0 = v9;
    if ( (float)(stru_1423D7D44.mParameter + dt) <= 0.0 )
      v36 = 0.0;
    if ( v36 >= stru_1423D7D44.mDuration )
      v36 = stru_1423D7D44.mDuration;
    stru_1423D7D44.mParameter = v36;
    v37 = (float)((float)((float)(stru_1423D7D44.A * 3.0) * v36) + (float)(stru_1423D7D44.B * 2.0)) * v36;
    v10 = (float)((float)((float)((float)((float)(stru_1423D7D44.A * v36) + stru_1423D7D44.B) * v36) + stru_1423D7D44.C)
                * v36)
        + stru_1423D7D44.D;
    v38 = stru_1423D7D90.mParameter + dt;
    stru_1423D7D44.v0 = v37 + stru_1423D7D44.C;
    stru_1423D7D44.p0 = v10;
    if ( (float)(stru_1423D7D90.mParameter + dt) <= 0.0 )
      v38 = 0.0;
    if ( v38 >= stru_1423D7D90.mDuration )
      v38 = stru_1423D7D90.mDuration;
    stru_1423D7D90.mParameter = v38;
    v39 = (float)((float)((float)(stru_1423D7D90.A * 3.0) * v38) + (float)(stru_1423D7D90.B * 2.0)) * v38;
    v11 = (float)((float)((float)((float)((float)(stru_1423D7D90.A * v38) + stru_1423D7D90.B) * v38) + stru_1423D7D90.C)
                * v38)
        + stru_1423D7D90.D;
    v40 = stru_1423D7DDC.mParameter + dt;
    stru_1423D7D90.v0 = v39 + stru_1423D7D90.C;
    stru_1423D7D90.p0 = v11;
    if ( (float)(stru_1423D7DDC.mParameter + dt) <= 0.0 )
      v40 = 0.0;
    if ( v40 >= stru_1423D7DDC.mDuration )
      v40 = stru_1423D7DDC.mDuration;
    stru_1423D7DDC.mParameter = v40;
    UFG::GameCameraComponent::mDofFocusDist.p1 = v30;
    v12 = (float)((float)((float)((float)((float)(stru_1423D7DDC.A * v40) + stru_1423D7DDC.B) * v40) + stru_1423D7DDC.C)
                * v40)
        + stru_1423D7DDC.D;
    stru_1423D7DDC.v0 = (float)((float)((float)((float)(stru_1423D7DDC.A * 3.0) * v40) + (float)(stru_1423D7DDC.B * 2.0))
                              * v40)
                      + stru_1423D7DDC.C;
    stru_1423D7DDC.p0 = (float)((float)((float)((float)((float)(stru_1423D7DDC.A * v40) + stru_1423D7DDC.B) * v40)
                                      + stru_1423D7DDC.C)
                              * v40)
                      + stru_1423D7DDC.D;
    UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDofFocusDist);
    v8 = v33 * 2.0;
  }
  v41 = 0;
  v42 = UFG::GameCameraComponent::mDofOverrideParams;
  while ( !*v42 )
  {
    v42 += 24;
    ++v41;
    if ( (signed __int64)v42 >= (signed __int64)&UI_HASH_SCREEN_PUSHED_7 )
      goto LABEL_46;
  }
  v43 = (float *)&UFG::GameCameraComponent::mDofOverrideParams[24 * v41];
  if ( v43 )
  {
    v8 = v43[1];
    v9 = v43[2];
    v10 = v43[4];
    v11 = v43[3];
    v12 = v43[5];
  }
LABEL_46:
  v44 = &UFG::trDofFocusDistanceDurationShrink;
  v45 = 0.0 / UFG::GameCameraComponent::mDofFocusDist.mDuration;
  if ( UFG::GameCameraComponent::mDofFocusDist.p1 > UFG::GameCameraComponent::mDofFocusDist.p0 )
    v44 = &UFG::trDofFocusDistanceDurationGrow;
  v46 = *v44;
  if ( *v44 <= v13 )
    v46 = v13;
  UFG::GameCameraComponent::mDofFocusDist.mDuration = v46;
  v47 = v45 * v46;
  if ( v46 > v13 )
    v13 = v46;
  v48 = v13 * v13;
  v49 = v47 + dt;
  v50 = (float)((float)((float)(UFG::GameCameraComponent::mDofFocusDist.v1 + UFG::GameCameraComponent::mDofFocusDist.v0)
                      * v13)
              + (float)((float)(UFG::GameCameraComponent::mDofFocusDist.p0 - UFG::GameCameraComponent::mDofFocusDist.p1)
                      * 2.0))
      / (float)((float)(v13 * v13) * v13);
  UFG::GameCameraComponent::mDofFocusDist.A = (float)((float)((float)(UFG::GameCameraComponent::mDofFocusDist.v1
                                                                    + UFG::GameCameraComponent::mDofFocusDist.v0)
                                                            * v13)
                                                    + (float)((float)(UFG::GameCameraComponent::mDofFocusDist.p0
                                                                    - UFG::GameCameraComponent::mDofFocusDist.p1)
                                                            * 2.0))
                                            / (float)((float)(v13 * v13) * v13);
  v51 = (float)((float)(UFG::GameCameraComponent::mDofFocusDist.v0 * 2.0) + UFG::GameCameraComponent::mDofFocusDist.v1)
      * v13;
  v52 = UFG::GameCameraComponent::mDofFocusDist.v0;
  UFG::GameCameraComponent::mDofFocusDist.C = UFG::GameCameraComponent::mDofFocusDist.v0;
  v53 = (float)((float)((float)(UFG::GameCameraComponent::mDofFocusDist.p1 - UFG::GameCameraComponent::mDofFocusDist.p0)
                      * 3.0)
              - v51)
      / v48;
  UFG::GameCameraComponent::mDofFocusDist.D = UFG::GameCameraComponent::mDofFocusDist.p0;
  UFG::GameCameraComponent::mDofFocusDist.B = (float)((float)((float)(UFG::GameCameraComponent::mDofFocusDist.p1
                                                                    - UFG::GameCameraComponent::mDofFocusDist.p0)
                                                            * 3.0)
                                                    - v51)
                                            / v48;
  if ( v49 <= 0.0 )
    v49 = 0.0;
  if ( v49 >= v46 )
    v49 = v46;
  UFG::GameCameraComponent::mDofFocusDist.mParameter = v49;
  UFG::GameCameraComponent::mDofFocusDist.v0 = (float)((float)((float)((float)(v50 * 3.0) * v49) + (float)(v53 * 2.0))
                                                     * v49)
                                             + UFG::GameCameraComponent::mDofFocusDist.v0;
  UFG::GameCameraComponent::mDofFocusDist.p0 = (float)((float)((float)((float)((float)(v50 * v49) + v53) * v49) + v52)
                                                     * v49)
                                             + UFG::GameCameraComponent::mDofFocusDist.p0;
  if ( v8 <= UFG::GameCameraComponent::mDofInFocusRange )
    v54 = UFG::trDofInFocusRangeRateShrink;
  else
    v54 = UFG::trDofInFocusRangeRateGrow;
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofInFocusRange,
    v8,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofInFocusRange - v8) & _xmm) * v54,
    dt);
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofNearRange,
    v9,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofNearRange - v9) & _xmm) * UFG::trDofNearRangeRate,
    dt);
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofNearBlur,
    v10,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofNearBlur - v10) & _xmm) * UFG::trDofNearBlurRate,
    dt);
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofFarRange,
    v11,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofFarRange - v11) & _xmm) * UFG::trDofFarRangeRate,
    dt);
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofFarBlur,
    v12,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofFarBlur - v12) & _xmm) * UFG::trDofFarBlurRate,
    dt);
  if ( v5 )
  {
    UFG::GameCameraComponent::mDofFocusDist.p0 = UFG::GameCameraComponent::mDofFocusDist.p1;
    UFG::GameCameraComponent::mDofFocusDist.v0 = UFG::GameCameraComponent::mDofFocusDist.v1;
    UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDofFocusDist);
    UFG::GameCameraComponent::mDofFocusDist.mParameter = 0.0;
    UFG::GameCameraComponent::mDofInFocusRange = v8;
    UFG::GameCameraComponent::mDofNearRange = v9;
    UFG::GameCameraComponent::mDofNearBlur = v10;
    UFG::GameCameraComponent::mDofFarRange = v11;
    UFG::GameCameraComponent::mDofFarBlur = v12;
  }
  v55 = v4->mDofNoiseAmplitude;
  v56 = 1.0 - (float)(dt * v4->mDofNoiseAmplitudeDecay);
  if ( v56 < 0.0 )
    v56 = 0.0;
  v57 = v56 * v55;
  v4->mDofNoiseAmplitude = v57;
  if ( v57 <= 0.0099999998 )
  {
    if ( v55 > 0.0099999998 )
      *(_QWORD *)&v4->mDofNoiseTimer = 0i64;
  }
  else
  {
    v4->mDofNoiseTimer = v7 + v4->mDofNoiseTimer;
  }
  Render::DepthOfField::Focus::Focus(&focus);
  v58 = UFG::GameCameraComponent::mDofFocusDist.p0;
  if ( 0.0 != v4->mDofNoiseAmplitude )
    v58 = v58 + (float)(UFG::qNoise<float,float>::GetValue(&v4->mDofNoise, v4->mDofNoiseTimer) * v4->mDofNoiseAmplitude);
  if ( v58 < 0.0099999998 )
    v58 = FLOAT_0_0099999998;
  focus.mFocalDistance = v58;
  if ( UFG::GameCameraComponent::mDofInFocusRange >= 0.0099999998 )
    focus.mInFocusRange = UFG::GameCameraComponent::mDofInFocusRange;
  else
    focus.mInFocusRange = 0.0099999998;
  if ( UFG::GameCameraComponent::mDofNearRange >= 0.0099999998 )
    focus.mNearRange = UFG::GameCameraComponent::mDofNearRange;
  else
    focus.mNearRange = 0.0099999998;
  if ( UFG::GameCameraComponent::mDofNearBlur >= 0.0 )
    focus.mNearBlurRadius = UFG::GameCameraComponent::mDofNearBlur;
  else
    focus.mNearBlurRadius = 0.0;
  if ( UFG::GameCameraComponent::mDofFarRange >= 0.0099999998 )
    focus.mFarRange = UFG::GameCameraComponent::mDofFarRange;
  else
    focus.mFarRange = 0.0099999998;
  if ( UFG::GameCameraComponent::mDofFarBlur >= 0.0 )
    focus.mFarBlurRadius = UFG::GameCameraComponent::mDofFarBlur;
  else
    focus.mFarBlurRadius = 0.0;
  Render::DepthOfField::Focus::Set(&v4->mCamera.mDepthOfFieldFocus, &focus);
}

// File Line: 922
// RVA: 0x3CE4E0
void UFG::GameCameraComponent::StartDynamicDof(void)
{
  UFG::GameCameraComponent::mDynamicDOF = 1;
}

// File Line: 928
// RVA: 0x3CE4F0
void UFG::GameCameraComponent::StopDynamicDof(void)
{
  UFG::GameCameraComponent::mDynamicDOF = 0;
}

// File Line: 934
// RVA: 0x3CC350
void __fastcall UFG::GameCameraComponent::SetDynamicDOFParam(UFG::GameCameraComponent::DynamicDofParamType dofParamType, float duration_high, float deviation_high, float value_high, float duration_low, float deviation_low, float value_low)
{
  UFG::GameCameraComponent::DynamicDofParam *v7; // rax

  v7 = (UFG::GameCameraComponent::DynamicDofParam *)((char *)&UFG::GameCameraComponent::mDynamicDofParams
                                                   + 76 * dofParamType);
  v7->mDurationHigh = duration_high;
  v7->mDurationLow = duration_low;
  v7->mDeviationLow = deviation_low;
  v7->mDeviationHigh = deviation_high;
  v7->mValueLow = value_low;
  v7->mValueHigh = value_high;
}

// File Line: 981
// RVA: 0x3C2160
UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *__fastcall UFG::GameCameraComponent::FindClosestCollidableHit(UFG::GameCameraComponent *this, UFG::ShapeCasterCollector *collector, UFG::qVector3 *startPos, float safeRadius)
{
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v4; // rbx
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *v5; // rdi
  UFG::qVector3 *v6; // rsi
  UFG::ShapeCasterCollector *v7; // r15
  UFG::GameCameraComponent *v8; // r14
  float v10; // xmm6_4
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v11; // rbp
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm2_4

  v4 = collector->mHitList.mNode.mNext;
  v5 = &collector->mHitList;
  v6 = startPos;
  v7 = collector;
  v8 = this;
  if ( v4 == (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)&collector->mHitList )
    return 0i64;
  v10 = FLOAT_1_0e12;
  v11 = 0i64;
  do
  {
    if ( !UFG::GameCameraComponent::ShouldPassThru(v8, (UFG::ShapeCasterCollector::HitInfo *)v4, v6) )
    {
      v12 = v7->mRadius;
      v13 = v12;
      v14 = (float)((float)(v12 * *((float *)&v4[2].mPrev + 1)) + *(float *)&v4[1].mNext) - v6->z;
      v15 = (float)((float)(v7->mRadius * *(float *)&v4[2].mPrev) + *((float *)&v4[1].mPrev + 1)) - v6->y;
      v16 = (float)((float)(v13 * *((float *)&v4[1].mNext + 1)) + *(float *)&v4[1].mPrev) - v6->x;
      v17 = (float)((float)(v15 * v15) + (float)(v16 * v16)) + (float)(v14 * v14);
      if ( v17 >= (float)(safeRadius * safeRadius) && v17 < v10 )
      {
        v11 = v4;
        v10 = v17;
      }
    }
    v4 = v4->mNext;
  }
  while ( v4 != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)v5 );
  return v11;
}

// File Line: 1051
// RVA: 0x3C0C20
float __fastcall UFG::GameCameraComponent::ComputeNearOffset(UFG::GameCameraComponent *this, UFG::qVector3 *eye, UFG::qVector3 *look, float dispFov)
{
  UFG::qVector3 *v4; // rdi
  UFG::qVector3 *v5; // rbx
  UFG::GameCameraComponent *v6; // r14
  float v8; // xmm15_4
  float v9; // xmm6_4
  float v10; // xmm11_4
  __m128 v11; // xmm10
  UFG::CharacterSubjectComponent *v12; // rdi
  float v13; // xmm8_4
  float v14; // xmm13_4
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm11_4
  __m128 v18; // xmm2
  float v19; // xmm3_4
  float v20; // xmm10_4
  float v21; // xmm11_4
  __m128 v22; // xmm12
  float v23; // xmm6_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm6_4
  float v27; // xmm0_4
  char v28; // r13
  __m128 v29; // xmm2
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm7_4
  char v34; // r15
  __m128 v35; // xmm2
  float v36; // xmm0_4
  __m128 v37; // xmm4
  float v38; // xmm13_4
  float v39; // xmm15_4
  __m128 v40; // xmm2
  float v41; // xmm5_4
  float v42; // xmm6_4
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm0_4
  char v48; // r12
  __m128 v49; // xmm3
  float v50; // xmm0_4
  float v51; // xmm6_4
  unsigned __int16 v52; // dx
  UFG::CharacterSubjectComponent *v53; // rax
  __int64 v54; // rax
  bool v55; // zf
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm1_4
  float v59; // xmm0_4
  __m128 v60; // xmm2
  float v61; // xmm6_4
  Render::DebugDrawContext *v62; // rax
  UFG::qColour *v63; // rsi
  float v64; // xmm7_4
  float v65; // xmm13_4
  float v66; // xmm14_4
  Render::DebugDrawContext *v67; // rdi
  UFG::qColour *v68; // r9
  float v69; // xmm0_4
  float v70; // xmm1_4
  UFG::qColour *v71; // r9
  float v72; // xmm0_4
  float v73; // xmm1_4
  float v74; // xmm11_4
  float v75; // xmm10_4
  float v76; // xmm12_4
  UFG::qColour *v77; // r9
  float v78; // xmm1_4
  float v79; // xmm0_4
  UFG::qVector3 rayEnd; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 closest_point; // [rsp+50h] [rbp-B0h]
  float v82; // [rsp+60h] [rbp-A0h]
  float v83; // [rsp+64h] [rbp-9Ch]
  float v84; // [rsp+68h] [rbp-98h]
  float v85; // [rsp+6Ch] [rbp-94h]
  float v86; // [rsp+70h] [rbp-90h]
  float v87; // [rsp+74h] [rbp-8Ch]
  float v88; // [rsp+78h] [rbp-88h]
  UFG::qVector3 lA0; // [rsp+80h] [rbp-80h]
  UFG::RayCastData data; // [rsp+90h] [rbp-70h]
  UFG::RayCastData v91; // [rsp+170h] [rbp+70h]
  UFG::RayCastData v92; // [rsp+250h] [rbp+150h]
  float v93; // [rsp+418h] [rbp+318h]

  v4 = look;
  v5 = eye;
  v6 = this;
  if ( !UFG::tbCollisionNearOffsetCasts )
    return 0.0;
  v93 = dispFov * 0.5;
  v8 = cosf(dispFov * 0.5);
  v9 = tanf(dispFov * 0.5);
  UFG::Director::Get();
  v10 = v4->x;
  v11 = (__m128)LODWORD(v4->y);
  v22 = (__m128)LODWORD(v4->z);
  v12 = 0i64;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_hitFraction = 1.0;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeys[0] = -1;
  v13 = 0.0;
  v22.m128_f32[0] = v22.m128_f32[0] - v5->z;
  v14 = UFG::trCollisionNearMargin + UFG::gCameraDefaultNear;
  v15 = v5->x;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  data.mOutput.m_rootCollidable = 0i64;
  data.mDebugName = 0i64;
  v16 = v5->y;
  v17 = v10 - v15;
  v11.m128_f32[0] = v11.m128_f32[0] - v16;
  v88 = UFG::trCollisionNearMargin + UFG::gCameraDefaultNear;
  v18 = v11;
  v18.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v17 * v17))
                  + (float)(v22.m128_f32[0] * v22.m128_f32[0]);
  v19 = (float)(UFG::trCollisionNearMargin + UFG::gCameraDefaultNear) / COERCE_FLOAT(_mm_sqrt_ps(v18));
  v20 = v11.m128_f32[0] * v19;
  v21 = v17 * v19;
  v22.m128_f32[0] = v22.m128_f32[0] * v19;
  v82 = (float)(UFG::trCollisionNearMargin + UFG::gCameraDefaultNear) * v9;
  v23 = v82
      / fsqrt((float)(COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(v21) ^ _xmm[0])) + (float)(v20 * v20));
  v24 = v23;
  v25 = v23;
  v26 = v23 * 0.0;
  v86 = v26;
  v83 = v24 * v20;
  v84 = v25 * COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]);
  data.mCollisionModelName.mUID = -1;
  v27 = (float)(v22.m128_f32[0] + v5->z) + v26;
  rayEnd.x = (float)(v15 + v21) + (float)(v24 * v20);
  rayEnd.y = (float)(v16 + v20) + (float)(v25 * COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]));
  rayEnd.z = v27;
  UFG::RayCastData::Init(&data, v5, &rayEnd, 0x12u);
  v28 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
  if ( v28 )
  {
    v29 = (__m128)LODWORD(data.point.y);
    v29.m128_f32[0] = (float)((float)((float)(data.point.y - v5->y) * (float)(data.point.y - v5->y))
                            + (float)((float)(data.point.x - v5->x) * (float)(data.point.x - v5->x)))
                    + (float)((float)(data.point.z - v5->z) * (float)(data.point.z - v5->z));
    LODWORD(v13) = COERCE_UNSIGNED_INT(v14 - (float)(COERCE_FLOAT(_mm_sqrt_ps(v29)) * v8)) ^ _xmm[0];
  }
  v91.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  v91.mInput.m_filterInfo = 0;
  v30 = v21 + v5->x;
  v31 = v20 + v5->y;
  v32 = v22.m128_f32[0] + v5->z;
  v33 = 0.0;
  v91.mInput.m_userData = 0i64;
  v91.mOutput.m_hitFraction = 1.0;
  v91.mOutput.m_extraInfo = -1;
  v91.mOutput.m_shapeKeyIndex = 0;
  v91.mOutput.m_shapeKeys[0] = -1;
  v91.mOutput.m_rootCollidable = 0i64;
  v91.mDebugName = 0i64;
  v91.mCollisionModelName.mUID = -1;
  rayEnd.x = v30 - v83;
  rayEnd.y = v31 - v84;
  rayEnd.z = v32 - v26;
  UFG::RayCastData::Init(&v91, v5, &rayEnd, 0x12u);
  v34 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v91);
  if ( v34 )
  {
    v35 = (__m128)LODWORD(v91.point.y);
    v35.m128_f32[0] = (float)((float)((float)(v91.point.y - v5->y) * (float)(v91.point.y - v5->y))
                            + (float)((float)(v91.point.x - v5->x) * (float)(v91.point.x - v5->x)))
                    + (float)((float)(v91.point.z - v5->z) * (float)(v91.point.z - v5->z));
    LODWORD(v33) = COERCE_UNSIGNED_INT(v14 - (float)(COERCE_FLOAT(_mm_sqrt_ps(v35)) * v8)) ^ _xmm[0];
  }
  v36 = Render::GetDisplayAspectRatio();
  v37 = v22;
  v38 = 0.0;
  v39 = 1.0 / v36;
  v92.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  v92.mInput.m_filterInfo = 0;
  v92.mInput.m_userData = 0i64;
  v37.m128_f32[0] = (float)(v22.m128_f32[0] * COERCE_FLOAT(LODWORD(v83) ^ _xmm[0]))
                  - (float)(COERCE_FLOAT(LODWORD(v86) ^ _xmm[0]) * v21);
  v92.mOutput.m_hitFraction = 1.0;
  v92.mOutput.m_extraInfo = -1;
  v92.mOutput.m_shapeKeyIndex = 0;
  v40 = v37;
  v92.mOutput.m_shapeKeys[0] = -1;
  v92.mOutput.m_rootCollidable = 0i64;
  v92.mDebugName = 0i64;
  v92.mCollisionModelName.mUID = -1;
  v41 = (float)(COERCE_FLOAT(LODWORD(v86) ^ _xmm[0]) * v20)
      - (float)(v22.m128_f32[0] * COERCE_FLOAT(LODWORD(v84) ^ _xmm[0]));
  v42 = (float)(COERCE_FLOAT(LODWORD(v84) ^ _xmm[0]) * v21) - (float)(COERCE_FLOAT(LODWORD(v83) ^ _xmm[0]) * v20);
  v43 = (float)(1.0 / v36) * v82;
  v40.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v41 * v41)) + (float)(v42 * v42);
  v44 = v20 + v5->y;
  LODWORD(v45) = (unsigned __int128)_mm_sqrt_ps(v40);
  v40.m128_f32[0] = v22.m128_f32[0] + v5->z;
  v46 = v43 / v45;
  v82 = v46 * v41;
  v47 = v21 + v5->x;
  v85 = v46 * v42;
  rayEnd.z = v40.m128_f32[0] + (float)(v46 * v42);
  v87 = v46 * v37.m128_f32[0];
  rayEnd.x = v47 + (float)(v46 * v41);
  rayEnd.y = v44 + (float)(v46 * v37.m128_f32[0]);
  UFG::RayCastData::Init(&v92, v5, &rayEnd, 0x12u);
  v48 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v92);
  if ( v48 )
  {
    v49 = (__m128)LODWORD(v92.point.y);
    v49.m128_f32[0] = (float)((float)((float)(v92.point.y - v5->y) * (float)(v92.point.y - v5->y))
                            + (float)((float)(v92.point.x - v5->x) * (float)(v92.point.x - v5->x)))
                    + (float)((float)(v92.point.z - v5->z) * (float)(v92.point.z - v5->z));
    v50 = cosf(v39 * v93);
    LODWORD(v38) = COERCE_UNSIGNED_INT(v88 - (float)(COERCE_FLOAT(_mm_sqrt_ps(v49)) * v50)) ^ _xmm[0];
  }
  v51 = 0.0;
  if ( LocalPlayer )
  {
    v52 = LocalPlayer->m_Flags;
    if ( (v52 >> 14) & 1 )
    {
      v53 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
    }
    else if ( (v52 & 0x8000u) == 0 )
    {
      if ( (v52 >> 13) & 1 )
      {
        v53 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                  UFG::CharacterSubjectComponent::_TypeUID);
      }
      else if ( (v52 >> 12) & 1 )
      {
        v53 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                  UFG::CharacterSubjectComponent::_TypeUID);
      }
      else
      {
        v53 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&LocalPlayer->vfptr,
                                                  UFG::CharacterSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v53 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                UFG::CharacterSubjectComponent::_TypeUID);
    }
    v12 = v53;
  }
  if ( v12 && !((unsigned __int8 (__fastcall *)(UFG::CharacterSubjectComponent *))v12->vfptr[29].__vecDelDtor)(v12) )
  {
    v54 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v12->vfptr[26].__vecDelDtor)(v12);
    v55 = v12->mPelvisDirty == 0;
    v56 = *(float *)(v54 + 4);
    v57 = *(float *)(v54 + 8);
    rayEnd.x = *(float *)v54;
    rayEnd.y = v56;
    rayEnd.z = v57;
    if ( !v55 )
      UFG::CharacterSubjectComponent::UpdatePelvis(v12);
    v58 = v12->mPelvisPosition.y;
    lA0.x = v12->mPelvisPosition.x;
    v59 = v12->mPelvisPosition.z;
    lA0.y = v58;
    lA0.z = v59;
    UFG::qGetClosestPointOnSegment(&closest_point, &lA0, &rayEnd, v5);
    v60 = (__m128)LODWORD(closest_point.y);
    v60.m128_f32[0] = (float)((float)((float)(closest_point.y - v5->y) * (float)(closest_point.y - v5->y))
                            + (float)((float)(closest_point.x - v5->x) * (float)(closest_point.x - v5->x)))
                    + (float)((float)(closest_point.z - v5->z) * (float)(closest_point.z - v5->z));
    v61 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v60)) - 0.40000001) * 2.8571429;
    if ( v61 <= 0.0 )
    {
      v61 = 0.0;
    }
    else if ( v61 >= 1.0 )
    {
      v61 = *(float *)&FLOAT_1_0;
    }
    v51 = (float)(v61 * 0.22) - 0.22;
  }
  if ( v13 >= v33 )
    v13 = v33;
  if ( v13 >= v38 )
    v13 = v38;
  if ( v13 >= v51 )
    v13 = v51;
  if ( (float)(v13 + UFG::gCameraDefaultNear) < UFG::trCollisionNearOffsetMin )
    v13 = UFG::trCollisionNearOffsetMin - UFG::gCameraDefaultNear;
  if ( COERCE_FLOAT(LODWORD(v13) & _xmm) < 0.000099999997 )
    v13 = 0.0;
  if ( UFG::tbCollisionDebugDraw )
  {
    v62 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    v63 = &UFG::qColour::Green;
    v64 = v86;
    v65 = v83;
    v66 = v84;
    v67 = v62;
    v68 = &UFG::qColour::Green;
    v69 = v21 + v5->x;
    v70 = v20 + v5->y;
    if ( v28 )
      v68 = &UFG::qColour::Red;
    closest_point.z = (float)(v22.m128_f32[0] + v5->z) + v86;
    closest_point.x = v69 + v83;
    closest_point.y = v70 + v84;
    Render::DebugDrawContext::DrawSphere(v62, &closest_point, 0.0099999998, v68, &UFG::qMatrix44::msIdentity, 0i64);
    if ( v28 )
      Render::DebugDrawContext::DrawSphere(
        v67,
        &data.point,
        0.0099999998,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
    v71 = &UFG::qColour::Green;
    if ( v34 )
      v71 = &UFG::qColour::Red;
    v72 = (float)(v21 + v5->x) - v65;
    v73 = (float)(v20 + v5->y) - v66;
    closest_point.z = (float)(v22.m128_f32[0] + v5->z) - v64;
    closest_point.x = v72;
    closest_point.y = v73;
    Render::DebugDrawContext::DrawSphere(v67, &closest_point, 0.0099999998, v71, &UFG::qMatrix44::msIdentity, 0i64);
    if ( v34 )
      Render::DebugDrawContext::DrawSphere(
        v67,
        &v91.point,
        0.0099999998,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
    v74 = v21 + v5->x;
    v75 = v20 + v5->y;
    v76 = v22.m128_f32[0] + v5->z;
    if ( v48 )
      v63 = &UFG::qColour::Red;
    closest_point.x = v74 + v82;
    closest_point.y = v75 + v87;
    closest_point.z = v76 + v85;
    Render::DebugDrawContext::DrawSphere(v67, &closest_point, 0.0099999998, v63, &UFG::qMatrix44::msIdentity, 0i64);
    if ( v48 )
      Render::DebugDrawContext::DrawSphere(
        v67,
        &v92.point,
        0.0099999998,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
    v77 = &UFG::qColour::Yellow;
    if ( v13 == 0.0 )
      v77 = &UFG::qColour::White;
    v78 = v6->mCamera.mProjection.v2.z;
    if ( v78 == 0.0 || v78 == v6->mCamera.mProjection.v2.w )
      v79 = v85;
    else
      v79 = v6->mCamera.mProjection.v3.z / v78;
    Render::DebugDrawContext::DrawTextA(v67, 440, 500, v77, "Nearoffset : %f(res:%f)", v13, v79);
  }
  return v13;
}

// File Line: 1185
// RVA: 0x3BF1C0
char __fastcall UFG::GameCameraComponent::AnyTargetPointVisible(UFG::GameCameraComponent *this, UFG::qVector3 *eye)
{
  int v2; // edi
  UFG::qVector3 *v3; // rbp
  UFG::GameCameraComponent *v4; // rbx
  float *v5; // rsi
  float v6; // xmm1_4
  UFG::ShapeCasterCollector *v7; // rdx
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::ShapeCasterCollector::HitInfo *v12; // rax
  UFG::qVector3 start; // [rsp+30h] [rbp-28h]
  UFG::qVector3 end; // [rsp+40h] [rbp-18h]

  v2 = 0;
  v3 = eye;
  v4 = this;
  if ( this->mCollisionTargetPointsNum <= 0 )
    return 0;
  v5 = &this->mCollisionTargetPoints[0].z;
  while ( 1 )
  {
    v6 = *(v5 - 1);
    v7 = v4->pCollisionCollectorTargetPoints;
    start.x = *(v5 - 2);
    v8 = *v5;
    start.y = v6;
    v9 = v3->x;
    start.z = v8;
    v10 = v3->y;
    end.x = v9;
    v11 = v3->z;
    end.y = v10;
    end.z = v11;
    if ( !UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, v7, &start, &end) )
      break;
    v12 = UFG::GameCameraComponent::FindClosestCollidableHit(
            v4,
            v4->pCollisionCollectorTargetPoints,
            &start,
            v4->mSafeRadius);
    if ( !v12 || UFG::GameCameraComponent::ShouldPassThru(v4, v12, &start) )
      break;
    ++v2;
    v5 += 3;
    if ( v2 >= v4->mCollisionTargetPointsNum )
      return 0;
  }
  return 1;
}

// File Line: 1276
// RVA: 0x3CB1C0
void __usercall UFG::GameCameraComponent::SetDesiredEyeLookUp(UFG::GameCameraComponent *this@<rcx>, float dt@<xmm1>, UFG::qVector3 *desEye@<r8>, UFG::qVector3 *desLook@<r9>, float *a5@<r13>, UFG::qVector3 *desUp, bool collide, UFG::qVector3 *newEye, UFG::qVector3 *newLook)
{
  char v9; // bl
  float v10; // xmm3_4
  float v11; // xmm4_4
  UFG::qVector3 *v12; // rdi
  UFG::qVector3 *v13; // r14
  UFG::GameCameraComponent *v14; // rsi
  float v15; // xmm8_4
  float v16; // xmm7_4
  bool v17; // zf
  __int128 v18; // xmm9
  float v19; // xmm15_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  UFG::qVector3 *v25; // rax
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm2_4
  UFG::qVector3 *v30; // rax
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm6_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float *v36; // rdi
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float *v43; // rax
  float v44; // xmm7_4
  float v45; // xmm8_4
  float v46; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm7_4
  float v49; // xmm8_4
  float v50; // xmm12_4
  __m128 v51; // xmm2
  float v52; // xmm1_4
  float v53; // xmm8_4
  float v54; // xmm9_4
  float v55; // xmm7_4
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v56; // rbx
  float v57; // xmm6_4
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v58; // rax
  float v59; // xmm0_4
  float v60; // xmm1_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // eax
  float v64; // xmm4_4
  __m128 v65; // xmm2
  float v66; // xmm3_4
  float v67; // xmm1_4
  float *v68; // r13
  float v69; // xmm0_4
  float v70; // xmm2_4
  float v71; // xmm13_4
  float v72; // xmm1_4
  float v73; // xmm2_4
  float v74; // xmm6_4
  float v75; // xmm2_4
  float v76; // xmm10_4
  float v77; // xmm2_4
  float v78; // xmm0_4
  float v79; // xmm3_4
  float v80; // xmm12_4
  float v81; // xmm2_4
  float v82; // xmm0_4
  float v83; // xmm1_4
  float v84; // xmm8_4
  float v85; // xmm9_4
  float *v86; // rdi
  float *v87; // rax
  float v88; // xmm7_4
  Render::DebugDrawContext *v89; // rax
  bool v90; // dl
  const char *v91; // rbx
  Render::DebugDrawContext *v92; // r12
  const char *v93; // rcx
  UFG::qColour *v94; // r9
  UFG::qColour *v95; // r9
  UFG::qColour *v96; // r9
  float v97; // xmm0_4
  double removePhantomWhenDone; // ST28_8
  UFG::qColour *v99; // r13
  char v100; // r14
  const char *v101; // rbx
  const char *v102; // rax
  UFG::qColour *v103; // r9
  UFG::qVector3 eye; // [rsp+40h] [rbp-90h]
  UFG::qVector3 loook; // [rsp+50h] [rbp-80h]
  UFG::qVector3 up; // [rsp+60h] [rbp-70h]
  UFG::qVector3 result; // [rsp+70h] [rbp-60h]
  UFG::GameCameraComponent *v108; // [rsp+120h] [rbp+50h]
  UFG::qVector3 *centre; // [rsp+138h] [rbp+68h]
  float *vars0; // [rsp+140h] [rbp+70h]
  void *retaddr; // [rsp+148h] [rbp+78h]
  float *v112; // [rsp+150h] [rbp+80h]
  float *v113; // [rsp+158h] [rbp+88h]
  float *v114; // [rsp+158h] [rbp+88h]

  v112 = (float *)this;
  v9 = (char)retaddr;
  v10 = desEye->x;
  v11 = desEye->y;
  v12 = desLook;
  v13 = desEye;
  v14 = this;
  v15 = desLook->x;
  v16 = desLook->z;
  eye.x = desEye->x;
  if ( UFG::tbCollisionDisable )
    v9 = 0;
  v17 = this->mImpactShakeAmplitude == 0.0;
  v18 = LODWORD(desLook->y);
  eye.y = v11;
  v19 = dt;
  v20 = *vars0;
  v21 = vars0[1];
  loook.x = v15;
  up.x = v20;
  v22 = vars0[2];
  up.y = v21;
  up.z = v22;
  v23 = desEye->z;
  LODWORD(loook.y) = v18;
  eye.z = v23;
  loook.z = v16;
  if ( !v17 )
  {
    ((void (*)(void))this->vfptr[19].__vecDelDtor)();
    v24 = tanf(v23 * 0.5) * (float)(v14->mImpactShakeAmplitude * 1.6);
    v25 = UFG::qNoise<UFG::qVector3,float>::GetValue(&v14->mEyeImpactNoise, &result, v14->mImpactShakeTimer);
    v26 = v24 * v25->z;
    v27 = eye.y + (float)(v24 * v25->y);
    v28 = v14->mImpactShakeSeed;
    eye.x = eye.x + (float)(v24 * v25->x);
    v29 = v28 + v14->mImpactShakeTimer;
    eye.y = v27;
    eye.z = eye.z + v26;
    v30 = UFG::qNoise<UFG::qVector3,float>::GetValue(&v14->mLookImpactNoise, &result, v29);
    v18 = LODWORD(loook.y);
    v31 = v24 * v30->x;
    v32 = v24 * v30->y;
    v33 = v24 * v30->z;
    v11 = eye.y;
    v10 = eye.x;
    v15 = loook.x + v31;
    *(float *)&v18 = loook.y + v32;
    v16 = loook.z + v33;
    loook.x = loook.x + v31;
    loook.y = loook.y + v32;
    loook.z = loook.z + v33;
  }
  v14->mInCollision = 0;
  v34 = UFG::qVector3::msZero.z;
  v35 = UFG::qVector3::msZero.x;
  v14->mCollisionLookOffset.y = UFG::qVector3::msZero.y;
  v14->mCollisionLookOffset.z = v34;
  v14->mCollisionLookOffset.x = v35;
  if ( v9 )
  {
    v41 = v13->y;
    v42 = v13->z;
    v114 = a5;
    v14->mCandidateEye.x = v13->x;
    v14->mCandidateEye.y = v41;
    v14->mCandidateEye.z = v42;
    v14->mLookModified = 0;
    if ( v14->mAlternateLookValid )
    {
      if ( UFG::BasePhysicsSystem::CastShape(
             UFG::BasePhysicsSystem::mInstance,
             v14->pCollisionCollectorTargetPoints,
             &v14->mAlternateLook,
             &loook)
        && (v43 = (float *)UFG::GameCameraComponent::FindClosestCollidableHit(
                             v14,
                             v14->pCollisionCollectorTargetPoints,
                             &v14->mAlternateLook,
                             0.0)) != 0i64 )
      {
        v44 = v14->pCollisionCollectorTargetPoints->mRadius;
        v45 = v44;
        v18 = LODWORD(v44);
        v16 = (float)(v44 * v43[9]) + v43[6];
        v15 = (float)(v45 * v43[7]) + v43[4];
        *(float *)&v18 = (float)(*(float *)&v18 * v43[8]) + v43[5];
        loook.z = v16;
        v46 = *(float *)&v18 - v12->y;
        v47 = v16 - v12->z;
        v14->mCollisionLookOffset.x = v15 - v12->x;
        v14->mCollisionLookOffset.y = v46;
        v14->mCollisionLookOffset.z = v47;
        v14->mLookModified = 1;
        loook.x = v15;
        LODWORD(loook.y) = v18;
      }
      else
      {
        v16 = loook.z;
        v18 = LODWORD(loook.y);
        v15 = loook.x;
      }
      v10 = eye.x;
      v11 = eye.y;
    }
    v48 = v16 - eye.z;
    v49 = v15 - v10;
    v50 = 0.0;
    *(float *)&v18 = *(float *)&v18 - v11;
    v51 = (__m128)v18;
    v51.m128_f32[0] = (float)((float)(*(float *)&v18 * *(float *)&v18) + (float)(v49 * v49)) + (float)(v48 * v48);
    if ( v51.m128_f32[0] <= 0.000099999997 )
    {
      v53 = *(float *)&FLOAT_1_0;
      v54 = 0.0;
      v55 = 0.0;
    }
    else
    {
      LODWORD(v50) = (unsigned __int128)_mm_sqrt_ps(v51);
      if ( v51.m128_f32[0] == 0.0 )
      {
        v53 = v49 * 0.0;
        v54 = *(float *)&v18 * 0.0;
        v55 = v48 * 0.0;
      }
      else
      {
        v52 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v51));
        v53 = v49 * v52;
        v54 = *(float *)&v18 * v52;
        v55 = v48 * v52;
      }
    }
    v56 = 0i64;
    if ( UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, v14->pCollisionCollector, &eye, &eye) )
      v56 = UFG::GameCameraComponent::FindClosestCollidableHit(v14, v14->pCollisionCollector, &eye, 0.0);
    v57 = 0.0;
    if ( (!UFG::GameCameraComponent::AnyTargetPointVisible(v14, &eye) || v56)
      && UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, v14->pCollisionCollector, &loook, &eye) )
    {
      v58 = UFG::GameCameraComponent::FindClosestCollidableHit(v14, v14->pCollisionCollector, &loook, v14->mSafeRadius);
      if ( v58 )
      {
        v59 = *(float *)&v58[2].mPrev;
        v60 = *((float *)&v58[2].mPrev + 1);
        v14->mCollisionSurfaceNormal.x = *((float *)&v58[1].mNext + 1);
        v14->mCollisionSurfaceNormal.y = v59;
        v14->mCollisionSurfaceNormal.z = v60;
        v61 = *((float *)&v58[1].mPrev + 1);
        v62 = *(float *)&v58[1].mNext;
        v63 = *(float *)&v58[1].mPrev;
        v14->mCollisionContactPosition.z = v62;
        v14->mCollisionContactPosition.y = v61;
        v14->mCollisionContactPosition.x = v63;
        v64 = (float)(UFG::trCollisionCastingRadius * v14->mCollisionSurfaceNormal.z) + v62;
        v65 = (__m128)LODWORD(eye.y);
        v66 = (float)(UFG::trCollisionCastingRadius * v14->mCollisionSurfaceNormal.y) + v61;
        v67 = eye.x
            - (float)((float)(UFG::trCollisionCastingRadius * v14->mCollisionSurfaceNormal.x)
                    + v14->mCollisionContactPosition.x);
        v65.m128_f32[0] = (float)((float)((float)(eye.y - v66) * (float)(eye.y - v66)) + (float)(v67 * v67))
                        + (float)((float)(eye.z - v64) * (float)(eye.z - v64));
        v57 = COERCE_FLOAT(_mm_sqrt_ps(v65)) / v50;
        if ( v57 > 1.0 )
          v57 = *(float *)&FLOAT_1_0;
        v14->mInCollision = 1;
      }
    }
    v14->mAllowCanOccludeCamera = v14->mInCollision == 0;
    if ( !v14->mEyePushValid )
    {
      v14->mEyePushPercent = 0.0;
      v14->mEyePushValid = 1;
    }
    v68 = &v14->mEyePushPercent;
    LODWORD(v69) = COERCE_UNSIGNED_INT(v57 - v14->mEyePushPercent) & _xmm;
    if ( UFG::tbCollisionForceSnap )
      *v68 = v57;
    if ( v57 <= *v68 )
    {
      v70 = UFG::trCollisionApproachRateFactorOut;
    }
    else
    {
      v70 = v14->mPushInOverrideRate;
      if ( v70 <= 0.0 )
        v70 = UFG::trCollisionApproachRateFactorIn;
    }
    UFG::qApproach(&v14->mEyePushPercent, v57, v70 * v69, v19);
    v71 = v50 * *v68;
    v72 = v14->mCollisionBlend + v14->mCollisionPlateau;
    v73 = v71 - (float)(v50 - v72);
    if ( v73 <= 0.0 )
      v73 = 0.0;
    if ( v73 >= v72 )
      v73 = v14->mCollisionBlend + v14->mCollisionPlateau;
    v74 = v14->mCollisionRise;
    v75 = v73 / v14->mCollisionBlend;
    if ( v75 >= 1.0 )
    {
      v76 = FLOAT_0_5;
    }
    else
    {
      v76 = FLOAT_0_5;
      v74 = (float)((float)(cosf((float)(v75 * 3.1415927) - 3.1415927) + 1.0) * 0.5) * v74;
    }
    v77 = v14->mEyePushRise;
    if ( v74 <= v77 )
      v78 = UFG::trCollisionEyeDropRate;
    else
      v78 = UFG::trCollisionEyeRiseRate;
    UFG::qApproach(&v14->mEyePushRise, v74, COERCE_FLOAT(COERCE_UNSIGNED_INT(v77 - v74) & _xmm) * v78, v19);
    v79 = FLOAT_0_050000001;
    v80 = v50 - v71;
    v81 = (float)((float)(v55 * v71) + eye.z) + v14->mEyePushRise;
    v82 = (float)(v53 * v71) + eye.x;
    v83 = (float)(v54 * v71) + eye.y;
    eye.z = (float)((float)(v55 * v71) + eye.z) + v14->mEyePushRise;
    eye.x = (float)(v53 * v71) + eye.x;
    eye.y = (float)(v54 * v71) + eye.y;
    if ( v80 >= 0.050000001 )
      v79 = v80;
    v84 = v53 * v79;
    v85 = v54 * v79;
    v86 = &aWaterExcludeBoxes[0].ymax;
    v87 = &aWaterExcludeBoxes[0].ymax;
    v88 = (float)(v55 * v79) + v81;
    loook.x = v82 + v84;
    loook.y = v83 + v85;
    loook.z = v88;
    while ( v82 >= *(v87 - 1) || v82 <= *(v87 - 3) || v83 >= *v87 || v83 <= *(v87 - 2) )
    {
      v87 += 4;
      if ( (signed __int64)v87 >= (signed __int64)&UFG::GameCameraComponent::mDofDamageDomain[3] )
      {
        if ( v81 < UFG::trCollisionWaterLevel )
        {
          v81 = UFG::trCollisionWaterLevel;
          LOBYTE(retaddr) = 1;
          eye.z = UFG::trCollisionWaterLevel;
          goto LABEL_67;
        }
        break;
      }
    }
    LOBYTE(retaddr) = 0;
LABEL_67:
    if ( v112 )
    {
      *v112 = v82;
      v112[1] = v83;
      v112[2] = v81;
    }
    if ( v114 )
    {
      *v114 = v82 + v84;
      v114[1] = v83 + v85;
      v114[2] = v88;
    }
    UFG::BaseCameraComponent::SetEyeLookUp((UFG::BaseCameraComponent *)&v14->vfptr, v19, &eye, &loook, &up);
    if ( UFG::tbCollisionDebugDraw )
    {
      v89 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      v90 = v14->mLookModified;
      v91 = "No";
      v92 = v89;
      v93 = "No";
      v94 = &UFG::qColour::White;
      if ( v90 )
        v93 = "Yes";
      if ( v90 )
        v94 = &UFG::qColour::Red;
      Render::DebugDrawContext::DrawTextA(v89, 240, 500, v94, "Look Modified : %s", v93);
      v95 = &UFG::qColour::White;
      if ( v14->mInCollision )
      {
        v91 = "Yes";
        if ( v14->mInCollision )
          v95 = &UFG::qColour::Red;
      }
      Render::DebugDrawContext::DrawTextA(v92, 240, 511, v95, "In Collision  : %s", v91);
      Render::DebugDrawContext::DrawTextA(v92, 240, 522, &UFG::qColour::White, "Collision Push: %f", v71);
      v96 = &UFG::qColour::White;
      v97 = v14->mEyePushRise;
      if ( v97 > 0.001 )
        v96 = &UFG::qColour::Red;
      Render::DebugDrawContext::DrawTextA(v92, 240, 533, v96, "Collision Rise: %f", v97);
      removePhantomWhenDone = *v68;
      v99 = &UFG::qColour::White;
      Render::DebugDrawContext::DrawTextA(
        v92,
        240,
        544,
        &UFG::qColour::White,
        "Push Percent  : %f",
        removePhantomWhenDone);
      Render::DebugDrawContext::DrawSphere(
        v92,
        centre,
        UFG::trCollisionTargetPointCastingRadius,
        &UFG::qColour::Blue,
        &UFG::qMatrix44::msIdentity,
        0i64);
      Render::DebugDrawContext::DrawSphere(
        v92,
        &loook,
        UFG::trCollisionTargetPointCastingRadius * 1.02,
        &UFG::qColour::White,
        &UFG::qMatrix44::msIdentity,
        0i64);
      Render::DebugDrawContext::DrawText(v92, centre, &UFG::qColour::Blue, "dL");
      Render::DebugDrawContext::DrawText(v92, &loook, &UFG::qColour::White, "  L");
      if ( v14->mAlternateLookValid )
      {
        Render::DebugDrawContext::DrawSphere(
          v92,
          &v14->mAlternateLook,
          UFG::trCollisionTargetPointCastingRadius * 0.98000002,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          0i64);
        Render::DebugDrawContext::DrawText(v92, &v14->mAlternateLook, &UFG::qColour::Green, "aL");
      }
      Render::DebugDrawContext::DrawSphere(
        v92,
        v13,
        UFG::trCollisionCastingRadius,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
      Render::DebugDrawContext::DrawSphere(
        v92,
        &eye,
        UFG::trCollisionCastingRadius * 1.02,
        &UFG::qColour::Yellow,
        &UFG::qMatrix44::msIdentity,
        0i64);
      Render::DebugDrawContext::DrawText(v92, v13, &UFG::qColour::Red, "dE");
      Render::DebugDrawContext::DrawText(v92, &eye, &UFG::qColour::Yellow, "  E");
      result.x = (float)(loook.x + eye.x) * v76;
      result.y = (float)(loook.y + eye.y) * v76;
      result.z = UFG::trCollisionWaterLevel;
      Render::DebugDrawContext::DrawCircle(
        v92,
        &result,
        &UFG::qVector3::msAxisY,
        3.0,
        &UFG::qColour::Blue,
        &UFG::qMatrix44::msIdentity,
        0i64);
      v100 = 0;
      do
      {
        Render::DebugDrawContext::DrawRect(
          v92,
          *(v86 - 3) + *(v86 - 1),
          *(v86 - 2) + *v86,
          *(v86 - 1) - *(v86 - 3),
          *v86 - *(v86 - 2),
          &UFG::qColour::Red);
        if ( eye.x < *(v86 - 1) && eye.x > *(v86 - 3) && eye.y < *v86 && eye.y > *(v86 - 2) )
          v100 = 1;
        v86 += 4;
      }
      while ( (signed __int64)v86 < (signed __int64)&UFG::GameCameraComponent::mDofDamageDomain[3] );
      v101 = "False";
      v102 = "False";
      v103 = &UFG::qColour::White;
      if ( v100 )
        v102 = "True";
      if ( v100 )
        v103 = &UFG::qColour::Red;
      Render::DebugDrawContext::DrawTextA(v92, 240, 555, v103, "Ignore Water Test: %s", v102);
      if ( (_BYTE)retaddr )
        v99 = &UFG::qColour::Red;
      if ( (_BYTE)retaddr )
        v101 = "True";
      Render::DebugDrawContext::DrawTextA(v92, 240, 566, v99, "DEye Below Water: %s", v101);
      v14 = v108;
    }
    *(_QWORD *)&v14->mCandidateEye.x = 0i64;
    v14->mCandidateEye.z = -100000.0;
  }
  else
  {
    v36 = &aWaterExcludeBoxes[0].ymax;
    while ( v10 >= *(v36 - 1) || v10 <= *(v36 - 3) || v11 >= *v36 || v11 <= *(v36 - 2) )
    {
      v36 += 4;
      if ( (signed __int64)v36 >= (signed __int64)&UFG::GameCameraComponent::mDofDamageDomain[3] )
      {
        if ( eye.z < UFG::trCollisionWaterLevel )
          eye.z = UFG::trCollisionWaterLevel;
        break;
      }
    }
    UFG::BaseCameraComponent::SetEyeLookUp((UFG::BaseCameraComponent *)&v14->vfptr, v19, &eye, &loook, &up);
    if ( v112 )
    {
      v37 = eye.y;
      *v112 = eye.x;
      v38 = eye.z;
      v112[1] = v37;
      v112[2] = v38;
    }
    if ( v113 )
    {
      v39 = loook.y;
      *v113 = loook.x;
      v40 = loook.z;
      v113[1] = v39;
      v113[2] = v40;
    }
  }
}

// File Line: 1525
// RVA: 0x3C39E0
char __fastcall UFG::GameCameraComponent::GetSurfaceNormal(UFG::qVector3 *surfNormal, hkpCollidable *collidable, unsigned int shapeKey)
{
  hkpCollidable *v3; // rdi
  UFG::qVector3 *v4; // rsi
  hkpShape *v5; // rax
  char result; // al
  unsigned __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rbx
  hkVector4f *v10; // rcx
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm2
  hkVector4f v13; // xmm3
  float v14; // xmm4_4
  float v15; // xmm9_4
  float v16; // xmm5_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  float v20; // ST24_4
  float v21; // ST20_4
  float v22; // xmm14_4
  float v23; // xmm9_4
  float v24; // xmm0_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float d; // [rsp+30h] [rbp-2F8h]
  float v28; // [rsp+34h] [rbp-2F4h]
  float v29; // [rsp+38h] [rbp-2F0h]
  float v30; // [rsp+40h] [rbp-2E8h]
  float v31; // [rsp+44h] [rbp-2E4h]
  float v32; // [rsp+48h] [rbp-2E0h]
  float v33; // [rsp+50h] [rbp-2D8h]
  float v34; // [rsp+54h] [rbp-2D4h]
  float v35; // [rsp+58h] [rbp-2D0h]
  float v36; // [rsp+60h] [rbp-2C8h]
  float v37; // [rsp+64h] [rbp-2C4h]
  float v38; // [rsp+68h] [rbp-2C0h]
  hkTransformf v39; // [rsp+70h] [rbp-2B8h]
  char v40; // [rsp+B0h] [rbp-278h]
  float v41; // [rsp+338h] [rbp+10h]
  float v42; // [rsp+348h] [rbp+20h]

  v3 = collidable;
  v4 = surfNormal;
  if ( !collidable )
    return 0;
  if ( shapeKey == -1 )
    return 0;
  v5 = collidable->m_shape;
  if ( !collidable->m_shape )
    return 0;
  if ( v5->m_type.m_storage != 9 )
    return 0;
  v7 = v5[2].m_userData;
  if ( !v7 || *(_BYTE *)(v7 + 41) != 1 )
    return 0;
  v8 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, char *))(*(_QWORD *)(v7 + 32) + 40i64))(
         v7 + 32,
         shapeKey,
         &v40);
  v9 = v8;
  if ( !v8 || *(_BYTE *)(v8 + 16) != 2 )
    return 0;
  v10 = (hkVector4f *)v3->m_motion;
  v11.m_quad = (__m128)v10[1];
  v12.m_quad = (__m128)v10[2];
  v13.m_quad = (__m128)v10[3];
  v39.m_rotation.m_col0 = (hkVector4f)v10->m_quad;
  v39.m_rotation.m_col1 = (hkVector4f)v11.m_quad;
  v39.m_rotation.m_col2 = (hkVector4f)v12.m_quad;
  v39.m_translation = (hkVector4f)v13.m_quad;
  hkTransformf::get4x4ColumnMajor(&v39, &d);
  v13.m_quad.m128_i32[0] = *(_DWORD *)(v9 + 48);
  v12.m_quad.m128_i32[0] = *(_DWORD *)(v9 + 52);
  v14 = *(float *)(v9 + 56);
  v15 = v32 * v12.m_quad.m128_f32[0];
  v41 = (float)((float)((float)(v30 * v12.m_quad.m128_f32[0]) + (float)(d * v13.m_quad.m128_f32[0])) + (float)(v33 * v14))
      + v36;
  v16 = v31 * v12.m_quad.m128_f32[0];
  v12.m_quad.m128_i32[0] = *(_DWORD *)(v9 + 68);
  v17 = (float)(v16 + (float)(v28 * v13.m_quad.m128_f32[0])) + (float)(v34 * v14);
  v18 = v29 * v13.m_quad.m128_f32[0];
  v13.m_quad.m128_i32[0] = *(_DWORD *)(v9 + 64);
  v11.m_quad.m128_f32[0] = v35 * v14;
  v19 = *(float *)(v9 + 72);
  v20 = (float)((float)(v15 + v18) + v11.m_quad.m128_f32[0]) + v38;
  v21 = (float)((float)((float)(v30 * v12.m_quad.m128_f32[0]) + (float)(d * v13.m_quad.m128_f32[0])) + (float)(v33 * v19))
      + v36;
  v22 = (float)((float)((float)((float)(v31 * v12.m_quad.m128_f32[0]) + (float)(v28 * v13.m_quad.m128_f32[0]))
                      + (float)(v34 * v19))
              + v37)
      - (float)(v17 + v37);
  v23 = v32 * v12.m_quad.m128_f32[0];
  v12.m_quad.m128_i32[0] = *(_DWORD *)(v9 + 88);
  result = 1;
  v24 = *(float *)(v9 + 84);
  v11.m_quad.m128_i32[0] = *(_DWORD *)(v9 + 80);
  v25 = (float)((float)((float)(v23 + (float)(v29 * v13.m_quad.m128_f32[0])) + (float)(v35 * v19)) + v38) - v20;
  v42 = (float)((float)((float)(v30 * v24) + (float)(d * v11.m_quad.m128_f32[0])) + (float)(v33 * v12.m_quad.m128_f32[0]))
      + v36;
  v26 = (float)((float)((float)((float)(v31 * v24) + (float)(v28 * v11.m_quad.m128_f32[0]))
                      + (float)(v34 * v12.m_quad.m128_f32[0]))
              + v37)
      - (float)(v17 + v37);
  v13.m_quad.m128_f32[0] = (float)((float)((float)((float)(v32 * v24) + (float)(v29 * v11.m_quad.m128_f32[0]))
                                         + (float)(v35 * v12.m_quad.m128_f32[0]))
                                 + v38)
                         - v20;
  v4->x = (float)(v22 * v13.m_quad.m128_f32[0]) - (float)(v25 * v26);
  v4->z = (float)((float)(v21 - v41) * v26) - (float)(v22 * (float)(v42 - v41));
  v4->y = (float)(v25 * (float)(v42 - v41)) - (float)((float)(v21 - v41) * v13.m_quad.m128_f32[0]);
  return result;
}

// File Line: 1581
// RVA: 0x3CD680
char __fastcall UFG::GameCameraComponent::ShouldPassThru(UFG::GameCameraComponent *this, UFG::ShapeCasterCollector::HitInfo *info, UFG::qVector3 *startPos)
{
  UFG::qVector3 *v3; // r14
  UFG::ShapeCasterCollector::HitInfo *v4; // rbx
  UFG::GameCameraComponent *v5; // rdi
  hkpRigidBody *v6; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  UFG::qReflectObject *v9; // rax
  __int128 v10; // xmm1
  __int128 v11; // xmm2
  __int128 v12; // xmm3
  __int64 v13; // r8
  __m128 v14; // xmm1
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  UFG::SimObjectCharacter *v18; // rbx
  unsigned __int16 v19; // cx
  UFG::TargetingSystemItemComponent *v20; // rax
  unsigned __int16 v21; // cx
  UFG::CharacterSubjectComponent *v22; // rax
  UFG::SimObjectCharacter *v23; // rax
  UFG::SimObjectCharacter *v24; // rax
  char v25; // bl
  UFG::qVector3 surfNormal; // [rsp+20h] [rbp-D8h]
  __m128 v28; // [rsp+30h] [rbp-C8h]
  __m128 v29; // [rsp+40h] [rbp-B8h]
  UFG::qReflectHandleBase v30; // [rsp+50h] [rbp-A8h]
  hkVector4f v31; // [rsp+78h] [rbp-80h]
  __int128 v32; // [rsp+88h] [rbp-70h]
  __int128 v33; // [rsp+98h] [rbp-60h]
  __int128 v34; // [rsp+A8h] [rbp-50h]
  hkpRigidBodyCinfo infoa; // [rsp+B8h] [rbp-40h]

  v31.m_quad.m128_u64[0] = -2i64;
  v3 = startPos;
  v4 = info;
  v5 = this;
  if ( info )
  {
    v6 = info->mRigidBody;
    if ( v6 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v30);
      v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
      v30.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v30, v30.mTypeUID, v4->mPhysicsObjectPropertyHandleUID);
      v9 = v30.mData;
      if ( !v30.mData )
        goto LABEL_54;
      if ( BYTE5(v30.mData[1].mHandles.mNode.mPrev) )
      {
        if ( BYTE6(v30.mData[1].mHandles.mNode.mPrev) && v5->mAllowCanOccludeCamera )
        {
          hkpRigidBodyCinfo::hkpRigidBodyCinfo(&infoa);
          hkpRigidBody::getCinfo(v6, &infoa);
          v10 = (__int128)v6->m_motion.m_motionState.m_transform.m_rotation.m_col1;
          v11 = (__int128)v6->m_motion.m_motionState.m_transform.m_rotation.m_col2;
          v12 = (__int128)v6->m_motion.m_motionState.m_transform.m_translation;
          v31.m_quad = (__m128)v6->m_motion.m_motionState.m_transform.m_rotation.m_col0;
          v32 = v10;
          v33 = v11;
          v34 = v12;
          ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))infoa.m_shape->vfptr[2].__vecDelDtor)(
            infoa.m_shape,
            &v31,
            v13,
            &v28);
          v14 = _mm_shuffle_ps(
                  (__m128)LODWORD(UFG::gCanOccludeTolerance),
                  (__m128)LODWORD(UFG::gCanOccludeTolerance),
                  0);
          v29 = _mm_add_ps(v29, v14);
          v28 = _mm_sub_ps(v28, v14);
          v15 = v5->mCandidateEye.x;
          if ( v15 < v28.m128_f32[0] )
            goto LABEL_48;
          if ( v15 > v29.m128_f32[0] )
            goto LABEL_48;
          v16 = v5->mCandidateEye.y;
          if ( v16 < v28.m128_f32[1] )
            goto LABEL_48;
          if ( v16 > v29.m128_f32[1] )
            goto LABEL_48;
          v17 = v5->mCandidateEye.z;
          if ( v17 < v28.m128_f32[2] || v17 > v29.m128_f32[2] )
            goto LABEL_48;
          v9 = v30.mData;
        }
        if ( !BYTE1(v9[2].vfptr)
          || !UFG::GameCameraComponent::GetSurfaceNormal(&surfNormal, v4->mCollidableB, v4->mShapeKeyB)
          || (float)((float)((float)(surfNormal.x * (float)(v3->x - v4->mContactPosition.x))
                           + (float)(surfNormal.y * (float)(v3->y - v4->mContactPosition.y)))
                   + (float)(surfNormal.z * (float)(v3->z - v4->mContactPosition.z))) >= 0.0 )
        {
LABEL_54:
          v18 = (UFG::SimObjectCharacter *)v4->mSimObject;
          if ( !v18
            || ((v19 = v18->m_Flags, !((v19 >> 14) & 1)) ? ((v19 & 0x8000u) == 0 ? (!((v19 >> 13) & 1) ? (!((v19 >> 12) & 1) ? (v20 = (UFG::TargetingSystemItemComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v18->vfptr, UFG::TargetingSystemItemComponent::_TypeUID)) : (v20 = (UFG::TargetingSystemItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v18->vfptr, UFG::TargetingSystemItemComponent::_TypeUID))) : (v20 = (UFG::TargetingSystemItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v18->vfptr, UFG::TargetingSystemItemComponent::_TypeUID))) : (v20 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemItemComponent>((UFG::SimObjectCVBase *)&v18->vfptr))) : (v20 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemItemComponent>((UFG::SimObjectCVBase *)&v18->vfptr)),
                !v20
             && ((v21 = v18->m_Flags, !((v21 >> 14) & 1)) ? ((v21 & 0x8000u) == 0 ? (!((v21 >> 13) & 1) ? (!((v21 >> 12) & 1) ? (v22 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v18->vfptr, UFG::CharacterSubjectComponent::_TypeUID)) : (v22 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v18->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v22 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v18->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v22 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v18->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v22 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(v18)),
                 !v22)) )
          {
            if ( (!UFG::GameCameraComponent::mCollisionIgnoreAllCharacters || !v18 || !((v18->m_Flags >> 14) & 1))
              && (!UFG::GameCameraComponent::mCollisionIgnoreAllVehicles || !v18 || (v18->m_Flags & 0x8000u) == 0) )
            {
              v23 = (UFG::SimObjectCharacter *)v5->pSimObjectPassThru1;
              if ( !v23 || v18 != v23 )
              {
                v24 = (UFG::SimObjectCharacter *)v5->pSimObjectPassThru2;
                if ( !v24 || v18 != v24 )
                {
                  v25 = 0;
                  goto LABEL_50;
                }
              }
            }
          }
        }
      }
LABEL_48:
      v25 = 1;
LABEL_50:
      UFG::qReflectHandleBase::~qReflectHandleBase(&v30);
      return v25;
    }
  }
  return 0;
}

// File Line: 1688
// RVA: 0x14BFF40
__int64 dynamic_initializer_for__UFG::GameSubject::s_GameSubjectList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::GameSubject::s_GameSubjectList__);
}

// File Line: 1689
// RVA: 0x3C3F00
signed __int64 __fastcall UFG::CopRoadBlock::GetTypeSize(UFG::GameSubject *this)
{
  return 304i64;
}

// File Line: 1694
// RVA: 0x3BCC30
void __fastcall UFG::GameSubject::GameSubject(UFG::GameSubject *this, unsigned int name_uid)
{
  UFG::GameSubject *v2; // rbx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v3; // rcx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraSubject::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->pTransformNodeComponent);
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::CameraSubject::_CameraSubjectTypeUID,
    "CameraSubject");
  UFG::CameraSubject::Init((UFG::CameraSubject *)&v2->vfptr);
  v3 = (UFG::qNode<UFG::GameSubject,UFG::GameSubject> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameSubject::`vftable;
  v4 = UFG::GameSubject::s_GameSubjectList.mNode.mPrev;
  UFG::GameSubject::s_GameSubjectList.mNode.mPrev->mNext = (UFG::qNode<UFG::GameSubject,UFG::GameSubject> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::GameSubject,UFG::GameSubject> *)&UFG::GameSubject::s_GameSubjectList;
  UFG::GameSubject::s_GameSubjectList.mNode.mPrev = (UFG::qNode<UFG::GameSubject,UFG::GameSubject> *)&v2->mPrev;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v2->vfptr, UFG::GameSubject::_GameSubjectTypeUID, "GameSubject");
}

// File Line: 1701
// RVA: 0x3BDF60
void __fastcall UFG::GameSubject::~GameSubject(UFG::GameSubject *this)
{
  UFG::GameSubject *v1; // rbx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v2; // rdx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v3; // rcx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v4; // rax
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v5; // rcx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameSubject::`vftable;
  if ( this == UFG::GameSubject::s_GameSubjectpCurrentIterator )
    UFG::GameSubject::s_GameSubjectpCurrentIterator = (UFG::GameSubject *)&this->mPrev[-18];
  v2 = (UFG::qNode<UFG::GameSubject,UFG::GameSubject> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraSubject::`vftable;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->pTransformNodeComponent);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 1717
// RVA: 0x3C81E0
UFG::SimComponent *__fastcall UFG::GameSubject::PropertiesOnActivate(UFG::SceneObjectProperties *scene_object_properties)
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
  v4 = UFG::qMemoryPool::Allocate(v3, 0x130ui64, "GameSubject", 0i64, 1u);
  if ( v4 )
  {
    UFG::GameSubject::GameSubject((UFG::GameSubject *)v4, v2);
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

// File Line: 1725
// RVA: 0x3D8560
void __fastcall UFG::GameSubject::UpdateAll(float delta_sec)
{
  UFG::CameraSubject *v1; // rcx
  UFG::qList<UFG::GameSubject,UFG::GameSubject,1,0> *v2; // rbx

  v1 = (UFG::CameraSubject *)&UFG::GameSubject::s_GameSubjectList.mNode.mNext[-18];
  if ( (UFG::qList<UFG::GameSubject,UFG::GameSubject,1,0> *)&UFG::GameSubject::s_GameSubjectList.mNode.mNext[-18] != &UFG::GameSubject::s_GameSubjectList - 18 )
  {
    do
    {
      v2 = (UFG::qList<UFG::GameSubject,UFG::GameSubject,1,0> *)&v1[1].m_SafePointerList.mNode.mPrev[-18];
      UFG::CameraSubject::UpdateBase(v1, delta_sec, UFG::bCameraDebugDraw, &UFG::gCameraSubjectUpdateParams);
      v1 = (UFG::CameraSubject *)v2;
    }
    while ( v2 != &UFG::GameSubject::s_GameSubjectList - 18 );
  }
}

