// File Line: 28
// RVA: 0xBEA770
void __fastcall hkaiEdgePath::fillFromFoundPath(hkaiEdgePath *this, hkaiPathfindingUtil::FindPathInput *findPathInput, hkaiPathfindingUtil::FindPathOutput *findPathOutput, float characterRadius, float leftTurnRadius, float rightTurnRadius, hkVector4f *worldUp, hkaiGeneralAccessor *accessor, hkaiNavMeshCutter *cutter)
{
  hkaiGeneralAccessor *v9; // r12
  hkaiEdgePath *v10; // r14
  hkaiPathfindingUtil::FindPathOutput *v11; // rsi
  float v12; // xmm0_4
  float v13; // xmm2_4
  unsigned int v14; // ebx
  hkSimdFloat32 *v15; // rdx
  __int64 v16; // r15
  hkaiNavMeshCutter *v17; // r13
  unsigned int edgeIdx; // edi
  __int64 i; // rbx
  __int64 v20; // rcx
  unsigned int v21; // edi
  hkaiEdgePath::Edge *v22; // rbx
  hkVector4f v23; // [rsp+50h] [rbp-30h]
  int faceIndex[4]; // [rsp+60h] [rbp-20h]
  hkVector4f b; // [rsp+70h] [rbp-10h]
  hkaiPathfindingUtil::FindPathInput *v26; // [rsp+C8h] [rbp+48h]
  unsigned int curFaceKey; // [rsp+D8h] [rbp+58h]

  v26 = findPathInput;
  v9 = accessor;
  v10 = this;
  v11 = findPathOutput;
  v12 = rightTurnRadius;
  v13 = fmaxf(leftTurnRadius, characterRadius);
  curFaceKey = LODWORD(characterRadius);
  this->m_characterRadius = characterRadius;
  this->m_leftTurnRadius = v13;
  leftTurnRadius = v12;
  this->m_rightTurnRadius = fmaxf(v12, *(float *)&curFaceKey);
  v14 = findPathInput->m_startFaceKey;
  curFaceKey = v14;
  LODWORD(rightTurnRadius) = v14 >> 22;
  hkaiGeneralAccessor::setSection(v9, v14 >> 22);
  v10->m_edgeDataStriding = v9->m_accessor->m_edgeDataStriding;
  v15 = (hkSimdFloat32 *)v9->m_accessor;
  LOBYTE(leftTurnRadius) = v9->m_accessor->m_originalMesh.m_pntr->m_flags.m_storage & 1;
  if ( LOBYTE(leftTurnRadius) )
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)&b,
      v15,
      (hkaiNavMeshInstance *)(v14 & 0x3FFFFF),
      (__int64)faceIndex);
  else
    *(hkVector4f *)faceIndex = (hkVector4f)worldUp->m_quad;
  hkaiEdgePath::expandEdges(v10, v11->m_visitedEdges.m_size);
  v16 = v11->m_visitedEdges.m_size;
  v17 = cutter;
  edgeIdx = 0;
  for ( i = 0i64; i < v16; ++edgeIdx )
    hkaiEdgePath::buildEdge(
      v10,
      v9,
      v17,
      v11->m_visitedEdges.m_data[i++],
      (hkVector4f *)faceIndex,
      &curFaceKey,
      (int *)&rightTurnRadius,
      (bool *)&leftTurnRadius,
      edgeIdx);
  if ( v11->m_outputParameters.m_status.m_storage == 1 )
  {
    v20 = v11->m_outputParameters.m_goalIndex;
    v21 = v26->m_goalFaceKeys.m_data[v20];
    _mm_store_si128((__m128i *)&b, (__m128i)v26->m_goalPoints.m_data[v20].m_quad);
    hkaiGeneralAccessor::setSection(v9, v21 >> 22);
    hkVector4f::setTransformedInversePos(&v23, &v9->m_accessor->m_referenceFrame.m_transform, &b);
    v23.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&v23), 4), 4);
    v22 = hkaiEdgePath::expandEdges(v10, 1);
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
_BOOL8 __fastcall hkaiEdgePath::updateTraversalState(hkaiEdgePath *this, hkaiEdgePath::TraversalState *traversalStateInOut, hkVector4f *newPositionLocal, unsigned int newFaceKey, bool repairPath, float userEdgeTolerance, hkaiStreamingCollection *streamingCollection, hkaiNavMeshCutter *cutter)
{
  hkaiEdgePath::Edge *v8; // rbx
  __int64 v9; // r13
  unsigned int v10; // esi
  hkVector4f *v11; // r12
  hkaiEdgePath::TraversalState *v12; // r15
  __int64 v14; // rdi
  signed int v15; // er14
  int v16; // ebp
  unsigned int v17; // esi
  bool v18; // zf
  __m128 v19; // xmm6
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm6
  __m128 v30; // xmm6
  int v31; // er9
  __int64 v32; // r8
  signed __int64 v33; // rdx
  __m128 v34; // xmm6
  signed __int64 v35; // rsi
  signed __int64 v36; // r12
  __m128 *v37; // rbx
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm0
  __m128 v41; // xmm2
  __m128 v42; // xmm2
  hkVector4f p; // [rsp+20h] [rbp-58h]
  hkaiPersistentFaceKey persistentFaceKeyOut; // [rsp+80h] [rbp+8h]

  v8 = this->m_edges.m_data;
  v9 = this->m_edges.m_size;
  v10 = newFaceKey;
  v11 = newPositionLocal;
  v12 = traversalStateInOut;
  if ( newFaceKey == -1 )
  {
    hkaiEdgePath::updateTraversalStateNaive(this, traversalStateInOut, newPositionLocal);
    return 1i64;
  }
  hkaiNavMeshCutter::makePersistentFaceKey(cutter, newFaceKey, &persistentFaceKeyOut);
  v14 = v12->m_faceEdge;
  v15 = v12->m_highestUserEdgeCrossed;
  v16 = v12->m_trailingEdge;
  v17 = v10 >> 22;
  if ( (_DWORD)v14 == -1
    || v8[v14].m_edge.m_faceKey.m_key != persistentFaceKeyOut.m_key
    || v8[v14].m_edge.m_faceKey.m_offset != persistentFaceKeyOut.m_offset )
  {
    if ( (signed int)v14 >= (signed int)v9 - 1
      || v8[(signed int)v14 + 1].m_edge.m_faceKey.m_key != persistentFaceKeyOut.m_key
      || v8[(signed int)v14 + 1].m_edge.m_faceKey.m_offset != persistentFaceKeyOut.m_offset )
    {
      v31 = v15 + 1;
      v32 = v15 + 1;
      if ( v32 == v9 )
      {
LABEL_21:
        if ( repairPath )
        {
          LODWORD(v14) = -1;
          goto LABEL_32;
        }
      }
      else
      {
        v33 = (signed __int64)&v8[v31].m_edge;
        while ( *(_DWORD *)v33 != persistentFaceKeyOut.m_key || *(_WORD *)(v33 + 4) != persistentFaceKeyOut.m_offset )
        {
          ++v32;
          ++v31;
          v33 += 144i64;
          if ( v32 == v9 )
            goto LABEL_21;
        }
        LODWORD(v14) = v31;
      }
    }
    else
    {
      LODWORD(v14) = v14 + 1;
    }
  }
  if ( (_DWORD)v14 != -1 )
  {
    v18 = v15 == (_DWORD)v14;
    if ( v15 < (signed int)v14 )
    {
      if ( v8[(signed int)v14].m_flags.m_storage & 0x10 )
      {
        if ( v17 == v8[(signed int)v14].m_edge.m_faceKey.m_key >> 22 )
        {
          v19 = v8[(signed int)v14].m_left.m_quad;
          v20 = v19;
          v21 = _mm_sub_ps(v19, v11->m_quad);
          v22 = _mm_sub_ps(v20, v8[(signed int)v14].m_right.m_quad);
          v23 = _mm_mul_ps(v22, v22);
          v24 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                  _mm_shuffle_ps(v23, v23, 170));
          v25 = _mm_mul_ps(v21, v22);
          v26 = _mm_rcp_ps(v24);
          v27 = _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
                    _mm_shuffle_ps(v25, v25, 170)),
                  _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v24, v26)), v26));
          v28 = _mm_cmpltps(v27, query.m_quad);
          v29 = _mm_sub_ps(
                  v21,
                  _mm_mul_ps(
                    _mm_max_ps((__m128)0i64, _mm_or_ps(_mm_and_ps(v27, v28), _mm_andnot_ps(v28, query.m_quad))),
                    v22));
          v30 = _mm_mul_ps(v29, v29);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v30, v30, 170))) < (float)(userEdgeTolerance * userEdgeTolerance) )
          {
            v15 = v14;
            v16 = v14 + 1;
            goto LABEL_32;
          }
        }
      }
      v18 = v15 == (_DWORD)v14;
    }
    if ( v18 )
    {
      v16 = v15 + 1;
    }
    else
    {
      v34 = v11->m_quad;
      v35 = (signed int)v14;
      v36 = v15 + 1;
      v16 = v14;
      if ( (signed int)v14 > v36 )
      {
        v37 = &v8[(signed int)v14 - 1].m_followingTransform.m_col1.m_quad;
        do
        {
          v34 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v37[-1]), v37[2]),
                    _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), *v37)),
                  _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v37[1]));
          v38 = v37[-4];
          v39 = _mm_sub_ps(v37[-3], v34);
          p.m_quad = v34;
          v40 = _mm_sub_ps(v38, v34);
          v41 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v40, v40, 201), v39),
                  _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v40));
          v42 = _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v37[-2]);
          if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 0)))
                     + COERCE_FLOAT(_mm_shuffle_ps(v42, v42, 170))) > 0.0 )
            break;
          if ( !hkaiEdgePathSteeringUtil::inCapsule(
                  &p,
                  (hkVector4f *)&v37[-4],
                  (hkVector4f *)&v37[-3],
                  (hkVector4f *)&v37[-2]) )
            break;
          --v35;
          --v16;
          v37 -= 9;
        }
        while ( v35 > v36 );
      }
    }
  }
LABEL_32:
  v12->m_faceEdge = v14;
  v12->m_trailingEdge = v16;
  v12->m_highestUserEdgeCrossed = v15;
  return (signed int)v14 >= 0;
}

// File Line: 270
// RVA: 0xBEB0D0
void __fastcall hkaiEdgePath::getFutureEdgeRange(hkaiEdgePath *this, hkaiEdgePath::TraversalState *traversalState, hkaiEdgePath::Edge **begin, hkaiEdgePath::Edge **end)
{
  *begin = &this->m_edges.m_data[traversalState->m_trailingEdge];
  *end = &this->m_edges.m_data[this->m_edges.m_size];
}

// File Line: 277
// RVA: 0xBEB100
void __fastcall hkaiEdgePath::getFutureEdgeRange(hkaiEdgePath *this, int offset, hkaiEdgePath::Edge **begin, hkaiEdgePath::Edge **end)
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
  int v4; // er9
  int v5; // esi
  hkaiEdgePath *v6; // rbp
  int v7; // eax
  __int64 v8; // rdi
  int v9; // er9
  int v10; // eax
  int v11; // eax
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = numNewEdges * this->m_edgeDataStriding;
  v3 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
  v4 = v2 + this->m_edgeData.m_size;
  v5 = numNewEdges;
  v6 = this;
  if ( v3 < v4 )
  {
    v7 = 2 * v3;
    if ( v4 < v7 )
      v4 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_edgeData,
      v4,
      4);
  }
  v6->m_edgeData.m_size += v2;
  v8 = v6->m_edges.m_size;
  v9 = v8 + v5;
  v10 = v6->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < (signed int)v8 + v5 )
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_edges, v9, 144);
  }
  v6->m_edges.m_size += v5;
  return &v6->m_edges.m_data[v8];
}

// File Line: 289
// RVA: 0xBEAA70
hkaiEdgePath::Edge *__fastcall hkaiEdgePath::expandEdges(hkaiEdgePath *this, int numNewEdges, int **edgeDataPtrOut)
{
  __int64 v3; // r14
  int v4; // esi
  int v5; // er9
  int v6; // eax
  int **v7; // r15
  int v8; // edi
  hkaiEdgePath *v9; // rbp
  int v10; // eax
  __int64 v11; // rsi
  int v12; // er9
  int v13; // eax
  int v14; // eax
  hkResult result; // [rsp+58h] [rbp+10h]

  v3 = this->m_edgeData.m_size;
  v4 = numNewEdges * this->m_edgeDataStriding;
  v5 = v3 + v4;
  v6 = this->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = edgeDataPtrOut;
  v8 = numNewEdges;
  v9 = this;
  if ( v6 < (signed int)v3 + v4 )
  {
    v10 = 2 * v6;
    if ( v5 < v10 )
      v5 = v10;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_edgeData,
      v5,
      4);
  }
  v9->m_edgeData.m_size += v4;
  *v7 = &v9->m_edgeData.m_data[v3];
  v11 = v9->m_edges.m_size;
  v12 = v11 + v8;
  v13 = v9->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < (signed int)v11 + v8 )
  {
    v14 = 2 * v13;
    if ( v12 < v14 )
      v12 = v14;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v9->m_edges,
      v12,
      144);
  }
  v9->m_edges.m_size += v8;
  return &v9->m_edges.m_data[v11];
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
void __fastcall hkaiEdgePath::getEdgePointsInGlobalSpace(hkaiEdgePath *this, int edgeIdx, hkaiStreamingCollection *streamingCollection, hkVector4f *leftGlobal, hkVector4f *rightGlobal)
{
  hkaiEdgePath::getEdgePointsInGlobalSpace(&this->m_edges.m_data[edgeIdx], streamingCollection, leftGlobal, rightGlobal);
}

// File Line: 318
// RVA: 0xBEABC0
void __fastcall hkaiEdgePath::getEdgePointsInGlobalSpace(hkaiEdgePath::Edge *edge, hkaiStreamingCollection *streamingCollection, hkVector4f *leftGlobal, hkVector4f *rightGlobal)
{
  hkaiEdgePath::Edge *v4; // rbx
  hkVector4f *v5; // rdi
  hkaiNavMeshInstance *v6; // rdx
  hkTransformf a; // [rsp+20h] [rbp-48h]

  v4 = edge;
  v5 = rightGlobal;
  v6 = streamingCollection->m_instances.m_data[edge->m_edge.m_faceKey.m_key >> 22].m_instancePtr;
  a.m_rotation.m_col0 = v6->m_referenceFrame.m_transform.m_rotation.m_col0;
  a.m_rotation.m_col1 = v6->m_referenceFrame.m_transform.m_rotation.m_col1;
  a.m_rotation.m_col2 = v6->m_referenceFrame.m_transform.m_rotation.m_col2;
  a.m_translation = v6->m_referenceFrame.m_transform.m_translation;
  hkVector4f::setTransformedPos(leftGlobal, &a, &edge->m_left);
  hkVector4f::setTransformedPos(v5, &a, &v4->m_right);
}

// File Line: 333
// RVA: 0xBEB010
void __fastcall hkaiEdgePath::updateTraversalStateNaive(hkaiEdgePath *this, hkaiEdgePath::TraversalState *traversalState, hkVector4f *newPositionGlobal)
{
  signed __int64 v3; // r10
  int v4; // er9
  signed __int64 v5; // rax
  __m128 v6; // xmm3
  hkaiEdgePath::Edge *v7; // rcx
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  int v12; // eax

  v3 = traversalState->m_trailingEdge;
  v4 = this->m_edges.m_size - 1;
  v5 = v3;
  if ( v3 < v4 )
  {
    v6 = newPositionGlobal->m_quad;
    v7 = &this->m_edges.m_data[v3];
    do
    {
      v8 = _mm_sub_ps(v7->m_right.m_quad, v6);
      v9 = _mm_sub_ps(v7->m_left.m_quad, v6);
      v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9));
      v11 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v7->m_up.m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v11, v11, 170))) >= 0.0 )
        break;
      ++v5;
      LODWORD(v3) = v3 + 1;
      ++v7;
    }
    while ( v5 < v4 );
  }
  v12 = v3 - 1;
  if ( (signed int)v3 - 1 < 0 )
    v12 = 0;
  traversalState->m_trailingEdge = v12;
}

// File Line: 357
// RVA: 0xBEB130
signed __int64 __fastcall hkaiEdgePath::getGoal(hkaiEdgePath *this, int *goalSectionOut, hkVector4f *goalOut)
{
  int *v3; // r10
  hkaiEdgePath::Edge *v4; // rdx
  unsigned int v5; // eax
  signed int v6; // eax
  signed __int64 result; // rax

  v3 = goalSectionOut;
  if ( !this->m_edges.m_size )
    return 0i64;
  v4 = &this->m_edges.m_data[this->m_edges.m_size];
  if ( _mm_movemask_ps(_mm_cmpeqps(v4[-1].m_right.m_quad, v4[-1].m_left.m_quad)) != 15 )
    return 0i64;
  v5 = v4[-1].m_edge.m_faceKey.m_key;
  if ( v5 == -1 )
    v6 = -1;
  else
    v6 = v5 >> 22;
  *v3 = v6;
  result = 1i64;
  *goalOut = v4[-1].m_left;
  return result;
}

// File Line: 379
// RVA: 0xBEB190
_BOOL8 __fastcall hkaiEdgePath::hasGoal(hkaiEdgePath *this)
{
  _BOOL8 result; // rax

  if ( this->m_edges.m_size )
    result = _mm_movemask_ps(
               _mm_cmpeqps(
                 *((__m128 *)&this->m_edges.m_data[this->m_edges.m_size] - 8),
                 this->m_edges.m_data[this->m_edges.m_size - 1].m_left.m_quad)) == 15;
  else
    result = 0i64;
  return result;
}

// File Line: 396
// RVA: 0xBEB2C0
void __fastcall hkaiEdgePath::calcWallClimbingTransform(hkVector4f *leftPoint, hkVector4f *curUp, hkVector4f *newUp, hkMatrix4f *transformOut)
{
  __m128 v4; // xmm7
  hkVector4f *v5; // rbx
  hkMatrix4f *v6; // rdi
  __m128 v7; // xmm9
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  __m128 v10; // xmm8
  __m128 v11; // xmm8
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm2
  __m128 v18; // xmm0
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128i v21; // xmm4
  __m128i v22; // xmm2
  __m128 v23; // xmm5
  hkMatrix3f aTb; // [rsp+20h] [rbp-D8h]
  hkMatrix3f bTc; // [rsp+50h] [rbp-A8h]
  __m128 v26; // [rsp+80h] [rbp-78h]
  __m128 v27; // [rsp+90h] [rbp-68h]
  __m128 v28; // [rsp+A0h] [rbp-58h]

  v4 = curUp->m_quad;
  v5 = leftPoint;
  v6 = transformOut;
  v7 = newUp->m_quad;
  v8 = _mm_shuffle_ps(v4, v4, 201);
  v9 = _mm_shuffle_ps(v7, v7, 201);
  aTb.m_col2 = (hkVector4f)curUp->m_quad;
  v10 = _mm_sub_ps(_mm_mul_ps(v7, v8), _mm_mul_ps(v9, v4));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  aTb.m_col0.m_quad = _mm_mul_ps(
                        v11,
                        _mm_andnot_ps(
                          _mm_cmpleps(v13, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
                            _mm_mul_ps(*(__m128 *)_xmm, v14))));
  v15 = _mm_shuffle_ps(aTb.m_col0.m_quad, aTb.m_col0.m_quad, 201);
  v16 = v15;
  v17 = _mm_sub_ps(_mm_mul_ps(v15, v7), _mm_mul_ps(v9, aTb.m_col0.m_quad));
  v18 = _mm_sub_ps(_mm_mul_ps(v16, v4), _mm_mul_ps(v8, aTb.m_col0.m_quad));
  v19 = _mm_shuffle_ps(v17, v17, 201);
  v20 = _mm_unpacklo_ps(aTb.m_col0.m_quad, v19);
  aTb.m_col1.m_quad = _mm_shuffle_ps(v18, v18, 201);
  bTc.m_col0.m_quad = _mm_movelh_ps(v20, v7);
  bTc.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(aTb.m_col0.m_quad, v19), v7, 228);
  bTc.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(bTc.m_col0.m_quad, v20), v7, 212);
  hkMatrix3f::setMul((hkMatrix3f *)&v26, &aTb, &bTc);
  v21 = (__m128i)v27;
  v22 = (__m128i)v26;
  v23 = _mm_sub_ps(
          v5->m_quad,
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v5->m_quad, v5->m_quad, 85), v27),
              _mm_mul_ps(_mm_shuffle_ps(v5->m_quad, v5->m_quad, 0), v26)),
            _mm_mul_ps(_mm_shuffle_ps(v5->m_quad, v5->m_quad, 170), v28)));
  v6->m_col2.m_quad = v28;
  v6->m_col0 = (hkVector4f)v22;
  v6->m_col3.m_quad = v23;
  v6->m_col1 = (hkVector4f)v21;
  _mm_store_si128((__m128i *)v6, _mm_srli_si128(_mm_slli_si128(v22, 4), 4));
  _mm_store_si128(
    (__m128i *)&v6->m_col2,
    _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&v6->m_col2), 4), 4));
  _mm_store_si128((__m128i *)&v6->m_col1, _mm_srli_si128(_mm_slli_si128(v21, 4), 4));
  v6->m_col3.m_quad = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, query.m_quad), 196);
}

// File Line: 442
// RVA: 0xBEB4B0
void __fastcall hkaiEdgePath::calcFollowingTransform(hkVector4f *curLeftPoint, hkVector4f *curRightPoint, hkVector4f *curUp, hkVector4f *newLeftPoint, hkVector4f *newRightPoint, hkVector4f *newUp, hkMatrix4f *followingTransform)
{
  hkVector4f *v7; // rbx
  hkVector4f *v8; // rdi
  __m128 v9; // xmm6
  __m128 v10; // xmm12
  __m128 v11; // xmm13
  __m128 v12; // xmm1
  __m128 v13; // xmm13
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128 v17; // xmm7
  __m128 v18; // xmm13
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
  __m128i v45; // xmm4
  hkVector4f v46; // xmm0
  hkVector4f v47; // xmm5
  __m128i v48; // xmm0
  hkSimdFloat32 scale; // [rsp+20h] [rbp-128h]
  hkMatrix3f v50; // [rsp+30h] [rbp-118h]
  hkMatrix3f bTc; // [rsp+60h] [rbp-E8h]
  __m128 v52; // [rsp+90h] [rbp-B8h]
  __m128 v53; // [rsp+A0h] [rbp-A8h]
  __m128 v54; // [rsp+B0h] [rbp-98h]

  v7 = newLeftPoint;
  v8 = curLeftPoint;
  v9 = _mm_sub_ps(newRightPoint->m_quad, newLeftPoint->m_quad);
  v10 = curUp->m_quad;
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
          _mm_cmpleps(v15, (__m128)0i64),
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v16, v15), v16)), _mm_mul_ps(v16, *(__m128 *)_xmm)));
  v18 = _mm_mul_ps(v13, v17);
  v19 = _mm_mul_ps(v17, v15);
  v20 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), curUp->m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v18));
  v21 = _mm_shuffle_ps(v20, v20, 201);
  v22 = _mm_mul_ps(v21, v21);
  v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)), _mm_shuffle_ps(v22, v22, 170));
  v24 = _mm_rsqrt_ps(v23);
  v52 = v18;
  v25 = newUp->m_quad;
  v53 = _mm_mul_ps(
          v21,
          _mm_andnot_ps(
            _mm_cmpleps(v23, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v24, v23), v24)),
              _mm_mul_ps(v24, *(__m128 *)_xmm))));
  v54 = v10;
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
          _mm_cmpleps(v29, (__m128)0i64),
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
            _mm_cmpleps(v38, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
              _mm_mul_ps(v39, *(__m128 *)_xmm))),
          v36);
  v41 = _mm_unpacklo_ps(v32, v40);
  bTc.m_col0.m_quad = _mm_movelh_ps(v41, v25);
  bTc.m_col2.m_quad = _mm_shuffle_ps(_mm_unpackhi_ps(v32, v40), v25, 228);
  bTc.m_col1.m_quad = _mm_shuffle_ps(_mm_movehl_ps(bTc.m_col0.m_quad, v41), v25, 212);
  hkMatrix3f::setMul(&v50, (hkMatrix3f *)&v52, &bTc);
  hkMatrix3f::mul(&v50, &scale);
  v42 = v7->m_quad;
  v43 = v8->m_quad;
  v44.m_quad = (__m128)v50.m_col0;
  v45 = (__m128i)v50.m_col1;
  followingTransform->m_col0 = v50.m_col0;
  followingTransform->m_col1 = (hkVector4f)v45;
  v46.m_quad = (__m128)v50.m_col2;
  followingTransform->m_col2 = v50.m_col2;
  v47.m_quad = _mm_sub_ps(
                 v43,
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), (__m128)v45),
                     _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), v44.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), v46.m_quad)));
  _mm_store_si128((__m128i *)followingTransform, _mm_srli_si128(_mm_slli_si128((__m128i)v44.m_quad, 4), 4));
  v48 = _mm_load_si128((const __m128i *)&followingTransform->m_col2);
  _mm_store_si128((__m128i *)&followingTransform->m_col1, _mm_srli_si128(_mm_slli_si128(v45, 4), 4));
  followingTransform->m_col3 = (hkVector4f)v47.m_quad;
  _mm_store_si128((__m128i *)&followingTransform->m_col2, _mm_srli_si128(_mm_slli_si128(v48, 4), 4));
  followingTransform->m_col3.m_quad = _mm_shuffle_ps(v47.m_quad, _mm_unpackhi_ps(v47.m_quad, query.m_quad), 196);
}

// File Line: 501
// RVA: 0xBEC040
void __usercall hkaiEdgePath::replacePrefixWithEdge(hkaiEdgePath *this@<rcx>, int numToRemove@<edx>, unsigned int edgeFaceKey@<r8d>, unsigned int edgeKey@<r9d>, __m128 *a5@<xmm13>, hkaiStreamingCollection *streamingCollection, hkaiNavMeshCutter *cutter)
{
  int v7; // esi
  hkaiEdgePath *v8; // rdi
  unsigned int v9; // er15
  unsigned int v10; // ebx
  int v11; // er14
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // er9
  __int64 v16; // rbp
  int v17; // er14
  int v18; // ebx
  int v19; // eax
  int v20; // eax
  int v21; // er9
  int curSection; // [rsp+50h] [rbp-78h]
  int faceIndex; // [rsp+60h] [rbp-68h]
  char v24; // [rsp+70h] [rbp-58h]
  hkSimdFloat32 *result; // [rsp+80h] [rbp-48h]
  int v26; // [rsp+88h] [rbp-40h]
  hkaiStreamingCollection::InstanceInfo *v27; // [rsp+90h] [rbp-38h]
  bool curSectionIsWC; // [rsp+D8h] [rbp+10h]
  unsigned int curFaceKey; // [rsp+E0h] [rbp+18h]

  curFaceKey = edgeFaceKey;
  v7 = numToRemove;
  v8 = this;
  v9 = edgeKey;
  v27 = streamingCollection->m_instances.m_data;
  v10 = edgeFaceKey;
  v26 = -1;
  result = 0i64;
  curSection = edgeFaceKey >> 22;
  hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)&result, edgeFaceKey >> 22);
  hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)&v24,
    result,
    (hkaiNavMeshInstance *)(v10 & 0x3FFFFF),
    (__int64)&faceIndex);
  curSectionIsWC = *(_BYTE *)(result[6].m_real.m128_u64[0] + 120) & 1;
  if ( v7 )
  {
    if ( v7 != 1 )
    {
      hkArrayBase<hkaiEdgePath::Edge>::_spliceInto(
        (hkArrayBase<hkaiEdgePath::Edge> *)&v8->m_edges.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        0,
        v7 - 1,
        0i64,
        0);
      hkArrayBase<unsigned int>::_spliceInto(
        (hkArrayBase<unsigned int> *)&v8->m_edgeData,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        0,
        (v7 - 1) * v8->m_edgeDataStriding,
        0i64,
        0);
    }
  }
  else
  {
    v11 = v8->m_edges.m_size;
    v12 = v8->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    v13 = v11 + 1;
    if ( v11 + 1 > v12 )
    {
      if ( v12 >= v13 )
      {
        LODWORD(streamingCollection) = 0;
      }
      else
      {
        v14 = 2 * v12;
        v15 = v11 + 1;
        if ( v13 < v14 )
          v15 = v14;
        hkArrayUtil::_reserve(
          (hkResult *)&streamingCollection,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v8->m_edges,
          v15,
          144);
      }
    }
    hkMemUtil::memMove(&v8->m_edges.m_data[1], v8->m_edges.m_data, 144 * v11);
    v8->m_edges.m_size = v13;
    v16 = v8->m_edgeDataStriding;
    v17 = v8->m_edgeData.m_size;
    v18 = v17 + v16;
    v19 = v8->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v17 + (signed int)v16 > v19 )
    {
      if ( v19 >= v18 )
      {
        LODWORD(streamingCollection) = 0;
      }
      else
      {
        v20 = 2 * v19;
        v21 = v17 + v16;
        if ( v18 < v20 )
          v21 = v20;
        hkArrayUtil::_reserve(
          (hkResult *)&streamingCollection,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v8->m_edgeData,
          v21,
          4);
      }
    }
    hkMemUtil::memMove(&v8->m_edgeData.m_data[v16], v8->m_edgeData.m_data, 4 * v17);
    v8->m_edgeData.m_size = v18;
  }
  hkaiEdgePath::buildEdge(
    v8,
    (hkaiGeneralAccessor *)&result,
    cutter,
    v9,
    a5,
    (hkVector4f *)&faceIndex,
    &curFaceKey,
    &curSection,
    &curSectionIsWC,
    0);
}

// File Line: 546
// RVA: 0xBEC930
__int64 __fastcall `anonymous namespace'::moveCwInFace(hkaiGeneralAccessor *accessor, unsigned int *edgeKey, unsigned int faceKey)
{
  unsigned int v3; // ebx
  unsigned int *v4; // rdi
  hkaiNavMesh::Face *v5; // rax
  int v6; // ecx
  int v7; // ecx
  __int64 result; // rax

  v3 = *edgeKey;
  v4 = edgeKey;
  v5 = hkaiGeneralAccessor::getFaceFromPacked(accessor, faceKey);
  v6 = *v4 & 0x3FFFFF;
  if ( v6 == v5->m_startEdgeIndex )
    v7 = v5->m_numEdges + v5->m_startEdgeIndex - 1;
  else
    v7 = v6 - 1;
  result = 0i64;
  *v4 = v7 | v3 & 0xFFC00000;
  return result;
}

// File Line: 568
// RVA: 0xBEC980
__int64 __fastcall `anonymous namespace'::moveCcwInFace(hkaiGeneralAccessor *accessor, unsigned int *edgeKey, unsigned int faceKey)
{
  unsigned int v3; // ebx
  unsigned int *v4; // rdi
  hkaiNavMesh::Face *v5; // rax
  int v6; // er8
  int v7; // er9
  __int64 result; // rax

  v3 = *edgeKey;
  v4 = edgeKey;
  v5 = hkaiGeneralAccessor::getFaceFromPacked(accessor, faceKey);
  v6 = v5->m_startEdgeIndex;
  v7 = *v4 & 0x3FFFFF;
  if ( v7 != v5->m_numEdges + v5->m_startEdgeIndex - 1 )
    v6 = v7 + 1;
  result = 0i64;
  *v4 = v6 | v3 & 0xFFC00000;
  return result;
}

// File Line: 590
// RVA: 0xBEC9E0
__int64 __fastcall `anonymous namespace'::moveCwAroundVertex(hkaiGeneralAccessor *accessor, unsigned int *edgeKey, unsigned int *faceKey)
{
  unsigned int *v3; // rdi
  unsigned int *v4; // rsi
  hkaiGeneralAccessor *v5; // rbx
  hkaiNavMesh::Edge *v6; // rax
  hkaiNavMesh::Edge *v7; // r9
  char v8; // al
  unsigned int v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  __int64 result; // rax

  v3 = edgeKey;
  v4 = faceKey;
  v5 = accessor;
  v6 = hkaiGeneralAccessor::getEdgeFromPacked(accessor, *edgeKey);
  v7 = v6;
  if ( v6->m_oppositeEdge == -1 || (v8 = v6->m_flags.m_storage, v8 & 0x20) )
  {
    *v3 = -1;
    *v4 = -1;
    result = (unsigned int)((v7->m_flags.m_storage & 0x40) != 0) + 1;
  }
  else
  {
    v9 = v7->m_oppositeFace;
    if ( v8 & 0x40 )
      v10 = v9 & 0xFFC00000;
    else
      v10 = v5->m_accessor->m_runtimeId << 22;
    v11 = v10 | v9 & 0x3FFFFF;
    if ( v9 == -1 )
      v11 = -1;
    *v4 = v11;
    v12 = v7->m_oppositeEdge;
    if ( v7->m_flags.m_storage & 0x40 )
      v13 = v12 & 0xFFC00000;
    else
      v13 = v5->m_accessor->m_runtimeId << 22;
    v14 = v13 | v12 & 0x3FFFFF;
    if ( v12 == -1 )
      v14 = -1;
    *v3 = v14;
    `anonymous namespace'::moveCcwInFace(v5, v3, *v4);
    result = 0i64;
  }
  return result;
}

// File Line: 617
// RVA: 0xBECAD0
signed __int64 __fastcall `anonymous namespace'::moveCcwAroundVertex(hkaiGeneralAccessor *accessor, unsigned int *edgeKey, unsigned int *faceKey)
{
  unsigned int *v3; // rdi
  unsigned int *v4; // rsi
  hkaiGeneralAccessor *v5; // rbx
  hkaiNavMesh::Edge *v6; // rax
  hkaiNavMesh::Edge *v7; // r9
  char v8; // al
  unsigned int v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  signed __int64 result; // rax

  v3 = edgeKey;
  v4 = faceKey;
  v5 = accessor;
  v6 = hkaiGeneralAccessor::getEdgeFromPacked(accessor, *edgeKey);
  v7 = v6;
  if ( v6->m_oppositeEdge == -1 || (v8 = v6->m_flags.m_storage, v8 & 0x20) )
  {
    *v3 = -1;
    *v4 = -1;
    result = 1i64;
  }
  else
  {
    v9 = v7->m_oppositeFace;
    if ( v8 & 0x40 )
      v10 = v9 & 0xFFC00000;
    else
      v10 = v5->m_accessor->m_runtimeId << 22;
    v11 = v10 | v9 & 0x3FFFFF;
    if ( v9 == -1 )
      v11 = -1;
    *v4 = v11;
    v12 = v7->m_oppositeEdge;
    if ( v7->m_flags.m_storage & 0x40 )
      v13 = v12 & 0xFFC00000;
    else
      v13 = v5->m_accessor->m_runtimeId << 22;
    v14 = v13 | v12 & 0x3FFFFF;
    if ( v12 == -1 )
      v14 = -1;
    *v3 = v14;
    `anonymous namespace'::moveCwInFace(v5, v3, *v4);
    result = 0i64;
  }
  return result;
}

// File Line: 642
// RVA: 0xBEC280
signed __int64 __usercall hkaiEdgePath::pullPastInternalVertex@<rax>(hkaiEdgePath *this@<rcx>, int edgeIndex@<edx>, bool isLeft@<r8b>, hkaiEdgePath::TraversalState *curTraversalState@<r9>, __m128 *a5@<xmm13>, hkaiStreamingCollection *streamingCollection, hkaiNavMeshCutter *cutter)
{
  hkaiStreamingCollection *v7; // rsi
  hkaiNavMeshCutter *v8; // r13
  int v9; // er12
  bool v10; // r15
  hkaiEdgePath *v11; // rbx
  int v12; // eax
  int v13; // eax
  int v14; // er14
  int v15; // edi
  int v16; // edi
  bool v17; // zf
  hkaiEdgePath::Edge *v19; // rax
  unsigned int v20; // esi
  int v21; // edi
  hkaiEdgePath::Edge *v22; // rax
  unsigned int v23; // eax
  int v24; // er12
  MoveResult v25; // eax
  MoveResult v26; // eax
  hkResultEnum v27; // esi
  __m128i v28; // xmm6
  int v29; // edi
  int v30; // edx
  int v31; // edi
  int v32; // edx
  int v33; // eax
  int v34; // eax
  int v35; // er9
  int v36; // eax
  int v37; // edx
  int v38; // ecx
  hkResultEnum v39; // eax
  signed int v40; // edi
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int v44; // er9
  int v45; // er12
  unsigned int edgeIdx; // edi
  __int64 v47; // rdx
  __int64 v48; // rcx
  unsigned int curFaceKey; // [rsp+50h] [rbp-39h]
  int curSection; // [rsp+54h] [rbp-35h]
  hkVector4f curUp; // [rsp+60h] [rbp-29h]
  hkaiGeneralAccessor accessor; // [rsp+70h] [rbp-19h]
  unsigned int faceKey; // [rsp+E0h] [rbp+57h]
  unsigned int edgeKey; // [rsp+E8h] [rbp+5Fh]
  hkResult result; // [rsp+F8h] [rbp+6Fh]

  edgeKey = edgeIndex;
  v7 = streamingCollection;
  v8 = cutter;
  v9 = 1;
  v10 = isLeft;
  v11 = this;
  accessor.m_sectionInfo = streamingCollection->m_instances.m_data;
  v12 = curTraversalState->m_faceEdge;
  accessor.m_currentSection = -1;
  v13 = v12 + 1;
  accessor.m_accessor = 0i64;
  v14 = edgeIndex;
  if ( v13 > 1 )
    v9 = v13;
  if ( edgeIndex >= v9 )
  {
    do
    {
      v15 = v14 - 1;
      if ( !hkaiEdgePath::consecutiveEdgesShareVertex(v11, v14 - 1, v10, v7, v8) )
        break;
      --v14;
    }
    while ( v15 >= v9 );
    edgeIndex = edgeKey;
  }
  v16 = edgeIndex + 1;
  v17 = edgeIndex + 1 == v11->m_edges.m_size;
  if ( edgeIndex + 1 < v11->m_edges.m_size )
  {
    do
    {
      if ( !hkaiEdgePath::consecutiveEdgesShareVertex(v11, v16 - 1, v10, v7, v8) )
        break;
      ++v16;
    }
    while ( v16 < v11->m_edges.m_size );
    v17 = v16 == v11->m_edges.m_size;
  }
  if ( v17 )
    return 1i64;
  v19 = hkaiEdgePath::getEdge(v11, v16);
  v20 = hkaiNavMeshCutter::resolvePersistentFaceKey(v8, &v19->m_edge.m_faceKey);
  curFaceKey = v20;
  if ( v20 == -1 )
    return 2i64;
  v21 = v16 - v14;
  v22 = hkaiEdgePath::getEdge(v11, v14);
  curUp.m_quad.m128_u64[0] = (unsigned __int64)v22;
  v23 = hkaiEdgePathSteeringUtil::resolveEdgeToKey(v22, &accessor, v8, (unsigned int *)&streamingCollection);
  curSection = v23;
  if ( v23 == -1 )
    return 2i64;
  edgeKey = v23;
  v24 = 0;
  result.m_enum = (signed int)streamingCollection;
  faceKey = (unsigned int)streamingCollection;
  v25 = v10 ? `anonymous namespace'::moveCcwInFace(&accessor, &edgeKey, (unsigned int)streamingCollection) : `anonymous namespace'::moveCwInFace(&accessor, &edgeKey, (unsigned int)streamingCollection);
  if ( v25 )
    return 2i64;
  if ( result.m_enum != v20 )
  {
    while ( 1 )
    {
      ++v24;
      v26 = v10 ? `anonymous namespace'::moveCwAroundVertex(&accessor, &edgeKey, &faceKey) : `anonymous namespace'::moveCcwAroundVertex(
                                                                                               &accessor,
                                                                                               &edgeKey,
                                                                                               &faceKey);
      if ( v26 )
        return 2i64;
      v27 = (signed int)streamingCollection;
      if ( faceKey == (_DWORD)streamingCollection )
        return 2i64;
      if ( faceKey == curFaceKey )
        goto LABEL_29;
    }
  }
  v27 = (signed int)streamingCollection;
LABEL_29:
  v28 = *(__m128i *)(curUp.m_quad.m128_u64[0] + 32);
  if ( v24 < v21 )
  {
    v29 = v21 - v24;
    hkArrayBase<hkaiEdgePath::Edge>::_spliceInto(
      (hkArrayBase<hkaiEdgePath::Edge> *)&v11->m_edges.m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v14,
      v29,
      0i64,
      0);
    hkArrayBase<unsigned int>::_spliceInto(
      (hkArrayBase<unsigned int> *)&v11->m_edgeData,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v14 * v11->m_edgeDataStriding,
      v29 * v11->m_edgeDataStriding,
      0i64,
      0);
LABEL_45:
    v27 = (signed int)streamingCollection;
    goto LABEL_46;
  }
  if ( v24 > v21 )
  {
    v30 = v11->m_edges.m_size;
    edgeKey = v24 - v21;
    v31 = v30 + v24 - v21;
    v32 = v30 - v14;
    v33 = v11->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
    faceKey = v32;
    if ( v31 > v33 )
    {
      if ( v33 >= v31 )
      {
        result.m_enum = 0;
      }
      else
      {
        v34 = 2 * v33;
        v35 = v31;
        if ( v31 < v34 )
          v35 = v34;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v11->m_edges,
          v35,
          144);
        v32 = faceKey;
      }
    }
    hkMemUtil::memMove(
      &v11->m_edges.m_data[v14 + (signed __int64)(signed int)edgeKey],
      &v11->m_edges.m_data[v14],
      144 * v32);
    v11->m_edges.m_size = v31;
    v36 = v11->m_edgeDataStriding;
    v37 = v11->m_edgeData.m_size;
    v38 = v36;
    v39 = v14 * v36;
    result.m_enum = v39;
    curFaceKey = edgeKey * v38;
    v40 = v37 + edgeKey * v38;
    v41 = v37 - v39;
    v42 = v11->m_edgeData.m_capacityAndFlags & 0x3FFFFFFF;
    edgeKey = v41;
    if ( v40 > v42 )
    {
      if ( v42 >= v40 )
      {
        faceKey = 0;
      }
      else
      {
        v43 = 2 * v42;
        v44 = v40;
        if ( v40 < v43 )
          v44 = v43;
        hkArrayUtil::_reserve(
          (hkResult *)&faceKey,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v11->m_edgeData,
          v44,
          4);
        v41 = edgeKey;
      }
    }
    hkMemUtil::memMove(
      &v11->m_edgeData.m_data[(signed int)result.m_enum + (signed __int64)(signed int)curFaceKey],
      &v11->m_edgeData.m_data[result.m_enum],
      4 * v41);
    v11->m_edgeData.m_size = v40;
    goto LABEL_45;
  }
LABEL_46:
  _mm_store_si128((__m128i *)&curUp, v28);
  faceKey = curSection;
  result.m_enum = v27;
  curSection = (unsigned int)v27 >> 22;
  LOBYTE(edgeKey) = accessor.m_accessor->m_originalMesh.m_pntr->m_flags.m_storage & 1;
  if ( v10 )
    `anonymous namespace'::moveCcwInFace(&accessor, &faceKey, v27);
  else
    `anonymous namespace'::moveCwInFace(&accessor, &faceKey, v27);
  v45 = v14 + v24;
  edgeIdx = v14;
  if ( v14 != v45 )
  {
    while ( 1 )
    {
      curFaceKey = v27;
      hkaiEdgePath::buildEdge(
        v11,
        &accessor,
        v8,
        faceKey,
        a5,
        &curUp,
        &curFaceKey,
        &curSection,
        (bool *)&edgeKey,
        edgeIdx);
      if ( v10 )
        `anonymous namespace'::moveCwAroundVertex(&accessor, &faceKey, (unsigned int *)&result);
      else
        `anonymous namespace'::moveCcwAroundVertex(&accessor, &faceKey, (unsigned int *)&result);
      if ( ++edgeIdx == v45 )
        break;
      v27 = result.m_enum;
    }
  }
  v47 = v14;
  if ( v14 )
  {
    v48 = 0i64;
    do
    {
      ++v48;
      *((_WORD *)&v11->m_edges.m_data[v48] - 10) = 0;
      *((_WORD *)&v11->m_edges.m_data[v48] - 9) = 0;
      --v47;
    }
    while ( v47 );
  }
  return 0i64;
}

// File Line: 858
// RVA: 0xBEB840
void __usercall hkaiEdgePath::buildEdge(hkaiEdgePath *this@<rcx>, hkaiGeneralAccessor *accessor@<rdx>, hkaiNavMeshCutter *cutter@<r8>, unsigned int edgeKey@<r9d>, __m128 a5@<xmm13>, hkVector4f *curUp, unsigned int *curFaceKey, int *curSection, bool *curSectionIsWC, unsigned int edgeIdx)
{
  hkArray<int,hkContainerHeapAllocator> **v10; // rsi
  unsigned int v11; // ebx
  __m128 v12; // xmm7
  hkaiEdgePath::Edge *v13; // rdi
  __m128 v14; // xmm8
  __m128 v15; // xmm12
  hkaiNavMesh::Edge *v16; // rax
  hkArray<int,hkContainerHeapAllocator> *v17; // rcx
  hkaiNavMesh::Edge *v18; // r14
  unsigned int v19; // edx
  __m128 v20; // xmm13
  char v21; // r8
  int v22; // er12
  unsigned int v23; // eax
  int v24; // er15
  bool v25; // zf
  unsigned int v26; // edx
  unsigned int v27; // eax
  int v28; // er13
  __int64 v29; // rax
  signed int v30; // edx
  __m128 *v31; // rax
  __m128 v32; // xmm9
  __int64 v33; // rax
  __m128 *v34; // rax
  __m128 v35; // xmm10
  unsigned int v36; // edx
  hkaiNavMesh::Face *v37; // rax
  int index; // ebx
  unsigned int v39; // ST40_4
  __m128 v40; // xmm6
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm13
  __m128 v46; // xmm1
  __m128 v47; // xmm1
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
  char v70; // bl
  hkVector4f *v71; // r14
  hkArray<int,hkContainerHeapAllocator> *v72; // rbx
  hkaiNavMesh::Edge *v73; // rax
  signed int v74; // edx
  __int64 v75; // rcx
  __m128 *v76; // rcx
  __int64 v77; // rax
  int *v78; // rax
  __int128 v79; // xmm0
  hkVector4f v80; // xmm0
  unsigned int startFaceKey; // [rsp+40h] [rbp-C0h]
  hkSimdFloat32 result; // [rsp+50h] [rbp-B0h]
  void *dst[2]; // [rsp+60h] [rbp-A0h]
  hkSimdFloat32 maxClearance; // [rsp+70h] [rbp-90h]
  int faceIndex[4]; // [rsp+80h] [rbp-80h]
  hkVector4f leftPoint; // [rsp+90h] [rbp-70h]
  hkVector4f curRightPoint; // [rsp+A0h] [rbp-60h]
  hkaiEdgePath *v88; // [rsp+1A0h] [rbp+A0h]
  int v89; // [rsp+1A8h] [rbp+A8h]
  hkaiNavMeshCutter *cuttera; // [rsp+1B0h] [rbp+B0h]
  unsigned int edgeKeya; // [rsp+1B8h] [rbp+B8h]
  bool edgeKeyb; // [rsp+1B8h] [rbp+B8h]
  unsigned int edgeIdxa; // [rsp+1E0h] [rbp+E0h]
  unsigned int edgeIdxc; // [rsp+1E0h] [rbp+E0h]
  bool edgeIdxb; // [rsp+1E0h] [rbp+E0h]

  edgeKeya = edgeKey;
  cuttera = cutter;
  v88 = this;
  v10 = (hkArray<int,hkContainerHeapAllocator> **)accessor;
  v11 = edgeKey;
  v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_leftTurnRadius), (__m128)LODWORD(this->m_leftTurnRadius), 0);
  v13 = &this->m_edges.m_data[edgeIdx];
  v14 = _mm_shuffle_ps((__m128)LODWORD(this->m_rightTurnRadius), (__m128)LODWORD(this->m_rightTurnRadius), 0);
  v15 = _mm_shuffle_ps((__m128)LODWORD(this->m_characterRadius), (__m128)LODWORD(this->m_characterRadius), 0);
  dst[0] = hkaiEdgePath::getEdgeDataPtr(this, edgeIdx);
  v16 = hkaiGeneralAccessor::getEdgeFromPacked((hkaiGeneralAccessor *)v10, v11);
  v17 = *v10;
  v18 = v16;
  v89 = v11 & 0x3FFFFF;
  maxClearance.m_real = _mm_shuffle_ps((__m128)LODWORD((*v10)[29].m_data), (__m128)LODWORD((*v10)[29].m_data), 0);
  v19 = v16->m_oppositeEdge;
  a5.m128_f32[0] = *(float *)&v17[29].m_data * 0.99000001;
  v20 = _mm_shuffle_ps(a5, a5, 0);
  v21 = v16->m_flags.m_storage & 0x40;
  if ( v21 )
    v22 = v19 >> 22;
  else
    v22 = v17[29].m_size;
  if ( v19 == -1 )
    v22 = -1;
  if ( v21 )
    v23 = v19 & 0xFFC00000;
  else
    v23 = v17[29].m_size << 22;
  v24 = v23 | v19 & 0x3FFFFF;
  v25 = v19 == -1;
  v26 = v18->m_oppositeFace;
  if ( v25 )
    v24 = -1;
  if ( v21 )
    v27 = v26 & 0xFFC00000;
  else
    v27 = v17[29].m_size << 22;
  v28 = v27 | v26 & 0x3FFFFF;
  v29 = v18->m_a;
  v25 = v26 == -1;
  v30 = v17[3].m_size;
  if ( v25 )
    v28 = -1;
  if ( (signed int)v29 >= v30 )
    v31 = (__m128 *)&v17[19].m_data[4 * ((signed int)v29 - v30)];
  else
    v31 = (__m128 *)&v17[3].m_data[4 * v29];
  v32 = *v31;
  v33 = v18->m_b;
  if ( (signed int)v33 >= v30 )
    v34 = (__m128 *)&v17[19].m_data[4 * ((signed int)v33 - v30)];
  else
    v34 = (__m128 *)&v17[3].m_data[4 * v33];
  v35 = *v34;
  v36 = *curFaceKey;
  curRightPoint.m_quad = v32;
  leftPoint.m_quad = v35;
  v37 = hkaiGeneralAccessor::getFaceFromPacked((hkaiGeneralAccessor *)v10, v36);
  edgeIdxa = *curFaceKey;
  index = v89 + 1;
  if ( v89 + 1 >= v37->m_startEdgeIndex + v37->m_numEdges )
    index = v37->m_startEdgeIndex;
  hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, edgeKeya >> 22);
  result.m_real.m128_u64[0] = (unsigned __int64)hkaiNavMeshInstance_get_hkaiNavMesh::Edge__7(
                                                  (hkaiNavMesh::Edge *)(*v10)[2].m_data,
                                                  (*v10)[2].m_size,
                                                  (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v10)[16],
                                                  (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v10)[18],
                                                  *v10 + 13,
                                                  index);
  hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, edgeIdxa >> 22);
  v39 = *((signed __int16 *)(*v10)[27].m_data + *(signed int *)result.m_real.m128_u64[0]) << 16;
  v40 = _mm_shuffle_ps((__m128)v39, (__m128)v39, 0);
  if ( v40.m128_f32[0] > maxClearance.m_real.m128_f32[0] )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(
      &result,
      (hkaiGeneralAccessor *)v10,
      edgeIdxa,
      (hkaiNavMesh::Edge *)result.m_real.m128_u64[0],
      curUp,
      &maxClearance);
    v40 = _mm_shuffle_ps(
            (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
            (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
            0);
  }
  startFaceKey = *curFaceKey;
  hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, *curFaceKey >> 22);
  edgeIdxc = *((signed __int16 *)(*v10)[27].m_data + v18->m_a) << 16;
  v41 = _mm_shuffle_ps((__m128)edgeIdxc, (__m128)edgeIdxc, 0);
  if ( v41.m128_f32[0] > maxClearance.m_real.m128_f32[0] )
  {
    hkaiNavMeshTraversalUtils::computeGlobalClearance(
      &result,
      (hkaiGeneralAccessor *)v10,
      startFaceKey,
      v18,
      curUp,
      &maxClearance);
    v41 = _mm_shuffle_ps(
            (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
            (__m128)(unsigned int)((signed __int16)(COERCE_UNSIGNED_INT(result.m_real.m128_f32[0] * 1.0039062) >> 16) << 16),
            0);
  }
  v42 = _mm_max_ps(v40, aabbOut.m_quad);
  v43 = _mm_max_ps(v41, aabbOut.m_quad);
  v44 = _mm_cmpleps(v20, v42);
  v45 = _mm_cmpleps(v20, v43);
  v46 = _mm_sub_ps(v35, v32);
  v47 = _mm_mul_ps(v46, v46);
  v48 = _mm_or_ps(_mm_andnot_ps(v44, v42), _mm_and_ps(v44, (__m128)xmmword_141A712B0));
  v49 = _mm_or_ps(_mm_andnot_ps(v45, v43), _mm_and_ps(v45, (__m128)xmmword_141A712B0));
  v50 = _mm_max_ps(_mm_sub_ps(v15, v48), aabbOut.m_quad);
  v51 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170));
  v52 = _mm_max_ps(_mm_sub_ps(v15, v49), aabbOut.m_quad);
  v53 = _mm_rsqrt_ps(v51);
  v54 = _mm_andnot_ps(
          _mm_cmpleps(v51, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v51, v53), v53)),
              _mm_mul_ps(*(__m128 *)_xmm, v53)),
            v51));
  if ( v18->m_flags.m_storage & 0x10 )
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
  if ( v18->m_flags.m_storage & 0x10 )
  {
    v13->m_edge.m_edgeOffset = -1;
    hkaiNavMeshCutter::makePersistentFaceKey(cuttera, *curFaceKey, &v13->m_edge.m_faceKey);
  }
  else
  {
    hkaiNavMeshCutter::makePersistentEdgeKey(cuttera, edgeKeya, *curFaceKey, &v13->m_edge);
  }
  v13->m_flags.m_storage = v18->m_flags.m_storage;
  v67 = 0i64;
  *(_DWORD *)&v13->m_leftFollowingCorner.m_data = 0;
  striding = (*v10)[5].m_size;
  if ( striding )
    v67 = hkaiNavMeshInstance_getWithStriding_int__2(
            (*v10)[5].m_data,
            (*v10)[2].m_size,
            *v10 + 23,
            *v10 + 25,
            *v10 + 13,
            v89,
            striding);
  hkString::memCpy(dst[0], v67, 4 * v88->m_edgeDataStriding);
  edgeIdxb = v22 != *curSection;
  if ( edgeIdxb )
  {
    hkaiGeneralAccessor::setSection((hkaiGeneralAccessor *)v10, v22);
    v69 = (*v10)[6].m_data[30] & 1;
  }
  else
  {
    v69 = *curSectionIsWC;
  }
  edgeKeyb = v69;
  v70 = ((unsigned __int8)v18->m_flags.m_storage >> 4) & 1;
  if ( *curSectionIsWC || v69 )
  {
    hkaiNavMeshUtils::calcFaceNormal<hkaiNavMeshInstance>(
      (hkaiNavMeshUtils *)dst,
      (hkSimdFloat32 *)*v10,
      (hkaiNavMeshInstance *)(v28 & 0x3FFFFF),
      (__int64)faceIndex);
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
    v72 = *v10;
    v73 = hkaiNavMeshInstance_get_hkaiNavMesh::Edge__7(
            (hkaiNavMesh::Edge *)(*v10)[2].m_data,
            (*v10)[2].m_size,
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v10)[16],
            (hkArray<hkaiNavMesh::Edge,hkContainerHeapAllocator> *)&(*v10)[18],
            *v10 + 13,
            v24 & 0x3FFFFF);
    v74 = v72[3].m_size;
    v75 = v73->m_a;
    if ( (signed int)v75 >= v74 )
      v76 = (__m128 *)&v72[19].m_data[4 * ((signed int)v75 - v74)];
    else
      v76 = (__m128 *)&v72[3].m_data[4 * v75];
    v77 = v73->m_b;
    if ( (signed int)v77 >= v74 )
      v78 = &v72[19].m_data[4 * ((signed int)v77 - v74)];
    else
      v78 = &v72[3].m_data[4 * v77];
    v79 = *(_OWORD *)v78;
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
  *curSection = v22;
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
  hkaiEdgePath::getFollowingCornerInfoPacked(this, startEdge, startIsLeft)->m_data = -32768;
}

// File Line: 1050
// RVA: 0xBEB1F0
void __fastcall hkaiEdgePath::setFollowingCornerInfoValid(hkaiEdgePath *this, int startEdge, bool startIsLeft, int followingCornerEdge, bool followingCornerIsLeft)
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
signed __int64 __fastcall hkaiEdgePath::getFollowingCornerInfo(hkaiEdgePath *this, int startEdge, bool startIsLeft, int *followingCornerEdgeOut, bool *followingCornerIsLeftOut)
{
  int *v5; // rdi
  int v6; // ebx
  hkaiEdgePath::FollowingCornerInfo *v7; // rax

  v5 = followingCornerEdgeOut;
  v6 = startEdge;
  v7 = hkaiEdgePath::getFollowingCornerInfoPacked(this, startEdge, startIsLeft);
  if ( !(v7->m_data & 0x4000) )
    return 0i64;
  *v5 = v6 + (v7->m_data & 0x1FFF);
  *followingCornerIsLeftOut = (v7->m_data >> 13) & 1;
  return 1i64;
}

// File Line: 1076
// RVA: 0xBEC7D0
hkaiEdgePath::FollowingCornerInfo *__fastcall hkaiEdgePath::getFollowingCornerInfoPacked(hkaiEdgePath *this, int startEdge, bool startIsLeft)
{
  hkaiEdgePath::Edge *v3; // rax
  hkaiEdgePath::FollowingCornerInfo *result; // rax

  v3 = &this->m_edges.m_data[startEdge];
  if ( startIsLeft )
    result = &v3->m_leftFollowingCorner;
  else
    result = &v3->m_rightFollowingCorner;
  return result;
}

// File Line: 1082
// RVA: 0xBEC800
hkaiEdgePath::FollowingCornerInfo *__fastcall hkaiEdgePath::getFollowingCornerInfoPacked(hkaiEdgePath *this, int startEdge, bool startIsLeft)
{
  hkaiEdgePath::Edge *v3; // rax
  hkaiEdgePath::FollowingCornerInfo *result; // rax

  v3 = &this->m_edges.m_data[startEdge];
  if ( startIsLeft )
    result = &v3->m_leftFollowingCorner;
  else
    result = &v3->m_rightFollowingCorner;
  return result;
}

// File Line: 1092
// RVA: 0xBEA710
void __fastcall hkaiEdgePath::hkaiEdgePath(hkaiEdgePath *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgePath::`vftable';
  this->m_edges.m_capacityAndFlags = 2147483648;
  this->m_edges.m_data = 0i64;
  this->m_edges.m_size = 0;
  this->m_edgeData.m_data = 0i64;
  this->m_edgeData.m_size = 0;
  this->m_edgeData.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&this->m_edgeDataStriding = 0i64;
  this->m_rightTurnRadius = 0.0;
}

// File Line: 1100
// RVA: 0xBEA750
void __fastcall hkaiEdgePath::hkaiEdgePath(hkaiEdgePath *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiEdgePath::`vftable';
}

// File Line: 1109
// RVA: 0xBEC6B0
__int64 __fastcall hkaiEdgePath::consecutiveEdgesShareVertex(hkaiEdgePath *this, int firstEdgeIndex, bool checkLeft, hkaiStreamingCollection *streamingCollection, hkaiNavMeshCutter *cutter)
{
  hkaiStreamingCollection::InstanceInfo *v5; // rax
  unsigned int v6; // ebp
  bool v7; // r14
  int v8; // ebx
  hkaiEdgePath *v9; // rdi
  hkaiEdgePath::Edge *v10; // rsi
  hkaiEdgePath::Edge *v11; // rbx
  hkaiNavMeshCutter *v12; // rdi
  unsigned int v13; // eax
  MoveResult v14; // eax
  unsigned int v15; // eax
  unsigned int faceKeyOut; // [rsp+20h] [rbp-38h]
  unsigned int v18; // [rsp+24h] [rbp-34h]
  hkaiGeneralAccessor accessor; // [rsp+28h] [rbp-30h]
  unsigned int edgeKey; // [rsp+68h] [rbp+10h]
  unsigned int faceKey; // [rsp+78h] [rbp+20h]

  v5 = streamingCollection->m_instances.m_data;
  v6 = 0;
  v7 = checkLeft;
  v8 = firstEdgeIndex;
  v9 = this;
  accessor.m_currentSection = -1;
  accessor.m_sectionInfo = v5;
  accessor.m_accessor = 0i64;
  v10 = hkaiEdgePath::getEdge(this, firstEdgeIndex);
  v11 = hkaiEdgePath::getEdge(v9, v8 + 1);
  if ( _mm_movemask_ps(_mm_cmpeqps(v10->m_right.m_quad, v10->m_left.m_quad)) == 15 )
    return 0i64;
  if ( v10->m_flags.m_storage & 0x10 )
    return 0i64;
  if ( _mm_movemask_ps(_mm_cmpeqps(v11->m_right.m_quad, v11->m_left.m_quad)) == 15 )
    return 0i64;
  if ( v11->m_flags.m_storage & 0x10 )
    return 0i64;
  v12 = cutter;
  v13 = hkaiEdgePathSteeringUtil::resolveEdgeToKey(v10, &accessor, cutter, &faceKeyOut);
  if ( v13 == -1 )
    return 0i64;
  edgeKey = v13;
  faceKey = faceKeyOut;
  v14 = v7 ? `anonymous namespace'::moveCcwAroundVertex(&accessor, &edgeKey, &faceKey) : `anonymous namespace'::moveCwAroundVertex(
                                                                                           &accessor,
                                                                                           &edgeKey,
                                                                                           &faceKey);
  if ( v14 == 1 )
    return 0i64;
  v15 = hkaiEdgePathSteeringUtil::resolveEdgeToKey(v11, &accessor, v12, &v18);
  LOBYTE(v6) = edgeKey == v15;
  return v6;
}

