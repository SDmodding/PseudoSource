// File Line: 21
// RVA: 0xEE7DAC
void __fastcall OSuite::ZMemoryBuffer::ZMemoryBuffer(OSuite::ZMemoryBuffer *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMemoryBuffer::`vftable;
  this->m_pNext = 0i64;
  this->m_pBuffer = 0i64;
  this->m_pIndex = 0i64;
  this->m_nBufferLength = 0i64;
  this->m_nDataLength = 0i64;
  this->m_nRemainingDataLength = 0i64;
}

// File Line: 44
// RVA: 0xEE8068
void __fastcall OSuite::ZMemoryBuffer::Allocate(OSuite::ZMemoryBuffer *this, unsigned __int64 nBufferLength, void *pSrc, unsigned __int64 nSrcLength)
{
  OSuite::ZMemoryBuffer *v4; // rdi
  void *v5; // rsi
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rbx
  void *v8; // rax

  v4 = this;
  v5 = pSrc;
  v6 = nSrcLength;
  v7 = nBufferLength;
  v8 = OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, nBufferLength, 0i64);
  v4->m_nDataLength = 0i64;
  v4->m_nRemainingDataLength = 0i64;
  v4->m_nBufferLength = v7;
  v4->m_pBuffer = v8;
  v4->m_pIndex = v8;
  if ( v5 )
    OSuite::ZMemoryBuffer::Write(v4, v5, v6);
}

// File Line: 67
// RVA: 0xEE83CC
OSuite::ZMemoryBuffer *__fastcall OSuite::ZMemoryBuffer::Release(OSuite::ZMemoryBuffer *this)
{
  OSuite::ZMemoryBuffer *v1; // rbx
  OSuite::ZMemoryBuffer *result; // rax

  v1 = this;
  OSuite::ZObject::free((OSuite::ZObject *)&this->vfptr, this->m_pBuffer);
  result = v1->m_pNext;
  v1->m_pBuffer = 0i64;
  v1->m_pIndex = 0i64;
  v1->m_nBufferLength = 0i64;
  v1->m_nDataLength = 0i64;
  v1->m_nRemainingDataLength = 0i64;
  v1->m_pNext = 0i64;
  return result;
}

// File Line: 81
// RVA: 0xEE8404
void __fastcall OSuite::ZMemoryBuffer::ReleaseChain(OSuite::ZMemoryBuffer *this)
{
  OSuite::ZMemoryBuffer *v1; // rbx

  v1 = this;
  OSuite::ZMemoryBuffer::InternalReleaseChain(this, this->m_pNext);
  v1->m_pNext = 0i64;
  OSuite::ZMemoryBuffer::Release(v1);
}

// File Line: 88
// RVA: 0xEE8224
unsigned __int64 __fastcall OSuite::ZMemoryBuffer::Read(OSuite::ZMemoryBuffer *this, void *pDest, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rbx
  OSuite::ZMemoryBuffer *v4; // rdi

  v3 = nLength;
  v4 = this;
  if ( !pDest || !nLength )
    return 0i64;
  if ( nLength >= this->m_nRemainingDataLength )
    v3 = this->m_nRemainingDataLength;
  if ( !v3 )
    return 0i64;
  memmove(pDest, this->m_pIndex, v3);
  v4->m_pIndex = (char *)v4->m_pIndex + v3;
  v4->m_nRemainingDataLength -= v3;
  return v3;
}

// File Line: 107
// RVA: 0xEE8658
unsigned __int64 __fastcall OSuite::ZMemoryBuffer::Write(OSuite::ZMemoryBuffer *this, const void *pSrc, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rbx
  OSuite::ZMemoryBuffer *v4; // rdi
  unsigned __int64 v5; // r8

  v3 = nLength;
  v4 = this;
  if ( !pSrc || !nLength )
    return 0i64;
  v5 = this->m_nDataLength;
  if ( v3 >= this->m_nBufferLength - v5 )
    v3 = this->m_nBufferLength - v5;
  if ( !v3 )
    return 0i64;
  memmove((char *)this->m_pBuffer + v5, pSrc, v3);
  v4->m_nDataLength += v3;
  v4->m_nRemainingDataLength += v3;
  return v3;
}

// File Line: 127
// RVA: 0xEE8428
unsigned __int64 __fastcall OSuite::ZMemoryBuffer::Rewind(OSuite::ZMemoryBuffer *this, unsigned __int64 nBytes)
{
  unsigned __int64 result; // rax
  OSuite::ZMemoryBuffer *v3; // r8
  unsigned __int64 v4; // rcx

  result = nBytes;
  v3 = this;
  v4 = this->m_nRemainingDataLength;
  if ( nBytes > v3->m_nDataLength - v4 )
    result = v3->m_nDataLength - v4;
  if ( result )
  {
    v3->m_pIndex = (char *)v3->m_pIndex - result;
    v3->m_nRemainingDataLength = result + v4;
  }
  return result;
}

// File Line: 220
// RVA: 0xEE81E0
void __fastcall OSuite::ZMemoryBuffer::InternalReleaseChain(OSuite::ZMemoryBuffer *this, OSuite::ZMemoryBuffer *pNext)
{
  OSuite::ZMemoryBuffer *v2; // rbx
  OSuite::ZMemoryBuffer *v3; // rdi

  if ( pNext )
  {
    v2 = pNext;
    do
    {
      v3 = OSuite::ZMemoryBuffer::Release(v2);
      if ( v2 )
        v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
      v2 = v3;
    }
    while ( v3 );
  }
}

// File Line: 243
// RVA: 0xEE7DD4
void __fastcall OSuite::ZMemoryBufferChain::ZMemoryBufferChain(OSuite::ZMemoryBufferChain *this, bool bDeleteOnRead)
{
  this->m_firstBuffer = 0i64;
  this->m_indexBuffer = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMemoryBufferChain::`vftable{for `OSuite::ZObject};
  this->m_bDeleteOnRead = bDeleteOnRead;
  this->vfptr = (OSuite::IReaderVtbl *)&OSuite::ZMemoryBufferChain::`vftable{for `OSuite::IReader};
}

// File Line: 247
// RVA: 0xEE7DFC
void __fastcall OSuite::ZMemoryBufferChain::~ZMemoryBufferChain(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZMemoryBufferChain *v1; // rbx
  OSuite::ZMemoryBuffer *v2; // rcx
  OSuite::ZMemoryBuffer *v3; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMemoryBufferChain::`vftable{for `OSuite::ZObject};
  this->vfptr = (OSuite::IReaderVtbl *)&OSuite::ZMemoryBufferChain::`vftable{for `OSuite::IReader};
  v2 = this->m_firstBuffer;
  if ( v2 )
    OSuite::ZMemoryBuffer::ReleaseChain(v2);
  v3 = v1->m_firstBuffer;
  if ( v3 )
    v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
  v1->m_firstBuffer = 0i64;
  v1->m_indexBuffer = 0i64;
}

// File Line: 258
// RVA: 0xEE80D8
void __fastcall OSuite::ZMemoryBufferChain::Chain(OSuite::ZMemoryBufferChain *this, OSuite::ZMemoryBuffer *pBuffer)
{
  OSuite::ZMemoryBuffer *v2; // rax

  if ( this->m_firstBuffer )
  {
    v2 = this->m_indexBuffer;
    if ( v2 )
    {
      while ( v2->m_pNext )
        v2 = v2->m_pNext;
    }
    if ( v2 )
      v2->m_pNext = pBuffer;
  }
  else
  {
    this->m_firstBuffer = pBuffer;
    this->m_indexBuffer = pBuffer;
  }
}

// File Line: 272
// RVA: 0xEE8278
__int64 __fastcall OSuite::ZMemoryBufferChain::Read(OSuite::ZMemoryBufferChain *this, void *pDest, unsigned __int64 nLength)
{
  unsigned __int64 v3; // rsi
  char *v4; // rbp
  OSuite::ZMemoryBufferChain *v5; // rdi
  OSuite::ZMemoryBuffer *v7; // rbx
  __int64 v8; // r14
  unsigned __int64 v9; // rax
  OSuite::ZMemoryBuffer *v10; // r15
  bool v11; // zf

  v3 = nLength;
  v4 = (char *)pDest;
  v5 = this;
  if ( !this->vfptr )
    return 0i64;
  v7 = this->m_firstBuffer;
  v8 = 0i64;
  if ( nLength )
  {
    do
    {
      if ( !v7 )
        break;
      v9 = OSuite::ZMemoryBuffer::Read(v7, &v4[v8], v3);
      v8 += v9;
      v3 -= v9;
      if ( !v7->m_nRemainingDataLength )
      {
        if ( LOBYTE(v5->m_indexBuffer) )
        {
          v10 = v7;
          v7 = OSuite::ZMemoryBuffer::Release(v7);
          if ( v10 )
            v10->vfptr->__vecDelDtor((OSuite::ZObject *)&v10->vfptr, 1u);
        }
        else
        {
          v7 = v7->m_pNext;
        }
      }
    }
    while ( v3 );
  }
  v11 = LOBYTE(v5->m_indexBuffer) == 0;
  v5->m_firstBuffer = v7;
  if ( !v11 )
  {
    if ( v7 && !v7->m_nRemainingDataLength )
    {
      v7->vfptr->__vecDelDtor((OSuite::ZObject *)&v7->vfptr, 1u);
      v5->m_firstBuffer = 0i64;
    }
    if ( LOBYTE(v5->m_indexBuffer) )
      v5->vfptr = (OSuite::IReaderVtbl *)v5->m_firstBuffer;
  }
  return v8;
}

// File Line: 314
// RVA: 0xEE8358
signed __int64 __fastcall OSuite::ZMemoryBufferChain::ReadByte(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZObjectVtbl *v1; // rax
  signed __int64 result; // rax
  char v3; // [rsp+20h] [rbp-18h]

  v1 = this->vfptr;
  v3 = 0;
  if ( ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *, char *, signed __int64))v1[1].__vecDelDtor)(
         this,
         &v3,
         1i64) == 1 )
    result = (unsigned int)v3;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 322
// RVA: 0xEE8124
void __fastcall OSuite::ZMemoryBufferChain::Flush(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZObjectVtbl *v1; // rbx
  OSuite::ZMemoryBufferChain *v2; // rdi
  __int64 v3; // rax

  v1 = this->vfptr;
  v2 = this;
  v3 = ((__int64 (*)(void))this->vfptr[8].__vecDelDtor)();
  v1[4].__vecDelDtor((OSuite::ZObject *)&v2->vfptr, v3);
}

// File Line: 327
// RVA: 0xEE8550
char __fastcall OSuite::ZMemoryBufferChain::Skip(OSuite::ZMemoryBufferChain *this, int nOffset)
{
  int v2; // edi
  OSuite::ZMemoryBufferChain *v3; // rbx
  unsigned __int64 v5; // rsi
  __int64 v6; // rax
  OSuite::ZMemoryBuffer *v7; // rcx
  char v8; // [rsp+20h] [rbp-1028h]

  v2 = nOffset;
  v3 = this;
  if ( nOffset < 0 )
    return 0;
  if ( nOffset > 0 )
  {
    do
    {
      v5 = v2;
      if ( (unsigned __int64)v2 >= 0x1000 )
        v5 = 4096i64;
      if ( v5 >= ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v3->vfptr[8].__vecDelDtor)(v3) )
        v5 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v3->vfptr[8].__vecDelDtor)(v3);
      v6 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *, char *, unsigned __int64))v3->vfptr[1].__vecDelDtor)(
             v3,
             &v8,
             v5);
      if ( !v6 )
        return 0;
      v2 -= v6;
    }
    while ( v2 > 0 );
  }
  if ( LOBYTE(v3->m_indexBuffer) )
  {
    v7 = v3->m_firstBuffer;
    if ( v7 && !v7->m_nRemainingDataLength )
    {
      v7->vfptr->__vecDelDtor((OSuite::ZObject *)&v7->vfptr, 1u);
      v3->m_firstBuffer = 0i64;
    }
    if ( LOBYTE(v3->m_indexBuffer) )
      v3->vfptr = (OSuite::IReaderVtbl *)v3->m_firstBuffer;
  }
  return 1;
}

// File Line: 358
// RVA: 0xEE8454
char __fastcall OSuite::ZMemoryBufferChain::Rewind(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZMemoryBuffer *v1; // rbx

  v1 = (OSuite::ZMemoryBuffer *)this->vfptr;
  if ( !v1 )
    return 0;
  this->m_firstBuffer = v1;
  do
  {
    OSuite::ZMemoryBuffer::Rewind(v1, v1->m_nDataLength);
    v1 = v1->m_pNext;
  }
  while ( v1 );
  return 1;
}

// File Line: 374
// RVA: 0xEE8488
bool __fastcall OSuite::ZMemoryBufferChain::SetPosition(OSuite::ZMemoryBufferChain *this, unsigned __int64 nPosition)
{
  unsigned __int64 v2; // rsi
  OSuite::ZMemoryBufferChain *v3; // rdi
  OSuite::ZObjectVtbl *v4; // rbx
  int v5; // eax
  bool result; // al
  OSuite::ZObjectVtbl *v7; // rax
  __int64 v8; // rax

  v2 = nPosition;
  v3 = this;
  if ( nPosition > ((__int64 (*)(void))this->vfptr[7].__vecDelDtor)()
    || v2 < ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v3->vfptr[9].__vecDelDtor)(v3) )
  {
    if ( v2 >= ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v3->vfptr[9].__vecDelDtor)(v3) )
    {
      result = 0;
    }
    else
    {
      v7 = v3->vfptr;
      if ( LOBYTE(v3->m_indexBuffer) )
      {
        v8 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v7[9].__vecDelDtor)(v3);
        result = OSuite::ZMemoryBuffer::Rewind((OSuite::ZMemoryBuffer *)v3->vfptr, v8 - v2) != 0;
      }
      else
      {
        result = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v7[5].__vecDelDtor)(v3);
        if ( result )
          result = (__int64)v3->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, v2);
      }
    }
  }
  else
  {
    v4 = v3->vfptr;
    v5 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))v3->vfptr[9].__vecDelDtor)(v3);
    result = (__int64)v4[4].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, (signed int)v2 - v5);
  }
  return result;
}

// File Line: 397
// RVA: 0xEE8150
OSuite::ZMemoryBuffer *__fastcall OSuite::ZHttpStreamReader::Size(OSuite::ZMemoryBufferChain *this)
{
  return this->m_indexBuffer;
}

// File Line: 414
// RVA: 0xEE7EC4
unsigned __int64 __fastcall OSuite::ZMemoryBufferChain::AccumulateData(OSuite::ZMemoryBufferChain *this, OSuite::IReader *reader, unsigned __int64 maxAccumulateBytes)
{
  OSuite::ZMemoryBufferChain *v3; // rbp
  unsigned __int64 v4; // r15
  OSuite::IReader *v5; // r14
  unsigned __int64 result; // rax
  unsigned __int64 v7; // rbx
  char *v8; // rsi
  unsigned __int64 v9; // rdi
  OSuite::ZMemoryBuffer *v10; // rcx
  unsigned __int64 v11; // r14
  OSuite::ZMemoryBuffer *v12; // rax
  OSuite::ZMemoryBuffer *v13; // rbx
  OSuite::ZMemoryBuffer *v14; // rax

  v3 = this;
  v4 = maxAccumulateBytes;
  v5 = reader;
  result = reader->vfptr->ReadyToRead(reader);
  v7 = result;
  if ( result )
  {
    v8 = 0i64;
    v9 = 0i64;
    if ( result >= v4 )
      v7 = v4;
    if ( v7 )
    {
      v8 = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, v7, 0i64);
      v9 = (*((__int64 (__fastcall **)(OSuite::IReader *, char *, unsigned __int64))&v5->vfptr->__vecDelDtor + 1))(
             v5,
             v8,
             v7);
      if ( v9 )
      {
        v10 = v3->m_indexBuffer;
        if ( v10 )
        {
          while ( v10->m_pNext )
            v10 = v10->m_pNext;
        }
        else
        {
          v10 = 0i64;
        }
        if ( !v10 || v10->m_nBufferLength == v10->m_nDataLength )
        {
          v14 = (OSuite::ZMemoryBuffer *)OSuite::ZObject::operator new(0x38ui64);
          if ( v14 )
          {
            v14->m_pNext = 0i64;
            v14->m_pBuffer = 0i64;
            v14->m_pIndex = 0i64;
            v14->m_nBufferLength = 0i64;
            v14->m_nDataLength = 0i64;
            v14->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMemoryBuffer::`vftable;
            v14->m_nRemainingDataLength = 0i64;
          }
          else
          {
            v14 = 0i64;
          }
          v14->m_pBuffer = v8;
          v14->m_pIndex = v8;
          v14->m_nBufferLength = v7;
          v14->m_nDataLength = v9;
          v14->m_nRemainingDataLength = v9;
          OSuite::ZMemoryBufferChain::Chain(v3, v14);
          goto LABEL_18;
        }
        v11 = OSuite::ZMemoryBuffer::Write(v10, v8, v9);
        v9 -= v11;
        if ( v9 )
        {
          v12 = (OSuite::ZMemoryBuffer *)OSuite::ZObject::operator new(0x38ui64);
          v13 = v12;
          if ( v12 )
          {
            v12->m_pNext = 0i64;
            v12->m_pBuffer = 0i64;
            v12->m_pIndex = 0i64;
            v12->m_nBufferLength = 0i64;
            v12->m_nDataLength = 0i64;
            v12->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMemoryBuffer::`vftable;
            v12->m_nRemainingDataLength = 0i64;
          }
          else
          {
            v13 = 0i64;
          }
          OSuite::ZMemoryBuffer::Allocate(v13, v9, &v8[v11], v9);
          OSuite::ZMemoryBufferChain::Chain(v3, v13);
        }
      }
    }
    OSuite::ZObject::free((OSuite::ZObject *)&v3->vfptr, v8);
LABEL_18:
    result = v9;
  }
  return result;
}

