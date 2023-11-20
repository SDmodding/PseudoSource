// File Line: 23
// RVA: 0xC1DD90
void __fastcall hkaiVolumeLineOfSightUtil::LineOfSightInput::LineOfSightInput(hkaiVolumeLineOfSightUtil::LineOfSightInput *this)
{
  *(_QWORD *)&this->m_maxNumberOfIterations = 100000i64;
  this->m_agentInfo.m_filterInfo = 0;
  this->m_edgeFilter = 0i64;
}

// File Line: 27
// RVA: 0xC1E5D0
bool __fastcall rayGoesThroughPortal(hkVector4f *start, hkVector4f *end, hkAabb *portal)
{
  hkAabb *v3; // rbx
  hkVector4f *v4; // rdi
  hkVector4f *v5; // rsi
  __m128 v6; // xmm2
  __int64 v7; // rax
  __m128 v8; // xmm0
  hkSimdFloat32 tOut; // [rsp+20h] [rbp-28h]
  __m128 v11; // [rsp+30h] [rbp-18h]

  v3 = portal;
  v4 = end;
  v5 = start;
  if ( !hkaiNavVolumeUtils::getPortalPlaneIntersection(start, end, portal, &tOut)
    || tOut.m_real.m128_f32[0] < 0.0
    || tOut.m_real.m128_f32[0] > 1.0 )
  {
    return 0;
  }
  v6 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v4->m_quad, v5->m_quad), tOut.m_real), v5->m_quad);
  tOut.m_real = _mm_mul_ps(_mm_sub_ps(v3->m_max.m_quad, v3->m_min.m_quad), (__m128)xmmword_141A711B0);
  if ( tOut.m_real.m128_f32[0] == 0.0 )
  {
    LODWORD(v7) = 0;
  }
  else
  {
    LODWORD(v7) = 1;
    if ( tOut.m_real.m128_f32[1] != 0.0 )
      LODWORD(v7) = 2;
  }
  v8 = v3->m_min.m_quad;
  v7 = (signed int)v7;
  v11 = v3->m_max.m_quad;
  tOut.m_real = v8;
  tOut.m_real.m128_i32[v7] = -8388626;
  v11.m128_i32[v7] = 2139095022;
  return (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v6, v11), _mm_cmpleps(tOut.m_real, v6))) & 7) == 7;
}

// File Line: 78
// RVA: 0xC1DDB0
char __fastcall hkaiVolumeLineOfSightUtil::checkLineOfSight(hkaiStreamingCollection::InstanceInfo *streamingInfo, hkaiVolumeLineOfSightUtil::LineOfSightInput *input, hkArray<unsigned int,hkContainerHeapAllocator> *cellsArrayOut, bool doNotExceedArrayCapacity)
{
  hkaiVolumeLineOfSightUtil::LineOfSightInput *v4; // r13
  char v5; // r12
  hkArray<unsigned int,hkContainerHeapAllocator> *v6; // r14
  hkaiStreamingCollection::InstanceInfo *v7; // rsi
  int v8; // er15
  __m128 *v9; // rdi
  signed int v10; // eax
  __m128 v11; // xmm0
  signed int v12; // ecx
  signed int v13; // ecx
  _QWORD *v14; // r8
  _QWORD *v15; // rcx
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  unsigned int v18; // er8
  __m128 v19; // xmm0
  __m128 v20; // xmm5
  __int64 v21; // r10
  signed int v22; // er11
  __m128 *v23; // r9
  unsigned __int64 v24; // rcx
  __m128i v25; // xmm3
  int v26; // eax
  __m128i v27; // xmm1
  __m128i v28; // xmm3
  hkaiAstarEdgeFilter *v29; // rcx
  __m128i v30; // xmm1
  __m128 *v31; // rax
  __m128 v32; // xmm0
  __m128 v33; // xmm10
  __m128 v34; // xmm9
  __m128 v35; // xmm0
  _QWORD *v36; // r9
  unsigned __int64 v37; // r8
  unsigned __int64 v38; // rax
  int v40; // ebx
  __m128 v41; // xmm4
  __int64 v42; // rdx
  int v43; // edi
  hkaiNavVolumeInstance *v44; // rsi
  int v45; // er12
  int v46; // eax
  int v47; // ecx
  int v48; // er15
  hkaiNavVolume::Edge *v49; // rax
  unsigned int v50; // ecx
  unsigned int v51; // ebx
  __m128 *v52; // r8
  unsigned __int64 v53; // rcx
  __m128i v54; // xmm3
  __m128i v55; // xmm1
  __m128i v56; // xmm3
  __m128i v57; // xmm1
  __m128 *v58; // rax
  __m128 v59; // xmm0
  __m128 v60; // xmm7
  __m128 v61; // xmm6
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  signed __int64 v64; // rax
  float v65; // xmm0_4
  float v66; // xmm1_4
  bool v67; // cf
  bool v68; // zf
  hkaiAstarEdgeFilter *v69; // rcx
  __m128 v70; // xmm0
  _QWORD *v71; // r9
  unsigned __int64 v72; // r8
  unsigned __int64 v73; // rax
  hkaiAstarEdgeFilter *v74; // rcx
  char v75; // al
  int v76; // [rsp+20h] [rbp-A8h]
  unsigned int v77; // [rsp+24h] [rbp-A4h]
  int v78; // [rsp+28h] [rbp-A0h]
  __int128 v79; // [rsp+30h] [rbp-98h]
  __int64 v80; // [rsp+40h] [rbp-88h]
  __int128 v81; // [rsp+48h] [rbp-80h]
  char portal[40]; // [rsp+58h] [rbp-70h]
  __int128 *v83; // [rsp+80h] [rbp-48h]
  __m128 v84; // [rsp+88h] [rbp-40h]
  unsigned int v85; // [rsp+98h] [rbp-30h]
  __int128 *v86; // [rsp+A0h] [rbp-28h]
  __m128 v87; // [rsp+A8h] [rbp-20h]
  int v88; // [rsp+B8h] [rbp-10h]
  char *v89; // [rsp+C0h] [rbp-8h]
  __m128 v90; // [rsp+C8h] [rbp+0h]
  __m128 v91; // [rsp+D8h] [rbp+10h]
  __m128 v92; // [rsp+E8h] [rbp+20h]
  hkaiStreamingCollection::InstanceInfo *v93; // [rsp+198h] [rbp+D0h]
  int v94; // [rsp+1A0h] [rbp+D8h]
  char v95; // [rsp+1B0h] [rbp+E8h]
  int *v96; // [rsp+1B8h] [rbp+F0h]

  v4 = input;
  v5 = doNotExceedArrayCapacity;
  v6 = cellsArrayOut;
  v7 = streamingInfo;
  v8 = 0;
  if ( input->m_startCellKey == -1 || input->m_endCellKey == -1 )
  {
$lineOfSightFailure:
    if ( v6 )
      v6->m_size = 0;
    if ( v96 )
      *v96 = v8;
    return 0;
  }
  v9 = &input->m_endPoint.m_quad;
  v10 = -1;
  v11 = _mm_sub_ps(input->m_endPoint.m_quad, input->m_startPoint.m_quad);
  *(__m128 *)&portal[24] = v11;
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
  LODWORD(v81) = v12;
  if ( *(float *)&portal[28] <= 0.0 )
  {
    v13 = 0;
    if ( *(float *)&portal[28] != 0.0 )
      v13 = -1;
  }
  else
  {
    v13 = 1;
  }
  DWORD1(v81) = v13;
  if ( *(float *)&portal[32] <= 0.0 )
  {
    if ( *(float *)&portal[32] == 0.0 )
      v10 = 0;
  }
  else
  {
    v10 = 1;
  }
  DWORD2(v81) = v10;
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = (_QWORD *)v14[1];
  if ( (unsigned __int64)v15 < v14[3] )
  {
    *v15 = "TtlosCheck";
    v16 = __rdtsc();
    v17 = (signed __int64)(v15 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v14[1] = v17;
  }
  v18 = v4->m_startCellKey;
  v19 = v4->m_startPoint.m_quad;
  v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
  *(_DWORD *)&portal[32] = -1;
  v85 = -1;
  v83 = 0i64;
  v86 = 0i64;
  v89 = 0i64;
  v88 = -1;
  v21 = v18 >> 22;
  v22 = -1;
  v77 = v18 >> 22;
  v94 = -1;
  v23 = (__m128 *)v7[v21].m_volumeInstancePtr;
  v24 = v23[1].m128_u64[0];
  LODWORD(v79) = *(_DWORD *)(v23[1].m128_u64[0] + 24i64 * (v18 & 0x3FFFFF));
  *(_QWORD *)((char *)&v79 + 4) = *(_QWORD *)(v24 + 24i64 * (v18 & 0x3FFFFF) + 4);
  HIDWORD(v79) = *(_DWORD *)(v24 + 24i64 * (v18 & 0x3FFFFF) + 12);
  v25 = _mm_loadu_si128((const __m128i *)&v79);
  LODWORD(v80) = *(_DWORD *)(v24 + 24i64 * (v18 & 0x3FFFFF) + 16);
  v26 = *(_DWORD *)(v24 + 24i64 * (v18 & 0x3FFFFF) + 20);
  v27 = v25;
  v84 = v19;
  v28 = _mm_unpackhi_epi16(v25, (__m128i)0i64);
  v29 = v4->m_edgeFilter;
  v30 = _mm_unpacklo_epi16(v27, (__m128i)0i64);
  HIDWORD(v80) = v26;
  *(_DWORD *)&portal[32] = v18;
  v83 = &v79;
  v31 = (__m128 *)v23[3].m128_u64[0];
  v32 = _mm_add_ps(v31[7], v23[7]);
  v33 = _mm_add_ps(
          _mm_mul_ps(
            v31[6],
            _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v30, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v30, 0x10u), 0x10u)))),
          v32);
  v34 = _mm_add_ps(
          _mm_mul_ps(
            v31[6],
            _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v28, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v28, 0x10u), 0x10u)))),
          v32);
  if ( v29 && v18 == v4->m_endCellKey )
  {
    v35 = *v9;
    v88 = -1;
    v86 = &v79;
    v89 = 0i64;
    v87 = v35;
    *((_QWORD *)&v81 + 1) = (char *)v4 + 44;
    v85 = v18;
    *(_QWORD *)&v81 = v23;
    portal[8] = 82;
    *(_QWORD *)portal = &portal[32];
    if ( !(unsigned __int8)v29->vfptr[2].__vecDelDtor((hkBaseObject *)&v29->vfptr, (unsigned int)&v81) )
      goto LABEL_20;
    v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
    LODWORD(v21) = v77;
    v22 = -1;
  }
  v40 = v4->m_startCellKey;
  v76 = v40;
  if ( v40 != v4->m_endCellKey )
  {
    v41 = (__m128)xmmword_141A711B0;
    while ( 1 )
    {
      if ( v8 >= v4->m_maxNumberOfIterations )
        goto LABEL_20;
      v42 = (__int64)v93;
      v78 = ++v8;
      v43 = 0;
      v44 = v93[(signed int)v21].m_volumeInstancePtr;
      if ( SWORD3(v79) <= 0 )
        goto LABEL_59;
      v45 = (_DWORD)v21 << 22;
      while ( 1 )
      {
        v46 = v44->m_numOriginalEdges;
        v47 = v43 + v80;
        v48 = (v43 + v80) | v45;
        if ( v43 + (signed int)v80 >= v46 )
        {
          v47 -= v46;
          v49 = v44->m_ownedEdges.m_data;
        }
        else
        {
          v49 = v44->m_originalEdges;
        }
        *(hkaiNavVolume::Edge *)&portal[24] = v49[v47];
        if ( portal[24] & 0x40 )
          v50 = *(_DWORD *)&portal[28] & 0xFFC00000;
        else
          v50 = v44->m_runtimeId << 22;
        v51 = v50 | *(_DWORD *)&portal[28] & 0x3FFFFF;
        if ( *(_DWORD *)&portal[28] == -1 )
          v51 = -1;
        *(_DWORD *)&portal[28] = v51;
        if ( v51 == v22 )
          goto LABEL_55;
        v52 = *(__m128 **)(v42 + 48i64 * (v51 >> 22) + 8);
        v53 = v52[1].m128_u64[0];
        v81 = *(_OWORD *)(v53 + 24i64 * (v51 & 0x3FFFFF));
        v54 = _mm_loadu_si128((const __m128i *)&v81);
        *(_DWORD *)portal = *(_DWORD *)(v53 + 24i64 * (v51 & 0x3FFFFF) + 16);
        v55 = v54;
        v56 = _mm_unpackhi_epi16(v54, (__m128i)0i64);
        v57 = _mm_unpacklo_epi16(v55, (__m128i)0i64);
        *(_DWORD *)&portal[4] = *(_DWORD *)(v53 + 24i64 * (v51 & 0x3FFFFF) + 20);
        v58 = (__m128 *)v52[3].m128_u64[0];
        v59 = _mm_add_ps(v58[7], v52[7]);
        v60 = _mm_add_ps(
                _mm_mul_ps(
                  v58[6],
                  _mm_add_ps(
                    _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v57, 0x10u)), v20),
                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v57, 0x10u), 0x10u)))),
                v59);
        v61 = _mm_add_ps(
                _mm_mul_ps(
                  v58[6],
                  _mm_add_ps(
                    _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v56, 0x10u)), v20),
                    _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v56, 0x10u), 0x10u)))),
                v59);
        v62 = _mm_max_ps(v60, v33);
        v63 = _mm_min_ps(v61, v34);
        *(__m128 *)&portal[16] = _mm_max_ps(v62, v63);
        *(__m128 *)portal = _mm_min_ps(v62, v63);
        v90 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)&portal[16], *(__m128 *)portal), v41);
        if ( v90.m128_f32[0] == 0.0 )
        {
          v64 = 0i64;
        }
        else
        {
          v64 = 1i64;
          if ( v90.m128_f32[1] != 0.0 )
            v64 = 2i64;
        }
        v91 = _mm_mul_ps(_mm_add_ps(v34, v33), v41);
        v65 = v91.m128_f32[v64];
        v92 = _mm_mul_ps(_mm_add_ps(v61, v60), v41);
        v66 = v92.m128_f32[v64];
        v67 = v65 < v66;
        v68 = v65 == v66;
        if ( v65 >= v66 )
          goto LABEL_50;
        if ( *((_DWORD *)&v81 + v64) == 1 )
          break;
LABEL_54:
        v42 = (__int64)v93;
LABEL_55:
        if ( ++v43 >= SWORD3(v79) )
        {
          v40 = v76;
LABEL_57:
          v5 = v95;
          LODWORD(v21) = v77;
          goto LABEL_58;
        }
      }
      v67 = v65 < v66;
      v68 = v65 == v66;
LABEL_50:
      if ( !v67 && !v68 && *((_DWORD *)&v81 + v64) != -1 )
        goto LABEL_54;
      if ( !rayGoesThroughPortal(&v4->m_startPoint, &v4->m_endPoint, (hkAabb *)portal) )
      {
        v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
        v41 = (__m128)xmmword_141A711B0;
        v22 = v94;
        goto LABEL_54;
      }
      v74 = v4->m_edgeFilter;
      if ( v74 )
      {
        v85 = v51;
        v40 = v76;
        v68 = v76 == v4->m_startCellKey;
        v89 = &portal[24];
        v86 = &v81;
        v87 = _mm_mul_ps(_mm_add_ps(v61, v60), (__m128)xmmword_141A711B0);
        *(_QWORD *)&portal[8] = (char *)v4 + 44;
        v88 = v48;
        *(_QWORD *)&portal[16] = &portal[32];
        v75 = 34;
        *(_QWORD *)portal = v44;
        if ( v68 )
          v75 = 18;
        portal[24] = v75;
        if ( !(unsigned __int8)v74->vfptr[2].__vecDelDtor((hkBaseObject *)&v74->vfptr, (unsigned int)portal) )
        {
          v43 = SWORD3(v79);
          v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
          v41 = (__m128)xmmword_141A711B0;
          v22 = v94;
          goto LABEL_57;
        }
      }
      else
      {
        v40 = v76;
      }
      v5 = v95;
      if ( v6 && (!v95 || v6->m_size < (v6->m_capacityAndFlags & 0x3FFFFFFF)) )
      {
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 4);
        v6->m_data[v6->m_size++] = v40;
      }
      v20 = (__m128)`hkIntVector::convertU32ToF32::`2::two16;
      v79 = v81;
      v22 = v40;
      v41 = (__m128)xmmword_141A711B0;
      v33 = v60;
      v34 = v61;
      v94 = v40;
      v84 = v87;
      v40 = *(_DWORD *)&portal[28];
      v80 = *(_QWORD *)portal;
      v83 = &v79;
      v76 = *(_DWORD *)&portal[28];
      LODWORD(v21) = *(_DWORD *)&portal[28] >> 22;
      *(_DWORD *)&portal[32] = *(_DWORD *)&portal[28];
      v77 = *(_DWORD *)&portal[28] >> 22;
LABEL_58:
      v8 = v78;
LABEL_59:
      if ( v43 == SWORD3(v79) )
        goto LABEL_20;
      if ( v40 == v4->m_endCellKey )
      {
        v7 = v93;
        v9 = &v4->m_endPoint.m_quad;
        break;
      }
    }
  }
  v69 = v4->m_edgeFilter;
  if ( v69 )
  {
    v70 = *v9;
    v85 = -1;
    v86 = 0i64;
    v89 = 0i64;
    v87 = v70;
    v88 = -1;
    portal[24] = 66;
    *(_QWORD *)portal = v7[(signed int)v21].m_volumeInstancePtr;
    *(_QWORD *)&portal[8] = (char *)v4 + 44;
    *(_QWORD *)&portal[16] = &portal[32];
    if ( !(unsigned __int8)v69->vfptr[2].__vecDelDtor((hkBaseObject *)&v69->vfptr, (unsigned int)portal) )
    {
LABEL_20:
      v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v37 = v36[1];
      if ( v37 < v36[3] )
      {
        *(_QWORD *)v37 = "Et";
        v38 = __rdtsc();
        *(_DWORD *)(v37 + 8) = v38;
        v36[1] = v37 + 16;
      }
      goto $lineOfSightFailure;
    }
  }
  v71 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v72 = v71[1];
  if ( v72 < v71[3] )
  {
    *(_QWORD *)v72 = "Et";
    v73 = __rdtsc();
    *(_DWORD *)(v72 + 8) = v73;
    v71[1] = v72 + 16;
  }
  if ( v6 && (!v5 || v6->m_size < (v6->m_capacityAndFlags & 0x3FFFFFFF)) )
  {
    if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 4);
    v6->m_data[v6->m_size++] = v4->m_endCellKey;
  }
  if ( v96 )
    *v96 = v8;
  return 1;
}

