// File Line: 38
// RVA: 0x12E8800
__int64 __fastcall NavMeshInstanceCastSegmentQuery::processLeaf(
        NavMeshInstanceCastSegmentQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  hkaiIntervalPartition *p_m_curPartition; // rdi
  hkaiIntervalPartition *p_m_fullPartition; // rcx

  p_m_curPartition = &this->m_curPartition;
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFace(
         &this->m_leftStart,
         &this->m_rightStart,
         &this->m_displacement,
         this->m_navMeshInstance,
         leafKey,
         leafKey,
         &this->m_curPartition) )
  {
    p_m_fullPartition = &this->m_fullPartition;
    if ( this->m_fullPartition.m_intervals.m_size > 0 )
    {
      hkaiIntervalPartition::combine<0,0>(p_m_fullPartition, p_m_curPartition);
      hkaiIntervalPartition::clear(p_m_curPartition);
      return 1i64;
    }
    hkaiIntervalPartition::swap(
      p_m_fullPartition,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)p_m_curPartition);
  }
  return 1i64;
}

// File Line: 77
// RVA: 0x12E7110
hkaiNavMeshInstanceSegmentCaster::AccelerationData *__fastcall hkaiNavMeshInstanceSegmentCaster::buildAccelerationData(
        hkaiNavMeshUtils *navMeshInstance)
{
  _QWORD **Value; // rax
  __int64 v3; // rax
  unsigned int v4; // ebx
  __int64 v5; // rsi
  _QWORD **v6; // rax
  hkcdDynamicAabbTree *v7; // rax
  hkReferencedObject *v8; // rax
  hkReferencedObject *v9; // rdi
  hkReferencedObject *v10; // rcx
  __int64 v11; // rdi
  int v12; // eax
  __int64 v13; // r14
  char *v14; // rax
  hkAabb *aabbOut[2]; // [rsp+20h] [rbp-48h] BYREF
  hkAabb extraRadius; // [rsp+30h] [rbp-38h] BYREF
  char v18; // [rsp+70h] [rbp+8h] BYREF
  char v19; // [rsp+78h] [rbp+10h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 24i64);
  v4 = 0;
  v5 = v3;
  if ( v3 )
  {
    *(_DWORD *)(v3 + 8) = 0x1FFFF;
    *(_QWORD *)v3 = &hkaiNavMeshInstanceSegmentCaster::AccelerationData::`vftable;
    *(_QWORD *)(v3 + 16) = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v6[11] + 8i64))(v6[11], 32i64);
  if ( v7 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = *(hkReferencedObject **)(v5 + 16);
  if ( v10 && v10 != v9 )
    hkReferencedObject::removeReference(v10);
  *(_QWORD *)(v5 + 16) = v9;
  v11 = 0i64;
  v12 = *(_DWORD *)&navMeshInstance[24] + *(_DWORD *)&navMeshInstance[280];
  v13 = v12;
  if ( v12 > 0 )
  {
    do
    {
      if ( *(_DWORD *)&navMeshInstance[328] )
      {
        v14 = &v18;
        v18 = *(_BYTE *)(v11 + *(_QWORD *)&navMeshInstance[320]);
      }
      else
      {
        v19 = 0;
        v14 = &v19;
      }
      if ( (*v14 & 1) == 0 )
      {
        aabbOut[1] = 0i64;
        hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
          navMeshInstance,
          (hkaiNavMeshInstance *)v4,
          (__m128 *)aabbOut,
          (hkSimdFloat32 *)&extraRadius,
          0i64);
        hkcdDynamicAabbTree::insert(*(hkcdDynamicAabbTree **)(v5 + 16), &extraRadius, v4);
      }
      ++v11;
      ++v4;
    }
    while ( v11 < v13 );
  }
  hkcdDynamicAabbTree::rebuild(*(hkcdDynamicAabbTree **)(v5 + 16));
  return (hkaiNavMeshInstanceSegmentCaster::AccelerationData *)v5;
}

// File Line: 104
// RVA: 0x12E7250
void __fastcall hkaiNavMeshInstanceSegmentCaster::hkaiNavMeshInstanceSegmentCaster(
        hkaiNavMeshInstanceSegmentCaster *this,
        hkaiNavMeshInstance *navMeshInstance,
        hkaiNavMeshInstanceSegmentCaster::AccelerationData *accelerationData)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_navMeshInstance = navMeshInstance;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstanceSegmentCaster::`vftable;
  if ( accelerationData )
  {
    hkReferencedObject::addReference(accelerationData);
    this->m_accelerationData.m_pntr = accelerationData;
  }
  else
  {
    this->m_accelerationData.m_pntr = 0i64;
  }
}

// File Line: 109
// RVA: 0x12E72B0
void __fastcall hkaiNavMeshInstanceSegmentCaster::~hkaiNavMeshInstanceSegmentCaster(
        hkaiNavMeshInstanceSegmentCaster *this)
{
  hkaiNavMeshInstanceSegmentCaster::AccelerationData *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstanceSegmentCaster::`vftable;
  m_pntr = this->m_accelerationData.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_accelerationData.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 117
// RVA: 0x12E72F0
void __fastcall hkaiNavMeshInstanceSegmentCaster::castSegment(
        hkaiNavMeshInstanceSegmentCaster *this,
        hkVector4f *leftStart,
        hkVector4f *rightStart,
        hkVector4f *displacement,
        hkaiIntervalPartition *partition)
{
  __m128 v6; // xmm2
  __m128 m_quad; // xmm0
  __m128 v8; // xmm3
  __m128 v9; // xmm0
  hkaiNavMeshInstance *m_navMeshInstance; // rax
  __m128 v11; // xmm0
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-98h] BYREF
  __m128 v13; // [rsp+30h] [rbp-88h]
  __m128 v14; // [rsp+40h] [rbp-78h]
  __m128 v15; // [rsp+50h] [rbp-68h]
  hkaiNavMeshInstance *v16; // [rsp+60h] [rbp-58h]
  hkaiIntervalPartition v17; // [rsp+68h] [rbp-50h] BYREF
  hkaiIntervalPartition other; // [rsp+78h] [rbp-40h] BYREF
  hkAabb aabb; // [rsp+90h] [rbp-28h] BYREF

  v6 = _mm_add_ps(displacement->m_quad, leftStart->m_quad);
  m_quad = leftStart->m_quad;
  v14 = rightStart->m_quad;
  v8 = _mm_add_ps(v14, displacement->m_quad);
  aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(m_quad, v14), v6), v8);
  aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(m_quad, v14), v6), v8);
  v9 = leftStart->m_quad;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&NavMeshInstanceCastSegmentQuery::`vftable;
  m_navMeshInstance = this->m_navMeshInstance;
  v13 = v9;
  v11 = displacement->m_quad;
  v16 = m_navMeshInstance;
  v15 = v11;
  hkaiIntervalPartition::hkaiIntervalPartition(&v17);
  hkaiIntervalPartition::hkaiIntervalPartition(&other);
  hkcdDynamicAabbTree::queryAabb(this->m_accelerationData.m_pntr->m_tree.m_pntr, &aabb, &collector);
  hkaiIntervalPartition::swap(partition, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
  other.m_intervals.m_size = 0;
  if ( other.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      other.m_intervals.m_data,
      20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  other.m_intervals.m_data = 0i64;
  other.m_intervals.m_capacityAndFlags = 0x80000000;
  v17.m_intervals.m_size = 0;
  if ( v17.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v17.m_intervals.m_data,
      20 * (v17.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 135
// RVA: 0x12E7770
_BOOL8 __fastcall `anonymous namespace::isEdgeMisconnected(
        hkaiNavMeshInstance *navMeshInstance,
        hkaiNavMesh::Edge *edge)
{
  return hkaiNavMeshInstance_get_hkaiNavMesh::Edge__24(
           navMeshInstance->m_originalEdges,
           navMeshInstance->m_numOriginalEdges,
           &navMeshInstance->m_instancedEdges,
           &navMeshInstance->m_ownedEdges,
           &navMeshInstance->m_edgeMap,
           edge->m_oppositeEdge & 0x3FFFFF)->m_a == edge->m_a;
}

// File Line: 149
// RVA: 0x12E80D0
void __fastcall hkaiNavMeshInstanceSegmentCaster::castSegmentAlongSurface_aux<0>(
        hkaiNavMeshInstanceSegmentCaster *this,
        hkVector4f *uEquation,
        hkVector4f *vEquation,
        int faceIndex,
        float minURange,
        float maxURange,
        hkaiIntervalPartition *partition)
{
  hkaiIntervalPartition *v7; // rdi
  hkaiNavMesh::Face *v8; // rax
  int v9; // edi
  int m_numEdges; // ebx
  hkLifoAllocator *Value; // rcx
  __int64 m_cur; // rax
  int v13; // edx
  void *v14; // r8
  hkLifoAllocator *v15; // rax
  __int64 v16; // rcx
  int v17; // edx
  void *v18; // r8
  float v19; // xmm6_4
  int m_slope_low; // esi
  int m_startEdgeIndex; // r10d
  hkaiNavMeshInstance *m_navMeshInstance; // rbx
  __int64 m_b; // rcx
  int m_numOriginalVertices; // eax
  __m128 *p_m_quad; // rax
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  float v31; // xmm2_4
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  int v34; // eax
  int v35; // edx
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm9_4
  float v39; // xmm8_4
  unsigned int index; // esi
  hkaiNavMeshInstance *v41; // rbx
  hkaiNavMesh::Edge *v42; // rax
  hkaiNavMesh::Edge *v43; // rdi
  char m_storage; // al
  signed int v45; // ebx
  hkLifoAllocator *v46; // rax
  int v47; // edi
  bool v48; // cc
  void *v49; // rbx
  signed int m_data; // esi
  hkLifoAllocator *v51; // rax
  int v52; // [rsp+50h] [rbp-98h]
  int v53; // [rsp+54h] [rbp-94h]
  char *p; // [rsp+58h] [rbp-90h]
  hkaiNavMesh::Face *v55; // [rsp+60h] [rbp-88h]
  float *v56; // [rsp+60h] [rbp-88h]
  int v57; // [rsp+60h] [rbp-88h]
  hkaiIntervalPartition::Interval interval; // [rsp+68h] [rbp-80h] BYREF
  hkaiNavMeshInstanceSegmentCaster *v59; // [rsp+128h] [rbp+40h]
  hkVector4f *uEquationa; // [rsp+130h] [rbp+48h]
  hkVector4f *retaddr; // [rsp+138h] [rbp+50h]
  float v62; // [rsp+148h] [rbp+60h]
  float v63; // [rsp+150h] [rbp+68h]
  hkaiIntervalPartition *v64; // [rsp+158h] [rbp+70h]

  v63 = *(float *)&vEquation;
  v62 = *(float *)&uEquation;
  v64 = v7;
  v8 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__22(
         this->m_navMeshInstance->m_originalFaces,
         this->m_navMeshInstance->m_numOriginalFaces,
         &this->m_navMeshInstance->m_instancedFaces,
         &this->m_navMeshInstance->m_ownedFaces,
         &this->m_navMeshInstance->m_faceMap,
         faceIndex);
  v9 = 0;
  m_numEdges = v8->m_numEdges;
  v55 = v8;
  v52 = m_numEdges;
  if ( v8->m_numEdges )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (__int64)Value->m_cur;
    v13 = (4 * m_numEdges + 127) & 0xFFFFFF80;
    p = (char *)m_cur;
    v14 = (void *)(m_cur + v13);
    if ( v13 <= Value->m_slabSize && v14 <= Value->m_end )
    {
      Value->m_cur = v14;
      goto LABEL_8;
    }
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v13);
  }
  else
  {
    m_cur = 0i64;
  }
  p = (char *)m_cur;
LABEL_8:
  interval.m_data = m_numEdges | 0x80000000;
  if ( m_numEdges )
  {
    v15 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (__int64)v15->m_cur;
    v17 = (4 * m_numEdges + 127) & 0xFFFFFF80;
    *(_QWORD *)&interval.m_leftX = v16;
    v18 = (void *)(v16 + v17);
    if ( v17 > v15->m_slabSize || v18 > v15->m_end )
    {
      v16 = hkLifoAllocator::allocateFromNewSlab(v15, v17);
      *(_QWORD *)&interval.m_leftX = v16;
      m_cur = (__int64)p;
    }
    else
    {
      v15->m_cur = v18;
      m_cur = (__int64)p;
    }
  }
  else
  {
    v16 = 0i64;
    *(_QWORD *)&interval.m_leftX = 0i64;
  }
  v19 = 3.40282e38;
  m_slope_low = -1;
  m_startEdgeIndex = v55->m_startEdgeIndex;
  v53 = v55->m_startEdgeIndex;
  if ( m_numEdges > 0 )
  {
    v56 = (float *)v16;
    *(_QWORD *)&interval.m_slope = m_cur - v16;
    do
    {
      m_navMeshInstance = v59->m_navMeshInstance;
      m_b = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__24(
              m_navMeshInstance->m_originalEdges,
              m_navMeshInstance->m_numOriginalEdges,
              &m_navMeshInstance->m_instancedEdges,
              &m_navMeshInstance->m_ownedEdges,
              &m_navMeshInstance->m_edgeMap,
              v9 + m_startEdgeIndex)->m_b;
      m_numOriginalVertices = m_navMeshInstance->m_numOriginalVertices;
      if ( (int)m_b >= m_numOriginalVertices )
        p_m_quad = &m_navMeshInstance->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices].m_quad;
      else
        p_m_quad = &m_navMeshInstance->m_originalVertices[m_b].m_quad;
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(*p_m_quad, *p_m_quad, 85),
                    m_navMeshInstance->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(
                    _mm_shuffle_ps(*p_m_quad, *p_m_quad, 0),
                    m_navMeshInstance->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(
                  _mm_shuffle_ps(*p_m_quad, *p_m_quad, 170),
                  m_navMeshInstance->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
              m_navMeshInstance->m_referenceFrame.m_transform.m_translation.m_quad);
      v27 = _mm_mul_ps(v26, uEquationa->m_quad);
      v28 = _mm_mul_ps(v26, retaddr->m_quad);
      v29 = _mm_shuffle_ps(v27, _mm_unpackhi_ps(v27, uEquationa->m_quad), 196);
      v30 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 78), v29);
      v31 = _mm_shuffle_ps(v30, v30, 177).m128_f32[0] + v30.m128_f32[0];
      v32 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, retaddr->m_quad), 196);
      *(float *)((char *)v56 + *(_QWORD *)&interval.m_slope) = v31;
      v33 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 78), v32);
      *v56 = _mm_shuffle_ps(v33, v33, 177).m128_f32[0] + v33.m128_f32[0];
      if ( v31 < v19 )
      {
        v19 = v31;
        m_slope_low = v9;
      }
      m_numEdges = v52;
      m_startEdgeIndex = v53;
      ++v9;
      ++v56;
    }
    while ( v9 < v52 );
    v16 = *(_QWORD *)&interval.m_leftX;
  }
  v57 = (m_slope_low + 1) % m_numEdges;
  if ( m_slope_low != v57 )
  {
    v34 = m_numEdges - 1;
    do
    {
      v35 = (m_slope_low + v34) % m_numEdges;
      v36 = *(float *)&p[4 * m_slope_low];
      LODWORD(interval.m_slope) = v35;
      v37 = *(float *)&p[4 * v35];
      if ( v37 > v62 )
      {
        if ( (float)(v36 - v37) > 0.0099999998 )
          break;
        if ( v36 < v37 )
        {
          if ( v36 >= v63 )
            break;
          v38 = *(float *)(v16 + 4i64 * m_slope_low);
          v39 = *(float *)(v16 + 4i64 * v35);
          if ( v38 < 1.0 || v39 < 1.0 )
          {
            index = m_startEdgeIndex + m_slope_low;
            v41 = v59->m_navMeshInstance;
            v42 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__24(
                    v41->m_originalEdges,
                    v41->m_numOriginalEdges,
                    &v41->m_instancedEdges,
                    &v41->m_ownedEdges,
                    &v41->m_edgeMap,
                    index);
            v43 = v42;
            if ( v42->m_oppositeEdge == -1
              || (m_storage = v42->m_flags.m_storage, (m_storage & 0x20) != 0)
              || (m_storage & 0x40) != 0
              || `anonymous namespace::isEdgeMisconnected(v41, v43) )
            {
              hkaiIntervalPartition::Interval::setFromEndpoints(&interval, v36, v38, v37, v39, index);
              interval.m_leftX = fmaxf(v36, v62);
              interval.m_rightX = fminf(v37, v63);
              if ( hkaiIntervalPartition::Interval::clampY(&interval, 0.0, 1.0) )
                hkaiIntervalPartition::appendInterval(v64, &interval);
            }
            else
            {
              hkaiNavMeshInstanceSegmentCaster::castSegmentAlongSurface_aux<0>(
                v59,
                uEquationa,
                retaddr,
                v43->m_oppositeFace & 0x3FFFFF,
                fmaxf(v36, v62),
                fminf(v37, v63),
                v64);
            }
            m_numEdges = v52;
          }
        }
      }
      m_slope_low = LODWORD(interval.m_slope);
      v16 = *(_QWORD *)&interval.m_leftX;
      m_startEdgeIndex = v53;
      v34 = m_numEdges - 1;
    }
    while ( LODWORD(interval.m_slope) != v57 );
  }
  v45 = (4 * m_numEdges + 127) & 0xFFFFFF80;
  LODWORD(v59) = v45;
  v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v47 = (v45 + 15) & 0xFFFFFFF0;
  v48 = v45 <= v46->m_slabSize;
  v49 = *(void **)&interval.m_leftX;
  if ( v48
    && (void *)(*(_QWORD *)&interval.m_leftX + v47) == v46->m_cur
    && v46->m_firstNonLifoEnd != *(void **)&interval.m_leftX )
  {
    v46->m_cur = *(void **)&interval.m_leftX;
  }
  else
  {
    hkLifoAllocator::slowBlockFree(v46, *(char **)&interval.m_leftX, v47);
  }
  m_data = interval.m_data;
  if ( (interval.m_data & 0x80000000) == 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v49, 4 * interval.m_data);
  v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( (int)v59 > v51->m_slabSize || &p[v47] != v51->m_cur || v51->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v51, p, v47);
  else
    v51->m_cur = p;
  if ( m_data >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, p, 4 * m_data);
}

// File Line: 374
// RVA: 0x12E7430
void __fastcall hkaiNavMeshInstanceSegmentCaster::castSegmentAlongSurface(
        hkaiNavMeshInstanceSegmentCaster *this,
        hkVector4f *leftStartIn,
        hkVector4f *rightStartIn,
        hkVector4f *displacement,
        hkVector4f *up,
        int startingFace,
        hkaiIntervalPartition *partition)
{
  int v7; // ebx
  __m128 m_quad; // xmm8
  __m128 v9; // xmm11
  __m128 v10; // xmm9
  __m128 v11; // xmm12
  __m128 v12; // xmm1
  __m128 v13; // xmm10
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm8
  __m128 v17; // xmm1
  __m128 v18; // xmm12
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm6
  __m128 v24; // xmm8
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm7
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm3
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  hkVector4f vEquation; // [rsp+40h] [rbp-A8h] BYREF
  hkVector4f uEquation; // [rsp+50h] [rbp-98h] BYREF

  v7 = 0;
  m_quad = rightStartIn->m_quad;
  v9 = leftStartIn->m_quad;
  v10 = up->m_quad;
  v11 = displacement->m_quad;
  v12 = _mm_sub_ps(rightStartIn->m_quad, leftStartIn->m_quad);
  v13 = _mm_shuffle_ps(v10, v10, 201);
  v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), up->m_quad), _mm_mul_ps(v13, v12));
  v15 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), displacement->m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
             + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]) < 0.0 )
    v7 = 1;
  if ( v7 )
  {
    v9 = rightStartIn->m_quad;
    m_quad = leftStartIn->m_quad;
  }
  v16 = _mm_sub_ps(m_quad, v9);
  v17 = _mm_mul_ps(v11, v10);
  v18 = _mm_sub_ps(
          v11,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170)),
            v10));
  v19 = _mm_mul_ps(v18, v18);
  v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)), _mm_shuffle_ps(v19, v19, 170));
  v21 = _mm_rsqrt_ps(v20);
  v22 = _mm_mul_ps(v10, v16);
  v23 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v20, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
              _mm_mul_ps(*(__m128 *)_xmm, v21))),
          v18);
  v24 = _mm_sub_ps(
          v16,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170)),
            v10));
  v25 = _mm_mul_ps(v24, v24);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v27 = _mm_rsqrt_ps(v26);
  v28 = _mm_sub_ps(_mm_mul_ps(v13, v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v10));
  v29 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v26, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v27, v26), v27)),
              _mm_mul_ps(*(__m128 *)_xmm, v27))),
          v24);
  v30 = _mm_shuffle_ps(v28, v28, 201);
  v31 = _mm_mul_ps(v30, v24);
  v32 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v33 = _mm_rcp_ps(v32);
  v34 = _mm_mul_ps(v33, v32);
  v35 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v10), _mm_mul_ps(v13, v29));
  v36 = _mm_mul_ps(v30, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v34), v33));
  v37 = _mm_shuffle_ps(v35, v35, 201);
  v38 = _mm_mul_ps(v36, v9);
  v39 = _mm_mul_ps(v37, v18);
  uEquation.m_quad = _mm_shuffle_ps(
                       v36,
                       _mm_unpackhi_ps(
                         v36,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                             _mm_shuffle_ps(v38, v38, 170)))),
                       196);
  v40 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)), _mm_shuffle_ps(v39, v39, 170));
  v41 = _mm_rcp_ps(v40);
  v42 = _mm_mul_ps(v37, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v40)), v41));
  v43 = _mm_mul_ps(v42, v9);
  vEquation.m_quad = _mm_shuffle_ps(
                       v42,
                       _mm_unpackhi_ps(
                         v42,
                         _mm_sub_ps(
                           (__m128)0i64,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                             _mm_shuffle_ps(v43, v43, 170)))),
                       196);
  hkaiNavMeshInstanceSegmentCaster::castSegmentAlongSurface_aux<1>(
    this,
    &uEquation,
    &vEquation,
    startingFace,
    0.0,
    1.0,
    partition);
  if ( v7 )
    hkaiIntervalPartition::reflectX(partition, 0.5);
}

// File Line: 446
// RVA: 0x12E70F0
__int64 __fastcall hkaiNavMeshInstanceSegmentCaster::AccelerationData::getSize(
        hkaiNavMeshInstanceSegmentCaster::AccelerationData *this)
{
  return (unsigned int)hkcdDynamicAabbTree::getMemoryFootPrint(this->m_tree.m_pntr) + 24;
}

