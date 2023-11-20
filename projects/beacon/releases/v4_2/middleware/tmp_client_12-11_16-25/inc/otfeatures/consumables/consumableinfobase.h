// File Line: 22
// RVA: 0x13310DC
OSuite::ZHttpParser *__fastcall OSuite::ZUrl::GetProtocol(OSuite::ZHttpResponseBase *this)
{
  return &this->m_parser;
}

// File Line: 23
// RVA: 0x13310EC
__int64 __fastcall OSuite::ZConsumableInfoBase::GetQuantity(OSuite::ZConsumableInfoBase *this)
{
  return this->m_uiQuantity;
}

// File Line: 24
// RVA: 0x1331270
void __fastcall OSuite::ZConsumableInfoBase::Release(OSuite::ZConsumableInfoBase *this)
{
  if ( this )
    ((void (__fastcall *)(OSuite::ZConsumableInfoBase *, signed __int64))this->vfptr->~IConsumableInfo)(this, 1i64);
}

