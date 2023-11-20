// File Line: 108
// RVA: 0xE4CDB0
void __fastcall hkRelocationInfo::addLocal(hkRelocationInfo *this, int fromOffset, int toOffset)
{
  hkRelocationInfo *v3; // rbx
  signed __int64 v4; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = __PAIR__(toOffset, fromOffset);
  if ( this->m_local.m_size == (this->m_local.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, 8);
  v3->m_local.m_data[v3->m_local.m_size++] = (hkRelocationInfo::Local)v4;
}

// File Line: 114
// RVA: 0xE6B360
void __fastcall hkRelocationInfo::addGlobal(hkRelocationInfo *this, int fromOffset, void *toAddr, hkClass *klass, unsigned int related)
{
  signed int *v5; // rbx
  hkClass *v6; // rsi
  void *v7; // rdi
  _QWORD *v8; // rcx
  __int64 v9; // [rsp+20h] [rbp-28h]
  __int64 v10; // [rsp+38h] [rbp-10h]

  v5 = (signed int *)&this->m_global;
  v6 = klass;
  LODWORD(v10) = related;
  v7 = toAddr;
  LODWORD(v9) = fromOffset;
  if ( this->m_global.m_size == (this->m_global.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 32);
  v8 = (_QWORD *)(*(_QWORD *)v5 + 32i64 * v5[2]);
  *v8 = v9;
  v8[1] = v7;
  v8[2] = v6;
  v8[3] = v10;
  ++v5[2];
}

