// File Line: 18
// RVA: 0xEEB744
void __fastcall OSuite::ZBufferedReader::ZBufferedReader(
        OSuite::ZBufferedReader *this,
        OSuite::IReader *pSource,
        unsigned __int64 prefetchSize,
        bool bReaderOwnership)
{
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZBufferedReader::`vftable{for `OSuite::ZObject};
  this->OSuite::IBufferedReader::OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)&OSuite::ZBufferedReader::`vftable{for `OSuite::IBufferedReader};
  OSuite::ZMemoryBufferChain::ZMemoryBufferChain(&this->m_memoryBufferChain, 1);
  this->m_pDecoder = 0i64;
  this->m_pSource = pSource;
  this->m_bReaderOwnership = bReaderOwnership;
  this->m_prefetchSize = prefetchSize;
}

// File Line: 24
// RVA: 0xEEB7B0
void __fastcall OSuite::ZBufferedReader::~ZBufferedReader(OSuite::ZBufferedReader *this)
{
  bool v1; // zf
  OSuite::IReader *m_pSource; // rcx
  OSuite::ZTextDecoder *m_pDecoder; // rcx

  v1 = !this->m_bReaderOwnership;
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZBufferedReader::`vftable{for `OSuite::ZObject};
  this->OSuite::IBufferedReader::OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)&OSuite::ZBufferedReader::`vftable{for `OSuite::IBufferedReader};
  if ( !v1 )
  {
    m_pSource = this->m_pSource;
    if ( m_pSource )
      m_pSource->vfptr->__vecDelDtor(m_pSource, 1u);
  }
  OSuite::ZMemoryBufferChain::~ZMemoryBufferChain(&this->m_memoryBufferChain);
  m_pDecoder = this->m_pDecoder;
  this->OSuite::IBufferedReader::OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)&OSuite::IBufferedReader::`vftable;
  if ( m_pDecoder )
    m_pDecoder->vfptr->__vecDelDtor(m_pDecoder, 1u);
  this->m_pDecoder = 0i64;
}

// File Line: 33
// RVA: 0xEEB9FC
void __fastcall OSuite::ZBufferedReader::Init(OSuite::ZBufferedReader *this, OSuite::IReaderVtbl *pDecoder)
{
  OSuite::IReaderVtbl *vfptr; // rcx

  vfptr = this->OSuite::IBufferedReader::OSuite::IReader::vfptr;
  if ( vfptr )
    (*(void (__fastcall **)(OSuite::IReaderVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
  this->OSuite::IBufferedReader::OSuite::IReader::vfptr = pDecoder;
  OSuite::ZMemoryBufferChain::AccumulateData(
    (OSuite::ZMemoryBufferChain *)&this->m_pDecoder,
    *(OSuite::IReader **)&this->m_memoryBufferChain.m_bDeleteOnRead,
    (unsigned __int64)this->m_pSource);
}

// File Line: 49
// RVA: 0xEEBA54
__int64 __fastcall OSuite::ZBufferedReader::Read(OSuite::ZBufferedReader *this, char *pDest, unsigned __int64 nCount)
{
  OSuite::ZMemoryBufferChain *p_m_memoryBufferChain; // rsi
  unsigned __int64 v7; // rax
  __int64 v8; // rbx
  __int64 v9; // rbp
  OSuite::ZObjectVtbl *vfptr; // rbx
  __int64 v12; // rax
  __int64 v13; // rbx

  p_m_memoryBufferChain = &this->m_memoryBufferChain;
  v7 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->m_memoryBufferChain.vfptr[8].__vecDelDtor)(&this->m_memoryBufferChain);
  v8 = 0i64;
  if ( !v7 )
    goto LABEL_7;
  if ( v7 < nCount )
  {
    vfptr = p_m_memoryBufferChain->OSuite::ZObject::vfptr;
    v12 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))p_m_memoryBufferChain->OSuite::ZObject::vfptr[8].__vecDelDtor)(p_m_memoryBufferChain);
    v8 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *, char *, __int64))vfptr[1].__vecDelDtor)(
           p_m_memoryBufferChain,
           pDest,
           v12);
LABEL_7:
    v13 = (*(__int64 (__fastcall **)(_QWORD, char *, unsigned __int64))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead
                                                                      + 8i64))(
            *(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead,
            &pDest[v8],
            nCount - v8)
        + v8;
    if ( !v13 )
      return 0i64;
    OSuite::ZMemoryBufferChain::AccumulateData(
      (OSuite::ZMemoryBufferChain *)&this->m_pDecoder,
      *(OSuite::IReader **)&this->m_memoryBufferChain.m_bDeleteOnRead,
      (unsigned __int64)this->m_pSource);
    return v13;
  }
  v9 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *, char *, unsigned __int64))p_m_memoryBufferChain->OSuite::ZObject::vfptr[1].__vecDelDtor)(
         p_m_memoryBufferChain,
         pDest,
         nCount);
  if ( !((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))p_m_memoryBufferChain->OSuite::ZObject::vfptr[8].__vecDelDtor)(p_m_memoryBufferChain) )
    OSuite::ZMemoryBufferChain::AccumulateData(
      (OSuite::ZMemoryBufferChain *)&this->m_pDecoder,
      *(OSuite::IReader **)&this->m_memoryBufferChain.m_bDeleteOnRead,
      (unsigned __int64)this->m_pSource);
  return v9;
}

// File Line: 74
// RVA: 0xEEB8D8
void __fastcall OSuite::ZBufferedReader::Flush(OSuite::ZBufferedReader *this)
{
  ((void (__fastcall *)(OSuite::ZMemoryBufferChain *))this->m_memoryBufferChain.vfptr[3].__vecDelDtor)(&this->m_memoryBufferChain);
  (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 24i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead);
}

// File Line: 85
// RVA: 0xEEBDB0
char __fastcall OSuite::ZBufferedReader::Skip(OSuite::ZBufferedReader *this, int nOffset)
{
  unsigned __int64 v2; // rsi
  OSuite::ZMemoryBufferChain *p_m_memoryBufferChain; // r14
  __int64 v6; // rbp
  unsigned __int64 v7; // rax
  OSuite::ZBufferedReader *v8; // rcx
  bool v9; // cf
  OSuite::ZObjectVtbl *vfptr; // rax
  __int64 v11; // rdx

  v2 = nOffset;
  if ( nOffset < 0 )
    return 0;
  if ( !nOffset )
    return 1;
  p_m_memoryBufferChain = &this->m_memoryBufferChain;
  v6 = nOffset
     - ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))p_m_memoryBufferChain->OSuite::ZObject::vfptr[8].__vecDelDtor)(p_m_memoryBufferChain);
  v7 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))p_m_memoryBufferChain->OSuite::ZObject::vfptr[8].__vecDelDtor)(p_m_memoryBufferChain);
  v8 = (OSuite::ZBufferedReader *)p_m_memoryBufferChain;
  v9 = v7 < v2;
  vfptr = p_m_memoryBufferChain->OSuite::ZObject::vfptr;
  if ( v9 )
  {
    ((void (__fastcall *)(OSuite::ZMemoryBufferChain *))vfptr[3].__vecDelDtor)(p_m_memoryBufferChain);
    if ( !OSuite::ZMemoryBufferChain::AccumulateData(
            (OSuite::ZMemoryBufferChain *)&this->m_pDecoder,
            *(OSuite::IReader **)&this->m_memoryBufferChain.m_bDeleteOnRead,
            (unsigned __int64)this->m_pSource) )
      return 0;
    vfptr = this->OSuite::ZObject::vfptr;
    v11 = (unsigned int)v6;
    v8 = this;
  }
  else
  {
    v11 = (unsigned int)v2;
  }
  return (char)vfptr[4].__vecDelDtor(v8, v11);
}

// File Line: 109
// RVA: 0xEEBCAC
void *__fastcall OSuite::ZBufferedReader::Rewind(OSuite::ZBufferedReader *this)
{
  return this->OSuite::ZObject::vfptr[6].__vecDelDtor(this, 0i64);
}

// File Line: 114
// RVA: 0xEEBCB8
char __fastcall OSuite::ZBufferedReader::SetPosition(OSuite::ZBufferedReader *this, unsigned __int64 nPosition)
{
  char v5; // bl
  OSuite::ZMemoryBufferChain *p_m_memoryBufferChain; // rsi
  __int64 v7; // rbp
  unsigned __int64 v8; // rbp

  if ( nPosition == ((__int64 (__fastcall *)(OSuite::ZBufferedReader *))this->OSuite::ZObject::vfptr[9].__vecDelDtor)(this) )
    return 1;
  if ( nPosition < (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 72i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead) )
  {
    p_m_memoryBufferChain = &this->m_memoryBufferChain;
    v7 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 72i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead);
    v8 = v7
       - ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->m_memoryBufferChain.vfptr[7].__vecDelDtor)(&this->m_memoryBufferChain);
    if ( nPosition >= v8 )
    {
      p_m_memoryBufferChain->OSuite::ZObject::vfptr[6].__vecDelDtor(&this->m_memoryBufferChain, nPosition - v8);
      return 1;
    }
    if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 40i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead) )
    {
      ((void (__fastcall *)(OSuite::ZMemoryBufferChain *))p_m_memoryBufferChain->OSuite::ZObject::vfptr[3].__vecDelDtor)(&this->m_memoryBufferChain);
      OSuite::ZMemoryBufferChain::AccumulateData(
        (OSuite::ZMemoryBufferChain *)&this->m_pDecoder,
        *(OSuite::IReader **)&this->m_memoryBufferChain.m_bDeleteOnRead,
        (unsigned __int64)this->m_pSource);
      return (char)this->OSuite::ZObject::vfptr[6].__vecDelDtor(this, nPosition);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(OSuite::ZMemoryBufferChain *))this->m_memoryBufferChain.vfptr[3].__vecDelDtor)(&this->m_memoryBufferChain);
    v5 = (*(__int64 (__fastcall **)(_QWORD, unsigned __int64))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead
                                                             + 48i64))(
           *(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead,
           nPosition);
    OSuite::ZMemoryBufferChain::AccumulateData(
      (OSuite::ZMemoryBufferChain *)&this->m_pDecoder,
      *(OSuite::IReader **)&this->m_memoryBufferChain.m_bDeleteOnRead,
      (unsigned __int64)this->m_pSource);
    return v5;
  }
}

// File Line: 149
// RVA: 0xEEBE48
__int64 __fastcall OSuite::ZBufferedReader::Tell(OSuite::ZBufferedReader *this)
{
  OSuite::ZMemoryBufferChain *p_m_memoryBufferChain; // rbx
  __int64 v2; // rdi

  p_m_memoryBufferChain = &this->m_memoryBufferChain;
  v2 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 72i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead);
  return v2
       - ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))p_m_memoryBufferChain->OSuite::ZObject::vfptr[8].__vecDelDtor)(p_m_memoryBufferChain);
}

// File Line: 158
// RVA: 0xEEBA40
unsigned __int64 __fastcall OSuite::ZBufferedReader::Prefetch(OSuite::ZBufferedReader *this)
{
  return OSuite::ZMemoryBufferChain::AccumulateData(&this->m_memoryBufferChain, this->m_pSource, this->m_prefetchSize);
}

