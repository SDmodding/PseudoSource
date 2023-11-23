// File Line: 20
// RVA: 0xB462A0
void __fastcall hkaMirroredSkeleton::hkaMirroredSkeleton(hkaMirroredSkeleton *this, hkaSkeleton *skeleton)
{
  int m_size_low; // ecx
  int v5; // edi
  hkMemoryAllocator **Value; // rax
  __int16 *v7; // rax
  __int16 v8; // si
  char v9; // dl
  __int16 v10; // r8
  __int64 v11; // rcx
  int m_size; // edi
  hkMemoryAllocator **v13; // rax
  __int16 *v14; // rax
  int m_numBones; // edi
  hkMemoryAllocator **v16; // rax
  __int64 v17; // rcx

  this->m_skeleton = skeleton;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaMirroredSkeleton::`vftable;
  this->m_parentIndices = skeleton->m_parentIndices.m_data;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_annotationNameMap.m_map,
    0);
  m_size_low = SLOBYTE(skeleton->m_partitions.m_size);
  this->m_numPartitions = m_size_low;
  v5 = m_size_low;
  this->m_partitions = skeleton->m_partitions.m_data;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (__int16 *)hkMemoryRouter::alignedAlloc(Value[11], 2 * v5, 16);
  v8 = 0;
  v9 = 0;
  this->m_partitionPairMap = v7;
  if ( this->m_numPartitions > 0 )
  {
    v10 = 0;
    do
    {
      v11 = v9++;
      this->m_partitionPairMap[v11] = v10;
      v10 = v9;
    }
    while ( v9 < this->m_numPartitions );
  }
  m_size = skeleton->m_bones.m_size;
  this->m_numBones = m_size;
  v13 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (__int16 *)hkMemoryRouter::alignedAlloc(v13[11], 2 * m_size, 16);
  m_numBones = this->m_numBones;
  this->m_bonePairMap = v14;
  v16 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  this->m_boneInvariants = (hkQuaternionf *)hkMemoryRouter::alignedAlloc(v16[11], 16 * (m_numBones + 1), 16);
  if ( this->m_numBones > 0 )
  {
    do
    {
      this->m_bonePairMap[v8] = v8;
      v17 = v8++;
      this->m_boneInvariants[v17] = (hkQuaternionf)qi.m_vec.m_quad;
    }
    while ( v8 < this->m_numBones );
  }
  this->m_boneInvariants[this->m_numBones] = (hkQuaternionf)qi.m_vec.m_quad;
}

// File Line: 51
// RVA: 0xB46400
void __fastcall hkaMirroredSkeleton::~hkaMirroredSkeleton(hkaMirroredSkeleton *this)
{
  __int16 *m_partitionPairMap; // rbx
  hkMemoryAllocator **Value; // rax
  __int16 *m_bonePairMap; // rbx
  hkMemoryAllocator **v5; // rax
  hkQuaternionf *m_boneInvariants; // rbx
  hkMemoryAllocator **v7; // rax

  m_partitionPairMap = this->m_partitionPairMap;
  this->vfptr = (hkBaseObjectVtbl *)&hkaMirroredSkeleton::`vftable;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(Value[11], m_partitionPairMap);
  m_bonePairMap = this->m_bonePairMap;
  v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(v5[11], m_bonePairMap);
  m_boneInvariants = this->m_boneInvariants;
  v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(v7[11], m_boneInvariants);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_annotationNameMap.m_map);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 62
// RVA: 0xB46490
hkaSkeleton::Partition *__fastcall hkaMirroredSkeleton::getPartitions(hkaMirroredSkeleton *this)
{
  return this->m_partitions;
}

// File Line: 67
// RVA: 0xB464A0
__int64 __fastcall hkaMirroredSkeleton::getNumPartitions(hkaMirroredSkeleton *this)
{
  return (unsigned int)this->m_numPartitions;
}

// File Line: 74
// RVA: 0xB464F0
void __fastcall hkaMirroredSkeleton::mirrorPairedBone(
        hkaMirroredSkeleton *this,
        hkQsTransformf *qInOut,
        int bone,
        bool isAdditive)
{
  int BoneParent; // ebp
  int v9; // edx
  hkQuaternionf *BoneInvariant; // rax
  hkQuaternionf v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm0
  __m128 v16; // xmm6
  hkQuaternionf *v17; // rax
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm5
  __m128 v21; // xmm0
  __m128 v22; // xmm6
  __m128 v23; // xmm5
  hkVector4f v24; // xmm6
  __m128 m_quad; // xmm2
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm3

  BoneParent = hkaMirroredSkeleton::getBoneParent(this, bone);
  v9 = BoneParent;
  if ( !isAdditive )
    v9 = bone;
  BoneInvariant = hkaMirroredSkeleton::getBoneInvariant(this, v9);
  v11.m_vec.m_quad = (__m128)qInOut->m_rotation;
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 201), BoneInvariant->m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(BoneInvariant->m_vec.m_quad, BoneInvariant->m_vec.m_quad, 201), v11.m_vec.m_quad));
  v13 = _mm_mul_ps(BoneInvariant->m_vec.m_quad, v11.m_vec.m_quad);
  v14 = _mm_add_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(v12, v12, 201),
            _mm_mul_ps(_mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 255), BoneInvariant->m_vec.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(BoneInvariant->m_vec.m_quad, BoneInvariant->m_vec.m_quad, 255), v11.m_vec.m_quad));
  v15 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v16 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15)), 196);
  v17 = hkaMirroredSkeleton::getBoneInvariant(this, BoneParent);
  v18 = _mm_shuffle_ps(v16, v16, 255);
  v19 = _mm_shuffle_ps(v17->m_vec.m_quad, v17->m_vec.m_quad, 255);
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v17->m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v17->m_vec.m_quad, v17->m_vec.m_quad, 201), v16));
  v21 = v16;
  v22 = _mm_mul_ps(v16, v17->m_vec.m_quad);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 201), _mm_mul_ps(v21, v19)), _mm_mul_ps(v17->m_vec.m_quad, v18));
  qInOut->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                      v23,
                                      _mm_unpackhi_ps(
                                        v23,
                                        _mm_sub_ps(
                                          _mm_mul_ps(v18, v19),
                                          _mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                                            _mm_shuffle_ps(v22, v22, 170)))),
                                      196);
  v24.m_quad = (__m128)qInOut->m_translation;
  m_quad = hkaMirroredSkeleton::getBoneInvariant(this, BoneParent)->m_vec.m_quad;
  v26 = _mm_shuffle_ps(m_quad, m_quad, 255);
  v27 = _mm_mul_ps(m_quad, v24.m_quad);
  v28 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v24.m_quad, v24.m_quad, 201), m_quad),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v24.m_quad));
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                _mm_shuffle_ps(v27, v27, 170)),
              m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v24.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v26));
  qInOut->m_translation.m_quad = _mm_xor_ps(
                                   (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                   _mm_add_ps(v29, v29));
}

// File Line: 92
// RVA: 0xB47260
void __fastcall hkaMirroredSkeleton::mirrorBonesNormal(
        hkQsTransformf *qInOut,
        const __int16 *parentIndices,
        hkQuaternionf *invariants,
        const __int16 *bonePairMap,
        unsigned int numBones)
{
  hkQuaternionf *p_m_rotation; // rdx
  hkQuaternionf *v7; // rbx
  __int64 v8; // rsi
  __m128 v9; // xmm7
  int v10; // eax
  __m128 v11; // xmm6
  __m128 v12; // xmm3
  __m128 m_quad; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm6
  __m128 v18; // xmm4
  __m128 v19; // xmm5
  __m128 v20; // xmm0
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm3

  if ( (int)numBones > 0 )
  {
    p_m_rotation = &qInOut->m_rotation;
    v7 = invariants + 1;
    v8 = numBones;
    v9 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v10 = *parentIndices + 1;
      v11 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), v7->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v7->m_vec.m_quad, v7->m_vec.m_quad, 201), p_m_rotation->m_vec.m_quad));
      v12 = _mm_mul_ps(p_m_rotation->m_vec.m_quad, v7->m_vec.m_quad);
      m_quad = invariants[v10].m_vec.m_quad;
      v14 = _mm_add_ps(
              _mm_sub_ps(
                _mm_shuffle_ps(v11, v11, 201),
                _mm_mul_ps(
                  _mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255),
                  v7->m_vec.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v7->m_vec.m_quad, v7->m_vec.m_quad, 255), p_m_rotation->m_vec.m_quad));
      v15 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v16 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v17 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15)), 196);
      v18 = _mm_shuffle_ps(v17, v17, 255);
      v19 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v17));
      v20 = _mm_mul_ps(v17, v16);
      v21 = _mm_mul_ps(v17, m_quad);
      v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 201), v20), _mm_mul_ps(m_quad, v18));
      p_m_rotation->m_vec.m_quad = _mm_shuffle_ps(
                                     v22,
                                     _mm_unpackhi_ps(
                                       v22,
                                       _mm_sub_ps(
                                         _mm_mul_ps(v18, v16),
                                         _mm_add_ps(
                                           _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                                           _mm_shuffle_ps(v21, v21, 170)))),
                                     196);
      v23 = invariants[v10].m_vec.m_quad;
      v24 = p_m_rotation[-1].m_vec.m_quad;
      v25 = _mm_mul_ps(v23, v24);
      v26 = _mm_shuffle_ps(v23, v23, 255);
      v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v24));
      p_m_rotation += 3;
      ++v7;
      ++parentIndices;
      v28 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                    _mm_shuffle_ps(v25, v25, 170)),
                  v23),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v24)),
              _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v26));
      p_m_rotation[-4].m_vec.m_quad = _mm_xor_ps(_mm_add_ps(v28, v28), v9);
      --v8;
    }
    while ( v8 );
  }
  hkaMirroredSkeleton::inplaceSwap(qInOut, bonePairMap, numBones);
}

// File Line: 116
// RVA: 0xB47440
void __fastcall hkaMirroredSkeleton::mirrorBonesAdditive(
        hkQsTransformf *qInOut,
        const __int16 *parentIndices,
        hkQuaternionf *invariants,
        const __int16 *bonePairMap,
        unsigned int numBones)
{
  hkQuaternionf *p_m_rotation; // rdx
  __int64 v7; // rbx
  __m128 v8; // xmm7
  int v9; // eax
  __m128 m_quad; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm0
  __m128 v16; // xmm6
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __m128 v19; // xmm0
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm6
  __m128 v26; // xmm5
  __m128 v27; // xmm3

  if ( (int)numBones > 0 )
  {
    p_m_rotation = &qInOut->m_rotation;
    v7 = numBones;
    v8 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v9 = *parentIndices + 1;
      m_quad = invariants[v9].m_vec.m_quad;
      v11 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v12 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), p_m_rotation->m_vec.m_quad));
      v13 = _mm_mul_ps(p_m_rotation->m_vec.m_quad, m_quad);
      v14 = _mm_add_ps(
              _mm_sub_ps(
                _mm_shuffle_ps(v12, v12, 201),
                _mm_mul_ps(_mm_shuffle_ps(p_m_rotation->m_vec.m_quad, p_m_rotation->m_vec.m_quad, 255), m_quad)),
              _mm_mul_ps(v11, p_m_rotation->m_vec.m_quad));
      v15 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v16 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15)), 196);
      v17 = _mm_shuffle_ps(v16, v16, 255);
      v18 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), m_quad),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v16));
      v19 = _mm_mul_ps(v16, v11);
      v20 = _mm_mul_ps(v16, m_quad);
      v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v18, v18, 201), v19), _mm_mul_ps(m_quad, v17));
      p_m_rotation->m_vec.m_quad = _mm_shuffle_ps(
                                     v21,
                                     _mm_unpackhi_ps(
                                       v21,
                                       _mm_sub_ps(
                                         _mm_mul_ps(v17, v11),
                                         _mm_add_ps(
                                           _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                                           _mm_shuffle_ps(v20, v20, 170)))),
                                     196);
      v22 = invariants[v9].m_vec.m_quad;
      v23 = p_m_rotation[-1].m_vec.m_quad;
      v24 = _mm_mul_ps(v22, v23);
      v25 = _mm_shuffle_ps(v22, v22, 255);
      v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v22), _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23));
      p_m_rotation += 3;
      ++parentIndices;
      v27 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                    _mm_shuffle_ps(v24, v24, 170)),
                  v22),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v23)),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v25));
      p_m_rotation[-4].m_vec.m_quad = _mm_xor_ps(_mm_add_ps(v27, v27), v8);
      --v7;
    }
    while ( v7 );
  }
  hkaMirroredSkeleton::inplaceSwap(qInOut, bonePairMap, numBones);
}

// File Line: 140
// RVA: 0xB47800
void __fastcall hkaMirroredSkeleton::inplaceSwap(hkQsTransformf *qInOut, const __int16 *bonePairMap, int numBones)
{
  int v3; // r9d
  __int64 v4; // r11
  __int64 v6; // rax
  hkQsTransformf *v7; // r8
  __int64 v8; // r10
  hkVector4f v9; // xmm4
  hkQuaternionf v10; // xmm3
  hkVector4f v11; // xmm2
  __int64 v12; // rdx

  if ( numBones > 0 )
  {
    v3 = 0;
    v4 = numBones;
    v6 = 0i64;
    v7 = qInOut;
    do
    {
      v8 = bonePairMap[v6];
      if ( (int)v8 >= 0 && (int)v8 < v3 )
      {
        v9.m_quad = (__m128)v7->m_translation;
        v10.m_vec.m_quad = (__m128)v7->m_rotation;
        v11.m_quad = (__m128)v7->m_scale;
        v12 = v8;
        *v7 = qInOut[v8];
        qInOut[v12].m_translation = (hkVector4f)v9.m_quad;
        qInOut[v12].m_rotation = (hkQuaternionf)v10.m_vec.m_quad;
        qInOut[v12].m_scale = (hkVector4f)v11.m_quad;
      }
      ++v6;
      ++v3;
      ++v7;
    }
    while ( v6 < v4 );
  }
}

// File Line: 153
// RVA: 0xB464B0
void __fastcall hkaMirroredSkeleton::mirrorRegularBone(hkaMirroredSkeleton *this, hkQsTransformf *qInOut, int bone)
{
  hkaMirroredSkeleton::mirrorPairedBone(this, qInOut, bone, 0);
}

// File Line: 157
// RVA: 0xB464C0
void __fastcall hkaMirroredSkeleton::mirrorAdditiveBone(hkaMirroredSkeleton *this, hkQsTransformf *qInOut, int bone)
{
  hkaMirroredSkeleton::mirrorPairedBone(this, qInOut, bone, 1);
}

// File Line: 162
// RVA: 0xB464D0
void __fastcall hkaMirroredSkeleton::mirrorExtractedMotion(hkaMirroredSkeleton *this, hkQsTransformf *qInOut)
{
  hkaMirroredSkeleton::mirrorPairedBone(this, qInOut, 0, 1);
}

// File Line: 167
// RVA: 0xB46BC0
void __fastcall hkaMirroredSkeleton::setPartitionPairMap(
        hkaMirroredSkeleton *this,
        const __int16 *partitionPairMap,
        int numPartitionPairMap)
{
  hkString::memCpy(this->m_partitionPairMap, partitionPairMap, 2 * numPartitionPairMap);
}

// File Line: 174
// RVA: 0xB46BE0
__int64 __fastcall hkaMirroredSkeleton::getPartitionPair(hkaMirroredSkeleton *this, __int16 pi)
{
  if ( pi >= 0 )
    return (unsigned __int16)this->m_partitionPairMap[pi];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 184
// RVA: 0xB46C50
__int64 __fastcall hkaMirroredSkeleton::getBonePair(hkaMirroredSkeleton *this, __int16 bi)
{
  if ( bi >= 0 )
    return (unsigned __int16)this->m_bonePairMap[bi];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 197
// RVA: 0xB47610
__int16 *__fastcall hkaMirroredSkeleton::getBonePairMap(hkaMirroredSkeleton *this)
{
  return this->m_bonePairMap;
}

// File Line: 202
// RVA: 0xB47620
hkQuaternionf *__fastcall hkaMirroredSkeleton::getInvariants(hkaMirroredSkeleton *this)
{
  return this->m_boneInvariants;
}

// File Line: 207
// RVA: 0xB46D20
const char *__fastcall hkaMirroredSkeleton::getAnnotationNamePair(hkaMirroredSkeleton *this, const char *text)
{
  const char *v2; // rbx
  hkResult result; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int64 out; // [rsp+40h] [rbp+18h] BYREF

  v2 = text;
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_annotationNameMap,
         &result,
         (unsigned __int64)text,
         &out)->m_enum == HK_SUCCESS )
    return (const char *)out;
  return v2;
}

// File Line: 223
// RVA: 0xB46C00
void __fastcall hkaMirroredSkeleton::setBonePair(hkaMirroredSkeleton *this, __int16 bi, __int16 bj)
{
  this->m_bonePairMap[bi] = bj;
  this->m_bonePairMap[bj] = bi;
}

// File Line: 230
// RVA: 0xB46C70
void __fastcall hkaMirroredSkeleton::setAnnotationPair(
        hkaMirroredSkeleton *this,
        hkaAnnotationTrack::Annotation *ai,
        hkaAnnotationTrack::Annotation *aj)
{
  hkStringMap<char const *,hkContainerHeapAllocator> *p_m_annotationNameMap; // rdi

  p_m_annotationNameMap = &this->m_annotationNameMap;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_annotationNameMap.m_map,
    (unsigned __int64)ai->m_text.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
    (unsigned __int64)aj->m_text.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &p_m_annotationNameMap->m_map,
    (unsigned __int64)aj->m_text.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
    (unsigned __int64)ai->m_text.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 236
// RVA: 0xB46CD0
void __fastcall hkaMirroredSkeleton::setAnnotationNamePair(
        hkaMirroredSkeleton *this,
        const char *namei,
        const char *namej)
{
  hkStringMap<char const *,hkContainerHeapAllocator> *p_m_annotationNameMap; // rbx

  p_m_annotationNameMap = &this->m_annotationNameMap;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_annotationNameMap.m_map,
    (unsigned __int64)namei,
    (unsigned __int64)namej);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &p_m_annotationNameMap->m_map,
    (unsigned __int64)namej,
    (unsigned __int64)namei);
}

// File Line: 243
// RVA: 0xB46D60
void __fastcall hkaMirroredSkeleton::clearAllAnnotationPairs(hkaMirroredSkeleton *this)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_annotationNameMap.m_map);
}

// File Line: 249
// RVA: 0xB46C30
void __fastcall hkaMirroredSkeleton::setBonePairMap(
        hkaMirroredSkeleton *this,
        const __int16 *bonePairMap,
        int numBonePairMap)
{
  hkString::memCpy(this->m_bonePairMap, bonePairMap, 2 * numBonePairMap);
}

// File Line: 256
// RVA: 0xB46D70
void __fastcall hkaMirroredSkeleton::computeBonePairingFromNames(
        hkaMirroredSkeleton *this,
        hkArrayBase<hkStringPtr> *ltag,
        hkArrayBase<hkStringPtr> *rtag)
{
  hkaMirroredSkeleton::computeBonePairingFromNames(ltag, rtag, this->m_skeleton, this->m_bonePairMap);
}

// File Line: 265
// RVA: 0xB46D90
void __fastcall hkaMirroredSkeleton::computeBonePairingFromNames(
        hkArrayBase<hkStringPtr> *ltag,
        hkArrayBase<hkStringPtr> *rtag,
        hkaSkeleton *skeleton,
        __int16 *bonePairMap)
{
  int m_size; // esi
  hkArrayBase<hkStringPtr> *v6; // rbx
  __int16 v8; // di
  __int16 *v9; // rcx
  __int16 v10; // r12
  int v11; // r14d
  __int64 v12; // r15
  __int64 v13; // rcx
  hkStringPtr *m_data; // rax
  __int16 v15; // bx
  __int64 v16; // rax
  hkStringBuf v17; // [rsp+30h] [rbp-C8h] BYREF
  __int16 to; // [rsp+110h] [rbp+18h] BYREF
  __int16 *v20; // [rsp+118h] [rbp+20h]

  v20 = bonePairMap;
  m_size = skeleton->m_bones.m_size;
  v6 = rtag;
  v8 = 0;
  if ( m_size > 0 )
  {
    v9 = bonePairMap;
    do
    {
      v10 = v8;
      v11 = 0;
      if ( ltag->m_size > 0 )
      {
        v12 = 0i64;
        v13 = v8;
        while ( 1 )
        {
          hkStringBuf::hkStringBuf(
            &v17,
            (const char *)((unsigned __int64)skeleton->m_bones.m_data[v13].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
          m_data = ltag->m_data;
          to = 255;
          hkStringBuf::replace(
            &v17,
            (const char *)((unsigned __int64)m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)&to,
            REPLACE_ALL);
          hkStringBuf::replace(
            &v17,
            (const char *)((unsigned __int64)v6->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)((unsigned __int64)ltag->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            REPLACE_ALL);
          hkStringBuf::replace(
            &v17,
            (const char *)&to,
            (const char *)((unsigned __int64)v6->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            REPLACE_ALL);
          v15 = 0;
          while ( v15 == v8
               || hkStringBuf::compareTo(
                    &v17,
                    (const char *)((unsigned __int64)skeleton->m_bones.m_data[v15].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
          {
            if ( ++v15 >= m_size )
              goto LABEL_11;
          }
          v10 = v15;
LABEL_11:
          v17.m_string.m_size = 0;
          if ( v10 != v8 )
            break;
          if ( v17.m_string.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              v17.m_string.m_data,
              v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
          v13 = v8;
          v6 = rtag;
          ++v11;
          ++v12;
          if ( v11 >= ltag->m_size )
            goto LABEL_18;
        }
        if ( v17.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v17.m_string.m_data,
            v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
LABEL_18:
        v6 = rtag;
        v9 = v20;
      }
      v16 = v8++;
      v9[v16] = v10;
    }
    while ( v8 < m_size );
  }
}

// File Line: 313
// RVA: 0xB46F90
void __fastcall hkaMirroredSkeleton::computePartitionPairingFromNames(
        hkaMirroredSkeleton *this,
        hkArrayBase<hkStringPtr> *ltag,
        hkArrayBase<hkStringPtr> *rtag)
{
  hkaMirroredSkeleton::computePartitionPairingFromNames(ltag, rtag, this->m_skeleton, this->m_partitionPairMap);
}

// File Line: 322
// RVA: 0xB46FB0
void __fastcall hkaMirroredSkeleton::computePartitionPairingFromNames(
        hkArrayBase<hkStringPtr> *ltag,
        hkArrayBase<hkStringPtr> *rtag,
        hkaSkeleton *skeleton,
        __int16 *partitionPairMap)
{
  int m_size; // esi
  hkArrayBase<hkStringPtr> *v6; // rbx
  __int16 v8; // di
  __int16 *v9; // rcx
  __int16 v10; // r12
  int v11; // r14d
  __int64 v12; // r15
  __int64 v13; // rcx
  hkStringPtr *m_data; // rax
  char v15; // bl
  __int64 v16; // rax
  hkStringBuf v17; // [rsp+30h] [rbp-C8h] BYREF
  __int16 to; // [rsp+110h] [rbp+18h] BYREF
  __int16 *v20; // [rsp+118h] [rbp+20h]

  v20 = partitionPairMap;
  m_size = skeleton->m_partitions.m_size;
  v6 = rtag;
  v8 = 0;
  if ( m_size > 0 )
  {
    v9 = partitionPairMap;
    do
    {
      v10 = v8;
      v11 = 0;
      if ( ltag->m_size > 0 )
      {
        v12 = 0i64;
        v13 = v8;
        while ( 1 )
        {
          hkStringBuf::hkStringBuf(
            &v17,
            (const char *)((unsigned __int64)skeleton->m_partitions.m_data[v13].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
          m_data = ltag->m_data;
          to = 255;
          hkStringBuf::replace(
            &v17,
            (const char *)((unsigned __int64)m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)&to,
            REPLACE_ALL);
          hkStringBuf::replace(
            &v17,
            (const char *)((unsigned __int64)v6->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)((unsigned __int64)ltag->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            REPLACE_ALL);
          hkStringBuf::replace(
            &v17,
            (const char *)&to,
            (const char *)((unsigned __int64)v6->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            REPLACE_ALL);
          v15 = 0;
          while ( v15 == v8
               || hkStringBuf::compareTo(
                    &v17,
                    (const char *)((unsigned __int64)skeleton->m_partitions.m_data[v15].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
          {
            if ( ++v15 >= m_size )
              goto LABEL_11;
          }
          v10 = v15;
LABEL_11:
          v17.m_string.m_size = 0;
          if ( v10 != v8 )
            break;
          if ( v17.m_string.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              v17.m_string.m_data,
              v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
          v13 = v8;
          v6 = rtag;
          ++v11;
          ++v12;
          if ( v11 >= ltag->m_size )
            goto LABEL_18;
        }
        if ( v17.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v17.m_string.m_data,
            v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
LABEL_18:
        v6 = rtag;
        v9 = v20;
      }
      v16 = v8++;
      v9[v16] = v10;
    }
    while ( v8 < m_size );
  }
}

// File Line: 370
// RVA: 0xB466C0
void __fastcall hkaMirroredSkeleton::setAllBoneInvariantsFromReferencePose(
        hkaMirroredSkeleton *this,
        hkQuaternionf *worldAxis,
        float tolerance)
{
  hkaSkeleton *m_skeleton; // rax
  int m_size; // edi
  int v7; // ebx
  int v8; // r9d
  int v9; // r9d
  int v10; // r9d
  int v11; // ebx
  int v12; // r9d
  int v13; // r9d
  float *v14; // rdi
  __int64 v15; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *SyncedPoseModelSpace; // rax
  hkaPose v17; // [rsp+18h] [rbp-19h] BYREF
  hkResult result; // [rsp+98h] [rbp+67h] BYREF

  m_skeleton = this->m_skeleton;
  v17.m_localPose.m_capacityAndFlags = 0x80000000;
  v17.m_modelPose.m_capacityAndFlags = 0x80000000;
  v17.m_skeleton = m_skeleton;
  v17.m_boneFlags.m_capacityAndFlags = 0x80000000;
  v17.m_floatSlotValues.m_capacityAndFlags = 0x80000000;
  v17.m_localPose.m_data = 0i64;
  v17.m_localPose.m_size = 0;
  v17.m_modelPose.m_data = 0i64;
  v17.m_modelPose.m_size = 0;
  v17.m_boneFlags.m_data = 0i64;
  v17.m_boneFlags.m_size = 0;
  *(_WORD *)&v17.m_modelInSync.m_bool = 0;
  v17.m_floatSlotValues.m_data = 0i64;
  v17.m_floatSlotValues.m_size = 0;
  m_size = m_skeleton->m_bones.m_size;
  v7 = (m_size + 3) & 0xFFFFFFFC;
  if ( m_size + 3 >= 0 && v7 != 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v17.m_modelPose, v7, 48);
  if ( (v17.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) < v7 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v17.m_localPose, v7, 48);
  if ( (v17.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) < v7 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v17.m_boneFlags, v7, 4);
  if ( (v17.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF) < m_size )
  {
    v8 = m_size;
    if ( m_size < 2 * (v17.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF) )
      v8 = 2 * (v17.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v17.m_modelPose, v8, 48);
  }
  v17.m_modelPose.m_size = m_size;
  if ( (v17.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) < m_size )
  {
    v9 = m_size;
    if ( m_size < 2 * (v17.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) )
      v9 = 2 * (v17.m_localPose.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v17.m_localPose, v9, 48);
  }
  v17.m_localPose.m_size = m_size;
  if ( (v17.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) < m_size )
  {
    v10 = m_size;
    if ( m_size < 2 * (v17.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) )
      v10 = 2 * (v17.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v17.m_boneFlags, v10, 4);
  }
  v17.m_boneFlags.m_size = m_size;
  v11 = v17.m_skeleton->m_floatSlots.m_size;
  v12 = (v11 + 3) & 0xFFFFFFFC;
  if ( (v17.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) < v12 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v17.m_floatSlotValues, v12, 4);
  if ( (v17.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) < v11 )
  {
    v13 = v11;
    if ( v11 < 2 * (v17.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) )
      v13 = 2 * (v17.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v17.m_floatSlotValues, v13, 4);
  }
  v14 = &v17.m_floatSlotValues.m_data[v17.m_floatSlotValues.m_size];
  v15 = v11 - v17.m_floatSlotValues.m_size;
  if ( v11 - v17.m_floatSlotValues.m_size > 0 )
  {
    while ( v15 )
    {
      *v14++ = 0.0;
      --v15;
    }
  }
  v17.m_floatSlotValues.m_size = v11;
  hkaPose::setToReferencePose(&v17);
  SyncedPoseModelSpace = hkaPose::getSyncedPoseModelSpace(&v17);
  hkaMirroredSkeleton::setAllBoneInvariantsFromSymmetricPose(this, worldAxis, tolerance, SyncedPoseModelSpace->m_data);
  hkaPose::~hkaPose(&v17);
}

// File Line: 377
// RVA: 0xB46930
void __fastcall hkaMirroredSkeleton::setAllBoneInvariantsFromSymmetricPose(
        hkaMirroredSkeleton *this,
        hkQuaternionf *worldAxis,
        float tolerance,
        hkaPose *pose)
{
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *SyncedPoseModelSpace; // rax

  SyncedPoseModelSpace = hkaPose::getSyncedPoseModelSpace(pose);
  hkaMirroredSkeleton::setAllBoneInvariantsFromSymmetricPose(this, worldAxis, tolerance, SyncedPoseModelSpace->m_data);
}

// File Line: 382
// RVA: 0xB46980
void __fastcall hkaMirroredSkeleton::setAllBoneInvariantsFromSymmetricPose(
        hkaMirroredSkeleton *this,
        hkQuaternionf *worldAxis,
        float tolerance,
        hkQsTransformf *poseModelSpace)
{
  int i; // esi
  hkQuaternionf v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm6
  __m128 v13; // xmm0
  __m128 v14; // xmm6
  __m128 v15; // xmm3
  hkQuaternionf v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm5
  __m128 v24; // xmm5
  __m128 v25; // xmm0
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  hkQuaternionf qInOut; // [rsp+20h] [rbp-58h] BYREF

  hkaMirroredSkeleton::setBoneInvariant(this, -1, worldAxis);
  for ( i = 0; i < hkaMirroredSkeleton::numBones(this); ++i )
  {
    v9.m_vec.m_quad = (__m128)poseModelSpace[i].m_rotation;
    v10 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9.m_vec.m_quad, v9.m_vec.m_quad, 201), worldAxis->m_vec.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(worldAxis->m_vec.m_quad, worldAxis->m_vec.m_quad, 201), v9.m_vec.m_quad));
    v11 = _mm_mul_ps(worldAxis->m_vec.m_quad, v9.m_vec.m_quad);
    v12 = _mm_sub_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9.m_vec.m_quad, v9.m_vec.m_quad, 255), worldAxis->m_vec.m_quad),
              _mm_shuffle_ps(v10, v10, 201)),
            _mm_mul_ps(_mm_shuffle_ps(worldAxis->m_vec.m_quad, worldAxis->m_vec.m_quad, 255), v9.m_vec.m_quad));
    v13 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 78), v11);
    v14 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, _mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13)), 196);
    v15 = _mm_shuffle_ps(v14, v14, 255);
    v16.m_vec.m_quad = (__m128)poseModelSpace[hkaMirroredSkeleton::getBonePair(this, i)].m_rotation;
    v17 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v16.m_vec.m_quad);
    v18 = _mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 255);
    v19 = _mm_mul_ps(v14, v18);
    v20 = _mm_mul_ps(_mm_shuffle_ps(v16.m_vec.m_quad, v16.m_vec.m_quad, 201), v14);
    v21 = _mm_mul_ps(v14, v16.m_vec.m_quad);
    v22 = _mm_sub_ps(v20, v17);
    v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 201), _mm_mul_ps(v16.m_vec.m_quad, v15)), v19);
    v24 = _mm_shuffle_ps(
            v23,
            _mm_unpackhi_ps(
              v23,
              _mm_sub_ps(
                _mm_mul_ps(v18, v15),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                  _mm_shuffle_ps(v21, v21, 170)))),
            196);
    v25 = _mm_mul_ps(v24, v24);
    v26 = _mm_add_ps(_mm_shuffle_ps(v25, v25, 78), v25);
    v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 177), v26);
    v28 = _mm_rsqrt_ps(v27);
    qInOut.m_vec.m_quad = _mm_mul_ps(
                            v24,
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v28, v27), v28)),
                              _mm_mul_ps(*(__m128 *)_xmm, v28)));
    hkaMirroredSkeleton::canonicalize(this, &qInOut, tolerance);
    hkaMirroredSkeleton::setBoneInvariant(this, i, &qInOut);
  }
}

// File Line: 405
// RVA: 0xB47650
void __fastcall hkaMirroredSkeleton::canonicalize(hkaMirroredSkeleton *this, hkQuaternionf *qInOut, float tolerance)
{
  float v3; // xmm2_4
  hkQuaternionf *v4; // rax
  __m128 v5; // xmm0
  __m128 v6; // xmm1

  LODWORD(v3) = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0).m128_u32[0];
  if ( (_S1_40 & 1) == 0 )
  {
    _S1_40 |= 1u;
    cardinals[4] = (hkQuaternionf)_xmm;
    cardinals[5] = (hkQuaternionf)_xmm;
    cardinals[6] = (hkQuaternionf)_xmm;
    cardinals[7] = (hkQuaternionf)_xmm;
    cardinals[8] = (hkQuaternionf)_xmm;
    cardinals[9] = (hkQuaternionf)_xmm_bf3504f33f3504f30000000000000000;
    cardinals[10] = (hkQuaternionf)_xmm;
    cardinals[11] = (hkQuaternionf)_xmm;
    cardinals[12] = (hkQuaternionf)_xmm;
    cardinals[13] = (hkQuaternionf)_xmm_bf3504f3000000003f3504f300000000;
    cardinals[14] = (hkQuaternionf)_xmm;
    cardinals[15] = (hkQuaternionf)_xmm_bf3504f300000000000000003f3504f3;
    cardinals[16] = *(hkQuaternionf *)_xmm;
    cardinals[17] = (hkQuaternionf)_xmm_bf0000003f0000003f0000003f000000;
    cardinals[18] = (hkQuaternionf)_xmm;
    cardinals[19] = (hkQuaternionf)_xmm_bf000000bf0000003f0000003f000000;
    cardinals[20] = (hkQuaternionf)_xmm;
    cardinals[21] = (hkQuaternionf)_xmm_bf0000003f000000bf0000003f000000;
    cardinals[22] = (hkQuaternionf)_xmm;
    cardinals[23] = (hkQuaternionf)_xmm_bf000000bf000000bf0000003f000000;
  }
  v4 = cardinals;
  while ( 1 )
  {
    v5 = _mm_mul_ps(v4->m_vec.m_quad, qInOut->m_vec.m_quad);
    v6 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 78), v5);
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(_mm_shuffle_ps(v6, v6, 177).m128_f32[0] + v6.m128_f32[0])) >> 1) >= (float)(1.0 - v3) )
      break;
    if ( (__int64)++v4 >= (__int64)&hkaMirroredSkeleton `RTTI Type Descriptor )
      return;
  }
  *qInOut = (hkQuaternionf)v4->m_vec.m_quad;
}

// File Line: 482
// RVA: 0xB46BA0
void __fastcall hkaMirroredSkeleton::setBoneInvariant(hkaMirroredSkeleton *this, int bone, hkQuaternionf *axis)
{
  this->m_boneInvariants[bone + 1] = (hkQuaternionf)axis->m_vec.m_quad;
}

// File Line: 490
// RVA: 0xB46B80
hkQuaternionf *__fastcall hkaMirroredSkeleton::getBoneInvariant(hkaMirroredSkeleton *this, int bone)
{
  return &this->m_boneInvariants[bone + 1];
}

// File Line: 497
// RVA: 0xB47630
__int64 __fastcall hkaMirroredSkeleton::getBoneParent(hkaMirroredSkeleton *this, int bone)
{
  return (unsigned int)this->m_parentIndices[bone];
}

// File Line: 504
// RVA: 0xB471C0
__int64 __fastcall hkaMirroredSkeleton::getNumDataChunks()
{
  return 5i64;
}

// File Line: 509
// RVA: 0xB471D0
void __fastcall hkaMirroredSkeleton::getDataChunks(hkaMirroredSkeleton *this, hkaAnimation::DataChunk *dataOut)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int m_numPartitions; // ecx

  dataOut->m_data = (const char *)this;
  dataOut->m_size = 104;
  v4 = hkaMirroredSkeleton::numBones(this);
  dataOut[1].m_data = (const char *)this->m_parentIndices;
  dataOut[1].m_size = 2 * v4;
  v5 = hkaMirroredSkeleton::numBones(this);
  dataOut[2].m_data = (const char *)this->m_boneInvariants;
  dataOut[2].m_size = 16 * (v5 + 1);
  v6 = hkaMirroredSkeleton::numBones(this);
  dataOut[3].m_data = (const char *)this->m_bonePairMap;
  dataOut[3].m_size = 2 * v6;
  m_numPartitions = this->m_numPartitions;
  dataOut[4].m_data = (const char *)this->m_partitions;
  dataOut[4].m_size = 16 * m_numPartitions;
}

// File Line: 523
// RVA: 0xB47250
hkaMirroredSkeleton *__fastcall hkaMirroredSkeleton::convertDataChunks(hkaAnimation::DataChunk *dataInOut)
{
  return (hkaMirroredSkeleton *)dataInOut->m_data;
}

// File Line: 543
// RVA: 0xB478A0
__int64 __fastcall hkaMirroredSkeleton::numBones(hkaMirroredSkeleton *this)
{
  return (unsigned int)this->m_numBones;
}

