// File Line: 16
// RVA: 0x12F48B0
void __fastcall hkaiNewFaceCutterUtil::EventQueue::EventQueue(hkaiNewFaceCutterUtil::EventQueue *this)
{
  hkaiNewFaceCutterUtil::EventQueue *v1; // rbx
  hkResult result; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->m_heap.m_capacityAndFlags = 2147483648;
  this->m_heap.m_data = 0i64;
  this->m_heap.m_size = 0;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 32, 16);
  v1->m_heap.m_size = 1;
}

// File Line: 22
// RVA: 0x12F4900
void __fastcall hkaiNewFaceCutterUtil::EventQueue::insert(hkaiNewFaceCutterUtil::EventQueue *this, hkaiNewFaceCutterUtil::Event *event)
{
  __m128i *v2; // rdi
  hkaiNewFaceCutterUtil::EventQueue *v3; // rbx

  v2 = (__m128i *)event;
  v3 = this;
  if ( this->m_heap.m_size == (this->m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 16);
  _mm_store_si128((__m128i *)&v3->m_heap.m_data[v3->m_heap.m_size++], *v2);
  hkaiNewFaceCutterUtil::EventQueue::upHeap(v3, v3->m_heap.m_size - 1);
}

// File Line: 28
// RVA: 0x12F4970
void __fastcall hkaiNewFaceCutterUtil::EventQueue::popFront(hkaiNewFaceCutterUtil::EventQueue *this)
{
  __int64 v1; // rax

  v1 = this->m_heap.m_size;
  if ( (signed int)v1 <= 2 )
  {
    this->m_heap.m_size = 1;
  }
  else
  {
    _mm_store_si128((__m128i *)&this->m_heap.m_data[1], (__m128i)this->m_heap.m_data[v1 - 1]);
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
  hkaiNewFaceCutterUtil::EventQueue *v1; // rdi
  int i; // ebx

  v1 = this;
  for ( i = this->m_heap.m_size / 2; i >= 1; --i )
    hkaiNewFaceCutterUtil::EventQueue::downHeap(v1, i);
}

// File Line: 66
// RVA: 0x12F4A50
void __fastcall hkaiNewFaceCutterUtil::EventQueue::upHeap(hkaiNewFaceCutterUtil::EventQueue *this, unsigned int i)
{
  hkaiNewFaceCutterUtil::EventQueue *v2; // r10
  __m128i v3; // xmm1
  hkaiNewFaceCutterUtil::Event *v4; // r8
  unsigned int v5; // eax
  __m128i v6; // xmm0
  __int64 v7; // rcx
  hkaiNewFaceCutterUtil::Event v8; // [rsp+0h] [rbp-18h]

  v2 = this;
  v3 = (__m128i)this->m_heap.m_data[i];
  v8 = this->m_heap.m_data[i];
  if ( i != 1 )
  {
    do
    {
      v4 = v2->m_heap.m_data;
      v5 = i >> 1;
      if ( v8.m_posAndType >= v2->m_heap.m_data[i >> 1].m_posAndType )
        break;
      v6 = (__m128i)v4[i >> 1];
      v7 = (signed int)i;
      i >>= 1;
      _mm_store_si128((__m128i *)&v4[v7], v6);
    }
    while ( v5 != 1 );
  }
  _mm_store_si128((__m128i *)&v2->m_heap.m_data[i], v3);
}

// File Line: 87
// RVA: 0x12F4AC0
void __fastcall hkaiNewFaceCutterUtil::EventQueue::downHeap(hkaiNewFaceCutterUtil::EventQueue *this, unsigned int i)
{
  unsigned int v2; // ebx
  hkaiNewFaceCutterUtil::EventQueue *v3; // r11
  unsigned int v4; // edi
  __m128i v5; // xmm1
  unsigned int v6; // esi
  hkaiNewFaceCutterUtil::Event *v7; // r10
  signed int v8; // er9
  __int64 v9; // rax
  signed int v10; // ecx
  __int64 v11; // rax

  v2 = this->m_heap.m_size - 1;
  v3 = this;
  v4 = (unsigned int)(this->m_heap.m_size - 2) >> 1;
  v5 = (__m128i)this->m_heap.m_data[i];
  v6 = (unsigned int)this->m_heap.m_data[i];
  if ( i > v4 )
  {
LABEL_6:
    if ( i == ((v2 >> 1) & ((v2 & 1) - 1)) )
    {
      v10 = 2 * i;
      if ( v3->m_heap.m_data[2 * i].m_posAndType < v6 )
      {
        v11 = (signed int)i;
        i *= 2;
        _mm_store_si128((__m128i *)&v3->m_heap.m_data[v11], (__m128i)v3->m_heap.m_data[v10]);
      }
    }
    _mm_store_si128((__m128i *)&v3->m_heap.m_data[i], v5);
  }
  else
  {
    while ( 1 )
    {
      v7 = this->m_heap.m_data;
      v8 = 2 * i | 1;
      if ( this->m_heap.m_data[2 * i].m_posAndType < this->m_heap.m_data[v8].m_posAndType )
        v8 = 2 * i;
      if ( v7[v8].m_posAndType >= v6 )
        break;
      v9 = (signed int)i;
      i = v8;
      _mm_store_si128((__m128i *)&v7[v9], (__m128i)v7[v8]);
      if ( v8 > v4 )
        goto LABEL_6;
    }
    _mm_store_si128((__m128i *)&v7[i], v5);
  }
}

// File Line: 126
// RVA: 0x12F4A30
hkaiNewFaceCutterUtil::Event *__fastcall hkaiNewFaceCutterUtil::EventQueue::peekAt(hkaiNewFaceCutterUtil::EventQueue *this, int idx)
{
  return &this->m_heap.m_data[idx + 1];
}

// File Line: 133
// RVA: 0x12F4BC0
void __fastcall hkaiNewFaceCutterUtil::enqueueStartSegmentEvent(hkaiNewFaceCutterUtil::State *state, __int16 segmentIndex, hkaiNewFaceCutterUtil::Vec2 pos)
{
  hkaiNewFaceCutterUtil::EventQueue *v3; // rbx
  __int16 v4; // di
  signed __int64 v5; // rdx
  unsigned int v6; // [rsp+40h] [rbp+18h]

  v6 = pos.m_xy;
  v3 = &state->m_eventQueue;
  v4 = segmentIndex;
  if ( state->m_eventQueue.m_heap.m_size == (state->m_eventQueue.m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 16);
    pos.m_xy = v6;
  }
  v5 = (signed __int64)&v3->m_heap.m_data[v3->m_heap.m_size++];
  *(_DWORD *)v5 = 4 * pos.m_xy | 1;
  *(_WORD *)(v5 + 6) = -1;
  *(_WORD *)(v5 + 4) = v4;
  hkaiNewFaceCutterUtil::EventQueue::heapifyLast(v3);
}

// File Line: 144
// RVA: 0x12F4C50
void __fastcall hkaiNewFaceCutterUtil::enqueueStartSegmentsEventNoHeapify(hkaiNewFaceCutterUtil::State *state, __int16 segmentIndexA, __int16 segmentIndexB, hkaiNewFaceCutterUtil::Vec2 pos)
{
  hkaiNewFaceCutterUtil::EventQueue *v4; // rbx
  __int16 v5; // di
  __int16 v6; // si
  signed __int64 v7; // rcx
  unsigned int v8; // [rsp+48h] [rbp+20h]

  v8 = pos.m_xy;
  v4 = &state->m_eventQueue;
  v5 = segmentIndexB;
  v6 = segmentIndexA;
  if ( state->m_eventQueue.m_heap.m_size == (state->m_eventQueue.m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
    pos.m_xy = v8;
  }
  v7 = (signed __int64)&v4->m_heap.m_data[v4->m_heap.m_size++];
  *(_WORD *)(v7 + 4) = v6;
  *(_DWORD *)v7 = 4 * pos.m_xy | 1;
  *(_WORD *)(v7 + 6) = v5;
}

// File Line: 154
// RVA: 0x12F4CE0
void __fastcall hkaiNewFaceCutterUtil::enqueueIntersectionEvent(hkaiNewFaceCutterUtil::State *state, __int16 lowerSegment, __int16 upperSegment, hkaiNewFaceCutterUtil::Vec2 pos)
{
  hkaiNewFaceCutterUtil::EventQueue *v4; // rbx
  __int16 v5; // si
  __int16 v6; // bp
  hkaiNewFaceCutterUtil::State *v7; // rdi
  signed __int64 v8; // r8
  unsigned __int16 v9; // dx
  unsigned int v10; // [rsp+48h] [rbp+20h]

  v10 = pos.m_xy;
  v4 = &state->m_eventQueue;
  v5 = upperSegment;
  v6 = lowerSegment;
  v7 = state;
  if ( state->m_eventQueue.m_heap.m_size == (state->m_eventQueue.m_heap.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
    pos.m_xy = v10;
  }
  v8 = (signed __int64)&v4->m_heap.m_data[v4->m_heap.m_size++];
  *(_DWORD *)v8 = 4 * pos.m_xy;
  *(_WORD *)(v8 + 4) = v6;
  v9 = v7->m_segments.m_data[v6].m_generation;
  *(_WORD *)(v8 + 6) = v5;
  *(_WORD *)(v8 + 8) = v9;
  *(_WORD *)(v8 + 10) = v7->m_segments.m_data[v5].m_generation;
  hkaiNewFaceCutterUtil::EventQueue::heapifyLast(v4);
}

