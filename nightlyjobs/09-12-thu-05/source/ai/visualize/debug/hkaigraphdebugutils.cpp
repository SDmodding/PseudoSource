// File Line: 40
// RVA: 0xC4EF20
void __fastcall hkaiGraphDebugUtils::DebugInfo::DebugInfo(hkaiGraphDebugUtils::DebugInfo *this)
{
  *(_DWORD *)&this->m_showNodes.m_bool = 257;
  this->m_materialColors.m_capacityAndFlags = 0x80000000;
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
  this->m_instanceEnabled.m_storage.m_words.m_capacityAndFlags = 0x80000000;
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
void __fastcall drawDirectedGraphEdge(
        hkaiDirectedGraphInstance *clusterGraph,
        int ei,
        hkaiStreamingCollection *collection,
        hkaiGraphDebugUtils::DebugInfo *settings,
        hkVector4f *nodePosition,
        const unsigned int *nodeDataPtr,
        hkDebugDisplayHandler *displayHandler,
        int tag)
{
  int m_numOriginalEdges; // eax
  hkaiDirectedGraphInstance *m_clusterGraphInstance; // r10
  hkaiDirectedGraphExplicitCost::Edge *m_data; // rax
  hkaiDirectedGraphExplicitCost::Edge *v12; // rcx
  unsigned int m_target; // edx
  unsigned int v14; // eax
  int v15; // r8d
  unsigned int v16; // eax
  int v17; // r8d
  __int64 v18; // rax
  int m_externalEdgeColor; // edx
  unsigned int m_size; // ecx
  __m128 m_quad; // xmm1
  __m128 v22; // xmm3
  hkVector4f end; // [rsp+40h] [rbp-18h] BYREF
  char v24; // [rsp+68h] [rbp+10h] BYREF

  m_numOriginalEdges = clusterGraph->m_numOriginalEdges;
  m_clusterGraphInstance = clusterGraph;
  if ( ei >= m_numOriginalEdges )
  {
    ei -= m_numOriginalEdges;
    m_data = clusterGraph->m_ownedEdges.m_data;
  }
  else
  {
    m_data = clusterGraph->m_originalEdges;
  }
  v12 = &m_data[ei];
  m_target = v12->m_target;
  if ( (v12->m_flags.m_storage & 0x40) != 0 )
    v14 = m_target & 0xFFC00000;
  else
    v14 = m_clusterGraphInstance->m_runtimeId << 22;
  v15 = v14 | m_target & 0x3FFFFF;
  if ( m_target == -1 )
    v15 = -1;
  v16 = v15;
  v17 = v15 & 0x3FFFFF;
  v18 = v16 >> 22;
  if ( (v12->m_flags.m_storage & 0x40) != 0 )
  {
    if ( (int)v18 >= 0 )
      m_clusterGraphInstance = collection->m_instances.m_data[v18].m_clusterGraphInstance;
    else
      m_clusterGraphInstance = 0i64;
    m_externalEdgeColor = settings->m_externalEdgeColor;
  }
  else
  {
    m_externalEdgeColor = settings->m_internalEdgeColor;
  }
  if ( nodeDataPtr )
  {
    if ( settings->m_colorEdgesByUserData.m_bool )
    {
      m_size = settings->m_materialColors.m_size;
      if ( m_size )
        m_externalEdgeColor = settings->m_materialColors.m_data[*nodeDataPtr % m_size];
    }
  }
  m_quad = m_clusterGraphInstance->m_originalPositions[v17].m_quad;
  v22 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(m_quad, m_quad, 85),
                m_clusterGraphInstance->m_transform.m_rotation.m_col1.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(m_quad, m_quad, 0),
                m_clusterGraphInstance->m_transform.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(
              _mm_shuffle_ps(m_quad, m_quad, 170),
              m_clusterGraphInstance->m_transform.m_rotation.m_col2.m_quad)),
          m_clusterGraphInstance->m_transform.m_translation.m_quad);
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
    displayHandler->vfptr->displayLine(
      displayHandler,
      (hkResult *)&v24,
      nodePosition,
      &end,
      m_externalEdgeColor,
      0,
      tag);
  else
    hkDebugDisplay::displayLine(
      hkSingleton<hkDebugDisplay>::s_instance,
      nodePosition,
      &end,
      m_externalEdgeColor,
      0,
      (int)hkDebugDisplayProcess::m_tag);
}

// File Line: 88
// RVA: 0xC4F760
void __fastcall formatUserData_unsigned_int_(hkStringBuf *label, const unsigned int *dataPtr, int N)
{
  int v4; // esi
  __int64 v6; // rax
  __int64 v7; // rdi
  __int64 v9; // r8
  __int64 v10; // rbp
  int v11; // r15d
  const char *v12; // r9

  if ( N > 0 )
  {
    v4 = 0;
    v6 = 0i64;
    v7 = N;
    while ( !dataPtr[v6] )
    {
      if ( ++v6 >= N )
        return;
    }
    if ( N == 1 )
    {
      v9 = *dataPtr;
      if ( (_DWORD)v9 )
        hkStringBuf::printf(label, "[%d]", v9);
    }
    else
    {
      hkStringBuf::operator=(label, "[");
      v10 = 0i64;
      v11 = N - 1;
      do
      {
        v12 = ", ";
        if ( v4 == v11 )
          v12 = "]";
        hkStringBuf::appendPrintf(label, "%d%s", dataPtr[v10++], v12);
        ++v4;
      }
      while ( v10 < v7 );
    }
  }
}

// File Line: 128
// RVA: 0xC4F000
void __fastcall hkaiGraphDebugUtils::showGraphCollection(
        hkaiGraphDebugUtils::DebugInfo *settings,
        hkaiStreamingCollection *collection,
        hkDebugDisplayHandler *displayHandler,
        int tag)
{
  __int64 m_size; // r8
  int v6; // ebx
  hkaiStreamingCollection *v8; // rax
  char *m_data; // rcx
  __int64 v11; // r9
  hkaiDirectedGraphInstance *v12; // r14
  unsigned int v13; // edx
  __int64 v14; // rdi
  __int64 v15; // rcx
  __m128 v16; // xmm1
  int m_nodeDataStriding; // eax
  __m128 v18; // xmm2
  const unsigned int *v19; // r15
  int m_nodeColor; // r9d
  unsigned int v21; // ecx
  float m_nodeSize; // xmm2_4
  int v23; // r8d
  hkaiDirectedGraphExplicitCost::Node *m_originalNodes; // rax
  int m_startEdgeIndex; // ebx
  int i; // edi
  __int64 v27; // rcx
  hkaiDirectedGraphExplicitCost::Node v28; // rbx
  int v29; // edi
  int v30; // ebx
  unsigned int v31; // [rsp+40h] [rbp-98h]
  int v32; // [rsp+44h] [rbp-94h]
  __int64 v33; // [rsp+50h] [rbp-88h]
  __int64 v34; // [rsp+58h] [rbp-80h]
  hkVector4f position; // [rsp+60h] [rbp-78h] BYREF
  __int64 v36; // [rsp+70h] [rbp-68h]
  hkStringBuf v37; // [rsp+78h] [rbp-60h] BYREF
  hkStringBuf label; // [rsp+108h] [rbp+30h] BYREF
  hkaiStreamingCollection *collectiona; // [rsp+1D0h] [rbp+F8h]

  m_size = collection->m_instances.m_size;
  v6 = 0;
  v8 = collection;
  v33 = m_size;
  v32 = 0;
  if ( m_size > 0 )
  {
    m_data = 0i64;
    v11 = collection->m_instances.m_size;
    v37.m_string.m_data = 0i64;
    do
    {
      if ( v6 >= 0 )
      {
        v12 = *(hkaiDirectedGraphInstance **)((char *)&v8->m_instances.m_data->m_clusterGraphInstance
                                            + (unsigned __int64)m_data);
        if ( v12 )
        {
          v13 = 0;
          v14 = 0i64;
          v31 = 0;
          v34 = 0i64;
          position.m_quad.m128_u64[0] = v12->m_numOriginalNodes;
          if ( position.m_quad.m128_i64[0] > 0 )
          {
            v15 = 0i64;
            v36 = 0i64;
            do
            {
              v16 = *(__m128 *)((char *)&v12->m_originalPositions->m_quad + v15);
              m_nodeDataStriding = v12->m_nodeDataStriding;
              v18 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v12->m_transform.m_rotation.m_col0.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v12->m_transform.m_rotation.m_col1.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12->m_transform.m_rotation.m_col2.m_quad)),
                      v12->m_transform.m_translation.m_quad);
              position.m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_mul_ps(
                                        _mm_shuffle_ps(v18, v18, 0),
                                        settings->m_displayTransform.m_col0.m_quad),
                                      settings->m_displayTransform.m_col3.m_quad),
                                    _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), settings->m_displayTransform.m_col1.m_quad)),
                                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 170), settings->m_displayTransform.m_col2.m_quad));
              if ( m_nodeDataStriding )
                v19 = &v12->m_originalNodeData[v13 * m_nodeDataStriding];
              else
                v19 = 0i64;
              if ( settings->m_showNodes.m_bool )
              {
                m_nodeColor = settings->m_nodeColor;
                if ( v19 )
                {
                  if ( settings->m_colorNodesByUserData.m_bool )
                  {
                    v21 = settings->m_materialColors.m_size;
                    if ( v21 )
                      m_nodeColor = settings->m_materialColors.m_data[*v19 % v21];
                  }
                }
                m_nodeSize = settings->m_nodeSize;
                if ( displayHandler )
                  hkDebugDisplayHandler::displayStar(displayHandler, &position, m_nodeSize, m_nodeColor, 0, tag);
                else
                  hkDebugDisplay::displayStar(
                    hkSingleton<hkDebugDisplay>::s_instance,
                    &position,
                    m_nodeSize,
                    m_nodeColor,
                    0,
                    (int)hkDebugDisplayProcess::m_tag);
                m_size = v33;
                v13 = v31;
              }
              if ( settings->m_labelNodes.m_bool )
              {
                v37.m_string.m_capacityAndFlags = -2147483520;
                v37.m_string.m_size = 1;
                v37.m_string.m_storage[0] = 0;
                v37.m_string.m_data = v37.m_string.m_storage;
                if ( m_size <= 1 )
                  hkStringBuf::printf(&v37, "%d", v13);
                else
                  hkStringBuf::printf(&v37, "%d:%d", (unsigned int)v6, v13);
                if ( settings->m_showNodeData.m_bool )
                {
                  if ( v19 )
                  {
                    v23 = v12->m_nodeDataStriding;
                    label.m_string.m_data = label.m_string.m_storage;
                    label.m_string.m_capacityAndFlags = -2147483520;
                    label.m_string.m_size = 1;
                    label.m_string.m_storage[0] = 0;
                    formatUserData_unsigned_int_(&label, v19, v23);
                    hkStringBuf::operator+=(&v37, label.m_string.m_data);
                    label.m_string.m_size = 0;
                    if ( label.m_string.m_capacityAndFlags >= 0 )
                      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                        &hkContainerTempAllocator::s_alloc,
                        label.m_string.m_data,
                        label.m_string.m_capacityAndFlags & 0x3FFFFFFF);
                  }
                }
                if ( displayHandler )
                  displayHandler->vfptr->display3dText(
                    displayHandler,
                    (hkResult *)&position.m_quad.m128_u16[4],
                    v37.m_string.m_data,
                    &position,
                    settings->m_nodeLabelColor,
                    0,
                    tag);
                else
                  hkDebugDisplay::display3dText(
                    hkSingleton<hkDebugDisplay>::s_instance,
                    v37.m_string.m_data,
                    &position,
                    settings->m_nodeLabelColor,
                    0,
                    (int)hkDebugDisplayProcess::m_tag);
                v37.m_string.m_size = 0;
                if ( v37.m_string.m_capacityAndFlags >= 0 )
                  hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerTempAllocator::s_alloc,
                    v37.m_string.m_data,
                    v37.m_string.m_capacityAndFlags & 0x3FFFFFFF);
              }
              if ( settings->m_showEdges.m_bool )
              {
                m_originalNodes = v12->m_originalNodes;
                m_startEdgeIndex = m_originalNodes[v14].m_startEdgeIndex;
                for ( i = m_startEdgeIndex + m_originalNodes[v14].m_numEdges; m_startEdgeIndex < i; ++m_startEdgeIndex )
                  drawDirectedGraphEdge(
                    v12,
                    m_startEdgeIndex,
                    collectiona,
                    settings,
                    &position,
                    v19,
                    displayHandler,
                    tag);
                if ( !v12->m_nodeMap.m_size || (v27 = v12->m_nodeMap.m_data[v34], (_DWORD)v27 == -1) )
                {
                  v29 = -1;
                  v28.m_numEdges = 0;
                }
                else
                {
                  v28 = v12->m_instancedNodes.m_data[v27];
                  v29 = v28.m_startEdgeIndex;
                }
                v28.m_startEdgeIndex = v29 + v28.m_numEdges;
                if ( v29 < v29 + v28.m_numEdges )
                {
                  do
                    drawDirectedGraphEdge(v12, v29++, collectiona, settings, &position, v19, displayHandler, tag);
                  while ( v29 < v30 );
                }
                v6 = v32;
                v14 = v34;
              }
              m_size = v33;
              ++v14;
              v13 = v31 + 1;
              v15 = v36 + 16;
              ++v31;
              v36 += 16i64;
              v34 = v14;
            }
            while ( v14 < position.m_quad.m128_i64[0] );
            m_data = v37.m_string.m_data;
            v11 = v14;
          }
        }
        v8 = collectiona;
      }
      ++v6;
      m_data += 48;
      --v11;
      v32 = v6;
      v37.m_string.m_data = m_data;
    }
    while ( v11 );
  }
}

// File Line: 205
// RVA: 0xC4F460
void __fastcall hkaiGraphDebugUtils::showGraph(
        hkaiGraphDebugUtils::DebugInfo *settings,
        hkaiDirectedGraphExplicitCost *clusterGraph,
        hkDebugDisplayHandler *displayHandler,
        int tag)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // r8
  __int64 v9; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkResult result; // [rsp+30h] [rbp-158h] BYREF
  hkaiStreamingCollection array; // [rsp+38h] [rbp-150h] BYREF
  hkaiDirectedGraphInstance v13; // [rsp+70h] [rbp-118h] BYREF

  hkaiDirectedGraphInstance::hkaiDirectedGraphInstance(&v13);
  hkaiDirectedGraphInstance::tempInit(&v13, clusterGraph);
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v9 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v9;
    }
    while ( v9 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_clusterGraphInstance = &v13;
  hkaiGraphDebugUtils::showGraphCollection(settings, &array, displayHandler, tag);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
  hkaiDirectedGraphInstance::~hkaiDirectedGraphInstance(&v13);
}

