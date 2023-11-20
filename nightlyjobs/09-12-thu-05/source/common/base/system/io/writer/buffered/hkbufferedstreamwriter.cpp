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
void __fastcall hkBufferedStreamWriter::hkBufferedStreamWriter(hkBufferedStreamWriter *this, hkStreamWriter *s, int bufSize)
{
  hkBufferedStreamWriter *v3; // rbx
  int v4; // edi
  hkMemoryAllocator **v5; // rax
  char *v6; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_stream = s;
  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamWriter::`vftable;
  v3 = this;
  this->m_ownBuffer.m_bool = 1;
  v4 = bufSize;
  if ( s )
    hkReferencedObject::addReference((hkReferencedObject *)&s->vfptr);
  v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (char *)hkMemoryRouter::alignedAlloc(v5[11], v4, 64);
  v3->m_bufSize = 0;
  v3->m_bufCapacity = v4;
  v3->m_buf = v6;
}

// File Line: 49
// RVA: 0xC824E0
void __fastcall hkBufferedStreamWriter::hkBufferedStreamWriter(hkBufferedStreamWriter *this, void *mem, int memSize, hkBool memoryIsString)
{
  int v4; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamWriter::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_stream = 0i64;
  this->m_bufSize = 0;
  this->m_buf = (char *)mem;
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
  hkBufferedStreamWriter *v1; // rdi
  hkReferencedObject *v2; // rcx
  char *v3; // rbx
  hkMemoryAllocator **v4; // rax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamWriter::`vftable;
  hkBufferedStreamWriter::flush(this);
  v2 = (hkReferencedObject *)&v1->m_stream->vfptr;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  if ( v1->m_ownBuffer.m_bool )
  {
    v3 = v1->m_buf;
    v4 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::alignedFree(v4[11], v3);
  }
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 70
// RVA: 0xC82830
__int64 __fastcall hkBufferedStreamWriter::flushBuffer(hkBufferedStreamWriter *this)
{
  hkBufferedStreamWriter *v1; // rsi
  int v2; // edi
  int v3; // ebx
  int v4; // eax

  v1 = this;
  if ( !this->m_stream )
    return 0i64;
  v2 = this->m_bufSize;
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_5:
    v1->m_bufSize = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = ((__int64 (__fastcall *)(hkStreamWriter *, char *, _QWORD))v1->m_stream->vfptr[2].__vecDelDtor)(
             v1->m_stream,
             &v1->m_buf[v3],
             (unsigned int)(v2 - v3));
      v3 += v4;
      if ( !v4 )
        break;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
  }
  return (unsigned int)v3;
}

// File Line: 94
// RVA: 0xC825B0
__int64 __fastcall hkBufferedStreamWriter::write(hkBufferedStreamWriter *this, const void *mem, int memSize)
{
  unsigned int v3; // er14
  char *v4; // r15
  int v5; // ebx
  hkBufferedStreamWriter *v6; // rsi
  int v7; // ebp
  int v8; // edi

  v3 = memSize;
  v4 = (char *)mem;
  v5 = this->m_bufCapacity - this->m_bufSize;
  v6 = this;
  v7 = memSize;
  if ( memSize <= v5 )
  {
LABEL_4:
    hkString::memCpy(&v6->m_buf[v6->m_bufSize], v4, v7);
    v6->m_bufSize += v7;
  }
  else
  {
    while ( 1 )
    {
      hkString::memCpy(&v6->m_buf[v6->m_bufSize], v4, v5);
      v6->m_bufSize += v5;
      v8 = v6->m_bufSize;
      v7 -= v5;
      v4 += v5;
      if ( hkBufferedStreamWriter::flushBuffer(v6) != v8 )
        break;
      v5 = v6->m_bufCapacity - v6->m_bufSize;
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
  hkBufferedStreamWriter *v1; // rbx
  hkStreamWriter *v2; // rcx

  v1 = this;
  hkBufferedStreamWriter::flushBuffer(this);
  v2 = v1->m_stream;
  if ( v2 )
    ((void (*)(void))v2->vfptr[2].__first_virtual_table_function__)();
}

// File Line: 131
// RVA: 0xC82690
hkBool *__fastcall hkBufferedStreamWriter::isOk(hkBufferedStreamWriter *this, hkBool *result)
{
  hkStreamWriter *v2; // r8
  hkBool *v3; // rbx
  hkBool *v4; // rax
  char v5; // [rsp+30h] [rbp+8h]

  v2 = this->m_stream;
  v3 = result;
  if ( v2 )
  {
    result->m_bool = *(char *)((__int64 (__fastcall *)(hkStreamWriter *, char *))v2->vfptr[1].__first_virtual_table_function__)(
                                this->m_stream,
                                &v5);
    v4 = v3;
  }
  else
  {
    result->m_bool = this->m_bufSize != this->m_bufCapacity;
    v4 = result;
  }
  return v4;
}

// File Line: 138
// RVA: 0xC826F0
hkBool *__fastcall hkBufferedStreamWriter::seekTellSupported(hkBufferedStreamWriter *this, hkBool *result)
{
  hkStreamWriter *v2; // rcx
  hkBool *v3; // rbx
  hkBool *v4; // rax
  char v5; // [rsp+30h] [rbp+8h]

  v2 = this->m_stream;
  v3 = result;
  if ( v2 )
  {
    result->m_bool = *(char *)v2->vfptr[3].__vecDelDtor((hkBaseObject *)&v2->vfptr, (unsigned int)&v5);
    v4 = v3;
  }
  else
  {
    result->m_bool = 1;
    v4 = result;
  }
  return v4;
}

// File Line: 145
// RVA: 0xC82740
hkResult *__fastcall hkBufferedStreamWriter::seek(hkBufferedStreamWriter *this, hkResult *result, int relOffset, hkStreamWriter::SeekWhence whence)
{
  hkStreamWriter::SeekWhence v4; // ebx
  unsigned int v5; // esi
  hkResult *v6; // r14
  hkBufferedStreamWriter *v7; // rdi
  int v8; // ecx
  hkResultEnum v9; // eax

  v4 = whence;
  v5 = relOffset;
  v6 = result;
  v7 = this;
  if ( !this->m_stream )
  {
    v8 = -1;
    if ( whence )
    {
      if ( whence == 1 )
      {
        v8 = relOffset + v7->m_bufSize;
      }
      else if ( whence == 2 )
      {
        v8 = v7->m_bufSize - relOffset;
      }
    }
    else
    {
      v8 = relOffset;
    }
    v9 = 0;
    if ( v8 >= 0 )
    {
      if ( v8 <= v7->m_bufCapacity )
      {
LABEL_14:
        v7->m_bufSize = v8;
        result->m_enum = v9;
        return v6;
      }
      v8 = v7->m_bufCapacity;
    }
    else
    {
      v8 = 0;
    }
    v9 = 1;
    goto LABEL_14;
  }
  hkBufferedStreamWriter::flushBuffer(this);
  ((void (__fastcall *)(hkStreamWriter *, hkResult *, _QWORD, _QWORD))v7->m_stream->vfptr[3].__first_virtual_table_function__)(
    v7->m_stream,
    v6,
    v5,
    (unsigned int)v4);
  return v6;
}

// File Line: 185
// RVA: 0xC827F0
signed __int64 __fastcall hkBufferedStreamWriter::tell(hkBufferedStreamWriter *this)
{
  hkBufferedStreamWriter *v1; // rbx
  hkStreamWriter *v2; // rcx
  int v3; // edx

  v1 = this;
  v2 = this->m_stream;
  if ( v2 )
  {
    v3 = ((__int64 (*)(void))v2->vfptr[4].__vecDelDtor)();
    if ( v3 < 0 )
      return 0xFFFFFFFFi64;
  }
  else
  {
    v3 = 0;
  }
  return (unsigned int)(v3 + v1->m_bufSize);
}

