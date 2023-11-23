// File Line: 13
// RVA: 0xC1EEF0
void __fastcall hkaiHeapOpenSet::adjustValue(hkaiHeapOpenSet *this, int nid, float updatedCost)
{
  int v3; // r9d
  __int64 m_heapSize; // rcx
  __int64 v6; // r8
  hkaiHeapOpenSet::IndexCostPair *i; // rax
  int m_idx; // ebx
  hkaiHeapOpenSet::IndexCostPair::CostUnion v9; // r8d
  int j; // r10d
  __int64 v11; // rcx

  v3 = 0;
  m_heapSize = this->m_heapSize;
  v6 = 0i64;
  if ( m_heapSize > 0 )
  {
    for ( i = this->m_heap; i->m_idx != nid; ++i )
    {
      ++v6;
      ++v3;
      if ( v6 >= m_heapSize )
        return;
    }
    this->m_heap[v3].m_cost.m_floatCost = updatedCost;
    m_idx = this->m_heap[v3].m_idx;
    LODWORD(v9.m_floatCost) = this->m_heap[v3].m_cost;
    for ( j = (v3 - 1) / 2; v3 > 0; j = (j - 1) / 2 )
    {
      if ( this->m_heap[j].m_cost.m_intCost <= v9.m_intCost )
        break;
      v11 = v3;
      v3 = j;
      this->m_heap[v11] = this->m_heap[j];
    }
    this->m_heap[v3].m_idx = m_idx;
    this->m_heap[v3].m_cost = v9;
  }
}

