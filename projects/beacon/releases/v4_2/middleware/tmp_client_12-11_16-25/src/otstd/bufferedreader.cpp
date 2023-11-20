// File Line: 18
// RVA: 0xEEB744
void __fastcall OSuite::ZBufferedReader::ZBufferedReader(OSuite::ZBufferedReader *this, OSuite::IReader *pSource, unsigned __int64 prefetchSize, bool bReaderOwnership)
{
  OSuite::IReader *v4; // rbx
  OSuite::ZBufferedReader *v5; // rsi
  bool v6; // bp
  unsigned __int64 v7; // rdi

  v4 = pSource;
  v5 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZBufferedReader::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IReaderVtbl *)&OSuite::ZBufferedReader::`vftable'{for `OSuite::IBufferedReader'};
  v6 = bReaderOwnership;
  v7 = prefetchSize;
  OSuite::ZMemoryBufferChain::ZMemoryBufferChain(&this->m_memoryBufferChain, 1);
  v5->m_pDecoder = 0i64;
  v5->m_pSource = v4;
  v5->m_bReaderOwnership = v6;
  v5->m_prefetchSize = v7;
}

// File Line: 24
// RVA: 0xEEB7B0
void __fastcall OSuite::ZBufferedReader::~ZBufferedReader(OSuite::ZBufferedReader *this)
{
  bool v1; // zf
  OSuite::ZBufferedReader *v2; // rbx
  OSuite::IReader *v3; // rcx
  OSuite::ZTextDecoder *v4; // rcx

  v1 = this->m_bReaderOwnership == 0;
  v2 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZBufferedReader::`vftable'{for `OSuite::ZObject'};
  this->vfptr = (OSuite::IReaderVtbl *)&OSuite::ZBufferedReader::`vftable'{for `OSuite::IBufferedReader'};
  if ( !v1 )
  {
    v3 = this->m_pSource;
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  OSuite::ZMemoryBufferChain::~ZMemoryBufferChain(&v2->m_memoryBufferChain);
  v4 = v2->m_pDecoder;
  v2->vfptr = (OSuite::IReaderVtbl *)&OSuite::IBufferedReader::`vftable';
  if ( v4 )
    v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
  v2->m_pDecoder = 0i64;
}

// File Line: 33
// RVA: 0xEEB9FC
void __fastcall OSuite::ZBufferedReader::Init(OSuite::ZBufferedReader *this, OSuite::ZTextDecoder *pDecoder)
{
  OSuite::ZBufferedReader *v2; // rbx
  OSuite::IReaderVtbl *v3; // rcx
  OSuite::ZTextDecoder *v4; // rdi

  v2 = this;
  v3 = this->vfptr;
  v4 = pDecoder;
  if ( v3 )
    (*(void (__fastcall **)(OSuite::IReaderVtbl *, signed __int64))v3->__vecDelDtor)(v3, 1i64);
  v2->vfptr = (OSuite::IReaderVtbl *)v4;
  OSuite::ZMemoryBufferChain::AccumulateData(
    (OSuite::ZMemoryBufferChain *)&v2->m_pDecoder,
    *(OSuite::IReader **)&v2->m_memoryBufferChain.m_bDeleteOnRead,
    (unsigned __int64)v2->m_pSource);
}

// File Line: 49
// RVA: 0xEEBA54
__int64 __fastcall OSuite::ZBufferedReader::Read(OSuite::ZBufferedReader *this, void *pDest, unsigned __int64 nCount)
{
  char *v3; // rsi
  OSuite::ZBufferedReader *v4; // rdi
  unsigned __int64 v5; // rbp
  char *v6; // r14
  unsigned __int64 v7; // rax
  __int64 v8; // rbx
  __int64 v9; // rbp
  __int64 v11; // rbx
  __int64 v12; // rax
  __int64 v13; // rbx

  v3 = (char *)&this->m_memoryBufferChain;
  v4 = this;
  v5 = nCount;
  v6 = (char *)pDest;
  v7 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->m_memoryBufferChain.vfptr[8].__vecDelDtor)(&this->m_memoryBufferChain);
  v8 = 0i64;
  if ( !v7 )
    goto LABEL_7;
  if ( v7 < v5 )
  {
    v11 = *(_QWORD *)v3;
    v12 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v3 + 64i64))(v3);
    v8 = (*(__int64 (__fastcall **)(char *, char *, __int64))(v11 + 8))(v3, v6, v12);
LABEL_7:
    v13 = (*(__int64 (__fastcall **)(_QWORD, char *, unsigned __int64))(**(_QWORD **)&v4->m_memoryBufferChain.m_bDeleteOnRead
                                                                      + 8i64))(
            *(_QWORD *)&v4->m_memoryBufferChain.m_bDeleteOnRead,
            &v6[v8],
            v5 - v8)
        + v8;
    if ( !v13 )
      return 0i64;
    OSuite::ZMemoryBufferChain::AccumulateData(
      (OSuite::ZMemoryBufferChain *)&v4->m_pDecoder,
      *(OSuite::IReader **)&v4->m_memoryBufferChain.m_bDeleteOnRead,
      (unsigned __int64)v4->m_pSource);
    return v13;
  }
  v9 = (*(__int64 (__fastcall **)(char *, char *, unsigned __int64))(*(_QWORD *)v3 + 8i64))(v3, v6, v5);
  if ( !(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v3 + 64i64))(v3) )
    OSuite::ZMemoryBufferChain::AccumulateData(
      (OSuite::ZMemoryBufferChain *)&v4->m_pDecoder,
      *(OSuite::IReader **)&v4->m_memoryBufferChain.m_bDeleteOnRead,
      (unsigned __int64)v4->m_pSource);
  return v9;
}

// File Line: 74
// RVA: 0xEEB8D8
void __fastcall OSuite::ZBufferedReader::Flush(OSuite::ZBufferedReader *this)
{
  OSuite::ZBufferedReader *v1; // rbx

  v1 = this;
  ((void (*)(void))this->m_memoryBufferChain.vfptr[3].__vecDelDtor)();
  (*(void (**)(void))(**(_QWORD **)&v1->m_memoryBufferChain.m_bDeleteOnRead + 24i64))();
}

// File Line: 85
// RVA: 0xEEBDB0
char __fastcall OSuite::ZBufferedReader::Skip(OSuite::ZBufferedReader *this, int nOffset)
{
  unsigned __int64 v2; // rsi
  OSuite::ZBufferedReader *v3; // rdi
  char *v5; // r14
  __int64 v6; // rbp
  unsigned __int64 v7; // rax
  OSuite::ZBufferedReader *v8; // rcx
  bool v9; // cf
  OSuite::ZObjectVtbl *v10; // rax
  __int64 v11; // rdx

  v2 = nOffset;
  v3 = this;
  if ( nOffset < 0 )
    return 0;
  if ( !nOffset )
    return 1;
  v5 = (char *)&this->m_memoryBufferChain;
  v6 = nOffset - (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 64i64))(v5);
  v7 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 64i64))(v5);
  v8 = (OSuite::ZBufferedReader *)v5;
  v9 = v7 < v2;
  v10 = *(OSuite::ZObjectVtbl **)v5;
  if ( v9 )
  {
    ((void (__fastcall *)(char *))v10[3].__vecDelDtor)(v5);
    if ( !OSuite::ZMemoryBufferChain::AccumulateData(
            (OSuite::ZMemoryBufferChain *)&v3->m_pDecoder,
            *(OSuite::IReader **)&v3->m_memoryBufferChain.m_bDeleteOnRead,
            (unsigned __int64)v3->m_pSource) )
      return 0;
    v10 = v3->vfptr;
    v11 = (unsigned int)v6;
    v8 = v3;
  }
  else
  {
    v11 = (unsigned int)v2;
  }
  return v10[4].__vecDelDtor((OSuite::ZObject *)&v8->vfptr, v11);
}

// File Line: 109
// RVA: 0xEEBCAC
__int64 __fastcall OSuite::ZBufferedReader::Rewind(OSuite::ZBufferedReader *this)
{
  return this->vfptr[6].__vecDelDtor((OSuite::ZObject *)this, 0);
}

// File Line: 114
// RVA: 0xEEBCB8
char __fastcall OSuite::ZBufferedReader::SetPosition(OSuite::ZBufferedReader *this, unsigned __int64 nPosition)
{
  unsigned __int64 v2; // rbx
  OSuite::ZBufferedReader *v3; // rdi
  char result; // al
  char v5; // bl
  signed __int64 v6; // rsi
  __int64 v7; // rbp
  unsigned __int64 v8; // rbp

  v2 = nPosition;
  v3 = this;
  if ( nPosition == ((__int64 (*)(void))this->vfptr[9].__vecDelDtor)() )
    return 1;
  if ( v2 < (*(__int64 (**)(void))(**(_QWORD **)&v3->m_memoryBufferChain.m_bDeleteOnRead + 72i64))() )
  {
    v6 = (signed __int64)&v3->m_memoryBufferChain;
    v7 = (*(__int64 (**)(void))(**(_QWORD **)&v3->m_memoryBufferChain.m_bDeleteOnRead + 72i64))();
    v8 = v7
       - ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v3->m_memoryBufferChain.vfptr[7].__vecDelDtor)(&v3->m_memoryBufferChain);
    if ( v2 >= v8 )
    {
      (*(void (__fastcall **)(OSuite::ZMemoryBufferChain *, unsigned __int64))(*(_QWORD *)v6 + 48i64))(
        &v3->m_memoryBufferChain,
        v2 - v8);
      return 1;
    }
    if ( (*(unsigned __int8 (**)(void))(**(_QWORD **)&v3->m_memoryBufferChain.m_bDeleteOnRead + 40i64))() )
    {
      (*(void (__fastcall **)(OSuite::ZMemoryBufferChain *))(*(_QWORD *)v6 + 24i64))(&v3->m_memoryBufferChain);
      OSuite::ZMemoryBufferChain::AccumulateData(
        (OSuite::ZMemoryBufferChain *)&v3->m_pDecoder,
        *(OSuite::IReader **)&v3->m_memoryBufferChain.m_bDeleteOnRead,
        (unsigned __int64)v3->m_pSource);
      result = (__int64)v3->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, v2);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    ((void (*)(void))v3->m_memoryBufferChain.vfptr[3].__vecDelDtor)();
    v5 = (*(__int64 (__fastcall **)(_QWORD, unsigned __int64))(**(_QWORD **)&v3->m_memoryBufferChain.m_bDeleteOnRead
                                                             + 48i64))(
           *(_QWORD *)&v3->m_memoryBufferChain.m_bDeleteOnRead,
           v2);
    OSuite::ZMemoryBufferChain::AccumulateData(
      (OSuite::ZMemoryBufferChain *)&v3->m_pDecoder,
      *(OSuite::IReader **)&v3->m_memoryBufferChain.m_bDeleteOnRead,
      (unsigned __int64)v3->m_pSource);
    result = v5;
  }
  return result;
}

// File Line: 149
// RVA: 0xEEBE48
__int64 __fastcall OSuite::ZBufferedReader::Tell(OSuite::ZBufferedReader *this)
{
  OSuite::ZMemoryBufferChain *v1; // rbx
  __int64 v2; // rdi

  v1 = &this->m_memoryBufferChain;
  v2 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&this->m_memoryBufferChain.m_bDeleteOnRead + 72i64))(*(_QWORD *)&this->m_memoryBufferChain.m_bDeleteOnRead);
  return v2 - ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v1->vfptr[8].__vecDelDtor)(v1);
}

// File Line: 158
// RVA: 0xEEBA40
unsigned __int64 __fastcall OSuite::ZBufferedReader::Prefetch(OSuite::ZBufferedReader *this)
{
  return OSuite::ZMemoryBufferChain::AccumulateData(&this->m_memoryBufferChain, this->m_pSource, this->m_prefetchSize);
}

