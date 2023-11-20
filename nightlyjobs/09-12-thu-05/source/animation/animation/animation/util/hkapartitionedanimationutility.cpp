// File Line: 19
// RVA: 0xB3E520
void __fastcall hkaPartitionedAnimationUtility::createPartitionedAnimation(hkaPartitionedAnimationUtility::Input *input, hkaPartitionedAnimationUtility::Output *output)
{
  hkaPartitionedAnimationUtility::Output *v2; // rbx
  hkaSkeleton *v3; // rdx
  hkaPartitionedAnimationUtility::Input *v4; // rdi
  signed __int64 v5; // rsi
  int v6; // er14
  int v7; // ebp
  signed __int16 v8; // r11
  __int16 v9; // ax
  signed __int64 v10; // r10
  __int16 v11; // r8
  hkaSkeleton *v12; // rdx
  signed __int64 v13; // rcx
  hkQsTransformf *v14; // rcx
  hkVector4f *v15; // rdx
  hkBool result; // [rsp+40h] [rbp+8h]

  v2 = output;
  v3 = input->m_skeleton;
  v4 = input;
  if ( v3 && hkaSkeletonUtils::hasValidPartitions(&result, v3)->m_bool )
  {
    hkaPartitionedAnimationUtility::getPartitionIndices(
      v4->m_partitionNames,
      v4->m_numberOfPartitions,
      v4->m_skeleton,
      v2->m_partitionIndicesOut);
    v5 = 0i64;
    v2->m_numTransformTracksOut = 0;
    v6 = 0;
    v7 = 0;
    if ( v4->m_numberOfPoses <= 0 )
    {
LABEL_15:
      v2->m_numTotalTranformsOut = v6;
    }
    else
    {
      while ( 1 )
      {
        v8 = 0;
        if ( v4->m_numberOfTransformTracks > 0 )
          break;
LABEL_14:
        if ( ++v7 >= v4->m_numberOfPoses )
          goto LABEL_15;
      }
      while ( 1 )
      {
        v9 = 0;
        if ( v4->m_numberOfPartitions > 0 )
          break;
LABEL_13:
        if ( ++v8 >= v4->m_numberOfTransformTracks )
          goto LABEL_14;
      }
      v10 = v5;
      while ( 1 )
      {
        v11 = v2->m_partitionIndicesOut[v9];
        if ( v11 < 0 )
          break;
        v12 = v4->m_skeleton;
        if ( v11 >= v12->m_partitions.m_size )
          break;
        v13 = (signed __int64)&v12->m_partitions.m_data[v11];
        if ( v8 < *(signed __int16 *)(v13 + 8) + *(signed __int16 *)(v13 + 10) && *(signed __int16 *)(v13 + 8) <= v8 )
        {
          ++v10;
          ++v6;
          ++v5;
          v14 = v2->m_transformsOut;
          v15 = &v4->m_animationData[v8 + v7 * v4->m_numberOfTransformTracks].m_translation;
          v14[v10 - 1].m_translation = (hkVector4f)v15->m_quad;
          *((hkVector4f *)&v14[v10] - 2) = (hkVector4f)v15[1].m_quad;
          *((hkVector4f *)&v14[v10] - 1) = (hkVector4f)v15[2].m_quad;
          if ( !v7 )
            ++v2->m_numTransformTracksOut;
        }
        if ( ++v9 >= v4->m_numberOfPartitions )
          goto LABEL_13;
      }
    }
  }
}

// File Line: 66
// RVA: 0xB3F200
void __fastcall hkaPartitionedAnimationUtility::sortPartitionNames(hkStringPtr *partitionNames, int numParitionNames, hkaSkeleton *skeleton, hkStringPtr *partitionNamesOut)
{
  __int64 v4; // rsi
  hkStringPtr *v5; // r15
  hkStringPtr *v6; // rcx
  hkaSkeleton *v7; // r13
  __int64 v8; // r12
  int v9; // eax
  hkLifoAllocator *v10; // rax
  int v11; // edx
  char *v12; // r8
  signed int v13; // edx
  int v14; // er9
  __int64 v15; // r14
  int v16; // ebx
  hkStringPtr *v17; // rdi
  hkStringPtr *v18; // rbx
  __int64 v19; // rdi
  hkStringPtr *v20; // r14
  signed int v21; // edi
  const char *v22; // rsi
  signed __int16 v23; // bx
  int v24; // esi
  int v25; // edi
  __int64 v26; // rbx
  hkStringPtr *v27; // r15
  int v28; // ebx
  hkStringPtr *v29; // rdi
  char *v30; // rdi
  signed int v31; // ebx
  hkLifoAllocator *v32; // rax
  int v33; // er8
  int v34; // ebx
  hkStringPtr *v35; // rdi
  hkStringPtr *array; // [rsp+30h] [rbp-20h]
  int v37; // [rsp+38h] [rbp-18h]
  int v38; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v40; // [rsp+48h] [rbp-8h]
  hkResult result; // [rsp+98h] [rbp+48h]
  __int64 v42; // [rsp+A0h] [rbp+50h]
  hkStringPtr *v43; // [rsp+A8h] [rbp+58h]

  v43 = partitionNamesOut;
  v4 = skeleton->m_partitions.m_size;
  v5 = partitionNames;
  v6 = 0i64;
  v7 = skeleton;
  v8 = (unsigned int)numParitionNames;
  v38 = 2147483648;
  array = 0i64;
  v9 = 0;
  v37 = 0;
  v40 = v4;
  if ( (_DWORD)v4 )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkStringPtr *)v10->m_cur;
    v11 = (8 * v4 + 127) & 0xFFFFFF80;
    v12 = (char *)v6 + v11;
    if ( v11 > v10->m_slabSize || v12 > v10->m_end )
      v6 = (hkStringPtr *)hkLifoAllocator::allocateFromNewSlab(v10, v11);
    else
      v10->m_cur = v12;
    v9 = v37;
  }
  array = v6;
  p = v6;
  v38 = v4 | 0x80000000;
  v13 = (v4 | 0x80000000) & 0x3FFFFFFF;
  if ( v13 < (signed int)v4 )
  {
    v14 = v4;
    if ( (signed int)v4 < 2 * v13 )
      v14 = 2 * v13;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v14, 8);
    v9 = v37;
    v6 = array;
  }
  v15 = v4;
  v42 = v4;
  v16 = v9 - v4 - 1;
  if ( v16 >= 0 )
  {
    v17 = &v6[v4 + v16];
    do
    {
      hkStringPtr::~hkStringPtr(v17);
      --v17;
      --v16;
    }
    while ( v16 >= 0 );
    v9 = v37;
    v6 = array;
  }
  v18 = &v6[v9];
  if ( (signed int)v4 - v9 > 0 )
  {
    v19 = (unsigned int)(v4 - v9);
    do
    {
      if ( v18 )
        hkStringPtr::hkStringPtr(v18);
      ++v18;
      --v19;
    }
    while ( v19 );
    v6 = array;
  }
  v37 = v4;
  if ( (signed int)v8 > 0 )
  {
    v20 = v5;
    do
    {
      v21 = v7->m_partitions.m_size;
      v22 = (const char *)((_QWORD)v5->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      v23 = 0;
      if ( v21 <= 0 )
      {
LABEL_27:
        v23 = -1;
      }
      else
      {
        while ( hkString::strCmp(
                  v22,
                  (const char *)((_QWORD)v7->m_partitions.m_data[v23].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
        {
          if ( ++v23 >= v21 )
          {
            v6 = array;
            goto LABEL_27;
          }
        }
        v6 = array;
      }
      if ( v23 >= 0 )
      {
        hkStringPtr::operator=(&v6[v23], v20);
        v6 = array;
      }
      ++v20;
      ++v5;
      --v8;
    }
    while ( v8 );
    v15 = v42;
  }
  v24 = 0;
  v25 = 0;
  v26 = 0i64;
  if ( v15 > 0 )
  {
    v27 = v43;
    do
    {
      if ( (_QWORD)v6[v26].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
      {
        hkStringPtr::operator=(&v27[v24], &v6[v25]);
        v6 = array;
        ++v24;
      }
      ++v26;
      ++v25;
    }
    while ( v26 < v15 );
  }
  if ( p == v6 )
  {
    v28 = v37 - 1;
    if ( v37 - 1 >= 0 )
    {
      v29 = &v6[v28];
      do
      {
        hkStringPtr::~hkStringPtr(v29);
        --v29;
        --v28;
      }
      while ( v28 >= 0 );
    }
    v37 = 0;
  }
  v30 = (char *)p;
  v31 = (8 * v40 + 127) & 0xFFFFFF80;
  v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v33 = (v31 + 15) & 0xFFFFFFF0;
  if ( v31 > v32->m_slabSize || &v30[v33] != v32->m_cur || v32->m_firstNonLifoEnd == v30 )
    hkLifoAllocator::slowBlockFree(v32, v30, v33);
  else
    v32->m_cur = v30;
  v34 = v37 - 1;
  if ( v37 - 1 >= 0 )
  {
    v35 = &array[v34];
    do
    {
      hkStringPtr::~hkStringPtr(v35);
      --v35;
      --v34;
    }
    while ( v34 >= 0 );
  }
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v38);
}

// File Line: 104
// RVA: 0xB3E6C0
void __fastcall hkaPartitionedAnimationUtility::getPartitionIndices(hkStringPtr *partitionNames, int numPartitionNames, hkaSkeleton *skeleton, __int16 *partitionIndicesOut)
{
  __int64 v4; // rsi
  __int16 *v5; // r13
  int v6; // eax
  hkaSkeleton *v7; // r15
  hkStringPtr *v8; // r14
  hkLifoAllocator *v9; // rax
  hkStringPtr *v10; // r9
  int v11; // edx
  char *v12; // rcx
  hkStringPtr *v13; // rax
  signed int v14; // ecx
  int v15; // er9
  __int64 v16; // r12
  int v17; // ebx
  hkStringPtr *v18; // rdi
  hkStringPtr *v19; // rbx
  __int64 v20; // rdi
  __int64 i; // rsi
  signed int v22; // edi
  signed __int16 v23; // bx
  const char *v24; // r14
  char *v25; // rdi
  int v26; // ebx
  hkStringPtr *v27; // rdi
  signed int v28; // ebx
  hkLifoAllocator *v29; // rax
  int v30; // er8
  int v31; // ebx
  hkStringPtr *v32; // rdi
  hkStringPtr *array; // [rsp+30h] [rbp-20h]
  int v34; // [rsp+38h] [rbp-18h]
  int v35; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v37; // [rsp+48h] [rbp-8h]
  hkResult result; // [rsp+88h] [rbp+38h]

  v4 = numPartitionNames;
  v5 = partitionIndicesOut;
  v6 = 0;
  v7 = skeleton;
  v8 = partitionNames;
  array = 0i64;
  v35 = 2147483648;
  v37 = numPartitionNames;
  v34 = 0;
  if ( numPartitionNames )
  {
    v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v10 = (hkStringPtr *)v9->m_cur;
    v11 = (8 * v4 + 127) & 0xFFFFFF80;
    v12 = (char *)v10 + v11;
    if ( v11 > v9->m_slabSize || v12 > v9->m_end )
    {
      v13 = (hkStringPtr *)hkLifoAllocator::allocateFromNewSlab(v9, v11);
      v10 = v13;
      array = v13;
      v6 = v34;
    }
    else
    {
      v9->m_cur = v12;
      v6 = v34;
      array = v10;
    }
  }
  else
  {
    v10 = 0i64;
    array = 0i64;
  }
  p = v10;
  v35 = v4 | 0x80000000;
  v14 = (v4 | 0x80000000) & 0x3FFFFFFF;
  if ( v14 < (signed int)v4 )
  {
    v15 = v4;
    if ( (signed int)v4 < 2 * v14 )
      v15 = 2 * v14;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 8);
    v6 = v34;
    v10 = array;
  }
  v16 = v4;
  v17 = v6 - v4 - 1;
  if ( v17 >= 0 )
  {
    v18 = &v10[v4 + v17];
    do
    {
      hkStringPtr::~hkStringPtr(v18);
      --v18;
      --v17;
    }
    while ( v17 >= 0 );
    v6 = v34;
    v10 = array;
  }
  v19 = &v10[v6];
  if ( (signed int)v4 - v6 > 0 )
  {
    v20 = (unsigned int)(v4 - v6);
    do
    {
      if ( v19 )
        hkStringPtr::hkStringPtr(v19);
      ++v19;
      --v20;
    }
    while ( v20 );
    v10 = array;
  }
  v34 = v4;
  hkaPartitionedAnimationUtility::sortPartitionNames(v8, v4, v7, v10);
  for ( i = 0i64; i < v16; ++i )
  {
    v22 = v7->m_partitions.m_size;
    v23 = 0;
    v24 = (const char *)((_QWORD)array[i].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( v22 <= 0 )
    {
LABEL_25:
      v23 = -1;
    }
    else
    {
      while ( hkString::strCmp(
                v24,
                (const char *)((_QWORD)v7->m_partitions.m_data[v23].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
      {
        if ( ++v23 >= v22 )
          goto LABEL_25;
      }
    }
    v5[i] = v23;
  }
  v25 = (char *)p;
  if ( p == array )
  {
    v26 = v34 - 1;
    if ( v34 - 1 >= 0 )
    {
      v27 = &array[v26];
      do
      {
        hkStringPtr::~hkStringPtr(v27);
        --v27;
        --v26;
      }
      while ( v26 >= 0 );
      v25 = (char *)p;
    }
    v34 = 0;
  }
  v28 = (8 * v37 + 127) & 0xFFFFFF80;
  v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v30 = (v28 + 15) & 0xFFFFFFF0;
  if ( v28 > v29->m_slabSize || &v25[v30] != v29->m_cur || v29->m_firstNonLifoEnd == v25 )
    hkLifoAllocator::slowBlockFree(v29, v25, v30);
  else
    v29->m_cur = v25;
  v31 = v34 - 1;
  if ( v34 - 1 >= 0 )
  {
    v32 = &array[v31];
    do
    {
      hkStringPtr::~hkStringPtr(v32);
      --v32;
      --v31;
    }
    while ( v31 >= 0 );
  }
  v34 = 0;
  if ( v35 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v35);
}

// File Line: 129
// RVA: 0xB3E990
void __fastcall hkaPartitionedAnimationUtility::setPartitionPoseToReference(hkaSkeleton *skeleton, const __int16 *partitionIndices, int numPartitionIndices, hkQsTransformf *transformsOut)
{
  int v4; // esi
  hkQsTransformf *v5; // r15
  hkaSkeleton *v6; // r14
  __int64 v7; // rbp
  __int64 v8; // rbx
  signed __int64 v9; // rdi
  int v10; // ecx
  __m128 *v11; // r10
  __m128 *v12; // rax
  __int64 v13; // r11
  int v14; // er8
  int v15; // er9
  int v16; // ecx

  if ( numPartitionIndices > 0 )
  {
    v4 = 0;
    v5 = transformsOut;
    v6 = skeleton;
    v7 = numPartitionIndices;
    v8 = 0i64;
    do
    {
      v9 = (signed __int64)&v6->m_partitions.m_data[partitionIndices[v8]];
      v10 = 3 * *(signed __int16 *)(v9 + 10);
      v11 = &v6->m_referencePose.m_data[*(signed __int16 *)(v9 + 8)].m_translation.m_quad;
      v12 = &v5[v4].m_translation.m_quad;
      if ( v10 > 0 )
      {
        v13 = (unsigned int)v10;
        do
        {
          v14 = v11->m128_u64[1];
          v15 = HIDWORD(v11->m128_u64[1]);
          v16 = v11->m128_u64[0];
          HIDWORD(v12->m128_u64[0]) = HIDWORD(v11->m128_u64[0]);
          LODWORD(v12->m128_u64[1]) = v14;
          HIDWORD(v12->m128_u64[1]) = v15;
          LODWORD(v12->m128_u64[0]) = v16;
          ++v12;
          ++v11;
          --v13;
        }
        while ( v13 );
      }
      ++v8;
      v4 += *(signed __int16 *)(v9 + 10);
    }
    while ( v8 < v7 );
  }
}

// File Line: 141
// RVA: 0xB3EA60
__int16 __fastcall hkaPartitionedAnimationUtility::getNumberOfBonesInPartitions(hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *partitions)
{
  __int64 v1; // rdx
  __int16 result; // ax
  __int16 *v3; // rcx

  v1 = partitions->m_size;
  result = 0;
  if ( (signed int)v1 > 0 )
  {
    v3 = &partitions->m_data->m_numBones;
    do
    {
      result += *v3;
      v3 += 8;
      --v1;
    }
    while ( v1 );
  }
  return result;
}

// File Line: 152
// RVA: 0xB3EA90
__int16 __fastcall hkaPartitionedAnimationUtility::getNumMappedPartitionBones(const __int16 *aToBPartitionMap, const __int16 *partitionIndicesSkeletonA, int numPartitionIndicesSkeletonA, hkaSkeleton *skelB)
{
  __int16 result; // ax
  const __int16 *v5; // rbx
  signed __int64 v6; // r10
  __int64 v7; // rdx

  result = 0;
  v5 = partitionIndicesSkeletonA;
  v6 = 0i64;
  if ( numPartitionIndicesSkeletonA > 0 )
  {
    do
    {
      v7 = v5[v6++];
      result += skelB->m_partitions.m_data[aToBPartitionMap[v7]].m_numBones;
    }
    while ( v6 < numPartitionIndicesSkeletonA );
  }
  return result;
}

// File Line: 168
// RVA: 0xB3EAF0
void __fastcall hkaPartitionedAnimationUtility::getMappedPartitionIndices(const __int16 *aToBPartitionMap, const __int16 *partitionIndicesSkeletonA, int numPartitionIndicesSkeletonA, hkaSkeleton *skelB, __int16 *partitionIndicesBOut)
{
  __int64 v5; // r9
  __int16 *v6; // rax
  signed __int64 v7; // r10
  __int64 v8; // rdx

  v5 = numPartitionIndicesSkeletonA;
  if ( numPartitionIndicesSkeletonA > 0 )
  {
    v6 = partitionIndicesBOut;
    v7 = (char *)partitionIndicesSkeletonA - (char *)partitionIndicesBOut;
    do
    {
      v8 = *(__int16 *)((char *)v6 + v7);
      ++v6;
      *(v6 - 1) = aToBPartitionMap[v8];
      --v5;
    }
    while ( v5 );
  }
  hkAlgorithm::insertionSort<short>(partitionIndicesBOut, numPartitionIndicesSkeletonA);
}

// File Line: 185
// RVA: 0xB3EB40
void __fastcall hkaPartitionedAnimationUtility::getPartitionsFromIndices(hkaSkeleton *skeleton, hkArray<short,hkContainerHeapAllocator> *partitionIndices, hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *partitionsOut)
{
  int v3; // ebp
  hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *v4; // rbx
  hkArray<short,hkContainerHeapAllocator> *v5; // r15
  hkaSkeleton *v6; // r12
  __int64 v7; // r14
  signed __int64 v8; // rsi
  signed __int64 v9; // rdi

  v3 = 0;
  v4 = partitionsOut;
  v5 = partitionIndices;
  v6 = skeleton;
  if ( partitionIndices->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = (signed __int64)&v6->m_partitions.m_data[v5->m_data[v7]];
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
      v9 = (signed __int64)&v4->m_data[v4->m_size];
      if ( v9 )
      {
        hkStringPtr::hkStringPtr((hkStringPtr *)v9, (hkStringPtr *)v8);
        *(_WORD *)(v9 + 8) = *(_WORD *)(v8 + 8);
        *(_WORD *)(v9 + 10) = *(_WORD *)(v8 + 10);
      }
      ++v4->m_size;
      ++v3;
      ++v7;
    }
    while ( v3 < v5->m_size );
  }
}

// File Line: 194
// RVA: 0xB3EC10
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPose(hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *partitions, hkArray<short,hkContainerHeapAllocator> *partitionIndices, hkQsTransformf *transformsIn, int numTransformsIn, hkQsTransformf *transformsOut)
{
  hkaPartitionedAnimationUtility::mapPartitionPoseToFullPose(
    partitions->m_data,
    partitionIndices->m_data,
    partitionIndices->m_size,
    transformsIn,
    numTransformsIn,
    transformsOut);
}

// File Line: 200
// RVA: 0xB3EC40
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPose(hkaSkeleton::Partition *partitions, const __int16 *partitionIndices, int numPartitionIndices, hkQsTransformf *transformsIn, int numTransformsIn, hkQsTransformf *transformsOut)
{
  int v6; // esi
  hkQsTransformf *v7; // r15
  __int64 v8; // rbx
  hkaSkeleton::Partition *v9; // r13
  __int64 v10; // rbp
  signed __int64 v11; // rdi
  int v12; // ecx
  __m128 *v13; // r10
  hkQsTransformf *v14; // rax
  __int64 v15; // r11
  int v16; // er8
  int v17; // er9
  int v18; // ecx

  if ( numPartitionIndices > 0 )
  {
    v6 = 0;
    v7 = transformsIn;
    v8 = 0i64;
    v9 = partitions;
    v10 = numPartitionIndices;
    do
    {
      v11 = partitionIndices[v8];
      v12 = 3 * v9[partitionIndices[v8]].m_numBones;
      v13 = &v7[v6].m_translation.m_quad;
      v14 = &transformsOut[v9[partitionIndices[v8]].m_startBoneIndex];
      if ( v12 > 0 )
      {
        v15 = (unsigned int)v12;
        do
        {
          v16 = v13->m128_u64[1];
          v17 = HIDWORD(v13->m128_u64[1]);
          v18 = v13->m128_u64[0];
          v14->m_translation.m_quad.m128_i32[1] = HIDWORD(v13->m128_u64[0]);
          v14->m_translation.m_quad.m128_i32[2] = v16;
          v14->m_translation.m_quad.m128_i32[3] = v17;
          v14->m_translation.m_quad.m128_i32[0] = v18;
          v14 = (hkQsTransformf *)((char *)v14 + 16);
          ++v13;
          --v15;
        }
        while ( v15 );
      }
      ++v8;
      v6 += v9[v11].m_numBones;
    }
    while ( v8 < v10 );
  }
}

// File Line: 216
// RVA: 0xB3ED20
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPose(hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *animPartitions, hkQsTransformf *transformsIn, int numTransformsIn, hkQsTransformf *transformsOut)
{
  int v4; // edi
  hkQsTransformf *v5; // r15
  int v6; // ebx
  hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *v7; // r14
  __int64 v8; // rsi
  hkaSkeleton::Partition *v9; // rbp
  int v10; // ecx
  hkQsTransformf *v11; // r10
  __m128 *v12; // rax
  __int64 v13; // r11
  float v14; // er8
  float v15; // er9
  int v16; // ecx
  int v17; // eax

  v4 = 0;
  v5 = transformsOut;
  v6 = 0;
  v7 = animPartitions;
  if ( animPartitions->m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v7->m_data;
      v10 = 3 * v7->m_data[v8].m_numBones;
      v11 = &transformsIn[v4];
      v12 = &v5[v7->m_data[v8].m_startBoneIndex].m_translation.m_quad;
      if ( v10 > 0 )
      {
        v13 = (unsigned int)v10;
        do
        {
          v14 = v11->m_translation.m_quad.m128_f32[2];
          v15 = v11->m_translation.m_quad.m128_f32[3];
          v16 = v11->m_translation.m_quad.m128_i32[0];
          HIDWORD(v12->m128_u64[0]) = LODWORD(v11->m_translation.m_quad.m128_f32[1]);
          *(float *)&v12->m128_u64[1] = v14;
          *((float *)&v12->m128_u64[1] + 1) = v15;
          LODWORD(v12->m128_u64[0]) = v16;
          ++v12;
          v11 = (hkQsTransformf *)((char *)v11 + 16);
          --v13;
        }
        while ( v13 );
      }
      v17 = v9[v8].m_numBones;
      ++v6;
      ++v8;
      v4 += v17;
    }
    while ( v6 < v7->m_size );
  }
}

// File Line: 232
// RVA: 0xB3EE00
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *partitions, hkArray<short,hkContainerHeapAllocator> *partitionIndices, hkQsTransformf *transformsIn, const char *weightsIn, int numTransformsIn, hkQsTransformf *transformsOut, char *weightsOut)
{
  hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(
    partitions->m_data,
    partitionIndices->m_data,
    partitionIndices->m_size,
    transformsIn,
    weightsIn,
    numTransformsIn,
    transformsOut,
    weightsOut);
}

// File Line: 238
// RVA: 0xB3EE50
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(hkaSkeleton::Partition *partitions, const __int16 *partitionIndices, int numPartitionIndices, hkQsTransformf *transformsIn, const char *weightsIn, int numTransformsIn, hkQsTransformf *transformsOut, char *weightsOut)
{
  int v8; // esi
  const __int16 *v9; // rax
  __int64 v10; // rdi
  __int64 v11; // rbp
  hkaSkeleton::Partition *v12; // rbx
  hkQsTransformf *v13; // r10
  int v14; // ecx
  hkQsTransformf *v15; // rax
  __int64 v16; // r11
  int v17; // er8
  int v18; // er9
  int v19; // ecx
  hkaSkeleton::Partition *v20; // [rsp+60h] [rbp+8h]
  const __int16 *v21; // [rsp+68h] [rbp+10h]
  hkQsTransformf *v22; // [rsp+78h] [rbp+20h]

  if ( numPartitionIndices > 0 )
  {
    v22 = transformsIn;
    v21 = partitionIndices;
    v20 = partitions;
    v8 = 0;
    v9 = partitionIndices;
    v10 = 0i64;
    v11 = numPartitionIndices;
    do
    {
      v12 = &partitions[v9[v10]];
      v13 = &transformsIn[v8];
      v14 = 3 * v12->m_numBones;
      v15 = &transformsOut[v12->m_startBoneIndex];
      if ( v14 > 0 )
      {
        v16 = (unsigned int)v14;
        do
        {
          v17 = v13->m_translation.m_quad.m128_i32[2];
          v18 = v13->m_translation.m_quad.m128_i32[3];
          v19 = v13->m_translation.m_quad.m128_i32[0];
          v15->m_translation.m_quad.m128_i32[1] = v13->m_translation.m_quad.m128_i32[1];
          v15->m_translation.m_quad.m128_i32[2] = v17;
          v15->m_translation.m_quad.m128_i32[3] = v18;
          v15->m_translation.m_quad.m128_i32[0] = v19;
          v15 = (hkQsTransformf *)((char *)v15 + 16);
          v13 = (hkQsTransformf *)((char *)v13 + 16);
          --v16;
        }
        while ( v16 );
      }
      hkString::memCpy(&weightsOut[v12->m_startBoneIndex], &weightsIn[v8], v12->m_numBones);
      transformsIn = v22;
      partitions = v20;
      v8 += v12->m_numBones;
      v9 = v21;
      ++v10;
    }
    while ( v10 < v11 );
  }
}

// File Line: 256
// RVA: 0xB3EF80
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(hkaSkeleton::Partition *partitions, const __int16 *partitionIndices, int numPartitionIndices, hkQsTransformf *transformsIn, const float *weightsIn, int numTransformsIn, hkQsTransformf *transformsOut, float *weightsOut)
{
  int v8; // esi
  const __int16 *v9; // rax
  __int64 v10; // rdi
  __int64 v11; // rbp
  hkaSkeleton::Partition *v12; // rbx
  hkQsTransformf *v13; // r10
  int v14; // ecx
  hkQsTransformf *v15; // rax
  __int64 v16; // r11
  int v17; // er8
  int v18; // er9
  int v19; // ecx
  __int64 v20; // r8
  const float *v21; // rcx
  float *v22; // rdx
  int v23; // eax
  hkaSkeleton::Partition *v24; // [rsp+40h] [rbp+8h]
  const __int16 *v25; // [rsp+48h] [rbp+10h]
  hkQsTransformf *v26; // [rsp+58h] [rbp+20h]

  if ( numPartitionIndices > 0 )
  {
    v26 = transformsIn;
    v25 = partitionIndices;
    v24 = partitions;
    v8 = 0;
    v9 = partitionIndices;
    v10 = 0i64;
    v11 = numPartitionIndices;
    do
    {
      v12 = &partitions[v9[v10]];
      v13 = &transformsIn[v8];
      v14 = 3 * v12->m_numBones;
      v15 = &transformsOut[v12->m_startBoneIndex];
      if ( v14 > 0 )
      {
        v16 = (unsigned int)v14;
        do
        {
          v17 = v13->m_translation.m_quad.m128_i32[2];
          v18 = v13->m_translation.m_quad.m128_i32[3];
          v19 = v13->m_translation.m_quad.m128_i32[0];
          v15->m_translation.m_quad.m128_i32[1] = v13->m_translation.m_quad.m128_i32[1];
          v15->m_translation.m_quad.m128_i32[2] = v17;
          v15->m_translation.m_quad.m128_i32[3] = v18;
          v15->m_translation.m_quad.m128_i32[0] = v19;
          v15 = (hkQsTransformf *)((char *)v15 + 16);
          v13 = (hkQsTransformf *)((char *)v13 + 16);
          --v16;
        }
        while ( v16 );
        transformsIn = v26;
      }
      LODWORD(v20) = v12->m_numBones;
      v21 = &weightsIn[v8];
      v22 = &weightsOut[v12->m_startBoneIndex];
      if ( (signed int)v20 > 0 )
      {
        v20 = (unsigned int)v20;
        do
        {
          v23 = *(_DWORD *)v21;
          ++v22;
          ++v21;
          *((_DWORD *)v22 - 1) = v23;
          --v20;
        }
        while ( v20 );
      }
      partitions = v24;
      ++v10;
      v8 += v12->m_numBones;
      v9 = v25;
    }
    while ( v10 < v11 );
  }
}

// File Line: 274
// RVA: 0xB3F0C0
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *animPartitions, hkQsTransformf *transformsIn, const char *weightsIn, int numTransformsIn, hkQsTransformf *transformsOut, char *weightsOut)
{
  int v6; // edi
  const char *v7; // r13
  hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *v8; // rbp
  int v9; // esi
  __int64 v10; // r14
  hkaSkeleton::Partition *v11; // rbx
  int v12; // ecx
  hkQsTransformf *v13; // r10
  hkQsTransformf *v14; // rax
  __int64 v15; // r11
  int v16; // er8
  int v17; // er9
  int v18; // ecx
  hkQsTransformf *v19; // [rsp+58h] [rbp+10h]

  v19 = transformsIn;
  v6 = 0;
  v7 = weightsIn;
  v8 = animPartitions;
  v9 = 0;
  if ( animPartitions->m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = &v8->m_data[v10];
      v12 = 3 * v11->m_numBones;
      v13 = &transformsIn[v6];
      v14 = &transformsOut[v11->m_startBoneIndex];
      if ( v12 > 0 )
      {
        v15 = (unsigned int)v12;
        do
        {
          v16 = v13->m_translation.m_quad.m128_i32[2];
          v17 = v13->m_translation.m_quad.m128_i32[3];
          v18 = v13->m_translation.m_quad.m128_i32[0];
          v14->m_translation.m_quad.m128_i32[1] = v13->m_translation.m_quad.m128_i32[1];
          v14->m_translation.m_quad.m128_i32[2] = v16;
          v14->m_translation.m_quad.m128_i32[3] = v17;
          v14->m_translation.m_quad.m128_i32[0] = v18;
          v14 = (hkQsTransformf *)((char *)v14 + 16);
          v13 = (hkQsTransformf *)((char *)v13 + 16);
          --v15;
        }
        while ( v15 );
      }
      hkString::memCpy(&weightsOut[v11->m_startBoneIndex], &v7[v6], v11->m_numBones);
      transformsIn = v19;
      ++v9;
      v6 += v11->m_numBones;
      ++v10;
    }
    while ( v9 < v8->m_size );
  }
}

// File Line: 291
// RVA: 0xB3F1C0
char __fastcall hkaPartitionedAnimationUtility::hasValidPartitions(hkaAnimationBinding *binding, hkaSkeleton *skeleton)
{
  __int64 v2; // r8
  int v3; // er9
  __int64 v4; // rdx
  __int16 *v5; // rcx

  v2 = binding->m_partitionIndices.m_size;
  v3 = skeleton->m_partitions.m_size;
  v4 = 0i64;
  if ( v2 <= 0 )
    return 1;
  v5 = binding->m_partitionIndices.m_data;
  while ( *v5 >= 0 && *v5 < v3 )
  {
    ++v4;
    ++v5;
    if ( v4 >= v2 )
      return 1;
  }
  return 0;
}

