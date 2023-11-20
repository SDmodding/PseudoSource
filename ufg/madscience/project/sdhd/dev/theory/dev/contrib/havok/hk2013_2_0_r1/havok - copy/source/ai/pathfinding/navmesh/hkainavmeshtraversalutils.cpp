// File Line: 45
// RVA: 0xC17640
signed __int64 __fastcall doesSegmentIntersectPlaneRegions(hkVector4f *A, hkVector4f *B, hkVector4f *edgePlane1, hkVector4f *edgePlane2, hkVector4f *vertex)
{
  __m128 v5; // xmm4
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
  int v19; // er8
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

  v5 = B->m_quad;
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
  v16 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v15, v15, 177)) + v15.m128_f32[0]) < 0.0;
  v17 = _mm_mul_ps(edgePlane2->m_quad, v8);
  v18 = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, edgePlane2->m_quad), 196);
  v19 = ((float)(COERCE_FLOAT(_mm_shuffle_ps(v14, v14, 177)) + v14.m128_f32[0]) < 0.0) + v16;
  v20 = _mm_add_ps(_mm_shuffle_ps(v18, v18, 78), v18);
  v21 = _mm_mul_ps(edgePlane2->m_quad, B->m_quad);
  v22 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, edgePlane2->m_quad), 196);
  v23 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 78), v22);
  v24 = ((float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 177)) + v23.m128_f32[0]) < 0.0)
      + ((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 177)) + v20.m128_f32[0]) < 0.0);
  if ( !v19 || !v24 )
    return 0i64;
  if ( v19 == 2 || v24 == 2 )
    return 1i64;
  v25 = _mm_sub_ps(v8, v5);
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
  v32 = _mm_cmpltps(v31, query.m_quad);
  v33 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v31, v32), _mm_andnot_ps(v32, query.m_quad)));
  v34 = _mm_add_ps(_mm_sub_ps(v26, _mm_mul_ps(v33, v25)), vertex->m_quad);
  v35 = _mm_shuffle_ps(v34, _mm_unpackhi_ps(v34, v33), 196);
  v36 = _mm_mul_ps(v6, v35);
  v37 = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v6), 196);
  v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
  v39 = _mm_mul_ps(v7, v35);
  v40 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, v7), 196);
  v41 = _mm_add_ps(_mm_shuffle_ps(v40, v40, 78), v40);
  if ( (float)(COERCE_FLOAT(_mm_shuffle_ps(v38, v38, 177)) + v38.m128_f32[0]) < 0.0
    && (float)(COERCE_FLOAT(_mm_shuffle_ps(v41, v41, 177)) + v41.m128_f32[0]) < 0.0 )
  {
    v9 = 1;
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
  hkVector4f v13; // xmm1
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  hkVector4f v16; // xmm1

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
      v16.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(A->m_quad, B->m_quad),
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v14, v15)), v15), v10)),
                     B->m_quad);
      *B = (hkVector4f)v16.m_quad;
      B->m_quad = _mm_shuffle_ps(v16.m_quad, _mm_unpackhi_ps(v16.m_quad, query.m_quad), 196);
    }
    else
    {
      v11 = _mm_sub_ps(v7, v10);
      v12 = _mm_rcp_ps(v11);
      v13.m_quad = _mm_add_ps(
                     _mm_mul_ps(
                       _mm_sub_ps(B->m_quad, A->m_quad),
                       _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v11, v12)), v12), v7)),
                     A->m_quad);
      *A = (hkVector4f)v13.m_quad;
      A->m_quad = _mm_shuffle_ps(v13.m_quad, _mm_unpackhi_ps(v13.m_quad, query.m_quad), 196);
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
__int64 __fastcall hkaiNavMeshTraversalUtils::isEdgePairTraversable(hkSimdFloat32 *diameter, hkaiNavMeshInstance *meshInstance, int faceIndex, int edgeInIndex, int edgeOutIndex, hkVector4f *up)
{
  hkSimdFloat32 *v6; // r13
  int v7; // er15
  int index; // er12
  hkaiNavMeshInstance *v9; // r14
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  _QWORD *v12; // r10
  unsigned __int64 v13; // rax
  signed __int64 v14; // rcx
  hkaiNavMesh::Face *v15; // rax
  int v16; // edi
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v17; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v18; // r9
  hkaiNavMesh::Edge *v19; // rax
  unsigned int insideEdgeKey; // er15
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v21; // r8
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v22; // r9
  hkaiNavMesh::Edge *v23; // rax
  __int64 v24; // rcx
  signed int v25; // edx
  hkaiNavMesh::Edge *v26; // rbx
  __m128 *v27; // rcx
  __m128 v28; // xmm3
  __m128 v29; // xmm4
  __int64 v30; // rax
  __m128 v31; // xmm5
  __m128 v32; // xmm2
  __m128 *v33; // rax
  __m128 v34; // xmm1
  int edgeOutKey; // edi
  int v36; // er9
  hkaiStreamingCollection::InstanceInfo *v37; // r8
  __int64 v38; // rdx
  hkaiDirectedGraphInstance **v39; // rax
  unsigned int v40; // ebx
  _QWORD *v41; // r8
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx
  hkaiNavMesh::Face *face; // [rsp+70h] [rbp-90h]
  hkaiNavMesh::Edge *edgeOut; // [rsp+78h] [rbp-88h]
  hkaiStreamingCollection array; // [rsp+80h] [rbp-80h]
  hkaiGeneralAccessor accessor; // [rsp+B0h] [rbp-50h]
  hkVector4f edgeA; // [rsp+D0h] [rbp-30h]
  hkVector4f edgeB; // [rsp+E0h] [rbp-20h]
  hkVector4f inA; // [rsp+F0h] [rbp-10h]
  hkVector4f inB; // [rsp+100h] [rbp+0h]
  hkResult result; // [rsp+148h] [rbp+48h]

  v6 = diameter;
  v7 = edgeInIndex;
  index = faceIndex;
  v9 = meshInstance;
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = (_QWORD *)v10[1];
  v12 = v10;
  if ( (unsigned __int64)v11 < v10[3] )
  {
    *v11 = "TttraverseCheck";
    v13 = __rdtsc();
    v14 = (signed __int64)(v11 + 2);
    *(_DWORD *)(v14 - 8) = v13;
    v12[1] = v14;
  }
  v15 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__13(
          v9->m_originalFaces,
          v9->m_numOriginalFaces,
          &v9->m_instancedFaces,
          &v9->m_ownedFaces,
          &v9->m_faceMap,
          index);
  v16 = v9->m_numOriginalEdges;
  face = v15;
  edgeOut = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
              v9->m_originalEdges,
              v9->m_numOriginalEdges,
              &v9->m_instancedEdges,
              &v9->m_ownedEdges,
              &v9->m_edgeMap,
              edgeOutIndex);
  v19 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(v9->m_originalEdges, v16, v17, v18, &v9->m_edgeMap, v7);
  insideEdgeKey = v19->m_oppositeEdge;
  v23 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
          v9->m_originalEdges,
          v16,
          v21,
          v22,
          &v9->m_edgeMap,
          v19->m_oppositeEdge);
  v24 = v23->m_a;
  v25 = v9->m_numOriginalVertices;
  v26 = v23;
  if ( (signed int)v24 >= v25 )
    v27 = &v9->m_ownedVertices.m_data[(signed int)v24 - v25].m_quad;
  else
    v27 = &v9->m_originalVertices[v24].m_quad;
  v28 = v9->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
  v29 = v9->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
  v30 = v23->m_b;
  v31 = v9->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
  v32 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 0), v29), _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 85), v28)),
            _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 170), v31)),
          v9->m_referenceFrame.m_transform.m_translation.m_quad);
  if ( (signed int)v30 >= v25 )
    v33 = &v9->m_ownedVertices.m_data[(signed int)v30 - v25].m_quad;
  else
    v33 = &v9->m_originalVertices[v30].m_quad;
  v34 = *v33;
  edgeOutKey = edgeOutIndex;
  inB.m_quad = v32;
  inA.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v29),
                     _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v28)),
                   _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v31)),
                 v9->m_referenceFrame.m_transform.m_translation.m_quad);
  hkaiNavMeshInstance::getEdgePoints(v9, edgeOutIndex, &edgeA, &edgeB);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v36 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v36 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v36,
      48);
  }
  v37 = array.m_instances.m_data;
  v38 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v39 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v39 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v39 - 2) = 0i64;
        *(v39 - 1) = 0i64;
        *v39 = 0i64;
        v39[1] = 0i64;
        v39[2] = 0i64;
        *((_DWORD *)v39 + 6) = -1;
      }
      v39 += 6;
      --v38;
    }
    while ( v38 );
    v37 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v37->m_instancePtr = v9;
  array.m_instances.m_data->m_clusterGraphInstance = 0i64;
  accessor.m_accessor = 0i64;
  array.m_instances.m_data->m_mediator = 0i64;
  accessor.m_sectionInfo = array.m_instances.m_data;
  accessor.m_currentSection = -1;
  v40 = hkaiNavMeshTraversalUtils::isEdgePairTraversable(
          v6,
          &accessor,
          index,
          face,
          up,
          v26,
          edgeOut,
          insideEdgeKey,
          edgeOutKey,
          &inA,
          &inB,
          &edgeA,
          &edgeB);
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "Et";
    v43 = __rdtsc();
    v44 = (signed __int64)(v42 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v41[1] = v44;
  }
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  return v40;
}

// File Line: 156
// RVA: 0xC13B90
_BOOL8 __fastcall hkaiNavMeshTraversalUtils::Angle::isOriented(hkaiNavMeshTraversalUtils::Angle *this)
{
  return ((this->b > this->c) + (this->a > this->b) + (this->a > this->c)) % 2 == 0;
}

// File Line: 161
// RVA: 0xC13BF0
_BOOL8 __fastcall hkaiNavMeshTraversalUtils::Angle::containsEdge(hkaiNavMeshTraversalUtils::Angle *this, int e, int n)
{
  int v3; // eax
  _BOOL8 result; // rax

  result = 1;
  if ( *(_QWORD *)&this->a != __PAIR__((this->a + 1) % n, e) )
  {
    v3 = this->b;
    if ( v3 != e || this->c != (v3 + 1) % n )
      result = 0;
  }
  return result;
}

// File Line: 167
// RVA: 0xC13C30
char __fastcall hkaiNavMeshTraversalUtils::Angle::sectorContainsEdge(hkaiNavMeshTraversalUtils::Angle *this, int e, int n)
{
  int v3; // er8
  int v5; // eax

  v3 = this->a;
  if ( !this->a )
    return e > this->b;
  v5 = this->b;
  if ( !v5 )
    return e == this->c;
  if ( !this->c )
    return e < v3;
  if ( e == v3 || e == v5 )
    return 0;
  return 1;
}

// File Line: 187
// RVA: 0xC13C80
void __fastcall hkaiNavMeshTraversalUtils::Angle::orient(hkaiNavMeshTraversalUtils::Angle *this)
{
  hkaiNavMeshTraversalUtils::Angle *v1; // rbx
  int v2; // edx

  v1 = this;
  if ( !(unsigned int)hkaiNavMeshTraversalUtils::Angle::isOriented(this) )
  {
    v2 = v1->a;
    v1->a = v1->c;
    v1->c = v2;
  }
}

// File Line: 195
// RVA: 0xC13CB0
void __fastcall hkaiNavMeshTraversalUtils::Angle::fromEdgePair(hkaiNavMeshTraversalUtils::Angle *this, int x, int y, int z, int w)
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
  int v1; // edx
  int v3; // eax

  v1 = this->a;
  if ( !this->a )
    return (unsigned int)(this->b + 2 * this->b - 3);
  if ( this->b )
  {
    v3 = 2 * v1 - 1;
  }
  else
  {
    v1 = this->c;
    v3 = 2 * v1 - 2;
  }
  return (unsigned int)(v1 + v3);
}

// File Line: 244
// RVA: 0xC13D30
void __fastcall hkaiNavMeshTraversalUtils::Angle::rotate(hkaiNavMeshTraversalUtils::Angle *this)
{
  int v1; // edx
  int v2; // eax

  v1 = this->a;
  this->a = this->b;
  v2 = this->c;
  this->c = v1;
  this->b = v2;
}

// File Line: 255
// RVA: 0xC17D60
__int64 __fastcall checkPath_AddToArray_(int n, int x, int y, AddToArray pred)
{
  int v4; // edi
  int v5; // er10
  int v6; // esi
  signed int v7; // ebx
  int v8; // er8
  hkaiNavMeshTraversalUtils::Angle *v9; // r8
  int v10; // edx
  hkaiNavMeshTraversalUtils::Angle *v11; // r8
  hkaiNavMeshTraversalUtils::Angle v13; // [rsp+30h] [rbp-18h]
  hkArrayBase<hkaiNavMeshTraversalUtils::Angle> *v14; // [rsp+68h] [rbp+20h]

  v14 = pred.m_array;
  v4 = y;
  v5 = x;
  v6 = n;
  if ( n == 3 )
  {
    hkaiNavMeshTraversalUtils::Angle::fromEdgePair(&v13, x, (x + 1) % 3, y, (y + 1) % 3);
LABEL_13:
    v11 = &v14->m_data[v14->m_size];
    if ( v11 )
    {
      v11->a = v13.a;
      v11->b = v13.b;
      v11->c = v13.c;
    }
    ++v14->m_size;
    return 0i64;
  }
  if ( x > y )
  {
    v4 = x;
    v5 = y;
  }
  v7 = (v5 + 1) % n;
  v8 = (v5 + 1) % n;
  if ( !v5 )
    v7 = 2;
  do
  {
    hkaiNavMeshTraversalUtils::Angle::fromEdgePair(&v13, v5, v8, v7, 0);
    v9 = &v14->m_data[v14->m_size];
    if ( v9 )
    {
      v9->a = v13.a;
      v9->b = v13.b;
      v9->c = v13.c;
    }
    ++v14->m_size;
    v5 = v7;
    v8 = 0;
    v10 = (v7 + 1) % v6;
    v7 = v10;
  }
  while ( v10 && v10 <= v4 );
  if ( v4 != v6 - 1 )
  {
    hkaiNavMeshTraversalUtils::Angle::fromEdgePair(&v13, v5, 0, v4, (v4 + 1) % v6);
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
  hkaiNavMeshInstance *v4; // rbx
  hkVector4f *v5; // rdi
  __int64 v6; // rcx
  signed int v7; // eax
  __m128 *v8; // rax

  v4 = accessor->m_accessor;
  v5 = vecOut;
  v6 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
         v4->m_originalEdges,
         v4->m_numOriginalEdges,
         &v4->m_instancedEdges,
         &v4->m_ownedEdges,
         &v4->m_edgeMap,
         index + face->m_startEdgeIndex)->m_a;
  v7 = v4->m_numOriginalVertices;
  if ( (signed int)v6 >= v7 )
    v8 = &v4->m_ownedVertices.m_data[(signed int)v6 - v7].m_quad;
  else
    v8 = &v4->m_originalVertices[v6].m_quad;
  v5->m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(*v8, *v8, 85), v4->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(*v8, *v8, 0), v4->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(*v8, *v8, 170), v4->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                 v4->m_referenceFrame.m_transform.m_translation.m_quad);
}

// File Line: 334
// RVA: 0xC17A40
signed __int64 __fastcall findTriangle(hkaiGeneralAccessor *accessor, hkaiNavMesh::Face *face, hkVector4f *up, hkVector4f *point)
{
  hkVector4f *v4; // rdi
  hkVector4f *v5; // r14
  hkaiNavMesh::Face *v6; // rsi
  hkaiGeneralAccessor *v7; // rbp
  int v8; // ebx
  __m128 v9; // xmm6
  __m128 v10; // xmm8
  int v11; // edi
  __m128 v12; // xmm6
  __m128 v13; // xmm9
  __m128 v14; // xmm7
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm2
  hkVector4f vecOut; // [rsp+20h] [rbp-68h]

  v4 = point;
  v5 = up;
  v6 = face;
  v7 = accessor;
  v8 = 2;
  getFaceVertex(accessor, face, 0, &vecOut);
  v9 = v4->m_quad;
  v10 = vecOut.m_quad;
  v11 = v6->m_numEdges - 1;
  v12 = _mm_sub_ps(v9, vecOut.m_quad);
  if ( v11 <= 2 )
    return 1i64;
  v13 = v5->m_quad;
  v14 = _mm_shuffle_ps(v12, v12, 201);
  do
  {
    getFaceVertex(v7, v6, v8, &vecOut);
    v15 = _mm_sub_ps(vecOut.m_quad, v10);
    v16 = _mm_sub_ps(_mm_mul_ps(v14, v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v12));
    v17 = _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v13);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170))) < 0.0 )
      break;
    ++v8;
  }
  while ( v8 < v11 );
  return (unsigned int)(v8 - 1);
}

// File Line: 417
// RVA: 0xC14F10
signed __int64 __usercall hkaiNavMeshTraversalUtils::isEdgePairTraversable@<rax>(hkSimdFloat32 *_diameter@<rcx>, hkaiGeneralAccessor *accessor@<rdx>, unsigned int faceKey@<r8d>, hkaiNavMesh::Face *face@<r9>, __int128 a5@<xmm14>, __int128 a6@<xmm15>, hkVector4f *up, hkaiNavMesh::Edge *insideEdge, hkaiNavMesh::Edge *edgeOut, unsigned int insideEdgeKey, unsigned int edgeOutKey, hkVector4f *inA, hkVector4f *inB, hkVector4f *outA, hkVector4f *outB)
{
  char v15; // r15
  __m128 v16; // xmm6
  int v17; // ebp
  hkaiNavMesh::Face *v18; // r14
  unsigned int v19; // er12
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> **v20; // rdi
  int v21; // er15
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
  int v52; // ecx
  int v53; // edx
  int v54; // er8
  int v56; // esi
  __m128 v57; // xmm7
  int v58; // ebx
  hkaiNavMesh::Edge *v59; // rbx
  __m128 v60; // xmm2
  __m128 v61; // xmm2
  __m128 v62; // xmm2
  __m128 v63; // xmm2
  hkSimdFloat32 maxClearance; // [rsp+30h] [rbp-128h]
  hkSimdFloat32 result; // [rsp+40h] [rbp-118h]
  HasNoClearance pred; // [rsp+50h] [rbp-108h]
  __int128 v67; // [rsp+90h] [rbp-C8h]
  __int128 v68; // [rsp+A0h] [rbp-B8h]
  unsigned int insideEdgea; // [rsp+188h] [rbp+30h]
  unsigned int insideEdgeb; // [rsp+188h] [rbp+30h]

  v15 = insideEdge->m_flags.m_storage;
  v16 = _mm_mul_ps(_diameter->m_real, _diameter->m_real);
  v17 = edgeOut->m_flags.m_storage & 0x10;
  v18 = face;
  v19 = faceKey;
  maxClearance.m_real = v16;
  v20 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> **)accessor;
  v21 = v15 & 0x10;
  if ( v21 || v17 )
  {
    v56 = faceKey >> 22;
    hkaiGeneralAccessor::setSection(accessor, faceKey >> 22);
    v57 = _mm_shuffle_ps((__m128)LODWORD((*v20)[29].m_data), (__m128)LODWORD((*v20)[29].m_data), 0);
    maxClearance.m_real = v57;
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v20, v56);
    insideEdgea = *((signed __int16 *)&(*v20)[27].m_data->m_a + edgeOut->m_a) << 16;
    if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)insideEdgea, (__m128)insideEdgea, 0)) > v57.m128_f32[0] )
      hkaiNavMeshTraversalUtils::computeGlobalClearance(
        &result,
        (hkaiGeneralAccessor *)v20,
        v19,
        edgeOut,
        up,
        &maxClearance);
    v58 = (edgeOutKey & 0x3FFFFF) + 1;
    if ( v58 >= v18->m_startEdgeIndex + v18->m_numEdges )
      v58 = v18->m_startEdgeIndex;
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v20, edgeOutKey >> 22);
    v59 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            (*v20)[2].m_data,
            (*v20)[2].m_size,
            *v20 + 16,
            *v20 + 18,
            (hkArray<int,hkContainerHeapAllocator> *)&(*v20)[13],
            v58);
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v20, v56);
    insideEdgeb = *((signed __int16 *)&(*v20)[27].m_data->m_a + v59->m_a) << 16;
    if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)insideEdgeb, (__m128)insideEdgeb, 0)) > v57.m128_f32[0] )
      hkaiNavMeshTraversalUtils::computeGlobalClearance(
        &result,
        (hkaiGeneralAccessor *)v20,
        v19,
        v59,
        up,
        &maxClearance);
    if ( !v17 )
    {
      v60 = _mm_sub_ps(outA->m_quad, outB->m_quad);
      v61 = _mm_mul_ps(v60, v60);
      return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 170))) >= v16.m128_f32[0];
    }
    if ( !v21 )
    {
      v62 = _mm_sub_ps(inA->m_quad, inB->m_quad);
      v63 = _mm_mul_ps(v62, v62);
      return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                   + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170))) >= v16.m128_f32[0];
    }
  }
  else
  {
    v68 = a5;
    v67 = a6;
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
    v43 = _mm_cmpleps(v35, *(__m128 *)&epsilon);
    v44 = _mm_cmpltps(v42, v35);
    v45 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  v43,
                  _mm_mul_ps(_mm_max_ps(aabbOut.m_quad, _mm_or_ps(_mm_and_ps(v42, v44), _mm_andnot_ps(v44, v35))), v37)),
                _mm_and_ps(v43, query.m_quad)),
              _mm_mul_ps(v39, v26)),
            _mm_mul_ps(v39, v30));
    v46 = _mm_cmpltps(v45, query.m_quad);
    v47 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v45, v46), _mm_andnot_ps(v46, query.m_quad)));
    v48 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v41, v26), v47), _mm_mul_ps(v41, v29));
    v49 = _mm_cmpltps(v48, query.m_quad);
    v50 = _mm_sub_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v48, v49), _mm_andnot_ps(v49, query.m_quad))),
                v22),
              inB->m_quad),
            _mm_add_ps(_mm_mul_ps(v47, v24), outA->m_quad));
    v51 = _mm_mul_ps(v50, v50);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v51, v51, 170))) < maxClearance.m_real.m128_f32[0] )
    {
      _mm_store_si128((__m128i *)&pred.m_diameter2, (__m128i)maxClearance.m_real);
      v52 = face->m_numEdges;
      pred.m_face = face;
      v53 = (insideEdgeKey & 0x3FFFFF) - face->m_startEdgeIndex;
      pred.m_accessor = (hkaiGeneralAccessor *)v20;
      v54 = (edgeOutKey & 0x3FFFFF) - face->m_startEdgeIndex;
      pred.m_faceKey = v19;
      pred.m_up = up;
      return checkPath_HasNoClearance_const_____ptr64_(v52, v53, v54, &pred) == 0;
    }
  }
  return 1i64;
}

// File Line: 495
// RVA: 0xC15480
signed __int64 __fastcall hkaiNavMeshTraversalUtils::isEdgeTraversable(hkSimdFloat32 *diameter, hkaiGeneralAccessor *accessor, unsigned int faceKey, hkaiNavMesh::Face *face, hkVector4f *up, hkaiNavMesh::Edge *startEdge, unsigned int edgeKey, hkVector4f *point)
{
  hkaiNavMesh::Face *v8; // rsi
  unsigned int v9; // er14
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> **v10; // rdi
  __m128 v12; // xmm0
  int v13; // er12
  int v14; // eax
  int v15; // edx
  __m128 v16; // xmm6
  int v17; // er13
  unsigned int v18; // ST40_4
  unsigned int v19; // ST40_4
  int v20; // ebx
  hkArrayBase<hkaiNavMeshTraversalUtils::Angle> *v21; // rax
  LPVOID v22; // rax
  hkLifoAllocator *v23; // r8
  int v24; // edx
  char *v25; // rcx
  int v26; // ebx
  int v27; // eax
  int v28; // er12
  int v29; // ebx
  BOOL v30; // edi
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  float v35; // xmm7_4
  hkaiNavMesh::Edge *v36; // r9
  float v37; // xmm0_4
  float v38; // xmm7_4
  int v39; // ebx
  hkaiNavMesh::Edge *v40; // rbx
  float v41; // xmm0_4
  char *v42; // rsi
  signed int v43; // ebx
  hkLifoAllocator *v44; // rax
  int v45; // er8
  int index; // [rsp+40h] [rbp-99h]
  AddToArray pred; // [rsp+48h] [rbp-91h]
  int v48; // [rsp+50h] [rbp-89h]
  int v49; // [rsp+54h] [rbp-85h]
  void *p; // [rsp+58h] [rbp-81h]
  int v51; // [rsp+60h] [rbp-79h]
  unsigned int v52; // [rsp+68h] [rbp-71h]
  int v53; // [rsp+6Ch] [rbp-6Dh]
  hkSimdFloat32 threshold; // [rsp+70h] [rbp-69h]
  int x; // [rsp+80h] [rbp-59h]
  hkSimdFloat32 maxClearance; // [rsp+90h] [rbp-49h]
  hkVector4f vecOut; // [rsp+A0h] [rbp-39h]
  hkSimdFloat32 result; // [rsp+B0h] [rbp-29h]
  hkSimdFloat32 *v59; // [rsp+120h] [rbp+47h]
  unsigned int startEdgea; // [rsp+148h] [rbp+6Fh]
  unsigned int startEdgeb; // [rsp+148h] [rbp+6Fh]

  v59 = diameter;
  v8 = face;
  v9 = faceKey;
  v10 = (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> **)accessor;
  if ( startEdge->m_flags.m_storage & 0x10 )
    return 1i64;
  v12 = diameter->m_real;
  v53 = face->m_numEdges;
  v13 = faceKey >> 22;
  threshold.m_real = _mm_mul_ps(v12, v12);
  hkaiGeneralAccessor::setSection(accessor, faceKey >> 22);
  v14 = findTriangle((hkaiGeneralAccessor *)v10, v8, up, point);
  v15 = v8->m_startEdgeIndex;
  v12.m128_i32[0] = (int)(*v10)[29].m_data;
  x = v14;
  v16 = _mm_shuffle_ps((__m128)v12.m128_u32[0], (__m128)v12.m128_u32[0], 0);
  v52 = edgeKey & 0x3FFFFF;
  maxClearance.m_real = v16;
  v17 = (edgeKey & 0x3FFFFF) - v15;
  index = (edgeKey & 0x3FFFFF) - 1;
  if ( index < v15 )
    index = v15 + v8->m_numEdges - 1;
  hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, v13);
  vecOut.m_quad.m128_u64[0] = (unsigned __int64)hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                                                  (*v10)[2].m_data,
                                                  (*v10)[2].m_size,
                                                  *v10 + 16,
                                                  *v10 + 18,
                                                  (hkArray<int,hkContainerHeapAllocator> *)&(*v10)[13],
                                                  index);
  hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, v13);
  v18 = *((signed __int16 *)&(*v10)[27].m_data->m_a + startEdge->m_a) << 16;
  if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)v18, (__m128)v18, 0)) > v16.m128_f32[0] )
    hkaiNavMeshTraversalUtils::computeGlobalClearance(
      &result,
      (hkaiGeneralAccessor *)v10,
      v9,
      startEdge,
      up,
      &maxClearance);
  hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, v13);
  v19 = *((signed __int16 *)&(*v10)[27].m_data->m_a + *(signed int *)vecOut.m_quad.m128_u64[0]) << 16;
  if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)v19, (__m128)v19, 0)) > v16.m128_f32[0] )
    hkaiNavMeshTraversalUtils::computeGlobalClearance(
      &result,
      (hkaiGeneralAccessor *)v10,
      v9,
      (hkaiNavMesh::Edge *)vecOut.m_quad.m128_u64[0],
      up,
      &maxClearance);
  v20 = v8->m_numEdges;
  v21 = 0i64;
  v49 = 2147483648;
  pred.m_array = 0i64;
  v48 = 0;
  v51 = v20;
  if ( v20 )
  {
    v22 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v23 = (hkLifoAllocator *)v22;
    v21 = (hkArrayBase<hkaiNavMeshTraversalUtils::Angle> *)*((_QWORD *)v22 + 3);
    v24 = (12 * v20 + 127) & 0xFFFFFF80;
    v25 = (char *)v21 + v24;
    if ( v24 > v23->m_slabSize || v25 > v23->m_end )
      v21 = (hkArrayBase<hkaiNavMeshTraversalUtils::Angle> *)hkLifoAllocator::allocateFromNewSlab(v23, v24);
    else
      v23->m_cur = v25;
  }
  pred.m_array = v21;
  p = v21;
  v49 = v20 | 0x80000000;
  v26 = x;
  if ( x == v17 || (checkPath_AddToArray_(v8->m_numEdges, x, v17, (AddToArray)&pred), v27 = v48, v48 < 2) )
  {
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, v13);
    getFaceVertex((hkaiGeneralAccessor *)v10, v8, v17, (hkVector4f *)&threshold);
    getFaceVertex((hkaiGeneralAccessor *)v10, v8, (v17 + 1) % v53, &vecOut);
    v31 = _mm_sub_ps(threshold.m_real, vecOut.m_quad);
    v32 = _mm_mul_ps(v31, v31);
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170));
    v34 = _mm_rsqrt_ps(v33);
    LODWORD(v35) = (unsigned __int128)_mm_andnot_ps(
                                        _mm_cmpleps(v33, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_mul_ps(
                                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v34), v34)),
                                            _mm_mul_ps(*(__m128 *)_xmm, v34)),
                                          v33));
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, v13);
    v36 = startEdge;
    startEdgea = *((signed __int16 *)&(*v10)[27].m_data->m_a + startEdge->m_a) << 16;
    LODWORD(v37) = (unsigned __int128)_mm_shuffle_ps((__m128)startEdgea, (__m128)startEdgea, 0);
    if ( v37 > v16.m128_f32[0] )
    {
      hkaiNavMeshTraversalUtils::computeGlobalClearance(
        &threshold,
        (hkaiGeneralAccessor *)v10,
        v9,
        v36,
        up,
        &maxClearance);
      LODWORD(v37) = (unsigned __int128)_mm_shuffle_ps(
                                          (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(
                                                                                    threshold.m_real.m128_f32[0]
                                                                                  * 1.0039062) >> 16) << 16),
                                          (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(
                                                                                    threshold.m_real.m128_f32[0]
                                                                                  * 1.0039062) >> 16) << 16),
                                          0);
    }
    v38 = v35 + fmax(v37, 0.0);
    v39 = v52 + 1;
    if ( (signed int)(v52 + 1) >= v8->m_startEdgeIndex + v8->m_numEdges )
      v39 = v8->m_startEdgeIndex;
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, edgeKey >> 22);
    v40 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            (*v10)[2].m_data,
            (*v10)[2].m_size,
            *v10 + 16,
            *v10 + 18,
            (hkArray<int,hkContainerHeapAllocator> *)&(*v10)[13],
            v39);
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, v13);
    startEdgeb = *((signed __int16 *)&(*v10)[27].m_data->m_a + v40->m_a) << 16;
    LODWORD(v41) = (unsigned __int128)_mm_shuffle_ps((__m128)startEdgeb, (__m128)startEdgeb, 0);
    if ( v41 > v16.m128_f32[0] )
    {
      hkaiNavMeshTraversalUtils::computeGlobalClearance(
        &threshold,
        (hkaiGeneralAccessor *)v10,
        v9,
        v40,
        up,
        &maxClearance);
      LODWORD(v41) = (unsigned __int128)_mm_shuffle_ps(
                                          (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(
                                                                                    threshold.m_real.m128_f32[0]
                                                                                  * 1.0039062) >> 16) << 16),
                                          (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(
                                                                                    threshold.m_real.m128_f32[0]
                                                                                  * 1.0039062) >> 16) << 16),
                                          0);
    }
    v30 = (float)(fmax(v41, 0.0) + v38) >= v59->m_real.m128_f32[0];
LABEL_33:
    v27 = v48;
  }
  else
  {
    if ( v26 >= v17 )
      v28 = v48 - 1;
    else
      v28 = 0;
    v29 = 0;
    if ( v48 > 0 )
    {
      do
      {
        if ( v29 != v28 )
        {
          maxClearance.m_real = (__m128)xmmword_141A712A0;
          if ( hkaiNavMeshTraversalUtils::isVertexClearanceForEdgeLessThan(
                 (hkaiGeneralAccessor *)v10,
                 v9,
                 v8,
                 (hkaiNavMeshTraversalUtils::Angle *)pred.m_array + v29,
                 up,
                 &maxClearance,
                 &threshold) )
          {
            v30 = 0;
            goto LABEL_33;
          }
          v27 = v48;
        }
        ++v29;
      }
      while ( v29 < v27 );
    }
    v30 = 1;
  }
  v42 = (char *)p;
  if ( p == pred.m_array )
    v27 = 0;
  v48 = v27;
  v43 = (12 * v51 + 127) & 0xFFFFFF80;
  v44 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v45 = (v43 + 15) & 0xFFFFFFF0;
  if ( v43 > v44->m_slabSize || &v42[v45] != v44->m_cur || v44->m_firstNonLifoEnd == v42 )
    hkLifoAllocator::slowBlockFree(v44, v42, v45);
  else
    v44->m_cur = v42;
  v48 = 0;
  if ( v49 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      pred.m_array,
      12 * (v49 & 0x3FFFFFFF));
  return (unsigned int)v30;
}

// File Line: 595
// RVA: 0xC15A50
hkSimdFloat32 *__fastcall hkaiNavMeshTraversalUtils::computeGlobalClearance(hkSimdFloat32 *result, hkaiGeneralAccessor *accessor, unsigned int startFaceKey, hkaiNavMesh::Edge *startEdge)
{
  hkaiNavMesh::Edge *v4; // r13
  unsigned int v5; // ebx
  hkaiGeneralAccessor *v6; // r12
  hkSimdFloat32 *v7; // r14
  __m128 v8; // xmm0
  __m128 v9; // xmm9
  __m128 *v10; // rcx
  __int64 v11; // rax
  signed int v12; // edx
  __m128 *v13; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm10
  __m128 v16; // xmm1
  __m128 v17; // xmm11
  hkLifoAllocator *v18; // rax
  char *v19; // rcx
  unsigned __int64 v20; // rdx
  hkLifoAllocator *v21; // rax
  char *v22; // rcx
  unsigned __int64 v23; // rdx
  int v24; // eax
  _DWORD *v25; // r15
  bool v26; // zf
  int v27; // esi
  unsigned int v28; // ebx
  hkaiNavMesh::Face *v29; // rax
  hkaiNavMesh::Face *v30; // r14
  int v31; // edi
  hkaiNavMeshInstance *v32; // rbx
  hkaiNavMesh::Edge *v33; // rax
  signed int v34; // edx
  __int64 v35; // r9
  hkaiNavMesh::Edge *v36; // r8
  __m128 *v37; // rcx
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __int64 v41; // rcx
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
  char v68; // al
  unsigned int v69; // ecx
  unsigned int v70; // eax
  unsigned int v71; // ebx
  signed __int64 v72; // rax
  int v73; // ecx
  int v74; // edx
  __m128 v75; // xmm3
  int v76; // eax
  char *v77; // rdi
  signed int v78; // ebx
  hkLifoAllocator *v79; // rax
  int v80; // er8
  int v81; // eax
  char *v82; // rdi
  signed int v83; // ebx
  hkLifoAllocator *v84; // rax
  int v85; // er8
  int index[2]; // [rsp+28h] [rbp-79h]
  signed __int64 array; // [rsp+30h] [rbp-71h]
  void *p; // [rsp+38h] [rbp-69h]
  void *v90; // [rsp+40h] [rbp-61h]
  int v91; // [rsp+48h] [rbp-59h]
  __m128 *v92; // [rsp+F8h] [rbp+57h]
  __m128 *retaddr; // [rsp+118h] [rbp+77h]
  int v94; // [rsp+120h] [rbp+7Fh]

  v4 = startEdge;
  v5 = startFaceKey;
  v6 = accessor;
  v7 = result;
  v8 = result->m_real;
  _mm_store_si128((__m128i *)result, (__m128i)result->m_real);
  if ( startEdge->m_oppositeEdge == -1 || startEdge->m_flags.m_storage & 0x20 )
  {
    *result = (hkSimdFloat32)g_vectorfConstants[0];
    goto $outputClearance;
  }
  v9 = _mm_mul_ps(v8, v8);
  hkaiGeneralAccessor::setSection(accessor, startFaceKey >> 22);
  v10 = (__m128 *)v6->m_accessor;
  v94 = v6->m_currentSection;
  v11 = v4->m_a;
  v12 = v6->m_accessor->m_numOriginalVertices;
  if ( (signed int)v11 >= v12 )
    v13 = (__m128 *)(v10[19].m128_u64[0] + 16i64 * ((signed int)v11 - v12));
  else
    v13 = (__m128 *)(v10[3].m128_u64[0] + 16 * v11);
  v14 = *v13;
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v10[8]),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v10[7])),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v10[9])),
          v10[10]);
  array = 0i64;
  p = (void *)0x8000000000000000i64;
  v91 = 64;
  v16 = _mm_mul_ps(v15, *retaddr);
  v17 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v16, v16, 85), _mm_shuffle_ps(v16, v16, 0)), _mm_shuffle_ps(v16, v16, 170));
  v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (char *)v18->m_cur;
  v20 = (unsigned __int64)(v19 + 256);
  if ( v18->m_slabSize < 256 || (void *)v20 > v18->m_end )
    v19 = (char *)hkLifoAllocator::allocateFromNewSlab(v18, 256);
  else
    v18->m_cur = (void *)v20;
  v90 = v19;
  HIDWORD(p) = -2147483584;
  *(_QWORD *)index = 0i64;
  array = 0x8000000000000000i64;
  LODWORD(v90) = 64;
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (char *)v21->m_cur;
  v23 = (unsigned __int64)(v22 + 256);
  if ( v21->m_slabSize < 256 || (void *)v23 > v21->m_end )
    v22 = (char *)hkLifoAllocator::allocateFromNewSlab(v21, 256);
  else
    v21->m_cur = (void *)v23;
  v24 = HIDWORD(p);
  *(_QWORD *)index = v22;
  p = v22;
  HIDWORD(array) = -2147483584;
  if ( (_DWORD)v22 == (v24 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
    LODWORD(v22) = (_DWORD)p;
  }
  *(_DWORD *)(array + 4i64 * (signed int)v22) = v5;
  v25 = *(_DWORD **)index;
  v26 = (_DWORD)p == -1;
  v27 = (_DWORD)p + 1;
  LODWORD(p) = (_DWORD)p + 1;
  if ( v26 )
  {
LABEL_59:
    v75 = _mm_rsqrt_ps(v9);
    v7->m_real = _mm_andnot_ps(
                   _mm_cmpleps(v9, (__m128)0i64),
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
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, index, 4);
      v25 = *(_DWORD **)index;
    }
    v25[(signed int)array] = v28;
    LODWORD(array) = array + 1;
    v29 = hkaiGeneralAccessor::getFaceFromPacked(v6, v28);
    v30 = v29;
    v31 = v29->m_numUserEdges <= 0 ? v29->m_startEdgeIndex : v29->m_startUserEdgeIndex;
    v27 = (signed int)p;
    v25 = *(_DWORD **)index;
    if ( v31 != -1 )
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
    v32 = v6->m_accessor;
    index[0] = v31;
    v33 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            v32->m_originalEdges,
            v32->m_numOriginalEdges,
            &v32->m_instancedEdges,
            &v32->m_ownedEdges,
            &v32->m_edgeMap,
            v31);
    v34 = v32->m_numOriginalVertices;
    v35 = v33->m_a;
    v36 = v33;
    v37 = (__m128 *)((signed int)v35 >= v34 ? &v32->m_ownedVertices.m_data[(signed int)v35 - v34] : &v32->m_originalVertices[v35]);
    v38 = *v37;
    v39 = v32->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
    v40 = v32->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
    v41 = v33->m_b;
    v42 = v32->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
    v43 = v32->m_referenceFrame.m_transform.m_translation.m_quad;
    v44 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), v40), _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), v39)),
              _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), v42)),
            v43);
    v45 = (__m128 *)((signed int)v41 >= v34 ? &v32->m_ownedVertices.m_data[(signed int)v41 - v34] : &v32->m_originalVertices[v41]);
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
    v60 = _mm_cmpltps(v59, query.m_quad);
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
    v68 = v36->m_flags.m_storage;
    if ( v68 & 0x20 )
      break;
    if ( v67.m128_f32[0] <= v9.m128_f32[0] )
    {
      v69 = v36->m_oppositeFace;
      if ( v68 & 0x40 )
        v70 = v69 & 0xFFC00000;
      else
        v70 = v32->m_runtimeId << 22;
      v71 = v70 | v69 & 0x3FFFFF;
      if ( v69 == -1 )
        v71 = -1;
      v72 = 0i64;
      v73 = 0;
      if ( (signed int)array <= 0i64 )
        goto LABEL_42;
      while ( v25[v72] != v71 )
      {
        ++v72;
        ++v73;
        if ( v72 >= (signed int)array )
          goto LABEL_42;
      }
      if ( v73 == -1 )
      {
LABEL_42:
        if ( v71 >> 22 == v94 )
        {
          if ( v27 == (HIDWORD(p) & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
            v27 = (signed int)p;
          }
          *(_DWORD *)(array + 4i64 * v27) = v71;
          v25 = *(_DWORD **)index;
          v27 = (_DWORD)p + 1;
          LODWORD(p) = (_DWORD)p + 1;
        }
      }
    }
LABEL_49:
    v74 = v30->m_startUserEdgeIndex;
    if ( v31 >= v74 && v31 < v30->m_numUserEdges + v74 - 1 )
      goto LABEL_55;
    if ( v31 != v30->m_numUserEdges + v74 - 1 )
    {
      if ( v31 < v30->m_startEdgeIndex || v31 >= v30->m_numEdges + v30->m_startEdgeIndex - 1 )
        goto LABEL_57;
LABEL_55:
      ++v31;
      goto LABEL_56;
    }
    v31 = v30->m_startEdgeIndex;
LABEL_56:
    if ( v31 == -1 )
      goto LABEL_57;
  }
  if ( (_DWORD)v35 != v4->m_a && (_DWORD)v41 != v4->m_a )
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
  if ( array >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *(void **)index,
      4 * HIDWORD(array));
  v81 = (signed int)p;
  v82 = (char *)v90;
  v26 = v90 == (void *)array;
  *(_QWORD *)index = 0i64;
  HIDWORD(array) = 2147483648;
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)array,
      4 * HIDWORD(p));
$outputClearance:
  hkaiNavMeshTraversalUtils::updateGlobalClearance(v6, v4->m_a, v7);
  return v7;
}

// File Line: 686
// RVA: 0xC163F0
hkSimdFloat32 *__fastcall hkaiNavMeshTraversalUtils::computeVertexClearance(hkSimdFloat32 *result, hkaiGeneralAccessor *accessor, unsigned int faceKey, hkaiNavMesh::Face *currentFace)
{
  hkaiGeneralAccessor *v4; // r15
  unsigned int v5; // esi
  hkaiNavMesh::Face *v6; // rax
  hkaiNavMeshInstance *v7; // rdi
  int v8; // er13
  hkaiNavMeshTraversalUtils::Angle *v9; // r15
  int v10; // eax
  int *v11; // rcx
  signed int v12; // er12
  int v13; // eax
  signed __int64 v14; // rsi
  __m128 *v15; // r14
  unsigned int *v16; // rbx
  hkaiNavMesh::Edge *v17; // rax
  char v18; // cl
  __int64 v19; // rax
  __m128 *v20; // rax
  __m128 v21; // xmm15
  hkVector4f *v22; // rdi
  __m128 v23; // xmm1
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
  char *v46; // rcx
  unsigned __int64 v47; // rdx
  hkLifoAllocator *v48; // rax
  char *v49; // rcx
  unsigned __int64 v50; // rdx
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
  signed __int64 v67; // rcx
  _DWORD *v68; // rax
  int v69; // edx
  unsigned int v70; // xmm0_4
  int v71; // xmm1_4
  float v72; // xmm6_4
  unsigned int v73; // ebx
  hkaiNavMesh::Face *v74; // rax
  int index; // er13
  int v76; // ecx
  int v77; // eax
  unsigned int v78; // er14
  hkaiNavMeshInstance *v79; // rbx
  hkaiNavMesh::Edge *v80; // rdi
  unsigned int v81; // ecx
  char v82; // dl
  unsigned int v83; // eax
  __m128 v84; // xmm2
  __m128 v85; // xmm8
  int v86; // esi
  unsigned int v87; // ecx
  unsigned int v88; // eax
  signed int v89; // edx
  __int64 v90; // r8
  unsigned int v91; // er12
  __int64 v92; // rcx
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
  unsigned int v118; // er8
  hkSimdFloat32 *v119; // rsi
  int v120; // eax
  char *v121; // rdi
  signed int v122; // ebx
  hkLifoAllocator *v123; // rax
  int v124; // er8
  __m128 v125; // xmm2
  __m128 v126; // xmm1
  __m128 v127; // xmm2
  __m128 v128; // xmm1
  __m128 v129; // xmm3
  __m128 v130; // xmm3
  int v131; // edx
  signed __int64 v132; // rcx
  int v133; // edx
  signed __int64 v134; // rcx
  _DWORD *v135; // rax
  int v136; // eax
  char *v137; // rdi
  signed int v138; // ebx
  hkLifoAllocator *v139; // rax
  int v140; // er8
  _DWORD *array; // [rsp+40h] [rbp-88h]
  int v143; // [rsp+48h] [rbp-80h]
  int v144; // [rsp+4Ch] [rbp-7Ch]
  unsigned int faceKeya[2]; // [rsp+50h] [rbp-78h]
  int v146; // [rsp+58h] [rbp-70h]
  _DWORD *v147; // [rsp+60h] [rbp-68h]
  hkSimdFloat32 value; // [rsp+68h] [rbp-60h]
  hkSimdFloat32 resulta; // [rsp+78h] [rbp-50h]
  float v150; // [rsp+88h] [rbp-40h]
  int section; // [rsp+8Ch] [rbp-3Ch]
  unsigned int v152; // [rsp+90h] [rbp-38h]
  unsigned int v153; // [rsp+94h] [rbp-34h]
  unsigned int v154; // [rsp+98h] [rbp-30h]
  unsigned int v155; // [rsp+9Ch] [rbp-2Ch]
  float v156; // [rsp+A0h] [rbp-28h]
  hkaiNavMesh::Edge v157; // [rsp+A8h] [rbp-20h]
  hkaiNavMesh::Edge edge; // [rsp+BCh] [rbp-Ch]
  hkaiNavMesh::Edge startEdge; // [rsp+D0h] [rbp+8h]
  hkaiNavMesh::Face *v160; // [rsp+E8h] [rbp+20h]
  hkSimdFloat32 maxClearance; // [rsp+F8h] [rbp+30h]
  hkVector4f A; // [rsp+108h] [rbp+40h]
  hkVector4f edgePlane2; // [rsp+118h] [rbp+50h]
  hkVector4f edgePlane1; // [rsp+128h] [rbp+60h]
  hkSimdFloat32 v165; // [rsp+138h] [rbp+70h]
  hkSimdFloat32 v166; // [rsp+148h] [rbp+80h]
  hkVector4f vertex; // [rsp+158h] [rbp+90h]
  __m128 v168; // [rsp+168h] [rbp+A0h]
  __m128i v169; // [rsp+178h] [rbp+B0h]
  __m128 v170; // [rsp+188h] [rbp+C0h]
  hkSimdFloat32 *v171; // [rsp+278h] [rbp+1B0h]
  hkaiGeneralAccessor *accessora; // [rsp+280h] [rbp+1B8h]
  unsigned int startFaceKey; // [rsp+288h] [rbp+1C0h]
  hkaiNavMeshTraversalUtils::Angle *v174; // [rsp+298h] [rbp+1D0h]
  hkVector4f *vars0; // [rsp+2A0h] [rbp+1D8h]
  __m128 *retaddr; // [rsp+2A8h] [rbp+1E0h]

  v4 = accessor;
  v5 = faceKey;
  v6 = hkaiGeneralAccessor::getFaceFromPacked(accessor, faceKey);
  v7 = v4->m_accessor;
  v8 = v6->m_startEdgeIndex;
  LODWORD(v6) = v4->m_currentSection;
  v9 = v174;
  LODWORD(v147) = (_DWORD)v6;
  v10 = hkaiNavMeshTraversalUtils::Angle::index(v174);
  v11 = v7->m_faceClearanceIndices.m_data;
  v12 = v7->m_numOriginalVertices;
  *(_QWORD *)&v157.m_oppositeEdge = -1i64;
  *(_DWORD *)&v157.m_flags.m_storage = 4;
  *(_QWORD *)&edge.m_oppositeEdge = -1i64;
  *(_DWORD *)&edge.m_flags.m_storage = 4;
  v13 = v11[v5 & 0x3FFFFF] + v10;
  *(_QWORD *)&startEdge.m_oppositeEdge = -1i64;
  *(_DWORD *)&startEdge.m_flags.m_storage = 4;
  v14 = 0i64;
  v15 = &v168;
  v16 = &v157.m_oppositeEdge;
  v143 = v13;
  do
  {
    v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            v7->m_originalEdges,
            v7->m_numOriginalEdges,
            &v7->m_instancedEdges,
            &v7->m_ownedEdges,
            &v7->m_edgeMap,
            v8 + *(&v9->a + v14));
    *(v16 - 2) = v17->m_a;
    *(v16 - 1) = v17->m_b;
    *v16 = v17->m_oppositeEdge;
    v16[1] = v17->m_oppositeFace;
    *((_BYTE *)v16 + 8) = v17->m_flags.m_storage;
    v18 = v17->m_paddingByte;
    LOWORD(v17) = v17->m_userEdgeCost.m_value;
    *((_BYTE *)v16 + 9) = v18;
    *((_WORD *)v16 + 5) = (_WORD)v17;
    v19 = (signed int)*(v16 - 2);
    if ( (signed int)v19 >= v12 )
      v20 = &v7->m_ownedVertices.m_data[(signed int)v19 - v12].m_quad;
    else
      v20 = &v7->m_originalVertices[v19].m_quad;
    ++v14;
    ++v15;
    v16 += 5;
    v15[-1] = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(*v20, *v20, 85),
                      v7->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(*v20, *v20, 0), v7->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(*v20, *v20, 170), v7->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                v7->m_referenceFrame.m_transform.m_translation.m_quad);
  }
  while ( v14 < 3 );
  v21 = (__m128)v169;
  v22 = vars0;
  v23 = vars0->m_quad;
  v24 = _mm_sub_ps(v168, (__m128)v169);
  v25 = _mm_sub_ps(v170, v168);
  v26 = _mm_shuffle_ps(v23, v23, 201);
  v27 = _mm_sub_ps(v170, (__m128)v169);
  _mm_store_si128((__m128i *)&vertex, v169);
  v28 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v23), _mm_mul_ps(v26, v24));
  v29 = _mm_shuffle_ps(v28, v28, 201);
  v30 = _mm_sub_ps(_mm_mul_ps(v26, v27), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v23));
  v31 = _mm_mul_ps(v29, v29);
  v32 = _mm_shuffle_ps(v30, v30, 201);
  v33 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)), _mm_shuffle_ps(v31, v31, 170));
  v34 = _mm_rsqrt_ps(v33);
  v35 = _mm_mul_ps(
          v29,
          _mm_andnot_ps(
            _mm_cmpleps(v33, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
              _mm_mul_ps(*(__m128 *)_xmm, v34))));
  v36 = _mm_mul_ps(v32, v32);
  v37 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)), _mm_shuffle_ps(v36, v36, 170));
  v38 = _mm_rsqrt_ps(v37);
  v39 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)), _mm_mul_ps(*(__m128 *)_xmm, v38));
  v40 = _mm_mul_ps(v35, v21);
  v41 = _mm_mul_ps(v32, _mm_andnot_ps(_mm_cmpleps(v37, (__m128)0i64), v39));
  v144 = 2147483648;
  v146 = 64;
  v42 = _mm_sub_ps(
          (__m128)0i64,
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
            _mm_shuffle_ps(v40, v40, 170)));
  v43 = _mm_mul_ps(v41, v21);
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
  v46 = (char *)v44->m_cur;
  v47 = (unsigned __int64)(v46 + 768);
  if ( v44->m_slabSize < 768 || (void *)v47 > v44->m_end )
    v46 = (char *)hkLifoAllocator::allocateFromNewSlab(v44, 768);
  else
    v44->m_cur = (void *)v47;
  array = v46;
  *(_QWORD *)faceKeya = v46;
  v144 = -2147483584;
  v147 = 0i64;
  value.m_real.m128_u64[0] = 0x8000000000000000i64;
  resulta.m_real.m128_i32[0] = 64;
  v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v49 = (char *)v48->m_cur;
  v50 = (unsigned __int64)(v49 + 256);
  if ( v48->m_slabSize < 256 || (void *)v50 > v48->m_end )
    v49 = (char *)hkLifoAllocator::allocateFromNewSlab(v48, 256);
  else
    v48->m_cur = (void *)v50;
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
          _mm_cmpleps(v55, (__m128)0i64),
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
          _mm_cmpleps(v59, (__m128)0i64),
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
    LODWORD(accessora) = (signed __int16)(COERCE_UNSIGNED_INT(resulta.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
    v63 = _mm_shuffle_ps((__m128)(unsigned int)accessora, (__m128)(unsigned int)accessora, 0);
  }
  hkaiGeneralAccessor::setSection(v45, v54);
  LODWORD(accessora) = v45->m_accessor->m_globalClearanceCache.m_data[v157.m_a].m_value << 16;
  v64 = _mm_shuffle_ps((__m128)(unsigned int)accessora, (__m128)(unsigned int)accessora, 0);
  if ( v64.m128_f32[0] > v61.m128_f32[0] )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(&resulta, v45, v52, &v157);
    LODWORD(accessora) = (signed __int16)(COERCE_UNSIGNED_INT(resulta.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
    v64 = _mm_shuffle_ps((__m128)(unsigned int)accessora, (__m128)(unsigned int)accessora, 0);
  }
  if ( v63.m128_f32[0] < 0.0 )
  {
    v84 = _mm_mul_ps(v25, v27);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v84, v84, 170))) <= 0.0 )
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
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v85, v85, 170))) >= 0.0 )
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
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 12);
    v65 = v143;
  }
  v67 = 3i64 * v65;
  v68 = array;
  v143 = v65 + 1;
  array[v67] = 0;
  v68[v67 + 1] = v52;
  v68[v67 + 2] = -1;
  v69 = v143;
  if ( v143 )
  {
    do
    {
      v70 = array[3 * v69 - 2];
      v71 = array[3 * v69 - 1];
      v72 = *(float *)&array[3 * v69 - 3];
      v143 = v69 - 1;
      faceKeya[1] = v70;
      v146 = v71;
      if ( value.m_real.m128_i32[0] == (value.m_real.m128_i32[1] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v147, 4);
      v73 = faceKeya[1];
      v147[value.m_real.m128_i32[0]] = faceKeya[1];
      ++value.m_real.m128_i32[0];
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
            || (LOBYTE(v77) = hkaiNavMeshTraversalUtils::Angle::sectorContainsEdge(
                                v174,
                                index - v74->m_startEdgeIndex,
                                v74->m_numEdges),
                v76 = (signed int)accessora,
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
              v81 = v80->m_oppositeFace;
              v82 = v80->m_flags.m_storage & 0x40;
              if ( v82 )
                v83 = v81 & 0xFFC00000;
              else
                v83 = v79->m_runtimeId << 22;
              v86 = v83 | v81 & 0x3FFFFF;
              v116 = v81 == -1;
              v87 = v80->m_oppositeEdge;
              if ( v116 )
                v86 = -1;
              if ( v82 )
                v88 = v87 & 0xFFC00000;
              else
                v88 = v79->m_runtimeId << 22;
              v89 = v79->m_numOriginalVertices;
              v90 = v80->m_b;
              v91 = v88 | v87 & 0x3FFFFF;
              v116 = v87 == -1;
              v92 = v80->m_a;
              if ( v116 )
                v91 = -1;
              if ( (signed int)v92 >= v89 )
                v93 = &v79->m_ownedVertices.m_data[(signed int)v92 - v89].m_quad;
              else
                v93 = &v79->m_originalVertices[v92].m_quad;
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
              if ( (signed int)v90 >= v89 )
                v99 = &v79->m_ownedVertices.m_data[(signed int)v90 - v89].m_quad;
              else
                v99 = &v79->m_originalVertices[v90].m_quad;
              v100 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(*v99, *v99, 0), v95),
                           _mm_mul_ps(_mm_shuffle_ps(*v99, *v99, 85), v94)),
                         _mm_mul_ps(_mm_shuffle_ps(*v99, *v99, 170), v96)),
                       v97);
              if ( v45->m_currentSection == (_DWORD)v147 && ((_DWORD)v92 == edge.m_a || (_DWORD)v90 == edge.m_a) )
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
                  v153 = (signed __int16)(COERCE_UNSIGNED_INT(v165.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
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
                  v152 = (signed __int16)(COERCE_UNSIGNED_INT(v166.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
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
                    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v113, v113, 85))
                                       + COERCE_FLOAT(_mm_shuffle_ps(v113, v113, 0)))
                               + COERCE_FLOAT(_mm_shuffle_ps(v113, v113, 170))) > 0.0 )
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
                      if ( v80->m_oppositeEdge == -1 || v80->m_flags.m_storage & 0x20 )
                      {
                        v66 = _mm_min_ps(v66, v117);
                        value.m_real = v66;
                      }
LABEL_82:
                      if ( v117.m128_f32[0] < v66.m128_f32[0]
                        && v80->m_oppositeEdge != -1
                        && !(v80->m_flags.m_storage & 0x20) )
                      {
                        v131 = 0;
                        v132 = 0i64;
                        if ( value.m_real.m128_i32[0] <= 0i64 )
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
                              hkArrayUtil::_reserveMore(
                                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                                &array,
                                12);
                              v133 = v143;
                            }
                            v134 = 3i64 * v133;
                            v135 = array;
                            v143 = v133 + 1;
                            array[v134 + 1] = v86;
                            v135[v134 + 2] = v91;
                            v135[v134] = v117.m128_i32[0];
                          }
                        }
                      }
                      v76 = (signed int)accessora;
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
              v76 = (signed int)accessora;
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v147,
      4 * value.m_real.m128_i32[1]);
  v136 = v143;
  v137 = *(char **)faceKeya;
  v147 = 0i64;
  value.m_real.m128_i32[1] = 2147483648;
  if ( *(_DWORD **)faceKeya == array )
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
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      12 * (v144 & 0x3FFFFFFF));
  return v119;
}

// File Line: 935
// RVA: 0xC17320
__m128i *__fastcall hkaiNavMeshTraversalUtils::updateClearance(hkSimdFloat32 *result, hkaiGeneralAccessor *accessor, unsigned int faceKey, hkaiNavMesh::Edge *edge, hkVector4f *up, int index, hkSimdFloat32 *value)
{
  hkaiGeneralAccessor *v7; // rsi
  __m128i *v8; // rdi
  int v9; // ebx
  hkaiNavMesh::Edge *v10; // rbp
  unsigned int v11; // er14
  __m128 v12; // xmm5
  __m128 v13; // xmm1
  __m128 v14; // xmm4
  __m128i *v15; // rax
  hkSimdFloat32 v16; // [rsp+30h] [rbp-48h]
  hkSimdFloat32 resulta; // [rsp+40h] [rbp-38h]
  unsigned int v18; // [rsp+90h] [rbp+18h]
  float v19; // [rsp+90h] [rbp+18h]

  v7 = accessor;
  v8 = (__m128i *)result;
  v9 = faceKey >> 22;
  v10 = edge;
  v11 = faceKey;
  hkaiGeneralAccessor::setSection(accessor, faceKey >> 22);
  v16.m_real = _mm_shuffle_ps(
                 (__m128)LODWORD(v7->m_accessor->m_maxGlobalClearance),
                 (__m128)LODWORD(v7->m_accessor->m_maxGlobalClearance),
                 0);
  _mm_store_si128(v8, (__m128i)value->m_real);
  hkaiGeneralAccessor::setSection(v7, v9);
  v18 = v7->m_accessor->m_globalClearanceCache.m_data[v10->m_a].m_value << 16;
  v12 = _mm_shuffle_ps((__m128)v18, (__m128)v18, 0);
  if ( v12.m128_f32[0] > v16.m_real.m128_f32[0] )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(&resulta, v7, v11, v10);
    v12 = _mm_shuffle_ps(
            (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(resulta.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
            (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(resulta.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
            0);
  }
  if ( v12.m128_f32[0] >= 0.0 )
  {
    v13 = _mm_rsqrt_ps(*(__m128 *)v8);
    v14 = _mm_add_ps(
            _mm_andnot_ps(
              _mm_cmpleps(*(__m128 *)v8, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(*(__m128 *)v8, v13), v13)),
                  _mm_mul_ps(*(__m128 *)_xmm, v13)),
                *(__m128 *)v8)),
            v12);
    *(__m128 *)v8 = _mm_mul_ps(v14, v14);
  }
  v15 = v8;
  v19 = COERCE_FLOAT(*v8) * 1.0039062;
  v7->m_accessor->m_clearanceCache.m_data[index].m_value = HIWORD(v19);
  return v15;
}

// File Line: 968
// RVA: 0xC17510
void __fastcall hkaiNavMeshTraversalUtils::updateGlobalClearance(hkaiGeneralAccessor *accessor, int vertexIndex, hkSimdFloat32 *clearance)
{
  float v3; // [rsp+10h] [rbp+10h]

  v3 = COERCE_FLOAT(*clearance) * 1.0039062;
  accessor->m_accessor->m_globalClearanceCache.m_data[vertexIndex].m_value = HIWORD(v3);
}

// File Line: 980
// RVA: 0xC174D0
void __fastcall hkaiNavMeshTraversalUtils::updateGlobalClearance(hkaiNavMeshInstance *meshInstance, int vertexIndex, hkSimdFloat32 *clearance)
{
  float v3; // [rsp+10h] [rbp+10h]

  v3 = COERCE_FLOAT(*clearance) * 1.0039062;
  meshInstance->m_globalClearanceCache.m_data[vertexIndex].m_value = HIWORD(v3);
}

// File Line: 985
// RVA: 0xC13D50
void __fastcall hkaiNavMeshTraversalUtils::resetClearanceForFace(hkaiNavMeshInstance *meshInstance, int faceIndex, bool resetEdgeClearance, bool resetGlobalClearance)
{
  __int64 v4; // rsi
  bool v5; // bp
  hkaiNavMeshInstance *v6; // rbx
  int *v7; // rax
  int index; // edi
  int v9; // ST34_4
  int v10; // ecx
  int v11; // ST3C_4
  __int16 v12; // r8
  char v13; // r11
  __int64 v14; // rdx
  __int64 v15; // rax
  __int64 i; // rdx
  int v17; // esi
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v18; // r9
  hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *v19; // r8
  hkaiNavMesh::Edge *v20; // rax

  v4 = faceIndex;
  v5 = resetGlobalClearance;
  v6 = meshInstance;
  v7 = (int *)hkaiNavMeshInstance_get_hkaiNavMesh::Face__13(
                meshInstance->m_originalFaces,
                meshInstance->m_numOriginalFaces,
                &meshInstance->m_instancedFaces,
                &meshInstance->m_ownedFaces,
                &meshInstance->m_faceMap,
                faceIndex);
  index = *v7;
  v9 = v7[1];
  v10 = v7[2];
  v11 = v7[3];
  v12 = v7[2];
  if ( v13 )
  {
    v14 = v6->m_faceClearanceIndices.m_data[v4];
    v15 = v14;
    for ( i = (signed int)v14 + 3 * ((signed __int16)v10 - 2);
          v15 < i;
          v6->m_clearanceCache.m_data[v15 - 1].m_value = -16512 )
    {
      ++v15;
    }
  }
  if ( v5 )
  {
    v17 = index + v12;
    if ( index < v17 )
    {
      v18 = &v6->m_ownedEdges;
      v19 = &v6->m_instancedEdges;
      do
      {
        v20 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                v6->m_originalEdges,
                v6->m_numOriginalEdges,
                v19,
                v18,
                &v6->m_edgeMap,
                index++);
        v6->m_globalClearanceCache.m_data[v20->m_a].m_value = 32639;
      }
      while ( index < v17 );
    }
  }
}

// File Line: 1025
// RVA: 0xC14A90
void __fastcall hkaiNavMeshTraversalUtils::getVertexClearanceForEdge(hkaiGeneralAccessor *accessor, unsigned int faceKey, hkaiNavMesh::Face *currentFace, hkaiNavMeshTraversalUtils::Angle *angle, hkVector4f *up, hkSimdFloat32 *maxRadius, hkaiNavMeshTraversalUtils::ClearanceValue *clearanceOut)
{
  unsigned int v7; // edi
  hkaiNavMeshTraversalUtils::Angle *v8; // rbp
  hkaiNavMesh::Face *v9; // r14
  hkaiGeneralAccessor *v10; // rsi
  hkaiNavMeshInstance *v11; // rbx
  __int64 v12; // rax
  __m128 v13; // xmm0
  hkSimdFloat32 result; // [rsp+40h] [rbp-28h]

  v7 = faceKey;
  v8 = angle;
  v9 = currentFace;
  v10 = accessor;
  hkaiGeneralAccessor::setSection(accessor, faceKey >> 22);
  v11 = v10->m_accessor;
  v12 = (unsigned __int16)v11->m_clearanceCache.m_data[v11->m_faceClearanceIndices.m_data[v7 & 0x3FFFFF]
                                                     + (signed __int64)(signed int)hkaiNavMeshTraversalUtils::Angle::index(v8)].m_value;
  if ( (_WORD)v12 == -16512 )
  {
    hkaiNavMeshTraversalUtils::computeVertexClearance(&result, v10, v7, v9, v8, up, maxRadius);
    v13 = result.m_real;
    clearanceOut->m_exactValueComputed = 1;
    clearanceOut->m_exactValue.m_real = v13;
    clearanceOut->m_valueHalf.m_value = v13.m128_i16[1];
    clearanceOut->m_truncatedValue.m_real = _mm_shuffle_ps(
                                              (__m128)(unsigned int)(v13.m128_i16[1] << 16),
                                              (__m128)(unsigned int)(v13.m128_i16[1] << 16),
                                              0);
  }
  else
  {
    clearanceOut->m_exactValueComputed = 0;
    clearanceOut->m_exactValue = 0i64;
    clearanceOut->m_truncatedValue.m_real = _mm_shuffle_ps(
                                              (__m128)(unsigned int)((signed __int16)v12 << 16),
                                              (__m128)(unsigned int)((signed __int16)v12 << 16),
                                              0);
    clearanceOut->m_valueHalf.m_value = v12;
  }
}

// File Line: 1053
// RVA: 0xC14960
char __fastcall hkaiNavMeshTraversalUtils::isVertexClearanceForEdgeLessThan(hkaiGeneralAccessor *accessor, unsigned int faceKey, hkaiNavMesh::Face *currentFace, hkaiNavMeshTraversalUtils::Angle *angle, hkVector4f *up, hkSimdFloat32 *maxRadius, hkSimdFloat32 *threshold)
{
  hkaiNavMeshTraversalUtils::Angle *v7; // rdi
  hkaiNavMesh::Face *v8; // rsi
  unsigned int v9; // ebp
  hkaiGeneralAccessor *v10; // r14
  hkSimdFloat32 result; // [rsp+50h] [rbp-58h]
  __int128 v13; // [rsp+60h] [rbp-48h]
  __int128 v14; // [rsp+70h] [rbp-38h]
  int v15; // [rsp+80h] [rbp-28h]
  __int16 v16; // [rsp+84h] [rbp-24h]

  v7 = angle;
  v8 = currentFace;
  v9 = faceKey;
  v14 = 0i64;
  v13 = 0i64;
  v16 = 0;
  v15 = 0;
  v10 = accessor;
  hkaiNavMeshTraversalUtils::getVertexClearanceForEdge(
    accessor,
    faceKey,
    currentFace,
    angle,
    up,
    maxRadius,
    (hkaiNavMeshTraversalUtils::ClearanceValue *)&v13);
  if ( v15 )
    return *(float *)&v14 < threshold->m_real.m128_f32[0];
  if ( *(float *)&v13 >= COERCE_FLOAT(*threshold) )
    return 0;
  if ( fmax(
         COERCE_FLOAT(
           _mm_shuffle_ps(
             (__m128)(unsigned int)((signed __int16)(v16 + 1) << 16),
             (__m128)(unsigned int)((signed __int16)(v16 + 1) << 16),
             0)),
         *(float *)&v13) < COERCE_FLOAT(*threshold) )
    return 1;
  hkaiNavMeshTraversalUtils::computeVertexClearance(&result, v10, v9, v8, v7, up, maxRadius);
  return result.m_real.m128_f32[0] < threshold->m_real.m128_f32[0];
}

// File Line: 1085
// RVA: 0xC13E90
void __fastcall hkaiNavMeshTraversalUtils::computeAllGlobalClearances(hkaiNavMeshInstance *meshInstance, hkVector4f *up)
{
  int v2; // er9
  hkaiNavMeshInstance *v3; // rbx
  hkVector4f *v4; // r15
  int v5; // er9
  int v6; // er9
  _QWORD *v7; // r8
  _QWORD *v8; // rcx
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  int v11; // edx
  int v12; // ecx
  int index; // er11
  unsigned __int64 v14; // rsi
  hkVector4f **v15; // rax
  signed int v16; // edi
  hkaiNavMesh::Face *v17; // r14
  int v18; // esi
  hkaiNavMesh::Edge *v19; // rax
  hkaiNavMesh::Edge *v20; // r8
  __int64 v21; // rax
  signed int v22; // ecx
  __m128 *v23; // rax
  __m128 v24; // xmm1
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __int64 v27; // rax
  __m128 v28; // xmm6
  __m128 v29; // xmm7
  __m128 v30; // xmm3
  __m128 *v31; // rax
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
  signed __int64 v45; // rcx
  int v46; // edx
  int v47; // edi
  __int64 v48; // rsi
  __m128 *v49; // rax
  __m128 v50; // xmm1
  hk1AxisSweep::AabbInt *v51; // rcx
  __m128 v52; // xmm2
  _QWORD *v53; // rax
  _QWORD *v54; // rcx
  _QWORD *v55; // r8
  unsigned __int64 v56; // rax
  signed __int64 v57; // rcx
  int v58; // ecx
  int v59; // esi
  signed __int64 v60; // r8
  int v61; // edi
  __int64 v62; // rdx
  _QWORD *v63; // r8
  _QWORD *v64; // rcx
  unsigned __int64 v65; // rax
  signed __int64 v66; // rcx
  _QWORD *v67; // r8
  _QWORD *v68; // rcx
  unsigned __int64 v69; // rax
  signed __int64 v70; // rcx
  _QWORD *v71; // r8
  _QWORD *v72; // rcx
  unsigned __int64 v73; // rax
  signed __int64 v74; // rcx
  hk1AxisSweep::AabbInt *v75; // rdx
  unsigned int v76; // eax
  bool v77; // cf
  bool v78; // zf
  unsigned __int64 v79; // rax
  unsigned __int64 v80; // rcx
  __int64 v81; // rsi
  signed int v82; // edi
  __m128 *v83; // rax
  __m128 v84; // xmm6
  __m128 v85; // xmm10
  __m128 v86; // xmm11
  __m128 v87; // xmm12
  __m128 v88; // xmm9
  hkaiNavMesh::Edge *v89; // rax
  __int64 v90; // rcx
  __m128 *v91; // rcx
  __int64 v92; // rax
  __m128 v93; // xmm8
  __m128 *v94; // rax
  __m128 v95; // xmm1
  __m128 v96; // xmm7
  __m128 v97; // xmm2
  __m128 v98; // xmm1
  __m128 v99; // xmm9
  __m128 v100; // xmm2
  __m128 v101; // xmm1
  __m128 v102; // xmm8
  __m128 v103; // xmm5
  __m128 v104; // xmm8
  __m128 v105; // xmm7
  __m128 v106; // xmm5
  __m128 v107; // xmm1
  __m128 v108; // xmm4
  __m128 v109; // xmm1
  __m128 v110; // xmm0
  __m128 v111; // xmm3
  __m128 v112; // xmm1
  __m128 v113; // xmm0
  __m128 v114; // xmm3
  __m128 v115; // xmm8
  __m128 v116; // xmm7
  __m128 v117; // xmm7
  __m128 v118; // xmm3
  __m128 v119; // xmm3
  __m128 v120; // xmm4
  __m128 v121; // xmm1
  _QWORD *v122; // rax
  _QWORD *v123; // rcx
  _QWORD *v124; // r8
  unsigned __int64 v125; // rax
  signed __int64 v126; // rcx
  hkSimdFloat32 clearance; // [rsp+30h] [rbp-C8h]
  hk1AxisSweep::AabbInt *aabbs; // [rsp+40h] [rbp-B8h]
  int v129; // [rsp+48h] [rbp-B0h]
  int v130; // [rsp+4Ch] [rbp-ACh]
  hk1AxisSweep::AabbInt *array; // [rsp+50h] [rbp-A8h]
  int size; // [rsp+58h] [rbp-A0h]
  int v133; // [rsp+5Ch] [rbp-9Ch]
  hkAabb aabbIn; // [rsp+60h] [rbp-98h]
  int v135; // [rsp+80h] [rbp-78h]
  int v136; // [rsp+84h] [rbp-74h]
  void *retaddr; // [rsp+148h] [rbp+50h]
  hkVector4f *v138; // [rsp+150h] [rbp+58h]
  hkVector4f *v139; // [rsp+158h] [rbp+60h]
  int v140; // [rsp+160h] [rbp+68h]

  v139 = up;
  v2 = meshInstance->m_numOriginalVertices + meshInstance->m_ownedVertices.m_size + 4;
  v3 = meshInstance;
  v4 = up;
  array = 0i64;
  size = 0;
  v133 = 2147483648;
  if ( v2 > 0 )
  {
    if ( v2 < 0 )
      v2 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      v2,
      32);
  }
  v5 = v3->m_numOriginalEdges;
  aabbs = 0i64;
  v129 = 0;
  v130 = 2147483648;
  v6 = v3->m_ownedEdges.m_size + v5 + 4;
  if ( v6 > 0 )
  {
    if ( v6 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &aabbs,
      v6,
      32);
  }
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = (_QWORD *)v7[1];
  if ( (unsigned __int64)v8 < v7[3] )
  {
    *v8 = "TtboundaryAabbs";
    v9 = __rdtsc();
    v10 = (signed __int64)(v8 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v7[1] = v10;
  }
  v11 = v3->m_numOriginalFaces;
  v12 = v3->m_ownedFaces.m_size;
  index = 0;
  v140 = 0;
  v14 = 0i64;
  clearance.m_real.m128_u64[0] = 0i64;
  if ( v11 + v12 > 0 )
  {
    do
    {
      if ( v3->m_faceFlags.m_size )
      {
        v15 = (hkVector4f **)&retaddr;
        LOBYTE(retaddr) = v3->m_faceFlags.m_data[v14].m_storage;
      }
      else
      {
        LOBYTE(v139) = 0;
        v15 = &v139;
      }
      if ( !(*(_BYTE *)v15 & 1) )
      {
        v16 = 0;
        v17 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__13(
                v3->m_originalFaces,
                v11,
                &v3->m_instancedFaces,
                &v3->m_ownedFaces,
                &v3->m_faceMap,
                index);
        if ( v17->m_numEdges > 0 )
        {
          do
          {
            v18 = v16 + v17->m_startEdgeIndex;
            v19 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
                    v3->m_originalEdges,
                    v3->m_numOriginalEdges,
                    &v3->m_instancedEdges,
                    &v3->m_ownedEdges,
                    &v3->m_edgeMap,
                    v16 + v17->m_startEdgeIndex);
            v20 = v19;
            if ( v19->m_oppositeEdge == -1 || v19->m_flags.m_storage & 0x20 )
            {
              v3->m_globalClearanceCache.m_data[v19->m_a].m_value = -16512;
              v3->m_globalClearanceCache.m_data[v19->m_b].m_value = -16512;
              v21 = v19->m_a;
              v22 = v3->m_numOriginalVertices;
              if ( (signed int)v21 >= v22 )
                v23 = &v3->m_ownedVertices.m_data[(signed int)v21 - v22].m_quad;
              else
                v23 = &v3->m_originalVertices[v21].m_quad;
              v24 = *v23;
              v25 = v3->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
              v26 = v3->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
              v27 = v20->m_b;
              v28 = v3->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
              v29 = v3->m_referenceFrame.m_transform.m_translation.m_quad;
              v30 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v26),
                          _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v25)),
                        _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v28)),
                      v29);
              if ( (signed int)v27 >= v22 )
                v31 = &v3->m_ownedVertices.m_data[(signed int)v27 - v22].m_quad;
              else
                v31 = &v3->m_originalVertices[v27].m_quad;
              v32 = *v31;
              v33 = &aabbs[v129++];
              v34 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v26),
                          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v25)),
                        _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v28)),
                      v29);
              aabbIn.m_min.m_quad = _mm_min_ps(v30, v34);
              aabbIn.m_max.m_quad = _mm_max_ps(v30, v34);
              hk1AxisSweep::AabbInt::set(v33, &aabbIn, v18);
            }
            ++v16;
          }
          while ( v16 < v17->m_numEdges );
          index = v140;
          v14 = clearance.m_real.m128_u64[0];
        }
      }
      v11 = v3->m_numOriginalFaces;
      ++index;
      ++v14;
      v35 = v11 + v3->m_ownedFaces.m_size;
      v140 = index;
      clearance.m_real.m128_u64[0] = v14;
    }
    while ( index < v35 );
    v4 = v138;
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
  v40 = _mm_shuffle_ps((__m128)LODWORD(v3->m_maxGlobalClearance), (__m128)LODWORD(v3->m_maxGlobalClearance), 0);
  *(float *)&retaddr = v40.m128_f32[0] * 1.0039062;
  v41 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v42 = (_QWORD *)v41[1];
  v43 = v41;
  if ( (unsigned __int64)v42 < v41[3] )
  {
    *v42 = "TtvertAabbs";
    v44 = __rdtsc();
    v45 = (signed __int64)(v42 + 2);
    *(_DWORD *)(v45 - 8) = v44;
    v43[1] = v45;
  }
  v46 = v3->m_numOriginalVertices;
  v47 = 0;
  if ( v46 + v3->m_ownedVertices.m_size > 0 )
  {
    v48 = 0i64;
    do
    {
      LODWORD(retaddr) = v3->m_globalClearanceCache.m_data[v48].m_value << 16;
      if ( COERCE_FLOAT(_mm_shuffle_ps((__m128)(unsigned int)retaddr, (__m128)(unsigned int)retaddr, 0)) > v40.m128_f32[0] )
      {
        if ( v47 >= v46 )
          v49 = &v3->m_ownedVertices.m_data[v47 - v46].m_quad;
        else
          v49 = &v3->m_originalVertices[v47].m_quad;
        v50 = *v49;
        v51 = &array[size++];
        v52 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v3->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v3->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v3->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad)),
                v3->m_referenceFrame.m_transform.m_translation.m_quad);
        aabbIn.m_max.m_quad = _mm_add_ps(v52, v40);
        aabbIn.m_min.m_quad = _mm_sub_ps(v52, v40);
        hk1AxisSweep::AabbInt::set(v51, &aabbIn, v47);
        v3->m_globalClearanceCache.m_data[v48].m_value = COERCE_UNSIGNED_INT(v40.m128_f32[0] * 1.0039062) >> 16;
      }
      v46 = v3->m_numOriginalVertices;
      ++v47;
      ++v48;
    }
    while ( v47 < v46 + v3->m_ownedVertices.m_size );
  }
  v53 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v54 = (_QWORD *)v53[1];
  v55 = v53;
  if ( (unsigned __int64)v54 < v53[3] )
  {
    *v54 = "Et";
    v56 = __rdtsc();
    v57 = (signed __int64)(v54 + 2);
    *(_DWORD *)(v57 - 8) = v56;
    v55[1] = v57;
  }
  v58 = size;
  v59 = v129;
  v60 = 4i64;
  v61 = size;
  while ( 1 )
  {
    size = v58 + 1;
    array[v58].m_min[0] = -1;
    v62 = v129++;
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
    v66 = (signed __int64)(v64 + 2);
    *(_DWORD *)(v66 - 8) = v65;
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
    v70 = (signed __int64)(v68 + 2);
    *(_DWORD *)(v70 - 8) = v69;
    v67[1] = v70;
  }
  v71 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v72 = (_QWORD *)v71[1];
  if ( (unsigned __int64)v72 < v71[3] )
  {
    *v72 = "Ttcalc";
    v73 = __rdtsc();
    v74 = (signed __int64)(v72 + 2);
    *(_DWORD *)(v74 - 8) = v73;
    v71[1] = v74;
  }
  v75 = array;
  v76 = aabbs->m_min[0];
  v135 = v61;
  v136 = v59;
  v77 = array->m_min[0] < v76;
  v78 = array->m_min[0] == v76;
  aabbIn.m_max.m_quad.m128_u64[1] = (unsigned __int64)aabbs;
  aabbIn.m_min.m_quad.m128_i32[0] = !v77 && !v78;
  if ( v77 || v78 )
  {
    aabbIn.m_min.m_quad.m128_u64[1] = (unsigned __int64)array;
    v75 = aabbs;
  }
  else
  {
    aabbIn.m_min.m_quad.m128_u64[1] = (unsigned __int64)aabbs;
  }
  aabbIn.m_max.m_quad.m128_u64[0] = (unsigned __int64)&v75[-1];
  hk1AxisSweep::IteratorAB::next((hk1AxisSweep::IteratorAB *)&aabbIn);
  while ( v135 > 0 && v136 > 0 )
  {
    if ( aabbIn.m_min.m_quad.m128_i32[0] )
    {
      v80 = aabbIn.m_max.m_quad.m128_u64[1];
      v79 = aabbIn.m_max.m_quad.m128_u64[0];
    }
    else
    {
      v79 = aabbIn.m_max.m_quad.m128_u64[1];
      v80 = aabbIn.m_max.m_quad.m128_u64[0];
    }
    v81 = *(signed int *)(v79 + 12);
    v82 = v3->m_numOriginalVertices;
    if ( (signed int)v81 >= v82 )
      v83 = &v3->m_ownedVertices.m_data[(signed int)v81 - v82].m_quad;
    else
      v83 = &v3->m_originalVertices[v81].m_quad;
    v84 = v3->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad;
    v85 = v3->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad;
    v86 = v3->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad;
    v87 = v3->m_referenceFrame.m_transform.m_translation.m_quad;
    v88 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v83, *v83, 0), v85),
                _mm_mul_ps(_mm_shuffle_ps(*v83, *v83, 85), v84)),
              _mm_mul_ps(_mm_shuffle_ps(*v83, *v83, 170), v86)),
            v87);
    v89 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__15(
            v3->m_originalEdges,
            v3->m_numOriginalEdges,
            &v3->m_instancedEdges,
            &v3->m_ownedEdges,
            &v3->m_edgeMap,
            *(_DWORD *)(v80 + 12));
    v90 = v89->m_a;
    if ( (signed int)v90 >= v82 )
      v91 = &v3->m_ownedVertices.m_data[(signed int)v90 - v82].m_quad;
    else
      v91 = &v3->m_originalVertices[v90].m_quad;
    v92 = v89->m_b;
    v93 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v91, *v91, 0), v85),
                _mm_mul_ps(_mm_shuffle_ps(*v91, *v91, 85), v84)),
              _mm_mul_ps(_mm_shuffle_ps(*v91, *v91, 170), v86)),
            v87);
    if ( (signed int)v92 >= v82 )
      v94 = &v3->m_ownedVertices.m_data[(signed int)v92 - v82].m_quad;
    else
      v94 = &v3->m_originalVertices[v92].m_quad;
    v95 = _mm_mul_ps(v88, v4->m_quad);
    v96 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*v94, *v94, 0), v85),
                _mm_mul_ps(_mm_shuffle_ps(*v94, *v94, 85), v84)),
              _mm_mul_ps(_mm_shuffle_ps(*v94, *v94, 170), v86)),
            v87);
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
    v103 = v102;
    v104 = _mm_sub_ps(v102, v99);
    v105 = _mm_sub_ps(
             v96,
             _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v101, v101, 85), _mm_shuffle_ps(v101, v101, 0)),
                 _mm_shuffle_ps(v101, v101, 170)),
               v4->m_quad));
    v106 = _mm_sub_ps(v103, v105);
    v107 = _mm_mul_ps(v106, v106);
    v108 = _mm_add_ps(
             _mm_add_ps(_mm_shuffle_ps(v107, v107, 85), _mm_shuffle_ps(v107, v107, 0)),
             _mm_shuffle_ps(v107, v107, 170));
    v109 = _mm_mul_ps(v104, v106);
    v110 = _mm_rcp_ps(v108);
    v111 = _mm_mul_ps(
             _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v108, v110)), v110),
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
               _mm_shuffle_ps(v109, v109, 170)));
    v112 = _mm_cmpltps(v111, query.m_quad);
    v113 = _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_andnot_ps(v112, query.m_quad), _mm_and_ps(v111, v112)));
    v114 = v104;
    v115 = _mm_mul_ps(v104, v104);
    v116 = _mm_sub_ps(v105, v99);
    LODWORD(retaddr) = v3->m_globalClearanceCache.m_data[v81].m_value << 16;
    v117 = _mm_mul_ps(v116, v116);
    v118 = _mm_sub_ps(v114, _mm_mul_ps(v113, v106));
    v119 = _mm_mul_ps(v118, v118);
    v120 = _mm_min_ps(
             _mm_min_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                 _mm_shuffle_ps(v115, v115, 170)),
               _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v117, v117, 85), _mm_shuffle_ps(v117, v117, 0)),
                 _mm_shuffle_ps(v117, v117, 170))),
             _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v119, v119, 85), _mm_shuffle_ps(v119, v119, 0)),
               _mm_shuffle_ps(v119, v119, 170)));
    v121 = _mm_rsqrt_ps(v120);
    clearance.m_real = _mm_andnot_ps(
                         _mm_cmpleps(v120, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v121, v120), v121)),
                             _mm_mul_ps(*(__m128 *)_xmm, v121)),
                           v120));
    if ( clearance.m_real.m128_f32[0] < COERCE_FLOAT(
                                          _mm_shuffle_ps(
                                            (__m128)(unsigned int)retaddr,
                                            (__m128)(unsigned int)retaddr,
                                            0)) )
      hkaiNavMeshTraversalUtils::updateGlobalClearance(v3, v81, &clearance);
    hk1AxisSweep::IteratorAB::next((hk1AxisSweep::IteratorAB *)&aabbIn);
  }
  v122 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v123 = (_QWORD *)v122[1];
  v124 = v122;
  if ( (unsigned __int64)v123 < v122[3] )
  {
    *v123 = "Et";
    v125 = __rdtsc();
    v126 = (signed __int64)(v123 + 2);
    *(_DWORD *)(v126 - 8) = v125;
    v124[1] = v126;
  }
  v129 = 0;
  if ( v130 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      aabbs,
      32 * v130);
  aabbs = 0i64;
  size = 0;
  v130 = 2147483648;
  if ( v133 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      32 * v133);
}

// File Line: 1205
// RVA: 0xC17EC0
_BOOL8 __fastcall SameSectionFilter::isInstanceEnabled(SameSectionFilter *this, hkaiNavMeshInstance *instance, unsigned int filterInfo, unsigned __int64 userData)
{
  int v4; // ecx
  _BOOL8 result; // rax

  if ( instance && (v4 = this->m_allowedSection, v4 != -1) )
    result = instance->m_runtimeId == v4;
  else
    result = 1i64;
  return result;
}

// File Line: 1232
// RVA: 0xC16270
hkSimdFloat32 *__fastcall hkaiNavMeshTraversalUtils::computeGlobalClearance(hkSimdFloat32 *result, hkaiNavMeshInstance *meshInstance, hkaiNavMeshQueryMediator *worldMediator, int vIdx, hkVector4f *up)
{
  hkSimdFloat32 *v5; // rbx
  int v6; // eax
  hkVector4f *v7; // rax
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  hkBaseObjectVtbl *v12; // rax
  __m128i v13; // xmm2
  __m128i v14; // xmm3
  hkSimdFloat32 *v15; // rax
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  void **v18; // [rsp+20h] [rbp-B8h]
  int v19; // [rsp+28h] [rbp-B0h]
  int v20; // [rsp+30h] [rbp-A8h]
  __m128 v21; // [rsp+40h] [rbp-98h]
  int v22; // [rsp+50h] [rbp-88h]
  __int64 v23; // [rsp+58h] [rbp-80h]
  void ***v24; // [rsp+60h] [rbp-78h]
  __int64 v25; // [rsp+68h] [rbp-70h]
  __int64 v26; // [rsp+70h] [rbp-68h]
  __int128 v27; // [rsp+80h] [rbp-58h]
  __int128 v28; // [rsp+90h] [rbp-48h]
  __int64 v29; // [rsp+A0h] [rbp-38h]
  __m128 v30; // [rsp+B0h] [rbp-28h]

  v18 = &SameSectionFilter::`vftable;
  v5 = result;
  v20 = meshInstance->m_runtimeId;
  v6 = meshInstance->m_numOriginalVertices;
  v19 = 0x1FFFF;
  if ( vIdx >= v6 )
    v7 = &meshInstance->m_ownedVertices.m_data[vIdx - v6];
  else
    v7 = &meshInstance->m_originalVertices[vIdx];
  v8 = v7->m_quad;
  v22 = 0;
  v23 = 0i64;
  v25 = 0i64;
  v26 = 0i64;
  v29 = 0i64;
  v9 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), meshInstance->m_referenceFrame.m_transform.m_rotation.m_col0.m_quad);
  v10 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), meshInstance->m_referenceFrame.m_transform.m_rotation.m_col1.m_quad);
  v11 = _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), meshInstance->m_referenceFrame.m_transform.m_rotation.m_col2.m_quad);
  v24 = &v18;
  v12 = worldMediator->vfptr;
  v13 = (__m128i)_mm_shuffle_ps(
                   (__m128)LODWORD(meshInstance->m_maxGlobalClearance),
                   (__m128)LODWORD(meshInstance->m_maxGlobalClearance),
                   0);
  v30 = up->m_quad;
  v14 = (__m128i)_mm_add_ps(
                   _mm_add_ps(_mm_add_ps(v10, v9), v11),
                   meshInstance->m_referenceFrame.m_transform.m_translation.m_quad);
  _mm_store_si128((__m128i *)&v28, v13);
  _mm_store_si128((__m128i *)&v27, v14);
  v21 = _mm_shuffle_ps((__m128)0i64, _mm_unpackhi_ps((__m128)0i64, _mm_mul_ps((__m128)v13, (__m128)v13)), 196);
  ((void (__fastcall *)(hkaiNavMeshQueryMediator *, int *, __m128 *))v12[2].__vecDelDtor)(worldMediator, &v22, &v21);
  v15 = v5;
  v16 = _mm_shuffle_ps(v21, v21, 255);
  v17 = _mm_rsqrt_ps(v16);
  v5->m_real = _mm_andnot_ps(
                 _mm_cmpleps(v16, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v17, v16), v17)),
                     _mm_mul_ps(*(__m128 *)_xmm, v17)),
                   v16));
  return v15;
}

