// File Line: 292
// RVA: 0xC1D1A0
void __fastcall hkaiNavVolumeGraph::nextNode(hkaiNavVolumeGraph *this, int nid)
{
  hkaiNavVolumeGraph *v2; // rbx
  int v3; // er11
  __int64 v4; // rcx
  hkaiNavVolumeInstance *v5; // r8
  __m128 *v6; // r9
  __m128i *v7; // r8
  __int64 v8; // r10
  _DWORD *v9; // rdx
  __int64 v10; // rcx
  __m128i v11; // xmm5
  __m128 *v12; // rax
  __m128i v13; // xmm2
  __m128i v14; // xmm5
  __m128i v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  hkaiHashSearchState *v20; // rbx
  hkaiSearchStateNode *v21; // rax

  v2 = this;
  v3 = nid;
  v4 = (unsigned int)nid >> 22;
  if ( v2->m_cachedCurrentSectionId != (_DWORD)v4 )
  {
    v5 = v2->m_streamingInfo[v4].m_volumeInstancePtr;
    v2->m_cachedCurrentSectionId = v4;
    v2->m_cachedCurrentNavVolume = v5;
  }
  v6 = (__m128 *)v2->m_cachedCurrentNavVolume;
  v7 = (__m128i *)&v2->m_cachedCurrentCell;
  v8 = nid & 0x3FFFFF;
  v9 = (_DWORD *)(v6[1].m128_u64[0] + 24 * v8);
  LODWORD(v7->m128i_i64[0]) = *v9;
  HIDWORD(v7->m128i_i64[0]) = v9[1];
  LODWORD(v7->m128i_i64[1]) = v9[2];
  HIDWORD(v7->m128i_i64[1]) = v9[3];
  v7[1].m128i_i32[0] = v9[4];
  v7[1].m128i_i32[1] = v9[5];
  if ( v6[4].m128_i32[0] && (v10 = *(signed int *)(v6[3].m128_u64[1] + 4 * v8), (_DWORD)v10 != -1) )
  {
    v2->m_cachedCurrentCellInstance = *(hkaiNavVolumeInstance::CellInstance *)(v6[4].m128_u64[1] + 8 * v10);
  }
  else
  {
    v2->m_cachedCurrentCellInstance.m_startEdgeIndex = -1;
    v2->m_cachedCurrentCellInstance.m_numEdges = 0;
  }
  v2->m_cachedModifierInfo.m_currentCellInfo.m_cell = (hkaiNavVolume::Cell *)v7;
  v2->m_cachedModifierInfo.m_currentCellInfo.m_cellKey = v3;
  v11 = _mm_loadu_si128(v7);
  v12 = (__m128 *)v6[3].m128_u64[0];
  v13 = v11;
  v14 = _mm_unpackhi_epi16(v11, (__m128i)0i64);
  v15 = _mm_unpacklo_epi16(v13, (__m128i)0i64);
  v16 = _mm_mul_ps(
          v12[6],
          _mm_add_ps(
            _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v15, 0x10u)), (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
            _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v15, 0x10u), 0x10u))));
  v17 = _mm_add_ps(v12[7], v6[7]);
  v18 = _mm_add_ps(
          _mm_mul_ps(
            v12[6],
            _mm_add_ps(
              _mm_mul_ps(
                _mm_cvtepi32_ps(_mm_srli_epi32(v14, 0x10u)),
                (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v14, 0x10u), 0x10u)))),
          v17);
  v19 = _mm_add_ps(v16, v17);
  v2->m_cachedCurrentAabb.m_max.m_quad = v18;
  v2->m_cachedCurrentAabb.m_min.m_quad = v19;
  v2->m_cachedModifierInfo.m_currentCellInfo.m_position.m_quad = _mm_mul_ps(
                                                                   _mm_add_ps(v18, v19),
                                                                   (__m128)xmmword_141A711B0);
  v20 = v2->m_searchState;
  v21 = hkaiHashSearchState::getNodeState(v20, v3);
  v20->m_currentNodeState = v21;
  v20->m_parentNodeState = v21;
  v20->m_parentIndex = (signed __int16)((signed __int64)(unsigned int)((_DWORD)v21 - LODWORD(v20->m_nodes)) >> 4);
}

// File Line: 310
// RVA: 0xC1D110
void __fastcall hkaiNavVolumeGraph::nextEdge(hkaiNavVolumeGraph *this, int nid, int eIdx)
{
  hkaiNavVolumeInstance *v3; // r9
  hkaiNavVolumeGraph *v4; // r10
  int v5; // ecx
  hkaiNavVolume::Edge *v6; // rax
  hkaiNavVolume::Edge v7; // rax
  unsigned int v8; // er11
  unsigned int v9; // ecx
  int v10; // eax

  v3 = this->m_cachedCurrentNavVolume;
  v4 = this;
  v5 = v3->m_numOriginalEdges;
  if ( eIdx >= v5 )
    v6 = &v3->m_ownedEdges.m_data[eIdx - v5];
  else
    v6 = &v3->m_originalEdges[eIdx];
  v7 = *v6;
  v4->m_cachedCurrentEdge = v7;
  v8 = v4->m_cachedCurrentEdge.m_oppositeCell;
  if ( v7.m_flags.m_storage & 0x40 )
    v9 = v8 & 0xFFC00000;
  else
    v9 = v3->m_runtimeId << 22;
  v4->m_cachedModifierInfo.m_edge = &v4->m_cachedCurrentEdge;
  v10 = v9 | v8 & 0x3FFFFF;
  if ( v8 == -1 )
    v10 = -1;
  v4->m_cachedCurrentEdge.m_oppositeCell = v10;
  v4->m_cachedModifierInfo.m_edgeKey = eIdx | (v4->m_cachedCurrentSectionId << 22);
}

// File Line: 373
// RVA: 0xC1D320
void __fastcall hkaiNavVolumeGraph::setAdjacentCachedCell(hkaiNavVolumeGraph *this, unsigned int cellKey)
{
  hkaiNavVolumeInstance *v2; // r10
  hkaiNavVolume::Cell *v3; // r11
  hkaiNavVolume::Cell *v4; // r9
  __m128 *v5; // rax
  __m128i v6; // xmm5
  __m128i v7; // xmm2
  __m128i v8; // xmm5
  __m128i v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  hkVector4f v12; // xmm2
  hkVector4f v13; // xmm1

  v2 = this->m_cachedAdjacentNavVolume;
  v3 = &this->m_cachedAdjacentCell;
  v4 = &v2->m_originalCells[cellKey & 0x3FFFFF];
  *(_DWORD *)v3->m_min = *(_DWORD *)v4->m_min;
  *(_DWORD *)&v3->m_min[2] = *(_DWORD *)&v4->m_min[2];
  *(_DWORD *)v3->m_max = *(_DWORD *)v4->m_max;
  *(_DWORD *)&v3->m_max[2] = *(_DWORD *)&v4->m_max[2];
  v3->m_startEdgeIndex = v4->m_startEdgeIndex;
  v3->m_data = v4->m_data;
  v5 = (__m128 *)v2->m_originalVolume.m_pntr;
  v6 = _mm_loadu_si128((const __m128i *)&this->m_cachedAdjacentCell);
  v7 = v6;
  v8 = _mm_unpackhi_epi16(v6, (__m128i)0i64);
  v9 = _mm_unpacklo_epi16(v7, (__m128i)0i64);
  v10 = _mm_mul_ps(
          v5[6],
          _mm_add_ps(
            _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v9, 0x10u)), (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
            _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v9, 0x10u), 0x10u))));
  v11 = _mm_add_ps(v5[7], v2->m_translation.m_quad);
  v12.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   v5[6],
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_cvtepi32_ps(_mm_srli_epi32(v8, 0x10u)),
                       (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                     _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v8, 0x10u), 0x10u)))),
                 v11);
  v13.m_quad = _mm_add_ps(v10, v11);
  this->m_cachedAdjacentAabb.m_max = (hkVector4f)v12.m_quad;
  this->m_cachedAdjacentAabb.m_min = (hkVector4f)v13.m_quad;
  this->m_cachedModifierInfo.m_adjacentCellInfo.m_cellKey = cellKey;
  this->m_cachedModifierInfo.m_adjacentCellInfo.m_cell = &this->m_cachedAdjacentCell;
  this->m_cachedModifierInfo.m_adjacentCellInfo.m_position.m_quad = _mm_mul_ps(
                                                                      _mm_add_ps(v12.m_quad, v13.m_quad),
                                                                      (__m128)xmmword_141A711B0);
}

