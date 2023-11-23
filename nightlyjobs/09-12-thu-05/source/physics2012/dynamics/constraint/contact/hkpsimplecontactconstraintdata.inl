// File Line: 11
// RVA: 0xD840F0
void __fastcall hkpSimpleContactConstraintData::~hkpSimpleContactConstraintData(hkpSimpleContactConstraintData *this)
{
  hkpSimpleContactConstraintAtom *m_atom; // rsi
  unsigned int v3; // ebx
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d

  m_atom = this->m_atom;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleContactConstraintData::`vftable;
  if ( m_atom )
  {
    v3 = atomSizeRoundUp(m_atom->m_sizeOfAllAtoms);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpSimpleContactConstraintAtom *, _QWORD))(*Value[11] + 16i64))(
      Value[11],
      m_atom,
      v3);
  }
  m_capacityAndFlags = this->m_idMgrA.m_values.m_capacityAndFlags;
  this->m_idMgrA.m_values.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_idMgrA.m_values.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_idMgrA.m_values.m_data = 0i64;
  this->m_idMgrA.m_values.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

