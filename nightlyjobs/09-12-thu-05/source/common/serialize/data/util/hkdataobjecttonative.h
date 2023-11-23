// File Line: 64
// RVA: 0xE63020
void __fastcall hkDataObjectToNative::CopyInfoOut::addPointer(
        hkDataObjectToNative::CopyInfoOut *this,
        hkDataObject *obj,
        void *addr,
        unsigned int isOwning)
{
  hkDataObjectImpl *m_impl; // rcx
  __int128 *v8; // rax
  void *v9; // rsi
  void *v10; // rdi
  hkDataObjectToNative::PointerInfo *v11; // rcx
  __int128 v12; // [rsp+20h] [rbp-18h] BYREF

  m_impl = obj->m_impl;
  v12 = 0ui64;
  if ( m_impl )
    v8 = (__int128 *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v12);
  else
    v8 = &v12;
  v9 = *(void **)v8;
  v10 = (void *)*((_QWORD *)v8 + 1);
  if ( *(_QWORD *)v8 || v10 )
  {
    if ( this->pointersOut.m_size == (this->pointersOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->pointersOut.m_data, 32);
    v11 = &this->pointersOut.m_data[this->pointersOut.m_size++];
    v11->m_handle.p0 = v9;
    v11->m_handle.p1 = v10;
    v11->m_addr = addr;
    v11->m_isOwning.m_bool = isOwning != 0;
    v11->m_isVariant.m_bool = 0;
  }
}

// File Line: 76
// RVA: 0xE630F0
void __fastcall hkDataObjectToNative::CopyInfoOut::addVariant(
        hkDataObjectToNative::CopyInfoOut *this,
        hkDataObject *obj,
        hkVariant *addr,
        unsigned int isOwning)
{
  hkDataObjectImpl *m_impl; // rcx
  __int128 *v8; // rax
  void *v9; // rsi
  void *v10; // rdi
  hkDataObjectToNative::PointerInfo *v11; // rcx
  __int128 v12; // [rsp+20h] [rbp-18h] BYREF

  m_impl = obj->m_impl;
  v12 = 0ui64;
  if ( m_impl )
    v8 = (__int128 *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v12);
  else
    v8 = &v12;
  v9 = *(void **)v8;
  v10 = (void *)*((_QWORD *)v8 + 1);
  if ( *(_QWORD *)v8 || v10 )
  {
    if ( this->pointersOut.m_size == (this->pointersOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->pointersOut.m_data, 32);
    v11 = &this->pointersOut.m_data[this->pointersOut.m_size++];
    v11->m_handle.p0 = v9;
    v11->m_handle.p1 = v10;
    v11->m_addr = addr;
    v11->m_isOwning.m_bool = isOwning != 0;
    v11->m_isVariant.m_bool = 1;
  }
}

// File Line: 88
// RVA: 0xE62FB0
void __fastcall hkDataObjectToNative::CopyInfoOut::addAlloc(hkDataObjectToNative::CopyInfoOut *this, void *p, int size)
{
  hkArray<hkDataObjectToNative::Alloc,hkContainerTempAllocator> *p_allocs; // rbx
  __int64 v6; // rcx

  p_allocs = &this->allocs;
  if ( this->allocs.m_size == (this->allocs.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&p_allocs->m_data, 16);
  v6 = (__int64)&p_allocs->m_data[p_allocs->m_size++];
  *(_QWORD *)v6 = p;
  *(_DWORD *)(v6 + 8) = size;
}

