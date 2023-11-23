// File Line: 17
// RVA: 0x12F4DB0
void __fastcall hkaiNewFaceCutterUtil::State::State(hkaiNewFaceCutterUtil::State *this)
{
  int v2; // ebx
  int v3; // r9d
  int v4; // r9d
  int v5; // r9d
  int v6; // r9d
  int v7; // r9d
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  this->m_segments.m_capacityAndFlags = 0x80000000;
  this->m_segments.m_data = 0i64;
  this->m_segments.m_size = 0;
  this->m_regions.m_data = 0i64;
  this->m_regions.m_size = 0;
  this->m_regions.m_capacityAndFlags = 0x80000000;
  this->m_regionEdges.m_data = 0i64;
  this->m_regionEdges.m_size = 0;
  this->m_regionEdges.m_capacityAndFlags = 0x80000000;
  this->m_outputVertices.m_data = 0i64;
  this->m_outputVertices.m_size = 0;
  this->m_outputVertices.m_capacityAndFlags = 0x80000000;
  this->m_painterMaterials.m_size = 0;
  hkaiNewFaceCutterUtil::EventQueue::EventQueue(&this->m_eventQueue);
  this->m_incomingSegments.m_data = 0i64;
  this->m_incomingSegments.m_size = 0;
  this->m_incomingSegments.m_capacityAndFlags = 0x80000000;
  this->m_outgoingSegments.m_data = 0i64;
  this->m_outgoingSegments.m_size = 0;
  this->m_outgoingSegments.m_capacityAndFlags = 0x80000000;
  this->m_sweepState.m_firstSegment = -1;
  this->m_sweepState.m_lastSegment = -1;
  v2 = 256;
  if ( (this->m_segments.m_capacityAndFlags & 0x3FFFFFFFu) < 0x100 )
  {
    v3 = 256;
    if ( 2 * (this->m_segments.m_capacityAndFlags & 0x3FFFFFFF) > 256 )
      v3 = 2 * (this->m_segments.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_segments.m_data, v3, 28);
  }
  if ( (this->m_regions.m_capacityAndFlags & 0x3FFFFFFFu) < 0x100 )
  {
    v4 = 256;
    if ( 2 * (this->m_regions.m_capacityAndFlags & 0x3FFFFFFF) > 256 )
      v4 = 2 * (this->m_regions.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_regions.m_data, v4, 6);
  }
  if ( (this->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFFu) < 0x100 )
  {
    v5 = 256;
    if ( 2 * (this->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF) > 256 )
      v5 = 2 * (this->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_regionEdges.m_data,
      v5,
      8);
  }
  if ( (this->m_outputVertices.m_capacityAndFlags & 0x3FFFFFFFu) < 0x100 )
  {
    v6 = 256;
    if ( 2 * (this->m_outputVertices.m_capacityAndFlags & 0x3FFFFFFF) > 256 )
      v6 = 2 * (this->m_outputVertices.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_outputVertices.m_data,
      v6,
      4);
  }
  if ( (this->m_incomingSegments.m_capacityAndFlags & 0x3FFFFFFFu) < 0x100 )
  {
    v7 = 256;
    if ( 2 * (this->m_incomingSegments.m_capacityAndFlags & 0x3FFFFFFF) > 256 )
      v7 = 2 * (this->m_incomingSegments.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_incomingSegments.m_data,
      v7,
      2);
  }
  if ( (this->m_outgoingSegments.m_capacityAndFlags & 0x3FFFFFFFu) < 0x100 )
  {
    if ( 2 * (this->m_outgoingSegments.m_capacityAndFlags & 0x3FFFFFFF) > 256 )
      v2 = 2 * (this->m_outgoingSegments.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_outgoingSegments.m_data,
      v2,
      2);
  }
  this->m_faceMaterial = 0;
}

// File Line: 32
// RVA: 0x12F5010
void __fastcall hkaiNewFaceCutterUtil::State::reset(hkaiNewFaceCutterUtil::State *this)
{
  hkaiNewFaceCutterUtil::EventQueue *p_m_eventQueue; // rcx

  p_m_eventQueue = &this->m_eventQueue;
  p_m_eventQueue[-8].m_heap.m_size = 0;
  p_m_eventQueue[-7].m_heap.m_size = 0;
  p_m_eventQueue[-6].m_heap.m_size = 0;
  p_m_eventQueue[-5].m_heap.m_size = 0;
  p_m_eventQueue[-1].m_heap.m_capacityAndFlags = 0;
  hkaiNewFaceCutterUtil::EventQueue::clear(p_m_eventQueue);
}

// File Line: 43
// RVA: 0x12F5040
__int64 __fastcall hkaiNewFaceCutterUtil::State::_addOutputVertex(
        hkaiNewFaceCutterUtil::State *this,
        hkaiNewFaceCutterUtil::Vec2 v)
{
  __int64 m_size; // rsi
  int v3; // ebx
  int v4; // eax
  hkArray<hkaiNewFaceCutterUtil::Vec2,hkContainerHeapAllocator> *p_m_outputVertices; // rdi
  hkaiNewFaceCutterUtil::Vec2 *m_data; // r9
  hkaiNewFaceCutterUtil::Vec2 *v7; // r8
  __int64 v8; // r8
  __int64 v9; // rax
  hkArray<hkaiNewFaceCutterUtil::Vec2,hkContainerHeapAllocator> *v11; // rdi
  unsigned int m_xy; // [rsp+38h] [rbp+10h]

  m_xy = v.m_xy;
  m_size = this->m_outputVertices.m_size;
  v3 = m_size;
  v4 = m_size - 1;
  if ( (int)m_size - 1 < 0 )
    goto LABEL_14;
  p_m_outputVertices = &this->m_outputVertices;
  m_data = this->m_outputVertices.m_data;
  v7 = &m_data[v4];
  do
  {
    if ( v7->m_xy < v.m_xy )
      break;
    v3 = v4;
    --v7;
    --v4;
  }
  while ( v4 >= 0 );
  if ( v3 == (_DWORD)m_size )
  {
LABEL_14:
    v11 = &this->m_outputVertices;
    if ( this->m_outputVertices.m_size == (this->m_outputVertices.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v11->m_data, 4);
      v.m_xy = m_xy;
    }
    v11->m_data[v11->m_size++] = v;
    return (unsigned __int16)v3;
  }
  else
  {
    if ( m_data[v3].m_xy != v.m_xy )
    {
      hkaiNewFaceCutterUtil::shiftOutputVertexIndicesInRegionEdges(this, v3);
      if ( p_m_outputVertices->m_size == (p_m_outputVertices->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_outputVertices->m_data, 4);
      ++p_m_outputVertices->m_size;
      if ( (int)m_size > v3 )
      {
        v8 = m_size;
        v9 = (unsigned int)(m_size - v3);
        do
        {
          --v8;
          p_m_outputVertices->m_data[v8 + 1].m_xy = p_m_outputVertices->m_data[v8].m_xy;
          --v9;
        }
        while ( v9 );
      }
      p_m_outputVertices->m_data[v3].m_xy = m_xy;
    }
    return (unsigned __int16)v3;
  }
}

