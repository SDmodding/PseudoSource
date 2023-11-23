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
void __fastcall OSuite::ZMemoryBuffer::Allocate(
        OSuite::ZMemoryBuffer *this,
        unsigned __int64 nBufferLength,
        void *pSrc,
        unsigned __int64 nSrcLength)
{
  void *v8; // rax

  v8 = (void *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, nBufferLength, 0i64);
  this->m_nDataLength = 0i64;
  this->m_nRemainingDataLength = 0i64;
  this->m_nBufferLength = nBufferLength;
  this->m_pBuffer = v8;
  this->m_pIndex = v8;
  if ( pSrc )
    OSuite::ZMemoryBuffer::Write(this, pSrc, nSrcLength);
}

// File Line: 67
// RVA: 0xEE83CC
OSuite::ZMemoryBuffer *__fastcall OSuite::ZMemoryBuffer::Release(OSuite::ZMemoryBuffer *this)
{
  OSuite::ZMemoryBuffer *result; // rax

  OSuite::ZObject::free(this, this->m_pBuffer);
  result = this->m_pNext;
  this->m_pBuffer = 0i64;
  this->m_pIndex = 0i64;
  this->m_nBufferLength = 0i64;
  this->m_nDataLength = 0i64;
  this->m_nRemainingDataLength = 0i64;
  this->m_pNext = 0i64;
  return result;
}

// File Line: 81
// RVA: 0xEE8404
void __fastcall OSuite::ZMemoryBuffer::ReleaseChain(OSuite::ZMemoryBuffer *this)
{
  OSuite::ZMemoryBuffer::InternalReleaseChain(this, this->m_pNext);
  this->m_pNext = 0i64;
  OSuite::ZMemoryBuffer::Release(this);
}

// File Line: 88
// RVA: 0xEE8224
unsigned __int64 __fastcall OSuite::ZMemoryBuffer::Read(
        OSuite::ZMemoryBuffer *this,
        void *pDest,
        unsigned __int64 nLength)
{
  unsigned __int64 m_nRemainingDataLength; // rbx

  m_nRemainingDataLength = nLength;
  if ( !pDest || !nLength )
    return 0i64;
  if ( nLength >= this->m_nRemainingDataLength )
    m_nRemainingDataLength = this->m_nRemainingDataLength;
  if ( !m_nRemainingDataLength )
    return 0i64;
  memmove(pDest, this->m_pIndex, m_nRemainingDataLength);
  this->m_pIndex = (char *)this->m_pIndex + m_nRemainingDataLength;
  this->m_nRemainingDataLength -= m_nRemainingDataLength;
  return m_nRemainingDataLength;
}

// File Line: 107
// RVA: 0xEE8658
size_t __fastcall OSuite::ZMemoryBuffer::Write(OSuite::ZMemoryBuffer *this, const void *pSrc, size_t nLength)
{
  size_t v3; // rbx
  unsigned __int64 m_nDataLength; // r8

  v3 = nLength;
  if ( !pSrc || !nLength )
    return 0i64;
  m_nDataLength = this->m_nDataLength;
  if ( v3 >= this->m_nBufferLength - m_nDataLength )
    v3 = this->m_nBufferLength - m_nDataLength;
  if ( !v3 )
    return 0i64;
  memmove((char *)this->m_pBuffer + m_nDataLength, pSrc, v3);
  this->m_nDataLength += v3;
  this->m_nRemainingDataLength += v3;
  return v3;
}

// File Line: 127
// RVA: 0xEE8428
unsigned __int64 __fastcall OSuite::ZMemoryBuffer::Rewind(OSuite::ZMemoryBuffer *this, unsigned __int64 nBytes)
{
  unsigned __int64 result; // rax
  unsigned __int64 m_nRemainingDataLength; // rcx

  result = nBytes;
  m_nRemainingDataLength = this->m_nRemainingDataLength;
  if ( nBytes > this->m_nDataLength - m_nRemainingDataLength )
    result = this->m_nDataLength - m_nRemainingDataLength;
  if ( result )
  {
    this->m_pIndex = (char *)this->m_pIndex - result;
    this->m_nRemainingDataLength = result + m_nRemainingDataLength;
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
        v2->vfptr->__vecDelDtor(v2, 1u);
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
  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMemoryBufferChain::`vftable{for `OSuite::ZObject};
  this->m_bDeleteOnRead = bDeleteOnRead;
  this->OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)&OSuite::ZMemoryBufferChain::`vftable{for `OSuite::IReader};
}

// File Line: 247
// RVA: 0xEE7DFC
void __fastcall OSuite::ZMemoryBufferChain::~ZMemoryBufferChain(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZMemoryBuffer *m_firstBuffer; // rcx
  OSuite::ZMemoryBuffer *v3; // rcx

  this->OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZMemoryBufferChain::`vftable{for `OSuite::ZObject};
  this->OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)&OSuite::ZMemoryBufferChain::`vftable{for `OSuite::IReader};
  m_firstBuffer = this->m_firstBuffer;
  if ( m_firstBuffer )
    OSuite::ZMemoryBuffer::ReleaseChain(m_firstBuffer);
  v3 = this->m_firstBuffer;
  if ( v3 )
    v3->vfptr->__vecDelDtor(v3, 1u);
  this->m_firstBuffer = 0i64;
  this->m_indexBuffer = 0i64;
}

// File Line: 258
// RVA: 0xEE80D8
void __fastcall OSuite::ZMemoryBufferChain::Chain(OSuite::ZMemoryBufferChain *this, OSuite::ZMemoryBuffer *pBuffer)
{
  OSuite::ZMemoryBuffer *m_indexBuffer; // rax

  if ( this->m_firstBuffer )
  {
    m_indexBuffer = this->m_indexBuffer;
    if ( m_indexBuffer )
    {
      while ( m_indexBuffer->m_pNext )
        m_indexBuffer = m_indexBuffer->m_pNext;
    }
    if ( m_indexBuffer )
      m_indexBuffer->m_pNext = pBuffer;
  }
  else
  {
    this->m_firstBuffer = pBuffer;
    this->m_indexBuffer = pBuffer;
  }
}

// File Line: 272
// RVA: 0xEE8278
__int64 __fastcall OSuite::ZMemoryBufferChain::Read(
        OSuite::ZMemoryBufferChain *this,
        char *pDest,
        unsigned __int64 nLength)
{
  unsigned __int64 v3; // rsi
  OSuite::ZMemoryBuffer *m_firstBuffer; // rbx
  __int64 v8; // r14
  unsigned __int64 v9; // rax
  OSuite::ZMemoryBuffer *v10; // r15
  bool v11; // zf

  v3 = nLength;
  if ( !this->OSuite::IReader::vfptr )
    return 0i64;
  m_firstBuffer = this->m_firstBuffer;
  v8 = 0i64;
  if ( nLength )
  {
    do
    {
      if ( !m_firstBuffer )
        break;
      v9 = OSuite::ZMemoryBuffer::Read(m_firstBuffer, &pDest[v8], v3);
      v8 += v9;
      v3 -= v9;
      if ( !m_firstBuffer->m_nRemainingDataLength )
      {
        if ( LOBYTE(this->m_indexBuffer) )
        {
          v10 = m_firstBuffer;
          m_firstBuffer = OSuite::ZMemoryBuffer::Release(m_firstBuffer);
          v10->vfptr->__vecDelDtor(v10, 1u);
        }
        else
        {
          m_firstBuffer = m_firstBuffer->m_pNext;
        }
      }
    }
    while ( v3 );
  }
  v11 = LOBYTE(this->m_indexBuffer) == 0;
  this->m_firstBuffer = m_firstBuffer;
  if ( !v11 )
  {
    if ( m_firstBuffer && !m_firstBuffer->m_nRemainingDataLength )
    {
      m_firstBuffer->vfptr->__vecDelDtor(m_firstBuffer, 1u);
      this->m_firstBuffer = 0i64;
    }
    if ( LOBYTE(this->m_indexBuffer) )
      this->OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)this->m_firstBuffer;
  }
  return v8;
}

// File Line: 314
// RVA: 0xEE8358
__int64 __fastcall OSuite::ZMemoryBufferChain::ReadByte(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZObjectVtbl *vfptr; // rax
  char v3[8]; // [rsp+20h] [rbp-18h] BYREF

  vfptr = this->OSuite::ZObject::vfptr;
  v3[0] = 0;
  if ( ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *, char *, __int64))vfptr[1].__vecDelDtor)(this, v3, 1i64) == 1 )
    return (unsigned int)v3[0];
  else
    return 0xFFFFFFFFi64;
}

// File Line: 322
// RVA: 0xEE8124
void __fastcall OSuite::ZMemoryBufferChain::Flush(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZObjectVtbl *vfptr; // rbx
  __int64 v3; // rax

  vfptr = this->OSuite::ZObject::vfptr;
  v3 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[8].__vecDelDtor)(this);
  vfptr[4].__vecDelDtor(this, v3);
}

// File Line: 327
// RVA: 0xEE8550
char __fastcall OSuite::ZMemoryBufferChain::Skip(OSuite::ZMemoryBufferChain *this, int nOffset)
{
  int v2; // edi
  unsigned __int64 v5; // rsi
  __int64 v6; // rax
  OSuite::ZMemoryBuffer *m_firstBuffer; // rcx
  char v8[4096]; // [rsp+20h] [rbp-1028h] BYREF

  v2 = nOffset;
  if ( nOffset < 0 )
    return 0;
  if ( nOffset > 0 )
  {
    do
    {
      v5 = v2;
      if ( (unsigned __int64)v2 >= 0x1000 )
        v5 = 4096i64;
      if ( v5 >= ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[8].__vecDelDtor)(this) )
        v5 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[8].__vecDelDtor)(this);
      v6 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *, char *, unsigned __int64))this->OSuite::ZObject::vfptr[1].__vecDelDtor)(
             this,
             v8,
             v5);
      if ( !v6 )
        return 0;
      v2 -= v6;
    }
    while ( v2 > 0 );
  }
  if ( LOBYTE(this->m_indexBuffer) )
  {
    m_firstBuffer = this->m_firstBuffer;
    if ( m_firstBuffer && !m_firstBuffer->m_nRemainingDataLength )
    {
      m_firstBuffer->vfptr->__vecDelDtor(m_firstBuffer, 1u);
      this->m_firstBuffer = 0i64;
    }
    if ( LOBYTE(this->m_indexBuffer) )
      this->OSuite::IReader::vfptr = (OSuite::IReaderVtbl *)this->m_firstBuffer;
  }
  return 1;
}

// File Line: 358
// RVA: 0xEE8454
char __fastcall OSuite::ZMemoryBufferChain::Rewind(OSuite::ZMemoryBufferChain *this)
{
  OSuite::ZMemoryBuffer *vfptr; // rbx

  vfptr = (OSuite::ZMemoryBuffer *)this->OSuite::IReader::vfptr;
  if ( !vfptr )
    return 0;
  this->m_firstBuffer = vfptr;
  do
  {
    OSuite::ZMemoryBuffer::Rewind(vfptr, vfptr->m_nDataLength);
    vfptr = vfptr->m_pNext;
  }
  while ( vfptr );
  return 1;
}

// File Line: 374
// RVA: 0xEE8488
bool __fastcall OSuite::ZMemoryBufferChain::SetPosition(OSuite::ZMemoryBufferChain *this, unsigned __int64 nPosition)
{
  OSuite::ZObjectVtbl *v4; // rbx
  int v5; // eax
  bool result; // al
  OSuite::ZObjectVtbl *vfptr; // rax
  __int64 v8; // rax

  if ( nPosition > ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[7].__vecDelDtor)(this)
    || nPosition < ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[9].__vecDelDtor)(this) )
  {
    if ( nPosition >= ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[9].__vecDelDtor)(this) )
    {
      return 0;
    }
    else
    {
      vfptr = this->OSuite::ZObject::vfptr;
      if ( LOBYTE(this->m_indexBuffer) )
      {
        v8 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))vfptr[9].__vecDelDtor)(this);
        return OSuite::ZMemoryBuffer::Rewind((OSuite::ZMemoryBuffer *)this->OSuite::IReader::vfptr, v8 - nPosition) != 0;
      }
      else
      {
        result = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))vfptr[5].__vecDelDtor)(this);
        if ( result )
          return (bool)this->OSuite::ZObject::vfptr[6].__vecDelDtor(this, nPosition);
      }
    }
  }
  else
  {
    v4 = this->OSuite::ZObject::vfptr;
    v5 = ((__int64 (__fastcall *)(OSuite::ZMemoryBufferChain *))this->OSuite::ZObject::vfptr[9].__vecDelDtor)(this);
    return (bool)v4[4].__vecDelDtor(this, (int)nPosition - v5);
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
unsigned __int64 __fastcall OSuite::ZMemoryBufferChain::AccumulateData(
        OSuite::ZMemoryBufferChain *this,
        OSuite::IReader *reader,
        unsigned __int64 maxAccumulateBytes)
{
  unsigned __int64 result; // rax
  unsigned __int64 v7; // rbx
  char *v8; // rsi
  unsigned __int64 v9; // rdi
  OSuite::ZMemoryBuffer *m_indexBuffer; // rcx
  unsigned __int64 v11; // r14
  OSuite::ZMemoryBuffer *v12; // rax
  OSuite::ZMemoryBuffer *v13; // rbx
  OSuite::ZMemoryBuffer *v14; // rax

  result = reader->vfptr->ReadyToRead(reader);
  v7 = result;
  if ( result )
  {
    v8 = 0i64;
    v9 = 0i64;
    if ( result >= maxAccumulateBytes )
      v7 = maxAccumulateBytes;
    if ( v7 )
    {
      v8 = (char *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, v7, 0i64);
      v9 = (*((__int64 (__fastcall **)(OSuite::IReader *, char *, unsigned __int64))&reader->vfptr->__vecDelDtor + 1))(
             reader,
             v8,
             v7);
      if ( v9 )
      {
        m_indexBuffer = this->m_indexBuffer;
        if ( m_indexBuffer )
        {
          while ( m_indexBuffer->m_pNext )
            m_indexBuffer = m_indexBuffer->m_pNext;
        }
        else
        {
          m_indexBuffer = 0i64;
        }
        if ( !m_indexBuffer || m_indexBuffer->m_nBufferLength == m_indexBuffer->m_nDataLength )
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
          OSuite::ZMemoryBufferChain::Chain(this, v14);
          return v9;
        }
        v11 = OSuite::ZMemoryBuffer::Write(m_indexBuffer, v8, v9);
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
          OSuite::ZMemoryBufferChain::Chain(this, v13);
        }
      }
    }
    OSuite::ZObject::free(this, v8);
    return v9;
  }
  return result;
}

