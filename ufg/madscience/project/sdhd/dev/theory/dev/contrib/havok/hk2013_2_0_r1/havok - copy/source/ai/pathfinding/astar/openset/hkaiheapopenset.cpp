// File Line: 13
// RVA: 0xC1EEF0
void __fastcall hkaiHeapOpenSet::adjustValue(hkaiHeapOpenSet *this, int nid, float updatedCost)
{
  int v3; // er9
  hkaiHeapOpenSet *v4; // r11
  __int64 v5; // rcx
  __int64 v6; // r8
  hkaiHeapOpenSet::IndexCostPair *v7; // rax
  int v8; // ebx
  float v9; // er8
  int i; // er10
  __int64 v11; // rcx
  __int64 v12; // rcx

  v3 = 0;
  v4 = this;
  v5 = this->m_heapSize;
  v6 = 0i64;
  if ( v5 > 0 )
  {
    v7 = v4->m_heap;
    while ( v7->m_idx != nid )
    {
      ++v6;
      ++v3;
      ++v7;
      if ( v6 >= v5 )
        return;
    }
    v4->m_heap[v3].m_cost.m_floatCost = updatedCost;
    v8 = v4->m_heap[v3].m_idx;
    v9 = v4->m_heap[v3].m_cost.m_floatCost;
    for ( i = (v3 - 1) / 2; v3 > 0; i = (i - 1) / 2 )
    {
      if ( v4->m_heap[i].m_cost.m_intCost <= SLODWORD(v9) )
        break;
      v11 = v3;
      v3 = i;
      v4->m_heap[v11] = v4->m_heap[i];
    }
    v12 = v3;
    v4->m_heap[v12].m_idx = v8;
    v4->m_heap[v12].m_cost.m_floatCost = v9;
  }
}

