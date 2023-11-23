// File Line: 49
// RVA: 0xC212C0
void __fastcall hkaiStringPulling::Funnel::Funnel(hkaiStringPulling::Funnel *this)
{
  *(_QWORD *)&this->m_start = 0i64;
  this->m_data.m_data = 0i64;
  this->m_data.m_size = 0;
  this->m_data.m_capacityAndFlags = 0x80000000;
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
bool __fastcall hkaiStringPulling::Funnel::add(
        hkaiStringPulling::Funnel *this,
        hkaiStringPulling::Vertex *vertex,
        hkaiStringPulling::Side side)
{
  int v5; // eax
  hkaiStringPulling::Vertex *v6; // r8
  bool result; // al
  hkaiStringPulling::Vertex *v8; // rcx

  if ( side == RIGHT )
  {
    if ( this->m_start <= 0 )
    {
      hkArrayBase<hkaiStringPulling::Vertex>::_insertAt(&this->m_data, &hkContainerTempAllocator::s_alloc, 0, vertex);
      ++this->m_apex;
      return 1;
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
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &this->m_data, 48);
    v8 = &this->m_data.m_data[this->m_data.m_size];
    if ( v8 )
    {
      *(_OWORD *)&v8->m_index = *(_OWORD *)&vertex->m_index;
      v8->m_pos = vertex->m_pos;
      v8->m_center = vertex->m_center;
    }
    ++this->m_data.m_size;
    return 1;
  }
  return result;
}

// File Line: 90
// RVA: 0xC21400
void __fastcall hkaiStringPulling::Funnel::pop(
        hkaiStringPulling::Funnel *this,
        hkaiStringPulling::Side side,
        hkaiStringPulling::Vertex *vertexOut)
{
  __int64 m_start; // rdx
  hkaiStringPulling::Vertex *v5; // rdx
  hkaiStringPulling::Vertex *v6; // rcx

  if ( side == RIGHT )
  {
    m_start = this->m_start;
    this->m_start = m_start + 1;
    v5 = &this->m_data.m_data[m_start];
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
    --this->m_data.m_size;
  }
}

// File Line: 105
// RVA: 0xC214C0
_BOOL8 __fastcall hkaiStringPulling::Funnel::apexPopped(hkaiStringPulling::Funnel *this)
{
  int m_apex; // eax

  m_apex = this->m_apex;
  return m_apex < this->m_start || m_apex >= this->m_data.m_size;
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
void __fastcall hkaiStringPulling::Funnel::Iterator::Iterator(
        hkaiStringPulling::Funnel::Iterator *this,
        hkaiStringPulling::Funnel *funnel,
        int side,
        int index)
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
void __fastcall hkaiStringPulling::Funnel::Iterator::operator++(
        hkaiStringPulling::Funnel::Iterator *this,
        int __formal)
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
  unsigned int v1; // r8d

  v1 = 0;
  if ( this->m_side == 1 )
    LOBYTE(v1) = this->m_funnelIndex < this->m_funnel->m_data.m_size;
  else
    LOBYTE(v1) = this->m_funnelIndex >= this->m_funnel->m_start;
  return v1;
}

// File Line: 168
// RVA: 0xC21600
hkaiStringPulling::Funnel::Iterator *__fastcall hkaiStringPulling::Funnel::Iterator::operator=(
        hkaiStringPulling::Funnel::Iterator *this,
        hkaiStringPulling::Funnel::Iterator *other)
{
  this->m_side = other->m_side;
  this->m_funnelIndex = other->m_funnelIndex;
  return this;
}

// File Line: 176
// RVA: 0xC21620
__int64 __fastcall hkaiStringPulling::Funnel::Iterator::lessOrEqualApex(hkaiStringPulling::Funnel::Iterator *this)
{
  unsigned int v1; // r8d

  v1 = 0;
  if ( this->m_side == 1 )
    LOBYTE(v1) = this->m_funnelIndex <= this->m_funnel->m_apex;
  else
    LOBYTE(v1) = this->m_funnelIndex >= this->m_funnel->m_apex;
  return v1;
}

// File Line: 191
// RVA: 0xC21660
void __fastcall hkaiStringPulling::PathEdgeCache::PathEdgeCache(
        hkaiStringPulling::PathEdgeCache *this,
        hkArrayBase<unsigned int> *visitedEdgeKeys)
{
  int m_size; // edi
  hkaiStringPulling::PathEdgeCache::PathEdge *m_cur; // rax
  hkLifoAllocator *Value; // rcx
  int v7; // edx
  char *v8; // r8

  m_size = visitedEdgeKeys->m_size;
  m_cur = 0i64;
  this->m_pathEdges.m_capacityAndFlags = 0x80000000;
  this->m_pathEdges.m_data = 0i64;
  this->m_pathEdges.m_size = 0;
  this->m_pathEdges.m_initialCapacity = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkaiStringPulling::PathEdgeCache::PathEdge *)Value->m_cur;
    v7 = ((m_size << 7) + 127) & 0xFFFFFF80;
    v8 = (char *)m_cur + v7;
    if ( v7 > Value->m_slabSize || v8 > Value->m_end )
      m_cur = (hkaiStringPulling::PathEdgeCache::PathEdge *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
    else
      Value->m_cur = v8;
  }
  this->m_pathEdges.m_data = m_cur;
  this->m_pathEdges.m_localMemory = m_cur;
  this->m_pathEdges.m_capacityAndFlags = m_size | 0x80000000;
  this->m_pathEdgeKeys = visitedEdgeKeys;
}

// File Line: 195
// RVA: 0xC21700
void __fastcall hkaiStringPulling::PathEdgeCache::cacheMeshData(
        hkaiStringPulling::PathEdgeCache *this,
        hkaiGeneralAccessor *accessor,
        unsigned int startFaceKey,
        hkVector4f *up,
        unsigned int computeNormals)
{
  _QWORD *Value; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  unsigned __int64 m_size; // rsi
  int v14; // ecx
  __int64 v15; // rdx
  unsigned int *p_m_oppositeEdge; // rcx
  hkaiNavMeshInstance *m_accessor; // rax
  __int64 v18; // rdx
  __int64 v19; // rsi
  unsigned int v20; // eax
  hkaiNavMesh::Edge *EdgeAndVertsFromPacked; // rax
  unsigned int m_oppositeFace; // edx
  hkaiNavMesh::Edge *v23; // r15
  char v24; // r8
  unsigned int v25; // ecx
  unsigned int v26; // r14d
  unsigned int m_oppositeEdge; // ecx
  unsigned int v28; // eax
  int v29; // r13d
  hkaiNavMesh::Face *v30; // r8
  char v31; // r11
  int v32; // ebx
  __m128 m_quad; // xmm0
  __m128 *v34; // rax
  __m128 *v35; // rcx
  int index; // ebx
  hkaiNavMesh::Edge *v37; // rbx
  __m128 v38; // xmm0
  hkaiNavMesh::Edge *v39; // rax
  hkaiStringPulling::PathEdgeCache::PathEdge *m_data; // rbx
  __m128 v41; // xmm1
  _QWORD *v42; // rax
  _QWORD *v43; // rcx
  _QWORD *v44; // r8
  unsigned __int64 v45; // rax
  _QWORD *v46; // rcx
  unsigned int v47; // [rsp+30h] [rbp-C8h]
  unsigned int v48; // [rsp+34h] [rbp-C4h]
  unsigned int v49; // [rsp+3Ch] [rbp-BCh]
  unsigned int v50; // [rsp+44h] [rbp-B4h]
  __m128 *v51; // [rsp+48h] [rbp-B0h]
  hkVector4f normalOut; // [rsp+50h] [rbp-A8h] BYREF
  __int64 v53; // [rsp+60h] [rbp-98h]
  hkSimdFloat32 maxClearance; // [rsp+70h] [rbp-88h]
  hkVector4f edgeBOut; // [rsp+88h] [rbp-70h] BYREF
  hkaiNavMesh::Face *v56; // [rsp+98h] [rbp-60h]
  hkVector4f edgeAOut; // [rsp+A8h] [rbp-50h] BYREF
  __m128 v58; // [rsp+B8h] [rbp-40h] BYREF
  __m128 v59; // [rsp+C8h] [rbp-30h] BYREF
  hkVector4f v60; // [rsp+D8h] [rbp-20h] BYREF
  __m128 v61; // [rsp+E8h] [rbp-10h] BYREF
  hkVector4f v62; // [rsp+F8h] [rbp+0h] BYREF
  __m128 v63; // [rsp+108h] [rbp+10h] BYREF
  hkSimdFloat32 result; // [rsp+118h] [rbp+20h] BYREF
  hkSimdFloat32 v65; // [rsp+128h] [rbp+30h] BYREF
  hkaiNavMeshUtils v66; // [rsp+138h] [rbp+40h] BYREF
  hkaiStringPulling::PathEdgeCache *retaddr; // [rsp+1A8h] [rbp+B0h]
  unsigned int v68; // [rsp+1B0h] [rbp+B8h]
  unsigned int v69; // [rsp+1B8h] [rbp+C0h]
  hkVector4f *upa; // [rsp+1C0h] [rbp+C8h]
  int v71; // [rsp+1C8h] [rbp+D0h]

  v71 = (int)up;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtcacheMeshData";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  m_size = this->m_pathEdgeKeys->m_size;
  v14 = this->m_pathEdgeKeys->m_size - this->m_pathEdges.m_size;
  v15 = v14;
  if ( v14 > 0 )
  {
    p_m_oppositeEdge = &this->m_pathEdges.m_data[(__int64)this->m_pathEdges.m_size].m_oppositeEdge.m_oppositeEdge;
    do
    {
      if ( p_m_oppositeEdge != (unsigned int *)28 )
      {
        *(p_m_oppositeEdge - 4) = -1;
        *(p_m_oppositeEdge - 5) = -1;
        *(p_m_oppositeEdge - 3) = 4;
        p_m_oppositeEdge[1] = -1;
        *p_m_oppositeEdge = -1;
        p_m_oppositeEdge[2] = 4;
      }
      p_m_oppositeEdge += 32;
      --v15;
    }
    while ( v15 );
  }
  this->m_pathEdges.m_size = m_size;
  hkaiGeneralAccessor::setSection(accessor, startFaceKey >> 22);
  if ( v71 )
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&v60,
      (hkSimdFloat32 *)accessor->m_accessor,
      (hkaiNavMeshInstance *)(startFaceKey & 0x3FFFFF),
      &this->m_startFaceNormal.m_quad);
  else
    this->m_startFaceNormal = (hkVector4f)up->m_quad;
  m_accessor = accessor->m_accessor;
  v18 = 0i64;
  maxClearance.m_real.m128_u64[1] = m_size;
  v53 = 0i64;
  maxClearance.m_real = _mm_shuffle_ps(
                          (__m128)LODWORD(m_accessor->m_maxGlobalClearance),
                          (__m128)LODWORD(m_accessor->m_maxGlobalClearance),
                          0);
  if ( (int)m_size > 0 )
  {
    v19 = 0i64;
    do
    {
      v47 = startFaceKey;
      v20 = this->m_pathEdgeKeys->m_data[v18];
      normalOut.m_quad.m128_u64[1] = 0i64;
      v69 = v20;
      EdgeAndVertsFromPacked = hkaiGeneralAccessor::getEdgeAndVertsFromPacked(
                                 accessor,
                                 v20,
                                 &edgeAOut,
                                 &edgeBOut,
                                 (const int **)&normalOut.m_quad.m128_u64[1]);
      m_oppositeFace = EdgeAndVertsFromPacked->m_oppositeFace;
      v23 = EdgeAndVertsFromPacked;
      v24 = EdgeAndVertsFromPacked->m_flags.m_storage & 0x40;
      if ( v24 )
        v25 = m_oppositeFace & 0xFFC00000;
      else
        v25 = accessor->m_accessor->m_runtimeId << 22;
      v26 = v25 | m_oppositeFace & 0x3FFFFF;
      m_oppositeEdge = EdgeAndVertsFromPacked->m_oppositeEdge;
      if ( m_oppositeFace == -1 )
        v26 = -1;
      if ( v24 )
        v28 = m_oppositeEdge & 0xFFC00000;
      else
        v28 = accessor->m_accessor->m_runtimeId << 22;
      v29 = v28 | m_oppositeEdge & 0x3FFFFF;
      if ( m_oppositeEdge == -1 )
        v29 = -1;
      v30 = hkaiNavMeshInstance_get_hkaiNavMesh::Face__18(
              accessor->m_accessor->m_originalFaces,
              accessor->m_accessor->m_numOriginalFaces,
              &accessor->m_accessor->m_instancedFaces,
              &accessor->m_accessor->m_ownedFaces,
              &accessor->m_accessor->m_faceMap,
              startFaceKey & 0x3FFFFF);
      v56 = v30;
      v32 = v31 & 0x10;
      if ( (v31 & 0x10) != 0 )
      {
        m_quad = aabbOut.m_quad;
        v34 = &v61;
        v61 = aabbOut.m_quad;
      }
      else
      {
        hkaiGeneralAccessor::setSection(accessor, startFaceKey >> 22);
        v68 = accessor->m_accessor->m_globalClearanceCache.m_data[v23->m_a].m_value << 16;
        v58 = _mm_shuffle_ps((__m128)v68, (__m128)v68, 0);
        if ( v58.m128_f32[0] > maxClearance.m_real.m128_f32[0] )
        {
          hkaiNavMeshTraversalUtils::computeGlobalClearance(&result, accessor, startFaceKey, v23);
          v48 = (__int16)(COERCE_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
          v58 = _mm_shuffle_ps((__m128)v48, (__m128)v48, 0);
        }
        m_quad = aabbOut.m_quad;
        v30 = v56;
        v34 = &v58;
      }
      v51 = v34;
      if ( v32 )
      {
        v63 = m_quad;
        v35 = &v63;
      }
      else
      {
        index = (v69 & 0x3FFFFF) + 1;
        if ( index >= v30->m_startEdgeIndex + v30->m_numEdges )
          index = v30->m_startEdgeIndex;
        hkaiGeneralAccessor::setSection(accessor, v69 >> 22);
        v37 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__19(
                accessor->m_accessor->m_originalEdges,
                accessor->m_accessor->m_numOriginalEdges,
                &accessor->m_accessor->m_instancedEdges,
                &accessor->m_accessor->m_ownedEdges,
                &accessor->m_accessor->m_edgeMap,
                index);
        hkaiGeneralAccessor::setSection(accessor, startFaceKey >> 22);
        v50 = accessor->m_accessor->m_globalClearanceCache.m_data[v37->m_a].m_value << 16;
        v59 = _mm_shuffle_ps((__m128)v50, (__m128)v50, 0);
        if ( v59.m128_f32[0] > maxClearance.m_real.m128_f32[0] )
        {
          hkaiNavMeshTraversalUtils::computeGlobalClearance(&v65, accessor, startFaceKey, v37);
          v49 = (__int16)(COERCE_INT(v65.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
          v59 = _mm_shuffle_ps((__m128)v49, (__m128)v49, 0);
        }
        v35 = &v59;
      }
      normalOut.m_quad.m128_u64[0] = 0i64;
      v38 = _mm_unpackhi_ps(edgeBOut.m_quad, *v35);
      edgeAOut.m_quad = _mm_shuffle_ps(edgeAOut.m_quad, _mm_unpackhi_ps(edgeAOut.m_quad, *v51), 196);
      edgeBOut.m_quad = _mm_shuffle_ps(edgeBOut.m_quad, v38, 196);
      v39 = hkaiGeneralAccessor::getEdgeAndVertsFromPacked(accessor, v29, &v62, &v60, (const int **)&normalOut);
      startFaceKey = v26;
      m_data = retaddr->m_pathEdges.m_data;
      m_data[v19].m_incomingEdge.m_a = v23->m_a;
      m_data[v19].m_incomingEdge.m_b = v23->m_b;
      m_data[v19].m_incomingEdge.m_oppositeEdge = v23->m_oppositeEdge;
      m_data[v19].m_incomingEdge.m_oppositeFace = v23->m_oppositeFace;
      m_data[v19].m_incomingEdge.m_flags.m_storage = v23->m_flags.m_storage;
      m_data[v19].m_incomingEdge.m_paddingByte = v23->m_paddingByte;
      m_data[v19].m_incomingEdge.m_userEdgeCost.m_value = v23->m_userEdgeCost.m_value;
      m_data[v19].m_incomingEdgePointA_GC = (hkVector4f)edgeAOut.m_quad;
      m_data[v19].m_incomingEdgePointB_GC = (hkVector4f)edgeBOut.m_quad;
      m_data[v19].m_oppositeEdge = *v39;
      m_data[v19].m_oppositeEdgePointA = (hkVector4f)v62.m_quad;
      v41 = v60.m_quad;
      m_data[v19].m_oppositeEdge.m_oppositeFace = v47;
      m_data[v19].m_incomingEdge.m_oppositeFace = v26;
      m_data[v19].m_incomingEdge.m_oppositeEdge = v29;
      m_data[v19].m_oppositeEdgePointB.m_quad = v41;
      m_data[v19].m_oppositeEdge.m_oppositeEdge = v69;
      if ( (v23->m_flags.m_storage & 0x10) != 0 && normalOut.m_quad.m128_u64[1] )
      {
        m_data[v19].m_incomingEdgeData = *(_DWORD *)normalOut.m_quad.m128_u64[1];
        m_data[v19].m_oppositeEdgeData = *(_DWORD *)normalOut.m_quad.m128_u64[0];
      }
      else
      {
        *(_QWORD *)&m_data[v19].m_incomingEdgeData = 0i64;
      }
      if ( v71 )
      {
        hkaiGeneralAccessor::setSection(accessor, v26 >> 22);
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
          &v66,
          (hkSimdFloat32 *)accessor->m_accessor,
          (hkaiNavMeshInstance *)(v26 & 0x3FFFFF),
          &m_data[v19].m_faceNormal.m_quad);
      }
      else
      {
        m_data[v19].m_faceNormal = (hkVector4f)upa->m_quad;
      }
      this = retaddr;
      ++v19;
      v18 = v53 + 1;
      v53 = v18;
    }
    while ( v18 < maxClearance.m_real.m128_i64[1] );
  }
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = (_QWORD *)v42[1];
  v44 = v42;
  if ( (unsigned __int64)v43 < v42[3] )
  {
    *v43 = "Et";
    v45 = __rdtsc();
    v46 = v43 + 2;
    *((_DWORD *)v46 - 2) = v45;
    v44[1] = v46;
  }
}

// File Line: 348
// RVA: 0xC21EB0
_BOOL8 __fastcall hkaiStringPulling::getSide(hkaiStringPulling *this, hkVector4f *a, hkVector4f *b, hkVector4f *p)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  __m128 v6; // xmm2
  __m128 v7; // xmm2

  v4 = _mm_sub_ps(b->m_quad, a->m_quad);
  v5 = _mm_sub_ps(p->m_quad, a->m_quad);
  v6 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v4), _mm_mul_ps(_mm_shuffle_ps(v4, v4, 201), v5));
  v7 = _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), this->m_up.m_quad);
  return (float)((float)(_mm_shuffle_ps(v7, v7, 85).m128_f32[0] + _mm_shuffle_ps(v7, v7, 0).m128_f32[0])
               + _mm_shuffle_ps(v7, v7, 170).m128_f32[0]) > 0.0;
}

// File Line: 389
// RVA: 0xC21D40
void __fastcall hkaiStringPulling::hkaiStringPulling(
        hkaiStringPulling *this,
        hkaiGeneralAccessor *accessor,
        hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdgeKeys,
        unsigned int startFaceKey,
        hkVector4f *startPoint,
        hkVector4f *endPoint,
        unsigned int project,
        unsigned int computeNormals,
        hkVector4f *up,
        float radius,
        hkaiPathWriter *writer)
{
  unsigned int v14; // eax
  int m_size; // eax
  __m128 m_quad; // xmm0

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v14 = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiStringPulling::`vftable;
  if ( radius != 0.0 )
    v14 = 0;
  this->m_radiusIsZero = v14;
  m_size = visitedEdgeKeys->m_size;
  this->m_accessor = accessor;
  this->m_pathLength = m_size;
  hkaiStringPulling::PathEdgeCache::PathEdgeCache(&this->m_pathEdgeCache, visitedEdgeKeys);
  hkaiStringPulling::Funnel::Funnel(&this->m_funnel);
  this->m_up = (hkVector4f)up->m_quad;
  this->m_startPoint = (hkVector4f)startPoint->m_quad;
  m_quad = endPoint->m_quad;
  this->m_writer = writer;
  this->m_endPoint.m_quad = m_quad;
  this->m_lastVertexInPath.m_index = -2;
  *(_DWORD *)&this->m_lastVertexInPath.m_side.m_storage = 255;
  this->m_lastVertexInPath.m_userEdgeSwapped.m_bool = 0;
  this->m_project = project;
  this->m_radius.m_real = _mm_shuffle_ps((__m128)LODWORD(radius), (__m128)LODWORD(radius), 0);
  this->m_lastVertexInPath.m_pos = 0i64;
  this->m_startFaceKey = startFaceKey;
  this->m_lastVertexInPath.m_center = (hkVector4f)aabbOut.m_quad;
  this->m_lastVertexInPath.m_clearanceIsNegative.m_bool = 0;
  this->m_lastVertexInPath.m_index = -1;
  this->m_lastVertexInPath.m_side.m_storage = -1;
  hkaiStringPulling::PathEdgeCache::cacheMeshData(
    &this->m_pathEdgeCache,
    accessor,
    startFaceKey,
    &this->m_up,
    computeNormals);
}

// File Line: 401
// RVA: 0xC22020
void __fastcall hkaiStringPulling::convertToTangent(
        hkaiStringPulling *this,
        hkVector4f *_start,
        hkVector4f *endInOut,
        hkaiStringPulling::Side side)
{
  if ( !this->m_radiusIsZero && side != -1 )
    hkaiStringPulling::convertToTangent(_start, &this->m_up, endInOut, &this->m_radius, side);
}

// File Line: 410
// RVA: 0xC22060
void __fastcall hkaiStringPulling::convertToTangent(
        hkVector4f *_start,
        hkVector4f *_up,
        hkVector4f *endInOut,
        hkSimdFloat32 *_radius,
        hkaiStringPulling::Side side)
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
            _mm_cmple_ps(v8, (__m128)0i64),
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
            _mm_cmple_ps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
              _mm_mul_ps(*(__m128 *)_xmm, v19))));
  v21 = _mm_mul_ps(v13, v13);
  v22 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v23 = _mm_rsqrt_ps(v22);
  v24 = _mm_andnot_ps(
          _mm_cmple_ps(v22, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)), _mm_mul_ps(*(__m128 *)_xmm, v23)));
  v25 = _mm_sub_ps(v22, _mm_mul_ps(v11, v11));
  v26 = _mm_rsqrt_ps(v25);
  v27 = _mm_mul_ps(v25, v24);
  v28 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v25, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)),
                  _mm_mul_ps(*(__m128 *)_xmm, v26)),
                v25)),
            v11),
          v24);
  if ( side == RIGHT )
    v29 = _mm_mul_ps(v20, v28);
  else
    v29 = _mm_mul_ps(v20, _mm_sub_ps((__m128)0i64, v28));
  v30 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)), _mm_shuffle_ps(v21, v21, 170));
  v31 = _mm_rsqrt_ps(v30);
  endInOut->m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_andnot_ps(
                             _mm_cmple_ps(v30, (__m128)0i64),
                             _mm_mul_ps(
                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                               _mm_mul_ps(*(__m128 *)_xmm, v31))),
                           v13),
                         v27),
                       _mm_add_ps(v29, v14));
}

// File Line: 465
// RVA: 0xC22300
void __fastcall hkaiStringPulling::convertToTangentNorm(
        hkaiStringPulling *this,
        hkVector4f *startInOut,
        hkVector4f *endInOut,
        hkaiStringPulling::Side side)
{
  __m128 m_quad; // xmm7
  __m128 v5; // xmm1
  __m128 v6; // xmm6
  __m128 v7; // xmm6
  __m128 v8; // xmm1
  __m128 v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm6

  if ( !this->m_radiusIsZero )
  {
    m_quad = endInOut->m_quad;
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
              _mm_cmple_ps(v9, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v10, v9), v10)),
                _mm_mul_ps(*(__m128 *)_xmm, v10))));
    if ( side == RIGHT )
    {
      endInOut->m_quad = _mm_add_ps(_mm_mul_ps(this->m_radius.m_real, v11), m_quad);
      startInOut->m_quad = _mm_add_ps(_mm_mul_ps(this->m_radius.m_real, v11), startInOut->m_quad);
    }
    else
    {
      endInOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, this->m_radius.m_real), v11), m_quad);
      startInOut->m_quad = _mm_add_ps(
                             _mm_mul_ps(_mm_sub_ps((__m128)0i64, this->m_radius.m_real), v11),
                             startInOut->m_quad);
    }
  }
}

// File Line: 492
// RVA: 0xC22400
void __fastcall hkaiStringPulling::convertToTangentCrossed(
        hkaiStringPulling *this,
        hkVector4f *startInOut,
        hkVector4f *endInOut,
        hkaiStringPulling::Side side)
{
  hkVector4f _start; // [rsp+20h] [rbp-18h] BYREF

  _start.m_quad = _mm_add_ps(
                    _mm_mul_ps(_mm_sub_ps(endInOut->m_quad, startInOut->m_quad), (__m128)xmmword_141A711B0),
                    startInOut->m_quad);
  hkaiStringPulling::convertToTangent(this, &_start, endInOut, side);
  hkaiStringPulling::convertToTangent(this, &_start, startInOut, side);
}

// File Line: 501
// RVA: 0xC226E0
__int64 __fastcall hkaiStringPulling::getIndex(hkaiStringPulling *this, int i, hkaiStringPulling::Side side)
{
  hkaiStringPulling::PathEdgeCache::PathEdge *v3; // rax

  if ( i < 0 || i >= this->m_pathLength )
    return 0xFFFFFFFFi64;
  v3 = &this->m_pathEdgeCache.m_pathEdges.m_data[(__int64)i];
  if ( side == RIGHT )
    return (unsigned int)v3->m_incomingEdge.m_b;
  else
    return (unsigned int)v3->m_incomingEdge.m_a;
}

// File Line: 514
// RVA: 0xC22470
__int64 __fastcall hkaiStringPulling::isUserEdge(hkaiStringPulling *this, int i)
{
  if ( i < 0 || i >= this->m_pathLength )
    return 0i64;
  else
    return this->m_pathEdgeCache.m_pathEdges.m_data[(__int64)i].m_incomingEdge.m_flags.m_storage & 0x10;
}

// File Line: 525
// RVA: 0xC22550
__int64 __fastcall hkaiStringPulling::getUserEdgeVertexPosition(
        hkaiStringPulling *this,
        int edgeIndex,
        hkaiStringPulling::Side side,
        hkVector4f *vertexOut)
{
  int m_start; // r14d
  int v7; // esi
  hkaiStringPulling::Funnel *p_m_funnel; // rcx
  __int64 v9; // rax
  unsigned __int8 v12; // bl
  __m128 v13; // xmm8
  __m128 v14; // xmm7
  hkaiStringPulling::Vertex *v15; // rax
  hkaiStringPulling::Funnel *v16; // rcx
  int m_apex; // eax
  hkVector4f v18; // xmm6
  __m128 v19; // xmm6
  hkaiStringPulling::Vertex *Apex; // rax
  hkVector4f *p_b; // rcx
  __int64 result; // rax
  hkVector4f b; // [rsp+20h] [rbp-78h] BYREF
  hkVector4f p; // [rsp+30h] [rbp-68h] BYREF

  m_start = this->m_funnel.m_start;
  v7 = this->m_funnel.m_data.m_size - 1;
  p_m_funnel = &this->m_funnel;
  v9 = *(_QWORD *)&p_m_funnel[-2].m_start + ((__int64)edgeIndex << 7);
  v12 = 0;
  v13 = *(__m128 *)(v9 + 48);
  v14 = *(__m128 *)(v9 + 64);
  b.m_quad = v13;
  p.m_quad = v14;
  v15 = hkaiStringPulling::Funnel::operator[](p_m_funnel, v7);
  v16 = &this->m_funnel;
  if ( v15->m_index == edgeIndex )
  {
    if ( !hkaiStringPulling::Funnel::operator[](v16, v7)->m_userEdgeSwapped.m_bool )
      goto LABEL_13;
  }
  else if ( hkaiStringPulling::Funnel::operator[](v16, m_start)->m_index == edgeIndex )
  {
    if ( !hkaiStringPulling::Funnel::operator[](&this->m_funnel, m_start)->m_userEdgeSwapped.m_bool )
      goto LABEL_13;
  }
  else
  {
    m_apex = this->m_funnel.m_apex;
    if ( v7 == m_apex || m_start == m_apex )
    {
      Apex = hkaiStringPulling::Funnel::getApex(&this->m_funnel);
      if ( hkaiStringPulling::getSide(this, &Apex->m_pos, &b, &p) )
        goto LABEL_13;
    }
    else
    {
      v18.m_quad = (__m128)hkaiStringPulling::Funnel::operator[](&this->m_funnel, m_start)->m_pos;
      v19 = _mm_mul_ps(
              _mm_sub_ps(v18.m_quad, hkaiStringPulling::Funnel::operator[](&this->m_funnel, v7)->m_pos.m_quad),
              _mm_sub_ps(v14, v13));
      if ( (float)((float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] + _mm_shuffle_ps(v19, v19, 0).m128_f32[0])
                 + _mm_shuffle_ps(v19, v19, 170).m128_f32[0]) >= 0.0 )
        goto LABEL_13;
    }
  }
  v12 = 1;
  p.m_quad = v13;
  b.m_quad = v14;
LABEL_13:
  p_b = &b;
  if ( side )
    p_b = &p;
  result = v12;
  *vertexOut = (hkVector4f)p_b->m_quad;
  return result;
}

// File Line: 592
// RVA: 0xC224A0
__int64 __fastcall hkaiStringPulling::getVertexPosition(
        hkaiStringPulling *this,
        int edgeIndex,
        hkaiStringPulling::Side side,
        hkVector4f *vertexOut,
        bool *userEdgeSwapped)
{
  __int64 v5; // rsi
  __int64 result; // rax
  hkaiStringPulling::PathEdgeCache::PathEdge *v10; // rax
  hkVector4f v11; // xmm0

  v5 = edgeIndex;
  *userEdgeSwapped = 0;
  if ( edgeIndex >= this->m_pathLength )
  {
    result = 0i64;
    *vertexOut = this->m_endPoint;
  }
  else if ( (unsigned int)hkaiStringPulling::isUserEdge(this, edgeIndex) )
  {
    *userEdgeSwapped = hkaiStringPulling::getUserEdgeVertexPosition(this, v5, side, vertexOut);
    return 1i64;
  }
  else
  {
    v10 = &this->m_pathEdgeCache.m_pathEdges.m_data[v5];
    if ( side == RIGHT )
      v11.m_quad = (__m128)v10->m_incomingEdgePointB_GC;
    else
      v11.m_quad = (__m128)v10->m_incomingEdgePointA_GC;
    result = 1i64;
    *vertexOut = (hkVector4f)v11.m_quad;
  }
  return result;
}

// File Line: 614
// RVA: 0xC22710
void __fastcall hkaiStringPulling::getVertex(hkaiStringPulling *this, hkaiStringPulling::Vertex *inOut)
{
  __m128 m_quad; // xmm2
  bool v5; // al
  hkVector4f vertexOut; // [rsp+30h] [rbp-18h] BYREF
  bool userEdgeSwapped; // [rsp+50h] [rbp+8h] BYREF

  hkaiStringPulling::getVertexPosition(
    this,
    inOut->m_index,
    (hkaiStringPulling::Side)(unsigned __int8)inOut->m_side.m_storage,
    &vertexOut,
    &userEdgeSwapped);
  m_quad = vertexOut.m_quad;
  inOut->m_center = (hkVector4f)vertexOut.m_quad;
  inOut->m_clearanceIsNegative.m_bool = _mm_shuffle_ps(m_quad, m_quad, 255).m128_f32[0] < 0.0;
  v5 = userEdgeSwapped;
  inOut->m_pos.m_quad = m_quad;
  inOut->m_userEdgeSwapped.m_bool = v5;
  if ( inOut->m_index < this->m_pathLength )
  {
    if ( (unsigned int)hkaiStringPulling::isUserEdge(this, inOut->m_index) )
      inOut->m_userEdge.m_bool = 1;
  }
  else
  {
    inOut->m_side.m_storage = -1;
  }
}

// File Line: 634
// RVA: 0xC22A80
bool __fastcall hkaiStringPulling::isShared(hkaiStringPulling *this, int i, hkaiStringPulling::Side side)
{
  hkaiStringPulling::PathEdgeCache::PathEdge *v5; // rbx
  int Index; // edx
  int m_a; // ecx

  if ( i + 1 >= this->m_pathLength )
    return 0;
  v5 = &this->m_pathEdgeCache.m_pathEdges.m_data[(__int64)i];
  if ( (v5->m_incomingEdge.m_flags.m_storage & 0x40) != 0 )
    return 0;
  Index = hkaiStringPulling::getIndex(this, i + 1, side);
  if ( side == RIGHT )
    m_a = v5->m_oppositeEdge.m_a;
  else
    m_a = v5->m_oppositeEdge.m_b;
  return m_a == Index;
}

// File Line: 655
// RVA: 0xC227A0
void __fastcall hkaiStringPulling::genericTangent(
        hkaiStringPulling *this,
        hkVector4f *start,
        hkaiStringPulling::Side startSide,
        hkVector4f *end,
        hkaiStringPulling::Side endSide)
{
  if ( startSide == -1 )
  {
    hkaiStringPulling::convertToTangent(this, start, end, endSide);
  }
  else if ( endSide == -1 )
  {
    if ( startSide )
    {
      if ( startSide == RIGHT )
        hkaiStringPulling::convertToTangent(this, end, start, LEFT);
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
void __fastcall hkaiStringPulling::genericTangent(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *start,
        hkaiStringPulling::Vertex *end)
{
  hkaiStringPulling::Side v4; // r8d
  hkaiStringPulling::Side endSide; // eax
  unsigned __int8 m_storage; // cl

  v4 = -1;
  if ( end->m_userEdge.m_bool
    || (LOBYTE(endSide) = end->m_side.m_storage, (_BYTE)endSide == 0xFF)
    || (endSide = (unsigned __int8)endSide, !end->m_clearanceIsNegative.m_bool) )
  {
    endSide = -1;
  }
  if ( !start->m_userEdge.m_bool )
  {
    m_storage = start->m_side.m_storage;
    if ( m_storage != 0xFF )
    {
      if ( start->m_clearanceIsNegative.m_bool )
        v4 = m_storage;
    }
  }
  hkaiStringPulling::genericTangent(this, &start->m_pos, v4, &end->m_pos, endSide);
}

// File Line: 681
// RVA: 0xC234E0
__int64 __fastcall hkaiStringPulling::handleUserEdge(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *vertex,
        int index)
{
  __int64 result; // rax
  int m_funnelIndex; // r14d
  hkaiStringPulling::Funnel *m_funnel; // r15
  hkaiStringPulling::Vertex *v7; // rax
  int v8; // r13d
  hkaiStringPulling::Funnel *v9; // rsi
  hkVector4f v10; // xmm7
  hkaiStringPulling::Vertex *v11; // rax
  int v12; // esi
  int *v13; // r15
  __m128 v14; // xmm7
  int v15; // r8d
  int m_apex; // ebx
  __m128 v17; // xmm2
  int v18; // eax
  int v19; // ecx
  __int64 v20; // r8
  hkaiStringPulling::Vertex *m_data; // rax
  __int64 v22; // r8
  __m128i v23; // xmm6
  hkVector4f v24; // xmm8
  hkVector4f v25; // xmm9
  char v26; // al
  __m128 v27; // xmm0
  hkaiStringPulling::Vertex *v28; // rsi
  __m128 v29; // xmm1
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm5
  __m128 v34; // xmm7
  __m128 v35; // xmm5
  hkVector4f v36; // xmm8
  hkVector4f v37; // xmm0
  __m128 v38; // xmm8
  __m128 v39; // xmm1
  __m128 v40; // xmm7
  int v41; // ebx
  hkOstream *v42; // rax
  hkOstream *v43; // rax
  hkVector4f v44; // xmm6
  hkVector4f v45; // xmm0
  hkaiStringPulling::Vertex *Apex; // rax
  hkaiStringPulling::PathEdgeCache::PathEdge *v47; // rax
  __m128 m_quad; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm7
  hkaiStringPulling::Vertex *v51; // rcx
  hkaiStringPulling::Funnel::Iterator v52; // [rsp+20h] [rbp-E0h] BYREF
  hkaiStringPulling::Funnel::Iterator other; // [rsp+30h] [rbp-D0h] BYREF
  int v54[2]; // [rsp+40h] [rbp-C0h] BYREF
  hkaiStringPulling::Funnel::Iterator v55; // [rsp+48h] [rbp-B8h] BYREF
  hkaiStringPulling::Vertex start; // [rsp+60h] [rbp-A0h] BYREF
  hkErrStream v57[2]; // [rsp+90h] [rbp-70h] BYREF
  hkaiStringPulling::Vertex end; // [rsp+C0h] [rbp-40h] BYREF
  char buf[512]; // [rsp+F0h] [rbp-10h] BYREF
  bool v62; // [rsp+388h] [rbp+288h]

  result = hkaiStringPulling::isUserEdge(this, index);
  if ( (_DWORD)result )
  {
    hkaiStringPulling::Funnel::Iterator::Iterator(&v52, &this->m_funnel, 1, -1);
    hkaiStringPulling::Funnel::Iterator::Iterator(&v55, &this->m_funnel, 0, -1);
    m_funnelIndex = v55.m_funnelIndex;
    m_funnel = v55.m_funnel;
    v7 = hkaiStringPulling::Funnel::operator[](v55.m_funnel, v55.m_funnelIndex);
    v8 = v52.m_funnelIndex;
    v9 = v52.m_funnel;
    if ( hkaiStringPulling::Funnel::operator[](v52.m_funnel, v52.m_funnelIndex)->m_index != v7->m_index )
      return 1i64;
    v62 = hkaiStringPulling::Funnel::operator[](v9, v8)->m_userEdgeSwapped.m_bool != 0;
    v10.m_quad = (__m128)hkaiStringPulling::Funnel::operator[](v9, v8)->m_pos;
    v11 = hkaiStringPulling::Funnel::operator[](m_funnel, m_funnelIndex);
    v12 = 0;
    v13 = v54;
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
      hkaiStringPulling::Funnel::Iterator::Iterator(
        (hkaiStringPulling::Funnel::Iterator *)v57,
        &this->m_funnel,
        v15,
        -1);
      m_apex = this->m_funnel.m_apex;
      HIDWORD(v57[0].vfptr) = m_apex;
      other = (hkaiStringPulling::Funnel::Iterator)v57[0].hkReferencedObject;
      hkaiStringPulling::Funnel::Iterator::operator++(&other, 0);
      if ( (unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&other) )
      {
        while ( 1 )
        {
          start = *hkaiStringPulling::Funnel::operator[](
                     *(hkaiStringPulling::Funnel **)&v57[0].m_memSizeAndFlags,
                     m_apex);
          end = *hkaiStringPulling::Funnel::operator[](other.m_funnel, other.m_funnelIndex);
          hkaiStringPulling::genericTangent(this, &start, &end);
          v17 = _mm_mul_ps(_mm_sub_ps(end.m_pos.m_quad, start.m_pos.m_quad), v14);
          if ( (float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
                     + _mm_shuffle_ps(v17, v17, 170).m128_f32[0]) < 0.0 == (v12 == 0) )
            break;
          hkaiStringPulling::addSegmentToPath(this, &start, &end);
          hkaiStringPulling::Funnel::Iterator::operator=((hkaiStringPulling::Funnel::Iterator *)v57, &other);
          other = (hkaiStringPulling::Funnel::Iterator)v57[0].hkReferencedObject;
          hkaiStringPulling::Funnel::Iterator::operator++(&other, 0);
          if ( !(unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&other) )
            goto LABEL_14;
          m_apex = HIDWORD(v57[0].vfptr);
        }
        *v13 = m_apex;
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
    v18 = this->m_funnel.m_apex;
    if ( v54[1] == v18 )
    {
      v19 = 0;
    }
    else
    {
      if ( v54[0] != v18 )
      {
        hkErrStream::hkErrStream(v57, buf, 512);
        v42 = hkOstream::operator<<(&v57[0], "Cannot handle user edge ");
        v41 = index;
        v43 = hkOstream::operator<<(v42, index);
        hkOstream::operator<<(v43, ". Is this edge not completely contained in its face?");
        hkError::messageWarning(773745910, buf, "NavMesh\\Smoothing\\hkaiStringPulling.cpp", 761);
        hkOstream::~hkOstream(&v57[0]);
        v40 = (__m128)xmmword_141A711B0;
        start = *hkaiStringPulling::Funnel::operator[](v52.m_funnel, v8);
        v44.m_quad = (__m128)start.m_pos;
        v45.m_quad = (__m128)hkaiStringPulling::Funnel::operator[](v55.m_funnel, v55.m_funnelIndex)->m_pos;
        start.m_side.m_storage = -1;
        start.m_pos.m_quad = _mm_add_ps(
                               v44.m_quad,
                               _mm_mul_ps(_mm_sub_ps(v45.m_quad, v44.m_quad), (__m128)xmmword_141A711B0));
        Apex = hkaiStringPulling::Funnel::getApex(&this->m_funnel);
        hkaiStringPulling::addSegmentToPath(this, Apex, &start);
        v28 = vertex;
LABEL_32:
        if ( v62 )
          v40 = _mm_sub_ps(query.m_quad, v40);
        hkaiStringPulling::Funnel::clear(&this->m_funnel);
        WORD2(v57[0].vfptr) = 255;
        *(_WORD *)((char *)&v57[0].vfptr + 7) = 1;
        v47 = &this->m_pathEdgeCache.m_pathEdges.m_data[(__int64)v41];
        m_quad = v47->m_oppositeEdgePointB.m_quad;
        v49 = v47->m_oppositeEdgePointA.m_quad;
        LODWORD(v57[0].vfptr) = v28->m_index;
        LODWORD(v47) = this->m_funnel.m_data.m_capacityAndFlags;
        v50 = _mm_add_ps(
                _mm_mul_ps(_mm_max_ps(_mm_min_ps(v40, query.m_quad), aabbOut.m_quad), _mm_sub_ps(v49, m_quad)),
                m_quad);
        BYTE6(v57[0].vfptr) = _mm_shuffle_ps(v50, v50, 255).m128_f32[0] < 0.0;
        if ( this->m_funnel.m_data.m_size == ((unsigned int)v47 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &this->m_funnel.m_data, 48);
        v51 = &this->m_funnel.m_data.m_data[this->m_funnel.m_data.m_size];
        if ( v51 )
        {
          *(hkReferencedObject *)&v51->m_index = v57[0].hkReferencedObject;
          v51->m_pos.m_quad = v50;
          v51->m_center.m_quad = v50;
        }
        ++this->m_funnel.m_data.m_size;
        this->m_funnel.m_apex = 0;
        return 1i64;
      }
      v19 = 1;
    }
    v20 = v54[v19];
    if ( (_DWORD)v20 == -1 )
    {
      v41 = index;
      v28 = vertex;
      if ( v19 == 1 )
        v40 = query.m_quad;
      else
        v40 = aabbOut.m_quad;
    }
    else
    {
      m_data = this->m_funnel.m_data.m_data;
      v22 = v20;
      *(_OWORD *)&end.m_index = *(_OWORD *)&m_data[v22].m_index;
      v23 = *(__m128i *)&end.m_index;
      v24.m_quad = (__m128)m_data[v22].m_pos;
      end.m_pos = (hkVector4f)v24.m_quad;
      end.m_center = m_data[v22].m_center;
      v25.m_quad = (__m128)hkaiStringPulling::Funnel::operator[](v55.m_funnel, v55.m_funnelIndex)->m_pos;
      v26 = _mm_cvtsi128_si32(_mm_srli_si128(v23, 4));
      if ( v26 == 1 )
      {
        v52 = (hkaiStringPulling::Funnel::Iterator)_mm_sub_ps((__m128)0i64, query.m_quad);
      }
      else
      {
        if ( v26 )
          v27 = aabbOut.m_quad;
        else
          v27 = query.m_quad;
        v52 = (hkaiStringPulling::Funnel::Iterator)v27;
      }
      v28 = vertex;
      v29 = _mm_mul_ps(v14, v14);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
              _mm_shuffle_ps(v29, v29, 170));
      v31 = _mm_rsqrt_ps(v30);
      v32 = _mm_mul_ps(this->m_radius.m_real, (__m128)v52);
      v33 = _mm_andnot_ps(
              _mm_cmple_ps(v30, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v31, v30), v31)),
                _mm_mul_ps(*(__m128 *)_xmm, v31)));
      start.m_pos = vertex->m_pos;
      v34 = _mm_mul_ps(v14, v33);
      v35 = _mm_mul_ps(v33, v30);
      v36.m_quad = _mm_add_ps(v24.m_quad, _mm_mul_ps(v32, v34));
      *(_OWORD *)&start.m_index = *(_OWORD *)&vertex->m_index;
      v37.m_quad = (__m128)vertex->m_center;
      end.m_pos = (hkVector4f)v36.m_quad;
      start.m_center = (hkVector4f)v37.m_quad;
      v38 = _mm_mul_ps(_mm_sub_ps(v36.m_quad, v25.m_quad), v34);
      v39 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
              _mm_shuffle_ps(v38, v38, 170));
      start.m_pos.m_quad = _mm_add_ps(_mm_mul_ps(v34, v39), v25.m_quad);
      v40 = _mm_andnot_ps(_mm_cmpeq_ps(v35, (__m128)0i64), _mm_div_ps(v39, v35));
      hkaiStringPulling::addSegmentToPath(this, &end, &start);
      v41 = index;
    }
    goto LABEL_32;
  }
  return result;
}

// File Line: 847
// RVA: 0xC23B30
__int64 __fastcall hkaiStringPulling::isCloser(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *s,
        hkaiStringPulling::Vertex *e,
        hkaiStringPulling::Vertex *p,
        int lastEdgeIndex)
{
  hkVector4f v5; // xmm4
  hkVector4f *p_m_pos; // r15
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
  hkVector4f v22; // [rsp+30h] [rbp-68h] BYREF
  hkVector4f vertexOut; // [rsp+40h] [rbp-58h] BYREF
  bool userEdgeSwapped; // [rsp+A0h] [rbp+8h] BYREF

  v5.m_quad = (__m128)this->m_up;
  p_m_pos = &s->m_pos;
  v10 = 1;
  v11 = _mm_sub_ps(p->m_pos.m_quad, s->m_pos.m_quad);
  v12 = _mm_sub_ps(e->m_pos.m_quad, s->m_pos.m_quad);
  v13 = _mm_mul_ps(v5.m_quad, v11);
  v14 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)), _mm_shuffle_ps(v13, v13, 170));
  v15 = _mm_mul_ps(v5.m_quad, v12);
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
    hkaiStringPulling::getVertexPosition(this, lastEdgeIndex, LEFT, &vertexOut, &userEdgeSwapped);
    hkaiStringPulling::getVertexPosition(this, lastEdgeIndex, RIGHT, &v22, &userEdgeSwapped);
    v18 = _mm_mul_ps(_mm_sub_ps(v22.m_quad, vertexOut.m_quad), v17);
    if ( (float)((float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] + _mm_shuffle_ps(v18, v18, 0).m128_f32[0])
               + _mm_shuffle_ps(v18, v18, 170).m128_f32[0]) > 0.0 == (e->m_side.m_storage == 0) )
      return 0i64;
  }
  v20 = _mm_mul_ps(v16, v16);
  v21 = _mm_mul_ps(v17, v17);
  if ( (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
             + _mm_shuffle_ps(v20, v20, 170).m128_f32[0]) >= (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0]
                                                                           + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                                                                   + _mm_shuffle_ps(v21, v21, 170).m128_f32[0])
    || hkaiStringPulling::getSide(this, p_m_pos, &e->m_center, &p->m_center) == e->m_side.m_storage )
  {
    return 0;
  }
  return v10;
}

// File Line: 885
// RVA: 0xC23CF0
_BOOL8 __fastcall hkaiStringPulling::isUndefinedTangentVertexAddable(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *wedgeStart,
        hkaiStringPulling::Vertex *wedgeEnd,
        hkaiStringPulling::Vertex *p)
{
  hkVector4f v4; // xmm1
  hkVector4f v8; // xmm0
  hkVector4f v9; // xmm1
  unsigned __int8 m_storage; // al
  __m128 v11; // xmm7
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  hkVector4f v14; // xmm6
  int v15; // edi
  int Side; // eax
  bool v17; // bp
  hkVector4f b; // [rsp+20h] [rbp-A8h] BYREF
  hkVector4f pa; // [rsp+30h] [rbp-98h] BYREF
  hkaiStringPulling::Vertex end; // [rsp+40h] [rbp-88h] BYREF
  hkaiStringPulling::Vertex v22; // [rsp+70h] [rbp-58h] BYREF

  v4.m_quad = (__m128)wedgeEnd->m_pos;
  *(_OWORD *)&end.m_index = *(_OWORD *)&wedgeEnd->m_index;
  v8.m_quad = (__m128)wedgeEnd->m_center;
  end.m_pos = (hkVector4f)v4.m_quad;
  v9.m_quad = (__m128)wedgeStart->m_pos;
  end.m_center = (hkVector4f)v8.m_quad;
  *(_OWORD *)&v22.m_index = *(_OWORD *)&wedgeStart->m_index;
  v22.m_center = wedgeStart->m_center;
  v22.m_pos = (hkVector4f)v9.m_quad;
  hkaiStringPulling::genericTangent(this, &v22, &end);
  m_storage = wedgeEnd->m_side.m_storage;
  v11 = _mm_sub_ps(end.m_pos.m_quad, v22.m_pos.m_quad);
  v12 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), this->m_up.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(this->m_up.m_quad, this->m_up.m_quad, 201), v11));
  v13 = _mm_shuffle_ps(v12, v12, 201);
  if ( m_storage == 1 )
    v13 = _mm_xor_ps(v13, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  v14.m_quad = (__m128)wedgeEnd->m_center;
  v15 = m_storage;
  b.m_quad = _mm_add_ps(v14.m_quad, v13);
  Side = hkaiStringPulling::getSide(this, &wedgeEnd->m_center, &b, &p->m_center);
  pa.m_quad = (__m128)p->m_center;
  b.m_quad = _mm_sub_ps(v14.m_quad, v11);
  v17 = Side != v15;
  return hkaiStringPulling::getSide(this, &b, &wedgeEnd->m_center, &pa) == v15 || !v17;
}

// File Line: 921
// RVA: 0xC22890
char __fastcall hkaiStringPulling::checkTermination(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *vertex,
        hkaiStringPulling::Side side,
        int index)
{
  int v8; // r8d
  int isValid; // eax
  char m_storage; // cl
  __int128 v11; // xmm0
  hkVector4f v12; // xmm1
  char v13; // al
  hkVector4f v14; // xmm0
  char v15; // al
  hkVector4f v16; // xmm1
  hkVector4f v17; // xmm0
  char m_bool; // al
  hkaiStringPulling::Funnel::Iterator v19; // [rsp+20h] [rbp-59h] BYREF
  hkaiStringPulling::Vertex start; // [rsp+30h] [rbp-49h] BYREF
  hkaiStringPulling::Funnel::Iterator v21; // [rsp+60h] [rbp-19h] BYREF
  hkaiStringPulling::Vertex end; // [rsp+70h] [rbp-9h] BYREF
  hkaiStringPulling::Vertex b; // [rsp+A0h] [rbp+27h] BYREF

  if ( hkaiStringPulling::handleUserEdge(this, vertex, index) || vertex->m_index != this->m_pathLength )
    return 0;
  if ( side )
  {
    if ( side == RIGHT )
      v8 = 0;
    else
      v8 = -1;
  }
  else
  {
    v8 = 1;
  }
  hkaiStringPulling::Funnel::Iterator::Iterator(&v21, &this->m_funnel, v8, this->m_funnel.m_apex);
  v19 = v21;
  hkaiStringPulling::Funnel::Iterator::operator++(&v19, 0);
  if ( (unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&v19) )
  {
    while ( 1 )
    {
      start = *hkaiStringPulling::Funnel::operator[](v21.m_funnel, v21.m_funnelIndex);
      end = *hkaiStringPulling::Funnel::operator[](v19.m_funnel, v19.m_funnelIndex);
      hkaiStringPulling::genericTangent(this, &start, &end);
      if ( (unsigned int)hkaiStringPulling::undefinedTangent(this, &start, vertex) )
        break;
      hkaiStringPulling::Funnel::Iterator::operator++(&v21, 0);
      hkaiStringPulling::Funnel::Iterator::operator++(&v19, 0);
      isValid = hkaiStringPulling::Funnel::Iterator::isValid(&v19);
      m_storage = end.m_type.m_storage;
      if ( !isValid )
        m_storage = 2;
      end.m_type.m_storage = m_storage;
      hkaiStringPulling::addSegmentToPath(this, &start, &end);
      if ( !(unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&v19) )
        return 1;
    }
    v11 = *(_OWORD *)&vertex->m_index;
    v12.m_quad = (__m128)vertex->m_pos;
    start.m_index = this->m_lastVertexInPath.m_index;
    v13 = this->m_lastVertexInPath.m_side.m_storage;
    *(_OWORD *)&b.m_index = v11;
    v14.m_quad = (__m128)vertex->m_center;
    b.m_pos = (hkVector4f)v12.m_quad;
    start.m_side.m_storage = v13;
    v15 = this->m_lastVertexInPath.m_type.m_storage;
    v16.m_quad = (__m128)this->m_lastVertexInPath.m_center;
    b.m_center = (hkVector4f)v14.m_quad;
    v17.m_quad = (__m128)this->m_lastVertexInPath.m_pos;
    start.m_type.m_storage = v15;
    start.m_clearanceIsNegative.m_bool = this->m_lastVertexInPath.m_clearanceIsNegative.m_bool;
    m_bool = this->m_lastVertexInPath.m_userEdge.m_bool;
    start.m_pos = (hkVector4f)v17.m_quad;
    start.m_center = (hkVector4f)v16.m_quad;
    start.m_userEdge.m_bool = m_bool;
    start.m_userEdgeSwapped.m_bool = this->m_lastVertexInPath.m_userEdgeSwapped.m_bool;
    hkaiStringPulling::addSegmentToPath(this, &start, &b);
  }
  return 1;
}

// File Line: 975
// RVA: 0xC21F10
__int64 __fastcall hkaiStringPulling::undefinedTangent(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *a,
        hkaiStringPulling::Vertex *b)
{
  int v3; // eax
  int v5; // r9d
  unsigned __int8 m_storage; // cl
  unsigned int v7; // r10d
  hkVector4f v8; // xmm3
  __m128 v9; // xmm6
  __m128 v10; // xmm2
  __m128 v11; // xmm6
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm1

  v3 = -1;
  if ( a->m_userEdge.m_bool
    || (LOBYTE(v5) = a->m_side.m_storage, (_BYTE)v5 == 0xFF)
    || (v5 = (unsigned __int8)v5, !a->m_clearanceIsNegative.m_bool) )
  {
    v5 = -1;
  }
  if ( !b->m_userEdge.m_bool )
  {
    m_storage = b->m_side.m_storage;
    if ( m_storage != 0xFF )
    {
      if ( b->m_clearanceIsNegative.m_bool )
        v3 = m_storage;
    }
  }
  v7 = 0;
  if ( (v5 == -1) == (v3 == -1) )
    return 0i64;
  v8.m_quad = (__m128)this->m_up;
  v9 = _mm_sub_ps(b->m_center.m_quad, a->m_center.m_quad);
  v10 = _mm_mul_ps(v8.m_quad, v9);
  v11 = _mm_add_ps(
          v9,
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                _mm_shuffle_ps(v10, v10, 170))),
            v8.m_quad));
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  LOBYTE(v7) = _mm_andnot_ps(
                 _mm_cmple_ps(v13, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                     _mm_mul_ps(*(__m128 *)_xmm, v14)),
                   v13)).m128_f32[0] < this->m_radius.m_real.m128_f32[0];
  return v7;
}

// File Line: 990
// RVA: 0xC24890
char __fastcall hkaiStringPulling::terminateOutput(hkaiStringPulling *this)
{
  hkaiPathWriter *m_writer; // rcx

  m_writer = this->m_writer;
  if ( m_writer->m_pathArrayOut || m_writer->m_totalNumOutput < m_writer->m_maxNumOutput )
  {
    hkaiPathWriter::addTerminatorToPathPointer(m_writer);
    return 1;
  }
  else
  {
    hkaiPathWriter::addTerminatorToPathPointer(m_writer);
    return 0;
  }
}

// File Line: 1000
// RVA: 0xC24280
void __fastcall hkaiStringPulling::addVertexToPath(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *a,
        char pointType)
{
  __int64 m_index; // rax
  int edgeData; // r10d
  int m_pathLength; // ecx
  hkaiStringPulling::PathEdgeCache::PathEdge *m_data; // rax
  __int64 v9; // rcx
  unsigned int m_startFaceKey; // r9d
  __m128 m_quad; // xmm0
  __int64 v12; // rdx
  __int64 v13; // rcx
  hkaiStringPulling::PathEdgeCache::PathEdge *v14; // rax
  int v15; // r9d
  hkaiPathWriter *m_writer; // rcx
  hkVector4f normal; // [rsp+30h] [rbp-18h] BYREF

  m_index = a->m_index;
  edgeData = 0;
  normal.m_quad = aabbOut.m_quad;
  if ( (int)m_index < 0 || (m_pathLength = this->m_pathLength) == 0 )
  {
    m_startFaceKey = this->m_startFaceKey;
    m_quad = this->m_pathEdgeCache.m_startFaceNormal.m_quad;
    goto LABEL_11;
  }
  if ( (int)m_index >= m_pathLength )
  {
    m_data = this->m_pathEdgeCache.m_pathEdges.m_data;
    v9 = (__int64)(m_pathLength - 1) << 7;
    m_startFaceKey = *(unsigned int *)((char *)&m_data->m_incomingEdge.m_oppositeFace + v9);
    m_quad = *(__m128 *)((char *)&m_data->m_faceNormal.m_quad + v9);
LABEL_11:
    v15 = m_startFaceKey >> 22;
    goto LABEL_12;
  }
  v12 = m_index;
  if ( (pointType & 2) != 0 )
  {
    v13 = m_index;
    v14 = this->m_pathEdgeCache.m_pathEdges.m_data;
    v13 <<= 7;
    edgeData = *(int *)((char *)&v14->m_oppositeEdgeData + v13);
    v15 = *(unsigned int *)((char *)&v14->m_incomingEdge.m_oppositeEdge + v13) >> 22;
    m_quad = v14[v12].m_faceNormal.m_quad;
  }
  else
  {
    v15 = this->m_pathEdgeCache.m_pathEdgeKeys->m_data[m_index] >> 22;
    if ( a->m_userEdge.m_bool )
      edgeData = this->m_pathEdgeCache.m_pathEdges.m_data[m_index].m_incomingEdgeData;
    m_quad = this->m_pathEdgeCache.m_pathEdges.m_data[m_index].m_faceNormal.m_quad;
  }
LABEL_12:
  m_writer = this->m_writer;
  normal.m_quad = m_quad;
  hkaiPathWriter::addPointToPath(m_writer, &a->m_pos, &normal, v15, edgeData, pointType);
  this->m_lastVertexInPath.m_index = a->m_index;
  this->m_lastVertexInPath.m_side.m_storage = a->m_side.m_storage;
  this->m_lastVertexInPath.m_type.m_storage = a->m_type.m_storage;
  this->m_lastVertexInPath.m_clearanceIsNegative.m_bool = a->m_clearanceIsNegative.m_bool;
  this->m_lastVertexInPath.m_userEdge.m_bool = a->m_userEdge.m_bool;
  this->m_lastVertexInPath.m_userEdgeSwapped.m_bool = a->m_userEdgeSwapped.m_bool;
  this->m_lastVertexInPath.m_pos = a->m_pos;
  this->m_lastVertexInPath.m_center = a->m_center;
}

// File Line: 1050
// RVA: 0xC243D0
void __fastcall hkaiStringPulling::addSegmentToPath(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *a,
        hkaiStringPulling::Vertex *b)
{
  char v3; // bl
  char v7; // r12
  int v8; // ebx
  __int64 v9; // rsi
  hkVector4f v10; // xmm10
  hkaiStringPulling::PathEdgeCache::PathEdge *m_data; // rax
  __m128 v12; // xmm13
  __m128 v13; // xmm7
  hkVector4f v14; // xmm5
  hkVector4f v15; // xmm11
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
  hkaiStringPulling::Vertex aa; // [rsp+20h] [rbp-E0h] BYREF
  hkaiStringPulling::Vertex projOut; // [rsp+50h] [rbp-B0h] BYREF
  hkaiStringPulling::Vertex v53; // [rsp+80h] [rbp-80h] BYREF

  v3 = 4;
  if ( a->m_userEdge.m_bool )
    v3 = 6;
  v7 = (b->m_userEdge.m_bool != 0) + 8;
  if ( !this->m_project )
  {
    hkaiStringPulling::addVertexToPath(this, a, v3);
    hkaiStringPulling::addVertexToPath(this, b, v7);
    return;
  }
  projOut.m_index = -2;
  *(_DWORD *)&projOut.m_side.m_storage = 255;
  projOut.m_userEdgeSwapped.m_bool = 0;
  hkaiStringPulling::projectSegmentEndpoint(this, a, &projOut);
  hkaiStringPulling::addVertexToPath(this, &projOut, v3);
  v8 = a->m_index + 1;
  if ( v8 <= b->m_index )
  {
    v9 = (__int64)v8 << 7;
    do
    {
      if ( v8 >= this->m_pathLength )
        break;
      v10.m_quad = (__m128)this->m_up;
      m_data = this->m_pathEdgeCache.m_pathEdges.m_data;
      v12 = *(__m128 *)((char *)&m_data->m_incomingEdgePointA_GC.m_quad + v9);
      v13 = _mm_sub_ps(*(__m128 *)((char *)&m_data->m_incomingEdgePointB_GC.m_quad + v9), v12);
      v14.m_quad = (__m128)a->m_pos;
      v15.m_quad = (__m128)b->m_pos;
      v16 = _mm_shuffle_ps(v13, v13, 201);
      v17 = _mm_sub_ps(_mm_mul_ps(v10.m_quad, v16), _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 201), v13));
      v18 = _mm_shuffle_ps(v17, v17, 201);
      v19 = _mm_mul_ps(v18, v18);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      v21 = _mm_rsqrt_ps(v20);
      v22 = _mm_mul_ps(
              v18,
              _mm_andnot_ps(
                _mm_cmple_ps(v20, (__m128)0i64),
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
      v25 = _mm_mul_ps(v24, v14.m_quad);
      v26 = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v24), 196);
      v27 = _mm_add_ps(_mm_shuffle_ps(v26, v26, 78), v26);
      v28 = _mm_mul_ps(v24, v15.m_quad);
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
                  _mm_sub_ps(v15.m_quad, v14.m_quad),
                  _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v35, v34)), v35), v29)),
                v14.m_quad);
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
                  _mm_cmple_ps(v40, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v41, v40), v41)),
                    _mm_mul_ps(v41, *(__m128 *)_xmm))));
        v43 = _mm_mul_ps(v42, v12);
        v44 = _mm_mul_ps(v42, v10.m_quad);
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
                              v10.m_quad));
        aa.m_center.m_quad = _mm_shuffle_ps(aa.m_pos.m_quad, _mm_unpackhi_ps(aa.m_pos.m_quad, aa.m_center.m_quad), 196);
        v48 = _mm_mul_ps(_mm_sub_ps(aa.m_pos.m_quad, v12), v13);
        v49 = _mm_mul_ps(v13, v13);
        v50 = (float)(_mm_shuffle_ps(v48, v48, 85).m128_f32[0] + _mm_shuffle_ps(v48, v48, 0).m128_f32[0])
            + _mm_shuffle_ps(v48, v48, 170).m128_f32[0];
        if ( v50 >= 0.0
          && v50 <= (float)((float)(_mm_shuffle_ps(v49, v49, 85).m128_f32[0] + _mm_shuffle_ps(v49, v49, 0).m128_f32[0])
                          + _mm_shuffle_ps(v49, v49, 170).m128_f32[0]) )
        {
          hkaiStringPulling::addVertexToPath(this, &aa, 0);
        }
      }
      ++v8;
      v9 += 128i64;
    }
    while ( v8 <= b->m_index );
  }
  v53.m_index = -2;
  *(_DWORD *)&v53.m_side.m_storage = 255;
  v53.m_userEdgeSwapped.m_bool = 0;
  hkaiStringPulling::projectSegmentEndpoint(this, b, &v53);
  hkaiStringPulling::addVertexToPath(this, &v53, v7);
}

// File Line: 1122
// RVA: 0xC248E0
void __fastcall hkaiStringPulling::projectSegmentEndpoint(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *a,
        hkaiStringPulling::Vertex *projOut)
{
  char m_storage; // al
  int v4; // r12d
  unsigned int m_startFaceKey; // r13d
  unsigned int m_oppositeFace; // r8d
  unsigned __int8 v10; // r14
  int m_index; // ebx
  int Index; // eax
  int v13; // r14d
  __m128 v14; // xmm6
  unsigned __int8 v15; // dl
  hkVector4f v16; // xmm7
  char v17; // bl
  char v18; // al
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  hkaiGeneralAccessor *m_accessor; // rcx
  BOOL v23; // ecx
  hkVector4f *p_pointInOut; // rax
  hkVector4f pointInOut; // [rsp+20h] [rbp-60h] BYREF
  hkaiStringPulling::Vertex inOut; // [rsp+30h] [rbp-50h] BYREF
  int v27; // [rsp+B8h] [rbp+38h]

  m_storage = a->m_type.m_storage;
  v4 = -1;
  m_startFaceKey = -1;
  if ( m_storage != 1 )
  {
    if ( m_storage == 2 )
    {
      m_startFaceKey = this->m_startFaceKey;
      v4 = this->m_pathLength - 1;
    }
    else
    {
      if ( COERCE_FLOAT(*(_OWORD *)&this->m_radius) < 0.00000011920929
        || a->m_userEdge.m_bool
        || (v10 = a->m_side.m_storage, v10 == 0xFF)
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
      m_index = a->m_index;
      Index = hkaiStringPulling::getIndex(this, a->m_index, (hkaiStringPulling::Side)v10);
      *(_DWORD *)&inOut.m_type.m_storage = 0;
      inOut.m_index = m_index;
      inOut.m_side.m_storage = v10;
      v27 = Index;
      hkaiStringPulling::getVertex(this, &inOut);
      v13 = a->m_index;
      v14 = _mm_sub_ps(a->m_pos.m_quad, a->m_center.m_quad);
      if ( a->m_index >= this->m_pathLength )
        goto LABEL_7;
      v15 = a->m_side.m_storage;
      v16.m_quad = (__m128)inOut.m_pos;
      v17 = inOut.m_side.m_storage;
      while ( (unsigned int)hkaiStringPulling::getIndex(this, v13, (hkaiStringPulling::Side)v15) == v27 )
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
        hkaiStringPulling::getVertex(this, &inOut);
        v15 = a->m_side.m_storage;
        v4 = v13;
        v19 = _mm_sub_ps(inOut.m_pos.m_quad, v16.m_quad);
        v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v14), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v19));
        v21 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), this->m_up.m_quad);
        if ( (v15 == 0) != (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) > 0.0 )
        {
          m_oppositeFace = this->m_pathEdgeCache.m_pathEdges.m_data[(__int64)v13].m_oppositeEdge.m_oppositeFace;
          goto LABEL_25;
        }
        if ( ++v13 >= this->m_pathLength )
          break;
      }
    }
    if ( v4 != -1 )
      m_startFaceKey = this->m_pathEdgeCache.m_pathEdges.m_data[(__int64)v4].m_incomingEdge.m_oppositeFace;
LABEL_7:
    m_oppositeFace = m_startFaceKey;
    goto LABEL_25;
  }
  m_oppositeFace = this->m_startFaceKey;
LABEL_25:
  m_accessor = this->m_accessor;
  pointInOut.m_quad = (__m128)a->m_pos;
  v23 = hkaiPathProjectionUtil::calcBarycentricHeightInterpolation(m_accessor, &this->m_up, m_oppositeFace, &pointInOut);
  projOut->m_index = a->m_index;
  projOut->m_side.m_storage = a->m_side.m_storage;
  projOut->m_type.m_storage = a->m_type.m_storage;
  projOut->m_clearanceIsNegative.m_bool = a->m_clearanceIsNegative.m_bool;
  projOut->m_userEdge.m_bool = a->m_userEdge.m_bool;
  projOut->m_userEdgeSwapped.m_bool = a->m_userEdgeSwapped.m_bool;
  p_pointInOut = &pointInOut;
  if ( !v23 )
    p_pointInOut = &a->m_pos;
  projOut->m_pos = a->m_pos;
  projOut->m_center = a->m_center;
  projOut->m_pos = (hkVector4f)p_pointInOut->m_quad;
}

// File Line: 1217
// RVA: 0xC23E40
char __fastcall hkaiStringPulling::doWedgeCheck(
        hkaiStringPulling *this,
        hkaiStringPulling::Vertex *wedgeStart,
        hkaiStringPulling::Vertex *wedgeEnd,
        hkaiStringPulling::Vertex *start)
{
  hkVector4f v4; // xmm1
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  bool v11; // zf
  hkVector4f v12; // xmm7
  __m128 v13; // xmm1
  __m128 v14; // xmm6
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  hkaiStringPulling::Vertex *v17; // rdi
  unsigned __int8 m_storage; // al
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  hkVector4f v22; // xmm0
  int v23; // ebx
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm3
  __m128 v30; // xmm6
  __m128 v31; // xmm5
  __m128 v32; // xmm6
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __int128 v35; // xmm0
  hkVector4f v36; // xmm1
  hkVector4f v37; // xmm2
  __int64 v38; // rdx
  __int64 v39; // rcx
  __int128 v41; // xmm0
  hkVector4f v42; // xmm1
  hkVector4f v43; // xmm2
  __int64 v44; // rdx
  __int64 v45; // rcx
  char v46[56]; // [rsp+30h] [rbp-79h] BYREF
  hkVector4f a; // [rsp+68h] [rbp-41h] BYREF
  hkVector4f b; // [rsp+78h] [rbp-31h] BYREF
  hkaiStringPulling::Vertex starta; // [rsp+88h] [rbp-21h] BYREF
  hkaiStringPulling::Vertex *userEdgeSwapped; // [rsp+118h] [rbp+6Fh] BYREF
  __int64 v51; // [rsp+120h] [rbp+77h]
  int edgeIndex; // [rsp+128h] [rbp+7Fh]

  v4.m_quad = (__m128)wedgeEnd->m_pos;
  *(_OWORD *)&v46[8] = *(_OWORD *)&wedgeEnd->m_index;
  v9.m_quad = (__m128)wedgeEnd->m_center;
  *(hkVector4f *)&v46[24] = (hkVector4f)v4.m_quad;
  v10.m_quad = (__m128)wedgeStart->m_pos;
  *(hkVector4f *)&v46[40] = (hkVector4f)v9.m_quad;
  *(_OWORD *)&starta.m_index = *(_OWORD *)&wedgeStart->m_index;
  starta.m_center = wedgeStart->m_center;
  starta.m_pos = (hkVector4f)v10.m_quad;
  hkaiStringPulling::genericTangent(
    this,
    (hkaiStringPulling::Vertex *)&starta.m_pos.m_quad.m128_u16[4],
    (hkaiStringPulling::Vertex *)&v46[32]);
  v11 = wedgeEnd->m_side.m_storage == 0;
  v12.m_quad = (__m128)this->m_up;
  v13 = *(__m128 *)&v46[24];
  a.m_quad = (__m128)starta.m_pos;
  *(_OWORD *)&v46[16] = *(_OWORD *)&v46[24];
  v14 = _mm_sub_ps(*(__m128 *)&v46[16], starta.m_pos.m_quad);
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v12.m_quad, v12.m_quad, 201), v14));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  if ( v11 )
    v16 = _mm_xor_ps(v16, (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0));
  v17 = userEdgeSwapped;
  v11 = userEdgeSwapped->m_userEdge.m_bool == 0;
  b.m_quad = _mm_add_ps(v16, v13);
  if ( !v11
    || (m_storage = userEdgeSwapped->m_side.m_storage, m_storage == 0xFF)
    || !userEdgeSwapped->m_clearanceIsNegative.m_bool
    || m_storage == -1 )
  {
    v22.m_quad = (__m128)userEdgeSwapped->m_center;
  }
  else
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
                         _mm_cmple_ps(v20, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v20), v21)),
                           _mm_mul_ps(*(__m128 *)_xmm, v21))),
                       v16),
                     this->m_radius.m_real));
  }
  v23 = (unsigned __int8)wedgeEnd->m_side.m_storage;
  *(hkVector4f *)v46 = (hkVector4f)v22.m_quad;
  if ( hkaiStringPulling::getSide(this, &a, (hkVector4f *)&v46[16], (hkVector4f *)v46) != v23 )
    goto LABEL_16;
  if ( hkaiStringPulling::getSide(this, (hkVector4f *)&v46[16], &b, (hkVector4f *)v46) != v23 )
    goto LABEL_15;
  hkaiStringPulling::getVertexPosition(this, edgeIndex, LEFT, (hkVector4f *)&v46[16], (bool *)&userEdgeSwapped);
  hkaiStringPulling::getVertexPosition(this, edgeIndex, RIGHT, (hkVector4f *)v46, (bool *)&userEdgeSwapped);
  v24 = wedgeEnd->m_side.m_storage
      ? _mm_sub_ps(*(__m128 *)&v46[16], *(__m128 *)v46)
      : _mm_sub_ps(*(__m128 *)v46, *(__m128 *)&v46[16]);
  v25 = _mm_mul_ps(v24, v12.m_quad);
  v26 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)), _mm_shuffle_ps(v25, v25, 170));
  v27 = _mm_mul_ps(v14, v12.m_quad);
  v28 = _mm_sub_ps(v24, _mm_mul_ps(v26, v12.m_quad));
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_sub_ps(
          v14,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
              _mm_shuffle_ps(v27, v27, 170)),
            v12.m_quad));
  v31 = _mm_mul_ps(v28, v30);
  v32 = _mm_mul_ps(v30, v30);
  v33 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
            _mm_shuffle_ps(v29, v29, 170)),
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
            _mm_shuffle_ps(v32, v32, 170)));
  v34 = _mm_rsqrt_ps(v33);
  if ( (float)(_mm_andnot_ps(
                 _mm_cmple_ps(v33, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v34, v33), v34)),
                   _mm_mul_ps(*(__m128 *)_xmm, v34))).m128_f32[0]
             * (float)((float)(_mm_shuffle_ps(v31, v31, 85).m128_f32[0] + _mm_shuffle_ps(v31, v31, 0).m128_f32[0])
                     + _mm_shuffle_ps(v31, v31, 170).m128_f32[0])) <= -0.001 )
  {
LABEL_16:
    v41 = *(_OWORD *)&wedgeStart->m_index;
    v42.m_quad = (__m128)wedgeStart->m_center;
    v43.m_quad = (__m128)wedgeStart->m_pos;
    v44 = v51;
    v45 = *(_QWORD *)&wedgeStart->m_index;
    start->m_index = *(_QWORD *)&wedgeStart->m_index;
    start->m_side.m_storage = BYTE4(v45);
    start->m_pos = (hkVector4f)v43.m_quad;
    start->m_center = (hkVector4f)v42.m_quad;
    start->m_type.m_storage = BYTE5(v45);
    *(_OWORD *)&v46[8] = v41;
    start->m_userEdge.m_bool = HIBYTE(v45);
    start->m_clearanceIsNegative.m_bool = BYTE6(v45);
    start->m_userEdgeSwapped.m_bool = v46[16];
    v17->m_index = *(_DWORD *)v44;
    v17->m_side.m_storage = *(_BYTE *)(v44 + 4);
    v17->m_type.m_storage = *(_BYTE *)(v44 + 5);
    v17->m_clearanceIsNegative.m_bool = *(_BYTE *)(v44 + 6);
    v17->m_userEdge.m_bool = *(_BYTE *)(v44 + 7);
    v17->m_userEdgeSwapped.m_bool = *(_BYTE *)(v44 + 8);
    v17->m_pos = *(hkVector4f *)(v44 + 16);
    v17->m_center = *(hkVector4f *)(v44 + 32);
    hkaiStringPulling::genericTangent(this, start, v17);
    return 0;
  }
  else
  {
LABEL_15:
    v35 = *(_OWORD *)&wedgeEnd->m_index;
    v36.m_quad = (__m128)wedgeEnd->m_center;
    v37.m_quad = (__m128)wedgeEnd->m_pos;
    v38 = v51;
    v39 = *(_QWORD *)&wedgeEnd->m_index;
    start->m_index = *(_QWORD *)&wedgeEnd->m_index;
    start->m_side.m_storage = BYTE4(v39);
    start->m_pos = (hkVector4f)v37.m_quad;
    start->m_center = (hkVector4f)v36.m_quad;
    start->m_type.m_storage = BYTE5(v39);
    *(_OWORD *)&v46[8] = v35;
    start->m_userEdge.m_bool = HIBYTE(v39);
    start->m_clearanceIsNegative.m_bool = BYTE6(v39);
    start->m_userEdgeSwapped.m_bool = v46[16];
    v17->m_index = *(_DWORD *)v38;
    v17->m_side.m_storage = *(_BYTE *)(v38 + 4);
    v17->m_type.m_storage = *(_BYTE *)(v38 + 5);
    v17->m_clearanceIsNegative.m_bool = *(_BYTE *)(v38 + 6);
    v17->m_userEdge.m_bool = *(_BYTE *)(v38 + 7);
    v17->m_userEdgeSwapped.m_bool = *(_BYTE *)(v38 + 8);
    v17->m_pos = *(hkVector4f *)(v38 + 16);
    v17->m_center = *(hkVector4f *)(v38 + 32);
    hkaiStringPulling::genericTangent(this, start, v17);
    return 1;
  }
}38 + 32);
    hkaiStringPulling::genericTangent(this, start, v17);
    return 1;
  }
}

// File Line: 1317
// RVA: 0xC22B00
bool __fastcall hkaiStringPulling::stringPull(hkaiStringPulling *this)
{
  int m_pathLength; // eax
  __m128 m_quad; // xmm6
  hkVector4f v4; // xmm0
  hkaiStringPulling::Funnel *p_m_funnel; // rbx
  hkaiStringPulling::Vertex *v7; // rcx
  __int64 m_size; // rcx
  BOOL v9; // r14d
  hkaiStringPulling::Vertex *v10; // rdx
  int v11; // esi
  float v12; // xmm9_4
  hkaiStringPulling::Vertex *v13; // rax
  hkVector4f v14; // xmm0
  hkaiStringPulling::Funnel *m_funnel; // rbx
  hkVector4f v16; // xmm6
  hkaiStringPulling::Vertex *v17; // rax
  char m_bool; // r15
  __m128 v19; // xmm6
  __m128 v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  int v23; // eax
  hkaiStringPulling::Funnel *v24; // r13
  int m_funnelIndex; // r15d
  int v26; // r12d
  int v27; // edx
  hkaiStringPulling::Funnel *v28; // rcx
  hkaiStringPulling::Vertex *v29; // rcx
  char m_storage; // bl
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
  int v41; // r13d
  int m_index; // esi
  hkaiStringPulling::Vertex *Apex; // rax
  hkaiStringPulling::Vertex *v44; // rcx
  int v45; // r15d
  __int128 *v46; // r14
  hkVector4f *p_m_pos; // r12
  hkaiStringPulling::Vertex *p_start; // rsi
  __int64 v49; // r13
  hkaiStringPulling::Vertex *v50; // rax
  hkVector4f v51; // xmm1
  hkVector4f v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm1
  __m128 v55; // xmm4
  __m128 v56; // xmm2
  hkaiStringPulling::Vertex a; // [rsp+40h] [rbp-C0h] BYREF
  hkaiStringPulling::Vertex wedgeEnd; // [rsp+70h] [rbp-90h] BYREF
  hkaiStringPulling::Funnel::Iterator v59; // [rsp+A0h] [rbp-60h] BYREF
  hkaiStringPulling::Funnel::Iterator v60; // [rsp+B0h] [rbp-50h] BYREF
  hkaiStringPulling::Vertex inOut; // [rsp+C0h] [rbp-40h] BYREF
  hkaiStringPulling::Vertex b; // [rsp+F0h] [rbp-10h] BYREF
  hkaiStringPulling::Vertex v63; // [rsp+120h] [rbp+20h] BYREF
  hkaiStringPulling::Vertex start; // [rsp+150h] [rbp+50h] BYREF
  int v65; // [rsp+180h] [rbp+80h]
  char v66; // [rsp+184h] [rbp+84h]
  int v67; // [rsp+185h] [rbp+85h]
  hkaiStringPulling::Vertex vertex; // [rsp+1B0h] [rbp+B0h] BYREF
  __int128 v69; // [rsp+1E0h] [rbp+E0h] BYREF
  __int128 v70; // [rsp+1F0h] [rbp+F0h]
  hkaiStringPulling::Vertex v71; // [rsp+200h] [rbp+100h] BYREF
  int v72; // [rsp+2B0h] [rbp+1B0h]
  int v73; // [rsp+2B8h] [rbp+1B8h]

  m_pathLength = this->m_pathLength;
  m_quad = this->m_startPoint.m_quad;
  if ( m_pathLength <= 0 )
  {
    v4.m_quad = (__m128)this->m_endPoint;
    a.m_pos = this->m_startPoint;
    *(_WORD *)&a.m_userEdge.m_bool = 0;
    a.m_index = -1;
    *(_WORD *)&a.m_side.m_storage = 511;
    *(_WORD *)&b.m_userEdge.m_bool = 0;
    a.m_center.m_quad = m_quad;
    b.m_pos = (hkVector4f)v4.m_quad;
    b.m_center = (hkVector4f)v4.m_quad;
    v4.m_quad.m128_i32[0] = this->m_endPoint.m_quad.m128_i32[3];
    a.m_clearanceIsNegative.m_bool = this->m_startPoint.m_quad.m128_f32[3] < 0.0;
    b.m_index = m_pathLength;
    *(_WORD *)&b.m_side.m_storage = 767;
    b.m_clearanceIsNegative.m_bool = v4.m_quad.m128_f32[0] < 0.0;
    hkaiStringPulling::addSegmentToPath(this, &a, &b);
    return hkaiStringPulling::terminateOutput(this);
  }
  p_m_funnel = &this->m_funnel;
  hkaiStringPulling::Funnel::clear(&this->m_funnel);
  if ( this->m_funnel.m_data.m_size == (this->m_funnel.m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &this->m_funnel.m_data, 48);
  v7 = &this->m_funnel.m_data.m_data[this->m_funnel.m_data.m_size];
  if ( v7 )
  {
    v7->m_index = -2;
    *(_DWORD *)&v7->m_side.m_storage = 255;
    v7->m_userEdgeSwapped.m_bool = 0;
  }
  m_size = this->m_funnel.m_data.m_size;
  v9 = 1;
  v73 = 0;
  this->m_funnel.m_data.m_size = m_size + 1;
  v72 = 0;
  v10 = &this->m_funnel.m_data.m_data[m_size];
  v10->m_pos.m_quad = m_quad;
  v10->m_center.m_quad = m_quad;
  v11 = 0;
  v10->m_clearanceIsNegative.m_bool = _mm_shuffle_ps(m_quad, m_quad, 255).m128_f32[0] < 0.0;
  v10->m_index = -1;
  *(_WORD *)&v10->m_side.m_storage = 511;
  this->m_funnel.m_apex = 0;
  LODWORD(v12) = _mm_shuffle_ps(
                   (__m128)LODWORD(hkaiStringPulling::TOLERANCE),
                   (__m128)LODWORD(hkaiStringPulling::TOLERANCE),
                   0).m128_u32[0];
  do
  {
    if ( v11 > this->m_pathLength )
      return hkaiStringPulling::terminateOutput(this);
    hkaiStringPulling::Funnel::Iterator::Iterator(&v59, p_m_funnel, v9, -1);
    v60 = v59;
    while ( 1 )
    {
      hkaiStringPulling::Funnel::Iterator::operator++(&v60, 0);
      v13 = hkaiStringPulling::Funnel::operator[](p_m_funnel, this->m_funnel.m_apex);
      *(_OWORD *)&start.m_index = *(_OWORD *)&v13->m_index;
      start.m_pos = v13->m_pos;
      v14.m_quad = (__m128)v13->m_center;
      *(_DWORD *)&inOut.m_type.m_storage = 0;
      inOut.m_index = v11;
      inOut.m_side.m_storage = v9;
      start.m_center = (hkVector4f)v14.m_quad;
      hkaiStringPulling::getVertex(this, &inOut);
      m_funnel = v59.m_funnel;
      v16.m_quad = (__m128)inOut.m_pos;
      vertex = inOut;
      if ( v11 < this->m_pathLength )
      {
        if ( (v17 = hkaiStringPulling::Funnel::operator[](v59.m_funnel, v59.m_funnelIndex),
              m_bool = inOut.m_userEdge.m_bool,
              v19 = _mm_sub_ps(v16.m_quad, v17->m_pos.m_quad),
              v20 = _mm_mul_ps(v19, v19),
              v21 = _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                      _mm_shuffle_ps(v20, v20, 170)),
              v22 = _mm_rsqrt_ps(v21),
              _mm_andnot_ps(
                _mm_cmple_ps(v21, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v21, v22), v22)),
                    _mm_mul_ps(*(__m128 *)_xmm, v22)),
                  v21)).m128_f32[0] < v12)
          && !inOut.m_userEdge.m_bool
          || (unsigned int)hkaiStringPulling::undefinedTangent(this, &start, &inOut) && v11 && !m_bool )
        {
LABEL_49:
          p_m_funnel = &this->m_funnel;
          goto LABEL_50;
        }
      }
      wedgeEnd.m_index = -2;
      *(_DWORD *)&wedgeEnd.m_side.m_storage = 255;
      wedgeEnd.m_userEdgeSwapped.m_bool = 0;
      a.m_index = -2;
      *(_DWORD *)&a.m_side.m_storage = 255;
      a.m_userEdgeSwapped.m_bool = 0;
      if ( !(unsigned int)hkaiStringPulling::Funnel::Iterator::isValid(&v60) )
        break;
      v23 = hkaiStringPulling::Funnel::Iterator::lessOrEqualApex(&v60);
      v24 = v60.m_funnel;
      m_funnelIndex = v60.m_funnelIndex;
      v26 = v23;
      if ( v23 )
      {
        v27 = v59.m_funnelIndex;
        v28 = m_funnel;
      }
      else
      {
        v27 = v60.m_funnelIndex;
        v28 = v60.m_funnel;
      }
      v29 = hkaiStringPulling::Funnel::operator[](v28, v27);
      m_storage = v29->m_side.m_storage;
      wedgeEnd.m_index = v29->m_index;
      v31 = v29->m_type.m_storage;
      v32.m_quad = (__m128)v29->m_center;
      wedgeEnd.m_pos = v29->m_pos;
      wedgeEnd.m_center = (hkVector4f)v32.m_quad;
      wedgeEnd.m_type.m_storage = v31;
      v33 = v29->m_clearanceIsNegative.m_bool;
      wedgeEnd.m_side.m_storage = m_storage;
      wedgeEnd.m_clearanceIsNegative.m_bool = v33;
      wedgeEnd.m_userEdge.m_bool = v29->m_userEdge.m_bool;
      wedgeEnd.m_userEdgeSwapped.m_bool = v29->m_userEdgeSwapped.m_bool;
      if ( v26 )
      {
        v34 = m_funnelIndex;
        v35 = v24;
      }
      else
      {
        v34 = v59.m_funnelIndex;
        v35 = v59.m_funnel;
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
      if ( (unsigned int)hkaiStringPulling::undefinedTangent(this, &inOut, &wedgeEnd) )
      {
        if ( v11 != this->m_pathLength && !(unsigned int)hkaiStringPulling::isUserEdge(this, v11) )
          goto LABEL_49;
        v40 = m_storage == v9 && hkaiStringPulling::isUndefinedTangentVertexAddable(this, &a, &wedgeEnd, &inOut);
        hkaiStringPulling::genericTangent(this, &start, &inOut);
      }
      else
      {
        if ( (unsigned int)hkaiStringPulling::undefinedTangent(this, &a, &wedgeEnd) )
          goto LABEL_36;
        if ( m_storage == v9 )
        {
          v40 = hkaiStringPulling::doWedgeCheck(this, &a, &wedgeEnd, &start, &inOut, &vertex, v11 - 1);
        }
        else
        {
          hkaiStringPulling::genericTangent(this, &start, &inOut);
          hkaiStringPulling::genericTangent(this, &a, &wedgeEnd);
          v40 = hkaiStringPulling::getSide(this, &a.m_pos, &wedgeEnd.m_pos, &inOut.m_pos) == v9;
        }
      }
      if ( v40 )
        goto LABEL_42;
LABEL_36:
      p_m_funnel = &this->m_funnel;
      b.m_index = -2;
      *(_DWORD *)&b.m_side.m_storage = 255;
      b.m_userEdgeSwapped.m_bool = 0;
      hkaiStringPulling::Funnel::pop(&this->m_funnel, (hkaiStringPulling::Side)v9, &b);
      if ( hkaiStringPulling::Funnel::apexPopped(&this->m_funnel) )
      {
        a = *hkaiStringPulling::Funnel::operator[](v24, m_funnelIndex);
        wedgeEnd = b;
        hkaiStringPulling::genericTangent(this, &wedgeEnd, &a);
        if ( hkaiStringPulling::isCloser(this, &wedgeEnd, &a, &inOut, v11 - 1) )
        {
          hkaiStringPulling::addSegmentToPath(this, &start, &inOut);
          hkaiStringPulling::Funnel::add(&this->m_funnel, &vertex, (hkaiStringPulling::Side)v9);
          v41 = vertex.m_index == this->m_pathLength;
          v72 = v41;
          hkaiStringPulling::handleUserEdge(this, &vertex, v11);
          goto LABEL_51;
        }
        hkaiStringPulling::addSegmentToPath(this, &wedgeEnd, &a);
        this->m_funnel.m_apex = m_funnelIndex;
      }
      hkaiStringPulling::Funnel::Iterator::operator++(&v59, 0);
    }
    hkaiStringPulling::genericTangent(this, &start, &inOut);
LABEL_42:
    p_m_funnel = &this->m_funnel;
    if ( hkaiStringPulling::Funnel::add(&this->m_funnel, &vertex, (hkaiStringPulling::Side)v9) )
    {
      v41 = (unsigned __int8)hkaiStringPulling::checkTermination(this, &vertex, (hkaiStringPulling::Side)v9, v11);
      v72 = v41;
      goto LABEL_51;
    }
    a.m_index = -2;
    *(_DWORD *)&a.m_side.m_storage = 255;
    a.m_userEdgeSwapped.m_bool = 0;
    m_index = hkaiStringPulling::Funnel::getApex(&this->m_funnel)->m_index;
    *(_DWORD *)&b.m_type.m_storage = 0;
    v11 = m_index + 1;
    *(_DWORD *)&v63.m_type.m_storage = 0;
    v63.m_side.m_storage = 1;
    v63.m_index = v11;
    b.m_index = v11;
    b.m_side.m_storage = 0;
    hkaiStringPulling::getVertex(this, &v63);
    hkaiStringPulling::getVertex(this, &b);
    a.m_index = v11;
    a.m_side.m_storage = -1;
    a.m_userEdge.m_bool = 0;
    a.m_pos.m_quad = _mm_add_ps(
                       _mm_mul_ps(_mm_sub_ps(b.m_pos.m_quad, v63.m_pos.m_quad), (__m128)xmmword_141A711B0),
                       v63.m_pos.m_quad);
    a.m_center.m_quad = _mm_shuffle_ps(a.m_pos.m_quad, _mm_unpackhi_ps(a.m_pos.m_quad, a.m_center.m_quad), 196);
    Apex = hkaiStringPulling::Funnel::getApex(&this->m_funnel);
    hkaiStringPulling::addSegmentToPath(this, Apex, &a);
    hkaiStringPulling::Funnel::clear(&this->m_funnel);
    if ( this->m_funnel.m_data.m_size == (this->m_funnel.m_data.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &this->m_funnel.m_data, 48);
    v44 = &this->m_funnel.m_data.m_data[this->m_funnel.m_data.m_size];
    if ( v44 )
      *v44 = a;
    ++this->m_funnel.m_data.m_size;
    v73 = -1;
    this->m_funnel.m_apex = 0;
LABEL_50:
    v41 = v72;
LABEL_51:
    v45 = v11 + 1;
    if ( v73 == -1 )
    {
      if ( hkaiStringPulling::isShared(this, v11, RIGHT) )
      {
        v41 = v72;
        v9 = 0;
        ++v11;
      }
      else if ( hkaiStringPulling::isShared(this, v11, LEFT) )
      {
        v41 = v72;
        v9 = 1;
        ++v11;
      }
      else
      {
        *(_DWORD *)&start.m_type.m_storage = 0;
        v67 = 0;
        v65 = v11 + 1;
        start.m_index = v11 + 1;
        v66 = 1;
        start.m_side.m_storage = 0;
        v70 = 0i64;
        v69 = 0i64;
        v46 = &v69;
        p_m_pos = &start.m_pos;
        p_start = &start;
        v49 = 2i64;
        do
        {
          hkaiStringPulling::getVertex(this, p_start);
          v50 = hkaiStringPulling::Funnel::getApex(p_m_funnel);
          v51.m_quad = (__m128)v50->m_pos;
          *(_OWORD *)&v71.m_index = *(_OWORD *)&v50->m_index;
          v52.m_quad = (__m128)v50->m_center;
          v71.m_pos = (hkVector4f)v51.m_quad;
          v71.m_center = (hkVector4f)v52.m_quad;
          hkaiStringPulling::genericTangent(this, &v71, p_start);
          ++v46;
          ++p_start;
          p_m_pos += 3;
          v53 = _mm_sub_ps(v71.m_pos.m_quad, p_m_pos[-3].m_quad);
          v54 = _mm_mul_ps(v53, v53);
          v55 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                  _mm_shuffle_ps(v54, v54, 170));
          v56 = _mm_rsqrt_ps(v55);
          *(v46 - 1) = (__int128)_mm_andnot_ps(
                                   _mm_cmple_ps(v55, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_mul_ps(
                                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v55, v56), v56)),
                                       _mm_mul_ps(v56, *(__m128 *)_xmm)),
                                     v55));
          --v49;
        }
        while ( v49 );
        v9 = *(float *)&v69 > *(float *)&v70;
        if ( *(float *)&v69 <= *(float *)&v70 )
        {
          v41 = v72;
          v73 = 1;
          v11 = v45;
        }
        else
        {
          v41 = v72;
          if ( *(float *)&v69 > *(float *)&v70 )
            v73 = 0;
          else
            v73 = -1;
          v11 = v45;
        }
      }
    }
    else
    {
      v9 = v73;
      v73 = -1;
    }
  }
  while ( !v41 );
  return hkaiStringPulling::terminateOutput(this);
}

