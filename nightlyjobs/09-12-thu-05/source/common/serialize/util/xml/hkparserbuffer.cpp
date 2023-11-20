// File Line: 13
// RVA: 0xE65710
void __fastcall hkParserBuffer::hkParserBuffer(hkParserBuffer *this, hkStreamReader *reader)
{
  hkParserBuffer *v2; // rbx
  int v3; // eax
  int v4; // eax
  int v5; // er9
  char *v6; // rax
  hkResult result; // [rsp+40h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkParserBuffer::`vftable';
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_size = 0;
  this->m_buffer.m_capacityAndFlags = 2147483648;
  v2 = this;
  this->m_reader = reader;
  hkReferencedObject::addReference((hkReferencedObject *)&reader->vfptr);
  v3 = v2->m_buffer.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < 1 )
  {
    v4 = 2 * v3;
    v5 = 1;
    if ( v4 > 1 )
      v5 = v4;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_buffer, v5, 1);
  }
  v2->m_buffer.m_size = 1;
  *v2->m_buffer.m_data = 0;
  v6 = v2->m_buffer.m_data;
  v2->m_buffer.m_size = 0;
  v2->m_pos = v6;
  *(_QWORD *)&v2->m_bufferStart = 0i64;
  *(_QWORD *)&v2->m_row = 0i64;
}

// File Line: 35
// RVA: 0xE657D0
void __fastcall hkParserBuffer::~hkParserBuffer(hkParserBuffer *this)
{
  hkParserBuffer *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkParserBuffer::`vftable';
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_reader->vfptr);
  v2 = v1->m_buffer.m_capacityAndFlags;
  v1->m_buffer.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_buffer.m_data,
      v2 & 0x3FFFFFFF);
  v1->m_buffer.m_data = 0i64;
  v1->m_buffer.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 40
// RVA: 0xE659B0
__int64 __fastcall hkParserBuffer::read(hkParserBuffer *this, int size)
{
  __int64 v2; // r12
  char *v3; // r14
  __int64 v4; // rbp
  unsigned int v5; // esi
  hkParserBuffer *v6; // rbx
  int v7; // eax
  int v8; // er9
  int v9; // eax
  int v10; // eax
  __int64 v11; // rdx
  int v12; // eax
  char *v13; // rcx
  hkResult result; // [rsp+68h] [rbp+10h]

  v2 = this->m_buffer.m_size;
  v3 = this->m_buffer.m_data;
  v4 = this->m_buffer.m_size;
  v5 = size;
  v6 = this;
  if ( size < 256 )
    v5 = 256;
  v7 = this->m_buffer.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = v2 + v5 + 1;
  if ( v7 >= v8 )
  {
    result.m_enum = 0;
  }
  else
  {
    v9 = 2 * v7;
    if ( v8 < v9 )
      v8 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_buffer,
      v8,
      1);
  }
  v6->m_buffer.m_size += v5 + 1;
  v10 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))v6->m_reader->vfptr[2].__vecDelDtor)(
          v6->m_reader,
          &v6->m_buffer.m_data[v2],
          v5);
  v11 = v10;
  v12 = v4 + v10;
  v6->m_buffer.m_data[v4 + v11] = 0;
  v13 = v6->m_buffer.m_data;
  v6->m_buffer.m_size = v12;
  if ( v13 != v3 )
    v6->m_pos += v13 - v3;
  return (unsigned int)(v12 - v4);
}

// File Line: 75
// RVA: 0xE65A80
void __fastcall hkParserBuffer::lexemeCommit(hkParserBuffer *this)
{
  char *v1; // r8
  char *i; // rax

  v1 = this->m_pos;
  for ( i = &this->m_buffer.m_data[this->m_lexemeStart]; i < v1; ++i )
  {
    if ( *i == 13 || *i == 10 )
    {
      ++this->m_row;
      this->m_col = 0;
    }
  }
  this->m_lexemeStart = (_DWORD)v1 - LODWORD(this->m_buffer.m_data);
}

// File Line: 108
// RVA: 0xE65AC0
void __fastcall hkParserBuffer::bufferCommit(hkParserBuffer *this)
{
  __int64 v1; // rax
  hkParserBuffer *v2; // rbx
  int v3; // eax
  __int64 v4; // rcx

  v1 = this->m_lexemeStart;
  v2 = this;
  this->m_bufferStart = v1;
  if ( (signed int)v1 > 1024 )
  {
    hkString::memMove(this->m_buffer.m_data, &this->m_buffer.m_data[v1], this->m_buffer.m_size - v1);
    v3 = v2->m_buffer.m_size - v2->m_bufferStart;
    v2->m_buffer.m_size = v3;
    v2->m_buffer.m_data[v3] = 0;
    v4 = v2->m_bufferStart;
    v2->m_bufferStart = 0;
    v2->m_pos -= v4;
    v2->m_lexemeStart -= v4;
  }
}

// File Line: 138
// RVA: 0xE65990
void __fastcall hkParserBuffer::setLexemePosition(hkParserBuffer *this, int pos)
{
  this->m_pos = &this->m_buffer.m_data[this->m_lexemeStart + pos];
}

// File Line: 144
// RVA: 0xE65910
hkBool *__fastcall hkParserBuffer::match(hkParserBuffer *this, hkBool *result, const char *text, int len)
{
  int v4; // esi
  const char *v5; // rbp
  hkBool *v6; // rbx
  hkParserBuffer *v7; // rdi
  int v8; // eax

  v4 = len;
  v5 = text;
  v6 = result;
  v7 = this;
  v8 = LODWORD(this->m_buffer.m_data) + this->m_buffer.m_size - LODWORD(this->m_pos);
  if ( len > v8 )
  {
    hkParserBuffer::read(this, len - v8);
    v8 = LODWORD(v7->m_buffer.m_data) + v7->m_buffer.m_size - LODWORD(v7->m_pos);
  }
  if ( v8 >= v4 )
    v6->m_bool = hkString::strNcmp(v7->m_pos, v5, v4) == 0;
  else
    v6->m_bool = 0;
  return v6;
}

// File Line: 155
// RVA: 0xE65840
hkBool *__fastcall hkParserBuffer::match(hkParserBuffer *this, hkBool *result, const char *text)
{
  hkParserBuffer *v3; // rdi
  const char *v4; // rbx
  hkBool *v5; // rsi
  int v6; // eax

  v3 = this;
  v4 = text;
  v5 = result;
  v6 = hkString::strLen(text);
  hkParserBuffer::match(v3, v5, v4, v6);
  return v5;
}

// File Line: 160
// RVA: 0xE65890
hkBool *__fastcall hkParserBuffer::matchAndConsume(hkParserBuffer *this, hkBool *result, const char *text)
{
  hkParserBuffer *v3; // rsi
  const char *v4; // rbx
  hkBool *v5; // rdi
  int v6; // eax
  __int64 v7; // rbp
  hkBool resulta; // [rsp+48h] [rbp+20h]

  v3 = this;
  v4 = text;
  v5 = result;
  v6 = hkString::strLen(text);
  v7 = v6;
  if ( hkParserBuffer::match(v3, &resulta, v4, v6)->m_bool )
  {
    if ( (signed int)v7 <= LODWORD(v3->m_buffer.m_data) + v3->m_buffer.m_size - LODWORD(v3->m_pos) )
      v3->m_pos += v7;
    v5->m_bool = 1;
  }
  else
  {
    v5->m_bool = 0;
  }
  return v5;
}

