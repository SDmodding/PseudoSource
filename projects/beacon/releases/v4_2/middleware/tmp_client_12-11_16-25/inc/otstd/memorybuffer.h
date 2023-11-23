// File Line: 237
// RVA: 0xEE8158
OSuite::ZDateTime *__fastcall OSuite::ZMemoryBufferChain::GetModificationDate(OSuite::ZMemoryBufferChain *this)
{
  if ( (`OSuite::ZMemoryBufferChain::GetModificationDate::`2::`local static guard & 1) == 0 )
  {
    `OSuite::ZMemoryBufferChain::GetModificationDate::`2::`local static guard |= 1u;
    OSuite::ZDateTime::ZDateTime(&`OSuite::ZMemoryBufferChain::GetModificationDate::`2::foo);
    atexit(`OSuite::ZMemoryBufferChain::GetModificationDate::`2::`dynamic atexit destructor for foo);
  }
  return &`OSuite::ZMemoryBufferChain::GetModificationDate::`2::foo;
}

// File Line: 238
// RVA: 0xEE8194
OSuite::ZString *__fastcall OSuite::ZMemoryBufferChain::GetName(OSuite::ZMemoryBufferChain *this)
{
  if ( (`OSuite::ZMemoryBufferChain::GetName::`2::`local static guard & 1) == 0 )
  {
    `OSuite::ZMemoryBufferChain::GetName::`2::foo.m_pString = 0i64;
    `OSuite::ZMemoryBufferChain::GetName::`2::`local static guard |= 1u;
    OSuite::ZString::ZString(&`OSuite::ZMemoryBufferChain::GetName::`2::foo, "ZMemoryBufferChain");
    atexit(`OSuite::ZMemoryBufferChain::GetName::`2::`dynamic atexit destructor for foo);
  }
  return &`OSuite::ZMemoryBufferChain::GetName::`2::foo;
}

// File Line: 255
// RVA: 0xEE8528
bool (__fastcall *__fastcall OSuite::ZMemoryBufferChain::Size(OSuite::ZMemoryBufferChain *this))(OSuite::IReader *this)
{
  OSuite::IReaderVtbl *vfptr; // rcx
  bool (__fastcall *result)(OSuite::IReader *); // rax
  bool (__fastcall *i)(OSuite::IReader *); // rdx

  vfptr = this->OSuite::IReader::vfptr;
  result = 0i64;
  if ( vfptr && vfptr->ReadByte )
  {
    for ( i = vfptr->Rewind; ; i = (bool (__fastcall *)(OSuite::IReader *))((char *)i + (unsigned __int64)vfptr->Rewind) )
    {
      vfptr = (OSuite::IReaderVtbl *)*((_QWORD *)&vfptr->__vecDelDtor + 1);
      if ( !vfptr )
        break;
    }
    return i;
  }
  return result;
}

// File Line: 273
// RVA: 0xEE83A4
unsigned __int64 __fastcall OSuite::ZMemoryBufferChain::ReadyToRead(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZMemoryBuffer *m_firstBuffer; // rcx
  unsigned __int64 result; // rax
  unsigned __int64 i; // rdx

  m_firstBuffer = this->m_firstBuffer;
  result = 0i64;
  if ( m_firstBuffer && m_firstBuffer->m_pBuffer )
  {
    for ( i = m_firstBuffer->m_nRemainingDataLength; ; i += m_firstBuffer->m_nRemainingDataLength )
    {
      m_firstBuffer = m_firstBuffer->m_pNext;
      if ( !m_firstBuffer )
        break;
    }
    return i;
  }
  return result;
}

// File Line: 278
// RVA: 0xEE8628
__int64 __fastcall OSuite::ZMemoryBufferChain::Tell(OSuite::ZMemoryBufferChain *this)
{
  __int64 v2; // rbx

  v2 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[8].__vecDelDtor)(this);
  return ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[7].__vecDelDtor)(this) - v2;
}

// File Line: 283
// RVA: 0xEE810C
bool __fastcall OSuite::ZMemoryBufferChain::Eof(OSuite::ZMemoryBufferChain *this)
{
  return ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[8].__vecDelDtor)(this) == 0;
}

