// File Line: 11
// RVA: 0xBF85A0
__int64 __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::upHeap(hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this, int i)
{
  hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *v2; // rdi
  int j; // ebx
  FacePriorityPair *v4; // r9
  signed __int64 v5; // r11
  float v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // er8

  v2 = this;
  for ( j = (i - 1) >> 1; j >= 0; j = (j - 1) >> 1 )
  {
    v4 = v2->m_contents.m_data;
    v5 = i;
    if ( v2->m_contents.m_data[i].m_priority > v2->m_contents.m_data[j].m_priority )
      break;
    v6 = v4[i].m_priority;
    v7 = v4[v5].m_faceKey;
    v8 = v4[v5].m_shouldCut;
    v4[v5].m_faceKey = v4[j].m_faceKey;
    v4[v5].m_priority = v4[j].m_priority;
    v4[v5].m_shouldCut = v4[j].m_shouldCut;
    v4[j].m_faceKey = v7;
    v4[j].m_priority = v6;
    i = j;
    v4[j].m_shouldCut = v8;
  }
  return (unsigned int)i;
}

// File Line: 30
// RVA: 0xBF7D10
void __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::addEntry(hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this, FacePriorityPair *entry)
{
  int v2; // edi
  FacePriorityPair *v3; // rsi
  hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *v4; // rbx
  FacePriorityPair *v5; // r8

  v2 = this->m_contents.m_size;
  v3 = entry;
  v4 = this;
  if ( v2 == (this->m_contents.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 12);
  v5 = &v4->m_contents.m_data[v4->m_contents.m_size];
  if ( v5 )
  {
    v5->m_faceKey = v3->m_faceKey;
    v5->m_priority = v3->m_priority;
    v5->m_shouldCut = v3->m_shouldCut;
  }
  ++v4->m_contents.m_size;
  hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::upHeap(v4, v2);
}

// File Line: 39
// RVA: 0xBF7CD0
__int64 __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::_getSmallerChild(hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this, int i)
{
  int v2; // edx
  __int64 result; // rax
  unsigned int v4; // er10

  v2 = 2 * i;
  result = (unsigned int)(v2 + 2);
  v4 = v2 + 1;
  if ( (signed int)result >= this->m_contents.m_size )
    return v4;
  if ( this->m_contents.m_data[v4].m_priority < this->m_contents.m_data[(signed int)result].m_priority )
    result = v4;
  return result;
}

// File Line: 75
// RVA: 0xBF7E30
__int64 __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::downHeap(hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this, int i)
{
  int v2; // ebp
  int v3; // ebx
  hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *v4; // rsi
  int j; // edi
  FacePriorityPair *v6; // r9
  signed __int64 v7; // r11
  unsigned int v8; // ecx
  float v9; // edx
  unsigned int v10; // er8

  v2 = this->m_contents.m_size;
  v3 = i;
  v4 = this;
  for ( j = hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::_getSmallerChild(this, i);
        j < v2;
        j = hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::_getSmallerChild(v4, j) )
  {
    v6 = v4->m_contents.m_data;
    v7 = v3;
    if ( v4->m_contents.m_data[v3].m_priority <= v4->m_contents.m_data[j].m_priority )
      break;
    v8 = v6[v3].m_faceKey;
    v9 = v6[v3].m_priority;
    v10 = v6[v3].m_shouldCut;
    v6[v3].m_faceKey = v6[j].m_faceKey;
    v6[v3].m_priority = v6[j].m_priority;
    v3 = j;
    v6[v7].m_shouldCut = v6[j].m_shouldCut;
    v6[j].m_faceKey = v8;
    v6[j].m_priority = v9;
    v6[j].m_shouldCut = v10;
  }
  return (unsigned int)v3;
}

// File Line: 97
// RVA: 0xBF8180
void __fastcall hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::removeEntry(hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *this, int removeIndex)
{
  hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair> > *v2; // r10
  int v3; // eax
  FacePriorityPair *v4; // r9
  signed __int64 v5; // rcx
  bool v6; // cf

  v2 = this;
  v3 = this->m_contents.m_size - 1;
  if ( removeIndex == v3 )
  {
    this->m_contents.m_size = v3;
  }
  else
  {
    v4 = this->m_contents.m_data;
    v5 = removeIndex;
    v6 = v4[v3].m_priority < v4[removeIndex].m_priority;
    v4[v5].m_faceKey = v4[v3].m_faceKey;
    v4[v5].m_priority = v4[v3].m_priority;
    v4[v5].m_shouldCut = v4[v3].m_shouldCut;
    --v2->m_contents.m_size;
    JUMPOUT(v6 != 0, hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::upHeap);
    hkMinHeap<FacePriorityPair,hkMinHeapDefaultOperations<FacePriorityPair>>::downHeap(v2, removeIndex);
  }
}

