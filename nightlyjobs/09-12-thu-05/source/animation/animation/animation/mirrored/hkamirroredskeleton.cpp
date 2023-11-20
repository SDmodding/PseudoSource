// File Line: 20
// RVA: 0xB462A0
void __fastcall hkaMirroredSkeleton::hkaMirroredSkeleton(hkaMirroredSkeleton *this, hkaSkeleton *skeleton)
{
  hkaSkeleton *v2; // rbp
  hkaMirroredSkeleton *v3; // rbx
  int v4; // ecx
  int v5; // edi
  hkMemoryAllocator **v6; // rax
  __int16 *v7; // rax
  __int16 v8; // si
  char v9; // dl
  __int16 v10; // r8
  __int64 v11; // rcx
  int v12; // edi
  hkMemoryAllocator **v13; // rax
  __int16 *v14; // rax
  int v15; // edi
  hkMemoryAllocator **v16; // rax
  signed __int64 v17; // rcx

  this->m_skeleton = skeleton;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaMirroredSkeleton::`vftable';
  v2 = skeleton;
  this->m_parentIndices = skeleton->m_parentIndices.m_data;
  v3 = this;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_annotationNameMap.m_map,
    0);
  v4 = SLOBYTE(v2->m_partitions.m_size);
  v3->m_numPartitions = v4;
  v5 = v4;
  v3->m_partitions = v2->m_partitions.m_data;
  v6 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (__int16 *)hkMemoryRouter::alignedAlloc(v6[11], 2 * v5, 16);
  v8 = 0;
  v9 = 0;
  v3->m_partitionPairMap = v7;
  if ( v3->m_numPartitions > 0 )
  {
    v10 = 0;
    do
    {
      v11 = v9++;
      v3->m_partitionPairMap[v11] = v10;
      v10 = v9;
    }
    while ( v9 < v3->m_numPartitions );
  }
  v12 = v2->m_bones.m_size;
  v3->m_numBones = v12;
  v13 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (__int16 *)hkMemoryRouter::alignedAlloc(v13[11], 2 * v12, 16);
  v15 = v3->m_numBones;
  v3->m_bonePairMap = v14;
  v16 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3->m_boneInvariants = (hkQuaternionf *)hkMemoryRouter::alignedAlloc(v16[11], 16 * (v15 + 1), 16);
  if ( v3->m_numBones > 0 )
  {
    do
    {
      v3->m_bonePairMap[v8] = v8;
      v17 = v8++;
      v3->m_boneInvariants[v17] = (hkQuaternionf)qi.m_vec.m_quad;
    }
    while ( v8 < v3->m_numBones );
  }
  v3->m_boneInvariants[v3->m_numBones] = (hkQuaternionf)qi.m_vec.m_quad;
}

// File Line: 51
// RVA: 0xB46400
void __fastcall hkaMirroredSkeleton::~hkaMirroredSkeleton(hkaMirroredSkeleton *this)
{
  __int16 *v1; // rbx
  hkaMirroredSkeleton *v2; // rdi
  hkMemoryAllocator **v3; // rax
  __int16 *v4; // rbx
  hkMemoryAllocator **v5; // rax
  hkQuaternionf *v6; // rbx
  hkMemoryAllocator **v7; // rax

  v1 = this->m_partitionPairMap;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaMirroredSkeleton::`vftable';
  v3 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(v3[11], v1);
  v4 = v2->m_bonePairMap;
  v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(v5[11], v4);
  v6 = v2->m_boneInvariants;
  v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(v7[11], v6);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v2->m_annotationNameMap.m_map);
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
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
void __fastcall hkaMirroredSkeleton::mirrorPairedBone(hkaMirroredSkeleton *this, hkQsTransformf *qInOut, int bone, bool isAdditive)
{
  hkQsTransformf *v4; // r14
  bool v5; // bl
  int v6; // esi
  hkaMirroredSkeleton *v7; // rdi
  int v8; // ebp
  int v9; // edx
  hkQuaternionf *v10; // rax
  __m128 v11; // xmm2
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
  __m128 v24; // xmm6
  __m128 v25; // xmm2
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm3

  v4 = qInOut;
  v5 = isAdditive;
  v6 = bone;
  v7 = this;
  v8 = hkaMirroredSkeleton::getBoneParent(this, bone);
  v9 = v8;
  if ( !v5 )
    v9 = v6;
  v10 = hkaMirroredSkeleton::getBoneInvariant(v7, v9);
  v11 = v4->m_rotation.m_vec.m_quad;
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v10->m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v10->m_vec.m_quad, v10->m_vec.m_quad, 201), v11));
  v13 = _mm_mul_ps(v10->m_vec.m_quad, v11);
  v14 = _mm_add_ps(
          _mm_sub_ps(
            _mm_shuffle_ps(v12, v12, 201),
            _mm_mul_ps(_mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v4->m_rotation.m_vec.m_quad, 255), v10->m_vec.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v10->m_vec.m_quad, v10->m_vec.m_quad, 255), v11));
  v15 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v16 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15)), 196);
  v17 = hkaMirroredSkeleton::getBoneInvariant(v7, v8);
  v18 = _mm_shuffle_ps(v16, v16, 255);
  v19 = _mm_shuffle_ps(v17->m_vec.m_quad, v17->m_vec.m_quad, 255);
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v17->m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v17->m_vec.m_quad, v17->m_vec.m_quad, 201), v16));
  v21 = v16;
  v22 = _mm_mul_ps(v16, v17->m_vec.m_quad);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 201), _mm_mul_ps(v21, v19)), _mm_mul_ps(v17->m_vec.m_quad, v18));
  v4->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                  v23,
                                  _mm_unpackhi_ps(
                                    v23,
                                    _mm_sub_ps(
                                      _mm_mul_ps(v18, v19),
                                      _mm_add_ps(
                                        _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                                        _mm_shuffle_ps(v22, v22, 170)))),
                                  196);
  v24 = v4->m_translation.m_quad;
  v25 = hkaMirroredSkeleton::getBoneInvariant(v7, v8)->m_vec.m_quad;
  v26 = _mm_shuffle_ps(v25, v25, 255);
  v27 = _mm_mul_ps(v25, v24);
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24));
  v29 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                _mm_shuffle_ps(v27, v27, 170)),
              v25),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v24)),
          _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v26));
  v4->m_translation.m_quad = _mm_xor_ps(
                               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                               _mm_add_ps(v29, v29));
}

// File Line: 92
// RVA: 0xB47260
void __fastcall hkaMirroredSkeleton::mirrorBonesNormal(hkQsTransformf *qInOut, const __int16 *parentIndices, hkQuaternionf *invariants, const __int16 *bonePairMap, int numBones)
{
  const __int16 *v5; // rdi
  __m128 *v6; // rdx
  hkQuaternionf *v7; // rbx
  __int64 v8; // rsi
  __m128 v9; // xmm7
  int v10; // eax
  __m128 v11; // xmm6
  __m128 v12; // xmm3
  __m128 v13; // xmm2
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

  v5 = parentIndices;
  if ( numBones > 0 )
  {
    v6 = &qInOut->m_rotation.m_vec.m_quad;
    v7 = invariants + 1;
    v8 = (unsigned int)numBones;
    v9 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v10 = *v5 + 1;
      v11 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 201), v7->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v7->m_vec.m_quad, v7->m_vec.m_quad, 201), *v6));
      v12 = _mm_mul_ps(*v6, v7->m_vec.m_quad);
      v13 = invariants[v10].m_vec.m_quad;
      v14 = _mm_add_ps(
              _mm_sub_ps(_mm_shuffle_ps(v11, v11, 201), _mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 255), v7->m_vec.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v7->m_vec.m_quad, v7->m_vec.m_quad, 255), *v6));
      v15 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
      v16 = _mm_shuffle_ps(invariants[v10].m_vec.m_quad, invariants[v10].m_vec.m_quad, 255);
      v17 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15)), 196);
      v18 = _mm_shuffle_ps(v17, v17, 255);
      v19 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v13),
              _mm_mul_ps(_mm_shuffle_ps(invariants[v10].m_vec.m_quad, v13, 201), v17));
      v20 = _mm_mul_ps(v17, v16);
      v21 = _mm_mul_ps(v17, v13);
      v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 201), v20), _mm_mul_ps(v13, v18));
      *v6 = _mm_shuffle_ps(
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
      v24 = v6[-1];
      v25 = _mm_mul_ps(invariants[v10].m_vec.m_quad, v24);
      v26 = _mm_shuffle_ps(invariants[v10].m_vec.m_quad, v23, 255);
      v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v24));
      v6 += 3;
      ++v7;
      ++v5;
      v28 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                    _mm_shuffle_ps(v25, v25, 170)),
                  v23),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v24)),
              _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v26));
      v6[-4] = _mm_xor_ps(_mm_add_ps(v28, v28), v9);
      --v8;
    }
    while ( v8 );
  }
  hkaMirroredSkeleton::inplaceSwap(qInOut, bonePairMap, numBones);
}

// File Line: 116
// RVA: 0xB47440
void __fastcall hkaMirroredSkeleton::mirrorBonesAdditive(hkQsTransformf *qInOut, const __int16 *parentIndices, hkQuaternionf *invariants, const __int16 *bonePairMap, int numBones)
{
  const __int16 *v5; // r11
  __m128 *v6; // rdx
  __int64 v7; // rbx
  __m128 v8; // xmm7
  int v9; // eax
  __m128 v10; // xmm1
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm6
  __m128 v18; // xmm3
  __m128 v19; // xmm4
  __m128 v20; // xmm0
  __m128 v21; // xmm6
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm3

  v5 = parentIndices;
  if ( numBones > 0 )
  {
    v6 = &qInOut->m_rotation.m_vec.m_quad;
    v7 = (unsigned int)numBones;
    v8 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
    do
    {
      v9 = *v5 + 1;
      v10 = invariants[v9].m_vec.m_quad;
      v11 = _mm_shuffle_ps(invariants[v9].m_vec.m_quad, invariants[v9].m_vec.m_quad, 255);
      v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 201), v10), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), *v6));
      v13 = _mm_mul_ps(*v6, v10);
      v14 = _mm_add_ps(
              _mm_sub_ps(_mm_shuffle_ps(v12, v12, 201), _mm_mul_ps(_mm_shuffle_ps(*v6, *v6, 255), v10)),
              _mm_mul_ps(v11, *v6));
      v15 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
      v16 = invariants[v9].m_vec.m_quad;
      v17 = _mm_shuffle_ps(v14, _mm_unpackhi_ps(v14, _mm_add_ps(_mm_shuffle_ps(v15, v15, 177), v15)), 196);
      v18 = _mm_shuffle_ps(v17, v17, 255);
      v19 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v16),
              _mm_mul_ps(_mm_shuffle_ps(invariants[v9].m_vec.m_quad, v16, 201), v17));
      v20 = _mm_mul_ps(v17, v11);
      v21 = _mm_mul_ps(v17, v16);
      v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 201), v20), _mm_mul_ps(v16, v18));
      *v6 = _mm_shuffle_ps(
              v22,
              _mm_unpackhi_ps(
                v22,
                _mm_sub_ps(
                  _mm_mul_ps(v18, v11),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                    _mm_shuffle_ps(v21, v21, 170)))),
              196);
      v23 = invariants[v9].m_vec.m_quad;
      v24 = v6[-1];
      v25 = _mm_mul_ps(invariants[v9].m_vec.m_quad, v24);
      v26 = _mm_shuffle_ps(invariants[v9].m_vec.m_quad, v23, 255);
      v27 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v24));
      v6 += 3;
      ++v5;
      v28 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                    _mm_shuffle_ps(v25, v25, 170)),
                  v23),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v26, v26), (__m128)xmmword_141A711B0), v24)),
              _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v26));
      v6[-4] = _mm_xor_ps(_mm_add_ps(v28, v28), v8);
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
  signed int v3; // er9
  __int64 v4; // r11
  const __int16 *v5; // rbx
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
    v5 = bonePairMap;
    v6 = 0i64;
    v7 = qInOut;
    do
    {
      v8 = v5[v6];
      if ( (signed int)v8 >= 0 && (signed int)v8 < v3 )
      {
        v9.m_quad = (__m128)v7->m_translation;
        v10.m_vec.m_quad = (__m128)v7->m_rotation;
        v11.m_quad = (__m128)v7->m_scale;
        v12 = v8;
        v7->m_translation = qInOut[v8].m_translation;
        v7->m_rotation = qInOut[v8].m_rotation;
        v7->m_scale = qInOut[v8].m_scale;
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
void __fastcall hkaMirroredSkeleton::setPartitionPairMap(hkaMirroredSkeleton *this, const __int16 *partitionPairMap, int numPartitionPairMap)
{
  hkString::memCpy(this->m_partitionPairMap, partitionPairMap, 2 * numPartitionPairMap);
}

// File Line: 174
// RVA: 0xB46BE0
signed __int64 __fastcall hkaMirroredSkeleton::getPartitionPair(hkaMirroredSkeleton *this, __int16 pi)
{
  signed __int64 result; // rax

  if ( pi >= 0 )
    result = (unsigned __int16)this->m_partitionPairMap[pi];
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 184
// RVA: 0xB46C50
signed __int64 __fastcall hkaMirroredSkeleton::getBonePair(hkaMirroredSkeleton *this, __int16 bi)
{
  signed __int64 result; // rax

  if ( bi >= 0 )
    result = (unsigned __int16)this->m_bonePairMap[bi];
  else
    result = 0xFFFFFFFFi64;
  return result;
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
  unsigned __int64 v2; // rbx
  hkResult result; // [rsp+30h] [rbp+8h]
  unsigned __int64 out; // [rsp+40h] [rbp+18h]

  v2 = (unsigned __int64)text;
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_annotationNameMap,
         &result,
         (unsigned __int64)text,
         &out)->m_enum == HK_SUCCESS )
    v2 = out;
  return (const char *)v2;
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
void __fastcall hkaMirroredSkeleton::setAnnotationPair(hkaMirroredSkeleton *this, hkaAnnotationTrack::Annotation *ai, hkaAnnotationTrack::Annotation *aj)
{
  hkaAnnotationTrack::Annotation *v3; // rsi
  hkaAnnotationTrack::Annotation *v4; // rbx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v5; // rdi

  v3 = aj;
  v4 = ai;
  v5 = &this->m_annotationNameMap.m_map;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_annotationNameMap.m_map,
    (_QWORD)ai->m_text.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
    (_QWORD)aj->m_text.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    v5,
    (_QWORD)v3->m_text.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64,
    (_QWORD)v4->m_text.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 236
// RVA: 0xB46CD0
void __fastcall hkaMirroredSkeleton::setAnnotationNamePair(hkaMirroredSkeleton *this, const char *namei, const char *namej)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v3; // rbx
  const char *v4; // rsi
  const char *v5; // rdi

  v3 = &this->m_annotationNameMap.m_map;
  v4 = namej;
  v5 = namei;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_annotationNameMap.m_map,
    (unsigned __int64)namei,
    (unsigned __int64)namej);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    v3,
    (unsigned __int64)v4,
    (unsigned __int64)v5);
}

// File Line: 243
// RVA: 0xB46D60
void __fastcall hkaMirroredSkeleton::clearAllAnnotationPairs(hkaMirroredSkeleton *this)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_annotationNameMap.m_map);
}

// File Line: 249
// RVA: 0xB46C30
void __fastcall hkaMirroredSkeleton::setBonePairMap(hkaMirroredSkeleton *this, const __int16 *bonePairMap, int numBonePairMap)
{
  hkString::memCpy(this->m_bonePairMap, bonePairMap, 2 * numBonePairMap);
}

// File Line: 256
// RVA: 0xB46D70
void __fastcall hkaMirroredSkeleton::computeBonePairingFromNames(hkaMirroredSkeleton *this, hkArrayBase<hkStringPtr> *ltag, hkArrayBase<hkStringPtr> *rtag)
{
  hkaMirroredSkeleton::computeBonePairingFromNames(ltag, rtag, this->m_skeleton, this->m_bonePairMap);
}

// File Line: 265
// RVA: 0xB46D90
void __fastcall hkaMirroredSkeleton::computeBonePairingFromNames(hkArrayBase<hkStringPtr> *ltag, hkArrayBase<hkStringPtr> *rtag, hkaSkeleton *skeleton, __int16 *bonePairMap)
{
  int v4; // esi
  hkaSkeleton *v5; // rbp
  hkArrayBase<hkStringPtr> *v6; // rbx
  hkArrayBase<hkStringPtr> *v7; // r13
  __int16 v8; // di
  __int16 *v9; // rcx
  __int16 v10; // r12
  int v11; // er14
  __int64 v12; // r15
  signed __int64 v13; // rcx
  hkStringPtr *v14; // rax
  __int16 v15; // bx
  __int64 v16; // rax
  hkStringBuf v17; // [rsp+30h] [rbp-C8h]
  hkArrayBase<hkStringPtr> *v18; // [rsp+108h] [rbp+10h]
  __int16 to; // [rsp+110h] [rbp+18h]
  __int16 *v20; // [rsp+118h] [rbp+20h]

  v20 = bonePairMap;
  v18 = rtag;
  v4 = skeleton->m_bones.m_size;
  v5 = skeleton;
  v6 = rtag;
  v7 = ltag;
  v8 = 0;
  if ( v4 > 0 )
  {
    v9 = bonePairMap;
    do
    {
      v10 = v8;
      v11 = 0;
      if ( v7->m_size > 0 )
      {
        v12 = 0i64;
        v13 = v8;
        while ( 1 )
        {
          hkStringBuf::hkStringBuf(
            &v17,
            (const char *)((_QWORD)v5->m_bones.m_data[v13].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
          v14 = v7->m_data;
          to = 255;
          hkStringBuf::replace(
            &v17,
            (const char *)((_QWORD)v14[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)&to,
            REPLACE_ALL);
          hkStringBuf::replace(
            &v17,
            (const char *)((_QWORD)v6->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)((_QWORD)v7->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            REPLACE_ALL);
          hkStringBuf::replace(
            &v17,
            (const char *)&to,
            (const char *)((_QWORD)v6->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            REPLACE_ALL);
          v15 = 0;
          while ( v15 == v8
               || hkStringBuf::compareTo(
                    &v17,
                    (const char *)((_QWORD)v5->m_bones.m_data[v15].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
          {
            if ( ++v15 >= v4 )
              goto LABEL_11;
          }
          v10 = v15;
LABEL_11:
          v17.m_string.m_size = 0;
          if ( v10 != v8 )
            break;
          if ( v17.m_string.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v17.m_string.m_data,
              v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
          v13 = v8;
          v6 = v18;
          ++v11;
          ++v12;
          if ( v11 >= v7->m_size )
            goto LABEL_18;
        }
        if ( v17.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v17.m_string.m_data,
            v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
LABEL_18:
        v6 = v18;
        v9 = v20;
      }
      v16 = v8++;
      v9[v16] = v10;
    }
    while ( v8 < v4 );
  }
}

// File Line: 313
// RVA: 0xB46F90
void __fastcall hkaMirroredSkeleton::computePartitionPairingFromNames(hkaMirroredSkeleton *this, hkArrayBase<hkStringPtr> *ltag, hkArrayBase<hkStringPtr> *rtag)
{
  hkaMirroredSkeleton::computePartitionPairingFromNames(ltag, rtag, this->m_skeleton, this->m_partitionPairMap);
}

// File Line: 322
// RVA: 0xB46FB0
void __fastcall hkaMirroredSkeleton::computePartitionPairingFromNames(hkArrayBase<hkStringPtr> *ltag, hkArrayBase<hkStringPtr> *rtag, hkaSkeleton *skeleton, __int16 *partitionPairMap)
{
  int v4; // esi
  hkaSkeleton *v5; // rbp
  hkArrayBase<hkStringPtr> *v6; // rbx
  hkArrayBase<hkStringPtr> *v7; // r13
  __int16 v8; // di
  __int16 *v9; // rcx
  __int16 v10; // r12
  int v11; // er14
  __int64 v12; // r15
  signed __int64 v13; // rcx
  hkStringPtr *v14; // rax
  char v15; // bl
  __int64 v16; // rax
  hkStringBuf v17; // [rsp+30h] [rbp-C8h]
  hkArrayBase<hkStringPtr> *v18; // [rsp+108h] [rbp+10h]
  __int16 to; // [rsp+110h] [rbp+18h]
  __int16 *v20; // [rsp+118h] [rbp+20h]

  v20 = partitionPairMap;
  v18 = rtag;
  v4 = skeleton->m_partitions.m_size;
  v5 = skeleton;
  v6 = rtag;
  v7 = ltag;
  v8 = 0;
  if ( v4 > 0 )
  {
    v9 = partitionPairMap;
    do
    {
      v10 = v8;
      v11 = 0;
      if ( v7->m_size > 0 )
      {
        v12 = 0i64;
        v13 = v8;
        while ( 1 )
        {
          hkStringBuf::hkStringBuf(
            &v17,
            (const char *)((_QWORD)v5->m_partitions.m_data[v13].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
          v14 = v7->m_data;
          to = 255;
          hkStringBuf::replace(
            &v17,
            (const char *)((_QWORD)v14[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)&to,
            REPLACE_ALL);
          hkStringBuf::replace(
            &v17,
            (const char *)((_QWORD)v6->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)((_QWORD)v7->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            REPLACE_ALL);
          hkStringBuf::replace(
            &v17,
            (const char *)&to,
            (const char *)((_QWORD)v6->m_data[v12].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            REPLACE_ALL);
          v15 = 0;
          while ( v15 == v8
               || hkStringBuf::compareTo(
                    &v17,
                    (const char *)((_QWORD)v5->m_partitions.m_data[v15].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
          {
            if ( ++v15 >= v4 )
              goto LABEL_11;
          }
          v10 = v15;
LABEL_11:
          v17.m_string.m_size = 0;
          if ( v10 != v8 )
            break;
          if ( v17.m_string.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v17.m_string.m_data,
              v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
          v13 = v8;
          v6 = v18;
          ++v11;
          ++v12;
          if ( v11 >= v7->m_size )
            goto LABEL_18;
        }
        if ( v17.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v17.m_string.m_data,
            v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
LABEL_18:
        v6 = v18;
        v9 = v20;
      }
      v16 = v8++;
      v9[v16] = v10;
    }
    while ( v8 < v4 );
  }
}

// File Line: 370
// RVA: 0xB466C0
void __fastcall hkaMirroredSkeleton::setAllBoneInvariantsFromReferencePose(hkaMirroredSkeleton *this, hkQuaternionf *worldAxis, float tolerance)
{
  hkaSkeleton *v3; // rax
  hkaMirroredSkeleton *v4; // rsi
  int v5; // edi
  hkQuaternionf *v6; // r14
  int v7; // ebx
  int v8; // er9
  int v9; // er9
  int v10; // er9
  int v11; // ebx
  int v12; // er9
  int v13; // er9
  float *v14; // rdi
  __int64 v15; // rcx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v16; // rax
  hkaPose v17; // [rsp+18h] [rbp-19h]
  hkResult result; // [rsp+98h] [rbp+67h]

  v3 = this->m_skeleton;
  v4 = this;
  v17.m_localPose.m_capacityAndFlags = 2147483648;
  v17.m_modelPose.m_capacityAndFlags = 2147483648;
  v17.m_skeleton = v3;
  v17.m_boneFlags.m_capacityAndFlags = 2147483648;
  v17.m_floatSlotValues.m_capacityAndFlags = 2147483648;
  v17.m_localPose.m_data = 0i64;
  v17.m_localPose.m_size = 0;
  v17.m_modelPose.m_data = 0i64;
  v17.m_modelPose.m_size = 0;
  v17.m_boneFlags.m_data = 0i64;
  v17.m_boneFlags.m_size = 0;
  *(_WORD *)&v17.m_modelInSync.m_bool = 0;
  v17.m_floatSlotValues.m_data = 0i64;
  v17.m_floatSlotValues.m_size = 0;
  v5 = v3->m_bones.m_size;
  v6 = worldAxis;
  v7 = (v5 + 3) & 0xFFFFFFFC;
  if ( v7 > 0 )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v17.m_modelPose,
      v7,
      48);
  if ( (v17.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) < v7 )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v17.m_localPose,
      v7,
      48);
  if ( (v17.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) < v7 )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v17.m_boneFlags,
      v7,
      4);
  if ( (v17.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF) < v5 )
  {
    v8 = v5;
    if ( v5 < 2 * (v17.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF) )
      v8 = 2 * (v17.m_modelPose.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v17.m_modelPose,
      v8,
      48);
  }
  v17.m_modelPose.m_size = v5;
  if ( (v17.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) < v5 )
  {
    v9 = v5;
    if ( v5 < 2 * (v17.m_localPose.m_capacityAndFlags & 0x3FFFFFFF) )
      v9 = 2 * (v17.m_localPose.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v17.m_localPose,
      v9,
      48);
  }
  v17.m_localPose.m_size = v5;
  if ( (v17.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) < v5 )
  {
    v10 = v5;
    if ( v5 < 2 * (v17.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF) )
      v10 = 2 * (v17.m_boneFlags.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v17.m_boneFlags,
      v10,
      4);
  }
  v17.m_boneFlags.m_size = v5;
  v11 = v17.m_skeleton->m_floatSlots.m_size;
  v12 = (v11 + 3) & 0xFFFFFFFC;
  if ( (v17.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) < v12 )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v17.m_floatSlotValues,
      v12,
      4);
  if ( (v17.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) < v11 )
  {
    v13 = v11;
    if ( v11 < 2 * (v17.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF) )
      v13 = 2 * (v17.m_floatSlotValues.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v17.m_floatSlotValues,
      v13,
      4);
  }
  v14 = &v17.m_floatSlotValues.m_data[v17.m_floatSlotValues.m_size];
  v15 = v11 - v17.m_floatSlotValues.m_size;
  if ( v11 - v17.m_floatSlotValues.m_size > 0 )
  {
    while ( v15 )
    {
      *v14 = 0.0;
      ++v14;
      --v15;
    }
  }
  v17.m_floatSlotValues.m_size = v11;
  hkaPose::setToReferencePose(&v17);
  v16 = hkaPose::getSyncedPoseModelSpace(&v17);
  hkaMirroredSkeleton::setAllBoneInvariantsFromSymmetricPose(v4, v6, tolerance, v16->m_data);
  hkaPose::~hkaPose(&v17);
}

// File Line: 377
// RVA: 0xB46930
void __fastcall hkaMirroredSkeleton::setAllBoneInvariantsFromSymmetricPose(hkaMirroredSkeleton *this, hkQuaternionf *worldAxis, float tolerance, hkaPose *pose)
{
  hkaMirroredSkeleton *v4; // rdi
  hkQuaternionf *v5; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v6; // rax

  v4 = this;
  v5 = worldAxis;
  v6 = hkaPose::getSyncedPoseModelSpace(pose);
  hkaMirroredSkeleton::setAllBoneInvariantsFromSymmetricPose(v4, v5, tolerance, v6->m_data);
}

// File Line: 382
// RVA: 0xB46980
void __fastcall hkaMirroredSkeleton::setAllBoneInvariantsFromSymmetricPose(hkaMirroredSkeleton *this, hkQuaternionf *worldAxis, float tolerance, hkQsTransformf *poseModelSpace)
{
  hkQuaternionf *v4; // rdi
  hkQsTransformf *v5; // rbp
  hkaMirroredSkeleton *v6; // rbx
  float v7; // xmm9_4
  int i; // esi
  __m128 v9; // xmm2
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm6
  __m128 v14; // xmm0
  __m128 v15; // xmm6
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm6
  __m128 v23; // xmm5
  __m128 v24; // xmm5
  __m128 v25; // xmm5
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  hkQuaternionf qInOut; // [rsp+20h] [rbp-58h]

  v4 = worldAxis;
  v5 = poseModelSpace;
  v6 = this;
  v7 = tolerance;
  hkaMirroredSkeleton::setBoneInvariant(this, -1, worldAxis);
  for ( i = 0; i < hkaMirroredSkeleton::numBones(v6); ++i )
  {
    v9 = v5[i].m_rotation.m_vec.m_quad;
    v10 = v5[i].m_rotation.m_vec.m_quad;
    v11 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v4->m_vec.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v4->m_vec.m_quad, v4->m_vec.m_quad, 201), v9));
    v12 = _mm_mul_ps(v4->m_vec.m_quad, v9);
    v13 = _mm_sub_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 255), v4->m_vec.m_quad), _mm_shuffle_ps(v11, v11, 201)),
            _mm_mul_ps(_mm_shuffle_ps(v4->m_vec.m_quad, v4->m_vec.m_quad, 255), v9));
    v14 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
    v15 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, _mm_add_ps(_mm_shuffle_ps(v14, v14, 177), v14)), 196);
    v16 = _mm_shuffle_ps(v15, v15, 255);
    v17 = v5[hkaMirroredSkeleton::getBonePair(v6, i)].m_rotation.m_vec.m_quad;
    v18 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v17);
    v19 = _mm_shuffle_ps(v17, v17, 255);
    v20 = _mm_mul_ps(v15, v19);
    v21 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 201), v15);
    v22 = _mm_mul_ps(v15, v17);
    v23 = _mm_sub_ps(v21, v18);
    v24 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v23, v23, 201), _mm_mul_ps(v17, v16)), v20);
    v25 = _mm_shuffle_ps(
            v24,
            _mm_unpackhi_ps(
              v24,
              _mm_sub_ps(
                _mm_mul_ps(v19, v16),
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                  _mm_shuffle_ps(v22, v22, 170)))),
            196);
    v26 = _mm_mul_ps(v25, v25);
    v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
    v28 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27);
    v29 = _mm_rsqrt_ps(v28);
    qInOut.m_vec.m_quad = _mm_mul_ps(
                            v25,
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                              _mm_mul_ps(*(__m128 *)_xmm, v29)));
    hkaMirroredSkeleton::canonicalize(v6, &qInOut, v7);
    hkaMirroredSkeleton::setBoneInvariant(v6, i, &qInOut);
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

  LODWORD(v3) = (unsigned __int128)_mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  if ( !(_S1_40 & 1) )
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
    if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(COERCE_FLOAT(_mm_shuffle_ps(v6, v6, 177)) + v6.m128_f32[0])) >> 1) >= (float)(1.0 - v3) )
      break;
    ++v4;
    if ( (signed __int64)v4 >= (signed __int64)&hkaMirroredSkeleton `RTTI Type Descriptor' )
      return;
  }
  *qInOut = (hkQuaternionf)v4->m_vec.m_quad;
}

// File Line: 482
// RVA: 0xB46BA0
void __fastcall hkaMirroredSkeleton::setBoneInvariant(hkaMirroredSkeleton *this, int bone, hkQuaternionf *axis)
{
  this->m_boneInvariants[bone + 1i64] = (hkQuaternionf)axis->m_vec.m_quad;
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
  return (unsigned int)(signed __int16)this->m_parentIndices[bone];
}

// File Line: 504
// RVA: 0xB471C0
signed __int64 __fastcall hkaMirroredSkeleton::getNumDataChunks()
{
  return 5i64;
}

// File Line: 509
// RVA: 0xB471D0
void __fastcall hkaMirroredSkeleton::getDataChunks(hkaMirroredSkeleton *this, hkaAnimation::DataChunk *dataOut)
{
  hkaAnimation::DataChunk *v2; // rdi
  hkaMirroredSkeleton *v3; // rbx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // ecx

  v2 = dataOut;
  v3 = this;
  dataOut->m_data = (const char *)this;
  dataOut->m_size = 104;
  v4 = hkaMirroredSkeleton::numBones(this);
  v2[1].m_data = (const char *)v3->m_parentIndices;
  v2[1].m_size = 2 * v4;
  v5 = hkaMirroredSkeleton::numBones(v3);
  v2[2].m_data = (const char *)v3->m_boneInvariants;
  v2[2].m_size = 16 * (v5 + 1);
  v6 = hkaMirroredSkeleton::numBones(v3);
  v2[3].m_data = (const char *)v3->m_bonePairMap;
  v2[3].m_size = 2 * v6;
  v7 = v3->m_numPartitions;
  v2[4].m_data = (const char *)v3->m_partitions;
  v2[4].m_size = 16 * v7;
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

