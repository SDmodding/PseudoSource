// File Line: 64
// RVA: 0x12E6850
signed __int64 __fastcall `anonymous namespace'::GeometryCastSegmentQuery::processLeaf(GeometryCastSegmentQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  int triangleIndex; // ebx
  GeometryCastSegmentQuery *v4; // rdi
  unsigned int data; // eax
  hkaiIntervalPartition *v6; // rcx
  hkaiIntervalPartition *v7; // rdx

  triangleIndex = leafKey;
  v4 = this;
  data = hkaiGeometrySegmentCaster::packData(0, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFace(
         &v4->m_leftStart,
         &v4->m_rightStart,
         &v4->m_displacement,
         v4->m_geometry,
         triangleIndex,
         data,
         &v4->m_curPartition) )
  {
    v6 = &v4->m_fullPartition;
    v7 = &v4->m_curPartition;
    if ( v4->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(v6, v7);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(v6, v7);
      hkaiIntervalPartition::clear(&v4->m_curPartition);
    }
  }
  return 1i64;
}

// File Line: 129
// RVA: 0x12E6650
signed __int64 __fastcall `anonymous namespace'::DoubledGeometryCastSegmentQuery::processLeaf(DoubledGeometryCastSegmentQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  unsigned int triangleIndex; // esi
  DoubledGeometryCastSegmentQuery *v4; // rbx
  unsigned int data; // eax
  hkaiIntervalPartition *v6; // rcx
  hkaiIntervalPartition *v7; // rdx
  unsigned int v8; // eax
  hkaiIntervalPartition *v9; // rcx
  hkaiIntervalPartition *v10; // rdx

  triangleIndex = leafKey;
  v4 = this;
  data = hkaiGeometrySegmentCaster::packData(0, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFace(
         &v4->m_leftStart,
         &v4->m_rightStart,
         &v4->m_displacement,
         v4->m_geometry,
         triangleIndex,
         data,
         &v4->m_curPartition) )
  {
    v6 = &v4->m_fullPartition;
    v7 = &v4->m_curPartition;
    if ( v4->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(v6, v7);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(v6, v7);
      hkaiIntervalPartition::clear(&v4->m_curPartition);
    }
  }
  v8 = hkaiGeometrySegmentCaster::packData(HITTYPE_TRANSLATED_FACE, v4->m_geometryIdx, triangleIndex);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentFace(
         &v4->m_shiftedLeftStart,
         &v4->m_shiftedRightStart,
         &v4->m_displacement,
         v4->m_geometry,
         triangleIndex,
         v8,
         &v4->m_curPartition) )
  {
    v9 = &v4->m_fullPartition;
    v10 = &v4->m_curPartition;
    if ( v4->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(v9, v10);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(v9, v10);
      hkaiIntervalPartition::clear(&v4->m_curPartition);
    }
  }
  return 1i64;
}

// File Line: 222
// RVA: 0x12E6B50
signed __int64 __fastcall `anonymous namespace'::GeometryExtrusionCastSegmentQuery::processLeaf(GeometryExtrusionCastSegmentQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkGeometry *v3; // r10
  GeometryExtrusionCastSegmentQuery *v4; // rbx
  hkaiGeometrySegmentCaster::ExtrudedEdge *v5; // r9
  unsigned int v6; // er8
  unsigned int v7; // edx
  unsigned int data; // eax
  hkaiIntervalPartition *v9; // rcx
  hkaiIntervalPartition *v10; // rdx
  hkVector4f vertexB; // [rsp+40h] [rbp-28h]
  hkVector4f vertexA; // [rsp+50h] [rbp-18h]

  v3 = this->m_geometry;
  v4 = this;
  v5 = &this->m_edges->m_data[leafKey];
  _mm_store_si128((__m128i *)&vertexA, (__m128i)v3->m_vertices.m_data[v5->m_a].m_quad);
  v6 = leafKey;
  v7 = this->m_geometryIdx;
  _mm_store_si128((__m128i *)&vertexB, (__m128i)v3->m_vertices.m_data[v5->m_b].m_quad);
  data = hkaiGeometrySegmentCaster::packData(HITTYPE_EXTRUDED_EDGE, v7, v6);
  if ( hkaiSegmentCastingUtil::intersectSweptSegmentExtrudedEdge(
         &v4->m_leftStart,
         &v4->m_rightStart,
         &v4->m_displacement,
         &vertexA,
         &vertexB,
         &v4->m_extrusion,
         data,
         &v4->m_curPartition) )
  {
    v9 = &v4->m_fullPartition;
    v10 = &v4->m_curPartition;
    if ( v4->m_fullPartition.m_intervals.m_size > 0 )
    {
      hkaiIntervalPartition::combine<0,0>(v9, v10);
      hkaiIntervalPartition::clear(&v4->m_curPartition);
      return 1i64;
    }
    hkaiIntervalPartition::swap(v9, v10);
  }
  return 1i64;
}

// File Line: 296
// RVA: 0x12E6D20
signed __int64 __fastcall `anonymous namespace'::GeometryTurnedSegmentQuery::processLeaf(GeometryTurnedSegmentQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  int triangleIndex; // ebx
  GeometryTurnedSegmentQuery *v4; // rdi
  unsigned int data; // eax
  hkaiIntervalPartition *v6; // rcx
  hkaiIntervalPartition *v7; // rdx

  triangleIndex = leafKey;
  v4 = this;
  data = hkaiGeometrySegmentCaster::packData(0, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
         &v4->m_leftStart,
         &v4->m_rightStart,
         &v4->m_leftEnd,
         &v4->m_rightEnd,
         v4->m_geometry,
         triangleIndex,
         data,
         &v4->m_curPartition) )
  {
    v6 = &v4->m_fullPartition;
    v7 = &v4->m_curPartition;
    if ( v4->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(v6, v7);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(v6, v7);
      hkaiIntervalPartition::clear(&v4->m_curPartition);
    }
  }
  return 1i64;
}

// File Line: 367
// RVA: 0x12E6740
signed __int64 __fastcall `anonymous namespace'::DoubledGeometryTurnedSegmentQuery::processLeaf(DoubledGeometryTurnedSegmentQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  unsigned int triangleIndex; // esi
  DoubledGeometryTurnedSegmentQuery *v4; // rbx
  unsigned int data; // eax
  hkaiIntervalPartition *v6; // rcx
  hkaiIntervalPartition *v7; // rdx
  unsigned int v8; // eax
  hkaiIntervalPartition *v9; // rcx
  hkaiIntervalPartition *v10; // rdx

  triangleIndex = leafKey;
  v4 = this;
  data = hkaiGeometrySegmentCaster::packData(0, this->m_geometryIdx, leafKey);
  if ( hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
         &v4->m_leftStart,
         &v4->m_rightStart,
         &v4->m_leftEnd,
         &v4->m_rightEnd,
         v4->m_geometry,
         triangleIndex,
         data,
         &v4->m_curPartition) )
  {
    v6 = &v4->m_fullPartition;
    v7 = &v4->m_curPartition;
    if ( v4->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(v6, v7);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(v6, v7);
      hkaiIntervalPartition::clear(&v4->m_curPartition);
    }
  }
  v8 = hkaiGeometrySegmentCaster::packData(HITTYPE_TRANSLATED_FACE, v4->m_geometryIdx, triangleIndex);
  if ( hkaiSegmentCastingUtil::intersectTurnedSegmentFace(
         &v4->m_shiftedLeftStart,
         &v4->m_shiftedRightStart,
         &v4->m_shiftedLeftEnd,
         &v4->m_shiftedRightEnd,
         v4->m_geometry,
         triangleIndex,
         v8,
         &v4->m_curPartition) )
  {
    v9 = &v4->m_fullPartition;
    v10 = &v4->m_curPartition;
    if ( v4->m_fullPartition.m_intervals.m_size <= 0 )
    {
      hkaiIntervalPartition::swap(v9, v10);
    }
    else
    {
      hkaiIntervalPartition::combine<0,0>(v9, v10);
      hkaiIntervalPartition::clear(&v4->m_curPartition);
    }
  }
  return 1i64;
}

// File Line: 467
// RVA: 0x12E6C30
signed __int64 __fastcall `anonymous namespace'::GeometryExtrusionTurnedSegmentQuery::processLeaf(GeometryExtrusionTurnedSegmentQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkGeometry *v3; // r10
  GeometryExtrusionTurnedSegmentQuery *v4; // rbx
  hkaiGeometrySegmentCaster::ExtrudedEdge *v5; // r9
  unsigned int v6; // er8
  unsigned int v7; // edx
  unsigned int data; // eax
  hkaiIntervalPartition *v9; // rcx
  hkaiIntervalPartition *v10; // rdx
  hkVector4f vertexB; // [rsp+50h] [rbp-28h]
  hkVector4f vertexA; // [rsp+60h] [rbp-18h]

  v3 = this->m_geometry;
  v4 = this;
  v5 = &this->m_edges->m_data[leafKey];
  _mm_store_si128((__m128i *)&vertexA, (__m128i)v3->m_vertices.m_data[v5->m_a].m_quad);
  v6 = leafKey;
  v7 = this->m_geometryIdx;
  _mm_store_si128((__m128i *)&vertexB, (__m128i)v3->m_vertices.m_data[v5->m_b].m_quad);
  data = hkaiGeometrySegmentCaster::packData(HITTYPE_EXTRUDED_EDGE, v7, v6);
  if ( hkaiSegmentCastingUtil::intersectTurnedSegmentExtrudedEdge(
         &v4->m_leftStart,
         &v4->m_rightStart,
         &v4->m_leftEnd,
         &v4->m_rightEnd,
         &vertexA,
         &vertexB,
         &v4->m_extrusion,
         data,
         &v4->m_curPartition) )
  {
    v9 = &v4->m_fullPartition;
    v10 = &v4->m_curPartition;
    if ( v4->m_fullPartition.m_intervals.m_size > 0 )
    {
      hkaiIntervalPartition::combine<0,0>(v9, v10);
      hkaiIntervalPartition::clear(&v4->m_curPartition);
      return 1i64;
    }
    hkaiIntervalPartition::swap(v9, v10);
  }
  return 1i64;
}

// File Line: 538
// RVA: 0x12E68E0
signed __int64 __fastcall `anonymous namespace'::GeometryExtremalProfileQuery::processLeaf(GeometryExtremalProfileQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkGeometry *v3; // r10
  unsigned int v4; // edi
  hkaiGeometrySegmentCaster::ExtrudedEdge *v5; // r9
  GeometryExtremalProfileQuery *v6; // rbx
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm2
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
  __m128 v21; // xmm7
  __m128 v22; // xmm6
  __m128 v23; // xmm7
  unsigned int v24; // eax
  hkVector4f b; // [rsp+40h] [rbp-88h]
  hkVector4f a; // [rsp+50h] [rbp-78h]
  hkaiIntervalPartition::Interval interval; // [rsp+60h] [rbp-68h]
  float t0; // [rsp+D0h] [rbp+8h]
  hkBool result; // [rsp+D8h] [rbp+10h]
  float t1; // [rsp+E8h] [rbp+20h]

  v3 = this->m_geometry;
  v4 = leafKey;
  v5 = this->m_edges->m_data;
  v6 = this;
  v7 = v3->m_vertices.m_data[v5[leafKey].m_a].m_quad;
  a.m_quad = v7;
  b.m_quad = (__m128)v3->m_vertices.m_data[v5[leafKey].m_b];
  v8 = _mm_mul_ps(_mm_sub_ps(b.m_quad, v7), this->m_xEqn.m_quad);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v8, v8, 170))) < 0.0 )
  {
    a.m_quad = b.m_quad;
    b.m_quad = v7;
  }
  if ( !hkgpConvexHull::clipLine(this->m_clippingVolume, &result, &a, &b, &t0, &t1, 0.0)->m_bool || t1 <= t0 )
    return 1i64;
  v9 = v6->m_xEqn.m_quad;
  v10 = _mm_sub_ps(b.m_quad, a.m_quad);
  v11 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(t0), (__m128)LODWORD(t0), 0), v10), a.m_quad);
  v12 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(t1), (__m128)LODWORD(t1), 0), v10), a.m_quad);
  v13 = _mm_mul_ps(v9, v11);
  v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, v9), 196);
  v15 = _mm_add_ps(_mm_shuffle_ps(v14, v14, 78), v14);
  v16 = _mm_mul_ps(v9, v12);
  v17 = COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 177)) + v15.m128_f32[0];
  v18 = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, v9), 196);
  v19 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v20 = COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 177)) + v19.m128_f32[0];
  if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v17 - v20)) >> 1) >= 0.0078740157 )
  {
    v21 = v6->m_extremalVector.m_quad;
    v22 = _mm_mul_ps(v21, v12);
    v23 = _mm_mul_ps(v21, v11);
    v24 = hkaiGeometrySegmentCaster::packData(HITTYPE_EXTRUDED_EDGE, v6->m_geometryIdx, v4);
    hkaiIntervalPartition::Interval::setFromEndpoints(
      &interval,
      v17,
      (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
    + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170)),
      v20,
      (float)(COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 0)))
    + COERCE_FLOAT(_mm_shuffle_ps(v22, v22, 170)),
      v24);
    hkaiIntervalPartition::unionOne<1>(&v6->m_extremalPartition, &interval);
  }
  return 1i64;
}

// File Line: 601
// RVA: 0x12E4100
hkaiGeometrySegmentCaster::AccelerationData *__fastcall hkaiGeometrySegmentCaster::buildAccelerationData(hkGeometry *geometry, hkBitField *mask, hkBool supportExtrusion)
{
  hkGeometry *v3; // rsi
  hkBitField *v4; // r13
  _QWORD **v5; // rax
  __int64 v6; // rax
  __int64 v7; // r14
  _QWORD **v8; // rax
  hkcdDynamicAabbTree *v9; // rax
  hkcdDynamicAabbTree *v10; // rax
  hkcdDynamicAabbTree *v11; // rdi
  hkReferencedObject *v12; // rcx
  __int64 v13; // rbx
  __int64 v14; // r15
  int v15; // edi
  hkResultEnum v16; // ebx
  unsigned int v17; // esi
  __int64 v18; // r14
  __int64 v19; // r12
  hkGeometry::Triangle *v20; // rcx
  hkVector4f *v21; // rdx
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __int64 v25; // rax
  hkcdDynamicAabbTree *v26; // rcx
  __m128 v27; // xmm2
  unsigned int v28; // ebx
  __int64 v29; // rsi
  __int64 v30; // rdi
  hkGeometry::Triangle *v31; // rcx
  hkVector4f *v32; // rdx
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __int64 v36; // rax
  hkcdDynamicAabbTree *v37; // rcx
  __m128 v38; // xmm2
  float v39; // edx
  unsigned __int64 v40; // r8
  int v41; // er9
  __int64 v42; // r14
  hkGeometry::Triangle *v43; // rsi
  int v44; // ebx
  int v45; // edi
  int v46; // er10
  signed int v47; // er11
  int v48; // ecx
  _DWORD *v49; // rdx
  int v50; // eax
  int v51; // ebx
  float v52; // er10
  float v53; // edx
  int v54; // edi
  int v55; // er9
  signed int v56; // er11
  int v57; // ecx
  _DWORD *v58; // rdx
  int v59; // eax
  int v60; // ebx
  float v61; // er10
  float v62; // er9
  int v63; // edi
  int v64; // er9
  signed int v65; // er11
  int v66; // eax
  _DWORD *v67; // rdx
  int v68; // er15
  unsigned int v69; // esi
  __int64 v70; // r11
  __int64 v71; // r10
  signed int *v72; // r14
  signed int v73; // ebx
  unsigned int v74; // edi
  int v75; // er10
  signed int v76; // er11
  int v77; // ecx
  _DWORD *v78; // rdx
  int v79; // eax
  signed int v80; // ebx
  float v81; // er10
  float v82; // edx
  unsigned int v83; // edi
  int v84; // er9
  signed int v85; // er11
  int v86; // ecx
  _DWORD *v87; // rdx
  int v88; // eax
  signed int v89; // ebx
  float v90; // er10
  float v91; // edx
  unsigned int v92; // edi
  int v93; // er9
  signed int v94; // er11
  int v95; // ecx
  _DWORD *v96; // rdx
  int v97; // er10
  int v98; // eax
  int v99; // eax
  _QWORD **v100; // rax
  hkcdDynamicAabbTree *v101; // rax
  hkcdDynamicAabbTree *v102; // rax
  hkcdDynamicAabbTree *v103; // rbx
  hkReferencedObject *v104; // rcx
  int v105; // er8
  unsigned __int64 v106; // rax
  int v107; // er9
  int v108; // edx
  signed __int64 v109; // rcx
  int v110; // edi
  hkVector4f *v111; // rcx
  unsigned int v112; // er8
  __int64 v113; // rbx
  __m128 v114; // xmm2
  __m128 v115; // xmm0
  __m128 v116; // xmm1
  hkcdDynamicAabbTree *v117; // rcx
  _QWORD *v118; // rdx
  float v119; // er9
  int v120; // er9
  int v121; // edx
  signed __int64 i; // rcx
  hkReferencedObject *v123; // rcx
  hkAabb aabb; // [rsp+30h] [rbp-69h]
  __int64 v126; // [rsp+50h] [rbp-49h]
  unsigned __int64 v127; // [rsp+58h] [rbp-41h]
  unsigned __int64 v128; // [rsp+60h] [rbp-39h]
  __int64 v129; // [rsp+68h] [rbp-31h]
  hkResult v130; // [rsp+70h] [rbp-29h]
  unsigned __int64 v131; // [rsp+74h] [rbp-25h]
  unsigned __int64 v132; // [rsp+7Ch] [rbp-1Dh]
  __int64 v133; // [rsp+88h] [rbp-11h]
  hkAabb v134; // [rsp+90h] [rbp-9h]
  hkGeometry *v135; // [rsp+100h] [rbp+67h]
  hkResult result; // [rsp+108h] [rbp+6Fh]
  char v137; // [rsp+110h] [rbp+77h]
  hkResult v138; // [rsp+118h] [rbp+7Fh]

  v137 = supportExtrusion.m_bool;
  v135 = geometry;
  v3 = geometry;
  v4 = mask;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 48i64);
  v7 = v6;
  v129 = v6;
  if ( v6 )
  {
    *(_DWORD *)(v6 + 8) = 0x1FFFF;
    *(_QWORD *)v6 = &hkaiGeometrySegmentCaster::AccelerationData::`vftable';
    *(_QWORD *)(v6 + 16) = 0i64;
    *(_QWORD *)(v6 + 24) = 0i64;
    *(_DWORD *)(v6 + 32) = 0;
    *(_DWORD *)(v6 + 36) = 2147483648;
    *(_QWORD *)(v6 + 40) = 0i64;
  }
  else
  {
    v7 = 0i64;
    v129 = 0i64;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 32i64);
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
  if ( v12 && v12 != (hkReferencedObject *)v11 )
    hkReferencedObject::removeReference(v12);
  *(_QWORD *)(v7 + 16) = v11;
  v13 = v3->m_triangles.m_size;
  hkcdDynamicAabbTree::reserveLeaves(v11, &result, v3->m_triangles.m_size);
  v14 = v13;
  v126 = v13;
  if ( v4 )
  {
    v15 = 0;
    if ( v4->m_storage.m_numBits <= 0 )
      v16 = 0;
    else
      v16 = *v4->m_storage.m_words.m_data;
    result.m_enum = v16;
    v17 = 0;
    if ( v14 <= 0 )
      goto LABEL_28;
    v18 = 0i64;
    v19 = v129;
    do
    {
      if ( result.m_enum & 1 )
      {
        v20 = v135->m_triangles.m_data;
        v21 = v135->m_vertices.m_data;
        v22 = v21[v20[v18].m_a].m_quad;
        v23 = v21[v20[v18].m_a].m_quad;
        v24 = v21[v20[v18].m_b].m_quad;
        v25 = v20[v18].m_c;
        v26 = *(hkcdDynamicAabbTree **)(v19 + 16);
        v27 = v21[v25].m_quad;
        aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(v23, v24), v27);
        aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(v22, v24), v27);
        hkcdDynamicAabbTree::insert(v26, &aabb, v17);
      }
      if ( ++v15 & 0x1F || v15 >= v4->m_storage.m_numBits )
        v16 = (unsigned int)v16 >> 1;
      else
        v16 = v4->m_storage.m_words.m_data[(signed __int64)v15 >> 5];
      ++v17;
      ++v18;
      result.m_enum = v16;
      --v14;
    }
    while ( v14 );
    v7 = v129;
  }
  else
  {
    v28 = 0;
    if ( v14 <= 0 )
      goto LABEL_29;
    v29 = v14;
    v30 = 0i64;
    do
    {
      v31 = v135->m_triangles.m_data;
      v32 = v135->m_vertices.m_data;
      v33 = v32[v31[v30].m_a].m_quad;
      v34 = v32[v31[v30].m_a].m_quad;
      v35 = v32[v31[v30].m_b].m_quad;
      v36 = v31[v30].m_c;
      v37 = *(hkcdDynamicAabbTree **)(v7 + 16);
      v38 = v32[v36].m_quad;
      aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(v34, v35), v38);
      aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(v33, v35), v38);
      hkcdDynamicAabbTree::insert(v37, &aabb, v28++);
      ++v30;
      --v29;
    }
    while ( v29 );
  }
  v14 = v126;
LABEL_28:
  v3 = v135;
LABEL_29:
  hkcdDynamicAabbTree::rebuild(*(hkcdDynamicAabbTree **)(v7 + 16));
  if ( v137 )
  {
    v39 = 0.0;
    v40 = 0i64;
    aabb.m_min.m_quad.m128_u64[0] = 0i64;
    v41 = 0;
    aabb.m_max.m_quad.m128_i32[0] = 0;
    aabb.m_min.m_quad.m128_u64[1] = 0x8000000000000000i64;
    if ( v4 )
    {
      if ( v14 <= 0 )
      {
LABEL_120:
        v98 = *(_DWORD *)(v7 + 36) & 0x3FFFFFFF;
        if ( v98 < v41 )
        {
          v99 = 2 * v98;
          if ( v41 < v99 )
            v41 = v99;
          hkArrayUtil::_reserve(
            &result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (void *)(v7 + 24),
            v41,
            8);
        }
        v100 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v101 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v100[11] + 8i64))(
                                        v100[11],
                                        32i64);
        if ( v101 )
        {
          hkcdDynamicAabbTree::hkcdDynamicAabbTree(v101);
          v103 = v102;
        }
        else
        {
          v103 = 0i64;
        }
        v104 = *(hkReferencedObject **)(v7 + 40);
        if ( v104 && v104 != (hkReferencedObject *)v103 )
          hkReferencedObject::removeReference(v104);
        v105 = aabb.m_max.m_quad.m128_i32[0];
        *(_QWORD *)(v7 + 40) = v103;
        hkcdDynamicAabbTree::reserveLeaves(v103, &result, v105);
        v106 = aabb.m_min.m_quad.m128_u64[0];
        v107 = aabb.m_min.m_quad.m128_i32[2] - 1;
        v108 = 0;
        v109 = 0i64;
        if ( aabb.m_min.m_quad.m128_i32[2] - 1 >= 0 )
        {
          do
          {
            if ( *(_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8 * v109) != -1 )
              break;
            ++v109;
            ++v108;
          }
          while ( v109 <= v107 );
        }
        v110 = v108;
        if ( v108 <= v107 )
        {
          do
          {
            v111 = v135->m_vertices.m_data;
            v112 = *(_DWORD *)(v7 + 32);
            v113 = *(_QWORD *)(v106 + 8i64 * v110);
            v114 = v111[(signed int)v113].m_quad;
            v115 = v111[(signed int)v113].m_quad;
            v116 = v111[SHIDWORD(v113)].m_quad;
            v117 = *(hkcdDynamicAabbTree **)(v7 + 40);
            v134.m_min.m_quad = _mm_min_ps(v115, v116);
            v134.m_max.m_quad = _mm_max_ps(v114, v116);
            hkcdDynamicAabbTree::insert(v117, &v134, v112);
            v118 = (_QWORD *)(*(_QWORD *)(v7 + 24) + 8i64 * *(signed int *)(v7 + 32));
            if ( v118 )
              *v118 = v113;
            v119 = aabb.m_min.m_quad.m128_f32[2];
            ++*(_DWORD *)(v7 + 32);
            v106 = aabb.m_min.m_quad.m128_u64[0];
            v120 = LODWORD(v119) - 1;
            v121 = v110 + 1;
            for ( i = v110 + 1; i <= v120; ++v121 )
            {
              if ( *(_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8 * i) != -1 )
                break;
              ++i;
            }
            v110 = v121;
          }
          while ( v121 <= v120 );
        }
        hkcdDynamicAabbTree::rebuild(*(hkcdDynamicAabbTree **)(v7 + 40));
        aabb.m_min.m_quad.m128_i32[2] = 0;
        if ( aabb.m_min.m_quad.m128_i32[3] >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            (void *)aabb.m_min.m_quad.m128_u64[0],
            8 * aabb.m_min.m_quad.m128_i32[3]);
        return (hkaiGeometrySegmentCaster::AccelerationData *)v7;
      }
      v42 = 0i64;
      while ( 1 )
      {
        v43 = &v3->m_triangles.m_data[v42];
        v44 = v43->m_b;
        v45 = v43->m_b;
        if ( v43->m_a < v44 )
          v45 = v43->m_a;
        if ( v43->m_a > v44 )
          v44 = v43->m_a;
        v127 = __PAIR__(v44, v45);
        if ( 2 * v41 > LODWORD(v39) - 1 )
        {
          hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
            (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
            &result,
            2 * LODWORD(v39));
          v41 = aabb.m_max.m_quad.m128_i32[0];
          v39 = aabb.m_min.m_quad.m128_f32[2];
          v40 = aabb.m_min.m_quad.m128_u64[0];
        }
        v46 = LODWORD(v39) - 1;
        v47 = 1;
        v48 = (LODWORD(v39) - 1) & (23857 * v45 ^ -1640531535 * v44);
        v49 = (_DWORD *)(v40 + 8i64 * v48);
        if ( *v49 != -1 )
        {
          while ( *v49 != v45 || v49[1] != v44 )
          {
            v48 = v46 & (v48 + 1);
            v49 = (_DWORD *)(v40 + 8i64 * v48);
            if ( *v49 == -1 )
              goto LABEL_45;
          }
          v47 = 0;
        }
LABEL_45:
        aabb.m_max.m_quad.m128_i32[0] = v47 + v41;
        *(_QWORD *)(v40 + 8i64 * v48) = v127;
        v50 = v43->m_b;
        v51 = v43->m_c;
        v52 = aabb.m_max.m_quad.m128_f32[0];
        v53 = aabb.m_min.m_quad.m128_f32[2];
        v54 = v43->m_c;
        if ( v50 < v51 )
          v54 = v43->m_b;
        if ( v50 > v51 )
          v51 = v43->m_b;
        v126 = __PAIR__(v51, v54);
        if ( 2 * aabb.m_max.m_quad.m128_i32[0] > aabb.m_min.m_quad.m128_i32[2] - 1 )
        {
          hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
            (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
            &v138,
            2 * aabb.m_min.m_quad.m128_i32[2]);
          v52 = aabb.m_max.m_quad.m128_f32[0];
          v53 = aabb.m_min.m_quad.m128_f32[2];
        }
        v55 = LODWORD(v53) - 1;
        v56 = 1;
        v57 = (LODWORD(v53) - 1) & (23857 * v54 ^ -1640531535 * v51);
        v58 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v57);
        if ( *v58 != -1 )
        {
          while ( *v58 != v54 || v58[1] != v51 )
          {
            v57 = v55 & (v57 + 1);
            v58 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v57);
            if ( *v58 == -1 )
              goto LABEL_57;
          }
          v56 = 0;
        }
LABEL_57:
        aabb.m_max.m_quad.m128_i32[0] = v56 + LODWORD(v52);
        *(_QWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v57) = v126;
        v59 = v43->m_c;
        v60 = v43->m_a;
        v61 = aabb.m_max.m_quad.m128_f32[0];
        v62 = aabb.m_min.m_quad.m128_f32[2];
        v63 = v43->m_a;
        if ( v59 < v43->m_a )
          v63 = v43->m_c;
        if ( v59 > v60 )
          v60 = v43->m_c;
        v128 = __PAIR__(v60, v63);
        if ( 2 * aabb.m_max.m_quad.m128_i32[0] > aabb.m_min.m_quad.m128_i32[2] - 1 )
        {
          hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
            (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
            &v130,
            2 * aabb.m_min.m_quad.m128_i32[2]);
          v61 = aabb.m_max.m_quad.m128_f32[0];
          v62 = aabb.m_min.m_quad.m128_f32[2];
        }
        v64 = LODWORD(v62) - 1;
        v65 = 1;
        v66 = v64 & (23857 * v63 ^ -1640531535 * v60);
        v67 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v66);
        if ( *v67 != -1 )
        {
          while ( *v67 != v63 || v67[1] != v60 )
          {
            v66 = v64 & (v66 + 1);
            v67 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v66);
            if ( *v67 == -1 )
              goto LABEL_69;
          }
          v65 = 0;
        }
LABEL_69:
        aabb.m_max.m_quad.m128_i32[0] = v65 + LODWORD(v61);
        ++v42;
        *(_QWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v66) = v128;
        v41 = aabb.m_max.m_quad.m128_i32[0];
        if ( !--v14 )
          break;
        v39 = aabb.m_min.m_quad.m128_f32[2];
        v40 = aabb.m_min.m_quad.m128_u64[0];
        v3 = v135;
      }
    }
    else
    {
      v68 = 0;
      if ( MEMORY[0x10] <= 0 )
      {
        v69 = 0;
        LODWORD(v127) = 0;
      }
      else
      {
        v69 = *(_DWORD *)MEMORY[0];
        LODWORD(v127) = *(_DWORD *)MEMORY[0];
      }
      v70 = v126;
      if ( v126 <= 0 )
        goto LABEL_120;
      v71 = 0i64;
      v133 = 0i64;
      do
      {
        if ( v127 & 1 )
        {
          v72 = (int *)((char *)&v135->m_triangles.m_data->m_a + v71);
          v73 = v72[1];
          v74 = v72[1];
          if ( *v72 < v73 )
            v74 = *v72;
          if ( *v72 > v73 )
            v73 = *v72;
          v128 = __PAIR__(v73, v74);
          if ( 2 * v41 > LODWORD(v39) - 1 )
          {
            hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
              (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
              &result,
              2 * LODWORD(v39));
            v41 = aabb.m_max.m_quad.m128_i32[0];
            v39 = aabb.m_min.m_quad.m128_f32[2];
            v40 = aabb.m_min.m_quad.m128_u64[0];
          }
          v75 = LODWORD(v39) - 1;
          v76 = 1;
          v77 = (LODWORD(v39) - 1) & (23857 * v74 ^ -1640531535 * v73);
          v78 = (_DWORD *)(v40 + 8i64 * v77);
          if ( *v78 != -1 )
          {
            while ( *v78 != v74 || v78[1] != v73 )
            {
              v77 = v75 & (v77 + 1);
              v78 = (_DWORD *)(v40 + 8i64 * v77);
              if ( *v78 == -1 )
                goto LABEL_89;
            }
            v76 = 0;
          }
LABEL_89:
          aabb.m_max.m_quad.m128_i32[0] = v76 + v41;
          *(_QWORD *)(v40 + 8i64 * v77) = v128;
          v79 = v72[1];
          v80 = v72[2];
          v81 = aabb.m_max.m_quad.m128_f32[0];
          v82 = aabb.m_min.m_quad.m128_f32[2];
          v83 = v72[2];
          if ( v79 < v80 )
            v83 = v72[1];
          if ( v79 > v80 )
            v80 = v72[1];
          v132 = __PAIR__(v80, v83);
          if ( 2 * aabb.m_max.m_quad.m128_i32[0] > aabb.m_min.m_quad.m128_i32[2] - 1 )
          {
            hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
              (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
              &v138,
              2 * aabb.m_min.m_quad.m128_i32[2]);
            v81 = aabb.m_max.m_quad.m128_f32[0];
            v82 = aabb.m_min.m_quad.m128_f32[2];
          }
          v84 = LODWORD(v82) - 1;
          v85 = 1;
          v86 = (LODWORD(v82) - 1) & (23857 * v83 ^ -1640531535 * v80);
          v87 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v86);
          if ( *v87 != -1 )
          {
            while ( *v87 != v83 || v87[1] != v80 )
            {
              v86 = v84 & (v86 + 1);
              v87 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v86);
              if ( *v87 == -1 )
                goto LABEL_101;
            }
            v85 = 0;
          }
LABEL_101:
          aabb.m_max.m_quad.m128_i32[0] = v85 + LODWORD(v81);
          *(_QWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v86) = v132;
          v88 = v72[2];
          v89 = *v72;
          v90 = aabb.m_max.m_quad.m128_f32[0];
          v91 = aabb.m_min.m_quad.m128_f32[2];
          v92 = *v72;
          if ( v88 < *v72 )
            v92 = v72[2];
          if ( v88 > v89 )
            v89 = v72[2];
          v131 = __PAIR__(v89, v92);
          if ( 2 * aabb.m_max.m_quad.m128_i32[0] > aabb.m_min.m_quad.m128_i32[2] - 1 )
          {
            hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge>>::resizeTable(
              (hkSet<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator,hkMapOperations<hkaiGeometrySegmentCaster::ExtrudedEdge> > *)&aabb,
              &v130,
              2 * aabb.m_min.m_quad.m128_i32[2]);
            v90 = aabb.m_max.m_quad.m128_f32[0];
            v91 = aabb.m_min.m_quad.m128_f32[2];
          }
          v93 = LODWORD(v91) - 1;
          v94 = 1;
          v95 = (LODWORD(v91) - 1) & (23857 * v92 ^ -1640531535 * v89);
          v96 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v95);
          if ( *v96 != -1 )
          {
            while ( *v96 != v92 || v96[1] != v89 )
            {
              v95 = v93 & (v95 + 1);
              v96 = (_DWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v95);
              if ( *v96 == -1 )
                goto LABEL_113;
            }
            v94 = 0;
          }
LABEL_113:
          v97 = v94 + LODWORD(v90);
          v70 = v126;
          aabb.m_max.m_quad.m128_i32[0] = v97;
          v71 = v133;
          *(_QWORD *)(aabb.m_min.m_quad.m128_u64[0] + 8i64 * v95) = v131;
          v41 = aabb.m_max.m_quad.m128_i32[0];
          v39 = aabb.m_min.m_quad.m128_f32[2];
          v40 = aabb.m_min.m_quad.m128_u64[0];
        }
        if ( ++v68 & 0x1F || v68 >= MEMORY[0x10] )
          v69 >>= 1;
        else
          v69 = *(_DWORD *)(MEMORY[0] + 4 * ((signed __int64)v68 >> 5));
        v71 += 16i64;
        --v70;
        LODWORD(v127) = v69;
        v126 = v70;
        v133 = v71;
      }
      while ( v70 );
    }
    v7 = v129;
    goto LABEL_120;
  }
  v123 = *(hkReferencedObject **)(v7 + 40);
  if ( v123 )
    hkReferencedObject::removeReference(v123);
  *(_QWORD *)(v7 + 40) = 0i64;
  return (hkaiGeometrySegmentCaster::AccelerationData *)v7;
}

// File Line: 701
// RVA: 0x12E49E0
void __fastcall hkaiGeometrySegmentCaster::hkaiGeometrySegmentCaster(hkaiGeometrySegmentCaster *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiGeometrySegmentCaster::`vftable';
  this->m_geometries.m_capacityAndFlags = 2147483648;
  this->m_geometries.m_data = 0i64;
  this->m_geometries.m_size = 0;
}

// File Line: 706
// RVA: 0x12E4A10
void __fastcall hkaiGeometrySegmentCaster::~hkaiGeometrySegmentCaster(hkaiGeometrySegmentCaster *this)
{
  hkaiGeometrySegmentCaster *v1; // rsi
  int v2; // eax
  hkaiGeometrySegmentCaster::Geometry *v3; // rcx
  int v4; // eax
  __int64 v5; // rdi
  hkReferencedObject **v6; // rbx
  int v7; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiGeometrySegmentCaster::`vftable';
  v2 = this->m_geometries.m_size;
  v3 = this->m_geometries.m_data;
  v4 = v2 - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = (hkReferencedObject **)&v3[v4].m_accelerationData;
    do
    {
      if ( *v6 )
        hkReferencedObject::removeReference(*v6);
      *v6 = 0i64;
      v6 -= 2;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v7 = v1->m_geometries.m_capacityAndFlags;
  v1->m_geometries.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_geometries.m_data,
      16 * v7);
  v1->m_geometries.m_data = 0i64;
  v1->m_geometries.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 710
// RVA: 0x12E4AD0
void __fastcall hkaiGeometrySegmentCaster::addGeometry(hkaiGeometrySegmentCaster *this, hkGeometry *geometry, hkaiGeometrySegmentCaster::AccelerationData *accelerationData)
{
  signed int *v3; // rdi
  hkaiGeometrySegmentCaster::AccelerationData *v4; // rsi
  hkGeometry *v5; // rbp
  signed __int64 v6; // rax
  hkGeometry **v7; // rbx
  hkReferencedObject *v8; // rcx

  v3 = (signed int *)&this->m_geometries;
  v4 = accelerationData;
  v5 = geometry;
  if ( this->m_geometries.m_size == (this->m_geometries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 16);
  v6 = *(_QWORD *)v3 + 16i64 * v3[2];
  if ( v6 )
    *(_QWORD *)(v6 + 8) = 0i64;
  v7 = (hkGeometry **)(*(_QWORD *)v3 + 16i64 * v3[2]++);
  *v7 = v5;
  if ( v4 )
    hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v8 = (hkReferencedObject *)v7[1];
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v7[1] = (hkGeometry *)v4;
}

// File Line: 722
// RVA: 0x12E4B80
void __fastcall hkaiGeometrySegmentCaster::castSegment(hkaiGeometrySegmentCaster *this, hkVector4f *leftStart, hkVector4f *rightStart, hkVector4f *displacement, hkaiIntervalPartition *partition)
{
  __int64 v5; // rsi
  int v6; // edi
  hkVector4f *v7; // r15
  hkVector4f *v8; // r12
  __m128i *v9; // r13
  hkaiGeometrySegmentCaster *v10; // r14
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  hkVector4f v13; // xmm0
  __int64 v14; // rbx
  __m128i v15; // xmm1
  __int64 v16; // rcx
  __m128i v17; // xmm0
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-B8h]
  __int128 v19; // [rsp+30h] [rbp-A8h]
  __int128 v20; // [rsp+40h] [rbp-98h]
  __int128 v21; // [rsp+50h] [rbp-88h]
  __int64 v22; // [rsp+60h] [rbp-78h]
  int v23; // [rsp+68h] [rbp-70h]
  hkaiIntervalPartition v24; // [rsp+70h] [rbp-68h]
  hkaiIntervalPartition other; // [rsp+80h] [rbp-58h]
  hkAabb aabb; // [rsp+90h] [rbp-48h]

  v5 = this->m_geometries.m_size;
  v6 = 0;
  v7 = displacement;
  v8 = rightStart;
  v9 = (__m128i *)leftStart;
  v10 = this;
  v11 = _mm_add_ps(displacement->m_quad, leftStart->m_quad);
  v12 = _mm_add_ps(rightStart->m_quad, displacement->m_quad);
  v13.m_quad = _mm_min_ps(_mm_min_ps(_mm_min_ps(leftStart->m_quad, rightStart->m_quad), v11), v12);
  aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(_mm_max_ps(leftStart->m_quad, rightStart->m_quad), v11), v12);
  aabb.m_min = (hkVector4f)v13.m_quad;
  if ( v5 > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = (__m128i)v8->m_quad;
      v16 = (__int64)v10->m_geometries.m_data[v14].m_geometry;
      _mm_store_si128((__m128i *)&v19, *v9);
      v17 = (__m128i)v7->m_quad;
      v22 = v16;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace'::GeometryCastSegmentQuery::`vftable';
      v23 = v6;
      _mm_store_si128((__m128i *)&v20, v15);
      _mm_store_si128((__m128i *)&v21, v17);
      hkaiIntervalPartition::hkaiIntervalPartition(&v24);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiIntervalPartition::swap(partition, &other);
      hkcdDynamicAabbTree::queryAabb(
        v10->m_geometries.m_data[v14].m_accelerationData.m_pntr->m_faceTree.m_pntr,
        &aabb,
        &collector);
      hkaiIntervalPartition::swap(partition, &other);
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      other.m_intervals.m_capacityAndFlags = 2147483648;
      other.m_intervals.m_data = 0i64;
      v24.m_intervals.m_size = 0;
      if ( v24.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v24.m_intervals.m_data,
          20 * (v24.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      ++v6;
      ++v14;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 747
// RVA: 0x12E4D60
void __fastcall hkaiGeometrySegmentCaster::castSegmentExtruded(hkaiGeometrySegmentCaster *this, hkVector4f *leftStart, hkVector4f *rightStart, hkVector4f *displacement, hkVector4f *extrusion, hkaiIntervalPartition *partition)
{
  __int64 v6; // rsi
  int v7; // edi
  hkVector4f *v8; // r12
  __m128i *v9; // r13
  hkaiGeometrySegmentCaster *v10; // r14
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm4
  __m128 v14; // xmm5
  __m128 v15; // xmm2
  __int64 v16; // rbx
  __m128i v17; // xmm1
  __int64 v18; // rcx
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  hkaiGeometrySegmentCaster::Geometry *v21; // rax
  __m128i v22; // xmm1
  __int64 v23; // rcx
  hkaiGeometrySegmentCaster::AccelerationData *v24; // rdx
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-E0h]
  __int128 v26; // [rsp+30h] [rbp-D0h]
  __int128 v27; // [rsp+40h] [rbp-C0h]
  __m128 v28; // [rsp+50h] [rbp-B0h]
  __m128 v29; // [rsp+60h] [rbp-A0h]
  __int128 v30; // [rsp+70h] [rbp-90h]
  __int64 v31; // [rsp+80h] [rbp-80h]
  int v32; // [rsp+88h] [rbp-78h]
  hkaiIntervalPartition v33; // [rsp+90h] [rbp-70h]
  hkaiIntervalPartition other; // [rsp+A0h] [rbp-60h]
  hkcdAabbTreeQueries::AabbCollector v35; // [rsp+B0h] [rbp-50h]
  __int128 v36; // [rsp+C0h] [rbp-40h]
  __int128 v37; // [rsp+D0h] [rbp-30h]
  __int128 v38; // [rsp+100h] [rbp+0h]
  __int128 v39; // [rsp+110h] [rbp+10h]
  __int64 v40; // [rsp+120h] [rbp+20h]
  hkArray<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator> *v41; // [rsp+128h] [rbp+28h]
  int v42; // [rsp+130h] [rbp+30h]
  hkaiIntervalPartition v43; // [rsp+138h] [rbp+38h]
  hkaiIntervalPartition v44; // [rsp+148h] [rbp+48h]
  hkAabb aabb; // [rsp+160h] [rbp+60h]
  __m128i *v46; // [rsp+1C8h] [rbp+C8h]

  v46 = (__m128i *)displacement;
  v6 = this->m_geometries.m_size;
  v7 = 0;
  v8 = rightStart;
  v9 = (__m128i *)leftStart;
  v10 = this;
  v11 = _mm_add_ps(displacement->m_quad, leftStart->m_quad);
  v12 = _mm_add_ps(rightStart->m_quad, displacement->m_quad);
  v13 = _mm_min_ps(_mm_min_ps(leftStart->m_quad, rightStart->m_quad), v11);
  v14 = _mm_max_ps(_mm_max_ps(_mm_max_ps(leftStart->m_quad, rightStart->m_quad), v11), v12);
  v15 = _mm_min_ps(extrusion->m_quad, aabbOut.m_quad);
  aabb.m_min.m_quad = _mm_sub_ps(_mm_min_ps(v13, v12), _mm_max_ps(extrusion->m_quad, aabbOut.m_quad));
  aabb.m_max.m_quad = _mm_sub_ps(v14, v15);
  if ( v6 > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = (__m128i)v8->m_quad;
      v18 = (__int64)v10->m_geometries.m_data[v16].m_geometry;
      _mm_store_si128((__m128i *)&v26, *v9);
      v19 = displacement->m_quad;
      v31 = v18;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace'::DoubledGeometryCastSegmentQuery::`vftable';
      v32 = v7;
      _mm_store_si128((__m128i *)&v27, v17);
      _mm_store_si128((__m128i *)&v30, (__m128i)v19);
      hkaiIntervalPartition::hkaiIntervalPartition(&v33);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      v20 = _mm_sub_ps(v8->m_quad, extrusion->m_quad);
      v28 = _mm_sub_ps(*(__m128 *)v9, extrusion->m_quad);
      v29 = v20;
      hkaiIntervalPartition::swap(partition, &other);
      hkcdDynamicAabbTree::queryAabb(
        v10->m_geometries.m_data[v16].m_accelerationData.m_pntr->m_faceTree.m_pntr,
        &aabb,
        &collector);
      v21 = v10->m_geometries.m_data;
      v22 = (__m128i)v8->m_quad;
      v23 = (__int64)v21[v16].m_geometry;
      v24 = v21[v16].m_accelerationData.m_pntr;
      _mm_store_si128((__m128i *)&v36, *v9);
      _mm_store_si128((__m128i *)&v37, v22);
      v35.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace'::GeometryExtrusionCastSegmentQuery::`vftable';
      v40 = v23;
      v42 = v7;
      _mm_store_si128((__m128i *)&v38, *v46);
      _mm_store_si128((__m128i *)&v39, (__m128i)extrusion->m_quad);
      v41 = &v24->m_edges;
      hkaiIntervalPartition::hkaiIntervalPartition(&v43);
      hkaiIntervalPartition::hkaiIntervalPartition(&v44);
      hkaiIntervalPartition::swap(&v44, &other);
      hkcdDynamicAabbTree::queryAabb(
        v10->m_geometries.m_data[v16].m_accelerationData.m_pntr->m_edgeTree.m_pntr,
        &aabb,
        &v35);
      hkaiIntervalPartition::swap(partition, &v44);
      v44.m_intervals.m_size = 0;
      if ( v44.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v44.m_intervals.m_data,
          20 * (v44.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v44.m_intervals.m_data = 0i64;
      v44.m_intervals.m_capacityAndFlags = 2147483648;
      v43.m_intervals.m_size = 0;
      if ( v43.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v43.m_intervals.m_data,
          20 * (v43.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v43.m_intervals.m_data = 0i64;
      v43.m_intervals.m_capacityAndFlags = 2147483648;
      v35.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable';
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      other.m_intervals.m_data = 0i64;
      other.m_intervals.m_capacityAndFlags = 2147483648;
      v33.m_intervals.m_size = 0;
      if ( v33.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v33.m_intervals.m_data,
          20 * (v33.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      displacement = (hkVector4f *)v46;
      ++v7;
      ++v16;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 811
// RVA: 0x12E5060
void __usercall hkaiGeometrySegmentCaster::castSegmentExtrudedEdges(hkaiGeometrySegmentCaster *this@<rcx>, hkVector4f *leftStart@<rdx>, hkVector4f *rightStart@<r8>, hkVector4f *displacement@<r9>, hkaiIntervalPartition *a5@<rbx>, hkVector4f *extrusion, hkaiIntervalPartition *partition)
{
  __int64 v7; // rsi
  hkVector4f *v8; // r13
  hkVector4f *v9; // r12
  int v10; // edi
  __m128i *v11; // r8
  hkaiGeometrySegmentCaster *v12; // r15
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __m128 *v17; // r9
  __m128 v18; // xmm2
  hkaiIntervalPartition *v19; // r14
  __int64 v20; // rbx
  hkaiGeometrySegmentCaster::Geometry *v21; // rax
  __m128i v22; // xmm1
  __int64 v23; // rcx
  hkaiGeometrySegmentCaster::AccelerationData *v24; // rdx
  __m128i v25; // xmm0
  __m128i v26; // xmm1
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+20h] [rbp-81h]
  __int128 v28; // [rsp+30h] [rbp-71h]
  __int128 v29; // [rsp+40h] [rbp-61h]
  __int128 v30; // [rsp+58h] [rbp-49h]
  __int64 v31; // [rsp+68h] [rbp-39h]
  hkArray<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator> *v32; // [rsp+70h] [rbp-31h]
  int v33; // [rsp+78h] [rbp-29h]
  hkaiIntervalPartition v34; // [rsp+80h] [rbp-21h]
  hkaiIntervalPartition v35; // [rsp+90h] [rbp-11h]
  hkAabb aabb; // [rsp+A8h] [rbp+7h]
  __m128i *v37; // [rsp+100h] [rbp+5Fh]
  __m128 *retaddr; // [rsp+118h] [rbp+77h]

  v7 = this->m_geometries.m_size;
  v8 = rightStart;
  v9 = displacement;
  v10 = 0;
  v11 = (__m128i *)leftStart;
  v12 = this;
  v13 = _mm_add_ps(displacement->m_quad, leftStart->m_quad);
  v14 = _mm_add_ps(v8->m_quad, displacement->m_quad);
  v15 = _mm_min_ps(_mm_min_ps(leftStart->m_quad, v8->m_quad), v13);
  v16 = _mm_max_ps(_mm_max_ps(leftStart->m_quad, v8->m_quad), v13);
  v17 = retaddr;
  v18 = _mm_min_ps(*retaddr, aabbOut.m_quad);
  aabb.m_min.m_quad = _mm_sub_ps(_mm_min_ps(v15, v14), _mm_max_ps(*retaddr, aabbOut.m_quad));
  aabb.m_max.m_quad = _mm_sub_ps(_mm_max_ps(v16, v14), v18);
  if ( v7 > 0 )
  {
    v19 = a5;
    v20 = 0i64;
    do
    {
      v21 = v12->m_geometries.m_data;
      v22 = (__m128i)v8->m_quad;
      v23 = (__int64)v21[v20].m_geometry;
      v24 = v21[v20].m_accelerationData.m_pntr;
      _mm_store_si128((__m128i *)&v28, *v11);
      v31 = v23;
      v25 = (__m128i)v9->m_quad;
      _mm_store_si128((__m128i *)&v29, v22);
      v26 = *(__m128i *)v17;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace'::GeometryExtrusionCastSegmentQuery::`vftable';
      v33 = v10;
      v32 = &v24->m_edges;
      _mm_store_si128((__m128i *)((char *)&v29 + 8), v25);
      _mm_store_si128((__m128i *)&v30, v26);
      hkaiIntervalPartition::hkaiIntervalPartition(&v34);
      hkaiIntervalPartition::hkaiIntervalPartition(&v35);
      hkaiIntervalPartition::swap(&v35, v19);
      hkcdDynamicAabbTree::queryAabb(
        v12->m_geometries.m_data[v20].m_accelerationData.m_pntr->m_edgeTree.m_pntr,
        &aabb,
        &collector);
      hkaiIntervalPartition::swap(v19, &v35);
      v35.m_intervals.m_size = 0;
      if ( v35.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v35.m_intervals.m_data,
          20 * (v35.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v35.m_intervals.m_capacityAndFlags = 2147483648;
      v35.m_intervals.m_data = 0i64;
      v34.m_intervals.m_size = 0;
      if ( v34.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v34.m_intervals.m_data,
          20 * (v34.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v11 = v37;
      v17 = retaddr;
      ++v10;
      ++v20;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 864
// RVA: 0x12E5250
void __usercall hkaiGeometrySegmentCaster::turnSegment(hkaiGeometrySegmentCaster *this@<rcx>, hkVector4f *leftStart@<rdx>, hkVector4f *rightStart@<r8>, hkVector4f *leftEnd@<r9>, hkaiIntervalPartition *a5@<rbx>, hkVector4f *rightEnd, hkaiIntervalPartition *partition)
{
  __int64 v7; // rsi
  hkVector4f *v8; // r13
  int v9; // edi
  hkVector4f *v10; // r12
  hkaiGeometrySegmentCaster *v11; // r15
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 *v14; // r8
  __m128 v15; // xmm1
  hkaiIntervalPartition *v16; // r14
  __int64 v17; // rbx
  __m128i v18; // xmm1
  __int64 v19; // rcx
  __m128i v20; // xmm0
  __m128i v21; // xmm1
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+0h] [rbp-79h]
  __int128 v23; // [rsp+10h] [rbp-69h]
  __int128 v24; // [rsp+20h] [rbp-59h]
  __int128 v25; // [rsp+30h] [rbp-49h]
  __int128 v26; // [rsp+40h] [rbp-39h]
  __int64 v27; // [rsp+50h] [rbp-29h]
  int v28; // [rsp+58h] [rbp-21h]
  hkaiIntervalPartition v29; // [rsp+60h] [rbp-19h]
  hkaiIntervalPartition other; // [rsp+70h] [rbp-9h]
  hkAabb aabb; // [rsp+80h] [rbp+7h]
  hkVector4f *v32; // [rsp+D8h] [rbp+5Fh]
  __m128 *retaddr; // [rsp+F0h] [rbp+77h]

  v7 = this->m_geometries.m_size;
  v8 = rightStart;
  v9 = 0;
  v10 = leftEnd;
  v11 = this;
  v12 = _mm_max_ps(leftStart->m_quad, rightStart->m_quad);
  v13 = _mm_min_ps(leftStart->m_quad, rightStart->m_quad);
  v14 = retaddr;
  v15 = _mm_min_ps(v13, leftEnd->m_quad);
  aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(v12, leftEnd->m_quad), *retaddr);
  aabb.m_min.m_quad = _mm_min_ps(v15, *retaddr);
  if ( v7 > 0 )
  {
    v16 = a5;
    v17 = 0i64;
    do
    {
      v18 = (__m128i)v8->m_quad;
      v19 = (__int64)v11->m_geometries.m_data[v17].m_geometry;
      _mm_store_si128((__m128i *)&v23, (__m128i)leftStart->m_quad);
      v20 = (__m128i)v10->m_quad;
      v27 = v19;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace'::GeometryTurnedSegmentQuery::`vftable';
      v28 = v9;
      _mm_store_si128((__m128i *)&v24, v18);
      v21 = *(__m128i *)v14;
      _mm_store_si128((__m128i *)&v25, v20);
      _mm_store_si128((__m128i *)&v26, v21);
      hkaiIntervalPartition::hkaiIntervalPartition(&v29);
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      hkaiIntervalPartition::swap(v16, &other);
      hkcdDynamicAabbTree::queryAabb(
        v11->m_geometries.m_data[v17].m_accelerationData.m_pntr->m_faceTree.m_pntr,
        &aabb,
        &collector);
      hkaiIntervalPartition::swap(v16, &other);
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      other.m_intervals.m_capacityAndFlags = 2147483648;
      other.m_intervals.m_data = 0i64;
      v29.m_intervals.m_size = 0;
      if ( v29.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v29.m_intervals.m_data,
          20 * (v29.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      leftStart = v32;
      v14 = retaddr;
      ++v9;
      ++v17;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 886
// RVA: 0x12E5410
void __usercall hkaiGeometrySegmentCaster::turnSegmentExtruded(hkaiGeometrySegmentCaster *this@<rcx>, hkVector4f *leftStart@<rdx>, hkVector4f *rightStart@<r8>, hkVector4f *leftEnd@<r9>, __m128 *a5@<rbx>, hkVector4f *rightEnd, hkVector4f *extrusion, hkaiIntervalPartition *partition)
{
  __m128 v8; // xmm4
  __int64 v9; // rsi
  __m128 v10; // xmm3
  __m128i *v11; // r13
  __m128 *v12; // rdx
  int v13; // edi
  hkVector4f *v14; // r15
  hkVector4f *v15; // r12
  hkaiGeometrySegmentCaster *v16; // r14
  hkVector4f v17; // xmm4
  __int64 v18; // rbx
  __m128i v19; // xmm1
  __int64 v20; // rcx
  __m128i v21; // xmm0
  __m128i v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm1
  hkaiGeometrySegmentCaster::Geometry *v27; // rax
  __m128i v28; // xmm1
  __int64 v29; // rcx
  hkaiGeometrySegmentCaster::AccelerationData *v30; // rdx
  __m128i v31; // xmm0
  hkcdAabbTreeQueries::AabbCollector v32; // [rsp+20h] [rbp-B8h]
  __int128 v33; // [rsp+30h] [rbp-A8h]
  __int128 v34; // [rsp+40h] [rbp-98h]
  __int64 v35; // [rsp+50h] [rbp-88h]
  __int64 v36; // [rsp+58h] [rbp-80h]
  __int128 v37; // [rsp+60h] [rbp-78h]
  hkaiIntervalPartition v38; // [rsp+70h] [rbp-68h]
  hkaiIntervalPartition v39; // [rsp+80h] [rbp-58h]
  hkAabb aabb; // [rsp+98h] [rbp-40h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+B8h] [rbp-20h]
  __int128 v42; // [rsp+C8h] [rbp-10h]
  __int128 v43; // [rsp+D8h] [rbp+0h]
  __int128 v44; // [rsp+E8h] [rbp+10h]
  __int128 v45; // [rsp+F8h] [rbp+20h]
  __m128 v46; // [rsp+108h] [rbp+30h]
  __m128 v47; // [rsp+118h] [rbp+40h]
  __m128 v48; // [rsp+128h] [rbp+50h]
  __m128 v49; // [rsp+138h] [rbp+60h]
  __int64 v50; // [rsp+148h] [rbp+70h]
  hkaiIntervalPartition v51; // [rsp+150h] [rbp+78h]
  int v52; // [rsp+160h] [rbp+88h]
  hkaiIntervalPartition other; // [rsp+168h] [rbp+90h]
  __m128 *retaddr; // [rsp+1C8h] [rbp+F0h]
  __m128 *v55; // [rsp+1D0h] [rbp+F8h]
  __m128 *v56; // [rsp+1D0h] [rbp+F8h]
  hkaiIntervalPartition *v57; // [rsp+1D8h] [rbp+100h]

  v8 = leftStart->m_quad;
  v9 = this->m_geometries.m_size;
  v10 = leftStart->m_quad;
  v11 = (__m128i *)leftStart;
  v12 = retaddr;
  v13 = 0;
  v14 = leftEnd;
  v15 = rightStart;
  v16 = this;
  v17.m_quad = _mm_sub_ps(
                 _mm_max_ps(_mm_max_ps(_mm_max_ps(v8, rightStart->m_quad), leftEnd->m_quad), *retaddr),
                 _mm_min_ps(*v55, aabbOut.m_quad));
  aabb.m_min.m_quad = _mm_sub_ps(
                        _mm_min_ps(_mm_min_ps(_mm_min_ps(v10, rightStart->m_quad), leftEnd->m_quad), *retaddr),
                        _mm_max_ps(*v55, aabbOut.m_quad));
  aabb.m_max = (hkVector4f)v17.m_quad;
  if ( v9 > 0 )
  {
    v56 = a5;
    v18 = 0i64;
    do
    {
      v19 = (__m128i)v15->m_quad;
      v20 = (__int64)v16->m_geometries.m_data[v18].m_geometry;
      _mm_store_si128((__m128i *)&v42, *v11);
      v21 = (__m128i)v14->m_quad;
      v50 = v20;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace'::DoubledGeometryTurnedSegmentQuery::`vftable';
      _mm_store_si128((__m128i *)&v43, v19);
      v22 = *(__m128i *)v12;
      _mm_store_si128((__m128i *)&v44, v21);
      _mm_store_si128((__m128i *)&v45, v22);
      hkaiIntervalPartition::hkaiIntervalPartition(&v51);
      v52 = v13;
      hkaiIntervalPartition::hkaiIntervalPartition(&other);
      v23 = *v56;
      v24 = _mm_sub_ps(v15->m_quad, *v56);
      v46 = _mm_sub_ps(*(__m128 *)v11, *v56);
      v25 = v14->m_quad;
      v47 = v24;
      v26 = *retaddr;
      v48 = _mm_sub_ps(v25, v23);
      v49 = _mm_sub_ps(v26, v23);
      hkaiIntervalPartition::swap(v57, &other);
      hkcdDynamicAabbTree::queryAabb(
        v16->m_geometries.m_data[v18].m_accelerationData.m_pntr->m_faceTree.m_pntr,
        &aabb,
        &collector);
      v27 = v16->m_geometries.m_data;
      v28 = (__m128i)v15->m_quad;
      v29 = (__int64)v27[v18].m_geometry;
      v30 = v27[v18].m_accelerationData.m_pntr;
      _mm_store_si128((__m128i *)&v33, *v11);
      v31 = (__m128i)v14->m_quad;
      _mm_store_si128((__m128i *)&v34, v28);
      v32.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace'::GeometryExtrusionTurnedSegmentQuery::`vftable';
      v36 = v29;
      _mm_store_si128((__m128i *)&v35, v31);
      DWORD2(v37) = v13;
      _mm_store_si128((__m128i *)&v37, *(__m128i *)retaddr);
      _mm_store_si128((__m128i *)&v38, *(__m128i *)v56);
      *(_QWORD *)&v37 = (char *)v30 + 24;
      hkaiIntervalPartition::hkaiIntervalPartition(&v38);
      hkaiIntervalPartition::hkaiIntervalPartition(&v39);
      hkaiIntervalPartition::swap(&v39, &other);
      hkcdDynamicAabbTree::queryAabb(
        v16->m_geometries.m_data[v18].m_accelerationData.m_pntr->m_edgeTree.m_pntr,
        &aabb,
        &v32);
      hkaiIntervalPartition::swap(v57, &v39);
      v39.m_intervals.m_size = 0;
      if ( v39.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v39.m_intervals.m_data,
          20 * (v39.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v39.m_intervals.m_data = 0i64;
      v39.m_intervals.m_capacityAndFlags = 2147483648;
      v38.m_intervals.m_size = 0;
      if ( v38.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v38.m_intervals.m_data,
          20 * (v38.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v38.m_intervals.m_data = 0i64;
      v38.m_intervals.m_capacityAndFlags = 2147483648;
      v32.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable';
      other.m_intervals.m_size = 0;
      if ( other.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          other.m_intervals.m_data,
          20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      other.m_intervals.m_data = 0i64;
      other.m_intervals.m_capacityAndFlags = 2147483648;
      v51.m_intervals.m_size = 0;
      if ( v51.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v51.m_intervals.m_data,
          20 * (v51.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      v12 = retaddr;
      ++v13;
      ++v18;
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 959
// RVA: 0x12E5770
void __usercall hkaiGeometrySegmentCaster::findExtremalProfile(hkaiGeometrySegmentCaster *this@<rcx>, hkArrayBase<hkVector4f> *clippingPlanes@<rdx>, hkVector4f *left@<r8>, hkVector4f *right@<r9>, __m128i *a5@<rdi>, hkVector4f *extremalVector, hkVector4f *uVector, hkVector4f *vVector, hkaiIntervalPartition *uPartition, hkaiIntervalPartition *vPartition)
{
  hkaiGeometrySegmentCaster *v10; // r14
  hkVector4f *v11; // rsi
  hkVector4f *v12; // r12
  hkArrayBase<hkVector4f> *v13; // rdi
  int v14; // ebx
  hkVector4f *v15; // rdi
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
  __m128i v33; // xmm11
  __int64 v34; // rsi
  int v35; // edi
  __int64 v36; // rbx
  hkaiGeometrySegmentCaster::Geometry *v37; // rax
  __m128i v38; // xmm0
  __int64 v39; // rcx
  hkaiGeometrySegmentCaster::AccelerationData *v40; // rdx
  __m128 v41; // xmm3
  hkVector4f v42; // xmm1
  hkVector4f v43; // xmm2
  __m128 v44; // xmm0
  hkVector4f *v45; // rbx
  hkVector4f *v46; // rdi
  int v47; // esi
  int i; // er15
  hkaiIntervalPartition::Interval *v49; // rax
  float v50; // xmm10_4
  float v51; // xmm9_4
  float v52; // xmm1_4
  hkaiGeometrySegmentCaster::Geometry *v53; // rcx
  hkaiGeometrySegmentCaster::ExtrudedEdge *v54; // rdx
  hkVector4f *v55; // rcx
  __m128 v56; // xmm7
  __m128 v57; // xmm1
  __m128 v58; // xmm6
  __m128 v59; // xmm1
  __m128 v60; // xmm0
  __m128 v61; // xmm1
  __m128 v62; // xmm4
  __m128 v63; // xmm2
  __m128 v64; // xmm1
  __m128 v65; // xmm3
  __m128 v66; // xmm5
  __m128 v67; // xmm8
  __m128 v68; // xmm7
  __m128 v69; // xmm6
  hkaiIntervalPartition other; // [rsp+30h] [rbp-C0h]
  hkgpConvexHull::BuildConfig v71; // [rsp+40h] [rbp-B0h]
  unsigned int data; // [rsp+50h] [rbp-A0h]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+60h] [rbp-90h]
  hkgpConvexHull *v74; // [rsp+68h] [rbp-88h]
  __int128 v75; // [rsp+70h] [rbp-80h]
  __int64 v76; // [rsp+80h] [rbp-70h]
  hkArray<hkaiGeometrySegmentCaster::ExtrudedEdge,hkContainerHeapAllocator> *v77; // [rsp+88h] [rbp-68h]
  int v78; // [rsp+90h] [rbp-60h]
  hkaiIntervalPartition v79; // [rsp+98h] [rbp-58h]
  hkMatrix4f out; // [rsp+B0h] [rbp-40h]
  hkgpConvexHull v81; // [rsp+F0h] [rbp+0h]
  hkMatrix4f m; // [rsp+120h] [rbp+30h]
  hkAabb result; // [rsp+160h] [rbp+70h]
  hkaiGeometrySegmentCaster::HitType hitType; // [rsp+220h] [rbp+130h]
  __m128i *v85; // [rsp+240h] [rbp+150h]
  __m128 *v86; // [rsp+248h] [rbp+158h]

  v85 = a5;
  v10 = this;
  v11 = right;
  v12 = left;
  v13 = clippingPlanes;
  hkgpConvexHull::hkgpConvexHull(&v81);
  v14 = v13->m_size;
  v15 = v13->m_data;
  hkgpConvexHull::BuildConfig::BuildConfig(&v71);
  hkgpConvexHull::buildFromPlanes(&v81, v15, v14, v16);
  hkgpConvexHull::getBoundingBox(&v81, &result, INTERNAL_VERTICES, 1.0, 0.0);
  v17 = (__m128i *)extremalVector;
  v18 = (__m128i *)v86;
  v19 = (__m128i)_mm_sub_ps(v11->m_quad, v12->m_quad);
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(extremalVector->m_quad, extremalVector->m_quad, 201), *v86),
          _mm_mul_ps(_mm_shuffle_ps(*v86, *v86, 201), extremalVector->m_quad));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_mul_ps(v21, v21);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_rsqrt_ps(v23);
  v25 = _mm_mul_ps(
          v21,
          _mm_andnot_ps(
            _mm_cmpleps(v23, (__m128)0i64),
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
  v32 = _mm_mul_ps(v31, v12->m_quad);
  v33 = (__m128i)_mm_shuffle_ps(
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
  v34 = v10->m_geometries.m_size;
  v35 = 0;
  if ( v34 > 0 )
  {
    v36 = 0i64;
    do
    {
      v37 = v10->m_geometries.m_data;
      v38 = *v85;
      v39 = (__int64)v37[v36].m_geometry;
      v40 = v37[v36].m_accelerationData.m_pntr;
      _mm_store_si128((__m128i *)&v75, v33);
      _mm_store_si128((__m128i *)&v75, v38);
      v74 = &v81;
      v76 = v39;
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&`anonymous namespace'::GeometryExtremalProfileQuery::`vftable';
      v78 = v35;
      v77 = &v40->m_edges;
      hkaiIntervalPartition::hkaiIntervalPartition(&v79);
      hkaiIntervalPartition::swap(&v79, &other);
      hkcdDynamicAabbTree::queryAabb(
        v10->m_geometries.m_data[v36].m_accelerationData.m_pntr->m_edgeTree.m_pntr,
        &result,
        &collector);
      hkaiIntervalPartition::swap(&v79, &other);
      v79.m_intervals.m_size = 0;
      if ( v79.m_intervals.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v79.m_intervals.m_data,
          20 * (v79.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
      ++v35;
      ++v36;
      --v34;
    }
    while ( v34 );
    v18 = (__m128i *)v86;
    v17 = (__m128i *)extremalVector;
  }
  hkaiIntervalPartition::clipX(&other, 0.0, 1.0);
  if ( other.m_intervals.m_size )
  {
    v41 = v12->m_quad;
    v42.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(*v18, 4), 4);
    v43.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(*v17, 4), 4);
    v44 = v12->m_quad;
    out.m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(v19, 4), 4);
    m.m_col2 = out.m_col2;
    out.m_col0 = (hkVector4f)v42.m_quad;
    m.m_col0 = (hkVector4f)v42.m_quad;
    out.m_col1 = (hkVector4f)v43.m_quad;
    *(float *)&v86 = FLOAT_0_001;
    out.m_col3.m_quad = _mm_shuffle_ps(v41, _mm_unpackhi_ps(v44, query.m_quad), 196);
    m.m_col1 = (hkVector4f)v43.m_quad;
    m.m_col3 = out.m_col3;
    v71 = (hkgpConvexHull::BuildConfig)_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_001), (__m128)LODWORD(FLOAT_0_001), 0);
    __hkMatrix4UtilAlgo::setInverse((hkResult *)&v86, &m, &out, (hkSimdFloat32 *)&v71);
    v45 = uVector;
    hkaiIntervalPartition::reserve((hkaiIntervalPartition *)uVector, other.m_intervals.m_size);
    v46 = vVector;
    hkaiIntervalPartition::reserve((hkaiIntervalPartition *)vVector, other.m_intervals.m_size);
    v47 = other.m_intervals.m_size;
    for ( i = 0; i < v47; ++i )
    {
      v49 = hkaiIntervalPartition::getInterval(&other, i);
      v50 = v49->m_leftX;
      v51 = v49->m_rightX;
      v52 = v49->m_offset;
      *(float *)&v71.m_setSourceIndices.m_bool = v49->m_slope;
      data = v49->m_data;
      *(float *)&v71.m_allowLowerDimensions.m_bool = v50;
      v71.m_minCosAngle = v51;
      *(float *)&v71.m_internalInputs.m_bool = v52;
      hkaiGeometrySegmentCaster::unpackData(data, &hitType, (unsigned int *)&v86, (unsigned int *)&extremalVector);
      v53 = &v10->m_geometries.m_data[(signed int)v86];
      v54 = v53->m_accelerationData.m_pntr->m_edges.m_data;
      v55 = v53->m_geometry->m_vertices.m_data;
      v56 = v55[v54[(signed int)extremalVector].m_a].m_quad;
      v57 = _mm_mul_ps(v55[v54[(signed int)extremalVector].m_a].m_quad, (__m128)v33);
      v58 = _mm_sub_ps(v55[v54[(signed int)extremalVector].m_b].m_quad, v56);
      v59 = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, (__m128)v33), 196);
      v60 = _mm_add_ps(_mm_shuffle_ps(v59, v59, 78), v59);
      v61 = _mm_mul_ps((__m128)v33, v58);
      v62 = _mm_add_ps(_mm_shuffle_ps(v60, v60, 177), v60);
      v63 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
              _mm_shuffle_ps(v61, v61, 170));
      v64 = _mm_rcp_ps(v63);
      v65 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v64, v63)), v64);
      v66 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps(
                      (__m128)*(unsigned int *)&v71.m_allowLowerDimensions.m_bool,
                      (__m128)*(unsigned int *)&v71.m_allowLowerDimensions.m_bool,
                      0),
                    v62),
                  v65),
                v58),
              v56);
      v67 = _mm_add_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_shuffle_ps((__m128)LODWORD(v71.m_minCosAngle), (__m128)LODWORD(v71.m_minCosAngle), 0),
                    v62),
                  v65),
                v58),
              v56);
      v68 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v66, v66, 0), out.m_col0.m_quad), out.m_col3.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v66, v66, 85), out.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v66, v66, 170), out.m_col2.m_quad));
      v69 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v67, v67, 0), out.m_col0.m_quad), out.m_col3.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v67, v67, 85), out.m_col1.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v67, v67, 170), out.m_col2.m_quad));
      hkaiIntervalPartition::appendIntervalFromEndpoints(
        (hkaiIntervalPartition *)v45,
        v50,
        v68.m128_f32[0],
        v51,
        v69.m128_f32[0],
        0xFFFFFFFF);
      hkaiIntervalPartition::appendIntervalFromEndpoints(
        (hkaiIntervalPartition *)v46,
        v50,
        COERCE_FLOAT(_mm_shuffle_ps(v68, v68, 85)),
        v51,
        COERCE_FLOAT(_mm_shuffle_ps(v69, v69, 85)),
        0xFFFFFFFF);
    }
  }
  other.m_intervals.m_size = 0;
  if ( other.m_intervals.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      other.m_intervals.m_data,
      20 * (other.m_intervals.m_capacityAndFlags & 0x3FFFFFFF));
  other.m_intervals.m_data = 0i64;
  other.m_intervals.m_capacityAndFlags = 2147483648;
  hkgpConvexHull::~hkgpConvexHull(&v81);
}

// File Line: 1094
// RVA: 0x12E5E30
__int64 __fastcall hkaiGeometrySegmentCaster::packData(hkaiGeometrySegmentCaster::HitType hitType, unsigned int geometryIndex, unsigned int nodeIndex)
{
  return nodeIndex | ((geometryIndex | 4 * hitType) << 28);
}

// File Line: 1101
// RVA: 0x12E5E50
void __fastcall hkaiGeometrySegmentCaster::unpackData(unsigned int data, hkaiGeometrySegmentCaster::HitType *hitType, unsigned int *geometryIndex, unsigned int *nodeIndex)
{
  *hitType = data >> 30;
  *geometryIndex = (data >> 28) & 3;
  *nodeIndex = data & 0xFFFFFFF;
}

// File Line: 1108
// RVA: 0x12E5DD0
__int64 __fastcall hkaiGeometrySegmentCaster::AccelerationData::getSize(hkaiGeometrySegmentCaster::AccelerationData *this)
{
  hkaiGeometrySegmentCaster::AccelerationData *v1; // rdi
  hkcdDynamicAabbTree *v2; // rcx
  int v3; // esi
  int v4; // ebx

  v1 = this;
  v2 = this->m_edgeTree.m_pntr;
  if ( v2 )
    v3 = hkcdDynamicAabbTree::getMemoryFootPrint(v2);
  else
    v3 = 0;
  v4 = v1->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  return v3 + (unsigned int)hkcdDynamicAabbTree::getMemoryFootPrint(v1->m_faceTree.m_pntr) + 8 * (v4 + 6);
}

