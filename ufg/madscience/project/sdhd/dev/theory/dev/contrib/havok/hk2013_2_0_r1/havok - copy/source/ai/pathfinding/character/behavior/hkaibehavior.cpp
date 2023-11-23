// File Line: 14
// RVA: 0xBD4B60
void __fastcall hkaiBehavior::getCharacters(
        hkaiBehavior *this,
        hkArray<hkaiCharacter *,hkContainerTempAllocator> *characters)
{
  int v4; // edi
  int v5; // r14d
  hkaiCharacter *v6; // rbp

  v4 = 0;
  v5 = ((__int64 (__fastcall *)(hkaiBehavior *))this->hkReferencedObject::hkBaseObject::vfptr[6].__vecDelDtor)(this);
  if ( v5 > 0 )
  {
    do
    {
      v6 = (hkaiCharacter *)((__int64 (__fastcall *)(hkaiBehavior *, _QWORD))this->hkReferencedObject::hkBaseObject::vfptr[6].__first_virtual_table_function__)(
                              this,
                              (unsigned int)v4);
      if ( characters->m_size == (characters->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, characters, 8);
      ++v4;
      characters->m_data[characters->m_size++] = v6;
    }
    while ( v4 < v5 );
  }
}

// File Line: 23
// RVA: 0xBD4B20
void __fastcall hkaiBehavior::requestPath(hkaiBehavior *this, hkVector4f *goal, unsigned int priority)
{
  ((void (__fastcall *)(hkaiBehavior *, hkVector4f *, __int64, _QWORD))this->hkReferencedObject::hkBaseObject::vfptr[4].__first_virtual_table_function__)(
    this,
    goal,
    1i64,
    priority);
}

// File Line: 28
// RVA: 0xBD4B40
void __fastcall hkaiBehavior::requestVolumePath(hkaiBehavior *this, hkVector4f *goal, unsigned int priority)
{
  ((void (__fastcall *)(hkaiBehavior *, hkVector4f *, __int64, _QWORD))this->hkReferencedObject::hkBaseObject::vfptr[5].__first_virtual_table_function__)(
    this,
    goal,
    1i64,
    priority);
}

