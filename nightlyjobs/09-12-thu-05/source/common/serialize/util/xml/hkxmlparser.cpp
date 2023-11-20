// File Line: 15
// RVA: 0xE67380
const char *__fastcall hkXmlParser::StartElement::getAttribute(hkXmlParser::StartElement *this, const char *a, const char *d)
{
  int v3; // ebx
  const char *v4; // r14
  const char *v5; // rsi
  hkXmlParser::StartElement *v6; // rbp
  __int64 v7; // rdi
  const char *v8; // rcx
  int v9; // eax

  v3 = 0;
  v4 = d;
  v5 = a;
  v6 = this;
  if ( this->attributes.m_size <= 0 )
    return v4;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = (const char *)((_QWORD)v6->attributes.m_data[v7].name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    if ( !v8 )
      break;
    if ( v5 )
    {
      v9 = hkString::strCmp(v8, v5);
      goto LABEL_7;
    }
LABEL_8:
    ++v3;
    ++v7;
    if ( v3 >= v6->attributes.m_size )
      return v4;
  }
  v9 = -(v5 != 0i64);
LABEL_7:
  if ( v9 )
    goto LABEL_8;
  return (const char *)((_QWORD)v6->attributes.m_data[v3].value.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 27
// RVA: 0xE67420
hkResult *__fastcall hkXmlParser::Characters::canonicalize(hkXmlParser::Characters *this, hkResult *result, const char *spaceChars)
{
  hkStringPtr *v3; // rsi
  const char *v4; // rbp
  hkResult *v5; // rbx
  int v6; // edi
  int v7; // er9
  const char *v8; // rdx
  char *array; // [rsp+30h] [rbp-28h]
  int v11; // [rsp+38h] [rbp-20h]
  int v12; // [rsp+3Ch] [rbp-1Ch]
  hkResult resulta; // [rsp+60h] [rbp+8h]

  v3 = &this->text;
  v4 = spaceChars;
  v5 = result;
  v12 = 2147483648;
  array = 0i64;
  v11 = 0;
  v6 = (unsigned __int64)hkStringPtr::getLength(&this->text) + 1;
  if ( v6 > 0 )
  {
    v7 = v6;
    if ( v6 < 0 )
      v7 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v7, 1);
  }
  v8 = (const char *)((_QWORD)v3->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  v11 = v6;
  if ( hkXmlParser::canonicalize(array, v8, v4) == -1 )
  {
    v5->m_enum = 1;
  }
  else
  {
    hkStringPtr::operator=(v3, array);
    v5->m_enum = 0;
  }
  v11 = 0;
  if ( v12 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      v12 & 0x3FFFFFFF);
  return v5;
}

// File Line: 76
// RVA: 0xE68070
signed __int64 __fastcall hkXmlParser::translateEntities(char *dst, const char *src)
{
  const char *v2; // rbx
  int v3; // er12
  char *v4; // r14
  char v5; // al
  char v6; // al
  const char *v7; // rbp
  int v8; // edi
  __int64 v10; // rsi
  const char *v11; // rax
  char v12; // r15
  const char *v13; // rdi
  int v14; // eax
  char dsta[16]; // [rsp+20h] [rbp-68h]
  const char *v16; // [rsp+30h] [rbp-58h]
  const char *v17; // [rsp+38h] [rbp-50h]
  const char *v18; // [rsp+40h] [rbp-48h]
  const char *v19; // [rsp+48h] [rbp-40h]
  const char *v20; // [rsp+50h] [rbp-38h]
  __int64 v21; // [rsp+58h] [rbp-30h]

  v2 = src;
  v3 = (signed int)dst;
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
    v17 = ">gt";
    v18 = "&amp";
    v19 = "\"quot";
    v20 = "apos";
    v21 = 0i64;
    v10 = 0i64;
    v11 = "<lt";
    while ( 1 )
    {
      v12 = *v11;
      v13 = v11 + 1;
      v14 = hkString::strLen(v11 + 1);
      if ( !hkString::strNcmp(v7, v13, v14) )
        break;
      v11 = (&v17)[v10++];
      if ( !v11 )
        goto LABEL_18;
    }
    *v4++ = v12;
LABEL_18:
    if ( !(&v16)[v10] )
      return 0xFFFFFFFFi64;
LABEL_10:
    if ( !*v2 )
      goto LABEL_11;
  }
  while ( v6 )
  {
    v6 = (v2++)[1];
    if ( v6 == 59 )
      goto LABEL_6;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 132
// RVA: 0xE682D0
char __fastcall inString(char c, const char *s)
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
  char *v4; // rbx
  char *v5; // r9
  char v6; // al
  signed __int64 v7; // rdi
  unsigned __int64 v8; // r10
  const char *v9; // rcx
  char v10; // dl

  v3 = src;
  v4 = dst;
  v5 = dst;
  v6 = 1;
  if ( !*src )
    goto LABEL_17;
  v7 = 4294977024i64;
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
  if ( v5 != v4 && v6 )
  {
    *(v5 - 1) = 0;
    return (unsigned int)((_DWORD)v5 - (_DWORD)v4);
  }
LABEL_17:
  *v5 = 0;
  return (unsigned int)((_DWORD)v5 - (_DWORD)v4);
}

// File Line: 184
// RVA: 0xE68300
hkBool *__fastcall isSpace(hkBool *result, __int64 c)
{
  signed __int64 v2; // rax
  hkBool *v3; // rax

  if ( (unsigned __int8)c <= 0x20u && (v2 = 4294977024i64, _bittest64(&v2, c)) )
  {
    result->m_bool = 1;
    v3 = result;
  }
  else
  {
    result->m_bool = 0;
    v3 = result;
  }
  return v3;
}

// File Line: 189
// RVA: 0xE68330
const char *__fastcall eatWhite(const char *p)
{
  signed __int64 v1; // rdx

  v1 = 4294977024i64;
  while ( *p <= 0x20u && _bittest64(&v1, *p) )
    ++p;
  return p;
}

// File Line: 198
// RVA: 0xE68360
hkResult *__fastcall extractAttributes(hkResult *result, const char *buf, hkArray<hkXmlParser::Attribute,hkContainerHeapAllocator> *attrs)
{
  hkResult *v3; // r14
  hkArray<hkXmlParser::Attribute,hkContainerHeapAllocator> *v4; // rsi
  const char *v5; // rbx
  signed __int64 v6; // rbp
  const char *v7; // rdx
  unsigned __int64 v8; // rax
  const char *v9; // rax
  const char *v10; // rax
  const char *v11; // rbx
  char v12; // al
  signed __int64 v13; // rbx
  const char *v14; // rdx
  hkStringPtr *v15; // rdi
  hkStringPtr strRef; // [rsp+20h] [rbp-18h]
  hkStringPtr v18; // [rsp+28h] [rbp-10h]

  v3 = result;
  v4 = attrs;
  v5 = eatWhite(buf);
  if ( *v5 )
  {
    v6 = 4294977024i64;
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
      v13 = (signed __int64)(v11 + 1);
      v14 = (const char *)v13;
      if ( v12 != 34 )
        break;
LABEL_14:
      hkStringPtr::set(&v18, v14, v13 - (_DWORD)v14);
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
      v15 = &v4->m_data[v4->m_size].name;
      if ( v15 )
      {
        hkStringPtr::hkStringPtr(v15, &strRef);
        hkStringPtr::hkStringPtr(v15 + 1, &v18);
      }
      ++v4->m_size;
      hkStringPtr::~hkStringPtr(&v18);
      hkStringPtr::~hkStringPtr(&strRef);
      v5 = eatWhite((const char *)(v13 + 1));
      if ( !*v5 )
        goto LABEL_19;
    }
    while ( 1 )
    {
      ++v13;
      if ( !v12 )
        break;
      v12 = *(_BYTE *)v13;
      if ( *(_BYTE *)v13 == 34 )
        goto LABEL_14;
    }
LABEL_8:
    v3->m_enum = 1;
    hkStringPtr::~hkStringPtr(&v18);
    hkStringPtr::~hkStringPtr(&strRef);
    return v3;
  }
LABEL_19:
  v3->m_enum = 0;
  return v3;
}

// File Line: 246
// RVA: 0xE67510
void __fastcall hkXmlParser::hkXmlParser(hkXmlParser *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlParser::`vftable;
  this->m_pendingNodes.m_capacityAndFlags = 2147483648;
  this->m_pendingNodes.m_data = 0i64;
  this->m_pendingNodes.m_size = 0;
  hkStringPtr::hkStringPtr(&this->m_lastError);
}

// File Line: 250
// RVA: 0xE67560
void __fastcall hkXmlParser::~hkXmlParser(hkXmlParser *this)
{
  int v1; // edi
  hkXmlParser *v2; // rbx
  __int64 v3; // rsi
  hkXmlParser::Node *v4; // rcx
  int v5; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlParser::`vftable;
  v2 = this;
  if ( this->m_pendingNodes.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_pendingNodes.m_data[v3];
      if ( v4 )
        v4->vfptr->__vecDelDtor((hkBaseObject *)&v4->vfptr, 1u);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_pendingNodes.m_size );
  }
  hkStringPtr::~hkStringPtr(&v2->m_lastError);
  v5 = v2->m_pendingNodes.m_capacityAndFlags;
  v2->m_pendingNodes.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_pendingNodes.m_data,
      8 * v5);
  v2->m_pendingNodes.m_data = 0i64;
  v2->m_pendingNodes.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 259
// RVA: 0xE684F0
void __fastcall eatTag(char *buf, int bufSize, int bufCapacity, hkStreamReader *sb, hkArray<char,hkContainerHeapAllocator> *tag)
{
  hkStreamReader *v5; // r14
  unsigned int v6; // er15
  int v7; // esi
  char *v8; // rdi
  int numtoinsert; // ebx
  signed __int64 v10; // rax
  hkBaseObjectVtbl *v11; // rax

  v5 = sb;
  v6 = bufCapacity;
  v7 = bufSize;
  v8 = buf;
  while ( 1 )
  {
    numtoinsert = 0;
    v10 = 0i64;
    if ( v7 > 0 )
    {
      do
      {
        if ( v8[v10] == 62 )
          break;
        ++v10;
        ++numtoinsert;
      }
      while ( v10 < v7 );
    }
    if ( tag )
      hkArrayBase<char>::_insertAt(
        (hkArrayBase<char> *)&tag->m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        tag->m_size,
        v8,
        numtoinsert);
    v11 = v5->vfptr;
    if ( numtoinsert != v7 )
      break;
    ((void (__fastcall *)(hkStreamReader *, _QWORD))v11[2].__first_virtual_table_function__)(v5, (unsigned int)v7);
    v7 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))v5->vfptr[3].__vecDelDtor)(v5, v8, v6);
    if ( !v7 )
      return;
  }
  ((void (__fastcall *)(hkStreamReader *, _QWORD))v11[2].__first_virtual_table_function__)(
    v5,
    (unsigned int)(numtoinsert + 1));
}

// File Line: 288
// RVA: 0xE685A0
void __fastcall eatText(char *buf, int bufSize, int bufCapacity, hkStreamReader *sb, hkArray<char,hkContainerHeapAllocator> *text)
{
  hkStreamReader *v5; // r14
  unsigned int v6; // er15
  int v7; // esi
  char *v8; // rdi
  unsigned int numtoinsert; // ebx
  signed __int64 v10; // rax
  hkBaseObjectVtbl *v11; // rax

  v5 = sb;
  v6 = bufCapacity;
  v7 = bufSize;
  v8 = buf;
  while ( 1 )
  {
    numtoinsert = 0;
    v10 = 0i64;
    if ( v7 > 0 )
    {
      do
      {
        if ( v8[v10] == 60 )
          break;
        ++v10;
        ++numtoinsert;
      }
      while ( v10 < v7 );
    }
    hkArrayBase<char>::_insertAt(
      (hkArrayBase<char> *)&text->m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      text->m_size,
      v8,
      numtoinsert);
    v11 = v5->vfptr;
    if ( numtoinsert != v7 )
      break;
    ((void (__fastcall *)(hkStreamReader *, _QWORD))v11[2].__first_virtual_table_function__)(v5, (unsigned int)v7);
    v7 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))v5->vfptr[3].__vecDelDtor)(v5, v8, v6);
    if ( !v7 )
      return;
  }
  ((void (__fastcall *)(hkStreamReader *, _QWORD))v11[2].__first_virtual_table_function__)(v5, numtoinsert);
}

// File Line: 320
// RVA: 0xE68650
void __fastcall eatComment(char *buf, int bufSize, int bufCapacity, hkStreamReader *sb)
{
  hkStreamReader *v4; // rdi
  unsigned int v5; // ebp
  int v6; // er11
  char *v7; // rsi
  __int64 v8; // rbx
  int v9; // edx
  char *v10; // r8
  hkBaseObjectVtbl *v11; // rax
  int v12; // [rsp+48h] [rbp+10h]

  v4 = sb;
  v5 = bufCapacity;
  v6 = bufSize;
  v7 = buf;
  v12 = 4074797;
  v8 = 0i64;
  while ( 1 )
  {
    v9 = 0;
    if ( v6 > 0 )
    {
      v10 = v7;
      do
      {
        if ( *v10 == *((_BYTE *)&v12 + v8) )
        {
          if ( !*((_BYTE *)&v12 + ++v8) )
            break;
        }
        else if ( *v10 != 45 )
        {
          v8 = 0i64;
        }
        ++v10;
        ++v9;
      }
      while ( v10 - v7 < v6 );
    }
    v11 = v4->vfptr;
    if ( v9 != v6 )
      break;
    ((void (__fastcall *)(hkStreamReader *, _QWORD))v11[2].__first_virtual_table_function__)(v4, (unsigned int)v6);
    v6 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))v4->vfptr[3].__vecDelDtor)(v4, v7, v5);
    if ( !v6 )
      return;
  }
  ((void (__fastcall *)(hkStreamReader *, _QWORD))v11[2].__first_virtual_table_function__)(v4, (unsigned int)(v9 + 1));
}

// File Line: 361
// RVA: 0xE67620
hkResult *__fastcall hkXmlParser::nextNode(hkXmlParser *this, hkResult *result, hkXmlParser::Node **ret, hkStreamReader *reader)
{
  hkXmlParser *v4; // r12
  hkResult *v5; // r15
  hkXmlParser::Node **v6; // r13
  __int64 v7; // r8
  hkXmlParser::Node **v8; // rax
  hkStreamReader *v9; // rdi
  int v10; // ebx
  signed __int64 v11; // r14
  int v12; // er8
  char *v13; // r9
  int v14; // ecx
  char *v15; // rdx
  char *v17; // rdi
  int v18; // er14
  _QWORD **v19; // rax
  __int64 v20; // rax
  hkXmlParser::Node *v21; // rdi
  _QWORD **v22; // rax
  hkXmlParser::Characters *v23; // rax
  hkXmlParser::Node *v24; // rax
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  char *v28; // rdx
  _QWORD **v29; // rax
  hkXmlParser::EndElement *v30; // rax
  hkXmlParser::Node *v31; // rax
  int v32; // er8
  bool v33; // bl
  int v34; // er14
  char *v35; // rax
  const char *v36; // r14
  _QWORD **v37; // rax
  hkXmlParser::StartElement *v38; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v39; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v40; // rdi
  _QWORD **v41; // rax
  hkXmlParser::EndElement *v42; // rax
  __int64 v43; // rax
  __int64 v44; // rdx
  int v45; // edi
  int v46; // edi
  hkXmlParser::Attribute *v47; // rbx
  hkArray<char,hkContainerHeapAllocator> text; // [rsp+30h] [rbp-D0h]
  hkArray<char,hkContainerHeapAllocator> array; // [rsp+40h] [rbp-C0h]
  hkArray<hkXmlParser::Attribute,hkContainerHeapAllocator> attrs; // [rsp+50h] [rbp-B0h]
  hkIstream v51; // [rsp+60h] [rbp-A0h]
  char buf; // [rsp+78h] [rbp-88h]
  char b; // [rsp+79h] [rbp-87h]
  hkStringBuf v54; // [rsp+A0h] [rbp-60h]
  hkBool resulta; // [rsp+160h] [rbp+60h]

  v4 = this;
  v5 = result;
  v6 = ret;
  hkIstream::hkIstream(&v51, reader);
  if ( v4->m_pendingNodes.m_size )
  {
    v7 = v4->m_pendingNodes.m_size;
    v8 = v4->m_pendingNodes.m_data;
    v5->m_enum = 0;
    *v6 = v8[v7 - 1];
    --v4->m_pendingNodes.m_size;
    hkIstream::~hkIstream(&v51);
    return v5;
  }
  *v6 = 0i64;
  if ( !hkIstream::isOk(&v51, &resulta)->m_bool )
  {
    hkStringPtr::operator=(&v4->m_lastError, "End of stream");
    v5->m_enum = 1;
    hkIstream::~hkIstream(&v51);
    return v5;
  }
  v9 = v51.m_streamReader.m_pntr;
  text.m_data = 0i64;
  text.m_size = 0;
  text.m_capacityAndFlags = 2147483648;
  v10 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v51.m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
          v51.m_streamReader.m_pntr,
          &buf,
          32i64);
  if ( !v10 )
  {
LABEL_24:
    hkStringPtr::printf(&v4->m_lastError, "premature end of stream");
    v5->m_enum = 1;
    goto LABEL_25;
  }
  v11 = 4294977024i64;
  while ( 1 )
  {
    if ( buf != 60 )
    {
      eatText(&buf, v10, 32, v9, &text);
      goto LABEL_23;
    }
    if ( v10 < 2 )
      goto LABEL_24;
    if ( b == 63 )
    {
      eatTag(&buf, v10, 32, v9, 0i64);
      goto LABEL_23;
    }
    if ( v10 >= 4 && !hkString::strNcmp("!--", &b, 3) )
    {
      eatComment(&buf, v10, 32, v9);
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
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &text, 1);
        v12 = text.m_size;
        v13 = text.m_data;
      }
      v13[v12] = 0;
      v17 = text.m_data;
      ++text.m_size;
      v18 = hkXmlParser::translateEntities(text.m_data, text.m_data);
      if ( v18 != 1 || *v17 )
      {
        v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v23 = (hkXmlParser::Characters *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(
                                           v22[11],
                                           32i64);
        if ( v23 )
        {
          hkXmlParser::Characters::Characters(v23, v17, v18);
          v5->m_enum = 0;
          *v6 = v24;
        }
        else
        {
          v5->m_enum = 0;
          *v6 = 0i64;
        }
      }
      else
      {
        v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v20 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 32i64);
        v21 = (hkXmlParser::Node *)v20;
        if ( v20 )
        {
          *(_DWORD *)(v20 + 8) = 0x1FFFF;
          *(_DWORD *)(v20 + 16) = 3;
          *(_QWORD *)v20 = &hkXmlParser::Characters::`vftable;
          hkStringPtr::hkStringPtr((hkStringPtr *)(v20 + 24), 0i64);
          *v6 = v21;
        }
        else
        {
          *v6 = 0i64;
        }
        v5->m_enum = 0;
      }
      goto LABEL_25;
    }
    text.m_size = 0;
LABEL_23:
    v10 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v9->vfptr[3].__vecDelDtor)(v9, &buf, 32i64);
    if ( !v10 )
      goto LABEL_24;
  }
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 2147483648;
  eatTag(&buf, v10, 32, v9, &array);
  v25 = array.m_size;
  if ( !array.m_size )
  {
    hkStringPtr::printf(&v4->m_lastError, "Empty tag");
    goto LABEL_42;
  }
  if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 1);
    v25 = array.m_size;
  }
  array.m_data[v25] = 0;
  ++array.m_size;
  v26 = hkXmlParser::translateEntities(array.m_data, array.m_data);
  v27 = v26;
  if ( v26 == -1 )
  {
    hkStringPtr::printf(&v4->m_lastError, "Bad tag");
LABEL_42:
    v5->m_enum = 1;
  }
  else
  {
    v28 = array.m_data;
    array.m_size = v26;
    if ( array.m_data[1] == 47 )
    {
      hkStringBuf::hkStringBuf(&v54, (const char *)array.m_data + 2);
      v29 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v30 = (hkXmlParser::EndElement *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v29[11] + 8i64))(
                                         v29[11],
                                         32i64);
      if ( v30 )
        hkXmlParser::EndElement::EndElement(v30, v54.m_string.m_data);
      else
        v31 = 0i64;
      v32 = v54.m_string.m_capacityAndFlags;
      *v6 = v31;
      v5->m_enum = 0;
      v54.m_string.m_size = 0;
      if ( v32 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v54.m_string.m_data,
          v32 & 0x3FFFFFFF);
      v54.m_string.m_data = 0i64;
      v54.m_string.m_capacityAndFlags = 2147483648;
    }
    else
    {
      v33 = array.m_data[v26 - 1] == 47;
      if ( array.m_data[v26 - 1] == 47 )
      {
        array.m_data[v26 - 1] = 0;
        v28 = array.m_data;
        v27 = array.m_size-- - 1;
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
      attrs.m_capacityAndFlags = 2147483648;
      if ( v34 != v27 )
      {
        extractAttributes((hkResult *)&resulta, &v28[v34], &attrs);
        array.m_data[v34] = 0;
        v28 = array.m_data;
        array.m_size = v34;
      }
      v36 = v28 + 1;
      v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v38 = (hkXmlParser::StartElement *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v37[11] + 8i64))(
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
        v40 + 2,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&attrs);
      if ( v33 )
      {
        v41 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v42 = (hkXmlParser::EndElement *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v41[11] + 8i64))(
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
        v4->vfptr[2].__vecDelDtor((hkBaseObject *)&v4->vfptr, v44);
      }
      *v6 = (hkXmlParser::Node *)v40;
      v45 = attrs.m_size;
      v5->m_enum = 0;
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
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          attrs.m_data,
          16 * attrs.m_capacityAndFlags);
      attrs.m_data = 0i64;
      attrs.m_capacityAndFlags = 2147483648;
    }
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array.m_data,
      array.m_capacityAndFlags & 0x3FFFFFFF);
  array.m_data = 0i64;
  array.m_capacityAndFlags = 2147483648;
LABEL_25:
  text.m_size = 0;
  if ( text.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      text.m_data,
      text.m_capacityAndFlags & 0x3FFFFFFF);
  text.m_data = 0i64;
  text.m_capacityAndFlags = 2147483648;
  hkIstream::~hkIstream(&v51);
  return v5;
}

// File Line: 500
// RVA: 0xE67C90
void __fastcall hkXmlParser::putBack(hkXmlParser *this, hkXmlParser::Node *node)
{
  hkArray<hkXmlParser::Node *,hkContainerHeapAllocator> *v2; // rbx
  hkXmlParser::Node *v3; // rdi

  v2 = &this->m_pendingNodes;
  v3 = node;
  if ( this->m_pendingNodes.m_size == (this->m_pendingNodes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3;
}

// File Line: 505
// RVA: 0xE67CF0
hkResult *__fastcall hkXmlParser::expandNode(hkXmlParser *this, hkResult *result, hkXmlParser::StartElement *top, hkTree<hkRefPtr<hkXmlParser::Node> > *tree, hkStreamReader *reader)
{
  hkStreamReader *v5; // rsi
  hkXmlParser *v6; // r13
  hkResult *v7; // r14
  hkTree<hkRefPtr<hkXmlParser::Node> > *v8; // r12
  hkXmlParser::StartElement *v9; // rbx
  hkXmlParser::Node *v10; // rbp
  _QWORD **v11; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v12; // rax
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *v13; // rdi
  hkTree<hkRefPtr<hkXmlParser::Node> > v14; // rcx
  hkTree<hkRefPtr<hkXmlParser::Node> >::Node *i; // rax
  hkBaseObjectVtbl *v16; // rax
  hkXmlParser::Node *v17; // rbx
  hkXmlParser::Node *v18; // rsi
  hkReferencedObject *v19; // r15
  unsigned __int64 v20; // rax
  int v21; // eax
  const char *v22; // rdx
  hkBaseObjectVtbl *v23; // r8
  hkIstream v25; // [rsp+20h] [rbp-58h]
  char v26; // [rsp+80h] [rbp+8h]
  hkReferencedObject *v27; // [rsp+90h] [rbp+18h]
  hkRefPtr<hkXmlParser::Node> value; // [rsp+98h] [rbp+20h]

  v5 = reader;
  v6 = this;
  v7 = result;
  v8 = tree;
  v9 = top;
  hkIstream::hkIstream(&v25, reader);
  v10 = 0i64;
  if ( v8->m_root )
  {
    hkTree<hkRefPtr<hkXmlParser::Node>>::remove(v8, v8->m_root);
    v8->m_root = 0i64;
  }
  if ( v9 )
    hkReferencedObject::addReference((hkReferencedObject *)&v9->vfptr);
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkTree<hkRefPtr<hkXmlParser::Node> >::Node *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                                        v11[11],
                                                        32i64);
  v13 = v12;
  if ( v12 )
  {
    v12->m_firstChild = 0i64;
    v12->m_nextSibling = 0i64;
    v12->m_parent = 0i64;
    if ( v9 )
      hkReferencedObject::addReference((hkReferencedObject *)&v9->vfptr);
    v13->m_value.m_pntr = (hkXmlParser::Node *)&v9->vfptr;
  }
  else
  {
    v13 = 0i64;
  }
  v13->m_parent = 0i64;
  v14.m_root = v8->m_root;
  if ( v8->m_root )
  {
    for ( i = v14.m_root->m_nextSibling; i; i = i->m_nextSibling )
      v14.m_root = i;
    v14.m_root->m_nextSibling = v13;
  }
  else
  {
    v8->m_root = v13;
  }
  if ( v9 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v9->vfptr);
  v16 = v6->vfptr;
  v27 = 0i64;
  if ( !*(_DWORD *)((__int64 (__fastcall *)(hkXmlParser *, char *, hkReferencedObject **, hkStreamReader *))v16[1].__first_virtual_table_function__)(
                     v6,
                     &v26,
                     &v27,
                     v5) )
  {
    while ( 1 )
    {
      v17 = (hkXmlParser::Node *)v27;
      if ( !v27 )
      {
LABEL_45:
        v7->m_enum = 0;
        goto LABEL_43;
      }
      if ( LODWORD(v27[1].vfptr) == 1 )
        break;
      if ( LODWORD(v27[1].vfptr) == 2 )
      {
        v18 = v13->m_value.m_pntr;
        v19 = v27;
        if ( v18->type != 1 )
          goto LABEL_46;
        v20 = *(_QWORD *)&v27[1].m_memSizeAndFlags & 0xFFFFFFFFFFFFFFFEui64;
        if ( (_QWORD)v18[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
        {
          if ( !v20 )
            goto LABEL_44;
          v21 = hkString::strCmp(
                  (const char *)((_QWORD)v18[1].vfptr & 0xFFFFFFFFFFFFFFFEui64),
                  (const char *)(*(_QWORD *)&v27[1].m_memSizeAndFlags & 0xFFFFFFFFFFFFFFFEui64));
          v17 = (hkXmlParser::Node *)v27;
        }
        else
        {
          v21 = -(v20 != 0);
        }
        if ( v21 )
        {
LABEL_44:
          hkStringPtr::printf(
            &v6->m_lastError,
            "Expected tag to end %s but got %s",
            (_QWORD)v18[1].vfptr & 0xFFFFFFFFFFFFFFFEui64,
            *(_QWORD *)&v19[1].m_memSizeAndFlags & 0xFFFFFFFFFFFFFFFEui64);
          goto LABEL_42;
        }
        if ( v18->type != 1 )
        {
LABEL_46:
          v23 = *(hkBaseObjectVtbl **)&v19[1].m_memSizeAndFlags;
          v22 = "Unexpected end tag %s";
          goto LABEL_41;
        }
        v13 = v13->m_parent;
        if ( v17 )
          v17->vfptr->__vecDelDtor((hkBaseObject *)&v17->vfptr, 1u);
        if ( !v13 )
          goto LABEL_45;
        v5 = reader;
      }
      else if ( LODWORD(v27[1].vfptr) == 3 )
      {
        hkReferencedObject::addReference(v27);
        value.m_pntr = v17;
        hkTree<hkRefPtr<hkXmlParser::Node>>::appendChild(v8, v13, &value);
LABEL_35:
        hkReferencedObject::removeReference((hkReferencedObject *)&v17->vfptr);
        hkReferencedObject::removeReference(v27);
        v27 = 0i64;
        goto LABEL_36;
      }
LABEL_36:
      if ( *(_DWORD *)((__int64 (__fastcall *)(hkXmlParser *, char *, hkReferencedObject **, hkStreamReader *))v6->vfptr[1].__first_virtual_table_function__)(
                        v6,
                        &v26,
                        &v27,
                        v5) )
        goto LABEL_37;
    }
    hkReferencedObject::addReference(v27);
    value.m_pntr = v17;
    v13 = hkTree<hkRefPtr<hkXmlParser::Node>>::appendChild(v8, v13, &value);
    goto LABEL_35;
  }
LABEL_37:
  if ( v13 )
  {
    v22 = "Missing closing tag of %s";
    if ( v13->m_value.m_pntr->type == 1 )
      v10 = v13->m_value.m_pntr;
    v23 = v10[1].vfptr;
LABEL_41:
    hkStringPtr::printf(&v6->m_lastError, v22, (unsigned __int64)v23 & 0xFFFFFFFFFFFFFFFEui64);
  }
LABEL_42:
  v7->m_enum = 1;
LABEL_43:
  hkIstream::~hkIstream(&v25);
  return v7;
}

// File Line: 566
// RVA: 0xE67FD0
hkResult *__fastcall hkXmlParser::parse(hkXmlParser *this, hkResult *result, hkTree<hkRefPtr<hkXmlParser::Node> > *tree, hkStreamReader *reader)
{
  hkTree<hkRefPtr<hkXmlParser::Node> > *v4; // rbp
  hkResult *v5; // rbx
  hkStreamReader *v6; // rsi
  hkXmlParser *v7; // rdi
  __int64 v9; // [rsp+30h] [rbp-18h]
  char v10; // [rsp+50h] [rbp+8h]

  v4 = tree;
  v5 = result;
  v6 = reader;
  v7 = this;
  if ( *(_DWORD *)((__int64 (__fastcall *)(hkXmlParser *, char *, __int64 *))this->vfptr[1].__first_virtual_table_function__)(
                    this,
                    &v10,
                    &v9) )
  {
LABEL_6:
    v5->m_enum = 1;
    return v5;
  }
  if ( v9 )
  {
    if ( *(_DWORD *)(v9 + 16) == 1 )
    {
      ((void (__fastcall *)(hkXmlParser *, hkResult *, __int64, hkTree<hkRefPtr<hkXmlParser::Node> > *, hkStreamReader *))v7->vfptr[2].__first_virtual_table_function__)(
        v7,
        v5,
        v9,
        v4,
        v6);
      return v5;
    }
    hkStringPtr::printf(&v7->m_lastError, "Document does not start with an element.");
    goto LABEL_6;
  }
  v5->m_enum = 0;
  return v5;
}

// File Line: 578
// RVA: 0xE682C0
const char *__fastcall hkXmlParser::getLastError(hkXmlParser *this)
{
  return (const char *)((_QWORD)this->m_lastError.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

