// File Line: 76
// RVA: 0x14BF550
const char *dynamic_initializer_for__sPoseDriverFactoryList__()
{
  const char *result; // rax

  sPoseDriverFactoryList[0].mClassName = RootUprightDriver::sClassName;
  sPoseDriverFactoryList[1].mClassName = AimConstraint::sClassName;
  sPoseDriverFactoryList[2].mClassName = AimConstraint2::sClassName;
  sPoseDriverFactoryList[3].mClassName = AimConstraintMultiLink::sClassName;
  sPoseDriverFactoryList[4].mClassName = TwoLinkIKsolver::sClassName;
  sPoseDriverFactoryList[5].mClassName = OrientationConstraint::sClassName;
  sPoseDriverFactoryList[6].mClassName = TwistXRotLinearLink::sClassName;
  sPoseDriverFactoryList[7].mClassName = FollowLink::sClassName;
  sPoseDriverFactoryList[8].mClassName = Follow2Link::sClassName;
  sPoseDriverFactoryList[9].mClassName = Follow3Link::sClassName;
  result = Spring1DOF::sClassName;
  sPoseDriverFactoryList[10].mClassName = Spring1DOF::sClassName;
  return result;
}

// File Line: 82
// RVA: 0x14BCFF0
__int64 dynamic_initializer_for__gPoseDriverFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gPoseDriverFactory, sPoseDriverFactoryList, sPoseDriverFactoryListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gPoseDriverFactory__);
}

// File Line: 84
// RVA: 0x14BF7B0
__int64 dynamic_initializer_for__symEffectorNone__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("none", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symEffectorNone, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symEffectorNone__);
}

// File Line: 90
// RVA: 0x39E2B0
void __fastcall PoseDriver::PoseDriver(PoseDriver *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
}

// File Line: 95
// RVA: 0x39FA60
void __fastcall PoseDriver::~PoseDriver(PoseDriver *this)
{
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rdx
  UFG::qNode<PoseDriver,PoseDriver> *mNext; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 163
// RVA: 0x14B95F0
__int64 dynamic_initializer_for__AimConstraint::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AimConstraint", 0xFFFFFFFF);
  AimConstraint::sClassNameUID = result;
  return result;
}

// File Line: 194
// RVA: 0x39CC30
void __fastcall AimConstraint::AimConstraint(AimConstraint *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimConstraint::`vftable;
  this->mAimAxis.mValue = 1;
  this->mEffectorJoint = UFG::gNullQSymbolUC;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mAimAxisLS.x = UFG::qVector3::msZero.x;
  this->mAimAxisLS.y = y;
  this->mAimAxisLS.z = z;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->mTargetPointWS.x = UFG::qVector3::msZero.x;
  this->mTargetPointWS.y = v3;
  this->mTargetPointWS.z = v4;
  *(_QWORD *)&this->mRotationX = 0i64;
  this->mRotationY = 0.0;
  this->mXJointLimitMag = 0.87266463;
  this->mZJointLimitMag = 0.40000001;
  this->mYJointLimitMag = 0.40000001;
  *(_QWORD *)&this->mTrackingGain = 1036831949i64;
}

// File Line: 211
// RVA: 0x3B05F0
bool __fastcall AimConstraint::Update(AimConstraint *this, float timeDelta)
{
  bool result; // al
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm1_4

  result = 1;
  v3 = timeDelta * 2.0;
  if ( this->mActive )
  {
    v4 = v3 + this->mWeight;
    this->mWeight = v4;
    if ( v4 > 1.0 )
      this->mWeight = 1.0;
  }
  else
  {
    v5 = this->mWeight - v3;
    this->mWeight = v5;
    if ( v5 <= 0.0 )
      this->mWeight = 0.0;
  }
  return result;
}

// File Line: 224
// RVA: 0x3B19B0
void __fastcall AimConstraint::UpdatePose(AimConstraint *this, SkeletalPose *pose)
{
  float v4; // xmm11_4
  float v5; // xmm7_4
  __int64 mJointID; // r8
  hkaPose *mHavokPose; // rdx
  float v8; // xmm2_4
  __m128 y_low; // xmm3
  float v10; // xmm4_4
  __m128 v11; // xmm5
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm4_4
  float v16; // xmm13_4
  __m128 v17; // xmm8
  __m128 v18; // xmm9
  __m128 v19; // xmm3
  unsigned int v20; // xmm0_4
  float mZJointLimitMag; // xmm8_4
  unsigned int mXJointLimitMag_low; // xmm6_4
  int v23; // xmm12_4
  unsigned int mYJointLimitMag_low; // xmm2_4
  float mTrackingGain; // xmm1_4
  float rotY; // xmm2_4
  float v27; // xmm6_4
  float v28; // xmm8_4
  float v29; // xmm8_4
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  double v34; // xmm6_8
  float v35; // xmm5_4
  float v36; // xmm8_4
  float v37; // xmm4_4
  double v38; // xmm0_8
  float mYJointLimitMag; // xmm1_4
  float v40; // xmm1_4
  UFG::qMatrix44 *v41; // rax
  UFG::qVector4 v42; // xmm2
  UFG::qVector4 v43; // xmm1
  UFG::qVector4 v44; // xmm0
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qMatrix44 result; // [rsp+70h] [rbp-88h] BYREF
  float v47; // [rsp+B0h] [rbp-48h]
  float v48; // [rsp+B8h] [rbp-40h]
  float v49; // [rsp+BCh] [rbp-3Ch]
  float v50; // [rsp+C0h] [rbp-38h]
  float v51; // [rsp+C8h] [rbp-30h]
  float v52; // [rsp+CCh] [rbp-2Ch]
  float v53; // [rsp+D0h] [rbp-28h]
  hkQsTransformf v54; // [rsp+E8h] [rbp-10h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+118h] [rbp+20h] BYREF
  UFG::qMatrix44 sourceA; // [rsp+158h] [rbp+60h] BYREF
  UFG::qMatrix44 d; // [rsp+198h] [rbp+A0h] BYREF
  UFG::qMatrix44 v58; // [rsp+1D8h] [rbp+E0h] BYREF
  UFG::qMatrix44 dest; // [rsp+218h] [rbp+120h] BYREF
  UFG::qMatrix44 v60; // [rsp+258h] [rbp+160h] BYREF

  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v4 = *(float *)&FLOAT_1_0;
  v5 = (float)(sinf((float)(this->mWeight * 3.1415927) - 1.5707964) + 1.0) * 0.5;
  if ( v5 <= 0.0 )
  {
    v5 = 0.0;
LABEL_5:
    if ( v5 <= 0.0 )
      return;
    goto LABEL_6;
  }
  if ( v5 < 1.0 )
    goto LABEL_5;
  v5 = *(float *)&FLOAT_1_0;
LABEL_6:
  mJointID = this->mJointID;
  mHavokPose = pose->mHavokPose;
  v54 = mHavokPose->m_skeleton->m_referencePose.m_data[mJointID];
  SkeletalPose::GetPositionWS(pose, mHavokPose->m_skeleton->m_parentIndices.m_data[mJointID], &matrixWS);
  hkQsTransformf::get4x4ColumnMajor(&v54, &d.v0.x);
  UFG::qMatrix44::operator*(&d, &result, &matrixWS);
  m.v0 = result.v0;
  m.v1 = *(UFG::qVector4 *)&result.v0.z;
  m.v2 = *(UFG::qVector4 *)&result.v1.z;
  m.v3 = *(UFG::qVector4 *)&result.v2.z;
  UFG::qTranspose((UFG::qMatrix44 *)&result.v3.z, &m);
  y_low = (__m128)LODWORD(this->mTargetPointWS.y);
  v8 = this->mTargetPointWS.x - m.v3.x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - m.v3.y;
  v11 = y_low;
  v10 = this->mTargetPointWS.z - m.v3.z;
  v11.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  v13 = v8 * v12;
  v14 = y_low.m128_f32[0] * v12;
  v15 = v10 * v12;
  v17 = (__m128)LODWORD(v49);
  v18 = (__m128)LODWORD(v50);
  v16 = (float)((float)(v48 * v14) + (float)(result.v3.z * v13)) + (float)(v51 * v15);
  v17.m128_f32[0] = (float)((float)(v49 * v14) + (float)(result.v3.w * v13)) + (float)(v52 * v15);
  v18.m128_f32[0] = (float)((float)(v50 * v14) + (float)(v47 * v13)) + (float)(v53 * v15);
  if ( this->mAimAxis.mValue == 2 )
  {
    v19 = v18;
    v19.m128_f32[0] = (float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v16 * v16);
    *(float *)&v20 = atan2f(v17.m128_f32[0], _mm_sqrt_ps(v19).m128_f32[0]);
    mZJointLimitMag = 0.0;
    mXJointLimitMag_low = v20;
    v23 = _xmm[0];
    mYJointLimitMag_low = COERCE_UNSIGNED_INT(atan2f(v16, v18.m128_f32[0])) ^ _xmm[0];
  }
  else
  {
    v23 = _xmm[0];
    mXJointLimitMag_low = COERCE_UNSIGNED_INT(atan2f(v18.m128_f32[0], v17.m128_f32[0])) ^ _xmm[0];
    v17.m128_f32[0] = (float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v18.m128_f32[0] * v18.m128_f32[0]);
    *(float *)&mYJointLimitMag_low = 0.0;
    mZJointLimitMag = atan2f(v16, _mm_sqrt_ps(v17).m128_f32[0]);
  }
  if ( *(float *)&mXJointLimitMag_low <= COERCE_FLOAT(LODWORD(this->mXJointLimitMag) ^ v23) )
    mXJointLimitMag_low = LODWORD(this->mXJointLimitMag) ^ v23;
  if ( *(float *)&mXJointLimitMag_low >= this->mXJointLimitMag )
    mXJointLimitMag_low = LODWORD(this->mXJointLimitMag);
  if ( mZJointLimitMag <= COERCE_FLOAT(LODWORD(this->mZJointLimitMag) ^ v23) )
    LODWORD(mZJointLimitMag) = LODWORD(this->mZJointLimitMag) ^ v23;
  if ( mZJointLimitMag >= this->mZJointLimitMag )
    mZJointLimitMag = this->mZJointLimitMag;
  if ( *(float *)&mYJointLimitMag_low <= COERCE_FLOAT(LODWORD(this->mYJointLimitMag) ^ v23) )
    mYJointLimitMag_low = LODWORD(this->mYJointLimitMag) ^ v23;
  if ( *(float *)&mYJointLimitMag_low >= this->mYJointLimitMag )
    mYJointLimitMag_low = LODWORD(this->mYJointLimitMag);
  mTrackingGain = this->mTrackingGain;
  rotY = (float)((float)(*(float *)&mYJointLimitMag_low - this->mRotationY) * mTrackingGain) + this->mRotationY;
  v27 = (float)((float)(*(float *)&mXJointLimitMag_low - this->mRotationX) * mTrackingGain) + this->mRotationX;
  v28 = (float)((float)(mZJointLimitMag - this->mRotationZ) * mTrackingGain) + this->mRotationZ;
  this->mRotationY = rotY;
  this->mRotationX = v27;
  this->mRotationZ = v28;
  AimConstraint::applyRotationXZY(this, &m, v27, v28, rotY);
  if ( sUntwist && this->mAimAxis.mValue != 2 )
  {
    v29 = 1.0 - (float)(m.v1.z * m.v1.z);
    LODWORD(v30) = COERCE_UNSIGNED_INT(m.v1.z * m.v1.x) ^ v23;
    LODWORD(v31) = COERCE_UNSIGNED_INT(m.v1.z * m.v1.y) ^ v23;
    v32 = (float)((float)(v31 * v31) + (float)(v30 * v30)) + (float)(v29 * v29);
    if ( v32 == 0.0 )
      v33 = 0.0;
    else
      v33 = 1.0 / fsqrt(v32);
    *(_QWORD *)&v34 = LODWORD(m.v0.y);
    v35 = v31 * v33;
    v36 = v29 * v33;
    v37 = v30 * v33;
    if ( (float)((float)((float)((float)((float)(m.v0.x * v36) - (float)(m.v0.z * v37)) * m.v1.y)
                       + (float)((float)((float)(m.v0.z * v35) - (float)(m.v0.y * v36)) * m.v1.x))
               + (float)((float)((float)(m.v0.y * v37) - (float)(m.v0.x * v35)) * m.v1.z)) > 0.0 )
      v4 = FLOAT_N1_0;
    *(float *)&v34 = (float)((float)(m.v0.y * v35) + (float)(m.v0.x * v37)) + (float)(m.v0.z * v36);
    v38 = UFG::qACos(v34);
    mYJointLimitMag = *(float *)&v38 * v4;
    if ( (float)(*(float *)&v38 * v4) <= COERCE_FLOAT(LODWORD(this->mYJointLimitMag) ^ v23) )
      LODWORD(mYJointLimitMag) = LODWORD(this->mYJointLimitMag) ^ v23;
    if ( mYJointLimitMag >= this->mYJointLimitMag )
      mYJointLimitMag = this->mYJointLimitMag;
    v40 = (float)((float)(mYJointLimitMag - this->mRotationY) * this->mTrackingGain) + this->mRotationY;
    this->mRotationY = v40;
    UFG::qRotationMatrixY(&dest, v40);
    v41 = UFG::qMatrix44::operator*(&dest, &v60, &m);
    v42 = v41->v2;
    v43 = v41->v3;
    v44 = v41->v0;
    m.v1 = v41->v1;
    m.v2 = v42;
    m.v0 = v44;
    m.v3 = v43;
  }
  SkeletalPose::GetPositionWS(pose, this->mJointID, &sourceA);
  BlendSlerp(&v58, &sourceA, &m, v5);
  SkeletalPose::SetPositionWS(pose, this->mJointID, &v58);
}

// File Line: 390
// RVA: 0x3B6400
void __fastcall AimConstraint::applyRotationXZY(
        AimConstraint *this,
        UFG::qVector3 *targetmatrix,
        float rotX,
        float rotZ,
        float rotY)
{
  float y; // xmm1_4
  float z; // xmm4_4
  float v8; // xmm8_4
  float v9; // xmm7_4
  float x; // xmm9_4
  UFG::qMatrix44 *v12; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm3
  UFG::qVector4 v15; // xmm1
  UFG::qMatrix44 *v16; // rax
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm3
  UFG::qVector4 v19; // xmm1
  UFG::qMatrix44 *v20; // rax
  UFG::qVector4 v21; // xmm3
  UFG::qVector4 v22; // xmm2
  UFG::qVector4 v23; // xmm1
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-88h] BYREF

  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v8 = targetmatrix[4].y;
  v9 = targetmatrix[4].z;
  x = targetmatrix[4].x;
  targetmatrix[4].x = UFG::qVector3::msZero.x;
  targetmatrix[4].y = y;
  targetmatrix[5].x = 1.0;
  targetmatrix[4].z = z;
  UFG::qRotationMatrixAxis(&dest, targetmatrix, rotX);
  v12 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)targetmatrix, &result, &dest);
  v13 = v12->v1;
  v14 = v12->v2;
  v15 = v12->v3;
  *(UFG::qVector4 *)&targetmatrix->x = v12->v0;
  *(UFG::qVector4 *)&targetmatrix[1].y = v13;
  *(UFG::qVector4 *)&targetmatrix[2].z = v14;
  *(UFG::qVector4 *)&targetmatrix[4].x = v15;
  UFG::qRotationMatrixAxis(&dest, (UFG::qVector3 *)((char *)targetmatrix + 32), rotZ);
  v16 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)targetmatrix, &result, &dest);
  v17 = v16->v2;
  v18 = v16->v1;
  v19 = v16->v3;
  *(UFG::qVector4 *)&targetmatrix->x = v16->v0;
  *(UFG::qVector4 *)&targetmatrix[1].y = v18;
  *(UFG::qVector4 *)&targetmatrix[2].z = v17;
  *(UFG::qVector4 *)&targetmatrix[4].x = v19;
  UFG::qRotationMatrixAxis(&dest, (UFG::qVector3 *)((char *)targetmatrix + 16), rotY);
  v20 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)targetmatrix, &result, &dest);
  v21 = v20->v1;
  v22 = v20->v2;
  v23 = v20->v3;
  *(UFG::qVector4 *)&targetmatrix->x = v20->v0;
  *(UFG::qVector4 *)&targetmatrix[1].y = v21;
  *(UFG::qVector4 *)&targetmatrix[2].z = v22;
  *(UFG::qVector4 *)&targetmatrix[4].x = v23;
  targetmatrix[4].x = x;
  targetmatrix[5].x = 1.0;
  targetmatrix[4].y = v8;
  targetmatrix[4].z = v9;
}

// File Line: 438
// RVA: 0x14B95D0
__int64 dynamic_initializer_for__AimConstraint2::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AimConstraint2", 0xFFFFFFFF);
  AimConstraint2::sClassNameUID = result;
  return result;
}

// File Line: 463
// RVA: 0x39CBB0
void __fastcall AimConstraint2::AimConstraint2(AimConstraint2 *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimConstraint2::`vftable;
  this->mEffectorJoint = UFG::gNullQSymbolUC;
  this->mTargetJoint = UFG::gNullQSymbolUC;
  *(_QWORD *)&this->mJointID = -1i64;
}

// File Line: 514
// RVA: 0x3B1660
void __fastcall AimConstraint2::UpdatePose(AimConstraint2 *this, SkeletalPose *pose)
{
  bool v4; // sf
  int mTargetJointID; // edx
  hkQsTransformf *TranslationMS; // rbx
  float x; // xmm9_4
  float y; // xmm10_4
  float z; // xmm11_4
  float v10; // xmm3_4
  __m128 v11; // xmm4
  float v12; // xmm5_4
  __m128 v13; // xmm2
  float v14; // xmm1_4
  __m128 z_low; // xmm6
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm8_4
  float v20; // xmm7_4
  float v21; // xmm0_4
  UFG::qMatrix44 *v22; // rax
  UFG::qVector4 v23; // xmm4
  UFG::qVector4 v24; // xmm3
  UFG::qVector4 v25; // xmm2
  float v26; // xmm0_4
  UFG::qMatrix44 *v27; // rax
  UFG::qVector4 v28; // xmm2
  UFG::qVector4 v29; // xmm1
  UFG::qVector4 v30; // xmm0
  int mJointID; // edx
  UFG::qMatrix44 p; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector4 b; // [rsp+60h] [rbp-98h] BYREF
  __int64 b_16; // [rsp+70h] [rbp-88h]
  UFG::qVector4 b_24; // [rsp+78h] [rbp-80h]
  UFG::qVector4 b_40; // [rsp+88h] [rbp-70h]
  UFG::qMatrix44 b_56; // [rsp+98h] [rbp-60h] BYREF
  UFG::qMatrix44 dest; // [rsp+D8h] [rbp-20h] BYREF
  UFG::qMatrix44 v39; // [rsp+118h] [rbp+20h] BYREF
  hkQsTransformf v40; // [rsp+158h] [rbp+60h] BYREF
  UFG::qMatrix44 result; // [rsp+188h] [rbp+90h] BYREF

  if ( !gDisablePoseDrivers )
  {
    v4 = this->mJointID < 0;
    this->mActive = 1;
    if ( !v4 )
    {
      mTargetJointID = this->mTargetJointID;
      if ( mTargetJointID >= 0 )
      {
        TranslationMS = SkeletalPose::GetTranslationMS(pose, mTargetJointID);
        SkeletalPose::GetPositionMS(pose, this->mJointID, &b_56);
        UFG::qTranspose(&dest, &b_56);
        v11 = (__m128)TranslationMS->m_translation.m_quad.m128_u32[1];
        x = b_56.v3.x;
        y = b_56.v3.y;
        z = b_56.v3.z;
        v10 = TranslationMS->m_translation.m_quad.m128_f32[0] - b_56.v3.x;
        v11.m128_f32[0] = v11.m128_f32[0] - b_56.v3.y;
        v12 = TranslationMS->m_translation.m_quad.m128_f32[2] - b_56.v3.z;
        v13 = v11;
        v13.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(v10 * v10)) + (float)(v12 * v12);
        if ( v13.m128_f32[0] == 0.0 )
          v14 = 0.0;
        else
          v14 = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
        z_low = (__m128)LODWORD(dest.v1.z);
        v16 = v10 * v14;
        v17 = v11.m128_f32[0] * v14;
        v18 = v12 * v14;
        p = b_56;
        v19 = (float)((float)(dest.v1.x * v17) + (float)(dest.v0.x * v16)) + (float)(dest.v2.x * v18);
        v20 = (float)((float)(dest.v1.y * v17) + (float)(dest.v0.y * v16)) + (float)(dest.v2.y * v18);
        z_low.m128_f32[0] = (float)((float)(dest.v1.z * v17) + (float)(dest.v0.z * v16)) + (float)(dest.v2.z * v18);
        v21 = atan2f(z_low.m128_f32[0], v19);
        UFG::qRotationMatrixY(&v39, COERCE_FLOAT(LODWORD(v21) ^ _xmm[0]));
        b = p.v0;
        b_16 = *(_QWORD *)&p.v1.x;
        b_24 = p.v2;
        b_40 = p.v3;
        v22 = UFG::qMatrix44::operator*(&v39, &result, (UFG::qMatrix44 *)&b);
        z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v19 * v19);
        v23 = v22->v1;
        v24 = v22->v2;
        v25 = v22->v3;
        p.v0 = v22->v0;
        p.v1 = v23;
        p.v2 = v24;
        p.v3 = v25;
        v26 = atan2f(v20, _mm_sqrt_ps(z_low).m128_f32[0]);
        UFG::qRotationMatrixZ(&v39, v26);
        b = p.v0;
        b_16 = *(_QWORD *)&p.v1.x;
        b_24 = v24;
        b_40 = v25;
        v27 = UFG::qMatrix44::operator*(&v39, &result, (UFG::qMatrix44 *)&b);
        v28 = v27->v2;
        v29 = v27->v3;
        v30 = v27->v0;
        p.v1 = v27->v1;
        p.v2 = v28;
        p.v0 = v30;
        p.v3 = v29;
        hkQsTransformf::set4x4ColumnMajor(&v40, &p.v0.x);
        hkQsTransformf::get4x4ColumnMajor(&v40, &p.v0.x);
        mJointID = this->mJointID;
        p.v3.x = x;
        p.v3.y = y;
        p.v3.z = z;
        p.v3.w = 1.0;
        SkeletalPose::SetPositionMS(pose, mJointID, &p);
      }
    }
  }
}v3.z = z;
        p.v3.w = 1.0;
        SkeletalPose::SetPositionMS(pose, mJ

// File Line: 618
// RVA: 0x14B9610
__int64 dynamic_initializer_for__AimConstraintMultiLink::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AimConstraintMultiLink", 0xFFFFFFFF);
  AimConstraintMultiLink::sClassNameUID = result;
  return result;
}

// File Line: 665
// RVA: 0x39CD20
void __fastcall AimConstraintMultiLink::AimConstraintMultiLink(AimConstraintMultiLink *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimConstraintMultiLink::`vftable;
  this->mFirstJoint = UFG::gNullQSymbolUC;
  this->mSecondJoint = UFG::gNullQSymbolUC;
  this->mThirdJoint = UFG::gNullQSymbolUC;
  this->mEndJoint = UFG::gNullQSymbolUC;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mTargetPointWS.x = UFG::qVector3::msZero.x;
  this->mTargetPointWS.y = y;
  this->mTargetPointWS.z = z;
  this->mActive = 0;
  *(_QWORD *)&this->mRotationX = 0i64;
  this->mRotationY = 0.0;
  this->mXJointLimitMaxMag = 0.87266463;
  this->mZJointLimitMaxMag = 0.40000001;
  this->mYJointLimitMaxMag = 0.40000001;
  this->mXJointLimitMinMag = -0.87266463;
  this->mZJointLimitMinMag = -0.40000001;
  this->mYJointLimitMinMag = -0.40000001;
  *(_QWORD *)&this->mTrackingGain = 1036831949i64;
  this->mJointCount = 0;
}

// File Line: 726
// RVA: 0x3B0640
bool __fastcall AimConstraintMultiLink::Update(AimConstraintMultiLink *this, float timeDelta)
{
  bool v2; // zf
  bool result; // al
  float v4; // xmm0_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v2 = this->mActive == 0;
  this->mUpdated = 0;
  result = 1;
  v4 = timeDelta * 2.0;
  if ( v2 )
  {
    v6 = this->mWeight - v4;
    this->mWeight = v6;
    if ( v6 <= 0.0 )
      this->mWeight = 0.0;
  }
  else
  {
    v5 = v4 + this->mWeight;
    this->mWeight = v5;
    if ( v5 > 1.0 )
      this->mWeight = 1.0;
  }
  return result;
}

// File Line: 761
// RVA: 0x3B7840
void __fastcall AimConstraintMultiLink::getTargetRotations(
        AimConstraintMultiLink *this,
        SkeletalPose *pose,
        float *rotX,
        float *rotY,
        float *rotZ)
{
  float x; // xmm3_4
  float y; // xmm2_4
  float z; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm8_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  __m128 y_low; // xmm7
  float v16; // xmm8_4
  float v17; // xmm8_4
  __m128 v18; // xmm3
  float v19; // xmm6_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qMatrix44 matrixRoot; // [rsp+60h] [rbp-78h] BYREF

  SkeletalPose::GetRootMatrix(pose, &matrixRoot);
  UFG::qInverseAffine(&d, &matrixRoot);
  x = this->mTargetPointWS.x;
  y = this->mTargetPointWS.y;
  z = this->mTargetPointWS.z;
  y_low = (__m128)LODWORD(d.v1.y);
  v11 = (float)(d.v1.x * y) + (float)(d.v0.x * x);
  y_low.m128_f32[0] = d.v1.y * y;
  v12 = d.v1.z * y;
  v13 = 0.0;
  v14 = (float)(v11 + (float)(d.v2.x * z)) + d.v3.x;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] + (float)(d.v0.y * x)) + (float)(d.v2.y * z)) + d.v3.y;
  v16 = (float)(v12 + (float)(d.v0.z * x)) + (float)(d.v2.z * z);
  v18 = y_low;
  v17 = v16 + d.v3.z;
  v18.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v14 * v14)) + (float)(v17 * v17);
  if ( v18.m128_f32[0] != 0.0 )
    v13 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
  y_low.m128_f32[0] = y_low.m128_f32[0] * v13;
  v19 = v13 * v14;
  *rotZ = atan2f(y_low.m128_f32[0], v13 * v14);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v19 * v19);
  *(_DWORD *)rotX = COERCE_UNSIGNED_INT(atan2f(v17 * v13, _mm_sqrt_ps(y_low).m128_f32[0])) ^ _xmm[0];
  *rotY = 0.0;
}

// File Line: 787
// RVA: 0x3B1F80
void __fastcall AimConstraintMultiLink::UpdatePose(AimConstraintMultiLink *this, SkeletalPose *pose)
{
  float mWeight; // xmm0_4
  float v5; // xmm8_4
  int mJointCount; // r14d
  float v7; // xmm9_4
  float mXJointLimitMinMag; // xmm3_4
  float mZJointLimitMinMag; // xmm5_4
  float mYJointLimitMinMag; // xmm7_4
  float v11; // xmm5_4
  float v12; // xmm7_4
  float mTrackingGain; // xmm4_4
  float mXJointLimitMaxMag; // xmm6_4
  float mZJointLimitMaxMag; // xmm3_4
  float mYJointLimitMaxMag; // xmm4_4
  float v17; // xmm6_4
  float v18; // xmm3_4
  float v19; // xmm6_4
  int i; // esi
  int mSecondJointID; // edi
  int j; // esi
  int mThirdJointID; // edi
  float rotY[4]; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector4 v25; // [rsp+40h] [rbp-98h] BYREF
  _BYTE v26[24]; // [rsp+50h] [rbp-88h] BYREF
  float matrixMS_8; // [rsp+68h] [rbp-70h]
  unsigned int matrixMS_12; // [rsp+6Ch] [rbp-6Ch]
  unsigned int matrixMS_16; // [rsp+70h] [rbp-68h]
  float matrixMS_20; // [rsp+74h] [rbp-64h]
  UFG::qMatrix44 matrixMS_24; // [rsp+78h] [rbp-60h] BYREF
  __int64 v32; // [rsp+B8h] [rbp-20h]
  UFG::qMatrix44 dest; // [rsp+C8h] [rbp-10h] BYREF
  UFG::qMatrix44 v34; // [rsp+108h] [rbp+30h] BYREF
  UFG::qMatrix44 v35; // [rsp+148h] [rbp+70h] BYREF
  float rotX; // [rsp+268h] [rbp+190h] BYREF
  float rotZ; // [rsp+270h] [rbp+198h] BYREF

  v32 = -2i64;
  if ( !sDisableAimConstraintMultiLink && this->mUpdated != 1 )
  {
    mWeight = this->mWeight;
    if ( mWeight > 0.0 || sForceActive )
    {
      v5 = EaseInOut(mWeight);
      this->mUpdated = 1;
      mJointCount = this->mJointCount;
      v7 = (float)mJointCount;
      if ( mJointCount > 0 )
      {
        rotZ = 0.0;
        rotX = 0.0;
        rotY[0] = 0.0;
        AimConstraintMultiLink::getTargetRotations(this, pose, &rotX, rotY, &rotZ);
        mXJointLimitMinMag = rotX;
        if ( rotX <= this->mXJointLimitMinMag )
          mXJointLimitMinMag = this->mXJointLimitMinMag;
        if ( mXJointLimitMinMag >= this->mXJointLimitMaxMag )
          mXJointLimitMinMag = this->mXJointLimitMaxMag;
        mZJointLimitMinMag = rotZ;
        if ( rotZ <= this->mZJointLimitMinMag )
          mZJointLimitMinMag = this->mZJointLimitMinMag;
        if ( mZJointLimitMinMag >= this->mZJointLimitMaxMag )
          mZJointLimitMinMag = this->mZJointLimitMaxMag;
        mYJointLimitMinMag = rotY[0];
        if ( rotY[0] <= this->mYJointLimitMinMag )
          mYJointLimitMinMag = this->mYJointLimitMinMag;
        if ( mYJointLimitMinMag >= this->mYJointLimitMaxMag )
          mYJointLimitMinMag = this->mYJointLimitMaxMag;
        v11 = mZJointLimitMinMag - this->mRotationZ;
        v12 = mYJointLimitMinMag - this->mRotationY;
        mTrackingGain = this->mTrackingGain;
        mXJointLimitMaxMag = (float)(mTrackingGain * (float)(mXJointLimitMinMag - this->mRotationX)) + this->mRotationX;
        this->mRotationX = mXJointLimitMaxMag;
        mZJointLimitMaxMag = (float)(mTrackingGain * v11) + this->mRotationZ;
        this->mRotationZ = mZJointLimitMaxMag;
        mYJointLimitMaxMag = (float)(mTrackingGain * v12) + this->mRotationY;
        this->mRotationY = mYJointLimitMaxMag;
        if ( mXJointLimitMaxMag <= this->mXJointLimitMinMag )
          mXJointLimitMaxMag = this->mXJointLimitMinMag;
        if ( mXJointLimitMaxMag >= this->mXJointLimitMaxMag )
          mXJointLimitMaxMag = this->mXJointLimitMaxMag;
        this->mRotationX = mXJointLimitMaxMag;
        if ( mZJointLimitMaxMag <= this->mZJointLimitMinMag )
          mZJointLimitMaxMag = this->mZJointLimitMinMag;
        if ( mZJointLimitMaxMag >= this->mZJointLimitMaxMag )
          mZJointLimitMaxMag = this->mZJointLimitMaxMag;
        this->mRotationZ = mZJointLimitMaxMag;
        if ( mYJointLimitMaxMag <= this->mYJointLimitMinMag )
          mYJointLimitMaxMag = this->mYJointLimitMinMag;
        if ( mYJointLimitMaxMag >= this->mYJointLimitMaxMag )
          mYJointLimitMaxMag = this->mYJointLimitMaxMag;
        v17 = mXJointLimitMaxMag * v5;
        this->mRotationX = v17;
        v18 = mZJointLimitMaxMag * v5;
        this->mRotationZ = v18;
        this->mRotationY = mYJointLimitMaxMag * v5;
        rotX = v18 * (float)(1.0 / v7);
        v19 = v17 * (float)(1.0 / v7);
        if ( (_S8_8 & 1) == 0 )
        {
          _S8_8 |= 1u;
          beforeColor = UFG::qColour::Lime;
        }
        if ( gDrawSkeletonBoneNormalityInfo )
        {
          v25 = (UFG::qVector4)beforeColor;
          SkeletalPose::DebugDraw(pose, (UFG::qColour *)&v25, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
        }
        UFG::qRotationMatrixY(&dest, v19);
        if ( sEnableBend )
        {
          for ( i = 0; i < mJointCount; ++i )
          {
            if ( i )
            {
              switch ( i )
              {
                case 1:
                  mSecondJointID = this->mSecondJointID;
                  break;
                case 2:
                  mSecondJointID = this->mThirdJointID;
                  break;
                case 3:
                  mSecondJointID = this->mEndJointID;
                  break;
                default:
                  mSecondJointID = 0;
                  break;
              }
            }
            else
            {
              mSecondJointID = this->mFirstJointID;
            }
            SkeletalPose::GetPositionMS_ReNormalize(pose, mSecondJointID, &matrixMS_24);
            v25 = matrixMS_24.v3;
            *(_QWORD *)v26 = _mm_mul_ps(
                               _mm_shuffle_ps((__m128)matrixMS_24.v0, (__m128)matrixMS_24.v0, 0),
                               (__m128)dest.v0).m128_u64[0];
            *(_QWORD *)&matrixMS_24.v0.x = *(unsigned __int128 *)&_mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_add_ps(
                                                                        _mm_mul_ps(
                                                                          _mm_shuffle_ps(
                                                                            (__m128)matrixMS_24.v1,
                                                                            (__m128)matrixMS_24.v1,
                                                                            85),
                                                                          (__m128)dest.v1),
                                                                        _mm_add_ps(
                                                                          _mm_mul_ps(
                                                                            _mm_shuffle_ps(
                                                                              (__m128)matrixMS_24.v1,
                                                                              (__m128)matrixMS_24.v1,
                                                                              0),
                                                                            (__m128)dest.v0),
                                                                          (__m128)0i64)),
                                                                      _mm_mul_ps(
                                                                        _mm_shuffle_ps(
                                                                          (__m128)matrixMS_24.v1,
                                                                          (__m128)matrixMS_24.v1,
                                                                          170),
                                                                        (__m128)dest.v2)),
                                                                    _mm_mul_ps(
                                                                      _mm_shuffle_ps(
                                                                        (__m128)matrixMS_24.v1,
                                                                        (__m128)matrixMS_24.v1,
                                                                        255),
                                                                      (__m128)dest.v3)) >> 64;
            *(__m128 *)&v26[8] = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           _mm_shuffle_ps((__m128)matrixMS_24.v2, (__m128)matrixMS_24.v2, 0),
                                           (__m128)dest.v0),
                                         (__m128)0i64),
                                       _mm_mul_ps(
                                         _mm_shuffle_ps((__m128)matrixMS_24.v2, (__m128)matrixMS_24.v2, 85),
                                         (__m128)dest.v1)),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps((__m128)matrixMS_24.v2, (__m128)matrixMS_24.v2, 170),
                                       (__m128)dest.v2)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps((__m128)matrixMS_24.v2, (__m128)matrixMS_24.v2, 255),
                                     (__m128)dest.v3));
            matrixMS_8 = matrixMS_24.v3.x;
            matrixMS_12 = _mm_shuffle_ps((__m128)matrixMS_24.v3, (__m128)matrixMS_24.v3, 85).m128_u32[0];
            matrixMS_16 = _mm_shuffle_ps((__m128)matrixMS_24.v3, (__m128)matrixMS_24.v3, 170).m128_u32[0];
            matrixMS_20 = matrixMS_24.v3.w;
            SkeletalPose::SetPositionMS_ReNormalize(pose, mSecondJointID, (UFG::qMatrix44 *)&v26[16]);
            SkeletalPose::GetPositionMS(pose, mSecondJointID, &v35);
          }
        }
        UFG::qRotationMatrixZ(&v34, rotX);
        if ( sEnableTwist )
        {
          for ( j = 0; j < mJointCount; ++j )
          {
            if ( j )
            {
              switch ( j )
              {
                case 1:
                  mThirdJointID = this->mSecondJointID;
                  break;
                case 2:
                  mThirdJointID = this->mThirdJointID;
                  break;
                case 3:
                  mThirdJointID = this->mEndJointID;
                  break;
                default:
                  mThirdJointID = 0;
                  break;
              }
            }
            else
            {
              mThirdJointID = this->mFirstJointID;
            }
            SkeletalPose::GetPositionMS_ReNormalize(pose, mThirdJointID, &matrixMS_24);
            v25 = matrixMS_24.v3;
            *(_QWORD *)v26 = _mm_mul_ps(
                               (__m128)v34.v0,
                               _mm_shuffle_ps((__m128)matrixMS_24.v3, (__m128)matrixMS_24.v3, 0)).m128_u64[0];
            *(_QWORD *)&matrixMS_24.v0.x = *(unsigned __int128 *)&_mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_add_ps(
                                                                        _mm_mul_ps(
                                                                          (__m128)v34.v1,
                                                                          _mm_shuffle_ps(
                                                                            (__m128)matrixMS_24.v1,
                                                                            (__m128)matrixMS_24.v1,
                                                                            85)),
                                                                        _mm_add_ps(
                                                                          _mm_mul_ps(
                                                                            (__m128)v34.v0,
                                                                            _mm_shuffle_ps(
                                                                              (__m128)matrixMS_24.v1,
                                                                              (__m128)matrixMS_24.v1,
                                                                              0)),
                                                                          (__m128)0i64)),
                                                                      _mm_mul_ps(
                                                                        (__m128)v34.v2,
                                                                        _mm_shuffle_ps(
                                                                          (__m128)matrixMS_24.v1,
                                                                          (__m128)matrixMS_24.v1,
                                                                          170))),
                                                                    _mm_mul_ps(
                                                                      (__m128)v34.v3,
                                                                      _mm_shuffle_ps(
                                                                        (__m128)matrixMS_24.v1,
                                                                        (__m128)matrixMS_24.v1,
                                                                        255))) >> 64;
            *(__m128 *)&v26[8] = _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       (__m128)v34.v2,
                                       _mm_shuffle_ps((__m128)matrixMS_24.v2, (__m128)matrixMS_24.v2, 170)),
                                     _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(
                                           (__m128)v34.v0,
                                           _mm_shuffle_ps((__m128)matrixMS_24.v2, (__m128)matrixMS_24.v2, 0)),
                                         (__m128)0i64),
                                       _mm_mul_ps(
                                         (__m128)v34.v1,
                                         _mm_shuffle_ps((__m128)matrixMS_24.v2, (__m128)matrixMS_24.v2, 85)))),
                                   _mm_mul_ps(
                                     (__m128)v34.v3,
                                     _mm_shuffle_ps((__m128)matrixMS_24.v2, (__m128)matrixMS_24.v2, 255)));
            matrixMS_8 = matrixMS_24.v3.x;
            matrixMS_12 = _mm_shuffle_ps((__m128)matrixMS_24.v3, (__m128)matrixMS_24.v3, 85).m128_u32[0];
            matrixMS_16 = _mm_shuffle_ps((__m128)matrixMS_24.v3, (__m128)matrixMS_24.v3, 170).m128_u32[0];
            matrixMS_20 = matrixMS_24.v3.w;
            SkeletalPose::SetPositionMS_ReNormalize(pose, mThirdJointID, (UFG::qMatrix44 *)&v26[16]);
            SkeletalPose::GetPositionMS(pose, mThirdJointID, &v35);
          }
        }
        if ( (_S8_8 & 2) == 0 )
        {
          _S8_8 |= 2u;
          afterColor = UFG::qColour::Pink;
        }
        if ( gDrawSkeletonBoneNormalityInfo )
        {
          *(UFG::qColour *)v26 = afterColor;
          SkeletalPose::DebugDraw(pose, (UFG::qColour *)v26, COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0));
        }
      }
    }
  }
}

// File Line: 983
// RVA: 0x3A1610
bool __fastcall AimConstraintMultiLink::AddTo(AimConstraintMultiLink *this, Creature *creature)
{
  int v2; // esi
  int BoneID; // eax
  int v6; // eax
  int v7; // eax
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax
  bool result; // al

  this->mJointCount = 0;
  v2 = -1;
  if ( creature->mPose.mRigHandle.mData )
    BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFirstJoint.mUID);
  else
    BoneID = -1;
  this->mFirstJointID = BoneID;
  if ( BoneID >= 0 )
    ++this->mJointCount;
  if ( creature->mPose.mRigHandle.mData )
    v6 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mSecondJoint.mUID);
  else
    v6 = -1;
  this->mSecondJointID = v6;
  if ( v6 >= 0 )
    ++this->mJointCount;
  if ( creature->mPose.mRigHandle.mData )
    v7 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mThirdJoint.mUID);
  else
    v7 = -1;
  this->mThirdJointID = v7;
  if ( v7 >= 0 )
    ++this->mJointCount;
  if ( creature->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mEndJoint.mUID);
  this->mEndJointID = v2;
  if ( v2 >= 0 )
    ++this->mJointCount;
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  result = 1;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  return result;
}

// File Line: 1007
// RVA: 0x14B9A50
__int64 dynamic_initializer_for__TwoLinkIKsolver::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TwoLinkIKsolver", 0xFFFFFFFF);
  TwoLinkIKsolver::sClassNameUID = result;
  return result;
}

// File Line: 1038
// RVA: 0x39E890
void __fastcall TwoLinkIKsolver::TwoLinkIKsolver(TwoLinkIKsolver *this)
{
  UFG::qVector4 v1; // xmm3

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&TwoLinkIKsolver::`vftable;
  this->mFirstJoint = UFG::gNullQSymbolUC;
  this->mSecondJoint = UFG::gNullQSymbolUC;
  this->mEndJoint = UFG::gNullQSymbolUC;
  this->mFixSiblingTwist = 0;
  this->mLinkInfo.m_firstJointIdx = -1;
  this->mLinkInfo.m_secondJointIdx = -1;
  this->mLinkInfo.m_endBoneIdx = -1;
  this->mLinkInfo.m_firstJointTwistIdx = -1;
  this->mLinkInfo.m_secondJointTwistIdx = -1;
  this->mLinkInfo.m_hingeAxisLS = (hkVector4f)aabbOut.m_quad;
  this->mLinkInfo.m_cosineMaxHingeAngle = -1.0;
  this->mLinkInfo.m_cosineMinHingeAngle = 1.0;
  this->mLinkInfo.m_firstJointIkGain = 1.0;
  this->mLinkInfo.m_secondJointIkGain = 1.0;
  this->mLinkInfo.m_endJointIkGain = 1.0;
  this->mLinkInfo.m_endTargetMS = (hkVector4f)aabbOut.m_quad;
  this->mLinkInfo.m_endTargetRotationMS = (hkQuaternionf)qi.m_vec.m_quad;
  this->mLinkInfo.m_endBoneOffsetLS = (hkVector4f)aabbOut.m_quad;
  this->mLinkInfo.m_endBoneRotationOffsetLS = (hkQuaternionf)qi.m_vec.m_quad;
  *(_WORD *)&this->mLinkInfo.m_enforceEndPosition.m_bool = 1;
  this->mFixSiblingTwist = 0;
  v1 = 0i64;
  v1.x = (float)1;
  this->mTargetMatrixWS.v0 = v1;
  this->mTargetMatrixWS.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v1, (__m128)v1, 81);
  this->mTargetMatrixWS.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v1, (__m128)v1, 69);
  this->mTargetMatrixWS.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v1, (__m128)v1, 21);
  this->mHkTargetMatrixWS.m_translation = 0i64;
  this->mHkTargetMatrixWS.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
  this->mHkTargetMatrixWS.m_scale = (hkVector4f)query.m_quad;
}

// File Line: 1088
// RVA: 0x3AF220
void __fastcall TwoLinkIKsolver::SetEffectorTarget(TwoLinkIKsolver *this, SkeletalPose *pose, UFG::qMatrix44 *matrixWS)
{
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1

  v3 = matrixWS->v1;
  v4 = matrixWS->v2;
  v5 = matrixWS->v3;
  this->mTargetMatrixWS.v0 = matrixWS->v0;
  this->mTargetMatrixWS.v1 = v3;
  this->mTargetMatrixWS.v2 = v4;
  this->mTargetMatrixWS.v3 = v5;
  TwoLinkIKsolver::UpdateWorldTarget(this, pose);
}

// File Line: 1161
// RVA: 0x3B5040
void __fastcall TwoLinkIKsolver::UpdateWorldTarget(TwoLinkIKsolver *this, SkeletalPose *pose)
{
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  float x; // xmm0_4
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
  float p[16]; // [rsp+20h] [rbp-E0h] BYREF
  hkTransformf transform; // [rsp+60h] [rbp-A0h] BYREF
  hkQsTransformf v21; // [rsp+A0h] [rbp-60h] BYREF
  UFG::qMatrix44 matrixRoot; // [rsp+D0h] [rbp-30h] BYREF
  UFG::qMatrix44 d; // [rsp+110h] [rbp+10h] BYREF
  UFG::qMatrix44 result; // [rsp+150h] [rbp+50h] BYREF

  y = this->mTargetMatrixWS.v0.y;
  p[0] = this->mTargetMatrixWS.v0.x;
  z = this->mTargetMatrixWS.v0.z;
  p[1] = y;
  w = this->mTargetMatrixWS.v0.w;
  p[2] = z;
  x = this->mTargetMatrixWS.v1.x;
  p[3] = w;
  v8 = this->mTargetMatrixWS.v1.y;
  p[4] = x;
  v9 = this->mTargetMatrixWS.v1.z;
  p[5] = v8;
  v10 = this->mTargetMatrixWS.v1.w;
  p[6] = v9;
  v11 = this->mTargetMatrixWS.v2.x;
  p[7] = v10;
  v12 = this->mTargetMatrixWS.v2.y;
  p[8] = v11;
  v13 = this->mTargetMatrixWS.v2.z;
  p[9] = v12;
  v14 = this->mTargetMatrixWS.v2.w;
  p[10] = v13;
  v15 = this->mTargetMatrixWS.v3.x;
  p[11] = v14;
  v16 = this->mTargetMatrixWS.v3.y;
  p[12] = v15;
  v17 = this->mTargetMatrixWS.v3.z;
  p[13] = v16;
  v18 = this->mTargetMatrixWS.v3.w;
  p[14] = v17;
  p[15] = v18;
  hkTransformf::set4x4ColumnMajor(&transform, p);
  hkQsTransformf::setFromTransformNoScale(&this->mHkTargetMatrixWS, &transform);
  SkeletalPose::GetRootMatrix(pose, &matrixRoot);
  UFG::qInverseAffine(&d, &matrixRoot);
  UFG::qMatrix44::operator*(&this->mTargetMatrixWS, &result, &d);
  hkTransformf::set4x4ColumnMajor(&transform, &result.v0.x);
  hkQsTransformf::setFromTransformNoScale(&v21, &transform);
  this->mLinkInfo.m_endTargetMS = v21.m_translation;
}

// File Line: 1275
// RVA: 0x3B7410
void __fastcall getRelativeDifferenceInPose(
        UFG::qMatrix44 *difference,
        SkeletalPose *pose,
        int baseRefFrameID,
        int inputFrameID)
{
  UFG::qVector4 v7; // xmm9
  UFG::qVector4 v8; // xmm11
  UFG::qVector4 v9; // xmm12
  UFG::qVector4 v10; // xmm13
  UFG::qVector4 v11; // xmm5
  __m128 v12; // xmm2
  UFG::qVector4 v13; // xmm4
  UFG::qVector4 v14; // xmm0
  UFG::qMatrix44 d; // [rsp+20h] [rbp-148h] BYREF
  UFG::qMatrix44 v16; // [rsp+60h] [rbp-108h] BYREF
  UFG::qMatrix44 matrixMS; // [rsp+A0h] [rbp-C8h] BYREF

  SkeletalPose::GetPositionMS(pose, baseRefFrameID, &matrixMS);
  SkeletalPose::GetPositionMS(pose, inputFrameID, &v16);
  UFG::qInverseAffine(&d, &matrixMS);
  v7 = d.v1;
  v8 = d.v2;
  v9 = d.v3;
  v10 = v16.v3;
  v11 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v1, (__m128)v16.v1, 0), (__m128)d.v0),
                               (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v1, (__m128)v16.v1, 85), (__m128)d.v1)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v1, (__m128)v16.v1, 170), (__m128)d.v2)),
                         _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v1, (__m128)v16.v1, 255), (__m128)d.v3));
  v12 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v16.v3, (__m128)v16.v3, 0), (__m128)d.v0), (__m128)0i64);
  v13 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v2, (__m128)v16.v2, 0), (__m128)d.v0),
                               (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v2, (__m128)v16.v2, 85), (__m128)d.v1)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v2, (__m128)v16.v2, 170), (__m128)d.v2)),
                         _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v2, (__m128)v16.v2, 255), (__m128)d.v3));
  v14 = v16.v3;
  difference->v0 = (UFG::qVector4)_mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v0, (__m128)v16.v0, 0), (__m128)d.v0),
                                          (__m128)0i64),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v0, (__m128)v16.v0, 85), (__m128)d.v1)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v0, (__m128)v16.v0, 170), (__m128)d.v2)),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v0, (__m128)v16.v0, 255), (__m128)d.v3));
  difference->v1 = v11;
  difference->v2 = v13;
  difference->v3 = (UFG::qVector4)_mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        v12,
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 85), (__m128)v7)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v10, 170), (__m128)v8)),
                                    _mm_mul_ps(_mm_shuffle_ps((__m128)v10, (__m128)v10, 255), (__m128)v9));
}

// File Line: 1297
// RVA: 0x3B3BE0
void __fastcall TwoLinkIKsolver::UpdatePose(TwoLinkIKsolver *this, SkeletalPose *pose)
{
  __int16 v4; // bx
  hkaSkeleton *m_skeleton; // rdx
  __int16 v6; // di
  __int64 m_firstJointIdx; // r8
  __int16 *m_data; // r9
  int m_size; // r10d
  __int64 m_secondJointIdx; // r11
  int v11; // ecx
  __int16 v12; // dx
  int m_endBoneIdx; // edx
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  float x; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  UFG::qMatrix44 difference; // [rsp+20h] [rbp-C8h] BYREF
  char translationWS[40]; // [rsp+60h] [rbp-88h] BYREF
  __m128 v27; // [rsp+88h] [rbp-60h]
  UFG::qMatrix44 v28; // [rsp+98h] [rbp-50h] BYREF
  UFG::qMatrix44 v29; // [rsp+D8h] [rbp-10h] BYREF
  hkBool result; // [rsp+1A8h] [rbp+C0h] BYREF

  if ( this->mActive )
  {
    v4 = -1;
    m_skeleton = pose->mHavokPose->m_skeleton;
    v6 = -1;
    if ( this->mFixSiblingTwist )
    {
      if ( m_skeleton )
      {
        m_firstJointIdx = this->mLinkInfo.m_firstJointIdx;
        m_data = m_skeleton->m_parentIndices.m_data;
        m_size = m_skeleton->m_parentIndices.m_size;
        m_secondJointIdx = this->mLinkInfo.m_secondJointIdx;
        v11 = 0;
        if ( m_size > 0 )
        {
          do
          {
            v12 = m_data[v11];
            if ( (__int16)m_firstJointIdx != v11 && v4 == -1 && v12 == m_data[m_firstJointIdx] )
              v4 = v11;
            if ( (__int16)m_secondJointIdx != v11 && v6 == -1 && v12 == m_data[m_secondJointIdx] )
              v6 = v11;
            if ( v4 != -1 && v6 != -1 )
              break;
            ++v11;
          }
          while ( v11 < m_size );
          if ( v4 != -1 )
            getRelativeDifferenceInPose(&difference, pose, (__int16)m_firstJointIdx, v4);
          if ( v6 != -1 )
            getRelativeDifferenceInPose(&v29, pose, this->mLinkInfo.m_secondJointIdx, v6);
        }
      }
    }
    hkaTwoJointsIkSolver::solve(&result, &this->mLinkInfo, pose->mHavokPose);
    if ( v4 != -1 )
    {
      SkeletalPose::GetPositionMS(pose, this->mLinkInfo.m_firstJointIdx, (UFG::qMatrix44 *)&translationWS[16]);
      v28.v0 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)difference.v0, (__m128)difference.v0, 0),
                                        *(__m128 *)&translationWS[16]),
                                      (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)difference.v0, (__m128)difference.v0, 85),
                                      *(__m128 *)&translationWS[8])),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps((__m128)difference.v0, (__m128)difference.v0, 170),
                                    *(__m128 *)&translationWS[24])),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v0, (__m128)difference.v0, 255), v27));
      v28.v1 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)difference.v1, (__m128)difference.v1, 0),
                                        *(__m128 *)&translationWS[16]),
                                      (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)difference.v1, (__m128)difference.v1, 85),
                                      *(__m128 *)&translationWS[8])),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps((__m128)difference.v1, (__m128)difference.v1, 170),
                                    *(__m128 *)&translationWS[24])),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v1, (__m128)difference.v1, 255), v27));
      v28.v2 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)difference.v2, (__m128)difference.v2, 0),
                                        *(__m128 *)&translationWS[16]),
                                      (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)difference.v2, (__m128)difference.v2, 85),
                                      *(__m128 *)&translationWS[8])),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps((__m128)difference.v2, (__m128)difference.v2, 170),
                                    *(__m128 *)&translationWS[24])),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v2, (__m128)difference.v2, 255), v27));
      v28.v3 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)difference.v3, (__m128)difference.v3, 0),
                                        *(__m128 *)&translationWS[16]),
                                      (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)difference.v3, (__m128)difference.v3, 85),
                                      *(__m128 *)&translationWS[8])),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps((__m128)difference.v3, (__m128)difference.v3, 170),
                                    *(__m128 *)&translationWS[24])),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v3, (__m128)difference.v3, 255), v27));
      SkeletalPose::SetPositionMS(pose, v4, &v28);
    }
    if ( v6 != -1 )
    {
      SkeletalPose::GetPositionMS(pose, this->mLinkInfo.m_secondJointIdx, &v28);
      *(__m128 *)&translationWS[8] = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(
                                               _mm_shuffle_ps((__m128)v29.v1, (__m128)v29.v1, 0),
                                               (__m128)v28.v0),
                                             (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps((__m128)v29.v1, (__m128)v29.v1, 85),
                                             (__m128)v28.v1)),
                                         _mm_mul_ps(_mm_shuffle_ps((__m128)v29.v1, (__m128)v29.v1, 170), (__m128)v28.v2)),
                                       _mm_mul_ps(_mm_shuffle_ps((__m128)v29.v1, (__m128)v29.v1, 255), (__m128)v28.v3));
      *(__m128 *)&translationWS[24] = _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_shuffle_ps((__m128)v29.v2, (__m128)v29.v2, 0),
                                                (__m128)v28.v0),
                                              (__m128)0i64),
                                            _mm_mul_ps(
                                              _mm_shuffle_ps((__m128)v29.v2, (__m128)v29.v2, 85),
                                              (__m128)v28.v1)),
                                          _mm_mul_ps(
                                            _mm_shuffle_ps((__m128)v29.v2, (__m128)v29.v2, 170),
                                            (__m128)v28.v2)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v29.v2, (__m128)v29.v2, 255), (__m128)v28.v3));
      v27 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps((__m128)v29.v3, (__m128)v29.v3, 0), (__m128)v28.v0),
                    (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)v29.v3, (__m128)v29.v3, 85), (__m128)v28.v1)),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v29.v3, (__m128)v29.v3, 170), (__m128)v28.v2)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v29.v3, (__m128)v29.v3, 255), (__m128)v28.v3));
      SkeletalPose::SetPositionMS(pose, v6, (UFG::qMatrix44 *)&translationWS[16]);
    }
    SkeletalPose::GetTranslationWS(pose, this->mLinkInfo.m_endBoneIdx, (UFG::qVector3 *)translationWS);
    m_endBoneIdx = this->mLinkInfo.m_endBoneIdx;
    y = this->mTargetMatrixWS.v0.y;
    difference.v0.x = this->mTargetMatrixWS.v0.x;
    z = this->mTargetMatrixWS.v0.z;
    difference.v0.y = y;
    w = this->mTargetMatrixWS.v0.w;
    difference.v0.z = z;
    x = this->mTargetMatrixWS.v1.x;
    difference.v0.w = w;
    v18 = this->mTargetMatrixWS.v1.y;
    difference.v1.x = x;
    v19 = this->mTargetMatrixWS.v1.z;
    difference.v1.y = v18;
    v20 = this->mTargetMatrixWS.v1.w;
    difference.v1.z = v19;
    v21 = this->mTargetMatrixWS.v2.x;
    difference.v1.w = v20;
    v22 = this->mTargetMatrixWS.v2.y;
    difference.v2.x = v21;
    v23 = this->mTargetMatrixWS.v2.z;
    difference.v2.y = v22;
    v24 = this->mTargetMatrixWS.v2.w;
    difference.v2.z = v23;
    difference.v2.w = v24;
    difference.v3.x = *(float *)translationWS;
    difference.v3.y = *(float *)&translationWS[4];
    difference.v3.z = *(float *)&translationWS[8];
    LODWORD(difference.v3.w) = (_DWORD)FLOAT_1_0;
    SkeletalPose::SetPositionWS(pose, m_endBoneIdx, &difference);
  }
}

// File Line: 1464
// RVA: 0x3A1910
char __fastcall RootUprightDriver::AddTo(RootUprightDriver *this, Creature *creature)
{
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v3; // rcx
  UFG::qList<PoseDriver,PoseDriver,1,0> *p_mPoseDrivers; // rdx

  mPrev = creature->mPoseDrivers.mNode.mPrev;
  v3 = &this->UFG::qNode<PoseDriver,PoseDriver>;
  p_mPoseDrivers = &creature->mPoseDrivers;
  mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = &p_mPoseDrivers->mNode;
  p_mPoseDrivers->mNode.mPrev = v3;
  return 1;
}

// File Line: 1470
// RVA: 0x3A15A0
char __fastcall AimConstraint::AddTo(AimConstraint *this, Creature *creature)
{
  int BoneID; // eax
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax

  if ( !creature->mPose.mRigHandle.mData )
    return 0;
  BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mEffectorJoint.mUID);
  if ( BoneID == -1 )
    return 0;
  this->mJointID = BoneID;
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  return 1;
}

// File Line: 1483
// RVA: 0x3A1500
char __fastcall AimConstraint2::AddTo(AimConstraint2 *this, Creature *creature)
{
  int v2; // edi
  int BoneID; // ebp
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax

  v2 = -1;
  if ( creature->mPose.mRigHandle.mData )
    BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mEffectorJoint.mUID);
  else
    BoneID = -1;
  if ( creature->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mTargetJoint.mUID);
  if ( BoneID == -1 || v2 == -1 )
    return 0;
  this->mJointID = BoneID;
  this->mTargetJointID = v2;
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  return 1;
}

// File Line: 1499
// RVA: 0x3A1A90
char __fastcall TwoLinkIKsolver::AddTo(TwoLinkIKsolver *this, Creature *creature)
{
  int v2; // esi
  int BoneID; // r14d
  int v6; // ebp
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax

  v2 = -1;
  if ( creature->mPose.mRigHandle.mData )
    BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFirstJoint.mUID);
  else
    BoneID = -1;
  if ( creature->mPose.mRigHandle.mData )
    v6 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mSecondJoint.mUID);
  else
    v6 = -1;
  if ( creature->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mEndJoint.mUID);
  if ( BoneID == -1 || v6 == -1 || v2 == -1 )
    return 0;
  this->mLinkInfo.m_firstJointIdx = BoneID;
  this->mLinkInfo.m_secondJointIdx = v6;
  this->mLinkInfo.m_endBoneIdx = v2;
  this->mLinkInfo.m_hingeAxisLS.m_quad.m128_i32[2] = 1065353216;
  this->mCreature = creature;
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  return 1;
}

// File Line: 1520
// RVA: 0x3A1880
char __fastcall OrientationConstraint::AddTo(OrientationConstraint *this, Creature *creature)
{
  __int64 v4; // rbx
  char *v5; // r14
  __int64 v6; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax

  ((void (__fastcall *)(JointReferences *))this->mDriveJoint.vfptr[1].FindWithOldPath)(&this->mDriveJoint);
  v4 = 0i64;
  v5 = (char *)&this->mInputJoints.mData + this->mInputJoints.mData.mOffset;
  if ( (this->mInputJoints.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v6 = (__int64)&v5[8 * v4 + *(_QWORD *)&v5[8 * v4]];
      (*(void (__fastcall **)(__int64, Creature *))(*(_QWORD *)v6 + 80i64))(v6, creature);
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < (this->mInputJoints.mCount & 0x7FFFFFFFu) );
  }
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  return 1;
}

// File Line: 1535
// RVA: 0x3A1840
char __fastcall JointReferences::AddTo(JointReferences *this, Creature *creature)
{
  if ( creature->mPose.mRigHandle.mData )
    this->mJointID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mJointName.mUID);
  else
    this->mJointID = -1;
  return 1;
}

// File Line: 1542
// RVA: 0x3A19E0
char __fastcall TwistXRotLinearLink::AddTo(TwistXRotLinearLink *this, Creature *creature)
{
  int v2; // esi
  int BoneID; // eax
  int v6; // eax
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax

  v2 = -1;
  if ( creature->mPose.mRigHandle.mData )
    BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mBaseJoint.mUID);
  else
    BoneID = -1;
  this->mBaseJointID = BoneID;
  if ( creature->mPose.mRigHandle.mData )
    v6 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mEndJoint.mUID);
  else
    v6 = -1;
  this->mEndJointID = v6;
  if ( creature->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mDriveJoint.mUID);
  this->mDriveJointID = v2;
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  return 1;
}

// File Line: 1551
// RVA: 0x3A1790
bool __fastcall FollowLink::AddTo(FollowLink *this, Creature *creature)
{
  int v2; // esi
  int BoneID; // eax
  int mFollowJointID; // edx
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax
  bool result; // al

  v2 = -1;
  if ( creature->mPose.mRigHandle.mData )
    BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFollowJoint.mUID);
  else
    BoneID = -1;
  this->mFollowJointID = BoneID;
  if ( creature->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mDriveJoint.mUID);
  mFollowJointID = this->mFollowJointID;
  this->mDriveJointID = v2;
  if ( mFollowJointID != -1 && v2 != -1 )
    this->mDriveJointIsParentOfFollow = Skeleton::IsParent(creature->mPose.mRigHandle.mUFGSkeleton, mFollowJointID, v2);
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  result = 1;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  return result;
}

// File Line: 1565
// RVA: 0x3A1700
char __fastcall Follow2Link::AddTo(Follow3Link *this, Creature *creature)
{
  int v2; // esi
  int BoneID; // eax
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax

  v2 = -1;
  if ( creature->mPose.mRigHandle.mData )
    BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFollowJoint.mUID);
  else
    BoneID = -1;
  this->mFollowJointID = BoneID;
  if ( creature->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mDriveJoint.mUID);
  this->mDriveJointID = v2;
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  return 1;
}

// File Line: 1587
// RVA: 0x14B9810
__int64 dynamic_initializer_for__JointReferences::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("JointReferences", 0xFFFFFFFF);
  JointReferences::sClassNameUID = result;
  return result;
}

// File Line: 1594
// RVA: 0x39E150
void __fastcall JointReferences::JointReferences(JointReferences *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&JointReferences::`vftable;
  this->mJointName = UFG::gNullQSymbolUC;
  this->mJointID = 0;
}

// File Line: 1611
// RVA: 0x14BF480
const char *dynamic_initializer_for__sJointReferencesFactoryList__()
{
  const char *result; // rax

  result = JointReferences::sClassName;
  sJointReferencesFactoryList[0].mClassName = JointReferences::sClassName;
  return result;
}

// File Line: 1616
// RVA: 0x14BCFC0
__int64 dynamic_initializer_for__gJointReferencesFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gJointReferencesFactory,
    sJointReferencesFactoryList,
    sJointReferencesFactoryListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gJointReferencesFactory__);
}

// File Line: 1618
// RVA: 0x14B98B0
__int64 dynamic_initializer_for__OrientationConstraint::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("OrientationConstraint", 0xFFFFFFFF);
  OrientationConstraint::sClassNameUID = result;
  return result;
}

// File Line: 1649
// RVA: 0x39F9F0
void __fastcall OrientationConstraint::~OrientationConstraint(OrientationConstraint *this)
{
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *mNext; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&OrientationConstraint::`vftable;
  BinPtrArray<JointReferences,1,0>::Clear((BinPtrArray<ITrack,1,0> *)&this->mInputJoints);
  this->mDriveJoint.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 1655
// RVA: 0x3AE5C0
void __fastcall OrientationConstraint::Serialize(OrientationConstraint *this, IActionTreeSerializer *serializer)
{
  unsigned int v4; // ebx
  char *v5; // r14
  char *v6; // rcx
  char *v7; // rdi
  const char *v8; // rax

  v4 = 0;
  v5 = (char *)&this->mInputJoints.mData + this->mInputJoints.mData.mOffset;
  if ( (this->mInputJoints.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v6 = &v5[8 * v4];
      v7 = &v6[*(_QWORD *)v6];
      if ( v7 )
      {
        v8 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 32i64))(&v6[*(_QWORD *)v6]);
        serializer->vfptr->_PushObjectToSerialize(
          serializer,
          v7,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          v8,
          PRIORITY_MEDIUM,
          0,
          0i64,
          -1u,
          0i64);
      }
      ++v4;
    }
    while ( v4 < (this->mInputJoints.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 1674
// RVA: 0x3A6370
Expression::IMemberMap *__fastcall OrientationConstraint::CreateClone(OrientationConstraint *this)
{
  char *v2; // rax
  char *v3; // rbx
  _QWORD *v4; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "OrientationConstraint::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v2 + 1) = 0i64;
    v4 = v2 + 16;
    *v4 = v4;
    v4[1] = v4;
    *(_QWORD *)v3 = &PoseDriver::`vftable;
    *((_WORD *)v3 + 20) = 0;
    v3[42] = 0;
    *((_DWORD *)v3 + 11) = -1;
    *((UFG::qStaticSymbolUC *)v3 + 11) = symEffectorNone;
    *(_QWORD *)v3 = &OrientationConstraint::`vftable;
    *((_QWORD *)v3 + 7) = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v3 + 8) = 0i64;
    *((_QWORD *)v3 + 7) = &JointReferences::`vftable;
    *((UFG::qSymbolUC *)v3 + 18) = UFG::gNullQSymbolUC;
    *((_DWORD *)v3 + 19) = 0;
    *((_DWORD *)v3 + 20) = 0;
    *((_QWORD *)v3 + 11) = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  *((_QWORD *)v3 + 1) = this->PoseDriver::Expression::IMemberMap::mResourceOwner;
  *((_QWORD *)v3 + 4) = this->PoseDriver::mResourceOwner;
  v3[40] = this->mActive;
  v3[41] = this->mDisabled;
  v3[42] = this->mBreakpoint;
  *((_DWORD *)v3 + 11) = this->mName.mUID;
  *((_QWORD *)v3 + 6) = this->mCreature;
  *((_QWORD *)v3 + 8) = this->mDriveJoint.mResourceOwner;
  *((_DWORD *)v3 + 18) = this->mDriveJoint.mJointName.mUID;
  *((_DWORD *)v3 + 19) = this->mDriveJoint.mJointID;
  OrientationConstraint::CopyFrom((OrientationConstraint *)v3, this);
  return (Expression::IMemberMap *)v3;
}

// File Line: 1693
// RVA: 0x3A5410
void __fastcall OrientationConstraint::CopyFrom(
        OrientationConstraint *this,
        OrientationConstraint *other_OrientationConstraint)
{
  __int64 v2; // rbp
  char *v4; // r12
  BinPtrArray<ITrack,1,0> *p_mInputJoints; // rsi
  __int64 v6; // rcx
  __int64 v7; // rax
  __int64 mCount; // r14
  __int64 v9; // rdi
  unsigned int v10; // ebx
  unsigned int v11; // edx
  __int64 mOffset; // rax
  char *v13; // rcx
  __int64 *v14; // rdx

  v2 = 0i64;
  v4 = (char *)&other_OrientationConstraint->mInputJoints.mData
     + other_OrientationConstraint->mInputJoints.mData.mOffset;
  if ( (other_OrientationConstraint->mInputJoints.mCount & 0x7FFFFFFF) != 0 )
  {
    p_mInputJoints = (BinPtrArray<ITrack,1,0> *)&this->mInputJoints;
    do
    {
      v6 = (__int64)&v4[8 * v2 + *(_QWORD *)&v4[8 * v2]];
      v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
      mCount = (unsigned int)p_mInputJoints->mCount;
      LODWORD(mCount) = mCount & 0x7FFFFFFF;
      v9 = v7;
      v10 = mCount + 1;
      if ( (int)mCount + 1 > (unsigned int)mCount )
      {
        v11 = 1;
        if ( (_DWORD)mCount )
          v11 = 2 * mCount;
        for ( ; v11 < v10; v11 *= 2 )
          ;
        if ( v11 - v10 > 0x10000 )
          v11 = mCount + 65537;
        BinPtrArray<Condition,1,0>::Reallocate(p_mInputJoints, v11, "BinPtrArray.Add");
      }
      p_mInputJoints->mCount &= 0x80000000;
      p_mInputJoints->mCount |= v10 & 0x7FFFFFFF;
      mOffset = p_mInputJoints->mData.mOffset;
      if ( mOffset )
        v13 = (char *)&p_mInputJoints->mData + mOffset;
      else
        v13 = 0i64;
      v14 = (__int64 *)&v13[8 * mCount];
      if ( v9 )
        v9 -= (__int64)v14;
      *v14 = v9;
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (other_OrientationConstraint->mInputJoints.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 1712
// RVA: 0x3B3490
void __fastcall OrientationConstraint::UpdatePose(OrientationConstraint *this, SkeletalPose *pose)
{
  bool v4; // sf
  char mCount; // al
  __int64 mOffset; // rcx
  char *v7; // rax
  _QWORD *v8; // rcx
  __int64 v9; // rcx
  char *v10; // rax
  _QWORD *v11; // rdx
  char *v12; // r8
  char *v13; // rdx
  __int64 v14; // rcx
  int v15; // ebx
  hkQsTransformf *TranslationMS; // rax
  int mJointID; // edx
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qMatrix44 matrixMS; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qMatrix44 sourceB; // [rsp+60h] [rbp-88h] BYREF
  UFG::qMatrix44 sourceA; // [rsp+A0h] [rbp-48h] BYREF

  if ( !gDisablePoseDrivers )
  {
    v4 = this->mDriveJoint.mJointID < 0;
    this->mActive = 1;
    if ( !v4 )
    {
      mCount = this->mInputJoints.mCount;
      if ( mCount )
      {
        if ( mCount == 1 )
        {
          mOffset = this->mInputJoints.mData.mOffset;
          v7 = 0i64;
          if ( mOffset )
            v8 = (__int64 *)((char *)&this->mInputJoints.mData.mOffset + mOffset);
          else
            v8 = 0i64;
          if ( *v8 )
            v7 = (char *)v8 + *v8;
          SkeletalPose::GetPositionMS(pose, (unsigned __int8)v7[20], &matrixMS);
        }
        else if ( mCount == 2 )
        {
          v9 = this->mInputJoints.mData.mOffset;
          v10 = 0i64;
          if ( v9 )
            v11 = (__int64 *)((char *)&this->mInputJoints.mData.mOffset + v9);
          else
            v11 = 0i64;
          if ( *v11 )
            v12 = (char *)v11 + *v11;
          else
            v12 = 0i64;
          if ( v9 )
            v13 = (char *)&this->mInputJoints.mData + v9;
          else
            v13 = 0i64;
          v14 = *((_QWORD *)v13 + 1);
          if ( v14 )
            v10 = &v13[v14 + 8];
          v15 = (unsigned __int8)v10[20];
          SkeletalPose::GetPositionMS(pose, (unsigned __int8)v12[20], &sourceA);
          SkeletalPose::GetPositionMS(pose, v15, &sourceB);
          BlendSlerp(&matrixMS, &sourceA, &sourceB, 0.5);
        }
        TranslationMS = SkeletalPose::GetTranslationMS(pose, this->mDriveJoint.mJointID);
        mJointID = this->mDriveJoint.mJointID;
        v18 = TranslationMS->m_translation.m_quad.m128_f32[1];
        v19 = TranslationMS->m_translation.m_quad.m128_f32[2];
        LODWORD(matrixMS.v3.x) = TranslationMS->m_translation.m_quad.m128_i32[0];
        matrixMS.v3.y = v18;
        LODWORD(matrixMS.v3.w) = (_DWORD)FLOAT_1_0;
        matrixMS.v3.z = v19;
        SkeletalPose::SetPositionMS(pose, mJointID, &matrixMS);
      }
    }
  }
}

// File Line: 1854
// RVA: 0x14B9A30
__int64 dynamic_initializer_for__TwistXRotLinearLink::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TwistXRotLinearLink", 0xFFFFFFFF);
  TwistXRotLinearLink::sClassNameUID = result;
  return result;
}

// File Line: 1892
// RVA: 0x39E7F0
void __fastcall TwistXRotLinearLink::TwistXRotLinearLink(TwistXRotLinearLink *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&TwistXRotLinearLink::`vftable;
  this->mDriveJoint = UFG::gNullQSymbolUC;
  this->mBaseJoint = UFG::gNullQSymbolUC;
  this->mEndJoint = UFG::gNullQSymbolUC;
  *(_QWORD *)&this->mDriveJointID = -1i64;
  this->mEndJointID = -1;
  this->mAtEnd = 0;
  this->m_M = -0.5;
  this->m_B = 0.0;
  this->mActive = 1;
}

// File Line: 1919
// RVA: 0x3B3900
void __fastcall TwistXRotLinearLink::UpdatePose(TwistXRotLinearLink *this, SkeletalPose *pose)
{
  int mBaseJointID; // edx
  __m128 v5; // xmm2
  UFG::qVector4 v6; // xmm4
  UFG::qVector4 v7; // xmm1
  float v8; // xmm2_4
  float v9; // xmm1_4
  float z; // xmm0_4
  float v11; // xmm0_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-208h] BYREF
  UFG::qMatrix44 matrixLS; // [rsp+60h] [rbp-1C8h] BYREF
  UFG::qMatrix44 b; // [rsp+A0h] [rbp-188h] BYREF
  UFG::qMatrix44 dest; // [rsp+E0h] [rbp-148h] BYREF
  UFG::qMatrix44 matrixRS; // [rsp+120h] [rbp-108h] BYREF
  UFG::qMatrix44 result; // [rsp+160h] [rbp-C8h] BYREF

  if ( !gDisablePoseDrivers )
  {
    if ( this->mActive )
    {
      if ( this->mDriveJointID >= 0 )
      {
        mBaseJointID = this->mBaseJointID;
        if ( mBaseJointID >= 0 && this->mEndJointID >= 0 )
        {
          if ( this->mAtEnd )
            mBaseJointID = this->mEndJointID;
          SkeletalPose::GetPositionMS(pose, mBaseJointID, &b);
          SkeletalPose::GetPositionRefS(pose, this->mEndJointID, &matrixRS);
          SkeletalPose::GetPositionLS(pose, this->mEndJointID, &matrixLS);
          UFG::qInverseAffine(&d, &matrixRS);
          v5 = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 0), (__m128)d.v0),
                       (__m128)0i64),
                     _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 85), (__m128)d.v1)),
                   _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 170), (__m128)d.v2)),
                 _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 255), (__m128)d.v3));
          v6 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 0),
                                        (__m128)d.v0),
                                      (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 85),
                                      (__m128)d.v1)),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 170),
                                    (__m128)d.v2)),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 255), (__m128)d.v3));
          v7 = (UFG::qVector4)_mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 170),
                                    (__m128)d.v2),
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 0),
                                        (__m128)d.v0),
                                      (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 85),
                                      (__m128)d.v1))),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 255), (__m128)d.v3));
          v8 = _mm_shuffle_ps(v5, v5, 170).m128_f32[0];
          d.v0 = (UFG::qVector4)_mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(
                                          _mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 0),
                                          (__m128)d.v0),
                                        (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 85),
                                        (__m128)d.v1)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 170),
                                      (__m128)d.v2)),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 255),
                                    (__m128)d.v3));
          d.v3 = v7;
          v9 = *(float *)&FLOAT_1_0;
          d.v2 = v6;
          if ( v8 <= -1.0 )
          {
            v8 = FLOAT_N1_0;
          }
          else if ( v8 >= 1.0 )
          {
            v8 = *(float *)&FLOAT_1_0;
          }
          z = d.v2.z;
          if ( d.v2.z <= -1.0 )
          {
            z = FLOAT_N1_0;
          }
          else if ( d.v2.z >= 1.0 )
          {
            goto LABEL_17;
          }
          v9 = z;
LABEL_17:
          v11 = atan2f(COERCE_FLOAT(LODWORD(v8) ^ _xmm[0]), v9);
          UFG::qRotationMatrixX(&dest, (float)(v11 * this->m_M) + this->m_B);
          UFG::qMatrix44::operator*(&dest, &result, &b);
          SkeletalPose::SetPositionMS(pose, this->mDriveJointID, &result);
        }
      }
    }
  }
}

// File Line: 1989
// RVA: 0x14B97D0
__int64 dynamic_initializer_for__FollowLink::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FollowLink", 0xFFFFFFFF);
  FollowLink::sClassNameUID = result;
  return result;
}

// File Line: 2024
// RVA: 0x39E0C0
void __fastcall FollowLink::FollowLink(FollowLink *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&FollowLink::`vftable;
  this->mDriveJoint = UFG::gNullQSymbolUC;
  this->mFollowJoint = UFG::gNullQSymbolUC;
  this->mTransformFloatParamRotInput.mValue = 2;
  this->mTransformFloatParamRotOutput.mValue = 2;
  *(_QWORD *)&this->m_M = 1065353216i64;
  this->mDriveJointIsParentOfFollow = 0;
}

// File Line: 2057
// RVA: 0x3B30E0
void __fastcall FollowLink::UpdatePose(FollowLink *this, SkeletalPose *pose)
{
  __int128 v2; // xmm8
  __int128 v3; // xmm9
  __int128 v4; // xmm10
  __int128 v5; // xmm11
  __int128 v6; // xmm12
  __int128 v7; // xmm13
  int mDriveJointID; // edx
  __m128 v11; // xmm11
  __m128 v12; // xmm5
  unsigned __int64 v13; // xmm4_8
  __m128 v14; // xmm0
  signed int mValue; // ecx
  double v16; // xmm0_8
  float v17; // xmm6_4
  Render::DebugDrawContext *Context; // rax
  __int64 v19; // rcx
  const char *v20; // rcx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  UFG::qVector4 v23; // xmm2
  UFG::qMatrix44 *v24; // rax
  bool v25; // zf
  UFG::qVector4 v26; // xmm2
  UFG::qVector4 v27; // xmm1
  UFG::qVector4 v28; // xmm0
  UFG::qVector3 world_position; // [rsp+40h] [rbp-B8h] BYREF
  __m128 d; // [rsp+50h] [rbp-A8h] BYREF
  __m128 d_16; // [rsp+60h] [rbp-98h]
  _BYTE d_32[24]; // [rsp+70h] [rbp-88h]
  UFG::qMatrix44 d_56; // [rsp+88h] [rbp-70h] BYREF
  UFG::qMatrix44 v34; // [rsp+C8h] [rbp-30h] BYREF
  UFG::qMatrix44 matrixLS; // [rsp+108h] [rbp+10h] BYREF
  UFG::qMatrix44 matrixRS; // [rsp+148h] [rbp+50h] BYREF
  UFG::qMatrix44 b; // [rsp+188h] [rbp+90h] BYREF
  UFG::qMatrix44 matrixMS; // [rsp+1C8h] [rbp+D0h] BYREF
  __int128 v39; // [rsp+210h] [rbp+118h]
  __int128 v40; // [rsp+220h] [rbp+128h]
  __int128 v41; // [rsp+230h] [rbp+138h]
  __int128 v42; // [rsp+240h] [rbp+148h]
  __int128 v43; // [rsp+250h] [rbp+158h]
  __int128 v44; // [rsp+260h] [rbp+168h]

  mDriveJointID = this->mDriveJointID;
  this->mActive = 1;
  if ( mDriveJointID >= 0 && this->mFollowJointID >= 0 )
  {
    v44 = v2;
    v43 = v3;
    v42 = v4;
    v41 = v5;
    v40 = v6;
    v39 = v7;
    SkeletalPose::GetPositionLS(pose, mDriveJointID, &matrixLS);
    SkeletalPose::GetPositionRefS(pose, this->mDriveJointID, &matrixRS);
    UFG::qInverseAffine((UFG::qMatrix44 *)&d, &matrixRS);
    v11 = *(__m128 *)d_32;
    v12 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 0), d), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 85), d_16)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 170), *(__m128 *)d_32)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 255), *(__m128 *)&d_32[8]));
    v13 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 0), d), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 85), d_16)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 170), *(__m128 *)d_32)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 255), *(__m128 *)&d_32[8])).m128_u64[0];
    v14 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 85), d_16),
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 0), d), (__m128)0i64));
    mValue = this->mTransformFloatParamRotInput.mValue;
    d = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 0), d), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 85), d_16)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 170), *(__m128 *)d_32)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 255), *(__m128 *)&d_32[8]));
    d_16 = v12;
    *(_QWORD *)d_32 = v13;
    *(__m128 *)&d_32[8] = _mm_add_ps(
                            _mm_add_ps(
                              v14,
                              _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 170), v11)),
                            _mm_mul_ps(
                              _mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 255),
                              *(__m128 *)&d_32[8]));
    v16 = ERotation((TransformFloatParamRot)mValue, (UFG::qMatrix44 *)&d);
    v17 = (float)(*(float *)&v16 * this->m_M) + this->m_B;
    if ( sFollowLinkDebug )
    {
      SkeletalPose::GetPositionWS(pose, this->mDriveJointID, (UFG::qMatrix44 *)&d);
      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                              Render::DebugDrawManager::mInstance,
                                              1u);
      v19 = (int)this->mTransformFloatParamRotInput.mValue;
      world_position.y = *(float *)&d_32[12];
      world_position.x = *(float *)&d_32[8];
      v20 = gTransformFloatParamRotStringList[v19];
      world_position.z = *(float *)&d_32[16];
      Render::DebugDrawContext::DrawText(
        Context,
        &world_position,
        &UFG::qColour::Green,
        "input:%s:%0.3f -> %0.3f",
        v20,
        *(float *)&v16,
        v17);
    }
    v21 = this->mTransformFloatParamRotOutput.mValue;
    if ( v21 )
    {
      v22 = v21 - 1;
      if ( v22 )
      {
        if ( v22 == 1 )
        {
          UFG::qRotationMatrixZ(&d_56, v17);
        }
        else
        {
          v23 = 0i64;
          v23.x = (float)1;
          d_56.v0 = v23;
          d_56.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 21);
          d_56.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 81);
          d_56.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v23, (__m128)v23, 69);
        }
      }
      else
      {
        UFG::qRotationMatrixY(&d_56, v17);
      }
    }
    else
    {
      UFG::qRotationMatrixX(&d_56, v17);
    }
    SkeletalPose::GetPositionRefS(pose, this->mFollowJointID, &b);
    v24 = UFG::qMatrix44::operator*(&d_56, (UFG::qMatrix44 *)&d, &b);
    v25 = this->mDriveJointIsParentOfFollow == 0;
    v26 = v24->v2;
    v27 = v24->v3;
    v28 = v24->v0;
    v34.v1 = v24->v1;
    v34.v2 = v26;
    v34.v0 = v28;
    v34.v3 = v27;
    if ( !v25 )
      SkeletalPose::GetPositionMS(pose, this->mDriveJointID, &matrixMS);
    SkeletalPose::SetPositionLS(pose, this->mFollowJointID, &v34);
    if ( this->mDriveJointIsParentOfFollow )
      SkeletalPose::SetPositionMS(pose, this->mDriveJointID, &matrixMS);
  }
}

// File Line: 2127
// RVA: 0x14B9790
__int64 dynamic_initializer_for__Follow2Link::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Follow2Link", 0xFFFFFFFF);
  Follow2Link::sClassNameUID = result;
  return result;
}

// File Line: 2155
// RVA: 0x39DFC0
void __fastcall Follow2Link::Follow2Link(Follow2Link *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&Follow2Link::`vftable;
  this->mDriveJoint = UFG::gNullQSymbolUC;
  this->mFollowJoint = UFG::gNullQSymbolUC;
}

// File Line: 2175
// RVA: 0x3B2D90
void __fastcall Follow2Link::UpdatePose(Follow2Link *this, SkeletalPose *pose)
{
  __int128 v2; // xmm6
  __int128 v3; // xmm7
  __int128 v4; // xmm8
  int mDriveJointID; // edx
  hkQsTransformf *v8; // rdx
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  int v12; // edx
  UFG::qMatrix44 v13; // [rsp+20h] [rbp-F8h] BYREF
  UFG::qMatrix44 matrixLS; // [rsp+60h] [rbp-B8h] BYREF
  UFG::qMatrix44 matrixMS; // [rsp+A0h] [rbp-78h] BYREF
  __int128 v16; // [rsp+E0h] [rbp-38h]
  __int128 v17; // [rsp+F0h] [rbp-28h]
  __int128 v18; // [rsp+100h] [rbp-18h]

  mDriveJointID = this->mDriveJointID;
  this->mActive = 1;
  if ( mDriveJointID >= 0 && this->mFollowJointID >= 0 )
  {
    v18 = v2;
    v17 = v3;
    v16 = v4;
    SkeletalPose::GetPositionLS(pose, mDriveJointID, &matrixLS);
    v8 = &pose->mRigHandle.mUFGSkeleton->mhkaSkeleton->m_referencePose.m_data[this->mDriveJointID];
    v9 = matrixLS.v3.x - v8->m_translation.m_quad.m128_f32[0];
    v10 = matrixLS.v3.y - v8->m_translation.m_quad.m128_f32[1];
    v11 = matrixLS.v3.z - v8->m_translation.m_quad.m128_f32[2];
    SkeletalPose::GetPositionLS(pose, this->mFollowJointID, &v13);
    v12 = this->mDriveJointID;
    v13.v3.y = v13.v3.y + v10;
    v13.v3.x = v13.v3.x + v9;
    v13.v3.w = v13.v3.w + 1.0;
    v13.v3.z = v13.v3.z + v11;
    SkeletalPose::GetPositionMS(pose, v12, &matrixMS);
    SkeletalPose::SetPositionLS(pose, this->mFollowJointID, &v13);
    SkeletalPose::SetPositionMS(pose, this->mDriveJointID, &matrixMS);
  }
}

// File Line: 2209
// RVA: 0x14B97B0
__int64 dynamic_initializer_for__Follow3Link::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Follow3Link", 0xFFFFFFFF);
  Follow3Link::sClassNameUID = result;
  return result;
}

// File Line: 2237
// RVA: 0x39E040
void __fastcall Follow3Link::Follow3Link(Follow3Link *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&Follow3Link::`vftable;
  this->mDriveJoint = UFG::gNullQSymbolUC;
  this->mFollowJoint = UFG::gNullQSymbolUC;
}

// File Line: 2256
// RVA: 0x3B2EE0
void __fastcall Follow3Link::UpdatePose(Follow3Link *this, SkeletalPose *pose)
{
  __int128 v2; // xmm6
  __int128 v3; // xmm7
  __int128 v4; // xmm8
  __int128 v5; // xmm9
  __int128 v6; // xmm10
  int mDriveJointID; // edx
  float v10; // xmm2_4
  __m128 z_low; // xmm1
  hkQsTransformf *v12; // rdx
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm1_4
  float v16; // xmm8_4
  float v17; // xmm7_4
  __m128 v18; // xmm3
  float v19; // xmm6_4
  float v20; // xmm10_4
  float v21; // xmm6_4
  float v22; // xmm10_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  UFG::qMatrix44 matrixLS; // [rsp+20h] [rbp-198h] BYREF
  UFG::qMatrix44 dest; // [rsp+60h] [rbp-158h] BYREF
  UFG::qMatrix44 result; // [rsp+A0h] [rbp-118h] BYREF
  UFG::qMatrix44 b; // [rsp+E0h] [rbp-D8h] BYREF
  UFG::qMatrix44 matrixMS; // [rsp+120h] [rbp-98h] BYREF
  __int128 v30; // [rsp+160h] [rbp-58h]
  __int128 v31; // [rsp+170h] [rbp-48h]
  __int128 v32; // [rsp+180h] [rbp-38h]
  __int128 v33; // [rsp+190h] [rbp-28h]
  __int128 v34; // [rsp+1A0h] [rbp-18h]

  mDriveJointID = this->mDriveJointID;
  this->mActive = 1;
  if ( mDriveJointID < 0 || this->mFollowJointID < 0 )
    return;
  v34 = v2;
  v33 = v3;
  v32 = v4;
  v31 = v5;
  v30 = v6;
  SkeletalPose::GetPositionLS(pose, mDriveJointID, &matrixLS);
  v10 = *(float *)&FLOAT_1_0;
  z_low = (__m128)LODWORD(matrixLS.v3.z);
  z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(matrixLS.v3.x * matrixLS.v3.x);
  v12 = &pose->mRigHandle.mUFGSkeleton->mhkaSkeleton->m_referencePose.m_data[this->mDriveJointID];
  v13 = v12->m_translation.m_quad.m128_f32[0];
  v14 = v12->m_translation.m_quad.m128_f32[2];
  if ( z_low.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / _mm_sqrt_ps(z_low).m128_f32[0];
  v18 = (__m128)v12->m_translation.m_quad.m128_u32[2];
  v16 = matrixLS.v3.x * v15;
  v17 = matrixLS.v3.z * v15;
  v18.m128_f32[0] = (float)(v14 * v14) + (float)(v13 * v13);
  if ( v18.m128_f32[0] == 0.0 )
    v19 = 0.0;
  else
    v19 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
  v20 = v19;
  v21 = v19 * v14;
  v22 = v20 * v13;
  v23 = (float)(v17 * v21) + (float)(v16 * v22);
  if ( v23 <= -1.0 )
  {
    v23 = FLOAT_N1_0;
  }
  else if ( v23 >= 1.0 )
  {
    goto LABEL_14;
  }
  v10 = v23;
LABEL_14:
  v24 = acosf(v10);
  if ( (float)((float)(v17 * v22) - (float)(v16 * v21)) > 0.0 )
    LODWORD(v24) ^= _xmm[0];
  UFG::qRotationMatrixY(&dest, v24);
  SkeletalPose::GetPositionLS(pose, this->mFollowJointID, &b);
  UFG::qMatrix44::operator*(&dest, &result, &b);
  SkeletalPose::GetPositionMS(pose, this->mDriveJointID, &matrixMS);
  SkeletalPose::SetPositionLS(pose, this->mFollowJointID, &result);
  SkeletalPose::SetPositionMS(pose, this->mDriveJointID, &matrixMS);
}

// File Line: 2304
// RVA: 0x14B9770
__int64 dynamic_initializer_for__DebugJointManipulater::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DebugJointManipulater", 0xFFFFFFFF);
  DebugJointManipulater::sClassNameUID = result;
  return result;
}

// File Line: 2342
// RVA: 0x14B99D0
__int64 dynamic_initializer_for__Spring1DOF::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Spring1DOF", 0xFFFFFFFF);
  Spring1DOF::sClassNameUID = result;
  return result;
}

// File Line: 2392
// RVA: 0x39E6F0
void __fastcall Spring1DOF::Spring1DOF(Spring1DOF *this)
{
  UFG::qVector4 v1; // xmm1
  UFG::qVector4 v2; // xmm2
  UFG::qVector4 v3; // xmm3

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&Spring1DOF::`vftable;
  this->mFollowJoint = UFG::gNullQSymbolUC;
  this->mTransformFollowAxis.mValue = 2;
  this->mTransformSpace.mValue = 2;
  this->mMass = 2.0;
  this->mCV = 4.0;
  this->mGain = 20.0;
  *(_QWORD *)&this->mCurrentBase = 0i64;
  *(_QWORD *)&this->mXcurr = 0i64;
  this->mTimeDelta = 0.0;
  this->mMinLimit = 0.2;
  this->mMaxLimit = 0.2;
  v1 = UFG::qMatrix44::msIdentity.v1;
  v2 = UFG::qMatrix44::msIdentity.v2;
  v3 = UFG::qMatrix44::msIdentity.v3;
  this->mCurrentTransform.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mCurrentTransform.v1 = v1;
  this->mCurrentTransform.v2 = v2;
  this->mCurrentTransform.v3 = v3;
  this->mTeleported = 0;
}

// File Line: 2463
// RVA: 0x3B1500
bool __fastcall Spring1DOF::Update(Spring1DOF *this, float timeDelta)
{
  bool result; // al

  this->mTimeDelta = timeDelta;
  if ( timeDelta == 0.0 )
    this->mTimeDelta = 0.033333335;
  result = 1;
  if ( this->mTimeDelta > 0.033333335 )
    this->mTimeDelta = 0.033333335;
  return result;
}

// File Line: 2503
// RVA: 0x3AF820
void __fastcall SetTransAlongAxisCoord(TransformFloatParamTrans axis, UFG::qMatrix44 *transform, float value)
{
  int v4; // ecx
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  if ( axis )
  {
    v4 = axis - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        x = transform->v2.x;
        y = transform->v2.y;
        z = transform->v2.z;
      }
      else
      {
        x = UFG::qVector4::msZero.x;
        y = UFG::qVector4::msZero.y;
        z = UFG::qVector4::msZero.z;
      }
    }
    else
    {
      x = transform->v1.x;
      y = transform->v1.y;
      z = transform->v1.z;
    }
  }
  else
  {
    x = transform->v0.x;
    y = transform->v0.y;
    z = transform->v0.z;
  }
  v8 = (float)(y * value) + transform->v3.y;
  v9 = (float)(z * value) + transform->v3.z;
  transform->v3.x = (float)(x * value) + transform->v3.x;
  transform->v3.y = v8;
  transform->v3.z = v9;
}

// File Line: 2517
// RVA: 0x3B40F0
void __fastcall Spring1DOF::UpdatePosePostPhysics(Spring1DOF *this, SkeletalPose *pose)
{
  int mFollowJointID; // edx
  __m128 v5; // xmm6
  UFG::qVector4 v6; // xmm0
  UFG::qVector4 v7; // xmm1
  int mValue; // ecx
  float v9; // xmm8_4
  int v10; // ecx
  unsigned int v11; // xmm0_4
  bool v12; // zf
  float x; // xmm9_4
  float y; // xmm10_4
  float z; // xmm7_4
  float w; // xmm11_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  int v20; // ecx
  int v21; // ecx
  float mXcurr; // xmm4_4
  float mTimeDelta; // xmm2_4
  float v24; // xmm3_4
  const char *v25; // r14
  Render::DebugDrawContext *Context; // rbx
  const char *v27; // r9
  const char *v28; // r9
  int v29; // eax
  float v30; // xmm9_4
  float v31; // xmm10_4
  float v32; // xmm11_4
  int v33; // ecx
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  float mMinLimit; // xmm0_4
  float v38; // xmm8_4
  float v39; // xmm7_4
  float v40; // xmm3_4
  float mMaxLimit; // xmm0_4
  float v42; // xmm6_4
  float v43; // xmm12_4
  float v44; // xmm13_4
  float v45; // xmm14_4
  float v46; // xmm0_4
  float v47; // xmm8_4
  float v48; // xmm7_4
  float v49; // xmm6_4
  const char *v50; // r9
  const char *v51; // r9
  float v52; // xmm11_4
  double v53; // xmm0_8
  float v54; // xmm9_4
  float v55; // xmm10_4
  int v56; // eax
  int v57; // ecx
  int v58; // ecx
  Render::DebugDrawContext *v59; // rbx
  UFG::qVector4 v60; // xmm1
  UFG::qVector3 p0; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qVector3 p1; // [rsp+3Ch] [rbp-ACh] BYREF
  float d; // [rsp+50h] [rbp-98h] BYREF
  float d_4; // [rsp+54h] [rbp-94h]
  float d_8; // [rsp+58h] [rbp-90h]
  float d_16; // [rsp+60h] [rbp-88h]
  float d_20; // [rsp+64h] [rbp-84h]
  float d_24; // [rsp+68h] [rbp-80h]
  float d_28; // [rsp+6Ch] [rbp-7Ch]
  float d_32; // [rsp+70h] [rbp-78h]
  float d_36; // [rsp+74h] [rbp-74h]
  UFG::qMatrix44 d_40; // [rsp+78h] [rbp-70h] BYREF
  UFG::qMatrix44 matrixRoot; // [rsp+B8h] [rbp-30h] BYREF
  UFG::qMatrix44 result; // [rsp+F8h] [rbp+10h] BYREF

  mFollowJointID = this->mFollowJointID;
  this->mActive = 1;
  SkeletalPose::GetPositionMS(pose, mFollowJointID, &d_40);
  v5 = (__m128)d_40.v3;
  if ( this->mTeleported )
  {
    v6 = d_40.v0;
    v7 = d_40.v2;
    this->mTeleported = 0;
    this->mCurrentTransform.v0 = v6;
    this->mCurrentTransform.v1 = d_40.v1;
    this->mCurrentTransform.v2 = v7;
    this->mCurrentTransform.v3 = (UFG::qVector4)v5;
  }
  mValue = this->mTransformFollowAxis.mValue;
  v9 = 0.0;
  if ( mValue )
  {
    v10 = mValue - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        v11 = _mm_shuffle_ps(v5, v5, 170).m128_u32[0];
      else
        v11 = 0;
    }
    else
    {
      v11 = _mm_shuffle_ps(v5, v5, 85).m128_u32[0];
    }
  }
  else
  {
    v11 = v5.m128_i32[0];
  }
  v12 = this->mTransformSpace.mValue == 1;
  LODWORD(this->mNeutralBase) = v11;
  x = this->mCurrentTransform.v3.x;
  y = this->mCurrentTransform.v3.y;
  z = this->mCurrentTransform.v3.z;
  w = this->mCurrentTransform.v3.w;
  if ( v12 )
  {
    UFG::qInverseAffine((UFG::qMatrix44 *)&d, &d_40);
    this->mNeutralBase = 0.0;
    v5 = (__m128)d_40.v3;
    v17 = (float)((float)((float)(d_20 * y) + (float)(d_4 * x)) + (float)(d_36 * z)) + (float)(d_28 * w);
    v18 = d_8 * x;
    x = (float)((float)((float)(d_16 * y) + (float)(d * x)) + (float)(d_32 * z)) + (float)(d_24 * w);
    v19 = (float)(d_24 * y) + v18;
    y = v17;
    z = (float)(v19 + (float)(d_40.v0.x * z)) + (float)(d_32 * w);
  }
  v20 = this->mTransformFollowAxis.mValue;
  if ( v20 )
  {
    v21 = v20 - 1;
    if ( v21 )
    {
      if ( v21 == 1 )
        v9 = z;
    }
    else
    {
      v9 = y;
    }
  }
  else
  {
    v9 = x;
  }
  this->mXcurr = v9;
  Spring1DOF::enforceLimits(this);
  mXcurr = this->mXcurr;
  mTimeDelta = this->mTimeDelta;
  v24 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                               (float)((float)((float)(mXcurr - this->mNeutralBase) * this->mGain)
                                     + (float)(this->mXdotcurr * this->mCV))
                             / this->mMass) ^ _xmm[0])
              * mTimeDelta)
      + this->mXdotcurr;
  this->mXdotcurr = v24;
  this->mXcurr = (float)(v24 * mTimeDelta) + mXcurr;
  Spring1DOF::enforceLimits(this);
  v25 = &customCaption;
  if ( this->mBreakpoint )
  {
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    SkeletalPose::GetRootMatrix(pose, &matrixRoot);
    UFG::qMatrix44::operator*(&this->mCurrentTransform, &result, &matrixRoot);
    SkeletalPose::GetPositionWS(pose, this->mFollowJointID, (UFG::qMatrix44 *)&d);
    v27 = &customCaption;
    if ( sText )
      v27 = "p0";
    Render::DebugDrawContext::DrawCoord(Context, &result, boneScale, v27);
    v28 = &customCaption;
    if ( sText )
      v28 = "pF";
    Render::DebugDrawContext::DrawCoord(Context, (UFG::qMatrix44 *)&d, boneScale, v28);
    v29 = this->mTransformSpace.mValue;
    v30 = d_24;
    v31 = d_28;
    v32 = d_32;
    if ( v29 == 2 )
    {
      v33 = this->mTransformFollowAxis.mValue;
      if ( !v33 )
      {
        v30 = matrixRoot.v0.x;
        v31 = matrixRoot.v0.y;
        v32 = matrixRoot.v0.z;
        goto LABEL_38;
      }
      v34 = v33 - 1;
      if ( !v34 )
      {
        v30 = matrixRoot.v1.x;
        v31 = matrixRoot.v1.y;
        v32 = matrixRoot.v1.z;
        goto LABEL_38;
      }
      if ( v34 == 1 )
      {
        v30 = matrixRoot.v2.x;
        v31 = matrixRoot.v2.y;
        v32 = matrixRoot.v2.z;
LABEL_38:
        mMinLimit = this->mMinLimit;
        v38 = d_24 - (float)(v30 * mMinLimit);
        v39 = d_28 - (float)(v31 * mMinLimit);
        v40 = v32 * mMinLimit;
        mMaxLimit = this->mMaxLimit;
        v42 = d_32 - v40;
        p1.x = v38;
        v43 = d_24 + (float)(v30 * mMaxLimit);
        v44 = d_28 + (float)(v31 * mMaxLimit);
        p1.y = v39;
        v45 = d_32 + (float)(v32 * mMaxLimit);
        p1.z = d_32 - v40;
        p0.x = v38 - (float)(v30 * sLimitArrowTail);
        p0.z = (float)(d_32 - v40) - (float)(v32 * sLimitArrowTail);
        p0.y = v39 - (float)(v31 * sLimitArrowTail);
        Render::DebugDrawContext::DrawArrow(
          Context,
          &p0,
          &p1,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback);
        p0.x = v43;
        p0.y = v44;
        p0.z = v45;
        p1.x = (float)(v30 * sLimitArrowTail) + v43;
        p1.y = (float)(v31 * sLimitArrowTail) + v44;
        p1.z = (float)(v32 * sLimitArrowTail) + v45;
        Render::DebugDrawContext::DrawArrow(
          Context,
          &p1,
          &p0,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback);
        v46 = this->mMinLimit;
        v47 = v38 - (float)(v30 * sLimitArrowTail);
        v48 = v39 - (float)(v31 * sLimitArrowTail);
        v49 = v42 - (float)(v32 * sLimitArrowTail);
        v50 = &customCaption;
        if ( sText )
          v50 = "MinLimit:%0.3f";
        p0.x = v47;
        p0.y = v48;
        p0.z = v49;
        Render::DebugDrawContext::DrawText(Context, &p0, &UFG::qColour::Green, v50, v46);
        v51 = &customCaption;
        v52 = v32 * sLimitArrowTail;
        v53 = this->mMaxLimit;
        v54 = (float)(v30 * sLimitArrowTail) + v43;
        v55 = (float)(v31 * sLimitArrowTail) + v44;
        if ( sText )
          v51 = "MaxLimit:%0.3f";
        p0.x = v54;
        p0.y = v55;
        p0.z = v52 + v45;
        Render::DebugDrawContext::DrawText(Context, &p0, &UFG::qColour::Green, v51, v53);
        v5 = (__m128)d_40.v3;
        goto LABEL_43;
      }
    }
    else
    {
      if ( v29 != 1 )
        goto LABEL_38;
      v35 = this->mTransformFollowAxis.mValue;
      if ( !v35 )
      {
        v30 = d;
        v31 = d_4;
        v32 = d_8;
        goto LABEL_38;
      }
      v36 = v35 - 1;
      if ( !v36 )
      {
        v30 = d_16;
        v31 = d_20;
        v32 = d_24;
        goto LABEL_38;
      }
      if ( v36 == 1 )
      {
        v30 = d_32;
        v31 = d_36;
        v32 = d_40.v0.x;
        goto LABEL_38;
      }
    }
    v30 = UFG::qVector4::msZero.x;
    v31 = UFG::qVector4::msZero.y;
    v32 = UFG::qVector4::msZero.z;
    goto LABEL_38;
  }
LABEL_43:
  v56 = this->mTransformSpace.mValue;
  if ( v56 == 2 )
  {
    v57 = this->mTransformFollowAxis.mValue;
    if ( v57 )
    {
      v58 = v57 - 1;
      if ( v58 )
      {
        if ( v58 == 1 )
          d_40.v3.z = this->mXcurr;
      }
      else
      {
        d_40.v3.y = this->mXcurr;
      }
    }
    else
    {
      d_40.v3.x = this->mXcurr;
    }
  }
  else
  {
    if ( v56 != 1 )
      goto LABEL_53;
    SetTransAlongAxisCoord((TransformFloatParamTrans)this->mTransformFollowAxis.mValue, &d_40, this->mXcurr);
  }
  SkeletalPose::SetPositionMS(pose, this->mFollowJointID, &d_40);
  v5 = (__m128)d_40.v3;
LABEL_53:
  if ( this->mBreakpoint )
  {
    v59 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    SkeletalPose::GetPositionWS(pose, this->mFollowJointID, &result);
    if ( sText )
      v25 = "pT";
    Render::DebugDrawContext::DrawCoord(v59, &result, boneScale_0, v25);
    v5 = (__m128)d_40.v3;
  }
  v60 = d_40.v2;
  this->mCurrentTransform.v0 = d_40.v0;
  this->mCurrentTransform.v1 = d_40.v1;
  this->mCurrentTransform.v2 = v60;
  this->mCurrentTransform.v3 = (UFG::qVector4)v5;
}

// File Line: 2637
// RVA: 0x3B6A90
void __fastcall Spring1DOF::enforceLimits(Spring1DOF *this)
{
  float mNeutralBase; // xmm1_4
  float mMaxLimit; // xmm0_4
  float v3; // xmm2_4
  bool v4; // cc

  mNeutralBase = this->mNeutralBase;
  mMaxLimit = this->mMaxLimit;
  v3 = this->mXcurr - mNeutralBase;
  if ( mMaxLimit >= v3 )
  {
    if ( COERCE_FLOAT(LODWORD(this->mMinLimit) ^ _xmm[0]) > v3 )
    {
      v4 = this->mXdotcurr >= 0.0;
      this->mXcurr = mNeutralBase - this->mMinLimit;
      if ( !v4 )
        this->mXdotcurr = 0.0;
    }
  }
  else
  {
    this->mXcurr = mMaxLimit + mNeutralBase;
    if ( this->mXdotcurr > 0.0 )
      this->mXdotcurr = 0.0;
  }
}

// File Line: 2660
// RVA: 0x3A1930
bool __fastcall Spring1DOF::AddTo(Spring1DOF *this, Creature *creature)
{
  int BoneID; // eax
  UFG::qNode<PoseDriver,PoseDriver> *mPrev; // rax
  bool result; // al
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm0
  UFG::qMatrix44 matrixMS; // [rsp+20h] [rbp-48h] BYREF

  if ( !creature->mPose.mRigHandle.mData )
    return 0;
  BoneID = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFollowJoint.mUID);
  if ( BoneID == -1 )
    return 0;
  this->mFollowJointID = BoneID;
  mPrev = creature->mPoseDrivers.mNode.mPrev;
  mPrev->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mPrev = mPrev;
  this->mNext = &creature->mPoseDrivers.mNode;
  creature->mPoseDrivers.mNode.mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  SkeletalPose::GetPositionMS(&creature->mPose, this->mFollowJointID, &matrixMS);
  result = 1;
  v7 = matrixMS.v2;
  this->mCurrentTransform.v0 = matrixMS.v0;
  this->mCurrentTransform.v1 = matrixMS.v1;
  v8 = matrixMS.v3;
  this->mCurrentTransform.v2 = v7;
  this->mCurrentTransform.v3 = v8;
  return result;
}

// File Line: 2680
// RVA: 0x3AC420
void __fastcall Spring1DOF::OnTeleport(Spring1DOF *this, SkeletalPose *pose)
{
  this->mTeleported = 1;
}

// File Line: 2690
// RVA: 0x14B97F0
__int64 dynamic_initializer_for__GravityDriver::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GravityDriver", 0xFFFFFFFF);
  GravityDriver::sClassNameUID = result;
  return result;
}

// File Line: 2881
// RVA: 0x14B9950
__int64 dynamic_initializer_for__RootUprightDriver::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RootUprightDriver", 0xFFFFFFFF);
  RootUprightDriver::sClassNameUID = result;
  return result;
}

// File Line: 2907
// RVA: 0x39E5A0
void __fastcall RootUprightDriver::RootUprightDriver(RootUprightDriver *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->PoseDriver::Expression::IMemberMap::mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->mNext = &this->UFG::qNode<PoseDriver,PoseDriver>;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable;
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&RootUprightDriver::`vftable;
  *(_QWORD *)&this->mUprightVector.x = 0i64;
  this->mUprightVector.z = 1.0;
}

// File Line: 2922
// RVA: 0x3B14B0
bool __fastcall RootUprightDriver::Update(RootUprightDriver *this, float timeDelta)
{
  float mBlendRate; // xmm3_4
  bool result; // al
  float v4; // xmm0_4

  if ( !this->mActive )
    return 1;
  mBlendRate = this->mBlendRate;
  if ( mBlendRate == 0.0 )
    return 1;
  result = 1;
  v4 = (float)(mBlendRate * timeDelta) + this->mBlendWeight;
  this->mBlendWeight = v4;
  if ( mBlendRate <= 0.0 )
  {
    if ( v4 <= 0.0 )
      this->mBlendWeight = 0.0;
  }
  else if ( v4 > 1.0 )
  {
    this->mBlendWeight = 1.0;
  }
  return result;
}

// File Line: 2950
// RVA: 0x3B3610
void __fastcall RootUprightDriver::UpdatePose(RootUprightDriver *this, SkeletalPose *pose)
{
  float v4; // xmm6_4
  hkQsTransformf *Root; // rax
  float y; // xmm7_4
  __m128 x_low; // xmm10
  float z; // xmm9_4
  float x; // xmm15_4
  __int64 v10; // kr00_8
  float v11; // xmm2_4
  float v12; // xmm0_4
  int v13; // xmm1_4
  float v14; // xmm4_4
  __m128 v15; // xmm5
  float v16; // xmm7_4
  __m128 v17; // xmm2
  UFG::qMatrix44 *v18; // rax
  bool v19; // zf
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm3
  hkQsTransformf *v22; // rax
  UFG::qMatrix44 d; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qVector3 axis; // [rsp+60h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+70h] [rbp-78h] BYREF
  UFG::qMatrix44 sourceA; // [rsp+D8h] [rbp-10h] BYREF
  float v27; // [rsp+198h] [rbp+B0h]

  if ( this->mActive )
  {
    v4 = 0.0;
    if ( this->mBlendWeight > 0.0 )
    {
      Root = SkeletalPose::GetRoot(pose);
      hkQsTransformf::get4x4ColumnMajor(Root, &d.v0.x);
      y = this->mUprightVector.y;
      x_low = (__m128)LODWORD(this->mUprightVector.x);
      z = this->mUprightVector.z;
      x = d.v3.x;
      v27 = d.v3.y;
      v10 = *(_QWORD *)&d.v3.z;
      v11 = (float)((float)(y * d.v2.y) + (float)(x_low.m128_f32[0] * d.v2.x)) + (float)(z * d.v2.z);
      if ( v11 <= -1.0 )
      {
        v11 = FLOAT_N1_0;
      }
      else if ( v11 >= 1.0 )
      {
        v11 = *(float *)&FLOAT_1_0;
      }
      v12 = acosf(v11);
      *(float *)&v13 = v12;
      if ( v12 < 0.0 )
        v13 = LODWORD(v12) ^ _xmm[0];
      if ( *(float *)&v13 >= 0.0015 )
      {
        v15 = x_low;
        v14 = (float)(z * d.v2.y) - (float)(y * d.v2.z);
        v15.m128_f32[0] = (float)(x_low.m128_f32[0] * d.v2.z) - (float)(z * d.v2.x);
        v16 = (float)(y * d.v2.x) - (float)(x_low.m128_f32[0] * d.v2.y);
        v17 = v15;
        v17.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
        if ( v17.m128_f32[0] != 0.0 )
          v4 = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
        axis.x = v14 * v4;
        axis.y = v15.m128_f32[0] * v4;
        axis.z = v16 * v4;
        UFG::qRotationMatrixAxis((UFG::qMatrix44 *)&result.v2.z, &axis, COERCE_FLOAT(LODWORD(v12) ^ _xmm[0]));
        d.v3.x = UFG::qVector3::msZero.x;
        d.v3.w = 1.0;
        *(_QWORD *)&d.v3.y = *(_QWORD *)&UFG::qVector3::msZero.y;
        v18 = UFG::qMatrix44::operator*(&d, &result, (UFG::qMatrix44 *)&result.v2.z);
        v19 = 1.0 == this->mBlendWeight;
        v20 = v18->v2;
        v21 = v18->v1;
        d.v0 = v18->v0;
        d.v2 = v20;
        d.v3.y = v27;
        *(_QWORD *)&d.v3.z = v10;
        d.v3.x = x;
        d.v1 = v21;
        if ( v19 )
        {
          SkeletalPose::SetRoot(pose, &d, 0);
          this->mActive = 0;
        }
        else
        {
          v22 = SkeletalPose::GetRoot(pose);
          hkQsTransformf::get4x4ColumnMajor(v22, &sourceA.v0.x);
          BlendSlerp(&result, &sourceA, &d, this->mBlendWeight);
          SkeletalPose::SetRoot(pose, &result, 0);
        }
      }
    }
  }
}

