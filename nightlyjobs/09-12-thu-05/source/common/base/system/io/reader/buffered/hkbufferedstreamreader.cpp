// File Line: 26
// RVA: 0xC84450
void __fastcall hkBufferedStreamReader::Buffer::Buffer(hkBufferedStreamReader::Buffer *this, int cap)
{
  hkMemoryAllocator **Value; // rax
  char *v5; // rax

  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (char *)hkMemoryRouter::alignedAlloc(Value[11], cap, 64);
  this->capacity = cap;
  this->begin = v5;
  *(_QWORD *)&this->current = 0i64;
}

// File Line: 31
// RVA: 0xC844A0
void __fastcall hkBufferedStreamReader::Buffer::~Buffer(hkBufferedStreamReader::Buffer *this)
{
  int *begin; // rbx
  hkMemoryAllocator **Value; // rax

  begin = (int *)this->begin;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(Value[11], begin);
}

// File Line: 40
// RVA: 0xC84080
void __fastcall hkBufferedStreamReader::hkBufferedStreamReader(
        hkBufferedStreamReader *this,
        hkStreamReader *s,
        int bufSize)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_stream = s;
  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamReader::`vftable;
  this->m_seekStream = (hkSeekableStreamReader *)((__int64 (__fastcall *)(hkStreamReader *))s->vfptr[3].__first_virtual_table_function__)(s);
  hkBufferedStreamReader::Buffer::Buffer(&this->m_buf, bufSize);
  hkReferencedObject::addReference(this->m_stream);
}

// File Line: 47
// RVA: 0xC840E0
void __fastcall hkBufferedStreamReader::~hkBufferedStreamReader(hkBufferedStreamReader *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamReader::`vftable;
  hkReferencedObject::removeReference(this->m_stream);
  hkBufferedStreamReader::Buffer::~Buffer(&this->m_buf);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 52
// RVA: 0xC844D0
__int64 __fastcall refillBuffer(hkStreamReader *sr, char *buf, unsigned int nbytes)
{
  unsigned int i; // edi
  int v8; // eax
  char v9; // [rsp+30h] [rbp+8h] BYREF

  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))sr->vfptr[1].__first_virtual_table_function__)(
                    sr,
                    &v9) )
    return 0i64;
  for ( i = 0; nbytes; nbytes -= v8 )
  {
    v8 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))sr->vfptr[2].__vecDelDtor)(sr, &buf[i], nbytes);
    if ( v8 <= 0 )
      break;
    i += v8;
  }
  return i;
}

// File Line: 78
// RVA: 0xC84120
__int64 __fastcall hkBufferedStreamReader::read(hkBufferedStreamReader *this, char *buf, int nbytes)
{
  signed int v3; // esi
  signed int v4; // edi
  unsigned int v7; // r14d
  int capacity; // r8d
  char *begin; // rdx
  hkStreamReader *m_stream; // rcx
  int v11; // eax

  v3 = nbytes;
  v4 = this->m_buf.size - this->m_buf.current;
  v7 = 0;
  if ( nbytes <= v4 )
  {
LABEL_4:
    hkString::memCpy(&buf[v7], &this->m_buf.begin[this->m_buf.current], v3);
    this->m_buf.current += v3;
    return v7 + v3;
  }
  else
  {
    while ( 1 )
    {
      hkString::memCpy(&buf[v7], &this->m_buf.begin[this->m_buf.current], v4);
      capacity = this->m_buf.capacity;
      begin = this->m_buf.begin;
      m_stream = this->m_stream;
      v3 -= v4;
      v7 += v4;
      *(_QWORD *)&this->m_buf.current = 0i64;
      v11 = refillBuffer(m_stream, begin, capacity);
      v4 = v11;
      if ( !v11 )
        return v7;
      this->m_buf.size = v11;
      if ( v3 <= v11 )
        goto LABEL_4;
    }
  }
}

// File Line: 116
// RVA: 0xC841D0
__int64 __fastcall hkBufferedStreamReader::skip(hkBufferedStreamReader *this, int nbytes)
{
  int v2; // ebp
  int v3; // esi
  int v4; // ebx
  int v6; // esi
  int v7; // r14d
  int v8; // eax

  v2 = 0;
  v3 = nbytes;
  v4 = this->m_buf.size - this->m_buf.current;
  if ( nbytes > v4 )
  {
    *(_QWORD *)&this->m_buf.current = 0i64;
    v6 = nbytes - v4;
    v7 = v6 / 512;
    v8 = ((__int64 (__fastcall *)(hkStreamReader *, _QWORD))this->m_stream->vfptr[2].__first_virtual_table_function__)(
           this->m_stream,
           (unsigned int)((nbytes - v4) / 512));
    if ( v8 < v6 / 512 )
      return (unsigned int)(v4 + v8);
    v3 = v6 - v7;
    v2 = v7 + v4;
    v4 = refillBuffer(this->m_stream, this->m_buf.begin, this->m_buf.capacity);
    this->m_buf.size = v4;
  }
  if ( v3 < v4 )
    v4 = v3;
  this->m_buf.current += v4;
  return (unsigned int)(v4 + v2);
}

// File Line: 155
// RVA: 0xC84370
hkBool *__fastcall hkBufferedStreamReader::isOk(hkBufferedStreamReader *this, hkBool *result)
{
  char v4; // [rsp+30h] [rbp+8h] BYREF

  if ( this->m_buf.current != this->m_buf.size
    || *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))this->m_stream->vfptr[1].__first_virtual_table_function__)(
                   this->m_stream,
                   &v4) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 161
// RVA: 0xC84280
__int64 __fastcall hkBufferedStreamReader::peek(hkBufferedStreamReader *this, void *buf, int nbytes)
{
  __int64 current; // rcx
  int size; // ebx
  int v9; // ebx
  int v10; // esi
  hkStreamReader *m_stream; // rcx
  int v12; // r8d
  char *v13; // rdx
  int v14; // ebx

  if ( nbytes > this->m_buf.capacity - 512 )
    return 0xFFFFFFFFi64;
  current = this->m_buf.current;
  size = this->m_buf.size;
  if ( (int)current + nbytes > size )
  {
    v9 = size - current;
    v10 = 512 - v9 % 512;
    if ( v10 != (_DWORD)current && v9 )
      hkMemUtil::memMove(&this->m_buf.begin[v10], &this->m_buf.begin[current], v9);
    m_stream = this->m_stream;
    v12 = this->m_buf.capacity - (v10 + v9);
    this->m_buf.current = v10;
    v13 = &this->m_buf.begin[v10 + v9];
    this->m_buf.size = v10 + v9;
    this->m_buf.size += refillBuffer(m_stream, v13, v12);
  }
  v14 = this->m_buf.size - this->m_buf.current;
  if ( nbytes < v14 )
    v14 = nbytes;
  hkMemUtil::memCpy(buf, &this->m_buf.begin[this->m_buf.current], v14);
  return (unsigned int)v14;
}

// File Line: 196
// RVA: 0xC843C0
hkBufferedStreamReader *__fastcall hkBufferedStreamReader::isSeekTellSupported(hkBufferedStreamReader *this)
{
  hkBufferedStreamReader *result; // rax

  result = 0i64;
  if ( this->m_seekStream )
    return this;
  return result;
}

// File Line: 201
// RVA: 0xC843E0
hkResult *__fastcall hkBufferedStreamReader::seek(
        hkBufferedStreamReader *this,
        hkResult *result,
        __int64 offset,
        __int64 whence)
{
  *(_QWORD *)&this->m_buf.current = 0i64;
  ((void (__fastcall *)(hkSeekableStreamReader *, hkResult *, __int64, __int64))this->m_seekStream->vfptr[4].__vecDelDtor)(
    this->m_seekStream,
    result,
    offset,
    whence);
  return result;
}

// File Line: 209
// RVA: 0xC84410
__int64 __fastcall hkBufferedStreamReader::tell(hkBufferedStreamReader *this)
{
  int v2; // ecx

  v2 = ((__int64 (__fastcall *)(hkSeekableStreamReader *))this->m_seekStream->vfptr[4].__first_virtual_table_function__)(this->m_seekStream);
  if ( v2 < 0 )
    return 0xFFFFFFFFi64;
  else
    return (unsigned int)(v2 + this->m_buf.current - this->m_buf.size);
}

