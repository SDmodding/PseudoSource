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
void __fastcall hkpMoppDefaultSplitter::findSplittingPlanePositions(hkpMoppDefaultSplitter *this, hkpMoppBasicNode *node, hkpMoppSplittingPlaneDirection *plane, hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *params, hkpMoppExtent *extents, int treeDepth)
{
  int v6; // er15
  int v7; // er12
  hkpMoppSplittingPlaneDirection *v8; // r13
  hkpMoppBasicNode *v9; // rbx
  float v10; // xmm0_4
  int v11; // edx
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *v12; // r14
  hkpMoppDefaultSplitter *v13; // rsi
  int v14; // ebp
  float v15; // xmm6_4
  unsigned int v16; // er8
  unsigned int v17; // er9
  float v18; // xmm15_4
  float v19; // xmm11_4
  hkpMoppSplitter::hkpMoppSplitParams *v20; // rax
  int v21; // edi
  unsigned int v22; // edx
  float v23; // xmm12_4
  unsigned int v24; // eax
  hkpMoppDefaultSplitter::hkpMoppMaxList *v25; // r8
  signed __int64 i; // rdx
  hkpMoppCompilerPrimitive **v27; // rcx
  hkpMoppSplitter::hkpMoppSplitParams *v28; // rax
  float v29; // xmm3_4
  float *v30; // r10
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
  int v41; // er9
  float v42; // xmm10_4
  int v43; // er11
  hkpMoppCompilerPrimitive *v44; // rax
  float v45; // xmm6_4
  int v46; // edx
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

  v6 = treeDepth;
  v7 = this->m_optimalDepth;
  v8 = plane;
  v9 = node;
  v10 = (float)params->m_numPrimitives;
  v11 = params->m_maxPrimitiveSplits;
  v12 = params;
  v13 = this;
  v14 = 0;
  treeDeptha = SLODWORD(extents->m_min);
  v16 = params->m_primitives->m_primitiveID;
  extentsa = extents->m_max;
  v15 = extentsa;
  v17 = params->m_primitives->m_primitiveID;
  v18 = 1.0 / v10;
  v19 = *(float *)&FLOAT_1_0;
  if ( (float)(extentsa - *(float *)&treeDeptha) >= 0.001 )
    v19 = 1.0 / (float)(extentsa - *(float *)&treeDeptha);
  v20 = this->m_compileParams;
  v21 = 0;
  if ( v11 > v20->m_maxPrimitiveSplitsPerNode )
    v11 = v20->m_maxPrimitiveSplitsPerNode;
  v62 = v11;
  while ( v21 < v12->m_numPrimitives )
  {
    v22 = v12->m_primitives[v21].m_primitiveID;
    v23 = v12->m_primitives[v21].m_extent.m_min;
    v24 = v12->m_primitives[v21].m_primitiveID;
    if ( v16 < v22 )
      v24 = v16;
    if ( v17 > v22 )
      v22 = v17;
    v60 = v24;
    v61 = v22;
    hkpMoppDefaultSplitter::hkpMoppMaxList::removeElementsLessThan(
      v13->m_maxList,
      v12->m_primitives[v21].m_extent.m_min);
    v25 = v13->m_maxList;
    for ( i = v25->m_currentNumElements - 1; i > v62; --v25->m_currentNumElements )
    {
      v27 = v25->buffer;
      v25->lastRemovedElement = v27[--i + 1];
      v27[i + 1] = 0i64;
    }
    v28 = v13->m_compileParams;
    v29 = *(float *)&treeDeptha;
    v30 = (float *)v13->m_costFunction;
    v31 = (float)(v15 + *(float *)&treeDeptha) * 0.5;
    if ( v6 >= v7 )
    {
      v33 = v19;
    }
    else
    {
      v32 = fminf(v30[9], v15 - *(float *)&treeDeptha) + (float)(v15 - *(float *)&treeDeptha);
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
    v34 = v33 * (float)(v23 - v31);
    if ( v34 >= 0.0 )
    {
      v36 = v34 * v34;
      v35 = (float)((float)((float)(v36 * 2.9000001) + (float)((float)(v36 * v36) * 3.0))
                  + (float)((float)((float)(v36 * v36) * (float)(v36 * v36)) * 1500.0))
          * v30[7];
    }
    else
    {
      v35 = 0.0;
    }
    if ( (signed int)(v61 - v60) >= 16 )
      v37 = 0.0;
    else
      v37 = v30[8] * -0.029999999;
    v38 = v13->m_maxList;
    v39 = FLOAT_1_0e7;
    v40 = 0;
    v41 = 0;
    v42 = (float)(v8->m_cost + v35) + v37;
    v43 = v28->m_minRangeMaxListCheck >> 1;
    if ( v38->m_currentNumElements )
    {
      if ( v42 > v9->m_bestOverallCost )
        goto LABEL_61;
      if ( v28->m_checkAllEveryN <= 0 )
      {
        v46 = v38->m_currentNumElements;
      }
      else
      {
        v46 = v43 + v14;
        if ( v43 + v14 > v38->m_currentNumElements )
          v46 = v38->m_currentNumElements;
        v41 = v14 - v43;
        if ( v14 - v43 < 0 )
          v41 = 0;
      }
      v40 = v46 - 1;
      while ( 2 )
      {
        if ( v40 < v41 )
        {
          v15 = extentsa;
          --v14;
          goto LABEL_61;
        }
        v47 = v13->m_maxList;
        if ( v40 > v47->m_currentNumElements )
          v48 = 0i64;
        else
          v48 = v47->buffer[v40];
        v45 = v48->m_extent.m_max;
LABEL_40:
        if ( v6 >= v7 )
        {
          v50 = v19;
        }
        else
        {
          v49 = fminf(v30[9], extentsa - v29) + (float)(extentsa - v29);
          if ( v49 <= 0.0 )
            v50 = FLOAT_3_4028202e37;
          else
            v50 = 1.0 / v49;
        }
        v51 = v50 * (float)(v45 - v31);
        if ( v51 <= 0.0 )
        {
          v53 = v51 * v51;
          v52 = (float)((float)((float)(v53 * 2.9000001) + (float)((float)(v53 * v53) * 3.0))
                      + (float)((float)((float)(v53 * v53) * (float)(v53 * v53)) * 1500.0))
              * v30[7];
        }
        else
        {
          v52 = 0.0;
        }
        v54 = COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT((float)(v21 - (v40 + v12->m_numPrimitives - v21)))) >> 1)
            * v18;
        if ( v6 >= v7 )
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
            v57 = (float)((float)((float)(v56 + v52) + (float)((float)((float)((float)v40 * v18) * 5.0) * v30[4]))
                        + (float)((float)((float)(v45 - v23) * v19) * v30[5]))
                + v42;
            if ( v57 >= v39
              || (v39 = v57, v14 = v40, v57 >= v9->m_bestOverallCost)
              || (v9->m_bestOverallCost = v57,
                  v9->m_planeRightPosition = v23,
                  v9->m_plane = v8,
                  v9->m_planeLeftPosition = v45,
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
      v56 = (float)((float)((float)(v55 * v55) * v55) * v55) * v30[6];
      goto LABEL_53;
    }
    v44 = v38->lastRemovedElement;
    if ( v44 )
    {
      v45 = v44->m_extent.m_max;
      goto LABEL_40;
    }
LABEL_61:
    hkpMoppDefaultSplitter::hkpMoppMaxList::addElement(v13->m_maxList, &v12->m_primitives[v21]);
    v16 = v60;
    v17 = v61;
    ++v21;
  }
  v58 = v13->m_maxList;
  for ( j = v58->m_currentNumElements - 1; j > 0; v58->buffer[--j + 1] = 0i64 )
    ;
  v58->m_currentNumElements = 0;
  v58->lastRemovedElement = 0i64;
}

// File Line: 277
// RVA: 0xDFA640
void __fastcall hkpMoppDefaultSplitter::sortLeftAndRight(hkpMoppDefaultSplitter *this, int switchPosition, hkpMoppBasicNode *bestNode, int depth, int *maxSplits, int *numSplits, hkpMoppCompilerPrimitive **beginUnsorted, hkpMoppCompilerPrimitive **endUnsorted, hkpMoppCompilerPrimitive **beginRight, hkpMoppCompilerPrimitive **beginMiddle)
{
  hkpMoppDefaultSplitter *v10; // rbp
  int v11; // edx
  int v12; // edx
  hkpMoppSplittingPlaneDirection *v13; // rbx
  hkpMoppCompilerPrimitive *v14; // ST28_8
  float v15; // xmm6_4
  hkpMoppMediator *v16; // rcx
  hkpMoppCompilerPrimitive *v17; // rdx
  hkpMoppCompilerPrimitive *v18; // rbx
  hkpMoppCompilerPrimitive *v19; // r11
  hkpMoppCompilerPrimitive *v20; // r10
  unsigned int v21; // ecx
  unsigned int v22; // edx
  float v23; // er8
  float v24; // er9
  unsigned int v25; // er10
  hkpMoppCompilerPrimitive *v26; // rax
  unsigned int v27; // er8
  unsigned int v28; // er9
  float v29; // er10
  float v30; // er11
  unsigned int v31; // ebx
  unsigned int v32; // ebp
  float v33; // er12
  float v34; // er13
  hkpMoppCompilerPrimitive *v35; // rdx
  unsigned int v36; // er15
  hkpMoppCompilerPrimitive *v37; // rcx
  hkpMoppCompilerPrimitive *v38; // rax
  hkpMoppCompilerPrimitive *v39; // rax
  __m128 v40; // [rsp+30h] [rbp-48h]
  unsigned int v41; // [rsp+88h] [rbp+10h]

  v10 = this;
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
          v13 = bestNode->m_plane;
          v14 = *beginRight;
          v15 = (float)(bestNode->m_planeLeftPosition + bestNode->m_planeRightPosition) * 0.5;
          ((void (__fastcall *)(hkpMoppMediator *, hkpMoppCompilerPrimitive *, hkpMoppSplittingPlaneDirection *))this->m_mediator->vfptr[4].__vecDelDtor)(
            this->m_mediator,
            *beginUnsorted,
            bestNode->m_plane);
          v16 = v10->m_mediator;
          v17 = *beginUnsorted;
          v40 = _mm_xor_ps(
                  (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                  v13->m_direction.m_quad);
          ((void (__fastcall *)(hkpMoppMediator *, hkpMoppCompilerPrimitive *, __m128 *))v16->vfptr[4].__vecDelDtor)(
            v16,
            v17,
            &v40);
          ++*beginUnsorted;
        }
      }
      else
      {
        --*beginRight;
        --*endUnsorted;
        v18 = *beginUnsorted;
        v19 = *beginRight;
        v20 = *endUnsorted;
        if ( *beginUnsorted != *beginRight )
        {
          v21 = v20->m_primitiveID;
          v22 = v20->m_primitiveID2;
          v23 = v20->m_extent.m_min;
          v24 = v20->m_extent.m_max;
          v25 = v20->m_origPrimitiveID;
          v19->m_primitiveID = v18->m_primitiveID;
          v19->m_primitiveID2 = v18->m_primitiveID2;
          v19->m_extent.m_min = v18->m_extent.m_min;
          v19->m_extent.m_max = v18->m_extent.m_max;
          v19->m_origPrimitiveID = v18->m_origPrimitiveID;
          v26 = *beginUnsorted;
          v26->m_primitiveID = v21;
          v26->m_primitiveID2 = v22;
          v26->m_extent.m_min = v23;
          v26->m_extent.m_max = v24;
          v26->m_origPrimitiveID = v25;
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
    v27 = (*beginUnsorted)->m_primitiveID;
    v28 = (*beginUnsorted)->m_primitiveID2;
    v29 = (*beginUnsorted)->m_extent.m_min;
    v30 = (*beginUnsorted)->m_extent.m_max;
    v31 = (*beginUnsorted)->m_origPrimitiveID;
    v32 = (*endUnsorted)->m_primitiveID;
    v33 = (*endUnsorted)->m_extent.m_min;
    v34 = (*endUnsorted)->m_extent.m_max;
    v35 = *beginRight;
    v41 = (*endUnsorted)->m_origPrimitiveID;
    v36 = (*endUnsorted)->m_primitiveID2;
    v37 = *beginMiddle;
    v35->m_primitiveID = (*beginMiddle)->m_primitiveID;
    v35->m_primitiveID2 = v37->m_primitiveID2;
    v35->m_extent.m_min = v37->m_extent.m_min;
    v35->m_extent.m_max = v37->m_extent.m_max;
    v35->m_origPrimitiveID = v37->m_origPrimitiveID;
    v38 = *beginMiddle;
    v38->m_primitiveID = v27;
    v38->m_primitiveID2 = v28;
    v38->m_extent.m_min = v29;
    v38->m_extent.m_max = v30;
    v38->m_origPrimitiveID = v31;
    v39 = *beginUnsorted;
    if ( *beginUnsorted != *endUnsorted )
    {
      v39->m_primitiveID = v32;
      v39->m_primitiveID2 = v36;
      v39->m_extent.m_min = v33;
      v39->m_extent.m_max = v34;
      v39->m_origPrimitiveID = v41;
    }
  }
}

// File Line: 368
// RVA: 0xDFA2B0
void __fastcall hkpMoppDefaultSplitter::distributeMiddle(hkpMoppDefaultSplitter *this, hkpMoppCompilerPrimitive **startLeft, hkpMoppCompilerPrimitive **endLeft, hkpMoppCompilerPrimitive **startRight, hkpMoppCompilerPrimitive **endRight, hkpMoppCompilerPrimitive **startMiddle, hkpMoppCompilerPrimitive **endMiddle, hkpMoppBasicNode *bestNode)
{
  hkpMoppCompilerPrimitive **v8; // r14
  hkpMoppCompilerPrimitive **v9; // r12
  hkpMoppCompilerPrimitive **v10; // r13
  hkpMoppCompilerPrimitive **v11; // rsi
  hkpMoppCompilerPrimitive **v12; // rdi
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rbx
  signed int v15; // er8
  float v16; // xmm1_4
  int v17; // edx
  hkpMoppCompilerPrimitive *v18; // r10
  bool i; // cl
  unsigned __int64 v20; // r9
  unsigned __int64 v21; // rdx
  hkpMoppCompilerPrimitive *v22; // rcx
  float v23; // edi
  float v24; // esi
  unsigned int v25; // ebp
  unsigned int v26; // er11
  unsigned int v27; // ebx
  unsigned int v28; // edx
  float v29; // er8
  float v30; // er9
  unsigned int v31; // er10
  hkpMoppCompilerPrimitive *v32; // rax
  hkpMoppCompilerPrimitive *v33; // rax
  hkpMoppCompilerPrimitive **v34; // [rsp+88h] [rbp+10h]
  hkpMoppCompilerPrimitive **v35; // [rsp+90h] [rbp+18h]

  v35 = endLeft;
  v34 = startLeft;
  v8 = startMiddle;
  v9 = endMiddle;
  v10 = startRight;
  v11 = startLeft;
  v12 = endLeft;
  v13 = (unsigned __int128)(((char *)*endMiddle - (char *)*startMiddle) * (signed __int128)7378697629483820647i64) >> 64;
  v14 = (v13 >> 63) + ((signed __int64)v13 >> 3);
  if ( v14 )
  {
    v15 = 0;
    v16 = 0.0;
    v17 = bestNode->m_plane->m_index;
    if ( v17 && (float)(bestNode->m_extents.m_extent[0].m_max - bestNode->m_extents.m_extent[0].m_min) > 0.0 )
      v16 = bestNode->m_extents.m_extent[0].m_max - bestNode->m_extents.m_extent[0].m_min;
    if ( v17 != 1 && (float)(bestNode->m_extents.m_extent[1].m_max - bestNode->m_extents.m_extent[1].m_min) > v16 )
    {
      v16 = bestNode->m_extents.m_extent[1].m_max - bestNode->m_extents.m_extent[1].m_min;
      v15 = 1;
    }
    if ( v17 != 2 && (float)(bestNode->m_extents.m_extent[2].m_max - bestNode->m_extents.m_extent[2].m_min) > v16 )
      v15 = 2;
    this->m_mediator->vfptr[3].__vecDelDtor(
      (hkBaseObject *)this->m_mediator,
      (unsigned int)&this->m_planeDirections[v15]);
    if ( (signed int)v14 > 1 )
      hkAlgorithm::quickSortRecursive<hkpMoppCompilerPrimitive,hkAlgorithm::less<hkpMoppCompilerPrimitive>>(
        *v8,
        0,
        v14 - 1,
        0);
    v18 = *v9;
    for ( i = (signed __int64)(((unsigned __int64)((unsigned __int128)(((char *)*v12 - (char *)*v11)
                                                                     * (signed __int128)7378697629483820647i64) >> 64) >> 63)
                             + ((signed __int64)((unsigned __int128)(((char *)*v12 - (char *)*v11)
                                                                   * (signed __int128)7378697629483820647i64) >> 64) >> 3)) < (signed __int64)(((unsigned __int64)((unsigned __int128)(((char *)*endRight - (char *)*v10) * (signed __int128)7378697629483820647i64) >> 64) >> 63) + ((signed __int64)((unsigned __int128)(((char *)*endRight - (char *)*v10) * (signed __int128)7378697629483820647i64) >> 64) >> 3));
          *v8 < *v9;
          v18 = *v9 )
    {
      v20 = ((unsigned __int64)((unsigned __int128)(((char *)*v12 - (char *)*v11)
                                                  * (signed __int128)7378697629483820647i64) >> 64) >> 63)
          + ((signed __int64)((unsigned __int128)(((char *)*v12 - (char *)*v11) * (signed __int128)7378697629483820647i64) >> 64) >> 3);
      v21 = ((unsigned __int64)((unsigned __int128)(((char *)*endRight - (char *)*v10)
                                                  * (signed __int128)7378697629483820647i64) >> 64) >> 63)
          + ((signed __int64)((unsigned __int128)(((char *)*endRight - (char *)*v10)
                                                * (signed __int128)7378697629483820647i64) >> 64) >> 3);
      if ( i )
        LODWORD(v21) = 4 * v21;
      else
        LODWORD(v20) = 4 * v20;
      if ( (signed int)v20 >= (signed int)v21 )
      {
        ++*endRight;
        ++*v8;
        i = 0;
      }
      else
      {
        v22 = *v8;
        v23 = v18[-1].m_extent.m_min;
        v24 = v18[-1].m_extent.m_max;
        v25 = v18[-1].m_origPrimitiveID;
        v26 = v18[-1].m_primitiveID;
        v27 = v18[-1].m_primitiveID2;
        v18[-1].m_primitiveID = (*v8)->m_primitiveID;
        v9 = endMiddle;
        v18[-1].m_primitiveID2 = v22->m_primitiveID2;
        v18[-1].m_extent.m_min = v22->m_extent.m_min;
        v18[-1].m_extent.m_max = v22->m_extent.m_max;
        v18[-1].m_origPrimitiveID = v22->m_origPrimitiveID;
        LODWORD(v22) = (*v10)->m_primitiveID;
        v28 = (*v10)->m_primitiveID2;
        v29 = (*v10)->m_extent.m_min;
        v30 = (*v10)->m_extent.m_max;
        v31 = (*v10)->m_origPrimitiveID;
        v32 = *v35;
        v32->m_primitiveID = v26;
        v32->m_primitiveID2 = v27;
        v32->m_extent.m_min = v23;
        v12 = v35;
        v32->m_extent.m_max = v24;
        v11 = v34;
        v32->m_origPrimitiveID = v25;
        v33 = *v8;
        v33->m_primitiveID = (unsigned int)v22;
        v33->m_primitiveID2 = v28;
        v33->m_extent.m_min = v29;
        v33->m_extent.m_max = v30;
        v33->m_origPrimitiveID = v31;
        ++*v12;
        ++*v10;
        ++*v8;
        ++*endRight;
        i = 1;
      }
    }
  }
}

// File Line: 456
// RVA: 0xDF9C80
void __usercall hkpMoppDefaultSplitter::groupPrimitives(hkpMoppDefaultSplitter *this@<rcx>, hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *in@<rdx>, hkpMoppBasicNode *bestNode@<r8>, int depth@<r9d>, __int64 a5@<rdi>, hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *leftOut, hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *rightOut)
{
  int v7; // edi
  hkpMoppDefaultSplitter *v8; // rsi
  int v9; // er14
  __int64 v10; // r9
  hkpMoppCompilerPrimitive *v11; // r15
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *v12; // r12
  hkpMoppBasicNode *v13; // rbx
  hkpMoppCompilerPrimitive *v14; // rcx
  hkpMoppCompilerPrimitive *v15; // rax
  int v16; // edx
  hkpMoppCompilerPrimitive **v17; // r10
  hkpMoppCompilerPrimitive *v18; // r11
  signed int v19; // edx
  __int64 v20; // rax
  bool v21; // zf
  signed __int64 v22; // rdx
  unsigned int v23; // eax
  hkpMoppCompilerPrimitive **beginRight; // [rsp+40h] [rbp-19h]
  hkpMoppCompilerPrimitive **beginMiddle; // [rsp+48h] [rbp-11h]
  hkpMoppCompilerPrimitive *startMiddle; // [rsp+50h] [rbp-9h]
  hkpMoppCompilerPrimitive *startRight; // [rsp+58h] [rbp-1h]
  hkpMoppCompilerPrimitive *beginUnsorted; // [rsp+60h] [rbp+7h]
  hkpMoppCompilerPrimitive *endMiddle; // [rsp+68h] [rbp+Fh]
  hkpMoppCompilerPrimitive *startLeft; // [rsp+70h] [rbp+17h]
  hkpMoppCompilerPrimitive *maxSplits; // [rsp+B8h] [rbp+5Fh]
  __int64 v32; // [rsp+D0h] [rbp+77h]
  __int64 v33; // [rsp+D8h] [rbp+7Fh]

  v32 = a5;
  v7 = in->m_maxPrimitiveSplits;
  v8 = this;
  v9 = depth;
  v10 = in->m_numPrimitives;
  v11 = in->m_primitives;
  v12 = in;
  v13 = bestNode;
  LODWORD(maxSplits) = v7;
  v14 = &in->m_primitives[(signed int)v10 + v7];
  v15 = v11;
  LODWORD(beginRight) = 0;
  startLeft = v11;
  beginMiddle = (hkpMoppCompilerPrimitive **)&v11[v10];
  startRight = &v11[(signed int)v10 + v7];
  startMiddle = &v11[(signed int)v10 + v7];
  endMiddle = &v11[(signed int)v10 + v7];
  beginUnsorted = v11;
  if ( v11 < (hkpMoppCompilerPrimitive *)beginMiddle )
  {
    do
    {
      if ( v13->m_planeRightPosition <= v15->m_extent.m_min )
      {
        v16 = 0;
        if ( v13->m_planeLeftPosition < v15->m_extent.m_max )
          v16 = 2;
      }
      else
      {
        v16 = 3;
        if ( v15->m_extent.m_max <= v13->m_planeLeftPosition )
          v16 = 1;
      }
      hkpMoppDefaultSplitter::sortLeftAndRight(
        v8,
        v16,
        v13,
        v9,
        (int *)&maxSplits,
        (int *)&beginRight,
        &beginUnsorted,
        (hkpMoppCompilerPrimitive **)&beginMiddle,
        &startRight,
        &startMiddle);
      v15 = beginUnsorted;
    }
    while ( beginUnsorted < (hkpMoppCompilerPrimitive *)beginMiddle );
    v7 = (signed int)maxSplits;
    v14 = startMiddle;
  }
  maxSplits = v14;
  hkpMoppDefaultSplitter::distributeMiddle(
    v8,
    &startLeft,
    (hkpMoppCompilerPrimitive **)&beginMiddle,
    &startRight,
    &maxSplits,
    &startMiddle,
    &endMiddle,
    v13);
  v17 = beginMiddle;
  v18 = startRight;
  v19 = ((unsigned __int64)((unsigned __int128)(((char *)beginMiddle - (char *)v11)
                                              * (signed __int128)7378697629483820647i64) >> 64) >> 63)
      + ((signed __int64)((unsigned __int128)(((char *)beginMiddle - (char *)v11)
                                            * (signed __int128)7378697629483820647i64) >> 64) >> 3);
  *(_DWORD *)(v32 + 8) = v19;
  *(_DWORD *)(v32 + 12) = (signed int)(float)((float)((float)v19 * (float)v7) / (float)v12->m_numPrimitives);
  *(_DWORD *)(v33 + 8) = ((unsigned __int64)((unsigned __int128)(((char *)maxSplits - (char *)v18)
                                                               * (signed __int128)7378697629483820647i64) >> 64) >> 63)
                       + ((signed __int64)((unsigned __int128)(((char *)maxSplits - (char *)v18)
                                                             * (signed __int128)7378697629483820647i64) >> 64) >> 3);
  *(_DWORD *)(v33 + 12) = v7 - *(_DWORD *)(v32 + 12);
  v20 = *(signed int *)(v32 + 12);
  *(_QWORD *)v32 = v11;
  v21 = *(_DWORD *)(v33 + 12) == 0;
  v22 = (signed __int64)v17 + 20 * v20;
  *(_QWORD *)v33 = v22;
  if ( !v21 && v18 < maxSplits )
  {
    do
    {
      v23 = v18->m_primitiveID;
      ++v18;
      v22 += 20i64;
      *(_DWORD *)(v22 - 20) = v23;
      *(_DWORD *)(v22 - 16) = v18[-1].m_primitiveID2;
      *(float *)(v22 - 12) = v18[-1].m_extent.m_min;
      *(float *)(v22 - 8) = v18[-1].m_extent.m_max;
      *(_DWORD *)(v22 - 4) = v18[-1].m_origPrimitiveID;
    }
    while ( v18 < maxSplits );
  }
}

// File Line: 516
// RVA: 0xDFA1D0
void __fastcall hkpMoppDefaultSplitter::calculateMaxMinId(hkpMoppDefaultSplitter *this, hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *params, hkpMoppTreeNode *node)
{
  hkpMoppCompilerPrimitive *v3; // rdi
  hkpMoppTreeNode *v4; // rbx
  unsigned int v5; // ebp
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *v6; // r12
  int v7; // esi
  hkpMoppDefaultSplitter *v8; // r13
  unsigned int i; // er14
  int v10; // eax
  unsigned int *v11; // rcx
  __int64 v12; // rdx
  unsigned int v13; // eax
  int v14; // eax
  char v15[8]; // [rsp+58h] [rbp+10h]

  v3 = params->m_primitives;
  v4 = node;
  v5 = params->m_primitives->m_primitiveID;
  node->m_numProperties = 0;
  node->m_minPropertyValue[0] = -1;
  node->m_maxPropertyValue[0] = 0;
  v6 = params;
  v7 = params->m_numPrimitives - 1;
  v8 = this;
  for ( i = v5; v7 >= 0; --v7 )
  {
    if ( v3->m_primitiveID > i )
      i = v3->m_primitiveID;
    if ( v3->m_primitiveID < v5 )
      v5 = v3->m_primitiveID;
    v10 = ((__int64 (__fastcall *)(hkpMoppMediator *, hkpMoppCompilerPrimitive *, char *))v8->m_mediator->vfptr[4].__first_virtual_table_function__)(
            v8->m_mediator,
            v3,
            v15);
    if ( v10 > v4->m_numProperties )
      v4->m_numProperties = v10;
    if ( v10 > 0 )
    {
      v11 = v4->m_maxPropertyValue;
      v12 = (unsigned int)v10;
      do
      {
        v13 = *(unsigned int *)((char *)v11 + v15 - (char *)v4 - 56);
        if ( v13 < *(v11 - 1) )
          *(v11 - 1) = v13;
        if ( v13 > *v11 )
          *v11 = v13;
        ++v11;
        --v12;
      }
      while ( v12 );
    }
    ++v3;
  }
  v14 = v6->m_numPrimitives;
  v4->m_minPrimitiveId = v5;
  v4->m_numPrimitives = v14;
  v4->m_maxPrimitiveId = i;
}

// File Line: 575
// RVA: 0xDF8FE0
hkpFreeListElem *__fastcall hkpMoppDefaultSplitter::createTerminal(hkpMoppDefaultSplitter *this, hkpMoppTreeInternalNode *parentNode, hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *params)
{
  hkpFreeListElem *v3; // r15
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *v4; // r14
  hkpMoppDefaultSplitter *v5; // rbp
  hkpFreeListElem *v6; // rax
  signed int v7; // ebx
  signed __int64 v8; // rdi
  __int64 v9; // rsi
  __int64 v11; // [rsp+20h] [rbp-38h]

  v3 = this->m_freeTerminals.m_elems;
  v4 = params;
  v5 = this;
  v6 = v3->m_next;
  --this->m_freeTerminals.m_freeElems;
  this->m_freeTerminals.m_elems = v6;
  HIDWORD(v3[7].m_next) = 0;
  LOWORD(v3[8].m_next) = 0;
  HIDWORD(v3[8].m_next) = -1;
  LODWORD(v3[12].m_next) = -1;
  LOBYTE(v3[1].m_next) = 1;
  v3->m_next = (hkpFreeListElem *)parentNode;
  v3[13].m_next = (hkpFreeListElem *)params->m_primitives;
  hkpMoppDefaultSplitter::calculateMaxMinId(this, params, (hkpMoppTreeNode *)v3);
  v7 = 0;
  v8 = (signed __int64)&v3[2];
  v9 = 0i64;
  do
  {
    LODWORD(v11) = v4->m_numPrimitives;
    ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, _QWORD, hkpMoppCompilerPrimitive *, __int64, signed __int64, signed __int64))v5->m_mediator->vfptr[3].__first_virtual_table_function__)(
      v5->m_mediator,
      &v5->m_planeDirections[v9],
      (unsigned int)v7++,
      v4->m_primitives,
      v11,
      v8,
      v8 + 4);
    v8 += 8i64;
    ++v9;
  }
  while ( v7 < 3 );
  return v3;
}

// File Line: 597
// RVA: 0xDF8F80
hkpFreeListElem *__fastcall hkpMoppDefaultSplitter::createNode(hkpMoppDefaultSplitter *this)
{
  hkpFreeListElem *v1; // rdx
  hkpFreeListElem *v2; // rax

  v1 = this->m_freeNodes.m_elems;
  v2 = v1->m_next;
  --this->m_freeNodes.m_freeElems;
  this->m_freeNodes.m_elems = v2;
  HIDWORD(v1[7].m_next) = 0;
  LOWORD(v1[8].m_next) = 0;
  HIDWORD(v1[8].m_next) = -1;
  LODWORD(v1[12].m_next) = -1;
  LOBYTE(v1[1].m_next) = 0;
  LODWORD(v1[15].m_next) = 1232348160;
  LODWORD(v1[14].m_next) = 1343554297;
  v1[16].m_next = 0i64;
  v1[17].m_next = 0i64;
  v1[13].m_next = 0i64;
  return v1;
}

// File Line: 628
// RVA: 0xDF9530
void __fastcall hkpMoppDefaultSplitter::resortAxis(hkpMoppDefaultSplitter *this, hkpMoppTreeInternalNode *parentNode, int *directionsOut, float *extraCostsOut)
{
  hkpMoppSplittingPlaneDirection *v4; // rcx
  hkpMoppSplittingPlaneDirection *v5; // rbx
  float v6; // xmm5_4
  float v7; // xmm0_4
  int v8; // er10
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
    v4 = this->m_planeDirections;
    v5 = parentNode->m_plane;
    v6 = 0.0;
    v7 = parentNode->m_extents.m_extent[0].m_max - parentNode->m_extents.m_extent[0].m_min;
    v8 = 0;
    v18 = parentNode->m_extents.m_extent[0].m_max - parentNode->m_extents.m_extent[0].m_min;
    if ( v5 == v4 )
    {
      v7 = v7 * 0.66000003;
      v18 = v7;
    }
    if ( v7 > 0.0 )
      v6 = v7;
    v9 = parentNode->m_extents.m_extent[1].m_max - parentNode->m_extents.m_extent[1].m_min;
    v19 = parentNode->m_extents.m_extent[1].m_max - parentNode->m_extents.m_extent[1].m_min;
    if ( v5 == &v4[1] )
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
    v20 = parentNode->m_extents.m_extent[2].m_max - parentNode->m_extents.m_extent[2].m_min;
    if ( v5 == &v4[2] )
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
hkpFreeListElem *__fastcall hkpMoppDefaultSplitter::split(hkpMoppDefaultSplitter *this, hkpMoppTreeInternalNode *parentNode, hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *params, hkpMoppDefaultSplitter::hkpMoppDsSide side, int depth)
{
  hkpMoppSplitter::hkpMoppSplitParams *v5; // rax
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray *v6; // rbx
  hkpMoppTreeInternalNode *v7; // rbp
  hkpMoppDefaultSplitter *v8; // rdi
  hkpFreeListElem *result; // rax
  hkpFreeListElem *v10; // rax
  hkpMoppTreeInternalNode *v11; // rsi
  hkpMoppExtent v12; // rax
  int v13; // ecx
  __int64 v14; // r8
  __int64 v15; // rdx
  hkpMoppSplittingPlaneDirection *v16; // rbp
  hkpMoppMediator *v17; // rcx
  hkpMoppCompilerPrimitive *v18; // r9
  hkBaseObjectVtbl *v19; // r10
  signed int v20; // er8
  signed __int64 i; // rbp
  int v22; // edx
  hkpMoppExtent *v23; // rcx
  hkpMoppSplittingPlaneDirection *v24; // rbp
  signed int v25; // er8
  hkpMoppSplittingPlaneDirection *v26; // rdx
  int v27; // ebp
  hkpMoppTreeNode *v28; // rax
  bool v29; // zf
  hkpMoppExtent *extents; // [rsp+20h] [rbp-298h]
  hkpMoppExtent v31; // [rsp+40h] [rbp-278h]
  hkpMoppSplittingPlaneDirection *v32; // [rsp+48h] [rbp-270h]
  hkpMoppExtent *v33; // [rsp+50h] [rbp-268h]
  int directionsOut[4]; // [rsp+58h] [rbp-260h]
  hkErrStream extraCostsOut; // [rsp+68h] [rbp-250h]
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray paramsa; // [rsp+80h] [rbp-238h]
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray leftOut; // [rsp+90h] [rbp-228h]
  char buf; // [rsp+A0h] [rbp-218h]
  int v39; // [rsp+2D0h] [rbp+18h]
  hkpMoppDefaultSplitter::hkpMoppDsSide v40; // [rsp+2D8h] [rbp+20h]

  v40 = side;
  v5 = this->m_compileParams;
  v6 = params;
  v7 = parentNode;
  v8 = this;
  if ( params->m_numPrimitives == 1 )
  {
    if ( v5->m_interleavedBuildingEnabled.m_bool )
    {
      if ( !this->m_freeTerminals.m_freeElems )
        ((void (__fastcall *)(hkpMoppAssembler *, hkpMoppTreeInternalNode *, hkpMoppDefaultSplitter *, signed __int64))this->m_assembler->vfptr[2].__first_virtual_table_function__)(
          this->m_assembler,
          this->m_rootNode,
          this,
          2048i64);
    }
    result = hkpMoppDefaultSplitter::createTerminal(v8, v7, v6);
  }
  else
  {
    if ( v5->m_interleavedBuildingEnabled.m_bool && !this->m_freeNodes.m_freeElems )
      ((void (__fastcall *)(hkpMoppAssembler *, hkpMoppTreeInternalNode *, hkpMoppDefaultSplitter *, signed __int64))this->m_assembler->vfptr[2].__first_virtual_table_function__)(
        this->m_assembler,
        this->m_rootNode,
        this,
        2048i64);
    v10 = hkpMoppDefaultSplitter::createNode(v8);
    LODWORD(v10[18].m_next) = v6->m_numPrimitives;
    v10->m_next = (hkpFreeListElem *)v7;
    v11 = (hkpMoppTreeInternalNode *)v10;
    if ( v7 )
    {
      if ( v40 )
        v7->m_rightBranch = (hkpMoppTreeNode *)v10;
      else
        v7->m_leftBranch = (hkpMoppTreeNode *)v10;
      *(float *)&v10[2].m_next = v7->m_extents.m_extent[0].m_min;
      HIDWORD(v10[2].m_next) = LODWORD(v7->m_extents.m_extent[0].m_max);
      *(float *)&v10[3].m_next = v7->m_extents.m_extent[1].m_min;
      HIDWORD(v10[3].m_next) = LODWORD(v7->m_extents.m_extent[1].m_max);
      *(float *)&v10[4].m_next = v7->m_extents.m_extent[2].m_min;
      HIDWORD(v10[4].m_next) = LODWORD(v7->m_extents.m_extent[2].m_max);
    }
    else
    {
      v8->m_rootNode = (hkpMoppTreeInternalNode *)v10;
    }
    v32 = 0i64;
    hkpMoppDefaultSplitter::resortAxis(v8, v7, directionsOut, (float *)&extraCostsOut);
    v12 = 0i64;
    v13 = 0;
    v39 = 0;
    v31 = 0i64;
    do
    {
      v14 = *(int *)((char *)directionsOut + *(_QWORD *)&v12);
      v15 = *(int *)((char *)directionsOut + *(_QWORD *)&v12);
      v16 = &v8->m_planeDirections[v14];
      if ( (float)(*(float *)((char *)&extraCostsOut.vfptr + *(_QWORD *)&v12) + v16->m_cost) > v11->m_bestOverallCost )
        break;
      v17 = v8->m_mediator;
      v18 = v6->m_primitives;
      v19 = v17->vfptr;
      v33 = (hkpMoppExtent *)((char *)v11 + 8 * (v15 + 2));
      LODWORD(extents) = v6->m_numPrimitives;
      ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, __int64, hkpMoppCompilerPrimitive *, hkpMoppExtent *, signed __int64, float *))v19[3].__vecDelDtor)(
        v17,
        v16,
        v14,
        v18,
        extents,
        (signed __int64)v11 + 8 * (v15 + 2),
        &v33->m_max);
      v20 = v6->m_numPrimitives;
      if ( v20 > 1 )
        hkAlgorithm::quickSortRecursive<hkpMoppCompilerPrimitive,hkAlgorithm::less<hkpMoppCompilerPrimitive>>(
          v6->m_primitives,
          0,
          v20 - 1,
          0);
      v32 = v16;
      hkpMoppDefaultSplitter::findSplittingPlanePositions(v8, (hkpMoppBasicNode *)&v11->m_parent, v16, v6, v33, depth);
      if ( !v11->m_plane )
      {
        hkErrStream::hkErrStream(&extraCostsOut, &buf, 512);
        hkOstream::operator<<((hkOstream *)&extraCostsOut.vfptr, "Could not find splitting plane for child");
        hkError::messageWarning(-1413864636, &buf, "Collide\\Mopp\\Builder\\Splitter\\hkpMoppDefaultSplitter.cpp", 773);
        hkOstream::~hkOstream((hkOstream *)&extraCostsOut.vfptr);
        goto LABEL_35;
      }
      v12 = (hkpMoppExtent)(*(_QWORD *)&v31 + 4i64);
      v13 = v39++ + 1;
      v31 = v12;
    }
    while ( *(signed __int64 *)&v12 < 12 );
    for ( i = v13; i < 3; ++i )
    {
      LODWORD(extents) = v6->m_numPrimitives;
      ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, _QWORD, hkpMoppCompilerPrimitive *, hkpMoppExtent *, hkpMoppExtent *, float *))v8->m_mediator->vfptr[3].__first_virtual_table_function__)(
        v8->m_mediator,
        &v8->m_planeDirections[directionsOut[i]],
        directionsOut[i],
        v6->m_primitives,
        extents,
        &v11->m_extents.m_extent[directionsOut[i]],
        &v11->m_extents.m_extent[directionsOut[i]].m_max);
    }
    v22 = 3;
    v39 = 3;
    if ( v8->m_numPlaneDirections > 3 )
    {
      v23 = (hkpMoppExtent *)96;
      v33 = (hkpMoppExtent *)96;
      do
      {
        v24 = (hkpMoppSplittingPlaneDirection *)((char *)v23 + (unsigned __int64)v8->m_planeDirections);
        if ( v11->m_bestOverallCost < v24->m_cost )
          break;
        LODWORD(extents) = v6->m_numPrimitives;
        ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, _QWORD, hkpMoppCompilerPrimitive *, hkpMoppExtent *, hkpMoppExtent *, float *))v8->m_mediator->vfptr[3].__vecDelDtor)(
          v8->m_mediator,
          v24,
          (unsigned int)v22,
          v6->m_primitives,
          extents,
          &v31,
          &v31.m_max);
        v25 = v6->m_numPrimitives;
        if ( v25 > 1 )
          hkAlgorithm::quickSortRecursive<hkpMoppCompilerPrimitive,hkAlgorithm::less<hkpMoppCompilerPrimitive>>(
            v6->m_primitives,
            0,
            v25 - 1,
            0);
        v32 = v24;
        hkpMoppDefaultSplitter::findSplittingPlanePositions(
          v8,
          (hkpMoppBasicNode *)&v11->m_parent,
          v24,
          v6,
          &v31,
          depth);
        v22 = v39 + 1;
        v23 = v33 + 4;
        v39 = v22;
        v33 += 4;
      }
      while ( v22 < v8->m_numPlaneDirections );
    }
    hkpMoppDefaultSplitter::calculateMaxMinId(v8, v6, (hkpMoppTreeNode *)&v11->m_parent);
    v26 = v11->m_plane;
    if ( v32 != v26 )
    {
      LODWORD(extents) = v6->m_numPrimitives;
      ((void (__fastcall *)(hkpMoppMediator *, hkpMoppSplittingPlaneDirection *, _QWORD, hkpMoppCompilerPrimitive *, hkpMoppExtent *, hkpMoppSplittingPlaneDirection **, int *))v8->m_mediator->vfptr[3].__vecDelDtor)(
        v8->m_mediator,
        v26,
        (unsigned int)v26->m_index,
        v6->m_primitives,
        extents,
        &v32,
        &v39);
    }
    v27 = depth;
    hkpMoppDefaultSplitter::groupPrimitives(v8, v6, (hkpMoppBasicNode *)&v11->m_parent, depth, &leftOut, &paramsa);
    v11->m_rightBranch = hkpMoppDefaultSplitter::split(v8, v11, &paramsa, HK_MOPP_DS_RIGHT, v27 + 1);
    v28 = hkpMoppDefaultSplitter::split(v8, v11, &leftOut, 0, v27 + 1);
    v29 = v11->m_rightBranch == 0i64;
    v11->m_leftBranch = v28;
    if ( !v29 && v28 )
      return (hkpFreeListElem *)v11;
LABEL_35:
    v11->m_parent = (hkpMoppTreeInternalNode *)v8->m_freeNodes.m_elems;
    ++v8->m_freeNodes.m_freeElems;
    result = 0i64;
    v8->m_freeNodes.m_elems = (hkpFreeListElem *)v11;
  }
  return result;
}

// File Line: 843
// RVA: 0xDF8F40
void __fastcall hkpMoppDefaultSplitter::releaseNode(hkpMoppDefaultSplitter *this, hkpMoppTreeNode *nodeToRelease)
{
  if ( nodeToRelease )
  {
    if ( nodeToRelease->m_isTerminal.m_bool )
    {
      nodeToRelease->m_parent = (hkpMoppTreeInternalNode *)this->m_freeTerminals.m_elems;
      ++this->m_freeTerminals.m_freeElems;
      this->m_freeTerminals.m_elems = (hkpFreeListElem *)nodeToRelease;
    }
    else
    {
      nodeToRelease->m_parent = (hkpMoppTreeInternalNode *)this->m_freeNodes.m_elems;
      ++this->m_freeNodes.m_freeElems;
      this->m_freeNodes.m_elems = (hkpFreeListElem *)nodeToRelease;
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
hkpMoppTreeNode *__fastcall hkpMoppDefaultSplitter::buildTree(hkpMoppDefaultSplitter *this, hkpMoppMediator *mediator, hkpMoppCostFunction *costFunction, hkpMoppAssembler *assembler, hkpMoppSplitter::hkpMoppSplitParams *in, hkpMoppSplitter::hkpMoppScratchArea *temp)
{
  hkpMoppDefaultSplitter *v6; // rbx
  hkpMoppAssembler *v7; // r15
  unsigned int v8; // eax
  __int64 v9; // rdx
  int v10; // er10
  signed int v11; // ecx
  int v12; // er14
  hkpMoppTreeInternalNode *v13; // rcx
  hkpMoppTreeTerminal *v14; // rcx
  int v15; // edi
  _QWORD **v16; // rax
  hkpMoppTreeNode *v17; // rsi
  __int64 v18; // rdi
  int v19; // ebx
  _QWORD **v20; // rax
  hkpMoppDefaultSplitter::hkpMoppPrimitiveArray params; // [rsp+30h] [rbp-48h]
  int v23; // [rsp+40h] [rbp-38h]
  int v24; // [rsp+44h] [rbp-34h]
  __int64 v25; // [rsp+48h] [rbp-30h]
  __int64 v26; // [rsp+50h] [rbp-28h]

  this->m_mediator = mediator;
  this->m_costFunction = costFunction;
  this->m_assembler = assembler;
  this->m_compileParams = in;
  v6 = this;
  v7 = assembler;
  v8 = ((__int64 (__fastcall *)(hkpMoppMediator *))mediator->vfptr[2].__vecDelDtor)(mediator);
  v10 = in->m_maxPrimitiveSplits;
  params.m_primitives = temp->m_primitives;
  params.m_numPrimitives = v8;
  params.m_maxPrimitiveSplits = v10;
  v11 = v8;
  v6->m_optimalDepth = 0;
  if ( v8 )
  {
    LODWORD(v9) = 0;
    do
    {
      v9 = (unsigned int)(v9 + 1);
      v11 >>= 1;
    }
    while ( v11 );
    v6->m_optimalDepth = v9;
  }
  v12 = 4096;
  if ( !v6->m_compileParams->m_interleavedBuildingEnabled.m_bool )
    v12 = v10 + v8;
  v6->m_freeNodes.m_elems = 0i64;
  v6->m_freeNodes.m_freeElems = 0;
  v13 = temp->m_nodes;
  if ( v12 > 0 )
  {
    v9 = (unsigned int)v12;
    do
    {
      v13->m_parent = (hkpMoppTreeInternalNode *)v6->m_freeNodes.m_elems;
      ++v6->m_freeNodes.m_freeElems;
      v6->m_freeNodes.m_elems = (hkpFreeListElem *)v13;
      ++v13;
      --v9;
    }
    while ( v9 );
  }
  v6->m_freeTerminals.m_elems = 0i64;
  v6->m_freeTerminals.m_freeElems = 0;
  v14 = temp->m_terminals;
  if ( v12 > 0 )
  {
    v9 = (unsigned int)v12;
    do
    {
      v14->m_parent = (hkpMoppTreeInternalNode *)v6->m_freeTerminals.m_elems;
      ++v6->m_freeTerminals.m_freeElems;
      v6->m_freeTerminals.m_elems = (hkpFreeListElem *)v14;
      ++v14;
      --v9;
    }
    while ( v9 );
  }
  v6->m_numPlaneDirections = ((__int64 (__fastcall *)(hkpMoppAssembler *, __int64, _QWORD))v7->vfptr[1].__first_virtual_table_function__)(
                               v7,
                               v9,
                               v8);
  v6->m_planeDirections = (hkpMoppSplittingPlaneDirection *)((__int64 (__fastcall *)(hkpMoppAssembler *))v7->vfptr[2].__vecDelDtor)(v7);
  v15 = v6->m_compileParams->m_maxPrimitiveSplitsPerNode + 2;
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v16[10] + 8i64))(v16[10], (unsigned int)(8 * v15));
  v24 = v15;
  v23 = 0;
  v6->m_maxList = (hkpMoppDefaultSplitter::hkpMoppMaxList *)&v23;
  v26 = 0i64;
  v17 = hkpMoppDefaultSplitter::split(v6, 0i64, &params, 0, 0);
  ((void (__fastcall *)(hkpMoppAssembler *, hkpMoppTreeNode *, hkpMoppDefaultSplitter *, _QWORD))v7->vfptr[2].__first_virtual_table_function__)(
    v7,
    v17,
    v6,
    (unsigned int)(2 * v12));
  v18 = v25;
  v6->m_maxList = 0i64;
  v6->m_planeDirections = 0i64;
  v6->m_numPlaneDirections = 0;
  v19 = v24;
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v20[10] + 16i64))(v20[10], v18, (unsigned int)(8 * v19));
  return v17;
}

