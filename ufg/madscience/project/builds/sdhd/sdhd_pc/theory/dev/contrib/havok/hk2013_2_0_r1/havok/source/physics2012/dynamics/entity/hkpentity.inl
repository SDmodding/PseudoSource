// File Line: 32
// RVA: 0xB7FC0
hkSmallArray<hkpEntityListener *> *__fastcall hkpEntity::getEntityListeners(hkpEntity *this)
{
  hkpEntity *v1; // rbx
  _QWORD **v2; // rax
  __int64 v3; // rax

  v1 = this;
  if ( !this->m_extendedListeners )
  {
    v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 32i64);
    if ( v3 )
    {
      *(_QWORD *)v3 = 0i64;
      *(_DWORD *)(v3 + 8) = 2147483648;
      *(_QWORD *)(v3 + 16) = 0i64;
      *(_DWORD *)(v3 + 24) = 2147483648;
    }
    else
    {
      v3 = 0i64;
    }
    v1->m_extendedListeners = (hkpEntity::ExtendedListeners *)v3;
  }
  return &v1->m_extendedListeners->m_entityListeners;
}

