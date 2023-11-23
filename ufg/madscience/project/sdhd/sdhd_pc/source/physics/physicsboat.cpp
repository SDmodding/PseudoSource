// File Line: 68
// RVA: 0x44A4F0
void __fastcall UFG::PhysicsBoat::PhysicsBoat(
        UFG::PhysicsBoat *this,
        UFG::VehicleParams *param,
        UFG::qMatrix44 *transform,
        UFG::qVector3 *velocity)
{
  float v5; // xmm1_4
  float v6; // xmm0_4
  __int64 v7; // rax
  UFG::qReflectObject *mData; // rcx
  hkpRigidBody *mBody; // rcx
  __int64 v10; // rdi
  char v11; // dl
  char v12; // cl
  _QWORD **Value; // rax
  hkpUnaryAction *v14; // rax
  hkpUnaryAction *v15; // rsi
  char v16; // al
  char v17; // dl
  char v18; // cl
  _QWORD **v19; // rax
  hkpReorientAction *v20; // rax
  hkpReorientAction *v21; // rax
  _QWORD **v22; // rax
  hkpReorientAction *v23; // rax
  hkpReorientAction *v24; // rax
  char v25; // al
  bool *mPrevFloatInWater; // rax
  __int64 v27; // rcx
  hkVector4f centerOfMass; // [rsp+30h] [rbp-98h] BYREF
  hkVector4f upAxis; // [rsp+40h] [rbp-88h] BYREF
  UFG::qReflectHandleBase v30; // [rsp+50h] [rbp-78h] BYREF
  hkVector4f rotationAxis; // [rsp+80h] [rbp-48h] BYREF
  hkVector4f v32; // [rsp+90h] [rbp-38h] BYREF
  __int64 v33; // [rsp+A0h] [rbp-28h]

  v33 = -2i64;
  UFG::PhysicsVehicle::PhysicsVehicle(this, param, transform, velocity);
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::PhysicsBoat::`vftable;
  this->mOustideWorldBoundaries = 0;
  this->mEngineDamage = 0.0;
  this->mChopFunction.bCircular = 0;
  *(_QWORD *)&this->mChopFunction.tDecay = 1060320051i64;
  this->mChopFunction.nOctaves = 3;
  LODWORD(this->mChopFunction.tFrequency) = (unsigned int)FLOAT_1_0 & _xmm;
  this->mChopFunction.tOffset = 0.0;
  this->mChopFunction.tRangeMax = 1.0;
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
  this->mChopFunction.tAmplitude = 1.0 / v5;
  *((_DWORD *)this + 246) &= 0xFFFFFFFA;
  UFG::qReflectHandleBase::qReflectHandleBase(&v30);
  v30.mTypeUID = UFG::qStringHash64("UFG::BoatPhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v30, v30.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
  UFG::PhysicsBoat::LoadProperties(this);
  mData = v30.mData;
  this->mFloatPositionsLocalSpace[0].m_quad = _mm_unpacklo_ps(
                                                _mm_unpacklo_ps(
                                                  (__m128)LODWORD(v30.mData[2].mBaseNode.mParent),
                                                  (__m128)LODWORD(v30.mData[2].mBaseNode.mChildren[0])),
                                                _mm_unpacklo_ps(
                                                  (__m128)HIDWORD(v30.mData[2].mBaseNode.mParent),
                                                  (__m128)(unsigned int)FLOAT_1_0));
  this->mFloatPositionsLocalSpace[1].m_quad = _mm_unpacklo_ps(
                                                _mm_unpacklo_ps(
                                                  (__m128)HIDWORD(mData[2].mBaseNode.mChildren[0]),
                                                  (__m128)HIDWORD(mData[2].mBaseNode.mChildren[1])),
                                                _mm_unpacklo_ps(
                                                  (__m128)LODWORD(mData[2].mBaseNode.mChildren[1]),
                                                  (__m128)(unsigned int)FLOAT_1_0));
  this->mFloatPositionsLocalSpace[2].m_quad = _mm_unpacklo_ps(
                                                _mm_unpacklo_ps(
                                                  (__m128)LODWORD(mData[2].mBaseNode.mNeighbours[0]),
                                                  (__m128)LODWORD(mData[2].mBaseNode.mNeighbours[1])),
                                                _mm_unpacklo_ps(
                                                  (__m128)HIDWORD(mData[2].mBaseNode.mNeighbours[0]),
                                                  (__m128)(unsigned int)FLOAT_1_0));
  this->mFloatPositionsLocalSpace[3].m_quad = _mm_unpacklo_ps(
                                                _mm_unpacklo_ps(
                                                  (__m128)HIDWORD(mData[2].mBaseNode.mNeighbours[1]),
                                                  (__m128)HIDWORD(mData[2].mTypeUID)),
                                                _mm_unpacklo_ps(
                                                  (__m128)LODWORD(mData[2].mTypeUID),
                                                  (__m128)(unsigned int)FLOAT_1_0));
  *(_QWORD *)this->mFloatBuoyancy = mData[3].mTypeUID;
  this->mFloatBuoyancy[2] = *(float *)&mData[3].mHandles.mNode.mPrev;
  this->mFloatBuoyancy[3] = *((float *)&mData[3].mHandles.mNode.mPrev + 1);
  this->mCOMShift = *((float *)&mData[3].mBaseNode.mChildren[1] + 1);
  this->mIsCOMShifted = 1;
  mBody = this->mRigidBody->mBody;
  centerOfMass.m_quad = _mm_add_ps(
                          mBody->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad,
                          _mm_unpacklo_ps(
                            _mm_unpacklo_ps(_mm_xor_ps((__m128)LODWORD(this->mCOMShift), *(__m128 *)_xmm), (__m128)0i64),
                            (__m128)0i64));
  hkpRigidBody::setCenterOfMassLocal(mBody, &centerOfMass);
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v11) = 3;
  *(_QWORD *)(v10 + 8i64 * v11 + 16) = "BoatAction";
  *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
  v12 = *(_BYTE *)(v10 + 81);
  if ( v11 > v12 )
    v12 = v11;
  *(_BYTE *)(v10 + 81) = v12;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkpUnaryAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 72i64);
  v15 = v14;
  centerOfMass.m_quad.m128_u64[0] = (unsigned __int64)v14;
  if ( v14 )
  {
    hkpUnaryAction::hkpUnaryAction(v14, this->mRigidBody->mBody, 0i64);
    v15->vfptr = (hkBaseObjectVtbl *)&UFG::BoatAction::`vftable;
    LODWORD(v15[1].vfptr) &= 0xFFFFFFF8;
    *(_QWORD *)&v15[1].m_memSizeAndFlags = this;
  }
  else
  {
    v15 = 0i64;
  }
  this->mBoatAction = (UFG::BoatAction *)v15;
  v16 = *(_BYTE *)(v10 + 80);
  if ( v16 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v16 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  rotationAxis.m_quad = (__m128)_xmm;
  v32.m_quad = _xmm;
  upAxis.m_quad = _xmm;
  v17 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v17) = 3;
  *(_QWORD *)(v10 + 8i64 * v17 + 16) = "hkpReorientAction";
  *(_QWORD *)(v10 + 8i64 * v17 + 48) = 0i64;
  v18 = *(_BYTE *)(v10 + 81);
  if ( v17 > v18 )
    v18 = v17;
  *(_BYTE *)(v10 + 81) = v18;
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (hkpReorientAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(v19[11], 112i64);
  centerOfMass.m_quad.m128_u64[0] = (unsigned __int64)v20;
  if ( v20 )
    hkpReorientAction::hkpReorientAction(
      v20,
      this->mRigidBody->mBody,
      &rotationAxis,
      &upAxis,
      this->mRollStability,
      0.1);
  else
    v21 = 0i64;
  this->mReorientActionRoll = v21;
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (hkpReorientAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v22[11] + 8i64))(v22[11], 112i64);
  centerOfMass.m_quad.m128_u64[0] = (unsigned __int64)v23;
  if ( v23 )
    hkpReorientAction::hkpReorientAction(v23, this->mRigidBody->mBody, &v32, &upAxis, this->mPitchStability, 0.1);
  else
    v24 = 0i64;
  this->mReorientActionPitch = v24;
  v25 = *(_BYTE *)(v10 + 80);
  if ( v25 > 0 )
  {
    *(_BYTE *)(v10 + 80) = v25 - 1;
  }
  else
  {
    *(_BYTE *)(v10 + 80) = 0;
    *(_DWORD *)v10 = 3;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_QWORD *)(v10 + 48) = 0i64;
  }
  this->mChopDist = UFG::qRandom(500.0, (unsigned int *)&UFG::qDefaultSeed);
  this->mChopTrough = 0.5;
  mPrevFloatInWater = this->mPrevFloatInWater;
  v27 = 4i64;
  do
  {
    *(mPrevFloatInWater - 4) = 1;
    *mPrevFloatInWater++ = 1;
    --v27;
  }
  while ( v27 );
  this->mUserData.isBoat = 1;
  this->mRigidBody->UFG::PhysicsVehicle::mUserData.isBoat = 1;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v30);
}

// File Line: 136
// RVA: 0x472B40
void __fastcall UFG::PhysicsBoat::Reload(UFG::PhysicsBoat *this, UFG::qSymbol *propertySetName)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v4; // rax

  this->mParams->mPhysicsPropertiesName.mUID = propertySetName->mUID;
  mUID = this->mParams->mPhysicsPropertiesName.mUID;
  if ( mUID )
  {
    v4 = UFG::qBaseTreeRB::Get(&UFG::BaseVehiclePhysicsDef::mSearchTree.mTree, mUID);
    if ( v4 )
      UFG::qReflectHandleBase::Init(
        &this->mDnaDefinition,
        this->mDnaDefinition.mTypeUID,
        (unsigned __int64)v4->mNULL.mParent);
  }
  UFG::PhysicsVehicle::LoadProperties(this);
  UFG::PhysicsBoat::LoadProperties(this);
}

// File Line: 144
// RVA: 0x46B6B0
void __fastcall UFG::PhysicsBoat::LoadProperties(UFG::PhysicsBoat *this)
{
  UFG::qReflectObject *mData; // rcx
  float v3; // xmm0_4
  hkpReorientAction *mReorientActionRoll; // rcx
  hkpReorientAction *mReorientActionPitch; // rcx
  UFG::qReflectHandleBase v6; // [rsp+28h] [rbp-30h] BYREF

  UFG::qReflectHandleBase::qReflectHandleBase(&v6);
  v6.mTypeUID = UFG::qStringHash64("UFG::BoatPhysicsDef", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&v6, v6.mTypeUID, this->mDnaDefinition.mData->mBaseNode.mUID);
  mData = v6.mData;
  *(_OWORD *)this->mFloatDragZ = *(_OWORD *)&v6.mData[3].mHandles.mNode.mNext;
  this->mRudderForceMultiplier = *(float *)&mData[2].mHandles.mNode.mPrev;
  this->mRudderOffset.m_quad.m128_i32[0] = HIDWORD(mData[2].mHandles.mNode.mPrev);
  this->mRudderOffset.m_quad.m128_i32[1] = 0;
  this->mRudderOffset.m_quad.m128_i32[2] = (int)mData[2].mHandles.mNode.mNext;
  this->mRudderOffset.m_quad.m128_i32[3] = 1065353216;
  this->mBowThrusterOffset.m_quad.m128_i32[0] = (int)mData[3].mBaseNode.mNeighbours[1];
  this->mBowThrusterOffset.m_quad.m128_i32[1] = 0;
  this->mBowThrusterOffset.m_quad.m128_i32[2] = HIDWORD(mData[3].mBaseNode.mNeighbours[1]);
  this->mBowThrusterOffset.m_quad.m128_i32[3] = 1065353216;
  this->mBowThrusterCutoffSpeed = *(float *)mData[3].mBaseNode.mNeighbours * 0.27777779;
  this->mBowThrusterPower = *((float *)mData[3].mBaseNode.mNeighbours + 1);
  v3 = (float)(*(float *)&mData[3].vfptr * 3.1415927) * 0.0055555557;
  this->mMaxRudderAngle = v3;
  this->mMaxRudderAngleForSpeed = v3;
  this->mMaxEngineThrust = *((float *)&mData[3].vfptr + 1);
  this->mEngineThrustAngle = (float)(*(float *)&mData[3].mBaseNode.mUID * 3.1415927) * 0.0055555557;
  this->mViscousDrag = *((float *)&mData[3].mBaseNode.mUID + 1);
  *(_QWORD *)&this->mViscousDragLateral = mData[3].mBaseNode.mParent;
  this->mTorqueDamping = *(float *)mData[3].mBaseNode.mChildren;
  this->mTorqueDampingBowScale = *((float *)mData[3].mBaseNode.mChildren + 1);
  this->mLeanFactor = *(float *)&mData[3].mBaseNode.mChildren[1];
  this->mKeelTorque = *((float *)&mData[2].mHandles.mNode.mNext + 1);
  this->mSteeringSensitivityMinSpeed = *((float *)&mData[1].mHandles.mNode.mNext + 1);
  this->mSteeringSensitivityMaxSpeed = *(float *)&mData[2].vfptr;
  this->mSteeringSensitivityHi = *(float *)&mData[1].mHandles.mNode.mNext;
  this->mSteeringSensitivityLo = *((float *)&mData[1].mHandles.mNode.mPrev + 1);
  this->mDollarValue = *(float *)&mData[1].mHandles.mNode.mPrev;
  mReorientActionRoll = this->mReorientActionRoll;
  if ( mReorientActionRoll )
    mReorientActionRoll->m_strength = this->mRollStability;
  mReorientActionPitch = this->mReorientActionPitch;
  if ( mReorientActionPitch )
    mReorientActionPitch->m_strength = this->mPitchStability;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v6);
}

// File Line: 204
// RVA: 0x4762B0
void __fastcall UFG::PhysicsBoat::Suspend(UFG::PhysicsBoat *this)
{
  UFG::BoatAction *mBoatAction; // rdx
  UFG::BasePhysicsSystem *v3; // rdi
  hkpRigidBody *mBody; // rdx
  hkpRigidBody *mBulletCollider; // rdx
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // rcx

  mBoatAction = this->mBoatAction;
  if ( mBoatAction )
    UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, mBoatAction);
  v3 = UFG::BasePhysicsSystem::mInstance;
  mBody = this->mRigidBody->mBody;
  if ( mBody && mBody->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(UFG::BasePhysicsSystem::mInstance, mBody, 0);
  mBulletCollider = this->mBulletCollider;
  if ( mBulletCollider && mBulletCollider->m_world )
    UFG::BasePhysicsSystem::RemoveEntity(v3, mBulletCollider, 0);
  mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
  if ( mWaterFloatingTrackerComponent )
    ((void (__fastcall *)(UFG::WaterFloatingTrackerComponent *))mWaterFloatingTrackerComponent->UFG::WaterFloatingTrackerBaseComponent::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[8].__vecDelDtor)(mWaterFloatingTrackerComponent);
}

// File Line: 216
// RVA: 0x473E40
void __fastcall UFG::PhysicsBoat::Restore(UFG::PhysicsBoat *this)
{
  UFG::BoatAction *mBoatAction; // rdx

  UFG::PhysicsVehicle::Restore(this);
  if ( this->mCurrentLod != LOD_NIS )
  {
    mBoatAction = this->mBoatAction;
    if ( mBoatAction )
    {
      if ( !mBoatAction->m_world )
        UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, mBoatAction);
    }
  }
}

// File Line: 234
// RVA: 0x479B20
void __fastcall UFG::PhysicsBoat::Update(
        UFG::PhysicsBoat *this,
        UFG::qMatrix44 *targetTransform,
        UFG::VehicleInput *input,
        float deltaTime)
{
  UFG::BasePhysicsSystem *v4; // r14
  UFG::RigidBodyComponent *mRigidBody; // r8
  hkpRigidBody *mBody; // rax
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm2
  hkVector4f v13; // xmm3
  hkVector4f v14; // xmm0
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  hkpRigidBody *v17; // rcx
  hkpRigidBody *v18; // rcx
  UFG::WaterFloatingTrackerComponent *mWaterFloatingTrackerComponent; // rcx
  float mSpeedKPH; // xmm1_4
  __m128 v21; // xmm8
  float v22; // xmm2_4
  float v23; // xmm2_4
  int v24; // r13d
  bool v25; // cc
  float mSteeringSensitivityHi; // xmm0_4
  float mSteeringSensitivityLo; // xmm3_4
  float v28; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm5_4
  float v31; // xmm9_4
  float v32; // xmm1_4
  float v33; // xmm1_4
  float mRudderAngle; // xmm0_4
  UFG::BoatAction *mBoatAction; // rax
  float v36; // xmm1_4
  __int64 v37; // rbx
  int v38; // eax
  float v39; // xmm1_4
  hkVector4f *mFloatPositionWorldSpace; // r12
  bool *mFloatInWater; // rsi
  float *mBuoyancyFactor; // r14
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
  float OneOverApparentMass; // xmm0_4
  UFG::RigidBodyComponent *v59; // rax
  hkpEntity *v60; // rbx
  UFG::qVector4 v61; // xmm3
  UFG::qVector4 v62; // xmm2
  UFG::qVector4 v63; // xmm1
  UFG::WorldBoundaries *p_m_size; // rcx
  hkpRigidBody *v65; // rdx
  UFG::BoatAction *v66; // rax
  int *p_m_translation; // rdx
  int v68; // xmm1_4
  int v69; // xmm0_4
  bool v70; // zf
  int v71; // xmm0_4
  int v72; // xmm1_4
  __m128 v73; // xmm9
  __m128 v74; // xmm6
  float v75; // xmm11_4
  float x; // xmm12_4
  float y; // xmm13_4
  float z; // xmm14_4
  __m128 v79; // xmm10
  float v80; // xmm4_4
  __m128 v81; // xmm5
  float v82; // xmm2_4
  UFG::RigidBodyComponent *v83; // rax
  float v84; // xmm4_4
  __m128 v85; // xmm3
  __m128 v86; // xmm2
  hkpEntity *v87; // rbx
  UFG::RigidBodyComponent *v88; // rbx
  __m128 v89; // xmm3
  __m128 v90; // xmm2
  __m128 v91; // xmm4
  float v92; // xmm1_4
  hkpEntity *v93; // rbx
  hkVector4f *p_centerOfMass; // rdx
  UFG::BoatAction *v95; // rax
  float v96; // xmm4_4
  float v97; // xmm6_4
  __m128 x_low; // xmm3
  __m128 y_low; // xmm2
  UFG::RigidBodyComponent *v100; // rax
  hkpEntity *v101; // rbx
  UFG::RigidBodyComponent *v102; // rbx
  __m128 v103; // xmm5
  __m128 v104; // xmm1
  __m128 v105; // xmm4
  __m128 v106; // xmm1
  UFG::RigidBodyComponent *v107; // rbx
  __m128 v108; // xmm3
  __m128 m_quad; // xmm4
  __m128 v110; // xmm2
  __m128 v111; // [rsp+30h] [rbp-B0h] BYREF
  hkVector4f centerOfMass; // [rsp+40h] [rbp-A0h] BYREF
  __m128 v113; // [rsp+50h] [rbp-90h] BYREF
  hkTransformf a; // [rsp+60h] [rbp-80h] BYREF
  float distance[2]; // [rsp+150h] [rbp+70h] BYREF
  __int64 vars0; // [rsp+160h] [rbp+80h]

  v4 = UFG::BasePhysicsSystem::mInstance;
  this->mOustideWorldBoundaries = 0;
  mRigidBody = this->mRigidBody;
  *(_QWORD *)distance = v4;
  mBody = mRigidBody->mBody;
  v11.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v12.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v13.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
  v14.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  a.m_rotation.m_col1 = (hkVector4f)v11.m_quad;
  a.m_rotation.m_col0 = (hkVector4f)v12.m_quad;
  *((_DWORD *)this + 246) ^= (*((_DWORD *)this + 246) ^ (*((_DWORD *)input + 4) >> 5)) & 1;
  LODWORD(mBody) = *((_DWORD *)this + 246);
  v15 = *((_DWORD *)input + 4);
  a.m_rotation.m_col0 = (hkVector4f)v14.m_quad;
  a.m_rotation.m_col1 = (hkVector4f)v13.m_quad;
  v16 = (unsigned int)mBody ^ ((unsigned __int8)mBody ^ (unsigned __int8)(v15 >> 3)) & 2;
  *((_DWORD *)this + 246) = v16;
  if ( (v16 & 1) != 0 )
  {
    if ( this->mIsCOMShifted )
    {
      v17 = mRigidBody->mBody;
      v11.m_quad.m128_u64[0] = 0i64;
      centerOfMass.m_quad = _mm_add_ps(
                              _mm_unpacklo_ps(
                                _mm_unpacklo_ps(
                                  _mm_xor_ps(
                                    _mm_xor_ps((__m128)LODWORD(this->mCOMShift), (__m128)(unsigned int)_xmm[0]),
                                    (__m128)(unsigned int)_xmm[0]),
                                  (__m128)0i64),
                                (__m128)0i64),
                              v17->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad);
      hkpRigidBody::setCenterOfMassLocal(v17, &centerOfMass);
      this->mIsCOMShifted = 0;
    }
  }
  else if ( !this->mIsCOMShifted )
  {
    v18 = mRigidBody->mBody;
    v11.m_quad.m128_u64[0] = 0i64;
    centerOfMass.m_quad = _mm_add_ps(
                            _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                _mm_xor_ps((__m128)LODWORD(this->mCOMShift), (__m128)(unsigned int)_xmm[0]),
                                (__m128)0i64),
                              (__m128)0i64),
                            v18->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad);
    hkpRigidBody::setCenterOfMassLocal(v18, &centerOfMass);
    this->mIsCOMShifted = 1;
  }
  mWaterFloatingTrackerComponent = this->mWaterFloatingTrackerComponent;
  if ( mWaterFloatingTrackerComponent && mWaterFloatingTrackerComponent->mInWaterState > 0 )
    UFG::WaterFloatingTrackerComponent::AdjustRipple(
      mWaterFloatingTrackerComponent,
      *(double *)v11.m_quad.m128_u64,
      (__int64)mRigidBody);
  UFG::PhysicsVehicle::Update(this, targetTransform, input, deltaTime);
  mSpeedKPH = this->mSpeedKPH;
  v21 = (__m128)(unsigned int)FLOAT_1_0;
  if ( this->mCurrentLod != LOD_NIS )
  {
    if ( (*((_BYTE *)input + 16) & 1) != 0 )
      v22 = *(float *)&FLOAT_1_0;
    else
      v22 = FLOAT_N1_0;
    v23 = v22 * input->mGasBrakes;
    v24 = 0;
    v25 = mSpeedKPH <= this->mHighSpeedGovernor;
    this->mThrottle = v23;
    if ( !v25 && v23 > 0.0 || mSpeedKPH < COERCE_FLOAT(LODWORD(this->mReverseSpeedGovernor) ^ _xmm[0]) && v23 < 0.0 )
      this->mThrottle = 0.0;
    mSteeringSensitivityHi = this->mSteeringSensitivityHi;
    mSteeringSensitivityLo = this->mSteeringSensitivityLo;
    v28 = this->mSteeringSensitivityMinSpeed * this->mSteeringSensitivityMinSpeed;
    if ( mSteeringSensitivityLo >= mSteeringSensitivityHi )
      v29 = this->mSteeringSensitivityHi;
    else
      v29 = this->mSteeringSensitivityLo;
    if ( mSteeringSensitivityLo <= mSteeringSensitivityHi )
      v30 = this->mSteeringSensitivityHi;
    else
      v30 = this->mSteeringSensitivityLo;
    v31 = FLOAT_0_000099999997;
    if ( (float)((float)(this->mSteeringSensitivityMaxSpeed * this->mSteeringSensitivityMaxSpeed) - v28) >= 0.000099999997 )
      v31 = (float)(this->mSteeringSensitivityMaxSpeed * this->mSteeringSensitivityMaxSpeed) - v28;
    v32 = (float)((float)((float)(mSpeedKPH * mSpeedKPH) - v28)
                * (float)((float)(mSteeringSensitivityHi - mSteeringSensitivityLo) / v31))
        + mSteeringSensitivityLo;
    if ( v32 <= v29 )
      v32 = v29;
    if ( v32 >= v30 )
      v32 = v30;
    v33 = v32 * this->mMaxRudderAngle;
    mRudderAngle = this->mRudderAngle;
    mBoatAction = this->mBoatAction;
    this->mMaxRudderAngleForSpeed = v33;
    v36 = v33 * input->mSteering;
    v37 = 4i64;
    vars0 = 4i64;
    this->mRudderAngle = (float)((float)(COERCE_FLOAT(LODWORD(v36) ^ _xmm[0]) - mRudderAngle) * sRudderMotionGain)
                       + mRudderAngle;
    if ( (*((_BYTE *)mBoatAction + 56) & 1) != 0 )
    {
      v38 = UFG::qRandom(4u, (unsigned int *)&UFG::qDefaultSeed);
      v39 = this->mFloatBuoyancy[v38] - (float)(UFG::PhysicsBoat::mSinkRate * deltaTime);
      this->mFloatBuoyancy[v38] = v39;
      if ( v39 >= 0.0 )
        hkpEntity::activate(this->mRigidBody->mBody);
      else
        this->mFloatBuoyancy[v38] = 0.0;
    }
    mFloatPositionWorldSpace = this->mFloatPositionWorldSpace;
    mFloatInWater = this->mFloatInWater;
    mBuoyancyFactor = this->mBuoyancyFactor;
    v43 = this->mFloatPositionWorldSpace;
    do
    {
      hkVector4f::setTransformedPos(v43, &a, v43 - 4);
      v44 = _mm_mul_ps(mFloatPositionWorldSpace->m_quad, mFloatPositionWorldSpace->m_quad);
      v45 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
              _mm_shuffle_ps(v44, v44, 170));
      v46 = _mm_rsqrt_ps(v45);
      v47 = fmodf(
              (float)(_mm_andnot_ps(
                        _mm_cmple_ps(v45, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
                            _mm_mul_ps(v46, *(__m128 *)_xmm)),
                          v45)).m128_f32[0]
                    * *(float *)(*(_QWORD *)distance + 99852i64))
            + *(float *)(*(_QWORD *)distance + 99856i64),
              6.2800002);
      v48 = cosf(v47);
      v49 = mFloatPositionWorldSpace->m_quad.m128_f32[2] - 0.5;
      v50 = (float)(v48 * *(float *)(*(_QWORD *)distance + 99844i64)) + *(float *)(*(_QWORD *)distance + 99840i64);
      if ( v49 < v50 )
      {
        if ( (float)(mFloatPositionWorldSpace->m_quad.m128_f32[2] + 0.5) > v50 )
          v51 = v50 - v49;
        else
          v51 = *(float *)&FLOAT_1_0;
      }
      else
      {
        v51 = 0.0;
      }
      *mBuoyancyFactor = v51;
      v52 = *mFloatInWater;
      mFloatInWater[4] = *mFloatInWater;
      if ( *mBuoyancyFactor <= 0.0099999998 )
      {
        *mFloatInWater = 0;
      }
      else
      {
        *mFloatInWater = 1;
        ++v24;
      }
      if ( !v52 && *mFloatInWater )
      {
        v53 = this->mRigidBody->mBody;
        v54 = _mm_sub_ps(
                mFloatPositionWorldSpace->m_quad,
                v53->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
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
          OneOverApparentMass = UFG::GetOneOverApparentMass(v53, v43, &centerOfMass);
          v59 = this->mRigidBody;
          v57.m128_f32[0] = (float)(v57.m128_f32[0] * (float)(1.0 / OneOverApparentMass))
                          * UFG::PhysicsBoat::mPontoonWaterCollisionResponse;
          v111 = _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)0i64, _mm_xor_ps(v57, (__m128)(unsigned int)_xmm[0])),
                   (__m128)0i64);
          v60 = v59->mBody;
          hkpEntity::activate(v60);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, hkVector4f *))v60->m_motion.vfptr[11].__first_virtual_table_function__)(
            &v60->m_motion,
            &v111,
            v43);
          v37 = vars0;
        }
      }
      ++v43;
      ++mBuoyancyFactor;
      ++mFloatPositionWorldSpace;
      ++mFloatInWater;
      vars0 = --v37;
    }
    while ( v37 );
    if ( v24 >= 2 && a.m_rotation.m_col0.m_quad.m128_f32[2] < 0.38 )
    {
      *((_DWORD *)this->mBoatAction + 14) |= 2u;
      *((_DWORD *)this->mBoatAction + 14) |= 1u;
    }
    v61 = this->mBodyTransform.v1;
    v62 = this->mBodyTransform.v2;
    v4 = *(UFG::BasePhysicsSystem **)distance;
    v63 = this->mBodyTransform.v3;
    this->mLastGoodPosition.v0 = this->mBodyTransform.v0;
    this->mLastGoodPosition.v1 = v61;
    this->mLastGoodPosition.v2 = v62;
    this->mLastGoodPosition.v3 = v63;
  }
  if ( this->mCurrentLod != LOD_NIS )
  {
    p_m_size = (UFG::WorldBoundaries *)&v4[1].mActiveRegionManager.mExtents.m_size;
    v65 = this->mRigidBody->mBody;
    v66 = this->mBoatAction;
    v111.m128_u64[0] = 0i64;
    p_m_translation = (int *)&v65->m_motion.m_motionState.m_transform.m_translation;
    v111.m128_i32[2] = 0;
    v68 = p_m_translation[1];
    centerOfMass.m_quad.m128_i32[0] = *p_m_translation;
    v69 = p_m_translation[2];
    centerOfMass.m_quad.m128_i32[1] = v68;
    *((_DWORD *)v66 + 14) &= ~4u;
    v70 = (*((_BYTE *)&this->UFG::PhysicsVehicle + 604) & 0x10) == 0;
    centerOfMass.m_quad.m128_i32[2] = v69;
    if ( v70 )
    {
      if ( !UFG::WorldBoundaries::IsOutsideBoundaries2(
              p_m_size,
              (UFG::qVector3 *)&centerOfMass,
              25.0,
              (UFG::qVector3 *)&v111) )
        return;
      v95 = this->mBoatAction;
      v96 = v111.m128_f32[1];
      v97 = v111.m128_f32[0];
      this->mOustideWorldBoundaries = 1;
      *((_DWORD *)v95 + 14) |= 4u;
      x_low = (__m128)LODWORD(this->mBodyTransform.v0.x);
      y_low = (__m128)LODWORD(this->mBodyTransform.v0.y);
      if ( (float)((float)((float)(this->mBodyTransform.v0.y * v96) + (float)(this->mBodyTransform.v0.x * v97))
                 + (float)(this->mBodyTransform.v0.z * v111.m128_f32[2])) >= 0.80000001 )
      {
        v107 = this->mRigidBody;
        v108 = _mm_unpacklo_ps(
                 _mm_unpacklo_ps(x_low, (__m128)LODWORD(this->mBodyTransform.v0.z)),
                 _mm_unpacklo_ps(y_low, (__m128)0i64));
        m_quad = v107->mBody->m_motion.m_linearVelocity.m_quad;
        v110 = _mm_mul_ps(v108, m_quad);
        if ( (float)((float)(_mm_shuffle_ps(v110, v110, 85).m128_f32[0] + _mm_shuffle_ps(v110, v110, 0).m128_f32[0])
                   + _mm_shuffle_ps(v110, v110, 170).m128_f32[0]) >= 5.0 )
          return;
        v113 = _mm_add_ps(m_quad, _mm_mul_ps((__m128)_xmm, v108));
        v93 = v107->mBody;
        hkpEntity::activate(v93);
        p_centerOfMass = (hkVector4f *)&v113;
      }
      else
      {
        v100 = this->mRigidBody;
        y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * v97) - (float)(x_low.m128_f32[0] * v96)) * -1.5;
        v113 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, y_low), (__m128)0i64);
        v101 = v100->mBody;
        hkpEntity::activate(v101);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v101->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v101->m_motion,
          &v113);
        v102 = this->mRigidBody;
        v103 = v102->mBody->m_motion.m_linearVelocity.m_quad;
        v104 = _mm_mul_ps(v103, v103);
        v105 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v104, v104, 85), _mm_shuffle_ps(v104, v104, 0)),
                 _mm_shuffle_ps(v104, v104, 170));
        v106 = _mm_rsqrt_ps(v105);
        if ( _mm_andnot_ps(
               _mm_cmple_ps(v105, (__m128)0i64),
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v106, v105), v106)),
                   _mm_mul_ps(*(__m128 *)_xmm, v106)),
                 v105)).m128_f32[0] <= 5.0 )
          return;
        centerOfMass.m_quad = _mm_mul_ps(v103, (__m128)_xmm);
        v93 = v102->mBody;
        hkpEntity::activate(v93);
        p_centerOfMass = &centerOfMass;
      }
    }
    else
    {
      v71 = *p_m_translation;
      v72 = p_m_translation[1];
      distance[0] = 0.0;
      v111.m128_u64[0] = 0i64;
      v111.m128_i32[2] = 0;
      centerOfMass.m_quad.m128_u64[0] = __PAIR64__(v72, v71);
      centerOfMass.m_quad.m128_i32[2] = p_m_translation[2];
      if ( !UFG::WorldBoundaries::IsOutsideBoundaries(
              p_m_size,
              (UFG::qVector3 *)&centerOfMass,
              25.0,
              (UFG::qVector3 *)&v111,
              distance) )
        return;
      v73 = (__m128)v111.m128_u32[1];
      v74 = (__m128)v111.m128_u32[0];
      v75 = v111.m128_f32[2];
      this->mOustideWorldBoundaries = 1;
      x = this->mBodyTransform.v0.x;
      y = this->mBodyTransform.v0.y;
      z = this->mBodyTransform.v0.z;
      if ( (float)((float)((float)(y * v73.m128_f32[0]) + (float)(x * v74.m128_f32[0])) + (float)(z * v75)) < 0.0 )
      {
        v79 = v73;
        v81 = v74;
        v79.m128_f32[0] = v73.m128_f32[0] - (float)(v75 * 0.0);
        v80 = (float)(v75 * 0.0) - v74.m128_f32[0];
        v81.m128_f32[0] = (float)(v74.m128_f32[0] * 0.0) - (float)(v73.m128_f32[0] * 0.0);
        v82 = (float)((float)(v80 * y) + (float)(v79.m128_f32[0] * x)) + (float)(v81.m128_f32[0] * z);
        if ( v82 <= 0.0 )
        {
          if ( v82 >= 0.0 )
            v21 = 0i64;
          else
            v21 = (__m128)LODWORD(FLOAT_N1_0);
        }
        v83 = this->mRigidBody;
        v84 = v80 * v21.m128_f32[0];
        v81.m128_f32[0] = v81.m128_f32[0] * v21.m128_f32[0];
        v85 = v81;
        v79.m128_f32[0] = v79.m128_f32[0] * v21.m128_f32[0];
        v86 = v79;
        v85.m128_f32[0] = (float)(v81.m128_f32[0] * y) - (float)(v84 * z);
        v86.m128_f32[0] = (float)(v79.m128_f32[0] * z) - (float)(v81.m128_f32[0] * x);
        v21.m128_f32[0] = (float)(v21.m128_f32[0] * 0.30000001)
                        + (float)((float)(v84 * x) - (float)(v79.m128_f32[0] * y));
        v113 = _mm_unpacklo_ps(_mm_unpacklo_ps(v85, v21), _mm_unpacklo_ps(v86, (__m128)0i64));
        v87 = v83->mBody;
        hkpEntity::activate(v87);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v87->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v87->m_motion,
          &v113);
      }
      v88 = this->mRigidBody;
      v89 = v88->mBody->m_motion.m_linearVelocity.m_quad;
      v90 = _mm_shuffle_ps(v89, v89, 85);
      v91 = _mm_shuffle_ps(v89, v89, 170);
      v111 = v89;
      v92 = (float)((float)(v90.m128_f32[0] * v73.m128_f32[0]) + (float)(v89.m128_f32[0] * v74.m128_f32[0]))
          + (float)(v91.m128_f32[0] * v75);
      if ( v92 < 0.0 && distance[0] < 4.0 )
      {
        v89.m128_f32[0] = v89.m128_f32[0] - (float)(v74.m128_f32[0] * v92);
        v91.m128_f32[0] = v91.m128_f32[0] - (float)(v75 * v92);
        v90.m128_f32[0] = v90.m128_f32[0] - (float)(v73.m128_f32[0] * v92);
        v111 = _mm_unpacklo_ps(_mm_unpacklo_ps(v89, v91), _mm_unpacklo_ps(v90, (__m128)0i64));
      }
      v93 = v88->mBody;
      hkpEntity::activate(v93);
      p_centerOfMass = (hkVector4f *)&v111;
    }
    v93->m_motion.vfptr[9].__vecDelDtor(&v93->m_motion, (unsigned int)p_centerOfMass);
  }
}

// File Line: 463
// RVA: 0x46EA30
void __fastcall UFG::PhysicsBoat::OnEnterWater(UFG::PhysicsBoat *this)
{
  hkpRigidBody *mBody; // rcx
  float v2; // xmm6_4
  float v3; // xmm7_4
  float v4; // xmm8_4
  float v5; // xmm9_4
  UFG::qVector4 v6; // [rsp+20h] [rbp-41h] BYREF
  UFG::qMatrix44 transform; // [rsp+38h] [rbp-29h] BYREF
  UFG::OneShotHandle retaddr; // [rsp+C8h] [rbp+67h] BYREF

  *((_DWORD *)this + 246) &= ~4u;
  mBody = this->mRigidBody->mBody;
  v2 = mBody->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[0];
  v3 = mBody->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[1];
  v4 = mBody->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[2];
  v5 = mBody->m_motion.m_motionState.m_transform.m_translation.m_quad.m128_f32[3];
  v6.x = v2;
  v6.y = v3;
  v6.z = v4;
  v6.w = v5;
  if ( UFG::TiDo::Distance2FromListener(UFG::TiDo::m_pInstance, 0, &v6) <= 400.0 )
  {
    retaddr.m_pOneShot = 0i64;
    transform.v0 = UFG::qMatrix44::msIdentity.v0;
    transform.v1 = UFG::qMatrix44::msIdentity.v1;
    transform.v2 = UFG::qMatrix44::msIdentity.v2;
    transform.v3.x = v2;
    transform.v3.y = v3;
    transform.v3.z = v4;
    transform.v3.w = v5;
    UFG::OneShotPool::GetOneShotHandle(&retaddr, &transform);
    if ( UFG::OneShotHandle::IsValid(&retaddr) )
      UFG::OneShot::Play(retaddr.m_pOneShot, 0x4FEB6CE0u);
    UFG::OneShotHandle::Release(&retaddr);
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
  hkpRigidBody *mBody; // rdx
  __m128 v2; // xmm1
  __m128 v3; // xmm3
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  __m128 v7; // xmm1

  mBody = this->mRigidBody->mBody;
  v2 = _mm_mul_ps(mBody->m_motion.m_linearVelocity.m_quad, mBody->m_motion.m_linearVelocity.m_quad);
  v3 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)), _mm_shuffle_ps(v2, v2, 170));
  v4 = _mm_rsqrt_ps(v3);
  v5 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v4, v3), v4));
  v6 = _mm_mul_ps(*(__m128 *)_xmm, v4);
  v7 = _mm_mul_ps(_xmm, mBody->m_motion.m_angularVelocity.m_quad);
  return atanf(
           (float)((float)((float)(_mm_shuffle_ps(v7, v7, 85).m128_f32[0] + _mm_shuffle_ps(v7, v7, 0).m128_f32[0])
                         + _mm_shuffle_ps(v7, v7, 170).m128_f32[0])
                 * this->mLeanFactor)
         / (float)(fsqrt(COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                        _mm_andnot_ps(
                                          _mm_cmple_ps(v3, (__m128)0i64),
                                          _mm_mul_ps(_mm_mul_ps(v5, v6), v3)).m128_f32[0]
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
  UFG::BoatAction *mBoatAction; // rdx
  int v3; // eax

  this->mEngineDamage = damage;
  if ( damage < 1.0 )
  {
    mBoatAction = this->mBoatAction;
    v3 = *((_DWORD *)mBoatAction + 14);
    if ( (v3 & 2) == 0 )
      *((_DWORD *)mBoatAction + 14) = v3 & 0xFFFFFFFE;
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
  float *mBuoyancyFactor; // rsi
  unsigned __int64 *v3; // rdi
  __int64 v4; // r15
  Render::DebugDrawContext *Context; // r14
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  float x; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  double v21; // xmm1_8
  float v22; // xmm2_4
  UFG::RigidBodyComponent *mRigidBody; // rcx
  hkpRigidBody *mBody; // rax
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
  float mRudderAngle; // xmm6_4
  float v39; // xmm8_4
  float v40; // xmm10_4
  float v41; // xmm9_4
  float v42; // xmm7_4
  float v43; // xmm12_4
  float v44; // xmm11_4
  float v45; // xmm6_4
  UFG::qVector3 world_position; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qVector3 v47; // [rsp+50h] [rbp-98h] BYREF
  UFG::qVector3 p0; // [rsp+60h] [rbp-88h] BYREF
  int v49; // [rsp+6Ch] [rbp-7Ch]
  UFG::qVector3 aabb_max; // [rsp+70h] [rbp-78h] BYREF
  UFG::qVector3 v51; // [rsp+7Ch] [rbp-6Ch] BYREF
  float v52; // [rsp+88h] [rbp-60h]
  float v53; // [rsp+8Ch] [rbp-5Ch]
  float v54; // [rsp+90h] [rbp-58h]
  float v55; // [rsp+94h] [rbp-54h]
  float v56; // [rsp+98h] [rbp-50h]
  float v57; // [rsp+9Ch] [rbp-4Ch]
  float v58; // [rsp+A0h] [rbp-48h]
  float v59; // [rsp+A4h] [rbp-44h]
  float v60; // [rsp+A8h] [rbp-40h]
  float v61; // [rsp+ACh] [rbp-3Ch]
  float v62; // [rsp+B0h] [rbp-38h]
  int v63; // [rsp+B4h] [rbp-34h]
  hkVector4f v64; // [rsp+B8h] [rbp-30h] BYREF
  hkVector4f v65; // [rsp+C8h] [rbp-20h] BYREF
  hkTransformf a; // [rsp+D8h] [rbp-10h] BYREF

  mBuoyancyFactor = this->mBuoyancyFactor;
  v3 = &this->mFloatPositionWorldSpace[0].m_quad.m128_u64[1];
  v4 = 4i64;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  do
  {
    y = this->mBodyTransform.v0.y;
    aabb_max.z = this->mBodyTransform.v0.x;
    z = this->mBodyTransform.v0.z;
    v51.x = y;
    v63 = 1065353216;
    w = this->mBodyTransform.v0.w;
    v51.y = z;
    x = this->mBodyTransform.v1.x;
    aabb_max.x = 0.5;
    aabb_max.y = 0.5;
    aabb_max.z = 0.5;
    v52 = x;
    v10 = this->mBodyTransform.v1.z;
    v51.z = w;
    v51.x = -0.5;
    p0.z = -0.5;
    v49 = -1090519040;
    v11 = this->mBodyTransform.v1.y;
    v54 = v10;
    v12 = this->mBodyTransform.v2.x;
    v53 = v11;
    v13 = this->mBodyTransform.v1.w;
    v56 = v12;
    v14 = this->mBodyTransform.v2.z;
    v55 = v13;
    v15 = this->mBodyTransform.v2.y;
    v58 = v14;
    v16 = *((float *)v3 - 2);
    v57 = v15;
    v17 = this->mBodyTransform.v2.w;
    v60 = v16;
    v18 = *(float *)v3;
    v59 = v17;
    v19 = *((float *)v3 - 1);
    v62 = v18;
    v61 = v19;
    Render::DebugDrawContext::DrawAABB(
      Context,
      &v51,
      &aabb_max,
      &UFG::qColour::Green,
      (UFG::qMatrix44 *)&aabb_max.z,
      0i64);
    v20 = *(mBuoyancyFactor - 8);
    world_position.y = v61;
    v21 = v20;
    v22 = v20 * *mBuoyancyFactor;
    world_position.x = v60;
    world_position.z = v62;
    Render::DebugDrawContext::DrawText(Context, &world_position, &UFG::qColour::Red, "buoyancy %f / %f", v22, v21);
    v3 += 2;
    ++mBuoyancyFactor;
    --v4;
  }
  while ( v4 );
  mRigidBody = this->mRigidBody;
  mBody = mRigidBody->mBody;
  v25.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v26.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
  v27.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  a.m_rotation.m_col1 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  a.m_translation = (hkVector4f)v26.m_quad;
  a.m_rotation.m_col0 = (hkVector4f)v27.m_quad;
  a.m_rotation.m_col2 = (hkVector4f)v25.m_quad;
  v28 = (__m128 *)mRigidBody->mBody;
  v29 = _mm_mul_ps(v28[35], v28[35]);
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)), _mm_shuffle_ps(v29, v29, 170));
  v31 = _mm_rsqrt_ps(v30);
  v32 = _mm_cmple_ps(v30, (__m128)0i64);
  v33 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31));
  v34 = _mm_mul_ps(*(__m128 *)_xmm, v31);
  v35 = _mm_mul_ps(_xmm, v28[36]);
  v36 = _mm_mul_ps(_mm_mul_ps(v33, v34), v30);
  v37 = (float)((float)(_mm_shuffle_ps(v35, v35, 85).m128_f32[0] + _mm_shuffle_ps(v35, v35, 0).m128_f32[0])
              + _mm_shuffle_ps(v35, v35, 170).m128_f32[0])
      * this->mLeanFactor;
  v30.m128_i32[0] = LODWORD(this->mBodyTransform.v3.z);
  v32.m128_f32[0] = _mm_andnot_ps(v32, v36).m128_f32[0];
  v36.m128_i32[0] = LODWORD(this->mBodyTransform.v3.y);
  world_position.x = this->mBodyTransform.v3.x;
  LODWORD(world_position.y) = v36.m128_i32[0];
  world_position.z = v30.m128_f32[0] + 1.0;
  v34.m128_f32[0] = atanf(v37 / (float)(fsqrt(COERCE_FLOAT(COERCE_UNSIGNED_INT(v32.m128_f32[0] * 0.25) & _xmm)) + 1.0));
  Render::DebugDrawContext::DrawText(
    Context,
    &world_position,
    &UFG::qColour::White,
    "leanAngle %f",
    (float)(v34.m128_f32[0] * 0.5));
  hkVector4f::setTransformedPos(&v64, &a, &this->mRudderOffset);
  mRudderAngle = this->mRudderAngle;
  v39 = v64.m_quad.m128_f32[0];
  v40 = v64.m_quad.m128_f32[2] + 1.5;
  v41 = v64.m_quad.m128_f32[1];
  *(_QWORD *)&p0.x = v64.m_quad.m128_u64[0];
  p0.z = v64.m_quad.m128_f32[2] + 1.5;
  LODWORD(v42) = COERCE_UNSIGNED_INT(cosf(mRudderAngle)) ^ _xmm[0];
  sinf(mRudderAngle);
  v43 = (float)((float)(mRudderAngle * this->mBodyTransform.v1.z) + (float)(v42 * this->mBodyTransform.v0.z))
      + (float)(this->mBodyTransform.v2.z * 0.0);
  v44 = (float)((float)(mRudderAngle * this->mBodyTransform.v1.x) + (float)(v42 * this->mBodyTransform.v0.x))
      + (float)(this->mBodyTransform.v2.x * 0.0);
  v45 = (float)((float)(mRudderAngle * this->mBodyTransform.v1.y) + (float)(v42 * this->mBodyTransform.v0.y))
      + (float)(this->mBodyTransform.v2.y * 0.0);
  world_position.z = v43 + v40;
  world_position.x = v39 + v44;
  world_position.y = v41 + v45;
  Render::DebugDrawContext::DrawLine(
    Context,
    &p0,
    &world_position,
    &UFG::qColour::Green,
    &UFG::qMatrix44::msIdentity,
    0i64,
    0);
  hkVector4f::setTransformedPos(&v65, &a, &this->mBowThrusterOffset);
  *(_QWORD *)&v47.x = v65.m_quad.m128_u64[0];
  world_position.z = v43 + (float)(v65.m_quad.m128_f32[2] + 1.5);
  v47.z = v65.m_quad.m128_f32[2] + 1.5;
  world_position.x = v65.m_quad.m128_f32[0] + v44;
  world_position.y = v65.m_quad.m128_f32[1] + v45;
  Render::DebugDrawContext::DrawLine(
    Context,
    &v47,
    &world_position,
    &UFG::qColour::Green,
    &UFG::qMatrix44::msIdentity,
    0i64,
    0);
}

// File Line: 621
// RVA: 0x474CB0
void __fastcall UFG::PhysicsBoat::SetLevelOfDetailInternal(UFG::PhysicsBoat *this, int lod)
{
  if ( lod > 0 )
  {
    if ( lod <= 2 )
    {
LABEL_5:
      UFG::BasePhysicsSystem::RemoveAction(UFG::BasePhysicsSystem::mInstance, this->mBoatAction);
      return;
    }
    if ( lod == 3 )
    {
      UFG::BasePhysicsSystem::AddAction(UFG::BasePhysicsSystem::mInstance, this->mBoatAction);
    }
    else if ( lod == 4 )
    {
      goto LABEL_5;
    }
  }
}

// File Line: 684
// RVA: 0x481260
void __fastcall UFG::BoatAction::applyAction(UFG::BoatAction *this, hkStepInfo *stepInfo)
{
  __m128 v2; // xmm7
  UFG::PhysicsBoat *mBoat; // rbx
  __m128 v4; // xmm6
  float *v7; // rsi
  hkpRigidBody *mBody; // r14
  hkVector4f v9; // xmm3
  hkVector4f v10; // xmm2
  hkVector4f v11; // xmm0
  __m128 v12; // xmm15
  hkVector4f v13; // xmm0
  __m128 v14; // xmm14
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  float v18; // xmm11_4
  __m128 v19; // xmm1
  float v20; // xmm8_4
  __m128 mChopDist_low; // xmm1
  float v22; // xmm8_4
  __m128 v23; // xmm7
  __m128 v24; // xmm10
  __m128 v25; // xmm0
  __m128 v26; // xmm6
  __m128 v27; // xmm0
  float mEngineThrustAngle; // xmm2_4
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
  __m128 m_storage_low; // xmm6
  __int64 v42; // rdx
  UFG::PhysicsBoat *v43; // rbx
  __m128 v44; // xmm1
  __m128 v45; // xmm7
  __m128 v46; // xmm5
  __m128 v47; // xmm3
  __m128 v48; // xmm2
  float v49; // xmm4_4
  __m128 mViscousDragLateral_low; // xmm1
  float mQuadraticDragLateralVelocityLimit; // xmm2_4
  int v52; // eax
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm1
  __m128 v56; // xmm4
  __m128 v57; // xmm2
  float v58; // xmm0_4
  float mEngineDamage; // xmm1_4
  __m128 v60; // xmm0
  float v61; // xmm2_4
  float v62; // xmm1_4
  __m128 v63; // xmm6
  __int64 v64; // rdx
  float v65; // xmm6_4
  hkVector4f *v66; // r8
  UFG::PhysicsBoat *v67; // rax
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm8_4
  __m128 v71; // xmm0
  __m128 v72; // xmm6
  __m128 v73; // xmm0
  __m128 v74; // xmm0
  __m128 v75; // xmm6
  __int64 v76; // rdx
  UFG::PhysicsBoat *v77; // rax
  __int64 v78; // r13
  __int64 v79; // rcx
  hkpMaxSizeMotion *p_m_motion; // rsi
  __int64 v81; // r15
  float mTorqueDamping; // xmm0_4
  __m128 v83; // xmm1
  __m128 v84; // xmm3
  __m128 v85; // xmm0
  UFG::PhysicsBoat *v86; // rax
  __m128 v87; // xmm0
  __m128 v88; // xmm3
  __m128 m_quad; // xmm0
  __m128 v90; // xmm2
  __m128 v91; // xmm1
  __m128 v92; // xmm2
  __m128 v93; // xmm0
  __m128 v94; // xmm2
  __m128 v95; // xmm6
  char *v96; // rbx
  __int64 v97; // rdx
  bool v98; // zf
  __int64 v99; // r13
  UFG::PhysicsBoat *v100; // rax
  __m128 mLastChop_low; // xmm0
  UFG::PhysicsBoat *v102; // rax
  UFG::PhysicsBoat *v103; // rax
  float v104; // xmm6_4
  float Value; // xmm8_4
  __m128 v106; // xmm10
  float v107; // xmm0_4
  bool v108; // cf
  UFG::PhysicsBoat *v109; // rax
  __m128 v110; // xmm15
  __m128 v111; // xmm1
  __m128 v112; // xmm2
  __m128 v113; // xmm3
  __m128 v114; // xmm1
  __m128 v115; // xmm11
  __m128 v116; // xmm11
  __m128 v117; // xmm1
  __m128 v118; // xmm3
  __m128 v119; // xmm2
  __m128 v120; // xmm11
  __m128 v121; // xmm2
  __m128 v122; // xmm9
  __m128 v123; // xmm7
  __m128 v124; // xmm2
  __m128 v125; // xmm5
  __m128 v126; // xmm4
  __m128 v127; // xmm3
  __m128 v128; // xmm2
  __m128 v129; // xmm0
  __m128 v130; // xmm4
  __m128 v131; // xmm4
  __m128 v132; // xmm1
  __m128 v133; // xmm2
  __m128 v134; // xmm1
  __m128 v135; // xmm3
  __m128 v136; // xmm0
  __m128 v137; // xmm2
  hkpReorientAction *mReorientActionRoll; // rcx
  __m128 v139; // xmm0
  __m128 v140; // xmm3
  __int64 v141; // r15
  UFG::PhysicsBoat *v142; // rax
  __m128 v143; // xmm0
  __m128 v144; // xmm6
  char *v145; // rbx
  __int64 v146; // rdx
  UFG::PhysicsBoat *v147; // rbx
  __m128 v148; // xmm0
  __m128 v149; // xmm2
  __m128 v150; // xmm1
  __m128 v151; // xmm8
  __m128 v152; // xmm0
  __m128 v153; // xmm8
  float v154; // xmm7_4
  __m128 v155; // xmm1
  float v156; // xmm1_4
  __m128 *v157; // rax
  hkpReorientAction *mReorientActionPitch; // rcx
  UFG::PhysicsBoat *v159; // rax
  __m128 v160; // xmm0
  float mVerticalVelocityDampingDown; // xmm1_4
  UFG::PhysicsBoat *v162; // rcx
  int v163; // eax
  UFG::PhysicsBoat *v164; // rax
  __int64 v165; // rdx
  __int64 v166; // rdx
  hkVector4f v167; // [rsp+20h] [rbp-B8h] BYREF
  hkVector4f v168; // [rsp+30h] [rbp-A8h] BYREF
  __m128 v169; // [rsp+40h] [rbp-98h] BYREF
  _BYTE v170[56]; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f direction; // [rsp+88h] [rbp-50h] BYREF
  __m128 v172; // [rsp+98h] [rbp-40h] BYREF
  hkTransformf a; // [rsp+A8h] [rbp-30h] BYREF
  hkVector4f b; // [rsp+E8h] [rbp+10h] BYREF
  hkVector4f axis; // [rsp+F8h] [rbp+20h] BYREF
  hkVector4f v176; // [rsp+108h] [rbp+30h] BYREF
  hkRotationf v177; // [rsp+118h] [rbp+40h] BYREF
  __m128 v178; // [rsp+1F0h] [rbp+118h]
  float X[2]; // [rsp+238h] [rbp+160h]
  float angle; // [rsp+240h] [rbp+168h]
  __int64 v181; // [rsp+248h] [rbp+170h]
  __int64 vars0; // [rsp+250h] [rbp+178h]

  v4 = _xmm;
  mBoat = this->mBoat;
  v7 = (float *)UFG::BasePhysicsSystem::mInstance;
  v178 = v2;
  mBody = mBoat->mRigidBody->mBody;
  v169 = 0i64;
  *(_OWORD *)&v170[16] = 0i64;
  v9.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  v10.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_translation;
  v11.m_quad = (__m128)mBody->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  a.m_rotation.m_col2 = mBody->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  *(hkVector4f *)&v170[8] = (hkVector4f)v9.m_quad;
  *(_DWORD *)&v170[20] = 0;
  v12 = *(__m128 *)&v170[8];
  a.m_rotation.m_col1 = (hkVector4f)v11.m_quad;
  a.m_rotation.m_col0 = (hkVector4f)v9.m_quad;
  a.m_translation = (hkVector4f)v10.m_quad;
  v13.m_quad = (__m128)mBody->m_motion.m_linearVelocity;
  direction.m_quad = _xmm;
  *(hkVector4f *)&v170[32] = (hkVector4f)v13.m_quad;
  *(_DWORD *)&v170[44] = 0;
  v14 = *(__m128 *)&v170[32];
  v15 = _mm_mul_ps(*(__m128 *)&v170[32], *(__m128 *)&v170[32]);
  v16 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)), _mm_shuffle_ps(v15, v15, 170));
  v17 = _mm_rsqrt_ps(v16);
  LODWORD(v18) = _mm_andnot_ps(
                   _mm_cmple_ps(v16, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                       _mm_mul_ps(v17, *(__m128 *)_xmm)),
                     v16)).m128_u32[0];
  v19 = _mm_mul_ps(*(__m128 *)&v170[8], *(__m128 *)&v170[32]);
  v20 = _mm_shuffle_ps(v19, v19, 85).m128_f32[0];
  v13.m_quad.m128_f32[0] = _mm_shuffle_ps(v19, v19, 0).m128_f32[0];
  mChopDist_low = _mm_shuffle_ps(v19, v19, 170);
  v22 = (float)(v20 + v13.m_quad.m128_f32[0]) + mChopDist_low.m128_f32[0];
  v2.m128_f32[0] = v22;
  v23 = _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), *(__m128 *)&v170[8]);
  v24 = _mm_sub_ps(*(__m128 *)&v170[32], v23);
  *(__m128 *)v170 = v24;
  LODWORD(angle) = COERCE_UNSIGNED_INT(UFG::PhysicsBoat::GetLeanAngle(mBoat)) ^ _xmm[0];
  if ( (float)((float)((float)(mBoat->mBuoyancyFactor[1] + mBoat->mBuoyancyFactor[0]) + mBoat->mBuoyancyFactor[2])
             + mBoat->mBuoyancyFactor[3]) >= 0.1 )
  {
    X[0] = mBoat->mRudderAngle;
    v25 = (__m128)LODWORD(X[0]);
    v25.m128_f32[0] = cosf(X[0]);
    v26 = v25;
    v27 = (__m128)LODWORD(X[0]);
    v27.m128_f32[0] = sinf(X[0]);
    axis.m_quad = _xmm;
    b.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps(_mm_xor_ps(v26, (__m128)(unsigned int)_xmm[0]), (__m128)0i64),
                 _mm_unpacklo_ps(v27, (__m128)0i64));
    mEngineThrustAngle = mBoat->mEngineThrustAngle;
    if ( mBoat->mThrottle < 0.0 )
      mEngineThrustAngle = 0.0;
    hkRotationf::setAxisAngle(&v177, &axis, mEngineThrustAngle);
    hkVector4f::setRotatedDir((hkVector4f *)&v170[8], &v177, &b);
    hkVector4f::setRotatedDir((hkVector4f *)&v170[8], &a.m_rotation, (hkVector4f *)&v170[8]);
    hkVector4f::setRotatedDir(&v176, &a.m_rotation, &b);
    hkVector4f::setTransformedPos((hkVector4f *)&v170[32], &a, &this->mBoat->mRudderOffset);
    v29 = this->mBoat;
    v30 = _mm_shuffle_ps(v176.m_quad, v176.m_quad, 201);
    v31 = _mm_sub_ps(_mm_mul_ps(v12, v30), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v176.m_quad));
    v32 = _mm_shuffle_ps(v31, v31, 201);
    v33 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v176.m_quad), _mm_mul_ps(v32, v30));
    v34 = _mm_mul_ps(v23, v23);
    v35 = _mm_shuffle_ps(v33, v33, 201);
    v172 = v35;
    v36 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v34, v34, 85), _mm_shuffle_ps(v34, v34, 0)),
            _mm_shuffle_ps(v34, v34, 170));
    v37 = _mm_rsqrt_ps(v36);
    v38 = 0i64;
    v38.m128_f32[0] = fsqrt(_mm_andnot_ps(
                              _mm_cmple_ps(v36, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_mul_ps(
                                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                                  _mm_mul_ps(v37, *(__m128 *)_xmm)),
                                v36)).m128_f32[0]);
    if ( v22 >= 0.0 )
    {
      v39 = _mm_xor_ps((__m128)LODWORD(v29->mRudderForceMultiplier), (__m128)(unsigned int)_xmm[0]);
    }
    else
    {
      v39 = (__m128)LODWORD(UFG::PhysicsBoat::mRudderExtraMultiplierWhenGoingBackwards);
      v39.m128_f32[0] = UFG::PhysicsBoat::mRudderExtraMultiplierWhenGoingBackwards * v29->mRudderForceMultiplier;
    }
    v40 = *((_DWORD *)this + 14);
    v39.m128_f32[0] = v39.m128_f32[0] * v38.m128_f32[0];
    v172 = _mm_mul_ps(v35, _mm_shuffle_ps(v39, v39, 0));
    if ( (v40 & 4) == 0 && (v40 & 1) == 0 )
    {
      m_storage_low = (__m128)LODWORD(stepInfo->m_deltaTime.m_storage);
      hkpEntity::activate(mBody);
      v38 = m_storage_low;
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *, _BYTE *))mBody->m_motion.hkpEntity::vfptr[12].__first_virtual_table_function__)(
        &mBody->m_motion,
        v42,
        &v172,
        &v170[32]);
    }
    v43 = this->mBoat;
    v38.m128_i32[0] = LODWORD(v43->mViscousDrag) ^ _xmm[0];
    v44 = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v23);
    v45 = _mm_mul_ps(v24, v24);
    v46 = _mm_add_ps(v169, v44);
    v169 = v46;
    v47 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
            _mm_shuffle_ps(v45, v45, 170));
    v48 = _mm_rsqrt_ps(v47);
    LODWORD(v49) = _mm_andnot_ps(
                     _mm_cmple_ps(v47, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v48, v47), v48)),
                         _mm_mul_ps(v48, *(__m128 *)_xmm)),
                       v47)).m128_u32[0];
    mViscousDragLateral_low = (__m128)LODWORD(v43->mViscousDragLateral);
    if ( ((*((_DWORD *)v43 + 246) >> 1) & 1) != 0 )
      mViscousDragLateral_low.m128_f32[0] = mViscousDragLateral_low.m128_f32[0] * 0.1;
    mQuadraticDragLateralVelocityLimit = v43->mQuadraticDragLateralVelocityLimit;
    if ( v49 < mQuadraticDragLateralVelocityLimit || ((*((_DWORD *)v43 + 246) >> 1) & 1) != 0 )
      mViscousDragLateral_low = _mm_xor_ps(mViscousDragLateral_low, (__m128)(unsigned int)_xmm[0]);
    else
      mViscousDragLateral_low.m128_i32[0] = COERCE_UNSIGNED_INT(
                                              (float)((float)((float)((float)(v49 - mQuadraticDragLateralVelocityLimit)
                                                                    * (float)(v49 - mQuadraticDragLateralVelocityLimit))
                                                            + mQuadraticDragLateralVelocityLimit)
                                                    / v49)
                                            * mViscousDragLateral_low.m128_f32[0]) ^ _xmm[0];
    v52 = *((_DWORD *)this + 14);
    v53 = _mm_shuffle_ps(v12, v12, 85);
    v169 = _mm_add_ps(v46, _mm_mul_ps(_mm_shuffle_ps(mViscousDragLateral_low, mViscousDragLateral_low, 0), v24));
    v54 = 0i64;
    v53.m128_f32[0] = (float)((float)(v53.m128_f32[0] * v14.m128_f32[0])
                            - (float)(v12.m128_f32[0] * _mm_shuffle_ps(v14, v14, 85).m128_f32[0]))
                    * v43->mKeelTorque;
    *(__m128 *)&v170[16] = _mm_add_ps(
                             *(__m128 *)&v170[16],
                             _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v53), (__m128)0i64));
    if ( (v52 & 4) == 0 && (v52 & 1) == 0 )
    {
      v55 = _mm_mul_ps(*(__m128 *)&v170[32], *(__m128 *)&v170[32]);
      v56 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
              _mm_shuffle_ps(v55, v55, 170));
      v57 = _mm_rsqrt_ps(v56);
      v54 = (__m128)LODWORD(FLOAT_6_2800002);
      v58 = fmodf(
              (float)(_mm_andnot_ps(
                        _mm_cmple_ps(v56, (__m128)0i64),
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v57, v56), v57)),
                            _mm_mul_ps(v57, *(__m128 *)_xmm)),
                          v56)).m128_f32[0]
                    * v7[24963])
            + v7[24964],
              6.2800002);
      if ( *(float *)&v170[40] <= (float)((float)(cosf(v58) * v7[24961]) + v7[24960]) )
      {
        mEngineDamage = v43->mEngineDamage;
        v60 = (__m128)(unsigned int)FLOAT_1_0;
        if ( mEngineDamage >= 0.80000001 )
          v60.m128_f32[0] = 1.0 - mEngineDamage;
        v61 = v43->mBuoyancyFactor[1] + v43->mBuoyancyFactor[0];
        v62 = (float)(v43->mMaxEngineThrust * v43->mThrottle) * v60.m128_f32[0];
        if ( v61 <= 0.1 )
        {
          v60 = (__m128)LODWORD(v43->mBuoyancyFactor[3]);
          if ( (float)(v61 * 2.0) < (float)(v60.m128_f32[0] + v43->mBuoyancyFactor[2]) )
            v62 = v62 * 0.5;
        }
        v63 = (__m128)LODWORD(stepInfo->m_deltaTime.m_storage);
        v60.m128_i32[0] = LODWORD(v62) ^ _xmm[0];
        v168.m_quad = _mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), *(__m128 *)&v170[8]);
        hkpEntity::activate(mBody);
        v54 = v63;
        ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, _BYTE *))mBody->m_motion.hkpEntity::vfptr[12].__first_virtual_table_function__)(
          &mBody->m_motion,
          v64,
          &v168,
          &v170[32]);
      }
      v65 = X[0];
      if ( COERCE_FLOAT(LODWORD(X[0]) & _xmm) > 0.087266468 && v22 >= 0.0 )
      {
        v66 = (hkVector4f *)this->mBoat;
        if ( (v66[61].m_quad.m128_i8[8] & 1) != 0 || v22 < v66[53].m_quad.m128_f32[0] )
        {
          hkVector4f::setTransformedPos((hkVector4f *)&v170[40], &a, v66 + 52);
          v67 = this->mBoat;
          v68 = *(float *)&FLOAT_1_0;
          v69 = v67->mEngineDamage;
          if ( v69 >= 0.80000001 )
            v68 = 1.0 - v69;
          v70 = (float)((float)(v67->mMaxEngineThrust * v67->mThrottle) * v68) * v67->mBowThrusterPower;
          if ( v65 <= 0.0 )
            v71 = (__m128)LODWORD(FLOAT_1_5707964);
          else
            v71 = (__m128)LODWORD(FLOAT_N1_5707964);
          X[0] = v71.m128_f32[0];
          v71.m128_f32[0] = cosf(v71.m128_f32[0]);
          v72 = v71;
          v73 = (__m128)LODWORD(X[0]);
          v73.m128_f32[0] = sinf(X[0]);
          v74 = _mm_unpacklo_ps(v73, (__m128)0i64);
          v168.m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(_mm_xor_ps(v72, (__m128)(unsigned int)_xmm[0]), (__m128)0i64),
                          v74);
          hkVector4f::setRotatedDir(&v167, &a.m_rotation, &v168);
          v75 = (__m128)LODWORD(stepInfo->m_deltaTime.m_storage);
          v74.m128_i32[0] = LODWORD(v70) ^ _xmm[0];
          *(__m128 *)&v170[24] = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 0), v167.m_quad);
          hkpEntity::activate(mBody);
          v54 = v75;
          ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, _BYTE *, _BYTE *))mBody->m_motion.hkpEntity::vfptr[12].__first_virtual_table_function__)(
            &mBody->m_motion,
            v76,
            &v170[24],
            &v170[40]);
        }
      }
    }
    v77 = this->mBoat;
    v78 = 688i64;
    v79 = 688i64;
    p_m_motion = &mBody->m_motion;
    v81 = 784i64;
    mTorqueDamping = v77->mTorqueDamping;
    *(_QWORD *)X = 688i64;
    v54.m128_i32[0] = LODWORD(mTorqueDamping) ^ _xmm[0];
    *(__m128 *)&v170[16] = _mm_add_ps(
                             *(__m128 *)&v170[16],
                             _mm_mul_ps(_mm_shuffle_ps(v54, v54, 0), mBody->m_motion.m_angularVelocity.m_quad));
    v83 = _mm_mul_ps(a.m_rotation.m_col1.m_quad, mBody->m_motion.m_angularVelocity.m_quad);
    v84 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v83, v83, 85), _mm_shuffle_ps(v83, v83, 0)),
            _mm_shuffle_ps(v83, v83, 170));
    v84.m128_f32[0] = v84.m128_f32[0] * v77->mTorqueDampingBowScale;
    vars0 = 4i64;
    v181 = 4i64;
    v85 = _mm_xor_ps(v84, (__m128)(unsigned int)_xmm[0]);
    *(__m128 *)&v170[16] = _mm_add_ps(
                             *(__m128 *)&v170[16],
                             _mm_mul_ps(
                               _mm_unpacklo_ps(_mm_unpacklo_ps(v85, v85), _mm_unpacklo_ps(v85, (__m128)0i64)),
                               a.m_rotation.m_col1.m_quad));
    do
    {
      v86 = this->mBoat;
      v87 = (__m128)*(unsigned int *)((char *)v86 + v81 - 32);
      v87.m128_f32[0] = v87.m128_f32[0] * *(float *)((char *)&v86->vfptr + v81);
      v88 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v87), (__m128)0i64);
      v168.m_quad = v88;
      if ( *(float *)((char *)&v86->vfptr + v81) > 0.1 )
      {
        m_quad = mBody->m_motion.m_angularVelocity.m_quad;
        v90 = _mm_sub_ps(
                *(__m128 *)((char *)&v86->vfptr + v79),
                mBody->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v91 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v90);
        v92 = _mm_mul_ps(_mm_shuffle_ps(v90, v90, 201), m_quad);
        v93 = _mm_shuffle_ps(
                (__m128)*(unsigned int *)((char *)v86 + v81 - 16),
                (__m128)*(unsigned int *)((char *)v86 + v81 - 16),
                0);
        v94 = _mm_sub_ps(v92, v91);
        v167.m_quad.m128_u64[1] = *(unsigned __int128 *)&_mm_add_ps(
                                                           _mm_shuffle_ps(v94, v94, 201),
                                                           mBody->m_motion.m_linearVelocity.m_quad) >> 64;
        v167.m_quad.m128_u64[0] = 0i64;
        v168.m_quad = _mm_add_ps(v88, _mm_mul_ps(v93, v167.m_quad));
      }
      v95 = (__m128)LODWORD(stepInfo->m_deltaTime.m_storage);
      v96 = (char *)v86 + v78;
      hkpEntity::activate(mBody);
      mChopDist_low = v95;
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, hkVector4f *, char *))p_m_motion->vfptr[12].__first_virtual_table_function__)(
        &mBody->m_motion,
        v97,
        &v168,
        v96);
      v78 += 16i64;
      v79 = *(_QWORD *)X + 16i64;
      v81 += 4i64;
      v98 = v181-- == 1;
      *(_QWORD *)X += 16i64;
    }
    while ( !v98 );
    v99 = 688i64;
    if ( (*((_BYTE *)this + 56) & 1) != 0 || v18 <= 5.0 )
      goto LABEL_48;
    v100 = this->mBoat;
    mLastChop_low = (__m128)LODWORD(v100->mLastChop);
    v100->mLastChop = mLastChop_low.m128_f32[0] - stepInfo->m_deltaTime.m_storage;
    v102 = this->mBoat;
    if ( v102->mLastChop < 0.0 )
    {
      mLastChop_low = (__m128)LODWORD(UFG::PhysicsBoat::gChopPeriod);
      v102->mLastChop = UFG::PhysicsBoat::gChopPeriod;
      if ( mBody->m_motion.m_linearVelocity.m_quad.m128_f32[2] < UFG::PhysicsBoat::gChopZThreshold )
      {
        v103 = this->mBoat;
        mLastChop_low = (__m128)LODWORD(v103->mBuoyancyFactor[1]);
        if ( (float)((float)((float)(mLastChop_low.m128_f32[0] + v103->mBuoyancyFactor[0]) + v103->mBuoyancyFactor[2])
                   + v103->mBuoyancyFactor[3]) >= 0.1 )
        {
          mLastChop_low = (__m128)LODWORD(UFG::PhysicsBoat::gChopImpulse);
          *(__m128 *)&v170[24] = _mm_unpacklo_ps(
                                   _mm_unpacklo_ps((__m128)0i64, (__m128)LODWORD(UFG::PhysicsBoat::gChopImpulse)),
                                   (__m128)0i64);
          hkpEntity::activate(mBody);
          p_m_motion->vfptr[11].__vecDelDtor(&mBody->m_motion, (unsigned int)&v170[24]);
        }
      }
    }
    v104 = (float)(v18 * 0.2) + 1.0;
    Value = UFG::qNoise<float,float>::GetValue(
              &this->mBoat->mChopFunction,
              COERCE_DOUBLE((unsigned __int64)LODWORD(this->mBoat->mChopDist)));
    this->mBoat->mChopDist = (float)(v104 * stepInfo->m_deltaTime.m_storage) + this->mBoat->mChopDist;
    mLastChop_low.m128_f32[0] = UFG::qNoise<float,float>::GetValue(
                                  &this->mBoat->mChopFunction,
                                  COERCE_DOUBLE((unsigned __int64)LODWORD(this->mBoat->mChopDist)));
    v106 = mLastChop_low;
    this->mBoat->mChopDist = (float)(v104 * stepInfo->m_deltaTime.m_storage) + this->mBoat->mChopDist;
    v107 = UFG::qNoise<float,float>::GetValue(
             &this->mBoat->mChopFunction,
             COERCE_DOUBLE((unsigned __int64)LODWORD(this->mBoat->mChopDist)));
    v108 = Value < v106.m128_f32[0];
    v109 = this->mBoat;
    mChopDist_low = (__m128)LODWORD(v109->mChopDist);
    v109->mChopDist = mChopDist_low.m128_f32[0] - (float)(v104 * stepInfo->m_deltaTime.m_storage);
    if ( Value > v106.m128_f32[0] )
    {
      if ( v106.m128_f32[0] < v107 )
      {
        LODWORD(this->mBoat->mChopTrough) = v106.m128_i32[0];
        goto LABEL_48;
      }
      v108 = Value < v106.m128_f32[0];
    }
    if ( v108 && v106.m128_f32[0] > v107 )
    {
      v147 = this->mBoat;
      v148 = _mm_mul_ps((__m128)_xmm, v12);
      v110 = 0i64;
      v106.m128_f32[0] = v106.m128_f32[0] - v147->mChopTrough;
      v167.m_quad = _mm_add_ps(v148, mBody->m_motion.m_motionState.m_transform.m_translation.m_quad);
      v149 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
               _mm_shuffle_ps(v45, v45, 170));
      v150 = _mm_rsqrt_ps(v149);
      v151 = _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v150, v149), v150));
      v152 = _mm_mul_ps(*(__m128 *)_xmm, v150);
      v150.m128_u64[0] = LODWORD(v147->mChopDist);
      v150.m128_f32[0] = v150.m128_f32[0] * 20.0;
      v153 = _mm_mul_ps(v151, v152);
      v152.m128_f32[0] = UFG::qNoise<float,float>::GetValue(&v147->mChopFunction, *(double *)v150.m128_u64);
      v150.m128_u64[0] = LODWORD(v147->mChopDist);
      v154 = v152.m128_f32[0];
      v150.m128_f32[0] = (float)(v150.m128_f32[0] * 20.0) + 1.0;
      v152.m128_f32[0] = UFG::qNoise<float,float>::GetValue(&v147->mChopFunction, *(double *)v150.m128_u64);
      v155 = (__m128)LODWORD(FLOAT_10_0);
      v155.m128_f32[0] = (float)((float)(v154 - v152.m128_f32[0]) * 10.0)
                       / (float)((float)(COERCE_FLOAT(LODWORD(angle) & _xmm) * 10.0) + 1.0);
      v167.m_quad = _mm_add_ps(
                      v167.m_quad,
                      _mm_mul_ps(
                        _mm_shuffle_ps(v155, v155, 0),
                        _mm_mul_ps(_mm_andnot_ps(_mm_cmple_ps(v149, (__m128)0i64), v153), *(__m128 *)v170)));
      v156 = (float)(v18 - 5.0) * 0.2;
      if ( v156 > 1.5 )
        v156 = FLOAT_1_5;
      if ( v18 > 30.0 )
        v156 = v156 * (float)(30.0 / v18);
      v106.m128_f32[0] = (float)(v106.m128_f32[0] * 300.0) * v156;
      mChopDist_low = 0i64;
      *(__m128 *)v170 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v106), (__m128)0i64);
      hkpEntity::activate(mBody);
      ((void (__fastcall *)(hkpMaxSizeMotion *, _BYTE *, hkVector4f *))p_m_motion->vfptr[11].__first_virtual_table_function__)(
        &mBody->m_motion,
        v170,
        &v167);
      goto LABEL_49;
    }
LABEL_48:
    v110 = 0i64;
LABEL_49:
    if ( (*((_BYTE *)this + 56) & 1) == 0 )
    {
      if ( this->mBoat->mReorientActionRoll )
      {
        v167.m_quad = (__m128)a.m_rotation.m_col0;
        v167.m_quad.m128_i32[2] = 0;
        v111 = _mm_mul_ps(v167.m_quad, v167.m_quad);
        v112 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v111, v111, 85), _mm_shuffle_ps(v111, v111, 0)),
                 _mm_shuffle_ps(v111, v111, 170));
        v113 = _mm_rsqrt_ps(v112);
        v167.m_quad = _mm_mul_ps(
                        v167.m_quad,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v112, v110),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v113, v112), v113)),
                            _mm_mul_ps(*(__m128 *)_xmm, v113))));
        hkQuaternionf::setAxisAngle((hkQuaternionf *)v170, &v167, angle);
        hkVector4f::setRotatedDir((hkVector4f *)&v170[24], (hkQuaternionf *)v170, &direction);
        v114 = _mm_mul_ps(a.m_rotation.m_col2.m_quad, v167.m_quad);
        v115 = _mm_xor_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                   _mm_shuffle_ps(v114, v114, 170)),
                 (__m128)(unsigned int)_xmm[0]);
        v116 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v115, v115, 0), v167.m_quad), a.m_rotation.m_col2.m_quad);
        v117 = _mm_mul_ps(v116, v116);
        v118 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                 _mm_shuffle_ps(v117, v117, 170));
        v119 = _mm_rsqrt_ps(v118);
        v120 = _mm_mul_ps(
                 v116,
                 _mm_andnot_ps(
                   _mm_cmple_ps(v118, v110),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v119, v118), v119)),
                     _mm_mul_ps(*(__m128 *)_xmm, v119))));
        v121 = _mm_mul_ps(*(__m128 *)&v170[24], v120);
        X[0] = (float)(_mm_shuffle_ps(v121, v121, 85).m128_f32[0] + _mm_shuffle_ps(v121, v121, 0).m128_f32[0])
             + _mm_shuffle_ps(v121, v121, 170).m128_f32[0];
        v122 = _mm_min_ps(
                 _mm_max_ps((__m128)LODWORD(X[0]), *(__m128 *)_xmm_bf800000bf800000bf800000bf800000),
                 *(__m128 *)_xmm);
        v123 = _mm_andnot_ps(*(__m128 *)_xmm, v122);
        v124 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v123), *(__m128 *)_xmm);
        v125 = _mm_cmplt_ps(*(__m128 *)_xmm, v123);
        v126 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v124), v125), _mm_andnot_ps(v125, v123));
        v127 = _mm_or_ps(_mm_andnot_ps(v125, _mm_mul_ps(v123, v123)), _mm_and_ps(v125, v124));
        v128 = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v127, *(__m128 *)coeff4), *(__m128 *)coeff3), v127),
                               *(__m128 *)coeff2),
                             v127),
                           *(__m128 *)coeff1),
                         v127),
                       *(__m128 *)coeff0),
                     v127),
                   v126),
                 v126);
        v129 = _mm_cmplt_ps(v123, *(__m128 *)_xmm);
        v130 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v170[24], *(__m128 *)&v170[24], 201), v120),
                 _mm_mul_ps(_mm_shuffle_ps(v120, v120, 201), *(__m128 *)&v170[24]));
        v131 = _mm_shuffle_ps(v130, v130, 201);
        v132 = _mm_mul_ps(v131, v131);
        v125.m128_f32[0] = 1.5707964
                         - COERCE_FLOAT((_mm_andnot_ps(
                                           v129,
                                           _mm_or_ps(
                                             _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v128, v128)), v125),
                                             _mm_andnot_ps(v125, v128))).m128_u32[0] | v129.m128_i32[0] & v123.m128_i32[0]) ^ v122.m128_i32[0] & _xmm[0]);
        v133 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                 _mm_shuffle_ps(v132, v132, 170));
        v134 = _mm_rsqrt_ps(v133);
        v135 = _mm_cmple_ps(v133, v110);
        v136 = *(__m128 *)_xmm;
        v137 = _mm_mul_ps(
                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v134, v133), v134)),
                 _mm_mul_ps(v134, *(__m128 *)_xmm));
        mChopDist_low = (__m128)LODWORD(UFG::PhysicsBoat::mLeanCodeFixConstant);
        mChopDist_low.m128_f32[0] = UFG::PhysicsBoat::mLeanCodeFixConstant * stepInfo->m_deltaTime.m_storage;
        mReorientActionRoll = this->mBoat->mReorientActionRoll;
        v136.m128_f32[0] = (float)(v125.m128_f32[0] * mReorientActionRoll->m_strength) * mChopDist_low.m128_f32[0];
        v139 = _mm_shuffle_ps(v136, v136, 0);
        v140 = _mm_mul_ps(_mm_mul_ps(_mm_andnot_ps(v135, v137), v131), v139);
        v139.m128_f32[0] = mChopDist_low.m128_f32[0] * mReorientActionRoll->m_damping;
        *(__m128 *)&v170[40] = _mm_sub_ps(
                                 v140,
                                 _mm_mul_ps(_mm_shuffle_ps(v139, v139, 0), mBody->m_motion.m_angularVelocity.m_quad));
        hkpEntity::activate(mBody);
        p_m_motion->vfptr[12].__vecDelDtor(&mBody->m_motion, (unsigned int)&v170[40]);
      }
      if ( (*((_BYTE *)this + 56) & 1) == 0 )
      {
        v141 = 752i64;
        do
        {
          v142 = this->mBoat;
          if ( *(float *)((char *)&v142->mUserData.simComponent.m_pPointer + v141) <= 0.0099999998 )
          {
            v143 = (__m128)*(unsigned int *)((char *)&v142->vfptr + v141);
            v144 = (__m128)LODWORD(stepInfo->m_deltaTime.m_storage);
            v145 = (char *)v142 + v99;
            v143.m128_f32[0] = v143.m128_f32[0] * -0.15000001;
            *(__m128 *)v170 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, v143), (__m128)0i64);
            hkpEntity::activate(mBody);
            mChopDist_low = v144;
            ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, _BYTE *, char *))p_m_motion->vfptr[12].__first_virtual_table_function__)(
              &mBody->m_motion,
              v146,
              v170,
              v145);
          }
          v99 += 16i64;
          v141 += 4i64;
          --vars0;
        }
        while ( vars0 );
      }
    }
    goto LABEL_75;
  }
  if ( (*((_BYTE *)this + 56) & 1) == 0 )
  {
    v157 = (__m128 *)mBoat->mReorientActionRoll;
    if ( v157 )
    {
      v157[5] = _xmm;
      ((void (__fastcall *)(hkpReorientAction *, hkStepInfo *))this->mBoat->mReorientActionRoll->vfptr[1].__first_virtual_table_function__)(
        this->mBoat->mReorientActionRoll,
        stepInfo);
      v4 = direction.m_quad;
    }
    mReorientActionPitch = this->mBoat->mReorientActionPitch;
    if ( mReorientActionPitch )
    {
      mReorientActionPitch->m_upAxis.m_quad = v4;
      ((void (__fastcall *)(hkpReorientAction *, hkStepInfo *))this->mBoat->mReorientActionPitch->vfptr[1].__first_virtual_table_function__)(
        this->mBoat->mReorientActionPitch,
        stepInfo);
    }
    v159 = this->mBoat;
    v160 = _mm_shuffle_ps(v14, v14, 170);
    if ( v160.m128_f32[0] <= 0.0 )
      mVerticalVelocityDampingDown = v159->mVerticalVelocityDampingDown;
    else
      mVerticalVelocityDampingDown = v159->mVerticalVelocityDampingUp;
    v160.m128_f32[0] = v160.m128_f32[0] * mVerticalVelocityDampingDown;
    mChopDist_low = 0i64;
    v169 = _mm_add_ps(
             v169,
             _mm_unpacklo_ps(
               _mm_unpacklo_ps((__m128)0i64, _mm_xor_ps(v160, (__m128)(unsigned int)_xmm[0])),
               (__m128)0i64));
  }
LABEL_75:
  v162 = this->mBoat;
  v163 = *((_DWORD *)&v162->UFG::PhysicsVehicle + 151);
  if ( (v163 & 8) != 0 )
  {
    if ( v162->mSpeedKPH < 0.5 )
      *((_DWORD *)&v162->UFG::PhysicsVehicle + 151) = v163 & 0xFFFFFFF7;
    v164 = this->mBoat;
    v168.m_quad = v14;
    v168.m_quad.m128_i32[2] = 0;
    mChopDist_low.m128_i32[0] = LODWORD(v164->mSuperStopDrag) ^ _xmm[0];
    v169 = _mm_add_ps(v169, _mm_mul_ps(_mm_shuffle_ps(mChopDist_low, mChopDist_low, 0), v168.m_quad));
  }
  hkpEntity::activate(mBody);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, __m128 *))mBody->m_motion.hkpEntity::vfptr[13].__vecDelDtor)(
    &mBody->m_motion,
    v165,
    &v169);
  hkpEntity::activate(mBody);
  ((void (__fastcall *)(hkpMaxSizeMotion *, __int64, _BYTE *))mBody->m_motion.hkpEntity::vfptr[13].__first_virtual_table_function__)(
    &mBody->m_motion,
    v166,
    &v170[16]);
}KPH < 0.5 )
      *((_DWORD *)&v162->UFG::PhysicsVehicle + 151) = v163 & 0xFFFFFFF7;
    v164 = this->mBoat;
    v168.m_quad = v14;
    v168.m_quad.m128_i32[2] = 0;
    mChopDist_low.m

