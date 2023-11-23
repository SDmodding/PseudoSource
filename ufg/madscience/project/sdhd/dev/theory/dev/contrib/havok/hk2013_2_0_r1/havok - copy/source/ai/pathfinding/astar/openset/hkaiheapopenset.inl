// File Line: 111
// RVA: 0xBFD7D0
void __fastcall hkaiHeapOpenSet::insertSearchIndex(hkaiHeapOpenSet *this, int nid, float newCost)
{
  __int64 m_heapSize; // r10
  hkaiHeapOpenSet::IndexCostPair *m_heap; // r8
  hkaiHeapOpenSet::IndexCostPair *v6; // rcx
  int m_idx; // ebx
  hkaiHeapOpenSet::IndexCostPair::CostUnion v8; // r9d
  int i; // r8d
  __int64 v10; // rcx

  m_heapSize = this->m_heapSize;
  m_heap = this->m_heap;
  this->m_heapSize = m_heapSize + 1;
  m_heap[m_heapSize].m_idx = nid;
  m_heap[m_heapSize].m_cost.m_floatCost = newCost;
  v6 = this->m_heap;
  m_idx = v6[m_heapSize].m_idx;
  LODWORD(v8.m_floatCost) = v6[m_heapSize].m_cost;
  for ( i = ((int)m_heapSize - 1) / 2; (int)m_heapSize > 0; i = (i - 1) / 2 )
  {
    if ( this->m_heap[i].m_cost.m_intCost <= v8.m_intCost )
      break;
    v10 = (int)m_heapSize;
    LODWORD(m_heapSize) = i;
    this->m_heap[v10] = this->m_heap[i];
  }
  this->m_heap[(int)m_heapSize].m_idx = m_idx;
  this->m_heap[(int)m_heapSize].m_cost = v8;
}

// File Line: 127
// RVA: 0xBFD860
__int64 __fastcall hkaiHeapOpenSet::popNextSearchIndex(hkaiHeapOpenSet *this)
{
  hkaiHeapOpenSet::IndexCostPair *m_heap; // r8
  int v2; // edi
  unsigned int m_idx; // esi
  int m_heapSize; // ebx
  int v6; // ecx
  hkaiHeapOpenSet::IndexCostPair *v7; // r8
  hkaiHeapOpenSet::IndexCostPair *v8; // r9
  hkaiHeapOpenSet::IndexCostPair v9; // rax
  int v10; // eax

  m_heap = this->m_heap;
  v2 = 0;
  m_idx = this->m_heap->m_idx;
  *m_heap = m_heap[--this->m_heapSize];
  m_heapSize = this->m_heapSize;
  if ( m_heapSize > 2 )
    v6 = (this->m_heap[1].m_cost.m_intCost > this->m_heap[2].m_cost.m_intCost) + 1;
  else
    v6 = 1;
  while ( v6 < m_heapSize )
  {
    v7 = &this->m_heap[v6];
    v8 = &this->m_heap[v2];
    if ( v7->m_cost.m_intCost >= v8->m_cost.m_intCost )
      break;
    v9 = *v8;
    v2 = v6;
    *v8 = *v7;
    *v7 = v9;
    v9.m_idx = 2 * v6;
    v6 = 2 * v6 + 1;
    v10 = v9.m_idx + 2;
    if ( v10 < this->m_heapSize )
      v6 += this->m_heap[v6].m_cost.m_intCost > this->m_heap[v10].m_cost.m_intCost;
  }
  return m_idx;
}

