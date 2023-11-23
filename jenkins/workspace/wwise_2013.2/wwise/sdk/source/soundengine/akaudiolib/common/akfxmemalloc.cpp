// File Line: 19
// RVA: 0x15BE030
__int64 dynamic_initializer_for__AkFXMemAlloc::m_instanceUpper__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AkFXMemAlloc::m_instanceUpper__);
}

// File Line: 20
// RVA: 0x15BE020
__int64 dynamic_initializer_for__AkFXMemAlloc::m_instanceLower__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AkFXMemAlloc::m_instanceLower__);
}

// File Line: 46
// RVA: 0xA68040
void *__fastcall AkFXMemAlloc::Malloc(AkFXMemAlloc *this, unsigned __int64 in_uSize)
{
  return AK::MemoryMgr::Malign(this->m_poolId, in_uSize, 0x10u);
}

// File Line: 59
// RVA: 0xA68030
void __fastcall AkFXMemAlloc::Free(AkFXMemAlloc *this, void *in_pMemAddress)
{
  AK::MemoryMgr::Free(this->m_poolId, in_pMemAddress);
}

