// File Line: 79
// RVA: 0xB6DF0
hkBool *__fastcall UFG::RagdollPenetrationRaycastInterface::castRay(
        UFG::RagdollPenetrationRaycastInterface *this,
        hkBool *result,
        hkpAabbPhantom *phantomIn,
        hkVector4f *fromWS,
        hkVector4f *toWS,
        hkVector4f *hitPointWS)
{
  hkpRayHitCollector collector; // [rsp+18h] [rbp-71h] BYREF
  hkVector4f v9; // [rsp+28h] [rbp-61h]
  unsigned int v10; // [rsp+38h] [rbp-51h]
  int v11; // [rsp+3Ch] [rbp-4Dh]
  int v12; // [rsp+48h] [rbp-41h]
  int v13; // [rsp+68h] [rbp-21h]
  __int64 v14; // [rsp+78h] [rbp-11h]
  hkpWorldRayCastInput input; // [rsp+88h] [rbp-1h] BYREF
  __int64 v16; // [rsp+B8h] [rbp+2Fh]
  hkVector4f *v17; // [rsp+F8h] [rbp+6Fh]

  v16 = -2i64;
  input.m_enableShapeCollectionFilter.m_bool = 0;
  input.m_filterInfo = 0;
  input.m_userData = 0i64;
  collector.vfptr = (hkpRayHitCollectorVtbl *)&hkpClosestRayHitCollector::`vftable;
  v14 = 0i64;
  v10 = 1065353216;
  v11 = -1;
  v13 = 0;
  v12 = -1;
  collector.m_earlyOutHitFraction = 1.0;
  input.m_from = (hkVector4f)fromWS->m_quad;
  input.m_to = (hkVector4f)v17->m_quad;
  input.m_filterInfo = 12;
  v14 = 0i64;
  v10 = 1065353216;
  v11 = -1;
  v13 = 0;
  v12 = -1;
  collector.m_earlyOutHitFraction = 1.0;
  hkpAabbPhantom::castRay(phantomIn, &input, &collector);
  if ( v14 )
  {
    toWS->m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(input.m_to.m_quad, input.m_from.m_quad),
                       _mm_shuffle_ps((__m128)v10, (__m128)v10, 0)),
                     input.m_from.m_quad);
    *hitPointWS = (hkVector4f)v9.m_quad;
    result->m_bool = 1;
  }
  else
  {
    result->m_bool = 0;
  }
  return result;
}

// File Line: 112
// RVA: 0xB1AD0
void __fastcall UFG::Ragdoll::SetMotorState(UFG::Ragdoll *this, int b, hkBool onOff)
{
  hkaRagdollInstance *mRagdollInstance; // r8
  int v5; // edx
  hkpConstraintInstance *v6; // rdi
  hkpLimitedHingeConstraintData *m_data; // rbx
  int v8; // eax

  mRagdollInstance = this->mRagdollInstance;
  v5 = mRagdollInstance->m_boneToRigidBodyMap.m_data[b] - 1;
  if ( v5 >= 0 )
  {
    v6 = mRagdollInstance->m_constraints.m_data[v5];
    if ( v6 )
    {
      m_data = (hkpLimitedHingeConstraintData *)v6->m_data;
      if ( m_data )
      {
        v8 = ((__int64 (__fastcall *)(hkpConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(v6->m_data);
        if ( v8 == 2 )
        {
          hkpLimitedHingeConstraintData::setMotorEnabled(m_data, v6->m_internal->m_runtime, onOff);
        }
        else if ( v8 == 7 )
        {
          hkpRagdollConstraintData::setMotorsEnabled(
            (hkpRagdollConstraintData *)m_data,
            v6->m_internal->m_runtime,
            onOff);
        }
      }
    }
  }
}

// File Line: 159
// RVA: 0xA0C20
void __fastcall UFG::Ragdoll::ApplyCorrectionImpulse(UFG::Ragdoll *this, hkpRigidBody *rb, int boneId, int parentId)
{
  int v4; // ebx
  __int64 v8; // rdi
  DetectRagdollPenetration::BonePenetration *m_data; // rcx
  hkVector4f v10; // xmm0
  float m_penetrationErrorVelocity; // xmm8_4
  __m128 m_penetrationImpulseMax_low; // xmm6
  __m128 v13; // xmm10
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  __m128 v16; // xmm7
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  float v21; // xmm9_4
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  float v25; // xmm7_4
  __m128 v26; // xmm6
  __m128 m_quad; // [rsp+20h] [rbp-C8h] BYREF
  __m128 v28; // [rsp+30h] [rbp-B8h] BYREF

  v4 = 0;
  if ( this->mPenetratedBones.m_penetrations.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = this->mPenetratedBones.m_penetrations.m_data;
      if ( m_data[v8].m_boneBeginIndex == boneId )
      {
        v10.m_quad = (__m128)rb->m_motion.m_angularVelocity;
        m_penetrationErrorVelocity = this->m_penetrationErrorVelocity;
        m_penetrationImpulseMax_low = (__m128)LODWORD(this->m_penetrationImpulseMax);
        m_quad = m_data[v8].m_penetrationPoint.m_quad;
        v13 = m_data[v8].m_penetrationNormal.m_quad;
        v14 = _mm_sub_ps(m_quad, rb->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v15 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v10.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 201), v14));
        v16 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 201), rb->m_motion.m_linearVelocity.m_quad);
        v17 = _mm_mul_ps(v16, v16);
        v18 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                _mm_shuffle_ps(v17, v17, 170));
        v19 = _mm_rsqrt_ps(v18);
        v20 = _mm_mul_ps(*(__m128 *)_xmm, v19);
        v21 = _mm_andnot_ps(
                _mm_cmple_ps(v18, (__m128)0i64),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)), v20), v18)).m128_f32[0];
        if ( v21 <= 0.00000011920929 )
        {
          v25 = 0.0;
        }
        else
        {
          v22 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
                  _mm_shuffle_ps(v17, v17, 170));
          v23 = _mm_rsqrt_ps(v22);
          v24 = _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmple_ps(v22, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                        _mm_mul_ps(*(__m128 *)_xmm, v23))),
                    v16),
                  v13);
          v20 = _mm_shuffle_ps(v24, v24, 0);
          v25 = (float)(_mm_shuffle_ps(v24, v24, 85).m128_f32[0] + v20.m128_f32[0])
              + _mm_shuffle_ps(v24, v24, 170).m128_f32[0];
        }
        v20.m128_f32[0] = hkpMotion::getMass(&rb->m_motion) * (float)(m_penetrationErrorVelocity - (float)(v25 * v21));
        if ( v20.m128_f32[0] > m_penetrationImpulseMax_low.m128_f32[0] )
          v20 = m_penetrationImpulseMax_low;
        v26 = _mm_xor_ps(m_penetrationImpulseMax_low, (__m128)(unsigned int)_xmm[0]);
        if ( v20.m128_f32[0] < v26.m128_f32[0] )
          v20 = v26;
        v28 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v13);
        hkpEntity::activate(rb);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))rb->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
          &rb->m_motion,
          &v28,
          &m_quad);
      }
      ++v4;
      ++v8;
    }
    while ( v4 < this->mPenetratedBones.m_penetrations.m_size );
  }
}

// File Line: 226
// RVA: 0xAB320
__int64 __fastcall UFG::Ragdoll::GetRigidBodyID(UFG::Ragdoll *this, int skeletonBoneID)
{
  __int64 v2; // r8
  hkaSkeletonMapper *highResToRagdollMapper; // rax
  __int64 m_size; // r9
  hkaSkeletonMapperData::SimpleMapping *i; // rax

  if ( !this->mRagdollInstance )
    return 0xFFFFFFFFi64;
  v2 = 0i64;
  highResToRagdollMapper = this->mRagdollData.m_pPointer->highResToRagdollMapper;
  m_size = highResToRagdollMapper->m_mapping.m_simpleMappings.m_size;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = highResToRagdollMapper->m_mapping.m_simpleMappings.m_data; i->m_boneA != skeletonBoneID; ++i )
  {
    if ( ++v2 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)i->m_boneB;
}

// File Line: 251
// RVA: 0xAB2B0
hkpRigidBody *__fastcall UFG::Ragdoll::GetRigidBody(UFG::Ragdoll *this, int skeletonBoneID)
{
  hkaRagdollInstance *mRagdollInstance; // r10
  __int64 v3; // r11
  hkaSkeletonMapper *highResToRagdollMapper; // rcx
  __int64 v5; // r8
  __int64 m_size; // r9
  hkaSkeletonMapperData::SimpleMapping *i; // rcx
  __int64 v9; // rdx

  mRagdollInstance = this->mRagdollInstance;
  if ( !mRagdollInstance )
    return 0i64;
  v3 = 0i64;
  highResToRagdollMapper = this->mRagdollData.m_pPointer->highResToRagdollMapper;
  v5 = 0i64;
  m_size = highResToRagdollMapper->m_mapping.m_simpleMappings.m_size;
  if ( m_size <= 0 )
    return 0i64;
  for ( i = highResToRagdollMapper->m_mapping.m_simpleMappings.m_data; i->m_boneA != skeletonBoneID; ++i )
  {
    if ( ++v5 >= m_size )
      return 0i64;
  }
  if ( i->m_boneB == -1 )
    return 0i64;
  v9 = mRagdollInstance->m_boneToRigidBodyMap.m_data[i->m_boneB];
  if ( (int)v9 >= 0 )
    return mRagdollInstance->m_rigidBodies.m_data[v9];
  return (hkpRigidBody *)v3;
}

// File Line: 285
// RVA: 0xA0F40
void __fastcall UFG::Ragdoll::ApplyImpulse(UFG::Ragdoll *this, int bone, hkVector4f *location, hkVector4f *impulse)
{
  __m128 m_quad; // xmm0
  __m128 v5; // xmm1
  UFG::RagdollData *m_pPointer; // rax
  hkaRagdollInstance *mRagdollInstance; // rdx
  hkaSkeletonMapper *highResToRagdollMapper; // rbp
  __int64 m_size; // rsi
  __int64 v11; // rbx
  hkaSkeletonMapperData::SimpleMapping *m_data; // rcx
  hkpEntity *v13; // rdi
  __m128 v14; // [rsp+20h] [rbp-38h] BYREF
  __m128 v15; // [rsp+30h] [rbp-28h] BYREF
  hkaRagdollInstance *v16; // [rsp+40h] [rbp-18h]

  m_quad = impulse->m_quad;
  v5 = location->m_quad;
  m_pPointer = this->mRagdollData.m_pPointer;
  mRagdollInstance = this->mRagdollInstance;
  v16 = mRagdollInstance;
  v15 = m_quad;
  v14 = v5;
  highResToRagdollMapper = m_pPointer->highResToRagdollMapper;
  m_size = highResToRagdollMapper->m_mapping.m_simpleMappings.m_size;
  if ( m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      m_data = highResToRagdollMapper->m_mapping.m_simpleMappings.m_data;
      if ( m_data[v11].m_boneA == bone )
      {
        v13 = mRagdollInstance->m_rigidBodies.m_data[m_data[v11].m_boneB];
        hkpEntity::activate(v13);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))v13->m_motion.vfptr[11].__first_virtual_table_function__)(
          &v13->m_motion,
          &v15,
          &v14);
        mRagdollInstance = v16;
      }
      ++v11;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 297
// RVA: 0xB8F40
void __fastcall UFG::wrenchBone(__m128 *cxt, int boneID)
{
  __m128 v2; // xmm1
  _QWORD *v3; // rbp
  __int64 v4; // r12
  __int64 v5; // rsi
  int v6; // r14d
  __m128 *v7; // rdx
  __m128 v9; // xmm10
  float i; // xmm9_4
  __int64 v11; // rcx
  hkpEntity *v12; // rbx
  hkpMaxSizeMotion *p_m_motion; // rdi
  hkpMotion *v14; // rcx
  __m128 v15; // xmm8
  __m128 v16; // xmm7
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  float Mass; // xmm6_4
  __m128 v21; // xmm8
  __m128 v22; // [rsp+20h] [rbp-B8h] BYREF
  __m128 v23; // [rsp+30h] [rbp-A8h] BYREF

  v3 = (_QWORD *)cxt[2].m128_u64[0];
  v4 = boneID;
  v5 = 0i64;
  v6 = 0;
  v7 = *(__m128 **)(v3[2] + 8i64 * boneID);
  v9 = v7[28];
  for ( i = v7[34].m128_f32[3]; v6 < *(_DWORD *)(v3[8] + 48i64); ++v5 )
  {
    v11 = *(int *)(v3[6] + 4 * v5);
    if ( (int)v11 >= 0 )
      v12 = *(hkpEntity **)(v3[2] + 8 * v11);
    else
      v12 = 0i64;
    p_m_motion = &v12->m_motion;
    v14 = &v12->m_motion;
    v15 = _mm_sub_ps(v12->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad, v9);
    if ( v5 == v4 )
    {
      v2.m128_f32[0] = hkpMotion::getMass(v14) * i;
    }
    else
    {
      v16 = (__m128)(unsigned int)FLOAT_1_0;
      v17 = _mm_mul_ps(v15, v15);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_rsqrt_ps(v18);
      v16.m128_f32[0] = (float)(1.0 - cxt[2].m128_f32[2])
                      * (float)(_mm_andnot_ps(
                                  _mm_cmple_ps(v18, (__m128)0i64),
                                  _mm_mul_ps(
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v19)),
                                    v18)).m128_f32[0]
                              * 4.0);
      v2 = v16;
      Mass = hkpMotion::getMass(v14);
      v2.m128_f32[0] = (float)(Mass * i) / powf(2.7182817, v16.m128_f32[0]);
    }
    v22 = _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), cxt[1]);
    hkpEntity::activate(v12);
    p_m_motion->vfptr[12].__vecDelDtor(&v12->m_motion, (unsigned int)&v22);
    v2 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v15);
    v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v22), v2);
    v23 = _mm_shuffle_ps(v21, v21, 201);
    hkpEntity::activate(v12);
    p_m_motion->vfptr[11].__vecDelDtor(&v12->m_motion, (unsigned int)&v23);
    ++v6;
  }
}

// File Line: 336
// RVA: 0xA0B30
void __fastcall UFG::Ragdoll::ApplyAngularImpulse(
        UFG::Ragdoll *this,
        int bone,
        hkVector4f *impulse,
        float connectionTransfer)
{
  hkaRagdollInstance *mRagdollInstance; // rax
  __m128 m_quad; // xmm0
  UFG::RagdollData *m_pPointer; // rax
  hkaSkeletonMapper *highResToRagdollMapper; // rsi
  __int64 m_size; // rdi
  __int64 v10; // rbx
  hkaSkeletonMapperData::SimpleMapping *m_data; // rcx
  char cxt[16]; // [rsp+20h] [rbp-38h] BYREF
  __m128 v13; // [rsp+30h] [rbp-28h]
  hkaRagdollInstance *v14; // [rsp+40h] [rbp-18h]
  float v15; // [rsp+48h] [rbp-10h]

  mRagdollInstance = this->mRagdollInstance;
  m_quad = impulse->m_quad;
  v15 = connectionTransfer;
  v14 = mRagdollInstance;
  m_pPointer = this->mRagdollData.m_pPointer;
  v13 = m_quad;
  highResToRagdollMapper = m_pPointer->highResToRagdollMapper;
  m_size = highResToRagdollMapper->m_mapping.m_simpleMappings.m_size;
  if ( m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      m_data = highResToRagdollMapper->m_mapping.m_simpleMappings.m_data;
      if ( m_data[v10].m_boneA == bone )
        UFG::wrenchBone(cxt, m_data[v10].m_boneB);
      ++v10;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 350
// RVA: 0xB11A0
void __fastcall UFG::Ragdoll::SetDynamic(UFG::Ragdoll *this, hkpRigidBody *rb, int boneId, unsigned int collisionLayer)
{
  unsigned int v5; // eax
  unsigned int v6; // edi
  hkpWorld *m_world; // rcx

  v5 = this->mRagdollData.m_pPointer->mCollisionFilterInfo.p[boneId];
  v6 = collisionLayer | (32 * ((v5 >> 5) & 0x1F | (32 * ((v5 >> 10) & 0x1F | (this->mCollisionSystem << 6)))));
  if ( (unsigned __int8)(rb->m_motion.m_type.m_storage - 4) <= 1u
    || rb->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo != v6 )
  {
    hkpRigidBody::setMotionType(
      rb,
      MOTION_DYNAMIC,
      HK_ENTITY_ACTIVATION_DO_ACTIVATE,
      HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
    m_world = rb->m_world;
    rb->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v6;
    if ( m_world )
      hkpWorld::updateCollisionFilterOnEntity(
        m_world,
        rb,
        HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  }
}

// File Line: 416
// RVA: 0x99410
void __fastcall UFG::Ragdoll::Ragdoll(
        UFG::Ragdoll *this,
        UFG::RagdollData *data,
        hkaRagdollInstance *instance,
        unsigned __int16 collisionSystem)
{
  hkpEaseConstraintsAction *v6; // rdi
  UFG::qSafePointer<UFG::RagdollData,UFG::RagdollData> *p_mRagdollData; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::BasePhysicsSystem *v9; // r14
  __int64 v10; // rsi
  char v11; // dl
  char v12; // cl
  _QWORD **Value; // rax
  hkaRagdollRigidBodyController *v14; // rax
  hkaRagdollRigidBodyController *v15; // rax
  char v16; // al
  hkaRagdollInstance *mRagdollInstance; // rsi
  _QWORD **v18; // rax
  hkpEaseConstraintsAction *v19; // rax
  hkpEaseConstraintsAction *v20; // rax

  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  this->mUserData.isBoat = 0;
  this->mUserData.simComponent.mPrev = &this->mUserData.simComponent;
  this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  v6 = 0i64;
  this->mUserData.simComponent.m_pPointer = 0i64;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::Ragdoll::`vftable;
  *(_QWORD *)&this->mMassProperties.m_volume = 0i64;
  this->mMassProperties.m_centerOfMass = 0i64;
  this->mMassProperties.m_inertiaTensor.m_col0 = 0i64;
  this->mMassProperties.m_inertiaTensor.m_col1 = 0i64;
  this->mMassProperties.m_inertiaTensor.m_col2 = 0i64;
  this->mRagdollInstance = instance;
  *(_QWORD *)&this->mDefaultControlData.m_hierarchyGain = 1043207291i64;
  this->mDefaultControlData.m_accelerationGain = 1.0;
  this->mDefaultControlData.m_velocityGain = 0.60000002;
  this->mDefaultControlData.m_positionGain = 0.050000001;
  this->mDefaultControlData.m_positionMaxLinearVelocity = 1.4;
  this->mDefaultControlData.m_positionMaxAngularVelocity = 1.8;
  this->mDefaultControlData.m_snapGain = 0.1;
  this->mDefaultControlData.m_snapMaxLinearVelocity = 0.30000001;
  this->mDefaultControlData.m_snapMaxAngularVelocity = 0.30000001;
  this->mDefaultControlData.m_snapMaxLinearDistance = 0.029999999;
  this->mDefaultControlData.m_snapMaxAngularDistance = 0.1;
  *(_QWORD *)&this->mKeyframedControlData.m_hierarchyGain = 1043207291i64;
  this->mKeyframedControlData.m_accelerationGain = 1.0;
  this->mKeyframedControlData.m_velocityGain = 0.60000002;
  this->mKeyframedControlData.m_positionGain = 0.050000001;
  this->mKeyframedControlData.m_positionMaxLinearVelocity = 1.4;
  this->mKeyframedControlData.m_positionMaxAngularVelocity = 1.8;
  this->mKeyframedControlData.m_snapGain = 0.1;
  this->mKeyframedControlData.m_snapMaxLinearVelocity = 0.30000001;
  this->mKeyframedControlData.m_snapMaxAngularVelocity = 0.30000001;
  this->mKeyframedControlData.m_snapMaxLinearDistance = 0.029999999;
  this->mKeyframedControlData.m_snapMaxAngularDistance = 0.1;
  this->mEaseConstraintsAction = 0i64;
  p_mRagdollData = &this->mRagdollData;
  this->mRagdollData.mPrev = &this->mRagdollData;
  this->mRagdollData.mNext = &this->mRagdollData;
  this->mRagdollData.m_pPointer = data;
  if ( data )
  {
    mPrev = data->m_SafePointerList.mNode.mPrev;
    mPrev->mNext = p_mRagdollData;
    p_mRagdollData->mPrev = mPrev;
    this->mRagdollData.mNext = &data->m_SafePointerList.mNode;
    data->m_SafePointerList.mNode.mPrev = p_mRagdollData;
  }
  this->mSnapShotPoseMS.m_data = 0i64;
  this->mSnapShotPoseMS.m_size = 0;
  this->mSnapShotPoseMS.m_capacityAndFlags = 0x80000000;
  this->mPenetratedBones.m_penetrations.m_data = 0i64;
  this->mPenetratedBones.m_penetrations.m_size = 0;
  this->mPenetratedBones.m_penetrations.m_capacityAndFlags = 0x80000000;
  this->mUID = data->rigGuid;
  this->mCollisionSystem = collisionSystem;
  v9 = UFG::BasePhysicsSystem::mInstance;
  UFG::Ragdoll::SetCollisionState(this, CS_DYNAMIC);
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  *(_DWORD *)(v10 + 4i64 * v11) = 3;
  *(_QWORD *)(v10 + 8i64 * v11 + 16) = "hkaRagdollRigidBodyController";
  *(_QWORD *)(v10 + 8i64 * v11 + 48) = 0i64;
  v12 = *(_BYTE *)(v10 + 81);
  if ( v11 > v12 )
    v12 = v11;
  *(_BYTE *)(v10 + 81) = v12;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (hkaRagdollRigidBodyController *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           112i64);
  if ( v14 )
    hkaRagdollRigidBodyController::hkaRagdollRigidBodyController(v14, this->mRagdollInstance);
  else
    v15 = 0i64;
  this->mRigidBodyController = v15;
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
  this->mDefaultControlData.m_hierarchyGain = UFG::g_default_m_hierarchyGain;
  this->mDefaultControlData.m_velocityDamping = UFG::g_default_m_velocityDamping;
  this->mDefaultControlData.m_accelerationGain = UFG::g_default_m_accelerationGain;
  this->mDefaultControlData.m_velocityGain = UFG::g_default_m_velocityGain;
  this->mDefaultControlData.m_positionGain = UFG::g_default_m_positionGain;
  this->mDefaultControlData.m_positionMaxLinearVelocity = UFG::g_default_m_positionMaxLinearVelocity;
  this->mDefaultControlData.m_positionMaxAngularVelocity = UFG::g_default_m_positionMaxAngularVelocity;
  this->mDefaultControlData.m_snapGain = UFG::g_default_m_snapGain;
  this->mDefaultControlData.m_snapMaxLinearVelocity = UFG::g_default_m_snapMaxLinearVelocity;
  this->mDefaultControlData.m_snapMaxAngularVelocity = UFG::g_default_m_snapMaxAngularVelocity;
  this->mDefaultControlData.m_snapMaxLinearDistance = UFG::g_default_m_snapMaxLinearDistance;
  this->mDefaultControlData.m_snapMaxAngularDistance = UFG::g_default_m_snapMaxAngularDistance;
  this->mKeyframedControlData.m_hierarchyGain = UFG::g_default_m_hierarchyGain;
  this->mKeyframedControlData.m_velocityDamping = UFG::g_default_m_velocityDamping;
  this->mKeyframedControlData.m_accelerationGain = 1.0;
  this->mKeyframedControlData.m_velocityGain = 0.60000002;
  this->mKeyframedControlData.m_positionGain = 0.25;
  this->mKeyframedControlData.m_positionMaxLinearVelocity = 100.0;
  this->mKeyframedControlData.m_positionMaxAngularVelocity = 10.0;
  this->mKeyframedControlData.m_snapGain = 0.89999998;
  this->mKeyframedControlData.m_snapMaxLinearVelocity = 100.0;
  this->mKeyframedControlData.m_snapMaxAngularVelocity = 10.0;
  this->mKeyframedControlData.m_snapMaxLinearDistance = 5.0;
  this->mKeyframedControlData.m_snapMaxAngularDistance = UFG::g_default_m_snapMaxAngularDistance;
  UFG::Ragdoll::SetControlData(this);
  this->m_penetrationErrorVelocity = data->m_penetrationErrorVelocity;
  this->m_penetrationImpulseMax = data->m_penetrationImpulseMax;
  hkReferencedObject::addReference(this->mRagdollData.m_pPointer->highResToRagdollMapper);
  hkReferencedObject::addReference(this->mRagdollData.m_pPointer->ragdollToHighResMapper);
  UFG::Ragdoll::CreateRagdollPenetrationUtil(this, v9->mWorld);
  mRagdollInstance = this->mRagdollInstance;
  v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (hkpEaseConstraintsAction *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(v18[11], 104i64);
  if ( v19 )
  {
    hkpEaseConstraintsAction::hkpEaseConstraintsAction(
      v19,
      (hkArray<hkpEntity *,hkContainerHeapAllocator> *)&mRagdollInstance->m_rigidBodies,
      0i64);
    v6 = v20;
  }
  this->mEaseConstraintsAction = v6;
}

// File Line: 468
// RVA: 0x9CC70
void __fastcall UFG::Ragdoll::~Ragdoll(UFG::Ragdoll *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  int v5; // r9d
  __int64 v6; // rdx
  hkaRagdollInstance *mRagdollInstance; // r8
  __int64 v8; // rcx
  hkpRigidBody *v9; // rax
  hkpEaseConstraintsAction *mEaseConstraintsAction; // rdx
  hkpWorld *m_world; // rcx
  hkpAabbPhantom *mPhantom; // rdx
  hkpWorld *v13; // rcx
  hkaRagdollRigidBodyController *mRigidBodyController; // rdi
  _QWORD **Value; // rax
  int m_capacityAndFlags; // eax
  UFG::qSafePointer<UFG::RagdollData,UFG::RagdollData> *p_mRagdollData; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v21; // rax
  UFG::qSafePointer<UFG::RagdollData,UFG::RagdollData> *result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::Ragdoll::`vftable;
  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = p_simComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    p_simComponent->mNext = p_simComponent;
  }
  p_simComponent->m_pPointer = 0i64;
  v5 = 0;
  if ( this->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      mRagdollInstance = this->mRagdollInstance;
      v8 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v6];
      if ( (int)v8 >= 0 )
        v9 = mRagdollInstance->m_rigidBodies.m_data[v8];
      else
        v9 = 0i64;
      v9->m_userData = 0i64;
      ++v5;
      ++v6;
    }
    while ( v5 < this->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size );
  }
  if ( hkaRagdollInstance::getWorld(this->mRagdollInstance) )
    hkaRagdollInstance::removeFromWorld(this->mRagdollInstance, (hkResult *)&result);
  mEaseConstraintsAction = this->mEaseConstraintsAction;
  m_world = mEaseConstraintsAction->m_world;
  if ( m_world )
    hkpWorld::removeAction(m_world, mEaseConstraintsAction);
  mPhantom = this->mPhantom;
  v13 = mPhantom->m_world;
  if ( v13 )
    hkpWorld::removePhantom(v13, mPhantom);
  hkReferencedObject::removeReference(this->mEaseConstraintsAction);
  hkReferencedObject::removeReference(this->mDetectRagdollPenetration);
  hkReferencedObject::removeReference(this->mRagdollRaycastInterface);
  hkReferencedObject::removeReference(this->mPhantom);
  mRigidBodyController = this->mRigidBodyController;
  if ( mRigidBodyController )
  {
    hkaRagdollRigidBodyController::~hkaRagdollRigidBodyController(this->mRigidBodyController);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkaRagdollRigidBodyController *, __int64))(*Value[11] + 16i64))(
      Value[11],
      mRigidBodyController,
      112i64);
  }
  hkReferencedObject::removeReference(this->mRagdollData.m_pPointer->highResToRagdollMapper);
  hkReferencedObject::removeReference(this->mRagdollData.m_pPointer->ragdollToHighResMapper);
  DetectRagdollPenetration::Output::~Output(&this->mPenetratedBones);
  this->mSnapShotPoseMS.m_size = 0;
  m_capacityAndFlags = this->mSnapShotPoseMS.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mSnapShotPoseMS.m_data,
      48 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->mSnapShotPoseMS.m_data = 0i64;
  this->mSnapShotPoseMS.m_capacityAndFlags = 0x80000000;
  p_mRagdollData = &this->mRagdollData;
  result = &this->mRagdollData;
  if ( this->mRagdollData.m_pPointer )
  {
    v18 = p_mRagdollData->mPrev;
    v19 = this->mRagdollData.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_mRagdollData->mPrev = p_mRagdollData;
    this->mRagdollData.mNext = &this->mRagdollData;
  }
  this->mRagdollData.m_pPointer = 0i64;
  v20 = p_mRagdollData->mPrev;
  v21 = this->mRagdollData.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_mRagdollData->mPrev = p_mRagdollData;
  this->mRagdollData.mNext = &this->mRagdollData;
  UFG::BasePhysicsObject::~BasePhysicsObject(this);
}

// File Line: 500
// RVA: 0xB0010
void __fastcall UFG::Ragdoll::ResetKeyframeControllerParams(UFG::Ragdoll *this)
{
  float v1; // xmm1_4

  this->mKeyframedControlData.m_hierarchyGain = UFG::g_default_m_hierarchyGain;
  v1 = UFG::g_default_m_velocityDamping;
  this->mKeyframedControlData.m_accelerationGain = 1.0;
  this->mKeyframedControlData.m_velocityGain = 0.60000002;
  this->mKeyframedControlData.m_positionGain = 0.25;
  this->mKeyframedControlData.m_positionMaxLinearVelocity = 100.0;
  this->mKeyframedControlData.m_positionMaxAngularVelocity = 10.0;
  this->mKeyframedControlData.m_snapGain = 0.89999998;
  this->mKeyframedControlData.m_velocityDamping = v1;
  this->mKeyframedControlData.m_snapMaxLinearVelocity = 100.0;
  this->mKeyframedControlData.m_snapMaxAngularVelocity = 10.0;
  this->mKeyframedControlData.m_snapMaxLinearDistance = 5.0;
  this->mKeyframedControlData.m_snapMaxAngularDistance = UFG::g_default_m_snapMaxAngularDistance;
}

// File Line: 518
// RVA: 0xB0900
void __fastcall UFG::Ragdoll::SetControlData(UFG::Ragdoll *this)
{
  hkaKeyFrameHierarchyUtility::ControlData *p_mDefaultControlData; // rdi
  int m_size; // esi
  hkaRagdollRigidBodyController *mRigidBodyController; // rbp
  int v5; // eax
  int v6; // eax
  int v7; // r9d
  __int64 v8; // rax
  int v9; // ecx
  __int64 v10; // rax
  int v11; // edx
  __int64 v12; // r8
  _DWORD *v13; // rax
  hkaRagdollRigidBodyController *v14; // rbp
  int v15; // eax
  int v16; // eax
  int v17; // r9d
  int v18; // r9d
  __int64 v19; // r8
  __int64 v20; // rsi
  __int64 v21; // rdx
  int v22; // r10d
  hkaKeyFrameHierarchyUtility::ControlData *m_data; // rcx
  hkaKeyFrameHierarchyUtility::ControlData *v24; // rcx
  hkaKeyFrameHierarchyUtility::ControlData *v25; // rcx
  hkaKeyFrameHierarchyUtility::ControlData *v26; // rcx
  unsigned __int64 v27; // rdx
  hkaKeyFrameHierarchyUtility::ControlData *v28; // rcx
  hkResult result; // [rsp+70h] [rbp+8h] BYREF
  __int64 v30; // [rsp+78h] [rbp+10h]
  _DWORD *v31; // [rsp+80h] [rbp+18h]

  p_mDefaultControlData = &this->mDefaultControlData;
  if ( this->mCollisionState )
    p_mDefaultControlData = &this->mKeyframedControlData;
  m_size = this->mRagdollInstance->m_rigidBodies.m_size;
  mRigidBodyController = this->mRigidBodyController;
  if ( mRigidBodyController->m_controlDataPalette.m_size <= 1 )
  {
    v5 = mRigidBodyController->m_controlDataPalette.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < m_size )
    {
      v6 = 2 * v5;
      v7 = this->mRagdollInstance->m_rigidBodies.m_size;
      if ( m_size < v6 )
        v7 = v6;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, mRigidBodyController, v7, 48);
    }
    v8 = mRigidBodyController->m_controlDataPalette.m_size;
    v9 = m_size - v8;
    v10 = (__int64)&mRigidBodyController->m_controlDataPalette.m_data[v8];
    v30 = v10;
    v11 = 0;
    result.m_enum = HK_SUCCESS;
    v12 = v9;
    if ( v9 > 0 )
    {
      v13 = (_DWORD *)(v10 + 8);
      do
      {
        v31 = v13 - 2;
        if ( v13 != (_DWORD *)8 )
        {
          *(v13 - 2) = 1043207291;
          *(v13 - 1) = 0;
          *v13 = 1065353216;
          v13[1] = 1058642330;
          v13[2] = 1028443341;
          v13[3] = 1068708659;
          v13[4] = 1072064102;
          v13[5] = 1036831949;
          v13[6] = 1050253722;
          v13[7] = 1050253722;
          v13[8] = 1022739087;
          v13[9] = 1036831949;
        }
        result.m_enum = ++v11;
        v13 += 12;
        --v12;
      }
      while ( v12 );
    }
    mRigidBodyController->m_controlDataPalette.m_size = m_size;
    v14 = this->mRigidBodyController;
    v15 = v14->m_bodyIndexToPaletteIndex.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v15 < m_size )
    {
      v16 = 2 * v15;
      v17 = m_size;
      if ( m_size < v16 )
        v17 = v16;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v14->m_bodyIndexToPaletteIndex, v17, 4);
    }
    v14->m_bodyIndexToPaletteIndex.m_size = m_size;
  }
  v18 = 0;
  v19 = 0i64;
  v20 = this->mRigidBodyController->m_controlDataPalette.m_size;
  if ( v20 >= 4 )
  {
    v21 = 0i64;
    v22 = 2;
    do
    {
      m_data = this->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v18 > this->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        m_data[v21].m_hierarchyGain = this->mDefaultControlData.m_hierarchyGain;
        m_data[v21].m_velocityDamping = this->mDefaultControlData.m_velocityDamping;
        m_data[v21].m_accelerationGain = this->mDefaultControlData.m_accelerationGain;
        m_data[v21].m_velocityGain = this->mDefaultControlData.m_velocityGain;
        m_data[v21].m_positionGain = this->mDefaultControlData.m_positionGain;
        m_data[v21].m_positionMaxLinearVelocity = this->mDefaultControlData.m_positionMaxLinearVelocity;
        m_data[v21].m_positionMaxAngularVelocity = this->mDefaultControlData.m_positionMaxAngularVelocity;
        m_data[v21].m_snapGain = this->mDefaultControlData.m_snapGain;
        m_data[v21].m_snapMaxLinearVelocity = this->mDefaultControlData.m_snapMaxLinearVelocity;
        m_data[v21].m_snapMaxAngularVelocity = this->mDefaultControlData.m_snapMaxAngularVelocity;
        m_data[v21].m_snapMaxLinearDistance = this->mDefaultControlData.m_snapMaxLinearDistance;
        m_data[v21].m_snapMaxAngularDistance = this->mDefaultControlData.m_snapMaxAngularDistance;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21].m_hierarchyGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21].m_accelerationGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21].m_positionGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21].m_snapGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21].m_velocityGain = 0.0;
      }
      else
      {
        m_data[v21].m_hierarchyGain = p_mDefaultControlData->m_hierarchyGain;
        m_data[v21].m_velocityDamping = p_mDefaultControlData->m_velocityDamping;
        m_data[v21].m_accelerationGain = p_mDefaultControlData->m_accelerationGain;
        m_data[v21].m_velocityGain = p_mDefaultControlData->m_velocityGain;
        m_data[v21].m_positionGain = p_mDefaultControlData->m_positionGain;
        m_data[v21].m_positionMaxLinearVelocity = p_mDefaultControlData->m_positionMaxLinearVelocity;
        m_data[v21].m_positionMaxAngularVelocity = p_mDefaultControlData->m_positionMaxAngularVelocity;
        m_data[v21].m_snapGain = p_mDefaultControlData->m_snapGain;
        m_data[v21].m_snapMaxLinearVelocity = p_mDefaultControlData->m_snapMaxLinearVelocity;
        m_data[v21].m_snapMaxAngularVelocity = p_mDefaultControlData->m_snapMaxAngularVelocity;
        m_data[v21].m_snapMaxLinearDistance = p_mDefaultControlData->m_snapMaxLinearDistance;
        m_data[v21].m_snapMaxAngularDistance = p_mDefaultControlData->m_snapMaxAngularDistance;
      }
      this->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19] = v18;
      v24 = this->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v22 - 1 > this->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v24[v21 + 1].m_hierarchyGain = this->mDefaultControlData.m_hierarchyGain;
        v24[v21 + 1].m_velocityDamping = this->mDefaultControlData.m_velocityDamping;
        v24[v21 + 1].m_accelerationGain = this->mDefaultControlData.m_accelerationGain;
        v24[v21 + 1].m_velocityGain = this->mDefaultControlData.m_velocityGain;
        v24[v21 + 1].m_positionGain = this->mDefaultControlData.m_positionGain;
        v24[v21 + 1].m_positionMaxLinearVelocity = this->mDefaultControlData.m_positionMaxLinearVelocity;
        v24[v21 + 1].m_positionMaxAngularVelocity = this->mDefaultControlData.m_positionMaxAngularVelocity;
        v24[v21 + 1].m_snapGain = this->mDefaultControlData.m_snapGain;
        v24[v21 + 1].m_snapMaxLinearVelocity = this->mDefaultControlData.m_snapMaxLinearVelocity;
        v24[v21 + 1].m_snapMaxAngularVelocity = this->mDefaultControlData.m_snapMaxAngularVelocity;
        v24[v21 + 1].m_snapMaxLinearDistance = this->mDefaultControlData.m_snapMaxLinearDistance;
        v24[v21 + 1].m_snapMaxAngularDistance = this->mDefaultControlData.m_snapMaxAngularDistance;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_hierarchyGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_accelerationGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_positionGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_snapGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_velocityGain = 0.0;
      }
      else
      {
        v24[v21 + 1].m_hierarchyGain = p_mDefaultControlData->m_hierarchyGain;
        v24[v21 + 1].m_velocityDamping = p_mDefaultControlData->m_velocityDamping;
        v24[v21 + 1].m_accelerationGain = p_mDefaultControlData->m_accelerationGain;
        v24[v21 + 1].m_velocityGain = p_mDefaultControlData->m_velocityGain;
        v24[v21 + 1].m_positionGain = p_mDefaultControlData->m_positionGain;
        v24[v21 + 1].m_positionMaxLinearVelocity = p_mDefaultControlData->m_positionMaxLinearVelocity;
        v24[v21 + 1].m_positionMaxAngularVelocity = p_mDefaultControlData->m_positionMaxAngularVelocity;
        v24[v21 + 1].m_snapGain = p_mDefaultControlData->m_snapGain;
        v24[v21 + 1].m_snapMaxLinearVelocity = p_mDefaultControlData->m_snapMaxLinearVelocity;
        v24[v21 + 1].m_snapMaxAngularVelocity = p_mDefaultControlData->m_snapMaxAngularVelocity;
        v24[v21 + 1].m_snapMaxLinearDistance = p_mDefaultControlData->m_snapMaxLinearDistance;
        v24[v21 + 1].m_snapMaxAngularDistance = p_mDefaultControlData->m_snapMaxAngularDistance;
      }
      this->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19 + 1] = v22 - 1;
      v25 = this->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v22 > this->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v25[v21 + 2].m_hierarchyGain = this->mDefaultControlData.m_hierarchyGain;
        v25[v21 + 2].m_velocityDamping = this->mDefaultControlData.m_velocityDamping;
        v25[v21 + 2].m_accelerationGain = this->mDefaultControlData.m_accelerationGain;
        v25[v21 + 2].m_velocityGain = this->mDefaultControlData.m_velocityGain;
        v25[v21 + 2].m_positionGain = this->mDefaultControlData.m_positionGain;
        v25[v21 + 2].m_positionMaxLinearVelocity = this->mDefaultControlData.m_positionMaxLinearVelocity;
        v25[v21 + 2].m_positionMaxAngularVelocity = this->mDefaultControlData.m_positionMaxAngularVelocity;
        v25[v21 + 2].m_snapGain = this->mDefaultControlData.m_snapGain;
        v25[v21 + 2].m_snapMaxLinearVelocity = this->mDefaultControlData.m_snapMaxLinearVelocity;
        v25[v21 + 2].m_snapMaxAngularVelocity = this->mDefaultControlData.m_snapMaxAngularVelocity;
        v25[v21 + 2].m_snapMaxLinearDistance = this->mDefaultControlData.m_snapMaxLinearDistance;
        v25[v21 + 2].m_snapMaxAngularDistance = this->mDefaultControlData.m_snapMaxAngularDistance;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_hierarchyGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_accelerationGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_positionGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_snapGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_velocityGain = 0.0;
      }
      else
      {
        v25[v21 + 2].m_hierarchyGain = p_mDefaultControlData->m_hierarchyGain;
        v25[v21 + 2].m_velocityDamping = p_mDefaultControlData->m_velocityDamping;
        v25[v21 + 2].m_accelerationGain = p_mDefaultControlData->m_accelerationGain;
        v25[v21 + 2].m_velocityGain = p_mDefaultControlData->m_velocityGain;
        v25[v21 + 2].m_positionGain = p_mDefaultControlData->m_positionGain;
        v25[v21 + 2].m_positionMaxLinearVelocity = p_mDefaultControlData->m_positionMaxLinearVelocity;
        v25[v21 + 2].m_positionMaxAngularVelocity = p_mDefaultControlData->m_positionMaxAngularVelocity;
        v25[v21 + 2].m_snapGain = p_mDefaultControlData->m_snapGain;
        v25[v21 + 2].m_snapMaxLinearVelocity = p_mDefaultControlData->m_snapMaxLinearVelocity;
        v25[v21 + 2].m_snapMaxAngularVelocity = p_mDefaultControlData->m_snapMaxAngularVelocity;
        v25[v21 + 2].m_snapMaxLinearDistance = p_mDefaultControlData->m_snapMaxLinearDistance;
        v25[v21 + 2].m_snapMaxAngularDistance = p_mDefaultControlData->m_snapMaxAngularDistance;
      }
      this->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19 + 2] = v22;
      v26 = this->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v22 + 1 > this->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v26[v21 + 3].m_hierarchyGain = this->mDefaultControlData.m_hierarchyGain;
        v26[v21 + 3].m_velocityDamping = this->mDefaultControlData.m_velocityDamping;
        v26[v21 + 3].m_accelerationGain = this->mDefaultControlData.m_accelerationGain;
        v26[v21 + 3].m_velocityGain = this->mDefaultControlData.m_velocityGain;
        v26[v21 + 3].m_positionGain = this->mDefaultControlData.m_positionGain;
        v26[v21 + 3].m_positionMaxLinearVelocity = this->mDefaultControlData.m_positionMaxLinearVelocity;
        v26[v21 + 3].m_positionMaxAngularVelocity = this->mDefaultControlData.m_positionMaxAngularVelocity;
        v26[v21 + 3].m_snapGain = this->mDefaultControlData.m_snapGain;
        v26[v21 + 3].m_snapMaxLinearVelocity = this->mDefaultControlData.m_snapMaxLinearVelocity;
        v26[v21 + 3].m_snapMaxAngularVelocity = this->mDefaultControlData.m_snapMaxAngularVelocity;
        v26[v21 + 3].m_snapMaxLinearDistance = this->mDefaultControlData.m_snapMaxLinearDistance;
        v26[v21 + 3].m_snapMaxAngularDistance = this->mDefaultControlData.m_snapMaxAngularDistance;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_hierarchyGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_accelerationGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_positionGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_snapGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_velocityGain = 0.0;
      }
      else
      {
        v26[v21 + 3].m_hierarchyGain = p_mDefaultControlData->m_hierarchyGain;
        v26[v21 + 3].m_velocityDamping = p_mDefaultControlData->m_velocityDamping;
        v26[v21 + 3].m_accelerationGain = p_mDefaultControlData->m_accelerationGain;
        v26[v21 + 3].m_velocityGain = p_mDefaultControlData->m_velocityGain;
        v26[v21 + 3].m_positionGain = p_mDefaultControlData->m_positionGain;
        v26[v21 + 3].m_positionMaxLinearVelocity = p_mDefaultControlData->m_positionMaxLinearVelocity;
        v26[v21 + 3].m_positionMaxAngularVelocity = p_mDefaultControlData->m_positionMaxAngularVelocity;
        v26[v21 + 3].m_snapGain = p_mDefaultControlData->m_snapGain;
        v26[v21 + 3].m_snapMaxLinearVelocity = p_mDefaultControlData->m_snapMaxLinearVelocity;
        v26[v21 + 3].m_snapMaxAngularVelocity = p_mDefaultControlData->m_snapMaxAngularVelocity;
        v26[v21 + 3].m_snapMaxLinearDistance = p_mDefaultControlData->m_snapMaxLinearDistance;
        v26[v21 + 3].m_snapMaxAngularDistance = p_mDefaultControlData->m_snapMaxAngularDistance;
      }
      this->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19 + 3] = v22 + 1;
      v18 += 4;
      v22 += 4;
      v19 += 4i64;
      v21 += 4i64;
    }
    while ( v19 < v20 - 3 );
  }
  if ( v19 < v20 )
  {
    v27 = v19;
    do
    {
      v28 = this->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v18 > this->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v28[v27].m_hierarchyGain = this->mDefaultControlData.m_hierarchyGain;
        v28[v27].m_velocityDamping = this->mDefaultControlData.m_velocityDamping;
        v28[v27].m_accelerationGain = this->mDefaultControlData.m_accelerationGain;
        v28[v27].m_velocityGain = this->mDefaultControlData.m_velocityGain;
        v28[v27].m_positionGain = this->mDefaultControlData.m_positionGain;
        v28[v27].m_positionMaxLinearVelocity = this->mDefaultControlData.m_positionMaxLinearVelocity;
        v28[v27].m_positionMaxAngularVelocity = this->mDefaultControlData.m_positionMaxAngularVelocity;
        v28[v27].m_snapGain = this->mDefaultControlData.m_snapGain;
        v28[v27].m_snapMaxLinearVelocity = this->mDefaultControlData.m_snapMaxLinearVelocity;
        v28[v27].m_snapMaxAngularVelocity = this->mDefaultControlData.m_snapMaxAngularVelocity;
        v28[v27].m_snapMaxLinearDistance = this->mDefaultControlData.m_snapMaxLinearDistance;
        v28[v27].m_snapMaxAngularDistance = this->mDefaultControlData.m_snapMaxAngularDistance;
        this->mRigidBodyController->m_controlDataPalette.m_data[v27].m_hierarchyGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v27].m_accelerationGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v27].m_positionGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v27].m_snapGain = 0.0;
        this->mRigidBodyController->m_controlDataPalette.m_data[v27].m_velocityGain = 0.0;
      }
      else
      {
        v28[v27].m_hierarchyGain = p_mDefaultControlData->m_hierarchyGain;
        v28[v27].m_velocityDamping = p_mDefaultControlData->m_velocityDamping;
        v28[v27].m_accelerationGain = p_mDefaultControlData->m_accelerationGain;
        v28[v27].m_velocityGain = p_mDefaultControlData->m_velocityGain;
        v28[v27].m_positionGain = p_mDefaultControlData->m_positionGain;
        v28[v27].m_positionMaxLinearVelocity = p_mDefaultControlData->m_positionMaxLinearVelocity;
        v28[v27].m_positionMaxAngularVelocity = p_mDefaultControlData->m_positionMaxAngularVelocity;
        v28[v27].m_snapGain = p_mDefaultControlData->m_snapGain;
        v28[v27].m_snapMaxLinearVelocity = p_mDefaultControlData->m_snapMaxLinearVelocity;
        v28[v27].m_snapMaxAngularVelocity = p_mDefaultControlData->m_snapMaxAngularVelocity;
        v28[v27].m_snapMaxLinearDistance = p_mDefaultControlData->m_snapMaxLinearDistance;
        v28[v27].m_snapMaxAngularDistance = p_mDefaultControlData->m_snapMaxAngularDistance;
      }
      this->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19++] = v18++;
      ++v27;
    }
    while ( v19 < v20 );
  }
}

// File Line: 570
// RVA: 0xB1CB0
void __fastcall UFG::Ragdoll::SetPositionTrackingStiffness(UFG::Ragdoll *this, float p)
{
  hkaRagdollRigidBodyController *mRigidBodyController; // r10
  __int64 v3; // r11
  __int64 v4; // r8
  bool v5; // dl
  float *v6; // rcx
  float *v7; // rax
  float v8; // xmm4_4
  float v9; // xmm6_4
  unsigned __int64 v10; // r9
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float *v15; // rax
  __int64 v16; // r8
  float v17; // xmm4_4
  float v18; // xmm4_4
  __int64 m_size; // rdx
  bool v20; // r8
  float *p_m_positionMaxAngularVelocity; // rcx
  float *v22; // rax
  unsigned __int64 v23; // r9
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float *p_m_hierarchyGain; // rax
  __int64 v32; // rdx
  float v33; // xmm4_4

  mRigidBodyController = this->mRigidBodyController;
  v3 = 0i64;
  if ( p >= 1.0 )
  {
    m_size = mRigidBodyController->m_controlDataPalette.m_size;
    v20 = sClamp_PositionGain;
    if ( m_size >= 4 )
    {
      p_m_positionMaxAngularVelocity = &mRigidBodyController->m_controlDataPalette.m_data->m_positionMaxAngularVelocity;
      v22 = &mRigidBodyController->m_controlDataPalette.m_data[1].m_positionMaxAngularVelocity;
      v23 = ((unsigned __int64)(m_size - 4) >> 2) + 1;
      v3 = 4 * v23;
      v24 = (float)((float)(p * 98.599998) * 0.0099999998) + 1.4;
      v25 = (float)((float)(p * 8.3415899) * 0.0099999998) + 1.8;
      v26 = (float)(p * 0.28) * 0.0099999998;
      do
      {
        *(p_m_positionMaxAngularVelocity - 2) = v26 + UFG::g_default_m_positionGain;
        *(p_m_positionMaxAngularVelocity - 1) = v24;
        *p_m_positionMaxAngularVelocity = v25;
        *(p_m_positionMaxAngularVelocity - 4) = UFG::g_default_m_accelerationGain;
        *(p_m_positionMaxAngularVelocity - 5) = UFG::g_default_m_velocityDamping;
        *(p_m_positionMaxAngularVelocity - 3) = UFG::g_default_m_velocityGain;
        *(p_m_positionMaxAngularVelocity - 6) = UFG::g_default_m_hierarchyGain;
        p_m_positionMaxAngularVelocity[1] = UFG::g_default_m_snapGain;
        if ( v20 )
        {
          v27 = *(p_m_positionMaxAngularVelocity - 2);
          if ( v27 <= 0.0 )
          {
            v27 = 0.0;
          }
          else if ( v27 >= 1.0 )
          {
            v27 = *(float *)&FLOAT_1_0;
          }
          *(p_m_positionMaxAngularVelocity - 2) = v27;
        }
        *(v22 - 2) = v26 + UFG::g_default_m_positionGain;
        *(v22 - 1) = v24;
        *v22 = v25;
        *(v22 - 4) = UFG::g_default_m_accelerationGain;
        *(v22 - 5) = UFG::g_default_m_velocityDamping;
        *(v22 - 3) = UFG::g_default_m_velocityGain;
        p_m_positionMaxAngularVelocity[6] = UFG::g_default_m_hierarchyGain;
        v22[1] = UFG::g_default_m_snapGain;
        if ( v20 )
        {
          v28 = *(v22 - 2);
          if ( v28 <= 0.0 )
          {
            v28 = 0.0;
          }
          else if ( v28 >= 1.0 )
          {
            v28 = *(float *)&FLOAT_1_0;
          }
          *(v22 - 2) = v28;
        }
        v22[10] = v26 + UFG::g_default_m_positionGain;
        v22[11] = v24;
        v22[12] = v25;
        v22[8] = UFG::g_default_m_accelerationGain;
        v22[7] = UFG::g_default_m_velocityDamping;
        v22[9] = UFG::g_default_m_velocityGain;
        p_m_positionMaxAngularVelocity[18] = UFG::g_default_m_hierarchyGain;
        v22[13] = UFG::g_default_m_snapGain;
        if ( v20 )
        {
          v29 = v22[10];
          if ( v29 <= 0.0 )
          {
            v29 = 0.0;
          }
          else if ( v29 >= 1.0 )
          {
            v29 = *(float *)&FLOAT_1_0;
          }
          v22[10] = v29;
        }
        v22[22] = v26 + UFG::g_default_m_positionGain;
        v22[23] = v24;
        v22[24] = v25;
        v22[20] = UFG::g_default_m_accelerationGain;
        v22[19] = UFG::g_default_m_velocityDamping;
        v22[21] = UFG::g_default_m_velocityGain;
        p_m_positionMaxAngularVelocity[30] = UFG::g_default_m_hierarchyGain;
        v22[25] = UFG::g_default_m_snapGain;
        if ( v20 )
        {
          v30 = v22[22];
          if ( v30 <= 0.0 )
          {
            v30 = 0.0;
          }
          else if ( v30 >= 1.0 )
          {
            v30 = *(float *)&FLOAT_1_0;
          }
          v22[22] = v30;
        }
        p_m_positionMaxAngularVelocity += 48;
        v22 += 48;
        --v23;
      }
      while ( v23 );
    }
    if ( v3 < m_size )
    {
      p_m_hierarchyGain = &mRigidBodyController->m_controlDataPalette.m_data[v3].m_hierarchyGain;
      v32 = m_size - v3;
      do
      {
        v33 = (float)((float)(p * 0.28) * 0.0099999998) + UFG::g_default_m_positionGain;
        p_m_hierarchyGain[5] = (float)((float)(p * 98.599998) * 0.0099999998) + 1.4;
        p_m_hierarchyGain[6] = (float)((float)(p * 8.3415899) * 0.0099999998) + 1.8;
        p_m_hierarchyGain[4] = v33;
        p_m_hierarchyGain[2] = UFG::g_default_m_accelerationGain;
        p_m_hierarchyGain[1] = UFG::g_default_m_velocityDamping;
        p_m_hierarchyGain[3] = UFG::g_default_m_velocityGain;
        *p_m_hierarchyGain = UFG::g_default_m_hierarchyGain;
        p_m_hierarchyGain[7] = UFG::g_default_m_snapGain;
        if ( v20 )
        {
          if ( v33 <= 0.0 )
          {
            v33 = 0.0;
          }
          else if ( v33 >= 1.0 )
          {
            v33 = *(float *)&FLOAT_1_0;
          }
          p_m_hierarchyGain[4] = v33;
        }
        p_m_hierarchyGain += 12;
        --v32;
      }
      while ( v32 );
    }
  }
  else
  {
    v4 = mRigidBodyController->m_controlDataPalette.m_size;
    v5 = sClamp_PositionGain;
    if ( v4 >= 4 )
    {
      v6 = &mRigidBodyController->m_controlDataPalette.m_data->m_positionMaxAngularVelocity;
      v7 = &mRigidBodyController->m_controlDataPalette.m_data[1].m_positionMaxAngularVelocity;
      v8 = p * 1.4;
      v9 = p * 1.8;
      v10 = ((unsigned __int64)(v4 - 4) >> 2) + 1;
      v3 = 4 * v10;
      do
      {
        *(v6 - 2) = UFG::g_default_m_positionGain * p;
        *(v6 - 1) = v8;
        *v6 = v9;
        *(v6 - 4) = UFG::g_default_m_accelerationGain * p;
        *(v6 - 5) = UFG::g_default_m_velocityDamping * p;
        *(v6 - 3) = UFG::g_default_m_velocityGain * p;
        *(v6 - 6) = UFG::g_default_m_hierarchyGain * p;
        v6[1] = UFG::g_default_m_snapGain * p;
        if ( v5 )
        {
          v11 = *(v6 - 2);
          if ( v11 <= 0.0 )
          {
            v11 = 0.0;
          }
          else if ( v11 >= 1.0 )
          {
            v11 = *(float *)&FLOAT_1_0;
          }
          *(v6 - 2) = v11;
        }
        *(v7 - 2) = UFG::g_default_m_positionGain * p;
        *(v7 - 1) = v8;
        *v7 = v9;
        *(v7 - 4) = UFG::g_default_m_accelerationGain * p;
        *(v7 - 5) = UFG::g_default_m_velocityDamping * p;
        *(v7 - 3) = UFG::g_default_m_velocityGain * p;
        v6[6] = UFG::g_default_m_hierarchyGain * p;
        v7[1] = UFG::g_default_m_snapGain * p;
        if ( v5 )
        {
          v12 = *(v7 - 2);
          if ( v12 <= 0.0 )
          {
            v12 = 0.0;
          }
          else if ( v12 >= 1.0 )
          {
            v12 = *(float *)&FLOAT_1_0;
          }
          *(v7 - 2) = v12;
        }
        v7[10] = UFG::g_default_m_positionGain * p;
        v7[11] = v8;
        v7[12] = v9;
        v7[8] = UFG::g_default_m_accelerationGain * p;
        v7[7] = UFG::g_default_m_velocityDamping * p;
        v7[9] = UFG::g_default_m_velocityGain * p;
        v6[18] = UFG::g_default_m_hierarchyGain * p;
        v7[13] = UFG::g_default_m_snapGain * p;
        if ( v5 )
        {
          v13 = v7[10];
          if ( v13 <= 0.0 )
          {
            v13 = 0.0;
          }
          else if ( v13 >= 1.0 )
          {
            v13 = *(float *)&FLOAT_1_0;
          }
          v7[10] = v13;
        }
        v7[22] = UFG::g_default_m_positionGain * p;
        v7[23] = v8;
        v7[24] = v9;
        v7[20] = UFG::g_default_m_accelerationGain * p;
        v7[19] = UFG::g_default_m_velocityDamping * p;
        v7[21] = UFG::g_default_m_velocityGain * p;
        v6[30] = UFG::g_default_m_hierarchyGain * p;
        v7[25] = UFG::g_default_m_snapGain * p;
        if ( v5 )
        {
          v14 = v7[22];
          if ( v14 <= 0.0 )
          {
            v14 = 0.0;
          }
          else if ( v14 >= 1.0 )
          {
            v14 = *(float *)&FLOAT_1_0;
          }
          v7[22] = v14;
        }
        v6 += 48;
        v7 += 48;
        --v10;
      }
      while ( v10 );
    }
    if ( v3 < v4 )
    {
      v15 = &mRigidBodyController->m_controlDataPalette.m_data[v3].m_hierarchyGain;
      v16 = v4 - v3;
      do
      {
        v17 = UFG::g_default_m_positionGain;
        v15[5] = p * 1.4;
        v15[6] = p * 1.8;
        v18 = v17 * p;
        v15[4] = v18;
        v15[2] = UFG::g_default_m_accelerationGain * p;
        v15[1] = UFG::g_default_m_velocityDamping * p;
        v15[3] = UFG::g_default_m_velocityGain * p;
        *v15 = UFG::g_default_m_hierarchyGain * p;
        v15[7] = UFG::g_default_m_snapGain * p;
        if ( v5 )
        {
          if ( v18 <= 0.0 )
          {
            v18 = 0.0;
          }
          else if ( v18 >= 1.0 )
          {
            v18 = *(float *)&FLOAT_1_0;
          }
          v15[4] = v18;
        }
        v15 += 12;
        --v16;
      }
      while ( v16 );
    }
  }
}

// File Line: 622
// RVA: 0xAB270
float __fastcall UFG::Ragdoll::GetPositionTrackingStiffness(UFG::Ragdoll *this)
{
  float m_positionGain; // xmm0_4

  m_positionGain = this->mRigidBodyController->m_controlDataPalette.m_data->m_positionGain;
  if ( m_positionGain >= 0.050000001 )
    return (float)((float)(m_positionGain - 0.050000001) * 357.14285) + 1.0;
  else
    return m_positionGain * 20.0;
}

// File Line: 638
// RVA: 0xB23E0
void __fastcall UFG::Ragdoll::SetPositionTrackingStiffnessAtJoint(UFG::Ragdoll *this, float p, int skeletonBoneID)
{
  __int64 v3; // r9
  hkaSkeletonMapper *highResToRagdollMapper; // rdx
  __int64 m_size; // r10
  hkaSkeletonMapperData::SimpleMapping *m_data; // rdx
  int m_boneB; // eax
  hkaKeyFrameHierarchyUtility::ControlData *v8; // rdx
  float v9; // xmm0_4

  if ( this->mRagdollInstance
    && (v3 = 0i64,
        highResToRagdollMapper = this->mRagdollData.m_pPointer->highResToRagdollMapper,
        m_size = highResToRagdollMapper->m_mapping.m_simpleMappings.m_size,
        m_size > 0) )
  {
    m_data = highResToRagdollMapper->m_mapping.m_simpleMappings.m_data;
    while ( m_data->m_boneA != skeletonBoneID )
    {
      ++v3;
      ++m_data;
      if ( v3 >= m_size )
        goto LABEL_6;
    }
    m_boneB = m_data->m_boneB;
  }
  else
  {
LABEL_6:
    m_boneB = -1;
  }
  v8 = &this->mRigidBodyController->m_controlDataPalette.m_data[m_boneB];
  if ( p >= 1.0 )
  {
    v8->m_positionGain = (float)((float)(p * 0.28) * 0.0099999998) + UFG::g_default_m_positionGain;
    v8->m_positionMaxAngularVelocity = (float)((float)(p * 8.3415899) * 0.0099999998) + 1.8;
    v8->m_positionMaxLinearVelocity = (float)((float)(p * 98.599998) * 0.0099999998) + 1.4;
    v8->m_accelerationGain = UFG::g_default_m_accelerationGain;
    v8->m_velocityDamping = UFG::g_default_m_velocityDamping;
    v8->m_velocityGain = UFG::g_default_m_velocityGain;
    v8->m_hierarchyGain = UFG::g_default_m_hierarchyGain;
    v8->m_snapGain = UFG::g_default_m_snapGain;
  }
  else
  {
    v9 = UFG::g_default_m_positionGain * p;
    v8->m_positionMaxLinearVelocity = p * 1.4;
    v8->m_positionGain = v9;
    v8->m_positionMaxAngularVelocity = p * 1.8;
    v8->m_accelerationGain = UFG::g_default_m_accelerationGain * p;
    v8->m_velocityDamping = UFG::g_default_m_velocityDamping * p;
    v8->m_velocityGain = UFG::g_default_m_velocityGain * p;
    v8->m_hierarchyGain = UFG::g_default_m_hierarchyGain * p;
    v8->m_snapGain = UFG::g_default_m_snapGain * p;
  }
}

// File Line: 698
// RVA: 0xAF980
void __fastcall UFG::Ragdoll::RemoveFromWorld(UFG::Ragdoll *this)
{
  hkpEaseConstraintsAction *mEaseConstraintsAction; // rdx
  hkpWorld *m_world; // rcx
  hkpAabbPhantom *mPhantom; // rdx
  hkpWorld *v5; // rcx
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  if ( hkaRagdollInstance::getWorld(this->mRagdollInstance) )
    hkaRagdollInstance::removeFromWorld(this->mRagdollInstance, &result);
  mEaseConstraintsAction = this->mEaseConstraintsAction;
  m_world = mEaseConstraintsAction->m_world;
  if ( m_world )
    hkpWorld::removeAction(m_world, mEaseConstraintsAction);
  mPhantom = this->mPhantom;
  v5 = mPhantom->m_world;
  if ( v5 )
    hkpWorld::removePhantom(v5, mPhantom);
}

// File Line: 726
// RVA: 0xA0A00
void __fastcall UFG::Ragdoll::AddToWorld(UFG::Ragdoll *this)
{
  hkpWorld *mWorld; // rbx
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  if ( !hkaRagdollInstance::getWorld(this->mRagdollInstance) )
  {
    mWorld = UFG::BasePhysicsSystem::mInstance->mWorld;
    hkaRagdollInstance::addToWorld(this->mRagdollInstance, &result, mWorld, (hkBool)1);
    hkpWorld::addPhantom(mWorld, this->mPhantom);
    this->m_framesSinceInterpenetration = 0;
  }
}

// File Line: 754
// RVA: 0xA8C50
void __fastcall UFG::Ragdoll::ForcePose(
        UFG::Ragdoll *this,
        hkaSkeleton *skel,
        hkaPose *pose,
        hkQsTransformf *worldTransform)
{
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *SyncedPoseModelSpace; // rsi
  hkaSkeleton *m_pntr; // rdi
  int m_size; // ebx
  hkLifoAllocator *Value; // rax
  int v10; // edx
  hkQsTransformf *m_cur; // r14
  char *v12; // rcx
  int v13; // ebx
  int v14; // esi
  hkLifoAllocator *v15; // rax
  int v16; // edx
  hkQsTransformf *v17; // rcx
  char *v18; // r8
  hkaRagdollInstance *mRagdollInstance; // r15
  int v20; // ebx
  __int64 v21; // rdi
  int v22; // edx
  hkpRigidBody *v23; // rcx
  hkVector4f v24; // xmm6
  hkVector4f v25; // xmm7
  hkVector4f v26; // xmm8
  hkVector4f v27; // xmm9
  hkVector4f v28; // xmm10
  hkVector4f v29; // xmm11
  __int64 v30; // rax
  bool v31; // zf
  __m128 *v32; // rax
  __int64 v33; // rdi
  char *v34; // r14
  hkpEntity *v35; // rbx
  hkpEntity *v36; // rbx
  void **v37; // rdx
  hkpEntity *v38; // rbx
  hkaRagdollInstance *v39; // rcx
  hkpEaseConstraintsAction *mEaseConstraintsAction; // rcx
  hkpWorld *World; // rax
  char *v42; // rdi
  int v43; // ecx
  hkLifoAllocator *v44; // rcx
  signed int v45; // ebx
  int v46; // r8d
  hkLifoAllocator *v47; // rax
  int v48; // r8d
  hkaSkeletonMapper::ConstraintSource source; // [rsp+20h] [rbp-79h]
  signed int v50; // [rsp+28h] [rbp-71h]
  hkQsTransformf *array; // [rsp+30h] [rbp-69h] BYREF
  void *p[2]; // [rsp+38h] [rbp-61h] BYREF
  __m128 *v53; // [rsp+48h] [rbp-51h]
  hkQsTransformf *v54; // [rsp+50h] [rbp-49h]
  int v55; // [rsp+58h] [rbp-41h]
  __int64 v56; // [rsp+60h] [rbp-39h]
  int numBytesIn[2]; // [rsp+F8h] [rbp+5Fh]
  void *retaddr; // [rsp+118h] [rbp+7Fh]

  v56 = -2i64;
  SyncedPoseModelSpace = hkaPose::getSyncedPoseModelSpace(pose);
  m_pntr = this->mRagdollInstance->m_skeleton.m_pntr;
  m_size = m_pntr->m_bones.m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v50 = (48 * m_size + 127) & 0xFFFFFF80;
  v10 = (v50 + 15) & 0xFFFFFFF0;
  numBytesIn[0] = v10;
  m_cur = (hkQsTransformf *)Value->m_cur;
  array = m_cur;
  v12 = (char *)m_cur + v10;
  if ( v10 > Value->m_slabSize || v12 > Value->m_end )
  {
    m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
    array = m_cur;
  }
  else
  {
    Value->m_cur = v12;
  }
  v54 = m_cur;
  v55 = m_size;
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    m_size,
    m_pntr->m_parentIndices.m_data,
    m_pntr->m_referencePose.m_data,
    m_cur);
  hkaSkeletonMapper::mapPose(
    this->mRagdollData.m_pPointer->highResToRagdollMapper,
    SyncedPoseModelSpace->m_data,
    m_pntr->m_referencePose.m_data,
    m_cur,
    CURRENT_POSE);
  v13 = m_size - this->mRagdollData.m_pPointer->mLastCoreRagdollBone - 1;
  v14 = 0;
  array = 0i64;
  p[0] = (void *)0x8000000000000000i64;
  source = v13;
  if ( v13 )
  {
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (((112 * v13 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v17 = (hkQsTransformf *)v15->m_cur;
    v18 = (char *)v17 + v16;
    if ( v16 > v15->m_slabSize || v18 > v15->m_end )
      v17 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v15, v16);
    else
      v15->m_cur = v18;
  }
  else
  {
    v17 = 0i64;
  }
  array = v17;
  HIDWORD(p[0]) = v13 | 0x80000000;
  p[1] = v17;
  mRagdollInstance = this->mRagdollInstance;
  v20 = this->mRagdollData.m_pPointer->mLastCoreRagdollBone + 1;
  if ( v20 < mRagdollInstance->m_rigidBodies.m_size )
  {
    v21 = v20;
    v22 = (int)p[0];
    do
    {
      v23 = mRagdollInstance->m_rigidBodies.m_data[v21];
      v24.m_quad = (__m128)v23->m_motion.m_motionState.m_transform.m_rotation.m_col0;
      v25.m_quad = (__m128)v23->m_motion.m_motionState.m_transform.m_rotation.m_col1;
      v26.m_quad = (__m128)v23->m_motion.m_motionState.m_transform.m_rotation.m_col2;
      v27.m_quad = (__m128)v23->m_motion.m_motionState.m_transform.m_translation;
      v28.m_quad = (__m128)v23->m_motion.m_linearVelocity;
      v29.m_quad = (__m128)v23->m_motion.m_angularVelocity;
      if ( v22 == (HIDWORD(p[0]) & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 112);
        v22 = (int)p[0];
      }
      v30 = 112i64 * v22;
      v31 = (hkQsTransformf *)((char *)array + v30) == 0i64;
      v32 = (__m128 *)((char *)&array->m_translation.m_quad + v30);
      v53 = v32;
      p[0] = v32;
      if ( !v31 )
      {
        *(hkVector4f *)v32 = (hkVector4f)v24.m_quad;
        v32[1] = v25.m_quad;
        v32[2] = v26.m_quad;
        v32[3] = v27.m_quad;
        v32[4] = v28.m_quad;
        v32[5] = v29.m_quad;
        v32[6].m128_i32[0] = v20;
      }
      v22 = ++LODWORD(p[0]);
      ++v20;
      ++v21;
    }
    while ( v20 < mRagdollInstance->m_rigidBodies.m_size );
  }
  hkaRagdollInstance::setPoseModelSpace(this->mRagdollInstance, m_cur, worldTransform);
  if ( SLODWORD(p[0]) > 0 )
  {
    v33 = 0i64;
    do
    {
      v34 = (char *)array + v33;
      if ( (_BYTE)retaddr )
      {
        *(_OWORD *)p = 0i64;
        v35 = mRagdollInstance->m_rigidBodies.m_data[*((int *)v34 + 24)];
        hkpEntity::activate(v35);
        v35->m_motion.vfptr[9].__vecDelDtor(&v35->m_motion, (unsigned int)p);
        v36 = mRagdollInstance->m_rigidBodies.m_data[*((int *)v34 + 24)];
        hkpEntity::activate(v36);
        v37 = p;
      }
      else
      {
        hkpRigidBody::setTransform(
          mRagdollInstance->m_rigidBodies.m_data[*((int *)v34 + 24)],
          (hkTransformf *)((char *)array + v33));
        v38 = mRagdollInstance->m_rigidBodies.m_data[*((int *)v34 + 24)];
        hkpEntity::activate(v38);
        v38->m_motion.vfptr[9].__vecDelDtor(&v38->m_motion, (unsigned int)(v34 + 64));
        v36 = mRagdollInstance->m_rigidBodies.m_data[*((int *)v34 + 24)];
        hkpEntity::activate(v36);
        v37 = (void **)(v34 + 80);
      }
      ((void (__fastcall *)(hkpMaxSizeMotion *, void **))v36->m_motion.vfptr[9].__first_virtual_table_function__)(
        &v36->m_motion,
        v37);
      ++v14;
      v33 += 112i64;
    }
    while ( v14 < SLODWORD(p[0]) );
    m_cur = array;
  }
  hkaRagdollRigidBodyController::reinitialize(this->mRigidBodyController);
  if ( (_BYTE)retaddr )
  {
    v39 = this->mRagdollInstance;
    if ( v39 )
    {
      if ( hkaRagdollInstance::getWorld(v39) )
      {
        mEaseConstraintsAction = this->mEaseConstraintsAction;
        if ( !mEaseConstraintsAction->m_world )
        {
          hkpEaseConstraintsAction::loosenConstraints(mEaseConstraintsAction);
          hkpEaseConstraintsAction::restoreConstraints(this->mEaseConstraintsAction, 0.5);
          World = hkaRagdollInstance::getWorld(this->mRagdollInstance);
          hkpWorld::addAction(World, this->mEaseConstraintsAction);
        }
      }
    }
  }
  v42 = (char *)p[1];
  v43 = (int)p[0];
  if ( p[1] == array )
    v43 = 0;
  LODWORD(p[0]) = v43;
  v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v45 = (112 * source + 127) & 0xFFFFFF80;
  v46 = (v45 + 15) & 0xFFFFFFF0;
  if ( v45 > v44->m_slabSize || &v42[v46] != v44->m_cur || v44->m_firstNonLifoEnd == v42 )
    hkLifoAllocator::slowBlockFree(v44, v42, v46);
  else
    v44->m_cur = v42;
  LODWORD(p[0]) = 0;
  if ( SHIDWORD(p[0]) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array,
      112 * (HIDWORD(p[0]) & 0x3FFFFFFF));
  array = 0i64;
  HIDWORD(p[0]) = 0x80000000;
  v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v50 > v47->m_slabSize )
  {
    v48 = numBytesIn[0];
  }
  else
  {
    v48 = numBytesIn[0];
    if ( (char *)m_cur + numBytesIn[0] == v47->m_cur && v47->m_firstNonLifoEnd != m_cur )
    {
      v47->m_cur = m_cur;
      return;
    }
  }
  hkLifoAllocator::slowBlockFree(v47, m_cur, v48);
}  }
  else
  {
    v48 = numBytesIn[0];
    if ( (char *)m_cur + numBytesIn[0] == v47->m_cur && v47->m_firstNonLifoEnd != m_cur )
    {
      v47->m_cur = m_cur;
      return;
    }
  }
  hkLifoAllocator::slowBlockFree

// File Line: 865
// RVA: 0xAA110
void __fastcall UFG::Ragdoll::GetHighResPose(
        UFG::Ragdoll *this,
        hkaSkeleton *skel,
        hkaPose *pose,
        hkQsTransformf *worldTransform)
{
  int m_size; // ebx
  hkLifoAllocator *Value; // rax
  signed int v9; // ebp
  int v10; // esi
  hkQsTransformf *m_cur; // rdi
  char *v12; // rcx
  hkQsTransformf *m_data; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v14; // rax
  hkLifoAllocator *v15; // rax

  m_size = this->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (48 * m_size + 127) & 0xFFFFFF80;
  v10 = (v9 + 15) & 0xFFFFFFF0;
  m_cur = (hkQsTransformf *)Value->m_cur;
  v12 = (char *)m_cur + v10;
  if ( v10 > Value->m_slabSize || v12 > Value->m_end )
    m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
  else
    Value->m_cur = v12;
  hkaRagdollInstance::getPoseModelSpace(this->mRagdollInstance, m_cur, worldTransform);
  m_data = hkaPose::getSyncedPoseLocalSpace(pose)->m_data;
  v14 = hkaPose::accessSyncedPoseModelSpace(pose);
  hkaSkeletonMapper::mapPose(
    this->mRagdollData.m_pPointer->ragdollToHighResMapper,
    m_cur,
    m_data,
    v14->m_data,
    CURRENT_POSE);
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v9 > v15->m_slabSize || (char *)m_cur + v10 != v15->m_cur || v15->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v15, m_cur, v10);
  else
    v15->m_cur = m_cur;
}

// File Line: 882
// RVA: 0xACB70
void __fastcall UFG::Ragdoll::InitializeVelocityTracking(UFG::Ragdoll *this)
{
  this->m_framesSinceInterpenetration = 0;
  hkaRagdollRigidBodyController::reinitialize(this->mRigidBodyController);
}

// File Line: 890
// RVA: 0xB56C0
void __fastcall UFG::Ragdoll::UpdateVelocityTracking(
        UFG::Ragdoll *this,
        hkaSkeleton *skel,
        hkaPose *pose,
        hkQsTransformf *worldTransform,
        float deltaT)
{
  hkaSkeleton *m_pntr; // r14
  int m_size; // r12d
  hkLifoAllocator *Value; // rax
  signed int v10; // r15d
  int v11; // edi
  hkQsTransformf *m_cur; // rbp
  char *v13; // rcx
  hkQsTransformf *m_data; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *SyncedPoseModelSpace; // rax
  hkLifoAllocator *v16; // rax
  hkQsTransformf *v17; // rsi
  char *v18; // rcx
  hkLifoAllocator *v19; // rax
  signed int v20; // r13d
  int v21; // r14d
  hkaKeyFrameHierarchyUtility::Output *v22; // rbx
  char *v23; // rcx
  hkLifoAllocator *v24; // rax
  hkLifoAllocator *v25; // rax
  hkLifoAllocator *v26; // rax

  m_pntr = this->mRagdollInstance->m_skeleton.m_pntr;
  m_size = m_pntr->m_bones.m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (48 * m_size + 127) & 0xFFFFFF80;
  v11 = (v10 + 15) & 0xFFFFFFF0;
  m_cur = (hkQsTransformf *)Value->m_cur;
  v13 = (char *)m_cur + v11;
  if ( v11 > Value->m_slabSize || v13 > Value->m_end )
    m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
  else
    Value->m_cur = v13;
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    m_size,
    m_pntr->m_parentIndices.m_data,
    m_pntr->m_referencePose.m_data,
    m_cur);
  m_data = m_pntr->m_referencePose.m_data;
  SyncedPoseModelSpace = hkaPose::getSyncedPoseModelSpace(pose);
  hkaSkeletonMapper::mapPose(
    this->mRagdollData.m_pPointer->highResToRagdollMapper,
    SyncedPoseModelSpace->m_data,
    m_data,
    m_cur,
    CURRENT_POSE);
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkQsTransformf *)v16->m_cur;
  v18 = (char *)v17 + v11;
  if ( v11 > v16->m_slabSize || v18 > v16->m_end )
    v17 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v16, v11);
  else
    v16->m_cur = v18;
  hkaSkeletonUtils::transformModelPoseToLocalPose(m_size, m_pntr->m_parentIndices.m_data, m_cur, v17);
  v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (4 * m_size + 127) & 0xFFFFFF80;
  v21 = (v20 + 15) & 0xFFFFFFF0;
  v22 = (hkaKeyFrameHierarchyUtility::Output *)v19->m_cur;
  v23 = (char *)v22 + v21;
  if ( v21 > v19->m_slabSize || v23 > v19->m_end )
    v22 = (hkaKeyFrameHierarchyUtility::Output *)hkLifoAllocator::allocateFromNewSlab(v19, v21);
  else
    v19->m_cur = v23;
  UFG::Ragdoll::UpdatePenetrationRecovery(this);
  hkaRagdollRigidBodyController::driveToPose(this->mRigidBodyController, deltaT, v17, worldTransform, v22);
  v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v20 > v24->m_slabSize || (char *)v22 + v21 != v24->m_cur || v24->m_firstNonLifoEnd == v22 )
    hkLifoAllocator::slowBlockFree(v24, v22, v21);
  else
    v24->m_cur = v22;
  v25 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v10 > v25->m_slabSize || (char *)v17 + v11 != v25->m_cur || v25->m_firstNonLifoEnd == v17 )
    hkLifoAllocator::slowBlockFree(v25, v17, v11);
  else
    v25->m_cur = v17;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v10 > v26->m_slabSize || (char *)m_cur + v11 != v26->m_cur || v26->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v26, m_cur, v11);
  else
    v26->m_cur = m_cur;
}

// File Line: 943
// RVA: 0xACB50
void __fastcall UFG::Ragdoll::InitializePoweredTracking(UFG::Ragdoll *this)
{
  hkaRagdollInstance *mRagdollInstance; // rcx

  this->m_framesSinceInterpenetration = 0;
  mRagdollInstance = this->mRagdollInstance;
  if ( mRagdollInstance )
    hkaRagdollPoweredConstraintController::startMotors(mRagdollInstance);
}

// File Line: 955
// RVA: 0xB2B50
void __fastcall UFG::Ragdoll::ShutdownPoweredTracking(UFG::Ragdoll *this)
{
  hkaRagdollInstance *mRagdollInstance; // rcx

  mRagdollInstance = this->mRagdollInstance;
  if ( mRagdollInstance )
    hkaRagdollPoweredConstraintController::stopMotors(mRagdollInstance);
}

// File Line: 967
// RVA: 0xB4D70
void __fastcall UFG::Ragdoll::UpdatePenetrationRecovery(UFG::Ragdoll *this)
{
  hkaSkeleton *m_pntr; // r8
  DetectRagdollPenetration *mDetectRagdollPenetration; // rdi
  int v4; // edx
  __int64 v5; // rcx
  int m_size; // edi
  int v7; // esi
  int v8; // r9d
  int v9; // r9d
  int v10; // r9d
  int v11; // esi
  int v12; // r9d
  int m_capacityAndFlags; // ecx
  int v14; // ecx
  int v15; // r9d
  float *v16; // rdi
  __int64 v17; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v18; // rax
  hkArray<enum DetectRagdollPenetration::BonePenetrationStatus,hkContainerHeapAllocator> *p_m_boneStates; // r8
  int v20; // esi
  __int64 v21; // r12
  __int64 v22; // r13
  hkaRagdollInstance *mRagdollInstance; // rdx
  __int64 v24; // rcx
  hkpRigidBody *v25; // rdi
  int v26; // r15d
  DetectRagdollPenetration::BonePenetrationStatus v27; // ecx
  UFG::RagdollData *m_pPointer; // rax
  int v29; // r15d
  unsigned int v30; // edx
  int m_storage; // ecx
  int v32; // r15d
  hkpWorld *v33; // rcx
  int v34; // r15d
  hkpWorld *m_world; // rcx
  hkaPose ragdollPoseIn; // [rsp+30h] [rbp-59h] BYREF
  hkResult v37; // [rsp+80h] [rbp-9h] BYREF
  hkResult v38; // [rsp+84h] [rbp-5h] BYREF
  hkResult v39; // [rsp+88h] [rbp-1h] BYREF
  hkResult v40; // [rsp+8Ch] [rbp+3h] BYREF
  __int64 v41; // [rsp+90h] [rbp+7h]
  hkResult result; // [rsp+F0h] [rbp+67h] BYREF
  hkArray<enum DetectRagdollPenetration::BonePenetrationStatus,hkContainerHeapAllocator> *v43; // [rsp+F8h] [rbp+6Fh] BYREF
  hkResult v44; // [rsp+100h] [rbp+77h] BYREF
  hkResult v45; // [rsp+108h] [rbp+7Fh] BYREF

  v41 = -2i64;
  if ( this->mCollisionState )
  {
    this->m_framesSinceInterpenetration = 0;
    return;
  }
  if ( this->m_framesSinceInterpenetration < 70 )
  {
    m_pntr = this->mRagdollInstance->m_skeleton.m_pntr;
    mDetectRagdollPenetration = this->mDetectRagdollPenetration;
    v4 = 0;
    if ( mDetectRagdollPenetration->m_boneStates.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        mDetectRagdollPenetration->m_boneStates.m_data[v5] = HK_YESP;
        ++v4;
        ++v5;
      }
      while ( v4 < mDetectRagdollPenetration->m_boneStates.m_size );
    }
    mDetectRagdollPenetration->m_ragdollIsOut.m_bool = 0;
    ragdollPoseIn.m_skeleton = m_pntr;
    ragdollPoseIn.m_localPose.m_data = 0i64;
    ragdollPoseIn.m_localPose.m_size = 0;
    ragdollPoseIn.m_localPose.m_capacityAndFlags = 0x80000000;
    ragdollPoseIn.m_modelPose.m_data = 0i64;
    ragdollPoseIn.m_modelPose.m_size = 0;
    ragdollPoseIn.m_modelPose.m_capacityAndFlags = 0x80000000;
    ragdollPoseIn.m_boneFlags.m_data = 0i64;
    ragdollPoseIn.m_boneFlags.m_size = 0;
    ragdollPoseIn.m_boneFlags.m_capacityAndFlags = 0x80000000;
    *(_WORD *)&ragdollPoseIn.m_modelInSync.m_bool = 0;
    ragdollPoseIn.m_floatSlotValues.m_data = 0i64;
    ragdollPoseIn.m_floatSlotValues.m_size = 0;
    ragdollPoseIn.m_floatSlotValues.m_capacityAndFlags = 0x80000000;
    m_size = m_pntr->m_bones.m_size;
    v7 = (m_size + 3) & 0xFFFFFFFC;
    if ( v7 <= 0 )
      result.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &ragdollPoseIn.m_modelPose, v7, 48);
    if ( (ragdollPoseIn.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v7 )
      LODWORD(v43) = 0;
    else
      hkArrayUtil::_reserve((hkResult *)&v43, &hkContainerHeapAllocator::s_alloc, &ragdollPoseIn.m_localPose, v7, 48);
    if ( (ragdollPoseIn.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v7 )
      v44.m_enum = HK_SUCCESS;
    else
      hkArrayUtil::_reserve(&v44, &hkContainerHeapAllocator::s_alloc, &ragdollPoseIn.m_boneFlags, v7, 4);
    if ( (ragdollPoseIn.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
    {
      v45.m_enum = HK_SUCCESS;
    }
    else
    {
      v8 = m_size;
      if ( m_size < 2 * (ragdollPoseIn.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF) )
        v8 = 2 * (ragdollPoseIn.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v45, &hkContainerHeapAllocator::s_alloc, &ragdollPoseIn.m_modelPose, v8, 48);
    }
    ragdollPoseIn.m_modelPose.m_size = m_size;
    if ( (ragdollPoseIn.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
    {
      v40.m_enum = HK_SUCCESS;
    }
    else
    {
      v9 = m_size;
      if ( m_size < 2 * (ragdollPoseIn.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) )
        v9 = 2 * (ragdollPoseIn.m_localPose.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v40, &hkContainerHeapAllocator::s_alloc, &ragdollPoseIn.m_localPose, v9, 48);
    }
    ragdollPoseIn.m_localPose.m_size = m_size;
    if ( (ragdollPoseIn.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= m_size )
    {
      v39.m_enum = HK_SUCCESS;
    }
    else
    {
      v10 = m_size;
      if ( m_size < 2 * (ragdollPoseIn.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) )
        v10 = 2 * (ragdollPoseIn.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v39, &hkContainerHeapAllocator::s_alloc, &ragdollPoseIn.m_boneFlags, v10, 4);
    }
    ragdollPoseIn.m_boneFlags.m_size = m_size;
    v11 = ragdollPoseIn.m_skeleton->m_floatSlots.m_size;
    v12 = (v11 + 3) & 0xFFFFFFFC;
    m_capacityAndFlags = ragdollPoseIn.m_floatSlotValues.m_capacityAndFlags;
    if ( (ragdollPoseIn.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v12 )
    {
      v37.m_enum = HK_SUCCESS;
    }
    else
    {
      hkArrayUtil::_reserve(&v37, &hkContainerHeapAllocator::s_alloc, &ragdollPoseIn.m_floatSlotValues, v12, 4);
      m_capacityAndFlags = ragdollPoseIn.m_floatSlotValues.m_capacityAndFlags;
    }
    v14 = m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 >= v11 )
    {
      v38.m_enum = HK_SUCCESS;
    }
    else
    {
      v15 = v11;
      if ( v11 < 2 * v14 )
        v15 = 2 * v14;
      hkArrayUtil::_reserve(&v38, &hkContainerHeapAllocator::s_alloc, &ragdollPoseIn.m_floatSlotValues, v15, 4);
    }
    v16 = &ragdollPoseIn.m_floatSlotValues.m_data[ragdollPoseIn.m_floatSlotValues.m_size];
    v17 = v11 - ragdollPoseIn.m_floatSlotValues.m_size;
    if ( v11 - ragdollPoseIn.m_floatSlotValues.m_size > 0 )
    {
      while ( v17 )
      {
        *v16++ = 0.0;
        --v17;
      }
    }
    ragdollPoseIn.m_floatSlotValues.m_size = v11;
    v18 = hkaPose::accessUnsyncedPoseModelSpace(&ragdollPoseIn);
    hkaRagdollInstance::getPoseWorldSpace(this->mRagdollInstance, v18->m_data);
    DetectRagdollPenetration::detectPenetration(
      this->mDetectRagdollPenetration,
      (hkBool *)&result,
      &ragdollPoseIn,
      &this->mPenetratedBones);
    p_m_boneStates = &this->mDetectRagdollPenetration->m_boneStates;
    v43 = p_m_boneStates;
    if ( !LOBYTE(result.m_enum) )
      ++this->m_framesSinceInterpenetration;
    v20 = 0;
    if ( this->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
    {
      v21 = 0i64;
      v22 = 0i64;
      do
      {
        mRagdollInstance = this->mRagdollInstance;
        v24 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v21];
        if ( (int)v24 >= 0 )
          v25 = mRagdollInstance->m_rigidBodies.m_data[v24];
        else
          v25 = 0i64;
        v26 = mRagdollInstance->m_skeleton.m_pntr->m_parentIndices.m_data[v22];
        v27 = p_m_boneStates->m_data[v21];
        if ( v27 )
        {
          if ( v27 == HK_YESP )
          {
            UFG::Ragdoll::SetDynamic(this, v25, v20, 8u);
            UFG::Ragdoll::ApplyCorrectionImpulse(this, v25, v20, v26);
          }
          else
          {
            UFG::Ragdoll::SetDynamic(this, v25, v20, 8u);
          }
          UFG::Ragdoll::SetMotorState(this, v20, 0);
        }
        else
        {
          m_pPointer = this->mRagdollData.m_pPointer;
          v29 = this->mCollisionSystem << 6;
          v30 = m_pPointer->mCollisionFilterInfo.p[v20];
          m_storage = (unsigned __int8)v25->m_motion.m_type.m_storage;
          if ( v20 > m_pPointer->mLastCoreRagdollBone )
          {
            v34 = (32 * ((v30 >> 5) & 0x1F | (32 * ((v30 >> 10) & 0x1F | v29)))) | 0x15;
            if ( (_BYTE)m_storage != 5
              && (_BYTE)m_storage != 4
              && v25->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo == v34 )
            {
              goto LABEL_67;
            }
            hkpRigidBody::setMotionType(
              v25,
              MOTION_DYNAMIC,
              HK_ENTITY_ACTIVATION_DO_ACTIVATE,
              HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
            v25->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v34;
            m_world = v25->m_world;
            if ( m_world )
              hkpWorld::updateCollisionFilterOnEntity(
                m_world,
                v25,
                HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
                HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
          }
          else
          {
            v32 = (32 * ((v30 >> 5) & 0x1F | (32 * ((v30 >> 10) & 0x1F | v29)))) | 7;
            if ( (_BYTE)m_storage == 5
              || (_BYTE)m_storage == 4
              || v25->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo != v32 )
            {
              hkpRigidBody::setMotionType(
                v25,
                MOTION_DYNAMIC,
                HK_ENTITY_ACTIVATION_DO_ACTIVATE,
                HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
              v25->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v32;
              v33 = v25->m_world;
              if ( v33 )
                hkpWorld::updateCollisionFilterOnEntity(
                  v33,
                  v25,
                  HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
                  HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
            }
            UFG::Ragdoll::SetMotorState(this, v20, (hkBool)1);
          }
        }
        p_m_boneStates = v43;
LABEL_67:
        ++v20;
        ++v22;
        ++v21;
      }
      while ( v20 < this->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size );
    }
    hkaPose::~hkaPose(&ragdollPoseIn);
  }
}

// File Line: 1038
// RVA: 0xB5270
void __fastcall UFG::Ragdoll::UpdatePoweredTracking(UFG::Ragdoll *this, hkaSkeleton *skel, hkaPose *pose)
{
  hkaSkeleton *m_pntr; // r13
  int m_size; // r15d
  hkLifoAllocator *Value; // rax
  signed int v7; // r14d
  int v8; // edi
  hkQsTransformf *m_cur; // rsi
  char *v10; // rcx
  hkLifoAllocator *v11; // rax
  hkQsTransformf *v12; // rbp
  char *v13; // rcx
  hkQsTransformf *m_data; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *SyncedPoseModelSpace; // rax
  hkLifoAllocator *v16; // rax
  hkLifoAllocator *v17; // rax

  m_pntr = this->mRagdollInstance->m_skeleton.m_pntr;
  m_size = m_pntr->m_bones.m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (48 * m_size + 127) & 0xFFFFFF80;
  v8 = (v7 + 15) & 0xFFFFFFF0;
  m_cur = (hkQsTransformf *)Value->m_cur;
  v10 = (char *)m_cur + v8;
  if ( v8 > Value->m_slabSize || v10 > Value->m_end )
    m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v8);
  else
    Value->m_cur = v10;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkQsTransformf *)v11->m_cur;
  v13 = (char *)v12 + v8;
  if ( v8 > v11->m_slabSize || v13 > v11->m_end )
    v12 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v11, v8);
  else
    v11->m_cur = v13;
  hkaSkeletonUtils::transformLocalPoseToModelPose(
    m_size,
    m_pntr->m_parentIndices.m_data,
    m_pntr->m_referencePose.m_data,
    m_cur);
  m_data = m_pntr->m_referencePose.m_data;
  SyncedPoseModelSpace = hkaPose::getSyncedPoseModelSpace(pose);
  hkaSkeletonMapper::mapPose(
    this->mRagdollData.m_pPointer->highResToRagdollMapper,
    SyncedPoseModelSpace->m_data,
    m_data,
    m_cur,
    CURRENT_POSE);
  hkaSkeletonUtils::transformModelPoseToLocalPose(m_size, m_pntr->m_parentIndices.m_data, m_cur, v12);
  UFG::Ragdoll::UpdatePenetrationRecovery(this);
  hkaRagdollPoweredConstraintController::driveToPose(this->mRagdollInstance, v12);
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v7 > v16->m_slabSize || (char *)v12 + v8 != v16->m_cur || v16->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v16, v12, v8);
  else
    v16->m_cur = v12;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v7 > v17->m_slabSize || (char *)m_cur + v8 != v17->m_cur || v17->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v17, m_cur, v8);
  else
    v17->m_cur = m_cur;
}

// File Line: 1065
// RVA: 0xB2780
void __fastcall UFG::Ragdoll::SetVelocity(UFG::Ragdoll *this, UFG::qVector3 *v)
{
  int v2; // r14d
  __int64 v5; // rsi
  hkaRagdollInstance *mRagdollInstance; // rdx
  __int64 v7; // rcx
  hkpEntity *v8; // rbx
  __m128 v9; // [rsp+20h] [rbp-18h] BYREF

  v2 = 0;
  if ( this->mRagdollData.m_pPointer->mLastCoreRagdollBone >= 0 )
  {
    v5 = 0i64;
    do
    {
      mRagdollInstance = this->mRagdollInstance;
      v7 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v5];
      if ( (int)v7 >= 0 )
        v8 = mRagdollInstance->m_rigidBodies.m_data[v7];
      else
        v8 = 0i64;
      v9 = _mm_unpacklo_ps(
             _mm_unpacklo_ps((__m128)LODWORD(v->x), (__m128)LODWORD(v->z)),
             _mm_unpacklo_ps((__m128)LODWORD(v->y), (__m128)0i64));
      hkpEntity::activate(v8);
      v8->m_motion.vfptr[9].__vecDelDtor(&v8->m_motion, (unsigned int)&v9);
      ++v2;
      ++v5;
    }
    while ( v2 <= this->mRagdollData.m_pPointer->mLastCoreRagdollBone );
  }
}

// File Line: 1082
// RVA: 0xB06F0
void __fastcall UFG::Ragdoll::SetCollisionState(UFG::Ragdoll *this, UFG::Ragdoll::CollisionState state)
{
  hkaRagdollInstance *mRagdollInstance; // rax
  __int64 v3; // rsi
  __int64 i; // r14
  hkaRagdollInstance *v7; // rbx
  __int64 v8; // rcx
  hkpRigidBody *v9; // rbx
  UFG::RagdollData *m_pPointer; // rdx
  unsigned int v11; // edi
  int v12; // edi
  hkpMotion::MotionType v13; // edx
  unsigned int v14; // edi
  unsigned int v15; // edi
  unsigned int v16; // eax
  unsigned int v17; // edi
  hkpWorld *m_world; // rcx

  mRagdollInstance = this->mRagdollInstance;
  this->mCollisionState = state;
  v3 = 0i64;
  if ( mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
  {
    for ( i = 0i64; ; ++i )
    {
      v7 = this->mRagdollInstance;
      v8 = v7->m_boneToRigidBodyMap.m_data[i];
      v9 = (int)v8 >= 0 ? v7->m_rigidBodies.m_data[v8] : 0i64;
      m_pPointer = this->mRagdollData.m_pPointer;
      if ( (int)v3 > m_pPointer->mLastCoreRagdollBone )
        break;
      switch ( state )
      {
        case CS_DYNAMIC:
          v16 = m_pPointer->mCollisionFilterInfo.p[v3];
          v12 = (32 * ((v16 >> 5) & 0x1F | (32 * ((v16 >> 10) & 0x1F | (this->mCollisionSystem << 6))))) | 7;
          goto LABEL_19;
        case CS_KEYFRAMED_RAGDOLL_LAYER:
          v15 = m_pPointer->mCollisionFilterInfo.p[v3];
          v12 = (32 * ((v15 >> 5) & 0x1F | (32 * ((this->mCollisionSystem << 6) | (v15 >> 10) & 0x1F)))) | 7;
          goto LABEL_12;
        case CS_KEYFRAMED_RAGDOLL_LAYER_2:
          v14 = m_pPointer->mCollisionFilterInfo.p[v3];
          v12 = (32 * ((v14 >> 5) & 0x1F | (32 * ((this->mCollisionSystem << 6) | (v14 >> 10) & 0x1F)))) | 8;
          goto LABEL_12;
        case CS_KEYFRAMED_NO_COLLISION:
          v11 = m_pPointer->mCollisionFilterInfo.p[v3];
          v12 = (32 * ((v11 >> 5) & 0x1F | (32 * ((this->mCollisionSystem << 6) | (v11 >> 10) & 0x1F)))) | 0x15;
LABEL_12:
          if ( (unsigned __int8)(v9->m_motion.m_type.m_storage - 4) <= 1u
            && v9->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo == v12 )
          {
            break;
          }
          v13 = MOTION_KEYFRAMED;
LABEL_22:
          hkpRigidBody::setMotionType(v9, v13, HK_ENTITY_ACTIVATION_DO_ACTIVATE, HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK);
          m_world = v9->m_world;
          v9->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v12;
          if ( m_world )
            hkpWorld::updateCollisionFilterOnEntity(
              m_world,
              v9,
              HK_UPDATE_FILTER_ON_ENTITY_FULL_CHECK,
              HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
          break;
      }
LABEL_24:
      v3 = (unsigned int)(v3 + 1);
      if ( (int)v3 >= this->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size )
        return;
    }
    v17 = m_pPointer->mCollisionFilterInfo.p[v3];
    v12 = (32 * ((v17 >> 5) & 0x1F | (32 * ((this->mCollisionSystem << 6) | (v17 >> 10) & 0x1F)))) | 0x15;
LABEL_19:
    if ( (unsigned __int8)(v9->m_motion.m_type.m_storage - 4) > 1u
      && v9->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo == v12 )
    {
      goto LABEL_24;
    }
    v13 = MOTION_DYNAMIC;
    goto LABEL_22;
  }
}

// File Line: 1123
// RVA: 0xB26D0
void __fastcall UFG::Ragdoll::SetUserData(UFG::Ragdoll *this, UFG::SimComponent *component)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_simComponent; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  hkaRagdollInstance *mRagdollInstance; // rdx
  int v9; // r9d
  __int64 v10; // r8
  __int64 v11; // rcx
  hkpRigidBody *v12; // rcx
  UFG::HavokUserData *p_mUserData; // rax

  p_simComponent = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    mPrev = p_simComponent->mPrev;
    mNext = this->mUserData.simComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_simComponent->mPrev = p_simComponent;
    this->mUserData.simComponent.mNext = &this->mUserData.simComponent;
  }
  this->mUserData.simComponent.m_pPointer = component;
  if ( component )
  {
    v7 = component->m_SafePointerList.mNode.mPrev;
    v7->mNext = p_simComponent;
    p_simComponent->mPrev = v7;
    this->mUserData.simComponent.mNext = &component->m_SafePointerList.mNode;
    component->m_SafePointerList.mNode.mPrev = p_simComponent;
  }
  mRagdollInstance = this->mRagdollInstance;
  v9 = 0;
  if ( mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v10];
      if ( (int)v11 >= 0 )
        v12 = mRagdollInstance->m_rigidBodies.m_data[v11];
      else
        v12 = 0i64;
      if ( component )
        p_mUserData = &this->mUserData;
      else
        p_mUserData = 0i64;
      v12->m_userData = (unsigned __int64)p_mUserData;
      mRagdollInstance = this->mRagdollInstance;
      ++v9;
      ++v10;
    }
    while ( v9 < mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size );
  }
}

// File Line: 1136
// RVA: 0xB1280
void __fastcall UFG::Ragdoll::SetFriction(UFG::Ragdoll *this, float mu)
{
  hkaRagdollInstance *mRagdollInstance; // rdx
  int v3; // edi
  __int64 v5; // rbx
  __int64 v6; // rcx
  hkpRigidBody *v7; // rcx

  mRagdollInstance = this->mRagdollInstance;
  v3 = 0;
  if ( mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v5];
      if ( (int)v6 >= 0 )
        v7 = mRagdollInstance->m_rigidBodies.m_data[v6];
      else
        v7 = 0i64;
      hkpRigidBody::setFriction(v7, mu);
      mRagdollInstance = this->mRagdollInstance;
      ++v3;
      ++v5;
    }
    while ( v3 < mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size );
  }
}

// File Line: 1148
// RVA: 0xB03F0
void __fastcall UFG::Ragdoll::ScaleMass(UFG::Ragdoll *this, float mu)
{
  hkaRagdollInstance *mRagdollInstance; // rdx
  int v4; // esi
  __int64 v5; // rdi
  __int64 v6; // rcx
  hkpRigidBody *v7; // rbx
  float Mass; // xmm0_4

  if ( mu >= 0.001 )
  {
    mRagdollInstance = this->mRagdollInstance;
    v4 = 0;
    if ( mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        v6 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v5];
        if ( (int)v6 >= 0 )
          v7 = mRagdollInstance->m_rigidBodies.m_data[v6];
        else
          v7 = 0i64;
        Mass = hkpMotion::getMass(&v7->m_motion);
        hkpRigidBody::setMass(v7, Mass * mu);
        mRagdollInstance = this->mRagdollInstance;
        ++v4;
        ++v5;
      }
      while ( v4 < mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size );
    }
  }
}

// File Line: 1170
// RVA: 0xAB150
void __fastcall UFG::Ragdoll::GetPelvisTransformWS(UFG::Ragdoll *this, UFG::qMatrix44 *transformWS)
{
  hkaRagdollInstance *mRagdollInstance; // r8
  __int64 v3; // rcx
  hkpRigidBody *v4; // rax
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm3
  hkVector4f v7; // xmm0
  hkTransformf v8; // [rsp+20h] [rbp-48h] BYREF

  mRagdollInstance = this->mRagdollInstance;
  v3 = *mRagdollInstance->m_boneToRigidBodyMap.m_data;
  if ( (int)v3 >= 0 )
    v4 = mRagdollInstance->m_rigidBodies.m_data[v3];
  else
    v4 = 0i64;
  v5.m_quad = (__m128)v4->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v6.m_quad = (__m128)v4->m_motion.m_motionState.m_transform.m_translation;
  v7.m_quad = (__m128)v4->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  v8.m_rotation.m_col1 = v4->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v8.m_rotation.m_col2 = (hkVector4f)v5.m_quad;
  v8.m_rotation.m_col0 = (hkVector4f)v7.m_quad;
  v8.m_translation = (hkVector4f)v6.m_quad;
  hkTransformf::get4x4ColumnMajor(&v8, &transformWS->v0.x);
}

// File Line: 1189
// RVA: 0xA7850
void __fastcall UFG::Ragdoll::EnableConstraints(UFG::Ragdoll *this)
{
  int v1; // ebx
  hkaRagdollInstance *mRagdollInstance; // r14
  __int64 v4; // rdi
  hkpConstraintInstance *v5; // rcx
  hkaRagdollInstance *v6; // rcx
  hkpEaseConstraintsAction *mEaseConstraintsAction; // rcx
  hkpWorld *World; // rax

  v1 = 0;
  mRagdollInstance = this->mRagdollInstance;
  if ( this->mRagdollData.m_pPointer->mLastCoreRagdollConstraint >= 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = mRagdollInstance->m_constraints.m_data[v4];
      if ( v5 )
        hkpConstraintInstance::enable(v5);
      ++v1;
      ++v4;
    }
    while ( v1 <= this->mRagdollData.m_pPointer->mLastCoreRagdollConstraint );
  }
  v6 = this->mRagdollInstance;
  if ( v6 && hkaRagdollInstance::getWorld(v6) )
  {
    mEaseConstraintsAction = this->mEaseConstraintsAction;
    if ( !mEaseConstraintsAction->m_world )
    {
      hkpEaseConstraintsAction::loosenConstraints(mEaseConstraintsAction);
      hkpEaseConstraintsAction::restoreConstraints(this->mEaseConstraintsAction, 0.5);
      World = hkaRagdollInstance::getWorld(this->mRagdollInstance);
      hkpWorld::addAction(World, this->mEaseConstraintsAction);
    }
  }
}

// File Line: 1217
// RVA: 0xA7440
void __fastcall UFG::Ragdoll::DisableConstraints(UFG::Ragdoll *this)
{
  hkaRagdollInstance *mRagdollInstance; // r14
  int v2; // ebx
  __int64 v4; // rdi
  hkpConstraintInstance *v5; // rcx

  mRagdollInstance = this->mRagdollInstance;
  v2 = 0;
  if ( this->mRagdollData.m_pPointer->mLastCoreRagdollConstraint >= 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = mRagdollInstance->m_constraints.m_data[v4];
      if ( v5 )
        hkpConstraintInstance::disable(v5);
      ++v2;
      ++v4;
    }
    while ( v2 <= this->mRagdollData.m_pPointer->mLastCoreRagdollConstraint );
  }
}

// File Line: 1235
// RVA: 0xB1640
void __fastcall UFG::Ragdoll::SetMotorMaxForce(UFG::Ragdoll *this, float force)
{
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  char *v5; // rdx
  int v6; // r14d
  hkaRagdollInstance *mRagdollInstance; // rdx
  __int64 v8; // rsi
  int v9; // ecx
  hkpConstraintInstance *v10; // rax
  hkpRagdollConstraintData *m_data; // rdi
  int v12; // eax
  hkpConstraintMotor *PlaneMotor; // rax
  hkpConstraintMotor *v14; // rbx
  int v15; // edx
  __int64 v16; // rcx
  int v17; // r9d
  _QWORD *v18; // r8
  hkpConstraintMotor *ConeMotor; // rax
  hkpConstraintMotor *v20; // rbx
  int v21; // edx
  __int64 v22; // rcx
  int v23; // r9d
  _QWORD *v24; // r8
  hkpConstraintMotor *TwistMotor; // rax
  hkpConstraintMotor *v26; // rbx
  int v27; // r9d
  __int64 v28; // rdx
  int v29; // r8d
  bool v30; // zf
  int v31; // edx
  __int64 v32; // rcx
  int v33; // r9d
  __int64 v34; // rdx
  char *v35; // rdi
  int v36; // ecx
  int v37; // ebx
  hkLifoAllocator *v38; // rax
  signed int v39; // ebx
  int v40; // r8d
  _QWORD *array; // [rsp+28h] [rbp-38h] BYREF
  int v42; // [rsp+30h] [rbp-30h]
  int v43; // [rsp+34h] [rbp-2Ch]
  void *p; // [rsp+38h] [rbp-28h]
  int v45; // [rsp+40h] [rbp-20h]

  array = 0i64;
  v42 = 0;
  v43 = 0x80000000;
  v45 = 26;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v5 = m_cur + 256;
  if ( Value->m_slabSize < 256 || v5 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, 256);
  else
    Value->m_cur = v5;
  array = m_cur;
  v43 = -2147483622;
  p = m_cur;
  v6 = 1;
  mRagdollInstance = this->mRagdollInstance;
  if ( mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 1 )
  {
    v8 = 1i64;
    while ( 1 )
    {
      v9 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v8] - 1;
      if ( v9 >= 0 )
        v10 = mRagdollInstance->m_constraints.m_data[v9];
      else
        v10 = 0i64;
      m_data = (hkpRagdollConstraintData *)v10->m_data;
      v12 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
      if ( v12 == 2 )
      {
        v26 = (hkpConstraintMotor *)m_data->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
        if ( !v26 )
          goto LABEL_46;
        v31 = 0;
        v32 = 0i64;
        v29 = v42;
        if ( v42 <= 0 )
        {
LABEL_37:
          if ( v29 == (v43 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
            v29 = v42;
          }
          array[v29] = v26;
          v29 = ++v42;
          goto LABEL_47;
        }
        while ( (hkpConstraintMotor *)array[v32] != v26 )
        {
          ++v31;
          if ( ++v32 >= v42 )
            goto LABEL_37;
        }
        v30 = v31 == -1;
      }
      else
      {
        if ( v12 != 7 )
          goto LABEL_46;
        PlaneMotor = hkpRagdollConstraintData::getPlaneMotor(m_data);
        v14 = PlaneMotor;
        if ( PlaneMotor )
        {
          v15 = 0;
          v16 = 0i64;
          v17 = v42;
          v18 = array;
          if ( v42 <= 0 )
            goto LABEL_18;
          while ( (hkpConstraintMotor *)array[v16] != PlaneMotor )
          {
            ++v15;
            if ( ++v16 >= v42 )
              goto LABEL_18;
          }
          if ( v15 == -1 )
          {
LABEL_18:
            if ( v42 == (v43 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
              v17 = v42;
              v18 = array;
            }
            v18[v17] = v14;
            ++v42;
          }
        }
        ConeMotor = hkpRagdollConstraintData::getConeMotor(m_data);
        v20 = ConeMotor;
        if ( ConeMotor )
        {
          v21 = 0;
          v22 = 0i64;
          v23 = v42;
          v24 = array;
          if ( v42 <= 0 )
            goto LABEL_27;
          while ( (hkpConstraintMotor *)array[v22] != ConeMotor )
          {
            ++v21;
            if ( ++v22 >= v42 )
              goto LABEL_27;
          }
          if ( v21 == -1 )
          {
LABEL_27:
            if ( v42 == (v43 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 8);
              v23 = v42;
              v24 = array;
            }
            v24[v23] = v20;
            ++v42;
          }
        }
        TwistMotor = hkpRagdollConstraintData::getTwistMotor(m_data);
        v26 = TwistMotor;
        if ( !TwistMotor )
        {
LABEL_46:
          v29 = v42;
          goto LABEL_47;
        }
        v27 = 0;
        v28 = 0i64;
        v29 = v42;
        if ( v42 <= 0 )
          goto LABEL_37;
        while ( (hkpConstraintMotor *)array[v28] != TwistMotor )
        {
          ++v27;
          if ( ++v28 >= v42 )
            goto LABEL_37;
        }
        v30 = v27 == -1;
      }
      if ( v30 )
        goto LABEL_37;
LABEL_47:
      ++v6;
      ++v8;
      mRagdollInstance = this->mRagdollInstance;
      if ( v6 >= mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size )
        goto LABEL_50;
    }
  }
  v29 = v42;
LABEL_50:
  v33 = 0;
  if ( v29 > 0 )
  {
    v34 = 0i64;
    do
    {
      *(float *)(array[v34] + 28i64) = force;
      ++v33;
      ++v34;
    }
    while ( v33 < v42 );
  }
  v35 = (char *)p;
  v36 = v42;
  if ( p == array )
    v36 = 0;
  v42 = v36;
  v37 = v45;
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (8 * v37 + 127) & 0xFFFFFF80;
  v40 = (v39 + 15) & 0xFFFFFFF0;
  if ( v39 > v38->m_slabSize || &v35[v40] != v38->m_cur || v38->m_firstNonLifoEnd == v35 )
    hkLifoAllocator::slowBlockFree(v38, v35, v40);
  else
    v38->m_cur = v35;
  v42 = 0;
  if ( v43 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v43);
}

// File Line: 1291
// RVA: 0xAA9D0
float __fastcall UFG::Ragdoll::GetMotorMaxForce(UFG::Ragdoll *this)
{
  hkaRagdollInstance *mRagdollInstance; // rdx
  int v2; // edi
  __int64 i; // rsi
  int v5; // ecx
  hkpConstraintInstance *v6; // rbx
  hkpRagdollConstraintData *m_data; // rbx
  int v8; // eax
  hkpConstraintMotor *PlaneMotor; // rax

  mRagdollInstance = this->mRagdollInstance;
  v2 = 1;
  if ( mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size <= 1 )
    return 0.0;
  for ( i = 1i64; ; ++i )
  {
    v5 = mRagdollInstance->m_boneToRigidBodyMap.m_data[i] - 1;
    v6 = v5 >= 0 ? mRagdollInstance->m_constraints.m_data[v5] : 0i64;
    m_data = (hkpRagdollConstraintData *)v6->m_data;
    v8 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
    if ( v8 != 2 )
      break;
    PlaneMotor = (hkpConstraintMotor *)m_data->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
LABEL_12:
    if ( PlaneMotor )
      return *((float *)&PlaneMotor[1].vfptr + 1);
LABEL_13:
    mRagdollInstance = this->mRagdollInstance;
    if ( ++v2 >= mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size )
      return 0.0;
  }
  if ( v8 != 7 )
    goto LABEL_13;
  PlaneMotor = hkpRagdollConstraintData::getPlaneMotor(m_data);
  if ( !PlaneMotor )
  {
    PlaneMotor = hkpRagdollConstraintData::getConeMotor(m_data);
    if ( !PlaneMotor )
    {
      PlaneMotor = hkpRagdollConstraintData::getTwistMotor(m_data);
      goto LABEL_12;
    }
  }
  return *((float *)&PlaneMotor[1].vfptr + 1);
}

// File Line: 1326
// RVA: 0xB19E0
void __fastcall UFG::Ragdoll::SetMotorMaxForceAtJoint(UFG::Ragdoll *this, float force, int skeletonBoneID)
{
  hkaRagdollInstance *mRagdollInstance; // r10
  hkpConstraintInstance *v4; // rbx
  hkaSkeletonMapper *highResToRagdollMapper; // rcx
  __int64 v6; // rdx
  __int64 m_size; // r9
  hkaSkeletonMapperData::SimpleMapping *i; // rcx
  int v9; // edx
  hkpRagdollConstraintData *m_data; // rbx
  int v11; // eax
  hkpConstraintMotor *PlaneMotor; // rax
  hkpConstraintMotor *ConeMotor; // rax
  hkpConstraintMotor *TwistMotor; // rax

  mRagdollInstance = this->mRagdollInstance;
  if ( mRagdollInstance )
  {
    v4 = 0i64;
    highResToRagdollMapper = this->mRagdollData.m_pPointer->highResToRagdollMapper;
    v6 = 0i64;
    m_size = highResToRagdollMapper->m_mapping.m_simpleMappings.m_size;
    if ( m_size > 0 )
    {
      for ( i = highResToRagdollMapper->m_mapping.m_simpleMappings.m_data; i->m_boneA != skeletonBoneID; ++i )
      {
        if ( ++v6 >= m_size )
          return;
      }
      if ( i->m_boneB != -1 )
      {
        v9 = mRagdollInstance->m_boneToRigidBodyMap.m_data[i->m_boneB] - 1;
        if ( v9 >= 0 )
          v4 = mRagdollInstance->m_constraints.m_data[v9];
        m_data = (hkpRagdollConstraintData *)v4->m_data;
        v11 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
        if ( v11 == 2 )
        {
          TwistMotor = (hkpConstraintMotor *)m_data->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
        }
        else
        {
          if ( v11 != 7 )
            return;
          PlaneMotor = hkpRagdollConstraintData::getPlaneMotor(m_data);
          if ( PlaneMotor )
            *((float *)&PlaneMotor[1].vfptr + 1) = force;
          ConeMotor = hkpRagdollConstraintData::getConeMotor(m_data);
          if ( ConeMotor )
            *((float *)&ConeMotor[1].vfptr + 1) = force;
          TwistMotor = hkpRagdollConstraintData::getTwistMotor(m_data);
        }
        if ( TwistMotor )
          *((float *)&TwistMotor[1].vfptr + 1) = force;
      }
    }
  }
}

// File Line: 1376
// RVA: 0xAAAA0
float __fastcall UFG::Ragdoll::GetMotorMaxForceAtJoint(UFG::Ragdoll *this, int boneIndex)
{
  hkaRagdollInstance *mRagdollInstance; // r8
  int v3; // edx
  hkpConstraintInstance *v4; // rbx
  hkpRagdollConstraintData *m_data; // rbx
  int v6; // eax
  hkpConstraintMotor *PlaneMotor; // rax
  hkpConstraintMotor *TwistMotor; // rax

  mRagdollInstance = this->mRagdollInstance;
  v3 = mRagdollInstance->m_boneToRigidBodyMap.m_data[boneIndex] - 1;
  if ( v3 >= 0 )
    v4 = mRagdollInstance->m_constraints.m_data[v3];
  else
    v4 = 0i64;
  m_data = (hkpRagdollConstraintData *)v4->m_data;
  v6 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))m_data->vfptr[1].__first_virtual_table_function__)(m_data);
  if ( v6 == 2 )
  {
    PlaneMotor = (hkpConstraintMotor *)m_data->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
    if ( PlaneMotor )
      return *((float *)&PlaneMotor[1].vfptr + 1);
  }
  else if ( v6 == 7 )
  {
    PlaneMotor = hkpRagdollConstraintData::getPlaneMotor(m_data);
    if ( !PlaneMotor )
    {
      PlaneMotor = hkpRagdollConstraintData::getConeMotor(m_data);
      if ( !PlaneMotor )
      {
        TwistMotor = hkpRagdollConstraintData::getTwistMotor(m_data);
        if ( TwistMotor )
          return *((float *)&TwistMotor[1].vfptr + 1);
        return 0.0;
      }
    }
    return *((float *)&PlaneMotor[1].vfptr + 1);
  }
  return 0.0;
}

// File Line: 1408
// RVA: 0xB1300
void __fastcall UFG::Ragdoll::SetLimitStiffness(UFG::Ragdoll *this, float tau)
{
  hkaRagdollInstance *mRagdollInstance; // rdx
  int v3; // edi
  __int64 v5; // rsi
  int v6; // ecx
  hkpConstraintInstance *v7; // rbx
  float *m_data; // rbx
  int v9; // eax

  mRagdollInstance = this->mRagdollInstance;
  v3 = 1;
  if ( mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 1 )
  {
    v5 = 1i64;
    do
    {
      v6 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v5] - 1;
      if ( v6 >= 0 )
        v7 = mRagdollInstance->m_constraints.m_data[v6];
      else
        v7 = 0i64;
      m_data = (float *)v7->m_data;
      v9 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)m_data + 24i64))(m_data);
      if ( v9 == 2 )
      {
        m_data[65] = tau;
      }
      else if ( v9 == 7 )
      {
        m_data[80] = tau;
        m_data[88] = tau;
        m_data[96] = tau;
      }
      mRagdollInstance = this->mRagdollInstance;
      ++v3;
      ++v5;
    }
    while ( v3 < mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size );
  }
}

// File Line: 1440
// RVA: 0xAA8E0
float __fastcall UFG::Ragdoll::GetLimitStiffness(UFG::Ragdoll *this)
{
  hkaRagdollInstance *mRagdollInstance; // rdx
  int v2; // ebx
  __int64 i; // rdi
  int v5; // ecx
  hkpConstraintInstance *v6; // rax
  float *m_data; // rsi
  int v8; // eax

  mRagdollInstance = this->mRagdollInstance;
  v2 = 1;
  if ( mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size <= 1 )
    return 0.0;
  for ( i = 1i64; ; ++i )
  {
    v5 = mRagdollInstance->m_boneToRigidBodyMap.m_data[i] - 1;
    v6 = v5 >= 0 ? mRagdollInstance->m_constraints.m_data[v5] : 0i64;
    m_data = (float *)v6->m_data;
    v8 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)m_data + 24i64))(m_data);
    if ( v8 == 2 )
      break;
    if ( v8 == 7 )
      return m_data[80];
    mRagdollInstance = this->mRagdollInstance;
    if ( ++v2 >= mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size )
      return 0.0;
  }
  return m_data[65];
}

// File Line: 1470
// RVA: 0xA5F40
void __fastcall UFG::Ragdoll::CreateRagdollPenetrationUtil(UFG::Ragdoll *this, hkpWorld *world)
{
  __int64 v4; // rbx
  char v5; // dl
  char v6; // cl
  _QWORD **Value; // rax
  hkpAabbPhantom *v8; // rax
  hkpAabbPhantom *v9; // rax
  char v10; // al
  char v11; // dl
  char v12; // cl
  _QWORD **v13; // rax
  __int64 v14; // rax
  char v15; // al
  UFG::RagdollPenetrationRaycastInterface *mRagdollRaycastInterface; // rax
  char v17; // dl
  char v18; // cl
  _QWORD **v19; // rax
  DetectRagdollPenetration *v20; // rax
  DetectRagdollPenetration *v21; // rax
  char v22; // al
  DetectRagdollPenetration::Setup setup; // [rsp+28h] [rbp-40h] BYREF
  hkAabb aabb; // [rsp+40h] [rbp-28h] BYREF

  aabb.m_min = (hkVector4f)_xmm;
  aabb.m_max = (hkVector4f)_xmm;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v5) = 3;
  *(_QWORD *)(v4 + 8i64 * v5 + 16) = "hkpAabbPhantom";
  *(_QWORD *)(v4 + 8i64 * v5 + 48) = 0i64;
  v6 = *(_BYTE *)(v4 + 81);
  if ( v5 > v6 )
    v6 = v5;
  *(_BYTE *)(v4 + 81) = v6;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 304i64);
  if ( v8 )
    hkpAabbPhantom::hkpAabbPhantom(v8, &aabb, 0xCu);
  else
    v9 = 0i64;
  this->mPhantom = v9;
  v10 = *(_BYTE *)(v4 + 80);
  if ( v10 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v10 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  v11 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v11) = 3;
  *(_QWORD *)(v4 + 8i64 * v11 + 16) = "RagdollPenetrationRaycastInterface";
  *(_QWORD *)(v4 + 8i64 * v11 + 48) = 0i64;
  v12 = *(_BYTE *)(v4 + 81);
  if ( v11 > v12 )
    v12 = v11;
  *(_BYTE *)(v4 + 81) = v12;
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 32i64);
  if ( v14 )
  {
    *(_QWORD *)v14 = &hkBaseObject::`vftable;
    *(_QWORD *)v14 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v14 + 8) = 0x1FFFF;
    *(_QWORD *)(v14 + 16) = &hkaRagdollRaycastInterface::`vftable;
    *(_QWORD *)v14 = &UFG::RagdollPenetrationRaycastInterface::`vftable{for `hkReferencedObject};
    *(_QWORD *)(v14 + 16) = &UFG::RagdollPenetrationRaycastInterface::`vftable{for `hkaRagdollRaycastInterface};
    *(_QWORD *)(v14 + 24) = world;
  }
  else
  {
    v14 = 0i64;
  }
  this->mRagdollRaycastInterface = (UFG::RagdollPenetrationRaycastInterface *)v14;
  v15 = *(_BYTE *)(v4 + 80);
  if ( v15 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v15 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  setup.m_ragdollSkeleton = this->mRagdollInstance->m_skeleton.m_pntr;
  mRagdollRaycastInterface = this->mRagdollRaycastInterface;
  if ( mRagdollRaycastInterface )
    setup.m_raycastInterface = &mRagdollRaycastInterface->hkaRagdollRaycastInterface;
  else
    setup.m_raycastInterface = 0i64;
  setup.m_ragdollPhantom = this->mPhantom;
  v17 = ++*(_BYTE *)(v4 + 80);
  *(_DWORD *)(v4 + 4i64 * v17) = 3;
  *(_QWORD *)(v4 + 8i64 * v17 + 16) = "DetectRagdollPenetration";
  *(_QWORD *)(v4 + 8i64 * v17 + 48) = 0i64;
  v18 = *(_BYTE *)(v4 + 81);
  if ( v17 > v18 )
    v18 = v17;
  *(_BYTE *)(v4 + 81) = v18;
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (DetectRagdollPenetration *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(v19[11], 72i64);
  if ( v20 )
    DetectRagdollPenetration::DetectRagdollPenetration(v20, &setup);
  else
    v21 = 0i64;
  this->mDetectRagdollPenetration = v21;
  v22 = *(_BYTE *)(v4 + 80);
  if ( v22 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v22 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  this->m_framesSinceInterpenetration = 0;
}4 = 3;
    *(_QWORD *)(v4

// File Line: 1499
// RVA: 0xB5440
void __fastcall UFG::Ragdoll::UpdateTotalInertia(UFG::Ragdoll *this)
{
  hkaRagdollInstance *mRagdollInstance; // r15
  __int64 v3; // rsi
  __int64 m_size; // r14
  hkpRigidBody *v5; // rdi
  float v6; // xmm7_4
  float v7; // xmm8_4
  hkVector4f v8; // xmm9
  __int128 v9; // xmm10
  hkVector4f v10; // xmm11
  hkVector4f v11; // xmm12
  hkVector4f v12; // xmm13
  hkVector4f v13; // xmm14
  hkVector4f v14; // xmm15
  hkVector4f v15; // xmm0
  int v16; // ecx
  __int64 v17; // rcx
  bool v18; // zf
  hkMassElement *v19; // rcx
  hkArray<hkMassElement,hkContainerHeapAllocator> array; // [rsp+28h] [rbp-A0h] BYREF
  _BYTE v21[24]; // [rsp+40h] [rbp-88h]
  _BYTE v22[24]; // [rsp+58h] [rbp-70h] BYREF
  __int128 v23[13]; // [rsp+70h] [rbp-58h] BYREF
  hkResult result[2]; // [rsp+148h] [rbp+80h] BYREF
  hkMassElement *v25; // [rsp+150h] [rbp+88h]

  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  mRagdollInstance = this->mRagdollInstance;
  v3 = 0i64;
  m_size = mRagdollInstance->m_rigidBodies.m_size;
  if ( m_size > 0 )
  {
    do
    {
      v5 = mRagdollInstance->m_rigidBodies.m_data[v3];
      v23[0] = 0i64;
      *(_OWORD *)&v21[8] = 0i64;
      memset(v22, 0, sizeof(v22));
      *(_DWORD *)&v21[20] = hkpMotion::getMass(&v5->m_motion);
      *(hkVector4f *)&v22[8] = v5->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v5->m_motion.hkpEntity::vfptr[3].__first_virtual_table_function__)(
        &v5->m_motion,
        v23);
      v6 = *(float *)&v21[16];
      v7 = *(float *)&v21[20];
      v8.m_quad = *(__m128 *)&v22[8];
      v9 = v23[0];
      v10.m_quad = *(__m128 *)&v21[8];
      v11.m_quad = *(__m128 *)v22;
      v12.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col0;
      v13.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col1;
      v14.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col2;
      v15.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_translation;
      *(hkVector4f *)v21 = (hkVector4f)v15.m_quad;
      v16 = array.m_size;
      if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 144);
        v16 = array.m_size;
        v15.m_quad = *(__m128 *)v21;
      }
      v17 = v16;
      v18 = &array.m_data[v17] == 0;
      v19 = &array.m_data[v17];
      *(_QWORD *)&result[0].m_enum = v19;
      v25 = v19;
      if ( !v18 )
      {
        v19->m_properties.m_volume = v6;
        v19->m_properties.m_mass = v7;
        v19->m_properties.m_centerOfMass = (hkVector4f)v8.m_quad;
        v19->m_properties.m_inertiaTensor.m_col0 = (hkVector4f)v9;
        v19->m_properties.m_inertiaTensor.m_col1 = (hkVector4f)v10.m_quad;
        v19->m_properties.m_inertiaTensor.m_col2 = (hkVector4f)v11.m_quad;
        v19->m_transform.m_rotation.m_col0 = (hkVector4f)v12.m_quad;
        v19->m_transform.m_rotation.m_col1 = (hkVector4f)v13.m_quad;
        v19->m_transform.m_rotation.m_col2 = (hkVector4f)v14.m_quad;
        v19->m_transform.m_translation = (hkVector4f)v15.m_quad;
      }
      ++array.m_size;
      ++v3;
    }
    while ( v3 < m_size );
  }
  hkInertiaTensorComputer::combineMassProperties(result, &array, &this->mMassProperties);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      144 * (array.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 1527
// RVA: 0xA66E0
void __fastcall UFG::Ragdoll::DampMotionOfExtremities(UFG::Ragdoll *this, float deltaT)
{
  __m128 v2; // xmm6
  hkaSkeleton *m_pntr; // r13
  UFG::RagdollData *m_pPointer; // rax
  float v6; // xmm7_4
  __int64 size; // r15
  __int64 v8; // rdi
  hkaRagdollInstance *mRagdollInstance; // rdx
  __int64 v10; // r8
  __int64 v11; // rbx
  __int64 v12; // rcx
  hkpEntity *v13; // rbp
  hkaRagdollInstance *v14; // rdx
  __int64 v15; // r8
  hkpRigidBody *v16; // r14
  __m128 m_quad; // xmm1
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // [rsp+20h] [rbp-78h] BYREF
  __m128 v23; // [rsp+30h] [rbp-68h] BYREF
  hkBool result; // [rsp+A8h] [rbp+10h] BYREF

  m_pntr = this->mRagdollInstance->m_skeleton.m_pntr;
  m_pPointer = this->mRagdollData.m_pPointer;
  v6 = UFG::gExtremityMotionDecayRate * deltaT;
  if ( (float)(UFG::gExtremityMotionDecayRate * deltaT) > 1.0 )
    v6 = *(float *)&FLOAT_1_0;
  size = m_pPointer->mExtremityBoneIndices.size;
  v8 = 0i64;
  if ( m_pPointer->mExtremityBoneIndices.size )
  {
    do
    {
      mRagdollInstance = this->mRagdollInstance;
      v10 = this->mRagdollData.m_pPointer->mExtremityBoneIndices.p[v8];
      v11 = v10;
      v12 = mRagdollInstance->m_boneToRigidBodyMap.m_data[v10];
      if ( (int)v12 >= 0 )
        v13 = mRagdollInstance->m_rigidBodies.m_data[v12];
      else
        v13 = 0i64;
      if ( UFG::Ragdoll::GetMotorMaxForceAtJoint(this, v10) < 0.1 && hkpEntity::isActive(v13, &result)->m_bool )
      {
        v14 = this->mRagdollInstance;
        v15 = v14->m_boneToRigidBodyMap.m_data[m_pntr->m_parentIndices.m_data[v11]];
        if ( (int)v15 >= 0 )
          v16 = v14->m_rigidBodies.m_data[v15];
        else
          v16 = 0i64;
        m_quad = v16->m_motion.m_linearVelocity.m_quad;
        v2.m128_f32[0] = v6;
        v18 = _mm_shuffle_ps(v2, v2, 0);
        v19 = _mm_sub_ps(v13->m_motion.m_linearVelocity.m_quad, m_quad);
        v22 = _mm_add_ps(_mm_sub_ps(v19, _mm_mul_ps(v18, v19)), m_quad);
        hkpEntity::activate(v13);
        v13->m_motion.vfptr[9].__vecDelDtor(&v13->m_motion, (unsigned int)&v22);
        v20 = v16->m_motion.m_angularVelocity.m_quad;
        v21 = _mm_sub_ps(v13->m_motion.m_angularVelocity.m_quad, v20);
        v2 = _mm_mul_ps(v18, v21);
        v23 = _mm_add_ps(_mm_sub_ps(v21, v2), v20);
        hkpEntity::activate(v13);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v13->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v13->m_motion,
          &v23);
      }
      ++v8;
    }
    while ( v8 < size );
  }
}

