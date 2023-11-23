// File Line: 28
// RVA: 0xBEA770
void __fastcall hkaiEdgePath::fillFromFoundPath(
        hkaiEdgePath *this,
        hkaiPathfindingUtil::FindPathInput *findPathInput,
        hkaiPathfindingUtil::FindPathOutput *findPathOutput,
        float characterRadius,
        float leftTurnRadius,
        float rightTurnRadius,
        hkVector4f *worldUp,
        hkaiGeneralAccessor *accessor,
        hkaiNavMeshCutter *cutter)
{
  hkaiGeneralAccessor *v9; // r12
  float v12; // xmm0_4
  float v13; // xmm2_4
  unsigned int m_startFaceKey; // ebx
  hkSimdFloat32 *m_accessor; // rdx
  __int64 m_size; // r15
  hkaiNavMeshCutter *v17; // r13
  unsigned int edgeIdx; // edi
  __int64 i; // rbx
  __int64 m_goalIndex; // rcx
  unsigned int v21; // edi
  hkaiEdgePath::Edge *v22; // rbx
  hkVector4f v23; // [rsp+50h] [rbp-30h] BYREF
  int faceIndex[4]; // [rsp+60h] [rbp-20h] BYREF
  hkVector4f b; // [rsp+70h] [rbp-10h] BYREF
  unsigned int curFaceKey; // [rsp+D8h] [rbp+58h] BYREF

  v9 = accessor;
  v12 = rightTurnRadius;
  v13 = fmaxf(leftTurnRadius, characterRadius);
  curFaceKey = LODWORD(characterRadius);
  this->m_characterRadius = characterRadius;
  this->m_leftTurnRadius = v13;
  leftTurnRadius = v12;
  this->m_rightTurnRadius = fmaxf(v12, *(float *)&curFaceKey);
  m_startFaceKey = findPathInput->m_startFaceKey;
  curFaceKey = m_startFaceKey;
  LODWORD(rightTurnRadius) = m_startFaceKey >> 22;
  hkaiGeneralAccessor::setSection(v9, m_startFaceKey >> 22);
  this->m_edgeDataStriding = v9->m_accessor->m_edgeDataStriding;
  m_accessor = (hkSimdFloat32 *)v9->m_accessor;
  LOBYTE(leftTurnRadius) = v9->m_accessor->m_originalMesh.m_pntr->m_flags.m_storage & 1;
  if ( LOBYTE(leftTurnRadius) )
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&b,
      m_accessor,
      (hkaiNavMeshInstance *)(m_startFaceKey & 0x3FFFFF),
      (__m128 *)faceIndex);
  else
    *(hkVector4f *)faceIndex = (hkVector4f)worldUp->m_quad;
  hkaiEdgePath::expandEdges(this, findPathOutput->m_visitedEdges.m_size);
  m_size = findPathOutput->m_visitedEdges.m_size;
  v17 = cutter;
  edgeIdx = 0;
  for ( i = 0i64; i < m_size; ++edgeIdx )
    hkaiEdgePath::buildEdge(
      this,
      v9,
      v17,
      findPathOutput->m_visitedEdges.m_data[i++],
      (hkVector4f *)faceIndex,
      &curFaceKey,
      (int *)&rightTurnRadius,
      (bool *)&leftTurnRadius,
      edgeIdx);
  if ( findPathOutput->m_outputParameters.m_status.m_storage == 1 )
  {
    m_goalIndex = findPathOutput->m_outputParameters.m_goalIndex;
    v21 = findPathInput->m_goalFaceKeys.m_data[m_goalIndex];
    b.m_quad = (__m128)findPathInput->m_goalPoints.m_data[m_goalIndex];
    hkaiGeneralAccessor::setSection(v9, v21 >> 22);
    hkVector4f::setTransformedInversePos(&v23, &v9->m_accessor->m_referenceFrame.m_transform, &b);
    v23.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&v23), 4), 4);
    v22 = hkaiEdgePath::expandEdges(this, 1);
    v22->m_left = (hkVector4f)v23.m_quad;
    v22->m_right = (hkVector4f)v23.m_quad;
    v22->m_up = *(hkVector4f *)faceIndex;
    v22->m_edge.m_edgeOffset = -1;
    hkaiNavMeshCutter::makePersistentFaceKey(v17, v21, &v22->m_edge.m_faceKey);
    v22->m_followingTransform.m_col0 = (hkVector4f)transform.m_quad;
    v22->m_followingTransform.m_col1 = (hkVector4f)direction.m_quad;
    v22->m_followingTransform.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v22->m_followingTransform.m_col3 = (hkVector4f)qi.m_vec.m_quad;
    v22->m_flags.m_storage = 0;
  }
}

// File Line: 106
// RVA: 0xBEAC90
void __fastcall hkaiEdgePath::initTraversalState(hkaiEdgePath *this, hkaiEdgePath::TraversalState *traversalState)
{
  traversalState->m_faceEdge = -1;
  traversalState->m_trailingEdge = 0;
  traversalState->m_highestUserEdgeCrossed = -1;
}

// File Line: 121
// RVA: 0xBEACB0
_BOOL8 __fastcall hkaiEdgePath::updateTraversalState(
        hkaiEdgePath *this,
        hkaiEdgePath::TraversalState *traversalStateInOut,
        hkVector4f *newPositionLocal,
        unsigned int newFaceKey,
        bool repairPath,
        float userEdgeTolerance,
        hkaiStreamingCollection *streamingCollection,
        hkaiNavMeshCutter *cutter)
{
  hkaiEdgePath::Edge *m_data; // rbx
  __int64 m_size; // r13
  __int64 m_faceEdge; // rdi
  int m_highestUserEdgeCrossed; // r14d
  int m_trailingEdge; // ebp
  unsigned int v17; // esi
  bool v18; // zf
  __m128 m_quad; // xmm5
  __m128 v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm6
  __m128 v29; // xmm6
  int v30; // r9d
  __int64 v31; // r8
  __int64 p_m_edge; // rdx
  __m128 v33; // xmm6
  __int64 v34; // rsi
  __int64 v35; // r12
  __m128 *p_m_quad; // rbx
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  __m128 v39; // xmm0
  __m128 v40; // xmm2
  __m128 v41; // xmm2
  hkVector4f p; // [rsp+20h] [rbp-58h] BYREF
  hkaiPersistentFaceKey persistentFaceKeyOut; // [rsp+80h] [rbp+8h] BYREF

  m_data = this->m_edges.m_data;
  m_size = this->m_edges.m_size;
  if ( newFaceKey == -1 )
  {
    hkaiEdgePath::updateTraversalStateNaive(this, traversalStateInOut, newPositionLocal);
    return 1i64;
  }
  hkaiNavMeshCutter::makePersistentFaceKey(cutter, newFaceKey, &persistentFaceKeyOut);
  m_faceEdge = traversalStateInOut->m_faceEdge;
  m_highestUserEdgeCrossed = traversalStateInOut->m_highestUserEdgeCrossed;
  m_trailingEdge = traversalStateInOut->m_trailingEdge;
  v17 = newFaceKey >> 22;
  if ( (_DWORD)m_faceEdge == -1
    || m_data[m_faceEdge].m_edge.m_faceKey.m_key != persistentFaceKeyOut.m_key
    || m_data[m_faceEdge].m_edge.m_faceKey.m_offset != persistentFaceKeyOut.m_offset )
  {
    if ( (int)m_faceEdge < (int)m_size - 1
      && m_data[(int)m_faceEdge + 1].m_edge.m_faceKey.m_key == persistentFaceKeyOut.m_key
      && m_data[(int)m_faceEdge + 1].m_edge.m_faceKey.m_offset == persistentFaceKeyOut.m_offset )
    {
      LODWORD(m_faceEdge) = m_faceEdge + 1;
    }
    else
    {
      v30 = m_highestUserEdgeCrossed + 1;
      v31 = m_highestUserEdgeCrossed + 1;
      if ( v31 == m_size )
      {
LABEL_21:
        if ( repairPath )
        {
          LODWORD(m_faceEdge) = -1;
          goto LABEL_32;
        }
      }
      else
      {
        p_m_edge = (__int64)&m_data[v30].m_edge;
        while ( *(_DWORD *)p_m_edge != persistentFaceKeyOut.m_key
             || *(_WORD *)(p_m_edge + 4) != persistentFaceKeyOut.m_offset )
        {
          ++v31;
          ++v30;
          p_m_edge += 144i64;
          if ( v31 == m_size )
            goto LABEL_21;
        }
        LODWORD(m_faceEdge) = v30;
      }
    }
  }
  if ( (_DWORD)m_faceEdge != -1 )
  {
    v18 = m_highestUserEdgeCrossed == (_DWORD)m_faceEdge;
    if ( m_highestUserEdgeCrossed < (int)m_faceEdge )
    {
      if ( (m_data[(int)m_faceEdge].m_flags.m_storage & 0x10) != 0
        && v17 == m_data[(int)m_faceEdge].m_edge.m_faceKey.m_key >> 22 )
      {
        m_quad = m_data[(int)m_faceEdge].m_left.m_quad;
        v20 = _mm_sub_ps(m_quad, newPositionLocal->m_quad);
        v21 = _mm_sub_ps(m_quad, m_data[(int)m_faceEdge].m_right.m_quad);
        v22 = _mm_mul_ps(v21, v21);
        v23 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                _mm_shuffle_ps(v22, v22, 170));
        v24 = _mm_mul_ps(v20, v21);
        v25 = _mm_rcp_ps(v23);
        v26 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                  _mm_shuffle_ps(v24, v24, 170)),
                _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v25)), v25));
        v27 = _mm_cmplt_ps(v26, query.m_quad);
        v28 = _mm_sub_ps(
                v20,
                _mm_mul_ps(
                  _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v26, v27), _mm_andnot_ps(v27, query.m_quad))),
                  v21));
        v29 = _mm_mul_ps(v28, v28);
        if ( (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
                   + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]) < (float)(userEdgeTolerance * userEdgeTolerance) )
        {
          m_highestUserEdgeCrossed = m_faceEdge;
          m_trailingEdge = m_faceEdge + 1;
          goto LABEL_32;
        }
      }
      v18 = m_highestUserEdgeCrossed == (_DWORD)m_faceEdge;
    }
    if ( v18 )
    {
      m_trailingEdge = m_highestUserEdgeCrossed + 1;
    }
    else
    {
      v33 = newPositionLocal->m_quad;
      v34 = (int)m_faceEdge;
      v35 = m_highestUserEdgeCrossed + 1;
      m_trailingEdge = m_faceEdge;
      if ( (int)m_faceEdge > v35 )
      {
        p_m_quad = &m_data[(int)m_faceEdge - 1].m_followingTransform.m_col1.m_quad;
        do
        {
          v33 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), p_m_quad[-1]), p_m_quad[2]),
                    _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), *p_m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), p_m_quad[1]));
          v37 = p_m_quad[-4];
          v38 = _mm_sub_ps(p_m_quad[-3], v33);
          p.m_quad = v33;
          v39 = _mm_sub_ps(v37, v33);
          v40 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v38),
                  _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v39));
          v41 = _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), p_m_quad[-2]);
          if ( (float)((float)(_mm_shuffle_ps(v41, v41, 85).m128_f32[0] + _mm_shuffle_ps(v41, v41, 0).m128_f32[0])
                     + _mm_shuffle_ps(v41, v41, 170).m128_f32[0]) > 0.0 )
            break;
          if ( !hkaiEdgePathSteeringUtil::inCapsule(
                  &p,
                  (hkVector4f *)&p_m_quad[-4],
                  (hkVector4f *)&p_m_quad[-3],
                  (hkVector4f *)&p_m_quad[-2]) )
            break;
          --v34;
          --m_trailingEdge;
          p_m_quad -= 9;
        }
        while ( v34 > v35 );
      }
    }
  }
LABEL_32:
  traversalStateInOut->m_faceEdge = m_faceEdge;
  traversalStateInOut->m_trailingEdge = m_trailingEdge;
  traversalStateInOut->m_highestUserEdgeCrossed = m_highestUserEdgeCrossed;
  return (int)m_faceEdge >= 0;
}

// File Line: 270
// RVA: 0xBEB0D0
void __fastcall hkaiEdgePath::getFutureEdgeRange(
        hkaiEdgePath *this,
        hkaiEdgePath::TraversalState *traversalState,
        hkaiEdgePath::Edge **begin,
        hkaiEdgePath::Edge **end)
{
  *begin = &this->m_edges.m_data[traversalState->m_trailingEdge];
  *end = &this->m_edges.m_data[this->m_edges.m_size];
}

// File Line: 277
// RVA: 0xBEB100
void __fastcall hkaiEdgePath::getFutureEdgeRange(
        hkaiEdgePath *this,
        int offset,
        hkaiEdgePath::Edge **begin,
        hkaiEdgePath::Edge **end)
{
  *begin = &this->m_edges.m_data[offset];
  *end = &this->m_edges.m_data[this->m_edges.m_size];
}

// File Line: 283
// RVA: 0xBEA9A0
hkaiEdgePath::Edge *__fastcall hkaiEdgePath::expandEdges(hkaiEdgePath *this, int numNewEdges)
{
  int v2; // edi
  int v3; // eax
  int v4; // r9d
  int v7; // eax
  __int64 m_size; // rdi
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v2 = numNewEdges * this->m_edgeDataStriding;
  v3 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = v2 + this->m_edgeData.m_size;
  if ( v3 < v4 )
  {
    v7 = 2 * v3;
    if ( v4 < v7 )
      v4 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edgeData, v4, 4);
  }
  this->m_edgeData.m_size += v2;
  m_size = this->m_edges.m_size;
  v9 = m_size + numNewEdges;
  v10 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (int)m_size + numNewEdges )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v9, 144);
  }
  this->m_edges.m_size += numNewEdges;
  return &this->m_edges.m_data[m_size];
}

// File Line: 289
// RVA: 0xBEAA70
hkaiEdgePath::Edge *__fastcall hkaiEdgePath::expandEdges(hkaiEdgePath *this, int numNewEdges, int **edgeDataPtrOut)
{
  __int64 m_size; // r14
  int v4; // esi
  int v5; // r9d
  int v6; // eax
  int v10; // eax
  __int64 v11; // rsi
  int v12; // r9d
  int v13; // eax
  int v14; // eax
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  m_size = this->m_edgeData.m_size;
  v4 = numNewEdges * this->m_edgeDataStriding;
  v5 = m_size + v4;
  v6 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < (int)m_size + v4 )
  {
    v10 = 2 * v6;
    if ( v5 < v10 )
      v5 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edgeData, v5, 4);
  }
  this->m_edgeData.m_size += v4;
  *edgeDataPtrOut = &this->m_edgeData.m_data[m_size];
  v11 = this->m_edges.m_size;
  v12 = v11 + numNewEdges;
  v13 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < (int)v11 + numNewEdges )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v12, 144);
  }
  this->m_edges.m_size += numNewEdges;
  return &this->m_edges.m_data[v11];
}

// File Line: 295
// RVA: 0xBEAB50
__int64 __fastcall hkaiEdgePath::getNumEdges(hkaiEdgePath *this)
{
  return (unsigned int)this->m_edges.m_size;
}

// File Line: 300
// RVA: 0xBEAB60
hkaiEdgePath::Edge *__fastcall hkaiEdgePath::getEdge(hkaiEdgePath *this, int edgeIdx)
{
  return &this->m_edges.m_data[edgeIdx];
}

// File Line: 308
// RVA: 0xBEAC50
void __fastcall hkaiEdgePath::getEdgePointsInGlobalSpace(
        hkaiEdgePath *this,
        int edgeIdx,
        hkaiStreamingCollection *streamingCollection,
        hkVector4f *leftGlobal,
        hkVector4f *rightGlobal)
{
  hkaiEdgePath::getEdgePointsInGlobalSpace(&this->m_edges.m_data[edgeIdx], streamingCollection, leftGlobal, rightGlobal);
}

// File Line: 318
// RVA: 0xBEABC0
void __fastcall hkaiEdgePath::getEdgePointsInGlobalSpace(
        hkaiEdgePath::Edge *edge,
        hkaiStreamingCollection *streamingCollection,
        hkVector4f *leftGlobal,
        hkVector4f *rightGlobal)
{
  hkTransformf a; // [rsp+20h] [rbp-48h] BYREF

  a = streamingCollection->m_instances.m_data[edge->m_edge.m_faceKey.m_key >> 22].m_instancePtr->m_referenceFrame.m_transform;
  hkVector4f::setTransformedPos(leftGlobal, &a, &edge->m_left);
  hkVector4f::setTransformedPos(rightGlobal, &a, &edge->m_right);
}

// File Line: 333
// RVA: 0xBEB010
void __fastcall hkaiEdgePath::updateTraversalStateNaive(
        hkaiEdgePath *this,
        hkaiEdgePath::TraversalState *traversalState,
        hkVector4f *newPositionGlobal)
{
  __int64 m_trailingEdge; // r10
  int v4; // r9d
  __int64 v5; // rax
  __m128 m_quad; // xmm3
  hkaiEdgePath::Edge *v7; // rcx
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  int v12; // eax

  m_trailingEdge = traversalState->m_trailingEdge;
  v4 = this->m_edges.m_size - 1;
  v5 = m_trailingEdge;
  if ( m_trailingEdge < v4 )
  {
    m_quad = newPositionGlobal->m_quad;
    v7 = &this->m_edges.m_data[m_trailingEdge];
    do
    {
      v8 = _mm_sub_ps(v7->m_right.m_quad, m_quad);
      v9 = _mm_sub_ps(v7->m_left.m_quad, m_quad);
      v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
      v11 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v7->m_up.m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
                 + _mm_shuffle_ps(v11, v11, 170).m128_f32[0]) >= 0.0 )
        break;
      ++v5;
      LODWORD(m_trailingEdge) = m_trailingEdge + 1;
      ++v7;
    }
    while ( v5 < v4 );
  }
  v12 = m_trailingEdge - 1;
  if ( (int)m_trailingEdge - 1 < 0 )
    v12 = 0;
  traversalState->m_trailingEdge = v12;
}

// File Line: 357
// RVA: 0xBEB130
__int64 __fastcall hkaiEdgePath::getGoal(hkaiEdgePath *this, int *goalSectionOut, hkVector4f *goalOut)
{
  hkaiEdgePath::Edge *v4; // rdx
  unsigned int m_key; // eax
  int v6; // eax
  __int64 result; // rax

  if ( !this->m_edges.m_size )
    return 0i64;
  v4 = &this->m_edges.m_data[this->m_edges.m_size];
  if ( _mm_movemask_ps(_mm_cmpeq_ps(v4[-1].m_right.m_quad, v4[-1].m_left.m_quad)) != 15 )
    return 0i64;
  m_key = v4[-1].m_edge.m_faceKey.m_key;
  if ( m_key == -1 )
    v6 = -1;
  else
    v6 = m_key >> 22;
  *goalSectionOut = v6;
  result = 1i64;
  *goalOut = v4[-1].m_left;
  return result;
}

// File Line: 379
// RVA: 0xBEB190
_BOOL8 __fastcall hkaiEdgePath::hasGoal(hkaiEdgePath *this)
{
  return this->m_edges.m_size
      && _mm_movemask_ps(
           _mm_cmpeq_ps(
             this->m_edges.m_data[this->m_edges.m_size - 1].m_right.m_quad,
             this->m_edges.m_data[this->m_edges.m_size - 1].m_left.m_quad)) == 15;
}

// File Line: 396
// RVA: 0xBEB2C0
void __fastcall hkaiEdgePath::calcWallClimbingTransform(
        hkVector4f *leftPoint,
        hkVector4f *curUp,
        hkVector4f *newUp,
        hkMatrix4f *transformOut)
{
  __m128 m_quad; // xmm7
  __m128 v7; // xmm9
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm8
  __m128 v11; // xmm8
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  __m128i m_col1; // xmm4
  __m128i m_col0; // xmm2
  hkVector4f v22; // xmm5
  hkMatrix3f aTb; // [rsp+20h] [rbp-D8h] BYREF
  hkMatrix3f bTc; // [rsp+50h] [rbp-A8h] BYREF
  hkMatrix3f v25; // [rsp+80h] [rbp-78h] BYREF

  m_quad = curUp->m_quad;
  v7 = newUp->m_quad;
  v8 = _mm_shuffle_ps(m_quad, m_quad, 201);
  v9 = _mm_shuffle_ps(v7, v7, 201);
  aTb.m_col2 = (hkVector4f)curUp->m_quad;
  v10 = _mm_sub_ps(_mm_mul_ps(v7, v8), _mm_mul_ps(v9, m_quad));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  aTb.m_col0.m_quad = _mm_mul_ps(
                        v11,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v13, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                            _mm_mul_ps(*(__m128 *)_xmm, v14))));
  v15 = _mm_shuffle_ps(aTb.m_col0.m_quad, aTb.m_col0.m_quad, 201);
  v16 = _mm_sub_ps(_mm_mul_ps(v15, v7), _mm_mul_ps(v9, aTb.m_col0.m_quad));
  v17 = _mm_sub_ps(_mm_mul_ps(v15, m_quad), _mm_mul_ps(v8, aTb.m_col0.m_quad));
  v18 = _mm_shuffle_ps(v16, v16, 201);
  v19 = _mm_unpacklo_ps(aTb.m_col0.m_quad, v18);
  aTb.m_col1.m_quad = _mm_shuffle_ps(v17, v17, 201);
  bTc.m_col0.m_quad = _mm_movelh_ps(v19, v7);
  bTc.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(aTb.m_col0.m_quad, v18), v7, 228);
  bTc.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(bTc.m_col0.m_quad, v19), v7, 212);
  hkMatrix3f::setMul(&v25, &aTb, &bTc);
  m_col1 = (__m128i)v25.m_col1;
  m_col0 = (__m128i)v25.m_col0;
  v22.m_quad = _mm_sub_ps(
                 leftPoint->m_quad,
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(leftPoint->m_quad, leftPoint->m_quad, 85), v25.m_col1.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(leftPoint->m_quad, leftPoint->m_quad, 0), v25.m_col0.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(leftPoint->m_quad, leftPoint->m_quad, 170), v25.m_col2.m_quad)));
  transformOut->m_col2 = v25.m_col2;
  transformOut->m_col0 = (hkVector4f)m_col0;
  transformOut->m_col3 = (hkVector4f)v22.m_quad;
  transformOut->m_col1 = (hkVector4f)m_col1;
  transformOut->m_col0 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(m_col0, 4), 4);
  transformOut->m_col2 = (hkVector4f)_mm_srli_si128(
                                       _mm_slli_si128(_mm_load_si128((const __m128i *)&transformOut->m_col2), 4),
                                       4);
  transformOut->m_col1 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(m_col1, 4), 4);
  transformOut->m_col3.m_quad = _mm_shuffle_ps(v22.m_quad, _mm_unpackhi_ps(v22.m_quad, query.m_quad), 196);
}

// File Line: 442
// RVA: 0xBEB4B0
void __fastcall hkaiEdgePath::calcFollowingTransform(
        hkVector4f *curLeftPoint,
        hkVector4f *curRightPoint,
        hkVector4f *curUp,
        hkVector4f *newLeftPoint,
        hkVector4f *newRightPoint,
        hkVector4f *newUp,
        hkMatrix4f *followingTransform)
{
  __m128 v9; // xmm6
  __m128 m_quad; // xmm12
  __m128 v11; // xmm13
  __m128 v12; // xmm1
  __m128 v13; // xmm13
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm7
  hkVector4f v18; // xmm13
  __m128 v19; // xmm7
  __m128 v20; // xmm8
  __m128 v21; // xmm8
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm5
  __m128 v26; // xmm1
  __m128 v27; // xmm6
  __m128 v28; // xmm1
  __m128 v29; // xmm4
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  __m128 v32; // xmm6
  __m128 v33; // xmm3
  __m128 v34; // xmm1
  __m128 v35; // xmm4
  __m128 v36; // xmm4
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm5
  hkVector4f v44; // xmm1
  __m128i m_col1; // xmm4
  hkVector4f v46; // xmm0
  hkVector4f v47; // xmm5
  __m128i si128; // xmm0
  hkSimdFloat32 scale; // [rsp+20h] [rbp-128h] BYREF
  hkMatrix3f v50; // [rsp+30h] [rbp-118h] BYREF
  hkMatrix3f bTc; // [rsp+60h] [rbp-E8h] BYREF
  hkMatrix3f v52; // [rsp+90h] [rbp-B8h] BYREF

  v9 = _mm_sub_ps(newRightPoint->m_quad, newLeftPoint->m_quad);
  m_quad = curUp->m_quad;
  v11 = _mm_sub_ps(curRightPoint->m_quad, curLeftPoint->m_quad);
  v12 = _mm_mul_ps(v11, curUp->m_quad);
  v13 = _mm_sub_ps(
          v11,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
              _mm_shuffle_ps(v12, v12, 170)),
            curUp->m_quad));
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)), _mm_shuffle_ps(v14, v14, 170));
  v16 = _mm_rsqrt_ps(v15);
  v17 = _mm_andnot_ps(
          _mm_cmple_ps(v15, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)), _mm_mul_ps(v16, *(__m128 *)_xmm)));
  v18.m_quad = _mm_mul_ps(v13, v17);
  v19 = _mm_mul_ps(v17, v15);
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v18.m_quad, v18.m_quad, 201), curUp->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v18.m_quad));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_mul_ps(v21, v21);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_rsqrt_ps(v23);
  v52.m_col0 = (hkVector4f)v18.m_quad;
  v25 = newUp->m_quad;
  v52.m_col1.m_quad = _mm_mul_ps(
                        v21,
                        _mm_andnot_ps(
                          _mm_cmple_ps(v23, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
                            _mm_mul_ps(v24, *(__m128 *)_xmm))));
  v52.m_col2.m_quad = m_quad;
  v26 = _mm_mul_ps(v9, v25);
  v27 = _mm_sub_ps(
          v9,
          _mm_mul_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
              _mm_shuffle_ps(v26, v26, 170)),
            v25));
  v28 = _mm_mul_ps(v27, v27);
  v29 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)), _mm_shuffle_ps(v28, v28, 170));
  v30 = _mm_rsqrt_ps(v29);
  v31 = _mm_andnot_ps(
          _mm_cmple_ps(v29, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)), _mm_mul_ps(v30, *(__m128 *)_xmm)));
  v32 = _mm_mul_ps(v27, v31);
  v33 = _mm_mul_ps(v31, v29);
  v34 = _mm_rcp_ps(v33);
  v35 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v25), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v32));
  scale.m_real = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v34, v33)), v34), v19);
  v36 = _mm_shuffle_ps(v35, v35, 201);
  v37 = _mm_mul_ps(v36, v36);
  v38 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)), _mm_shuffle_ps(v37, v37, 170));
  v39 = _mm_rsqrt_ps(v38);
  v40 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmple_ps(v38, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
              _mm_mul_ps(v39, *(__m128 *)_xmm))),
          v36);
  v41 = _mm_unpacklo_ps(v32, v40);
  bTc.m_col0.m_quad = _mm_movelh_ps(v41, v25);
  bTc.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v32, v40), v25, 228);
  bTc.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(bTc.m_col0.m_quad, v41), v25, 212);
  hkMatrix3f::setMul(&v50, &v52, &bTc);
  hkMatrix3f::mul(&v50, &scale);
  v42 = newLeftPoint->m_quad;
  v43 = curLeftPoint->m_quad;
  v44.m_quad = (__m128)v50.m_col0;
  m_col1 = (__m128i)v50.m_col1;
  followingTransform->m_col0 = v50.m_col0;
  followingTransform->m_col1 = (hkVector4f)m_col1;
  v46.m_quad = (__m128)v50.m_col2;
  followingTransform->m_col2 = v50.m_col2;
  v47.m_quad = _mm_sub_ps(
                 v43,
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), (__m128)m_col1),
                     _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v44.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v46.m_quad)));
  followingTransform->m_col0 = (hkVector4f)_mm_srli_si128(_mm_slli_si128((__m128i)v44.m_quad, 4), 4);
  si128 = _mm_load_si128((const __m128i *)&followingTransform->m_col2);
  followingTransform->m_col1 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(m_col1, 4), 4);
  followingTransform->m_col3 = (hkVector4f)v47.m_quad;
  followingTransform->m_col2 = (hkVector4f)_mm_srli_si128(_mm_slli_si128(si128, 4), 4);
  followingTransform->m_col3.m_quad = _mm_shuffle_ps(v47.m_quad, _mm_unpackhi_ps(v47.m_quad, query.m_quad), 196);
}

// File Line: 501
// RVA: 0xBEC040
void __fastcall hkaiEdgePath::replacePrefixWithEdge(
        hkaiEdgePath *this,
        int numToRemove,
        unsigned int edgeFaceKey,
        unsigned int edgeKey,
        hkaiStreamingCollection *streamingCollection,
        hkaiNavMeshCutter *cutter)
{
  int m_size; // r14d
  int v11; // eax
  int v12; // ebx
  int v13; // eax
  int v14; // r9d
  __int64 m_edgeDataStriding; // rbp
  int v16; // r14d
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  int curSection[4]; // [rsp+50h] [rbp-78h] BYREF
  __m128 faceIndex; // [rsp+60h] [rbp-68h] BYREF
  hkaiNavMeshUtils v23; // [rsp+70h] [rbp-58h] BYREF
  hkaiGeneralAccessor result[3]; // [rsp+80h] [rbp-48h] BYREF
  bool curSectionIsWC; // [rsp+D8h] [rbp+10h] BYREF
  unsigned int curFaceKey; // [rsp+E0h] [rbp+18h] BYREF

  curFaceKey = edgeFaceKey;
  result[0].m_sectionInfo = streamingCollection->m_instances.m_data;
  result[0].m_currentSection = -1;
  result[0].m_accessor = 0i64;
  curSection[0] = edgeFaceKey >> 22;
  hkaiGeneralAccessor::setSection(result, edgeFaceKey >> 22);
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
    &v23,
    (hkSimdFloat32 *)result[0].m_accessor,
    (hkaiNavMeshInstance *)(edgeFaceKey & 0x3FFFFF),
    &faceIndex);
  curSectionIsWC = result[0].m_accessor->m_originalMesh.m_pntr->m_flags.m_storage & 1;
  if ( numToRemove )
  {
    if ( numToRemove != 1 )
    {
      hkArrayBase<hkaiEdgePath::Edge>::_spliceInto(
        &this->m_edges,
        &hkContainerHeapAllocator::s_alloc,
        0,
        numToRemove - 1,
        0i64,
        0);
      hkArrayBase<unsigned int>::_spliceInto(
        (hkArrayBase<unsigned int> *)&this->m_edgeData,
        &hkContainerHeapAllocator::s_alloc,
        0,
        (numToRemove - 1) * this->m_edgeDataStriding,
        0i64,
        0);
    }
  }
  else
  {
    m_size = this->m_edges.m_size;
    v11 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    v12 = m_size + 1;
    if ( m_size + 1 > v11 )
    {
      v13 = 2 * v11;
      v14 = m_size + 1;
      if ( v12 < v13 )
        v14 = v13;
      hkArrayUtil::_reserve(
        (hkResult *)&streamingCollection,
        &hkContainerHeapAllocator::s_alloc,
        &this->m_edges,
        v14,
        144);
    }
    hkMemUtil::memMove(&this->m_edges.m_data[1], this->m_edges.m_data, 144 * m_size);
    this->m_edges.m_size = v12;
    m_edgeDataStriding = this->m_edgeDataStriding;
    v16 = this->m_edgeData.m_size;
    v17 = v16 + m_edgeDataStriding;
    v18 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v16 + (int)m_edgeDataStriding > v18 )
    {
      v19 = 2 * v18;
      v20 = v16 + m_edgeDataStriding;
      if ( v17 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(
        (hkResult *)&streamingCollection,
        &hkContainerHeapAllocator::s_alloc,
        &this->m_edgeData,
        v20,
        4);
    }
    hkMemUtil::memMove(&this->m_edgeData.m_data[m_edgeDataStriding], this->m_edgeData.m_data, 4 * v16);
    this->m_edgeData.m_size = v17;
  }
  hkaiEdgePath::buildEdge(
    this,
    result,
    cutter,
    edgeKey,
    (hkVector4f *)&faceIndex,
    &curFaceKey,
    curSection,
    &curSectionIsWC,
    0);
}

// File Line: 546
// RVA: 0xBEC930
__int64 __fastcall `anonymous namespace::moveCwInFace(
        hkaiGeneralAccessor *accessor,
        unsigned int *edgeKey,
        unsigned int faceKey)
{
  int v3; // ebx
  hkaiNavMesh::Face *FaceFromPacked; // rax
  unsigned int v6; // ecx
  int v7; // ecx
  __int64 result; // rax

  v3 = *edgeKey;
  FaceFromPacked = hkaiGeneralAccessor::getFaceFromPacked(accessor, faceKey);
  v6 = *edgeKey & 0x3FFFFF;
  if ( v6 == FaceFromPacked->m_startEdgeIndex )
    v7 = FaceFromPacked->m_numEdges + FaceFromPacked->m_startEdgeIndex - 1;
  else
    v7 = v6 - 1;
  result = 0i64;
  *edgeKey = v7 | v3 & 0xFFC00000;
  return result;
}

// File Line: 568
// RVA: 0xBEC980
__int64 __fastcall `anonymous namespace::moveCcwInFace(
        hkaiGeneralAccessor *accessor,
        unsigned int *edgeKey,
        unsigned int faceKey)
{
  int v3; // ebx
  hkaiNavMesh::Face *FaceFromPacked; // rax
  int m_startEdgeIndex; // r8d
  unsigned int v7; // r9d
  __int64 result; // rax

  v3 = *edgeKey;
  FaceFromPacked = hkaiGeneralAccessor::getFaceFromPacked(accessor, faceKey);
  m_startEdgeIndex = FaceFromPacked->m_startEdgeIndex;
  v7 = *edgeKey & 0x3FFFFF;
  if ( v7 != FaceFromPacked->m_numEdges + FaceFromPacked->m_startEdgeIndex - 1 )
    m_startEdgeIndex = v7 + 1;
  result = 0i64;
  *edgeKey = m_startEdgeIndex | v3 & 0xFFC00000;
  return result;
}

// File Line: 590
// RVA: 0xBEC9E0
__int64 __fastcall `anonymous namespace::moveCwAroundVertex(
        hkaiGeneralAccessor *accessor,
        unsigned int *edgeKey,
        unsigned int *faceKey)
{
  hkaiNavMesh::Edge *EdgeFromPacked; // rax
  hkaiNavMesh::Edge *v7; // r9
  char m_storage; // al
  unsigned int m_oppositeFace; // edx
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int m_oppositeEdge; // edx
  unsigned int v13; // ecx
  int v14; // eax

  EdgeFromPacked = hkaiGeneralAccessor::getEdgeFromPacked(accessor, *edgeKey);
  v7 = EdgeFromPacked;
  if ( EdgeFromPacked->m_oppositeEdge == -1 || (m_storage = EdgeFromPacked->m_flags.m_storage, (m_storage & 0x20) != 0) )
  {
    *edgeKey = -1;
    *faceKey = -1;
    return (unsigned int)((v7->m_flags.m_storage & 0x40) != 0) + 1;
  }
  else
  {
    m_oppositeFace = v7->m_oppositeFace;
    if ( (m_storage & 0x40) != 0 )
      v10 = m_oppositeFace & 0xFFC00000;
    else
      v10 = accessor->m_accessor->m_runtimeId << 22;
    v11 = v10 | m_oppositeFace & 0x3FFFFF;
    if ( m_oppositeFace == -1 )
      v11 = -1;
    *faceKey = v11;
    m_oppositeEdge = v7->m_oppositeEdge;
    if ( (v7->m_flags.m_storage & 0x40) != 0 )
      v13 = m_oppositeEdge & 0xFFC00000;
    else
      v13 = accessor->m_accessor->m_runtimeId << 22;
    v14 = v13 | m_oppositeEdge & 0x3FFFFF;
    if ( m_oppositeEdge == -1 )
      v14 = -1;
    *edgeKey = v14;
    `anonymous namespace::moveCcwInFace(accessor, edgeKey, *faceKey);
    return 0i64;
  }
}

// File Line: 617
// RVA: 0xBECAD0
__int64 __fastcall `anonymous namespace::moveCcwAroundVertex(
        hkaiGeneralAccessor *accessor,
        unsigned int *edgeKey,
        unsigned int *faceKey)
{
  hkaiNavMesh::Edge *EdgeFromPacked; // rax
  hkaiNavMesh::Edge *v7; // r9
  char m_storage; // al
  unsigned int m_oppositeFace; // edx
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int m_oppositeEdge; // edx
  unsigned int v13; // ecx
  int v14; // eax

  EdgeFromPacked = hkaiGeneralAccessor::getEdgeFromPacked(accessor, *edgeKey);
  v7 = EdgeFromPacked;
  if ( EdgeFromPacked->m_oppositeEdge == -1 || (m_storage = EdgeFromPacked->m_flags.m_storage, (m_storage & 0x20) != 0) )
  {
    *edgeKey = -1;
    *faceKey = -1;
    return 1i64;
  }
  else
  {
    m_oppositeFace = v7->m_oppositeFace;
    if ( (m_storage & 0x40) != 0 )
      v10 = m_oppositeFace & 0xFFC00000;
    else
      v10 = accessor->m_accessor->m_runtimeId << 22;
    v11 = v10 | m_oppositeFace & 0x3FFFFF;
    if ( m_oppositeFace == -1 )
      v11 = -1;
    *faceKey = v11;
    m_oppositeEdge = v7->m_oppositeEdge;
    if ( (v7->m_flags.m_storage & 0x40) != 0 )
      v13 = m_oppositeEdge & 0xFFC00000;
    else
      v13 = accessor->m_accessor->m_runtimeId << 22;
    v14 = v13 | m_oppositeEdge & 0x3FFFFF;
    if ( m_oppositeEdge == -1 )
      v14 = -1;
    *edgeKey = v14;
    `anonymous namespace::moveCwInFace(accessor, edgeKey, *faceKey);
    return 0i64;
  }
}

// File Line: 642
// RVA: 0xBEC280
__int64 __fastcall hkaiEdgePath::pullPastInternalVertex(
        hkaiEdgePath *this,
        int edgeIndex,
        bool isLeft,
        hkaiEdgePath::TraversalState *curTraversalState,
        hkaiStreamingCollection *streamingCollection,
        hkaiNavMeshCutter *cutter)
{
  hkaiStreamingCollection *v6; // rsi
  hkaiNavMeshCutter *v7; // r13
  int v8; // r12d
  int m_faceEdge; // eax
  int v12; // eax
  int v13; // r14d
  int v14; // edi
  int v15; // edi
  bool v16; // zf
  hkaiEdgePath::Edge *Edge; // rax
  unsigned int v19; // esi
  int v20; // edi
  unsigned int v21; // eax
  int v22; // r12d
  hkResultEnum m_enum; // esi
  __m128 v26; // xmm6
  int v27; // edi
  int m_size; // edx
  int v29; // edi
  unsigned int v30; // edx
  int v31; // eax
  int v32; // eax
  int v33; // r9d
  int v34; // edx
  int m_edgeDataStriding; // ecx
  int v36; // edi
  unsigned int v37; // edx
  int v38; // eax
  int v39; // eax
  int v40; // r9d
  int v41; // r12d
  int edgeIdx; // edi
  __int64 v43; // rdx
  __int64 v44; // rcx
  unsigned int curFaceKey; // [rsp+50h] [rbp-39h] BYREF
  int curSection[3]; // [rsp+54h] [rbp-35h] BYREF
  hkVector4f curUp; // [rsp+60h] [rbp-29h] BYREF
  hkaiGeneralAccessor accessor; // [rsp+70h] [rbp-19h] BYREF
  unsigned int faceKey; // [rsp+E0h] [rbp+57h] BYREF
  unsigned int edgeKey; // [rsp+E8h] [rbp+5Fh] BYREF
  hkResult result; // [rsp+F8h] [rbp+6Fh] BYREF

  edgeKey = edgeIndex;
  v6 = streamingCollection;
  v7 = cutter;
  v8 = 1;
  accessor.m_sectionInfo = streamingCollection->m_instances.m_data;
  m_faceEdge = curTraversalState->m_faceEdge;
  accessor.m_currentSection = -1;
  v12 = m_faceEdge + 1;
  accessor.m_accessor = 0i64;
  v13 = edgeIndex;
  if ( v12 > 1 )
    v8 = v12;
  if ( edgeIndex >= v8 )
  {
    do
    {
      v14 = v13 - 1;
      if ( !hkaiEdgePath::consecutiveEdgesShareVertex(this, v13 - 1, isLeft, v6, v7) )
        break;
      --v13;
    }
    while ( v14 >= v8 );
    edgeIndex = edgeKey;
  }
  v15 = edgeIndex + 1;
  v16 = edgeIndex + 1 == this->m_edges.m_size;
  if ( edgeIndex + 1 < this->m_edges.m_size )
  {
    do
    {
      if ( !hkaiEdgePath::consecutiveEdgesShareVertex(this, v15 - 1, isLeft, v6, v7) )
        break;
      ++v15;
    }
    while ( v15 < this->m_edges.m_size );
    v16 = v15 == this->m_edges.m_size;
  }
  if ( v16 )
    return 1i64;
  Edge = hkaiEdgePath::getEdge(this, v15);
  v19 = hkaiNavMeshCutter::resolvePersistentFaceKey(v7, &Edge->m_edge.m_faceKey);
  curFaceKey = v19;
  if ( v19 == -1 )
    return 2i64;
  v20 = v15 - v13;
  curUp.m_quad.m128_u64[0] = (unsigned __int64)hkaiEdgePath::getEdge(this, v13);
  v21 = hkaiEdgePathSteeringUtil::resolveEdgeToKey(
          (hkaiEdgePath::Edge *)curUp.m_quad.m128_u64[0],
          &accessor,
          v7,
          (unsigned int *)&streamingCollection);
  curSection[0] = v21;
  if ( v21 == -1 )
    return 2i64;
  edgeKey = v21;
  v22 = 0;
  result.m_enum = (int)streamingCollection;
  faceKey = (unsigned int)streamingCollection;
  if ( isLeft
     ? `anonymous namespace::moveCcwInFace(&accessor, &edgeKey, (unsigned int)streamingCollection)
     : `anonymous namespace::moveCwInFace(&accessor, &edgeKey, (unsigned int)streamingCollection) )
  {
    return 2i64;
  }
  if ( result.m_enum != v19 )
  {
    while ( 1 )
    {
      ++v22;
      if ( isLeft
         ? `anonymous namespace::moveCwAroundVertex(&accessor, &edgeKey, &faceKey)
         : `anonymous namespace::moveCcwAroundVertex(&accessor, &edgeKey, &faceKey) )
      {
        return 2i64;
      }
      m_enum = (int)streamingCollection;
      if ( faceKey == (_DWORD)streamingCollection )
        return 2i64;
      if ( faceKey == curFaceKey )
        goto LABEL_29;
    }
  }
  m_enum = (int)streamingCollection;
LABEL_29:
  v26 = *(__m128 *)(curUp.m_quad.m128_u64[0] + 32);
  if ( v22 < v20 )
  {
    v27 = v20 - v22;
    hkArrayBase<hkaiEdgePath::Edge>::_spliceInto(&this->m_edges, &hkContainerHeapAllocator::s_alloc, v13, v27, 0i64, 0);
    hkArrayBase<unsigned int>::_spliceInto(
      (hkArrayBase<unsigned int> *)&this->m_edgeData,
      &hkContainerHeapAllocator::s_alloc,
      v13 * this->m_edgeDataStriding,
      v27 * this->m_edgeDataStriding,
      0i64,
      0);
LABEL_41:
    m_enum = (int)streamingCollection;
    goto LABEL_42;
  }
  if ( v22 > v20 )
  {
    m_size = this->m_edges.m_size;
    edgeKey = v22 - v20;
    v29 = m_size + v22 - v20;
    v30 = m_size - v13;
    v31 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    faceKey = v30;
    if ( v29 > v31 )
    {
      v32 = 2 * v31;
      v33 = v29;
      if ( v29 < v32 )
        v33 = v32;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_edges, v33, 144);
      v30 = faceKey;
    }
    hkMemUtil::memMove(&this->m_edges.m_data[v13 + (__int64)(int)edgeKey], &this->m_edges.m_data[v13], 144 * v30);
    this->m_edges.m_size = v29;
    v34 = this->m_edgeData.m_size;
    m_edgeDataStriding = this->m_edgeDataStriding;
    result.m_enum = v13 * m_edgeDataStriding;
    curFaceKey = edgeKey * m_edgeDataStriding;
    v36 = v34 + edgeKey * m_edgeDataStriding;
    v37 = v34 - v13 * m_edgeDataStriding;
    v38 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
    edgeKey = v37;
    if ( v36 > v38 )
    {
      v39 = 2 * v38;
      v40 = v36;
      if ( v36 < v39 )
        v40 = v39;
      hkArrayUtil::_reserve((hkResult *)&faceKey, &hkContainerHeapAllocator::s_alloc, &this->m_edgeData, v40, 4);
      v37 = edgeKey;
    }
    hkMemUtil::memMove(
      &this->m_edgeData.m_data[(int)result.m_enum + (__int64)(int)curFaceKey],
      &this->m_edgeData.m_data[result.m_enum],
      4 * v37);
    this->m_edgeData.m_size = v36;
    goto LABEL_41;
  }
LABEL_42:
  curUp.m_quad = v26;
  faceKey = curSection[0];
  result.m_enum = m_enum;
  curSection[0] = (unsigned int)m_enum >> 22;
  LOBYTE(edgeKey) = accessor.m_accessor->m_originalMesh.m_pntr->m_flags.m_storage & 1;
  if ( isLeft )
    `anonymous namespace::moveCcwInFace(&accessor, &faceKey, m_enum);
  else
    `anonymous namespace::moveCwInFace(&accessor, &faceKey, m_enum);
  v41 = v13 + v22;
  edgeIdx = v13;
  if ( v13 != v41 )
  {
    while ( 1 )
    {
      curFaceKey = m_enum;
      hkaiEdgePath::buildEdge(this, &accessor, v7, faceKey, &curUp, &curFaceKey, curSection, (bool *)&edgeKey, edgeIdx);
      if ( isLeft )
        `anonymous namespace::moveCwAroundVertex(&accessor, &faceKey, (unsigned int *)&result);
      else
        `anonymous namespace::moveCcwAroundVertex(&accessor, &faceKey, (unsigned int *)&result);
      if ( ++edgeIdx == v41 )
        break;
      m_enum = result.m_enum;
    }
  }
  v43 = v13;
  if ( v13 )
  {
    v44 = 0i64;
    do
    {
      this->m_edges.m_data[v44++].m_leftFollowingCorner.m_data = 0;
      this->m_edges.m_data[v44 - 1].m_rightFollowingCorner.m_data = 0;
      --v43;
    }
    while ( v43 );
  }
  return 0i64;
}

// File Line: 858
// RVA: 0xBEB840
void __fastcall hkaiEdgePath::buildEdge(
        hkaiEdgePath *this,
        hkaiGeneralAccessor *accessor,
        hkaiNavMeshCutter *cutter,
        unsigned int edgeKey,
        hkVector4f *curUp,
        unsigned int *curFaceKey,
        int *curSection,
        bool *curSectionIsWC,
        int edgeIdx)
{
  __m128 v9; // xmm13
  __m128 v12; // xmm7
  hkaiEdgePath::Edge *v13; // rdi
  __m128 v14; // xmm8
  __m128 v15; // xmm12
  hkaiNavMesh::Edge *EdgeFromPacked; // rax
  hkaiNavMeshInstance *m_accessor; // rcx
  hkaiNavMesh::Edge *v18; // r14
  unsigned int m_oppositeEdge; // edx
  __m128 v20; // xmm13
  char v21; // r8
  int m_runtimeId; // r12d
  unsigned int v23; // eax
  int v24; // r15d
  bool v25; // zf
  unsigned int m_oppositeFace; // edx
  unsigned int v27; // eax
  int v28; // r13d
  __int64 m_a; // rax
  int m_numOriginalVertices; // edx
  __m128 *p_m_quad; // rax
  __m128 v32; // xmm9
  __int64 m_b; // rax
  __m128 *v34; // rax
  __m128 v35; // xmm10
  unsigned int v36; // edx
  hkaiNavMesh::Face *FaceFromPacked; // rax
  int index; // ebx
  __m128 v39; // xmm6
  __m128 v40; // xmm2
  __m128 v41; // xmm6
  __m128 v42; // xmm2
  __m128 v43; // xmm0
  __m128 v44; // xmm1
  __m128 v45; // xmm1
  __m128 v46; // xmm11
  __m128 v47; // xmm6
  __m128 v48; // xmm11
  __m128 v49; // xmm6
  __m128 v50; // xmm13
  __m128 v51; // xmm3
  __m128 v52; // xmm15
  __m128 v53; // xmm1
  __m128 v54; // xmm4
  __m128 v55; // xmm4
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  __m128 v60; // xmm4
  __m128 v61; // xmm1
  __m128 v62; // xmm8
  __m128 v63; // xmm7
  __m128 v64; // xmm1
  __m128 v65; // xmm0
  __m128 v66; // xmm4
  int *v67; // rax
  int striding; // edx
  char v69; // al
  bool v70; // bl
  hkVector4f *v71; // r14
  hkaiNavMeshInstance *v72; // rbx
  hkaiNavMesh::Edge *v73; // rax
  int v74; // edx
  __int64 v75; // rcx
  __m128 *v76; // rcx
  __int64 v77; // rax
  __int128 *v78; // rax
  __int128 v79; // xmm0
  hkVector4f v80; // xmm0
  unsigned int startFaceKeya; // [rsp+40h] [rbp-C0h]
  unsigned int startFaceKey; // [rsp+40h] [rbp-C0h]
  hkSimdFloat32 result; // [rsp+50h] [rbp-B0h] BYREF
  void *dst[2]; // [rsp+60h] [rbp-A0h] BYREF
  hkSimdFloat32 maxClearance; // [rsp+70h] [rbp-90h] BYREF
  int faceIndex[4]; // [rsp+80h] [rbp-80h] BYREF
  hkVector4f leftPoint; // [rsp+90h] [rbp-70h] BYREF
  hkVector4f curRightPoint; // [rsp+A0h] [rbp-60h] BYREF
  unsigned int v90; // [rsp+1A8h] [rbp+A8h]
  bool edgeKeyb; // [rsp+1B8h] [rbp+B8h]
  unsigned int edgeIdxa; // [rsp+1E0h] [rbp+E0h]
  unsigned int edgeIdxc; // [rsp+1E0h] [rbp+E0h]
  unsigned int edgeIdxd; // [rsp+1E0h] [rbp+E0h]
  unsigned int edgeIdxe; // [rsp+1E0h] [rbp+E0h]
  bool edgeIdxb; // [rsp+1E0h] [rbp+E0h]

  v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_leftTurnRadius), (__m128)LODWORD(this->m_leftTurnRadius), 0);
  v13 = &this->m_edges.m_data[edgeIdx];
  v14 = _mm_shuffle_ps((__m128)LODWORD(this->m_rightTurnRadius), (__m128)LODWORD(this->m_rightTurnRadius), 0);
  v15 = _mm_shuffle_ps((__m128)LODWORD(this->m_characterRadius), (__m128)LODWORD(this->m_characterRadius), 0);
  dst[0] = hkaiEdgePath::getEdgeDataPtr(this, edgeIdx);
  EdgeFromPacked = hkaiGeneralAccessor::getEdgeFromPacked(accessor, edgeKey);
  m_accessor = accessor->m_accessor;
  v18 = EdgeFromPacked;
  v90 = edgeKey & 0x3FFFFF;
  maxClearance.m_real = _mm_shuffle_ps(
                          (__m128)LODWORD(accessor->m_accessor->m_maxGlobalClearance),
                          (__m128)LODWORD(accessor->m_accessor->m_maxGlobalClearance),
                          0);
  m_oppositeEdge = EdgeFromPacked->m_oppositeEdge;
  v9.m128_f32[0] = m_accessor->m_maxGlobalClearance * 0.99000001;
  v20 = _mm_shuffle_ps(v9, v9, 0);
  v21 = EdgeFromPacked->m_flags.m_storage & 0x40;
  if ( v21 )
    m_runtimeId = m_oppositeEdge >> 22;
  else
    m_runtimeId = m_accessor->m_runtimeId;
  if ( m_oppositeEdge == -1 )
    m_runtimeId = -1;
  if ( v21 )
    v23 = m_oppositeEdge & 0xFFC00000;
  else
    v23 = m_accessor->m_runtimeId << 22;
  v24 = v23 | m_oppositeEdge & 0x3FFFFF;
  v25 = m_oppositeEdge == -1;
  m_oppositeFace = v18->m_oppositeFace;
  if ( v25 )
    v24 = -1;
  if ( v21 )
    v27 = m_oppositeFace & 0xFFC00000;
  else
    v27 = m_accessor->m_runtimeId << 22;
  v28 = v27 | m_oppositeFace & 0x3FFFFF;
  m_a = v18->m_a;
  v25 = m_oppositeFace == -1;
  m_numOriginalVertices = m_accessor->m_numOriginalVertices;
  if ( v25 )
    v28 = -1;
  if ( (int)m_a >= m_numOriginalVertices )
    p_m_quad = &m_accessor->m_ownedVertices.m_data[(int)m_a - m_numOriginalVertices].m_quad;
  else
    p_m_quad = &m_accessor->m_originalVertices[m_a].m_quad;
  v32 = *p_m_quad;
  m_b = v18->m_b;
  if ( (int)m_b >= m_numOriginalVertices )
    v34 = &m_accessor->m_ownedVertices.m_data[(int)m_b - m_numOriginalVertices].m_quad;
  else
    v34 = &m_accessor->m_originalVertices[m_b].m_quad;
  v35 = *v34;
  v36 = *curFaceKey;
  curRightPoint.m_quad = v32;
  leftPoint.m_quad = v35;
  FaceFromPacked = hkaiGeneralAccessor::getFaceFromPacked(accessor, v36);
  edgeIdxa = *curFaceKey;
  index = v90 + 1;
  if ( (int)(v90 + 1) >= FaceFromPacked->m_startEdgeIndex + FaceFromPacked->m_numEdges )
    index = FaceFromPacked->m_startEdgeIndex;
  hkaiGeneralAccessor::setSection(accessor, edgeKey >> 22);
  result.m_real.m128_u64[0] = (unsigned __int64)hkaiNavMeshInstance_get_hkaiNavMesh::Edge__7(
                                                  accessor->m_accessor->m_originalEdges,
                                                  accessor->m_accessor->m_numOriginalEdges,
                                                  &accessor->m_accessor->m_instancedEdges,
                                                  &accessor->m_accessor->m_ownedEdges,
                                                  &accessor->m_accessor->m_edgeMap,
                                                  index);
  hkaiGeneralAccessor::setSection(accessor, edgeIdxa >> 22);
  startFaceKeya = accessor->m_accessor->m_globalClearanceCache.m_data[*(_DWORD *)result.m_real.m128_u64[0]].m_value << 16;
  v39 = _mm_shuffle_ps((__m128)startFaceKeya, (__m128)startFaceKeya, 0);
  if ( v39.m128_f32[0] > maxClearance.m_real.m128_f32[0] )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(
      &result,
      accessor,
      edgeIdxa,
      (hkaiNavMesh::Edge *)result.m_real.m128_u64[0],
      curUp,
      &maxClearance);
    edgeIdxc = (__int16)(COERCE_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
    v39 = _mm_shuffle_ps((__m128)edgeIdxc, (__m128)edgeIdxc, 0);
  }
  startFaceKey = *curFaceKey;
  hkaiGeneralAccessor::setSection(accessor, *curFaceKey >> 22);
  edgeIdxd = accessor->m_accessor->m_globalClearanceCache.m_data[v18->m_a].m_value << 16;
  v40 = _mm_shuffle_ps((__m128)edgeIdxd, (__m128)edgeIdxd, 0);
  if ( v40.m128_f32[0] > maxClearance.m_real.m128_f32[0] )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(&result, accessor, startFaceKey, v18, curUp, &maxClearance);
    edgeIdxe = (__int16)(COERCE_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16;
    v40 = _mm_shuffle_ps((__m128)edgeIdxe, (__m128)edgeIdxe, 0);
  }
  v41 = _mm_max_ps(v39, aabbOut.m_quad);
  v42 = _mm_max_ps(v40, aabbOut.m_quad);
  v43 = _mm_cmple_ps(v20, v41);
  v44 = _mm_sub_ps(v35, v32);
  v45 = _mm_mul_ps(v44, v44);
  v46 = _mm_andnot_ps(v43, v41);
  v47 = _mm_cmple_ps(v20, v42);
  v48 = _mm_or_ps(v46, _mm_and_ps(v43, (__m128)xmmword_141A712B0));
  v49 = _mm_or_ps(_mm_andnot_ps(v47, v42), _mm_and_ps(v47, (__m128)xmmword_141A712B0));
  v50 = _mm_max_ps(_mm_sub_ps(v15, v48), aabbOut.m_quad);
  v51 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)), _mm_shuffle_ps(v45, v45, 170));
  v52 = _mm_max_ps(_mm_sub_ps(v15, v49), aabbOut.m_quad);
  v53 = _mm_rsqrt_ps(v51);
  v54 = _mm_andnot_ps(
          _mm_cmple_ps(v51, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v53), v53)),
              _mm_mul_ps(*(__m128 *)_xmm, v53)),
            v51));
  if ( (v18->m_flags.m_storage & 0x10) != 0 )
  {
    v55 = 0i64;
    v56 = 0i64;
  }
  else
  {
    v57 = _mm_add_ps(v52, v50);
    if ( v54.m128_f32[0] >= v57.m128_f32[0] )
    {
      v56 = _mm_max_ps(_mm_sub_ps(v14, v49), aabbOut.m_quad);
      v61 = _mm_max_ps(_mm_sub_ps(v12, v48), aabbOut.m_quad);
      if ( v54.m128_f32[0] >= (float)(v56.m128_f32[0] + v61.m128_f32[0]) )
      {
        v55 = v61;
      }
      else
      {
        v62 = _mm_sub_ps(v14, v15);
        v63 = _mm_sub_ps(v12, v15);
        v64 = _mm_add_ps(v62, v63);
        v65 = _mm_rcp_ps(v64);
        v66 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v64, v65)), v65), _mm_sub_ps(v54, v57));
        v56 = _mm_add_ps(_mm_mul_ps(v66, v62), v52);
        v55 = _mm_add_ps(_mm_mul_ps(v66, v63), v50);
      }
    }
    else if ( v48.m128_f32[0] == v49.m128_f32[0] )
    {
      v55 = _mm_mul_ps(v54, (__m128)xmmword_141A711B0);
      v56 = v55;
    }
    else
    {
      v58 = _mm_add_ps(v49, v48);
      v59 = _mm_rcp_ps(v58);
      v60 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v58, v59)), v59), v54);
      v56 = _mm_mul_ps(v60, v48);
      v55 = _mm_mul_ps(v60, v49);
    }
  }
  v13->m_left.m_quad = _mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, _mm_sub_ps((__m128)0i64, v55)), 196);
  v13->m_right.m_quad = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, v56), 196);
  v13->m_up = (hkVector4f)curUp->m_quad;
  if ( (v18->m_flags.m_storage & 0x10) != 0 )
  {
    v13->m_edge.m_edgeOffset = -1;
    hkaiNavMeshCutter::makePersistentFaceKey(cutter, *curFaceKey, &v13->m_edge.m_faceKey);
  }
  else
  {
    hkaiNavMeshCutter::makePersistentEdgeKey(cutter, edgeKey, *curFaceKey, &v13->m_edge);
  }
  v13->m_flags.m_storage = v18->m_flags.m_storage;
  v67 = 0i64;
  *(_DWORD *)&v13->m_leftFollowingCorner.m_data = 0;
  striding = accessor->m_accessor->m_edgeDataStriding;
  if ( striding )
    v67 = hkaiNavMeshInstance_getWithStriding_int__2(
            accessor->m_accessor->m_originalEdgeData,
            accessor->m_accessor->m_numOriginalEdges,
            &accessor->m_accessor->m_instancedEdgeData,
            &accessor->m_accessor->m_ownedEdgeData,
            &accessor->m_accessor->m_edgeMap,
            v90,
            striding);
  hkString::memCpy(dst[0], v67, 4 * this->m_edgeDataStriding);
  edgeIdxb = m_runtimeId != *curSection;
  if ( m_runtimeId == *curSection )
  {
    v69 = *curSectionIsWC;
  }
  else
  {
    hkaiGeneralAccessor::setSection(accessor, m_runtimeId);
    v69 = accessor->m_accessor->m_originalMesh.m_pntr->m_flags.m_storage & 1;
  }
  edgeKeyb = v69;
  v70 = (v18->m_flags.m_storage & 0x10) != 0;
  if ( *curSectionIsWC || v69 )
  {
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)dst,
      (hkSimdFloat32 *)accessor->m_accessor,
      (hkaiNavMeshInstance *)(v28 & 0x3FFFFF),
      (__m128 *)faceIndex);
    v71 = curUp;
    v69 = 1;
  }
  else
  {
    v71 = curUp;
    *(hkVector4f *)faceIndex = (hkVector4f)curUp->m_quad;
  }
  if ( v70 || edgeIdxb )
  {
    v72 = accessor->m_accessor;
    v73 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__7(
            accessor->m_accessor->m_originalEdges,
            accessor->m_accessor->m_numOriginalEdges,
            &accessor->m_accessor->m_instancedEdges,
            &accessor->m_accessor->m_ownedEdges,
            &accessor->m_accessor->m_edgeMap,
            v24 & 0x3FFFFF);
    v74 = v72->m_numOriginalVertices;
    v75 = v73->m_a;
    if ( (int)v75 >= v74 )
      v76 = &v72->m_ownedVertices.m_data[(int)v75 - v74].m_quad;
    else
      v76 = &v72->m_originalVertices[v75].m_quad;
    v77 = v73->m_b;
    if ( (int)v77 >= v74 )
      v78 = (__int128 *)&v72->m_ownedVertices.m_data[(int)v77 - v74];
    else
      v78 = (__int128 *)&v72->m_originalVertices[v77];
    v79 = *v78;
    result.m_real = *v76;
    *(_OWORD *)dst = v79;
    hkaiEdgePath::calcFollowingTransform(
      &leftPoint,
      &curRightPoint,
      v71,
      (hkVector4f *)&result,
      (hkVector4f *)dst,
      (hkVector4f *)faceIndex,
      &v13->m_followingTransform);
  }
  else if ( v69 )
  {
    hkaiEdgePath::calcWallClimbingTransform(&leftPoint, v71, (hkVector4f *)faceIndex, &v13->m_followingTransform);
  }
  else
  {
    v13->m_followingTransform.m_col0 = (hkVector4f)transform.m_quad;
    v13->m_followingTransform.m_col1 = (hkVector4f)direction.m_quad;
    v13->m_followingTransform.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v13->m_followingTransform.m_col3 = (hkVector4f)qi.m_vec.m_quad;
  }
  v80.m_quad = *(__m128 *)faceIndex;
  *curSection = m_runtimeId;
  *curFaceKey = v28;
  *curSectionIsWC = edgeKeyb;
  *v71 = (hkVector4f)v80.m_quad;
}

// File Line: 1033
// RVA: 0xBEAB80
int *__fastcall hkaiEdgePath::getEdgeDataPtr(hkaiEdgePath *this, int edgeIdx)
{
  return &this->m_edgeData.m_data[edgeIdx * this->m_edgeDataStriding];
}

// File Line: 1038
// RVA: 0xBEABA0
int *__fastcall hkaiEdgePath::getEdgeDataPtr(hkaiEdgePath *this, int edgeIdx)
{
  return &this->m_edgeData.m_data[edgeIdx * this->m_edgeDataStriding];
}

// File Line: 1043
// RVA: 0xBEB1D0
void __fastcall hkaiEdgePath::setFollowingCornerInfoInvalid(hkaiEdgePath *this, int startEdge, bool startIsLeft)
{
  hkaiEdgePath::getFollowingCornerInfoPacked(this, startEdge, startIsLeft)->m_data = 0x8000;
}

// File Line: 1050
// RVA: 0xBEB1F0
void __fastcall hkaiEdgePath::setFollowingCornerInfoValid(
        hkaiEdgePath *this,
        int startEdge,
        bool startIsLeft,
        __int16 followingCornerEdge,
        bool followingCornerIsLeft)
{
  hkaiEdgePath::getFollowingCornerInfoPacked(this, startEdge, startIsLeft)->m_data = (followingCornerEdge - startEdge) | ((followingCornerIsLeft | 6) << 13);
}

// File Line: 1056
// RVA: 0xBEB240
__int64 __fastcall hkaiEdgePath::hasFollowingCornerInfo(hkaiEdgePath *this, int startEdge, bool startIsLeft)
{
  return hkaiEdgePath::getFollowingCornerInfoPacked(this, startEdge, startIsLeft)->m_data & 0x8000;
}

// File Line: 1061
// RVA: 0xBEB260
__int64 __fastcall hkaiEdgePath::getFollowingCornerInfo(
        hkaiEdgePath *this,
        int startEdge,
        bool startIsLeft,
        int *followingCornerEdgeOut,
        bool *followingCornerIsLeftOut)
{
  hkaiEdgePath::FollowingCornerInfo *FollowingCornerInfoPacked; // rax

  FollowingCornerInfoPacked = hkaiEdgePath::getFollowingCornerInfoPacked(this, startEdge, startIsLeft);
  if ( (FollowingCornerInfoPacked->m_data & 0x4000) == 0 )
    return 0i64;
  *followingCornerEdgeOut = startEdge + (FollowingCornerInfoPacked->m_data & 0x1FFF);
  *followingCornerIsLeftOut = (FollowingCornerInfoPacked->m_data & 0x2000) != 0;
  return 1i64;
}

// File Line: 1076
// RVA: 0xBEC7D0
hkaiEdgePath::FollowingCornerInfo *__fastcall hkaiEdgePath::getFollowingCornerInfoPacked(
        hkaiEdgePath *this,
        int startEdge,
        bool startIsLeft)
{
  hkaiEdgePath::Edge *v3; // rax

  v3 = &this->m_edges.m_data[startEdge];
  if ( startIsLeft )
    return &v3->m_leftFollowingCorner;
  else
    return &v3->m_rightFollowingCorner;
}

// File Line: 1082
// RVA: 0xBEC800
hkaiEdgePath::FollowingCornerInfo *__fastcall hkaiEdgePath::getFollowingCornerInfoPacked(
        hkaiEdgePath *this,
        int startEdge,
        bool startIsLeft)
{
  hkaiEdgePath::Edge *v3; // rax

  v3 = &this->m_edges.m_data[startEdge];
  if ( startIsLeft )
    return &v3->m_leftFollowingCorner;
  else
    return &v3->m_rightFollowingCorner;
}

// File Line: 1092
// RVA: 0xBEA710
void __fastcall hkaiEdgePath::hkaiEdgePath(hkaiEdgePath *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgePath::`vftable;
  this->m_edges.m_capacityAndFlags = 0x80000000;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_edgeData.m_data = 0i64;
  this->m_edgeData.m_size = 0;
  this->m_edgeData.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_edgeDataStriding = 0i64;
  this->m_rightTurnRadius = 0.0;
}

// File Line: 1100
// RVA: 0xBEA750
void __fastcall hkaiEdgePath::hkaiEdgePath(hkaiEdgePath *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgePath::`vftable;
}

// File Line: 1109
// RVA: 0xBEC6B0
__int64 __fastcall hkaiEdgePath::consecutiveEdgesShareVertex(
        hkaiEdgePath *this,
        int firstEdgeIndex,
        bool checkLeft,
        hkaiStreamingCollection *streamingCollection,
        hkaiNavMeshCutter *cutter)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  unsigned int v6; // ebp
  hkaiEdgePath::Edge *Edge; // rsi
  hkaiEdgePath::Edge *v11; // rbx
  hkaiNavMeshCutter *v12; // rdi
  unsigned int v13; // eax
  MoveResult v14; // eax
  unsigned int v15; // eax
  unsigned int faceKeyOut; // [rsp+20h] [rbp-38h] BYREF
  unsigned int v18; // [rsp+24h] [rbp-34h] BYREF
  hkaiGeneralAccessor accessor; // [rsp+28h] [rbp-30h] BYREF
  unsigned int edgeKey; // [rsp+68h] [rbp+10h] BYREF
  unsigned int faceKey; // [rsp+78h] [rbp+20h] BYREF

  m_data = streamingCollection->m_instances.m_data;
  v6 = 0;
  accessor.m_currentSection = -1;
  accessor.m_sectionInfo = m_data;
  accessor.m_accessor = 0i64;
  Edge = hkaiEdgePath::getEdge(this, firstEdgeIndex);
  v11 = hkaiEdgePath::getEdge(this, firstEdgeIndex + 1);
  if ( _mm_movemask_ps(_mm_cmpeq_ps(Edge->m_right.m_quad, Edge->m_left.m_quad)) == 15 )
    return 0i64;
  if ( (Edge->m_flags.m_storage & 0x10) != 0 )
    return 0i64;
  if ( _mm_movemask_ps(_mm_cmpeq_ps(v11->m_right.m_quad, v11->m_left.m_quad)) == 15 )
    return 0i64;
  if ( (v11->m_flags.m_storage & 0x10) != 0 )
    return 0i64;
  v12 = cutter;
  v13 = hkaiEdgePathSteeringUtil::resolveEdgeToKey(Edge, &accessor, cutter, &faceKeyOut);
  if ( v13 == -1 )
    return 0i64;
  edgeKey = v13;
  faceKey = faceKeyOut;
  v14 = checkLeft
      ? `anonymous namespace::moveCcwAroundVertex(&accessor, &edgeKey, &faceKey)
      : `anonymous namespace::moveCwAroundVertex(&accessor, &edgeKey, &faceKey);
  if ( v14 == MOVERESULT_HIT_NONTRAVERSABLE )
    return 0i64;
  v15 = hkaiEdgePathSteeringUtil::resolveEdgeToKey(v11, &accessor, v12, &v18);
  LOBYTE(v6) = edgeKey == v15;
  return v6;
}

