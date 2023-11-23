// File Line: 32
// RVA: 0xB7FC0
hkSmallArray<hkpEntityListener *> *__fastcall hkpEntity::getEntityListeners(hkpEntity *this)
{
  _QWORD **Value; // rax
  __int64 v3; // rax

  if ( !this->m_extendedListeners )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v3 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    if ( v3 )
    {
      *(_QWORD *)v3 = 0i64;
      *(_DWORD *)(v3 + 8) = 0x80000000;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_DWORD *)(v3 + 24) = 0x80000000;
    }
    else
    {
      v3 = 0i64;
    }
    this->m_extendedListeners = (hkpEntity::ExtendedListeners *)v3;
  }
  return &this->m_extendedListeners->m_entityListeners;
}

