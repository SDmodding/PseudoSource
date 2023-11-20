// File Line: 16
// RVA: 0x1301B10
void __fastcall hkMemoryStreamReader::hkMemoryStreamReader(hkMemoryStreamReader *this, const void *mem, int memSize, hkMemoryStreamReader::MemoryType mt)
{
  int v4; // esi
  const void *v5; // rdi
  hkMemoryStreamReader *v6; // rbx
  hkMemoryAllocator **v7; // rax
  char *v8; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_bufCurrent = 0;
  this->m_bufSize = memSize;
  this->m_memType = mt;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryStreamReader::`vftable';
  this->m_hitEof.m_bool = 0;
  v4 = memSize;
  v5 = mem;
  v6 = this;
  if ( mt )
  {
    this->m_buf = (char *)mem;
  }
  else
  {
    v7 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (char *)hkMemoryRouter::easyAlloc(v7[11], v4);
    v6->m_buf = v8;
    hkString::memCpy(v8, v5, v4);
  }
}

// File Line: 29
// RVA: 0x1301BB0
void __fastcall hkMemoryStreamReader::~hkMemoryStreamReader(hkMemoryStreamReader *this)
{
  bool v1; // cf
  bool v2; // zf
  hkMemoryStreamReader *v3; // rdi
  char *v4; // rbx
  hkMemoryAllocator **v5; // rax

  v1 = this->m_memType < 1u;
  v2 = this->m_memType == 1;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryStreamReader::`vftable';
  if ( v1 || v2 )
  {
    v4 = this->m_buf;
    v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(v5[11], v4);
    v3->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  }
  else
  {
    this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  }
}

// File Line: 37
// RVA: 0x1301C20
__int64 __fastcall hkMemoryStreamReader::read(hkMemoryStreamReader *this, void *buf, int nbytes)
{
  unsigned int v3; // ebx
  int v4; // esi
  hkMemoryStreamReader *v5; // rdi
  __int64 result; // rax

  v3 = nbytes;
  v4 = nbytes;
  v5 = this;
  if ( this->m_bufSize - this->m_bufCurrent < nbytes )
    v3 = this->m_bufSize - this->m_bufCurrent;
  hkString::memCpy(buf, &this->m_buf[this->m_bufCurrent], v3);
  v5->m_bufCurrent += v3;
  result = v3;
  if ( !v3 )
  {
    if ( v4 )
      v5->m_hitEof.m_bool = 1;
  }
  return result;
}

// File Line: 49
// RVA: 0x1301C90
__int64 __fastcall hkMemoryStreamReader::skip(hkMemoryStreamReader *this, int nbytes)
{
  int v2; // er9
  __int64 result; // rax
  int v4; // er8

  v2 = this->m_bufCurrent;
  result = (unsigned int)nbytes;
  v4 = this->m_bufSize - v2;
  if ( v4 < nbytes )
    result = (unsigned int)v4;
  this->m_bufCurrent = v2 + result;
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
hkResult *__fastcall hkMemoryStreamReader::seek(hkMemoryStreamReader *this, hkResult *result, int relOffset, hkSeekableStreamReader::SeekWhence whence)
{
  int v4; // er10
  __int32 v5; // er9
  hkResult *v6; // rax

  v4 = -1;
  if ( whence )
  {
    v5 = whence - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
        v4 = this->m_bufSize - relOffset;
    }
    else
    {
      v4 = relOffset + this->m_bufCurrent;
    }
  }
  else
  {
    v4 = relOffset;
  }
  result->m_enum = 0;
  if ( v4 >= 0 )
  {
    if ( v4 > this->m_bufSize )
    {
      v4 = this->m_bufSize;
      result->m_enum = 1;
    }
    this->m_bufCurrent = v4;
    v6 = result;
    this->m_hitEof.m_bool = 0;
  }
  else
  {
    result->m_enum = 1;
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

