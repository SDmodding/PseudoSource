// File Line: 180
// RVA: 0xC035A0
float __fastcall hkaiDirectedGraphVisitor::getTotalCost(hkaiDirectedGraphVisitor *this, unsigned int nit, unsigned int adj, int edgeIndex)
{
  hkaiDirectedGraphExplicitCost::Edge *v4; // rbx
  unsigned int v5; // er11
  int v6; // edi
  hkaiDirectedGraphVisitor *v7; // r10
  unsigned int v8; // er8
  __m128i v9; // xmm6
  const float *v10; // rax
  __m128i v11; // xmm3
  __int64 v12; // rdx
  const unsigned int *v13; // rcx
  hkaiAstarCostModifier *v14; // r9
  __int128 v15; // xmm0
  __m128 *v16; // r8
  __int64 v17; // rdx
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  int v20; // eax
  unsigned int v22; // [rsp+18h] [rbp-61h]
  hkaiDirectedGraphExplicitCost::Node *v23; // [rsp+20h] [rbp-59h]
  __int128 v24; // [rsp+28h] [rbp-51h]
  unsigned int v25; // [rsp+38h] [rbp-41h]
  __int64 *v26; // [rsp+40h] [rbp-39h]
  __m128 v27; // [rsp+48h] [rbp-31h]
  int v28; // [rsp+58h] [rbp-21h]
  hkaiDirectedGraphExplicitCost::Edge *v29; // [rsp+60h] [rbp-19h]
  hkaiStreamingCollection::InstanceInfo *v30; // [rsp+68h] [rbp-11h]
  hkaiAgentTraversalInfo *v31; // [rsp+70h] [rbp-9h]
  int *v32; // [rsp+78h] [rbp-1h]
  __int128 v33; // [rsp+88h] [rbp+Fh]
  __int128 v34; // [rsp+98h] [rbp+1Fh]
  char v35; // [rsp+A8h] [rbp+2Fh]
  __int64 retaddr; // [rsp+D8h] [rbp+5Fh]
  unsigned int v37; // [rsp+F8h] [rbp+7Fh]

  v4 = this->m_currentEdge;
  v5 = adj;
  v6 = edgeIndex;
  v7 = this;
  v8 = nit;
  v9 = (__m128i)_mm_shuffle_ps((__m128)v37, (__m128)v37, 0);
  v10 = this->m_finalCosts;
  v11 = (__m128i)_mm_shuffle_ps(
                   (__m128)(unsigned int)(v4->m_cost.m_value << 16),
                   (__m128)(unsigned int)(v4->m_cost.m_value << 16),
                   0);
  if ( v10 )
  {
    v12 = (unsigned int)this->m_numGoals;
    if ( (signed int)v12 > 0 )
    {
      v13 = this->m_goalNodes;
      do
      {
        if ( *v13 == v5 )
          v11 = (__m128i)_mm_add_ps(
                           (__m128)v11,
                           _mm_shuffle_ps((__m128)*(unsigned int *)v10, (__m128)*(unsigned int *)v10, 0));
        ++v10;
        ++v13;
        --v12;
      }
      while ( v12 );
    }
  }
  v14 = v7->m_costModifier;
  if ( v14 )
  {
    v15 = (__int128)v7->m_cachedPosition;
    v22 = v8;
    v16 = (__m128 *)v7->m_outgoingGraph;
    v26 = 0i64;
    v29 = 0i64;
    v24 = v15;
    v25 = -1;
    v28 = -1;
    v23 = &v7->m_cachedNode;
    v17 = v5 & 0x3FFFFF;
    retaddr = *(_QWORD *)(v16[1].m128_u64[0] + 8 * v17);
    v18 = *(__m128 *)(v16[3].m128_u64[0] + 16 * v17);
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v16[14]),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v16[13])),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v16[15])),
            v16[16]);
    v26 = &retaddr;
    v20 = v7->m_cachedIncomingSectionId;
    v25 = v5;
    _mm_store_si128((__m128i *)&v33, v9);
    _mm_store_si128((__m128i *)&v34, v11);
    v29 = v4;
    v27 = v19;
    v28 = v6 | (v20 << 22);
    v30 = v7->m_streamingInfo;
    v31 = &v7->m_agentInfo;
    v32 = (int *)&v22;
    *(float *)v11.m128i_i32 = fmax(
                                0.0,
                                *(float *)((__int64 (__fastcall *)(hkaiAstarCostModifier *, char *, hkaiStreamingCollection::InstanceInfo **))v14->vfptr[1].__first_virtual_table_function__)(
                                            v14,
                                            &v35,
                                            &v30));
  }
  return *(float *)v11.m128i_i32 + *(float *)v9.m128i_i32;
}

// File Line: 316
// RVA: 0xC1FD90
void __fastcall copyEdges_1(hkaiDirectedGraphExplicitCost::Edge *edgeLocalDst, hkaiDirectedGraphExplicitCost::Edge *edgeMainMemSrc, int edgeStartIdx, int numEdges)
{
  hkaiDirectedGraphExplicitCost::Edge *v4; // rax
  signed int v5; // edx
  unsigned __int64 v6; // r8
  char *v7; // r10
  int v8; // ecx

  v4 = &edgeMainMemSrc[edgeStartIdx];
  v5 = 0;
  v6 = (unsigned __int64)(8i64 * numEdges) >> 2;
  if ( (signed int)v6 > 0 )
  {
    v7 = (char *)((char *)edgeLocalDst - (char *)v4);
    do
    {
      v8 = *(_DWORD *)&v4->m_cost.m_value;
      ++v5;
      v4 = (hkaiDirectedGraphExplicitCost::Edge *)((char *)v4 + 4);
      *(_DWORD *)((char *)v4 + (_QWORD)v7 - 4) = v8;
    }
    while ( v5 < (signed int)v6 );
  }
}

