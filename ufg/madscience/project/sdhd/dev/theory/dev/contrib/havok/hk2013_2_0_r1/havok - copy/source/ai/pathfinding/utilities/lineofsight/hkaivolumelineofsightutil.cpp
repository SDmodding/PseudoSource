// File Line: 23
// RVA: 0xC1DD90
void __fastcall hkaiVolumeLineOfSightUtil::LineOfSightInput::LineOfSightInput(
        hkaiVolumeLineOfSightUtil::LineOfSightInput *this)
{
  *(_QWORD *)&this->m_maxNumberOfIterations = 100000i64;
  this->m_agentInfo.m_filterInfo = 0;
  this->m_edgeFilter = 0i64;
}

// File Line: 27
// RVA: 0xC1E5D0
bool __fastcall rayGoesThroughPortal(hkVector4f *start, hkVector4f *end, hkAabb *portal)
{
  __m128 v6; // xmm2
  int v7; // eax
  __m128 m_quad; // xmm0
  hkSimdFloat32 tOut; // [rsp+20h] [rbp-28h] BYREF
  __m128 v11; // [rsp+30h] [rbp-18h]

  if ( !hkaiNavVolumeUtils::getPortalPlaneIntersection(start, end, portal, &tOut)
    || tOut.m_real.m128_f32[0] < 0.0
    || tOut.m_real.m128_f32[0] > 1.0 )
  {
    return 0;
  }
  v6 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(end->m_quad, start->m_quad), tOut.m_real), start->m_quad);
  tOut.m_real = _mm_mul_ps(_mm_sub_ps(portal->m_max.m_quad, portal->m_min.m_quad), (__m128)xmmword_141A711B0);
  if ( tOut.m_real.m128_f32[0] == 0.0 )
  {
    v7 = 0;
  }
  else
  {
    v7 = 1;
    if ( tOut.m_real.m128_f32[1] != 0.0 )
      v7 = 2;
  }
  m_quad = portal->m_min.m_quad;
  v11 = portal->m_max.m_quad;
  tOut.m_real = m_quad;
  tOut.m_real.m128_i32[v7] = -8388626;
  v11.m128_i32[v7] = 2139095022;
  return (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v6, v11), _mm_cmple_ps(tOut.m_real, v6))) & 7) == 7;
}

// File Line: 78
// RVA: 0xC1DDB0
char __fastcall hkaiVolumeLineOfSightUtil::checkLineOfSight(
        hkaiStreamingCollection::InstanceInfo *streamingInfo,
        hkaiVolumeLineOfSightUtil::LineOfSightInput *input,
        hkArray<unsigned int,hkContainerHeapAllocator> *cellsArrayOut,
        char doNotExceedArrayCapacity)
{
  int v8; // r15d
  hkVector4f *p_m_endPoint; // rdi
  int v10; // eax
  __m128 v11; // xmm0
  int v12; // ecx
  int v13; // ecx
  _QWORD *Value; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  unsigned int m_startCellKey; // r8d
  hkVector4f v19; // xmm0
  __m128 v20; // xmm5
  __int64 v21; // r10
  int v22; // r11d
  hkaiNavVolumeInstance *m_volumeInstancePtr; // r9
  hkaiNavVolume::Cell *m_originalCells; // rcx
  __m128i v25; // xmm3
  int m_data; // eax
  __m128i v27; // xmm1
  __m128i v28; // xmm3
  hkaiAstarEdgeFilter *m_edgeFilter; // rcx
  __m128i v30; // xmm0
  __m128 *m_pntr; // rax
  __m128 v32; // xmm2
  __m128 v33; // xmm0
  __m128 v34; // xmm10
  __m128 v35; // xmm9
  __m128 v36; // xmm0
  _QWORD *v37; // r9
  unsigned __int64 v38; // r8
  unsigned __int64 v39; // rax
  unsigned int v41; // ebx
  __m128 v42; // xmm4
  hkaiStreamingCollection::InstanceInfo *v43; // rdx
  int v44; // edi
  unsigned __int64 v45; // rsi
  int v46; // r12d
  int v47; // eax
  int v48; // ecx
  int v49; // r15d
  __int64 v50; // rax
  unsigned int v51; // ecx
  unsigned int v52; // ebx
  __m128 *v53; // r8
  unsigned __int64 v54; // rcx
  __m128i v55; // xmm3
  __m128i v56; // xmm1
  __m128i v57; // xmm3
  __m128 *v58; // rax
  __m128i v59; // xmm0
  __m128 v60; // xmm2
  __m128 v61; // xmm0
  __m128 v62; // xmm7
  __m128 v63; // xmm6
  __m128 v64; // xmm1
  __m128 v65; // xmm0
  __int64 v66; // rax
  float v67; // xmm0_4
  float v68; // xmm1_4
  bool v69; // cc
  hkaiAstarEdgeFilter *v70; // rcx
  __m128 v71; // xmm0
  _QWORD *v72; // r9
  unsigned __int64 v73; // r8
  unsigned __int64 v74; // rax
  hkaiAstarEdgeFilter *v75; // rcx
  bool v76; // zf
  char v77; // al
  unsigned int v78; // [rsp+20h] [rbp-A8h]
  unsigned int v79; // [rsp+24h] [rbp-A4h]
  int v80; // [rsp+28h] [rbp-A0h]
  __m128i v81; // [rsp+30h] [rbp-98h] BYREF
  unsigned __int64 v82; // [rsp+40h] [rbp-88h]
  __m128i v83; // [rsp+48h] [rbp-80h] BYREF
  __m128 portal; // [rsp+58h] [rbp-70h] BYREF
  _BYTE portal_16[24]; // [rsp+68h] [rbp-60h] BYREF
  __m128i *v86; // [rsp+80h] [rbp-48h]
  __m128 m_quad; // [rsp+88h] [rbp-40h]
  unsigned int v88; // [rsp+98h] [rbp-30h]
  __m128i *v89; // [rsp+A0h] [rbp-28h]
  __m128 v90; // [rsp+A8h] [rbp-20h]
  int v91; // [rsp+B8h] [rbp-10h]
  _BYTE *v92; // [rsp+C0h] [rbp-8h]
  __m128 v93; // [rsp+C8h] [rbp+0h]
  __m128 v94; // [rsp+D8h] [rbp+10h]
  __m128 v95; // [rsp+E8h] [rbp+20h]
  hkaiStreamingCollection::InstanceInfo *v96; // [rsp+198h] [rbp+D0h]
  int v97; // [rsp+1A0h] [rbp+D8h]
  char v98; // [rsp+1B0h] [rbp+E8h]
  int *v99; // [rsp+1B8h] [rbp+F0h]

  v8 = 0;
  if ( input->m_startCellKey == -1 || input->m_endCellKey == -1 )
  {
$lineOfSightFailure:
    if ( cellsArrayOut )
      cellsArrayOut->m_size = 0;
    if ( v99 )
      *v99 = v8;
    return 0;
  }
  p_m_endPoint = &input->m_endPoint;
  v10 = -1;
  v11 = _mm_sub_ps(input->m_endPoint.m_quad, input->m_startPoint.m_quad);
  *(__m128 *)&portal_16[8] = v11;
  if ( v11.m128_f32[0] <= 0.0 )
  {
    v12 = 0;
    if ( v11.m128_f32[0] != 0.0 )
      v12 = -1;
  }
  else
  {
    v12 = 1;
  }
  v83.m128i_i32[0] = v12;
  if ( *(float *)&portal_16[12] <= 0.0 )
  {
    v13 = 0;
    if ( *(float *)&portal_16[12] != 0.0 )
      v13 = -1;
  }
  else
  {
    v13 = 1;
  }
  v83.m128i_i32[1] = v13;
  if ( *(float *)&portal_16[16] <= 0.0 )
  {
    if ( *(float *)&portal_16[16] == 0.0 )
      v10 = 0;
  }
  else
  {
    v10 = 1;
  }
  v83.m128i_i32[2] = v10;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v15 < Value[3] )
  {
    *v15 = "TtlosCheck";
    v16 = __rdtsc();
    v17 = v15 + 2;
    *((_DWORD *)v17 - 2) = v16;
    Value[1] = v17;
  }
  m_startCellKey = input->m_startCellKey;
  v19.m_quad = (__m128)input->m_startPoint;
  v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
  *(_DWORD *)&portal_16[16] = -1;
  v88 = -1;
  v86 = 0i64;
  v89 = 0i64;
  v92 = 0i64;
  v91 = -1;
  v21 = m_startCellKey >> 22;
  v22 = -1;
  v79 = m_startCellKey >> 22;
  v97 = -1;
  m_volumeInstancePtr = streamingInfo[v21].m_volumeInstancePtr;
  m_originalCells = m_volumeInstancePtr->m_originalCells;
  v81 = *(__m128i *)m_originalCells[m_startCellKey & 0x3FFFFF].m_min;
  v25 = _mm_loadu_si128(&v81);
  LODWORD(v82) = m_originalCells[m_startCellKey & 0x3FFFFF].m_startEdgeIndex;
  m_data = m_originalCells[m_startCellKey & 0x3FFFFF].m_data;
  v27 = v25;
  m_quad = v19.m_quad;
  v28 = _mm_unpackhi_epi16(v25, (__m128i)0i64);
  m_edgeFilter = input->m_edgeFilter;
  HIDWORD(v82) = m_data;
  v30 = _mm_unpacklo_epi16(v27, (__m128i)0i64);
  *(_DWORD *)&portal_16[16] = m_startCellKey;
  v86 = &v81;
  m_pntr = (__m128 *)m_volumeInstancePtr->m_originalVolume.m_pntr;
  v32 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v30, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
          _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v30, 0x10u), 0x10u)));
  v33 = _mm_add_ps(m_pntr[7], m_volumeInstancePtr->m_translation.m_quad);
  v34 = _mm_add_ps(_mm_mul_ps(m_pntr[6], v32), v33);
  v35 = _mm_add_ps(
          _mm_mul_ps(
            m_pntr[6],
            _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v28, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v28, 0x10u), 0x10u)))),
          v33);
  if ( m_edgeFilter && m_startCellKey == input->m_endCellKey )
  {
    v36 = p_m_endPoint->m_quad;
    v91 = -1;
    v89 = &v81;
    v92 = 0i64;
    v90 = v36;
    v83.m128i_i64[1] = (__int64)&input->m_agentInfo;
    v88 = m_startCellKey;
    v83.m128i_i64[0] = (__int64)m_volumeInstancePtr;
    portal.m128_i8[8] = 82;
    portal.m128_u64[0] = (unsigned __int64)&portal_16[16];
    if ( !m_edgeFilter->vfptr[2].__vecDelDtor(m_edgeFilter, (unsigned int)&v83) )
      goto LABEL_20;
    v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
    LODWORD(v21) = v79;
    v22 = -1;
  }
  v41 = input->m_startCellKey;
  v78 = v41;
  if ( v41 != input->m_endCellKey )
  {
    v42 = (__m128)xmmword_141A711B0;
    while ( 1 )
    {
      if ( v8 >= input->m_maxNumberOfIterations )
        goto LABEL_20;
      v43 = v96;
      v80 = ++v8;
      v44 = 0;
      v45 = (unsigned __int64)v96[(int)v21].m_volumeInstancePtr;
      if ( v81.m128i_i16[3] <= 0 )
        goto LABEL_58;
      v46 = (_DWORD)v21 << 22;
      while ( 1 )
      {
        v47 = *(_DWORD *)(v45 + 40);
        v48 = v44 + v82;
        v49 = (v44 + v82) | v46;
        if ( v44 + (int)v82 >= v47 )
        {
          v48 -= v47;
          v50 = *(_QWORD *)(v45 + 88);
        }
        else
        {
          v50 = *(_QWORD *)(v45 + 32);
        }
        *(_QWORD *)&portal_16[8] = *(_QWORD *)(v50 + 8i64 * v48);
        if ( (portal_16[8] & 0x40) != 0 )
          v51 = *(_DWORD *)&portal_16[12] & 0xFFC00000;
        else
          v51 = *(_DWORD *)(v45 + 108) << 22;
        v52 = v51 | *(_DWORD *)&portal_16[12] & 0x3FFFFF;
        if ( *(_DWORD *)&portal_16[12] == -1 )
          v52 = -1;
        *(_DWORD *)&portal_16[12] = v52;
        if ( v52 == v22 )
          goto LABEL_54;
        v53 = (__m128 *)v43[v52 >> 22].m_volumeInstancePtr;
        v54 = v53[1].m128_u64[0];
        v83 = *(__m128i *)(v54 + 24i64 * (v52 & 0x3FFFFF));
        v55 = _mm_loadu_si128(&v83);
        portal.m128_i32[0] = *(_DWORD *)(v54 + 24i64 * (v52 & 0x3FFFFF) + 16);
        v56 = v55;
        v57 = _mm_unpackhi_epi16(v55, (__m128i)0i64);
        portal.m128_i32[1] = *(_DWORD *)(v54 + 24i64 * (v52 & 0x3FFFFF) + 20);
        v58 = (__m128 *)v53[3].m128_u64[0];
        v59 = _mm_unpacklo_epi16(v56, (__m128i)0i64);
        v60 = _mm_add_ps(
                _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v59, 0x10u)), v20),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v59, 0x10u), 0x10u)));
        v61 = _mm_add_ps(v58[7], v53[7]);
        v62 = _mm_add_ps(_mm_mul_ps(v58[6], v60), v61);
        v63 = _mm_add_ps(
                _mm_mul_ps(
                  v58[6],
                  _mm_add_ps(
                    _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v57, 0x10u)), v20),
                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v57, 0x10u), 0x10u)))),
                v61);
        v64 = _mm_min_ps(v63, v35);
        v65 = _mm_max_ps(v62, v34);
        *(__m128 *)portal_16 = _mm_max_ps(v65, v64);
        portal = _mm_min_ps(v65, v64);
        v93 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)portal_16, portal), v42);
        if ( v93.m128_f32[0] == 0.0 )
        {
          v66 = 0i64;
        }
        else
        {
          v66 = 1i64;
          if ( v93.m128_f32[1] != 0.0 )
            v66 = 2i64;
        }
        v94 = _mm_mul_ps(_mm_add_ps(v35, v34), v42);
        v67 = v94.m128_f32[v66];
        v95 = _mm_mul_ps(_mm_add_ps(v63, v62), v42);
        v68 = v95.m128_f32[v66];
        v69 = v67 <= v68;
        if ( v67 >= v68 )
          goto LABEL_49;
        if ( v83.m128i_i32[v66] == 1 )
          break;
LABEL_53:
        v43 = v96;
LABEL_54:
        if ( ++v44 >= v81.m128i_i16[3] )
        {
          v41 = v78;
LABEL_56:
          doNotExceedArrayCapacity = v98;
          LODWORD(v21) = v79;
          goto LABEL_57;
        }
      }
      v69 = v67 <= v68;
LABEL_49:
      if ( !v69 && v83.m128i_i32[v66] != -1 )
        goto LABEL_53;
      if ( !rayGoesThroughPortal(&input->m_startPoint, &input->m_endPoint, (hkAabb *)&portal) )
      {
        v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
        v42 = (__m128)xmmword_141A711B0;
        v22 = v97;
        goto LABEL_53;
      }
      v75 = input->m_edgeFilter;
      if ( v75 )
      {
        v88 = v52;
        v41 = v78;
        v76 = v78 == input->m_startCellKey;
        v92 = &portal_16[8];
        v89 = &v83;
        v90 = _mm_mul_ps(_mm_add_ps(v63, v62), (__m128)xmmword_141A711B0);
        portal.m128_u64[1] = (unsigned __int64)&input->m_agentInfo;
        v91 = v49;
        *(_QWORD *)portal_16 = &portal_16[16];
        v77 = 34;
        portal.m128_u64[0] = v45;
        if ( v76 )
          v77 = 18;
        portal_16[8] = v77;
        if ( !v75->vfptr[2].__vecDelDtor(v75, (unsigned int)&portal) )
        {
          v44 = v81.m128i_i16[3];
          v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
          v42 = (__m128)xmmword_141A711B0;
          v22 = v97;
          goto LABEL_56;
        }
      }
      else
      {
        v41 = v78;
      }
      doNotExceedArrayCapacity = v98;
      if ( cellsArrayOut && (!v98 || cellsArrayOut->m_size < (cellsArrayOut->m_capacityAndFlags & 0x3FFFFFFF)) )
      {
        if ( cellsArrayOut->m_size == (cellsArrayOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, cellsArrayOut, 4);
        cellsArrayOut->m_data[cellsArrayOut->m_size++] = v41;
      }
      v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
      v81 = v83;
      v22 = v41;
      v42 = (__m128)xmmword_141A711B0;
      v34 = v62;
      v35 = v63;
      v97 = v41;
      m_quad = v90;
      v41 = *(_DWORD *)&portal_16[12];
      v82 = portal.m128_u64[0];
      v86 = &v81;
      v78 = *(_DWORD *)&portal_16[12];
      LODWORD(v21) = *(_DWORD *)&portal_16[12] >> 22;
      *(_DWORD *)&portal_16[16] = *(_DWORD *)&portal_16[12];
      v79 = *(_DWORD *)&portal_16[12] >> 22;
LABEL_57:
      v8 = v80;
LABEL_58:
      if ( v44 == v81.m128i_i16[3] )
        goto LABEL_20;
      if ( v41 == input->m_endCellKey )
      {
        streamingInfo = v96;
        p_m_endPoint = &input->m_endPoint;
        break;
      }
    }
  }
  v70 = input->m_edgeFilter;
  if ( v70 )
  {
    v71 = p_m_endPoint->m_quad;
    v88 = -1;
    v89 = 0i64;
    v92 = 0i64;
    v90 = v71;
    v91 = -1;
    portal_16[8] = 66;
    portal.m128_u64[0] = (unsigned __int64)streamingInfo[(int)v21].m_volumeInstancePtr;
    portal.m128_u64[1] = (unsigned __int64)&input->m_agentInfo;
    *(_QWORD *)portal_16 = &portal_16[16];
    if ( !v70->vfptr[2].__vecDelDtor(v70, (unsigned int)&portal) )
    {
LABEL_20:
      v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v38 = v37[1];
      if ( v38 < v37[3] )
      {
        *(_QWORD *)v38 = "Et";
        v39 = __rdtsc();
        *(_DWORD *)(v38 + 8) = v39;
        v37[1] = v38 + 16;
      }
      goto $lineOfSightFailure;
    }
  }
  v72 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v73 = v72[1];
  if ( v73 < v72[3] )
  {
    *(_QWORD *)v73 = "Et";
    v74 = __rdtsc();
    *(_DWORD *)(v73 + 8) = v74;
    v72[1] = v73 + 16;
  }
  if ( cellsArrayOut
    && (!doNotExceedArrayCapacity || cellsArrayOut->m_size < (cellsArrayOut->m_capacityAndFlags & 0x3FFFFFFF)) )
  {
    if ( cellsArrayOut->m_size == (cellsArrayOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, cellsArrayOut, 4);
    cellsArrayOut->m_data[cellsArrayOut->m_size++] = input->m_endCellKey;
  }
  if ( v99 )
    *v99 = v8;
  return 1;
}

