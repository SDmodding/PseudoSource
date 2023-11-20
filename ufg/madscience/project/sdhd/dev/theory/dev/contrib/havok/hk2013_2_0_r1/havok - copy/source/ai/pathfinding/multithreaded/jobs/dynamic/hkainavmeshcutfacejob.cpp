// File Line: 32
// RVA: 0xBD8C20
void __fastcall convertAabbToSilhouette(hkAabb *genAabb, hkaiSilhouetteGenerationParameters *generationParams, hkArrayBase<hkVector4f> *vertices, float extraRadius, int *silSize)
{
  hkArrayBase<hkVector4f> *v5; // rbx
  hkSimdFloat32 extraRadiusa; // [rsp+20h] [rbp-18h]

  v5 = vertices;
  extraRadiusa.m_real = _mm_shuffle_ps((__m128)LODWORD(extraRadius), (__m128)LODWORD(extraRadius), 0);
  hkaiConvex2dUtils::createAabbSilhouette(generationParams, genAabb, &extraRadiusa, vertices);
  *silSize = v5->m_size;
}

// File Line: 39
// RVA: 0xBD8C70
__int64 __fastcall hkaiProcessNavMeshCutFaceJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // r14
  hkJobQueue::JobQueueEntry *v3; // r13
  _QWORD *v4; // r9
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rax
  int index; // ebx
  __int64 v8; // rax
  hkaiNavMeshInstance *v9; // rsi
  int v10; // ebx
  int v11; // edi
  hkLifoAllocator *v12; // rax
  hkLifoAllocator *v13; // rcx
  char *v14; // rax
  int v15; // edx
  char *v16; // r8
  LPVOID v17; // rax
  hkLifoAllocator *v18; // rcx
  int *v19; // rax
  int v20; // edx
  char *v21; // r8
  __m128i v22; // xmm0
  signed __int64 v23; // rbx
  bool v24; // zf
  __m128 v25; // xmm6
  __m128 v26; // xmm6
  __m128 v27; // xmm5
  __m128 v28; // xmm6
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  __m128 v31; // xmm2
  int v32; // er12
  signed __int64 v33; // rdi
  hkLifoAllocator *v34; // rax
  hkVector4f *v35; // rcx
  unsigned __int64 v36; // rdx
  hkLifoAllocator *v37; // rax
  int *v38; // rcx
  unsigned __int64 v39; // rdx
  __int64 v40; // rax
  __m128i *v41; // rbx
  _QWORD *v42; // r8
  _QWORD *v43; // rcx
  unsigned __int64 v44; // rax
  signed __int64 v45; // rcx
  int v46; // eax
  char *v47; // rdi
  signed int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // er8
  int v51; // eax
  char *v52; // rdi
  signed int v53; // ebx
  hkLifoAllocator *v54; // rax
  int v55; // er8
  hkaiSilhouetteGenerator *v56; // r14
  hkVector4f v57; // xmm1
  __m128 v58; // xmm0
  int v59; // eax
  char *v60; // rdi
  signed int v61; // ebx
  hkLifoAllocator *v62; // rax
  int v63; // er8
  int v64; // eax
  char *v65; // rdi
  signed int v66; // ebx
  hkLifoAllocator *v67; // rax
  int v68; // er8
  _QWORD *v69; // r8
  _QWORD *v70; // rcx
  unsigned __int64 v71; // rax
  signed __int64 v72; // rcx
  int v73; // eax
  int v74; // esi
  __int64 v75; // rdi
  __int64 v76; // r15
  int v77; // ebx
  int v78; // er9
  char *v79; // rdi
  signed int v80; // ebx
  hkLifoAllocator *v81; // rax
  int v82; // er8
  int v83; // eax
  char *v84; // rdi
  signed int v85; // ebx
  hkLifoAllocator *v86; // rax
  int v87; // er8
  _QWORD *v88; // rax
  _QWORD *v89; // rcx
  _QWORD *v90; // r8
  unsigned __int64 v91; // rax
  signed __int64 v92; // rcx
  _QWORD *v93; // r8
  _QWORD *v94; // rcx
  unsigned __int64 v95; // rax
  signed __int64 v96; // rcx
  hkJobQueue::JobStatus v97; // eax
  int v98; // ecx
  char *v99; // rdi
  hkJobQueue::JobStatus v100; // esi
  signed int v101; // ebx
  hkLifoAllocator *v102; // rax
  int v103; // er8
  int v104; // eax
  char *v105; // rdi
  signed int v106; // ebx
  hkLifoAllocator *v107; // rax
  int v108; // er8
  hkArrayBase<int> v110; // [rsp+40h] [rbp-A8h]
  void *p; // [rsp+50h] [rbp-98h]
  int v112; // [rsp+58h] [rbp-90h]
  hkArrayBase<hkVector4f> vertices; // [rsp+60h] [rbp-88h]
  int v114; // [rsp+70h] [rbp-78h]
  int v115; // [rsp+74h] [rbp-74h]
  void *v116; // [rsp+78h] [rbp-70h]
  int v117; // [rsp+80h] [rbp-68h]
  hkArrayBase<int> indexRemap; // [rsp+88h] [rbp-60h]
  void *v119; // [rsp+98h] [rbp-50h]
  int v120; // [rsp+A0h] [rbp-48h]
  hkSimdFloat32 regionExpansion; // [rsp+A8h] [rbp-40h]
  hkVector4f up; // [rsp+B8h] [rbp-30h]
  hkaiAbstractFaceCutter v123; // [rsp+C8h] [rbp-20h]
  hkaiSilhouetteGenerationParameters generationParams; // [rsp+F8h] [rbp+10h]
  hkAabb aabbInOut; // [rsp+138h] [rbp+50h]
  hkSimdFloat32 extrusion; // [rsp+158h] [rbp+70h]
  hkAabb genAabb; // [rsp+168h] [rbp+80h]
  hkQTransformf v128; // [rsp+188h] [rbp+A0h]
  hkJobQueue *v129; // [rsp+208h] [rbp+120h]
  int silSize; // [rsp+210h] [rbp+128h]
  signed __int64 retaddr; // [rsp+218h] [rbp+130h]
  signed __int64 v132; // [rsp+220h] [rbp+138h]

  v2 = jobQueue;
  v3 = nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = v4[1];
  if ( v5 < v4[3] )
  {
    *(_QWORD *)v5 = "LtCutFaceJob";
    *(_QWORD *)(v5 + 16) = "Stinit";
    v6 = __rdtsc();
    *(_DWORD *)(v5 + 8) = v6;
    v4[1] = v5 + 24;
  }
  index = *(_DWORD *)&v3->m_data[24] & 0x3FFFFF;
  hkaiAbstractFaceCutter::hkaiAbstractFaceCutter(&v123, v3->m_data[73] != 0);
  v8 = *(_QWORD *)&v3->m_data[88];
  v9 = *(hkaiNavMeshInstance **)&v3->m_data[16];
  *(_OWORD *)&generationParams.m_extraExpansion = *(_OWORD *)v8;
  generationParams.m_referenceFrame.m_up = *(hkVector4f *)(v8 + 16);
  generationParams.m_referenceFrame.m_referenceAxis = *(hkVector4f *)(v8 + 32);
  generationParams.m_referenceFrame.m_orthogonalAxis = *(hkVector4f *)(v8 + 48);
  v10 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__6(
          v9->m_originalFaces,
          v9->m_numOriginalFaces,
          &v9->m_instancedFaces,
          &v9->m_ownedFaces,
          &v9->m_faceMap,
          index)->m_numEdges;
  *(_QWORD *)&vertices.m_size = 0i64;
  v114 = 0;
  v11 = v10 + 1;
  v115 = 2147483648;
  v117 = v10 + 1;
  if ( v10 == -1 )
  {
    v14 = 0i64;
  }
  else
  {
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = v12;
    v14 = (char *)v12->m_cur;
    v15 = (16 * v11 + 127) & 0xFFFFFF80;
    v16 = &v14[v15];
    if ( v15 > v13->m_slabSize || v16 > v13->m_end )
      v14 = (char *)hkLifoAllocator::allocateFromNewSlab(v13, v15);
    else
      v13->m_cur = v16;
  }
  *(_QWORD *)&vertices.m_size = v14;
  v116 = v14;
  indexRemap.m_data = 0i64;
  indexRemap.m_size = 0;
  indexRemap.m_capacityAndFlags = 2147483648;
  v115 = v11 | 0x80000000;
  v120 = v10;
  if ( v10 )
  {
    v17 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v18 = (hkLifoAllocator *)v17;
    v19 = (int *)*((_QWORD *)v17 + 3);
    v20 = (4 * v10 + 127) & 0xFFFFFF80;
    v21 = (char *)v19 + v20;
    if ( v20 > v18->m_slabSize || v21 > v18->m_end )
      v19 = (int *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
    else
      v18->m_cur = v21;
  }
  else
  {
    v19 = 0i64;
  }
  v22 = *(__m128i *)&v3->m_data[48];
  indexRemap.m_capacityAndFlags = v10 | 0x80000000;
  v23 = *(signed int *)&v3->m_data[40];
  indexRemap.m_data = v19;
  _mm_store_si128((__m128i *)&up, v22);
  v119 = v19;
  if ( (signed int)v23 <= 0 )
  {
    hkaiAbstractFaceCutter::reset(&v123, *(_DWORD *)&v3->m_data[24]);
  }
  else
  {
    v24 = v3->m_data[72] == 0;
    regionExpansion.m_real = _mm_shuffle_ps(
                               (__m128)LODWORD(generationParams.m_maxSilhouetteSize),
                               (__m128)LODWORD(generationParams.m_maxSilhouetteSize),
                               0);
    hkaiAbstractFaceCutter::setFace(
      &v123,
      v9,
      (hkVector4f *)&v3->m_data[48],
      !v24,
      *(_DWORD *)&v3->m_data[24],
      &regionExpansion,
      (hkArrayBase<hkVector4f> *)((char *)&vertices + 8),
      &indexRemap);
    v25 = hkaiAbstractFaceCutter::getUp(&v123)->m_quad;
    up.m_quad = v25;
    if ( _mm_movemask_ps(_mm_cmpeqps(generationParams.m_referenceFrame.m_up.m_quad, v25)) != 15 )
    {
      v26 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, (__m128)0i64), 196);
      v27 = _mm_shuffle_ps(v26, v26, 241);
      v28 = _mm_shuffle_ps(v26, v26, 206);
      v29 = _mm_mul_ps(v28, v28);
      v30 = _mm_mul_ps(v27, v27);
      v31 = _mm_cmpltps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                _mm_shuffle_ps(v30, v30, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                _mm_shuffle_ps(v29, v29, 170)));
      regionExpansion.m_real = _mm_xor_ps(
                                 _mm_or_ps(_mm_and_ps(v31, v28), _mm_andnot_ps(v31, v27)),
                                 (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
      hkaiSilhouetteReferenceFrame::set(&generationParams.m_referenceFrame, &up, (hkVector4f *)&regionExpansion);
    }
  }
  v32 = 0;
  v33 = 0i64;
  retaddr = 0i64;
  v132 = v23;
  if ( (signed int)v23 > 0 )
  {
    do
    {
      vertices.m_data = 0i64;
      vertices.m_size = 0;
      vertices.m_capacityAndFlags = 2147483648;
      LODWORD(v116) = 2048;
      v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v35 = (hkVector4f *)v34->m_cur;
      v36 = (unsigned __int64)&v35[2048];
      if ( v34->m_slabSize < 0x8000 || (void *)v36 > v34->m_end )
        v35 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v34, 0x8000);
      else
        v34->m_cur = (void *)v36;
      vertices.m_data = v35;
      *(_QWORD *)&v114 = v35;
      vertices.m_capacityAndFlags = -2147481600;
      v110.m_data = 0i64;
      v110.m_size = 0;
      v110.m_capacityAndFlags = 2147483648;
      v112 = 16;
      v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (int *)v37->m_cur;
      v39 = (unsigned __int64)(v38 + 32);
      if ( v37->m_slabSize < 128 || (void *)v39 > v37->m_end )
        v38 = (int *)hkLifoAllocator::allocateFromNewSlab(v37, 128);
      else
        v37->m_cur = (void *)v39;
      v40 = *(_QWORD *)&v3->m_data[32];
      v110.m_data = v38;
      p = v38;
      v110.m_capacityAndFlags = -2147483632;
      v41 = *(__m128i **)(v40 + 8 * v33);
      v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v43 = (_QWORD *)v42[1];
      if ( (unsigned __int64)v43 < v42[3] )
      {
        *v43 = "StgatherSilhouettes";
        v44 = __rdtsc();
        v45 = (signed __int64)(v43 + 2);
        *(_DWORD *)(v45 - 8) = v44;
        v42[1] = v45;
      }
      if ( v41[2].m128i_i8[13] )
      {
        v56 = (hkaiSilhouetteGenerator *)v41[2].m128i_i64[0];
        _mm_store_si128((__m128i *)&v128, *v41);
        _mm_store_si128((__m128i *)&v128.m_translation, v41[1]);
        g_getAabbFunc(v56, &v128, &genAabb);
        v57.m_quad = (__m128)genAabb.m_max;
        aabbInOut = genAabb;
        v57.m_quad.m128_f32[0] = *(float *)&v3->m_data[68] + v56->m_lazyRecomputeDisplacementThreshold;
        v58 = _mm_shuffle_ps((__m128)*(unsigned int *)&v3->m_data[64], (__m128)*(unsigned int *)&v3->m_data[64], 0);
        regionExpansion.m_real = _mm_shuffle_ps(v57.m_quad, v57.m_quad, 0);
        extrusion.m_real = v58;
        hkaiSilhouetteGenerator::expandAabb(&aabbInOut, &up, &extrusion, &regionExpansion, 3u);
        if ( (unsigned int)hkaiNavMeshUtils::faceAabbCheck(
                             &aabbInOut,
                             (hkArrayBase<hkVector4f> *)((char *)&vertices + 8)) )
        {
          g_generateSilhouettesFunc(v56, &v128, &generationParams, &vertices, &v110);
          v69 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
          v70 = (_QWORD *)v69[1];
          if ( (unsigned __int64)v70 < v69[3] )
          {
            *v70 = "StaddToCutter";
            v71 = __rdtsc();
            v72 = (signed __int64)(v70 + 2);
            *(_DWORD *)(v72 - 8) = v71;
            v69[1] = v72;
          }
          v73 = v110.m_size;
          v74 = 0;
          v75 = 0i64;
          v76 = v110.m_size;
          if ( v110.m_size > 0 )
          {
            do
            {
              v77 = v110.m_data[v75];
              silSize = v77;
              if ( !v77 )
              {
                convertAabbToSilhouette(
                  &genAabb,
                  &generationParams,
                  &vertices,
                  v56->m_lazyRecomputeDisplacementThreshold,
                  &silSize);
                v77 = silSize;
                v75 = v76;
              }
              if ( v32 < *(_DWORD *)&v3->m_data[44] )
                v78 = -1;
              else
                v78 = v56->m_materialId;
              hkaiAbstractFaceCutter::addSilhouette(&v123, &vertices.m_data[v74], v77, v78);
              ++v75;
              v74 += v77;
            }
            while ( v75 < v76 );
            v73 = v110.m_size;
          }
          v79 = (char *)p;
          if ( p == v110.m_data )
            v73 = 0;
          v110.m_size = v73;
          v80 = (4 * v112 + 127) & 0xFFFFFF80;
          v81 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v82 = (v80 + 15) & 0xFFFFFFF0;
          if ( v80 > v81->m_slabSize || &v79[v82] != v81->m_cur || v81->m_firstNonLifoEnd == v79 )
            hkLifoAllocator::slowBlockFree(v81, v79, v82);
          else
            v81->m_cur = v79;
          v110.m_size = 0;
          if ( v110.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v110.m_data,
              4 * v110.m_capacityAndFlags);
          v83 = vertices.m_size;
          v84 = *(char **)&v114;
          v110.m_data = 0i64;
          if ( *(hkVector4f **)&v114 == vertices.m_data )
            v83 = 0;
          v110.m_capacityAndFlags = 2147483648;
          vertices.m_size = v83;
          v85 = (16 * (_DWORD)v116 + 127) & 0xFFFFFF80;
          v86 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v87 = (v85 + 15) & 0xFFFFFFF0;
          if ( v85 > v86->m_slabSize || &v84[v87] != v86->m_cur || v86->m_firstNonLifoEnd == v84 )
            hkLifoAllocator::slowBlockFree(v86, v84, v87);
          else
            v86->m_cur = v84;
          vertices.m_size = 0;
          if ( vertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              vertices.m_data,
              16 * vertices.m_capacityAndFlags);
        }
        else
        {
          v59 = v110.m_size;
          v60 = (char *)p;
          if ( p == v110.m_data )
            v59 = 0;
          v110.m_size = v59;
          v61 = (4 * v112 + 127) & 0xFFFFFF80;
          v62 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v63 = (v61 + 15) & 0xFFFFFFF0;
          if ( v61 > v62->m_slabSize || &v60[v63] != v62->m_cur || v62->m_firstNonLifoEnd == v60 )
            hkLifoAllocator::slowBlockFree(v62, v60, v63);
          else
            v62->m_cur = v60;
          v110.m_size = 0;
          if ( v110.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v110.m_data,
              4 * v110.m_capacityAndFlags);
          v64 = vertices.m_size;
          v65 = *(char **)&v114;
          v110.m_data = 0i64;
          if ( *(hkVector4f **)&v114 == vertices.m_data )
            v64 = 0;
          v110.m_capacityAndFlags = 2147483648;
          vertices.m_size = v64;
          v66 = (16 * (_DWORD)v116 + 127) & 0xFFFFFF80;
          v67 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v68 = (v66 + 15) & 0xFFFFFFF0;
          if ( v66 > v67->m_slabSize || &v65[v68] != v67->m_cur || v67->m_firstNonLifoEnd == v65 )
            hkLifoAllocator::slowBlockFree(v67, v65, v68);
          else
            v67->m_cur = v65;
          vertices.m_size = 0;
          if ( vertices.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              vertices.m_data,
              16 * vertices.m_capacityAndFlags);
        }
      }
      else
      {
        v46 = v110.m_size;
        v47 = (char *)p;
        if ( p == v110.m_data )
          v46 = 0;
        v110.m_size = v46;
        v48 = (4 * v112 + 127) & 0xFFFFFF80;
        v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v50 = (v48 + 15) & 0xFFFFFFF0;
        if ( v48 > v49->m_slabSize || &v47[v50] != v49->m_cur || v49->m_firstNonLifoEnd == v47 )
          hkLifoAllocator::slowBlockFree(v49, v47, v50);
        else
          v49->m_cur = v47;
        v110.m_size = 0;
        if ( v110.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v110.m_data,
            4 * v110.m_capacityAndFlags);
        v51 = vertices.m_size;
        v52 = *(char **)&v114;
        v110.m_data = 0i64;
        if ( *(hkVector4f **)&v114 == vertices.m_data )
          v51 = 0;
        v110.m_capacityAndFlags = 2147483648;
        vertices.m_size = v51;
        v53 = (16 * (_DWORD)v116 + 127) & 0xFFFFFF80;
        v54 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v55 = (v53 + 15) & 0xFFFFFFF0;
        if ( v53 > v54->m_slabSize || &v52[v55] != v54->m_cur || v54->m_firstNonLifoEnd == v52 )
          hkLifoAllocator::slowBlockFree(v54, v52, v55);
        else
          v54->m_cur = v52;
        vertices.m_size = 0;
        if ( vertices.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            vertices.m_data,
            16 * vertices.m_capacityAndFlags);
      }
      ++v32;
      v33 = retaddr + 1;
      retaddr = v33;
    }
    while ( v33 < v132 );
    v2 = v129;
  }
  v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v89 = (_QWORD *)v88[1];
  v90 = v88;
  if ( (unsigned __int64)v89 < v88[3] )
  {
    *v89 = "Stconvexify";
    v91 = __rdtsc();
    v92 = (signed __int64)(v89 + 2);
    *(_DWORD *)(v92 - 8) = v91;
    v90[1] = v92;
  }
  hkaiAbstractFaceCutter::computeConvexDecomposition(
    &v123,
    *(hkaiFaceCutResults **)&v3->m_data[80],
    (hkArrayBase<hkVector4f> *)((char *)&vertices + 8),
    &indexRemap);
  v93 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v94 = (_QWORD *)v93[1];
  if ( (unsigned __int64)v94 < v93[3] )
  {
    *v94 = "lt";
    v95 = __rdtsc();
    v96 = (signed __int64)(v94 + 2);
    *(_DWORD *)(v96 - 8) = v95;
    v93[1] = v96;
  }
  v97 = hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
  v98 = indexRemap.m_size;
  v99 = (char *)v119;
  v100 = v97;
  if ( v119 == indexRemap.m_data )
    v98 = 0;
  indexRemap.m_size = v98;
  v101 = (4 * v120 + 127) & 0xFFFFFF80;
  v102 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v103 = (v101 + 15) & 0xFFFFFFF0;
  if ( v101 > v102->m_slabSize || &v99[v103] != v102->m_cur || v102->m_firstNonLifoEnd == v99 )
    hkLifoAllocator::slowBlockFree(v102, v99, v103);
  else
    v102->m_cur = v99;
  indexRemap.m_size = 0;
  if ( indexRemap.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      indexRemap.m_data,
      4 * indexRemap.m_capacityAndFlags);
  v104 = v114;
  v105 = (char *)v116;
  indexRemap.m_data = 0i64;
  if ( v116 == *(void **)&vertices.m_size )
    v104 = 0;
  indexRemap.m_capacityAndFlags = 2147483648;
  v114 = v104;
  v106 = (16 * v117 + 127) & 0xFFFFFF80;
  v107 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v108 = (v106 + 15) & 0xFFFFFFF0;
  if ( v106 > v107->m_slabSize || &v105[v108] != v107->m_cur || v107->m_firstNonLifoEnd == v105 )
    hkLifoAllocator::slowBlockFree(v107, v105, v108);
  else
    v107->m_cur = v105;
  v114 = 0;
  if ( v115 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)&vertices.m_size,
      16 * v115);
  *(_QWORD *)&vertices.m_size = 0i64;
  v115 = 2147483648;
  hkaiAbstractFaceCutter::~hkaiAbstractFaceCutter(&v123);
  return v100;
}

