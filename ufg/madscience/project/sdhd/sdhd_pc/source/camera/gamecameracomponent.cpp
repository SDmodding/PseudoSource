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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GameCameraComponent::mDofFocusDist__);
}

// File Line: 154
// RVA: 0x14BFE20
__int64 dynamic_initializer_for__UFG::GameCameraComponent::mDynamicDofParams__()
{
  `eh vector constructor iterator(
    (char *)&UFG::GameCameraComponent::mDynamicDofParams,
    0x4Cui64,
    6,
    (void (__fastcall *)(void *))UFG::GameCameraComponent::DynamicDofParam::DynamicDofParam);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GameCameraComponent::mDynamicDofParams__);
}

// File Line: 155
// RVA: 0x14BFE10
__int64 dynamic_initializer_for__UFG::GameCameraComponent::mDutchDyn__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GameCameraComponent::mDutchDyn__);
}

// File Line: 159
// RVA: 0x3BC3F0
void __fastcall UFG::GameCameraComponent::GameCameraComponent(UFG::GameCameraComponent *this, unsigned int name_uid)
{
  UFG::qNoise<float,float> *p_mDofNoise; // rsi
  int v4; // ebx
  float y; // xmm1_4
  float z; // xmm2_4
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
  __int64 nOctaves; // rax
  float v23; // xmm8_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  __int64 v26; // rax
  float v27; // xmm7_4
  float v28; // xmm1_4
  float v29; // xmm1_4
  int v30; // esi
  char *p_dest; // r14
  char *v32; // rsi
  UFG::qVector3 v33; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector3 v34; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 v35; // [rsp+50h] [rbp-88h] BYREF
  __int64 v36; // [rsp+60h] [rbp-78h]
  char dest; // [rsp+70h] [rbp-68h] BYREF
  char v38; // [rsp+548h] [rbp+470h] BYREF
  UFG::allocator::free_link *v39; // [rsp+AB8h] [rbp+9E0h]

  v36 = -2i64;
  UFG::BaseCameraComponent::BaseCameraComponent(this, name_uid);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameCameraComponent::`vftable;
  p_mDofNoise = &this->mDofNoise;
  UFG::qNoise<float,float>::qNoise<float,float>(&this->mDofNoise);
  this->mEyeImpactNoise.bCircular = 0;
  v35.x = 1.0;
  v35.y = 1.0;
  v35.z = 1.0;
  v33.x = -1.0;
  v33.y = -1.0;
  v33.z = -1.0;
  v34.x = 0.5;
  v34.y = 0.5;
  v34.z = 0.5;
  UFG::qNoise<UFG::qVector3,float>::SetParameters(&this->mEyeImpactNoise, 6, 1.0, &v34, &v33, &v35);
  UFG::qNoise<UFG::qVector3,float>::qNoise<UFG::qVector3,float>(&this->mLookImpactNoise);
  this->cAimWobbleRadius.mDuration = 0.0099999998;
  UFG::SimComponent::AddType(this, UFG::GameCameraComponent::_GameCameraComponentTypeUID, "GameCameraComponent");
  this->mResetNext = -1;
  *(_WORD *)&this->mInCollision = 0;
  v4 = 0;
  this->mPushInOverrideRate = 0.0;
  y = UFG::qVector3::msAxisZ.y;
  z = UFG::qVector3::msAxisZ.z;
  this->mCollisionSurfaceNormal.x = UFG::qVector3::msAxisZ.x;
  this->mCollisionSurfaceNormal.y = y;
  this->mCollisionSurfaceNormal.z = z;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  this->mCollisionContactPosition.x = UFG::qVector3::msZero.x;
  this->mCollisionContactPosition.y = v7;
  this->mCollisionContactPosition.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  this->mCollisionLookOffset.x = UFG::qVector3::msZero.x;
  this->mCollisionLookOffset.y = v9;
  this->mCollisionLookOffset.z = v10;
  *(_QWORD *)&this->mSafeRadius = 1065353216i64;
  strcpy((char *)&this->mCollisionBlend, "333?333?");
  BYTE1(this->mCollisionTargetPointsNum) = 0;
  HIWORD(this->mCollisionTargetPointsNum) = 0;
  UFG::qMemSet(this->mCollisionTargetPoints, 0, 4u);
  v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
  v39 = v11;
  if ( v11 )
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)v11,
      UFG::trCollisionTargetPointCastingRadius,
      0x12u,
      PhantomBehaviour_Simple);
  else
    v12 = 0i64;
  this->pCollisionCollectorTargetPoints = v12;
  v13 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
  v39 = v13;
  if ( v13 )
    UFG::ShapeCasterCollector::ShapeCasterCollector(
      (UFG::ShapeCasterCollector *)v13,
      UFG::trCollisionCastingRadius,
      0x12u,
      PhantomBehaviour_Simple);
  else
    v14 = 0i64;
  this->pCollisionCollector = v14;
  this->mCollisionTargetPointCastingRadiusSubmitted = UFG::trCollisionTargetPointCastingRadius;
  this->mCollisionCastingRadiusSubmitted = UFG::trCollisionCastingRadius;
  this->mAlternateLookValid = 0;
  v15 = UFG::qVector3::msZero.y;
  v16 = UFG::qVector3::msZero.z;
  this->mAlternateLook.x = UFG::qVector3::msZero.x;
  this->mAlternateLook.y = v15;
  this->mAlternateLook.z = v16;
  this->mEyePushValid = 0;
  *(_QWORD *)&this->mEyePushPercent = 0i64;
  this->mAllowCanOccludeCamera = 1;
  v17 = UFG::qVector3::msZero.y;
  v18 = UFG::qVector3::msZero.z;
  this->mCandidateEye.x = UFG::qVector3::msZero.x;
  this->mCandidateEye.y = v17;
  this->mCandidateEye.z = v18;
  this->pSimObjectPassThru1 = 0i64;
  this->pSimObjectPassThru2 = 0i64;
  *(_QWORD *)&this->mDofNoiseTimer = 0i64;
  this->mDofNoiseAmplitudeDecay = 2.0;
  this->mDofNoise.tRangeMin = -1.0;
  this->mDofNoise.tRangeMax = 1.0;
  v19 = 0.0;
  v20 = 0.0;
  v21 = *(float *)&FLOAT_1_0;
  nOctaves = (unsigned int)this->mDofNoise.nOctaves;
  if ( (int)nOctaves > 0 )
  {
    do
    {
      v20 = v20 + v21;
      v21 = v21 * p_mDofNoise->tDecay;
      --nOctaves;
    }
    while ( nOctaves );
  }
  this->mDofNoise.tAmplitude = 1.0 / v20;
  v23 = FLOAT_0_000099999997;
  if ( COERCE_FLOAT((unsigned int)FLOAT_1_0 & _xmm) <= 0.000099999997 )
    v24 = FLOAT_0_000099999997;
  else
    LODWORD(v24) = (unsigned int)FLOAT_1_0 & _xmm;
  this->mDofNoise.tOffset = (float)((float)(1.0 / v24) * this->mDofNoise.tFrequency) * this->mDofNoise.tOffset;
  LODWORD(this->mDofNoise.tFrequency) = (unsigned int)FLOAT_1_0 & _xmm;
  v25 = *(float *)&FLOAT_1_0;
  v26 = (unsigned int)this->mDofNoise.nOctaves;
  if ( (int)v26 > 0 )
  {
    do
    {
      v19 = v19 + v25;
      v25 = v25 * p_mDofNoise->tDecay;
      --v26;
    }
    while ( v26 );
  }
  this->mDofNoise.tAmplitude = 1.0 / v19;
  LODWORD(v27) = LODWORD(FLOAT_15_0) & _xmm;
  if ( COERCE_FLOAT(LODWORD(FLOAT_15_0) & _xmm) <= 0.000099999997 )
    v28 = FLOAT_0_000099999997;
  else
    LODWORD(v28) = LODWORD(FLOAT_15_0) & _xmm;
  this->mEyeImpactNoise.tOffset = (float)((float)(1.0 / v28) * this->mEyeImpactNoise.tFrequency)
                                * this->mEyeImpactNoise.tOffset;
  this->mEyeImpactNoise.tFrequency = v27;
  UFG::qNoise<UFG::qVector3,float>::Init(&this->mEyeImpactNoise);
  if ( v27 > 0.000099999997 )
    LODWORD(v23) = LODWORD(FLOAT_15_0) & _xmm;
  this->mLookImpactNoise.tOffset = (float)((float)(1.0 / v23) * this->mLookImpactNoise.tFrequency)
                                 * this->mLookImpactNoise.tOffset;
  this->mLookImpactNoise.tFrequency = v27;
  UFG::qNoise<UFG::qVector3,float>::Init(&this->mLookImpactNoise);
  v34.x = 0.2;
  v34.y = 0.2;
  v34.z = 0.2;
  v33.x = -0.2;
  v33.y = -0.2;
  v33.z = -0.2;
  UFG::qNoise<UFG::qVector3,float>::SetRange(&this->mEyeImpactNoise, &v33, &v34);
  v34.x = 0.1;
  v34.y = 0.1;
  v34.z = 0.1;
  v33.x = -0.1;
  v33.y = -0.1;
  v33.z = -0.1;
  UFG::qNoise<UFG::qVector3,float>::SetRange(&this->mLookImpactNoise, &v33, &v34);
  v29 = UFG::qVector2::msZero.y;
  this->mAimWobble.x = UFG::qVector2::msZero.x;
  this->mAimWobble.y = v29;
  *(_QWORD *)&this->cAimWobbleRadius.mDuration = 1065353216i64;
  *(_QWORD *)&this->cAimWobbleRadius.v0 = 0i64;
  *(_QWORD *)&this->cAimWobbleRadius.p0 = 0i64;
  UFG::HomerCubic<float>::MakeCoeffs(&this->cAimWobbleRadius);
  UFG::GameCameraComponent::ResetAimWobble(this);
  *(_QWORD *)&this->mImpactShakeSeed = 0i64;
  this->mImpactShakeAmplitude = 0.0;
  this->mImpactShakeAmplitudeDecay = 8.0;
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
  p_dest = &dest;
  do
  {
    UFG::qSPrintf(p_dest, "\\Camera\\Damage FX\\Damage %d", (unsigned int)v30++);
    p_dest += 256;
  }
  while ( v30 < 5 );
  v32 = &v38;
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
  UFG::ShapeCasterCollector *pCollisionCollector; // rcx
  UFG::ShapeCasterCollector *pCollisionCollectorTargetPoints; // rcx
  UFG::GameCameraComponent *mCurrentCamera; // rcx
  UFG::Director *v5; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameCameraComponent::`vftable;
  if ( this->mActive )
    this->mActive = 0;
  pCollisionCollector = this->pCollisionCollector;
  if ( pCollisionCollector )
    pCollisionCollector->vfptr->__vecDelDtor(pCollisionCollector, 1u);
  pCollisionCollectorTargetPoints = this->pCollisionCollectorTargetPoints;
  if ( pCollisionCollectorTargetPoints )
    pCollisionCollectorTargetPoints->vfptr->__vecDelDtor(pCollisionCollectorTargetPoints, 1u);
  mCurrentCamera = (UFG::GameCameraComponent *)UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    mCurrentCamera = (UFG::GameCameraComponent *)((char *)mCurrentCamera + 80);
  if ( mCurrentCamera == (UFG::GameCameraComponent *)&this->mCamera )
  {
    v5 = UFG::Director::Get();
    UFG::Director::SetCurrentCamera(v5, 0i64);
  }
  UFG::BaseCameraComponent::~BaseCameraComponent(this);
}

// File Line: 343
// RVA: 0x3C89C0
void __fastcall UFG::GameCameraComponent::Reset(UFG::GameCameraComponent *this)
{
  float z; // xmm2_4
  float x; // xmm0_4

  this->mAllowCanOccludeCamera = 1;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->mCollisionLookOffset.y = UFG::qVector3::msZero.y;
  this->mCollisionLookOffset.z = z;
  this->mCollisionLookOffset.x = x;
  UFG::BaseCameraComponent::Reset(this);
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
  UFG::HomerCubic<float> *p_cAimWobbleRadius; // rbx
  float v2; // xmm0_4
  float rAimWobbleRadiusPeriod; // xmm1_4

  this->rAimWobbleRadiusMin = 0.0020000001;
  this->rAimWobbleRadiusMax = 0.003;
  this->rAimWobbleRadiusPeriod = 5.5;
  this->rAimWobbleFreq = 2.2;
  this->rAimWobbleAxisWeight = 0.27500001;
  *(_WORD *)&this->bAimWobbleHoldingBreathInput = 0;
  this->rAimWobbleHoldBreathMultiplier = 1.0;
  p_cAimWobbleRadius = &this->cAimWobbleRadius;
  *(_QWORD *)&this->rAimWobbleOverallScale = 0i64;
  *(_QWORD *)&this->rAimWobbleHoldBreathElapsedTime = 0i64;
  v2 = this->cAimWobbleRadius.mParameter / this->cAimWobbleRadius.mDuration;
  this->cAimWobbleRadius.mParameter = v2;
  rAimWobbleRadiusPeriod = this->rAimWobbleRadiusPeriod;
  if ( rAimWobbleRadiusPeriod <= 0.0099999998 )
    rAimWobbleRadiusPeriod = FLOAT_0_0099999998;
  p_cAimWobbleRadius->mDuration = rAimWobbleRadiusPeriod;
  this->cAimWobbleRadius.mParameter = rAimWobbleRadiusPeriod * v2;
  UFG::HomerCubic<float>::MakeCoeffs(&this->cAimWobbleRadius);
  p_cAimWobbleRadius->p1 = 0.0;
  UFG::HomerCubic<float>::MakeCoeffs(p_cAimWobbleRadius);
  p_cAimWobbleRadius->mParameter = 0.0;
  p_cAimWobbleRadius->p0 = p_cAimWobbleRadius->p1;
  p_cAimWobbleRadius->v0 = p_cAimWobbleRadius->v1;
  UFG::HomerCubic<float>::MakeCoeffs(p_cAimWobbleRadius);
  p_cAimWobbleRadius->mParameter = 0.0;
}

// File Line: 408
// RVA: 0x3D5E00
void __fastcall UFG::GameCameraComponent::Update(UFG::GameCameraComponent *this, float delta_seconds)
{
  float v3; // xmm2_4
  float v4; // xmm2_4
  float v5; // xmm9_4
  UFG::ShapeCasterCollector *v6; // rdi
  UFG::ShapeCasterCollector *pCollisionCollectorTargetPoints; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::ShapeCasterCollector *v9; // rax
  UFG::ShapeCasterCollector *pCollisionCollector; // rcx
  UFG::allocator::free_link *v11; // rax
  UFG::ShapeCasterCollector *v12; // rax
  float v13; // xmm15_4
  float v14; // xmm13_4
  float v15; // xmm8_4
  float v16; // xmm6_4
  float v17; // xmm11_4
  float v18; // xmm12_4
  float v19; // xmm3_4
  float mDuration; // xmm5_4
  float v21; // xmm3_4
  float A; // xmm4_4
  float B; // xmm14_4
  float C; // xmm2_4
  float v25; // xmm9_4
  float v26; // xmm0_4
  float p0; // xmm6_4
  float v28; // xmm3_4
  float v29; // [rsp+F0h] [rbp+8h]
  float v30; // [rsp+100h] [rbp+18h]

  UFG::BaseCameraComponent::Update(this, delta_seconds);
  v3 = 1.0 - (float)(delta_seconds * this->mImpactShakeAmplitudeDecay);
  if ( v3 < 0.0 )
    v3 = 0.0;
  v4 = v3 * this->mImpactShakeAmplitude;
  this->mImpactShakeAmplitude = v4;
  v5 = FLOAT_0_0099999998;
  if ( v4 > 0.0099999998 )
    this->mImpactShakeTimer = delta_seconds + this->mImpactShakeTimer;
  UFG::GameCameraComponent::mNoRotationTimer = UFG::GameCameraComponent::mNoRotationTimer - delta_seconds;
  if ( UFG::GameCameraComponent::mNoRotationTimer < 0.0 )
    UFG::GameCameraComponent::mNoRotationTimer = 0.0;
  UFG::GameCameraComponent::UpdateAimWobble(this, delta_seconds);
  v6 = 0i64;
  if ( UFG::trCollisionTargetPointCastingRadius != this->mCollisionTargetPointCastingRadiusSubmitted )
  {
    pCollisionCollectorTargetPoints = this->pCollisionCollectorTargetPoints;
    if ( pCollisionCollectorTargetPoints )
      pCollisionCollectorTargetPoints->vfptr->__vecDelDtor(pCollisionCollectorTargetPoints, 1u);
    v8 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
    if ( v8 )
      UFG::ShapeCasterCollector::ShapeCasterCollector(
        (UFG::ShapeCasterCollector *)v8,
        UFG::trCollisionTargetPointCastingRadius,
        0x12u,
        PhantomBehaviour_Simple);
    else
      v9 = 0i64;
    this->pCollisionCollectorTargetPoints = v9;
    this->mCollisionTargetPointCastingRadiusSubmitted = UFG::trCollisionTargetPointCastingRadius;
  }
  if ( UFG::trCollisionCastingRadius != this->mCollisionCastingRadiusSubmitted )
  {
    pCollisionCollector = this->pCollisionCollector;
    if ( pCollisionCollector )
      pCollisionCollector->vfptr->__vecDelDtor(pCollisionCollector, 1u);
    v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x30ui64, "ShapeCasterCollector", 0i64, 1u);
    if ( v11 )
    {
      UFG::ShapeCasterCollector::ShapeCasterCollector(
        (UFG::ShapeCasterCollector *)v11,
        UFG::trCollisionCastingRadius,
        0x12u,
        PhantomBehaviour_Simple);
      v6 = v12;
    }
    this->pCollisionCollector = v6;
    this->mCollisionCastingRadiusSubmitted = UFG::trCollisionCastingRadius;
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
    mDuration = UFG::GameCameraComponent::mDynamicDutchTransitionDuration;
    if ( UFG::GameCameraComponent::mDynamicDutchTransitionDuration <= 0.0099999998 )
      mDuration = FLOAT_0_0099999998;
    UFG::GameCameraComponent::mDutchDyn.mDuration = mDuration;
    v21 = v19 * mDuration;
    UFG::GameCameraComponent::mDutchDyn.mParameter = v21;
    if ( mDuration > 0.0099999998 )
      v5 = mDuration;
    A = (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.v1 + UFG::GameCameraComponent::mDutchDyn.v0) * v5)
              + (float)((float)(UFG::GameCameraComponent::mDutchDyn.p0 - UFG::GameCameraComponent::mDutchDyn.p1) * 2.0))
      / (float)((float)(v5 * v5) * v5);
    UFG::GameCameraComponent::mDutchDyn.A = A;
    B = (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.p1 - UFG::GameCameraComponent::mDutchDyn.p0) * 3.0)
              - (float)((float)((float)(UFG::GameCameraComponent::mDutchDyn.v0 * 2.0)
                              + UFG::GameCameraComponent::mDutchDyn.v1)
                      * v5))
      / (float)(v5 * v5);
    UFG::GameCameraComponent::mDutchDyn.B = B;
    C = UFG::GameCameraComponent::mDutchDyn.v0;
    UFG::GameCameraComponent::mDutchDyn.C = UFG::GameCameraComponent::mDutchDyn.v0;
    UFG::GameCameraComponent::mDutchDyn.D = UFG::GameCameraComponent::mDutchDyn.p0;
    UFG::GameCameraComponent::mDynamicDutchCurElapsed = UFG::GameCameraComponent::mDynamicDutchCurElapsed
                                                      + delta_seconds;
    if ( UFG::GameCameraComponent::mDynamicDutchCurElapsed <= UFG::GameCameraComponent::mDynamicDutchCurDuration )
    {
      v25 = FLOAT_2_0;
      p0 = UFG::GameCameraComponent::mDutchDyn.p0;
    }
    else
    {
      UFG::GameCameraComponent::mDynamicDutchCurIsHigh = !UFG::GameCameraComponent::mDynamicDutchCurIsHigh;
      if ( !UFG::GameCameraComponent::mDynamicDutchCurIsHigh )
      {
        v13 = v29;
        v14 = v30;
      }
      v25 = FLOAT_2_0;
      v26 = UFG::qRandom(v14 * 2.0, (unsigned int *)&UFG::qDefaultSeed);
      UFG::GameCameraComponent::mDynamicDutchCurElapsed = 0.0;
      UFG::GameCameraComponent::mDynamicDutchCurDuration = (float)(v26 - v14) + v13;
      if ( !UFG::GameCameraComponent::mDynamicDutchCurIsHigh )
      {
        v15 = v17;
        v16 = v18;
      }
      UFG::GameCameraComponent::mDutchDyn.p1 = (float)(UFG::qRandom(v16 * 2.0, (unsigned int *)&UFG::qDefaultSeed) - v16)
                                             + v15;
      UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDutchDyn);
      v21 = 0.0;
      p0 = UFG::GameCameraComponent::mDutchDyn.D;
      C = UFG::GameCameraComponent::mDutchDyn.C;
      B = UFG::GameCameraComponent::mDutchDyn.B;
      A = UFG::GameCameraComponent::mDutchDyn.A;
      mDuration = UFG::GameCameraComponent::mDutchDyn.mDuration;
    }
    v28 = v21 + delta_seconds;
    if ( v28 <= 0.0 )
      v28 = 0.0;
    if ( v28 >= mDuration )
      v28 = mDuration;
    UFG::GameCameraComponent::mDutchDyn.mParameter = v28;
    UFG::GameCameraComponent::mDutchDyn.v0 = (float)((float)((float)((float)(A * 3.0) * v28) + (float)(B * v25)) * v28)
                                           + C;
    UFG::GameCameraComponent::mDutchDyn.p0 = (float)((float)((float)((float)((float)(A * v28) + B) * v28) + C) * v28)
                                           + p0;
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
  UFG::GameCameraComponent::mDynamicDutch = 0;
  UFG::GameCameraComponent::mDutchDyn.p1 = angle;
  UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDutchDyn);
  UFG::GameCameraComponent::mDutchDyn.mParameter = 0.0;
  if ( snap )
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
void __fastcall UFG::GameCameraComponent::SetDynamicDutch(
        float dur_high,
        float dur_dev_high,
        float ang_high,
        float ang_dev_high,
        float dur_low,
        float dur_dev_low,
        float ang_low,
        float ang_dev_low)
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
  bool bAimWobbleHoldingBreathInput; // al
  float rAimWobbleHoldBreathElapsedTime; // xmm1_4
  float v4; // xmm1_4

  bAimWobbleHoldingBreathInput = this->bAimWobbleHoldingBreathInput;
  if ( enable != bAimWobbleHoldingBreathInput )
  {
    if ( !enable
      || UFG::rtAimWobbleBreathRequiredTime >= this->rAimWobbleBreathElapsedTime
      || bAimWobbleHoldingBreathInput )
    {
      if ( this->bAimWobbleHoldingBreath )
      {
        rAimWobbleHoldBreathElapsedTime = this->rAimWobbleHoldBreathElapsedTime;
        this->bAimWobbleHoldingBreath = 0;
        v4 = rAimWobbleHoldBreathElapsedTime / UFG::rtAimWobbleHoldBreathMaxTime;
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
  float v5; // xmm0_4
  float v6; // xmm0_4
  float rAimWobbleHoldBreathElapsedTime; // xmm1_4
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float *p_rAimWobbleRadiusPeriod; // rax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float rAimWobbleRadiusMin; // xmm6_4
  float rAimWobbleRadiusMax; // xmm0_4
  float rAimWobbleAxisWeight; // xmm11_4
  float rAimWobbleFreq; // xmm10_4
  float v18; // xmm10_4
  float p0; // xmm6_4
  float v20; // xmm8_4
  float v21; // xmm0_4
  float rAimWobbleOverallScale; // xmm1_4
  float y; // xmm1_4

  v2 = !this->bAimWobbleHoldingBreath;
  this->rAimWobbleElapsedTime = dt + this->rAimWobbleElapsedTime;
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
  rAimWobbleHoldBreathElapsedTime = this->rAimWobbleHoldBreathElapsedTime;
  v8 = 0.0;
  if ( rAimWobbleHoldBreathElapsedTime > UFG::rtAimWobbleHoldBreathMaxTime )
  {
    this->bAimWobbleHoldingBreath = 0;
    v9 = rAimWobbleHoldBreathElapsedTime / UFG::rtAimWobbleHoldBreathMaxTime;
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
  UFG::qApproach(&this->rAimWobbleHoldBreathMultiplier, 1.0, UFG::rtAimWobbleMaxBreathDecayRate, dt);
  if ( this->bAimWobbleHoldingBreath )
  {
    v10 = UFG::trAimWobbleHoldBreathRate;
  }
  else
  {
    v10 = UFG::trAimWobbleReleaseBreathRate;
    v8 = *(float *)&FLOAT_1_0;
  }
  UFG::qApproach(&this->rAimWobbleOverallScale, v8, v10, dt);
  p_rAimWobbleRadiusPeriod = &UFG::trAimWobbleRadiusPeriod;
  if ( !UFG::tbAimWobbleUseTweakables )
    p_rAimWobbleRadiusPeriod = &this->rAimWobbleRadiusPeriod;
  v12 = this->cAimWobbleRadius.mParameter / this->cAimWobbleRadius.mDuration;
  this->cAimWobbleRadius.mParameter = v12;
  v13 = *p_rAimWobbleRadiusPeriod;
  if ( *p_rAimWobbleRadiusPeriod <= 0.0099999998 )
    v13 = FLOAT_0_0099999998;
  this->cAimWobbleRadius.mDuration = v13;
  this->cAimWobbleRadius.mParameter = v13 * v12;
  UFG::HomerCubic<float>::MakeCoeffs(&this->cAimWobbleRadius);
  UFG::HomerCubic<float>::Update(&this->cAimWobbleRadius, dt);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(this->cAimWobbleRadius.p1 - this->cAimWobbleRadius.p0) & _xmm) < 0.0000099999997 )
  {
    if ( UFG::tbAimWobbleUseTweakables )
    {
      rAimWobbleRadiusMin = UFG::trAimWobbleRadiusMin;
      rAimWobbleRadiusMax = UFG::trAimWobbleRadiusMax;
    }
    else
    {
      rAimWobbleRadiusMin = this->rAimWobbleRadiusMin;
      rAimWobbleRadiusMax = this->rAimWobbleRadiusMax;
    }
    this->cAimWobbleRadius.p1 = UFG::qRandom(
                                  rAimWobbleRadiusMax - rAimWobbleRadiusMin,
                                  (unsigned int *)&UFG::qDefaultSeed)
                              + rAimWobbleRadiusMin;
    UFG::HomerCubic<float>::MakeCoeffs(&this->cAimWobbleRadius);
    this->cAimWobbleRadius.mParameter = 0.0;
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::GameCameraComponent *))this->vfptr[37].__vecDelDtor)(this) )
  {
    if ( UFG::tbAimWobbleUseTweakables )
    {
      rAimWobbleAxisWeight = UFG::trAimWobbleAxisWeight;
      rAimWobbleFreq = UFG::trAimWobbleFreq;
    }
    else
    {
      rAimWobbleAxisWeight = this->rAimWobbleAxisWeight;
      rAimWobbleFreq = this->rAimWobbleFreq;
    }
    v18 = rAimWobbleFreq * this->rAimWobbleElapsedTime;
    p0 = this->cAimWobbleRadius.p0;
    v20 = (float)(sinf(v18) * (float)((float)(1.0 - rAimWobbleAxisWeight) * p0)) * this->rAimWobbleHoldBreathMultiplier;
    v21 = (float)(cosf(v18) * (float)(p0 * rAimWobbleAxisWeight)) * this->rAimWobbleHoldBreathMultiplier;
    this->mAimWobble.y = v20;
    this->mAimWobble.x = v21;
    rAimWobbleOverallScale = this->rAimWobbleOverallScale;
    this->mAimWobble.y = rAimWobbleOverallScale * v20;
    this->mAimWobble.x = rAimWobbleOverallScale * v21;
  }
  else
  {
    y = UFG::qVector2::msZero.y;
    this->mAimWobble.x = UFG::qVector2::msZero.x;
    this->mAimWobble.y = y;
  }
}

// File Line: 623
// RVA: 0x3BF110
void __fastcall UFG::GameCameraComponent::AddShakeAmplitude(UFG::GameCameraComponent *this, float shake)
{
  UFG::GameCameraComponent *CurrentGameCamera; // rax
  UFG::SimComponent *v4; // rbx

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  v4 = CurrentGameCamera;
  if ( (!CurrentGameCamera
     || !UFG::SimComponent::IsType(CurrentGameCamera, UFG::AnimatedCameraComponent::_AnimatedCameraComponentTypeUID)
     && !UFG::SimComponent::IsType(v4, UFG::ScriptCameraComponent::_ScriptCameraComponentTypeUID))
    && shake > this->mImpactShakeAmplitude )
  {
    this->mImpactShakeAmplitude = shake;
    this->mImpactShakeTimer = UFG::qRandom(511.0, (unsigned int *)&UFG::qDefaultSeed);
    this->mImpactShakeSeed = UFG::qRandom(511.0, (unsigned int *)&UFG::qDefaultSeed) + 511.0;
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
void __fastcall UFG::GameCameraComponent::BeginDOFOverride(
        float focalRange,
        float nearRange,
        float farRange,
        float nearBlur,
        float farBlur,
        UFG::GameCameraComponent::DOFOverridePriority priority)
{
  __int64 v6; // rcx

  v6 = 3i64 * (int)priority;
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
void __fastcall UFG::GameCameraComponent::UpdateDof(
        UFG::GameCameraComponent *this,
        float dt,
        float inFocusRange,
        float nearRange,
        float nearBlurRadius,
        float farRange,
        float farBlurRadius)
{
  float v8; // xmm7_4
  float v9; // xmm6_4
  Render::DepthOfField::Focus desDofParameters; // [rsp+20h] [rbp-68h] BYREF

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
  UFG::GameCameraComponent::UpdateDof(this, dt, &desDofParameters, 0);
}

// File Line: 770
// RVA: 0x3DB660
void __fastcall UFG::GameCameraComponent::UpdateDof(
        UFG::GameCameraComponent *this,
        float dt,
        Render::DepthOfField::Focus *desDofParameters,
        bool snap)
{
  float mInFocusRange; // xmm8_4
  float mNearRange; // xmm9_4
  float mNearBlurRadius; // xmm10_4
  float mFarRange; // xmm11_4
  float mFarBlurRadius; // xmm13_4
  float v13; // xmm6_4
  float v14; // xmm8_4
  float *p_mParameter; // rbx
  __int64 v16; // rbp
  float v17; // xmm0_4
  float v18; // xmm0_4
  bool v19; // cc
  bool v20; // al
  float v21; // xmm8_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  int v26; // xmm0_4
  float mDuration; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  float v32; // xmm8_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  int v40; // ecx
  _BYTE *v41; // rax
  float *v42; // rax
  float *v43; // rax
  float v44; // xmm3_4
  float v45; // xmm5_4
  float v46; // xmm3_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  float v49; // xmm4_4
  float v50; // xmm0_4
  float v51; // xmm6_4
  float v52; // xmm14_4
  float v53; // xmm0_4
  float mDofNoiseAmplitude; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm1_4
  float p0; // xmm6_4
  Render::DepthOfField::Focus focus; // [rsp+20h] [rbp-D8h] BYREF

  UFG::GameCameraComponent::mDofFocusDist.p1 = desDofParameters->mFocalDistance;
  UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDofFocusDist);
  UFG::GameCameraComponent::mDofFocusDist.mParameter = 0.0;
  mInFocusRange = desDofParameters->mInFocusRange;
  mNearRange = desDofParameters->mNearRange;
  mNearBlurRadius = desDofParameters->mNearBlurRadius;
  mFarRange = desDofParameters->mFarRange;
  mFarBlurRadius = desDofParameters->mFarBlurRadius;
  v13 = FLOAT_0_0099999998;
  if ( UFG::GameCameraComponent::mDynamicDOF )
  {
    v14 = UFG::GameCameraComponent::mDynamicDOFTransitionDuration;
    p_mParameter = &UFG::GameCameraComponent::mDynamicDofParams.mParameter;
    v16 = 6i64;
    do
    {
      *p_mParameter = *p_mParameter / *(p_mParameter - 1);
      if ( v14 <= v13 )
        v17 = v13;
      else
        v17 = v14;
      *(p_mParameter - 1) = v17;
      *p_mParameter = v17 * *p_mParameter;
      UFG::HomerCubic<float>::MakeCoeffs((UFG::HomerCubic<float> *)(p_mParameter - 1));
      v18 = dt + p_mParameter[17];
      v19 = v18 <= p_mParameter[16];
      p_mParameter[17] = v18;
      if ( !v19 )
      {
        v20 = *((_BYTE *)p_mParameter + 60) == 0;
        *((_BYTE *)p_mParameter + 60) = v20;
        if ( v20 )
        {
          v21 = p_mParameter[9];
          v22 = p_mParameter[10];
        }
        else
        {
          v21 = p_mParameter[12];
          v22 = p_mParameter[13];
        }
        v23 = UFG::qRandom(v22 * 2.0, (unsigned int *)&UFG::qDefaultSeed);
        p_mParameter[17] = 0.0;
        v24 = v23 - v22;
        v13 = FLOAT_0_0099999998;
        v25 = v24 + v21;
        v14 = UFG::GameCameraComponent::mDynamicDOFTransitionDuration;
        p_mParameter[16] = v25;
      }
      if ( *((_BYTE *)p_mParameter + 60) )
        v26 = *((_DWORD *)p_mParameter + 11);
      else
        v26 = *((_DWORD *)p_mParameter + 14);
      *((_DWORD *)p_mParameter + 6) = v26;
      UFG::HomerCubic<float>::MakeCoeffs((UFG::HomerCubic<float> *)(p_mParameter - 1));
      *p_mParameter = 0.0;
      p_mParameter += 19;
      --v16;
    }
    while ( v16 );
    mDuration = UFG::GameCameraComponent::mDynamicDofParams.mParameter + dt;
    if ( (float)(UFG::GameCameraComponent::mDynamicDofParams.mParameter + dt) <= 0.0 )
      mDuration = 0.0;
    if ( mDuration >= UFG::GameCameraComponent::mDynamicDofParams.mDuration )
      mDuration = UFG::GameCameraComponent::mDynamicDofParams.mDuration;
    UFG::GameCameraComponent::mDynamicDofParams.mParameter = mDuration;
    v28 = (float)((float)((float)(UFG::GameCameraComponent::mDynamicDofParams.A * 3.0) * mDuration)
                + (float)(UFG::GameCameraComponent::mDynamicDofParams.B * 2.0))
        * mDuration;
    v29 = (float)((float)((float)((float)((float)(UFG::GameCameraComponent::mDynamicDofParams.A * mDuration)
                                        + UFG::GameCameraComponent::mDynamicDofParams.B)
                                * mDuration)
                        + UFG::GameCameraComponent::mDynamicDofParams.C)
                * mDuration)
        + UFG::GameCameraComponent::mDynamicDofParams.D;
    v30 = stru_1423D7CAC.mParameter + dt;
    UFG::GameCameraComponent::mDynamicDofParams.v0 = v28 + UFG::GameCameraComponent::mDynamicDofParams.C;
    UFG::GameCameraComponent::mDynamicDofParams.p0 = v29;
    if ( (float)(stru_1423D7CAC.mParameter + dt) <= 0.0 )
      v30 = 0.0;
    if ( v30 >= stru_1423D7CAC.mDuration )
      v30 = stru_1423D7CAC.mDuration;
    stru_1423D7CAC.mParameter = v30;
    v31 = (float)((float)((float)(stru_1423D7CAC.A * 3.0) * v30) + (float)(stru_1423D7CAC.B * 2.0)) * v30;
    v32 = (float)((float)((float)((float)((float)(stru_1423D7CAC.A * v30) + stru_1423D7CAC.B) * v30) + stru_1423D7CAC.C)
                * v30)
        + stru_1423D7CAC.D;
    v33 = stru_1423D7CF8.mParameter + dt;
    stru_1423D7CAC.v0 = v31 + stru_1423D7CAC.C;
    stru_1423D7CAC.p0 = v32;
    if ( (float)(stru_1423D7CF8.mParameter + dt) <= 0.0 )
      v33 = 0.0;
    if ( v33 >= stru_1423D7CF8.mDuration )
      v33 = stru_1423D7CF8.mDuration;
    stru_1423D7CF8.mParameter = v33;
    v34 = (float)((float)((float)(stru_1423D7CF8.A * 3.0) * v33) + (float)(stru_1423D7CF8.B * 2.0)) * v33;
    mNearRange = (float)((float)((float)((float)((float)(stru_1423D7CF8.A * v33) + stru_1423D7CF8.B) * v33)
                               + stru_1423D7CF8.C)
                       * v33)
               + stru_1423D7CF8.D;
    v35 = stru_1423D7D44.mParameter + dt;
    stru_1423D7CF8.v0 = v34 + stru_1423D7CF8.C;
    stru_1423D7CF8.p0 = mNearRange;
    if ( (float)(stru_1423D7D44.mParameter + dt) <= 0.0 )
      v35 = 0.0;
    if ( v35 >= stru_1423D7D44.mDuration )
      v35 = stru_1423D7D44.mDuration;
    stru_1423D7D44.mParameter = v35;
    v36 = (float)((float)((float)(stru_1423D7D44.A * 3.0) * v35) + (float)(stru_1423D7D44.B * 2.0)) * v35;
    mNearBlurRadius = (float)((float)((float)((float)((float)(stru_1423D7D44.A * v35) + stru_1423D7D44.B) * v35)
                                    + stru_1423D7D44.C)
                            * v35)
                    + stru_1423D7D44.D;
    v37 = stru_1423D7D90.mParameter + dt;
    stru_1423D7D44.v0 = v36 + stru_1423D7D44.C;
    stru_1423D7D44.p0 = mNearBlurRadius;
    if ( (float)(stru_1423D7D90.mParameter + dt) <= 0.0 )
      v37 = 0.0;
    if ( v37 >= stru_1423D7D90.mDuration )
      v37 = stru_1423D7D90.mDuration;
    stru_1423D7D90.mParameter = v37;
    v38 = (float)((float)((float)(stru_1423D7D90.A * 3.0) * v37) + (float)(stru_1423D7D90.B * 2.0)) * v37;
    mFarRange = (float)((float)((float)((float)((float)(stru_1423D7D90.A * v37) + stru_1423D7D90.B) * v37)
                              + stru_1423D7D90.C)
                      * v37)
              + stru_1423D7D90.D;
    v39 = stru_1423D7DDC.mParameter + dt;
    stru_1423D7D90.v0 = v38 + stru_1423D7D90.C;
    stru_1423D7D90.p0 = mFarRange;
    if ( (float)(stru_1423D7DDC.mParameter + dt) <= 0.0 )
      v39 = 0.0;
    if ( v39 >= stru_1423D7DDC.mDuration )
      v39 = stru_1423D7DDC.mDuration;
    stru_1423D7DDC.mParameter = v39;
    UFG::GameCameraComponent::mDofFocusDist.p1 = v29;
    mFarBlurRadius = (float)((float)((float)((float)((float)(stru_1423D7DDC.A * v39) + stru_1423D7DDC.B) * v39)
                                   + stru_1423D7DDC.C)
                           * v39)
                   + stru_1423D7DDC.D;
    stru_1423D7DDC.v0 = (float)((float)((float)((float)(stru_1423D7DDC.A * 3.0) * v39) + (float)(stru_1423D7DDC.B * 2.0))
                              * v39)
                      + stru_1423D7DDC.C;
    stru_1423D7DDC.p0 = mFarBlurRadius;
    UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDofFocusDist);
    mInFocusRange = v32 * 2.0;
  }
  v40 = 0;
  v41 = UFG::GameCameraComponent::mDofOverrideParams;
  while ( !*v41 )
  {
    v41 += 24;
    ++v40;
    if ( (__int64)v41 >= (__int64)&UI_HASH_SCREEN_PUSHED_7 )
      goto LABEL_46;
  }
  v42 = (float *)&UFG::GameCameraComponent::mDofOverrideParams[24 * v40];
  if ( v42 )
  {
    mInFocusRange = v42[1];
    mNearRange = v42[2];
    mNearBlurRadius = v42[4];
    mFarRange = v42[3];
    mFarBlurRadius = v42[5];
  }
LABEL_46:
  v43 = &UFG::trDofFocusDistanceDurationShrink;
  v44 = 0.0 / UFG::GameCameraComponent::mDofFocusDist.mDuration;
  if ( UFG::GameCameraComponent::mDofFocusDist.p1 > UFG::GameCameraComponent::mDofFocusDist.p0 )
    v43 = &UFG::trDofFocusDistanceDurationGrow;
  v45 = *v43;
  if ( *v43 <= v13 )
    v45 = v13;
  UFG::GameCameraComponent::mDofFocusDist.mDuration = v45;
  v46 = v44 * v45;
  if ( v45 > v13 )
    v13 = v45;
  v47 = v13 * v13;
  v48 = v46 + dt;
  v49 = (float)((float)((float)(UFG::GameCameraComponent::mDofFocusDist.v1 + UFG::GameCameraComponent::mDofFocusDist.v0)
                      * v13)
              + (float)((float)(UFG::GameCameraComponent::mDofFocusDist.p0 - UFG::GameCameraComponent::mDofFocusDist.p1)
                      * 2.0))
      / (float)((float)(v13 * v13) * v13);
  UFG::GameCameraComponent::mDofFocusDist.A = v49;
  v50 = (float)((float)(UFG::GameCameraComponent::mDofFocusDist.v0 * 2.0) + UFG::GameCameraComponent::mDofFocusDist.v1)
      * v13;
  v51 = UFG::GameCameraComponent::mDofFocusDist.v0;
  UFG::GameCameraComponent::mDofFocusDist.C = UFG::GameCameraComponent::mDofFocusDist.v0;
  v52 = (float)((float)((float)(UFG::GameCameraComponent::mDofFocusDist.p1 - UFG::GameCameraComponent::mDofFocusDist.p0)
                      * 3.0)
              - v50)
      / v47;
  UFG::GameCameraComponent::mDofFocusDist.D = UFG::GameCameraComponent::mDofFocusDist.p0;
  UFG::GameCameraComponent::mDofFocusDist.B = v52;
  if ( v48 <= 0.0 )
    v48 = 0.0;
  if ( v48 >= v45 )
    v48 = v45;
  UFG::GameCameraComponent::mDofFocusDist.mParameter = v48;
  UFG::GameCameraComponent::mDofFocusDist.v0 = (float)((float)((float)((float)(v49 * 3.0) * v48) + (float)(v52 * 2.0))
                                                     * v48)
                                             + UFG::GameCameraComponent::mDofFocusDist.v0;
  UFG::GameCameraComponent::mDofFocusDist.p0 = (float)((float)((float)((float)((float)(v49 * v48) + v52) * v48) + v51)
                                                     * v48)
                                             + UFG::GameCameraComponent::mDofFocusDist.p0;
  if ( mInFocusRange <= UFG::GameCameraComponent::mDofInFocusRange )
    v53 = UFG::trDofInFocusRangeRateShrink;
  else
    v53 = UFG::trDofInFocusRangeRateGrow;
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofInFocusRange,
    mInFocusRange,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofInFocusRange - mInFocusRange) & _xmm) * v53,
    dt);
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofNearRange,
    mNearRange,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofNearRange - mNearRange) & _xmm)
  * UFG::trDofNearRangeRate,
    dt);
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofNearBlur,
    mNearBlurRadius,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofNearBlur - mNearBlurRadius) & _xmm)
  * UFG::trDofNearBlurRate,
    dt);
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofFarRange,
    mFarRange,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofFarRange - mFarRange) & _xmm)
  * UFG::trDofFarRangeRate,
    dt);
  UFG::qApproach(
    &UFG::GameCameraComponent::mDofFarBlur,
    mFarBlurRadius,
    COERCE_FLOAT(COERCE_UNSIGNED_INT(UFG::GameCameraComponent::mDofFarBlur - mFarBlurRadius) & _xmm)
  * UFG::trDofFarBlurRate,
    dt);
  if ( snap )
  {
    UFG::GameCameraComponent::mDofFocusDist.p0 = UFG::GameCameraComponent::mDofFocusDist.p1;
    UFG::GameCameraComponent::mDofFocusDist.v0 = UFG::GameCameraComponent::mDofFocusDist.v1;
    UFG::HomerCubic<float>::MakeCoeffs(&UFG::GameCameraComponent::mDofFocusDist);
    UFG::GameCameraComponent::mDofFocusDist.mParameter = 0.0;
    UFG::GameCameraComponent::mDofInFocusRange = mInFocusRange;
    UFG::GameCameraComponent::mDofNearRange = mNearRange;
    UFG::GameCameraComponent::mDofNearBlur = mNearBlurRadius;
    UFG::GameCameraComponent::mDofFarRange = mFarRange;
    UFG::GameCameraComponent::mDofFarBlur = mFarBlurRadius;
  }
  mDofNoiseAmplitude = this->mDofNoiseAmplitude;
  v55 = 1.0 - (float)(dt * this->mDofNoiseAmplitudeDecay);
  if ( v55 < 0.0 )
    v55 = 0.0;
  v56 = v55 * mDofNoiseAmplitude;
  this->mDofNoiseAmplitude = v56;
  if ( v56 <= 0.0099999998 )
  {
    if ( mDofNoiseAmplitude > 0.0099999998 )
      *(_QWORD *)&this->mDofNoiseTimer = 0i64;
  }
  else
  {
    this->mDofNoiseTimer = dt + this->mDofNoiseTimer;
  }
  Render::DepthOfField::Focus::Focus(&focus);
  p0 = UFG::GameCameraComponent::mDofFocusDist.p0;
  if ( this->mDofNoiseAmplitude != 0.0 )
    p0 = p0
       + (float)(UFG::qNoise<float,float>::GetValue(
                   &this->mDofNoise,
                   COERCE_DOUBLE((unsigned __int64)LODWORD(this->mDofNoiseTimer)))
               * this->mDofNoiseAmplitude);
  if ( p0 < 0.0099999998 )
    p0 = FLOAT_0_0099999998;
  focus.mFocalDistance = p0;
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
  Render::DepthOfField::Focus::Set(&this->mCamera.mDepthOfFieldFocus, &focus);
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
void __fastcall UFG::GameCameraComponent::SetDynamicDOFParam(
        UFG::GameCameraComponent::DynamicDofParamType dofParamType,
        float duration_high,
        float deviation_high,
        float value_high,
        float duration_low,
        float deviation_low,
        float value_low)
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
UFG::ShapeCasterCollector::HitInfo *__fastcall UFG::GameCameraComponent::FindClosestCollidableHit(
        UFG::GameCameraComponent *this,
        UFG::ShapeCasterCollector *collector,
        UFG::qVector3 *startPos,
        float safeRadius)
{
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mNext; // rbx
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *p_mHitList; // rdi
  float v10; // xmm6_4
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v11; // rbp
  float mRadius; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm2_4

  mNext = collector->mHitList.mNode.mNext;
  p_mHitList = &collector->mHitList;
  if ( mNext == (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)&collector->mHitList )
    return 0i64;
  v10 = FLOAT_1_0e12;
  v11 = 0i64;
  do
  {
    if ( !UFG::GameCameraComponent::ShouldPassThru(this, (UFG::ShapeCasterCollector::HitInfo *)mNext, startPos) )
    {
      mRadius = collector->mRadius;
      v13 = (float)((float)(mRadius * *((float *)&mNext[2].mPrev + 1)) + *(float *)&mNext[1].mNext) - startPos->z;
      v14 = (float)((float)(mRadius * *(float *)&mNext[2].mPrev) + *((float *)&mNext[1].mPrev + 1)) - startPos->y;
      v15 = (float)((float)(mRadius * *((float *)&mNext[1].mNext + 1)) + *(float *)&mNext[1].mPrev) - startPos->x;
      v16 = (float)((float)(v14 * v14) + (float)(v15 * v15)) + (float)(v13 * v13);
      if ( v16 >= (float)(safeRadius * safeRadius) && v16 < v10 )
      {
        v11 = mNext;
        v10 = v16;
      }
    }
    mNext = mNext->mNext;
  }
  while ( mNext != (UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *)p_mHitList );
  return (UFG::ShapeCasterCollector::HitInfo *)v11;
}

// File Line: 1051
// RVA: 0x3C0C20
float __fastcall UFG::GameCameraComponent::ComputeNearOffset(
        UFG::GameCameraComponent *this,
        UFG::qVector3 *eye,
        UFG::qVector3 *look,
        float dispFov)
{
  float v8; // xmm15_4
  float v9; // xmm6_4
  float x; // xmm11_4
  __m128 y_low; // xmm10
  UFG::CharacterSubjectComponent *v12; // rdi
  float v13; // xmm8_4
  float v14; // xmm13_4
  float v15; // xmm7_4
  float y; // xmm5_4
  float v17; // xmm11_4
  __m128 v18; // xmm2
  float v19; // xmm3_4
  float v20; // xmm10_4
  float v21; // xmm11_4
  __m128 z_low; // xmm12
  float v23; // xmm3_4
  float v24; // xmm0_4
  char v25; // r13
  __m128 v26; // xmm2
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm7_4
  char v31; // r15
  __m128 v32; // xmm2
  float DisplayAspectRatio; // xmm0_4
  __m128 v34; // xmm4
  float v35; // xmm13_4
  float v36; // xmm15_4
  __m128 v37; // xmm2
  float v38; // xmm5_4
  float v39; // xmm6_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm3_4
  float v44; // xmm0_4
  char v45; // r12
  __m128 v46; // xmm3
  float v47; // xmm0_4
  float v48; // xmm6_4
  signed __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfTypeHK; // rax
  __int64 v51; // rax
  bool v52; // zf
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float z; // xmm0_4
  __m128 v57; // xmm2
  float v58; // xmm6_4
  Render::DebugDrawContext *Context; // rax
  UFG::qColour *v60; // rsi
  float v61; // xmm7_4
  float v62; // xmm13_4
  float v63; // xmm14_4
  Render::DebugDrawContext *v64; // rdi
  UFG::qColour *v65; // r9
  float v66; // xmm0_4
  float v67; // xmm1_4
  UFG::qColour *v68; // r9
  float v69; // xmm0_4
  float v70; // xmm1_4
  float v71; // xmm11_4
  float v72; // xmm10_4
  float v73; // xmm12_4
  UFG::qColour *v74; // r9
  float v75; // xmm1_4
  float v76; // xmm0_4
  UFG::qVector3 rayEnd; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 closest_point; // [rsp+50h] [rbp-B0h] BYREF
  float v79; // [rsp+60h] [rbp-A0h]
  float v80; // [rsp+64h] [rbp-9Ch]
  float v81; // [rsp+68h] [rbp-98h]
  float v82; // [rsp+6Ch] [rbp-94h]
  float v83; // [rsp+70h] [rbp-90h]
  float v84; // [rsp+74h] [rbp-8Ch]
  float v85; // [rsp+78h] [rbp-88h]
  UFG::qVector3 lA0; // [rsp+80h] [rbp-80h] BYREF
  UFG::RayCastData data; // [rsp+90h] [rbp-70h] BYREF
  UFG::RayCastData v88; // [rsp+170h] [rbp+70h] BYREF
  UFG::RayCastData v89; // [rsp+250h] [rbp+150h] BYREF
  float v90; // [rsp+418h] [rbp+318h]

  if ( !UFG::tbCollisionNearOffsetCasts )
    return 0.0;
  v90 = dispFov * 0.5;
  v8 = cosf(dispFov * 0.5);
  v9 = tanf(dispFov * 0.5);
  UFG::Director::Get();
  x = look->x;
  y_low = (__m128)LODWORD(look->y);
  z_low = (__m128)LODWORD(look->z);
  v12 = 0i64;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_hitFraction = 1.0;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeys[0] = -1;
  v13 = 0.0;
  z_low.m128_f32[0] = z_low.m128_f32[0] - eye->z;
  v14 = UFG::trCollisionNearMargin + UFG::gCameraDefaultNear;
  v15 = eye->x;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  data.mOutput.m_rootCollidable = 0i64;
  data.mDebugName = 0i64;
  y = eye->y;
  v17 = x - v15;
  y_low.m128_f32[0] = y_low.m128_f32[0] - y;
  v85 = UFG::trCollisionNearMargin + UFG::gCameraDefaultNear;
  v18 = y_low;
  v18.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v17 * v17))
                  + (float)(z_low.m128_f32[0] * z_low.m128_f32[0]);
  v19 = (float)(UFG::trCollisionNearMargin + UFG::gCameraDefaultNear) / _mm_sqrt_ps(v18).m128_f32[0];
  v20 = y_low.m128_f32[0] * v19;
  v21 = v17 * v19;
  z_low.m128_f32[0] = z_low.m128_f32[0] * v19;
  v79 = (float)(UFG::trCollisionNearMargin + UFG::gCameraDefaultNear) * v9;
  v23 = v79
      / fsqrt((float)(COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(v21) ^ _xmm[0])) + (float)(v20 * v20));
  v83 = v23 * 0.0;
  v80 = v23 * v20;
  v81 = v23 * COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]);
  data.mCollisionModelName.mUID = -1;
  v24 = (float)(z_low.m128_f32[0] + eye->z) + (float)(v23 * 0.0);
  rayEnd.x = (float)(v15 + v21) + (float)(v23 * v20);
  rayEnd.y = (float)(y + v20) + v81;
  rayEnd.z = v24;
  UFG::RayCastData::Init(&data, eye, &rayEnd, 0x12u);
  v25 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data);
  if ( v25 )
  {
    v26 = (__m128)LODWORD(data.point.y);
    v26.m128_f32[0] = (float)((float)((float)(data.point.y - eye->y) * (float)(data.point.y - eye->y))
                            + (float)((float)(data.point.x - eye->x) * (float)(data.point.x - eye->x)))
                    + (float)((float)(data.point.z - eye->z) * (float)(data.point.z - eye->z));
    LODWORD(v13) = COERCE_UNSIGNED_INT(v14 - (float)(_mm_sqrt_ps(v26).m128_f32[0] * v8)) ^ _xmm[0];
  }
  v88.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  v88.mInput.m_filterInfo = 0;
  v27 = v21 + eye->x;
  v28 = v20 + eye->y;
  v29 = z_low.m128_f32[0] + eye->z;
  v30 = 0.0;
  v88.mInput.m_userData = 0i64;
  v88.mOutput.m_hitFraction = 1.0;
  v88.mOutput.m_extraInfo = -1;
  v88.mOutput.m_shapeKeyIndex = 0;
  v88.mOutput.m_shapeKeys[0] = -1;
  v88.mOutput.m_rootCollidable = 0i64;
  v88.mDebugName = 0i64;
  v88.mCollisionModelName.mUID = -1;
  rayEnd.x = v27 - v80;
  rayEnd.y = v28 - v81;
  rayEnd.z = v29 - (float)(v23 * 0.0);
  UFG::RayCastData::Init(&v88, eye, &rayEnd, 0x12u);
  v31 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v88);
  if ( v31 )
  {
    v32 = (__m128)LODWORD(v88.point.y);
    v32.m128_f32[0] = (float)((float)((float)(v88.point.y - eye->y) * (float)(v88.point.y - eye->y))
                            + (float)((float)(v88.point.x - eye->x) * (float)(v88.point.x - eye->x)))
                    + (float)((float)(v88.point.z - eye->z) * (float)(v88.point.z - eye->z));
    LODWORD(v30) = COERCE_UNSIGNED_INT(v14 - (float)(_mm_sqrt_ps(v32).m128_f32[0] * v8)) ^ _xmm[0];
  }
  DisplayAspectRatio = Render::GetDisplayAspectRatio();
  v34 = z_low;
  v35 = 0.0;
  v36 = 1.0 / DisplayAspectRatio;
  v89.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  v89.mInput.m_filterInfo = 0;
  v89.mInput.m_userData = 0i64;
  v34.m128_f32[0] = (float)(z_low.m128_f32[0] * COERCE_FLOAT(LODWORD(v80) ^ _xmm[0]))
                  - (float)(COERCE_FLOAT(LODWORD(v83) ^ _xmm[0]) * v21);
  v89.mOutput.m_hitFraction = 1.0;
  v89.mOutput.m_extraInfo = -1;
  v89.mOutput.m_shapeKeyIndex = 0;
  v37 = v34;
  v89.mOutput.m_shapeKeys[0] = -1;
  v89.mOutput.m_rootCollidable = 0i64;
  v89.mDebugName = 0i64;
  v89.mCollisionModelName.mUID = -1;
  v38 = (float)(COERCE_FLOAT(LODWORD(v83) ^ _xmm[0]) * v20)
      - (float)(z_low.m128_f32[0] * COERCE_FLOAT(LODWORD(v81) ^ _xmm[0]));
  v39 = (float)(COERCE_FLOAT(LODWORD(v81) ^ _xmm[0]) * v21) - (float)(COERCE_FLOAT(LODWORD(v80) ^ _xmm[0]) * v20);
  v40 = (float)(1.0 / DisplayAspectRatio) * v79;
  v37.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v38 * v38)) + (float)(v39 * v39);
  v41 = v20 + eye->y;
  v42 = _mm_sqrt_ps(v37).m128_f32[0];
  v37.m128_f32[0] = z_low.m128_f32[0] + eye->z;
  v43 = v40 / v42;
  v79 = v43 * v38;
  v44 = v21 + eye->x;
  v82 = v43 * v39;
  rayEnd.z = v37.m128_f32[0] + (float)(v43 * v39);
  v84 = v43 * v34.m128_f32[0];
  rayEnd.x = v44 + (float)(v43 * v38);
  rayEnd.y = v41 + (float)(v43 * v34.m128_f32[0]);
  UFG::RayCastData::Init(&v89, eye, &rayEnd, 0x12u);
  v45 = UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &v89);
  if ( v45 )
  {
    v46 = (__m128)LODWORD(v89.point.y);
    v46.m128_f32[0] = (float)((float)((float)(v89.point.y - eye->y) * (float)(v89.point.y - eye->y))
                            + (float)((float)(v89.point.x - eye->x) * (float)(v89.point.x - eye->x)))
                    + (float)((float)(v89.point.z - eye->z) * (float)(v89.point.z - eye->z));
    v47 = cosf(v36 * v90);
    LODWORD(v35) = COERCE_UNSIGNED_INT(v85 - (float)(_mm_sqrt_ps(v46).m128_f32[0] * v47)) ^ _xmm[0];
  }
  v48 = 0.0;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              LocalPlayer,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                              LocalPlayer,
                                                              UFG::CharacterSubjectComponent::_TypeUID);
    }
    v12 = ComponentOfTypeHK;
  }
  if ( v12 && !((unsigned __int8 (__fastcall *)(UFG::CharacterSubjectComponent *))v12->vfptr[29].__vecDelDtor)(v12) )
  {
    v51 = ((__int64 (__fastcall *)(UFG::CharacterSubjectComponent *))v12->vfptr[26].__vecDelDtor)(v12);
    v52 = !v12->mPelvisDirty;
    v53 = *(float *)(v51 + 4);
    v54 = *(float *)(v51 + 8);
    rayEnd.x = *(float *)v51;
    rayEnd.y = v53;
    rayEnd.z = v54;
    if ( !v52 )
      UFG::CharacterSubjectComponent::UpdatePelvis(v12);
    v55 = v12->mPelvisPosition.y;
    lA0.x = v12->mPelvisPosition.x;
    z = v12->mPelvisPosition.z;
    lA0.y = v55;
    lA0.z = z;
    UFG::qGetClosestPointOnSegment(&closest_point, &lA0, &rayEnd, eye);
    v57 = (__m128)LODWORD(closest_point.y);
    v57.m128_f32[0] = (float)((float)((float)(closest_point.y - eye->y) * (float)(closest_point.y - eye->y))
                            + (float)((float)(closest_point.x - eye->x) * (float)(closest_point.x - eye->x)))
                    + (float)((float)(closest_point.z - eye->z) * (float)(closest_point.z - eye->z));
    v58 = (float)(_mm_sqrt_ps(v57).m128_f32[0] - 0.40000001) * 2.8571429;
    if ( v58 <= 0.0 )
    {
      v58 = 0.0;
    }
    else if ( v58 >= 1.0 )
    {
      v58 = *(float *)&FLOAT_1_0;
    }
    v48 = (float)(v58 * 0.22) - 0.22;
  }
  if ( v13 >= v30 )
    v13 = v30;
  if ( v13 >= v35 )
    v13 = v35;
  if ( v13 >= v48 )
    v13 = v48;
  if ( (float)(v13 + UFG::gCameraDefaultNear) < UFG::trCollisionNearOffsetMin )
    v13 = UFG::trCollisionNearOffsetMin - UFG::gCameraDefaultNear;
  if ( COERCE_FLOAT(LODWORD(v13) & _xmm) < 0.000099999997 )
    v13 = 0.0;
  if ( UFG::tbCollisionDebugDraw )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    v60 = &UFG::qColour::Green;
    v61 = v83;
    v62 = v80;
    v63 = v81;
    v64 = Context;
    v65 = &UFG::qColour::Green;
    v66 = v21 + eye->x;
    v67 = v20 + eye->y;
    if ( v25 )
      v65 = &UFG::qColour::Red;
    closest_point.z = (float)(z_low.m128_f32[0] + eye->z) + v83;
    closest_point.x = v66 + v80;
    closest_point.y = v67 + v81;
    Render::DebugDrawContext::DrawSphere(Context, &closest_point, 0.0099999998, v65, &UFG::qMatrix44::msIdentity, 0i64);
    if ( v25 )
      Render::DebugDrawContext::DrawSphere(
        v64,
        &data.point,
        0.0099999998,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
    v68 = &UFG::qColour::Green;
    if ( v31 )
      v68 = &UFG::qColour::Red;
    v69 = (float)(v21 + eye->x) - v62;
    v70 = (float)(v20 + eye->y) - v63;
    closest_point.z = (float)(z_low.m128_f32[0] + eye->z) - v61;
    closest_point.x = v69;
    closest_point.y = v70;
    Render::DebugDrawContext::DrawSphere(v64, &closest_point, 0.0099999998, v68, &UFG::qMatrix44::msIdentity, 0i64);
    if ( v31 )
      Render::DebugDrawContext::DrawSphere(
        v64,
        &v88.point,
        0.0099999998,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
    v71 = v21 + eye->x;
    v72 = v20 + eye->y;
    v73 = z_low.m128_f32[0] + eye->z;
    if ( v45 )
      v60 = &UFG::qColour::Red;
    closest_point.x = v71 + v79;
    closest_point.y = v72 + v84;
    closest_point.z = v73 + v82;
    Render::DebugDrawContext::DrawSphere(v64, &closest_point, 0.0099999998, v60, &UFG::qMatrix44::msIdentity, 0i64);
    if ( v45 )
      Render::DebugDrawContext::DrawSphere(
        v64,
        &v89.point,
        0.0099999998,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
    v74 = &UFG::qColour::Yellow;
    if ( v13 == 0.0 )
      v74 = &UFG::qColour::White;
    v75 = this->mCamera.mProjection.v2.z;
    if ( v75 == 0.0 || v75 == this->mCamera.mProjection.v2.w )
      v76 = v82;
    else
      v76 = this->mCamera.mProjection.v3.z / v75;
    Render::DebugDrawContext::DrawTextA(v64, 440, 500, v74, "Nearoffset : %f(res:%f)", v13, v76);
  }
  return v13;
}

// File Line: 1185
// RVA: 0x3BF1C0
char __fastcall UFG::GameCameraComponent::AnyTargetPointVisible(UFG::GameCameraComponent *this, UFG::qVector3 *eye)
{
  int v2; // edi
  float *i; // rsi
  float v6; // xmm1_4
  UFG::ShapeCasterCollector *pCollisionCollectorTargetPoints; // rdx
  float v8; // xmm0_4
  float x; // xmm1_4
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::ShapeCasterCollector::HitInfo *ClosestCollidableHit; // rax
  UFG::qVector3 start; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 end; // [rsp+40h] [rbp-18h] BYREF

  v2 = 0;
  if ( this->mCollisionTargetPointsNum <= 0 )
    return 0;
  for ( i = &this->mCollisionTargetPoints[0].z; ; i += 3 )
  {
    v6 = *(i - 1);
    pCollisionCollectorTargetPoints = this->pCollisionCollectorTargetPoints;
    start.x = *(i - 2);
    v8 = *i;
    start.y = v6;
    x = eye->x;
    start.z = v8;
    y = eye->y;
    end.x = x;
    z = eye->z;
    end.y = y;
    end.z = z;
    if ( !UFG::BasePhysicsSystem::CastShape(
            UFG::BasePhysicsSystem::mInstance,
            pCollisionCollectorTargetPoints,
            &start,
            &end) )
      break;
    ClosestCollidableHit = UFG::GameCameraComponent::FindClosestCollidableHit(
                             this,
                             this->pCollisionCollectorTargetPoints,
                             &start,
                             this->mSafeRadius);
    if ( !ClosestCollidableHit || UFG::GameCameraComponent::ShouldPassThru(this, ClosestCollidableHit, &start) )
      break;
    if ( ++v2 >= this->mCollisionTargetPointsNum )
      return 0;
  }
  return 1;
}

// File Line: 1276
// RVA: 0x3CB1C0
void __fastcall UFG::GameCameraComponent::SetDesiredEyeLookUp(
        UFG::GameCameraComponent *this,
        float dt,
        UFG::qVector3 *desEye,
        UFG::qVector3 *desLook,
        UFG::qVector3 *desUp,
        bool collide,
        UFG::qVector3 *newEye,
        UFG::qVector3 *newLook)
{
  float *v8; // r13
  char v9; // bl
  float x; // xmm3_4
  float y; // xmm4_4
  UFG::GameCameraComponent *v14; // rsi
  float v15; // xmm8_4
  float z; // xmm7_4
  bool v17; // zf
  __int128 y_low; // xmm9
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  UFG::qVector3 *Value; // rax
  float v27; // xmm3_4
  float v28; // xmm1_4
  float mImpactShakeSeed; // xmm2_4
  float v30; // xmm2_4
  UFG::qVector3 *v31; // rax
  float v32; // xmm2_4
  float v33; // xmm0_4
  float *v34; // rdi
  float v35; // xmm1_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  UFG::ShapeCasterCollector::HitInfo *ClosestCollidableHit; // rax
  float mRadius; // xmm8_4
  float v43; // xmm1_4
  float v44; // xmm0_4
  float v45; // xmm7_4
  float v46; // xmm8_4
  float v47; // xmm12_4
  __m128 v48; // xmm2
  float v49; // xmm1_4
  float v50; // xmm8_4
  float v51; // xmm9_4
  float v52; // xmm7_4
  UFG::ShapeCasterCollector::HitInfo *v53; // rbx
  float v54; // xmm6_4
  UFG::ShapeCasterCollector::HitInfo *v55; // rax
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // eax
  float v61; // xmm4_4
  __m128 v62; // xmm2
  float v63; // xmm3_4
  float v64; // xmm1_4
  float *p_mEyePushPercent; // r13
  float v66; // xmm0_4
  float mPushInOverrideRate; // xmm2_4
  float v68; // xmm13_4
  float v69; // xmm1_4
  float v70; // xmm2_4
  float mCollisionRise; // xmm6_4
  float v72; // xmm2_4
  float mEyePushRise; // xmm2_4
  float v74; // xmm0_4
  float v75; // xmm3_4
  float v76; // xmm12_4
  float v77; // xmm2_4
  float v78; // xmm0_4
  float v79; // xmm1_4
  float *p_ymax; // rdi
  float *v81; // rax
  float v82; // xmm7_4
  Render::DebugDrawContext *Context; // rax
  bool mLookModified; // dl
  const char *v85; // rbx
  Render::DebugDrawContext *v86; // r12
  const char *v87; // rcx
  UFG::qColour *v88; // r9
  UFG::qColour *v89; // r9
  UFG::qColour *v90; // r9
  float v91; // xmm0_4
  UFG::qColour *v92; // r13
  char v93; // r14
  const char *v94; // rbx
  const char *v95; // rax
  UFG::qColour *v96; // r9
  double removePhantomWhenDone; // [rsp+28h] [rbp-A8h]
  UFG::qVector3 eye; // [rsp+40h] [rbp-90h] BYREF
  UFG::qVector3 loook; // [rsp+50h] [rbp-80h] BYREF
  UFG::qVector3 up; // [rsp+60h] [rbp-70h] BYREF
  UFG::qVector3 result; // [rsp+70h] [rbp-60h] BYREF
  UFG::GameCameraComponent *v102; // [rsp+120h] [rbp+50h]
  UFG::qVector3 *centre; // [rsp+138h] [rbp+68h]
  float *vars0; // [rsp+140h] [rbp+70h]
  void *retaddr; // [rsp+148h] [rbp+78h]
  float *v107; // [rsp+158h] [rbp+88h]
  float *v108; // [rsp+158h] [rbp+88h]

  v9 = (char)retaddr;
  x = desEye->x;
  y = desEye->y;
  v14 = this;
  v15 = desLook->x;
  z = desLook->z;
  eye.x = desEye->x;
  if ( UFG::tbCollisionDisable )
    v9 = 0;
  v17 = this->mImpactShakeAmplitude == 0.0;
  y_low = LODWORD(desLook->y);
  eye.y = y;
  v20 = *vars0;
  v21 = vars0[1];
  loook.x = v15;
  up.x = v20;
  v22 = vars0[2];
  up.y = v21;
  up.z = v22;
  v23 = desEye->z;
  LODWORD(loook.y) = y_low;
  eye.z = v23;
  loook.z = z;
  if ( !v17 )
  {
    v24 = ((float (__fastcall *)(UFG::GameCameraComponent *))this->vfptr[19].__vecDelDtor)(this);
    v25 = tanf(v24 * 0.5) * (float)(v14->mImpactShakeAmplitude * 1.6);
    Value = UFG::qNoise<UFG::qVector3,float>::GetValue(&v14->mEyeImpactNoise, &result, v14->mImpactShakeTimer);
    v27 = v25 * Value->z;
    v28 = eye.y + (float)(v25 * Value->y);
    mImpactShakeSeed = v14->mImpactShakeSeed;
    eye.x = eye.x + (float)(v25 * Value->x);
    v30 = mImpactShakeSeed + v14->mImpactShakeTimer;
    eye.y = v28;
    eye.z = eye.z + v27;
    v31 = UFG::qNoise<UFG::qVector3,float>::GetValue(&v14->mLookImpactNoise, &result, v30);
    y_low = LODWORD(loook.y);
    y = v28;
    x = eye.x;
    v15 = loook.x + (float)(v25 * v31->x);
    *(float *)&y_low = loook.y + (float)(v25 * v31->y);
    z = loook.z + (float)(v25 * v31->z);
    loook.x = v15;
    loook.y = *(float *)&y_low;
    loook.z = z;
  }
  v14->mInCollision = 0;
  v32 = UFG::qVector3::msZero.z;
  v33 = UFG::qVector3::msZero.x;
  v14->mCollisionLookOffset.y = UFG::qVector3::msZero.y;
  v14->mCollisionLookOffset.z = v32;
  v14->mCollisionLookOffset.x = v33;
  if ( v9 )
  {
    v39 = desEye->y;
    v40 = desEye->z;
    v108 = v8;
    v14->mCandidateEye.x = desEye->x;
    v14->mCandidateEye.y = v39;
    v14->mCandidateEye.z = v40;
    v14->mLookModified = 0;
    if ( v14->mAlternateLookValid )
    {
      if ( UFG::BasePhysicsSystem::CastShape(
             UFG::BasePhysicsSystem::mInstance,
             v14->pCollisionCollectorTargetPoints,
             &v14->mAlternateLook,
             &loook)
        && (ClosestCollidableHit = UFG::GameCameraComponent::FindClosestCollidableHit(
                                     v14,
                                     v14->pCollisionCollectorTargetPoints,
                                     &v14->mAlternateLook,
                                     0.0)) != 0i64 )
      {
        mRadius = v14->pCollisionCollectorTargetPoints->mRadius;
        y_low = LODWORD(mRadius);
        z = (float)(mRadius * ClosestCollidableHit->mContactNormal.z) + ClosestCollidableHit->mContactPosition.z;
        v15 = (float)(mRadius * ClosestCollidableHit->mContactNormal.x) + ClosestCollidableHit->mContactPosition.x;
        *(float *)&y_low = (float)(*(float *)&y_low * ClosestCollidableHit->mContactNormal.y)
                         + ClosestCollidableHit->mContactPosition.y;
        loook.z = z;
        v43 = *(float *)&y_low - desLook->y;
        v44 = z - desLook->z;
        v14->mCollisionLookOffset.x = v15 - desLook->x;
        v14->mCollisionLookOffset.y = v43;
        v14->mCollisionLookOffset.z = v44;
        v14->mLookModified = 1;
        loook.x = v15;
        LODWORD(loook.y) = y_low;
      }
      else
      {
        z = loook.z;
        y_low = LODWORD(loook.y);
        v15 = loook.x;
      }
      x = eye.x;
      y = eye.y;
    }
    v45 = z - eye.z;
    v46 = v15 - x;
    v47 = 0.0;
    *(float *)&y_low = *(float *)&y_low - y;
    v48 = (__m128)y_low;
    v48.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v46 * v46)) + (float)(v45 * v45);
    if ( v48.m128_f32[0] <= 0.000099999997 )
    {
      v50 = *(float *)&FLOAT_1_0;
      v51 = 0.0;
      v52 = 0.0;
    }
    else
    {
      LODWORD(v47) = _mm_sqrt_ps(v48).m128_u32[0];
      if ( v48.m128_f32[0] == 0.0 )
      {
        v50 = v46 * 0.0;
        v51 = *(float *)&y_low * 0.0;
        v52 = v45 * 0.0;
      }
      else
      {
        v49 = 1.0 / _mm_sqrt_ps(v48).m128_f32[0];
        v50 = v46 * v49;
        v51 = *(float *)&y_low * v49;
        v52 = v45 * v49;
      }
    }
    v53 = 0i64;
    if ( UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, v14->pCollisionCollector, &eye, &eye) )
      v53 = UFG::GameCameraComponent::FindClosestCollidableHit(v14, v14->pCollisionCollector, &eye, 0.0);
    v54 = 0.0;
    if ( (!UFG::GameCameraComponent::AnyTargetPointVisible(v14, &eye) || v53)
      && UFG::BasePhysicsSystem::CastShape(UFG::BasePhysicsSystem::mInstance, v14->pCollisionCollector, &loook, &eye) )
    {
      v55 = UFG::GameCameraComponent::FindClosestCollidableHit(v14, v14->pCollisionCollector, &loook, v14->mSafeRadius);
      if ( v55 )
      {
        v56 = v55->mContactNormal.y;
        v57 = v55->mContactNormal.z;
        v14->mCollisionSurfaceNormal.x = v55->mContactNormal.x;
        v14->mCollisionSurfaceNormal.y = v56;
        v14->mCollisionSurfaceNormal.z = v57;
        v58 = v55->mContactPosition.y;
        v59 = v55->mContactPosition.z;
        v60 = v55->mContactPosition.x;
        v14->mCollisionContactPosition.z = v59;
        v14->mCollisionContactPosition.y = v58;
        v14->mCollisionContactPosition.x = v60;
        v61 = (float)(UFG::trCollisionCastingRadius * v14->mCollisionSurfaceNormal.z) + v59;
        v62 = (__m128)LODWORD(eye.y);
        v63 = (float)(UFG::trCollisionCastingRadius * v14->mCollisionSurfaceNormal.y) + v58;
        v64 = eye.x
            - (float)((float)(UFG::trCollisionCastingRadius * v14->mCollisionSurfaceNormal.x)
                    + v14->mCollisionContactPosition.x);
        v62.m128_f32[0] = (float)((float)((float)(eye.y - v63) * (float)(eye.y - v63)) + (float)(v64 * v64))
                        + (float)((float)(eye.z - v61) * (float)(eye.z - v61));
        v54 = _mm_sqrt_ps(v62).m128_f32[0] / v47;
        if ( v54 > 1.0 )
          v54 = *(float *)&FLOAT_1_0;
        v14->mInCollision = 1;
      }
    }
    v14->mAllowCanOccludeCamera = !v14->mInCollision;
    if ( !v14->mEyePushValid )
    {
      v14->mEyePushPercent = 0.0;
      v14->mEyePushValid = 1;
    }
    p_mEyePushPercent = &v14->mEyePushPercent;
    LODWORD(v66) = COERCE_UNSIGNED_INT(v54 - v14->mEyePushPercent) & _xmm;
    if ( UFG::tbCollisionForceSnap )
      *p_mEyePushPercent = v54;
    if ( v54 <= *p_mEyePushPercent )
    {
      mPushInOverrideRate = UFG::trCollisionApproachRateFactorOut;
    }
    else
    {
      mPushInOverrideRate = v14->mPushInOverrideRate;
      if ( mPushInOverrideRate <= 0.0 )
        mPushInOverrideRate = UFG::trCollisionApproachRateFactorIn;
    }
    UFG::qApproach(&v14->mEyePushPercent, v54, mPushInOverrideRate * v66, dt);
    v68 = v47 * *p_mEyePushPercent;
    v69 = v14->mCollisionBlend + v14->mCollisionPlateau;
    v70 = v68 - (float)(v47 - v69);
    if ( v70 <= 0.0 )
      v70 = 0.0;
    if ( v70 >= v69 )
      v70 = v14->mCollisionBlend + v14->mCollisionPlateau;
    mCollisionRise = v14->mCollisionRise;
    v72 = v70 / v14->mCollisionBlend;
    if ( v72 < 1.0 )
      mCollisionRise = (float)((float)(cosf((float)(v72 * 3.1415927) - 3.1415927) + 1.0) * 0.5) * mCollisionRise;
    mEyePushRise = v14->mEyePushRise;
    if ( mCollisionRise <= mEyePushRise )
      v74 = UFG::trCollisionEyeDropRate;
    else
      v74 = UFG::trCollisionEyeRiseRate;
    UFG::qApproach(
      &v14->mEyePushRise,
      mCollisionRise,
      COERCE_FLOAT(COERCE_UNSIGNED_INT(mEyePushRise - mCollisionRise) & _xmm) * v74,
      dt);
    v75 = FLOAT_0_050000001;
    v76 = v47 - v68;
    v77 = (float)((float)(v52 * v68) + eye.z) + v14->mEyePushRise;
    v78 = (float)(v50 * v68) + eye.x;
    v79 = (float)(v51 * v68) + eye.y;
    eye.z = v77;
    eye.x = v78;
    eye.y = v79;
    if ( v76 >= 0.050000001 )
      v75 = v76;
    p_ymax = &aWaterExcludeBoxes[0].ymax;
    v81 = &aWaterExcludeBoxes[0].ymax;
    v82 = (float)(v52 * v75) + v77;
    loook.x = v78 + (float)(v50 * v75);
    loook.y = v79 + (float)(v51 * v75);
    loook.z = v82;
    while ( v78 >= *(v81 - 1) || v78 <= *(v81 - 3) || v79 >= *v81 || v79 <= *(v81 - 2) )
    {
      v81 += 4;
      if ( (__int64)v81 >= (__int64)&UFG::GameCameraComponent::mDofDamageDomain[3] )
      {
        if ( v77 < UFG::trCollisionWaterLevel )
        {
          v77 = UFG::trCollisionWaterLevel;
          LOBYTE(retaddr) = 1;
          eye.z = UFG::trCollisionWaterLevel;
          goto LABEL_66;
        }
        break;
      }
    }
    LOBYTE(retaddr) = 0;
LABEL_66:
    if ( this )
    {
      *(float *)&this->vfptr = v78;
      *((float *)&this->vfptr + 1) = v79;
      *(float *)&this->m_SafePointerList.mNode.UFG::BaseCameraComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v77;
    }
    if ( v108 )
    {
      *v108 = v78 + (float)(v50 * v75);
      v108[1] = v79 + (float)(v51 * v75);
      v108[2] = v82;
    }
    UFG::BaseCameraComponent::SetEyeLookUp(v14, dt, &eye, &loook, &up);
    if ( UFG::tbCollisionDebugDraw )
    {
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      mLookModified = v14->mLookModified;
      v85 = "No";
      v86 = Context;
      v87 = "No";
      v88 = &UFG::qColour::White;
      if ( mLookModified )
        v87 = "Yes";
      if ( mLookModified )
        v88 = &UFG::qColour::Red;
      Render::DebugDrawContext::DrawTextA(Context, 240, 500, v88, "Look Modified : %s", v87);
      v89 = &UFG::qColour::White;
      if ( v14->mInCollision )
      {
        v85 = "Yes";
        if ( v14->mInCollision )
          v89 = &UFG::qColour::Red;
      }
      Render::DebugDrawContext::DrawTextA(v86, 240, 511, v89, "In Collision  : %s", v85);
      Render::DebugDrawContext::DrawTextA(v86, 240, 522, &UFG::qColour::White, "Collision Push: %f", v68);
      v90 = &UFG::qColour::White;
      v91 = v14->mEyePushRise;
      if ( v91 > 0.001 )
        v90 = &UFG::qColour::Red;
      Render::DebugDrawContext::DrawTextA(v86, 240, 533, v90, "Collision Rise: %f", v91);
      removePhantomWhenDone = *p_mEyePushPercent;
      v92 = &UFG::qColour::White;
      Render::DebugDrawContext::DrawTextA(
        v86,
        240,
        544,
        &UFG::qColour::White,
        "Push Percent  : %f",
        removePhantomWhenDone);
      Render::DebugDrawContext::DrawSphere(
        v86,
        centre,
        UFG::trCollisionTargetPointCastingRadius,
        &UFG::qColour::Blue,
        &UFG::qMatrix44::msIdentity,
        0i64);
      Render::DebugDrawContext::DrawSphere(
        v86,
        &loook,
        UFG::trCollisionTargetPointCastingRadius * 1.02,
        &UFG::qColour::White,
        &UFG::qMatrix44::msIdentity,
        0i64);
      Render::DebugDrawContext::DrawText(v86, centre, &UFG::qColour::Blue, "dL");
      Render::DebugDrawContext::DrawText(v86, &loook, &UFG::qColour::White, "  L");
      if ( v14->mAlternateLookValid )
      {
        Render::DebugDrawContext::DrawSphere(
          v86,
          &v14->mAlternateLook,
          UFG::trCollisionTargetPointCastingRadius * 0.98000002,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          0i64);
        Render::DebugDrawContext::DrawText(v86, &v14->mAlternateLook, &UFG::qColour::Green, "aL");
      }
      Render::DebugDrawContext::DrawSphere(
        v86,
        desEye,
        UFG::trCollisionCastingRadius,
        &UFG::qColour::Red,
        &UFG::qMatrix44::msIdentity,
        0i64);
      Render::DebugDrawContext::DrawSphere(
        v86,
        &eye,
        UFG::trCollisionCastingRadius * 1.02,
        &UFG::qColour::Yellow,
        &UFG::qMatrix44::msIdentity,
        0i64);
      Render::DebugDrawContext::DrawText(v86, desEye, &UFG::qColour::Red, "dE");
      Render::DebugDrawContext::DrawText(v86, &eye, &UFG::qColour::Yellow, "  E");
      result.x = (float)(loook.x + eye.x) * 0.5;
      result.y = (float)(loook.y + eye.y) * 0.5;
      result.z = UFG::trCollisionWaterLevel;
      Render::DebugDrawContext::DrawCircle(
        v86,
        &result,
        &UFG::qVector3::msAxisY,
        3.0,
        &UFG::qColour::Blue,
        &UFG::qMatrix44::msIdentity,
        0i64);
      v93 = 0;
      do
      {
        Render::DebugDrawContext::DrawRect(
          v86,
          *(p_ymax - 3) + *(p_ymax - 1),
          *(p_ymax - 2) + *p_ymax,
          *(p_ymax - 1) - *(p_ymax - 3),
          *p_ymax - *(p_ymax - 2),
          &UFG::qColour::Red);
        if ( eye.x < *(p_ymax - 1) && eye.x > *(p_ymax - 3) && eye.y < *p_ymax && eye.y > *(p_ymax - 2) )
          v93 = 1;
        p_ymax += 4;
      }
      while ( (__int64)p_ymax < (__int64)&UFG::GameCameraComponent::mDofDamageDomain[3] );
      v94 = "False";
      v95 = "False";
      v96 = &UFG::qColour::White;
      if ( v93 )
        v95 = "True";
      if ( v93 )
        v96 = &UFG::qColour::Red;
      Render::DebugDrawContext::DrawTextA(v86, 240, 555, v96, "Ignore Water Test: %s", v95);
      if ( (_BYTE)retaddr )
        v92 = &UFG::qColour::Red;
      if ( (_BYTE)retaddr )
        v94 = "True";
      Render::DebugDrawContext::DrawTextA(v86, 240, 566, v92, "DEye Below Water: %s", v94);
      v14 = v102;
    }
    *(_QWORD *)&v14->mCandidateEye.x = 0i64;
    v14->mCandidateEye.z = -100000.0;
  }
  else
  {
    v34 = &aWaterExcludeBoxes[0].ymax;
    while ( x >= *(v34 - 1) || x <= *(v34 - 3) || y >= *v34 || y <= *(v34 - 2) )
    {
      v34 += 4;
      if ( (__int64)v34 >= (__int64)&UFG::GameCameraComponent::mDofDamageDomain[3] )
      {
        if ( eye.z < UFG::trCollisionWaterLevel )
          eye.z = UFG::trCollisionWaterLevel;
        break;
      }
    }
    UFG::BaseCameraComponent::SetEyeLookUp(v14, dt, &eye, &loook, &up);
    if ( this )
    {
      v35 = eye.y;
      *(float *)&this->vfptr = eye.x;
      v36 = eye.z;
      *((float *)&this->vfptr + 1) = v35;
      *(float *)&this->m_SafePointerList.mNode.UFG::BaseCameraComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = v36;
    }
    if ( v107 )
    {
      v37 = loook.y;
      *v107 = loook.x;
      v38 = loook.z;
      v107[1] = v37;
      v107[2] = v38;
    }
  }
}

// File Line: 1525
// RVA: 0x3C39E0
bool __fastcall UFG::GameCameraComponent::GetSurfaceNormal(
        UFG::qVector3 *surfNormal,
        hkpCollidable *collidable,
        unsigned int shapeKey)
{
  hkpShape *m_shape; // rax
  bool result; // al
  unsigned __int64 m_userData; // rcx
  __int64 v8; // rax
  __int64 v9; // rbx
  const void *m_motion; // rcx
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm2
  hkVector4f v13; // xmm3
  float v14; // xmm4_4
  float v15; // xmm9_4
  float v16; // xmm5_4
  float v17; // xmm5_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  float v20; // xmm14_4
  float v21; // xmm9_4
  float v22; // xmm0_4
  float v23; // xmm9_4
  float v24; // xmm10_4
  float v25; // [rsp+20h] [rbp-308h]
  float v26; // [rsp+24h] [rbp-304h]
  float d; // [rsp+30h] [rbp-2F8h] BYREF
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
  hkTransformf v39; // [rsp+70h] [rbp-2B8h] BYREF
  char v40[512]; // [rsp+B0h] [rbp-278h] BYREF
  float v41; // [rsp+338h] [rbp+10h]
  float v42; // [rsp+348h] [rbp+20h]

  if ( !collidable )
    return 0;
  if ( shapeKey == -1 )
    return 0;
  m_shape = collidable->m_shape;
  if ( !collidable->m_shape )
    return 0;
  if ( m_shape->m_type.m_storage != 9 )
    return 0;
  m_userData = m_shape[2].m_userData;
  if ( !m_userData || *(_BYTE *)(m_userData + 41) != 1 )
    return 0;
  v8 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, char *))(*(_QWORD *)(m_userData + 32) + 40i64))(
         m_userData + 32,
         shapeKey,
         v40);
  v9 = v8;
  if ( !v8 || *(_BYTE *)(v8 + 16) != 2 )
    return 0;
  m_motion = collidable->m_motion;
  v11.m_quad = (__m128)*((_OWORD *)m_motion + 1);
  v12.m_quad = (__m128)*((_OWORD *)m_motion + 2);
  v13.m_quad = (__m128)*((_OWORD *)m_motion + 3);
  v39.m_rotation.m_col0 = *(hkVector4f *)m_motion;
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
  v26 = (float)((float)(v15 + v18) + v11.m_quad.m128_f32[0]) + v38;
  v25 = (float)((float)((float)(v30 * v12.m_quad.m128_f32[0]) + (float)(d * v13.m_quad.m128_f32[0])) + (float)(v33 * v19))
      + v36;
  v20 = (float)((float)((float)((float)(v31 * v12.m_quad.m128_f32[0]) + (float)(v28 * v13.m_quad.m128_f32[0]))
                      + (float)(v34 * v19))
              + v37)
      - (float)(v17 + v37);
  v21 = v32 * v12.m_quad.m128_f32[0];
  v12.m_quad.m128_i32[0] = *(_DWORD *)(v9 + 88);
  result = 1;
  v22 = *(float *)(v9 + 84);
  v11.m_quad.m128_i32[0] = *(_DWORD *)(v9 + 80);
  v23 = (float)((float)((float)(v21 + (float)(v29 * v13.m_quad.m128_f32[0])) + (float)(v35 * v19)) + v38) - v26;
  v42 = (float)((float)((float)(v30 * v22) + (float)(d * v11.m_quad.m128_f32[0])) + (float)(v33 * v12.m_quad.m128_f32[0]))
      + v36;
  v24 = (float)((float)((float)((float)(v31 * v22) + (float)(v28 * v11.m_quad.m128_f32[0]))
                      + (float)(v34 * v12.m_quad.m128_f32[0]))
              + v37)
      - (float)(v17 + v37);
  v13.m_quad.m128_f32[0] = (float)((float)((float)((float)(v32 * v22) + (float)(v29 * v11.m_quad.m128_f32[0]))
                                         + (float)(v35 * v12.m_quad.m128_f32[0]))
                                 + v38)
                         - v26;
  surfNormal->x = (float)(v20 * v13.m_quad.m128_f32[0]) - (float)(v23 * v24);
  surfNormal->z = (float)((float)(v25 - v41) * v24) - (float)(v20 * (float)(v42 - v41));
  surfNormal->y = (float)(v23 * (float)(v42 - v41)) - (float)((float)(v25 - v41) * v13.m_quad.m128_f32[0]);
  return result;
}

// File Line: 1581
// RVA: 0x3CD680
char __fastcall UFG::GameCameraComponent::ShouldPassThru(
        UFG::GameCameraComponent *this,
        UFG::ShapeCasterCollector::HitInfo *info,
        UFG::qVector3 *startPos)
{
  hkpRigidBody *mRigidBody; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  UFG::qReflectObject *mData; // rax
  hkVector4f v10; // xmm1
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm3
  __int64 v13; // r8
  __m128 v14; // xmm1
  float x; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4
  UFG::SimObjectCharacter *mSimObject; // rbx
  __int16 m_Flags; // cx
  UFG::TargetingSystemItemComponent *ComponentOfTypeHK; // rax
  __int16 v21; // cx
  UFG::CharacterSubjectComponent *ComponentOfType; // rax
  UFG::SimObject *pSimObjectPassThru1; // rax
  UFG::SimObject *pSimObjectPassThru2; // rax
  char v25; // bl
  UFG::qVector3 surfNormal; // [rsp+20h] [rbp-E0h] BYREF
  __m128 v28; // [rsp+30h] [rbp-D0h] BYREF
  __m128 v29; // [rsp+40h] [rbp-C0h]
  UFG::qReflectHandleBase v30; // [rsp+50h] [rbp-B0h] BYREF
  __int64 v31; // [rsp+78h] [rbp-88h]
  _OWORD v32[3]; // [rsp+80h] [rbp-80h] BYREF
  __m128 m_quad; // [rsp+B0h] [rbp-50h]
  hkpRigidBodyCinfo info_8; // [rsp+C0h] [rbp-40h] BYREF

  v31 = -2i64;
  if ( info )
  {
    mRigidBody = info->mRigidBody;
    if ( mRigidBody )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v30);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
      v30.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&v30, v30.mTypeUID, info->mPhysicsObjectPropertyHandleUID);
      mData = v30.mData;
      if ( !v30.mData )
        goto LABEL_17;
      if ( BYTE5(v30.mData[1].mHandles.mNode.mPrev) )
      {
        if ( BYTE6(v30.mData[1].mHandles.mNode.mPrev) && this->mAllowCanOccludeCamera )
        {
          hkpRigidBodyCinfo::hkpRigidBodyCinfo(&info_8);
          hkpRigidBody::getCinfo(mRigidBody, &info_8);
          v10.m_quad = (__m128)mRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
          v11.m_quad = (__m128)mRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
          v12.m_quad = (__m128)mRigidBody->m_motion.m_motionState.m_transform.m_translation;
          v32[0] = mRigidBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
          v32[1] = v10.m_quad;
          v32[2] = v11.m_quad;
          m_quad = v12.m_quad;
          ((void (__fastcall *)(hkpShape *, _OWORD *, __int64, __m128 *))info_8.m_shape->vfptr[2].__vecDelDtor)(
            info_8.m_shape,
            v32,
            v13,
            &v28);
          v14 = _mm_shuffle_ps(
                  (__m128)LODWORD(UFG::gCanOccludeTolerance),
                  (__m128)LODWORD(UFG::gCanOccludeTolerance),
                  0);
          v29 = _mm_add_ps(v29, v14);
          v28 = _mm_sub_ps(v28, v14);
          x = this->mCandidateEye.x;
          if ( x < v28.m128_f32[0] )
            goto LABEL_45;
          if ( x > v29.m128_f32[0] )
            goto LABEL_45;
          y = this->mCandidateEye.y;
          if ( y < v28.m128_f32[1] )
            goto LABEL_45;
          if ( y > v29.m128_f32[1] )
            goto LABEL_45;
          z = this->mCandidateEye.z;
          if ( z < v28.m128_f32[2] || z > v29.m128_f32[2] )
            goto LABEL_45;
          mData = v30.mData;
        }
        if ( !BYTE1(mData[2].vfptr)
          || !UFG::GameCameraComponent::GetSurfaceNormal(&surfNormal, info->mCollidableB, info->mShapeKeyB)
          || (float)((float)((float)(surfNormal.x * (float)(startPos->x - info->mContactPosition.x))
                           + (float)(surfNormal.y * (float)(startPos->y - info->mContactPosition.y)))
                   + (float)(surfNormal.z * (float)(startPos->z - info->mContactPosition.z))) >= 0.0 )
        {
LABEL_17:
          mSimObject = (UFG::SimObjectCharacter *)info->mSimObject;
          if ( !mSimObject
            || ((m_Flags = mSimObject->m_Flags, (m_Flags & 0x4000) != 0) || m_Flags < 0
              ? (ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemItemComponent>(mSimObject))
              : (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
              ? (ComponentOfTypeHK = (UFG::TargetingSystemItemComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            mSimObject,
                                                                            UFG::TargetingSystemItemComponent::_TypeUID))
              : (ComponentOfTypeHK = (UFG::TargetingSystemItemComponent *)UFG::SimObject::GetComponentOfType(
                                                                            mSimObject,
                                                                            UFG::TargetingSystemItemComponent::_TypeUID)),
                !ComponentOfTypeHK
             && ((v21 = mSimObject->m_Flags, (v21 & 0x4000) == 0)
               ? (v21 >= 0 && (v21 & 0x2000) == 0 && (v21 & 0x1000) == 0
                ? (ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                         mSimObject,
                                                                         UFG::CharacterSubjectComponent::_TypeUID))
                : (ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         mSimObject,
                                                                         UFG::CharacterSubjectComponent::_TypeUID)))
               : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(mSimObject)),
                 !ComponentOfType)) )
          {
            if ( (!UFG::GameCameraComponent::mCollisionIgnoreAllCharacters
               || !mSimObject
               || (mSimObject->m_Flags & 0x4000) == 0)
              && (!UFG::GameCameraComponent::mCollisionIgnoreAllVehicles
               || !mSimObject
               || (mSimObject->m_Flags & 0x8000u) == 0) )
            {
              pSimObjectPassThru1 = this->pSimObjectPassThru1;
              if ( !pSimObjectPassThru1 || mSimObject != pSimObjectPassThru1 )
              {
                pSimObjectPassThru2 = this->pSimObjectPassThru2;
                if ( !pSimObjectPassThru2 || mSimObject != pSimObjectPassThru2 )
                {
                  v25 = 0;
                  goto LABEL_47;
                }
              }
            }
          }
        }
      }
LABEL_45:
      v25 = 1;
LABEL_47:
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::GameSubject::s_GameSubjectList__);
}

// File Line: 1689
// RVA: 0x3C3F00
__int64 __fastcall UFG::CopRoadBlock::GetTypeSize(UFG::GameSubject *this)
{
  return 304i64;
}

// File Line: 1694
// RVA: 0x3BCC30
void __fastcall UFG::GameSubject::GameSubject(UFG::GameSubject *this, unsigned int name_uid)
{
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraSubject::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->pTransformNodeComponent);
  UFG::SimComponent::AddType(this, UFG::CameraSubject::_CameraSubjectTypeUID, "CameraSubject");
  UFG::CameraSubject::Init(this);
  this->mPrev = &this->UFG::qNode<UFG::GameSubject,UFG::GameSubject>;
  this->mNext = &this->UFG::qNode<UFG::GameSubject,UFG::GameSubject>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameSubject::`vftable;
  mPrev = UFG::GameSubject::s_GameSubjectList.mNode.mPrev;
  UFG::GameSubject::s_GameSubjectList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::GameSubject,UFG::GameSubject>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::GameSubject,UFG::GameSubject> *)&UFG::GameSubject::s_GameSubjectList;
  UFG::GameSubject::s_GameSubjectList.mNode.mPrev = &this->UFG::qNode<UFG::GameSubject,UFG::GameSubject>;
  UFG::SimComponent::AddType(this, UFG::GameSubject::_GameSubjectTypeUID, "GameSubject");
}

// File Line: 1701
// RVA: 0x3BDF60
void __fastcall UFG::GameSubject::~GameSubject(UFG::GameSubject *this)
{
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v2; // rdx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *mPrev; // rcx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *mNext; // rax
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v5; // rcx
  UFG::qNode<UFG::GameSubject,UFG::GameSubject> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::GameSubject::`vftable;
  if ( this == UFG::GameSubject::s_GameSubjectpCurrentIterator )
    UFG::GameSubject::s_GameSubjectpCurrentIterator = (UFG::GameSubject *)&this->mPrev[-18];
  v2 = &this->UFG::qNode<UFG::GameSubject,UFG::GameSubject>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraSubject::`vftable;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->pTransformNodeComponent);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 1717
// RVA: 0x3C81E0
UFG::GameSubject *__fastcall UFG::GameSubject::PropertiesOnActivate(
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
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x130ui64, "GameSubject", 0i64, 1u);
  if ( v4 )
  {
    UFG::GameSubject::GameSubject((UFG::GameSubject *)v4, m_NameUID);
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
  return (UFG::GameSubject *)v6;
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

