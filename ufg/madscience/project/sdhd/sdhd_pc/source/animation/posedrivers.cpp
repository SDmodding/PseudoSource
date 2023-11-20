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
  return atexit(dynamic_atexit_destructor_for__gPoseDriverFactory__);
}

// File Line: 84
// RVA: 0x14BF7B0
__int64 dynamic_initializer_for__symEffectorNone__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("none", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symEffectorNone, v0);
  return atexit(dynamic_atexit_destructor_for__symEffectorNone__);
}

// File Line: 90
// RVA: 0x39E2B0
void __fastcall PoseDriver::PoseDriver(PoseDriver *this)
{
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
}

// File Line: 95
// RVA: 0x39FA60
void __fastcall PoseDriver::~PoseDriver(PoseDriver *this)
{
  UFG::qNode<PoseDriver,PoseDriver> *v1; // r8
  UFG::qNode<PoseDriver,PoseDriver> *v2; // rdx
  UFG::qNode<PoseDriver,PoseDriver> *v3; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = this->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimConstraint::`vftable';
  this->mAimAxis.mValue = 1;
  this->mEffectorJoint = UFG::gNullQSymbolUC;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->mAimAxisLS.x = UFG::qVector3::msZero.x;
  this->mAimAxisLS.y = v2;
  this->mAimAxisLS.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mTargetPointWS.x = UFG::qVector3::msZero.x;
  this->mTargetPointWS.y = v4;
  this->mTargetPointWS.z = v5;
  *(_QWORD *)&this->mRotationX = 0i64;
  this->mRotationY = 0.0;
  this->mXJointLimitMag = 0.87266463;
  this->mZJointLimitMag = 0.40000001;
  this->mYJointLimitMag = 0.40000001;
  *(_QWORD *)&this->mTrackingGain = 1036831949i64;
}

// File Line: 211
// RVA: 0x3B05F0
char __fastcall AimConstraint::Update(AimConstraint *this, float timeDelta)
{
  char result; // al
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
  AimConstraint *v2; // rbx
  SkeletalPose *v3; // rdi
  float v4; // xmm11_4
  float v5; // xmm7_4
  __int64 v6; // r8
  hkaPose *v7; // rdx
  hkQuaternionf *v8; // rcx
  float v9; // xmm2_4
  __m128 v10; // xmm3
  float v11; // xmm4_4
  __m128 v12; // xmm5
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm13_4
  __m128 v18; // xmm8
  __m128 v19; // xmm9
  __m128 v20; // xmm3
  unsigned int v21; // xmm0_4
  float v22; // xmm8_4
  unsigned int v23; // xmm6_4
  int v24; // xmm12_4
  unsigned int v25; // xmm2_4
  float v26; // xmm1_4
  float rotY; // xmm2_4
  float v28; // xmm6_4
  float v29; // xmm8_4
  float v30; // xmm8_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // xmm8_4
  float v37; // xmm4_4
  float v38; // xmm0_4
  int v39; // xmm1_4
  float v40; // xmm1_4
  UFG::qMatrix44 *v41; // rax
  UFG::qVector4 v42; // xmm2
  UFG::qVector4 v43; // xmm1
  UFG::qVector4 v44; // xmm0
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C8h]
  UFG::qMatrix44 result; // [rsp+70h] [rbp-88h]
  float v47; // [rsp+B0h] [rbp-48h]
  float v48; // [rsp+B8h] [rbp-40h]
  float v49; // [rsp+BCh] [rbp-3Ch]
  float v50; // [rsp+C0h] [rbp-38h]
  float v51; // [rsp+C8h] [rbp-30h]
  float v52; // [rsp+CCh] [rbp-2Ch]
  float v53; // [rsp+D0h] [rbp-28h]
  hkQsTransformf v54; // [rsp+E8h] [rbp-10h]
  UFG::qMatrix44 matrixWS; // [rsp+118h] [rbp+20h]
  UFG::qMatrix44 sourceA; // [rsp+158h] [rbp+60h]
  UFG::qMatrix44 d; // [rsp+198h] [rbp+A0h]
  UFG::qMatrix44 v58; // [rsp+1D8h] [rbp+E0h]
  UFG::qMatrix44 dest; // [rsp+218h] [rbp+120h]
  UFG::qMatrix44 v60; // [rsp+258h] [rbp+160h]

  v2 = this;
  v3 = pose;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  v4 = *(float *)&FLOAT_1_0;
  v5 = (float)(sinf((float)(v2->mWeight * 3.1415927) - 1.5707964) + 1.0) * 0.5;
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
  v6 = v2->mJointID;
  v7 = v3->mHavokPose;
  v8 = (hkQuaternionf *)&v7->m_skeleton->m_referencePose.m_data[v6];
  v54.m_translation = (hkVector4f)v8->m_vec.m_quad;
  v54.m_rotation = (hkQuaternionf)v8[1].m_vec.m_quad;
  v54.m_scale = (hkVector4f)v8[2].m_vec.m_quad;
  SkeletalPose::GetPositionWS(v3, v7->m_skeleton->m_parentIndices.m_data[v6], &matrixWS);
  hkQsTransformf::get4x4ColumnMajor(&v54, &d.v0.x);
  UFG::qMatrix44::operator*(&d, &result, &matrixWS);
  m.v0 = result.v0;
  m.v1 = *(UFG::qVector4 *)&result.v0.z;
  m.v2 = *(UFG::qVector4 *)&result.v1.z;
  m.v3 = *(UFG::qVector4 *)&result.v2.z;
  UFG::qTranspose((UFG::qMatrix44 *)((char *)&result + 56), &m);
  v10 = (__m128)LODWORD(v2->mTargetPointWS.y);
  v9 = v2->mTargetPointWS.x - m.v3.x;
  v10.m128_f32[0] = v10.m128_f32[0] - m.v3.y;
  v12 = v10;
  v11 = v2->mTargetPointWS.z - m.v3.z;
  v12.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9)) + (float)(v11 * v11);
  if ( v12.m128_f32[0] == 0.0 )
    v13 = 0.0;
  else
    v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
  v14 = v9 * v13;
  v15 = v10.m128_f32[0] * v13;
  v16 = v11 * v13;
  v18 = (__m128)LODWORD(v49);
  v19 = (__m128)LODWORD(v50);
  v17 = (float)((float)(v48 * v15) + (float)(result.v3.z * v14)) + (float)(v51 * v16);
  v18.m128_f32[0] = (float)((float)(v49 * v15) + (float)(result.v3.w * v14)) + (float)(v52 * v16);
  v19.m128_f32[0] = (float)((float)(v50 * v15) + (float)(v47 * v14)) + (float)(v53 * v16);
  if ( v2->mAimAxis.mValue == 2 )
  {
    v20 = v19;
    v20.m128_f32[0] = (float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v17 * v17);
    *(float *)&v21 = atan2f(v18.m128_f32[0], COERCE_FLOAT(_mm_sqrt_ps(v20)));
    v22 = 0.0;
    v23 = v21;
    v24 = _xmm[0];
    v25 = COERCE_UNSIGNED_INT(atan2f(v17, v19.m128_f32[0])) ^ _xmm[0];
  }
  else
  {
    v24 = _xmm[0];
    v23 = COERCE_UNSIGNED_INT(atan2f(v19.m128_f32[0], v18.m128_f32[0])) ^ _xmm[0];
    v18.m128_f32[0] = (float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(v19.m128_f32[0] * v19.m128_f32[0]);
    *(float *)&v25 = 0.0;
    v22 = atan2f(v17, COERCE_FLOAT(_mm_sqrt_ps(v18)));
  }
  if ( *(float *)&v23 <= COERCE_FLOAT(LODWORD(v2->mXJointLimitMag) ^ v24) )
    v23 = LODWORD(v2->mXJointLimitMag) ^ v24;
  if ( *(float *)&v23 >= v2->mXJointLimitMag )
    v23 = LODWORD(v2->mXJointLimitMag);
  if ( v22 <= COERCE_FLOAT(LODWORD(v2->mZJointLimitMag) ^ v24) )
    LODWORD(v22) = LODWORD(v2->mZJointLimitMag) ^ v24;
  if ( v22 >= v2->mZJointLimitMag )
    v22 = v2->mZJointLimitMag;
  if ( *(float *)&v25 <= COERCE_FLOAT(LODWORD(v2->mYJointLimitMag) ^ v24) )
    v25 = LODWORD(v2->mYJointLimitMag) ^ v24;
  if ( *(float *)&v25 >= v2->mYJointLimitMag )
    v25 = LODWORD(v2->mYJointLimitMag);
  v26 = v2->mTrackingGain;
  rotY = (float)((float)(*(float *)&v25 - v2->mRotationY) * v26) + v2->mRotationY;
  v28 = (float)((float)(*(float *)&v23 - v2->mRotationX) * v26) + v2->mRotationX;
  v29 = (float)((float)(v22 - v2->mRotationZ) * v26) + v2->mRotationZ;
  v2->mRotationY = rotY;
  v2->mRotationX = v28;
  v2->mRotationZ = v29;
  AimConstraint::applyRotationXZY(v2, &m, v28, v29, rotY);
  if ( sUntwist && v2->mAimAxis.mValue != 2 )
  {
    v30 = 1.0 - (float)(m.v1.z * m.v1.z);
    LODWORD(v31) = COERCE_UNSIGNED_INT(m.v1.z * m.v1.x) ^ v24;
    LODWORD(v32) = COERCE_UNSIGNED_INT(m.v1.z * m.v1.y) ^ v24;
    v33 = (float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v30 * v30);
    if ( v33 == 0.0 )
      v34 = 0.0;
    else
      v34 = 1.0 / fsqrt(v33);
    v35 = v32 * v34;
    v36 = v30 * v34;
    v37 = v31 * v34;
    if ( (float)((float)((float)((float)((float)(m.v0.x * v36) - (float)(m.v0.z * v37)) * m.v1.y)
                       + (float)((float)((float)(m.v0.z * v35) - (float)(m.v0.y * v36)) * m.v1.x))
               + (float)((float)((float)(m.v0.y * v37) - (float)(m.v0.x * v35)) * m.v1.z)) > 0.0 )
      v4 = FLOAT_N1_0;
    v38 = (float)((float)(m.v0.y * v35) + (float)(m.v0.x * v37)) + (float)(m.v0.z * v36);
    UFG::qACos(v38);
    *(float *)&v39 = v38 * v4;
    if ( (float)(v38 * v4) <= COERCE_FLOAT(LODWORD(v2->mYJointLimitMag) ^ v24) )
      v39 = LODWORD(v2->mYJointLimitMag) ^ v24;
    if ( *(float *)&v39 >= v2->mYJointLimitMag )
      v39 = SLODWORD(v2->mYJointLimitMag);
    v40 = (float)((float)(*(float *)&v39 - v2->mRotationY) * v2->mTrackingGain) + v2->mRotationY;
    v2->mRotationY = v40;
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
  SkeletalPose::GetPositionWS(v3, v2->mJointID, &sourceA);
  BlendSlerp(&v58, &sourceA, &m, v5);
  SkeletalPose::SetPositionWS(v3, v2->mJointID, &v58);
}

// File Line: 390
// RVA: 0x3B6400
void __fastcall AimConstraint::applyRotationXZY(AimConstraint *this, UFG::qMatrix44 *targetmatrix, float rotX, float rotZ, float rotY)
{
  float v5; // xmm1_4
  float v6; // xmm4_4
  UFG::qMatrix44 *v7; // rsi
  float v8; // xmm8_4
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm9_4
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
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-C8h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-88h]

  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  v7 = targetmatrix;
  v8 = targetmatrix->v3.y;
  v9 = targetmatrix->v3.z;
  v10 = rotZ;
  v11 = targetmatrix->v3.x;
  targetmatrix->v3.x = UFG::qVector3::msZero.x;
  targetmatrix->v3.y = v5;
  targetmatrix->v3.w = 1.0;
  targetmatrix->v3.z = v6;
  UFG::qRotationMatrixAxis(&dest, (UFG::qVector3 *)targetmatrix, rotX);
  v12 = UFG::qMatrix44::operator*(v7, &result, &dest);
  v13 = v12->v1;
  v14 = v12->v2;
  v15 = v12->v3;
  v7->v0 = v12->v0;
  v7->v1 = v13;
  v7->v2 = v14;
  v7->v3 = v15;
  UFG::qRotationMatrixAxis(&dest, (UFG::qVector3 *)&v7->v2, v10);
  v16 = UFG::qMatrix44::operator*(v7, &result, &dest);
  v17 = v16->v2;
  v18 = v16->v1;
  v19 = v16->v3;
  v7->v0 = v16->v0;
  v7->v1 = v18;
  v7->v2 = v17;
  v7->v3 = v19;
  UFG::qRotationMatrixAxis(&dest, (UFG::qVector3 *)&v7->v1, rotY);
  v20 = UFG::qMatrix44::operator*(v7, &result, &dest);
  v21 = v20->v1;
  v22 = v20->v2;
  v23 = v20->v3;
  v7->v0 = v20->v0;
  v7->v1 = v21;
  v7->v2 = v22;
  v7->v3 = v23;
  v7->v3.x = v11;
  v7->v3.w = 1.0;
  v7->v3.y = v8;
  v7->v3.z = v9;
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimConstraint2::`vftable';
  this->mEffectorJoint = UFG::gNullQSymbolUC;
  this->mTargetJoint = UFG::gNullQSymbolUC;
  *(_QWORD *)&this->mJointID = -1i64;
}

// File Line: 514
// RVA: 0x3B1660
void __fastcall AimConstraint2::UpdatePose(AimConstraint2 *this, SkeletalPose *pose)
{
  SkeletalPose *v2; // rsi
  AimConstraint2 *v3; // rdi
  bool v4; // sf
  int v5; // edx
  hkQsTransformf *v6; // rbx
  __int64 v7; // kr00_8
  unsigned int v8; // xmm11_4
  float v9; // xmm3_4
  __m128 v10; // xmm4
  float v11; // xmm5_4
  __m128 v12; // xmm2
  float v13; // xmm1_4
  __m128 v14; // xmm6
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm8_4
  float v19; // xmm7_4
  float v20; // xmm0_4
  UFG::qMatrix44 *v21; // rax
  UFG::qVector4 v22; // xmm4
  __int128 v23; // xmm3
  __int128 v24; // xmm2
  float v25; // xmm0_4
  UFG::qMatrix44 *v26; // rax
  __int128 v27; // xmm2
  __int128 v28; // xmm1
  UFG::qVector4 v29; // xmm0
  int v30; // edx
  float p[4]; // [rsp+20h] [rbp-D8h]
  UFG::qVector4 v32; // [rsp+30h] [rbp-C8h]
  __int128 v33; // [rsp+40h] [rbp-B8h]
  __int128 v34; // [rsp+50h] [rbp-A8h]
  UFG::qMatrix44 b; // [rsp+60h] [rbp-98h]
  UFG::qVector4 v36; // [rsp+A8h] [rbp-50h]
  __int128 v37; // [rsp+B8h] [rbp-40h]
  __int128 v38; // [rsp+C8h] [rbp-30h]
  UFG::qMatrix44 dest; // [rsp+D8h] [rbp-20h]
  UFG::qMatrix44 v40; // [rsp+118h] [rbp+20h]
  hkQsTransformf v41; // [rsp+158h] [rbp+60h]
  UFG::qMatrix44 result; // [rsp+188h] [rbp+90h]

  v2 = pose;
  v3 = this;
  if ( !gDisablePoseDrivers )
  {
    v4 = this->mJointID < 0;
    this->mActive = 1;
    if ( !v4 )
    {
      v5 = this->mTargetJointID;
      if ( v5 >= 0 )
      {
        v6 = SkeletalPose::GetTranslationMS(v2, v5);
        SkeletalPose::GetPositionMS(v2, v3->mJointID, (UFG::qMatrix44 *)((char *)&b + 56));
        UFG::qTranspose(&dest, (UFG::qMatrix44 *)((char *)&b + 56));
        v10 = (__m128)v6->m_translation.m_quad.m128_u32[1];
        v7 = v38;
        v8 = DWORD2(v38);
        v9 = v6->m_translation.m_quad.m128_f32[0] - *(float *)&v38;
        v10.m128_f32[0] = v10.m128_f32[0] - *((float *)&v38 + 1);
        v11 = v6->m_translation.m_quad.m128_f32[2] - *((float *)&v38 + 2);
        v12 = v10;
        v12.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9)) + (float)(v11 * v11);
        if ( v12.m128_f32[0] == 0.0 )
          v13 = 0.0;
        else
          v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
        v14 = (__m128)LODWORD(dest.v1.z);
        v15 = v9 * v13;
        v16 = v10.m128_f32[0] * v13;
        v17 = v11 * v13;
        v34 = v38;
        v18 = (float)((float)(dest.v1.x * v16) + (float)(dest.v0.x * v15)) + (float)(dest.v2.x * v17);
        v19 = (float)((float)(dest.v1.y * v16) + (float)(dest.v0.y * v15)) + (float)(dest.v2.y * v17);
        *(_OWORD *)p = *(_OWORD *)&b.v3.z;
        v32 = v36;
        v14.m128_f32[0] = (float)((float)(dest.v1.z * v16) + (float)(dest.v0.z * v15)) + (float)(dest.v2.z * v17);
        v33 = v37;
        v20 = atan2f(v14.m128_f32[0], v18);
        UFG::qRotationMatrixY(&v40, COERCE_FLOAT(LODWORD(v20) ^ _xmm[0]));
        b.v0 = *(UFG::qVector4 *)p;
        b.v1 = v32;
        *(_OWORD *)&b.v1.z = v33;
        *(_OWORD *)&b.v2.z = v34;
        v21 = UFG::qMatrix44::operator*(&v40, &result, &b);
        v14.m128_f32[0] = (float)(v14.m128_f32[0] * v14.m128_f32[0]) + (float)(v18 * v18);
        v22 = v21->v1;
        v23 = (__int128)v21->v2;
        v24 = (__int128)v21->v3;
        *(UFG::qVector4 *)p = v21->v0;
        v32 = v22;
        v33 = v23;
        v34 = v24;
        v25 = atan2f(v19, COERCE_FLOAT(_mm_sqrt_ps(v14)));
        UFG::qRotationMatrixZ(&v40, v25);
        b.v0 = *(UFG::qVector4 *)p;
        b.v1 = v32;
        *(_OWORD *)&b.v1.z = v23;
        *(_OWORD *)&b.v2.z = v24;
        v26 = UFG::qMatrix44::operator*(&v40, &result, &b);
        v27 = (__int128)v26->v2;
        v28 = (__int128)v26->v3;
        v29 = v26->v0;
        v32 = v26->v1;
        v33 = v27;
        *(UFG::qVector4 *)p = v29;
        v34 = v28;
        hkQsTransformf::set4x4ColumnMajor(&v41, p);
        hkQsTransformf::get4x4ColumnMajor(&v41, p);
        v30 = v3->mJointID;
        *(_QWORD *)&v34 = v7;
        *((_QWORD *)&v34 + 1) = __PAIR__(1065353216, v8);
        SkeletalPose::SetPositionMS(v2, v30, (UFG::qMatrix44 *)p);
      }
    }
  }
}

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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax
  float v2; // xmm1_4
  float v3; // xmm2_4

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimConstraintMultiLink::`vftable';
  this->mFirstJoint = UFG::gNullQSymbolUC;
  this->mSecondJoint = UFG::gNullQSymbolUC;
  this->mThirdJoint = UFG::gNullQSymbolUC;
  this->mEndJoint = UFG::gNullQSymbolUC;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->mTargetPointWS.x = UFG::qVector3::msZero.x;
  this->mTargetPointWS.y = v2;
  this->mTargetPointWS.z = v3;
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
char __fastcall AimConstraintMultiLink::Update(AimConstraintMultiLink *this, float timeDelta)
{
  bool v2; // zf
  char result; // al
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
void __fastcall AimConstraintMultiLink::getTargetRotations(AimConstraintMultiLink *this, SkeletalPose *pose, float *rotX, float *rotY, float *rotZ)
{
  AimConstraintMultiLink *v5; // rbx
  float *v6; // rdi
  float *v7; // rsi
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm8_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  __m128 v15; // xmm7
  float v16; // xmm8_4
  float v17; // xmm8_4
  __m128 v18; // xmm3
  float v19; // xmm6_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-B8h]
  UFG::qMatrix44 matrixRoot; // [rsp+60h] [rbp-78h]

  v5 = this;
  v6 = rotY;
  v7 = rotX;
  SkeletalPose::GetRootMatrix(pose, &matrixRoot);
  UFG::qInverseAffine(&d, &matrixRoot);
  v8 = v5->mTargetPointWS.x;
  v9 = v5->mTargetPointWS.y;
  v10 = v5->mTargetPointWS.z;
  v15 = (__m128)LODWORD(d.v1.y);
  v11 = (float)(d.v1.x * v9) + (float)(d.v0.x * v8);
  v15.m128_f32[0] = d.v1.y * v9;
  v12 = d.v1.z * v9;
  v13 = 0.0;
  v14 = (float)(v11 + (float)(d.v2.x * v10)) + d.v3.x;
  v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] + (float)(d.v0.y * v8)) + (float)(d.v2.y * v10)) + d.v3.y;
  v16 = (float)(v12 + (float)(d.v0.z * v8)) + (float)(d.v2.z * v10);
  v18 = v15;
  v17 = v16 + d.v3.z;
  v18.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v17 * v17);
  if ( v18.m128_f32[0] != 0.0 )
    v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
  v15.m128_f32[0] = v15.m128_f32[0] * v13;
  v19 = v13 * v14;
  *rotZ = atan2f(v15.m128_f32[0], v13 * v14);
  v15.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v19 * v19);
  *(_DWORD *)v7 = COERCE_UNSIGNED_INT(atan2f(v17 * v13, COERCE_FLOAT(_mm_sqrt_ps(v15)))) ^ _xmm[0];
  *v6 = 0.0;
}

// File Line: 787
// RVA: 0x3B1F80
void __fastcall AimConstraintMultiLink::UpdatePose(AimConstraintMultiLink *this, SkeletalPose *pose)
{
  SkeletalPose *v2; // r15
  AimConstraintMultiLink *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm8_4
  int v6; // er14
  float v7; // xmm9_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm7_4
  float v11; // xmm5_4
  float v12; // xmm7_4
  float v13; // xmm4_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm6_4
  float v18; // xmm3_4
  float v19; // xmm6_4
  int i; // esi
  int v21; // edi
  int j; // esi
  int v23; // edi
  float rotY; // [rsp+30h] [rbp-A8h]
  UFG::qColour v25; // [rsp+40h] [rbp-98h]
  __m128 v26; // [rsp+50h] [rbp-88h]
  UFG::qMatrix44 matrixMS; // [rsp+60h] [rbp-78h]
  __m128 v28; // [rsp+A8h] [rbp-30h]
  __int64 v29; // [rsp+B8h] [rbp-20h]
  UFG::qMatrix44 dest; // [rsp+C8h] [rbp-10h]
  UFG::qMatrix44 v31; // [rsp+108h] [rbp+30h]
  UFG::qMatrix44 v32; // [rsp+148h] [rbp+70h]
  float rotX; // [rsp+268h] [rbp+190h]
  float rotZ; // [rsp+270h] [rbp+198h]

  v29 = -2i64;
  v2 = pose;
  v3 = this;
  if ( sDisableAimConstraintMultiLink != 1 && this->mUpdated != 1 )
  {
    v4 = this->mWeight;
    if ( v4 > 0.0 || sForceActive )
    {
      v5 = EaseInOut(v4);
      v3->mUpdated = 1;
      v6 = v3->mJointCount;
      v7 = (float)v3->mJointCount;
      if ( v6 > 0 )
      {
        rotZ = 0.0;
        rotX = 0.0;
        rotY = 0.0;
        AimConstraintMultiLink::getTargetRotations(v3, v2, &rotX, &rotY, &rotZ);
        v8 = rotX;
        if ( rotX <= v3->mXJointLimitMinMag )
          v8 = v3->mXJointLimitMinMag;
        if ( v8 >= v3->mXJointLimitMaxMag )
          v8 = v3->mXJointLimitMaxMag;
        v9 = rotZ;
        if ( rotZ <= v3->mZJointLimitMinMag )
          v9 = v3->mZJointLimitMinMag;
        if ( v9 >= v3->mZJointLimitMaxMag )
          v9 = v3->mZJointLimitMaxMag;
        v10 = rotY;
        if ( rotY <= v3->mYJointLimitMinMag )
          v10 = v3->mYJointLimitMinMag;
        if ( v10 >= v3->mYJointLimitMaxMag )
          v10 = v3->mYJointLimitMaxMag;
        v11 = v9 - v3->mRotationZ;
        v12 = v10 - v3->mRotationY;
        v13 = v3->mTrackingGain;
        v14 = (float)(v3->mTrackingGain * (float)(v8 - v3->mRotationX)) + v3->mRotationX;
        v3->mRotationX = v14;
        v15 = (float)(v13 * v11) + v3->mRotationZ;
        v3->mRotationZ = v15;
        v16 = (float)(v13 * v12) + v3->mRotationY;
        v3->mRotationY = v16;
        if ( v14 <= v3->mXJointLimitMinMag )
          v14 = v3->mXJointLimitMinMag;
        if ( v14 >= v3->mXJointLimitMaxMag )
          v14 = v3->mXJointLimitMaxMag;
        v3->mRotationX = v14;
        if ( v15 <= v3->mZJointLimitMinMag )
          v15 = v3->mZJointLimitMinMag;
        if ( v15 >= v3->mZJointLimitMaxMag )
          v15 = v3->mZJointLimitMaxMag;
        v3->mRotationZ = v15;
        if ( v16 <= v3->mYJointLimitMinMag )
          v16 = v3->mYJointLimitMinMag;
        if ( v16 >= v3->mYJointLimitMaxMag )
          v16 = v3->mYJointLimitMaxMag;
        v17 = v14 * v5;
        v3->mRotationX = v17;
        v18 = v15 * v5;
        v3->mRotationZ = v18;
        v3->mRotationY = v16 * v5;
        rotX = v18 * (float)(1.0 / v7);
        v19 = v17 * (float)(1.0 / v7);
        if ( !(_S8_8 & 1) )
        {
          _S8_8 |= 1u;
          beforeColor = UFG::qColour::Lime;
        }
        if ( gDrawSkeletonBoneNormalityInfo )
        {
          v25 = beforeColor;
          SkeletalPose::DebugDraw(v2, &v25, 1.0);
        }
        UFG::qRotationMatrixY(&dest, v19);
        if ( sEnableBend )
        {
          for ( i = 0; i < v6; ++i )
          {
            if ( i )
            {
              switch ( i )
              {
                case 1:
                  v21 = v3->mSecondJointID;
                  break;
                case 2:
                  v21 = v3->mThirdJointID;
                  break;
                case 3:
                  v21 = v3->mEndJointID;
                  break;
                default:
                  v21 = 0;
                  break;
              }
            }
            else
            {
              v21 = v3->mFirstJointID;
            }
            SkeletalPose::GetPositionMS_ReNormalize(v2, v21, (UFG::qMatrix44 *)((char *)&matrixMS + 24));
            v25 = (UFG::qColour)v28;
            v26 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&matrixMS.v1.z, *(__m128 *)&matrixMS.v1.z, 0), (__m128)dest.v0);
            matrixMS.v1 = (UFG::qVector4)_mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_shuffle_ps(
                                                   *(__m128 *)&matrixMS.v2.z,
                                                   *(__m128 *)&matrixMS.v2.z,
                                                   85),
                                                 (__m128)dest.v1),
                                               _mm_add_ps(
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     *(__m128 *)&matrixMS.v2.z,
                                                     *(__m128 *)&matrixMS.v2.z,
                                                     0),
                                                   (__m128)dest.v0),
                                                 (__m128)0i64)),
                                             _mm_mul_ps(
                                               _mm_shuffle_ps(*(__m128 *)&matrixMS.v2.z, *(__m128 *)&matrixMS.v2.z, 170),
                                               (__m128)dest.v2)),
                                           _mm_mul_ps(
                                             _mm_shuffle_ps(*(__m128 *)&matrixMS.v2.z, *(__m128 *)&matrixMS.v2.z, 255),
                                             (__m128)dest.v3));
            *(__m128 *)((char *)&v26 + 8) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      _mm_shuffle_ps(
                                                        *(__m128 *)&matrixMS.v3.z,
                                                        *(__m128 *)&matrixMS.v3.z,
                                                        0),
                                                      (__m128)dest.v0),
                                                    (__m128)0i64),
                                                  _mm_mul_ps(
                                                    _mm_shuffle_ps(
                                                      *(__m128 *)&matrixMS.v3.z,
                                                      *(__m128 *)&matrixMS.v3.z,
                                                      85),
                                                    (__m128)dest.v1)),
                                                _mm_mul_ps(
                                                  _mm_shuffle_ps(
                                                    *(__m128 *)&matrixMS.v3.z,
                                                    *(__m128 *)&matrixMS.v3.z,
                                                    170),
                                                  (__m128)dest.v2)),
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(
                                                  *(__m128 *)&matrixMS.v3.z,
                                                  *(__m128 *)&matrixMS.v3.z,
                                                  255),
                                                (__m128)dest.v3));
            LODWORD(matrixMS.v0.z) = v28.m128_i32[0];
            LODWORD(matrixMS.v0.w) = (unsigned __int128)_mm_shuffle_ps(v28, v28, 85);
            LODWORD(matrixMS.v1.x) = (unsigned __int128)_mm_shuffle_ps(v28, v28, 170);
            matrixMS.v1.y = v28.m128_f32[3];
            SkeletalPose::SetPositionMS_ReNormalize(v2, v21, &matrixMS);
            SkeletalPose::GetPositionMS(v2, v21, &v32);
          }
        }
        UFG::qRotationMatrixZ(&v31, rotX);
        if ( sEnableTwist )
        {
          for ( j = 0; j < v6; ++j )
          {
            if ( j )
            {
              switch ( j )
              {
                case 1:
                  v23 = v3->mSecondJointID;
                  break;
                case 2:
                  v23 = v3->mThirdJointID;
                  break;
                case 3:
                  v23 = v3->mEndJointID;
                  break;
                default:
                  v23 = 0;
                  break;
              }
            }
            else
            {
              v23 = v3->mFirstJointID;
            }
            SkeletalPose::GetPositionMS_ReNormalize(v2, v23, (UFG::qMatrix44 *)((char *)&matrixMS + 24));
            v25 = (UFG::qColour)v28;
            v26 = _mm_mul_ps((__m128)v31.v0, _mm_shuffle_ps(v28, v28, 0));
            matrixMS.v1 = (UFG::qVector4)_mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 (__m128)v31.v1,
                                                 _mm_shuffle_ps(
                                                   *(__m128 *)&matrixMS.v2.z,
                                                   *(__m128 *)&matrixMS.v2.z,
                                                   85)),
                                               _mm_add_ps(
                                                 _mm_mul_ps(
                                                   (__m128)v31.v0,
                                                   _mm_shuffle_ps(
                                                     *(__m128 *)&matrixMS.v2.z,
                                                     *(__m128 *)&matrixMS.v2.z,
                                                     0)),
                                                 (__m128)0i64)),
                                             _mm_mul_ps(
                                               (__m128)v31.v2,
                                               _mm_shuffle_ps(*(__m128 *)&matrixMS.v2.z, *(__m128 *)&matrixMS.v2.z, 170))),
                                           _mm_mul_ps(
                                             (__m128)v31.v3,
                                             _mm_shuffle_ps(*(__m128 *)&matrixMS.v2.z, *(__m128 *)&matrixMS.v2.z, 255)));
            *(__m128 *)((char *)&v26 + 8) = _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_mul_ps(
                                                  (__m128)v31.v2,
                                                  _mm_shuffle_ps(
                                                    *(__m128 *)&matrixMS.v3.z,
                                                    *(__m128 *)&matrixMS.v3.z,
                                                    170)),
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_mul_ps(
                                                      (__m128)v31.v0,
                                                      _mm_shuffle_ps(
                                                        *(__m128 *)&matrixMS.v3.z,
                                                        *(__m128 *)&matrixMS.v3.z,
                                                        0)),
                                                    (__m128)0i64),
                                                  _mm_mul_ps(
                                                    (__m128)v31.v1,
                                                    _mm_shuffle_ps(
                                                      *(__m128 *)&matrixMS.v3.z,
                                                      *(__m128 *)&matrixMS.v3.z,
                                                      85)))),
                                              _mm_mul_ps(
                                                (__m128)v31.v3,
                                                _mm_shuffle_ps(
                                                  *(__m128 *)&matrixMS.v3.z,
                                                  *(__m128 *)&matrixMS.v3.z,
                                                  255)));
            LODWORD(matrixMS.v0.z) = v28.m128_i32[0];
            LODWORD(matrixMS.v0.w) = (unsigned __int128)_mm_shuffle_ps(v28, v28, 85);
            LODWORD(matrixMS.v1.x) = (unsigned __int128)_mm_shuffle_ps(v28, v28, 170);
            matrixMS.v1.y = v28.m128_f32[3];
            SkeletalPose::SetPositionMS_ReNormalize(v2, v23, &matrixMS);
            SkeletalPose::GetPositionMS(v2, v23, &v32);
          }
        }
        if ( !(_S8_8 & 2) )
        {
          _S8_8 |= 2u;
          afterColor = UFG::qColour::Pink;
        }
        if ( gDrawSkeletonBoneNormalityInfo )
        {
          v26 = (__m128)afterColor;
          SkeletalPose::DebugDraw(v2, (UFG::qColour *)&v26, 1.0);
        }
      }
    }
  }
}

// File Line: 983
// RVA: 0x3A1610
char __fastcall AimConstraintMultiLink::AddTo(AimConstraintMultiLink *this, Creature *creature)
{
  signed int v2; // esi
  Creature *v3; // rdi
  AimConstraintMultiLink *v4; // rbx
  signed int v5; // eax
  signed int v6; // eax
  signed int v7; // eax
  UFG::qNode<PoseDriver,PoseDriver> *v8; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v9; // rcx
  char result; // al

  this->mJointCount = 0;
  v2 = -1;
  v3 = creature;
  v4 = this;
  if ( creature->mPose.mRigHandle.mData )
    v5 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFirstJoint.mUID);
  else
    v5 = -1;
  v4->mFirstJointID = v5;
  if ( v5 >= 0 )
    ++v4->mJointCount;
  if ( v3->mPose.mRigHandle.mData )
    v6 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mSecondJoint.mUID);
  else
    v6 = -1;
  v4->mSecondJointID = v6;
  if ( v6 >= 0 )
    ++v4->mJointCount;
  if ( v3->mPose.mRigHandle.mData )
    v7 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mThirdJoint.mUID);
  else
    v7 = -1;
  v4->mThirdJointID = v7;
  if ( v7 >= 0 )
    ++v4->mJointCount;
  if ( v3->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mEndJoint.mUID);
  v4->mEndJointID = v2;
  if ( v2 >= 0 )
    ++v4->mJointCount;
  v8 = v3->mPoseDrivers.mNode.mPrev;
  v9 = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v8->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v9->mPrev = v8;
  v9->mNext = &v3->mPoseDrivers.mNode;
  result = 1;
  v3->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax
  UFG::qVector4 v2; // xmm3

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&TwoLinkIKsolver::`vftable';
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
  v2 = 0i64;
  v2.x = (float)1;
  this->mTargetMatrixWS.v0 = v2;
  this->mTargetMatrixWS.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 81);
  this->mTargetMatrixWS.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 69);
  this->mTargetMatrixWS.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v2, (__m128)v2, 21);
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
  float v2; // xmm1_4
  SkeletalPose *v3; // rbx
  TwoLinkIKsolver *v4; // rsi
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
  float p; // [rsp+20h] [rbp-E0h]
  float v20; // [rsp+24h] [rbp-DCh]
  float v21; // [rsp+28h] [rbp-D8h]
  float v22; // [rsp+2Ch] [rbp-D4h]
  float v23; // [rsp+30h] [rbp-D0h]
  float v24; // [rsp+34h] [rbp-CCh]
  float v25; // [rsp+38h] [rbp-C8h]
  float v26; // [rsp+3Ch] [rbp-C4h]
  float v27; // [rsp+40h] [rbp-C0h]
  float v28; // [rsp+44h] [rbp-BCh]
  float v29; // [rsp+48h] [rbp-B8h]
  float v30; // [rsp+4Ch] [rbp-B4h]
  float v31; // [rsp+50h] [rbp-B0h]
  float v32; // [rsp+54h] [rbp-ACh]
  float v33; // [rsp+58h] [rbp-A8h]
  float v34; // [rsp+5Ch] [rbp-A4h]
  hkTransformf transform; // [rsp+60h] [rbp-A0h]
  hkQsTransformf v36; // [rsp+A0h] [rbp-60h]
  UFG::qMatrix44 matrixRoot; // [rsp+D0h] [rbp-30h]
  UFG::qMatrix44 d; // [rsp+110h] [rbp+10h]
  UFG::qMatrix44 result; // [rsp+150h] [rbp+50h]

  v2 = this->mTargetMatrixWS.v0.y;
  v3 = pose;
  v4 = this;
  p = this->mTargetMatrixWS.v0.x;
  v5 = this->mTargetMatrixWS.v0.z;
  v20 = v2;
  v6 = this->mTargetMatrixWS.v0.w;
  v21 = v5;
  v7 = this->mTargetMatrixWS.v1.x;
  v22 = v6;
  v8 = this->mTargetMatrixWS.v1.y;
  v23 = v7;
  v9 = this->mTargetMatrixWS.v1.z;
  v24 = v8;
  v10 = this->mTargetMatrixWS.v1.w;
  v25 = v9;
  v11 = this->mTargetMatrixWS.v2.x;
  v26 = v10;
  v12 = this->mTargetMatrixWS.v2.y;
  v27 = v11;
  v13 = this->mTargetMatrixWS.v2.z;
  v28 = v12;
  v14 = this->mTargetMatrixWS.v2.w;
  v29 = v13;
  v15 = this->mTargetMatrixWS.v3.x;
  v30 = v14;
  v16 = this->mTargetMatrixWS.v3.y;
  v31 = v15;
  v17 = this->mTargetMatrixWS.v3.z;
  v32 = v16;
  v18 = this->mTargetMatrixWS.v3.w;
  v33 = v17;
  v34 = v18;
  hkTransformf::set4x4ColumnMajor(&transform, &p);
  hkQsTransformf::setFromTransformNoScale(&v4->mHkTargetMatrixWS, &transform);
  SkeletalPose::GetRootMatrix(v3, &matrixRoot);
  UFG::qInverseAffine(&d, &matrixRoot);
  UFG::qMatrix44::operator*(&v4->mTargetMatrixWS, &result, &d);
  hkTransformf::set4x4ColumnMajor(&transform, &result.v0.x);
  hkQsTransformf::setFromTransformNoScale(&v36, &transform);
  v4->mLinkInfo.m_endTargetMS = v36.m_translation;
}

// File Line: 1275
// RVA: 0x3B7410
void __fastcall getRelativeDifferenceInPose(UFG::qMatrix44 *difference, SkeletalPose *pose, int baseRefFrameID, int inputFrameID)
{
  SkeletalPose *v4; // rbx
  UFG::qMatrix44 *v5; // rsi
  int v6; // edi
  UFG::qVector4 v7; // xmm9
  UFG::qVector4 v8; // xmm11
  UFG::qVector4 v9; // xmm12
  UFG::qVector4 v10; // xmm13
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm4
  UFG::qVector4 v14; // xmm0
  UFG::qMatrix44 d; // [rsp+20h] [rbp-148h]
  UFG::qMatrix44 v16; // [rsp+60h] [rbp-108h]
  UFG::qMatrix44 matrixMS; // [rsp+A0h] [rbp-C8h]

  v4 = pose;
  v5 = difference;
  v6 = inputFrameID;
  SkeletalPose::GetPositionMS(pose, baseRefFrameID, &matrixMS);
  SkeletalPose::GetPositionMS(v4, v6, &v16);
  UFG::qInverseAffine(&d, &matrixMS);
  v7 = d.v1;
  v8 = d.v2;
  v9 = d.v3;
  v10 = v16.v3;
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v16.v1, (__m128)v16.v1, 0), (__m128)d.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v1, (__m128)v16.v1, 85), (__m128)d.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v1, (__m128)v16.v1, 170), (__m128)d.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v1, (__m128)v16.v1, 255), (__m128)d.v3));
  v12 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v16.v3, (__m128)v16.v3, 0), (__m128)d.v0), (__m128)0i64);
  v13 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v16.v2, (__m128)v16.v2, 0), (__m128)d.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v2, (__m128)v16.v2, 85), (__m128)d.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v2, (__m128)v16.v2, 170), (__m128)d.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v2, (__m128)v16.v2, 255), (__m128)d.v3));
  v14 = v16.v3;
  v5->v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v0, (__m128)v16.v0, 0), (__m128)d.v0),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v0, (__m128)v16.v0, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v0, (__m128)v16.v0, 170), (__m128)d.v2)),
                            _mm_mul_ps(_mm_shuffle_ps((__m128)v16.v0, (__m128)v16.v0, 255), (__m128)d.v3));
  v5->v1 = (UFG::qVector4)v11;
  v5->v2 = (UFG::qVector4)v13;
  v5->v3 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(v12, _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v14, 85), (__m128)v7)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)v14, (__m128)v10, 170), (__m128)v8)),
                            _mm_mul_ps(_mm_shuffle_ps((__m128)v10, (__m128)v10, 255), (__m128)v9));
}

// File Line: 1297
// RVA: 0x3B3BE0
void __fastcall TwoLinkIKsolver::UpdatePose(TwoLinkIKsolver *this, SkeletalPose *pose)
{
  SkeletalPose *v2; // r14
  TwoLinkIKsolver *v3; // rsi
  signed __int16 v4; // bx
  hkaSkeleton *v5; // rdx
  signed __int16 v6; // di
  __int64 v7; // r8
  __int16 *v8; // r9
  int v9; // er10
  __int16 v10; // r15
  __int64 v11; // r11
  __int16 v12; // r12
  int v13; // ecx
  __int16 v14; // dx
  int v15; // edx
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  UFG::qMatrix44 difference; // [rsp+20h] [rbp-C8h]
  char translationWS[24]; // [rsp+60h] [rbp-88h]
  __m128 v29; // [rsp+78h] [rbp-70h]
  __m128 v30; // [rsp+88h] [rbp-60h]
  __m128 v31; // [rsp+98h] [rbp-50h]
  __m128 v32; // [rsp+A8h] [rbp-40h]
  __m128 v33; // [rsp+B8h] [rbp-30h]
  __m128 v34; // [rsp+C8h] [rbp-20h]
  UFG::qMatrix44 v35; // [rsp+D8h] [rbp-10h]
  hkBool result; // [rsp+1A8h] [rbp+C0h]

  v2 = pose;
  v3 = this;
  if ( this->mActive )
  {
    v4 = -1;
    v5 = pose->mHavokPose->m_skeleton;
    v6 = -1;
    if ( this->mFixSiblingTwist )
    {
      if ( v5 )
      {
        v7 = this->mLinkInfo.m_firstJointIdx;
        v8 = v5->m_parentIndices.m_data;
        v9 = v5->m_parentIndices.m_size;
        v10 = v8[v7];
        v11 = this->mLinkInfo.m_secondJointIdx;
        v12 = v8[v11];
        v13 = 0;
        if ( v9 > 0 )
        {
          LODWORD(v7) = (signed __int16)v7;
          LODWORD(v11) = (signed __int16)v11;
          do
          {
            v14 = v8[v13];
            if ( (_DWORD)v7 != v13 && v4 == -1 && v14 == v10 )
              v4 = v13;
            if ( (_DWORD)v11 != v13 && v6 == -1 && v14 == v12 )
              v6 = v13;
            if ( v4 != -1 && v6 != -1 )
              break;
            ++v13;
          }
          while ( v13 < v9 );
          if ( v4 != -1 )
            getRelativeDifferenceInPose(&difference, v2, v7, v4);
          if ( v6 != -1 )
            getRelativeDifferenceInPose(&v35, v2, v3->mLinkInfo.m_secondJointIdx, v6);
        }
      }
    }
    hkaTwoJointsIkSolver::solve(&result, &v3->mLinkInfo, v2->mHavokPose);
    if ( v4 != -1 )
    {
      SkeletalPose::GetPositionMS(v2, v3->mLinkInfo.m_firstJointIdx, (UFG::qMatrix44 *)&translationWS[16]);
      v31 = _mm_add_ps(
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
                _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v0, (__m128)difference.v0, 170), v29)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v0, (__m128)difference.v0, 255), v30));
      v32 = _mm_add_ps(
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
                _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v1, (__m128)difference.v1, 170), v29)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v1, (__m128)difference.v1, 255), v30));
      v33 = _mm_add_ps(
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
                _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v2, (__m128)difference.v2, 170), v29)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v2, (__m128)difference.v2, 255), v30));
      v34 = _mm_add_ps(
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
                _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v3, (__m128)difference.v3, 170), v29)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)difference.v3, (__m128)difference.v3, 255), v30));
      SkeletalPose::SetPositionMS(v2, v4, (UFG::qMatrix44 *)&v31);
    }
    if ( v6 != -1 )
    {
      SkeletalPose::GetPositionMS(v2, v3->mLinkInfo.m_secondJointIdx, (UFG::qMatrix44 *)&v31);
      *(__m128 *)&translationWS[8] = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v1, (__m128)v35.v1, 0), v31),
                                             (__m128)0i64),
                                           _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v1, (__m128)v35.v1, 85), v32)),
                                         _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v1, (__m128)v35.v1, 170), v33)),
                                       _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v1, (__m128)v35.v1, 255), v34));
      v29 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v35.v2, (__m128)v35.v2, 0), v31), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v2, (__m128)v35.v2, 85), v32)),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v2, (__m128)v35.v2, 170), v33)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v2, (__m128)v35.v2, 255), v34));
      v30 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v35.v3, (__m128)v35.v3, 0), v31), (__m128)0i64),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v3, (__m128)v35.v3, 85), v32)),
                _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v3, (__m128)v35.v3, 170), v33)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)v35.v3, (__m128)v35.v3, 255), v34));
      SkeletalPose::SetPositionMS(v2, v6, (UFG::qMatrix44 *)&translationWS[16]);
    }
    SkeletalPose::GetTranslationWS(v2, v3->mLinkInfo.m_endBoneIdx, (UFG::qVector3 *)translationWS);
    v15 = v3->mLinkInfo.m_endBoneIdx;
    v16 = v3->mTargetMatrixWS.v0.y;
    difference.v0.x = v3->mTargetMatrixWS.v0.x;
    v17 = v3->mTargetMatrixWS.v0.z;
    difference.v0.y = v16;
    v18 = v3->mTargetMatrixWS.v0.w;
    difference.v0.z = v17;
    v19 = v3->mTargetMatrixWS.v1.x;
    difference.v0.w = v18;
    v20 = v3->mTargetMatrixWS.v1.y;
    difference.v1.x = v19;
    v21 = v3->mTargetMatrixWS.v1.z;
    difference.v1.y = v20;
    v22 = v3->mTargetMatrixWS.v1.w;
    difference.v1.z = v21;
    v23 = v3->mTargetMatrixWS.v2.x;
    difference.v1.w = v22;
    v24 = v3->mTargetMatrixWS.v2.y;
    difference.v2.x = v23;
    v25 = v3->mTargetMatrixWS.v2.z;
    difference.v2.y = v24;
    v26 = v3->mTargetMatrixWS.v2.w;
    difference.v2.z = v25;
    difference.v2.w = v26;
    difference.v3.x = *(float *)translationWS;
    difference.v3.y = *(float *)&translationWS[4];
    difference.v3.z = *(float *)&translationWS[8];
    LODWORD(difference.v3.w) = (_DWORD)FLOAT_1_0;
    SkeletalPose::SetPositionWS(v2, v15, &difference);
  }
} *(float *)&translatio

// File Line: 1464
// RVA: 0x3A1910
char __fastcall RootUprightDriver::AddTo(RootUprightDriver *this, Creature *creature)
{
  UFG::qNode<PoseDriver,PoseDriver> *v2; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v3; // rcx
  UFG::qList<PoseDriver,PoseDriver,1,0> *v4; // rdx

  v2 = creature->mPoseDrivers.mNode.mPrev;
  v3 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v4 = &creature->mPoseDrivers;
  v2->mNext = v3;
  v3->mPrev = v2;
  v3->mNext = &v4->mNode;
  v4->mNode.mPrev = v3;
  return 1;
}

// File Line: 1470
// RVA: 0x3A15A0
char __fastcall AimConstraint::AddTo(AimConstraint *this, Creature *creature)
{
  Creature *v2; // rbx
  AimConstraint *v3; // rdi
  int v4; // eax
  UFG::qNode<PoseDriver,PoseDriver> *v5; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v6; // rcx

  v2 = creature;
  v3 = this;
  if ( !creature->mPose.mRigHandle.mData )
    return 0;
  v4 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mEffectorJoint.mUID);
  if ( v4 == -1 )
    return 0;
  v3->mJointID = v4;
  v5 = v2->mPoseDrivers.mNode.mPrev;
  v6 = (UFG::qNode<PoseDriver,PoseDriver> *)&v3->mPrev;
  v5->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v3->mPrev;
  v6->mPrev = v5;
  v6->mNext = &v2->mPoseDrivers.mNode;
  v2->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v3->mPrev;
  return 1;
}

// File Line: 1483
// RVA: 0x3A1500
char __fastcall AimConstraint2::AddTo(AimConstraint2 *this, Creature *creature)
{
  signed int v2; // edi
  Creature *v3; // rbx
  AimConstraint2 *v4; // rsi
  signed int v5; // ebp
  UFG::qNode<PoseDriver,PoseDriver> *v6; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v7; // rcx

  v2 = -1;
  v3 = creature;
  v4 = this;
  if ( creature->mPose.mRigHandle.mData )
    v5 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mEffectorJoint.mUID);
  else
    v5 = -1;
  if ( v3->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mTargetJoint.mUID);
  if ( v5 == -1 || v2 == -1 )
    return 0;
  v4->mJointID = v5;
  v4->mTargetJointID = v2;
  v6 = v3->mPoseDrivers.mNode.mPrev;
  v7 = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v6->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v7->mPrev = v6;
  v7->mNext = &v3->mPoseDrivers.mNode;
  v3->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  return 1;
}

// File Line: 1499
// RVA: 0x3A1A90
char __fastcall TwoLinkIKsolver::AddTo(TwoLinkIKsolver *this, Creature *creature)
{
  signed int v2; // esi
  Creature *v3; // rbx
  TwoLinkIKsolver *v4; // rdi
  signed int v5; // er14
  signed int v6; // ebp
  UFG::qNode<PoseDriver,PoseDriver> *v7; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v8; // rcx

  v2 = -1;
  v3 = creature;
  v4 = this;
  if ( creature->mPose.mRigHandle.mData )
    v5 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFirstJoint.mUID);
  else
    v5 = -1;
  if ( v3->mPose.mRigHandle.mData )
    v6 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mSecondJoint.mUID);
  else
    v6 = -1;
  if ( v3->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mEndJoint.mUID);
  if ( v5 == -1 || v6 == -1 || v2 == -1 )
    return 0;
  v4->mLinkInfo.m_firstJointIdx = v5;
  v4->mLinkInfo.m_secondJointIdx = v6;
  v4->mLinkInfo.m_endBoneIdx = v2;
  v4->mLinkInfo.m_hingeAxisLS.m_quad.m128_i32[2] = 1065353216;
  v4->mCreature = v3;
  v7 = v3->mPoseDrivers.mNode.mPrev;
  v8 = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v7->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v8->mPrev = v7;
  v8->mNext = &v3->mPoseDrivers.mNode;
  v3->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  return 1;
}

// File Line: 1520
// RVA: 0x3A1880
char __fastcall OrientationConstraint::AddTo(OrientationConstraint *this, Creature *creature)
{
  OrientationConstraint *v2; // rdi
  Creature *v3; // rsi
  __int64 v4; // rbx
  signed __int64 v5; // r14
  signed __int64 v6; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *v7; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v8; // rcx

  v2 = this;
  v3 = creature;
  ((void (__fastcall *)(JointReferences *))this->mDriveJoint.vfptr[1].FindWithOldPath)(&this->mDriveJoint);
  v4 = 0i64;
  v5 = (signed __int64)&v2->mInputJoints.mData + v2->mInputJoints.mData.mOffset;
  if ( v2->mInputJoints.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = *(_QWORD *)(v5 + 8 * v4) + v5 + 8 * v4;
      (*(void (__fastcall **)(signed __int64, Creature *))(*(_QWORD *)v6 + 80i64))(v6, v3);
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < (v2->mInputJoints.mCount & 0x7FFFFFFFu) );
  }
  v7 = v3->mPoseDrivers.mNode.mPrev;
  v8 = (UFG::qNode<PoseDriver,PoseDriver> *)&v2->mPrev;
  v7->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v2->mPrev;
  v8->mPrev = v7;
  v8->mNext = &v3->mPoseDrivers.mNode;
  v3->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v2->mPrev;
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
  signed int v2; // esi
  Creature *v3; // rbx
  TwistXRotLinearLink *v4; // rdi
  signed int v5; // eax
  signed int v6; // eax
  UFG::qNode<PoseDriver,PoseDriver> *v7; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v8; // rcx

  v2 = -1;
  v3 = creature;
  v4 = this;
  if ( creature->mPose.mRigHandle.mData )
    v5 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mBaseJoint.mUID);
  else
    v5 = -1;
  v4->mBaseJointID = v5;
  if ( v3->mPose.mRigHandle.mData )
    v6 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mEndJoint.mUID);
  else
    v6 = -1;
  v4->mEndJointID = v6;
  if ( v3->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mDriveJoint.mUID);
  v4->mDriveJointID = v2;
  v7 = v3->mPoseDrivers.mNode.mPrev;
  v8 = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v7->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v8->mPrev = v7;
  v8->mNext = &v3->mPoseDrivers.mNode;
  v3->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  return 1;
}

// File Line: 1551
// RVA: 0x3A1790
char __fastcall FollowLink::AddTo(FollowLink *this, Creature *creature)
{
  int v2; // esi
  Creature *v3; // rdi
  FollowLink *v4; // rbx
  signed int v5; // eax
  int v6; // edx
  UFG::qNode<PoseDriver,PoseDriver> *v7; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v8; // rcx
  char result; // al

  v2 = -1;
  v3 = creature;
  v4 = this;
  if ( creature->mPose.mRigHandle.mData )
    v5 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFollowJoint.mUID);
  else
    v5 = -1;
  v4->mFollowJointID = v5;
  if ( v3->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mDriveJoint.mUID);
  v6 = v4->mFollowJointID;
  v4->mDriveJointID = v2;
  if ( v6 != -1 && v2 != -1 )
    v4->mDriveJointIsParentOfFollow = Skeleton::IsParent(v3->mPose.mRigHandle.mUFGSkeleton, v6, v2);
  v7 = v3->mPoseDrivers.mNode.mPrev;
  v8 = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v7->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v8->mPrev = v7;
  v8->mNext = &v3->mPoseDrivers.mNode;
  result = 1;
  v3->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  return result;
}

// File Line: 1565
// RVA: 0x3A1700
char __fastcall Follow2Link::AddTo(Follow3Link *this, Creature *creature)
{
  signed int v2; // esi
  Creature *v3; // rbx
  Follow3Link *v4; // rdi
  signed int v5; // eax
  UFG::qNode<PoseDriver,PoseDriver> *v6; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v7; // rcx

  v2 = -1;
  v3 = creature;
  v4 = this;
  if ( creature->mPose.mRigHandle.mData )
    v5 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFollowJoint.mUID);
  else
    v5 = -1;
  v4->mFollowJointID = v5;
  if ( v3->mPose.mRigHandle.mData )
    v2 = Skeleton::GetBoneID(v3->mPose.mRigHandle.mUFGSkeleton, v4->mDriveJoint.mUID);
  v4->mDriveJointID = v2;
  v6 = v3->mPoseDrivers.mNode.mPrev;
  v7 = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v6->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
  v7->mPrev = v6;
  v7->mNext = &v3->mPoseDrivers.mNode;
  v3->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v4->mPrev;
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
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&JointReferences::`vftable';
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
  return atexit(dynamic_atexit_destructor_for__gJointReferencesFactory__);
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
  OrientationConstraint *v1; // rbx
  UFG::qNode<PoseDriver,PoseDriver> *v2; // rdx
  UFG::qNode<PoseDriver,PoseDriver> *v3; // rcx
  UFG::qNode<PoseDriver,PoseDriver> *v4; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&OrientationConstraint::`vftable';
  BinPtrArray<JointReferences,1,0>::Clear((BinPtrArray<ITrack,1,0> *)&this->mInputJoints);
  v1->mDriveJoint.vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  v2 = (UFG::qNode<PoseDriver,PoseDriver> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 1655
// RVA: 0x3AE5C0
void __fastcall OrientationConstraint::Serialize(OrientationConstraint *this, IActionTreeSerializer *serializer)
{
  IActionTreeSerializer *v2; // r15
  OrientationConstraint *v3; // rsi
  unsigned int v4; // ebx
  char *v5; // r14
  char *v6; // rcx
  char *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // [rsp+28h] [rbp-40h]
  __int64 v10; // [rsp+30h] [rbp-38h]
  __int64 v11; // [rsp+40h] [rbp-28h]

  v2 = serializer;
  v3 = this;
  v4 = 0;
  v5 = (char *)&this->mInputJoints.mData + this->mInputJoints.mData.mOffset;
  if ( this->mInputJoints.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = &v5[8 * v4];
      v7 = &v6[*(_QWORD *)v6];
      if ( v7 )
      {
        v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 32i64))(&v6[*(_QWORD *)v6]);
        LODWORD(v11) = -1;
        LODWORD(v10) = 0;
        LODWORD(v9) = 1;
        v2->vfptr->_PushObjectToSerialize(
          v2,
          v7,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          (const char *)v8,
          (QUEUE_PRIORITY)v9,
          v10,
          0i64,
          v11,
          0i64);
      }
      ++v4;
    }
    while ( v4 < (v3->mInputJoints.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 1674
// RVA: 0x3A6370
Expression::IMemberMap *__fastcall OrientationConstraint::CreateClone(OrientationConstraint *this)
{
  OrientationConstraint *v1; // rdi
  char *v2; // rax
  char *v3; // rbx
  _QWORD *v4; // rax
  _OWORD *v6; // [rsp+58h] [rbp+10h]

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "OrientationConstraint::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Expression::IMemberMap::`vftable';
    *((_QWORD *)v2 + 1) = 0i64;
    v4 = v2 + 16;
    *v4 = v4;
    v4[1] = v4;
    *(_QWORD *)v3 = &PoseDriver::`vftable';
    *((_WORD *)v3 + 20) = 0;
    v3[42] = 0;
    *((_DWORD *)v3 + 11) = -1;
    *((UFG::qStaticSymbolUC *)v3 + 11) = symEffectorNone;
    *(_QWORD *)v3 = &OrientationConstraint::`vftable';
    v6 = v3 + 56;
    *v6 = (unsigned __int64)&Expression::IMemberMap::`vftable';
    *(_QWORD *)v6 = &JointReferences::`vftable';
    *((UFG::qSymbolUC *)v3 + 18) = UFG::gNullQSymbolUC;
    *((_DWORD *)v3 + 19) = 0;
    *((_DWORD *)v3 + 20) = 0;
    *((_QWORD *)v3 + 11) = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  *((_QWORD *)v3 + 1) = v1->mResourceOwner;
  *((_QWORD *)v3 + 4) = v1->mResourceOwner;
  v3[40] = v1->mActive;
  v3[41] = v1->mDisabled;
  v3[42] = v1->mBreakpoint;
  *((_DWORD *)v3 + 11) = v1->mName.mUID;
  *((_QWORD *)v3 + 6) = v1->mCreature;
  *((_QWORD *)v3 + 8) = v1->mDriveJoint.mResourceOwner;
  *((_DWORD *)v3 + 18) = v1->mDriveJoint.mJointName.mUID;
  *((_DWORD *)v3 + 19) = v1->mDriveJoint.mJointID;
  OrientationConstraint::CopyFrom((OrientationConstraint *)v3, v1);
  return (Expression::IMemberMap *)v3;
}

// File Line: 1693
// RVA: 0x3A5410
void __fastcall OrientationConstraint::CopyFrom(OrientationConstraint *this, OrientationConstraint *other_OrientationConstraint)
{
  __int64 v2; // rbp
  OrientationConstraint *v3; // r15
  char *v4; // r12
  BinPtrArray<ITrack,1,0> *v5; // rsi
  __int64 v6; // rax
  __int64 v7; // r14
  __int64 v8; // rdi
  unsigned int v9; // ebx
  unsigned int v10; // edx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  signed __int64 v13; // rdx

  v2 = 0i64;
  v3 = other_OrientationConstraint;
  v4 = (char *)&other_OrientationConstraint->mInputJoints.mData
     + other_OrientationConstraint->mInputJoints.mData.mOffset;
  if ( other_OrientationConstraint->mInputJoints.mCount & 0x7FFFFFFF )
  {
    v5 = (BinPtrArray<ITrack,1,0> *)&this->mInputJoints;
    do
    {
      v6 = (*(__int64 (**)(void))(*(_QWORD *)&v4[8 * v2 + *(_QWORD *)&v4[8 * v2]] + 16i64))();
      v7 = (unsigned int)v5->mCount;
      LODWORD(v7) = v7 & 0x7FFFFFFF;
      v8 = v6;
      v9 = v7 + 1;
      if ( (signed int)v7 + 1 > (unsigned int)v7 )
      {
        v10 = 1;
        if ( (_DWORD)v7 )
          v10 = 2 * v7;
        for ( ; v10 < v9; v10 *= 2 )
          ;
        if ( v10 - v9 > 0x10000 )
          v10 = v7 + 65537;
        BinPtrArray<Condition,1,0>::Reallocate(v5, v10, "BinPtrArray.Add");
      }
      v5->mCount &= 0x80000000;
      v5->mCount |= v9 & 0x7FFFFFFF;
      v11 = v5->mData.mOffset;
      if ( v11 )
        v12 = (signed __int64)&v5->mData + v11;
      else
        v12 = 0i64;
      v13 = v12 + 8 * v7;
      if ( v8 )
        v8 -= v13;
      *(_QWORD *)v13 = v8;
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (v3->mInputJoints.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 1712
// RVA: 0x3B3490
void __fastcall OrientationConstraint::UpdatePose(OrientationConstraint *this, SkeletalPose *pose)
{
  SkeletalPose *v2; // rsi
  OrientationConstraint *v3; // rdi
  bool v4; // sf
  char v5; // al
  __int64 v6; // rcx
  char *v7; // rax
  _QWORD *v8; // rcx
  __int64 v9; // rcx
  signed __int64 v10; // rax
  _QWORD *v11; // rdx
  char *v12; // r8
  signed __int64 v13; // rdx
  __int64 v14; // rcx
  int v15; // ebx
  hkQsTransformf *v16; // rax
  int v17; // edx
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qMatrix44 matrixMS; // [rsp+20h] [rbp-C8h]
  UFG::qMatrix44 sourceB; // [rsp+60h] [rbp-88h]
  UFG::qMatrix44 sourceA; // [rsp+A0h] [rbp-48h]

  v2 = pose;
  v3 = this;
  if ( !gDisablePoseDrivers )
  {
    v4 = this->mDriveJoint.mJointID < 0;
    this->mActive = 1;
    if ( !v4 )
    {
      v5 = this->mInputJoints.mCount;
      if ( v5 )
      {
        if ( v5 == 1 )
        {
          v6 = this->mInputJoints.mData.mOffset;
          v7 = 0i64;
          if ( v6 )
            v8 = (__int64 *)((char *)&v3->mInputJoints.mData.mOffset + v6);
          else
            v8 = 0i64;
          if ( *v8 )
            v7 = (char *)v8 + *v8;
          SkeletalPose::GetPositionMS(pose, (unsigned __int8)v7[20], &matrixMS);
        }
        else if ( v5 == 2 )
        {
          v9 = this->mInputJoints.mData.mOffset;
          v10 = 0i64;
          if ( v9 )
            v11 = (__int64 *)((char *)&v3->mInputJoints.mData.mOffset + v9);
          else
            v11 = 0i64;
          if ( *v11 )
            v12 = (char *)v11 + *v11;
          else
            v12 = 0i64;
          if ( v9 )
            v13 = (signed __int64)&v3->mInputJoints.mData + v9;
          else
            v13 = 0i64;
          v14 = *(_QWORD *)(v13 + 8);
          if ( v14 )
            v10 = v14 + v13 + 8;
          v15 = *(unsigned __int8 *)(v10 + 20);
          SkeletalPose::GetPositionMS(v2, (unsigned __int8)v12[20], &sourceA);
          SkeletalPose::GetPositionMS(v2, v15, &sourceB);
          BlendSlerp(&matrixMS, &sourceA, &sourceB, 0.5);
        }
        v16 = SkeletalPose::GetTranslationMS(v2, v3->mDriveJoint.mJointID);
        v17 = v3->mDriveJoint.mJointID;
        v18 = v16->m_translation.m_quad.m128_f32[1];
        v19 = v16->m_translation.m_quad.m128_f32[2];
        LODWORD(matrixMS.v3.x) = v16->m_translation.m_quad.m128_i32[0];
        matrixMS.v3.y = v18;
        LODWORD(matrixMS.v3.w) = (_DWORD)FLOAT_1_0;
        matrixMS.v3.z = v19;
        SkeletalPose::SetPositionMS(v2, v17, &matrixMS);
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&TwistXRotLinearLink::`vftable';
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
  SkeletalPose *v2; // rdi
  TwistXRotLinearLink *v3; // rbx
  int v4; // edx
  __m128 v5; // xmm2
  UFG::qVector4 v6; // xmm4
  UFG::qVector4 v7; // xmm1
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  UFG::qMatrix44 d; // [rsp+20h] [rbp-208h]
  UFG::qMatrix44 matrixLS; // [rsp+60h] [rbp-1C8h]
  UFG::qMatrix44 b; // [rsp+A0h] [rbp-188h]
  UFG::qMatrix44 dest; // [rsp+E0h] [rbp-148h]
  UFG::qMatrix44 matrixRS; // [rsp+120h] [rbp-108h]
  UFG::qMatrix44 result; // [rsp+160h] [rbp-C8h]

  v2 = pose;
  v3 = this;
  if ( !gDisablePoseDrivers )
  {
    if ( this->mActive )
    {
      if ( this->mDriveJointID >= 0 )
      {
        v4 = this->mBaseJointID;
        if ( v4 >= 0 && this->mEndJointID >= 0 )
        {
          if ( this->mAtEnd )
            v4 = this->mEndJointID;
          SkeletalPose::GetPositionMS(v2, v4, &b);
          SkeletalPose::GetPositionRefS(v2, v3->mEndJointID, &matrixRS);
          SkeletalPose::GetPositionLS(v2, v3->mEndJointID, &matrixLS);
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
          LODWORD(v8) = (unsigned __int128)_mm_shuffle_ps(v5, v5, 170);
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
          v10 = d.v2.z;
          if ( d.v2.z <= -1.0 )
          {
            v10 = FLOAT_N1_0;
          }
          else if ( d.v2.z >= 1.0 )
          {
            goto LABEL_17;
          }
          v9 = v10;
LABEL_17:
          v11 = atan2f(COERCE_FLOAT(LODWORD(v8) ^ _xmm[0]), v9);
          UFG::qRotationMatrixX(&dest, (float)(v11 * v3->m_M) + v3->m_B);
          UFG::qMatrix44::operator*(&dest, &result, &b);
          SkeletalPose::SetPositionMS(v2, v3->mDriveJointID, &result);
          return;
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&FollowLink::`vftable';
  this->mDriveJoint = UFG::gNullQSymbolUC;
  this->mFollowJoint = UFG::gNullQSymbolUC;
  this->mTransformFloatParamRotInput.mValue = 2;
  this->mTransformFloatParamRotOutput.mValue = 2;
  *(_QWORD *)&this->m_M = 1065353216i64;
  this->mDriveJointIsParentOfFollow = 0;
}

// File Line: 2057
// RVA: 0x3B30E0
void __usercall FollowLink::UpdatePose(FollowLink *this@<rcx>, SkeletalPose *pose@<rdx>, __int128 a3@<xmm8>, __int128 a4@<xmm9>, __int128 a5@<xmm10>, __int128 a6@<xmm11>, __int128 a7@<xmm12>, __int128 a8@<xmm13>)
{
  SkeletalPose *v8; // rdi
  int v9; // edx
  FollowLink *v10; // rbx
  UFG::qVector4 v11; // xmm11
  __m128 v12; // xmm12
  UFG::qVector4 v13; // xmm5
  UFG::qVector4 v14; // xmm4
  __m128 v15; // xmm0
  TransformFloatParamRot v16; // ecx
  __m128 v17; // xmm0
  float v18; // xmm6_4
  Render::DebugDrawContext *v19; // rax
  __int64 v20; // rcx
  const char *v21; // rcx
  unsigned int v22; // ecx
  int v23; // ecx
  __m128 v24; // xmm2
  UFG::qMatrix44 *v25; // rax
  bool v26; // zf
  UFG::qVector4 v27; // xmm2
  UFG::qVector4 v28; // xmm1
  UFG::qVector4 v29; // xmm0
  UFG::qVector3 world_position; // [rsp+40h] [rbp-B8h]
  UFG::qMatrix44 d; // [rsp+50h] [rbp-A8h]
  __m128 v32; // [rsp+98h] [rbp-60h]
  __m128 v33; // [rsp+A8h] [rbp-50h]
  __m128 v34; // [rsp+B8h] [rbp-40h]
  UFG::qMatrix44 v35; // [rsp+C8h] [rbp-30h]
  UFG::qMatrix44 matrixLS; // [rsp+108h] [rbp+10h]
  UFG::qMatrix44 matrixRS; // [rsp+148h] [rbp+50h]
  UFG::qMatrix44 b; // [rsp+188h] [rbp+90h]
  UFG::qMatrix44 matrixMS; // [rsp+1C8h] [rbp+D0h]
  __int128 v40; // [rsp+210h] [rbp+118h]
  __int128 v41; // [rsp+220h] [rbp+128h]
  __int128 v42; // [rsp+230h] [rbp+138h]
  __int128 v43; // [rsp+240h] [rbp+148h]
  __int128 v44; // [rsp+250h] [rbp+158h]
  __int128 v45; // [rsp+260h] [rbp+168h]

  v8 = pose;
  v9 = this->mDriveJointID;
  v10 = this;
  this->mActive = 1;
  if ( v9 >= 0 && this->mFollowJointID >= 0 )
  {
    v45 = a3;
    v44 = a4;
    v43 = a5;
    v42 = a6;
    v41 = a7;
    v40 = a8;
    SkeletalPose::GetPositionLS(v8, v9, &matrixLS);
    SkeletalPose::GetPositionRefS(v8, v10->mDriveJointID, &matrixRS);
    UFG::qInverseAffine(&d, &matrixRS);
    v11 = d.v2;
    v12 = *(__m128 *)&d.v2.z;
    v13 = (UFG::qVector4)_mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 0), (__m128)d.v0),
                                 (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 85), (__m128)d.v1)),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 170), (__m128)d.v2)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v1, (__m128)matrixLS.v1, 255), *(__m128 *)&d.v2.z));
    v14 = (UFG::qVector4)_mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 0), (__m128)d.v0),
                                 (__m128)0i64),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 85), (__m128)d.v1)),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 170), (__m128)d.v2)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v2, (__m128)matrixLS.v2, 255), *(__m128 *)&d.v2.z));
    v15 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 85), (__m128)d.v1),
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 0), (__m128)d.v0),
              (__m128)0i64));
    v16 = v10->mTransformFloatParamRotInput.mValue;
    d.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 0), (__m128)d.v0),
                                  (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 85), (__m128)d.v1)),
                              _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 170), (__m128)d.v2)),
                            _mm_mul_ps(
                              _mm_shuffle_ps((__m128)matrixLS.v0, (__m128)matrixLS.v0, 255),
                              *(__m128 *)&d.v2.z));
    d.v1 = v13;
    d.v2 = v14;
    v17 = _mm_add_ps(
            _mm_add_ps(v15, _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 170), (__m128)v11)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)matrixLS.v3, (__m128)matrixLS.v3, 255), v12));
    *(__m128 *)&d.v2.z = v17;
    ERotation(v16, &d);
    v18 = (float)(v17.m128_f32[0] * v10->m_M) + v10->m_B;
    if ( sFollowLinkDebug )
    {
      SkeletalPose::GetPositionWS(v8, v10->mDriveJointID, &d);
      v19 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
      v20 = (signed int)v10->mTransformFloatParamRotInput.mValue;
      world_position.y = d.v2.w;
      world_position.x = d.v2.z;
      v21 = gTransformFloatParamRotStringList[v20];
      world_position.z = d.v3.x;
      Render::DebugDrawContext::DrawText(
        v19,
        &world_position,
        &UFG::qColour::Green,
        "input:%s:%0.3f -> %0.3f",
        v21,
        v17.m128_f32[0],
        v18);
    }
    v22 = v10->mTransformFloatParamRotOutput.mValue;
    if ( v22 )
    {
      v23 = v22 - 1;
      if ( v23 )
      {
        if ( v23 == 1 )
        {
          UFG::qRotationMatrixZ((UFG::qMatrix44 *)((char *)&d + 56), v18);
        }
        else
        {
          v24 = 0i64;
          v24.m128_f32[0] = (float)1;
          *(__m128 *)&d.v3.z = v24;
          v34 = _mm_shuffle_ps(v24, v24, 21);
          v32 = _mm_shuffle_ps(v24, v24, 81);
          v33 = _mm_shuffle_ps(v24, v24, 69);
        }
      }
      else
      {
        UFG::qRotationMatrixY((UFG::qMatrix44 *)((char *)&d + 56), v18);
      }
    }
    else
    {
      UFG::qRotationMatrixX((UFG::qMatrix44 *)((char *)&d + 56), v18);
    }
    SkeletalPose::GetPositionRefS(v8, v10->mFollowJointID, &b);
    v25 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)((char *)&d + 56), &d, &b);
    v26 = v10->mDriveJointIsParentOfFollow == 0;
    v27 = v25->v2;
    v28 = v25->v3;
    v29 = v25->v0;
    v35.v1 = v25->v1;
    v35.v2 = v27;
    v35.v0 = v29;
    v35.v3 = v28;
    if ( !v26 )
      SkeletalPose::GetPositionMS(v8, v10->mDriveJointID, &matrixMS);
    SkeletalPose::SetPositionLS(v8, v10->mFollowJointID, &v35);
    if ( v10->mDriveJointIsParentOfFollow )
      SkeletalPose::SetPositionMS(v8, v10->mDriveJointID, &matrixMS);
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&Follow2Link::`vftable';
  this->mDriveJoint = UFG::gNullQSymbolUC;
  this->mFollowJoint = UFG::gNullQSymbolUC;
}

// File Line: 2175
// RVA: 0x3B2D90
void __usercall Follow2Link::UpdatePose(Follow2Link *this@<rcx>, SkeletalPose *pose@<rdx>, __int128 a3@<xmm6>, __int128 a4@<xmm7>, __int128 a5@<xmm8>)
{
  SkeletalPose *v5; // rdi
  int v6; // edx
  Follow2Link *v7; // rbx
  float *v8; // rdx
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  int v12; // edx
  UFG::qMatrix44 v13; // [rsp+20h] [rbp-F8h]
  UFG::qMatrix44 matrixLS; // [rsp+60h] [rbp-B8h]
  UFG::qMatrix44 matrixMS; // [rsp+A0h] [rbp-78h]
  __int128 v16; // [rsp+E0h] [rbp-38h]
  __int128 v17; // [rsp+F0h] [rbp-28h]
  __int128 v18; // [rsp+100h] [rbp-18h]

  v5 = pose;
  v6 = this->mDriveJointID;
  v7 = this;
  this->mActive = 1;
  if ( v6 >= 0 && this->mFollowJointID >= 0 )
  {
    v18 = a3;
    v17 = a4;
    v16 = a5;
    SkeletalPose::GetPositionLS(v5, v6, &matrixLS);
    v8 = v5->mRigHandle.mUFGSkeleton->mhkaSkeleton->m_referencePose.m_data[v7->mDriveJointID].m_translation.m_quad.m128_f32;
    v9 = matrixLS.v3.x - *v8;
    v10 = matrixLS.v3.y - v8[1];
    v11 = matrixLS.v3.z - v8[2];
    SkeletalPose::GetPositionLS(v5, v7->mFollowJointID, &v13);
    v12 = v7->mDriveJointID;
    v13.v3.y = v13.v3.y + v10;
    v13.v3.x = v13.v3.x + v9;
    v13.v3.w = v13.v3.w + 1.0;
    v13.v3.z = v13.v3.z + v11;
    SkeletalPose::GetPositionMS(v5, v12, &matrixMS);
    SkeletalPose::SetPositionLS(v5, v7->mFollowJointID, &v13);
    SkeletalPose::SetPositionMS(v5, v7->mDriveJointID, &matrixMS);
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&Follow3Link::`vftable';
  this->mDriveJoint = UFG::gNullQSymbolUC;
  this->mFollowJoint = UFG::gNullQSymbolUC;
}

// File Line: 2256
// RVA: 0x3B2EE0
void __usercall Follow3Link::UpdatePose(Follow3Link *this@<rcx>, SkeletalPose *pose@<rdx>, __int128 a3@<xmm6>, __int128 a4@<xmm7>, __int128 a5@<xmm8>, __int128 a6@<xmm9>, __int128 a7@<xmm10>)
{
  SkeletalPose *v7; // rdi
  int v8; // edx
  Follow3Link *v9; // rbx
  __m128 v10; // xmm7
  float v11; // xmm2_4
  __m128 v12; // xmm1
  float *v13; // rdx
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm8_4
  float v18; // xmm7_4
  __m128 v19; // xmm3
  float v20; // xmm6_4
  float v21; // xmm10_4
  float v22; // xmm6_4
  float v23; // xmm10_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  UFG::qMatrix44 matrixLS; // [rsp+20h] [rbp-198h]
  UFG::qMatrix44 dest; // [rsp+60h] [rbp-158h]
  UFG::qMatrix44 result; // [rsp+A0h] [rbp-118h]
  UFG::qMatrix44 b; // [rsp+E0h] [rbp-D8h]
  UFG::qMatrix44 matrixMS; // [rsp+120h] [rbp-98h]
  __int128 v31; // [rsp+160h] [rbp-58h]
  __int128 v32; // [rsp+170h] [rbp-48h]
  __int128 v33; // [rsp+180h] [rbp-38h]
  __int128 v34; // [rsp+190h] [rbp-28h]
  __int128 v35; // [rsp+1A0h] [rbp-18h]

  v7 = pose;
  v8 = this->mDriveJointID;
  v9 = this;
  this->mActive = 1;
  if ( v8 < 0 || this->mFollowJointID < 0 )
    return;
  v35 = a3;
  v34 = a4;
  v33 = a5;
  v32 = a6;
  v31 = a7;
  SkeletalPose::GetPositionLS(v7, v8, &matrixLS);
  v10 = (__m128)LODWORD(matrixLS.v3.z);
  v11 = *(float *)&FLOAT_1_0;
  v12 = v10;
  v12.m128_f32[0] = (float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(matrixLS.v3.x * matrixLS.v3.x);
  v13 = v7->mRigHandle.mUFGSkeleton->mhkaSkeleton->m_referencePose.m_data[v9->mDriveJointID].m_translation.m_quad.m128_f32;
  v14 = *v13;
  v15 = v13[2];
  if ( v12.m128_f32[0] == 0.0 )
    v16 = 0.0;
  else
    v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
  v19 = (__m128)*((unsigned int *)v13 + 2);
  v17 = matrixLS.v3.x * v16;
  v18 = matrixLS.v3.z * v16;
  v19.m128_f32[0] = (float)(v15 * v15) + (float)(v14 * v14);
  if ( v19.m128_f32[0] == 0.0 )
    v20 = 0.0;
  else
    v20 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19));
  v21 = v20;
  v22 = v20 * v15;
  v23 = v21 * v14;
  v24 = (float)(v18 * v22) + (float)(v17 * v23);
  if ( v24 <= -1.0 )
  {
    v24 = FLOAT_N1_0;
  }
  else if ( v24 >= 1.0 )
  {
    goto LABEL_14;
  }
  v11 = v24;
LABEL_14:
  v25 = acosf(v11);
  if ( (float)((float)(v18 * v23) - (float)(v17 * v22)) > 0.0 )
    LODWORD(v25) ^= _xmm[0];
  UFG::qRotationMatrixY(&dest, v25);
  SkeletalPose::GetPositionLS(v7, v9->mFollowJointID, &b);
  UFG::qMatrix44::operator*(&dest, &result, &b);
  SkeletalPose::GetPositionMS(v7, v9->mDriveJointID, &matrixMS);
  SkeletalPose::SetPositionLS(v7, v9->mFollowJointID, &result);
  SkeletalPose::SetPositionMS(v7, v9->mDriveJointID, &matrixMS);
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax
  UFG::qVector4 v2; // xmm1
  UFG::qVector4 v3; // xmm2
  UFG::qVector4 v4; // xmm3

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&Spring1DOF::`vftable';
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
  v2 = UFG::qMatrix44::msIdentity.v1;
  v3 = UFG::qMatrix44::msIdentity.v2;
  v4 = UFG::qMatrix44::msIdentity.v3;
  this->mCurrentTransform.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mCurrentTransform.v1 = v2;
  this->mCurrentTransform.v2 = v3;
  this->mCurrentTransform.v3 = v4;
  this->mTeleported = 0;
}

// File Line: 2463
// RVA: 0x3B1500
char __fastcall Spring1DOF::Update(Spring1DOF *this, float timeDelta)
{
  char result; // al

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
  float v3; // xmm3_4
  __int32 v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  v3 = value;
  if ( axis )
  {
    v4 = axis - 1;
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        v5 = transform->v2.x;
        v6 = transform->v2.y;
        v7 = transform->v2.z;
      }
      else
      {
        v5 = UFG::qVector4::msZero.x;
        v6 = UFG::qVector4::msZero.y;
        v7 = UFG::qVector4::msZero.z;
      }
    }
    else
    {
      v5 = transform->v1.x;
      v6 = transform->v1.y;
      v7 = transform->v1.z;
    }
  }
  else
  {
    v5 = transform->v0.x;
    v6 = transform->v0.y;
    v7 = transform->v0.z;
  }
  v8 = (float)(v6 * v3) + transform->v3.y;
  v9 = (float)(v7 * v3) + transform->v3.z;
  transform->v3.x = (float)(v5 * v3) + transform->v3.x;
  transform->v3.y = v8;
  transform->v3.z = v9;
}

// File Line: 2517
// RVA: 0x3B40F0
void __fastcall Spring1DOF::UpdatePosePostPhysics(Spring1DOF *this, SkeletalPose *pose)
{
  SkeletalPose *v2; // rsi
  int v3; // edx
  Spring1DOF *v4; // rdi
  __m128 v5; // xmm6
  UFG::qVector4 v6; // xmm0
  __int128 v7; // xmm1
  int v8; // ecx
  float v9; // xmm8_4
  int v10; // ecx
  float v11; // xmm0_4
  bool v12; // zf
  float v13; // xmm9_4
  float v14; // xmm10_4
  float v15; // xmm7_4
  float v16; // xmm11_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  int v20; // ecx
  int v21; // ecx
  float v22; // xmm4_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  const char *v25; // r14
  Render::DebugDrawContext *v26; // rbx
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
  float v37; // xmm0_4
  float v38; // xmm8_4
  float v39; // xmm7_4
  float v40; // xmm3_4
  float v41; // xmm0_4
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
  __int128 v60; // xmm1
  UFG::qVector3 p0; // [rsp+30h] [rbp-B8h]
  UFG::qVector3 p1; // [rsp+3Ch] [rbp-ACh]
  UFG::qMatrix44 d; // [rsp+50h] [rbp-98h]
  __int128 v64; // [rsp+98h] [rbp-50h]
  __m128 v65; // [rsp+A8h] [rbp-40h]
  UFG::qMatrix44 matrixRoot; // [rsp+B8h] [rbp-30h]
  UFG::qMatrix44 result; // [rsp+F8h] [rbp+10h]

  v2 = pose;
  v3 = this->mFollowJointID;
  v4 = this;
  this->mActive = 1;
  SkeletalPose::GetPositionMS(v2, v3, (UFG::qMatrix44 *)((char *)&d + 40));
  v5 = v65;
  if ( v4->mTeleported )
  {
    v6 = *(UFG::qVector4 *)&d.v2.z;
    v7 = v64;
    v4->mTeleported = 0;
    v4->mCurrentTransform.v0 = v6;
    v4->mCurrentTransform.v1 = *(UFG::qVector4 *)&d.v3.z;
    v4->mCurrentTransform.v2 = (UFG::qVector4)v7;
    v4->mCurrentTransform.v3 = (UFG::qVector4)v5;
  }
  v8 = v4->mTransformFollowAxis.mValue;
  v9 = 0.0;
  if ( v8 )
  {
    v10 = v8 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(v5, v5, 170);
      else
        v11 = 0.0;
    }
    else
    {
      LODWORD(v11) = (unsigned __int128)_mm_shuffle_ps(v5, v5, 85);
    }
  }
  else
  {
    v11 = v5.m128_f32[0];
  }
  v12 = v4->mTransformSpace.mValue == 1;
  v4->mNeutralBase = v11;
  v13 = v4->mCurrentTransform.v3.x;
  v14 = v4->mCurrentTransform.v3.y;
  v15 = v4->mCurrentTransform.v3.z;
  v16 = v4->mCurrentTransform.v3.w;
  if ( v12 )
  {
    UFG::qInverseAffine(&d, (UFG::qMatrix44 *)((char *)&d + 40));
    v4->mNeutralBase = 0.0;
    v5 = v65;
    v17 = (float)((float)((float)(d.v1.y * v14) + (float)(d.v0.y * v13)) + (float)(d.v2.y * v15))
        + (float)(d.v1.w * v16);
    v18 = d.v0.z * v13;
    v13 = (float)((float)((float)(d.v1.x * v14) + (float)(d.v0.x * v13)) + (float)(d.v2.x * v15))
        + (float)(d.v1.z * v16);
    v19 = (float)(d.v1.z * v14) + v18;
    v14 = v17;
    v15 = (float)(v19 + (float)(d.v2.z * v15)) + (float)(d.v2.x * v16);
  }
  v20 = v4->mTransformFollowAxis.mValue;
  if ( v20 )
  {
    v21 = v20 - 1;
    if ( v21 )
    {
      if ( v21 == 1 )
        v9 = v15;
    }
    else
    {
      v9 = v14;
    }
  }
  else
  {
    v9 = v13;
  }
  v4->mXcurr = v9;
  Spring1DOF::enforceLimits(v4);
  v22 = v4->mXcurr;
  v23 = v4->mTimeDelta;
  v24 = (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                               (float)((float)((float)(v4->mXcurr - v4->mNeutralBase) * v4->mGain)
                                     + (float)(v4->mXdotcurr * v4->mCV))
                             / v4->mMass) ^ _xmm[0])
              * v23)
      + v4->mXdotcurr;
  v4->mXdotcurr = v24;
  v4->mXcurr = (float)(v24 * v23) + v22;
  Spring1DOF::enforceLimits(v4);
  v25 = &customWorldMapCaption;
  if ( v4->mBreakpoint )
  {
    v26 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    SkeletalPose::GetRootMatrix(v2, &matrixRoot);
    UFG::qMatrix44::operator*(&v4->mCurrentTransform, &result, &matrixRoot);
    SkeletalPose::GetPositionWS(v2, v4->mFollowJointID, &d);
    v27 = &customWorldMapCaption;
    if ( sText )
      v27 = "p0";
    Render::DebugDrawContext::DrawCoord(v26, &result, boneScale, v27);
    v28 = &customWorldMapCaption;
    if ( sText )
      v28 = "pF";
    Render::DebugDrawContext::DrawCoord(v26, &d, boneScale, v28);
    v29 = v4->mTransformSpace.mValue;
    v30 = d.v1.z;
    v31 = d.v1.w;
    v32 = d.v2.x;
    if ( v29 == 2 )
    {
      v33 = v4->mTransformFollowAxis.mValue;
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
        v37 = v4->mMinLimit;
        v38 = d.v1.z - (float)(v30 * v37);
        v39 = d.v1.w - (float)(v31 * v37);
        v40 = v32 * v37;
        v41 = v4->mMaxLimit;
        v42 = d.v2.x - v40;
        p1.x = v38;
        v43 = d.v1.z + (float)(v30 * v41);
        v44 = d.v1.w + (float)(v31 * v41);
        p1.y = v39;
        v45 = d.v2.x + (float)(v32 * v41);
        p1.z = d.v2.x - v40;
        p0.x = v38 - (float)(v30 * sLimitArrowTail);
        p0.z = (float)(d.v2.x - v40) - (float)(v32 * sLimitArrowTail);
        p0.y = v39 - (float)(v31 * sLimitArrowTail);
        Render::DebugDrawContext::DrawArrow(
          v26,
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
          v26,
          &p1,
          &p0,
          &UFG::qColour::Green,
          &UFG::qMatrix44::msIdentity,
          (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback);
        v46 = v4->mMinLimit;
        v47 = v38 - (float)(v30 * sLimitArrowTail);
        v48 = v39 - (float)(v31 * sLimitArrowTail);
        v49 = v42 - (float)(v32 * sLimitArrowTail);
        v50 = &customWorldMapCaption;
        if ( sText )
          v50 = "MinLimit:%0.3f";
        p0.x = v47;
        p0.y = v48;
        p0.z = v49;
        Render::DebugDrawContext::DrawText(v26, &p0, &UFG::qColour::Green, v50, v46);
        v51 = &customWorldMapCaption;
        v52 = v32 * sLimitArrowTail;
        v53 = v4->mMaxLimit;
        v54 = (float)(v30 * sLimitArrowTail) + v43;
        v55 = (float)(v31 * sLimitArrowTail) + v44;
        if ( sText )
          v51 = "MaxLimit:%0.3f";
        p0.x = v54;
        p0.y = v55;
        p0.z = v52 + v45;
        Render::DebugDrawContext::DrawText(v26, &p0, &UFG::qColour::Green, v51, v53);
        v5 = v65;
        goto LABEL_43;
      }
    }
    else
    {
      if ( v29 != 1 )
        goto LABEL_38;
      v35 = v4->mTransformFollowAxis.mValue;
      if ( !v35 )
      {
        v30 = d.v0.x;
        v31 = d.v0.y;
        v32 = d.v0.z;
        goto LABEL_38;
      }
      v36 = v35 - 1;
      if ( !v36 )
      {
        v30 = d.v1.x;
        v31 = d.v1.y;
        v32 = d.v1.z;
        goto LABEL_38;
      }
      if ( v36 == 1 )
      {
        v30 = d.v2.x;
        v31 = d.v2.y;
        v32 = d.v2.z;
        goto LABEL_38;
      }
    }
    v30 = UFG::qVector4::msZero.x;
    v31 = UFG::qVector4::msZero.y;
    v32 = UFG::qVector4::msZero.z;
    goto LABEL_38;
  }
LABEL_43:
  v56 = v4->mTransformSpace.mValue;
  if ( v56 == 2 )
  {
    v57 = v4->mTransformFollowAxis.mValue;
    if ( v57 )
    {
      v58 = v57 - 1;
      if ( v58 )
      {
        if ( v58 == 1 )
          v65.m128_i32[2] = LODWORD(v4->mXcurr);
      }
      else
      {
        v65.m128_i32[1] = LODWORD(v4->mXcurr);
      }
    }
    else
    {
      v65.m128_i32[0] = LODWORD(v4->mXcurr);
    }
  }
  else
  {
    if ( v56 != 1 )
      goto LABEL_53;
    SetTransAlongAxisCoord(
      (TransformFloatParamTrans)v4->mTransformFollowAxis.mValue,
      (UFG::qMatrix44 *)((char *)&d + 40),
      v4->mXcurr);
  }
  SkeletalPose::SetPositionMS(v2, v4->mFollowJointID, (UFG::qMatrix44 *)((char *)&d + 40));
  v5 = v65;
LABEL_53:
  if ( v4->mBreakpoint )
  {
    v59 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    SkeletalPose::GetPositionWS(v2, v4->mFollowJointID, &result);
    if ( sText )
      v25 = "pT";
    Render::DebugDrawContext::DrawCoord(v59, &result, boneScale_0, v25);
    v5 = v65;
  }
  v60 = v64;
  v4->mCurrentTransform.v0 = *(UFG::qVector4 *)&d.v2.z;
  v4->mCurrentTransform.v1 = *(UFG::qVector4 *)&d.v3.z;
  v4->mCurrentTransform.v2 = (UFG::qVector4)v60;
  v4->mCurrentTransform.v3 = (UFG::qVector4)v5;
}

// File Line: 2637
// RVA: 0x3B6A90
void __fastcall Spring1DOF::enforceLimits(Spring1DOF *this)
{
  float v1; // xmm1_4
  float v2; // xmm0_4
  float v3; // xmm2_4
  bool v4; // cf
  bool v5; // zf

  v1 = this->mNeutralBase;
  v2 = this->mMaxLimit;
  v3 = this->mXcurr - v1;
  if ( v2 >= v3 )
  {
    if ( COERCE_FLOAT(LODWORD(this->mMinLimit) ^ _xmm[0]) > v3 )
    {
      v4 = this->mXdotcurr > 0.0;
      v5 = this->mXdotcurr == 0.0;
      this->mXcurr = v1 - this->mMinLimit;
      if ( !v4 && !v5 )
        this->mXdotcurr = 0.0;
    }
  }
  else
  {
    this->mXcurr = v2 + v1;
    if ( this->mXdotcurr > 0.0 )
      this->mXdotcurr = 0.0;
  }
}

// File Line: 2660
// RVA: 0x3A1930
char __fastcall Spring1DOF::AddTo(Spring1DOF *this, Creature *creature)
{
  Creature *v2; // rdi
  Spring1DOF *v3; // rbx
  int v4; // eax
  UFG::qNode<PoseDriver,PoseDriver> *v5; // rax
  UFG::qNode<PoseDriver,PoseDriver> *v6; // rcx
  char result; // al
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  UFG::qMatrix44 matrixMS; // [rsp+20h] [rbp-48h]

  v2 = creature;
  v3 = this;
  if ( !creature->mPose.mRigHandle.mData )
    return 0;
  v4 = Skeleton::GetBoneID(creature->mPose.mRigHandle.mUFGSkeleton, this->mFollowJoint.mUID);
  if ( v4 == -1 )
    return 0;
  v3->mFollowJointID = v4;
  v5 = v2->mPoseDrivers.mNode.mPrev;
  v6 = (UFG::qNode<PoseDriver,PoseDriver> *)&v3->mPrev;
  v5->mNext = (UFG::qNode<PoseDriver,PoseDriver> *)&v3->mPrev;
  v6->mPrev = v5;
  v6->mNext = &v2->mPoseDrivers.mNode;
  v2->mPoseDrivers.mNode.mPrev = (UFG::qNode<PoseDriver,PoseDriver> *)&v3->mPrev;
  SkeletalPose::GetPositionMS(&v2->mPose, v3->mFollowJointID, &matrixMS);
  result = 1;
  v8 = matrixMS.v2;
  v3->mCurrentTransform.v0 = matrixMS.v0;
  v3->mCurrentTransform.v1 = matrixMS.v1;
  v9 = matrixMS.v3;
  v3->mCurrentTransform.v2 = v8;
  v3->mCurrentTransform.v3 = v9;
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
  UFG::qNode<PoseDriver,PoseDriver> *v1; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v1 = (UFG::qNode<PoseDriver,PoseDriver> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Expression::IMemberMapVtbl *)&PoseDriver::`vftable';
  *(_WORD *)&this->mActive = 0;
  this->mBreakpoint = 0;
  this->mName.mUID = -1;
  this->mName.mUID = symEffectorNone.mUID;
  this->vfptr = (Expression::IMemberMapVtbl *)&RootUprightDriver::`vftable';
  *(_QWORD *)&this->mUprightVector.x = 0i64;
  this->mUprightVector.z = 1.0;
}

// File Line: 2922
// RVA: 0x3B14B0
bool __fastcall RootUprightDriver::Update(RootUprightDriver *this, float timeDelta)
{
  float v2; // xmm3_4
  bool result; // al
  float v4; // xmm0_4

  if ( !this->mActive )
    return 1;
  v2 = this->mBlendRate;
  if ( v2 == 0.0 )
    return 1;
  result = 1;
  v4 = (float)(v2 * timeDelta) + this->mBlendWeight;
  this->mBlendWeight = v4;
  if ( v2 <= 0.0 )
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
  SkeletalPose *v2; // rdi
  RootUprightDriver *v3; // rbx
  float v4; // xmm6_4
  hkQsTransformf *v5; // rax
  float v6; // xmm7_4
  __m128 v7; // xmm10
  float v8; // xmm2_4
  float v9; // xmm9_4
  unsigned int v10; // xmm15_4
  float v11; // xmm1_4
  __int64 v12; // kr00_8
  float v13; // xmm2_4
  float v14; // xmm0_4
  int v15; // xmm1_4
  float v16; // xmm4_4
  __m128 v17; // xmm5
  float v18; // xmm7_4
  __m128 v19; // xmm2
  UFG::qMatrix44 *v20; // rax
  bool v21; // zf
  __int128 v22; // xmm2
  UFG::qVector4 v23; // xmm1
  __int128 v24; // xmm3
  hkQsTransformf *v25; // rax
  float d[4]; // [rsp+20h] [rbp-C8h]
  __int128 v27; // [rsp+30h] [rbp-B8h]
  __int128 v28; // [rsp+40h] [rbp-A8h]
  __int128 v29; // [rsp+50h] [rbp-98h]
  UFG::qVector3 axis; // [rsp+60h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+70h] [rbp-78h]
  UFG::qMatrix44 sourceA; // [rsp+D8h] [rbp-10h]
  unsigned int v33; // [rsp+198h] [rbp+B0h]

  v2 = pose;
  v3 = this;
  if ( this->mActive )
  {
    v4 = 0.0;
    if ( this->mBlendWeight > 0.0 )
    {
      v5 = SkeletalPose::GetRoot(pose);
      hkQsTransformf::get4x4ColumnMajor(v5, d);
      v6 = v3->mUprightVector.y;
      v7 = (__m128)LODWORD(v3->mUprightVector.x);
      v8 = v3->mUprightVector.y;
      v9 = v3->mUprightVector.z;
      v10 = v29;
      v11 = v3->mUprightVector.z * *((float *)&v28 + 2);
      v33 = DWORD1(v29);
      v12 = *((_QWORD *)&v29 + 1);
      v13 = (float)((float)(v8 * *((float *)&v28 + 1)) + (float)(v7.m128_f32[0] * *(float *)&v28)) + v11;
      if ( v13 <= -1.0 )
      {
        v13 = FLOAT_N1_0;
      }
      else if ( v13 >= 1.0 )
      {
        v13 = *(float *)&FLOAT_1_0;
      }
      v14 = acosf(v13);
      *(float *)&v15 = v14;
      if ( v14 < 0.0 )
        v15 = LODWORD(v14) ^ _xmm[0];
      if ( *(float *)&v15 >= 0.0015 )
      {
        v17 = v7;
        v16 = (float)(v9 * *((float *)&v28 + 1)) - (float)(v6 * *((float *)&v28 + 2));
        v17.m128_f32[0] = (float)(v7.m128_f32[0] * *((float *)&v28 + 2)) - (float)(v9 * *(float *)&v28);
        v18 = (float)(v6 * *(float *)&v28) - (float)(v7.m128_f32[0] * *((float *)&v28 + 1));
        v19 = v17;
        v19.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16)) + (float)(v18 * v18);
        if ( v19.m128_f32[0] != 0.0 )
          v4 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v19));
        axis.x = v16 * v4;
        axis.y = v17.m128_f32[0] * v4;
        axis.z = v18 * v4;
        UFG::qRotationMatrixAxis((UFG::qMatrix44 *)((char *)&result + 40), &axis, COERCE_FLOAT(LODWORD(v14) ^ _xmm[0]));
        *(UFG::qVector3 *)&v29 = UFG::qVector3::msZero;
        HIDWORD(v29) = 1065353216;
        v20 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)d, &result, (UFG::qMatrix44 *)((char *)&result + 40));
        v21 = 1.0 == v3->mBlendWeight;
        v22 = (__int128)v20->v2;
        v23 = v20->v3;
        v24 = (__int128)v20->v1;
        *(UFG::qVector4 *)d = v20->v0;
        v28 = v22;
        *((_QWORD *)&v29 + 1) = v12;
        *(_QWORD *)&v29 = __PAIR__(v33, v10);
        v27 = v24;
        if ( v21 )
        {
          SkeletalPose::SetRoot(v2, (UFG::qMatrix44 *)d, 0);
          v3->mActive = 0;
        }
        else
        {
          v25 = SkeletalPose::GetRoot(v2);
          hkQsTransformf::get4x4ColumnMajor(v25, &sourceA.v0.x);
          BlendSlerp(&result, &sourceA, (UFG::qMatrix44 *)d, v3->mBlendWeight);
          SkeletalPose::SetRoot(v2, &result, 0);
        }
      }
    }
  }
}

