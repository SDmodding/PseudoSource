// File Line: 68
// RVA: 0x44A4F0
void __fastcall UFG::PhysicsBoat::PhysicsBoat(UFG::PhysicsBoat *this, UFG::VehicleParams *param, UFG::qMatrix44 *transform, UFG::qVector3 *velocity)
{
  UFG::PhysicsBoat *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  signed __int64 v7; // rax
  unsigned int *v8; // rcx
  hkpRigidBody *v9; // rcx
  signed __int64 v10; // rdi
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  _QWORD **v14; // rax
  hkpUnaryAction *v15; // rax
  hkpUnaryAction *v16; // rsi
  char v17; // al
  char v18; // dl
  __int64 v19; // rax
  char v20; // cl
  _QWORD **v21; // rax
  hkpReorientAction *v22; // rax
  hkpReorientAction *v23; // rax
  _QWORD **v24; // rax
  hkpReorientAction *v25; // rax
  hkpReorientAction *v26; // rax
  char v27; // al
  bool *v28; // rax
  signed __int64 v29; // rcx
  hkVector4f centerOfMass; // [rsp+30h] [rbp-98h]
  hkVector4f upAxis; // [rsp+40h] [rbp-88h]
  UFG::qReflectHandleBase v32; // [rsp+50h] [rbp-78h]
  hkVector4f rotationAxis; // [rsp+80h] [rbp-48h]
  hkVector4f v34; // [rsp+90h] [rbp-38h]
  __int64 v35; // [rsp+A0h] [rbp-28h]

  v35 = -2i64;
  v4 = this;
  UFG::PhysicsVehicle::PhysicsVehicle((UFG::PhysicsVehicle *)&this->vfptr, param, transform, velocity);
  v4->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsBoat::`vftable;
  v4->mOustideWorldBoundaries = 0;
  v4->mEngineDamage = 0.0;
  v4->mChopFunction.bCircular = 0;
  *(_QWORD *)&v4->mChopFunction.tDecay = 1060320051i64;
  v4->mChopFunction.nOctaves = 3;
  LODWORD(v4->mChopFunction.tFrequency) = (unsigned int)FLOAT_1_0 & _xmm;
  v4->mChopFunction.tOffset = 0.0;
  v4->mChopFunction.tRangeMax = 1.0;
  v5 = 0.0;
  v6 = *(float *)&FLOAT_1_0;
  v7 = 3i64;
  do
  {
    v5 = v5 + v6;
    v6 = v6 * 0.69999999;
    --v7;
  }
  while ( v7 );
  v4->mChopFunction.tAmplitude = 1.0 / v5;
  *((_DWORD *)v4 + 246) &= 0xFFFFFFFA;
  UFG::qReflectHandleBase::qReflectHandleBase(&v32);
  v32.mTypeUID = UFG::qStringHash64("UFG::BoatPhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v32, v32.mTypeUID, v4->mDnaDefinition.mData->mBaseNode.mUID);
  UFG::PhysicsBoat::LoadProperties(v4);
  v8 = (unsigned int *)v32.mData;
  v4->mFloatPositionsLocalSpace[0].m_quad = _mm_unpacklo_ps(
                                              _mm_unpacklo_ps(
                                                (__m128)LODWORD(v32.mData[2].mBaseNode.mParent),
                                                (__m128)LODWORD(v32.mData[2].mBaseNode.mChildren[0])),
                                              _mm_unpacklo_ps(
                                                (__m128)HIDWORD(v32.mData[2].mBaseNode.mParent),
                                                (__m128)(unsigned int)FLOAT_1_0));
  v4->mFloatPositionsLocalSpace[1].m_quad = _mm_unpacklo_ps(
                                              _mm_unpacklo_ps((__m128)v8[47], (__m128)v8[49]),
                                              _mm_unpacklo_ps((__m128)v8[48], (__m128)(unsigned int)FLOAT_1_0));
  v4->mFloatPositionsLocalSpace[2].m_quad = _mm_unpacklo_ps(
                                              _mm_unpacklo_ps((__m128)v8[50], (__m128)v8[52]),
                                              _mm_unpacklo_ps((__m128)v8[51], (__m128)(unsigned int)FLOAT_1_0));
  v4->mFloatPositionsLocalSpace[3].m_quad = _mm_unpacklo_ps(
                                              _mm_unpacklo_ps((__m128)v8[53], (__m128)v8[55]),
                                              _mm_unpacklo_ps((__m128)v8[54], (__m128)(unsigned int)FLOAT_1_0));
  LODWORD(v4->mFloatBuoyancy[0]) = v8[74];
  LODWORD(v4->mFloatBuoyancy[1]) = v8[75];
  LODWORD(v4->mFloatBuoyancy[2]) = v8[76];
  LODWORD(v4->mFloatBuoyancy[3]) = v8[77];
  LODWORD(v4->mCOMShift) = v8[69];
  v4->mIsCOMShifted = 1;
  v9 = v4->mRigidBody->mBody;
  centerOfMass.m_quad = _mm_add_ps(
                          v9->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad,
                          _mm_unpacklo_ps(
                            _mm_unpacklo_ps(_mm_xor_ps((__m128)LODWORD(v4->mCOMShift), *(__m128 *)_xmm), (__m128)0i64),
                            (__m128)0i64));
  hkpRigidBody::setCenterOfMassLocal(v9, &centerOfMass);
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = v11;
  *(_DWORD *)(v10 + 4 * v12) = 3;
  *(_QWORD *)(v10 + 8 * v12 + 16) = "BoatAction";
  *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v10 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v10 + 81) = v13;
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkpUnaryAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 72i64);
  v16 = v15;
  centerOfMass.m_quad.m128_u64[0] = (unsigned __int64)v15;
  if ( v15 )
  {
    hkpUnaryAction::hkpUnaryAction(v15, (hkpEntity *)&v4->mRigidBody->mBody->vfptr, 0i64);
    v16->vfptr = (hkBaseObjectVtbl *)&UFG::BoatAction::`vftable;
    LODWORD(v16[1].vfptr) &= 0xFFFFFFF8;
    *(_QWORD *)&v16[1].m_memSizeAndFlags = v4;
  }
  else
  {
    v16 = 0i64;
  }
  v4->mBoatAction = (UFG::BoatAction *)v16;
  v17 = *(_BYTE *)(v10 + 80);
  if ( v17 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v17 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  rotationAxis.m_quad = (__m128)_xmm;
  v34.m_quad = _xmm;
  upAxis.m_quad = _xmm;
  v18 = ++*(_BYTE *)(v10 + 80);
  v19 = v18;
  *(_DWORD *)(v10 + 4 * v19) = 3;
  *(_QWORD *)(v10 + 8 * v19 + 16) = "hkpReorientAction";
  *(_QWORD *)(v10 + 8 * v19 + 48) = 0i64;
  v20 = *(_BYTE *)(v10 + 81);
  if ( v18 > v20 )
    v20 = v18;
  *(_BYTE *)(v10 + 81) = v20;
  v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (hkpReorientAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 112i64);
  centerOfMass.m_quad.m128_u64[0] = (unsigned __int64)v22;
  if ( v22 )
    hkpReorientAction::hkpReorientAction(v22, v4->mRigidBody->mBody, &rotationAxis, &upAxis, v4->mRollStability, 0.1);
  else
    v23 = 0i64;
  v4->mReorientActionRoll = v23;
  v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (hkpReorientAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(v24[11], 112i64);
  centerOfMass.m_quad.m128_u64[0] = (unsigned __int64)v25;
  if ( v25 )
    hkpReorientAction::hkpReorientAction(v25, v4->mRigidBody->mBody, &v34, &upAxis, v4->mPitchStability, 0.1);
  else
    v26 = 0i64;
  v4->mReorientActionPitch = v26;
  v27 = *(_BYTE *)(v10 + 80);
  if ( v27 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v27 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  v4->mChopDist = UFG::qRandom(500.0, &UFG::qDefaultSeed);
  v4->mChopTrough = 0.5;
  v28 = v4->mPrevFloatInWater;
  v29 = 4i64;
  do
  {
    *(v28 - 4) = 1;
    *v28++ = 1;
    --v29;
  }
  while ( v29 );
  v4->mUserData.isBoat = 1;
  v4->mRigidBody->mUserData.isBoat = 1;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v32);
}

// File Line: 136
// RVA: 0x472B40
void __fastcall UFG::PhysicsBoat::Reload(UFG::PhysicsBoat *this, UFG::qSymbol *propertySetName)
{
  UFG::PhysicsBoat *v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax

  v2 = this;
  this->mParams->mPhysicsPropertiesName.mUID = propertySetName->mUID;
  v3 = this->mParams->mPhysicsPropertiesName.mUID;
  if ( v3 )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, v3);
    if ( v4 )
      UFG::qReflectHandleBase::Init(
        (UFG::qReflectHandleBase *)&v2->mDnaDefinition.mPrev,
        v2->mDnaDefinition.mTypeUID,
        (unsigned __int64)v4->mNULL.mParent);
  }
  UFG::PhysicsVehicle::LoadProperties((UFG::PhysicsVehicle *)&v2->vfptr);
  UFG::PhysicsBoat::LoadProperties(v2);
}

// File Line: 144
// RVA: 0x46B6B0
void __fastcall UFG::PhysicsBoat::LoadProperties(UFG::PhysicsBoat *this)
{
  UFG::PhysicsBoat *v1; // rbx
  UFG::qReflectObject *v2; // rcx
  float v3; // xmm0_4
  hkpReorientAction *v4; // rcx
  hkpReorientAction *v5; // rcx
  UFG::qReflectHandleBase v6; // [rsp+28h] [rbp-30h]

  v1 = this;
  UFG::qReflectHandleBase::qReflectHandleBase(&v6);
  v6.mTypeUID = UFG::qStringHash64("UFG::BoatPhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v6, v6.mTypeUID, v1->mDnaDefinition.mData->mBaseNode.mUID);
  v2 = v6.mData;
  v1->mFloatDragZ[0] = *(float *)&v6.mData[3].mHandles.mNode.mNext;
  v1->mFloatDragZ[1] = *((float *)&v2[3].mHandles.mNode.mNext + 1);
  v1->mFloatDragZ[2] = *(float *)&v2[4].vfptr;
  v1->mFloatDragZ[3] = *((float *)&v2[4].vfptr + 1);
  v1->mRudderForceMultiplier = *(float *)&v2[2].mHandles.mNode.mPrev;
  v1->mRudderOffset.m_quad.m128_i32[0] = HIDWORD(v2[2].mHandles.mNode.mPrev);
  v1->mRudderOffset.m_quad.m128_i32[1] = 0;
  v1->mRudderOffset.m_quad.m128_i32[2] = (int)v2[2].mHandles.mNode.mNext;
  v1->mRudderOffset.m_quad.m128_i32[3] = 1065353216;
  v1->mBowThrusterOffset.m_quad.m128_i32[0] = (int)v2[3].mBaseNode.mNeighbours[1];
  v1->mBowThrusterOffset.m_quad.m128_i32[1] = 0;
  v1->mBowThrusterOffset.m_quad.m128_i32[2] = HIDWORD(v2[3].mBaseNode.mNeighbours[1]);
  v1->mBowThrusterOffset.m_quad.m128_i32[3] = 1065353216;
  v1->mBowThrusterCutoffSpeed = *(float *)v2[3].mBaseNode.mNeighbours * 0.27777779;
  v1->mBowThrusterPower = *((float *)v2[3].mBaseNode.mNeighbours + 1);
  v3 = (float)(*(float *)&v2[3].vfptr * 3.1415927) * 0.0055555557;
  v1->mMaxRudderAngle = v3;
  v1->mMaxRudderAngleForSpeed = v3;
  v1->mMaxEngineThrust = *((float *)&v2[3].vfptr + 1);
  v1->mEngineThrustAngle = (float)(*(float *)&v2[3].mBaseNode.mUID * 3.1415927) * 0.0055555557;
  v1->mViscousDrag = *((float *)&v2[3].mBaseNode.mUID + 1);
  v1->mViscousDragLateral = *(float *)&v2[3].mBaseNode.mParent;
  v1->mQuadraticDragLateralVelocityLimit = *((float *)&v2[3].mBaseNode.mParent + 1);
  v1->mTorqueDamping = *(float *)v2[3].mBaseNode.mChildren;
  v1->mTorqueDampingBowScale = *((float *)v2[3].mBaseNode.mChildren + 1);
  v1->mLeanFactor = *(float *)&v2[3].mBaseNode.mChildren[1];
  v1->mKeelTorque = *((float *)&v2[2].mHandles.mNode.mNext + 1);
  v1->mSteeringSensitivityMinSpeed = *((float *)&v2[1].mHandles.mNode.mNext + 1);
  v1->mSteeringSensitivityMaxSpeed = *(float *)&v2[2].vfptr;
  v1->mSteeringSensitivityHi = *(float *)&v2[1].mHandles.mNode.mNext;
  v1->mSteeringSensitivityLo = *((float *)&v2[1].mHandles.mNode.mPrev + 1);
  v1->mDollarValue = *(float *)&v2[1].mHandles.mNode.mPrev;
  v4 = v1->mReorientActionRoll;
  if ( v4 )
    v4->m_strength = v1->mRollStability;
  v5 = v1->mReorientActionPitch;
  if ( v5 )
    v5->m_strength = v1->mPitchStability;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v6);
}

// File Line: 204
// RVA: 0x4762B0
void __fastcall UFG::PhysicsBoat::Suspend(UFG::PhysicsBoat *this)
{
  UFG::BoatAction *v1; // rdx
  UFG::PhysicsBoat *v2; // rbx
  UFG::BasePhysicsSystem *v3; // rdi
  hkpRigidBody *v4; // rdx
  hkpRigidBody *v5; // rdx
  UFG::WaterFloatingTrackerComponent *v6; // rcx

  v1 = this->mBoatAction;
  v2 = this;
  if ( v1 )
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, (hkpAction *)&v1->vfptr);
  v3 = UFG::BasePhysicsSystem::mInstance;
  v4 = v2->mRigidBody->mBody;
  if ( v4 && v4->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, v4, 0);
  v5 = v2->mBulletCollider;
  if ( v5 && v5->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(v3, v5, 0);
  v6 = v2->mWaterFloatingTrackerComponent;
  if ( v6 )
    ((void (*)(void))v6->vfptr[8].__vecDelDtor)();
}

// File Line: 216
// RVA: 0x473E40
void __fastcall UFG::PhysicsBoat::Restore(UFG::PhysicsBoat *this)
{
  UFG::PhysicsBoat *v1; // rbx
  hkpAction *v2; // rdx

  v1 = this;
  UFG::PhysicsVehicle::Restore((UFG::PhysicsVehicle *)&this->vfptr);
  if ( v1->mCurrentLod != 4 )
  {
    v2 = (hkpAction *)&v1->mBoatAction->vfptr;
    if ( v2 )
    {
      if ( !v2->m_world )
        UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, v2);
    }
  }
}

// File Line: 234
// RVA: 0x479B20
void __fastcall UFG::PhysicsBoat::Update(UFG::PhysicsBoat *this, UFG::qMatrix44 *targetTransform, UFG::VehicleInput *input, float deltaTime)
{
  UFG::BasePhysicsSystem *v4; // r14
  UFG::PhysicsBoat *v5; // rdi
  UFG::VehicleInput *v6; // rbx
  UFG::RigidBodyComponent *v7; // r8
  UFG::qMatrix44 *v8; // rsi
  float v9; // xmm11_4
  hkpRigidBody *v10; // rax
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm3
  hkVector4f v13; // xmm0
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  hkpRigidBody *v16; // rcx
  hkpRigidBody *v17; // rcx
  UFG::WaterFloatingTrackerComponent *v18; // rcx
  float v19; // xmm1_4
  __m128 v20; // xmm8
  float v21; // xmm2_4
  float v22; // xmm2_4
  signed int v23; // er13
  bool v24; // cf
  bool v25; // zf
  float v26; // xmm0_4
  float v27; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm9_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  UFG::BoatAction *v35; // rax
  float v36; // xmm1_4
  signed __int64 v37; // rbx
  int v38; // eax
  float v39; // xmm1_4
  __m128 *v40; // r12
  bool *v41; // rsi
  float *v42; // r14
  hkVector4f *v43; // r15
  __m128 v44; // xmm1
  __m128 v45; // xmm4
  __m128 v46; // xmm2
  float v47; // xmm0_4
  float v48; // xmm0_4
  float v49; // xmm2_4
  float v50; // xmm0_4
  float v51; // xmm0_4
  bool v52; // al
  hkpRigidBody *v53; // rcx
  __m128 v54; // xmm1
  __m128 v55; // xmm6
  __m128 v56; // xmm6
  __m128 v57; // xmm6
  float v58; // xmm0_4
  UFG::RigidBodyComponent *v59; // rax
  hkpRigidBody *v60; // rbx
  UFG::qVector4 v61; // xmm3
  UFG::qVector4 v62; // xmm2
  UFG::qVector4 v63; // xmm1
  UFG::WorldBoundaries *v64; // rcx
  hkpRigidBody *v65; // rdx
  UFG::BoatAction *v66; // rax
  int *v67; // rdx
  int v68; // xmm1_4
  int v69; // xmm0_4
  int v70; // xmm0_4
  int v71; // xmm1_4
  __m128 v72; // xmm9
  __m128 v73; // xmm6
  float v74; // xmm11_4
  float v75; // xmm12_4
  float v76; // xmm13_4
  float v77; // xmm14_4
  __m128 v78; // xmm10
  float v79; // xmm4_4
  __m128 v80; // xmm5
  float v81; // xmm2_4
  UFG::RigidBodyComponent *v82; // rax
  float v83; // xmm4_4
  __m128 v84; // xmm3
  __m128 v85; // xmm2
  hkpRigidBody *v86; // rbx
  UFG::RigidBodyComponent *v87; // rbx
  __m128 *v88; // rax
  __m128 v89; // xmm3
  float v90; // xmm0_4
  __m128 v91; // xmm2
  __m128 v92; // xmm4
  float v93; // xmm1_4
  hkpEntity *v94; // rbx
  hkVector4f *v95; // rdx
  UFG::BoatAction *v96; // rax
  float v97; // xmm4_4
  float v98; // xmm6_4
  __m128 v99; // xmm3
  __m128 v100; // xmm2
  UFG::RigidBodyComponent *v101; // rax
  hkpRigidBody *v102; // rbx
  UFG::RigidBodyComponent *v103; // rbx
  __m128 v104; // xmm5
  __m128 v105; // xmm1
  __m128 v106; // xmm4
  __m128 v107; // xmm1
  UFG::RigidBodyComponent *v108; // rbx
  __m128 v109; // xmm3
  __m128 v110; // xmm4
  __m128 v111; // xmm2
  __m128 v112; // [rsp+30h] [rbp-B0h]
  hkVector4f centerOfMass; // [rsp+40h] [rbp-A0h]
  __m128 v114; // [rsp+50h] [rbp-90h]
  hkTransformf a; // [rsp+60h] [rbp-80h]
  float distance[2]; // [rsp+150h] [rbp+70h]
  __int64 vars0; // [rsp+160h] [rbp+80h]

  v4 = UFG::BasePhysicsSystem::mInstance;
  this->mOustideWorldBoundaries = 0;
  v5 = this;
  v6 = input;
  v7 = this->mRigidBody;
  *(_QWORD *)distance = v4;
  v8 = targetTransform;
  v9 = deltaTime;
  v10 = v7->mBody;
  v11.m_quad = (__m128)v10->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v12.m_quad = (__m128)v10->m_motion.m_motionState.m_transform.m_translation;
  v13.m_quad = (__m128)v10->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  a.m_rotation.m_col1 = v10->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  a.m_rotation.m_col0 = (hkVector4f)v11.m_quad;
  *((_DWORD *)this + 246) ^= (*((_DWORD *)this + 246) ^ (*((_DWORD *)v6 + 4) >> 5)) & 1;
  LODWORD(v10) = *((_DWORD *)this + 246);
  v14 = *((_DWORD *)v6 + 4);
  a.m_rotation.m_col0 = (hkVector4f)v13.m_quad;
  a.m_rotation.m_col1 = (hkVector4f)v12.m_quad;
  v15 = (unsigned int)v10 ^ ((unsigned __int8)v10 ^ (unsigned __int8)(v14 >> 3)) & 2;
  *((_DWORD *)v5 + 246) = v15;
  if ( v15 & 1 )
  {
    if ( v5->mIsCOMShifted )
    {
      v16 = v7->mBody;
      centerOfMass.m_quad = _mm_add_ps(
                              _mm_unpacklo_ps(
                                _mm_unpacklo_ps(
                                  _mm_xor_ps(
                                    _mm_xor_ps((__m128)LODWORD(v5->mCOMShift), (__m128)(unsigned int)_xmm[0]),
                                    (__m128)(unsigned int)_xmm[0]),
                                  (__m128)0i64),
                                (__m128)0i64),
                              v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad);
      hkpRigidBody::setCenterOfMassLocal(v16, &centerOfMass);
      v5->mIsCOMShifted = 0;
    }
  }
  else if ( !v5->mIsCOMShifted )
  {
    v17 = v7->mBody;
    centerOfMass.m_quad = _mm_add_ps(
                            _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                _mm_xor_ps((__m128)LODWORD(v5->mCOMShift), (__m128)(unsigned int)_xmm[0]),
                                (__m128)0i64),
                              (__m128)0i64),
                            v17->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad);
    hkpRigidBody::setCenterOfMassLocal(v17, &centerOfMass);
    v5->mIsCOMShifted = 1;
  }
  v18 = v5->mWaterFloatingTrackerComponent;
  if ( v18 && v18->mInWaterState > 0 )
    UFG::WaterFloatingTrackerComponent::AdjustRipple(v18);
  UFG::PhysicsVehicle::Update((UFG::PhysicsVehicle *)&v5->vfptr, v8, v6, v9);
  v19 = v5->mSpeedKPH;
  v20 = (__m128)(unsigned int)FLOAT_1_0;
  if ( v5->mCurrentLod != 4 )
  {
    if ( *((_BYTE *)v6 + 16) & 1 )
      v21 = *(float *)&FLOAT_1_0;
    else
      v21 = FLOAT_N1_0;
    v22 = v21 * v6->mGasBrakes;
    v23 = 0;
    v24 = v19 < v5->mHighSpeedGovernor;
    v25 = v19 == v5->mHighSpeedGovernor;
    v5->mThrottle = v22;
    if ( !v24 && !v25 && v22 > 0.0 || v19 < COERCE_FLOAT(LODWORD(v5->mReverseSpeedGovernor) ^ _xmm[0]) && v22 < 0.0 )
      v5->mThrottle = 0.0;
    v26 = v5->mSteeringSensitivityHi;
    v27 = v5->mSteeringSensitivityLo;
    v28 = v5->mSteeringSensitivityMinSpeed * v5->mSteeringSensitivityMinSpeed;
    if ( v27 >= v26 )
      v29 = v5->mSteeringSensitivityHi;
    else
      v29 = v5->mSteeringSensitivityLo;
    if ( v27 <= v26 )
      v30 = v5->mSteeringSensitivityHi;
    else
      v30 = v5->mSteeringSensitivityLo;
    v31 = FLOAT_0_000099999997;
    if ( (float)((float)(v5->mSteeringSensitivityMaxSpeed * v5->mSteeringSensitivityMaxSpeed) - v28) >= 0.000099999997 )
      v31 = (float)(v5->mSteeringSensitivityMaxSpeed * v5->mSteeringSensitivityMaxSpeed) - v28;
    v32 = (float)((float)((float)(v19 * v19) - v28) * (float)((float)(v26 - v27) / v31)) + v27;
    if ( v32 <= v29 )
      v32 = v29;
    if ( v32 >= v30 )
      v32 = v30;
    v33 = v32 * v5->mMaxRudderAngle;
    v34 = v5->mRudderAngle;
    v35 = v5->mBoatAction;
    v5->mMaxRudderAngleForSpeed = v33;
    v36 = v33 * v6->mSteering;
    v37 = 4i64;
    vars0 = 4i64;
    v5->mRudderAngle = (float)((float)(COERCE_FLOAT(LODWORD(v36) ^ _xmm[0]) - v34) * sRudderMotionGain) + v34;
    if ( *((_BYTE *)v35 + 56) & 1 )
    {
      v38 = UFG::qRandom(4, &UFG::qDefaultSeed);
      v39 = v5->mFloatBuoyancy[v38] - (float)(UFG::PhysicsBoat::mSinkRate * v9);
      v5->mFloatBuoyancy[v38] = v39;
      if ( v39 >= 0.0 )
        hkpEntity::activate((hkpEntity *)&v5->mRigidBody->mBody->vfptr);
      else
        v5->mFloatBuoyancy[v38] = 0.0;
    }
    v40 = (__m128 *)v5->mFloatPositionWorldSpace;
    v41 = v5->mFloatInWater;
    v42 = v5->mBuoyancyFactor;
    v43 = v5->mFloatPositionWorldSpace;
    do
    {
      hkVector4f::setTransformedPos(v43, &a, v43 - 4);
      v44 = _mm_mul_ps(*v40, *v40);
      v45 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
              _mm_shuffle_ps(v44, v44, 170));
      v46 = _mm_rsqrt_ps(v45);
      v47 = fmodf(
              (float)(COERCE_FLOAT(
                        _mm_andnot_ps(
                          _mm_cmpleps(v45, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
                              _mm_mul_ps(v46, *(__m128 *)_xmm)),
                            v45)))
                    * *(float *)(*(_QWORD *)distance + 99852i64))
            + *(float *)(*(_QWORD *)distance + 99856i64),
              6.2800002);
      v48 = cosf(v47);
      v49 = *(float *)&v40->m128_u64[1] - 0.5;
      v50 = (float)(v48 * *(float *)(*(_QWORD *)distance + 99844i64)) + *(float *)(*(_QWORD *)distance + 99840i64);
      if ( v49 < v50 )
      {
        if ( (float)(*(float *)&v40->m128_u64[1] + 0.5) > v50 )
          v51 = v50 - v49;
        else
          v51 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v51 = 0.0;
      }
      *v42 = v51;
      v52 = *v41;
      v41[4] = *v41;
      if ( *v42 <= 0.0099999998 )
      {
        *v41 = 0;
      }
      else
      {
        *v41 = 1;
        ++v23;
      }
      if ( !v52 && *v41 )
      {
        v53 = v5->mRigidBody->mBody;
        v54 = _mm_sub_ps(*v40, v53->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v55 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v54, v54, 201), v53->m_motion.m_angularVelocity.m_quad),
                _mm_mul_ps(
                  _mm_shuffle_ps(v53->m_motion.m_angularVelocity.m_quad, v53->m_motion.m_angularVelocity.m_quad, 201),
                  v54));
        v56 = _mm_add_ps(_mm_shuffle_ps(v55, v55, 201), v53->m_motion.m_linearVelocity.m_quad);
        v57 = _mm_shuffle_ps(v56, v56, 170);
        if ( v57.m128_f32[0] < UFG::PhysicsBoat::mPontoonWaterCollisionMinVelocity )
        {
          centerOfMass.m_quad = _xmm;
          v58 = UFG::GetOneOverApparentMass(v53, v43, &centerOfMass);
          v59 = v5->mRigidBody;
          v57.m128_f32[0] = (float)(v57.m128_f32[0] * (float)(1.0 / v58))
                          * UFG::PhysicsBoat::mPontoonWaterCollisionResponse;
          v112 = _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)0i64, _mm_xor_ps(v57, (__m128)(unsigned int)_xmm[0])),
                   (__m128)0i64);
          v60 = v59->mBody;
          hkpEntity::activate((hkpEntity *)&v59->mBody->vfptr);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))v60->m_motion.vfptr[11].__first_virtual_table_function__)(
            &v60->m_motion,
            &v112,
            v43);
          v37 = vars0;
        }
      }
      ++v43;
      ++v42;
      ++v40;
      ++v41;
      vars0 = --v37;
    }
    while ( v37 );
    if ( v23 >= 2 && a.m_rotation.m_col0.m_quad.m128_f32[2] < 0.38 )
    {
      *((_DWORD *)v5->mBoatAction + 14) |= 2u;
      *((_DWORD *)v5->mBoatAction + 14) |= 1u;
    }
    v61 = v5->mBodyTransform.v1;
    v62 = v5->mBodyTransform.v2;
    v4 = *(UFG::BasePhysicsSystem **)distance;
    v63 = v5->mBodyTransform.v3;
    v5->mLastGoodPosition.v0 = v5->mBodyTransform.v0;
    v5->mLastGoodPosition.v1 = v61;
    v5->mLastGoodPosition.v2 = v62;
    v5->mLastGoodPosition.v3 = v63;
  }
  if ( v5->mCurrentLod != 4 )
  {
    v64 = (UFG::WorldBoundaries *)&v4[1].mActiveRegionManager.mExtents.m_size;
    v65 = v5->mRigidBody->mBody;
    v66 = v5->mBoatAction;
    v112.m128_u64[0] = 0i64;
    v67 = (int *)&v65->m_motion.m_motionState.m_transform.m_translation;
    v112.m128_i32[2] = 0;
    v68 = v67[1];
    centerOfMass.m_quad.m128_i32[0] = *v67;
    v69 = v67[2];
    centerOfMass.m_quad.m128_i32[1] = v68;
    *((_DWORD *)v66 + 14) &= 0xFFFFFFFB;
    v25 = (*((_BYTE *)&v5->0 + 604) & 0x10) == 0;
    centerOfMass.m_quad.m128_i32[2] = v69;
    if ( v25 )
    {
      if ( !UFG::WorldBoundaries::IsOutsideBoundaries2(
              v64,
              (UFG::qVector3 *)&centerOfMass,
              25.0,
              (UFG::qVector3 *)&v112) )
        return;
      v96 = v5->mBoatAction;
      v97 = v112.m128_f32[1];
      v98 = v112.m128_f32[0];
      v5->mOustideWorldBoundaries = 1;
      *((_DWORD *)v96 + 14) |= 4u;
      v99 = (__m128)LODWORD(v5->mBodyTransform.v0.x);
      v100 = (__m128)LODWORD(v5->mBodyTransform.v0.y);
      if ( (float)((float)((float)(v5->mBodyTransform.v0.y * v97) + (float)(v5->mBodyTransform.v0.x * v98))
                 + (float)(v5->mBodyTransform.v0.z * v112.m128_f32[2])) >= 0.80000001 )
      {
        v108 = v5->mRigidBody;
        v109 = _mm_unpacklo_ps(
                 _mm_unpacklo_ps(v99, (__m128)LODWORD(v5->mBodyTransform.v0.z)),
                 _mm_unpacklo_ps(v100, (__m128)0i64));
        v110 = v108->mBody->m_motion.m_linearVelocity.m_quad;
        v111 = _mm_mul_ps(v109, v110);
        if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v111, v111, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v111, v111, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v111, v111, 170))) >= 5.0 )
          return;
        v114 = _mm_add_ps(v110, _mm_mul_ps((__m128)_xmm, v109));
        v94 = (hkpEntity *)&v108->mBody->vfptr;
        hkpEntity::activate(v94);
        v95 = (hkVector4f *)&v114;
      }
      else
      {
        v101 = v5->mRigidBody;
        v100.m128_f32[0] = (float)((float)(v100.m128_f32[0] * v98) - (float)(v99.m128_f32[0] * v97)) * -1.5;
        v114 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v100), (__m128)0i64);
        v102 = v101->mBody;
        hkpEntity::activate((hkpEntity *)&v101->mBody->vfptr);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v102->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v102->m_motion,
          &v114);
        v103 = v5->mRigidBody;
        v104 = v103->mBody->m_motion.m_linearVelocity.m_quad;
        v105 = _mm_mul_ps(v104, v104);
        v106 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v105, v105, 85), _mm_shuffle_ps(v105, v105, 0)),
                 _mm_shuffle_ps(v105, v105, 170));
        v107 = _mm_rsqrt_ps(v106);
        if ( COERCE_FLOAT(
               _mm_andnot_ps(
                 _mm_cmpleps(v106, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v107, v106), v107)),
                     _mm_mul_ps(*(__m128 *)_xmm, v107)),
                   v106))) <= 5.0 )
          return;
        centerOfMass.m_quad = _mm_mul_ps(v104, (__m128)_xmm);
        v94 = (hkpEntity *)&v103->mBody->vfptr;
        hkpEntity::activate(v94);
        v95 = &centerOfMass;
      }
    }
    else
    {
      v70 = *v67;
      v71 = v67[1];
      distance[0] = 0.0;
      v112.m128_u64[0] = 0i64;
      v112.m128_i32[2] = 0;
      centerOfMass.m_quad.m128_u64[0] = __PAIR__(v71, v70);
      centerOfMass.m_quad.m128_i32[2] = v67[2];
      if ( !UFG::WorldBoundaries::IsOutsideBoundaries(
              v64,
              (UFG::qVector3 *)&centerOfMass,
              25.0,
              (UFG::qVector3 *)&v112,
              distance) )
        return;
      v72 = (__m128)v112.m128_u32[1];
      v73 = (__m128)v112.m128_u32[0];
      v74 = v112.m128_f32[2];
      v5->mOustideWorldBoundaries = 1;
      v75 = v5->mBodyTransform.v0.x;
      v76 = v5->mBodyTransform.v0.y;
      v77 = v5->mBodyTransform.v0.z;
      if ( (float)((float)((float)(v5->mBodyTransform.v0.y * v72.m128_f32[0])
                         + (float)(v5->mBodyTransform.v0.x * v73.m128_f32[0]))
                 + (float)(v5->mBodyTransform.v0.z * v74)) < 0.0 )
      {
        v78 = v72;
        v80 = v73;
        v78.m128_f32[0] = v72.m128_f32[0] - (float)(v74 * 0.0);
        v79 = (float)(v74 * 0.0) - v73.m128_f32[0];
        v80.m128_f32[0] = (float)(v73.m128_f32[0] * 0.0) - (float)(v72.m128_f32[0] * 0.0);
        v81 = (float)((float)(v79 * v76) + (float)(v78.m128_f32[0] * v75)) + (float)(v80.m128_f32[0] * v77);
        if ( v81 <= 0.0 )
        {
          if ( v81 >= 0.0 )
            v20 = 0i64;
          else
            v20 = (__m128)LODWORD(FLOAT_N1_0);
        }
        v82 = v5->mRigidBody;
        v83 = v79 * v20.m128_f32[0];
        v80.m128_f32[0] = v80.m128_f32[0] * v20.m128_f32[0];
        v84 = v80;
        v78.m128_f32[0] = v78.m128_f32[0] * v20.m128_f32[0];
        v85 = v78;
        v84.m128_f32[0] = (float)(v80.m128_f32[0] * v76) - (float)(v83 * v77);
        v85.m128_f32[0] = (float)(v78.m128_f32[0] * v77) - (float)(v80.m128_f32[0] * v75);
        v20.m128_f32[0] = (float)(v20.m128_f32[0] * 0.30000001)
                        + (float)((float)(v83 * v75) - (float)(v78.m128_f32[0] * v76));
        v114 = _mm_unpacklo_ps(_mm_unpacklo_ps(v84, v20), _mm_unpacklo_ps(v85, (__m128)0i64));
        v86 = v82->mBody;
        hkpEntity::activate((hkpEntity *)&v82->mBody->vfptr);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v86->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v86->m_motion,
          &v114);
      }
      v87 = v5->mRigidBody;
      v88 = (__m128 *)v87->mBody;
      v89 = v88[35];
      v90 = COERCE_FLOAT(*(_OWORD *)&v88[35]) * v73.m128_f32[0];
      v91 = _mm_shuffle_ps(v89, v89, 85);
      v92 = _mm_shuffle_ps(v88[35], v89, 170);
      v112 = v88[35];
      v93 = (float)((float)(v91.m128_f32[0] * v72.m128_f32[0]) + v90) + (float)(v92.m128_f32[0] * v74);
      if ( v93 < 0.0 && distance[0] < 4.0 )
      {
        v89.m128_f32[0] = v89.m128_f32[0] - (float)(v73.m128_f32[0] * v93);
        v92.m128_f32[0] = v92.m128_f32[0] - (float)(v74 * v93);
        v91.m128_f32[0] = v91.m128_f32[0] - (float)(v72.m128_f32[0] * v93);
        v112 = _mm_unpacklo_ps(_mm_unpacklo_ps(v89, v92), _mm_unpacklo_ps(v91, (__m128)0i64));
      }
      v94 = (hkpEntity *)&v87->mBody->vfptr;
      hkpEntity::activate(v94);
      v95 = (hkVector4f *)&v112;
    }
    v94->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v94->m_motion.vfptr, (unsigned int)v95);
  }
}

// File Line: 463
// RVA: 0x46EA30
void __fastcall UFG::PhysicsBoat::OnEnterWater(UFG::PhysicsBoat *this)
{
  hkpRigidBody *v1; // rcx
  float v2; // xmm6_4
  float v3; // xmm7_4
  float v4; // xmm8_4
  float v5; // xmm9_4
  int v6; // [rsp+20h] [rbp-41h]
  float v7; // [rsp+24h] [rbp-3Dh]
  float v8; // [rsp+28h] [rbp-39h]
  float v9; // [rsp+2Ch] [rbp-35h]
  UFG::qMatrix44 transform; // [rsp+38h] [rbp-29h]
  UFG::OneShot *retaddr; // [rsp+C8h] [rbp+67h]

  *((_DWORD *)this + 246) &= 0xFFFFFFFB;
  v1 = this->mRigidBody->mBody;
  v2 = v1->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[0];
  v3 = v1->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1];
  v4 = v1->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[2];
  v5 = v1->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[3];
  v6 = v1->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_i32[0];
  v7 = v3;
  v8 = v4;
  v9 = v5;
  if ( UFG::TiDo::Distance2FromListener(UFG::TiDo::m_pInstance, 0, (UFG::qVector4 *)&v6) <= 400.0 )
  {
    retaddr = 0i64;
    transform.v0 = UFG::qMatrix44::msIdentity.v0;
    transform.v1 = UFG::qMatrix44::msIdentity.v1;
    transform.v2 = UFG::qMatrix44::msIdentity.v2;
    transform.v3.x = v2;
    transform.v3.y = v3;
    transform.v3.z = v4;
    transform.v3.w = v5;
    UFG::OneShotPool::GetOneShotHandle((UFG::OneShotHandle *)&retaddr, &transform);
    if ( UFG::OneShotHandle::IsValid((UFG::OneShotHandle *)&retaddr) )
      UFG::OneShot::Play(retaddr, 0x4FEB6CE0u);
    UFG::OneShotHandle::Release((UFG::OneShotHandle *)&retaddr);
  }
}

// File Line: 488
// RVA: 0x46EC40
void __fastcall UFG::PhysicsBoat::OnExitWater(UFG::PhysicsBoat *this)
{
  *((_DWORD *)this + 246) |= 4u;
}

// File Line: 495
// RVA: 0x466810
float __fastcall UFG::PhysicsBoat::GetFloatBuoyancy(UFG::PhysicsBoat *this, unsigned int index)
{
  return this->mBuoyancyFactor[index];
}

// File Line: 520
// RVA: 0x466A90
float __fastcall UFG::PhysicsBoat::GetLeanAngle(UFG::PhysicsBoat *this)
{
  hkpRigidBody *v1; // rdx
  __m128 v2; // xmm1
  __m128 v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm1

  v1 = this->mRigidBody->mBody;
  v2 = _mm_mul_ps(v1->m_motion.m_linearVelocity.m_quad, v1->m_motion.m_linearVelocity.m_quad);
  v3 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)), _mm_shuffle_ps(v2, v2, 170));
  v4 = _mm_rsqrt_ps(v3);
  v5 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v4, v3), v4));
  v6 = _mm_mul_ps(*(__m128 *)_xmm, v4);
  v7 = _mm_mul_ps(_xmm, v1->m_motion.m_angularVelocity.m_quad);
  return atanf(
           (float)((float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 0)))
                         + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170)))
                 * this->mLeanFactor)
         / (float)(fsqrt(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                        COERCE_FLOAT(
                                          _mm_andnot_ps(
                                            _mm_cmpleps(v3, (__m128)0i64),
                                            _mm_mul_ps(_mm_mul_ps(v5, v6), v3)))
                                      * 0.25) & _xmm))
                 + 1.0))
       * 0.5;
}

// File Line: 534
// RVA: 0x467080
float __fastcall UFG::PhysicsBoat::GetRudderAngle(UFG::PhysicsBoat *this)
{
  return this->mRudderAngle;
}

// File Line: 541
// RVA: 0x474C40
void __fastcall UFG::PhysicsBoat::SetEngineDamage(UFG::PhysicsBoat *this, float damage)
{
  UFG::BoatAction *v2; // rdx
  int v3; // eax

  this->mEngineDamage = damage;
  if ( damage < 1.0 )
  {
    v2 = this->mBoatAction;
    v3 = *((_DWORD *)v2 + 14);
    if ( !(v3 & 2) )
      *((_DWORD *)v2 + 14) = v3 & 0xFFFFFFFE;
  }
  else
  {
    *((_DWORD *)this->mBoatAction + 14) |= 1u;
  }
}

// File Line: 562
// RVA: 0x460360
void __fastcall UFG::PhysicsBoat::DebugDraw(UFG::PhysicsBoat *this)
{
  hkVector4f *v1; // rbx
  float *v2; // rsi
  float *v3; // rdi
  signed __int64 v4; // r15
  Render::DebugDrawContext *v5; // r14
  int v6; // xmm1_4
  int v7; // xmm0_4
  int v8; // xmm1_4
  int v9; // xmm0_4
  int v10; // xmm0_4
  int v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  int v15; // xmm1_4
  float v16; // xmm0_4
  int v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  double v21; // xmm1_8
  float v22; // xmm2_4
  unsigned __int64 v23; // rcx
  hkVector4f *v24; // rax
  hkVector4f v25; // xmm2
  hkVector4f v26; // xmm3
  hkVector4f v27; // xmm0
  __m128 *v28; // rax
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  float v37; // xmm4_4
  float v38; // xmm6_4
  float v39; // xmm8_4
  float v40; // xmm10_4
  float v41; // xmm9_4
  float v42; // xmm7_4
  float v43; // xmm12_4
  float v44; // xmm11_4
  float v45; // xmm6_4
  UFG::qVector3 world_position; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 v47; // [rsp+50h] [rbp-98h]
  UFG::qVector3 p0; // [rsp+60h] [rbp-88h]
  int v49; // [rsp+6Ch] [rbp-7Ch]
  UFG::qVector3 aabb_max; // [rsp+70h] [rbp-78h]
  int v51; // [rsp+7Ch] [rbp-6Ch]
  int v52; // [rsp+80h] [rbp-68h]
  int v53; // [rsp+84h] [rbp-64h]
  int v54; // [rsp+88h] [rbp-60h]
  int v55; // [rsp+8Ch] [rbp-5Ch]
  int v56; // [rsp+90h] [rbp-58h]
  int v57; // [rsp+94h] [rbp-54h]
  int v58; // [rsp+98h] [rbp-50h]
  int v59; // [rsp+9Ch] [rbp-4Ch]
  int v60; // [rsp+A0h] [rbp-48h]
  int v61; // [rsp+A4h] [rbp-44h]
  float v62; // [rsp+A8h] [rbp-40h]
  float v63; // [rsp+ACh] [rbp-3Ch]
  float v64; // [rsp+B0h] [rbp-38h]
  int v65; // [rsp+B4h] [rbp-34h]
  hkVector4f v66; // [rsp+B8h] [rbp-30h]
  hkVector4f v67; // [rsp+C8h] [rbp-20h]
  hkTransformf a; // [rsp+D8h] [rbp-10h]

  v1 = (hkVector4f *)this;
  v2 = this->mBuoyancyFactor;
  v3 = &this->mFloatPositionWorldSpace[0].m_quad.m128_f32[2];
  v4 = 4i64;
  v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  do
  {
    v6 = v1[16].m_quad.m128_i32[1];
    aabb_max.z = v1[16].m_quad.m128_f32[0];
    v7 = v1[16].m_quad.m128_i32[2];
    v51 = v6;
    v65 = 1065353216;
    v8 = v1[16].m_quad.m128_i32[3];
    v52 = v7;
    v9 = v1[17].m_quad.m128_i32[0];
    aabb_max.x = 0.5;
    aabb_max.y = 0.5;
    aabb_max.z = 0.5;
    v54 = v9;
    v10 = v1[17].m_quad.m128_i32[2];
    v53 = v8;
    v51 = -1090519040;
    p0.z = -0.5;
    v49 = -1090519040;
    v11 = v1[17].m_quad.m128_i32[1];
    v56 = v10;
    v12 = v1[18].m_quad.m128_i32[0];
    v55 = v11;
    v13 = v1[17].m_quad.m128_i32[3];
    v58 = v12;
    v14 = v1[18].m_quad.m128_i32[2];
    v57 = v13;
    v15 = v1[18].m_quad.m128_i32[1];
    v60 = v14;
    v16 = *(v3 - 2);
    v59 = v15;
    v17 = v1[18].m_quad.m128_i32[3];
    v62 = v16;
    v18 = *v3;
    v61 = v17;
    v19 = *(v3 - 1);
    v64 = v18;
    v63 = v19;
    Render::DebugDrawContext::DrawAABB(
      v5,
      (UFG::qVector3 *)&v51,
      &aabb_max,
      &UFG::qColour::Green,
      (UFG::qMatrix44 *)&aabb_max.z,
      0i64);
    v20 = *(v2 - 8);
    world_position.y = v63;
    v21 = v20;
    v22 = v20 * *v2;
    world_position.x = v62;
    world_position.z = v64;
    Render::DebugDrawContext::DrawText(v5, &world_position, &UFG::qColour::Red, "buoyancy %f / %f", v22, v21);
    v3 += 4;
    ++v2;
    --v4;
  }
  while ( v4 );
  v23 = v1[6].m_quad.m128_u64[0];
  v24 = *(hkVector4f **)(v23 + 168);
  v25.m_quad = (__m128)v24[25];
  v26.m_quad = (__m128)v24[26];
  v27.m_quad = (__m128)v24[23];
  a.m_rotation.m_col1 = (hkVector4f)v24[24].m_quad;
  a.m_translation = (hkVector4f)v26.m_quad;
  a.m_rotation.m_col0 = (hkVector4f)v27.m_quad;
  a.m_rotation.m_col2 = (hkVector4f)v25.m_quad;
  v28 = *(__m128 **)(v23 + 168);
  v29 = _mm_mul_ps(v28[35], v28[35]);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32 = _mm_cmpleps(v30, (__m128)0i64);
  v33 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31));
  v34 = _mm_mul_ps(*(__m128 *)_xmm, v31);
  v35 = _mm_mul_ps(_xmm, v28[36]);
  v36 = _mm_mul_ps(_mm_mul_ps(v33, v34), v30);
  v37 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 170)))
      * v1[57].m_quad.m128_f32[0];
  v30.m128_i32[0] = v1[19].m_quad.m128_i32[2];
  v32.m128_i32[0] = (unsigned __int128)_mm_andnot_ps(v32, v36);
  v36.m128_i32[0] = v1[19].m_quad.m128_i32[1];
  world_position.x = v1[19].m_quad.m128_f32[0];
  LODWORD(world_position.y) = v36.m128_i32[0];
  world_position.z = v30.m128_f32[0] + 1.0;
  v34.m128_f32[0] = atanf(v37 / (float)(fsqrt(COERCE_FLOAT(COERCE_UNSIGNED_INT(v32.m128_f32[0] * 0.25) & _xmm)) + 1.0));
  Render::DebugDrawContext::DrawText(
    v5,
    &world_position,
    &UFG::qColour::White,
    "leanAngle %f",
    (float)(v34.m128_f32[0] * 0.5));
  hkVector4f::setTransformedPos(&v66, &a, v1 + 51);
  v38 = v1[53].m_quad.m128_f32[3];
  v39 = v66.m_quad.m128_f32[0];
  v34.m128_i32[0] = v1[53].m_quad.m128_i32[3];
  v40 = v66.m_quad.m128_f32[2] + 1.5;
  v41 = v66.m_quad.m128_f32[1];
  *(_QWORD *)&p0.x = v66.m_quad.m128_u64[0];
  p0.z = v66.m_quad.m128_f32[2] + 1.5;
  LODWORD(v42) = COERCE_UNSIGNED_INT(cosf(v34.m128_f32[0])) ^ _xmm[0];
  v34.m128_f32[0] = sinf(v38);
  v43 = (float)((float)(v34.m128_f32[0] * v1[17].m_quad.m128_f32[2]) + (float)(v42 * v1[16].m_quad.m128_f32[2]))
      + (float)(v1[18].m_quad.m128_f32[2] * 0.0);
  v44 = (float)((float)(v34.m128_f32[0] * v1[17].m_quad.m128_f32[0]) + (float)(v42 * v1[16].m_quad.m128_f32[0]))
      + (float)(v1[18].m_quad.m128_f32[0] * 0.0);
  v45 = (float)((float)(v34.m128_f32[0] * v1[17].m_quad.m128_f32[1]) + (float)(v42 * v1[16].m_quad.m128_f32[1]))
      + (float)(v1[18].m_quad.m128_f32[1] * 0.0);
  world_position.z = v43 + v40;
  world_position.x = v39 + v44;
  world_position.y = v41 + v45;
  Render::DebugDrawContext::DrawLine(
    v5,
    &p0,
    &world_position,
    &UFG::qColour::Green,
    &UFG::qMatrix44::msIdentity,
    0i64,
    0);
  hkVector4f::setTransformedPos(&v67, &a, v1 + 52);
  *(_QWORD *)&v47.x = v67.m_quad.m128_u64[0];
  world_position.z = v43 + (float)(v67.m_quad.m128_f32[2] + 1.5);
  v47.z = v67.m_quad.m128_f32[2] + 1.5;
  world_position.x = v67.m_quad.m128_f32[0] + v44;
  world_position.y = v67.m_quad.m128_f32[1] + v45;
  Render::DebugDrawContext::DrawLine(
    v5,
    &v47,
    &world_position,
    &UFG::qColour::Green,
    &UFG::qMatrix44::msIdentity,
    0i64,
    0);
}

// File Line: 621
// RVA: 0x474CB0
void __fastcall UFG::PhysicsBoat::SetLevelOfDetailInternal(UFG::PhysicsBoat *this, UFG::PhysicsVehicle::Lod lod)
{
  if ( (signed int)lod > 0 )
  {
    if ( (signed int)lod <= 2 )
    {
LABEL_5:
      UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, (hkpAction *)&this->mBoatAction->vfptr);
      return;
    }
    if ( lod == 3 )
    {
      UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, (hkpAction *)&this->mBoatAction->vfptr);
    }
    else if ( lod == 4 )
    {
      goto LABEL_5;
    }
  }
}

// File Line: 684
// RVA: 0x481260
void __usercall UFG::BoatAction::applyAction(UFG::BoatAction *this@<rcx>, hkStepInfo *stepInfo@<rdx>, __m128 a3@<xmm7>)
{
  UFG::PhysicsBoat *v3; // rbx
  __m128 v4; // xmm6
  UFG::BoatAction *v5; // rdi
  hkStepInfo *v6; // r12
  float *v7; // rsi
  hkpRigidBody *v8; // r14
  hkVector4f v9; // xmm3
  __int128 v10; // xmm2
  hkVector4f v11; // xmm0
  __m128 v12; // xmm15
  __m128 v13; // xmm0
  __m128 v14; // xmm14
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  float v18; // xmm11_4
  __m128 v19; // xmm1
  float v20; // xmm8_4
  __m128 v21; // xmm1
  float v22; // xmm8_4
  __m128 v23; // xmm7
  __m128 v24; // xmm10
  __m128 v25; // xmm0
  __m128 v26; // xmm6
  __m128 v27; // xmm0
  float v28; // xmm2_4
  UFG::PhysicsBoat *v29; // rax
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm1
  __m128 v35; // xmm5
  __m128 v36; // xmm4
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  int v40; // eax
  __m128 v41; // xmm6
  __int64 v42; // rdx
  UFG::PhysicsBoat *v43; // rbx
  __m128 v44; // xmm1
  __m128 v45; // xmm7
  __m128 v46; // xmm5
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  float v49; // xmm4_4
  __m128 v50; // xmm1
  float v51; // xmm2_4
  int v52; // eax
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm2
  float v58; // xmm0_4
  float v59; // xmm0_4
  float v60; // xmm1_4
  __m128 v61; // xmm0
  float v62; // xmm2_4
  float v63; // xmm1_4
  __m128 v64; // xmm6
  __int64 v65; // rdx
  float v66; // xmm6_4
  hkVector4f *v67; // r8
  float *v68; // rax
  float v69; // xmm0_4
  float v70; // xmm1_4
  float v71; // xmm8_4
  __m128 v72; // xmm0
  __m128 v73; // xmm6
  __m128 v74; // xmm0
  __m128 v75; // xmm0
  __m128 v76; // xmm6
  __int64 v77; // rdx
  UFG::PhysicsBoat *v78; // rax
  signed __int64 v79; // r13
  signed __int64 v80; // rcx
  signed __int64 v81; // rsi
  signed __int64 v82; // r15
  float v83; // xmm0_4
  __m128 v84; // xmm1
  __m128 v85; // xmm3
  __m128 v86; // xmm2
  UFG::PhysicsBoat *v87; // rax
  __m128 v88; // xmm0
  __m128 v89; // xmm3
  __m128 v90; // xmm0
  __m128 v91; // xmm2
  __m128 v92; // xmm1
  __m128 v93; // xmm2
  __m128 v94; // xmm0
  __m128 v95; // xmm2
  __m128 v96; // xmm6
  signed __int64 v97; // rbx
  __int64 v98; // rdx
  bool v99; // zf
  signed __int64 v100; // r13
  UFG::PhysicsBoat *v101; // rax
  __m128 v102; // xmm0
  UFG::PhysicsBoat *v103; // rax
  UFG::PhysicsBoat *v104; // rax
  float v105; // xmm6_4
  float v106; // xmm8_4
  __m128 v107; // xmm10
  float v108; // xmm0_4
  bool v109; // cf
  UFG::PhysicsBoat *v110; // rax
  __m128 v111; // xmm15
  __m128 v112; // xmm1
  __m128 v113; // xmm2
  __m128 v114; // xmm3
  __m128 v115; // xmm1
  __m128 v116; // xmm11
  __m128 v117; // xmm11
  __m128 v118; // xmm1
  __m128 v119; // xmm3
  __m128 v120; // xmm2
  __m128 v121; // xmm11
  __m128 v122; // xmm2
  __m128 v123; // xmm9
  __m128 v124; // xmm7
  __m128 v125; // xmm6
  __m128 v126; // xmm2
  __m128 v127; // xmm5
  __m128 v128; // xmm4
  __m128 v129; // xmm3
  __m128 v130; // xmm2
  __m128 v131; // xmm4
  __m128 v132; // xmm4
  __m128 v133; // xmm1
  __m128 v134; // xmm2
  __m128 v135; // xmm1
  __m128 v136; // xmm3
  __m128 v137; // xmm0
  __m128 v138; // xmm2
  hkpReorientAction *v139; // rcx
  __m128 v140; // xmm0
  __m128 v141; // xmm3
  signed __int64 v142; // r15
  UFG::PhysicsBoat *v143; // rax
  __m128 v144; // xmm0
  __m128 v145; // xmm6
  signed __int64 v146; // rbx
  __int64 v147; // rdx
  UFG::qNoise<float,float> *v148; // rcx
  UFG::qNoise<float,float> *v149; // rbx
  __m128 v150; // xmm0
  __m128 v151; // xmm2
  __m128 v152; // xmm1
  __m128 v153; // xmm8
  float v154; // xmm7_4
  __m128 v155; // xmm1
  float v156; // xmm1_4
  __m128 *v157; // rax
  hkpReorientAction *v158; // rcx
  UFG::PhysicsBoat *v159; // rax
  __m128 v160; // xmm0
  float v161; // xmm1_4
  UFG::PhysicsBoat *v162; // rcx
  int v163; // eax
  UFG::PhysicsBoat *v164; // rax
  __int128 v165; // xmm6
  __int64 v166; // rdx
  __int128 v167; // xmm6
  __int64 v168; // rdx
  hkVector4f v169; // [rsp+20h] [rbp-B8h]
  hkVector4f v170; // [rsp+30h] [rbp-A8h]
  __m128 v171; // [rsp+40h] [rbp-98h]
  __m256i v172; // [rsp+50h] [rbp-88h]
  hkVector4f v173; // [rsp+70h] [rbp-68h]
  hkVector4f direction; // [rsp+88h] [rbp-50h]
  __m128 v175; // [rsp+98h] [rbp-40h]
  hkMatrix3f a; // [rsp+A8h] [rbp-30h]
  __int128 v177; // [rsp+D8h] [rbp+0h]
  hkVector4f b; // [rsp+E8h] [rbp+10h]
  hkVector4f axis; // [rsp+F8h] [rbp+20h]
  hkVector4f v180; // [rsp+108h] [rbp+30h]
  hkRotationf v181; // [rsp+118h] [rbp+40h]
  float X[2]; // [rsp+238h] [rbp+160h]
  float angle; // [rsp+240h] [rbp+168h]
  __int64 v184; // [rsp+248h] [rbp+170h]
  __int64 vars0; // [rsp+250h] [rbp+178h]

  v4 = _xmm;
  v5 = this;
  v3 = this->mBoat;
  v6 = stepInfo;
  v7 = (float *)UFG::BasePhysicsSystem::mInstance;
  v8 = v3->mRigidBody->mBody;
  v171 = 0i64;
  *(_OWORD *)&v172.m256i_u64[2] = 0i64;
  v9.m_quad = (__m128)v8->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  v10 = (__int128)v8->m_motion.m_motionState.m_transform.m_translation;
  v11.m_quad = (__m128)v8->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  a.m_col2 = v8->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  *(hkVector4f *)&v172.m256i_u64[1] = (hkVector4f)v9.m_quad;
  v172.m256i_i32[5] = 0;
  v12 = *(__m128 *)&v172.m256i_u64[1];
  a.m_col1 = (hkVector4f)v11.m_quad;
  a.m_col0 = (hkVector4f)v9.m_quad;
  v177 = v10;
  v13 = v8->m_motion.m_linearVelocity.m_quad;
  direction.m_quad = _xmm;
  v173.m_quad = v13;
  v173.m_quad.m128_i32[3] = 0;
  v14 = v173.m_quad;
  v15 = _mm_mul_ps(v173.m_quad, v173.m_quad);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  LODWORD(v18) = (unsigned __int128)_mm_andnot_ps(
                                      _mm_cmpleps(v16, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                                          _mm_mul_ps(v17, *(__m128 *)_xmm)),
                                        v16));
  v19 = _mm_mul_ps(*(__m128 *)&v172.m256i_u64[1], v173.m_quad);
  LODWORD(v20) = (unsigned __int128)_mm_shuffle_ps(v19, v19, 85);
  v13.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps(v19, v19, 0);
  v21 = _mm_shuffle_ps(v19, v19, 170);
  v22 = (float)(v20 + v13.m128_f32[0]) + v21.m128_f32[0];
  a3.m128_f32[0] = v22;
  v23 = _mm_mul_ps(_mm_shuffle_ps(a3, a3, 0), *(__m128 *)&v172.m256i_u64[1]);
  v24 = _mm_sub_ps(v173.m_quad, v23);
  *(__m128 *)v172.m256i_i8 = v24;
  LODWORD(angle) = COERCE_UNSIGNED_INT(UFG::PhysicsBoat::GetLeanAngle(v3)) ^ _xmm[0];
  if ( (float)((float)((float)(v3->mBuoyancyFactor[1] + v3->mBuoyancyFactor[0]) + v3->mBuoyancyFactor[2])
             + v3->mBuoyancyFactor[3]) >= 0.1 )
  {
    X[0] = v3->mRudderAngle;
    v25 = (__m128)LODWORD(X[0]);
    v25.m128_f32[0] = cosf(X[0]);
    v26 = v25;
    v27 = (__m128)LODWORD(X[0]);
    v27.m128_f32[0] = sinf(X[0]);
    axis.m_quad = _xmm;
    b.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps(_mm_xor_ps(v26, (__m128)(unsigned int)_xmm[0]), (__m128)0i64),
                 _mm_unpacklo_ps(v27, (__m128)0i64));
    v28 = v3->mEngineThrustAngle;
    if ( v3->mThrottle < 0.0 )
      v28 = 0.0;
    hkRotationf::setAxisAngle(&v181, &axis, v28);
    hkVector4f::setRotatedDir((hkVector4f *)&v172.m256i_u64[1], (hkMatrix3f *)&v181.m_col0, &b);
    hkVector4f::setRotatedDir((hkVector4f *)&v172.m256i_u64[1], &a, (hkVector4f *)&v172.m256i_u64[1]);
    hkVector4f::setRotatedDir(&v180, &a, &b);
    hkVector4f::setTransformedPos(&v173, (hkTransformf *)&a, &v5->mBoat->mRudderOffset);
    v29 = v5->mBoat;
    v30 = _mm_shuffle_ps(v180.m_quad, v180.m_quad, 201);
    v31 = _mm_sub_ps(_mm_mul_ps(v12, v30), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v180.m_quad));
    v32 = _mm_shuffle_ps(v31, v31, 201);
    v33 = _mm_sub_ps(_mm_mul_ps(v32, v180.m_quad), _mm_mul_ps(v32, v30));
    v34 = _mm_mul_ps(v23, v23);
    v35 = _mm_shuffle_ps(v33, v33, 201);
    v175 = v35;
    v36 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    v37 = _mm_rsqrt_ps(v36);
    v38 = 0i64;
    v38.m128_f32[0] = fsqrt(
                        COERCE_FLOAT(
                          _mm_andnot_ps(
                            _mm_cmpleps(v36, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                                _mm_mul_ps(v37, *(__m128 *)_xmm)),
                              v36))));
    if ( v22 >= 0.0 )
    {
      v39 = _mm_xor_ps((__m128)LODWORD(v29->mRudderForceMultiplier), (__m128)(unsigned int)_xmm[0]);
    }
    else
    {
      v39 = (__m128)LODWORD(UFG::PhysicsBoat::mRudderExtraMultiplierWhenGoingBackwards);
      v39.m128_f32[0] = UFG::PhysicsBoat::mRudderExtraMultiplierWhenGoingBackwards * v29->mRudderForceMultiplier;
    }
    v40 = *((_DWORD *)v5 + 14);
    v39.m128_f32[0] = v39.m128_f32[0] * v38.m128_f32[0];
    v175 = _mm_mul_ps(v35, _mm_shuffle_ps(v39, v39, 0));
    if ( !(v40 & 4) && !(v40 & 1) )
    {
      v41 = (__m128)LODWORD(v6->m_deltaTime.m_storage);
      hkpEntity::activate((hkpEntity *)&v8->vfptr);
      v38 = v41;
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, hkVector4f *))v8->m_motion.vfptr[12].__first_virtual_table_function__)(
        &v8->m_motion,
        v42,
        &v175,
        &v173);
    }
    v43 = v5->mBoat;
    v38.m128_f32[0] = COERCE_FLOAT(LODWORD(v43->mViscousDrag) ^ _xmm[0]);
    v44 = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v23);
    v45 = _mm_mul_ps(v24, v24);
    v46 = _mm_add_ps(v171, v44);
    v171 = v46;
    v47 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
            _mm_shuffle_ps(v45, v45, 170));
    v48 = _mm_rsqrt_ps(v47);
    LODWORD(v49) = (unsigned __int128)_mm_andnot_ps(
                                        _mm_cmpleps(v47, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                                            _mm_mul_ps(v48, *(__m128 *)_xmm)),
                                          v47));
    v50 = (__m128)LODWORD(v43->mViscousDragLateral);
    if ( (*((_DWORD *)v43 + 246) >> 1) & 1 )
      v50.m128_f32[0] = v50.m128_f32[0] * 0.1;
    v51 = v43->mQuadraticDragLateralVelocityLimit;
    if ( v49 < v51 || (*((_DWORD *)v43 + 246) >> 1) & 1 )
      v50 = _mm_xor_ps(v50, (__m128)(unsigned int)_xmm[0]);
    else
      v50.m128_f32[0] = COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                       (float)((float)((float)((float)(v49 - v51) * (float)(v49 - v51)) + v51) / v49)
                                     * v50.m128_f32[0]) ^ _xmm[0]);
    v52 = *((_DWORD *)v5 + 14);
    v53 = _mm_shuffle_ps(v12, v12, 85);
    v171 = _mm_add_ps(v46, _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v24));
    v54 = 0i64;
    v53.m128_f32[0] = (float)((float)(v53.m128_f32[0] * v14.m128_f32[0])
                            - (float)(v12.m128_f32[0] * COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 85))))
                    * v43->mKeelTorque;
    *(__m128 *)&v172.m256i_u64[2] = _mm_add_ps(
                                      *(__m128 *)&v172.m256i_u64[2],
                                      _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v53), (__m128)0i64));
    if ( !(v52 & 4) && !(v52 & 1) )
    {
      v55 = _mm_mul_ps(v173.m_quad, v173.m_quad);
      v56 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
              _mm_shuffle_ps(v55, v55, 170));
      v57 = _mm_rsqrt_ps(v56);
      v54 = (__m128)LODWORD(FLOAT_6_2800002);
      v58 = fmodf(
              (float)(COERCE_FLOAT(
                        _mm_andnot_ps(
                          _mm_cmpleps(v56, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v57, v56), v57)),
                              _mm_mul_ps(v57, *(__m128 *)_xmm)),
                            v56)))
                    * v7[24963])
            + v7[24964],
              6.2800002);
      v59 = cosf(v58);
      if ( v173.m_quad.m128_f32[2] <= (float)((float)(v59 * v7[24961]) + v7[24960]) )
      {
        v60 = v43->mEngineDamage;
        v61 = (__m128)(unsigned int)FLOAT_1_0;
        if ( v60 >= 0.80000001 )
          v61.m128_f32[0] = 1.0 - v60;
        v62 = v43->mBuoyancyFactor[1] + v43->mBuoyancyFactor[0];
        v63 = (float)(v43->mMaxEngineThrust * v43->mThrottle) * v61.m128_f32[0];
        if ( v62 <= 0.1 )
        {
          v61 = (__m128)LODWORD(v43->mBuoyancyFactor[3]);
          if ( (float)(v62 * 2.0) < (float)(v61.m128_f32[0] + v43->mBuoyancyFactor[2]) )
            v63 = v63 * 0.5;
        }
        v64 = (__m128)LODWORD(v6->m_deltaTime.m_storage);
        v61.m128_f32[0] = COERCE_FLOAT(LODWORD(v63) ^ _xmm[0]);
        v170.m_quad = _mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), *(__m128 *)&v172.m256i_u64[1]);
        hkpEntity::activate((hkpEntity *)&v8->vfptr);
        v54 = v64;
        ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, hkVector4f *))v8->m_motion.vfptr[12].__first_virtual_table_function__)(
          &v8->m_motion,
          v65,
          &v170,
          &v173);
      }
      v66 = X[0];
      if ( COERCE_FLOAT(LODWORD(X[0]) & _xmm) > 0.087266468 && v22 >= 0.0 )
      {
        v67 = (hkVector4f *)v5->mBoat;
        if ( v67[61].m_quad.m128_i8[8] & 1 || v22 < v67[53].m_quad.m128_f32[0] )
        {
          hkVector4f::setTransformedPos((hkVector4f *)((char *)&v173 + 8), (hkTransformf *)&a, v67 + 52);
          v68 = (float *)v5->mBoat;
          v69 = *(float *)&FLOAT_1_0;
          v70 = v68[214];
          if ( v70 >= 0.80000001 )
            v69 = 1.0 - v70;
          v71 = (float)((float)(v68[220] * v68[216]) * v69) * v68[213];
          if ( v66 <= 0.0 )
            v72 = (__m128)LODWORD(FLOAT_1_5707964);
          else
            v72 = (__m128)LODWORD(FLOAT_N1_5707964);
          X[0] = v72.m128_f32[0];
          v72.m128_f32[0] = cosf(v72.m128_f32[0]);
          v73 = v72;
          v74 = (__m128)LODWORD(X[0]);
          v74.m128_f32[0] = sinf(X[0]);
          v75 = _mm_unpacklo_ps(v74, (__m128)0i64);
          v170.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(_mm_xor_ps(v73, (__m128)(unsigned int)_xmm[0]), (__m128)0i64),
                          v75);
          hkVector4f::setRotatedDir(&v169, &a, &v170);
          v76 = (__m128)LODWORD(v6->m_deltaTime.m_storage);
          v75.m128_f32[0] = COERCE_FLOAT(LODWORD(v71) ^ _xmm[0]);
          *(__m128 *)&v172.m256i_u64[3] = _mm_mul_ps(_mm_shuffle_ps(v75, v75, 0), v169.m_quad);
          hkpEntity::activate((hkpEntity *)&v8->vfptr);
          v54 = v76;
          ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, unsigned __int64 *, unsigned __int16 *))v8->m_motion.vfptr[12].__first_virtual_table_function__)(
            &v8->m_motion,
            v77,
            &v172.m256i_u64[3],
            &v173.m_quad.m128_u16[4]);
        }
      }
    }
    v78 = v5->mBoat;
    v79 = 688i64;
    v80 = 688i64;
    v81 = (signed __int64)&v8->m_motion;
    v82 = 784i64;
    v83 = v78->mTorqueDamping;
    *(_QWORD *)X = 688i64;
    v54.m128_f32[0] = COERCE_FLOAT(LODWORD(v83) ^ _xmm[0]);
    *(__m128 *)&v172.m256i_u64[2] = _mm_add_ps(
                                      *(__m128 *)&v172.m256i_u64[2],
                                      _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), v8->m_motion.m_angularVelocity.m_quad));
    v84 = _mm_mul_ps(a.m_col1.m_quad, v8->m_motion.m_angularVelocity.m_quad);
    v85 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v84, v84, 85), _mm_shuffle_ps(v84, v84, 0)),
            _mm_shuffle_ps(v84, v84, 170));
    v85.m128_f32[0] = v85.m128_f32[0] * v78->mTorqueDampingBowScale;
    vars0 = 4i64;
    v184 = 4i64;
    v86 = _mm_xor_ps(v85, (__m128)(unsigned int)_xmm[0]);
    *(__m128 *)&v172.m256i_u64[2] = _mm_add_ps(
                                      *(__m128 *)&v172.m256i_u64[2],
                                      _mm_mul_ps(
                                        _mm_unpacklo_ps(_mm_unpacklo_ps(v86, v86), _mm_unpacklo_ps(v86, (__m128)0i64)),
                                        a.m_col1.m_quad));
    do
    {
      v87 = v5->mBoat;
      v88 = (__m128)*(unsigned int *)((char *)v87 + v82 - 32);
      v88.m128_f32[0] = v88.m128_f32[0] * *(float *)((char *)&v87->vfptr + v82);
      v89 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v88), (__m128)0i64);
      v170.m_quad = v89;
      if ( *(float *)((char *)&v87->vfptr + v82) > 0.1 )
      {
        v90 = v8->m_motion.m_angularVelocity.m_quad;
        v91 = _mm_sub_ps(
                *(__m128 *)((char *)&v87->vfptr + v80),
                v8->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v92 = _mm_mul_ps(_mm_shuffle_ps(v90, v90, 201), v91);
        v93 = _mm_mul_ps(_mm_shuffle_ps(v91, v91, 201), v90);
        v94 = _mm_shuffle_ps(
                (__m128)*(unsigned int *)((char *)v87 + v82 - 16),
                (__m128)*(unsigned int *)((char *)v87 + v82 - 16),
                0);
        v95 = _mm_sub_ps(v93, v92);
        v169.m_quad = _mm_add_ps(_mm_shuffle_ps(v95, v95, 201), v8->m_motion.m_linearVelocity.m_quad);
        v169.m_quad.m128_u64[0] = 0i64;
        v170.m_quad = _mm_add_ps(v89, _mm_mul_ps(v94, v169.m_quad));
      }
      v96 = (__m128)LODWORD(v6->m_deltaTime.m_storage);
      v97 = (signed __int64)v87 + v79;
      hkpEntity::activate((hkpEntity *)&v8->vfptr);
      v21 = v96;
      (*(void (__fastcall **)(hkpMaxSizeMotion *, __int64, hkVector4f *, signed __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))(*(_QWORD *)v81 + 200i64))(
        &v8->m_motion,
        v98,
        &v170,
        v97,
        v169.m_quad.m128_u64[0],
        v169.m_quad.m128_u64[1],
        v170.m_quad.m128_u64[0],
        v170.m_quad.m128_u64[1]);
      v79 += 16i64;
      v80 = *(_QWORD *)X + 16i64;
      v82 += 4i64;
      v99 = v184-- == 1;
      *(_QWORD *)X += 16i64;
    }
    while ( !v99 );
    v100 = 688i64;
    if ( *((_BYTE *)v5 + 56) & 1 || v18 <= 5.0 )
      goto LABEL_48;
    v101 = v5->mBoat;
    v102 = (__m128)LODWORD(v101->mLastChop);
    v101->mLastChop = v102.m128_f32[0] - v6->m_deltaTime.m_storage;
    v103 = v5->mBoat;
    if ( v103->mLastChop < 0.0 )
    {
      v102 = (__m128)LODWORD(UFG::PhysicsBoat::gChopPeriod);
      v103->mLastChop = UFG::PhysicsBoat::gChopPeriod;
      if ( v8->m_motion.m_linearVelocity.m_quad.m128_f32[2] < UFG::PhysicsBoat::gChopZThreshold )
      {
        v104 = v5->mBoat;
        v102 = (__m128)LODWORD(v104->mBuoyancyFactor[1]);
        if ( (float)((float)((float)(v102.m128_f32[0] + v104->mBuoyancyFactor[0]) + v104->mBuoyancyFactor[2])
                   + v104->mBuoyancyFactor[3]) >= 0.1 )
        {
          v102 = (__m128)LODWORD(UFG::PhysicsBoat::gChopImpulse);
          *(__m128 *)&v172.m256i_u64[3] = _mm_unpacklo_ps(
                                            _mm_unpacklo_ps(
                                              (__m128)0i64,
                                              (__m128)LODWORD(UFG::PhysicsBoat::gChopImpulse)),
                                            (__m128)0i64);
          hkpEntity::activate((hkpEntity *)&v8->vfptr);
          (*(void (__fastcall **)(hkpMaxSizeMotion *, unsigned __int64 *))(*(_QWORD *)v81 + 176i64))(
            &v8->m_motion,
            &v172.m256i_u64[3]);
        }
      }
    }
    v105 = (float)(v18 * 0.2) + 1.0;
    v106 = UFG::qNoise<float,float>::GetValue(&v5->mBoat->mChopFunction, v5->mBoat->mChopDist);
    v5->mBoat->mChopDist = (float)(v105 * v6->m_deltaTime.m_storage) + v5->mBoat->mChopDist;
    v102.m128_f32[0] = UFG::qNoise<float,float>::GetValue(&v5->mBoat->mChopFunction, v5->mBoat->mChopDist);
    v107 = v102;
    v5->mBoat->mChopDist = (float)(v105 * v6->m_deltaTime.m_storage) + v5->mBoat->mChopDist;
    v108 = UFG::qNoise<float,float>::GetValue(&v5->mBoat->mChopFunction, v5->mBoat->mChopDist);
    v109 = v106 < v107.m128_f32[0];
    v110 = v5->mBoat;
    v21 = (__m128)LODWORD(v110->mChopDist);
    v110->mChopDist = v21.m128_f32[0] - (float)(v105 * v6->m_deltaTime.m_storage);
    if ( v106 > v107.m128_f32[0] )
    {
      if ( v107.m128_f32[0] < v108 )
      {
        LODWORD(v5->mBoat->mChopTrough) = v107.m128_i32[0];
        goto LABEL_48;
      }
      v109 = v106 < v107.m128_f32[0];
    }
    if ( v109 && v107.m128_f32[0] > v108 )
    {
      v148 = (UFG::qNoise<float,float> *)v5->mBoat;
      v149 = v148;
      v148 = (UFG::qNoise<float,float> *)((char *)v148 + 940);
      v150 = _mm_mul_ps((__m128)_xmm, v12);
      v111 = 0i64;
      v107.m128_f32[0] = v107.m128_f32[0] - v148[1].tDecay;
      v169.m_quad = _mm_add_ps(v150, v8->m_motion.m_motionState.m_transform.m_translation.m_quad);
      v151 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
               _mm_shuffle_ps(v45, v45, 170));
      v152 = _mm_rsqrt_ps(v151);
      v153 = _mm_mul_ps(
               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v152, v151), v152)),
               _mm_mul_ps(*(__m128 *)_xmm, v152));
      v154 = UFG::qNoise<float,float>::GetValue(v148, v148[1].tRangeMin * 20.0);
      v150.m128_f32[0] = UFG::qNoise<float,float>::GetValue(
                           (UFG::qNoise<float,float> *)((char *)v149 + 940),
                           (float)(v149[30].tFrequency * 20.0) + 1.0);
      v155 = (__m128)LODWORD(FLOAT_10_0);
      v155.m128_f32[0] = (float)((float)(v154 - v150.m128_f32[0]) * 10.0)
                       / (float)((float)(COERCE_FLOAT(LODWORD(angle) & _xmm) * 10.0) + 1.0);
      v169.m_quad = _mm_add_ps(
                      v169.m_quad,
                      _mm_mul_ps(
                        _mm_shuffle_ps(v155, v155, 0),
                        _mm_mul_ps(_mm_andnot_ps(_mm_cmpleps(v151, (__m128)0i64), v153), *(__m128 *)v172.m256i_i8)));
      v156 = (float)(v18 - 5.0) * 0.2;
      if ( v156 > 1.5 )
        v156 = FLOAT_1_5;
      if ( v18 > 30.0 )
        v156 = v156 * (float)(30.0 / v18);
      v107.m128_f32[0] = (float)(v107.m128_f32[0] * 300.0) * v156;
      v21 = 0i64;
      *(__m128 *)v172.m256i_i8 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v107), (__m128)0i64);
      hkpEntity::activate((hkpEntity *)&v8->vfptr);
      (*(void (__fastcall **)(hkpMaxSizeMotion *, __m256i *, hkVector4f *))(*(_QWORD *)v81 + 184i64))(
        &v8->m_motion,
        &v172,
        &v169);
      goto LABEL_49;
    }
LABEL_48:
    v111 = 0i64;
LABEL_49:
    if ( !(*((_BYTE *)v5 + 56) & 1) )
    {
      if ( v5->mBoat->mReorientActionRoll )
      {
        v169.m_quad = (__m128)a.m_col0;
        v169.m_quad.m128_i32[2] = 0;
        v112 = _mm_mul_ps(v169.m_quad, v169.m_quad);
        v113 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                 _mm_shuffle_ps(v112, v112, 170));
        v114 = _mm_rsqrt_ps(v113);
        v169.m_quad = _mm_mul_ps(
                        v169.m_quad,
                        _mm_andnot_ps(
                          _mm_cmpleps(v113, v111),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v114, v113), v114)),
                            _mm_mul_ps(*(__m128 *)_xmm, v114))));
        hkQuaternionf::setAxisAngle((hkQuaternionf *)&v172, &v169, angle);
        hkVector4f::setRotatedDir((hkVector4f *)&v172.m256i_u64[3], (hkQuaternionf *)&v172, &direction);
        v115 = _mm_mul_ps(a.m_col2.m_quad, v169.m_quad);
        v116 = _mm_xor_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                   _mm_shuffle_ps(v115, v115, 170)),
                 (__m128)(unsigned int)_xmm[0]);
        v117 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v116, v116, 0), v169.m_quad), a.m_col2.m_quad);
        v118 = _mm_mul_ps(v117, v117);
        v119 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
                 _mm_shuffle_ps(v118, v118, 170));
        v120 = _mm_rsqrt_ps(v119);
        v121 = _mm_mul_ps(
                 v117,
                 _mm_andnot_ps(
                   _mm_cmpleps(v119, v111),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v120, v119), v120)),
                     _mm_mul_ps(*(__m128 *)_xmm, v120))));
        v122 = _mm_mul_ps(*(__m128 *)&v172.m256i_u64[3], v121);
        X[0] = (float)(COERCE_FLOAT(_mm_shuffle_ps(v122, v122, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v122, v122, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v122, v122, 170));
        v123 = _mm_min_ps(
                 _mm_max_ps((__m128)LODWORD(X[0]), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
                 *(__m128 *)_xmm);
        v124 = _mm_andnot_ps(*(__m128 *)_xmm, v123);
        v125 = _mm_cmpltps(v124, *(__m128 *)_xmm);
        v126 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v124), *(__m128 *)_xmm);
        v127 = _mm_cmpltps(*(__m128 *)_xmm, v124);
        v128 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v126), v127), _mm_andnot_ps(v127, v124));
        v129 = _mm_or_ps(_mm_andnot_ps(v127, _mm_mul_ps(v124, v124)), _mm_and_ps(v127, v126));
        v130 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v129, *(__m128 *)coeff4), *(__m128 *)coeff3), v129),
                               *(__m128 *)coeff2),
                             v129),
                           *(__m128 *)coeff1),
                         v129),
                       *(__m128 *)coeff0),
                     v129),
                   v128),
                 v128);
        v131 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v172.m256i_u64[3], *(__m128 *)&v172.m256i_u64[3], 201), v121),
                 _mm_mul_ps(_mm_shuffle_ps(v121, v121, 201), *(__m128 *)&v172.m256i_u64[3]));
        v132 = _mm_shuffle_ps(v131, v131, 201);
        v133 = _mm_mul_ps(v132, v132);
        v127.m128_f32[0] = 1.5707964
                         - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                  v125,
                                                                  _mm_or_ps(
                                                                    _mm_and_ps(
                                                                      _mm_sub_ps(
                                                                        *(__m128 *)_xmm,
                                                                        _mm_add_ps(v130, v130)),
                                                                      v127),
                                                                    _mm_andnot_ps(v127, v130))) | v125.m128_i32[0] & v124.m128_i32[0]) ^ v123.m128_i32[0] & _xmm[0]);
        v134 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v133, v133, 85), _mm_shuffle_ps(v133, v133, 0)),
                 _mm_shuffle_ps(v133, v133, 170));
        v135 = _mm_rsqrt_ps(v134);
        v136 = _mm_cmpleps(v134, v111);
        v137 = *(__m128 *)_xmm;
        v138 = _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v135, v134), v135)),
                 _mm_mul_ps(v135, *(__m128 *)_xmm));
        v21 = (__m128)LODWORD(UFG::PhysicsBoat::mLeanCodeFixConstant);
        v21.m128_f32[0] = UFG::PhysicsBoat::mLeanCodeFixConstant * v6->m_deltaTime.m_storage;
        v139 = v5->mBoat->mReorientActionRoll;
        v137.m128_f32[0] = (float)(v127.m128_f32[0] * v139->m_strength) * v21.m128_f32[0];
        v140 = _mm_shuffle_ps(v137, v137, 0);
        v141 = _mm_mul_ps(_mm_mul_ps(_mm_andnot_ps(v136, v138), v132), v140);
        v140.m128_f32[0] = v21.m128_f32[0] * v139->m_damping;
        *(hkVector4f *)((char *)&v173 + 8) = (hkVector4f)_mm_sub_ps(
                                                           v141,
                                                           _mm_mul_ps(
                                                             _mm_shuffle_ps(v140, v140, 0),
                                                             v8->m_motion.m_angularVelocity.m_quad));
        hkpEntity::activate((hkpEntity *)&v8->vfptr);
        (*(void (__fastcall **)(hkpMaxSizeMotion *, unsigned __int16 *))(*(_QWORD *)v81 + 192i64))(
          &v8->m_motion,
          &v173.m_quad.m128_u16[4]);
      }
      if ( !(*((_BYTE *)v5 + 56) & 1) )
      {
        v142 = 752i64;
        do
        {
          v143 = v5->mBoat;
          if ( *(float *)((char *)&v143->mUserData.simComponent.m_pPointer + v142) <= 0.0099999998 )
          {
            v144 = (__m128)*(unsigned int *)((char *)&v143->vfptr + v142);
            v145 = (__m128)LODWORD(v6->m_deltaTime.m_storage);
            v146 = (signed __int64)v143 + v100;
            v144.m128_f32[0] = v144.m128_f32[0] * -0.15000001;
            *(__m128 *)v172.m256i_i8 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v144), (__m128)0i64);
            hkpEntity::activate((hkpEntity *)&v8->vfptr);
            v21 = v145;
            (*(void (__fastcall **)(hkpMaxSizeMotion *, __int64, __m256i *, signed __int64))(*(_QWORD *)v81 + 200i64))(
              &v8->m_motion,
              v147,
              &v172,
              v146);
          }
          v100 += 16i64;
          v142 += 4i64;
          --vars0;
        }
        while ( vars0 );
      }
    }
    goto LABEL_75;
  }
  if ( !(*((_BYTE *)v5 + 56) & 1) )
  {
    v157 = (__m128 *)v3->mReorientActionRoll;
    if ( v157 )
    {
      v157[5] = _xmm;
      ((void (__fastcall *)(hkpReorientAction *, hkStepInfo *))v5->mBoat->mReorientActionRoll->vfptr[1].__first_virtual_table_function__)(
        v5->mBoat->mReorientActionRoll,
        v6);
      v4 = direction.m_quad;
    }
    v158 = v5->mBoat->mReorientActionPitch;
    if ( v158 )
    {
      v158->m_upAxis.m_quad = v4;
      ((void (__fastcall *)(hkpReorientAction *, hkStepInfo *))v5->mBoat->mReorientActionPitch->vfptr[1].__first_virtual_table_function__)(
        v5->mBoat->mReorientActionPitch,
        v6);
    }
    v159 = v5->mBoat;
    v160 = _mm_shuffle_ps(v14, v14, 170);
    if ( v160.m128_f32[0] <= 0.0 )
      v161 = v159->mVerticalVelocityDampingDown;
    else
      v161 = v159->mVerticalVelocityDampingUp;
    v160.m128_f32[0] = v160.m128_f32[0] * v161;
    v21 = 0i64;
    v171 = _mm_add_ps(
             v171,
             _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)0i64, _mm_xor_ps(v160, (__m128)(unsigned int)_xmm[0])),
               (__m128)0i64));
  }
LABEL_75:
  v162 = v5->mBoat;
  v163 = *((_DWORD *)&v162->0 + 151);
  if ( v163 & 8 )
  {
    if ( v162->mSpeedKPH < 0.5 )
      *((_DWORD *)&v162->0 + 151) = v163 & 0xFFFFFFF7;
    v164 = v5->mBoat;
    v170.m_quad = v14;
    v170.m_quad.m128_i32[2] = 0;
    v21.m128_f32[0] = COERCE_FLOAT(LODWORD(v164->mSuperStopDrag) ^ _xmm[0]);
    v171 = _mm_add_ps(v171, _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v170.m_quad));
  }
  v165 = LODWORD(v6->m_deltaTime.m_storage);
  hkpEntity::activate((hkpEntity *)&v8->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *))v8->m_motion.vfptr[13].__vecDelDtor)(
    &v8->m_motion,
    v166,
    &v171);
  v167 = LODWORD(v6->m_deltaTime.m_storage);
  hkpEntity::activate((hkpEntity *)&v8->vfptr);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, unsigned __int64 *))v8->m_motion.vfptr[13].__first_virtual_table_function__)(
    &v8->m_motion,
    v168,
    &v172.m256i_u64[2]);
}FF7;
    v164 = v5->mBoat;
    v170.m_quad = v14;
    v170.m_quad.m128_i32[2] = 0;
    v21.m128_f32[0] = COERCE_FLOAT(LODWORD(v164->mSuperStopDrag) ^ _xmm[0]);
    v171 = _mm_add_ps(v171, _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v170.m_quad));
  }
  v165 = LODWORD(v6->m_deltaTime.m_storage);
  hkpEntity::activate((hkpEntity *)&v

