// File Line: 32
// RVA: 0xEEB974
OSuite::ZDateTime *__fastcall OSuite::ZBufferedReader::GetModificationDate(OSuite::ZBufferedReader *this)
{
  if ( (`OSuite::ZBufferedReader::GetModificationDate::`2::`local static guard & 1) == 0 )
  {
    `OSuite::ZBufferedReader::GetModificationDate::`2::`local static guard |= 1u;
    OSuite::ZDateTime::ZDateTime(&`OSuite::ZBufferedReader::GetModificationDate::`2::foo);
    atexit(`OSuite::ZBufferedReader::GetModificationDate::`2::`dynamic atexit destructor for foo);
  }
  return &`OSuite::ZBufferedReader::GetModificationDate::`2::foo;
}

// File Line: 33
// RVA: 0xEEB9B0
OSuite::ZString *__fastcall OSuite::ZBufferedReader::GetName(OSuite::ZBufferedReader *this)
{
  if ( (`OSuite::ZBufferedReader::GetName::`2::`local static guard & 1) == 0 )
  {
    `OSuite::ZBufferedReader::GetName::`2::foo.m_pString = 0i64;
    `OSuite::ZBufferedReader::GetName::`2::`local static guard |= 1u;
    OSuite::ZString::ZString(&`OSuite::ZBufferedReader::GetName::`2::foo, "ZBufferedReader");
    atexit(`OSuite::ZBufferedReader::GetName::`2::`dynamic atexit destructor for foo);
  }
  return &`OSuite::ZBufferedReader::GetName::`2::foo;
}

// File Line: 54
// RVA: 0xEEBDA4
__int64 __fastcall OSuite::ZBufferedReader::Size(OSuite::ZBufferedReader *this)
{
  return (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 56i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead);
}

// File Line: 59
// RVA: 0xEEBC74
__int64 __fastcall OSuite::ZBufferedReader::ReadyToRead(OSuite::ZBufferedReader *this)
{
  OSuite::ZMemoryBufferChain *p_m_memoryBufferChain; // rbx
  __int64 v2; // rdi

  p_m_memoryBufferChain = &this->m_memoryBufferChain;
  v2 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 64i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead);
  return v2
       + ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))p_m_memoryBufferChain->OSuite::ZObject::vfptr[8].__vecDelDtor)(p_m_memoryBufferChain);
}

// File Line: 68
// RVA: 0xEEB8A8
bool __fastcall OSuite::ZBufferedReader::Eof(OSuite::ZBufferedReader *this)
{
  if ( ((unsigned __int8 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->m_memoryBufferChain.vfptr[10].__vecDelDtor)(&this->m_memoryBufferChain) )
    return (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 80i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead);
  else
    return 0;
}

