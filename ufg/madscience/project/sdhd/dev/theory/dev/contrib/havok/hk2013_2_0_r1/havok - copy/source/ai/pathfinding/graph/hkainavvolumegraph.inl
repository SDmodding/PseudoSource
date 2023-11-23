// File Line: 292
// RVA: 0xC1D1A0
void __fastcall hkaiNavVolumeGraph::nextNode(hkaiNavVolumeGraph *this, unsigned int nid)
{
  __int64 v4; // rcx
  hkaiNavVolumeInstance *m_volumeInstancePtr; // r8
  hkaiNavVolumeInstance *m_cachedCurrentNavVolume; // r9
  hkaiNavVolume::Cell *p_m_cachedCurrentCell; // r8
  __int64 v8; // r10
  hkaiNavVolume::Cell *v9; // rdx
  __int64 v10; // rcx
  __m128 *m_pntr; // rax
  __m128i v12; // xmm2
  __m128i v13; // xmm0
  __m128 v14; // xmm4
  __m128i v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm0
  hkVector4f v18; // xmm2
  hkVector4f v19; // xmm1
  hkaiHashSearchState *m_searchState; // rbx
  hkaiSearchStateNode *NodeState; // rax

  v4 = nid >> 22;
  if ( this->m_cachedCurrentSectionId != (_DWORD)v4 )
  {
    m_volumeInstancePtr = this->m_streamingInfo[v4].m_volumeInstancePtr;
    this->m_cachedCurrentSectionId = v4;
    this->m_cachedCurrentNavVolume = m_volumeInstancePtr;
  }
  m_cachedCurrentNavVolume = this->m_cachedCurrentNavVolume;
  p_m_cachedCurrentCell = &this->m_cachedCurrentCell;
  v8 = nid & 0x3FFFFF;
  v9 = &m_cachedCurrentNavVolume->m_originalCells[v8];
  *(_DWORD *)this->m_cachedCurrentCell.m_min = *(_DWORD *)v9->m_min;
  *(_DWORD *)&this->m_cachedCurrentCell.m_min[2] = *(_DWORD *)&v9->m_min[2];
  *(_DWORD *)this->m_cachedCurrentCell.m_max = *(_DWORD *)v9->m_max;
  *(_DWORD *)&this->m_cachedCurrentCell.m_max[2] = *(_DWORD *)&v9->m_max[2];
  this->m_cachedCurrentCell.m_startEdgeIndex = v9->m_startEdgeIndex;
  this->m_cachedCurrentCell.m_data = v9->m_data;
  if ( !m_cachedCurrentNavVolume->m_cellMap.m_size
    || (v10 = m_cachedCurrentNavVolume->m_cellMap.m_data[v8], (_DWORD)v10 == -1) )
  {
    this->m_cachedCurrentCellInstance.m_startEdgeIndex = -1;
    this->m_cachedCurrentCellInstance.m_numEdges = 0;
  }
  else
  {
    this->m_cachedCurrentCellInstance = m_cachedCurrentNavVolume->m_instancedCells.m_data[v10];
  }
  this->m_cachedModifierInfo.m_currentCellInfo.m_cell = p_m_cachedCurrentCell;
  this->m_cachedModifierInfo.m_currentCellInfo.m_cellKey = nid;
  m_pntr = (__m128 *)m_cachedCurrentNavVolume->m_originalVolume.m_pntr;
  v12 = _mm_loadu_si128((const __m128i *)p_m_cachedCurrentCell);
  v13 = _mm_unpacklo_epi16(v12, (__m128i)0i64);
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v13, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
          _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v13, 0x10u), 0x10u)));
  v15 = _mm_unpackhi_epi16(v12, (__m128i)0i64);
  v16 = _mm_add_ps(
          _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v15, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
          _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v15, 0x10u), 0x10u)));
  v17 = _mm_add_ps(m_pntr[7], m_cachedCurrentNavVolume->m_translation.m_quad);
  v18.m_quad = _mm_add_ps(_mm_mul_ps(m_pntr[6], v16), v17);
  v19.m_quad = _mm_add_ps(_mm_mul_ps(m_pntr[6], v14), v17);
  this->m_cachedCurrentAabb.m_max = (hkVector4f)v18.m_quad;
  this->m_cachedCurrentAabb.m_min = (hkVector4f)v19.m_quad;
  this->m_cachedModifierInfo.m_currentCellInfo.m_position.m_quad = _mm_mul_ps(
                                                                     _mm_add_ps(v18.m_quad, v19.m_quad),
                                                                     (__m128)xmmword_141A711B0);
  m_searchState = this->m_searchState;
  NodeState = hkaiHashSearchState::getNodeState(m_searchState, nid);
  m_searchState->m_currentNodeState = NodeState;
  m_searchState->m_parentNodeState = NodeState;
  m_searchState->m_parentIndex = (__int16)((__int64)(unsigned int)((_DWORD)NodeState - LODWORD(m_searchState->m_nodes)) >> 4);
}

// File Line: 310
// RVA: 0xC1D110
void __fastcall hkaiNavVolumeGraph::nextEdge(hkaiNavVolumeGraph *this, int nid, int eIdx)
{
  hkaiNavVolumeInstance *m_cachedCurrentNavVolume; // r9
  int m_numOriginalEdges; // ecx
  hkaiNavVolume::Edge *v6; // rax
  hkaiNavVolume::Edge v7; // rax
  unsigned int m_oppositeCell; // r11d
  unsigned int v9; // ecx
  int v10; // eax

  m_cachedCurrentNavVolume = this->m_cachedCurrentNavVolume;
  m_numOriginalEdges = m_cachedCurrentNavVolume->m_numOriginalEdges;
  if ( eIdx >= m_numOriginalEdges )
    v6 = &m_cachedCurrentNavVolume->m_ownedEdges.m_data[eIdx - m_numOriginalEdges];
  else
    v6 = &m_cachedCurrentNavVolume->m_originalEdges[eIdx];
  v7 = *v6;
  this->m_cachedCurrentEdge = v7;
  m_oppositeCell = this->m_cachedCurrentEdge.m_oppositeCell;
  if ( (v7.m_flags.m_storage & 0x40) != 0 )
    v9 = m_oppositeCell & 0xFFC00000;
  else
    v9 = m_cachedCurrentNavVolume->m_runtimeId << 22;
  this->m_cachedModifierInfo.m_edge = &this->m_cachedCurrentEdge;
  v10 = v9 | m_oppositeCell & 0x3FFFFF;
  if ( m_oppositeCell == -1 )
    v10 = -1;
  this->m_cachedCurrentEdge.m_oppositeCell = v10;
  this->m_cachedModifierInfo.m_edgeKey = eIdx | (this->m_cachedCurrentSectionId << 22);
}

// File Line: 373
// RVA: 0xC1D320
void __fastcall hkaiNavVolumeGraph::setAdjacentCachedCell(hkaiNavVolumeGraph *this, unsigned int cellKey)
{
  hkaiNavVolumeInstance *m_cachedAdjacentNavVolume; // r10
  __m128 *m_pntr; // rax
  __m128i v4; // xmm2
  __m128i v5; // xmm0
  __m128 v6; // xmm4
  __m128i v7; // xmm0
  __m128 v8; // xmm3
  __m128 v9; // xmm0
  hkVector4f v10; // xmm2
  hkVector4f v11; // xmm1

  m_cachedAdjacentNavVolume = this->m_cachedAdjacentNavVolume;
  this->m_cachedAdjacentCell = m_cachedAdjacentNavVolume->m_originalCells[cellKey & 0x3FFFFF];
  m_pntr = (__m128 *)m_cachedAdjacentNavVolume->m_originalVolume.m_pntr;
  v4 = _mm_loadu_si128((const __m128i *)&this->m_cachedAdjacentCell);
  v5 = _mm_unpacklo_epi16(v4, (__m128i)0i64);
  v6 = _mm_add_ps(
         _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v5, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v5, 0x10u), 0x10u)));
  v7 = _mm_unpackhi_epi16(v4, (__m128i)0i64);
  v8 = _mm_add_ps(
         _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v7, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v7, 0x10u), 0x10u)));
  v9 = _mm_add_ps(m_pntr[7], m_cachedAdjacentNavVolume->m_translation.m_quad);
  v10.m_quad = _mm_add_ps(_mm_mul_ps(m_pntr[6], v8), v9);
  v11.m_quad = _mm_add_ps(_mm_mul_ps(m_pntr[6], v6), v9);
  this->m_cachedAdjacentAabb.m_max = (hkVector4f)v10.m_quad;
  this->m_cachedAdjacentAabb.m_min = (hkVector4f)v11.m_quad;
  this->m_cachedModifierInfo.m_adjacentCellInfo.m_cellKey = cellKey;
  this->m_cachedModifierInfo.m_adjacentCellInfo.m_cell = &this->m_cachedAdjacentCell;
  this->m_cachedModifierInfo.m_adjacentCellInfo.m_position.m_quad = _mm_mul_ps(
                                                                      _mm_add_ps(v10.m_quad, v11.m_quad),
                                                                      (__m128)xmmword_141A711B0);
}

