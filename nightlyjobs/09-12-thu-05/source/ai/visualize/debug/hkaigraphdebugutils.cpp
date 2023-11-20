// File Line: 40
// RVA: 0xC4EF20
void __fastcall hkaiGraphDebugUtils::DebugInfo::DebugInfo(hkaiGraphDebugUtils::DebugInfo *this)
{
  *(_DWORD *)&this->m_showNodes.m_bool = 257;
  this->m_materialColors.m_capacityAndFlags = 2147483648;
  this->m_materialColors.m_data = 0i64;
  this->m_materialColors.m_size = 0;
  *(_WORD *)&this->m_colorNodesByUserData.m_bool = 257;
  *(_QWORD *)&this->m_nodeSize = 1048576000i64;
  this->m_nodeColor = hkColor::BLUEVIOLET;
  this->m_internalEdgeColor = hkColor::BLUE;
  this->m_externalEdgeColor = hkColor::MAGENTA;
  this->m_nodeLabelColor = hkColor::BLACK;
  this->m_edgeLabelColor = hkColor::PURPLE;
  this->m_instanceEnabled.m_storage.m_words.m_data = 0i64;
  this->m_instanceEnabled.m_storage.m_words.m_size = 0;
  this->m_instanceEnabled.m_storage.m_words.m_capacityAndFlags = 2147483648;
  this->m_instanceEnabled.m_storage.m_numBits = 0;
  this->m_displayTransform.m_col0 = (hkVector4f)transform.m_quad;
  this->m_displayTransform.m_col1 = (hkVector4f)direction.m_quad;
  this->m_displayTransform.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_displayTransform.m_col3 = (hkVector4f)qi.m_vec.m_quad;
  this->m_pruneLabelsAabb.m_min = (hkVector4f)xmmword_141A712A0;
  this->m_pruneLabelsAabb.m_max.m_quad = _mm_xor_ps(
                                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                                           this->m_pruneLabelsAabb.m_min.m_quad);
}

// File Line: 47
// RVA: 0xC4F5A0
void __fastcall drawDirectedGraphEdge(hkaiDirectedGraphInstance *clusterGraph, int ei, hkaiStreamingCollection *collection, hkaiGraphDebugUtils::DebugInfo *settings, hkVector4f *nodePosition, const unsigned int *nodeDataPtr, hkDebugDisplayHandler *displayHandler, int tag)
{
  int v8; // eax
  hkaiStreamingCollection *v9; // r11
  hkaiDirectedGraphInstance *v10; // r10
  hkaiDirectedGraphExplicitCost::Edge *v11; // rax
  signed __int64 v12; // rcx
  int v13; // edx
  unsigned int v14; // eax
  int v15; // er8
  unsigned int v16; // eax
  int v17; // er8
  __int64 v18; // rax
  int v19; // edx
  unsigned int v20; // ecx
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  hkVector4f end; // [rsp+40h] [rbp-18h]
  char v24; // [rsp+68h] [rbp+10h]

  v8 = clusterGraph->m_numOriginalEdges;
  v9 = collection;
  v10 = clusterGraph;
  if ( ei >= v8 )
  {
    ei -= v8;
    v11 = clusterGraph->m_ownedEdges.m_data;
  }
  else
  {
    v11 = clusterGraph->m_originalEdges;
  }
  v12 = (signed __int64)&v11[ei];
  v13 = *(_DWORD *)(v12 + 4);
  if ( *(_BYTE *)(v12 + 2) & 0x40 )
    v14 = v13 & 0xFFC00000;
  else
    v14 = v10->m_runtimeId << 22;
  v15 = v14 | v13 & 0x3FFFFF;
  if ( v13 == -1 )
    v15 = -1;
  v16 = v15;
  v17 = v15 & 0x3FFFFF;
  v18 = v16 >> 22;
  if ( *(_BYTE *)(v12 + 2) & 0x40 )
  {
    if ( (signed int)v18 >= 0 )
      v10 = v9->m_instances.m_data[v18].m_clusterGraphInstance;
    else
      v10 = 0i64;
    v19 = settings->m_externalEdgeColor;
  }
  else
  {
    v19 = settings->m_internalEdgeColor;
  }
  if ( nodeDataPtr )
  {
    if ( settings->m_colorEdgesByUserData.m_bool )
    {
      v20 = settings->m_materialColors.m_size;
      if ( v20 )
        v19 = settings->m_materialColors.m_data[*nodeDataPtr % v20];
    }
  }
  v21 = v10->m_originalPositions[v17].m_quad;
  v22 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), v10->m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), v10->m_transform.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), v10->m_transform.m_rotation.m_col2.m_quad)),
          v10->m_transform.m_translation.m_quad);
  end.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), settings->m_displayTransform.m_col0.m_quad),
                           settings->m_displayTransform.m_col3.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), settings->m_displayTransform.m_col1.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), settings->m_displayTransform.m_col2.m_quad)),
                     nodePosition->m_quad),
                   (__m128)xmmword_141A711B0),
                 nodePosition->m_quad);
  if ( displayHandler )
    displayHandler->vfptr->displayLine(displayHandler, (hkResult *)&v24, nodePosition, &end, v19, 0, tag);
  else
    hkDebugDisplay::displayLine(
      hkSingleton<hkDebugDisplay>::s_instance,
      nodePosition,
      &end,
      v19,
      0,
      (int)hkDebugDisplayProcess::m_tag);
}

// File Line: 88
// RVA: 0xC4F760
void __fastcall formatUserData_unsigned_int_(hkStringBuf *label, const unsigned int *dataPtr, int N)
{
  int v3; // er15
  int v4; // esi
  const unsigned int *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rdi
  hkStringBuf *v8; // r14
  __int64 v9; // rbp
  int v10; // er15
  const char *v11; // r9

  if ( N > 0 )
  {
    v3 = N;
    v4 = 0;
    v5 = dataPtr;
    v6 = 0i64;
    v7 = N;
    v8 = label;
    while ( !dataPtr[v6] )
    {
      if ( ++v6 >= N )
        return;
    }
    if ( N == 1 )
    {
      if ( *dataPtr )
        hkStringBuf::printf(label, "[%d]");
    }
    else
    {
      hkStringBuf::operator=(label, "[");
      v9 = 0i64;
      v10 = v3 - 1;
      do
      {
        v11 = ", ";
        if ( v4 == v10 )
          v11 = "]";
        hkStringBuf::appendPrintf(v8, "%d%s", v5[v9++], v11);
        ++v4;
      }
      while ( v9 < v7 );
    }
  }
}

// File Line: 128
// RVA: 0xC4F000
void __fastcall hkaiGraphDebugUtils::showGraphCollection(hkaiGraphDebugUtils::DebugInfo *settings, hkaiStreamingCollection *collection, hkDebugDisplayHandler *displayHandler, int tag)
{
  hkDebugDisplayHandler *v4; // r12
  signed __int64 v5; // r8
  unsigned int v6; // ebx
  int v7; // er13
  hkaiStreamingCollection *v8; // rax
  hkaiGraphDebugUtils::DebugInfo *v9; // rsi
  char *v10; // rcx
  signed __int64 v11; // r9
  hkaiDirectedGraphInstance *v12; // r14
  unsigned int v13; // edx
  signed __int64 v14; // rdi
  __int64 v15; // rcx
  __m128 v16; // xmm1
  int v17; // eax
  __m128 v18; // xmm2
  const unsigned int *v19; // r15
  unsigned int v20; // er9
  unsigned int v21; // ecx
  float v22; // xmm2_4
  int v23; // er8
  hkaiDirectedGraphExplicitCost::Node *v24; // rax
  int v25; // ebx
  int i; // edi
  __int64 v27; // rcx
  hkaiDirectedGraphExplicitCost::Node v28; // rbx
  int v29; // edi
  int v30; // ebx
  __int64 id; // [rsp+20h] [rbp-B8h]
  __int64 taga; // [rsp+28h] [rbp-B0h]
  hkDebugDisplayHandler *displayHandlera; // [rsp+30h] [rbp-A8h]
  unsigned int v34; // [rsp+40h] [rbp-98h]
  unsigned int v35; // [rsp+44h] [rbp-94h]
  signed __int64 v36; // [rsp+50h] [rbp-88h]
  signed __int64 v37; // [rsp+58h] [rbp-80h]
  hkVector4f position; // [rsp+60h] [rbp-78h]
  __int64 v39; // [rsp+70h] [rbp-68h]
  hkStringBuf v40; // [rsp+78h] [rbp-60h]
  hkStringBuf label; // [rsp+108h] [rbp+30h]
  hkaiStreamingCollection *collectiona; // [rsp+1D0h] [rbp+F8h]

  v4 = displayHandler;
  v5 = collection->m_instances.m_size;
  v6 = 0;
  v7 = tag;
  v8 = collection;
  v9 = settings;
  v36 = v5;
  v35 = 0;
  if ( v5 > 0 )
  {
    v10 = 0i64;
    v11 = collection->m_instances.m_size;
    v40.m_string.m_data = 0i64;
    do
    {
      if ( (v6 & 0x80000000) == 0 )
      {
        v12 = *(hkaiDirectedGraphInstance **)((char *)&v8->m_instances.m_data->m_clusterGraphInstance
                                            + (unsigned __int64)v10);
        if ( v12 )
        {
          v13 = 0;
          v14 = 0i64;
          v34 = 0;
          v37 = 0i64;
          position.m_quad.m128_u64[0] = v12->m_numOriginalNodes;
          if ( (signed __int64)position.m_quad.m128_u64[0] > 0 )
          {
            v15 = 0i64;
            v39 = 0i64;
            do
            {
              v16 = *(__m128 *)((char *)&v12->m_originalPositions->m_quad + v15);
              v17 = v12->m_nodeDataStriding;
              v18 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v12->m_transform.m_rotation.m_col0.m_quad),
                          _mm_mul_ps(
                            _mm_shuffle_ps(*(__m128 *)((char *)&v12->m_originalPositions->m_quad + v15), v16, 85),
                            v12->m_transform.m_rotation.m_col1.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12->m_transform.m_rotation.m_col2.m_quad)),
                      v12->m_transform.m_translation.m_quad);
              position.m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(_mm_shuffle_ps(v18, v18, 0), v9->m_displayTransform.m_col0.m_quad),
                                      v9->m_displayTransform.m_col3.m_quad),
                                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), v9->m_displayTransform.m_col1.m_quad)),
                                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), v9->m_displayTransform.m_col2.m_quad));
              if ( v17 )
                v19 = &v12->m_originalNodeData[v13 * v17];
              else
                v19 = 0i64;
              if ( v9->m_showNodes.m_bool )
              {
                v20 = v9->m_nodeColor;
                if ( v19 )
                {
                  if ( v9->m_colorNodesByUserData.m_bool )
                  {
                    v21 = v9->m_materialColors.m_size;
                    if ( v21 )
                      v20 = v9->m_materialColors.m_data[*v19 % v21];
                  }
                }
                v22 = v9->m_nodeSize;
                if ( v4 )
                  hkDebugDisplayHandler::displayStar(v4, &position, v22, v20, 0, v7);
                else
                  hkDebugDisplay::displayStar(
                    hkSingleton<hkDebugDisplay>::s_instance,
                    &position,
                    v22,
                    v20,
                    0,
                    (int)hkDebugDisplayProcess::m_tag);
                v5 = v36;
                v13 = v34;
              }
              if ( v9->m_labelNodes.m_bool )
              {
                v40.m_string.m_capacityAndFlags = -2147483520;
                v40.m_string.m_size = 1;
                v40.m_string.m_storage[0] = 0;
                v40.m_string.m_data = v40.m_string.m_storage;
                if ( v5 <= 1 )
                  hkStringBuf::printf(&v40, "%d", v13, v11);
                else
                  hkStringBuf::printf(&v40, "%d:%d", v6, v13);
                if ( v9->m_showNodeData.m_bool )
                {
                  if ( v19 )
                  {
                    v23 = v12->m_nodeDataStriding;
                    label.m_string.m_data = label.m_string.m_storage;
                    label.m_string.m_capacityAndFlags = -2147483520;
                    label.m_string.m_size = 1;
                    label.m_string.m_storage[0] = 0;
                    formatUserData_unsigned_int_(&label, v19, v23);
                    hkStringBuf::operator+=(&v40, label.m_string.m_data);
                    label.m_string.m_size = 0;
                    if ( label.m_string.m_capacityAndFlags >= 0 )
                      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                        label.m_string.m_data,
                        label.m_string.m_capacityAndFlags & 0x3FFFFFFF);
                  }
                }
                if ( v4 )
                {
                  LODWORD(displayHandlera) = v7;
                  LODWORD(taga) = 0;
                  LODWORD(id) = v9->m_nodeLabelColor;
                  v4->vfptr->display3dText(
                    v4,
                    (hkResult *)&position.m_quad.m128_u16[4],
                    v40.m_string.m_data,
                    &position,
                    id,
                    taga,
                    (int)displayHandlera);
                }
                else
                {
                  hkDebugDisplay::display3dText(
                    hkSingleton<hkDebugDisplay>::s_instance,
                    v40.m_string.m_data,
                    &position,
                    v9->m_nodeLabelColor,
                    0,
                    (int)hkDebugDisplayProcess::m_tag);
                }
                v40.m_string.m_size = 0;
                if ( v40.m_string.m_capacityAndFlags >= 0 )
                  hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                    v40.m_string.m_data,
                    v40.m_string.m_capacityAndFlags & 0x3FFFFFFF);
              }
              if ( v9->m_showEdges.m_bool )
              {
                v24 = v12->m_originalNodes;
                v25 = v24[v14].m_startEdgeIndex;
                for ( i = v25 + v24[v14].m_numEdges; v25 < i; ++v25 )
                  drawDirectedGraphEdge(v12, v25, collectiona, v9, &position, v19, v4, v7);
                if ( v12->m_nodeMap.m_size && (v27 = v12->m_nodeMap.m_data[v37], (_DWORD)v27 != -1) )
                {
                  v28 = v12->m_instancedNodes.m_data[v27];
                  v29 = (int)v12->m_instancedNodes.m_data[v27];
                }
                else
                {
                  v29 = -1;
                  v28.m_numEdges = 0;
                }
                v28.m_startEdgeIndex = v29 + v28.m_numEdges;
                if ( v29 < v29 + v28.m_numEdges )
                {
                  do
                    drawDirectedGraphEdge(v12, v29++, collectiona, v9, &position, v19, v4, v7);
                  while ( v29 < v30 );
                }
                v6 = v35;
                v14 = v37;
              }
              v5 = v36;
              ++v14;
              v13 = v34 + 1;
              v15 = v39 + 16;
              ++v34;
              v39 += 16i64;
              v37 = v14;
            }
            while ( v14 < (signed __int64)position.m_quad.m128_u64[0] );
            v10 = v40.m_string.m_data;
            v11 = v14;
          }
        }
        v8 = collectiona;
      }
      ++v6;
      v10 += 48;
      --v11;
      v35 = v6;
      v40.m_string.m_data = v10;
    }
    while ( v11 );
  }
}

// File Line: 205
// RVA: 0xC4F460
void __fastcall hkaiGraphDebugUtils::showGraph(hkaiGraphDebugUtils::DebugInfo *settings, hkaiDirectedGraphExplicitCost *clusterGraph, hkDebugDisplayHandler *displayHandler, int tag)
{
  hkaiGraphDebugUtils::DebugInfo *v4; // rbp
  int v5; // edi
  hkDebugDisplayHandler *v6; // rsi
  hkaiDirectedGraphExplicitCost *v7; // rbx
  int v8; // er9
  hkaiStreamingCollection::InstanceInfo *v9; // r8
  __int64 v10; // rdx
  hkaiDirectedGraphInstance **v11; // rax
  hkResult result; // [rsp+30h] [rbp-158h]
  hkaiStreamingCollection array; // [rsp+38h] [rbp-150h]
  hkaiDirectedGraphInstance v14; // [rsp+70h] [rbp-118h]

  v4 = settings;
  v5 = tag;
  v6 = displayHandler;
  v7 = clusterGraph;
  hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(&v14);
  hkaiDirectedGraphInstance::tempInit(&v14, v7);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v8 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v8 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v8,
      48);
  }
  v9 = array.m_instances.m_data;
  v10 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v11 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v11 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v11 - 2) = 0i64;
        *(v11 - 1) = 0i64;
        *v11 = 0i64;
        v11[1] = 0i64;
        v11[2] = 0i64;
        *((_DWORD *)v11 + 6) = -1;
      }
      v11 += 6;
      --v10;
    }
    while ( v10 );
    v9 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v9->m_clusterGraphInstance = &v14;
  hkaiGraphDebugUtils::showGraphCollection(v4, &array, v6, v5);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiDirectedGraphInstance::~hkaiDirectedGraphInstance(&v14);
}

