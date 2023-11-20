// File Line: 64
// RVA: 0xD06BD0
void __fastcall memclear16(void *dest, int bytesize)
{
  int i; // edx
  _OWORD *v3; // rax

  for ( i = bytesize >> 4; i >= 0; *v3 = 0i64 )
  {
    v3 = dest;
    dest = (char *)dest + 16;
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
  return bitField[(signed __int64)index >> 5] & (1 << (index & 0x1F));
}

// File Line: 273
// RVA: 0xD05AE0
void __fastcall hkp3AxisSweep::beginOverlap(hkp3AxisSweep::hkpBpNode *a, hkp3AxisSweep::hkpBpNode *b, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairsOut)
{
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v3; // rbx
  unsigned __int128 v4; // di
  hkpBroadPhaseHandlePair *v5; // rcx

  v3 = newPairsOut;
  v4 = __PAIR__((unsigned __int64)a, (unsigned __int64)b);
  if ( newPairsOut->m_size == (newPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, newPairsOut, 16);
  v5 = &v3->m_data[v3->m_size++];
  v5->m_a = *(hkpBroadPhaseHandle **)(*((_QWORD *)&v4 + 1) + 16i64);
  v5->m_b = *(hkpBroadPhaseHandle **)(v4 + 16);
}

// File Line: 280
// RVA: 0xD05B60
void __fastcall hkp3AxisSweep::endOverlap(hkp3AxisSweep::hkpBpNode *a, hkp3AxisSweep::hkpBpNode *b, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *deletedPairsOut)
{
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v3; // rbx
  unsigned __int128 v4; // di
  hkpBroadPhaseHandlePair *v5; // rcx

  v3 = deletedPairsOut;
  v4 = __PAIR__((unsigned __int64)a, (unsigned __int64)b);
  if ( deletedPairsOut->m_size == (deletedPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, deletedPairsOut, 16);
  v5 = &v3->m_data[v3->m_size++];
  v5->m_a = *(hkpBroadPhaseHandle **)(*((_QWORD *)&v4 + 1) + 16i64);
  v5->m_b = *(hkpBroadPhaseHandle **)(v4 + 16);
}

// File Line: 287
// RVA: 0xD05920
void __fastcall hkp3AxisSweep::beginOverlapCheckMarker(hkp3AxisSweep::hkpBpMarker *markers, hkp3AxisSweep::hkpBpNode *a, int nodeIndexA, hkp3AxisSweep::hkpBpNode *b, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairsOut)
{
  hkp3AxisSweep::hkpBpNode *v5; // rdi
  __int16 v6; // si
  hkp3AxisSweep::hkpBpNode *v7; // rbp
  hkpBroadPhaseHandlePair *v8; // rcx
  _DWORD *v9; // rbx

  v5 = b;
  v6 = nodeIndexA;
  v7 = a;
  if ( (_QWORD)b->m_handle & 1 )
  {
    v9 = (_DWORD *)((char *)&markers->m_nodeIndex + ((_QWORD)b->m_handle & 0xFFFFFFFFFFFFFFFEui64));
    if ( v9[4] == (v9[5] & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9 + 2, 2);
    *(_WORD *)(*((_QWORD *)v9 + 1) + 2i64 * (signed int)v9[4]++) = v6;
  }
  else
  {
    if ( newPairsOut->m_size == (newPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, newPairsOut, 16);
    v8 = &newPairsOut->m_data[newPairsOut->m_size++];
    v8->m_a = v7->m_handle;
    v8->m_b = v5->m_handle;
  }
}

// File Line: 302
// RVA: 0xD059F0
void __fastcall hkp3AxisSweep::endOverlapCheckMarker(hkp3AxisSweep::hkpBpMarker *markers, hkp3AxisSweep::hkpBpNode *a, int nodeIndexA, hkp3AxisSweep::hkpBpNode *b, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *deletedPairsOut)
{
  hkp3AxisSweep::hkpBpNode *v5; // rdi
  __int16 v6; // r10
  hkp3AxisSweep::hkpBpNode *v7; // rsi
  hkpBroadPhaseHandlePair *v8; // rcx
  signed int v9; // er8
  char *v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // r11
  _WORD *v13; // rax

  v5 = b;
  v6 = nodeIndexA;
  v7 = a;
  if ( (_QWORD)b->m_handle & 1 )
  {
    v9 = 0;
    v10 = (char *)markers + ((_QWORD)b->m_handle & 0xFFFFFFFFFFFFFFFEui64);
    v11 = 0i64;
    v12 = *((signed int *)v10 + 4);
    if ( (signed int)v12 <= 0 )
    {
LABEL_9:
      v9 = -1;
    }
    else
    {
      v13 = (_WORD *)*((_QWORD *)v10 + 1);
      while ( *v13 != v6 )
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
      *(_WORD *)(*((_QWORD *)v10 + 1) + 2i64 * v9) = *(_WORD *)(*((_QWORD *)v10 + 1) + 2i64 * ((signed int)v12 - 1));
  }
  else
  {
    if ( deletedPairsOut->m_size == (deletedPairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, deletedPairsOut, 16);
    v8 = &deletedPairsOut->m_data[deletedPairsOut->m_size++];
    v8->m_a = v7->m_handle;
    v8->m_b = v5->m_handle;
  }
}

// File Line: 646
// RVA: 0xD05BE0
void __fastcall hkp3AxisSweep::_fixDeterministicOrderAfterNodeIdWasDecreased(hkp3AxisSweep *this, int nodeIndex)
{
  hkp3AxisSweep::hkpBpNode *v2; // r11
  hkp3AxisSweep *v3; // rdi
  __int64 v4; // r10
  hkp3AxisSweep::hkpBpNode *v5; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v6; // r9
  hkp3AxisSweep::hkpBpEndPoint *v7; // r8
  __int64 v8; // rcx
  unsigned __int16 v9; // ax
  __int64 v10; // r10
  signed __int64 v11; // r8
  _DWORD *v12; // r9
  __int64 v13; // rcx
  __int16 v14; // ax
  __int64 v15; // r10
  signed __int64 v16; // r8
  _DWORD *v17; // r9
  __int64 v18; // rcx
  __int16 v19; // ax
  __int64 v20; // r10
  signed __int64 v21; // r8
  _DWORD *v22; // r9
  __int64 v23; // rcx
  __int16 v24; // ax
  __int64 v25; // r10
  signed __int64 v26; // r8
  _DWORD *v27; // r9
  __int64 v28; // rcx
  __int16 v29; // ax
  __int64 v30; // r9
  signed __int64 v31; // r8
  _DWORD *v32; // r10
  __int64 v33; // rcx
  __int16 v34; // ax

  v2 = this->m_nodes.m_data;
  v3 = this;
  v4 = v2[nodeIndex].min_x;
  v5 = &v2[nodeIndex];
  v6 = &this->m_axis[0].m_endPoints.m_data[v4];
  v7 = v6 - 1;
  if ( v6->m_value == v6[-1].m_value )
  {
    do
    {
      v8 = v6[-1].m_nodeIndex;
      if ( nodeIndex >= (unsigned int)v8 )
        break;
      *v6 = *v7;
      v2[v8].min_x = v4;
      v9 = v7[-1].m_value;
      v6 = v7;
      --v7;
      LOWORD(v4) = v4 - 1;
    }
    while ( v6->m_value == v9 );
  }
  v6->m_nodeIndex = nodeIndex;
  v5->min_x = v4;
  v10 = v5->max_x;
  v11 = (signed __int64)&v3->m_axis[0].m_endPoints.m_data[v10];
  v12 = (_DWORD *)(v11 - 4);
  if ( *(_WORD *)v11 == *(_WORD *)(v11 - 4) )
  {
    do
    {
      v13 = *(unsigned __int16 *)(v11 - 2);
      if ( nodeIndex >= (unsigned int)v13 )
        break;
      *(_DWORD *)v11 = *v12;
      v2[v13].max_x = v10;
      v14 = *((_WORD *)v12 - 2);
      v11 = (signed __int64)v12;
      --v12;
      LOWORD(v10) = v10 - 1;
    }
    while ( *(_WORD *)v11 == v14 );
  }
  *(_WORD *)(v11 + 2) = nodeIndex;
  v5->max_x = v10;
  v15 = v5->min_y;
  v16 = (signed __int64)&v3->m_axis[1].m_endPoints.m_data[v15];
  v17 = (_DWORD *)(v16 - 4);
  if ( *(_WORD *)v16 == *(_WORD *)(v16 - 4) )
  {
    do
    {
      v18 = *(unsigned __int16 *)(v16 - 2);
      if ( nodeIndex >= (unsigned int)v18 )
        break;
      *(_DWORD *)v16 = *v17;
      v2[v18].min_y = v15;
      v19 = *((_WORD *)v17 - 2);
      v16 = (signed __int64)v17;
      --v17;
      LOWORD(v15) = v15 - 1;
    }
    while ( *(_WORD *)v16 == v19 );
  }
  *(_WORD *)(v16 + 2) = nodeIndex;
  v5->min_y = v15;
  v20 = v5->max_y;
  v21 = (signed __int64)&v3->m_axis[1].m_endPoints.m_data[v20];
  v22 = (_DWORD *)(v21 - 4);
  if ( *(_WORD *)v21 == *(_WORD *)(v21 - 4) )
  {
    do
    {
      v23 = *(unsigned __int16 *)(v21 - 2);
      if ( nodeIndex >= (unsigned int)v23 )
        break;
      *(_DWORD *)v21 = *v22;
      v2[v23].max_y = v20;
      v24 = *((_WORD *)v22 - 2);
      v21 = (signed __int64)v22;
      --v22;
      LOWORD(v20) = v20 - 1;
    }
    while ( *(_WORD *)v21 == v24 );
  }
  *(_WORD *)(v21 + 2) = nodeIndex;
  v5->max_y = v20;
  v25 = v5->min_z;
  v26 = (signed __int64)&v3->m_axis[2].m_endPoints.m_data[v25];
  v27 = (_DWORD *)(v26 - 4);
  if ( *(_WORD *)v26 == *(_WORD *)(v26 - 4) )
  {
    do
    {
      v28 = *(unsigned __int16 *)(v26 - 2);
      if ( nodeIndex >= (unsigned int)v28 )
        break;
      *(_DWORD *)v26 = *v27;
      v2[v28].min_z = v25;
      v29 = *((_WORD *)v27 - 2);
      v26 = (signed __int64)v27;
      --v27;
      LOWORD(v25) = v25 - 1;
    }
    while ( *(_WORD *)v26 == v29 );
  }
  *(_WORD *)(v26 + 2) = nodeIndex;
  v5->min_z = v25;
  v30 = v5->max_z;
  v31 = (signed __int64)&v3->m_axis[2].m_endPoints.m_data[v30];
  v32 = (_DWORD *)(v31 - 4);
  if ( *(_WORD *)v31 == *(_WORD *)(v31 - 4) )
  {
    do
    {
      v33 = *(unsigned __int16 *)(v31 - 2);
      if ( nodeIndex >= (unsigned int)v33 )
        break;
      *(_DWORD *)v31 = *v32;
      v2[v33].max_z = v30;
      v34 = *((_WORD *)v32 - 2);
      v31 = (signed __int64)v32;
      --v32;
      LOWORD(v30) = v30 - 1;
    }
    while ( *(_WORD *)v31 == v34 );
  }
  *(_WORD *)(v31 + 2) = nodeIndex;
  v5->max_z = v30;
}

// File Line: 683
// RVA: 0xCFF180
void __fastcall hkp3AxisSweep::updateAabbs(hkp3AxisSweep *this, hkpBroadPhaseHandle **objects, hkAabb *aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairsOut, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairsOut)
{
  hkp3AxisSweep *v6; // r12
  hkp3AxisSweep *v7; // r10
  hkp3AxisSweep::hkpBpNode *v8; // rdi
  __m128 v9; // xmm0
  __m128i v10; // xmm1
  __m128 v11; // xmm0
  unsigned int v12; // er12
  __m128 v13; // xmm0
  __m128i v14; // xmm6
  unsigned int v15; // er15
  __int64 v16; // r14
  unsigned int v17; // er13
  __int64 v18; // rbp
  hkp3AxisSweep::hkpBpNode *v19; // rbx
  signed __int64 v20; // rsi
  unsigned int v21; // er9
  _DWORD *v22; // r8
  signed __int64 v23; // rcx
  signed __int64 v24; // rdx
  int v25; // ecx
  int v26; // eax
  _DWORD *v27; // rcx
  __int64 v28; // rdx
  int v29; // eax
  __int64 v30; // rbp
  signed __int64 v31; // rsi
  unsigned int v32; // er8
  signed __int64 v33; // rcx
  signed __int64 v34; // rdx
  int v35; // ecx
  int v36; // eax
  signed __int64 v37; // rdx
  __int64 v38; // rcx
  int v39; // eax
  unsigned int v40; // er9
  _DWORD *v41; // r8
  __int64 v42; // rax
  signed __int64 v43; // rdx
  int v44; // ecx
  int v45; // eax
  _DWORD *v46; // rcx
  __int64 v47; // rdx
  int v48; // eax
  __int64 v49; // rbp
  signed __int64 v50; // rsi
  unsigned int v51; // er9
  _DWORD *v52; // r8
  signed __int64 v53; // rcx
  signed __int64 v54; // rdx
  int v55; // ecx
  int v56; // eax
  signed __int64 v57; // rcx
  __int64 v58; // rdx
  int v59; // eax
  unsigned int v60; // er15
  __int64 v61; // rbp
  signed __int64 v62; // rsi
  unsigned int v63; // er9
  _DWORD *v64; // r8
  signed __int64 v65; // rcx
  hkp3AxisSweep::hkpBpNode *v66; // rdx
  unsigned __int16 v67; // cx
  unsigned __int16 v68; // ax
  _DWORD *v69; // rcx
  __int64 v70; // rdx
  int v71; // eax
  __int64 v72; // rbp
  signed __int64 v73; // rsi
  unsigned int v74; // er8
  signed __int64 v75; // rcx
  hkp3AxisSweep::hkpBpNode *v76; // rdx
  unsigned __int16 v77; // cx
  unsigned __int16 v78; // ax
  signed __int64 v79; // rdx
  __int64 v80; // rcx
  int v81; // eax
  unsigned int v82; // er9
  _DWORD *v83; // r8
  __int64 v84; // rax
  hkp3AxisSweep::hkpBpNode *v85; // rdx
  unsigned __int16 v86; // cx
  unsigned __int16 v87; // ax
  _DWORD *v88; // rcx
  __int64 v89; // rdx
  int v90; // eax
  __int64 v91; // rbp
  signed __int64 v92; // rsi
  unsigned int v93; // er9
  _DWORD *v94; // r8
  signed __int64 v95; // rcx
  hkp3AxisSweep::hkpBpNode *v96; // rdx
  __int16 v97; // cx
  __int16 v98; // ax
  signed __int64 v99; // rcx
  __int64 v100; // rdx
  int v101; // eax
  __int64 v102; // rbp
  signed __int64 v103; // rsi
  unsigned int v104; // er9
  _DWORD *v105; // r8
  signed __int64 v106; // rcx
  hkp3AxisSweep::hkpBpNode *v107; // rdx
  unsigned __int16 v108; // cx
  unsigned __int16 v109; // ax
  _DWORD *v110; // rcx
  __int64 v111; // rdx
  int v112; // eax
  __int16 v113; // r15
  __int64 v114; // rbp
  signed __int64 v115; // rsi
  unsigned int v116; // er8
  signed __int64 v117; // rcx
  hkp3AxisSweep::hkpBpNode *v118; // rdx
  unsigned __int16 v119; // cx
  unsigned __int16 v120; // ax
  signed __int64 v121; // rdx
  __int64 v122; // rcx
  int v123; // eax
  unsigned int v124; // er9
  _DWORD *v125; // r8
  __int64 v126; // rax
  hkp3AxisSweep::hkpBpNode *v127; // rdx
  unsigned __int16 v128; // cx
  unsigned __int16 v129; // ax
  _DWORD *v130; // rcx
  __int64 v131; // rdx
  int v132; // eax
  __int64 v133; // rbp
  signed __int64 v134; // rsi
  unsigned int v135; // er9
  _DWORD *v136; // r8
  signed __int64 v137; // rcx
  hkp3AxisSweep::hkpBpNode *v138; // rdx
  unsigned __int16 v139; // cx
  unsigned __int16 v140; // ax
  signed __int64 v141; // rcx
  __int64 v142; // rdx
  int v143; // eax
  unsigned int v144; // [rsp+30h] [rbp-108h]
  unsigned int v145; // [rsp+50h] [rbp-E8h]
  __int16 v146; // [rsp+60h] [rbp-D8h]
  __int16 v147; // [rsp+64h] [rbp-D4h]
  __int64 v148; // [rsp+80h] [rbp-B8h]
  __int64 v149; // [rsp+90h] [rbp-A8h]
  unsigned int v150; // [rsp+B0h] [rbp-88h]
  hkpBroadPhaseHandle **v151; // [rsp+B8h] [rbp-80h]
  hkpBroadPhaseHandle **i; // [rsp+C0h] [rbp-78h]
  hkp3AxisSweep *v153; // [rsp+140h] [rbp+8h]
  unsigned int v154; // [rsp+148h] [rbp+10h]
  hkAabb *v155; // [rsp+150h] [rbp+18h]

  v155 = aabbs;
  v153 = this;
  v151 = objects;
  v6 = this;
  for ( i = &objects[numObjects]; objects < i; v151 = objects )
  {
    v7 = v153;
    v8 = v153->m_nodes.m_data;
    v9 = _mm_max_ps(
           _mm_min_ps(
             _mm_mul_ps(_mm_add_ps(aabbs->m_min.m_quad, v6->m_offsetLow.m_quad), v6->m_scale.m_quad),
             hkp3AxisSweep::MaxVal),
           (__m128)0i64);
    v10 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v9),
              _mm_cvttps_epi32(v9)),
            (__m128i)_xmm);
    v11 = _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(aabbs->m_max.m_quad, v6->m_offsetHigh.m_quad), v6->m_scale.m_quad),
            hkp3AxisSweep::MaxVal);
    v148 = (unsigned __int128)_mm_add_epi16(
                                _mm_packs_epi32(v10, v10),
                                (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
    v12 = v148 & 0xFFFE;
    v13 = _mm_max_ps(v11, (__m128)0i64);
    v154 = WORD1(v148) & 0xFFFE;
    v147 = WORD1(v148) & 0xFFFE;
    v145 = WORD2(v148) & 0xFFFE;
    v14 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v13),
              _mm_cvttps_epi32(v13)),
            (__m128i)_xmm);
    v146 = v148 & 0xFFFE;
    v149 = (unsigned __int128)_mm_add_epi16(
                                _mm_packs_epi32(v14, v14),
                                (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
    v15 = (unsigned __int16)v149 | 1;
    v150 = WORD2(v149) | 1;
    v16 = (*objects)->m_id;
    v17 = WORD1(v149) | 1;
    v18 = v8[v16].min_x;
    v19 = &v8[v16];
    v20 = (signed __int64)&v153->m_axis[0].m_endPoints.m_data[v18];
    v144 = (*objects)->m_id;
    v21 = *(unsigned __int16 *)(v20 - 4);
    v22 = (_DWORD *)(v20 - 4);
    if ( v12 < v21 )
    {
      do
      {
        v23 = *(unsigned __int16 *)(v20 - 2);
        *(_DWORD *)v20 = *v22;
        v20 = (signed __int64)v22;
        v24 = (signed __int64)&v8[v23];
        if ( v21 & 1 )
        {
          v25 = *(_DWORD *)(v24 + 4) - *(_DWORD *)&v19->min_y;
          v26 = *(_DWORD *)&v19->max_y - *(_DWORD *)v24;
          *(_WORD *)(v24 + 10) = v18;
          if ( !((v26 | v25) & 0x80008000) )
            hkp3AxisSweep::beginOverlapCheckMarker(
              v153->m_markers,
              &v8[v16],
              v16,
              (hkp3AxisSweep::hkpBpNode *)v24,
              addedPairsOut);
        }
        else
        {
          *(_WORD *)(v24 + 8) = v18;
        }
        v21 = *(unsigned __int16 *)(v20 - 4);
        v22 = (_DWORD *)(v20 - 4);
        LOWORD(v18) = v18 - 1;
      }
      while ( v12 < v21 );
      v15 = (unsigned __int16)v149 | 1;
      v17 = WORD1(v149) | 1;
      v7 = v153;
    }
    v27 = (_DWORD *)(v20 - 4);
    if ( v12 == *(unsigned __int16 *)(v20 - 4) )
    {
      do
      {
        v28 = *(unsigned __int16 *)(v20 - 2);
        if ( (unsigned int)v16 >= (unsigned int)v28 )
          break;
        *(_DWORD *)v20 = *v27;
        v20 = (signed __int64)v27;
        v8[v28].min_x = v18;
        v29 = *((unsigned __int16 *)v27 - 2);
        --v27;
        LOWORD(v18) = v18 - 1;
      }
      while ( v12 == v29 );
    }
    *(_WORD *)(v20 + 2) = v16;
    *(_WORD *)v20 = v146;
    v19->min_x = v18;
    v30 = v19->max_x;
    v31 = (signed __int64)&v7->m_axis[0].m_endPoints.m_data[v30];
    v32 = *(unsigned __int16 *)(v31 + 4);
    v33 = v31 + 4;
    if ( v15 > v32 )
    {
      do
      {
        LOWORD(v30) = v30 + 1;
        *(_DWORD *)v31 = *(_DWORD *)v33;
        v31 = v33;
        v34 = (signed __int64)&v8[*(unsigned __int16 *)(v33 + 2)];
        if ( v32 & 1 )
        {
          --*(_WORD *)(v34 + 10);
        }
        else
        {
          v35 = *(_DWORD *)&v19->max_y - *(_DWORD *)v34;
          v36 = *(_DWORD *)(v34 + 4) - *(_DWORD *)&v19->min_y;
          --*(_WORD *)(v34 + 8);
          if ( !((v36 | v35) & 0x80008000) )
            hkp3AxisSweep::beginOverlapCheckMarker(
              v153->m_markers,
              &v8[v16],
              v16,
              (hkp3AxisSweep::hkpBpNode *)v34,
              addedPairsOut);
        }
        v32 = *(unsigned __int16 *)(v31 + 4);
        v33 = v31 + 4;
      }
      while ( v15 > v32 );
      v12 = v148 & 0xFFFE;
      v17 = WORD1(v149) | 1;
      v7 = v153;
    }
    v37 = v31 + 4;
    if ( v15 == *(unsigned __int16 *)(v31 + 4) )
    {
      do
      {
        v38 = *(unsigned __int16 *)(v31 + 6);
        if ( (unsigned int)v16 <= (unsigned int)v38 )
          break;
        if ( !*(_WORD *)(v31 + 6) )
          break;
        LOWORD(v30) = v30 + 1;
        *(_DWORD *)v31 = *(_DWORD *)v37;
        --v8[v38].max_x;
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
        LOWORD(v30) = v30 - 1;
        *(_DWORD *)v31 = *v41;
        v42 = *(unsigned __int16 *)(v31 - 2);
        v31 = (signed __int64)v41;
        v43 = (signed __int64)&v8[v42];
        if ( v40 & 1 )
        {
          ++*(_WORD *)(v43 + 10);
        }
        else
        {
          v44 = *(_DWORD *)&v19->max_y - *(_DWORD *)v43;
          v45 = *(_DWORD *)(v43 + 4) - *(_DWORD *)&v19->min_y;
          ++*(_WORD *)(v43 + 8);
          if ( !((v45 | v44) & 0x80008000) )
            hkp3AxisSweep::endOverlapCheckMarker(
              v153->m_markers,
              &v8[v16],
              v16,
              (hkp3AxisSweep::hkpBpNode *)v43,
              removedPairsOut);
        }
        v40 = *(unsigned __int16 *)(v31 - 4);
        v41 = (_DWORD *)(v31 - 4);
      }
      while ( v15 < v40 );
      v12 = v148 & 0xFFFE;
      v17 = WORD1(v149) | 1;
      v7 = v153;
    }
    v46 = (_DWORD *)(v31 - 4);
    if ( v15 == *(unsigned __int16 *)(v31 - 4) )
    {
      do
      {
        v47 = *(unsigned __int16 *)(v31 - 2);
        if ( (unsigned int)v16 >= (unsigned int)v47 )
          break;
        LOWORD(v30) = v30 - 1;
        *(_DWORD *)v31 = *v46;
        v31 = (signed __int64)v46;
        ++v8[v47].max_x;
        v48 = *((unsigned __int16 *)v46 - 2);
        --v46;
      }
      while ( v15 == v48 );
    }
    v19->max_x = v30;
    *(_WORD *)(v31 + 2) = v16;
    *(_WORD *)v31 = v149 | 1;
    v49 = v19->min_x;
    v50 = (signed __int64)&v7->m_axis[0].m_endPoints.m_data[v49];
    v51 = *(unsigned __int16 *)(v50 + 4);
    v52 = (_DWORD *)(v50 + 4);
    if ( v12 > v51 )
    {
      do
      {
        LOWORD(v49) = v49 + 1;
        v53 = *(unsigned __int16 *)(v50 + 6);
        *(_DWORD *)v50 = *v52;
        v50 = (signed __int64)v52;
        v54 = (signed __int64)&v8[v53];
        if ( v51 & 1 )
        {
          v55 = *(_DWORD *)&v19->max_y - *(_DWORD *)v54;
          v56 = *(_DWORD *)(v54 + 4) - *(_DWORD *)&v19->min_y;
          --*(_WORD *)(v54 + 10);
          if ( !((v56 | v55) & 0x80008000) )
            hkp3AxisSweep::endOverlapCheckMarker(
              v153->m_markers,
              &v8[v16],
              v16,
              (hkp3AxisSweep::hkpBpNode *)v54,
              removedPairsOut);
        }
        else
        {
          --*(_WORD *)(v54 + 8);
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
        if ( (unsigned int)v16 <= (unsigned int)v58 )
          break;
        LOWORD(v49) = v49 + 1;
        *(_DWORD *)v50 = *(_DWORD *)v57;
        v50 = v57;
        --v8[v58].min_x;
        v59 = *(unsigned __int16 *)(v57 + 4);
        v57 += 4i64;
      }
      while ( v12 == v59 );
    }
    v6 = v153;
    v60 = WORD1(v148) & 0xFFFE;
    v19->min_x = v49;
    *(_WORD *)v50 = v146;
    *(_WORD *)(v50 + 2) = v16;
    v61 = v19->min_y;
    v62 = (signed __int64)&v153->m_axis[1].m_endPoints.m_data[v61];
    v63 = *(unsigned __int16 *)(v62 - 4);
    v64 = (_DWORD *)(v62 - 4);
    if ( v154 < v63 )
    {
      do
      {
        v65 = *(unsigned __int16 *)(v62 - 2);
        *(_DWORD *)v62 = *v64;
        v62 = (signed __int64)v64;
        v66 = &v8[v65];
        if ( v63 & 1 )
        {
          v67 = (v19->max_x - v66->min_x) | (v19->max_z - v66->min_z) | (v66->max_z - v19->min_z);
          v68 = v66->max_x - v19->min_x;
          v66->max_y = v61;
          if ( !((v68 | v67) & 0x8000) )
            hkp3AxisSweep::beginOverlap(v19, v66, addedPairsOut);
        }
        else
        {
          v66->min_y = v61;
        }
        v63 = *(unsigned __int16 *)(v62 - 4);
        v64 = (_DWORD *)(v62 - 4);
        LOWORD(v61) = v61 - 1;
      }
      while ( v154 < v63 );
      LODWORD(v16) = v144;
      v17 = WORD1(v149) | 1;
    }
    v69 = (_DWORD *)(v62 - 4);
    if ( v154 == *(unsigned __int16 *)(v62 - 4) )
    {
      do
      {
        v70 = *(unsigned __int16 *)(v62 - 2);
        if ( (unsigned int)v16 >= (unsigned int)v70 )
          break;
        *(_DWORD *)v62 = *v69;
        v62 = (signed __int64)v69;
        v8[v70].min_y = v61;
        v71 = *((unsigned __int16 *)v69 - 2);
        --v69;
        LOWORD(v61) = v61 - 1;
      }
      while ( v154 == v71 );
    }
    *(_WORD *)(v62 + 2) = v16;
    *(_WORD *)v62 = v147;
    v19->min_y = v61;
    v72 = v19->max_y;
    v73 = (signed __int64)&v153->m_axis[1].m_endPoints.m_data[v72];
    v74 = *(unsigned __int16 *)(v73 + 4);
    v75 = v73 + 4;
    if ( v17 > v74 )
    {
      do
      {
        LOWORD(v72) = v72 + 1;
        *(_DWORD *)v73 = *(_DWORD *)v75;
        v73 = v75;
        v76 = &v8[*(unsigned __int16 *)(v75 + 2)];
        if ( v74 & 1 )
        {
          --v76->max_y;
        }
        else
        {
          v77 = (v19->max_x - v76->min_x) | (v19->max_z - v76->min_z) | (v76->max_z - v19->min_z);
          v78 = v76->max_x - v19->min_x;
          --v76->min_y;
          if ( !((v78 | v77) & 0x8000) )
            hkp3AxisSweep::beginOverlap(v19, v76, addedPairsOut);
        }
        v74 = *(unsigned __int16 *)(v73 + 4);
        v75 = v73 + 4;
      }
      while ( v17 > v74 );
      LODWORD(v16) = v144;
      v60 = WORD1(v148) & 0xFFFE;
      v6 = v153;
    }
    v79 = v73 + 4;
    if ( v17 == *(unsigned __int16 *)(v73 + 4) )
    {
      do
      {
        v80 = *(unsigned __int16 *)(v73 + 6);
        if ( (unsigned int)v16 <= (unsigned int)v80 )
          break;
        if ( !*(_WORD *)(v73 + 6) )
          break;
        LOWORD(v72) = v72 + 1;
        *(_DWORD *)v73 = *(_DWORD *)v79;
        --v8[v80].max_y;
        v81 = *(unsigned __int16 *)(v79 + 4);
        v73 = v79;
        v79 += 4i64;
      }
      while ( v17 == v81 );
      v60 = WORD1(v148) & 0xFFFE;
    }
    v82 = *(unsigned __int16 *)(v73 - 4);
    v83 = (_DWORD *)(v73 - 4);
    if ( v17 < v82 )
    {
      do
      {
        LOWORD(v72) = v72 - 1;
        *(_DWORD *)v73 = *v83;
        v84 = *(unsigned __int16 *)(v73 - 2);
        v73 = (signed __int64)v83;
        v85 = &v8[v84];
        if ( v82 & 1 )
        {
          ++v85->max_y;
        }
        else
        {
          v86 = (v19->max_x - v85->min_x) | (v19->max_z - v85->min_z) | (v85->max_z - v19->min_z);
          v87 = v85->max_x - v19->min_x;
          ++v85->min_y;
          if ( !((v87 | v86) & 0x8000) )
            hkp3AxisSweep::endOverlap(v19, v85, removedPairsOut);
        }
        v82 = *(unsigned __int16 *)(v73 - 4);
        v83 = (_DWORD *)(v73 - 4);
      }
      while ( v17 < v82 );
      v60 = WORD1(v148) & 0xFFFE;
      v6 = v153;
    }
    v88 = (_DWORD *)(v73 - 4);
    if ( v17 == *(unsigned __int16 *)(v73 - 4) )
    {
      do
      {
        v89 = *(unsigned __int16 *)(v73 - 2);
        if ( (unsigned int)v16 >= (unsigned int)v89 )
          break;
        LOWORD(v72) = v72 - 1;
        *(_DWORD *)v73 = *v88;
        v73 = (signed __int64)v88;
        ++v8[v89].max_y;
        v90 = *((unsigned __int16 *)v88 - 2);
        --v88;
      }
      while ( v17 == v90 );
    }
    v19->max_y = v72;
    *(_WORD *)(v73 + 2) = v16;
    *(_WORD *)v73 = WORD1(v149) | 1;
    v91 = v19->min_y;
    v92 = (signed __int64)&v6->m_axis[1].m_endPoints.m_data[v91];
    v93 = *(unsigned __int16 *)(v92 + 4);
    v94 = (_DWORD *)(v92 + 4);
    if ( v60 > v93 )
    {
      do
      {
        LOWORD(v91) = v91 + 1;
        v95 = *(unsigned __int16 *)(v92 + 6);
        *(_DWORD *)v92 = *v94;
        v92 = (signed __int64)v94;
        v96 = &v8[v95];
        if ( v93 & 1 )
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
      LODWORD(v16) = v144;
      v6 = v153;
    }
    v99 = v92 + 4;
    if ( v60 == *(unsigned __int16 *)(v92 + 4) )
    {
      do
      {
        v100 = *(unsigned __int16 *)(v92 + 6);
        if ( (unsigned int)v16 <= (unsigned int)v100 )
          break;
        LOWORD(v91) = v91 + 1;
        *(_DWORD *)v92 = *(_DWORD *)v99;
        v92 = v99;
        --v8[v100].min_y;
        v101 = *(unsigned __int16 *)(v99 + 4);
        v99 += 4i64;
      }
      while ( v60 == v101 );
      v6 = v153;
    }
    v19->min_y = v91;
    *(_WORD *)v92 = v147;
    *(_WORD *)(v92 + 2) = v16;
    v102 = v19->min_z;
    v103 = (signed __int64)&v6->m_axis[2].m_endPoints.m_data[v102];
    v104 = *(unsigned __int16 *)(v103 - 4);
    v105 = (_DWORD *)(v103 - 4);
    if ( v145 < v104 )
    {
      do
      {
        v106 = *(unsigned __int16 *)(v103 - 2);
        *(_DWORD *)v103 = *v105;
        v103 = (signed __int64)v105;
        v107 = &v8[v106];
        if ( v104 & 1 )
        {
          v108 = (v107->max_x - v19->min_x) | (v107->max_y - v19->min_y) | (v19->max_x - v107->min_x);
          v109 = v19->max_y - v107->min_y;
          v107->max_z = v102;
          if ( !((v109 | v108) & 0x8000) )
            hkp3AxisSweep::beginOverlap(v19, v107, addedPairsOut);
        }
        else
        {
          v107->min_z = v102;
        }
        v104 = *(unsigned __int16 *)(v103 - 4);
        v105 = (_DWORD *)(v103 - 4);
        LOWORD(v102) = v102 - 1;
      }
      while ( v145 < v104 );
      LODWORD(v16) = v144;
      v6 = v153;
    }
    v110 = (_DWORD *)(v103 - 4);
    if ( v145 == *(unsigned __int16 *)(v103 - 4) )
    {
      do
      {
        v111 = *(unsigned __int16 *)(v103 - 2);
        if ( (unsigned int)v16 >= (unsigned int)v111 )
          break;
        *(_DWORD *)v103 = *v110;
        v103 = (signed __int64)v110;
        v8[v111].min_z = v102;
        v112 = *((unsigned __int16 *)v110 - 2);
        --v110;
        LOWORD(v102) = v102 - 1;
      }
      while ( v145 == v112 );
    }
    v113 = WORD2(v148) & 0xFFFE;
    *(_WORD *)(v103 + 2) = v16;
    *(_WORD *)v103 = WORD2(v148) & 0xFFFE;
    v19->min_z = v102;
    v114 = v19->max_z;
    v115 = (signed __int64)&v6->m_axis[2].m_endPoints.m_data[v114];
    v116 = *(unsigned __int16 *)(v115 + 4);
    v117 = v115 + 4;
    if ( v150 > v116 )
    {
      do
      {
        LOWORD(v114) = v114 + 1;
        *(_DWORD *)v115 = *(_DWORD *)v117;
        v115 = v117;
        v118 = &v8[*(unsigned __int16 *)(v117 + 2)];
        if ( v116 & 1 )
        {
          --v118->max_z;
        }
        else
        {
          v119 = (v118->max_x - v19->min_x) | (v118->max_y - v19->min_y) | (v19->max_x - v118->min_x);
          v120 = v19->max_y - v118->min_y;
          --v118->min_z;
          if ( !((v120 | v119) & 0x8000) )
            hkp3AxisSweep::beginOverlap(v19, v118, addedPairsOut);
        }
        v116 = *(unsigned __int16 *)(v115 + 4);
        v117 = v115 + 4;
      }
      while ( v150 > v116 );
      LODWORD(v16) = v144;
      v6 = v153;
      v113 = WORD2(v148) & 0xFFFE;
    }
    v121 = v115 + 4;
    if ( v150 == *(unsigned __int16 *)(v115 + 4) )
    {
      do
      {
        v122 = *(unsigned __int16 *)(v115 + 6);
        if ( (unsigned int)v16 <= (unsigned int)v122 )
          break;
        if ( !*(_WORD *)(v115 + 6) )
          break;
        LOWORD(v114) = v114 + 1;
        *(_DWORD *)v115 = *(_DWORD *)v121;
        --v8[v122].max_z;
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
        LOWORD(v114) = v114 - 1;
        *(_DWORD *)v115 = *v125;
        v126 = *(unsigned __int16 *)(v115 - 2);
        v115 = (signed __int64)v125;
        v127 = &v8[v126];
        if ( v124 & 1 )
        {
          ++v127->max_z;
        }
        else
        {
          v128 = (v127->max_x - v19->min_x) | (v127->max_y - v19->min_y) | (v19->max_x - v127->min_x);
          v129 = v19->max_y - v127->min_y;
          ++v127->min_z;
          if ( !((v129 | v128) & 0x8000) )
            hkp3AxisSweep::endOverlap(v19, v127, removedPairsOut);
        }
        v124 = *(unsigned __int16 *)(v115 - 4);
        v125 = (_DWORD *)(v115 - 4);
      }
      while ( v150 < v124 );
      v6 = v153;
      v113 = WORD2(v148) & 0xFFFE;
    }
    v130 = (_DWORD *)(v115 - 4);
    if ( v150 == *(unsigned __int16 *)(v115 - 4) )
    {
      do
      {
        v131 = *(unsigned __int16 *)(v115 - 2);
        if ( (unsigned int)v16 >= (unsigned int)v131 )
          break;
        LOWORD(v114) = v114 - 1;
        *(_DWORD *)v115 = *v130;
        v115 = (signed __int64)v130;
        ++v8[v131].max_z;
        v132 = *((unsigned __int16 *)v130 - 2);
        --v130;
      }
      while ( v150 == v132 );
    }
    v19->max_z = v114;
    *(_WORD *)v115 = WORD2(v149) | 1;
    *(_WORD *)(v115 + 2) = v16;
    v133 = v19->min_z;
    v134 = (signed __int64)&v6->m_axis[2].m_endPoints.m_data[v133];
    v135 = *(unsigned __int16 *)(v134 + 4);
    v136 = (_DWORD *)(v134 + 4);
    if ( v145 > v135 )
    {
      do
      {
        LOWORD(v133) = v133 + 1;
        v137 = *(unsigned __int16 *)(v134 + 6);
        *(_DWORD *)v134 = *v136;
        v134 = (signed __int64)v136;
        v138 = &v8[v137];
        if ( v135 & 1 )
        {
          v139 = (v138->max_x - v19->min_x) | (v138->max_y - v19->min_y) | (v19->max_x - v138->min_x);
          v140 = v19->max_y - v138->min_y;
          --v138->max_z;
          if ( !((v140 | v139) & 0x8000) )
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
      LODWORD(v16) = v144;
      v6 = v153;
      v113 = WORD2(v148) & 0xFFFE;
    }
    v141 = v134 + 4;
    if ( v145 == *(unsigned __int16 *)(v134 + 4) )
    {
      do
      {
        v142 = *(unsigned __int16 *)(v134 + 6);
        if ( (unsigned int)v16 <= (unsigned int)v142 )
          break;
        LOWORD(v133) = v133 + 1;
        *(_DWORD *)v134 = *(_DWORD *)v141;
        v134 = v141;
        --v8[v142].min_z;
        v143 = *(unsigned __int16 *)(v141 + 4);
        v141 += 4i64;
      }
      while ( v145 == v143 );
      v113 = WORD2(v148) & 0xFFFE;
    }
    v19->min_z = v133;
    objects = v151 + 1;
    aabbs = v155 + 1;
    *(_WORD *)(v134 + 2) = v16;
    *(_WORD *)v134 = v113;
    ++v155;
  }
}_int16 *)(v134 + 4);
        v136 = (_DWORD *)(v134 + 4);
      }
      while ( v145 > v135 );
      LODWORD(v16) = v144;
      v6 = v153;
      v113 = WORD2(v148) & 0xFFFE;
    }
    v141 = v134 + 4;
    if ( v145 == *(unsigned __int16 *)(v134 + 4) )
    {
      do
      {
        v142 = *(unsigned __int16 *)(v134 + 6);
        if ( (unsigned int)v16 <= (unsigned int)

// File Line: 708
// RVA: 0xCFFFA0
void __fastcall hkp3AxisSweep::updateAabbsUint32(hkp3AxisSweep *this, hkpBroadPhaseHandle **objects, hkAabbUint32 *aabbs, int numObjects, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *addedPairsOut, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *removedPairsOut)
{
  hkpBroadPhaseHandle **v6; // r11
  hkp3AxisSweep *v7; // r10
  unsigned int v8; // ebp
  unsigned int v9; // edx
  unsigned int v10; // ebp
  unsigned int v11; // er13
  unsigned int v12; // er13
  unsigned int v13; // ecx
  hkp3AxisSweep::hkpBpNode *v14; // r14
  unsigned int v15; // er12
  __int64 v16; // r15
  __int64 v17; // rsi
  hkp3AxisSweep::hkpBpNode *v18; // rbx
  signed __int64 v19; // rdi
  unsigned int v20; // er9
  _DWORD *v21; // r8
  signed __int64 v22; // rcx
  signed __int64 v23; // rdx
  int v24; // ecx
  int v25; // eax
  _DWORD *v26; // rcx
  __int64 v27; // rdx
  int v28; // eax
  __int64 v29; // rsi
  signed __int64 v30; // rdi
  unsigned int v31; // er8
  signed __int64 i; // rcx
  signed __int64 v33; // rdx
  int v34; // ecx
  signed __int64 v35; // rdx
  __int64 v36; // rcx
  int v37; // eax
  unsigned int v38; // er9
  _DWORD *j; // r8
  __int64 v40; // rax
  signed __int64 v41; // rdx
  int v42; // ecx
  int v43; // eax
  _DWORD *v44; // rdx
  __int64 v45; // rcx
  int v46; // eax
  hkp3AxisSweep *v47; // r10
  __int64 v48; // rsi
  signed __int64 v49; // rdi
  unsigned int v50; // er9
  _DWORD *k; // r8
  signed __int64 v52; // rcx
  signed __int64 v53; // rdx
  int v54; // ecx
  signed __int64 v55; // rdx
  __int64 v56; // rcx
  int v57; // eax
  unsigned int v58; // er12
  __int64 v59; // rsi
  signed __int64 v60; // rdi
  unsigned int v61; // er9
  _DWORD *v62; // r8
  signed __int64 v63; // rcx
  hkp3AxisSweep::hkpBpNode *v64; // rdx
  unsigned __int16 v65; // cx
  unsigned __int16 v66; // ax
  _DWORD *v67; // rcx
  __int64 v68; // rdx
  int v69; // eax
  __int16 v70; // bp
  __int64 v71; // rsi
  signed __int64 v72; // rdi
  unsigned int v73; // er8
  signed __int64 v74; // rcx
  hkp3AxisSweep::hkpBpNode *v75; // rdx
  unsigned __int16 v76; // cx
  unsigned __int16 v77; // ax
  signed __int64 v78; // rdx
  __int64 v79; // rcx
  int v80; // eax
  unsigned int v81; // er9
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
  signed __int64 v92; // rdi
  unsigned int v93; // er9
  _DWORD *v94; // r8
  signed __int64 v95; // rcx
  hkp3AxisSweep::hkpBpNode *v96; // rdx
  __int16 v97; // cx
  __int16 v98; // ax
  signed __int64 v99; // rdx
  __int64 v100; // rcx
  int v101; // eax
  unsigned int v102; // er13
  __int64 v103; // rsi
  signed __int64 v104; // rdi
  unsigned int v105; // er9
  _DWORD *v106; // r8
  signed __int64 v107; // rcx
  hkp3AxisSweep::hkpBpNode *v108; // rdx
  __int16 v109; // cx
  __int16 v110; // ax
  _DWORD *v111; // rcx
  __int64 v112; // rdx
  int v113; // eax
  __int16 v114; // bp
  __int64 v115; // rsi
  signed __int64 v116; // rdi
  unsigned int v117; // er8
  signed __int64 v118; // rcx
  hkp3AxisSweep::hkpBpNode *v119; // rdx
  unsigned __int16 v120; // cx
  unsigned __int16 v121; // ax
  signed __int64 v122; // rdx
  __int64 v123; // rcx
  int v124; // eax
  unsigned int v125; // er9
  _DWORD *v126; // r8
  __int64 v127; // rax
  hkp3AxisSweep::hkpBpNode *v128; // rdx
  unsigned __int16 v129; // cx
  unsigned __int16 v130; // ax
  _DWORD *v131; // rdx
  __int64 v132; // rcx
  int v133; // eax
  __int64 v134; // rsi
  signed __int64 v135; // rdi
  unsigned int v136; // er9
  _DWORD *v137; // r8
  signed __int64 v138; // rcx
  hkp3AxisSweep::hkpBpNode *v139; // rdx
  __int16 v140; // cx
  __int16 v141; // ax
  signed __int64 v142; // rcx
  __int64 v143; // rdx
  int v144; // eax
  unsigned int v145; // [rsp+30h] [rbp-C8h]
  unsigned int v146; // [rsp+50h] [rbp-A8h]
  __int16 v147; // [rsp+60h] [rbp-98h]
  __int16 v148; // [rsp+64h] [rbp-94h]
  __int16 v149; // [rsp+68h] [rbp-90h]
  __int16 v150; // [rsp+78h] [rbp-80h]
  unsigned int v151; // [rsp+80h] [rbp-78h]
  hkpBroadPhaseHandle **v152; // [rsp+A0h] [rbp-58h]
  hkpBroadPhaseHandle **v153; // [rsp+A8h] [rbp-50h]
  hkp3AxisSweep *v154; // [rsp+100h] [rbp+8h]
  unsigned int v155; // [rsp+108h] [rbp+10h]
  hkAabbUint32 *v156; // [rsp+110h] [rbp+18h]

  v156 = aabbs;
  v154 = this;
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
      v14 = v7->m_nodes.m_data;
      v15 = (aabbs->m_min[0] >> 15) & 0xFFFE;
      v155 = (aabbs->m_min[1] >> 15) & 0xFFFE;
      v148 = (aabbs->m_min[1] >> 15) & 0xFFFE;
      v16 = (*v6)->m_id;
      v147 = (aabbs->m_min[0] >> 15) & 0xFFFE;
      v17 = v14[v16].min_x;
      v18 = &v14[v16];
      v19 = (signed __int64)&v7->m_axis[0].m_endPoints.m_data[v17];
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
          v19 = (signed __int64)v21;
          v23 = (signed __int64)&v14[v22];
          if ( v20 & 1 )
          {
            v24 = *(_DWORD *)&v18->max_y - *(_DWORD *)v23;
            v25 = *(_DWORD *)(v23 + 4) - *(_DWORD *)&v18->min_y;
            *(_WORD *)(v23 + 10) = v17;
            if ( !((v25 | v24) & 0x80008000) )
              hkp3AxisSweep::beginOverlapCheckMarker(
                v154->m_markers,
                &v14[v16],
                v16,
                (hkp3AxisSweep::hkpBpNode *)v23,
                addedPairsOut);
          }
          else
          {
            *(_WORD *)(v23 + 8) = v17;
          }
          v20 = *(unsigned __int16 *)(v19 - 4);
          v21 = (_DWORD *)(v19 - 4);
          LOWORD(v17) = v17 - 1;
        }
        while ( v15 < v20 );
        v7 = v154;
      }
      v26 = (_DWORD *)(v19 - 4);
      if ( v15 == *(unsigned __int16 *)(v19 - 4) )
      {
        do
        {
          v27 = *(unsigned __int16 *)(v19 - 2);
          if ( (unsigned int)v16 >= (unsigned int)v27 )
            break;
          *(_DWORD *)v19 = *v26;
          v19 = (signed __int64)v26;
          v14[v27].min_x = v17;
          v28 = *((unsigned __int16 *)v26 - 2);
          --v26;
          LOWORD(v17) = v17 - 1;
        }
        while ( v15 == v28 );
      }
      *(_WORD *)(v19 + 2) = v16;
      *(_WORD *)v19 = v15;
      v18->min_x = v17;
      v29 = v18->max_x;
      v30 = (signed __int64)&v7->m_axis[0].m_endPoints.m_data[v29];
      v31 = *(unsigned __int16 *)(v30 + 4);
      for ( i = v30 + 4; v10 > v31; i = v30 + 4 )
      {
        LOWORD(v29) = v29 + 1;
        *(_DWORD *)v30 = *(_DWORD *)i;
        v30 = i;
        v33 = (signed __int64)&v14[*(unsigned __int16 *)(i + 2)];
        if ( v31 & 1 )
        {
          --*(_WORD *)(v33 + 10);
        }
        else
        {
          v34 = (*(_DWORD *)(v33 + 4) - *(_DWORD *)&v18->min_y) | (*(_DWORD *)&v18->max_y - *(_DWORD *)v33);
          --*(_WORD *)(v33 + 8);
          if ( !(v34 & 0x80008000) )
            hkp3AxisSweep::beginOverlapCheckMarker(
              v154->m_markers,
              &v14[v16],
              v16,
              (hkp3AxisSweep::hkpBpNode *)v33,
              addedPairsOut);
        }
        v31 = *(unsigned __int16 *)(v30 + 4);
      }
      v35 = v30 + 4;
      if ( v10 == *(unsigned __int16 *)(v30 + 4) )
      {
        do
        {
          v36 = *(unsigned __int16 *)(v30 + 6);
          if ( (unsigned int)v16 <= (unsigned int)v36 )
            break;
          if ( !*(_WORD *)(v30 + 6) )
            break;
          LOWORD(v29) = v29 + 1;
          *(_DWORD *)v30 = *(_DWORD *)v35;
          --v14[v36].max_x;
          v37 = *(unsigned __int16 *)(v35 + 4);
          v30 = v35;
          v35 += 4i64;
        }
        while ( v10 == v37 );
      }
      v38 = *(unsigned __int16 *)(v30 - 4);
      for ( j = (_DWORD *)(v30 - 4); v10 < v38; j = (_DWORD *)(v30 - 4) )
      {
        LOWORD(v29) = v29 - 1;
        *(_DWORD *)v30 = *j;
        v40 = *(unsigned __int16 *)(v30 - 2);
        v30 = (signed __int64)j;
        v41 = (signed __int64)&v14[v40];
        if ( v38 & 1 )
        {
          ++*(_WORD *)(v41 + 10);
        }
        else
        {
          v42 = *(_DWORD *)&v18->max_y - *(_DWORD *)v41;
          v43 = *(_DWORD *)(v41 + 4) - *(_DWORD *)&v18->min_y;
          ++*(_WORD *)(v41 + 8);
          if ( !((v43 | v42) & 0x80008000) )
            hkp3AxisSweep::endOverlapCheckMarker(
              v154->m_markers,
              &v14[v16],
              v16,
              (hkp3AxisSweep::hkpBpNode *)v41,
              removedPairsOut);
        }
        v38 = *(unsigned __int16 *)(v30 - 4);
      }
      v44 = (_DWORD *)(v30 - 4);
      if ( v10 == *(unsigned __int16 *)(v30 - 4) )
      {
        do
        {
          v45 = *(unsigned __int16 *)(v30 - 2);
          if ( (unsigned int)v16 >= (unsigned int)v45 )
            break;
          LOWORD(v29) = v29 - 1;
          *(_DWORD *)v30 = *v44;
          ++v14[v45].max_x;
          v46 = *((unsigned __int16 *)v44 - 2);
          v30 = (signed __int64)v44;
          --v44;
        }
        while ( v10 == v46 );
      }
      v47 = v154;
      v18->max_x = v29;
      *(_WORD *)v30 = v10;
      *(_WORD *)(v30 + 2) = v16;
      v48 = v18->min_x;
      v49 = (signed __int64)&v154->m_axis[0].m_endPoints.m_data[v48];
      v50 = *(unsigned __int16 *)(v49 + 4);
      for ( k = (_DWORD *)(v49 + 4); v15 > v50; k = (_DWORD *)(v49 + 4) )
      {
        LOWORD(v48) = v48 + 1;
        v52 = *(unsigned __int16 *)(v49 + 6);
        *(_DWORD *)v49 = *k;
        v49 = (signed __int64)k;
        v53 = (signed __int64)&v14[v52];
        if ( v50 & 1 )
        {
          v54 = (*(_DWORD *)(v53 + 4) - *(_DWORD *)&v18->min_y) | (*(_DWORD *)&v18->max_y - *(_DWORD *)v53);
          --*(_WORD *)(v53 + 10);
          if ( !(v54 & 0x80008000) )
          {
            hkp3AxisSweep::endOverlapCheckMarker(
              v47->m_markers,
              &v14[v16],
              v16,
              (hkp3AxisSweep::hkpBpNode *)v53,
              removedPairsOut);
            v47 = v154;
          }
        }
        else
        {
          --*(_WORD *)(v53 + 8);
        }
        v50 = *(unsigned __int16 *)(v49 + 4);
      }
      v55 = v49 + 4;
      if ( v15 == *(unsigned __int16 *)(v49 + 4) )
      {
        do
        {
          v56 = *(unsigned __int16 *)(v49 + 6);
          if ( (unsigned int)v16 <= (unsigned int)v56 )
            break;
          LOWORD(v48) = v48 + 1;
          *(_DWORD *)v49 = *(_DWORD *)v55;
          --v14[v56].min_x;
          v57 = *(unsigned __int16 *)(v55 + 4);
          v49 = v55;
          v55 += 4i64;
        }
        while ( v15 == v57 );
      }
      v58 = v155;
      v18->min_x = v48;
      *(_WORD *)v49 = v147;
      *(_WORD *)(v49 + 2) = v16;
      v59 = v18->min_y;
      v60 = (signed __int64)&v47->m_axis[1].m_endPoints.m_data[v59];
      v61 = *(unsigned __int16 *)(v60 - 4);
      v62 = (_DWORD *)(v60 - 4);
      if ( v155 < v61 )
      {
        do
        {
          v63 = *(unsigned __int16 *)(v60 - 2);
          *(_DWORD *)v60 = *v62;
          v60 = (signed __int64)v62;
          v64 = &v14[v63];
          if ( v61 & 1 )
          {
            v65 = (v18->max_x - v64->min_x) | (v18->max_z - v64->min_z) | (v64->max_z - v18->min_z);
            v66 = v64->max_x - v18->min_x;
            v64->max_y = v59;
            if ( !((v66 | v65) & 0x8000) )
              hkp3AxisSweep::beginOverlap(v18, v64, addedPairsOut);
          }
          else
          {
            v64->min_y = v59;
          }
          v61 = *(unsigned __int16 *)(v60 - 4);
          v62 = (_DWORD *)(v60 - 4);
          LOWORD(v59) = v59 - 1;
        }
        while ( v155 < v61 );
        LODWORD(v16) = v146;
        v47 = v154;
      }
      v67 = (_DWORD *)(v60 - 4);
      if ( v155 == *(unsigned __int16 *)(v60 - 4) )
      {
        do
        {
          v68 = *(unsigned __int16 *)(v60 - 2);
          if ( (unsigned int)v16 >= (unsigned int)v68 )
            break;
          *(_DWORD *)v60 = *v67;
          v60 = (signed __int64)v67;
          v14[v68].min_y = v59;
          v69 = *((unsigned __int16 *)v67 - 2);
          --v67;
          LOWORD(v59) = v59 - 1;
        }
        while ( v155 == v69 );
      }
      v70 = v148;
      *(_WORD *)(v60 + 2) = v16;
      *(_WORD *)v60 = v148;
      v18->min_y = v59;
      v71 = v18->max_y;
      v72 = (signed __int64)&v47->m_axis[1].m_endPoints.m_data[v71];
      v73 = *(unsigned __int16 *)(v72 + 4);
      v74 = v72 + 4;
      if ( v12 > v73 )
      {
        do
        {
          LOWORD(v71) = v71 + 1;
          *(_DWORD *)v72 = *(_DWORD *)v74;
          v72 = v74;
          v75 = &v14[*(unsigned __int16 *)(v74 + 2)];
          if ( v73 & 1 )
          {
            --v75->max_y;
          }
          else
          {
            v76 = (v18->max_x - v75->min_x) | (v18->max_z - v75->min_z) | (v75->max_z - v18->min_z);
            v77 = v75->max_x - v18->min_x;
            --v75->min_y;
            if ( !((v77 | v76) & 0x8000) )
              hkp3AxisSweep::beginOverlap(v18, v75, addedPairsOut);
          }
          v73 = *(unsigned __int16 *)(v72 + 4);
          v74 = v72 + 4;
        }
        while ( v12 > v73 );
        LODWORD(v16) = v146;
        v70 = v148;
        v58 = v155;
      }
      v78 = v72 + 4;
      if ( v12 == *(unsigned __int16 *)(v72 + 4) )
      {
        do
        {
          v79 = *(unsigned __int16 *)(v72 + 6);
          if ( (unsigned int)v16 <= (unsigned int)v79 )
            break;
          if ( !*(_WORD *)(v72 + 6) )
            break;
          LOWORD(v71) = v71 + 1;
          *(_DWORD *)v72 = *(_DWORD *)v78;
          --v14[v79].max_y;
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
          LOWORD(v71) = v71 - 1;
          *(_DWORD *)v72 = *v82;
          v83 = *(unsigned __int16 *)(v72 - 2);
          v72 = (signed __int64)v82;
          v84 = &v14[v83];
          if ( v81 & 1 )
          {
            ++v84->max_y;
          }
          else
          {
            v85 = (v18->max_x - v84->min_x) | (v18->max_z - v84->min_z) | (v84->max_z - v18->min_z);
            v86 = v84->max_x - v18->min_x;
            ++v84->min_y;
            if ( !((v86 | v85) & 0x8000) )
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
          if ( (unsigned int)v16 >= (unsigned int)v88 )
            break;
          LOWORD(v71) = v71 - 1;
          *(_DWORD *)v72 = *v87;
          ++v14[v88].max_y;
          v89 = *((unsigned __int16 *)v87 - 2);
          v72 = (signed __int64)v87;
          --v87;
        }
        while ( v12 == v89 );
      }
      v90 = v154;
      v18->max_y = v71;
      *(_WORD *)v72 = v12;
      *(_WORD *)(v72 + 2) = v16;
      v91 = v18->min_y;
      v92 = (signed __int64)&v154->m_axis[1].m_endPoints.m_data[v91];
      v93 = *(unsigned __int16 *)(v92 + 4);
      v94 = (_DWORD *)(v92 + 4);
      if ( v58 > v93 )
      {
        do
        {
          LOWORD(v91) = v91 + 1;
          v95 = *(unsigned __int16 *)(v92 + 6);
          *(_DWORD *)v92 = *v94;
          v92 = (signed __int64)v94;
          v96 = &v14[v95];
          if ( v93 & 1 )
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
          v93 = *(unsigned __int16 *)(v92 + 4);
          v94 = (_DWORD *)(v92 + 4);
        }
        while ( v58 > v93 );
        LODWORD(v16) = v146;
        v70 = v148;
        v90 = v154;
      }
      v99 = v92 + 4;
      if ( v58 == *(unsigned __int16 *)(v92 + 4) )
      {
        do
        {
          v100 = *(unsigned __int16 *)(v92 + 6);
          if ( (unsigned int)v16 <= (unsigned int)v100 )
            break;
          LOWORD(v91) = v91 + 1;
          *(_DWORD *)v92 = *(_DWORD *)v99;
          --v14[v100].min_y;
          v101 = *(unsigned __int16 *)(v99 + 4);
          v92 = v99;
          v99 += 4i64;
        }
        while ( v58 == v101 );
        v90 = v154;
      }
      v102 = v145;
      v18->min_y = v91;
      *(_WORD *)(v92 + 2) = v16;
      *(_WORD *)v92 = v70;
      v103 = v18->min_z;
      v104 = (signed __int64)&v90->m_axis[2].m_endPoints.m_data[v103];
      v105 = *(unsigned __int16 *)(v104 - 4);
      v106 = (_DWORD *)(v104 - 4);
      if ( v145 < v105 )
      {
        do
        {
          v107 = *(unsigned __int16 *)(v104 - 2);
          *(_DWORD *)v104 = *v106;
          v104 = (signed __int64)v106;
          v108 = &v14[v107];
          if ( v105 & 1 )
          {
            v109 = (v108->max_y - v18->min_y) | (v108->max_x - v18->min_x) | (v18->max_x - v108->min_x);
            v110 = v18->max_y - v108->min_y;
            v108->max_z = v103;
            if ( ((v110 | v109) & 0x8000u) == 0 )
              hkp3AxisSweep::beginOverlap(v18, v108, addedPairsOut);
          }
          else
          {
            v108->min_z = v103;
          }
          v105 = *(unsigned __int16 *)(v104 - 4);
          v106 = (_DWORD *)(v104 - 4);
          LOWORD(v103) = v103 - 1;
        }
        while ( v145 < v105 );
        LODWORD(v16) = v146;
        v90 = v154;
      }
      v111 = (_DWORD *)(v104 - 4);
      if ( v145 == *(unsigned __int16 *)(v104 - 4) )
      {
        do
        {
          v112 = *(unsigned __int16 *)(v104 - 2);
          if ( (unsigned int)v16 >= (unsigned int)v112 )
            break;
          *(_DWORD *)v104 = *v111;
          v104 = (signed __int64)v111;
          v14[v112].min_z = v103;
          v113 = *((unsigned __int16 *)v111 - 2);
          --v111;
          LOWORD(v103) = v103 - 1;
        }
        while ( v145 == v113 );
      }
      v114 = v149;
      *(_WORD *)(v104 + 2) = v16;
      *(_WORD *)v104 = v149;
      v18->min_z = v103;
      v115 = v18->max_z;
      v116 = (signed __int64)&v90->m_axis[2].m_endPoints.m_data[v115];
      v117 = *(unsigned __int16 *)(v116 + 4);
      v118 = v116 + 4;
      if ( v151 > v117 )
      {
        do
        {
          LOWORD(v115) = v115 + 1;
          *(_DWORD *)v116 = *(_DWORD *)v118;
          v116 = v118;
          v119 = &v14[*(unsigned __int16 *)(v118 + 2)];
          if ( v117 & 1 )
          {
            --v119->max_z;
          }
          else
          {
            v120 = (v119->max_y - v18->min_y) | (v119->max_x - v18->min_x) | (v18->max_x - v119->min_x);
            v121 = v18->max_y - v119->min_y;
            --v119->min_z;
            if ( !((v121 | v120) & 0x8000) )
              hkp3AxisSweep::beginOverlap(v18, v119, addedPairsOut);
          }
          v117 = *(unsigned __int16 *)(v116 + 4);
          v118 = v116 + 4;
        }
        while ( v151 > v117 );
        LODWORD(v16) = v146;
        v114 = v149;
        v102 = v145;
      }
      v122 = v116 + 4;
      if ( v151 == *(unsigned __int16 *)(v116 + 4) )
      {
        do
        {
          v123 = *(unsigned __int16 *)(v116 + 6);
          if ( (unsigned int)v16 <= (unsigned int)v123 )
            break;
          if ( !*(_WORD *)(v116 + 6) )
            break;
          LOWORD(v115) = v115 + 1;
          *(_DWORD *)v116 = *(_DWORD *)v122;
          --v14[v123].max_z;
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
          LOWORD(v115) = v115 - 1;
          *(_DWORD *)v116 = *v126;
          v127 = *(unsigned __int16 *)(v116 - 2);
          v116 = (signed __int64)v126;
          v128 = &v14[v127];
          if ( v125 & 1 )
          {
            ++v128->max_z;
          }
          else
          {
            v129 = (v128->max_y - v18->min_y) | (v128->max_x - v18->min_x) | (v18->max_x - v128->min_x);
            v130 = v18->max_y - v128->min_y;
            ++v128->min_z;
            if ( !((v130 | v129) & 0x8000) )
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
          if ( (unsigned int)v16 >= (unsigned int)v132 )
            break;
          LOWORD(v115) = v115 - 1;
          *(_DWORD *)v116 = *v131;
          ++v14[v132].max_z;
          v133 = *((unsigned __int16 *)v131 - 2);
          v116 = (signed __int64)v131;
          --v131;
        }
        while ( v151 == v133 );
      }
      v7 = v154;
      v18->max_z = v115;
      *(_WORD *)v116 = v150;
      *(_WORD *)(v116 + 2) = v16;
      v134 = v18->min_z;
      v135 = (signed __int64)&v154->m_axis[2].m_endPoints.m_data[v134];
      v136 = *(unsigned __int16 *)(v135 + 4);
      v137 = (_DWORD *)(v135 + 4);
      if ( v102 > v136 )
      {
        do
        {
          LOWORD(v134) = v134 + 1;
          v138 = *(unsigned __int16 *)(v135 + 6);
          *(_DWORD *)v135 = *v137;
          v135 = (signed __int64)v137;
          v139 = &v14[v138];
          if ( v136 & 1 )
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
          v136 = *(unsigned __int16 *)(v135 + 4);
          v137 = (_DWORD *)(v135 + 4);
        }
        while ( v102 > v136 );
        LODWORD(v16) = v146;
        v114 = v149;
        v7 = v154;
      }
      v142 = v135 + 4;
      if ( v102 == *(unsigned __int16 *)(v135 + 4) )
      {
        do
        {
          v143 = *(unsigned __int16 *)(v135 + 6);
          if ( (unsigned int)v16 <= (unsigned int)v143 )
            break;
          LOWORD(v134) = v134 + 1;
          *(_DWORD *)v135 = *(_DWORD *)v142;
          v135 = v142;
          --v14[v143].min_z;
          v144 = *(unsigned __int16 *)(v142 + 4);
          v142 += 4i64;
        }
        while ( v102 == v144 );
        v7 = v154;
      }
      v18->min_z = v134;
      v6 = v152 + 1;
      aabbs = v156 + 1;
      *(_WORD *)(v135 + 2) = v16;
      *(_WORD *)v135 = v114;
      ++v156;
      v152 = v6;
    }
    while ( v6 < v153 );
  }
};
        LODWORD(v16) = v146;
        v114 = v149;
        v7 = v154;
      }
      v142 = v135 + 4;
      if ( v102 == *(unsigned __int16 *)(v135 + 4) )
      {
        do
        {
          v143 = *(unsigned __int16 *)(v135 + 6);
          if ( (unsigned int)v16 <= (unsigned int)v143 )
            break;
          LOWORD(v134) = v134 + 1;
          *(_DWORD *)v135 = *(_DWORD *)v142;
          v135 = v142;
          --v14[v143].min_z;
          v144 = *(unsigned __int16 *)(v142 + 4);
          v142 += 4i64;
        }
        while ( v102 == v144 );
        v7 = v154;
      }
    

// File Line: 741
// RVA: 0xCFC350
void __usercall hkp3AxisSweep::hkp3AxisSweep(hkp3AxisSweep *this@<rcx>, hkVector4f *worldMin@<rdx>, hkVector4f *worldMax@<r8>, int numMarkers@<r9d>, __m128 a5@<xmm2>)
{
  int v5; // ebp
  hkVector4f *v6; // rdi
  hkVector4f *v7; // rbx
  hkp3AxisSweep *v8; // r14
  signed __int64 v9; // rsi
  signed __int64 v10; // r15
  signed int v11; // ebx
  int v12; // er9
  int v13; // eax
  int v14; // eax
  float v15; // xmm7_4
  signed __int64 v16; // rcx
  __m128i v17; // xmm13
  __m128i v18; // xmm14
  __m128 v19; // xmm4
  __m128 v20; // xmm5
  __m128 v21; // xmm3
  __m128 v22; // xmm3
  __m128i v23; // xmm1
  __int64 v24; // rcx
  _QWORD *v25; // rdx
  signed __int64 v26; // r12
  int v27; // er9
  int v28; // eax
  int v29; // eax
  signed __int64 v30; // r13
  int v31; // edi
  int v32; // eax
  int v33; // eax
  int v34; // er9
  hkp3AxisSweep::hkpBpAxis *v35; // rbp
  int v36; // eax
  int v37; // eax
  _DWORD *v38; // rdx
  _DWORD *v39; // r8
  hkp3AxisSweep::hkpBpEndPoint *v40; // r8
  hkMemoryAllocator **v41; // rax
  int v42; // edi
  signed __int64 v43; // r12
  hkp3AxisSweep::hkpBpMarker *v44; // r8
  unsigned __int16 v45; // dx
  int v46; // ecx
  unsigned __int16 v47; // bx
  int v48; // eax
  __int64 v49; // rcx
  _QWORD *v50; // r8
  hkResult *v51; // r9
  hkResult *v52; // r9
  _QWORD *v53; // rcx
  hkResult *v54; // rdx
  hkResultEnum v55; // eax
  hkResultEnum *v56; // r8
  hkResultEnum *v57; // r8
  signed int v58; // [rsp+120h] [rbp+8h]
  signed __int64 v59; // [rsp+128h] [rbp+10h]
  _QWORD *v60; // [rsp+130h] [rbp+18h]
  hkResult result; // [rsp+138h] [rbp+20h]

  v5 = numMarkers;
  v6 = worldMax;
  v7 = worldMin;
  v8 = this;
  hkpBroadPhase::hkpBroadPhase((hkpBroadPhase *)&this->vfptr, 0, 272, 4123);
  v9 = (signed __int64)v8->m_axis;
  v10 = (signed __int64)&v8->m_nodes;
  v8->vfptr = (hkBaseObjectVtbl *)&hkp3AxisSweep::`vftable';
  *(_QWORD *)v10 = 0i64;
  *(_DWORD *)(v10 + 8) = 0;
  *(_DWORD *)(v10 + 12) = 2147483648;
  *(_QWORD *)v9 = 0i64;
  *(_QWORD *)(v9 + 16) = 0i64;
  *(_DWORD *)(v9 + 8) = 0;
  *(_DWORD *)(v9 + 12) = 2147483648;
  *(_DWORD *)(v9 + 24) = 0;
  *(_DWORD *)(v9 + 28) = 2147483648;
  *(_QWORD *)(v9 + 32) = 0i64;
  *(_DWORD *)(v9 + 40) = 0;
  *(_DWORD *)(v9 + 44) = 2147483648;
  v8->m_aabb.m_min = (hkVector4f)v7->m_quad;
  if ( !v5 )
    v5 = 1;
  v11 = -1;
  for ( v8->m_aabb.m_max = (hkVector4f)v6->m_quad; v5 > 0; ++v11 )
    v5 >>= 1;
  v12 = 255;
  v13 = v8->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < 255 )
  {
    v14 = 2 * v13;
    if ( v14 > 255 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_nodes, v12, 24);
  }
  v15 = FLOAT_10_0;
  v8->m_scale = *(hkVector4f *)_xmm;
  v8->m_offsetLow = 0i64;
  v16 = 23i64;
  v8->m_offsetHigh = 0i64;
  v17 = _mm_load_si128((const __m128i *)&_xmm);
  v18 = _mm_load_si128((const __m128i *)&`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v19 = (__m128)LODWORD(FLOAT_11_0);
  do
  {
    v20 = v19;
    v20.m128_f32[0] = (float)(v19.m128_f32[0] + v15) * 0.5;
    v21 = v20;
    a5.m128_f32[0] = v20.m128_f32[0];
    v21.m128_f32[0] = v20.m128_f32[0] + 1.0;
    a5 = _mm_max_ps(
           _mm_min_ps(
             _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(a5, a5, 0), (__m128)0i64), *(__m128 *)_xmm),
             hkp3AxisSweep::MaxVal),
           (__m128)0i64);
    v22 = _mm_max_ps(
            _mm_min_ps(
              _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 0), (__m128)0i64), *(__m128 *)_xmm),
              hkp3AxisSweep::MaxVal),
            (__m128)0i64);
    v23 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v22),
              _mm_cvttps_epi32(v22)),
            v17);
    if ( ((unsigned __int16)*(_OWORD *)&_mm_add_epi16(_mm_packs_epi32(v23, v23), v18) | 1u) >= 0xC )
      v19 = v20;
    else
      v15 = (float)(v19.m128_f32[0] + v15) * 0.5;
    --v16;
  }
  while ( v16 );
  v8->m_scale = 0i64;
  v8->m_offsetLow = 0i64;
  v8->m_offsetHigh = 0i64;
  v8->m_intToFloatFloorCorrection = (float)((float)(v19.m128_f32[0] + v15) * 0.5) - 11.0;
  if ( v8->m_nodes.m_size == (v8->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_nodes, 24);
  v24 = v8->m_nodes.m_size;
  v25 = *(_QWORD **)v10;
  v26 = 3 * v24;
  v8->m_nodes.m_size = v24 + 1;
  LODWORD(v25[v26]) = 0;
  LOWORD(v25[v26 + 1]) = 0;
  v25[v26 + 2] = 0i64;
  v27 = 2 * (1 << v11) + 510;
  v58 = 1 << v11;
  v28 = v8->m_axis[0].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  v59 = 3 * v24;
  v60 = v25;
  if ( v28 < v27 )
  {
    v29 = 2 * v28;
    if ( v27 < v29 )
      v27 = v29;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8->m_axis, v27, 4);
  }
  v30 = (signed __int64)&v8->m_axis[1];
  v31 = 512;
  v32 = v8->m_axis[1].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v32 < 512 )
  {
    v33 = 2 * v32;
    v34 = 512;
    if ( v33 > 512 )
      v34 = v33;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_axis[1],
      v34,
      4);
  }
  v35 = &v8->m_axis[2];
  v36 = v8->m_axis[2].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v36 < 512 )
  {
    v37 = 2 * v36;
    if ( v37 > 512 )
      v31 = v37;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_axis[2],
      v31,
      4);
  }
  v38 = (_DWORD *)(*(_QWORD *)v9 + 4i64 * v8->m_axis[0].m_endPoints.m_size);
  result.m_enum = 0;
  if ( v38 )
    *v38 = 0;
  ++v8->m_axis[0].m_endPoints.m_size;
  v39 = (_DWORD *)(*(_QWORD *)v30 + 4i64 * v8->m_axis[1].m_endPoints.m_size);
  if ( v39 )
    *v39 = 0;
  ++v8->m_axis[1].m_endPoints.m_size;
  v40 = &v35->m_endPoints.m_data[v8->m_axis[2].m_endPoints.m_size];
  if ( v40 )
    *v40 = 0;
  ++v8->m_axis[2].m_endPoints.m_size;
  v8->m_ld2NumMarkers = v11;
  v8->m_markers = 0i64;
  v8->m_numMarkers = v58 - 1;
  if ( v58 != 1 )
  {
    v41 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8->m_markers = (hkp3AxisSweep::hkpBpMarker *)hkMemoryRouter::easyAlloc(v41[11], 24 * (v58 - 1));
  }
  v42 = 0;
  if ( v8->m_numMarkers > 0 )
  {
    do
    {
      v43 = v42;
      v44 = &v8->m_markers[v43];
      if ( v44 )
      {
        v44->m_overlappingObjects.m_data = 0i64;
        v44->m_overlappingObjects.m_size = 0;
        v44->m_overlappingObjects.m_capacityAndFlags = 2147483648;
      }
      else
      {
        v44 = 0i64;
      }
      v45 = v8->m_nodes.m_size;
      v46 = 16 - v8->m_ld2NumMarkers;
      v44->m_nodeIndex = v45;
      HIWORD(result.m_enum) = v45;
      v47 = ((_WORD)v42 + 1) << v46;
      v44->m_value = v47;
      v48 = v8->m_nodes.m_capacityAndFlags;
      LOWORD(result.m_enum) = ((_WORD)v42 + 1) << v46;
      if ( v8->m_nodes.m_size == (v48 & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_nodes, 24);
      v49 = v8->m_nodes.m_size;
      v50 = *(_QWORD **)v10;
      v8->m_nodes.m_size = v49 + 1;
      LOWORD(v50[3 * v49 + 1]) = v8->m_axis[0].m_endPoints.m_size;
      v51 = (hkResult *)(*(_QWORD *)v9 + 4i64 * v8->m_axis[0].m_endPoints.m_size);
      if ( v51 )
        v51->m_enum = result.m_enum;
      ++v8->m_axis[0].m_endPoints.m_size;
      WORD1(v50[3 * v49 + 1]) = v8->m_axis[0].m_endPoints.m_size;
      v52 = (hkResult *)(*(_QWORD *)v9 + 4i64 * v8->m_axis[0].m_endPoints.m_size);
      LOWORD(result.m_enum) = v47 | 1;
      if ( v52 )
        v52->m_enum = result.m_enum;
      ++v8->m_axis[0].m_endPoints.m_size;
      ++v42;
      LODWORD(v50[3 * v49]) = 0;
      HIDWORD(v50[3 * v49]) = 65537;
      v50[3 * v49 + 2] = v43 * 24 | 1;
    }
    while ( v42 < v8->m_numMarkers );
    v26 = v59;
    v30 = (signed __int64)&v8->m_axis[1];
  }
  v53 = *(_QWORD **)v10;
  result.m_enum = 65533;
  v60[v26] = *v53;
  v60[v26 + 1] = v53[1];
  v60[v26 + 2] = v53[2];
  WORD1(v60[v26 + 1]) = v8->m_axis[0].m_endPoints.m_size;
  WORD2(v60[v26]) = v8->m_axis[1].m_endPoints.m_size;
  HIWORD(v60[v26]) = v8->m_axis[2].m_endPoints.m_size;
  v54 = (hkResult *)(*(_QWORD *)v9 + 4i64 * v8->m_axis[0].m_endPoints.m_size);
  v55 = result.m_enum;
  if ( v54 )
    v54->m_enum = result.m_enum;
  ++v8->m_axis[0].m_endPoints.m_size;
  v56 = (hkResultEnum *)(*(_QWORD *)v30 + 4i64 * *(signed int *)(v30 + 8));
  if ( v56 )
    *v56 = v55;
  ++*(_DWORD *)(v30 + 8);
  v57 = (hkResultEnum *)&v35->m_endPoints.m_data[v8->m_axis[2].m_endPoints.m_size];
  if ( v57 )
    *v57 = v55;
  ++v8->m_axis[2].m_endPoints.m_size;
}

// File Line: 892
// RVA: 0xCFC9D0
void __fastcall hkp3AxisSweep::~hkp3AxisSweep(hkp3AxisSweep *this)
{
  hkp3AxisSweep *v1; // rdi
  int v2; // esi
  __int64 v3; // r14
  hkp3AxisSweep::hkpBpMarker *v4; // rbx
  int v5; // er8
  hkp3AxisSweep::hkpBpMarker *v6; // rbx
  hkMemoryAllocator **v7; // rax
  signed int v8; // esi
  _DWORD *v9; // rbx
  int v10; // er8
  int v11; // eax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkp3AxisSweep::`vftable';
  v2 = 0;
  if ( this->m_numMarkers > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = &v1->m_markers[v3];
      v5 = v4->m_overlappingObjects.m_capacityAndFlags;
      v4->m_overlappingObjects.m_size = 0;
      if ( v5 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v4->m_overlappingObjects.m_data,
          2 * (v5 & 0x3FFFFFFF));
      ++v2;
      v4->m_overlappingObjects.m_data = 0i64;
      v4->m_overlappingObjects.m_capacityAndFlags = 2147483648;
      ++v3;
    }
    while ( v2 < v1->m_numMarkers );
  }
  v6 = v1->m_markers;
  v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::easyFree(v7[11], v6);
  v8 = 2;
  v9 = (_DWORD *)((char *)&v1->m_markers + 4);
  do
  {
    v10 = *(v9 - 4);
    v9 -= 4;
    *(v9 - 1) = 0;
    if ( v10 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v9 - 3),
        4 * v10);
    --v8;
    *(_QWORD *)(v9 - 3) = 0i64;
    *v9 = 2147483648;
  }
  while ( v8 >= 0 );
  v11 = v1->m_nodes.m_capacityAndFlags;
  v1->m_nodes.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_nodes.m_data,
      24 * (v11 & 0x3FFFFFFF));
  v1->m_nodes.m_data = 0i64;
  v1->m_nodes.m_capacityAndFlags = 2147483648;
  hkpBroadPhase::~hkpBroadPhase((hkpBroadPhase *)&v1->vfptr);
}

// File Line: 911
// RVA: 0xD04E10
void __fastcall hkp3AxisSweep::set32BitOffsetAndScale(hkp3AxisSweep *this, hkVector4f *offsetLow, hkVector4f *offsetHigh, hkVector4f *scale)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm2
  __m128 v6; // xmm0
  hkVector4f v7; // xmm1

  v4 = _mm_sub_ps(this->m_aabb.m_max.m_quad, this->m_aabb.m_min.m_quad);
  this->m_offsetLow32bit = (hkVector4f)offsetLow->m_quad;
  this->m_offsetHigh32bit = (hkVector4f)offsetHigh->m_quad;
  this->m_scale32bit = (hkVector4f)scale->m_quad;
  v5 = offsetLow->m_quad;
  v6 = _mm_rcp_ps(v4);
  this->m_offsetLow = (hkVector4f)offsetLow->m_quad;
  this->m_offsetHigh.m_quad = _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(FLOAT_0_00001525972),
                                    (__m128)LODWORD(FLOAT_0_00001525972),
                                    0),
                                  v4),
                                v5);
  v7.m_quad = _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(FLOAT_65532_0), (__m128)LODWORD(FLOAT_65532_0), 0),
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v4, v6)), v6));
  this->m_scale = (hkVector4f)v7.m_quad;
  _mm_store_si128((__m128i *)&this->m_scale, _mm_srli_si128(_mm_slli_si128((__m128i)v7.m_quad, 4), 4));
  _mm_store_si128(
    (__m128i *)&this->m_offsetLow,
    _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&this->m_offsetLow), 4), 4));
  _mm_store_si128(
    (__m128i *)&this->m_offsetHigh,
    _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&this->m_offsetHigh), 4), 4));
}

// File Line: 969
// RVA: 0xD05320
void __fastcall hkp3AxisSweep::hkpBpAxis::mergeBatch(hkp3AxisSweep::hkpBpAxis *this, hkp3AxisSweep::hkpBpNode *nodes, int indexOfNewEps, int newNum, int axis, hkp3AxisSweep::hkpBpEndPoint *scratch)
{
  signed __int64 v6; // r10
  hkp3AxisSweep::hkpBpNode *v7; // rsi
  hkp3AxisSweep::hkpBpAxis *v8; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v9; // r11
  hkp3AxisSweep::hkpBpEndPoint *v10; // r10
  hkp3AxisSweep::hkpBpEndPoint *v11; // r15
  hkp3AxisSweep::hkpBpEndPoint *v12; // r14
  signed int v13; // edx
  hkp3AxisSweep::hkpBpEndPoint *v14; // rax
  signed int v15; // ecx
  hkp3AxisSweep::hkpBpEndPoint v16; // ecx
  char v17; // dl
  __int64 v18; // rcx
  signed __int64 v19; // r9
  hkp3AxisSweep::hkpBpEndPoint v20; // ecx
  char v21; // dl
  __int64 v22; // rcx
  signed __int64 v23; // r9
  hkp3AxisSweep::hkpBpEndPoint v24; // ecx
  signed __int64 v25; // r9
  hkp3AxisSweep::hkpBpEndPoint v26; // ecx
  signed __int64 v27; // r9

  v6 = 0i64;
  v7 = nodes;
  v8 = this;
  if ( indexOfNewEps > 0 )
  {
    do
    {
      ++v6;
      scratch[v6 - 1] = this->m_endPoints.m_data[v6 - 1];
    }
    while ( v6 < indexOfNewEps );
  }
  v9 = &this->m_endPoints.m_data[indexOfNewEps];
  v10 = scratch + 1;
  v11 = &scratch[indexOfNewEps - 1];
  v12 = &this->m_endPoints.m_data[indexOfNewEps + newNum];
  v13 = v9->m_value;
  v14 = this->m_endPoints.m_data + 1;
  if ( scratch[1].m_value < v13 )
  {
    do
    {
      v15 = v10[1].m_value;
      ++v10;
      ++v14;
    }
    while ( v15 < v13 );
  }
  if ( v10 < v11 )
  {
    if ( v9 >= v12 )
      goto LABEL_15;
    do
    {
      while ( v10->m_value >= v9->m_value && (v10->m_value != v9->m_value || v10->m_nodeIndex >= v9->m_nodeIndex) )
      {
        v16 = *v9;
        ++v9;
        *v14 = v16;
        v17 = v16.m_value;
        v18 = v14->m_nodeIndex;
        v19 = (signed __int64)(unsigned int)((_DWORD)v14 - LODWORD(v8->m_endPoints.m_data)) >> 2;
        ++v14;
        *(unsigned __int16 *)((char *)&v7[v18].min_y + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(v17 & 1) + 2i64 * axis]) = v19;
        if ( v9 >= v12 )
          goto LABEL_15;
      }
      v20 = *v10;
      ++v10;
      *v14 = v20;
      v21 = v20.m_value;
      v22 = v14->m_nodeIndex;
      v23 = (signed __int64)(unsigned int)((_DWORD)v14 - LODWORD(v8->m_endPoints.m_data)) >> 2;
      ++v14;
      *(unsigned __int16 *)((char *)&v7[v22].min_y + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(v21 & 1) + 2i64 * axis]) = v23;
    }
    while ( v10 < v11 );
  }
  for ( ;
        v9 < v12;
        *(unsigned __int16 *)((char *)&v7[v14[-1].m_nodeIndex].min_y
                            + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2i64 * axis + (v24.m_value & 1)]) = v25 )
  {
    v24 = *v9;
    ++v9;
    *v14 = v24;
    v25 = (signed __int64)(unsigned int)((_DWORD)v14 - LODWORD(v8->m_endPoints.m_data)) >> 2;
    ++v14;
  }
LABEL_15:
  while ( v10 <= v11 )
  {
    v26 = *v10;
    ++v10;
    *v14 = v26;
    v27 = (signed __int64)(unsigned int)((_DWORD)v14 - LODWORD(v8->m_endPoints.m_data)) >> 2;
    ++v14;
    *(unsigned __int16 *)((char *)&v7[v14[-1].m_nodeIndex].min_y
                        + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2i64 * axis + (v26.m_value & 1)]) = v27;
  }
}

// File Line: 1087
// RVA: 0xD05540
void __fastcall hkp3AxisSweep::hkpBpAxis::insert(hkp3AxisSweep::hkpBpAxis *this, hkp3AxisSweep::hkpBpNode *nodes, int nodeIndex, unsigned __int16 minPosition, unsigned __int16 maxPosition, unsigned __int16 *minInsertPositionOut, unsigned __int16 *maxInsertPositionOut)
{
  unsigned __int16 v7; // bp
  int v8; // edi
  int v9; // eax
  unsigned int v10; // ebx
  hkp3AxisSweep::hkpBpAxis *v11; // rsi
  int v12; // eax
  int v13; // er9
  signed int v14; // er8
  hkp3AxisSweep::hkpBpEndPoint *v15; // rax
  hkp3AxisSweep::hkpBpEndPoint v16; // ecx
  hkp3AxisSweep::hkpBpEndPoint v17; // ecx
  unsigned __int16 *v18; // rcx
  hkp3AxisSweep::hkpBpEndPoint v19; // ecx
  hkp3AxisSweep::hkpBpEndPoint v20; // ecx
  hkResult result; // [rsp+58h] [rbp+20h]

  v7 = minPosition;
  v8 = this->m_endPoints.m_size + 2;
  v9 = this->m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = nodeIndex;
  v11 = this;
  if ( v9 < v8 )
  {
    v12 = 2 * v9;
    v13 = this->m_endPoints.m_size + 2;
    if ( v8 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v13, 4);
  }
  v14 = maxPosition;
  v11->m_endPoints.m_size = v8;
  v15 = &v11->m_endPoints.m_data[v8 - 4];
  for ( v15[3] = v11->m_endPoints.m_data[v8 - 3]; v14 < v15->m_value; v15[3] = v16 )
  {
    v16 = *v15;
    --v15;
  }
  for ( ; v14 == v15->m_value; v15[3] = v17 )
  {
    if ( v10 >= v15->m_nodeIndex )
      break;
    v17 = *v15;
    --v15;
  }
  v18 = maxInsertPositionOut;
  v15[2].m_nodeIndex = v10;
  v15[2].m_value = v14;
  for ( *v18 = (unsigned __int64)((signed __int64)(unsigned int)((_DWORD)v15 - LODWORD(v11->m_endPoints.m_data)) >> 2)
             + 2; v7 < (signed int)v15->m_value; v15[2] = v19 )
  {
    v19 = *v15;
    --v15;
  }
  for ( ; v7 == v15->m_value; v15[2] = v20 )
  {
    if ( v10 >= v15->m_nodeIndex )
      break;
    v20 = *v15;
    --v15;
  }
  v15[1].m_value = v7;
  v15[1].m_nodeIndex = v10;
  *minInsertPositionOut = (unsigned __int64)((signed __int64)(unsigned int)((_DWORD)v15
                                                                          - LODWORD(v11->m_endPoints.m_data)) >> 2)
                        + 1;
}

// File Line: 1140
// RVA: 0xD05690
void __fastcall hkp3AxisSweep::hkpBpAxis::remove(hkp3AxisSweep::hkpBpAxis *this, int minPosition, int maxPosition)
{
  hkp3AxisSweep::hkpBpEndPoint *v3; // r9
  hkp3AxisSweep::hkpBpAxis *v4; // r10
  hkp3AxisSweep::hkpBpEndPoint *v5; // rdx
  hkp3AxisSweep::hkpBpEndPoint *v6; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v7; // rdi
  unsigned __int64 v8; // rdx
  unsigned __int64 i; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v10; // rax
  int v11; // edx
  unsigned __int64 v12; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v13; // rsi
  hkp3AxisSweep::hkpBpEndPoint *v14; // rdi
  unsigned __int64 j; // rcx

  v3 = &this->m_endPoints.m_data[minPosition];
  v4 = this;
  v5 = &this->m_endPoints.m_data[maxPosition - 1i64];
  if ( v3 < v5 )
  {
    v6 = v3 + 1;
    v7 = v3;
    v8 = ((unsigned __int64)((char *)v5 - (char *)v3 - 1) >> 2) + 1;
    for ( i = v8; i; --i )
    {
      *v7 = *v6;
      ++v6;
      ++v7;
    }
    v3 += v8;
  }
  v10 = v4->m_endPoints.m_data;
  v11 = v4->m_endPoints.m_size - 2;
  v4->m_endPoints.m_size = v11;
  v12 = (unsigned __int64)&v10[v11];
  if ( (unsigned __int64)v3 < v12 )
  {
    v13 = v3 + 2;
    v14 = v3;
    for ( j = ((v12 - (unsigned __int64)v3 - 1) >> 2) + 1; j; --j )
    {
      *v14 = *v13;
      ++v13;
      ++v14;
    }
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
void __fastcall hkp3AxisSweep::updateNodesAfterInsert(hkp3AxisSweep *this, hkp3AxisSweep::hkpBpNode *nodes, int numNodes, hkp3AxisSweep::hkpBpNode *newNode)
{
  hkp3AxisSweep::hkpBpNode *v4; // rsi
  int v5; // er10
  int v6; // er11
  unsigned __int16 v7; // bx
  hkp3AxisSweep::hkpBpNode *v8; // rbp
  unsigned __int16 v9; // dx
  int v10; // edi
  unsigned __int16 v11; // r9
  int v12; // eax
  int v13; // er9
  signed __int64 v14; // r8
  int v15; // er14
  int v16; // edx
  __int16 v17; // cx
  int v18; // edx
  __int16 v19; // cx
  int v20; // edx
  __int16 v21; // cx
  int v22; // edx
  __int16 v23; // cx
  int v24; // edx
  __int16 v25; // cx
  int v26; // edx
  int v27; // [rsp+58h] [rbp+10h]

  v4 = nodes;
  LOWORD(v5) = newNode->min_x - 1;
  LOWORD(v6) = newNode->min_y - 1;
  v7 = newNode->min_z - 1;
  v8 = &nodes[numNodes];
  v9 = newNode->max_x - 2;
  LOWORD(v10) = newNode->max_y - 2;
  v11 = newNode->max_z - 2;
  if ( v4 < v8 )
  {
    v27 = v11;
    v12 = v11;
    v13 = v9;
    v14 = (signed __int64)&v4->max_x;
    v15 = v9;
    v5 = (unsigned __int16)v5;
    v10 = (unsigned __int16)v10;
    v6 = (unsigned __int16)v6;
    do
    {
      v16 = *(unsigned __int16 *)(v14 - 2);
      v14 += 24i64;
      v17 = v16 + ((unsigned int)(v15 - v16) >> 31) + (((unsigned int)(unsigned __int16)v5 - v16) >> 31);
      v18 = *(unsigned __int16 *)(v14 - 34);
      *(_WORD *)(v14 - 26) = v17;
      v19 = v18
          + (((unsigned int)(unsigned __int16)v10 - v18) >> 31)
          + (((unsigned int)(unsigned __int16)v6 - v18) >> 31);
      v20 = *(unsigned __int16 *)(v14 - 24);
      *(_WORD *)(v14 - 34) = v19;
      v21 = v20 + ((unsigned int)(v13 - v20) >> 31) + ((unsigned int)(v5 - v20) >> 31);
      v22 = *(unsigned __int16 *)(v14 - 30);
      *(_WORD *)(v14 - 24) = v21;
      v23 = v22 + ((unsigned int)(v10 - v22) >> 31) + ((unsigned int)(v6 - v22) >> 31);
      v24 = *(unsigned __int16 *)(v14 - 32);
      *(_WORD *)(v14 - 30) = v23;
      v25 = v24 + ((unsigned int)(v27 - v24) >> 31) + (((unsigned int)v7 - v24) >> 31);
      v26 = *(unsigned __int16 *)(v14 - 28);
      *(_WORD *)(v14 - 32) = v25;
      *(_WORD *)(v14 - 28) = v26 + ((unsigned int)(v12 - v26) >> 31) + (((unsigned int)v7 - v26) >> 31);
    }
    while ( v14 - 10 < (unsigned __int64)v8 );
  }
}

// File Line: 1391
// RVA: 0xD04EE0
void __fastcall hkp3AxisSweep::collide1Axis(hkp3AxisSweep *this, hkp3AxisSweep::hkpBpNode *pa, int numA, hkp3AxisSweep::hkpBpNode *pb, int numB, hkp3AxisSweep::MarkerHandling markerHandlingForNodesB, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut)
{
  hkpBroadPhaseHandle **v7; // r15
  unsigned __int16 *v8; // r12
  unsigned __int16 v9; // ax
  unsigned int v10; // er14
  signed __int64 v11; // rsi
  int v12; // edi
  unsigned __int64 v13; // r8
  _DWORD *v14; // rbx
  signed __int64 v15; // r10
  signed int v16; // ecx
  signed __int64 v17; // rdx
  _WORD *v18; // rax
  hkpBroadPhaseHandlePair *v19; // rcx
  unsigned int v20; // eax
  bool v21; // zf
  bool v22; // sf
  unsigned int v23; // er14
  hkpBroadPhaseHandle **v24; // rdi
  int v25; // esi
  unsigned __int64 v26; // r8
  _DWORD *v27; // rbx
  signed __int64 v28; // r10
  signed int v29; // ecx
  signed __int64 v30; // rdx
  _WORD *v31; // rax
  hkpBroadPhaseHandlePair *v32; // rcx
  unsigned int v33; // eax
  hkp3AxisSweep::hkpBpMarker *v34; // [rsp+70h] [rbp+8h]
  hkpBroadPhaseHandle **v35; // [rsp+78h] [rbp+10h]
  int v36; // [rsp+80h] [rbp+18h]
  unsigned __int16 *v37; // [rsp+88h] [rbp+20h]

  v36 = numA;
  v7 = &pb->m_handle;
  v8 = &pa->min_x;
  v34 = this->m_markers;
  v35 = &pb->m_handle;
  v37 = &pa->min_x;
  do
  {
    v9 = *((_WORD *)v7 - 4);
    if ( *v8 <= v9 )
    {
      v23 = v8[1];
      if ( v9 < v23 )
      {
        v24 = v7;
        do
        {
          if ( !(((*((_DWORD *)v8 - 1) - *((_DWORD *)v24 - 4)) | (*((_DWORD *)v24 - 3) - *((_DWORD *)v8 - 2))) & 0x80008000) )
          {
            if ( *(_BYTE *)v24 & 1 )
            {
              if ( markerHandlingForNodesB != 1 )
              {
                v25 = **((_DWORD **)v8 + 1);
                v26 = (unsigned __int64)v34 + ((unsigned __int64)*v24 & 0xFFFFFFFFFFFFFFFEui64);
                if ( markerHandlingForNodesB )
                {
                  v28 = *(signed int *)(v26 + 16);
                  v29 = 0;
                  v30 = 0i64;
                  if ( (signed int)v28 <= 0 )
                  {
LABEL_38:
                    v29 = -1;
                    v30 = -1i64;
                  }
                  else
                  {
                    v31 = *(_WORD **)(v26 + 8);
                    while ( *v31 != (_WORD)v25 )
                    {
                      ++v30;
                      ++v29;
                      ++v31;
                      if ( v30 >= v28 )
                        goto LABEL_38;
                    }
                  }
                  *(_DWORD *)(v26 + 16) = v28 - 1;
                  if ( (_DWORD)v28 - 1 != v29 )
                    *(_WORD *)(*(_QWORD *)(v26 + 8) + 2 * v30) = *(_WORD *)(*(_QWORD *)(v26 + 8)
                                                                          + 2i64 * ((signed int)v28 - 1));
                }
                else
                {
                  v27 = (_DWORD *)(v26 + 8);
                  if ( *(_DWORD *)(v26 + 16) == (*(_DWORD *)(v26 + 20) & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v27, 2);
                  *(_WORD *)(*(_QWORD *)v27 + 2i64 * (signed int)v27[2]++) = v25;
                }
              }
            }
            else
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, pairsOut, 16);
              v32 = &pairsOut->m_data[pairsOut->m_size++];
              v32->m_a = (hkpBroadPhaseHandle *)*((_QWORD *)v8 + 1);
              v32->m_b = *v24;
            }
          }
          v33 = *((unsigned __int16 *)v24 + 8);
          v24 += 3;
        }
        while ( v33 < v23 );
        v7 = v35;
        numA = v36;
      }
      v8 += 12;
      --numA;
      v37 = v8;
      v36 = numA;
      v21 = numA == 0;
      v22 = numA < 0;
    }
    else
    {
      v10 = *((unsigned __int16 *)v7 - 3);
      if ( *v8 < v10 )
      {
        v11 = (signed __int64)(v8 + 4);
        do
        {
          if ( !(((*((_DWORD *)v7 - 3) - *(_DWORD *)(v11 - 16)) | (*(_DWORD *)(v11 - 12) - *((_DWORD *)v7 - 4))) & 0x80008000) )
          {
            if ( *(_BYTE *)v7 & 1 )
            {
              if ( markerHandlingForNodesB != 1 )
              {
                v12 = **(_DWORD **)v11;
                v13 = (unsigned __int64)v34 + ((unsigned __int64)*v7 & 0xFFFFFFFFFFFFFFFEui64);
                if ( markerHandlingForNodesB )
                {
                  v15 = *(signed int *)(v13 + 16);
                  v16 = 0;
                  v17 = 0i64;
                  if ( (signed int)v15 <= 0 )
                  {
LABEL_16:
                    v16 = -1;
                    v17 = -1i64;
                  }
                  else
                  {
                    v18 = *(_WORD **)(v13 + 8);
                    while ( *v18 != (_WORD)v12 )
                    {
                      ++v17;
                      ++v16;
                      ++v18;
                      if ( v17 >= v15 )
                        goto LABEL_16;
                    }
                  }
                  *(_DWORD *)(v13 + 16) = v15 - 1;
                  if ( (_DWORD)v15 - 1 != v16 )
                    *(_WORD *)(*(_QWORD *)(v13 + 8) + 2 * v17) = *(_WORD *)(*(_QWORD *)(v13 + 8)
                                                                          + 2i64 * ((signed int)v15 - 1));
                }
                else
                {
                  v14 = (_DWORD *)(v13 + 8);
                  if ( *(_DWORD *)(v13 + 16) == (*(_DWORD *)(v13 + 20) & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v14, 2);
                  *(_WORD *)(*(_QWORD *)v14 + 2i64 * (signed int)v14[2]++) = v12;
                }
              }
            }
            else
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, pairsOut, 16);
              v19 = &pairsOut->m_data[pairsOut->m_size++];
              v19->m_a = *(hkpBroadPhaseHandle **)v11;
              v19->m_b = *v7;
            }
          }
          v20 = *(unsigned __int16 *)(v11 + 16);
          v11 += 24i64;
        }
        while ( v20 < v10 );
        v8 = v37;
        numA = v36;
      }
      v7 += 3;
      v35 = v7;
      v21 = --numB == 0;
      v22 = numB < 0;
    }
  }
  while ( !v22 && !v21 );
}

// File Line: 1424
// RVA: 0xD05240
void __fastcall hkp3AxisSweep::collide1Axis(hkp3AxisSweep *this, hkp3AxisSweep::hkpBpNode *pa, int numA, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut)
{
  int v4; // er14
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v5; // rdi
  hkpBroadPhaseHandle **v6; // rsi
  unsigned int v7; // ebp
  hkpBroadPhaseHandle **v8; // rbx
  hkpBroadPhaseHandlePair *v9; // rcx
  unsigned int v10; // eax

  v4 = numA - 1;
  v5 = pairsOut;
  if ( numA - 1 > 0 )
  {
    v6 = &pa[1].m_handle;
    do
    {
      v7 = *((unsigned __int16 *)v6 - 15);
      if ( *((unsigned __int16 *)v6 - 4) < v7 )
      {
        v8 = v6;
        do
        {
          if ( !(((*((_DWORD *)v6 - 9) - *((_DWORD *)v8 - 4)) | (*((_DWORD *)v8 - 3) - *((_DWORD *)v6 - 10))) & 0x80008000)
            && !(*(_BYTE *)v8 & 1) )
          {
            if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
            v9 = &v5->m_data[v5->m_size++];
            v9->m_a = *(v6 - 3);
            v9->m_b = *v8;
          }
          v10 = *((unsigned __int16 *)v8 + 8);
          v8 += 3;
        }
        while ( v10 < v7 );
      }
      --v4;
      v6 += 3;
    }
    while ( v4 > 0 );
  }
}

// File Line: 1445
// RVA: 0xD06190
void __fastcall hkp3AxisSweep::updateNodesAfterBatchTailInsert(hkp3AxisSweep *this, hkp3AxisSweep::hkpBpNode *nodes, int numNodes, int numNewEndPoints, int *offsets)
{
  __int16 v5; // bx
  int v6; // er10
  int v7; // er11
  hkp3AxisSweep::hkpBpNode *v8; // r8
  char *v9; // rax
  int v10; // edx
  __int16 v11; // cx
  int v12; // edx
  __int16 v13; // cx
  int v14; // edx
  __int16 v15; // cx
  int v16; // edx
  __int16 v17; // cx
  int v18; // edx
  __int16 v19; // cx
  int v20; // edx

  v5 = numNewEndPoints;
  LOWORD(v6) = *(_WORD *)offsets - 1;
  LOWORD(v7) = *((_WORD *)offsets + 2) - 1;
  LOWORD(numNewEndPoints) = *((_WORD *)offsets + 4) - 1;
  v8 = &nodes[numNodes];
  if ( nodes < v8 )
  {
    v6 = (unsigned __int16)v6;
    v7 = (unsigned __int16)v7;
    numNewEndPoints = (unsigned __int16)numNewEndPoints;
    v9 = (char *)&nodes->max_x;
    do
    {
      v10 = *((unsigned __int16 *)v9 - 1);
      v9 += 24;
      v11 = v10 + (v5 & (((unsigned int)(unsigned __int16)v6 - v10) >> 31));
      v12 = *((unsigned __int16 *)v9 - 17);
      *((_WORD *)v9 - 13) = v11;
      v13 = v12 + (v5 & (((unsigned int)(unsigned __int16)v7 - v12) >> 31));
      v14 = *((unsigned __int16 *)v9 - 12);
      *((_WORD *)v9 - 17) = v13;
      v15 = v14 + (v5 & ((unsigned int)(v6 - v14) >> 31));
      v16 = *((unsigned __int16 *)v9 - 15);
      *((_WORD *)v9 - 12) = v15;
      v17 = v16 + (v5 & ((unsigned int)(v7 - v16) >> 31));
      v18 = *((unsigned __int16 *)v9 - 16);
      *((_WORD *)v9 - 15) = v17;
      v19 = v18 + (v5 & (((unsigned int)(unsigned __int16)numNewEndPoints - v18) >> 31));
      v20 = *((unsigned __int16 *)v9 - 14);
      *((_WORD *)v9 - 16) = v19;
      *((_WORD *)v9 - 14) = v20 + (v5 & ((unsigned int)(numNewEndPoints - v20) >> 31));
    }
    while ( v9 - 10 < (char *)v8 );
  }
}

// File Line: 1571
// RVA: 0xD05FE0
void __fastcall hkp3AxisSweep::updateNodesAfterDelete(hkp3AxisSweep *this, hkp3AxisSweep::hkpBpNode *nodes, int numNodes, hkp3AxisSweep::hkpBpNode *oldNode)
{
  int v4; // er10
  int v5; // er11
  int v6; // ebx
  int v7; // edi
  int v8; // esi
  hkp3AxisSweep::hkpBpNode *v9; // rbp
  char *v10; // r8
  int v11; // edx
  __int16 v12; // cx
  unsigned int v13; // eax
  int v14; // edx
  __int16 v15; // cx
  unsigned int v16; // eax
  int v17; // edx
  __int16 v18; // cx
  unsigned int v19; // eax
  int v20; // edx
  __int16 v21; // cx
  unsigned int v22; // eax
  int v23; // edx
  __int16 v24; // cx
  unsigned int v25; // eax
  int v26; // edx

  LOWORD(v4) = oldNode->min_x;
  LOWORD(v5) = oldNode->min_y;
  LOWORD(v6) = oldNode->min_z;
  LOWORD(v7) = oldNode->max_x;
  LOWORD(v8) = oldNode->max_y;
  LOWORD(oldNode) = oldNode->max_z;
  v9 = &nodes[numNodes];
  if ( nodes != v9 )
  {
    LODWORD(oldNode) = (unsigned __int16)oldNode;
    v6 = (unsigned __int16)v6;
    v7 = (unsigned __int16)v7;
    v8 = (unsigned __int16)v8;
    v10 = (char *)&nodes->max_x;
    v4 = (unsigned __int16)v4;
    v5 = (unsigned __int16)v5;
    do
    {
      v11 = *((unsigned __int16 *)v10 - 1);
      v10 += 24;
      v12 = v11 - (((unsigned int)(unsigned __int16)v7 - v11) >> 31);
      v13 = (unsigned __int16)v4 - v11;
      v14 = *((unsigned __int16 *)v10 - 12);
      *((_WORD *)v10 - 13) = v12 - (v13 >> 31);
      v15 = v14 - ((unsigned int)(v4 - v14) >> 31);
      v16 = v7 - v14;
      v17 = *((unsigned __int16 *)v10 - 17);
      *((_WORD *)v10 - 12) = v15 - (v16 >> 31);
      v18 = v17 - (((unsigned int)(unsigned __int16)v5 - v17) >> 31);
      v19 = (unsigned __int16)v8 - v17;
      v20 = *((unsigned __int16 *)v10 - 15);
      *((_WORD *)v10 - 17) = v18 - (v19 >> 31);
      v21 = v20 - ((unsigned int)(v5 - v20) >> 31);
      v22 = v8 - v20;
      v23 = *((unsigned __int16 *)v10 - 16);
      *((_WORD *)v10 - 15) = v21 - (v22 >> 31);
      v24 = v23 - ((unsigned int)(v6 - v23) >> 31);
      v25 = (_DWORD)oldNode - v23;
      v26 = *((unsigned __int16 *)v10 - 14);
      *((_WORD *)v10 - 16) = v24 - (v25 >> 31);
      *((_WORD *)v10 - 14) = v26
                           - (((unsigned int)(unsigned __int16)v6 - v26) >> 31)
                           - (((unsigned int)(unsigned __int16)oldNode - v26) >> 31);
    }
    while ( v10 - 10 != (char *)v9 );
  }
}

// File Line: 1664
// RVA: 0xD062B0
void __fastcall hkp3AxisSweep::setBitsBasedOnXInterval(hkp3AxisSweep *this, int numNodes, int x_value, hkp3AxisSweep::hkpBpNode *queryNode, unsigned __int16 queryNodeIndex, unsigned int *bitField)
{
  __int64 v6; // rbp
  int v7; // edx
  __int64 v8; // rsi
  hkp3AxisSweep *v9; // rbx
  unsigned int *i; // r9
  unsigned int *v11; // rax
  hkp3AxisSweep::hkpBpEndPoint *v12; // rdx
  unsigned __int64 v13; // rax
  int v14; // er8
  hkp3AxisSweep::hkpBpMarker *v15; // rdi
  unsigned __int16 *v16; // r8
  int j; // er9
  unsigned __int16 v18; // ax
  unsigned int *v19; // rdx
  hkp3AxisSweep::hkpBpNode *v20; // r11
  hkp3AxisSweep::hkpBpEndPoint *v21; // rcx
  unsigned __int64 v22; // r8
  unsigned __int64 k; // r9
  unsigned __int64 l; // r9
  int v25; // ecx
  unsigned __int64 v26; // rax
  unsigned __int64 m; // r9

  v6 = queryNode->max_x;
  v7 = numNodes >> 7;
  v8 = queryNode->min_x;
  v9 = this;
  for ( i = bitField; v7 >= 0; *(_OWORD *)v11 = 0i64 )
  {
    v11 = i;
    i += 4;
    --v7;
  }
  v12 = this->m_axis[0].m_endPoints.m_data;
  v13 = (unsigned __int64)&v12[1];
  if ( this->m_numMarkers )
  {
    v14 = x_value >> (16 - LOBYTE(this->m_ld2NumMarkers));
    if ( v14 > 0 )
    {
      v15 = &this->m_markers[v14 - 1];
      bitField[(signed int)v15->m_nodeIndex >> 5] ^= 1 << (v15->m_nodeIndex & 0x1F);
      v16 = v15->m_overlappingObjects.m_data;
      for ( j = v15->m_overlappingObjects.m_size - 1; j >= 0; --j )
      {
        v18 = *v16;
        if ( *v16 != queryNodeIndex )
        {
          v19 = &bitField[(signed int)v18 >> 5];
          *v19 ^= 1 << (v18 & 0x1F);
        }
        ++v16;
      }
      v20 = &this->m_nodes.m_data[v15->m_nodeIndex];
      v21 = this->m_axis[0].m_endPoints.m_data;
      v22 = (unsigned __int64)&v21[v20->min_x + 1];
      for ( k = (unsigned __int64)&v21[v20->max_x]; v22 < k; v22 += 4i64 )
      {
        if ( !(*(_BYTE *)v22 & 1) )
          bitField[(signed int)*(unsigned __int16 *)(v22 + 2) >> 5] &= ~(1 << (*(_WORD *)(v22 + 2) & 0x1F));
      }
      v12 = v9->m_axis[0].m_endPoints.m_data;
      v13 = (unsigned __int64)&v12[v20->min_x + 1];
    }
  }
  for ( l = (unsigned __int64)&v12[v8]; v13 < l; bitField[v25 >> 5] ^= 1 << (v25 & 0x1F) )
  {
    v25 = *(unsigned __int16 *)(v13 + 2);
    v13 += 4i64;
  }
  v26 = v13 + 4;
  for ( m = (unsigned __int64)&v9->m_axis[0].m_endPoints.m_data[v6]; v26 < m; v26 += 4i64 )
  {
    if ( !(*(_BYTE *)v26 & 1) )
      bitField[(signed int)*(unsigned __int16 *)(v26 + 2) >> 5] ^= 1 << (*(_WORD *)(v26 + 2) & 0x1F);
  }
}

// File Line: 1740
// RVA: 0xD01C70
void __fastcall hkp3AxisSweep::reQuerySingleObject(hkp3AxisSweep *this, hkpBroadPhaseHandle *object, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  int v3; // edi
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v4; // rsi
  hkpBroadPhaseHandle *v5; // r12
  hkp3AxisSweep *v6; // rbx
  int v7; // eax
  unsigned int *bitField; // r10
  signed int v9; // ebp
  signed __int64 v10; // r14
  hkp3AxisSweep::hkpBpEndPoint *v11; // rax
  __int64 v12; // rcx
  unsigned int *v13; // r15
  hkp3AxisSweep::hkpBpNode *v14; // r13
  unsigned int *v15; // rcx
  unsigned __int64 v16; // rax
  unsigned int v17; // ebx
  hkp3AxisSweep::hkpBpNode *v18; // rdi
  hkpBroadPhaseHandle *v19; // rbp
  hkpBroadPhaseHandlePair *v20; // rax
  unsigned __int16 queryNodeIndex; // [rsp+20h] [rbp-58h]
  unsigned __int64 v22; // [rsp+30h] [rbp-48h]
  int v23; // [rsp+80h] [rbp+8h]
  int v24; // [rsp+88h] [rbp+10h]
  unsigned int *v25; // [rsp+98h] [rbp+20h]

  v3 = this->m_nodes.m_size;
  v4 = pairs_out;
  v5 = object;
  v6 = this;
  v7 = (this->m_nodes.m_size >> 5) + 8;
  if ( this->m_nodes.m_size >> 5 == -8 )
  {
    bitField = 0i64;
  }
  else
  {
    v23 = 4 * v7;
    bitField = (unsigned int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                 &v23);
    v7 = v23 / 4;
  }
  queryNodeIndex = v5->m_id;
  v9 = 2147483648;
  if ( v7 )
    v9 = v7;
  v10 = (signed __int64)&v6->m_nodes.m_data[v5->m_id];
  v11 = v6->m_axis[0].m_endPoints.m_data;
  v25 = bitField;
  v12 = *(unsigned __int16 *)(v10 + 8);
  v24 = v9;
  v13 = bitField;
  hkp3AxisSweep::setBitsBasedOnXInterval(
    v6,
    v3,
    v11[v12].m_value,
    (hkp3AxisSweep::hkpBpNode *)v10,
    queryNodeIndex,
    bitField);
  v14 = v6->m_nodes.m_data;
  v15 = v13;
  v16 = (unsigned __int64)&v13[((signed __int64)v6->m_nodes.m_size >> 5) + 1];
  v22 = v16;
  if ( (unsigned __int64)v13 < v16 )
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
            if ( v17 & 1
              && !(((*(_DWORD *)(v10 + 4) - *(_DWORD *)&v18->min_y) | (*(_DWORD *)&v18->max_y - *(_DWORD *)v10)) & 0x80008000)
              && !((_QWORD)v18->m_handle & 1) )
            {
              v19 = v18->m_handle;
              if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
              v20 = &v4->m_data[v4->m_size];
              if ( v20 )
              {
                v20->m_a = v5;
                v20->m_b = v19;
              }
              ++v4->m_size;
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
    while ( (unsigned __int64)v13 < v16 );
    v9 = v24;
    v15 = v25;
  }
  if ( v9 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v15,
      4 * v9);
}

// File Line: 1789
// RVA: 0xD01E60
bool __fastcall hkp3AxisSweep::areAabbsOverlapping(hkp3AxisSweep *this, hkpBroadPhaseHandle *bhA, hkpBroadPhaseHandle *bhB)
{
  hkp3AxisSweep::hkpBpNode *v3; // r9
  hkp3AxisSweep::hkpBpNode *v4; // rdx
  __int16 v5; // ax
  hkp3AxisSweep::hkpBpNode *v6; // r8

  v3 = this->m_nodes.m_data;
  v4 = &v3[bhA->m_id];
  v5 = v3[bhB->m_id].max_x - v4->min_x;
  v6 = &v3[bhB->m_id];
  return (((v6->max_y - v4->min_y) | (v4->max_y - v6->min_y) | v5 | (v4->max_x - v6->min_x)) & 0x8000u) == 0
      && !(((*(_DWORD *)&v6->max_y - *(_DWORD *)&v4->min_y) | (*(_DWORD *)&v4->max_y - *(_DWORD *)&v6->min_y)) & 0x80008000);
}

// File Line: 1848
// RVA: 0xCFCB60
void __fastcall hkp3AxisSweep::addObject(hkp3AxisSweep *this, hkpBroadPhaseHandle *object, hkAabbUint32 *aabbIn, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs, bool border)
{
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v5; // rbp
  unsigned int v6; // edi
  unsigned int v7; // er9
  unsigned int v8; // er10
  unsigned int v9; // er11
  hkAabbUint32 *v10; // rax
  hkpBroadPhaseHandle *v11; // r15
  hkp3AxisSweep *v12; // r14
  unsigned int v13; // er9
  unsigned int v14; // er8
  unsigned int v15; // er8
  unsigned int v16; // edx
  unsigned int v17; // edx
  unsigned int v18; // edi
  unsigned int v19; // er10
  unsigned int v20; // er11
  signed __int16 v21; // cx
  signed int v22; // eax
  signed __int16 v23; // ax
  signed __int16 v24; // ax
  signed __int16 v25; // ax
  signed __int16 v26; // ax
  int v27; // er12
  hkp3AxisSweep::hkpBpNode **v28; // rsi
  __int64 v29; // rdx
  hkp3AxisSweep::hkpBpNode *v30; // rbx
  hkp3AxisSweep::hkpBpNode *minInsertPositionOut; // r13
  int v32; // ebx
  int v33; // eax
  unsigned int *v34; // rax
  unsigned int *v35; // rcx
  unsigned int v36; // edx
  unsigned int *v37; // rdx
  hkp3AxisSweep::hkpBpNode *v38; // rcx
  unsigned int *v39; // r15
  unsigned __int64 v40; // rax
  unsigned int v41; // esi
  hkp3AxisSweep::hkpBpNode *v42; // rbx
  hkpBroadPhaseHandle *v43; // rdi
  hkpBroadPhaseHandlePair *v44; // rax
  _DWORD *v45; // rdi
  unsigned int *v46; // [rsp+40h] [rbp-78h]
  hkpBroadPhaseHandle *v47; // [rsp+48h] [rbp-70h]
  unsigned __int64 v48; // [rsp+50h] [rbp-68h]
  unsigned __int16 v49; // [rsp+60h] [rbp-58h]
  unsigned __int16 v50; // [rsp+64h] [rbp-54h]
  unsigned __int16 v51; // [rsp+68h] [rbp-50h]
  unsigned __int16 maxPosition; // [rsp+70h] [rbp-48h]
  unsigned __int16 v53; // [rsp+74h] [rbp-44h]
  unsigned __int16 v54; // [rsp+78h] [rbp-40h]
  signed int v55; // [rsp+C0h] [rbp+8h]
  unsigned int *v56; // [rsp+C8h] [rbp+10h]
  hkp3AxisSweep::hkpBpNode *v57; // [rsp+D0h] [rbp+18h]

  v5 = newPairs;
  v6 = aabbIn->m_min[0] >> 15;
  v7 = aabbIn->m_max[0] >> 15;
  v8 = aabbIn->m_min[1] >> 15;
  v9 = aabbIn->m_min[2] >> 15;
  v10 = aabbIn;
  v11 = object;
  v47 = object;
  v12 = this;
  if ( v7 != 0xFFFF )
    ++v7;
  v13 = v7 | 1;
  v14 = aabbIn->m_max[1] >> 15;
  maxPosition = v13;
  if ( v14 != 0xFFFF )
    ++v14;
  v15 = v14 | 1;
  v16 = v10->m_max[2] >> 15;
  v53 = v15;
  if ( v16 != 0xFFFF )
    ++v16;
  v17 = v16 | 1;
  v18 = v6 & 0xFFFE;
  v19 = v8 & 0xFFFE;
  v20 = v9 & 0xFFFE;
  v54 = v17;
  v49 = v18;
  v56 = 0i64;
  v50 = v19;
  v51 = v20;
  if ( border )
  {
    v21 = -4;
    v22 = 65532;
    if ( v18 < 0x7FFE )
      v22 = 0;
    v18 = v22;
    v49 = v22;
    v23 = -4;
    if ( v13 < 0x7FFE )
      v23 = 0;
    maxPosition = v23 + 1;
    v24 = -4;
    if ( v19 < 0x7FFE )
      v24 = 0;
    v50 = v24;
    v25 = -4;
    if ( v15 < 0x7FFE )
      v25 = 0;
    v53 = v25 + 1;
    v26 = -4;
    if ( v20 < 0x7FFE )
      v26 = 0;
    if ( v17 < 0x7FFE )
      v21 = 0;
    v51 = v26;
    v54 = v21 + 1;
  }
  v27 = v12->m_nodes.m_size;
  v28 = &v12->m_nodes.m_data;
  if ( v12->m_nodes.m_size == (v12->m_nodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v12->m_nodes, 24);
  v29 = v12->m_nodes.m_size;
  v30 = *v28;
  minInsertPositionOut = &(*v28)[v29];
  v12->m_nodes.m_size = v29 + 1;
  hkp3AxisSweep::hkpBpAxis::insert(
    v12->m_axis,
    v30,
    v27,
    v49,
    maxPosition,
    &minInsertPositionOut->min_x,
    &minInsertPositionOut->max_x);
  hkp3AxisSweep::hkpBpAxis::insert(
    &v12->m_axis[1],
    v30,
    v27,
    v50,
    v53,
    &minInsertPositionOut->min_y,
    &minInsertPositionOut->max_y);
  hkp3AxisSweep::hkpBpAxis::insert(
    &v12->m_axis[2],
    v30,
    v27,
    v51,
    v54,
    &minInsertPositionOut->min_z,
    &minInsertPositionOut->max_z);
  hkp3AxisSweep::updateNodesAfterInsert(v12, v30, v27, minInsertPositionOut);
  minInsertPositionOut->m_handle = v11;
  v11->m_id = v27;
  v32 = v12->m_nodes.m_size;
  v33 = (v12->m_nodes.m_size >> 5) + 8;
  if ( v12->m_nodes.m_size >> 5 == -8 )
  {
    v35 = 0i64;
  }
  else
  {
    *(_DWORD *)&border = 4 * v33;
    v34 = (unsigned int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                            (int *)&border);
    v35 = v34;
    v56 = v34;
    v33 = border / 4;
  }
  v36 = 2147483648;
  if ( v33 )
    v36 = v33;
  v55 = v36;
  hkp3AxisSweep::setBitsBasedOnXInterval(v12, v32, v18, minInsertPositionOut, v27, v35);
  v37 = v56;
  v38 = *v28;
  v39 = v56;
  v46 = v56;
  v57 = *v28;
  v40 = (unsigned __int64)&v56[((signed __int64)v12->m_nodes.m_size >> 5) + 1];
  v48 = v40;
  if ( (unsigned __int64)v56 < v40 )
  {
    do
    {
      v41 = *v39;
      v42 = v38;
      if ( *v39 )
      {
        do
        {
          if ( (_BYTE)v41 )
          {
            if ( v41 & 1
              && !(((*(_DWORD *)&minInsertPositionOut->max_y - *(_DWORD *)&v42->min_y) | (*(_DWORD *)&v42->max_y
                                                                                        - *(_DWORD *)&minInsertPositionOut->min_y)) & 0x80008000) )
            {
              v43 = v42->m_handle;
              if ( (unsigned __int8)v43 & 1 )
              {
                v45 = (_DWORD *)((char *)&v12->m_markers->m_nodeIndex + ((unsigned __int64)v43 & 0xFFFFFFFFFFFFFFFEui64));
                if ( v45[4] == (v45[5] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v45 + 2, 2);
                *(_WORD *)(*((_QWORD *)v45 + 1) + 2i64 * (signed int)v45[4]++) = v27;
              }
              else
              {
                if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
                v44 = &v5->m_data[v5->m_size];
                if ( v44 )
                {
                  v44->m_a = v47;
                  v44->m_b = v43;
                }
                ++v5->m_size;
              }
            }
            ++v42;
            v41 >>= 1;
          }
          else
          {
            v42 += 8;
            v41 >>= 8;
          }
        }
        while ( v41 );
        v39 = v46;
        v38 = v57;
        v40 = v48;
      }
      ++v39;
      v38 += 32;
      v57 = v38;
      v46 = v39;
    }
    while ( (unsigned __int64)v39 < v40 );
    v37 = v56;
  }
  if ( v55 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v37,
      4 * v55);
}

// File Line: 1908
// RVA: 0xCFCFB0
void __fastcall hkp3AxisSweep::addObject(hkp3AxisSweep *this, hkpBroadPhaseHandle *object, hkAabb *aabbIn, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs, bool border)
{
  hkBaseObjectVtbl *v5; // r10
  bool v6; // ST20_1
  __m128 v7; // xmm4
  __m128 v8; // xmm8
  __m128i v9; // xmm3
  __m128i v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm3
  __m128i v13; // xmm2
  __int128 v14; // [rsp+30h] [rbp-48h]
  __int128 v15; // [rsp+40h] [rbp-38h]

  v5 = this->vfptr;
  v6 = border;
  v7 = _mm_max_ps(
         _mm_min_ps(
           _mm_mul_ps(_mm_add_ps(this->m_offsetLow32bit.m_quad, aabbIn->m_min.m_quad), this->m_scale32bit.m_quad),
           hkAabbUtil::hkAabbUint32MaxVal),
         (__m128)0i64);
  v8 = _mm_add_ps(
         *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31,
         *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31);
  v9 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v7);
  v10 = _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v7, _mm_and_ps((__m128)v9, *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v9, 0x1Fu)),
          (__m128i)_mm_cmpleps(v8, v7));
  v11 = _mm_add_ps(this->m_offsetHigh32bit.m_quad, aabbIn->m_max.m_quad);
  _mm_store_si128((__m128i *)&v14, v10);
  v12 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(v11, this->m_scale32bit.m_quad), hkAabbUtil::hkAabbUint32MaxVal), (__m128)0i64);
  v13 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v12);
  _mm_store_si128(
    (__m128i *)&v15,
    _mm_or_si128(
      _mm_add_epi32(
        _mm_cvttps_epi32(
          _mm_max_ps(
            _mm_sub_ps(v12, _mm_and_ps((__m128)v13, *(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31)),
            (__m128)0i64)),
        _mm_slli_epi32(v13, 0x1Fu)),
      (__m128i)_mm_cmpleps(v8, v12)));
  ((void (__fastcall *)(hkp3AxisSweep *, hkpBroadPhaseHandle *, __int128 *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, bool))v5[3].__vecDelDtor)(
    this,
    object,
    &v14,
    newPairs,
    v6);
}

// File Line: 1992
// RVA: 0xCFE120
void __fastcall hkp3AxisSweep::removeObject(hkp3AxisSweep *this, hkpBroadPhaseHandle *object, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairsOut)
{
  unsigned int v3; // er12
  __int64 queryNodeIndex; // r14
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v5; // rbp
  hkp3AxisSweep::hkpBpNode *v6; // r15
  hkp3AxisSweep *v7; // r13
  __int32 v8; // eax
  unsigned int *bitField; // rdi
  hkp3AxisSweep::hkpBpAxis *v10; // rsi
  signed int v11; // ebx
  int v12; // er8
  hkp3AxisSweep::hkpBpNode *v13; // rcx
  unsigned int *v14; // r12
  unsigned __int64 v15; // rax
  unsigned int v16; // edi
  hkp3AxisSweep::hkpBpNode *v17; // rbx
  hkpBroadPhaseHandle *v18; // rsi
  hkpBroadPhaseHandlePair *v19; // rax
  signed int v20; // ecx
  signed __int64 v21; // rdx
  unsigned __int64 v22; // r9
  signed __int64 v23; // r10
  _WORD *v24; // rax
  hkArray<hkp3AxisSweep::hkpBpNode,hkContainerHeapAllocator> *v25; // rbp
  hkp3AxisSweep::hkpBpNode *v26; // rbx
  int v27; // er12
  hkp3AxisSweep::hkpBpNode *v28; // rcx
  __int64 v29; // r10
  hkp3AxisSweep::hkpBpEndPoint *v30; // r11
  char v31; // cl
  signed __int64 v32; // r9
  signed int v33; // edx
  signed __int64 v34; // r10
  signed __int64 v35; // r11
  hkp3AxisSweep::hkpBpMarker *v36; // r9
  signed __int64 v37; // rcx
  signed __int64 v38; // rdx
  unsigned __int16 *v39; // rax
  unsigned __int16 *v40; // rax
  int v41; // ebx
  int v42; // eax
  int v43; // eax
  int v44; // er9
  hkp3AxisSweep::hkpBpNode *v45; // [rsp+30h] [rbp-68h]
  unsigned int *v46; // [rsp+38h] [rbp-60h]
  unsigned int *v47; // [rsp+40h] [rbp-58h]
  hkpBroadPhaseHandle *v48; // [rsp+48h] [rbp-50h]
  unsigned __int64 v49; // [rsp+50h] [rbp-48h]
  hkResult result; // [rsp+A0h] [rbp+8h]
  int v51; // [rsp+A8h] [rbp+10h]
  int numNodes; // [rsp+B8h] [rbp+20h]

  v3 = this->m_nodes.m_size;
  queryNodeIndex = (signed int)object->m_id;
  v48 = object;
  v5 = delPairsOut;
  v6 = &this->m_nodes.m_data[queryNodeIndex];
  v7 = this;
  numNodes = v3;
  v8 = (v3 >> 5) + 8;
  if ( v3 >> 5 == -8 )
  {
    bitField = 0i64;
  }
  else
  {
    result.m_enum = 4 * v8;
    bitField = (unsigned int *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                 (int *)&result);
    v8 = result.m_enum / 4;
  }
  v10 = v7->m_axis;
  v11 = 2147483648;
  if ( v8 )
    v11 = v8;
  v12 = v10->m_endPoints.m_data[v6->min_x].m_value;
  v47 = bitField;
  v51 = v11;
  hkp3AxisSweep::setBitsBasedOnXInterval(v7, v3, v12, v6, queryNodeIndex, bitField);
  v13 = v7->m_nodes.m_data;
  v14 = bitField;
  v46 = bitField;
  v45 = v7->m_nodes.m_data;
  v15 = (unsigned __int64)&bitField[((signed __int64)v7->m_nodes.m_size >> 5) + 1];
  v49 = v15;
  if ( (unsigned __int64)bitField < v15 )
  {
    do
    {
      v16 = *v14;
      v17 = v13;
      if ( *v14 )
      {
        do
        {
          if ( (_BYTE)v16 )
          {
            if ( v16 & 1
              && !(((*(_DWORD *)&v17->max_y - *(_DWORD *)&v6->min_y) | (*(_DWORD *)&v6->max_y - *(_DWORD *)&v17->min_y)) & 0x80008000) )
            {
              if ( (_QWORD)v17->m_handle & 1 )
              {
                v20 = 0;
                v21 = 0i64;
                v22 = (unsigned __int64)v7->m_markers + ((_QWORD)v17->m_handle & 0xFFFFFFFFFFFFFFFEui64);
                v23 = *(signed int *)(v22 + 16);
                if ( (signed int)v23 <= 0 )
                {
LABEL_22:
                  v20 = -1;
                  v21 = -1i64;
                }
                else
                {
                  v24 = *(_WORD **)(v22 + 8);
                  while ( *v24 != (_WORD)queryNodeIndex )
                  {
                    ++v21;
                    ++v20;
                    ++v24;
                    if ( v21 >= v23 )
                      goto LABEL_22;
                  }
                }
                *(_DWORD *)(v22 + 16) = v23 - 1;
                if ( (_DWORD)v23 - 1 != v20 )
                  *(_WORD *)(*(_QWORD *)(v22 + 8) + 2 * v21) = *(_WORD *)(*(_QWORD *)(v22 + 8)
                                                                        + 2i64 * ((signed int)v23 - 1));
              }
              else
              {
                v18 = v17->m_handle;
                if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
                v19 = &v5->m_data[v5->m_size];
                if ( v19 )
                {
                  v19->m_a = v48;
                  v19->m_b = v18;
                }
                ++v5->m_size;
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
        v13 = v45;
        v15 = v49;
      }
      ++v14;
      v13 += 32;
      v45 = v13;
      v46 = v14;
    }
    while ( (unsigned __int64)v14 < v15 );
    v11 = v51;
    bitField = v47;
    v10 = v7->m_axis;
  }
  if ( v11 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      bitField,
      4 * v11);
  v25 = &v7->m_nodes;
  v26 = v7->m_nodes.m_data;
  hkp3AxisSweep::hkpBpAxis::remove(v10, v6->min_x, v6->max_x);
  hkp3AxisSweep::hkpBpAxis::remove(&v7->m_axis[1], v6->min_y, v6->max_y);
  hkp3AxisSweep::hkpBpAxis::remove(&v7->m_axis[2], v6->min_z, v6->max_z);
  v27 = numNodes;
  hkp3AxisSweep::updateNodesAfterDelete(v7, v26, numNodes, v6);
  if ( (unsigned int)queryNodeIndex < v27 - 1 )
  {
    v28 = &v25->m_data[v27 - 1];
    *(_QWORD *)&v6->min_y = *(_QWORD *)&v28->min_y;
    *(_QWORD *)&v6->min_x = *(_QWORD *)&v28->min_x;
    v6->m_handle = v28->m_handle;
    v7->m_axis[0].m_endPoints.m_data[v6->min_x].m_nodeIndex = queryNodeIndex;
    v7->m_axis[0].m_endPoints.m_data[v6->max_x].m_nodeIndex = queryNodeIndex;
    if ( (_QWORD)v6->m_handle & 1 )
    {
      *(unsigned __int16 *)((char *)&v7->m_markers->m_nodeIndex + ((_QWORD)v6->m_handle & 0xFFFFFFFFFFFFFFFEui64)) = queryNodeIndex;
    }
    else
    {
      v7->m_axis[1].m_endPoints.m_data[v6->min_y].m_nodeIndex = queryNodeIndex;
      v7->m_axis[1].m_endPoints.m_data[v6->max_y].m_nodeIndex = queryNodeIndex;
      v7->m_axis[2].m_endPoints.m_data[v6->min_z].m_nodeIndex = queryNodeIndex;
      v7->m_axis[2].m_endPoints.m_data[v6->max_z].m_nodeIndex = queryNodeIndex;
      v6->m_handle->m_id = queryNodeIndex;
    }
    if ( v7->m_numMarkers && !((_QWORD)v6->m_handle & 1) )
    {
      v29 = v6->min_x;
      v30 = v7->m_axis[0].m_endPoints.m_data;
      v31 = 16 - LOBYTE(v7->m_ld2NumMarkers);
      LODWORD(v32) = (unsigned int)v30[v29].m_value >> v31;
      if ( (signed int)v32 > 0
        && v25->m_data[v7->m_markers[(signed int)v32 - 1].m_nodeIndex].max_x > (unsigned __int16)v29 )
      {
        LODWORD(v32) = v32 - 1;
      }
      v32 = (signed int)v32;
      v33 = ((unsigned int)v30[v6->max_x].m_value >> v31) - 1;
      if ( (signed int)v32 <= (signed __int64)v33 )
      {
        v34 = v32;
        v35 = v33 - v32 + 1;
        do
        {
          v36 = v7->m_markers;
          v37 = 0i64;
          v38 = v36[v34].m_overlappingObjects.m_size;
          if ( v38 <= 0 )
          {
LABEL_47:
            v37 = -1i64;
          }
          else
          {
            v39 = v36[v34].m_overlappingObjects.m_data;
            while ( *v39 != (_WORD)v27 - 1 )
            {
              ++v37;
              ++v39;
              if ( v37 >= v38 )
                goto LABEL_47;
            }
          }
          v40 = v36[v34].m_overlappingObjects.m_data;
          ++v34;
          v40[v37] = queryNodeIndex;
          --v35;
        }
        while ( v35 );
      }
    }
    hkp3AxisSweep::_fixDeterministicOrderAfterNodeIdWasDecreased(v7, queryNodeIndex);
  }
  v41 = v27 - 1;
  v42 = v7->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v42 < v27 - 1 )
  {
    v43 = 2 * v42;
    v44 = v27 - 1;
    if ( v41 < v43 )
      v44 = v43;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_nodes, v44, 24);
  }
  v7->m_nodes.m_size = v41;
}

// File Line: 2095
// RVA: 0xD05720
signed __int64 __fastcall hkp3AxisSweep::hkpBpAxis::insertTail(hkp3AxisSweep::hkpBpAxis *this, hkp3AxisSweep::hkpBpNode *nodes, int axis, hkp3AxisSweep::hkpBpEndPoint *newNodes, int numNewEndPoints)
{
  __int64 v5; // r14
  __int64 v6; // rbp
  int v7; // edi
  int v8; // eax
  hkp3AxisSweep::hkpBpEndPoint *v9; // r15
  __int64 v10; // r12
  hkp3AxisSweep::hkpBpNode *v11; // rsi
  hkp3AxisSweep::hkpBpAxis *v12; // rbx
  int v13; // eax
  int v14; // er9
  signed int v15; // er10
  int v18; // ecx
  unsigned __int16 *v19; // r11
  signed __int64 v20; // r9
  char *v21; // rax
  signed int v22; // ebp
  signed int v24; // ecx

  v5 = this->m_endPoints.m_size;
  v6 = numNewEndPoints;
  v7 = v5 + numNewEndPoints;
  v8 = this->m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = newNodes;
  v10 = axis;
  v11 = nodes;
  v12 = this;
  if ( v8 < (signed int)v5 + numNewEndPoints )
  {
    v13 = 2 * v8;
    v14 = v5 + numNewEndPoints;
    if ( v7 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      (hkResult *)&numNewEndPoints,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      this,
      v14,
      4);
  }
  v12->m_endPoints.m_size = v7;
  v15 = v9[v6 - 1].m_value;
  _R11 = (signed __int64)&v12->m_endPoints.m_data[v5];
  _RAX = (signed __int64)&v12->m_endPoints.m_data[v7];
  __asm
  {
    prefetchnta byte ptr [rax-4]; Prefetch to L1 cache
    prefetchnta byte ptr [rax-204h]; Prefetch to L1 cache
    prefetchnta byte ptr [r11-4]; Prefetch to L1 cache
    prefetchnta byte ptr [rax-204h]; Prefetch to L1 cache
  }
  v18 = *(_DWORD *)(_R11 - 4);
  v19 = (unsigned __int16 *)(_R11 - 8);
  *(_DWORD *)(_RAX - 4) = v18;
  v20 = (signed __int64)(unsigned int)(_RAX - 4 - LODWORD(v12->m_endPoints.m_data)) >> 2;
  v21 = (char *)(_RAX - 8);
  v22 = v15;
  *(unsigned __int16 *)((char *)&v11[v19[3]].min_y + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2 * v10 + (v19[2] & 1)]) = v20;
  if ( *v19 > v15 )
  {
    _R10 = (signed __int64)(v19 - 256);
    do
    {
      *(_DWORD *)v21 = *(_DWORD *)v19;
      __asm { prefetchnta byte ptr [r10]; Prefetch to L1 cache }
      *(unsigned __int16 *)((char *)&v11[*(unsigned __int16 *)(_R10 + 514)].min_y
                          + hkp3AxisSweep::hkpBpNode::s_memberOffsets[2 * v10 + (*v19 & 1)]) = (signed __int64)(unsigned int)((_DWORD)v21 - LODWORD(v12->m_endPoints.m_data)) >> 2;
      __asm { prefetchnta byte ptr [r10]; Prefetch to L1 cache }
      v24 = *(v19 - 2);
      v19 -= 2;
      v21 -= 4;
      _R10 -= 4i64;
    }
    while ( v24 > v22 );
  }
  return ((v21 - (char *)v12->m_endPoints.m_data) >> 2) + 1;
}

// File Line: 2135
// RVA: 0xD06E10
void __fastcall hkp3AxisSweep::hkpBpAxis::mergeRest<2>(hkp3AxisSweep::hkpBpAxis *this, hkp3AxisSweep::hkpBpNode *nodes, int startOfTail, hkp3AxisSweep::hkpBpEndPoint *newEndPoints, int numNewEndPoints)
{
  hkp3AxisSweep::hkpBpEndPoint *v5; // rbp
  hkp3AxisSweep::hkpBpEndPoint *v6; // rax
  int v7; // er9
  hkp3AxisSweep::hkpBpEndPoint *v8; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v9; // r10
  int v10; // er11
  int v11; // edi
  hkp3AxisSweep::hkpBpEndPoint v12; // ecx
  hkp3AxisSweep::hkpBpEndPoint v13; // ecx

  v5 = newEndPoints;
  v6 = &newEndPoints[numNewEndPoints - 1];
  v7 = startOfTail - 1;
  v8 = &this->m_endPoints.m_data[startOfTail - numNewEndPoints - 1];
  v9 = &this->m_endPoints.m_data[startOfTail - 1];
  v10 = v6->m_value;
LABEL_2:
  v11 = v8->m_value;
  while ( 1 )
  {
    if ( v11 > v10 )
    {
      v12 = *v8;
      --v8;
      --v9;
      v9[1] = v12;
      *(unsigned __int16 *)((char *)&nodes[v8[1].m_nodeIndex].min_y
                          + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(v8[1].m_value & 1) + 4]) = v7--;
      goto LABEL_2;
    }
    v13 = *v6;
    --v6;
    --v9;
    v9[1] = v13;
    *(unsigned __int16 *)((char *)&nodes[v6[1].m_nodeIndex].min_y
                        + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(v6[1].m_value & 1) + 4]) = v7--;
    if ( v6 < v5 )
      break;
    v10 = v6->m_value;
  }
}

// File Line: 2181
// RVA: 0xCFD0B0
void __fastcall hkp3AxisSweep::addObjectBatch(hkp3AxisSweep *this, hkArrayBase<hkpBroadPhaseHandle *> *addObjectList, hkArrayBase<hkAabb> *addAabbList, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs)
{
  hkArrayBase<hkAabb> *v4; // rdi
  hkArrayBase<hkpBroadPhaseHandle *> *v5; // rsi
  hkp3AxisSweep *v6; // rbx
  int v7; // er12
  __int64 v8; // r13
  int v9; // er15
  int v10; // er14
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // ecx
  hkArray<hkp3AxisSweep::hkpBpNode,hkContainerHeapAllocator> *v17; // r12
  int v18; // er9
  int v19; // eax
  int v20; // eax
  __m128 v21; // xmm9
  __m128 v22; // xmm8
  int v23; // ebx
  signed __int64 v24; // r8
  __int64 v25; // r14
  signed __int64 v26; // r9
  hkp3AxisSweep::hkpBpEndPoint *v27; // r10
  signed __int64 v28; // r11
  char *v29; // rcx
  __m128 v30; // xmm0
  __m128i v31; // xmm1
  __m128 v32; // xmm0
  __m128 v33; // xmm0
  __m128i v34; // xmm6
  int *v35; // rdx
  unsigned __int16 v36; // ax
  unsigned __int16 v37; // ax
  unsigned __int16 v38; // ax
  unsigned __int16 v39; // ax
  unsigned __int16 v40; // ax
  unsigned __int16 v41; // ax
  hkp3AxisSweep *v42; // r9
  int v43; // ebx
  int v44; // eax
  _DWORD *v45; // rax
  _DWORD *v46; // r13
  hkResultEnum v47; // ecx
  int v48; // ebx
  _OWORD *v49; // rcx
  _OWORD *v50; // rax
  __m128 v51; // xmm0
  hkp3AxisSweep::hkpBpAxis *v52; // rdi
  hkp3AxisSweep::hkpBpEndPoint *v53; // r8
  __m128 v54; // xmm0
  __m128i v55; // xmm1
  __m128 v56; // xmm0
  unsigned int v57; // er10
  __m128 v58; // xmm0
  __m128i v59; // xmm6
  unsigned int v60; // er11
  bool v61; // zf
  signed int v62; // edx
  hkp3AxisSweep::hkpBpMarker *v63; // rbx
  unsigned __int16 *v64; // r8
  int i; // er9
  int v66; // ecx
  signed __int64 v67; // rbx
  unsigned __int64 v68; // r8
  unsigned __int64 j; // r9
  int v70; // ecx
  unsigned int v71; // eax
  hkp3AxisSweep::hkpBpEndPoint *v72; // rsi
  __int64 v73; // rax
  signed __int64 v74; // rbx
  signed __int64 v75; // rax
  hkp3AxisSweep::hkpBpEndPoint *v76; // rsi
  signed __int64 v77; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v78; // rax
  unsigned int *v79; // rbx
  hkp3AxisSweep::hkpBpNode *v80; // rcx
  unsigned __int64 v81; // rsi
  hkResultEnum v82; // er9
  hkResultEnum v83; // er10
  signed __int64 v84; // rdi
  unsigned int v85; // er8
  signed __int64 v86; // rax
  int v87; // er9
  int v88; // eax
  int v89; // eax
  hkp3AxisSweep::hkpBpNode *v90; // r13
  signed __int64 v91; // rbx
  hkp3AxisSweep::hkpBpAxis *v92; // r14
  int v93; // ebx
  hkResult *v94; // rdi
  hkp3AxisSweep::hkpBpEndPoint **v95; // rsi
  int v96; // eax
  __int64 v97; // r8
  __int64 v98; // r9
  int v99; // eax
  hkp3AxisSweep::hkpBpNode *v100; // rax
  signed __int64 v101; // rdx
  int v102; // edx
  hkp3AxisSweep::hkpBpAxis *v103; // r15
  signed int v104; // er13
  __int32 v105; // ebx
  int v106; // eax
  hkRadixSort::SortData16 *v107; // r14
  signed int v108; // edi
  hkp3AxisSweep::hkpBpAxis *v109; // r10
  signed int v110; // esi
  int v111; // er8
  __int16 v112; // r15
  hkRadixSort::SortData16 *v113; // rdx
  signed __int64 v114; // r9
  unsigned __int16 v115; // ax
  unsigned __int16 *v116; // r9
  hkp3AxisSweep::hkpBpAxis *v117; // r8
  __int64 v118; // r10
  __int64 v119; // rax
  hkp3AxisSweep::hkpBpNode *v120; // rdx
  int v121; // ebx
  __int32 v122; // edx
  __int32 v123; // edi
  signed int v124; // er15
  int v125; // eax
  hkRadixSort::SortData16 *v126; // rbx
  signed int v127; // esi
  int v128; // er10
  hkp3AxisSweep::hkpBpNode *v129; // r11
  signed int v130; // er14
  __int64 v131; // r9
  __int64 v132; // rdi
  __int64 v133; // r8
  __int64 v134; // rcx
  hkRadixSort::SortData16 *v135; // r8
  unsigned __int16 *v136; // r9
  hkp3AxisSweep::hkpBpAxis *v137; // r8
  __int64 v138; // r10
  __int64 v139; // rax
  hkp3AxisSweep::hkpBpNode *v140; // rdx
  signed __int64 v141; // rax
  hkp3AxisSweep::hkpBpNode *v142; // rdi
  hkp3AxisSweep::hkpBpNode *v143; // rbx
  hkResult v144; // [rsp+40h] [rbp-C0h]
  int numB; // [rsp+44h] [rbp-BCh]
  _QWORD *array; // [rsp+48h] [rbp-B8h]
  int v147; // [rsp+50h] [rbp-B0h]
  int v148; // [rsp+54h] [rbp-ACh]
  __int64 v149; // [rsp+60h] [rbp-A0h]
  int v150; // [rsp+70h] [rbp-90h]
  hkp3AxisSweep::hkpBpAxis *v151; // [rsp+78h] [rbp-88h]
  hkResult result[2]; // [rsp+80h] [rbp-80h]
  int startOfTail; // [rsp+88h] [rbp-78h]
  hkp3AxisSweep::hkpBpAxis *v154; // [rsp+A0h] [rbp-60h]
  hkp3AxisSweep::hkpBpAxis *v155; // [rsp+A8h] [rbp-58h]
  int v156; // [rsp+B0h] [rbp-50h]
  int v157; // [rsp+B4h] [rbp-4Ch]
  int v158; // [rsp+B8h] [rbp-48h]
  int v159; // [rsp+C0h] [rbp-40h]
  int v160; // [rsp+C4h] [rbp-3Ch]
  int v161; // [rsp+C8h] [rbp-38h]
  int v162; // [rsp+D0h] [rbp-30h]
  int v163; // [rsp+D4h] [rbp-2Ch]
  int v164; // [rsp+D8h] [rbp-28h]
  hkp3AxisSweep::hkpBpEndPoint *v165; // [rsp+E0h] [rbp-20h]
  hkp3AxisSweep::hkpBpEndPoint *newEndPoints; // [rsp+E8h] [rbp-18h]
  hkp3AxisSweep::hkpBpEndPoint *v167; // [rsp+F0h] [rbp-10h]
  int v168; // [rsp+F8h] [rbp-8h]
  int v169; // [rsp+FCh] [rbp-4h]
  int v170; // [rsp+100h] [rbp+0h]
  hkp3AxisSweep::hkpBpEndPoint *pArr; // [rsp+108h] [rbp+8h]
  hkp3AxisSweep::hkpBpEndPoint *v172; // [rsp+110h] [rbp+10h]
  hkp3AxisSweep::hkpBpEndPoint *v173; // [rsp+118h] [rbp+18h]
  hkp3AxisSweep *v174; // [rsp+1A0h] [rbp+A0h]
  int numA; // [rsp+1B0h] [rbp+B0h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut; // [rsp+1B8h] [rbp+B8h]

  pairsOut = newPairs;
  v174 = this;
  v4 = addAabbList;
  v5 = addObjectList;
  v6 = this;
  if ( addAabbList->m_size >= 1 )
  {
    v7 = this->m_nodes.m_size;
    v8 = addObjectList->m_size;
    v9 = 2 * v8;
    v10 = 0;
    numB = this->m_nodes.m_size;
    numA = v8;
    v144.m_enum = 2 * v8;
    v11 = 2 * v8;
    if ( 2 * (_DWORD)v8 )
    {
      v156 = 8 * v8;
      newEndPoints = (hkp3AxisSweep::hkpBpEndPoint *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                                       &v156);
      v11 = v156 / 4;
    }
    else
    {
      newEndPoints = 0i64;
    }
    v12 = 2147483648;
    if ( v11 )
      v12 = v11;
    v13 = 2 * v8;
    v169 = v12;
    if ( v9 )
    {
      v158 = 8 * v8;
      v165 = (hkp3AxisSweep::hkpBpEndPoint *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                               (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                               &v158);
      v13 = v158 / 4;
    }
    else
    {
      v165 = 0i64;
    }
    v14 = 2147483648;
    if ( v13 )
      v14 = v13;
    v15 = 2 * v8;
    v168 = v14;
    if ( v9 )
    {
      v157 = 8 * v8;
      v167 = (hkp3AxisSweep::hkpBpEndPoint *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                               (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                               &v157);
      v15 = v157 / 4;
    }
    else
    {
      v167 = 0i64;
    }
    v16 = 2147483648;
    array = 0i64;
    if ( v15 )
      v16 = v15;
    v147 = 0;
    v148 = 2147483648;
    v170 = v16;
    if ( v7 > 0 )
    {
      hkArrayUtil::_reserve(result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v7, 8);
      v10 = v147;
    }
    v17 = &v6->m_nodes;
    v18 = v8 + v6->m_nodes.m_size;
    v19 = v6->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v19 < v18 )
    {
      v20 = 2 * v19;
      if ( v18 < v20 )
        v18 = v20;
      hkArrayUtil::_reserve(
        result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_nodes,
        v18,
        24);
      v10 = v147;
    }
    v6->m_nodes.m_size += v8;
    v21 = (__m128)xmmword_141A712A0;
    v172 = v165;
    v173 = v167;
    pArr = newEndPoints;
    v22 = _mm_xor_ps(
            (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
            (__m128)xmmword_141A712A0);
    if ( v8 > 0 )
    {
      v23 = numB;
      v24 = (char *)v165 - (char *)newEndPoints;
      v25 = 0i64;
      v26 = (char *)v167 - (char *)newEndPoints;
      v27 = newEndPoints + 1;
      v28 = -4i64 - (_QWORD)newEndPoints;
      do
      {
        v29 = (char *)v27 + v28;
        v27 += 2;
        ++v25;
        v21 = _mm_min_ps(v21, v4->m_data[v25 - 1].m_min.m_quad);
        v22 = _mm_max_ps(v22, *((__m128 *)&v4->m_data[v25] - 1));
        v30 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(v4->m_data[v25 - 1].m_min.m_quad, v174->m_offsetLow.m_quad),
                    v174->m_scale.m_quad),
                  hkp3AxisSweep::MaxVal),
                (__m128)0i64);
        v31 = _mm_sub_epi32(
                _mm_xor_si128(
                  (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v30),
                  _mm_cvttps_epi32(v30)),
                (__m128i)_xmm);
        v32 = _mm_min_ps(
                _mm_mul_ps(
                  _mm_add_ps(*((__m128 *)&v4->m_data[v25] - 1), v174->m_offsetHigh.m_quad),
                  v174->m_scale.m_quad),
                hkp3AxisSweep::MaxVal);
        *(_QWORD *)&result[0].m_enum = (unsigned __int128)_mm_add_epi16(
                                                            _mm_packs_epi32(v31, v31),
                                                            (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
        v159 = result[0].m_enum & 0xFFFE;
        v33 = _mm_max_ps(v32, (__m128)0i64);
        v160 = HIWORD(result[0].m_enum) & 0xFFFE;
        v161 = result[1].m_enum & 0xFFFE;
        v34 = _mm_sub_epi32(
                _mm_xor_si128(
                  (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v33),
                  _mm_cvttps_epi32(v33)),
                (__m128i)_xmm);
        v149 = (unsigned __int128)_mm_add_epi16(
                                    _mm_packs_epi32(v34, v34),
                                    (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
        v162 = (unsigned __int16)v149 | 1;
        v163 = WORD1(v149) | 1;
        v164 = WORD2(v149) | 1;
        v35 = *(int **)&v29[(unsigned __int64)v5->m_data];
        v17->m_data[v23].m_handle = (hkpBroadPhaseHandle *)v35;
        v36 = v159;
        *v35 = v23;
        v27[-3].m_value = v36;
        v37 = v162;
        v27[-3].m_nodeIndex = v23;
        v27[-2].m_value = v37;
        v38 = v160;
        v27[-2].m_nodeIndex = v23;
        *(unsigned __int16 *)((char *)&v27[-3].m_value + v24) = v38;
        v39 = v163;
        *(_WORD *)((char *)&v27[-2] + v24 - 2) = v23;
        *(unsigned __int16 *)((char *)&v27[-2].m_value + v24) = v39;
        v40 = v161;
        *(_WORD *)((char *)&v27[-1] + v24 - 2) = v23;
        *(unsigned __int16 *)((char *)&v27[-3].m_value + v26) = v40;
        v41 = v164;
        *(_WORD *)((char *)&v27[-2] + v26 - 2) = v23;
        *(_WORD *)((char *)&v27[-1] + v26 - 2) = v23;
        *(unsigned __int16 *)((char *)&v27[-2].m_value + v26) = v41;
        ++v23;
        --v8;
      }
      while ( v8 );
      v10 = v147;
      v9 = v144.m_enum;
    }
    v42 = v174;
    v17->m_size = numB;
    v43 = v174->m_nodes.m_size;
    v44 = (v174->m_nodes.m_size >> 5) + 8;
    if ( v174->m_nodes.m_size >> 5 == -8 )
    {
      v46 = 0i64;
    }
    else
    {
      v150 = 4 * v44;
      v45 = (_DWORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                        &v150);
      v10 = v147;
      v42 = v174;
      v46 = v45;
      v44 = v150 / 4;
    }
    v47 = 2147483648;
    if ( v44 )
      v47 = v44;
    v48 = v43 >> 7;
    v144.m_enum = v47;
    v49 = v46;
    if ( v48 >= 0 )
    {
      do
      {
        v50 = v49;
        ++v49;
        --v48;
        *v50 = 0i64;
      }
      while ( v48 >= 0 );
      v10 = v147;
    }
    v51 = v42->m_offsetLow.m_quad;
    v52 = v42->m_axis;
    v155 = v42->m_axis;
    v53 = v42->m_axis[0].m_endPoints.m_data + 1;
    v54 = _mm_max_ps(
            _mm_min_ps(_mm_mul_ps(_mm_add_ps(v51, v21), v42->m_scale.m_quad), hkp3AxisSweep::MaxVal),
            (__m128)0i64);
    v55 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v54),
              _mm_cvttps_epi32(v54)),
            (__m128i)_xmm);
    v56 = _mm_min_ps(_mm_mul_ps(_mm_add_ps(v42->m_offsetHigh.m_quad, v22), v42->m_scale.m_quad), hkp3AxisSweep::MaxVal);
    *(_QWORD *)&result[0].m_enum = (unsigned __int128)_mm_add_epi16(
                                                        _mm_packs_epi32(v55, v55),
                                                        (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
    v57 = result[0].m_enum & 0xFFFE;
    v160 = HIWORD(result[0].m_enum) & 0xFFFE;
    v58 = _mm_max_ps(v56, (__m128)0i64);
    v161 = result[1].m_enum & 0xFFFE;
    v59 = _mm_sub_epi32(
            _mm_xor_si128(
              (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v58),
              _mm_cvttps_epi32(v58)),
            (__m128i)_xmm);
    v149 = (unsigned __int128)_mm_add_epi16(
                                _mm_packs_epi32(v59, v59),
                                (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
    v60 = (unsigned __int16)v149 | 1;
    v163 = WORD1(v149) | 1;
    v61 = v42->m_numMarkers == 0;
    v164 = WORD2(v149) | 1;
    if ( !v61 )
    {
      v62 = (signed int)v57 >> (16 - LOBYTE(v42->m_ld2NumMarkers));
      if ( v62 > 0 )
      {
        v63 = &v42->m_markers[v62 - 1];
        v46[(signed int)v63->m_nodeIndex >> 5] ^= 1 << (v63->m_nodeIndex & 0x1F);
        v64 = v63->m_overlappingObjects.m_data;
        for ( i = v63->m_overlappingObjects.m_size - 1; i >= 0; --i )
        {
          v66 = *v64;
          ++v64;
          v46[v66 >> 5] ^= 1 << (v66 & 0x1F);
        }
        v67 = (signed __int64)&v17->m_data[v63->m_nodeIndex];
        v68 = (unsigned __int64)&v52->m_endPoints.m_data[*(unsigned __int16 *)(v67 + 8) + 1];
        for ( j = (unsigned __int64)&v52->m_endPoints.m_data[*(unsigned __int16 *)(v67 + 10)]; v68 < j; v68 += 4i64 )
        {
          if ( !(*(_BYTE *)v68 & 1) )
            v46[(signed int)*(unsigned __int16 *)(v68 + 2) >> 5] &= ~(1 << (*(_WORD *)(v68 + 2) & 0x1F));
        }
        v10 = v147;
        v42 = v174;
        v53 = &v52->m_endPoints.m_data[*(unsigned __int16 *)(v67 + 8) + 1];
      }
    }
    if ( v53->m_value < v57 )
    {
      do
      {
        v70 = v53->m_nodeIndex;
        ++v53;
        v46[v70 >> 5] ^= 1 << (v70 & 0x1F);
      }
      while ( v53->m_value < v57 );
      v10 = v147;
    }
    v71 = v53->m_value;
    if ( v71 < v60 )
    {
      do
      {
        if ( !(v71 & 1) )
          v46[(signed int)v53->m_nodeIndex >> 5] ^= 1 << (v53->m_nodeIndex & 0x1F);
        v71 = v53[1].m_value;
        ++v53;
      }
      while ( v71 < v60 );
      v10 = v147;
    }
    v72 = v42->m_axis[1].m_endPoints.m_data;
    v73 = v42->m_axis[1].m_endPoints.m_size;
    v151 = &v42->m_axis[1];
    v74 = (signed __int64)&v72[v73];
    LOWORD(result[0].m_enum) = hkp3AxisSweep::hkpBpAxis::find(
                                 &v42->m_axis[1],
                                 v72 + 1,
                                 (hkp3AxisSweep::hkpBpEndPoint *)(v74 - 8),
                                 v160)
                             - v72;
    v75 = (signed __int64)((char *)hkp3AxisSweep::hkpBpAxis::find(
                                     v151,
                                     v72 + 1,
                                     (hkp3AxisSweep::hkpBpEndPoint *)(v74 - 8),
                                     v163)
                         - 4i64
                         - (_QWORD)v72) >> 2;
    v76 = v174->m_axis[2].m_endPoints.m_data;
    LOWORD(result[1].m_enum) = v75;
    v77 = (signed __int64)&v76[v174->m_axis[2].m_endPoints.m_size];
    v154 = &v174->m_axis[2];
    HIWORD(result[0].m_enum) = hkp3AxisSweep::hkpBpAxis::find(
                                 &v174->m_axis[2],
                                 v76 + 1,
                                 (hkp3AxisSweep::hkpBpEndPoint *)(v77 - 8),
                                 v161)
                             - v76;
    v78 = hkp3AxisSweep::hkpBpAxis::find(v154, v76 + 1, (hkp3AxisSweep::hkpBpEndPoint *)(v77 - 8), v164);
    v79 = v46;
    v80 = v17->m_data;
    HIWORD(result[1].m_enum) = (signed __int64)((char *)v78 - 4i64 - (_QWORD)v76) >> 2;
    v81 = (unsigned __int64)&v46[((signed __int64)v174->m_nodes.m_size >> 5) + 1];
    if ( (unsigned __int64)v46 < v81 )
    {
      v82 = result[1].m_enum;
      v83 = result[0].m_enum;
      v84 = (signed __int64)&v80[2].max_y;
      do
      {
        v85 = *v79;
        if ( *v79 )
        {
          v86 = v84;
          do
          {
            if ( v85 & 0xF )
            {
              if ( v85 & 1
                && !(((v82 - *(_DWORD *)(v86 - 52)) | (*(_DWORD *)(v86 - 48) - v83)) & 0x80008000)
                && !(*(_BYTE *)(v86 - 36) & 1) )
              {
                array[v10] = v86 - 52;
                v10 = v147++ + 1;
              }
              if ( v85 & 2
                && !(((v82 - *(_DWORD *)(v86 - 28)) | (*(_DWORD *)(v86 - 24) - v83)) & 0x80008000)
                && !(*(_BYTE *)(v86 - 12) & 1) )
              {
                array[v10] = v86 - 28;
                v10 = v147++ + 1;
              }
              if ( v85 & 4
                && !(((v82 - *(_DWORD *)(v86 - 4)) | (*(_DWORD *)v86 - v83)) & 0x80008000)
                && !(*(_BYTE *)(v86 + 12) & 1) )
              {
                array[v10] = v86 - 4;
                v10 = v147++ + 1;
              }
              if ( v85 & 8
                && !(((v82 - *(_DWORD *)(v86 + 20)) | (*(_DWORD *)(v86 + 24) - v83)) & 0x80008000)
                && !(*(_BYTE *)(v86 + 36) & 1) )
              {
                array[v10] = v86 + 20;
                v10 = v147++ + 1;
              }
            }
            v85 >>= 4;
            v86 += 96i64;
          }
          while ( v85 );
        }
        ++v79;
        v84 += 768i64;
      }
      while ( (unsigned __int64)v79 < v81 );
    }
    if ( (signed int)v144.m_enum >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v46,
        4 * v144.m_enum);
    v87 = numA + v17->m_size;
    v88 = v17->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v88 < v87 )
    {
      v89 = 2 * v88;
      if ( v87 < v89 )
        v87 = v89;
      hkArrayUtil::_reserve(&v144, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v17, v87, 24);
    }
    v17->m_size += numA;
    v90 = v17->m_data;
    v91 = 0i64;
    do
    {
      if ( v9 > 1 )
        hkAlgorithm::quickSortRecursive<hkp3AxisSweep::hkpBpEndPoint,hkAlgorithm::less<hkp3AxisSweep::hkpBpEndPoint>>(
          (&pArr)[v91],
          0,
          v9 - 1,
          0);
      ++v91;
    }
    while ( v91 < 3 );
    v92 = v155;
    v93 = 0;
    v94 = result;
    v95 = &pArr;
    do
    {
      v96 = hkp3AxisSweep::hkpBpAxis::insertTail(v92, v90, v93++, *v95, v9);
      ++v92;
      v94->m_enum = v96;
      ++v94;
      ++v95;
    }
    while ( v93 < 3 );
    hkp3AxisSweep::hkpBpAxis::mergeRest<0>(v155, v90, result[0].m_enum, newEndPoints, v9);
    hkp3AxisSweep::hkpBpAxis::mergeRest<1>(v151, v90, result[1].m_enum, v165, v9);
    hkp3AxisSweep::hkpBpAxis::mergeRest<2>(v154, v90, startOfTail, v167, v9);
    v99 = v174->m_numMarkers;
    if ( v99 )
    {
      v98 = 0i64;
      if ( v99 > 0 )
      {
        v97 = 0i64;
        do
        {
          v98 = (unsigned int)(v98 + 1);
          ++v97;
          v100 = v17->m_data;
          v101 = v174->m_markers[v97 - 1].m_nodeIndex;
          v100[v101].max_y += v9;
          v100[v101].max_z += v9;
        }
        while ( (signed int)v98 < v174->m_numMarkers );
      }
    }
    v102 = numA + 1;
    if ( numA == -1 )
    {
      v103 = 0i64;
    }
    else
    {
      v150 = 24 * v102;
      v103 = (hkp3AxisSweep::hkpBpAxis *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, __int64, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                           &hkContainerTempAllocator::s_alloc,
                                           &v150,
                                           v97 * 24,
                                           v98);
      v102 = v150 / 24;
    }
    v104 = 2147483648;
    v155 = v103;
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
      LODWORD(v149) = 4 * v105;
      v107 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                          (int *)&v149);
      v106 = (signed int)v149 / 4;
    }
    v108 = 2147483648;
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
                                           (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                           (int *)result);
      v105 = result[0].m_enum / 4;
    }
    v110 = 2147483648;
    if ( v105 )
      v110 = v105;
    v111 = 0;
    v151 = v109;
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
        ++v114;
        v113[-1].m_key = *((_WORD *)&v17->m_data[v114] - 8);
      }
      while ( v111 < numA );
      v103 = v155;
    }
    v107[numA].m_key = -1;
    v107[numA + 1].m_key = -1;
    v107[numA + 2].m_key = -1;
    hkRadixSort::sort16(v107, (numA + 3) & 0xFFFFFFFC, (hkRadixSort::SortData16 *)v109);
    if ( numA > 0i64 )
    {
      v117 = v103;
      v116 = &v107->m_userData;
      v118 = numA;
      do
      {
        v119 = *v116;
        v117 = (hkp3AxisSweep::hkpBpAxis *)((char *)v117 + 24);
        v116 += 2;
        v120 = &v17->m_data[v119];
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
        v151,
        (unsigned int)(4 * v110),
        v116);
    if ( v108 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v107,
        (unsigned int)(4 * v108),
        v116);
    v121 = v147;
    numB = v147;
    v122 = v147 + 1;
    if ( v147 == -1 )
    {
      v154 = 0i64;
    }
    else
    {
      result[0].m_enum = 24 * v122;
      v154 = (hkp3AxisSweep::hkpBpAxis *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, hkResult *, hkMemoryAllocatorVtbl *, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                           &hkContainerTempAllocator::s_alloc,
                                           result,
                                           hkContainerTempAllocator::s_alloc.vfptr,
                                           v116);
      v122 = result[0].m_enum / 24;
    }
    v123 = v121 + 4;
    v124 = 2147483648;
    if ( v122 )
      v124 = v122;
    v125 = v121 + 4;
    if ( v121 == -4 )
    {
      v126 = 0i64;
    }
    else
    {
      LODWORD(v149) = 4 * v123;
      v126 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                          (int *)&v149);
      v125 = (signed int)v149 / 4;
    }
    v127 = 2147483648;
    if ( v125 )
      v127 = v125;
    if ( v123 )
    {
      v144.m_enum = 4 * v123;
      v151 = (hkp3AxisSweep::hkpBpAxis *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                           (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                           (int *)&v144);
      v123 = v144.m_enum / 4;
    }
    else
    {
      v151 = 0i64;
    }
    v128 = numB;
    v129 = v17->m_data;
    v130 = 2147483648;
    if ( v123 )
      v130 = v123;
    v131 = 0i64;
    v132 = numB;
    if ( numB > 0 )
    {
      do
      {
        v133 = array[++v131 - 1];
        v134 = array[v131 - 1] - (_QWORD)v129;
        *((_WORD *)&v126[v131] - 1) = ((unsigned __int64)((unsigned __int128)(v134
                                                                            * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                                    + ((signed __int64)((unsigned __int128)(v134
                                                                          * (signed __int128)3074457345618258603i64) >> 64) >> 2);
        v126[v131 - 1].m_key = *(_WORD *)(v133 + 8);
      }
      while ( v131 < v132 );
      v128 = numB;
    }
    v135 = (hkRadixSort::SortData16 *)v151;
    v126[v132].m_key = -1;
    v126[v132 + 1].m_key = -1;
    v126[v132 + 2].m_key = -1;
    hkRadixSort::sort16(v126, (v128 + 3) & 0xFFFFFFFC, v135);
    if ( v132 > 0 )
    {
      v137 = v154;
      v136 = &v126->m_userData;
      v138 = v132;
      do
      {
        v139 = *v136;
        v137 = (hkp3AxisSweep::hkpBpAxis *)((char *)v137 + 24);
        v136 += 2;
        v140 = &v17->m_data[v139];
        *(_QWORD *)&v137[-2].m_endPoints.m_size = *(_QWORD *)&v140->min_y;
        v137[-1].m_endPoints.m_data = *(hkp3AxisSweep::hkpBpEndPoint **)&v140->min_x;
        *(_QWORD *)&v137[-1].m_endPoints.m_size = v140->m_handle;
        --v138;
      }
      while ( v138 );
    }
    v141 = 3 * v132;
    v142 = (hkp3AxisSweep::hkpBpNode *)v154;
    *((_WORD *)&v154->m_endPoints.m_size + 4 * v141) = -1;
    if ( v130 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkp3AxisSweep::hkpBpAxis *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v151,
        (unsigned int)(4 * v130),
        v136);
    if ( v127 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        v126,
        (unsigned int)(4 * v127),
        v136);
    v143 = (hkp3AxisSweep::hkpBpNode *)v155;
    hkp3AxisSweep::collide1Axis(v174, (hkp3AxisSweep::hkpBpNode *)v155, numA, pairsOut);
    hkp3AxisSweep::collide1Axis(v174, v143, numA, v142, numB, 0, pairsOut);
    if ( v124 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v142,
        24 * (v124 & 0x3FFFFFFF));
    if ( v104 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v143,
        24 * (v104 & 0x3FFFFFFF));
    v147 = 0;
    if ( v148 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        8 * v148);
    array = 0i64;
    v148 = 2147483648;
    if ( v170 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v167,
        4 * v170);
    if ( v168 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v165,
        4 * v168);
    if ( v169 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        newEndPoints,
        4 * v169);
  }
}

// File Line: 2381
// RVA: 0xCFE5F0
void __fastcall hkp3AxisSweep::removeObjectBatch(hkp3AxisSweep *this, hkArrayBase<hkpBroadPhaseHandle *> *removeObjectList, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairsOut)
{
  __int64 v3; // r14
  int v4; // er13
  hkArrayBase<hkpBroadPhaseHandle *> *v5; // rbx
  int v6; // edx
  hkp3AxisSweep *v7; // rdi
  unsigned int v8; // eax
  int v9; // esi
  hkpBroadPhaseHandle **v10; // rax
  signed __int64 v11; // rcx
  hkp3AxisSweep::hkpBpNode *v12; // rax
  signed __int64 v13; // rdx
  int v14; // eax
  hkRadixSort::SortData16 *v15; // r15
  signed int v16; // edi
  __int64 v17; // r9
  unsigned __int16 v18; // r12
  unsigned __int16 v19; // r10
  unsigned __int16 v20; // r11
  unsigned __int16 v21; // r13
  unsigned __int16 v22; // di
  hkRadixSort::SortData16 *v23; // rsi
  __int64 v24; // rax
  __int64 v25; // rdx
  unsigned __int16 *v26; // r8
  unsigned __int16 v27; // ax
  unsigned __int16 v28; // ax
  unsigned __int16 v29; // ax
  unsigned __int16 v30; // ax
  unsigned __int16 v31; // ax
  unsigned __int16 v32; // ax
  hkRadixSort::SortData16 *v33; // r12
  signed int v34; // ebx
  unsigned __int16 *v35; // r9
  hkp3AxisSweep::hkpBpNode *v36; // rsi
  hkRadixSort::SortData16 *v37; // r11
  hkp3AxisSweep::hkpBpNode *v38; // r8
  __int64 v39; // r10
  __int64 v40; // rax
  _QWORD *v41; // rdx
  hkp3AxisSweep *v42; // r12
  int v43; // ebx
  int v44; // er9
  int v45; // er9
  int v46; // eax
  _DWORD *v47; // rsi
  unsigned int v48; // ecx
  int v49; // er14
  int v50; // eax
  hkRadixSort::SortData16 *v51; // r8
  int v52; // er9
  unsigned int v53; // ecx
  signed int v54; // edx
  __int16 v55; // r15
  __int16 v56; // r13
  _DWORD *v57; // r11
  signed __int64 v58; // r10
  hkRadixSort::SortData16 *v59; // rdi
  hkArray<hkp3AxisSweep::hkpBpNode,hkContainerHeapAllocator> *v60; // rax
  hkp3AxisSweep::hkpBpNode *v61; // rbx
  signed __int64 v62; // r8
  __int64 v63; // rax
  hkArray<hkp3AxisSweep::hkpBpNode,hkContainerHeapAllocator> *v64; // r13
  int v65; // ebx
  int v66; // eax
  int v67; // eax
  int v68; // er9
  __int32 v69; // edx
  unsigned __int16 v70; // bx
  unsigned int v71; // eax
  __int32 v72; // eax
  hkRadixSort::SortData16 *v73; // r15
  signed int v74; // ebx
  hkRadixSort::SortData16 *v75; // rax
  unsigned __int16 *v76; // r9
  hkp3AxisSweep::hkpBpNode *v77; // r8
  __int64 v78; // r10
  __int64 v79; // rax
  hkp3AxisSweep::hkpBpNode *v80; // rdx
  hkp3AxisSweep::hkpBpNode *v81; // rdi
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v82; // rbx
  int v83; // er15
  int sizeElem; // ST20_4
  hkp3AxisSweep::hkpBpNode *v85; // r14
  unsigned __int64 v86; // r9
  hkp3AxisSweep::hkpBpNode *v87; // r11
  unsigned __int64 v88; // r10
  int v89; // ebx
  unsigned __int64 v90; // r8
  __int64 v91; // rcx
  int v92; // eax
  int v93; // eax
  int v94; // er9
  unsigned __int64 v95; // r9
  hkp3AxisSweep::hkpBpNode *v96; // r11
  unsigned __int64 v97; // r10
  int v98; // ebx
  unsigned __int64 v99; // r8
  __int64 v100; // rcx
  int v101; // eax
  int v102; // eax
  int v103; // er9
  unsigned __int64 v104; // r9
  hkp3AxisSweep::hkpBpNode *v105; // r11
  unsigned __int64 v106; // r10
  int v107; // ebx
  unsigned __int64 v108; // r8
  __int64 v109; // rcx
  int v110; // eax
  int v111; // eax
  int v112; // er9
  int v113; // eax
  int v114; // er14
  __int16 v115; // r13
  __int64 v116; // r15
  int v117; // edx
  int v118; // ebx
  hkp3AxisSweep::hkpBpMarker *v119; // r11
  signed __int64 v120; // rcx
  hkp3AxisSweep::hkpBpNode *v121; // rax
  __int64 v122; // r8
  __int64 v123; // rcx
  unsigned __int16 *v124; // r9
  int v125; // er10
  signed __int64 v126; // rdi
  int v127; // eax
  int v128; // eax
  int v129; // er9
  int v130; // edi
  __int64 v131; // rbx
  int v132; // [rsp+40h] [rbp-59h]
  int numA; // [rsp+44h] [rbp-55h]
  int v134; // [rsp+48h] [rbp-51h]
  hkp3AxisSweep::hkpBpNode *pa; // [rsp+50h] [rbp-49h]
  int v136; // [rsp+58h] [rbp-41h]
  int v137; // [rsp+5Ch] [rbp-3Dh]
  int v138; // [rsp+60h] [rbp-39h]
  _DWORD *array; // [rsp+68h] [rbp-31h]
  int v140; // [rsp+70h] [rbp-29h]
  int v141; // [rsp+74h] [rbp-25h]
  hkRadixSort::SortData16 *data; // [rsp+78h] [rbp-21h]
  __int64 v143; // [rsp+80h] [rbp-19h]
  __int64 v144; // [rsp+88h] [rbp-11h]
  __int64 v145; // [rsp+90h] [rbp-9h]
  int v146; // [rsp+98h] [rbp-1h]
  hkp3AxisSweep::hkpBpNode *pb; // [rsp+A0h] [rbp+7h]
  int v148; // [rsp+A8h] [rbp+Fh]
  hkp3AxisSweep *result; // [rsp+100h] [rbp+67h]
  hkResult v150; // [rsp+108h] [rbp+6Fh]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut; // [rsp+110h] [rbp+77h]
  hkResult v152; // [rsp+118h] [rbp+7Fh]

  pairsOut = delPairsOut;
  result = this;
  v3 = removeObjectList->m_size;
  v4 = this->m_nodes.m_size;
  v5 = removeObjectList;
  v6 = v3 + 1;
  v7 = this;
  v138 = 0;
  numA = v3;
  v136 = v4;
  if ( (_DWORD)v3 == -1 )
  {
    pa = 0i64;
  }
  else
  {
    v146 = 24 * v6;
    pa = (hkp3AxisSweep::hkpBpNode *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                       &v146);
    v6 = v146 / 24;
  }
  v8 = 2147483648;
  v9 = v3 + 4;
  if ( v6 )
    v8 = v6;
  v137 = v3 + 4;
  v148 = v8;
  v10 = v5->m_data;
  data = (hkRadixSort::SortData16 *)&v7->m_nodes;
  v11 = (signed int)(*v10)->m_id;
  v12 = v7->m_nodes.m_data;
  v13 = (signed __int64)&v12[v11];
  v143 = *(_QWORD *)&v12[v11].min_y;
  v144 = *(_QWORD *)(v13 + 8);
  v145 = *(_QWORD *)(v13 + 16);
  v14 = v3 + 4;
  if ( (_DWORD)v3 == -4 )
  {
    v15 = 0i64;
  }
  else
  {
    v134 = 4 * v9;
    v15 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                       &v134);
    v14 = v134 / 4;
  }
  v16 = 2147483648;
  if ( v14 )
    v16 = v14;
  v17 = 0i64;
  v132 = v16;
  if ( v3 <= 0 )
  {
    LOWORD(v152.m_enum) = WORD1(v144);
    LOWORD(v150.m_enum) = v144;
  }
  else
  {
    v18 = WORD1(v144);
    v19 = HIWORD(v143);
    v21 = WORD2(v143);
    v20 = WORD1(v143);
    v22 = v143;
    v23 = data;
    LOWORD(v150.m_enum) = v144;
    do
    {
      v24 = *(_QWORD *)&v23->m_key;
      v25 = v5->m_data[v17]->m_id;
      v15[v17].m_userData = v25;
      v26 = (unsigned __int16 *)(v24 + 24 * v25);
      v15[v17].m_key = *(_WORD *)(v24 + 24 * v25 + 8);
      v27 = v26[4];
      if ( LOWORD(v150.m_enum) < v27 )
        v27 = v150.m_enum;
      LOWORD(v150.m_enum) = v27;
      v28 = *v26;
      if ( v22 < *v26 )
        v28 = v22;
      v22 = v28;
      v29 = v26[1];
      if ( v20 < v29 )
        v29 = v20;
      v20 = v29;
      v30 = v26[5];
      if ( v18 > v30 )
        v30 = v18;
      v18 = v30;
      v31 = v26[2];
      if ( v21 > v31 )
        v31 = v21;
      v21 = v31;
      v32 = v26[3];
      if ( v19 > v32 )
        v32 = v19;
      ++v17;
      v19 = v32;
    }
    while ( v17 < v3 );
    v9 = v137;
    WORD2(v143) = v21;
    v4 = v136;
    LOWORD(v143) = v22;
    v16 = v132;
    HIWORD(v143) = v32;
    WORD1(v143) = v20;
    LOWORD(v152.m_enum) = v18;
  }
  if ( v9 )
  {
    v132 = 4 * v9;
    v33 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                       &v132);
    v9 = v132 / 4;
  }
  else
  {
    v33 = 0i64;
  }
  v34 = 2147483648;
  if ( v9 )
    v34 = v9;
  v15[v3].m_key = -1;
  v15[v3 + 1].m_key = -1;
  v15[v3 + 2].m_key = -1;
  hkRadixSort::sort16(v15, (v3 + 3) & 0xFFFFFFFC, v33);
  v36 = pa;
  if ( v3 > 0 )
  {
    v37 = data;
    v38 = pa;
    v35 = &v15->m_userData;
    v39 = v3;
    do
    {
      v40 = *v35;
      v35 += 2;
      ++v38;
      v41 = (_QWORD *)(*(_QWORD *)&v37->m_key + 24 * v40);
      *(_QWORD *)&v38[-1].min_y = *v41;
      *(_QWORD *)&v38[-1].min_x = v41[1];
      v38[-1].m_handle = (hkpBroadPhaseHandle *)v41[2];
      *(_DWORD *)v41[2] = 0;
      v41[2] = &v138;
      --v39;
    }
    while ( v39 );
  }
  v36[v3].min_x = -1;
  if ( v34 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v33,
      (unsigned int)(4 * v34),
      v35);
  if ( v16 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v15,
      (unsigned int)(4 * v16),
      v35);
  v42 = result;
  v43 = v3;
  v44 = result->m_numMarkers;
  array = 0i64;
  v140 = 0;
  v45 = v3 + v44;
  v141 = 2147483648;
  if ( v45 > 0 )
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      v45,
      4);
  v46 = v4;
  if ( v4 )
  {
    LODWORD(result) = 4 * v4;
    v47 = (_DWORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      (int *)&result);
    v46 = (signed int)result / 4;
  }
  else
  {
    v47 = 0i64;
  }
  v48 = 2147483648;
  v49 = 0;
  if ( v46 )
    v48 = v46;
  v134 = v48;
  v50 = v4 - v43 + 4;
  if ( v4 - v43 == -4 )
  {
    v51 = 0i64;
  }
  else
  {
    v132 = 4 * v50;
    v51 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                       &v132);
    v50 = v132 / 4;
  }
  v52 = v4 - 1;
  v53 = 2147483648;
  if ( v50 )
    v53 = v50;
  v54 = 1;
  data = v51;
  v137 = v53;
  *v47 = 0;
  if ( v52 >= 1 )
  {
    v55 = WORD2(v143);
    v56 = v143;
    v57 = &v47[v52];
    v58 = v52;
    v59 = v51;
    v60 = &v42->m_nodes;
    while ( 1 )
    {
      v61 = v60->m_data;
      if ( (int *)v60->m_data[v58].m_handle != &v138 )
        break;
      *v57 = -1;
      --v57;
      --v52;
      --v58;
      --v54;
LABEL_61:
      if ( ++v54 > v52 )
        goto LABEL_62;
    }
    v62 = (signed __int64)&v61[v54];
    if ( *(int **)(v62 + 16) == &v138 )
    {
      v63 = *(_QWORD *)&v61[v58].min_y;
      --v52;
      --v58;
      *(_QWORD *)v62 = v63;
      --v57;
      *(_QWORD *)(v62 + 8) = *(_QWORD *)&v61[v58 + 1].min_x;
      *(_QWORD *)(v62 + 16) = v61[v58 + 1].m_handle;
      v57[1] = v54;
      v47[v54] = -1;
      array[v140++] = v54;
      if ( *(_BYTE *)(v62 + 16) & 1 )
      {
        *(unsigned __int16 *)((char *)&v42->m_markers->m_nodeIndex + (*(_QWORD *)(v62 + 16) & 0xFFFFFFFFFFFFFFFEui64)) = v54;
LABEL_60:
        v60 = &v42->m_nodes;
        goto LABEL_61;
      }
      **(_DWORD **)(v62 + 16) = v54;
    }
    else
    {
      v47[v54] = v54;
    }
    if ( !(((HIDWORD(v143) - *(_DWORD *)v62) | (*(_DWORD *)(v62 + 4) - (_DWORD)v143)) & 0x80008000) )
    {
      v70 = *(_WORD *)(v62 + 8);
      v60 = &v42->m_nodes;
      if ( (((v55 - *(_WORD *)v62) | (LOWORD(v152.m_enum) - v70) | (*(_WORD *)(v62 + 4) - v56) | (*(_WORD *)(v62 + 10)
                                                                                                - LOWORD(v150.m_enum))) & 0x8000u) == 0 )
      {
        v59->m_key = v70;
        ++v49;
        v59->m_userData = v54;
        ++v59;
      }
      goto LABEL_61;
    }
    goto LABEL_60;
  }
LABEL_62:
  v64 = &v42->m_nodes;
  v65 = v52 + 1;
  v66 = v42->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v66 < v52 + 1 )
  {
    v67 = 2 * v66;
    v68 = v52 + 1;
    if ( v65 < v67 )
      v68 = v67;
    hkArrayUtil::_reserve(&v150, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v42->m_nodes, v68, 24);
  }
  v69 = v49 + 1;
  v42->m_nodes.m_size = v65;
  if ( v49 == -1 )
  {
    pb = 0i64;
  }
  else
  {
    v150.m_enum = 24 * v69;
    pb = (hkp3AxisSweep::hkpBpNode *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                       (int *)&v150);
    v69 = v150.m_enum / 24;
  }
  v71 = 2147483648;
  if ( v69 )
    v71 = v69;
  v136 = v71;
  v72 = v49 + 4;
  if ( v49 == -4 )
  {
    v73 = 0i64;
  }
  else
  {
    v152.m_enum = 4 * v72;
    v73 = (hkRadixSort::SortData16 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                       (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                       (int *)&v152);
    v72 = v152.m_enum / 4;
  }
  v74 = 2147483648;
  if ( v72 )
    v74 = v72;
  v75 = data;
  data[v49].m_key = -1;
  v75[v49 + 1].m_key = -1;
  v75[v49 + 2].m_key = -1;
  hkRadixSort::sort16(v75, (v49 + 3) & 0xFFFFFFFC, v73);
  if ( v49 > 0 )
  {
    v77 = pb;
    v78 = v49;
    v76 = &data->m_userData;
    do
    {
      v79 = *v76;
      ++v77;
      v76 += 2;
      v80 = &v64->m_data[v79];
      *(_QWORD *)&v77[-1].min_y = *(_QWORD *)&v80->min_y;
      *(_QWORD *)&v77[-1].min_x = *(_QWORD *)&v80->min_x;
      v77[-1].m_handle = v80->m_handle;
      --v78;
    }
    while ( v78 );
  }
  v81 = pb;
  pb[v49].min_x = -1;
  if ( v74 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData16 *, _QWORD, unsigned __int16 *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v73,
      (unsigned int)(4 * v74),
      v76);
  v82 = pairsOut;
  v83 = numA;
  hkp3AxisSweep::collide1Axis(v42, pa, numA, pairsOut);
  sizeElem = v49;
  v85 = pa;
  hkp3AxisSweep::collide1Axis(v42, pa, v83, v81, sizeElem, MARKERS_IGNORE, v82);
  v86 = (unsigned __int64)v42->m_axis[0].m_endPoints.m_data;
  v87 = v64->m_data;
  v88 = v86 + 4i64 * v42->m_axis[0].m_endPoints.m_size;
  v89 = 0;
  v90 = (unsigned __int64)v42->m_axis[0].m_endPoints.m_data;
  if ( v86 < v88 )
  {
    do
    {
      v91 = (signed int)v47[*(unsigned __int16 *)(v90 + 2)];
      if ( (signed int)v91 >= 0 )
      {
        v86 += 4i64;
        *(_DWORD *)(v86 - 4) = *(_DWORD *)v90;
        *(_WORD *)(v86 - 2) = v91;
        *(unsigned __int16 *)((char *)&v87[v91].min_y + hkp3AxisSweep::hkpBpNode::s_memberOffsets[*(_WORD *)v90 & 1]) = v89++;
      }
      v90 += 4i64;
    }
    while ( v90 < v88 );
    LOWORD(v83) = numA;
  }
  v92 = v42->m_axis[0].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v92 < v89 )
  {
    v93 = 2 * v92;
    v94 = v89;
    if ( v89 < v93 )
      v94 = v93;
    hkArrayUtil::_reserve(&v152, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v42->m_axis, v94, 4);
  }
  v42->m_axis[0].m_endPoints.m_size = v89;
  v95 = (unsigned __int64)v42->m_axis[1].m_endPoints.m_data;
  v96 = v64->m_data;
  v97 = v95 + 4i64 * v42->m_axis[1].m_endPoints.m_size;
  v98 = 0;
  v99 = (unsigned __int64)v42->m_axis[1].m_endPoints.m_data;
  if ( v95 < v97 )
  {
    do
    {
      v100 = (signed int)v47[*(unsigned __int16 *)(v99 + 2)];
      if ( (signed int)v100 >= 0 )
      {
        v95 += 4i64;
        *(_DWORD *)(v95 - 4) = *(_DWORD *)v99;
        *(_WORD *)(v95 - 2) = v100;
        *(unsigned __int16 *)((char *)&v96[v100].min_y
                            + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(*(_WORD *)v99 & 1) + 2]) = v98++;
      }
      v99 += 4i64;
    }
    while ( v99 < v97 );
    LOWORD(v83) = numA;
  }
  v101 = v42->m_axis[1].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v101 < v98 )
  {
    v102 = 2 * v101;
    v103 = v98;
    if ( v98 < v102 )
      v103 = v102;
    hkArrayUtil::_reserve(
      &v152,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v42->m_axis[1],
      v103,
      4);
  }
  v42->m_axis[1].m_endPoints.m_size = v98;
  v104 = (unsigned __int64)v42->m_axis[2].m_endPoints.m_data;
  v105 = v64->m_data;
  v106 = v104 + 4i64 * v42->m_axis[2].m_endPoints.m_size;
  v107 = 0;
  v108 = (unsigned __int64)v42->m_axis[2].m_endPoints.m_data;
  if ( v104 < v106 )
  {
    do
    {
      v109 = (signed int)v47[*(unsigned __int16 *)(v108 + 2)];
      if ( (signed int)v109 >= 0 )
      {
        v104 += 4i64;
        *(_DWORD *)(v104 - 4) = *(_DWORD *)v108;
        *(_WORD *)(v104 - 2) = v109;
        *(unsigned __int16 *)((char *)&v105[v109].min_y
                            + hkp3AxisSweep::hkpBpNode::s_memberOffsets[(*(_WORD *)v108 & 1) + 4]) = v107++;
      }
      v108 += 4i64;
    }
    while ( v108 < v106 );
    v85 = pa;
  }
  v110 = v42->m_axis[2].m_endPoints.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v110 < v107 )
  {
    v111 = 2 * v110;
    v112 = v107;
    if ( v107 < v111 )
      v112 = v111;
    hkArrayUtil::_reserve(
      &v152,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v42->m_axis[2],
      v112,
      4);
  }
  v42->m_axis[2].m_endPoints.m_size = v107;
  v113 = v42->m_numMarkers;
  if ( v113 )
  {
    v114 = 0;
    v115 = 2 * v83;
    if ( v113 > 0 )
    {
      v116 = 0i64;
      do
      {
        v117 = 0;
        v118 = 0;
        v119 = &v42->m_markers[v116];
        v120 = v119->m_nodeIndex;
        v121 = v42->m_nodes.m_data;
        v121[v120].max_y -= v115;
        v121[v120].max_z -= v115;
        if ( v119->m_overlappingObjects.m_size > 0 )
        {
          v122 = 0i64;
          v123 = 0i64;
          do
          {
            v124 = v119->m_overlappingObjects.m_data;
            v125 = v47[v124[v123]];
            if ( v125 >= 0 )
            {
              v124[v122] = v125;
              ++v118;
              ++v122;
            }
            ++v117;
            ++v123;
          }
          while ( v117 < v119->m_overlappingObjects.m_size );
        }
        v126 = (signed __int64)&v119->m_overlappingObjects;
        v127 = v119->m_overlappingObjects.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v127 >= v118 )
        {
          v152.m_enum = 0;
        }
        else
        {
          v128 = 2 * v127;
          v129 = v118;
          if ( v118 < v128 )
            v129 = v128;
          hkArrayUtil::_reserve(
            &v152,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v119->m_overlappingObjects,
            v129,
            2);
        }
        ++v114;
        *(_DWORD *)(v126 + 8) = v118;
        ++v116;
      }
      while ( v114 < v42->m_numMarkers );
    }
    v85 = pa;
  }
  v130 = 0;
  if ( v140 > 0 )
  {
    v131 = 0i64;
    do
    {
      hkp3AxisSweep::_fixDeterministicOrderAfterNodeIdWasDecreased(v42, array[v131]);
      ++v130;
      ++v131;
    }
    while ( v130 < v140 );
  }
  if ( v136 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      pb,
      24 * (v136 & 0x3FFFFFFF));
  if ( v137 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      data,
      4 * v137);
  if ( v134 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v47,
      4 * v134);
  v140 = 0;
  if ( v141 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v141);
  array = 0i64;
  v141 = 2147483648;
  if ( v148 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v85,
      24 * (v148 & 0x3FFFFFFF));
}llocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v85,
      24 * (v148 & 0x3FFFFFFF));
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
  hkArray<hkAabb,hkContainerHeapAllocator> *v2; // r14
  int v3; // er9
  hkp3AxisSweep *v4; // rbx
  int v5; // ebp
  int v6; // edi
  __int64 v7; // rsi
  hkp3AxisSweep::hkpBpNode *v8; // rdx
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = allAabbs;
  v3 = this->m_nodes.m_size - this->m_numMarkers;
  v4 = this;
  if ( (allAabbs->m_capacityAndFlags & 0x3FFFFFFF) < v3 )
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, allAabbs, v3, 32);
  v5 = 0;
  v6 = 0;
  v2->m_size = v4->m_nodes.m_size - v4->m_numMarkers;
  if ( v4->m_nodes.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = &v4->m_nodes.m_data[v7];
      if ( !((_QWORD)v8->m_handle & 1) )
        hkp3AxisSweep::getAabbFromNode(v4, v8, &v2->m_data[v5++]);
      ++v6;
      ++v7;
    }
    while ( v6 < v4->m_nodes.m_size );
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
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm1

  worldMinOut->m_quad = _mm_xor_ps(
                          (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                          this->m_offsetLow.m_quad);
  v3.m_quad = (__m128)this->m_scale;
  v4 = _mm_rcp_ps(v3.m_quad);
  v5.m_quad = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v3.m_quad, v4)), v4);
  *worldMaxOut = (hkVector4f)v5.m_quad;
  v6.m_quad = _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(FLOAT_65532_0), (__m128)LODWORD(FLOAT_65532_0), 0),
                _mm_shuffle_ps(v5.m_quad, _mm_unpackhi_ps(v5.m_quad, query.m_quad), 196));
  *worldMaxOut = (hkVector4f)v6.m_quad;
  worldMaxOut->m_quad = _mm_add_ps(worldMinOut->m_quad, v6.m_quad);
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
hkp3AxisSweep::hkpBpEndPoint *__fastcall hkp3AxisSweep::hkpBpAxis::find(hkp3AxisSweep::hkpBpAxis *this, hkp3AxisSweep::hkpBpEndPoint *start, hkp3AxisSweep::hkpBpEndPoint *end, unsigned __int16 value)
{
  signed __int64 i; // rcx
  signed __int64 v5; // rcx
  signed int v6; // eax

  for ( i = (char *)end - (char *)start;
        (signed __int64)(((char *)end - (char *)start) & 0xFFFFFFFFFFFFFFFCui64) > 64;
        i = (char *)end - (char *)start )
  {
    v5 = i >> 3;
    if ( start[v5].m_value >= value )
      end = &start[v5];
    else
      start += v5;
  }
  if ( start->m_value < (signed int)value )
  {
    do
    {
      v6 = start[1].m_value;
      ++start;
    }
    while ( v6 < value );
  }
  return start;
}

// File Line: 2889
// RVA: 0xD064B0
void __usercall hkp3AxisSweep::queryBatchAabbSub(hkp3AxisSweep *this@<rcx>, const unsigned int *bitFieldOfQueryNodes@<rdx>, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairsOut@<r8>, hkBool addMode@<r9b>, __int64 a5@<rbx>)
{
  const unsigned int *v5; // r10
  hkp3AxisSweep::hkpBpEndPoint *v6; // rdx
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v7; // r13
  unsigned __int64 v8; // r8
  hkp3AxisSweep *v9; // r9
  __int64 v10; // rax
  __int64 v11; // rbx
  char v12; // cl
  int v13; // er12
  char **v14; // r9
  signed int v15; // ecx
  signed __int64 v16; // rdx
  signed __int64 v17; // r10
  char *v18; // rax
  int v19; // esi
  signed __int64 v20; // r15
  __int64 v21; // r14
  hkp3AxisSweep::hkpBpNode *v22; // rdx
  signed __int64 v23; // rbx
  signed __int64 v24; // r9
  signed __int64 v25; // rcx
  hkpBroadPhaseHandlePair *v26; // rcx
  _DWORD *v27; // r9
  unsigned __int64 v28; // rdx
  unsigned __int64 v29; // rdi
  signed __int64 v30; // rbx
  signed __int64 v31; // r10
  signed int v32; // ecx
  signed __int64 v33; // rdx
  _WORD *v34; // rax
  int v35; // esi
  __int64 v36; // r14
  hkp3AxisSweep::hkpBpNode *v37; // rdx
  signed __int64 v38; // rbx
  signed __int64 v39; // r8
  signed __int64 v40; // rcx
  hkpBroadPhaseHandlePair *v41; // rcx
  unsigned __int64 v42; // r8
  unsigned __int64 v43; // rdx
  unsigned __int64 v44; // rdi
  _DWORD *v45; // rbx
  signed __int64 v46; // r10
  signed int v47; // ecx
  signed __int64 v48; // rdx
  _WORD *v49; // rax
  __int16 v50; // [rsp+20h] [rbp-D8h]
  int v51; // [rsp+24h] [rbp-D4h]
  signed __int64 v52; // [rsp+28h] [rbp-D0h]
  unsigned __int64 v53; // [rsp+30h] [rbp-C8h]
  char *v54; // [rsp+40h] [rbp-B8h]
  int v55; // [rsp+48h] [rbp-B0h]
  int v56; // [rsp+4Ch] [rbp-ACh]
  char v57; // [rsp+50h] [rbp-A8h]
  __int64 *array; // [rsp+248h] [rbp+150h]
  int v59; // [rsp+250h] [rbp+158h]
  int v60; // [rsp+254h] [rbp+15Ch]
  __int64 v61; // [rsp+260h] [rbp+168h]
  hkp3AxisSweep *retaddr; // [rsp+498h] [rbp+3A0h]
  hkp3AxisSweep *v63; // [rsp+4A0h] [rbp+3A8h]
  __int64 v64; // [rsp+4B0h] [rbp+3B8h]

  v63 = this;
  v5 = bitFieldOfQueryNodes;
  v6 = this->m_axis[0].m_endPoints.m_data;
  array = &v61;
  v54 = &v57;
  v7 = pairsOut;
  v8 = (unsigned __int64)&v6[1];
  v9 = this;
  v10 = this->m_axis[0].m_endPoints.m_size - 1;
  v59 = 0;
  v60 = -2147483392;
  v55 = 0;
  v56 = -2147483392;
  v53 = (unsigned __int64)&v6[v10];
  v52 = (signed __int64)&v6[1];
  if ( (unsigned __int64)&v6[1] < v53 )
  {
    v64 = a5;
    do
    {
      v11 = *(unsigned __int16 *)(v8 + 2);
      v50 = *(_WORD *)(v8 + 2);
      v12 = *(_WORD *)(v8 + 2) & 0x1F;
      v13 = v5[v11 >> 5] & (1 << v12);
      v51 = v5[v11 >> 5] & (1 << v12);
      if ( *(_BYTE *)v8 & 1 )
      {
        v14 = (char **)&array;
        if ( !v13 )
          v14 = &v54;
        v15 = 0;
        v16 = 0i64;
        v17 = *((signed int *)v14 + 2);
        if ( (signed int)v17 <= 0 )
        {
LABEL_10:
          v15 = -1;
          v16 = -1i64;
        }
        else
        {
          v18 = *v14;
          while ( *(_WORD *)v18 != (_WORD)v11 )
          {
            ++v16;
            ++v15;
            v18 += 2;
            if ( v16 >= v17 )
              goto LABEL_10;
          }
        }
        *((_DWORD *)v14 + 2) = v17 - 1;
        if ( (_DWORD)v17 - 1 != v15 )
          *(_WORD *)&(*v14)[2 * v16] = *(_WORD *)&(*v14)[2 * ((signed int)v17 - 1)];
        goto LABEL_63;
      }
      v19 = 0;
      v20 = (signed __int64)&v9->m_nodes.m_data[v11];
      if ( v59 <= 0 )
        goto LABEL_35;
      v21 = 0i64;
      do
      {
        v22 = retaddr->m_nodes.m_data;
        v23 = (signed __int64)&v22[*(unsigned __int16 *)((char *)array + v21)];
        if ( ((*(_DWORD *)(v20 + 4) - *(_DWORD *)v23) | (*(_DWORD *)&v22[*(unsigned __int16 *)((char *)array + v21)].max_y
                                                       - *(_DWORD *)v20)) & 0x80008000 )
          goto LABEL_33;
        v24 = v20;
        v25 = (signed __int64)&v22[*(unsigned __int16 *)((char *)array + v21)];
        if ( !(*(_BYTE *)(v20 + 16) & 1) )
        {
          if ( !(*(_BYTE *)(v23 + 16) & 1) )
          {
            if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
            v26 = &v7->m_data[v7->m_size++];
            v26->m_a = *(hkpBroadPhaseHandle **)(v23 + 16);
            v26->m_b = *(hkpBroadPhaseHandle **)(v20 + 16);
            goto LABEL_33;
          }
          v25 = v20;
          v24 = (signed __int64)&v22[*(unsigned __int16 *)((char *)array + v21)];
        }
        v27 = (_DWORD *)((char *)&retaddr->m_markers->m_nodeIndex + (*(_QWORD *)(v24 + 16) & 0xFFFFFFFFFFFFFFFEui64));
        v28 = (unsigned __int128)((v25 - (signed __int64)v22) * (signed __int128)3074457345618258603i64) >> 64;
        v29 = (v28 >> 63) + ((signed __int64)v28 >> 2);
        if ( (_BYTE)v64 )
        {
          v30 = (signed __int64)(v27 + 2);
          if ( v27[4] == (v27[5] & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v27 + 2, 2);
          *(_WORD *)(*(_QWORD *)v30 + 2i64 * (signed int)(*(_DWORD *)(v30 + 8))++) = v29;
        }
        else
        {
          v31 = (signed int)v27[4];
          v32 = 0;
          v33 = 0i64;
          if ( (signed int)v31 <= 0 )
          {
LABEL_30:
            v32 = -1;
            v33 = -1i64;
          }
          else
          {
            v34 = (_WORD *)*((_QWORD *)v27 + 1);
            while ( *v34 != (_WORD)v29 )
            {
              ++v33;
              ++v32;
              ++v34;
              if ( v33 >= v31 )
                goto LABEL_30;
            }
          }
          v27[4] = v31 - 1;
          if ( (_DWORD)v31 - 1 != v32 )
            *(_WORD *)(*((_QWORD *)v27 + 1) + 2 * v33) = *(_WORD *)(*((_QWORD *)v27 + 1) + 2i64 * ((signed int)v31 - 1));
        }
LABEL_33:
        ++v19;
        v21 += 2i64;
      }
      while ( v19 < v59 );
      v13 = v51;
      v9 = retaddr;
      LOWORD(v11) = v50;
LABEL_35:
      if ( v13 )
      {
        v35 = 0;
        if ( v55 > 0 )
        {
          v36 = 0i64;
          do
          {
            v37 = v9->m_nodes.m_data;
            v38 = (signed __int64)&v37[*(unsigned __int16 *)&v54[v36]];
            if ( !(((*(_DWORD *)(v20 + 4) - *(_DWORD *)v38) | (*(_DWORD *)&v37[*(unsigned __int16 *)&v54[v36]].max_y
                                                             - *(_DWORD *)v20)) & 0x80008000) )
            {
              v39 = v20;
              v40 = (signed __int64)&v37[*(unsigned __int16 *)&v54[v36]];
              if ( *(_BYTE *)(v20 + 16) & 1 )
                goto LABEL_45;
              if ( *(_BYTE *)(v38 + 16) & 1 )
              {
                v40 = v20;
                v39 = (signed __int64)&v37[*(unsigned __int16 *)&v54[v36]];
LABEL_45:
                v42 = (unsigned __int64)v9->m_markers + (*(_QWORD *)(v39 + 16) & 0xFFFFFFFFFFFFFFFEui64);
                v43 = (unsigned __int128)((v40 - (signed __int64)v37) * (signed __int128)3074457345618258603i64) >> 64;
                v44 = (v43 >> 63) + ((signed __int64)v43 >> 2);
                if ( (_BYTE)v64 )
                {
                  v45 = (_DWORD *)(v42 + 8);
                  if ( *(_DWORD *)(v42 + 16) == (*(_DWORD *)(v42 + 20) & 0x3FFFFFFF) )
                    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v45, 2);
                  *(_WORD *)(*(_QWORD *)v45 + 2i64 * (signed int)v45[2]++) = v44;
                }
                else
                {
                  v46 = *(signed int *)(v42 + 16);
                  v47 = 0;
                  v48 = 0i64;
                  if ( (signed int)v46 <= 0 )
                  {
LABEL_53:
                    v47 = -1;
                    v48 = -1i64;
                  }
                  else
                  {
                    v49 = *(_WORD **)(v42 + 8);
                    while ( *v49 != (_WORD)v44 )
                    {
                      ++v48;
                      ++v47;
                      ++v49;
                      if ( v48 >= v46 )
                        goto LABEL_53;
                    }
                  }
                  *(_DWORD *)(v42 + 16) = v46 - 1;
                  if ( (_DWORD)v46 - 1 != v47 )
                    *(_WORD *)(*(_QWORD *)(v42 + 8) + 2 * v48) = *(_WORD *)(*(_QWORD *)(v42 + 8)
                                                                          + 2i64 * ((signed int)v46 - 1));
                }
                goto LABEL_56;
              }
              if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
              v41 = &v7->m_data[v7->m_size++];
              v41->m_a = *(hkpBroadPhaseHandle **)(v38 + 16);
              v41->m_b = *(hkpBroadPhaseHandle **)(v20 + 16);
            }
LABEL_56:
            v9 = retaddr;
            ++v35;
            v36 += 2i64;
          }
          while ( v35 < v55 );
        }
        if ( v59 == (v60 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 2);
        *((_WORD *)array + v59++) = v50;
      }
      else
      {
        if ( v55 == (v56 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v54, 2);
        *(_WORD *)&v54[2 * v55++] = v11;
      }
LABEL_63:
      v9 = retaddr;
      v5 = (const unsigned int *)v63;
      v8 = v52 + 4;
      v52 = v8;
    }
    while ( v8 < v53 );
  }
  v55 = 0;
  if ( v56 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, hkp3AxisSweep *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v54,
      2 * (v56 & 0x3FFFFFFFu),
      v9);
  v54 = 0i64;
  v56 = 2147483648;
  v59 = 0;
  if ( v60 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64 *, _QWORD, hkp3AxisSweep *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      2 * (v60 & 0x3FFFFFFFu),
      v9);
}

// File Line: 3186
// RVA: 0xD01110
void __fastcall hkp3AxisSweep::querySingleAabb(hkp3AxisSweep *this, hkAabb *aabbIn, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *pairs_out)
{
  int v3; // edi
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v4; // rbx
  hkAabb *v5; // rsi
  hkp3AxisSweep *v6; // r13
  int v7; // eax
  _DWORD *v8; // r14
  unsigned int v9; // ecx
  int v10; // edi
  _OWORD *i; // rcx
  _OWORD *v12; // rax
  hkp3AxisSweep::hkpBpEndPoint *v13; // r8
  __m128 v14; // xmm0
  __m128i v15; // xmm1
  unsigned int v16; // er10
  __m128 v17; // xmm0
  __m128i v18; // xmm6
  unsigned int v19; // er11
  signed int v20; // edx
  hkp3AxisSweep::hkpBpMarker *v21; // rdi
  unsigned __int16 *v22; // r8
  int j; // er9
  int v24; // ecx
  signed __int64 v25; // rdi
  hkp3AxisSweep::hkpBpEndPoint *v26; // rcx
  unsigned __int64 v27; // r8
  unsigned __int64 k; // r9
  int v29; // ecx
  unsigned int l; // eax
  hkp3AxisSweep::hkpBpEndPoint *v31; // r15
  signed __int64 v32; // rdi
  hkp3AxisSweep::hkpBpEndPoint *v33; // r15
  signed __int64 v34; // rdi
  hkp3AxisSweep::hkpBpEndPoint *v35; // rax
  void *v36; // rdx
  unsigned int *v37; // r8
  unsigned __int64 v38; // rax
  int v39; // er14
  int v40; // er15
  signed __int64 v41; // r13
  unsigned int v42; // esi
  signed __int64 v43; // rdi
  hkpBroadPhaseHandle *v44; // r12
  hkpBroadPhaseHandlePair *v45; // rax
  hkpBroadPhaseHandle *v46; // r12
  hkpBroadPhaseHandlePair *v47; // rax
  hkpBroadPhaseHandle *v48; // r12
  hkpBroadPhaseHandlePair *v49; // rax
  hkpBroadPhaseHandle *v50; // r12
  hkpBroadPhaseHandlePair *v51; // rax
  __int64 v52; // [rsp+0h] [rbp-59h]
  unsigned __int64 v53; // [rsp+0h] [rbp-59h]
  __int64 v54; // [rsp+10h] [rbp-49h]
  unsigned __int64 v55; // [rsp+10h] [rbp-49h]
  __int64 v56; // [rsp+20h] [rbp-39h]
  int v57; // [rsp+C0h] [rbp+67h]
  int v58; // [rsp+C8h] [rbp+6Fh]
  unsigned __int64 v59; // [rsp+D8h] [rbp+7Fh]

  v3 = this->m_nodes.m_size;
  v4 = pairs_out;
  v5 = aabbIn;
  v6 = this;
  v7 = (this->m_nodes.m_size >> 5) + 8;
  if ( this->m_nodes.m_size >> 5 == -8 )
  {
    v8 = 0i64;
  }
  else
  {
    v57 = 4 * v7;
    v8 = (_DWORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                     &v57);
    v7 = v57 / 4;
  }
  v9 = 2147483648;
  v59 = (unsigned __int64)v8;
  if ( v7 )
    v9 = v7;
  v10 = v3 >> 7;
  v58 = v9;
  for ( i = v8; v10 >= 0; *v12 = 0i64 )
  {
    v12 = i;
    ++i;
    --v10;
  }
  v13 = v6->m_axis[0].m_endPoints.m_data + 1;
  v14 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(v6->m_offsetLow.m_quad, v5->m_min.m_quad), v6->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v15 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v14),
            _mm_cvttps_epi32(v14)),
          (__m128i)_xmm);
  v52 = (unsigned __int128)_mm_add_epi16(
                             _mm_packs_epi32(v15, v15),
                             (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v16 = v52 & 0xFFFE;
  v17 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(v6->m_offsetHigh.m_quad, v5->m_max.m_quad), v6->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v18 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v17),
            _mm_cvttps_epi32(v17)),
          (__m128i)_xmm);
  v54 = (unsigned __int128)_mm_add_epi16(
                             _mm_packs_epi32(v18, v18),
                             (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v19 = (unsigned __int16)v54 | 1;
  if ( v6->m_numMarkers )
  {
    v20 = (signed int)v16 >> (16 - LOBYTE(v6->m_ld2NumMarkers));
    if ( v20 > 0 )
    {
      v21 = &v6->m_markers[v20 - 1];
      v8[(signed int)v21->m_nodeIndex >> 5] ^= 1 << (v21->m_nodeIndex & 0x1F);
      v22 = v21->m_overlappingObjects.m_data;
      for ( j = v21->m_overlappingObjects.m_size - 1; j >= 0; --j )
      {
        v24 = *v22;
        ++v22;
        v8[v24 >> 5] ^= 1 << (v24 & 0x1F);
      }
      v25 = (signed __int64)&v6->m_nodes.m_data[v21->m_nodeIndex];
      v26 = v6->m_axis[0].m_endPoints.m_data;
      v27 = (unsigned __int64)&v26[*(unsigned __int16 *)(v25 + 8) + 1];
      for ( k = (unsigned __int64)&v26[*(unsigned __int16 *)(v25 + 10)]; v27 < k; v27 += 4i64 )
      {
        if ( !(*(_BYTE *)v27 & 1) )
          v8[(signed int)*(unsigned __int16 *)(v27 + 2) >> 5] &= ~(1 << (*(_WORD *)(v27 + 2) & 0x1F));
      }
      v13 = &v6->m_axis[0].m_endPoints.m_data[*(unsigned __int16 *)(v25 + 8) + 1];
    }
  }
  for ( ; v13->m_value < v16; v8[v29 >> 5] ^= 1 << (v29 & 0x1F) )
  {
    v29 = v13->m_nodeIndex;
    ++v13;
  }
  for ( l = v13->m_value; l < v19; ++v13 )
  {
    if ( !(l & 1) )
      v8[(signed int)v13->m_nodeIndex >> 5] ^= 1 << (v13->m_nodeIndex & 0x1F);
    l = v13[1].m_value;
  }
  v31 = v6->m_axis[1].m_endPoints.m_data;
  v32 = (signed __int64)&v31[v6->m_axis[1].m_endPoints.m_size];
  hkp3AxisSweep::hkpBpAxis::find(
    &v6->m_axis[1],
    v31 + 1,
    (hkp3AxisSweep::hkpBpEndPoint *)(v32 - 8),
    WORD1(v52) & 0xFFFE);
  hkp3AxisSweep::hkpBpAxis::find(&v6->m_axis[1], v31 + 1, (hkp3AxisSweep::hkpBpEndPoint *)(v32 - 8), WORD1(v54) | 1);
  v33 = v6->m_axis[2].m_endPoints.m_data;
  v34 = (signed __int64)&v33[v6->m_axis[2].m_endPoints.m_size];
  hkp3AxisSweep::hkpBpAxis::find(
    &v6->m_axis[2],
    v33 + 1,
    (hkp3AxisSweep::hkpBpEndPoint *)(v34 - 8),
    WORD2(v52) & 0xFFFE);
  v35 = hkp3AxisSweep::hkpBpAxis::find(
          &v6->m_axis[2],
          v33 + 1,
          (hkp3AxisSweep::hkpBpEndPoint *)(v34 - 8),
          WORD2(v54) | 1u);
  v36 = (void *)v59;
  v37 = (unsigned int *)v59;
  v55 = v59;
  HIWORD(v56) = (signed __int64)((char *)v35 - 4i64 - (_QWORD)v33) >> 2;
  v38 = v59 + 4 * (((signed __int64)v6->m_nodes.m_size >> 5) + 1);
  v53 = v38;
  if ( v59 < v38 )
  {
    v39 = HIDWORD(v56);
    v40 = v56;
    v41 = (signed __int64)&v6->m_nodes.m_data[2].max_y;
    do
    {
      v42 = *v37;
      if ( *v37 )
      {
        v43 = v41;
        do
        {
          if ( v42 & 0xF )
          {
            if ( v42 & 1
              && !(((*(_DWORD *)(v43 - 48) - v40) | (v39 - *(_DWORD *)(v43 - 52))) & 0x80008000)
              && !(*(_BYTE *)(v43 - 36) & 1) )
            {
              v44 = *(hkpBroadPhaseHandle **)(v43 - 36);
              if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
              v45 = &v4->m_data[v4->m_size];
              if ( v45 )
              {
                v45->m_a = 0i64;
                v45->m_b = v44;
              }
              ++v4->m_size;
            }
            if ( v42 & 2
              && !(((*(_DWORD *)(v43 - 24) - v40) | (v39 - *(_DWORD *)(v43 - 28))) & 0x80008000)
              && !(*(_BYTE *)(v43 - 12) & 1) )
            {
              v46 = *(hkpBroadPhaseHandle **)(v43 - 12);
              if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
              v47 = &v4->m_data[v4->m_size];
              if ( v47 )
              {
                v47->m_a = 0i64;
                v47->m_b = v46;
              }
              ++v4->m_size;
            }
            if ( v42 & 4
              && !(((*(_DWORD *)v43 - v40) | (v39 - *(_DWORD *)(v43 - 4))) & 0x80008000)
              && !(*(_BYTE *)(v43 + 12) & 1) )
            {
              v48 = *(hkpBroadPhaseHandle **)(v43 + 12);
              if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
              v49 = &v4->m_data[v4->m_size];
              if ( v49 )
              {
                v49->m_a = 0i64;
                v49->m_b = v48;
              }
              ++v4->m_size;
            }
            if ( v42 & 8
              && !(((*(_DWORD *)(v43 + 24) - v40) | (v39 - *(_DWORD *)(v43 + 20))) & 0x80008000)
              && !(*(_BYTE *)(v43 + 36) & 1) )
            {
              v50 = *(hkpBroadPhaseHandle **)(v43 + 36);
              if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
              v51 = &v4->m_data[v4->m_size];
              if ( v51 )
              {
                v51->m_a = 0i64;
                v51->m_b = v50;
              }
              ++v4->m_size;
            }
          }
          v42 >>= 4;
          v43 += 96i64;
        }
        while ( v42 );
        v37 = (unsigned int *)v55;
        v38 = v53;
      }
      ++v37;
      v41 += 768i64;
      v55 = (unsigned __int64)v37;
    }
    while ( (unsigned __int64)v37 < v38 );
    v36 = (void *)v59;
  }
  if ( v58 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v36,
      4 * v58);
}

// File Line: 3192
// RVA: 0xD01710
void __fastcall hkp3AxisSweep::querySingleAabbWithCollector(hkp3AxisSweep *this, hkAabb *aabbIn, hkpBroadPhaseCastCollector *collector)
{
  int v3; // ebx
  hkpBroadPhaseCastCollector *v4; // r15
  hkAabb *v5; // rdi
  hkp3AxisSweep *v6; // r13
  int v7; // eax
  _DWORD *v8; // r12
  unsigned int v9; // ecx
  int v10; // ebx
  _OWORD *i; // rcx
  _OWORD *v12; // rax
  hkp3AxisSweep::hkpBpEndPoint *v13; // r8
  __m128 v14; // xmm0
  __m128i v15; // xmm1
  unsigned int v16; // er10
  __m128 v17; // xmm0
  __m128i v18; // xmm6
  unsigned int v19; // er11
  signed int v20; // edx
  hkp3AxisSweep::hkpBpMarker *v21; // rbx
  unsigned __int16 *v22; // r8
  int j; // er9
  int v24; // ecx
  signed __int64 v25; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v26; // rcx
  unsigned __int64 v27; // r8
  unsigned __int64 k; // r9
  int v29; // ecx
  unsigned int l; // eax
  hkp3AxisSweep::hkpBpEndPoint *v31; // rbp
  signed __int64 v32; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v33; // rax
  signed __int64 v34; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v35; // rbp
  signed __int64 v36; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v37; // rax
  hkp3AxisSweep::hkpBpNode *v38; // rcx
  unsigned int *v39; // r14
  unsigned __int64 v40; // rax
  signed __int64 v41; // r13
  unsigned int v42; // edi
  signed __int64 v43; // rbx
  __int64 v44; // [rsp+20h] [rbp-B8h]
  __int64 v45; // [rsp+30h] [rbp-A8h]
  int v46; // [rsp+40h] [rbp-98h]
  int v47; // [rsp+44h] [rbp-94h]
  int v48; // [rsp+E0h] [rbp+8h]
  int v49; // [rsp+E8h] [rbp+10h]
  unsigned __int64 v50; // [rsp+F8h] [rbp+20h]

  v3 = this->m_nodes.m_size;
  v4 = collector;
  v5 = aabbIn;
  v6 = this;
  v7 = (this->m_nodes.m_size >> 5) + 8;
  if ( this->m_nodes.m_size >> 5 == -8 )
  {
    v8 = 0i64;
  }
  else
  {
    v48 = 4 * v7;
    v8 = (_DWORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                     &v48);
    v7 = v48 / 4;
  }
  v9 = 2147483648;
  if ( v7 )
    v9 = v7;
  v10 = v3 >> 7;
  v49 = v9;
  for ( i = v8; v10 >= 0; *v12 = 0i64 )
  {
    v12 = i;
    ++i;
    --v10;
  }
  v13 = v6->m_axis[0].m_endPoints.m_data + 1;
  v14 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(v6->m_offsetLow.m_quad, v5->m_min.m_quad), v6->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v15 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v14),
            _mm_cvttps_epi32(v14)),
          (__m128i)_xmm);
  v44 = (unsigned __int128)_mm_add_epi16(
                             _mm_packs_epi32(v15, v15),
                             (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v16 = v44 & 0xFFFE;
  v17 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(v6->m_offsetHigh.m_quad, v5->m_max.m_quad), v6->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v18 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v17),
            _mm_cvttps_epi32(v17)),
          (__m128i)_xmm);
  v45 = (unsigned __int128)_mm_add_epi16(
                             _mm_packs_epi32(v18, v18),
                             (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v19 = (unsigned __int16)v45 | 1;
  if ( v6->m_numMarkers )
  {
    v20 = (signed int)v16 >> (16 - LOBYTE(v6->m_ld2NumMarkers));
    if ( v20 > 0 )
    {
      v21 = &v6->m_markers[v20 - 1];
      v8[(signed int)v21->m_nodeIndex >> 5] ^= 1 << (v21->m_nodeIndex & 0x1F);
      v22 = v21->m_overlappingObjects.m_data;
      for ( j = v21->m_overlappingObjects.m_size - 1; j >= 0; --j )
      {
        v24 = *v22;
        ++v22;
        v8[v24 >> 5] ^= 1 << (v24 & 0x1F);
      }
      v25 = (signed __int64)&v6->m_nodes.m_data[v21->m_nodeIndex];
      v26 = v6->m_axis[0].m_endPoints.m_data;
      v27 = (unsigned __int64)&v26[*(unsigned __int16 *)(v25 + 8) + 1];
      for ( k = (unsigned __int64)&v26[*(unsigned __int16 *)(v25 + 10)]; v27 < k; v27 += 4i64 )
      {
        if ( !(*(_BYTE *)v27 & 1) )
          v8[(signed int)*(unsigned __int16 *)(v27 + 2) >> 5] &= ~(1 << (*(_WORD *)(v27 + 2) & 0x1F));
      }
      v13 = &v6->m_axis[0].m_endPoints.m_data[*(unsigned __int16 *)(v25 + 8) + 1];
    }
  }
  for ( ; v13->m_value < v16; v8[v29 >> 5] ^= 1 << (v29 & 0x1F) )
  {
    v29 = v13->m_nodeIndex;
    ++v13;
  }
  for ( l = v13->m_value; l < v19; ++v13 )
  {
    if ( !(l & 1) )
      v8[(signed int)v13->m_nodeIndex >> 5] ^= 1 << (v13->m_nodeIndex & 0x1F);
    l = v13[1].m_value;
  }
  v31 = v6->m_axis[1].m_endPoints.m_data;
  v32 = v6->m_axis[1].m_endPoints.m_size;
  LOWORD(v46) = hkp3AxisSweep::hkpBpAxis::find(&v6->m_axis[1], v31 + 1, &v31[v32 - 2], WORD1(v44) & 0xFFFE) - v31;
  v33 = hkp3AxisSweep::hkpBpAxis::find(&v6->m_axis[1], v31 + 1, &v31[v32 - 2], WORD1(v45) | 1u);
  v34 = -4i64 - (_QWORD)v31;
  v35 = v6->m_axis[2].m_endPoints.m_data;
  LOWORD(v47) = ((signed __int64)v33 + v34) >> 2;
  v36 = v6->m_axis[2].m_endPoints.m_size;
  HIWORD(v46) = hkp3AxisSweep::hkpBpAxis::find(&v6->m_axis[2], v35 + 1, &v35[v36 - 2], WORD2(v44) & 0xFFFE) - v35;
  v37 = hkp3AxisSweep::hkpBpAxis::find(&v6->m_axis[2], v35 + 1, &v35[v36 - 2], WORD2(v45) | 1u);
  v38 = v6->m_nodes.m_data;
  v39 = v8;
  HIWORD(v47) = (signed __int64)((char *)v37 - 4i64 - (_QWORD)v35) >> 2;
  v40 = (unsigned __int64)&v8[((signed __int64)v6->m_nodes.m_size >> 5) + 1];
  v50 = v40;
  if ( (unsigned __int64)v8 < v40 )
  {
    v41 = (signed __int64)&v38[2].max_y;
    do
    {
      v42 = *v39;
      if ( *v39 )
      {
        v43 = v41;
        do
        {
          if ( v42 & 0xF )
          {
            if ( v42 & 1
              && !(((*(_DWORD *)(v43 - 48) - v46) | (v47 - *(_DWORD *)(v43 - 52))) & 0x80008000)
              && !(*(_BYTE *)(v43 - 36) & 1) )
            {
              v4->vfptr->addBroadPhaseHandle(v4, *(hkpBroadPhaseHandle **)(v43 - 36), 0);
            }
            if ( v42 & 2
              && !(((*(_DWORD *)(v43 - 24) - v46) | (v47 - *(_DWORD *)(v43 - 28))) & 0x80008000)
              && !(*(_BYTE *)(v43 - 12) & 1) )
            {
              v4->vfptr->addBroadPhaseHandle(v4, *(hkpBroadPhaseHandle **)(v43 - 12), 0);
            }
            if ( v42 & 4
              && !(((*(_DWORD *)v43 - v46) | (v47 - *(_DWORD *)(v43 - 4))) & 0x80008000)
              && !(*(_BYTE *)(v43 + 12) & 1) )
            {
              v4->vfptr->addBroadPhaseHandle(v4, *(hkpBroadPhaseHandle **)(v43 + 12), 0);
            }
            if ( v42 & 8
              && !(((*(_DWORD *)(v43 + 24) - v46) | (v47 - *(_DWORD *)(v43 + 20))) & 0x80008000)
              && !(*(_BYTE *)(v43 + 36) & 1) )
            {
              v4->vfptr->addBroadPhaseHandle(v4, *(hkpBroadPhaseHandle **)(v43 + 36), 0);
            }
          }
          v42 >>= 4;
          v43 += 96i64;
        }
        while ( v42 );
        v40 = v50;
      }
      ++v39;
      v41 += 768i64;
    }
    while ( (unsigned __int64)v39 < v40 );
  }
  if ( v49 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v8,
      4 * v49);
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
  int v3; // er9
  int v4; // er12
  hkAabb *v5; // rdi
  hkp3AxisSweep *v6; // rsi
  int v7; // ebx
  __int32 v8; // eax
  _DWORD *v9; // rax
  _DWORD *v10; // r13
  unsigned int v11; // ecx
  int v12; // ebx
  _OWORD *v13; // rcx
  _OWORD *v14; // rax
  hkp3AxisSweep::hkpBpEndPoint *v15; // r8
  __m128 v16; // xmm0
  __m128i v17; // xmm1
  __m128 v18; // xmm0
  __int64 v19; // ST00_8
  unsigned int v20; // er10
  __m128 v21; // xmm0
  __m128i v22; // xmm6
  __int64 v23; // ST10_8
  unsigned int v24; // er11
  bool v25; // zf
  signed int v26; // edx
  hkp3AxisSweep::hkpBpMarker *v27; // rbx
  unsigned __int16 *v28; // r8
  int i; // er9
  int v30; // ecx
  signed __int64 v31; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v32; // rcx
  unsigned __int64 v33; // r8
  unsigned __int64 j; // r9
  int v35; // ecx
  unsigned int v36; // eax
  hkp3AxisSweep::hkpBpEndPoint *v37; // r14
  signed __int64 v38; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v39; // rax
  hkp3AxisSweep *v40; // rsi
  signed __int64 v41; // rcx
  hkp3AxisSweep::hkpBpEndPoint *v42; // r14
  signed __int64 v43; // rbx
  hkp3AxisSweep::hkpBpEndPoint *v44; // rax
  hkp3AxisSweep::hkpBpNode *v45; // rdi
  unsigned int *v46; // rbx
  unsigned __int64 v47; // r14
  int v48; // er9
  int v49; // er10
  signed __int64 v50; // rdi
  unsigned int v51; // er8
  signed __int64 v52; // rax
  _QWORD *array; // [rsp+20h] [rbp-59h]
  int v54; // [rsp+28h] [rbp-51h]
  int v55; // [rsp+2Ch] [rbp-4Dh]
  int sizeElem; // [rsp+30h] [rbp-49h]
  int v57; // [rsp+34h] [rbp-45h]
  int v58; // [rsp+54h] [rbp-25h]
  int v59; // [rsp+58h] [rbp-21h]
  int v60; // [rsp+64h] [rbp-15h]
  int v61; // [rsp+68h] [rbp-11h]
  hkp3AxisSweep *v62; // [rsp+E0h] [rbp+67h]
  hkResult result; // [rsp+E8h] [rbp+6Fh]
  char *AabbCacheOuta; // [rsp+F0h] [rbp+77h]
  int v65; // [rsp+F8h] [rbp+7Fh]

  v3 = this->m_nodes.m_size;
  v4 = 0;
  v5 = aabb;
  v6 = this;
  array = 0i64;
  v54 = 0;
  v55 = 2147483648;
  if ( v3 > 0 )
  {
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v3, 8);
    v4 = v54;
  }
  v7 = v6->m_nodes.m_size;
  v8 = (v6->m_nodes.m_size >> 5) + 8;
  if ( v6->m_nodes.m_size >> 5 == -8 )
  {
    v10 = 0i64;
  }
  else
  {
    result.m_enum = 4 * v8;
    v9 = (_DWORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                     (int *)&result);
    v4 = v54;
    v10 = v9;
    v8 = result.m_enum / 4;
  }
  v11 = 2147483648;
  if ( v8 )
    v11 = v8;
  v12 = v7 >> 7;
  v65 = v11;
  v13 = v10;
  if ( v12 >= 0 )
  {
    do
    {
      v14 = v13;
      ++v13;
      --v12;
      *v14 = 0i64;
    }
    while ( v12 >= 0 );
    v4 = v54;
  }
  v15 = v6->m_axis[0].m_endPoints.m_data + 1;
  v16 = _mm_max_ps(
          _mm_min_ps(
            _mm_mul_ps(_mm_add_ps(v6->m_offsetLow.m_quad, v5->m_min.m_quad), v6->m_scale.m_quad),
            hkp3AxisSweep::MaxVal),
          (__m128)0i64);
  v17 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v16),
            _mm_cvttps_epi32(v16)),
          (__m128i)_xmm);
  v18 = _mm_min_ps(
          _mm_mul_ps(_mm_add_ps(v6->m_offsetHigh.m_quad, v5->m_max.m_quad), v6->m_scale.m_quad),
          hkp3AxisSweep::MaxVal);
  v19 = (unsigned __int128)_mm_add_epi16(
                             _mm_packs_epi32(v17, v17),
                             (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v20 = v19 & 0xFFFE;
  v58 = WORD1(v19) & 0xFFFE;
  v21 = _mm_max_ps(v18, (__m128)0i64);
  v59 = WORD2(v19) & 0xFFFE;
  v22 = _mm_sub_epi32(
          _mm_xor_si128(
            (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v21),
            _mm_cvttps_epi32(v21)),
          (__m128i)_xmm);
  v23 = (unsigned __int128)_mm_add_epi16(
                             _mm_packs_epi32(v22, v22),
                             (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v24 = (unsigned __int16)v23 | 1;
  v60 = WORD1(v23) | 1;
  v25 = v6->m_numMarkers == 0;
  v61 = WORD2(v23) | 1;
  if ( !v25 )
  {
    v26 = (signed int)v20 >> (16 - LOBYTE(v6->m_ld2NumMarkers));
    if ( v26 > 0 )
    {
      v27 = &v6->m_markers[v26 - 1];
      v10[(signed int)v27->m_nodeIndex >> 5] ^= 1 << (v27->m_nodeIndex & 0x1F);
      v28 = v27->m_overlappingObjects.m_data;
      for ( i = v27->m_overlappingObjects.m_size - 1; i >= 0; --i )
      {
        v30 = *v28;
        ++v28;
        v10[v30 >> 5] ^= 1 << (v30 & 0x1F);
      }
      v31 = (signed __int64)&v6->m_nodes.m_data[v27->m_nodeIndex];
      v32 = v6->m_axis[0].m_endPoints.m_data;
      v33 = (unsigned __int64)&v32[*(unsigned __int16 *)(v31 + 8) + 1];
      for ( j = (unsigned __int64)&v32[*(unsigned __int16 *)(v31 + 10)]; v33 < j; v33 += 4i64 )
      {
        if ( !(*(_BYTE *)v33 & 1) )
          v10[(signed int)*(unsigned __int16 *)(v33 + 2) >> 5] &= ~(1 << (*(_WORD *)(v33 + 2) & 0x1F));
      }
      v4 = v54;
      v15 = &v6->m_axis[0].m_endPoints.m_data[*(unsigned __int16 *)(v31 + 8) + 1];
    }
  }
  if ( v15->m_value < v20 )
  {
    do
    {
      v35 = v15->m_nodeIndex;
      ++v15;
      v10[v35 >> 5] ^= 1 << (v35 & 0x1F);
    }
    while ( v15->m_value < v20 );
    v4 = v54;
  }
  v36 = v15->m_value;
  if ( v36 < v24 )
  {
    do
    {
      if ( !(v36 & 1) )
        v10[(signed int)v15->m_nodeIndex >> 5] ^= 1 << (v15->m_nodeIndex & 0x1F);
      v36 = v15[1].m_value;
      ++v15;
    }
    while ( v36 < v24 );
    v4 = v54;
  }
  v37 = v6->m_axis[1].m_endPoints.m_data;
  v38 = (signed __int64)&v37[v6->m_axis[1].m_endPoints.m_size];
  LOWORD(sizeElem) = hkp3AxisSweep::hkpBpAxis::find(
                       &v6->m_axis[1],
                       v37 + 1,
                       (hkp3AxisSweep::hkpBpEndPoint *)(v38 - 8),
                       v58)
                   - v37;
  v39 = hkp3AxisSweep::hkpBpAxis::find(&v6->m_axis[1], v37 + 1, (hkp3AxisSweep::hkpBpEndPoint *)(v38 - 8), v60);
  v40 = v62;
  v41 = -4i64 - (_QWORD)v37;
  v42 = v62->m_axis[2].m_endPoints.m_data;
  LOWORD(v57) = ((signed __int64)v39 + v41) >> 2;
  v43 = (signed __int64)&v42[v62->m_axis[2].m_endPoints.m_size];
  HIWORD(sizeElem) = hkp3AxisSweep::hkpBpAxis::find(
                       &v62->m_axis[2],
                       v42 + 1,
                       (hkp3AxisSweep::hkpBpEndPoint *)(v43 - 8),
                       v59)
                   - v42;
  v44 = hkp3AxisSweep::hkpBpAxis::find(&v40->m_axis[2], v42 + 1, (hkp3AxisSweep::hkpBpEndPoint *)(v43 - 8), v61);
  v45 = v40->m_nodes.m_data;
  v46 = v10;
  HIWORD(v57) = (signed __int64)((char *)v44 - 4i64 - (_QWORD)v42) >> 2;
  v47 = (unsigned __int64)&v10[((signed __int64)v40->m_nodes.m_size >> 5) + 1];
  if ( (unsigned __int64)v10 < v47 )
  {
    v48 = v57;
    v49 = sizeElem;
    v50 = (signed __int64)&v45[2].max_y;
    do
    {
      v51 = *v46;
      if ( *v46 )
      {
        v52 = v50;
        do
        {
          if ( v51 & 0xF )
          {
            if ( v51 & 1
              && !(((v48 - *(_DWORD *)(v52 - 52)) | (*(_DWORD *)(v52 - 48) - v49)) & 0x80008000)
              && !(*(_BYTE *)(v52 - 36) & 1) )
            {
              array[v4] = v52 - 52;
              v4 = v54++ + 1;
            }
            if ( v51 & 2
              && !(((v48 - *(_DWORD *)(v52 - 28)) | (*(_DWORD *)(v52 - 24) - v49)) & 0x80008000)
              && !(*(_BYTE *)(v52 - 12) & 1) )
            {
              array[v4] = v52 - 28;
              v4 = v54++ + 1;
            }
            if ( v51 & 4
              && !(((*(_DWORD *)v52 - v49) | (v48 - *(_DWORD *)(v52 - 4))) & 0x80008000)
              && !(*(_BYTE *)(v52 + 12) & 1) )
            {
              array[v4] = v52 - 4;
              v4 = v54++ + 1;
            }
            if ( v51 & 8
              && !(((v48 - *(_DWORD *)(v52 + 20)) | (*(_DWORD *)(v52 + 24) - v49)) & 0x80008000)
              && !(*(_BYTE *)(v52 + 36) & 1) )
            {
              array[v4] = v52 + 20;
              v4 = v54++ + 1;
            }
          }
          v51 >>= 4;
          v52 += 96i64;
        }
        while ( v51 );
      }
      ++v46;
      v50 += 768i64;
    }
    while ( (unsigned __int64)v46 < v47 );
  }
  if ( v65 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v10,
      4 * v65);
  hkp3AxisSweep::calcAabbCacheInternal(v40, (hkArrayBase<hkp3AxisSweep::hkpBpNode const *> *)&array, AabbCacheOuta);
  v54 = 0;
  if ( v55 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v55);
}

// File Line: 3232
// RVA: 0xD03B60
void __fastcall hkp3AxisSweep::calcAabbCache(hkp3AxisSweep *this, hkArrayBase<hkpCollidable *> *overlappingCollidables, char *AabbCacheOut)
{
  int v3; // ebp
  int v4; // ebx
  char *v5; // r12
  hkArrayBase<hkpCollidable *> *v6; // r14
  hkp3AxisSweep *v7; // r15
  hkLifoAllocator *v8; // rax
  hkp3AxisSweep::hkpBpNode **v9; // rdi
  int v10; // edx
  char *v11; // rcx
  signed int v12; // esi
  __int64 v13; // r8
  __int64 v14; // rax
  signed int v15; // ebx
  hkLifoAllocator *v16; // rax
  int v17; // er8
  hkArrayBase<hkp3AxisSweep::hkpBpNode const *> overlaps; // [rsp+20h] [rbp-38h]
  hkp3AxisSweep::hkpBpNode **v19; // [rsp+30h] [rbp-28h]
  int v20; // [rsp+38h] [rbp-20h]

  v3 = overlappingCollidables->m_size;
  v4 = 0;
  v5 = AabbCacheOut;
  v6 = overlappingCollidables;
  v7 = this;
  overlaps.m_size = 0;
  v20 = v3;
  if ( v3 )
  {
    v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkp3AxisSweep::hkpBpNode **)v8->m_cur;
    v10 = (8 * v3 + 127) & 0xFFFFFF80;
    v11 = (char *)v9 + v10;
    if ( v10 > v8->m_slabSize || v11 > v8->m_end )
    {
      v9 = (hkp3AxisSweep::hkpBpNode **)hkLifoAllocator::allocateFromNewSlab(v8, v10);
      overlaps.m_data = v9;
    }
    else
    {
      v8->m_cur = v11;
      overlaps.m_data = v9;
    }
  }
  else
  {
    v9 = 0i64;
    overlaps.m_data = 0i64;
  }
  v19 = v9;
  v12 = v3 | 0x80000000;
  overlaps.m_capacityAndFlags = v3 | 0x80000000;
  if ( v6->m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      ++v13;
      v14 = v4++;
      v9[v14] = &v7->m_nodes.m_data[v6->m_data[v13 - 1]->m_broadPhaseHandle.m_id];
      overlaps.m_size = v4;
    }
    while ( v4 < v6->m_size );
  }
  hkp3AxisSweep::calcAabbCacheInternal(v7, &overlaps, v5);
  v15 = (8 * v3 + 127) & 0xFFFFFF80;
  v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (v15 + 15) & 0xFFFFFFF0;
  if ( v15 > v16->m_slabSize || (char *)v9 + v17 != v16->m_cur || v16->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(v16, v9, v17);
  else
    v16->m_cur = v9;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v9,
      8 * v12);
}

// File Line: 3250
// RVA: 0xD03CF0
void __fastcall hkp3AxisSweep::calcAabbCacheInternal(hkp3AxisSweep *this, hkArrayBase<hkp3AxisSweep::hkpBpNode const *> *overlaps, char *AabbCacheOut)
{
  char *v3; // rdi
  char *v4; // r9
  hkArrayBase<hkp3AxisSweep::hkpBpNode const *> *v5; // r11
  int v6; // er8
  _QWORD *v7; // r14
  _QWORD *v8; // rbx
  _DWORD *v9; // rdx
  _DWORD *v10; // r8
  _DWORD *v11; // r8
  hkp3AxisSweep::hkpBpNode **v12; // rdx
  int i; // er11
  hkp3AxisSweep::hkpBpEndPoint *v14; // r8
  hkp3AxisSweep::hkpBpEndPoint *v15; // r8
  hkp3AxisSweep::hkpBpEndPoint *v16; // r8
  hkp3AxisSweep::hkpBpEndPoint *v17; // r8
  hkp3AxisSweep::hkpBpEndPoint *v18; // r8
  hkp3AxisSweep::hkpBpEndPoint *v19; // r8
  char *v20; // rsi
  signed __int64 v21; // rbp
  _DWORD *v22; // rdx
  _DWORD *v23; // r8
  _DWORD *v24; // r8

  v3 = AabbCacheOut;
  v4 = AabbCacheOut + 48;
  v5 = overlaps;
  v6 = 2 * overlaps->m_size + 2;
  if ( v3 )
  {
    *(_QWORD *)v3 = v4;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = v6 | 0x80000000;
  }
  v7 = v3 + 16;
  if ( v3 != (char *)-16i64 )
  {
    *((_DWORD *)v3 + 6) = 0;
    *v7 = &v4[4 * v6];
    *((_DWORD *)v3 + 7) = v6 | 0x80000000;
  }
  v8 = v3 + 32;
  if ( v3 != (char *)-32i64 )
  {
    *((_DWORD *)v3 + 10) = 0;
    *((_DWORD *)v3 + 11) = v6 | 0x80000000;
    *v8 = &v4[8 * v6];
  }
  v9 = (_DWORD *)(*(_QWORD *)v3 + 4i64 * *((signed int *)v3 + 2));
  if ( v9 )
    *v9 = 0;
  ++*((_DWORD *)v3 + 2);
  v10 = (_DWORD *)(*v7 + 4i64 * *((signed int *)v3 + 6));
  if ( v10 )
    *v10 = 0;
  ++*((_DWORD *)v3 + 6);
  v11 = (_DWORD *)(*v8 + 4i64 * *((signed int *)v3 + 10));
  if ( v11 )
    *v11 = 0;
  ++*((_DWORD *)v3 + 10);
  v12 = v5->m_data;
  for ( i = v5->m_size - 1; i >= 0; --i )
  {
    v14 = (hkp3AxisSweep::hkpBpEndPoint *)(*(_QWORD *)v3 + 4i64 * *((signed int *)v3 + 2));
    if ( v14 )
      *v14 = this->m_axis[0].m_endPoints.m_data[(*v12)->min_x];
    v15 = (hkp3AxisSweep::hkpBpEndPoint *)(*(_QWORD *)v3 + 4i64 * (signed int)++*((_DWORD *)v3 + 2));
    if ( v15 )
      *v15 = this->m_axis[0].m_endPoints.m_data[(*v12)->max_x];
    ++*((_DWORD *)v3 + 2);
    v16 = (hkp3AxisSweep::hkpBpEndPoint *)(*((_QWORD *)v3 + 2) + 4i64 * *((signed int *)v3 + 6));
    if ( v16 )
      *v16 = this->m_axis[1].m_endPoints.m_data[(*v12)->min_y];
    v17 = (hkp3AxisSweep::hkpBpEndPoint *)(*((_QWORD *)v3 + 2) + 4i64 * (signed int)++*((_DWORD *)v3 + 6));
    if ( v17 )
      *v17 = this->m_axis[1].m_endPoints.m_data[(*v12)->max_y];
    ++*((_DWORD *)v3 + 6);
    v18 = (hkp3AxisSweep::hkpBpEndPoint *)(*((_QWORD *)v3 + 4) + 4i64 * *((signed int *)v3 + 10));
    if ( v18 )
      *v18 = this->m_axis[2].m_endPoints.m_data[(*v12)->min_z];
    v19 = (hkp3AxisSweep::hkpBpEndPoint *)(*((_QWORD *)v3 + 4) + 4i64 * (signed int)++*((_DWORD *)v3 + 10));
    if ( v19 )
      *v19 = this->m_axis[2].m_endPoints.m_data[(*v12)->max_z];
    ++*((_DWORD *)v3 + 10);
    ++v12;
  }
  v20 = v3;
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
  v22 = (_DWORD *)(*(_QWORD *)v3 + 4i64 * *((signed int *)v3 + 2));
  if ( v22 )
    *v22 = 65532;
  ++*((_DWORD *)v3 + 2);
  v23 = (_DWORD *)(*v7 + 4i64 * *((signed int *)v3 + 6));
  if ( v23 )
    *v23 = 65532;
  ++*((_DWORD *)v3 + 6);
  v24 = (_DWORD *)(*v8 + 4i64 * *((signed int *)v3 + 10));
  if ( v24 )
    *v24 = 65532;
  ++*((_DWORD *)v3 + 10);
}

// File Line: 3313
// RVA: 0xD00D50
void __fastcall hkp3AxisSweep::defragment(hkp3AxisSweep *this)
{
  int v1; // esi
  hkp3AxisSweep *v2; // rbx
  int v3; // edx
  _QWORD *v4; // r13
  signed int v5; // er15
  int v6; // eax
  ValueIntPair<unsigned short> *v7; // r12
  signed int v8; // ebp
  int v9; // eax
  _DWORD *v10; // rdi
  signed int v11; // er14
  int i; // er9
  hkp3AxisSweep::hkpBpNode *v13; // rcx
  __int64 v14; // rdx
  signed __int64 v15; // r8
  int v16; // er8
  __int64 v17; // r9
  unsigned __int16 *v18; // r10
  __int64 v19; // rax
  hkp3AxisSweep::hkpBpNode *v20; // rcx
  int v21; // esi
  signed int j; // edx
  signed __int64 v23; // rcx
  int v24; // er10
  __int64 v25; // r11
  hkp3AxisSweep::hkpBpMarker *v26; // r9
  int v27; // eax
  __int64 k; // r8
  unsigned __int16 *v29; // rdx
  int *v30; // r9
  signed __int64 v31; // r10
  int v32; // er8
  unsigned __int16 *v33; // rax
  __int64 v34; // rcx
  int v35; // [rsp+60h] [rbp+8h]
  int v36; // [rsp+68h] [rbp+10h]
  int v37; // [rsp+70h] [rbp+18h]

  v1 = this->m_nodes.m_size;
  v2 = this;
  v3 = v1;
  if ( v1 )
  {
    v35 = 24 * v1;
    v4 = (_QWORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                     &v35);
    v3 = v35 / 24;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = 2147483648;
  if ( v3 )
    v5 = v3;
  v6 = v1;
  if ( v1 )
  {
    v36 = 4 * v1;
    v7 = (ValueIntPair<unsigned short> *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                           (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                           &v36);
    v6 = v36 / 4;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = 2147483648;
  if ( v6 )
    v8 = v6;
  v9 = v1;
  if ( v1 )
  {
    v37 = 4 * v1;
    v10 = (_DWORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      &v37);
    v9 = v37 / 4;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = 2147483648;
  if ( v9 )
    v11 = v9;
  for ( i = 0; i < v2->m_nodes.m_size; v7[v14].m_value = (unsigned __int16)v13 )
  {
    v13 = v2->m_nodes.m_data;
    v14 = i;
    v15 = 24i64 * i;
    v4[(unsigned __int64)v15 / 8] = *(_QWORD *)&v13[i].min_y;
    v4[(unsigned __int64)v15 / 8 + 1] = *(_QWORD *)&v13[i].min_x;
    v4[(unsigned __int64)v15 / 8 + 2] = v13[i].m_handle;
    LOWORD(v13) = v2->m_nodes.m_data[(unsigned __int64)v15 / 0x18].min_x;
    v7[v14].m_oldIndex = i++;
  }
  if ( v1 - 1 > 1 )
    hkAlgorithm::quickSortRecursive<ValueIntPair<unsigned short>,hkAlgorithm::less<ValueIntPair<unsigned short>>>(
      v7 + 1,
      0,
      v1 - 2,
      0);
  v16 = 0;
  if ( v2->m_nodes.m_size > 0 )
  {
    v17 = 0i64;
    v18 = &v7->m_oldIndex;
    do
    {
      v19 = *v18;
      v18 += 2;
      ++v17;
      v10[v19] = v16;
      v20 = v2->m_nodes.m_data;
      ++v16;
      *(_QWORD *)&v20[v17 - 1].min_y = v4[3 * v19];
      *((_QWORD *)&v20[v17] - 2) = v4[3 * v19 + 1];
      *((_QWORD *)&v20[v17] - 1) = v4[3 * v19 + 2];
    }
    while ( v16 < v2->m_nodes.m_size );
  }
  v21 = 1;
  for ( j = 1; j < v2->m_nodes.m_size; ++j )
  {
    v23 = (signed __int64)&v2->m_nodes.m_data[j];
    if ( *(_BYTE *)(v23 + 16) & 1 )
      *(unsigned __int16 *)((char *)&v2->m_markers->m_nodeIndex + (*(_QWORD *)(v23 + 16) & 0xFFFFFFFFFFFFFFFEui64)) = j;
    else
      **(_DWORD **)(v23 + 16) = j;
  }
  v24 = 0;
  if ( v2->m_numMarkers > 0 )
  {
    v25 = 0i64;
    do
    {
      v26 = v2->m_markers;
      v27 = v26[v25].m_overlappingObjects.m_size - 1;
      for ( k = v27; k >= 0; *v29 = v10[*v29] )
        v29 = &v26[v25].m_overlappingObjects.m_data[k--];
      ++v24;
      ++v25;
    }
    while ( v24 < v2->m_numMarkers );
  }
  v30 = &v2->m_axis[0].m_endPoints.m_size;
  v31 = 3i64;
  do
  {
    v32 = 0;
    if ( *v30 > 0 )
    {
      v33 = (unsigned __int16 *)(*((_QWORD *)v30 - 1) + 2i64);
      do
      {
        v34 = *v33;
        ++v32;
        v33 += 2;
        *(v33 - 2) = v10[v34];
      }
      while ( v32 < *v30 );
    }
    v30 += 4;
    --v31;
  }
  while ( v31 );
  if ( v2->m_nodes.m_size > 1 )
  {
    do
      hkp3AxisSweep::_fixDeterministicOrderAfterNodeIdWasDecreased(v2, v21++);
    while ( v21 < v2->m_nodes.m_size );
  }
  if ( v11 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _DWORD *, _QWORD, int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v10,
      (unsigned int)(4 * v11),
      v30);
  if ( v8 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, ValueIntPair<unsigned short> *, _QWORD, int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v7,
      (unsigned int)(4 * v8),
      v30);
  if ( v5 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _QWORD *, _QWORD, int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v4,
      24 * (v5 & 0x3FFFFFFFu),
      v30);
}

// File Line: 3598
// RVA: 0xD02040
void __fastcall hkp3AxisSweep::castRay(hkp3AxisSweep *this, hkpBroadPhase::hkpCastRayInput *rayInput, hkpBroadPhaseCastCollector *collectorBase, int collectorStriding)
{
  __m128 v4; // xmm0
  hkpBroadPhaseCastCollector *v5; // r15
  hkpBroadPhase::hkpCastRayInput *v6; // r13
  hkp3AxisSweep *v7; // rbx
  __m128 v8; // xmm0
  __m128i v9; // xmm1
  __m128i v10; // xmm0
  __m128i v11; // xmm1
  int v12; // eax
  float *v13; // rdi
  unsigned int v14; // ecx
  int v15; // edx
  float *i; // rcx
  float *v17; // rax
  signed __int64 v18; // r11
  char v19; // dl
  __int64 *v20; // rbx
  __int128 *v21; // rsi
  signed __int64 v22; // r14
  int v23; // ecx
  __int64 v24; // r9
  unsigned int v25; // er8
  unsigned __int64 v26; // r10
  unsigned __int16 *v27; // rcx
  __int64 v28; // rax
  __int64 v29; // rax
  unsigned __int16 *j; // rcx
  __int64 v31; // rax
  __int64 v32; // rax
  int v33; // ebx
  hkLifoAllocator *v34; // rax
  float *v35; // r10
  int v36; // edx
  char *v37; // rcx
  int v38; // edx
  float *v39; // rcx
  __int64 v40; // rdx
  unsigned __int64 v41; // r12
  __int64 v42; // r9
  _QWORD *v43; // r13
  signed __int64 v44; // rdx
  int v45; // ecx
  _BYTE *v46; // r8
  _BYTE *v47; // r9
  int v48; // er14
  hkpBroadPhaseCastCollector *v49; // rsi
  hkpBroadPhaseHandle **v50; // r15
  float *v51; // rbx
  __int64 v52; // r13
  int v53; // er14
  hkpBroadPhaseCastCollector *v54; // rsi
  float *v55; // rbx
  __int64 v56; // r13
  int v57; // er14
  hkpBroadPhaseCastCollector *v58; // rsi
  float *v59; // rbx
  __int64 v60; // r13
  int v61; // er14
  hkpBroadPhaseCastCollector *v62; // rsi
  float *v63; // rbx
  __int64 v64; // r15
  int v65; // er14
  int v66; // er12
  float *v67; // rsi
  __m128 v68; // xmm3
  __m128 v69; // xmm5
  float v70; // xmm7_4
  signed int v71; // er8
  __m128 *v72; // r11
  __int64 v73; // r9
  __int128 *v74; // r10
  __int64 v75; // rcx
  hkVector4f *v76; // rax
  __m128i v77; // xmm8
  __m128 v78; // xmm1
  __m128 v79; // xmm4
  __m128 v80; // xmm0
  __m128 v81; // xmm5
  __m128 v82; // xmm0
  __m128i v83; // xmm6
  __m128 v84; // xmm5
  __m128 v85; // xmm2
  __m128 v86; // xmm0
  __int64 v87; // rdx
  int v88; // ebx
  __m128 v89; // xmm0
  __m128 v90; // xmm1
  __m128 v91; // xmm3
  __m128 v92; // xmm0
  __int64 v93; // rax
  __int64 v94; // rbx
  char v95; // r14
  unsigned __int16 *v96; // rsi
  __int64 v97; // rcx
  signed __int64 v98; // rdx
  __int64 v99; // rcx
  unsigned __int16 v100; // cx
  unsigned __int16 *v101; // rdx
  float *v102; // r8
  unsigned __int64 v103; // r9
  int v104; // ecx
  int v105; // edx
  hkLifoAllocator *v106; // rax
  int v107; // er8
  __int64 v108; // [rsp+20h] [rbp-D0h]
  __int64 v109; // [rsp+28h] [rbp-C8h]
  _QWORD *v110; // [rsp+30h] [rbp-C0h]
  _QWORD *v111; // [rsp+38h] [rbp-B8h]
  int v112; // [rsp+38h] [rbp-B8h]
  float *p; // [rsp+40h] [rbp-B0h]
  hkpBroadPhaseHandle **v114; // [rsp+48h] [rbp-A8h]
  __m128i v115; // [rsp+50h] [rbp-A0h]
  float *v116; // [rsp+60h] [rbp-90h]
  __m128 v117; // [rsp+70h] [rbp-80h]
  int v118; // [rsp+80h] [rbp-70h]
  int v119; // [rsp+84h] [rbp-6Ch]
  unsigned __int16 *v120; // [rsp+88h] [rbp-68h]
  unsigned __int16 *v121; // [rsp+90h] [rbp-60h]
  unsigned __int16 *v122; // [rsp+98h] [rbp-58h]
  unsigned __int16 *v123; // [rsp+A0h] [rbp-50h]
  unsigned __int16 *v124; // [rsp+A8h] [rbp-48h]
  unsigned __int16 *v125; // [rsp+B0h] [rbp-40h]
  __int64 v126[5]; // [rsp+B8h] [rbp-38h]
  __int64 vars0; // [rsp+170h] [rbp+80h]
  hkpBroadPhase::hkpCastRayInput *retaddr; // [rsp+178h] [rbp+88h]
  hkp3AxisSweep *v129; // [rsp+180h] [rbp+90h]
  hkpBroadPhase::hkpCastRayInput *v130; // [rsp+188h] [rbp+98h]
  int v131; // [rsp+198h] [rbp+A8h]

  v131 = collectorStriding;
  v130 = rayInput;
  v129 = this;
  v4 = _mm_add_ps(rayInput->m_from.m_quad, this->m_offsetLow.m_quad);
  v117.m128_u64[0] = (unsigned __int64)collectorBase;
  v5 = collectorBase;
  v6 = rayInput;
  v7 = this;
  v8 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(v4, this->m_scale.m_quad), hkp3AxisSweep::MaxVal), (__m128)0i64);
  v9 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v8);
  v10 = _mm_cvttps_epi32(v8);
  v11 = _mm_sub_epi32(_mm_xor_si128(v9, v10), (__m128i)_xmm);
  v129 = (hkp3AxisSweep *)*(_OWORD *)&_mm_add_epi16(
                                        _mm_packs_epi32(v11, v11),
                                        (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v115.m128i_i32[0] = (unsigned __int16)v129;
  v115.m128i_i32[1] = WORD1(v129);
  v115.m128i_i32[2] = WORD2(v129);
  v115.m128i_i32[3] = HIWORD(v129);
  v12 = this->m_nodes.m_size + 16;
  if ( this->m_nodes.m_size == -16 )
  {
    v13 = 0i64;
  }
  else
  {
    LODWORD(v129) = this->m_nodes.m_size + 16;
    v13 = (float *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                     (int *)&v129);
    v12 = (signed int)v129;
  }
  v14 = 2147483648;
  if ( v12 )
    v14 = v12;
  v15 = v7->m_nodes.m_size >> 4;
  v116 = v13;
  v119 = v14;
  for ( i = v13; v15 >= 0; *(_OWORD *)v17 = 0i64 )
  {
    v17 = i;
    i += 4;
    --v15;
  }
  v18 = (signed __int64)v6->m_aabbCacheInfo;
  if ( !v18 )
    v18 = (signed __int64)v7->m_axis;
  v19 = 17;
  v20 = (__int64 *)&v123;
  v21 = (__int128 *)&v115;
  v22 = 3i64;
  do
  {
    v23 = *(_DWORD *)(v18 + 8);
    v24 = *(_QWORD *)v18;
    v25 = *(_DWORD *)v21;
    if ( *(_DWORD *)v21 >= (unsigned int)*(unsigned __int16 *)(*(_QWORD *)v18
                                                             + 4 * ((signed __int64)*(signed int *)(v18 + 8) >> 1)) )
    {
      for ( j = (unsigned __int16 *)(v24 + 4i64 * (v23 - 2)); (unsigned __int64)j >= v24 + 16; *((_BYTE *)v13 + j[3]) ^= v19 )
      {
        if ( *(j - 6) <= v25 )
          break;
        v31 = j[1];
        j -= 8;
        *((_BYTE *)v13 + v31) ^= v19;
        *((_BYTE *)v13 + j[7]) ^= v19;
        *((_BYTE *)v13 + j[5]) ^= v19;
      }
      for ( ; *j > v25; *((_BYTE *)v13 + v32) ^= v19 )
      {
        v32 = j[1];
        j -= 2;
      }
      v27 = j + 2;
    }
    else
    {
      v26 = v24 + 4i64 * (v23 - 4);
      v27 = (unsigned __int16 *)(v24 + 4);
      if ( v24 + 4 < v26 )
      {
        do
        {
          if ( v27[6] > v25 )
            break;
          v28 = v27[1];
          v27 += 8;
          *((_BYTE *)v13 + v28) ^= v19;
          *((_BYTE *)v13 + *(v27 - 5)) ^= v19;
          *((_BYTE *)v13 + *(v27 - 3)) ^= v19;
          *((_BYTE *)v13 + *(v27 - 1)) ^= v19;
        }
        while ( (unsigned __int64)v27 < v26 );
      }
      for ( ; *v27 <= v25; *((_BYTE *)v13 + v29) ^= v19 )
      {
        v29 = v27[1];
        v27 += 2;
      }
    }
    *v20 = (__int64)v27;
    ++v20;
    v19 *= 2;
    v18 += 16i64;
    v21 = (__int128 *)((char *)v21 + 4);
    --v22;
  }
  while ( v22 );
  v33 = v6->m_numCasts;
  v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (float *)v34->m_cur;
  v36 = (4 * v33 + 127) & 0xFFFFFF80;
  v118 = (4 * v33 + 127) & 0xFFFFFF80;
  p = v35;
  v37 = (char *)v35 + v36;
  if ( v36 > v34->m_slabSize || v37 > v34->m_end )
  {
    v35 = (float *)hkLifoAllocator::allocateFromNewSlab(v34, v36);
    p = v35;
  }
  else
  {
    v34->m_cur = v37;
  }
  v38 = 0;
  if ( v6->m_numCasts > 0 )
  {
    v39 = v35;
    do
    {
      *v39 = 1.0;
      ++v38;
      ++v39;
    }
    while ( v38 < v6->m_numCasts );
  }
  v40 = vars0;
  v41 = (unsigned __int64)v13;
  v42 = *(_QWORD *)(vars0 + 176);
  v115.m128i_i64[0] = (__int64)&v13[((signed __int64)*(signed int *)(vars0 + 184) >> 2) + 1];
  if ( (unsigned __int64)v13 < v115.m128i_i64[0] )
  {
    v43 = (_QWORD *)(v42 + 88);
    v44 = v42 + 64;
    v45 = retaddr->m_numCasts;
    v46 = (_BYTE *)(v42 + 40);
    v47 = (_BYTE *)(v42 + 16);
    v110 = v43;
    v114 = (hkpBroadPhaseHandle **)v44;
    v117.m128_u64[0] = (unsigned __int64)v47;
    v111 = v46;
    while ( !((*(_DWORD *)v41 + 16843009) & 0x8080808) )
    {
      if ( (*(_DWORD *)(v41 + 4) + 16843009) & 0x8080808 )
        goto LABEL_65;
      if ( (*(_DWORD *)(v41 + 8) + 16843009) & 0x8080808 )
      {
        v47 += 192;
        v46 += 192;
        v44 += 192i64;
        v43 += 24;
        v41 += 8i64;
      }
      else
      {
        v47 += 288;
        v46 += 288;
        v44 += 288i64;
        v43 += 36;
        v41 += 12i64;
      }
LABEL_66:
      v110 = v43;
      v114 = (hkpBroadPhaseHandle **)v44;
      v111 = v46;
      v117.m128_u64[0] = (unsigned __int64)v47;
      if ( v41 >= v115.m128i_i64[0] )
      {
        v13 = v116;
        v6 = retaddr;
        v40 = vars0;
        goto LABEL_68;
      }
      v35 = p;
    }
    if ( *(_BYTE *)v41 == 119 && !(*v47 & 1) )
    {
      v48 = 0;
      v49 = v5;
      if ( v45 > 0 )
      {
        v50 = (hkpBroadPhaseHandle **)v117.m128_u64[0];
        v51 = v35;
        v52 = (signed int)v130;
        do
        {
          v49->vfptr->addBroadPhaseHandle(v49, *v50, v48++);
          v49 = (hkpBroadPhaseCastCollector *)((char *)v49 + v52);
          ++v51;
          LODWORD(v108) = v10.m128i_i32[0];
          v10.m128i_i32[0] = *(int *)(v51 - 1);
          *(float *)&v109 = *(v51 - 1);
          *(v51 - 1) = fminf(*(float *)&v109, *(float *)&v108);
          v45 = retaddr->m_numCasts;
        }
        while ( v48 < v45 );
        v5 = (hkpBroadPhaseCastCollector *)v117.m128_u64[0];
        v43 = v110;
        v46 = v111;
      }
    }
    if ( *(_BYTE *)(v41 + 1) == 119 && !(*v46 & 1) )
    {
      v45 = retaddr->m_numCasts;
      v53 = 0;
      v54 = v5;
      if ( v45 > 0 )
      {
        v55 = p;
        v56 = (signed int)v130;
        do
        {
          v54->vfptr->addBroadPhaseHandle(v54, (hkpBroadPhaseHandle *)*v111, v53++);
          v54 = (hkpBroadPhaseCastCollector *)((char *)v54 + v56);
          ++v55;
          LODWORD(v108) = v10.m128i_i32[0];
          v10.m128i_i32[0] = *(int *)(v55 - 1);
          *(float *)&v109 = *(v55 - 1);
          *(v55 - 1) = fminf(*(float *)&v109, *(float *)&v108);
          v45 = retaddr->m_numCasts;
        }
        while ( v53 < v45 );
        v5 = (hkpBroadPhaseCastCollector *)v117.m128_u64[0];
        v43 = v110;
      }
    }
    if ( *(_BYTE *)(v41 + 2) == 119 && !(*(_BYTE *)v114 & 1) )
    {
      v45 = retaddr->m_numCasts;
      v57 = 0;
      v58 = v5;
      if ( v45 > 0 )
      {
        v59 = p;
        v60 = (signed int)v130;
        do
        {
          v58->vfptr->addBroadPhaseHandle(v58, *v114, v57++);
          v58 = (hkpBroadPhaseCastCollector *)((char *)v58 + v60);
          ++v59;
          LODWORD(v108) = v10.m128i_i32[0];
          v10.m128i_i32[0] = *(int *)(v59 - 1);
          *(float *)&v109 = *(v59 - 1);
          *(v59 - 1) = fminf(*(float *)&v109, *(float *)&v108);
          v45 = retaddr->m_numCasts;
        }
        while ( v57 < v45 );
        v5 = (hkpBroadPhaseCastCollector *)v117.m128_u64[0];
        v43 = v110;
      }
    }
    if ( *(_BYTE *)(v41 + 3) == 119 && !(*(_BYTE *)v43 & 1) )
    {
      v45 = retaddr->m_numCasts;
      v61 = 0;
      v62 = v5;
      if ( v45 > 0 )
      {
        v63 = p;
        v64 = (signed int)v130;
        do
        {
          v62->vfptr->addBroadPhaseHandle(v62, (hkpBroadPhaseHandle *)*v43, v61++);
          v62 = (hkpBroadPhaseCastCollector *)((char *)v62 + v64);
          ++v63;
          LODWORD(v108) = v10.m128i_i32[0];
          v10.m128i_i32[0] = *(int *)(v63 - 1);
          *(float *)&v109 = *(v63 - 1);
          *(v63 - 1) = fminf(*(float *)&v109, *(float *)&v108);
          v45 = retaddr->m_numCasts;
        }
        while ( v61 < v45 );
        v5 = (hkpBroadPhaseCastCollector *)v117.m128_u64[0];
      }
    }
    v47 = (_BYTE *)v117.m128_u64[0];
    v46 = v111;
    v44 = (signed __int64)v114;
LABEL_65:
    v47 += 96;
    v46 += 96;
    v44 += 96i64;
    v43 += 12;
    v41 += 4i64;
    goto LABEL_66;
  }
LABEL_68:
  *(_BYTE *)v13 = -120;
  v65 = *(_DWORD *)(v40 + 184);
  v66 = 0;
  v112 = *(_DWORD *)(v40 + 184);
  if ( v6->m_numCasts > 0 )
  {
    v67 = p;
    v116 = p;
    while ( 1 )
    {
      v68 = *(__m128 *)(v40 + 112);
      v69 = v6->m_from.m_quad;
      v70 = *v67;
      v120 = v123;
      v121 = v124;
      v71 = 0;
      v122 = v125;
      v72 = (__m128 *)`hkVector4f::getComponent'::`2'::indexToMask;
      LODWORD(v73) = 1;
      v74 = (__int128 *)&v117;
      v75 = v6->m_toStriding * v66;
      v76 = v6->m_toBase;
      v77 = (__m128i)_mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v76->m_quad + v75), v69), v68);
      v78 = _mm_rcp_ps((__m128)v77);
      v79 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v77, 1u), 1u);
      v80 = *(__m128 *)(v40 + 80);
      v81 = _mm_add_ps(v69, v80);
      v82 = _mm_add_ps(v80, *(__m128 *)((char *)&v76->m_quad + v75));
      v83 = (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps((__m128)v77, v78)), v78);
      v84 = _mm_mul_ps(v81, v68);
      v115 = v83;
      v85 = _mm_cmpltps(
              v79,
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_mul_ps(_mm_mul_ps(v82, v68), *(__m128 *)&epsilon), 1u),
                        1u));
      v86 = (__m128)*(unsigned int *)(v40 + 256);
      v87 = 0i64;
      v88 = _mm_movemask_ps(
              _mm_or_ps(
                v85,
                _mm_cmpltps(
                  v79,
                  (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_mul_ps(v84, *(__m128 *)&epsilon), 1u), 1u))));
      v117 = _mm_mul_ps(_mm_sub_ps(v84, _mm_shuffle_ps(v86, v86, 0)), (__m128)v83);
      do
      {
        if ( (unsigned int)v73 & v88 )
        {
          if ( v71 == 1 )
          {
            *(_DWORD *)v74 = -1073741824;
            v83 = (__m128i)_mm_shuffle_ps(_mm_unpacklo_ps((__m128)v83, (__m128)0i64), (__m128)v83, 228);
            v115 = v83;
          }
          else if ( v71 == 2 )
          {
            *(_DWORD *)v74 = -1073741824;
            v83 = (__m128i)_mm_shuffle_ps((__m128)v83, _mm_unpackhi_ps((__m128)v83, (__m128)0i64), 180);
            v115 = v83;
          }
          else
          {
            if ( v71 == 3 )
            {
              *(_DWORD *)v74 = -1073741824;
              v83 = _mm_srli_si128(_mm_slli_si128(v83, 4), 4);
            }
            else
            {
              *(_DWORD *)v74 = -1073741824;
              v83 = _mm_slli_si128(_mm_srli_si128(v83, 4), 4);
            }
            v115 = v83;
          }
        }
        else
        {
          v126[v87] = 4i64;
          v89 = _mm_and_ps((__m128)v77, *v72);
          v90 = _mm_or_ps(_mm_shuffle_ps(v89, v89, 78), v89);
          if ( COERCE_FLOAT(*(unsigned __int128 *)&_mm_shuffle_ps(v90, v90, 177) | v90.m128_i32[0]) < 0.0 )
          {
            (&v120)[v87] -= 2;
            v126[v87] = -4i64;
          }
        }
        v73 = (unsigned int)__ROL4__(v73, 1);
        ++v71;
        v74 = (__int128 *)((char *)v74 + 4);
        ++v72;
        ++v87;
      }
      while ( v71 < 3 );
      v91 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_unpacklo_ps(
                  _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)*v120), (__m128)COERCE_UNSIGNED_INT((float)*v122)),
                  _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)*v121), (__m128)0i64)),
                (__m128)v83),
              v117);
      v92 = _mm_shuffle_ps(v91, v91, 0);
      v117 = v91;
      v93 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                    _mm_and_ps(
                                                                      _mm_cmpleps(
                                                                        v91,
                                                                        _mm_min_ps(
                                                                          _mm_shuffle_ps(v91, v91, 170),
                                                                          _mm_min_ps(_mm_shuffle_ps(v91, v91, 85), v92))),
                                                                      (__m128)xmmword_141A81740))];
      v94 = (unsigned int)v93;
      if ( v70 >= v117.m128_f32[v93] )
        break;
LABEL_93:
      if ( v66 < v6->m_numCasts - 1 )
      {
        v102 = v13;
        v103 = (unsigned __int64)&v13[((signed __int64)v65 >> 2) + 1];
        if ( (unsigned __int64)v13 < v103 )
        {
          do
          {
            v104 = *(_DWORD *)v102;
            v105 = *((_DWORD *)v102 + 1);
            v102 += 2;
            *((_DWORD *)v102 - 2) = v104 & 0xF0F0F0F | 16 * (v104 & 0xF0F0F0F);
            *((_DWORD *)v102 - 1) = v105 & 0xF0F0F0F | 16 * (v105 & 0xF0F0F0F);
          }
          while ( (unsigned __int64)v102 < v103 );
        }
      }
      v40 = vars0;
      ++v67;
      ++v66;
      v5 = (hkpBroadPhaseCastCollector *)((char *)v5 + (signed int)v130);
      v116 = v67;
      if ( v66 >= v6->m_numCasts )
        goto LABEL_97;
    }
LABEL_84:
    v95 = 1 << (v93 + 4);
    while ( 1 )
    {
      v96 = (&v120)[v94];
      v97 = v96[1];
      *((_BYTE *)v13 + v97) ^= v95;
      if ( *((_BYTE *)v13 + v97) >= 0x70u )
      {
        if ( !(_DWORD)v97 )
        {
          v117.m128_i32[v94] = 0x40000000;
LABEL_91:
          v92 = _mm_shuffle_ps(v117, v117, 0);
          v93 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                        _mm_and_ps(
                                                                          _mm_cmpleps(
                                                                            v117,
                                                                            _mm_min_ps(
                                                                              _mm_shuffle_ps(v117, v117, 170),
                                                                              _mm_min_ps(
                                                                                _mm_shuffle_ps(v117, v117, 85),
                                                                                v92))),
                                                                          (__m128)xmmword_141A81740))];
          v94 = (unsigned int)v93;
          if ( v70 < v117.m128_f32[v93] )
          {
            v6 = retaddr;
            v67 = v116;
            v65 = v112;
            goto LABEL_93;
          }
          goto LABEL_84;
        }
        v98 = 3 * v97;
        v99 = *(_QWORD *)(vars0 + 176);
        if ( !(*(_BYTE *)(v99 + 8 * v98 + 16) & 1) )
        {
          ((void (__fastcall *)(hkpBroadPhaseCastCollector *, _QWORD, _QWORD, __int64, __int64, __int64))v5->vfptr->addBroadPhaseHandle)(
            v5,
            *(_QWORD *)(v99 + 8 * v98 + 16),
            (unsigned int)v66,
            v73,
            v108,
            v109);
          *(float *)&v108 = v70;
          LODWORD(v109) = v92.m128_i32[0];
          v70 = fminf(v70, v92.m128_f32[0]);
        }
      }
      v100 = *v96;
      v101 = (unsigned __int16 *)((char *)v96 + v126[v94]);
      (&v120)[v94] = v101;
      if ( v100 != *v101 )
      {
        v117.m128_f32[v94] = (float)((float)*v101 * *(float *)&v115.m128i_i32[v94]) - v117.m128_f32[v94];
        goto LABEL_91;
      }
    }
  }
LABEL_97:
  v106 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v107 = (v118 + 15) & 0xFFFFFFF0;
  if ( v118 > v106->m_slabSize || (char *)p + v107 != v106->m_cur || v106->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v106, p, v107);
  else
    v106->m_cur = p;
  if ( v119 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v13,
      v119 & 0x3FFFFFFF);
}      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v13,
      v119 & 0x3FFFFFFF);
}

// File Line: 4016
// RVA: 0xD02B40
void __fastcall hkp3AxisSweep::castAabb(hkp3AxisSweep *this, hkpBroadPhase::hkpCastAabbInput *input, hkpBroadPhaseCastCollector *collector)
{
  hkpBroadPhaseCastCollector *v3; // r14
  hkpBroadPhase::hkpCastAabbInput *v4; // r12
  hkp3AxisSweep *v5; // r13
  __m128 v6; // xmm13
  __m128 v7; // xmm14
  __m128 v8; // xmm0
  __m128i v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm0
  __m128i v12; // xmm7
  __m128i v13; // xmm0
  __m128i v14; // xmm7
  __int64 v15; // ST30_8
  int v16; // eax
  _BYTE *v17; // rbx
  unsigned int v18; // ecx
  int v19; // edx
  _OWORD *i; // rcx
  _OWORD *v21; // rax
  signed __int64 v22; // rsi
  __int64 v23; // rdi
  __int64 v24; // r11
  char v25; // r8
  signed __int64 v26; // r15
  int v27; // ecx
  __int64 v28; // rdx
  unsigned int v29; // er9
  unsigned __int64 v30; // r10
  unsigned __int16 *k; // rdx
  __int64 v32; // rax
  __int64 v33; // rax
  unsigned int v34; // er9
  unsigned int v35; // eax
  char v36; // al
  __int64 v37; // rcx
  unsigned __int64 v38; // r10
  unsigned __int16 *v39; // rdx
  unsigned int v40; // ecx
  __int64 v41; // rax
  unsigned int j; // ecx
  __int64 v43; // rax
  char v44; // al
  __int64 v45; // rcx
  float v46; // xmm11_4
  _BYTE *v47; // rsi
  unsigned __int64 v48; // r15
  hkpBroadPhaseHandle **v49; // rdi
  __m128 v50; // xmm9
  __m128 v51; // xmm6
  __m128 v52; // xmm4
  signed int v53; // er11
  __int64 v54; // r9
  __int64 v55; // r8
  signed int v56; // er10
  __m128 v57; // xmm7
  __m128 v58; // xmm3
  __m128i v59; // xmm2
  __m128 v60; // xmm1
  __m128 v61; // xmm8
  __m128 v62; // xmm5
  int v63; // edi
  __m128i v64; // xmm10
  __m128 v65; // xmm3
  int v66; // esi
  int v67; // ecx
  unsigned __int16 *v68; // rdx
  unsigned __int64 v69; // rax
  unsigned __int16 *v70; // r9
  unsigned __int16 *v71; // r10
  signed int v72; // eax
  __m128 v73; // xmm4
  signed int v74; // eax
  __m128 v75; // xmm4
  __m128 v76; // xmm5
  __m128i v77; // xmm2
  signed int v78; // eax
  int v79; // er15
  int v80; // eax
  int v81; // er12
  float v82; // xmm0_4
  float v83; // xmm1_4
  int v84; // er13
  unsigned __int16 *v85; // rdi
  __int64 v86; // rdx
  int v87; // eax
  signed __int64 v88; // rdx
  __int64 v89; // rcx
  unsigned __int16 v90; // cx
  unsigned __int16 *v91; // rdx
  unsigned __int8 v92; // r10
  unsigned __int16 *v93; // r8
  __int64 v94; // rdx
  unsigned __int16 v95; // cx
  unsigned __int16 *v96; // rdx
  signed int v97; // [rsp+30h] [rbp-98h]
  __m128 v98; // [rsp+40h] [rbp-88h]
  __m128 v99; // [rsp+50h] [rbp-78h]
  unsigned __int16 *v100; // [rsp+60h] [rbp-68h]
  unsigned __int16 *v101; // [rsp+68h] [rbp-60h]
  unsigned __int16 *v102; // [rsp+70h] [rbp-58h]
  __m128 v103; // [rsp+88h] [rbp-40h]
  __m128 v104; // [rsp+98h] [rbp-30h]
  int v105[4]; // [rsp+A8h] [rbp-20h]
  unsigned __int16 *v106; // [rsp+B8h] [rbp-10h]
  unsigned __int16 *v107; // [rsp+C0h] [rbp-8h]
  unsigned __int16 *v108; // [rsp+C8h] [rbp+0h]
  __int64 v109[28]; // [rsp+D0h] [rbp+8h]
  __int64 v110; // [rsp+1B8h] [rbp+F0h]
  int v111; // [rsp+1C0h] [rbp+F8h]
  float v112; // [rsp+1D0h] [rbp+108h]

  v3 = collector;
  v4 = input;
  v5 = this;
  v6 = _mm_add_ps(input->m_from.m_quad, input->m_halfExtents.m_quad);
  v7 = _mm_sub_ps(input->m_from.m_quad, input->m_halfExtents.m_quad);
  v8 = _mm_max_ps(
         _mm_min_ps(_mm_mul_ps(_mm_add_ps(v7, this->m_offsetLow.m_quad), this->m_scale.m_quad), hkp3AxisSweep::MaxVal),
         (__m128)0i64);
  v9 = _mm_sub_epi32(
         _mm_xor_si128(
           (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v8),
           _mm_cvttps_epi32(v8)),
         (__m128i)_xmm);
  v9.m128i_i64[0] = (unsigned __int128)_mm_add_epi16(
                                         _mm_packs_epi32(v9, v9),
                                         (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v10 = _mm_min_ps(_mm_mul_ps(_mm_add_ps(v6, this->m_offsetLow.m_quad), this->m_scale.m_quad), hkp3AxisSweep::MaxVal);
  v99.m128_i32[0] = v9.m128i_u16[0];
  v99.m128_i32[1] = v9.m128i_u16[1];
  v11 = _mm_max_ps(v10, (__m128)0i64);
  v12 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32'::`2'::two31, v11);
  v13 = _mm_cvttps_epi32(v11);
  v99.m128_i32[2] = v9.m128i_u16[2];
  v99.m128_i32[3] = v9.m128i_u16[3];
  v14 = _mm_sub_epi32(_mm_xor_si128(v12, v13), (__m128i)_xmm);
  v15 = (unsigned __int128)_mm_add_epi16(
                             _mm_packs_epi32(v14, v14),
                             (__m128i)`hkIntVector::setConvertSaturateS32ToU16'::`2'::offset2);
  v98.m128_i32[0] = (unsigned __int16)v15;
  v98.m128_i32[1] = WORD1(v15);
  v98.m128_i32[2] = WORD2(v15);
  v98.m128_i32[3] = HIWORD(v15);
  v16 = this->m_nodes.m_size + 16;
  if ( this->m_nodes.m_size == -16 )
  {
    v17 = 0i64;
  }
  else
  {
    v111 = this->m_nodes.m_size + 16;
    v17 = (_BYTE *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                     (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                     &v111);
    v16 = v111;
  }
  v18 = 2147483648;
  if ( v16 )
    v18 = v16;
  v19 = v5->m_nodes.m_size >> 4;
  v97 = v18;
  for ( i = v17; v19 >= 0; *v21 = 0i64 )
  {
    v21 = i;
    ++i;
    --v19;
  }
  v22 = (signed __int64)v4->m_aabbCacheInfo;
  if ( !v22 )
    v22 = (signed __int64)v5->m_axis;
  v23 = 0i64;
  v24 = 0i64;
  v25 = 1;
  v26 = 3i64;
  do
  {
    v27 = *(_DWORD *)(v22 + 8);
    v28 = *(_QWORD *)v22;
    v29 = v99.m128_u32[v23];
    if ( v29 >= *(unsigned __int16 *)(*(_QWORD *)v22 + 4 * ((signed __int64)*(signed int *)(v22 + 8) >> 1)) )
    {
      v38 = v28 + 16;
      v39 = (unsigned __int16 *)(v28 + 4i64 * (v27 - 2));
      if ( (unsigned __int64)v39 >= v38 )
      {
        v40 = v98.m128_u32[v23];
        do
        {
          if ( *(v39 - 6) <= v40 )
            break;
          v41 = v39[1];
          v39 -= 8;
          v17[v41] ^= v25;
          v17[v39[7]] ^= v25;
          v17[v39[5]] ^= v25;
          v17[v39[3]] ^= v25;
        }
        while ( (unsigned __int64)v39 >= v38 );
      }
      for ( j = v98.m128_u32[v23]; *v39 > j; v17[v43] ^= v25 )
      {
        v43 = v39[1];
        v39 -= 2;
      }
      for ( v99.m128_u64[v24 + 1] = (unsigned __int64)(v39 + 2); *v39 > v29; v17[v45] ^= v25 & (unsigned __int8)-(v44 & 1) )
      {
        v44 = *(_BYTE *)v39;
        v45 = v39[1];
        v39 -= 2;
      }
      (&v100)[v24] = v39 + 2;
    }
    else
    {
      v30 = v28 + 4i64 * (v27 - 4);
      for ( k = (unsigned __int16 *)(v28 + 4); (unsigned __int64)k < v30; v17[*(k - 1)] ^= v25 )
      {
        if ( k[6] > v29 )
          break;
        v32 = k[1];
        k += 8;
        v17[v32] ^= v25;
        v17[*(k - 5)] ^= v25;
        v17[*(k - 3)] ^= v25;
      }
      for ( ; *k <= v29; v17[v33] ^= v25 )
      {
        v33 = k[1];
        k += 2;
      }
      v34 = v98.m128_u32[v23];
      v35 = *k;
      (&v100)[v24] = k;
      if ( v35 <= v34 )
      {
        do
        {
          v36 = *(_BYTE *)k;
          v37 = k[1];
          k += 2;
          v17[v37] ^= v25 & (unsigned __int8)((v36 & 1) - 1);
        }
        while ( *k <= v34 );
      }
      v99.m128_u64[v24 + 1] = (unsigned __int64)k;
    }
    v25 *= 2;
    v22 += 16i64;
    ++v23;
    ++v24;
    --v26;
  }
  while ( v26 );
  v46 = *(float *)&FLOAT_1_0;
  v47 = v17;
  v48 = (unsigned __int64)&v17[4 * (((signed __int64)v5->m_nodes.m_size >> 2) + 1)];
  if ( (unsigned __int64)v17 < v48 )
  {
    v49 = &v5->m_nodes.m_data[1].m_handle;
    do
    {
      if ( (*(_DWORD *)v47 + 16843009) & 0x8080808 )
      {
        if ( *v47 == 7 && !(*(_BYTE *)(v49 - 3) & 1) )
        {
          v3->vfptr->addBroadPhaseHandle(v3, *(v49 - 3), 0);
          v112 = v46;
          v46 = fminf(v46, *(float *)v13.m128i_i32);
        }
        if ( v47[1] == 7 && !(*(_BYTE *)v49 & 1) )
        {
          v3->vfptr->addBroadPhaseHandle(v3, *v49, 0);
          v112 = v46;
          v46 = fminf(v46, *(float *)v13.m128i_i32);
        }
        if ( v47[2] == 7 && !((_BYTE)v49[3] & 1) )
        {
          v3->vfptr->addBroadPhaseHandle(v3, v49[3], 0);
          v112 = v46;
          v46 = fminf(v46, *(float *)v13.m128i_i32);
        }
        if ( v47[3] == 7 && !((_BYTE)v49[6] & 1) )
        {
          v3->vfptr->addBroadPhaseHandle(v3, v49[6], 0);
          v112 = v46;
          v46 = fminf(v46, *(float *)v13.m128i_i32);
        }
      }
      v47 += 4;
      v49 += 12;
    }
    while ( (unsigned __int64)v47 < v48 );
  }
  v50 = v5->m_scale.m_quad;
  v51 = v4->m_to.m_quad;
  v52 = v5->m_offsetLow.m_quad;
  v53 = 0;
  v54 = 0i64;
  v55 = 0i64;
  v56 = 1;
  v57 = _mm_shuffle_ps(
          (__m128)LODWORD(v5->m_intToFloatFloorCorrection),
          (__m128)LODWORD(v5->m_intToFloatFloorCorrection),
          0);
  v58 = v5->m_offsetLow.m_quad;
  v59 = (__m128i)_mm_mul_ps(_mm_sub_ps(v4->m_to.m_quad, v4->m_from.m_quad), v50);
  v60 = _mm_rcp_ps((__m128)v59);
  v61 = _mm_cmpltps((__m128)0i64, (__m128)v59);
  v62 = (__m128)_mm_srli_epi32(_mm_slli_epi32(v59, 1u), 1u);
  v63 = _mm_movemask_ps(v61);
  v64 = (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v60, (__m128)v59)), v60);
  *(__m128i *)((char *)&v98 + 8) = v64;
  v65 = _mm_mul_ps(_mm_add_ps(v58, _mm_or_ps(_mm_andnot_ps(v61, v6), _mm_and_ps(v7, v61))), v50);
  v104 = _mm_mul_ps(_mm_sub_ps(v65, v57), (__m128)v64);
  v66 = _mm_movemask_ps(
          _mm_or_ps(
            _mm_cmpltps(v62, _mm_mul_ps(_mm_mul_ps(_mm_add_ps(v51, v52), v50), *(__m128 *)&epsilon)),
            _mm_cmpltps(v62, _mm_mul_ps(v65, *(__m128 *)&epsilon))));
  v103 = _mm_mul_ps(
           _mm_sub_ps(_mm_mul_ps(_mm_add_ps(_mm_or_ps(_mm_andnot_ps(v61, v7), _mm_and_ps(v6, v61)), v52), v50), v57),
           (__m128)v64);
  do
  {
    if ( v63 & v56 )
    {
      v109[v54] = 4i64;
      *(_DWORD *)((char *)&v102 + v55 * 4) = 0;
      v105[v55] = 1;
    }
    else
    {
      v67 = v99.m128_i32[v55];
      v68 = (&v100)[v54];
      v99.m128_i32[v55] = v98.m128_i32[v55];
      v69 = v99.m128_u64[v54 + 1];
      v109[v54] = -4i64;
      v98.m128_i32[v55] = v67;
      *(_DWORD *)((char *)&v102 + v55 * 4) = 1;
      (&v100)[v54] = (unsigned __int16 *)(v69 - 4);
      v105[v55] = 0;
      v99.m128_u64[v54 + 1] = (unsigned __int64)(v68 - 2);
    }
    if ( v66 & v56 )
    {
      switch ( v53 )
      {
        case 1:
          v64 = (__m128i)_mm_shuffle_ps(_mm_unpacklo_ps((__m128)v64, (__m128)0i64), (__m128)v64, 228);
          break;
        case 2:
          v64 = (__m128i)_mm_shuffle_ps((__m128)v64, _mm_unpackhi_ps((__m128)v64, (__m128)0i64), 180);
          break;
        case 3:
          v64 = _mm_srli_si128(_mm_slli_si128(v64, 4), 4);
          break;
        default:
          v64 = _mm_slli_si128(_mm_srli_si128(v64, 4), 4);
          break;
      }
      *(__m128i *)((char *)&v98 + 8) = v64;
      v104.m128_i32[v55] = -1073741824;
      v103.m128_i32[v55] = -1073741824;
    }
    v56 = __ROL4__(v56, 1);
    ++v53;
    ++v54;
    ++v55;
  }
  while ( v53 < 3 );
  v70 = v100;
  v71 = v101;
  v106 = v100;
  v72 = *v100;
  v107 = v101;
  v108 = v102;
  v100 = (unsigned __int16 *)v99.m128_u64[1];
  v73 = (__m128)COERCE_UNSIGNED_INT((float)v72);
  v74 = *v101;
  v101 = v70;
  v102 = v71;
  v75 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(v73, (__m128)COERCE_UNSIGNED_INT((float)*v108)),
          _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v74), (__m128)0i64));
  v76 = (__m128)COERCE_UNSIGNED_INT((float)*(unsigned __int16 *)v99.m128_u64[1]);
  v77 = _mm_cvtsi32_si128(*v70);
  v78 = *v71;
  *v17 = 8;
  v98 = _mm_sub_ps(_mm_mul_ps(v75, (__m128)v64), v104);
  v99 = _mm_sub_ps(
          _mm_mul_ps(
            _mm_unpacklo_ps(
              _mm_unpacklo_ps(v76, (__m128)COERCE_UNSIGNED_INT((float)v78)),
              _mm_unpacklo_ps(_mm_cvtepi32_ps(v77), (__m128)0i64)),
            (__m128)v64),
          v103);
  v79 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                _mm_and_ps(
                                                                  _mm_cmpleps(
                                                                    v98,
                                                                    _mm_min_ps(
                                                                      _mm_shuffle_ps(v98, v98, 170),
                                                                      _mm_min_ps(
                                                                        _mm_shuffle_ps(v98, v98, 85),
                                                                        _mm_shuffle_ps(v98, v98, 0)))),
                                                                  (__m128)xmmword_141A81740))];
  v80 = _mm_movemask_ps(
          _mm_and_ps(
            _mm_cmpleps(
              v99,
              _mm_min_ps(
                _mm_shuffle_ps(v99, v99, 170),
                _mm_min_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)))),
            (__m128)xmmword_141A81740));
LABEL_61:
  v81 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[v80];
  while ( 1 )
  {
    v82 = v99.m128_f32[v81];
    v83 = v98.m128_f32[v79];
    if ( v82 < v83 )
      break;
    if ( v83 > v46 )
      goto LABEL_81;
    v92 = *((_BYTE *)&v102 + 4 * v79);
    while ( 1 )
    {
      v93 = (&v106)[v79];
      v94 = v93[1];
      v17[v94] ^= (v92 ^ *(_BYTE *)v93 & 1) << v79;
      if ( v17[v94] > 8u )
        break;
      v95 = *v93;
      v96 = (unsigned __int16 *)((char *)v93 + v109[v79]);
      (&v106)[v79] = v96;
      if ( v95 != *v96 )
      {
        v98.m128_f32[v79] = (float)((float)*v96 * v98.m128_f32[v79 + 2]) - v104.m128_f32[v79];
        goto LABEL_79;
      }
    }
    v98.m128_i32[v79] = 0x40000000;
LABEL_79:
    v79 = (unsigned __int8)hkVector4Comparison_maskToFirstIndex[_mm_movemask_ps(
                                                                  _mm_and_ps(
                                                                    _mm_cmpleps(
                                                                      v98,
                                                                      _mm_min_ps(
                                                                        _mm_shuffle_ps(v98, v98, 170),
                                                                        _mm_min_ps(
                                                                          _mm_shuffle_ps(v98, v98, 85),
                                                                          _mm_shuffle_ps(v98, v98, 0)))),
                                                                    (__m128)xmmword_141A81740))];
  }
  if ( v82 <= v46 )
  {
    v84 = v105[v81];
    while ( 1 )
    {
      v85 = (&v100)[v81];
      v86 = v85[1];
      v87 = (v84 ^ *v85 & 1) << v81;
      v17[v86] ^= v87;
      if ( v17[v86] >= 7u )
      {
        if ( !(_DWORD)v86 )
        {
          v99.m128_i32[v81] = 0x40000000;
LABEL_72:
          v80 = _mm_movemask_ps(
                  _mm_and_ps(
                    _mm_cmpleps(
                      v99,
                      _mm_min_ps(
                        _mm_shuffle_ps(v99, v99, 170),
                        _mm_min_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)))),
                    (__m128)xmmword_141A81740));
          goto LABEL_61;
        }
        v88 = 3 * v86;
        v89 = *(_QWORD *)(v110 + 176);
        if ( v87 )
        {
          if ( !(*(_BYTE *)(v89 + 8 * v88 + 16) & 1) )
          {
            v3->vfptr->addBroadPhaseHandle(v3, *(hkpBroadPhaseHandle **)(v89 + 8 * v88 + 16), 0);
            v112 = v46;
            v46 = fminf(v46, v82);
          }
        }
      }
      v90 = *v85;
      v91 = (unsigned __int16 *)((char *)v85 + v109[v81]);
      (&v100)[v81] = v91;
      if ( v90 != *v91 )
      {
        v99.m128_f32[v81] = (float)((float)*v91 * v98.m128_f32[v81 + 2]) - v103.m128_f32[v81];
        goto LABEL_72;
      }
    }
  }
LABEL_81:
  if ( v97 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v17,
      v97 & 0x3FFFFFFF);
}2);
          }
        }
      }
      v90 = *v85;
      v91 = (unsigned __int16 *)((char *)v85 + v109[v81]);
      (&v100)[v81] = v91;
      if ( v90 != *v91 )
      {
        v99.m128_f32[v81] = (float

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
void __fastcall hkp3AxisSweep::shiftAllObjects(hkp3AxisSweep *this, hkVector4f *shiftDistance, hkVector4f *effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newCollisionPairs)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  hkp3AxisSweep *v6; // r11
  __int64 v7; // rax
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  __int64 v11; // rax
  float v12; // xmm0_4
  __int64 v13; // rax
  float v14; // xmm0_4
  __int64 v15; // rax
  hkVector4f v16; // xmm0
  int v17; // er9
  signed __int64 v18; // r8
  int v19; // eax
  int v20; // ecx
  signed int v21; // edx
  __int64 v22; // rbx
  __int64 v23; // r8
  int v24; // ecx
  signed __int64 v25; // rax
  hkp3AxisSweep::hkpBpNode *v26; // r10
  int v27; // ecx
  int v28; // edx
  signed __int64 v29; // r9
  signed int v30; // ecx
  hkp3AxisSweep::hkpBpEndPoint *v31; // r8
  hkp3AxisSweep::hkpBpEndPoint *v32; // rdx
  unsigned int v33; // er13
  hkp3AxisSweep::hkpBpNode *v34; // r14
  int v35; // ecx
  __int64 v36; // rax
  hkp3AxisSweep::hkpBpEndPoint *v37; // rcx
  unsigned int v38; // er15
  __int64 v39; // rax
  hkpBroadPhaseHandle *v40; // rax
  __int64 v41; // r12
  __int64 v42; // rsi
  hkp3AxisSweep::hkpBpNode *v43; // rbx
  signed __int64 v44; // rdi
  unsigned int v45; // er9
  _DWORD *v46; // r8
  signed __int64 v47; // rcx
  signed __int64 v48; // rdx
  int v49; // ecx
  int v50; // eax
  _DWORD *v51; // rcx
  __int64 v52; // rdx
  int v53; // eax
  __int16 v54; // ax
  __int64 v55; // rsi
  signed __int64 v56; // rdi
  unsigned int v57; // er8
  signed __int64 v58; // rcx
  signed __int64 v59; // rdx
  int v60; // ecx
  signed __int64 v61; // rdx
  __int64 v62; // rcx
  int v63; // eax
  unsigned int v64; // er9
  _DWORD *v65; // r8
  __int64 v66; // rax
  signed __int64 v67; // rdx
  int v68; // ecx
  int v69; // eax
  _DWORD *v70; // rdx
  __int64 v71; // rcx
  int v72; // eax
  __int16 v73; // ax
  hkp3AxisSweep *v74; // r10
  __int64 v75; // rsi
  signed __int64 v76; // rdi
  unsigned int v77; // er9
  _DWORD *j; // r8
  signed __int64 v79; // rcx
  signed __int64 v80; // rdx
  int v81; // ecx
  signed __int64 v82; // rdx
  __int64 v83; // rcx
  int v84; // eax
  __int16 v85; // ax
  unsigned int v86; // er15
  __int64 v87; // rsi
  signed __int64 v88; // rdi
  unsigned int v89; // er9
  _DWORD *v90; // r8
  signed __int64 v91; // rcx
  hkp3AxisSweep::hkpBpNode *v92; // rdx
  __int16 v93; // cx
  __int16 v94; // ax
  _DWORD *v95; // rcx
  __int64 v96; // rdx
  int v97; // eax
  __int16 v98; // r15
  unsigned int v99; // er13
  __int64 v100; // rsi
  signed __int64 v101; // rdi
  unsigned int v102; // er8
  signed __int64 v103; // rcx
  hkp3AxisSweep::hkpBpNode *v104; // rdx
  __int16 v105; // cx
  __int16 v106; // ax
  signed __int64 v107; // rdx
  __int64 v108; // rcx
  int v109; // eax
  unsigned int v110; // er9
  _DWORD *v111; // r8
  __int64 v112; // rax
  hkp3AxisSweep::hkpBpNode *v113; // rdx
  unsigned __int16 v114; // cx
  unsigned __int16 v115; // ax
  _DWORD *v116; // rdx
  __int64 v117; // rcx
  int v118; // eax
  __int16 v119; // ax
  hkp3AxisSweep *v120; // r10
  unsigned int v121; // er13
  __int64 v122; // rsi
  signed __int64 v123; // rdi
  unsigned int v124; // er9
  _DWORD *v125; // r8
  signed __int64 v126; // rcx
  hkp3AxisSweep::hkpBpNode *v127; // rdx
  unsigned __int16 v128; // cx
  unsigned __int16 v129; // ax
  signed __int64 v130; // rdx
  __int64 v131; // rcx
  int v132; // eax
  unsigned int v133; // er15
  __int64 v134; // rsi
  signed __int64 v135; // rdi
  unsigned int v136; // er9
  _DWORD *v137; // r8
  signed __int64 v138; // rcx
  hkp3AxisSweep::hkpBpNode *v139; // rdx
  __int16 v140; // cx
  __int16 v141; // ax
  _DWORD *v142; // rcx
  __int64 v143; // rdx
  int v144; // eax
  __int16 v145; // r15
  unsigned int v146; // er13
  __int64 v147; // rsi
  signed __int64 v148; // rdi
  unsigned int v149; // er8
  signed __int64 v150; // rcx
  hkp3AxisSweep::hkpBpNode *v151; // rdx
  __int16 v152; // cx
  __int16 v153; // ax
  signed __int64 v154; // rdx
  __int64 v155; // rcx
  int v156; // eax
  unsigned int v157; // er9
  _DWORD *v158; // r8
  __int64 v159; // rax
  hkp3AxisSweep::hkpBpNode *v160; // rdx
  unsigned __int16 v161; // cx
  unsigned __int16 v162; // ax
  _DWORD *v163; // rcx
  __int64 v164; // rdx
  int v165; // eax
  __int16 v166; // ax
  unsigned int v167; // er13
  __int64 v168; // rsi
  signed __int64 v169; // rdi
  unsigned int v170; // er9
  _DWORD *v171; // r8
  signed __int64 v172; // rcx
  hkp3AxisSweep::hkpBpNode *v173; // rdx
  unsigned __int16 v174; // cx
  unsigned __int16 v175; // ax
  signed __int64 v176; // rcx
  __int64 v177; // rdx
  int v178; // eax
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> deletedPairsOut; // [rsp+30h] [rbp-59h]
  unsigned int v180; // [rsp+40h] [rbp-49h]
  int v181; // [rsp+44h] [rbp-45h]
  unsigned int v182; // [rsp+48h] [rbp-41h]
  unsigned int v183; // [rsp+50h] [rbp-39h]
  unsigned int v184; // [rsp+54h] [rbp-35h]
  unsigned int v185; // [rsp+58h] [rbp-31h]
  __int64 v186; // [rsp+60h] [rbp-29h]
  __int64 v187; // [rsp+68h] [rbp-21h]
  __int64 i; // [rsp+70h] [rbp-19h]
  hkp3AxisSweep *v189; // [rsp+78h] [rbp-11h]
  __int64 v190; // [rsp+80h] [rbp-9h]
  __int64 v191; // [rsp+88h] [rbp-1h]
  __int64 v192; // [rsp+90h] [rbp+7h]
  __int64 v193; // [rsp+98h] [rbp+Fh]
  hkp3AxisSweep *v194; // [rsp+F0h] [rbp+67h]
  int v195; // [rsp+F8h] [rbp+6Fh]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairsOut; // [rsp+108h] [rbp+7Fh]

  newPairsOut = newCollisionPairs;
  v194 = this;
  v4 = this->m_scale.m_quad.m128_f32[0];
  v5 = this->m_scale.m_quad.m128_f32[2];
  deletedPairsOut = (hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator>)shiftDistance->m_quad;
  v6 = this;
  v7 = (signed int)(float)(v4 * *(float *)&deletedPairsOut.m_data) & 0xFFFFFFFE;
  v191 = v7;
  v8 = (float)(signed int)v7 / v4;
  v9 = this->m_scale.m_quad.m128_f32[1];
  v10 = this->m_scale.m_quad.m128_f32[1] * *((float *)&deletedPairsOut.m_data + 1);
  *(float *)&deletedPairsOut.m_data = v8;
  v11 = (signed int)v10 & 0xFFFFFFFE;
  v192 = v11;
  v12 = (float)(signed int)v11;
  v13 = (signed int)(float)(v5 * *(float *)&deletedPairsOut.m_size) & 0xFFFFFFFE;
  v193 = v13;
  *((float *)&deletedPairsOut.m_data + 1) = v12 / v9;
  v14 = (float)(signed int)v13;
  v15 = 0i64;
  v186 = 0i64;
  *(float *)&deletedPairsOut.m_size = v14 / v5;
  v16.m_quad = (__m128)deletedPairsOut;
  deletedPairsOut.m_data = 0i64;
  deletedPairsOut.m_size = 0;
  deletedPairsOut.m_capacityAndFlags = 2147483648;
  *effectiveShiftDistanceOut = (hkVector4f)v16.m_quad;
  do
  {
    v17 = *((_DWORD *)&v191 + 2 * v15);
    v195 = v17;
    v18 = (signed __int64)v6 + 16 * (v15 + 12);
    v189 = (hkp3AxisSweep *)((char *)v6 + 16 * (v15 + 12));
    if ( v17 >= 0 )
    {
      v20 = 0;
      v19 = *(_DWORD *)(v18 + 8) - 2;
      v21 = -1;
    }
    else
    {
      v19 = 1;
      v20 = *(_DWORD *)(v18 + 8) - 1;
      v21 = 1;
    }
    v22 = v19;
    v190 = v21;
    v187 = v19;
    for ( i = v20; v22 != i; v187 = v22 )
    {
      v23 = *(_QWORD *)v18;
      v24 = *(unsigned __int16 *)(v23 + 4 * v22);
      if ( (unsigned int)(v24 - 2) <= 0xFFF9 )
      {
        v25 = *(unsigned __int16 *)(v23 + 4 * v22 + 2);
        v26 = v6->m_nodes.m_data;
        v27 = v17 + v24;
        v28 = *(_WORD *)(v23 + 4 * v22) & 1;
        v29 = v25;
        v30 = v28 | v27 & 0xFFFFFFFE;
        if ( v30 >= 0 )
        {
          if ( v30 >= 65532 )
            v30 = v28 | 0xFFFC;
        }
        else
        {
          v30 = *(_WORD *)(v23 + 4 * v22) & 1;
        }
        *(_WORD *)(v23 + 4 * v22) = v30;
        if ( !v30 || v30 == 65533 )
        {
          v31 = v6->m_axis[0].m_endPoints.m_data;
          v32 = v6->m_axis[1].m_endPoints.m_data;
          v33 = v31[v26[v25].min_x].m_value;
          v34 = v6->m_nodes.m_data;
          v35 = v32[v26[v25].min_y].m_value;
          v36 = v26[v25].min_z;
          v180 = v33;
          v181 = v35;
          v37 = v6->m_axis[2].m_endPoints.m_data;
          v182 = v37[v36].m_value;
          v38 = v31[v26[v29].max_x].m_value;
          LODWORD(v31) = v32[v26[v29].max_y].m_value;
          v39 = v26[v29].max_z;
          v183 = v38;
          LODWORD(v32) = v37[v39].m_value;
          v40 = v26[v29].m_handle;
          v184 = (unsigned int)v31;
          v41 = v40->m_id;
          v185 = (unsigned int)v32;
          v42 = v34[v41].min_x;
          v43 = &v34[v41];
          v44 = (signed __int64)&v6->m_axis[0].m_endPoints.m_data[v42];
          v45 = *(unsigned __int16 *)(v44 - 4);
          v46 = (_DWORD *)(v44 - 4);
          if ( v33 < v45 )
          {
            do
            {
              v47 = *(unsigned __int16 *)(v44 - 2);
              *(_DWORD *)v44 = *v46;
              v44 = (signed __int64)v46;
              v48 = (signed __int64)&v34[v47];
              if ( v45 & 1 )
              {
                v49 = *(_DWORD *)(v48 + 4) - *(_DWORD *)&v43->min_y;
                v50 = *(_DWORD *)&v43->max_y - *(_DWORD *)v48;
                *(_WORD *)(v48 + 10) = v42;
                if ( !((v50 | v49) & 0x80008000) )
                  hkp3AxisSweep::beginOverlapCheckMarker(
                    v194->m_markers,
                    &v34[v41],
                    v41,
                    (hkp3AxisSweep::hkpBpNode *)v48,
                    newPairsOut);
              }
              else
              {
                *(_WORD *)(v48 + 8) = v42;
              }
              v45 = *(unsigned __int16 *)(v44 - 4);
              v46 = (_DWORD *)(v44 - 4);
              LOWORD(v42) = v42 - 1;
            }
            while ( v33 < v45 );
            v38 = v183;
            v6 = v194;
          }
          v51 = (_DWORD *)(v44 - 4);
          if ( v33 == *(unsigned __int16 *)(v44 - 4) )
          {
            do
            {
              v52 = *(unsigned __int16 *)(v44 - 2);
              if ( (unsigned int)v41 >= (unsigned int)v52 )
                break;
              *(_DWORD *)v44 = *v51;
              v44 = (signed __int64)v51;
              v34[v52].min_x = v42;
              v53 = *((unsigned __int16 *)v51 - 2);
              --v51;
              LOWORD(v42) = v42 - 1;
            }
            while ( v33 == v53 );
          }
          v54 = v180;
          *(_WORD *)(v44 + 2) = v41;
          *(_WORD *)v44 = v54;
          v43->min_x = v42;
          v55 = v43->max_x;
          v56 = (signed __int64)&v6->m_axis[0].m_endPoints.m_data[v55];
          v57 = *(unsigned __int16 *)(v56 + 4);
          v58 = v56 + 4;
          if ( v38 > v57 )
          {
            do
            {
              LOWORD(v55) = v55 + 1;
              *(_DWORD *)v56 = *(_DWORD *)v58;
              v56 = v58;
              v59 = (signed __int64)&v34[*(unsigned __int16 *)(v58 + 2)];
              if ( v57 & 1 )
              {
                --*(_WORD *)(v59 + 10);
              }
              else
              {
                v60 = (*(_DWORD *)(v59 + 4) - *(_DWORD *)&v43->min_y) | (*(_DWORD *)&v43->max_y - *(_DWORD *)v59);
                --*(_WORD *)(v59 + 8);
                if ( !(v60 & 0x80008000) )
                  hkp3AxisSweep::beginOverlapCheckMarker(
                    v194->m_markers,
                    &v34[v41],
                    v41,
                    (hkp3AxisSweep::hkpBpNode *)v59,
                    newPairsOut);
              }
              v57 = *(unsigned __int16 *)(v56 + 4);
              v58 = v56 + 4;
            }
            while ( v38 > v57 );
            v33 = v180;
          }
          v61 = v56 + 4;
          if ( v38 == *(unsigned __int16 *)(v56 + 4) )
          {
            do
            {
              v62 = *(unsigned __int16 *)(v56 + 6);
              if ( (unsigned int)v41 <= (unsigned int)v62 )
                break;
              if ( !*(_WORD *)(v56 + 6) )
                break;
              LOWORD(v55) = v55 + 1;
              *(_DWORD *)v56 = *(_DWORD *)v61;
              --v34[v62].max_x;
              v63 = *(unsigned __int16 *)(v61 + 4);
              v56 = v61;
              v61 += 4i64;
            }
            while ( v38 == v63 );
            v33 = v180;
          }
          v64 = *(unsigned __int16 *)(v56 - 4);
          v65 = (_DWORD *)(v56 - 4);
          if ( v38 < v64 )
          {
            do
            {
              LOWORD(v55) = v55 - 1;
              *(_DWORD *)v56 = *v65;
              v66 = *(unsigned __int16 *)(v56 - 2);
              v56 = (signed __int64)v65;
              v67 = (signed __int64)&v34[v66];
              if ( v64 & 1 )
              {
                ++*(_WORD *)(v67 + 10);
              }
              else
              {
                v68 = *(_DWORD *)&v43->max_y - *(_DWORD *)v67;
                v69 = *(_DWORD *)(v67 + 4) - *(_DWORD *)&v43->min_y;
                ++*(_WORD *)(v67 + 8);
                if ( !((v69 | v68) & 0x80008000) )
                  hkp3AxisSweep::endOverlapCheckMarker(
                    v194->m_markers,
                    &v34[v41],
                    v41,
                    (hkp3AxisSweep::hkpBpNode *)v67,
                    &deletedPairsOut);
              }
              v64 = *(unsigned __int16 *)(v56 - 4);
              v65 = (_DWORD *)(v56 - 4);
            }
            while ( v38 < v64 );
            v33 = v180;
          }
          v70 = (_DWORD *)(v56 - 4);
          if ( v38 == *(unsigned __int16 *)(v56 - 4) )
          {
            do
            {
              v71 = *(unsigned __int16 *)(v56 - 2);
              if ( (unsigned int)v41 >= (unsigned int)v71 )
                break;
              LOWORD(v55) = v55 - 1;
              *(_DWORD *)v56 = *v70;
              ++v34[v71].max_x;
              v72 = *((unsigned __int16 *)v70 - 2);
              v56 = (signed __int64)v70;
              --v70;
            }
            while ( v38 == v72 );
          }
          v73 = v183;
          v74 = v194;
          v43->max_x = v55;
          *(_WORD *)v56 = v73;
          *(_WORD *)(v56 + 2) = v41;
          v75 = v43->min_x;
          v76 = (signed __int64)&v194->m_axis[0].m_endPoints.m_data[v75];
          v77 = *(unsigned __int16 *)(v76 + 4);
          for ( j = (_DWORD *)(v76 + 4); v33 > v77; j = (_DWORD *)(v76 + 4) )
          {
            LOWORD(v75) = v75 + 1;
            v79 = *(unsigned __int16 *)(v76 + 6);
            *(_DWORD *)v76 = *j;
            v76 = (signed __int64)j;
            v80 = (signed __int64)&v34[v79];
            if ( v77 & 1 )
            {
              v81 = (*(_DWORD *)(v80 + 4) - *(_DWORD *)&v43->min_y) | (*(_DWORD *)&v43->max_y - *(_DWORD *)v80);
              --*(_WORD *)(v80 + 10);
              if ( !(v81 & 0x80008000) )
              {
                hkp3AxisSweep::endOverlapCheckMarker(
                  v74->m_markers,
                  &v34[v41],
                  v41,
                  (hkp3AxisSweep::hkpBpNode *)v80,
                  &deletedPairsOut);
                v74 = v194;
              }
            }
            else
            {
              --*(_WORD *)(v80 + 8);
            }
            v77 = *(unsigned __int16 *)(v76 + 4);
          }
          v82 = v76 + 4;
          if ( v33 == *(unsigned __int16 *)(v76 + 4) )
          {
            do
            {
              v83 = *(unsigned __int16 *)(v76 + 6);
              if ( (unsigned int)v41 <= (unsigned int)v83 )
                break;
              LOWORD(v75) = v75 + 1;
              *(_DWORD *)v76 = *(_DWORD *)v82;
              --v34[v83].min_x;
              v84 = *(unsigned __int16 *)(v82 + 4);
              v76 = v82;
              v82 += 4i64;
            }
            while ( v33 == v84 );
            v74 = v194;
          }
          v85 = v180;
          v86 = v181;
          v43->min_x = v75;
          *(_WORD *)v76 = v85;
          *(_WORD *)(v76 + 2) = v41;
          v87 = v43->min_y;
          v88 = (signed __int64)&v74->m_axis[1].m_endPoints.m_data[v87];
          v89 = *(unsigned __int16 *)(v88 - 4);
          v90 = (_DWORD *)(v88 - 4);
          if ( v86 < v89 )
          {
            do
            {
              v91 = *(unsigned __int16 *)(v88 - 2);
              *(_DWORD *)v88 = *v90;
              v88 = (signed __int64)v90;
              v92 = &v34[v91];
              if ( v89 & 1 )
              {
                v93 = (v43->max_x - v92->min_x) | (v43->max_z - v92->min_z) | (v92->max_z - v43->min_z);
                v94 = v92->max_x - v43->min_x;
                v92->max_y = v87;
                if ( ((v94 | v93) & 0x8000u) == 0 )
                  hkp3AxisSweep::beginOverlap(v43, v92, newPairsOut);
              }
              else
              {
                v92->min_y = v87;
              }
              v89 = *(unsigned __int16 *)(v88 - 4);
              v90 = (_DWORD *)(v88 - 4);
              LOWORD(v87) = v87 - 1;
            }
            while ( v86 < v89 );
            v74 = v194;
          }
          v95 = (_DWORD *)(v88 - 4);
          if ( v86 == *(unsigned __int16 *)(v88 - 4) )
          {
            do
            {
              v96 = *(unsigned __int16 *)(v88 - 2);
              if ( (unsigned int)v41 >= (unsigned int)v96 )
                break;
              *(_DWORD *)v88 = *v95;
              v88 = (signed __int64)v95;
              v34[v96].min_y = v87;
              v97 = *((unsigned __int16 *)v95 - 2);
              --v95;
              LOWORD(v87) = v87 - 1;
            }
            while ( v86 == v97 );
          }
          v98 = v181;
          v99 = v184;
          *(_WORD *)(v88 + 2) = v41;
          *(_WORD *)v88 = v98;
          v43->min_y = v87;
          v100 = v43->max_y;
          v101 = (signed __int64)&v74->m_axis[1].m_endPoints.m_data[v100];
          v102 = *(unsigned __int16 *)(v101 + 4);
          v103 = v101 + 4;
          if ( v99 > v102 )
          {
            do
            {
              LOWORD(v100) = v100 + 1;
              *(_DWORD *)v101 = *(_DWORD *)v103;
              v101 = v103;
              v104 = &v34[*(unsigned __int16 *)(v103 + 2)];
              if ( v102 & 1 )
              {
                --v104->max_y;
              }
              else
              {
                v105 = (v43->max_x - v104->min_x) | (v104->max_z - v43->min_z) | (v43->max_z - v104->min_z);
                v106 = v104->max_x - v43->min_x;
                --v104->min_y;
                if ( ((v106 | v105) & 0x8000u) == 0 )
                  hkp3AxisSweep::beginOverlap(v43, v104, newPairsOut);
              }
              v102 = *(unsigned __int16 *)(v101 + 4);
              v103 = v101 + 4;
            }
            while ( v99 > v102 );
            v98 = v181;
          }
          v107 = v101 + 4;
          if ( v99 == *(unsigned __int16 *)(v101 + 4) )
          {
            do
            {
              v108 = *(unsigned __int16 *)(v101 + 6);
              if ( (unsigned int)v41 <= (unsigned int)v108 )
                break;
              if ( !*(_WORD *)(v101 + 6) )
                break;
              LOWORD(v100) = v100 + 1;
              *(_DWORD *)v101 = *(_DWORD *)v107;
              --v34[v108].max_y;
              v109 = *(unsigned __int16 *)(v107 + 4);
              v101 = v107;
              v107 += 4i64;
            }
            while ( v99 == v109 );
            v98 = v181;
          }
          v110 = *(unsigned __int16 *)(v101 - 4);
          v111 = (_DWORD *)(v101 - 4);
          if ( v99 < v110 )
          {
            do
            {
              LOWORD(v100) = v100 - 1;
              *(_DWORD *)v101 = *v111;
              v112 = *(unsigned __int16 *)(v101 - 2);
              v101 = (signed __int64)v111;
              v113 = &v34[v112];
              if ( v110 & 1 )
              {
                ++v113->max_y;
              }
              else
              {
                v114 = (v43->max_x - v113->min_x) | (v113->max_z - v43->min_z) | (v43->max_z - v113->min_z);
                v115 = v113->max_x - v43->min_x;
                ++v113->min_y;
                if ( !((v115 | v114) & 0x8000) )
                  hkp3AxisSweep::endOverlap(v43, v113, &deletedPairsOut);
              }
              v110 = *(unsigned __int16 *)(v101 - 4);
              v111 = (_DWORD *)(v101 - 4);
            }
            while ( v99 < v110 );
            v98 = v181;
          }
          v116 = (_DWORD *)(v101 - 4);
          if ( v99 == *(unsigned __int16 *)(v101 - 4) )
          {
            do
            {
              v117 = *(unsigned __int16 *)(v101 - 2);
              if ( (unsigned int)v41 >= (unsigned int)v117 )
                break;
              LOWORD(v100) = v100 - 1;
              *(_DWORD *)v101 = *v116;
              ++v34[v117].max_y;
              v118 = *((unsigned __int16 *)v116 - 2);
              v101 = (signed __int64)v116;
              --v116;
            }
            while ( v99 == v118 );
          }
          v119 = v184;
          v120 = v194;
          v121 = v181;
          v43->max_y = v100;
          *(_WORD *)v101 = v119;
          *(_WORD *)(v101 + 2) = v41;
          v122 = v43->min_y;
          v123 = (signed __int64)&v194->m_axis[1].m_endPoints.m_data[v122];
          v124 = *(unsigned __int16 *)(v123 + 4);
          v125 = (_DWORD *)(v123 + 4);
          if ( v121 > v124 )
          {
            do
            {
              LOWORD(v122) = v122 + 1;
              v126 = *(unsigned __int16 *)(v123 + 6);
              *(_DWORD *)v123 = *v125;
              v123 = (signed __int64)v125;
              v127 = &v34[v126];
              if ( v124 & 1 )
              {
                v128 = (v43->max_x - v127->min_x) | (v127->max_z - v43->min_z) | (v43->max_z - v127->min_z);
                v129 = v127->max_x - v43->min_x;
                --v127->max_y;
                if ( !((v129 | v128) & 0x8000) )
                  hkp3AxisSweep::endOverlap(v43, v127, &deletedPairsOut);
              }
              else
              {
                --v127->min_y;
              }
              v124 = *(unsigned __int16 *)(v123 + 4);
              v125 = (_DWORD *)(v123 + 4);
            }
            while ( v121 > v124 );
            v98 = v181;
            v120 = v194;
          }
          v130 = v123 + 4;
          if ( v121 == *(unsigned __int16 *)(v123 + 4) )
          {
            do
            {
              v131 = *(unsigned __int16 *)(v123 + 6);
              if ( (unsigned int)v41 <= (unsigned int)v131 )
                break;
              LOWORD(v122) = v122 + 1;
              *(_DWORD *)v123 = *(_DWORD *)v130;
              --v34[v131].min_y;
              v132 = *(unsigned __int16 *)(v130 + 4);
              v123 = v130;
              v130 += 4i64;
            }
            while ( v121 == v132 );
            v98 = v181;
          }
          v43->min_y = v122;
          *(_WORD *)v123 = v98;
          v133 = v182;
          *(_WORD *)(v123 + 2) = v41;
          v134 = v43->min_z;
          v135 = (signed __int64)&v120->m_axis[2].m_endPoints.m_data[v134];
          v136 = *(unsigned __int16 *)(v135 - 4);
          v137 = (_DWORD *)(v135 - 4);
          if ( v133 < v136 )
          {
            do
            {
              v138 = *(unsigned __int16 *)(v135 - 2);
              *(_DWORD *)v135 = *v137;
              v135 = (signed __int64)v137;
              v139 = &v34[v138];
              if ( v136 & 1 )
              {
                v140 = (v139->max_x - v43->min_x) | (v139->max_y - v43->min_y) | (v43->max_x - v139->min_x);
                v141 = v43->max_y - v139->min_y;
                v139->max_z = v134;
                if ( ((v141 | v140) & 0x8000u) == 0 )
                  hkp3AxisSweep::beginOverlap(v43, v139, newPairsOut);
              }
              else
              {
                v139->min_z = v134;
              }
              v136 = *(unsigned __int16 *)(v135 - 4);
              v137 = (_DWORD *)(v135 - 4);
              LOWORD(v134) = v134 - 1;
            }
            while ( v133 < v136 );
            v120 = v194;
          }
          v142 = (_DWORD *)(v135 - 4);
          if ( v133 == *(unsigned __int16 *)(v135 - 4) )
          {
            do
            {
              v143 = *(unsigned __int16 *)(v135 - 2);
              if ( (unsigned int)v41 >= (unsigned int)v143 )
                break;
              *(_DWORD *)v135 = *v142;
              v135 = (signed __int64)v142;
              v34[v143].min_z = v134;
              v144 = *((unsigned __int16 *)v142 - 2);
              --v142;
              LOWORD(v134) = v134 - 1;
            }
            while ( v133 == v144 );
          }
          v145 = v182;
          v146 = v185;
          *(_WORD *)(v135 + 2) = v41;
          *(_WORD *)v135 = v145;
          v43->min_z = v134;
          v147 = v43->max_z;
          v148 = (signed __int64)&v120->m_axis[2].m_endPoints.m_data[v147];
          v149 = *(unsigned __int16 *)(v148 + 4);
          v150 = v148 + 4;
          if ( v146 > v149 )
          {
            do
            {
              LOWORD(v147) = v147 + 1;
              *(_DWORD *)v148 = *(_DWORD *)v150;
              v148 = v150;
              v151 = &v34[*(unsigned __int16 *)(v150 + 2)];
              if ( v149 & 1 )
              {
                --v151->max_z;
              }
              else
              {
                v152 = (v151->max_x - v43->min_x) | (v151->max_y - v43->min_y) | (v43->max_x - v151->min_x);
                v153 = v43->max_y - v151->min_y;
                --v151->min_z;
                if ( ((v153 | v152) & 0x8000u) == 0 )
                  hkp3AxisSweep::beginOverlap(v43, v151, newPairsOut);
              }
              v149 = *(unsigned __int16 *)(v148 + 4);
              v150 = v148 + 4;
            }
            while ( v146 > v149 );
            v145 = v182;
          }
          v154 = v148 + 4;
          if ( v146 == *(unsigned __int16 *)(v148 + 4) )
          {
            do
            {
              v155 = *(unsigned __int16 *)(v148 + 6);
              if ( (unsigned int)v41 <= (unsigned int)v155 )
                break;
              if ( !*(_WORD *)(v148 + 6) )
                break;
              LOWORD(v147) = v147 + 1;
              *(_DWORD *)v148 = *(_DWORD *)v154;
              --v34[v155].max_z;
              v156 = *(unsigned __int16 *)(v154 + 4);
              v148 = v154;
              v154 += 4i64;
            }
            while ( v146 == v156 );
            v145 = v182;
          }
          v157 = *(unsigned __int16 *)(v148 - 4);
          v158 = (_DWORD *)(v148 - 4);
          if ( v146 < v157 )
          {
            do
            {
              LOWORD(v147) = v147 - 1;
              *(_DWORD *)v148 = *v158;
              v159 = *(unsigned __int16 *)(v148 - 2);
              v148 = (signed __int64)v158;
              v160 = &v34[v159];
              if ( v157 & 1 )
              {
                ++v160->max_z;
              }
              else
              {
                v161 = (v160->max_x - v43->min_x) | (v160->max_y - v43->min_y) | (v43->max_x - v160->min_x);
                v162 = v43->max_y - v160->min_y;
                ++v160->min_z;
                if ( !((v162 | v161) & 0x8000) )
                  hkp3AxisSweep::endOverlap(v43, v160, &deletedPairsOut);
              }
              v157 = *(unsigned __int16 *)(v148 - 4);
              v158 = (_DWORD *)(v148 - 4);
            }
            while ( v146 < v157 );
            v145 = v182;
          }
          v163 = (_DWORD *)(v148 - 4);
          if ( v146 == *(unsigned __int16 *)(v148 - 4) )
          {
            do
            {
              v164 = *(unsigned __int16 *)(v148 - 2);
              if ( (unsigned int)v41 >= (unsigned int)v164 )
                break;
              LOWORD(v147) = v147 - 1;
              *(_DWORD *)v148 = *v163;
              v148 = (signed __int64)v163;
              ++v34[v164].max_z;
              v165 = *((unsigned __int16 *)v163 - 2);
              --v163;
            }
            while ( v146 == v165 );
          }
          v166 = v185;
          v6 = v194;
          v167 = v182;
          v43->max_z = v147;
          *(_WORD *)v148 = v166;
          *(_WORD *)(v148 + 2) = v41;
          v168 = v43->min_z;
          v169 = (signed __int64)&v194->m_axis[2].m_endPoints.m_data[v168];
          v170 = *(unsigned __int16 *)(v169 + 4);
          v171 = (_DWORD *)(v169 + 4);
          if ( v167 > v170 )
          {
            do
            {
              LOWORD(v168) = v168 + 1;
              v172 = *(unsigned __int16 *)(v169 + 6);
              *(_DWORD *)v169 = *v171;
              v169 = (signed __int64)v171;
              v173 = &v34[v172];
              if ( v170 & 1 )
              {
                v174 = (v173->max_x - v43->min_x) | (v173->max_y - v43->min_y) | (v43->max_x - v173->min_x);
                v175 = v43->max_y - v173->min_y;
                --v173->max_z;
                if ( !((v175 | v174) & 0x8000) )
                  hkp3AxisSweep::endOverlap(v43, v173, &deletedPairsOut);
              }
              else
              {
                --v173->min_z;
              }
              v170 = *(unsigned __int16 *)(v169 + 4);
              v171 = (_DWORD *)(v169 + 4);
            }
            while ( v167 > v170 );
            v145 = v182;
            v6 = v194;
          }
          v176 = v169 + 4;
          if ( v167 == *(unsigned __int16 *)(v169 + 4) )
          {
            do
            {
              v177 = *(unsigned __int16 *)(v169 + 6);
              if ( (unsigned int)v41 <= (unsigned int)v177 )
                break;
              LOWORD(v168) = v168 + 1;
              *(_DWORD *)v169 = *(_DWORD *)v176;
              v169 = v176;
              --v34[v177].min_z;
              v178 = *(unsigned __int16 *)(v176 + 4);
              v176 += 4i64;
            }
            while ( v167 == v178 );
            v145 = v182;
          }
          v43->min_z = v168;
          v22 = v187;
          *(_WORD *)(v169 + 2) = v41;
          *(_WORD *)v169 = v145;
        }
        v17 = v195;
      }
      v22 += v190;
      v18 = (signed __int64)v189;
    }
    v15 = v186 + 1;
    v186 = v15;
  }
  while ( v15 < 3 );
  deletedPairsOut.m_size = 0;
  if ( deletedPairsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      deletedPairsOut.m_data,
      16 * deletedPairsOut.m_capacityAndFlags);
}

// File Line: 4665
// RVA: 0xD04D20
void __fastcall hkp3AxisSweep::shiftBroadPhase(hkp3AxisSweep *this, hkVector4f *shiftDistance, hkVector4f *effectiveShiftDistanceOut, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newCollisionPairs)
{
  hkVector4f *v4; // rdi
  hkBaseObjectVtbl *v5; // rax
  hkp3AxisSweep *v6; // rbx
  __m128 v7; // xmm6
  __m128 v8; // xmm5
  __m128 v9; // xmm3
  __m128 v10; // xmm6
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm4
  __m128 v18; // [rsp+20h] [rbp-38h]
  __m128 v19; // [rsp+30h] [rbp-28h]

  v4 = effectiveShiftDistanceOut;
  v5 = this->vfptr;
  v6 = this;
  v7 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v18 = _mm_xor_ps(shiftDistance->m_quad, v7);
  ((void (__fastcall *)(hkp3AxisSweep *, __m128 *, __m128 *, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *, unsigned __int64, unsigned __int64))v5[11].__vecDelDtor)(
    this,
    &v18,
    &v19,
    newCollisionPairs,
    v18.m128_u64[0],
    v18.m128_u64[1]);
  v8 = v19;
  v9 = _mm_add_ps(v6->m_offsetLow.m_quad, v19);
  v10 = _mm_xor_ps(v7, v19);
  v6->m_offsetLow.m_quad = v9;
  v11 = v6->m_scale.m_quad;
  v12 = _mm_rcp_ps(v11);
  v13 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v12)), v12);
  v6->m_offsetHigh.m_quad = _mm_add_ps(v9, _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196));
  v14 = _mm_add_ps(v6->m_offsetLow32bit.m_quad, v8);
  v6->m_offsetLow32bit.m_quad = v14;
  v15 = v6->m_scale32bit.m_quad;
  v16 = _mm_rcp_ps(v15);
  v17 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v16)), v16);
  v6->m_offsetHigh32bit.m_quad = _mm_add_ps(v14, _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, query.m_quad), 196));
  *v4 = (hkVector4f)v10;
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
  hkVector4f *v3; // rsi
  int v4; // ebx
  hkVector4f *v5; // rdi
  _QWORD **v6; // rax
  hkp3AxisSweep *v7; // rax

  v3 = worldMin;
  v4 = numMarkers;
  v5 = worldMax;
  hkOptionalComponent_hkp3AxisSweep.m_isUsed.m_bool = 1;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkp3AxisSweep *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 272i64);
  if ( v7 )
    hkp3AxisSweep::hkp3AxisSweep(v7, v3, v5, v4);
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

