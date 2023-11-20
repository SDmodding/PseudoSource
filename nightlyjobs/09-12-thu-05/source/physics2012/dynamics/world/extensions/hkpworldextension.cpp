// File Line: 16
// RVA: 0xD8AC20
void __fastcall hkpWorldExtension::hkpWorldExtension(hkpWorldExtension *this, int id)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_id = id;
  this->vfptr = (hkBaseObjectVtbl *)&hkpWorldExtension::`vftable;
  this->m_world = 0i64;
  this->m_attachmentCount = 0;
}

