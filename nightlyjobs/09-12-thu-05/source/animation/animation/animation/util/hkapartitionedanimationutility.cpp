// File Line: 19
// RVA: 0xB3E520
void __fastcall hkaPartitionedAnimationUtility::createPartitionedAnimation(
        hkaPartitionedAnimationUtility::Input *input,
        hkaPartitionedAnimationUtility::Output *output)
{
  hkaSkeleton *m_skeleton; // rdx
  __int64 v5; // rsi
  int v6; // r14d
  int v7; // ebp
  __int16 v8; // r11
  __int16 v9; // ax
  __int64 v10; // r10
  __int16 v11; // r8
  hkaSkeleton *v12; // rdx
  __int64 v13; // rcx
  hkQsTransformf *m_transformsOut; // rcx
  hkQsTransformf *v15; // rdx
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  m_skeleton = input->m_skeleton;
  if ( m_skeleton && hkaSkeletonUtils::hasValidPartitions(&result, m_skeleton)->m_bool )
  {
    hkaPartitionedAnimationUtility::getPartitionIndices(
      input->m_partitionNames,
      input->m_numberOfPartitions,
      input->m_skeleton,
      output->m_partitionIndicesOut);
    v5 = 0i64;
    output->m_numTransformTracksOut = 0;
    v6 = 0;
    v7 = 0;
    if ( input->m_numberOfPoses <= 0 )
    {
LABEL_15:
      output->m_numTotalTranformsOut = v6;
    }
    else
    {
      while ( 1 )
      {
        v8 = 0;
        if ( input->m_numberOfTransformTracks > 0 )
          break;
LABEL_14:
        if ( ++v7 >= input->m_numberOfPoses )
          goto LABEL_15;
      }
      while ( 1 )
      {
        v9 = 0;
        if ( input->m_numberOfPartitions > 0 )
          break;
LABEL_13:
        if ( ++v8 >= input->m_numberOfTransformTracks )
          goto LABEL_14;
      }
      v10 = v5;
      while ( 1 )
      {
        v11 = output->m_partitionIndicesOut[v9];
        if ( v11 < 0 )
          break;
        v12 = input->m_skeleton;
        if ( v11 >= v12->m_partitions.m_size )
          break;
        v13 = (__int64)&v12->m_partitions.m_data[v11];
        if ( v8 < *(__int16 *)(v13 + 8) + *(__int16 *)(v13 + 10) && *(__int16 *)(v13 + 8) <= v8 )
        {
          ++v10;
          ++v6;
          ++v5;
          m_transformsOut = output->m_transformsOut;
          v15 = &input->m_animationData[v8 + v7 * input->m_numberOfTransformTracks];
          m_transformsOut[v10 - 1].m_translation = v15->m_translation;
          m_transformsOut[v10 - 1].m_rotation = v15->m_rotation;
          m_transformsOut[v10 - 1].m_scale = v15->m_scale;
          if ( !v7 )
            ++output->m_numTransformTracksOut;
        }
        if ( ++v9 >= input->m_numberOfPartitions )
          goto LABEL_13;
      }
    }
  }
}

// File Line: 66
// RVA: 0xB3F200
void __fastcall hkaPartitionedAnimationUtility::sortPartitionNames(
        hkStringPtr *partitionNames,
        unsigned int numParitionNames,
        hkaSkeleton *skeleton,
        hkStringPtr *partitionNamesOut)
{
  __int64 m_size; // rsi
  hkStringPtr *m_cur; // rcx
  __int64 v8; // r12
  int v9; // eax
  hkLifoAllocator *Value; // rax
  int v11; // edx
  char *v12; // r8
  int v13; // edx
  int v14; // r9d
  __int64 v15; // r14
  int v16; // ebx
  hkStringPtr *v17; // rdi
  hkStringPtr *v18; // rbx
  __int64 v19; // rdi
  hkStringPtr *v20; // r14
  int v21; // edi
  const char *v22; // rsi
  __int16 v23; // bx
  int v24; // esi
  int v25; // edi
  __int64 v26; // rbx
  hkStringPtr *v27; // r15
  int v28; // ebx
  hkStringPtr *v29; // rdi
  char *v30; // rdi
  signed int v31; // ebx
  hkLifoAllocator *v32; // rax
  int v33; // r8d
  int v34; // ebx
  hkStringPtr *v35; // rdi
  hkStringPtr *array; // [rsp+30h] [rbp-20h] BYREF
  int v37; // [rsp+38h] [rbp-18h]
  int v38; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v40; // [rsp+48h] [rbp-8h]
  hkResult result; // [rsp+98h] [rbp+48h] BYREF
  __int64 v42; // [rsp+A0h] [rbp+50h]
  hkStringPtr *v43; // [rsp+A8h] [rbp+58h]

  v43 = partitionNamesOut;
  m_size = skeleton->m_partitions.m_size;
  m_cur = 0i64;
  v8 = numParitionNames;
  v38 = 0x80000000;
  array = 0i64;
  v9 = 0;
  v37 = 0;
  v40 = m_size;
  if ( (_DWORD)m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkStringPtr *)Value->m_cur;
    v11 = (8 * m_size + 127) & 0xFFFFFF80;
    v12 = (char *)m_cur + v11;
    if ( v11 > Value->m_slabSize || v12 > Value->m_end )
      m_cur = (hkStringPtr *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
    else
      Value->m_cur = v12;
    v9 = v37;
  }
  array = m_cur;
  p = m_cur;
  v38 = m_size | 0x80000000;
  v13 = m_size & 0x3FFFFFFF;
  if ( (m_size & 0x3FFFFFFF) < (int)m_size )
  {
    v14 = m_size;
    if ( (int)m_size < 2 * v13 )
      v14 = 2 * v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v14, 8);
    v9 = v37;
    m_cur = array;
  }
  v15 = m_size;
  v42 = m_size;
  v16 = v9 - m_size - 1;
  if ( v16 >= 0 )
  {
    v17 = &m_cur[m_size + v16];
    do
    {
      hkStringPtr::~hkStringPtr(v17--);
      --v16;
    }
    while ( v16 >= 0 );
    v9 = v37;
    m_cur = array;
  }
  v18 = &m_cur[v9];
  if ( (int)m_size - v9 > 0 )
  {
    v19 = (unsigned int)(m_size - v9);
    do
    {
      if ( v18 )
        hkStringPtr::hkStringPtr(v18);
      ++v18;
      --v19;
    }
    while ( v19 );
    m_cur = array;
  }
  v37 = m_size;
  if ( (int)v8 > 0 )
  {
    v20 = partitionNames;
    do
    {
      v21 = skeleton->m_partitions.m_size;
      v22 = (const char *)((unsigned __int64)partitionNames->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
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
                  (const char *)((unsigned __int64)skeleton->m_partitions.m_data[v23].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
        {
          if ( ++v23 >= v21 )
          {
            m_cur = array;
            goto LABEL_27;
          }
        }
        m_cur = array;
      }
      if ( v23 >= 0 )
      {
        hkStringPtr::operator=(&m_cur[v23], v20);
        m_cur = array;
      }
      ++v20;
      ++partitionNames;
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
      if ( ((unsigned __int64)m_cur[v26].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      {
        hkStringPtr::operator=(&v27[v24], &m_cur[v25]);
        m_cur = array;
        ++v24;
      }
      ++v26;
      ++v25;
    }
    while ( v26 < v15 );
  }
  if ( p == m_cur )
  {
    v28 = v37 - 1;
    if ( v37 - 1 >= 0 )
    {
      v29 = &m_cur[v28];
      do
      {
        hkStringPtr::~hkStringPtr(v29--);
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
      hkStringPtr::~hkStringPtr(v35--);
      --v34;
    }
    while ( v34 >= 0 );
  }
  v37 = 0;
  if ( v38 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v38);
}

// File Line: 104
// RVA: 0xB3E6C0
void __fastcall hkaPartitionedAnimationUtility::getPartitionIndices(
        hkStringPtr *partitionNames,
        int numPartitionNames,
        hkaSkeleton *skeleton,
        __int16 *partitionIndicesOut)
{
  __int64 v4; // rsi
  int v6; // eax
  hkLifoAllocator *Value; // rax
  hkStringPtr *m_cur; // r9
  int v11; // edx
  char *v12; // rcx
  int v13; // ecx
  int v14; // r9d
  __int64 v15; // r12
  int v16; // ebx
  hkStringPtr *v17; // rdi
  hkStringPtr *v18; // rbx
  __int64 v19; // rdi
  __int64 i; // rsi
  int m_size; // edi
  __int16 v22; // bx
  const char *v23; // r14
  char *v24; // rdi
  int v25; // ebx
  hkStringPtr *v26; // rdi
  signed int v27; // ebx
  hkLifoAllocator *v28; // rax
  int v29; // r8d
  int v30; // ebx
  hkStringPtr *v31; // rdi
  hkStringPtr *array; // [rsp+30h] [rbp-20h] BYREF
  int v33; // [rsp+38h] [rbp-18h]
  int v34; // [rsp+3Ch] [rbp-14h]
  void *p; // [rsp+40h] [rbp-10h]
  int v36; // [rsp+48h] [rbp-8h]
  hkResult result; // [rsp+88h] [rbp+38h] BYREF

  v4 = numPartitionNames;
  v6 = 0;
  array = 0i64;
  v34 = 0x80000000;
  v36 = numPartitionNames;
  v33 = 0;
  if ( numPartitionNames )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkStringPtr *)Value->m_cur;
    v11 = (8 * v4 + 127) & 0xFFFFFF80;
    v12 = (char *)m_cur + v11;
    if ( v11 > Value->m_slabSize || v12 > Value->m_end )
    {
      m_cur = (hkStringPtr *)hkLifoAllocator::allocateFromNewSlab(Value, v11);
      array = m_cur;
      v6 = v33;
    }
    else
    {
      Value->m_cur = v12;
      v6 = v33;
      array = m_cur;
    }
  }
  else
  {
    m_cur = 0i64;
    array = 0i64;
  }
  p = m_cur;
  v34 = v4 | 0x80000000;
  v13 = v4 & 0x3FFFFFFF;
  if ( (v4 & 0x3FFFFFFF) < (int)v4 )
  {
    v14 = v4;
    if ( (int)v4 < 2 * v13 )
      v14 = 2 * v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array, v14, 8);
    v6 = v33;
    m_cur = array;
  }
  v15 = v4;
  v16 = v6 - v4 - 1;
  if ( v16 >= 0 )
  {
    v17 = &m_cur[v4 + v16];
    do
    {
      hkStringPtr::~hkStringPtr(v17--);
      --v16;
    }
    while ( v16 >= 0 );
    v6 = v33;
    m_cur = array;
  }
  v18 = &m_cur[v6];
  if ( (int)v4 - v6 > 0 )
  {
    v19 = (unsigned int)(v4 - v6);
    do
    {
      if ( v18 )
        hkStringPtr::hkStringPtr(v18);
      ++v18;
      --v19;
    }
    while ( v19 );
    m_cur = array;
  }
  v33 = v4;
  hkaPartitionedAnimationUtility::sortPartitionNames(partitionNames, v4, skeleton, m_cur);
  for ( i = 0i64; i < v15; ++i )
  {
    m_size = skeleton->m_partitions.m_size;
    v22 = 0;
    v23 = (const char *)((unsigned __int64)array[i].m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( m_size <= 0 )
    {
LABEL_25:
      v22 = -1;
    }
    else
    {
      while ( hkString::strCmp(
                v23,
                (const char *)((unsigned __int64)skeleton->m_partitions.m_data[v22].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
      {
        if ( ++v22 >= m_size )
          goto LABEL_25;
      }
    }
    partitionIndicesOut[i] = v22;
  }
  v24 = (char *)p;
  if ( p == array )
  {
    v25 = v33 - 1;
    if ( v33 - 1 >= 0 )
    {
      v26 = &array[v25];
      do
      {
        hkStringPtr::~hkStringPtr(v26--);
        --v25;
      }
      while ( v25 >= 0 );
      v24 = (char *)p;
    }
    v33 = 0;
  }
  v27 = (8 * v36 + 127) & 0xFFFFFF80;
  v28 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (v27 + 15) & 0xFFFFFFF0;
  if ( v27 > v28->m_slabSize || &v24[v29] != v28->m_cur || v28->m_firstNonLifoEnd == v24 )
    hkLifoAllocator::slowBlockFree(v28, v24, v29);
  else
    v28->m_cur = v24;
  v30 = v33 - 1;
  if ( v33 - 1 >= 0 )
  {
    v31 = &array[v30];
    do
    {
      hkStringPtr::~hkStringPtr(v31--);
      --v30;
    }
    while ( v30 >= 0 );
  }
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v34);
}
    while ( v30 >= 0 );
  }
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContain

// File Line: 129
// RVA: 0xB3E990
void __fastcall hkaPartitionedAnimationUtility::setPartitionPoseToReference(
        hkaSkeleton *skeleton,
        const __int16 *partitionIndices,
        int numPartitionIndices,
        hkQsTransformf *transformsOut)
{
  int v4; // esi
  __int64 v7; // rbp
  __int64 i; // rbx
  hkaSkeleton::Partition *v9; // rdi
  int v10; // ecx
  hkQsTransformf *v11; // r10
  hkQsTransformf *v12; // rax
  __int64 v13; // r11
  int v14; // r8d
  int v15; // r9d
  int v16; // ecx

  if ( numPartitionIndices > 0 )
  {
    v4 = 0;
    v7 = numPartitionIndices;
    for ( i = 0i64; i < v7; ++i )
    {
      v9 = &skeleton->m_partitions.m_data[partitionIndices[i]];
      v10 = 3 * v9->m_numBones;
      v11 = &skeleton->m_referencePose.m_data[v9->m_startBoneIndex];
      v12 = &transformsOut[v4];
      if ( v10 > 0 )
      {
        v13 = (unsigned int)v10;
        do
        {
          v14 = v11->m_translation.m_quad.m128_i32[2];
          v15 = v11->m_translation.m_quad.m128_i32[3];
          v16 = v11->m_translation.m_quad.m128_i32[0];
          v12->m_translation.m_quad.m128_i32[1] = v11->m_translation.m_quad.m128_i32[1];
          v12->m_translation.m_quad.m128_i32[2] = v14;
          v12->m_translation.m_quad.m128_i32[3] = v15;
          v12->m_translation.m_quad.m128_i32[0] = v16;
          v12 = (hkQsTransformf *)((char *)v12 + 16);
          v11 = (hkQsTransformf *)((char *)v11 + 16);
          --v13;
        }
        while ( v13 );
      }
      v4 += v9->m_numBones;
    }
  }
}

// File Line: 141
// RVA: 0xB3EA60
__int16 __fastcall hkaPartitionedAnimationUtility::getNumberOfBonesInPartitions(
        hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *partitions)
{
  __int64 m_size; // rdx
  __int16 result; // ax
  __int16 *p_m_numBones; // rcx

  m_size = partitions->m_size;
  result = 0;
  if ( (int)m_size > 0 )
  {
    p_m_numBones = &partitions->m_data->m_numBones;
    do
    {
      result += *p_m_numBones;
      p_m_numBones += 8;
      --m_size;
    }
    while ( m_size );
  }
  return result;
}

// File Line: 152
// RVA: 0xB3EA90
__int16 __fastcall hkaPartitionedAnimationUtility::getNumMappedPartitionBones(
        const __int16 *aToBPartitionMap,
        const __int16 *partitionIndicesSkeletonA,
        int numPartitionIndicesSkeletonA,
        hkaSkeleton *skelB)
{
  __int16 result; // ax
  __int64 i; // r10
  __int64 v7; // rdx

  result = 0;
  for ( i = 0i64; i < numPartitionIndicesSkeletonA; result += skelB->m_partitions.m_data[aToBPartitionMap[v7]].m_numBones )
    v7 = partitionIndicesSkeletonA[i++];
  return result;
}

// File Line: 168
// RVA: 0xB3EAF0
void __fastcall hkaPartitionedAnimationUtility::getMappedPartitionIndices(
        const __int16 *aToBPartitionMap,
        char *partitionIndicesSkeletonA,
        int numPartitionIndicesSkeletonA,
        hkaSkeleton *skelB,
        __int16 *partitionIndicesBOut)
{
  __int64 v5; // r9
  __int16 *v6; // rax
  signed __int64 v7; // r10
  __int64 v8; // rdx

  v5 = numPartitionIndicesSkeletonA;
  if ( numPartitionIndicesSkeletonA > 0 )
  {
    v6 = partitionIndicesBOut;
    v7 = partitionIndicesSkeletonA - (char *)partitionIndicesBOut;
    do
    {
      v8 = *(__int16 *)((char *)v6++ + v7);
      *(v6 - 1) = aToBPartitionMap[v8];
      --v5;
    }
    while ( v5 );
  }
  hkAlgorithm::insertionSort<short>(partitionIndicesBOut, numPartitionIndicesSkeletonA);
}

// File Line: 185
// RVA: 0xB3EB40
void __fastcall hkaPartitionedAnimationUtility::getPartitionsFromIndices(
        hkaSkeleton *skeleton,
        hkArray<short,hkContainerHeapAllocator> *partitionIndices,
        hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *partitionsOut)
{
  int v3; // ebp
  __int64 v7; // r14
  hkaSkeleton::Partition *v8; // rsi
  hkaSkeleton::Partition *v9; // rdi

  v3 = 0;
  if ( partitionIndices->m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = &skeleton->m_partitions.m_data[partitionIndices->m_data[v7]];
      if ( partitionsOut->m_size == (partitionsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, partitionsOut, 16);
      v9 = &partitionsOut->m_data[partitionsOut->m_size];
      if ( v9 )
      {
        hkStringPtr::hkStringPtr(&v9->m_name, &v8->m_name);
        v9->m_startBoneIndex = v8->m_startBoneIndex;
        v9->m_numBones = v8->m_numBones;
      }
      ++partitionsOut->m_size;
      ++v3;
      ++v7;
    }
    while ( v3 < partitionIndices->m_size );
  }
}

// File Line: 194
// RVA: 0xB3EC10
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPose(
        hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *partitions,
        hkArray<short,hkContainerHeapAllocator> *partitionIndices,
        hkQsTransformf *transformsIn,
        int numTransformsIn,
        hkQsTransformf *transformsOut)
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
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPose(
        hkaSkeleton::Partition *partitions,
        const __int16 *partitionIndices,
        int numPartitionIndices,
        hkQsTransformf *transformsIn,
        int numTransformsIn,
        hkQsTransformf *transformsOut)
{
  int v6; // esi
  __int64 v8; // rbx
  __int64 v10; // rbp
  __int64 v11; // rdi
  int v12; // ecx
  hkQsTransformf *v13; // r10
  hkQsTransformf *v14; // rax
  __int64 v15; // r11
  int v16; // r8d
  int v17; // r9d
  int v18; // ecx

  if ( numPartitionIndices > 0 )
  {
    v6 = 0;
    v8 = 0i64;
    v10 = numPartitionIndices;
    do
    {
      v11 = partitionIndices[v8];
      v12 = 3 * partitions[partitionIndices[v8]].m_numBones;
      v13 = &transformsIn[v6];
      v14 = &transformsOut[partitions[partitionIndices[v8]].m_startBoneIndex];
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
      ++v8;
      v6 += partitions[v11].m_numBones;
    }
    while ( v8 < v10 );
  }
}

// File Line: 216
// RVA: 0xB3ED20
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPose(
        hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *animPartitions,
        hkQsTransformf *transformsIn,
        int numTransformsIn,
        hkQsTransformf *transformsOut)
{
  int v4; // edi
  int v6; // ebx
  __int64 v8; // rsi
  hkaSkeleton::Partition *m_data; // rbp
  int v10; // ecx
  hkQsTransformf *v11; // r10
  hkQsTransformf *v12; // rax
  __int64 v13; // r11
  int v14; // r8d
  int v15; // r9d
  int v16; // ecx
  int m_numBones; // eax

  v4 = 0;
  v6 = 0;
  if ( animPartitions->m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = animPartitions->m_data;
      v10 = 3 * animPartitions->m_data[v8].m_numBones;
      v11 = &transformsIn[v4];
      v12 = &transformsOut[animPartitions->m_data[v8].m_startBoneIndex];
      if ( v10 > 0 )
      {
        v13 = (unsigned int)v10;
        do
        {
          v14 = v11->m_translation.m_quad.m128_i32[2];
          v15 = v11->m_translation.m_quad.m128_i32[3];
          v16 = v11->m_translation.m_quad.m128_i32[0];
          v12->m_translation.m_quad.m128_i32[1] = v11->m_translation.m_quad.m128_i32[1];
          v12->m_translation.m_quad.m128_i32[2] = v14;
          v12->m_translation.m_quad.m128_i32[3] = v15;
          v12->m_translation.m_quad.m128_i32[0] = v16;
          v12 = (hkQsTransformf *)((char *)v12 + 16);
          v11 = (hkQsTransformf *)((char *)v11 + 16);
          --v13;
        }
        while ( v13 );
      }
      m_numBones = m_data[v8].m_numBones;
      ++v6;
      ++v8;
      v4 += m_numBones;
    }
    while ( v6 < animPartitions->m_size );
  }
}

// File Line: 232
// RVA: 0xB3EE00
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(
        hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *partitions,
        hkArray<short,hkContainerHeapAllocator> *partitionIndices,
        hkQsTransformf *transformsIn,
        const char *weightsIn,
        int numTransformsIn,
        hkQsTransformf *transformsOut,
        char *weightsOut)
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
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(
        hkaSkeleton::Partition *partitions,
        const __int16 *partitionIndices,
        int numPartitionIndices,
        hkQsTransformf *transformsIn,
        const char *weightsIn,
        int numTransformsIn,
        hkQsTransformf *transformsOut,
        char *weightsOut)
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
  int v17; // r8d
  int v18; // r9d
  int v19; // ecx
  hkaSkeleton::Partition *v20; // [rsp+60h] [rbp+8h]
  hkQsTransformf *v22; // [rsp+78h] [rbp+20h]

  if ( numPartitionIndices > 0 )
  {
    v22 = transformsIn;
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
      v9 = partitionIndices;
      ++v10;
    }
    while ( v10 < v11 );
  }
}

// File Line: 256
// RVA: 0xB3EF80
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(
        hkaSkeleton::Partition *partitions,
        const __int16 *partitionIndices,
        int numPartitionIndices,
        hkQsTransformf *transformsIn,
        const float *weightsIn,
        int numTransformsIn,
        hkQsTransformf *transformsOut,
        float *weightsOut)
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
  int v17; // r8d
  int v18; // r9d
  int v19; // ecx
  __int64 v20; // r8
  const float *v21; // rcx
  float *v22; // rdx
  int v23; // eax
  hkaSkeleton::Partition *v24; // [rsp+40h] [rbp+8h]
  hkQsTransformf *v26; // [rsp+58h] [rbp+20h]

  if ( numPartitionIndices > 0 )
  {
    v26 = transformsIn;
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
      if ( (int)v20 > 0 )
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
      v9 = partitionIndices;
    }
    while ( v10 < v11 );
  }
}

// File Line: 274
// RVA: 0xB3F0C0
void __fastcall hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(
        hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *animPartitions,
        hkQsTransformf *transformsIn,
        const char *weightsIn,
        int numTransformsIn,
        hkQsTransformf *transformsOut,
        char *weightsOut)
{
  int v6; // edi
  int v9; // esi
  __int64 v10; // r14
  hkaSkeleton::Partition *v11; // rbx
  int v12; // ecx
  hkQsTransformf *v13; // r10
  hkQsTransformf *v14; // rax
  __int64 v15; // r11
  int v16; // r8d
  int v17; // r9d
  int v18; // ecx
  hkQsTransformf *v19; // [rsp+58h] [rbp+10h]

  v19 = transformsIn;
  v6 = 0;
  v9 = 0;
  if ( animPartitions->m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = &animPartitions->m_data[v10];
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
      hkString::memCpy(&weightsOut[v11->m_startBoneIndex], &weightsIn[v6], v11->m_numBones);
      transformsIn = v19;
      ++v9;
      v6 += v11->m_numBones;
      ++v10;
    }
    while ( v9 < animPartitions->m_size );
  }
}

// File Line: 291
// RVA: 0xB3F1C0
char __fastcall hkaPartitionedAnimationUtility::hasValidPartitions(hkaAnimationBinding *binding, hkaSkeleton *skeleton)
{
  __int64 m_size; // r8
  int v3; // r9d
  __int64 v4; // rdx
  __int16 *i; // rcx

  m_size = binding->m_partitionIndices.m_size;
  v3 = skeleton->m_partitions.m_size;
  v4 = 0i64;
  if ( m_size <= 0 )
    return 1;
  for ( i = binding->m_partitionIndices.m_data; *i >= 0 && *i < v3; ++i )
  {
    if ( ++v4 >= m_size )
      return 1;
  }
  return 0;
}

