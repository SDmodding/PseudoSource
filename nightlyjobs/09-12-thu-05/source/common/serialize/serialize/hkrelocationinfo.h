// File Line: 108
// RVA: 0xE4CDB0
void __fastcall hkRelocationInfo::addLocal(hkRelocationInfo *this, unsigned int fromOffset, unsigned int toOffset)
{
  unsigned __int64 v4; // [rsp+30h] [rbp+8h]

  v4 = __PAIR64__(toOffset, fromOffset);
  if ( this->m_local.m_size == (this->m_local.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_local.m_data, 8);
  this->m_local.m_data[this->m_local.m_size++] = (hkRelocationInfo::Local)v4;
}

// File Line: 114
// RVA: 0xE6B360
void __fastcall hkRelocationInfo::addGlobal(
        hkRelocationInfo *this,
        int fromOffset,
        void *toAddr,
        hkClass *klass,
        unsigned int related)
{
  hkArray<hkRelocationInfo::Global,hkContainerHeapAllocator> *p_m_global; // rbx
  hkRelocationInfo::Global *v8; // rcx
  __int64 v9; // [rsp+20h] [rbp-28h]
  __int64 v10; // [rsp+38h] [rbp-10h]

  p_m_global = &this->m_global;
  LODWORD(v10) = related;
  LODWORD(v9) = fromOffset;
  if ( this->m_global.m_size == (this->m_global.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_global->m_data, 32);
  v8 = &p_m_global->m_data[p_m_global->m_size];
  *(_QWORD *)&v8->m_fromOffset = v9;
  v8->m_toAddress = toAddr;
  v8->m_toClass = klass;
  *(_QWORD *)&v8->m_related = v10;
  ++p_m_global->m_size;
}

