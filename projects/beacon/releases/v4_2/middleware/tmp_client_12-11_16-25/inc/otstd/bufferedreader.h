// File Line: 32
// RVA: 0xEEB974
OSuite::ZDateTime *__fastcall OSuite::ZBufferedReader::GetModificationDate(OSuite::ZBufferedReader *this)
{
  if ( !(`OSuite::ZBufferedReader::GetModificationDate::`2::`local static guard & 1) )
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
  if ( !(`OSuite::ZBufferedReader::GetName::`2::`local static guard & 1) )
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
  return (*(__int64 (**)(void))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 56i64))();
}

// File Line: 59
// RVA: 0xEEBC74
__int64 __fastcall OSuite::ZBufferedReader::ReadyToRead(OSuite::ZBufferedReader *this)
{
  OSuite::ZMemoryBufferChain *v1; // rbx
  __int64 v2; // rdi

  v1 = &this->m_memoryBufferChain;
  v2 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 64i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead);
  return v2 + ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v1->vfptr[8].__vecDelDtor)(v1);
}

// File Line: 68
// RVA: 0xEEB8A8
bool __fastcall OSuite::ZBufferedReader::Eof(OSuite::ZBufferedReader *this)
{
  OSuite::ZBufferedReader *v1; // rbx
  bool result; // al

  v1 = this;
  if ( ((unsigned __int8 (*)(void))this->m_memoryBufferChain.vfptr[10].__vecDelDtor)() )
    result = (*(__int64 (**)(void))(**(_QWORD **)&v1->m_memoryBufferChain.m_bDeleteOnRead + 80i64))();
  else
    result = 0;
  return result;
}

