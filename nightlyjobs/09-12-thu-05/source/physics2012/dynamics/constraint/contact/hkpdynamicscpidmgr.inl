// File Line: 31
// RVA: 0xD98630
__int64 __fastcall hkpDynamicsCpIdMgr::newId(hkpDynamicsCpIdMgr *this, int value)
{
  hkpDynamicsCpIdMgr *v2; // rbx
  int v3; // ecx
  char v4; // di
  int v5; // er8
  __int64 v6; // rax
  char *v7; // r9
  __int64 result; // rax

  v2 = this;
  v3 = this->m_values.m_size;
  v4 = value;
  v5 = v3 - 1;
  v6 = v3 - 1;
  if ( v3 - 1 < 0 )
  {
LABEL_5:
    if ( v3 == (v2->m_values.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 1);
    v2->m_values.m_data[v2->m_values.m_size++] = v4;
    result = (unsigned int)(v2->m_values.m_size - 1);
  }
  else
  {
    v7 = v2->m_values.m_data;
    while ( v7[v6] != -1 )
    {
      --v5;
      if ( --v6 < 0 )
        goto LABEL_5;
    }
    result = (unsigned int)v5;
    v7[v5] = value;
  }
  return result;
}

// File Line: 88
// RVA: 0xD84250
void __fastcall hkpDynamicsCpIdMgr::getAllUsedIds(hkpDynamicsCpIdMgr *this, hkArray<unsigned short,hkContainerHeapAllocator> *ids)
{
  int v2; // ebx
  hkArray<unsigned short,hkContainerHeapAllocator> *v3; // rdi
  hkpDynamicsCpIdMgr *i; // rsi

  v2 = 0;
  v3 = ids;
  for ( i = this; v2 < i->m_values.m_size; ++v2 )
  {
    if ( i->m_values.m_data[v2] != -1 )
    {
      if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 2);
      v3->m_data[v3->m_size++] = v2;
    }
  }
}

