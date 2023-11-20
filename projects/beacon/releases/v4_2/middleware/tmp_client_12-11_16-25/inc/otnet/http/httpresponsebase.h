// File Line: 22
// RVA: 0xEDFEF0
__int64 __fastcall OSuite::ZHttpResponseBase::GetLastError(OSuite::ZHttpResponseBase *this)
{
  return (unsigned int)this->m_nStatus;
}

// File Line: 27
// RVA: 0xEDFF08
__int64 __fastcall OSuite::ZHttpResponseBase::GetStatusCode(OSuite::ZHttpResponseBase *this)
{
  return (unsigned int)this->m_nMajorVersion;
}

// File Line: 29
// RVA: 0xEE0480
bool __fastcall OSuite::ZHttpResponseBase::IsContentText(OSuite::ZHttpResponseBase *this)
{
  return this->m_nMinorVersion;
}

// File Line: 30
// RVA: 0xEE0488
bool __fastcall OSuite::ZHttpResponseBase::IsHandled(OSuite::ZHttpResponseBase *this)
{
  return BYTE1(this->m_nMinorVersion);
}

// File Line: 64
// RVA: 0xEDFEF8
OSuite::ZObjectVtbl **__fastcall OSuite::ZHttpResponseBase::GetOSErrors(OSuite::ZHttpResponseBase *this)
{
  return &this->m_CacheControl.m_Comparer.vfptr;
}

