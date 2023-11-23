// File Line: 25
// RVA: 0x15C77B0
void dynamic_initializer_for__hkBufferedStreamWriterClass__()
{
  hkClass::hkClass(
    &hkBufferedStreamWriterClass,
    "hkBufferedStreamWriter",
    0i64,
    48,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 32
// RVA: 0xC82460
void __fastcall hkBufferedStreamWriter::hkBufferedStreamWriter(
        hkBufferedStreamWriter *this,
        hkStreamWriter *s,
        int bufSize)
{
  hkMemoryAllocator **Value; // rax
  char *v6; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_stream = s;
  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamWriter::`vftable;
  this->m_ownBuffer.m_bool = 1;
  if ( s )
    hkReferencedObject::addReference(s);
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (char *)hkMemoryRouter::alignedAlloc(Value[11], bufSize, 64);
  this->m_bufSize = 0;
  this->m_bufCapacity = bufSize;
  this->m_buf = v6;
}

// File Line: 49
// RVA: 0xC824E0
void __fastcall hkBufferedStreamWriter::hkBufferedStreamWriter(
        hkBufferedStreamWriter *this,
        char *mem,
        unsigned int memSize,
        hkBool memoryIsString)
{
  int v4; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamWriter::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_stream = 0i64;
  this->m_bufSize = 0;
  this->m_buf = mem;
  v4 = memSize - 1;
  if ( !memoryIsString.m_bool )
    v4 = memSize;
  this->m_bufCapacity = v4;
  this->m_ownBuffer.m_bool = 0;
  if ( memoryIsString.m_bool )
    hkString::memSet(mem, 0, memSize);
}

// File Line: 57
// RVA: 0xC82540
void __fastcall hkBufferedStreamWriter::~hkBufferedStreamWriter(hkBufferedStreamWriter *this)
{
  hkStreamWriter *m_stream; // rcx
  int *m_buf; // rbx
  hkMemoryAllocator **Value; // rax

  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamWriter::`vftable;
  hkBufferedStreamWriter::flush(this);
  m_stream = this->m_stream;
  if ( m_stream )
    hkReferencedObject::removeReference(m_stream);
  if ( this->m_ownBuffer.m_bool )
  {
    m_buf = (int *)this->m_buf;
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::alignedFree(Value[11], m_buf);
  }
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 70
// RVA: 0xC82830
__int64 __fastcall hkBufferedStreamWriter::flushBuffer(hkBufferedStreamWriter *this)
{
  int m_bufSize; // edi
  int v3; // ebx
  int v4; // eax

  if ( !this->m_stream )
    return 0i64;
  m_bufSize = this->m_bufSize;
  v3 = 0;
  if ( m_bufSize <= 0 )
  {
LABEL_5:
    this->m_bufSize = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = ((__int64 (__fastcall *)(hkStreamWriter *, char *, _QWORD))this->m_stream->vfptr[2].__vecDelDtor)(
             this->m_stream,
             &this->m_buf[v3],
             (unsigned int)(m_bufSize - v3));
      v3 += v4;
      if ( !v4 )
        break;
      if ( v3 >= m_bufSize )
        goto LABEL_5;
    }
  }
  return (unsigned int)v3;
}

// File Line: 94
// RVA: 0xC825B0
__int64 __fastcall hkBufferedStreamWriter::write(hkBufferedStreamWriter *this, char *mem, int memSize)
{
  unsigned int v3; // r14d
  signed int v5; // ebx
  signed int v7; // ebp
  int m_bufSize; // edi

  v3 = memSize;
  v5 = this->m_bufCapacity - this->m_bufSize;
  v7 = memSize;
  if ( memSize <= v5 )
  {
LABEL_4:
    hkString::memCpy(&this->m_buf[this->m_bufSize], mem, v7);
    this->m_bufSize += v7;
  }
  else
  {
    while ( 1 )
    {
      hkString::memCpy(&this->m_buf[this->m_bufSize], mem, v5);
      this->m_bufSize += v5;
      m_bufSize = this->m_bufSize;
      v7 -= v5;
      mem += v5;
      if ( hkBufferedStreamWriter::flushBuffer(this) != m_bufSize )
        break;
      v5 = this->m_bufCapacity - this->m_bufSize;
      if ( v7 <= v5 )
        goto LABEL_4;
    }
    v3 -= v7;
  }
  return v3;
}

// File Line: 122
// RVA: 0xC82660
void __fastcall hkBufferedStreamWriter::flush(hkBufferedStreamWriter *this)
{
  hkStreamWriter *m_stream; // rcx

  hkBufferedStreamWriter::flushBuffer(this);
  m_stream = this->m_stream;
  if ( m_stream )
    m_stream->vfptr[2].__first_virtual_table_function__(m_stream);
}

// File Line: 131
// RVA: 0xC82690
hkBool *__fastcall hkBufferedStreamWriter::isOk(hkBufferedStreamWriter *this, hkBool *result)
{
  hkStreamWriter *m_stream; // r8
  char v5; // [rsp+30h] [rbp+8h] BYREF

  m_stream = this->m_stream;
  if ( m_stream )
  {
    result->m_bool = *(char *)((__int64 (__fastcall *)(hkStreamWriter *, char *))m_stream->vfptr[1].__first_virtual_table_function__)(
                                this->m_stream,
                                &v5);
    return result;
  }
  else
  {
    result->m_bool = this->m_bufSize != this->m_bufCapacity;
    return result;
  }
}

// File Line: 138
// RVA: 0xC826F0
hkBool *__fastcall hkBufferedStreamWriter::seekTellSupported(hkBufferedStreamWriter *this, hkBool *result)
{
  hkStreamWriter *m_stream; // rcx
  char v5; // [rsp+30h] [rbp+8h] BYREF

  m_stream = this->m_stream;
  if ( m_stream )
  {
    result->m_bool = *(char *)m_stream->vfptr[3].__vecDelDtor(m_stream, (unsigned int)&v5);
    return result;
  }
  else
  {
    result->m_bool = 1;
    return result;
  }
}

// File Line: 145
// RVA: 0xC82740
hkResult *__fastcall hkBufferedStreamWriter::seek(
        hkBufferedStreamWriter *this,
        hkResult *result,
        unsigned int relOffset,
        unsigned int whence)
{
  int m_bufCapacity; // ecx
  hkResultEnum v9; // eax

  if ( !this->m_stream )
  {
    m_bufCapacity = -1;
    if ( whence )
    {
      if ( whence == 1 )
      {
        m_bufCapacity = relOffset + this->m_bufSize;
      }
      else if ( whence == 2 )
      {
        m_bufCapacity = this->m_bufSize - relOffset;
      }
    }
    else
    {
      m_bufCapacity = relOffset;
    }
    v9 = HK_SUCCESS;
    if ( m_bufCapacity >= 0 )
    {
      if ( m_bufCapacity <= this->m_bufCapacity )
      {
LABEL_14:
        this->m_bufSize = m_bufCapacity;
        result->m_enum = v9;
        return result;
      }
      m_bufCapacity = this->m_bufCapacity;
    }
    else
    {
      m_bufCapacity = 0;
    }
    v9 = HK_FAILURE;
    goto LABEL_14;
  }
  hkBufferedStreamWriter::flushBuffer(this);
  ((void (__fastcall *)(hkStreamWriter *, hkResult *, _QWORD, _QWORD))this->m_stream->vfptr[3].__first_virtual_table_function__)(
    this->m_stream,
    result,
    relOffset,
    whence);
  return result;
}

// File Line: 185
// RVA: 0xC827F0
__int64 __fastcall hkBufferedStreamWriter::tell(hkBufferedStreamWriter *this)
{
  hkStreamWriter *m_stream; // rcx
  int v3; // edx

  m_stream = this->m_stream;
  if ( m_stream )
  {
    v3 = ((__int64 (__fastcall *)(hkStreamWriter *))m_stream->vfptr[4].__vecDelDtor)(m_stream);
    if ( v3 < 0 )
      return 0xFFFFFFFFi64;
  }
  else
  {
    v3 = 0;
  }
  return (unsigned int)(v3 + this->m_bufSize);
}

