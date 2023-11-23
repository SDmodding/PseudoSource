// File Line: 45
// RVA: 0xC17640
__int64 __fastcall doesSegmentIntersectPlaneRegions(
        hkVector4f *A,
        hkVector4f *B,
        hkVector4f *edgePlane1,
        hkVector4f *edgePlane2,
        hkVector4f *vertex)
{
  __m128 m_quad; // xmm4
  __m128 v6; // xmm8
  __m128 v7; // xmm9
  __m128 v8; // xmm10
  unsigned int v9; // ecx
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  bool v16; // cf
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  int v19; // r8d
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  int v24; // edx
  __m128 v25; // xmm5
  __m128 v26; // xmm10
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm2
  __m128 v34; // xmm10
  __m128 v35; // xmm10
  __m128 v36; // xmm1
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm1
  __m128 v41; // xmm3

  m_quad = B->m_quad;
  v6 = edgePlane1->m_quad;
  v7 = edgePlane2->m_quad;
  v8 = A->m_quad;
  v9 = 0;
  v10 = _mm_mul_ps(edgePlane1->m_quad, v8);
  v11 = _mm_mul_ps(B->m_quad, edgePlane1->m_quad);
  v12 = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, edgePlane1->m_quad), 196);
  v13 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, edgePlane1->m_quad), 196);
  v14 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v15 = _mm_add_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v16 = (float)(_mm_shuffle_ps(v15, v15, 177).m128_f32[0] + v15.m128_f32[0]) < 0.0;
  v17 = _mm_mul_ps(edgePlane2->m_quad, v8);
  v18 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, edgePlane2->m_quad), 196);
  v19 = ((float)(_mm_shuffle_ps(v14, v14, 177).m128_f32[0] + v14.m128_f32[0]) < 0.0) + v16;
  v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v21 = _mm_mul_ps(edgePlane2->m_quad, B->m_quad);
  v22 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, edgePlane2->m_quad), 196);
  v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 78), v22);
  v24 = ((float)(_mm_shuffle_ps(v23, v23, 177).m128_f32[0] + v23.m128_f32[0]) < 0.0)
      + ((float)(_mm_shuffle_ps(v20, v20, 177).m128_f32[0] + v20.m128_f32[0]) < 0.0);
  if ( !v19 || !v24 )
    return 0i64;
  if ( v19 == 2 || v24 == 2 )
    return 1i64;
  v25 = _mm_sub_ps(v8, m_quad);
  v26 = _mm_sub_ps(v8, vertex->m_quad);
  v27 = _mm_mul_ps(v25, v25);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_mul_ps(v26, v25);
  v30 = _mm_rcp_ps(v28);
  v31 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v28, v30)), v30),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
            _mm_shuffle_ps(v29, v29, 170)));
  v32 = _mm_cmplt_ps(v31, query.m_quad);
  v33 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v31, v32), _mm_andnot_ps(v32, query.m_quad)));
  v34 = _mm_add_ps(_mm_sub_ps(v26, _mm_mul_ps(v33, v25)), vertex->m_quad);
  v35 = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, v33), 196);
  v36 = _mm_mul_ps(v6, v35);
  v37 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v6), 196);
  v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
  v39 = _mm_mul_ps(v7, v35);
  v40 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, v7), 196);
  v41 = _mm_add_ps(_mm_shuffle_ps(v40, v40, 78), v40);
  if ( (float)(_mm_shuffle_ps(v38, v38, 177).m128_f32[0] + v38.m128_f32[0]) < 0.0
    && (float)(_mm_shuffle_ps(v41, v41, 177).m128_f32[0] + v41.m128_f32[0]) < 0.0 )
  {
    return 1;
  }
  return v9;
}

// File Line: 85
// RVA: 0xC178A0
void __fastcall clipSegmentToSinglePlaneRegion(hkVector4f *A, hkVector4f *B, hkVector4f *edgePlane1)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm1
  __m128 v5; // xmm0
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm4
  __m128 v11; // xmm1
  __m128 v12; // xmm0
  __m128 v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm1

  v3 = _mm_mul_ps(edgePlane1->m_quad, A->m_quad);
  v4 = _mm_shuffle_ps(v3, _mm_unpackhi_ps(v3, edgePlane1->m_quad), 196);
  v5 = _mm_add_ps(_mm_shuffle_ps(v4, v4, 78), v4);
  v6 = _mm_mul_ps(edgePlane1->m_quad, B->m_quad);
  v7 = _mm_add_ps(_mm_shuffle_ps(v5, v5, 177), v5);
  v8 = _mm_shuffle_ps(v6, _mm_unpackhi_ps(v6, edgePlane1->m_quad), 196);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9);
  if ( (float)(v10.m128_f32[0] * v7.m128_f32[0]) < 0.0 )
  {
    if ( v7.m128_f32[0] <= 0.0 )
    {
      v14 = _mm_sub_ps(v10, v7);
      v15 = _mm_rcp_ps(v14);
      v16 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(A->m_quad, B->m_quad),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15), v10)),
              B->m_quad);
      *B = (hkVector4f)v16;
      B->m_quad = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, query.m_quad), 196);
    }
    else
    {
      v11 = _mm_sub_ps(v7, v10);
      v12 = _mm_rcp_ps(v11);
      v13 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(B->m_quad, A->m_quad),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v12)), v12), v7)),
              A->m_quad);
      *A = (hkVector4f)v13;
      A->m_quad = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196);
    }
  }
}

// File Line: 111
// RVA: 0xC17880
void __fastcall clipSegmentToPlaneRegions(hkVector4f *A, hkVector4f *B, hkVector4f *edgePlane1, hkVector4f *edgePlane2)
{
  hkVector4f *v4; // rdx
  hkVector4f *v5; // rcx
  hkVector4f *v6; // r9

  clipSegmentToSinglePlaneRegion(A, B, edgePlane1);
  clipSegmentToSinglePlaneRegion(v5, v4, v6);
}

// File Line: 126
// RVA: 0xC14BB0
__int64 __fastcall hkaiNavMeshTraversalUtils::isEdgePairTraversable(
        hkSimdFloat32 *diameter,
        hkaiNavMeshInstance *meshInstance,
        unsigned int faceIndex,
        int edgeInIndex,
        int edgeOutIndex,
        hkVector4f *up)
{
  _QWORD *Value; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  _QWORD *v14; // rcx
  hkaiNavMesh::Face *v15; // rax
  int m_numOriginalEdges; // edi
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v17; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v18; // r9
  unsigned int insideEdgeKey; // r15d
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v20; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v21; // r9
  hkaiNavMesh::Edge *v22; // rax
  __int64 m_a; // rcx
  int m_numOriginalVertices; // edx
  hkaiNavMesh::Edge *v25; // rbx
  hkVector4f *v26; // rcx
  hkVector4f v27; // xmm3
  hkVector4f v28; // xmm4
  __int64 m_b; // rax
  hkVector4f v30; // xmm5
  __m128 v31; // xmm2
  hkVector4f *v32; // rax
  __m128 m_quad; // xmm1
  unsigned int edgeOutKey; // edi
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v36; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  unsigned int isEdgePairTraversable; // ebx
  _QWORD *v39; // r8
  _QWORD *v40; // rcx
  unsigned __int64 v41; // rax
  _QWORD *v42; // rcx
  hkaiNavMesh::Face *face; // [rsp+70h] [rbp-90h]
  hkaiNavMesh::Edge *edgeOut; // [rsp+78h] [rbp-88h]
  hkaiStreamingCollection array; // [rsp+80h] [rbp-80h] BYREF
  hkaiGeneralAccessor accessor; // [rsp+B0h] [rbp-50h] BYREF
  hkVector4f edgeA; // [rsp+D0h] [rbp-30h] BYREF
  hkVector4f edgeB; // [rsp+E0h] [rbp-20h] BYREF
  hkVector4f inA; // [rsp+F0h] [rbp-10h] BYREF
  hkVector4f inB; // [rsp+100h] [rbp+0h] BYREF
  hkResult result; // [rsp+148h] [rbp+48h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)Value[1];
  v12 = Value;
  if ( (unsigned __int64)v11 < Value[3] )
  {
    *v11 = "TttraverseCheck";
    v13 = __rdtsc();
    v14 = v11 + 2;
    *((_DWORD *)v14 - 2) = v13;
    v12[1] = v14;
  }
  v15 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__13(
          meshInstance->m_originalFaces,
          meshInstance->m_numOriginalFaces,
          &meshInstance->m_instancedFaces,
          &meshInstance->m_ownedFaces,
          &meshInstance->m_faceMap,
          faceIndex);
  m_numOriginalEdges = meshInstance->m_numOriginalEdges;
  face = v15;
  edgeOut = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
              meshInstance->m_originalEdges,
              m_numOriginalEdges,
              &meshInstance->m_instancedEdges,
              &meshInstance->m_ownedEdges,
              &meshInstance->m_edgeMap,
              edgeOutIndex);
  insideEdgeKey = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                    meshInstance->m_originalEdges,
                    m_numOriginalEdges,
                    v17,
                    v18,
                    &meshInstance->m_edgeMap,
                    edgeInIndex)->m_oppositeEdge;
  v22 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
          meshInstance->m_originalEdges,
          m_numOriginalEdges,
          v20,
          v21,
          &meshInstance->m_edgeMap,
          insideEdgeKey);
  m_a = v22->m_a;
  m_numOriginalVertices = meshInstance->m_numOriginalVertices;
  v25 = v22;
  if ( (int)m_a >= m_numOriginalVertices )
    v26 = &meshInstance->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
  else
    v26 = &meshInstance->m_originalVertices[m_a];
  v27.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col1;
  v28.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col0;
  m_b = v22->m_b;
  v30.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col2;
  v31 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v26->m_quad, v26->m_quad, 0), v28.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v26->m_quad, v26->m_quad, 85), v27.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v26->m_quad, v26->m_quad, 170), v30.m_quad)),
          meshInstance->m_referenceFrame.m_transform.m_translation.m_quad);
  if ( (int)m_b >= m_numOriginalVertices )
    v32 = &meshInstance->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
  else
    v32 = &meshInstance->m_originalVertices[m_b];
  m_quad = v32->m_quad;
  edgeOutKey = edgeOutIndex;
  inB.m_quad = v31;
  inA.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v28.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v27.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v30.m_quad)),
                 meshInstance->m_referenceFrame.m_transform.m_translation.m_quad);
  hkaiNavMeshInstance::getEdgePoints(meshInstance, edgeOutIndex, &edgeA, &edgeB);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v36 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v36;
    }
    while ( v36 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_instancePtr = meshInstance;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  accessor.m_accessor = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  accessor.m_sectionInfo = array.m_instances.m_data;
  accessor.m_currentSection = -1;
  isEdgePairTraversable = hkaiNavMeshTraversalUtils::isEdgePairTraversable(
                            diameter,
                            &accessor,
                            faceIndex,
                            face,
                            up,
                            v25,
                            edgeOut,
                            insideEdgeKey,
                            edgeOutKey,
                            &inA,
                            &inB,
                            &edgeA,
                            &edgeB);
  v39 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v40 = (_QWORD *)v39[1];
  if ( (unsigned __int64)v40 < v39[3] )
  {
    *v40 = "Et";
    v41 = __rdtsc();
    v42 = v40 + 2;
    *((_DWORD *)v42 - 2) = v41;
    v39[1] = v42;
  }
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  return isEdgePairTraversable;
}

// File Line: 156
// RVA: 0xC13B90
_BOOL8 __fastcall hkaiNavMeshTraversalUtils::Angle::isOriented(hkaiNavMeshTraversalUtils::Angle *this)
{
  return ((this->b > this->c) + (this->a > this->b) + (this->a > this->c)) % 2 == 0;
}

// File Line: 161
// RVA: 0xC13BF0
_BOOL8 __fastcall hkaiNavMeshTraversalUtils::Angle::containsEdge(
        hkaiNavMeshTraversalUtils::Angle *this,
        unsigned int e,
        int n)
{
  return this->a == e && this->b == (this->a + 1) % n || *(_QWORD *)&this->b == __PAIR64__((this->b + 1) % n, e);
}

// File Line: 167
// RVA: 0xC13C30
BOOL __fastcall hkaiNavMeshTraversalUtils::Angle::sectorContainsEdge(
        hkaiNavMeshTraversalUtils::Angle *this,
        int e,
        int n)
{
  int a; // r8d
  int b; // eax

  a = this->a;
  if ( !this->a )
    return e > this->b;
  b = this->b;
  if ( !b )
    return e == this->c;
  if ( !this->c )
    return e < a;
  return e != a && e != b;
}

// File Line: 187
// RVA: 0xC13C80
void __fastcall hkaiNavMeshTraversalUtils::Angle::orient(hkaiNavMeshTraversalUtils::Angle *this)
{
  int a; // edx

  if ( !hkaiNavMeshTraversalUtils::Angle::isOriented(this) )
  {
    a = this->a;
    this->a = this->c;
    this->c = a;
  }
}

// File Line: 195
// RVA: 0xC13CB0
void __fastcall hkaiNavMeshTraversalUtils::Angle::fromEdgePair(
        hkaiNavMeshTraversalUtils::Angle *this,
        int x,
        int y,
        int z,
        int w)
{
  int v5; // eax

  if ( x == z || x == w )
  {
    v5 = x;
    x = y;
    y = v5;
  }
  this->a = x;
  this->b = y;
  if ( y == z )
    z = w;
  this->c = z;
  hkaiNavMeshTraversalUtils::Angle::orient(this);
}

// File Line: 222
// RVA: 0xC13CF0
__int64 __fastcall hkaiNavMeshTraversalUtils::Angle::index(hkaiNavMeshTraversalUtils::Angle *this)
{
  int a; // edx
  int v3; // eax

  a = this->a;
  if ( !this->a )
    return (unsigned int)(this->b + 2 * this->b - 3);
  if ( this->b )
  {
    v3 = 2 * a - 1;
  }
  else
  {
    a = this->c;
    v3 = 2 * a - 2;
  }
  return (unsigned int)(a + v3);
}

// File Line: 244
// RVA: 0xC13D30
void __fastcall hkaiNavMeshTraversalUtils::Angle::rotate(hkaiNavMeshTraversalUtils::Angle *this)
{
  int a; // edx
  int c; // eax

  a = this->a;
  this->a = this->b;
  c = this->c;
  this->c = a;
  this->b = c;
}

// File Line: 255
// RVA: 0xC17D60
__int64 __fastcall checkPath_AddToArray_(int n, int x, int y, AddToArray pred)
{
  int v4; // edi
  int v5; // r10d
  int v7; // ebx
  int v8; // r8d
  hkaiNavMeshTraversalUtils::Angle *v9; // r8
  int v10; // edx
  hkaiNavMeshTraversalUtils::Angle *v11; // r8
  hkaiNavMeshTraversalUtils::Angle v13; // [rsp+30h] [rbp-18h] BYREF

  v4 = y;
  v5 = x;
  if ( n == 3 )
  {
    hkaiNavMeshTraversalUtils::Angle::fromEdgePair(&v13, x, (x + 1) % 3, y, (y + 1) % 3);
LABEL_13:
    v11 = &pred.m_array->m_data[pred.m_array->m_size];
    if ( v11 )
      *v11 = v13;
    ++pred.m_array->m_size;
    return 0i64;
  }
  if ( x > y )
  {
    v4 = x;
    v5 = y;
  }
  v7 = (v5 + 1) % n;
  v8 = v7;
  if ( !v5 )
    v7 = 2;
  do
  {
    hkaiNavMeshTraversalUtils::Angle::fromEdgePair(&v13, v5, v8, v7, 0);
    v9 = &pred.m_array->m_data[pred.m_array->m_size];
    if ( v9 )
      *v9 = v13;
    ++pred.m_array->m_size;
    v5 = v7;
    v8 = 0;
    v10 = (v7 + 1) % n;
    v7 = v10;
  }
  while ( v10 && v10 <= v4 );
  if ( v4 != n - 1 )
  {
    hkaiNavMeshTraversalUtils::Angle::fromEdgePair(&v13, v5, 0, v4, (v4 + 1) % n);
    goto LABEL_13;
  }
  return 0i64;
}

// File Line: 311
// RVA: 0xC17980
__int64 __fastcall findEdgeIndexInFace(hkaiNavMesh::Face *face, int edgeIndex)
{
  return (unsigned int)(edgeIndex - face->m_startEdgeIndex);
}

// File Line: 320
// RVA: 0xC17990
void __fastcall getFaceVertex(hkaiGeneralAccessor *accessor, hkaiNavMesh::Face *face, int index, hkVector4f *vecOut)
{
  hkaiNavMeshInstance *m_accessor; // rbx
  __int64 m_a; // rcx
  int m_numOriginalVertices; // eax
  __m128 *p_m_quad; // rax

  m_accessor = accessor->m_accessor;
  m_a = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
          m_accessor->m_originalEdges,
          m_accessor->m_numOriginalEdges,
          &m_accessor->m_instancedEdges,
          &m_accessor->m_ownedEdges,
          &m_accessor->m_edgeMap,
          index + face->m_startEdgeIndex)->m_a;
  m_numOriginalVertices = m_accessor->m_numOriginalVertices;
  if ( (int)m_a >= m_numOriginalVertices )
    p_m_quad = &m_accessor->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
  else
    p_m_quad = &m_accessor->m_originalVertices[m_a].m_quad;
  vecOut->m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_shuffle_ps(*p_m_quad, *p_m_quad, 85),
                           m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                         _mm_mul_ps(
                           _mm_shuffle_ps(*p_m_quad, *p_m_quad, 0),
                           m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                       _mm_mul_ps(
                         _mm_shuffle_ps(*p_m_quad, *p_m_quad, 170),
                         m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                     m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
}

// File Line: 334
// RVA: 0xC17A40
__int64 __fastcall findTriangle(
        hkaiGeneralAccessor *accessor,
        hkaiNavMesh::Face *face,
        hkVector4f *up,
        hkVector4f *point)
{
  int v8; // ebx
  __m128 m_quad; // xmm6
  __m128 v10; // xmm8
  int v11; // edi
  __m128 v12; // xmm6
  __m128 v13; // xmm9
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  hkVector4f vecOut; // [rsp+20h] [rbp-68h] BYREF

  v8 = 2;
  getFaceVertex(accessor, face, 0, &vecOut);
  m_quad = point->m_quad;
  v10 = vecOut.m_quad;
  v11 = face->m_numEdges - 1;
  v12 = _mm_sub_ps(m_quad, vecOut.m_quad);
  if ( v11 <= 2 )
    return 1i64;
  v13 = up->m_quad;
  v14 = _mm_shuffle_ps(v12, v12, 201);
  do
  {
    getFaceVertex(accessor, face, v8, &vecOut);
    v15 = _mm_sub_ps(vecOut.m_quad, v10);
    v16 = _mm_sub_ps(_mm_mul_ps(v14, v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v12));
    v17 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v13);
    if ( (float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
               + _mm_shuffle_ps(v17, v17, 170).m128_f32[0]) < 0.0 )
      break;
    ++v8;
  }
  while ( v8 < v11 );
  return (unsigned int)(v8 - 1);
}

// File Line: 417
// RVA: 0xC14F10
__int64 __fastcall hkaiNavMeshTraversalUtils::isEdgePairTraversable(
        hkSimdFloat32 *_diameter,
        hkaiGeneralAccessor *accessor,
        unsigned int faceKey,
        hkaiNavMesh::Face *face,
        hkVector4f *up,
        hkaiNavMesh::Edge *insideEdge,
        hkaiNavMesh::Edge *edgeOut,
        unsigned int insideEdgeKey,
        unsigned int edgeOutKey,
        hkVector4f *inA,
        hkVector4f *inB,
        hkVector4f *outA,
        hkVector4f *outB)
{
  __int128 v13; // xmm14
  __int128 v14; // xmm15
  char m_storage; // r15
  __m128 v16; // xmm6
  int v17; // ebp
  int v21; // r15d
  __m128 v22; // xmm13
  __m128 v23; // xmm2
  __m128 v24; // xmm12
  __m128 v25; // xmm1
  __m128 v26; // xmm11
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm10
  __m128 v30; // xmm9
  __m128 v31; // xmm1
  __m128 v32; // xmm6
  __m128 v33; // xmm1
  __m128 v34; // xmm7
  __m128 v35; // xmm4
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm5
  __m128 v40; // xmm1
  __m128 v41; // xmm8
  __m128 v42; // xmm7
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  __m128 v46; // xmm0
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm5
  __m128 v51; // xmm5
  int m_numEdges; // ecx
  int v53; // edx
  int v54; // r8d
  int v56; // esi
  __m128 v57; // xmm7
  int m_startEdgeIndex; // ebx
  hkaiNavMesh::Edge *v59; // rbx
  __m128 v60; // xmm2
  __m128 v61; // xmm2
  __m128 v62; // xmm2
  __m128 v63; // xmm2
  hkSimdFloat32 maxClearance; // [rsp+30h] [rbp-128h] BYREF
  hkSimdFloat32 result; // [rsp+40h] [rbp-118h] BYREF
  HasNoClearance pred; // [rsp+50h] [rbp-108h] BYREF
  __int128 v67; // [rsp+90h] [rbp-C8h]
  __int128 v68; // [rsp+A0h] [rbp-B8h]
  unsigned int insideEdgea; // [rsp+188h] [rbp+30h]
  unsigned int insideEdgeb; // [rsp+188h] [rbp+30h]

  m_storage = insideEdge->m_flags.m_storage;
  v16 = _mm_mul_ps(_diameter->m_real, _diameter->m_real);
  v17 = edgeOut->m_flags.m_storage & 0x10;
  maxClearance.m_real = v16;
  v21 = m_storage & 0x10;
  if ( v21 || v17 )
  {
    v56 = faceKey >> 22;
    hkaiGeneralAccessor::setSection(accessor, faceKey >> 22);
    v57 = _mm_shuffle_ps(
            (__m128)LODWORD(accessor->m_accessor->m_maxGlobalClearance),
            (__m128)LODWORD(accessor->m_accessor->m_maxGlobalClearance),
            0);
    maxClearance.m_real = v57;
    hkaiGeneralAccessor::setSection(accessor, v56);
    insideEdgea = accessor->m_accessor->m_globalClearanceCache.m_data[edgeOut->m_a].m_value << 16;
    if ( _mm_shuffle_ps((__m128)insideEdgea, (__m128)insideEdgea, 0).m128_f32[0] > v57.m128_f32[0] )
      hkaiNavMeshTraversalUtils::computeGlobalClearance(&result, accessor, faceKey, edgeOut, up, &maxClearance);
    m_startEdgeIndex = (edgeOutKey & 0x3FFFFF) + 1;
    if ( m_startEdgeIndex >= face->m_startEdgeIndex + face->m_numEdges )
      m_startEdgeIndex = face->m_startEdgeIndex;
    hkaiGeneralAccessor::setSection(accessor, edgeOutKey >> 22);
    v59 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            accessor->m_accessor->m_originalEdges,
            accessor->m_accessor->m_numOriginalEdges,
            &accessor->m_accessor->m_instancedEdges,
            &accessor->m_accessor->m_ownedEdges,
            &accessor->m_accessor->m_edgeMap,
            m_startEdgeIndex);
    hkaiGeneralAccessor::setSection(accessor, v56);
    insideEdgeb = accessor->m_accessor->m_globalClearanceCache.m_data[v59->m_a].m_value << 16;
    if ( _mm_shuffle_ps((__m128)insideEdgeb, (__m128)insideEdgeb, 0).m128_f32[0] > v57.m128_f32[0] )
      hkaiNavMeshTraversalUtils::computeGlobalClearance(&result, accessor, faceKey, v59, up, &maxClearance);
    if ( !v17 )
    {
      v60 = _mm_sub_ps(outA->m_quad, outB->m_quad);
      v61 = _mm_mul_ps(v60, v60);
      return (float)((float)(_mm_shuffle_ps(v61, v61, 85).m128_f32[0] + _mm_shuffle_ps(v61, v61, 0).m128_f32[0])
                   + _mm_shuffle_ps(v61, v61, 170).m128_f32[0]) >= v16.m128_f32[0];
    }
    if ( !v21 )
    {
      v62 = _mm_sub_ps(inA->m_quad, inB->m_quad);
      v63 = _mm_mul_ps(v62, v62);
      return (float)((float)(_mm_shuffle_ps(v63, v63, 85).m128_f32[0] + _mm_shuffle_ps(v63, v63, 0).m128_f32[0])
                   + _mm_shuffle_ps(v63, v63, 170).m128_f32[0]) >= v16.m128_f32[0];
    }
  }
  else
  {
    v68 = v13;
    v67 = v14;
    v22 = _mm_sub_ps(outB->m_quad, inB->m_quad);
    v23 = _mm_sub_ps(outA->m_quad, inB->m_quad);
    v24 = _mm_sub_ps(inA->m_quad, outA->m_quad);
    v25 = _mm_mul_ps(v24, v22);
    v26 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
            _mm_shuffle_ps(v25, v25, 170));
    v27 = _mm_mul_ps(v23, v22);
    v28 = _mm_mul_ps(v23, v24);
    v29 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
            _mm_shuffle_ps(v27, v27, 170));
    v30 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
            _mm_shuffle_ps(v28, v28, 170));
    v31 = _mm_mul_ps(v22, v22);
    v32 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
            _mm_shuffle_ps(v31, v31, 170));
    v33 = _mm_mul_ps(v24, v24);
    v34 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
            _mm_shuffle_ps(v33, v33, 170));
    v35 = _mm_max_ps(_mm_sub_ps(_mm_mul_ps(v34, v32), _mm_mul_ps(v26, v26)), *(__m128 *)&epsilon);
    v36 = _mm_rcp_ps(v35);
    v37 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v36, v35)), v36);
    v38 = _mm_rcp_ps(v34);
    v39 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v34)), v38);
    v40 = _mm_rcp_ps(v32);
    v41 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v32)), v40);
    v42 = _mm_sub_ps(_mm_mul_ps(v34, v29), _mm_mul_ps(v30, v26));
    v43 = _mm_cmple_ps(v35, *(__m128 *)&epsilon);
    v44 = _mm_cmplt_ps(v42, v35);
    v45 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  v43,
                  _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v42, v44), _mm_andnot_ps(v44, v35))), v37)),
                _mm_and_ps(v43, query.m_quad)),
              _mm_mul_ps(v39, v26)),
            _mm_mul_ps(v39, v30));
    v46 = _mm_cmplt_ps(v45, query.m_quad);
    v47 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v45, v46), _mm_andnot_ps(v46, query.m_quad)));
    v48 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v41, v26), v47), _mm_mul_ps(v41, v29));
    v49 = _mm_cmplt_ps(v48, query.m_quad);
    v50 = _mm_sub_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v48, v49), _mm_andnot_ps(v49, query.m_quad))),
                v22),
              inB->m_quad),
            _mm_add_ps(_mm_mul_ps(v47, v24), outA->m_quad));
    v51 = _mm_mul_ps(v50, v50);
    if ( (float)((float)(_mm_shuffle_ps(v51, v51, 85).m128_f32[0] + _mm_shuffle_ps(v51, v51, 0).m128_f32[0])
               + _mm_shuffle_ps(v51, v51, 170).m128_f32[0]) < maxClearance.m_real.m128_f32[0] )
    {
      pred.m_diameter2 = (hkSimdFloat32)maxClearance.m_real;
      m_numEdges = face->m_numEdges;
      pred.m_face = face;
      v53 = (insideEdgeKey & 0x3FFFFF) - face->m_startEdgeIndex;
      pred.m_accessor = accessor;
      v54 = (edgeOutKey & 0x3FFFFF) - face->m_startEdgeIndex;
      pred.m_faceKey = faceKey;
      pred.m_up = up;
      return checkPath_HasNoClearance_const_____ptr64_(m_numEdges, v53, v54, &pred) == 0;
    }
  }
  return 1i64;
}

// File Line: 495
// RVA: 0xC15480
__int64 __fastcall hkaiNavMeshTraversalUtils::isEdgeTraversable(
        hkSimdFloat32 *diameter,
        hkaiGeneralAccessor *accessor,
        unsigned int faceKey,
        hkaiNavMesh::Face *face,
        hkVector4f *up,
        hkaiNavMesh::Edge *startEdge,
        unsigned int edgeKey,
        hkVector4f *point)
{
  __m128 m_real; // xmm0
  int v13; // r12d
  int Triangle; // eax
  int m_startEdgeIndex; // edx
  __m128 v16; // xmm6
  int v17; // r13d
  int v18; // ebx
  hkArrayBase<hkaiNavMeshTraversalUtils::Angle> *m_cur; // rax
  hkLifoAllocator *Value; // r8
  int v21; // edx
  char *v22; // rcx
  int v23; // ebx
  int v24; // eax
  int v25; // r12d
  int v26; // ebx
  BOOL v27; // edi
  __m128 v28; // xmm1
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  float v32; // xmm7_4
  float v34; // xmm0_4
  float v35; // xmm7_4
  int v36; // ebx
  hkaiNavMesh::Edge *v37; // rbx
  float v38; // xmm0_4
  char *v39; // rsi
  signed int v40; // ebx
  hkLifoAllocator *v41; // rax
  int v42; // r8d
  signed int index; // [rsp+40h] [rbp-99h]
  unsigned int v44; // [rsp+40h] [rbp-99h]
  unsigned int v45; // [rsp+40h] [rbp-99h]
  AddToArray pred; // [rsp+48h] [rbp-91h] BYREF
  int v47; // [rsp+50h] [rbp-89h]
  int v48; // [rsp+54h] [rbp-85h]
  void *p; // [rsp+58h] [rbp-81h]
  int v50; // [rsp+60h] [rbp-79h]
  unsigned int v51; // [rsp+68h] [rbp-71h]
  int m_numEdges; // [rsp+6Ch] [rbp-6Dh]
  hkSimdFloat32 threshold; // [rsp+70h] [rbp-69h] BYREF
  int x; // [rsp+80h] [rbp-59h]
  hkSimdFloat32 maxClearance; // [rsp+90h] [rbp-49h] BYREF
  hkVector4f vecOut; // [rsp+A0h] [rbp-39h] BYREF
  hkSimdFloat32 result; // [rsp+B0h] [rbp-29h] BYREF
  unsigned int startEdgea; // [rsp+148h] [rbp+6Fh]
  unsigned int startEdgeb; // [rsp+148h] [rbp+6Fh]
  unsigned int startEdgec; // [rsp+148h] [rbp+6Fh]
  unsigned int startEdged; // [rsp+148h] [rbp+6Fh]

  if ( (startEdge->m_flags.m_storage & 0x10) != 0 )
    return 1i64;
  m_real = diameter->m_real;
  m_numEdges = face->m_numEdges;
  v13 = faceKey >> 22;
  threshold.m_real = _mm_mul_ps(m_real, m_real);
  hkaiGeneralAccessor::setSection(accessor, faceKey >> 22);
  Triangle = findTriangle(accessor, face, up, point);
  m_startEdgeIndex = face->m_startEdgeIndex;
  m_real.m128_i32[0] = LODWORD(accessor->m_accessor->m_maxGlobalClearance);
  x = Triangle;
  v16 = _mm_shuffle_ps((__m128)m_real.m128_u32[0], (__m128)m_real.m128_u32[0], 0);
  v51 = edgeKey & 0x3FFFFF;
  maxClearance.m_real = v16;
  v17 = (edgeKey & 0x3FFFFF) - m_startEdgeIndex;
  index = (edgeKey & 0x3FFFFF) - 1;
  if ( index < m_startEdgeIndex )
    index = m_startEdgeIndex + face->m_numEdges - 1;
  hkaiGeneralAccessor::setSection(accessor, v13);
  vecOut.m_quad.m128_u64[0] = (unsigned __int64)hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                                                  accessor->m_accessor->m_originalEdges,
                                                  accessor->m_accessor->m_numOriginalEdges,
                                                  &accessor->m_accessor->m_instancedEdges,
                                                  &accessor->m_accessor->m_ownedEdges,
                                                  &accessor->m_accessor->m_edgeMap,
                                                  index);
  hkaiGeneralAccessor::setSection(accessor, v13);
  v44 = accessor->m_accessor->m_globalClearanceCache.m_data[startEdge->m_a].m_value << 16;
  if ( _mm_shuffle_ps((__m128)v44, (__m128)v44, 0).m128_f32[0] > v16.m128_f32[0] )
    hkaiNavMeshTraversalUtils::computeGlobalClearance(&result, accessor, faceKey, startEdge, up, &maxClearance);
  hkaiGeneralAccessor::setSection(accessor, v13);
  v45 = accessor->m_accessor->m_globalClearanceCache.m_data[*(_DWORD *)vecOut.m_quad.m128_u64[0]].m_value << 16;
  if ( _mm_shuffle_ps((__m128)v45, (__m128)v45, 0).m128_f32[0] > v16.m128_f32[0] )
    hkaiNavMeshTraversalUtils::computeGlobalClearance(
      &result,
      accessor,
      faceKey,
      (hkaiNavMesh::Edge *)vecOut.m_quad.m128_u64[0],
      up,
      &maxClearance);
  v18 = face->m_numEdges;
  m_cur = 0i64;
  v48 = 0x80000000;
  pred.m_array = 0i64;
  v47 = 0;
  v50 = v18;
  if ( v18 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkArrayBase<hkaiNavMeshTraversalUtils::Angle> *)Value->m_cur;
    v21 = (12 * v18 + 127) & 0xFFFFFF80;
    v22 = (char *)m_cur + v21;
    if ( v21 > Value->m_slabSize || v22 > Value->m_end )
      m_cur = (hkArrayBase<hkaiNavMeshTraversalUtils::Angle> *)hkLifoAllocator::allocateFromNewSlab(Value, v21);
    else
      Value->m_cur = v22;
  }
  pred.m_array = m_cur;
  p = m_cur;
  v48 = v18 | 0x80000000;
  v23 = x;
  if ( x == v17 || (checkPath_AddToArray_(face->m_numEdges, x, v17, (AddToArray)&pred), v24 = v47, v47 < 2) )
  {
    hkaiGeneralAccessor::setSection(accessor, v13);
    getFaceVertex(accessor, face, v17, (hkVector4f *)&threshold);
    getFaceVertex(accessor, face, (v17 + 1) % m_numEdges, &vecOut);
    v28 = _mm_sub_ps(threshold.m_real, vecOut.m_quad);
    v29 = _mm_mul_ps(v28, v28);
    v30 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
            _mm_shuffle_ps(v29, v29, 170));
    v31 = _mm_rsqrt_ps(v30);
    LODWORD(v32) = _mm_andnot_ps(
                     _mm_cmple_ps(v30, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v31), v31)),
                         _mm_mul_ps(*(__m128 *)_xmm, v31)),
                       v30)).m128_u32[0];
    hkaiGeneralAccessor::setSection(accessor, v13);
    startEdgea = accessor->m_accessor->m_globalClearanceCache.m_data[startEdge->m_a].m_value << 16;
    v34 = _mm_shuffle_ps((__m128)startEdgea, (__m128)startEdgea, 0).m128_f32[0];
    if ( v34 > v16.m128_f32[0] )
    {
      hkaiNavMeshTraversalUtils::computeGlobalClearance(&threshold, accessor, faceKey, startEdge, up, &maxClearance);
      startEdgeb = (__int16)(COERCE_INT(threshold.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
      LODWORD(v34) = _mm_shuffle_ps((__m128)startEdgeb, (__m128)startEdgeb, 0).m128_u32[0];
    }
    v35 = v32 + fmax(v34, 0.0);
    v36 = v51 + 1;
    if ( (int)(v51 + 1) >= face->m_startEdgeIndex + face->m_numEdges )
      v36 = face->m_startEdgeIndex;
    hkaiGeneralAccessor::setSection(accessor, edgeKey >> 22);
    v37 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            accessor->m_accessor->m_originalEdges,
            accessor->m_accessor->m_numOriginalEdges,
            &accessor->m_accessor->m_instancedEdges,
            &accessor->m_accessor->m_ownedEdges,
            &accessor->m_accessor->m_edgeMap,
            v36);
    hkaiGeneralAccessor::setSection(accessor, v13);
    startEdgec = accessor->m_accessor->m_globalClearanceCache.m_data[v37->m_a].m_value << 16;
    v38 = _mm_shuffle_ps((__m128)startEdgec, (__m128)startEdgec, 0).m128_f32[0];
    if ( v38 > v16.m128_f32[0] )
    {
      hkaiNavMeshTraversalUtils::computeGlobalClearance(&threshold, accessor, faceKey, v37, up, &maxClearance);
      startEdged = (__int16)(COERCE_INT(threshold.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
      LODWORD(v38) = _mm_shuffle_ps((__m128)startEdged, (__m128)startEdged, 0).m128_u32[0];
    }
    v27 = (float)(fmax(v38, 0.0) + v35) >= diameter->m_real.m128_f32[0];
    goto LABEL_33;
  }
  if ( v23 >= v17 )
    v25 = v47 - 1;
  else
    v25 = 0;
  v26 = 0;
  while ( v26 == v25 )
  {
LABEL_23:
    if ( ++v26 >= v24 )
    {
      v27 = 1;
      goto LABEL_34;
    }
  }
  maxClearance.m_real = (__m128)xmmword_141A712A0;
  if ( !hkaiNavMeshTraversalUtils::isVertexClearanceForEdgeLessThan(
          accessor,
          faceKey,
          face,
          (hkaiNavMeshTraversalUtils::Angle *)pred.m_array + v26,
          up,
          &maxClearance,
          &threshold) )
  {
    v24 = v47;
    goto LABEL_23;
  }
  v27 = 0;
LABEL_33:
  v24 = v47;
LABEL_34:
  v39 = (char *)p;
  if ( p == pred.m_array )
    v24 = 0;
  v47 = v24;
  v40 = (12 * v50 + 127) & 0xFFFFFF80;
  v41 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v42 = (v40 + 15) & 0xFFFFFFF0;
  if ( v40 > v41->m_slabSize || &v39[v42] != v41->m_cur || v41->m_firstNonLifoEnd == v39 )
    hkLifoAllocator::slowBlockFree(v41, v39, v42);
  else
    v41->m_cur = v39;
  v47 = 0;
  if ( v48 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      pred.m_array,
      12 * (v48 & 0x3FFFFFFF));
  return v27;
}

// File Line: 595
// RVA: 0xC15A50
hkSimdFloat32 *__fastcall hkaiNavMeshTraversalUtils::computeGlobalClearance(
        hkSimdFloat32 *result,
        hkaiGeneralAccessor *accessor,
        unsigned int startFaceKey,
        hkaiNavMesh::Edge *startEdge)
{
  hkSimdFloat32 *v7; // r14
  __m128 m_real; // xmm0
  __m128 v9; // xmm9
  hkaiNavMeshInstance *m_accessor; // rcx
  __int64 m_a; // rax
  int m_numOriginalVertices; // edx
  __m128 *p_m_quad; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm10
  __m128 v16; // xmm1
  __m128 v17; // xmm11
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  void *v20; // rdx
  hkLifoAllocator *v21; // rax
  char *v22; // rcx
  char *v23; // rdx
  int v24; // eax
  _DWORD *v25; // r15
  bool v26; // zf
  int v27; // esi
  unsigned int v28; // ebx
  hkaiNavMesh::Face *FaceFromPacked; // rax
  hkaiNavMesh::Face *v30; // r14
  int m_startEdgeIndex; // edi
  hkaiNavMeshInstance *v32; // rbx
  hkaiNavMesh::Edge *v33; // rax
  int v34; // edx
  __int64 v35; // r9
  hkaiNavMesh::Edge *v36; // r8
  hkVector4f *v37; // rcx
  __m128 m_quad; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __int64 m_b; // rcx
  __m128 v42; // xmm5
  __m128 v43; // xmm6
  __m128 v44; // xmm4
  __m128 *v45; // rax
  __m128 v46; // xmm8
  __m128 v47; // xmm2
  __m128 v48; // xmm8
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm6
  __m128 v52; // xmm7
  __m128 v53; // xmm8
  __m128 v54; // xmm5
  __m128 v55; // xmm1
  __m128 v56; // xmm3
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __m128 v59; // xmm4
  __m128 v60; // xmm1
  __m128 v61; // xmm7
  __m128 v62; // xmm7
  __m128 v63; // xmm1
  __m128 v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  char m_storage; // al
  unsigned int m_oppositeFace; // ecx
  unsigned int v70; // eax
  unsigned int v71; // ebx
  __int64 v72; // rax
  int v73; // ecx
  int m_startUserEdgeIndex; // edx
  __m128 v75; // xmm3
  int v76; // eax
  char *v77; // rdi
  signed int v78; // ebx
  hkLifoAllocator *v79; // rax
  int v80; // r8d
  int v81; // eax
  char *v82; // rdi
  signed int v83; // ebx
  hkLifoAllocator *v84; // rax
  int v85; // r8d
  int index[2]; // [rsp+28h] [rbp-79h] BYREF
  unsigned __int64 array; // [rsp+30h] [rbp-71h] BYREF
  void *p; // [rsp+38h] [rbp-69h]
  void *v90; // [rsp+40h] [rbp-61h]
  int v91; // [rsp+48h] [rbp-59h]
  __m128 *v92; // [rsp+F8h] [rbp+57h]
  __m128 *retaddr; // [rsp+118h] [rbp+77h]
  int m_currentSection; // [rsp+120h] [rbp+7Fh]

  v7 = result;
  m_real = result->m_real;
  *result = (hkSimdFloat32)result->m_real;
  if ( startEdge->m_oppositeEdge == -1 || (startEdge->m_flags.m_storage & 0x20) != 0 )
  {
    *result = (hkSimdFloat32)g_vectorfConstants[0];
    goto $outputClearance;
  }
  v9 = _mm_mul_ps(m_real, m_real);
  hkaiGeneralAccessor::setSection(accessor, startFaceKey >> 22);
  m_accessor = accessor->m_accessor;
  m_currentSection = accessor->m_currentSection;
  m_a = startEdge->m_a;
  m_numOriginalVertices = accessor->m_accessor->m_numOriginalVertices;
  if ( (int)m_a >= m_numOriginalVertices )
    p_m_quad = &m_accessor->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
  else
    p_m_quad = &m_accessor->m_originalVertices[m_a].m_quad;
  v14 = *p_m_quad;
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(v14, v14, 85),
                m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
          m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
  array = 0i64;
  p = (void *)0x8000000000000000i64;
  v91 = 64;
  v16 = _mm_mul_ps(v15, *retaddr);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v20 = m_cur + 256;
  if ( Value->m_slabSize < 256 || v20 > Value->m_end )
    HIDWORD(m_cur) = (unsigned __int64)hkLifoAllocator::allocateFromNewSlab(Value, 256) >> 32;
  else
    Value->m_cur = v20;
  HIDWORD(v90) = HIDWORD(m_cur);
  HIDWORD(p) = -2147483584;
  *(_QWORD *)index = 0i64;
  array = 0x8000000000000000ui64;
  LODWORD(v90) = 64;
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (char *)v21->m_cur;
  v23 = v22 + 256;
  if ( v21->m_slabSize < 256 || v23 > v21->m_end )
    v22 = (char *)hkLifoAllocator::allocateFromNewSlab(v21, 256);
  else
    v21->m_cur = v23;
  v24 = HIDWORD(p);
  *(_QWORD *)index = v22;
  p = v22;
  HIDWORD(array) = -2147483584;
  if ( (_DWORD)v22 == (v24 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
    LODWORD(v22) = (_DWORD)p;
  }
  *(_DWORD *)(array + 4i64 * (int)v22) = startFaceKey;
  v25 = *(_DWORD **)index;
  v26 = (_DWORD)p == -1;
  v27 = (_DWORD)p + 1;
  LODWORD(p) = (_DWORD)p + 1;
  if ( v26 )
  {
LABEL_59:
    v75 = _mm_rsqrt_ps(v9);
    v7->m_real = _mm_andnot_ps(
                   _mm_cmple_ps(v9, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v75, v9), v75)),
                       _mm_mul_ps(*(__m128 *)_xmm, v75)),
                     v9));
    goto LABEL_61;
  }
  while ( 1 )
  {
    v28 = *(_DWORD *)(array + 4i64 * v27 - 4);
    LODWORD(p) = v27 - 1;
    if ( (_DWORD)array == (HIDWORD(array) & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, index, 4);
      v25 = *(_DWORD **)index;
    }
    v25[(int)array] = v28;
    LODWORD(array) = array + 1;
    FaceFromPacked = hkaiGeneralAccessor::getFaceFromPacked(accessor, v28);
    v30 = FaceFromPacked;
    m_startEdgeIndex = FaceFromPacked->m_numUserEdges <= 0
                     ? FaceFromPacked->m_startEdgeIndex
                     : FaceFromPacked->m_startUserEdgeIndex;
    v27 = (int)p;
    v25 = *(_DWORD **)index;
    if ( m_startEdgeIndex != -1 )
      break;
LABEL_57:
    if ( !v27 )
    {
      v7 = (hkSimdFloat32 *)v92;
      goto LABEL_59;
    }
  }
  while ( 1 )
  {
    v32 = accessor->m_accessor;
    v33 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            v32->m_originalEdges,
            v32->m_numOriginalEdges,
            &v32->m_instancedEdges,
            &v32->m_ownedEdges,
            &v32->m_edgeMap,
            m_startEdgeIndex);
    v34 = v32->m_numOriginalVertices;
    v35 = v33->m_a;
    v36 = v33;
    v37 = (int)v35 >= v34 ? &v32->m_ownedVertices.m_data[(int)v35 - v34] : &v32->m_originalVertices[v35];
    m_quad = v37->m_quad;
    v39 = v32->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
    v40 = v32->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
    m_b = v33->m_b;
    v42 = v32->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
    v43 = v32->m_referenceFrame.m_transform.m_translation.m_quad;
    v44 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v40),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v39)),
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v42)),
            v43);
    v45 = (__m128 *)((int)m_b >= v34 ? &v32->m_ownedVertices.m_data[(int)m_b - v34] : &v32->m_originalVertices[m_b]);
    v46 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v45, *v45, 0), v40), _mm_mul_ps(_mm_shuffle_ps(*v45, *v45, 85), v39)),
            _mm_mul_ps(_mm_shuffle_ps(*v45, *v45, 170), v42));
    v47 = _mm_mul_ps(v44, *retaddr);
    v48 = _mm_add_ps(v46, v43);
    v49 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)),
            _mm_shuffle_ps(v47, v47, 170));
    v50 = _mm_mul_ps(v48, *retaddr);
    v51 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17, v49), *retaddr), v44);
    v52 = _mm_sub_ps(v51, v15);
    v53 = _mm_add_ps(
            v48,
            _mm_mul_ps(
              _mm_sub_ps(
                v17,
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                  _mm_shuffle_ps(v50, v50, 170))),
              *retaddr));
    v54 = _mm_sub_ps(v51, v53);
    v55 = _mm_mul_ps(v54, v54);
    v56 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
            _mm_shuffle_ps(v55, v55, 170));
    v57 = _mm_mul_ps(v52, v54);
    v58 = _mm_rcp_ps(v56);
    v59 = _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
              _mm_shuffle_ps(v57, v57, 170)),
            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v58, v56)), v58));
    v60 = _mm_cmplt_ps(v59, query.m_quad);
    v61 = _mm_sub_ps(
            v52,
            _mm_mul_ps(_mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v60, query.m_quad), _mm_and_ps(v59, v60))), v54));
    v62 = _mm_mul_ps(v61, v61);
    v63 = _mm_sub_ps(v15, v51);
    v64 = _mm_sub_ps(v15, v53);
    v65 = _mm_mul_ps(v63, v63);
    v66 = _mm_mul_ps(v64, v64);
    v67 = _mm_min_ps(
            _mm_min_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                _mm_shuffle_ps(v65, v65, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v66, v66, 85), _mm_shuffle_ps(v66, v66, 0)),
                _mm_shuffle_ps(v66, v66, 170))),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
              _mm_shuffle_ps(v62, v62, 170)));
    if ( v36->m_oppositeEdge == -1 )
      break;
    m_storage = v36->m_flags.m_storage;
    if ( (m_storage & 0x20) != 0 )
      break;
    if ( v67.m128_f32[0] <= v9.m128_f32[0] )
    {
      m_oppositeFace = v36->m_oppositeFace;
      if ( (m_storage & 0x40) != 0 )
        v70 = m_oppositeFace & 0xFFC00000;
      else
        v70 = v32->m_runtimeId << 22;
      v71 = v70 | m_oppositeFace & 0x3FFFFF;
      if ( m_oppositeFace == -1 )
        v71 = -1;
      v72 = 0i64;
      v73 = 0;
      if ( (int)array <= 0i64 )
        goto LABEL_42;
      while ( v25[v72] != v71 )
      {
        ++v72;
        ++v73;
        if ( v72 >= (int)array )
          goto LABEL_42;
      }
      if ( v73 == -1 )
      {
LABEL_42:
        if ( v71 >> 22 == m_currentSection )
        {
          if ( v27 == (HIDWORD(p) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
            v27 = (int)p;
          }
          *(_DWORD *)(array + 4i64 * v27) = v71;
          v25 = *(_DWORD **)index;
          v27 = (_DWORD)p + 1;
          LODWORD(p) = (_DWORD)p + 1;
        }
      }
    }
LABEL_49:
    m_startUserEdgeIndex = v30->m_startUserEdgeIndex;
    if ( m_startEdgeIndex >= m_startUserEdgeIndex && m_startEdgeIndex < v30->m_numUserEdges + m_startUserEdgeIndex - 1 )
      goto LABEL_55;
    if ( m_startEdgeIndex != v30->m_numUserEdges + m_startUserEdgeIndex - 1 )
    {
      if ( m_startEdgeIndex < v30->m_startEdgeIndex || m_startEdgeIndex >= v30->m_numEdges + v30->m_startEdgeIndex - 1 )
        goto LABEL_57;
LABEL_55:
      ++m_startEdgeIndex;
      goto LABEL_56;
    }
    m_startEdgeIndex = v30->m_startEdgeIndex;
LABEL_56:
    if ( m_startEdgeIndex == -1 )
      goto LABEL_57;
  }
  if ( (_DWORD)v35 != startEdge->m_a && (_DWORD)m_b != startEdge->m_a )
  {
    v9 = _mm_min_ps(v67, v9);
    goto LABEL_49;
  }
  v7 = (hkSimdFloat32 *)v92;
  *v92 = g_vectorfConstants[0];
LABEL_61:
  v76 = array;
  v77 = (char *)p;
  if ( p == v25 )
    v76 = 0;
  LODWORD(array) = v76;
  v78 = (4 * (_DWORD)v90 + 127) & 0xFFFFFF80;
  v79 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v80 = (v78 + 15) & 0xFFFFFFF0;
  if ( v78 > v79->m_slabSize || &v77[v80] != v79->m_cur || v79->m_firstNonLifoEnd == v77 )
    hkLifoAllocator::slowBlockFree(v79, v77, v80);
  else
    v79->m_cur = v77;
  LODWORD(array) = 0;
  if ( (array & 0x8000000000000000ui64) == 0i64 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      *(void **)index,
      4 * HIDWORD(array));
  v81 = (int)p;
  v82 = (char *)v90;
  v26 = v90 == (void *)array;
  *(_QWORD *)index = 0i64;
  HIDWORD(array) = 0x80000000;
  if ( v26 )
    v81 = 0;
  LODWORD(p) = v81;
  v83 = (4 * v91 + 127) & 0xFFFFFF80;
  v84 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v85 = (v83 + 15) & 0xFFFFFFF0;
  if ( v83 > v84->m_slabSize || &v82[v85] != v84->m_cur || v84->m_firstNonLifoEnd == v82 )
    hkLifoAllocator::slowBlockFree(v84, v82, v85);
  else
    v84->m_cur = v82;
  LODWORD(p) = 0;
  if ( SHIDWORD(p) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, (void *)array, 4 * HIDWORD(p));
$outputClearance:
  hkaiNavMeshTraversalUtils::updateGlobalClearance(accessor, startEdge->m_a, v7);
  return v7;
}

// File Line: 686
// RVA: 0xC163F0
hkSimdFloat32 *__fastcall hkaiNavMeshTraversalUtils::computeVertexClearance(
        hkSimdFloat32 *result,
        hkaiGeneralAccessor *accessor,
        unsigned int faceKey,
        hkaiNavMesh::Face *currentFace)
{
  hkaiNavMesh::Face *FaceFromPacked; // rax
  hkaiNavMeshInstance *m_accessor; // rdi
  int m_startEdgeIndex; // r13d
  hkaiNavMeshTraversalUtils::Angle *v9; // r15
  int v10; // eax
  int *m_data; // rcx
  int m_numOriginalVertices; // r12d
  int v13; // eax
  __int64 v14; // rsi
  __m128 *v15; // r14
  unsigned int *p_m_oppositeEdge; // rbx
  hkaiNavMesh::Edge *v17; // rax
  char m_paddingByte; // cl
  __int64 v19; // rax
  __m128 *p_m_quad; // rax
  __m128 v21; // xmm15
  hkVector4f *v22; // rdi
  __m128 m_quad; // xmm1
  __m128 v24; // xmm13
  __m128 v25; // xmm8
  __m128 v26; // xmm6
  __m128 v27; // xmm11
  __m128 v28; // xmm5
  __m128 v29; // xmm5
  __m128 v30; // xmm6
  __m128 v31; // xmm1
  __m128 v32; // xmm6
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  __m128 v35; // xmm5
  __m128 v36; // xmm1
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm6
  __m128 v42; // xmm0
  __m128 v43; // xmm2
  hkLifoAllocator *v44; // rax
  hkaiGeneralAccessor *v45; // r15
  char *m_cur; // rcx
  char *v47; // rdx
  hkLifoAllocator *v48; // rax
  char *v49; // rcx
  char *v50; // rdx
  hkaiNavMeshInstance *v51; // rax
  unsigned int v52; // esi
  __m128 v53; // xmm1
  int v54; // ebx
  __m128 v55; // xmm3
  __m128 v56; // xmm2
  __m128 v57; // xmm7
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm1
  __m128 v61; // xmm14
  __m128 v62; // xmm6
  __m128 v63; // xmm10
  __m128 v64; // xmm3
  int v65; // edx
  __m128 v66; // xmm7
  __int64 v67; // rcx
  char *v68; // rax
  int v69; // edx
  unsigned int v70; // xmm0_4
  int v71; // xmm1_4
  float v72; // xmm6_4
  unsigned int v73; // ebx
  hkaiNavMesh::Face *v74; // rax
  int index; // r13d
  int v76; // ecx
  BOOL v77; // eax
  unsigned int v78; // r14d
  hkaiNavMeshInstance *v79; // rbx
  hkaiNavMesh::Edge *v80; // rdi
  unsigned int m_oppositeFace; // ecx
  char v82; // dl
  unsigned int v83; // eax
  __m128 v84; // xmm2
  __m128 v85; // xmm8
  int v86; // esi
  unsigned int m_oppositeEdge; // ecx
  unsigned int v88; // eax
  int v89; // edx
  __int64 m_b; // r8
  unsigned int v91; // r12d
  __int64 m_a; // rcx
  __m128 *v93; // rax
  __m128 v94; // xmm2
  __m128 v95; // xmm3
  __m128 v96; // xmm4
  __m128 v97; // xmm5
  __m128 v98; // xmm8
  __m128 *v99; // rax
  __m128 v100; // xmm6
  unsigned int v101; // ebx
  __m128 v102; // xmm1
  int v103; // ecx
  int v104; // eax
  int v105; // ebx
  hkaiNavMesh::Edge *v106; // rbx
  __m128 v107; // xmm1
  hkaiNavMesh::Edge *v108; // r9
  __m128 v109; // xmm4
  __m128 v110; // xmm3
  __m128 v111; // xmm2
  __m128 v112; // xmm1
  __m128 v113; // xmm5
  __m128 v114; // xmm6
  __m128 v115; // xmm4
  bool v116; // zf
  __m128 v117; // xmm6
  unsigned int v118; // r8d
  hkSimdFloat32 *v119; // rsi
  int v120; // eax
  char *v121; // rdi
  signed int v122; // ebx
  hkLifoAllocator *v123; // rax
  int v124; // r8d
  __m128 v125; // xmm2
  __m128 v126; // xmm1
  __m128 v127; // xmm2
  __m128 v128; // xmm1
  __m128 v129; // xmm3
  __m128 v130; // xmm3
  int v131; // edx
  __int64 v132; // rcx
  int v133; // edx
  __int64 v134; // rcx
  char *v135; // rax
  int v136; // eax
  char *v137; // rdi
  signed int v138; // ebx
  hkLifoAllocator *v139; // rax
  int v140; // r8d
  char *array; // [rsp+40h] [rbp-88h] BYREF
  int v143; // [rsp+48h] [rbp-80h]
  int v144; // [rsp+4Ch] [rbp-7Ch]
  unsigned int faceKeya[2]; // [rsp+50h] [rbp-78h]
  int v146; // [rsp+58h] [rbp-70h]
  _DWORD *v147; // [rsp+60h] [rbp-68h] BYREF
  hkSimdFloat32 value; // [rsp+68h] [rbp-60h] BYREF
  hkSimdFloat32 resulta; // [rsp+78h] [rbp-50h] BYREF
  float v150; // [rsp+88h] [rbp-40h]
  int section; // [rsp+8Ch] [rbp-3Ch]
  unsigned int v152; // [rsp+90h] [rbp-38h]
  unsigned int v153; // [rsp+94h] [rbp-34h]
  unsigned int v154; // [rsp+98h] [rbp-30h]
  unsigned int v155; // [rsp+9Ch] [rbp-2Ch]
  float v156; // [rsp+A0h] [rbp-28h]
  hkaiNavMesh::Edge v157; // [rsp+A8h] [rbp-20h] BYREF
  hkaiNavMesh::Edge edge; // [rsp+BCh] [rbp-Ch] BYREF
  hkaiNavMesh::Edge startEdge; // [rsp+D0h] [rbp+8h] BYREF
  hkaiNavMesh::Face *v160; // [rsp+E8h] [rbp+20h]
  hkSimdFloat32 maxClearance; // [rsp+F8h] [rbp+30h]
  hkVector4f A; // [rsp+108h] [rbp+40h] BYREF
  hkVector4f edgePlane2; // [rsp+118h] [rbp+50h] BYREF
  hkVector4f edgePlane1; // [rsp+128h] [rbp+60h] BYREF
  hkSimdFloat32 v165; // [rsp+138h] [rbp+70h] BYREF
  hkSimdFloat32 v166; // [rsp+148h] [rbp+80h] BYREF
  hkVector4f vertex; // [rsp+158h] [rbp+90h] BYREF
  __m128 v168; // [rsp+168h] [rbp+A0h] BYREF
  __m128 v169; // [rsp+178h] [rbp+B0h]
  __m128 v170; // [rsp+188h] [rbp+C0h]
  hkSimdFloat32 *v171; // [rsp+278h] [rbp+1B0h]
  hkaiGeneralAccessor *accessora; // [rsp+280h] [rbp+1B8h]
  unsigned int startFaceKey; // [rsp+288h] [rbp+1C0h]
  hkaiNavMeshTraversalUtils::Angle *v174; // [rsp+298h] [rbp+1D0h]
  hkVector4f *vars0; // [rsp+2A0h] [rbp+1D8h]
  __m128 *retaddr; // [rsp+2A8h] [rbp+1E0h]

  FaceFromPacked = hkaiGeneralAccessor::getFaceFromPacked(accessor, faceKey);
  m_accessor = accessor->m_accessor;
  m_startEdgeIndex = FaceFromPacked->m_startEdgeIndex;
  LODWORD(FaceFromPacked) = accessor->m_currentSection;
  v9 = v174;
  LODWORD(v147) = (_DWORD)FaceFromPacked;
  v10 = hkaiNavMeshTraversalUtils::Angle::index(v174);
  m_data = m_accessor->m_faceClearanceIndices.m_data;
  m_numOriginalVertices = m_accessor->m_numOriginalVertices;
  *(_QWORD *)&v157.m_oppositeEdge = -1i64;
  *(_DWORD *)&v157.m_flags.m_storage = 4;
  *(_QWORD *)&edge.m_oppositeEdge = -1i64;
  *(_DWORD *)&edge.m_flags.m_storage = 4;
  v13 = m_data[faceKey & 0x3FFFFF] + v10;
  *(_QWORD *)&startEdge.m_oppositeEdge = -1i64;
  *(_DWORD *)&startEdge.m_flags.m_storage = 4;
  v14 = 0i64;
  v15 = &v168;
  p_m_oppositeEdge = &v157.m_oppositeEdge;
  v143 = v13;
  do
  {
    v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            m_accessor->m_originalEdges,
            m_accessor->m_numOriginalEdges,
            &m_accessor->m_instancedEdges,
            &m_accessor->m_ownedEdges,
            &m_accessor->m_edgeMap,
            m_startEdgeIndex + *(&v9->a + v14));
    *(p_m_oppositeEdge - 2) = v17->m_a;
    *(p_m_oppositeEdge - 1) = v17->m_b;
    *p_m_oppositeEdge = v17->m_oppositeEdge;
    p_m_oppositeEdge[1] = v17->m_oppositeFace;
    *((_BYTE *)p_m_oppositeEdge + 8) = v17->m_flags.m_storage;
    m_paddingByte = v17->m_paddingByte;
    LOWORD(v17) = v17->m_userEdgeCost.m_value;
    *((_BYTE *)p_m_oppositeEdge + 9) = m_paddingByte;
    *((_WORD *)p_m_oppositeEdge + 5) = (_WORD)v17;
    v19 = (int)*(p_m_oppositeEdge - 2);
    if ( (int)v19 >= m_numOriginalVertices )
      p_m_quad = &m_accessor->m_ownedVertices.m_data[(int)v19 - m_numOriginalVertices].m_quad;
    else
      p_m_quad = &m_accessor->m_originalVertices[v19].m_quad;
    ++v14;
    ++v15;
    p_m_oppositeEdge += 5;
    v15[-1] = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(*p_m_quad, *p_m_quad, 85),
                      m_accessor->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(
                      _mm_shuffle_ps(*p_m_quad, *p_m_quad, 0),
                      m_accessor->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(*p_m_quad, *p_m_quad, 170),
                    m_accessor->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                m_accessor->m_referenceFrame.m_transform.m_translation.m_quad);
  }
  while ( v14 < 3 );
  v21 = v169;
  v22 = vars0;
  m_quad = vars0->m_quad;
  v24 = _mm_sub_ps(v168, v169);
  v25 = _mm_sub_ps(v170, v168);
  v26 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v27 = _mm_sub_ps(v170, v169);
  vertex.m_quad = v169;
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), m_quad), _mm_mul_ps(v26, v24));
  v29 = _mm_shuffle_ps(v28, v28, 201);
  v30 = _mm_sub_ps(_mm_mul_ps(v26, v27), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), m_quad));
  v31 = _mm_mul_ps(v29, v29);
  v32 = _mm_shuffle_ps(v30, v30, 201);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_mul_ps(
          v29,
          _mm_andnot_ps(
            _mm_cmple_ps(v33, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(*(__m128 *)_xmm, v34))));
  v36 = _mm_mul_ps(v32, v32);
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  v38 = _mm_rsqrt_ps(v37);
  v39 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)), _mm_mul_ps(*(__m128 *)_xmm, v38));
  v40 = _mm_mul_ps(v35, v169);
  v41 = _mm_mul_ps(v32, _mm_andnot_ps(_mm_cmple_ps(v37, (__m128)0i64), v39));
  v144 = 0x80000000;
  v146 = 64;
  v42 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170)));
  v43 = _mm_mul_ps(v41, v169);
  array = 0i64;
  v143 = 0;
  edgePlane1.m_quad = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, v42), 196);
  edgePlane2.m_quad = _mm_shuffle_ps(
                        v41,
                        _mm_unpackhi_ps(
                          v41,
                          _mm_sub_ps(
                            (__m128)0i64,
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                              _mm_shuffle_ps(v43, v43, 170)))),
                        196);
  v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v45 = accessora;
  m_cur = (char *)v44->m_cur;
  v47 = m_cur + 768;
  if ( v44->m_slabSize < 768 || v47 > v44->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v44, 768);
  else
    v44->m_cur = v47;
  array = m_cur;
  *(_QWORD *)faceKeya = m_cur;
  v144 = -2147483584;
  v147 = 0i64;
  value.m_real.m128_u64[0] = 0x8000000000000000ui64;
  resulta.m_real.m128_i32[0] = 64;
  v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v49 = (char *)v48->m_cur;
  v50 = v49 + 256;
  if ( v48->m_slabSize < 256 || v50 > v48->m_end )
    v49 = (char *)hkLifoAllocator::allocateFromNewSlab(v48, 256);
  else
    v48->m_cur = v50;
  v51 = v45->m_accessor;
  v52 = startFaceKey;
  v147 = v49;
  value.m_real.m128_u64[1] = (unsigned __int64)v49;
  value.m_real.m128_i32[1] = -2147483584;
  v53 = _mm_mul_ps(v27, v27);
  v54 = startFaceKey >> 22;
  v55 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)), _mm_shuffle_ps(v53, v53, 170));
  v56 = _mm_rsqrt_ps(v55);
  v57 = _mm_andnot_ps(
          _mm_cmple_ps(v55, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v55), v56)),
              _mm_mul_ps(*(__m128 *)_xmm, v56)),
            v55));
  v58 = _mm_mul_ps(v24, v24);
  v59 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)), _mm_shuffle_ps(v58, v58, 170));
  v60 = _mm_rsqrt_ps(v59);
  *(float *)&accessora = v51->m_maxGlobalClearance;
  v61 = _mm_shuffle_ps((__m128)(unsigned int)accessora, (__m128)(unsigned int)accessora, 0);
  v62 = _mm_andnot_ps(
          _mm_cmple_ps(v59, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v60, v59), v60)),
              _mm_mul_ps(*(__m128 *)_xmm, v60)),
            v59));
  maxClearance.m_real = v61;
  hkaiGeneralAccessor::setSection(v45, startFaceKey >> 22);
  LODWORD(accessora) = v45->m_accessor->m_globalClearanceCache.m_data[startEdge.m_a].m_value << 16;
  v63 = _mm_shuffle_ps((__m128)(unsigned int)accessora, (__m128)(unsigned int)accessora, 0);
  if ( v63.m128_f32[0] > v61.m128_f32[0] )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(&resulta, v45, v52, &startEdge);
    LODWORD(accessora) = (__int16)(COERCE_INT(resulta.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
    v63 = _mm_shuffle_ps((__m128)(unsigned int)accessora, (__m128)(unsigned int)accessora, 0);
  }
  hkaiGeneralAccessor::setSection(v45, v54);
  LODWORD(accessora) = v45->m_accessor->m_globalClearanceCache.m_data[v157.m_a].m_value << 16;
  v64 = _mm_shuffle_ps((__m128)(unsigned int)accessora, (__m128)(unsigned int)accessora, 0);
  if ( v64.m128_f32[0] > v61.m128_f32[0] )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(&resulta, v45, v52, &v157);
    LODWORD(accessora) = (__int16)(COERCE_INT(resulta.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
    v64 = _mm_shuffle_ps((__m128)(unsigned int)accessora, (__m128)(unsigned int)accessora, 0);
  }
  if ( v63.m128_f32[0] < 0.0 )
  {
    v84 = _mm_mul_ps(v25, v27);
    if ( (float)((float)(_mm_shuffle_ps(v84, v84, 85).m128_f32[0] + _mm_shuffle_ps(v84, v84, 0).m128_f32[0])
               + _mm_shuffle_ps(v84, v84, 170).m128_f32[0]) <= 0.0 )
    {
      value.m_real = _mm_mul_ps(v57, v57);
      goto LABEL_71;
    }
  }
  else
  {
    v57 = _mm_add_ps(v57, v63);
  }
  if ( v64.m128_f32[0] < 0.0 )
  {
    v85 = _mm_mul_ps(v25, v24);
    if ( (float)((float)(_mm_shuffle_ps(v85, v85, 85).m128_f32[0] + _mm_shuffle_ps(v85, v85, 0).m128_f32[0])
               + _mm_shuffle_ps(v85, v85, 170).m128_f32[0]) >= 0.0 )
    {
      value.m_real = _mm_mul_ps(v62, v62);
      goto LABEL_71;
    }
  }
  else
  {
    v62 = _mm_add_ps(v62, v64);
  }
  v65 = v143;
  v66 = _mm_min_ps(_mm_min_ps(_mm_mul_ps(v57, v57), _mm_mul_ps(v62, v62)), *retaddr);
  value.m_real = v66;
  if ( v143 == (v144 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 12);
    v65 = v143;
  }
  v67 = 3i64 * v65;
  v68 = array;
  v143 = v65 + 1;
  *(_DWORD *)&array[4 * v67] = 0;
  *(_DWORD *)&v68[4 * v67 + 4] = v52;
  *(_DWORD *)&v68[4 * v67 + 8] = -1;
  v69 = v143;
  if ( v143 )
  {
    do
    {
      v70 = *(_DWORD *)&array[12 * v69 - 8];
      v71 = *(_DWORD *)&array[12 * v69 - 4];
      v72 = *(float *)&array[12 * v69 - 12];
      v143 = v69 - 1;
      faceKeya[1] = v70;
      v146 = v71;
      if ( value.m_real.m128_i32[0] == (value.m_real.m128_i32[1] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &v147, 4);
      v73 = faceKeya[1];
      v147[value.m_real.m128_i32[0]++] = faceKeya[1];
      if ( v72 <= v66.m128_f32[0] )
      {
        v74 = hkaiGeneralAccessor::getFaceFromPacked(v45, v73);
        v160 = v74;
        index = v74->m_startEdgeIndex;
        v76 = v74->m_startEdgeIndex + v74->m_numEdges;
        LODWORD(accessora) = v76;
        while ( index < v76 )
        {
          if ( v73 != v52
            || (v77 = hkaiNavMeshTraversalUtils::Angle::sectorContainsEdge(
                        v174,
                        index - v74->m_startEdgeIndex,
                        v74->m_numEdges),
                v76 = (int)accessora,
                v77) )
          {
            v78 = index | (v45->m_currentSection << 22);
            if ( v78 != v146 )
            {
              v79 = v45->m_accessor;
              v80 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                      v45->m_accessor->m_originalEdges,
                      v45->m_accessor->m_numOriginalEdges,
                      &v45->m_accessor->m_instancedEdges,
                      &v45->m_accessor->m_ownedEdges,
                      &v45->m_accessor->m_edgeMap,
                      index);
              m_oppositeFace = v80->m_oppositeFace;
              v82 = v80->m_flags.m_storage & 0x40;
              if ( v82 )
                v83 = m_oppositeFace & 0xFFC00000;
              else
                v83 = v79->m_runtimeId << 22;
              v86 = v83 | m_oppositeFace & 0x3FFFFF;
              v116 = m_oppositeFace == -1;
              m_oppositeEdge = v80->m_oppositeEdge;
              if ( v116 )
                v86 = -1;
              if ( v82 )
                v88 = m_oppositeEdge & 0xFFC00000;
              else
                v88 = v79->m_runtimeId << 22;
              v89 = v79->m_numOriginalVertices;
              m_b = v80->m_b;
              v91 = v88 | m_oppositeEdge & 0x3FFFFF;
              v116 = m_oppositeEdge == -1;
              m_a = v80->m_a;
              if ( v116 )
                v91 = -1;
              if ( (int)m_a >= v89 )
                v93 = &v79->m_ownedVertices.m_data[(int)m_a - v89].m_quad;
              else
                v93 = &v79->m_originalVertices[m_a].m_quad;
              v94 = v79->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
              v95 = v79->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
              v96 = v79->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
              v97 = v79->m_referenceFrame.m_transform.m_translation.m_quad;
              v98 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(*v93, *v93, 0), v95),
                          _mm_mul_ps(_mm_shuffle_ps(*v93, *v93, 85), v94)),
                        _mm_mul_ps(_mm_shuffle_ps(*v93, *v93, 170), v96)),
                      v97);
              if ( (int)m_b >= v89 )
                v99 = &v79->m_ownedVertices.m_data[(int)m_b - v89].m_quad;
              else
                v99 = &v79->m_originalVertices[m_b].m_quad;
              v100 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(*v99, *v99, 0), v95),
                           _mm_mul_ps(_mm_shuffle_ps(*v99, *v99, 85), v94)),
                         _mm_mul_ps(_mm_shuffle_ps(*v99, *v99, 170), v96)),
                       v97);
              if ( v45->m_currentSection == (_DWORD)v147 && ((_DWORD)m_a == edge.m_a || (_DWORD)m_b == edge.m_a) )
              {
                v73 = faceKeya[1];
              }
              else
              {
                v101 = faceKeya[1];
                section = faceKeya[1] >> 22;
                hkaiGeneralAccessor::setSection(v45, faceKeya[1] >> 22);
                v155 = v45->m_accessor->m_globalClearanceCache.m_data[v80->m_a].m_value << 16;
                v102 = _mm_shuffle_ps((__m128)v155, (__m128)v155, 0);
                if ( v102.m128_f32[0] > v61.m128_f32[0] )
                {
                  hkaiNavMeshTraversalUtils::computeGlobalClearance(&v165, v45, v101, v80);
                  v150 = v165.m_real.m128_f32[0] * 1.0039062;
                  v153 = (__int16)(COERCE_INT(v165.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
                  v102 = _mm_shuffle_ps((__m128)v153, (__m128)v153, 0);
                }
                v103 = v160->m_startEdgeIndex;
                v104 = v160->m_startEdgeIndex + v160->m_numEdges;
                v105 = (v78 & 0x3FFFFF) + 1;
                A.m_quad = _mm_shuffle_ps(v98, _mm_unpackhi_ps(v98, v102), 196);
                if ( v105 >= v104 )
                  v105 = v103;
                hkaiGeneralAccessor::setSection(v45, v78 >> 22);
                v106 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                         v45->m_accessor->m_originalEdges,
                         v45->m_accessor->m_numOriginalEdges,
                         &v45->m_accessor->m_instancedEdges,
                         &v45->m_accessor->m_ownedEdges,
                         &v45->m_accessor->m_edgeMap,
                         v105);
                hkaiGeneralAccessor::setSection(v45, section);
                v154 = v45->m_accessor->m_globalClearanceCache.m_data[v106->m_a].m_value << 16;
                v107 = _mm_shuffle_ps((__m128)v154, (__m128)v154, 0);
                if ( v107.m128_f32[0] <= v61.m128_f32[0] )
                {
                  v73 = faceKeya[1];
                }
                else
                {
                  v108 = v106;
                  v73 = faceKeya[1];
                  hkaiNavMeshTraversalUtils::computeGlobalClearance(&v166, v45, faceKeya[1], v108);
                  v156 = v166.m_real.m128_f32[0] * 1.0039062;
                  v152 = (__int16)(COERCE_INT(v166.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
                  v107 = _mm_shuffle_ps((__m128)v152, (__m128)v152, 0);
                }
                resulta.m_real = _mm_shuffle_ps(v100, _mm_unpackhi_ps(v100, v107), 196);
                if ( doesSegmentIntersectPlaneRegions(&A, (hkVector4f *)&resulta, &edgePlane1, &edgePlane2, &vertex) )
                {
                  clipSegmentToPlaneRegions(&A, (hkVector4f *)&resulta, &edgePlane1, &edgePlane2);
                  v109 = _mm_sub_ps(A.m_quad, v21);
                  v110 = _mm_sub_ps(resulta.m_real, A.m_quad);
                  v111 = _mm_sub_ps(resulta.m_real, v21);
                  v112 = _mm_mul_ps(v110, v109);
                  v113 = _mm_mul_ps(v110, v111);
                  v114 = _mm_add_ps(
                           _mm_add_ps(_mm_shuffle_ps(v112, v112, 85), _mm_shuffle_ps(v112, v112, 0)),
                           _mm_shuffle_ps(v112, v112, 170));
                  if ( v114.m128_f32[0] < 0.0 )
                  {
                    if ( (float)((float)(_mm_shuffle_ps(v113, v113, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v113, v113, 0).m128_f32[0])
                               + _mm_shuffle_ps(v113, v113, 170).m128_f32[0]) > 0.0 )
                    {
                      v126 = _mm_mul_ps(v110, v110);
                      v127 = _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v126, v126, 85), _mm_shuffle_ps(v126, v126, 0)),
                               _mm_shuffle_ps(v126, v126, 170));
                      v128 = _mm_rcp_ps(v127);
                      v129 = _mm_add_ps(
                               _mm_mul_ps(
                                 v110,
                                 _mm_mul_ps(
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v128, v127)), v128),
                                   _mm_sub_ps((__m128)0i64, v114))),
                               v109);
                      v130 = _mm_mul_ps(v129, v129);
                      v117 = _mm_add_ps(
                               _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                               _mm_shuffle_ps(v130, v130, 170));
                      if ( v80->m_oppositeEdge == -1 || (v80->m_flags.m_storage & 0x20) != 0 )
                      {
                        v66 = _mm_min_ps(v66, v117);
                        value.m_real = v66;
                      }
LABEL_82:
                      if ( v117.m128_f32[0] < v66.m128_f32[0]
                        && v80->m_oppositeEdge != -1
                        && (v80->m_flags.m_storage & 0x20) == 0 )
                      {
                        v131 = 0;
                        v132 = 0i64;
                        if ( value.m_real.m128_i32[0] <= 0 )
                          goto LABEL_90;
                        while ( v147[v132] != v86 )
                        {
                          ++v132;
                          ++v131;
                          if ( v132 >= value.m_real.m128_i32[0] )
                            goto LABEL_90;
                        }
                        if ( v131 < 0 )
                        {
LABEL_90:
                          if ( v91 >> 22 == (_DWORD)v147 )
                          {
                            v133 = v143;
                            if ( v143 == (v144 & 0x3FFFFFFF) )
                            {
                              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 12);
                              v133 = v143;
                            }
                            v134 = 3i64 * v133;
                            v135 = array;
                            v143 = v133 + 1;
                            *(_DWORD *)&array[4 * v134 + 4] = v86;
                            *(_DWORD *)&v135[4 * v134 + 8] = v91;
                            *(_DWORD *)&v135[4 * v134] = v117.m128_i32[0];
                          }
                        }
                      }
                      v76 = (int)accessora;
                      v52 = startFaceKey;
                      goto LABEL_68;
                    }
                    v125 = _mm_mul_ps(v111, v111);
                    v116 = resulta.m_real.m128_f32[3] == -1.0;
                    v117 = _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v125, v125, 85), _mm_shuffle_ps(v125, v125, 0)),
                             _mm_shuffle_ps(v125, v125, 170));
                  }
                  else
                  {
                    v115 = _mm_mul_ps(v109, v109);
                    v116 = A.m_quad.m128_f32[3] == -1.0;
                    v117 = _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                             _mm_shuffle_ps(v115, v115, 170));
                  }
                  if ( !v116 )
                    goto LABEL_82;
                  v66 = _mm_min_ps(v66, v117);
                  value.m_real = v66;
                }
              }
              v76 = (int)accessora;
              v52 = startFaceKey;
            }
          }
LABEL_68:
          v74 = v160;
          ++index;
        }
      }
      v69 = v143;
    }
    while ( v143 );
    v22 = vars0;
  }
LABEL_71:
  v118 = v52;
  v119 = v171;
  hkaiNavMeshTraversalUtils::updateClearance(v171, v45, v118, &edge, v22, v143, &value);
  v120 = value.m_real.m128_i32[0];
  v121 = (char *)value.m_real.m128_u64[1];
  if ( (_DWORD *)value.m_real.m128_u64[1] == v147 )
    v120 = 0;
  value.m_real.m128_i32[0] = v120;
  v122 = (4 * resulta.m_real.m128_i32[0] + 127) & 0xFFFFFF80;
  v123 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v124 = (v122 + 15) & 0xFFFFFFF0;
  if ( v122 > v123->m_slabSize || &v121[v124] != v123->m_cur || v123->m_firstNonLifoEnd == v121 )
    hkLifoAllocator::slowBlockFree(v123, v121, v124);
  else
    v123->m_cur = v121;
  value.m_real.m128_i32[0] = 0;
  if ( value.m_real.m128_i32[1] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v147,
      4 * value.m_real.m128_i32[1]);
  v136 = v143;
  v137 = *(char **)faceKeya;
  v147 = 0i64;
  value.m_real.m128_i32[1] = 0x80000000;
  if ( *(char **)faceKeya == array )
    v136 = 0;
  v143 = v136;
  v138 = (12 * v146 + 127) & 0xFFFFFF80;
  v139 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v140 = (v138 + 15) & 0xFFFFFFF0;
  if ( v138 > v139->m_slabSize || &v137[v140] != v139->m_cur || v139->m_firstNonLifoEnd == v137 )
    hkLifoAllocator::slowBlockFree(v139, v137, v140);
  else
    v139->m_cur = v137;
  v143 = 0;
  if ( v144 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array,
      12 * (v144 & 0x3FFFFFFF));
  return v119;
}

// File Line: 935
// RVA: 0xC17320
hkSimdFloat32 *__fastcall hkaiNavMeshTraversalUtils::updateClearance(
        hkSimdFloat32 *result,
        hkaiGeneralAccessor *accessor,
        unsigned int faceKey,
        hkaiNavMesh::Edge *edge,
        hkVector4f *up,
        int index,
        hkSimdFloat32 *value)
{
  int v9; // ebx
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  hkSimdFloat32 *v15; // rax
  float v16; // [rsp+30h] [rbp-48h]
  hkSimdFloat32 resulta; // [rsp+40h] [rbp-38h] BYREF
  unsigned int v18; // [rsp+90h] [rbp+18h]
  float v19; // [rsp+90h] [rbp+18h]

  v9 = faceKey >> 22;
  hkaiGeneralAccessor::setSection(accessor, faceKey >> 22);
  v16 = _mm_shuffle_ps(
          (__m128)LODWORD(accessor->m_accessor->m_maxGlobalClearance),
          (__m128)LODWORD(accessor->m_accessor->m_maxGlobalClearance),
          0).m128_f32[0];
  *result = (hkSimdFloat32)value->m_real;
  hkaiGeneralAccessor::setSection(accessor, v9);
  v18 = accessor->m_accessor->m_globalClearanceCache.m_data[edge->m_a].m_value << 16;
  v12 = _mm_shuffle_ps((__m128)v18, (__m128)v18, 0);
  if ( v12.m128_f32[0] > v16 )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(&resulta, accessor, faceKey, edge);
    v12 = _mm_shuffle_ps(
            (__m128)(unsigned int)((__int16)(COERCE_INT(resulta.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
            (__m128)(unsigned int)((__int16)(COERCE_INT(resulta.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
            0);
  }
  if ( v12.m128_f32[0] >= 0.0 )
  {
    v13 = _mm_rsqrt_ps(result->m_real);
    v14 = _mm_add_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(result->m_real, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(result->m_real, v13), v13)),
                  _mm_mul_ps(*(__m128 *)_xmm, v13)),
                result->m_real)),
            v12);
    result->m_real = _mm_mul_ps(v14, v14);
  }
  v15 = result;
  v19 = COERCE_FLOAT(*result) * 1.0039062;
  accessor->m_accessor->m_clearanceCache.m_data[index].m_value = HIWORD(v19);
  return v15;
}

// File Line: 968
// RVA: 0xC17510
void __fastcall hkaiNavMeshTraversalUtils::updateGlobalClearance(
        hkaiGeneralAccessor *accessor,
        int vertexIndex,
        hkSimdFloat32 *clearance)
{
  float v3; // [rsp+10h] [rbp+10h]

  v3 = COERCE_FLOAT(*clearance) * 1.0039062;
  accessor->m_accessor->m_globalClearanceCache.m_data[vertexIndex].m_value = HIWORD(v3);
}

// File Line: 980
// RVA: 0xC174D0
void __fastcall hkaiNavMeshTraversalUtils::updateGlobalClearance(
        hkaiNavMeshInstance *meshInstance,
        int vertexIndex,
        hkSimdFloat32 *clearance)
{
  float v3; // [rsp+10h] [rbp+10h]

  v3 = COERCE_FLOAT(*clearance) * 1.0039062;
  meshInstance->m_globalClearanceCache.m_data[vertexIndex].m_value = HIWORD(v3);
}

// File Line: 985
// RVA: 0xC13D50
void __fastcall hkaiNavMeshTraversalUtils::resetClearanceForFace(
        hkaiNavMeshInstance *meshInstance,
        int faceIndex,
        bool resetEdgeClearance,
        bool resetGlobalClearance)
{
  __int64 v4; // rsi
  int *v7; // rax
  int index; // edi
  int v9; // ecx
  char v10; // r11
  __int64 v11; // rax
  __int64 i; // rdx
  int v13; // esi
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_ownedEdges; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *p_m_instancedEdges; // r8
  hkaiNavMesh::Edge *v16; // rax

  v4 = faceIndex;
  v7 = (int *)hkaiNavMeshInstance_get_hkaiNavMesh::Face__13(
                meshInstance->m_originalFaces,
                meshInstance->m_numOriginalFaces,
                &meshInstance->m_instancedFaces,
                &meshInstance->m_ownedFaces,
                &meshInstance->m_faceMap,
                faceIndex);
  index = *v7;
  v9 = v7[2];
  if ( v10 )
  {
    v11 = meshInstance->m_faceClearanceIndices.m_data[v4];
    for ( i = (int)v11 + 3 * ((__int16)v9 - 2); v11 < i; meshInstance->m_clearanceCache.m_data[v11 - 1].m_value = -16512 )
      ++v11;
  }
  if ( resetGlobalClearance )
  {
    v13 = index + (__int16)v9;
    if ( index < v13 )
    {
      p_m_ownedEdges = &meshInstance->m_ownedEdges;
      p_m_instancedEdges = &meshInstance->m_instancedEdges;
      do
      {
        v16 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                meshInstance->m_originalEdges,
                meshInstance->m_numOriginalEdges,
                p_m_instancedEdges,
                p_m_ownedEdges,
                &meshInstance->m_edgeMap,
                index++);
        meshInstance->m_globalClearanceCache.m_data[v16->m_a].m_value = 32639;
      }
      while ( index < v13 );
    }
  }
}

// File Line: 1025
// RVA: 0xC14A90
void __fastcall hkaiNavMeshTraversalUtils::getVertexClearanceForEdge(
        hkaiGeneralAccessor *accessor,
        unsigned int faceKey,
        hkaiNavMesh::Face *currentFace,
        hkaiNavMeshTraversalUtils::Angle *angle,
        hkVector4f *up,
        hkSimdFloat32 *maxRadius,
        hkaiNavMeshTraversalUtils::ClearanceValue *clearanceOut)
{
  hkaiNavMeshInstance *m_accessor; // rbx
  __int16 m_value; // ax
  __m128 m_real; // xmm0
  hkSimdFloat32 result; // [rsp+40h] [rbp-28h] BYREF

  hkaiGeneralAccessor::setSection(accessor, faceKey >> 22);
  m_accessor = accessor->m_accessor;
  m_value = m_accessor->m_clearanceCache.m_data[m_accessor->m_faceClearanceIndices.m_data[faceKey & 0x3FFFFF]
                                              + (__int64)(int)hkaiNavMeshTraversalUtils::Angle::index(angle)].m_value;
  if ( m_value == -16512 )
  {
    hkaiNavMeshTraversalUtils::computeVertexClearance(&result, accessor, faceKey, currentFace, angle, up, maxRadius);
    m_real = result.m_real;
    clearanceOut->m_exactValueComputed = 1;
    clearanceOut->m_exactValue.m_real = m_real;
    clearanceOut->m_valueHalf.m_value = m_real.m128_i16[1];
    clearanceOut->m_truncatedValue.m_real = _mm_shuffle_ps(
                                              (__m128)(unsigned int)(m_real.m128_i16[1] << 16),
                                              (__m128)(unsigned int)(m_real.m128_i16[1] << 16),
                                              0);
  }
  else
  {
    clearanceOut->m_exactValueComputed = 0;
    clearanceOut->m_exactValue = 0i64;
    clearanceOut->m_truncatedValue.m_real = _mm_shuffle_ps(
                                              (__m128)(unsigned int)(m_value << 16),
                                              (__m128)(unsigned int)(m_value << 16),
                                              0);
    clearanceOut->m_valueHalf.m_value = m_value;
  }
}

// File Line: 1053
// RVA: 0xC14960
char __fastcall hkaiNavMeshTraversalUtils::isVertexClearanceForEdgeLessThan(
        hkaiGeneralAccessor *accessor,
        unsigned int faceKey,
        hkaiNavMesh::Face *currentFace,
        hkaiNavMeshTraversalUtils::Angle *angle,
        hkVector4f *up,
        hkSimdFloat32 *maxRadius,
        hkSimdFloat32 *threshold)
{
  hkSimdFloat32 result; // [rsp+50h] [rbp-58h] BYREF
  hkaiNavMeshTraversalUtils::ClearanceValue v13; // [rsp+60h] [rbp-48h] BYREF

  memset(&v13, 0, 38);
  hkaiNavMeshTraversalUtils::getVertexClearanceForEdge(accessor, faceKey, currentFace, angle, up, maxRadius, &v13);
  if ( v13.m_exactValueComputed )
    return v13.m_exactValue.m_real.m128_f32[0] < threshold->m_real.m128_f32[0];
  if ( v13.m_truncatedValue.m_real.m128_f32[0] >= COERCE_FLOAT(*threshold) )
    return 0;
  if ( fmax(
         _mm_shuffle_ps(
           (__m128)(unsigned int)((__int16)(v13.m_valueHalf.m_value + 1) << 16),
           (__m128)(unsigned int)((__int16)(v13.m_valueHalf.m_value + 1) << 16),
           0).m128_f32[0],
         v13.m_truncatedValue.m_real.m128_f32[0]) < COERCE_FLOAT(*threshold) )
    return 1;
  hkaiNavMeshTraversalUtils::computeVertexClearance(&result, accessor, faceKey, currentFace, angle, up, maxRadius);
  return result.m_real.m128_f32[0] < threshold->m_real.m128_f32[0];
}

// File Line: 1085
// RVA: 0xC13E90
void __fastcall hkaiNavMeshTraversalUtils::computeAllGlobalClearances(
        hkaiNavMeshInstance *meshInstance,
        hkVector4f *up)
{
  int v2; // r9d
  hkVector4f *v4; // r15
  int m_numOriginalEdges; // r9d
  int v6; // r9d
  _QWORD *Value; // r8
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  int m_numOriginalFaces; // edx
  int m_size; // ecx
  int index; // r11d
  unsigned __int64 v14; // rsi
  hkVector4f **v15; // rax
  int v16; // edi
  hkaiNavMesh::Face *v17; // r14
  int v18; // esi
  hkaiNavMesh::Edge *v19; // rax
  hkaiNavMesh::Edge *v20; // r8
  __int64 m_a; // rax
  int m_numOriginalVertices; // ecx
  hkVector4f *v23; // rax
  __m128 m_quad; // xmm1
  hkVector4f v25; // xmm4
  hkVector4f v26; // xmm5
  __int64 m_b; // rax
  hkVector4f v28; // xmm6
  hkVector4f v29; // xmm7
  __m128 v30; // xmm3
  hkVector4f *v31; // rax
  __m128 v32; // xmm1
  hk1AxisSweep::AabbInt *v33; // rcx
  __m128 v34; // xmm2
  int v35; // ecx
  _QWORD *v36; // rax
  unsigned __int64 v37; // rcx
  _QWORD *v38; // r8
  unsigned __int64 v39; // rax
  __m128 v40; // xmm6
  _QWORD *v41; // rax
  _QWORD *v42; // rcx
  _QWORD *v43; // r8
  unsigned __int64 v44; // rax
  _QWORD *v45; // rcx
  int v46; // edx
  int v47; // edi
  __int64 v48; // rsi
  hkVector4f *v49; // rax
  __m128 v50; // xmm1
  hk1AxisSweep::AabbInt *v51; // rcx
  __m128 v52; // xmm0
  _QWORD *v53; // rax
  _QWORD *v54; // rcx
  _QWORD *v55; // r8
  unsigned __int64 v56; // rax
  _QWORD *v57; // rcx
  int v58; // ecx
  int v59; // esi
  __int64 v60; // r8
  int v61; // edi
  __int64 v62; // rdx
  _QWORD *v63; // r8
  _QWORD *v64; // rcx
  unsigned __int64 v65; // rax
  _QWORD *v66; // rcx
  _QWORD *v67; // r8
  _QWORD *v68; // rcx
  unsigned __int64 v69; // rax
  _QWORD *v70; // rcx
  _QWORD *v71; // r8
  _QWORD *v72; // rcx
  unsigned __int64 v73; // rax
  _QWORD *v74; // rcx
  hk1AxisSweep::AabbInt *v75; // rdx
  unsigned int v76; // eax
  bool v77; // cf
  bool v78; // zf
  hk1AxisSweep::AabbInt *m_potentialPtr; // rax
  hk1AxisSweep::AabbInt *m_pa; // rcx
  __int64 v81; // rsi
  int v82; // edi
  hkVector4f *v83; // rax
  hkVector4f v84; // xmm6
  hkVector4f v85; // xmm10
  hkVector4f v86; // xmm11
  hkVector4f v87; // xmm12
  __m128 v88; // xmm9
  hkaiNavMesh::Edge *v89; // rax
  __int64 v90; // rcx
  hkVector4f *v91; // rcx
  __int64 v92; // rax
  __m128 v93; // xmm8
  hkVector4f *v94; // rax
  __m128 v95; // xmm1
  __m128 v96; // xmm7
  __m128 v97; // xmm2
  __m128 v98; // xmm1
  __m128 v99; // xmm9
  __m128 v100; // xmm2
  __m128 v101; // xmm1
  __m128 v102; // xmm5
  __m128 v103; // xmm8
  __m128 v104; // xmm7
  __m128 v105; // xmm5
  __m128 v106; // xmm1
  __m128 v107; // xmm4
  __m128 v108; // xmm1
  __m128 v109; // xmm0
  __m128 v110; // xmm3
  __m128 v111; // xmm1
  __m128 v112; // xmm0
  __m128 v113; // xmm3
  __m128 v114; // xmm8
  __m128 v115; // xmm7
  __m128 v116; // xmm7
  __m128 v117; // xmm3
  __m128 v118; // xmm3
  __m128 v119; // xmm4
  __m128 v120; // xmm1
  _QWORD *v121; // rax
  _QWORD *v122; // rcx
  _QWORD *v123; // r8
  unsigned __int64 v124; // rax
  _QWORD *v125; // rcx
  hkSimdFloat32 clearance; // [rsp+30h] [rbp-C8h] BYREF
  hk1AxisSweep::AabbInt *aabbs; // [rsp+40h] [rbp-B8h] BYREF
  int v128; // [rsp+48h] [rbp-B0h]
  int v129; // [rsp+4Ch] [rbp-ACh]
  hk1AxisSweep::AabbInt *array; // [rsp+50h] [rbp-A8h] BYREF
  int size; // [rsp+58h] [rbp-A0h]
  int v132; // [rsp+5Ch] [rbp-9Ch]
  hk1AxisSweep::IteratorAB aabbIn; // [rsp+60h] [rbp-98h] BYREF
  void *retaddr; // [rsp+148h] [rbp+50h] BYREF
  hkVector4f *v135; // [rsp+150h] [rbp+58h]
  hkVector4f *v136; // [rsp+158h] [rbp+60h] BYREF
  int v137; // [rsp+160h] [rbp+68h]

  v136 = up;
  v2 = meshInstance->m_numOriginalVertices + meshInstance->m_ownedVertices.m_size + 4;
  v4 = up;
  array = 0i64;
  size = 0;
  v132 = 0x80000000;
  if ( v2 > 0 )
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerTempAllocator::s_alloc, &array, v2, 32);
  m_numOriginalEdges = meshInstance->m_numOriginalEdges;
  aabbs = 0i64;
  v128 = 0;
  v129 = 0x80000000;
  v6 = meshInstance->m_ownedEdges.m_size + m_numOriginalEdges + 4;
  if ( v6 > 0 )
    hkArrayUtil::_reserve((hkResult *)&retaddr, &hkContainerTempAllocator::s_alloc, &aabbs, v6, 32);
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v8 < Value[3] )
  {
    *v8 = "TtboundaryAabbs";
    v9 = __rdtsc();
    v10 = v8 + 2;
    *((_DWORD *)v10 - 2) = v9;
    Value[1] = v10;
  }
  m_numOriginalFaces = meshInstance->m_numOriginalFaces;
  m_size = meshInstance->m_ownedFaces.m_size;
  index = 0;
  v137 = 0;
  v14 = 0i64;
  clearance.m_real.m128_u64[0] = 0i64;
  if ( m_numOriginalFaces + m_size > 0 )
  {
    do
    {
      if ( meshInstance->m_faceFlags.m_size )
      {
        v15 = (hkVector4f **)&retaddr;
        LOBYTE(retaddr) = meshInstance->m_faceFlags.m_data[v14].m_storage;
      }
      else
      {
        LOBYTE(v136) = 0;
        v15 = &v136;
      }
      if ( (*(_BYTE *)v15 & 1) == 0 )
      {
        v16 = 0;
        v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__13(
                meshInstance->m_originalFaces,
                m_numOriginalFaces,
                &meshInstance->m_instancedFaces,
                &meshInstance->m_ownedFaces,
                &meshInstance->m_faceMap,
                index);
        if ( v17->m_numEdges > 0 )
        {
          do
          {
            v18 = v16 + v17->m_startEdgeIndex;
            v19 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                    meshInstance->m_originalEdges,
                    meshInstance->m_numOriginalEdges,
                    &meshInstance->m_instancedEdges,
                    &meshInstance->m_ownedEdges,
                    &meshInstance->m_edgeMap,
                    v18);
            v20 = v19;
            if ( v19->m_oppositeEdge == -1 || (v19->m_flags.m_storage & 0x20) != 0 )
            {
              meshInstance->m_globalClearanceCache.m_data[v19->m_a].m_value = -16512;
              meshInstance->m_globalClearanceCache.m_data[v19->m_b].m_value = -16512;
              m_a = v19->m_a;
              m_numOriginalVertices = meshInstance->m_numOriginalVertices;
              if ( (int)m_a >= m_numOriginalVertices )
                v23 = &meshInstance->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices];
              else
                v23 = &meshInstance->m_originalVertices[m_a];
              m_quad = v23->m_quad;
              v25.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col1;
              v26.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col0;
              m_b = v20->m_b;
              v28.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col2;
              v29.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_translation;
              v30 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v26.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v25.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v28.m_quad)),
                      v29.m_quad);
              if ( (int)m_b >= m_numOriginalVertices )
                v31 = &meshInstance->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices];
              else
                v31 = &meshInstance->m_originalVertices[m_b];
              v32 = v31->m_quad;
              v33 = &aabbs[v128++];
              v34 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v26.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v25.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v28.m_quad)),
                      v29.m_quad);
              *(__m128 *)&aabbIn.m_aIsBigger = _mm_min_ps(v30, v34);
              *(__m128 *)&aabbIn.m_potentialPtr = _mm_max_ps(v30, v34);
              hk1AxisSweep::AabbInt::set(v33, (hkAabb *)&aabbIn, v18);
            }
            ++v16;
          }
          while ( v16 < v17->m_numEdges );
          index = v137;
          v14 = clearance.m_real.m128_u64[0];
        }
      }
      m_numOriginalFaces = meshInstance->m_numOriginalFaces;
      ++index;
      ++v14;
      v35 = m_numOriginalFaces + meshInstance->m_ownedFaces.m_size;
      v137 = index;
      clearance.m_real.m128_u64[0] = v14;
    }
    while ( index < v35 );
    v4 = v135;
  }
  v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v37 = v36[1];
  v38 = v36;
  if ( v37 < v36[3] )
  {
    *(_QWORD *)v37 = "Et";
    v39 = __rdtsc();
    *(_DWORD *)(v37 + 8) = v39;
    v38[1] = v37 + 16;
  }
  v40 = _mm_shuffle_ps(
          (__m128)LODWORD(meshInstance->m_maxGlobalClearance),
          (__m128)LODWORD(meshInstance->m_maxGlobalClearance),
          0);
  *(float *)&retaddr = v40.m128_f32[0] * 1.0039062;
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  v43 = v41;
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "TtvertAabbs";
    v44 = __rdtsc();
    v45 = v42 + 2;
    *((_DWORD *)v45 - 2) = v44;
    v43[1] = v45;
  }
  v46 = meshInstance->m_numOriginalVertices;
  v47 = 0;
  if ( v46 + meshInstance->m_ownedVertices.m_size > 0 )
  {
    v48 = 0i64;
    do
    {
      LODWORD(retaddr) = meshInstance->m_globalClearanceCache.m_data[v48].m_value << 16;
      if ( _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0).m128_f32[0] > v40.m128_f32[0] )
      {
        if ( v47 >= v46 )
          v49 = &meshInstance->m_ownedVertices.m_data[v47 - v46];
        else
          v49 = &meshInstance->m_originalVertices[v47];
        v50 = v49->m_quad;
        v51 = &array[size++];
        v52 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(v50, v50, 85),
                      meshInstance->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v50, v50, 0),
                      meshInstance->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(v50, v50, 170),
                    meshInstance->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                meshInstance->m_referenceFrame.m_transform.m_translation.m_quad);
        *(__m128 *)&aabbIn.m_potentialPtr = _mm_add_ps(v52, v40);
        *(__m128 *)&aabbIn.m_aIsBigger = _mm_sub_ps(v52, v40);
        hk1AxisSweep::AabbInt::set(v51, (hkAabb *)&aabbIn, v47);
        meshInstance->m_globalClearanceCache.m_data[v48].m_value = COERCE_INT(v40.m128_f32[0] * 1.0039062) >> 16;
      }
      v46 = meshInstance->m_numOriginalVertices;
      ++v47;
      ++v48;
    }
    while ( v47 < v46 + meshInstance->m_ownedVertices.m_size );
  }
  v53 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v54 = (_QWORD *)v53[1];
  v55 = v53;
  if ( (unsigned __int64)v54 < v53[3] )
  {
    *v54 = "Et";
    v56 = __rdtsc();
    v57 = v54 + 2;
    *((_DWORD *)v57 - 2) = v56;
    v55[1] = v57;
  }
  v58 = size;
  v59 = v128;
  v60 = 4i64;
  v61 = size;
  while ( 1 )
  {
    size = v58 + 1;
    array[v58].m_min[0] = -1;
    v62 = v128++;
    aabbs[v62].m_min[0] = -1;
    if ( !--v60 )
      break;
    v58 = size;
  }
  v63 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v64 = (_QWORD *)v63[1];
  if ( (unsigned __int64)v64 < v63[3] )
  {
    *v64 = "Ttsort";
    v65 = __rdtsc();
    v66 = v64 + 2;
    *((_DWORD *)v66 - 2) = v65;
    v63[1] = v66;
  }
  hk1AxisSweep::sortAabbs(array, v61);
  hk1AxisSweep::sortAabbs(aabbs, v59);
  v67 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v68 = (_QWORD *)v67[1];
  if ( (unsigned __int64)v68 < v67[3] )
  {
    *v68 = "Et";
    v69 = __rdtsc();
    v70 = v68 + 2;
    *((_DWORD *)v70 - 2) = v69;
    v67[1] = v70;
  }
  v71 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v72 = (_QWORD *)v71[1];
  if ( (unsigned __int64)v72 < v71[3] )
  {
    *v72 = "Ttcalc";
    v73 = __rdtsc();
    v74 = v72 + 2;
    *((_DWORD *)v74 - 2) = v73;
    v71[1] = v74;
  }
  v75 = array;
  v76 = aabbs->m_min[0];
  aabbIn.m_pb = (hk1AxisSweep::AabbInt *)__PAIR64__(v59, v61);
  v77 = array->m_min[0] < v76;
  v78 = array->m_min[0] == v76;
  aabbIn.m_pa = aabbs;
  aabbIn.m_aIsBigger = !v77 && !v78;
  if ( v77 || v78 )
  {
    aabbIn.m_currentPtr = array;
    v75 = aabbs;
  }
  else
  {
    aabbIn.m_currentPtr = aabbs;
  }
  aabbIn.m_potentialPtr = v75 - 1;
  hk1AxisSweep::IteratorAB::next(&aabbIn);
  while ( SLODWORD(aabbIn.m_pb) > 0 && SHIDWORD(aabbIn.m_pb) > 0 )
  {
    if ( aabbIn.m_aIsBigger )
    {
      m_pa = aabbIn.m_pa;
      m_potentialPtr = aabbIn.m_potentialPtr;
    }
    else
    {
      m_potentialPtr = aabbIn.m_pa;
      m_pa = aabbIn.m_potentialPtr;
    }
    v81 = *(int *)m_potentialPtr->m_expansionMin;
    v82 = meshInstance->m_numOriginalVertices;
    if ( (int)v81 >= v82 )
      v83 = &meshInstance->m_ownedVertices.m_data[(int)v81 - v82];
    else
      v83 = &meshInstance->m_originalVertices[v81];
    v84.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col1;
    v85.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col0;
    v86.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_rotation.m_col2;
    v87.m_quad = (__m128)meshInstance->m_referenceFrame.m_transform.m_translation;
    v88 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v83->m_quad, v83->m_quad, 0), v85.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v83->m_quad, v83->m_quad, 85), v84.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v83->m_quad, v83->m_quad, 170), v86.m_quad)),
            v87.m_quad);
    v89 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            meshInstance->m_originalEdges,
            meshInstance->m_numOriginalEdges,
            &meshInstance->m_instancedEdges,
            &meshInstance->m_ownedEdges,
            &meshInstance->m_edgeMap,
            *(_DWORD *)m_pa->m_expansionMin);
    v90 = v89->m_a;
    if ( (int)v90 >= v82 )
      v91 = &meshInstance->m_ownedVertices.m_data[(int)v90 - v82];
    else
      v91 = &meshInstance->m_originalVertices[v90];
    v92 = v89->m_b;
    v93 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v91->m_quad, v91->m_quad, 0), v85.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v91->m_quad, v91->m_quad, 85), v84.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v91->m_quad, v91->m_quad, 170), v86.m_quad)),
            v87.m_quad);
    if ( (int)v92 >= v82 )
      v94 = &meshInstance->m_ownedVertices.m_data[(int)v92 - v82];
    else
      v94 = &meshInstance->m_originalVertices[v92];
    v95 = _mm_mul_ps(v88, v4->m_quad);
    v96 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v94->m_quad, v94->m_quad, 0), v85.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v94->m_quad, v94->m_quad, 85), v84.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v94->m_quad, v94->m_quad, 170), v86.m_quad)),
            v87.m_quad);
    v97 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
            _mm_shuffle_ps(v95, v95, 170));
    v98 = _mm_mul_ps(v93, v4->m_quad);
    v99 = _mm_sub_ps(v88, _mm_mul_ps(v97, v4->m_quad));
    v100 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v98, v98, 85), _mm_shuffle_ps(v98, v98, 0)),
             _mm_shuffle_ps(v98, v98, 170));
    v101 = _mm_mul_ps(v96, v4->m_quad);
    v102 = _mm_sub_ps(v93, _mm_mul_ps(v100, v4->m_quad));
    v103 = _mm_sub_ps(v102, v99);
    v104 = _mm_sub_ps(
             v96,
             _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                 _mm_shuffle_ps(v101, v101, 170)),
               v4->m_quad));
    v105 = _mm_sub_ps(v102, v104);
    v106 = _mm_mul_ps(v105, v105);
    v107 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v106, v106, 85), _mm_shuffle_ps(v106, v106, 0)),
             _mm_shuffle_ps(v106, v106, 170));
    v108 = _mm_mul_ps(v103, v105);
    v109 = _mm_rcp_ps(v107);
    v110 = _mm_mul_ps(
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v107, v109)), v109),
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
               _mm_shuffle_ps(v108, v108, 170)));
    v111 = _mm_cmplt_ps(v110, query.m_quad);
    v112 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v111, query.m_quad), _mm_and_ps(v110, v111)));
    v113 = v103;
    v114 = _mm_mul_ps(v103, v103);
    v115 = _mm_sub_ps(v104, v99);
    LODWORD(retaddr) = meshInstance->m_globalClearanceCache.m_data[v81].m_value << 16;
    v116 = _mm_mul_ps(v115, v115);
    v117 = _mm_sub_ps(v113, _mm_mul_ps(v112, v105));
    v118 = _mm_mul_ps(v117, v117);
    v119 = _mm_min_ps(
             _mm_min_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                 _mm_shuffle_ps(v114, v114, 170)),
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v116, v116, 85), _mm_shuffle_ps(v116, v116, 0)),
                 _mm_shuffle_ps(v116, v116, 170))),
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v118, v118, 85), _mm_shuffle_ps(v118, v118, 0)),
               _mm_shuffle_ps(v118, v118, 170)));
    v120 = _mm_rsqrt_ps(v119);
    clearance.m_real = _mm_andnot_ps(
                         _mm_cmple_ps(v119, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v120, v119), v120)),
                             _mm_mul_ps(*(__m128 *)_xmm, v120)),
                           v119));
    if ( clearance.m_real.m128_f32[0] < _mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0).m128_f32[0] )
      hkaiNavMeshTraversalUtils::updateGlobalClearance(meshInstance, v81, &clearance);
    hk1AxisSweep::IteratorAB::next(&aabbIn);
  }
  v121 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v122 = (_QWORD *)v121[1];
  v123 = v121;
  if ( (unsigned __int64)v122 < v121[3] )
  {
    *v122 = "Et";
    v124 = __rdtsc();
    v125 = v122 + 2;
    *((_DWORD *)v125 - 2) = v124;
    v123[1] = v125;
  }
  v128 = 0;
  if ( v129 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, aabbs, 32 * v129);
  aabbs = 0i64;
  size = 0;
  v129 = 0x80000000;
  if ( v132 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 32 * v132);
}

// File Line: 1205
// RVA: 0xC17EC0
_BOOL8 __fastcall SameSectionFilter::isInstanceEnabled(
        SameSectionFilter *this,
        hkaiNavMeshInstance *instance,
        unsigned int filterInfo,
        unsigned __int64 userData)
{
  int m_allowedSection; // ecx

  if ( !instance )
    return 1i64;
  m_allowedSection = this->m_allowedSection;
  return m_allowedSection == -1 || instance->m_runtimeId == m_allowedSection;
}

// File Line: 1232
// RVA: 0xC16270
hkSimdFloat32 *__fastcall hkaiNavMeshTraversalUtils::computeGlobalClearance(
        hkSimdFloat32 *result,
        hkaiNavMeshInstance *meshInstance,
        hkaiNavMeshQueryMediator *worldMediator,
        int vIdx,
        hkVector4f *up)
{
  int m_numOriginalVertices; // eax
  hkVector4f *v7; // rax
  __m128 m_quad; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v13; // xmm3
  hkSimdFloat32 *v14; // rax
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  void **v17; // [rsp+20h] [rbp-B8h] BYREF
  int v18; // [rsp+28h] [rbp-B0h]
  int m_runtimeId; // [rsp+30h] [rbp-A8h]
  __m128 v20; // [rsp+40h] [rbp-98h] BYREF
  int v21; // [rsp+50h] [rbp-88h] BYREF
  __int64 v22; // [rsp+58h] [rbp-80h]
  void ***v23; // [rsp+60h] [rbp-78h]
  __int64 v24; // [rsp+68h] [rbp-70h]
  __int64 v25; // [rsp+70h] [rbp-68h]
  __m128 v26; // [rsp+80h] [rbp-58h]
  __m128 v27; // [rsp+90h] [rbp-48h]
  __int64 v28; // [rsp+A0h] [rbp-38h]
  __m128 v29; // [rsp+B0h] [rbp-28h]
  float m_maxGlobalClearance; // [rsp+F8h] [rbp+20h]

  v17 = &SameSectionFilter::`vftable;
  m_runtimeId = meshInstance->m_runtimeId;
  m_numOriginalVertices = meshInstance->m_numOriginalVertices;
  v18 = 0x1FFFF;
  if ( vIdx >= m_numOriginalVertices )
    v7 = &meshInstance->m_ownedVertices.m_data[vIdx - m_numOriginalVertices];
  else
    v7 = &meshInstance->m_originalVertices[vIdx];
  m_quad = v7->m_quad;
  v21 = 0;
  v22 = 0i64;
  v24 = 0i64;
  v25 = 0i64;
  v28 = 0i64;
  v9 = _mm_mul_ps(
         _mm_shuffle_ps(m_quad, m_quad, 0),
         meshInstance->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad);
  v10 = _mm_mul_ps(
          _mm_shuffle_ps(m_quad, m_quad, 85),
          meshInstance->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad);
  v11 = _mm_mul_ps(
          _mm_shuffle_ps(m_quad, m_quad, 170),
          meshInstance->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad);
  v23 = &v17;
  m_maxGlobalClearance = meshInstance->m_maxGlobalClearance;
  vfptr = worldMediator->vfptr;
  v29 = up->m_quad;
  v13 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(v10, v9), v11),
          meshInstance->m_referenceFrame.m_transform.m_translation.m_quad);
  v27 = _mm_shuffle_ps((__m128)LODWORD(m_maxGlobalClearance), (__m128)LODWORD(m_maxGlobalClearance), 0);
  v26 = v13;
  v20 = _mm_shuffle_ps((__m128)0i64, _mm_unpackhi_ps((__m128)0i64, _mm_mul_ps(v27, v27)), 196);
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, __m128 *))vfptr[2].__vecDelDtor)(worldMediator, &v21, &v20);
  v14 = result;
  v15 = _mm_shuffle_ps(v20, v20, 255);
  v16 = _mm_rsqrt_ps(v15);
  result->m_real = _mm_andnot_ps(
                     _mm_cmple_ps(v15, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)),
                         _mm_mul_ps(*(__m128 *)_xmm, v16)),
                       v15));
  return v14;
}

