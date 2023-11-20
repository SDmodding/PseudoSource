// File Line: 79
// RVA: 0xB6DF0
hkBool *__fastcall UFG::RagdollPenetrationRaycastInterface::castRay(UFG::RagdollPenetrationRaycastInterface *this, hkBool *result, hkpAabbPhantom *phantomIn, hkVector4f *fromWS, hkVector4f *toWS, hkVector4f *hitPointWS)
{
  hkBool *v6; // rbx
  hkpRayHitCollector collector; // [rsp+18h] [rbp-71h]
  hkVector4f v9; // [rsp+28h] [rbp-61h]
  unsigned int v10; // [rsp+38h] [rbp-51h]
  int v11; // [rsp+3Ch] [rbp-4Dh]
  int v12; // [rsp+48h] [rbp-41h]
  int v13; // [rsp+68h] [rbp-21h]
  __int64 v14; // [rsp+78h] [rbp-11h]
  hkpWorldRayCastInput input; // [rsp+88h] [rbp-1h]
  __int64 v16; // [rsp+B8h] [rbp+2Fh]
  hkVector4f *v17; // [rsp+F8h] [rbp+6Fh]

  v16 = -2i64;
  v6 = result;
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
    v6->m_bool = 1;
  }
  else
  {
    v6->m_bool = 0;
  }
  return v6;
}

// File Line: 112
// RVA: 0xB1AD0
void __fastcall UFG::Ragdoll::SetMotorState(UFG::Ragdoll *this, int b, bool onOff)
{
  bool v3; // si
  hkaRagdollInstance *v4; // r8
  int v5; // edx
  hkpConstraintInstance *v6; // rdi
  hkpLimitedHingeConstraintData *v7; // rbx
  int v8; // eax

  v3 = onOff;
  v4 = this->mRagdollInstance;
  v5 = v4->m_boneToRigidBodyMap.m_data[b] - 1;
  if ( v5 >= 0 )
  {
    v6 = v4->m_constraints.m_data[v5];
    if ( v6 )
    {
      v7 = (hkpLimitedHingeConstraintData *)v6->m_data;
      if ( v7 )
      {
        v8 = ((__int64 (__fastcall *)(hkpConstraintData *))v7->vfptr[1].__first_virtual_table_function__)(v6->m_data);
        if ( v8 == 2 )
        {
          hkpLimitedHingeConstraintData::setMotorEnabled(v7, v6->m_internal->m_runtime, (hkBool)v3);
        }
        else if ( v8 == 7 )
        {
          hkpRagdollConstraintData::setMotorsEnabled(
            (hkpRagdollConstraintData *)v7,
            v6->m_internal->m_runtime,
            (hkBool)v3);
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
  int v5; // er15
  hkpRigidBody *v6; // r14
  UFG::Ragdoll *v7; // rbp
  __int64 v8; // rdi
  DetectRagdollPenetration::BonePenetration *v9; // rcx
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  float v12; // xmm8_4
  __m128 v13; // xmm6
  __m128 v14; // xmm10
  __m128 v15; // xmm1
  __m128 v16; // xmm7
  __m128 v17; // xmm7
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  float v22; // xmm9_4
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  float v26; // xmm7_4
  __m128 v27; // xmm6
  __m128 v28; // [rsp+20h] [rbp-C8h]
  __m128 v29; // [rsp+30h] [rbp-B8h]

  v4 = 0;
  v5 = boneId;
  v6 = rb;
  v7 = this;
  if ( this->mPenetratedBones.m_penetrations.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v7->mPenetratedBones.m_penetrations.m_data;
      if ( v9[v8].m_boneBeginIndex == v5 )
      {
        v10 = v9[v8].m_penetrationPoint.m_quad;
        v11 = v6->m_motion.m_angularVelocity.m_quad;
        v12 = v7->m_penetrationErrorVelocity;
        v13 = (__m128)LODWORD(v7->m_penetrationImpulseMax);
        v28 = v10;
        v14 = v9[v8].m_penetrationNormal.m_quad;
        v15 = _mm_sub_ps(v10, v6->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v15));
        v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 201), v6->m_motion.m_linearVelocity.m_quad);
        v18 = _mm_mul_ps(v17, v17);
        v19 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                _mm_shuffle_ps(v18, v18, 170));
        v20 = _mm_rsqrt_ps(v19);
        v21 = _mm_mul_ps(*(__m128 *)_xmm, v20);
        LODWORD(v22) = (unsigned __int128)_mm_andnot_ps(
                                            _mm_cmpleps(v19, (__m128)0i64),
                                            _mm_mul_ps(
                                              _mm_mul_ps(
                                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v19), v20)),
                                                v21),
                                              v19));
        if ( v22 <= 0.00000011920929 )
        {
          v26 = 0.0;
        }
        else
        {
          v23 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                  _mm_shuffle_ps(v18, v18, 170));
          v24 = _mm_rsqrt_ps(v23);
          v25 = _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_andnot_ps(
                      _mm_cmpleps(v23, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                        _mm_mul_ps(*(__m128 *)_xmm, v24))),
                    v17),
                  v14);
          v21 = _mm_shuffle_ps(v25, v25, 0);
          v26 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 85)) + v21.m128_f32[0])
              + COERCE_FLOAT(_mm_shuffle_ps(v25, v25, 170));
        }
        v21.m128_f32[0] = hkpMotion::getMass((hkpMotion *)&v6->m_motion.vfptr) * (float)(v12 - (float)(v26 * v22));
        if ( v21.m128_f32[0] > v13.m128_f32[0] )
          v21 = v13;
        v27 = _mm_xor_ps(v13, (__m128)(unsigned int)_xmm[0]);
        if ( v21.m128_f32[0] < v27.m128_f32[0] )
          v21 = v27;
        v29 = _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v14);
        hkpEntity::activate((hkpEntity *)&v6->vfptr);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))v6->m_motion.vfptr[11].__first_virtual_table_function__)(
          &v6->m_motion,
          &v29,
          &v28);
      }
      ++v4;
      ++v8;
    }
    while ( v4 < v7->mPenetratedBones.m_penetrations.m_size );
  }
}

// File Line: 226
// RVA: 0xAB320
signed __int64 __fastcall UFG::Ragdoll::GetRigidBodyID(UFG::Ragdoll *this, int skeletonBoneID)
{
  __int64 v2; // r8
  hkaSkeletonMapper *v3; // rax
  __int64 v4; // r9
  hkaSkeletonMapperData::SimpleMapping *v5; // rax

  if ( !this->mRagdollInstance )
    return 0xFFFFFFFFi64;
  v2 = 0i64;
  v3 = this->mRagdollData.m_pPointer->highResToRagdollMapper;
  v4 = v3->m_mapping.m_simpleMappings.m_size;
  if ( v4 <= 0 )
    return 0xFFFFFFFFi64;
  v5 = v3->m_mapping.m_simpleMappings.m_data;
  while ( v5->m_boneA != skeletonBoneID )
  {
    ++v2;
    ++v5;
    if ( v2 >= v4 )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v5->m_boneB;
}

// File Line: 251
// RVA: 0xAB2B0
hkpRigidBody *__fastcall UFG::Ragdoll::GetRigidBody(UFG::Ragdoll *this, int skeletonBoneID)
{
  hkaRagdollInstance *v2; // r10
  hkpRigidBody *v3; // r11
  hkaSkeletonMapper *v4; // rcx
  __int64 v5; // r8
  __int64 v6; // r9
  hkaSkeletonMapperData::SimpleMapping *v7; // rcx
  __int64 v9; // rdx

  v2 = this->mRagdollInstance;
  if ( !v2 )
    return 0i64;
  v3 = 0i64;
  v4 = this->mRagdollData.m_pPointer->highResToRagdollMapper;
  v5 = 0i64;
  v6 = v4->m_mapping.m_simpleMappings.m_size;
  if ( v6 <= 0 )
    return 0i64;
  v7 = v4->m_mapping.m_simpleMappings.m_data;
  while ( v7->m_boneA != skeletonBoneID )
  {
    ++v5;
    ++v7;
    if ( v5 >= v6 )
      return 0i64;
  }
  if ( v7->m_boneB == -1 )
    return 0i64;
  v9 = v2->m_boneToRigidBodyMap.m_data[v7->m_boneB];
  if ( (signed int)v9 >= 0 )
    v3 = v2->m_rigidBodies.m_data[v9];
  return v3;
}

// File Line: 285
// RVA: 0xA0F40
void __fastcall UFG::Ragdoll::ApplyImpulse(UFG::Ragdoll *this, int bone, hkVector4f *location, hkVector4f *impulse)
{
  __m128 v4; // xmm0
  __m128 v5; // xmm1
  UFG::RagdollData *v6; // rax
  int v7; // er14
  hkaRagdollInstance *v8; // rdx
  hkaSkeletonMapper *v9; // rbp
  __int64 v10; // rsi
  __int64 v11; // rbx
  hkaSkeletonMapperData::SimpleMapping *v12; // rcx
  hkpEntity *v13; // rdi
  __m128 v14; // [rsp+20h] [rbp-38h]
  __m128 v15; // [rsp+30h] [rbp-28h]
  hkaRagdollInstance *v16; // [rsp+40h] [rbp-18h]

  v4 = impulse->m_quad;
  v5 = location->m_quad;
  v6 = this->mRagdollData.m_pPointer;
  v7 = bone;
  v8 = this->mRagdollInstance;
  v16 = this->mRagdollInstance;
  v15 = v4;
  v14 = v5;
  v9 = v6->highResToRagdollMapper;
  v10 = v9->m_mapping.m_simpleMappings.m_size;
  if ( v10 > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = v9->m_mapping.m_simpleMappings.m_data;
      if ( v12[v11].m_boneA == v7 )
      {
        v13 = (hkpEntity *)&v8->m_rigidBodies.m_data[v12[v11].m_boneB]->vfptr;
        hkpEntity::activate(v13);
        ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *, __m128 *))v13->m_motion.vfptr[11].__first_virtual_table_function__)(
          &v13->m_motion,
          &v15,
          &v14);
        v8 = v16;
      }
      ++v11;
      --v10;
    }
    while ( v10 );
  }
}

// File Line: 297
// RVA: 0xB8F40
void __usercall UFG::wrenchBone(void *cxt@<rcx>, int boneID@<edx>, __m128 a3@<xmm1>)
{
  _QWORD *v3; // rbp
  __int64 v4; // r12
  __int64 v5; // rsi
  int v6; // er14
  __m128 *v7; // rdx
  __m128 *v8; // r15
  __m128 v9; // xmm10
  float i; // xmm9_4
  __int64 v11; // rcx
  hkpEntity *v12; // rbx
  signed __int64 v13; // rdi
  hkpMotion *v14; // rcx
  __m128 v15; // xmm8
  __m128 v16; // xmm7
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  float v20; // xmm6_4
  __m128 v21; // xmm8
  __m128 v22; // [rsp+20h] [rbp-B8h]
  __m128 v23; // [rsp+30h] [rbp-A8h]

  v3 = (_QWORD *)*((_QWORD *)cxt + 4);
  v4 = boneID;
  v5 = 0i64;
  v6 = 0;
  v7 = *(__m128 **)(v3[2] + 8i64 * boneID);
  v8 = (__m128 *)cxt;
  v9 = v7[28];
  for ( i = v7[34].m128_f32[3]; v6 < *(_DWORD *)(v3[8] + 48i64); ++v5 )
  {
    v11 = *(signed int *)(v3[6] + 4 * v5);
    if ( (signed int)v11 >= 0 )
      v12 = *(hkpEntity **)(v3[2] + 8 * v11);
    else
      v12 = 0i64;
    v13 = (signed __int64)&v12->m_motion;
    v14 = (hkpMotion *)&v12->m_motion.vfptr;
    v15 = _mm_sub_ps(v12->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad, v9);
    if ( v5 == v4 )
    {
      a3.m128_f32[0] = hkpMotion::getMass(v14) * i;
    }
    else
    {
      v16 = (__m128)(unsigned int)FLOAT_1_0;
      v17 = _mm_mul_ps(v15, v15);
      v18 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170));
      v19 = _mm_rsqrt_ps(v18);
      v16.m128_f32[0] = (float)(1.0 - v8[2].m128_f32[2])
                      * (float)(COERCE_FLOAT(
                                  _mm_andnot_ps(
                                    _mm_cmpleps(v18, (__m128)0i64),
                                    _mm_mul_ps(
                                      _mm_mul_ps(
                                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                        _mm_mul_ps(*(__m128 *)_xmm, v19)),
                                      v18)))
                              * 4.0);
      a3 = v16;
      v20 = hkpMotion::getMass(v14);
      a3.m128_f32[0] = (float)(v20 * i) / powf(2.7182817, v16.m128_f32[0]);
    }
    v22 = _mm_mul_ps(_mm_shuffle_ps(a3, a3, 0), v8[1]);
    hkpEntity::activate(v12);
    (*(void (__fastcall **)(hkpMaxSizeMotion *, __m128 *))(*(_QWORD *)v13 + 192i64))(&v12->m_motion, &v22);
    a3 = _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v15);
    v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v22), a3);
    v23 = _mm_shuffle_ps(v21, v21, 201);
    hkpEntity::activate(v12);
    (*(void (__fastcall **)(hkpMaxSizeMotion *, __m128 *))(*(_QWORD *)v13 + 176i64))(&v12->m_motion, &v23);
    ++v6;
  }
}

// File Line: 336
// RVA: 0xA0B30
void __fastcall UFG::Ragdoll::ApplyAngularImpulse(UFG::Ragdoll *this, int bone, hkVector4f *impulse, float connectionTransfer)
{
  hkaRagdollInstance *v4; // rax
  __m128 v5; // xmm0
  UFG::RagdollData *v6; // rax
  int v7; // ebp
  hkaSkeletonMapper *v8; // rsi
  __int64 v9; // rdi
  __int64 v10; // rbx
  hkaSkeletonMapperData::SimpleMapping *v11; // rcx
  char cxt; // [rsp+20h] [rbp-38h]
  __m128 v13; // [rsp+30h] [rbp-28h]
  hkaRagdollInstance *v14; // [rsp+40h] [rbp-18h]
  float v15; // [rsp+48h] [rbp-10h]

  v4 = this->mRagdollInstance;
  v5 = impulse->m_quad;
  v15 = connectionTransfer;
  v14 = v4;
  v6 = this->mRagdollData.m_pPointer;
  v7 = bone;
  v13 = v5;
  v8 = v6->highResToRagdollMapper;
  v9 = v8->m_mapping.m_simpleMappings.m_size;
  if ( v9 > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = v8->m_mapping.m_simpleMappings.m_data;
      if ( v11[v10].m_boneA == v7 )
        UFG::wrenchBone(&cxt, v11[v10].m_boneB);
      ++v10;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 350
// RVA: 0xB11A0
void __fastcall UFG::Ragdoll::SetDynamic(UFG::Ragdoll *this, hkpRigidBody *rb, int boneId, unsigned int collisionLayer)
{
  hkpRigidBody *v4; // rbx
  unsigned int v5; // edi
  hkpWorld *v6; // rcx

  v4 = rb;
  v5 = collisionLayer | 32
                      * (((unsigned int)this->mRagdollData.m_pPointer->mCollisionFilterInfo.p[boneId] >> 5) & 0x1F | 32 * (((unsigned int)this->mRagdollData.m_pPointer->mCollisionFilterInfo.p[boneId] >> 10) & 0x1F | (this->mCollisionSystem << 6)));
  if ( (unsigned __int8)(rb->m_motion.m_type.m_storage - 4) <= 1u
    || rb->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo != v5 )
  {
    hkpRigidBody::setMotionType(rb, MOTION_DYNAMIC, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
    v6 = v4->m_world;
    v4->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v5;
    if ( v6 )
      hkpWorld::updateCollisionFilterOnEntity(
        v6,
        (hkpEntity *)&v4->vfptr,
        0,
        HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
  }
}

// File Line: 416
// RVA: 0x99410
void __fastcall UFG::Ragdoll::Ragdoll(UFG::Ragdoll *this, UFG::RagdollData *data, hkaRagdollInstance *instance, unsigned int collisionSystem)
{
  UFG::RagdollData *v4; // rbp
  UFG::Ragdoll *v5; // rbx
  hkpEaseConstraintsAction *v6; // rdi
  UFG::qSafePointer<UFG::RagdollData,UFG::RagdollData> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::BasePhysicsSystem *v9; // r14
  signed __int64 v10; // rsi
  char v11; // dl
  __int64 v12; // rax
  char v13; // cl
  _QWORD **v14; // rax
  hkaRagdollRigidBodyController *v15; // rax
  hkaRagdollRigidBodyController *v16; // rax
  char v17; // al
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v18; // rsi
  _QWORD **v19; // rax
  hkpEaseConstraintsAction *v20; // rax
  hkpEaseConstraintsAction *v21; // rax
  DetectRagdollPenetration::Output *v22; // [rsp+68h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v23; // [rsp+70h] [rbp+18h]

  v4 = data;
  v5 = this;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::BasePhysicsObject::`vftable;
  this->mUserData.isBoat = 0;
  v23 = &this->mUserData.simComponent;
  v23->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
  v23->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v23->mPrev;
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
  v7 = &this->mRagdollData;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  this->mRagdollData.m_pPointer = v4;
  if ( v4 )
  {
    v8 = v4->m_SafePointerList.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v8;
    this->mRagdollData.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  this->mSnapShotPoseMS.m_data = 0i64;
  this->mSnapShotPoseMS.m_size = 0;
  this->mSnapShotPoseMS.m_capacityAndFlags = 2147483648;
  v22 = &this->mPenetratedBones;
  v22->m_penetrations.m_data = 0i64;
  v22->m_penetrations.m_size = 0;
  v22->m_penetrations.m_capacityAndFlags = 2147483648;
  this->mUID = v4->rigGuid;
  this->mCollisionSystem = collisionSystem;
  v9 = UFG::BasePhysicsSystem::mInstance;
  UFG::Ragdoll::SetCollisionState(this, 0);
  v10 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v11 = ++*(_BYTE *)(v10 + 80);
  v12 = v11;
  *(_DWORD *)(v10 + 4 * v12) = 3;
  *(_QWORD *)(v10 + 8 * v12 + 16) = "hkaRagdollRigidBodyController";
  *(_QWORD *)(v10 + 8 * v12 + 48) = 0i64;
  v13 = *(_BYTE *)(v10 + 81);
  if ( v11 > v13 )
    v13 = v11;
  *(_BYTE *)(v10 + 81) = v13;
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkaRagdollRigidBodyController *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(
                                           v14[11],
                                           112i64);
  if ( v15 )
    hkaRagdollRigidBodyController::hkaRagdollRigidBodyController(v15, v5->mRagdollInstance);
  else
    v16 = 0i64;
  v5->mRigidBodyController = v16;
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
  v5->mDefaultControlData.m_hierarchyGain = UFG::g_default_m_hierarchyGain;
  v5->mDefaultControlData.m_velocityDamping = UFG::g_default_m_velocityDamping;
  v5->mDefaultControlData.m_accelerationGain = UFG::g_default_m_accelerationGain;
  v5->mDefaultControlData.m_velocityGain = UFG::g_default_m_velocityGain;
  v5->mDefaultControlData.m_positionGain = UFG::g_default_m_positionGain;
  v5->mDefaultControlData.m_positionMaxLinearVelocity = UFG::g_default_m_positionMaxLinearVelocity;
  v5->mDefaultControlData.m_positionMaxAngularVelocity = UFG::g_default_m_positionMaxAngularVelocity;
  v5->mDefaultControlData.m_snapGain = UFG::g_default_m_snapGain;
  v5->mDefaultControlData.m_snapMaxLinearVelocity = UFG::g_default_m_snapMaxLinearVelocity;
  v5->mDefaultControlData.m_snapMaxAngularVelocity = UFG::g_default_m_snapMaxAngularVelocity;
  v5->mDefaultControlData.m_snapMaxLinearDistance = UFG::g_default_m_snapMaxLinearDistance;
  v5->mDefaultControlData.m_snapMaxAngularDistance = UFG::g_default_m_snapMaxAngularDistance;
  v5->mKeyframedControlData.m_hierarchyGain = UFG::g_default_m_hierarchyGain;
  v5->mKeyframedControlData.m_velocityDamping = UFG::g_default_m_velocityDamping;
  v5->mKeyframedControlData.m_accelerationGain = 1.0;
  v5->mKeyframedControlData.m_velocityGain = 0.60000002;
  v5->mKeyframedControlData.m_positionGain = 0.25;
  v5->mKeyframedControlData.m_positionMaxLinearVelocity = 100.0;
  v5->mKeyframedControlData.m_positionMaxAngularVelocity = 10.0;
  v5->mKeyframedControlData.m_snapGain = 0.89999998;
  v5->mKeyframedControlData.m_snapMaxLinearVelocity = 100.0;
  v5->mKeyframedControlData.m_snapMaxAngularVelocity = 10.0;
  v5->mKeyframedControlData.m_snapMaxLinearDistance = 5.0;
  v5->mKeyframedControlData.m_snapMaxAngularDistance = UFG::g_default_m_snapMaxAngularDistance;
  UFG::Ragdoll::SetControlData(v5);
  v5->m_penetrationErrorVelocity = v4->m_penetrationErrorVelocity;
  v5->m_penetrationImpulseMax = v4->m_penetrationImpulseMax;
  hkReferencedObject::addReference((hkReferencedObject *)&v5->mRagdollData.m_pPointer->highResToRagdollMapper->vfptr);
  hkReferencedObject::addReference((hkReferencedObject *)&v5->mRagdollData.m_pPointer->ragdollToHighResMapper->vfptr);
  UFG::Ragdoll::CreateRagdollPenetrationUtil(v5, v9->mWorld);
  v18 = (hkArray<hkpEntity *,hkContainerHeapAllocator> *)v5->mRagdollInstance;
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (hkpEaseConstraintsAction *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(
                                      v19[11],
                                      104i64);
  if ( v20 )
  {
    hkpEaseConstraintsAction::hkpEaseConstraintsAction(v20, v18 + 1, 0i64);
    v6 = v21;
  }
  v5->mEaseConstraintsAction = v6;
});
  if ( v20 )
  {
    hkpEaseConstraintsActi

// File Line: 468
// RVA: 0x9CC70
void __fastcall UFG::Ragdoll::~Ragdoll(UFG::Ragdoll *this)
{
  UFG::Ragdoll *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  int v5; // er9
  __int64 v6; // rdx
  hkaRagdollInstance *v7; // r8
  __int64 v8; // rcx
  hkpRigidBody *v9; // rax
  hkpAction *v10; // rdx
  hkpWorld *v11; // rcx
  hkpPhantom *v12; // rdx
  hkpWorld *v13; // rcx
  hkaRagdollRigidBodyController *v14; // rdi
  _QWORD **v15; // rax
  int v16; // eax
  UFG::qSafePointer<UFG::RagdollData,UFG::RagdollData> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v20; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *v21; // rax
  hkResult result; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::BasePhysicsObjectVtbl *)&UFG::Ragdoll::`vftable;
  v2 = &this->mUserData.simComponent;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = 0;
  if ( v1->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = v1->mRagdollInstance;
      v8 = v7->m_boneToRigidBodyMap.m_data[v6];
      if ( (signed int)v8 >= 0 )
        v9 = v7->m_rigidBodies.m_data[v8];
      else
        v9 = 0i64;
      v9->m_userData = 0i64;
      ++v5;
      ++v6;
    }
    while ( v5 < v1->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size );
  }
  if ( hkaRagdollInstance::getWorld(v1->mRagdollInstance) )
    hkaRagdollInstance::removeFromWorld(v1->mRagdollInstance, &result);
  v10 = (hkpAction *)&v1->mEaseConstraintsAction->vfptr;
  v11 = v10->m_world;
  if ( v11 )
    hkpWorld::removeAction(v11, v10);
  v12 = (hkpPhantom *)&v1->mPhantom->vfptr;
  v13 = v12->m_world;
  if ( v13 )
    hkpWorld::removePhantom(v13, v12);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mEaseConstraintsAction->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mDetectRagdollPenetration->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mRagdollRaycastInterface->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mPhantom->vfptr);
  v14 = v1->mRigidBodyController;
  if ( v14 )
  {
    hkaRagdollRigidBodyController::~hkaRagdollRigidBodyController(v1->mRigidBodyController);
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkaRagdollRigidBodyController *, signed __int64))(*v15[11] + 16i64))(
      v15[11],
      v14,
      112i64);
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mRagdollData.m_pPointer->highResToRagdollMapper->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mRagdollData.m_pPointer->ragdollToHighResMapper->vfptr);
  DetectRagdollPenetration::Output::~Output(&v1->mPenetratedBones);
  v1->mSnapShotPoseMS.m_size = 0;
  v16 = v1->mSnapShotPoseMS.m_capacityAndFlags;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mSnapShotPoseMS.m_data,
      48 * (v16 & 0x3FFFFFFF));
  v1->mSnapShotPoseMS.m_data = 0i64;
  v1->mSnapShotPoseMS.m_capacityAndFlags = 2147483648;
  v17 = &v1->mRagdollData;
  *(_QWORD *)&result.m_enum = (char *)v1 + 248;
  if ( v1->mRagdollData.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->mRagdollData.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->mRagdollData.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)&v1->mRagdollData.mPrev;
  }
  v1->mRagdollData.m_pPointer = 0i64;
  v20 = v17->mPrev;
  v21 = v1->mRagdollData.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v1->mRagdollData.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RagdollData>,UFG::qSafePointerNodeList> *)&v1->mRagdollData.mPrev;
  UFG::BasePhysicsObject::~BasePhysicsObject((UFG::BasePhysicsObject *)&v1->vfptr);
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
  UFG::Ragdoll *v1; // rbx
  float *v2; // rdi
  int v3; // esi
  hkaRagdollRigidBodyController *v4; // rbp
  int v5; // eax
  int v6; // eax
  int v7; // er9
  __int64 v8; // rax
  int v9; // ecx
  signed __int64 v10; // rax
  int v11; // edx
  __int64 v12; // r8
  _DWORD *v13; // rax
  hkaRagdollRigidBodyController *v14; // rbp
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // er9
  signed __int64 v19; // r8
  signed __int64 v20; // rsi
  __int64 v21; // rdx
  signed int v22; // er10
  hkaKeyFrameHierarchyUtility::ControlData *v23; // rcx
  hkaKeyFrameHierarchyUtility::ControlData *v24; // rcx
  hkaKeyFrameHierarchyUtility::ControlData *v25; // rcx
  hkaKeyFrameHierarchyUtility::ControlData *v26; // rcx
  signed __int64 v27; // rdx
  hkaKeyFrameHierarchyUtility::ControlData *v28; // rcx
  hkResult result; // [rsp+70h] [rbp+8h]
  __int64 v30; // [rsp+78h] [rbp+10h]
  _DWORD *v31; // [rsp+80h] [rbp+18h]

  v1 = this;
  v2 = &this->mDefaultControlData.m_hierarchyGain;
  if ( this->mCollisionState )
    v2 = &this->mKeyframedControlData.m_hierarchyGain;
  v3 = this->mRagdollInstance->m_rigidBodies.m_size;
  v4 = this->mRigidBodyController;
  if ( v4->m_controlDataPalette.m_size <= 1 )
  {
    v5 = v4->m_controlDataPalette.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < v3 )
    {
      v6 = 2 * v5;
      v7 = this->mRagdollInstance->m_rigidBodies.m_size;
      if ( v3 < v6 )
        v7 = v6;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v7, 48);
    }
    v8 = v4->m_controlDataPalette.m_size;
    v9 = v3 - v8;
    v10 = (signed __int64)&v4->m_controlDataPalette.m_data[v8];
    v30 = v10;
    v11 = 0;
    result.m_enum = 0;
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
    v4->m_controlDataPalette.m_size = v3;
    v14 = v1->mRigidBodyController;
    v15 = v14->m_bodyIndexToPaletteIndex.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v15 < v3 )
    {
      v16 = 2 * v15;
      v17 = v3;
      if ( v3 < v16 )
        v17 = v16;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v14->m_bodyIndexToPaletteIndex,
        v17,
        4);
    }
    v14->m_bodyIndexToPaletteIndex.m_size = v3;
  }
  v18 = 0;
  v19 = 0i64;
  v20 = v1->mRigidBodyController->m_controlDataPalette.m_size;
  if ( v20 >= 4 )
  {
    v21 = 0i64;
    v22 = 2;
    do
    {
      v23 = v1->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v18 > v1->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v23[v21].m_hierarchyGain = v1->mDefaultControlData.m_hierarchyGain;
        v23[v21].m_velocityDamping = v1->mDefaultControlData.m_velocityDamping;
        v23[v21].m_accelerationGain = v1->mDefaultControlData.m_accelerationGain;
        v23[v21].m_velocityGain = v1->mDefaultControlData.m_velocityGain;
        v23[v21].m_positionGain = v1->mDefaultControlData.m_positionGain;
        v23[v21].m_positionMaxLinearVelocity = v1->mDefaultControlData.m_positionMaxLinearVelocity;
        v23[v21].m_positionMaxAngularVelocity = v1->mDefaultControlData.m_positionMaxAngularVelocity;
        v23[v21].m_snapGain = v1->mDefaultControlData.m_snapGain;
        v23[v21].m_snapMaxLinearVelocity = v1->mDefaultControlData.m_snapMaxLinearVelocity;
        v23[v21].m_snapMaxAngularVelocity = v1->mDefaultControlData.m_snapMaxAngularVelocity;
        v23[v21].m_snapMaxLinearDistance = v1->mDefaultControlData.m_snapMaxLinearDistance;
        v23[v21].m_snapMaxAngularDistance = v1->mDefaultControlData.m_snapMaxAngularDistance;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21].m_hierarchyGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21].m_accelerationGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21].m_positionGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21].m_snapGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21].m_velocityGain = 0.0;
      }
      else
      {
        v23[v21].m_hierarchyGain = *v2;
        v23[v21].m_velocityDamping = v2[1];
        v23[v21].m_accelerationGain = v2[2];
        v23[v21].m_velocityGain = v2[3];
        v23[v21].m_positionGain = v2[4];
        v23[v21].m_positionMaxLinearVelocity = v2[5];
        v23[v21].m_positionMaxAngularVelocity = v2[6];
        v23[v21].m_snapGain = v2[7];
        v23[v21].m_snapMaxLinearVelocity = v2[8];
        v23[v21].m_snapMaxAngularVelocity = v2[9];
        v23[v21].m_snapMaxLinearDistance = v2[10];
        v23[v21].m_snapMaxAngularDistance = v2[11];
      }
      v1->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19] = v18;
      v24 = v1->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v22 - 1 > v1->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v24[v21 + 1].m_hierarchyGain = v1->mDefaultControlData.m_hierarchyGain;
        v24[v21 + 1].m_velocityDamping = v1->mDefaultControlData.m_velocityDamping;
        v24[v21 + 1].m_accelerationGain = v1->mDefaultControlData.m_accelerationGain;
        v24[v21 + 1].m_velocityGain = v1->mDefaultControlData.m_velocityGain;
        v24[v21 + 1].m_positionGain = v1->mDefaultControlData.m_positionGain;
        v24[v21 + 1].m_positionMaxLinearVelocity = v1->mDefaultControlData.m_positionMaxLinearVelocity;
        v24[v21 + 1].m_positionMaxAngularVelocity = v1->mDefaultControlData.m_positionMaxAngularVelocity;
        v24[v21 + 1].m_snapGain = v1->mDefaultControlData.m_snapGain;
        v24[v21 + 1].m_snapMaxLinearVelocity = v1->mDefaultControlData.m_snapMaxLinearVelocity;
        v24[v21 + 1].m_snapMaxAngularVelocity = v1->mDefaultControlData.m_snapMaxAngularVelocity;
        v24[v21 + 1].m_snapMaxLinearDistance = v1->mDefaultControlData.m_snapMaxLinearDistance;
        v24[v21 + 1].m_snapMaxAngularDistance = v1->mDefaultControlData.m_snapMaxAngularDistance;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_hierarchyGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_accelerationGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_positionGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_snapGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 1].m_velocityGain = 0.0;
      }
      else
      {
        v24[v21 + 1].m_hierarchyGain = *v2;
        v24[v21 + 1].m_velocityDamping = v2[1];
        v24[v21 + 1].m_accelerationGain = v2[2];
        v24[v21 + 1].m_velocityGain = v2[3];
        v24[v21 + 1].m_positionGain = v2[4];
        v24[v21 + 1].m_positionMaxLinearVelocity = v2[5];
        v24[v21 + 1].m_positionMaxAngularVelocity = v2[6];
        v24[v21 + 1].m_snapGain = v2[7];
        v24[v21 + 1].m_snapMaxLinearVelocity = v2[8];
        v24[v21 + 1].m_snapMaxAngularVelocity = v2[9];
        v24[v21 + 1].m_snapMaxLinearDistance = v2[10];
        v24[v21 + 1].m_snapMaxAngularDistance = v2[11];
      }
      v1->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19 + 1] = v22 - 1;
      v25 = v1->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v22 > v1->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v25[v21 + 2].m_hierarchyGain = v1->mDefaultControlData.m_hierarchyGain;
        v25[v21 + 2].m_velocityDamping = v1->mDefaultControlData.m_velocityDamping;
        v25[v21 + 2].m_accelerationGain = v1->mDefaultControlData.m_accelerationGain;
        v25[v21 + 2].m_velocityGain = v1->mDefaultControlData.m_velocityGain;
        v25[v21 + 2].m_positionGain = v1->mDefaultControlData.m_positionGain;
        v25[v21 + 2].m_positionMaxLinearVelocity = v1->mDefaultControlData.m_positionMaxLinearVelocity;
        v25[v21 + 2].m_positionMaxAngularVelocity = v1->mDefaultControlData.m_positionMaxAngularVelocity;
        v25[v21 + 2].m_snapGain = v1->mDefaultControlData.m_snapGain;
        v25[v21 + 2].m_snapMaxLinearVelocity = v1->mDefaultControlData.m_snapMaxLinearVelocity;
        v25[v21 + 2].m_snapMaxAngularVelocity = v1->mDefaultControlData.m_snapMaxAngularVelocity;
        v25[v21 + 2].m_snapMaxLinearDistance = v1->mDefaultControlData.m_snapMaxLinearDistance;
        v25[v21 + 2].m_snapMaxAngularDistance = v1->mDefaultControlData.m_snapMaxAngularDistance;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_hierarchyGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_accelerationGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_positionGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_snapGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 2].m_velocityGain = 0.0;
      }
      else
      {
        v25[v21 + 2].m_hierarchyGain = *v2;
        v25[v21 + 2].m_velocityDamping = v2[1];
        v25[v21 + 2].m_accelerationGain = v2[2];
        v25[v21 + 2].m_velocityGain = v2[3];
        v25[v21 + 2].m_positionGain = v2[4];
        v25[v21 + 2].m_positionMaxLinearVelocity = v2[5];
        v25[v21 + 2].m_positionMaxAngularVelocity = v2[6];
        v25[v21 + 2].m_snapGain = v2[7];
        v25[v21 + 2].m_snapMaxLinearVelocity = v2[8];
        v25[v21 + 2].m_snapMaxAngularVelocity = v2[9];
        v25[v21 + 2].m_snapMaxLinearDistance = v2[10];
        v25[v21 + 2].m_snapMaxAngularDistance = v2[11];
      }
      v1->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19 + 2] = v22;
      v26 = v1->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v22 + 1 > v1->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v26[v21 + 3].m_hierarchyGain = v1->mDefaultControlData.m_hierarchyGain;
        v26[v21 + 3].m_velocityDamping = v1->mDefaultControlData.m_velocityDamping;
        v26[v21 + 3].m_accelerationGain = v1->mDefaultControlData.m_accelerationGain;
        v26[v21 + 3].m_velocityGain = v1->mDefaultControlData.m_velocityGain;
        v26[v21 + 3].m_positionGain = v1->mDefaultControlData.m_positionGain;
        v26[v21 + 3].m_positionMaxLinearVelocity = v1->mDefaultControlData.m_positionMaxLinearVelocity;
        v26[v21 + 3].m_positionMaxAngularVelocity = v1->mDefaultControlData.m_positionMaxAngularVelocity;
        v26[v21 + 3].m_snapGain = v1->mDefaultControlData.m_snapGain;
        v26[v21 + 3].m_snapMaxLinearVelocity = v1->mDefaultControlData.m_snapMaxLinearVelocity;
        v26[v21 + 3].m_snapMaxAngularVelocity = v1->mDefaultControlData.m_snapMaxAngularVelocity;
        v26[v21 + 3].m_snapMaxLinearDistance = v1->mDefaultControlData.m_snapMaxLinearDistance;
        v26[v21 + 3].m_snapMaxAngularDistance = v1->mDefaultControlData.m_snapMaxAngularDistance;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_hierarchyGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_accelerationGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_positionGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_snapGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v21 + 3].m_velocityGain = 0.0;
      }
      else
      {
        v26[v21 + 3].m_hierarchyGain = *v2;
        v26[v21 + 3].m_velocityDamping = v2[1];
        v26[v21 + 3].m_accelerationGain = v2[2];
        v26[v21 + 3].m_velocityGain = v2[3];
        v26[v21 + 3].m_positionGain = v2[4];
        v26[v21 + 3].m_positionMaxLinearVelocity = v2[5];
        v26[v21 + 3].m_positionMaxAngularVelocity = v2[6];
        v26[v21 + 3].m_snapGain = v2[7];
        v26[v21 + 3].m_snapMaxLinearVelocity = v2[8];
        v26[v21 + 3].m_snapMaxAngularVelocity = v2[9];
        v26[v21 + 3].m_snapMaxLinearDistance = v2[10];
        v26[v21 + 3].m_snapMaxAngularDistance = v2[11];
      }
      v1->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19 + 3] = v22 + 1;
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
      v28 = v1->mRigidBodyController->m_controlDataPalette.m_data;
      if ( v18 > v1->mRagdollData.m_pPointer->mLastCoreRagdollBone )
      {
        v28[v27].m_hierarchyGain = v1->mDefaultControlData.m_hierarchyGain;
        v28[v27].m_velocityDamping = v1->mDefaultControlData.m_velocityDamping;
        v28[v27].m_accelerationGain = v1->mDefaultControlData.m_accelerationGain;
        v28[v27].m_velocityGain = v1->mDefaultControlData.m_velocityGain;
        v28[v27].m_positionGain = v1->mDefaultControlData.m_positionGain;
        v28[v27].m_positionMaxLinearVelocity = v1->mDefaultControlData.m_positionMaxLinearVelocity;
        v28[v27].m_positionMaxAngularVelocity = v1->mDefaultControlData.m_positionMaxAngularVelocity;
        v28[v27].m_snapGain = v1->mDefaultControlData.m_snapGain;
        v28[v27].m_snapMaxLinearVelocity = v1->mDefaultControlData.m_snapMaxLinearVelocity;
        v28[v27].m_snapMaxAngularVelocity = v1->mDefaultControlData.m_snapMaxAngularVelocity;
        v28[v27].m_snapMaxLinearDistance = v1->mDefaultControlData.m_snapMaxLinearDistance;
        v28[v27].m_snapMaxAngularDistance = v1->mDefaultControlData.m_snapMaxAngularDistance;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v27].m_hierarchyGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v27].m_accelerationGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v27].m_positionGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v27].m_snapGain = 0.0;
        v1->mRigidBodyController->m_controlDataPalette.m_data[v27].m_velocityGain = 0.0;
      }
      else
      {
        v28[v27].m_hierarchyGain = *v2;
        v28[v27].m_velocityDamping = v2[1];
        v28[v27].m_accelerationGain = v2[2];
        v28[v27].m_velocityGain = v2[3];
        v28[v27].m_positionGain = v2[4];
        v28[v27].m_positionMaxLinearVelocity = v2[5];
        v28[v27].m_positionMaxAngularVelocity = v2[6];
        v28[v27].m_snapGain = v2[7];
        v28[v27].m_snapMaxLinearVelocity = v2[8];
        v28[v27].m_snapMaxAngularVelocity = v2[9];
        v28[v27].m_snapMaxLinearDistance = v2[10];
        v28[v27].m_snapMaxAngularDistance = v2[11];
      }
      v1->mRigidBodyController->m_bodyIndexToPaletteIndex.m_data[v19++] = v18++;
      ++v27;
    }
    while ( v19 < v20 );
  }
}

// File Line: 570
// RVA: 0xB1CB0
void __fastcall UFG::Ragdoll::SetPositionTrackingStiffness(UFG::Ragdoll *this, float p)
{
  hkaRagdollRigidBodyController *v2; // r10
  signed __int64 v3; // r11
  signed __int64 v4; // r8
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
  signed __int64 v16; // r8
  float v17; // xmm4_4
  float v18; // xmm4_4
  signed __int64 v19; // rdx
  bool v20; // r8
  float *v21; // rcx
  float *v22; // rax
  unsigned __int64 v23; // r9
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm0_4
  float *v31; // rax
  signed __int64 v32; // rdx
  float v33; // xmm4_4

  v2 = this->mRigidBodyController;
  v3 = 0i64;
  if ( p >= 1.0 )
  {
    v19 = v2->m_controlDataPalette.m_size;
    v20 = sClamp_PositionGain;
    if ( v19 >= 4 )
    {
      v21 = &v2->m_controlDataPalette.m_data->m_positionMaxAngularVelocity;
      v22 = &v2->m_controlDataPalette.m_data[1].m_positionMaxAngularVelocity;
      v23 = ((unsigned __int64)(v19 - 4) >> 2) + 1;
      v3 = 4 * v23;
      v24 = (float)((float)(p * 98.599998) * 0.0099999998) + 1.4;
      v25 = (float)((float)(p * 8.3415899) * 0.0099999998) + 1.8;
      v26 = (float)(p * 0.28) * 0.0099999998;
      do
      {
        *(v21 - 2) = v26 + UFG::g_default_m_positionGain;
        *(v21 - 1) = v24;
        *v21 = v25;
        *(v21 - 4) = UFG::g_default_m_accelerationGain;
        *(v21 - 5) = UFG::g_default_m_velocityDamping;
        *(v21 - 3) = UFG::g_default_m_velocityGain;
        *(v21 - 6) = UFG::g_default_m_hierarchyGain;
        v21[1] = UFG::g_default_m_snapGain;
        if ( v20 )
        {
          v27 = *(v21 - 2);
          if ( v27 <= 0.0 )
          {
            v27 = 0.0;
          }
          else if ( v27 >= 1.0 )
          {
            v27 = *(float *)&FLOAT_1_0;
          }
          *(v21 - 2) = v27;
        }
        *(v22 - 2) = v26 + UFG::g_default_m_positionGain;
        *(v22 - 1) = v24;
        *v22 = v25;
        *(v22 - 4) = UFG::g_default_m_accelerationGain;
        *(v22 - 5) = UFG::g_default_m_velocityDamping;
        *(v22 - 3) = UFG::g_default_m_velocityGain;
        v21[6] = UFG::g_default_m_hierarchyGain;
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
        v21[18] = UFG::g_default_m_hierarchyGain;
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
        v21[30] = UFG::g_default_m_hierarchyGain;
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
        v21 += 48;
        v22 += 48;
        --v23;
      }
      while ( v23 );
    }
    if ( v3 < v19 )
    {
      v31 = &v2->m_controlDataPalette.m_data[v3].m_hierarchyGain;
      v32 = v19 - v3;
      do
      {
        v33 = (float)((float)(p * 0.28) * 0.0099999998) + UFG::g_default_m_positionGain;
        v31[5] = (float)((float)(p * 98.599998) * 0.0099999998) + 1.4;
        v31[6] = (float)((float)(p * 8.3415899) * 0.0099999998) + 1.8;
        v31[4] = v33;
        v31[2] = UFG::g_default_m_accelerationGain;
        v31[1] = UFG::g_default_m_velocityDamping;
        v31[3] = UFG::g_default_m_velocityGain;
        *v31 = UFG::g_default_m_hierarchyGain;
        v31[7] = UFG::g_default_m_snapGain;
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
          v31[4] = v33;
        }
        v31 += 12;
        --v32;
      }
      while ( v32 );
    }
  }
  else
  {
    v4 = v2->m_controlDataPalette.m_size;
    v5 = sClamp_PositionGain;
    if ( v4 >= 4 )
    {
      v6 = &v2->m_controlDataPalette.m_data->m_positionMaxAngularVelocity;
      v7 = &v2->m_controlDataPalette.m_data[1].m_positionMaxAngularVelocity;
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
      v15 = &v2->m_controlDataPalette.m_data[v3].m_hierarchyGain;
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
  float v1; // xmm0_4
  float result; // xmm0_4

  v1 = this->mRigidBodyController->m_controlDataPalette.m_data->m_positionGain;
  if ( v1 >= 0.050000001 )
    result = (float)((float)(v1 - 0.050000001) * 357.14285) + 1.0;
  else
    result = v1 * 20.0;
  return result;
}

// File Line: 638
// RVA: 0xB23E0
void __fastcall UFG::Ragdoll::SetPositionTrackingStiffnessAtJoint(UFG::Ragdoll *this, float p, int skeletonBoneID)
{
  __int64 v3; // r9
  hkaSkeletonMapper *v4; // rdx
  __int64 v5; // r10
  hkaSkeletonMapperData::SimpleMapping *v6; // rdx
  signed int v7; // eax
  hkaKeyFrameHierarchyUtility::ControlData *v8; // rdx
  float v9; // xmm0_4

  if ( this->mRagdollInstance
    && (v3 = 0i64,
        v4 = this->mRagdollData.m_pPointer->highResToRagdollMapper,
        v5 = v4->m_mapping.m_simpleMappings.m_size,
        v5 > 0) )
  {
    v6 = v4->m_mapping.m_simpleMappings.m_data;
    while ( v6->m_boneA != skeletonBoneID )
    {
      ++v3;
      ++v6;
      if ( v3 >= v5 )
        goto LABEL_6;
    }
    v7 = v6->m_boneB;
  }
  else
  {
LABEL_6:
    v7 = -1;
  }
  v8 = &this->mRigidBodyController->m_controlDataPalette.m_data[v7];
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
  UFG::Ragdoll *v1; // rbx
  hkpAction *v2; // rdx
  hkpWorld *v3; // rcx
  hkpPhantom *v4; // rdx
  hkpWorld *v5; // rcx
  hkResult result; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( hkaRagdollInstance::getWorld(this->mRagdollInstance) )
    hkaRagdollInstance::removeFromWorld(v1->mRagdollInstance, &result);
  v2 = (hkpAction *)&v1->mEaseConstraintsAction->vfptr;
  v3 = v2->m_world;
  if ( v3 )
    hkpWorld::removeAction(v3, v2);
  v4 = (hkpPhantom *)&v1->mPhantom->vfptr;
  v5 = v4->m_world;
  if ( v5 )
    hkpWorld::removePhantom(v5, v4);
}

// File Line: 726
// RVA: 0xA0A00
void __fastcall UFG::Ragdoll::AddToWorld(UFG::Ragdoll *this)
{
  UFG::Ragdoll *v1; // rdi
  hkpWorld *v2; // rbx
  hkResult result; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( !hkaRagdollInstance::getWorld(this->mRagdollInstance) )
  {
    v2 = UFG::BasePhysicsSystem::mInstance->mWorld;
    hkaRagdollInstance::addToWorld(v1->mRagdollInstance, &result, UFG::BasePhysicsSystem::mInstance->mWorld, (hkBool)1);
    hkpWorld::addPhantom(v2, (hkpPhantom *)&v1->mPhantom->vfptr);
    v1->m_framesSinceInterpenetration = 0;
  }
}

// File Line: 754
// RVA: 0xA8C50
void __fastcall UFG::Ragdoll::ForcePose(UFG::Ragdoll *this, hkaSkeleton *skel, hkaPose *pose, hkQsTransformf *worldTransform)
{
  hkQsTransformf *v4; // r12
  UFG::Ragdoll *v5; // r13
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v6; // rsi
  hkaSkeleton *v7; // rdi
  int v8; // ebx
  hkLifoAllocator *v9; // rax
  unsigned int v10; // ecx
  int v11; // edx
  hkQsTransformf *v12; // r14
  char *v13; // rcx
  int v14; // ebx
  int v15; // esi
  hkLifoAllocator *v16; // rax
  int v17; // edx
  hkQsTransformf *v18; // rcx
  char *v19; // r8
  hkaRagdollInstance *v20; // r15
  int v21; // ebx
  signed __int64 v22; // rdi
  int v23; // edx
  hkpRigidBody *v24; // rcx
  hkVector4f v25; // xmm6
  hkVector4f v26; // xmm7
  hkVector4f v27; // xmm8
  hkVector4f v28; // xmm9
  hkVector4f v29; // xmm10
  hkVector4f v30; // xmm11
  signed __int64 v31; // rax
  bool v32; // zf
  __m128 *v33; // rax
  __int64 v34; // rdi
  __int64 v35; // r14
  hkpEntity *v36; // rbx
  hkpEntity *v37; // rbx
  void **v38; // rdx
  hkpEntity *v39; // rbx
  hkaRagdollInstance *v40; // rcx
  hkpEaseConstraintsAction *v41; // rcx
  hkpWorld *v42; // rax
  char *v43; // rdi
  int v44; // ecx
  hkLifoAllocator *v45; // rcx
  signed int v46; // ebx
  int v47; // er8
  hkLifoAllocator *v48; // rax
  int v49; // er8
  hkaSkeletonMapper::ConstraintSource source; // [rsp+20h] [rbp-79h]
  signed int v51; // [rsp+28h] [rbp-71h]
  hkQsTransformf *array; // [rsp+30h] [rbp-69h]
  void *p[2]; // [rsp+38h] [rbp-61h]
  __m128 *v54; // [rsp+48h] [rbp-51h]
  hkQsTransformf *v55; // [rsp+50h] [rbp-49h]
  int v56; // [rsp+58h] [rbp-41h]
  __int64 v57; // [rsp+60h] [rbp-39h]
  int numBytesIn[2]; // [rsp+F8h] [rbp+5Fh]
  void *retaddr; // [rsp+118h] [rbp+7Fh]

  v57 = -2i64;
  v4 = worldTransform;
  v5 = this;
  v6 = hkaPose::getSyncedPoseModelSpace(pose);
  v7 = v5->mRagdollInstance->m_skeleton.m_pntr;
  v8 = v7->m_bones.m_size;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (48 * v8 + 127) & 0xFFFFFF80;
  v51 = v10;
  v11 = (v10 + 15) & 0xFFFFFFF0;
  numBytesIn[0] = v11;
  v12 = (hkQsTransformf *)v9->m_cur;
  array = v12;
  v13 = (char *)v12 + v11;
  if ( v11 > v9->m_slabSize || v13 > v9->m_end )
  {
    v12 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
    array = v12;
  }
  else
  {
    v9->m_cur = v13;
  }
  v55 = v12;
  v56 = v8;
  hkaSkeletonUtils::transformLocalPoseToModelPose(v8, v7->m_parentIndices.m_data, v7->m_referencePose.m_data, v12);
  hkaSkeletonMapper::mapPose(
    v5->mRagdollData.m_pPointer->highResToRagdollMapper,
    v6->m_data,
    v7->m_referencePose.m_data,
    v12,
    CURRENT_POSE);
  v14 = v8 - v5->mRagdollData.m_pPointer->mLastCoreRagdollBone - 1;
  v15 = 0;
  array = 0i64;
  p[0] = (void *)0x8000000000000000i64;
  source = v14;
  if ( v14 )
  {
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (((112 * v14 + 127) & 0xFFFFFF80) + 15) & 0xFFFFFFF0;
    v18 = (hkQsTransformf *)v16->m_cur;
    v19 = (char *)v18 + v17;
    if ( v17 > v16->m_slabSize || v19 > v16->m_end )
      v18 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v16, v17);
    else
      v16->m_cur = v19;
  }
  else
  {
    v18 = 0i64;
  }
  array = v18;
  HIDWORD(p[0]) = v14 | 0x80000000;
  p[1] = v18;
  v20 = v5->mRagdollInstance;
  v21 = v5->mRagdollData.m_pPointer->mLastCoreRagdollBone + 1;
  if ( v21 < v20->m_rigidBodies.m_size )
  {
    v22 = v21;
    v23 = (int)p[0];
    do
    {
      v24 = v20->m_rigidBodies.m_data[v22];
      v25.m_quad = (__m128)v24->m_motion.m_motionState.m_transform.m_rotation.m_col0;
      v26.m_quad = (__m128)v24->m_motion.m_motionState.m_transform.m_rotation.m_col1;
      v27.m_quad = (__m128)v24->m_motion.m_motionState.m_transform.m_rotation.m_col2;
      v28.m_quad = (__m128)v24->m_motion.m_motionState.m_transform.m_translation;
      v29.m_quad = (__m128)v24->m_motion.m_linearVelocity;
      v30.m_quad = (__m128)v24->m_motion.m_angularVelocity;
      if ( v23 == (HIDWORD(p[0]) & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 112);
        v23 = (int)p[0];
      }
      v31 = 112i64 * v23;
      v32 = (hkQsTransformf *)((char *)array + v31) == 0i64;
      v33 = (__m128 *)((char *)&array->m_translation.m_quad + v31);
      v54 = v33;
      p[0] = v33;
      if ( !v32 )
      {
        *(hkVector4f *)v33 = (hkVector4f)v25.m_quad;
        v33[1] = v26.m_quad;
        v33[2] = v27.m_quad;
        v33[3] = v28.m_quad;
        v33[4] = v29.m_quad;
        v33[5] = v30.m_quad;
        v33[6].m128_i32[0] = v21;
      }
      v23 = LODWORD(p[0])++ + 1;
      ++v21;
      ++v22;
    }
    while ( v21 < v20->m_rigidBodies.m_size );
  }
  hkaRagdollInstance::setPoseModelSpace(v5->mRagdollInstance, v12, v4);
  if ( SLODWORD(p[0]) > 0 )
  {
    v34 = 0i64;
    do
    {
      v35 = (__int64)array + v34;
      if ( (_BYTE)retaddr )
      {
        *(_OWORD *)p = 0i64;
        v36 = (hkpEntity *)&v20->m_rigidBodies.m_data[*(signed int *)(v35 + 96)]->vfptr;
        hkpEntity::activate(v36);
        v36->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v36->m_motion.vfptr, (unsigned int)p);
        v37 = (hkpEntity *)&v20->m_rigidBodies.m_data[*(signed int *)(v35 + 96)]->vfptr;
        hkpEntity::activate(v37);
        v38 = p;
      }
      else
      {
        hkpRigidBody::setTransform(
          v20->m_rigidBodies.m_data[*(signed int *)(v35 + 96)],
          (hkTransformf *)((char *)array + v34));
        v39 = (hkpEntity *)&v20->m_rigidBodies.m_data[*(signed int *)(v35 + 96)]->vfptr;
        hkpEntity::activate(v39);
        v39->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v39->m_motion.vfptr, v35 + 64);
        v37 = (hkpEntity *)&v20->m_rigidBodies.m_data[*(signed int *)(v35 + 96)]->vfptr;
        hkpEntity::activate(v37);
        v38 = (void **)(v35 + 80);
      }
      ((void (__fastcall *)(hkpMaxSizeMotion *, void **))v37->m_motion.vfptr[9].__first_virtual_table_function__)(
        &v37->m_motion,
        v38);
      ++v15;
      v34 += 112i64;
    }
    while ( v15 < SLODWORD(p[0]) );
    v12 = array;
  }
  hkaRagdollRigidBodyController::reinitialize(v5->mRigidBodyController);
  if ( (_BYTE)retaddr )
  {
    v40 = v5->mRagdollInstance;
    if ( v40 )
    {
      if ( hkaRagdollInstance::getWorld(v40) )
      {
        v41 = v5->mEaseConstraintsAction;
        if ( !v41->m_world )
        {
          hkpEaseConstraintsAction::loosenConstraints(v41);
          hkpEaseConstraintsAction::restoreConstraints(v5->mEaseConstraintsAction, 0.5);
          v42 = hkaRagdollInstance::getWorld(v5->mRagdollInstance);
          hkpWorld::addAction(v42, (hkpAction *)&v5->mEaseConstraintsAction->vfptr);
        }
      }
    }
  }
  v43 = (char *)p[1];
  v44 = (int)p[0];
  if ( p[1] == array )
    v44 = 0;
  LODWORD(p[0]) = v44;
  v45 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v46 = (112 * source + 127) & 0xFFFFFF80;
  v47 = (v46 + 15) & 0xFFFFFFF0;
  if ( v46 > v45->m_slabSize || &v43[v47] != v45->m_cur || v45->m_firstNonLifoEnd == v43 )
    hkLifoAllocator::slowBlockFree(v45, v43, v47);
  else
    v45->m_cur = v43;
  LODWORD(p[0]) = 0;
  if ( SHIDWORD(p[0]) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      112 * (HIDWORD(p[0]) & 0x3FFFFFFF));
  array = 0i64;
  HIDWORD(p[0]) = 2147483648;
  v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v51 > v48->m_slabSize )
  {
    v49 = numBytesIn[0];
  }
  else
  {
    v49 = numBytesIn[0];
    if ( (char *)v12 + numBytesIn[0] == v48->m_cur && v48->m_firstNonLifoEnd != v12 )
    {
      v48->m_cur = v12;
      return;
    }
  }
  hkLifoAllocator::slowBlockFree(v48, v12, v49);
}= v12 )
    {
      v48->m_cur = v12;
      return;
    }
  }
  hkLifoAllocator::slowBlockFree(v48, v12, v49);
}

// File Line: 865
// RVA: 0xAA110
void __fastcall UFG::Ragdoll::GetHighResPose(UFG::Ragdoll *this, hkaSkeleton *skel, hkaPose *pose, hkQsTransformf *worldTransform)
{
  hkQsTransformf *v4; // r12
  hkaPose *v5; // r15
  UFG::Ragdoll *v6; // r14
  int v7; // ebx
  hkLifoAllocator *v8; // rax
  signed int v9; // ebp
  int v10; // esi
  hkQsTransformf *v11; // rdi
  char *v12; // rcx
  hkQsTransformf *v13; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v14; // rax
  hkLifoAllocator *v15; // rax

  v4 = worldTransform;
  v5 = pose;
  v6 = this;
  v7 = this->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size;
  v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (48 * v7 + 127) & 0xFFFFFF80;
  v10 = (v9 + 15) & 0xFFFFFFF0;
  v11 = (hkQsTransformf *)v8->m_cur;
  v12 = (char *)v11 + v10;
  if ( v10 > v8->m_slabSize || v12 > v8->m_end )
    v11 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v8, v10);
  else
    v8->m_cur = v12;
  hkaRagdollInstance::getPoseModelSpace(v6->mRagdollInstance, v11, v4);
  v13 = hkaPose::getSyncedPoseLocalSpace(v5)->m_data;
  v14 = hkaPose::accessSyncedPoseModelSpace(v5);
  hkaSkeletonMapper::mapPose(v6->mRagdollData.m_pPointer->ragdollToHighResMapper, v11, v13, v14->m_data, CURRENT_POSE);
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v9 > v15->m_slabSize || (char *)v11 + v10 != v15->m_cur || v15->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v15, v11, v10);
  else
    v15->m_cur = v11;
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
void __fastcall UFG::Ragdoll::UpdateVelocityTracking(UFG::Ragdoll *this, hkaSkeleton *skel, hkaPose *pose, hkQsTransformf *worldTransform, float deltaT)
{
  hkaPose *v5; // r13
  UFG::Ragdoll *v6; // rsi
  hkaSkeleton *v7; // r14
  int v8; // er12
  hkLifoAllocator *v9; // rax
  signed int v10; // er15
  int v11; // edi
  hkQsTransformf *v12; // rbp
  char *v13; // rcx
  hkQsTransformf *v14; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v15; // rax
  hkLifoAllocator *v16; // rax
  hkQsTransformf *v17; // rsi
  char *v18; // rcx
  hkLifoAllocator *v19; // rax
  signed int v20; // er13
  int v21; // er14
  hkaKeyFrameHierarchyUtility::Output *v22; // rbx
  char *v23; // rcx
  hkLifoAllocator *v24; // rax
  hkLifoAllocator *v25; // rax
  hkLifoAllocator *v26; // rax
  UFG::Ragdoll *v27; // [rsp+B0h] [rbp+8h]
  hkQsTransformf *worldFromModel; // [rsp+C8h] [rbp+20h]

  worldFromModel = worldTransform;
  v27 = this;
  v5 = pose;
  v6 = this;
  v7 = this->mRagdollInstance->m_skeleton.m_pntr;
  v8 = v7->m_bones.m_size;
  v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (48 * v8 + 127) & 0xFFFFFF80;
  v11 = (v10 + 15) & 0xFFFFFFF0;
  v12 = (hkQsTransformf *)v9->m_cur;
  v13 = (char *)v12 + v11;
  if ( v11 > v9->m_slabSize || v13 > v9->m_end )
    v12 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
  else
    v9->m_cur = v13;
  hkaSkeletonUtils::transformLocalPoseToModelPose(v8, v7->m_parentIndices.m_data, v7->m_referencePose.m_data, v12);
  v14 = v7->m_referencePose.m_data;
  v15 = hkaPose::getSyncedPoseModelSpace(v5);
  hkaSkeletonMapper::mapPose(v6->mRagdollData.m_pPointer->highResToRagdollMapper, v15->m_data, v14, v12, CURRENT_POSE);
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkQsTransformf *)v16->m_cur;
  v18 = (char *)v17 + v11;
  if ( v11 > v16->m_slabSize || v18 > v16->m_end )
    v17 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v16, v11);
  else
    v16->m_cur = v18;
  hkaSkeletonUtils::transformModelPoseToLocalPose(v8, v7->m_parentIndices.m_data, v12, v17);
  v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (4 * v8 + 127) & 0xFFFFFF80;
  v21 = (v20 + 15) & 0xFFFFFFF0;
  v22 = (hkaKeyFrameHierarchyUtility::Output *)v19->m_cur;
  v23 = (char *)v22 + v21;
  if ( v21 > v19->m_slabSize || v23 > v19->m_end )
    v22 = (hkaKeyFrameHierarchyUtility::Output *)hkLifoAllocator::allocateFromNewSlab(v19, v21);
  else
    v19->m_cur = v23;
  UFG::Ragdoll::UpdatePenetrationRecovery(v27);
  hkaRagdollRigidBodyController::driveToPose(v27->mRigidBodyController, deltaT, v17, worldFromModel, v22);
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
  if ( v10 > v26->m_slabSize || (char *)v12 + v11 != v26->m_cur || v26->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v26, v12, v11);
  else
    v26->m_cur = v12;
}

// File Line: 943
// RVA: 0xACB50
void __fastcall UFG::Ragdoll::InitializePoweredTracking(UFG::Ragdoll *this)
{
  this->m_framesSinceInterpenetration = 0;
  JUMPOUT(this->mRagdollInstance, 0i64, hkaRagdollPoweredConstraintController::startMotors);
}

// File Line: 955
// RVA: 0xB2B50
void __fastcall UFG::Ragdoll::ShutdownPoweredTracking(UFG::Ragdoll *this)
{
  JUMPOUT(this->mRagdollInstance, 0i64, hkaRagdollPoweredConstraintController::stopMotors);
}

// File Line: 967
// RVA: 0xB4D70
void __fastcall UFG::Ragdoll::UpdatePenetrationRecovery(UFG::Ragdoll *this)
{
  UFG::Ragdoll *v1; // rbx
  hkaSkeleton *v2; // r8
  DetectRagdollPenetration *v3; // rdi
  int v4; // edx
  __int64 v5; // rcx
  int v6; // edi
  int v7; // esi
  int v8; // er9
  int v9; // er9
  int v10; // er9
  int v11; // esi
  int v12; // er9
  int v13; // ecx
  int v14; // ecx
  int v15; // er9
  float *v16; // rdi
  __int64 v17; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v18; // rax
  hkArray<enum DetectRagdollPenetration::BonePenetrationStatus,hkContainerHeapAllocator> *v19; // r8
  unsigned int v20; // esi
  __int64 v21; // r12
  __int64 v22; // r13
  hkaRagdollInstance *v23; // rdx
  __int64 v24; // rcx
  hkpRigidBody *v25; // rdi
  int v26; // er15
  DetectRagdollPenetration::BonePenetrationStatus v27; // ecx
  UFG::RagdollData *v28; // rax
  int v29; // er15
  bool v30; // zf
  bool v31; // sf
  unsigned __int8 v32; // of
  unsigned int v33; // edx
  unsigned int v34; // eax
  int v35; // ecx
  int v36; // er15
  hkpWorld *v37; // rcx
  int v38; // er15
  hkpWorld *v39; // rcx
  hkaPose ragdollPoseIn; // [rsp+30h] [rbp-59h]
  hkResult v41; // [rsp+80h] [rbp-9h]
  hkResult v42; // [rsp+84h] [rbp-5h]
  hkResult v43; // [rsp+88h] [rbp-1h]
  hkResult v44; // [rsp+8Ch] [rbp+3h]
  __int64 v45; // [rsp+90h] [rbp+7h]
  hkResult result; // [rsp+F0h] [rbp+67h]
  hkResult v47; // [rsp+F8h] [rbp+6Fh]
  hkResult v48; // [rsp+100h] [rbp+77h]
  hkResult v49; // [rsp+108h] [rbp+7Fh]

  v45 = -2i64;
  v1 = this;
  if ( this->mCollisionState )
  {
    this->m_framesSinceInterpenetration = 0;
    return;
  }
  if ( this->m_framesSinceInterpenetration < 70 )
  {
    v2 = this->mRagdollInstance->m_skeleton.m_pntr;
    v3 = this->mDetectRagdollPenetration;
    v4 = 0;
    if ( v3->m_boneStates.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        v3->m_boneStates.m_data[v5] = 1;
        ++v4;
        ++v5;
      }
      while ( v4 < v3->m_boneStates.m_size );
    }
    v3->m_ragdollIsOut.m_bool = 0;
    ragdollPoseIn.m_skeleton = v2;
    ragdollPoseIn.m_localPose.m_data = 0i64;
    ragdollPoseIn.m_localPose.m_size = 0;
    ragdollPoseIn.m_localPose.m_capacityAndFlags = 2147483648;
    ragdollPoseIn.m_modelPose.m_data = 0i64;
    ragdollPoseIn.m_modelPose.m_size = 0;
    ragdollPoseIn.m_modelPose.m_capacityAndFlags = 2147483648;
    ragdollPoseIn.m_boneFlags.m_data = 0i64;
    ragdollPoseIn.m_boneFlags.m_size = 0;
    ragdollPoseIn.m_boneFlags.m_capacityAndFlags = 2147483648;
    *(_WORD *)&ragdollPoseIn.m_modelInSync.m_bool = 0;
    ragdollPoseIn.m_floatSlotValues.m_data = 0i64;
    ragdollPoseIn.m_floatSlotValues.m_size = 0;
    ragdollPoseIn.m_floatSlotValues.m_capacityAndFlags = 2147483648;
    v6 = v2->m_bones.m_size;
    v7 = (v6 + 3) & 0xFFFFFFFC;
    if ( v7 <= 0 )
      result.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &ragdollPoseIn.m_modelPose,
        v7,
        48);
    if ( (ragdollPoseIn.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v7 )
      v47.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &v47,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &ragdollPoseIn.m_localPose,
        v7,
        48);
    if ( (ragdollPoseIn.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v7 )
      v48.m_enum = 0;
    else
      hkArrayUtil::_reserve(
        &v48,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &ragdollPoseIn.m_boneFlags,
        v7,
        4);
    if ( (ragdollPoseIn.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF) >= v6 )
    {
      v49.m_enum = 0;
    }
    else
    {
      v8 = v6;
      if ( v6 < 2 * (ragdollPoseIn.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF) )
        v8 = 2 * (ragdollPoseIn.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &v49,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &ragdollPoseIn.m_modelPose,
        v8,
        48);
    }
    ragdollPoseIn.m_modelPose.m_size = v6;
    if ( (ragdollPoseIn.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) >= v6 )
    {
      v44.m_enum = 0;
    }
    else
    {
      v9 = v6;
      if ( v6 < 2 * (ragdollPoseIn.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) )
        v9 = 2 * (ragdollPoseIn.m_localPose.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &v44,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &ragdollPoseIn.m_localPose,
        v9,
        48);
    }
    ragdollPoseIn.m_localPose.m_size = v6;
    if ( (ragdollPoseIn.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) >= v6 )
    {
      v43.m_enum = 0;
    }
    else
    {
      v10 = v6;
      if ( v6 < 2 * (ragdollPoseIn.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) )
        v10 = 2 * (ragdollPoseIn.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &v43,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &ragdollPoseIn.m_boneFlags,
        v10,
        4);
    }
    ragdollPoseIn.m_boneFlags.m_size = v6;
    v11 = ragdollPoseIn.m_skeleton->m_floatSlots.m_size;
    v12 = (v11 + 3) & 0xFFFFFFFC;
    v13 = ragdollPoseIn.m_floatSlotValues.m_capacityAndFlags;
    if ( (ragdollPoseIn.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) >= v12 )
    {
      v41.m_enum = 0;
    }
    else
    {
      hkArrayUtil::_reserve(
        &v41,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &ragdollPoseIn.m_floatSlotValues,
        v12,
        4);
      v13 = ragdollPoseIn.m_floatSlotValues.m_capacityAndFlags;
    }
    v14 = v13 & 0x3FFFFFFF;
    if ( v14 >= v11 )
    {
      v42.m_enum = 0;
    }
    else
    {
      v15 = v11;
      if ( v11 < 2 * v14 )
        v15 = 2 * v14;
      hkArrayUtil::_reserve(
        &v42,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &ragdollPoseIn.m_floatSlotValues,
        v15,
        4);
    }
    v16 = &ragdollPoseIn.m_floatSlotValues.m_data[ragdollPoseIn.m_floatSlotValues.m_size];
    v17 = v11 - ragdollPoseIn.m_floatSlotValues.m_size;
    if ( v11 - ragdollPoseIn.m_floatSlotValues.m_size > 0 )
    {
      while ( v17 )
      {
        *v16 = 0.0;
        ++v16;
        --v17;
      }
    }
    ragdollPoseIn.m_floatSlotValues.m_size = v11;
    v18 = hkaPose::accessUnsyncedPoseModelSpace(&ragdollPoseIn);
    hkaRagdollInstance::getPoseWorldSpace(v1->mRagdollInstance, v18->m_data);
    DetectRagdollPenetration::detectPenetration(
      v1->mDetectRagdollPenetration,
      (hkBool *)&result,
      &ragdollPoseIn,
      &v1->mPenetratedBones);
    v19 = &v1->mDetectRagdollPenetration->m_boneStates;
    *(_QWORD *)&v47.m_enum = (char *)v1->mDetectRagdollPenetration + 48;
    if ( !LOBYTE(result.m_enum) )
      ++v1->m_framesSinceInterpenetration;
    v20 = 0;
    if ( v1->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size > 0 )
    {
      v21 = 0i64;
      v22 = 0i64;
      do
      {
        v23 = v1->mRagdollInstance;
        v24 = v23->m_boneToRigidBodyMap.m_data[v21];
        if ( (signed int)v24 >= 0 )
          v25 = v23->m_rigidBodies.m_data[v24];
        else
          v25 = 0i64;
        v26 = v23->m_skeleton.m_pntr->m_parentIndices.m_data[v22];
        v27 = v19->m_data[v21];
        if ( v27 )
        {
          if ( v27 == 1 )
          {
            UFG::Ragdoll::SetDynamic(v1, v25, v20, 8u);
            UFG::Ragdoll::ApplyCorrectionImpulse(v1, v25, v20, v26);
          }
          else
          {
            UFG::Ragdoll::SetDynamic(v1, v25, v20, 8u);
          }
          UFG::Ragdoll::SetMotorState(v1, v20, 0);
        }
        else
        {
          v28 = v1->mRagdollData.m_pPointer;
          v29 = v1->mCollisionSystem << 6;
          v32 = __OFSUB__(v20, v28->mLastCoreRagdollBone);
          v30 = v20 == v28->mLastCoreRagdollBone;
          v31 = (signed int)(v20 - v28->mLastCoreRagdollBone) < 0;
          v33 = v28->mCollisionFilterInfo.p[v20];
          v34 = v28->mCollisionFilterInfo.p[v20];
          v35 = (unsigned __int8)v25->m_motion.m_type.m_storage;
          if ( (unsigned __int8)(v31 ^ v32) | v30 )
          {
            v36 = 32 * ((v34 >> 5) & 0x1F | 32 * ((v33 >> 10) & 0x1F | v29)) | 7;
            if ( (_BYTE)v35 == 5 || (_BYTE)v35 == 4 || v25->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo != v36 )
            {
              hkpRigidBody::setMotionType(v25, MOTION_DYNAMIC, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
              v25->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v36;
              v37 = v25->m_world;
              if ( v37 )
                hkpWorld::updateCollisionFilterOnEntity(
                  v37,
                  (hkpEntity *)&v25->vfptr,
                  0,
                  HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
            }
            UFG::Ragdoll::SetMotorState(v1, v20, 1);
          }
          else
          {
            v38 = 32 * ((v34 >> 5) & 0x1F | 32 * ((v33 >> 10) & 0x1F | v29)) | 0x15;
            if ( (_BYTE)v35 != 5 && (_BYTE)v35 != 4 && v25->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo == v38 )
              goto LABEL_67;
            hkpRigidBody::setMotionType(v25, MOTION_DYNAMIC, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
            v25->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v38;
            v39 = v25->m_world;
            if ( v39 )
              hkpWorld::updateCollisionFilterOnEntity(
                v39,
                (hkpEntity *)&v25->vfptr,
                0,
                HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
          }
        }
        v19 = *(hkArray<enum DetectRagdollPenetration::BonePenetrationStatus,hkContainerHeapAllocator> **)&v47.m_enum;
LABEL_67:
        ++v20;
        ++v22;
        ++v21;
      }
      while ( (signed int)v20 < v1->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size );
    }
    hkaPose::~hkaPose(&ragdollPoseIn);
  }
}

// File Line: 1038
// RVA: 0xB5270
void __fastcall UFG::Ragdoll::UpdatePoweredTracking(UFG::Ragdoll *this, hkaSkeleton *skel, hkaPose *pose)
{
  UFG::Ragdoll *v3; // r12
  hkaSkeleton *v4; // r13
  int v5; // er15
  hkLifoAllocator *v6; // rax
  signed int v7; // er14
  int v8; // edi
  hkQsTransformf *v9; // rsi
  char *v10; // rcx
  hkLifoAllocator *v11; // rax
  hkQsTransformf *v12; // rbp
  char *v13; // rcx
  hkQsTransformf *v14; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v15; // rax
  hkLifoAllocator *v16; // rax
  hkLifoAllocator *v17; // rax
  hkaPose *v18; // [rsp+A0h] [rbp+18h]

  v18 = pose;
  v3 = this;
  v4 = this->mRagdollInstance->m_skeleton.m_pntr;
  v5 = v4->m_bones.m_size;
  v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (48 * v5 + 127) & 0xFFFFFF80;
  v8 = (v7 + 15) & 0xFFFFFFF0;
  v9 = (hkQsTransformf *)v6->m_cur;
  v10 = (char *)v9 + v8;
  if ( v8 > v6->m_slabSize || v10 > v6->m_end )
    v9 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
  else
    v6->m_cur = v10;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkQsTransformf *)v11->m_cur;
  v13 = (char *)v12 + v8;
  if ( v8 > v11->m_slabSize || v13 > v11->m_end )
    v12 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v11, v8);
  else
    v11->m_cur = v13;
  hkaSkeletonUtils::transformLocalPoseToModelPose(v5, v4->m_parentIndices.m_data, v4->m_referencePose.m_data, v9);
  v14 = v4->m_referencePose.m_data;
  v15 = hkaPose::getSyncedPoseModelSpace(v18);
  hkaSkeletonMapper::mapPose(v3->mRagdollData.m_pPointer->highResToRagdollMapper, v15->m_data, v14, v9, CURRENT_POSE);
  hkaSkeletonUtils::transformModelPoseToLocalPose(v5, v4->m_parentIndices.m_data, v9, v12);
  UFG::Ragdoll::UpdatePenetrationRecovery(v3);
  hkaRagdollPoweredConstraintController::driveToPose(v3->mRagdollInstance, v12);
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v7 > v16->m_slabSize || (char *)v12 + v8 != v16->m_cur || v16->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v16, v12, v8);
  else
    v16->m_cur = v12;
  v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v7 > v17->m_slabSize || (char *)v9 + v8 != v17->m_cur || v17->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(v17, v9, v8);
  else
    v17->m_cur = v9;
}

// File Line: 1065
// RVA: 0xB2780
void __fastcall UFG::Ragdoll::SetVelocity(UFG::Ragdoll *this, UFG::qVector3 *v)
{
  int v2; // er14
  UFG::qVector3 *v3; // rbp
  UFG::Ragdoll *v4; // rdi
  __int64 v5; // rsi
  hkaRagdollInstance *v6; // rdx
  __int64 v7; // rcx
  hkpEntity *v8; // rbx
  __m128 v9; // [rsp+20h] [rbp-18h]

  v2 = 0;
  v3 = v;
  v4 = this;
  if ( this->mRagdollData.m_pPointer->mLastCoreRagdollBone >= 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->mRagdollInstance;
      v7 = v6->m_boneToRigidBodyMap.m_data[v5];
      if ( (signed int)v7 >= 0 )
        v8 = (hkpEntity *)&v6->m_rigidBodies.m_data[v7]->vfptr;
      else
        v8 = 0i64;
      v9 = _mm_unpacklo_ps(
             _mm_unpacklo_ps((__m128)LODWORD(v3->x), (__m128)LODWORD(v3->z)),
             _mm_unpacklo_ps((__m128)LODWORD(v3->y), (__m128)0i64));
      hkpEntity::activate(v8);
      v8->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v8->m_motion.vfptr, (unsigned int)&v9);
      ++v2;
      ++v5;
    }
    while ( v2 <= v4->mRagdollData.m_pPointer->mLastCoreRagdollBone );
  }
}

// File Line: 1082
// RVA: 0xB06F0
void __fastcall UFG::Ragdoll::SetCollisionState(UFG::Ragdoll *this, UFG::Ragdoll::CollisionState state)
{
  hkaRagdollInstance *v2; // rax
  __int64 v3; // rsi
  UFG::Ragdoll::CollisionState v4; // er15
  UFG::Ragdoll *v5; // rbp
  __int64 v6; // r14
  hkaRagdollInstance *v7; // rbx
  __int64 v8; // rcx
  hkpRigidBody *v9; // rbx
  UFG::RagdollData *v10; // rdx
  unsigned int v11; // edx
  int v12; // edi
  hkpMotion::MotionType v13; // edx
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned int v16; // edx
  unsigned int v17; // edx
  hkpWorld *v18; // rcx

  v2 = this->mRagdollInstance;
  this->mCollisionState = state;
  v3 = 0i64;
  v4 = state;
  v5 = this;
  if ( v2->m_skeleton.m_pntr->m_bones.m_size > 0 )
  {
    v6 = 0i64;
    while ( 1 )
    {
      v7 = v5->mRagdollInstance;
      v8 = v7->m_boneToRigidBodyMap.m_data[v6];
      v9 = (signed int)v8 >= 0 ? v7->m_rigidBodies.m_data[v8] : 0i64;
      v10 = v5->mRagdollData.m_pPointer;
      if ( (signed int)v3 > v10->mLastCoreRagdollBone )
        break;
      switch ( v4 )
      {
        case 0:
          v16 = v10->mCollisionFilterInfo.p[v3];
          v12 = 32 * ((v16 >> 5) & 0x1F | 32 * ((v16 >> 10) & 0x1F | (v5->mCollisionSystem << 6))) | 7;
          goto LABEL_19;
        case 1:
          v15 = v10->mCollisionFilterInfo.p[v3];
          v12 = 32 * ((v15 >> 5) & 0x1F | 32 * ((v5->mCollisionSystem << 6) | (v15 >> 10) & 0x1F)) | 7;
          goto LABEL_12;
        case 2:
          v14 = v10->mCollisionFilterInfo.p[v3];
          v12 = 32 * ((v14 >> 5) & 0x1F | 32 * ((v5->mCollisionSystem << 6) | (v14 >> 10) & 0x1F)) | 8;
          goto LABEL_12;
        case 3:
          v11 = v10->mCollisionFilterInfo.p[v3];
          v12 = 32 * ((v11 >> 5) & 0x1F | 32 * ((v5->mCollisionSystem << 6) | (v11 >> 10) & 0x1F)) | 0x15;
LABEL_12:
          if ( (unsigned __int8)(v9->m_motion.m_type.m_storage - 4) <= 1u
            && v9->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo == v12 )
          {
            break;
          }
          v13 = 4;
LABEL_22:
          hkpRigidBody::setMotionType(v9, v13, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
          v18 = v9->m_world;
          v9->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v12;
          if ( v18 )
            hkpWorld::updateCollisionFilterOnEntity(
              v18,
              (hkpEntity *)&v9->vfptr,
              0,
              HK_UPDATE_COLLECTION_FILTER_PROCESS_SHAPE_COLLECTIONS);
          break;
      }
LABEL_24:
      v3 = (unsigned int)(v3 + 1);
      ++v6;
      if ( (signed int)v3 >= v5->mRagdollInstance->m_skeleton.m_pntr->m_bones.m_size )
        return;
    }
    v17 = v10->mCollisionFilterInfo.p[v3];
    v12 = 32 * ((v17 >> 5) & 0x1F | 32 * ((v5->mCollisionSystem << 6) | (v17 >> 10) & 0x1F)) | 0x15;
LABEL_19:
    if ( (unsigned __int8)(v9->m_motion.m_type.m_storage - 4) > 1u
      && v9->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo == v12 )
    {
      goto LABEL_24;
    }
    v13 = 1;
    goto LABEL_22;
  }
}

// File Line: 1123
// RVA: 0xB26D0
void __fastcall UFG::Ragdoll::SetUserData(UFG::Ragdoll *this, UFG::SimComponent *component)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::SimComponent *v3; // r11
  UFG::Ragdoll *v4; // r10
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  hkaRagdollInstance *v8; // rdx
  int v9; // er9
  __int64 v10; // r8
  __int64 v11; // rcx
  hkpRigidBody *v12; // rcx
  signed __int64 v13; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mUserData.simComponent.mPrev;
  v3 = component;
  v4 = this;
  if ( this->mUserData.simComponent.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = this->mUserData.simComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = v2;
    this->mUserData.simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mUserData.simComponent.mPrev;
  }
  this->mUserData.simComponent.m_pPointer = component;
  if ( component )
  {
    v7 = component->m_SafePointerList.mNode.mPrev;
    v7->mNext = v2;
    v2->mPrev = v7;
    this->mUserData.simComponent.mNext = &component->m_SafePointerList.mNode;
    component->m_SafePointerList.mNode.mPrev = v2;
  }
  v8 = this->mRagdollInstance;
  v9 = 0;
  if ( v8->m_skeleton.m_pntr->m_bones.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = v8->m_boneToRigidBodyMap.m_data[v10];
      if ( (signed int)v11 >= 0 )
        v12 = v8->m_rigidBodies.m_data[v11];
      else
        v12 = 0i64;
      if ( v3 )
        v13 = (signed __int64)&v4->mUserData;
      else
        v13 = 0i64;
      v12->m_userData = v13;
      v8 = v4->mRagdollInstance;
      ++v9;
      ++v10;
    }
    while ( v9 < v8->m_skeleton.m_pntr->m_bones.m_size );
  }
}

// File Line: 1136
// RVA: 0xB1280
void __fastcall UFG::Ragdoll::SetFriction(UFG::Ragdoll *this, float mu)
{
  hkaRagdollInstance *v2; // rdx
  int v3; // edi
  UFG::Ragdoll *v4; // rsi
  __int64 v5; // rbx
  __int64 v6; // rcx
  hkpRigidBody *v7; // rcx

  v2 = this->mRagdollInstance;
  v3 = 0;
  v4 = this;
  if ( v2->m_skeleton.m_pntr->m_bones.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v2->m_boneToRigidBodyMap.m_data[v5];
      if ( (signed int)v6 >= 0 )
        v7 = v2->m_rigidBodies.m_data[v6];
      else
        v7 = 0i64;
      hkpRigidBody::setFriction(v7, mu);
      v2 = v4->mRagdollInstance;
      ++v3;
      ++v5;
    }
    while ( v3 < v2->m_skeleton.m_pntr->m_bones.m_size );
  }
}

// File Line: 1148
// RVA: 0xB03F0
void __fastcall UFG::Ragdoll::ScaleMass(UFG::Ragdoll *this, float mu)
{
  UFG::Ragdoll *v2; // rbp
  hkaRagdollInstance *v3; // rdx
  int v4; // esi
  __int64 v5; // rdi
  __int64 v6; // rcx
  hkpRigidBody *v7; // rbx
  float v8; // xmm0_4

  v2 = this;
  if ( mu >= 0.001 )
  {
    v3 = this->mRagdollInstance;
    v4 = 0;
    if ( v3->m_skeleton.m_pntr->m_bones.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        v6 = v3->m_boneToRigidBodyMap.m_data[v5];
        if ( (signed int)v6 >= 0 )
          v7 = v3->m_rigidBodies.m_data[v6];
        else
          v7 = 0i64;
        v8 = hkpMotion::getMass((hkpMotion *)&v7->m_motion.vfptr);
        hkpRigidBody::setMass(v7, v8 * mu);
        v3 = v2->mRagdollInstance;
        ++v4;
        ++v5;
      }
      while ( v4 < v3->m_skeleton.m_pntr->m_bones.m_size );
    }
  }
}

// File Line: 1170
// RVA: 0xAB150
void __fastcall UFG::Ragdoll::GetPelvisTransformWS(UFG::Ragdoll *this, UFG::qMatrix44 *transformWS)
{
  hkaRagdollInstance *v2; // r8
  __int64 v3; // rcx
  hkpRigidBody *v4; // rax
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm3
  hkVector4f v7; // xmm0
  hkTransformf v8; // [rsp+20h] [rbp-48h]

  v2 = this->mRagdollInstance;
  v3 = *v2->m_boneToRigidBodyMap.m_data;
  if ( (signed int)v3 >= 0 )
    v4 = v2->m_rigidBodies.m_data[v3];
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
  hkaRagdollInstance *v2; // r14
  UFG::Ragdoll *v3; // rsi
  __int64 v4; // rdi
  hkpConstraintInstance *v5; // rcx
  hkaRagdollInstance *v6; // rcx
  hkpEaseConstraintsAction *v7; // rcx
  hkpWorld *v8; // rax

  v1 = 0;
  v2 = this->mRagdollInstance;
  v3 = this;
  if ( this->mRagdollData.m_pPointer->mLastCoreRagdollConstraint >= 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = v2->m_constraints.m_data[v4];
      if ( v5 )
        hkpConstraintInstance::enable(v5);
      ++v1;
      ++v4;
    }
    while ( v1 <= v3->mRagdollData.m_pPointer->mLastCoreRagdollConstraint );
  }
  v6 = v3->mRagdollInstance;
  if ( v6 && hkaRagdollInstance::getWorld(v6) )
  {
    v7 = v3->mEaseConstraintsAction;
    if ( !v7->m_world )
    {
      hkpEaseConstraintsAction::loosenConstraints(v7);
      hkpEaseConstraintsAction::restoreConstraints(v3->mEaseConstraintsAction, 0.5);
      v8 = hkaRagdollInstance::getWorld(v3->mRagdollInstance);
      hkpWorld::addAction(v8, (hkpAction *)&v3->mEaseConstraintsAction->vfptr);
    }
  }
}

// File Line: 1217
// RVA: 0xA7440
void __fastcall UFG::Ragdoll::DisableConstraints(UFG::Ragdoll *this)
{
  hkaRagdollInstance *v1; // r14
  int v2; // ebx
  UFG::Ragdoll *v3; // rsi
  __int64 v4; // rdi
  hkpConstraintInstance *v5; // rcx

  v1 = this->mRagdollInstance;
  v2 = 0;
  v3 = this;
  if ( this->mRagdollData.m_pPointer->mLastCoreRagdollConstraint >= 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = v1->m_constraints.m_data[v4];
      if ( v5 )
        hkpConstraintInstance::disable(v5);
      ++v2;
      ++v4;
    }
    while ( v2 <= v3->mRagdollData.m_pPointer->mLastCoreRagdollConstraint );
  }
}

// File Line: 1235
// RVA: 0xB1640
void __fastcall UFG::Ragdoll::SetMotorMaxForce(UFG::Ragdoll *this, float force)
{
  UFG::Ragdoll *v2; // r15
  hkLifoAllocator *v3; // rax
  char *v4; // rcx
  unsigned __int64 v5; // rdx
  signed int v6; // er14
  hkaRagdollInstance *v7; // rdx
  signed __int64 v8; // rsi
  int v9; // ecx
  hkpConstraintInstance *v10; // rax
  hkpRagdollConstraintData *v11; // rdi
  int v12; // eax
  hkpConstraintMotor *v13; // rax
  hkpConstraintMotor *v14; // rbx
  int v15; // edx
  __int64 v16; // rcx
  int v17; // er9
  _QWORD *v18; // r8
  hkpConstraintMotor *v19; // rax
  hkpConstraintMotor *v20; // rbx
  int v21; // edx
  __int64 v22; // rcx
  int v23; // er9
  _QWORD *v24; // r8
  hkpConstraintMotor *v25; // rax
  hkpConstraintMotor *v26; // rbx
  int v27; // er9
  __int64 v28; // rdx
  int v29; // er8
  bool v30; // zf
  int v31; // edx
  __int64 v32; // rcx
  int v33; // er9
  __int64 v34; // rdx
  char *v35; // rdi
  int v36; // ecx
  int v37; // ebx
  hkLifoAllocator *v38; // rax
  signed int v39; // ebx
  int v40; // er8
  _QWORD *array; // [rsp+28h] [rbp-38h]
  int v42; // [rsp+30h] [rbp-30h]
  int v43; // [rsp+34h] [rbp-2Ch]
  void *p; // [rsp+38h] [rbp-28h]
  int v45; // [rsp+40h] [rbp-20h]

  v2 = this;
  array = 0i64;
  v42 = 0;
  v43 = 2147483648;
  v45 = 26;
  v3 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (char *)v3->m_cur;
  v5 = (unsigned __int64)(v4 + 256);
  if ( v3->m_slabSize < 256 || (void *)v5 > v3->m_end )
    v4 = (char *)hkLifoAllocator::allocateFromNewSlab(v3, 256);
  else
    v3->m_cur = (void *)v5;
  array = v4;
  v43 = -2147483622;
  p = v4;
  v6 = 1;
  v7 = v2->mRagdollInstance;
  if ( v7->m_skeleton.m_pntr->m_bones.m_size > 1 )
  {
    v8 = 1i64;
    while ( 1 )
    {
      v9 = v7->m_boneToRigidBodyMap.m_data[v8] - 1;
      if ( v9 >= 0 )
        v10 = v7->m_constraints.m_data[v9];
      else
        v10 = 0i64;
      v11 = (hkpRagdollConstraintData *)v10->m_data;
      v12 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))v11->vfptr[1].__first_virtual_table_function__)(v11);
      if ( v12 == 2 )
      {
        v26 = (hkpConstraintMotor *)v11->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
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
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
            v29 = v42;
          }
          array[v29] = v26;
          v29 = v42++ + 1;
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
        v13 = hkpRagdollConstraintData::getPlaneMotor(v11);
        v14 = v13;
        if ( v13 )
        {
          v15 = 0;
          v16 = 0i64;
          v17 = v42;
          v18 = array;
          if ( v42 <= 0 )
            goto LABEL_18;
          while ( (hkpConstraintMotor *)array[v16] != v13 )
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
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
              v17 = v42;
              v18 = array;
            }
            v18[v17] = v14;
            ++v42;
          }
        }
        v19 = hkpRagdollConstraintData::getConeMotor(v11);
        v20 = v19;
        if ( v19 )
        {
          v21 = 0;
          v22 = 0i64;
          v23 = v42;
          v24 = array;
          if ( v42 <= 0 )
            goto LABEL_27;
          while ( (hkpConstraintMotor *)array[v22] != v19 )
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
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
              v23 = v42;
              v24 = array;
            }
            v24[v23] = v20;
            ++v42;
          }
        }
        v25 = hkpRagdollConstraintData::getTwistMotor(v11);
        v26 = v25;
        if ( !v25 )
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
        while ( (hkpConstraintMotor *)array[v28] != v25 )
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
      v7 = v2->mRagdollInstance;
      if ( v6 >= v7->m_skeleton.m_pntr->m_bones.m_size )
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v43);
}

// File Line: 1291
// RVA: 0xAA9D0
float __fastcall UFG::Ragdoll::GetMotorMaxForce(UFG::Ragdoll *this)
{
  hkaRagdollInstance *v1; // rdx
  signed int v2; // edi
  UFG::Ragdoll *v3; // rbp
  signed __int64 v4; // rsi
  int v5; // ecx
  hkpConstraintInstance *v6; // rbx
  hkpRagdollConstraintData *v7; // rbx
  int v8; // eax
  hkpConstraintMotor *v9; // rax

  v1 = this->mRagdollInstance;
  v2 = 1;
  v3 = this;
  if ( v1->m_skeleton.m_pntr->m_bones.m_size <= 1 )
    return 0.0;
  v4 = 1i64;
  while ( 1 )
  {
    v5 = v1->m_boneToRigidBodyMap.m_data[v4] - 1;
    v6 = v5 >= 0 ? v1->m_constraints.m_data[v5] : 0i64;
    v7 = (hkpRagdollConstraintData *)v6->m_data;
    v8 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))v7->vfptr[1].__first_virtual_table_function__)(v7);
    if ( v8 != 2 )
      break;
    v9 = (hkpConstraintMotor *)v7->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
LABEL_12:
    if ( v9 )
      return *((float *)&v9[1].vfptr + 1);
LABEL_13:
    v1 = v3->mRagdollInstance;
    ++v2;
    ++v4;
    if ( v2 >= v1->m_skeleton.m_pntr->m_bones.m_size )
      return 0.0;
  }
  if ( v8 != 7 )
    goto LABEL_13;
  v9 = hkpRagdollConstraintData::getPlaneMotor(v7);
  if ( !v9 )
  {
    v9 = hkpRagdollConstraintData::getConeMotor(v7);
    if ( !v9 )
    {
      v9 = hkpRagdollConstraintData::getTwistMotor(v7);
      goto LABEL_12;
    }
  }
  return *((float *)&v9[1].vfptr + 1);
}

// File Line: 1326
// RVA: 0xB19E0
void __fastcall UFG::Ragdoll::SetMotorMaxForceAtJoint(UFG::Ragdoll *this, float force, int skeletonBoneID)
{
  hkaRagdollInstance *v3; // r10
  hkpConstraintInstance *v4; // rbx
  hkaSkeletonMapper *v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // r9
  hkaSkeletonMapperData::SimpleMapping *v8; // rcx
  int v9; // edx
  hkpRagdollConstraintData *v10; // rbx
  int v11; // eax
  hkpConstraintMotor *v12; // rax
  hkpConstraintMotor *v13; // rax
  hkpConstraintMotor *v14; // rax

  v3 = this->mRagdollInstance;
  if ( v3 )
  {
    v4 = 0i64;
    v5 = this->mRagdollData.m_pPointer->highResToRagdollMapper;
    v6 = 0i64;
    v7 = v5->m_mapping.m_simpleMappings.m_size;
    if ( v7 > 0 )
    {
      v8 = v5->m_mapping.m_simpleMappings.m_data;
      while ( v8->m_boneA != skeletonBoneID )
      {
        ++v6;
        ++v8;
        if ( v6 >= v7 )
          return;
      }
      if ( v8->m_boneB != -1 )
      {
        v9 = v3->m_boneToRigidBodyMap.m_data[v8->m_boneB] - 1;
        if ( v9 >= 0 )
          v4 = v3->m_constraints.m_data[v9];
        v10 = (hkpRagdollConstraintData *)v4->m_data;
        v11 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))v10->vfptr[1].__first_virtual_table_function__)(v10);
        if ( v11 == 2 )
        {
          v14 = (hkpConstraintMotor *)v10->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
        }
        else
        {
          if ( v11 != 7 )
            return;
          v12 = hkpRagdollConstraintData::getPlaneMotor(v10);
          if ( v12 )
            *((float *)&v12[1].vfptr + 1) = force;
          v13 = hkpRagdollConstraintData::getConeMotor(v10);
          if ( v13 )
            *((float *)&v13[1].vfptr + 1) = force;
          v14 = hkpRagdollConstraintData::getTwistMotor(v10);
        }
        if ( v14 )
          *((float *)&v14[1].vfptr + 1) = force;
      }
    }
  }
}

// File Line: 1376
// RVA: 0xAAAA0
float __fastcall UFG::Ragdoll::GetMotorMaxForceAtJoint(UFG::Ragdoll *this, int boneIndex)
{
  hkaRagdollInstance *v2; // r8
  int v3; // edx
  hkpConstraintInstance *v4; // rbx
  hkpRagdollConstraintData *v5; // rbx
  int v6; // eax
  hkpConstraintMotor *v7; // rax
  hkpConstraintMotor *v8; // rax

  v2 = this->mRagdollInstance;
  v3 = v2->m_boneToRigidBodyMap.m_data[boneIndex] - 1;
  if ( v3 >= 0 )
    v4 = v2->m_constraints.m_data[v3];
  else
    v4 = 0i64;
  v5 = (hkpRagdollConstraintData *)v4->m_data;
  v6 = ((__int64 (__fastcall *)(hkpRagdollConstraintData *))v5->vfptr[1].__first_virtual_table_function__)(v5);
  if ( v6 == 2 )
  {
    v7 = (hkpConstraintMotor *)v5->m_atoms.m_ragdollMotors.m_target_bRca.m_col0.m_quad.m128_u64[0];
    if ( v7 )
      return *((float *)&v7[1].vfptr + 1);
  }
  else if ( v6 == 7 )
  {
    v7 = hkpRagdollConstraintData::getPlaneMotor(v5);
    if ( !v7 )
    {
      v7 = hkpRagdollConstraintData::getConeMotor(v5);
      if ( !v7 )
      {
        v8 = hkpRagdollConstraintData::getTwistMotor(v5);
        if ( v8 )
          return *((float *)&v8[1].vfptr + 1);
        return 0.0;
      }
    }
    return *((float *)&v7[1].vfptr + 1);
  }
  return 0.0;
}

// File Line: 1408
// RVA: 0xB1300
void __fastcall UFG::Ragdoll::SetLimitStiffness(UFG::Ragdoll *this, float tau)
{
  hkaRagdollInstance *v2; // rdx
  signed int v3; // edi
  UFG::Ragdoll *v4; // rbp
  signed __int64 v5; // rsi
  int v6; // ecx
  hkpConstraintInstance *v7; // rbx
  float *v8; // rbx
  int v9; // eax

  v2 = this->mRagdollInstance;
  v3 = 1;
  v4 = this;
  if ( v2->m_skeleton.m_pntr->m_bones.m_size > 1 )
  {
    v5 = 1i64;
    do
    {
      v6 = v2->m_boneToRigidBodyMap.m_data[v5] - 1;
      if ( v6 >= 0 )
        v7 = v2->m_constraints.m_data[v6];
      else
        v7 = 0i64;
      v8 = (float *)v7->m_data;
      v9 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v8 + 24i64))(v8);
      if ( v9 == 2 )
      {
        v8[65] = tau;
      }
      else if ( v9 == 7 )
      {
        v8[80] = tau;
        v8[88] = tau;
        v8[96] = tau;
      }
      v2 = v4->mRagdollInstance;
      ++v3;
      ++v5;
    }
    while ( v3 < v2->m_skeleton.m_pntr->m_bones.m_size );
  }
}

// File Line: 1440
// RVA: 0xAA8E0
float __fastcall UFG::Ragdoll::GetLimitStiffness(UFG::Ragdoll *this)
{
  hkaRagdollInstance *v1; // rdx
  signed int v2; // ebx
  UFG::Ragdoll *v3; // rbp
  signed __int64 v4; // rdi
  int v5; // ecx
  hkpConstraintInstance *v6; // rax
  float *v7; // rsi
  int v8; // eax

  v1 = this->mRagdollInstance;
  v2 = 1;
  v3 = this;
  if ( v1->m_skeleton.m_pntr->m_bones.m_size <= 1 )
    return 0.0;
  v4 = 1i64;
  while ( 1 )
  {
    v5 = v1->m_boneToRigidBodyMap.m_data[v4] - 1;
    v6 = v5 >= 0 ? v1->m_constraints.m_data[v5] : 0i64;
    v7 = (float *)v6->m_data;
    v8 = (*(__int64 (__fastcall **)(float *))(*(_QWORD *)v7 + 24i64))(v7);
    if ( v8 == 2 )
      break;
    if ( v8 == 7 )
      return v7[80];
    v1 = v3->mRagdollInstance;
    ++v2;
    ++v4;
    if ( v2 >= v1->m_skeleton.m_pntr->m_bones.m_size )
      return 0.0;
  }
  return v7[65];
}

// File Line: 1470
// RVA: 0xA5F40
void __fastcall UFG::Ragdoll::CreateRagdollPenetrationUtil(UFG::Ragdoll *this, hkpWorld *world)
{
  hkpWorld *v2; // rsi
  UFG::Ragdoll *v3; // rdi
  signed __int64 v4; // rbx
  char v5; // dl
  __int64 v6; // rax
  char v7; // cl
  _QWORD **v8; // rax
  hkpAabbPhantom *v9; // rax
  hkpAabbPhantom *v10; // rax
  char v11; // al
  char v12; // dl
  __int64 v13; // rax
  char v14; // cl
  _QWORD **v15; // rax
  __int64 v16; // rax
  char v17; // al
  hkaRagdollRaycastInterface *v18; // rax
  char v19; // dl
  __int64 v20; // rax
  char v21; // cl
  _QWORD **v22; // rax
  DetectRagdollPenetration *v23; // rax
  DetectRagdollPenetration *v24; // rax
  char v25; // al
  DetectRagdollPenetration::Setup setup; // [rsp+28h] [rbp-40h]
  hkAabb aabb; // [rsp+40h] [rbp-28h]

  v2 = world;
  v3 = this;
  aabb.m_min = (hkVector4f)_xmm;
  aabb.m_max = (hkVector4f)_xmm;
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = ++*(_BYTE *)(v4 + 80);
  v6 = v5;
  *(_DWORD *)(v4 + 4 * v6) = 3;
  *(_QWORD *)(v4 + 8 * v6 + 16) = "hkpAabbPhantom";
  *(_QWORD *)(v4 + 8 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v4 + 81);
  if ( v5 > v7 )
    v7 = v5;
  *(_BYTE *)(v4 + 81) = v7;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 304i64);
  if ( v9 )
    hkpAabbPhantom::hkpAabbPhantom(v9, &aabb, 0xCu);
  else
    v10 = 0i64;
  v3->mPhantom = v10;
  v11 = *(_BYTE *)(v4 + 80);
  if ( v11 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v11 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  v12 = ++*(_BYTE *)(v4 + 80);
  v13 = v12;
  *(_DWORD *)(v4 + 4 * v13) = 3;
  *(_QWORD *)(v4 + 8 * v13 + 16) = "RagdollPenetrationRaycastInterface";
  *(_QWORD *)(v4 + 8 * v13 + 48) = 0i64;
  v14 = *(_BYTE *)(v4 + 81);
  if ( v12 > v14 )
    v14 = v12;
  *(_BYTE *)(v4 + 81) = v14;
  v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(v15[11], 32i64);
  if ( v16 )
  {
    *(_QWORD *)v16 = &hkBaseObject::`vftable;
    *(_QWORD *)v16 = &hkReferencedObject::`vftable;
    *(_DWORD *)(v16 + 8) = 0x1FFFF;
    *(_QWORD *)(v16 + 16) = &hkaRagdollRaycastInterface::`vftable;
    *(_QWORD *)v16 = &UFG::RagdollPenetrationRaycastInterface::`vftable{for `hkReferencedObject};
    *(_QWORD *)(v16 + 16) = &UFG::RagdollPenetrationRaycastInterface::`vftable{for `hkaRagdollRaycastInterface};
    *(_QWORD *)(v16 + 24) = v2;
  }
  else
  {
    v16 = 0i64;
  }
  v3->mRagdollRaycastInterface = (UFG::RagdollPenetrationRaycastInterface *)v16;
  v17 = *(_BYTE *)(v4 + 80);
  if ( v17 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v17 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  setup.m_ragdollSkeleton = v3->mRagdollInstance->m_skeleton.m_pntr;
  v18 = (hkaRagdollRaycastInterface *)v3->mRagdollRaycastInterface;
  if ( v18 )
    setup.m_raycastInterface = v18 + 2;
  else
    setup.m_raycastInterface = 0i64;
  setup.m_ragdollPhantom = v3->mPhantom;
  v19 = ++*(_BYTE *)(v4 + 80);
  v20 = v19;
  *(_DWORD *)(v4 + 4 * v20) = 3;
  *(_QWORD *)(v4 + 8 * v20 + 16) = "DetectRagdollPenetration";
  *(_QWORD *)(v4 + 8 * v20 + 48) = 0i64;
  v21 = *(_BYTE *)(v4 + 81);
  if ( v19 > v21 )
    v21 = v19;
  *(_BYTE *)(v4 + 81) = v21;
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (DetectRagdollPenetration *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(
                                      v22[11],
                                      72i64);
  if ( v23 )
    DetectRagdollPenetration::DetectRagdollPenetration(v23, &setup);
  else
    v24 = 0i64;
  v3->mDetectRagdollPenetration = v24;
  v25 = *(_BYTE *)(v4 + 80);
  if ( v25 > 0 )
  {
    *(_BYTE *)(v4 + 80) = v25 - 1;
  }
  else
  {
    *(_BYTE *)(v4 + 80) = 0;
    *(_DWORD *)v4 = 3;
    *(_QWORD *)(v4 + 16) = 0i64;
    *(_QWORD *)(v4 + 48) = 0i64;
  }
  v3->m_framesSinceInterpenetration = 0;
}

// File Line: 1499
// RVA: 0xB5440
void __fastcall UFG::Ragdoll::UpdateTotalInertia(UFG::Ragdoll *this)
{
  UFG::Ragdoll *v1; // r13
  hkaRagdollInstance *v2; // r15
  __int64 v3; // rsi
  __int64 v4; // r14
  hkpRigidBody *v5; // rdi
  __int64 v6; // kr00_8
  __int128 v7; // xmm9
  __int128 v8; // xmm10
  __int128 v9; // xmm11
  __int128 v10; // xmm12
  hkVector4f v11; // xmm13
  hkVector4f v12; // xmm14
  hkVector4f v13; // xmm15
  hkVector4f v14; // xmm0
  int v15; // ecx
  signed __int64 v16; // rcx
  bool v17; // zf
  __int64 v18; // rcx
  char *array; // [rsp+28h] [rbp-A0h]
  int v20; // [rsp+30h] [rbp-98h]
  int v21; // [rsp+34h] [rbp-94h]
  char v22[24]; // [rsp+40h] [rbp-88h]
  char v23[24]; // [rsp+58h] [rbp-70h]
  __int128 v24; // [rsp+70h] [rbp-58h]
  hkResult result[2]; // [rsp+148h] [rbp+80h]
  __int64 v26; // [rsp+150h] [rbp+88h]

  v1 = this;
  array = 0i64;
  v20 = 0;
  v21 = 2147483648;
  v2 = this->mRagdollInstance;
  v3 = 0i64;
  v4 = v2->m_rigidBodies.m_size;
  if ( v4 > 0 )
  {
    do
    {
      v5 = v2->m_rigidBodies.m_data[v3];
      *(_OWORD *)&v23[8] = 0i64;
      v24 = 0i64;
      *(_OWORD *)&v22[8] = 0i64;
      *(_OWORD *)v23 = 0i64;
      *(_DWORD *)&v22[20] = hkpMotion::getMass((hkpMotion *)&v5->m_motion.vfptr);
      *(hkVector4f *)&v23[8] = v5->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal;
      ((void (__fastcall *)(hkpMaxSizeMotion *, __int128 *))v5->m_motion.vfptr[3].__first_virtual_table_function__)(
        &v5->m_motion,
        &v24);
      v6 = *(_QWORD *)&v22[16];
      v7 = *(_OWORD *)&v23[8];
      v8 = v24;
      v9 = *(_OWORD *)&v22[8];
      v10 = *(_OWORD *)v23;
      v11.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col0;
      v12.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col1;
      v13.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_rotation.m_col2;
      v14.m_quad = (__m128)v5->m_motion.m_motionState.m_transform.m_translation;
      *(hkVector4f *)v22 = v5->m_motion.m_motionState.m_transform.m_translation;
      v15 = v20;
      if ( v20 == (v21 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 144);
        v15 = v20;
        v14.m_quad = *(__m128 *)v22;
      }
      v16 = 144i64 * v15;
      v17 = &array[v16] == 0i64;
      v18 = (__int64)&array[v16];
      *(_QWORD *)&result[0].m_enum = v18;
      v26 = v18;
      if ( !v17 )
      {
        *(_QWORD *)v18 = v6;
        *(_OWORD *)(v18 + 16) = v7;
        *(_OWORD *)(v18 + 32) = v8;
        *(_OWORD *)(v18 + 48) = v9;
        *(_OWORD *)(v18 + 64) = v10;
        *(hkVector4f *)(v18 + 80) = (hkVector4f)v11.m_quad;
        *(hkVector4f *)(v18 + 96) = (hkVector4f)v12.m_quad;
        *(hkVector4f *)(v18 + 112) = (hkVector4f)v13.m_quad;
        *(hkVector4f *)(v18 + 128) = (hkVector4f)v14.m_quad;
      }
      ++v20;
      ++v3;
    }
    while ( v3 < v4 );
  }
  hkInertiaTensorComputer::combineMassProperties(
    result,
    (hkArray<hkMassElement,hkContainerHeapAllocator> *)&array,
    &v1->mMassProperties);
  v20 = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      144 * (v21 & 0x3FFFFFFF));
}

// File Line: 1527
// RVA: 0xA66E0
void __usercall UFG::Ragdoll::DampMotionOfExtremities(UFG::Ragdoll *this@<rcx>, float deltaT@<xmm1>, __m128 a3@<xmm6>)
{
  UFG::Ragdoll *v3; // rsi
  hkaSkeleton *v4; // r13
  float v5; // xmm7_4
  __int64 v6; // r15
  __int64 i; // rdi
  hkaRagdollInstance *v8; // rdx
  __int64 v9; // r8
  __int64 v10; // rbx
  __int64 v11; // rcx
  hkpEntity *v12; // rbp
  hkaRagdollInstance *v13; // rdx
  __int64 v14; // r8
  __m128 *v15; // r14
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // [rsp+20h] [rbp-78h]
  __m128 v22; // [rsp+30h] [rbp-68h]
  hkBool result; // [rsp+A8h] [rbp+10h]

  v3 = this;
  v4 = this->mRagdollInstance->m_skeleton.m_pntr;
  v5 = UFG::gExtremityMotionDecayRate * deltaT;
  if ( (float)(UFG::gExtremityMotionDecayRate * deltaT) > 1.0 )
    v5 = *(float *)&FLOAT_1_0;
  v6 = this->mRagdollData.m_pPointer->mExtremityBoneIndices.size;
  for ( i = 0i64; i < v6; ++i )
  {
    v8 = v3->mRagdollInstance;
    v9 = v3->mRagdollData.m_pPointer->mExtremityBoneIndices.p[i];
    v10 = v9;
    v11 = v8->m_boneToRigidBodyMap.m_data[v9];
    if ( (signed int)v11 >= 0 )
      v12 = (hkpEntity *)&v8->m_rigidBodies.m_data[v11]->vfptr;
    else
      v12 = 0i64;
    if ( UFG::Ragdoll::GetMotorMaxForceAtJoint(v3, v9) < 0.1 && hkpEntity::isActive(v12, &result)->m_bool )
    {
      v13 = v3->mRagdollInstance;
      v14 = v13->m_boneToRigidBodyMap.m_data[v4->m_parentIndices.m_data[v10]];
      if ( (signed int)v14 >= 0 )
        v15 = (__m128 *)v13->m_rigidBodies.m_data[v14];
      else
        v15 = 0i64;
      v16 = v15[35];
      a3.m128_f32[0] = v5;
      v17 = _mm_shuffle_ps(a3, a3, 0);
      v18 = _mm_sub_ps(v12->m_motion.m_linearVelocity.m_quad, v16);
      v21 = _mm_add_ps(_mm_sub_ps(v18, _mm_mul_ps(v17, v18)), v16);
      hkpEntity::activate(v12);
      v12->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v12->m_motion.vfptr, (unsigned int)&v21);
      v19 = v15[36];
      v20 = _mm_sub_ps(v12->m_motion.m_angularVelocity.m_quad, v19);
      a3 = _mm_mul_ps(v17, v20);
      v22 = _mm_add_ps(_mm_sub_ps(v20, a3), v19);
      hkpEntity::activate(v12);
      ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v12->m_motion.vfptr[9].__first_virtual_table_function__)(
        &v12->m_motion,
        &v22);
    }
  }
}

