// File Line: 15
// RVA: 0xE67380
const char *__fastcall hkXmlParser::StartElement::getAttribute(
        hkXmlParser::StartElement *this,
        const char *a,
        const char *d)
{
  int v3; // ebx
  __int64 i; // rdi
  const char *v8; // rcx
  int v9; // eax

  v3 = 0;
  if ( this->attributes.m_size <= 0 )
    return d;
  for ( i = 0i64; ; ++i )
  {
    v8 = (const char *)((unsigned __int64)this->attributes.m_data[i].name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( !v8 )
      break;
    if ( a )
    {
      v9 = hkString::strCmp(v8, a);
      goto LABEL_7;
    }
LABEL_8:
    if ( ++v3 >= this->attributes.m_size )
      return d;
  }
  v9 = -(a != 0i64);
LABEL_7:
  if ( v9 )
    goto LABEL_8;
  return (const char *)((unsigned __int64)this->attributes.m_data[v3].value.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 27
// RVA: 0xE67420
hkResult *__fastcall hkXmlParser::Characters::canonicalize(
        hkXmlParser::Characters *this,
        hkResult *result,
        const char *spaceChars)
{
  hkStringPtr *p_text; // rsi
  int v6; // edi
  int v7; // r9d
  const char *v8; // rdx
  char *array; // [rsp+30h] [rbp-28h] BYREF
  int v11; // [rsp+38h] [rbp-20h]
  int v12; // [rsp+3Ch] [rbp-1Ch]
  hkResult resulta; // [rsp+60h] [rbp+8h] BYREF

  p_text = &this->text;
  v12 = 0x80000000;
  array = 0i64;
  v11 = 0;
  v6 = hkStringPtr::getLength(&this->text) + 1;
  if ( v6 > 0 )
  {
    v7 = v6;
    hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, (const void **)&array, v7, 1);
  }
  v8 = (const char *)((unsigned __int64)p_text->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  v11 = v6;
  if ( hkXmlParser::canonicalize(array, v8, spaceChars) == -1 )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    hkStringPtr::operator=(p_text, array);
    result->m_enum = HK_SUCCESS;
  }
  v11 = 0;
  if ( v12 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, v12 & 0x3FFFFFFF);
  return result;
}

// File Line: 76
// RVA: 0xE68070
__int64 __fastcall hkXmlParser::translateEntities(char *dst, const char *src)
{
  const char *v2; // rbx
  int v3; // r12d
  char *v4; // r14
  char v5; // al
  char v6; // al
  const char *v7; // rbp
  signed int v8; // edi
  __int64 v10; // rsi
  const char *v11; // rax
  char v12; // r15
  const char *v13; // rdi
  unsigned int v14; // eax
  char dsta[16]; // [rsp+20h] [rbp-68h] BYREF
  const char *v16; // [rsp+30h] [rbp-58h]
  __int64 v17[5]; // [rsp+38h] [rbp-50h]

  v2 = src;
  v3 = (int)dst;
  v4 = dst;
  if ( !*src )
  {
LABEL_11:
    *v4 = 0;
    return (unsigned int)((_DWORD)v4 - v3);
  }
  while ( 1 )
  {
    v5 = *v2++;
    if ( v5 != 38 )
      goto LABEL_9;
    v6 = *v2;
    v7 = v2;
    if ( *v2 != 59 )
      break;
LABEL_6:
    ++v2;
    if ( *v7 == 35 )
    {
      v8 = (_DWORD)v2 - (_DWORD)v7 - 2;
      if ( v8 >= 10 )
        return 0xFFFFFFFFi64;
      hkString::strNcpy(dsta, v7 + 1, v8);
      dsta[v8] = 0;
      v5 = hkString::atoi(dsta, 0);
LABEL_9:
      *v4++ = v5;
      goto LABEL_10;
    }
    v16 = "<lt";
    v17[0] = (__int64)">gt";
    v17[1] = (__int64)"&amp";
    v17[2] = (__int64)"\"quot";
    v17[3] = (__int64)"apos";
    v17[4] = 0i64;
    v10 = 0i64;
    v11 = "<lt";
    while ( 1 )
    {
      v12 = *v11;
      v13 = v11 + 1;
      v14 = hkString::strLen(v11 + 1);
      if ( !hkString::strNcmp(v7, v13, v14) )
        break;
      v11 = (const char *)v17[v10++];
      if ( !v11 )
        goto LABEL_17;
    }
    *v4++ = v12;
LABEL_17:
    if ( !v17[v10 - 1] )
      return 0xFFFFFFFFi64;
LABEL_10:
    if ( !*v2 )
      goto LABEL_11;
  }
  while ( v6 )
  {
    v6 = *++v2;
    if ( v6 == 59 )
      goto LABEL_6;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 132
// RVA: 0xE682D0
char __fastcall inString(char c, char *s)
{
  char v2; // al

  if ( !s )
    return 0;
  v2 = *s;
  if ( !*s )
    return 0;
  while ( 1 )
  {
    ++s;
    if ( c == v2 )
      break;
    v2 = *s;
    if ( !*s )
      return 0;
  }
  return 1;
}

// File Line: 149
// RVA: 0xE68220
__int64 __fastcall hkXmlParser::canonicalize(char *dst, const char *src, const char *spaceChars)
{
  const char *v3; // r11
  char *v5; // r9
  char v6; // al
  __int64 v7; // rdi
  unsigned __int64 v8; // r10
  const char *v9; // rcx
  char v10; // dl

  v3 = src;
  v5 = dst;
  v6 = 1;
  if ( !*src )
    goto LABEL_17;
  v7 = 0x100002600i64;
  do
  {
    v8 = *(unsigned __int8 *)v3++;
    if ( (unsigned __int8)v8 > 0x20u || !_bittest64(&v7, v8) )
    {
      v9 = spaceChars;
      if ( !spaceChars || !*spaceChars )
      {
LABEL_9:
        v6 = 0;
        *v5 = v8;
LABEL_10:
        ++v5;
        continue;
      }
      while ( 1 )
      {
        v10 = *v9++;
        if ( (_BYTE)v8 == v10 )
          break;
        if ( !*v9 )
          goto LABEL_9;
      }
    }
    if ( !v6 )
    {
      *v5 = 32;
      v6 = 1;
      goto LABEL_10;
    }
  }
  while ( *v3 );
  if ( v5 != dst && v6 )
  {
    *(v5 - 1) = 0;
    return (unsigned int)((_DWORD)v5 - (_DWORD)dst);
  }
LABEL_17:
  *v5 = 0;
  return (unsigned int)((_DWORD)v5 - (_DWORD)dst);
}

// File Line: 184
// RVA: 0xE68300
hkBool *__fastcall isSpace(hkBool *result, unsigned __int64 c)
{
  __int64 v2; // rax

  if ( (unsigned __int8)c <= 0x20u && (v2 = 0x100002600i64, _bittest64(&v2, c)) )
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

// File Line: 189
// RVA: 0xE68330
const char *__fastcall eatWhite(const char *p)
{
  __int64 v1; // rdx

  v1 = 0x100002600i64;
  while ( *p <= 0x20u && _bittest64(&v1, *p) )
    ++p;
  return p;
}

// File Line: 198
// RVA: 0xE68360
hkResult *__fastcall extractAttributes(
        hkResult *result,
        const char *buf,
        hkArray<hkXmlParser::Attribute,hkContainerHeapAllocator> *attrs)
{
  const char *v5; // rbx
  __int64 v6; // rbp
  const char *v7; // rdx
  unsigned __int64 v8; // rax
  const char *v9; // rax
  const char *v10; // rax
  const char *v11; // rbx
  char v12; // al
  const char *v13; // rbx
  const char *v14; // rdx
  hkXmlParser::Attribute *v15; // rdi
  hkStringPtr strRef; // [rsp+20h] [rbp-18h] BYREF
  hkStringPtr v18; // [rsp+28h] [rbp-10h] BYREF

  v5 = eatWhite(buf);
  if ( *v5 )
  {
    v6 = 0x100002600i64;
    while ( 1 )
    {
      hkStringPtr::hkStringPtr(&strRef);
      hkStringPtr::hkStringPtr(&v18);
      v7 = v5;
      while ( 1 )
      {
        v8 = *(unsigned __int8 *)v5;
        if ( (unsigned __int8)v8 <= 0x20u )
        {
          if ( _bittest64(&v6, v8) )
            break;
        }
        if ( (_BYTE)v8 == 61 )
          break;
        ++v5;
        if ( !(_BYTE)v8 )
          goto LABEL_8;
      }
      hkStringPtr::set(&strRef, v7, (_DWORD)v5 - (_DWORD)v7);
      v9 = eatWhite(v5);
      if ( *v9 != 61 )
        goto LABEL_8;
      v10 = eatWhite(v9 + 1);
      v11 = v10;
      if ( *v10 != 34 )
        goto LABEL_8;
      v12 = v10[1];
      v13 = v11 + 1;
      v14 = v13;
      if ( v12 != 34 )
        break;
LABEL_14:
      hkStringPtr::set(&v18, v14, (_DWORD)v13 - (_DWORD)v14);
      if ( attrs->m_size == (attrs->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&attrs->m_data, 16);
      v15 = &attrs->m_data[attrs->m_size];
      if ( v15 )
      {
        hkStringPtr::hkStringPtr(&v15->name, &strRef);
        hkStringPtr::hkStringPtr(&v15->value, &v18);
      }
      ++attrs->m_size;
      hkStringPtr::~hkStringPtr(&v18);
      hkStringPtr::~hkStringPtr(&strRef);
      v5 = eatWhite(v13 + 1);
      if ( !*v5 )
        goto LABEL_19;
    }
    while ( 1 )
    {
      ++v13;
      if ( !v12 )
        break;
      v12 = *v13;
      if ( *v13 == 34 )
        goto LABEL_14;
    }
LABEL_8:
    result->m_enum = HK_FAILURE;
    hkStringPtr::~hkStringPtr(&v18);
    hkStringPtr::~hkStringPtr(&strRef);
    return result;
  }
LABEL_19:
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 246
// RVA: 0xE67510
void __fastcall hkXmlParser::hkXmlParser(hkXmlParser *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlParser::`vftable;
  this->m_pendingNodes.m_capacityAndFlags = 0x80000000;
  this->m_pendingNodes.m_data = 0i64;
  this->m_pendingNodes.m_size = 0;
  hkStringPtr::hkStringPtr(&this->m_lastError);
}

// File Line: 250
// RVA: 0xE67560
void __fastcall hkXmlParser::~hkXmlParser(hkXmlParser *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkXmlParser::Node *v4; // rcx
  int m_capacityAndFlags; // r8d

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlParser::`vftable;
  if ( this->m_pendingNodes.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_pendingNodes.m_data[v3];
      if ( v4 )
        v4->vfptr->__vecDelDtor(v4, 1u);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_pendingNodes.m_size );
  }
  hkStringPtr::~hkStringPtr(&this->m_lastError);
  m_capacityAndFlags = this->m_pendingNodes.m_capacityAndFlags;
  this->m_pendingNodes.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_pendingNodes.m_data,
      8 * m_capacityAndFlags);
  this->m_pendingNodes.m_data = 0i64;
  this->m_pendingNodes.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 259
// RVA: 0xE684F0
void __fastcall eatTag(
        char *buf,
        unsigned int bufSize,
        unsigned int bufCapacity,
        hkStreamReader *sb,
        hkArray<char,hkContainerHeapAllocator> *tag)
{
  int numtoinsert; // ebx
  __int64 i; // rax
  hkBaseObjectVtbl *vfptr; // rax

  while ( 1 )
  {
    numtoinsert = 0;
    for ( i = 0i64; i < (int)bufSize; ++numtoinsert )
    {
      if ( buf[i] == 62 )
        break;
      ++i;
    }
    if ( tag )
      hkArrayBase<char>::_insertAt(tag, &hkContainerHeapAllocator::s_alloc, tag->m_size, buf, numtoinsert);
    vfptr = sb->vfptr;
    if ( numtoinsert != bufSize )
      break;
    ((void (__fastcall *)(hkStreamReader *, _QWORD))vfptr[2].__first_virtual_table_function__)(sb, bufSize);
    bufSize = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))sb->vfptr[3].__vecDelDtor)(
                sb,
                buf,
                bufCapacity);
    if ( !bufSize )
      return;
  }
  ((void (__fastcall *)(hkStreamReader *, _QWORD))vfptr[2].__first_virtual_table_function__)(
    sb,
    (unsigned int)(numtoinsert + 1));
}

// File Line: 288
// RVA: 0xE685A0
void __fastcall eatText(
        char *buf,
        unsigned int bufSize,
        unsigned int bufCapacity,
        hkStreamReader *sb,
        hkArray<char,hkContainerHeapAllocator> *text)
{
  unsigned int numtoinsert; // ebx
  __int64 i; // rax
  hkBaseObjectVtbl *vfptr; // rax

  while ( 1 )
  {
    numtoinsert = 0;
    for ( i = 0i64; i < (int)bufSize; ++numtoinsert )
    {
      if ( buf[i] == 60 )
        break;
      ++i;
    }
    hkArrayBase<char>::_insertAt(text, &hkContainerHeapAllocator::s_alloc, text->m_size, buf, numtoinsert);
    vfptr = sb->vfptr;
    if ( numtoinsert != bufSize )
      break;
    ((void (__fastcall *)(hkStreamReader *, _QWORD))vfptr[2].__first_virtual_table_function__)(sb, bufSize);
    bufSize = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))sb->vfptr[3].__vecDelDtor)(
                sb,
                buf,
                bufCapacity);
    if ( !bufSize )
      return;
  }
  ((void (__fastcall *)(hkStreamReader *, _QWORD))vfptr[2].__first_virtual_table_function__)(sb, numtoinsert);
}

// File Line: 320
// RVA: 0xE68650
void __fastcall eatComment(char *buf, unsigned int bufSize, unsigned int bufCapacity, hkStreamReader *sb)
{
  __int64 v8; // rbx
  int v9; // edx
  char *v10; // r8
  hkBaseObjectVtbl *vfptr; // rax
  int v12; // [rsp+48h] [rbp+10h]

  v12 = 4074797;
  v8 = 0i64;
  while ( 1 )
  {
    v9 = 0;
    if ( (int)bufSize > 0 )
    {
      v10 = buf;
      do
      {
        if ( *v10 == *((_BYTE *)&v12 + v8) )
        {
          ++v8;
          if ( !*((_BYTE *)&v12 + v8) )
            break;
        }
        else if ( *v10 != 45 )
        {
          v8 = 0i64;
        }
        ++v10;
        ++v9;
      }
      while ( v10 - buf < (int)bufSize );
    }
    vfptr = sb->vfptr;
    if ( v9 != bufSize )
      break;
    ((void (__fastcall *)(hkStreamReader *, _QWORD))vfptr[2].__first_virtual_table_function__)(sb, bufSize);
    bufSize = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))sb->vfptr[3].__vecDelDtor)(
                sb,
                buf,
                bufCapacity);
    if ( !bufSize )
      return;
  }
  ((void (__fastcall *)(hkStreamReader *, _QWORD))vfptr[2].__first_virtual_table_function__)(sb, (unsigned int)(v9 + 1));
}

// File Line: 361
// RVA: 0xE67620
hkResult *__fastcall hkXmlParser::nextNode(
        hkXmlParser *this,
        hkResult *result,
        hkXmlParser::Node **ret,
        hkStreamReader *reader)
{
  __int64 m_size; // r8
  hkXmlParser::Node **m_data; // rax
  hkStreamReader *m_pntr; // rdi
  int v10; // ebx
  __int64 v11; // r14
  int v12; // r8d
  char *v13; // r9
  int v14; // ecx
  char *v15; // rdx
  char *v17; // rdi
  int v18; // r14d
  _QWORD **v19; // rax
  __int64 v20; // rax
  hkXmlParser::Node *v21; // rdi
  _QWORD **Value; // rax
  hkXmlParser::Characters *v23; // rax
  hkXmlParser::Node *v24; // rax
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  char *v28; // rdx
  _QWORD **v29; // rax
  hkXmlParser::EndElement *v30; // rax
  hkXmlParser::Node *v31; // rax
  int m_capacityAndFlags; // r8d
  bool v33; // bl
  int v34; // r14d
  char *v35; // rax
  const char *v36; // r14
  _QWORD **v37; // rax
  hkXmlParser::StartElement *v38; // rax
  __int64 v39; // rax
  __int64 v40; // rdi
  _QWORD **v41; // rax
  hkXmlParser::EndElement *v42; // rax
  __int64 v43; // rax
  __int64 v44; // rdx
  int v45; // edi
  int v46; // edi
  hkXmlParser::Attribute *v47; // rbx
  hkArray<char,hkContainerHeapAllocator> text; // [rsp+30h] [rbp-D0h] BYREF
  hkArray<char,hkContainerHeapAllocator> array; // [rsp+40h] [rbp-C0h] BYREF
  hkArray<hkXmlParser::Attribute,hkContainerHeapAllocator> attrs; // [rsp+50h] [rbp-B0h] BYREF
  hkIstream v51; // [rsp+60h] [rbp-A0h] BYREF
  char buf; // [rsp+78h] [rbp-88h] BYREF
  char b[39]; // [rsp+79h] [rbp-87h] BYREF
  hkStringBuf v54; // [rsp+A0h] [rbp-60h] BYREF
  hkResult resulta; // [rsp+160h] [rbp+60h] BYREF

  hkIstream::hkIstream(&v51, reader);
  if ( this->m_pendingNodes.m_size )
  {
    m_size = this->m_pendingNodes.m_size;
    m_data = this->m_pendingNodes.m_data;
    result->m_enum = HK_SUCCESS;
    *ret = m_data[m_size - 1];
    --this->m_pendingNodes.m_size;
    hkIstream::~hkIstream(&v51);
    return result;
  }
  *ret = 0i64;
  if ( !hkIstream::isOk(&v51, (hkBool *)&resulta)->m_bool )
  {
    hkStringPtr::operator=(&this->m_lastError, "End of stream");
    result->m_enum = HK_FAILURE;
    hkIstream::~hkIstream(&v51);
    return result;
  }
  m_pntr = v51.m_streamReader.m_pntr;
  text.m_data = 0i64;
  text.m_size = 0;
  text.m_capacityAndFlags = 0x80000000;
  v10 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))v51.m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
          v51.m_streamReader.m_pntr,
          &buf,
          32i64);
  if ( !v10 )
  {
LABEL_24:
    hkStringPtr::printf(&this->m_lastError, "premature end of stream");
    result->m_enum = HK_FAILURE;
    goto LABEL_25;
  }
  v11 = 0x100002600i64;
  while ( 1 )
  {
    if ( buf != 60 )
    {
      eatText(&buf, v10, 32, m_pntr, &text);
      goto LABEL_23;
    }
    if ( v10 < 2 )
      goto LABEL_24;
    if ( b[0] == 63 )
    {
      eatTag(&buf, v10, 32, m_pntr, 0i64);
      goto LABEL_23;
    }
    if ( v10 >= 4 && !hkString::strNcmp("!--", b, 3u) )
    {
      eatComment(&buf, v10, 32, m_pntr);
      goto LABEL_23;
    }
    v12 = text.m_size;
    if ( !text.m_size )
      break;
    v13 = text.m_data;
    v14 = 0;
    if ( text.m_size > 0 )
    {
      v15 = text.m_data;
      do
      {
        if ( (unsigned __int8)*v15 > 0x20u )
          break;
        if ( !_bittest64(&v11, *v15) )
          break;
        ++v14;
        ++v15;
      }
      while ( v14 < text.m_size );
    }
    if ( v14 != text.m_size )
    {
      if ( text.m_size == (text.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&text.m_data, 1);
        v12 = text.m_size;
        v13 = text.m_data;
      }
      v13[v12] = 0;
      v17 = text.m_data;
      ++text.m_size;
      v18 = hkXmlParser::translateEntities(text.m_data, text.m_data);
      if ( v18 != 1 || *v17 )
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v23 = (hkXmlParser::Characters *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           32i64);
        if ( v23 )
        {
          hkXmlParser::Characters::Characters(v23, v17, v18);
          result->m_enum = HK_SUCCESS;
          *ret = v24;
        }
        else
        {
          result->m_enum = HK_SUCCESS;
          *ret = 0i64;
        }
      }
      else
      {
        v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v20 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(v19[11], 32i64);
        v21 = (hkXmlParser::Node *)v20;
        if ( v20 )
        {
          *(_DWORD *)(v20 + 8) = 0x1FFFF;
          *(_DWORD *)(v20 + 16) = 3;
          *(_QWORD *)v20 = &hkXmlParser::Characters::`vftable;
          hkStringPtr::hkStringPtr((hkStringPtr *)(v20 + 24), 0i64);
          *ret = v21;
        }
        else
        {
          *ret = 0i64;
        }
        result->m_enum = HK_SUCCESS;
      }
      goto LABEL_25;
    }
    text.m_size = 0;
LABEL_23:
    v10 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))m_pntr->vfptr[3].__vecDelDtor)(
            m_pntr,
            &buf,
            32i64);
    if ( !v10 )
      goto LABEL_24;
  }
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  eatTag(&buf, v10, 32, m_pntr, &array);
  v25 = array.m_size;
  if ( !array.m_size )
  {
    hkStringPtr::printf(&this->m_lastError, "Empty tag");
    goto LABEL_42;
  }
  if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 1);
    v25 = array.m_size;
  }
  array.m_data[v25] = 0;
  ++array.m_size;
  v26 = hkXmlParser::translateEntities(array.m_data, array.m_data);
  v27 = v26;
  if ( v26 == -1 )
  {
    hkStringPtr::printf(&this->m_lastError, "Bad tag");
LABEL_42:
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v28 = array.m_data;
    array.m_size = v26;
    if ( array.m_data[1] == 47 )
    {
      hkStringBuf::hkStringBuf(&v54, (const char *)array.m_data + 2);
      v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v30 = (hkXmlParser::EndElement *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v29[11] + 8i64))(v29[11], 32i64);
      if ( v30 )
        hkXmlParser::EndElement::EndElement(v30, v54.m_string.m_data);
      else
        v31 = 0i64;
      m_capacityAndFlags = v54.m_string.m_capacityAndFlags;
      *ret = v31;
      result->m_enum = HK_SUCCESS;
      v54.m_string.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          v54.m_string.m_data,
          m_capacityAndFlags & 0x3FFFFFFF);
      v54.m_string.m_data = 0i64;
      v54.m_string.m_capacityAndFlags = 0x80000000;
    }
    else
    {
      v33 = array.m_data[v26 - 1] == 47;
      if ( array.m_data[v26 - 1] == 47 )
      {
        array.m_data[v26 - 1] = 0;
        v28 = array.m_data;
        v27 = --array.m_size;
      }
      v34 = 0;
      if ( v27 > 0 )
      {
        v35 = v28;
        do
        {
          if ( *v35 == 32 )
            break;
          ++v34;
          ++v35;
        }
        while ( v34 < v27 );
      }
      attrs.m_data = 0i64;
      attrs.m_size = 0;
      attrs.m_capacityAndFlags = 0x80000000;
      if ( v34 != v27 )
      {
        extractAttributes(&resulta, &v28[v34], &attrs);
        array.m_data[v34] = 0;
        v28 = array.m_data;
        array.m_size = v34;
      }
      v36 = v28 + 1;
      v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (hkXmlParser::StartElement *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v37[11] + 8i64))(
                                           v37[11],
                                           48i64);
      if ( v38 )
      {
        hkXmlParser::StartElement::StartElement(v38, v36);
        v40 = v39;
      }
      else
      {
        v40 = 0i64;
      }
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)(v40 + 32),
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&attrs);
      if ( v33 )
      {
        v41 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v42 = (hkXmlParser::EndElement *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v41[11] + 8i64))(
                                           v41[11],
                                           32i64);
        if ( v42 )
        {
          hkXmlParser::EndElement::EndElement(v42, v36);
          v44 = v43;
        }
        else
        {
          v44 = 0i64;
        }
        this->vfptr[2].__vecDelDtor(this, v44);
      }
      *ret = (hkXmlParser::Node *)v40;
      v45 = attrs.m_size;
      result->m_enum = HK_SUCCESS;
      v46 = v45 - 1;
      if ( v46 >= 0 )
      {
        v47 = &attrs.m_data[v46];
        do
        {
          hkStringPtr::~hkStringPtr(&v47->value);
          hkStringPtr::~hkStringPtr(&v47->name);
          --v47;
          --v46;
        }
        while ( v46 >= 0 );
      }
      attrs.m_size = 0;
      if ( attrs.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          attrs.m_data,
          16 * attrs.m_capacityAndFlags);
      attrs.m_data = 0i64;
      attrs.m_capacityAndFlags = 0x80000000;
    }
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      array.m_capacityAndFlags & 0x3FFFFFFF);
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
LABEL_25:
  text.m_size = 0;
  if ( text.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      text.m_data,
      text.m_capacityAndFlags & 0x3FFFFFFF);
  text.m_data = 0i64;
  text.m_capacityAndFlags = 0x80000000;
  hkIstream::~hkIstream(&v51);
  return result;
}

// File Line: 500
// RVA: 0xE67C90
void __fastcall hkXmlParser::putBack(hkXmlParser *this, hkXmlParser::Node *node)
{
  hkArray<hkXmlParser::Node *,hkContainerHeapAllocator> *p_m_pendingNodes; // rbx

  p_m_pendingNodes = &this->m_pendingNodes;
  if ( this->m_pendingNodes.m_size == (this->m_pendingNodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_pendingNodes->m_data, 8);
  p_m_pendingNodes->m_data[p_m_pendingNodes->m_size++] = node;
}

// File Line: 505
// RVA: 0xE67CF0
hkResult *__fastcall hkXmlParser::expandNode(
        hkXmlParser *this,
        hkResult *result,
        hkXmlParser::StartElement *top,
        hkTree<hkRefPtr<hkXmlParser::Node> > *tree,
        hkStreamReader *reader)
{
  hkStreamReader *v5; // rsi
  hkXmlParser::Node *m_pntr; // rbp
  _QWORD **v11; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v12; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *appended; // rdi
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *m_root; // rcx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *i; // rax
  hkBaseObjectVtbl *vfptr; // rax
  hkXmlParser::Node *v17; // rbx
  hkXmlParser::Node *v18; // rsi
  hkReferencedObject *v19; // r15
  unsigned __int64 v20; // rax
  int v21; // eax
  hkIstream v23; // [rsp+20h] [rbp-58h] BYREF
  char v24; // [rsp+80h] [rbp+8h] BYREF
  hkReferencedObject *v25; // [rsp+90h] [rbp+18h] BYREF
  hkRefPtr<hkXmlParser::Node> value; // [rsp+98h] [rbp+20h] BYREF

  v5 = reader;
  hkIstream::hkIstream(&v23, reader);
  m_pntr = 0i64;
  if ( tree->m_root )
  {
    hkTree<hkRefPtr<hkXmlParser::Node>>::remove(tree, tree->m_root);
    tree->m_root = 0i64;
  }
  if ( top )
    hkReferencedObject::addReference(top);
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkTree<hkRefPtr<hkXmlParser::Node> >::Node *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v11[11] + 8i64))(
                                                        v11[11],
                                                        32i64);
  appended = v12;
  if ( v12 )
  {
    v12->m_firstChild = 0i64;
    v12->m_nextSibling = 0i64;
    v12->m_parent = 0i64;
    if ( top )
      hkReferencedObject::addReference(top);
    appended->m_value.m_pntr = top;
  }
  else
  {
    appended = 0i64;
  }
  appended->m_parent = 0i64;
  m_root = tree->m_root;
  if ( tree->m_root )
  {
    for ( i = m_root->m_nextSibling; i; i = i->m_nextSibling )
      m_root = i;
    m_root->m_nextSibling = appended;
  }
  else
  {
    tree->m_root = appended;
  }
  if ( top )
    hkReferencedObject::removeReference(top);
  vfptr = this->vfptr;
  v25 = 0i64;
  if ( *(_DWORD *)((__int64 (__fastcall *)(hkXmlParser *, char *, hkReferencedObject **, hkStreamReader *))vfptr[1].__first_virtual_table_function__)(
                    this,
                    &v24,
                    &v25,
                    v5) )
  {
LABEL_37:
    if ( appended )
    {
      if ( appended->m_value.m_pntr->type == CYLINDER )
        m_pntr = appended->m_value.m_pntr;
      hkStringPtr::printf(
        &this->m_lastError,
        "Missing closing tag of %s",
        (unsigned __int64)m_pntr[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
    }
    goto LABEL_41;
  }
  while ( 1 )
  {
    v17 = (hkXmlParser::Node *)v25;
    if ( !v25 )
    {
LABEL_44:
      result->m_enum = HK_SUCCESS;
      goto LABEL_42;
    }
    if ( LODWORD(v25[1].vfptr) == 1 )
    {
      hkReferencedObject::addReference(v25);
      value.m_pntr = v17;
      appended = hkTree<hkRefPtr<hkXmlParser::Node>>::appendChild(tree, appended, &value);
      goto LABEL_35;
    }
    if ( LODWORD(v25[1].vfptr) == 2 )
      break;
    if ( LODWORD(v25[1].vfptr) == 3 )
    {
      hkReferencedObject::addReference(v25);
      value.m_pntr = v17;
      hkTree<hkRefPtr<hkXmlParser::Node>>::appendChild(tree, appended, &value);
LABEL_35:
      hkReferencedObject::removeReference(v17);
      hkReferencedObject::removeReference(v25);
      v25 = 0i64;
    }
LABEL_36:
    if ( *(_DWORD *)((__int64 (__fastcall *)(hkXmlParser *, char *, hkReferencedObject **, hkStreamReader *))this->vfptr[1].__first_virtual_table_function__)(
                      this,
                      &v24,
                      &v25,
                      v5) )
      goto LABEL_37;
  }
  v18 = appended->m_value.m_pntr;
  v19 = v25;
  if ( v18->type != CYLINDER )
    goto LABEL_45;
  v20 = *(_QWORD *)&v25[1].m_memSizeAndFlags & 0xFFFFFFFFFFFFFFFEui64;
  if ( ((unsigned __int64)v18[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( !v20 )
      goto LABEL_43;
    v21 = hkString::strCmp(
            (const char *)((unsigned __int64)v18[1].vfptr & 0xFFFFFFFFFFFFFFFEui64),
            (const char *)(*(_QWORD *)&v25[1].m_memSizeAndFlags & 0xFFFFFFFFFFFFFFFEui64));
    v17 = (hkXmlParser::Node *)v25;
  }
  else
  {
    v21 = -(v20 != 0);
  }
  if ( v21 )
  {
LABEL_43:
    hkStringPtr::printf(
      &this->m_lastError,
      "Expected tag to end %s but got %s",
      (const char *)((unsigned __int64)v18[1].vfptr & 0xFFFFFFFFFFFFFFFEui64),
      (const char *)(*(_QWORD *)&v19[1].m_memSizeAndFlags & 0xFFFFFFFFFFFFFFFEui64));
    goto LABEL_41;
  }
  if ( v18->type == CYLINDER )
  {
    appended = appended->m_parent;
    if ( v17 )
      v17->vfptr->__vecDelDtor(v17, 1u);
    if ( !appended )
      goto LABEL_44;
    v5 = reader;
    goto LABEL_36;
  }
LABEL_45:
  hkStringPtr::printf(
    &this->m_lastError,
    "Unexpected end tag %s",
    *(_QWORD *)&v19[1].m_memSizeAndFlags & 0xFFFFFFFFFFFFFFFEui64);
LABEL_41:
  result->m_enum = HK_FAILURE;
LABEL_42:
  hkIstream::~hkIstream(&v23);
  return result;
}

// File Line: 566
// RVA: 0xE67FD0
hkResult *__fastcall hkXmlParser::parse(
        hkXmlParser *this,
        hkResult *result,
        hkTree<hkRefPtr<hkXmlParser::Node> > *tree,
        hkStreamReader *reader)
{
  __int64 v9[3]; // [rsp+30h] [rbp-18h] BYREF
  char v10; // [rsp+50h] [rbp+8h] BYREF

  if ( *(_DWORD *)((__int64 (__fastcall *)(hkXmlParser *, char *, __int64 *))this->vfptr[1].__first_virtual_table_function__)(
                    this,
                    &v10,
                    v9) )
  {
LABEL_6:
    result->m_enum = HK_FAILURE;
    return result;
  }
  if ( v9[0] )
  {
    if ( *(_DWORD *)(v9[0] + 16) == 1 )
    {
      ((void (__fastcall *)(hkXmlParser *, hkResult *, __int64, hkTree<hkRefPtr<hkXmlParser::Node> > *, hkStreamReader *))this->vfptr[2].__first_virtual_table_function__)(
        this,
        result,
        v9[0],
        tree,
        reader);
      return result;
    }
    hkStringPtr::printf(&this->m_lastError, "Document does not start with an element.");
    goto LABEL_6;
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 578
// RVA: 0xE682C0
const char *__fastcall hkXmlParser::getLastError(hkXmlParser *this)
{
  return (const char *)((unsigned __int64)this->m_lastError.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

