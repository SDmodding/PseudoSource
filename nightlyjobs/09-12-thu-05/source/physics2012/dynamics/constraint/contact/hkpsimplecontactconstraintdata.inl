// File Line: 11
// RVA: 0xD840F0
void __fastcall hkpSimpleContactConstraintData::~hkpSimpleContactConstraintData(hkpSimpleContactConstraintData *this)
{
  hkpSimpleContactConstraintAtom *v1; // rsi
  hkpSimpleContactConstraintData *v2; // rdi
  unsigned int v3; // ebx
  _QWORD **v4; // rax
  int v5; // er8

  v1 = this->m_atom;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleContactConstraintData::`vftable';
  if ( v1 )
  {
    v3 = atomSizeRoundUp(v1->m_sizeOfAllAtoms);
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpSimpleContactConstraintAtom *, _QWORD))(*v4[11] + 16i64))(v4[11], v1, v3);
  }
  v5 = v2->m_idMgrA.m_values.m_capacityAndFlags;
  v2->m_idMgrA.m_values.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_idMgrA.m_values.m_data,
      v5 & 0x3FFFFFFF);
  v2->m_idMgrA.m_values.m_data = 0i64;
  v2->m_idMgrA.m_values.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

