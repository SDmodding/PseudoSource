// File Line: 16
// RVA: 0x12F48B0
void __fastcall hkaiNewFaceCutterUtil::EventQueue::EventQueue(hkaiNewFaceCutterUtil::EventQueue *this)
{
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  this->m_heap.m_capacityAndFlags = 0x80000000;
  this->m_heap.m_data = 0i64;
  this->m_heap.m_size = 0;
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_heap.m_data, 32, 16);
  this->m_heap.m_size = 1;
}

// File Line: 22
// RVA: 0x12F4900
void __fastcall hkaiNewFaceCutterUtil::EventQueue::insert(
        hkaiNewFaceCutterUtil::EventQueue *this,
        hkaiNewFaceCutterUtil::Event *event)
{
  if ( this->m_heap.m_size == (this->m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_heap.m_data, 16);
  this->m_heap.m_data[this->m_heap.m_size++] = *event;
  hkaiNewFaceCutterUtil::EventQueue::upHeap(this, this->m_heap.m_size - 1);
}

// File Line: 28
// RVA: 0x12F4970
void __fastcall hkaiNewFaceCutterUtil::EventQueue::popFront(hkaiNewFaceCutterUtil::EventQueue *this)
{
  __int64 m_size; // rax

  m_size = this->m_heap.m_size;
  if ( (int)m_size <= 2 )
  {
    this->m_heap.m_size = 1;
  }
  else
  {
    this->m_heap.m_data[1] = this->m_heap.m_data[m_size - 1];
    --this->m_heap.m_size;
    hkaiNewFaceCutterUtil::EventQueue::downHeap(this, 1u);
  }
}

// File Line: 43
// RVA: 0x12F49B0
void __fastcall hkaiNewFaceCutterUtil::EventQueue::clear(hkaiNewFaceCutterUtil::EventQueue *this)
{
  this->m_heap.m_size = 1;
}

// File Line: 48
// RVA: 0x12F49C0
void __fastcall hkaiNewFaceCutterUtil::EventQueue::heapifyFirst(hkaiNewFaceCutterUtil::EventQueue *this)
{
  hkaiNewFaceCutterUtil::EventQueue::downHeap(this, 1u);
}

// File Line: 53
// RVA: 0x12F49D0
void __fastcall hkaiNewFaceCutterUtil::EventQueue::heapifyLast(hkaiNewFaceCutterUtil::EventQueue *this)
{
  hkaiNewFaceCutterUtil::EventQueue::upHeap(this, this->m_heap.m_size - 1);
}

// File Line: 58
// RVA: 0x12F49E0
void __fastcall hkaiNewFaceCutterUtil::EventQueue::heapifyAll(hkaiNewFaceCutterUtil::EventQueue *this)
{
  int i; // ebx

  for ( i = this->m_heap.m_size / 2; i >= 1; --i )
    hkaiNewFaceCutterUtil::EventQueue::downHeap(this, i);
}

// File Line: 66
// RVA: 0x12F4A50
void __fastcall hkaiNewFaceCutterUtil::EventQueue::upHeap(hkaiNewFaceCutterUtil::EventQueue *this, unsigned int i)
{
  hkaiNewFaceCutterUtil::Event v3; // xmm1
  hkaiNewFaceCutterUtil::Event *m_data; // r8
  unsigned int v5; // eax
  hkaiNewFaceCutterUtil::Event v6; // xmm0
  __int64 v7; // rcx

  v3 = this->m_heap.m_data[i];
  if ( i != 1 )
  {
    do
    {
      m_data = this->m_heap.m_data;
      v5 = i >> 1;
      if ( v3.m_posAndType >= this->m_heap.m_data[i >> 1].m_posAndType )
        break;
      v6 = m_data[i >> 1];
      v7 = (int)i;
      i >>= 1;
      m_data[v7] = v6;
    }
    while ( v5 != 1 );
  }
  this->m_heap.m_data[i] = v3;
}

// File Line: 87
// RVA: 0x12F4AC0
void __fastcall hkaiNewFaceCutterUtil::EventQueue::downHeap(hkaiNewFaceCutterUtil::EventQueue *this, int i)
{
  unsigned int v2; // ebx
  unsigned int v4; // edi
  hkaiNewFaceCutterUtil::Event v5; // xmm1
  hkaiNewFaceCutterUtil::Event *m_data; // r10
  signed int v7; // r9d
  __int64 v8; // rax
  unsigned int v9; // ecx
  __int64 v10; // rax

  v2 = this->m_heap.m_size - 1;
  v4 = (unsigned int)(this->m_heap.m_size - 2) >> 1;
  v5 = this->m_heap.m_data[i];
  if ( i > v4 )
  {
LABEL_6:
    if ( i == ((v2 >> 1) & ((v2 & 1) - 1)) )
    {
      v9 = 2 * i;
      if ( this->m_heap.m_data[2 * i].m_posAndType < v5.m_posAndType )
      {
        v10 = i;
        i *= 2;
        this->m_heap.m_data[v10] = this->m_heap.m_data[v9];
      }
    }
    this->m_heap.m_data[i] = v5;
  }
  else
  {
    while ( 1 )
    {
      m_data = this->m_heap.m_data;
      v7 = (2 * i) | 1;
      if ( this->m_heap.m_data[2 * i].m_posAndType < this->m_heap.m_data[v7].m_posAndType )
        v7 = 2 * i;
      if ( m_data[v7].m_posAndType >= v5.m_posAndType )
        break;
      v8 = i;
      i = v7;
      m_data[v8] = m_data[v7];
      if ( v7 > v4 )
        goto LABEL_6;
    }
    m_data[i] = v5;
  }
}

// File Line: 126
// RVA: 0x12F4A30
hkaiNewFaceCutterUtil::Event *__fastcall hkaiNewFaceCutterUtil::EventQueue::peekAt(
        hkaiNewFaceCutterUtil::EventQueue *this,
        int idx)
{
  return &this->m_heap.m_data[idx + 1];
}

// File Line: 133
// RVA: 0x12F4BC0
void __fastcall hkaiNewFaceCutterUtil::enqueueStartSegmentEvent(
        hkaiNewFaceCutterUtil::State *state,
        __int16 segmentIndex,
        hkaiNewFaceCutterUtil::Vec2 pos)
{
  hkaiNewFaceCutterUtil::EventQueue *p_m_eventQueue; // rbx
  __int64 v5; // rdx
  unsigned int m_xy; // [rsp+40h] [rbp+18h]

  m_xy = pos.m_xy;
  p_m_eventQueue = &state->m_eventQueue;
  if ( state->m_eventQueue.m_heap.m_size == (state->m_eventQueue.m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_eventQueue->m_heap.m_data, 16);
    pos.m_xy = m_xy;
  }
  v5 = (__int64)&p_m_eventQueue->m_heap.m_data[p_m_eventQueue->m_heap.m_size++];
  *(_DWORD *)v5 = (4 * pos.m_xy) | 1;
  *(_WORD *)(v5 + 6) = -1;
  *(_WORD *)(v5 + 4) = segmentIndex;
  hkaiNewFaceCutterUtil::EventQueue::heapifyLast(p_m_eventQueue);
}

// File Line: 144
// RVA: 0x12F4C50
void __fastcall hkaiNewFaceCutterUtil::enqueueStartSegmentsEventNoHeapify(
        hkaiNewFaceCutterUtil::State *state,
        __int16 segmentIndexA,
        __int16 segmentIndexB,
        hkaiNewFaceCutterUtil::Vec2 pos)
{
  hkaiNewFaceCutterUtil::EventQueue *p_m_eventQueue; // rbx
  __int64 v7; // rcx
  unsigned int m_xy; // [rsp+48h] [rbp+20h]

  m_xy = pos.m_xy;
  p_m_eventQueue = &state->m_eventQueue;
  if ( state->m_eventQueue.m_heap.m_size == (state->m_eventQueue.m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_eventQueue->m_heap.m_data, 16);
    pos.m_xy = m_xy;
  }
  v7 = (__int64)&p_m_eventQueue->m_heap.m_data[p_m_eventQueue->m_heap.m_size++];
  *(_WORD *)(v7 + 4) = segmentIndexA;
  *(_DWORD *)v7 = (4 * pos.m_xy) | 1;
  *(_WORD *)(v7 + 6) = segmentIndexB;
}

// File Line: 154
// RVA: 0x12F4CE0
void __fastcall hkaiNewFaceCutterUtil::enqueueIntersectionEvent(
        hkaiNewFaceCutterUtil::State *state,
        __int16 lowerSegment,
        __int16 upperSegment,
        hkaiNewFaceCutterUtil::Vec2 pos)
{
  hkaiNewFaceCutterUtil::EventQueue *p_m_eventQueue; // rbx
  __int64 v8; // r8
  unsigned __int16 m_generation; // dx
  unsigned int m_xy; // [rsp+48h] [rbp+20h]

  m_xy = pos.m_xy;
  p_m_eventQueue = &state->m_eventQueue;
  if ( state->m_eventQueue.m_heap.m_size == (state->m_eventQueue.m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_eventQueue->m_heap.m_data, 16);
    pos.m_xy = m_xy;
  }
  v8 = (__int64)&p_m_eventQueue->m_heap.m_data[p_m_eventQueue->m_heap.m_size++];
  *(_DWORD *)v8 = 4 * pos.m_xy;
  *(_WORD *)(v8 + 4) = lowerSegment;
  m_generation = state->m_segments.m_data[lowerSegment].m_generation;
  *(_WORD *)(v8 + 6) = upperSegment;
  *(_WORD *)(v8 + 8) = m_generation;
  *(_WORD *)(v8 + 10) = state->m_segments.m_data[upperSegment].m_generation;
  hkaiNewFaceCutterUtil::EventQueue::heapifyLast(p_m_eventQueue);
}

