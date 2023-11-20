// File Line: 64
// RVA: 0xE63020
void __fastcall hkDataObjectToNative::CopyInfoOut::addPointer(hkDataObjectToNative::CopyInfoOut *this, hkDataObject *obj, void *addr, unsigned int isOwning)
{
  hkDataObjectToNative::CopyInfoOut *v4; // rbx
  hkDataObjectImpl *v5; // rcx
  unsigned int v6; // ebp
  void *v7; // r14
  __m128i *v8; // rax
  __int64 v9; // rsi
  __int64 v10; // rdi
  signed __int64 v11; // rcx
  __m128i v12; // [rsp+20h] [rbp-18h]

  v4 = this;
  v5 = obj->m_impl;
  v6 = isOwning;
  v7 = addr;
  v12 = 0ui64;
  if ( v5 )
  {
    v8 = (__m128i *)v5->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v5->vfptr, (unsigned int)&v12);
  }
  else
  {
    v8 = &v12;
    _mm_store_si128(&v12, v12);
  }
  v9 = v8->m128i_i64[0];
  v10 = v8->m128i_i64[1];
  if ( v8->m128i_i64[0] || v10 )
  {
    if ( v4->pointersOut.m_size == (v4->pointersOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 32);
    v11 = (signed __int64)&v4->pointersOut.m_data[v4->pointersOut.m_size++];
    *(_QWORD *)v11 = v9;
    *(_QWORD *)(v11 + 8) = v10;
    *(_QWORD *)(v11 + 16) = v7;
    *(_BYTE *)(v11 + 25) = v6 != 0;
    *(_BYTE *)(v11 + 24) = 0;
  }
}

// File Line: 76
// RVA: 0xE630F0
void __fastcall hkDataObjectToNative::CopyInfoOut::addVariant(hkDataObjectToNative::CopyInfoOut *this, hkDataObject *obj, hkVariant *addr, unsigned int isOwning)
{
  hkDataObjectToNative::CopyInfoOut *v4; // rbx
  hkDataObjectImpl *v5; // rcx
  unsigned int v6; // ebp
  hkVariant *v7; // r14
  __m128i *v8; // rax
  __int64 v9; // rsi
  __int64 v10; // rdi
  signed __int64 v11; // rcx
  __m128i v12; // [rsp+20h] [rbp-18h]

  v4 = this;
  v5 = obj->m_impl;
  v6 = isOwning;
  v7 = addr;
  v12 = 0ui64;
  if ( v5 )
  {
    v8 = (__m128i *)v5->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v5->vfptr, (unsigned int)&v12);
  }
  else
  {
    v8 = &v12;
    _mm_store_si128(&v12, v12);
  }
  v9 = v8->m128i_i64[0];
  v10 = v8->m128i_i64[1];
  if ( v8->m128i_i64[0] || v10 )
  {
    if ( v4->pointersOut.m_size == (v4->pointersOut.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 32);
    v11 = (signed __int64)&v4->pointersOut.m_data[v4->pointersOut.m_size++];
    *(_QWORD *)v11 = v9;
    *(_QWORD *)(v11 + 8) = v10;
    *(_QWORD *)(v11 + 16) = v7;
    *(_BYTE *)(v11 + 25) = v6 != 0;
    *(_BYTE *)(v11 + 24) = 1;
  }
}

// File Line: 88
// RVA: 0xE62FB0
void __fastcall hkDataObjectToNative::CopyInfoOut::addAlloc(hkDataObjectToNative::CopyInfoOut *this, void *p, int size)
{
  hkArray<hkDataObjectToNative::Alloc,hkContainerTempAllocator> *v3; // rbx
  int v4; // edi
  void *v5; // rsi
  signed __int64 v6; // rcx

  v3 = &this->allocs;
  v4 = size;
  v5 = p;
  if ( this->allocs.m_size == (this->allocs.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v3, 16);
  v6 = (signed __int64)&v3->m_data[v3->m_size++];
  *(_QWORD *)v6 = v5;
  *(_DWORD *)(v6 + 8) = v4;
}

