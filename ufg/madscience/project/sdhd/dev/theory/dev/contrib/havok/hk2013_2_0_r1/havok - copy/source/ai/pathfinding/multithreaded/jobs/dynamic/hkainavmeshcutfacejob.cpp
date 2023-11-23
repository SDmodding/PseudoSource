// File Line: 32
// RVA: 0xBD8C20
void __fastcall convertAabbToSilhouette(
        hkAabb *genAabb,
        hkaiSilhouetteGenerationParameters *generationParams,
        hkArrayBase<hkVector4f> *vertices,
        float extraRadius,
        int *silSize)
{
  hkSimdFloat32 extraRadiusa; // [rsp+20h] [rbp-18h] BYREF

  extraRadiusa.m_real = _mm_shuffle_ps((__m128)LODWORD(extraRadius), (__m128)LODWORD(extraRadius), 0);
  hkaiConvex2dUtils::createAabbSilhouette(generationParams, genAabb, &extraRadiusa, vertices);
  *silSize = vertices->m_size;
}

// File Line: 39
// RVA: 0xBD8C70
__int64 __fastcall hkaiProcessNavMeshCutFaceJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // r9
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rax
  int index; // ebx
  hkaiNavMeshInstance *v8; // rsi
  int m_numEdges; // ebx
  int v10; // edi
  hkLifoAllocator *v11; // rcx
  char *m_cur; // rax
  int v13; // edx
  char *v14; // r8
  hkLifoAllocator *v15; // rcx
  int *v16; // rax
  int v17; // edx
  char *v18; // r8
  __m128 v19; // xmm0
  __int64 v20; // rbx
  bool v21; // zf
  __m128 m_quad; // xmm6
  __m128 v23; // xmm6
  __m128 v24; // xmm5
  __m128 v25; // xmm6
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  int v29; // r12d
  __int64 v30; // rdi
  hkLifoAllocator *v31; // rax
  hkVector4f *v32; // rcx
  hkVector4f *v33; // rdx
  hkLifoAllocator *v34; // rax
  int *v35; // rcx
  int *v36; // rdx
  __int64 v37; // rax
  hkQTransformf *v38; // rbx
  _QWORD *v39; // r8
  _QWORD *v40; // rcx
  unsigned __int64 v41; // rax
  _QWORD *v42; // rcx
  int v43; // eax
  char *v44; // rdi
  signed int v45; // ebx
  hkLifoAllocator *v46; // rax
  int v47; // r8d
  int v48; // eax
  hkVector4f *v49; // rdi
  signed int v50; // ebx
  hkLifoAllocator *v51; // rax
  int v52; // r8d
  hkaiSilhouetteGenerator *v53; // r14
  hkVector4f v54; // xmm1
  __m128 v55; // xmm0
  int v56; // eax
  char *v57; // rdi
  signed int v58; // ebx
  hkLifoAllocator *v59; // rax
  int v60; // r8d
  int v61; // eax
  hkVector4f *v62; // rdi
  signed int v63; // ebx
  hkLifoAllocator *v64; // rax
  int v65; // r8d
  _QWORD *v66; // r8
  _QWORD *v67; // rcx
  unsigned __int64 v68; // rax
  _QWORD *v69; // rcx
  int m_size; // eax
  int v71; // esi
  __int64 v72; // rdi
  __int64 v73; // r15
  int v74; // ebx
  int m_materialId; // r9d
  char *v76; // rdi
  signed int v77; // ebx
  hkLifoAllocator *v78; // rax
  int v79; // r8d
  int v80; // eax
  hkVector4f *v81; // rdi
  signed int v82; // ebx
  hkLifoAllocator *v83; // rax
  int v84; // r8d
  _QWORD *v85; // rax
  _QWORD *v86; // rcx
  _QWORD *v87; // r8
  unsigned __int64 v88; // rax
  _QWORD *v89; // rcx
  _QWORD *v90; // r8
  _QWORD *v91; // rcx
  unsigned __int64 v92; // rax
  _QWORD *v93; // rcx
  hkJobQueue::JobStatus NextJob; // eax
  int v95; // ecx
  char *v96; // rdi
  hkJobQueue::JobStatus v97; // esi
  signed int v98; // ebx
  hkLifoAllocator *v99; // rax
  int v100; // r8d
  int v101; // eax
  char *v102; // rdi
  signed int v103; // ebx
  hkLifoAllocator *v104; // rax
  int v105; // r8d
  hkArrayBase<int> v107; // [rsp+40h] [rbp-A8h] BYREF
  void *p; // [rsp+50h] [rbp-98h]
  int v109; // [rsp+58h] [rbp-90h]
  hkArrayBase<hkVector4f> vertices; // [rsp+60h] [rbp-88h] BYREF
  hkVector4f *v111; // [rsp+70h] [rbp-78h]
  void *v112; // [rsp+78h] [rbp-70h]
  int v113; // [rsp+80h] [rbp-68h]
  hkArrayBase<int> indexRemap; // [rsp+88h] [rbp-60h] BYREF
  void *v115; // [rsp+98h] [rbp-50h]
  int v116; // [rsp+A0h] [rbp-48h]
  hkSimdFloat32 regionExpansion; // [rsp+A8h] [rbp-40h] BYREF
  hkVector4f up; // [rsp+B8h] [rbp-30h] BYREF
  hkaiAbstractFaceCutter v119; // [rsp+C8h] [rbp-20h] BYREF
  hkaiSilhouetteGenerationParameters generationParams; // [rsp+F8h] [rbp+10h] BYREF
  hkAabb aabbInOut; // [rsp+138h] [rbp+50h] BYREF
  hkSimdFloat32 extrusion; // [rsp+158h] [rbp+70h] BYREF
  hkAabb genAabb; // [rsp+168h] [rbp+80h] BYREF
  hkQTransformf v124; // [rsp+188h] [rbp+A0h] BYREF
  hkJobQueue *v125; // [rsp+208h] [rbp+120h]
  int silSize; // [rsp+210h] [rbp+128h] BYREF
  char *retaddr; // [rsp+218h] [rbp+130h]
  __int64 v128; // [rsp+220h] [rbp+138h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = Value[1];
  if ( v5 < Value[3] )
  {
    *(_QWORD *)v5 = "LtCutFaceJob";
    *(_QWORD *)(v5 + 16) = "Stinit";
    v6 = __rdtsc();
    *(_DWORD *)(v5 + 8) = v6;
    Value[1] = v5 + 24;
  }
  index = *(_DWORD *)&nextJobOut->m_data[24] & 0x3FFFFF;
  hkaiAbstractFaceCutter::hkaiAbstractFaceCutter(&v119, nextJobOut->m_data[73] != 0);
  v8 = *(hkaiNavMeshInstance **)&nextJobOut->m_data[16];
  generationParams = *(hkaiSilhouetteGenerationParameters *)*(_QWORD *)&nextJobOut->m_data[88];
  m_numEdges = hkaiNavMeshInstance_get_hkaiNavMesh::Face__6(
                 v8->m_originalFaces,
                 v8->m_numOriginalFaces,
                 &v8->m_instancedFaces,
                 &v8->m_ownedFaces,
                 &v8->m_faceMap,
                 index)->m_numEdges;
  *(_QWORD *)&vertices.m_size = 0i64;
  v111 = (hkVector4f *)0x8000000000000000i64;
  v10 = m_numEdges + 1;
  v113 = m_numEdges + 1;
  if ( m_numEdges == -1 )
  {
    m_cur = 0i64;
  }
  else
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)v11->m_cur;
    v13 = (16 * v10 + 127) & 0xFFFFFF80;
    v14 = &m_cur[v13];
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
    else
      v11->m_cur = v14;
  }
  *(_QWORD *)&vertices.m_size = m_cur;
  v112 = m_cur;
  indexRemap.m_data = 0i64;
  indexRemap.m_size = 0;
  indexRemap.m_capacityAndFlags = 0x80000000;
  HIDWORD(v111) = v10 | 0x80000000;
  v116 = m_numEdges;
  if ( m_numEdges )
  {
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (int *)v15->m_cur;
    v17 = (4 * m_numEdges + 127) & 0xFFFFFF80;
    v18 = (char *)v16 + v17;
    if ( v17 > v15->m_slabSize || v18 > v15->m_end )
      v16 = (int *)hkLifoAllocator::allocateFromNewSlab(v15, v17);
    else
      v15->m_cur = v18;
  }
  else
  {
    v16 = 0i64;
  }
  v19 = *(__m128 *)&nextJobOut->m_data[48];
  indexRemap.m_capacityAndFlags = m_numEdges | 0x80000000;
  v20 = *(int *)&nextJobOut->m_data[40];
  indexRemap.m_data = v16;
  up.m_quad = v19;
  v115 = v16;
  if ( (int)v20 <= 0 )
  {
    hkaiAbstractFaceCutter::reset(&v119, *(_DWORD *)&nextJobOut->m_data[24]);
  }
  else
  {
    v21 = nextJobOut->m_data[72] == 0;
    regionExpansion.m_real = _mm_shuffle_ps(
                               (__m128)LODWORD(generationParams.m_maxSilhouetteSize),
                               (__m128)LODWORD(generationParams.m_maxSilhouetteSize),
                               0);
    hkaiAbstractFaceCutter::setFace(
      &v119,
      v8,
      (hkVector4f *)&nextJobOut->m_data[48],
      !v21,
      *(_DWORD *)&nextJobOut->m_data[24],
      &regionExpansion,
      (hkArrayBase<hkVector4f> *)&vertices.m_size,
      &indexRemap);
    m_quad = hkaiAbstractFaceCutter::getUp(&v119)->m_quad;
    up.m_quad = m_quad;
    if ( _mm_movemask_ps(_mm_cmpeq_ps(generationParams.m_referenceFrame.m_up.m_quad, m_quad)) != 15 )
    {
      v23 = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(m_quad, (__m128)0i64), 196);
      v24 = _mm_shuffle_ps(v23, v23, 241);
      v25 = _mm_shuffle_ps(v23, v23, 206);
      v26 = _mm_mul_ps(v25, v25);
      v27 = _mm_mul_ps(v24, v24);
      v28 = _mm_cmplt_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                _mm_shuffle_ps(v27, v27, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                _mm_shuffle_ps(v26, v26, 170)));
      regionExpansion.m_real = _mm_xor_ps(
                                 _mm_or_ps(_mm_and_ps(v28, v25), _mm_andnot_ps(v28, v24)),
                                 (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      hkaiSilhouetteReferenceFrame::set(&generationParams.m_referenceFrame, &up, (hkVector4f *)&regionExpansion);
    }
  }
  v29 = 0;
  v30 = 0i64;
  retaddr = 0i64;
  v128 = v20;
  if ( (int)v20 > 0 )
  {
    while ( 1 )
    {
      vertices.m_data = 0i64;
      vertices.m_size = 0;
      vertices.m_capacityAndFlags = 0x80000000;
      LODWORD(v112) = 2048;
      v31 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v32 = (hkVector4f *)v31->m_cur;
      v33 = v32 + 2048;
      if ( v31->m_slabSize < 0x8000 || v33 > v31->m_end )
        v32 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v31, 0x8000);
      else
        v31->m_cur = v33;
      vertices.m_data = v32;
      v111 = v32;
      vertices.m_capacityAndFlags = -2147481600;
      v107.m_data = 0i64;
      v107.m_size = 0;
      v107.m_capacityAndFlags = 0x80000000;
      v109 = 16;
      v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v35 = (int *)v34->m_cur;
      v36 = v35 + 32;
      if ( v34->m_slabSize < 128 || v36 > v34->m_end )
        v35 = (int *)hkLifoAllocator::allocateFromNewSlab(v34, 128);
      else
        v34->m_cur = v36;
      v37 = *(_QWORD *)&nextJobOut->m_data[32];
      v107.m_data = v35;
      p = v35;
      v107.m_capacityAndFlags = -2147483632;
      v38 = *(hkQTransformf **)(v37 + 8 * v30);
      v39 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v40 = (_QWORD *)v39[1];
      if ( (unsigned __int64)v40 < v39[3] )
      {
        *v40 = "StgatherSilhouettes";
        v41 = __rdtsc();
        v42 = v40 + 2;
        *((_DWORD *)v42 - 2) = v41;
        v39[1] = v42;
      }
      if ( v38[1].m_rotation.m_vec.m_quad.m128_i8[13] )
      {
        v53 = (hkaiSilhouetteGenerator *)v38[1].m_rotation.m_vec.m_quad.m128_u64[0];
        v124 = *v38;
        g_getAabbFunc(v53, &v124, &genAabb);
        v54.m_quad = (__m128)genAabb.m_max;
        aabbInOut = genAabb;
        v54.m_quad.m128_f32[0] = *(float *)&nextJobOut->m_data[68] + v53->m_lazyRecomputeDisplacementThreshold;
        v55 = _mm_shuffle_ps(
                (__m128)*(unsigned int *)&nextJobOut->m_data[64],
                (__m128)*(unsigned int *)&nextJobOut->m_data[64],
                0);
        regionExpansion.m_real = _mm_shuffle_ps(v54.m_quad, v54.m_quad, 0);
        extrusion.m_real = v55;
        hkaiSilhouetteGenerator::expandAabb(&aabbInOut, &up, &extrusion, &regionExpansion, 3u);
        if ( (unsigned int)hkaiNavMeshUtils::faceAabbCheck(&aabbInOut, (hkArrayBase<hkVector4f> *)&vertices.m_size) )
        {
          g_generateSilhouettesFunc(v53, &v124, &generationParams, &vertices, &v107);
          v66 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v67 = (_QWORD *)v66[1];
          if ( (unsigned __int64)v67 < v66[3] )
          {
            *v67 = "StaddToCutter";
            v68 = __rdtsc();
            v69 = v67 + 2;
            *((_DWORD *)v69 - 2) = v68;
            v66[1] = v69;
          }
          m_size = v107.m_size;
          v71 = 0;
          v72 = 0i64;
          v73 = v107.m_size;
          if ( v107.m_size > 0 )
          {
            do
            {
              v74 = v107.m_data[v72];
              silSize = v74;
              if ( !v74 )
              {
                convertAabbToSilhouette(
                  &genAabb,
                  &generationParams,
                  &vertices,
                  v53->m_lazyRecomputeDisplacementThreshold,
                  &silSize);
                v74 = silSize;
                v72 = v73;
              }
              if ( v29 < *(_DWORD *)&nextJobOut->m_data[44] )
                m_materialId = -1;
              else
                m_materialId = v53->m_materialId;
              hkaiAbstractFaceCutter::addSilhouette(&v119, &vertices.m_data[v71], v74, m_materialId);
              ++v72;
              v71 += v74;
            }
            while ( v72 < v73 );
            m_size = v107.m_size;
          }
          v76 = (char *)p;
          if ( p == v107.m_data )
            m_size = 0;
          v107.m_size = m_size;
          v77 = (4 * v109 + 127) & 0xFFFFFF80;
          v78 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v79 = (v77 + 15) & 0xFFFFFFF0;
          if ( v77 > v78->m_slabSize || &v76[v79] != v78->m_cur || v78->m_firstNonLifoEnd == v76 )
            hkLifoAllocator::slowBlockFree(v78, v76, v79);
          else
            v78->m_cur = v76;
          v107.m_size = 0;
          if ( v107.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v107.m_data,
              4 * v107.m_capacityAndFlags);
          v80 = vertices.m_size;
          v81 = v111;
          v107.m_data = 0i64;
          if ( v111 == vertices.m_data )
            v80 = 0;
          v107.m_capacityAndFlags = 0x80000000;
          vertices.m_size = v80;
          v82 = (16 * (_DWORD)v112 + 127) & 0xFFFFFF80;
          v83 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v84 = (v82 + 15) & 0xFFFFFFF0;
          if ( v82 > v83->m_slabSize || (char *)v81 + v84 != v83->m_cur || v83->m_firstNonLifoEnd == v81 )
            hkLifoAllocator::slowBlockFree(v83, v81, v84);
          else
            v83->m_cur = v81;
          vertices.m_size = 0;
          if ( vertices.m_capacityAndFlags < 0 )
            goto LABEL_96;
        }
        else
        {
          v56 = v107.m_size;
          v57 = (char *)p;
          if ( p == v107.m_data )
            v56 = 0;
          v107.m_size = v56;
          v58 = (4 * v109 + 127) & 0xFFFFFF80;
          v59 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v60 = (v58 + 15) & 0xFFFFFFF0;
          if ( v58 > v59->m_slabSize || &v57[v60] != v59->m_cur || v59->m_firstNonLifoEnd == v57 )
            hkLifoAllocator::slowBlockFree(v59, v57, v60);
          else
            v59->m_cur = v57;
          v107.m_size = 0;
          if ( v107.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v107.m_data,
              4 * v107.m_capacityAndFlags);
          v61 = vertices.m_size;
          v62 = v111;
          v107.m_data = 0i64;
          if ( v111 == vertices.m_data )
            v61 = 0;
          v107.m_capacityAndFlags = 0x80000000;
          vertices.m_size = v61;
          v63 = (16 * (_DWORD)v112 + 127) & 0xFFFFFF80;
          v64 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v65 = (v63 + 15) & 0xFFFFFFF0;
          if ( v63 > v64->m_slabSize || (char *)v62 + v65 != v64->m_cur || v64->m_firstNonLifoEnd == v62 )
            hkLifoAllocator::slowBlockFree(v64, v62, v65);
          else
            v64->m_cur = v62;
          vertices.m_size = 0;
          if ( vertices.m_capacityAndFlags < 0 )
            goto LABEL_96;
        }
      }
      else
      {
        v43 = v107.m_size;
        v44 = (char *)p;
        if ( p == v107.m_data )
          v43 = 0;
        v107.m_size = v43;
        v45 = (4 * v109 + 127) & 0xFFFFFF80;
        v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v47 = (v45 + 15) & 0xFFFFFFF0;
        if ( v45 > v46->m_slabSize || &v44[v47] != v46->m_cur || v46->m_firstNonLifoEnd == v44 )
          hkLifoAllocator::slowBlockFree(v46, v44, v47);
        else
          v46->m_cur = v44;
        v107.m_size = 0;
        if ( v107.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v107.m_data,
            4 * v107.m_capacityAndFlags);
        v48 = vertices.m_size;
        v49 = v111;
        v107.m_data = 0i64;
        if ( v111 == vertices.m_data )
          v48 = 0;
        v107.m_capacityAndFlags = 0x80000000;
        vertices.m_size = v48;
        v50 = (16 * (_DWORD)v112 + 127) & 0xFFFFFF80;
        v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v52 = (v50 + 15) & 0xFFFFFFF0;
        if ( v50 > v51->m_slabSize || (char *)v49 + v52 != v51->m_cur || v51->m_firstNonLifoEnd == v49 )
          hkLifoAllocator::slowBlockFree(v51, v49, v52);
        else
          v51->m_cur = v49;
        vertices.m_size = 0;
        if ( vertices.m_capacityAndFlags < 0 )
          goto LABEL_96;
      }
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        vertices.m_data,
        16 * vertices.m_capacityAndFlags);
LABEL_96:
      ++v29;
      v30 = (__int64)(retaddr + 1);
      retaddr = (char *)v30;
      if ( v30 >= v128 )
      {
        jobQueue = v125;
        break;
      }
    }
  }
  v85 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v86 = (_QWORD *)v85[1];
  v87 = v85;
  if ( (unsigned __int64)v86 < v85[3] )
  {
    *v86 = "Stconvexify";
    v88 = __rdtsc();
    v89 = v86 + 2;
    *((_DWORD *)v89 - 2) = v88;
    v87[1] = v89;
  }
  hkaiAbstractFaceCutter::computeConvexDecomposition(
    &v119,
    *(hkaiFaceCutResults **)&nextJobOut->m_data[80],
    (hkArrayBase<hkVector4f> *)&vertices.m_size,
    &indexRemap);
  v90 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v91 = (_QWORD *)v90[1];
  if ( (unsigned __int64)v91 < v90[3] )
  {
    *v91 = "lt";
    v92 = __rdtsc();
    v93 = v91 + 2;
    *((_DWORD *)v93 - 2) = v92;
    v90[1] = v93;
  }
  NextJob = hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
  v95 = indexRemap.m_size;
  v96 = (char *)v115;
  v97 = NextJob;
  if ( v115 == indexRemap.m_data )
    v95 = 0;
  indexRemap.m_size = v95;
  v98 = (4 * v116 + 127) & 0xFFFFFF80;
  v99 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v100 = (v98 + 15) & 0xFFFFFFF0;
  if ( v98 > v99->m_slabSize || &v96[v100] != v99->m_cur || v99->m_firstNonLifoEnd == v96 )
    hkLifoAllocator::slowBlockFree(v99, v96, v100);
  else
    v99->m_cur = v96;
  indexRemap.m_size = 0;
  if ( indexRemap.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      indexRemap.m_data,
      4 * indexRemap.m_capacityAndFlags);
  v101 = (int)v111;
  v102 = (char *)v112;
  indexRemap.m_data = 0i64;
  if ( v112 == *(void **)&vertices.m_size )
    v101 = 0;
  indexRemap.m_capacityAndFlags = 0x80000000;
  LODWORD(v111) = v101;
  v103 = (16 * v113 + 127) & 0xFFFFFF80;
  v104 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v105 = (v103 + 15) & 0xFFFFFFF0;
  if ( v103 > v104->m_slabSize || &v102[v105] != v104->m_cur || v104->m_firstNonLifoEnd == v102 )
    hkLifoAllocator::slowBlockFree(v104, v102, v105);
  else
    v104->m_cur = v102;
  LODWORD(v111) = 0;
  if ( SHIDWORD(v111) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)&vertices.m_size,
      16 * HIDWORD(v111));
  *(_QWORD *)&vertices.m_size = 0i64;
  HIDWORD(v111) = 0x80000000;
  hkaiAbstractFaceCutter::~hkaiAbstractFaceCutter(&v119);
  return (unsigned int)v97;
}

