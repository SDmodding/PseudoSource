// File Line: 12
// RVA: 0xC52120
void __fastcall hkaRagdollInstance::commonInit(
        hkaRagdollInstance *this,
        hkArrayBase<hkpRigidBody *> *rigidBodies,
        hkArrayBase<hkpConstraintInstance *> *constraints,
        hkaSkeleton *skeleton)
{
  hkaSkeleton *m_pntr; // rcx
  __int64 m_size; // rax
  hkpRigidBody **m_data; // rcx
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
  int v23; // [rsp+30h] [rbp+8h] BYREF

  if ( skeleton )
    hkReferencedObject::addReference(skeleton);
  m_pntr = this->m_skeleton.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_skeleton.m_pntr = skeleton;
  if ( (this->m_rigidBodies.m_capacityAndFlags & 0x3FFFFFFF) < rigidBodies->m_size )
  {
    if ( this->m_rigidBodies.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_rigidBodies.m_data,
        8 * this->m_rigidBodies.m_capacityAndFlags);
    v23 = 8 * rigidBodies->m_size;
    this->m_rigidBodies.m_data = (hkpRigidBody **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                    &hkContainerHeapAllocator::s_alloc,
                                                    &v23);
    this->m_rigidBodies.m_capacityAndFlags = v23 / 8;
  }
  m_size = rigidBodies->m_size;
  m_data = this->m_rigidBodies.m_data;
  this->m_rigidBodies.m_size = m_size;
  v11 = m_size;
  if ( (int)m_size > 0 )
  {
    v12 = (char *)((char *)rigidBodies->m_data - (char *)m_data);
    do
    {
      v13 = *(hkpRigidBody **)((char *)m_data++ + (_QWORD)v12);
      *(m_data - 1) = v13;
      --v11;
    }
    while ( v11 );
  }
  if ( (this->m_constraints.m_capacityAndFlags & 0x3FFFFFFF) < constraints->m_size )
  {
    if ( this->m_constraints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_constraints.m_data,
        8 * this->m_constraints.m_capacityAndFlags);
    v23 = 8 * constraints->m_size;
    this->m_constraints.m_data = (hkpConstraintInstance **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                             &hkContainerHeapAllocator::s_alloc,
                                                             &v23);
    this->m_constraints.m_capacityAndFlags = v23 / 8;
  }
  v14 = constraints->m_size;
  v15 = this->m_constraints.m_data;
  this->m_constraints.m_size = v14;
  v16 = v14;
  if ( (int)v14 > 0 )
  {
    v17 = (char *)((char *)constraints->m_data - (char *)v15);
    do
    {
      v18 = *(hkpConstraintInstance **)((char *)v15++ + (_QWORD)v17);
      *(v15 - 1) = v18;
      --v16;
    }
    while ( v16 );
  }
  v19 = 0;
  v20 = 0;
  if ( this->m_rigidBodies.m_size > 0 )
  {
    v21 = 0i64;
    do
    {
      hkReferencedObject::addReference(this->m_rigidBodies.m_data[v21]);
      ++v20;
      ++v21;
    }
    while ( v20 < this->m_rigidBodies.m_size );
  }
  if ( this->m_constraints.m_size > 0 )
  {
    v22 = 0i64;
    do
    {
      hkReferencedObject::addReference(this->m_constraints.m_data[v22]);
      ++v19;
      ++v22;
    }
    while ( v19 < this->m_constraints.m_size );
  }
}

// File Line: 31
// RVA: 0xC50430
void __fastcall hkaRagdollInstance::hkaRagdollInstance(
        hkaRagdollInstance *this,
        hkArrayBase<hkpRigidBody *> *rigidBodies,
        hkArrayBase<hkpConstraintInstance *> *constraints,
        hkaSkeleton *skeleton)
{
  int v4; // ebx
  int m_size; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  __int64 v11; // rcx
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaRagdollInstance::`vftable;
  this->m_rigidBodies.m_data = 0i64;
  this->m_rigidBodies.m_size = 0;
  this->m_rigidBodies.m_capacityAndFlags = 0x80000000;
  this->m_constraints.m_data = 0i64;
  this->m_constraints.m_size = 0;
  this->m_constraints.m_capacityAndFlags = 0x80000000;
  this->m_boneToRigidBodyMap.m_data = 0i64;
  this->m_boneToRigidBodyMap.m_size = 0;
  this->m_boneToRigidBodyMap.m_capacityAndFlags = 0x80000000;
  this->m_skeleton.m_pntr = 0i64;
  hkaRagdollInstance::commonInit(this, rigidBodies, constraints, skeleton);
  m_size = skeleton->m_bones.m_size;
  v8 = this->m_boneToRigidBodyMap.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < m_size )
  {
    v9 = 2 * v8;
    v10 = skeleton->m_bones.m_size;
    if ( m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_boneToRigidBodyMap, v10, 4);
  }
  this->m_boneToRigidBodyMap.m_size = m_size;
  if ( skeleton->m_bones.m_size > 0 )
  {
    v11 = 0i64;
    do
      this->m_boneToRigidBodyMap.m_data[v11++] = v4++;
    while ( v4 < skeleton->m_bones.m_size );
  }
}

// File Line: 45
// RVA: 0xC50510
void __fastcall hkaRagdollInstance::hkaRagdollInstance(
        hkaRagdollInstance *this,
        hkArrayBase<hkpRigidBody *> *rigidBodies,
        hkArrayBase<hkpConstraintInstance *> *constraints,
        hkaSkeleton *skeleton,
        hkArrayBase<int> *boneToRigidBodyMap)
{
  hkArrayBase<int> *v6; // rdi
  __int64 m_size; // rcx
  int *m_data; // rax
  __int64 v9; // rdx
  signed __int64 v10; // r8
  int v11; // ecx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaRagdollInstance::`vftable;
  this->m_rigidBodies.m_capacityAndFlags = 0x80000000;
  this->m_rigidBodies.m_data = 0i64;
  this->m_rigidBodies.m_size = 0;
  this->m_constraints.m_data = 0i64;
  this->m_constraints.m_size = 0;
  this->m_constraints.m_capacityAndFlags = 0x80000000;
  this->m_boneToRigidBodyMap.m_data = 0i64;
  this->m_boneToRigidBodyMap.m_size = 0;
  this->m_boneToRigidBodyMap.m_capacityAndFlags = 0x80000000;
  this->m_skeleton.m_pntr = 0i64;
  hkaRagdollInstance::commonInit(this, rigidBodies, constraints, skeleton);
  v6 = boneToRigidBodyMap;
  if ( (this->m_boneToRigidBodyMap.m_capacityAndFlags & 0x3FFFFFFF) < boneToRigidBodyMap->m_size )
  {
    if ( this->m_boneToRigidBodyMap.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_boneToRigidBodyMap.m_data,
        4 * this->m_boneToRigidBodyMap.m_capacityAndFlags);
    LODWORD(boneToRigidBodyMap) = 4 * v6->m_size;
    this->m_boneToRigidBodyMap.m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                 &hkContainerHeapAllocator::s_alloc,
                                                 &boneToRigidBodyMap);
    this->m_boneToRigidBodyMap.m_capacityAndFlags = (int)boneToRigidBodyMap / 4;
  }
  m_size = v6->m_size;
  m_data = this->m_boneToRigidBodyMap.m_data;
  this->m_boneToRigidBodyMap.m_size = m_size;
  v9 = m_size;
  if ( (int)m_size > 0 )
  {
    v10 = (char *)v6->m_data - (char *)m_data;
    do
    {
      v11 = *(int *)((char *)m_data++ + v10);
      *(m_data - 1) = v11;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 55
// RVA: 0xC52100
void __fastcall hkaRagdollInstance::hkaRagdollInstance(hkaRagdollInstance *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaRagdollInstance::`vftable;
}

// File Line: 59
// RVA: 0xC50620
void __fastcall hkaRagdollInstance::~hkaRagdollInstance(hkaRagdollInstance *this)
{
  int v2; // esi
  __int64 v3; // rdi
  int v4; // edi
  __int64 v5; // rsi
  hkaSkeleton *m_pntr; // rcx
  int m_capacityAndFlags; // r8d
  int v8; // r8d
  int v9; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaRagdollInstance::`vftable;
  v2 = 0;
  if ( this->m_rigidBodies.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_rigidBodies.m_data[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_rigidBodies.m_size );
  }
  v4 = 0;
  if ( this->m_constraints.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_constraints.m_data[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_constraints.m_size );
  }
  m_pntr = this->m_skeleton.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_skeleton.m_pntr = 0i64;
  m_capacityAndFlags = this->m_boneToRigidBodyMap.m_capacityAndFlags;
  this->m_boneToRigidBodyMap.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_boneToRigidBodyMap.m_data,
      4 * m_capacityAndFlags);
  this->m_boneToRigidBodyMap.m_data = 0i64;
  this->m_boneToRigidBodyMap.m_capacityAndFlags = 0x80000000;
  v8 = this->m_constraints.m_capacityAndFlags;
  this->m_constraints.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_constraints.m_data,
      8 * v8);
  this->m_constraints.m_data = 0i64;
  this->m_constraints.m_capacityAndFlags = 0x80000000;
  v9 = this->m_rigidBodies.m_capacityAndFlags;
  this->m_rigidBodies.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_rigidBodies.m_data,
      8 * v9);
  this->m_rigidBodies.m_data = 0i64;
  this->m_rigidBodies.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 71
// RVA: 0xC50BD0
void __fastcall hkaRagdollInstance::getPoseWorldSpace(
        hkaRagdollInstance *this,
        hkQsTransformf *poseOut,
        hkQsTransformf *worldFromModel,
        hkQsTransformf *localSpacePoseForUnmappedBonesOptional)
{
  hkQsTransformf *m_data; // rax
  hkaSkeleton *m_pntr; // r9
  int v9; // ebx
  char *v10; // rdx
  __int64 v11; // rbp
  __int64 v12; // r14
  __m128 *p_m_quad; // r12
  __int64 v14; // rcx
  hkpRigidBody *v15; // rdx
  __int64 v16; // rcx
  __int64 v17; // rcx
  hkVector4f v18; // xmm8
  hkQuaternionf v19; // xmm7
  hkVector4f v20; // xmm9
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

  m_data = localSpacePoseForUnmappedBonesOptional;
  if ( !localSpacePoseForUnmappedBonesOptional )
    m_data = this->m_skeleton.m_pntr->m_referencePose.m_data;
  m_pntr = this->m_skeleton.m_pntr;
  v9 = 0;
  if ( m_pntr->m_bones.m_size > 0 )
  {
    v10 = (char *)((char *)poseOut - (char *)m_data);
    v11 = 0i64;
    v12 = 0i64;
    p_m_quad = &m_data->m_rotation.m_vec.m_quad;
    v33 = v10;
    while ( 1 )
    {
      v14 = this->m_boneToRigidBodyMap.m_data[v12];
      if ( (int)v14 < 0 )
        goto LABEL_9;
      v15 = this->m_rigidBodies.m_data[v14];
      if ( !v15 )
        break;
      hkQsTransformf::setFromTransformNoScale(&poseOut[v9], &v15->m_motion.m_motionState.m_transform);
      hkaSkeletonUtils::getModelSpaceScale(
        this->m_skeleton.m_pntr,
        this->m_skeleton.m_pntr->m_referencePose.m_data,
        v9,
        &poseOut[v9].m_scale);
      v10 = v33;
LABEL_13:
      m_pntr = this->m_skeleton.m_pntr;
      ++v9;
      ++v12;
      ++v11;
      p_m_quad += 3;
      if ( v9 >= m_pntr->m_bones.m_size )
        return;
    }
    v10 = v33;
LABEL_9:
    v16 = m_pntr->m_parentIndices.m_data[v11];
    if ( (int)v16 < 0 )
    {
      v18.m_quad = (__m128)worldFromModel->m_translation;
      v19.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
      v20.m_quad = (__m128)worldFromModel->m_scale;
    }
    else
    {
      v17 = v16;
      v18.m_quad = (__m128)poseOut[v17].m_translation;
      v19.m_vec.m_quad = (__m128)poseOut[v17].m_rotation;
      v20.m_quad = (__m128)poseOut[v17].m_scale;
    }
    v21 = p_m_quad[-1];
    v22 = _mm_shuffle_ps(v19.m_vec.m_quad, v19.m_vec.m_quad, 201);
    v23 = _mm_mul_ps(v19.m_vec.m_quad, v21);
    v24 = _mm_shuffle_ps(v19.m_vec.m_quad, v19.m_vec.m_quad, 255);
    v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v19.m_vec.m_quad), _mm_mul_ps(v22, v21));
    v26 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                  _mm_shuffle_ps(v23, v23, 170)),
                v19.m_vec.m_quad),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v24, v24), (__m128)xmmword_141A711B0), v21)),
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24));
    *(__m128 *)((char *)p_m_quad + (_QWORD)v10 - 16) = _mm_add_ps(_mm_add_ps(v26, v26), v18.m_quad);
    v27 = _mm_shuffle_ps(*p_m_quad, *p_m_quad, 255);
    v28 = _mm_mul_ps(_mm_shuffle_ps(*p_m_quad, *p_m_quad, 201), v19.m_vec.m_quad);
    v29 = _mm_mul_ps(v19.m_vec.m_quad, v27);
    v30 = _mm_mul_ps(v19.m_vec.m_quad, *p_m_quad);
    v31 = _mm_sub_ps(v28, _mm_mul_ps(v22, *p_m_quad));
    v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 201), _mm_mul_ps(v24, *p_m_quad)), v29);
    *(__m128 *)((char *)p_m_quad + (_QWORD)v10) = _mm_shuffle_ps(
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
    *(__m128 *)((char *)p_m_quad + (_QWORD)v10 + 16) = _mm_mul_ps(p_m_quad[1], v20.m_quad);
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
void __fastcall hkaRagdollInstance::getApproxCurrentPoseWorldSpace(
        hkaRagdollInstance *this,
        hkQsTransformf *poseWorldSpaceOut)
{
  hkpWorld *World; // rax
  float CurrentTime; // xmm0_4

  World = hkaRagdollInstance::getWorld(this);
  if ( World )
  {
    CurrentTime = hkpWorld::getCurrentTime(World);
    hkaRagdollInstance::getApproxPoseWorldSpaceAt(this, CurrentTime, poseWorldSpaceOut);
  }
  else
  {
    hkaRagdollInstance::getPoseWorldSpace(this, poseWorldSpaceOut);
  }
}

// File Line: 126
// RVA: 0xC50E90
void __fastcall hkaRagdollInstance::getApproxPoseWorldSpaceAt(
        hkaRagdollInstance *this,
        float time,
        hkQsTransformf *poseWorldSpaceOut)
{
  int v3; // ebx
  int m_size; // ebp

  v3 = 0;
  m_size = this->m_skeleton.m_pntr->m_bones.m_size;
  if ( m_size > 0 )
  {
    do
      hkaRagdollInstance::getApproxWorldFromBoneTransformAt(this, v3++, time, poseWorldSpaceOut++);
    while ( v3 < m_size );
  }
}

// File Line: 136
// RVA: 0xC50FF0
void __fastcall hkaRagdollInstance::getPoseModelSpace(
        hkaRagdollInstance *this,
        hkQsTransformf *poseOut,
        hkQsTransformf *worldFromModel)
{
  hkQsTransformf *v3; // rbp
  __int64 m_size; // rsi
  __m128i inserted; // xmm0
  __int64 v8; // rax
  __m128 v9; // xmm9
  __m128 v10; // xmm5
  hkVector4f v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm9
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm8
  __m128 v17; // xmm7
  __m128 m_quad; // xmm2
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm4
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  hkVector4f v27; // [rsp+20h] [rbp-78h] BYREF

  v3 = poseOut;
  hkaRagdollInstance::getPoseWorldSpace(this, poseOut);
  m_size = this->m_skeleton.m_pntr->m_bones.m_size;
  hkVector4f::setRotatedInverseDir(&v27, &worldFromModel->m_rotation, &worldFromModel->m_translation);
  inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
  v8 = m_size;
  v9 = (__m128)_mm_shuffle_epi32(inserted, 0);
  v10 = (__m128)_mm_shuffle_epi32(inserted, 64);
  v11.m_quad = (__m128)worldFromModel->m_scale;
  v12 = _mm_xor_ps(v10, worldFromModel->m_rotation.m_vec.m_quad);
  v13 = _mm_xor_ps(v9, v27.m_quad);
  v14 = _mm_rcp_ps(v11.m_quad);
  v15 = (__m128)_mm_srli_si128(
                  _mm_slli_si128((__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11.m_quad, v14)), v14), 4),
                  4);
  if ( m_size > 0 )
  {
    v16 = _mm_shuffle_ps(v12, v12, 201);
    v17 = _mm_shuffle_ps(v12, v12, 255);
    do
    {
      m_quad = v3->m_translation.m_quad;
      ++v3;
      v19 = _mm_mul_ps(m_quad, v12);
      v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v12), _mm_mul_ps(m_quad, v16));
      v21 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                    _mm_shuffle_ps(v19, v19, 170)),
                  v12),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v17, v17), (__m128)xmmword_141A711B0), m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v17));
      v3[-1].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v21, v21), v13);
      v22 = v3[-1].m_rotation.m_vec.m_quad;
      v23 = _mm_shuffle_ps(v22, v22, 255);
      v24 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v12), _mm_mul_ps(v16, v22));
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
void __fastcall hkaRagdollInstance::setPoseModelSpace(
        hkaRagdollInstance *this,
        hkQsTransformf *poseIn,
        hkQsTransformf *worldFromModel)
{
  __int64 v3; // rdi
  __int64 m_size; // r15
  __int64 v8; // rcx
  hkpRigidBody *v9; // r14
  hkQuaternionf v10; // xmm2
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm4
  hkQuaternionf v15; // xmm2
  hkQuaternionf v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm5
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __m128 v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  hkVector4f position; // [rsp+20h] [rbp-58h] BYREF
  hkQuaternionf rotation; // [rsp+30h] [rbp-48h] BYREF
  __m128 v29; // [rsp+40h] [rbp-38h]

  v3 = 0i64;
  m_size = this->m_skeleton.m_pntr->m_bones.m_size;
  if ( m_size > 0 )
  {
    do
    {
      v8 = this->m_boneToRigidBodyMap.m_data[v3];
      if ( (int)v8 >= 0 )
      {
        v9 = this->m_rigidBodies.m_data[v8];
        if ( v9 )
        {
          v10.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
          v11 = _mm_mul_ps(v10.m_vec.m_quad, poseIn->m_translation.m_quad);
          v12 = _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(poseIn->m_translation.m_quad, poseIn->m_translation.m_quad, 201),
                    v10.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 201), poseIn->m_translation.m_quad));
          v13 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 255);
          v14 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)),
                    _mm_shuffle_ps(v11, v11, 170)),
                  v10.m_vec.m_quad);
          v15.m_vec.m_quad = (__m128)poseIn->m_rotation;
          v16.m_vec.m_quad = (__m128)worldFromModel->m_rotation;
          v17 = _mm_add_ps(
                  _mm_add_ps(
                    v14,
                    _mm_mul_ps(
                      _mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0),
                      poseIn->m_translation.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13));
          v18 = _mm_mul_ps(v16.m_vec.m_quad, v15.m_vec.m_quad);
          position.m_quad = _mm_add_ps(_mm_add_ps(v17, v17), worldFromModel->m_translation.m_quad);
          v19 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v15.m_vec.m_quad, v15.m_vec.m_quad, 201), v16.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 201), v15.m_vec.m_quad));
          v20 = _mm_shuffle_ps(v15.m_vec.m_quad, v15.m_vec.m_quad, 255);
          v21 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v19, v19, 201), _mm_mul_ps(v15.m_vec.m_quad, v13)),
                  _mm_mul_ps(v16.m_vec.m_quad, v20));
          v22 = _mm_shuffle_ps(
                  v21,
                  _mm_unpackhi_ps(
                    v21,
                    _mm_sub_ps(
                      _mm_mul_ps(v20, v13),
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                        _mm_shuffle_ps(v18, v18, 170)))),
                  196);
          v23 = _mm_mul_ps(v22, v22);
          v29 = _mm_mul_ps(poseIn->m_scale.m_quad, worldFromModel->m_scale.m_quad);
          v24 = _mm_add_ps(_mm_shuffle_ps(v23, v23, 78), v23);
          v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 177), v24);
          v26 = _mm_rsqrt_ps(v25);
          rotation.m_vec.m_quad = _mm_mul_ps(
                                    v22,
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                                      _mm_mul_ps(*(__m128 *)_xmm, v26)));
          hkpRigidBody::setPositionAndRotation(v9, &position, &rotation);
          hkpEntity::activate(v9);
          v9->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&v9->m_motion, (unsigned int)&aabbOut);
          hkpEntity::activate(v9);
          ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v9->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
            &v9->m_motion,
            &aabbOut);
        }
      }
      ++v3;
      ++poseIn;
    }
    while ( v3 < m_size );
  }
}

// File Line: 179
// RVA: 0xC51400
void __fastcall hkaRagdollInstance::setPoseAndVelocitiesModelSpace(
        hkaRagdollInstance *this,
        hkQsTransformf *poseModelSpaceA,
        hkQsTransformf *worldFromModelA,
        hkQsTransformf *poseModelSpaceB,
        hkQsTransformf *worldFromModelB,
        float timestep)
{
  __int64 v6; // rbx
  __int64 m_size; // r15
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm14
  hkQuaternionf *p_m_rotation; // rbp
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
  __m128 m_quad; // xmm3
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
  __m128 v69; // xmm2
  __m128 v70; // xmm5
  __m128 v71; // xmm4
  __m128 v72; // xmm3
  __m128 v73; // xmm2
  __m128 v74; // xmm1
  __m128 v75; // xmm5
  __m128 v76; // xmm2
  __m128 v77; // xmm2
  __m128 v78; // xmm1
  __m128 v79; // [rsp+20h] [rbp-128h] BYREF
  __m128 v80; // [rsp+30h] [rbp-118h] BYREF
  hkVector4f position; // [rsp+40h] [rbp-108h] BYREF
  hkQuaternionf rotation; // [rsp+50h] [rbp-F8h] BYREF
  __m128 v83; // [rsp+60h] [rbp-E8h]
  unsigned int v84; // [rsp+150h] [rbp+8h]
  hkQsTransformf *v85; // [rsp+160h] [rbp+18h]

  v85 = worldFromModelA;
  v6 = 0i64;
  m_size = this->m_skeleton.m_pntr->m_bones.m_size;
  v9 = _mm_shuffle_ps((__m128)LODWORD(timestep), (__m128)LODWORD(timestep), 0);
  v10 = _mm_rcp_ps(v9);
  v11 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v9, v10)), v10);
  if ( m_size > 0 )
  {
    p_m_rotation = &poseModelSpaceB->m_rotation;
    v13 = (char *)poseModelSpaceA - (char *)poseModelSpaceB;
    do
    {
      v14 = this->m_boneToRigidBodyMap.m_data[v6];
      if ( (int)v14 >= 0 )
      {
        v15 = this->m_rigidBodies.m_data[v14];
        if ( v15 )
        {
          v16.m_vec.m_quad = (__m128)worldFromModelA->m_rotation;
          v17 = *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + v13);
          v18 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 201), v17));
          v19 = _mm_mul_ps(v16.m_vec.m_quad, v17);
          v20 = _mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 255);
          v21 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v17);
          v22 = *(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v13);
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
          v25 = _mm_shuffle_ps(v22, v22, 255);
          v26 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v16.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 201), v22));
          v27 = _mm_mul_ps(v22, v16.m_vec.m_quad);
          v28 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_shuffle_ps(v26, v26, 201),
                    _mm_mul_ps(*(__m128 *)((char *)&p_m_rotation->m_vec.m_quad + v13), v20)),
                  _mm_mul_ps(v16.m_vec.m_quad, v25));
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
          m_quad = p_m_rotation[-1].m_vec.m_quad;
          v38 = _mm_mul_ps(v35.m_vec.m_quad, m_quad);
          v39 = _mm_shuffle_ps(v35.m_vec.m_quad, v35.m_vec.m_quad, 255);
          v40 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v35.m_vec.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v35.m_vec.m_quad, v35.m_vec.m_quad, 201), m_quad));
          v41 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                    _mm_shuffle_ps(v38, v38, 170)),
                  v35.m_vec.m_quad);
          v42 = p_m_rotation->m_vec.m_quad;
          v43.m_vec.m_quad = (__m128)worldFromModelB->m_rotation;
          v44 = _mm_add_ps(
                  _mm_add_ps(v41, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v39, v39), (__m128)xmmword_141A711B0), m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39));
          v45 = _mm_mul_ps(_mm_shuffle_ps(v43.m_vec.m_quad, v43.m_vec.m_quad, 201), p_m_rotation->m_vec.m_quad);
          v46 = _mm_mul_ps(v43.m_vec.m_quad, p_m_rotation->m_vec.m_quad);
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
          v83 = _mm_mul_ps(p_m_rotation[1].m_vec.m_quad, worldFromModelB->m_scale.m_quad);
          v52 = _mm_add_ps(_mm_shuffle_ps(v51, v51, 78), v51);
          v53 = _mm_add_ps(_mm_shuffle_ps(v52, v52, 177), v52);
          v54 = _mm_rsqrt_ps(v53);
          rotation.m_vec.m_quad = _mm_mul_ps(
                                    v50,
                                    _mm_mul_ps(
                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
                                      _mm_mul_ps(v54, *(__m128 *)_xmm)));
          hkpRigidBody::setPositionAndRotation(v15, &position, &rotation);
          v80 = _mm_mul_ps(_mm_sub_ps(position.m_quad, v24), v11);
          hkpEntity::activate(v15);
          v15->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&v15->m_motion, (unsigned int)&v80);
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
          if ( (float)((float)(_mm_shuffle_ps(v65, v65, 85).m128_f32[0] + _mm_shuffle_ps(v65, v65, 0).m128_f32[0])
                     + _mm_shuffle_ps(v65, v65, 170).m128_f32[0]) > 1.4210855e-14 )
          {
            v66 = (__m128i)_mm_shuffle_ps(v64, v64, 255);
            v67 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v66, 1u), 1u);
            v68 = _mm_andnot_ps(*(__m128 *)_xmm, v67);
            v69 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v68), *(__m128 *)_xmm);
            v70 = _mm_cmplt_ps(*(__m128 *)_xmm, v68);
            v71 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v69), v70), _mm_andnot_ps(v70, v68));
            v72 = _mm_or_ps(_mm_andnot_ps(v70, _mm_mul_ps(v68, v68)), _mm_and_ps(v70, v69));
            v73 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v72, *(__m128 *)coeff4), *(__m128 *)coeff3), v72),
                                  *(__m128 *)coeff2),
                                v72),
                              *(__m128 *)coeff1),
                            v72),
                          *(__m128 *)coeff0),
                        v72),
                      v71),
                    v71);
            v74 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v73, v73)), v70);
            v75 = _mm_andnot_ps(v70, v73);
            v76 = _mm_cmplt_ps(v68, *(__m128 *)_xmm);
            *(float *)&v84 = (float)(1.5707964
                                   - COERCE_FLOAT((_mm_andnot_ps(v76, _mm_or_ps(v74, v75)).m128_u32[0] | v76.m128_i32[0] & v68.m128_i32[0]) ^ v67.m128_i32[0] & _xmm[0]))
                           * 2.0;
            v77 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                    _mm_shuffle_ps(v65, v65, 170));
            v78 = _mm_rsqrt_ps(v77);
            v79 = _mm_mul_ps(
                    _mm_xor_ps(
                      (__m128)_mm_slli_epi32(
                                _mm_srli_epi32((__m128i)_mm_cmplt_ps((__m128)v66, (__m128)0i64), 0x1Fu),
                                0x1Fu),
                      _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmple_ps(v77, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v78, v77), v78)),
                            _mm_mul_ps(v78, *(__m128 *)_xmm))),
                        v64)),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)v84, (__m128)v84, 0), v11));
          }
          else
          {
            v79 = 0i64;
          }
          hkpEntity::activate(v15);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v15->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
            &v15->m_motion,
            &v79);
          worldFromModelA = v85;
        }
      }
      ++v6;
      p_m_rotation += 3;
    }
    while ( v6 < m_size );
  }
}

// File Line: 232
// RVA: 0xC50F00
void __fastcall hkaRagdollInstance::setPoseWorldSpace(hkaRagdollInstance *this, hkQsTransformf *poseWorldSpaceIn)
{
  int v2; // esi
  __int64 m_size; // r15
  __int64 i; // rbx
  __int64 v7; // rcx
  hkpRigidBody *v8; // rbp

  v2 = 0;
  m_size = this->m_skeleton.m_pntr->m_bones.m_size;
  for ( i = 0i64; i < m_size; ++v2 )
  {
    v7 = this->m_boneToRigidBodyMap.m_data[i];
    if ( (int)v7 >= 0 )
    {
      v8 = this->m_rigidBodies.m_data[v7];
      if ( v8 )
      {
        hkpRigidBody::setPositionAndRotation(v8, &poseWorldSpaceIn[v2].m_translation, &poseWorldSpaceIn[v2].m_rotation);
        hkpEntity::activate(v8);
        v8->m_motion.hkpEntity::vfptr[9].__vecDelDtor(&v8->m_motion, (unsigned int)&aabbOut);
        hkpEntity::activate(v8);
        ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *))v8->m_motion.hkpEntity::vfptr[9].__first_virtual_table_function__)(
          &v8->m_motion,
          &aabbOut);
      }
    }
    ++i;
  }
}

// File Line: 255
// RVA: 0xC51A80
hkResult *__fastcall hkaRagdollInstance::addToWorld(
        hkaRagdollInstance *this,
        hkResult *result,
        hkpWorld *world,
        hkBool updateFilter)
{
  int v8; // esi
  __int64 v9; // rbx
  __int64 m_size; // rsi
  __int64 i; // rbx

  if ( hkaRagdollInstance::getWorld(this) )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    hkpWorld::addEntityBatch(
      world,
      this->m_rigidBodies.m_data,
      this->m_rigidBodies.m_size,
      HK_ENTITY_ACTIVATION_DO_ACTIVATE);
    v8 = 0;
    if ( this->m_constraints.m_size > 0 )
    {
      v9 = 0i64;
      do
      {
        hkpWorld::addConstraint(world, this->m_constraints.m_data[v9]);
        ++v8;
        ++v9;
      }
      while ( v8 < this->m_constraints.m_size );
    }
    if ( updateFilter.m_bool )
    {
      m_size = this->m_rigidBodies.m_size;
      for ( i = 0i64; i < m_size; ++i )
        hkpWorld::updateCollisionFilterOnEntity(
          world,
          this->m_rigidBodies.m_data[i],
          HK_UPDATE_FILTER_ON_ENTITY_DISABLE_ENTITY_ENTITY_COLLISIONS_ONLY,
          HK_UPDATE_COLLECTION_FILTER_IGNORE_SHAPE_COLLECTIONS);
    }
    result->m_enum = HK_SUCCESS;
    return result;
  }
}

// File Line: 286
// RVA: 0xC51B60
hkResult *__fastcall hkaRagdollInstance::removeFromWorld(hkaRagdollInstance *this, hkResult *result)
{
  hkpWorld *World; // rbp
  int v6; // edi
  __int64 v7; // rsi
  hkpConstraintInstance *v8; // r8
  int m_size; // eax
  hkpEntity **v10; // rsi
  int v11; // edi
  int v12; // edx
  int v13; // r8d
  __int64 v14; // rcx
  _QWORD *v15; // r9
  hkpRigidBody *v16; // r10
  int resulta; // [rsp+50h] [rbp+18h] BYREF

  World = hkaRagdollInstance::getWorld(this);
  if ( World )
  {
    v6 = 0;
    if ( this->m_constraints.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = this->m_constraints.m_data[v7];
        if ( v8->m_owner )
          hkpWorld::removeConstraint(World, (hkBool *)&resulta, v8);
        ++v6;
        ++v7;
      }
      while ( v6 < this->m_constraints.m_size );
    }
    m_size = this->m_rigidBodies.m_size;
    if ( m_size )
    {
      resulta = 8 * m_size;
      v10 = (hkpEntity **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                            &hkContainerHeapAllocator::s_alloc,
                            &resulta);
      m_size = resulta / 8;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = 0x80000000;
    if ( m_size )
      v11 = m_size;
    v12 = 0;
    v13 = 0;
    if ( this->m_rigidBodies.m_size > 0 )
    {
      v14 = 0i64;
      v15 = v10;
      do
      {
        v16 = this->m_rigidBodies.m_data[v14];
        if ( v16->m_world == World )
        {
          *v15 = v16;
          ++v13;
          ++v15;
        }
        ++v12;
        ++v14;
      }
      while ( v12 < this->m_rigidBodies.m_size );
    }
    hkpWorld::removeEntityBatch(World, v10, v13);
    result->m_enum = HK_SUCCESS;
    if ( v11 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 8 * v11);
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 325
// RVA: 0xC50770
hkaRagdollInstance *__fastcall hkaRagdollInstance::clone(
        hkaRagdollInstance *this,
        hkpConstraintInstance::CloningMode mode)
{
  __int64 m_size; // rbx
  __int64 v3; // r15
  __int64 v4; // r12
  hkLifoAllocator *Value; // rax
  hkpRigidBody **m_cur; // r8
  int v9; // edx
  char *v10; // rcx
  int v11; // ecx
  int v12; // r9d
  hkLifoAllocator *v13; // rax
  IAmdDxExtQuadBufferStereo *v14; // rcx
  int v15; // edx
  char *v16; // r8
  int v17; // r9d
  __int64 v18; // rdi
  __int64 v19; // r14
  hkpRigidBody *v20; // rcx
  hkpRigidBody **v21; // rbx
  hkpConstraintInstance *v22; // rcx
  unsigned __int64 v23; // rbx
  hkpEntity *v24; // rdi
  hkpEntity *v25; // rax
  IAmdDxExtQuadBufferStereo *v26; // rbx
  hkpConstraintInstance *v27; // rax
  _QWORD **v28; // rax
  hkaRagdollInstance *v29; // rax
  __int64 v30; // rax
  __int64 v31; // rsi
  __int64 i; // rbx
  __int64 j; // rbx
  int mExtension; // eax
  char *v35; // rdi
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // r8d
  int v39; // eax
  char *v40; // rdi
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // r8d
  AMD_HD3D v45; // [rsp+30h] [rbp-50h] BYREF
  void *p; // [rsp+50h] [rbp-30h]
  int v47; // [rsp+58h] [rbp-28h]
  hkArrayBase<hkpRigidBody *> array; // [rsp+60h] [rbp-20h] BYREF
  void *m_data; // [rsp+70h] [rbp-10h]
  int v50; // [rsp+78h] [rbp-8h]
  hkResult result; // [rsp+B0h] [rbp+30h] BYREF

  m_size = this->m_rigidBodies.m_size;
  v3 = this->m_constraints.m_size;
  v4 = 0i64;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v50 = m_size;
  if ( (_DWORD)m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpRigidBody **)Value->m_cur;
    v9 = (8 * m_size + 127) & 0xFFFFFF80;
    v10 = (char *)m_cur + v9;
    if ( v9 > Value->m_slabSize || v10 > Value->m_end )
    {
      array.m_data = (hkpRigidBody **)hkLifoAllocator::allocateFromNewSlab(Value, v9);
    }
    else
    {
      Value->m_cur = v10;
      array.m_data = m_cur;
    }
  }
  else
  {
    array.m_data = 0i64;
  }
  m_data = array.m_data;
  array.m_capacityAndFlags = m_size | 0x80000000;
  v11 = m_size & 0x3FFFFFFF;
  if ( (m_size & 0x3FFFFFFF) < (int)m_size )
  {
    v12 = m_size;
    if ( (int)m_size < 2 * v11 )
      v12 = 2 * v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v12, 8);
  }
  array.m_size = m_size;
  v45.mStereo = 0i64;
  v45.mExtension = (IAmdDxExt *)0x8000000000000000i64;
  v47 = v3;
  if ( (_DWORD)v3 )
  {
    v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (IAmdDxExtQuadBufferStereo *)v13->m_cur;
    v15 = (8 * v3 + 127) & 0xFFFFFF80;
    v16 = (char *)v14 + v15;
    if ( v15 > v13->m_slabSize || v16 > v13->m_end )
      v14 = (IAmdDxExtQuadBufferStereo *)hkLifoAllocator::allocateFromNewSlab(v13, v15);
    else
      v13->m_cur = v16;
  }
  else
  {
    v14 = 0i64;
  }
  v45.mStereo = v14;
  p = v14;
  HIDWORD(v45.mExtension) = v3 | 0x80000000;
  if ( (v3 & 0x3FFFFFFF) < (int)v3 )
  {
    v17 = v3;
    if ( (int)v3 < (int)(2 * (v3 & 0x3FFFFFFF)) )
      v17 = 2 * (v3 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v45.mStereo, v17, 8);
  }
  LODWORD(v45.mExtension) = v3;
  *(_QWORD *)&v45.mEnableStereo = 0i64;
  v45.mWidth = 0;
  v45.mHeight = -1;
  v18 = 0i64;
  v19 = m_size;
  if ( (int)m_size > 0 )
  {
    do
    {
      v20 = this->m_rigidBodies.m_data[v18];
      v21 = &array.m_data[v18];
      *v21 = (hkpRigidBody *)((__int64 (__fastcall *)(hkpRigidBody *))v20->vfptr[3].__first_virtual_table_function__)(v20);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v45,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)this->m_rigidBodies.m_data[v18],
        (unsigned __int64)array.m_data[v18]);
      ++v18;
    }
    while ( v18 < v19 );
  }
  if ( v3 > 0 )
  {
    do
    {
      v22 = this->m_constraints.m_data[v4];
      v23 = (unsigned __int64)v22->m_entities[1];
      v24 = (hkpEntity *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v45,
                           (unsigned __int64)v22->m_entities[0],
                           0i64);
      v25 = (hkpEntity *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v45,
                           v23,
                           0i64);
      v26 = &v45.mStereo[v4];
      v27 = hkpConstraintInstance::clone(this->m_constraints.m_data[v4++], v24, v25, mode);
      v26->vfptr = (IAmdDxExtInterfaceVtbl *)v27;
    }
    while ( v4 < v3 );
  }
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (hkaRagdollInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v28[11] + 8i64))(v28[11], 72i64);
  if ( v29 )
  {
    hkaRagdollInstance::hkaRagdollInstance(
      v29,
      &array,
      (hkArrayBase<hkpConstraintInstance *> *)&v45.mStereo,
      this->m_skeleton.m_pntr,
      &this->m_boneToRigidBodyMap);
    v31 = v30;
  }
  else
  {
    v31 = 0i64;
  }
  for ( i = 0i64; i < v19; ++i )
    hkReferencedObject::removeReference(array.m_data[i]);
  for ( j = 0i64; j < v3; ++j )
    hkReferencedObject::removeReference((hkReferencedObject *)v45.mStereo[j].vfptr);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v45,
    &hkContainerHeapAllocator::s_alloc);
  _(&v45);
  mExtension = (int)v45.mExtension;
  v35 = (char *)p;
  if ( p == v45.mStereo )
    mExtension = 0;
  LODWORD(v45.mExtension) = mExtension;
  v36 = (8 * v47 + 127) & 0xFFFFFF80;
  v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v38 = (v36 + 15) & 0xFFFFFFF0;
  if ( v36 > v37->m_slabSize || &v35[v38] != v37->m_cur || v37->m_firstNonLifoEnd == v35 )
    hkLifoAllocator::slowBlockFree(v37, v35, v38);
  else
    v37->m_cur = v35;
  LODWORD(v45.mExtension) = 0;
  if ( SHIDWORD(v45.mExtension) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v45.mStereo,
      8 * HIDWORD(v45.mExtension));
  v39 = array.m_size;
  v40 = (char *)m_data;
  v45.mStereo = 0i64;
  HIDWORD(v45.mExtension) = 0x80000000;
  if ( m_data == array.m_data )
    v39 = 0;
  array.m_size = v39;
  v41 = (8 * v50 + 127) & 0xFFFFFF80;
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (v41 + 15) & 0xFFFFFFF0;
  if ( v41 > v42->m_slabSize || &v40[v43] != v42->m_cur || v42->m_firstNonLifoEnd == v40 )
    hkLifoAllocator::slowBlockFree(v42, v40, v43);
  else
    v42->m_cur = v40;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
  return (hkaRagdollInstance *)v31;
}

// File Line: 380
// RVA: 0xC51CF0
void __fastcall hkaRagdollInstance::getWorldFromBoneTransform(
        hkaRagdollInstance *this,
        int i,
        hkQsTransformf *worldFromBoneOut)
{
  __int64 v3; // rbp
  __int64 v5; // rcx
  hkpRigidBody *v7; // rdx
  int v8; // edx
  __m128 v9; // xmm8
  __m128 m_quad; // xmm7
  hkVector4f v11; // xmm9
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  hkQsTransformf *v14; // rcx
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
  hkQsTransformf worldFromBoneOuta; // [rsp+20h] [rbp-78h] BYREF

  v3 = i;
  v5 = this->m_boneToRigidBodyMap.m_data[i];
  if ( (int)v5 >= 0 && (v7 = this->m_rigidBodies.m_data[v5]) != 0i64 )
  {
    hkQsTransformf::setFromTransformNoScale(worldFromBoneOut, &v7->m_motion.m_motionState.m_transform);
    hkaSkeletonUtils::getModelSpaceScale(
      this->m_skeleton.m_pntr,
      this->m_skeleton.m_pntr->m_referencePose.m_data,
      v3,
      &worldFromBoneOut->m_scale);
  }
  else
  {
    v8 = this->m_skeleton.m_pntr->m_parentIndices.m_data[v3];
    if ( v8 < 0 )
    {
      m_quad = qi.m_vec.m_quad;
      v9 = query.m_quad;
      v11.m_quad = 0i64;
      worldFromBoneOuta.m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
      worldFromBoneOuta.m_scale = (hkVector4f)query.m_quad;
      worldFromBoneOuta.m_translation = 0i64;
    }
    else
    {
      hkaRagdollInstance::getWorldFromBoneTransform(this, v8, &worldFromBoneOuta);
      v9 = worldFromBoneOuta.m_scale.m_quad;
      m_quad = worldFromBoneOuta.m_rotation.m_vec.m_quad;
      v11.m_quad = (__m128)worldFromBoneOuta.m_translation;
    }
    v12 = _mm_shuffle_ps(m_quad, m_quad, 255);
    v13 = _mm_shuffle_ps(m_quad, m_quad, 201);
    v14 = &this->m_skeleton.m_pntr->m_referencePose.m_data[v3];
    v15 = _mm_mul_ps(v14->m_translation.m_quad, m_quad);
    v16 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14->m_translation.m_quad, v14->m_translation.m_quad, 201), m_quad),
            _mm_mul_ps(v13, v14->m_translation.m_quad));
    v17 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                  _mm_shuffle_ps(v15, v15, 170)),
                m_quad),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v14->m_translation.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v12));
    worldFromBoneOut->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v17, v17), v11.m_quad);
    v18 = v14->m_rotation.m_vec.m_quad;
    v19 = _mm_shuffle_ps(v18, v18, 255);
    v20 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), m_quad);
    v21 = _mm_mul_ps(m_quad, v19);
    v22 = _mm_mul_ps(m_quad, v18);
    v23 = _mm_sub_ps(v20, _mm_mul_ps(v13, v18));
    v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(v12, v18)), v21);
    worldFromBoneOut->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                  v24,
                                                  _mm_unpackhi_ps(
                                                    v24,
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(v19, v12),
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v22, v22, 85),
                                                          _mm_shuffle_ps(v22, v22, 0)),
                                                        _mm_shuffle_ps(v22, v22, 170)))),
                                                  196);
    worldFromBoneOut->m_scale.m_quad = _mm_mul_ps(v14->m_scale.m_quad, v9);
  }
}

// File Line: 414
// RVA: 0xC51EF0
void __fastcall hkaRagdollInstance::getApproxWorldFromBoneTransformAt(
        hkaRagdollInstance *this,
        int i,
        float time,
        hkQsTransformf *worldFromBoneOut)
{
  __int64 v4; // rbp
  __int64 v6; // rcx
  hkpRigidBody *v8; // rcx
  int v9; // edx
  __m128 v10; // xmm8
  __m128 m_quad; // xmm7
  hkVector4f v12; // xmm9
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  hkQsTransformf *v15; // rcx
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
  hkTransformf transformOut; // [rsp+20h] [rbp-88h] BYREF

  v4 = i;
  v6 = this->m_boneToRigidBodyMap.m_data[i];
  if ( (int)v6 >= 0 && (v8 = this->m_rigidBodies.m_data[v6]) != 0i64 )
  {
    hkpMotion::approxTransformAt(&v8->m_motion, time, &transformOut);
    hkQsTransformf::setFromTransformNoScale(worldFromBoneOut, &transformOut);
    hkaSkeletonUtils::getModelSpaceScale(
      this->m_skeleton.m_pntr,
      this->m_skeleton.m_pntr->m_referencePose.m_data,
      v4,
      &worldFromBoneOut->m_scale);
  }
  else
  {
    v9 = this->m_skeleton.m_pntr->m_parentIndices.m_data[i];
    if ( v9 < 0 )
    {
      m_quad = qi.m_vec.m_quad;
      v10 = query.m_quad;
      v12.m_quad = 0i64;
      transformOut.m_rotation.m_col1 = (hkVector4f)qi.m_vec.m_quad;
      transformOut.m_rotation.m_col2 = (hkVector4f)query.m_quad;
      transformOut.m_rotation.m_col0 = 0i64;
    }
    else
    {
      hkaRagdollInstance::getApproxWorldFromBoneTransformAt(this, v9, time, (hkQsTransformf *)&transformOut);
      v10 = transformOut.m_rotation.m_col2.m_quad;
      m_quad = transformOut.m_rotation.m_col1.m_quad;
      v12.m_quad = (__m128)transformOut.m_rotation.m_col0;
    }
    v13 = _mm_shuffle_ps(m_quad, m_quad, 255);
    v14 = _mm_shuffle_ps(m_quad, m_quad, 201);
    v15 = &this->m_skeleton.m_pntr->m_referencePose.m_data[v4];
    v16 = _mm_mul_ps(v15->m_translation.m_quad, m_quad);
    v17 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15->m_translation.m_quad, v15->m_translation.m_quad, 201), m_quad),
            _mm_mul_ps(v14, v15->m_translation.m_quad));
    v18 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)),
                  _mm_shuffle_ps(v16, v16, 170)),
                m_quad),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v15->m_translation.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v13));
    worldFromBoneOut->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v18, v18), v12.m_quad);
    v19 = v15->m_rotation.m_vec.m_quad;
    v20 = _mm_shuffle_ps(v19, v19, 255);
    v21 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), m_quad);
    v22 = _mm_mul_ps(m_quad, v20);
    v23 = _mm_mul_ps(m_quad, v19);
    v24 = _mm_sub_ps(v21, _mm_mul_ps(v14, v19));
    v25 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v24, v24, 201), _mm_mul_ps(v13, v19)), v22);
    worldFromBoneOut->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                  v25,
                                                  _mm_unpackhi_ps(
                                                    v25,
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(v20, v13),
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v23, v23, 85),
                                                          _mm_shuffle_ps(v23, v23, 0)),
                                                        _mm_shuffle_ps(v23, v23, 170)))),
                                                  196);
    worldFromBoneOut->m_scale.m_quad = _mm_mul_ps(v15->m_scale.m_quad, v10);
  }
}      196);
    worldFromBoneOut->m_scale.m_quad = _mm_mul_ps(v15->m_scale.m_qua

// File Line: 450
// RVA: 0xC51CB0
hkpWorld *__fastcall hkaRagdollInstance::getWorld(hkaRagdollInstance *this)
{
  __int64 m_size; // r8
  __int64 v2; // rdx
  hkpRigidBody **i; // rcx
  hkpWorld *result; // rax

  m_size = this->m_rigidBodies.m_size;
  v2 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  for ( i = this->m_rigidBodies.m_data; ; ++i )
  {
    result = (*i)->m_world;
    if ( result )
      break;
    if ( ++v2 >= m_size )
      return 0i64;
  }
  return result;
}

