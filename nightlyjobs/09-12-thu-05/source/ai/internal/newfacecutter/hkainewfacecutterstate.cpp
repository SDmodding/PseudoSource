// File Line: 17
// RVA: 0x12F4DB0
void __fastcall hkaiNewFaceCutterUtil::State::State(hkaiNewFaceCutterUtil::State *this)
{
  hkaiNewFaceCutterUtil::State *v1; // rdi
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // er9
  int v6; // eax
  int v7; // eax
  int v8; // er9
  int v9; // eax
  int v10; // eax
  int v11; // er9
  int v12; // eax
  int v13; // eax
  int v14; // er9
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // eax
  int v19; // eax
  hkResult result; // [rsp+60h] [rbp+8h]

  this->m_segments.m_capacityAndFlags = 2147483648;
  v1 = this;
  this->m_segments.m_data = 0i64;
  this->m_segments.m_size = 0;
  this->m_regions.m_data = 0i64;
  this->m_regions.m_size = 0;
  this->m_regions.m_capacityAndFlags = 2147483648;
  this->m_regionEdges.m_data = 0i64;
  this->m_regionEdges.m_size = 0;
  this->m_regionEdges.m_capacityAndFlags = 2147483648;
  this->m_outputVertices.m_data = 0i64;
  this->m_outputVertices.m_size = 0;
  this->m_outputVertices.m_capacityAndFlags = 2147483648;
  this->m_painterMaterials.m_size = 0;
  hkaiNewFaceCutterUtil::EventQueue::EventQueue(&this->m_eventQueue);
  v1->m_incomingSegments.m_data = 0i64;
  v1->m_incomingSegments.m_size = 0;
  v1->m_incomingSegments.m_capacityAndFlags = 2147483648;
  v1->m_outgoingSegments.m_data = 0i64;
  v1->m_outgoingSegments.m_size = 0;
  v1->m_outgoingSegments.m_capacityAndFlags = 2147483648;
  v1->m_sweepState.m_firstSegment = -1;
  v1->m_sweepState.m_lastSegment = -1;
  v2 = 256;
  v3 = v1->m_segments.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < 256 )
  {
    v4 = 2 * v3;
    v5 = 256;
    if ( v4 > 256 )
      v5 = v4;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_segments,
      v5,
      28);
  }
  v6 = v1->m_regions.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < 256 )
  {
    v7 = 2 * v6;
    v8 = 256;
    if ( v7 > 256 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_regions, v8, 6);
  }
  v9 = v1->m_regionEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < 256 )
  {
    v10 = 2 * v9;
    v11 = 256;
    if ( v10 > 256 )
      v11 = v10;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_regionEdges,
      v11,
      8);
  }
  v12 = v1->m_outputVertices.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v12 < 256 )
  {
    v13 = 2 * v12;
    v14 = 256;
    if ( v13 > 256 )
      v14 = v13;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_outputVertices,
      v14,
      4);
  }
  v15 = v1->m_incomingSegments.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < 256 )
  {
    v16 = 2 * v15;
    v17 = 256;
    if ( v16 > 256 )
      v17 = v16;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_incomingSegments,
      v17,
      2);
  }
  v18 = v1->m_outgoingSegments.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v18 < 256 )
  {
    v19 = 2 * v18;
    if ( v19 > 256 )
      v2 = v19;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_outgoingSegments,
      v2,
      2);
  }
  v1->m_faceMaterial = 0;
}

// File Line: 32
// RVA: 0x12F5010
void __fastcall hkaiNewFaceCutterUtil::State::reset(hkaiNewFaceCutterUtil::State *this)
{
  hkaiNewFaceCutterUtil::EventQueue *v1; // rcx

  v1 = &this->m_eventQueue;
  v1[-8].m_heap.m_size = 0;
  v1[-7].m_heap.m_size = 0;
  v1[-6].m_heap.m_size = 0;
  v1[-5].m_heap.m_size = 0;
  v1[-1].m_heap.m_capacityAndFlags = 0;
  hkaiNewFaceCutterUtil::EventQueue::clear(v1);
}

// File Line: 43
// RVA: 0x12F5040
__int64 __fastcall hkaiNewFaceCutterUtil::State::_addOutputVertex(hkaiNewFaceCutterUtil::State *this, hkaiNewFaceCutterUtil::Vec2 v)
{
  signed __int64 v2; // rsi
  signed int v3; // ebx
  signed int v4; // eax
  hkArray<hkaiNewFaceCutterUtil::Vec2,hkContainerHeapAllocator> *v5; // rdi
  hkaiNewFaceCutterUtil::Vec2 *v6; // r9
  hkaiNewFaceCutterUtil::Vec2 *v7; // r8
  signed __int64 v8; // r8
  __int64 v9; // rax
  __int64 result; // rax
  hkArray<hkaiNewFaceCutterUtil::Vec2,hkContainerHeapAllocator> *v11; // rdi
  unsigned int v12; // [rsp+38h] [rbp+10h]

  v12 = v.m_xy;
  v2 = this->m_outputVertices.m_size;
  v3 = v2;
  v4 = v2 - 1;
  if ( (signed int)v2 - 1 < 0 )
    goto LABEL_19;
  v5 = &this->m_outputVertices;
  v6 = this->m_outputVertices.m_data;
  v7 = &v6[v4];
  do
  {
    if ( v7->m_xy < v.m_xy )
      break;
    v3 = v4;
    --v7;
    --v4;
  }
  while ( v4 >= 0 );
  if ( v3 == (_DWORD)v2 )
  {
LABEL_19:
    v11 = &this->m_outputVertices;
    if ( this->m_outputVertices.m_size == (this->m_outputVertices.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 4);
      v.m_xy = v12;
    }
    v11->m_data[v11->m_size++] = v;
    result = (unsigned __int16)v3;
  }
  else
  {
    if ( v6[v3].m_xy != v.m_xy )
    {
      hkaiNewFaceCutterUtil::shiftOutputVertexIndicesInRegionEdges(this, v3);
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 4);
      ++v5->m_size;
      if ( (signed int)v2 > v3 )
      {
        v8 = v2;
        v9 = (unsigned int)(v2 - v3);
        do
        {
          --v8;
          v5->m_data[v8 + 1].m_xy = v5->m_data[v8].m_xy;
          --v9;
        }
        while ( v9 );
      }
      v5->m_data[v3].m_xy = v12;
    }
    result = (unsigned __int16)v3;
  }
  return result;
}

