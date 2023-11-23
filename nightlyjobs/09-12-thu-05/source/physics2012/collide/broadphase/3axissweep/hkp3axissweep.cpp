// File Line: 64
// RVA: 0xD06BD0
void __fastcall memclear16(char *dest, int bytesize)
{
  int i; // edx
  _OWORD *v3; // rax

  for ( i = bytesize >> 4; i >= 0; *v3 = 0i64 )
  {
    v3 = dest;
    dest += 16;
    --i;
  }
}

// File Line: 89
// RVA: 0xCFCB50
__int64 __fastcall hkp3AxisSweep::getType(hkp3AxisSweep *this)
{
  return 0i64;
}

// File Line: 98
// RVA: 0xD06C00
void __fastcall staticFlipBit(unsigned int *bitField, int index)
{
  bitField[index >> 5] ^= 1 << (index & 0x1F);
}

// File Line: 105
// RVA: 0xD06C30
void __fastcall staticClearBit(unsigned int *bitField, int index)
{
  bitField[index >> 5] &= ~(1 << (index & 0x1F));
}

// File Line: 112
// RVA: 0xD06C60
__int64 __fastcall staticIsBitSet(const unsigned int *bitField, int index)
{
  return bitField[(__int64)index >> 5] & (1 << (index & 0x1F));
}

// File Line: 273
// RVA: 0xD05AE0
void __fastcall hkp3AxisSweep::beginOverlap(
        hkp3AxisSweep::hkpBpNode *a,
        hkp3AxisSweep::hkpBpNode *b,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairsOut)
{
  hkpBroadPhaseHandlePair *v6; // rcx

  if ( newPairsOut->m_size == (newPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&newPairsOut->m_data, 16);
  v6 = &newPairsOut->m_data[newPairsOut->m_size++];
  v6->m_a = a->m_handle;
  v6->m_b = b->m_handle;
}

// File Line: 280
// RVA: 0xD05B60
void __fastcall hkp3AxisSweep::endOverlap(
        hkp3AxisSweep::hkpBpNode *a,
        hkp3AxisSweep::hkpBpNode *b,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *deletedPairsOut)
{
  hkpBroadPhaseHandlePair *v6; // rcx

  if ( deletedPairsOut->m_size == (deletedPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&deletedPairsOut->m_data, 16);
  v6 = &deletedPairsOut->m_data[deletedPairsOut->m_size++];
  v6->m_a = a->m_handle;
  v6->m_b = b->m_handle;
}

// File Line: 287
// RVA: 0xD05920
void __fastcall hkp3AxisSweep::beginOverlapCheckMarker(
        hkp3AxisSweep::hkpBpMarker *markers,
        hkp3AxisSweep::hkpBpNode *a,
        __int16 nodeIndexA,
        hkp3AxisSweep::hkpBpNode *b,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairsOut)
{
  hkpBroadPhaseHandlePair *v8; // rcx
  const void **v9; // rbx

  if ( ((__int64)b->m_handle & 1) != 0 )
  {
    v9 = (const void **)((char *)markers + ((unsigned __int64)b->m_handle & 0xFFFFFFFFFFFFFFFEui64));
    if ( *((_DWORD *)v9 + 4) == (*((_DWORD *)v9 + 5) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v9 + 1, 2);
    *((_WORD *)v9[1] + (int)(*((_DWORD *)v9 + 4))++) = nodeIndexA;
  }
  else
  {
    if ( newPairsOut->m_size == (newPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&newPairsOut->m_data, 16);
    v8 = &newPairsOut->m_data[newPairsOut->m_size++];
    v8->m_a = a->m_handle;
    v8->m_b = b->m_handle;
  }
}

// File Line: 302
// RVA: 0xD059F0
void __fastcall hkp3AxisSweep::endOverlapCheckMarker(
        hkp3AxisSweep::hkpBpMarker *markers,
        hkp3AxisSweep::hkpBpNode *a,
        __int16 nodeIndexA,
        hkp3AxisSweep::hkpBpNode *b,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *deletedPairsOut)
{
  hkpBroadPhaseHandlePair *v8; // rcx
  int v9; // r8d
  char *v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // r11
  _WORD *v13; // rax

  if ( ((__int64)b->m_handle & 1) != 0 )
  {
    v9 = 0;
    v10 = (char *)markers + ((unsigned __int64)b->m_handle & 0xFFFFFFFFFFFFFFFEui64);
    v11 = 0i64;
    v12 = *((int *)v10 + 4);
    if ( (int)v12 <= 0 )
    {
LABEL_9:
      v9 = -1;
    }
    else
    {
      v13 = (_WORD *)*((_QWORD *)v10 + 1);
      while ( *v13 != nodeIndexA )
      {
        ++v11;
        ++v9;
        ++v13;
        if ( v11 >= v12 )
          goto LABEL_9;
      }
    }
    *((_DWORD *)v10 + 4) = v12 - 1;
    if ( (_DWORD)v12 - 1 != v9 )
      *(_WORD *)(*((_QWORD *)v10 + 1) + 2i64 * v9) = *(_WORD *)(*((_QWORD *)v10 + 1) + 2i64 * ((int)v12 - 1));
  }
  else
  {
    if ( deletedPairsOut->m_size == (deletedPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&deletedPairsOut->m_data, 16);
    v8 = &deletedPairsOut->m_data[deletedPairsOut->m_size++];
    v8->m_a = a->m_handle;
    v8->m_b = b->m_handle;
  }
}

// File Line: 646
// RVA: 0xD05BE0
void __fastcall hkp3AxisSweep::_fixDeterministicOrderAfterNodeIdWasDecreased(
        hkp3AxisSweep *this,
        unsigned int nodeIndex)
{
  hkp3AxisSweep::hkpBpNode *m_data; // r11
  __int64 min_x; // r10
  hkp3AxisSweep::hkpBpNode *v5; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v6; // r9
  hkp3AxisSweep::hkpBpEndPoint *v7; // r8
  __int64 m_nodeIndex; // rcx
  unsigned __int16 m_value; // ax
  __int64 max_x; // r10
  hkp3AxisSweep::hkpBpEndPoint *v11; // r8
  hkp3AxisSweep::hkpBpEndPoint *v12; // r9
  __int64 v13; // rcx
  unsigned __int16 v14; // ax
  __int64 min_y; // r10
  hkp3AxisSweep::hkpBpEndPoint *v16; // r8
  hkp3AxisSweep::hkpBpEndPoint *v17; // r9
  __int64 v18; // rcx
  unsigned __int16 v19; // ax
  __int64 max_y; // r10
  hkp3AxisSweep::hkpBpEndPoint *v21; // r8
  hkp3AxisSweep::hkpBpEndPoint *v22; // r9
  __int64 v23; // rcx
  unsigned __int16 v24; // ax
  __int64 min_z; // r10
  hkp3AxisSweep::hkpBpEndPoint *v26; // r8
  hkp3AxisSweep::hkpBpEndPoint *v27; // r9
  __int64 v28; // rcx
  unsigned __int16 v29; // ax
  __int64 max_z; // r9
  hkp3AxisSweep::hkpBpEndPoint *v31; // r8
  hkp3AxisSweep::hkpBpEndPoint *v32; // r10
  __int64 v33; // rcx
  unsigned __int16 v34; // ax

  m_data = this->m_nodes.m_data;
  min_x = m_data[nodeIndex].min_x;
  v5 = &m_data[nodeIndex];
  v6 = &this->m_axis[0].m_endPoints.m_data[min_x];
  v7 = v6 - 1;
  if ( v6->m_value == v6[-1].m_value )
  {
    do
    {
      m_nodeIndex = v6[-1].m_nodeIndex;
      if ( nodeIndex >= (unsigned int)m_nodeIndex )
        break;
      *v6 = *v7;
      m_data[m_nodeIndex].min_x = min_x;
      m_value = v7[-1].m_value;
      v6 = v7--;
      LOWORD(min_x) = min_x - 1;
    }
    while ( v6->m_value == m_value );
  }
  v6->m_nodeIndex = nodeIndex;
  v5->min_x = min_x;
  max_x = v5->max_x;
  v11 = &this->m_axis[0].m_endPoints.m_data[max_x];
  v12 = v11 - 1;
  if ( v11->m_value == v11[-1].m_value )
  {
    do
    {
      v13 = v11[-1].m_nodeIndex;
      if ( nodeIndex >= (unsigned int)v13 )
        break;
      *v11 = *v12;
      m_data[v13].max_x = max_x;
      v14 = v12[-1].m_value;
      v11 = v12--;
      LOWORD(max_x) = max_x - 1;
    }
    while ( v11->m_value == v14 );
  }
  v11->m_nodeIndex = nodeIndex;
  v5->max_x = max_x;
  min_y = v5->min_y;
  v16 = &this->m_axis[1].m_endPoints.m_data[min_y];
  v17 = v16 - 1;
  if ( v16->m_value == v16[-1].m_value )
  {
    do
    {
      v18 = v16[-1].m_nodeIndex;
      if ( nodeIndex >= (unsigned int)v18 )
        break;
      *v16 = *v17;
      m_data[v18].min_y = min_y;
      v19 = v17[-1].m_value;
      v16 = v17--;
      LOWORD(min_y) = min_y - 1;
    }
    while ( v16->m_value == v19 );
  }
  v16->m_nodeIndex = nodeIndex;
  v5->min_y = min_y;
  max_y = v5->max_y;
  v21 = &this->m_axis[1].m_endPoints.m_data[max_y];
  v22 = v21 - 1;
  if ( v21->m_value == v21[-1].m_value )
  {
    do
    {
      v23 = v21[-1].m_nodeIndex;
      if ( nodeIndex >= (unsigned int)v23 )
        break;
      *v21 = *v22;
      m_data[v23].max_y = max_y;
      v24 = v22[-1].m_value;
      v21 = v22--;
      LOWORD(max_y) = max_y - 1;
    }
    while ( v21->m_value == v24 );
  }
  v21->m_nodeIndex = nodeIndex;
  v5->max_y = max_y;
  min_z = v5->min_z;
  v26 = &this->m_axis[2].m_endPoints.m_data[min_z];
  v27 = v26 - 1;
  if ( v26->m_value == v26[-1].m_value )
  {
    do
    {
      v28 = v26[-1].m_nodeIndex;
      if ( nodeIndex >= (unsigned int)v28 )
        break;
      *v26 = *v27;
      m_data[v28].min_z = min_z;
      v29 = v27[-1].m_value;
      v26 = v27--;
      LOWORD(min_z) = min_z - 1;
    }
    while ( v26->m_value == v29 );
  }
  v26->m_nodeIndex = nodeIndex;
  v5->min_z = min_z;
  max_z = v5->max_z;
  v31 = &this->m_axis[2].m_endPoints.m_data[max_z];
  v32 = v31 - 1;
  if ( v31->m_value == v31[-1].m_value )
  {
    do
    {
      v33 = v31[-1].m_nodeIndex;
      if ( nodeIndex >= (unsigned int)v33 )
        break;
      *v31 = *v32;
      m_data[v33].max_z = max_z;
      v34 = v32[-1].m_value;
      v31 = v32--;
      LOWORD(max_z) = max_z - 1;
    }
    while ( v31->m_value == v34 );
  }
  v31->m_nodeIndex = nodeIndex;
  v5->max_z = max_z;
}

// File Line: 683
// RVA: 0xCFF180
void __fastcall hkp3AxisSweep::updateAabbs(
        hkp3AxisSweep *this,
        hkpBroadPhaseHandle **objects,
        hkAabb *aabbs,
        int numObjects,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairsOut,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairsOut)
{
  hkp3AxisSweep *v6; // r12
  hkp3AxisSweep *v7; // r10
  hkp3AxisSweep::hkpBpNode *m_data; // rdi
  __m128 v9; // xmm0
  __m128i v10; // xmm1
  __m128 v11; // xmm0
  unsigned int v12; // r12d
  __m128 v13; // xmm0
  __m128i v14; // xmm6
  unsigned int v15; // r15d
  __int64 m_id; // r14
  unsigned int v17; // r13d
  __int64 min_x; // rbp
  hkp3AxisSweep::hkpBpNode *v19; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v20; // rsi
  unsigned int m_value; // r9d
  hkp3AxisSweep::hkpBpEndPoint *v22; // r8
  __int64 m_nodeIndex; // rcx
  hkp3AxisSweep::hkpBpNode *v24; // rdx
  int v25; // ecx
  int v26; // eax
  hkp3AxisSweep::hkpBpEndPoint *v27; // rcx
  __int64 v28; // rdx
  int v29; // eax
  __int64 max_x; // rbp
  __int64 v31; // rsi
  unsigned int v32; // r8d
  __int64 v33; // rcx
  hkp3AxisSweep::hkpBpNode *v34; // rdx
  int v35; // ecx
  int v36; // eax
  __int64 v37; // rdx
  __int64 v38; // rcx
  int v39; // eax
  unsigned int v40; // r9d
  _DWORD *v41; // r8
  __int64 v42; // rax
  hkp3AxisSweep::hkpBpNode *v43; // rdx
  int v44; // ecx
  int v45; // eax
  _DWORD *v46; // rcx
  __int64 v47; // rdx
  int v48; // eax
  __int64 v49; // rbp
  __int64 v50; // rsi
  unsigned int v51; // r9d
  _DWORD *v52; // r8
  __int64 v53; // rcx
  hkp3AxisSweep::hkpBpNode *v54; // rdx
  int v55; // ecx
  int v56; // eax
  __int64 v57; // rcx
  __int64 v58; // rdx
  int v59; // eax
  unsigned int v60; // r15d
  __int64 min_y; // rbp
  hkp3AxisSweep::hkpBpEndPoint *v62; // rsi
  unsigned int v63; // r9d
  hkp3AxisSweep::hkpBpEndPoint *v64; // r8
  __int64 v65; // rcx
  hkp3AxisSweep::hkpBpNode *v66; // rdx
  unsigned __int16 v67; // cx
  unsigned __int16 v68; // ax
  hkp3AxisSweep::hkpBpEndPoint *v69; // rcx
  __int64 v70; // rdx
  int v71; // eax
  __int64 max_y; // rbp
  hkp3AxisSweep::hkpBpEndPoint *v73; // rsi
  unsigned int v74; // r8d
  hkp3AxisSweep::hkpBpEndPoint *v75; // rcx
  hkp3AxisSweep::hkpBpNode *v76; // rdx
  unsigned __int16 v77; // cx
  unsigned __int16 v78; // ax
  hkp3AxisSweep::hkpBpEndPoint *v79; // rdx
  __int64 v80; // rcx
  int v81; // eax
  unsigned int v82; // r9d
  hkp3AxisSweep::hkpBpEndPoint *v83; // r8
  __int64 v84; // rax
  hkp3AxisSweep::hkpBpNode *v85; // rdx
  unsigned __int16 v86; // cx
  unsigned __int16 v87; // ax
  hkp3AxisSweep::hkpBpEndPoint *v88; // rcx
  __int64 v89; // rdx
  int v90; // eax
  __int64 v91; // rbp
  __int64 v92; // rsi
  unsigned int v93; // r9d
  _DWORD *v94; // r8
  __int64 v95; // rcx
  hkp3AxisSweep::hkpBpNode *v96; // rdx
  __int16 v97; // cx
  __int16 v98; // ax
  __int64 v99; // rcx
  __int64 v100; // rdx
  int v101; // eax
  __int64 min_z; // rbp
  __int64 v103; // rsi
  unsigned int v104; // r9d
  _DWORD *v105; // r8
  __int64 v106; // rcx
  hkp3AxisSweep::hkpBpNode *v107; // rdx
  unsigned __int16 v108; // cx
  unsigned __int16 v109; // ax
  _DWORD *v110; // rcx
  __int64 v111; // rdx
  int v112; // eax
  __int16 v113; // r15
  __int64 max_z; // rbp
  __int64 v115; // rsi
  unsigned int v116; // r8d
  __int64 v117; // rcx
  hkp3AxisSweep::hkpBpNode *v118; // rdx
  unsigned __int16 v119; // cx
  unsigned __int16 v120; // ax
  __int64 v121; // rdx
  __int64 v122; // rcx
  int v123; // eax
  unsigned int v124; // r9d
  _DWORD *v125; // r8
  __int64 v126; // rax
  hkp3AxisSweep::hkpBpNode *v127; // rdx
  unsigned __int16 v128; // cx
  unsigned __int16 v129; // ax
  _DWORD *v130; // rcx
  __int64 v131; // rdx
  int v132; // eax
  __int64 v133; // rbp
  __int64 v134; // rsi
  unsigned int v135; // r9d
  _DWORD *v136; // r8
  __int64 v137; // rcx
  hkp3AxisSweep::hkpBpNode *v138; // rdx
  unsigned __int16 v139; // cx
  unsigned __int16 v140; // ax
  __int64 v141; // rcx
  __int64 v142; // rdx
  int v143; // eax
  unsigned int v144; // [rsp+30h] [rbp-108h]
  unsigned int v145; // [rsp+50h] [rbp-E8h]
  unsigned __int16 v146; // [rsp+60h] [rbp-D8h]
  unsigned __int16 v147; // [rsp+64h] [rbp-D4h]
  unsigned __int64 v148; // [rsp+80h] [rbp-B8h]
  unsigned __int64 v149; // [rsp+90h] [rbp-A8h]
  unsigned int v150; // [rsp+B0h] [rbp-88h]
  hkpBroadPhaseHandle **v151; // [rsp+B8h] [rbp-80h]
  hkpBroadPhaseHandle **i; // [rsp+C0h] [rbp-78h]
  unsigned int v154; // [rsp+148h] [rbp+10h]
  hkAabb *v155; // [rsp+150h] [rbp+18h]

  v155 = aabbs;
  v151 = objects;
  v6 = this;
  for ( i = &objects[numObjects]; objects < i; v151 = objects )
  {
    v7 = this;
    m_data = this->m_nodes.m_data;
    v9 = _mm_max_ps(
           _mm_min_ps(
             _mm_mul_ps(_mm_add_ps(aabbs->m_min.m_quad, v6->m_offsetLow.m_quad), v6->m_scale.m_quad),
             hkp3AxisSweep::MaxVal),
           (__m128)0i64);
    v10 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v9),
              _mm_cvttps_epi32(v9)),
            (__m128i)_xmm);
    v11 = _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(aabbs->m_max.m_quad, v6->m_offsetHigh.m_quad), v6->m_scale.m_quad),
            hkp3AxisSweep::MaxVal);
    v148 = _mm_add_epi16(_mm_packs_epi32(v10, v10), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
    v12 = v148 & 0xFFFE;
    v13 = _mm_max_ps(v11, (__m128)0i64);
    v154 = WORD1(v148) & 0xFFFE;
    v147 = WORD1(v148) & 0xFFFE;
    v145 = WORD2(v148) & 0xFFFE;
    v14 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v13),
              _mm_cvttps_epi32(v13)),
            (__m128i)_xmm);
    v146 = v148 & 0xFFFE;
    v149 = _mm_add_epi16(_mm_packs_epi32(v14, v14), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
    v15 = (unsigned __int16)v149 | 1;
    m_id = (*objects)->m_id;
    v17 = WORD1(v149) | 1;
    min_x = m_data[m_id].min_x;
    v19 = &m_data[m_id];
    v20 = &this->m_axis[0].m_endPoints.m_data[min_x];
    v144 = (*objects)->m_id;
    m_value = v20[-1].m_value;
    v22 = v20 - 1;
    if ( v12 < m_value )
    {
      do
      {
        m_nodeIndex = v20[-1].m_nodeIndex;
        *v20 = *v22;
        v20 = v22;
        v24 = &m_data[m_nodeIndex];
        if ( (m_value & 1) != 0 )
        {
          v25 = *(_DWORD *)&v24->max_y - *(_DWORD *)&v19->min_y;
          v26 = *(_DWORD *)&v19->max_y - *(_DWORD *)&v24->min_y;
          v24->max_x = min_x;
          if ( ((v26 | v25) & 0x80008000) == 0 )
            hkp3AxisSweep::beginOverlapCheckMarker(this->m_markers, &m_data[m_id], m_id, v24, addedPairsOut);
        }
        else
        {
          v24->min_x = min_x;
        }
        m_value = v20[-1].m_value;
        v22 = v20 - 1;
        LOWORD(min_x) = min_x - 1;
      }
      while ( v12 < m_value );
      v15 = (unsigned __int16)v149 | 1;
      v17 = WORD1(v149) | 1;
      v7 = this;
    }
    v27 = v20 - 1;
    if ( v12 == v20[-1].m_value )
    {
      do
      {
        v28 = v20[-1].m_nodeIndex;
        if ( (unsigned int)m_id >= (unsigned int)v28 )
          break;
        *v20 = *v27;
        v20 = v27;
        m_data[v28].min_x = min_x;
        v29 = v27[-1].m_value;
        --v27;
        LOWORD(min_x) = min_x - 1;
      }
      while ( v12 == v29 );
    }
    v20->m_nodeIndex = m_id;
    v20->m_value = v146;
    v19->min_x = min_x;
    max_x = v19->max_x;
    v31 = (__int64)&v7->m_axis[0].m_endPoints.m_data[max_x];
    v32 = *(unsigned __int16 *)(v31 + 4);
    v33 = v31 + 4;
    if ( v15 > v32 )
    {
      do
      {
        LOWORD(max_x) = max_x + 1;
        *(_DWORD *)v31 = *(_DWORD *)v33;
        v31 = v33;
        v34 = &m_data[*(unsigned __int16 *)(v33 + 2)];
        if ( (v32 & 1) != 0 )
        {
          --v34->max_x;
        }
        else
        {
          v35 = *(_DWORD *)&v19->max_y - *(_DWORD *)&v34->min_y;
          v36 = *(_DWORD *)&v34->max_y - *(_DWORD *)&v19->min_y;
          --v34->min_x;
          if ( ((v36 | v35) & 0x80008000) == 0 )
            hkp3AxisSweep::beginOverlapCheckMarker(this->m_markers, &m_data[m_id], m_id, v34, addedPairsOut);
        }
        v32 = *(unsigned __int16 *)(v31 + 4);
        v33 = v31 + 4;
      }
      while ( v15 > v32 );
      v17 = WORD1(v149) | 1;
      v7 = this;
    }
    v37 = v31 + 4;
    if ( v15 == *(unsigned __int16 *)(v31 + 4) )
    {
      do
      {
        v38 = *(unsigned __int16 *)(v31 + 6);
        if ( (unsigned int)m_id <= (unsigned int)v38 )
          break;
        if ( !*(_WORD *)(v31 + 6) )
          break;
        LOWORD(max_x) = max_x + 1;
        *(_DWORD *)v31 = *(_DWORD *)v37;
        --m_data[v38].max_x;
        v39 = *(unsigned __int16 *)(v37 + 4);
        v31 = v37;
        v37 += 4i64;
      }
      while ( v15 == v39 );
    }
    v40 = *(unsigned __int16 *)(v31 - 4);
    v41 = (_DWORD *)(v31 - 4);
    if ( v15 < v40 )
    {
      do
      {
        LOWORD(max_x) = max_x - 1;
        *(_DWORD *)v31 = *v41;
        v42 = *(unsigned __int16 *)(v31 - 2);
        v31 = (__int64)v41;
        v43 = &m_data[v42];
        if ( (v40 & 1) != 0 )
        {
          ++v43->max_x;
        }
        else
        {
          v44 = *(_DWORD *)&v19->max_y - *(_DWORD *)&v43->min_y;
          v45 = *(_DWORD *)&v43->max_y - *(_DWORD *)&v19->min_y;
          ++v43->min_x;
          if ( ((v45 | v44) & 0x80008000) == 0 )
            hkp3AxisSweep::endOverlapCheckMarker(this->m_markers, &m_data[m_id], m_id, v43, removedPairsOut);
        }
        v40 = *(unsigned __int16 *)(v31 - 4);
        v41 = (_DWORD *)(v31 - 4);
      }
      while ( v15 < v40 );
      v17 = WORD1(v149) | 1;
      v7 = this;
    }
    v46 = (_DWORD *)(v31 - 4);
    if ( v15 == *(unsigned __int16 *)(v31 - 4) )
    {
      do
      {
        v47 = *(unsigned __int16 *)(v31 - 2);
        if ( (unsigned int)m_id >= (unsigned int)v47 )
          break;
        LOWORD(max_x) = max_x - 1;
        *(_DWORD *)v31 = *v46;
        v31 = (__int64)v46;
        ++m_data[v47].max_x;
        v48 = *((unsigned __int16 *)v46-- - 2);
      }
      while ( v15 == v48 );
    }
    v19->max_x = max_x;
    *(_WORD *)(v31 + 2) = m_id;
    *(_WORD *)v31 = v149 | 1;
    v49 = v19->min_x;
    v50 = (__int64)&v7->m_axis[0].m_endPoints.m_data[v49];
    v51 = *(unsigned __int16 *)(v50 + 4);
    v52 = (_DWORD *)(v50 + 4);
    if ( v12 > v51 )
    {
      do
      {
        LOWORD(v49) = v49 + 1;
        v53 = *(unsigned __int16 *)(v50 + 6);
        *(_DWORD *)v50 = *v52;
        v50 = (__int64)v52;
        v54 = &m_data[v53];
        if ( (v51 & 1) != 0 )
        {
          v55 = *(_DWORD *)&v19->max_y - *(_DWORD *)&v54->min_y;
          v56 = *(_DWORD *)&v54->max_y - *(_DWORD *)&v19->min_y;
          --v54->max_x;
          if ( ((v56 | v55) & 0x80008000) == 0 )
            hkp3AxisSweep::endOverlapCheckMarker(this->m_markers, &m_data[m_id], m_id, v54, removedPairsOut);
        }
        else
        {
          --v54->min_x;
        }
        v51 = *(unsigned __int16 *)(v50 + 4);
        v52 = (_DWORD *)(v50 + 4);
      }
      while ( v12 > v51 );
      v17 = WORD1(v149) | 1;
    }
    v57 = v50 + 4;
    if ( v12 == *(unsigned __int16 *)(v50 + 4) )
    {
      do
      {
        v58 = *(unsigned __int16 *)(v50 + 6);
        if ( (unsigned int)m_id <= (unsigned int)v58 )
          break;
        LOWORD(v49) = v49 + 1;
        *(_DWORD *)v50 = *(_DWORD *)v57;
        v50 = v57;
        --m_data[v58].min_x;
        v59 = *(unsigned __int16 *)(v57 + 4);
        v57 += 4i64;
      }
      while ( v12 == v59 );
    }
    v6 = this;
    v60 = WORD1(v148) & 0xFFFE;
    v19->min_x = v49;
    *(_WORD *)v50 = v146;
    *(_WORD *)(v50 + 2) = m_id;
    min_y = v19->min_y;
    v62 = &this->m_axis[1].m_endPoints.m_data[min_y];
    v63 = v62[-1].m_value;
    v64 = v62 - 1;
    if ( v154 < v63 )
    {
      do
      {
        v65 = v62[-1].m_nodeIndex;
        *v62 = *v64;
        v62 = v64;
        v66 = &m_data[v65];
        if ( (v63 & 1) != 0 )
        {
          v67 = (v19->max_x - v66->min_x) | (v19->max_z - v66->min_z) | (v66->max_z - v19->min_z);
          v68 = v66->max_x - v19->min_x;
          v66->max_y = min_y;
          if ( ((v68 | v67) & 0x8000) == 0 )
            hkp3AxisSweep::beginOverlap(v19, v66, addedPairsOut);
        }
        else
        {
          v66->min_y = min_y;
        }
        v63 = v62[-1].m_value;
        v64 = v62 - 1;
        LOWORD(min_y) = min_y - 1;
      }
      while ( v154 < v63 );
      LODWORD(m_id) = v144;
      v17 = WORD1(v149) | 1;
    }
    v69 = v62 - 1;
    if ( v154 == v62[-1].m_value )
    {
      do
      {
        v70 = v62[-1].m_nodeIndex;
        if ( (unsigned int)m_id >= (unsigned int)v70 )
          break;
        *v62 = *v69;
        v62 = v69;
        m_data[v70].min_y = min_y;
        v71 = v69[-1].m_value;
        --v69;
        LOWORD(min_y) = min_y - 1;
      }
      while ( v154 == v71 );
    }
    v62->m_nodeIndex = m_id;
    v62->m_value = v147;
    v19->min_y = min_y;
    max_y = v19->max_y;
    v73 = &this->m_axis[1].m_endPoints.m_data[max_y];
    v74 = v73[1].m_value;
    v75 = v73 + 1;
    if ( v17 > v74 )
    {
      do
      {
        LOWORD(max_y) = max_y + 1;
        *v73 = *v75;
        v73 = v75;
        v76 = &m_data[v75->m_nodeIndex];
        if ( (v74 & 1) != 0 )
        {
          --v76->max_y;
        }
        else
        {
          v77 = (v19->max_x - v76->min_x) | (v19->max_z - v76->min_z) | (v76->max_z - v19->min_z);
          v78 = v76->max_x - v19->min_x;
          --v76->min_y;
          if ( ((v78 | v77) & 0x8000) == 0 )
            hkp3AxisSweep::beginOverlap(v19, v76, addedPairsOut);
        }
        v74 = v73[1].m_value;
        v75 = v73 + 1;
      }
      while ( v17 > v74 );
      LODWORD(m_id) = v144;
      v60 = WORD1(v148) & 0xFFFE;
      v6 = this;
    }
    v79 = v73 + 1;
    if ( v17 == v73[1].m_value )
    {
      do
      {
        v80 = v73[1].m_nodeIndex;
        if ( (unsigned int)m_id <= (unsigned int)v80 )
          break;
        if ( !v73[1].m_nodeIndex )
          break;
        LOWORD(max_y) = max_y + 1;
        *v73 = *v79;
        --m_data[v80].max_y;
        v81 = v79[1].m_value;
        v73 = v79++;
      }
      while ( v17 == v81 );
      v60 = WORD1(v148) & 0xFFFE;
    }
    v82 = v73[-1].m_value;
    v83 = v73 - 1;
    if ( v17 < v82 )
    {
      do
      {
        LOWORD(max_y) = max_y - 1;
        *v73 = *v83;
        v84 = v73[-1].m_nodeIndex;
        v73 = v83;
        v85 = &m_data[v84];
        if ( (v82 & 1) != 0 )
        {
          ++v85->max_y;
        }
        else
        {
          v86 = (v19->max_x - v85->min_x) | (v19->max_z - v85->min_z) | (v85->max_z - v19->min_z);
          v87 = v85->max_x - v19->min_x;
          ++v85->min_y;
          if ( ((v87 | v86) & 0x8000) == 0 )
            hkp3AxisSweep::endOverlap(v19, v85, removedPairsOut);
        }
        v82 = v73[-1].m_value;
        v83 = v73 - 1;
      }
      while ( v17 < v82 );
      v60 = WORD1(v148) & 0xFFFE;
      v6 = this;
    }
    v88 = v73 - 1;
    if ( v17 == v73[-1].m_value )
    {
      do
      {
        v89 = v73[-1].m_nodeIndex;
        if ( (unsigned int)m_id >= (unsigned int)v89 )
          break;
        LOWORD(max_y) = max_y - 1;
        *v73 = *v88;
        v73 = v88;
        ++m_data[v89].max_y;
        v90 = v88[-1].m_value;
        --v88;
      }
      while ( v17 == v90 );
    }
    v19->max_y = max_y;
    v73->m_nodeIndex = m_id;
    v73->m_value = WORD1(v149) | 1;
    v91 = v19->min_y;
    v92 = (__int64)&v6->m_axis[1].m_endPoints.m_data[v91];
    v93 = *(unsigned __int16 *)(v92 + 4);
    v94 = (_DWORD *)(v92 + 4);
    if ( v60 > v93 )
    {
      do
      {
        LOWORD(v91) = v91 + 1;
        v95 = *(unsigned __int16 *)(v92 + 6);
        *(_DWORD *)v92 = *v94;
        v92 = (__int64)v94;
        v96 = &m_data[v95];
        if ( (v93 & 1) != 0 )
        {
          v97 = (v19->max_x - v96->min_x) | (v19->max_z - v96->min_z) | (v96->max_z - v19->min_z);
          v98 = v96->max_x - v19->min_x;
          --v96->max_y;
          if ( ((v98 | v97) & 0x8000u) == 0 )
            hkp3AxisSweep::endOverlap(v19, v96, removedPairsOut);
        }
        else
        {
          --v96->min_y;
        }
        v93 = *(unsigned __int16 *)(v92 + 4);
        v94 = (_DWORD *)(v92 + 4);
      }
      while ( v60 > v93 );
      LODWORD(m_id) = v144;
      v6 = this;
    }
    v99 = v92 + 4;
    if ( v60 == *(unsigned __int16 *)(v92 + 4) )
    {
      do
      {
        v100 = *(unsigned __int16 *)(v92 + 6);
        if ( (unsigned int)m_id <= (unsigned int)v100 )
          break;
        LOWORD(v91) = v91 + 1;
        *(_DWORD *)v92 = *(_DWORD *)v99;
        v92 = v99;
        --m_data[v100].min_y;
        v101 = *(unsigned __int16 *)(v99 + 4);
        v99 += 4i64;
      }
      while ( v60 == v101 );
      v6 = this;
    }
    v19->min_y = v91;
    *(_WORD *)v92 = v147;
    *(_WORD *)(v92 + 2) = m_id;
    min_z = v19->min_z;
    v103 = (__int64)&v6->m_axis[2].m_endPoints.m_data[min_z];
    v104 = *(unsigned __int16 *)(v103 - 4);
    v105 = (_DWORD *)(v103 - 4);
    if ( v145 < v104 )
    {
      do
      {
        v106 = *(unsigned __int16 *)(v103 - 2);
        *(_DWORD *)v103 = *v105;
        v103 = (__int64)v105;
        v107 = &m_data[v106];
        if ( (v104 & 1) != 0 )
        {
          v108 = (v107->max_x - v19->min_x) | (v107->max_y - v19->min_y) | (v19->max_x - v107->min_x);
          v109 = v19->max_y - v107->min_y;
          v107->max_z = min_z;
          if ( ((v109 | v108) & 0x8000) == 0 )
            hkp3AxisSweep::beginOverlap(v19, v107, addedPairsOut);
        }
        else
        {
          v107->min_z = min_z;
        }
        v104 = *(unsigned __int16 *)(v103 - 4);
        v105 = (_DWORD *)(v103 - 4);
        LOWORD(min_z) = min_z - 1;
      }
      while ( v145 < v104 );
      LODWORD(m_id) = v144;
      v6 = this;
    }
    v110 = (_DWORD *)(v103 - 4);
    if ( v145 == *(unsigned __int16 *)(v103 - 4) )
    {
      do
      {
        v111 = *(unsigned __int16 *)(v103 - 2);
        if ( (unsigned int)m_id >= (unsigned int)v111 )
          break;
        *(_DWORD *)v103 = *v110;
        v103 = (__int64)v110;
        m_data[v111].min_z = min_z;
        v112 = *((unsigned __int16 *)v110-- - 2);
        LOWORD(min_z) = min_z - 1;
      }
      while ( v145 == v112 );
    }
    v113 = WORD2(v148) & 0xFFFE;
    *(_WORD *)(v103 + 2) = m_id;
    *(_WORD *)v103 = WORD2(v148) & 0xFFFE;
    v19->min_z = min_z;
    max_z = v19->max_z;
    v115 = (__int64)&v6->m_axis[2].m_endPoints.m_data[max_z];
    v116 = *(unsigned __int16 *)(v115 + 4);
    v117 = v115 + 4;
    v150 = WORD2(v149) | 1;
    if ( v150 > v116 )
    {
      do
      {
        LOWORD(max_z) = max_z + 1;
        *(_DWORD *)v115 = *(_DWORD *)v117;
        v115 = v117;
        v118 = &m_data[*(unsigned __int16 *)(v117 + 2)];
        if ( (v116 & 1) != 0 )
        {
          --v118->max_z;
        }
        else
        {
          v119 = (v118->max_x - v19->min_x) | (v118->max_y - v19->min_y) | (v19->max_x - v118->min_x);
          v120 = v19->max_y - v118->min_y;
          --v118->min_z;
          if ( ((v120 | v119) & 0x8000) == 0 )
            hkp3AxisSweep::beginOverlap(v19, v118, addedPairsOut);
        }
        v116 = *(unsigned __int16 *)(v115 + 4);
        v117 = v115 + 4;
      }
      while ( v150 > v116 );
      LODWORD(m_id) = v144;
      v6 = this;
      v113 = WORD2(v148) & 0xFFFE;
    }
    v121 = v115 + 4;
    if ( v150 == *(unsigned __int16 *)(v115 + 4) )
    {
      do
      {
        v122 = *(unsigned __int16 *)(v115 + 6);
        if ( (unsigned int)m_id <= (unsigned int)v122 )
          break;
        if ( !*(_WORD *)(v115 + 6) )
          break;
        LOWORD(max_z) = max_z + 1;
        *(_DWORD *)v115 = *(_DWORD *)v121;
        --m_data[v122].max_z;
        v123 = *(unsigned __int16 *)(v121 + 4);
        v115 = v121;
        v121 += 4i64;
      }
      while ( v150 == v123 );
      v113 = WORD2(v148) & 0xFFFE;
    }
    v124 = *(unsigned __int16 *)(v115 - 4);
    v125 = (_DWORD *)(v115 - 4);
    if ( v150 < v124 )
    {
      do
      {
        LOWORD(max_z) = max_z - 1;
        *(_DWORD *)v115 = *v125;
        v126 = *(unsigned __int16 *)(v115 - 2);
        v115 = (__int64)v125;
        v127 = &m_data[v126];
        if ( (v124 & 1) != 0 )
        {
          ++v127->max_z;
        }
        else
        {
          v128 = (v127->max_x - v19->min_x) | (v127->max_y - v19->min_y) | (v19->max_x - v127->min_x);
          v129 = v19->max_y - v127->min_y;
          ++v127->min_z;
          if ( ((v129 | v128) & 0x8000) == 0 )
            hkp3AxisSweep::endOverlap(v19, v127, removedPairsOut);
        }
        v124 = *(unsigned __int16 *)(v115 - 4);
        v125 = (_DWORD *)(v115 - 4);
      }
      while ( v150 < v124 );
      v6 = this;
      v113 = WORD2(v148) & 0xFFFE;
    }
    v130 = (_DWORD *)(v115 - 4);
    if ( v150 == *(unsigned __int16 *)(v115 - 4) )
    {
      do
      {
        v131 = *(unsigned __int16 *)(v115 - 2);
        if ( (unsigned int)m_id >= (unsigned int)v131 )
          break;
        LOWORD(max_z) = max_z - 1;
        *(_DWORD *)v115 = *v130;
        v115 = (__int64)v130;
        ++m_data[v131].max_z;
        v132 = *((unsigned __int16 *)v130-- - 2);
      }
      while ( v150 == v132 );
    }
    v19->max_z = max_z;
    *(_WORD *)v115 = WORD2(v149) | 1;
    *(_WORD *)(v115 + 2) = m_id;
    v133 = v19->min_z;
    v134 = (__int64)&v6->m_axis[2].m_endPoints.m_data[v133];
    v135 = *(unsigned __int16 *)(v134 + 4);
    v136 = (_DWORD *)(v134 + 4);
    if ( v145 > v135 )
    {
      do
      {
        LOWORD(v133) = v133 + 1;
        v137 = *(unsigned __int16 *)(v134 + 6);
        *(_DWORD *)v134 = *v136;
        v134 = (__int64)v136;
        v138 = &m_data[v137];
        if ( (v135 & 1) != 0 )
        {
          v139 = (v138->max_x - v19->min_x) | (v138->max_y - v19->min_y) | (v19->max_x - v138->min_x);
          v140 = v19->max_y - v138->min_y;
          --v138->max_z;
          if ( ((v140 | v139) & 0x8000) == 0 )
            hkp3AxisSweep::endOverlap(v19, v138, removedPairsOut);
        }
        else
        {
          --v138->min_z;
        }
        v135 = *(unsigned __int16 *)(v134 + 4);
        v136 = (_DWORD *)(v134 + 4);
      }
      while ( v145 > v135 );
      LODWORD(m_id) = v144;
      v6 = this;
      v113 = WORD2(v148) & 0xFFFE;
    }
    v141 = v134 + 4;
    if ( v145 == *(unsigned __int16 *)(v134 + 4) )
    {
      do
      {
        v142 = *(unsigned __int16 *)(v134 + 6);
        if ( (unsigned int)m_id <= (unsigned int)v142 )
          break;
        LOWORD(v133) = v133 + 1;
        *(_DWORD *)v134 = *(_DWORD *)v141;
        v134 = v141;
        --m_data[v142].min_z;
        v143 = *(unsigned __int16 *)(v141 + 4);
        v141 += 4i64;
      }
      while ( v145 == v143 );
      v113 = WORD2(v148) & 0xFFFE;
    }
    v19->min_z = v133;
    objects = v151 + 1;
    aabbs = v155 + 1;
    *(_WORD *)(v134 + 2) = m_id;
    *(_WORD *)v134 = v113;
    ++v155;
  }
}ects = v151 + 1;
    aabbs = v155 + 1;
    *(_WORD *)(v134 + 2) = m_id;
    *(_WORD *)v134 = v113;
    ++v155;
  }
}

// File Line: 708
// RVA: 0xCFFFA0
void __fastcall hkp3AxisSweep::updateAabbsUint32(
        hkp3AxisSweep *this,
        hkpBroadPhaseHandle **objects,
        hkAabbUint32 *aabbs,
        int numObjects,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairsOut,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairsOut)
{
  hkpBroadPhaseHandle **v6; // r11
  hkp3AxisSweep *v7; // r10
  unsigned int v8; // ebp
  unsigned int v9; // edx
  unsigned int v10; // ebp
  unsigned int v11; // r13d
  unsigned int v12; // r13d
  unsigned int v13; // ecx
  hkp3AxisSweep::hkpBpNode *m_data; // r14
  unsigned int v15; // r12d
  __int64 m_id; // r15
  __int64 min_x; // rsi
  hkp3AxisSweep::hkpBpNode *v18; // rbx
  __int64 v19; // rdi
  unsigned int v20; // r9d
  _DWORD *v21; // r8
  __int64 v22; // rcx
  hkp3AxisSweep::hkpBpNode *v23; // rdx
  int v24; // ecx
  int v25; // eax
  _DWORD *v26; // rcx
  __int64 v27; // rdx
  int v28; // eax
  __int64 max_x; // rsi
  __int64 v30; // rdi
  unsigned int v31; // r8d
  __int64 i; // rcx
  hkp3AxisSweep::hkpBpNode *v33; // rdx
  int v34; // ecx
  __int64 v35; // rdx
  __int64 v36; // rcx
  int v37; // eax
  unsigned int v38; // r9d
  _DWORD *j; // r8
  __int64 v40; // rax
  hkp3AxisSweep::hkpBpNode *v41; // rdx
  int v42; // ecx
  int v43; // eax
  _DWORD *v44; // rdx
  __int64 v45; // rcx
  int v46; // eax
  hkp3AxisSweep *v47; // r10
  __int64 v48; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v49; // rdi
  unsigned int m_value; // r9d
  hkp3AxisSweep::hkpBpEndPoint *k; // r8
  __int64 m_nodeIndex; // rcx
  hkp3AxisSweep::hkpBpNode *v53; // rdx
  int v54; // ecx
  hkp3AxisSweep::hkpBpEndPoint *v55; // rdx
  __int64 v56; // rcx
  int v57; // eax
  unsigned int v58; // r12d
  __int64 min_y; // rsi
  __int64 v60; // rdi
  unsigned int v61; // r9d
  _DWORD *v62; // r8
  __int64 v63; // rcx
  hkp3AxisSweep::hkpBpNode *v64; // rdx
  unsigned __int16 v65; // cx
  unsigned __int16 v66; // ax
  _DWORD *v67; // rcx
  __int64 v68; // rdx
  int v69; // eax
  unsigned __int16 v70; // bp
  __int64 max_y; // rsi
  __int64 v72; // rdi
  unsigned int v73; // r8d
  __int64 v74; // rcx
  hkp3AxisSweep::hkpBpNode *v75; // rdx
  unsigned __int16 v76; // cx
  unsigned __int16 v77; // ax
  __int64 v78; // rdx
  __int64 v79; // rcx
  int v80; // eax
  unsigned int v81; // r9d
  _DWORD *v82; // r8
  __int64 v83; // rax
  hkp3AxisSweep::hkpBpNode *v84; // rdx
  unsigned __int16 v85; // cx
  unsigned __int16 v86; // ax
  _DWORD *v87; // rdx
  __int64 v88; // rcx
  int v89; // eax
  hkp3AxisSweep *v90; // r10
  __int64 v91; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v92; // rdi
  unsigned int v93; // r9d
  hkp3AxisSweep::hkpBpEndPoint *v94; // r8
  __int64 v95; // rcx
  hkp3AxisSweep::hkpBpNode *v96; // rdx
  __int16 v97; // cx
  __int16 v98; // ax
  hkp3AxisSweep::hkpBpEndPoint *v99; // rdx
  __int64 v100; // rcx
  int v101; // eax
  unsigned int v102; // r13d
  __int64 min_z; // rsi
  __int64 v104; // rdi
  unsigned int v105; // r9d
  _DWORD *v106; // r8
  __int64 v107; // rcx
  hkp3AxisSweep::hkpBpNode *v108; // rdx
  __int16 v109; // cx
  __int16 v110; // ax
  _DWORD *v111; // rcx
  __int64 v112; // rdx
  int v113; // eax
  unsigned __int16 v114; // bp
  __int64 max_z; // rsi
  __int64 v116; // rdi
  unsigned int v117; // r8d
  __int64 v118; // rcx
  hkp3AxisSweep::hkpBpNode *v119; // rdx
  unsigned __int16 v120; // cx
  unsigned __int16 v121; // ax
  __int64 v122; // rdx
  __int64 v123; // rcx
  int v124; // eax
  unsigned int v125; // r9d
  _DWORD *v126; // r8
  __int64 v127; // rax
  hkp3AxisSweep::hkpBpNode *v128; // rdx
  unsigned __int16 v129; // cx
  unsigned __int16 v130; // ax
  _DWORD *v131; // rdx
  __int64 v132; // rcx
  int v133; // eax
  __int64 v134; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v135; // rdi
  unsigned int v136; // r9d
  hkp3AxisSweep::hkpBpEndPoint *v137; // r8
  __int64 v138; // rcx
  hkp3AxisSweep::hkpBpNode *v139; // rdx
  __int16 v140; // cx
  __int16 v141; // ax
  hkp3AxisSweep::hkpBpEndPoint *v142; // rcx
  __int64 v143; // rdx
  int v144; // eax
  unsigned int v145; // [rsp+30h] [rbp-C8h]
  unsigned int v146; // [rsp+50h] [rbp-A8h]
  unsigned __int16 v147; // [rsp+60h] [rbp-98h]
  unsigned __int16 v148; // [rsp+64h] [rbp-94h]
  unsigned __int16 v149; // [rsp+68h] [rbp-90h]
  __int16 v150; // [rsp+78h] [rbp-80h]
  unsigned int v151; // [rsp+80h] [rbp-78h]
  hkpBroadPhaseHandle **v152; // [rsp+A0h] [rbp-58h]
  hkpBroadPhaseHandle **v153; // [rsp+A8h] [rbp-50h]
  unsigned int v155; // [rsp+108h] [rbp+10h]
  hkAabbUint32 *v156; // [rsp+110h] [rbp+18h]

  v156 = aabbs;
  v6 = objects;
  v152 = objects;
  v7 = this;
  v153 = &objects[numObjects];
  if ( objects < v153 )
  {
    do
    {
      v8 = aabbs->m_max[0] >> 15;
      v9 = aabbs->m_min[2] >> 15;
      if ( v8 != 0xFFFF )
        ++v8;
      v10 = v8 | 1;
      v11 = aabbs->m_max[1] >> 15;
      if ( v11 != 0xFFFF )
        ++v11;
      v12 = v11 | 1;
      v13 = aabbs->m_max[2] >> 15;
      if ( v13 != 0xFFFF )
        ++v13;
      m_data = v7->m_nodes.m_data;
      v15 = (aabbs->m_min[0] >> 15) & 0xFFFE;
      v155 = (aabbs->m_min[1] >> 15) & 0xFFFE;
      v148 = (aabbs->m_min[1] >> 15) & 0xFFFE;
      m_id = (*v6)->m_id;
      v147 = (aabbs->m_min[0] >> 15) & 0xFFFE;
      min_x = m_data[m_id].min_x;
      v18 = &m_data[m_id];
      v19 = (__int64)&v7->m_axis[0].m_endPoints.m_data[min_x];
      v151 = v13 | 1;
      v150 = v13 | 1;
      v20 = *(unsigned __int16 *)(v19 - 4);
      v21 = (_DWORD *)(v19 - 4);
      v145 = v9 & 0xFFFE;
      v149 = v9 & 0xFFFE;
      v146 = (*v6)->m_id;
      if ( v15 < v20 )
      {
        do
        {
          v22 = *(unsigned __int16 *)(v19 - 2);
          *(_DWORD *)v19 = *v21;
          v19 = (__int64)v21;
          v23 = &m_data[v22];
          if ( (v20 & 1) != 0 )
          {
            v24 = *(_DWORD *)&v18->max_y - *(_DWORD *)&v23->min_y;
            v25 = *(_DWORD *)&v23->max_y - *(_DWORD *)&v18->min_y;
            v23->max_x = min_x;
            if ( ((v25 | v24) & 0x80008000) == 0 )
              hkp3AxisSweep::beginOverlapCheckMarker(this->m_markers, &m_data[m_id], m_id, v23, addedPairsOut);
          }
          else
          {
            v23->min_x = min_x;
          }
          v20 = *(unsigned __int16 *)(v19 - 4);
          v21 = (_DWORD *)(v19 - 4);
          LOWORD(min_x) = min_x - 1;
        }
        while ( v15 < v20 );
        v7 = this;
      }
      v26 = (_DWORD *)(v19 - 4);
      if ( v15 == *(unsigned __int16 *)(v19 - 4) )
      {
        do
        {
          v27 = *(unsigned __int16 *)(v19 - 2);
          if ( (unsigned int)m_id >= (unsigned int)v27 )
            break;
          *(_DWORD *)v19 = *v26;
          v19 = (__int64)v26;
          m_data[v27].min_x = min_x;
          v28 = *((unsigned __int16 *)v26-- - 2);
          LOWORD(min_x) = min_x - 1;
        }
        while ( v15 == v28 );
      }
      *(_WORD *)(v19 + 2) = m_id;
      *(_WORD *)v19 = v15;
      v18->min_x = min_x;
      max_x = v18->max_x;
      v30 = (__int64)&v7->m_axis[0].m_endPoints.m_data[max_x];
      v31 = *(unsigned __int16 *)(v30 + 4);
      for ( i = v30 + 4; v10 > v31; i = v30 + 4 )
      {
        LOWORD(max_x) = max_x + 1;
        *(_DWORD *)v30 = *(_DWORD *)i;
        v30 = i;
        v33 = &m_data[*(unsigned __int16 *)(i + 2)];
        if ( (v31 & 1) != 0 )
        {
          --v33->max_x;
        }
        else
        {
          v34 = (*(_DWORD *)&v33->max_y - *(_DWORD *)&v18->min_y) | (*(_DWORD *)&v18->max_y - *(_DWORD *)&v33->min_y);
          --v33->min_x;
          if ( (v34 & 0x80008000) == 0 )
            hkp3AxisSweep::beginOverlapCheckMarker(this->m_markers, &m_data[m_id], m_id, v33, addedPairsOut);
        }
        v31 = *(unsigned __int16 *)(v30 + 4);
      }
      v35 = v30 + 4;
      if ( v10 == *(unsigned __int16 *)(v30 + 4) )
      {
        do
        {
          v36 = *(unsigned __int16 *)(v30 + 6);
          if ( (unsigned int)m_id <= (unsigned int)v36 )
            break;
          if ( !*(_WORD *)(v30 + 6) )
            break;
          LOWORD(max_x) = max_x + 1;
          *(_DWORD *)v30 = *(_DWORD *)v35;
          --m_data[v36].max_x;
          v37 = *(unsigned __int16 *)(v35 + 4);
          v30 = v35;
          v35 += 4i64;
        }
        while ( v10 == v37 );
      }
      v38 = *(unsigned __int16 *)(v30 - 4);
      for ( j = (_DWORD *)(v30 - 4); v10 < v38; j = (_DWORD *)(v30 - 4) )
      {
        LOWORD(max_x) = max_x - 1;
        *(_DWORD *)v30 = *j;
        v40 = *(unsigned __int16 *)(v30 - 2);
        v30 = (__int64)j;
        v41 = &m_data[v40];
        if ( (v38 & 1) != 0 )
        {
          ++v41->max_x;
        }
        else
        {
          v42 = *(_DWORD *)&v18->max_y - *(_DWORD *)&v41->min_y;
          v43 = *(_DWORD *)&v41->max_y - *(_DWORD *)&v18->min_y;
          ++v41->min_x;
          if ( ((v43 | v42) & 0x80008000) == 0 )
            hkp3AxisSweep::endOverlapCheckMarker(this->m_markers, &m_data[m_id], m_id, v41, removedPairsOut);
        }
        v38 = *(unsigned __int16 *)(v30 - 4);
      }
      v44 = (_DWORD *)(v30 - 4);
      if ( v10 == *(unsigned __int16 *)(v30 - 4) )
      {
        do
        {
          v45 = *(unsigned __int16 *)(v30 - 2);
          if ( (unsigned int)m_id >= (unsigned int)v45 )
            break;
          LOWORD(max_x) = max_x - 1;
          *(_DWORD *)v30 = *v44;
          ++m_data[v45].max_x;
          v46 = *((unsigned __int16 *)v44 - 2);
          v30 = (__int64)v44--;
        }
        while ( v10 == v46 );
      }
      v47 = this;
      v18->max_x = max_x;
      *(_WORD *)v30 = v10;
      *(_WORD *)(v30 + 2) = m_id;
      v48 = v18->min_x;
      v49 = &this->m_axis[0].m_endPoints.m_data[v48];
      m_value = v49[1].m_value;
      for ( k = v49 + 1; v15 > m_value; k = v49 + 1 )
      {
        LOWORD(v48) = v48 + 1;
        m_nodeIndex = v49[1].m_nodeIndex;
        *v49 = *k;
        v49 = k;
        v53 = &m_data[m_nodeIndex];
        if ( (m_value & 1) != 0 )
        {
          v54 = (*(_DWORD *)&v53->max_y - *(_DWORD *)&v18->min_y) | (*(_DWORD *)&v18->max_y - *(_DWORD *)&v53->min_y);
          --v53->max_x;
          if ( (v54 & 0x80008000) == 0 )
          {
            hkp3AxisSweep::endOverlapCheckMarker(v47->m_markers, &m_data[m_id], m_id, v53, removedPairsOut);
            v47 = this;
          }
        }
        else
        {
          --v53->min_x;
        }
        m_value = v49[1].m_value;
      }
      v55 = v49 + 1;
      if ( v15 == v49[1].m_value )
      {
        do
        {
          v56 = v49[1].m_nodeIndex;
          if ( (unsigned int)m_id <= (unsigned int)v56 )
            break;
          LOWORD(v48) = v48 + 1;
          *v49 = *v55;
          --m_data[v56].min_x;
          v57 = v55[1].m_value;
          v49 = v55++;
        }
        while ( v15 == v57 );
      }
      v58 = v155;
      v18->min_x = v48;
      v49->m_value = v147;
      v49->m_nodeIndex = m_id;
      min_y = v18->min_y;
      v60 = (__int64)&v47->m_axis[1].m_endPoints.m_data[min_y];
      v61 = *(unsigned __int16 *)(v60 - 4);
      v62 = (_DWORD *)(v60 - 4);
      if ( v155 < v61 )
      {
        do
        {
          v63 = *(unsigned __int16 *)(v60 - 2);
          *(_DWORD *)v60 = *v62;
          v60 = (__int64)v62;
          v64 = &m_data[v63];
          if ( (v61 & 1) != 0 )
          {
            v65 = (v18->max_x - v64->min_x) | (v18->max_z - v64->min_z) | (v64->max_z - v18->min_z);
            v66 = v64->max_x - v18->min_x;
            v64->max_y = min_y;
            if ( ((v66 | v65) & 0x8000) == 0 )
              hkp3AxisSweep::beginOverlap(v18, v64, addedPairsOut);
          }
          else
          {
            v64->min_y = min_y;
          }
          v61 = *(unsigned __int16 *)(v60 - 4);
          v62 = (_DWORD *)(v60 - 4);
          LOWORD(min_y) = min_y - 1;
        }
        while ( v155 < v61 );
        LODWORD(m_id) = v146;
        v47 = this;
      }
      v67 = (_DWORD *)(v60 - 4);
      if ( v155 == *(unsigned __int16 *)(v60 - 4) )
      {
        do
        {
          v68 = *(unsigned __int16 *)(v60 - 2);
          if ( (unsigned int)m_id >= (unsigned int)v68 )
            break;
          *(_DWORD *)v60 = *v67;
          v60 = (__int64)v67;
          m_data[v68].min_y = min_y;
          v69 = *((unsigned __int16 *)v67-- - 2);
          LOWORD(min_y) = min_y - 1;
        }
        while ( v155 == v69 );
      }
      v70 = v148;
      *(_WORD *)(v60 + 2) = m_id;
      *(_WORD *)v60 = v148;
      v18->min_y = min_y;
      max_y = v18->max_y;
      v72 = (__int64)&v47->m_axis[1].m_endPoints.m_data[max_y];
      v73 = *(unsigned __int16 *)(v72 + 4);
      v74 = v72 + 4;
      if ( v12 > v73 )
      {
        do
        {
          LOWORD(max_y) = max_y + 1;
          *(_DWORD *)v72 = *(_DWORD *)v74;
          v72 = v74;
          v75 = &m_data[*(unsigned __int16 *)(v74 + 2)];
          if ( (v73 & 1) != 0 )
          {
            --v75->max_y;
          }
          else
          {
            v76 = (v18->max_x - v75->min_x) | (v18->max_z - v75->min_z) | (v75->max_z - v18->min_z);
            v77 = v75->max_x - v18->min_x;
            --v75->min_y;
            if ( ((v77 | v76) & 0x8000) == 0 )
              hkp3AxisSweep::beginOverlap(v18, v75, addedPairsOut);
          }
          v73 = *(unsigned __int16 *)(v72 + 4);
          v74 = v72 + 4;
        }
        while ( v12 > v73 );
        LODWORD(m_id) = v146;
        v70 = v148;
        v58 = v155;
      }
      v78 = v72 + 4;
      if ( v12 == *(unsigned __int16 *)(v72 + 4) )
      {
        do
        {
          v79 = *(unsigned __int16 *)(v72 + 6);
          if ( (unsigned int)m_id <= (unsigned int)v79 )
            break;
          if ( !*(_WORD *)(v72 + 6) )
            break;
          LOWORD(max_y) = max_y + 1;
          *(_DWORD *)v72 = *(_DWORD *)v78;
          --m_data[v79].max_y;
          v80 = *(unsigned __int16 *)(v78 + 4);
          v72 = v78;
          v78 += 4i64;
        }
        while ( v12 == v80 );
        v70 = v148;
      }
      v81 = *(unsigned __int16 *)(v72 - 4);
      v82 = (_DWORD *)(v72 - 4);
      if ( v12 < v81 )
      {
        do
        {
          LOWORD(max_y) = max_y - 1;
          *(_DWORD *)v72 = *v82;
          v83 = *(unsigned __int16 *)(v72 - 2);
          v72 = (__int64)v82;
          v84 = &m_data[v83];
          if ( (v81 & 1) != 0 )
          {
            ++v84->max_y;
          }
          else
          {
            v85 = (v18->max_x - v84->min_x) | (v18->max_z - v84->min_z) | (v84->max_z - v18->min_z);
            v86 = v84->max_x - v18->min_x;
            ++v84->min_y;
            if ( ((v86 | v85) & 0x8000) == 0 )
              hkp3AxisSweep::endOverlap(v18, v84, removedPairsOut);
          }
          v81 = *(unsigned __int16 *)(v72 - 4);
          v82 = (_DWORD *)(v72 - 4);
        }
        while ( v12 < v81 );
        v70 = v148;
        v58 = v155;
      }
      v87 = (_DWORD *)(v72 - 4);
      if ( v12 == *(unsigned __int16 *)(v72 - 4) )
      {
        do
        {
          v88 = *(unsigned __int16 *)(v72 - 2);
          if ( (unsigned int)m_id >= (unsigned int)v88 )
            break;
          LOWORD(max_y) = max_y - 1;
          *(_DWORD *)v72 = *v87;
          ++m_data[v88].max_y;
          v89 = *((unsigned __int16 *)v87 - 2);
          v72 = (__int64)v87--;
        }
        while ( v12 == v89 );
      }
      v90 = this;
      v18->max_y = max_y;
      *(_WORD *)v72 = v12;
      *(_WORD *)(v72 + 2) = m_id;
      v91 = v18->min_y;
      v92 = &this->m_axis[1].m_endPoints.m_data[v91];
      v93 = v92[1].m_value;
      v94 = v92 + 1;
      if ( v58 > v93 )
      {
        do
        {
          LOWORD(v91) = v91 + 1;
          v95 = v92[1].m_nodeIndex;
          *v92 = *v94;
          v92 = v94;
          v96 = &m_data[v95];
          if ( (v93 & 1) != 0 )
          {
            v97 = (v18->max_x - v96->min_x) | (v18->max_z - v96->min_z) | (v96->max_z - v18->min_z);
            v98 = v96->max_x - v18->min_x;
            --v96->max_y;
            if ( ((v98 | v97) & 0x8000u) == 0 )
              hkp3AxisSweep::endOverlap(v18, v96, removedPairsOut);
          }
          else
          {
            --v96->min_y;
          }
          v93 = v92[1].m_value;
          v94 = v92 + 1;
        }
        while ( v58 > v93 );
        LODWORD(m_id) = v146;
        v70 = v148;
        v90 = this;
      }
      v99 = v92 + 1;
      if ( v58 == v92[1].m_value )
      {
        do
        {
          v100 = v92[1].m_nodeIndex;
          if ( (unsigned int)m_id <= (unsigned int)v100 )
            break;
          LOWORD(v91) = v91 + 1;
          *v92 = *v99;
          --m_data[v100].min_y;
          v101 = v99[1].m_value;
          v92 = v99++;
        }
        while ( v58 == v101 );
        v90 = this;
      }
      v102 = v145;
      v18->min_y = v91;
      v92->m_nodeIndex = m_id;
      v92->m_value = v70;
      min_z = v18->min_z;
      v104 = (__int64)&v90->m_axis[2].m_endPoints.m_data[min_z];
      v105 = *(unsigned __int16 *)(v104 - 4);
      v106 = (_DWORD *)(v104 - 4);
      if ( v145 < v105 )
      {
        do
        {
          v107 = *(unsigned __int16 *)(v104 - 2);
          *(_DWORD *)v104 = *v106;
          v104 = (__int64)v106;
          v108 = &m_data[v107];
          if ( (v105 & 1) != 0 )
          {
            v109 = (v108->max_y - v18->min_y) | (v108->max_x - v18->min_x) | (v18->max_x - v108->min_x);
            v110 = v18->max_y - v108->min_y;
            v108->max_z = min_z;
            if ( ((v110 | v109) & 0x8000u) == 0 )
              hkp3AxisSweep::beginOverlap(v18, v108, addedPairsOut);
          }
          else
          {
            v108->min_z = min_z;
          }
          v105 = *(unsigned __int16 *)(v104 - 4);
          v106 = (_DWORD *)(v104 - 4);
          LOWORD(min_z) = min_z - 1;
        }
        while ( v145 < v105 );
        LODWORD(m_id) = v146;
        v90 = this;
      }
      v111 = (_DWORD *)(v104 - 4);
      if ( v145 == *(unsigned __int16 *)(v104 - 4) )
      {
        do
        {
          v112 = *(unsigned __int16 *)(v104 - 2);
          if ( (unsigned int)m_id >= (unsigned int)v112 )
            break;
          *(_DWORD *)v104 = *v111;
          v104 = (__int64)v111;
          m_data[v112].min_z = min_z;
          v113 = *((unsigned __int16 *)v111-- - 2);
          LOWORD(min_z) = min_z - 1;
        }
        while ( v145 == v113 );
      }
      v114 = v149;
      *(_WORD *)(v104 + 2) = m_id;
      *(_WORD *)v104 = v149;
      v18->min_z = min_z;
      max_z = v18->max_z;
      v116 = (__int64)&v90->m_axis[2].m_endPoints.m_data[max_z];
      v117 = *(unsigned __int16 *)(v116 + 4);
      v118 = v116 + 4;
      if ( v151 > v117 )
      {
        do
        {
          LOWORD(max_z) = max_z + 1;
          *(_DWORD *)v116 = *(_DWORD *)v118;
          v116 = v118;
          v119 = &m_data[*(unsigned __int16 *)(v118 + 2)];
          if ( (v117 & 1) != 0 )
          {
            --v119->max_z;
          }
          else
          {
            v120 = (v119->max_y - v18->min_y) | (v119->max_x - v18->min_x) | (v18->max_x - v119->min_x);
            v121 = v18->max_y - v119->min_y;
            --v119->min_z;
            if ( ((v121 | v120) & 0x8000) == 0 )
              hkp3AxisSweep::beginOverlap(v18, v119, addedPairsOut);
          }
          v117 = *(unsigned __int16 *)(v116 + 4);
          v118 = v116 + 4;
        }
        while ( v151 > v117 );
        LODWORD(m_id) = v146;
        v114 = v149;
        v102 = v145;
      }
      v122 = v116 + 4;
      if ( v151 == *(unsigned __int16 *)(v116 + 4) )
      {
        do
        {
          v123 = *(unsigned __int16 *)(v116 + 6);
          if ( (unsigned int)m_id <= (unsigned int)v123 )
            break;
          if ( !*(_WORD *)(v116 + 6) )
            break;
          LOWORD(max_z) = max_z + 1;
          *(_DWORD *)v116 = *(_DWORD *)v122;
          --m_data[v123].max_z;
          v124 = *(unsigned __int16 *)(v122 + 4);
          v116 = v122;
          v122 += 4i64;
        }
        while ( v151 == v124 );
        v114 = v149;
      }
      v125 = *(unsigned __int16 *)(v116 - 4);
      v126 = (_DWORD *)(v116 - 4);
      if ( v151 < v125 )
      {
        do
        {
          LOWORD(max_z) = max_z - 1;
          *(_DWORD *)v116 = *v126;
          v127 = *(unsigned __int16 *)(v116 - 2);
          v116 = (__int64)v126;
          v128 = &m_data[v127];
          if ( (v125 & 1) != 0 )
          {
            ++v128->max_z;
          }
          else
          {
            v129 = (v128->max_y - v18->min_y) | (v128->max_x - v18->min_x) | (v18->max_x - v128->min_x);
            v130 = v18->max_y - v128->min_y;
            ++v128->min_z;
            if ( ((v130 | v129) & 0x8000) == 0 )
              hkp3AxisSweep::endOverlap(v18, v128, removedPairsOut);
          }
          v125 = *(unsigned __int16 *)(v116 - 4);
          v126 = (_DWORD *)(v116 - 4);
        }
        while ( v151 < v125 );
        v114 = v149;
        v102 = v145;
      }
      v131 = (_DWORD *)(v116 - 4);
      if ( v151 == *(unsigned __int16 *)(v116 - 4) )
      {
        do
        {
          v132 = *(unsigned __int16 *)(v116 - 2);
          if ( (unsigned int)m_id >= (unsigned int)v132 )
            break;
          LOWORD(max_z) = max_z - 1;
          *(_DWORD *)v116 = *v131;
          ++m_data[v132].max_z;
          v133 = *((unsigned __int16 *)v131 - 2);
          v116 = (__int64)v131--;
        }
        while ( v151 == v133 );
      }
      v7 = this;
      v18->max_z = max_z;
      *(_WORD *)v116 = v150;
      *(_WORD *)(v116 + 2) = m_id;
      v134 = v18->min_z;
      v135 = &this->m_axis[2].m_endPoints.m_data[v134];
      v136 = v135[1].m_value;
      v137 = v135 + 1;
      if ( v102 > v136 )
      {
        do
        {
          LOWORD(v134) = v134 + 1;
          v138 = v135[1].m_nodeIndex;
          *v135 = *v137;
          v135 = v137;
          v139 = &m_data[v138];
          if ( (v136 & 1) != 0 )
          {
            v140 = (v139->max_y - v18->min_y) | (v139->max_x - v18->min_x) | (v18->max_x - v139->min_x);
            v141 = v18->max_y - v139->min_y;
            --v139->max_z;
            if ( ((v141 | v140) & 0x8000u) == 0 )
              hkp3AxisSweep::endOverlap(v18, v139, removedPairsOut);
          }
          else
          {
            --v139->min_z;
          }
          v136 = v135[1].m_value;
          v137 = v135 + 1;
        }
        while ( v102 > v136 );
        LODWORD(m_id) = v146;
        v114 = v149;
        v7 = this;
      }
      v142 = v135 + 1;
      if ( v102 == v135[1].m_value )
      {
        do
        {
          v143 = v135[1].m_nodeIndex;
          if ( (unsigned int)m_id <= (unsigned int)v143 )
            break;
          LOWORD(v134) = v134 + 1;
          *v135 = *v142;
          v135 = v142;
          --m_data[v143].min_z;
          v144 = v142[1].m_value;
          ++v142;
        }
        while ( v102 == v144 );
        v7 = this;
      }
      v18->min_z = v134;
      v6 = v152 + 1;
      aabbs = v156 + 1;
      v135->m_nodeIndex = m_id;
      v135->m_value = v114;
      ++v156;
      v152 = v6;
    }
    while ( v6 < v153 );
  }
}m_nodeIndex = m_id;
      v135->m_value = v114;
      ++v156;
      v152 = v6;
    }
    while ( v6 < v153 );
  }
}

// File Line: 741
// RVA: 0xCFC350
void __fastcall hkp3AxisSweep::hkp3AxisSweep(
        hkp3AxisSweep *this,
        hkVector4f *worldMin,
        hkVector4f *worldMax,
        int numMarkers)
{
  __m128 v4; // xmm2
  hkp3AxisSweep::hkpBpAxis *m_axis; // rsi
  hkArray<hkp3AxisSweep::hkpBpNode,hkContainerHeapAllocator> *p_m_nodes; // r15
  int v11; // ebx
  int v12; // r9d
  float v13; // xmm7_4
  __int64 v14; // rcx
  __m128i si128; // xmm13
  __m128i v16; // xmm14
  __m128 v17; // xmm4
  __m128 v18; // xmm5
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128i v21; // xmm1
  __int64 m_size; // rcx
  hkp3AxisSweep::hkpBpNode *m_data; // rdx
  __int64 v24; // r12
  int v25; // r9d
  int v26; // eax
  int v27; // eax
  hkp3AxisSweep::hkpBpAxis *v28; // r13
  int v29; // edi
  int v30; // r9d
  hkp3AxisSweep::hkpBpAxis *v31; // rbp
  hkp3AxisSweep::hkpBpEndPoint *v32; // rdx
  hkp3AxisSweep::hkpBpEndPoint *v33; // r8
  hkp3AxisSweep::hkpBpEndPoint *v34; // r8
  hkMemoryAllocator **Value; // rax
  int v36; // edi
  __int64 v37; // r12
  hkp3AxisSweep::hkpBpMarker *v38; // r8
  unsigned __int16 v39; // dx
  int v40; // ecx
  unsigned __int16 v41; // bx
  int m_capacityAndFlags; // eax
  __int64 v43; // rcx
  hkp3AxisSweep::hkpBpNode *v44; // r8
  hkResult *v45; // r9
  hkResult *v46; // r9
  hkp3AxisSweep::hkpBpNode *v47; // rcx
  hkResult *v48; // rdx
  hkResultEnum m_enum; // eax
  _DWORD *p_m_value; // r8
  _DWORD *v51; // r8
  int v52; // [rsp+120h] [rbp+8h]
  __int64 v53; // [rsp+128h] [rbp+10h]
  hkp3AxisSweep::hkpBpNode *v54; // [rsp+130h] [rbp+18h]
  hkResult result; // [rsp+138h] [rbp+20h] BYREF

  hkpBroadPhase::hkpBroadPhase(this, BROADPHASE_16BIT, 272, 4123);
  m_axis = this->m_axis;
  p_m_nodes = &this->m_nodes;
  this->vfptr = (hkBaseObjectVtbl *)&hkp3AxisSweep::`vftable;
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_size = 0;
  this->m_nodes.m_capacityAndFlags = 0x80000000;
  this->m_axis[0].m_endPoints.m_data = 0i64;
  this->m_axis[1].m_endPoints.m_data = 0i64;
  this->m_axis[0].m_endPoints.m_size = 0;
  this->m_axis[0].m_endPoints.m_capacityAndFlags = 0x80000000;
  this->m_axis[1].m_endPoints.m_size = 0;
  this->m_axis[1].m_endPoints.m_capacityAndFlags = 0x80000000;
  this->m_axis[2].m_endPoints.m_data = 0i64;
  this->m_axis[2].m_endPoints.m_size = 0;
  this->m_axis[2].m_endPoints.m_capacityAndFlags = 0x80000000;
  this->m_aabb.m_min = (hkVector4f)worldMin->m_quad;
  if ( !numMarkers )
    numMarkers = 1;
  v11 = -1;
  for ( this->m_aabb.m_max = (hkVector4f)worldMax->m_quad; numMarkers > 0; ++v11 )
    numMarkers >>= 1;
  v12 = 255;
  if ( (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFFu) < 0xFF )
  {
    if ( 2 * (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) > 255 )
      v12 = 2 * (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, v12, 24);
  }
  v13 = FLOAT_10_0;
  this->m_scale = *(hkVector4f *)_xmm;
  this->m_offsetLow = 0i64;
  v14 = 23i64;
  this->m_offsetHigh = 0i64;
  si128 = _mm_load_si128((const __m128i *)&_xmm);
  v16 = _mm_load_si128((const __m128i *)&`hkIntVector::setConvertSaturateS32ToU16::`2::offset2);
  v17 = (__m128)LODWORD(FLOAT_11_0);
  do
  {
    v18 = v17;
    v18.m128_f32[0] = (float)(v17.m128_f32[0] + v13) * 0.5;
    v19 = v18;
    v4.m128_f32[0] = v18.m128_f32[0];
    v19.m128_f32[0] = v18.m128_f32[0] + 1.0;
    v4 = _mm_max_ps(
           _mm_min_ps(
             _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v4, v4, 0), (__m128)0i64), *(__m128 *)_xmm),
             hkp3AxisSweep::MaxVal),
           (__m128)0i64);
    v20 = _mm_max_ps(
            _mm_min_ps(
              _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 0), (__m128)0i64), *(__m128 *)_xmm),
              hkp3AxisSweep::MaxVal),
            (__m128)0i64);
    v21 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v20),
              _mm_cvttps_epi32(v20)),
            si128);
    if ( (_mm_add_epi16(_mm_packs_epi32(v21, v21), v16).m128i_u16[0] | 1u) >= 0xC )
      v17 = v18;
    else
      v13 = (float)(v17.m128_f32[0] + v13) * 0.5;
    --v14;
  }
  while ( v14 );
  this->m_scale = 0i64;
  this->m_offsetLow = 0i64;
  this->m_offsetHigh = 0i64;
  this->m_intToFloatFloorCorrection = (float)((float)(v17.m128_f32[0] + v13) * 0.5) - 11.0;
  if ( this->m_nodes.m_size == (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, 24);
  m_size = this->m_nodes.m_size;
  m_data = p_m_nodes->m_data;
  v24 = 3 * m_size;
  this->m_nodes.m_size = m_size + 1;
  *((_DWORD *)&m_data->min_y + 2 * v24) = 0;
  *(&m_data->min_x + 4 * v24) = 0;
  (&m_data->m_handle)[v24] = 0i64;
  v25 = 2 * (1 << v11) + 510;
  v52 = 1 << v11;
  v26 = this->m_axis[0].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  v53 = 3 * m_size;
  v54 = m_data;
  if ( v26 < v25 )
  {
    v27 = 2 * v26;
    if ( v25 < v27 )
      v25 = v27;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_axis[0].m_endPoints.m_data,
      v25,
      4);
  }
  v28 = &this->m_axis[1];
  v29 = 512;
  if ( (this->m_axis[1].m_endPoints.m_capacityAndFlags & 0x3FFFFFFFu) < 0x200 )
  {
    v30 = 512;
    if ( 2 * (this->m_axis[1].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF) > 512 )
      v30 = 2 * (this->m_axis[1].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_axis[1].m_endPoints.m_data,
      v30,
      4);
  }
  v31 = &this->m_axis[2];
  if ( (this->m_axis[2].m_endPoints.m_capacityAndFlags & 0x3FFFFFFFu) < 0x200 )
  {
    if ( 2 * (this->m_axis[2].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF) > 512 )
      v29 = 2 * (this->m_axis[2].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_axis[2].m_endPoints.m_data,
      v29,
      4);
  }
  v32 = &m_axis->m_endPoints.m_data[this->m_axis[0].m_endPoints.m_size];
  result.m_enum = HK_SUCCESS;
  if ( v32 )
    *v32 = 0;
  ++this->m_axis[0].m_endPoints.m_size;
  v33 = &v28->m_endPoints.m_data[this->m_axis[1].m_endPoints.m_size];
  if ( v33 )
    *v33 = 0;
  ++this->m_axis[1].m_endPoints.m_size;
  v34 = &v31->m_endPoints.m_data[this->m_axis[2].m_endPoints.m_size];
  if ( v34 )
    *v34 = 0;
  ++this->m_axis[2].m_endPoints.m_size;
  this->m_ld2NumMarkers = v11;
  this->m_markers = 0i64;
  this->m_numMarkers = v52 - 1;
  if ( v52 != 1 )
  {
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    this->m_markers = (hkp3AxisSweep::hkpBpMarker *)hkMemoryRouter::easyAlloc(Value[11], 24 * (v52 - 1));
  }
  v36 = 0;
  if ( this->m_numMarkers > 0 )
  {
    do
    {
      v37 = v36;
      v38 = &this->m_markers[v37];
      if ( v38 )
      {
        v38->m_overlappingObjects.m_data = 0i64;
        v38->m_overlappingObjects.m_size = 0;
        v38->m_overlappingObjects.m_capacityAndFlags = 0x80000000;
      }
      else
      {
        v38 = 0i64;
      }
      v39 = this->m_nodes.m_size;
      v40 = 16 - this->m_ld2NumMarkers;
      v38->m_nodeIndex = v39;
      HIWORD(result.m_enum) = v39;
      v41 = ((_WORD)v36 + 1) << v40;
      v38->m_value = v41;
      m_capacityAndFlags = this->m_nodes.m_capacityAndFlags;
      LOWORD(result.m_enum) = v41;
      if ( this->m_nodes.m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, 24);
      v43 = this->m_nodes.m_size;
      v44 = p_m_nodes->m_data;
      this->m_nodes.m_size = v43 + 1;
      v44[v43].min_x = this->m_axis[0].m_endPoints.m_size;
      v45 = (hkResult *)&m_axis->m_endPoints.m_data[this->m_axis[0].m_endPoints.m_size];
      if ( v45 )
        v45->m_enum = result.m_enum;
      ++this->m_axis[0].m_endPoints.m_size;
      v44[v43].max_x = this->m_axis[0].m_endPoints.m_size;
      v46 = (hkResult *)&m_axis->m_endPoints.m_data[this->m_axis[0].m_endPoints.m_size];
      LOWORD(result.m_enum) = v41 | 1;
      if ( v46 )
        v46->m_enum = result.m_enum;
      ++this->m_axis[0].m_endPoints.m_size;
      ++v36;
      *(_DWORD *)&v44[v43].min_y = 0;
      *(_DWORD *)&v44[v43].max_y = 65537;
      v44[v43].m_handle = (hkpBroadPhaseHandle *)((v37 * 24) | 1);
    }
    while ( v36 < this->m_numMarkers );
    v24 = v53;
    v28 = &this->m_axis[1];
  }
  v47 = p_m_nodes->m_data;
  result.m_enum = 65533;
  *((_QWORD *)&v54->min_y + v24) = *(_QWORD *)&v47->min_y;
  *((_QWORD *)&v54->min_x + v24) = *(_QWORD *)&v47->min_x;
  (&v54->m_handle)[v24] = v47->m_handle;
  *(&v54->max_x + 4 * v24) = this->m_axis[0].m_endPoints.m_size;
  *(&v54->max_y + 4 * v24) = this->m_axis[1].m_endPoints.m_size;
  *(&v54->max_z + 4 * v24) = this->m_axis[2].m_endPoints.m_size;
  v48 = (hkResult *)&m_axis->m_endPoints.m_data[this->m_axis[0].m_endPoints.m_size];
  m_enum = result.m_enum;
  if ( v48 )
    v48->m_enum = result.m_enum;
  ++this->m_axis[0].m_endPoints.m_size;
  p_m_value = &v28->m_endPoints.m_data[v28->m_endPoints.m_size].m_value;
  if ( p_m_value )
    *p_m_value = m_enum;
  ++v28->m_endPoints.m_size;
  v51 = &v31->m_endPoints.m_data[this->m_axis[2].m_endPoints.m_size].m_value;
  if ( v51 )
    *v51 = m_enum;
  ++this->m_axis[2].m_endPoints.m_size;
}

// File Line: 892
// RVA: 0xCFC9D0
void __fastcall hkp3AxisSweep::~hkp3AxisSweep(hkp3AxisSweep *this)
{
  int v2; // esi
  __int64 v3; // r14
  hkp3AxisSweep::hkpBpMarker *v4; // rbx
  int m_capacityAndFlags; // r8d
  hkp3AxisSweep::hkpBpMarker *m_markers; // rbx
  hkMemoryAllocator **Value; // rax
  int v8; // esi
  _DWORD *v9; // rbx
  int v10; // r8d
  int v11; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkp3AxisSweep::`vftable;
  v2 = 0;
  if ( this->m_numMarkers > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = &this->m_markers[v3];
      m_capacityAndFlags = v4->m_overlappingObjects.m_capacityAndFlags;
      v4->m_overlappingObjects.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v4->m_overlappingObjects.m_data,
          2 * (m_capacityAndFlags & 0x3FFFFFFF));
      ++v2;
      v4->m_overlappingObjects.m_data = 0i64;
      v4->m_overlappingObjects.m_capacityAndFlags = 0x80000000;
      ++v3;
    }
    while ( v2 < this->m_numMarkers );
  }
  m_markers = this->m_markers;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::easyFree(Value[11], m_markers);
  v8 = 2;
  v9 = (_DWORD *)&this->m_markers + 1;
  do
  {
    v10 = *(v9 - 4);
    v9 -= 4;
    *(v9 - 1) = 0;
    if ( v10 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, *(void **)(v9 - 3), 4 * v10);
    --v8;
    *(_QWORD *)(v9 - 3) = 0i64;
    *v9 = 0x80000000;
  }
  while ( v8 >= 0 );
  v11 = this->m_nodes.m_capacityAndFlags;
  this->m_nodes.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_nodes.m_data,
      24 * (v11 & 0x3FFFFFFF));
  this->m_nodes.m_data = 0i64;
  this->m_nodes.m_capacityAndFlags = 0x80000000;
  hkpBroadPhase::~hkpBroadPhase(this);
}

// File Line: 911
// RVA: 0xD04E10
void __fastcall hkp3AxisSweep::set32BitOffsetAndScale(
        hkp3AxisSweep *this,
        hkVector4f *offsetLow,
        hkVector4f *offsetHigh,
        hkVector4f *scale)
{
  __m128 v4; // xmm3
  __m128 m_quad; // xmm2
  __m128 v6; // xmm0
  hkVector4f v7; // xmm1

  v4 = _mm_sub_ps(this->m_aabb.m_max.m_quad, this->m_aabb.m_min.m_quad);
  this->m_offsetLow32bit = (hkVector4f)offsetLow->m_quad;
  this->m_offsetHigh32bit = (hkVector4f)offsetHigh->m_quad;
  this->m_scale32bit = (hkVector4f)scale->m_quad;
  m_quad = offsetLow->m_quad;
  v6 = _mm_rcp_ps(v4);
  this->m_offsetLow = (hkVector4f)offsetLow->m_quad;
  this->m_offsetHigh.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(FLOAT_0_00001525972),
                                    (__m128)LODWORD(FLOAT_0_00001525972),
                                    0),
                                  v4),
                                m_quad);
  v7.m_quad = _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(FLOAT_65532_0), (__m128)LODWORD(FLOAT_65532_0), 0),
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v6)), v6));
  this->m_scale = (hkVector4f)v7.m_quad;
  this->m_scale = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v7.m_quad, 4), 4);
  this->m_offsetLow = (hkVector4f)_mm_srli_si128(
                                    _mm_slli_si128(_mm_load_si128((const __m128i *)&this->m_offsetLow), 4),
                                    4);
  this->m_offsetHigh = (hkVector4f)_mm_srli_si128(
                                     _mm_slli_si128(_mm_load_si128((const __m128i *)&this->m_offsetHigh), 4),
                                     4);
}

// File Line: 969
// RVA: 0xD05320
void __fastcall hkp3AxisSweep::hkpBpAxis::mergeBatch(
        hkp3AxisSweep::hkpBpAxis *this,
        hkp3AxisSweep::hkpBpNode *nodes,
        int indexOfNewEps,
        int newNum,
        int axis,
        hkp3AxisSweep::hkpBpEndPoint *scratch)
{
  __int64 i; // r10
  hkp3AxisSweep::hkpBpEndPoint *v9; // r11
  hkp3AxisSweep::hkpBpEndPoint *v10; // r10
  hkp3AxisSweep::hkpBpEndPoint *v11; // r15
  hkp3AxisSweep::hkpBpEndPoint *v12; // r14
  int m_value; // edx
  hkp3AxisSweep::hkpBpEndPoint *v14; // rax
  int v15; // ecx
  hkp3AxisSweep::hkpBpEndPoint v16; // ecx
  char v17; // dl
  __int64 m_nodeIndex; // rcx
  __int64 v19; // r9
  hkp3AxisSweep::hkpBpEndPoint v20; // ecx
  char v21; // dl
  __int64 v22; // rcx
  __int64 v23; // r9
  hkp3AxisSweep::hkpBpEndPoint v24; // ecx
  __int64 v25; // r9
  hkp3AxisSweep::hkpBpEndPoint v26; // ecx
  __int64 v27; // r9

  for ( i = 0i64; i < indexOfNewEps; scratch[i - 1] = this->m_endPoints.m_data[i - 1] )
    ++i;
  v9 = &this->m_endPoints.m_data[indexOfNewEps];
  v10 = scratch + 1;
  v11 = &scratch[indexOfNewEps - 1];
  v12 = &this->m_endPoints.m_data[indexOfNewEps + newNum];
  m_value = v9->m_value;
  v14 = this->m_endPoints.m_data + 1;
  if ( scratch[1].m_value < m_value )
  {
    do
    {
      v15 = v10[1].m_value;
      ++v10;
      ++v14;
    }
    while ( v15 < m_value );
  }
  if ( v10 < v11 )
  {
    if ( v9 >= v12 )
      goto LABEL_15;
    do
    {
      while ( v10->m_value >= v9->m_value && (v10->m_value != v9->m_value || v10->m_nodeIndex >= v9->m_nodeIndex) )
      {
        v16 = *v9++;
        *v14 = v16;
        v17 = v16.m_value;
        m_nodeIndex = v14->m_nodeIndex;
        v19 = (__int64)(unsigned int)((_DWORD)v14++ - LODWORD(this->m_endPoints.m_data)) >> 2;
        *(unsigned __int16 *)((char *)&nodes[m_nodeIndex].min_y
                            + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2 * axis + (v17 & 1)]) = v19;
        if ( v9 >= v12 )
          goto LABEL_15;
      }
      v20 = *v10++;
      *v14 = v20;
      v21 = v20.m_value;
      v22 = v14->m_nodeIndex;
      v23 = (__int64)(unsigned int)((_DWORD)v14++ - LODWORD(this->m_endPoints.m_data)) >> 2;
      *(unsigned __int16 *)((char *)&nodes[v22].min_y + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2 * axis + (v21 & 1)]) = v23;
    }
    while ( v10 < v11 );
  }
  for ( ;
        v9 < v12;
        *(unsigned __int16 *)((char *)&nodes[v14[-1].m_nodeIndex].min_y
                            + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2 * axis + (v24.m_value & 1)]) = v25 )
  {
    v24 = *v9++;
    *v14 = v24;
    v25 = (__int64)(unsigned int)((_DWORD)v14++ - LODWORD(this->m_endPoints.m_data)) >> 2;
  }
LABEL_15:
  while ( v10 <= v11 )
  {
    v26 = *v10++;
    *v14 = v26;
    v27 = (__int64)(unsigned int)((_DWORD)v14++ - LODWORD(this->m_endPoints.m_data)) >> 2;
    *(unsigned __int16 *)((char *)&nodes[v14[-1].m_nodeIndex].min_y
                        + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2 * axis + (v26.m_value & 1)]) = v27;
  }
}

// File Line: 1087
// RVA: 0xD05540
void __fastcall hkp3AxisSweep::hkpBpAxis::insert(
        hkp3AxisSweep::hkpBpAxis *this,
        hkp3AxisSweep::hkpBpNode *nodes,
        unsigned int nodeIndex,
        unsigned __int16 minPosition,
        unsigned __int16 maxPosition,
        unsigned __int16 *minInsertPositionOut,
        unsigned __int16 *maxInsertPositionOut)
{
  int v8; // edi
  int v9; // eax
  int v12; // eax
  int v13; // r9d
  int v14; // r8d
  hkp3AxisSweep::hkpBpEndPoint *v15; // rax
  hkp3AxisSweep::hkpBpEndPoint v16; // ecx
  hkp3AxisSweep::hkpBpEndPoint v17; // ecx
  unsigned __int16 *v18; // rcx
  hkp3AxisSweep::hkpBpEndPoint v19; // ecx
  hkp3AxisSweep::hkpBpEndPoint v20; // ecx
  hkResult result; // [rsp+58h] [rbp+20h] BYREF

  v8 = this->m_endPoints.m_size + 2;
  v9 = this->m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < v8 )
  {
    v12 = 2 * v9;
    v13 = this->m_endPoints.m_size + 2;
    if ( v8 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_endPoints.m_data, v13, 4);
  }
  v14 = maxPosition;
  this->m_endPoints.m_size = v8;
  v15 = &this->m_endPoints.m_data[v8 - 4];
  for ( v15[3] = this->m_endPoints.m_data[v8 - 3]; v14 < v15->m_value; v15[3] = v16 )
    v16 = *v15--;
  for ( ; v14 == v15->m_value; v15[3] = v17 )
  {
    if ( nodeIndex >= v15->m_nodeIndex )
      break;
    v17 = *v15--;
  }
  v18 = maxInsertPositionOut;
  v15[2].m_nodeIndex = nodeIndex;
  v15[2].m_value = v14;
  for ( *v18 = ((__int64)(unsigned int)((_DWORD)v15 - LODWORD(this->m_endPoints.m_data)) >> 2) + 2;
        minPosition < (int)v15->m_value;
        v15[2] = v19 )
  {
    v19 = *v15--;
  }
  for ( ; minPosition == v15->m_value; v15[2] = v20 )
  {
    if ( nodeIndex >= v15->m_nodeIndex )
      break;
    v20 = *v15--;
  }
  v15[1].m_value = minPosition;
  v15[1].m_nodeIndex = nodeIndex;
  *minInsertPositionOut = ((__int64)(unsigned int)((_DWORD)v15 - LODWORD(this->m_endPoints.m_data)) >> 2) + 1;
}

// File Line: 1140
// RVA: 0xD05690
void __fastcall hkp3AxisSweep::hkpBpAxis::remove(hkp3AxisSweep::hkpBpAxis *this, int minPosition, int maxPosition)
{
  hkp3AxisSweep::hkpBpEndPoint *v3; // r9
  hkp3AxisSweep::hkpBpEndPoint *v5; // rdx
  hkp3AxisSweep::hkpBpEndPoint *v6; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v7; // rdi
  unsigned __int64 v8; // rdx
  unsigned __int64 i; // rcx
  hkp3AxisSweep::hkpBpEndPoint *m_data; // rax
  int v11; // edx
  hkp3AxisSweep::hkpBpEndPoint *v12; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v13; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v14; // rdi
  unsigned __int64 j; // rcx

  v3 = &this->m_endPoints.m_data[minPosition];
  v5 = &this->m_endPoints.m_data[maxPosition - 1];
  if ( v3 < v5 )
  {
    v6 = v3 + 1;
    v7 = v3;
    v8 = ((unsigned __int64)((char *)v5 - (char *)v3 - 1) >> 2) + 1;
    for ( i = v8; i; --i )
      *v7++ = *v6++;
    v3 += v8;
  }
  m_data = this->m_endPoints.m_data;
  v11 = this->m_endPoints.m_size - 2;
  this->m_endPoints.m_size = v11;
  v12 = &m_data[v11];
  if ( v3 < v12 )
  {
    v13 = v3 + 2;
    v14 = v3;
    for ( j = ((unsigned __int64)((char *)v12 - (char *)v3 - 1) >> 2) + 1; j; --j )
      *v14++ = *v13++;
  }
}

// File Line: 1162
// RVA: 0xD06C90
unsigned __int16 __fastcall calcOffset(unsigned __int16 x, unsigned __int16 mi, unsigned __int16 ma)
{
  return (ma < (unsigned int)x) + (mi < (unsigned int)x);
}

// File Line: 1171
// RVA: 0xD06CC0
unsigned __int16 __fastcall calcOffset2(unsigned __int16 x, unsigned __int16 mi, unsigned __int16 shift)
{
  return (unsigned __int8)shift & (mi < (unsigned int)x);
}

// File Line: 1230
// RVA: 0xD05E20
void __fastcall hkp3AxisSweep::updateNodesAfterInsert(
        hkp3AxisSweep *this,
        hkp3AxisSweep::hkpBpNode *nodes,
        int numNodes,
        hkp3AxisSweep::hkpBpNode *newNode)
{
  unsigned __int16 v5; // r10
  unsigned __int16 v6; // r11
  unsigned __int16 v7; // bx
  hkp3AxisSweep::hkpBpNode *v8; // rbp
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // di
  unsigned __int16 v11; // r9
  int v12; // eax
  int v13; // r9d
  unsigned __int16 *p_max_x; // r8
  int v15; // r14d
  int v16; // edx
  unsigned __int16 v17; // cx
  int v18; // edx
  unsigned __int16 v19; // cx
  int v20; // edx
  unsigned __int16 v21; // cx
  int v22; // edx
  unsigned __int16 v23; // cx
  int v24; // edx
  unsigned __int16 v25; // cx
  int v26; // edx
  int v27; // [rsp+58h] [rbp+10h]

  v5 = newNode->min_x - 1;
  v6 = newNode->min_y - 1;
  v7 = newNode->min_z - 1;
  v8 = &nodes[numNodes];
  v9 = newNode->max_x - 2;
  v10 = newNode->max_y - 2;
  v11 = newNode->max_z - 2;
  if ( nodes < v8 )
  {
    v27 = v11;
    v12 = v11;
    v13 = v9;
    p_max_x = &nodes->max_x;
    v15 = v9;
    do
    {
      v16 = *(p_max_x - 1);
      p_max_x += 12;
      v17 = v16 + ((unsigned int)(v15 - v16) >> 31) + (((unsigned int)v5 - v16) >> 31);
      v18 = *(p_max_x - 17);
      *(p_max_x - 13) = v17;
      v19 = v18 + (((unsigned int)v10 - v18) >> 31) + (((unsigned int)v6 - v18) >> 31);
      v20 = *(p_max_x - 12);
      *(p_max_x - 17) = v19;
      v21 = v20 + ((unsigned int)(v13 - v20) >> 31) + (((unsigned int)v5 - v20) >> 31);
      v22 = *(p_max_x - 15);
      *(p_max_x - 12) = v21;
      v23 = v22 + (((unsigned int)v10 - v22) >> 31) + (((unsigned int)v6 - v22) >> 31);
      v24 = *(p_max_x - 16);
      *(p_max_x - 15) = v23;
      v25 = v24 + ((unsigned int)(v27 - v24) >> 31) + (((unsigned int)v7 - v24) >> 31);
      v26 = *(p_max_x - 14);
      *(p_max_x - 16) = v25;
      *(p_max_x - 14) = v26 + ((unsigned int)(v12 - v26) >> 31) + (((unsigned int)v7 - v26) >> 31);
    }
    while ( p_max_x - 5 < (unsigned __int16 *)v8 );
  }
}

// File Line: 1391
// RVA: 0xD04EE0
void __fastcall hkp3AxisSweep::collide1Axis(
        hkp3AxisSweep *this,
        hkp3AxisSweep::hkpBpNode *pa,
        int numA,
        hkp3AxisSweep::hkpBpNode *pb,
        int numB,
        hkp3AxisSweep::MarkerHandling markerHandlingForNodesB,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut)
{
  hkpBroadPhaseHandle **p_m_handle; // r15
  unsigned __int16 *p_min_x; // r12
  unsigned __int16 v9; // ax
  unsigned int v10; // r14d
  unsigned __int16 *v11; // rsi
  int v12; // edi
  char *v13; // r8
  char *v14; // rbx
  __int64 v15; // r10
  int v16; // ecx
  __int64 v17; // rdx
  _WORD *v18; // rax
  hkpBroadPhaseHandlePair *v19; // rcx
  unsigned int v20; // eax
  bool v21; // cc
  unsigned int v22; // r14d
  hkpBroadPhaseHandle **v23; // rdi
  int v24; // esi
  char *v25; // r8
  char *v26; // rbx
  __int64 v27; // r10
  int v28; // ecx
  __int64 v29; // rdx
  _WORD *v30; // rax
  hkpBroadPhaseHandlePair *v31; // rcx
  unsigned int v32; // eax
  hkp3AxisSweep::hkpBpMarker *m_markers; // [rsp+70h] [rbp+8h]
  hkpBroadPhaseHandle **v34; // [rsp+78h] [rbp+10h]
  int v35; // [rsp+80h] [rbp+18h]
  unsigned __int16 *v36; // [rsp+88h] [rbp+20h]

  v35 = numA;
  p_m_handle = &pb->m_handle;
  p_min_x = &pa->min_x;
  m_markers = this->m_markers;
  v34 = &pb->m_handle;
  v36 = &pa->min_x;
  do
  {
    v9 = *((_WORD *)p_m_handle - 4);
    if ( *p_min_x <= v9 )
    {
      v22 = p_min_x[1];
      if ( v9 < v22 )
      {
        v23 = p_m_handle;
        do
        {
          if ( (((*((_DWORD *)p_min_x - 1) - *((_DWORD *)v23 - 4)) | (*((_DWORD *)v23 - 3) - *((_DWORD *)p_min_x - 2))) & 0x80008000) == 0 )
          {
            if ( (*(_BYTE *)v23 & 1) != 0 )
            {
              if ( markerHandlingForNodesB != MARKERS_IGNORE )
              {
                v24 = **((_DWORD **)p_min_x + 1);
                v25 = (char *)m_markers + ((unsigned __int64)*v23 & 0xFFFFFFFFFFFFFFFEui64);
                if ( markerHandlingForNodesB )
                {
                  v27 = *((int *)v25 + 4);
                  v28 = 0;
                  v29 = 0i64;
                  if ( (int)v27 <= 0 )
                  {
LABEL_38:
                    v28 = -1;
                    v29 = -1i64;
                  }
                  else
                  {
                    v30 = (_WORD *)*((_QWORD *)v25 + 1);
                    while ( *v30 != (_WORD)v24 )
                    {
                      ++v29;
                      ++v28;
                      ++v30;
                      if ( v29 >= v27 )
                        goto LABEL_38;
                    }
                  }
                  *((_DWORD *)v25 + 4) = v27 - 1;
                  if ( (_DWORD)v27 - 1 != v28 )
                    *(_WORD *)(*((_QWORD *)v25 + 1) + 2 * v29) = *(_WORD *)(*((_QWORD *)v25 + 1) + 2i64 * ((int)v27 - 1));
                }
                else
                {
                  v26 = v25 + 8;
                  if ( *((_DWORD *)v25 + 4) == (*((_DWORD *)v25 + 5) & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v26, 2);
                  *(_WORD *)(*(_QWORD *)v26 + 2i64 * (int)(*((_DWORD *)v26 + 2))++) = v24;
                }
              }
            }
            else
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 16);
              v31 = &pairsOut->m_data[pairsOut->m_size++];
              v31->m_a = (hkpBroadPhaseHandle *)*((_QWORD *)p_min_x + 1);
              v31->m_b = *v23;
            }
          }
          v32 = *((unsigned __int16 *)v23 + 8);
          v23 += 3;
        }
        while ( v32 < v22 );
        p_m_handle = v34;
        numA = v35;
      }
      p_min_x += 12;
      --numA;
      v36 = p_min_x;
      v35 = numA;
      v21 = numA <= 0;
    }
    else
    {
      v10 = *((unsigned __int16 *)p_m_handle - 3);
      if ( *p_min_x < v10 )
      {
        v11 = p_min_x + 4;
        do
        {
          if ( (((*((_DWORD *)p_m_handle - 3) - *((_DWORD *)v11 - 4)) | (*((_DWORD *)v11 - 3)
                                                                       - *((_DWORD *)p_m_handle - 4))) & 0x80008000) == 0 )
          {
            if ( (*(_BYTE *)p_m_handle & 1) != 0 )
            {
              if ( markerHandlingForNodesB != MARKERS_IGNORE )
              {
                v12 = **(_DWORD **)v11;
                v13 = (char *)m_markers + ((unsigned __int64)*p_m_handle & 0xFFFFFFFFFFFFFFFEui64);
                if ( markerHandlingForNodesB )
                {
                  v15 = *((int *)v13 + 4);
                  v16 = 0;
                  v17 = 0i64;
                  if ( (int)v15 <= 0 )
                  {
LABEL_16:
                    v16 = -1;
                    v17 = -1i64;
                  }
                  else
                  {
                    v18 = (_WORD *)*((_QWORD *)v13 + 1);
                    while ( *v18 != (_WORD)v12 )
                    {
                      ++v17;
                      ++v16;
                      ++v18;
                      if ( v17 >= v15 )
                        goto LABEL_16;
                    }
                  }
                  *((_DWORD *)v13 + 4) = v15 - 1;
                  if ( (_DWORD)v15 - 1 != v16 )
                    *(_WORD *)(*((_QWORD *)v13 + 1) + 2 * v17) = *(_WORD *)(*((_QWORD *)v13 + 1) + 2i64 * ((int)v15 - 1));
                }
                else
                {
                  v14 = v13 + 8;
                  if ( *((_DWORD *)v13 + 4) == (*((_DWORD *)v13 + 5) & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v14, 2);
                  *(_WORD *)(*(_QWORD *)v14 + 2i64 * (int)(*((_DWORD *)v14 + 2))++) = v12;
                }
              }
            }
            else
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 16);
              v19 = &pairsOut->m_data[pairsOut->m_size++];
              v19->m_a = *(hkpBroadPhaseHandle **)v11;
              v19->m_b = *p_m_handle;
            }
          }
          v20 = v11[8];
          v11 += 12;
        }
        while ( v20 < v10 );
        p_min_x = v36;
        numA = v35;
      }
      p_m_handle += 3;
      v34 = p_m_handle;
      v21 = --numB <= 0;
    }
  }
  while ( !v21 );
}

// File Line: 1424
// RVA: 0xD05240
void __fastcall hkp3AxisSweep::collide1Axis(
        hkp3AxisSweep *this,
        hkp3AxisSweep::hkpBpNode *pa,
        int numA,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut)
{
  int v4; // r14d
  hkpBroadPhaseHandle **p_m_handle; // rsi
  unsigned int v7; // ebp
  hkpBroadPhaseHandle **v8; // rbx
  hkpBroadPhaseHandlePair *v9; // rcx
  unsigned int v10; // eax

  v4 = numA - 1;
  if ( numA - 1 > 0 )
  {
    p_m_handle = &pa[1].m_handle;
    do
    {
      v7 = *((unsigned __int16 *)p_m_handle - 15);
      if ( *((unsigned __int16 *)p_m_handle - 4) < v7 )
      {
        v8 = p_m_handle;
        do
        {
          if ( (((*((_DWORD *)p_m_handle - 9) - *((_DWORD *)v8 - 4)) | (*((_DWORD *)v8 - 3)
                                                                      - *((_DWORD *)p_m_handle - 10))) & 0x80008000) == 0
            && (*(_BYTE *)v8 & 1) == 0 )
          {
            if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 16);
            v9 = &pairsOut->m_data[pairsOut->m_size++];
            v9->m_a = *(p_m_handle - 3);
            v9->m_b = *v8;
          }
          v10 = *((unsigned __int16 *)v8 + 8);
          v8 += 3;
        }
        while ( v10 < v7 );
      }
      --v4;
      p_m_handle += 3;
    }
    while ( v4 > 0 );
  }
}

// File Line: 1445
// RVA: 0xD06190
void __fastcall hkp3AxisSweep::updateNodesAfterBatchTailInsert(
        hkp3AxisSweep *this,
        hkp3AxisSweep::hkpBpNode *nodes,
        int numNodes,
        unsigned __int8 numNewEndPoints,
        int *offsets)
{
  unsigned __int16 v6; // r10
  unsigned __int16 v7; // r11
  unsigned __int16 v8; // r9
  hkp3AxisSweep::hkpBpNode *v9; // r8
  unsigned __int16 *p_max_x; // rax
  int v11; // edx
  unsigned __int16 v12; // cx
  int v13; // edx
  unsigned __int16 v14; // cx
  int v15; // edx
  unsigned __int16 v16; // cx
  int v17; // edx
  unsigned __int16 v18; // cx
  int v19; // edx
  unsigned __int16 v20; // cx
  int v21; // edx

  v6 = *(_WORD *)offsets - 1;
  v7 = *((_WORD *)offsets + 2) - 1;
  v8 = *((_WORD *)offsets + 4) - 1;
  v9 = &nodes[numNodes];
  if ( nodes < v9 )
  {
    p_max_x = &nodes->max_x;
    do
    {
      v11 = *(p_max_x - 1);
      p_max_x += 12;
      v12 = v11 + (numNewEndPoints & (v6 - v11 < 0));
      v13 = *(p_max_x - 17);
      *(p_max_x - 13) = v12;
      v14 = v13 + (numNewEndPoints & (v7 - v13 < 0));
      v15 = *(p_max_x - 12);
      *(p_max_x - 17) = v14;
      v16 = v15 + (numNewEndPoints & (v6 - v15 < 0));
      v17 = *(p_max_x - 15);
      *(p_max_x - 12) = v16;
      v18 = v17 + (numNewEndPoints & (v7 - v17 < 0));
      v19 = *(p_max_x - 16);
      *(p_max_x - 15) = v18;
      v20 = v19 + (numNewEndPoints & (v8 - v19 < 0));
      v21 = *(p_max_x - 14);
      *(p_max_x - 16) = v20;
      *(p_max_x - 14) = v21 + (numNewEndPoints & (v8 - v21 < 0));
    }
    while ( p_max_x - 5 < (unsigned __int16 *)v9 );
  }
}

// File Line: 1571
// RVA: 0xD05FE0
void __fastcall hkp3AxisSweep::updateNodesAfterDelete(
        hkp3AxisSweep *this,
        hkp3AxisSweep::hkpBpNode *nodes,
        int numNodes,
        hkp3AxisSweep::hkpBpNode *oldNode)
{
  unsigned __int16 min_x; // r10
  unsigned __int16 min_y; // r11
  unsigned __int16 min_z; // bx
  unsigned __int16 max_x; // di
  unsigned __int16 max_y; // si
  unsigned __int16 max_z; // r9
  hkp3AxisSweep::hkpBpNode *v10; // rbp
  unsigned __int16 *p_max_x; // r8
  int v12; // edx
  __int16 v13; // cx
  unsigned int v14; // eax
  int v15; // edx
  __int16 v16; // cx
  unsigned int v17; // eax
  int v18; // edx
  __int16 v19; // cx
  unsigned int v20; // eax
  int v21; // edx
  __int16 v22; // cx
  unsigned int v23; // eax
  int v24; // edx
  __int16 v25; // cx
  unsigned int v26; // eax
  int v27; // edx

  min_x = oldNode->min_x;
  min_y = oldNode->min_y;
  min_z = oldNode->min_z;
  max_x = oldNode->max_x;
  max_y = oldNode->max_y;
  max_z = oldNode->max_z;
  v10 = &nodes[numNodes];
  if ( nodes != v10 )
  {
    p_max_x = &nodes->max_x;
    do
    {
      v12 = *(p_max_x - 1);
      p_max_x += 12;
      v13 = v12 - (((unsigned int)max_x - v12) >> 31);
      v14 = min_x - v12;
      v15 = *(p_max_x - 12);
      *(p_max_x - 13) = v13 - (v14 >> 31);
      v16 = v15 - (((unsigned int)min_x - v15) >> 31);
      v17 = max_x - v15;
      v18 = *(p_max_x - 17);
      *(p_max_x - 12) = v16 - (v17 >> 31);
      v19 = v18 - (((unsigned int)min_y - v18) >> 31);
      v20 = max_y - v18;
      v21 = *(p_max_x - 15);
      *(p_max_x - 17) = v19 - (v20 >> 31);
      v22 = v21 - (((unsigned int)min_y - v21) >> 31);
      v23 = max_y - v21;
      v24 = *(p_max_x - 16);
      *(p_max_x - 15) = v22 - (v23 >> 31);
      v25 = v24 - (((unsigned int)min_z - v24) >> 31);
      v26 = max_z - v24;
      v27 = *(p_max_x - 14);
      *(p_max_x - 16) = v25 - (v26 >> 31);
      *(p_max_x - 14) = v27 - (((unsigned int)min_z - v27) >> 31) - (((unsigned int)max_z - v27) >> 31);
    }
    while ( p_max_x - 5 != (unsigned __int16 *)v10 );
  }
}

// File Line: 1664
// RVA: 0xD062B0
void __fastcall hkp3AxisSweep::setBitsBasedOnXInterval(
        hkp3AxisSweep *this,
        int numNodes,
        int x_value,
        hkp3AxisSweep::hkpBpNode *queryNode,
        unsigned __int16 queryNodeIndex,
        unsigned int *bitField)
{
  __int64 max_x; // rbp
  int v7; // edx
  __int64 min_x; // rsi
  unsigned int *i; // r9
  unsigned int *v11; // rax
  hkp3AxisSweep::hkpBpEndPoint *m_data; // rdx
  hkp3AxisSweep::hkpBpEndPoint *v13; // rax
  int v14; // r8d
  hkp3AxisSweep::hkpBpMarker *v15; // rdi
  unsigned __int16 *v16; // r8
  int j; // r9d
  unsigned __int16 v18; // ax
  unsigned int *v19; // rdx
  hkp3AxisSweep::hkpBpNode *v20; // r11
  hkp3AxisSweep::hkpBpEndPoint *v21; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v22; // r8
  hkp3AxisSweep::hkpBpEndPoint *k; // r9
  hkp3AxisSweep::hkpBpEndPoint *m; // r9
  int m_nodeIndex; // ecx
  unsigned __int64 v26; // rax
  hkp3AxisSweep::hkpBpEndPoint *n; // r9

  max_x = queryNode->max_x;
  v7 = numNodes >> 7;
  min_x = queryNode->min_x;
  for ( i = bitField; v7 >= 0; *(_OWORD *)v11 = 0i64 )
  {
    v11 = i;
    i += 4;
    --v7;
  }
  m_data = this->m_axis[0].m_endPoints.m_data;
  v13 = m_data + 1;
  if ( this->m_numMarkers )
  {
    v14 = x_value >> (16 - LOBYTE(this->m_ld2NumMarkers));
    if ( v14 > 0 )
    {
      v15 = &this->m_markers[v14 - 1];
      bitField[(int)v15->m_nodeIndex >> 5] ^= 1 << (v15->m_nodeIndex & 0x1F);
      v16 = v15->m_overlappingObjects.m_data;
      for ( j = v15->m_overlappingObjects.m_size - 1; j >= 0; --j )
      {
        v18 = *v16;
        if ( *v16 != queryNodeIndex )
        {
          v19 = &bitField[(int)v18 >> 5];
          *v19 ^= 1 << (v18 & 0x1F);
        }
        ++v16;
      }
      v20 = &this->m_nodes.m_data[v15->m_nodeIndex];
      v21 = this->m_axis[0].m_endPoints.m_data;
      v22 = &v21[v20->min_x + 1];
      for ( k = &v21[v20->max_x]; v22 < k; ++v22 )
      {
        if ( (v22->m_value & 1) == 0 )
          bitField[(int)v22->m_nodeIndex >> 5] &= ~(1 << (v22->m_nodeIndex & 0x1F));
      }
      m_data = this->m_axis[0].m_endPoints.m_data;
      v13 = &m_data[v20->min_x + 1];
    }
  }
  for ( m = &m_data[min_x]; v13 < m; bitField[m_nodeIndex >> 5] ^= 1 << (m_nodeIndex & 0x1F) )
  {
    m_nodeIndex = v13->m_nodeIndex;
    ++v13;
  }
  v26 = (unsigned __int64)&v13[1];
  for ( n = &this->m_axis[0].m_endPoints.m_data[max_x]; v26 < (unsigned __int64)n; v26 += 4i64 )
  {
    if ( (*(_BYTE *)v26 & 1) == 0 )
      bitField[(int)*(unsigned __int16 *)(v26 + 2) >> 5] ^= 1 << (*(_WORD *)(v26 + 2) & 0x1F);
  }
}

// File Line: 1740
// RVA: 0xD01C70
void __fastcall hkp3AxisSweep::reQuerySingleObject(
        hkp3AxisSweep *this,
        hkpBroadPhaseHandle *object,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  int m_size; // edi
  int v7; // eax
  unsigned int *bitField; // r10
  int v9; // ebp
  hkp3AxisSweep::hkpBpNode *v10; // r14
  hkp3AxisSweep::hkpBpEndPoint *m_data; // rax
  __int64 min_x; // rcx
  unsigned int *v13; // r15
  hkp3AxisSweep::hkpBpNode *v14; // r13
  unsigned int *v15; // rcx
  unsigned int *v16; // rax
  unsigned int v17; // ebx
  hkp3AxisSweep::hkpBpNode *v18; // rdi
  hkpBroadPhaseHandle *m_handle; // rbp
  hkpBroadPhaseHandlePair *v20; // rax
  unsigned __int16 queryNodeIndex; // [rsp+20h] [rbp-58h]
  unsigned int *v22; // [rsp+30h] [rbp-48h]
  int v23; // [rsp+80h] [rbp+8h] BYREF
  int v24; // [rsp+88h] [rbp+10h]
  unsigned int *v25; // [rsp+98h] [rbp+20h]

  m_size = this->m_nodes.m_size;
  v7 = (m_size >> 5) + 8;
  if ( m_size >> 5 == -8 )
  {
    bitField = 0i64;
  }
  else
  {
    v23 = 4 * v7;
    bitField = (unsigned int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                 &hkContainerTempAllocator::s_alloc,
                                 &v23);
    v7 = v23 / 4;
  }
  queryNodeIndex = object->m_id;
  v9 = 0x80000000;
  if ( v7 )
    v9 = v7;
  v10 = &this->m_nodes.m_data[object->m_id];
  m_data = this->m_axis[0].m_endPoints.m_data;
  v25 = bitField;
  min_x = v10->min_x;
  v24 = v9;
  v13 = bitField;
  hkp3AxisSweep::setBitsBasedOnXInterval(this, m_size, m_data[min_x].m_value, v10, queryNodeIndex, bitField);
  v14 = this->m_nodes.m_data;
  v15 = v13;
  v16 = &v13[((__int64)this->m_nodes.m_size >> 5) + 1];
  v22 = v16;
  if ( v13 < v16 )
  {
    do
    {
      v17 = *v13;
      v18 = v14;
      if ( *v13 )
      {
        do
        {
          if ( (_BYTE)v17 )
          {
            if ( (v17 & 1) != 0
              && (((*(_DWORD *)&v10->max_y - *(_DWORD *)&v18->min_y) | (*(_DWORD *)&v18->max_y - *(_DWORD *)&v10->min_y)) & 0x80008000) == 0
              && ((__int64)v18->m_handle & 1) == 0 )
            {
              m_handle = v18->m_handle;
              if ( pairs_out->m_size == (pairs_out->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairs_out->m_data, 16);
              v20 = &pairs_out->m_data[pairs_out->m_size];
              if ( v20 )
              {
                v20->m_a = object;
                v20->m_b = m_handle;
              }
              ++pairs_out->m_size;
            }
            ++v18;
            v17 >>= 1;
          }
          else
          {
            v18 += 8;
            v17 >>= 8;
          }
        }
        while ( v17 );
        v16 = v22;
      }
      ++v13;
      v14 += 32;
    }
    while ( v13 < v16 );
    v9 = v24;
    v15 = v25;
  }
  if ( v9 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v15, 4 * v9);
}

// File Line: 1789
// RVA: 0xD01E60
bool __fastcall hkp3AxisSweep::areAabbsOverlapping(
        hkp3AxisSweep *this,
        hkpBroadPhaseHandle *bhA,
        hkpBroadPhaseHandle *bhB)
{
  hkp3AxisSweep::hkpBpNode *m_data; // r9
  hkp3AxisSweep::hkpBpNode *v4; // rdx
  __int16 v5; // ax
  hkp3AxisSweep::hkpBpNode *v6; // r8

  m_data = this->m_nodes.m_data;
  v4 = &m_data[bhA->m_id];
  v5 = m_data[bhB->m_id].max_x - v4->min_x;
  v6 = &m_data[bhB->m_id];
  return (((v6->max_y - v4->min_y) | (v4->max_y - v6->min_y) | v5 | (v4->max_x - v6->min_x)) & 0x8000u) == 0
      && (((*(_DWORD *)&v6->max_y - *(_DWORD *)&v4->min_y) | (*(_DWORD *)&v4->max_y - *(_DWORD *)&v6->min_y)) & 0x80008000) == 0;
}

// File Line: 1848
// RVA: 0xCFCB60
void __fastcall hkp3AxisSweep::addObject(
        hkp3AxisSweep *this,
        hkpBroadPhaseHandle *object,
        hkAabbUint32 *aabbIn,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs,
        int border)
{
  unsigned int v6; // edi
  unsigned int v7; // r9d
  unsigned int v8; // r10d
  unsigned int v9; // r11d
  unsigned int v13; // r9d
  unsigned int v14; // r8d
  unsigned int v15; // r8d
  unsigned int v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // edi
  unsigned int v19; // r10d
  unsigned int v20; // r11d
  __int16 v21; // cx
  int v22; // eax
  __int16 v23; // ax
  __int16 v24; // ax
  __int16 v25; // ax
  __int16 v26; // ax
  int m_size; // r12d
  hkArray<hkp3AxisSweep::hkpBpNode,hkContainerHeapAllocator> *p_m_nodes; // rsi
  __int64 v29; // rdx
  hkp3AxisSweep::hkpBpNode *m_data; // rbx
  hkp3AxisSweep::hkpBpNode *minInsertPositionOut; // r13
  int v32; // ebx
  int v33; // eax
  unsigned int *v34; // rcx
  unsigned int v35; // edx
  unsigned int *v36; // rdx
  hkp3AxisSweep::hkpBpNode *v37; // rcx
  unsigned int *v38; // r15
  unsigned __int64 v39; // rax
  unsigned int v40; // esi
  hkp3AxisSweep::hkpBpNode *v41; // rbx
  hkpBroadPhaseHandle *m_handle; // rdi
  hkpBroadPhaseHandlePair *v43; // rax
  const void **v44; // rdi
  unsigned int *v45; // [rsp+40h] [rbp-78h]
  unsigned __int64 v47; // [rsp+50h] [rbp-68h]
  unsigned __int16 v48; // [rsp+60h] [rbp-58h]
  unsigned __int16 v49; // [rsp+64h] [rbp-54h]
  unsigned __int16 v50; // [rsp+68h] [rbp-50h]
  unsigned __int16 maxPosition; // [rsp+70h] [rbp-48h]
  unsigned __int16 v52; // [rsp+74h] [rbp-44h]
  unsigned __int16 v53; // [rsp+78h] [rbp-40h]
  int v54; // [rsp+C0h] [rbp+8h]
  unsigned int *v55; // [rsp+C8h] [rbp+10h]
  hkp3AxisSweep::hkpBpNode *v56; // [rsp+D0h] [rbp+18h]

  v6 = aabbIn->m_min[0] >> 15;
  v7 = aabbIn->m_max[0] >> 15;
  v8 = aabbIn->m_min[1] >> 15;
  v9 = aabbIn->m_min[2] >> 15;
  if ( v7 != 0xFFFF )
    ++v7;
  v13 = v7 | 1;
  v14 = aabbIn->m_max[1] >> 15;
  maxPosition = v13;
  if ( v14 != 0xFFFF )
    ++v14;
  v15 = v14 | 1;
  v16 = aabbIn->m_max[2] >> 15;
  v52 = v15;
  if ( v16 != 0xFFFF )
    ++v16;
  v17 = v16 | 1;
  v18 = v6 & 0xFFFE;
  v19 = v8 & 0xFFFE;
  v20 = v9 & 0xFFFE;
  v53 = v17;
  v48 = v18;
  v55 = 0i64;
  v49 = v19;
  v50 = v20;
  if ( (_BYTE)border )
  {
    v21 = -4;
    v22 = 65532;
    if ( v18 < 0x7FFE )
      v22 = 0;
    v18 = v22;
    v48 = v22;
    v23 = -4;
    if ( v13 < 0x7FFE )
      v23 = 0;
    maxPosition = v23 + 1;
    v24 = -4;
    if ( v19 < 0x7FFE )
      v24 = 0;
    v49 = v24;
    v25 = -4;
    if ( v15 < 0x7FFE )
      v25 = 0;
    v52 = v25 + 1;
    v26 = -4;
    if ( v20 < 0x7FFE )
      v26 = 0;
    if ( v17 < 0x7FFE )
      v21 = 0;
    v50 = v26;
    v53 = v21 + 1;
  }
  m_size = this->m_nodes.m_size;
  p_m_nodes = &this->m_nodes;
  if ( m_size == (this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, 24);
  v29 = this->m_nodes.m_size;
  m_data = p_m_nodes->m_data;
  minInsertPositionOut = &p_m_nodes->m_data[v29];
  this->m_nodes.m_size = v29 + 1;
  hkp3AxisSweep::hkpBpAxis::insert(
    this->m_axis,
    m_data,
    m_size,
    v48,
    maxPosition,
    &minInsertPositionOut->min_x,
    &minInsertPositionOut->max_x);
  hkp3AxisSweep::hkpBpAxis::insert(
    &this->m_axis[1],
    m_data,
    m_size,
    v49,
    v52,
    &minInsertPositionOut->min_y,
    &minInsertPositionOut->max_y);
  hkp3AxisSweep::hkpBpAxis::insert(
    &this->m_axis[2],
    m_data,
    m_size,
    v50,
    v53,
    &minInsertPositionOut->min_z,
    &minInsertPositionOut->max_z);
  hkp3AxisSweep::updateNodesAfterInsert(this, m_data, m_size, minInsertPositionOut);
  minInsertPositionOut->m_handle = object;
  object->m_id = m_size;
  v32 = this->m_nodes.m_size;
  v33 = (v32 >> 5) + 8;
  if ( v32 >> 5 == -8 )
  {
    v34 = 0i64;
  }
  else
  {
    border = 4 * v33;
    v34 = (unsigned int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &border);
    v55 = v34;
    v33 = border / 4;
  }
  v35 = 0x80000000;
  if ( v33 )
    v35 = v33;
  v54 = v35;
  hkp3AxisSweep::setBitsBasedOnXInterval(this, v32, v18, minInsertPositionOut, m_size, v34);
  v36 = v55;
  v37 = p_m_nodes->m_data;
  v38 = v55;
  v45 = v55;
  v56 = p_m_nodes->m_data;
  v39 = (unsigned __int64)&v55[((__int64)this->m_nodes.m_size >> 5) + 1];
  v47 = v39;
  if ( (unsigned __int64)v55 < v39 )
  {
    do
    {
      v40 = *v38;
      v41 = v37;
      if ( *v38 )
      {
        do
        {
          if ( (_BYTE)v40 )
          {
            if ( (v40 & 1) != 0
              && (((*(_DWORD *)&minInsertPositionOut->max_y - *(_DWORD *)&v41->min_y) | (*(_DWORD *)&v41->max_y
                                                                                       - *(_DWORD *)&minInsertPositionOut->min_y)) & 0x80008000) == 0 )
            {
              m_handle = v41->m_handle;
              if ( ((unsigned __int8)m_handle & 1) != 0 )
              {
                v44 = (const void **)((char *)this->m_markers + ((unsigned __int64)m_handle & 0xFFFFFFFFFFFFFFFEui64));
                if ( *((_DWORD *)v44 + 4) == (*((_DWORD *)v44 + 5) & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v44 + 1, 2);
                *((_WORD *)v44[1] + (int)(*((_DWORD *)v44 + 4))++) = m_size;
              }
              else
              {
                if ( newPairs->m_size == (newPairs->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&newPairs->m_data, 16);
                v43 = &newPairs->m_data[newPairs->m_size];
                if ( v43 )
                {
                  v43->m_a = object;
                  v43->m_b = m_handle;
                }
                ++newPairs->m_size;
              }
            }
            ++v41;
            v40 >>= 1;
          }
          else
          {
            v41 += 8;
            v40 >>= 8;
          }
        }
        while ( v40 );
        v38 = v45;
        v37 = v56;
        v39 = v47;
      }
      ++v38;
      v37 += 32;
      v56 = v37;
      v45 = v38;
    }
    while ( (unsigned __int64)v38 < v39 );
    v36 = v55;
  }
  if ( v54 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v36, 4 * v54);
}

// File Line: 1908
// RVA: 0xCFCFB0
void __fastcall hkp3AxisSweep::addObject(
        hkp3AxisSweep *this,
        hkpBroadPhaseHandle *object,
        hkAabb *aabbIn,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs,
        bool border)
{
  hkBaseObjectVtbl *vfptr; // r10
  __m128 v6; // xmm4
  __m128 v7; // xmm8
  __m128i v8; // xmm0
  __m128 v9; // xmm3
  __m128 v10; // xmm3
  __m128i v11; // xmm0
  __int128 v13[2]; // [rsp+30h] [rbp-48h] BYREF

  vfptr = this->vfptr;
  v6 = _mm_max_ps(
         _mm_min_ps(
           _mm_mul_ps(_mm_add_ps(this->m_offsetLow32bit.m_quad, aabbIn->m_min.m_quad), this->m_scale32bit.m_quad),
           hkAabbUtil::hkAabbUint32MaxVal),
         (__m128)0i64);
  v7 = _mm_add_ps(
         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
  v8 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v6);
  v9 = _mm_add_ps(this->m_offsetHigh32bit.m_quad, aabbIn->m_max.m_quad);
  v13[0] = (__int128)_mm_or_si128(
                       _mm_add_epi32(
                         _mm_cvttps_epi32(
                           _mm_max_ps(
                             _mm_sub_ps(
                               v6,
                               _mm_and_ps((__m128)v8, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                             (__m128)0i64)),
                         _mm_slli_epi32(v8, 0x1Fu)),
                       (__m128i)_mm_cmple_ps(v7, v6));
  v10 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(v9, this->m_scale32bit.m_quad), hkAabbUtil::hkAabbUint32MaxVal), (__m128)0i64);
  v11 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v10);
  v13[1] = (__int128)_mm_or_si128(
                       _mm_add_epi32(
                         _mm_cvttps_epi32(
                           _mm_max_ps(
                             _mm_sub_ps(
                               v10,
                               _mm_and_ps((__m128)v11, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                             (__m128)0i64)),
                         _mm_slli_epi32(v11, 0x1Fu)),
                       (__m128i)_mm_cmple_ps(v7, v10));
  ((void (__fastcall *)(hkp3AxisSweep *, hkpBroadPhaseHandle *, __int128 *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, bool))vfptr[3].__vecDelDtor)(
    this,
    object,
    v13,
    newPairs,
    border);
}

// File Line: 1992
// RVA: 0xCFE120
void __fastcall hkp3AxisSweep::removeObject(
        hkp3AxisSweep *this,
        hkpBroadPhaseHandle *object,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairsOut)
{
  unsigned int m_size; // r12d
  __int64 queryNodeIndex; // r14
  hkp3AxisSweep::hkpBpNode *v6; // r15
  __int32 v8; // eax
  unsigned int *bitField; // rdi
  hkp3AxisSweep::hkpBpAxis *m_axis; // rsi
  int v11; // ebx
  int m_value; // r8d
  hkp3AxisSweep::hkpBpNode *m_data; // rcx
  unsigned int *v14; // r12
  unsigned int *v15; // rax
  unsigned int v16; // edi
  hkp3AxisSweep::hkpBpNode *v17; // rbx
  hkpBroadPhaseHandle *m_handle; // rsi
  hkpBroadPhaseHandlePair *v19; // rax
  int v20; // ecx
  __int64 v21; // rdx
  char *v22; // r9
  __int64 v23; // r10
  _WORD *v24; // rax
  hkArray<hkp3AxisSweep::hkpBpNode,hkContainerHeapAllocator> *p_m_nodes; // rbp
  hkp3AxisSweep::hkpBpNode *v26; // rbx
  int v27; // r12d
  hkp3AxisSweep::hkpBpNode *v28; // rcx
  __int64 min_x; // r10
  hkp3AxisSweep::hkpBpEndPoint *v30; // r11
  char v31; // cl
  int v32; // r9d
  int v33; // edx
  __int64 v34; // r10
  __int64 v35; // r11
  hkp3AxisSweep::hkpBpMarker *m_markers; // r9
  __int64 v37; // rcx
  __int64 v38; // rdx
  unsigned __int16 *v39; // rax
  unsigned __int16 *v40; // rax
  int v41; // ebx
  int v42; // eax
  int v43; // eax
  int v44; // r9d
  hkp3AxisSweep::hkpBpNode *v45; // [rsp+30h] [rbp-68h]
  unsigned int *v46; // [rsp+38h] [rbp-60h]
  unsigned int *v47; // [rsp+40h] [rbp-58h]
  unsigned int *v49; // [rsp+50h] [rbp-48h]
  hkResult result; // [rsp+A0h] [rbp+8h] BYREF
  int v51; // [rsp+A8h] [rbp+10h]
  int numNodes; // [rsp+B8h] [rbp+20h]

  m_size = this->m_nodes.m_size;
  queryNodeIndex = (int)object->m_id;
  v6 = &this->m_nodes.m_data[queryNodeIndex];
  numNodes = m_size;
  v8 = (m_size >> 5) + 8;
  if ( m_size >> 5 == -8 )
  {
    bitField = 0i64;
  }
  else
  {
    result.m_enum = 4 * v8;
    bitField = (unsigned int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                 &hkContainerTempAllocator::s_alloc,
                                 &result);
    v8 = result.m_enum / 4;
  }
  m_axis = this->m_axis;
  v11 = 0x80000000;
  if ( v8 )
    v11 = v8;
  m_value = m_axis->m_endPoints.m_data[v6->min_x].m_value;
  v47 = bitField;
  v51 = v11;
  hkp3AxisSweep::setBitsBasedOnXInterval(this, m_size, m_value, v6, queryNodeIndex, bitField);
  m_data = this->m_nodes.m_data;
  v14 = bitField;
  v46 = bitField;
  v45 = m_data;
  v15 = &bitField[((__int64)this->m_nodes.m_size >> 5) + 1];
  v49 = v15;
  if ( bitField < v15 )
  {
    do
    {
      v16 = *v14;
      v17 = m_data;
      if ( *v14 )
      {
        do
        {
          if ( (_BYTE)v16 )
          {
            if ( (v16 & 1) != 0
              && (((*(_DWORD *)&v17->max_y - *(_DWORD *)&v6->min_y) | (*(_DWORD *)&v6->max_y - *(_DWORD *)&v17->min_y)) & 0x80008000) == 0 )
            {
              if ( ((__int64)v17->m_handle & 1) != 0 )
              {
                v20 = 0;
                v21 = 0i64;
                v22 = (char *)this->m_markers + ((unsigned __int64)v17->m_handle & 0xFFFFFFFFFFFFFFFEui64);
                v23 = *((int *)v22 + 4);
                if ( (int)v23 <= 0 )
                {
LABEL_22:
                  v20 = -1;
                  v21 = -1i64;
                }
                else
                {
                  v24 = (_WORD *)*((_QWORD *)v22 + 1);
                  while ( *v24 != (_WORD)queryNodeIndex )
                  {
                    ++v21;
                    ++v20;
                    ++v24;
                    if ( v21 >= v23 )
                      goto LABEL_22;
                  }
                }
                *((_DWORD *)v22 + 4) = v23 - 1;
                if ( (_DWORD)v23 - 1 != v20 )
                  *(_WORD *)(*((_QWORD *)v22 + 1) + 2 * v21) = *(_WORD *)(*((_QWORD *)v22 + 1) + 2i64 * ((int)v23 - 1));
              }
              else
              {
                m_handle = v17->m_handle;
                if ( delPairsOut->m_size == (delPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&delPairsOut->m_data, 16);
                v19 = &delPairsOut->m_data[delPairsOut->m_size];
                if ( v19 )
                {
                  v19->m_a = object;
                  v19->m_b = m_handle;
                }
                ++delPairsOut->m_size;
              }
            }
            ++v17;
            v16 >>= 1;
          }
          else
          {
            v17 += 8;
            v16 >>= 8;
          }
        }
        while ( v16 );
        v14 = v46;
        m_data = v45;
        v15 = v49;
      }
      ++v14;
      m_data += 32;
      v45 = m_data;
      v46 = v14;
    }
    while ( v14 < v15 );
    v11 = v51;
    bitField = v47;
    m_axis = this->m_axis;
  }
  if ( v11 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, bitField, 4 * v11);
  p_m_nodes = &this->m_nodes;
  v26 = this->m_nodes.m_data;
  hkp3AxisSweep::hkpBpAxis::remove(m_axis, v6->min_x, v6->max_x);
  hkp3AxisSweep::hkpBpAxis::remove(&this->m_axis[1], v6->min_y, v6->max_y);
  hkp3AxisSweep::hkpBpAxis::remove(&this->m_axis[2], v6->min_z, v6->max_z);
  v27 = numNodes;
  hkp3AxisSweep::updateNodesAfterDelete(this, v26, numNodes, v6);
  if ( (unsigned int)queryNodeIndex < v27 - 1 )
  {
    v28 = &p_m_nodes->m_data[v27 - 1];
    *(_QWORD *)&v6->min_y = *(_QWORD *)&v28->min_y;
    *(_QWORD *)&v6->min_x = *(_QWORD *)&v28->min_x;
    v6->m_handle = v28->m_handle;
    this->m_axis[0].m_endPoints.m_data[v6->min_x].m_nodeIndex = queryNodeIndex;
    this->m_axis[0].m_endPoints.m_data[v6->max_x].m_nodeIndex = queryNodeIndex;
    if ( ((__int64)v6->m_handle & 1) != 0 )
    {
      *(unsigned __int16 *)((char *)&this->m_markers->m_nodeIndex
                          + ((unsigned __int64)v6->m_handle & 0xFFFFFFFFFFFFFFFEui64)) = queryNodeIndex;
    }
    else
    {
      this->m_axis[1].m_endPoints.m_data[v6->min_y].m_nodeIndex = queryNodeIndex;
      this->m_axis[1].m_endPoints.m_data[v6->max_y].m_nodeIndex = queryNodeIndex;
      this->m_axis[2].m_endPoints.m_data[v6->min_z].m_nodeIndex = queryNodeIndex;
      this->m_axis[2].m_endPoints.m_data[v6->max_z].m_nodeIndex = queryNodeIndex;
      v6->m_handle->m_id = queryNodeIndex;
    }
    if ( this->m_numMarkers && ((__int64)v6->m_handle & 1) == 0 )
    {
      min_x = v6->min_x;
      v30 = this->m_axis[0].m_endPoints.m_data;
      v31 = 16 - LOBYTE(this->m_ld2NumMarkers);
      v32 = v30[min_x].m_value >> v31;
      if ( v32 && p_m_nodes->m_data[this->m_markers[v32 - 1].m_nodeIndex].max_x > (unsigned __int16)min_x )
        --v32;
      v33 = (v30[v6->max_x].m_value >> v31) - 1;
      if ( v32 <= (__int64)v33 )
      {
        v34 = v32;
        v35 = v33 - (__int64)v32 + 1;
        do
        {
          m_markers = this->m_markers;
          v37 = 0i64;
          v38 = m_markers[v34].m_overlappingObjects.m_size;
          if ( v38 <= 0 )
          {
LABEL_47:
            v37 = -1i64;
          }
          else
          {
            v39 = m_markers[v34].m_overlappingObjects.m_data;
            while ( *v39 != (_WORD)v27 - 1 )
            {
              ++v37;
              ++v39;
              if ( v37 >= v38 )
                goto LABEL_47;
            }
          }
          v40 = m_markers[v34++].m_overlappingObjects.m_data;
          v40[v37] = queryNodeIndex;
          --v35;
        }
        while ( v35 );
      }
    }
    hkp3AxisSweep::_fixDeterministicOrderAfterNodeIdWasDecreased(this, queryNodeIndex);
  }
  v41 = v27 - 1;
  v42 = this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v42 < v27 - 1 )
  {
    v43 = 2 * v42;
    v44 = v27 - 1;
    if ( v41 < v43 )
      v44 = v43;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, v44, 24);
  }
  this->m_nodes.m_size = v41;
}- 1 )
  {
    v43 = 2 * v42;
    v44 = v27 - 1;
    if ( v41 < v43 )
      v44 = v43;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, v44, 

// File Line: 2095
// RVA: 0xD05720
__int64 __fastcall hkp3AxisSweep::hkpBpAxis::insertTail(
        hkp3AxisSweep::hkpBpAxis *this,
        hkp3AxisSweep::hkpBpNode *nodes,
        int axis,
        hkp3AxisSweep::hkpBpEndPoint *newNodes,
        int numNewEndPoints)
{
  __int64 m_size; // r14
  __int64 v6; // rbp
  int v7; // edi
  int v8; // eax
  __int64 v10; // r12
  int v13; // eax
  int v14; // r9d
  int m_value; // r10d
  hkp3AxisSweep::hkpBpEndPoint *v16; // r11
  hkp3AxisSweep::hkpBpEndPoint *v17; // rax
  hkp3AxisSweep::hkpBpEndPoint v18; // ecx
  hkp3AxisSweep::hkpBpEndPoint *v19; // r11
  __int64 v20; // r9
  hkp3AxisSweep::hkpBpEndPoint *v21; // rax
  int v22; // ebp
  unsigned __int16 *p_m_value; // r10
  int v24; // ecx

  m_size = this->m_endPoints.m_size;
  v6 = numNewEndPoints;
  v7 = m_size + numNewEndPoints;
  v8 = this->m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = axis;
  if ( v8 < (int)m_size + numNewEndPoints )
  {
    v13 = 2 * v8;
    v14 = m_size + numNewEndPoints;
    if ( v7 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      (hkResult *)&numNewEndPoints,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_endPoints.m_data,
      v14,
      4);
  }
  this->m_endPoints.m_size = v7;
  m_value = newNodes[v6 - 1].m_value;
  v16 = &this->m_endPoints.m_data[m_size];
  v17 = &this->m_endPoints.m_data[v7];
  _mm_prefetch((const char *)&v17[-1], 0);
  _mm_prefetch((const char *)&v17[-129], 0);
  _mm_prefetch((const char *)&v16[-1], 0);
  _mm_prefetch((const char *)&v17[-129], 0);
  v18 = v16[-1];
  v19 = v16 - 2;
  v17[-1] = v18;
  v20 = (__int64)(unsigned int)((_DWORD)v17 - 4 - LODWORD(this->m_endPoints.m_data)) >> 2;
  v21 = v17 - 2;
  v22 = m_value;
  *(unsigned __int16 *)((char *)&nodes[v19[1].m_nodeIndex].min_y
                      + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2 * v10 + (v19[1].m_value & 1)]) = v20;
  if ( v19->m_value > m_value )
  {
    p_m_value = &v19[-128].m_value;
    do
    {
      *v21 = *v19;
      _mm_prefetch((const char *)p_m_value, 0);
      *(unsigned __int16 *)((char *)&nodes[p_m_value[257]].min_y
                          + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2 * v10 + (v19->m_value & 1)]) = (__int64)(unsigned int)((_DWORD)v21 - LODWORD(this->m_endPoints.m_data)) >> 2;
      _mm_prefetch((const char *)p_m_value, 0);
      v24 = v19[-1].m_value;
      --v19;
      --v21;
      p_m_value -= 2;
    }
    while ( v24 > v22 );
  }
  return v21 - this->m_endPoints.m_data + 1;
}

// File Line: 2135
// RVA: 0xD06E10
void __fastcall hkp3AxisSweep::hkpBpAxis::mergeRest<2>(
        hkp3AxisSweep::hkpBpAxis *this,
        hkp3AxisSweep::hkpBpNode *nodes,
        int startOfTail,
        hkp3AxisSweep::hkpBpEndPoint *newEndPoints,
        int numNewEndPoints)
{
  hkp3AxisSweep::hkpBpEndPoint *v6; // rax
  int v7; // r9d
  hkp3AxisSweep::hkpBpEndPoint *v8; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v9; // r10
  int m_value; // r11d
  int v11; // edi
  hkp3AxisSweep::hkpBpEndPoint v12; // ecx
  hkp3AxisSweep::hkpBpEndPoint v13; // ecx

  v6 = &newEndPoints[numNewEndPoints - 1];
  v7 = startOfTail - 1;
  v8 = &this->m_endPoints.m_data[startOfTail - numNewEndPoints - 1];
  v9 = &this->m_endPoints.m_data[startOfTail - 1];
  m_value = v6->m_value;
LABEL_2:
  v11 = v8->m_value;
  while ( 1 )
  {
    if ( v11 > m_value )
    {
      v12 = *v8--;
      --v9;
      v9[1] = v12;
      *(unsigned __int16 *)((char *)&nodes[v8[1].m_nodeIndex].min_y
                          + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(v8[1].m_value & 1) + 4]) = v7--;
      goto LABEL_2;
    }
    v13 = *v6--;
    --v9;
    v9[1] = v13;
    *(unsigned __int16 *)((char *)&nodes[v6[1].m_nodeIndex].min_y
                        + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(v6[1].m_value & 1) + 4]) = v7--;
    if ( v6 < newEndPoints )
      break;
    m_value = v6->m_value;
  }
}

// File Line: 2181
// RVA: 0xCFD0B0
void __fastcall hkp3AxisSweep::addObjectBatch(
        hkp3AxisSweep *this,
        hkArrayBase<hkpBroadPhaseHandle *> *addObjectList,
        hkArrayBase<hkAabb> *addAabbList,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs)
{
  int m_size; // r12d
  __int64 v8; // r13
  int m_enum; // r15d
  int v10; // r14d
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  hkArray<hkp3AxisSweep::hkpBpNode,hkContainerHeapAllocator> *p_m_nodes; // r12
  int v18; // r9d
  int v19; // eax
  int v20; // eax
  __m128 v21; // xmm9
  __m128 v22; // xmm8
  int v23; // ebx
  signed __int64 v24; // r8
  __int64 v25; // r14
  signed __int64 v26; // r9
  hkp3AxisSweep::hkpBpEndPoint *v27; // r10
  __int64 v28; // r11
  char *v29; // rcx
  __m128 v30; // xmm0
  __m128i v31; // xmm1
  __m128 v32; // xmm0
  __m128 v33; // xmm0
  __m128i v34; // xmm6
  hkpBroadPhaseHandle *v35; // rdx
  unsigned __int16 v36; // ax
  unsigned __int16 v37; // ax
  unsigned __int16 v38; // ax
  unsigned __int16 v39; // ax
  unsigned __int16 v40; // ax
  unsigned __int16 v41; // ax
  hkp3AxisSweep *v42; // r9
  int v43; // ebx
  int v44; // eax
  char *v45; // rax
  char *v46; // r13
  hkResultEnum v47; // ecx
  int v48; // ebx
  char *v49; // rcx
  char *v50; // rax
  __m128 m_quad; // xmm0
  hkp3AxisSweep::hkpBpAxis *m_axis; // rdi
  hkp3AxisSweep::hkpBpEndPoint *v53; // r8
  __m128 v54; // xmm0
  __m128i v55; // xmm1
  __m128 v56; // xmm0
  int v57; // r10d
  __m128 v58; // xmm0
  __m128i v59; // xmm6
  unsigned int v60; // r11d
  bool v61; // zf
  int v62; // edx
  hkp3AxisSweep::hkpBpMarker *v63; // rbx
  unsigned __int16 *m_data; // r8
  int i; // r9d
  int v66; // ecx
  __int64 v67; // rbx
  unsigned __int64 v68; // r8
  unsigned __int64 j; // r9
  int m_nodeIndex; // ecx
  unsigned int m_value; // eax
  hkp3AxisSweep::hkpBpEndPoint *v72; // rsi
  __int64 v73; // rax
  hkp3AxisSweep::hkpBpEndPoint *v74; // rbx
  __int64 v75; // rax
  hkp3AxisSweep::hkpBpEndPoint *v76; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v77; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v78; // rax
  char *v79; // rbx
  hkp3AxisSweep::hkpBpNode *v80; // rcx
  char *v81; // rsi
  hkResultEnum v82; // r9d
  hkResultEnum v83; // r10d
  unsigned __int16 *p_max_y; // rdi
  unsigned int v85; // r8d
  unsigned __int16 *v86; // rax
  int v87; // r9d
  int v88; // eax
  int v89; // eax
  hkp3AxisSweep::hkpBpNode *v90; // r13
  __int64 k; // rbx
  hkp3AxisSweep::hkpBpAxis *v92; // r14
  int v93; // ebx
  hkResult *v94; // rdi
  hkp3AxisSweep::hkpBpEndPoint **v95; // rsi
  int inserted; // eax
  __int64 v97; // r8
  __int64 v98; // r9
  int m_numMarkers; // eax
  hkp3AxisSweep::hkpBpNode *v100; // rax
  __int64 v101; // rdx
  int v102; // edx
  hkp3AxisSweep::hkpBpAxis *v103; // r15
  int v104; // r13d
  __int32 v105; // ebx
  int v106; // eax
  hkRadixSort::SortData16 *v107; // r14
  int v108; // edi
  hkp3AxisSweep::hkpBpAxis *v109; // r10
  int v110; // esi
  int v111; // r8d
  __int16 v112; // r15
  hkRadixSort::SortData16 *v113; // rdx
  __int64 v114; // r9
  unsigned __int16 v115; // ax
  unsigned __int16 *p_m_userData; // r9
  hkp3AxisSweep::hkpBpAxis *v117; // r8
  __int64 v118; // r10
  __int64 v119; // rax
  hkp3AxisSweep::hkpBpNode *v120; // rdx
  int v121; // ebx
  __int32 v122; // edx
  __int32 v123; // edi
  int v124; // r15d
  int v125; // eax
  hkRadixSort::SortData16 *v126; // rbx
  int v127; // esi
  int v128; // r10d
  hkp3AxisSweep::hkpBpNode *v129; // r11
  int v130; // r14d
  __int64 v131; // r9
  __int64 v132; // rdi
  __int64 v133; // r8
  hkRadixSort::SortData16 *v134; // r8
  unsigned __int16 *v135; // r9
  hkp3AxisSweep::hkpBpAxis *v136; // r8
  __int64 v137; // r10
  __int64 v138; // rax
  hkp3AxisSweep::hkpBpNode *v139; // rdx
  __int64 v140; // rax
  hkp3AxisSweep::hkpBpNode *v141; // rdi
  hkp3AxisSweep::hkpBpNode *v142; // rbx
  hkResult v143; // [rsp+40h] [rbp-C0h] BYREF
  int numB; // [rsp+44h] [rbp-BCh]
  _QWORD *array; // [rsp+48h] [rbp-B8h] BYREF
  int v146; // [rsp+50h] [rbp-B0h]
  int v147; // [rsp+54h] [rbp-ACh]
  __int64 v148[2]; // [rsp+60h] [rbp-A0h] BYREF
  int v149; // [rsp+70h] [rbp-90h] BYREF
  hkp3AxisSweep::hkpBpAxis *v150; // [rsp+78h] [rbp-88h]
  hkResult result[2]; // [rsp+80h] [rbp-80h] BYREF
  int startOfTail; // [rsp+88h] [rbp-78h]
  hkp3AxisSweep::hkpBpAxis *v153; // [rsp+A0h] [rbp-60h]
  hkp3AxisSweep::hkpBpAxis *v154; // [rsp+A8h] [rbp-58h]
  int v155; // [rsp+B0h] [rbp-50h] BYREF
  int v156; // [rsp+B4h] [rbp-4Ch] BYREF
  int v157; // [rsp+B8h] [rbp-48h] BYREF
  int v158; // [rsp+C0h] [rbp-40h]
  int v159; // [rsp+C4h] [rbp-3Ch]
  int v160; // [rsp+C8h] [rbp-38h]
  int v161; // [rsp+D0h] [rbp-30h]
  int v162; // [rsp+D4h] [rbp-2Ch]
  int v163; // [rsp+D8h] [rbp-28h]
  hkp3AxisSweep::hkpBpEndPoint *v164; // [rsp+E0h] [rbp-20h]
  hkp3AxisSweep::hkpBpEndPoint *newEndPoints; // [rsp+E8h] [rbp-18h]
  hkp3AxisSweep::hkpBpEndPoint *v166; // [rsp+F0h] [rbp-10h]
  int v167; // [rsp+F8h] [rbp-8h]
  int v168; // [rsp+FCh] [rbp-4h]
  int v169; // [rsp+100h] [rbp+0h]
  hkp3AxisSweep::hkpBpEndPoint *pArr[3]; // [rsp+108h] [rbp+8h] BYREF
  int numA; // [rsp+1B0h] [rbp+B0h]

  if ( addAabbList->m_size >= 1 )
  {
    m_size = this->m_nodes.m_size;
    v8 = addObjectList->m_size;
    m_enum = 2 * v8;
    v10 = 0;
    numB = m_size;
    numA = v8;
    v143.m_enum = 2 * v8;
    v11 = 2 * v8;
    if ( 2 * (_DWORD)v8 )
    {
      v155 = 8 * v8;
      newEndPoints = (hkp3AxisSweep::hkpBpEndPoint *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                       &hkContainerTempAllocator::s_alloc,
                                                       &v155);
      v11 = v155 / 4;
    }
    else
    {
      newEndPoints = 0i64;
    }
    v12 = 0x80000000;
    if ( v11 )
      v12 = v11;
    v13 = 2 * v8;
    v168 = v12;
    if ( m_enum )
    {
      v157 = 8 * v8;
      v164 = (hkp3AxisSweep::hkpBpEndPoint *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                               &hkContainerTempAllocator::s_alloc,
                                               &v157);
      v13 = v157 / 4;
    }
    else
    {
      v164 = 0i64;
    }
    v14 = 0x80000000;
    if ( v13 )
      v14 = v13;
    v15 = 2 * v8;
    v167 = v14;
    if ( m_enum )
    {
      v156 = 8 * v8;
      v166 = (hkp3AxisSweep::hkpBpEndPoint *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                               &hkContainerTempAllocator::s_alloc,
                                               &v156);
      v15 = v156 / 4;
    }
    else
    {
      v166 = 0i64;
    }
    v16 = 0x80000000;
    array = 0i64;
    if ( v15 )
      v16 = v15;
    v146 = 0;
    v147 = 0x80000000;
    v169 = v16;
    if ( m_size > 0 )
    {
      hkArrayUtil::_reserve(result, &hkContainerTempAllocator::s_alloc, (const void **)&array, m_size, 8);
      v10 = v146;
    }
    p_m_nodes = &this->m_nodes;
    v18 = v8 + this->m_nodes.m_size;
    v19 = this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v19 < v18 )
    {
      v20 = 2 * v19;
      if ( v18 < v20 )
        v18 = v20;
      hkArrayUtil::_reserve(result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, v18, 24);
      v10 = v146;
    }
    this->m_nodes.m_size += v8;
    v21 = (__m128)xmmword_141A712A0;
    pArr[1] = v164;
    pArr[2] = v166;
    pArr[0] = newEndPoints;
    v22 = _mm_xor_ps(
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
            (__m128)xmmword_141A712A0);
    if ( v8 > 0 )
    {
      v23 = numB;
      v24 = (char *)v164 - (char *)newEndPoints;
      v25 = 0i64;
      v26 = (char *)v166 - (char *)newEndPoints;
      v27 = newEndPoints + 1;
      v28 = -4i64 - (_QWORD)newEndPoints;
      do
      {
        v29 = (char *)v27 + v28;
        v27 += 2;
        v21 = _mm_min_ps(v21, addAabbList->m_data[v25++].m_min.m_quad);
        v22 = _mm_max_ps(v22, addAabbList->m_data[v25 - 1].m_max.m_quad);
        v30 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(addAabbList->m_data[v25 - 1].m_min.m_quad, this->m_offsetLow.m_quad),
                    this->m_scale.m_quad),
                  hkp3AxisSweep::MaxVal),
                (__m128)0i64);
        v31 = _mm_sub_epi32(
                _mm_xor_si128(
                  (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v30),
                  _mm_cvttps_epi32(v30)),
                (__m128i)_xmm);
        v32 = _mm_min_ps(
                _mm_mul_ps(
                  _mm_add_ps(addAabbList->m_data[v25 - 1].m_max.m_quad, this->m_offsetHigh.m_quad),
                  this->m_scale.m_quad),
                hkp3AxisSweep::MaxVal);
        *(_QWORD *)&result[0].m_enum = _mm_add_epi16(
                                         _mm_packs_epi32(v31, v31),
                                         (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
        v158 = result[0].m_enum & 0xFFFE;
        v33 = _mm_max_ps(v32, (__m128)0i64);
        v159 = HIWORD(result[0].m_enum) & 0xFFFE;
        v160 = result[1].m_enum & 0xFFFE;
        v34 = _mm_sub_epi32(
                _mm_xor_si128(
                  (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v33),
                  _mm_cvttps_epi32(v33)),
                (__m128i)_xmm);
        v148[0] = _mm_add_epi16(
                    _mm_packs_epi32(v34, v34),
                    (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
        v161 = LOWORD(v148[0]) | 1;
        v162 = WORD1(v148[0]) | 1;
        v163 = WORD2(v148[0]) | 1;
        v35 = *(hkpBroadPhaseHandle **)&v29[(unsigned __int64)addObjectList->m_data];
        p_m_nodes->m_data[v23].m_handle = v35;
        v36 = v158;
        v35->m_id = v23;
        v27[-3].m_value = v36;
        v37 = v161;
        v27[-3].m_nodeIndex = v23;
        v27[-2].m_value = v37;
        v38 = v159;
        v27[-2].m_nodeIndex = v23;
        *(unsigned __int16 *)((char *)&v27[-3].m_value + v24) = v38;
        v39 = v162;
        *(_WORD *)((char *)&v27[-2] + v24 - 2) = v23;
        *(unsigned __int16 *)((char *)&v27[-2].m_value + v24) = v39;
        v40 = v160;
        *(_WORD *)((char *)&v27[-1] + v24 - 2) = v23;
        *(unsigned __int16 *)((char *)&v27[-3].m_value + v26) = v40;
        v41 = v163;
        *(_WORD *)((char *)&v27[-2] + v26 - 2) = v23;
        *(_WORD *)((char *)&v27[-1] + v26 - 2) = v23;
        *(unsigned __int16 *)((char *)&v27[-2].m_value + v26) = v41;
        ++v23;
        --v8;
      }
      while ( v8 );
      v10 = v146;
      m_enum = v143.m_enum;
    }
    v42 = this;
    p_m_nodes->m_size = numB;
    v43 = this->m_nodes.m_size;
    v44 = (v43 >> 5) + 8;
    if ( v43 >> 5 == -8 )
    {
      v46 = 0i64;
    }
    else
    {
      v149 = 4 * v44;
      v45 = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v149);
      v10 = v146;
      v42 = this;
      v46 = v45;
      v44 = v149 / 4;
    }
    v47 = 0x80000000;
    if ( v44 )
      v47 = v44;
    v48 = v43 >> 7;
    v143.m_enum = v47;
    v49 = v46;
    if ( v48 >= 0 )
    {
      do
      {
        v50 = v49;
        v49 += 16;
        --v48;
        *(_OWORD *)v50 = 0i64;
      }
      while ( v48 >= 0 );
      v10 = v146;
    }
    m_quad = v42->m_offsetLow.m_quad;
    m_axis = v42->m_axis;
    v154 = v42->m_axis;
    v53 = v42->m_axis[0].m_endPoints.m_data + 1;
    v54 = _mm_max_ps(
            _mm_min_ps(_mm_mul_ps(_mm_add_ps(m_quad, v21), v42->m_scale.m_quad), hkp3AxisSweep::MaxVal),
            (__m128)0i64);
    v55 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v54),
              _mm_cvttps_epi32(v54)),
            (__m128i)_xmm);
    v56 = _mm_min_ps(_mm_mul_ps(_mm_add_ps(v42->m_offsetHigh.m_quad, v22), v42->m_scale.m_quad), hkp3AxisSweep::MaxVal);
    *(_QWORD *)&result[0].m_enum = _mm_add_epi16(
                                     _mm_packs_epi32(v55, v55),
                                     (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
    v57 = result[0].m_enum & 0xFFFE;
    v159 = HIWORD(result[0].m_enum) & 0xFFFE;
    v58 = _mm_max_ps(v56, (__m128)0i64);
    v160 = result[1].m_enum & 0xFFFE;
    v59 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v58),
              _mm_cvttps_epi32(v58)),
            (__m128i)_xmm);
    v148[0] = _mm_add_epi16(_mm_packs_epi32(v59, v59), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
    v60 = LOWORD(v148[0]) | 1;
    v162 = WORD1(v148[0]) | 1;
    v61 = v42->m_numMarkers == 0;
    v163 = WORD2(v148[0]) | 1;
    if ( !v61 )
    {
      v62 = v57 >> (16 - LOBYTE(v42->m_ld2NumMarkers));
      if ( v62 > 0 )
      {
        v63 = &v42->m_markers[v62 - 1];
        *(_DWORD *)&v46[4 * ((int)v63->m_nodeIndex >> 5)] ^= 1 << (v63->m_nodeIndex & 0x1F);
        m_data = v63->m_overlappingObjects.m_data;
        for ( i = v63->m_overlappingObjects.m_size - 1; i >= 0; --i )
        {
          v66 = *m_data++;
          *(_DWORD *)&v46[4 * (v66 >> 5)] ^= 1 << (v66 & 0x1F);
        }
        v67 = (__int64)&p_m_nodes->m_data[v63->m_nodeIndex];
        v68 = (unsigned __int64)&m_axis->m_endPoints.m_data[*(unsigned __int16 *)(v67 + 8) + 1];
        for ( j = (unsigned __int64)&m_axis->m_endPoints.m_data[*(unsigned __int16 *)(v67 + 10)]; v68 < j; v68 += 4i64 )
        {
          if ( (*(_BYTE *)v68 & 1) == 0 )
            *(_DWORD *)&v46[4 * ((int)*(unsigned __int16 *)(v68 + 2) >> 5)] &= ~(1 << (*(_WORD *)(v68 + 2) & 0x1F));
        }
        v10 = v146;
        v42 = this;
        v53 = &m_axis->m_endPoints.m_data[*(unsigned __int16 *)(v67 + 8) + 1];
      }
    }
    if ( v53->m_value < (unsigned int)v57 )
    {
      do
      {
        m_nodeIndex = v53->m_nodeIndex;
        ++v53;
        *(_DWORD *)&v46[4 * (m_nodeIndex >> 5)] ^= 1 << (m_nodeIndex & 0x1F);
      }
      while ( v53->m_value < (unsigned int)v57 );
      v10 = v146;
    }
    m_value = v53->m_value;
    if ( m_value < v60 )
    {
      do
      {
        if ( (m_value & 1) == 0 )
          *(_DWORD *)&v46[4 * ((int)v53->m_nodeIndex >> 5)] ^= 1 << (v53->m_nodeIndex & 0x1F);
        m_value = v53[1].m_value;
        ++v53;
      }
      while ( m_value < v60 );
      v10 = v146;
    }
    v72 = v42->m_axis[1].m_endPoints.m_data;
    v73 = v42->m_axis[1].m_endPoints.m_size;
    v150 = &v42->m_axis[1];
    v74 = &v72[v73];
    LOWORD(result[0].m_enum) = hkp3AxisSweep::hkpBpAxis::find(&v42->m_axis[1], v72 + 1, v74 - 2, v159) - v72;
    v75 = ((__int64)hkp3AxisSweep::hkpBpAxis::find(v150, v72 + 1, v74 - 2, v162) - 4 - (__int64)v72) >> 2;
    v76 = this->m_axis[2].m_endPoints.m_data;
    LOWORD(result[1].m_enum) = v75;
    v77 = &v76[this->m_axis[2].m_endPoints.m_size];
    v153 = &this->m_axis[2];
    HIWORD(result[0].m_enum) = hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[2], v76 + 1, v77 - 2, v160) - v76;
    v78 = hkp3AxisSweep::hkpBpAxis::find(v153, v76 + 1, v77 - 2, v163);
    v79 = v46;
    v80 = p_m_nodes->m_data;
    HIWORD(result[1].m_enum) = ((__int64)v78 - 4 - (__int64)v76) >> 2;
    v81 = &v46[4 * ((__int64)this->m_nodes.m_size >> 5) + 4];
    if ( v46 < v81 )
    {
      v82 = result[1].m_enum;
      v83 = result[0].m_enum;
      p_max_y = &v80[2].max_y;
      do
      {
        v85 = *(_DWORD *)v79;
        if ( *(_DWORD *)v79 )
        {
          v86 = p_max_y;
          do
          {
            if ( (v85 & 0xF) != 0 )
            {
              if ( (v85 & 1) != 0
                && (((v82 - *((_DWORD *)v86 - 13)) | (*((_DWORD *)v86 - 12) - v83)) & 0x80008000) == 0
                && (*(_BYTE *)(v86 - 18) & 1) == 0 )
              {
                array[v10] = v86 - 26;
                v10 = ++v146;
              }
              if ( (v85 & 2) != 0
                && (((v82 - *((_DWORD *)v86 - 7)) | (*((_DWORD *)v86 - 6) - v83)) & 0x80008000) == 0
                && (*(_BYTE *)(v86 - 6) & 1) == 0 )
              {
                array[v10] = v86 - 14;
                v10 = ++v146;
              }
              if ( (v85 & 4) != 0
                && (((v82 - *((_DWORD *)v86 - 1)) | (*(_DWORD *)v86 - v83)) & 0x80008000) == 0
                && (v86[6] & 1) == 0 )
              {
                array[v10] = v86 - 2;
                v10 = ++v146;
              }
              if ( (v85 & 8) != 0
                && (((v82 - *((_DWORD *)v86 + 5)) | (*((_DWORD *)v86 + 6) - v83)) & 0x80008000) == 0
                && (v86[18] & 1) == 0 )
              {
                array[v10] = v86 + 10;
                v10 = ++v146;
              }
            }
            v85 >>= 4;
            v86 += 48;
          }
          while ( v85 );
        }
        v79 += 4;
        p_max_y += 384;
      }
      while ( v79 < v81 );
    }
    if ( v143.m_enum >= HK_SUCCESS )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v46, 4 * v143.m_enum);
    v87 = numA + p_m_nodes->m_size;
    v88 = p_m_nodes->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v88 < v87 )
    {
      v89 = 2 * v88;
      if ( v87 < v89 )
        v87 = v89;
      hkArrayUtil::_reserve(&v143, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_nodes->m_data, v87, 24);
    }
    p_m_nodes->m_size += numA;
    v90 = p_m_nodes->m_data;
    for ( k = 0i64; k < 3; ++k )
    {
      if ( m_enum > 1 )
        hkAlgorithm::quickSortRecursive<hkp3AxisSweep::hkpBpEndPoint,hkAlgorithm::less<hkp3AxisSweep::hkpBpEndPoint>>(
          pArr[k],
          0,
          m_enum - 1,
          0);
    }
    v92 = v154;
    v93 = 0;
    v94 = result;
    v95 = pArr;
    do
    {
      inserted = hkp3AxisSweep::hkpBpAxis::insertTail(v92++, v90, v93++, *v95, m_enum);
      v94->m_enum = inserted;
      ++v94;
      ++v95;
    }
    while ( v93 < 3 );
    hkp3AxisSweep::hkpBpAxis::mergeRest<0>(v154, v90, result[0].m_enum, newEndPoints, m_enum);
    hkp3AxisSweep::hkpBpAxis::mergeRest<1>(v150, v90, result[1].m_enum, v164, m_enum);
    hkp3AxisSweep::hkpBpAxis::mergeRest<2>(v153, v90, startOfTail, v166, m_enum);
    m_numMarkers = this->m_numMarkers;
    if ( m_numMarkers )
    {
      v98 = 0i64;
      if ( m_numMarkers > 0 )
      {
        v97 = 0i64;
        do
        {
          v98 = (unsigned int)(v98 + 1);
          ++v97;
          v100 = p_m_nodes->m_data;
          v101 = this->m_markers[v97 - 1].m_nodeIndex;
          v100[v101].max_y += m_enum;
          v100[v101].max_z += m_enum;
        }
        while ( (int)v98 < this->m_numMarkers );
      }
    }
    v102 = numA + 1;
    if ( numA == -1 )
    {
      v103 = 0i64;
    }
    else
    {
      v149 = 24 * v102;
      v103 = (hkp3AxisSweep::hkpBpAxis *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, __int64, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                           &hkContainerTempAllocator::s_alloc,
                                           &v149,
                                           v97 * 24,
                                           v98);
      v102 = v149 / 24;
    }
    v104 = 0x80000000;
    v154 = v103;
    if ( v102 )
      v104 = v102;
    v105 = numA + 4;
    v106 = numA + 4;
    if ( numA == -4 )
    {
      v107 = 0i64;
    }
    else
    {
      LODWORD(v148[0]) = 4 * v105;
      v107 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                          &hkContainerTempAllocator::s_alloc,
                                          v148);
      v106 = SLODWORD(v148[0]) / 4;
    }
    v108 = 0x80000000;
    if ( v106 )
      v108 = v106;
    if ( numA == -4 )
    {
      v109 = 0i64;
    }
    else
    {
      result[0].m_enum = 4 * v105;
      v109 = (hkp3AxisSweep::hkpBpAxis *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                           &hkContainerTempAllocator::s_alloc,
                                           result);
      v105 = result[0].m_enum / 4;
    }
    v110 = 0x80000000;
    if ( v105 )
      v110 = v105;
    v111 = 0;
    v150 = v109;
    if ( numA > 0 )
    {
      v112 = numB;
      v113 = v107;
      v114 = numB;
      do
      {
        v115 = v111++ + v112;
        ++v113;
        v113[-1].m_userData = v115;
        v113[-1].m_key = p_m_nodes->m_data[v114++].min_x;
      }
      while ( v111 < numA );
      v103 = v154;
    }
    v107[numA].m_key = -1;
    v107[numA + 1].m_key = -1;
    v107[numA + 2].m_key = -1;
    hkRadixSort::sort16(v107, (numA + 3) & 0xFFFFFFFC, (hkRadixSort::SortData16 *)v109);
    if ( numA > 0i64 )
    {
      v117 = v103;
      p_m_userData = &v107->m_userData;
      v118 = numA;
      do
      {
        v119 = *p_m_userData;
        v117 = (hkp3AxisSweep::hkpBpAxis *)((char *)v117 + 24);
        p_m_userData += 2;
        v120 = &p_m_nodes->m_data[v119];
        *(_QWORD *)&v117[-2].m_endPoints.m_size = *(_QWORD *)&v120->min_y;
        v117[-1].m_endPoints.m_data = *(hkp3AxisSweep::hkpBpEndPoint **)&v120->min_x;
        *(_QWORD *)&v117[-1].m_endPoints.m_size = v120->m_handle;
        --v118;
      }
      while ( v118 );
    }
    *((_WORD *)&v103->m_endPoints.m_size + 12 * numA) = -1;
    if ( v110 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkp3AxisSweep::hkpBpAxis *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v150,
        (unsigned int)(4 * v110),
        p_m_userData);
    if ( v108 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v107,
        (unsigned int)(4 * v108),
        p_m_userData);
    v121 = v146;
    numB = v146;
    v122 = v146 + 1;
    if ( v146 == -1 )
    {
      v153 = 0i64;
    }
    else
    {
      result[0].m_enum = 24 * v122;
      v153 = (hkp3AxisSweep::hkpBpAxis *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, hkResult *, hkMemoryAllocatorVtbl *, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                           &hkContainerTempAllocator::s_alloc,
                                           result,
                                           hkContainerTempAllocator::s_alloc.vfptr,
                                           p_m_userData);
      v122 = result[0].m_enum / 24;
    }
    v123 = v121 + 4;
    v124 = 0x80000000;
    if ( v122 )
      v124 = v122;
    v125 = v121 + 4;
    if ( v121 == -4 )
    {
      v126 = 0i64;
    }
    else
    {
      LODWORD(v148[0]) = 4 * v123;
      v126 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                          &hkContainerTempAllocator::s_alloc,
                                          v148);
      v125 = SLODWORD(v148[0]) / 4;
    }
    v127 = 0x80000000;
    if ( v125 )
      v127 = v125;
    if ( v123 )
    {
      v143.m_enum = 4 * v123;
      v150 = (hkp3AxisSweep::hkpBpAxis *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                           &hkContainerTempAllocator::s_alloc,
                                           &v143);
      v123 = v143.m_enum / 4;
    }
    else
    {
      v150 = 0i64;
    }
    v128 = numB;
    v129 = p_m_nodes->m_data;
    v130 = 0x80000000;
    if ( v123 )
      v130 = v123;
    v131 = 0i64;
    v132 = numB;
    if ( numB > 0 )
    {
      do
      {
        v133 = array[v131++];
        v126[v131 - 1].m_userData = (v133 - (__int64)v129) / 24;
        v126[v131 - 1].m_key = *(_WORD *)(v133 + 8);
      }
      while ( v131 < v132 );
      v128 = numB;
    }
    v134 = (hkRadixSort::SortData16 *)v150;
    v126[v132].m_key = -1;
    v126[v132 + 1].m_key = -1;
    v126[v132 + 2].m_key = -1;
    hkRadixSort::sort16(v126, (v128 + 3) & 0xFFFFFFFC, v134);
    if ( v132 > 0 )
    {
      v136 = v153;
      v135 = &v126->m_userData;
      v137 = v132;
      do
      {
        v138 = *v135;
        v136 = (hkp3AxisSweep::hkpBpAxis *)((char *)v136 + 24);
        v135 += 2;
        v139 = &p_m_nodes->m_data[v138];
        *(_QWORD *)&v136[-2].m_endPoints.m_size = *(_QWORD *)&v139->min_y;
        v136[-1].m_endPoints.m_data = *(hkp3AxisSweep::hkpBpEndPoint **)&v139->min_x;
        *(_QWORD *)&v136[-1].m_endPoints.m_size = v139->m_handle;
        --v137;
      }
      while ( v137 );
    }
    v140 = 3 * v132;
    v141 = (hkp3AxisSweep::hkpBpNode *)v153;
    *((_WORD *)&v153->m_endPoints.m_size + 4 * v140) = -1;
    if ( v130 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkp3AxisSweep::hkpBpAxis *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v150,
        (unsigned int)(4 * v130),
        v135);
    if ( v127 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v126,
        (unsigned int)(4 * v127),
        v135);
    v142 = (hkp3AxisSweep::hkpBpNode *)v154;
    hkp3AxisSweep::collide1Axis(this, (hkp3AxisSweep::hkpBpNode *)v154, numA, newPairs);
    hkp3AxisSweep::collide1Axis(this, v142, numA, v141, numB, MARKERS_ADD_NEW_OVERLAPS, newPairs);
    if ( v124 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v141,
        24 * (v124 & 0x3FFFFFFF));
    if ( v104 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v142,
        24 * (v104 & 0x3FFFFFFF));
    v146 = 0;
    if ( v147 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 8 * v147);
    array = 0i64;
    v147 = 0x80000000;
    if ( v169 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v166, 4 * v169);
    if ( v167 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v164, 4 * v167);
    if ( v168 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, newEndPoints, 4 * v168);
  }
}

// File Line: 2381
// RVA: 0xCFE5F0
void __fastcall hkp3AxisSweep::removeObjectBatch(
        hkp3AxisSweep *this,
        hkArrayBase<hkpBroadPhaseHandle *> *removeObjectList,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairsOut)
{
  __int64 m_size; // r14
  int v4; // r13d
  int v6; // edx
  unsigned int v8; // eax
  int v9; // esi
  hkpBroadPhaseHandle **m_data; // rax
  __int64 *v11; // rdx
  int v12; // eax
  hkRadixSort::SortData16 *v13; // r15
  int v14; // edi
  __int64 v15; // r9
  unsigned __int16 v16; // r12
  unsigned __int16 v17; // r10
  unsigned __int16 v18; // r11
  unsigned __int16 v19; // r13
  unsigned __int16 v20; // di
  hkRadixSort::SortData16 *v21; // rsi
  __int64 v22; // rax
  __int64 m_id; // rdx
  unsigned __int16 *v24; // r8
  unsigned __int16 m_enum; // ax
  unsigned __int16 v26; // ax
  unsigned __int16 v27; // ax
  unsigned __int16 v28; // ax
  unsigned __int16 v29; // ax
  unsigned __int16 v30; // ax
  hkRadixSort::SortData16 *v31; // r12
  int v32; // ebx
  unsigned __int16 *p_m_userData; // r9
  hkp3AxisSweep::hkpBpNode *v34; // rsi
  hkRadixSort::SortData16 *v35; // r11
  hkp3AxisSweep::hkpBpNode *v36; // r8
  __int64 v37; // r10
  __int64 v38; // rax
  _QWORD *v39; // rdx
  __int64 v40; // r12
  int v41; // ebx
  int m_numMarkers; // r9d
  int v43; // r9d
  int v44; // eax
  _DWORD *v45; // rsi
  unsigned int v46; // ecx
  int v47; // r14d
  int v48; // eax
  hkRadixSort::SortData16 *v49; // r8
  int v50; // r9d
  unsigned int v51; // ecx
  int v52; // edx
  __int16 v53; // r15
  __int16 v54; // r13
  _DWORD *v55; // r11
  __int64 v56; // r10
  hkRadixSort::SortData16 *v57; // rdi
  __int64 *v58; // rax
  __int64 v59; // rbx
  __int64 v60; // r8
  __int64 v61; // rax
  __int64 *v62; // r13
  int v63; // ebx
  int v64; // eax
  int v65; // eax
  int v66; // r9d
  __int32 v67; // edx
  unsigned __int16 v68; // bx
  unsigned int v69; // eax
  __int32 v70; // eax
  hkRadixSort::SortData16 *v71; // r15
  int v72; // ebx
  hkRadixSort::SortData16 *v73; // rax
  unsigned __int16 *v74; // r9
  hkp3AxisSweep::hkpBpNode *v75; // r8
  __int64 v76; // r10
  __int64 v77; // rax
  _QWORD *v78; // rdx
  hkp3AxisSweep::hkpBpNode *v79; // rdi
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v80; // rbx
  int v81; // r15d
  hkp3AxisSweep::hkpBpNode *v82; // r14
  unsigned __int64 v83; // r9
  __int64 v84; // r11
  unsigned __int64 v85; // r10
  int v86; // ebx
  unsigned __int64 v87; // r8
  __int64 v88; // rcx
  int v89; // eax
  int v90; // eax
  int v91; // r9d
  unsigned __int64 v92; // r9
  __int64 v93; // r11
  unsigned __int64 v94; // r10
  int v95; // ebx
  unsigned __int64 v96; // r8
  __int64 v97; // rcx
  int v98; // eax
  int v99; // eax
  int v100; // r9d
  unsigned __int64 v101; // r9
  __int64 v102; // r11
  unsigned __int64 v103; // r10
  int v104; // ebx
  unsigned __int64 v105; // r8
  __int64 v106; // rcx
  int v107; // eax
  int v108; // eax
  int v109; // r9d
  int v110; // eax
  int v111; // r14d
  __int16 v112; // r13
  __int64 v113; // r15
  int v114; // edx
  int v115; // ebx
  unsigned __int16 *v116; // r11
  __int64 v117; // rcx
  __int64 v118; // rax
  __int64 v119; // r8
  __int64 v120; // rcx
  __int64 v121; // r9
  int v122; // r10d
  unsigned __int16 *v123; // rdi
  int v124; // eax
  int v125; // eax
  int v126; // r9d
  int v127; // edi
  __int64 v128; // rbx
  int sizeElem; // [rsp+20h] [rbp-79h]
  int v130; // [rsp+40h] [rbp-59h] BYREF
  int numA; // [rsp+44h] [rbp-55h]
  int v132; // [rsp+48h] [rbp-51h] BYREF
  hkp3AxisSweep::hkpBpNode *pa; // [rsp+50h] [rbp-49h]
  int v134; // [rsp+58h] [rbp-41h]
  int v135; // [rsp+5Ch] [rbp-3Dh]
  int v136; // [rsp+60h] [rbp-39h] BYREF
  _DWORD *array; // [rsp+68h] [rbp-31h] BYREF
  int v138; // [rsp+70h] [rbp-29h]
  int v139; // [rsp+74h] [rbp-25h]
  hkRadixSort::SortData16 *data; // [rsp+78h] [rbp-21h]
  __int64 v141; // [rsp+80h] [rbp-19h]
  __int64 v142; // [rsp+88h] [rbp-11h]
  __int64 v143; // [rsp+90h] [rbp-9h]
  int v144; // [rsp+98h] [rbp-1h] BYREF
  hkp3AxisSweep::hkpBpNode *pb; // [rsp+A0h] [rbp+7h]
  int v146; // [rsp+A8h] [rbp+Fh]
  hkp3AxisSweep *result; // [rsp+100h] [rbp+67h] BYREF
  hkResult v148; // [rsp+108h] [rbp+6Fh] BYREF
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut; // [rsp+110h] [rbp+77h]
  hkResult v150; // [rsp+118h] [rbp+7Fh] BYREF

  pairsOut = delPairsOut;
  result = this;
  m_size = removeObjectList->m_size;
  v4 = this->m_nodes.m_size;
  v6 = m_size + 1;
  v136 = 0;
  numA = m_size;
  v134 = v4;
  if ( (_DWORD)m_size == -1 )
  {
    pa = 0i64;
  }
  else
  {
    v144 = 24 * v6;
    pa = (hkp3AxisSweep::hkpBpNode *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerTempAllocator::s_alloc,
                                       &v144);
    v6 = v144 / 24;
  }
  v8 = 0x80000000;
  v9 = m_size + 4;
  if ( v6 )
    v8 = v6;
  v135 = m_size + 4;
  v146 = v8;
  m_data = removeObjectList->m_data;
  data = (hkRadixSort::SortData16 *)&this->m_nodes;
  v11 = (__int64 *)&this->m_nodes.m_data[(*m_data)->m_id];
  v141 = *v11;
  v142 = v11[1];
  v143 = v11[2];
  v12 = m_size + 4;
  if ( (_DWORD)m_size == -4 )
  {
    v13 = 0i64;
  }
  else
  {
    v132 = 4 * v9;
    v13 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerTempAllocator::s_alloc,
                                       &v132);
    v12 = v132 / 4;
  }
  v14 = 0x80000000;
  if ( v12 )
    v14 = v12;
  v15 = 0i64;
  v130 = v14;
  if ( m_size <= 0 )
  {
    LOWORD(v150.m_enum) = WORD1(v142);
    LOWORD(v148.m_enum) = v142;
  }
  else
  {
    v16 = WORD1(v142);
    v17 = HIWORD(v141);
    v18 = WORD1(v141);
    v19 = WORD2(v141);
    v20 = v141;
    v21 = data;
    LOWORD(v148.m_enum) = v142;
    do
    {
      v22 = *(_QWORD *)&v21->m_key;
      m_id = removeObjectList->m_data[v15]->m_id;
      v13[v15].m_userData = m_id;
      v24 = (unsigned __int16 *)(v22 + 24 * m_id);
      v13[v15].m_key = v24[4];
      m_enum = v24[4];
      if ( LOWORD(v148.m_enum) < m_enum )
        m_enum = v148.m_enum;
      LOWORD(v148.m_enum) = m_enum;
      v26 = *v24;
      if ( v20 < *v24 )
        v26 = v20;
      v20 = v26;
      v27 = v24[1];
      if ( v18 < v27 )
        v27 = v18;
      v18 = v27;
      v28 = v24[5];
      if ( v16 > v28 )
        v28 = v16;
      v16 = v28;
      v29 = v24[2];
      if ( v19 > v29 )
        v29 = v19;
      v19 = v29;
      v30 = v24[3];
      if ( v17 > v30 )
        v30 = v17;
      ++v15;
      v17 = v30;
    }
    while ( v15 < m_size );
    v9 = v135;
    WORD2(v141) = v19;
    v4 = v134;
    LOWORD(v141) = v20;
    v14 = v130;
    HIWORD(v141) = v30;
    WORD1(v141) = v18;
    LOWORD(v150.m_enum) = v16;
  }
  if ( v9 )
  {
    v130 = 4 * v9;
    v31 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerTempAllocator::s_alloc,
                                       &v130);
    v9 = v130 / 4;
  }
  else
  {
    v31 = 0i64;
  }
  v32 = 0x80000000;
  if ( v9 )
    v32 = v9;
  v13[m_size].m_key = -1;
  v13[m_size + 1].m_key = -1;
  v13[m_size + 2].m_key = -1;
  hkRadixSort::sort16(v13, (m_size + 3) & 0xFFFFFFFC, v31);
  v34 = pa;
  if ( m_size > 0 )
  {
    v35 = data;
    v36 = pa;
    p_m_userData = &v13->m_userData;
    v37 = m_size;
    do
    {
      v38 = *p_m_userData;
      p_m_userData += 2;
      ++v36;
      v39 = (_QWORD *)(*(_QWORD *)&v35->m_key + 24 * v38);
      *(_QWORD *)&v36[-1].min_y = *v39;
      *(_QWORD *)&v36[-1].min_x = v39[1];
      v36[-1].m_handle = (hkpBroadPhaseHandle *)v39[2];
      *(_DWORD *)v39[2] = 0;
      v39[2] = &v136;
      --v37;
    }
    while ( v37 );
  }
  v34[m_size].min_x = -1;
  if ( v32 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v31,
      (unsigned int)(4 * v32),
      p_m_userData);
  if ( v14 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v13,
      (unsigned int)(4 * v14),
      p_m_userData);
  v40 = (__int64)result;
  v41 = m_size;
  m_numMarkers = result->m_numMarkers;
  array = 0i64;
  v138 = 0;
  v43 = m_size + m_numMarkers;
  v139 = 0x80000000;
  if ( v43 > 0 )
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerTempAllocator::s_alloc, (const void **)&array, v43, 4);
  v44 = v4;
  if ( v4 )
  {
    LODWORD(result) = 4 * v4;
    v45 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &result);
    v44 = (int)result / 4;
  }
  else
  {
    v45 = 0i64;
  }
  v46 = 0x80000000;
  v47 = 0;
  if ( v44 )
    v46 = v44;
  v132 = v46;
  v48 = v4 - v41 + 4;
  if ( v4 - v41 == -4 )
  {
    v49 = 0i64;
  }
  else
  {
    v130 = 4 * v48;
    v49 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerTempAllocator::s_alloc,
                                       &v130);
    v48 = v130 / 4;
  }
  v50 = v4 - 1;
  v51 = 0x80000000;
  if ( v48 )
    v51 = v48;
  v52 = 1;
  data = v49;
  v135 = v51;
  *v45 = 0;
  if ( v50 >= 1 )
  {
    v53 = WORD2(v141);
    v54 = v141;
    v55 = &v45[v50];
    v56 = 24i64 * v50;
    v57 = v49;
    v58 = (__int64 *)(v40 + 176);
    while ( 1 )
    {
      v59 = *v58;
      if ( *(int **)(v56 + *v58 + 16) != &v136 )
        break;
      *v55-- = -1;
      --v50;
      v56 -= 24i64;
      --v52;
LABEL_61:
      if ( ++v52 > v50 )
        goto LABEL_62;
    }
    v60 = v59 + 24i64 * v52;
    if ( *(int **)(v60 + 16) == &v136 )
    {
      v61 = *(_QWORD *)(v56 + v59);
      --v50;
      v56 -= 24i64;
      *(_QWORD *)v60 = v61;
      --v55;
      *(_QWORD *)(v60 + 8) = *(_QWORD *)(v56 + v59 + 32);
      *(_QWORD *)(v60 + 16) = *(_QWORD *)(v56 + v59 + 40);
      v55[1] = v52;
      v45[v52] = -1;
      array[v138++] = v52;
      if ( (*(_BYTE *)(v60 + 16) & 1) != 0 )
      {
        *(_WORD *)((*(_QWORD *)(v60 + 16) & 0xFFFFFFFFFFFFFFFEui64) + *(_QWORD *)(v40 + 248)) = v52;
LABEL_60:
        v58 = (__int64 *)(v40 + 176);
        goto LABEL_61;
      }
      **(_DWORD **)(v60 + 16) = v52;
    }
    else
    {
      v45[v52] = v52;
    }
    if ( (((HIDWORD(v141) - *(_DWORD *)v60) | (*(_DWORD *)(v60 + 4) - (_DWORD)v141)) & 0x80008000) == 0 )
    {
      v68 = *(_WORD *)(v60 + 8);
      v58 = (__int64 *)(v40 + 176);
      if ( (((v53 - *(_WORD *)v60) | (LOWORD(v150.m_enum) - v68) | (*(_WORD *)(v60 + 4) - v54) | (*(_WORD *)(v60 + 10)
                                                                                                - LOWORD(v148.m_enum))) & 0x8000u) == 0 )
      {
        v57->m_key = v68;
        ++v47;
        v57->m_userData = v52;
        ++v57;
      }
      goto LABEL_61;
    }
    goto LABEL_60;
  }
LABEL_62:
  v62 = (__int64 *)(v40 + 176);
  v63 = v50 + 1;
  v64 = *(_DWORD *)(v40 + 188) & 0x3FFFFFFF;
  if ( v64 < v50 + 1 )
  {
    v65 = 2 * v64;
    v66 = v50 + 1;
    if ( v63 < v65 )
      v66 = v65;
    hkArrayUtil::_reserve(&v148, &hkContainerHeapAllocator::s_alloc, (const void **)(v40 + 176), v66, 24);
  }
  v67 = v47 + 1;
  *(_DWORD *)(v40 + 184) = v63;
  if ( v47 == -1 )
  {
    pb = 0i64;
  }
  else
  {
    v148.m_enum = 24 * v67;
    pb = (hkp3AxisSweep::hkpBpNode *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerTempAllocator::s_alloc,
                                       &v148);
    v67 = v148.m_enum / 24;
  }
  v69 = 0x80000000;
  if ( v67 )
    v69 = v67;
  v134 = v69;
  v70 = v47 + 4;
  if ( v47 == -4 )
  {
    v71 = 0i64;
  }
  else
  {
    v150.m_enum = 4 * v70;
    v71 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerTempAllocator::s_alloc,
                                       &v150);
    v70 = v150.m_enum / 4;
  }
  v72 = 0x80000000;
  if ( v70 )
    v72 = v70;
  v73 = data;
  data[v47].m_key = -1;
  v73[v47 + 1].m_key = -1;
  v73[v47 + 2].m_key = -1;
  hkRadixSort::sort16(v73, (v47 + 3) & 0xFFFFFFFC, v71);
  if ( v47 > 0 )
  {
    v75 = pb;
    v76 = v47;
    v74 = &data->m_userData;
    do
    {
      v77 = *v74;
      ++v75;
      v74 += 2;
      v78 = (_QWORD *)(*v62 + 24 * v77);
      *(_QWORD *)&v75[-1].min_y = *v78;
      *(_QWORD *)&v75[-1].min_x = v78[1];
      v75[-1].m_handle = (hkpBroadPhaseHandle *)v78[2];
      --v76;
    }
    while ( v76 );
  }
  v79 = pb;
  pb[v47].min_x = -1;
  if ( v72 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v71,
      (unsigned int)(4 * v72),
      v74);
  v80 = pairsOut;
  v81 = numA;
  hkp3AxisSweep::collide1Axis((hkp3AxisSweep *)v40, pa, numA, pairsOut);
  sizeElem = v47;
  v82 = pa;
  hkp3AxisSweep::collide1Axis((hkp3AxisSweep *)v40, pa, v81, v79, sizeElem, MARKERS_IGNORE, v80);
  v83 = *(_QWORD *)(v40 + 192);
  v84 = *v62;
  v85 = v83 + 4i64 * *(int *)(v40 + 200);
  v86 = 0;
  v87 = v83;
  if ( v83 < v85 )
  {
    do
    {
      v88 = (int)v45[*(unsigned __int16 *)(v87 + 2)];
      if ( (int)v88 >= 0 )
      {
        v83 += 4i64;
        *(_DWORD *)(v83 - 4) = *(_DWORD *)v87;
        *(_WORD *)(v83 - 2) = v88;
        *(_WORD *)(v84 + hkp3AxisSweep::hkpBpNode::s_memberOffsets[*(_WORD *)v87 & 1] + 24 * v88) = v86++;
      }
      v87 += 4i64;
    }
    while ( v87 < v85 );
    LOWORD(v81) = numA;
  }
  v89 = *(_DWORD *)(v40 + 204) & 0x3FFFFFFF;
  if ( v89 < v86 )
  {
    v90 = 2 * v89;
    v91 = v86;
    if ( v86 < v90 )
      v91 = v90;
    hkArrayUtil::_reserve(&v150, &hkContainerHeapAllocator::s_alloc, (const void **)(v40 + 192), v91, 4);
  }
  *(_DWORD *)(v40 + 200) = v86;
  v92 = *(_QWORD *)(v40 + 208);
  v93 = *v62;
  v94 = v92 + 4i64 * *(int *)(v40 + 216);
  v95 = 0;
  v96 = v92;
  if ( v92 < v94 )
  {
    do
    {
      v97 = (int)v45[*(unsigned __int16 *)(v96 + 2)];
      if ( (int)v97 >= 0 )
      {
        v92 += 4i64;
        *(_DWORD *)(v92 - 4) = *(_DWORD *)v96;
        *(_WORD *)(v92 - 2) = v97;
        *(_WORD *)(v93 + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(*(_WORD *)v96 & 1) + 2] + 24 * v97) = v95++;
      }
      v96 += 4i64;
    }
    while ( v96 < v94 );
    LOWORD(v81) = numA;
  }
  v98 = *(_DWORD *)(v40 + 220) & 0x3FFFFFFF;
  if ( v98 < v95 )
  {
    v99 = 2 * v98;
    v100 = v95;
    if ( v95 < v99 )
      v100 = v99;
    hkArrayUtil::_reserve(&v150, &hkContainerHeapAllocator::s_alloc, (const void **)(v40 + 208), v100, 4);
  }
  *(_DWORD *)(v40 + 216) = v95;
  v101 = *(_QWORD *)(v40 + 224);
  v102 = *v62;
  v103 = v101 + 4i64 * *(int *)(v40 + 232);
  v104 = 0;
  v105 = v101;
  if ( v101 < v103 )
  {
    do
    {
      v106 = (int)v45[*(unsigned __int16 *)(v105 + 2)];
      if ( (int)v106 >= 0 )
      {
        v101 += 4i64;
        *(_DWORD *)(v101 - 4) = *(_DWORD *)v105;
        *(_WORD *)(v101 - 2) = v106;
        *(_WORD *)(v102 + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(*(_WORD *)v105 & 1) + 4] + 24 * v106) = v104++;
      }
      v105 += 4i64;
    }
    while ( v105 < v103 );
    v82 = pa;
  }
  v107 = *(_DWORD *)(v40 + 236) & 0x3FFFFFFF;
  if ( v107 < v104 )
  {
    v108 = 2 * v107;
    v109 = v104;
    if ( v104 < v108 )
      v109 = v108;
    hkArrayUtil::_reserve(&v150, &hkContainerHeapAllocator::s_alloc, (const void **)(v40 + 224), v109, 4);
  }
  *(_DWORD *)(v40 + 232) = v104;
  v110 = *(_DWORD *)(v40 + 240);
  if ( v110 )
  {
    v111 = 0;
    v112 = 2 * v81;
    if ( v110 > 0 )
    {
      v113 = 0i64;
      do
      {
        v114 = 0;
        v115 = 0;
        v116 = (unsigned __int16 *)(v113 + *(_QWORD *)(v40 + 248));
        v117 = 3i64 * *v116;
        v118 = *(_QWORD *)(v40 + 176);
        *(_WORD *)(v118 + 8 * v117 + 4) -= v112;
        *(_WORD *)(v118 + 8 * v117 + 6) -= v112;
        if ( *((int *)v116 + 4) > 0 )
        {
          v119 = 0i64;
          v120 = 0i64;
          do
          {
            v121 = *((_QWORD *)v116 + 1);
            v122 = v45[*(unsigned __int16 *)(v121 + v120)];
            if ( v122 >= 0 )
            {
              *(_WORD *)(v121 + v119) = v122;
              ++v115;
              v119 += 2i64;
            }
            ++v114;
            v120 += 2i64;
          }
          while ( v114 < *((_DWORD *)v116 + 4) );
        }
        v123 = v116 + 4;
        v124 = *((_DWORD *)v116 + 5) & 0x3FFFFFFF;
        if ( v124 >= v115 )
        {
          v150.m_enum = HK_SUCCESS;
        }
        else
        {
          v125 = 2 * v124;
          v126 = v115;
          if ( v115 < v125 )
            v126 = v125;
          hkArrayUtil::_reserve(&v150, &hkContainerHeapAllocator::s_alloc, (const void **)v116 + 1, v126, 2);
        }
        ++v111;
        *((_DWORD *)v123 + 2) = v115;
        v113 += 24i64;
      }
      while ( v111 < *(_DWORD *)(v40 + 240) );
    }
    v82 = pa;
  }
  v127 = 0;
  if ( v138 > 0 )
  {
    v128 = 0i64;
    do
    {
      hkp3AxisSweep::_fixDeterministicOrderAfterNodeIdWasDecreased((hkp3AxisSweep *)v40, array[v128]);
      ++v127;
      ++v128;
    }
    while ( v127 < v138 );
  }
  if ( v134 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, pb, 24 * (v134 & 0x3FFFFFFF));
  if ( v135 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, data, 4 * v135);
  if ( v132 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v45, 4 * v132);
  v138 = 0;
  if ( v139 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 4 * v139);
  array = 0i64;
  v139 = 0x80000000;
  if ( v146 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v82, 24 * (v146 & 0x3FFFFFFF));
}

// File Line: 2607
// RVA: 0xCFF170
__int64 __fastcall hkp3AxisSweep::getNumObjects(hkp3AxisSweep *this)
{
  return (unsigned int)(this->m_nodes.m_size - 1);
}

// File Line: 2616
// RVA: 0xD01EE0
void __fastcall hkp3AxisSweep::getAllAabbs(hkp3AxisSweep *this, hkArray<hkAabb,hkContainerHeapAllocator> *allAabbs)
{
  int v3; // r9d
  int v5; // ebp
  int v6; // edi
  __int64 v7; // rsi
  hkp3AxisSweep::hkpBpNode *v8; // rdx
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  v3 = this->m_nodes.m_size - this->m_numMarkers;
  if ( (allAabbs->m_capacityAndFlags & 0x3FFFFFFF) < v3 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&allAabbs->m_data, v3, 32);
  v5 = 0;
  v6 = 0;
  allAabbs->m_size = this->m_nodes.m_size - this->m_numMarkers;
  if ( this->m_nodes.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = &this->m_nodes.m_data[v7];
      if ( ((__int64)v8->m_handle & 1) == 0 )
        hkp3AxisSweep::getAabbFromNode(this, v8, &allAabbs->m_data[v5++]);
      ++v6;
      ++v7;
    }
    while ( v6 < this->m_nodes.m_size );
  }
}

// File Line: 2638
// RVA: 0xD01FA0
void __fastcall hkp3AxisSweep::getAabb(hkp3AxisSweep *this, hkpBroadPhaseHandle *object, hkAabb *aabb)
{
  hkp3AxisSweep::getAabbFromNode(this, &this->m_nodes.m_data[object->m_id], aabb);
}

// File Line: 2651
// RVA: 0xD01FC0
void __fastcall hkp3AxisSweep::getExtents(hkp3AxisSweep *this, hkVector4f *worldMinOut, hkVector4f *worldMaxOut)
{
  hkVector4f v3; // xmm1
  __m128 v4; // xmm0
  __m128 v5; // xmm2
  __m128 v6; // xmm1

  worldMinOut->m_quad = _mm_xor_ps(
                          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                          this->m_offsetLow.m_quad);
  v3.m_quad = (__m128)this->m_scale;
  v4 = _mm_rcp_ps(v3.m_quad);
  v5 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3.m_quad, v4)), v4);
  *worldMaxOut = (hkVector4f)v5;
  v6 = _mm_mul_ps(
         _mm_shuffle_ps((__m128)LODWORD(FLOAT_65532_0), (__m128)LODWORD(FLOAT_65532_0), 0),
         _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, query.m_quad), 196));
  *worldMaxOut = (hkVector4f)v6;
  worldMaxOut->m_quad = _mm_add_ps(worldMinOut->m_quad, v6);
}

// File Line: 2665
// RVA: 0xCFCB40
void __fastcall hkp3AxisSweep::checkConsistency(hkp3AxisSweep *this)
{
  ;
}

// File Line: 2818
// RVA: 0xD06D20
__int64 __fastcall getEpValue(hkp3AxisSweep::hkpBpEndPoint *ep)
{
  return ep->m_value;
}

// File Line: 2833
// RVA: 0xD058A0
hkp3AxisSweep::hkpBpEndPoint *__fastcall hkp3AxisSweep::hkpBpAxis::find(
        hkp3AxisSweep::hkpBpAxis *this,
        hkp3AxisSweep::hkpBpEndPoint *start,
        hkp3AxisSweep::hkpBpEndPoint *end,
        unsigned __int16 value)
{
  signed __int64 i; // rcx
  __int64 v5; // rcx
  int m_value; // eax

  for ( i = (char *)end - (char *)start;
        (__int64)(((char *)end - (char *)start) & 0xFFFFFFFFFFFFFFFCui64) > 64;
        i = (char *)end - (char *)start )
  {
    v5 = i >> 3;
    if ( start[v5].m_value >= value )
      end = &start[v5];
    else
      start += v5;
  }
  if ( start->m_value < (int)value )
  {
    do
    {
      m_value = start[1].m_value;
      ++start;
    }
    while ( m_value < value );
  }
  return start;
}

// File Line: 2889
// RVA: 0xD064B0
void __fastcall hkp3AxisSweep::queryBatchAabbSub(
        hkp3AxisSweep *this,
        hkp3AxisSweep *bitFieldOfQueryNodes,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut,
        hkBool addMode)
{
  char v4; // bl
  hkp3AxisSweep::hkpBpEndPoint *m_data; // rdx
  hkp3AxisSweep::hkpBpEndPoint *v8; // r8
  hkp3AxisSweep *v9; // r9
  __int64 v10; // rax
  __int64 m_nodeIndex; // rbx
  unsigned int v12; // r12d
  char **p_array; // r9
  int v14; // ecx
  __int64 v15; // rdx
  __int64 v16; // r10
  char *v17; // rax
  int v18; // esi
  __int64 v19; // r15
  __int64 v20; // r14
  hkp3AxisSweep::hkpBpNode *v21; // rdx
  hkp3AxisSweep::hkpBpNode *v22; // rbx
  __int64 v23; // r9
  __int64 v24; // rcx
  hkpBroadPhaseHandlePair *v25; // rcx
  unsigned __int64 v26; // r9
  __int64 v27; // rdi
  unsigned __int64 v28; // rbx
  __int64 v29; // r10
  int v30; // ecx
  __int64 v31; // rdx
  _WORD *v32; // rax
  int v33; // esi
  __int64 v34; // r14
  hkp3AxisSweep::hkpBpNode *v35; // rdx
  hkp3AxisSweep::hkpBpNode *v36; // rbx
  __int64 v37; // r8
  __int64 v38; // rcx
  hkpBroadPhaseHandlePair *v39; // rcx
  unsigned __int64 v40; // r8
  __int64 v41; // rdi
  unsigned __int64 v42; // rbx
  __int64 v43; // r10
  int v44; // ecx
  __int64 v45; // rdx
  _WORD *v46; // rax
  unsigned __int16 v47; // [rsp+20h] [rbp-D8h]
  hkp3AxisSweep::hkpBpEndPoint *v48; // [rsp+28h] [rbp-D0h]
  unsigned __int64 v49; // [rsp+30h] [rbp-C8h]
  char *v50; // [rsp+40h] [rbp-B8h] BYREF
  int v51; // [rsp+48h] [rbp-B0h]
  int v52; // [rsp+4Ch] [rbp-ACh]
  char v53; // [rsp+50h] [rbp-A8h] BYREF
  __int64 *array; // [rsp+248h] [rbp+150h] BYREF
  int v55; // [rsp+250h] [rbp+158h]
  int v56; // [rsp+254h] [rbp+15Ch]
  __int64 v57; // [rsp+260h] [rbp+168h] BYREF
  hkp3AxisSweep *retaddr; // [rsp+498h] [rbp+3A0h]
  char v60; // [rsp+4B0h] [rbp+3B8h]

  m_data = this->m_axis[0].m_endPoints.m_data;
  array = &v57;
  v50 = &v53;
  v8 = m_data + 1;
  v9 = this;
  v10 = this->m_axis[0].m_endPoints.m_size - 1;
  v55 = 0;
  v56 = -2147483392;
  v51 = 0;
  v52 = -2147483392;
  v49 = (unsigned __int64)&m_data[v10];
  v48 = m_data + 1;
  if ( (unsigned __int64)&m_data[1] < v49 )
  {
    v60 = v4;
    do
    {
      m_nodeIndex = v8->m_nodeIndex;
      v47 = v8->m_nodeIndex;
      v12 = *((_DWORD *)&bitFieldOfQueryNodes->vfptr + (m_nodeIndex >> 5)) & (1 << (v47 & 0x1F));
      if ( (v8->m_value & 1) != 0 )
      {
        p_array = (char **)&array;
        if ( !v12 )
          p_array = &v50;
        v14 = 0;
        v15 = 0i64;
        v16 = *((int *)p_array + 2);
        if ( (int)v16 <= 0 )
        {
LABEL_10:
          v14 = -1;
          v15 = -1i64;
        }
        else
        {
          v17 = *p_array;
          while ( *(_WORD *)v17 != (_WORD)m_nodeIndex )
          {
            ++v15;
            ++v14;
            v17 += 2;
            if ( v15 >= v16 )
              goto LABEL_10;
          }
        }
        *((_DWORD *)p_array + 2) = v16 - 1;
        if ( (_DWORD)v16 - 1 != v14 )
          *(_WORD *)&(*p_array)[2 * v15] = *(_WORD *)&(*p_array)[2 * (int)v16 - 2];
        goto LABEL_63;
      }
      v18 = 0;
      v19 = (__int64)&v9->m_nodes.m_data[m_nodeIndex];
      if ( v55 <= 0 )
        goto LABEL_35;
      v20 = 0i64;
      do
      {
        v21 = retaddr->m_nodes.m_data;
        v22 = &v21[*(unsigned __int16 *)((char *)array + v20)];
        if ( (((*(_DWORD *)(v19 + 4) - *(_DWORD *)&v22->min_y) | (*(_DWORD *)&v22->max_y - *(_DWORD *)v19)) & 0x80008000) != 0 )
          goto LABEL_33;
        v23 = v19;
        v24 = (__int64)&v21[*(unsigned __int16 *)((char *)array + v20)];
        if ( (*(_BYTE *)(v19 + 16) & 1) == 0 )
        {
          if ( ((__int64)v22->m_handle & 1) == 0 )
          {
            if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 16);
            v25 = &pairsOut->m_data[pairsOut->m_size++];
            v25->m_a = v22->m_handle;
            v25->m_b = *(hkpBroadPhaseHandle **)(v19 + 16);
            goto LABEL_33;
          }
          v24 = v19;
          v23 = (__int64)&v21[*(unsigned __int16 *)((char *)array + v20)];
        }
        v26 = (unsigned __int64)retaddr->m_markers + (*(_QWORD *)(v23 + 16) & 0xFFFFFFFFFFFFFFFEui64);
        v27 = (v24 - (__int64)v21) / 24;
        if ( v60 )
        {
          v28 = v26 + 8;
          if ( *(_DWORD *)(v26 + 16) == (*(_DWORD *)(v26 + 20) & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)(v26 + 8), 2);
          *(_WORD *)(*(_QWORD *)v28 + 2i64 * (int)(*(_DWORD *)(v28 + 8))++) = v27;
        }
        else
        {
          v29 = *(int *)(v26 + 16);
          v30 = 0;
          v31 = 0i64;
          if ( (int)v29 <= 0 )
          {
LABEL_30:
            v30 = -1;
            v31 = -1i64;
          }
          else
          {
            v32 = *(_WORD **)(v26 + 8);
            while ( *v32 != (_WORD)v27 )
            {
              ++v31;
              ++v30;
              ++v32;
              if ( v31 >= v29 )
                goto LABEL_30;
            }
          }
          *(_DWORD *)(v26 + 16) = v29 - 1;
          if ( (_DWORD)v29 - 1 != v30 )
            *(_WORD *)(*(_QWORD *)(v26 + 8) + 2 * v31) = *(_WORD *)(*(_QWORD *)(v26 + 8) + 2i64 * ((int)v29 - 1));
        }
LABEL_33:
        ++v18;
        v20 += 2i64;
      }
      while ( v18 < v55 );
      v9 = retaddr;
      LOWORD(m_nodeIndex) = v47;
LABEL_35:
      if ( v12 )
      {
        v33 = 0;
        if ( v51 > 0 )
        {
          v34 = 0i64;
          do
          {
            v35 = v9->m_nodes.m_data;
            v36 = &v35[*(unsigned __int16 *)&v50[v34]];
            if ( (((*(_DWORD *)(v19 + 4) - *(_DWORD *)&v36->min_y) | (*(_DWORD *)&v36->max_y - *(_DWORD *)v19)) & 0x80008000) == 0 )
            {
              v37 = v19;
              v38 = (__int64)&v35[*(unsigned __int16 *)&v50[v34]];
              if ( (*(_BYTE *)(v19 + 16) & 1) != 0 )
                goto LABEL_45;
              if ( ((__int64)v36->m_handle & 1) != 0 )
              {
                v38 = v19;
                v37 = (__int64)&v35[*(unsigned __int16 *)&v50[v34]];
LABEL_45:
                v40 = (unsigned __int64)v9->m_markers + (*(_QWORD *)(v37 + 16) & 0xFFFFFFFFFFFFFFFEui64);
                v41 = (v38 - (__int64)v35) / 24;
                if ( v60 )
                {
                  v42 = v40 + 8;
                  if ( *(_DWORD *)(v40 + 16) == (*(_DWORD *)(v40 + 20) & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v42, 2);
                  *(_WORD *)(*(_QWORD *)v42 + 2i64 * (int)(*(_DWORD *)(v42 + 8))++) = v41;
                }
                else
                {
                  v43 = *(int *)(v40 + 16);
                  v44 = 0;
                  v45 = 0i64;
                  if ( (int)v43 <= 0 )
                  {
LABEL_53:
                    v44 = -1;
                    v45 = -1i64;
                  }
                  else
                  {
                    v46 = *(_WORD **)(v40 + 8);
                    while ( *v46 != (_WORD)v41 )
                    {
                      ++v45;
                      ++v44;
                      ++v46;
                      if ( v45 >= v43 )
                        goto LABEL_53;
                    }
                  }
                  *(_DWORD *)(v40 + 16) = v43 - 1;
                  if ( (_DWORD)v43 - 1 != v44 )
                    *(_WORD *)(*(_QWORD *)(v40 + 8) + 2 * v45) = *(_WORD *)(*(_QWORD *)(v40 + 8) + 2i64 * ((int)v43 - 1));
                }
                goto LABEL_56;
              }
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 16);
              v39 = &pairsOut->m_data[pairsOut->m_size++];
              v39->m_a = v36->m_handle;
              v39->m_b = *(hkpBroadPhaseHandle **)(v19 + 16);
            }
LABEL_56:
            v9 = retaddr;
            ++v33;
            v34 += 2i64;
          }
          while ( v33 < v51 );
        }
        if ( v55 == (v56 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 2);
        *((_WORD *)array + v55++) = v47;
      }
      else
      {
        if ( v51 == (v52 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v50, 2);
        *(_WORD *)&v50[2 * v51++] = m_nodeIndex;
      }
LABEL_63:
      v9 = retaddr;
      bitFieldOfQueryNodes = this;
      v8 = v48 + 1;
      v48 = v8;
    }
    while ( (unsigned __int64)v8 < v49 );
  }
  v51 = 0;
  if ( v52 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, hkp3AxisSweep *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v50,
      2 * (v52 & 0x3FFFFFFFu),
      v9);
  v50 = 0i64;
  v52 = 0x80000000;
  v55 = 0;
  if ( v56 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64 *, _QWORD, hkp3AxisSweep *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      2 * (v56 & 0x3FFFFFFFu),
      v9);
}

// File Line: 3186
// RVA: 0xD01110
void __fastcall hkp3AxisSweep::querySingleAabb(
        hkp3AxisSweep *this,
        hkAabb *aabbIn,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  int m_size; // edi
  int v7; // eax
  _DWORD *v8; // r14
  unsigned int v9; // ecx
  int v10; // edi
  _OWORD *i; // rcx
  _OWORD *v12; // rax
  hkp3AxisSweep::hkpBpEndPoint *v13; // r8
  __m128 v14; // xmm0
  __m128i v15; // xmm1
  int v16; // r10d
  __m128 v17; // xmm0
  __m128i v18; // xmm6
  unsigned int v19; // r11d
  int v20; // edx
  hkp3AxisSweep::hkpBpMarker *v21; // rdi
  unsigned __int16 *m_data; // r8
  int j; // r9d
  int v24; // ecx
  hkp3AxisSweep::hkpBpNode *v25; // rdi
  hkp3AxisSweep::hkpBpEndPoint *v26; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v27; // r8
  hkp3AxisSweep::hkpBpEndPoint *k; // r9
  int m_nodeIndex; // ecx
  unsigned int m; // eax
  hkp3AxisSweep::hkpBpEndPoint *v31; // r15
  hkp3AxisSweep::hkpBpEndPoint *v32; // rdi
  hkp3AxisSweep::hkpBpEndPoint *v33; // r15
  hkp3AxisSweep::hkpBpEndPoint *v34; // rdi
  hkp3AxisSweep::hkpBpEndPoint *v35; // rax
  void *v36; // rdx
  unsigned int *v37; // r8
  unsigned __int64 v38; // rax
  int v39; // r14d
  int v40; // r15d
  unsigned __int16 *p_max_y; // r13
  unsigned int v42; // esi
  unsigned __int16 *v43; // rdi
  hkpBroadPhaseHandle *v44; // r12
  hkpBroadPhaseHandlePair *v45; // rax
  hkpBroadPhaseHandle *v46; // r12
  hkpBroadPhaseHandlePair *v47; // rax
  hkpBroadPhaseHandle *v48; // r12
  hkpBroadPhaseHandlePair *v49; // rax
  hkpBroadPhaseHandle *v50; // r12
  hkpBroadPhaseHandlePair *v51; // rax
  unsigned __int64 v52; // [rsp+0h] [rbp-59h]
  unsigned __int64 v53; // [rsp+0h] [rbp-59h]
  unsigned __int64 v54; // [rsp+10h] [rbp-49h]
  unsigned __int64 v55; // [rsp+10h] [rbp-49h]
  __int64 v56; // [rsp+20h] [rbp-39h]
  int v57; // [rsp+C0h] [rbp+67h] BYREF
  int v58; // [rsp+C8h] [rbp+6Fh]
  unsigned __int64 v59; // [rsp+D8h] [rbp+7Fh]

  m_size = this->m_nodes.m_size;
  v7 = (m_size >> 5) + 8;
  if ( m_size >> 5 == -8 )
  {
    v8 = 0i64;
  }
  else
  {
    v57 = 4 * v7;
    v8 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v57);
    v7 = v57 / 4;
  }
  v9 = 0x80000000;
  v59 = (unsigned __int64)v8;
  if ( v7 )
    v9 = v7;
  v10 = m_size >> 7;
  v58 = v9;
  for ( i = v8; v10 >= 0; *v12 = 0i64 )
  {
    v12 = i++;
    --v10;
  }
  v13 = this->m_axis[0].m_endPoints.m_data + 1;
  v14 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(this->m_offsetLow.m_quad, aabbIn->m_min.m_quad), this->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v15 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v14),
            _mm_cvttps_epi32(v14)),
          (__m128i)_xmm);
  v52 = _mm_add_epi16(_mm_packs_epi32(v15, v15), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v16 = v52 & 0xFFFE;
  v17 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(this->m_offsetHigh.m_quad, aabbIn->m_max.m_quad), this->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v18 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v17),
            _mm_cvttps_epi32(v17)),
          (__m128i)_xmm);
  v54 = _mm_add_epi16(_mm_packs_epi32(v18, v18), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v19 = (unsigned __int16)v54 | 1;
  if ( this->m_numMarkers )
  {
    v20 = v16 >> (16 - LOBYTE(this->m_ld2NumMarkers));
    if ( v20 > 0 )
    {
      v21 = &this->m_markers[v20 - 1];
      v8[(int)v21->m_nodeIndex >> 5] ^= 1 << (v21->m_nodeIndex & 0x1F);
      m_data = v21->m_overlappingObjects.m_data;
      for ( j = v21->m_overlappingObjects.m_size - 1; j >= 0; --j )
      {
        v24 = *m_data++;
        v8[v24 >> 5] ^= 1 << (v24 & 0x1F);
      }
      v25 = &this->m_nodes.m_data[v21->m_nodeIndex];
      v26 = this->m_axis[0].m_endPoints.m_data;
      v27 = &v26[v25->min_x + 1];
      for ( k = &v26[v25->max_x]; v27 < k; ++v27 )
      {
        if ( (v27->m_value & 1) == 0 )
          v8[(int)v27->m_nodeIndex >> 5] &= ~(1 << (v27->m_nodeIndex & 0x1F));
      }
      v13 = &this->m_axis[0].m_endPoints.m_data[v25->min_x + 1];
    }
  }
  for ( ; v13->m_value < (unsigned int)v16; v8[m_nodeIndex >> 5] ^= 1 << (m_nodeIndex & 0x1F) )
  {
    m_nodeIndex = v13->m_nodeIndex;
    ++v13;
  }
  for ( m = v13->m_value; m < v19; ++v13 )
  {
    if ( (m & 1) == 0 )
      v8[(int)v13->m_nodeIndex >> 5] ^= 1 << (v13->m_nodeIndex & 0x1F);
    m = v13[1].m_value;
  }
  v31 = this->m_axis[1].m_endPoints.m_data;
  v32 = &v31[this->m_axis[1].m_endPoints.m_size];
  hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[1], v31 + 1, v32 - 2, WORD1(v52) & 0xFFFE);
  hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[1], v31 + 1, v32 - 2, WORD1(v54) | 1);
  v33 = this->m_axis[2].m_endPoints.m_data;
  v34 = &v33[this->m_axis[2].m_endPoints.m_size];
  hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[2], v33 + 1, v34 - 2, WORD2(v52) & 0xFFFE);
  v35 = hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[2], v33 + 1, v34 - 2, WORD2(v54) | 1u);
  v36 = (void *)v59;
  v37 = (unsigned int *)v59;
  v55 = v59;
  HIWORD(v56) = ((__int64)v35 - 4 - (__int64)v33) >> 2;
  v38 = v59 + 4 * (((__int64)this->m_nodes.m_size >> 5) + 1);
  v53 = v38;
  if ( v59 < v38 )
  {
    v39 = HIDWORD(v56);
    v40 = v56;
    p_max_y = &this->m_nodes.m_data[2].max_y;
    do
    {
      v42 = *v37;
      if ( *v37 )
      {
        v43 = p_max_y;
        do
        {
          if ( (v42 & 0xF) != 0 )
          {
            if ( (v42 & 1) != 0
              && (((*((_DWORD *)v43 - 12) - v40) | (v39 - *((_DWORD *)v43 - 13))) & 0x80008000) == 0
              && (*(_BYTE *)(v43 - 18) & 1) == 0 )
            {
              v44 = *(hkpBroadPhaseHandle **)(v43 - 18);
              if ( pairs_out->m_size == (pairs_out->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairs_out->m_data, 16);
              v45 = &pairs_out->m_data[pairs_out->m_size];
              if ( v45 )
              {
                v45->m_a = 0i64;
                v45->m_b = v44;
              }
              ++pairs_out->m_size;
            }
            if ( (v42 & 2) != 0
              && (((*((_DWORD *)v43 - 6) - v40) | (v39 - *((_DWORD *)v43 - 7))) & 0x80008000) == 0
              && (*(_BYTE *)(v43 - 6) & 1) == 0 )
            {
              v46 = *(hkpBroadPhaseHandle **)(v43 - 6);
              if ( pairs_out->m_size == (pairs_out->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairs_out->m_data, 16);
              v47 = &pairs_out->m_data[pairs_out->m_size];
              if ( v47 )
              {
                v47->m_a = 0i64;
                v47->m_b = v46;
              }
              ++pairs_out->m_size;
            }
            if ( (v42 & 4) != 0
              && (((*(_DWORD *)v43 - v40) | (v39 - *((_DWORD *)v43 - 1))) & 0x80008000) == 0
              && (v43[6] & 1) == 0 )
            {
              v48 = *(hkpBroadPhaseHandle **)(v43 + 6);
              if ( pairs_out->m_size == (pairs_out->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairs_out->m_data, 16);
              v49 = &pairs_out->m_data[pairs_out->m_size];
              if ( v49 )
              {
                v49->m_a = 0i64;
                v49->m_b = v48;
              }
              ++pairs_out->m_size;
            }
            if ( (v42 & 8) != 0
              && (((*((_DWORD *)v43 + 6) - v40) | (v39 - *((_DWORD *)v43 + 5))) & 0x80008000) == 0
              && (v43[18] & 1) == 0 )
            {
              v50 = *(hkpBroadPhaseHandle **)(v43 + 18);
              if ( pairs_out->m_size == (pairs_out->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairs_out->m_data, 16);
              v51 = &pairs_out->m_data[pairs_out->m_size];
              if ( v51 )
              {
                v51->m_a = 0i64;
                v51->m_b = v50;
              }
              ++pairs_out->m_size;
            }
          }
          v42 >>= 4;
          v43 += 48;
        }
        while ( v42 );
        v37 = (unsigned int *)v55;
        v38 = v53;
      }
      ++v37;
      p_max_y += 384;
      v55 = (unsigned __int64)v37;
    }
    while ( (unsigned __int64)v37 < v38 );
    v36 = (void *)v59;
  }
  if ( v58 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v36, 4 * v58);
}

// File Line: 3192
// RVA: 0xD01710
void __fastcall hkp3AxisSweep::querySingleAabbWithCollector(
        hkp3AxisSweep *this,
        hkAabb *aabbIn,
        hkpBroadPhaseCastCollector *collector)
{
  int m_size; // ebx
  int v7; // eax
  _DWORD *v8; // r12
  unsigned int v9; // ecx
  int v10; // ebx
  _OWORD *i; // rcx
  _OWORD *v12; // rax
  hkp3AxisSweep::hkpBpEndPoint *v13; // r8
  __m128 v14; // xmm0
  __m128i v15; // xmm1
  int v16; // r10d
  __m128 v17; // xmm0
  __m128i v18; // xmm6
  unsigned int v19; // r11d
  int v20; // edx
  hkp3AxisSweep::hkpBpMarker *v21; // rbx
  unsigned __int16 *m_data; // r8
  int j; // r9d
  int v24; // ecx
  hkp3AxisSweep::hkpBpNode *v25; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v26; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v27; // r8
  hkp3AxisSweep::hkpBpEndPoint *k; // r9
  int m_nodeIndex; // ecx
  unsigned int m; // eax
  hkp3AxisSweep::hkpBpEndPoint *v31; // rbp
  __int64 v32; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v33; // rax
  __int64 v34; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v35; // rbp
  __int64 v36; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v37; // rax
  hkp3AxisSweep::hkpBpNode *v38; // rcx
  unsigned int *v39; // r14
  unsigned __int64 v40; // rax
  unsigned __int16 *p_max_y; // r13
  unsigned int v42; // edi
  unsigned __int16 *v43; // rbx
  unsigned __int64 v44; // [rsp+20h] [rbp-B8h]
  unsigned __int64 v45; // [rsp+30h] [rbp-A8h]
  int v46; // [rsp+40h] [rbp-98h]
  int v47; // [rsp+44h] [rbp-94h]
  int v48; // [rsp+E0h] [rbp+8h] BYREF
  int v49; // [rsp+E8h] [rbp+10h]
  unsigned __int64 v50; // [rsp+F8h] [rbp+20h]

  m_size = this->m_nodes.m_size;
  v7 = (m_size >> 5) + 8;
  if ( m_size >> 5 == -8 )
  {
    v8 = 0i64;
  }
  else
  {
    v48 = 4 * v7;
    v8 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v48);
    v7 = v48 / 4;
  }
  v9 = 0x80000000;
  if ( v7 )
    v9 = v7;
  v10 = m_size >> 7;
  v49 = v9;
  for ( i = v8; v10 >= 0; *v12 = 0i64 )
  {
    v12 = i++;
    --v10;
  }
  v13 = this->m_axis[0].m_endPoints.m_data + 1;
  v14 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(this->m_offsetLow.m_quad, aabbIn->m_min.m_quad), this->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v15 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v14),
            _mm_cvttps_epi32(v14)),
          (__m128i)_xmm);
  v44 = _mm_add_epi16(_mm_packs_epi32(v15, v15), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v16 = v44 & 0xFFFE;
  v17 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(this->m_offsetHigh.m_quad, aabbIn->m_max.m_quad), this->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v18 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v17),
            _mm_cvttps_epi32(v17)),
          (__m128i)_xmm);
  v45 = _mm_add_epi16(_mm_packs_epi32(v18, v18), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v19 = (unsigned __int16)v45 | 1;
  if ( this->m_numMarkers )
  {
    v20 = v16 >> (16 - LOBYTE(this->m_ld2NumMarkers));
    if ( v20 > 0 )
    {
      v21 = &this->m_markers[v20 - 1];
      v8[(int)v21->m_nodeIndex >> 5] ^= 1 << (v21->m_nodeIndex & 0x1F);
      m_data = v21->m_overlappingObjects.m_data;
      for ( j = v21->m_overlappingObjects.m_size - 1; j >= 0; --j )
      {
        v24 = *m_data++;
        v8[v24 >> 5] ^= 1 << (v24 & 0x1F);
      }
      v25 = &this->m_nodes.m_data[v21->m_nodeIndex];
      v26 = this->m_axis[0].m_endPoints.m_data;
      v27 = &v26[v25->min_x + 1];
      for ( k = &v26[v25->max_x]; v27 < k; ++v27 )
      {
        if ( (v27->m_value & 1) == 0 )
          v8[(int)v27->m_nodeIndex >> 5] &= ~(1 << (v27->m_nodeIndex & 0x1F));
      }
      v13 = &this->m_axis[0].m_endPoints.m_data[v25->min_x + 1];
    }
  }
  for ( ; v13->m_value < (unsigned int)v16; v8[m_nodeIndex >> 5] ^= 1 << (m_nodeIndex & 0x1F) )
  {
    m_nodeIndex = v13->m_nodeIndex;
    ++v13;
  }
  for ( m = v13->m_value; m < v19; ++v13 )
  {
    if ( (m & 1) == 0 )
      v8[(int)v13->m_nodeIndex >> 5] ^= 1 << (v13->m_nodeIndex & 0x1F);
    m = v13[1].m_value;
  }
  v31 = this->m_axis[1].m_endPoints.m_data;
  v32 = this->m_axis[1].m_endPoints.m_size;
  LOWORD(v46) = hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[1], v31 + 1, &v31[v32 - 2], WORD1(v44) & 0xFFFE) - v31;
  v33 = hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[1], v31 + 1, &v31[v32 - 2], WORD1(v45) | 1u);
  v34 = -4i64 - (_QWORD)v31;
  v35 = this->m_axis[2].m_endPoints.m_data;
  LOWORD(v47) = ((__int64)v33 + v34) >> 2;
  v36 = this->m_axis[2].m_endPoints.m_size;
  HIWORD(v46) = hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[2], v35 + 1, &v35[v36 - 2], WORD2(v44) & 0xFFFE) - v35;
  v37 = hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[2], v35 + 1, &v35[v36 - 2], WORD2(v45) | 1u);
  v38 = this->m_nodes.m_data;
  v39 = v8;
  HIWORD(v47) = ((__int64)v37 - 4 - (__int64)v35) >> 2;
  v40 = (unsigned __int64)&v8[((__int64)this->m_nodes.m_size >> 5) + 1];
  v50 = v40;
  if ( (unsigned __int64)v8 < v40 )
  {
    p_max_y = &v38[2].max_y;
    do
    {
      v42 = *v39;
      if ( *v39 )
      {
        v43 = p_max_y;
        do
        {
          if ( (v42 & 0xF) != 0 )
          {
            if ( (v42 & 1) != 0
              && (((*((_DWORD *)v43 - 12) - v46) | (v47 - *((_DWORD *)v43 - 13))) & 0x80008000) == 0
              && (*(_BYTE *)(v43 - 18) & 1) == 0 )
            {
              collector->vfptr->addBroadPhaseHandle(collector, *(hkpBroadPhaseHandle **)(v43 - 18), 0);
            }
            if ( (v42 & 2) != 0
              && (((*((_DWORD *)v43 - 6) - v46) | (v47 - *((_DWORD *)v43 - 7))) & 0x80008000) == 0
              && (*(_BYTE *)(v43 - 6) & 1) == 0 )
            {
              collector->vfptr->addBroadPhaseHandle(collector, *(hkpBroadPhaseHandle **)(v43 - 6), 0);
            }
            if ( (v42 & 4) != 0
              && (((*(_DWORD *)v43 - v46) | (v47 - *((_DWORD *)v43 - 1))) & 0x80008000) == 0
              && (v43[6] & 1) == 0 )
            {
              collector->vfptr->addBroadPhaseHandle(collector, *(hkpBroadPhaseHandle **)(v43 + 6), 0);
            }
            if ( (v42 & 8) != 0
              && (((*((_DWORD *)v43 + 6) - v46) | (v47 - *((_DWORD *)v43 + 5))) & 0x80008000) == 0
              && (v43[18] & 1) == 0 )
            {
              collector->vfptr->addBroadPhaseHandle(collector, *(hkpBroadPhaseHandle **)(v43 + 18), 0);
            }
          }
          v42 >>= 4;
          v43 += 48;
        }
        while ( v42 );
        v40 = v50;
      }
      ++v39;
      p_max_y += 384;
    }
    while ( (unsigned __int64)v39 < v40 );
  }
  if ( v49 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v8, 4 * v49);
}

// File Line: 3200
// RVA: 0xD03510
__int64 __fastcall hkp3AxisSweep::getAabbCacheSize(hkp3AxisSweep *this)
{
  return (unsigned int)(24 * (this->m_nodes.m_size - this->m_numMarkers + 2));
}

// File Line: 3216
// RVA: 0xD03530
void __fastcall hkp3AxisSweep::calcAabbCache(hkp3AxisSweep *this, hkAabb *aabb, char *AabbCacheOut)
{
  int m_size; // r9d
  int v4; // r12d
  int v7; // ebx
  __int32 v8; // eax
  char *v9; // rax
  char *v10; // r13
  unsigned int v11; // ecx
  int v12; // ebx
  char *v13; // rcx
  char *v14; // rax
  hkp3AxisSweep::hkpBpEndPoint *v15; // r8
  __m128 v16; // xmm0
  __m128i v17; // xmm1
  __m128 v18; // xmm0
  int v19; // r10d
  __m128 v20; // xmm0
  __m128i v21; // xmm6
  unsigned int v22; // r11d
  bool v23; // zf
  int v24; // edx
  hkp3AxisSweep::hkpBpMarker *v25; // rbx
  unsigned __int16 *m_data; // r8
  int i; // r9d
  int v28; // ecx
  hkp3AxisSweep::hkpBpNode *v29; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v30; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v31; // r8
  hkp3AxisSweep::hkpBpEndPoint *j; // r9
  int m_nodeIndex; // ecx
  unsigned int m_value; // eax
  hkp3AxisSweep::hkpBpEndPoint *v35; // r14
  hkp3AxisSweep::hkpBpEndPoint *v36; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v37; // rax
  hkp3AxisSweep *v38; // rsi
  __int64 v39; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v40; // r14
  hkp3AxisSweep::hkpBpEndPoint *v41; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v42; // rax
  hkp3AxisSweep::hkpBpNode *v43; // rdi
  char *v44; // rbx
  char *v45; // r14
  int v46; // r9d
  int v47; // r10d
  unsigned __int16 *p_max_y; // rdi
  unsigned int v49; // r8d
  unsigned __int16 *v50; // rax
  unsigned __int64 v51; // [rsp+0h] [rbp-79h]
  unsigned __int64 v52; // [rsp+10h] [rbp-69h]
  hkArrayBase<hkp3AxisSweep::hkpBpNode const *> array; // [rsp+20h] [rbp-59h] BYREF
  int sizeElem; // [rsp+30h] [rbp-49h]
  int v55; // [rsp+34h] [rbp-45h]
  int v56; // [rsp+54h] [rbp-25h]
  int v57; // [rsp+58h] [rbp-21h]
  int v58; // [rsp+64h] [rbp-15h]
  int v59; // [rsp+68h] [rbp-11h]
  hkp3AxisSweep *v60; // [rsp+E0h] [rbp+67h]
  hkResult result; // [rsp+E8h] [rbp+6Fh] BYREF
  char *AabbCacheOuta; // [rsp+F0h] [rbp+77h]
  int v63; // [rsp+F8h] [rbp+7Fh]

  m_size = this->m_nodes.m_size;
  v4 = 0;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  if ( m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, m_size, 8);
    v4 = array.m_size;
  }
  v7 = this->m_nodes.m_size;
  v8 = (v7 >> 5) + 8;
  if ( v7 >> 5 == -8 )
  {
    v10 = 0i64;
  }
  else
  {
    result.m_enum = 4 * v8;
    v9 = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &result);
    v4 = array.m_size;
    v10 = v9;
    v8 = result.m_enum / 4;
  }
  v11 = 0x80000000;
  if ( v8 )
    v11 = v8;
  v12 = v7 >> 7;
  v63 = v11;
  v13 = v10;
  if ( v12 >= 0 )
  {
    do
    {
      v14 = v13;
      v13 += 16;
      --v12;
      *(_OWORD *)v14 = 0i64;
    }
    while ( v12 >= 0 );
    v4 = array.m_size;
  }
  v15 = this->m_axis[0].m_endPoints.m_data + 1;
  v16 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(this->m_offsetLow.m_quad, aabb->m_min.m_quad), this->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v17 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v16),
            _mm_cvttps_epi32(v16)),
          (__m128i)_xmm);
  v18 = _mm_min_ps(
          _mm_mul_ps(_mm_add_ps(this->m_offsetHigh.m_quad, aabb->m_max.m_quad), this->m_scale.m_quad),
          hkp3AxisSweep::MaxVal);
  v51 = _mm_add_epi16(_mm_packs_epi32(v17, v17), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v19 = v51 & 0xFFFE;
  v56 = WORD1(v51) & 0xFFFE;
  v20 = _mm_max_ps(v18, (__m128)0i64);
  v57 = WORD2(v51) & 0xFFFE;
  v21 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v20),
            _mm_cvttps_epi32(v20)),
          (__m128i)_xmm);
  v52 = _mm_add_epi16(_mm_packs_epi32(v21, v21), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v22 = (unsigned __int16)v52 | 1;
  v58 = WORD1(v52) | 1;
  v23 = this->m_numMarkers == 0;
  v59 = WORD2(v52) | 1;
  if ( !v23 )
  {
    v24 = v19 >> (16 - LOBYTE(this->m_ld2NumMarkers));
    if ( v24 > 0 )
    {
      v25 = &this->m_markers[v24 - 1];
      *(_DWORD *)&v10[4 * ((int)v25->m_nodeIndex >> 5)] ^= 1 << (v25->m_nodeIndex & 0x1F);
      m_data = v25->m_overlappingObjects.m_data;
      for ( i = v25->m_overlappingObjects.m_size - 1; i >= 0; --i )
      {
        v28 = *m_data++;
        *(_DWORD *)&v10[4 * (v28 >> 5)] ^= 1 << (v28 & 0x1F);
      }
      v29 = &this->m_nodes.m_data[v25->m_nodeIndex];
      v30 = this->m_axis[0].m_endPoints.m_data;
      v31 = &v30[v29->min_x + 1];
      for ( j = &v30[v29->max_x]; v31 < j; ++v31 )
      {
        if ( (v31->m_value & 1) == 0 )
          *(_DWORD *)&v10[4 * ((int)v31->m_nodeIndex >> 5)] &= ~(1 << (v31->m_nodeIndex & 0x1F));
      }
      v4 = array.m_size;
      v15 = &this->m_axis[0].m_endPoints.m_data[v29->min_x + 1];
    }
  }
  if ( v15->m_value < (unsigned int)v19 )
  {
    do
    {
      m_nodeIndex = v15->m_nodeIndex;
      ++v15;
      *(_DWORD *)&v10[4 * (m_nodeIndex >> 5)] ^= 1 << (m_nodeIndex & 0x1F);
    }
    while ( v15->m_value < (unsigned int)v19 );
    v4 = array.m_size;
  }
  m_value = v15->m_value;
  if ( m_value < v22 )
  {
    do
    {
      if ( (m_value & 1) == 0 )
        *(_DWORD *)&v10[4 * ((int)v15->m_nodeIndex >> 5)] ^= 1 << (v15->m_nodeIndex & 0x1F);
      m_value = v15[1].m_value;
      ++v15;
    }
    while ( m_value < v22 );
    v4 = array.m_size;
  }
  v35 = this->m_axis[1].m_endPoints.m_data;
  v36 = &v35[this->m_axis[1].m_endPoints.m_size];
  LOWORD(sizeElem) = hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[1], v35 + 1, v36 - 2, v56) - v35;
  v37 = hkp3AxisSweep::hkpBpAxis::find(&this->m_axis[1], v35 + 1, v36 - 2, v58);
  v38 = v60;
  v39 = -4i64 - (_QWORD)v35;
  v40 = v60->m_axis[2].m_endPoints.m_data;
  LOWORD(v55) = ((__int64)v37 + v39) >> 2;
  v41 = &v40[v60->m_axis[2].m_endPoints.m_size];
  HIWORD(sizeElem) = hkp3AxisSweep::hkpBpAxis::find(&v60->m_axis[2], v40 + 1, v41 - 2, v57) - v40;
  v42 = hkp3AxisSweep::hkpBpAxis::find(&v38->m_axis[2], v40 + 1, v41 - 2, v59);
  v43 = v38->m_nodes.m_data;
  v44 = v10;
  HIWORD(v55) = ((__int64)v42 - 4 - (__int64)v40) >> 2;
  v45 = &v10[4 * ((__int64)v38->m_nodes.m_size >> 5) + 4];
  if ( v10 < v45 )
  {
    v46 = v55;
    v47 = sizeElem;
    p_max_y = &v43[2].max_y;
    do
    {
      v49 = *(_DWORD *)v44;
      if ( *(_DWORD *)v44 )
      {
        v50 = p_max_y;
        do
        {
          if ( (v49 & 0xF) != 0 )
          {
            if ( (v49 & 1) != 0
              && (((v46 - *((_DWORD *)v50 - 13)) | (*((_DWORD *)v50 - 12) - v47)) & 0x80008000) == 0
              && (*(_BYTE *)(v50 - 18) & 1) == 0 )
            {
              array.m_data[v4] = (hkp3AxisSweep::hkpBpNode *)(v50 - 26);
              v4 = ++array.m_size;
            }
            if ( (v49 & 2) != 0
              && (((v46 - *((_DWORD *)v50 - 7)) | (*((_DWORD *)v50 - 6) - v47)) & 0x80008000) == 0
              && (*(_BYTE *)(v50 - 6) & 1) == 0 )
            {
              array.m_data[v4] = (hkp3AxisSweep::hkpBpNode *)(v50 - 14);
              v4 = ++array.m_size;
            }
            if ( (v49 & 4) != 0
              && (((*(_DWORD *)v50 - v47) | (v46 - *((_DWORD *)v50 - 1))) & 0x80008000) == 0
              && (v50[6] & 1) == 0 )
            {
              array.m_data[v4] = (hkp3AxisSweep::hkpBpNode *)(v50 - 2);
              v4 = ++array.m_size;
            }
            if ( (v49 & 8) != 0
              && (((v46 - *((_DWORD *)v50 + 5)) | (*((_DWORD *)v50 + 6) - v47)) & 0x80008000) == 0
              && (v50[18] & 1) == 0 )
            {
              array.m_data[v4] = (hkp3AxisSweep::hkpBpNode *)(v50 + 10);
              v4 = ++array.m_size;
            }
          }
          v49 >>= 4;
          v50 += 48;
        }
        while ( v49 );
      }
      v44 += 4;
      p_max_y += 384;
    }
    while ( v44 < v45 );
  }
  if ( v63 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v10, 4 * v63);
  hkp3AxisSweep::calcAabbCacheInternal(v38, &array, AabbCacheOuta);
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
}

// File Line: 3232
// RVA: 0xD03B60
void __fastcall hkp3AxisSweep::calcAabbCache(
        hkp3AxisSweep *this,
        hkArrayBase<hkpCollidable *> *overlappingCollidables,
        char *AabbCacheOut)
{
  int m_size; // ebp
  int v4; // ebx
  hkLifoAllocator *Value; // rax
  hkp3AxisSweep::hkpBpNode **m_cur; // rdi
  int v10; // edx
  char *v11; // rcx
  __int64 v12; // r8
  __int64 v13; // rax
  signed int v14; // ebx
  hkLifoAllocator *v15; // rax
  int v16; // r8d
  hkArrayBase<hkp3AxisSweep::hkpBpNode const *> overlaps; // [rsp+20h] [rbp-38h] BYREF
  hkp3AxisSweep::hkpBpNode **v18; // [rsp+30h] [rbp-28h]
  int v19; // [rsp+38h] [rbp-20h]

  m_size = overlappingCollidables->m_size;
  v4 = 0;
  overlaps.m_size = 0;
  v19 = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkp3AxisSweep::hkpBpNode **)Value->m_cur;
    v10 = (8 * m_size + 127) & 0xFFFFFF80;
    v11 = (char *)m_cur + v10;
    if ( v10 > Value->m_slabSize || v11 > Value->m_end )
    {
      m_cur = (hkp3AxisSweep::hkpBpNode **)hkLifoAllocator::allocateFromNewSlab(Value, v10);
      overlaps.m_data = m_cur;
    }
    else
    {
      Value->m_cur = v11;
      overlaps.m_data = m_cur;
    }
  }
  else
  {
    m_cur = 0i64;
    overlaps.m_data = 0i64;
  }
  v18 = m_cur;
  overlaps.m_capacityAndFlags = m_size | 0x80000000;
  if ( overlappingCollidables->m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      ++v12;
      v13 = v4++;
      m_cur[v13] = &this->m_nodes.m_data[overlappingCollidables->m_data[v12 - 1]->m_broadPhaseHandle.m_id];
      overlaps.m_size = v4;
    }
    while ( v4 < overlappingCollidables->m_size );
  }
  hkp3AxisSweep::calcAabbCacheInternal(this, &overlaps, AabbCacheOut);
  v14 = (8 * m_size + 127) & 0xFFFFFF80;
  v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v16 = (v14 + 15) & 0xFFFFFFF0;
  if ( v14 > v15->m_slabSize || (char *)m_cur + v16 != v15->m_cur || v15->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v15, (char *)m_cur, v16);
  else
    v15->m_cur = m_cur;
}

// File Line: 3250
// RVA: 0xD03CF0
void __fastcall hkp3AxisSweep::calcAabbCacheInternal(
        hkp3AxisSweep *this,
        hkArrayBase<hkp3AxisSweep::hkpBpNode const *> *overlaps,
        char *AabbCacheOut)
{
  char *v4; // r9
  int v6; // r8d
  char *v7; // r14
  char *v8; // rbx
  _DWORD *v9; // rdx
  _DWORD *v10; // r8
  _DWORD *v11; // r8
  hkp3AxisSweep::hkpBpNode **m_data; // rdx
  int i; // r11d
  hkp3AxisSweep::hkpBpEndPoint *v14; // r8
  hkp3AxisSweep::hkpBpEndPoint *v15; // r8
  hkp3AxisSweep::hkpBpEndPoint *v16; // r8
  hkp3AxisSweep::hkpBpEndPoint *v17; // r8
  hkp3AxisSweep::hkpBpEndPoint *v18; // r8
  hkp3AxisSweep::hkpBpEndPoint *v19; // r8
  char *v20; // rsi
  __int64 v21; // rbp
  _DWORD *v22; // rdx
  _DWORD *v23; // r8
  _DWORD *v24; // r8

  v4 = AabbCacheOut + 48;
  v6 = 2 * overlaps->m_size + 2;
  if ( AabbCacheOut )
  {
    *(_QWORD *)AabbCacheOut = v4;
    *((_DWORD *)AabbCacheOut + 2) = 0;
    *((_DWORD *)AabbCacheOut + 3) = v6 | 0x80000000;
  }
  v7 = AabbCacheOut + 16;
  if ( AabbCacheOut != (char *)-16i64 )
  {
    *((_DWORD *)AabbCacheOut + 6) = 0;
    *(_QWORD *)v7 = &v4[4 * v6];
    *((_DWORD *)AabbCacheOut + 7) = v6 | 0x80000000;
  }
  v8 = AabbCacheOut + 32;
  if ( AabbCacheOut != (char *)-32i64 )
  {
    *((_DWORD *)AabbCacheOut + 10) = 0;
    *((_DWORD *)AabbCacheOut + 11) = v6 | 0x80000000;
    *(_QWORD *)v8 = &v4[8 * v6];
  }
  v9 = (_DWORD *)(*(_QWORD *)AabbCacheOut + 4i64 * *((int *)AabbCacheOut + 2));
  if ( v9 )
    *v9 = 0;
  ++*((_DWORD *)AabbCacheOut + 2);
  v10 = (_DWORD *)(*(_QWORD *)v7 + 4i64 * *((int *)AabbCacheOut + 6));
  if ( v10 )
    *v10 = 0;
  ++*((_DWORD *)AabbCacheOut + 6);
  v11 = (_DWORD *)(*(_QWORD *)v8 + 4i64 * *((int *)AabbCacheOut + 10));
  if ( v11 )
    *v11 = 0;
  ++*((_DWORD *)AabbCacheOut + 10);
  m_data = overlaps->m_data;
  for ( i = overlaps->m_size - 1; i >= 0; --i )
  {
    v14 = (hkp3AxisSweep::hkpBpEndPoint *)(*(_QWORD *)AabbCacheOut + 4i64 * *((int *)AabbCacheOut + 2));
    if ( v14 )
      *v14 = this->m_axis[0].m_endPoints.m_data[(*m_data)->min_x];
    v15 = (hkp3AxisSweep::hkpBpEndPoint *)(*(_QWORD *)AabbCacheOut + 4i64 * (int)++*((_DWORD *)AabbCacheOut + 2));
    if ( v15 )
      *v15 = this->m_axis[0].m_endPoints.m_data[(*m_data)->max_x];
    ++*((_DWORD *)AabbCacheOut + 2);
    v16 = (hkp3AxisSweep::hkpBpEndPoint *)(*((_QWORD *)AabbCacheOut + 2) + 4i64 * *((int *)AabbCacheOut + 6));
    if ( v16 )
      *v16 = this->m_axis[1].m_endPoints.m_data[(*m_data)->min_y];
    v17 = (hkp3AxisSweep::hkpBpEndPoint *)(*((_QWORD *)AabbCacheOut + 2) + 4i64 * (int)++*((_DWORD *)AabbCacheOut + 6));
    if ( v17 )
      *v17 = this->m_axis[1].m_endPoints.m_data[(*m_data)->max_y];
    ++*((_DWORD *)AabbCacheOut + 6);
    v18 = (hkp3AxisSweep::hkpBpEndPoint *)(*((_QWORD *)AabbCacheOut + 4) + 4i64 * *((int *)AabbCacheOut + 10));
    if ( v18 )
      *v18 = this->m_axis[2].m_endPoints.m_data[(*m_data)->min_z];
    v19 = (hkp3AxisSweep::hkpBpEndPoint *)(*((_QWORD *)AabbCacheOut + 4) + 4i64 * (int)++*((_DWORD *)AabbCacheOut + 10));
    if ( v19 )
      *v19 = this->m_axis[2].m_endPoints.m_data[(*m_data)->max_z];
    ++*((_DWORD *)AabbCacheOut + 10);
    ++m_data;
  }
  v20 = AabbCacheOut;
  v21 = 3i64;
  do
  {
    if ( *((_DWORD *)v20 + 2) - 1 > 1 )
      hkAlgorithm::quickSortRecursive<hkp3AxisSweep::hkpBpEndPoint,hkAlgorithm::less<hkp3AxisSweep::hkpBpEndPoint>>(
        (hkp3AxisSweep::hkpBpEndPoint *)(*(_QWORD *)v20 + 4i64),
        0,
        *((_DWORD *)v20 + 2) - 2,
        0);
    v20 += 16;
    --v21;
  }
  while ( v21 );
  v22 = (_DWORD *)(*(_QWORD *)AabbCacheOut + 4i64 * *((int *)AabbCacheOut + 2));
  if ( v22 )
    *v22 = 65532;
  ++*((_DWORD *)AabbCacheOut + 2);
  v23 = (_DWORD *)(*(_QWORD *)v7 + 4i64 * *((int *)AabbCacheOut + 6));
  if ( v23 )
    *v23 = 65532;
  ++*((_DWORD *)AabbCacheOut + 6);
  v24 = (_DWORD *)(*(_QWORD *)v8 + 4i64 * *((int *)AabbCacheOut + 10));
  if ( v24 )
    *v24 = 65532;
  ++*((_DWORD *)AabbCacheOut + 10);
}

// File Line: 3313
// RVA: 0xD00D50
void __fastcall hkp3AxisSweep::defragment(hkp3AxisSweep *this)
{
  int m_size; // esi
  int v3; // edx
  _QWORD *v4; // r13
  int v5; // r15d
  int v6; // eax
  ValueIntPair<unsigned short> *v7; // r12
  int v8; // ebp
  int v9; // eax
  _DWORD *v10; // rdi
  int v11; // r14d
  int i; // r9d
  hkp3AxisSweep::hkpBpNode *m_data; // rcx
  __int64 v14; // rdx
  unsigned __int64 v15; // r8
  int v16; // r8d
  __int64 v17; // r9
  unsigned __int16 *p_m_oldIndex; // r10
  __int64 v19; // rax
  hkp3AxisSweep::hkpBpNode *v20; // rcx
  int v21; // esi
  int j; // edx
  hkp3AxisSweep::hkpBpNode *v23; // rcx
  int v24; // r10d
  __int64 v25; // r11
  hkp3AxisSweep::hkpBpMarker *m_markers; // r9
  int v27; // eax
  __int64 k; // r8
  unsigned __int16 *v29; // rdx
  int *p_m_size; // r9
  __int64 v31; // r10
  int v32; // r8d
  unsigned __int16 *v33; // rax
  __int64 v34; // rcx
  int v35; // [rsp+60h] [rbp+8h] BYREF
  int v36; // [rsp+68h] [rbp+10h] BYREF
  int v37; // [rsp+70h] [rbp+18h] BYREF

  m_size = this->m_nodes.m_size;
  v3 = m_size;
  if ( m_size )
  {
    v35 = 24 * m_size;
    v4 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v35);
    v3 = v35 / 24;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = 0x80000000;
  if ( v3 )
    v5 = v3;
  v6 = m_size;
  if ( m_size )
  {
    v36 = 4 * m_size;
    v7 = (ValueIntPair<unsigned short> *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                           &hkContainerTempAllocator::s_alloc,
                                           &v36);
    v6 = v36 / 4;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = 0x80000000;
  if ( v6 )
    v8 = v6;
  v9 = m_size;
  if ( m_size )
  {
    v37 = 4 * m_size;
    v10 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v37);
    v9 = v37 / 4;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 0x80000000;
  if ( v9 )
    v11 = v9;
  for ( i = 0; i < this->m_nodes.m_size; v7[v14].m_value = (unsigned __int16)m_data )
  {
    m_data = this->m_nodes.m_data;
    v14 = i;
    v15 = 24i64 * i;
    v4[v15 / 8] = *(_QWORD *)&m_data[v15 / 0x18].min_y;
    v4[v15 / 8 + 1] = *(_QWORD *)&m_data[v15 / 0x18].min_x;
    v4[v15 / 8 + 2] = m_data[v15 / 0x18].m_handle;
    LOWORD(m_data) = this->m_nodes.m_data[v15 / 0x18].min_x;
    v7[i].m_oldIndex = i;
    ++i;
  }
  if ( m_size - 1 > 1 )
    hkAlgorithm::quickSortRecursive<ValueIntPair<unsigned short>,hkAlgorithm::less<ValueIntPair<unsigned short>>>(
      v7 + 1,
      0,
      m_size - 2,
      0);
  v16 = 0;
  if ( this->m_nodes.m_size > 0 )
  {
    v17 = 0i64;
    p_m_oldIndex = &v7->m_oldIndex;
    do
    {
      v19 = *p_m_oldIndex;
      p_m_oldIndex += 2;
      ++v17;
      v10[v19] = v16;
      v20 = this->m_nodes.m_data;
      ++v16;
      *(_QWORD *)&v20[v17 - 1].min_y = v4[3 * v19];
      *(_QWORD *)&v20[v17 - 1].min_x = v4[3 * v19 + 1];
      v20[v17 - 1].m_handle = (hkpBroadPhaseHandle *)v4[3 * v19 + 2];
    }
    while ( v16 < this->m_nodes.m_size );
  }
  v21 = 1;
  for ( j = 1; j < this->m_nodes.m_size; ++j )
  {
    v23 = &this->m_nodes.m_data[j];
    if ( ((__int64)v23->m_handle & 1) != 0 )
      *(unsigned __int16 *)((char *)&this->m_markers->m_nodeIndex
                          + ((unsigned __int64)v23->m_handle & 0xFFFFFFFFFFFFFFFEui64)) = j;
    else
      v23->m_handle->m_id = j;
  }
  v24 = 0;
  if ( this->m_numMarkers > 0 )
  {
    v25 = 0i64;
    do
    {
      m_markers = this->m_markers;
      v27 = m_markers[v25].m_overlappingObjects.m_size - 1;
      for ( k = v27; k >= 0; *v29 = v10[*v29] )
        v29 = &m_markers[v25].m_overlappingObjects.m_data[k--];
      ++v24;
      ++v25;
    }
    while ( v24 < this->m_numMarkers );
  }
  p_m_size = &this->m_axis[0].m_endPoints.m_size;
  v31 = 3i64;
  do
  {
    v32 = 0;
    if ( *p_m_size > 0 )
    {
      v33 = (unsigned __int16 *)(*((_QWORD *)p_m_size - 1) + 2i64);
      do
      {
        v34 = *v33;
        ++v32;
        v33 += 2;
        *(v33 - 2) = v10[v34];
      }
      while ( v32 < *p_m_size );
    }
    p_m_size += 4;
    --v31;
  }
  while ( v31 );
  if ( this->m_nodes.m_size > 1 )
  {
    do
      hkp3AxisSweep::_fixDeterministicOrderAfterNodeIdWasDecreased(this, v21++);
    while ( v21 < this->m_nodes.m_size );
  }
  if ( v11 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _DWORD *, _QWORD, int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v10,
      (unsigned int)(4 * v11),
      p_m_size);
  if ( v8 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, ValueIntPair<unsigned short> *, _QWORD, int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v7,
      (unsigned int)(4 * v8),
      p_m_size);
  if ( v5 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _QWORD *, _QWORD, int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v4,
      24 * (v5 & 0x3FFFFFFFu),
      p_m_size);
}

// File Line: 3598
// RVA: 0xD02040
void __fastcall hkp3AxisSweep::castRay(
        hkp3AxisSweep *this,
        hkpBroadPhase::hkpCastRayInput *rayInput,
        hkpBroadPhaseCastCollector *collectorBase,
        int collectorStriding)
{
  __m128 v4; // xmm0
  hkpBroadPhaseCastCollector *v5; // r15
  hkpBroadPhase::hkpCastRayInput *v6; // r13
  __m128 v8; // xmm0
  __m128i v9; // xmm1
  int v10; // eax
  int *v11; // rdi
  unsigned int v12; // ecx
  int v13; // edx
  int *i; // rcx
  int *v15; // rax
  hkp3AxisSweep::hkpBpAxis *m_aabbCacheInfo; // r11
  char v17; // dl
  __int64 *v18; // rbx
  unsigned int *v19; // rsi
  __int64 v20; // r14
  int m_size; // ecx
  hkp3AxisSweep::hkpBpEndPoint *m_data; // r9
  unsigned int v23; // r8d
  unsigned __int64 v24; // r10
  hkp3AxisSweep::hkpBpEndPoint *k; // rcx
  __int64 m_nodeIndex; // rax
  __int64 v27; // rax
  unsigned __int16 *j; // rcx
  __int64 v29; // rax
  __int64 v30; // rax
  int m_numCasts; // ebx
  hkLifoAllocator *Value; // rax
  __int64 m_cur; // r10
  int v34; // edx
  void *v35; // rcx
  int v36; // edx
  _DWORD *v37; // rcx
  __int64 v38; // rdx
  unsigned __int64 v39; // r12
  __int64 v40; // r9
  _QWORD *v41; // r13
  _QWORD *v42; // rdx
  int v43; // ecx
  _BYTE *v44; // r8
  _BYTE *v45; // r9
  int v46; // r14d
  hkpBroadPhaseCastCollector *v47; // rsi
  hkpBroadPhaseHandle **v48; // r15
  __int64 v49; // rbx
  __int64 v50; // r13
  float v51; // xmm0_4
  int v52; // r14d
  hkpBroadPhaseCastCollector *v53; // rsi
  char *v54; // rbx
  __int64 v55; // r13
  float v56; // xmm0_4
  int v57; // r14d
  hkpBroadPhaseCastCollector *v58; // rsi
  char *v59; // rbx
  __int64 v60; // r13
  float v61; // xmm0_4
  int v62; // r14d
  hkpBroadPhaseCastCollector *v63; // rsi
  char *v64; // rbx
  __int64 v65; // r15
  float v66; // xmm0_4
  int v67; // r14d
  int v68; // r12d
  float *v69; // rsi
  __m128 v70; // xmm3
  __m128 m_quad; // xmm5
  float v72; // xmm7_4
  int v73; // r8d
  __m128 *v74; // r11
  __int64 v75; // r9
  __m128 *v76; // r10
  __int64 v77; // rcx
  hkVector4f *m_toBase; // rax
  __m128i v79; // xmm8
  __m128 v80; // xmm1
  __m128 v81; // xmm4
  __m128 v82; // xmm0
  __m128 v83; // xmm5
  __m128 v84; // xmm0
  __m128i v85; // xmm6
  __m128 v86; // xmm5
  __m128 v87; // xmm2
  __m128 v88; // xmm0
  __int64 v89; // rdx
  int v90; // ebx
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __int64 v93; // rax
  __int64 v94; // rbx
  char v95; // r14
  unsigned __int16 *v96; // rsi
  __int64 v97; // rcx
  __int64 v98; // rdx
  __int64 v99; // rcx
  unsigned __int16 v100; // cx
  unsigned __int16 *v101; // rdx
  int *v102; // r8
  int *v103; // r9
  int v104; // ecx
  int v105; // edx
  hkLifoAllocator *v106; // rax
  int v107; // r8d
  _QWORD *v108; // [rsp+30h] [rbp-C0h]
  _QWORD *v109; // [rsp+38h] [rbp-B8h]
  int v110; // [rsp+38h] [rbp-B8h]
  char *p; // [rsp+40h] [rbp-B0h]
  _QWORD *v112; // [rsp+48h] [rbp-A8h]
  __m128i v113; // [rsp+50h] [rbp-A0h] BYREF
  int *v114; // [rsp+60h] [rbp-90h]
  __m128 v115; // [rsp+70h] [rbp-80h] BYREF
  int v116; // [rsp+80h] [rbp-70h]
  int v117; // [rsp+84h] [rbp-6Ch]
  unsigned __int16 *v118; // [rsp+88h] [rbp-68h]
  unsigned __int16 *v119; // [rsp+90h] [rbp-60h]
  unsigned __int16 *v120; // [rsp+98h] [rbp-58h]
  __int64 v121[8]; // [rsp+A0h] [rbp-50h] BYREF
  __int64 vars0; // [rsp+170h] [rbp+80h]
  hkpBroadPhase::hkpCastRayInput *retaddr; // [rsp+178h] [rbp+88h]
  hkp3AxisSweep *v124; // [rsp+180h] [rbp+90h] BYREF
  hkpBroadPhase::hkpCastRayInput *v125; // [rsp+188h] [rbp+98h]
  int v126; // [rsp+198h] [rbp+A8h]

  v126 = collectorStriding;
  v125 = rayInput;
  v124 = this;
  v4 = _mm_add_ps(rayInput->m_from.m_quad, this->m_offsetLow.m_quad);
  v115.m128_u64[0] = (unsigned __int64)collectorBase;
  v5 = collectorBase;
  v6 = rayInput;
  v8 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(v4, this->m_scale.m_quad), hkp3AxisSweep::MaxVal), (__m128)0i64);
  v9 = _mm_sub_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v8),
           _mm_cvttps_epi32(v8)),
         (__m128i)_xmm);
  v124 = (hkp3AxisSweep *)_mm_add_epi16(
                            _mm_packs_epi32(v9, v9),
                            (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v113.m128i_i32[0] = (unsigned __int16)v124;
  v113.m128i_i32[1] = WORD1(v124);
  v113.m128i_i32[2] = WORD2(v124);
  v113.m128i_i32[3] = HIWORD(v124);
  v10 = this->m_nodes.m_size + 16;
  if ( this->m_nodes.m_size == -16 )
  {
    v11 = 0i64;
  }
  else
  {
    LODWORD(v124) = this->m_nodes.m_size + 16;
    v11 = (int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v124);
    v10 = (int)v124;
  }
  v12 = 0x80000000;
  if ( v10 )
    v12 = v10;
  v13 = this->m_nodes.m_size >> 4;
  v114 = v11;
  v117 = v12;
  for ( i = v11; v13 >= 0; *(_OWORD *)v15 = 0i64 )
  {
    v15 = i;
    i += 4;
    --v13;
  }
  m_aabbCacheInfo = (hkp3AxisSweep::hkpBpAxis *)v6->m_aabbCacheInfo;
  if ( !m_aabbCacheInfo )
    m_aabbCacheInfo = this->m_axis;
  v17 = 17;
  v18 = v121;
  v19 = (unsigned int *)&v113;
  v20 = 3i64;
  do
  {
    m_size = m_aabbCacheInfo->m_endPoints.m_size;
    m_data = m_aabbCacheInfo->m_endPoints.m_data;
    v23 = *v19;
    if ( *v19 >= m_aabbCacheInfo->m_endPoints.m_data[(__int64)m_size >> 1].m_value )
    {
      for ( j = &m_data[m_size - 2].m_value; j >= &m_data[4].m_value; *((_BYTE *)v11 + j[3]) ^= v17 )
      {
        if ( *(j - 6) <= v23 )
          break;
        v29 = j[1];
        j -= 8;
        *((_BYTE *)v11 + v29) ^= v17;
        *((_BYTE *)v11 + j[7]) ^= v17;
        *((_BYTE *)v11 + j[5]) ^= v17;
      }
      for ( ; *j > v23; *((_BYTE *)v11 + v30) ^= v17 )
      {
        v30 = j[1];
        j -= 2;
      }
      k = (hkp3AxisSweep::hkpBpEndPoint *)(j + 2);
    }
    else
    {
      v24 = (unsigned __int64)&m_data[m_size - 4];
      for ( k = m_data + 1; (unsigned __int64)k < v24; *((_BYTE *)v11 + k[-1].m_nodeIndex) ^= v17 )
      {
        if ( k[3].m_value > v23 )
          break;
        m_nodeIndex = k->m_nodeIndex;
        k += 4;
        *((_BYTE *)v11 + m_nodeIndex) ^= v17;
        *((_BYTE *)v11 + k[-3].m_nodeIndex) ^= v17;
        *((_BYTE *)v11 + k[-2].m_nodeIndex) ^= v17;
      }
      for ( ; k->m_value <= v23; *((_BYTE *)v11 + v27) ^= v17 )
      {
        v27 = k->m_nodeIndex;
        ++k;
      }
    }
    *v18++ = (__int64)k;
    v17 *= 2;
    ++m_aabbCacheInfo;
    ++v19;
    --v20;
  }
  while ( v20 );
  m_numCasts = v6->m_numCasts;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v34 = (4 * m_numCasts + 127) & 0xFFFFFF80;
  v116 = v34;
  p = (char *)m_cur;
  v35 = (void *)(m_cur + v34);
  if ( v34 > Value->m_slabSize || v35 > Value->m_end )
  {
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v34);
    p = (char *)m_cur;
  }
  else
  {
    Value->m_cur = v35;
  }
  v36 = 0;
  if ( v6->m_numCasts > 0 )
  {
    v37 = (_DWORD *)m_cur;
    do
    {
      *v37 = 1065353216;
      ++v36;
      ++v37;
    }
    while ( v36 < v6->m_numCasts );
  }
  v38 = vars0;
  v39 = (unsigned __int64)v11;
  v40 = *(_QWORD *)(vars0 + 176);
  v113.m128i_i64[0] = (__int64)&v11[((__int64)*(int *)(vars0 + 184) >> 2) + 1];
  if ( (unsigned __int64)v11 < v113.m128i_i64[0] )
  {
    v41 = (_QWORD *)(v40 + 88);
    v42 = (_QWORD *)(v40 + 64);
    v43 = retaddr->m_numCasts;
    v44 = (_BYTE *)(v40 + 40);
    v45 = (_BYTE *)(v40 + 16);
    v108 = v41;
    v112 = v42;
    v115.m128_u64[0] = (unsigned __int64)v45;
    v109 = v44;
    while ( ((*(_DWORD *)v39 + 16843009) & 0x8080808) == 0 )
    {
      if ( ((*(_DWORD *)(v39 + 4) + 16843009) & 0x8080808) != 0 )
        goto LABEL_65;
      if ( ((*(_DWORD *)(v39 + 8) + 16843009) & 0x8080808) != 0 )
      {
        v45 += 192;
        v44 += 192;
        v42 += 24;
        v41 += 24;
        v39 += 8i64;
      }
      else
      {
        v45 += 288;
        v44 += 288;
        v42 += 36;
        v41 += 36;
        v39 += 12i64;
      }
LABEL_66:
      v108 = v41;
      v112 = v42;
      v109 = v44;
      v115.m128_u64[0] = (unsigned __int64)v45;
      if ( v39 >= v113.m128i_i64[0] )
      {
        v11 = v114;
        v6 = retaddr;
        v38 = vars0;
        goto LABEL_68;
      }
      m_cur = (__int64)p;
    }
    if ( *(_BYTE *)v39 == 119 && (*v45 & 1) == 0 )
    {
      v46 = 0;
      v47 = v5;
      if ( v43 > 0 )
      {
        v48 = (hkpBroadPhaseHandle **)v115.m128_u64[0];
        v49 = m_cur;
        v50 = (int)v125;
        do
        {
          v51 = v47->vfptr->addBroadPhaseHandle(v47, *v48, v46++);
          v47 = (hkpBroadPhaseCastCollector *)((char *)v47 + v50);
          v49 += 4i64;
          *(float *)(v49 - 4) = fminf(*(float *)(v49 - 4), v51);
          v43 = retaddr->m_numCasts;
        }
        while ( v46 < v43 );
        v5 = (hkpBroadPhaseCastCollector *)v115.m128_u64[0];
        v41 = v108;
        v44 = v109;
      }
    }
    if ( *(_BYTE *)(v39 + 1) == 119 && (*v44 & 1) == 0 )
    {
      v43 = retaddr->m_numCasts;
      v52 = 0;
      v53 = v5;
      if ( v43 > 0 )
      {
        v54 = p;
        v55 = (int)v125;
        do
        {
          v56 = v53->vfptr->addBroadPhaseHandle(v53, (hkpBroadPhaseHandle *)*v109, v52++);
          v53 = (hkpBroadPhaseCastCollector *)((char *)v53 + v55);
          v54 += 4;
          *((float *)v54 - 1) = fminf(*((float *)v54 - 1), v56);
          v43 = retaddr->m_numCasts;
        }
        while ( v52 < v43 );
        v5 = (hkpBroadPhaseCastCollector *)v115.m128_u64[0];
        v41 = v108;
      }
    }
    if ( *(_BYTE *)(v39 + 2) == 119 && (*(_BYTE *)v112 & 1) == 0 )
    {
      v43 = retaddr->m_numCasts;
      v57 = 0;
      v58 = v5;
      if ( v43 > 0 )
      {
        v59 = p;
        v60 = (int)v125;
        do
        {
          v61 = v58->vfptr->addBroadPhaseHandle(v58, (hkpBroadPhaseHandle *)*v112, v57++);
          v58 = (hkpBroadPhaseCastCollector *)((char *)v58 + v60);
          v59 += 4;
          *((float *)v59 - 1) = fminf(*((float *)v59 - 1), v61);
          v43 = retaddr->m_numCasts;
        }
        while ( v57 < v43 );
        v5 = (hkpBroadPhaseCastCollector *)v115.m128_u64[0];
        v41 = v108;
      }
    }
    if ( *(_BYTE *)(v39 + 3) == 119 && (*(_BYTE *)v41 & 1) == 0 )
    {
      v43 = retaddr->m_numCasts;
      v62 = 0;
      v63 = v5;
      if ( v43 > 0 )
      {
        v64 = p;
        v65 = (int)v125;
        do
        {
          v66 = v63->vfptr->addBroadPhaseHandle(v63, (hkpBroadPhaseHandle *)*v41, v62++);
          v63 = (hkpBroadPhaseCastCollector *)((char *)v63 + v65);
          v64 += 4;
          *((float *)v64 - 1) = fminf(*((float *)v64 - 1), v66);
          v43 = retaddr->m_numCasts;
        }
        while ( v62 < v43 );
        v5 = (hkpBroadPhaseCastCollector *)v115.m128_u64[0];
      }
    }
    v45 = (_BYTE *)v115.m128_u64[0];
    v44 = v109;
    v42 = v112;
LABEL_65:
    v45 += 96;
    v44 += 96;
    v42 += 12;
    v41 += 12;
    v39 += 4i64;
    goto LABEL_66;
  }
LABEL_68:
  *(_BYTE *)v11 = -120;
  v67 = *(_DWORD *)(v38 + 184);
  v68 = 0;
  v110 = v67;
  if ( v6->m_numCasts > 0 )
  {
    v69 = (float *)p;
    v114 = (int *)p;
    while ( 1 )
    {
      v70 = *(__m128 *)(v38 + 112);
      m_quad = v6->m_from.m_quad;
      v72 = *v69;
      v118 = (unsigned __int16 *)v121[0];
      v119 = (unsigned __int16 *)v121[1];
      v73 = 0;
      v120 = (unsigned __int16 *)v121[2];
      v74 = (__m128 *)`hkVector4f::getComponent::`2::indexToMask;
      LODWORD(v75) = 1;
      v76 = &v115;
      v77 = v6->m_toStriding * v68;
      m_toBase = v6->m_toBase;
      v79 = (__m128i)_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&m_toBase->m_quad + v77), m_quad), v70);
      v80 = _mm_rcp_ps((__m128)v79);
      v81 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v79, 1u), 1u);
      v82 = *(__m128 *)(v38 + 80);
      v83 = _mm_add_ps(m_quad, v82);
      v84 = _mm_add_ps(v82, *(__m128 *)((char *)&m_toBase->m_quad + v77));
      v85 = (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v79, v80)), v80);
      v86 = _mm_mul_ps(v83, v70);
      v113 = v85;
      v87 = _mm_cmplt_ps(
              v81,
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_mul_ps(v84, v70), *(__m128 *)&epsilon), 1u),
                        1u));
      v88 = (__m128)*(unsigned int *)(v38 + 256);
      v89 = 0i64;
      v90 = _mm_movemask_ps(
              _mm_or_ps(
                v87,
                _mm_cmplt_ps(
                  v81,
                  (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_mul_ps(v86, *(__m128 *)&epsilon), 1u), 1u))));
      v115 = _mm_mul_ps(_mm_sub_ps(v86, _mm_shuffle_ps(v88, v88, 0)), (__m128)v85);
      do
      {
        if ( ((unsigned int)v75 & v90) != 0 )
        {
          if ( v73 == 1 )
          {
            v76->m128_i32[0] = -1073741824;
            v85 = (__m128i)_mm_shuffle_ps(_mm_unpacklo_ps((__m128)v85, (__m128)0i64), (__m128)v85, 228);
            v113 = v85;
          }
          else
          {
            v76->m128_i32[0] = -1073741824;
            if ( v73 == 2 )
              v85 = (__m128i)_mm_shuffle_ps((__m128)v85, _mm_unpackhi_ps((__m128)v85, (__m128)0i64), 180);
            else
              v85 = _mm_slli_si128(_mm_srli_si128(v85, 4), 4);
            v113 = v85;
          }
        }
        else
        {
          v121[v89 + 3] = 4i64;
          v91 = _mm_and_ps((__m128)v79, *v74);
          v92 = _mm_or_ps(_mm_shuffle_ps(v91, v91, 78), v91);
          if ( COERCE_FLOAT(_mm_shuffle_ps(v92, v92, 177).m128_u32[0] | v92.m128_i32[0]) < 0.0 )
          {
            (&v118)[v89] -= 2;
            v121[v89 + 3] = -4i64;
          }
        }
        v75 = (unsigned int)__ROL4__(v75, 1);
        ++v73;
        v76 = (__m128 *)((char *)v76 + 4);
        ++v74;
        ++v89;
      }
      while ( v73 < 3 );
      v115 = _mm_sub_ps(
               _mm_mul_ps(
                 _mm_unpacklo_ps(
                   _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)*v118), (__m128)COERCE_UNSIGNED_INT((float)*v120)),
                   _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)*v119), (__m128)0i64)),
                 (__m128)v85),
               v115);
      v93 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                    _mm_and_ps(
                                                                      _mm_cmple_ps(
                                                                        v115,
                                                                        _mm_min_ps(
                                                                          _mm_shuffle_ps(v115, v115, 170),
                                                                          _mm_min_ps(
                                                                            _mm_shuffle_ps(v115, v115, 85),
                                                                            _mm_shuffle_ps(v115, v115, 0)))),
                                                                      (__m128)xmmword_141A81740))];
      v94 = (unsigned int)v93;
      if ( v72 >= v115.m128_f32[v93] )
        break;
LABEL_91:
      if ( v68 < v6->m_numCasts - 1 )
      {
        v102 = v11;
        v103 = &v11[((__int64)v67 >> 2) + 1];
        if ( v11 < v103 )
        {
          do
          {
            v104 = *v102;
            v105 = v102[1];
            v102 += 2;
            *(v102 - 2) = v104 & 0xF0F0F0F | (16 * (v104 & 0xF0F0F0F));
            *(v102 - 1) = v105 & 0xF0F0F0F | (16 * (v105 & 0xF0F0F0F));
          }
          while ( v102 < v103 );
        }
      }
      v38 = vars0;
      ++v69;
      ++v68;
      v5 = (hkpBroadPhaseCastCollector *)((char *)v5 + (int)v125);
      v114 = (int *)v69;
      if ( v68 >= v6->m_numCasts )
        goto LABEL_95;
    }
LABEL_82:
    v95 = 1 << (v93 + 4);
    while ( 1 )
    {
      v96 = (&v118)[v94];
      v97 = v96[1];
      *((_BYTE *)v11 + v97) ^= v95;
      if ( *((_BYTE *)v11 + v97) >= 0x70u )
      {
        if ( !(_DWORD)v97 )
        {
          v115.m128_i32[v94] = 0x40000000;
LABEL_89:
          v93 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                        _mm_and_ps(
                                                                          _mm_cmple_ps(
                                                                            v115,
                                                                            _mm_min_ps(
                                                                              _mm_shuffle_ps(v115, v115, 170),
                                                                              _mm_min_ps(
                                                                                _mm_shuffle_ps(v115, v115, 85),
                                                                                _mm_shuffle_ps(v115, v115, 0)))),
                                                                          (__m128)xmmword_141A81740))];
          v94 = (unsigned int)v93;
          if ( v72 < v115.m128_f32[v93] )
          {
            v6 = retaddr;
            v69 = (float *)v114;
            v67 = v110;
            goto LABEL_91;
          }
          goto LABEL_82;
        }
        v98 = 3 * v97;
        v99 = *(_QWORD *)(vars0 + 176);
        if ( (*(_BYTE *)(v99 + 8 * v98 + 16) & 1) == 0 )
          v72 = fminf(
                  v72,
                  ((float (__fastcall *)(hkpBroadPhaseCastCollector *, _QWORD, _QWORD, __int64))v5->vfptr->addBroadPhaseHandle)(
                    v5,
                    *(_QWORD *)(v99 + 8 * v98 + 16),
                    (unsigned int)v68,
                    v75));
      }
      v100 = *v96;
      v101 = (unsigned __int16 *)((char *)v96 + v121[v94 + 3]);
      (&v118)[v94] = v101;
      if ( v100 != *v101 )
      {
        v115.m128_f32[v94] = (float)((float)*v101 * *(float *)&v113.m128i_i32[v94]) - v115.m128_f32[v94];
        goto LABEL_89;
      }
    }
  }
LABEL_95:
  v106 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v107 = (v116 + 15) & 0xFFFFFFF0;
  if ( v116 > v106->m_slabSize || &p[v107] != v106->m_cur || v106->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v106, p, v107);
  else
    v106->m_cur = p;
  if ( v117 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v11, v117 & 0x3FFFFFFF);
}

// File Line: 4016
// RVA: 0xD02B40
void __fastcall hkp3AxisSweep::castAabb(
        hkp3AxisSweep *this,
        hkpBroadPhase::hkpCastAabbInput *input,
        hkpBroadPhaseCastCollector *collector)
{
  __m128 v6; // xmm13
  __m128 v7; // xmm14
  __m128 v8; // xmm0
  __m128i v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  __m128i v12; // xmm7
  int v13; // eax
  _BYTE *v14; // rbx
  unsigned int v15; // ecx
  int v16; // edx
  _OWORD *i; // rcx
  _OWORD *v18; // rax
  _DWORD *m_aabbCacheInfo; // rsi
  __int64 v20; // rdi
  __int64 v21; // r11
  char v22; // r8
  __int64 v23; // r15
  int v24; // ecx
  __int64 v25; // rdx
  unsigned int v26; // r9d
  unsigned __int64 v27; // r10
  unsigned __int16 *k; // rdx
  __int64 v29; // rax
  __int64 v30; // rax
  unsigned int v31; // r9d
  unsigned int v32; // eax
  char v33; // al
  __int64 v34; // rcx
  unsigned __int64 v35; // r10
  unsigned __int16 *v36; // rdx
  unsigned int v37; // ecx
  __int64 v38; // rax
  unsigned int j; // ecx
  __int64 v40; // rax
  char v41; // al
  __int64 v42; // rcx
  float v43; // xmm11_4
  _BYTE *v44; // rsi
  _BYTE *v45; // r15
  hkpBroadPhaseHandle **p_m_handle; // rdi
  float v47; // xmm0_4
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm0_4
  hkVector4f v51; // xmm9
  hkVector4f v52; // xmm4
  int v53; // r11d
  __int64 v54; // r9
  __int64 v55; // r8
  int v56; // r10d
  __m128 v57; // xmm7
  hkVector4f v58; // xmm2
  __m128 v59; // xmm6
  __m128i v60; // xmm2
  __m128 v61; // xmm1
  __m128 v62; // xmm8
  __m128 v63; // xmm5
  int v64; // edi
  __m128i v65; // xmm10
  __m128 v66; // xmm0
  int v67; // esi
  int v68; // ecx
  unsigned __int16 *v69; // rdx
  __int64 v70; // rax
  unsigned __int16 *v71; // r9
  unsigned __int16 *v72; // r10
  int v73; // eax
  __m128 v74; // xmm4
  int v75; // eax
  __m128 v76; // xmm4
  __m128 v77; // xmm5
  __m128i v78; // xmm2
  int v79; // eax
  int v80; // r15d
  int v81; // eax
  int v82; // r12d
  float v83; // xmm0_4
  float v84; // xmm1_4
  int v85; // r13d
  unsigned __int16 *v86; // rdi
  __int64 v87; // rdx
  int v88; // eax
  __int64 v89; // rdx
  __int64 v90; // rcx
  float v91; // xmm0_4
  unsigned __int16 v92; // cx
  unsigned __int16 *v93; // rdx
  unsigned __int8 v94; // r10
  __int64 v95; // r8
  __int64 v96; // rdx
  __int16 v97; // cx
  _WORD *v98; // rdx
  unsigned __int64 v99; // [rsp+30h] [rbp-98h]
  int v100; // [rsp+30h] [rbp-98h]
  __m256i v101; // [rsp+40h] [rbp-88h]
  unsigned __int16 *v102; // [rsp+60h] [rbp-68h]
  unsigned __int16 *v103; // [rsp+68h] [rbp-60h]
  __int64 v104[3]; // [rsp+70h] [rbp-58h]
  __m128 v105; // [rsp+88h] [rbp-40h]
  __m128 v106[2]; // [rsp+98h] [rbp-30h]
  __int64 v107[2]; // [rsp+B8h] [rbp-10h]
  unsigned __int16 *v108; // [rsp+C8h] [rbp+0h]
  __int64 v109[30]; // [rsp+D0h] [rbp+8h]
  int v110[4]; // [rsp+1C0h] [rbp+F8h] BYREF
  float v111; // [rsp+1D0h] [rbp+108h]

  v6 = _mm_add_ps(input->m_from.m_quad, input->m_halfExtents.m_quad);
  v7 = _mm_sub_ps(input->m_from.m_quad, input->m_halfExtents.m_quad);
  v8 = _mm_max_ps(
         _mm_min_ps(_mm_mul_ps(_mm_add_ps(v7, this->m_offsetLow.m_quad), this->m_scale.m_quad), hkp3AxisSweep::MaxVal),
         (__m128)0i64);
  v9 = _mm_sub_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v8),
           _mm_cvttps_epi32(v8)),
         (__m128i)_xmm);
  v9.m128i_i64[0] = _mm_add_epi16(
                      _mm_packs_epi32(v9, v9),
                      (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v10 = _mm_min_ps(_mm_mul_ps(_mm_add_ps(v6, this->m_offsetLow.m_quad), this->m_scale.m_quad), hkp3AxisSweep::MaxVal);
  v101.m256i_i32[4] = v9.m128i_u16[0];
  v101.m256i_i32[5] = v9.m128i_u16[1];
  v11 = _mm_max_ps(v10, (__m128)0i64);
  v101.m256i_i32[6] = v9.m128i_u16[2];
  v101.m256i_i32[7] = v9.m128i_u16[3];
  v12 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v11),
            _mm_cvttps_epi32(v11)),
          (__m128i)_xmm);
  v99 = _mm_add_epi16(_mm_packs_epi32(v12, v12), (__m128i)`hkIntVector::setConvertSaturateS32ToU16::`2::offset2).m128i_u64[0];
  v101.m256i_i32[0] = (unsigned __int16)v99;
  v101.m256i_i32[1] = WORD1(v99);
  v101.m256i_i32[2] = WORD2(v99);
  v101.m256i_i32[3] = HIWORD(v99);
  v13 = this->m_nodes.m_size + 16;
  if ( this->m_nodes.m_size == -16 )
  {
    v14 = 0i64;
  }
  else
  {
    v110[0] = this->m_nodes.m_size + 16;
    v14 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, v110);
    v13 = v110[0];
  }
  v15 = 0x80000000;
  if ( v13 )
    v15 = v13;
  v16 = this->m_nodes.m_size >> 4;
  v100 = v15;
  for ( i = v14; v16 >= 0; *v18 = 0i64 )
  {
    v18 = i++;
    --v16;
  }
  m_aabbCacheInfo = input->m_aabbCacheInfo;
  if ( !m_aabbCacheInfo )
    m_aabbCacheInfo = this->m_axis;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 1;
  v23 = 3i64;
  do
  {
    v24 = m_aabbCacheInfo[2];
    v25 = *(_QWORD *)m_aabbCacheInfo;
    v26 = v101.m256i_u32[v20 + 4];
    if ( v26 >= *(unsigned __int16 *)(*(_QWORD *)m_aabbCacheInfo + 4 * ((__int64)v24 >> 1)) )
    {
      v35 = v25 + 16;
      v36 = (unsigned __int16 *)(v25 + 4i64 * (v24 - 2));
      if ( (unsigned __int64)v36 >= v35 )
      {
        v37 = v101.m256i_u32[v20];
        do
        {
          if ( *(v36 - 6) <= v37 )
            break;
          v38 = v36[1];
          v36 -= 8;
          v14[v38] ^= v22;
          v14[v36[7]] ^= v22;
          v14[v36[5]] ^= v22;
          v14[v36[3]] ^= v22;
        }
        while ( (unsigned __int64)v36 >= v35 );
      }
      for ( j = v101.m256i_u32[v20]; *v36 > j; v14[v40] ^= v22 )
      {
        v40 = v36[1];
        v36 -= 2;
      }
      for ( v101.m256i_i64[v21 + 3] = (__int64)(v36 + 2); *v36 > v26; v14[v42] ^= v22 & (unsigned __int8)-(v41 & 1) )
      {
        v41 = *(_BYTE *)v36;
        v42 = v36[1];
        v36 -= 2;
      }
      (&v102)[v21] = v36 + 2;
    }
    else
    {
      v27 = v25 + 4i64 * (v24 - 4);
      for ( k = (unsigned __int16 *)(v25 + 4); (unsigned __int64)k < v27; v14[*(k - 1)] ^= v22 )
      {
        if ( k[6] > v26 )
          break;
        v29 = k[1];
        k += 8;
        v14[v29] ^= v22;
        v14[*(k - 5)] ^= v22;
        v14[*(k - 3)] ^= v22;
      }
      for ( ; *k <= v26; v14[v30] ^= v22 )
      {
        v30 = k[1];
        k += 2;
      }
      v31 = v101.m256i_u32[v20];
      v32 = *k;
      (&v102)[v21] = k;
      if ( v32 <= v31 )
      {
        do
        {
          v33 = *(_BYTE *)k;
          v34 = k[1];
          k += 2;
          v14[v34] ^= v22 & (unsigned __int8)((v33 & 1) - 1);
        }
        while ( *k <= v31 );
      }
      v101.m256i_i64[v21 + 3] = (__int64)k;
    }
    v22 *= 2;
    m_aabbCacheInfo += 4;
    ++v20;
    ++v21;
    --v23;
  }
  while ( v23 );
  v43 = *(float *)&FLOAT_1_0;
  v44 = v14;
  v45 = &v14[4 * ((__int64)this->m_nodes.m_size >> 2) + 4];
  if ( v14 < v45 )
  {
    p_m_handle = &this->m_nodes.m_data[1].m_handle;
    do
    {
      if ( ((*(_DWORD *)v44 + 16843009) & 0x8080808) != 0 )
      {
        if ( *v44 == 7 && (*(_BYTE *)(p_m_handle - 3) & 1) == 0 )
        {
          v47 = collector->vfptr->addBroadPhaseHandle(collector, *(p_m_handle - 3), 0);
          v111 = v43;
          v43 = fminf(v43, v47);
        }
        if ( v44[1] == 7 && (*(_BYTE *)p_m_handle & 1) == 0 )
        {
          v48 = collector->vfptr->addBroadPhaseHandle(collector, *p_m_handle, 0);
          v111 = v43;
          v43 = fminf(v43, v48);
        }
        if ( v44[2] == 7 && ((_BYTE)p_m_handle[3] & 1) == 0 )
        {
          v49 = collector->vfptr->addBroadPhaseHandle(collector, p_m_handle[3], 0);
          v111 = v43;
          v43 = fminf(v43, v49);
        }
        if ( v44[3] == 7 && ((_BYTE)p_m_handle[6] & 1) == 0 )
        {
          v50 = collector->vfptr->addBroadPhaseHandle(collector, p_m_handle[6], 0);
          v111 = v43;
          v43 = fminf(v43, v50);
        }
      }
      v44 += 4;
      p_m_handle += 12;
    }
    while ( v44 < v45 );
  }
  v51.m_quad = (__m128)this->m_scale;
  v52.m_quad = (__m128)this->m_offsetLow;
  v53 = 0;
  v54 = 0i64;
  v55 = 0i64;
  v56 = 1;
  v57 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_intToFloatFloorCorrection),
          (__m128)LODWORD(this->m_intToFloatFloorCorrection),
          0);
  v58.m_quad = (__m128)input->m_to;
  v59 = _mm_mul_ps(_mm_mul_ps(_mm_add_ps(v58.m_quad, v52.m_quad), v51.m_quad), *(__m128 *)&epsilon);
  v60 = (__m128i)_mm_mul_ps(_mm_sub_ps(v58.m_quad, input->m_from.m_quad), v51.m_quad);
  v61 = _mm_rcp_ps((__m128)v60);
  v62 = _mm_cmplt_ps((__m128)0i64, (__m128)v60);
  v63 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v60, 1u), 1u);
  v64 = _mm_movemask_ps(v62);
  v65 = (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v61, (__m128)v60)), v61);
  *(__m128i *)&v101.m256i_u64[1] = v65;
  v66 = _mm_mul_ps(_mm_add_ps(v52.m_quad, _mm_or_ps(_mm_andnot_ps(v62, v6), _mm_and_ps(v7, v62))), v51.m_quad);
  v106[0] = _mm_mul_ps(_mm_sub_ps(v66, v57), (__m128)v65);
  v67 = _mm_movemask_ps(_mm_or_ps(_mm_cmplt_ps(v63, v59), _mm_cmplt_ps(v63, _mm_mul_ps(v66, *(__m128 *)&epsilon))));
  v105 = _mm_mul_ps(
           _mm_sub_ps(
             _mm_mul_ps(_mm_add_ps(_mm_or_ps(_mm_andnot_ps(v62, v7), _mm_and_ps(v6, v62)), v52.m_quad), v51.m_quad),
             v57),
           (__m128)v65);
  do
  {
    if ( (v64 & v56) != 0 )
    {
      v109[v54] = 4i64;
      *(_DWORD *)((char *)v104 + v55 * 4) = 0;
      v106[1].m128_i32[v55] = 1;
    }
    else
    {
      v68 = v101.m256i_i32[v55 + 4];
      v69 = (&v102)[v54];
      v101.m256i_i32[v55 + 4] = v101.m256i_i32[v55];
      v70 = v101.m256i_i64[v54 + 3];
      v109[v54] = -4i64;
      v101.m256i_i32[v55] = v68;
      *(_DWORD *)((char *)v104 + v55 * 4) = 1;
      (&v102)[v54] = (unsigned __int16 *)(v70 - 4);
      v106[1].m128_i32[v55] = 0;
      v101.m256i_i64[v54 + 3] = (__int64)(v69 - 2);
    }
    if ( (v67 & v56) != 0 )
    {
      if ( v53 == 1 )
      {
        v65 = (__m128i)_mm_shuffle_ps(_mm_unpacklo_ps((__m128)v65, (__m128)0i64), (__m128)v65, 228);
      }
      else if ( v53 == 2 )
      {
        v65 = (__m128i)_mm_shuffle_ps((__m128)v65, _mm_unpackhi_ps((__m128)v65, (__m128)0i64), 180);
      }
      else
      {
        v65 = _mm_slli_si128(_mm_srli_si128(v65, 4), 4);
      }
      *(__m128i *)&v101.m256i_u64[1] = v65;
      v106[0].m128_i32[v55] = -1073741824;
      v105.m128_i32[v55] = -1073741824;
    }
    v56 = __ROL4__(v56, 1);
    ++v53;
    ++v54;
    ++v55;
  }
  while ( v53 < 3 );
  v71 = v102;
  v72 = v103;
  v107[0] = (__int64)v102;
  v73 = *v102;
  v107[1] = (__int64)v103;
  v108 = (unsigned __int16 *)v104[0];
  v102 = (unsigned __int16 *)v101.m256i_i64[3];
  v74 = (__m128)COERCE_UNSIGNED_INT((float)v73);
  v75 = *v103;
  v103 = v71;
  v104[0] = (__int64)v72;
  v76 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(v74, (__m128)COERCE_UNSIGNED_INT((float)*v108)),
          _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v75), (__m128)0i64));
  v77 = (__m128)COERCE_UNSIGNED_INT((float)*(unsigned __int16 *)v101.m256i_i64[3]);
  v78 = _mm_cvtsi32_si128(*v71);
  v79 = *v72;
  *v14 = 8;
  *(__m128 *)v101.m256i_i8 = _mm_sub_ps(_mm_mul_ps(v76, (__m128)v65), v106[0]);
  *(__m128 *)&v101.m256i_u64[2] = _mm_sub_ps(
                                    _mm_mul_ps(
                                      _mm_unpacklo_ps(
                                        _mm_unpacklo_ps(v77, (__m128)COERCE_UNSIGNED_INT((float)v79)),
                                        _mm_unpacklo_ps(_mm_cvtepi32_ps(v78), (__m128)0i64)),
                                      (__m128)v65),
                                    v105);
  v80 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                _mm_and_ps(
                                                                  _mm_cmple_ps(
                                                                    *(__m128 *)v101.m256i_i8,
                                                                    _mm_min_ps(
                                                                      _mm_shuffle_ps(
                                                                        *(__m128 *)v101.m256i_i8,
                                                                        *(__m128 *)v101.m256i_i8,
                                                                        170),
                                                                      _mm_min_ps(
                                                                        _mm_shuffle_ps(
                                                                          *(__m128 *)v101.m256i_i8,
                                                                          *(__m128 *)v101.m256i_i8,
                                                                          85),
                                                                        _mm_shuffle_ps(
                                                                          *(__m128 *)v101.m256i_i8,
                                                                          *(__m128 *)v101.m256i_i8,
                                                                          0)))),
                                                                  (__m128)xmmword_141A81740))];
  v81 = _mm_movemask_ps(
          _mm_and_ps(
            _mm_cmple_ps(
              *(__m128 *)&v101.m256i_u64[2],
              _mm_min_ps(
                _mm_shuffle_ps(*(__m128 *)&v101.m256i_u64[2], *(__m128 *)&v101.m256i_u64[2], 170),
                _mm_min_ps(
                  _mm_shuffle_ps(*(__m128 *)&v101.m256i_u64[2], *(__m128 *)&v101.m256i_u64[2], 85),
                  _mm_shuffle_ps(*(__m128 *)&v101.m256i_u64[2], *(__m128 *)&v101.m256i_u64[2], 0)))),
            (__m128)xmmword_141A81740));
LABEL_59:
  v82 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v81];
  while ( 1 )
  {
    v83 = *(float *)&v101.m256i_i32[v82 + 4];
    v84 = *(float *)&v101.m256i_i32[v80];
    if ( v83 < v84 )
      break;
    if ( v84 > v43 )
      goto LABEL_79;
    v94 = *((_BYTE *)v104 + 4 * v80);
    while ( 1 )
    {
      v95 = v107[v80];
      v96 = *(unsigned __int16 *)(v95 + 2);
      v14[v96] ^= (v94 ^ *(_BYTE *)v95 & 1) << v80;
      if ( v14[v96] > 8u )
        break;
      v97 = *(_WORD *)v95;
      v98 = (_WORD *)(v95 + v109[v80]);
      v107[v80] = (__int64)v98;
      if ( v97 != *v98 )
      {
        *(float *)&v101.m256i_i32[v80] = (float)((float)(unsigned __int16)*v98 * *(float *)&v101.m256i_i32[v80 + 2])
                                       - v106[0].m128_f32[v80];
        goto LABEL_77;
      }
    }
    v101.m256i_i32[v80] = 0x40000000;
LABEL_77:
    v80 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                  _mm_and_ps(
                                                                    _mm_cmple_ps(
                                                                      *(__m128 *)v101.m256i_i8,
                                                                      _mm_min_ps(
                                                                        _mm_shuffle_ps(
                                                                          *(__m128 *)v101.m256i_i8,
                                                                          *(__m128 *)v101.m256i_i8,
                                                                          170),
                                                                        _mm_min_ps(
                                                                          _mm_shuffle_ps(
                                                                            *(__m128 *)v101.m256i_i8,
                                                                            *(__m128 *)v101.m256i_i8,
                                                                            85),
                                                                          _mm_shuffle_ps(
                                                                            *(__m128 *)v101.m256i_i8,
                                                                            *(__m128 *)v101.m256i_i8,
                                                                            0)))),
                                                                    (__m128)xmmword_141A81740))];
  }
  if ( v83 <= v43 )
  {
    v85 = v106[1].m128_i32[v82];
    while ( 1 )
    {
      v86 = (&v102)[v82];
      v87 = v86[1];
      v88 = (v85 ^ *v86 & 1) << v82;
      v14[v87] ^= v88;
      if ( v14[v87] >= 7u )
      {
        if ( !(_DWORD)v87 )
        {
          v101.m256i_i32[v82 + 4] = 0x40000000;
LABEL_70:
          v81 = _mm_movemask_ps(
                  _mm_and_ps(
                    _mm_cmple_ps(
                      *(__m128 *)&v101.m256i_u64[2],
                      _mm_min_ps(
                        _mm_shuffle_ps(*(__m128 *)&v101.m256i_u64[2], *(__m128 *)&v101.m256i_u64[2], 170),
                        _mm_min_ps(
                          _mm_shuffle_ps(*(__m128 *)&v101.m256i_u64[2], *(__m128 *)&v101.m256i_u64[2], 85),
                          _mm_shuffle_ps(*(__m128 *)&v101.m256i_u64[2], *(__m128 *)&v101.m256i_u64[2], 0)))),
                    (__m128)xmmword_141A81740));
          goto LABEL_59;
        }
        v89 = 3 * v87;
        v90 = *(_QWORD *)(v109[29] + 176);
        if ( v88 )
        {
          if ( (*(_BYTE *)(v90 + 8 * v89 + 16) & 1) == 0 )
          {
            v91 = collector->vfptr->addBroadPhaseHandle(collector, *(hkpBroadPhaseHandle **)(v90 + 8 * v89 + 16), 0);
            v111 = v43;
            v43 = fminf(v43, v91);
          }
        }
      }
      v92 = *v86;
      v93 = (unsigned __int16 *)((char *)v86 + v109[v82]);
      (&v102)[v82] = v93;
      if ( v92 != *v93 )
      {
        *(float *)&v101.m256i_i32[v82 + 4] = (float)((float)*v93 * *(float *)&v101.m256i_i32[v82 + 2])
                                           - v105.m128_f32[v82];
        goto LABEL_70;
      }
    }
  }
LABEL_79:
  if ( v100 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v14, v100 & 0x3FFFFFFF);
}

// File Line: 4519
// RVA: 0xD06AC0
void __fastcall hkp3AxisSweep::getAabbFromNode(hkp3AxisSweep *this, hkp3AxisSweep::hkpBpNode *node, hkAabb *aabb)
{
  hkVector4f v3; // xmm0
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  hkVector4f v6; // xmm3

  v3.m_quad = (__m128)this->m_scale;
  v4 = _mm_rcp_ps(v3.m_quad);
  v5 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3.m_quad, v4)), v4);
  v6.m_quad = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_unpacklo_ps(
                    _mm_unpacklo_ps(
                      (__m128)COERCE_UNSIGNED_INT((float)this->m_axis[0].m_endPoints.m_data[node->max_x].m_value),
                      (__m128)COERCE_UNSIGNED_INT((float)this->m_axis[2].m_endPoints.m_data[node->max_z].m_value)),
                    _mm_unpacklo_ps(
                      (__m128)COERCE_UNSIGNED_INT((float)this->m_axis[1].m_endPoints.m_data[node->max_y].m_value),
                      (__m128)0i64)),
                  v5),
                this->m_offsetLow.m_quad);
  aabb->m_min.m_quad = _mm_sub_ps(
                         _mm_mul_ps(
                           _mm_unpacklo_ps(
                             _mm_unpacklo_ps(
                               (__m128)COERCE_UNSIGNED_INT((float)this->m_axis[0].m_endPoints.m_data[node->min_x].m_value),
                               (__m128)COERCE_UNSIGNED_INT((float)this->m_axis[2].m_endPoints.m_data[node->min_z].m_value)),
                             _mm_unpacklo_ps(
                               (__m128)COERCE_UNSIGNED_INT((float)this->m_axis[1].m_endPoints.m_data[node->min_y].m_value),
                               (__m128)0i64)),
                           v5),
                         this->m_offsetLow.m_quad);
  aabb->m_max = (hkVector4f)v6.m_quad;
}

// File Line: 4560
// RVA: 0xD03FA0
void __fastcall hkp3AxisSweep::shiftAllObjects(
        hkp3AxisSweep *this,
        hkVector4f *shiftDistance,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *effectiveShiftDistanceOut,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newCollisionPairs)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  hkp3AxisSweep *v6; // r11
  float v7; // xmm0_4
  float v8; // xmm2_4
  __int64 v9; // rax
  __int64 v10; // rax
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> v11; // xmm0
  int v12; // r9d
  __int64 v13; // r8
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  __int64 v17; // rbx
  __int64 v18; // r8
  int v19; // ecx
  __int64 v20; // rax
  hkp3AxisSweep::hkpBpNode *m_data; // r10
  int v22; // ecx
  int v23; // edx
  __int64 v24; // r9
  int v25; // ecx
  hkp3AxisSweep::hkpBpEndPoint *v26; // r8
  hkp3AxisSweep::hkpBpEndPoint *v27; // rdx
  unsigned int m_value; // r13d
  hkp3AxisSweep::hkpBpNode *v29; // r14
  int v30; // ecx
  __int64 min_z; // rax
  hkp3AxisSweep::hkpBpEndPoint *v32; // rcx
  unsigned int v33; // r15d
  __int64 max_z; // rax
  hkpBroadPhaseHandle *m_handle; // rax
  __int64 m_id; // r12
  __int64 min_x; // rsi
  hkp3AxisSweep::hkpBpNode *v38; // rbx
  __int64 v39; // rdi
  unsigned int v40; // r9d
  _DWORD *v41; // r8
  __int64 v42; // rcx
  hkp3AxisSweep::hkpBpNode *v43; // rdx
  int v44; // ecx
  int v45; // eax
  _DWORD *v46; // rcx
  __int64 v47; // rdx
  int v48; // eax
  __int16 v49; // ax
  __int64 max_x; // rsi
  __int64 v51; // rdi
  unsigned int v52; // r8d
  __int64 v53; // rcx
  hkp3AxisSweep::hkpBpNode *v54; // rdx
  int v55; // ecx
  __int64 v56; // rdx
  __int64 v57; // rcx
  int v58; // eax
  unsigned int v59; // r9d
  _DWORD *v60; // r8
  __int64 v61; // rax
  hkp3AxisSweep::hkpBpNode *v62; // rdx
  int v63; // ecx
  int v64; // eax
  _DWORD *v65; // rdx
  __int64 v66; // rcx
  int v67; // eax
  __int16 v68; // ax
  hkp3AxisSweep *v69; // r10
  __int64 v70; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v71; // rdi
  unsigned int v72; // r9d
  hkp3AxisSweep::hkpBpEndPoint *j; // r8
  __int64 m_nodeIndex; // rcx
  hkp3AxisSweep::hkpBpNode *v75; // rdx
  int v76; // ecx
  hkp3AxisSweep::hkpBpEndPoint *v77; // rdx
  __int64 v78; // rcx
  int v79; // eax
  unsigned __int16 v80; // ax
  unsigned int v81; // r15d
  __int64 min_y; // rsi
  __int64 v83; // rdi
  unsigned int v84; // r9d
  _DWORD *v85; // r8
  __int64 v86; // rcx
  hkp3AxisSweep::hkpBpNode *v87; // rdx
  __int16 v88; // cx
  __int16 v89; // ax
  _DWORD *v90; // rcx
  __int64 v91; // rdx
  int v92; // eax
  unsigned __int16 v93; // r15
  unsigned int v94; // r13d
  __int64 max_y; // rsi
  __int64 v96; // rdi
  unsigned int v97; // r8d
  __int64 v98; // rcx
  hkp3AxisSweep::hkpBpNode *v99; // rdx
  __int16 v100; // cx
  __int16 v101; // ax
  __int64 v102; // rdx
  __int64 v103; // rcx
  int v104; // eax
  unsigned int v105; // r9d
  _DWORD *v106; // r8
  __int64 v107; // rax
  hkp3AxisSweep::hkpBpNode *v108; // rdx
  unsigned __int16 v109; // cx
  unsigned __int16 v110; // ax
  _DWORD *v111; // rdx
  __int64 v112; // rcx
  int v113; // eax
  __int16 v114; // ax
  hkp3AxisSweep *v115; // r10
  unsigned int v116; // r13d
  __int64 v117; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v118; // rdi
  unsigned int v119; // r9d
  hkp3AxisSweep::hkpBpEndPoint *v120; // r8
  __int64 v121; // rcx
  hkp3AxisSweep::hkpBpNode *v122; // rdx
  unsigned __int16 v123; // cx
  unsigned __int16 v124; // ax
  hkp3AxisSweep::hkpBpEndPoint *v125; // rdx
  __int64 v126; // rcx
  int v127; // eax
  unsigned int v128; // r15d
  __int64 v129; // rsi
  __int64 v130; // rdi
  unsigned int v131; // r9d
  _DWORD *v132; // r8
  __int64 v133; // rcx
  hkp3AxisSweep::hkpBpNode *v134; // rdx
  __int16 v135; // cx
  __int16 v136; // ax
  _DWORD *v137; // rcx
  __int64 v138; // rdx
  int v139; // eax
  unsigned __int16 v140; // r15
  unsigned int v141; // r13d
  __int64 v142; // rsi
  __int64 v143; // rdi
  unsigned int v144; // r8d
  __int64 v145; // rcx
  hkp3AxisSweep::hkpBpNode *v146; // rdx
  __int16 v147; // cx
  __int16 v148; // ax
  __int64 v149; // rdx
  __int64 v150; // rcx
  int v151; // eax
  unsigned int v152; // r9d
  _DWORD *v153; // r8
  __int64 v154; // rax
  hkp3AxisSweep::hkpBpNode *v155; // rdx
  unsigned __int16 v156; // cx
  unsigned __int16 v157; // ax
  _DWORD *v158; // rcx
  __int64 v159; // rdx
  int v160; // eax
  __int16 v161; // ax
  unsigned int v162; // r13d
  __int64 v163; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v164; // rdi
  unsigned int v165; // r9d
  hkp3AxisSweep::hkpBpEndPoint *v166; // r8
  __int64 v167; // rcx
  hkp3AxisSweep::hkpBpNode *v168; // rdx
  unsigned __int16 v169; // cx
  unsigned __int16 v170; // ax
  hkp3AxisSweep::hkpBpEndPoint *v171; // rcx
  __int64 v172; // rdx
  int v173; // eax
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> deletedPairsOut; // [rsp+30h] [rbp-59h] BYREF
  unsigned int v175; // [rsp+40h] [rbp-49h]
  int v176; // [rsp+44h] [rbp-45h]
  unsigned int v177; // [rsp+48h] [rbp-41h]
  unsigned int v178; // [rsp+50h] [rbp-39h]
  unsigned int v179; // [rsp+54h] [rbp-35h]
  unsigned int v180; // [rsp+58h] [rbp-31h]
  __int64 v181; // [rsp+60h] [rbp-29h]
  __int64 v182; // [rsp+68h] [rbp-21h]
  __int64 i; // [rsp+70h] [rbp-19h]
  __int64 v184; // [rsp+78h] [rbp-11h]
  __int64 v185; // [rsp+80h] [rbp-9h]
  __int64 v186[2]; // [rsp+88h] [rbp-1h]
  __int64 v187; // [rsp+98h] [rbp+Fh]
  int v189; // [rsp+F8h] [rbp+6Fh]

  v4 = this->m_scale.m_quad.m128_f32[0];
  v5 = this->m_scale.m_quad.m128_f32[2];
  deletedPairsOut = (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator>)shiftDistance->m_quad;
  v6 = this;
  v186[0] = (int)(float)(v4 * *(float *)&deletedPairsOut.m_data) & 0xFFFFFFFE;
  v7 = (float)SLODWORD(v186[0]) / v4;
  v8 = this->m_scale.m_quad.m128_f32[1];
  *(float *)&deletedPairsOut.m_data = v7;
  v9 = (unsigned int)(int)(float)(v8 * *((float *)&deletedPairsOut.m_data + 1));
  v186[1] = v9 & 0xFFFFFFFFFFFFFFFEui64;
  v187 = (int)(float)(v5 * *(float *)&deletedPairsOut.m_size) & 0xFFFFFFFE;
  *((float *)&deletedPairsOut.m_data + 1) = (float)(v9 & 0xFFFFFFFE) / v8;
  v10 = 0i64;
  v181 = 0i64;
  *(float *)&deletedPairsOut.m_size = (float)(int)v187 / v5;
  v11 = deletedPairsOut;
  deletedPairsOut.m_data = 0i64;
  deletedPairsOut.m_size = 0;
  deletedPairsOut.m_capacityAndFlags = 0x80000000;
  *effectiveShiftDistanceOut = v11;
  do
  {
    v12 = v186[v10];
    v189 = v12;
    v13 = (__int64)&v6->m_axis[v10];
    v184 = v13;
    if ( v12 >= 0 )
    {
      v15 = 0;
      v14 = *(_DWORD *)(v13 + 8) - 2;
      v16 = -1;
    }
    else
    {
      v14 = 1;
      v15 = *(_DWORD *)(v13 + 8) - 1;
      v16 = 1;
    }
    v17 = v14;
    v185 = v16;
    v182 = v14;
    for ( i = v15; v17 != i; v182 = v17 )
    {
      v18 = *(_QWORD *)v13;
      v19 = *(unsigned __int16 *)(v18 + 4 * v17);
      if ( (unsigned int)(v19 - 2) <= 0xFFF9 )
      {
        v20 = *(unsigned __int16 *)(v18 + 4 * v17 + 2);
        m_data = v6->m_nodes.m_data;
        v22 = v12 + v19;
        v23 = *(_WORD *)(v18 + 4 * v17) & 1;
        v24 = v20;
        v25 = v23 | v22 & 0xFFFFFFFE;
        if ( v25 >= 0 )
        {
          if ( v25 >= 65532 )
            v25 = v23 | 0xFFFC;
        }
        else
        {
          v25 = *(_WORD *)(v18 + 4 * v17) & 1;
        }
        *(_WORD *)(v18 + 4 * v17) = v25;
        if ( !v25 || v25 == 65533 )
        {
          v26 = v6->m_axis[0].m_endPoints.m_data;
          v27 = v6->m_axis[1].m_endPoints.m_data;
          m_value = v26[m_data[v20].min_x].m_value;
          v29 = v6->m_nodes.m_data;
          v30 = v27[m_data[v20].min_y].m_value;
          min_z = m_data[v20].min_z;
          v175 = m_value;
          v176 = v30;
          v32 = v6->m_axis[2].m_endPoints.m_data;
          v177 = v32[min_z].m_value;
          v33 = v26[m_data[v24].max_x].m_value;
          LODWORD(v26) = v27[m_data[v24].max_y].m_value;
          max_z = m_data[v24].max_z;
          v178 = v33;
          LODWORD(v27) = v32[max_z].m_value;
          m_handle = m_data[v24].m_handle;
          v179 = (unsigned int)v26;
          m_id = m_handle->m_id;
          v180 = (unsigned int)v27;
          min_x = v29[m_id].min_x;
          v38 = &v29[m_id];
          v39 = (__int64)&v6->m_axis[0].m_endPoints.m_data[min_x];
          v40 = *(unsigned __int16 *)(v39 - 4);
          v41 = (_DWORD *)(v39 - 4);
          if ( m_value < v40 )
          {
            do
            {
              v42 = *(unsigned __int16 *)(v39 - 2);
              *(_DWORD *)v39 = *v41;
              v39 = (__int64)v41;
              v43 = &v29[v42];
              if ( (v40 & 1) != 0 )
              {
                v44 = *(_DWORD *)&v43->max_y - *(_DWORD *)&v38->min_y;
                v45 = *(_DWORD *)&v38->max_y - *(_DWORD *)&v43->min_y;
                v43->max_x = min_x;
                if ( ((v45 | v44) & 0x80008000) == 0 )
                  hkp3AxisSweep::beginOverlapCheckMarker(this->m_markers, &v29[m_id], m_id, v43, newCollisionPairs);
              }
              else
              {
                v43->min_x = min_x;
              }
              v40 = *(unsigned __int16 *)(v39 - 4);
              v41 = (_DWORD *)(v39 - 4);
              LOWORD(min_x) = min_x - 1;
            }
            while ( m_value < v40 );
            v33 = v178;
            v6 = this;
          }
          v46 = (_DWORD *)(v39 - 4);
          if ( m_value == *(unsigned __int16 *)(v39 - 4) )
          {
            do
            {
              v47 = *(unsigned __int16 *)(v39 - 2);
              if ( (unsigned int)m_id >= (unsigned int)v47 )
                break;
              *(_DWORD *)v39 = *v46;
              v39 = (__int64)v46;
              v29[v47].min_x = min_x;
              v48 = *((unsigned __int16 *)v46-- - 2);
              LOWORD(min_x) = min_x - 1;
            }
            while ( m_value == v48 );
          }
          v49 = v175;
          *(_WORD *)(v39 + 2) = m_id;
          *(_WORD *)v39 = v49;
          v38->min_x = min_x;
          max_x = v38->max_x;
          v51 = (__int64)&v6->m_axis[0].m_endPoints.m_data[max_x];
          v52 = *(unsigned __int16 *)(v51 + 4);
          v53 = v51 + 4;
          if ( v33 > v52 )
          {
            do
            {
              LOWORD(max_x) = max_x + 1;
              *(_DWORD *)v51 = *(_DWORD *)v53;
              v51 = v53;
              v54 = &v29[*(unsigned __int16 *)(v53 + 2)];
              if ( (v52 & 1) != 0 )
              {
                --v54->max_x;
              }
              else
              {
                v55 = (*(_DWORD *)&v54->max_y - *(_DWORD *)&v38->min_y) | (*(_DWORD *)&v38->max_y
                                                                         - *(_DWORD *)&v54->min_y);
                --v54->min_x;
                if ( (v55 & 0x80008000) == 0 )
                  hkp3AxisSweep::beginOverlapCheckMarker(this->m_markers, &v29[m_id], m_id, v54, newCollisionPairs);
              }
              v52 = *(unsigned __int16 *)(v51 + 4);
              v53 = v51 + 4;
            }
            while ( v33 > v52 );
            m_value = v175;
          }
          v56 = v51 + 4;
          if ( v33 == *(unsigned __int16 *)(v51 + 4) )
          {
            do
            {
              v57 = *(unsigned __int16 *)(v51 + 6);
              if ( (unsigned int)m_id <= (unsigned int)v57 )
                break;
              if ( !*(_WORD *)(v51 + 6) )
                break;
              LOWORD(max_x) = max_x + 1;
              *(_DWORD *)v51 = *(_DWORD *)v56;
              --v29[v57].max_x;
              v58 = *(unsigned __int16 *)(v56 + 4);
              v51 = v56;
              v56 += 4i64;
            }
            while ( v33 == v58 );
            m_value = v175;
          }
          v59 = *(unsigned __int16 *)(v51 - 4);
          v60 = (_DWORD *)(v51 - 4);
          if ( v33 < v59 )
          {
            do
            {
              LOWORD(max_x) = max_x - 1;
              *(_DWORD *)v51 = *v60;
              v61 = *(unsigned __int16 *)(v51 - 2);
              v51 = (__int64)v60;
              v62 = &v29[v61];
              if ( (v59 & 1) != 0 )
              {
                ++v62->max_x;
              }
              else
              {
                v63 = *(_DWORD *)&v38->max_y - *(_DWORD *)&v62->min_y;
                v64 = *(_DWORD *)&v62->max_y - *(_DWORD *)&v38->min_y;
                ++v62->min_x;
                if ( ((v64 | v63) & 0x80008000) == 0 )
                  hkp3AxisSweep::endOverlapCheckMarker(this->m_markers, &v29[m_id], m_id, v62, &deletedPairsOut);
              }
              v59 = *(unsigned __int16 *)(v51 - 4);
              v60 = (_DWORD *)(v51 - 4);
            }
            while ( v33 < v59 );
            m_value = v175;
          }
          v65 = (_DWORD *)(v51 - 4);
          if ( v33 == *(unsigned __int16 *)(v51 - 4) )
          {
            do
            {
              v66 = *(unsigned __int16 *)(v51 - 2);
              if ( (unsigned int)m_id >= (unsigned int)v66 )
                break;
              LOWORD(max_x) = max_x - 1;
              *(_DWORD *)v51 = *v65;
              ++v29[v66].max_x;
              v67 = *((unsigned __int16 *)v65 - 2);
              v51 = (__int64)v65--;
            }
            while ( v33 == v67 );
          }
          v68 = v178;
          v69 = this;
          v38->max_x = max_x;
          *(_WORD *)v51 = v68;
          *(_WORD *)(v51 + 2) = m_id;
          v70 = v38->min_x;
          v71 = &this->m_axis[0].m_endPoints.m_data[v70];
          v72 = v71[1].m_value;
          for ( j = v71 + 1; m_value > v72; j = v71 + 1 )
          {
            LOWORD(v70) = v70 + 1;
            m_nodeIndex = v71[1].m_nodeIndex;
            *v71 = *j;
            v71 = j;
            v75 = &v29[m_nodeIndex];
            if ( (v72 & 1) != 0 )
            {
              v76 = (*(_DWORD *)&v75->max_y - *(_DWORD *)&v38->min_y) | (*(_DWORD *)&v38->max_y - *(_DWORD *)&v75->min_y);
              --v75->max_x;
              if ( (v76 & 0x80008000) == 0 )
              {
                hkp3AxisSweep::endOverlapCheckMarker(v69->m_markers, &v29[m_id], m_id, v75, &deletedPairsOut);
                v69 = this;
              }
            }
            else
            {
              --v75->min_x;
            }
            v72 = v71[1].m_value;
          }
          v77 = v71 + 1;
          if ( m_value == v71[1].m_value )
          {
            do
            {
              v78 = v71[1].m_nodeIndex;
              if ( (unsigned int)m_id <= (unsigned int)v78 )
                break;
              LOWORD(v70) = v70 + 1;
              *v71 = *v77;
              --v29[v78].min_x;
              v79 = v77[1].m_value;
              v71 = v77++;
            }
            while ( m_value == v79 );
            v69 = this;
          }
          v80 = v175;
          v81 = v176;
          v38->min_x = v70;
          v71->m_value = v80;
          v71->m_nodeIndex = m_id;
          min_y = v38->min_y;
          v83 = (__int64)&v69->m_axis[1].m_endPoints.m_data[min_y];
          v84 = *(unsigned __int16 *)(v83 - 4);
          v85 = (_DWORD *)(v83 - 4);
          if ( v81 < v84 )
          {
            do
            {
              v86 = *(unsigned __int16 *)(v83 - 2);
              *(_DWORD *)v83 = *v85;
              v83 = (__int64)v85;
              v87 = &v29[v86];
              if ( (v84 & 1) != 0 )
              {
                v88 = (v38->max_x - v87->min_x) | (v38->max_z - v87->min_z) | (v87->max_z - v38->min_z);
                v89 = v87->max_x - v38->min_x;
                v87->max_y = min_y;
                if ( ((v89 | v88) & 0x8000u) == 0 )
                  hkp3AxisSweep::beginOverlap(v38, v87, newCollisionPairs);
              }
              else
              {
                v87->min_y = min_y;
              }
              v84 = *(unsigned __int16 *)(v83 - 4);
              v85 = (_DWORD *)(v83 - 4);
              LOWORD(min_y) = min_y - 1;
            }
            while ( v81 < v84 );
            v69 = this;
          }
          v90 = (_DWORD *)(v83 - 4);
          if ( v81 == *(unsigned __int16 *)(v83 - 4) )
          {
            do
            {
              v91 = *(unsigned __int16 *)(v83 - 2);
              if ( (unsigned int)m_id >= (unsigned int)v91 )
                break;
              *(_DWORD *)v83 = *v90;
              v83 = (__int64)v90;
              v29[v91].min_y = min_y;
              v92 = *((unsigned __int16 *)v90-- - 2);
              LOWORD(min_y) = min_y - 1;
            }
            while ( v81 == v92 );
          }
          v93 = v176;
          v94 = v179;
          *(_WORD *)(v83 + 2) = m_id;
          *(_WORD *)v83 = v93;
          v38->min_y = min_y;
          max_y = v38->max_y;
          v96 = (__int64)&v69->m_axis[1].m_endPoints.m_data[max_y];
          v97 = *(unsigned __int16 *)(v96 + 4);
          v98 = v96 + 4;
          if ( v94 > v97 )
          {
            do
            {
              LOWORD(max_y) = max_y + 1;
              *(_DWORD *)v96 = *(_DWORD *)v98;
              v96 = v98;
              v99 = &v29[*(unsigned __int16 *)(v98 + 2)];
              if ( (v97 & 1) != 0 )
              {
                --v99->max_y;
              }
              else
              {
                v100 = (v38->max_x - v99->min_x) | (v99->max_z - v38->min_z) | (v38->max_z - v99->min_z);
                v101 = v99->max_x - v38->min_x;
                --v99->min_y;
                if ( ((v101 | v100) & 0x8000u) == 0 )
                  hkp3AxisSweep::beginOverlap(v38, v99, newCollisionPairs);
              }
              v97 = *(unsigned __int16 *)(v96 + 4);
              v98 = v96 + 4;
            }
            while ( v94 > v97 );
            v93 = v176;
          }
          v102 = v96 + 4;
          if ( v94 == *(unsigned __int16 *)(v96 + 4) )
          {
            do
            {
              v103 = *(unsigned __int16 *)(v96 + 6);
              if ( (unsigned int)m_id <= (unsigned int)v103 )
                break;
              if ( !*(_WORD *)(v96 + 6) )
                break;
              LOWORD(max_y) = max_y + 1;
              *(_DWORD *)v96 = *(_DWORD *)v102;
              --v29[v103].max_y;
              v104 = *(unsigned __int16 *)(v102 + 4);
              v96 = v102;
              v102 += 4i64;
            }
            while ( v94 == v104 );
            v93 = v176;
          }
          v105 = *(unsigned __int16 *)(v96 - 4);
          v106 = (_DWORD *)(v96 - 4);
          if ( v94 < v105 )
          {
            do
            {
              LOWORD(max_y) = max_y - 1;
              *(_DWORD *)v96 = *v106;
              v107 = *(unsigned __int16 *)(v96 - 2);
              v96 = (__int64)v106;
              v108 = &v29[v107];
              if ( (v105 & 1) != 0 )
              {
                ++v108->max_y;
              }
              else
              {
                v109 = (v38->max_x - v108->min_x) | (v108->max_z - v38->min_z) | (v38->max_z - v108->min_z);
                v110 = v108->max_x - v38->min_x;
                ++v108->min_y;
                if ( ((v110 | v109) & 0x8000) == 0 )
                  hkp3AxisSweep::endOverlap(v38, v108, &deletedPairsOut);
              }
              v105 = *(unsigned __int16 *)(v96 - 4);
              v106 = (_DWORD *)(v96 - 4);
            }
            while ( v94 < v105 );
            v93 = v176;
          }
          v111 = (_DWORD *)(v96 - 4);
          if ( v94 == *(unsigned __int16 *)(v96 - 4) )
          {
            do
            {
              v112 = *(unsigned __int16 *)(v96 - 2);
              if ( (unsigned int)m_id >= (unsigned int)v112 )
                break;
              LOWORD(max_y) = max_y - 1;
              *(_DWORD *)v96 = *v111;
              ++v29[v112].max_y;
              v113 = *((unsigned __int16 *)v111 - 2);
              v96 = (__int64)v111--;
            }
            while ( v94 == v113 );
          }
          v114 = v179;
          v115 = this;
          v116 = v176;
          v38->max_y = max_y;
          *(_WORD *)v96 = v114;
          *(_WORD *)(v96 + 2) = m_id;
          v117 = v38->min_y;
          v118 = &this->m_axis[1].m_endPoints.m_data[v117];
          v119 = v118[1].m_value;
          v120 = v118 + 1;
          if ( v116 > v119 )
          {
            do
            {
              LOWORD(v117) = v117 + 1;
              v121 = v118[1].m_nodeIndex;
              *v118 = *v120;
              v118 = v120;
              v122 = &v29[v121];
              if ( (v119 & 1) != 0 )
              {
                v123 = (v38->max_x - v122->min_x) | (v122->max_z - v38->min_z) | (v38->max_z - v122->min_z);
                v124 = v122->max_x - v38->min_x;
                --v122->max_y;
                if ( ((v124 | v123) & 0x8000) == 0 )
                  hkp3AxisSweep::endOverlap(v38, v122, &deletedPairsOut);
              }
              else
              {
                --v122->min_y;
              }
              v119 = v118[1].m_value;
              v120 = v118 + 1;
            }
            while ( v116 > v119 );
            v93 = v176;
            v115 = this;
          }
          v125 = v118 + 1;
          if ( v116 == v118[1].m_value )
          {
            do
            {
              v126 = v118[1].m_nodeIndex;
              if ( (unsigned int)m_id <= (unsigned int)v126 )
                break;
              LOWORD(v117) = v117 + 1;
              *v118 = *v125;
              --v29[v126].min_y;
              v127 = v125[1].m_value;
              v118 = v125++;
            }
            while ( v116 == v127 );
            v93 = v176;
          }
          v38->min_y = v117;
          v118->m_value = v93;
          v128 = v177;
          v118->m_nodeIndex = m_id;
          v129 = v38->min_z;
          v130 = (__int64)&v115->m_axis[2].m_endPoints.m_data[v129];
          v131 = *(unsigned __int16 *)(v130 - 4);
          v132 = (_DWORD *)(v130 - 4);
          if ( v128 < v131 )
          {
            do
            {
              v133 = *(unsigned __int16 *)(v130 - 2);
              *(_DWORD *)v130 = *v132;
              v130 = (__int64)v132;
              v134 = &v29[v133];
              if ( (v131 & 1) != 0 )
              {
                v135 = (v134->max_x - v38->min_x) | (v134->max_y - v38->min_y) | (v38->max_x - v134->min_x);
                v136 = v38->max_y - v134->min_y;
                v134->max_z = v129;
                if ( ((v136 | v135) & 0x8000u) == 0 )
                  hkp3AxisSweep::beginOverlap(v38, v134, newCollisionPairs);
              }
              else
              {
                v134->min_z = v129;
              }
              v131 = *(unsigned __int16 *)(v130 - 4);
              v132 = (_DWORD *)(v130 - 4);
              LOWORD(v129) = v129 - 1;
            }
            while ( v128 < v131 );
            v115 = this;
          }
          v137 = (_DWORD *)(v130 - 4);
          if ( v128 == *(unsigned __int16 *)(v130 - 4) )
          {
            do
            {
              v138 = *(unsigned __int16 *)(v130 - 2);
              if ( (unsigned int)m_id >= (unsigned int)v138 )
                break;
              *(_DWORD *)v130 = *v137;
              v130 = (__int64)v137;
              v29[v138].min_z = v129;
              v139 = *((unsigned __int16 *)v137-- - 2);
              LOWORD(v129) = v129 - 1;
            }
            while ( v128 == v139 );
          }
          v140 = v177;
          v141 = v180;
          *(_WORD *)(v130 + 2) = m_id;
          *(_WORD *)v130 = v140;
          v38->min_z = v129;
          v142 = v38->max_z;
          v143 = (__int64)&v115->m_axis[2].m_endPoints.m_data[v142];
          v144 = *(unsigned __int16 *)(v143 + 4);
          v145 = v143 + 4;
          if ( v141 > v144 )
          {
            do
            {
              LOWORD(v142) = v142 + 1;
              *(_DWORD *)v143 = *(_DWORD *)v145;
              v143 = v145;
              v146 = &v29[*(unsigned __int16 *)(v145 + 2)];
              if ( (v144 & 1) != 0 )
              {
                --v146->max_z;
              }
              else
              {
                v147 = (v146->max_x - v38->min_x) | (v146->max_y - v38->min_y) | (v38->max_x - v146->min_x);
                v148 = v38->max_y - v146->min_y;
                --v146->min_z;
                if ( ((v148 | v147) & 0x8000u) == 0 )
                  hkp3AxisSweep::beginOverlap(v38, v146, newCollisionPairs);
              }
              v144 = *(unsigned __int16 *)(v143 + 4);
              v145 = v143 + 4;
            }
            while ( v141 > v144 );
            v140 = v177;
          }
          v149 = v143 + 4;
          if ( v141 == *(unsigned __int16 *)(v143 + 4) )
          {
            do
            {
              v150 = *(unsigned __int16 *)(v143 + 6);
              if ( (unsigned int)m_id <= (unsigned int)v150 )
                break;
              if ( !*(_WORD *)(v143 + 6) )
                break;
              LOWORD(v142) = v142 + 1;
              *(_DWORD *)v143 = *(_DWORD *)v149;
              --v29[v150].max_z;
              v151 = *(unsigned __int16 *)(v149 + 4);
              v143 = v149;
              v149 += 4i64;
            }
            while ( v141 == v151 );
            v140 = v177;
          }
          v152 = *(unsigned __int16 *)(v143 - 4);
          v153 = (_DWORD *)(v143 - 4);
          if ( v141 < v152 )
          {
            do
            {
              LOWORD(v142) = v142 - 1;
              *(_DWORD *)v143 = *v153;
              v154 = *(unsigned __int16 *)(v143 - 2);
              v143 = (__int64)v153;
              v155 = &v29[v154];
              if ( (v152 & 1) != 0 )
              {
                ++v155->max_z;
              }
              else
              {
                v156 = (v155->max_x - v38->min_x) | (v155->max_y - v38->min_y) | (v38->max_x - v155->min_x);
                v157 = v38->max_y - v155->min_y;
                ++v155->min_z;
                if ( ((v157 | v156) & 0x8000) == 0 )
                  hkp3AxisSweep::endOverlap(v38, v155, &deletedPairsOut);
              }
              v152 = *(unsigned __int16 *)(v143 - 4);
              v153 = (_DWORD *)(v143 - 4);
            }
            while ( v141 < v152 );
            v140 = v177;
          }
          v158 = (_DWORD *)(v143 - 4);
          if ( v141 == *(unsigned __int16 *)(v143 - 4) )
          {
            do
            {
              v159 = *(unsigned __int16 *)(v143 - 2);
              if ( (unsigned int)m_id >= (unsigned int)v159 )
                break;
              LOWORD(v142) = v142 - 1;
              *(_DWORD *)v143 = *v158;
              v143 = (__int64)v158;
              ++v29[v159].max_z;
              v160 = *((unsigned __int16 *)v158-- - 2);
            }
            while ( v141 == v160 );
          }
          v161 = v180;
          v6 = this;
          v162 = v177;
          v38->max_z = v142;
          *(_WORD *)v143 = v161;
          *(_WORD *)(v143 + 2) = m_id;
          v163 = v38->min_z;
          v164 = &this->m_axis[2].m_endPoints.m_data[v163];
          v165 = v164[1].m_value;
          v166 = v164 + 1;
          if ( v162 > v165 )
          {
            do
            {
              LOWORD(v163) = v163 + 1;
              v167 = v164[1].m_nodeIndex;
              *v164 = *v166;
              v164 = v166;
              v168 = &v29[v167];
              if ( (v165 & 1) != 0 )
              {
                v169 = (v168->max_x - v38->min_x) | (v168->max_y - v38->min_y) | (v38->max_x - v168->min_x);
                v170 = v38->max_y - v168->min_y;
                --v168->max_z;
                if ( ((v170 | v169) & 0x8000) == 0 )
                  hkp3AxisSweep::endOverlap(v38, v168, &deletedPairsOut);
              }
              else
              {
                --v168->min_z;
              }
              v165 = v164[1].m_value;
              v166 = v164 + 1;
            }
            while ( v162 > v165 );
            v140 = v177;
            v6 = this;
          }
          v171 = v164 + 1;
          if ( v162 == v164[1].m_value )
          {
            do
            {
              v172 = v164[1].m_nodeIndex;
              if ( (unsigned int)m_id <= (unsigned int)v172 )
                break;
              LOWORD(v163) = v163 + 1;
              *v164 = *v171;
              v164 = v171;
              --v29[v172].min_z;
              v173 = v171[1].m_value;
              ++v171;
            }
            while ( v162 == v173 );
            v140 = v177;
          }
          v38->min_z = v163;
          v17 = v182;
          v164->m_nodeIndex = m_id;
          v164->m_value = v140;
        }
        v12 = v189;
      }
      v17 += v185;
      v13 = v184;
    }
    v10 = v181 + 1;
    v181 = v10;
  }
  while ( v10 < 3 );
  deletedPairsOut.m_size = 0;
  if ( deletedPairsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      deletedPairsOut.m_data,
      16 * deletedPairsOut.m_capacityAndFlags);
}

// File Line: 4665
// RVA: 0xD04D20
void __fastcall hkp3AxisSweep::shiftBroadPhase(
        hkp3AxisSweep *this,
        hkVector4f *shiftDistance,
        hkVector4f *effectiveShiftDistanceOut,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newCollisionPairs)
{
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  hkVector4f v9; // xmm3
  hkVector4f v10; // xmm6
  hkVector4f v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  hkVector4f v14; // xmm2
  hkVector4f v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // [rsp+20h] [rbp-38h] BYREF
  __m128 v19; // [rsp+30h] [rbp-28h] BYREF

  vfptr = this->vfptr;
  v7 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v18 = _mm_xor_ps(shiftDistance->m_quad, v7);
  ((void (__fastcall *)(hkp3AxisSweep *, __m128 *, __m128 *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *))vfptr[11].__vecDelDtor)(
    this,
    &v18,
    &v19,
    newCollisionPairs);
  v8 = v19;
  v9.m_quad = _mm_add_ps(this->m_offsetLow.m_quad, v19);
  v10.m_quad = _mm_xor_ps(v7, v19);
  this->m_offsetLow = (hkVector4f)v9.m_quad;
  v11.m_quad = (__m128)this->m_scale;
  v12 = _mm_rcp_ps(v11.m_quad);
  v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11.m_quad, v12)), v12);
  this->m_offsetHigh.m_quad = _mm_add_ps(v9.m_quad, _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196));
  v14.m_quad = _mm_add_ps(this->m_offsetLow32bit.m_quad, v8);
  this->m_offsetLow32bit = (hkVector4f)v14.m_quad;
  v15.m_quad = (__m128)this->m_scale32bit;
  v16 = _mm_rcp_ps(v15.m_quad);
  v17 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15.m_quad, v16)), v16);
  this->m_offsetHigh32bit.m_quad = _mm_add_ps(v14.m_quad, _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, query.m_quad), 196));
  *effectiveShiftDistanceOut = (hkVector4f)v10.m_quad;
}

// File Line: 4694
// RVA: 0xD04E00
hkAabb *__fastcall hkp3AxisSweep::getOriginalAabb(hkp3AxisSweep *this)
{
  return &this->m_aabb;
}

// File Line: 4700
// RVA: 0xD06BA0
void __fastcall hkp3AxisSweep::checkDeterminism(hkp3AxisSweep *this)
{
  ;
}

// File Line: 4733
// RVA: 0xCFC2D0
void __fastcall hk3AxisSweep16CreateBroadPhase(hkVector4f *worldMin, hkVector4f *worldMax, int numMarkers)
{
  _QWORD **Value; // rax
  hkp3AxisSweep *v7; // rax

  hkOptionalComponent_hkp3AxisSweep.m_isUsed.m_bool = 1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkp3AxisSweep *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 272i64);
  if ( v7 )
    hkp3AxisSweep::hkp3AxisSweep(v7, worldMin, worldMax, numMarkers);
}

// File Line: 4737
// RVA: 0x15CC8E0
void dynamic_initializer_for__hkOptionalComponent_hkp3AxisSweep__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkp3AxisSweep,
    "hkp3AxisSweep",
    (void **)&hkpBroadPhase::s_createSweepAndPruneBroadPhaseFunction,
    hk3AxisSweep16CreateBroadPhase);
}

