// File Line: 49
// RVA: 0xC212C0
void __fastcall hkaiStringPulling::Funnel::Funnel(hkaiStringPulling::Funnel *this)
{
  *(_QWORD *)&this->m_start = 0i64;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 2147483648;
}

// File Line: 53
// RVA: 0xC212E0
void __fastcall hkaiStringPulling::Funnel::clear(hkaiStringPulling::Funnel *this)
{
  this->m_data.m_size = 0;
  *(_QWORD *)&this->m_start = 0i64;
}

// File Line: 60
// RVA: 0xC212F0
char __fastcall hkaiStringPulling::Funnel::add(hkaiStringPulling::Funnel *this, hkaiStringPulling::Vertex *vertex, hkaiStringPulling::Side side)
{
  hkaiStringPulling::Vertex *v3; // rdi
  hkaiStringPulling::Funnel *v4; // rbx
  int v5; // eax
  hkaiStringPulling::Vertex *v6; // r8
  char result; // al
  hkaiStringPulling::Vertex *v8; // rcx

  v3 = vertex;
  v4 = this;
  if ( side == 1 )
  {
    if ( this->m_start <= 0 )
    {
      hkArrayBase<hkaiStringPulling::Vertex>::_insertAt(
        (hkArrayBase<hkaiStringPulling::Vertex> *)&this->m_data.m_data,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        0,
        vertex);
      ++v4->m_apex;
      result = 1;
    }
    else
    {
      v5 = this->m_start - 1;
      this->m_start = v5;
      v6 = &this->m_data.m_data[v5];
      v6->m_index = vertex->m_index;
      v6->m_side.m_storage = vertex->m_side.m_storage;
      v6->m_type.m_storage = vertex->m_type.m_storage;
      v6->m_clearanceIsNegative.m_bool = vertex->m_clearanceIsNegative.m_bool;
      v6->m_userEdge.m_bool = vertex->m_userEdge.m_bool;
      v6->m_userEdgeSwapped.m_bool = vertex->m_userEdgeSwapped.m_bool;
      result = 1;
      v6->m_pos = vertex->m_pos;
      v6->m_center = vertex->m_center;
    }
  }
  else
  {
    if ( this->m_data.m_size == (this->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &this->m_data, 48);
    v8 = &v4->m_data.m_data[v4->m_data.m_size];
    if ( v8 )
    {
      *(_OWORD *)&v8->m_index = *(_OWORD *)&v3->m_index;
      v8->m_pos = v3->m_pos;
      v8->m_center = v3->m_center;
    }
    ++v4->m_data.m_size;
    result = 1;
  }
  return result;
}

// File Line: 90
// RVA: 0xC21400
void __fastcall hkaiStringPulling::Funnel::pop(hkaiStringPulling::Funnel *this, hkaiStringPulling::Side side, hkaiStringPulling::Vertex *vertexOut)
{
  hkaiStringPulling::Funnel *v3; // r9
  __int64 v4; // rdx
  hkaiStringPulling::Vertex *v5; // rdx
  hkaiStringPulling::Vertex *v6; // rcx

  v3 = this;
  if ( side == 1 )
  {
    v4 = this->m_start;
    this->m_start = v4 + 1;
    v5 = &this->m_data.m_data[v4];
    vertexOut->m_index = v5->m_index;
    vertexOut->m_side.m_storage = v5->m_side.m_storage;
    vertexOut->m_type.m_storage = v5->m_type.m_storage;
    vertexOut->m_clearanceIsNegative.m_bool = v5->m_clearanceIsNegative.m_bool;
    vertexOut->m_userEdge.m_bool = v5->m_userEdge.m_bool;
    vertexOut->m_userEdgeSwapped.m_bool = v5->m_userEdgeSwapped.m_bool;
    vertexOut->m_pos = v5->m_pos;
    vertexOut->m_center = v5->m_center;
  }
  else
  {
    v6 = &this->m_data.m_data[this->m_data.m_size - 1];
    vertexOut->m_index = v6->m_index;
    vertexOut->m_side.m_storage = v6->m_side.m_storage;
    vertexOut->m_type.m_storage = v6->m_type.m_storage;
    vertexOut->m_clearanceIsNegative.m_bool = v6->m_clearanceIsNegative.m_bool;
    vertexOut->m_userEdge.m_bool = v6->m_userEdge.m_bool;
    vertexOut->m_userEdgeSwapped.m_bool = v6->m_userEdgeSwapped.m_bool;
    vertexOut->m_pos = v6->m_pos;
    vertexOut->m_center = v6->m_center;
    --v3->m_data.m_size;
  }
}

// File Line: 105
// RVA: 0xC214C0
_BOOL8 __fastcall hkaiStringPulling::Funnel::apexPopped(hkaiStringPulling::Funnel *this)
{
  int v1; // eax

  v1 = this->m_apex;
  return v1 < this->m_start || v1 >= this->m_data.m_size;
}

// File Line: 110
// RVA: 0xC214E0
hkaiStringPulling::Vertex *__fastcall hkaiStringPulling::Funnel::getApex(hkaiStringPulling::Funnel *this)
{
  return &this->m_data.m_data[this->m_apex];
}

// File Line: 115
// RVA: 0xC21500
hkaiStringPulling::Vertex *__fastcall hkaiStringPulling::Funnel::getApex(hkaiStringPulling::Funnel *this)
{
  return &this->m_data.m_data[this->m_apex];
}

// File Line: 120
// RVA: 0xC21520
hkaiStringPulling::Vertex *__fastcall hkaiStringPulling::Funnel::operator[](hkaiStringPulling::Funnel *this, int index)
{
  return &this->m_data.m_data[index];
}

// File Line: 126
// RVA: 0xC21540
hkaiStringPulling::Vertex *__fastcall hkaiStringPulling::Funnel::operator[](hkaiStringPulling::Funnel *this, int index)
{
  return &this->m_data.m_data[index];
}

// File Line: 135
// RVA: 0xC21560
void __fastcall hkaiStringPulling::Funnel::Iterator::Iterator(hkaiStringPulling::Funnel::Iterator *this, hkaiStringPulling::Funnel *funnel, hkaiStringPulling::Side side, int index)
{
  this->m_side = side;
  this->m_funnelIndex = index;
  this->m_funnel = funnel;
  if ( index == -1 )
  {
    if ( side == 1 )
      this->m_funnelIndex = funnel->m_start;
    else
      this->m_funnelIndex = funnel->m_data.m_size - 1;
  }
}

// File Line: 143
// RVA: 0xC215A0
void __fastcall hkaiStringPulling::Funnel::Iterator::operator++(hkaiStringPulling::Funnel::Iterator *this, int __formal)
{
  if ( this->m_side == 1 )
    ++this->m_funnelIndex;
  else
    --this->m_funnelIndex;
}

// File Line: 155
// RVA: 0xC215C0
__int64 __fastcall hkaiStringPulling::Funnel::Iterator::isValid(hkaiStringPulling::Funnel::Iterator *this)
{
  unsigned int v1; // er8

  v1 = 0;
  if ( this->m_side == 1 )
    LOBYTE(v1) = this->m_funnelIndex < this->m_funnel->m_data.m_size;
  else
    LOBYTE(v1) = this->m_funnelIndex >= this->m_funnel->m_start;
  return v1;
}

// File Line: 168
// RVA: 0xC21600
hkaiStringPulling::Funnel::Iterator *__fastcall hkaiStringPulling::Funnel::Iterator::operator=(hkaiStringPulling::Funnel::Iterator *this, hkaiStringPulling::Funnel::Iterator *other)
{
  this->m_side = other->m_side;
  this->m_funnelIndex = other->m_funnelIndex;
  return this;
}

// File Line: 176
// RVA: 0xC21620
__int64 __fastcall hkaiStringPulling::Funnel::Iterator::lessOrEqualApex(hkaiStringPulling::Funnel::Iterator *this)
{
  unsigned int v1; // er8

  v1 = 0;
  if ( this->m_side == 1 )
    LOBYTE(v1) = this->m_funnelIndex <= this->m_funnel->m_apex;
  else
    LOBYTE(v1) = this->m_funnelIndex >= this->m_funnel->m_apex;
  return v1;
}

// File Line: 191
// RVA: 0xC21660
void __fastcall hkaiStringPulling::PathEdgeCache::PathEdgeCache(hkaiStringPulling::PathEdgeCache *this, hkArrayBase<unsigned int> *visitedEdgeKeys)
{
  int v2; // edi
  hkaiStringPulling::PathEdgeCache::PathEdge *v3; // rax
  hkArrayBase<unsigned int> *v4; // rsi
  hkaiStringPulling::PathEdgeCache *v5; // rbx
  hkLifoAllocator *v6; // rax
  hkLifoAllocator *v7; // rcx
  int v8; // edx
  char *v9; // r8

  v2 = visitedEdgeKeys->m_size;
  v3 = 0i64;
  v4 = visitedEdgeKeys;
  v5 = this;
  this->m_pathEdges.m_capacityAndFlags = 2147483648;
  this->m_pathEdges.m_data = 0i64;
  this->m_pathEdges.m_size = 0;
  this->m_pathEdges.m_initialCapacity = v2;
  if ( v2 )
  {
    v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = v6;
    v3 = (hkaiStringPulling::PathEdgeCache::PathEdge *)v6->m_cur;
    v8 = ((v2 << 7) + 127) & 0xFFFFFF80;
    v9 = (char *)v3 + v8;
    if ( v8 > v7->m_slabSize || v9 > v7->m_end )
      v3 = (hkaiStringPulling::PathEdgeCache::PathEdge *)hkLifoAllocator::allocateFromNewSlab(v7, v8);
    else
      v7->m_cur = v9;
  }
  v5->m_pathEdges.m_data = v3;
  v5->m_pathEdges.m_localMemory = v3;
  v5->m_pathEdges.m_capacityAndFlags = v2 | 0x80000000;
  v5->m_pathEdgeKeys = v4;
}

// File Line: 195
// RVA: 0xC21700
void __fastcall hkaiStringPulling::PathEdgeCache::cacheMeshData(hkaiStringPulling::PathEdgeCache *this, hkaiGeneralAccessor *accessor, unsigned int startFaceKey, hkVector4f *up, unsigned int computeNormals)
{
  hkaiStringPulling::PathEdgeCache *v5; // r14
  hkVector4f *v6; // rbx
  unsigned int v7; // er12
  hkArray<int,hkContainerHeapAllocator> **v8; // rdi
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  unsigned __int64 v13; // rsi
  int v14; // ecx
  __int64 v15; // rdx
  unsigned int *v16; // rcx
  hkArray<int,hkContainerHeapAllocator> *v17; // rax
  __int64 v18; // rdx
  __int64 v19; // rsi
  unsigned int v20; // eax
  hkaiNavMesh::Edge *v21; // rax
  unsigned int v22; // edx
  hkaiNavMesh::Edge *v23; // r15
  char v24; // r8
  unsigned int v25; // ecx
  unsigned int v26; // er14
  unsigned int v27; // ecx
  unsigned int v28; // eax
  int v29; // er13
  hkaiNavMesh::Face *v30; // r8
  char v31; // r11
  int v32; // ebx
  __m128 v33; // xmm0
  __m128 *v34; // rax
  __m128 *v35; // rcx
  int index; // ebx
  hkaiNavMesh::Edge *v37; // rbx
  unsigned int v38; // ST44_4
  __m128 v39; // xmm0
  hkaiNavMesh::Edge *v40; // rax
  hkaiStringPulling::PathEdgeCache::PathEdge *v41; // rbx
  __m128 v42; // xmm1
  _QWORD *v43; // rax
  _QWORD *v44; // rcx
  _QWORD *v45; // r8
  unsigned __int64 v46; // rax
  signed __int64 v47; // rcx
  unsigned int v48; // [rsp+30h] [rbp-C8h]
  __m128 *v49; // [rsp+48h] [rbp-B0h]
  hkVector4f normalOut; // [rsp+50h] [rbp-A8h]
  __int64 v51; // [rsp+60h] [rbp-98h]
  hkSimdFloat32 maxClearance; // [rsp+70h] [rbp-88h]
  hkVector4f edgeBOut; // [rsp+88h] [rbp-70h]
  hkaiNavMesh::Face *v54; // [rsp+98h] [rbp-60h]
  hkVector4f edgeAOut; // [rsp+A8h] [rbp-50h]
  __m128 v56; // [rsp+B8h] [rbp-40h]
  __m128 v57; // [rsp+C8h] [rbp-30h]
  hkVector4f v58; // [rsp+D8h] [rbp-20h]
  __m128 v59; // [rsp+E8h] [rbp-10h]
  hkVector4f v60; // [rsp+F8h] [rbp+0h]
  __m128 v61; // [rsp+108h] [rbp+10h]
  hkSimdFloat32 result; // [rsp+118h] [rbp+20h]
  hkSimdFloat32 v63; // [rsp+128h] [rbp+30h]
  char v64; // [rsp+138h] [rbp+40h]
  hkaiStringPulling::PathEdgeCache *retaddr; // [rsp+1A8h] [rbp+B0h]
  unsigned int v66; // [rsp+1B0h] [rbp+B8h]
  unsigned int v67; // [rsp+1B8h] [rbp+C0h]
  hkVector4f *upa; // [rsp+1C0h] [rbp+C8h]
  hkVector4f *v69; // [rsp+1C8h] [rbp+D0h]

  v69 = up;
  v5 = this;
  v6 = up;
  v7 = startFaceKey;
  v8 = (hkArray<int,hkContainerHeapAllocator> **)accessor;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtcacheMeshData";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = v5->m_pathEdgeKeys->m_size;
  v14 = v5->m_pathEdgeKeys->m_size - v5->m_pathEdges.m_size;
  v15 = v14;
  if ( v14 > 0 )
  {
    v16 = &v5->m_pathEdges.m_data[(signed __int64)v5->m_pathEdges.m_size].m_oppositeEdge.m_oppositeEdge;
    do
    {
      if ( v16 != (unsigned int *)28 )
      {
        *(v16 - 4) = -1;
        *(v16 - 5) = -1;
        *(v16 - 3) = 4;
        v16[1] = -1;
        *v16 = -1;
        v16[2] = 4;
      }
      v16 += 32;
      --v15;
    }
    while ( v15 );
  }
  v5->m_pathEdges.m_size = v13;
  hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v8, v7 >> 22);
  if ( (_DWORD)v69 )
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&v58,
      (hkSimdFloat32 *)*v8,
      (hkaiNavMeshInstance *)(v7 & 0x3FFFFF),
      (__int64)v5);
  else
    v5->m_startFaceNormal = (hkVector4f)v6->m_quad;
  v17 = *v8;
  v18 = 0i64;
  maxClearance.m_real.m128_u64[1] = v13;
  v51 = 0i64;
  maxClearance.m_real = _mm_shuffle_ps((__m128)LODWORD(v17[29].m_data), (__m128)LODWORD(v17[29].m_data), 0);
  if ( (signed int)v13 > 0 )
  {
    v19 = 0i64;
    do
    {
      v48 = v7;
      v20 = v5->m_pathEdgeKeys->m_data[v18];
      normalOut.m_quad.m128_u64[1] = 0i64;
      v67 = v20;
      v21 = hkaiGeneralAccessor::getEdgeAndVertsFromPacked(
              (hkaiGeneralAccessor *)v8,
              v20,
              &edgeAOut,
              &edgeBOut,
              (const int **)&normalOut.m_quad.m128_u64[1]);
      v22 = v21->m_oppositeFace;
      v23 = v21;
      v24 = v21->m_flags.m_storage & 0x40;
      if ( v24 )
        v25 = v22 & 0xFFC00000;
      else
        v25 = (*v8)[29].m_size << 22;
      v26 = v25 | v22 & 0x3FFFFF;
      v27 = v21->m_oppositeEdge;
      if ( v22 == -1 )
        v26 = -1;
      if ( v24 )
        v28 = v27 & 0xFFC00000;
      else
        v28 = (*v8)[29].m_size << 22;
      v29 = v28 | v27 & 0x3FFFFF;
      if ( v27 == -1 )
        v29 = -1;
      v30 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__18(
              (hkaiNavMesh::Face *)(*v8)[1].m_data,
              (*v8)[1].m_size,
              (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&(*v8)[15],
              (hkArray<hkaiNavMesh::Face,hkContainerHeapAllocator> *)&(*v8)[17],
              *v8 + 14,
              v7 & 0x3FFFFF);
      v54 = v30;
      v32 = v31 & 0x10;
      if ( v31 & 0x10 )
      {
        v33 = aabbOut.m_quad;
        v34 = &v59;
        v59 = aabbOut.m_quad;
      }
      else
      {
        hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v8, v7 >> 22);
        v66 = *((signed __int16 *)(*v8)[27].m_data + v23->m_a) << 16;
        v56 = _mm_shuffle_ps((__m128)v66, (__m128)v66, 0);
        if ( v56.m128_f32[0] > maxClearance.m_real.m128_f32[0] )
        {
          hkaiNavMeshTraversalUtils::computeGlobalClearance(&result, (hkaiGeneralAccessor *)v8, v7, v23);
          v56 = _mm_shuffle_ps(
                  (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
                  (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
                  0);
        }
        v33 = aabbOut.m_quad;
        v30 = v54;
        v34 = &v56;
      }
      v49 = v34;
      if ( v32 )
      {
        v61 = v33;
        v35 = &v61;
      }
      else
      {
        index = (v67 & 0x3FFFFF) + 1;
        if ( index >= v30->m_startEdgeIndex + v30->m_numEdges )
          index = v30->m_startEdgeIndex;
        hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v8, v67 >> 22);
        v37 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__19(
                (hkaiNavMesh::Edge *)(*v8)[2].m_data,
                (*v8)[2].m_size,
                (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v8)[16],
                (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v8)[18],
                *v8 + 13,
                index);
        hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v8, v7 >> 22);
        v38 = *((signed __int16 *)(*v8)[27].m_data + v37->m_a) << 16;
        v57 = _mm_shuffle_ps((__m128)v38, (__m128)v38, 0);
        if ( v57.m128_f32[0] > maxClearance.m_real.m128_f32[0] )
        {
          hkaiNavMeshTraversalUtils::computeGlobalClearance(&v63, (hkaiGeneralAccessor *)v8, v7, v37);
          v57 = _mm_shuffle_ps(
                  (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(v63.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
                  (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(v63.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
                  0);
        }
        v35 = &v57;
      }
      normalOut.m_quad.m128_u64[0] = 0i64;
      v39 = _mm_unpackhi_ps(edgeBOut.m_quad, *v35);
      edgeAOut.m_quad = _mm_shuffle_ps(edgeAOut.m_quad, _mm_unpackhi_ps(edgeAOut.m_quad, *v49), 196);
      edgeBOut.m_quad = _mm_shuffle_ps(edgeBOut.m_quad, v39, 196);
      v40 = hkaiGeneralAccessor::getEdgeAndVertsFromPacked(
              (hkaiGeneralAccessor *)v8,
              v29,
              &v60,
              &v58,
              (const int **)&normalOut);
      v7 = v26;
      v41 = retaddr->m_pathEdges.m_data;
      v41[v19].m_incomingEdge.m_a = v23->m_a;
      v41[v19].m_incomingEdge.m_b = v23->m_b;
      v41[v19].m_incomingEdge.m_oppositeEdge = v23->m_oppositeEdge;
      v41[v19].m_incomingEdge.m_oppositeFace = v23->m_oppositeFace;
      v41[v19].m_incomingEdge.m_flags.m_storage = v23->m_flags.m_storage;
      v41[v19].m_incomingEdge.m_paddingByte = v23->m_paddingByte;
      v41[v19].m_incomingEdge.m_userEdgeCost.m_value = v23->m_userEdgeCost.m_value;
      v41[v19].m_incomingEdgePointA_GC = (hkVector4f)edgeAOut.m_quad;
      v41[v19].m_incomingEdgePointB_GC = (hkVector4f)edgeBOut.m_quad;
      v41[v19].m_oppositeEdge.m_a = v40->m_a;
      v41[v19].m_oppositeEdge.m_b = v40->m_b;
      v41[v19].m_oppositeEdge.m_oppositeEdge = v40->m_oppositeEdge;
      v41[v19].m_oppositeEdge.m_oppositeFace = v40->m_oppositeFace;
      v41[v19].m_oppositeEdge.m_flags.m_storage = v40->m_flags.m_storage;
      v41[v19].m_oppositeEdge.m_paddingByte = v40->m_paddingByte;
      v41[v19].m_oppositeEdge.m_userEdgeCost.m_value = v40->m_userEdgeCost.m_value;
      v41[v19].m_oppositeEdgePointA = (hkVector4f)v60.m_quad;
      v42 = v58.m_quad;
      v41[v19].m_oppositeEdge.m_oppositeFace = v48;
      v41[v19].m_incomingEdge.m_oppositeFace = v26;
      v41[v19].m_incomingEdge.m_oppositeEdge = v29;
      v41[v19].m_oppositeEdgePointB.m_quad = v42;
      v41[v19].m_oppositeEdge.m_oppositeEdge = v67;
      if ( v23->m_flags.m_storage & 0x10 && normalOut.m_quad.m128_u64[1] )
      {
        v41[v19].m_incomingEdgeData = *(_DWORD *)normalOut.m_quad.m128_u64[1];
        v41[v19].m_oppositeEdgeData = *(_DWORD *)normalOut.m_quad.m128_u64[0];
      }
      else
      {
        *(_QWORD *)&v41[v19].m_incomingEdgeData = 0i64;
      }
      if ( (_DWORD)v69 )
      {
        hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v8, v26 >> 22);
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          (hkaiNavMeshUtils *)&v64,
          (hkSimdFloat32 *)*v8,
          (hkaiNavMeshInstance *)(v26 & 0x3FFFFF),
          (__int64)&v41[v19].m_faceNormal);
      }
      else
      {
        v41[v19].m_faceNormal = (hkVector4f)upa->m_quad;
      }
      v5 = retaddr;
      ++v19;
      v18 = v51 + 1;
      v51 = v18;
    }
    while ( v18 < (signed __int64)maxClearance.m_real.m128_u64[1] );
  }
  v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v44 = (_QWORD *)v43[1];
  v45 = v43;
  if ( (unsigned __int64)v44 < v43[3] )
  {
    *v44 = "Et";
    v46 = __rdtsc();
    v47 = (signed __int64)(v44 + 2);
    *(_DWORD *)(v47 - 8) = v46;
    v45[1] = v47;
  }
}

// File Line: 348
// RVA: 0xC21EB0
bool __fastcall hkaiStringPulling::getSide(hkaiStringPulling *this, hkVector4f *a, hkVector4f *b, hkVector4f *p)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm2
  __m128 v7; // xmm2

  v4 = _mm_sub_ps(b->m_quad, a->m_quad);
  v5 = _mm_sub_ps(p->m_quad, a->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4), _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5));
  v7 = _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), this->m_up.m_quad);
  return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v7, v7, 170))) > 0.0;
}

// File Line: 389
// RVA: 0xC21D40
void __fastcall hkaiStringPulling::hkaiStringPulling(hkaiStringPulling *this, hkaiGeneralAccessor *accessor, hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdgeKeys, unsigned int startFaceKey, hkVector4f *startPoint, hkVector4f *endPoint, unsigned int project, unsigned int computeNormals, hkVector4f *up, float radius, hkaiPathWriter *writer)
{
  hkaiStringPulling *v11; // rdi
  unsigned int v12; // esi
  hkaiGeneralAccessor *v13; // rbp
  unsigned int v14; // eax
  int v15; // eax
  __m128 v16; // xmm0

  v11 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v12 = startFaceKey;
  v13 = accessor;
  v14 = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStringPulling::`vftable';
  if ( radius != 0.0 )
    v14 = 0;
  this->m_radiusIsZero = v14;
  v15 = visitedEdgeKeys->m_size;
  this->m_accessor = accessor;
  this->m_pathLength = v15;
  hkaiStringPulling::PathEdgeCache::PathEdgeCache(
    &this->m_pathEdgeCache,
    (hkArrayBase<unsigned int> *)&visitedEdgeKeys->m_data);
  hkaiStringPulling::Funnel::Funnel(&v11->m_funnel);
  v11->m_up = (hkVector4f)up->m_quad;
  v11->m_startPoint = (hkVector4f)startPoint->m_quad;
  v16 = endPoint->m_quad;
  v11->m_writer = writer;
  v11->m_endPoint.m_quad = v16;
  v11->m_lastVertexInPath.m_index = -2;
  *(_DWORD *)&v11->m_lastVertexInPath.m_side.m_storage = 255;
  v11->m_lastVertexInPath.m_userEdgeSwapped.m_bool = 0;
  v11->m_project = project;
  v11->m_radius.m_real = _mm_shuffle_ps((__m128)LODWORD(radius), (__m128)LODWORD(radius), 0);
  v11->m_lastVertexInPath.m_pos = 0i64;
  v11->m_startFaceKey = v12;
  v11->m_lastVertexInPath.m_center = (hkVector4f)aabbOut.m_quad;
  v11->m_lastVertexInPath.m_clearanceIsNegative.m_bool = 0.0 < 0.0;
  v11->m_lastVertexInPath.m_index = -1;
  v11->m_lastVertexInPath.m_side.m_storage = -1;
  hkaiStringPulling::PathEdgeCache::cacheMeshData(&v11->m_pathEdgeCache, v13, v12, &v11->m_up, computeNormals);
}

// File Line: 401
// RVA: 0xC22020
void __fastcall hkaiStringPulling::convertToTangent(hkaiStringPulling *this, hkVector4f *_start, hkVector4f *endInOut, hkaiStringPulling::Side side)
{
  if ( !this->m_radiusIsZero && side != -1 )
    hkaiStringPulling::convertToTangent(_start, &this->m_up, endInOut, &this->m_radius, side);
}

// File Line: 410
// RVA: 0xC22060
void __fastcall hkaiStringPulling::convertToTangent(hkVector4f *_start, hkVector4f *_up, hkVector4f *endInOut, hkSimdFloat32 *_radius, hkaiStringPulling::Side side)
{
  __m128 v5; // xmm1
  __m128 v6; // xmm13
  __m128 v7; // xmm1
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm13
  __m128 v14; // xmm11
  __m128 v15; // xmm7
  __m128 v16; // xmm7
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm7
  __m128 v21; // xmm8
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm14
  __m128 v28; // xmm3
  __m128 v29; // xmm7
  __m128 v30; // xmm2
  __m128 v31; // xmm1

  v5 = _mm_sub_ps(_start->m_quad, endInOut->m_quad);
  v6 = _mm_sub_ps(endInOut->m_quad, _start->m_quad);
  v7 = _mm_mul_ps(v5, v5);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_rsqrt_ps(v8);
  v10 = _mm_mul_ps(_up->m_quad, v6);
  v11 = _mm_min_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v8, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v8, v9), v9)), _mm_mul_ps(*(__m128 *)_xmm, v9)),
              v8)),
          _radius->m_real);
  v12 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
            _mm_shuffle_ps(v10, v10, 170)),
          _up->m_quad);
  v13 = _mm_sub_ps(v6, v12);
  v14 = _mm_add_ps(_start->m_quad, v12);
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(_up->m_quad, _up->m_quad, 201), v13),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), _up->m_quad));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v20 = _mm_mul_ps(
          v16,
          _mm_andnot_ps(
            _mm_cmpleps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
              _mm_mul_ps(*(__m128 *)_xmm, v19))));
  v21 = _mm_mul_ps(v13, v13);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_andnot_ps(
          _mm_cmpleps(v22, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)), _mm_mul_ps(*(__m128 *)_xmm, v23)));
  v25 = _mm_sub_ps(v22, _mm_mul_ps(v11, v11));
  v26 = _mm_rsqrt_ps(v25);
  v27 = _mm_mul_ps(v25, v24);
  v28 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v25, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                  _mm_mul_ps(*(__m128 *)_xmm, v26)),
                v25)),
            v11),
          v24);
  if ( side == 1 )
    v29 = _mm_mul_ps(v20, v28);
  else
    v29 = _mm_mul_ps(v20, _mm_sub_ps((__m128)0i64, v28));
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v31 = _mm_rsqrt_ps(v30);
  endInOut->m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmpleps(v30, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                               _mm_mul_ps(*(__m128 *)_xmm, v31))),
                           v13),
                         v27),
                       _mm_add_ps(v29, v14));
}

// File Line: 465
// RVA: 0xC22300
void __fastcall hkaiStringPulling::convertToTangentNorm(hkaiStringPulling *this, hkVector4f *startInOut, hkVector4f *endInOut, hkaiStringPulling::Side side)
{
  __m128 v4; // xmm7
  __m128 v5; // xmm1
  __m128 v6; // xmm6
  __m128 v7; // xmm6
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm6

  if ( !this->m_radiusIsZero )
  {
    v4 = endInOut->m_quad;
    v5 = _mm_sub_ps(endInOut->m_quad, startInOut->m_quad);
    v6 = _mm_sub_ps(
           _mm_mul_ps(_mm_shuffle_ps(this->m_up.m_quad, this->m_up.m_quad, 201), v5),
           _mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), this->m_up.m_quad));
    v7 = _mm_shuffle_ps(v6, v6, 201);
    v8 = _mm_mul_ps(v7, v7);
    v9 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)), _mm_shuffle_ps(v8, v8, 170));
    v10 = _mm_rsqrt_ps(v9);
    v11 = _mm_mul_ps(
            v7,
            _mm_andnot_ps(
              _mm_cmpleps(v9, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                _mm_mul_ps(*(__m128 *)_xmm, v10))));
    if ( side == 1 )
    {
      endInOut->m_quad = _mm_add_ps(_mm_mul_ps(this->m_radius.m_real, v11), v4);
      startInOut->m_quad = _mm_add_ps(_mm_mul_ps(this->m_radius.m_real, v11), startInOut->m_quad);
    }
    else
    {
      endInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, this->m_radius.m_real), v11), v4);
      startInOut->m_quad = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps((__m128)0i64, this->m_radius.m_real), v11),
                             startInOut->m_quad);
    }
  }
}

// File Line: 492
// RVA: 0xC22400
void __fastcall hkaiStringPulling::convertToTangentCrossed(hkaiStringPulling *this, hkVector4f *startInOut, hkVector4f *endInOut, hkaiStringPulling::Side side)
{
  hkVector4f *v4; // rbx
  hkaiStringPulling::Side v5; // edi
  hkaiStringPulling *v6; // rsi
  hkVector4f _start; // [rsp+20h] [rbp-18h]

  v4 = startInOut;
  v5 = side;
  v6 = this;
  _start.m_quad = _mm_add_ps(
                    _mm_mul_ps(_mm_sub_ps(endInOut->m_quad, startInOut->m_quad), (__m128)xmmword_141A711B0),
                    startInOut->m_quad);
  hkaiStringPulling::convertToTangent(this, &_start, endInOut, side);
  hkaiStringPulling::convertToTangent(v6, &_start, v4, v5);
}

// File Line: 501
// RVA: 0xC226E0
signed __int64 __fastcall hkaiStringPulling::getIndex(hkaiStringPulling *this, int i, hkaiStringPulling::Side side)
{
  hkaiStringPulling::PathEdgeCache::PathEdge *v3; // rax
  signed __int64 result; // rax

  if ( i < 0 || i >= this->m_pathLength )
    return 0xFFFFFFFFi64;
  v3 = &this->m_pathEdgeCache.m_pathEdges.m_data[(signed __int64)i];
  if ( side == 1 )
    result = (unsigned int)v3->m_incomingEdge.m_b;
  else
    result = (unsigned int)v3->m_incomingEdge.m_a;
  return result;
}

// File Line: 514
// RVA: 0xC22470
__int64 __fastcall hkaiStringPulling::isUserEdge(hkaiStringPulling *this, int i)
{
  __int64 result; // rax

  if ( i < 0 || i >= this->m_pathLength )
    result = 0i64;
  else
    result = this->m_pathEdgeCache.m_pathEdges.m_data[(signed __int64)i].m_incomingEdge.m_flags.m_storage & 0x10;
  return result;
}

// File Line: 525
// RVA: 0xC22550
__int64 __fastcall hkaiStringPulling::getUserEdgeVertexPosition(hkaiStringPulling *this, int edgeIndex, hkaiStringPulling::Side side, hkVector4f *vertexOut)
{
  int v4; // er14
  int v5; // er15
  hkaiStringPulling *v6; // rbp
  int v7; // esi
  signed __int64 v8; // rax
  int v9; // edx
  hkaiStringPulling::Funnel *v10; // rcx
  __m128 *v11; // rax
  hkVector4f *v12; // r12
  hkaiStringPulling::Side v13; // er13
  unsigned __int8 v14; // bl
  __m128 v15; // xmm8
  __m128 v16; // xmm7
  hkaiStringPulling::Vertex *v17; // rax
  hkaiStringPulling::Funnel *v18; // rcx
  int v19; // eax
  hkVector4f v20; // xmm6
  __m128 v21; // xmm6
  hkaiStringPulling::Vertex *v22; // rax
  int v23; // eax
  hkVector4f *v24; // rcx
  __int64 result; // rax
  hkVector4f b; // [rsp+20h] [rbp-78h]
  hkVector4f p; // [rsp+30h] [rbp-68h]

  v4 = this->m_funnel.m_start;
  v5 = edgeIndex;
  v6 = this;
  v7 = this->m_funnel.m_data.m_size - 1;
  v8 = (signed __int64)edgeIndex << 7;
  v9 = this->m_funnel.m_data.m_size - 1;
  v10 = &this->m_funnel;
  v11 = (__m128 *)(*(_QWORD *)&v10[-2].m_start + v8);
  v12 = vertexOut;
  v13 = side;
  v14 = 0;
  v15 = v11[3];
  v16 = v11[4];
  b.m_quad = v11[3];
  p.m_quad = v16;
  v17 = hkaiStringPulling::Funnel::operator[](v10, v9);
  v18 = &v6->m_funnel;
  if ( v17->m_index == v5 )
  {
    if ( !hkaiStringPulling::Funnel::operator[](v18, v7)->m_userEdgeSwapped.m_bool )
      goto LABEL_13;
  }
  else if ( hkaiStringPulling::Funnel::operator[](v18, v4)->m_index == v5 )
  {
    if ( !hkaiStringPulling::Funnel::operator[](&v6->m_funnel, v4)->m_userEdgeSwapped.m_bool )
      goto LABEL_13;
  }
  else
  {
    v19 = v6->m_funnel.m_apex;
    if ( v7 == v19 || v4 == v19 )
    {
      v22 = hkaiStringPulling::Funnel::getApex(&v6->m_funnel);
      LOBYTE(v23) = hkaiStringPulling::getSide(v6, &v22->m_pos, &b, &p);
      if ( v23 )
        goto LABEL_13;
    }
    else
    {
      v20.m_quad = (__m128)hkaiStringPulling::Funnel::operator[](&v6->m_funnel, v4)->m_pos;
      v21 = _mm_mul_ps(
              _mm_sub_ps(v20.m_quad, hkaiStringPulling::Funnel::operator[](&v6->m_funnel, v7)->m_pos.m_quad),
              _mm_sub_ps(v16, v15));
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) >= 0.0 )
        goto LABEL_13;
    }
  }
  v14 = 1;
  p.m_quad = v15;
  b.m_quad = v16;
LABEL_13:
  v24 = &b;
  if ( v13 )
    v24 = &p;
  result = v14;
  *v12 = (hkVector4f)v24->m_quad;
  return result;
}

// File Line: 592
// RVA: 0xC224A0
signed __int64 __fastcall hkaiStringPulling::getVertexPosition(hkaiStringPulling *this, int edgeIndex, hkaiStringPulling::Side side, hkVector4f *vertexOut, bool *userEdgeSwapped)
{
  __int64 v5; // rsi
  hkVector4f *v6; // rbx
  hkaiStringPulling::Side v7; // ebp
  hkaiStringPulling *v8; // rdi
  signed __int64 result; // rax
  hkaiStringPulling::PathEdgeCache::PathEdge *v10; // rax
  hkVector4f v11; // xmm0

  v5 = edgeIndex;
  v6 = vertexOut;
  *userEdgeSwapped = 0;
  v7 = side;
  v8 = this;
  if ( edgeIndex >= this->m_pathLength )
  {
    result = 0i64;
    *vertexOut = this->m_endPoint;
  }
  else if ( (unsigned int)hkaiStringPulling::isUserEdge(this, edgeIndex) )
  {
    *userEdgeSwapped = hkaiStringPulling::getUserEdgeVertexPosition(v8, v5, v7, v6);
    result = 1i64;
  }
  else
  {
    v10 = &v8->m_pathEdgeCache.m_pathEdges.m_data[v5];
    if ( v7 == 1 )
      v11.m_quad = (__m128)v10->m_incomingEdgePointB_GC;
    else
      v11.m_quad = (__m128)v10->m_incomingEdgePointA_GC;
    result = 1i64;
    *v6 = (hkVector4f)v11.m_quad;
  }
  return result;
}

// File Line: 614
// RVA: 0xC22710
void __fastcall hkaiStringPulling::getVertex(hkaiStringPulling *this, hkaiStringPulling::Vertex *inOut)
{
  hkaiStringPulling::Vertex *v2; // rbx
  hkaiStringPulling *v3; // rdi
  __m128 v4; // xmm2
  bool v5; // al
  hkVector4f vertexOut; // [rsp+30h] [rbp-18h]
  bool userEdgeSwapped; // [rsp+50h] [rbp+8h]

  v2 = inOut;
  v3 = this;
  hkaiStringPulling::getVertexPosition(
    this,
    inOut->m_index,
    (hkaiStringPulling::Side)(unsigned __int8)inOut->m_side.m_storage,
    &vertexOut,
    &userEdgeSwapped);
  v4 = vertexOut.m_quad;
  v2->m_center = (hkVector4f)vertexOut.m_quad;
  v2->m_clearanceIsNegative.m_bool = COERCE_FLOAT(_mm_shuffle_ps(v4, v4, 255)) < 0.0;
  v5 = userEdgeSwapped;
  v2->m_pos.m_quad = v4;
  v2->m_userEdgeSwapped.m_bool = v5;
  if ( v2->m_index < v3->m_pathLength )
  {
    if ( (unsigned int)hkaiStringPulling::isUserEdge(v3, v2->m_index) )
      v2->m_userEdge.m_bool = 1;
  }
  else
  {
    v2->m_side.m_storage = -1;
  }
}

// File Line: 634
// RVA: 0xC22A80
bool __fastcall hkaiStringPulling::isShared(hkaiStringPulling *this, int i, hkaiStringPulling::Side side)
{
  hkaiStringPulling::Side v3; // edi
  hkaiStringPulling::PathEdgeCache::PathEdge *v5; // rbx
  int v6; // edx
  int v7; // ecx

  v3 = side;
  if ( i + 1 >= this->m_pathLength )
    return 0;
  v5 = &this->m_pathEdgeCache.m_pathEdges.m_data[(signed __int64)i];
  if ( v5->m_incomingEdge.m_flags.m_storage & 0x40 )
    return 0;
  v6 = hkaiStringPulling::getIndex(this, i + 1, side);
  if ( v3 == 1 )
    v7 = v5->m_oppositeEdge.m_a;
  else
    v7 = v5->m_oppositeEdge.m_b;
  return v7 == v6;
}

// File Line: 655
// RVA: 0xC227A0
void __fastcall hkaiStringPulling::genericTangent(hkaiStringPulling *this, hkVector4f *start, hkaiStringPulling::Side startSide, hkVector4f *end, hkaiStringPulling::Side endSide)
{
  if ( startSide == -1 )
  {
    hkaiStringPulling::convertToTangent(this, start, end, endSide);
  }
  else if ( endSide == -1 )
  {
    if ( startSide )
    {
      if ( startSide == 1 )
        hkaiStringPulling::convertToTangent(this, end, start, 0);
      else
        hkaiStringPulling::convertToTangent(this, end, start, (hkaiStringPulling::Side)-1);
    }
    else
    {
      hkaiStringPulling::convertToTangent(this, end, start, RIGHT);
    }
  }
  else if ( startSide == endSide )
  {
    hkaiStringPulling::convertToTangentNorm(this, start, end, startSide);
  }
  else
  {
    hkaiStringPulling::convertToTangentCrossed(this, start, end, endSide);
  }
}

// File Line: 675
// RVA: 0xC22820
void __fastcall hkaiStringPulling::genericTangent(hkaiStringPulling *this, hkaiStringPulling::Vertex *start, hkaiStringPulling::Vertex *end)
{
  hkaiStringPulling::Vertex *v3; // r9
  hkaiStringPulling::Side v4; // er8
  hkaiStringPulling *v5; // r10
  hkaiStringPulling::Side endSide; // eax
  unsigned __int8 v7; // cl

  v3 = end;
  v4 = -1;
  v5 = this;
  if ( v3->m_userEdge.m_bool
    || (LOBYTE(endSide) = v3->m_side.m_storage, (_BYTE)endSide == -1)
    || (endSide = (unsigned __int8)endSide, !v3->m_clearanceIsNegative.m_bool) )
  {
    endSide = -1;
  }
  if ( !start->m_userEdge.m_bool )
  {
    v7 = start->m_side.m_storage;
    if ( v7 != -1 )
    {
      if ( start->m_clearanceIsNegative.m_bool )
        v4 = v7;
    }
  }
  hkaiStringPulling::genericTangent(v5, &start->m_pos, v4, &v3->m_pos, endSide);
}

// File Line: 681
// RVA: 0xC234E0
__int64 __fastcall hkaiStringPulling::handleUserEdge(hkaiStringPulling *this, hkaiStringPulling::Vertex *vertex, int index)
{
  hkaiStringPulling *v3; // rdi
  __int64 result; // rax
  int v5; // er14
  hkaiStringPulling::Funnel *v6; // r15
  hkaiStringPulling::Vertex *v7; // rax
  int v8; // er13
  hkaiStringPulling::Funnel *v9; // rsi
  hkVector4f v10; // xmm7
  hkaiStringPulling::Vertex *v11; // rax
  signed int v12; // esi
  int *v13; // r15
  __m128 v14; // xmm7
  hkaiStringPulling::Side v15; // er8
  int v16; // ebx
  hkaiStringPulling::Vertex *v17; // rax
  hkaiStringPulling::Vertex *v18; // rax
  __m128 v19; // xmm2
  int v20; // eax
  signed int v21; // ecx
  signed __int64 v22; // r8
  hkaiStringPulling::Vertex *v23; // rax
  signed __int64 v24; // r8
  __m128i v25; // xmm6
  __m128 v26; // xmm8
  hkVector4f v27; // xmm9
  char v28; // al
  __m128 v29; // xmm0
  int *v30; // rsi
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm0
  __m128 v35; // xmm5
  __m128 v36; // xmm7
  __m128 v37; // xmm5
  hkVector4f v38; // xmm8
  hkVector4f v39; // xmm0
  __m128 v40; // xmm8
  __m128 v41; // xmm1
  __m128 v42; // xmm7
  int v43; // ebx
  hkOstream *v44; // rax
  hkOstream *v45; // rax
  hkaiStringPulling::Vertex *v46; // rax
  hkVector4f v47; // xmm6
  hkVector4f v48; // xmm0
  hkaiStringPulling::Vertex *v49; // rax
  signed __int64 v50; // rax
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm7
  signed __int64 v54; // rcx
  hkaiStringPulling::Funnel::Iterator v55; // [rsp+20h] [rbp-E0h]
  hkaiStringPulling::Funnel::Iterator other; // [rsp+30h] [rbp-D0h]
  int v57; // [rsp+40h] [rbp-C0h]
  int v58; // [rsp+44h] [rbp-BCh]
  hkaiStringPulling::Funnel::Iterator v59; // [rsp+48h] [rbp-B8h]
  hkaiStringPulling::Vertex start; // [rsp+60h] [rbp-A0h]
  hkaiStringPulling::Funnel::Iterator v61; // [rsp+90h] [rbp-70h]
  hkaiStringPulling::Vertex end; // [rsp+C0h] [rbp-40h]
  char buf; // [rsp+F0h] [rbp-10h]
  hkaiStringPulling::Vertex *v64; // [rsp+378h] [rbp+278h]
  int i; // [rsp+380h] [rbp+280h]
  bool v66; // [rsp+388h] [rbp+288h]

  i = index;
  v64 = vertex;
  v3 = this;
  result = hkaiStringPulling::isUserEdge(this, index);
  if ( (_DWORD)result )
  {
    hkaiStringPulling::Funnel::Iterator::Iterator(&v55, &v3->m_funnel, RIGHT, -1);
    hkaiStringPulling::Funnel::Iterator::Iterator(&v59, &v3->m_funnel, 0, -1);
    v5 = v59.m_funnelIndex;
    v6 = v59.m_funnel;
    v7 = hkaiStringPulling::Funnel::operator[](v59.m_funnel, v59.m_funnelIndex);
    v8 = v55.m_funnelIndex;
    v9 = v55.m_funnel;
    if ( hkaiStringPulling::Funnel::operator[](v55.m_funnel, v55.m_funnelIndex)->m_index != v7->m_index )
      return 1i64;
    v66 = hkaiStringPulling::Funnel::operator[](v9, v8)->m_userEdgeSwapped.m_bool != 0;
    v10.m_quad = (__m128)hkaiStringPulling::Funnel::operator[](v9, v8)->m_pos;
    v11 = hkaiStringPulling::Funnel::operator[](v6, v5);
    v12 = 0;
    v13 = &v57;
    v14 = _mm_sub_ps(v10.m_quad, v11->m_pos.m_quad);
    do
    {
      if ( v12 )
      {
        if ( v12 == 1 )
          v15 = 0;
        else
          v15 = -1;
      }
      else
      {
        v15 = 1;
      }
      hkaiStringPulling::Funnel::Iterator::Iterator(&v61, &v3->m_funnel, v15, -1);
      v16 = v3->m_funnel.m_apex;
      v61.m_funnelIndex = v3->m_funnel.m_apex;
      _mm_store_si128((__m128i *)&other, (__m128i)v61);
      hkaiStringPulling::Funnel::Iterator::operator++(&other, 0);
      if ( (unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&other) )
      {
        while ( 1 )
        {
          v17 = hkaiStringPulling::Funnel::operator[](v61.m_funnel, v16);
          *(_OWORD *)&start.m_index = *(_OWORD *)&v17->m_index;
          start.m_pos = v17->m_pos;
          start.m_center = v17->m_center;
          v18 = hkaiStringPulling::Funnel::operator[](other.m_funnel, other.m_funnelIndex);
          *(_OWORD *)&end.m_index = *(_OWORD *)&v18->m_index;
          end.m_pos = v18->m_pos;
          end.m_center = v18->m_center;
          hkaiStringPulling::genericTangent(v3, &start, &end);
          v19 = _mm_mul_ps(_mm_sub_ps(end.m_pos.m_quad, start.m_pos.m_quad), v14);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v19, v19, 170))) < 0.0 == (v12 == 0) )
            break;
          hkaiStringPulling::addSegmentToPath(v3, &start, &end);
          hkaiStringPulling::Funnel::Iterator::operator=(&v61, &other);
          _mm_store_si128((__m128i *)&other, (__m128i)v61);
          hkaiStringPulling::Funnel::Iterator::operator++(&other, 0);
          if ( !(unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&other) )
            goto LABEL_14;
          v16 = v61.m_funnelIndex;
        }
        *v13 = v16;
      }
      else
      {
LABEL_14:
        *v13 = -1;
      }
      ++v12;
      ++v13;
    }
    while ( v12 < 2 );
    v20 = v3->m_funnel.m_apex;
    if ( v58 == v20 )
    {
      v21 = 0;
    }
    else
    {
      if ( v57 != v20 )
      {
        hkErrStream::hkErrStream((hkErrStream *)&v61, &buf, 512);
        v44 = hkOstream::operator<<((hkOstream *)&v61, "Cannot handle user edge ");
        v43 = i;
        v45 = hkOstream::operator<<(v44, i);
        hkOstream::operator<<(v45, ". Is this edge not completely contained in its face?");
        hkError::messageWarning(773745910, &buf, "NavMesh\\Smoothing\\hkaiStringPulling.cpp", 761);
        hkOstream::~hkOstream((hkOstream *)&v61);
        v42 = (__m128)xmmword_141A711B0;
        v46 = hkaiStringPulling::Funnel::operator[](v55.m_funnel, v8);
        *(_OWORD *)&start.m_index = *(_OWORD *)&v46->m_index;
        start.m_pos = v46->m_pos;
        v47.m_quad = (__m128)start.m_pos;
        start.m_center = v46->m_center;
        v48.m_quad = (__m128)hkaiStringPulling::Funnel::operator[](v59.m_funnel, v59.m_funnelIndex)->m_pos;
        start.m_side.m_storage = -1;
        start.m_pos.m_quad = _mm_add_ps(
                               v47.m_quad,
                               _mm_mul_ps(_mm_sub_ps(v48.m_quad, v47.m_quad), (__m128)xmmword_141A711B0));
        v49 = hkaiStringPulling::Funnel::getApex(&v3->m_funnel);
        hkaiStringPulling::addSegmentToPath(v3, v49, &start);
        v30 = &v64->m_index;
LABEL_32:
        if ( v66 )
          v42 = _mm_sub_ps(query.m_quad, v42);
        hkaiStringPulling::Funnel::clear(&v3->m_funnel);
        LOWORD(v61.m_funnelIndex) = 255;
        *(_WORD *)((char *)&v61.m_funnelIndex + 3) = 1;
        v50 = (signed __int64)&v3->m_pathEdgeCache.m_pathEdges.m_data[(signed __int64)v43];
        v51 = *(__m128 *)(v50 + 96);
        v52 = *(__m128 *)(v50 + 80);
        v61.m_side = *v30;
        LODWORD(v50) = v3->m_funnel.m_data.m_capacityAndFlags;
        v53 = _mm_add_ps(
                _mm_mul_ps(_mm_max_ps(_mm_min_ps(v42, query.m_quad), aabbOut.m_quad), _mm_sub_ps(v52, v51)),
                v51);
        BYTE2(v61.m_funnelIndex) = COERCE_FLOAT(_mm_shuffle_ps(v53, v53, 255)) < 0.0;
        if ( v3->m_funnel.m_data.m_size == (v50 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            &v3->m_funnel.m_data,
            48);
        v54 = (signed __int64)&v3->m_funnel.m_data.m_data[v3->m_funnel.m_data.m_size];
        if ( v54 )
        {
          *(hkaiStringPulling::Funnel::Iterator *)v54 = v61;
          *(__m128 *)(v54 + 16) = v53;
          *(__m128 *)(v54 + 32) = v53;
        }
        ++v3->m_funnel.m_data.m_size;
        v3->m_funnel.m_apex = 0;
        return 1i64;
      }
      v21 = 1;
    }
    v22 = *(&v57 + v21);
    if ( (_DWORD)v22 == -1 )
    {
      v43 = i;
      v30 = &v64->m_index;
      if ( v21 == 1 )
        v42 = query.m_quad;
      else
        v42 = aabbOut.m_quad;
    }
    else
    {
      v23 = v3->m_funnel.m_data.m_data;
      v24 = v22;
      *(_OWORD *)&end.m_index = *(_OWORD *)&v23[v24].m_index;
      v25 = *(__m128i *)&end.m_index;
      v26 = v23[v24].m_pos.m_quad;
      end.m_pos = v23[v24].m_pos;
      end.m_center = v23[v24].m_center;
      v27.m_quad = (__m128)hkaiStringPulling::Funnel::operator[](v59.m_funnel, v59.m_funnelIndex)->m_pos;
      v28 = _mm_cvtsi128_si32(_mm_srli_si128(v25, 4));
      if ( v28 == 1 )
      {
        v55 = (hkaiStringPulling::Funnel::Iterator)_mm_sub_ps((__m128)0i64, query.m_quad);
      }
      else
      {
        if ( v28 )
          v29 = aabbOut.m_quad;
        else
          v29 = query.m_quad;
        v55 = (hkaiStringPulling::Funnel::Iterator)v29;
        _mm_store_si128((__m128i *)&v55, (__m128i)v29);
      }
      v30 = &v64->m_index;
      v31 = _mm_mul_ps(v14, v14);
      v32 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
              _mm_shuffle_ps(v31, v31, 170));
      v33 = _mm_rsqrt_ps(v32);
      v34 = _mm_mul_ps(v3->m_radius.m_real, (__m128)v55);
      v35 = _mm_andnot_ps(
              _mm_cmpleps(v32, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                _mm_mul_ps(*(__m128 *)_xmm, v33)));
      start.m_pos = v64->m_pos;
      v36 = _mm_mul_ps(v14, v35);
      v37 = _mm_mul_ps(v35, v32);
      v38.m_quad = _mm_add_ps(v26, _mm_mul_ps(v34, v36));
      *(_OWORD *)&start.m_index = *(_OWORD *)&v64->m_index;
      v39.m_quad = (__m128)v64->m_center;
      end.m_pos = (hkVector4f)v38.m_quad;
      start.m_center = (hkVector4f)v39.m_quad;
      v40 = _mm_mul_ps(_mm_sub_ps(v38.m_quad, v27.m_quad), v36);
      v41 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
              _mm_shuffle_ps(v40, v40, 170));
      start.m_pos.m_quad = _mm_add_ps(_mm_mul_ps(v36, v41), v27.m_quad);
      v42 = _mm_andnot_ps(_mm_cmpeqps(v37, (__m128)0i64), _mm_div_ps(v41, v37));
      hkaiStringPulling::addSegmentToPath(v3, &end, &start);
      v43 = i;
    }
    goto LABEL_32;
  }
  return result;
}

// File Line: 847
// RVA: 0xC23B30
__int64 __fastcall hkaiStringPulling::isCloser(hkaiStringPulling *this, hkaiStringPulling::Vertex *s, hkaiStringPulling::Vertex *e, hkaiStringPulling::Vertex *p, int lastEdgeIndex)
{
  hkVector4f v5; // xmm4
  hkVector4f *v6; // r15
  hkaiStringPulling::Vertex *v7; // r14
  hkaiStringPulling::Vertex *v8; // rdi
  hkaiStringPulling *v9; // rsi
  unsigned int v10; // ebx
  __m128 v11; // xmm7
  __m128 v12; // xmm6
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm7
  __m128 v17; // xmm6
  __m128 v18; // xmm2
  __m128 v20; // xmm7
  __m128 v21; // xmm6
  int v22; // eax
  hkVector4f v23; // [rsp+30h] [rbp-68h]
  hkVector4f vertexOut; // [rsp+40h] [rbp-58h]
  bool userEdgeSwapped; // [rsp+A0h] [rbp+8h]

  v5.m_quad = (__m128)this->m_up;
  v6 = &s->m_pos;
  v7 = p;
  v8 = e;
  v9 = this;
  v10 = 1;
  v11 = _mm_sub_ps(p->m_pos.m_quad, s->m_pos.m_quad);
  v12 = _mm_sub_ps(e->m_pos.m_quad, s->m_pos.m_quad);
  v13 = _mm_mul_ps(this->m_up.m_quad, v11);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_mul_ps(this->m_up.m_quad, v12);
  v16 = _mm_add_ps(v11, _mm_mul_ps(_mm_sub_ps((__m128)0i64, v14), v5.m_quad));
  v17 = _mm_add_ps(
          v12,
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                _mm_shuffle_ps(v15, v15, 170))),
            v5.m_quad));
  if ( lastEdgeIndex != -1 )
  {
    hkaiStringPulling::getVertexPosition(this, lastEdgeIndex, 0, &vertexOut, &userEdgeSwapped);
    hkaiStringPulling::getVertexPosition(v9, lastEdgeIndex, RIGHT, &v23, &userEdgeSwapped);
    v18 = _mm_mul_ps(_mm_sub_ps(v23.m_quad, vertexOut.m_quad), v17);
    if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v18, v18, 170))) > 0.0 == (v8->m_side.m_storage == 0) )
      return 0i64;
  }
  v20 = _mm_mul_ps(v16, v16);
  v21 = _mm_mul_ps(v17, v17);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170))) >= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85))
                                                                             + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                                                                     + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170)))
    || (LOBYTE(v22) = hkaiStringPulling::getSide(v9, v6, &v8->m_center, &v7->m_center),
        v22 == (unsigned __int8)v8->m_side.m_storage) )
  {
    v10 = 0;
  }
  return v10;
}

// File Line: 885
// RVA: 0xC23CF0
_BOOL8 __fastcall hkaiStringPulling::isUndefinedTangentVertexAddable(hkaiStringPulling *this, hkaiStringPulling::Vertex *wedgeStart, hkaiStringPulling::Vertex *wedgeEnd, hkaiStringPulling::Vertex *p)
{
  hkVector4f v4; // xmm1
  hkaiStringPulling::Vertex *v5; // rsi
  hkaiStringPulling::Vertex *v6; // rbx
  hkaiStringPulling *v7; // r14
  hkVector4f v8; // xmm0
  hkVector4f v9; // xmm1
  unsigned __int8 v10; // al
  __m128 v11; // xmm7
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  int v15; // edi
  int v16; // eax
  bool v17; // bp
  int v18; // eax
  hkVector4f b; // [rsp+20h] [rbp-A8h]
  hkVector4f pa; // [rsp+30h] [rbp-98h]
  hkaiStringPulling::Vertex end; // [rsp+40h] [rbp-88h]
  __int128 v23; // [rsp+70h] [rbp-58h]
  __m128 v24; // [rsp+80h] [rbp-48h]
  hkVector4f v25; // [rsp+90h] [rbp-38h]

  v4.m_quad = (__m128)wedgeEnd->m_pos;
  v5 = wedgeEnd;
  v6 = p;
  v7 = this;
  *(_OWORD *)&end.m_index = *(_OWORD *)&wedgeEnd->m_index;
  v8.m_quad = (__m128)wedgeEnd->m_center;
  end.m_pos = (hkVector4f)v4.m_quad;
  v9.m_quad = (__m128)wedgeStart->m_pos;
  end.m_center = (hkVector4f)v8.m_quad;
  v23 = *(_OWORD *)&wedgeStart->m_index;
  v25.m_quad = (__m128)wedgeStart->m_center;
  v24 = v9.m_quad;
  hkaiStringPulling::genericTangent(this, (hkaiStringPulling::Vertex *)&v23, &end);
  v10 = v5->m_side.m_storage;
  v11 = _mm_sub_ps(end.m_pos.m_quad, v24);
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v7->m_up.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v7->m_up.m_quad, v7->m_up.m_quad, 201), v11));
  v13 = _mm_shuffle_ps(v12, v12, 201);
  if ( v10 == 1 )
    v13 = _mm_xor_ps(v13, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  v14 = v5->m_center.m_quad;
  v15 = v10;
  b.m_quad = _mm_add_ps(v5->m_center.m_quad, v13);
  LOBYTE(v16) = hkaiStringPulling::getSide(v7, &v5->m_center, &b, &v6->m_center);
  _mm_store_si128((__m128i *)&pa, (__m128i)v6->m_center.m_quad);
  b.m_quad = _mm_sub_ps(v14, v11);
  v17 = v16 != v15;
  LOBYTE(v18) = hkaiStringPulling::getSide(v7, &b, &v5->m_center, &pa);
  return v18 == v15 || !v17;
}

// File Line: 921
// RVA: 0xC22890
char __fastcall hkaiStringPulling::checkTermination(hkaiStringPulling *this, hkaiStringPulling::Vertex *vertex, hkaiStringPulling::Side side, int index)
{
  hkaiStringPulling::Side v4; // edi
  hkaiStringPulling::Vertex *v5; // rsi
  hkaiStringPulling *v6; // rbx
  hkaiStringPulling::Side v8; // er8
  hkaiStringPulling::Vertex *v9; // rax
  hkaiStringPulling::Vertex *v10; // rax
  int v11; // eax
  char v12; // cl
  __int128 v13; // xmm0
  hkVector4f v14; // xmm1
  char v15; // al
  hkVector4f v16; // xmm0
  char v17; // al
  hkVector4f v18; // xmm1
  hkVector4f v19; // xmm0
  char v20; // al
  hkaiStringPulling::Funnel::Iterator v21; // [rsp+20h] [rbp-59h]
  hkaiStringPulling::Vertex start; // [rsp+30h] [rbp-49h]
  hkaiStringPulling::Funnel::Iterator v23; // [rsp+60h] [rbp-19h]
  hkaiStringPulling::Vertex end; // [rsp+70h] [rbp-9h]
  hkaiStringPulling::Vertex b; // [rsp+A0h] [rbp+27h]

  v4 = side;
  v5 = vertex;
  v6 = this;
  if ( hkaiStringPulling::handleUserEdge(this, vertex, index) || v5->m_index != v6->m_pathLength )
    return 0;
  if ( v4 )
  {
    if ( v4 == 1 )
      v8 = 0;
    else
      v8 = -1;
  }
  else
  {
    v8 = 1;
  }
  hkaiStringPulling::Funnel::Iterator::Iterator(&v23, &v6->m_funnel, v8, v6->m_funnel.m_apex);
  _mm_store_si128((__m128i *)&v21, (__m128i)v23);
  hkaiStringPulling::Funnel::Iterator::operator++(&v21, 0);
  if ( (unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&v21) )
  {
    while ( 1 )
    {
      v9 = hkaiStringPulling::Funnel::operator[](v23.m_funnel, v23.m_funnelIndex);
      *(_OWORD *)&start.m_index = *(_OWORD *)&v9->m_index;
      start.m_pos = v9->m_pos;
      start.m_center = v9->m_center;
      v10 = hkaiStringPulling::Funnel::operator[](v21.m_funnel, v21.m_funnelIndex);
      *(_OWORD *)&end.m_index = *(_OWORD *)&v10->m_index;
      end.m_pos = v10->m_pos;
      end.m_center = v10->m_center;
      hkaiStringPulling::genericTangent(v6, &start, &end);
      if ( (unsigned int)hkaiStringPulling::undefinedTangent(v6, &start, v5) )
        break;
      hkaiStringPulling::Funnel::Iterator::operator++(&v23, 0);
      hkaiStringPulling::Funnel::Iterator::operator++(&v21, 0);
      v11 = hkaiStringPulling::Funnel::Iterator::isValid(&v21);
      v12 = end.m_type.m_storage;
      if ( !v11 )
        v12 = 2;
      end.m_type.m_storage = v12;
      hkaiStringPulling::addSegmentToPath(v6, &start, &end);
      if ( !(unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&v21) )
        return 1;
    }
    v13 = *(_OWORD *)&v5->m_index;
    v14.m_quad = (__m128)v5->m_pos;
    start.m_index = v6->m_lastVertexInPath.m_index;
    v15 = v6->m_lastVertexInPath.m_side.m_storage;
    *(_OWORD *)&b.m_index = v13;
    v16.m_quad = (__m128)v5->m_center;
    b.m_pos = (hkVector4f)v14.m_quad;
    start.m_side.m_storage = v15;
    v17 = v6->m_lastVertexInPath.m_type.m_storage;
    v18.m_quad = (__m128)v6->m_lastVertexInPath.m_center;
    b.m_center = (hkVector4f)v16.m_quad;
    v19.m_quad = (__m128)v6->m_lastVertexInPath.m_pos;
    start.m_type.m_storage = v17;
    start.m_clearanceIsNegative.m_bool = v6->m_lastVertexInPath.m_clearanceIsNegative.m_bool;
    v20 = v6->m_lastVertexInPath.m_userEdge.m_bool;
    start.m_pos = (hkVector4f)v19.m_quad;
    start.m_center = (hkVector4f)v18.m_quad;
    start.m_userEdge.m_bool = v20;
    start.m_userEdgeSwapped.m_bool = v6->m_lastVertexInPath.m_userEdgeSwapped.m_bool;
    hkaiStringPulling::addSegmentToPath(v6, &start, &b);
  }
  return 1;
}

// File Line: 975
// RVA: 0xC21F10
__int64 __fastcall hkaiStringPulling::undefinedTangent(hkaiStringPulling *this, hkaiStringPulling::Vertex *a, hkaiStringPulling::Vertex *b)
{
  signed int v3; // eax
  hkaiStringPulling *v4; // r11
  signed int v5; // er9
  unsigned __int8 v6; // cl
  unsigned int v7; // er10
  __m128 v8; // xmm3
  __m128 v9; // xmm6
  __m128 v10; // xmm2
  __m128 v11; // xmm6
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm1

  v3 = -1;
  v4 = this;
  if ( a->m_userEdge.m_bool
    || (LOBYTE(v5) = a->m_side.m_storage, (_BYTE)v5 == -1)
    || (v5 = (unsigned __int8)v5, !a->m_clearanceIsNegative.m_bool) )
  {
    v5 = -1;
  }
  if ( !b->m_userEdge.m_bool )
  {
    v6 = b->m_side.m_storage;
    if ( v6 != -1 )
    {
      if ( b->m_clearanceIsNegative.m_bool )
        v3 = v6;
    }
  }
  v7 = 0;
  if ( !((v5 == -1) ^ (v3 == -1)) )
    return 0i64;
  v8 = v4->m_up.m_quad;
  v9 = _mm_sub_ps(b->m_center.m_quad, a->m_center.m_quad);
  v10 = _mm_mul_ps(v8, v9);
  v11 = _mm_add_ps(
          v9,
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                _mm_shuffle_ps(v10, v10, 170))),
            v8));
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  LOBYTE(v7) = COERCE_FLOAT(
                 _mm_andnot_ps(
                   _mm_cmpleps(v13, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                       _mm_mul_ps(*(__m128 *)_xmm, v14)),
                     v13))) < v4->m_radius.m_real.m128_f32[0];
  return v7;
}

// File Line: 990
// RVA: 0xC24890
char __fastcall hkaiStringPulling::terminateOutput(hkaiStringPulling *this)
{
  hkaiPathWriter *v1; // rcx
  char result; // al

  v1 = this->m_writer;
  if ( v1->m_pathArrayOut || v1->m_totalNumOutput < v1->m_maxNumOutput )
  {
    hkaiPathWriter::addTerminatorToPathPointer(v1);
    result = 1;
  }
  else
  {
    hkaiPathWriter::addTerminatorToPathPointer(v1);
    result = 0;
  }
  return result;
}

// File Line: 1000
// RVA: 0xC24280
void __fastcall hkaiStringPulling::addVertexToPath(hkaiStringPulling *this, hkaiStringPulling::Vertex *a, char pointType)
{
  __int64 v3; // rax
  unsigned int edgeData; // er10
  hkaiStringPulling::Vertex *v5; // rsi
  hkaiStringPulling *v6; // rdi
  int v7; // ecx
  hkaiStringPulling::PathEdgeCache::PathEdge *v8; // rax
  signed __int64 v9; // rcx
  unsigned int v10; // er9
  __m128 v11; // xmm0
  __int64 v12; // rdx
  __int64 v13; // rcx
  hkaiStringPulling::PathEdgeCache::PathEdge *v14; // rax
  int v15; // er9
  hkaiPathWriter *v16; // rcx
  hkVector4f normal; // [rsp+30h] [rbp-18h]

  v3 = a->m_index;
  edgeData = 0;
  v5 = a;
  v6 = this;
  _mm_store_si128((__m128i *)&normal, (__m128i)aabbOut.m_quad);
  if ( (signed int)v3 < 0 || (v7 = this->m_pathLength) == 0 )
  {
    v10 = v6->m_startFaceKey;
    v11 = v6->m_pathEdgeCache.m_startFaceNormal.m_quad;
    goto LABEL_11;
  }
  if ( (signed int)v3 >= v7 )
  {
    v8 = v6->m_pathEdgeCache.m_pathEdges.m_data;
    v9 = (signed __int64)(v7 - 1) << 7;
    v10 = *(unsigned int *)((char *)&v8->m_incomingEdge.m_oppositeFace + v9);
    v11 = *(__m128 *)((char *)&v8->m_faceNormal.m_quad + v9);
LABEL_11:
    v15 = v10 >> 22;
    goto LABEL_12;
  }
  v12 = v3;
  if ( pointType & 2 )
  {
    v13 = v3;
    v14 = v6->m_pathEdgeCache.m_pathEdges.m_data;
    v13 <<= 7;
    edgeData = *(int *)((char *)&v14->m_oppositeEdgeData + v13);
    v15 = *(unsigned int *)((char *)&v14->m_incomingEdge.m_oppositeEdge + v13) >> 22;
    v11 = v14[v12].m_faceNormal.m_quad;
  }
  else
  {
    v15 = v6->m_pathEdgeCache.m_pathEdgeKeys->m_data[v3] >> 22;
    if ( v5->m_userEdge.m_bool )
      edgeData = v6->m_pathEdgeCache.m_pathEdges.m_data[v3].m_incomingEdgeData;
    v11 = v6->m_pathEdgeCache.m_pathEdges.m_data[v3].m_faceNormal.m_quad;
  }
LABEL_12:
  v16 = v6->m_writer;
  normal.m_quad = v11;
  hkaiPathWriter::addPointToPath(v16, &v5->m_pos, &normal, v15, edgeData, pointType);
  v6->m_lastVertexInPath.m_index = v5->m_index;
  v6->m_lastVertexInPath.m_side.m_storage = v5->m_side.m_storage;
  v6->m_lastVertexInPath.m_type.m_storage = v5->m_type.m_storage;
  v6->m_lastVertexInPath.m_clearanceIsNegative.m_bool = v5->m_clearanceIsNegative.m_bool;
  v6->m_lastVertexInPath.m_userEdge.m_bool = v5->m_userEdge.m_bool;
  v6->m_lastVertexInPath.m_userEdgeSwapped.m_bool = v5->m_userEdgeSwapped.m_bool;
  v6->m_lastVertexInPath.m_pos = v5->m_pos;
  v6->m_lastVertexInPath.m_center = v5->m_center;
}

// File Line: 1050
// RVA: 0xC243D0
void __fastcall hkaiStringPulling::addSegmentToPath(hkaiStringPulling *this, hkaiStringPulling::Vertex *a, hkaiStringPulling::Vertex *b)
{
  char v3; // bl
  hkaiStringPulling::Vertex *v4; // r14
  hkaiStringPulling::Vertex *v5; // r15
  hkaiStringPulling *v6; // rdi
  char v7; // r12
  int v8; // ebx
  signed __int64 v9; // rsi
  __m128 v10; // xmm10
  hkaiStringPulling::PathEdgeCache::PathEdge *v11; // rax
  __m128 v12; // xmm13
  __m128 v13; // xmm7
  __m128 v14; // xmm5
  __m128 v15; // xmm11
  __m128 v16; // xmm12
  __m128 v17; // xmm8
  __m128 v18; // xmm8
  __m128 v19; // xmm1
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __m128 v22; // xmm8
  __m128 v23; // xmm2
  __m128 v24; // xmm8
  __m128 v25; // xmm1
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  bool v30; // cf
  __m128 v31; // xmm1
  __m128 v32; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm2
  __m128 v36; // xmm11
  __m128 v37; // xmm5
  __m128 v38; // xmm5
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm5
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 v46; // xmm4
  __m128 v47; // xmm1
  __m128 v48; // xmm11
  __m128 v49; // xmm7
  float v50; // xmm2_4
  hkaiStringPulling::Vertex aa; // [rsp+20h] [rbp-E0h]
  hkaiStringPulling::Vertex projOut; // [rsp+50h] [rbp-B0h]
  hkaiStringPulling::Vertex v53; // [rsp+80h] [rbp-80h]

  v3 = 4;
  if ( a->m_userEdge.m_bool )
    v3 = 6;
  v4 = b;
  v5 = a;
  v6 = this;
  v7 = (b->m_userEdge.m_bool != 0) + 8;
  if ( !this->m_project )
  {
    hkaiStringPulling::addVertexToPath(this, a, v3);
    hkaiStringPulling::addVertexToPath(v6, v4, v7);
    return;
  }
  projOut.m_index = -2;
  *(_DWORD *)&projOut.m_side.m_storage = 255;
  projOut.m_userEdgeSwapped.m_bool = 0;
  hkaiStringPulling::projectSegmentEndpoint(this, a, &projOut);
  hkaiStringPulling::addVertexToPath(v6, &projOut, v3);
  v8 = v5->m_index + 1;
  if ( v8 <= v4->m_index )
  {
    v9 = (signed __int64)v8 << 7;
    do
    {
      if ( v8 >= v6->m_pathLength )
        break;
      v10 = v6->m_up.m_quad;
      v11 = v6->m_pathEdgeCache.m_pathEdges.m_data;
      v12 = *(__m128 *)((char *)&v11->m_incomingEdgePointA_GC.m_quad + v9);
      v13 = _mm_sub_ps(*(__m128 *)((char *)&v11->m_incomingEdgePointB_GC.m_quad + v9), v12);
      v14 = v5->m_pos.m_quad;
      v15 = v4->m_pos.m_quad;
      v16 = _mm_shuffle_ps(v13, v13, 201);
      v17 = _mm_sub_ps(_mm_mul_ps(v6->m_up.m_quad, v16), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v13));
      v18 = _mm_shuffle_ps(v17, v17, 201);
      v19 = _mm_mul_ps(v18, v18);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v21 = _mm_rsqrt_ps(v20);
      v22 = _mm_mul_ps(
              v18,
              _mm_andnot_ps(
                _mm_cmpleps(v20, (__m128)0i64),
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                  _mm_mul_ps(*(__m128 *)_xmm, v21))));
      v23 = _mm_mul_ps(v22, v12);
      v24 = _mm_shuffle_ps(
              v22,
              _mm_unpackhi_ps(
                v22,
                _mm_sub_ps(
                  (__m128)0i64,
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)))),
              196);
      v25 = _mm_mul_ps(v24, v14);
      v26 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v24), 196);
      v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
      v28 = _mm_mul_ps(v24, v15);
      v29 = _mm_add_ps(_mm_shuffle_ps(v27, v27, 177), v27);
      v30 = v29.m128_f32[0] < 0.0;
      v31 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, v24), 196);
      v32 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 78), v31);
      v33 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 177), v32);
      if ( v29.m128_f32[0] > 0.0 )
      {
        if ( v33.m128_f32[0] < 0.0 )
          goto LABEL_13;
        v30 = v29.m128_f32[0] < 0.0;
      }
      if ( v30 && v33.m128_f32[0] > 0.0 )
      {
LABEL_13:
        *(_DWORD *)&aa.m_type.m_storage = 0;
        aa.m_index = v8;
        aa.m_side.m_storage = -1;
        v34 = _mm_sub_ps(v29, v33);
        v35 = _mm_rcp_ps(v34);
        v36 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_sub_ps(v15, v14),
                  _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v34)), v35), v29)),
                v14);
        v37 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v13), _mm_mul_ps(v24, v16));
        v38 = _mm_shuffle_ps(v37, v37, 201);
        v39 = _mm_mul_ps(v38, v38);
        v40 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                _mm_shuffle_ps(v39, v39, 170));
        v41 = _mm_rsqrt_ps(v40);
        v42 = _mm_mul_ps(
                v38,
                _mm_andnot_ps(
                  _mm_cmpleps(v40, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                    _mm_mul_ps(v41, *(__m128 *)_xmm))));
        v43 = _mm_mul_ps(v42, v12);
        v44 = _mm_mul_ps(v42, v10);
        v45 = _mm_mul_ps(v42, v36);
        v46 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
                _mm_shuffle_ps(v44, v44, 170));
        v47 = _mm_rcp_ps(v46);
        aa.m_pos.m_quad = _mm_add_ps(
                            v36,
                            _mm_mul_ps(
                              _mm_mul_ps(
                                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v47, v46)), v47),
                                _mm_sub_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                                    _mm_shuffle_ps(v43, v43, 170)),
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                                    _mm_shuffle_ps(v45, v45, 170)))),
                              v10));
        aa.m_center.m_quad = _mm_shuffle_ps(aa.m_pos.m_quad, _mm_unpackhi_ps(aa.m_pos.m_quad, aa.m_center.m_quad), 196);
        v48 = _mm_mul_ps(_mm_sub_ps(aa.m_pos.m_quad, v12), v13);
        v49 = _mm_mul_ps(v13, v13);
        v50 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v48, v48, 170));
        if ( v50 >= 0.0
          && v50 <= (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 85))
                                  + COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 0)))
                          + COERCE_FLOAT(_mm_shuffle_ps(v49, v49, 170))) )
        {
          hkaiStringPulling::addVertexToPath(v6, &aa, 0);
        }
      }
      ++v8;
      v9 += 128i64;
    }
    while ( v8 <= v4->m_index );
  }
  v53.m_index = -2;
  *(_DWORD *)&v53.m_side.m_storage = 255;
  v53.m_userEdgeSwapped.m_bool = 0;
  hkaiStringPulling::projectSegmentEndpoint(v6, v4, &v53);
  hkaiStringPulling::addVertexToPath(v6, &v53, v7);
}

// File Line: 1122
// RVA: 0xC248E0
void __fastcall hkaiStringPulling::projectSegmentEndpoint(hkaiStringPulling *this, hkaiStringPulling::Vertex *a, hkaiStringPulling::Vertex *projOut)
{
  char v3; // al
  int v4; // er12
  unsigned int v5; // er13
  hkaiStringPulling::Vertex *v6; // rsi
  hkaiStringPulling::Vertex *v7; // rdi
  hkaiStringPulling *v8; // r15
  unsigned int v9; // er8
  unsigned __int8 v10; // r14
  int v11; // ebx
  int v12; // eax
  int v13; // er14
  __m128 v14; // xmm6
  unsigned __int8 v15; // dl
  hkVector4f v16; // xmm7
  char v17; // bl
  char v18; // al
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  hkaiGeneralAccessor *v22; // rcx
  int v23; // ecx
  hkVector4f *v24; // rax
  hkVector4f pointInOut; // [rsp+20h] [rbp-60h]
  hkaiStringPulling::Vertex inOut; // [rsp+30h] [rbp-50h]
  int v27; // [rsp+B8h] [rbp+38h]

  v3 = a->m_type.m_storage;
  v4 = -1;
  v5 = -1;
  v6 = projOut;
  v7 = a;
  v8 = this;
  if ( v3 != 1 )
  {
    if ( v3 == 2 )
    {
      v5 = this->m_startFaceKey;
      v4 = this->m_pathLength - 1;
    }
    else
    {
      if ( COERCE_FLOAT(*(_OWORD *)&this->m_radius) < 0.00000011920929
        || a->m_userEdge.m_bool
        || (v10 = a->m_side.m_storage, v10 == -1)
        || !a->m_clearanceIsNegative.m_bool
        || v10 == -1 )
      {
        projOut->m_index = a->m_index;
        projOut->m_side.m_storage = a->m_side.m_storage;
        projOut->m_type.m_storage = a->m_type.m_storage;
        projOut->m_clearanceIsNegative.m_bool = a->m_clearanceIsNegative.m_bool;
        projOut->m_userEdge.m_bool = a->m_userEdge.m_bool;
        projOut->m_userEdgeSwapped.m_bool = a->m_userEdgeSwapped.m_bool;
        projOut->m_pos = a->m_pos;
        projOut->m_center = a->m_center;
        return;
      }
      v11 = a->m_index;
      v12 = hkaiStringPulling::getIndex(this, a->m_index, (hkaiStringPulling::Side)v10);
      *(_DWORD *)&inOut.m_type.m_storage = 0;
      inOut.m_index = v11;
      inOut.m_side.m_storage = v10;
      v27 = v12;
      hkaiStringPulling::getVertex(v8, &inOut);
      v13 = v7->m_index;
      v14 = _mm_sub_ps(v7->m_pos.m_quad, v7->m_center.m_quad);
      if ( v7->m_index >= v8->m_pathLength )
        goto LABEL_7;
      v15 = v7->m_side.m_storage;
      v16.m_quad = (__m128)inOut.m_pos;
      v17 = inOut.m_side.m_storage;
      while ( (unsigned int)hkaiStringPulling::getIndex(v8, v13, (hkaiStringPulling::Side)v15) == v27 )
      {
        *(_DWORD *)&inOut.m_type.m_storage = 0;
        inOut.m_index = v13;
        if ( v17 )
        {
          if ( v17 == 1 )
            v18 = 0;
          else
            v18 = -1;
        }
        else
        {
          v18 = 1;
        }
        inOut.m_side.m_storage = v18;
        hkaiStringPulling::getVertex(v8, &inOut);
        v15 = v7->m_side.m_storage;
        v4 = v13;
        v19 = _mm_sub_ps(inOut.m_pos.m_quad, v16.m_quad);
        v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v19));
        v21 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v8->m_up.m_quad);
        if ( (v15 == 0) != (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85))
                                         + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
                                 + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) > 0.0 )
        {
          v9 = v8->m_pathEdgeCache.m_pathEdges.m_data[(signed __int64)v13].m_oppositeEdge.m_oppositeFace;
          goto LABEL_25;
        }
        if ( ++v13 >= v8->m_pathLength )
          break;
      }
    }
    if ( v4 != -1 )
      v5 = v8->m_pathEdgeCache.m_pathEdges.m_data[(signed __int64)v4].m_incomingEdge.m_oppositeFace;
LABEL_7:
    v9 = v5;
    goto LABEL_25;
  }
  v9 = this->m_startFaceKey;
LABEL_25:
  v22 = v8->m_accessor;
  _mm_store_si128((__m128i *)&pointInOut, (__m128i)v7->m_pos.m_quad);
  v23 = (unsigned __int8)hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(v22, &v8->m_up, v9, &pointInOut);
  v6->m_index = v7->m_index;
  v6->m_side.m_storage = v7->m_side.m_storage;
  v6->m_type.m_storage = v7->m_type.m_storage;
  v6->m_clearanceIsNegative.m_bool = v7->m_clearanceIsNegative.m_bool;
  v6->m_userEdge.m_bool = v7->m_userEdge.m_bool;
  v6->m_userEdgeSwapped.m_bool = v7->m_userEdgeSwapped.m_bool;
  v24 = &pointInOut;
  if ( !v23 )
    v24 = &v7->m_pos;
  v6->m_pos = v7->m_pos;
  v6->m_center = v7->m_center;
  v6->m_pos = (hkVector4f)v24->m_quad;
}

// File Line: 1217
// RVA: 0xC23E40
char __fastcall hkaiStringPulling::doWedgeCheck(hkaiStringPulling *this, hkaiStringPulling::Vertex *wedgeStart, hkaiStringPulling::Vertex *wedgeEnd, hkaiStringPulling::Vertex *start)
{
  hkVector4f v4; // xmm1
  hkaiStringPulling::Vertex *v5; // r15
  hkaiStringPulling::Vertex *v6; // r12
  hkaiStringPulling::Vertex *v7; // rsi
  hkaiStringPulling *v8; // r14
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  bool v11; // zf
  __m128 v12; // xmm7
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  hkaiStringPulling::Vertex *v17; // rdi
  unsigned __int8 v18; // al
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  hkVector4f v22; // xmm0
  int v23; // ebx
  int v24; // eax
  int v25; // eax
  __m128 v26; // xmm3
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  __m128 v33; // xmm6
  __m128 v34; // xmm5
  __m128 v35; // xmm6
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __int128 v38; // xmm0
  hkVector4f v39; // xmm1
  hkVector4f v40; // xmm2
  __int64 v41; // rdx
  __int64 v42; // rcx
  char result; // al
  __int128 v44; // xmm0
  hkVector4f v45; // xmm1
  hkVector4f v46; // xmm2
  __int64 v47; // rdx
  __int64 v48; // rcx
  hkaiStringPulling::Vertex v49; // [rsp+30h] [rbp-79h]
  hkVector4f a; // [rsp+68h] [rbp-41h]
  hkVector4f b; // [rsp+78h] [rbp-31h]
  hkaiStringPulling::Vertex starta; // [rsp+88h] [rbp-21h]
  hkaiStringPulling::Vertex *userEdgeSwapped; // [rsp+118h] [rbp+6Fh]
  __int64 v54; // [rsp+120h] [rbp+77h]
  int edgeIndex; // [rsp+128h] [rbp+7Fh]

  v4.m_quad = (__m128)wedgeEnd->m_pos;
  v5 = wedgeEnd;
  v6 = wedgeStart;
  v7 = start;
  v8 = this;
  *(_OWORD *)&v49.m_userEdgeSwapped.m_bool = *(_OWORD *)&wedgeEnd->m_index;
  v9.m_quad = (__m128)wedgeEnd->m_center;
  *(hkVector4f *)((char *)&v49.m_pos + 8) = (hkVector4f)v4.m_quad;
  v10.m_quad = (__m128)wedgeStart->m_pos;
  *(hkVector4f *)((char *)&v49.m_center + 8) = (hkVector4f)v9.m_quad;
  *(_OWORD *)&starta.m_index = *(_OWORD *)&wedgeStart->m_index;
  starta.m_center = wedgeStart->m_center;
  starta.m_pos = (hkVector4f)v10.m_quad;
  hkaiStringPulling::genericTangent(
    this,
    (hkaiStringPulling::Vertex *)((char *)&starta + 24),
    (hkaiStringPulling::Vertex *)((char *)&v49 + 32));
  v11 = v5->m_side.m_storage == 0;
  v12 = v8->m_up.m_quad;
  v13 = *(__m128 *)((char *)&v49.m_pos.m_quad + 8);
  a.m_quad = (__m128)starta.m_pos;
  v49.m_pos = *(hkVector4f *)((char *)&v49.m_pos + 8);
  v14 = _mm_sub_ps(v49.m_pos.m_quad, starta.m_pos.m_quad);
  v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v14));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  if ( v11 )
    v16 = _mm_xor_ps(v16, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  v17 = userEdgeSwapped;
  v11 = userEdgeSwapped->m_userEdge.m_bool == 0;
  b.m_quad = _mm_add_ps(v16, v13);
  if ( v11
    && (v18 = userEdgeSwapped->m_side.m_storage, v18 != -1)
    && userEdgeSwapped->m_clearanceIsNegative.m_bool
    && v18 != -1 )
  {
    v19 = _mm_mul_ps(v16, v16);
    v20 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
            _mm_shuffle_ps(v19, v19, 170));
    v21 = _mm_rsqrt_ps(v20);
    v22.m_quad = _mm_sub_ps(
                   userEdgeSwapped->m_center.m_quad,
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_andnot_ps(
                         _mm_cmpleps(v20, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                           _mm_mul_ps(*(__m128 *)_xmm, v21))),
                       v16),
                     v8->m_radius.m_real));
  }
  else
  {
    v22.m_quad = (__m128)userEdgeSwapped->m_center;
  }
  v23 = (unsigned __int8)v5->m_side.m_storage;
  *(hkVector4f *)&v49.m_index = (hkVector4f)v22.m_quad;
  LOBYTE(v24) = hkaiStringPulling::getSide(v8, &a, &v49.m_pos, (hkVector4f *)&v49);
  if ( v24 != v23 )
    goto LABEL_19;
  LOBYTE(v25) = hkaiStringPulling::getSide(v8, &v49.m_pos, &b, (hkVector4f *)&v49);
  if ( v25 != v23 )
    goto LABEL_20;
  hkaiStringPulling::getVertexPosition(v8, edgeIndex, 0, &v49.m_pos, (bool *)&userEdgeSwapped);
  hkaiStringPulling::getVertexPosition(v8, edgeIndex, RIGHT, (hkVector4f *)&v49, (bool *)&userEdgeSwapped);
  v26 = v5->m_side.m_storage ? _mm_sub_ps(v49.m_pos.m_quad, *(__m128 *)&v49.m_index) : _mm_sub_ps(
                                                                                         *(__m128 *)&v49.m_index,
                                                                                         v49.m_pos.m_quad);
  v27 = _mm_mul_ps(v26, v12);
  v28 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)), _mm_shuffle_ps(v27, v27, 170));
  v29 = _mm_mul_ps(v14, v12);
  v30 = _mm_sub_ps(v26, _mm_mul_ps(v28, v12));
  v31 = v30;
  v32 = _mm_mul_ps(v30, v30);
  v33 = _mm_sub_ps(
          v14,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170)),
            v12));
  v34 = _mm_mul_ps(v31, v33);
  v35 = _mm_mul_ps(v33, v33);
  v36 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
            _mm_shuffle_ps(v35, v35, 170)));
  v37 = _mm_rsqrt_ps(v36);
  if ( (float)(COERCE_FLOAT(
                 _mm_andnot_ps(
                   _mm_cmpleps(v36, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v36), v37)),
                     _mm_mul_ps(*(__m128 *)_xmm, v37))))
             * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v34, v34, 170)))) <= -0.001 )
  {
LABEL_19:
    v44 = *(_OWORD *)&v6->m_index;
    v45.m_quad = (__m128)v6->m_center;
    v46.m_quad = (__m128)v6->m_pos;
    v47 = v54;
    v48 = *(_OWORD *)&v6->m_index;
    v7->m_index = v48;
    v7->m_side.m_storage = BYTE4(v48);
    v7->m_pos = (hkVector4f)v46.m_quad;
    v7->m_center = (hkVector4f)v45.m_quad;
    v7->m_type.m_storage = BYTE5(v48);
    *(_OWORD *)&v49.m_userEdgeSwapped.m_bool = v44;
    v7->m_userEdge.m_bool = HIBYTE(v48);
    v7->m_clearanceIsNegative.m_bool = BYTE6(v48);
    v7->m_userEdgeSwapped.m_bool = v49.m_pos.m_quad.m128_i8[0];
    v17->m_index = *(_DWORD *)v47;
    v17->m_side.m_storage = *(_BYTE *)(v47 + 4);
    v17->m_type.m_storage = *(_BYTE *)(v47 + 5);
    v17->m_clearanceIsNegative.m_bool = *(_BYTE *)(v47 + 6);
    v17->m_userEdge.m_bool = *(_BYTE *)(v47 + 7);
    v17->m_userEdgeSwapped.m_bool = *(_BYTE *)(v47 + 8);
    v17->m_pos = *(hkVector4f *)(v47 + 16);
    v17->m_center = *(hkVector4f *)(v47 + 32);
    hkaiStringPulling::genericTangent(v8, v7, v17);
    result = 0;
  }
  else
  {
LABEL_20:
    v38 = *(_OWORD *)&v5->m_index;
    v39.m_quad = (__m128)v5->m_center;
    v40.m_quad = (__m128)v5->m_pos;
    v41 = v54;
    v42 = *(_OWORD *)&v5->m_index;
    v7->m_index = v42;
    v7->m_side.m_storage = BYTE4(v42);
    v7->m_pos = (hkVector4f)v40.m_quad;
    v7->m_center = (hkVector4f)v39.m_quad;
    v7->m_type.m_storage = BYTE5(v42);
    *(_OWORD *)&v49.m_userEdgeSwapped.m_bool = v38;
    v7->m_userEdge.m_bool = HIBYTE(v42);
    v7->m_clearanceIsNegative.m_bool = BYTE6(v42);
    v7->m_userEdgeSwapped.m_bool = v49.m_pos.m_quad.m128_i8[0];
    v17->m_index = *(_DWORD *)v41;
    v17->m_side.m_storage = *(_BYTE *)(v41 + 4);
    v17->m_type.m_storage = *(_BYTE *)(v41 + 5);
    v17->m_clearanceIsNegative.m_bool = *(_BYTE *)(v41 + 6);
    v17->m_userEdge.m_bool = *(_BYTE *)(v41 + 7);
    v17->m_userEdgeSwapped.m_bool = *(_BYTE *)(v41 + 8);
    v17->m_pos = *(hkVector4f *)(v41 + 16);
    v17->m_center = *(hkVector4f *)(v41 + 32);
    hkaiStringPulling::genericTangent(v8, v7, v17);
    result = 1;
  }
  return result;
}

// File Line: 1317
// RVA: 0xC22B00
bool __fastcall hkaiStringPulling::stringPull(hkaiStringPulling *this)
{
  int v1; // eax
  __m128 v2; // xmm6
  hkaiStringPulling *v3; // rdi
  hkVector4f v4; // xmm0
  hkaiStringPulling::Funnel *v6; // rbx
  signed __int64 v7; // rcx
  __int64 v8; // rcx
  BOOL v9; // er14
  signed __int64 v10; // rdx
  int v11; // esi
  float v12; // xmm9_4
  hkaiStringPulling::Vertex *v13; // rax
  hkVector4f v14; // xmm0
  hkaiStringPulling::Funnel *v15; // rbx
  hkVector4f v16; // xmm6
  hkaiStringPulling::Vertex *v17; // rax
  char v18; // r15
  __m128 v19; // xmm6
  __m128 v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  int v23; // eax
  hkaiStringPulling::Funnel *v24; // r13
  int v25; // er15
  int v26; // er12
  int v27; // edx
  hkaiStringPulling::Funnel *v28; // rcx
  hkaiStringPulling::Vertex *v29; // rcx
  char v30; // bl
  char v31; // al
  hkVector4f v32; // xmm1
  char v33; // al
  int v34; // edx
  hkaiStringPulling::Funnel *v35; // rcx
  hkaiStringPulling::Vertex *v36; // rcx
  hkVector4f v37; // xmm0
  hkVector4f v38; // xmm1
  char v39; // al
  BOOL v40; // ebx
  int v41; // eax
  hkaiStringPulling::Vertex *v42; // rax
  int v43; // eax
  unsigned int v44; // er13
  unsigned __int8 v45; // al
  int v46; // esi
  hkaiStringPulling::Vertex *v47; // rax
  signed __int64 v48; // rcx
  int v49; // er15
  __int128 *v50; // r14
  hkVector4f *v51; // r12
  hkaiStringPulling::Vertex *v52; // rsi
  signed __int64 v53; // r13
  hkaiStringPulling::Vertex *v54; // rax
  hkVector4f v55; // xmm1
  hkVector4f v56; // xmm0
  __m128 v57; // xmm1
  __m128 v58; // xmm1
  __m128 v59; // xmm4
  __m128 v60; // xmm2
  hkaiStringPulling::Vertex a; // [rsp+40h] [rbp-C0h]
  hkaiStringPulling::Vertex wedgeEnd; // [rsp+70h] [rbp-90h]
  hkaiStringPulling::Funnel::Iterator v63; // [rsp+A0h] [rbp-60h]
  hkaiStringPulling::Funnel::Iterator v64; // [rsp+B0h] [rbp-50h]
  hkaiStringPulling::Vertex inOut; // [rsp+C0h] [rbp-40h]
  hkaiStringPulling::Vertex b; // [rsp+F0h] [rbp-10h]
  hkaiStringPulling::Vertex v67; // [rsp+120h] [rbp+20h]
  hkaiStringPulling::Vertex start; // [rsp+150h] [rbp+50h]
  int v69; // [rsp+180h] [rbp+80h]
  char v70; // [rsp+184h] [rbp+84h]
  int v71; // [rsp+185h] [rbp+85h]
  hkaiStringPulling::Vertex vertex; // [rsp+1B0h] [rbp+B0h]
  __int128 v73; // [rsp+1E0h] [rbp+E0h]
  __int128 v74; // [rsp+1F0h] [rbp+F0h]
  hkaiStringPulling::Vertex v75; // [rsp+200h] [rbp+100h]
  unsigned int v76; // [rsp+2B0h] [rbp+1B0h]
  signed int v77; // [rsp+2B8h] [rbp+1B8h]

  v1 = this->m_pathLength;
  v2 = this->m_startPoint.m_quad;
  v3 = this;
  if ( v1 <= 0 )
  {
    v4.m_quad = (__m128)this->m_endPoint;
    a.m_pos = this->m_startPoint;
    *(_WORD *)&a.m_userEdge.m_bool = 0;
    a.m_index = -1;
    *(_WORD *)&a.m_side.m_storage = 511;
    *(_WORD *)&b.m_userEdge.m_bool = 0;
    a.m_center.m_quad = v2;
    b.m_pos = (hkVector4f)v4.m_quad;
    b.m_center = (hkVector4f)v4.m_quad;
    v4.m_quad.m128_i32[0] = this->m_endPoint.m_quad.m128_i32[3];
    a.m_clearanceIsNegative.m_bool = this->m_startPoint.m_quad.m128_f32[3] < 0.0;
    b.m_index = v1;
    *(_WORD *)&b.m_side.m_storage = 767;
    b.m_clearanceIsNegative.m_bool = v4.m_quad.m128_f32[0] < 0.0;
    hkaiStringPulling::addSegmentToPath(this, &a, &b);
    return hkaiStringPulling::terminateOutput(v3);
  }
  v6 = &this->m_funnel;
  hkaiStringPulling::Funnel::clear(&this->m_funnel);
  if ( v3->m_funnel.m_data.m_size == (v3->m_funnel.m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v3->m_funnel.m_data, 48);
  v7 = (signed __int64)&v3->m_funnel.m_data.m_data[v3->m_funnel.m_data.m_size];
  if ( v7 )
  {
    *(_DWORD *)v7 = -2;
    *(_DWORD *)(v7 + 4) = 255;
    *(_BYTE *)(v7 + 8) = 0;
  }
  v8 = v3->m_funnel.m_data.m_size;
  v9 = 1;
  v77 = 0;
  v3->m_funnel.m_data.m_size = v8 + 1;
  v76 = 0;
  v10 = (signed __int64)&v3->m_funnel.m_data.m_data[v8];
  *(__m128 *)(v10 + 16) = v2;
  *(__m128 *)(v10 + 32) = v2;
  v11 = 0;
  *(_BYTE *)(v10 + 6) = COERCE_FLOAT(_mm_shuffle_ps(v2, v2, 255)) < 0.0;
  *(_DWORD *)v10 = -1;
  *(_WORD *)(v10 + 4) = 511;
  v3->m_funnel.m_apex = 0;
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps(
                                      (__m128)LODWORD(hkaiStringPulling::TOLERANCE),
                                      (__m128)LODWORD(hkaiStringPulling::TOLERANCE),
                                      0);
  do
  {
    if ( v11 > v3->m_pathLength )
      return hkaiStringPulling::terminateOutput(v3);
    hkaiStringPulling::Funnel::Iterator::Iterator(&v63, v6, (hkaiStringPulling::Side)v9, -1);
    _mm_store_si128((__m128i *)&v64, (__m128i)v63);
    while ( 1 )
    {
      hkaiStringPulling::Funnel::Iterator::operator++(&v64, 0);
      v13 = hkaiStringPulling::Funnel::operator[](v6, v3->m_funnel.m_apex);
      *(_OWORD *)&start.m_index = *(_OWORD *)&v13->m_index;
      start.m_pos = v13->m_pos;
      v14.m_quad = (__m128)v13->m_center;
      *(_DWORD *)&inOut.m_type.m_storage = 0;
      inOut.m_index = v11;
      inOut.m_side.m_storage = v9;
      start.m_center = (hkVector4f)v14.m_quad;
      hkaiStringPulling::getVertex(v3, &inOut);
      v15 = v63.m_funnel;
      v16.m_quad = (__m128)inOut.m_pos;
      vertex = inOut;
      if ( v11 < v3->m_pathLength )
      {
        if ( (v17 = hkaiStringPulling::Funnel::operator[](v63.m_funnel, v63.m_funnelIndex),
              v18 = inOut.m_userEdge.m_bool,
              v19 = _mm_sub_ps(v16.m_quad, v17->m_pos.m_quad),
              v20 = _mm_mul_ps(v19, v19),
              v21 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                      _mm_shuffle_ps(v20, v20, 170)),
              v22 = _mm_rsqrt_ps(v21),
              COERCE_FLOAT(
                _mm_andnot_ps(
                  _mm_cmpleps(v21, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v22), v22)),
                      _mm_mul_ps(*(__m128 *)_xmm, v22)),
                    v21))) < v12)
          && !inOut.m_userEdge.m_bool
          || (unsigned int)hkaiStringPulling::undefinedTangent(v3, &start, &inOut) && v11 && !v18 )
        {
LABEL_49:
          v6 = &v3->m_funnel;
          goto LABEL_50;
        }
      }
      wedgeEnd.m_index = -2;
      *(_DWORD *)&wedgeEnd.m_side.m_storage = 255;
      wedgeEnd.m_userEdgeSwapped.m_bool = 0;
      a.m_index = -2;
      *(_DWORD *)&a.m_side.m_storage = 255;
      a.m_userEdgeSwapped.m_bool = 0;
      if ( !(unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&v64) )
        break;
      v23 = hkaiStringPulling::Funnel::Iterator::lessOrEqualApex(&v64);
      v24 = v64.m_funnel;
      v25 = v64.m_funnelIndex;
      v26 = v23;
      if ( v23 )
      {
        v27 = v63.m_funnelIndex;
        v28 = v15;
      }
      else
      {
        v27 = v64.m_funnelIndex;
        v28 = v64.m_funnel;
      }
      v29 = hkaiStringPulling::Funnel::operator[](v28, v27);
      v30 = v29->m_side.m_storage;
      wedgeEnd.m_index = v29->m_index;
      v31 = v29->m_type.m_storage;
      v32.m_quad = (__m128)v29->m_center;
      wedgeEnd.m_pos = v29->m_pos;
      wedgeEnd.m_center = (hkVector4f)v32.m_quad;
      wedgeEnd.m_type.m_storage = v31;
      v33 = v29->m_clearanceIsNegative.m_bool;
      wedgeEnd.m_side.m_storage = v30;
      wedgeEnd.m_clearanceIsNegative.m_bool = v33;
      wedgeEnd.m_userEdge.m_bool = v29->m_userEdge.m_bool;
      wedgeEnd.m_userEdgeSwapped.m_bool = v29->m_userEdgeSwapped.m_bool;
      if ( v26 )
      {
        v34 = v25;
        v35 = v24;
      }
      else
      {
        v34 = v63.m_funnelIndex;
        v35 = v63.m_funnel;
      }
      v36 = hkaiStringPulling::Funnel::operator[](v35, v34);
      a.m_index = v36->m_index;
      v37.m_quad = (__m128)v36->m_pos;
      v38.m_quad = (__m128)v36->m_center;
      a.m_side.m_storage = v36->m_side.m_storage;
      v39 = v36->m_type.m_storage;
      a.m_pos = (hkVector4f)v37.m_quad;
      a.m_center = (hkVector4f)v38.m_quad;
      a.m_type.m_storage = v39;
      a.m_clearanceIsNegative.m_bool = v36->m_clearanceIsNegative.m_bool;
      a.m_userEdge.m_bool = v36->m_userEdge.m_bool;
      a.m_userEdgeSwapped.m_bool = v36->m_userEdgeSwapped.m_bool;
      if ( (unsigned int)hkaiStringPulling::undefinedTangent(v3, &inOut, &wedgeEnd) )
      {
        if ( v11 != v3->m_pathLength && !(unsigned int)hkaiStringPulling::isUserEdge(v3, v11) )
          goto LABEL_49;
        v40 = v30 == (_BYTE)v9 && hkaiStringPulling::isUndefinedTangentVertexAddable(v3, &a, &wedgeEnd, &inOut);
        hkaiStringPulling::genericTangent(v3, &start, &inOut);
      }
      else
      {
        if ( (unsigned int)hkaiStringPulling::undefinedTangent(v3, &a, &wedgeEnd) )
          goto LABEL_36;
        if ( v30 == (_BYTE)v9 )
        {
          v40 = hkaiStringPulling::doWedgeCheck(v3, &a, &wedgeEnd, &start, &inOut, &vertex, v11 - 1);
        }
        else
        {
          hkaiStringPulling::genericTangent(v3, &start, &inOut);
          hkaiStringPulling::genericTangent(v3, &a, &wedgeEnd);
          LOBYTE(v41) = hkaiStringPulling::getSide(v3, &a.m_pos, &wedgeEnd.m_pos, &inOut.m_pos);
          v40 = v41 == v9;
        }
      }
      if ( v40 )
        goto LABEL_42;
LABEL_36:
      v6 = &v3->m_funnel;
      b.m_index = -2;
      *(_DWORD *)&b.m_side.m_storage = 255;
      b.m_userEdgeSwapped.m_bool = 0;
      hkaiStringPulling::Funnel::pop(&v3->m_funnel, (hkaiStringPulling::Side)v9, &b);
      if ( (unsigned int)hkaiStringPulling::Funnel::apexPopped(&v3->m_funnel) )
      {
        v42 = hkaiStringPulling::Funnel::operator[](v24, v25);
        *(_OWORD *)&a.m_index = *(_OWORD *)&v42->m_index;
        a.m_pos = v42->m_pos;
        a.m_center = v42->m_center;
        wedgeEnd.m_pos = b.m_pos;
        *(_OWORD *)&wedgeEnd.m_index = *(_OWORD *)&b.m_index;
        wedgeEnd.m_center = b.m_center;
        hkaiStringPulling::genericTangent(v3, &wedgeEnd, &a);
        if ( hkaiStringPulling::isCloser(v3, &wedgeEnd, &a, &inOut, v11 - 1) )
        {
          hkaiStringPulling::addSegmentToPath(v3, &start, &inOut);
          hkaiStringPulling::Funnel::add(&v3->m_funnel, &vertex, (hkaiStringPulling::Side)v9);
          v43 = v3->m_pathLength;
          v44 = vertex.m_index == v43;
          v76 = vertex.m_index == v43;
          hkaiStringPulling::handleUserEdge(v3, &vertex, v11);
          goto LABEL_51;
        }
        hkaiStringPulling::addSegmentToPath(v3, &wedgeEnd, &a);
        v3->m_funnel.m_apex = v25;
      }
      hkaiStringPulling::Funnel::Iterator::operator++(&v63, 0);
    }
    hkaiStringPulling::genericTangent(v3, &start, &inOut);
LABEL_42:
    v6 = &v3->m_funnel;
    if ( hkaiStringPulling::Funnel::add(&v3->m_funnel, &vertex, (hkaiStringPulling::Side)v9) )
    {
      v45 = hkaiStringPulling::checkTermination(v3, &vertex, (hkaiStringPulling::Side)v9, v11);
      v44 = v45;
      v76 = v45;
      goto LABEL_51;
    }
    a.m_index = -2;
    *(_DWORD *)&a.m_side.m_storage = 255;
    a.m_userEdgeSwapped.m_bool = 0;
    v46 = hkaiStringPulling::Funnel::getApex(&v3->m_funnel)->m_index;
    *(_DWORD *)&b.m_type.m_storage = 0;
    v11 = v46 + 1;
    *(_DWORD *)&v67.m_type.m_storage = 0;
    v67.m_side.m_storage = 1;
    v67.m_index = v11;
    b.m_index = v11;
    b.m_side.m_storage = 0;
    hkaiStringPulling::getVertex(v3, &v67);
    hkaiStringPulling::getVertex(v3, &b);
    a.m_index = v11;
    a.m_side.m_storage = -1;
    a.m_userEdge.m_bool = 0;
    a.m_pos.m_quad = _mm_add_ps(
                       _mm_mul_ps(_mm_sub_ps(b.m_pos.m_quad, v67.m_pos.m_quad), (__m128)xmmword_141A711B0),
                       v67.m_pos.m_quad);
    a.m_center.m_quad = _mm_shuffle_ps(a.m_pos.m_quad, _mm_unpackhi_ps(a.m_pos.m_quad, a.m_center.m_quad), 196);
    v47 = hkaiStringPulling::Funnel::getApex(&v3->m_funnel);
    hkaiStringPulling::addSegmentToPath(v3, v47, &a);
    hkaiStringPulling::Funnel::clear(&v3->m_funnel);
    if ( v3->m_funnel.m_data.m_size == (v3->m_funnel.m_data.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v3->m_funnel.m_data, 48);
    v48 = (signed __int64)&v3->m_funnel.m_data.m_data[v3->m_funnel.m_data.m_size];
    if ( v48 )
    {
      *(_OWORD *)v48 = *(_OWORD *)&a.m_index;
      *(hkVector4f *)(v48 + 16) = a.m_pos;
      *(hkVector4f *)(v48 + 32) = a.m_center;
    }
    ++v3->m_funnel.m_data.m_size;
    v77 = -1;
    v3->m_funnel.m_apex = 0;
LABEL_50:
    v44 = v76;
LABEL_51:
    v49 = v11 + 1;
    if ( v77 == -1 )
    {
      if ( hkaiStringPulling::isShared(v3, v11, RIGHT) )
      {
        v44 = v76;
        v9 = 0;
        ++v11;
      }
      else if ( hkaiStringPulling::isShared(v3, v11, 0) )
      {
        v44 = v76;
        v9 = 1;
        ++v11;
      }
      else
      {
        *(_DWORD *)&start.m_type.m_storage = 0;
        v71 = 0;
        v69 = v11 + 1;
        start.m_index = v11 + 1;
        v70 = 1;
        start.m_side.m_storage = 0;
        v74 = 0i64;
        v73 = 0i64;
        v50 = &v73;
        v51 = &start.m_pos;
        v52 = &start;
        v53 = 2i64;
        do
        {
          hkaiStringPulling::getVertex(v3, v52);
          v54 = hkaiStringPulling::Funnel::getApex(v6);
          v55.m_quad = (__m128)v54->m_pos;
          *(_OWORD *)&v75.m_index = *(_OWORD *)&v54->m_index;
          v56.m_quad = (__m128)v54->m_center;
          v75.m_pos = (hkVector4f)v55.m_quad;
          v75.m_center = (hkVector4f)v56.m_quad;
          hkaiStringPulling::genericTangent(v3, &v75, v52);
          ++v50;
          ++v52;
          v51 += 3;
          v57 = _mm_sub_ps(v75.m_pos.m_quad, v51[-3].m_quad);
          v58 = _mm_mul_ps(v57, v57);
          v59 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                  _mm_shuffle_ps(v58, v58, 170));
          v60 = _mm_rsqrt_ps(v59);
          *(v50 - 1) = (__int128)_mm_andnot_ps(
                                   _mm_cmpleps(v59, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v59, v60), v60)),
                                       _mm_mul_ps(v60, *(__m128 *)_xmm)),
                                     v59));
          --v53;
        }
        while ( v53 );
        v9 = *(float *)&v73 > *(float *)&v74;
        if ( *(float *)&v73 <= *(float *)&v74 )
        {
          v44 = v76;
          v77 = 1;
          v11 = v49;
        }
        else
        {
          if ( *(float *)&v73 > *(float *)&v74 == 1 )
          {
            v44 = v76;
            v77 = 0;
          }
          else
          {
            v44 = v76;
            v77 = -1;
          }
          v11 = v49;
        }
      }
    }
    else
    {
      v9 = v77;
      v77 = -1;
    }
  }
  while ( !v44 );
  return hkaiStringPulling::terminateOutput(v3);
}

