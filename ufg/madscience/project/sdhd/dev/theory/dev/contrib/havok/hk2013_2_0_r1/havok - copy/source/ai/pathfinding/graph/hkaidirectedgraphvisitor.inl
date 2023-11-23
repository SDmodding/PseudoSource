// File Line: 180
// RVA: 0xC035A0
float __fastcall hkaiDirectedGraphVisitor::getTotalCost(
        hkaiDirectedGraphVisitor *this,
        unsigned int nit,
        unsigned int adj,
        int edgeIndex)
{
  hkaiDirectedGraphExplicitCost::Edge *m_currentEdge; // rbx
  __m128 v9; // xmm6
  const float *m_finalCosts; // rax
  __m128 v11; // xmm3
  __int64 m_numGoals; // rdx
  const unsigned int *m_goalNodes; // rcx
  hkaiAstarCostModifier *m_costModifier; // r9
  hkVector4f v15; // xmm0
  hkaiDirectedGraphInstance *m_outgoingGraph; // r8
  __int64 v17; // rdx
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  int m_cachedIncomingSectionId; // eax
  unsigned int v22; // [rsp+18h] [rbp-61h] BYREF
  hkaiDirectedGraphExplicitCost::Node *p_m_cachedNode; // [rsp+20h] [rbp-59h]
  __m128 m_quad; // [rsp+28h] [rbp-51h]
  unsigned int v25; // [rsp+38h] [rbp-41h]
  void **v26; // [rsp+40h] [rbp-39h]
  __m128 v27; // [rsp+48h] [rbp-31h]
  int v28; // [rsp+58h] [rbp-21h]
  hkaiDirectedGraphExplicitCost::Edge *v29; // [rsp+60h] [rbp-19h]
  __int64 v30[4]; // [rsp+68h] [rbp-11h] BYREF
  __m128 v31; // [rsp+88h] [rbp+Fh]
  __m128 v32; // [rsp+98h] [rbp+1Fh]
  char v33[40]; // [rsp+A8h] [rbp+2Fh] BYREF
  hkaiDirectedGraphExplicitCost::Node retaddr; // [rsp+D8h] [rbp+5Fh] BYREF
  unsigned int v35; // [rsp+F8h] [rbp+7Fh]

  m_currentEdge = this->m_currentEdge;
  v9 = _mm_shuffle_ps((__m128)v35, (__m128)v35, 0);
  m_finalCosts = this->m_finalCosts;
  v11 = _mm_shuffle_ps(
          (__m128)(unsigned int)(m_currentEdge->m_cost.m_value << 16),
          (__m128)(unsigned int)(m_currentEdge->m_cost.m_value << 16),
          0);
  if ( m_finalCosts )
  {
    m_numGoals = (unsigned int)this->m_numGoals;
    if ( (int)m_numGoals > 0 )
    {
      m_goalNodes = this->m_goalNodes;
      do
      {
        if ( *m_goalNodes == adj )
          v11 = _mm_add_ps(
                  v11,
                  _mm_shuffle_ps((__m128)*(unsigned int *)m_finalCosts, (__m128)*(unsigned int *)m_finalCosts, 0));
        ++m_finalCosts;
        ++m_goalNodes;
        --m_numGoals;
      }
      while ( m_numGoals );
    }
  }
  m_costModifier = this->m_costModifier;
  if ( m_costModifier )
  {
    v15.m_quad = (__m128)this->m_cachedPosition;
    v22 = nit;
    m_outgoingGraph = this->m_outgoingGraph;
    v26 = 0i64;
    v29 = 0i64;
    m_quad = v15.m_quad;
    v25 = -1;
    v28 = -1;
    p_m_cachedNode = &this->m_cachedNode;
    v17 = adj & 0x3FFFFF;
    retaddr = m_outgoingGraph->m_originalNodes[v17];
    v18 = m_outgoingGraph->m_originalPositions[v17].m_quad;
    v19 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), m_outgoingGraph->m_transform.m_rotation.m_col1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), m_outgoingGraph->m_transform.m_rotation.m_col0.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), m_outgoingGraph->m_transform.m_rotation.m_col2.m_quad)),
            m_outgoingGraph->m_transform.m_translation.m_quad);
    v26 = (void **)&retaddr;
    m_cachedIncomingSectionId = this->m_cachedIncomingSectionId;
    v25 = adj;
    v31 = v9;
    v32 = v11;
    v29 = m_currentEdge;
    v27 = v19;
    v28 = edgeIndex | (m_cachedIncomingSectionId << 22);
    v30[0] = (__int64)this->m_streamingInfo;
    v30[1] = (__int64)&this->m_agentInfo;
    v30[2] = (__int64)&v22;
    v11.m128_f32[0] = fmax(
                        0.0,
                        *(float *)((__int64 (__fastcall *)(hkaiAstarCostModifier *, char *, __int64 *))m_costModifier->vfptr[1].__first_virtual_table_function__)(
                                    m_costModifier,
                                    v33,
                                    v30));
  }
  return v11.m128_f32[0] + v9.m128_f32[0];
}

// File Line: 316
// RVA: 0xC1FD90
void __fastcall copyEdges_1(
        hkaiDirectedGraphExplicitCost::Edge *edgeLocalDst,
        hkaiDirectedGraphExplicitCost::Edge *edgeMainMemSrc,
        int edgeStartIdx,
        int numEdges)
{
  hkaiDirectedGraphExplicitCost::Edge *v4; // rax
  int v5; // edx
  unsigned __int64 v6; // r8
  char *v7; // r10
  int v8; // ecx

  v4 = &edgeMainMemSrc[edgeStartIdx];
  v5 = 0;
  v6 = (unsigned __int64)(8i64 * numEdges) >> 2;
  if ( (int)v6 > 0 )
  {
    v7 = (char *)((char *)edgeLocalDst - (char *)v4);
    do
    {
      v8 = *(_DWORD *)&v4->m_cost.m_value;
      ++v5;
      v4 = (hkaiDirectedGraphExplicitCost::Edge *)((char *)v4 + 4);
      *(_DWORD *)((char *)v4 + (_QWORD)v7 - 4) = v8;
    }
    while ( v5 < (int)v6 );
  }
}

