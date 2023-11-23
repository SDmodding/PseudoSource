// File Line: 11
// RVA: 0xBF85A0
__int64 __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::upHeap(
        hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this,
        unsigned int i)
{
  int j; // ebx
  FacePriorityPair *m_data; // r9
  __int64 v5; // r11
  float m_priority; // edx
  unsigned int m_faceKey; // ecx
  unsigned int m_shouldCut; // r8d

  for ( j = (int)(i - 1) >> 1; j >= 0; j = (j - 1) >> 1 )
  {
    m_data = this->m_contents.m_data;
    v5 = (int)i;
    if ( this->m_contents.m_data[i].m_priority > this->m_contents.m_data[j].m_priority )
      break;
    m_priority = m_data[i].m_priority;
    m_faceKey = m_data[v5].m_faceKey;
    m_shouldCut = m_data[v5].m_shouldCut;
    m_data[v5].m_faceKey = m_data[j].m_faceKey;
    m_data[v5].m_priority = m_data[j].m_priority;
    m_data[v5].m_shouldCut = m_data[j].m_shouldCut;
    m_data[j].m_faceKey = m_faceKey;
    m_data[j].m_priority = m_priority;
    i = j;
    m_data[j].m_shouldCut = m_shouldCut;
  }
  return i;
}

// File Line: 30
// RVA: 0xBF7D10
void __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(
        hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this,
        FacePriorityPair *entry)
{
  int m_size; // edi
  FacePriorityPair *v5; // r8

  m_size = this->m_contents.m_size;
  if ( m_size == (this->m_contents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this, 12);
  v5 = &this->m_contents.m_data[this->m_contents.m_size];
  if ( v5 )
  {
    v5->m_faceKey = entry->m_faceKey;
    v5->m_priority = entry->m_priority;
    v5->m_shouldCut = entry->m_shouldCut;
  }
  ++this->m_contents.m_size;
  hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::upHeap(this, m_size);
}

// File Line: 39
// RVA: 0xBF7CD0
__int64 __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::_getSmallerChild(
        hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this,
        int i)
{
  int v2; // edx
  __int64 result; // rax
  unsigned int v4; // r10d

  v2 = 2 * i;
  result = (unsigned int)(v2 + 2);
  v4 = v2 + 1;
  if ( (int)result >= this->m_contents.m_size )
    return v4;
  if ( this->m_contents.m_data[v4].m_priority < this->m_contents.m_data[(int)result].m_priority )
    return v4;
  return result;
}

// File Line: 75
// RVA: 0xBF7E30
__int64 __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::downHeap(
        hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this,
        int i)
{
  int m_size; // ebp
  int v3; // ebx
  int j; // edi
  FacePriorityPair *m_data; // r9
  __int64 v7; // r11
  unsigned int m_faceKey; // ecx
  float m_priority; // edx
  unsigned int m_shouldCut; // r8d

  m_size = this->m_contents.m_size;
  v3 = i;
  for ( j = hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::_getSmallerChild(this, i);
        j < m_size;
        j = hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::_getSmallerChild(this, j) )
  {
    m_data = this->m_contents.m_data;
    v7 = v3;
    if ( this->m_contents.m_data[v3].m_priority <= this->m_contents.m_data[j].m_priority )
      break;
    m_faceKey = m_data[v3].m_faceKey;
    m_priority = m_data[v3].m_priority;
    m_shouldCut = m_data[v3].m_shouldCut;
    m_data[v3].m_faceKey = m_data[j].m_faceKey;
    m_data[v3].m_priority = m_data[j].m_priority;
    v3 = j;
    m_data[v7].m_shouldCut = m_data[j].m_shouldCut;
    m_data[j].m_faceKey = m_faceKey;
    m_data[j].m_priority = m_priority;
    m_data[j].m_shouldCut = m_shouldCut;
  }
  return (unsigned int)v3;
}

// File Line: 97
// RVA: 0xBF8180
void __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::removeEntry(
        hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this,
        int removeIndex)
{
  int v2; // eax
  FacePriorityPair *m_data; // r9
  bool v4; // cf

  v2 = this->m_contents.m_size - 1;
  if ( removeIndex == v2 )
  {
    this->m_contents.m_size = v2;
  }
  else
  {
    m_data = this->m_contents.m_data;
    v4 = m_data[v2].m_priority < m_data[removeIndex].m_priority;
    m_data[removeIndex] = m_data[v2];
    --this->m_contents.m_size;
    if ( v4 )
      hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::upHeap(this, removeIndex);
    else
      hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::downHeap(this, removeIndex);
  }
}

