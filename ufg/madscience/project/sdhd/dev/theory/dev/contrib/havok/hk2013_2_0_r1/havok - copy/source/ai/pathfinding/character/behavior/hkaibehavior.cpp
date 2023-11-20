// File Line: 14
// RVA: 0xBD4B60
void __fastcall hkaiBehavior::getCharacters(hkaiBehavior *this, hkArray<hkaiCharacter *,hkContainerTempAllocator> *characters)
{
  hkArray<hkaiCharacter *,hkContainerTempAllocator> *v2; // rbx
  hkaiBehavior *v3; // rsi
  unsigned int v4; // edi
  int v5; // er14
  __int64 v6; // rbp

  v2 = characters;
  v3 = this;
  v4 = 0;
  v5 = ((__int64 (*)(void))this->vfptr[6].__vecDelDtor)();
  if ( v5 > 0 )
  {
    do
    {
      v6 = ((__int64 (__fastcall *)(hkaiBehavior *, _QWORD))v3->vfptr[6].__first_virtual_table_function__)(v3, v4);
      if ( v2->m_size == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v2, 8);
      ++v4;
      v2->m_data[v2->m_size++] = (hkaiCharacter *)v6;
    }
    while ( (signed int)v4 < v5 );
  }
}

// File Line: 23
// RVA: 0xBD4B20
void __fastcall hkaiBehavior::requestPath(hkaiBehavior *this, hkVector4f *goal, int priority)
{
  ((void (__fastcall *)(hkaiBehavior *, hkVector4f *, signed __int64, _QWORD))this->vfptr[4].__first_virtual_table_function__)(
    this,
    goal,
    1i64,
    (unsigned int)priority);
}

// File Line: 28
// RVA: 0xBD4B40
void __fastcall hkaiBehavior::requestVolumePath(hkaiBehavior *this, hkVector4f *goal, int priority)
{
  ((void (__fastcall *)(hkaiBehavior *, hkVector4f *, signed __int64, _QWORD))this->vfptr[5].__first_virtual_table_function__)(
    this,
    goal,
    1i64,
    (unsigned int)priority);
}

