// File Line: 16
// RVA: 0x1301B10
void __fastcall hkMemoryStreamReader::hkMemoryStreamReader(
        hkMemoryStreamReader *this,
        char *mem,
        unsigned int memSize,
        hkMemoryStreamReader::MemoryType mt)
{
  hkMemoryAllocator **Value; // rax
  char *v8; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_bufCurrent = 0;
  this->m_bufSize = memSize;
  this->m_memType = mt;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryStreamReader::`vftable;
  this->m_hitEof.m_bool = 0;
  if ( mt )
  {
    this->m_buf = mem;
  }
  else
  {
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (char *)hkMemoryRouter::easyAlloc(Value[11], memSize);
    this->m_buf = v8;
    hkString::memCpy(v8, mem, memSize);
  }
}

// File Line: 29
// RVA: 0x1301BB0
void __fastcall hkMemoryStreamReader::~hkMemoryStreamReader(hkMemoryStreamReader *this)
{
  bool v1; // cc
  char *m_buf; // rbx
  hkMemoryAllocator **Value; // rax

  v1 = this->m_memType <= (unsigned int)MEMORY_TAKE;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryStreamReader::`vftable;
  if ( v1 )
  {
    m_buf = this->m_buf;
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(Value[11], m_buf);
    this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
  else
  {
    this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
}

// File Line: 37
// RVA: 0x1301C20
__int64 __fastcall hkMemoryStreamReader::read(hkMemoryStreamReader *this, void *buf, int nbytes)
{
  unsigned int v3; // ebx
  __int64 result; // rax

  v3 = nbytes;
  if ( this->m_bufSize - this->m_bufCurrent < nbytes )
    v3 = this->m_bufSize - this->m_bufCurrent;
  hkString::memCpy(buf, &this->m_buf[this->m_bufCurrent], v3);
  this->m_bufCurrent += v3;
  result = v3;
  if ( !v3 )
  {
    if ( nbytes )
      this->m_hitEof.m_bool = 1;
  }
  return result;
}

// File Line: 49
// RVA: 0x1301C90
__int64 __fastcall hkMemoryStreamReader::skip(hkMemoryStreamReader *this, unsigned int nbytes)
{
  int m_bufCurrent; // r9d
  __int64 result; // rax
  unsigned int v4; // r8d

  m_bufCurrent = this->m_bufCurrent;
  result = nbytes;
  v4 = this->m_bufSize - m_bufCurrent;
  if ( (int)v4 < (int)nbytes )
    result = v4;
  this->m_bufCurrent = m_bufCurrent + result;
  if ( !(_DWORD)result )
  {
    if ( nbytes )
      this->m_hitEof.m_bool = 1;
  }
  return result;
}

// File Line: 60
// RVA: 0x1301CC0
hkBool *__fastcall hkMemoryStreamReader::isOk(hkMemoryStreamReader *this, hkBool *result)
{
  result->m_bool = this->m_hitEof.m_bool == 0;
  return result;
}

// File Line: 65
// RVA: 0x1301CE0
__int64 __fastcall hkMemoryStreamReader::peek(hkMemoryStreamReader *this, void *buf, int nbytes)
{
  unsigned int v3; // ebx

  v3 = nbytes;
  if ( this->m_bufSize - this->m_bufCurrent < nbytes )
    v3 = this->m_bufSize - this->m_bufCurrent;
  hkMemUtil::memCpy(buf, &this->m_buf[this->m_bufCurrent], v3);
  return v3;
}

// File Line: 72
// RVA: 0x1301D20
hkResult *__fastcall hkMemoryStreamReader::seek(
        hkMemoryStreamReader *this,
        hkResult *result,
        int relOffset,
        hkSeekableStreamReader::SeekWhence whence)
{
  int m_bufSize; // r10d
  int v5; // r9d
  hkResult *v6; // rax

  m_bufSize = -1;
  if ( whence )
  {
    v5 = whence - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
        m_bufSize = this->m_bufSize - relOffset;
    }
    else
    {
      m_bufSize = relOffset + this->m_bufCurrent;
    }
  }
  else
  {
    m_bufSize = relOffset;
  }
  result->m_enum = HK_SUCCESS;
  if ( m_bufSize >= 0 )
  {
    if ( m_bufSize > this->m_bufSize )
    {
      m_bufSize = this->m_bufSize;
      result->m_enum = HK_FAILURE;
    }
    this->m_bufCurrent = m_bufSize;
    v6 = result;
    this->m_hitEof.m_bool = 0;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    v6 = result;
    this->m_bufCurrent = 0;
    this->m_hitEof.m_bool = 0;
  }
  return v6;
}

// File Line: 103
// RVA: 0x1301D90
__int64 __fastcall hkMemoryStreamReader::tell(hkMemoryStreamReader *this)
{
  return (unsigned int)this->m_bufCurrent;
}

