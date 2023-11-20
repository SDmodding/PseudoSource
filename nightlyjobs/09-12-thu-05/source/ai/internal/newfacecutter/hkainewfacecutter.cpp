// File Line: 30
// RVA: 0x12F1610
void __fastcall hkaiNewFaceCutter::hkaiNewFaceCutter(hkaiNewFaceCutter *this)
{
  hkaiNewFaceCutter *v1; // rbx

  v1 = this;
  hkaiNewFaceCutterUtil::State::State(&this->m_state);
  hkaiNewFaceCutterUtil::State::reset(&v1->m_state);
  v1->m_silhouettesAdded = 0;
}

// File Line: 43
// RVA: 0x12F1640
void __fastcall hkaiNewFaceCutter::setFace(hkaiNewFaceCutter *this, hkaiNavMeshInstance *origMesh, hkVector4f *up, bool isWallClimbing, unsigned int faceKey, hkSimdFloat32 *regionExpansion, hkArrayBase<hkVector4f> *faceVertsOut)
{
  hkaiNavMeshInstance *v7; // rsi
  bool v8; // r14
  hkVector4f *v9; // rbx
  hkaiNewFaceCutter *v10; // rdi
  int v11; // ebx
  int *v12; // rax
  hkArrayBase<hkVector4f> *v13; // r9
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // r11
  int v15; // ecx
  int v16; // eax
  int v17; // [rsp+40h] [rbp-28h]
  int v18; // [rsp+44h] [rbp-24h]
  int v19; // [rsp+48h] [rbp-20h]
  int v20; // [rsp+4Ch] [rbp-1Ch]
  hkVector4f planeOut; // [rsp+50h] [rbp-18h]

  v7 = origMesh;
  v8 = isWallClimbing;
  v9 = up;
  v10 = this;
  hkaiNewFaceCutter::reset(this, faceKey);
  v10->m_state.m_up = (hkVector4f)v9->m_quad;
  v11 = v7->m_numOriginalFaces;
  v12 = (int *)hkaiNavMeshInstance_get_hkaiNavMesh::Face__23(
                 v7->m_originalFaces,
                 v7->m_numOriginalFaces,
                 &v7->m_instancedFaces,
                 &v7->m_ownedFaces,
                 &v7->m_faceMap,
                 faceKey & 0x3FFFFF);
  v17 = *v12;
  v18 = v12[1];
  v19 = v12[2];
  v20 = v12[3];
  if ( v7->m_faceDataStriding )
    v15 = *hkaiNavMeshInstance_getWithStriding_int__5(
             v7->m_originalFaceData,
             v11,
             &v7->m_instancedFaceData,
             &v7->m_ownedFaceData,
             instanceMap,
             faceKey & 0x3FFFFF,
             v7->m_faceDataStriding);
  else
    v15 = 0;
  v16 = (signed __int16)v19;
  v10->m_state.m_faceMaterial = v15;
  faceVertsOut->m_size = v16 + 1;
  hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)v7,
    (hkaiNavMeshInstance *)&v17,
    (hkaiNavMesh::Face *)faceVertsOut,
    v13);
  hkaiNavMeshUtils::calcFacePlane(faceVertsOut, &planeOut);
  if ( v8 )
    v10->m_state.m_up = (hkVector4f)planeOut.m_quad;
  --faceVertsOut->m_size;
  hkaiNewFaceCutterUtil::setupDomain(&v10->m_state, &planeOut, faceVertsOut);
  hkaiNewFaceCutterUtil::createFacePolygon(&v10->m_state, faceVertsOut);
}

// File Line: 73
// RVA: 0x12F1780
signed __int64 __fastcall hkaiNewFaceCutter::addSilhouette(hkaiNewFaceCutter *this, hkVector4f *points, int loopSize, int materialId)
{
  int v4; // er10
  hkaiNewFaceCutter *v5; // r11
  signed int v6; // er8
  char v7; // r8
  __int64 v8; // rcx
  hkArrayBase<hkVector4f> vertices; // [rsp+20h] [rbp-18h]

  v4 = loopSize;
  v5 = this;
  this->m_silhouettesAdded = 1;
  if ( materialId == -1 )
  {
    v6 = 0x10000;
  }
  else
  {
    v7 = this->m_state.m_painterMaterials.m_size;
    v8 = this->m_state.m_painterMaterials.m_size;
    v5->m_state.m_painterMaterials.m_size = v8 + 1;
    v5->m_state.m_painterMaterials.m_data[v8] = materialId;
    v6 = 1 << (v7 + 1);
  }
  vertices.m_size = v4;
  vertices.m_data = points;
  vertices.m_capacityAndFlags = v4 | 0x80000000;
  hkaiNewFaceCutterUtil::createNonFacePolygon(&v5->m_state, &vertices, (hkaiNewFaceCutterUtil::Difference)v6);
  return 1i64;
}

// File Line: 103
// RVA: 0x12F1810
signed __int64 __fastcall hkaiNewFaceCutter::computeConvexDecomposition(hkaiNewFaceCutter *this, hkaiFaceCutResults *results, hkArrayBase<hkVector4f> *faceVertices, hkArrayBase<int> *indexRemap)
{
  hkArrayBase<hkVector4f> *v4; // r14
  hkaiFaceCutResults *v5; // rsi
  hkaiNewFaceCutter *v6; // rbx
  signed __int64 v7; // rax
  int v8; // er9
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // eax
  int v13; // eax
  int v14; // ebp
  unsigned int *v15; // rax
  int v16; // edi
  LPVOID v17; // rax
  hkLifoAllocator *v18; // rcx
  unsigned int *v19; // rax
  int v20; // edx
  char *v21; // r8
  int i; // edi
  int v23; // edi
  hkaiNewFaceCutterUtil::Vec2 *v24; // r9
  __m128i v25; // xmm9
  int v26; // er8
  signed int v27; // edx
  __m128 v28; // xmm6
  __m128 v29; // xmm7
  __m128 v30; // xmm8
  unsigned __int64 v31; // rcx
  unsigned __int64 v32; // rdx
  signed __int64 v33; // rcx
  __int64 v34; // rax
  __m128i v35; // xmm3
  __m128i v36; // xmm2
  __m128i v37; // xmm3
  __m128i v38; // xmm2
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  int v41; // eax
  char *v42; // rdi
  signed int v43; // ebx
  hkLifoAllocator *v44; // rax
  int v45; // er8
  hkArrayBase<unsigned int> regionEdgeIndices; // [rsp+30h] [rbp-88h]
  void *p; // [rsp+40h] [rbp-78h]
  int v48; // [rsp+48h] [rbp-70h]
  hkResult result; // [rsp+C0h] [rbp+8h]
  unsigned int *output; // [rsp+C8h] [rbp+10h]

  v4 = faceVertices;
  v5 = results;
  v6 = this;
  if ( !HK_flyingcolors_ai_3.m_bool )
  {
    hkaiCheckKeycode();
    hkaiProcessFlyingColors(&HK_flyingcolors_ai_3);
    if ( !HK_flyingcolors_ai_3.m_bool )
      v6->m_silhouettesAdded = 0;
  }
  v5->m_originalFace = v6->m_faceKey;
  if ( v6->m_silhouettesAdded )
  {
    hkaiNewFaceCutterUtil::EventQueue::heapifyAll(&v6->m_state.m_eventQueue);
    v8 = v6->m_state.m_segments.m_size;
    v9 = v6->m_state.m_incomingSegments.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < v8 )
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_state.m_incomingSegments,
        v8,
        2);
    }
    v11 = v6->m_state.m_segments.m_size;
    v12 = v6->m_state.m_outgoingSegments.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v12 < v11 )
    {
      v13 = 2 * v12;
      if ( v11 < v13 )
        v11 = v13;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_state.m_outgoingSegments,
        v11,
        2);
    }
    while ( v6->m_state.m_eventQueue.m_heap.m_size != 1 )
      hkaiNewFaceCutterUtil::step(&v6->m_state);
    hkaiNewFaceCutterUtil::clipDegenerateEars(&v6->m_state);
    hkaiNewFaceCutterUtil::checkRegions(&v6->m_state);
    v14 = v6->m_state.m_regions.m_size;
    v15 = (unsigned int *)hkaiFaceCutResults::init(v5, v6->m_state.m_regions.m_size, v6->m_state.m_regionEdges.m_size);
    v16 = v6->m_state.m_regionEdges.m_size;
    regionEdgeIndices.m_data = 0i64;
    regionEdgeIndices.m_size = 0;
    regionEdgeIndices.m_capacityAndFlags = 2147483648;
    output = v15;
    v48 = v16;
    if ( v16 )
    {
      v17 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (hkLifoAllocator *)v17;
      v19 = (unsigned int *)*((_QWORD *)v17 + 3);
      v20 = (4 * v16 + 127) & 0xFFFFFF80;
      v21 = (char *)v19 + v20;
      if ( v20 > v18->m_slabSize || v21 > v18->m_end )
        v19 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v18, v20);
      else
        v18->m_cur = v21;
    }
    else
    {
      v19 = 0i64;
    }
    regionEdgeIndices.m_data = v19;
    p = v19;
    regionEdgeIndices.m_capacityAndFlags = v16 | 0x80000000;
    hkaiNewFaceCutterUtil::translateRegionEdgeIndices(&v6->m_state, &regionEdgeIndices);
    for ( i = 0; i < v14; ++i )
      hkaiNewFaceCutterUtil::outputRegion(
        &v6->m_state,
        &v6->m_state.m_regions.m_data[(signed __int16)i],
        &regionEdgeIndices,
        v5,
        &output);
    v23 = v6->m_state.m_outputVertices.m_size;
    v24 = v6->m_state.m_outputVertices.m_data;
    v25 = _mm_load_si128((const __m128i *)&_xmm);
    v26 = 0;
    v27 = (v23 + 3) & 0xFFFFFFFC;
    v6->m_state.m_outputVertices.m_size = v27;
    v28 = v6->m_state.m_internalToExternal.m_col0.m_quad;
    v29 = v6->m_state.m_internalToExternal.m_col1.m_quad;
    v30 = v6->m_state.m_internalToExternal.m_col3.m_quad;
    if ( v27 > 0 )
    {
      v31 = v27 - 1i64;
      v32 = (unsigned __int64)&v5->m_data[((11 * v5->m_numPolys + 9 * v5->m_numEdges + 15i64) & 0xFFFFFFFFFFFFFFF0ui64)
                                        + 32];
      v33 = (v31 >> 2) + 1;
      do
      {
        v34 = v26;
        v32 += 64i64;
        v26 += 4;
        v35 = _mm_load_si128((const __m128i *)&v24[v34]);
        v36 = v35;
        v37 = _mm_and_si128(v35, v25);
        v38 = _mm_srli_epi32(v36, 0x10u);
        v39 = _mm_add_ps(
                _mm_mul_ps(_mm_cvtepi32_ps(v38), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v38, 0x10u), 0x10u)));
        v40 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v37, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v37, 0x10u), 0x10u)));
        *(__m128 *)(v32 - 96) = _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), v28), v30),
                                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v29));
        *(__m128 *)(v32 - 80) = _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), v28), v30),
                                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v29));
        *(__m128 *)(v32 - 64) = _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), v28), v30),
                                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v29));
        *(__m128 *)(v32 - 48) = _mm_add_ps(
                                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v39, v39, 255), v28), v30),
                                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 255), v29));
        --v33;
      }
      while ( v33 );
    }
    hkaiNewFaceCutterUtil::fitToPlanes(
      v4,
      &v6->m_state.m_up,
      (hkVector4f *)&v5->m_data[(9 * v5->m_numEdges + 11 * v5->m_numPolys + 15i64) & 0xFFFFFFFFFFFFFFF0ui64],
      v23);
    v41 = regionEdgeIndices.m_size;
    v5->m_numVertices = v23;
    v42 = (char *)p;
    if ( p == regionEdgeIndices.m_data )
      v41 = 0;
    regionEdgeIndices.m_size = v41;
    v43 = (4 * v48 + 127) & 0xFFFFFF80;
    v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v45 = (v43 + 15) & 0xFFFFFFF0;
    if ( v43 > v44->m_slabSize || &v42[v45] != v44->m_cur || v44->m_firstNonLifoEnd == v42 )
      hkLifoAllocator::slowBlockFree(v44, v42, v45);
    else
      v44->m_cur = v42;
    regionEdgeIndices.m_size = 0;
    if ( regionEdgeIndices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        regionEdgeIndices.m_data,
        4 * regionEdgeIndices.m_capacityAndFlags);
    v7 = 1i64;
  }
  else
  {
    v5->m_flags.m_storage |= 1u;
    v7 = 1i64;
  }
  return v7;
}

// File Line: 197
// RVA: 0x12F1CB0
void __fastcall hkaiNewFaceCutter::reset(hkaiNewFaceCutter *this, unsigned int faceKey)
{
  unsigned int v2; // ebx
  hkaiNewFaceCutter *v3; // rdi

  v2 = faceKey;
  v3 = this;
  hkaiNewFaceCutterUtil::State::reset(&this->m_state);
  v3->m_faceKey = v2;
  v3->m_silhouettesAdded = 0;
}

