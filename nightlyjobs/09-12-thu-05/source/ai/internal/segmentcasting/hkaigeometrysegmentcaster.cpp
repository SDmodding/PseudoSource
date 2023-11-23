// File Line: 64
// RVA: 0x12E6850
__int64 __fastcall `anonymous namespace::GeometryCastSegmentQuery::processLeaf(
        GeometryCastSegmentQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  unsigned int data; // eax
  hkaiIntervalPartition *p_m_fullPartition; // rcx
  hkaiIntervalPartition *p_m_curPartition; // rdx

  data = hkaiGeometrySegmentCaster::packData(HITTYPE_FACE, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFace(
         &this->m_leftStart,
         &this->m_rightStart,
         &this->m_displacement,
         this->m_geometry,
         leafKey,
         data,
         &this->m_curPartition) )
  {
    p_m_fullPartition = &this->m_fullPartition;
    p_m_curPartition = &this->m_curPartition;
    if ( this->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(
        p_m_fullPartition,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)p_m_curPartition);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(p_m_fullPartition, p_m_curPartition);
      hkaiIntervalPartition::clear(&this->m_curPartition);
    }
  }
  return 1i64;
}

// File Line: 129
// RVA: 0x12E6650
__int64 __fastcall `anonymous namespace::DoubledGeometryCastSegmentQuery::processLeaf(
        DoubledGeometryCastSegmentQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  unsigned int data; // eax
  hkaiIntervalPartition *p_m_fullPartition; // rcx
  hkaiIntervalPartition *p_m_curPartition; // rdx
  unsigned int v8; // eax
  hkaiIntervalPartition *v9; // rcx
  hkaiIntervalPartition *v10; // rdx

  data = hkaiGeometrySegmentCaster::packData(HITTYPE_FACE, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFace(
         &this->m_leftStart,
         &this->m_rightStart,
         &this->m_displacement,
         this->m_geometry,
         leafKey,
         data,
         &this->m_curPartition) )
  {
    p_m_fullPartition = &this->m_fullPartition;
    p_m_curPartition = &this->m_curPartition;
    if ( this->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(
        p_m_fullPartition,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)p_m_curPartition);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(p_m_fullPartition, p_m_curPartition);
      hkaiIntervalPartition::clear(&this->m_curPartition);
    }
  }
  v8 = hkaiGeometrySegmentCaster::packData(HITTYPE_TRANSLATED_FACE, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFace(
         &this->m_shiftedLeftStart,
         &this->m_shiftedRightStart,
         &this->m_displacement,
         this->m_geometry,
         leafKey,
         v8,
         &this->m_curPartition) )
  {
    v9 = &this->m_fullPartition;
    v10 = &this->m_curPartition;
    if ( this->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(v9, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v10);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(v9, v10);
      hkaiIntervalPartition::clear(&this->m_curPartition);
    }
  }
  return 1i64;
}

// File Line: 222
// RVA: 0x12E6B50
__int64 __fastcall `anonymous namespace::GeometryExtrusionCastSegmentQuery::processLeaf(
        GeometryExtrusionCastSegmentQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  hkGeometry *m_geometry; // r10
  hkaiGeometrySegmentCaster::ExtrudedEdge *v5; // r9
  unsigned int m_geometryIdx; // edx
  unsigned int data; // eax
  hkaiIntervalPartition *p_m_fullPartition; // rcx
  hkaiIntervalPartition *p_m_curPartition; // rdx
  hkVector4f vertexB; // [rsp+40h] [rbp-28h] BYREF
  hkVector4f vertexA; // [rsp+50h] [rbp-18h] BYREF

  m_geometry = this->m_geometry;
  v5 = &this->m_edges->m_data[leafKey];
  vertexA.m_quad = (__m128)m_geometry->m_vertices.m_data[v5->m_a];
  m_geometryIdx = this->m_geometryIdx;
  vertexB.m_quad = (__m128)m_geometry->m_vertices.m_data[v5->m_b];
  data = hkaiGeometrySegmentCaster::packData(HITTYPE_EXTRUDED_EDGE, m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentExtrudedEdge(
         &this->m_leftStart,
         &this->m_rightStart,
         &this->m_displacement,
         &vertexA,
         &vertexB,
         &this->m_extrusion,
         data,
         &this->m_curPartition) )
  {
    p_m_fullPartition = &this->m_fullPartition;
    p_m_curPartition = &this->m_curPartition;
    if ( this->m_fullPartition.m_intervals.m_size > 0 )
    {
      hkaiIntervalPartition::combine<0,0>(p_m_fullPartition, p_m_curPartition);
      hkaiIntervalPartition::clear(&this->m_curPartition);
      return 1i64;
    }
    hkaiIntervalPartition::swap(
      p_m_fullPartition,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)p_m_curPartition);
  }
  return 1i64;
}

// File Line: 296
// RVA: 0x12E6D20
__int64 __fastcall `anonymous namespace::GeometryTurnedSegmentQuery::processLeaf(
        GeometryTurnedSegmentQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  unsigned int data; // eax
  hkaiIntervalPartition *p_m_fullPartition; // rcx
  hkaiIntervalPartition *p_m_curPartition; // rdx

  data = hkaiGeometrySegmentCaster::packData(HITTYPE_FACE, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
         &this->m_leftStart,
         &this->m_rightStart,
         &this->m_leftEnd,
         &this->m_rightEnd,
         this->m_geometry,
         leafKey,
         data,
         &this->m_curPartition) )
  {
    p_m_fullPartition = &this->m_fullPartition;
    p_m_curPartition = &this->m_curPartition;
    if ( this->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(
        p_m_fullPartition,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)p_m_curPartition);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(p_m_fullPartition, p_m_curPartition);
      hkaiIntervalPartition::clear(&this->m_curPartition);
    }
  }
  return 1i64;
}

// File Line: 367
// RVA: 0x12E6740
__int64 __fastcall `anonymous namespace::DoubledGeometryTurnedSegmentQuery::processLeaf(
        DoubledGeometryTurnedSegmentQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  unsigned int data; // eax
  hkaiIntervalPartition *p_m_fullPartition; // rcx
  hkaiIntervalPartition *p_m_curPartition; // rdx
  unsigned int v8; // eax
  hkaiIntervalPartition *v9; // rcx
  hkaiIntervalPartition *v10; // rdx

  data = hkaiGeometrySegmentCaster::packData(HITTYPE_FACE, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
         &this->m_leftStart,
         &this->m_rightStart,
         &this->m_leftEnd,
         &this->m_rightEnd,
         this->m_geometry,
         leafKey,
         data,
         &this->m_curPartition) )
  {
    p_m_fullPartition = &this->m_fullPartition;
    p_m_curPartition = &this->m_curPartition;
    if ( this->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(
        p_m_fullPartition,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)p_m_curPartition);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(p_m_fullPartition, p_m_curPartition);
      hkaiIntervalPartition::clear(&this->m_curPartition);
    }
  }
  v8 = hkaiGeometrySegmentCaster::packData(HITTYPE_TRANSLATED_FACE, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
         &this->m_shiftedLeftStart,
         &this->m_shiftedRightStart,
         &this->m_shiftedLeftEnd,
         &this->m_shiftedRightEnd,
         this->m_geometry,
         leafKey,
         v8,
         &this->m_curPartition) )
  {
    v9 = &this->m_fullPartition;
    v10 = &this->m_curPartition;
    if ( this->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(v9, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v10);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(v9, v10);
      hkaiIntervalPartition::clear(&this->m_curPartition);
    }
  }
  return 1i64;
}

// File Line: 467
// RVA: 0x12E6C30
__int64 __fastcall `anonymous namespace::GeometryExtrusionTurnedSegmentQuery::processLeaf(
        GeometryExtrusionTurnedSegmentQuery *this,
        unsigned int leafKey,
        hkAabb *leafAabb)
{
  hkGeometry *m_geometry; // r10
  hkaiGeometrySegmentCaster::ExtrudedEdge *v5; // r9
  unsigned int m_geometryIdx; // edx
  unsigned int data; // eax
  hkaiIntervalPartition *p_m_fullPartition; // rcx
  hkaiIntervalPartition *p_m_curPartition; // rdx
  hkVector4f vertexB; // [rsp+50h] [rbp-28h] BYREF
  hkVector4f vertexA; // [rsp+60h] [rbp-18h] BYREF

  m_geometry = this->m_geometry;
  v5 = &this->m_edges->m_data[leafKey];
  vertexA.m_quad = (__m128)m_geometry->m_vertices.m_data[v5->m_a];
  m_geometryIdx = this->m_geometryIdx;
  vertexB.m_quad = (__m128)m_geometry->m_vertices.m_data[v5->m_b];
  data = hkaiGeometrySegmentCaster::packData(HITTYPE_EXTRUDED_EDGE, m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectTurnedSegmentExtrudedEdge(
         &this->m_leftStart,
         &this->m_rightStart,
         &this->m_leftEnd,
         &this->m_rightEnd,
         &vertexA,
         &vertexB,
         &this->m_extrusion,
         data,
         &this->m_curPartition) )
  {
    p_m_fullPartition = &this->m_fullPartition;
    p_m_curPartition = &this->m_curPartition;
    if ( this->m_fullPartition.m_intervals.m_size > 0 )
    {
      hkaiIntervalPartition::combine<0,0>(p_m_fullPartition, p_m_curPartition);
      hkaiIntervalPartition::clear(&this->m_curPartition);
      return 1i64;
    }
    hkaiIntervalPartition::swap(
      p_m_fullPartition,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)p_m_curPartition);
  }
  return 1i64;
}

// File Line: 538
// RVA: 0x12E68E0
__int64 __fastcall `anonymous namespace::GeometryExtremalProfileQuery::processLeaf(
        GeometryExtremalProfileQuery *this,
        signed int leafKey,
        hkAabb *leafAabb)
{
  hkGeometry *m_geometry; // r10
  hkaiGeometrySegmentCaster::ExtrudedEdge *m_data; // r9
  __m128 m_quad; // xmm4
  __m128 v8; // xmm2
  hkVector4f v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  float v17; // xmm8_4
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  float v20; // xmm9_4
  hkVector4f v21; // xmm7
  __m128 v22; // xmm6
  __m128 v23; // xmm7
  unsigned int v24; // eax
  hkVector4f b; // [rsp+40h] [rbp-88h] BYREF
  hkVector4f a; // [rsp+50h] [rbp-78h] BYREF
  hkaiIntervalPartition::Interval interval; // [rsp+60h] [rbp-68h] BYREF
  float t0; // [rsp+D0h] [rbp+8h] BYREF
  hkBool result; // [rsp+D8h] [rbp+10h] BYREF
  float t1; // [rsp+E8h] [rbp+20h] BYREF

  m_geometry = this->m_geometry;
  m_data = this->m_edges->m_data;
  m_quad = m_geometry->m_vertices.m_data[m_data[leafKey].m_a].m_quad;
  a.m_quad = m_quad;
  b.m_quad = (__m128)m_geometry->m_vertices.m_data[m_data[leafKey].m_b];
  v8 = _mm_mul_ps(_mm_sub_ps(b.m_quad, m_quad), this->m_xEqn.m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
             + _mm_shuffle_ps(v8, v8, 170).m128_f32[0]) < 0.0 )
  {
    a.m_quad = b.m_quad;
    b.m_quad = m_quad;
  }
  if ( !hkgpConvexHull::clipLine(this->m_clippingVolume, &result, &a, &b, &t0, &t1, 0.0)->m_bool || t1 <= t0 )
    return 1i64;
  v9.m_quad = (__m128)this->m_xEqn;
  v10 = _mm_sub_ps(b.m_quad, a.m_quad);
  v11 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(t0), (__m128)LODWORD(t0), 0), v10), a.m_quad);
  v12 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(t1), (__m128)LODWORD(t1), 0), v10), a.m_quad);
  v13 = _mm_mul_ps(v9.m_quad, v11);
  v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, v9.m_quad), 196);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_mul_ps(v9.m_quad, v12);
  v17 = _mm_shuffle_ps(v15, v15, 177).m128_f32[0] + v15.m128_f32[0];
  v18 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, v9.m_quad), 196);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = _mm_shuffle_ps(v19, v19, 177).m128_f32[0] + v19.m128_f32[0];
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(v17 - v20)) >> 1) >= 0.0078740157 )
  {
    v21.m_quad = (__m128)this->m_extremalVector;
    v22 = _mm_mul_ps(v21.m_quad, v12);
    v23 = _mm_mul_ps(v21.m_quad, v11);
    v24 = hkaiGeometrySegmentCaster::packData(HITTYPE_EXTRUDED_EDGE, this->m_geometryIdx, leafKey);
    hkaiIntervalPartition::Interval::setFromEndpoints(
      &interval,
      v17,
      (float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
    + _mm_shuffle_ps(v23, v23, 170).m128_f32[0],
      v20,
      (float)(_mm_shuffle_ps(v22, v22, 85).m128_f32[0] + _mm_shuffle_ps(v22, v22, 0).m128_f32[0])
    + _mm_shuffle_ps(v22, v22, 170).m128_f32[0],
      v24);
    hkaiIntervalPartition::unionOne<1>(&this->m_extremalPartition, &interval);
  }
  return 1i64;
}

// File Line: 601
// RVA: 0x12E4100
hkaiGeometrySegmentCaster::AccelerationData *__fastcall hkaiGeometrySegmentCaster::buildAccelerationData(
        hkGeometry *geometry,
        hkBitField *mask,
        hkBool supportExtrusion)
{
  hkGeometry *v3; // rsi
  _QWORD **Value; // rax
  __int64 v6; // rax
  __int64 v7; // r14
  _QWORD **v8; // rax
  hkcdDynamicAabbTree *v9; // rax
  hkcdDynamicAabbTree *v10; // rax
  hkcdDynamicAabbTree *v11; // rdi
  hkReferencedObject *v12; // rcx
  __int64 m_size; // rbx
  __int64 v14; // r15
  int v15; // edi
  unsigned int v16; // ebx
  unsigned int v17; // esi
  __int64 v18; // r14
  __int64 v19; // r12
  hkGeometry::Triangle *m_data; // rcx
  hkVector4f *v21; // rdx
  __m128 m_quad; // xmm3
  __m128 v23; // xmm0
  __int64 m_c; // rax
  hkcdDynamicAabbTree *v25; // rcx
  __m128 v26; // xmm2
  unsigned int v27; // ebx
  __int64 v28; // rsi
  __int64 v29; // rdi
  hkGeometry::Triangle *v30; // rcx
  hkVector4f *v31; // rdx
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __int64 v34; // rax
  hkcdDynamicAabbTree *v35; // rcx
  __m128 v36; // xmm2
  int v37; // edx
  unsigned __int64 v38; // r8
  int v39; // r9d
  __int64 v40; // r14
  hkGeometry::Triangle *v41; // rsi
  int m_b; // ebx
  int m_a; // edi
  int v44; // r10d
  int v45; // r11d
  int v46; // ecx
  _DWORD *v47; // rdx
  int v48; // eax
  int v49; // ebx
  int v50; // r10d
  int v51; // edx
  int v52; // edi
  int v53; // r9d
  int v54; // r11d
  int v55; // ecx
  _DWORD *v56; // rdx
  int v57; // eax
  int v58; // ebx
  int v59; // r10d
  int v60; // r9d
  int v61; // edi
  int v62; // r9d
  int v63; // r11d
  int v64; // eax
  _DWORD *v65; // rdx
  int v66; // r15d
  unsigned int v67; // esi
  __int64 v68; // r11
  __int64 v69; // r10
  signed int *v70; // r14
  signed int v71; // ebx
  unsigned int v72; // edi
  int v73; // r10d
  int v74; // r11d
  int v75; // ecx
  _DWORD *v76; // rdx
  int v77; // eax
  signed int v78; // ebx
  int v79; // r10d
  int v80; // edx
  unsigned int v81; // edi
  int v82; // r9d
  int v83; // r11d
  int v84; // ecx
  _DWORD *v85; // rdx
  int v86; // eax
  signed int v87; // ebx
  int v88; // r10d
  int v89; // edx
  unsigned int v90; // edi
  int v91; // r9d
  int v92; // r11d
  int v93; // ecx
  _DWORD *v94; // rdx
  int v95; // r10d
  int v96; // eax
  int v97; // eax
  _QWORD **v98; // rax
  hkcdDynamicAabbTree *v99; // rax
  hkcdDynamicAabbTree *v100; // rax
  hkcdDynamicAabbTree *v101; // rbx
  hkReferencedObject *v102; // rcx
  int v103; // r8d
  unsigned __int64 v104; // rax
  int v105; // r9d
  int v106; // edx
  __int64 i; // rcx
  int v108; // edi
  hkVector4f *v109; // rcx
  unsigned int v110; // r8d
  __int64 v111; // rbx
  __m128 v112; // xmm2
  __m128 v113; // xmm1
  hkcdDynamicAabbTree *v114; // rcx
  _QWORD *v115; // rdx
  int v116; // r9d
  int v117; // r9d
  int v118; // edx
  __int64 j; // rcx
  hkReferencedObject *v120; // rcx
  hkAabb aabb; // [rsp+30h] [rbp-69h] BYREF
  __int64 v123; // [rsp+50h] [rbp-49h]
  unsigned __int64 v124; // [rsp+58h] [rbp-41h]
  unsigned __int64 v125; // [rsp+60h] [rbp-39h]
  __int64 v126; // [rsp+68h] [rbp-31h]
  hkResult v127; // [rsp+70h] [rbp-29h] BYREF
  unsigned __int64 v128; // [rsp+74h] [rbp-25h]
  unsigned __int64 v129; // [rsp+7Ch] [rbp-1Dh]
  __int64 v130; // [rsp+88h] [rbp-11h]
  hkAabb v131; // [rsp+90h] [rbp-9h] BYREF
  hkResult result; // [rsp+108h] [rbp+6Fh] BYREF
  char m_bool; // [rsp+110h] [rbp+77h]
  hkResult v135; // [rsp+118h] [rbp+7Fh] BYREF

  m_bool = supportExtrusion.m_bool;
  v3 = geometry;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v7 = v6;
  v126 = v6;
  if ( v6 )
  {
    *(_DWORD *)(v6 + 8) = 0x1FFFF;
    *(_QWORD *)v6 = &hkaiGeometrySegmentCaster::AccelerationData::`vftable;
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 24) = 0i64;
    *(_DWORD *)(v6 + 32) = 0;
    *(_DWORD *)(v6 + 36) = 0x80000000;
    *(_QWORD *)(v6 + 40) = 0i64;
  }
  else
  {
    v7 = 0i64;
    v126 = 0i64;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 32i64);
  if ( v9 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v9);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = *(hkReferencedObject **)(v7 + 16);
  if ( v12 && v12 != v11 )
    hkReferencedObject::removeReference(v12);
  *(_QWORD *)(v7 + 16) = v11;
  m_size = v3->m_triangles.m_size;
  hkcdDynamicAabbTree::reserveLeaves(v11, &result, v3->m_triangles.m_size);
  v14 = m_size;
  v123 = m_size;
  if ( mask )
  {
    v15 = 0;
    if ( mask->m_storage.m_numBits <= 0 )
      v16 = 0;
    else
      v16 = *mask->m_storage.m_words.m_data;
    result.m_enum = v16;
    v17 = 0;
    if ( v14 <= 0 )
      goto LABEL_28;
    v18 = 0i64;
    v19 = v126;
    do
    {
      if ( (result.m_enum & 1) != 0 )
      {
        m_data = geometry->m_triangles.m_data;
        v21 = geometry->m_vertices.m_data;
        m_quad = v21[m_data[v18].m_a].m_quad;
        v23 = v21[m_data[v18].m_b].m_quad;
        m_c = m_data[v18].m_c;
        v25 = *(hkcdDynamicAabbTree **)(v19 + 16);
        v26 = v21[m_c].m_quad;
        aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(m_quad, v23), v26);
        aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(m_quad, v23), v26);
        hkcdDynamicAabbTree::insert(v25, &aabb, v17);
      }
      if ( (++v15 & 0x1F) != 0 || v15 >= mask->m_storage.m_numBits )
        v16 >>= 1;
      else
        v16 = mask->m_storage.m_words.m_data[(__int64)v15 >> 5];
      ++v17;
      ++v18;
      result.m_enum = v16;
      --v14;
    }
    while ( v14 );
    v7 = v126;
  }
  else
  {
    v27 = 0;
    if ( v14 <= 0 )
      goto LABEL_29;
    v28 = v14;
    v29 = 0i64;
    do
    {
      v30 = geometry->m_triangles.m_data;
      v31 = geometry->m_vertices.m_data;
      v32 = v31[v30[v29].m_a].m_quad;
      v33 = v31[v30[v29].m_b].m_quad;
      v34 = v30[v29].m_c;
      v35 = *(hkcdDynamicAabbTree **)(v7 + 16);
      v36 = v31[v34].m_quad;
      aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(v32, v33), v36);
      aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(v32, v33), v36);
      hkcdDynamicAabbTree::insert(v35, &aabb, v27++);
      ++v29;
      --v28;
    }
    while ( v28 );
  }
  v14 = v123;
LABEL_28:
  v3 = geometry;
LABEL_29:
  hkcdDynamicAabbTree::rebuild(*(hkcdDynamicAabbTree **)(v7 + 16));
  if ( m_bool )
  {
    v37 = 0;
    v38 = 0i64;
    aabb.m_min.m_quad.m128_u64[0] = 0i64;
    v39 = 0;
    aabb.m_max.m_quad.m128_i32[0] = 0;
    aabb.m_min.m_quad.m128_u64[1] = 0x8000000000000000ui64;
    if ( mask )
    {
      if ( v14 <= 0 )
      {
LABEL_120:
        v96 = *(_DWORD *)(v7 + 36) & 0x3FFFFFFF;
        if ( v96 < v39 )
        {
          v97 = 2 * v96;
          if ( v39 < v97 )
            v39 = v97;
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v7 + 24), v39, 8);
        }
        v98 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v99 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v98[11] + 8i64))(v98[11], 32i64);
        if ( v99 )
        {
          hkcdDynamicAabbTree::hkcdDynamicAabbTree(v99);
          v101 = v100;
        }
        else
        {
          v101 = 0i64;
        }
        v102 = *(hkReferencedObject **)(v7 + 40);
        if ( v102 && v102 != v101 )
          hkReferencedObject::removeReference(v102);
        v103 = aabb.m_max.m_quad.m128_i32[0];
        *(_QWORD *)(v7 + 40) = v101;
        hkcdDynamicAabbTree::reserveLeaves(v101, &result, v103);
        v104 = aabb.m_min.m_quad.m128_u64[0];
        v105 = aabb.m_min.m_quad.m128_i32[2] - 1;
        v106 = 0;
        for ( i = 0i64; i <= v105; ++v106 )
        {
          if ( *(_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8 * i) != -1 )
            break;
          ++i;
        }
        v108 = v106;
        if ( v106 <= v105 )
        {
          do
          {
            v109 = geometry->m_vertices.m_data;
            v110 = *(_DWORD *)(v7 + 32);
            v111 = *(_QWORD *)(v104 + 8i64 * v108);
            v112 = v109[(int)v111].m_quad;
            v113 = v109[SHIDWORD(v111)].m_quad;
            v114 = *(hkcdDynamicAabbTree **)(v7 + 40);
            v131.m_min.m_quad = _mm_min_ps(v112, v113);
            v131.m_max.m_quad = _mm_max_ps(v112, v113);
            hkcdDynamicAabbTree::insert(v114, &v131, v110);
            v115 = (_QWORD *)(*(_QWORD *)(v7 + 24) + 8i64 * *(int *)(v7 + 32));
            if ( v115 )
              *v115 = v111;
            v116 = aabb.m_min.m_quad.m128_i32[2];
            ++*(_DWORD *)(v7 + 32);
            v104 = aabb.m_min.m_quad.m128_u64[0];
            v117 = v116 - 1;
            v118 = v108 + 1;
            for ( j = v108 + 1; j <= v117; ++v118 )
            {
              if ( *(_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8 * j) != -1 )
                break;
              ++j;
            }
            v108 = v118;
          }
          while ( v118 <= v117 );
        }
        hkcdDynamicAabbTree::rebuild(*(hkcdDynamicAabbTree **)(v7 + 40));
        aabb.m_min.m_quad.m128_i32[2] = 0;
        if ( aabb.m_min.m_quad.m128_i32[3] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            (void *)aabb.m_min.m_quad.m128_u64[0],
            8 * aabb.m_min.m_quad.m128_i32[3]);
        return (hkaiGeometrySegmentCaster::AccelerationData *)v7;
      }
      v40 = 0i64;
      while ( 1 )
      {
        v41 = &v3->m_triangles.m_data[v40];
        m_b = v41->m_b;
        m_a = m_b;
        if ( v41->m_a < m_b )
          m_a = v41->m_a;
        if ( v41->m_a > m_b )
          m_b = v41->m_a;
        v124 = __PAIR64__(m_b, m_a);
        if ( 2 * v39 > v37 - 1 )
        {
          hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
            (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
            &result,
            2 * v37);
          v39 = aabb.m_max.m_quad.m128_i32[0];
          v37 = aabb.m_min.m_quad.m128_i32[2];
          v38 = aabb.m_min.m_quad.m128_u64[0];
        }
        v44 = v37 - 1;
        v45 = 1;
        v46 = (v37 - 1) & ((23857 * m_a) ^ (-1640531535 * m_b));
        v47 = (_DWORD *)(v38 + 8i64 * v46);
        if ( *v47 != -1 )
        {
          while ( *v47 != m_a || v47[1] != m_b )
          {
            v46 = v44 & (v46 + 1);
            v47 = (_DWORD *)(v38 + 8i64 * v46);
            if ( *v47 == -1 )
              goto LABEL_45;
          }
          v45 = 0;
        }
LABEL_45:
        aabb.m_max.m_quad.m128_i32[0] = v45 + v39;
        *(_QWORD *)(v38 + 8i64 * v46) = v124;
        v48 = v41->m_b;
        v49 = v41->m_c;
        v50 = aabb.m_max.m_quad.m128_i32[0];
        v51 = aabb.m_min.m_quad.m128_i32[2];
        v52 = v49;
        if ( v48 < v49 )
          v52 = v41->m_b;
        if ( v48 > v49 )
          v49 = v41->m_b;
        v123 = __PAIR64__(v49, v52);
        if ( 2 * aabb.m_max.m_quad.m128_i32[0] > aabb.m_min.m_quad.m128_i32[2] - 1 )
        {
          hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
            (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
            &v135,
            2 * aabb.m_min.m_quad.m128_i32[2]);
          v50 = aabb.m_max.m_quad.m128_i32[0];
          v51 = aabb.m_min.m_quad.m128_i32[2];
        }
        v53 = v51 - 1;
        v54 = 1;
        v55 = (v51 - 1) & ((23857 * v52) ^ (-1640531535 * v49));
        v56 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v55);
        if ( *v56 != -1 )
        {
          while ( *v56 != v52 || v56[1] != v49 )
          {
            v55 = v53 & (v55 + 1);
            v56 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v55);
            if ( *v56 == -1 )
              goto LABEL_57;
          }
          v54 = 0;
        }
LABEL_57:
        aabb.m_max.m_quad.m128_i32[0] = v54 + v50;
        *(_QWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v55) = v123;
        v57 = v41->m_c;
        v58 = v41->m_a;
        v59 = aabb.m_max.m_quad.m128_i32[0];
        v60 = aabb.m_min.m_quad.m128_i32[2];
        v61 = v41->m_a;
        if ( v57 < v41->m_a )
          v61 = v41->m_c;
        if ( v57 > v58 )
          v58 = v41->m_c;
        v125 = __PAIR64__(v58, v61);
        if ( 2 * aabb.m_max.m_quad.m128_i32[0] > aabb.m_min.m_quad.m128_i32[2] - 1 )
        {
          hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
            (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
            &v127,
            2 * aabb.m_min.m_quad.m128_i32[2]);
          v59 = aabb.m_max.m_quad.m128_i32[0];
          v60 = aabb.m_min.m_quad.m128_i32[2];
        }
        v62 = v60 - 1;
        v63 = 1;
        v64 = v62 & ((23857 * v61) ^ (-1640531535 * v58));
        v65 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v64);
        if ( *v65 != -1 )
        {
          while ( *v65 != v61 || v65[1] != v58 )
          {
            v64 = v62 & (v64 + 1);
            v65 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v64);
            if ( *v65 == -1 )
              goto LABEL_69;
          }
          v63 = 0;
        }
LABEL_69:
        aabb.m_max.m_quad.m128_i32[0] = v63 + v59;
        ++v40;
        *(_QWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v64) = v125;
        v39 = aabb.m_max.m_quad.m128_i32[0];
        if ( !--v14 )
          break;
        v37 = aabb.m_min.m_quad.m128_i32[2];
        v38 = aabb.m_min.m_quad.m128_u64[0];
        v3 = geometry;
      }
    }
    else
    {
      v66 = 0;
      if ( MEMORY[0x10] <= 0 )
      {
        v67 = 0;
        LODWORD(v124) = 0;
      }
      else
      {
        v67 = *(_DWORD *)MEMORY[0];
        LODWORD(v124) = *(_DWORD *)MEMORY[0];
      }
      v68 = v123;
      if ( v123 <= 0 )
        goto LABEL_120;
      v69 = 0i64;
      v130 = 0i64;
      do
      {
        if ( (v124 & 1) != 0 )
        {
          v70 = (int *)((char *)&geometry->m_triangles.m_data->m_a + v69);
          v71 = v70[1];
          v72 = v71;
          if ( *v70 < v71 )
            v72 = *v70;
          if ( *v70 > v71 )
            v71 = *v70;
          v125 = __PAIR64__(v71, v72);
          if ( 2 * v39 > v37 - 1 )
          {
            hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
              (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
              &result,
              2 * v37);
            v39 = aabb.m_max.m_quad.m128_i32[0];
            v37 = aabb.m_min.m_quad.m128_i32[2];
            v38 = aabb.m_min.m_quad.m128_u64[0];
          }
          v73 = v37 - 1;
          v74 = 1;
          v75 = (v37 - 1) & ((23857 * v72) ^ (-1640531535 * v71));
          v76 = (_DWORD *)(v38 + 8i64 * v75);
          if ( *v76 != -1 )
          {
            while ( *v76 != v72 || v76[1] != v71 )
            {
              v75 = v73 & (v75 + 1);
              v76 = (_DWORD *)(v38 + 8i64 * v75);
              if ( *v76 == -1 )
                goto LABEL_89;
            }
            v74 = 0;
          }
LABEL_89:
          aabb.m_max.m_quad.m128_i32[0] = v74 + v39;
          *(_QWORD *)(v38 + 8i64 * v75) = v125;
          v77 = v70[1];
          v78 = v70[2];
          v79 = aabb.m_max.m_quad.m128_i32[0];
          v80 = aabb.m_min.m_quad.m128_i32[2];
          v81 = v78;
          if ( v77 < v78 )
            v81 = v70[1];
          if ( v77 > v78 )
            v78 = v70[1];
          v129 = __PAIR64__(v78, v81);
          if ( 2 * aabb.m_max.m_quad.m128_i32[0] > aabb.m_min.m_quad.m128_i32[2] - 1 )
          {
            hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
              (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
              &v135,
              2 * aabb.m_min.m_quad.m128_i32[2]);
            v79 = aabb.m_max.m_quad.m128_i32[0];
            v80 = aabb.m_min.m_quad.m128_i32[2];
          }
          v82 = v80 - 1;
          v83 = 1;
          v84 = (v80 - 1) & ((23857 * v81) ^ (-1640531535 * v78));
          v85 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v84);
          if ( *v85 != -1 )
          {
            while ( *v85 != v81 || v85[1] != v78 )
            {
              v84 = v82 & (v84 + 1);
              v85 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v84);
              if ( *v85 == -1 )
                goto LABEL_101;
            }
            v83 = 0;
          }
LABEL_101:
          aabb.m_max.m_quad.m128_i32[0] = v83 + v79;
          *(_QWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v84) = v129;
          v86 = v70[2];
          v87 = *v70;
          v88 = aabb.m_max.m_quad.m128_i32[0];
          v89 = aabb.m_min.m_quad.m128_i32[2];
          v90 = *v70;
          if ( v86 < *v70 )
            v90 = v70[2];
          if ( v86 > v87 )
            v87 = v70[2];
          v128 = __PAIR64__(v87, v90);
          if ( 2 * aabb.m_max.m_quad.m128_i32[0] > aabb.m_min.m_quad.m128_i32[2] - 1 )
          {
            hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
              (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
              &v127,
              2 * aabb.m_min.m_quad.m128_i32[2]);
            v88 = aabb.m_max.m_quad.m128_i32[0];
            v89 = aabb.m_min.m_quad.m128_i32[2];
          }
          v91 = v89 - 1;
          v92 = 1;
          v93 = (v89 - 1) & ((23857 * v90) ^ (-1640531535 * v87));
          v94 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v93);
          if ( *v94 != -1 )
          {
            while ( *v94 != v90 || v94[1] != v87 )
            {
              v93 = v91 & (v93 + 1);
              v94 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v93);
              if ( *v94 == -1 )
                goto LABEL_113;
            }
            v92 = 0;
          }
LABEL_113:
          v95 = v92 + v88;
          v68 = v123;
          aabb.m_max.m_quad.m128_i32[0] = v95;
          v69 = v130;
          *(_QWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v93) = v128;
          v39 = aabb.m_max.m_quad.m128_i32[0];
          v37 = aabb.m_min.m_quad.m128_i32[2];
          v38 = aabb.m_min.m_quad.m128_u64[0];
        }
        if ( (++v66 & 0x1F) != 0 || v66 >= MEMORY[0x10] )
          v67 >>= 1;
        else
          v67 = *(_DWORD *)(MEMORY[0] + 4 * ((__int64)v66 >> 5));
        v69 += 16i64;
        --v68;
        LODWORD(v124) = v67;
        v123 = v68;
        v130 = v69;
      }
      while ( v68 );
    }
    v7 = v126;
    goto LABEL_120;
  }
  v120 = *(hkReferencedObject **)(v7 + 40);
  if ( v120 )
    hkReferencedObject::removeReference(v120);
  *(_QWORD *)(v7 + 40) = 0i64;
  return (hkaiGeometrySegmentCaster::AccelerationData *)v7;
}v120);
  *(_QWORD *)(v7 + 40) = 0i64;
  return (hkaiGeometrySegmentCaster::AccelerationData *)v7;
}

// File Line: 701
// RVA: 0x12E49E0
void __fastcall hkaiGeometrySegmentCaster::hkaiGeometrySegmentCaster(hkaiGeometrySegmentCaster *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiGeometrySegmentCaster::`vftable;
  this->m_geometries.m_capacityAndFlags = 0x80000000;
  this->m_geometries.m_data = 0i64;
  this->m_geometries.m_size = 0;
}

// File Line: 706
// RVA: 0x12E4A10
void __fastcall hkaiGeometrySegmentCaster::~hkaiGeometrySegmentCaster(hkaiGeometrySegmentCaster *this)
{
  int m_size; // eax
  hkaiGeometrySegmentCaster::Geometry *m_data; // rcx
  int v4; // eax
  __int64 v5; // rdi
  hkReferencedObject **p_m_pntr; // rbx
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaiGeometrySegmentCaster::`vftable;
  m_size = this->m_geometries.m_size;
  m_data = this->m_geometries.m_data;
  v4 = m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    p_m_pntr = &m_data[v4].m_accelerationData.m_pntr;
    do
    {
      if ( *p_m_pntr )
        hkReferencedObject::removeReference(*p_m_pntr);
      *p_m_pntr = 0i64;
      p_m_pntr -= 2;
      --v5;
    }
    while ( v5 >= 0 );
  }
  m_capacityAndFlags = this->m_geometries.m_capacityAndFlags;
  this->m_geometries.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_geometries.m_data,
      16 * m_capacityAndFlags);
  this->m_geometries.m_data = 0i64;
  this->m_geometries.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 710
// RVA: 0x12E4AD0
void __fastcall hkaiGeometrySegmentCaster::addGeometry(
        hkaiGeometrySegmentCaster *this,
        hkGeometry *geometry,
        hkaiGeometrySegmentCaster::AccelerationData *accelerationData)
{
  hkArray<hkaiGeometrySegmentCaster::Geometry,hkContainerHeapAllocator> *p_m_geometries; // rdi
  __int64 v6; // rax
  hkaiGeometrySegmentCaster::Geometry *v7; // rbx
  hkReferencedObject *m_pntr; // rcx

  p_m_geometries = &this->m_geometries;
  if ( this->m_geometries.m_size == (this->m_geometries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_geometries->m_data, 16);
  v6 = (__int64)&p_m_geometries->m_data[p_m_geometries->m_size];
  if ( v6 )
    *(_QWORD *)(v6 + 8) = 0i64;
  v7 = &p_m_geometries->m_data[p_m_geometries->m_size++];
  v7->m_geometry = geometry;
  if ( accelerationData )
    hkReferencedObject::addReference(accelerationData);
  m_pntr = v7->m_accelerationData.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  v7->m_accelerationData.m_pntr = accelerationData;
}

// File Line: 722
// RVA: 0x12E4B80
void __fastcall hkaiGeometrySegmentCaster::castSegment(
        hkaiGeometrySegmentCaster *this,
        hkVector4f *leftStart,
        hkVector4f *rightStart,
        hkVector4f *displacement,
        hkaiIntervalPartition *partition)
{
  __int64 m_size; // rsi
  int v6; // edi
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  hkVector4f v13; // xmm0
  __int64 v14; // rbx
  __m128 m_quad; // xmm1
  hkGeometry *m_geometry; // rcx
  __m128 v17; // xmm0
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-B8h] BYREF
  __m128 v19; // [rsp+30h] [rbp-A8h]
  __m128 v20; // [rsp+40h] [rbp-98h]
  __m128 v21; // [rsp+50h] [rbp-88h]
  hkGeometry *v22; // [rsp+60h] [rbp-78h]
  int v23; // [rsp+68h] [rbp-70h]
  hkaiIntervalPartition v24; // [rsp+70h] [rbp-68h] BYREF
  hkaiIntervalPartition other; // [rsp+80h] [rbp-58h] BYREF
  hkAabb aabb; // [rsp+90h] [rbp-48h] BYREF

  m_size = this->m_geometries.m_size;
  v6 = 0;
  v11 = _mm_add_ps(displacement->m_quad, leftStart->m_quad);
  v12 = _mm_add_ps(rightStart->m_quad, displacement->m_quad);
  v13.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(leftStart->m_quad, rightStart->m_quad), v11), v12);
  aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(leftStart->m_quad, rightStart->m_quad), v11), v12);
  aabb.m_min = (hkVector4f)v13.m_quad;
  if ( m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      m_quad = rightStart->m_quad;
      m_geometry = this->m_geometries.m_data[v14].m_geometry;
      v19 = leftStart->m_quad;
      v17 = displacement->m_quad;
      v22 = m_geometry;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace::GeometryCastSegmentQuery::`vftable;
      v23 = v6;
      v20 = m_quad;
      v21 = v17;
      hkaiIntervalPartition::hkaiIntervalPartition(&v24);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiIntervalPartition::swap(partition, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      hkcdDynamicAabbTree::queryAabb(
        this->m_geometries.m_data[v14].m_accelerationData.m_pntr->m_faceTree.m_pntr,
        &aabb,
        &collector);
      hkaiIntervalPartition::swap(partition, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      other.m_intervals.m_capacityAndFlags = 0x80000000;
      other.m_intervals.m_data = 0i64;
      v24.m_intervals.m_size = 0;
      if ( v24.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v24.m_intervals.m_data,
          20 * (v24.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      ++v6;
      ++v14;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 747
// RVA: 0x12E4D60
void __fastcall hkaiGeometrySegmentCaster::castSegmentExtruded(
        hkaiGeometrySegmentCaster *this,
        hkVector4f *leftStart,
        hkVector4f *rightStart,
        hkVector4f *displacement,
        hkVector4f *extrusion,
        hkaiIntervalPartition *partition)
{
  __int64 m_size; // rsi
  int v7; // edi
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  __m128 v15; // xmm2
  __int64 v16; // rbx
  __m128 m_quad; // xmm1
  hkGeometry *m_geometry; // rcx
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  hkaiGeometrySegmentCaster::Geometry *m_data; // rax
  __m128 v22; // xmm1
  __int64 v23; // rcx
  hkaiGeometrySegmentCaster::AccelerationData *m_pntr; // rdx
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-E0h] BYREF
  __m128 v26; // [rsp+30h] [rbp-D0h]
  __m128 v27; // [rsp+40h] [rbp-C0h]
  __m128 v28; // [rsp+50h] [rbp-B0h]
  __m128 v29; // [rsp+60h] [rbp-A0h]
  __m128 v30; // [rsp+70h] [rbp-90h]
  hkGeometry *v31; // [rsp+80h] [rbp-80h]
  int v32; // [rsp+88h] [rbp-78h]
  hkaiIntervalPartition v33; // [rsp+90h] [rbp-70h] BYREF
  hkaiIntervalPartition other; // [rsp+A0h] [rbp-60h] BYREF
  hkcdAabbTreeQueries::AabbCollector v35; // [rsp+B0h] [rbp-50h] BYREF
  __m128 v36; // [rsp+C0h] [rbp-40h]
  __m128 v37; // [rsp+D0h] [rbp-30h]
  hkVector4f v38; // [rsp+100h] [rbp+0h]
  __m128 v39; // [rsp+110h] [rbp+10h]
  __int64 v40; // [rsp+120h] [rbp+20h]
  hkArray<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator> *p_m_edges; // [rsp+128h] [rbp+28h]
  int v42; // [rsp+130h] [rbp+30h]
  hkaiIntervalPartition v43; // [rsp+138h] [rbp+38h] BYREF
  hkaiIntervalPartition v44; // [rsp+148h] [rbp+48h] BYREF
  hkAabb aabb; // [rsp+160h] [rbp+60h] BYREF
  hkVector4f *v46; // [rsp+1C8h] [rbp+C8h]

  v46 = displacement;
  m_size = this->m_geometries.m_size;
  v7 = 0;
  v11 = _mm_add_ps(displacement->m_quad, leftStart->m_quad);
  v12 = _mm_add_ps(rightStart->m_quad, displacement->m_quad);
  v13 = _mm_min_ps(_mm_min_ps(leftStart->m_quad, rightStart->m_quad), v11);
  v14 = _mm_max_ps(_mm_max_ps(_mm_max_ps(leftStart->m_quad, rightStart->m_quad), v11), v12);
  v15 = _mm_min_ps(extrusion->m_quad, aabbOut.m_quad);
  aabb.m_min.m_quad = _mm_sub_ps(_mm_min_ps(v13, v12), _mm_max_ps(extrusion->m_quad, aabbOut.m_quad));
  aabb.m_max.m_quad = _mm_sub_ps(v14, v15);
  if ( m_size > 0 )
  {
    v16 = 0i64;
    do
    {
      m_quad = rightStart->m_quad;
      m_geometry = this->m_geometries.m_data[v16].m_geometry;
      v26 = leftStart->m_quad;
      v19 = displacement->m_quad;
      v31 = m_geometry;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace::DoubledGeometryCastSegmentQuery::`vftable;
      v32 = v7;
      v27 = m_quad;
      v30 = v19;
      hkaiIntervalPartition::hkaiIntervalPartition(&v33);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      v20 = _mm_sub_ps(rightStart->m_quad, extrusion->m_quad);
      v28 = _mm_sub_ps(leftStart->m_quad, extrusion->m_quad);
      v29 = v20;
      hkaiIntervalPartition::swap(partition, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      hkcdDynamicAabbTree::queryAabb(
        this->m_geometries.m_data[v16].m_accelerationData.m_pntr->m_faceTree.m_pntr,
        &aabb,
        &collector);
      m_data = this->m_geometries.m_data;
      v22 = rightStart->m_quad;
      v23 = (__int64)m_data[v16].m_geometry;
      m_pntr = m_data[v16].m_accelerationData.m_pntr;
      v36 = leftStart->m_quad;
      v37 = v22;
      v35.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace::GeometryExtrusionCastSegmentQuery::`vftable;
      v40 = v23;
      v42 = v7;
      v38.m_quad = v46->m_quad;
      v39 = extrusion->m_quad;
      p_m_edges = &m_pntr->m_edges;
      hkaiIntervalPartition::hkaiIntervalPartition(&v43);
      hkaiIntervalPartition::hkaiIntervalPartition(&v44);
      hkaiIntervalPartition::swap(&v44, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      hkcdDynamicAabbTree::queryAabb(
        this->m_geometries.m_data[v16].m_accelerationData.m_pntr->m_edgeTree.m_pntr,
        &aabb,
        &v35);
      hkaiIntervalPartition::swap(partition, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v44);
      v44.m_intervals.m_size = 0;
      if ( v44.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v44.m_intervals.m_data,
          20 * (v44.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v44.m_intervals.m_data = 0i64;
      v44.m_intervals.m_capacityAndFlags = 0x80000000;
      v43.m_intervals.m_size = 0;
      if ( v43.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v43.m_intervals.m_data,
          20 * (v43.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v43.m_intervals.m_data = 0i64;
      v43.m_intervals.m_capacityAndFlags = 0x80000000;
      v35.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      other.m_intervals.m_data = 0i64;
      other.m_intervals.m_capacityAndFlags = 0x80000000;
      v33.m_intervals.m_size = 0;
      if ( v33.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v33.m_intervals.m_data,
          20 * (v33.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      displacement = v46;
      ++v7;
      ++v16;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 811
// RVA: 0x12E5060
void __fastcall hkaiGeometrySegmentCaster::castSegmentExtrudedEdges(
        hkaiGeometrySegmentCaster *this,
        hkVector4f *leftStart,
        hkVector4f *rightStart,
        hkVector4f *displacement,
        hkVector4f *extrusion,
        hkaiIntervalPartition *partition)
{
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v6; // rbx
  __int64 m_size; // rsi
  int v10; // edi
  __int128 *v11; // r8
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __m128 *v17; // r9
  __m128 v18; // xmm2
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v19; // r14
  __int64 v20; // rbx
  hkaiGeometrySegmentCaster::Geometry *m_data; // rax
  __m128 m_quad; // xmm1
  hkGeometry *m_geometry; // rcx
  hkaiGeometrySegmentCaster::AccelerationData *m_pntr; // rdx
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-81h] BYREF
  __int128 v28; // [rsp+30h] [rbp-71h]
  _QWORD v29[7]; // [rsp+40h] [rbp-61h]
  int v30; // [rsp+78h] [rbp-29h]
  hkaiIntervalPartition v31; // [rsp+80h] [rbp-21h] BYREF
  hkaiIntervalPartition v32; // [rsp+90h] [rbp-11h] BYREF
  hkAabb aabb; // [rsp+A8h] [rbp+7h] BYREF
  __int128 *v34; // [rsp+100h] [rbp+5Fh]
  __m128 *retaddr; // [rsp+118h] [rbp+77h]

  m_size = this->m_geometries.m_size;
  v10 = 0;
  v11 = (__int128 *)leftStart;
  v13 = _mm_add_ps(displacement->m_quad, leftStart->m_quad);
  v14 = _mm_add_ps(rightStart->m_quad, displacement->m_quad);
  v15 = _mm_min_ps(_mm_min_ps(leftStart->m_quad, rightStart->m_quad), v13);
  v16 = _mm_max_ps(_mm_max_ps(leftStart->m_quad, rightStart->m_quad), v13);
  v17 = retaddr;
  v18 = _mm_min_ps(*retaddr, aabbOut.m_quad);
  aabb.m_min.m_quad = _mm_sub_ps(_mm_min_ps(v15, v14), _mm_max_ps(*retaddr, aabbOut.m_quad));
  aabb.m_max.m_quad = _mm_sub_ps(_mm_max_ps(v16, v14), v18);
  if ( m_size > 0 )
  {
    v19 = v6;
    v20 = 0i64;
    do
    {
      m_data = this->m_geometries.m_data;
      m_quad = rightStart->m_quad;
      m_geometry = m_data[v20].m_geometry;
      m_pntr = m_data[v20].m_accelerationData.m_pntr;
      v28 = *v11;
      v29[5] = m_geometry;
      v25 = displacement->m_quad;
      *(__m128 *)v29 = m_quad;
      v26 = *v17;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace::GeometryExtrusionCastSegmentQuery::`vftable;
      v30 = v10;
      v29[6] = &m_pntr->m_edges;
      *(__m128 *)&v29[1] = v25;
      *(__m128 *)&v29[3] = v26;
      hkaiIntervalPartition::hkaiIntervalPartition(&v31);
      hkaiIntervalPartition::hkaiIntervalPartition(&v32);
      hkaiIntervalPartition::swap(&v32, v19);
      hkcdDynamicAabbTree::queryAabb(
        this->m_geometries.m_data[v20].m_accelerationData.m_pntr->m_edgeTree.m_pntr,
        &aabb,
        &collector);
      hkaiIntervalPartition::swap(
        (hkaiIntervalPartition *)v19,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v32);
      v32.m_intervals.m_size = 0;
      if ( v32.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v32.m_intervals.m_data,
          20 * (v32.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v32.m_intervals.m_capacityAndFlags = 0x80000000;
      v32.m_intervals.m_data = 0i64;
      v31.m_intervals.m_size = 0;
      if ( v31.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v31.m_intervals.m_data,
          20 * (v31.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v11 = v34;
      v17 = retaddr;
      ++v10;
      ++v20;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 864
// RVA: 0x12E5250
// bad sp value at call has been detected, the output may be wrong!
void __fastcall hkaiGeometrySegmentCaster::turnSegment(
        hkaiGeometrySegmentCaster *this,
        hkVector4f *leftStart,
        hkVector4f *rightStart,
        hkVector4f *leftEnd,
        hkVector4f *rightEnd,
        hkaiIntervalPartition *partition)
{
  hkaiIntervalPartition *v6; // rbx
  __int64 m_size; // rsi
  int v9; // edi
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 *v14; // r8
  __m128 v15; // xmm1
  hkaiIntervalPartition *v16; // r14
  __int64 v17; // rbx
  __m128 m_quad; // xmm1
  hkGeometry *m_geometry; // rcx
  __m128 v20; // xmm0
  __int128 v21; // xmm1
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+0h] [rbp-79h] BYREF
  __m128 v23; // [rsp+10h] [rbp-69h]
  __m128 v24; // [rsp+20h] [rbp-59h]
  __m128 v25; // [rsp+30h] [rbp-49h]
  __int128 v26; // [rsp+40h] [rbp-39h]
  hkGeometry *v27; // [rsp+50h] [rbp-29h]
  int v28; // [rsp+58h] [rbp-21h]
  hkaiIntervalPartition v29; // [rsp+60h] [rbp-19h] BYREF
  hkaiIntervalPartition other; // [rsp+70h] [rbp-9h] BYREF
  hkAabb aabb; // [rsp+80h] [rbp+7h] BYREF
  hkVector4f *v32; // [rsp+D8h] [rbp+5Fh]
  __m128 *retaddr; // [rsp+F0h] [rbp+77h]

  m_size = this->m_geometries.m_size;
  v9 = 0;
  v12 = _mm_max_ps(leftStart->m_quad, rightStart->m_quad);
  v13 = _mm_min_ps(leftStart->m_quad, rightStart->m_quad);
  v14 = retaddr;
  v15 = _mm_min_ps(v13, leftEnd->m_quad);
  aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(v12, leftEnd->m_quad), *retaddr);
  aabb.m_min.m_quad = _mm_min_ps(v15, *retaddr);
  if ( m_size > 0 )
  {
    v16 = v6;
    v17 = 0i64;
    do
    {
      m_quad = rightStart->m_quad;
      m_geometry = this->m_geometries.m_data[v17].m_geometry;
      v23 = leftStart->m_quad;
      v20 = leftEnd->m_quad;
      v27 = m_geometry;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace::GeometryTurnedSegmentQuery::`vftable;
      v28 = v9;
      v24 = m_quad;
      v21 = (__int128)*v14;
      v25 = v20;
      v26 = v21;
      hkaiIntervalPartition::hkaiIntervalPartition(&v29);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiIntervalPartition::swap(v16, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      hkcdDynamicAabbTree::queryAabb(
        this->m_geometries.m_data[v17].m_accelerationData.m_pntr->m_faceTree.m_pntr,
        &aabb,
        &collector);
      hkaiIntervalPartition::swap(v16, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      other.m_intervals.m_capacityAndFlags = 0x80000000;
      other.m_intervals.m_data = 0i64;
      v29.m_intervals.m_size = 0;
      if ( v29.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v29.m_intervals.m_data,
          20 * (v29.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      leftStart = v32;
      v14 = retaddr;
      ++v9;
      ++v17;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 886
// RVA: 0x12E5410
void __fastcall hkaiGeometrySegmentCaster::turnSegmentExtruded(
        hkaiGeometrySegmentCaster *this,
        hkVector4f *leftStart,
        hkVector4f *rightStart,
        hkVector4f *leftEnd,
        hkVector4f *rightEnd,
        hkVector4f *extrusion,
        hkaiIntervalPartition *partition)
{
  __m128 *v7; // rbx
  __int64 m_size; // rsi
  __m128 m_quad; // xmm3
  __m128 *v11; // rdx
  int v12; // edi
  hkVector4f v16; // xmm4
  __int64 v17; // rbx
  __m128 v18; // xmm1
  hkGeometry *m_geometry; // rcx
  __m128 v20; // xmm0
  __int128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  __m128 v26; // xmm1
  hkaiGeometrySegmentCaster::AccelerationData *m_pntr; // rdx
  __m128 v28; // xmm0
  hkcdAabbTreeQueries::AabbCollector v29; // [rsp+20h] [rbp-B8h] BYREF
  __m128 v30; // [rsp+30h] [rbp-A8h]
  __m128 v31; // [rsp+40h] [rbp-98h]
  __m128 v32; // [rsp+50h] [rbp-88h]
  __m128 v33; // [rsp+60h] [rbp-78h]
  hkaiIntervalPartition v34; // [rsp+70h] [rbp-68h] BYREF
  hkaiIntervalPartition v35; // [rsp+80h] [rbp-58h] BYREF
  hkAabb aabb; // [rsp+98h] [rbp-40h] BYREF
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+B8h] [rbp-20h] BYREF
  __m128 v38; // [rsp+C8h] [rbp-10h]
  __m128 v39; // [rsp+D8h] [rbp+0h]
  __m128 v40; // [rsp+E8h] [rbp+10h]
  __int128 v41; // [rsp+F8h] [rbp+20h]
  __m128 v42; // [rsp+108h] [rbp+30h]
  __m128 v43; // [rsp+118h] [rbp+40h]
  __m128 v44; // [rsp+128h] [rbp+50h]
  __m128 v45; // [rsp+138h] [rbp+60h]
  hkGeometry *v46; // [rsp+148h] [rbp+70h]
  hkaiIntervalPartition v47; // [rsp+150h] [rbp+78h] BYREF
  int v48; // [rsp+160h] [rbp+88h]
  hkaiIntervalPartition other; // [rsp+168h] [rbp+90h] BYREF
  __m128 *retaddr; // [rsp+1C8h] [rbp+F0h]
  __m128 *v51; // [rsp+1D0h] [rbp+F8h]
  __m128 *v52; // [rsp+1D0h] [rbp+F8h]
  hkaiIntervalPartition *v53; // [rsp+1D8h] [rbp+100h]

  m_size = this->m_geometries.m_size;
  m_quad = leftStart->m_quad;
  v11 = retaddr;
  v12 = 0;
  v16.m_quad = _mm_sub_ps(
                 _mm_max_ps(_mm_max_ps(_mm_max_ps(m_quad, rightStart->m_quad), leftEnd->m_quad), *retaddr),
                 _mm_min_ps(*v51, aabbOut.m_quad));
  aabb.m_min.m_quad = _mm_sub_ps(
                        _mm_min_ps(_mm_min_ps(_mm_min_ps(m_quad, rightStart->m_quad), leftEnd->m_quad), *retaddr),
                        _mm_max_ps(*v51, aabbOut.m_quad));
  aabb.m_max = (hkVector4f)v16.m_quad;
  if ( m_size > 0 )
  {
    v52 = v7;
    v17 = 0i64;
    do
    {
      v18 = rightStart->m_quad;
      m_geometry = this->m_geometries.m_data[v17].m_geometry;
      v38 = leftStart->m_quad;
      v20 = leftEnd->m_quad;
      v46 = m_geometry;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace::DoubledGeometryTurnedSegmentQuery::`vftable;
      v39 = v18;
      v21 = (__int128)*v11;
      v40 = v20;
      v41 = v21;
      hkaiIntervalPartition::hkaiIntervalPartition(&v47);
      v48 = v12;
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      v22 = *v52;
      v23 = _mm_sub_ps(rightStart->m_quad, *v52);
      v42 = _mm_sub_ps(leftStart->m_quad, *v52);
      v24 = leftEnd->m_quad;
      v43 = v23;
      v25 = *retaddr;
      v44 = _mm_sub_ps(v24, v22);
      v45 = _mm_sub_ps(v25, v22);
      hkaiIntervalPartition::swap(v53, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      hkcdDynamicAabbTree::queryAabb(
        this->m_geometries.m_data[v17].m_accelerationData.m_pntr->m_faceTree.m_pntr,
        &aabb,
        &collector);
      v26 = rightStart->m_quad;
      m_pntr = this->m_geometries.m_data[v17].m_accelerationData.m_pntr;
      v30 = leftStart->m_quad;
      v28 = leftEnd->m_quad;
      v31 = v26;
      v29.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace::GeometryExtrusionTurnedSegmentQuery::`vftable;
      v32 = v28;
      v33.m128_i32[2] = v12;
      v33 = *retaddr;
      v34 = (hkaiIntervalPartition)*v52;
      v33.m128_u64[0] = (unsigned __int64)&m_pntr->m_edges;
      hkaiIntervalPartition::hkaiIntervalPartition(&v34);
      hkaiIntervalPartition::hkaiIntervalPartition(&v35);
      hkaiIntervalPartition::swap(&v35, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      hkcdDynamicAabbTree::queryAabb(
        this->m_geometries.m_data[v17].m_accelerationData.m_pntr->m_edgeTree.m_pntr,
        &aabb,
        &v29);
      hkaiIntervalPartition::swap(v53, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v35);
      v35.m_intervals.m_size = 0;
      if ( v35.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v35.m_intervals.m_data,
          20 * (v35.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v35.m_intervals.m_data = 0i64;
      v35.m_intervals.m_capacityAndFlags = 0x80000000;
      v34.m_intervals.m_size = 0;
      if ( v34.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v34.m_intervals.m_data,
          20 * (v34.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v34.m_intervals.m_data = 0i64;
      v34.m_intervals.m_capacityAndFlags = 0x80000000;
      v29.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      other.m_intervals.m_data = 0i64;
      other.m_intervals.m_capacityAndFlags = 0x80000000;
      v47.m_intervals.m_size = 0;
      if ( v47.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v47.m_intervals.m_data,
          20 * (v47.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v11 = retaddr;
      ++v12;
      ++v17;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 959
// RVA: 0x12E5770
void __fastcall hkaiGeometrySegmentCaster::findExtremalProfile(
        hkaiGeometrySegmentCaster *this,
        hkArrayBase<hkVector4f> *clippingPlanes,
        hkVector4f *left,
        hkVector4f *right,
        __m128i *extremalVector,
        hkVector4f *uVector,
        hkVector4f *vVector,
        hkaiIntervalPartition *uPartition,
        hkaiIntervalPartition *vPartition)
{
  __int128 *v9; // rdi
  int m_size; // ebx
  hkVector4f *m_data; // rdi
  hkgpConvexHull::BuildConfig *v16; // rax
  __m128i *v17; // rbx
  __m128i *v18; // r13
  __m128i v19; // xmm8
  __m128 v20; // xmm5
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm11
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm11
  __m128 v32; // xmm2
  __m128 v33; // xmm11
  __int64 v34; // rsi
  int v35; // edi
  __int64 v36; // rbx
  hkaiGeometrySegmentCaster::Geometry *v37; // rax
  __int64 m_geometry; // rcx
  hkaiGeometrySegmentCaster::AccelerationData *m_pntr; // rdx
  __m128 m_quad; // xmm3
  hkVector4f v41; // xmm1
  hkVector4f v42; // xmm2
  __m128 v43; // xmm0
  hkaiIntervalPartition *v44; // rbx
  hkaiIntervalPartition *v45; // rdi
  int v46; // esi
  int i; // r15d
  hkaiIntervalPartition::Interval *Interval; // rax
  float m_leftX; // xmm10_4
  float m_rightX; // xmm9_4
  float m_offset; // xmm1_4
  hkaiGeometrySegmentCaster::Geometry *v52; // rcx
  hkaiGeometrySegmentCaster::ExtrudedEdge *v53; // rdx
  hkVector4f *v54; // rcx
  __m128 v55; // xmm7
  __m128 v56; // xmm1
  __m128 v57; // xmm6
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  __m128 v60; // xmm1
  __m128 v61; // xmm4
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  __m128 v64; // xmm3
  __m128 v65; // xmm5
  __m128 v66; // xmm8
  __m128 v67; // xmm7
  __m128 v68; // xmm6
  hkaiIntervalPartition other; // [rsp+30h] [rbp-C0h] BYREF
  hkgpConvexHull::BuildConfig v70; // [rsp+40h] [rbp-B0h] BYREF
  unsigned int data; // [rsp+50h] [rbp-A0h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+60h] [rbp-90h] BYREF
  hkgpConvexHull *v73; // [rsp+68h] [rbp-88h]
  __int128 v74; // [rsp+70h] [rbp-80h]
  __int64 v75; // [rsp+80h] [rbp-70h]
  hkArray<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator> *p_m_edges; // [rsp+88h] [rbp-68h]
  int v77; // [rsp+90h] [rbp-60h]
  hkaiIntervalPartition v78; // [rsp+98h] [rbp-58h] BYREF
  hkMatrix4f out; // [rsp+B0h] [rbp-40h] BYREF
  hkgpConvexHull v80; // [rsp+F0h] [rbp+0h] BYREF
  hkMatrix4f m; // [rsp+120h] [rbp+30h] BYREF
  hkAabb result; // [rsp+160h] [rbp+70h] BYREF
  hkaiGeometrySegmentCaster::HitType hitType; // [rsp+220h] [rbp+130h] BYREF
  __int128 *v84; // [rsp+240h] [rbp+150h]
  __m128i *v85; // [rsp+248h] [rbp+158h] BYREF

  v84 = v9;
  hkgpConvexHull::hkgpConvexHull(&v80);
  m_size = clippingPlanes->m_size;
  m_data = clippingPlanes->m_data;
  hkgpConvexHull::BuildConfig::BuildConfig(&v70);
  hkgpConvexHull::buildFromPlanes(&v80, m_data, m_size, v16);
  hkgpConvexHull::getBoundingBox(&v80, &result, 1, 1.0, 0.0);
  v17 = extremalVector;
  v18 = v85;
  v19 = (__m128i)_mm_sub_ps(right->m_quad, left->m_quad);
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)extremalVector, *(__m128 *)extremalVector, 201), *(__m128 *)v85),
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)v85, *(__m128 *)v85, 201), *(__m128 *)extremalVector));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_mul_ps(v21, v21);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_mul_ps(
          v21,
          _mm_andnot_ps(
            _mm_cmple_ps(v23, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(*(__m128 *)_xmm, v24))));
  v26 = _mm_mul_ps(v25, (__m128)v19);
  v27 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
            _mm_shuffle_ps(v26, v26, 170)),
          v25);
  v28 = _mm_mul_ps(v27, v27);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)), _mm_shuffle_ps(v28, v28, 170));
  v30 = _mm_rcp_ps(v29);
  v31 = _mm_mul_ps(v27, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v29, v30)), v30));
  v32 = _mm_mul_ps(v31, left->m_quad);
  v33 = _mm_shuffle_ps(
          v31,
          _mm_unpackhi_ps(
            v31,
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                _mm_shuffle_ps(v32, v32, 170)))),
          196);
  hkaiIntervalPartition::hkaiIntervalPartition(&other);
  v34 = this->m_geometries.m_size;
  v35 = 0;
  if ( v34 > 0 )
  {
    v36 = 0i64;
    do
    {
      v37 = this->m_geometries.m_data;
      m_geometry = (__int64)v37[v36].m_geometry;
      m_pntr = v37[v36].m_accelerationData.m_pntr;
      v74 = *v84;
      v73 = &v80;
      v75 = m_geometry;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace::GeometryExtremalProfileQuery::`vftable;
      v77 = v35;
      p_m_edges = &m_pntr->m_edges;
      hkaiIntervalPartition::hkaiIntervalPartition(&v78);
      hkaiIntervalPartition::swap(&v78, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      hkcdDynamicAabbTree::queryAabb(
        this->m_geometries.m_data[v36].m_accelerationData.m_pntr->m_edgeTree.m_pntr,
        &result,
        &collector);
      hkaiIntervalPartition::swap(&v78, (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other);
      v78.m_intervals.m_size = 0;
      if ( v78.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v78.m_intervals.m_data,
          20 * (v78.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      ++v35;
      ++v36;
      --v34;
    }
    while ( v34 );
    v18 = v85;
    v17 = extremalVector;
  }
  hkaiIntervalPartition::clipX(&other, 0.0, 1.0);
  if ( other.m_intervals.m_size )
  {
    m_quad = left->m_quad;
    v41.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(*v18, 4), 4);
    v42.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(*v17, 4), 4);
    v43 = left->m_quad;
    out.m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v19, 4), 4);
    m.m_col2 = out.m_col2;
    out.m_col0 = (hkVector4f)v41.m_quad;
    m.m_col0 = (hkVector4f)v41.m_quad;
    out.m_col1 = (hkVector4f)v42.m_quad;
    *(float *)&v85 = FLOAT_0_001;
    out.m_col3.m_quad = _mm_shuffle_ps(m_quad, _mm_unpackhi_ps(v43, query.m_quad), 196);
    m.m_col1 = (hkVector4f)v42.m_quad;
    m.m_col3 = out.m_col3;
    v70 = (hkgpConvexHull::BuildConfig)_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
    __hkMatrix4UtilAlgo::setInverse((hkResult *)&v85, &m, &out, (hkSimdFloat32 *)&v70);
    v44 = (hkaiIntervalPartition *)uVector;
    hkaiIntervalPartition::reserve((hkaiIntervalPartition *)uVector, other.m_intervals.m_size);
    v45 = (hkaiIntervalPartition *)vVector;
    hkaiIntervalPartition::reserve((hkaiIntervalPartition *)vVector, other.m_intervals.m_size);
    v46 = other.m_intervals.m_size;
    for ( i = 0; i < v46; ++i )
    {
      Interval = hkaiIntervalPartition::getInterval(&other, i);
      m_leftX = Interval->m_leftX;
      m_rightX = Interval->m_rightX;
      m_offset = Interval->m_offset;
      *(float *)&v70.m_setSourceIndices.m_bool = Interval->m_slope;
      data = Interval->m_data;
      *(float *)&v70.m_allowLowerDimensions.m_bool = m_leftX;
      v70.m_minCosAngle = m_rightX;
      *(float *)&v70.m_internalInputs.m_bool = m_offset;
      hkaiGeometrySegmentCaster::unpackData(data, &hitType, (unsigned int *)&v85, (unsigned int *)&extremalVector);
      v52 = &this->m_geometries.m_data[(int)v85];
      v53 = v52->m_accelerationData.m_pntr->m_edges.m_data;
      v54 = v52->m_geometry->m_vertices.m_data;
      v55 = v54[v53[(int)extremalVector].m_a].m_quad;
      v56 = _mm_mul_ps(v55, v33);
      v57 = _mm_sub_ps(v54[v53[(int)extremalVector].m_b].m_quad, v55);
      v58 = _mm_shuffle_ps(v56, _mm_unpackhi_ps(v56, v33), 196);
      v59 = _mm_add_ps(_mm_shuffle_ps(v58, v58, 78), v58);
      v60 = _mm_mul_ps(v33, v57);
      v61 = _mm_add_ps(_mm_shuffle_ps(v59, v59, 177), v59);
      v62 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
              _mm_shuffle_ps(v60, v60, 170));
      v63 = _mm_rcp_ps(v62);
      v64 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v63, v62)), v63);
      v65 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)*(unsigned int *)&v70.m_allowLowerDimensions.m_bool,
                      (__m128)*(unsigned int *)&v70.m_allowLowerDimensions.m_bool,
                      0),
                    v61),
                  v64),
                v57),
              v55);
      v66 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps((__m128)LODWORD(v70.m_minCosAngle), (__m128)LODWORD(v70.m_minCosAngle), 0),
                    v61),
                  v64),
                v57),
              v55);
      v67 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), out.m_col0.m_quad), out.m_col3.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), out.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v65, v65, 170), out.m_col2.m_quad));
      v68 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v66, v66, 0), out.m_col0.m_quad), out.m_col3.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v66, v66, 85), out.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v66, v66, 170), out.m_col2.m_quad));
      hkaiIntervalPartition::appendIntervalFromEndpoints(
        v44,
        m_leftX,
        v67.m128_f32[0],
        m_rightX,
        v68.m128_f32[0],
        0xFFFFFFFF);
      hkaiIntervalPartition::appendIntervalFromEndpoints(
        v45,
        m_leftX,
        _mm_shuffle_ps(v67, v67, 85).m128_f32[0],
        m_rightX,
        _mm_shuffle_ps(v68, v68, 85).m128_f32[0],
        0xFFFFFFFF);
    }
  }
  other.m_intervals.m_size = 0;
  if ( other.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      other.m_intervals.m_data,
      20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  other.m_intervals.m_data = 0i64;
  other.m_intervals.m_capacityAndFlags = 0x80000000;
  hkgpConvexHull::~hkgpConvexHull(&v80);
}

// File Line: 1094
// RVA: 0x12E5E30
__int64 __fastcall hkaiGeometrySegmentCaster::packData(
        hkaiGeometrySegmentCaster::HitType hitType,
        unsigned int geometryIndex,
        unsigned int nodeIndex)
{
  return nodeIndex | ((geometryIndex | (4 * hitType)) << 28);
}

// File Line: 1101
// RVA: 0x12E5E50
void __fastcall hkaiGeometrySegmentCaster::unpackData(
        unsigned int data,
        hkaiGeometrySegmentCaster::HitType *hitType,
        unsigned int *geometryIndex,
        unsigned int *nodeIndex)
{
  *hitType = data >> 30;
  *geometryIndex = (data >> 28) & 3;
  *nodeIndex = data & 0xFFFFFFF;
}

// File Line: 1108
// RVA: 0x12E5DD0
__int64 __fastcall hkaiGeometrySegmentCaster::AccelerationData::getSize(
        hkaiGeometrySegmentCaster::AccelerationData *this)
{
  hkcdDynamicAabbTree *m_pntr; // rcx
  int MemoryFootPrint; // esi
  int v4; // ebx

  m_pntr = this->m_edgeTree.m_pntr;
  if ( m_pntr )
    MemoryFootPrint = hkcdDynamicAabbTree::getMemoryFootPrint(m_pntr);
  else
    MemoryFootPrint = 0;
  v4 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  return MemoryFootPrint + (unsigned int)hkcdDynamicAabbTree::getMemoryFootPrint(this->m_faceTree.m_pntr) + 8 * (v4 + 6);
}

