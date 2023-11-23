// File Line: 23
// RVA: 0xDF8D10
void __fastcall hkpMoppDefaultSplitter::hkpMoppDefaultSplitter(hkpMoppDefaultSplitter *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppDefaultSplitter::`vftable;
  this->m_freeNodes.m_elems = 0i64;
  this->m_freeNodes.m_freeElems = 0;
  this->m_freeTerminals.m_elems = 0i64;
  this->m_freeTerminals.m_freeElems = 0;
  this->m_compileParams = 0i64;
  this->m_maxList = 0i64;
}

// File Line: 29
// RVA: 0xDF8D50
void __fastcall hkpMoppDefaultSplitter::~hkpMoppDefaultSplitter(hkpMoppDefaultSplitter *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 149
// RVA: 0xDF9710
void __fastcall hkpMoppDefaultSplitter::findSplittingPlanePositions(
        hkpMoppDefaultSplitter *this,
        hkpMoppBasicNode *node,
        hkpMoppSplittingPlaneDirection *plane,
        hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *params,
        hkpMoppExtent *extents,
        int treeDepth)
{
  int m_optimalDepth; // r12d
  float m_numPrimitives; // xmm0_4
  int m_maxPrimitiveSplits; // edx
  int v14; // ebp
  float v15; // xmm6_4
  unsigned int m_primitiveID; // r8d
  unsigned int v17; // r9d
  float v18; // xmm15_4
  float v19; // xmm11_4
  hkpMoppSplitter::hkpMoppSplitParams *m_compileParams; // rax
  int v21; // edi
  unsigned int v22; // edx
  float m_min; // xmm12_4
  unsigned int v24; // eax
  hkpMoppDefaultSplitter::hkpMoppMaxList *m_maxList; // r8
  __int64 i; // rdx
  hkpMoppCompilerPrimitive **buffer; // rcx
  hkpMoppSplitter::hkpMoppSplitParams *v28; // rax
  float v29; // xmm3_4
  hkpMoppCostFunction *m_costFunction; // r10
  float v31; // xmm9_4
  float v32; // xmm3_4
  float v33; // xmm2_4
  float v34; // xmm2_4
  float v35; // xmm2_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  hkpMoppDefaultSplitter::hkpMoppMaxList *v38; // rcx
  float v39; // xmm8_4
  int v40; // edx
  int v41; // r9d
  float v42; // xmm10_4
  int v43; // r11d
  hkpMoppCompilerPrimitive *lastRemovedElement; // rax
  float m_max; // xmm6_4
  int m_currentNumElements; // edx
  hkpMoppDefaultSplitter::hkpMoppMaxList *v47; // rax
  hkpMoppCompilerPrimitive *v48; // r8
  float v49; // xmm4_4
  float v50; // xmm3_4
  float v51; // xmm3_4
  float v52; // xmm3_4
  float v53; // xmm3_4
  float v54; // xmm1_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm2_4
  hkpMoppDefaultSplitter::hkpMoppMaxList *v58; // rdx
  __int64 j; // rcx
  unsigned int v60; // [rsp+110h] [rbp+8h]
  unsigned int v61; // [rsp+120h] [rbp+18h]
  int v62; // [rsp+128h] [rbp+20h]
  float extentsa; // [rsp+130h] [rbp+28h]
  int treeDeptha; // [rsp+138h] [rbp+30h]

  m_optimalDepth = this->m_optimalDepth;
  m_numPrimitives = (float)params->m_numPrimitives;
  m_maxPrimitiveSplits = params->m_maxPrimitiveSplits;
  v14 = 0;
  treeDeptha = SLODWORD(extents->m_min);
  m_primitiveID = params->m_primitives->m_primitiveID;
  extentsa = extents->m_max;
  v15 = extentsa;
  v17 = m_primitiveID;
  v18 = 1.0 / m_numPrimitives;
  v19 = *(float *)&FLOAT_1_0;
  if ( (float)(extentsa - *(float *)&treeDeptha) >= 0.001 )
    v19 = 1.0 / (float)(extentsa - *(float *)&treeDeptha);
  m_compileParams = this->m_compileParams;
  v21 = 0;
  if ( m_maxPrimitiveSplits > m_compileParams->m_maxPrimitiveSplitsPerNode )
    m_maxPrimitiveSplits = m_compileParams->m_maxPrimitiveSplitsPerNode;
  v62 = m_maxPrimitiveSplits;
  while ( v21 < params->m_numPrimitives )
  {
    v22 = params->m_primitives[v21].m_primitiveID;
    m_min = params->m_primitives[v21].m_extent.m_min;
    v24 = v22;
    if ( m_primitiveID < v22 )
      v24 = m_primitiveID;
    if ( v17 > v22 )
      v22 = v17;
    v60 = v24;
    v61 = v22;
    hkpMoppDefaultSplitter::hkpMoppMaxList::removeElementsLessThan(
      this->m_maxList,
      params->m_primitives[v21].m_extent.m_min);
    m_maxList = this->m_maxList;
    for ( i = m_maxList->m_currentNumElements - 1; i > v62; --m_maxList->m_currentNumElements )
    {
      buffer = m_maxList->buffer;
      m_maxList->lastRemovedElement = buffer[i--];
      buffer[i + 1] = 0i64;
    }
    v28 = this->m_compileParams;
    v29 = *(float *)&treeDeptha;
    m_costFunction = this->m_costFunction;
    v31 = (float)(v15 + *(float *)&treeDeptha) * 0.5;
    if ( treeDepth >= m_optimalDepth )
    {
      v33 = v19;
    }
    else
    {
      v32 = fminf(m_costFunction->m_userScaling.m_queryErrorTolerance, v15 - *(float *)&treeDeptha)
          + (float)(v15 - *(float *)&treeDeptha);
      if ( v32 <= 0.0 )
      {
        v29 = *(float *)&treeDeptha;
        v33 = FLOAT_3_4028202e37;
      }
      else
      {
        v33 = 1.0 / v32;
        v29 = *(float *)&treeDeptha;
      }
    }
    v34 = v33 * (float)(m_min - v31);
    if ( v34 >= 0.0 )
    {
      v36 = v34 * v34;
      v35 = (float)((float)((float)(v36 * 2.9000001) + (float)((float)(v36 * v36) * 3.0))
                  + (float)((float)((float)(v36 * v36) * (float)(v36 * v36)) * 1500.0))
          * m_costFunction->m_userScaling.m_weightPlanePosition;
    }
    else
    {
      v35 = 0.0;
    }
    if ( (int)(v61 - v60) >= 16 )
      v37 = 0.0;
    else
      v37 = m_costFunction->m_userScaling.m_weightPrimitiveIdSpread * -0.029999999;
    v38 = this->m_maxList;
    v39 = FLOAT_1_0e7;
    v40 = 0;
    v41 = 0;
    v42 = (float)(plane->m_cost + v35) + v37;
    v43 = v28->m_minRangeMaxListCheck >> 1;
    if ( v38->m_currentNumElements )
    {
      if ( v42 > node->m_bestOverallCost )
        goto LABEL_61;
      if ( v28->m_checkAllEveryN <= 0 )
      {
        m_currentNumElements = v38->m_currentNumElements;
      }
      else
      {
        m_currentNumElements = v43 + v14;
        if ( v43 + v14 > v38->m_currentNumElements )
          m_currentNumElements = v38->m_currentNumElements;
        v41 = v14 - v43;
        if ( v14 - v43 < 0 )
          v41 = 0;
      }
      v40 = m_currentNumElements - 1;
      while ( 2 )
      {
        if ( v40 < v41 )
        {
          v15 = extentsa;
          --v14;
          goto LABEL_61;
        }
        v47 = this->m_maxList;
        if ( v40 > v47->m_currentNumElements )
          v48 = 0i64;
        else
          v48 = v47->buffer[v40];
        m_max = v48->m_extent.m_max;
LABEL_40:
        if ( treeDepth >= m_optimalDepth )
        {
          v50 = v19;
        }
        else
        {
          v49 = fminf(m_costFunction->m_userScaling.m_queryErrorTolerance, extentsa - v29) + (float)(extentsa - v29);
          if ( v49 <= 0.0 )
            v50 = FLOAT_3_4028202e37;
          else
            v50 = 1.0 / v49;
        }
        v51 = v50 * (float)(m_max - v31);
        if ( v51 <= 0.0 )
        {
          v53 = v51 * v51;
          v52 = (float)((float)((float)(v53 * 2.9000001) + (float)((float)(v53 * v53) * 3.0))
                      + (float)((float)((float)(v53 * v53) * (float)(v53 * v53)) * 1500.0))
              * m_costFunction->m_userScaling.m_weightPlanePosition;
        }
        else
        {
          v52 = 0.0;
        }
        v54 = COERCE_FLOAT((unsigned int)(2 * COERCE_INT((float)(v21 - (v40 + params->m_numPrimitives - v21)))) >> 1)
            * v18;
        if ( treeDepth >= m_optimalDepth )
        {
          v55 = v54 * v54;
        }
        else
        {
          v55 = (float)(v54 - 0.75) * 6.0;
          if ( v55 < 0.0 )
          {
            v56 = 0.0;
LABEL_53:
            v57 = (float)((float)((float)(v56 + v52)
                                + (float)((float)((float)((float)v40 * v18) * 5.0)
                                        * m_costFunction->m_userScaling.m_weightPrimitiveSplit))
                        + (float)((float)((float)(m_max - m_min) * v19)
                                * m_costFunction->m_userScaling.m_weightPlaneDistance))
                + v42;
            if ( v57 >= v39
              || (v39 = v57, v14 = v40, v57 >= node->m_bestOverallCost)
              || (node->m_bestOverallCost = v57,
                  node->m_planeRightPosition = m_min,
                  node->m_plane = plane,
                  node->m_planeLeftPosition = m_max,
                  v40 - v43 >= v41) )
            {
              v29 = *(float *)&treeDeptha;
              --v40;
            }
            else
            {
              v29 = *(float *)&treeDeptha;
              v41 = v40 - v43;
              if ( v40 - v43 < 0 )
                v41 = 0;
              --v40;
            }
            continue;
          }
        }
        break;
      }
      v56 = (float)((float)((float)(v55 * v55) * v55) * v55)
          * m_costFunction->m_userScaling.m_weightNumUnbalancedTriangles;
      goto LABEL_53;
    }
    lastRemovedElement = v38->lastRemovedElement;
    if ( lastRemovedElement )
    {
      m_max = lastRemovedElement->m_extent.m_max;
      goto LABEL_40;
    }
LABEL_61:
    hkpMoppDefaultSplitter::hkpMoppMaxList::addElement(this->m_maxList, &params->m_primitives[v21]);
    m_primitiveID = v60;
    v17 = v61;
    ++v21;
  }
  v58 = this->m_maxList;
  for ( j = v58->m_currentNumElements - 1; j > 0; v58->buffer[j + 1] = 0i64 )
    --j;
  v58->m_currentNumElements = 0;
  v58->lastRemovedElement = 0i64;
}

// File Line: 277
// RVA: 0xDFA640
void __fastcall hkpMoppDefaultSplitter::sortLeftAndRight(
        hkpMoppDefaultSplitter *this,
        int switchPosition,
        hkpMoppBasicNode *bestNode,
        int depth,
        int *maxSplits,
        int *numSplits,
        hkpMoppCompilerPrimitive **beginUnsorted,
        hkpMoppCompilerPrimitive **endUnsorted,
        hkpMoppCompilerPrimitive **beginRight,
        hkpMoppCompilerPrimitive **beginMiddle)
{
  int v11; // edx
  int v12; // edx
  hkpMoppSplittingPlaneDirection *m_plane; // rbx
  hkpMoppMediator *m_mediator; // rcx
  _DWORD *v15; // rbx
  _DWORD *v16; // r11
  int *v17; // r10
  int v18; // ecx
  int v19; // edx
  int v20; // r8d
  int v21; // r9d
  int v22; // r10d
  _DWORD *v23; // rax
  unsigned int m_primitiveID; // r8d
  unsigned int m_primitiveID2; // r9d
  float m_min; // r10d
  float m_max; // r11d
  unsigned int m_origPrimitiveID; // ebx
  unsigned int v29; // ebp
  float v30; // r12d
  float v31; // r13d
  unsigned int v32; // r15d
  hkpMoppCompilerPrimitive *v33; // rax
  float *v34; // rax
  __int64 v35; // [rsp+28h] [rbp-50h]
  __m128 v36; // [rsp+30h] [rbp-48h] BYREF
  unsigned int v37; // [rsp+88h] [rbp+10h]

  if ( switchPosition )
  {
    v11 = switchPosition - 1;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        if ( v12 == 1 )
        {
          --*maxSplits;
          ++*numSplits;
          --*beginRight;
          m_plane = bestNode->m_plane;
          ((void (__fastcall *)(hkpMoppMediator *, _QWORD, hkpMoppSplittingPlaneDirection *))this->m_mediator->vfptr[4].__vecDelDtor)(
            this->m_mediator,
            *beginUnsorted,
            m_plane);
          m_mediator = this->m_mediator;
          v35 = (__int64)*beginUnsorted;
          v36 = _mm_xor_ps(
                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                  m_plane->m_direction.m_quad);
          ((void (__fastcall *)(hkpMoppMediator *, __int64, __m128 *))m_mediator->vfptr[4].__vecDelDtor)(
            m_mediator,
            v35,
            &v36);
          ++*beginUnsorted;
        }
      }
      else
      {
        --*beginRight;
        --*endUnsorted;
        v15 = *beginUnsorted;
        v16 = *beginRight;
        v17 = (int *)*endUnsorted;
        if ( *beginUnsorted != *beginRight )
        {
          v18 = *v17;
          v19 = v17[1];
          v20 = v17[2];
          v21 = v17[3];
          v22 = v17[4];
          *v16 = *v15;
          v16[1] = v15[1];
          v16[2] = v15[2];
          v16[3] = v15[3];
          v16[4] = v15[4];
          v23 = *beginUnsorted;
          *v23 = v18;
          v23[1] = v19;
          v23[2] = v20;
          v23[3] = v21;
          v23[4] = v22;
        }
      }
    }
    else
    {
      ++*beginUnsorted;
    }
  }
  else
  {
    --*beginRight;
    --*beginMiddle;
    --*endUnsorted;
    m_primitiveID = (*beginUnsorted)->m_primitiveID;
    m_primitiveID2 = (*beginUnsorted)->m_primitiveID2;
    m_min = (*beginUnsorted)->m_extent.m_min;
    m_max = (*beginUnsorted)->m_extent.m_max;
    m_origPrimitiveID = (*beginUnsorted)->m_origPrimitiveID;
    v29 = (*endUnsorted)->m_primitiveID;
    v30 = (*endUnsorted)->m_extent.m_min;
    v31 = (*endUnsorted)->m_extent.m_max;
    v37 = (*endUnsorted)->m_origPrimitiveID;
    v32 = (*endUnsorted)->m_primitiveID2;
    **beginRight = **beginMiddle;
    v33 = *beginMiddle;
    v33->m_primitiveID = m_primitiveID;
    v33->m_primitiveID2 = m_primitiveID2;
    v33->m_extent.m_min = m_min;
    v33->m_extent.m_max = m_max;
    v33->m_origPrimitiveID = m_origPrimitiveID;
    v34 = (float *)*beginUnsorted;
    if ( *beginUnsorted != *endUnsorted )
    {
      *(_DWORD *)v34 = v29;
      *((_DWORD *)v34 + 1) = v32;
      v34[2] = v30;
      v34[3] = v31;
      *((_DWORD *)v34 + 4) = v37;
    }
  }
}

// File Line: 368
// RVA: 0xDFA2B0
void __fastcall hkpMoppDefaultSplitter::distributeMiddle(
        hkpMoppDefaultSplitter *this,
        hkpMoppCompilerPrimitive **startLeft,
        hkpMoppCompilerPrimitive **endLeft,
        hkpMoppCompilerPrimitive **startRight,
        hkpMoppCompilerPrimitive **endRight,
        hkpMoppCompilerPrimitive **startMiddle,
        hkpMoppCompilerPrimitive **endMiddle,
        hkpMoppBasicNode *bestNode)
{
  hkpMoppCompilerPrimitive **v8; // r12
  hkpMoppCompilerPrimitive **v10; // rsi
  hkpMoppCompilerPrimitive **v11; // rdi
  signed __int64 v12; // rbx
  int v13; // r8d
  float v14; // xmm1_4
  int m_index; // edx
  hkpMoppCompilerPrimitive *v16; // r10
  bool v17; // cl
  __int64 v18; // r9
  signed __int64 v19; // rdx
  float m_min; // edi
  float m_max; // esi
  unsigned int m_origPrimitiveID; // ebp
  unsigned int m_primitiveID; // r11d
  unsigned int m_primitiveID2; // ebx
  unsigned int v25; // ecx
  unsigned int v26; // edx
  float v27; // r8d
  float v28; // r9d
  unsigned int v29; // r10d
  hkpMoppCompilerPrimitive *v30; // rax
  hkpMoppCompilerPrimitive *v31; // rax

  v8 = endMiddle;
  v10 = startLeft;
  v11 = endLeft;
  v12 = *endMiddle - *startMiddle;
  if ( v12 )
  {
    v13 = 0;
    v14 = 0.0;
    m_index = bestNode->m_plane->m_index;
    if ( m_index && (float)(bestNode->m_extents.m_extent[0].m_max - bestNode->m_extents.m_extent[0].m_min) > 0.0 )
      v14 = bestNode->m_extents.m_extent[0].m_max - bestNode->m_extents.m_extent[0].m_min;
    if ( m_index != 1 && (float)(bestNode->m_extents.m_extent[1].m_max - bestNode->m_extents.m_extent[1].m_min) > v14 )
    {
      v14 = bestNode->m_extents.m_extent[1].m_max - bestNode->m_extents.m_extent[1].m_min;
      v13 = 1;
    }
    if ( m_index != 2 && (float)(bestNode->m_extents.m_extent[2].m_max - bestNode->m_extents.m_extent[2].m_min) > v14 )
      v13 = 2;
    this->m_mediator->vfptr[3].__vecDelDtor(this->m_mediator, (unsigned int)&this->m_planeDirections[v13]);
    if ( (int)v12 > 1 )
      hkAlgorithm::quickSortRecursive<hkpMoppCompilerPrimitive,hkAlgorithm::less<hkpMoppCompilerPrimitive>>(
        *startMiddle,
        0,
        v12 - 1,
        0);
    v16 = *endMiddle;
    v17 = *v11 - *v10 < *endRight - *startRight;
    if ( *startMiddle < *endMiddle )
    {
      do
      {
        v18 = *v11 - *v10;
        v19 = *endRight - *startRight;
        if ( v17 )
          LODWORD(v19) = 4 * v19;
        else
          LODWORD(v18) = 4 * v18;
        if ( (int)v18 >= (int)v19 )
        {
          ++*endRight;
          ++*startMiddle;
          v17 = 0;
        }
        else
        {
          m_min = v16[-1].m_extent.m_min;
          m_max = v16[-1].m_extent.m_max;
          m_origPrimitiveID = v16[-1].m_origPrimitiveID;
          m_primitiveID = v16[-1].m_primitiveID;
          m_primitiveID2 = v16[-1].m_primitiveID2;
          v16[-1] = **startMiddle;
          v8 = endMiddle;
          v25 = (*startRight)->m_primitiveID;
          v26 = (*startRight)->m_primitiveID2;
          v27 = (*startRight)->m_extent.m_min;
          v28 = (*startRight)->m_extent.m_max;
          v29 = (*startRight)->m_origPrimitiveID;
          v30 = *endLeft;
          v30->m_primitiveID = m_primitiveID;
          v30->m_primitiveID2 = m_primitiveID2;
          v30->m_extent.m_min = m_min;
          v11 = endLeft;
          v30->m_extent.m_max = m_max;
          v10 = startLeft;
          v30->m_origPrimitiveID = m_origPrimitiveID;
          v31 = *startMiddle;
          v31->m_primitiveID = v25;
          v31->m_primitiveID2 = v26;
          v31->m_extent.m_min = v27;
          v31->m_extent.m_max = v28;
          v31->m_origPrimitiveID = v29;
          ++*endLeft;
          ++*startRight;
          ++*startMiddle;
          ++*endRight;
          v17 = 1;
        }
        v16 = *v8;
      }
      while ( *startMiddle < *v8 );
    }
  }
}

// File Line: 456
// RVA: 0xDF9C80
void __fastcall hkpMoppDefaultSplitter::groupPrimitives(
        hkpMoppDefaultSplitter *this,
        hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *in,
        hkpMoppBasicNode *bestNode,
        int depth,
        hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *leftOut,
        hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *rightOut)
{
  __int64 v6; // rdi
  __int64 v7; // r12
  int m_maxPrimitiveSplits; // edi
  __int64 m_numPrimitives; // r9
  hkpMoppCompilerPrimitive *m_primitives; // r15
  hkpMoppCompilerPrimitive *v15; // rcx
  hkpMoppCompilerPrimitive *v16; // rax
  int v17; // edx
  hkpMoppCompilerPrimitive **v18; // r10
  hkpMoppCompilerPrimitive *v19; // r11
  int v20; // edx
  __int64 v21; // rax
  bool v22; // zf
  char *v23; // rdx
  unsigned int m_primitiveID; // eax
  hkpMoppCompilerPrimitive **beginRight; // [rsp+40h] [rbp-19h] BYREF
  hkpMoppCompilerPrimitive **beginMiddle; // [rsp+48h] [rbp-11h] BYREF
  hkpMoppCompilerPrimitive *startMiddle; // [rsp+50h] [rbp-9h] BYREF
  hkpMoppCompilerPrimitive *startRight; // [rsp+58h] [rbp-1h] BYREF
  hkpMoppCompilerPrimitive *beginUnsorted; // [rsp+60h] [rbp+7h] BYREF
  hkpMoppCompilerPrimitive *endMiddle; // [rsp+68h] [rbp+Fh] BYREF
  hkpMoppCompilerPrimitive *startLeft; // [rsp+70h] [rbp+17h] BYREF
  hkpMoppCompilerPrimitive *maxSplits; // [rsp+B8h] [rbp+5Fh] BYREF
  __int64 v33; // [rsp+D0h] [rbp+77h]
  __int64 v34; // [rsp+D8h] [rbp+7Fh]

  v33 = v6;
  m_maxPrimitiveSplits = in->m_maxPrimitiveSplits;
  v34 = v7;
  m_numPrimitives = in->m_numPrimitives;
  m_primitives = in->m_primitives;
  LODWORD(maxSplits) = m_maxPrimitiveSplits;
  v15 = &in->m_primitives[(int)m_numPrimitives + m_maxPrimitiveSplits];
  v16 = m_primitives;
  LODWORD(beginRight) = 0;
  startLeft = m_primitives;
  beginMiddle = (hkpMoppCompilerPrimitive **)&m_primitives[m_numPrimitives];
  startRight = &m_primitives[(int)m_numPrimitives + m_maxPrimitiveSplits];
  startMiddle = startRight;
  endMiddle = startRight;
  beginUnsorted = m_primitives;
  if ( m_primitives < (hkpMoppCompilerPrimitive *)beginMiddle )
  {
    do
    {
      if ( bestNode->m_planeRightPosition <= v16->m_extent.m_min )
      {
        v17 = 0;
        if ( bestNode->m_planeLeftPosition < v16->m_extent.m_max )
          v17 = 2;
      }
      else
      {
        v17 = 3;
        if ( v16->m_extent.m_max <= bestNode->m_planeLeftPosition )
          v17 = 1;
      }
      hkpMoppDefaultSplitter::sortLeftAndRight(
        this,
        v17,
        bestNode,
        depth,
        (int *)&maxSplits,
        (int *)&beginRight,
        &beginUnsorted,
        (hkpMoppCompilerPrimitive **)&beginMiddle,
        &startRight,
        &startMiddle);
      v16 = beginUnsorted;
    }
    while ( beginUnsorted < (hkpMoppCompilerPrimitive *)beginMiddle );
    m_maxPrimitiveSplits = (int)maxSplits;
    v15 = startMiddle;
  }
  maxSplits = v15;
  hkpMoppDefaultSplitter::distributeMiddle(
    this,
    &startLeft,
    (hkpMoppCompilerPrimitive **)&beginMiddle,
    &startRight,
    &maxSplits,
    &startMiddle,
    &endMiddle,
    bestNode);
  v18 = beginMiddle;
  v19 = startRight;
  v20 = ((int)beginMiddle - (int)m_primitives) / 20;
  *(_DWORD *)(v33 + 8) = v20;
  *(_DWORD *)(v33 + 12) = (int)(float)((float)((float)v20 * (float)m_maxPrimitiveSplits) / (float)in->m_numPrimitives);
  *(_DWORD *)(v34 + 8) = ((int)maxSplits - (int)v19) / 20;
  *(_DWORD *)(v34 + 12) = m_maxPrimitiveSplits - *(_DWORD *)(v33 + 12);
  v21 = *(int *)(v33 + 12);
  *(_QWORD *)v33 = m_primitives;
  v22 = *(_DWORD *)(v34 + 12) == 0;
  v23 = (char *)v18 + 20 * v21;
  *(_QWORD *)v34 = v23;
  if ( !v22 && v19 < maxSplits )
  {
    do
    {
      m_primitiveID = v19->m_primitiveID;
      ++v19;
      v23 += 20;
      *((_DWORD *)v23 - 5) = m_primitiveID;
      *((_DWORD *)v23 - 4) = v19[-1].m_primitiveID2;
      *((_DWORD *)v23 - 3) = LODWORD(v19[-1].m_extent.m_min);
      *((_DWORD *)v23 - 2) = LODWORD(v19[-1].m_extent.m_max);
      *((_DWORD *)v23 - 1) = v19[-1].m_origPrimitiveID;
    }
    while ( v19 < maxSplits );
  }
}_extent.m_max);
      *((_DWORD *)v23 - 1) = v19[

// File Line: 516
// RVA: 0xDFA1D0
void __fastcall hkpMoppDefaultSplitter::calculateMaxMinId(
        hkpMoppDefaultSplitter *this,
        hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *params,
        hkpMoppTreeNode *node)
{
  hkpMoppCompilerPrimitive *m_primitives; // rdi
  unsigned int m_primitiveID; // ebp
  int v7; // esi
  unsigned int i; // r14d
  int v10; // eax
  unsigned int *m_maxPropertyValue; // rcx
  __int64 v12; // rdx
  unsigned int v13; // eax
  int m_numPrimitives; // eax
  char v15; // [rsp+58h] [rbp+10h] BYREF

  m_primitives = params->m_primitives;
  m_primitiveID = params->m_primitives->m_primitiveID;
  node->m_numProperties = 0;
  node->m_minPropertyValue[0] = -1;
  node->m_maxPropertyValue[0] = 0;
  v7 = params->m_numPrimitives - 1;
  for ( i = m_primitiveID; v7 >= 0; --v7 )
  {
    if ( m_primitives->m_primitiveID > i )
      i = m_primitives->m_primitiveID;
    if ( m_primitives->m_primitiveID < m_primitiveID )
      m_primitiveID = m_primitives->m_primitiveID;
    v10 = ((__int64 (__fastcall *)(hkpMoppMediator *, hkpMoppCompilerPrimitive *, char *))this->m_mediator->vfptr[4].__first_virtual_table_function__)(
            this->m_mediator,
            m_primitives,
            &v15);
    if ( v10 > node->m_numProperties )
      node->m_numProperties = v10;
    if ( v10 > 0 )
    {
      m_maxPropertyValue = node->m_maxPropertyValue;
      v12 = (unsigned int)v10;
      do
      {
        v13 = *(unsigned int *)((char *)m_maxPropertyValue + &v15 - (char *)node - 56);
        if ( v13 < *(m_maxPropertyValue - 1) )
          *(m_maxPropertyValue - 1) = v13;
        if ( v13 > *m_maxPropertyValue )
          *m_maxPropertyValue = v13;
        ++m_maxPropertyValue;
        --v12;
      }
      while ( v12 );
    }
    ++m_primitives;
  }
  m_numPrimitives = params->m_numPrimitives;
  node->m_minPrimitiveId = m_primitiveID;
  node->m_numPrimitives = m_numPrimitives;
  node->m_maxPrimitiveId = i;
}

// File Line: 575
// RVA: 0xDF8FE0
hkpFreeListElem *__fastcall hkpMoppDefaultSplitter::createTerminal(
        hkpMoppDefaultSplitter *this,
        hkpFreeListElem *parentNode,
        hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *params)
{
  hkpFreeListElem *m_elems; // r15
  hkpFreeListElem *m_next; // rax
  int v7; // ebx
  hkpFreeListElem *v8; // rdi
  __int64 v9; // rsi

  m_elems = this->m_freeTerminals.m_elems;
  m_next = m_elems->m_next;
  --this->m_freeTerminals.m_freeElems;
  this->m_freeTerminals.m_elems = m_next;
  HIDWORD(m_elems[7].m_next) = 0;
  LOWORD(m_elems[8].m_next) = 0;
  HIDWORD(m_elems[8].m_next) = -1;
  LODWORD(m_elems[12].m_next) = -1;
  LOBYTE(m_elems[1].m_next) = 1;
  m_elems->m_next = parentNode;
  m_elems[13].m_next = (hkpFreeListElem *)params->m_primitives;
  hkpMoppDefaultSplitter::calculateMaxMinId(this, params, (hkpMoppTreeNode *)m_elems);
  v7 = 0;
  v8 = m_elems + 2;
  v9 = 0i64;
  do
  {
    ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, _QWORD, hkpMoppCompilerPrimitive *, int, hkpFreeListElem *, char *))this->m_mediator->vfptr[3].__first_virtual_table_function__)(
      this->m_mediator,
      &this->m_planeDirections[v9],
      (unsigned int)v7++,
      params->m_primitives,
      params->m_numPrimitives,
      v8,
      (char *)&v8->m_next + 4);
    ++v8;
    ++v9;
  }
  while ( v7 < 3 );
  return m_elems;
}

// File Line: 597
// RVA: 0xDF8F80
hkpFreeListElem *__fastcall hkpMoppDefaultSplitter::createNode(hkpMoppDefaultSplitter *this)
{
  hkpFreeListElem *m_elems; // rdx
  hkpFreeListElem *m_next; // rax

  m_elems = this->m_freeNodes.m_elems;
  m_next = m_elems->m_next;
  --this->m_freeNodes.m_freeElems;
  this->m_freeNodes.m_elems = m_next;
  HIDWORD(m_elems[7].m_next) = 0;
  LOWORD(m_elems[8].m_next) = 0;
  HIDWORD(m_elems[8].m_next) = -1;
  LODWORD(m_elems[12].m_next) = -1;
  LOBYTE(m_elems[1].m_next) = 0;
  LODWORD(m_elems[15].m_next) = 1232348160;
  LODWORD(m_elems[14].m_next) = 1343554297;
  m_elems[16].m_next = 0i64;
  m_elems[17].m_next = 0i64;
  m_elems[13].m_next = 0i64;
  return m_elems;
}

// File Line: 628
// RVA: 0xDF9530
void __fastcall hkpMoppDefaultSplitter::resortAxis(
        hkpMoppDefaultSplitter *this,
        hkpMoppTreeInternalNode *parentNode,
        int *directionsOut,
        float *extraCostsOut)
{
  hkpMoppSplittingPlaneDirection *m_planeDirections; // rcx
  hkpMoppSplittingPlaneDirection *m_plane; // rbx
  float v6; // xmm5_4
  float v7; // xmm0_4
  int v8; // r10d
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  int v13; // ebx
  int v14; // ecx
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // [rsp+0h] [rbp-28h]
  float v19; // [rsp+4h] [rbp-24h]
  float v20; // [rsp+8h] [rbp-20h]

  if ( parentNode )
  {
    m_planeDirections = this->m_planeDirections;
    m_plane = parentNode->m_plane;
    v6 = 0.0;
    v7 = parentNode->m_extents.m_extent[0].m_max - parentNode->m_extents.m_extent[0].m_min;
    v8 = 0;
    v18 = v7;
    if ( m_plane == m_planeDirections )
    {
      v7 = v7 * 0.66000003;
      v18 = v7;
    }
    if ( v7 > 0.0 )
      v6 = v7;
    v9 = parentNode->m_extents.m_extent[1].m_max - parentNode->m_extents.m_extent[1].m_min;
    v19 = v9;
    if ( m_plane == &m_planeDirections[1] )
    {
      v9 = v9 * 0.66000003;
      v19 = v9;
    }
    if ( v9 > v6 )
    {
      v6 = v9;
      v8 = 1;
    }
    v10 = parentNode->m_extents.m_extent[2].m_max - parentNode->m_extents.m_extent[2].m_min;
    v20 = v10;
    if ( m_plane == &m_planeDirections[2] )
    {
      v10 = v10 * 0.66000003;
      v20 = v10;
    }
    if ( v10 > v6 )
    {
      v6 = v10;
      v8 = 2;
    }
    *directionsOut = v8;
    v11 = v6;
    *extraCostsOut = 0.0;
    v12 = 1.0 / v6;
    v13 = (v8 + 1) % 3;
    v14 = (v8 + 2) % 3;
    v15 = *(&v18 + v13);
    if ( v15 >= *(&v18 + v14) )
    {
      v17 = v6 - *(&v18 + v14);
      directionsOut[1] = v13;
      extraCostsOut[1] = (float)((float)((float)((float)((float)(v11 - v15) * v12) * (float)((float)(v11 - v15) * v12))
                                       * (float)((float)(v11 - v15) * v12))
                               * 16.0)
                       * 0.050000001;
      directionsOut[2] = v14;
    }
    else
    {
      v16 = v6 - *(&v18 + v14);
      directionsOut[1] = v14;
      v17 = v6 - v15;
      extraCostsOut[1] = (float)((float)((float)((float)(v16 * v12) * (float)(v16 * v12)) * (float)(v16 * v12)) * 16.0)
                       * 0.050000001;
      directionsOut[2] = v13;
    }
    extraCostsOut[2] = (float)((float)((float)((float)(v17 * v12) * (float)(v17 * v12)) * (float)(v17 * v12)) * 16.0)
                     * 0.050000001;
  }
  else
  {
    *directionsOut = 0;
    directionsOut[1] = 1;
    directionsOut[2] = 2;
    *(_QWORD *)extraCostsOut = 0i64;
    extraCostsOut[2] = 0.0;
  }
}

// File Line: 691
// RVA: 0xDF90B0
hkpFreeListElem *__fastcall hkpMoppDefaultSplitter::split(
        hkpMoppDefaultSplitter *this,
        hkpFreeListElem *parentNode,
        hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *params,
        hkpMoppDefaultSplitter::hkpMoppDsSide side,
        int depth)
{
  hkpMoppSplitter::hkpMoppSplitParams *m_compileParams; // rax
  hkpFreeListElem *result; // rax
  hkpFreeListElem *Node; // rax
  hkpMoppTreeInternalNode *v11; // rsi
  hkpMoppExtent v12; // rax
  int v13; // ecx
  __int64 v14; // r8
  hkpMoppSplittingPlaneDirection *v15; // rbp
  hkpMoppMediator *m_mediator; // rcx
  hkpMoppCompilerPrimitive *m_primitives; // r9
  hkBaseObjectVtbl *vfptr; // r10
  int m_numPrimitives; // r8d
  __int64 v20; // rbp
  int v21; // edx
  __int64 v22; // rcx
  hkpMoppSplittingPlaneDirection *v23; // rbp
  int v24; // r8d
  hkpMoppSplittingPlaneDirection *m_plane; // rdx
  int v26; // ebp
  hkpMoppTreeNode *v27; // rax
  bool v28; // zf
  hkpMoppExtent v29; // [rsp+40h] [rbp-278h] BYREF
  hkpMoppSplittingPlaneDirection *v30; // [rsp+48h] [rbp-270h] BYREF
  hkpMoppExtent *extents; // [rsp+50h] [rbp-268h]
  int directionsOut[4]; // [rsp+58h] [rbp-260h] BYREF
  hkOstream extraCostsOut; // [rsp+68h] [rbp-250h] BYREF
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray paramsa; // [rsp+80h] [rbp-238h] BYREF
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray leftOut; // [rsp+90h] [rbp-228h] BYREF
  char buf[536]; // [rsp+A0h] [rbp-218h] BYREF
  int v37; // [rsp+2D0h] [rbp+18h] BYREF
  hkpMoppDefaultSplitter::hkpMoppDsSide v38; // [rsp+2D8h] [rbp+20h]

  v38 = side;
  m_compileParams = this->m_compileParams;
  if ( params->m_numPrimitives == 1 )
  {
    if ( m_compileParams->m_interleavedBuildingEnabled.m_bool )
    {
      if ( !this->m_freeTerminals.m_freeElems )
        ((void (__fastcall *)(hkpMoppAssembler *, hkpMoppTreeInternalNode *, hkpMoppDefaultSplitter *, __int64))this->m_assembler->vfptr[2].__first_virtual_table_function__)(
          this->m_assembler,
          this->m_rootNode,
          this,
          2048i64);
    }
    return hkpMoppDefaultSplitter::createTerminal(this, parentNode, params);
  }
  else
  {
    if ( m_compileParams->m_interleavedBuildingEnabled.m_bool && !this->m_freeNodes.m_freeElems )
      ((void (__fastcall *)(hkpMoppAssembler *, hkpMoppTreeInternalNode *, hkpMoppDefaultSplitter *, __int64))this->m_assembler->vfptr[2].__first_virtual_table_function__)(
        this->m_assembler,
        this->m_rootNode,
        this,
        2048i64);
    Node = hkpMoppDefaultSplitter::createNode(this);
    LODWORD(Node[18].m_next) = params->m_numPrimitives;
    Node->m_next = parentNode;
    v11 = (hkpMoppTreeInternalNode *)Node;
    if ( parentNode )
    {
      if ( v38 )
        parentNode[17].m_next = Node;
      else
        parentNode[16].m_next = Node;
      LODWORD(Node[2].m_next) = parentNode[2].m_next;
      HIDWORD(Node[2].m_next) = HIDWORD(parentNode[2].m_next);
      LODWORD(Node[3].m_next) = parentNode[3].m_next;
      HIDWORD(Node[3].m_next) = HIDWORD(parentNode[3].m_next);
      LODWORD(Node[4].m_next) = parentNode[4].m_next;
      HIDWORD(Node[4].m_next) = HIDWORD(parentNode[4].m_next);
    }
    else
    {
      this->m_rootNode = (hkpMoppTreeInternalNode *)Node;
    }
    v30 = 0i64;
    hkpMoppDefaultSplitter::resortAxis(
      this,
      (hkpMoppTreeInternalNode *)parentNode,
      directionsOut,
      (float *)&extraCostsOut);
    v12 = 0i64;
    v13 = 0;
    v37 = 0;
    v29 = 0i64;
    do
    {
      v14 = *(int *)((char *)directionsOut + *(_QWORD *)&v12);
      v15 = &this->m_planeDirections[v14];
      if ( (float)(*(float *)((char *)&extraCostsOut.vfptr + *(_QWORD *)&v12) + v15->m_cost) > v11->m_bestOverallCost )
        break;
      m_mediator = this->m_mediator;
      m_primitives = params->m_primitives;
      vfptr = m_mediator->vfptr;
      extents = &v11->m_extents.m_extent[v14];
      ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, __int64, hkpMoppCompilerPrimitive *, int, hkpMoppExtent *, float *))vfptr[3].__vecDelDtor)(
        m_mediator,
        v15,
        v14,
        m_primitives,
        params->m_numPrimitives,
        extents,
        &extents->m_max);
      m_numPrimitives = params->m_numPrimitives;
      if ( m_numPrimitives > 1 )
        hkAlgorithm::quickSortRecursive<hkpMoppCompilerPrimitive,hkAlgorithm::less<hkpMoppCompilerPrimitive>>(
          params->m_primitives,
          0,
          m_numPrimitives - 1,
          0);
      v30 = v15;
      hkpMoppDefaultSplitter::findSplittingPlanePositions(this, v11, v15, params, extents, depth);
      if ( !v11->m_plane )
      {
        hkErrStream::hkErrStream((hkErrStream *)&extraCostsOut, buf, 512);
        hkOstream::operator<<(&extraCostsOut, "Could not find splitting plane for child");
        hkError::messageWarning(0xABBA2344, buf, "Collide\\Mopp\\Builder\\Splitter\\hkpMoppDefaultSplitter.cpp", 773);
        hkOstream::~hkOstream(&extraCostsOut);
        goto LABEL_35;
      }
      v12 = (hkpMoppExtent)(*(_QWORD *)&v29 + 4i64);
      v13 = ++v37;
      v29 = v12;
    }
    while ( *(__int64 *)&v12 < 12 );
    v20 = v13;
    if ( v13 < 3i64 )
    {
      do
      {
        ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, _QWORD, hkpMoppCompilerPrimitive *, int, hkpMoppExtent *, float *))this->m_mediator->vfptr[3].__first_virtual_table_function__)(
          this->m_mediator,
          &this->m_planeDirections[directionsOut[v20]],
          directionsOut[v20],
          params->m_primitives,
          params->m_numPrimitives,
          &v11->m_extents.m_extent[directionsOut[v20]],
          &v11->m_extents.m_extent[directionsOut[v20]].m_max);
        ++v20;
      }
      while ( v20 < 3 );
    }
    v21 = 3;
    v37 = 3;
    if ( this->m_numPlaneDirections > 3 )
    {
      v22 = 96i64;
      extents = (hkpMoppExtent *)96;
      do
      {
        v23 = (hkpMoppSplittingPlaneDirection *)((char *)this->m_planeDirections + v22);
        if ( v11->m_bestOverallCost < v23->m_cost )
          break;
        ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, _QWORD, hkpMoppCompilerPrimitive *, int, hkpMoppExtent *, float *))this->m_mediator->vfptr[3].__vecDelDtor)(
          this->m_mediator,
          v23,
          (unsigned int)v21,
          params->m_primitives,
          params->m_numPrimitives,
          &v29,
          &v29.m_max);
        v24 = params->m_numPrimitives;
        if ( v24 > 1 )
          hkAlgorithm::quickSortRecursive<hkpMoppCompilerPrimitive,hkAlgorithm::less<hkpMoppCompilerPrimitive>>(
            params->m_primitives,
            0,
            v24 - 1,
            0);
        v30 = v23;
        hkpMoppDefaultSplitter::findSplittingPlanePositions(this, v11, v23, params, &v29, depth);
        v21 = v37 + 1;
        v22 = (__int64)&extents[4];
        v37 = v21;
        extents += 4;
      }
      while ( v21 < this->m_numPlaneDirections );
    }
    hkpMoppDefaultSplitter::calculateMaxMinId(this, params, v11);
    m_plane = v11->m_plane;
    if ( v30 != m_plane )
      ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, _QWORD, hkpMoppCompilerPrimitive *, int, hkpMoppSplittingPlaneDirection **, int *))this->m_mediator->vfptr[3].__vecDelDtor)(
        this->m_mediator,
        m_plane,
        (unsigned int)m_plane->m_index,
        params->m_primitives,
        params->m_numPrimitives,
        &v30,
        &v37);
    v26 = depth;
    hkpMoppDefaultSplitter::groupPrimitives(this, params, v11, depth, &leftOut, &paramsa);
    v11->m_rightBranch = hkpMoppDefaultSplitter::split(this, v11, &paramsa, HK_MOPP_DS_RIGHT, v26 + 1);
    v27 = hkpMoppDefaultSplitter::split(this, v11, &leftOut, HK_MOPP_DS_LEFT, v26 + 1);
    v28 = v11->m_rightBranch == 0i64;
    v11->m_leftBranch = v27;
    if ( !v28 && v27 )
      return (hkpFreeListElem *)v11;
LABEL_35:
    v11->m_parent = (hkpMoppTreeInternalNode *)this->m_freeNodes.m_elems;
    ++this->m_freeNodes.m_freeElems;
    result = 0i64;
    this->m_freeNodes.m_elems = (hkpFreeListElem *)v11;
  }
  return result;
} v11->m_parent = (hkpMoppTreeInternalNode *)this->m_freeNodes.m_elems;


// File Line: 843
// RVA: 0xDF8F40
void __fastcall hkpMoppDefaultSplitter::releaseNode(hkpMoppDefaultSplitter *this, hkpFreeListElem *nodeToRelease)
{
  if ( nodeToRelease )
  {
    if ( LOBYTE(nodeToRelease[1].m_next) )
    {
      nodeToRelease->m_next = this->m_freeTerminals.m_elems;
      ++this->m_freeTerminals.m_freeElems;
      this->m_freeTerminals.m_elems = nodeToRelease;
    }
    else
    {
      nodeToRelease->m_next = this->m_freeNodes.m_elems;
      ++this->m_freeNodes.m_freeElems;
      this->m_freeNodes.m_elems = nodeToRelease;
    }
  }
}

// File Line: 860
// RVA: 0xDF8F70
__int64 __fastcall hkpMoppDefaultSplitter::getFreeNodes(hkpMoppDefaultSplitter *this)
{
  return (unsigned int)(this->m_freeNodes.m_freeElems + this->m_freeTerminals.m_freeElems);
}

// File Line: 867
// RVA: 0xDF8D70
hkpMoppTreeNode *__fastcall hkpMoppDefaultSplitter::buildTree(
        hkpMoppDefaultSplitter *this,
        hkpMoppMediator *mediator,
        hkpMoppCostFunction *costFunction,
        hkpMoppAssembler *assembler,
        hkpMoppSplitter::hkpMoppSplitParams *in,
        hkpMoppSplitter::hkpMoppScratchArea *temp)
{
  unsigned int v8; // eax
  __int64 v9; // rdx
  int m_maxPrimitiveSplits; // r10d
  int v11; // ecx
  int v12; // r14d
  hkpFreeListElem *m_nodes; // rcx
  hkpFreeListElem *m_terminals; // rcx
  int v15; // edi
  _QWORD **Value; // rax
  hkpMoppTreeNode *v17; // rsi
  __int64 v18; // rdi
  int v19; // ebx
  _QWORD **v20; // rax
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray params; // [rsp+30h] [rbp-48h] BYREF
  int v23; // [rsp+40h] [rbp-38h] BYREF
  int v24; // [rsp+44h] [rbp-34h]
  __int64 v25; // [rsp+48h] [rbp-30h]
  __int64 v26; // [rsp+50h] [rbp-28h]

  this->m_mediator = mediator;
  this->m_costFunction = costFunction;
  this->m_assembler = assembler;
  this->m_compileParams = in;
  v8 = ((__int64 (__fastcall *)(hkpMoppMediator *))mediator->vfptr[2].__vecDelDtor)(mediator);
  m_maxPrimitiveSplits = in->m_maxPrimitiveSplits;
  params.m_primitives = temp->m_primitives;
  params.m_numPrimitives = v8;
  params.m_maxPrimitiveSplits = m_maxPrimitiveSplits;
  v11 = v8;
  this->m_optimalDepth = 0;
  if ( v8 )
  {
    LODWORD(v9) = 0;
    do
    {
      v9 = (unsigned int)(v9 + 1);
      v11 >>= 1;
    }
    while ( v11 );
    this->m_optimalDepth = v9;
  }
  v12 = 4096;
  if ( !this->m_compileParams->m_interleavedBuildingEnabled.m_bool )
    v12 = m_maxPrimitiveSplits + v8;
  this->m_freeNodes.m_elems = 0i64;
  this->m_freeNodes.m_freeElems = 0;
  m_nodes = (hkpFreeListElem *)temp->m_nodes;
  if ( v12 > 0 )
  {
    v9 = (unsigned int)v12;
    do
    {
      m_nodes->m_next = this->m_freeNodes.m_elems;
      ++this->m_freeNodes.m_freeElems;
      this->m_freeNodes.m_elems = m_nodes;
      m_nodes += 19;
      --v9;
    }
    while ( v9 );
  }
  this->m_freeTerminals.m_elems = 0i64;
  this->m_freeTerminals.m_freeElems = 0;
  m_terminals = (hkpFreeListElem *)temp->m_terminals;
  if ( v12 > 0 )
  {
    v9 = (unsigned int)v12;
    do
    {
      m_terminals->m_next = this->m_freeTerminals.m_elems;
      ++this->m_freeTerminals.m_freeElems;
      this->m_freeTerminals.m_elems = m_terminals;
      m_terminals += 14;
      --v9;
    }
    while ( v9 );
  }
  this->m_numPlaneDirections = ((__int64 (__fastcall *)(hkpMoppAssembler *, __int64, _QWORD))assembler->vfptr[1].__first_virtual_table_function__)(
                                 assembler,
                                 v9,
                                 v8);
  this->m_planeDirections = (hkpMoppSplittingPlaneDirection *)((__int64 (__fastcall *)(hkpMoppAssembler *))assembler->vfptr[2].__vecDelDtor)(assembler);
  v15 = this->m_compileParams->m_maxPrimitiveSplitsPerNode + 2;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[10] + 8i64))(Value[10], (unsigned int)(8 * v15));
  v24 = v15;
  v23 = 0;
  this->m_maxList = (hkpMoppDefaultSplitter::hkpMoppMaxList *)&v23;
  v26 = 0i64;
  v17 = hkpMoppDefaultSplitter::split(this, 0i64, &params, HK_MOPP_DS_LEFT, 0);
  ((void (__fastcall *)(hkpMoppAssembler *, hkpMoppTreeNode *, hkpMoppDefaultSplitter *, _QWORD))assembler->vfptr[2].__first_virtual_table_function__)(
    assembler,
    v17,
    this,
    (unsigned int)(2 * v12));
  v18 = v25;
  this->m_maxList = 0i64;
  this->m_planeDirections = 0i64;
  this->m_numPlaneDirections = 0;
  v19 = v24;
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v20[10] + 16i64))(v20[10], v18, (unsigned int)(8 * v19));
  return v17;
}

