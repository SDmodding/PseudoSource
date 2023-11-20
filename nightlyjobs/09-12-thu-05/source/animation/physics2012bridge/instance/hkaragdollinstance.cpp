// File Line: 12
// RVA: 0xC52120
void __fastcall hkaRagdollInstance::commonInit(hkaRagdollInstance *this, hkArrayBase<hkpRigidBody *> *rigidBodies, hkArrayBase<hkpConstraintInstance *> *constraints, hkaSkeleton *skeleton)
{
  hkaSkeleton *v4; // rdi
  hkArrayBase<hkpConstraintInstance *> *v5; // r14
  hkArrayBase<hkpRigidBody *> *v6; // rsi
  hkaRagdollInstance *v7; // rbx
  hkReferencedObject *v8; // rcx
  __int64 v9; // rax
  hkpRigidBody **v10; // rcx
  __int64 v11; // rdx
  char *v12; // r8
  hkpRigidBody *v13; // rax
  __int64 v14; // rax
  hkpConstraintInstance **v15; // rcx
  __int64 v16; // rdx
  char *v17; // r8
  hkpConstraintInstance *v18; // rax
  int v19; // edi
  int v20; // esi
  __int64 v21; // r14
  __int64 v22; // rsi
  int v23; // [rsp+30h] [rbp+8h]

  v4 = skeleton;
  v5 = constraints;
  v6 = rigidBodies;
  v7 = this;
  if ( skeleton )
    hkReferencedObject::addReference((hkReferencedObject *)&skeleton->vfptr);
  v8 = (hkReferencedObject *)&v7->m_skeleton.m_pntr->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v7->m_skeleton.m_pntr = v4;
  if ( (v7->m_rigidBodies.m_capacityAndFlags & 0x3FFFFFFF) < v6->m_size )
  {
    if ( v7->m_rigidBodies.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v7->m_rigidBodies.m_data,
        8 * v7->m_rigidBodies.m_capacityAndFlags);
    v23 = 8 * v6->m_size;
    v7->m_rigidBodies.m_data = (hkpRigidBody **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                  &v23);
    v7->m_rigidBodies.m_capacityAndFlags = v23 / 8;
  }
  v9 = v6->m_size;
  v10 = v7->m_rigidBodies.m_data;
  v7->m_rigidBodies.m_size = v9;
  v11 = v9;
  if ( (signed int)v9 > 0 )
  {
    v12 = (char *)((char *)v6->m_data - (char *)v10);
    do
    {
      v13 = *(hkpRigidBody **)((char *)v10 + (_QWORD)v12);
      ++v10;
      *(v10 - 1) = v13;
      --v11;
    }
    while ( v11 );
  }
  if ( (v7->m_constraints.m_capacityAndFlags & 0x3FFFFFFF) < v5->m_size )
  {
    if ( v7->m_constraints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v7->m_constraints.m_data,
        8 * v7->m_constraints.m_capacityAndFlags);
    v23 = 8 * v5->m_size;
    v7->m_constraints.m_data = (hkpConstraintInstance **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                           &v23);
    v7->m_constraints.m_capacityAndFlags = v23 / 8;
  }
  v14 = v5->m_size;
  v15 = v7->m_constraints.m_data;
  v7->m_constraints.m_size = v14;
  v16 = v14;
  if ( (signed int)v14 > 0 )
  {
    v17 = (char *)((char *)v5->m_data - (char *)v15);
    do
    {
      v18 = *(hkpConstraintInstance **)((char *)v15 + (_QWORD)v17);
      ++v15;
      *(v15 - 1) = v18;
      --v16;
    }
    while ( v16 );
  }
  v19 = 0;
  v20 = 0;
  if ( v7->m_rigidBodies.m_size > 0 )
  {
    v21 = 0i64;
    do
    {
      hkReferencedObject::addReference((hkReferencedObject *)&v7->m_rigidBodies.m_data[v21]->vfptr);
      ++v20;
      ++v21;
    }
    while ( v20 < v7->m_rigidBodies.m_size );
  }
  if ( v7->m_constraints.m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      hkReferencedObject::addReference((hkReferencedObject *)&v7->m_constraints.m_data[v22]->vfptr);
      ++v19;
      ++v22;
    }
    while ( v19 < v7->m_constraints.m_size );
  }
}

// File Line: 31
// RVA: 0xC50430
void __fastcall hkaRagdollInstance::hkaRagdollInstance(hkaRagdollInstance *this, hkArrayBase<hkpRigidBody *> *rigidBodies, hkArrayBase<hkpConstraintInstance *> *constraints, hkaSkeleton *skeleton)
{
  int v4; // ebx
  hkaSkeleton *v5; // rsi
  hkaRagdollInstance *v6; // r14
  int v7; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // er9
  __int64 v11; // rcx
  hkResult result; // [rsp+50h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaRagdollInstance::`vftable';
  this->m_rigidBodies.m_data = 0i64;
  this->m_rigidBodies.m_size = 0;
  this->m_rigidBodies.m_capacityAndFlags = 2147483648;
  this->m_constraints.m_data = 0i64;
  this->m_constraints.m_size = 0;
  this->m_constraints.m_capacityAndFlags = 2147483648;
  this->m_boneToRigidBodyMap.m_data = 0i64;
  this->m_boneToRigidBodyMap.m_size = 0;
  this->m_boneToRigidBodyMap.m_capacityAndFlags = 2147483648;
  v5 = skeleton;
  v6 = this;
  this->m_skeleton.m_pntr = 0i64;
  hkaRagdollInstance::commonInit(this, rigidBodies, constraints, skeleton);
  v7 = v5->m_bones.m_size;
  v8 = v6->m_boneToRigidBodyMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v7 )
  {
    v9 = 2 * v8;
    v10 = v5->m_bones.m_size;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v6->m_boneToRigidBodyMap,
      v10,
      4);
  }
  v6->m_boneToRigidBodyMap.m_size = v7;
  if ( v5->m_bones.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      ++v11;
      v6->m_boneToRigidBodyMap.m_data[v11 - 1] = v4++;
    }
    while ( v4 < v5->m_bones.m_size );
  }
}

// File Line: 45
// RVA: 0xC50510
void __fastcall hkaRagdollInstance::hkaRagdollInstance(hkaRagdollInstance *this, hkArrayBase<hkpRigidBody *> *rigidBodies, hkArrayBase<hkpConstraintInstance *> *constraints, hkaSkeleton *skeleton, hkArrayBase<int> *boneToRigidBodyMap)
{
  hkaRagdollInstance *v5; // rbx
  hkArrayBase<int> *v6; // rdi
  __int64 v7; // rcx
  int *v8; // rax
  __int64 v9; // rdx
  char *v10; // r8
  int v11; // ecx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v5 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaRagdollInstance::`vftable';
  this->m_rigidBodies.m_capacityAndFlags = 2147483648;
  this->m_rigidBodies.m_data = 0i64;
  this->m_rigidBodies.m_size = 0;
  this->m_constraints.m_data = 0i64;
  this->m_constraints.m_size = 0;
  this->m_constraints.m_capacityAndFlags = 2147483648;
  this->m_boneToRigidBodyMap.m_data = 0i64;
  this->m_boneToRigidBodyMap.m_size = 0;
  this->m_boneToRigidBodyMap.m_capacityAndFlags = 2147483648;
  this->m_skeleton.m_pntr = 0i64;
  hkaRagdollInstance::commonInit(this, rigidBodies, constraints, skeleton);
  v6 = boneToRigidBodyMap;
  if ( (v5->m_boneToRigidBodyMap.m_capacityAndFlags & 0x3FFFFFFF) < boneToRigidBodyMap->m_size )
  {
    if ( v5->m_boneToRigidBodyMap.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v5->m_boneToRigidBodyMap.m_data,
        4 * v5->m_boneToRigidBodyMap.m_capacityAndFlags);
    LODWORD(boneToRigidBodyMap) = 4 * v6->m_size;
    v5->m_boneToRigidBodyMap.m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                               (int *)&boneToRigidBodyMap);
    v5->m_boneToRigidBodyMap.m_capacityAndFlags = (signed int)boneToRigidBodyMap / 4;
  }
  v7 = v6->m_size;
  v8 = v5->m_boneToRigidBodyMap.m_data;
  v5->m_boneToRigidBodyMap.m_size = v7;
  v9 = v7;
  if ( (signed int)v7 > 0 )
  {
    v10 = (char *)((char *)v6->m_data - (char *)v8);
    do
    {
      v11 = *(int *)((char *)v8 + (_QWORD)v10);
      ++v8;
      *(v8 - 1) = v11;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 55
// RVA: 0xC52100
void __fastcall hkaRagdollInstance::hkaRagdollInstance(hkaRagdollInstance *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaRagdollInstance::`vftable';
}

// File Line: 59
// RVA: 0xC50620
void __fastcall hkaRagdollInstance::~hkaRagdollInstance(hkaRagdollInstance *this)
{
  hkaRagdollInstance *v1; // rbx
  int v2; // esi
  __int64 v3; // rdi
  int v4; // edi
  __int64 v5; // rsi
  hkReferencedObject *v6; // rcx
  int v7; // er8
  int v8; // er8
  int v9; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaRagdollInstance::`vftable';
  v2 = 0;
  if ( this->m_rigidBodies.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_rigidBodies.m_data[v3]->vfptr);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_rigidBodies.m_size );
  }
  v4 = 0;
  if ( v1->m_constraints.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_constraints.m_data[v5]->vfptr);
      ++v4;
      ++v5;
    }
    while ( v4 < v1->m_constraints.m_size );
  }
  v6 = (hkReferencedObject *)&v1->m_skeleton.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v1->m_skeleton.m_pntr = 0i64;
  v7 = v1->m_boneToRigidBodyMap.m_capacityAndFlags;
  v1->m_boneToRigidBodyMap.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_boneToRigidBodyMap.m_data,
      4 * v7);
  v1->m_boneToRigidBodyMap.m_data = 0i64;
  v1->m_boneToRigidBodyMap.m_capacityAndFlags = 2147483648;
  v8 = v1->m_constraints.m_capacityAndFlags;
  v1->m_constraints.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_constraints.m_data,
      8 * v8);
  v1->m_constraints.m_data = 0i64;
  v1->m_constraints.m_capacityAndFlags = 2147483648;
  v9 = v1->m_rigidBodies.m_capacityAndFlags;
  v1->m_rigidBodies.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_rigidBodies.m_data,
      8 * v9);
  v1->m_rigidBodies.m_data = 0i64;
  v1->m_rigidBodies.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 71
// RVA: 0xC50BD0
void __fastcall hkaRagdollInstance::getPoseWorldSpace(hkaRagdollInstance *this, hkQsTransformf *poseOut, hkQsTransformf *worldFromModel, hkQsTransformf *localSpacePoseForUnmappedBonesOptional)
{
  hkQsTransformf *v4; // rax
  hkQsTransformf *v5; // r15
  hkQsTransformf *v6; // r13
  hkaRagdollInstance *v7; // rsi
  hkaSkeleton *v8; // r9
  int v9; // ebx
  char *v10; // rdx
  __int64 v11; // rbp
  __int64 v12; // r14
  __m128 *v13; // r12
  __int64 v14; // rcx
  hkpRigidBody *v15; // rdx
  signed __int64 v16; // rcx
  signed __int64 v17; // rcx
  __m128 v18; // xmm8
  __m128 v19; // xmm7
  __m128 v20; // xmm9
  __m128 v21; // xmm3
  __m128 v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm6
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm4
  __m128 v32; // xmm4
  char *v33; // [rsp+90h] [rbp+8h]

  v4 = localSpacePoseForUnmappedBonesOptional;
  v5 = worldFromModel;
  v6 = poseOut;
  v7 = this;
  if ( !localSpacePoseForUnmappedBonesOptional )
    v4 = this->m_skeleton.m_pntr->m_referencePose.m_data;
  v8 = this->m_skeleton.m_pntr;
  v9 = 0;
  if ( v8->m_bones.m_size > 0 )
  {
    v10 = (char *)((char *)poseOut - (char *)v4);
    v11 = 0i64;
    v12 = 0i64;
    v13 = &v4->m_rotation.m_vec.m_quad;
    v33 = v10;
    while ( 1 )
    {
      v14 = v7->m_boneToRigidBodyMap.m_data[v12];
      if ( (signed int)v14 < 0 )
        goto LABEL_9;
      v15 = v7->m_rigidBodies.m_data[v14];
      if ( !v15 )
        break;
      hkQsTransformf::setFromTransformNoScale(&v6[v9], &v15->m_motion.m_motionState.m_transform);
      hkaSkeletonUtils::getModelSpaceScale(
        v7->m_skeleton.m_pntr,
        v7->m_skeleton.m_pntr->m_referencePose.m_data,
        v9,
        &v6[v9].m_scale);
      v10 = v33;
LABEL_13:
      v8 = v7->m_skeleton.m_pntr;
      ++v9;
      ++v12;
      ++v11;
      v13 += 3;
      if ( v9 >= v8->m_bones.m_size )
        return;
    }
    v10 = v33;
LABEL_9:
    v16 = v8->m_parentIndices.m_data[v11];
    if ( (signed int)v16 < 0 )
    {
      v18 = v5->m_translation.m_quad;
      v19 = v5->m_rotation.m_vec.m_quad;
      v20 = v5->m_scale.m_quad;
    }
    else
    {
      v17 = v16;
      v18 = v6[v17].m_translation.m_quad;
      v19 = v6[v17].m_rotation.m_vec.m_quad;
      v20 = v6[v17].m_scale.m_quad;
    }
    v21 = v13[-1];
    v22 = _mm_shuffle_ps(v19, v19, 201);
    v23 = _mm_mul_ps(v19, v21);
    v24 = _mm_shuffle_ps(v19, v19, 255);
    v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13[-1], v21, 201), v19), _mm_mul_ps(v22, v21));
    v26 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                  _mm_shuffle_ps(v23, v23, 170)),
                v19),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v24, v24), (__m128)xmmword_141A711B0), v21)),
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24));
    *(__m128 *)((char *)v13 + (_QWORD)v10 - 16) = _mm_add_ps(_mm_add_ps(v26, v26), v18);
    v27 = _mm_shuffle_ps(*v13, *v13, 255);
    v28 = _mm_mul_ps(_mm_shuffle_ps(*v13, *v13, 201), v19);
    v29 = _mm_mul_ps(v19, v27);
    v30 = _mm_mul_ps(v19, *v13);
    v31 = _mm_sub_ps(v28, _mm_mul_ps(v22, *v13));
    v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v24, *v13)), v29);
    *(__m128 *)((char *)v13 + (_QWORD)v10) = _mm_shuffle_ps(
                                               v32,
                                               _mm_unpackhi_ps(
                                                 v32,
                                                 _mm_sub_ps(
                                                   _mm_mul_ps(v27, v24),
                                                   _mm_add_ps(
                                                     _mm_add_ps(
                                                       _mm_shuffle_ps(v30, v30, 85),
                                                       _mm_shuffle_ps(v30, v30, 0)),
                                                     _mm_shuffle_ps(v30, v30, 170)))),
                                               196);
    *(__m128 *)((char *)v13 + (_QWORD)v10 + 16) = _mm_mul_ps(v13[1], v20);
    goto LABEL_13;
  }
}

// File Line: 107
// RVA: 0xC50BB0
void __fastcall hkaRagdollInstance::getPoseWorldSpace(hkaRagdollInstance *this, hkQsTransformf *poseOut)
{
  hkaRagdollInstance::getPoseWorldSpace(this, poseOut, &hkQsTransformf_identityStorage, 0i64);
}

// File Line: 112
// RVA: 0xC50E30
void __fastcall hkaRagdollInstance::getApproxCurrentPoseWorldSpace(hkaRagdollInstance *this, hkQsTransformf *poseWorldSpaceOut)
{
  hkQsTransformf *v2; // rdi
  hkaRagdollInstance *v3; // rbx
  hkpWorld *v4; // rax
  float v5; // xmm0_4

  v2 = poseWorldSpaceOut;
  v3 = this;
  v4 = hkaRagdollInstance::getWorld(this);
  if ( v4 )
  {
    v5 = hkpWorld::getCurrentTime(v4);
    hkaRagdollInstance::getApproxPoseWorldSpaceAt(v3, v5, v2);
  }
  else
  {
    hkaRagdollInstance::getPoseWorldSpace(v3, v2);
  }
}

// File Line: 126
// RVA: 0xC50E90
void __fastcall hkaRagdollInstance::getApproxPoseWorldSpaceAt(hkaRagdollInstance *this, float time, hkQsTransformf *poseWorldSpaceOut)
{
  int v3; // ebx
  int v4; // ebp
  hkQsTransformf *v5; // rdi
  hkaRagdollInstance *v6; // rsi

  v3 = 0;
  v4 = this->m_skeleton.m_pntr->m_bones.m_size;
  v5 = poseWorldSpaceOut;
  v6 = this;
  if ( v4 > 0 )
  {
    do
    {
      hkaRagdollInstance::getApproxWorldFromBoneTransformAt(v6, v3++, time, v5);
      ++v5;
    }
    while ( v3 < v4 );
  }
}

// File Line: 136
// RVA: 0xC50FF0
void __fastcall hkaRagdollInstance::getPoseModelSpace(hkaRagdollInstance *this, hkQsTransformf *poseOut, hkQsTransformf *worldFromModel)
{
  hkQsTransformf *v3; // rbp
  hkQsTransformf *v4; // rdi
  hkaRagdollInstance *v5; // rbx
  __int64 v6; // rsi
  __m128i v7; // xmm0
  __int64 v8; // rax
  __m128 v9; // xmm9
  __m128 v10; // xmm5
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm9
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm8
  __m128 v17; // xmm7
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  hkVector4f v27; // [rsp+20h] [rbp-78h]

  v3 = poseOut;
  v4 = worldFromModel;
  v5 = this;
  hkaRagdollInstance::getPoseWorldSpace(this, poseOut);
  v6 = v5->m_skeleton.m_pntr->m_bones.m_size;
  hkVector4f::setRotatedInverseDir(&v27, &v4->m_rotation, &v4->m_translation);
  v7 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v8 = v6;
  v9 = (__m128)_mm_shuffle_epi32(v7, 0);
  v10 = (__m128)_mm_shuffle_epi32(v7, 64);
  v11 = v4->m_scale.m_quad;
  v12 = _mm_xor_ps(v10, v4->m_rotation.m_vec.m_quad);
  v13 = _mm_xor_ps(v9, v27.m_quad);
  v14 = _mm_rcp_ps(v11);
  v15 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v14)), v14), 4),
                  4);
  if ( v6 > 0 )
  {
    v16 = _mm_shuffle_ps(v12, v12, 201);
    v17 = _mm_shuffle_ps(v12, v12, 255);
    do
    {
      v18 = v3->m_translation.m_quad;
      ++v3;
      v19 = _mm_mul_ps(v18, v12);
      v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v12), _mm_mul_ps(v18, v16));
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                    _mm_shuffle_ps(v19, v19, 170)),
                  v12),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), v18)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v17));
      v3[-1].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v21, v21), v13);
      v22 = v3[-1].m_rotation.m_vec.m_quad;
      v23 = _mm_shuffle_ps(v3[-1].m_rotation.m_vec.m_quad, v3[-1].m_rotation.m_vec.m_quad, 255);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v3[-1].m_rotation.m_vec.m_quad, v22, 201), v12), _mm_mul_ps(v16, v22));
      v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(v17, v22)), _mm_mul_ps(v12, v23));
      v26 = _mm_mul_ps(v12, v22);
      v3[-1].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                         v25,
                                         _mm_unpackhi_ps(
                                           v25,
                                           _mm_sub_ps(
                                             _mm_mul_ps(v23, v17),
                                             _mm_add_ps(
                                               _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                                               _mm_shuffle_ps(v26, v26, 170)))),
                                         196);
      v3[-1].m_scale.m_quad = _mm_mul_ps(v15, v3[-1].m_scale.m_quad);
      --v8;
    }
    while ( v8 );
  }
}

// File Line: 151
// RVA: 0xC511D0
void __fastcall hkaRagdollInstance::setPoseModelSpace(hkaRagdollInstance *this, hkQsTransformf *poseIn, hkQsTransformf *worldFromModel)
{
  __int64 v3; // rdi
  hkQsTransformf *v4; // r12
  __int64 v5; // r15
  hkQsTransformf *v6; // rsi
  hkaRagdollInstance *v7; // rbp
  __int64 v8; // rcx
  hkpRigidBody *v9; // r14
  __m128 v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm4
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm5
  __m128 v23; // xmm5
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  __m128 v27; // xmm2
  hkVector4f position; // [rsp+20h] [rbp-58h]
  hkQuaternionf rotation; // [rsp+30h] [rbp-48h]
  __m128 v30; // [rsp+40h] [rbp-38h]

  v3 = 0i64;
  v4 = worldFromModel;
  v5 = this->m_skeleton.m_pntr->m_bones.m_size;
  v6 = poseIn;
  v7 = this;
  if ( v5 > 0 )
  {
    do
    {
      v8 = v7->m_boneToRigidBodyMap.m_data[v3];
      if ( (signed int)v8 >= 0 )
      {
        v9 = v7->m_rigidBodies.m_data[v8];
        if ( v9 )
        {
          v10 = v4->m_rotation.m_vec.m_quad;
          v11 = _mm_mul_ps(v4->m_rotation.m_vec.m_quad, v6->m_translation.m_quad);
          v12 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v6->m_translation.m_quad, v6->m_translation.m_quad, 201), v10),
                  _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v6->m_translation.m_quad));
          v13 = _mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v10, 255);
          v14 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                    _mm_shuffle_ps(v11, v11, 170)),
                  v10);
          v15 = v6->m_rotation.m_vec.m_quad;
          v16 = v4->m_rotation.m_vec.m_quad;
          v17 = _mm_add_ps(
                  _mm_add_ps(
                    v14,
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v6->m_translation.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13));
          v18 = _mm_mul_ps(_mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v16, 201), v15);
          v19 = _mm_mul_ps(v16, v15);
          position.m_quad = _mm_add_ps(_mm_add_ps(v17, v17), v4->m_translation.m_quad);
          v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16), v18);
          v21 = _mm_shuffle_ps(v15, v15, 255);
          v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 201), _mm_mul_ps(v15, v13)), _mm_mul_ps(v16, v21));
          v23 = _mm_shuffle_ps(
                  v22,
                  _mm_unpackhi_ps(
                    v22,
                    _mm_sub_ps(
                      _mm_mul_ps(v21, v13),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                        _mm_shuffle_ps(v19, v19, 170)))),
                  196);
          v24 = _mm_mul_ps(v23, v23);
          v30 = _mm_mul_ps(v6->m_scale.m_quad, v4->m_scale.m_quad);
          v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
          v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25);
          v27 = _mm_rsqrt_ps(v26);
          rotation.m_vec.m_quad = _mm_mul_ps(
                                    v23,
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v27)));
          hkpRigidBody::setPositionAndRotation(v9, &position, &rotation);
          hkpEntity::activate((hkpEntity *)&v9->vfptr);
          v9->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v9->m_motion.vfptr, (unsigned int)&aabbOut);
          hkpEntity::activate((hkpEntity *)&v9->vfptr);
          ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v9->m_motion.vfptr[9].__first_virtual_table_function__)(
            &v9->m_motion,
            &aabbOut);
        }
      }
      ++v3;
      ++v6;
    }
    while ( v3 < v5 );
  }
}

// File Line: 179
// RVA: 0xC51400
void __fastcall hkaRagdollInstance::setPoseAndVelocitiesModelSpace(hkaRagdollInstance *this, hkQsTransformf *poseModelSpaceA, hkQsTransformf *worldFromModelA, hkQsTransformf *poseModelSpaceB, hkQsTransformf *worldFromModelB, float timestep)
{
  __int64 v6; // rbx
  __int64 v7; // r15
  hkaRagdollInstance *v8; // rsi
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm14
  __m128 *v12; // rbp
  signed __int64 v13; // r12
  __int64 v14; // rcx
  hkpRigidBody *v15; // rdi
  hkQuaternionf v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm0
  __m128 v22; // xmm3
  __m128 v23; // xmm9
  __m128 v24; // xmm9
  __m128 v25; // xmm4
  __m128 v26; // xmm8
  __m128 v27; // xmm3
  __m128 v28; // xmm8
  __m128 v29; // xmm8
  __m128 v30; // xmm0
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  hkQuaternionf v35; // xmm2
  __m128 v36; // xmm8
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm6
  __m128 v40; // xmm5
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  hkQuaternionf v43; // xmm1
  __m128 v44; // xmm4
  __m128 v45; // xmm0
  __m128 v46; // xmm3
  __m128 v47; // xmm5
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  __m128 v50; // xmm5
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm13
  __m128 v56; // xmm1
  __m128 v57; // xmm13
  __m128 v58; // xmm0
  __m128 v59; // xmm13
  __m128 v60; // xmm0
  __m128 v61; // xmm2
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm13
  __m128 v65; // xmm11
  __m128i v66; // xmm10
  __m128 v67; // xmm9
  __m128 v68; // xmm7
  __m128 v69; // xmm6
  __m128 v70; // xmm2
  __m128 v71; // xmm5
  __m128 v72; // xmm4
  __m128 v73; // xmm3
  __m128 v74; // xmm2
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  __m128 v77; // [rsp+20h] [rbp-128h]
  __m128 v78; // [rsp+30h] [rbp-118h]
  hkVector4f position; // [rsp+40h] [rbp-108h]
  hkQuaternionf rotation; // [rsp+50h] [rbp-F8h]
  __m128 v81; // [rsp+60h] [rbp-E8h]
  unsigned int v82; // [rsp+150h] [rbp+8h]
  hkQsTransformf *v83; // [rsp+160h] [rbp+18h]

  v83 = worldFromModelA;
  v6 = 0i64;
  v7 = this->m_skeleton.m_pntr->m_bones.m_size;
  v8 = this;
  v9 = _mm_shuffle_ps((__m128)LODWORD(timestep), (__m128)LODWORD(timestep), 0);
  v10 = _mm_rcp_ps(v9);
  v11 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v10)), v10);
  if ( v7 > 0 )
  {
    v12 = &poseModelSpaceB->m_rotation.m_vec.m_quad;
    v13 = (char *)poseModelSpaceA - (char *)poseModelSpaceB;
    do
    {
      v14 = v8->m_boneToRigidBodyMap.m_data[v6];
      if ( (signed int)v14 >= 0 )
      {
        v15 = v8->m_rigidBodies.m_data[v14];
        if ( v15 )
        {
          v16.m_vec.m_quad = (__m128)worldFromModelA->m_rotation;
          v17 = *(__m128 *)((char *)v12 + v13 - 16);
          v18 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 201), v17));
          v19 = _mm_mul_ps(worldFromModelA->m_rotation.m_vec.m_quad, v17);
          v20 = _mm_shuffle_ps(worldFromModelA->m_rotation.m_vec.m_quad, v16.m_vec.m_quad, 255);
          v21 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v17);
          v22 = *(__m128 *)((char *)v12 + v13);
          v23 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                        _mm_shuffle_ps(v19, v19, 170)),
                      v16.m_vec.m_quad),
                    v21),
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v20));
          v24 = _mm_add_ps(_mm_add_ps(v23, v23), worldFromModelA->m_translation.m_quad);
          v25 = _mm_shuffle_ps(*(__m128 *)((char *)v12 + v13), *(__m128 *)((char *)v12 + v13), 255);
          v26 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v16.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(worldFromModelA->m_rotation.m_vec.m_quad, v16.m_vec.m_quad, 201), v22));
          v27 = _mm_mul_ps(v22, v16.m_vec.m_quad);
          v28 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v26, v26, 201), _mm_mul_ps(*(__m128 *)((char *)v12 + v13), v20)),
                  _mm_mul_ps(worldFromModelA->m_rotation.m_vec.m_quad, v25));
          v29 = _mm_shuffle_ps(
                  v28,
                  _mm_unpackhi_ps(
                    v28,
                    _mm_sub_ps(
                      _mm_mul_ps(v25, v20),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                        _mm_shuffle_ps(v27, v27, 170)))),
                  196);
          v30 = _mm_mul_ps(v29, v29);
          v31 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 78), v30);
          v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v31);
          v33 = _mm_rsqrt_ps(v32);
          v34 = _mm_mul_ps(v33, v32);
          v35.m_vec.m_quad = (__m128)worldFromModelB->m_rotation;
          v36 = _mm_mul_ps(
                  v29,
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v33)), _mm_mul_ps(v33, *(__m128 *)_xmm)));
          v37 = v12[-1];
          v38 = _mm_mul_ps(worldFromModelB->m_rotation.m_vec.m_quad, v37);
          v39 = _mm_shuffle_ps(worldFromModelB->m_rotation.m_vec.m_quad, v35.m_vec.m_quad, 255);
          v40 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v12[-1], v37, 201), v35.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v35.m_vec.m_quad, v35.m_vec.m_quad, 201), v37));
          v41 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                    _mm_shuffle_ps(v38, v38, 170)),
                  v35.m_vec.m_quad);
          v42 = *v12;
          v43.m_vec.m_quad = (__m128)worldFromModelB->m_rotation;
          v44 = _mm_add_ps(
                  _mm_add_ps(v41, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v39, v39), (__m128)xmmword_141A711B0), v37)),
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39));
          v45 = _mm_mul_ps(_mm_shuffle_ps(worldFromModelB->m_rotation.m_vec.m_quad, v43.m_vec.m_quad, 201), *v12);
          v46 = _mm_mul_ps(v43.m_vec.m_quad, *v12);
          position.m_quad = _mm_add_ps(_mm_add_ps(v44, v44), worldFromModelB->m_translation.m_quad);
          v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v43.m_vec.m_quad), v45);
          v48 = _mm_shuffle_ps(v42, v42, 255);
          v49 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v47, v47, 201), _mm_mul_ps(v42, v39)),
                  _mm_mul_ps(v43.m_vec.m_quad, v48));
          v50 = _mm_shuffle_ps(
                  v49,
                  _mm_unpackhi_ps(
                    v49,
                    _mm_sub_ps(
                      _mm_mul_ps(v48, v39),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v46, v46, 85), _mm_shuffle_ps(v46, v46, 0)),
                        _mm_shuffle_ps(v46, v46, 170)))),
                  196);
          v51 = _mm_mul_ps(v50, v50);
          v81 = _mm_mul_ps(v12[1], worldFromModelB->m_scale.m_quad);
          v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
          v53 = _mm_add_ps(_mm_shuffle_ps(v52, v52, 177), v52);
          v54 = _mm_rsqrt_ps(v53);
          rotation.m_vec.m_quad = _mm_mul_ps(
                                    v50,
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
                                      _mm_mul_ps(v54, *(__m128 *)_xmm)));
          hkpRigidBody::setPositionAndRotation(v15, &position, &rotation);
          v78 = _mm_mul_ps(_mm_sub_ps(position.m_quad, v24), v11);
          hkpEntity::activate((hkpEntity *)&v15->vfptr);
          v15->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v15->m_motion.vfptr, (unsigned int)&v78);
          v55 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(rotation.m_vec.m_quad, rotation.m_vec.m_quad, 201), v36),
                  _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), rotation.m_vec.m_quad));
          v56 = _mm_mul_ps(rotation.m_vec.m_quad, v36);
          v57 = _mm_add_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(v55, v55, 201),
                    _mm_mul_ps(_mm_shuffle_ps(rotation.m_vec.m_quad, rotation.m_vec.m_quad, 255), v36)),
                  _mm_mul_ps(_mm_shuffle_ps(v36, v36, 255), rotation.m_vec.m_quad));
          v58 = _mm_add_ps(_mm_shuffle_ps(v56, v56, 78), v56);
          v59 = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, _mm_add_ps(_mm_shuffle_ps(v58, v58, 177), v58)), 196);
          v60 = _mm_mul_ps(v59, v59);
          v61 = _mm_add_ps(_mm_shuffle_ps(v60, v60, 78), v60);
          v62 = _mm_add_ps(_mm_shuffle_ps(v61, v61, 177), v61);
          v63 = _mm_rsqrt_ps(v62);
          v64 = _mm_mul_ps(
                  v59,
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v63, v62), v63)),
                    _mm_mul_ps(v63, *(__m128 *)_xmm)));
          v65 = _mm_mul_ps(v64, v64);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 170))) > 1.4210855e-14 )
          {
            v66 = (__m128i)_mm_shuffle_ps(v64, v64, 255);
            v67 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v66, 1u), 1u);
            v68 = _mm_andnot_ps(*(__m128 *)_xmm, v67);
            v69 = _mm_cmpltps(v68, *(__m128 *)_xmm);
            v70 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v68), *(__m128 *)_xmm);
            v71 = _mm_cmpltps(*(__m128 *)_xmm, v68);
            v72 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v70), v71), _mm_andnot_ps(v71, v68));
            v73 = _mm_or_ps(_mm_andnot_ps(v71, _mm_mul_ps(v68, v68)), _mm_and_ps(v71, v70));
            v74 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v73, *(__m128 *)coeff4), *(__m128 *)coeff3), v73),
                                  *(__m128 *)coeff2),
                                v73),
                              *(__m128 *)coeff1),
                            v73),
                          *(__m128 *)coeff0),
                        v73),
                      v72),
                    v72);
            *(float *)&v82 = (float)(1.5707964
                                   - COERCE_FLOAT((*(unsigned __int128 *)&_mm_andnot_ps(
                                                                            v69,
                                                                            _mm_or_ps(
                                                                              _mm_and_ps(
                                                                                _mm_sub_ps(
                                                                                  *(__m128 *)_xmm,
                                                                                  _mm_add_ps(v74, v74)),
                                                                                v71),
                                                                              _mm_andnot_ps(v71, v74))) | v69.m128_i32[0] & v68.m128_i32[0]) ^ v67.m128_i32[0] & _xmm[0]))
                           * 2.0;
            v75 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                    _mm_shuffle_ps(v65, v65, 170));
            v76 = _mm_rsqrt_ps(v75);
            v77 = _mm_mul_ps(
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32((__m128i)_mm_cmpltps((__m128)v66, (__m128)0i64), 0x1Fu),
                                0x1Fu),
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v75, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v76, v75), v76)),
                            _mm_mul_ps(v76, *(__m128 *)_xmm))),
                        v64)),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)v82, (__m128)v82, 0), v11));
          }
          else
          {
            v77 = 0i64;
          }
          hkpEntity::activate((hkpEntity *)&v15->vfptr);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v15->m_motion.vfptr[9].__first_virtual_table_function__)(
            &v15->m_motion,
            &v77);
          worldFromModelA = v83;
        }
      }
      ++v6;
      v12 += 3;
    }
    while ( v6 < v7 );
  }
}

// File Line: 232
// RVA: 0xC50F00
void __fastcall hkaRagdollInstance::setPoseWorldSpace(hkaRagdollInstance *this, hkQsTransformf *poseWorldSpaceIn)
{
  int v2; // esi
  hkQsTransformf *v3; // r12
  __int64 v4; // r15
  hkaRagdollInstance *v5; // r14
  __int64 i; // rbx
  __int64 v7; // rcx
  hkpRigidBody *v8; // rbp

  v2 = 0;
  v3 = poseWorldSpaceIn;
  v4 = this->m_skeleton.m_pntr->m_bones.m_size;
  v5 = this;
  for ( i = 0i64; i < v4; ++v2 )
  {
    v7 = v5->m_boneToRigidBodyMap.m_data[i];
    if ( (signed int)v7 >= 0 )
    {
      v8 = v5->m_rigidBodies.m_data[v7];
      if ( v8 )
      {
        hkpRigidBody::setPositionAndRotation(v8, &v3[v2].m_translation, &v3[v2].m_rotation);
        hkpEntity::activate((hkpEntity *)&v8->vfptr);
        v8->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v8->m_motion.vfptr, (unsigned int)&aabbOut);
        hkpEntity::activate((hkpEntity *)&v8->vfptr);
        ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v8->m_motion.vfptr[9].__first_virtual_table_function__)(
          &v8->m_motion,
          &aabbOut);
      }
    }
    ++i;
  }
}

// File Line: 255
// RVA: 0xC51A80
hkResult *__fastcall hkaRagdollInstance::addToWorld(hkaRagdollInstance *this, hkResult *result, hkpWorld *world, hkBool updateFilter)
{
  hkpWorld *v4; // rbp
  hkResult *v5; // r14
  hkaRagdollInstance *v6; // rdi
  hkResult *v7; // rax
  int v8; // esi
  __int64 v9; // rbx
  __int64 v10; // rsi
  __int64 i; // rbx
  char v12; // [rsp+58h] [rbp+20h]

  v12 = updateFilter.m_bool;
  v4 = world;
  v5 = result;
  v6 = this;
  if ( hkaRagdollInstance::getWorld(this) )
  {
    v5->m_enum = 1;
    v7 = v5;
  }
  else
  {
    hkpWorld::addEntityBatch(
      v4,
      (hkpEntity *const *)v6->m_rigidBodies.m_data,
      v6->m_rigidBodies.m_size,
      HK_ENTITY_ACTIVATION_DO_ACTIVATE);
    v8 = 0;
    if ( v6->m_constraints.m_size > 0 )
    {
      v9 = 0i64;
      do
      {
        hkpWorld::addConstraint(v4, v6->m_constraints.m_data[v9]);
        ++v8;
        ++v9;
      }
      while ( v8 < v6->m_constraints.m_size );
    }
    if ( v12 )
    {
      v10 = v6->m_rigidBodies.m_size;
      for ( i = 0i64; i < v10; ++i )
        hkpWorld::updateCollisionFilterOnEntity(
          v4,
          (hkpEntity *)&v6->m_rigidBodies.m_data[i]->vfptr,
          HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
          0);
    }
    v5->m_enum = 0;
    v7 = v5;
  }
  return v7;
}

// File Line: 286
// RVA: 0xC51B60
hkResult *__fastcall hkaRagdollInstance::removeFromWorld(hkaRagdollInstance *this, hkResult *result)
{
  hkResult *v2; // r14
  hkaRagdollInstance *v3; // rbx
  hkpWorld *v4; // rbp
  hkResult *v5; // rax
  int v6; // edi
  __int64 v7; // rsi
  hkpConstraintInstance *v8; // r8
  int v9; // eax
  hkpEntity **v10; // rsi
  signed int v11; // edi
  int v12; // edx
  int v13; // er8
  __int64 v14; // rcx
  hkpEntity **v15; // r9
  hkpRigidBody *v16; // r10
  hkBool resulta; // [rsp+50h] [rbp+18h]

  v2 = result;
  v3 = this;
  v4 = hkaRagdollInstance::getWorld(this);
  if ( v4 )
  {
    v6 = 0;
    if ( v3->m_constraints.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = v3->m_constraints.m_data[v7];
        if ( v8->m_owner )
          hkpWorld::removeConstraint(v4, &resulta, v8);
        ++v6;
        ++v7;
      }
      while ( v6 < v3->m_constraints.m_size );
    }
    v9 = v3->m_rigidBodies.m_size;
    if ( v9 )
    {
      *(_DWORD *)&resulta.m_bool = 8 * v9;
      v10 = (hkpEntity **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                            (int *)&resulta);
      v9 = *(_DWORD *)&resulta.m_bool / 8;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = 2147483648;
    if ( v9 )
      v11 = v9;
    v12 = 0;
    v13 = 0;
    if ( v3->m_rigidBodies.m_size > 0 )
    {
      v14 = 0i64;
      v15 = v10;
      do
      {
        v16 = v3->m_rigidBodies.m_data[v14];
        if ( v16->m_world == v4 )
        {
          *v15 = (hkpEntity *)&v16->vfptr;
          ++v13;
          ++v15;
        }
        ++v12;
        ++v14;
      }
      while ( v12 < v3->m_rigidBodies.m_size );
    }
    hkpWorld::removeEntityBatch(v4, v10, v13);
    v2->m_enum = 0;
    if ( v11 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v10,
        8 * v11);
    v5 = v2;
  }
  else
  {
    v2->m_enum = 1;
    v5 = v2;
  }
  return v5;
}

// File Line: 325
// RVA: 0xC50770
hkaRagdollInstance *__fastcall hkaRagdollInstance::clone(hkaRagdollInstance *this, hkpConstraintInstance::CloningMode mode)
{
  __int64 v2; // rbx
  __int64 v3; // r15
  __int64 v4; // r12
  hkpConstraintInstance::CloningMode v5; // er13
  hkaRagdollInstance *v6; // rsi
  hkLifoAllocator *v7; // rax
  char *v8; // r8
  int v9; // edx
  char *v10; // rcx
  signed int v11; // ecx
  int v12; // er9
  hkLifoAllocator *v13; // rax
  hkpConstraintInstance **v14; // rcx
  int v15; // edx
  char *v16; // r8
  signed int v17; // eax
  int v18; // eax
  int v19; // er9
  __int64 v20; // rdi
  __int64 v21; // r14
  char *v22; // rbx
  hkpConstraintInstance *v23; // rcx
  unsigned __int64 v24; // rbx
  hkpEntity *v25; // rdi
  hkpEntity *v26; // rax
  hkpConstraintInstance **v27; // rbx
  hkpConstraintInstance *v28; // rax
  _QWORD **v29; // rax
  hkaRagdollInstance *v30; // rax
  __int64 v31; // rax
  __int64 v32; // rsi
  __int64 i; // rbx
  __int64 j; // rbx
  int v35; // eax
  char *v36; // rdi
  signed int v37; // ebx
  hkLifoAllocator *v38; // rax
  int v39; // er8
  int v40; // eax
  char *v41; // rdi
  signed int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // er8
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v46; // [rsp+30h] [rbp-50h]
  hkArrayBase<hkpConstraintInstance *> constraints; // [rsp+40h] [rbp-40h]
  void *p; // [rsp+50h] [rbp-30h]
  int v49; // [rsp+58h] [rbp-28h]
  char *array; // [rsp+60h] [rbp-20h]
  int v51; // [rsp+68h] [rbp-18h]
  int v52; // [rsp+6Ch] [rbp-14h]
  void *v53; // [rsp+70h] [rbp-10h]
  int v54; // [rsp+78h] [rbp-8h]
  hkResult result; // [rsp+B0h] [rbp+30h]

  v2 = this->m_rigidBodies.m_size;
  v3 = this->m_constraints.m_size;
  v4 = 0i64;
  v5 = mode;
  v6 = this;
  array = 0i64;
  v51 = 0;
  v52 = 2147483648;
  v54 = v2;
  if ( (_DWORD)v2 )
  {
    v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (char *)v7->m_cur;
    v9 = (8 * v2 + 127) & 0xFFFFFF80;
    v10 = &v8[v9];
    if ( v9 > v7->m_slabSize || v10 > v7->m_end )
    {
      array = (char *)hkLifoAllocator::allocateFromNewSlab(v7, v9);
    }
    else
    {
      v7->m_cur = v10;
      array = v8;
    }
  }
  else
  {
    array = 0i64;
  }
  v53 = array;
  v52 = v2 | 0x80000000;
  v11 = (v2 | 0x80000000) & 0x3FFFFFFF;
  if ( v11 < (signed int)v2 )
  {
    v12 = v2;
    if ( (signed int)v2 < 2 * v11 )
      v12 = 2 * v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v12, 8);
  }
  v51 = v2;
  constraints.m_data = 0i64;
  constraints.m_size = 0;
  constraints.m_capacityAndFlags = 2147483648;
  v49 = v3;
  if ( (_DWORD)v3 )
  {
    v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkpConstraintInstance **)v13->m_cur;
    v15 = (8 * v3 + 127) & 0xFFFFFF80;
    v16 = (char *)v14 + v15;
    if ( v15 > v13->m_slabSize || v16 > v13->m_end )
      v14 = (hkpConstraintInstance **)hkLifoAllocator::allocateFromNewSlab(v13, v15);
    else
      v13->m_cur = v16;
  }
  else
  {
    v14 = 0i64;
  }
  constraints.m_data = v14;
  p = v14;
  constraints.m_capacityAndFlags = v3 | 0x80000000;
  v17 = (v3 | 0x80000000) & 0x3FFFFFFF;
  if ( v17 < (signed int)v3 )
  {
    v18 = 2 * v17;
    v19 = v3;
    if ( (signed int)v3 < v18 )
      v19 = v18;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &constraints, v19, 8);
  }
  constraints.m_size = v3;
  v46.m_elem = 0i64;
  v46.m_numElems = 0;
  v46.m_hashMod = -1;
  v20 = 0i64;
  v21 = v2;
  if ( (signed int)v2 > 0 )
  {
    do
    {
      v22 = &array[8 * v20];
      *(_QWORD *)v22 = ((__int64 (*)(void))v6->m_rigidBodies.m_data[v20]->vfptr[3].__first_virtual_table_function__)();
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v46,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v6->m_rigidBodies.m_data[v20],
        *(_QWORD *)&array[8 * v20]);
      ++v20;
    }
    while ( v20 < v21 );
  }
  if ( v3 > 0 )
  {
    do
    {
      v23 = v6->m_constraints.m_data[v4];
      v24 = (unsigned __int64)v23->m_entities[1];
      v25 = (hkpEntity *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           &v46,
                           (unsigned __int64)v23->m_entities[0],
                           0i64);
      v26 = (hkpEntity *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           &v46,
                           v24,
                           0i64);
      v27 = &constraints.m_data[v4];
      v28 = hkpConstraintInstance::clone(v6->m_constraints.m_data[v4++], v25, v26, v5);
      *v27 = v28;
    }
    while ( v4 < v3 );
  }
  v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (hkaRagdollInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v29[11] + 8i64))(v29[11], 72i64);
  if ( v30 )
  {
    hkaRagdollInstance::hkaRagdollInstance(
      v30,
      (hkArrayBase<hkpRigidBody *> *)&array,
      &constraints,
      v6->m_skeleton.m_pntr,
      (hkArrayBase<int> *)&v6->m_boneToRigidBodyMap.m_data);
    v32 = v31;
  }
  else
  {
    v32 = 0i64;
  }
  for ( i = 0i64; i < v21; ++i )
    hkReferencedObject::removeReference(*(hkReferencedObject **)&array[8 * i]);
  for ( j = 0i64; j < v3; ++j )
    hkReferencedObject::removeReference((hkReferencedObject *)&constraints.m_data[j]->vfptr);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v46,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v46);
  v35 = constraints.m_size;
  v36 = (char *)p;
  if ( p == constraints.m_data )
    v35 = 0;
  constraints.m_size = v35;
  v37 = (8 * v49 + 127) & 0xFFFFFF80;
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (v37 + 15) & 0xFFFFFFF0;
  if ( v37 > v38->m_slabSize || &v36[v39] != v38->m_cur || v38->m_firstNonLifoEnd == v36 )
    hkLifoAllocator::slowBlockFree(v38, v36, v39);
  else
    v38->m_cur = v36;
  constraints.m_size = 0;
  if ( constraints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      constraints.m_data,
      8 * constraints.m_capacityAndFlags);
  v40 = v51;
  v41 = (char *)v53;
  constraints.m_data = 0i64;
  constraints.m_capacityAndFlags = 2147483648;
  if ( v53 == array )
    v40 = 0;
  v51 = v40;
  v42 = (8 * v54 + 127) & 0xFFFFFF80;
  v43 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v44 = (v42 + 15) & 0xFFFFFFF0;
  if ( v42 > v43->m_slabSize || &v41[v44] != v43->m_cur || v43->m_firstNonLifoEnd == v41 )
    hkLifoAllocator::slowBlockFree(v43, v41, v44);
  else
    v43->m_cur = v41;
  v51 = 0;
  if ( v52 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v52);
  return (hkaRagdollInstance *)v32;
}

// File Line: 380
// RVA: 0xC51CF0
void __fastcall hkaRagdollInstance::getWorldFromBoneTransform(hkaRagdollInstance *this, int i, hkQsTransformf *worldFromBoneOut)
{
  __int64 v3; // rbp
  hkaRagdollInstance *v4; // rbx
  __int64 v5; // rcx
  hkQsTransformf *v6; // rsi
  hkpRigidBody *v7; // rdx
  int v8; // edx
  __m128 v9; // xmm8
  __m128 v10; // xmm7
  hkVector4f v11; // xmm9
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 *v14; // rcx
  __m128 v15; // xmm1
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm7
  __m128 v23; // xmm4
  __m128 v24; // xmm4
  hkQsTransformf worldFromBoneOuta; // [rsp+20h] [rbp-78h]

  v3 = i;
  v4 = this;
  v5 = this->m_boneToRigidBodyMap.m_data[i];
  v6 = worldFromBoneOut;
  if ( (signed int)v5 >= 0 && (v7 = v4->m_rigidBodies.m_data[v5]) != 0i64 )
  {
    hkQsTransformf::setFromTransformNoScale(worldFromBoneOut, &v7->m_motion.m_motionState.m_transform);
    hkaSkeletonUtils::getModelSpaceScale(
      v4->m_skeleton.m_pntr,
      v4->m_skeleton.m_pntr->m_referencePose.m_data,
      v3,
      &v6->m_scale);
  }
  else
  {
    v8 = v4->m_skeleton.m_pntr->m_parentIndices.m_data[v3];
    if ( v8 < 0 )
    {
      v10 = qi.m_vec.m_quad;
      v9 = query.m_quad;
      v11.m_quad = 0i64;
      worldFromBoneOuta.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
      worldFromBoneOuta.m_scale = (hkVector4f)query.m_quad;
      worldFromBoneOuta.m_translation = 0i64;
    }
    else
    {
      hkaRagdollInstance::getWorldFromBoneTransform(v4, v8, &worldFromBoneOuta);
      v9 = worldFromBoneOuta.m_scale.m_quad;
      v10 = worldFromBoneOuta.m_rotation.m_vec.m_quad;
      v11.m_quad = (__m128)worldFromBoneOuta.m_translation;
    }
    v12 = _mm_shuffle_ps(v10, v10, 255);
    v13 = _mm_shuffle_ps(v10, v10, 201);
    v14 = &v4->m_skeleton.m_pntr->m_referencePose.m_data[v3].m_translation.m_quad;
    v15 = _mm_mul_ps(*v14, v10);
    v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*v14, *v14, 201), v10), _mm_mul_ps(v13, *v14));
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                  _mm_shuffle_ps(v15, v15, 170)),
                v10),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), *v14)),
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v12));
    v6->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v17, v17), v11.m_quad);
    v18 = v14[1];
    v19 = _mm_shuffle_ps(v14[1], v14[1], 255);
    v20 = _mm_mul_ps(_mm_shuffle_ps(v14[1], v18, 201), v10);
    v21 = _mm_mul_ps(v10, v19);
    v22 = _mm_mul_ps(v10, v18);
    v23 = _mm_sub_ps(v20, _mm_mul_ps(v13, v18));
    v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(v12, v18)), v21);
    v6->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v24,
                                    _mm_unpackhi_ps(
                                      v24,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v19, v12),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                                          _mm_shuffle_ps(v22, v22, 170)))),
                                    196);
    v6->m_scale.m_quad = _mm_mul_ps(v14[2], v9);
  }
}

// File Line: 414
// RVA: 0xC51EF0
void __fastcall hkaRagdollInstance::getApproxWorldFromBoneTransformAt(hkaRagdollInstance *this, int i, float time, hkQsTransformf *worldFromBoneOut)
{
  __int64 v4; // rbp
  hkaRagdollInstance *v5; // rbx
  __int64 v6; // rcx
  hkQsTransformf *v7; // rsi
  hkpRigidBody *v8; // rcx
  int v9; // edx
  __m128 v10; // xmm8
  __m128 v11; // xmm7
  hkVector4f v12; // xmm9
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  __m128 *v15; // rcx
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  __m128 v21; // xmm4
  __m128 v22; // xmm1
  __m128 v23; // xmm7
  __m128 v24; // xmm4
  __m128 v25; // xmm4
  hkTransformf transformOut; // [rsp+20h] [rbp-88h]

  v4 = i;
  v5 = this;
  v6 = this->m_boneToRigidBodyMap.m_data[i];
  v7 = worldFromBoneOut;
  if ( (signed int)v6 >= 0 && (v8 = v5->m_rigidBodies.m_data[v6]) != 0i64 )
  {
    hkpMotion::approxTransformAt((hkpMotion *)&v8->m_motion.vfptr, time, &transformOut);
    hkQsTransformf::setFromTransformNoScale(v7, &transformOut);
    hkaSkeletonUtils::getModelSpaceScale(
      v5->m_skeleton.m_pntr,
      v5->m_skeleton.m_pntr->m_referencePose.m_data,
      v4,
      &v7->m_scale);
  }
  else
  {
    v9 = v5->m_skeleton.m_pntr->m_parentIndices.m_data[i];
    if ( v9 < 0 )
    {
      v11 = qi.m_vec.m_quad;
      v10 = query.m_quad;
      v12.m_quad = 0i64;
      transformOut.m_rotation.m_col1 = (hkVector4f)qi.m_vec.m_quad;
      transformOut.m_rotation.m_col2 = (hkVector4f)query.m_quad;
      transformOut.m_rotation.m_col0 = 0i64;
    }
    else
    {
      hkaRagdollInstance::getApproxWorldFromBoneTransformAt(v5, v9, time, (hkQsTransformf *)&transformOut);
      v10 = transformOut.m_rotation.m_col2.m_quad;
      v11 = transformOut.m_rotation.m_col1.m_quad;
      v12.m_quad = (__m128)transformOut.m_rotation.m_col0;
    }
    v13 = _mm_shuffle_ps(v11, v11, 255);
    v14 = _mm_shuffle_ps(v11, v11, 201);
    v15 = &v5->m_skeleton.m_pntr->m_referencePose.m_data[v4].m_translation.m_quad;
    v16 = _mm_mul_ps(*v15, v11);
    v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*v15, *v15, 201), v11), _mm_mul_ps(v14, *v15));
    v18 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                  _mm_shuffle_ps(v16, v16, 170)),
                v11),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), *v15)),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v13));
    v7->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v18, v18), v12.m_quad);
    v19 = v15[1];
    v20 = _mm_shuffle_ps(v15[1], v15[1], 255);
    v21 = _mm_mul_ps(_mm_shuffle_ps(v15[1], v19, 201), v11);
    v22 = _mm_mul_ps(v11, v20);
    v23 = _mm_mul_ps(v11, v19);
    v24 = _mm_sub_ps(v21, _mm_mul_ps(v14, v19));
    v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(v13, v19)), v22);
    v7->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                    v25,
                                    _mm_unpackhi_ps(
                                      v25,
                                      _mm_sub_ps(
                                        _mm_mul_ps(v20, v13),
                                        _mm_add_ps(
                                          _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                                          _mm_shuffle_ps(v23, v23, 170)))),
                                    196);
    v7->m_scale.m_quad = _mm_mul_ps(v15[2], v10);
  }
}

// File Line: 450
// RVA: 0xC51CB0
hkpWorld *__fastcall hkaRagdollInstance::getWorld(hkaRagdollInstance *this)
{
  __int64 v1; // r8
  __int64 v2; // rdx
  hkpRigidBody **v3; // rcx
  hkpWorld *result; // rax

  v1 = this->m_rigidBodies.m_size;
  v2 = 0i64;
  if ( v1 <= 0 )
    return 0i64;
  v3 = this->m_rigidBodies.m_data;
  while ( 1 )
  {
    result = (*v3)->m_world;
    if ( result )
      break;
    ++v2;
    ++v3;
    if ( v2 >= v1 )
      return 0i64;
  }
  return result;
}

