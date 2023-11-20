// File Line: 237
// RVA: 0xEE8158
OSuite::ZDateTime *__fastcall OSuite::ZMemoryBufferChain::GetModificationDate(OSuite::ZMemoryBufferChain *this)
{
  if ( !(`OSuite::ZMemoryBufferChain::GetModificationDate'::`2'::`local static guard' & 1) )
  {
    `OSuite::ZMemoryBufferChain::GetModificationDate'::`2'::`local static guard' |= 1u;
    OSuite::ZDateTime::ZDateTime(&`OSuite::ZMemoryBufferChain::GetModificationDate'::`2'::foo);
    atexit(`OSuite::ZMemoryBufferChain::GetModificationDate'::`2'::`dynamic atexit destructor for 'foo'');
  }
  return &`OSuite::ZMemoryBufferChain::GetModificationDate'::`2'::foo;
}

// File Line: 238
// RVA: 0xEE8194
OSuite::ZString *__fastcall OSuite::ZMemoryBufferChain::GetName(OSuite::ZMemoryBufferChain *this)
{
  if ( !(`OSuite::ZMemoryBufferChain::GetName'::`2'::`local static guard' & 1) )
  {
    `OSuite::ZMemoryBufferChain::GetName'::`2'::foo.m_pString = 0i64;
    `OSuite::ZMemoryBufferChain::GetName'::`2'::`local static guard' |= 1u;
    OSuite::ZString::ZString(&`OSuite::ZMemoryBufferChain::GetName'::`2'::foo, "ZMemoryBufferChain");
    atexit(`OSuite::ZMemoryBufferChain::GetName'::`2'::`dynamic atexit destructor for 'foo'');
  }
  return &`OSuite::ZMemoryBufferChain::GetName'::`2'::foo;
}

// File Line: 255
// RVA: 0xEE8528
unsigned __int64 __fastcall OSuite::ZMemoryBufferChain::Size(OSuite::ZMemoryBufferChain *this)
{
  OSuite::IReaderVtbl *v1; // rcx
  unsigned __int64 result; // rax
  unsigned __int64 i; // rdx

  v1 = this->vfptr;
  result = 0i64;
  if ( v1 && v1->ReadByte )
  {
    for ( i = (unsigned __int64)v1->Rewind; ; i += (unsigned __int64)v1->Rewind )
    {
      v1 = (OSuite::IReaderVtbl *)*((_QWORD *)&v1->__vecDelDtor + 1);
      if ( !v1 )
        break;
    }
    result = i;
  }
  return result;
}

// File Line: 273
// RVA: 0xEE83A4
unsigned __int64 __fastcall OSuite::ZMemoryBufferChain::ReadyToRead(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZMemoryBuffer *v1; // rcx
  unsigned __int64 result; // rax
  unsigned __int64 i; // rdx

  v1 = this->m_firstBuffer;
  result = 0i64;
  if ( v1 && v1->m_pBuffer )
  {
    for ( i = v1->m_nRemainingDataLength; ; i += v1->m_nRemainingDataLength )
    {
      v1 = v1->m_pNext;
      if ( !v1 )
        break;
    }
    result = i;
  }
  return result;
}

// File Line: 278
// RVA: 0xEE8628
__int64 __fastcall OSuite::ZMemoryBufferChain::Tell(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZMemoryBufferChain *v1; // rdi
  __int64 v2; // rbx

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[8].__vecDelDtor)();
  return ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v1->vfptr[7].__vecDelDtor)(v1) - v2;
}

// File Line: 283
// RVA: 0xEE810C
bool __fastcall OSuite::ZMemoryBufferChain::Eof(OSuite::ZMemoryBufferChain *this)
{
  return ((__int64 (*)(void))this->vfptr[8].__vecDelDtor)() == 0;
}

