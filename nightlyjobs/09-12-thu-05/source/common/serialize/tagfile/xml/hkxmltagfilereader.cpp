// File Line: 130
// RVA: 0xE533C0
void __fastcall `anonymous namespace::Reader::Reader(Reader *this, hkStreamReader *sr, hkDataWorld *cont)
{
  hkArray<char *,hkContainerHeapAllocator> *p_m_prevStrings; // rbx
  hkSubString text; // [rsp+20h] [rbp-18h] BYREF

  hkXmlStreamParser::hkXmlStreamParser(&this->m_parser, sr);
  this->m_world = cont;
  this->m_classes.m_data = 0i64;
  this->m_classes.m_size = 0;
  this->m_classes.m_capacityAndFlags = 0x80000000;
  p_m_prevStrings = &this->m_prevStrings;
  this->m_prevStrings.m_data = 0i64;
  this->m_prevStrings.m_size = 0;
  this->m_prevStrings.m_capacityAndFlags = 0x80000000;
  this->m_numPrevStringsStatic = 0;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_stringMap.m_map,
    0);
  this->m_blockStack.m_data = 0i64;
  this->m_blockStack.m_size = 0;
  this->m_blockStack.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_referenceMap.m_map,
    0);
  this->m_tmpObjects.m_data = 0i64;
  this->m_tmpObjects.m_size = 0;
  this->m_tmpObjects.m_capacityAndFlags = 0x80000000;
  if ( this->m_classes.m_size == (this->m_classes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_classes.m_data, 8);
  this->m_classes.m_data[this->m_classes.m_size++] = 0i64;
  if ( this->m_prevStrings.m_size == (this->m_prevStrings.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_prevStrings.m_data, 8);
  p_m_prevStrings->m_data[this->m_prevStrings.m_size++] = &customCaption;
  if ( this->m_prevStrings.m_size == (this->m_prevStrings.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_prevStrings.m_data, 8);
  p_m_prevStrings->m_data[this->m_prevStrings.m_size++] = 0i64;
  this->m_numPrevStringsStatic = 2;
  text.m_start = "#0000";
  text.m_end = &a0000[(int)hkString::strLen("#0000")];
  this->m_null = `anonymous namespace::Reader::_getString(this, &text);
}

// File Line: 141
// RVA: 0xE53560
void __fastcall `anonymous namespace::Reader::~Reader(Reader *this)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *p_m_referenceMap; // rbp
  Dummy *Iterator; // rdi
  ReferenceInfo *Value; // rax
  ReferenceInfo *v5; // rsi
  _QWORD **v6; // rax
  hkDataObject *m_data; // rsi
  int v8; // eax
  __int64 i; // rdi
  hkDataObjectImpl *m_impl; // rcx
  int m_capacityAndFlags; // r8d
  int v13; // r8d
  Dummy *Next; // rsi
  char *Key; // rax
  int v16; // r8d
  int v17; // r8d
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  p_m_referenceMap = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(p_m_referenceMap, &result, Iterator);
  while ( result.m_bool )
  {
    Value = (ReferenceInfo *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                               p_m_referenceMap,
                               Iterator);
    v5 = Value;
    if ( Value )
    {
      `anonymous namespace::ReferenceInfo::~ReferenceInfo(Value);
      v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, ReferenceInfo *, __int64))(*v6[11] + 16i64))(v6[11], v5, 40i64);
    }
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 p_m_referenceMap,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(p_m_referenceMap, &result, Iterator);
  }
  m_data = this->m_tmpObjects.m_data;
  v8 = this->m_tmpObjects.m_size - 1;
  for ( i = v8; i >= 0; --i )
  {
    m_impl = m_data[i].m_impl;
    if ( m_impl )
    {
      --m_impl->m_externalCount;
      if ( m_impl->m_count-- == 1 )
        m_impl->vfptr->__vecDelDtor(m_impl, 1u);
    }
  }
  m_capacityAndFlags = this->m_tmpObjects.m_capacityAndFlags;
  this->m_tmpObjects.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_tmpObjects.m_data,
      8 * m_capacityAndFlags);
  this->m_tmpObjects.m_data = 0i64;
  this->m_tmpObjects.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>((hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)p_m_referenceMap);
  v13 = this->m_blockStack.m_capacityAndFlags;
  this->m_blockStack.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_blockStack.m_data,
      8 * v13);
  this->m_blockStack.m_data = 0i64;
  this->m_blockStack.m_capacityAndFlags = 0x80000000;
  Next = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_stringMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_stringMap,
    &result,
    Next);
  while ( result.m_bool )
  {
    Key = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                    &this->m_stringMap.m_map,
                    Next);
    hkString::strFree(Key, &hkContainerHeapAllocator::s_alloc);
    Next = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_stringMap,
             Next);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_stringMap,
      &result,
      Next);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_stringMap.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_stringMap.m_map);
  v16 = this->m_prevStrings.m_capacityAndFlags;
  this->m_prevStrings.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_prevStrings.m_data,
      8 * v16);
  this->m_prevStrings.m_data = 0i64;
  this->m_prevStrings.m_capacityAndFlags = 0x80000000;
  v17 = this->m_classes.m_capacityAndFlags;
  this->m_classes.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_classes.m_data,
      8 * v17);
  this->m_classes.m_data = 0i64;
  this->m_classes.m_capacityAndFlags = 0x80000000;
  hkXmlStreamParser::~hkXmlStreamParser(&this->m_parser);
}

// File Line: 152
// RVA: 0xE55B00
hkResult *__fastcall `anonymous namespace::Reader::_parseObjectReferenceImpl<hkDataArray_Value>(
        Reader *this,
        hkResult *result,
        hkSubString *valueOut)
{
  hkXmlStreamParser::Token m_token; // eax
  hkSubString *v7; // rax
  hkSubString *Lexeme; // rax
  char *String; // rax
  ReferenceInfo *v10; // rax
  hkSubString v11; // xmm0
  hkArray<hkDataArray_Value,hkContainerHeapAllocator> *p_m_arrayRefs; // rsi
  hkSubString *v13; // rax
  hkSubString *BlockName; // rax
  hkSubString resulta; // [rsp+20h] [rbp-18h] BYREF
  hkBool v17; // [rsp+40h] [rbp+8h] BYREF

  `anonymous namespace::Reader::_skipWhiteSpace(this);
  m_token = this->m_parser.m_token;
  if ( m_token != TOKEN_BLOCK_START )
  {
    if ( m_token == TOKEN_BLOCK_START_END )
    {
      BlockName = hkXmlStreamParser::getBlockName(&this->m_parser, &resulta);
      if ( hkSubString::operator==(BlockName, &v17, "null")->m_bool )
      {
        (*(void (__fastcall **)(const char *, _QWORD, _QWORD))(*(_QWORD *)valueOut->m_start + 176i64))(
          valueOut->m_start,
          LODWORD(valueOut->m_end),
          0i64);
        result->m_enum = HK_SUCCESS;
        return result;
      }
    }
    goto LABEL_15;
  }
  v7 = hkXmlStreamParser::getBlockName(&this->m_parser, &resulta);
  if ( !hkSubString::operator==(v7, &v17, "ref")->m_bool
    || (`anonymous namespace::Reader::_pushBlock(this),
        hkXmlStreamParser::advance(&this->m_parser),
        `anonymous namespace::Reader::_skipWhiteSpace(this) != TOKEN_TEXT) )
  {
LABEL_15:
    result->m_enum = HK_FAILURE;
    return result;
  }
  Lexeme = hkXmlStreamParser::getLexeme(&this->m_parser, &resulta);
  String = `anonymous namespace::Reader::_getString(this, Lexeme);
  if ( String == this->m_null )
  {
    (*(void (__fastcall **)(const char *, _QWORD, _QWORD))(*(_QWORD *)valueOut->m_start + 176i64))(
      valueOut->m_start,
      LODWORD(valueOut->m_end),
      0i64);
  }
  else
  {
    v10 = `anonymous namespace::Reader::_requireReferenceInfo(this, String);
    v11 = *valueOut;
    p_m_arrayRefs = &v10->m_arrayRefs;
    resulta = v11;
    if ( v10->m_arrayRefs.m_size == (v10->m_arrayRefs.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_arrayRefs->m_data, 16);
      v11 = resulta;
    }
    v13 = (hkSubString *)&p_m_arrayRefs->m_data[p_m_arrayRefs->m_size];
    if ( v13 )
      *v13 = v11;
    ++p_m_arrayRefs->m_size;
  }
  hkXmlStreamParser::advance(&this->m_parser);
  `anonymous namespace::Reader::_skipWhiteSpace(this);
  `anonymous namespace::Reader::_popBlock(this, result);
  return result;
}

// File Line: 199
// RVA: 0xE53DA0
char *__fastcall `anonymous namespace::Reader::_getString(Reader *this, hkSubString *text)
{
  char *v3; // rcx
  signed int v4; // ebx
  int v6; // r9d
  const char *m_start; // rdx
  char *v8; // rbx
  Dummy *Key; // rsi
  char *v10; // rbx
  char *array; // [rsp+30h] [rbp-98h] BYREF
  int v13; // [rsp+38h] [rbp-90h]
  int v14; // [rsp+3Ch] [rbp-8Ch]
  char v15[128]; // [rsp+40h] [rbp-88h] BYREF
  hkResult result; // [rsp+D0h] [rbp+8h] BYREF

  v3 = v15;
  v4 = LODWORD(text->m_end) - LODWORD(text->m_start);
  v13 = 0;
  array = v15;
  v14 = -2147483520;
  if ( v4 + 1 > 128 )
  {
    v6 = v4 + 1;
    if ( v4 + 1 < 256 )
      v6 = 256;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v6, 1);
    v3 = array;
  }
  m_start = text->m_start;
  v13 = v4 + 1;
  hkString::strNcpy(v3, m_start, v4);
  array[v4] = 0;
  v8 = array;
  Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_stringMap,
          array);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_stringMap,
    (hkBool *)&result,
    Key);
  if ( LOBYTE(result.m_enum) )
  {
    v10 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&this->m_stringMap.m_map, Key);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(&this->m_stringMap.m_map, Key, 1ui64);
  }
  else
  {
    v10 = hkString::strDup(v8, &hkContainerHeapAllocator::s_alloc);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_stringMap.m_map, v10, 1ui64);
  }
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v14 & 0x3FFFFFFF);
  return v10;
}

// File Line: 212
// RVA: 0xE54330
hkTypeManager::Type *__fastcall `anonymous namespace::Reader::_getType(
        Reader *this,
        const char *name,
        const char *className)
{
  hkTypeManager *v5; // rbx
  char v7; // al
  const char *v8; // rcx
  int v9; // eax
  hkTypeManager::Type *v10; // rax

  v5 = (hkTypeManager *)((__int64 (__fastcall *)(hkDataWorld *))this->m_world->vfptr[5].__first_virtual_table_function__)(this->m_world);
  switch ( *name )
  {
    case b:
      if ( !(unsigned int)hkString::strCmp(name, "byte") )
        return v5->m_builtInTypes[2];
      break;
    case i:
      if ( !(unsigned int)hkString::strCmp(name, "int") )
        return v5->m_builtInTypes[4];
      break;
    case r:
      if ( !(unsigned int)hkString::strCmp(name, "real") )
        return v5->m_builtInTypes[3];
      if ( !(unsigned int)hkString::strCmp(name, "ref") )
      {
        v10 = hkTypeManager::addClass(v5, className);
        return hkTypeManager::makePointer(v5, v10);
      }
      break;
    case s:
      if ( !(unsigned int)hkString::strCmp(name, "string") )
        return v5->m_builtInTypes[5];
      if ( !(unsigned int)hkString::strCmp(name, "struct") )
        return hkTypeManager::addClass(v5, className);
      break;
    case v:
      if ( !(unsigned int)hkString::strCmp(name, "void") )
        return v5->m_builtInTypes[1];
      if ( !hkString::strNcmp(name, "vec", 3u) )
      {
        v7 = name[3];
        v8 = name + 3;
        if ( v7 )
        {
          while ( (unsigned __int8)(v7 - 48) <= 9u )
          {
            v7 = *++v8;
            if ( !v7 )
              goto LABEL_14;
          }
        }
        if ( !*v8 )
        {
LABEL_14:
          v9 = hkString::atoi(name + 3, 0);
          return hkTypeManager::makeTuple(v5, v5->m_builtInTypes[3], v9);
        }
      }
      break;
  }
  return 0i64;
}

// File Line: 283
// RVA: 0xE53CA0
void __fastcall `anonymous namespace::Reader::_pushBlock(Reader *this)
{
  hkSubString *BlockName; // rax
  const char *String; // rax
  hkArray<char const *,hkContainerHeapAllocator> *p_m_blockStack; // rbx
  const char *v5; // rdi
  hkSubString result; // [rsp+20h] [rbp-18h] BYREF

  BlockName = hkXmlStreamParser::getBlockName(&this->m_parser, &result);
  String = `anonymous namespace::Reader::_getString(this, BlockName);
  p_m_blockStack = &this->m_blockStack;
  v5 = String;
  if ( p_m_blockStack->m_size == (p_m_blockStack->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_blockStack->m_data, 8);
  p_m_blockStack->m_data[p_m_blockStack->m_size++] = v5;
}

// File Line: 289
// RVA: 0xE53D10
hkResult *__fastcall `anonymous namespace::Reader::_popBlock(Reader *this, hkResult *result)
{
  hkSubString *BlockName; // rax
  const char *String; // rdx
  hkSubString resulta; // [rsp+20h] [rbp-18h] BYREF

  `anonymous namespace::Reader::_skipWhiteSpace(this);
  BlockName = hkXmlStreamParser::getBlockName(&this->m_parser, &resulta);
  String = `anonymous namespace::Reader::_getString(this, BlockName);
  if ( this->m_blockStack.m_size > 0 && String == this->m_blockStack.m_data[this->m_blockStack.m_size - 1] )
  {
    hkXmlStreamParser::advance(&this->m_parser);
    --this->m_blockStack.m_size;
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 313
// RVA: 0xE54060
hkResult *__fastcall `anonymous namespace::Reader::_parseClassDefinition(Reader *this, hkResult *result)
{
  char *Attribute; // rdi
  char *v6; // rax
  hkDataWorld *m_world; // rcx
  hkTypeManager *v8; // r12
  hkSubString *BlockName; // rax
  char *v10; // r15
  char *v11; // rdi
  char *v12; // rax
  char *v13; // r14
  hkTypeManager::Type *Type; // rdi
  int v15; // edx
  __int64 v16; // rcx
  _QWORD *v17; // rax
  int value; // [rsp+20h] [rbp-29h] BYREF
  int tupleSize; // [rsp+24h] [rbp-25h] BYREF
  hkResult v20; // [rsp+28h] [rbp-21h] BYREF
  hkSubString v21; // [rsp+30h] [rbp-19h] BYREF
  char *v22; // [rsp+40h] [rbp-9h] BYREF
  int v23; // [rsp+48h] [rbp-1h]
  char *v24; // [rsp+50h] [rbp+7h]
  _QWORD *array; // [rsp+58h] [rbp+Fh] BYREF
  int v26; // [rsp+60h] [rbp+17h]
  int v27; // [rsp+64h] [rbp+1Bh]
  hkResult resulta; // [rsp+C0h] [rbp+77h] BYREF
  hkBool v29; // [rsp+C8h] [rbp+7Fh] BYREF

  `anonymous namespace::Reader::_pushBlock(this);
  Attribute = `anonymous namespace::Reader::_getAttribute(this, "name");
  if ( Attribute )
  {
    value = 0;
    hkXmlStreamParser::getIntAttribute(&this->m_parser, &resulta, "version", &value);
    v6 = `anonymous namespace::Reader::_getAttribute(this, "parent");
    array = 0i64;
    v23 = value;
    m_world = this->m_world;
    v26 = 0;
    v27 = 0x80000000;
    v22 = Attribute;
    v24 = v6;
    v8 = (hkTypeManager *)((__int64 (__fastcall *)(hkDataWorld *))m_world->vfptr[5].__first_virtual_table_function__)(m_world);
    hkXmlStreamParser::advance(&this->m_parser);
    while ( `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_BLOCK_START_END )
    {
      BlockName = hkXmlStreamParser::getBlockName(&this->m_parser, &v21);
      if ( !hkSubString::operator==(BlockName, (hkBool *)&resulta, "member")->m_bool )
        break;
      v10 = `anonymous namespace::Reader::_getAttribute(this, "name");
      v11 = `anonymous namespace::Reader::_getAttribute(this, "type");
      v12 = `anonymous namespace::Reader::_getAttribute(this, "class");
      v13 = v12;
      if ( !v10 )
        goto LABEL_18;
      if ( !v11 )
        goto LABEL_18;
      Type = `anonymous namespace::Reader::_getType(this, v11, v12);
      if ( !Type )
        goto LABEL_18;
      if ( `anonymous namespace::Reader::_getBoolAttribute(this, &v29, "array", 0)->m_bool )
        Type = hkTypeManager::makeArray(v8, Type);
      tupleSize = 0;
      hkXmlStreamParser::getIntAttribute(&this->m_parser, &v20, "count", &tupleSize);
      if ( tupleSize > 0 )
        Type = hkTypeManager::makeTuple(v8, Type, tupleSize);
      v15 = v26;
      if ( v26 == (v27 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 24);
        v15 = v26;
      }
      v16 = 3i64 * v15;
      v17 = array;
      v26 = v15 + 1;
      array[v16] = v10;
      v17[v16 + 1] = Type;
      v17[v16 + 2] = 0i64;
      if ( v13 )
        ((void (__fastcall *)(hkDataWorld *, char *))this->m_world->vfptr[4].__first_virtual_table_function__)(
          this->m_world,
          v13);
      hkXmlStreamParser::advance(&this->m_parser);
    }
    if ( `anonymous namespace::Reader::_popBlock(this, &resulta)->m_enum == HK_FAILURE )
    {
LABEL_18:
      result->m_enum = HK_FAILURE;
    }
    else
    {
      hkXmlStreamParser::advance(&this->m_parser);
      ((void (__fastcall *)(hkDataWorld *, char **))this->m_world->vfptr[1].__first_virtual_table_function__)(
        this->m_world,
        &v22);
      result->m_enum = HK_SUCCESS;
    }
    v26 = 0;
    if ( v27 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array,
        24 * (v27 & 0x3FFFFFFF));
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 409
// RVA: 0xE54AE0
hkResult *__fastcall `anonymous namespace::Reader::_parseInt(
        Reader *this,
        hkResult *result,
        const char *blockName,
        __int64 *valueOut)
{
  hkSubString *v8; // rax
  hkSubString *Lexeme; // rax
  hkResult v11; // [rsp+20h] [rbp-28h] BYREF
  hkSubString resulta; // [rsp+28h] [rbp-20h] BYREF
  hkBool v13; // [rsp+50h] [rbp+8h] BYREF

  if ( this->m_parser.m_token == TOKEN_BLOCK_START
    && (v8 = hkXmlStreamParser::getBlockName(&this->m_parser, &resulta),
        hkSubString::operator==(v8, &v13, blockName)->m_bool)
    && (`anonymous namespace::Reader::_pushBlock(this),
        hkXmlStreamParser::advance(&this->m_parser),
        `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_TEXT) )
  {
    Lexeme = hkXmlStreamParser::getLexeme(&this->m_parser, &resulta);
    hkXmlStreamParser::parseInt(&v11, Lexeme, valueOut);
    if ( v11.m_enum )
    {
      result->m_enum = v11.m_enum;
    }
    else
    {
      hkXmlStreamParser::advance(&this->m_parser);
      `anonymous namespace::Reader::_popBlock(this, result);
    }
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 436
// RVA: 0xE54BB0
hkResult *__fastcall `anonymous namespace::Reader::_parseReal(
        Reader *this,
        hkResult *result,
        const char *blockName,
        float *valueOut)
{
  hkSubString *v8; // rax
  hkSubString *Lexeme; // rax
  hkResult v11; // [rsp+20h] [rbp-28h] BYREF
  hkSubString resulta; // [rsp+28h] [rbp-20h] BYREF
  hkBool v13; // [rsp+50h] [rbp+8h] BYREF

  if ( this->m_parser.m_token == TOKEN_BLOCK_START
    && (v8 = hkXmlStreamParser::getBlockName(&this->m_parser, &resulta),
        hkSubString::operator==(v8, &v13, blockName)->m_bool)
    && (`anonymous namespace::Reader::_pushBlock(this),
        hkXmlStreamParser::advance(&this->m_parser),
        `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_TEXT) )
  {
    Lexeme = hkXmlStreamParser::getLexeme(&this->m_parser, &resulta);
    hkXmlStreamParser::parseReal(&v11, Lexeme, valueOut);
    if ( v11.m_enum )
    {
      result->m_enum = v11.m_enum;
    }
    else
    {
      hkXmlStreamParser::advance(&this->m_parser);
      `anonymous namespace::Reader::_popBlock(this, result);
    }
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 487
// RVA: 0xE55040
hkResult *__fastcall `anonymous namespace::Reader::_parseRealVector(
        Reader *this,
        hkResult *result,
        float *out,
        int numReal)
{
  int v8; // ebx
  hkSubString resulta; // [rsp+20h] [rbp-28h] BYREF
  hkResult v11; // [rsp+68h] [rbp+20h] BYREF

  `anonymous namespace::Reader::_pushBlock(this);
  hkXmlStreamParser::advance(&this->m_parser);
  v8 = 0;
  if ( numReal <= 0 )
  {
LABEL_5:
    `anonymous namespace::Reader::_popBlock(this, result);
  }
  else
  {
    while ( `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_TEXT )
    {
      hkXmlStreamParser::getLexeme(&this->m_parser, &resulta);
      hkXmlStreamParser::parseReal(&v11, &resulta, &out[v8]);
      if ( v11.m_enum )
      {
        result->m_enum = v11.m_enum;
        return result;
      }
      hkXmlStreamParser::advance(&this->m_parser);
      if ( ++v8 >= numReal )
        goto LABEL_5;
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 515
// RVA: 0xE550F0
hkResult *__fastcall `anonymous namespace::Reader::_parseString(Reader *this, hkResult *result, char **stringOut)
{
  hkXmlStreamParser::Token m_token; // eax
  hkXmlStreamParser::Token v7; // eax
  char *m_data; // r15
  Dummy *Key; // r12
  char *v10; // r15
  hkSubString subString; // [rsp+20h] [rbp-E0h] BYREF
  hkSubString resulta; // [rsp+30h] [rbp-D0h] BYREF
  hkStringBuf v14; // [rsp+40h] [rbp-C0h] BYREF
  hkStringBuf buf; // [rsp+D0h] [rbp-30h] BYREF
  hkResult v16; // [rsp+190h] [rbp+90h] BYREF

  *stringOut = 0i64;
  hkXmlStreamParser::getBlockName(&this->m_parser, &resulta);
  if ( hkSubString::operator==(&resulta, (hkBool *)&v16, "null")->m_bool )
  {
    hkXmlStreamParser::advance(&this->m_parser);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    if ( !hkSubString::operator==(&resulta, (hkBool *)&v16, "string")->m_bool )
      goto LABEL_4;
    m_token = this->m_parser.m_token;
    if ( m_token == TOKEN_BLOCK_START_END )
    {
      hkXmlStreamParser::advance(&this->m_parser);
      *stringOut = &customCaption;
      result->m_enum = HK_SUCCESS;
      return result;
    }
    if ( m_token == TOKEN_BLOCK_START )
    {
      `anonymous namespace::Reader::_pushBlock(this);
      v7 = hkXmlStreamParser::advance(&this->m_parser);
      if ( v7 == TOKEN_BLOCK_END )
      {
        *stringOut = &customCaption;
        `anonymous namespace::Reader::_popBlock(this, result);
      }
      else
      {
        v14.m_string.m_capacityAndFlags = -2147483520;
        v14.m_string.m_size = 1;
        v14.m_string.m_data = v14.m_string.m_storage;
        v14.m_string.m_storage[0] = 0;
        while ( (unsigned int)(v7 - 4) <= 1 )
        {
          hkXmlStreamParser::getLexeme(&this->m_parser, &subString);
          hkStringBuf::append(&v14, subString.m_start, LODWORD(subString.m_end) - LODWORD(subString.m_start));
          v7 = hkXmlStreamParser::advance(&this->m_parser);
        }
        subString.m_start = v14.m_string.m_data;
        subString.m_end = &v14.m_string.m_data[v14.m_string.m_size - 1];
        if ( hkXmlStreamParser::needsDecode((hkBool *)&v16, &subString)->m_bool )
        {
          buf.m_string.m_data = buf.m_string.m_storage;
          subString.m_start = v14.m_string.m_data;
          buf.m_string.m_capacityAndFlags = -2147483520;
          buf.m_string.m_size = 1;
          buf.m_string.m_storage[0] = 0;
          subString.m_end = &v14.m_string.m_data[v14.m_string.m_size - 1];
          hkXmlStreamParser::decodeString(&v16, &subString, &buf);
          hkStringBuf::operator=(&v14, &buf);
          buf.m_string.m_size = 0;
          if ( buf.m_string.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              buf.m_string.m_data,
              buf.m_string.m_capacityAndFlags & 0x3FFFFFFF);
        }
        m_data = v14.m_string.m_data;
        Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_stringMap,
                v14.m_string.m_data);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_stringMap,
          (hkBool *)&v16,
          Key);
        if ( LOBYTE(v16.m_enum) )
        {
          v10 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                          &this->m_stringMap.m_map,
                          Key);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
            &this->m_stringMap.m_map,
            Key,
            1ui64);
        }
        else
        {
          v10 = hkString::strDup(m_data, &hkContainerHeapAllocator::s_alloc);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_stringMap.m_map, v10, 1ui64);
        }
        *stringOut = v10;
        `anonymous namespace::Reader::_popBlock(this, result);
        v14.m_string.m_size = 0;
        if ( v14.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v14.m_string.m_data,
            v14.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
    }
    else
    {
LABEL_4:
      result->m_enum = HK_FAILURE;
    }
  }
  return result;
}

// File Line: 575
// RVA: 0xE55660
hkResult *__fastcall `anonymous namespace::Reader::_parseIntArray(
        Reader *this,
        hkResult *result,
        const char *blockName,
        hkDataArray *arr)
{
  unsigned int v8; // ebx
  int v9; // ebp
  hkXmlStreamParser::Token m_token; // ecx
  hkResultEnum m_enum; // eax
  hkResult v13; // [rsp+20h] [rbp-48h] BYREF
  __int64 valueOut; // [rsp+28h] [rbp-40h] BYREF
  __int64 v15; // [rsp+30h] [rbp-38h] BYREF
  hkSubString subString; // [rsp+38h] [rbp-30h] BYREF
  hkResult resulta; // [rsp+88h] [rbp+20h] BYREF

  v8 = 0;
  v9 = ((__int64 (__fastcall *)(hkDataArrayImpl *))arr->m_impl->vfptr[5].__vecDelDtor)(arr->m_impl);
  if ( v9 > 0 )
  {
    do
    {
      `anonymous namespace::Reader::_skipWhiteSpace(this);
      m_token = this->m_parser.m_token;
      if ( m_token == TOKEN_BLOCK_START )
      {
        `anonymous namespace::Reader::_parseInt(this, &resulta, blockName, &valueOut);
        m_enum = resulta.m_enum;
        if ( resulta.m_enum )
          goto LABEL_11;
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))arr->m_impl->vfptr[20].__vecDelDtor)(
          arr->m_impl,
          v8,
          valueOut);
      }
      else
      {
        if ( m_token != TOKEN_TEXT )
        {
          result->m_enum = HK_FAILURE;
          return result;
        }
        hkXmlStreamParser::getLexeme(&this->m_parser, &subString);
        hkXmlStreamParser::parseInt(&v13, &subString, &v15);
        m_enum = v13.m_enum;
        if ( v13.m_enum )
        {
LABEL_11:
          result->m_enum = m_enum;
          return result;
        }
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))arr->m_impl->vfptr[20].__vecDelDtor)(
          arr->m_impl,
          v8,
          v15);
        hkXmlStreamParser::advance(&this->m_parser);
      }
      ++v8;
    }
    while ( (int)v8 < v9 );
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 617
// RVA: 0xE55780
hkResult *__fastcall `anonymous namespace::Reader::_parseRealArray(
        Reader *this,
        hkResult *result,
        const char *blockName,
        hkDataArray *arr)
{
  signed int v8; // ebx
  int v9; // ebp
  hkXmlStreamParser::Token m_token; // ecx
  hkResultEnum m_enum; // eax
  hkSubString *Lexeme; // rax
  float valueOut; // [rsp+20h] [rbp-38h] BYREF
  hkResult v15; // [rsp+24h] [rbp-34h] BYREF
  float v16; // [rsp+28h] [rbp-30h] BYREF
  hkSubString v17; // [rsp+30h] [rbp-28h] BYREF
  hkResult resulta; // [rsp+78h] [rbp+20h] BYREF

  v8 = 0;
  v9 = ((__int64 (__fastcall *)(hkDataArrayImpl *))arr->m_impl->vfptr[5].__vecDelDtor)(arr->m_impl);
  if ( v9 > 0 )
  {
    do
    {
      `anonymous namespace::Reader::_skipWhiteSpace(this);
      m_token = this->m_parser.m_token;
      if ( m_token == TOKEN_BLOCK_START )
      {
        `anonymous namespace::Reader::_parseReal(this, &resulta, blockName, &valueOut);
        m_enum = resulta.m_enum;
        if ( resulta.m_enum )
          goto LABEL_11;
        arr->m_impl->vfptr[16].__vecDelDtor(arr->m_impl, v8);
      }
      else
      {
        if ( m_token != TOKEN_TEXT )
        {
          result->m_enum = HK_FAILURE;
          return result;
        }
        Lexeme = hkXmlStreamParser::getLexeme(&this->m_parser, &v17);
        hkXmlStreamParser::parseReal(&v15, Lexeme, &v16);
        m_enum = v15.m_enum;
        if ( v15.m_enum )
        {
LABEL_11:
          result->m_enum = m_enum;
          return result;
        }
        arr->m_impl->vfptr[16].__vecDelDtor(arr->m_impl, v8);
        hkXmlStreamParser::advance(&this->m_parser);
      }
      ++v8;
    }
    while ( v8 < v9 );
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 656
// RVA: 0xE54C80
hkResult *__fastcall `anonymous namespace::Reader::_parseArrayItems(
        Reader *this,
        hkResult *result,
        int numElems,
        hkDataArray *arr)
{
  __int64 v8; // rdx
  int v9; // eax
  const char *v10; // r8
  int TupleSize; // eax
  int v12; // r8d
  int v13; // r12d
  int v14; // r9d
  int v15; // ebx
  int v16; // r8d
  int v17; // ebx
  unsigned int v18; // r12d
  hkDataArrayImpl *v19; // rax
  hkDataArrayImpl *m_impl; // rdx
  hkDataObject *v21; // r8
  hkDataArrayImpl *v22; // rax
  hkDataArrayImpl *v23; // rcx
  bool v24; // zf
  int i; // ebx
  hkDataArrayImpl *v26; // rax
  hkDataArray_Value obj; // [rsp+30h] [rbp-39h] BYREF
  hkResult v29; // [rsp+40h] [rbp-29h] BYREF
  hkResult v30; // [rsp+44h] [rbp-25h] BYREF
  char *array; // [rsp+50h] [rbp-19h] BYREF
  int v32; // [rsp+58h] [rbp-11h]
  int v33; // [rsp+5Ch] [rbp-Dh]
  char v34; // [rsp+60h] [rbp-9h] BYREF
  const char *resulta; // [rsp+E8h] [rbp+7Fh] BYREF

  v8 = ((__int64 (__fastcall *)(hkDataArrayImpl *))arr->m_impl->vfptr[1].__vecDelDtor)(arr->m_impl);
  v9 = *(_DWORD *)v8;
  switch ( *(_DWORD *)v8 )
  {
    case 2:
    case 4:
      v10 = "int";
      if ( v9 == 2 )
        v10 = "byte";
      `anonymous namespace::Reader::_parseIntArray(this, result, v10, arr);
      return result;
    case 3:
      `anonymous namespace::Reader::_parseRealArray(this, result, "real", arr);
      return result;
    case 5:
      v17 = 0;
      if ( numElems <= 0 )
        goto LABEL_38;
      do
      {
        `anonymous namespace::Reader::_skipWhiteSpace(this);
        if ( `anonymous namespace::Reader::_parseString(this, &v29, &resulta)->m_enum )
          goto LABEL_45;
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const char *))arr->m_impl->vfptr[14].__vecDelDtor)(
          arr->m_impl,
          (unsigned int)v17++,
          resulta);
      }
      while ( v17 < numElems );
      `anonymous namespace::Reader::_skipWhiteSpace(this);
      result->m_enum = HK_SUCCESS;
      return result;
    case 6:
      v18 = 0;
      if ( numElems <= 0 )
        goto LABEL_38;
      while ( 1 )
      {
        `anonymous namespace::Reader::_skipWhiteSpace(this);
        v19 = (hkDataArrayImpl *)arr->m_impl->vfptr[21].__vecDelDtor(arr->m_impl, v18);
        m_impl = v19;
        obj.m_impl = v19;
        if ( v19 )
        {
          ++v19->m_externalCount;
          ++v19->m_count;
          m_impl = obj.m_impl;
        }
        if ( this->m_tmpObjects.m_size == (this->m_tmpObjects.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_tmpObjects.m_data, 8);
          m_impl = obj.m_impl;
        }
        v21 = &this->m_tmpObjects.m_data[this->m_tmpObjects.m_size];
        if ( v21 )
        {
          v21->m_impl = (hkDataObjectImpl *)m_impl;
          v22 = obj.m_impl;
          if ( obj.m_impl )
          {
            ++obj.m_impl->m_externalCount;
            ++v22->m_count;
          }
        }
        ++this->m_tmpObjects.m_size;
        `anonymous namespace::Reader::_parseObject(this, (hkResult *)&resulta, (hkDataObject *)&obj);
        v23 = obj.m_impl;
        if ( (_DWORD)resulta )
          break;
        if ( obj.m_impl )
        {
          --obj.m_impl->m_externalCount;
          v24 = v23->m_count-- == 1;
          if ( v24 )
            v23->vfptr->__vecDelDtor(v23, 1u);
        }
        if ( (int)++v18 >= numElems )
          goto LABEL_38;
      }
      result->m_enum = (int)resulta;
      if ( v23 )
      {
        --v23->m_externalCount;
        v24 = v23->m_count-- == 1;
        if ( v24 )
          v23->vfptr->__vecDelDtor(v23, 1u);
      }
      return result;
    case 7:
      for ( i = 0; i < numElems; ++i )
      {
        v26 = arr->m_impl;
        obj.m_index = i;
        obj.m_impl = v26;
        `anonymous namespace::Reader::_parseObjectReferenceImpl<hkDataArray_Value>(this, (hkResult *)&resulta, &obj);
      }
      goto LABEL_38;
    case 9:
      if ( v9 != 9 || **(_DWORD **)(v8 + 8) != 3 || ((*(_DWORD *)(v8 + 16) - 4) & 0xFFFFFFF3) != 0 )
        goto LABEL_38;
      TupleSize = hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v8);
      v12 = -2147483632;
      v32 = 0;
      v13 = TupleSize;
      v33 = -2147483632;
      array = &v34;
      if ( TupleSize > 16 )
      {
        v14 = TupleSize;
        if ( TupleSize < 32 )
          v14 = 32;
        hkArrayUtil::_reserve((hkResult *)&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v14, 4);
        v12 = v33;
      }
      v32 = v13;
      v15 = 0;
      if ( numElems <= 0 )
        goto LABEL_17;
      break;
    default:
LABEL_45:
      result->m_enum = HK_FAILURE;
      return result;
  }
  do
  {
    `anonymous namespace::Reader::_skipWhiteSpace(this);
    if ( `anonymous namespace::Reader::_parseRealVector(this, &v30, (float *)array, v13)->m_enum )
    {
      v16 = v33;
      result->m_enum = HK_FAILURE;
      v32 = 0;
      if ( v16 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v16);
      return result;
    }
    ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, char *))arr->m_impl->vfptr[12].__vecDelDtor)(
      arr->m_impl,
      (unsigned int)v15++,
      array);
  }
  while ( v15 < numElems );
  v12 = v33;
LABEL_17:
  v32 = 0;
  if ( v12 < 0 )
  {
LABEL_38:
    `anonymous namespace::Reader::_skipWhiteSpace(this);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v12);
    `anonymous namespace::Reader::_skipWhiteSpace(this);
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 753
// RVA: 0xE54550
hkResult *__fastcall `anonymous namespace::Reader::_parseMemberValue(
        Reader *this,
        hkResult *result,
        hkDataClass_MemberInfo *minfo,
        hkDataObject_Value *valueOut)
{
  hkTypeManager::Type *m_type; // r15
  hkTypeManager::SubType m_subType; // eax
  int TupleSize; // eax
  bool v11; // zf
  hkResultEnum m_enum; // eax
  int v13; // eax
  hkDataObjectImpl *v14; // rdi
  hkDataArrayImpl *v15; // rax
  hkDataArrayImpl *v16; // rbx
  hkSubString *BlockName; // rax
  int v18; // eax
  hkResultEnum v19; // eax
  hkDataArrayImpl *v20; // rcx
  hkDataArrayImpl *v21; // rax
  hkDataArrayImpl *v22; // rbx
  hkDataArrayImpl *v23; // rcx
  hkBaseObjectVtbl *vfptr; // rbx
  const char *TypeName; // rax
  hkDataClassImpl *v26; // rax
  hkDataArrayImpl *m_impl; // rcx
  hkDataArrayImpl *v28; // rcx
  int value; // [rsp+20h] [rbp-39h] BYREF
  hkDataArray arr; // [rsp+28h] [rbp-31h] BYREF
  hkDataArray v32; // [rsp+30h] [rbp-29h] BYREF
  __int64 v33; // [rsp+38h] [rbp-21h]
  hkResult v34; // [rsp+40h] [rbp-19h] BYREF
  hkSubString v35; // [rsp+48h] [rbp-11h] BYREF
  float out[16]; // [rsp+60h] [rbp+7h] BYREF
  hkResult resulta; // [rsp+D0h] [rbp+77h] BYREF

  m_type = minfo->m_type;
  m_subType = m_type->m_subType;
  if ( m_type->m_subType != SUB_TYPE_TUPLE )
  {
    if ( m_subType != SUB_TYPE_ARRAY )
    {
      switch ( m_subType )
      {
        case SUB_TYPE_BYTE:
          `anonymous namespace::Reader::_parseInt(this, &resulta, "byte", (__int64 *)&v32);
          m_enum = resulta.m_enum;
          if ( resulta.m_enum )
            goto LABEL_53;
          goto LABEL_51;
        case SUB_TYPE_REAL:
          `anonymous namespace::Reader::_parseReal(this, &resulta, "real", (float *)&value);
          m_enum = resulta.m_enum;
          if ( resulta.m_enum )
            goto LABEL_53;
          valueOut->m_impl->vfptr[20].__vecDelDtor(valueOut->m_impl, (unsigned int)valueOut->m_handle);
          result->m_enum = HK_SUCCESS;
          return result;
        case SUB_TYPE_INT:
          `anonymous namespace::Reader::_parseInt(this, &resulta, "int", (__int64 *)&v32);
          m_enum = resulta.m_enum;
          if ( resulta.m_enum )
            goto LABEL_53;
LABEL_51:
          ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataArrayImpl *))valueOut->m_impl->vfptr[16].__vecDelDtor)(
            valueOut->m_impl,
            valueOut->m_handle,
            v32.m_impl);
          result->m_enum = HK_SUCCESS;
          return result;
        case SUB_TYPE_CSTRING:
          `anonymous namespace::Reader::_parseString(this, &resulta, (const char **)&v32);
          if ( resulta.m_enum )
            goto LABEL_68;
          ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataArrayImpl *))valueOut->m_impl->vfptr[21].__vecDelDtor)(
            valueOut->m_impl,
            valueOut->m_handle,
            v32.m_impl);
          goto LABEL_67;
        case SUB_TYPE_CLASS:
          vfptr = this->m_world->vfptr;
          TypeName = hkTypeManager::Type::getTypeName(minfo->m_type);
          v26 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *, const char *))vfptr[4].__first_virtual_table_function__)(
                                     this->m_world,
                                     TypeName);
          if ( !v26 )
            goto LABEL_68;
          arr.m_impl = 0i64;
          `anonymous namespace::Reader::_parseAndCreateObject(this, &resulta, v26, (hkDataObject *)&arr);
          if ( resulta.m_enum )
          {
            m_impl = arr.m_impl;
            result->m_enum = resulta.m_enum;
            if ( m_impl )
            {
              --m_impl->m_externalCount;
              v11 = m_impl->m_count-- == 1;
              if ( v11 )
                m_impl->vfptr->__vecDelDtor(m_impl, 1u);
            }
          }
          else
          {
            ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataArrayImpl *))valueOut->m_impl->vfptr[23].__vecDelDtor)(
              valueOut->m_impl,
              valueOut->m_handle,
              arr.m_impl);
            v28 = arr.m_impl;
            if ( arr.m_impl && (--arr.m_impl->m_externalCount, v11 = v28->m_count == 1, --v28->m_count, v11) )
            {
              v28->vfptr->__vecDelDtor(v28, 1u);
              result->m_enum = HK_SUCCESS;
            }
            else
            {
LABEL_67:
              result->m_enum = HK_SUCCESS;
            }
          }
          break;
        case SUB_TYPE_POINTER:
          `anonymous namespace::Reader::_parseObjectReferenceImpl<hkDataObject_Value>(this, result, valueOut);
          return result;
        default:
          goto LABEL_68;
      }
      return result;
    }
    hkXmlStreamParser::getIntAttribute(&this->m_parser, (hkResult *)&value, "size", (int *)&resulta);
    m_enum = value;
    if ( !value )
    {
      v20 = (hkDataArrayImpl *)valueOut->m_impl;
      arr.m_impl = v20;
      if ( v20 )
      {
        ++v20->m_externalCount;
        ++v20->m_count;
        v20 = arr.m_impl;
      }
      ((void (__fastcall *)(hkDataArrayImpl *, hkSubString *, const char *))v20->vfptr[3].__vecDelDtor)(
        v20,
        &v35,
        minfo->m_name);
      v21 = (hkDataArrayImpl *)((__int64 (__fastcall *)(hkDataWorld *, hkDataArray *, const char *, hkDataClass_MemberInfo *))this->m_world->vfptr[2].__first_virtual_table_function__)(
                                 this->m_world,
                                 &arr,
                                 v35.m_end,
                                 minfo);
      v22 = v21;
      v32.m_impl = v21;
      if ( v21 )
      {
        ++v21->m_externalCount;
        ++v21->m_count;
      }
      v21->vfptr[4].__vecDelDtor(v21, resulta.m_enum);
      `anonymous namespace::Reader::_pushBlock(this);
      hkXmlStreamParser::advance(&this->m_parser);
      if ( `anonymous namespace::Reader::_parseArrayItems(this, &v34, resulta.m_enum, &v32)->m_enum )
      {
        result->m_enum = HK_FAILURE;
        --v22->m_externalCount;
        v11 = v22->m_count-- == 1;
        if ( v11 )
          v22->vfptr->__vecDelDtor(v22, 1u);
        v23 = arr.m_impl;
        if ( !arr.m_impl )
          return result;
        --arr.m_impl->m_externalCount;
        v11 = v23->m_count-- == 1;
        if ( !v11 )
          return result;
      }
      else
      {
        `anonymous namespace::Reader::_popBlock(this, result);
        --v22->m_externalCount;
        v11 = v22->m_count-- == 1;
        if ( v11 )
          v22->vfptr->__vecDelDtor(v22, 1u);
        v23 = arr.m_impl;
        if ( !arr.m_impl )
          return result;
        --arr.m_impl->m_externalCount;
        v11 = v23->m_count-- == 1;
        if ( !v11 )
          return result;
      }
      v23->vfptr->__vecDelDtor(v23, 1u);
      return result;
    }
    goto LABEL_53;
  }
  TupleSize = hkTypeManager::Type::getTupleSize(minfo->m_type);
  v11 = m_type->m_subType == SUB_TYPE_TUPLE;
  value = TupleSize;
  if ( v11 && m_type->m_parent->m_subType == SUB_TYPE_REAL && ((m_type->m_extra.m_size - 4) & 0xFFFFFFF3) == 0 )
  {
    if ( `anonymous namespace::Reader::_parseRealVector(this, &resulta, out, TupleSize)->m_enum == HK_SUCCESS )
    {
      ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, float *, _QWORD))valueOut->m_impl->vfptr[18].__vecDelDtor)(
        valueOut->m_impl,
        valueOut->m_handle,
        out,
        (unsigned int)value);
      result->m_enum = HK_SUCCESS;
      return result;
    }
LABEL_68:
    result->m_enum = HK_FAILURE;
    return result;
  }
  if ( hkXmlStreamParser::hasAttribute(&this->m_parser, (hkBool *)&resulta, "size")->m_bool )
  {
    m_enum = hkXmlStreamParser::getIntAttribute(&this->m_parser, &resulta, "size", &value)->m_enum;
    if ( m_enum == HK_SUCCESS )
    {
      v13 = hkTypeManager::Type::getTupleSize(m_type);
      if ( value != v13 )
        goto LABEL_68;
      goto LABEL_10;
    }
LABEL_53:
    result->m_enum = m_enum;
    return result;
  }
LABEL_10:
  v14 = valueOut->m_impl;
  if ( v14 )
  {
    ++v14->m_externalCount;
    ++v14->m_count;
  }
  ((void (__fastcall *)(hkDataObjectImpl *, hkDataArray *, const char *))v14->vfptr[3].__vecDelDtor)(
    v14,
    &v32,
    minfo->m_name);
  v15 = (hkDataArrayImpl *)v32.m_impl->vfptr[10].__vecDelDtor(v32.m_impl, v33);
  v16 = v15;
  arr.m_impl = v15;
  if ( v15 )
  {
    ++v15->m_externalCount;
    ++v15->m_count;
  }
  if ( this->m_parser.m_token == TOKEN_BLOCK_START
    && (BlockName = hkXmlStreamParser::getBlockName(&this->m_parser, &v35),
        hkSubString::operator==(BlockName, (hkBool *)&resulta, "tuple")->m_bool) )
  {
    `anonymous namespace::Reader::_pushBlock(this);
    hkXmlStreamParser::advance(&this->m_parser);
    v18 = hkTypeManager::Type::getTupleSize(m_type);
    v19 = `anonymous namespace::Reader::_parseArrayItems(this, &resulta, v18, &arr)->m_enum;
    if ( v19 )
    {
      result->m_enum = v19;
      if ( v16 )
      {
        --v16->m_externalCount;
        v11 = v16->m_count-- == 1;
        if ( v11 )
          v16->vfptr->__vecDelDtor(v16, 1u);
      }
      --v14->m_externalCount;
      v11 = v14->m_count-- == 1;
      if ( v11 )
LABEL_31:
        v14->vfptr->__vecDelDtor(v14, 1u);
    }
    else
    {
      `anonymous namespace::Reader::_popBlock(this, result);
      if ( v16 )
      {
        --v16->m_externalCount;
        v11 = v16->m_count-- == 1;
        if ( v11 )
          v16->vfptr->__vecDelDtor(v16, 1u);
      }
      --v14->m_externalCount;
      v11 = v14->m_count-- == 1;
      if ( v11 )
        goto LABEL_31;
    }
  }
  else
  {
    result->m_enum = HK_FAILURE;
    if ( v16 )
    {
      --v16->m_externalCount;
      v11 = v16->m_count-- == 1;
      if ( v11 )
        v16->vfptr->__vecDelDtor(v16, 1u);
    }
    --v14->m_externalCount;
    v11 = v14->m_count-- == 1;
    if ( v11 )
      goto LABEL_31;
  }
  return result;
}

// File Line: 917
// RVA: 0xE53F10
char *__fastcall `anonymous namespace::Reader::_getAttribute(Reader *this, const char *key)
{
  hkSubString valueOut; // [rsp+20h] [rbp-18h] BYREF
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  valueOut.m_start = 0i64;
  valueOut.m_end = 0i64;
  if ( hkXmlStreamParser::getValue(&this->m_parser, &result, key, &valueOut)->m_enum
    || LODWORD(valueOut.m_end) - LODWORD(valueOut.m_start) < 2
    || *valueOut.m_start != 34
    || *((_BYTE *)valueOut.m_end - 1) != 34 )
  {
    return 0i64;
  }
  --valueOut.m_end;
  ++valueOut.m_start;
  return `anonymous namespace::Reader::_getString(this, &valueOut);
}

// File Line: 936
// RVA: 0xE53FC0
hkBool *__fastcall `anonymous namespace::Reader::_getBoolAttribute(
        Reader *this,
        hkBool *result,
        const char *key,
        hkBool defaultValue)
{
  hkSubString valueOut; // [rsp+20h] [rbp-18h] BYREF
  hkResult resulta; // [rsp+40h] [rbp+8h] BYREF
  char m_bool; // [rsp+58h] [rbp+20h]

  m_bool = defaultValue.m_bool;
  valueOut.m_start = 0i64;
  valueOut.m_end = 0i64;
  if ( hkXmlStreamParser::getValue(&this->m_parser, &resulta, key, &valueOut)->m_enum )
    goto LABEL_6;
  if ( hkSubString::operator==(&valueOut, (hkBool *)&resulta, "\"true\"")->m_bool )
  {
    result->m_bool = 1;
    return result;
  }
  if ( !hkSubString::operator==(&valueOut, (hkBool *)&resulta, "\"false\"")->m_bool )
  {
LABEL_6:
    result->m_bool = m_bool;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 957
// RVA: 0xE53F90
hkXmlStreamParser::Token __fastcall `anonymous namespace::Reader::_skipWhiteSpace(Reader *this)
{
  hkXmlStreamParser::Token result; // eax

  for ( result = this->m_parser.m_token; result == TOKEN_WHITESPACE; result = hkXmlStreamParser::advance(&this->m_parser) )
    ;
  return result;
}

// File Line: 967
// RVA: 0xE55890
ReferenceInfo *__fastcall `anonymous namespace::Reader::_findReferenceInfo(Reader *this, const char *key)
{
  return (ReferenceInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap,
                            key,
                            0i64);
}

// File Line: 972
// RVA: 0xE55910
ReferenceInfo *__fastcall `anonymous namespace::Reader::_requireReferenceInfo(Reader *this, const char *key)
{
  hkStringMap<ReferenceInfo *,hkContainerHeapAllocator> *p_m_referenceMap; // rsi
  ReferenceInfo *result; // rax
  _QWORD **Value; // rax
  unsigned __int64 v6; // rbx

  p_m_referenceMap = &this->m_referenceMap;
  result = (ReferenceInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap,
                              key,
                              0i64);
  if ( !result )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *(_QWORD *)(v6 + 8) = 0i64;
      *(_DWORD *)(v6 + 16) = 0;
      *(_DWORD *)(v6 + 20) = 0x80000000;
      *(_QWORD *)(v6 + 24) = 0i64;
      *(_DWORD *)(v6 + 32) = 0;
      *(_DWORD *)(v6 + 36) = 0x80000000;
    }
    else
    {
      v6 = 0i64;
    }
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&p_m_referenceMap->m_map, key, v6);
    return (ReferenceInfo *)v6;
  }
  return result;
}

// File Line: 985
// RVA: 0xE558B0
hkResult *__fastcall `anonymous namespace::Reader::_setReferencedObject(
        Reader *this,
        hkResult *result,
        const char *id,
        hkDataObject *obj)
{
  ReferenceInfo *v6; // rcx
  hkDataObjectImpl *m_impl; // rax

  v6 = `anonymous namespace::Reader::_requireReferenceInfo(this, id);
  if ( v6->m_object )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    m_impl = obj->m_impl;
    result->m_enum = HK_SUCCESS;
    v6->m_object = m_impl;
  }
  return result;
}

// File Line: 998
// RVA: 0xE553E0
hkResult *__fastcall `anonymous namespace::Reader::_parseAndCreateObject(
        Reader *this,
        hkResult *result,
        hkDataClassImpl *klassImpl,
        hkDataObject *objOut)
{
  hkDataClassImpl *v5; // rbx
  char *v8; // rdx
  char *Attribute; // rax
  hkDataWorld *m_world; // rcx
  const char *v12; // rbp
  hkDataObjectImpl *v13; // rax
  hkDataObjectImpl *v14; // rbx
  hkResultEnum m_enum; // eax
  hkDataObjectImpl *m_impl; // rcx
  bool v17; // zf
  hkDataObject obj; // [rsp+20h] [rbp-28h] BYREF
  hkDataClassImpl *v19; // [rsp+28h] [rbp-20h] BYREF
  hkResult resulta; // [rsp+60h] [rbp+18h] BYREF

  v5 = klassImpl;
  if ( klassImpl
    || (v8 = `anonymous namespace::Reader::_getAttribute(this, "type")) != 0i64
    && (v5 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *, char *))this->m_world->vfptr[4].__first_virtual_table_function__)(
                                  this->m_world,
                                  v8)) != 0i64 )
  {
    Attribute = `anonymous namespace::Reader::_getAttribute(this, "id");
    m_world = this->m_world;
    v19 = v5;
    v12 = Attribute;
    v13 = (hkDataObjectImpl *)((__int64 (__fastcall *)(hkDataWorld *, hkDataClassImpl **, _QWORD))m_world->vfptr[2].__vecDelDtor)(
                                m_world,
                                &v19,
                                0i64);
    v14 = v13;
    obj.m_impl = v13;
    if ( v13 )
    {
      ++v13->m_externalCount;
      ++v13->m_count;
    }
    `anonymous namespace::Reader::_parseObject(this, &resulta, &obj);
    if ( resulta.m_enum )
    {
      result->m_enum = resulta.m_enum;
    }
    else if ( v12
           && (m_enum = `anonymous namespace::Reader::_setReferencedObject(this, &resulta, v12, &obj)->m_enum) != HK_SUCCESS )
    {
      result->m_enum = m_enum;
    }
    else
    {
      if ( v14 )
      {
        ++v14->m_externalCount;
        ++v14->m_count;
      }
      m_impl = objOut->m_impl;
      if ( objOut->m_impl )
      {
        --m_impl->m_externalCount;
        v17 = m_impl->m_count-- == 1;
        if ( v17 )
          m_impl->vfptr->__vecDelDtor(m_impl, 1u);
      }
      objOut->m_impl = v14;
      result->m_enum = HK_SUCCESS;
    }
    if ( v14 )
    {
      --v14->m_externalCount;
      v17 = v14->m_count-- == 1;
      if ( v17 )
        v14->vfptr->__vecDelDtor(v14, 1u);
    }
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 1043
// RVA: 0xE55530
hkResult *__fastcall `anonymous namespace::Reader::_parseObject(Reader *this, hkResult *result, hkDataObject *obj)
{
  __int64 v6; // rbx
  char *Attribute; // rax
  int v8; // eax
  __int64 v9; // r9
  hkDataObject_Value valueOut; // [rsp+20h] [rbp-48h] BYREF
  hkDataClass_MemberInfo minfo; // [rsp+30h] [rbp-38h] BYREF
  hkResult resulta; // [rsp+70h] [rbp+8h] BYREF

  `anonymous namespace::Reader::_pushBlock(this);
  v6 = ((__int64 (__fastcall *)(hkDataObjectImpl *))obj->m_impl->vfptr[2].__vecDelDtor)(obj->m_impl);
  hkXmlStreamParser::advance(&this->m_parser);
  while ( `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_BLOCK_START )
  {
    Attribute = `anonymous namespace::Reader::_getAttribute(this, "name");
    if ( !Attribute )
      goto LABEL_10;
    v8 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 88i64))(v6, Attribute);
    if ( v8 < 0 )
      goto LABEL_10;
    v9 = *(_QWORD *)v6;
    memset(&minfo, 0, sizeof(minfo));
    (*(void (__fastcall **)(__int64, _QWORD, hkDataClass_MemberInfo *))(v9 + 80))(v6, (unsigned int)v8, &minfo);
    ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))obj->m_impl->vfptr[3].__vecDelDtor)(
      obj->m_impl,
      &valueOut,
      minfo.m_name);
    `anonymous namespace::Reader::_parseMemberValue(this, &resulta, &minfo, &valueOut);
    if ( resulta.m_enum )
    {
      result->m_enum = resulta.m_enum;
      return result;
    }
  }
  if ( `anonymous namespace::Reader::_popBlock(this, &resulta)->m_enum )
  {
LABEL_10:
    result->m_enum = HK_FAILURE;
    return result;
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 1096
// RVA: 0xE559B0
hkResult *__fastcall `anonymous namespace::Reader::_fixUpReferences(Reader *this, hkResult *result)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *p_m_referenceMap; // r15
  Dummy *Iterator; // rbp
  unsigned __int64 Value; // rax
  unsigned __int64 v6; // rdi
  int v7; // esi
  __int64 v8; // r14
  __int64 v9; // rbx
  int v11; // ebx
  __int64 v12; // rsi
  hkBool resulta; // [rsp+50h] [rbp+8h] BYREF

  p_m_referenceMap = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(p_m_referenceMap, &resulta, Iterator);
  if ( resulta.m_bool )
  {
    while ( 1 )
    {
      Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(p_m_referenceMap, Iterator);
      v6 = Value;
      if ( !*(_QWORD *)Value )
        break;
      v7 = 0;
      if ( *(int *)(Value + 16) > 0 )
      {
        v8 = 0i64;
        do
        {
          v9 = *(_QWORD *)v6;
          if ( *(_QWORD *)v6 )
          {
            ++*(_WORD *)(v9 + 10);
            ++*(_DWORD *)(v9 + 12);
          }
          (*(void (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)(v8 + *(_QWORD *)(v6 + 8)) + 176i64))(
            *(_QWORD *)(v8 + *(_QWORD *)(v6 + 8)),
            *(unsigned int *)(v8 + *(_QWORD *)(v6 + 8) + 8),
            v9);
          if ( v9 )
          {
            --*(_WORD *)(v9 + 10);
            if ( (*(_DWORD *)(v9 + 12))-- == 1 )
              (**(void (__fastcall ***)(__int64, __int64))v9)(v9, 1i64);
          }
          ++v7;
          v8 += 16i64;
        }
        while ( v7 < *(_DWORD *)(v6 + 16) );
      }
      v11 = 0;
      if ( *(int *)(v6 + 32) > 0 )
      {
        v12 = 0i64;
        do
        {
          (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(v12 + *(_QWORD *)(v6 + 24)) + 184i64))(
            *(_QWORD *)(v12 + *(_QWORD *)(v6 + 24)),
            *(_QWORD *)(v12 + *(_QWORD *)(v6 + 24) + 8),
            *(_QWORD *)v6);
          ++v11;
          v12 += 16i64;
        }
        while ( v11 < *(_DWORD *)(v6 + 32) );
      }
      Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                   p_m_referenceMap,
                   Iterator);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(p_m_referenceMap, &resulta, Iterator);
      if ( !resulta.m_bool )
        goto LABEL_15;
    }
    result->m_enum = HK_FAILURE;
  }
  else
  {
LABEL_15:
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 1117
// RVA: 0xE53B30
hkResult *__fastcall `anonymous namespace::Reader::readHeader(
        Reader *this,
        hkResult *result,
        hkXmlTagfile::Header *out)
{
  hkSubString *BlockName; // rax
  hkOstream *v7; // rax
  hkErrStream resulta; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF
  hkResult v11; // [rsp+250h] [rbp+8h] BYREF

  hkXmlStreamParser::advance(&this->m_parser);
  if ( `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_QBLOCK )
    hkXmlStreamParser::advance(&this->m_parser);
  if ( `anonymous namespace::Reader::_skipWhiteSpace(this) != TOKEN_BLOCK_START )
    goto LABEL_11;
  BlockName = hkXmlStreamParser::getBlockName(&this->m_parser, (hkSubString *)&resulta);
  if ( !hkSubString::operator==(BlockName, (hkBool *)&v11, "hktagfile")->m_bool
    || hkXmlStreamParser::getIntAttribute(&this->m_parser, &v11, "version", &out->m_version)->m_enum == HK_FAILURE )
  {
    goto LABEL_11;
  }
  if ( (unsigned int)(out->m_version - 1) > 1 )
  {
    hkErrStream::hkErrStream(&resulta, buf, 512);
    v7 = hkOstream::operator<<(&resulta, "Unrecognised tagfile version ");
    hkOstream::operator<<(v7, out->m_version);
    hkError::messageWarning(0x23C6037Fu, buf, "Tagfile\\Xml\\hkXmlTagfileReader.cpp", 1162);
    hkOstream::~hkOstream(&resulta);
LABEL_11:
    result->m_enum = HK_FAILURE;
    return result;
  }
  resulta.vfptr = 0i64;
  *(_QWORD *)&resulta.m_memSizeAndFlags = 0i64;
  if ( hkXmlStreamParser::getValue(&this->m_parser, &v11, "sdkversion", (hkSubString *)&resulta)->m_enum == HK_SUCCESS )
    hkStringPtr::set(
      &out->m_sdkVersion,
      (const char *)&resulta.vfptr->__vecDelDtor + 1,
      *(_DWORD *)&resulta.m_memSizeAndFlags - LODWORD(resulta.vfptr) - 2);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 1171
// RVA: 0xE53800
hkResult *__fastcall `anonymous namespace::Reader::parseRoot(Reader *this, hkResult *result, hkDataObject *objOut)
{
  int v6; // r9d
  hkSubString *BlockName; // rax
  hkSubString *v9; // rax
  hkDataObjectImpl *v10; // rbx
  const char *v11; // rdi
  bool v12; // zf
  const char *m_start; // rcx
  hkDataObjectImpl *m_impl; // rcx
  hkSubString resulta; // [rsp+20h] [rbp-E0h] BYREF
  hkErrStream v16; // [rsp+30h] [rbp-D0h] BYREF
  char buf[512]; // [rsp+50h] [rbp-B0h] BYREF
  hkResult v18; // [rsp+280h] [rbp+180h] BYREF
  int value; // [rsp+298h] [rbp+198h] BYREF

  hkXmlStreamParser::advance(&this->m_parser);
  if ( `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_QBLOCK )
    hkXmlStreamParser::advance(&this->m_parser);
  if ( `anonymous namespace::Reader::_skipWhiteSpace(this) != TOKEN_BLOCK_START )
  {
    hkErrStream::hkErrStream(&v16, buf, 512);
    hkOstream::operator<<(&v16, "Didnt find the root hktagfile block");
    v6 = 1187;
LABEL_5:
    hkError::messageWarning(0xFEED00AA, buf, "Tagfile\\Xml\\hkXmlTagfileReader.cpp", v6);
    hkOstream::~hkOstream(&v16);
    result->m_enum = HK_FAILURE;
    return result;
  }
  BlockName = hkXmlStreamParser::getBlockName(&this->m_parser, &resulta);
  if ( !hkSubString::operator==(BlockName, (hkBool *)&v18, "hktagfile")->m_bool )
  {
    hkErrStream::hkErrStream(&v16, buf, 512);
    hkOstream::operator<<(&v16, "Expecting hktagfile block");
    v6 = 1193;
    goto LABEL_5;
  }
  value = 0;
  hkXmlStreamParser::getIntAttribute(&this->m_parser, &v18, "version", &value);
  `anonymous namespace::Reader::_pushBlock(this);
  hkXmlStreamParser::advance(&this->m_parser);
  while ( `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_BLOCK_START )
  {
    v9 = hkXmlStreamParser::getBlockName(&this->m_parser, (hkSubString *)&v16);
    if ( !hkSubString::operator==(v9, (hkBool *)&v18, "class")->m_bool )
      break;
    `anonymous namespace::Reader::_parseClassDefinition(this, (hkResult *)&resulta);
  }
  v10 = 0i64;
  while ( (unsigned int)(`anonymous namespace::Reader::_skipWhiteSpace(this) - 1) <= 1 )
  {
    resulta.m_start = 0i64;
    `anonymous namespace::Reader::_parseAndCreateObject(this, &v18, 0i64, (hkDataObject *)&resulta);
    if ( v18.m_enum == HK_FAILURE )
    {
      m_start = resulta.m_start;
      result->m_enum = HK_FAILURE;
      if ( m_start )
      {
        --*((_WORD *)m_start + 5);
        v12 = (*((_DWORD *)m_start + 3))-- == 1;
        if ( v12 )
          (**(void (__fastcall ***)(const char *, __int64))m_start)(m_start, 1i64);
      }
      goto LABEL_37;
    }
    v11 = resulta.m_start;
    if ( resulta.m_start )
    {
      ++*((_WORD *)resulta.m_start + 5);
      ++*((_DWORD *)v11 + 3);
    }
    if ( v10 )
    {
      --v10->m_externalCount;
      v12 = v10->m_count-- == 1;
      if ( v12 )
        v10->vfptr->__vecDelDtor(v10, 1u);
    }
    v10 = (hkDataObjectImpl *)v11;
    if ( v11 )
    {
      --*((_WORD *)v11 + 5);
      v12 = (*((_DWORD *)v11 + 3))-- == 1;
      if ( v12 )
        (**(void (__fastcall ***)(const char *, __int64))v11)(v11, 1i64);
    }
  }
  if ( `anonymous namespace::Reader::_popBlock(this, &v18)->m_enum )
  {
    result->m_enum = HK_FAILURE;
  }
  else if ( `anonymous namespace::Reader::_skipWhiteSpace(this) == TOKEN_EOF )
  {
    `anonymous namespace::Reader::_fixUpReferences(this, &v18);
    if ( v18.m_enum )
    {
      result->m_enum = v18.m_enum;
    }
    else
    {
      if ( v10 )
      {
        ++v10->m_externalCount;
        ++v10->m_count;
      }
      m_impl = objOut->m_impl;
      if ( objOut->m_impl )
      {
        --m_impl->m_externalCount;
        v12 = m_impl->m_count-- == 1;
        if ( v12 )
          m_impl->vfptr->__vecDelDtor(m_impl, 1u);
      }
      objOut->m_impl = v10;
      result->m_enum = HK_SUCCESS;
    }
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
LABEL_37:
  if ( v10 )
  {
    --v10->m_externalCount;
    v12 = v10->m_count-- == 1;
    if ( v12 )
      v10->vfptr->__vecDelDtor(v10, 1u);
  }
  return result;
}m_externalCount;
    v12 = v10->m_count-- 

// File Line: 1273
// RVA: 0xE532C0
hkDataObject *__fastcall hkXmlTagfileReader::load(
        hkXmlTagfileReader *this,
        hkDataObject *result,
        hkStreamReader *stream,
        hkDataWorld *world)
{
  hkDataObjectImpl *m_impl; // rcx
  bool v6; // zf
  int m_count; // eax
  hkDataObject objOut; // [rsp+20h] [rbp-158h] BYREF
  hkResult resulta; // [rsp+28h] [rbp-150h] BYREF
  Reader v11; // [rsp+30h] [rbp-148h] BYREF

  `anonymous namespace::Reader::Reader(&v11, stream, world);
  objOut.m_impl = 0i64;
  `anonymous namespace::Reader::parseRoot(&v11, &resulta, &objOut);
  m_impl = objOut.m_impl;
  if ( resulta.m_enum )
  {
    result->m_impl = 0i64;
    if ( !m_impl )
      goto LABEL_8;
    --m_impl->m_externalCount;
    v6 = m_impl->m_count-- == 1;
  }
  else
  {
    result->m_impl = objOut.m_impl;
    if ( !m_impl )
      goto LABEL_8;
    m_count = m_impl->m_count;
    m_impl->m_count = m_count;
    v6 = m_count == 0;
  }
  if ( v6 )
    m_impl->vfptr->__vecDelDtor(m_impl, 1u);
LABEL_8:
  `anonymous namespace::Reader::~Reader(&v11);
  return result;
}

// File Line: 1287
// RVA: 0xE53360
hkResult *__fastcall hkXmlTagfileReader::readHeader(
        hkXmlTagfileReader *this,
        hkResult *result,
        hkStreamReader *stream,
        hkXmlTagfile::Header *out)
{
  Reader v7; // [rsp+20h] [rbp-148h] BYREF

  `anonymous namespace::Reader::Reader(&v7, stream, 0i64);
  `anonymous namespace::Reader::readHeader(&v7, result, out);
  `anonymous namespace::Reader::~Reader(&v7);
  return result;
}

