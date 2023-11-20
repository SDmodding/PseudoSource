// File Line: 27
// RVA: 0xC1D460
__int64 __fastcall hkaiVolumePathSmoothingUtil::findSmoothedPath(hkaiStreamingCollection::InstanceInfo *sectionInfo, hkArray<unsigned int,hkContainerHeapAllocator> *visitedCells, unsigned int startCellKey, hkVector4f *startPoint, hkVector4f *endPoint, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathArrayOut, hkaiPath::PathPoint *pathPtrOut, int maxPathLength)
{
  unsigned int v8; // er15
  int v9; // ebp
  hkVector4f *v10; // rbx
  int v11; // er13
  hkArray<unsigned int,hkContainerHeapAllocator> *v12; // r14
  hkLifoAllocator *v13; // rax
  _OWORD *v14; // rdi
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
  signed int v26; // ebx
  signed int v27; // er11
  int v28; // ebp
  signed __int64 v29; // r13
  unsigned int v30; // er9
  __m128 *v31; // r8
  __m128i v32; // xmm3
  __m128 *v33; // rax
  __m128i v34; // xmm1
  __m128i v35; // xmm3
  __m128i v36; // xmm1
  __m128 *v37; // rdx
  __m128 v38; // xmm7
  __m128 v39; // xmm0
  __m128 v40; // xmm6
  __m128i v41; // xmm2
  __m128 *v42; // rax
  __m128 v43; // xmm7
  __m128 v44; // xmm6
  __m128i v45; // xmm1
  __m128i v46; // xmm2
  __m128i v47; // xmm1
  __m128 v48; // xmm4
  __m128 v49; // xmm0
  __m128 v50; // xmm1
  __m128 v51; // xmm6
  __m128 v52; // xmm7
  __m128 v53; // xmm0
  __m128 v54; // xmm7
  __m128 *v55; // rcx
  signed __int64 v56; // rax
  __int64 v57; // rax
  signed __int64 v58; // r8
  __m128 *v59; // rcx
  __m128 *v60; // rax
  signed __int64 v61; // rdx
  __m128 v62; // xmm7
  __m128 v63; // xmm8
  __m128 v64; // xmm9
  __m128 v65; // xmm5
  __m128 v66; // xmm4
  __m128 v67; // xmm0
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm4
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
  signed __int64 v82; // rbx
  __m128i *v83; // r14
  int v84; // er9
  char v85; // al
  signed int v86; // er13
  hkLifoAllocator *v87; // rax
  int v88; // er8
  signed int v89; // ebx
  hkLifoAllocator *v90; // rcx
  int v91; // er8
  signed int v92; // ebp
  hkLifoAllocator *v93; // rcx
  int v94; // er8
  signed int v96; // [rsp+30h] [rbp-F8h]
  int v97; // [rsp+34h] [rbp-F4h]
  signed int v98; // [rsp+38h] [rbp-F0h]
  int v99; // [rsp+3Ch] [rbp-ECh]
  hkVector4f normal; // [rsp+40h] [rbp-E8h]
  hkVector4f p; // [rsp+50h] [rbp-D8h]
  hkaiPathWriter v102; // [rsp+60h] [rbp-C8h]
  hkaiStreamingCollection::InstanceInfo *v103; // [rsp+130h] [rbp+8h]
  unsigned int v104; // [rsp+138h] [rbp+10h]
  unsigned int v105; // [rsp+140h] [rbp+18h]

  v103 = sectionInfo;
  v8 = 0;
  v9 = visitedCells->m_size + 1;
  v10 = startPoint;
  v105 = startCellKey;
  v11 = visitedCells->m_size - 1;
  v12 = visitedCells;
  v97 = visitedCells->m_size + 1;
  v99 = visitedCells->m_size - 1;
  if ( visitedCells->m_size == -1 )
  {
    v14 = 0i64;
  }
  else
  {
    v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = v13->m_cur;
    v15 = (16 * v9 + 127) & 0xFFFFFF80;
    v16 = (char *)v14 + v15;
    if ( v15 > v13->m_slabSize || v16 > v13->m_end )
      v14 = hkLifoAllocator::allocateFromNewSlab(v13, v15);
    else
      v13->m_cur = v16;
  }
  v96 = v9 | 0x80000000;
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
  v25 = v105;
  *v14 = v10->m_quad;
  v26 = 1;
  v27 = 1;
  v98 = v11 | 0x80000000;
  *v18 = v105 >> 22;
  if ( v12->m_size > 1 )
  {
    v28 = 0;
    v29 = 1i64;
    do
    {
      v30 = v12->m_data[v29];
      v104 = v12->m_data[v29 - 1] >> 22;
      v31 = (__m128 *)v103[v104].m_volumeInstancePtr;
      v32 = _mm_loadu_si128((const __m128i *)(v31[1].m128_u64[0] + 24i64 * (v12->m_data[v29 - 1] & 0x3FFFFF)));
      v33 = (__m128 *)v31[3].m128_u64[0];
      v34 = v32;
      v35 = _mm_unpackhi_epi16(v32, (__m128i)0i64);
      v36 = _mm_unpacklo_epi16(v34, (__m128i)0i64);
      v37 = (__m128 *)v103[v30 >> 22].m_volumeInstancePtr;
      v38 = _mm_mul_ps(
              v33[6],
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v36, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v36, 0x10u), 0x10u))));
      v39 = _mm_add_ps(v33[7], v31[7]);
      v40 = _mm_mul_ps(
              v33[6],
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v35, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v35, 0x10u), 0x10u))));
      v41 = _mm_loadu_si128((const __m128i *)(v37[1].m128_u64[0] + 24i64 * (v30 & 0x3FFFFF)));
      v42 = (__m128 *)v37[3].m128_u64[0];
      v43 = _mm_add_ps(v38, v39);
      v44 = _mm_add_ps(v40, v39);
      v45 = v41;
      v46 = _mm_unpackhi_epi16(v41, (__m128i)0i64);
      v47 = _mm_unpacklo_epi16(v45, (__m128i)0i64);
      v48 = _mm_cvtepi32_ps(_mm_srli_epi32(v47, 0x10u));
      v49 = _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v47, 0x10u), 0x10u));
      v50 = _mm_add_ps(v42[7], v37[7]);
      v51 = _mm_min_ps(
              v44,
              _mm_add_ps(
                _mm_mul_ps(
                  v42[6],
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_cvtepi32_ps(_mm_srli_epi32(v46, 0x10u)),
                      (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v46, 0x10u), 0x10u)))),
                v50));
      v52 = _mm_max_ps(
              v43,
              _mm_add_ps(
                _mm_mul_ps(v42[6], _mm_add_ps(_mm_mul_ps(v48, (__m128)`hkIntVector::convertU32ToF32'::`2'::two16), v49)),
                v50));
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
      v14[v56] = _mm_mul_ps(_mm_add_ps(v54, v53), (__m128)xmmword_141A711B0);
      v57 = v27++;
      v18[v57] = v104;
    }
    while ( v27 < v12->m_size );
    v9 = v97;
    v11 = v99;
    v25 = v105;
    v8 = 0;
  }
  v14[v26] = endPoint->m_quad;
  if ( v12->m_size )
    v25 = v12->m_data[v12->m_size - 1];
  v18[v27] = v25 >> 22;
  v58 = 3i64;
  do
  {
    if ( v26 > 1i64 )
    {
      v59 = v22;
      v60 = (__m128 *)(v14 + 2);
      v61 = v26 - 1i64;
      do
      {
        v62 = v59[1];
        v63 = *v59;
        v64 = v60[-2];
        v65 = _mm_sub_ps(*v60, v64);
        v66 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v59[1], *v59), 1u), 1u);
        v67 = _mm_shuffle_ps(v66, v66, 85);
        v68 = _mm_shuffle_ps(v66, v66, 0);
        v69 = _mm_cmpltps(v67, v68);
        v70 = _mm_cmpltps(_mm_shuffle_ps(v66, v66, 170), _mm_or_ps(_mm_and_ps(v69, v67), _mm_andnot_ps(v69, v68)));
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
                                       * COERCE_SIGNED_INT(
                                           (float)(COERCE_FLOAT(_mm_shuffle_ps(v74, v74, 85))
                                                 + COERCE_FLOAT(_mm_shuffle_ps(v74, v74, 0)))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v74, v74, 170)))) >> 1) < 0.00000011920929 )
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
        ++v60;
        v59 += 2;
        v60[-2] = _mm_max_ps(v63, _mm_min_ps(v62, _mm_add_ps(v81, v64)));
        --v61;
      }
      while ( v61 );
    }
    --v58;
  }
  while ( v58 );
  hkaiPathWriter::hkaiPathWriter(&v102);
  hkaiPathWriter::init(&v102, pathArrayOut, pathPtrOut, maxPathLength);
  v82 = 0i64;
  if ( v9 > 0 )
  {
    v83 = (__m128i *)v14;
    do
    {
      v84 = v18[v82];
      _mm_store_si128((__m128i *)&p, *v83);
      normal.m_quad = 0i64;
      hkaiPathWriter::addPointToPath(&v102, &p, &normal, v84, 0, 0);
      ++v82;
      ++v83;
    }
    while ( v82 < v9 );
    v11 = v9 - 2;
  }
  hkaiPathWriter::addTerminatorToPathPointer(&v102);
  if ( v102.m_pathArrayOut || (v85 = 1, v102.m_totalNumOutput < v102.m_maxNumOutput) )
    v85 = 0;
  LOBYTE(v8) = v85 == 0;
  v86 = (32 * v11 + 127) & 0xFFFFFF80;
  v87 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v88 = (v86 + 15) & 0xFFFFFFF0;
  if ( v86 > v87->m_slabSize || (char *)v22 + v88 != v87->m_cur || v87->m_firstNonLifoEnd == v22 )
    hkLifoAllocator::slowBlockFree(v87, v22, v88);
  else
    v87->m_cur = v22;
  if ( v98 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v22,
      32 * v98);
  v89 = (4 * v9 + 127) & 0xFFFFFF80;
  v90 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v91 = (v89 + 15) & 0xFFFFFFF0;
  if ( v89 > v90->m_slabSize || (char *)v18 + v91 != v90->m_cur || v90->m_firstNonLifoEnd == v18 )
    hkLifoAllocator::slowBlockFree(v90, v18, v91);
  else
    v90->m_cur = v18;
  if ( v96 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v18,
      4 * v96);
  v92 = (16 * v9 + 127) & 0xFFFFFF80;
  v93 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v94 = (v92 + 15) & 0xFFFFFFF0;
  if ( v92 > v93->m_slabSize || (char *)v14 + v94 != v93->m_cur || v93->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v93, v14, v94);
  else
    v93->m_cur = v14;
  if ( v96 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v14,
      16 * v96);
  return v8;
}0;
  if ( v92 > v93->m_slabSize || (char *)v14 + v94 != v93->m_cur || v93->m_firstNonLifoEnd == v14 )
    hkLifoAllocator::slowBlockFree(v93, v14, v94);
  else
    v93->m_cur = v14;
  if ( v96 >= 0 )
    hkContainerHeapAllocator::s_al

