// File Line: 111
// RVA: 0xBFD7D0
void __fastcall hkaiHeapOpenSet::insertSearchIndex(hkaiHeapOpenSet *this, int nid, float newCost)
{
  __int64 v3; // r10
  hkaiHeapOpenSet::IndexCostPair *v4; // r8
  hkaiHeapOpenSet *v5; // r11
  hkaiHeapOpenSet::IndexCostPair *v6; // rcx
  int v7; // ebx
  float v8; // er9
  int i; // er8
  __int64 v10; // rcx
  __int64 v11; // rcx

  v3 = this->m_heapSize;
  v4 = this->m_heap;
  v5 = this;
  this->m_heapSize = v3 + 1;
  v4[v3].m_idx = nid;
  v4[v3].m_cost.m_floatCost = newCost;
  v6 = this->m_heap;
  v7 = v6[v3].m_idx;
  v8 = v6[v3].m_cost.m_floatCost;
  for ( i = ((signed int)v3 - 1) / 2; (signed int)v3 > 0; i = (i - 1) / 2 )
  {
    if ( v5->m_heap[i].m_cost.m_intCost <= SLODWORD(v8) )
      break;
    v10 = (signed int)v3;
    LODWORD(v3) = i;
    v5->m_heap[v10] = v5->m_heap[i];
  }
  v11 = (signed int)v3;
  v5->m_heap[v11].m_idx = v7;
  v5->m_heap[v11].m_cost.m_floatCost = v8;
}

// File Line: 127
// RVA: 0xBFD860
__int64 __fastcall hkaiHeapOpenSet::popNextSearchIndex(hkaiHeapOpenSet *this)
{
  hkaiHeapOpenSet::IndexCostPair *v1; // r8
  int v2; // edi
  hkaiHeapOpenSet *v3; // r11
  unsigned int v4; // esi
  int v5; // ebx
  int v6; // ecx
  signed __int64 v7; // r8
  signed __int64 v8; // r9
  __int64 v9; // rax
  int v10; // eax

  v1 = this->m_heap;
  v2 = 0;
  v3 = this;
  v4 = this->m_heap->m_idx;
  *v1 = v1[--this->m_heapSize];
  v5 = this->m_heapSize;
  if ( v5 > 2 )
    v6 = (this->m_heap[1].m_cost.m_intCost > this->m_heap[2].m_cost.m_intCost) + 1;
  else
    v6 = 1;
  while ( v6 < v5 )
  {
    v7 = (signed __int64)&v3->m_heap[v6];
    v8 = (signed __int64)&v3->m_heap[v2];
    if ( *(_DWORD *)(v7 + 4) >= *(_DWORD *)(v8 + 4) )
      break;
    v9 = *(_QWORD *)v8;
    v2 = v6;
    *(_QWORD *)v8 = *(_QWORD *)v7;
    *(_QWORD *)v7 = v9;
    LODWORD(v9) = 2 * v6;
    v6 = 2 * v6 + 1;
    v10 = v9 + 2;
    if ( v10 < v3->m_heapSize )
      v6 += v3->m_heap[v6].m_cost.m_intCost > v3->m_heap[v10].m_cost.m_intCost;
  }
  return v4;
}

