// File Line: 30
// RVA: 0x12F1610
void __fastcall hkaiNewFaceCutter::hkaiNewFaceCutter(hkaiNewFaceCutter *this)
{
  hkaiNewFaceCutterUtil::State::State(&this->m_state);
  hkaiNewFaceCutterUtil::State::reset(&this->m_state);
  this->m_silhouettesAdded = 0;
}

// File Line: 43
// RVA: 0x12F1640
void __fastcall hkaiNewFaceCutter::setFace(
        hkaiNewFaceCutter *this,
        hkaiNavMeshUtils *origMesh,
        hkVector4f *up,
        bool isWallClimbing,
        unsigned int faceKey,
        hkSimdFloat32 *regionExpansion,
        hkArrayBase<hkVector4f> *faceVertsOut)
{
  int v11; // ebx
  hkArrayBase<hkVector4f> *v12; // r9
  hkArray<int,hkContainerHeapAllocator> *instanceMap; // r11
  int v14; // ecx
  int m_numEdges; // eax
  hkaiNavMesh::Face v16; // [rsp+40h] [rbp-28h] BYREF
  hkVector4f planeOut; // [rsp+50h] [rbp-18h] BYREF

  hkaiNewFaceCutter::reset(this, faceKey);
  this->m_state.m_up = (hkVector4f)up->m_quad;
  v11 = *(_DWORD *)&origMesh[24];
  v16 = *hkaiNavMeshInstance_get_hkaiNavMesh::Face__23(
           *(hkaiNavMesh::Face **)&origMesh[16],
           v11,
           (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&origMesh[240],
           (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&origMesh[272],
           (hkArray<int,hkContainerHeapAllocator> *)&origMesh[224],
           faceKey & 0x3FFFFF);
  if ( *(_DWORD *)&origMesh[72] )
    v14 = *hkaiNavMeshInstance_getWithStriding_int__5(
             *(const int **)&origMesh[64],
             v11,
             (hkArray<int,hkContainerHeapAllocator> *)&origMesh[352],
             (hkArray<int,hkContainerHeapAllocator> *)&origMesh[384],
             instanceMap,
             faceKey & 0x3FFFFF,
             *(_DWORD *)&origMesh[72]);
  else
    v14 = 0;
  m_numEdges = v16.m_numEdges;
  this->m_state.m_faceMaterial = v14;
  faceVertsOut->m_size = m_numEdges + 1;
  hkaiNavMeshUtils::getFaceLocalVertices<hkaiNavMeshInstance>(
    origMesh,
    (hkaiNavMeshInstance *)&v16,
    (hkaiNavMesh::Face *)faceVertsOut,
    v12);
  hkaiNavMeshUtils::calcFacePlane(faceVertsOut, &planeOut);
  if ( isWallClimbing )
    this->m_state.m_up = (hkVector4f)planeOut.m_quad;
  --faceVertsOut->m_size;
  hkaiNewFaceCutterUtil::setupDomain(&this->m_state, &planeOut, faceVertsOut);
  hkaiNewFaceCutterUtil::createFacePolygon(&this->m_state, faceVertsOut);
}

// File Line: 73
// RVA: 0x12F1780
__int64 __fastcall hkaiNewFaceCutter::addSilhouette(
        hkaiNewFaceCutter *this,
        hkVector4f *points,
        int loopSize,
        int materialId)
{
  int v6; // r8d
  char m_size; // r8
  __int64 v8; // rcx
  hkArrayBase<hkVector4f> vertices; // [rsp+20h] [rbp-18h] BYREF

  this->m_silhouettesAdded = 1;
  if ( materialId == -1 )
  {
    v6 = 0x10000;
  }
  else
  {
    m_size = this->m_state.m_painterMaterials.m_size;
    v8 = this->m_state.m_painterMaterials.m_size;
    this->m_state.m_painterMaterials.m_size = v8 + 1;
    this->m_state.m_painterMaterials.m_data[v8] = materialId;
    v6 = 1 << (m_size + 1);
  }
  vertices.m_size = loopSize;
  vertices.m_data = points;
  vertices.m_capacityAndFlags = loopSize | 0x80000000;
  hkaiNewFaceCutterUtil::createNonFacePolygon(&this->m_state, &vertices, (hkaiNewFaceCutterUtil::Difference)v6);
  return 1i64;
}

// File Line: 103
// RVA: 0x12F1810
__int64 __fastcall hkaiNewFaceCutter::computeConvexDecomposition(
        hkaiNewFaceCutter *this,
        hkaiFaceCutResults *results,
        hkArrayBase<hkVector4f> *faceVertices,
        hkArrayBase<int> *indexRemap)
{
  int m_size; // r9d
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  int v12; // eax
  int v13; // eax
  int v14; // ebp
  unsigned int *v15; // rax
  int v16; // edi
  hkLifoAllocator *Value; // rcx
  unsigned int *m_cur; // rax
  int v19; // edx
  char *v20; // r8
  int i; // edi
  int v22; // edi
  hkaiNewFaceCutterUtil::Vec2 *m_data; // r9
  __m128i si128; // xmm9
  int v25; // r8d
  int v26; // edx
  hkVector4f v27; // xmm6
  hkVector4f v28; // xmm7
  hkVector4f v29; // xmm8
  unsigned __int64 v30; // rcx
  char *v31; // rdx
  __int64 v32; // rcx
  __int64 v33; // rax
  __m128i v34; // xmm2
  __m128i v35; // xmm0
  __m128 v36; // xmm5
  __m128i v37; // xmm0
  __m128 v38; // xmm4
  int v39; // eax
  char *v40; // rdi
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // r8d
  hkArrayBase<unsigned int> regionEdgeIndices; // [rsp+30h] [rbp-88h] BYREF
  void *p; // [rsp+40h] [rbp-78h]
  int v46; // [rsp+48h] [rbp-70h]
  hkResult result; // [rsp+C0h] [rbp+8h] BYREF
  unsigned int *output; // [rsp+C8h] [rbp+10h] BYREF

  if ( !HK_flyingcolors_ai_3.m_bool )
  {
    hkaiCheckKeycode();
    hkaiProcessFlyingColors(&HK_flyingcolors_ai_3);
    if ( !HK_flyingcolors_ai_3.m_bool )
      this->m_silhouettesAdded = 0;
  }
  results->m_originalFace = this->m_faceKey;
  if ( this->m_silhouettesAdded )
  {
    hkaiNewFaceCutterUtil::EventQueue::heapifyAll(&this->m_state.m_eventQueue);
    m_size = this->m_state.m_segments.m_size;
    v9 = this->m_state.m_incomingSegments.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < m_size )
    {
      v10 = 2 * v9;
      if ( m_size < v10 )
        m_size = v10;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_state.m_incomingSegments.m_data,
        m_size,
        2);
    }
    v11 = this->m_state.m_segments.m_size;
    v12 = this->m_state.m_outgoingSegments.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v12 < v11 )
    {
      v13 = 2 * v12;
      if ( v11 < v13 )
        v11 = v13;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_state.m_outgoingSegments.m_data,
        v11,
        2);
    }
    while ( this->m_state.m_eventQueue.m_heap.m_size != 1 )
      hkaiNewFaceCutterUtil::step(&this->m_state);
    hkaiNewFaceCutterUtil::clipDegenerateEars(&this->m_state);
    hkaiNewFaceCutterUtil::checkRegions(&this->m_state);
    v14 = this->m_state.m_regions.m_size;
    v15 = (unsigned int *)hkaiFaceCutResults::init(results, v14, this->m_state.m_regionEdges.m_size);
    v16 = this->m_state.m_regionEdges.m_size;
    regionEdgeIndices.m_data = 0i64;
    regionEdgeIndices.m_size = 0;
    regionEdgeIndices.m_capacityAndFlags = 0x80000000;
    output = v15;
    v46 = v16;
    if ( v16 )
    {
      Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (unsigned int *)Value->m_cur;
      v19 = (4 * v16 + 127) & 0xFFFFFF80;
      v20 = (char *)m_cur + v19;
      if ( v19 > Value->m_slabSize || v20 > Value->m_end )
        m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(Value, v19);
      else
        Value->m_cur = v20;
    }
    else
    {
      m_cur = 0i64;
    }
    regionEdgeIndices.m_data = m_cur;
    p = m_cur;
    regionEdgeIndices.m_capacityAndFlags = v16 | 0x80000000;
    hkaiNewFaceCutterUtil::translateRegionEdgeIndices(&this->m_state, &regionEdgeIndices);
    for ( i = 0; i < v14; ++i )
      hkaiNewFaceCutterUtil::outputRegion(
        &this->m_state,
        &this->m_state.m_regions.m_data[(__int16)i],
        &regionEdgeIndices,
        results,
        &output);
    v22 = this->m_state.m_outputVertices.m_size;
    m_data = this->m_state.m_outputVertices.m_data;
    si128 = _mm_load_si128((const __m128i *)&_xmm);
    v25 = 0;
    v26 = (v22 + 3) & 0xFFFFFFFC;
    this->m_state.m_outputVertices.m_size = v26;
    v27.m_quad = (__m128)this->m_state.m_internalToExternal.m_col0;
    v28.m_quad = (__m128)this->m_state.m_internalToExternal.m_col1;
    v29.m_quad = (__m128)this->m_state.m_internalToExternal.m_col3;
    if ( v22 + 3 >= 0 && v26 != 0 )
    {
      v30 = v26 - 1i64;
      v31 = &results->m_data[((11 * results->m_numPolys + 9 * results->m_numEdges + 15i64) & 0xFFFFFFFFFFFFFFF0ui64)
                           + 32];
      v32 = (v30 >> 2) + 1;
      do
      {
        v33 = v25;
        v31 += 64;
        v25 += 4;
        v34 = _mm_load_si128((const __m128i *)&m_data[v33]);
        v35 = _mm_srli_epi32(v34, 0x10u);
        v36 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v35, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v35, 0x10u), 0x10u)));
        v37 = _mm_and_si128(v34, si128);
        v38 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v37, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v37, 0x10u), 0x10u)));
        *((__m128 *)v31 - 6) = _mm_add_ps(
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), v27.m_quad), v29.m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v28.m_quad));
        *((__m128 *)v31 - 5) = _mm_add_ps(
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), v27.m_quad), v29.m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), v28.m_quad));
        *((__m128 *)v31 - 4) = _mm_add_ps(
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 170), v27.m_quad), v29.m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v28.m_quad));
        *((__m128 *)v31 - 3) = _mm_add_ps(
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v36, v36, 255), v27.m_quad), v29.m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(v38, v38, 255), v28.m_quad));
        --v32;
      }
      while ( v32 );
    }
    hkaiNewFaceCutterUtil::fitToPlanes(
      faceVertices,
      &this->m_state.m_up,
      (hkVector4f *)&results->m_data[(9 * results->m_numEdges + 11 * results->m_numPolys + 15i64) & 0xFFFFFFFFFFFFFFF0ui64],
      v22);
    v39 = regionEdgeIndices.m_size;
    results->m_numVertices = v22;
    v40 = (char *)p;
    if ( p == regionEdgeIndices.m_data )
      v39 = 0;
    regionEdgeIndices.m_size = v39;
    v41 = (4 * v46 + 127) & 0xFFFFFF80;
    v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v43 = (v41 + 15) & 0xFFFFFFF0;
    if ( v41 > v42->m_slabSize || &v40[v43] != v42->m_cur || v42->m_firstNonLifoEnd == v40 )
      hkLifoAllocator::slowBlockFree(v42, v40, v43);
    else
      v42->m_cur = v40;
    regionEdgeIndices.m_size = 0;
    if ( regionEdgeIndices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        regionEdgeIndices.m_data,
        4 * regionEdgeIndices.m_capacityAndFlags);
    return 1i64;
  }
  else
  {
    results->m_flags.m_storage |= 1u;
    return 1i64;
  }
}

// File Line: 197
// RVA: 0x12F1CB0
void __fastcall hkaiNewFaceCutter::reset(hkaiNewFaceCutter *this, unsigned int faceKey)
{
  hkaiNewFaceCutterUtil::State::reset(&this->m_state);
  this->m_faceKey = faceKey;
  this->m_silhouettesAdded = 0;
}

