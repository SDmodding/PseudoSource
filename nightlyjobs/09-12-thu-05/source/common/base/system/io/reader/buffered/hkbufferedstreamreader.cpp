// File Line: 26
// RVA: 0xC84450
void __fastcall hkBufferedStreamReader::Buffer::Buffer(hkBufferedStreamReader::Buffer *this, int cap)
{
  hkBufferedStreamReader::Buffer *v2; // rdi
  int v3; // ebx
  hkMemoryAllocator **v4; // rax
  char *v5; // rax

  v2 = this;
  v3 = cap;
  v4 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (char *)hkMemoryRouter::alignedAlloc(v4[11], v3, 64);
  v2->capacity = v3;
  v2->begin = v5;
  *(_QWORD *)&v2->current = 0i64;
}

// File Line: 31
// RVA: 0xC844A0
void __fastcall hkBufferedStreamReader::Buffer::~Buffer(hkBufferedStreamReader::Buffer *this)
{
  char *v1; // rbx
  hkMemoryAllocator **v2; // rax

  v1 = this->begin;
  v2 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::alignedFree(v2[11], v1);
}

// File Line: 40
// RVA: 0xC84080
void __fastcall hkBufferedStreamReader::hkBufferedStreamReader(hkBufferedStreamReader *this, hkStreamReader *s, int bufSize)
{
  hkBufferedStreamReader *v3; // rdi
  int v4; // ebx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_stream = s;
  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamReader::`vftable;
  v3 = this;
  v4 = bufSize;
  this->m_seekStream = (hkSeekableStreamReader *)((__int64 (__fastcall *)(hkStreamReader *))s->vfptr[3].__first_virtual_table_function__)(s);
  hkBufferedStreamReader::Buffer::Buffer(&v3->m_buf, v4);
  hkReferencedObject::addReference((hkReferencedObject *)&v3->m_stream->vfptr);
}

// File Line: 47
// RVA: 0xC840E0
void __fastcall hkBufferedStreamReader::~hkBufferedStreamReader(hkBufferedStreamReader *this)
{
  hkBufferedStreamReader *v1; // rbx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkBufferedStreamReader::`vftable;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_stream->vfptr);
  hkBufferedStreamReader::Buffer::~Buffer(&v1->m_buf);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 52
// RVA: 0xC844D0
__int64 __fastcall refillBuffer(hkStreamReader *sr, void *buf, int nbytes)
{
  char *v3; // rbp
  unsigned int v4; // ebx
  hkStreamReader *v5; // rsi
  unsigned int i; // edi
  int v8; // eax
  char v9; // [rsp+30h] [rbp+8h]

  v3 = (char *)buf;
  v4 = nbytes;
  v5 = sr;
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))sr->vfptr[1].__first_virtual_table_function__)(
                    sr,
                    &v9) )
    return 0i64;
  for ( i = 0; v4; v4 -= v8 )
  {
    v8 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))v5->vfptr[2].__vecDelDtor)(v5, &v3[i], v4);
    if ( v8 <= 0 )
      break;
    i += v8;
  }
  return i;
}

// File Line: 78
// RVA: 0xC84120
__int64 __fastcall hkBufferedStreamReader::read(hkBufferedStreamReader *this, void *buf, int nbytes)
{
  int v3; // esi
  int v4; // edi
  char *v5; // rbp
  hkBufferedStreamReader *v6; // rbx
  unsigned int v7; // er14
  int v8; // er8
  char *v9; // rdx
  hkStreamReader *v10; // rcx
  int v11; // eax
  __int64 result; // rax

  v3 = nbytes;
  v4 = this->m_buf.size - this->m_buf.current;
  v5 = (char *)buf;
  v6 = this;
  v7 = 0;
  if ( nbytes <= v4 )
  {
LABEL_4:
    hkString::memCpy(&v5[v7], &v6->m_buf.begin[v6->m_buf.current], v3);
    v6->m_buf.current += v3;
    result = v7 + v3;
  }
  else
  {
    while ( 1 )
    {
      hkString::memCpy(&v5[v7], &v6->m_buf.begin[v6->m_buf.current], v4);
      v8 = v6->m_buf.capacity;
      v9 = v6->m_buf.begin;
      v10 = v6->m_stream;
      v3 -= v4;
      v7 += v4;
      *(_QWORD *)&v6->m_buf.current = 0i64;
      v11 = refillBuffer(v10, v9, v8);
      v4 = v11;
      if ( !v11 )
        break;
      v6->m_buf.size = v11;
      if ( v3 <= v11 )
        goto LABEL_4;
    }
    result = v7;
  }
  return result;
}

// File Line: 116
// RVA: 0xC841D0
__int64 __fastcall hkBufferedStreamReader::skip(hkBufferedStreamReader *this, int nbytes)
{
  int v2; // ebp
  int v3; // esi
  int v4; // ebx
  hkBufferedStreamReader *v5; // rdi
  int v6; // esi
  int v7; // er14
  int v8; // eax

  v2 = 0;
  v3 = nbytes;
  v4 = this->m_buf.size - this->m_buf.current;
  v5 = this;
  if ( nbytes > v4 )
  {
    *(_QWORD *)&this->m_buf.current = 0i64;
    v6 = nbytes - v4;
    v7 = v6 / 512;
    v8 = ((__int64 (__fastcall *)(hkStreamReader *, _QWORD))this->m_stream->vfptr[2].__first_virtual_table_function__)(
           this->m_stream,
           (nbytes - v4) / 512);
    if ( v8 < v6 / 512 )
      return (unsigned int)(v4 + v8);
    v3 = v6 - v7;
    v2 = v7 + v4;
    v4 = refillBuffer(v5->m_stream, v5->m_buf.begin, v5->m_buf.capacity);
    v5->m_buf.size = v4;
  }
  if ( v3 < v4 )
    v4 = v3;
  v5->m_buf.current += v4;
  return (unsigned int)(v4 + v2);
}

// File Line: 155
// RVA: 0xC84370
hkBool *__fastcall hkBufferedStreamReader::isOk(hkBufferedStreamReader *this, hkBool *result)
{
  hkBool *v2; // rbx
  hkBool *v3; // rax
  char v4; // [rsp+30h] [rbp+8h]

  v2 = result;
  if ( this->m_buf.current != this->m_buf.size
    || *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))this->m_stream->vfptr[1].__first_virtual_table_function__)(
                   this->m_stream,
                   &v4) )
  {
    v2->m_bool = 1;
    v3 = v2;
  }
  else
  {
    v2->m_bool = 0;
    v3 = v2;
  }
  return v3;
}

// File Line: 161
// RVA: 0xC84280
signed __int64 __fastcall hkBufferedStreamReader::peek(hkBufferedStreamReader *this, void *buf, int nbytes)
{
  int v3; // ebp
  void *v4; // r14
  hkBufferedStreamReader *v5; // rdi
  __int64 v7; // rcx
  int v8; // ebx
  int v9; // ebx
  int v10; // esi
  hkStreamReader *v11; // rcx
  int v12; // er8
  char *v13; // rdx
  int v14; // ebx

  v3 = nbytes;
  v4 = buf;
  v5 = this;
  if ( nbytes > this->m_buf.capacity - 512 )
    return 0xFFFFFFFFi64;
  v7 = this->m_buf.current;
  v8 = v5->m_buf.size;
  if ( (signed int)v7 + nbytes > v8 )
  {
    v9 = v8 - v7;
    v10 = 512 - v9 % 512;
    if ( v10 != (_DWORD)v7 && v9 )
      hkMemUtil::memMove(&v5->m_buf.begin[v10], &v5->m_buf.begin[v7], v9);
    v11 = v5->m_stream;
    v12 = v5->m_buf.capacity - (v10 + v9);
    v5->m_buf.current = v10;
    v13 = &v5->m_buf.begin[v10 + v9];
    v5->m_buf.size = v10 + v9;
    v5->m_buf.size += refillBuffer(v11, v13, v12);
  }
  v14 = v5->m_buf.size - v5->m_buf.current;
  if ( v3 < v14 )
    v14 = v3;
  hkMemUtil::memCpy(v4, &v5->m_buf.begin[v5->m_buf.current], v14);
  return (unsigned int)v14;
}

// File Line: 196
// RVA: 0xC843C0
hkBufferedStreamReader *__fastcall hkBufferedStreamReader::isSeekTellSupported(hkBufferedStreamReader *this)
{
  hkBufferedStreamReader *result; // rax

  result = 0i64;
  if ( this->m_seekStream )
    result = this;
  return result;
}

// File Line: 201
// RVA: 0xC843E0
hkResult *__fastcall hkBufferedStreamReader::seek(hkBufferedStreamReader *this, hkResult *result, __int64 offset, __int64 whence)
{
  hkResult *v4; // rbx

  v4 = result;
  *(_QWORD *)&this->m_buf.current = 0i64;
  ((void (__fastcall *)(hkSeekableStreamReader *, hkResult *, __int64, __int64))this->m_seekStream->vfptr[4].__vecDelDtor)(
    this->m_seekStream,
    result,
    offset,
    whence);
  return v4;
}

// File Line: 209
// RVA: 0xC84410
signed __int64 __fastcall hkBufferedStreamReader::tell(hkBufferedStreamReader *this)
{
  hkBufferedStreamReader *v1; // rbx
  int v2; // ecx
  signed __int64 result; // rax

  v1 = this;
  v2 = ((__int64 (*)(void))this->m_seekStream->vfptr[4].__first_virtual_table_function__)();
  if ( v2 < 0 )
    result = 0xFFFFFFFFi64;
  else
    result = (unsigned int)(v2 + v1->m_buf.current - v1->m_buf.size);
  return result;
}

