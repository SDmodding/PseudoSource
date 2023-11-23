// File Line: 27
// RVA: 0xC1D460
__int64 __fastcall hkaiVolumePathSmoothingUtil::findSmoothedPath(
        hkaiStreamingCollection::InstanceInfo *sectionInfo,
        hkArray<unsigned int,hkContainerHeapAllocator> *visitedCells,
        unsigned int startCellKey,
        hkVector4f *startPoint,
        hkVector4f *endPoint,
        hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut,
        hkaiPath::PathPoint *pathPtrOut,
        int maxPathLength)
{
  unsigned int v8; // r15d
  int v9; // ebp
  int v11; // r13d
  hkLifoAllocator *Value; // rax
  hkVector4f *m_cur; // rdi
  int v15; // edx
  char *v16; // rcx
  hkLifoAllocator *v17; // rax
  _DWORD *v18; // rsi
  int v19; // edx
  char *v20; // rcx
  hkLifoAllocator *v21; // rax
  __m128 *v22; // r12
  int v23; // edx
  char *v24; // rcx
  unsigned int v25; // edx
  int v26; // ebx
  int v27; // r11d
  int v28; // ebp
  __int64 v29; // r13
  unsigned int v30; // r10d
  hkaiNavVolumeInstance *m_volumeInstancePtr; // r8
  __m128 *m_pntr; // rax
  __m128i v33; // xmm1
  __m128i v34; // xmm3
  hkaiNavVolumeInstance *v35; // rdx
  __m128i v36; // xmm0
  __m128 v37; // xmm7
  __m128 v38; // xmm0
  __m128 v39; // xmm6
  hkaiNavVolume *v40; // rax
  __m128 v41; // xmm7
  __m128 v42; // xmm6
  __m128i v43; // xmm1
  __m128i v44; // xmm2
  __m128i v45; // xmm1
  __m128 v46; // xmm4
  __m128 v47; // xmm0
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 m_quad; // xmm2
  __m128 v51; // xmm6
  __m128 v52; // xmm7
  __m128 v53; // xmm0
  __m128 v54; // xmm7
  __m128 *v55; // rcx
  __int64 v56; // rax
  __int64 v57; // rax
  __int64 v58; // r8
  __m128 *v59; // rcx
  __m128 *p_m_quad; // rax
  __int64 v61; // rdx
  __m128 v62; // xmm7
  __m128 v63; // xmm8
  __m128 v64; // xmm9
  __m128 v65; // xmm5
  __m128 v66; // xmm4
  __m128 v67; // xmm0
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm6
  __m128 v71; // xmm6
  __m128 v72; // xmm2
  __m128 v73; // xmm6
  __m128 v74; // xmm3
  __m128 v75; // xmm2
  __m128 v76; // xmm2
  __m128 v77; // xmm4
  __m128 v78; // xmm1
  __m128 v79; // xmm0
  __m128 v80; // xmm1
  __m128 v81; // xmm5
  __int64 v82; // rbx
  __m128 *v83; // r14
  int v84; // r9d
  char v85; // al
  signed int v86; // r13d
  hkLifoAllocator *v87; // rax
  int v88; // r8d
  signed int v89; // ebx
  hkLifoAllocator *v90; // rcx
  int v91; // r8d
  signed int v92; // ebp
  hkLifoAllocator *v93; // rcx
  int v94; // r8d
  int v96; // [rsp+34h] [rbp-F4h]
  int v97; // [rsp+3Ch] [rbp-ECh]
  hkVector4f normal; // [rsp+40h] [rbp-E8h] BYREF
  hkVector4f p; // [rsp+50h] [rbp-D8h] BYREF
  hkaiPathWriter v100; // [rsp+60h] [rbp-C8h] BYREF
  unsigned int v102; // [rsp+138h] [rbp+10h]

  v8 = 0;
  v9 = visitedCells->m_size + 1;
  v11 = visitedCells->m_size - 1;
  v96 = v9;
  v97 = v11;
  if ( visitedCells->m_size == -1 )
  {
    m_cur = 0i64;
  }
  else
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)Value->m_cur;
    v15 = (16 * v9 + 127) & 0xFFFFFF80;
    v16 = (char *)m_cur + v15;
    if ( v15 > Value->m_slabSize || v16 > Value->m_end )
      m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v15);
    else
      Value->m_cur = v16;
  }
  if ( v9 )
  {
    v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = v17->m_cur;
    v19 = (4 * v9 + 127) & 0xFFFFFF80;
    v20 = (char *)v18 + v19;
    if ( v19 > v17->m_slabSize || v20 > v17->m_end )
      v18 = hkLifoAllocator::allocateFromNewSlab(v17, v19);
    else
      v17->m_cur = v20;
  }
  else
  {
    v18 = 0i64;
  }
  if ( v11 )
  {
    v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (__m128 *)v21->m_cur;
    v23 = (32 * v11 + 127) & 0xFFFFFF80;
    v24 = (char *)v22 + v23;
    if ( v23 > v21->m_slabSize || v24 > v21->m_end )
      v22 = (__m128 *)hkLifoAllocator::allocateFromNewSlab(v21, v23);
    else
      v21->m_cur = v24;
  }
  else
  {
    v22 = 0i64;
  }
  v25 = startCellKey;
  *m_cur = (hkVector4f)startPoint->m_quad;
  v26 = 1;
  v27 = 1;
  *v18 = startCellKey >> 22;
  if ( visitedCells->m_size > 1 )
  {
    v28 = 0;
    v29 = 1i64;
    do
    {
      v30 = visitedCells->m_data[v29];
      v102 = visitedCells->m_data[v29 - 1] >> 22;
      m_volumeInstancePtr = sectionInfo[v102].m_volumeInstancePtr;
      m_pntr = (__m128 *)m_volumeInstancePtr->m_originalVolume.m_pntr;
      v33 = _mm_loadu_si128((const __m128i *)&m_volumeInstancePtr->m_originalCells[visitedCells->m_data[v29 - 1] & 0x3FFFFF]);
      v34 = _mm_unpackhi_epi16(v33, (__m128i)0i64);
      v35 = sectionInfo[v30 >> 22].m_volumeInstancePtr;
      v36 = _mm_unpacklo_epi16(v33, (__m128i)0i64);
      v37 = _mm_mul_ps(
              m_pntr[6],
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v36, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v36, 0x10u), 0x10u))));
      v38 = _mm_add_ps(m_pntr[7], m_volumeInstancePtr->m_translation.m_quad);
      v39 = _mm_mul_ps(
              m_pntr[6],
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v34, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v34, 0x10u), 0x10u))));
      v40 = v35->m_originalVolume.m_pntr;
      v41 = _mm_add_ps(v37, v38);
      v42 = _mm_add_ps(v39, v38);
      v43 = _mm_loadu_si128((const __m128i *)&v35->m_originalCells[v30 & 0x3FFFFF]);
      v44 = _mm_unpackhi_epi16(v43, (__m128i)0i64);
      v45 = _mm_unpacklo_epi16(v43, (__m128i)0i64);
      v46 = _mm_cvtepi32_ps(_mm_srli_epi32(v45, 0x10u));
      v47 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v45, 0x10u), 0x10u));
      v48 = _mm_add_ps(v40->m_quantizationOffset.m_quad, v35->m_translation.m_quad);
      v49 = _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v44, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v44, 0x10u), 0x10u)));
      m_quad = v40->m_quantizationScale.m_quad;
      v51 = _mm_min_ps(v42, _mm_add_ps(_mm_mul_ps(m_quad, v49), v48));
      v52 = _mm_max_ps(
              v41,
              _mm_add_ps(
                _mm_mul_ps(m_quad, _mm_add_ps(_mm_mul_ps(v46, (__m128)`hkIntVector::convertU32ToF32::`2::two16), v47)),
                v48));
      v53 = _mm_min_ps(v52, v51);
      v54 = _mm_max_ps(v52, v51);
      v55 = &v22[2 * v28];
      if ( v55 )
      {
        *v55 = v53;
        v55[1] = v54;
      }
      v56 = v26;
      ++v28;
      ++v26;
      ++v29;
      m_cur[v56].m_quad = _mm_mul_ps(_mm_add_ps(v54, v53), (__m128)xmmword_141A711B0);
      v57 = v27++;
      v18[v57] = v102;
    }
    while ( v27 < visitedCells->m_size );
    v9 = v96;
    v11 = v97;
    v25 = startCellKey;
    v8 = 0;
  }
  m_cur[v26] = (hkVector4f)endPoint->m_quad;
  if ( visitedCells->m_size )
    v25 = visitedCells->m_data[visitedCells->m_size - 1];
  v18[v27] = v25 >> 22;
  v58 = 3i64;
  do
  {
    if ( v26 > 1i64 )
    {
      v59 = v22;
      p_m_quad = &m_cur[2].m_quad;
      v61 = v26 - 1i64;
      do
      {
        v62 = v59[1];
        v63 = *v59;
        v64 = p_m_quad[-2];
        v65 = _mm_sub_ps(*p_m_quad, v64);
        v66 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v62, *v59), 1u), 1u);
        v67 = _mm_shuffle_ps(v66, v66, 85);
        v68 = _mm_shuffle_ps(v66, v66, 0);
        v69 = _mm_cmplt_ps(v67, v68);
        v70 = _mm_cmplt_ps(_mm_shuffle_ps(v66, v66, 170), _mm_or_ps(_mm_and_ps(v69, v67), _mm_andnot_ps(v69, v68)));
        v71 = _mm_or_ps(
                _mm_andnot_ps(v70, _mm_or_ps(_mm_andnot_ps(v69, transform.m_quad), _mm_and_ps(v69, direction.m_quad))),
                _mm_and_ps(v70, stru_141A71280.m_quad));
        v72 = _mm_mul_ps(_mm_mul_ps(_mm_add_ps(*v59, v62), (__m128)xmmword_141A711B0), v71);
        v73 = _mm_shuffle_ps(
                v71,
                _mm_unpackhi_ps(
                  v71,
                  _mm_sub_ps(
                    (__m128)0i64,
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                      _mm_shuffle_ps(v72, v72, 170)))),
                196);
        v74 = _mm_mul_ps(v65, v73);
        if ( COERCE_FLOAT((unsigned int)(2
                                       * COERCE_INT(
                                           (float)(_mm_shuffle_ps(v74, v74, 85).m128_f32[0]
                                                 + _mm_shuffle_ps(v74, v74, 0).m128_f32[0])
                                         + _mm_shuffle_ps(v74, v74, 170).m128_f32[0])) >> 1) < 0.00000011920929 )
        {
          v81 = _mm_mul_ps(v65, (__m128)xmmword_141A711B0);
        }
        else
        {
          v75 = _mm_mul_ps(v73, v64);
          v76 = _mm_shuffle_ps(v75, _mm_unpackhi_ps(v75, v73), 196);
          v77 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v74, v74, 85), _mm_shuffle_ps(v74, v74, 0)),
                  _mm_shuffle_ps(v74, v74, 170));
          v78 = _mm_add_ps(_mm_shuffle_ps(v76, v76, 78), v76);
          v79 = _mm_add_ps(_mm_shuffle_ps(v78, v78, 177), v78);
          v80 = _mm_rcp_ps(v77);
          v81 = _mm_mul_ps(
                  v65,
                  _mm_mul_ps(
                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v80, v77)), v80),
                    _mm_sub_ps((__m128)0i64, v79)));
        }
        ++p_m_quad;
        v59 += 2;
        p_m_quad[-2] = _mm_max_ps(v63, _mm_min_ps(v62, _mm_add_ps(v81, v64)));
        --v61;
      }
      while ( v61 );
    }
    --v58;
  }
  while ( v58 );
  hkaiPathWriter::hkaiPathWriter(&v100);
  hkaiPathWriter::init(&v100, pathArrayOut, pathPtrOut, maxPathLength);
  v82 = 0i64;
  if ( v9 > 0 )
  {
    v83 = &m_cur->m_quad;
    do
    {
      v84 = v18[v82];
      p.m_quad = *v83;
      normal.m_quad = 0i64;
      hkaiPathWriter::addPointToPath(&v100, &p, &normal, v84, 0, 0);
      ++v82;
      ++v83;
    }
    while ( v82 < v9 );
    v11 = v9 - 2;
  }
  hkaiPathWriter::addTerminatorToPathPointer(&v100);
  if ( v100.m_pathArrayOut || (v85 = 1, v100.m_totalNumOutput < v100.m_maxNumOutput) )
    v85 = 0;
  LOBYTE(v8) = v85 == 0;
  v86 = (32 * v11 + 127) & 0xFFFFFF80;
  v87 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v88 = (v86 + 15) & 0xFFFFFFF0;
  if ( v86 > v87->m_slabSize || (char *)v22 + v88 != v87->m_cur || v87->m_firstNonLifoEnd == v22 )
    hkLifoAllocator::slowBlockFree(v87, v22, v88);
  else
    v87->m_cur = v22;
  v89 = (4 * v9 + 127) & 0xFFFFFF80;
  v90 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v91 = (v89 + 15) & 0xFFFFFFF0;
  if ( v89 > v90->m_slabSize || (char *)v18 + v91 != v90->m_cur || v90->m_firstNonLifoEnd == v18 )
    hkLifoAllocator::slowBlockFree(v90, v18, v91);
  else
    v90->m_cur = v18;
  v92 = (16 * v9 + 127) & 0xFFFFFF80;
  v93 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v94 = (v92 + 15) & 0xFFFFFFF0;
  if ( v92 > v93->m_slabSize || (char *)m_cur + v94 != v93->m_cur || v93->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v93, m_cur, v94);
  else
    v93->m_cur = m_cur;
  return v8;
}

