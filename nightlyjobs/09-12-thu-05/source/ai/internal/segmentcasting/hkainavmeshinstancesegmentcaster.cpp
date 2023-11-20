// File Line: 38
// RVA: 0x12E8800
signed __int64 __fastcall NavMeshInstanceCastSegmentQuery::processLeaf(NavMeshInstanceCastSegmentQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  NavMeshInstanceCastSegmentQuery *v3; // rbx
  hkaiIntervalPartition *v4; // rdi
  hkaiIntervalPartition *v5; // rcx

  v3 = this;
  v4 = &this->m_curPartition;
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFace(
         &this->m_leftStart,
         &this->m_rightStart,
         &this->m_displacement,
         this->m_navMeshInstance,
         leafKey,
         leafKey,
         &this->m_curPartition) )
  {
    v5 = &v3->m_fullPartition;
    if ( v3->m_fullPartition.m_intervals.m_size > 0 )
    {
      hkaiIntervalPartition::combine<0,0>(v5, v4);
      hkaiIntervalPartition::clear(v4);
      return 1i64;
    }
    hkaiIntervalPartition::swap(v5, v4);
  }
  return 1i64;
}

// File Line: 77
// RVA: 0x12E7110
hkaiNavMeshInstanceSegmentCaster::AccelerationData *__fastcall hkaiNavMeshInstanceSegmentCaster::buildAccelerationData(hkaiNavMeshInstance *navMeshInstance)
{
  hkaiNavMeshInstance *v1; // rbp
  _QWORD **v2; // rax
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
  hkAabb *aabbOut[2]; // [rsp+20h] [rbp-48h]
  hkSimdFloat32 extraRadius; // [rsp+30h] [rbp-38h]
  char v18; // [rsp+70h] [rbp+8h]
  char v19; // [rsp+78h] [rbp+10h]

  v1 = navMeshInstance;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 24i64);
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
  v7 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 32i64);
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
  v12 = v1->m_numOriginalFaces + v1->m_ownedFaces.m_size;
  v13 = v12;
  if ( v12 > 0 )
  {
    do
    {
      if ( v1->m_faceFlags.m_size )
      {
        v14 = &v18;
        v18 = v1->m_faceFlags.m_data[v11].m_storage;
      }
      else
      {
        v19 = 0;
        v14 = &v19;
      }
      if ( !(*v14 & 1) )
      {
        *(hkVector4f *)aabbOut = (hkVector4f)::aabbOut.m_quad;
        hkaiNavMeshUtils::calcFaceAabb<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)v1,
          (hkaiNavMeshInstance *)v4,
          (__int64)aabbOut,
          &extraRadius,
          (hkAabb *)::aabbOut.m_quad.m128_u64[0]);
        hkcdDynamicAabbTree::insert(*(hkcdDynamicAabbTree **)(v5 + 16), (hkAabb *)&extraRadius, v4);
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
void __fastcall hkaiNavMeshInstanceSegmentCaster::hkaiNavMeshInstanceSegmentCaster(hkaiNavMeshInstanceSegmentCaster *this, hkaiNavMeshInstance *navMeshInstance, hkaiNavMeshInstanceSegmentCaster::AccelerationData *accelerationData)
{
  hkaiNavMeshInstanceSegmentCaster::AccelerationData *v3; // rdi
  hkaiNavMeshInstanceSegmentCaster *v4; // rbx

  v3 = accelerationData;
  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_navMeshInstance = navMeshInstance;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstanceSegmentCaster::`vftable;
  if ( accelerationData )
  {
    hkReferencedObject::addReference((hkReferencedObject *)&accelerationData->vfptr);
    v4->m_accelerationData.m_pntr = v3;
  }
  else
  {
    this->m_accelerationData.m_pntr = 0i64;
  }
}

// File Line: 109
// RVA: 0x12E72B0
void __fastcall hkaiNavMeshInstanceSegmentCaster::~hkaiNavMeshInstanceSegmentCaster(hkaiNavMeshInstanceSegmentCaster *this)
{
  hkaiNavMeshInstanceSegmentCaster *v1; // rbx
  hkaiNavMeshInstanceSegmentCaster::AccelerationData *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshInstanceSegmentCaster::`vftable;
  v2 = this->m_accelerationData.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_accelerationData.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 117
// RVA: 0x12E72F0
void __fastcall hkaiNavMeshInstanceSegmentCaster::castSegment(hkaiNavMeshInstanceSegmentCaster *this, hkVector4f *leftStart, hkVector4f *rightStart, hkVector4f *displacement, hkaiIntervalPartition *partition)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm4
  hkaiNavMeshInstanceSegmentCaster *v7; // rbx
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm0
  hkaiNavMeshInstance *v11; // rax
  __m128 v12; // xmm0
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-98h]
  __int128 v14; // [rsp+30h] [rbp-88h]
  __int128 v15; // [rsp+40h] [rbp-78h]
  __int128 v16; // [rsp+50h] [rbp-68h]
  hkaiNavMeshInstance *v17; // [rsp+60h] [rbp-58h]
  hkaiIntervalPartition v18; // [rsp+68h] [rbp-50h]
  hkaiIntervalPartition other; // [rsp+78h] [rbp-40h]
  hkAabb aabb; // [rsp+90h] [rbp-28h]

  v5 = rightStart->m_quad;
  v6 = leftStart->m_quad;
  v7 = this;
  v8 = _mm_add_ps(displacement->m_quad, leftStart->m_quad);
  _mm_store_si128((__m128i *)&v15, (__m128i)rightStart->m_quad);
  v9 = _mm_add_ps(v5, displacement->m_quad);
  aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(v6, v5), v8), v9);
  aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(v6, v5), v8), v9);
  v10 = leftStart->m_quad;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&NavMeshInstanceCastSegmentQuery::`vftable;
  v11 = this->m_navMeshInstance;
  _mm_store_si128((__m128i *)&v14, (__m128i)v10);
  v12 = displacement->m_quad;
  v17 = v11;
  _mm_store_si128((__m128i *)&v16, (__m128i)v12);
  hkaiIntervalPartition::hkaiIntervalPartition(&v18);
  hkaiIntervalPartition::hkaiIntervalPartition(&other);
  hkcdDynamicAabbTree::queryAabb(v7->m_accelerationData.m_pntr->m_tree.m_pntr, &aabb, &collector);
  hkaiIntervalPartition::swap(partition, &other);
  other.m_intervals.m_size = 0;
  if ( other.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      other.m_intervals.m_data,
      20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  other.m_intervals.m_data = 0i64;
  other.m_intervals.m_capacityAndFlags = 2147483648;
  v18.m_intervals.m_size = 0;
  if ( v18.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v18.m_intervals.m_data,
      20 * (v18.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 135
// RVA: 0x12E7770
_BOOL8 __fastcall `anonymous namespace::isEdgeMisconnected(hkaiNavMeshInstance *navMeshInstance, hkaiNavMesh::Edge *edge)
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
void __usercall hkaiNavMeshInstanceSegmentCaster::castSegmentAlongSurface_aux<0>(hkaiNavMeshInstanceSegmentCaster *this@<rcx>, hkVector4f *uEquation@<rdx>, hkVector4f *vEquation@<r8>, int faceIndex@<r9d>, hkaiIntervalPartition *a5@<rdi>, float minURange, float maxURange, hkaiIntervalPartition *partition)
{
  hkaiNavMesh::Face *v8; // rax
  float v9; // edi
  int v10; // ebx
  hkLifoAllocator *v11; // rax
  hkLifoAllocator *v12; // rcx
  char *v13; // rax
  int v14; // edx
  char *v15; // r8
  hkLifoAllocator *v16; // rax
  float *v17; // rcx
  int v18; // edx
  char *v19; // r8
  float *v20; // rax
  float v21; // xmm6_4
  float v22; // esi
  int v23; // er10
  hkaiNavMeshInstance *v24; // rbx
  __int64 v25; // rcx
  signed int v26; // eax
  __m128 *v27; // rax
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  float v33; // xmm2_4
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  int v36; // eax
  int v37; // edx
  float v38; // xmm6_4
  float v39; // xmm7_4
  float v40; // xmm9_4
  float v41; // xmm8_4
  int index; // esi
  hkaiNavMeshInstance *v43; // rbx
  hkaiNavMesh::Edge *v44; // rax
  hkaiNavMesh::Edge *v45; // rdi
  char v46; // al
  int v47; // eax
  unsigned int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // edi
  bool v51; // zf
  bool v52; // sf
  unsigned __int8 v53; // of
  void *v54; // rbx
  signed int v55; // esi
  hkLifoAllocator *v56; // rax
  int v57; // [rsp+50h] [rbp-98h]
  int v58; // [rsp+54h] [rbp-94h]
  char *p; // [rsp+58h] [rbp-90h]
  hkaiNavMesh::Face *v60; // [rsp+60h] [rbp-88h]
  float *v61; // [rsp+60h] [rbp-88h]
  int v62; // [rsp+60h] [rbp-88h]
  hkaiIntervalPartition::Interval interval; // [rsp+68h] [rbp-80h]
  hkaiNavMeshInstanceSegmentCaster *v64; // [rsp+128h] [rbp+40h]
  hkVector4f *uEquationa; // [rsp+130h] [rbp+48h]
  hkVector4f *retaddr; // [rsp+138h] [rbp+50h]
  hkVector4f *v67; // [rsp+148h] [rbp+60h]
  hkVector4f *v68; // [rsp+150h] [rbp+68h]
  hkaiIntervalPartition *v69; // [rsp+158h] [rbp+70h]

  v68 = vEquation;
  v67 = uEquation;
  v69 = a5;
  v8 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__22(
         this->m_navMeshInstance->m_originalFaces,
         this->m_navMeshInstance->m_numOriginalFaces,
         &this->m_navMeshInstance->m_instancedFaces,
         &this->m_navMeshInstance->m_ownedFaces,
         &this->m_navMeshInstance->m_faceMap,
         faceIndex);
  v9 = 0.0;
  v10 = v8->m_numEdges;
  v60 = v8;
  v57 = v8->m_numEdges;
  if ( v8->m_numEdges )
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = v11;
    v13 = (char *)v11->m_cur;
    v14 = (4 * v10 + 127) & 0xFFFFFF80;
    p = v13;
    v15 = &v13[v14];
    if ( v14 <= v12->m_slabSize && v15 <= v12->m_end )
    {
      v12->m_cur = v15;
      goto LABEL_8;
    }
    v13 = (char *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
  }
  else
  {
    v13 = 0i64;
  }
  p = v13;
LABEL_8:
  interval.m_data = v10 | 0x80000000;
  if ( v10 )
  {
    v16 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v17 = (float *)v16->m_cur;
    v18 = (4 * v10 + 127) & 0xFFFFFF80;
    *(_QWORD *)&interval.m_leftX = v17;
    v19 = (char *)v17 + v18;
    if ( v18 > v16->m_slabSize || v19 > v16->m_end )
    {
      v20 = (float *)hkLifoAllocator::allocateFromNewSlab(v16, v18);
      v17 = v20;
      *(_QWORD *)&interval.m_leftX = v20;
      v13 = p;
    }
    else
    {
      v16->m_cur = v19;
      v13 = p;
    }
  }
  else
  {
    v17 = 0i64;
    *(_QWORD *)&interval.m_leftX = 0i64;
  }
  v21 = *(float *)&xmmword_141A712A0;
  v22 = -6.8056469e38/*NaN*/;
  v23 = v60->m_startEdgeIndex;
  v58 = v60->m_startEdgeIndex;
  if ( v10 > 0 )
  {
    v61 = v17;
    *(_QWORD *)&interval.m_slope = v13 - (char *)v17;
    do
    {
      v24 = v64->m_navMeshInstance;
      v25 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__24(
              v24->m_originalEdges,
              v24->m_numOriginalEdges,
              &v24->m_instancedEdges,
              &v24->m_ownedEdges,
              &v24->m_edgeMap,
              LODWORD(v9) + v23)->m_b;
      v26 = v24->m_numOriginalVertices;
      if ( (signed int)v25 >= v26 )
        v27 = &v24->m_ownedVertices.m_data[(signed int)v25 - v26].m_quad;
      else
        v27 = &v24->m_originalVertices[v25].m_quad;
      v28 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 85), v24->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 0), v24->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 170), v24->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
              v24->m_referenceFrame.m_transform.m_translation.m_quad);
      v29 = _mm_mul_ps(v28, uEquationa->m_quad);
      v30 = _mm_mul_ps(v28, retaddr->m_quad);
      v31 = _mm_shuffle_ps(v29, _mm_unpackhi_ps(v29, uEquationa->m_quad), 196);
      v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
      v33 = COERCE_FLOAT(_mm_shuffle_ps(v32, v32, 177)) + v32.m128_f32[0];
      v34 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, retaddr->m_quad), 196);
      *(float *)((char *)v61 + *(_QWORD *)&interval.m_slope) = v33;
      v35 = _mm_add_ps(_mm_shuffle_ps(v34, v34, 78), v34);
      *v61 = COERCE_FLOAT(_mm_shuffle_ps(v35, v35, 177)) + v35.m128_f32[0];
      if ( v33 < v21 )
      {
        v21 = v33;
        v22 = v9;
      }
      v10 = v57;
      v23 = v58;
      ++LODWORD(v9);
      ++v61;
    }
    while ( SLODWORD(v9) < v57 );
    v17 = *(float **)&interval.m_leftX;
  }
  v62 = (LODWORD(v22) + 1) % v10;
  if ( LODWORD(v22) != v62 )
  {
    v36 = v10 - 1;
    do
    {
      v37 = (LODWORD(v22) + v36) % v10;
      v38 = *(float *)&p[4 * SLODWORD(v22)];
      LODWORD(interval.m_slope) = v37;
      v39 = *(float *)&p[4 * v37];
      if ( v39 > *(float *)&v67 )
      {
        if ( (float)(v38 - v39) > 0.0099999998 )
          break;
        if ( v38 < v39 )
        {
          if ( v38 >= *(float *)&v68 )
            break;
          v40 = v17[SLODWORD(v22)];
          v41 = v17[v37];
          if ( v40 < 1.0 || v41 < 1.0 )
          {
            index = v23 + LODWORD(v22);
            v43 = v64->m_navMeshInstance;
            v44 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__24(
                    v43->m_originalEdges,
                    v43->m_numOriginalEdges,
                    &v43->m_instancedEdges,
                    &v43->m_ownedEdges,
                    &v43->m_edgeMap,
                    index);
            v45 = v44;
            if ( v44->m_oppositeEdge == -1
              || (v46 = v44->m_flags.m_storage, v46 & 0x20)
              || v46 & 0x40
              || (unsigned int)`anonymous namespace::isEdgeMisconnected(v43, v45) )
            {
              hkaiIntervalPartition::Interval::setFromEndpoints(&interval, v38, v40, v39, v41, index);
              interval.m_leftX = fmaxf(v38, *(float *)&v67);
              interval.m_rightX = fminf(v39, *(float *)&v68);
              LOBYTE(v47) = hkaiIntervalPartition::Interval::clampY(&interval, 0.0, 1.0);
              if ( v47 )
                hkaiIntervalPartition::appendInterval(v69, &interval);
            }
            else
            {
              hkaiNavMeshInstanceSegmentCaster::castSegmentAlongSurface_aux<0>(
                v64,
                uEquationa,
                retaddr,
                v45->m_oppositeFace & 0x3FFFFF,
                fmaxf(v38, *(float *)&v67),
                fminf(v39, *(float *)&v68),
                v69);
            }
            v10 = v57;
          }
        }
      }
      v22 = interval.m_slope;
      v17 = *(float **)&interval.m_leftX;
      v23 = v58;
      v36 = v10 - 1;
    }
    while ( LODWORD(interval.m_slope) != v62 );
  }
  v48 = (4 * v10 + 127) & 0xFFFFFF80;
  LODWORD(v64) = v48;
  v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v50 = (v48 + 15) & 0xFFFFFFF0;
  v53 = __OFSUB__(v48, v49->m_slabSize);
  v51 = v48 == v49->m_slabSize;
  v52 = (signed int)(v48 - v49->m_slabSize) < 0;
  v54 = *(void **)&interval.m_leftX;
  if ( (unsigned __int8)(v52 ^ v53) | v51
    && (void *)(*(_QWORD *)&interval.m_leftX + v50) == v49->m_cur
    && v49->m_firstNonLifoEnd != *(void **)&interval.m_leftX )
  {
    v49->m_cur = *(void **)&interval.m_leftX;
  }
  else
  {
    hkLifoAllocator::slowBlockFree(v49, *(void **)&interval.m_leftX, v50);
  }
  v55 = interval.m_data;
  if ( (interval.m_data & 0x80000000) == 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v54,
      4 * interval.m_data);
  v56 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( (signed int)v64 > v56->m_slabSize || &p[v50] != v56->m_cur || v56->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(v56, p, v50);
  else
    v56->m_cur = p;
  if ( v55 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      p,
      4 * v55);
}

// File Line: 374
// RVA: 0x12E7430
void __fastcall hkaiNavMeshInstanceSegmentCaster::castSegmentAlongSurface(hkaiNavMeshInstanceSegmentCaster *this, hkVector4f *leftStartIn, hkVector4f *rightStartIn, hkVector4f *displacement, hkVector4f *up, int startingFace, hkaiIntervalPartition *partition)
{
  signed int v7; // ebx
  __m128 v8; // xmm8
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
  hkVector4f vEquation; // [rsp+40h] [rbp-A8h]
  hkVector4f uEquation; // [rsp+50h] [rbp-98h]

  v7 = 0;
  v8 = rightStartIn->m_quad;
  v9 = leftStartIn->m_quad;
  v10 = up->m_quad;
  v11 = displacement->m_quad;
  v12 = _mm_sub_ps(rightStartIn->m_quad, leftStartIn->m_quad);
  v13 = _mm_shuffle_ps(v10, v10, 201);
  v14 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), up->m_quad), _mm_mul_ps(v13, v12));
  v15 = _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), displacement->m_quad);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 170))) < 0.0 )
    v7 = 1;
  if ( v7 )
  {
    v9 = rightStartIn->m_quad;
    v8 = leftStartIn->m_quad;
  }
  v16 = _mm_sub_ps(v8, v9);
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
            _mm_cmpleps(v20, (__m128)0i64),
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
            _mm_cmpleps(v26, (__m128)0i64),
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
__int64 __fastcall hkaiNavMeshInstanceSegmentCaster::AccelerationData::getSize(hkaiNavMeshInstanceSegmentCaster::AccelerationData *this)
{
  return (unsigned int)hkcdDynamicAabbTree::getMemoryFootPrint(this->m_tree.m_pntr) + 24;
}

