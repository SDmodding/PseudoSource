// File Line: 13
// RVA: 0xE65710
void __fastcall hkParserBuffer::hkParserBuffer(hkParserBuffer *this, hkStreamReader *reader)
{
  char *m_data; // rax
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkParserBuffer::`vftable;
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_size = 0;
  this->m_buffer.m_capacityAndFlags = 0x80000000;
  this->m_reader = reader;
  hkReferencedObject::addReference(reader);
  if ( (this->m_buffer.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_buffer.m_data, 1, 1);
  this->m_buffer.m_size = 1;
  *this->m_buffer.m_data = 0;
  m_data = this->m_buffer.m_data;
  this->m_buffer.m_size = 0;
  this->m_pos = m_data;
  *(_QWORD *)&this->m_bufferStart = 0i64;
  *(_QWORD *)&this->m_row = 0i64;
}

// File Line: 35
// RVA: 0xE657D0
void __fastcall hkParserBuffer::~hkParserBuffer(hkParserBuffer *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkParserBuffer::`vftable;
  hkReferencedObject::removeReference(this->m_reader);
  m_capacityAndFlags = this->m_buffer.m_capacityAndFlags;
  this->m_buffer.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_buffer.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 40
// RVA: 0xE659B0
__int64 __fastcall hkParserBuffer::read(hkParserBuffer *this, int size)
{
  __int64 m_size; // r12
  char *m_data; // r14
  unsigned int v4; // esi
  int v6; // eax
  int v7; // r9d
  int v8; // eax
  int v9; // eax
  __int64 v10; // rdx
  int v11; // eax
  char *v12; // rcx
  hkResult result; // [rsp+68h] [rbp+10h] BYREF

  m_size = this->m_buffer.m_size;
  m_data = this->m_buffer.m_data;
  v4 = size;
  if ( size < 256 )
    v4 = 256;
  v6 = this->m_buffer.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = m_size + v4 + 1;
  if ( v6 >= v7 )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v8 = 2 * v6;
    if ( v7 < v8 )
      v7 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_buffer.m_data, v7, 1);
  }
  this->m_buffer.m_size += v4 + 1;
  v9 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))this->m_reader->vfptr[2].__vecDelDtor)(
         this->m_reader,
         &this->m_buffer.m_data[m_size],
         v4);
  v10 = v9;
  v11 = m_size + v9;
  this->m_buffer.m_data[m_size + v10] = 0;
  v12 = this->m_buffer.m_data;
  this->m_buffer.m_size = v11;
  if ( v12 != m_data )
    this->m_pos += v12 - m_data;
  return (unsigned int)(v11 - m_size);
}

// File Line: 75
// RVA: 0xE65A80
void __fastcall hkParserBuffer::lexemeCommit(hkParserBuffer *this)
{
  char *m_pos; // r8
  char *i; // rax

  m_pos = this->m_pos;
  for ( i = &this->m_buffer.m_data[this->m_lexemeStart]; i < m_pos; ++i )
  {
    if ( *i == 13 || *i == 10 )
    {
      ++this->m_row;
      this->m_col = 0;
    }
  }
  this->m_lexemeStart = (_DWORD)m_pos - LODWORD(this->m_buffer.m_data);
}

// File Line: 108
// RVA: 0xE65AC0
void __fastcall hkParserBuffer::bufferCommit(hkParserBuffer *this)
{
  __int64 m_lexemeStart; // rax
  int v3; // eax
  __int64 m_bufferStart; // rcx

  m_lexemeStart = this->m_lexemeStart;
  this->m_bufferStart = m_lexemeStart;
  if ( (int)m_lexemeStart > 1024 )
  {
    hkString::memMove(
      this->m_buffer.m_data,
      &this->m_buffer.m_data[m_lexemeStart],
      this->m_buffer.m_size - m_lexemeStart);
    v3 = this->m_buffer.m_size - this->m_bufferStart;
    this->m_buffer.m_size = v3;
    this->m_buffer.m_data[v3] = 0;
    m_bufferStart = this->m_bufferStart;
    this->m_bufferStart = 0;
    this->m_pos -= m_bufferStart;
    this->m_lexemeStart -= m_bufferStart;
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
  int v8; // eax

  v8 = LODWORD(this->m_buffer.m_data) + this->m_buffer.m_size - LODWORD(this->m_pos);
  if ( len > v8 )
  {
    hkParserBuffer::read(this, len - v8);
    v8 = LODWORD(this->m_buffer.m_data) + this->m_buffer.m_size - LODWORD(this->m_pos);
  }
  result->m_bool = v8 >= len && hkString::strNcmp(this->m_pos, text, len) == 0;
  return result;
}

// File Line: 155
// RVA: 0xE65840
hkBool *__fastcall hkParserBuffer::match(hkParserBuffer *this, hkBool *result, const char *text)
{
  int v6; // eax

  v6 = hkString::strLen(text);
  hkParserBuffer::match(this, result, text, v6);
  return result;
}

// File Line: 160
// RVA: 0xE65890
hkBool *__fastcall hkParserBuffer::matchAndConsume(hkParserBuffer *this, hkBool *result, const char *text)
{
  int v6; // eax
  __int64 v7; // rbp
  hkBool resulta; // [rsp+48h] [rbp+20h] BYREF

  v6 = hkString::strLen(text);
  v7 = v6;
  if ( hkParserBuffer::match(this, &resulta, text, v6)->m_bool )
  {
    if ( (int)v7 <= LODWORD(this->m_buffer.m_data) + this->m_buffer.m_size - LODWORD(this->m_pos) )
      this->m_pos += v7;
    result->m_bool = 1;
  }
  else
  {
    result->m_bool = 0;
  }
  return result;
}

