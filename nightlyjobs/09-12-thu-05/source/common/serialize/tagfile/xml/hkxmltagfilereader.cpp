// File Line: 130
// RVA: 0xE533C0
void __fastcall `anonymous namespace'::Reader::Reader(Reader *this, hkStreamReader *sr, hkDataWorld *cont)
{
  hkDataWorld *v3; // rbx
  Reader *v4; // rsi
  signed __int64 v5; // rdi
  signed __int64 v6; // rbx
  hkSubString text; // [rsp+20h] [rbp-18h]

  v3 = cont;
  v4 = this;
  hkXmlStreamParser::hkXmlStreamParser(&this->m_parser, sr);
  v4->m_world = v3;
  v5 = (signed __int64)&v4->m_classes;
  *(_QWORD *)v5 = 0i64;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 2147483648;
  v6 = (signed __int64)&v4->m_prevStrings;
  *(_QWORD *)v6 = 0i64;
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(v6 + 12) = 2147483648;
  v4->m_numPrevStringsStatic = 0;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v4->m_stringMap.m_map,
    0);
  v4->m_blockStack.m_data = 0i64;
  v4->m_blockStack.m_size = 0;
  v4->m_blockStack.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v4->m_referenceMap.m_map,
    0);
  v4->m_tmpObjects.m_data = 0i64;
  v4->m_tmpObjects.m_size = 0;
  v4->m_tmpObjects.m_capacityAndFlags = 2147483648;
  if ( v4->m_classes.m_size == (v4->m_classes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_classes, 8);
  *(_QWORD *)(*(_QWORD *)v5 + 8i64 * v4->m_classes.m_size++) = 0i64;
  if ( v4->m_prevStrings.m_size == (v4->m_prevStrings.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_prevStrings, 8);
  *(_QWORD *)(*(_QWORD *)v6 + 8i64 * v4->m_prevStrings.m_size++) = &customWorldMapCaption;
  if ( v4->m_prevStrings.m_size == (v4->m_prevStrings.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_prevStrings, 8);
  *(_QWORD *)(*(_QWORD *)v6 + 8i64 * v4->m_prevStrings.m_size++) = 0i64;
  v4->m_numPrevStringsStatic = 2;
  text.m_start = "#0000";
  text.m_end = &a0000[(signed int)hkString::strLen("#0000")];
  v4->m_null = `anonymous namespace'::Reader::_getString(v4, &text);
}

// File Line: 141
// RVA: 0xE53560
void __fastcall `anonymous namespace'::Reader::~Reader(Reader *this)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v1; // rbp
  Reader *v2; // rbx
  Dummy *v3; // rdi
  ReferenceInfo *v4; // rax
  ReferenceInfo *v5; // rsi
  _QWORD **v6; // rax
  hkDataObject *v7; // rsi
  int v8; // eax
  __int64 i; // rdi
  hkDataObjectImpl *v10; // rcx
  bool v11; // zf
  int v12; // er8
  int v13; // er8
  Dummy *v14; // rsi
  char *v15; // rax
  int v16; // er8
  int v17; // er8
  hkBool result; // [rsp+40h] [rbp+8h]

  v1 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap;
  v2 = this;
  v3 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v1, &result, v3);
  while ( result.m_bool )
  {
    v4 = (ReferenceInfo *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(v1, v3);
    v5 = v4;
    if ( v4 )
    {
      `anonymous namespace'::ReferenceInfo::~ReferenceInfo(v4);
      v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, ReferenceInfo *, signed __int64))(*v6[11] + 16i64))(v6[11], v5, 40i64);
    }
    v3 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(v1, v3);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v1, &result, v3);
  }
  v7 = v2->m_tmpObjects.m_data;
  v8 = v2->m_tmpObjects.m_size - 1;
  for ( i = v8; i >= 0; --i )
  {
    v10 = v7[i].m_impl;
    if ( v10 )
    {
      --v10->m_externalCount;
      v11 = v10->m_count-- == 1;
      if ( v11 )
        v10->vfptr->__vecDelDtor((hkDataRefCounted *)&v10->vfptr, 1u);
    }
  }
  v12 = v2->m_tmpObjects.m_capacityAndFlags;
  v2->m_tmpObjects.m_size = 0;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_tmpObjects.m_data,
      8 * v12);
  v2->m_tmpObjects.m_data = 0i64;
  v2->m_tmpObjects.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>((hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v1);
  v13 = v2->m_blockStack.m_capacityAndFlags;
  v2->m_blockStack.m_size = 0;
  if ( v13 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_blockStack.m_data,
      8 * v13);
  v2->m_blockStack.m_data = 0i64;
  v2->m_blockStack.m_capacityAndFlags = 2147483648;
  v14 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_stringMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_stringMap,
    &result,
    v14);
  while ( result.m_bool )
  {
    v15 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&v2->m_stringMap.m_map, v14);
    hkString::strFree(v15, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    v14 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_stringMap,
            v14);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_stringMap,
      &result,
      v14);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&v2->m_stringMap.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v2->m_stringMap.m_map);
  v16 = v2->m_prevStrings.m_capacityAndFlags;
  v2->m_prevStrings.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_prevStrings.m_data,
      8 * v16);
  v2->m_prevStrings.m_data = 0i64;
  v2->m_prevStrings.m_capacityAndFlags = 2147483648;
  v17 = v2->m_classes.m_capacityAndFlags;
  v2->m_classes.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_classes.m_data,
      8 * v17);
  v2->m_classes.m_data = 0i64;
  v2->m_classes.m_capacityAndFlags = 2147483648;
  hkXmlStreamParser::~hkXmlStreamParser(&v2->m_parser);
}

// File Line: 152
// RVA: 0xE55B00
hkResult *__fastcall `anonymous namespace'::Reader::_parseObjectReferenceImpl<hkDataArray_Value>(Reader *this, hkResult *result, hkDataArray_Value *valueOut)
{
  hkDataArray_Value *v3; // rsi
  hkResult *v4; // rdi
  Reader *v5; // rbx
  hkXmlStreamParser::Token v6; // eax
  hkSubString *v7; // rax
  hkSubString *v8; // rax
  char *v9; // rax
  ReferenceInfo *v10; // rax
  hkSubString v11; // xmm0
  signed int *v12; // rsi
  hkSubString *v13; // rax
  hkSubString *v15; // rax
  hkSubString resulta; // [rsp+20h] [rbp-18h]
  hkBool v17; // [rsp+40h] [rbp+8h]

  v3 = valueOut;
  v4 = result;
  v5 = this;
  `anonymous namespace'::Reader::_skipWhiteSpace(this);
  v6 = v5->m_parser.m_token;
  if ( v6 != 1 )
  {
    if ( v6 == 2 )
    {
      v15 = hkXmlStreamParser::getBlockName(&v5->m_parser, &resulta);
      if ( hkSubString::operator==(v15, &v17, "null")->m_bool )
      {
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v3->m_impl->vfptr[22].__vecDelDtor)(
          v3->m_impl,
          (unsigned int)v3->m_index,
          0i64);
        v4->m_enum = 0;
        return v4;
      }
    }
    goto LABEL_15;
  }
  v7 = hkXmlStreamParser::getBlockName(&v5->m_parser, &resulta);
  if ( !hkSubString::operator==(v7, &v17, "ref")->m_bool
    || (`anonymous namespace'::Reader::_pushBlock(v5),
        hkXmlStreamParser::advance(&v5->m_parser),
        `anonymous namespace'::Reader::_skipWhiteSpace(v5) != 4) )
  {
LABEL_15:
    v4->m_enum = 1;
    return v4;
  }
  v8 = hkXmlStreamParser::getLexeme(&v5->m_parser, &resulta);
  v9 = `anonymous namespace'::Reader::_getString(v5, v8);
  if ( v9 == v5->m_null )
  {
    ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v3->m_impl->vfptr[22].__vecDelDtor)(
      v3->m_impl,
      (unsigned int)v3->m_index,
      0i64);
  }
  else
  {
    v10 = `anonymous namespace'::Reader::_requireReferenceInfo(v5, v9);
    v11 = (hkSubString)*v3;
    v12 = (signed int *)&v10->m_arrayRefs;
    resulta = v11;
    if ( v10->m_arrayRefs.m_size == (v10->m_arrayRefs.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, 16);
      v11 = resulta;
    }
    v13 = (hkSubString *)(*(_QWORD *)v12 + 16i64 * v12[2]);
    if ( v13 )
      *v13 = v11;
    ++v12[2];
  }
  hkXmlStreamParser::advance(&v5->m_parser);
  `anonymous namespace'::Reader::_skipWhiteSpace(v5);
  `anonymous namespace'::Reader::_popBlock(v5, v4);
  return v4;
}

// File Line: 199
// RVA: 0xE53DA0
char *__fastcall `anonymous namespace'::Reader::_getString(Reader *this, hkSubString *text)
{
  Reader *v2; // rbp
  char *v3; // rcx
  int v4; // ebx
  hkSubString *v5; // rsi
  int v6; // er9
  const char *v7; // rdx
  const char *v8; // rbx
  Dummy *v9; // rsi
  char *v10; // rbx
  char *array; // [rsp+30h] [rbp-98h]
  int v13; // [rsp+38h] [rbp-90h]
  int v14; // [rsp+3Ch] [rbp-8Ch]
  char v15; // [rsp+40h] [rbp-88h]
  hkBool result; // [rsp+D0h] [rbp+8h]

  v2 = this;
  v3 = &v15;
  v4 = LODWORD(text->m_end) - LODWORD(text->m_start);
  v5 = text;
  v13 = 0;
  array = &v15;
  v14 = -2147483520;
  if ( v4 + 1 > 128 )
  {
    v6 = v4 + 1;
    if ( v4 + 1 < 256 )
      v6 = 256;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v6,
      1);
    v3 = array;
  }
  v7 = v5->m_start;
  v13 = v4 + 1;
  hkString::strNcpy(v3, v7, v4);
  array[v4] = 0;
  v8 = array;
  v9 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_stringMap,
         (unsigned __int64)array);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_stringMap,
    &result,
    v9);
  if ( result.m_bool )
  {
    v10 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&v2->m_stringMap.m_map, v9);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(&v2->m_stringMap.m_map, v9, 1ui64);
  }
  else
  {
    v10 = hkString::strDup(v8, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &v2->m_stringMap.m_map,
      (unsigned __int64)v10,
      1ui64);
  }
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v14 & 0x3FFFFFFF);
  return v10;
}

// File Line: 212
// RVA: 0xE54330
hkTypeManager::Type *__fastcall `anonymous namespace'::Reader::_getType(Reader *this, const char *name, const char *className)
{
  const char *v3; // rsi
  const char *v4; // rdi
  hkTypeManager *v5; // rbx
  char v7; // al
  _BYTE *v8; // rcx
  int v9; // eax
  hkTypeManager::Type *v10; // rax

  v3 = className;
  v4 = name;
  v5 = (hkTypeManager *)((__int64 (*)(void))this->m_world->vfptr[5].__first_virtual_table_function__)();
  switch ( *v4 )
  {
    case 98:
      if ( !(unsigned int)hkString::strCmp(v4, "byte") )
        return v5->m_builtInTypes[2];
      break;
    case 105:
      if ( !(unsigned int)hkString::strCmp(v4, "int") )
        return v5->m_builtInTypes[4];
      break;
    case 114:
      if ( !(unsigned int)hkString::strCmp(v4, "real") )
        return v5->m_builtInTypes[3];
      if ( !(unsigned int)hkString::strCmp(v4, "ref") )
      {
        v10 = hkTypeManager::addClass(v5, v3);
        return hkTypeManager::makePointer(v5, v10);
      }
      break;
    case 115:
      if ( !(unsigned int)hkString::strCmp(v4, "string") )
        return v5->m_builtInTypes[5];
      if ( !(unsigned int)hkString::strCmp(v4, "struct") )
        return hkTypeManager::addClass(v5, v3);
      break;
    case 118:
      if ( !(unsigned int)hkString::strCmp(v4, "void") )
        return v5->m_builtInTypes[1];
      if ( !hkString::strNcmp(v4, "vec", 3) )
      {
        v7 = v4[3];
        v8 = v4 + 3;
        if ( v7 )
        {
          while ( (unsigned __int8)(v7 - 48) <= 9u )
          {
            v7 = (v8++)[1];
            if ( !v7 )
              goto LABEL_14;
          }
        }
        if ( !*v8 )
        {
LABEL_14:
          v9 = hkString::atoi(v4 + 3, 0);
          return hkTypeManager::makeTuple(v5, v5->m_builtInTypes[3], v9);
        }
      }
      break;
  }
  return 0i64;
}

// File Line: 283
// RVA: 0xE53CA0
void __fastcall `anonymous namespace'::Reader::_pushBlock(Reader *this)
{
  Reader *v1; // rbx
  hkSubString *v2; // rax
  const char *v3; // rax
  hkArray<char const *,hkContainerHeapAllocator> *v4; // rbx
  const char *v5; // rdi
  hkSubString result; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = hkXmlStreamParser::getBlockName(&this->m_parser, &result);
  v3 = `anonymous namespace'::Reader::_getString(v1, v2);
  v4 = &v1->m_blockStack;
  v5 = v3;
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
  v4->m_data[v4->m_size++] = v5;
}

// File Line: 289
// RVA: 0xE53D10
hkResult *__fastcall `anonymous namespace'::Reader::_popBlock(Reader *this, hkResult *result)
{
  hkResult *v2; // rbx
  Reader *v3; // rdi
  hkSubString *v4; // rax
  const char *v5; // rdx
  hkResult *v6; // rax
  hkSubString resulta; // [rsp+20h] [rbp-18h]

  v2 = result;
  v3 = this;
  `anonymous namespace'::Reader::_skipWhiteSpace(this);
  v4 = hkXmlStreamParser::getBlockName(&v3->m_parser, &resulta);
  v5 = `anonymous namespace'::Reader::_getString(v3, v4);
  if ( v3->m_blockStack.m_size <= 0 || v5 != v3->m_blockStack.m_data[v3->m_blockStack.m_size - 1] )
  {
    v2->m_enum = 1;
    v6 = v2;
  }
  else
  {
    hkXmlStreamParser::advance(&v3->m_parser);
    --v3->m_blockStack.m_size;
    v2->m_enum = 0;
    v6 = v2;
  }
  return v6;
}

// File Line: 313
// RVA: 0xE54060
hkResult *__fastcall `anonymous namespace'::Reader::_parseClassDefinition(Reader *this, hkResult *result)
{
  hkResult *v2; // rsi
  Reader *v3; // rbx
  char *v4; // rdi
  hkResult *v5; // rax
  char *v6; // rax
  hkDataWorld *v7; // rcx
  hkTypeManager *v8; // r12
  hkSubString *v9; // rax
  char *v10; // r15
  char *v11; // rdi
  char *v12; // rax
  char *v13; // r14
  hkTypeManager::Type *v14; // rdi
  int v15; // edx
  signed __int64 v16; // rcx
  _QWORD *v17; // rax
  int value; // [rsp+20h] [rbp-29h]
  int tupleSize; // [rsp+24h] [rbp-25h]
  hkResult v20; // [rsp+28h] [rbp-21h]
  hkSubString v21; // [rsp+30h] [rbp-19h]
  char *v22; // [rsp+40h] [rbp-9h]
  int v23; // [rsp+48h] [rbp-1h]
  char *v24; // [rsp+50h] [rbp+7h]
  _QWORD *array; // [rsp+58h] [rbp+Fh]
  int v26; // [rsp+60h] [rbp+17h]
  int v27; // [rsp+64h] [rbp+1Bh]
  hkResult resulta; // [rsp+C0h] [rbp+77h]
  hkBool v29; // [rsp+C8h] [rbp+7Fh]

  v2 = result;
  v3 = this;
  `anonymous namespace'::Reader::_pushBlock(this);
  v4 = `anonymous namespace'::Reader::_getAttribute(v3, "name");
  if ( v4 )
  {
    value = 0;
    hkXmlStreamParser::getIntAttribute(&v3->m_parser, &resulta, "version", &value);
    v6 = `anonymous namespace'::Reader::_getAttribute(v3, "parent");
    array = 0i64;
    v23 = value;
    v7 = v3->m_world;
    v26 = 0;
    v27 = 2147483648;
    v22 = v4;
    v24 = v6;
    v8 = (hkTypeManager *)((__int64 (*)(void))v7->vfptr[5].__first_virtual_table_function__)();
    hkXmlStreamParser::advance(&v3->m_parser);
    while ( `anonymous namespace'::Reader::_skipWhiteSpace(v3) == 2 )
    {
      v9 = hkXmlStreamParser::getBlockName(&v3->m_parser, &v21);
      if ( !hkSubString::operator==(v9, (hkBool *)&resulta, "member")->m_bool )
        break;
      v10 = `anonymous namespace'::Reader::_getAttribute(v3, "name");
      v11 = `anonymous namespace'::Reader::_getAttribute(v3, "type");
      v12 = `anonymous namespace'::Reader::_getAttribute(v3, "class");
      v13 = v12;
      if ( !v10 )
        goto LABEL_18;
      if ( !v11 )
        goto LABEL_18;
      v14 = `anonymous namespace'::Reader::_getType(v3, v11, v12);
      if ( !v14 )
        goto LABEL_18;
      if ( `anonymous namespace'::Reader::_getBoolAttribute(v3, &v29, "array", 0)->m_bool )
        v14 = hkTypeManager::makeArray(v8, v14);
      tupleSize = 0;
      hkXmlStreamParser::getIntAttribute(&v3->m_parser, &v20, "count", &tupleSize);
      if ( tupleSize > 0 )
        v14 = hkTypeManager::makeTuple(v8, v14, tupleSize);
      v15 = v26;
      if ( v26 == (v27 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 24);
        v15 = v26;
      }
      v16 = 3i64 * v15;
      v17 = array;
      v26 = v15 + 1;
      array[v16] = v10;
      v17[v16 + 1] = v14;
      v17[v16 + 2] = 0i64;
      if ( v13 )
        ((void (__fastcall *)(hkDataWorld *, char *))v3->m_world->vfptr[4].__first_virtual_table_function__)(
          v3->m_world,
          v13);
      hkXmlStreamParser::advance(&v3->m_parser);
    }
    if ( `anonymous namespace'::Reader::_popBlock(v3, &resulta)->m_enum == 1 )
    {
LABEL_18:
      v2->m_enum = 1;
    }
    else
    {
      hkXmlStreamParser::advance(&v3->m_parser);
      ((void (__fastcall *)(hkDataWorld *, char **))v3->m_world->vfptr[1].__first_virtual_table_function__)(
        v3->m_world,
        &v22);
      v2->m_enum = 0;
    }
    v26 = 0;
    if ( v27 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        24 * (v27 & 0x3FFFFFFF));
    v5 = v2;
  }
  else
  {
    v2->m_enum = 1;
    v5 = v2;
  }
  return v5;
}

// File Line: 409
// RVA: 0xE54AE0
hkResult *__fastcall `anonymous namespace'::Reader::_parseInt(Reader *this, hkResult *result, const char *blockName, __int64 *valueOut)
{
  __int64 *v4; // rbp
  const char *v5; // rsi
  hkResult *v6; // rbx
  Reader *v7; // rdi
  hkSubString *v8; // rax
  hkSubString *v9; // rax
  hkResult v11; // [rsp+20h] [rbp-28h]
  hkSubString resulta; // [rsp+28h] [rbp-20h]
  hkBool v13; // [rsp+50h] [rbp+8h]

  v4 = valueOut;
  v5 = blockName;
  v6 = result;
  v7 = this;
  if ( this->m_parser.m_token == 1
    && (v8 = hkXmlStreamParser::getBlockName(&this->m_parser, &resulta), hkSubString::operator==(v8, &v13, v5)->m_bool)
    && (`anonymous namespace'::Reader::_pushBlock(v7),
        hkXmlStreamParser::advance(&v7->m_parser),
        `anonymous namespace'::Reader::_skipWhiteSpace(v7) == 4) )
  {
    v9 = hkXmlStreamParser::getLexeme(&v7->m_parser, &resulta);
    hkXmlStreamParser::parseInt(&v11, v9, v4);
    if ( v11.m_enum )
    {
      v6->m_enum = v11.m_enum;
    }
    else
    {
      hkXmlStreamParser::advance(&v7->m_parser);
      `anonymous namespace'::Reader::_popBlock(v7, v6);
    }
  }
  else
  {
    v6->m_enum = 1;
  }
  return v6;
}

// File Line: 436
// RVA: 0xE54BB0
hkResult *__fastcall `anonymous namespace'::Reader::_parseReal(Reader *this, hkResult *result, const char *blockName, float *valueOut)
{
  float *v4; // rbp
  const char *v5; // rsi
  hkResult *v6; // rbx
  Reader *v7; // rdi
  hkSubString *v8; // rax
  hkSubString *v9; // rax
  hkResult v11; // [rsp+20h] [rbp-28h]
  hkSubString resulta; // [rsp+28h] [rbp-20h]
  hkBool v13; // [rsp+50h] [rbp+8h]

  v4 = valueOut;
  v5 = blockName;
  v6 = result;
  v7 = this;
  if ( this->m_parser.m_token == 1
    && (v8 = hkXmlStreamParser::getBlockName(&this->m_parser, &resulta), hkSubString::operator==(v8, &v13, v5)->m_bool)
    && (`anonymous namespace'::Reader::_pushBlock(v7),
        hkXmlStreamParser::advance(&v7->m_parser),
        `anonymous namespace'::Reader::_skipWhiteSpace(v7) == 4) )
  {
    v9 = hkXmlStreamParser::getLexeme(&v7->m_parser, &resulta);
    hkXmlStreamParser::parseReal(&v11, v9, v4);
    if ( v11.m_enum )
    {
      v6->m_enum = v11.m_enum;
    }
    else
    {
      hkXmlStreamParser::advance(&v7->m_parser);
      `anonymous namespace'::Reader::_popBlock(v7, v6);
    }
  }
  else
  {
    v6->m_enum = 1;
  }
  return v6;
}

// File Line: 487
// RVA: 0xE55040
hkResult *__fastcall `anonymous namespace'::Reader::_parseRealVector(Reader *this, hkResult *result, float *out, int numReal)
{
  int v4; // ebp
  float *v5; // r14
  hkResult *v6; // rsi
  Reader *v7; // rdi
  int v8; // ebx
  hkSubString resulta; // [rsp+20h] [rbp-28h]
  hkResult v11; // [rsp+68h] [rbp+20h]

  v4 = numReal;
  v5 = out;
  v6 = result;
  v7 = this;
  `anonymous namespace'::Reader::_pushBlock(this);
  hkXmlStreamParser::advance(&v7->m_parser);
  v8 = 0;
  if ( v4 <= 0 )
  {
LABEL_5:
    `anonymous namespace'::Reader::_popBlock(v7, v6);
  }
  else
  {
    while ( `anonymous namespace'::Reader::_skipWhiteSpace(v7) == 4 )
    {
      hkXmlStreamParser::getLexeme(&v7->m_parser, &resulta);
      hkXmlStreamParser::parseReal(&v11, &resulta, &v5[v8]);
      if ( v11.m_enum )
      {
        v6->m_enum = v11.m_enum;
        return v6;
      }
      hkXmlStreamParser::advance(&v7->m_parser);
      if ( ++v8 >= v4 )
        goto LABEL_5;
    }
    v6->m_enum = 1;
  }
  return v6;
}

// File Line: 515
// RVA: 0xE550F0
hkResult *__fastcall `anonymous namespace'::Reader::_parseString(Reader *this, hkResult *result, const char **stringOut)
{
  hkResult *v3; // rbx
  const char **v4; // r14
  Reader *v5; // rdi
  hkXmlStreamParser::Token v6; // eax
  hkXmlStreamParser::Token v7; // eax
  char *v8; // r15
  Dummy *v9; // r12
  char *v10; // r15
  hkSubString subString; // [rsp+20h] [rbp-E0h]
  hkSubString resulta; // [rsp+30h] [rbp-D0h]
  hkStringBuf v14; // [rsp+40h] [rbp-C0h]
  hkStringBuf buf; // [rsp+D0h] [rbp-30h]
  hkBool v16; // [rsp+190h] [rbp+90h]

  v3 = result;
  v4 = stringOut;
  v5 = this;
  *stringOut = 0i64;
  hkXmlStreamParser::getBlockName(&this->m_parser, &resulta);
  if ( hkSubString::operator==(&resulta, &v16, "null")->m_bool )
  {
    hkXmlStreamParser::advance(&v5->m_parser);
    v3->m_enum = 0;
  }
  else
  {
    if ( !hkSubString::operator==(&resulta, &v16, "string")->m_bool )
      goto LABEL_24;
    v6 = v5->m_parser.m_token;
    if ( v6 == 2 )
    {
      hkXmlStreamParser::advance(&v5->m_parser);
      *v4 = &customWorldMapCaption;
      v3->m_enum = 0;
      return v3;
    }
    if ( v6 == 1 )
    {
      `anonymous namespace'::Reader::_pushBlock(v5);
      v7 = hkXmlStreamParser::advance(&v5->m_parser);
      if ( v7 == 3 )
      {
        *v4 = &customWorldMapCaption;
        `anonymous namespace'::Reader::_popBlock(v5, v3);
      }
      else
      {
        v14.m_string.m_capacityAndFlags = -2147483520;
        v14.m_string.m_size = 1;
        v14.m_string.m_data = v14.m_string.m_storage;
        v14.m_string.m_storage[0] = 0;
        while ( (unsigned int)(v7 - 4) <= 1 )
        {
          hkXmlStreamParser::getLexeme(&v5->m_parser, &subString);
          hkStringBuf::append(&v14, subString.m_start, LODWORD(subString.m_end) - LODWORD(subString.m_start));
          v7 = hkXmlStreamParser::advance(&v5->m_parser);
        }
        subString.m_start = v14.m_string.m_data;
        subString.m_end = &v14.m_string.m_data[v14.m_string.m_size - 1];
        if ( hkXmlStreamParser::needsDecode(&v16, &subString)->m_bool )
        {
          buf.m_string.m_data = buf.m_string.m_storage;
          subString.m_start = v14.m_string.m_data;
          buf.m_string.m_capacityAndFlags = -2147483520;
          buf.m_string.m_size = 1;
          buf.m_string.m_storage[0] = 0;
          subString.m_end = &v14.m_string.m_data[v14.m_string.m_size - 1];
          hkXmlStreamParser::decodeString((hkResult *)&v16, &subString, &buf);
          hkStringBuf::operator=(&v14, &buf);
          buf.m_string.m_size = 0;
          if ( buf.m_string.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              buf.m_string.m_data,
              buf.m_string.m_capacityAndFlags & 0x3FFFFFFF);
        }
        v8 = v14.m_string.m_data;
        v9 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
               (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5->m_stringMap,
               (unsigned __int64)v14.m_string.m_data);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5->m_stringMap,
          &v16,
          v9);
        if ( v16.m_bool )
        {
          v10 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                          &v5->m_stringMap.m_map,
                          v9);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(&v5->m_stringMap.m_map, v9, 1ui64);
        }
        else
        {
          v10 = hkString::strDup(v8, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
            &v5->m_stringMap.m_map,
            (unsigned __int64)v10,
            1ui64);
        }
        *v4 = v10;
        `anonymous namespace'::Reader::_popBlock(v5, v3);
        v14.m_string.m_size = 0;
        if ( v14.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v14.m_string.m_data,
            v14.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      }
    }
    else
    {
LABEL_24:
      v3->m_enum = 1;
    }
  }
  return v3;
}

// File Line: 575
// RVA: 0xE55660
hkResult *__fastcall `anonymous namespace'::Reader::_parseIntArray(Reader *this, hkResult *result, const char *blockName, hkDataArray *arr)
{
  Reader *v4; // rdi
  hkDataArray *v5; // r14
  const char *v6; // r15
  hkResult *v7; // rsi
  unsigned int v8; // ebx
  int v9; // ebp
  hkXmlStreamParser::Token v10; // ecx
  hkResultEnum v11; // eax
  hkResult v13; // [rsp+20h] [rbp-48h]
  __int64 valueOut; // [rsp+28h] [rbp-40h]
  __int64 v15; // [rsp+30h] [rbp-38h]
  hkSubString subString; // [rsp+38h] [rbp-30h]
  hkResult resulta; // [rsp+88h] [rbp+20h]

  v4 = this;
  v5 = arr;
  v6 = blockName;
  v7 = result;
  v8 = 0;
  v9 = ((__int64 (*)(void))arr->m_impl->vfptr[5].__vecDelDtor)();
  if ( v9 > 0 )
  {
    do
    {
      `anonymous namespace'::Reader::_skipWhiteSpace(v4);
      v10 = v4->m_parser.m_token;
      if ( v10 == 1 )
      {
        `anonymous namespace'::Reader::_parseInt(v4, &resulta, v6, &valueOut);
        v11 = resulta.m_enum;
        if ( resulta.m_enum )
          goto LABEL_11;
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->m_impl->vfptr[20].__vecDelDtor)(
          v5->m_impl,
          v8,
          valueOut);
      }
      else
      {
        if ( v10 != 4 )
        {
          v7->m_enum = 1;
          return v7;
        }
        hkXmlStreamParser::getLexeme(&v4->m_parser, &subString);
        hkXmlStreamParser::parseInt(&v13, &subString, &v15);
        v11 = v13.m_enum;
        if ( v13.m_enum )
        {
LABEL_11:
          v7->m_enum = v11;
          return v7;
        }
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->m_impl->vfptr[20].__vecDelDtor)(
          v5->m_impl,
          v8,
          v15);
        hkXmlStreamParser::advance(&v4->m_parser);
      }
      ++v8;
    }
    while ( (signed int)v8 < v9 );
  }
  v7->m_enum = 0;
  return v7;
}

// File Line: 617
// RVA: 0xE55780
hkResult *__fastcall `anonymous namespace'::Reader::_parseRealArray(Reader *this, hkResult *result, const char *blockName, hkDataArray *arr)
{
  Reader *v4; // rdi
  hkDataArray *v5; // r14
  const char *v6; // r15
  hkResult *v7; // rsi
  signed int v8; // ebx
  signed int v9; // ebp
  hkXmlStreamParser::Token v10; // ecx
  hkResultEnum v11; // eax
  hkSubString *v12; // rax
  float valueOut; // [rsp+20h] [rbp-38h]
  hkResult v15; // [rsp+24h] [rbp-34h]
  float v16; // [rsp+28h] [rbp-30h]
  hkSubString v17; // [rsp+30h] [rbp-28h]
  hkResult resulta; // [rsp+78h] [rbp+20h]

  v4 = this;
  v5 = arr;
  v6 = blockName;
  v7 = result;
  v8 = 0;
  v9 = ((__int64 (*)(void))arr->m_impl->vfptr[5].__vecDelDtor)();
  if ( v9 > 0 )
  {
    do
    {
      `anonymous namespace'::Reader::_skipWhiteSpace(v4);
      v10 = v4->m_parser.m_token;
      if ( v10 == 1 )
      {
        `anonymous namespace'::Reader::_parseReal(v4, &resulta, v6, &valueOut);
        v11 = resulta.m_enum;
        if ( resulta.m_enum )
          goto LABEL_11;
        v5->m_impl->vfptr[16].__vecDelDtor((hkDataRefCounted *)v5->m_impl, v8);
      }
      else
      {
        if ( v10 != 4 )
        {
          v7->m_enum = 1;
          return v7;
        }
        v12 = hkXmlStreamParser::getLexeme(&v4->m_parser, &v17);
        hkXmlStreamParser::parseReal(&v15, v12, &v16);
        v11 = v15.m_enum;
        if ( v15.m_enum )
        {
LABEL_11:
          v7->m_enum = v11;
          return v7;
        }
        v5->m_impl->vfptr[16].__vecDelDtor((hkDataRefCounted *)v5->m_impl, v8);
        hkXmlStreamParser::advance(&v4->m_parser);
      }
      ++v8;
    }
    while ( v8 < v9 );
  }
  v7->m_enum = 0;
  return v7;
}

// File Line: 656
// RVA: 0xE54C80
hkResult *__fastcall `anonymous namespace'::Reader::_parseArrayItems(Reader *this, hkResult *result, int numElems, hkDataArray *arr)
{
  Reader *v4; // rdi
  hkDataArray *v5; // r15
  int v6; // esi
  hkResult *v7; // r14
  _DWORD *v8; // rax
  _DWORD *v9; // rdx
  int v10; // eax
  const char *v11; // r8
  int v12; // eax
  signed int v13; // er8
  int v14; // er12
  int v15; // er9
  int v16; // ebx
  int v17; // er8
  int v18; // ebx
  unsigned int v19; // er12
  hkDataObjectImpl *v20; // rax
  hkDataObjectImpl *v21; // rdx
  hkDataObject *v22; // r8
  hkDataObjectImpl *v23; // rax
  hkDataObjectImpl *v24; // rcx
  bool v25; // zf
  int i; // ebx
  hkDataObjectImpl *v27; // rax
  hkDataObject obj; // [rsp+30h] [rbp-39h]
  int v30; // [rsp+38h] [rbp-31h]
  hkResult v31; // [rsp+40h] [rbp-29h]
  hkResult v32; // [rsp+44h] [rbp-25h]
  char *array; // [rsp+50h] [rbp-19h]
  int v34; // [rsp+58h] [rbp-11h]
  int v35; // [rsp+5Ch] [rbp-Dh]
  char v36; // [rsp+60h] [rbp-9h]
  hkResult resulta; // [rsp+E8h] [rbp+7Fh]

  v4 = this;
  v5 = arr;
  v6 = numElems;
  v7 = result;
  v8 = (_DWORD *)((__int64 (*)(void))arr->m_impl->vfptr[1].__vecDelDtor)();
  v9 = v8;
  v10 = *v8;
  switch ( v10 )
  {
    case 2:
    case 4:
      v11 = "int";
      if ( v10 == 2 )
        v11 = "byte";
      `anonymous namespace'::Reader::_parseIntArray(v4, v7, v11, v5);
      return v7;
    case 3:
      `anonymous namespace'::Reader::_parseRealArray(v4, v7, "real", v5);
      return v7;
    case 5:
      v18 = 0;
      if ( v6 <= 0 )
        goto LABEL_44;
      do
      {
        `anonymous namespace'::Reader::_skipWhiteSpace(v4);
        if ( `anonymous namespace'::Reader::_parseString(v4, &v31, (const char **)&resulta)->m_enum )
          goto LABEL_45;
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v5->m_impl->vfptr[14].__vecDelDtor)(
          v5->m_impl,
          (unsigned int)v18++,
          *(_QWORD *)&resulta.m_enum);
      }
      while ( v18 < v6 );
      `anonymous namespace'::Reader::_skipWhiteSpace(v4);
      v7->m_enum = 0;
      return v7;
    case 6:
      v19 = 0;
      if ( v6 <= 0 )
        goto LABEL_44;
      while ( 1 )
      {
        `anonymous namespace'::Reader::_skipWhiteSpace(v4);
        v20 = (hkDataObjectImpl *)v5->m_impl->vfptr[21].__vecDelDtor((hkDataRefCounted *)v5->m_impl, v19);
        v21 = v20;
        obj.m_impl = v20;
        if ( v20 )
        {
          ++v20->m_externalCount;
          ++v20->m_count;
          v21 = obj.m_impl;
        }
        if ( v4->m_tmpObjects.m_size == (v4->m_tmpObjects.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_tmpObjects, 8);
          v21 = obj.m_impl;
        }
        v22 = &v4->m_tmpObjects.m_data[v4->m_tmpObjects.m_size];
        if ( v22 )
        {
          v22->m_impl = v21;
          v23 = obj.m_impl;
          if ( obj.m_impl )
          {
            ++obj.m_impl->m_externalCount;
            ++v23->m_count;
          }
        }
        ++v4->m_tmpObjects.m_size;
        `anonymous namespace'::Reader::_parseObject(v4, &resulta, &obj);
        v24 = obj.m_impl;
        if ( resulta.m_enum )
          break;
        if ( obj.m_impl )
        {
          --obj.m_impl->m_externalCount;
          v25 = v24->m_count-- == 1;
          if ( v25 )
            v24->vfptr->__vecDelDtor((hkDataRefCounted *)&v24->vfptr, 1u);
        }
        if ( (signed int)++v19 >= v6 )
        {
          `anonymous namespace'::Reader::_skipWhiteSpace(v4);
          v7->m_enum = 0;
          return v7;
        }
      }
      v7->m_enum = resulta.m_enum;
      if ( v24 )
      {
        --v24->m_externalCount;
        v25 = v24->m_count-- == 1;
        if ( v25 )
          v24->vfptr->__vecDelDtor((hkDataRefCounted *)&v24->vfptr, 1u);
      }
      return v7;
    case 7:
      for ( i = 0; i < v6; ++i )
      {
        v27 = (hkDataObjectImpl *)v5->m_impl;
        v30 = i;
        obj.m_impl = v27;
        `anonymous namespace'::Reader::_parseObjectReferenceImpl<hkDataArray_Value>(
          v4,
          &resulta,
          (hkDataArray_Value *)&obj);
      }
      goto LABEL_44;
    case 9:
      if ( v10 != 9 || **((_DWORD **)v9 + 1) != 3 || (v9[4] - 4) & 0xFFFFFFF3 )
        goto LABEL_44;
      v12 = hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v9);
      v13 = -2147483632;
      v34 = 0;
      v14 = v12;
      v35 = -2147483632;
      array = &v36;
      if ( v12 > 16 )
      {
        v15 = v12;
        if ( v12 < 32 )
          v15 = 32;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v15, 4);
        v13 = v35;
      }
      v34 = v14;
      v16 = 0;
      if ( v6 <= 0 )
        goto LABEL_17;
      break;
    default:
LABEL_45:
      v7->m_enum = 1;
      return v7;
  }
  do
  {
    `anonymous namespace'::Reader::_skipWhiteSpace(v4);
    if ( `anonymous namespace'::Reader::_parseRealVector(v4, &v32, (float *)array, v14)->m_enum )
    {
      v17 = v35;
      v7->m_enum = 1;
      v34 = 0;
      if ( v17 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          4 * v17);
      return v7;
    }
    ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, char *))v5->m_impl->vfptr[12].__vecDelDtor)(
      v5->m_impl,
      (unsigned int)v16++,
      array);
  }
  while ( v16 < v6 );
  v13 = v35;
LABEL_17:
  v34 = 0;
  if ( v13 < 0 )
  {
LABEL_44:
    `anonymous namespace'::Reader::_skipWhiteSpace(v4);
    v7->m_enum = 0;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v13);
    `anonymous namespace'::Reader::_skipWhiteSpace(v4);
    v7->m_enum = 0;
  }
  return v7;
}

// File Line: 753
// RVA: 0xE54550
hkResult *__fastcall `anonymous namespace'::Reader::_parseMemberValue(Reader *this, hkResult *result, hkDataClass_MemberInfo *minfo, hkDataObject_Value *valueOut)
{
  hkTypeManager::Type *v4; // r15
  hkDataObject_Value *v5; // rdi
  hkDataClass_MemberInfo *v6; // rbx
  hkTypeManager::SubType v7; // eax
  hkResult *v8; // rsi
  Reader *v9; // r14
  int v10; // eax
  bool v11; // zf
  __int32 v12; // eax
  int v13; // eax
  hkDataObjectImpl *v14; // rdi
  hkDataArrayImpl *v15; // rax
  hkDataArrayImpl *v16; // rbx
  hkSubString *v17; // rax
  int v18; // eax
  hkResultEnum v19; // eax
  hkDataArrayImpl *v20; // rcx
  hkDataArrayImpl *v21; // rax
  hkDataArrayImpl *v22; // rbx
  hkDataArrayImpl *v23; // rcx
  hkDataArrayImpl *v24; // rcx
  hkBaseObjectVtbl *v25; // rbx
  const char *v26; // rax
  hkDataClassImpl *v27; // rax
  hkDataArrayImpl *v28; // rcx
  hkDataArrayImpl *v29; // rcx
  int value; // [rsp+20h] [rbp-39h]
  hkDataArray arr; // [rsp+28h] [rbp-31h]
  hkDataArray v33; // [rsp+30h] [rbp-29h]
  __int64 v34; // [rsp+38h] [rbp-21h]
  hkResult v35; // [rsp+40h] [rbp-19h]
  hkSubString v36; // [rsp+48h] [rbp-11h]
  float out; // [rsp+60h] [rbp+7h]
  hkResult resulta; // [rsp+D0h] [rbp+77h]

  v4 = minfo->m_type;
  v5 = valueOut;
  v6 = minfo;
  v7 = v4->m_subType;
  v8 = result;
  v9 = this;
  if ( v4->m_subType == 9 )
  {
    v10 = hkTypeManager::Type::getTupleSize(minfo->m_type);
    v11 = v4->m_subType == 9;
    value = v10;
    if ( v11 && v4->m_parent->m_subType == 3 && !((v4->m_extra.m_size - 4) & 0xFFFFFFF3) )
    {
      if ( `anonymous namespace'::Reader::_parseRealVector(v9, &resulta, &out, v10)->m_enum == HK_SUCCESS )
      {
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, float *, _QWORD))v5->m_impl->vfptr[18].__vecDelDtor)(
          v5->m_impl,
          v5->m_handle,
          &out,
          (unsigned int)value);
        v8->m_enum = 0;
        return v8;
      }
LABEL_68:
      v8->m_enum = 1;
      return v8;
    }
    if ( !hkXmlStreamParser::hasAttribute(&v9->m_parser, (hkBool *)&resulta, "size")->m_bool )
      goto LABEL_10;
    v12 = hkXmlStreamParser::getIntAttribute(&v9->m_parser, &resulta, "size", &value)->m_enum;
    if ( !v12 )
    {
      v13 = hkTypeManager::Type::getTupleSize(v4);
      if ( value != v13 )
        goto LABEL_68;
LABEL_10:
      v14 = v5->m_impl;
      if ( v14 )
      {
        ++v14->m_externalCount;
        ++v14->m_count;
      }
      ((void (__fastcall *)(hkDataObjectImpl *, hkDataArray *, const char *))v14->vfptr[3].__vecDelDtor)(
        v14,
        &v33,
        v6->m_name);
      v15 = (hkDataArrayImpl *)v33.m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)v33.m_impl, v34);
      v16 = v15;
      arr.m_impl = v15;
      if ( v15 )
      {
        ++v15->m_externalCount;
        ++v15->m_count;
      }
      if ( v9->m_parser.m_token == 1
        && (v17 = hkXmlStreamParser::getBlockName(&v9->m_parser, &v36),
            hkSubString::operator==(v17, (hkBool *)&resulta, "tuple")->m_bool) )
      {
        `anonymous namespace'::Reader::_pushBlock(v9);
        hkXmlStreamParser::advance(&v9->m_parser);
        v18 = hkTypeManager::Type::getTupleSize(v4);
        v19 = `anonymous namespace'::Reader::_parseArrayItems(v9, &resulta, v18, &arr)->m_enum;
        if ( v19 )
        {
          v8->m_enum = v19;
          if ( v16 )
          {
            --v16->m_externalCount;
            v11 = v16->m_count-- == 1;
            if ( v11 )
              v16->vfptr->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
          }
          --v14->m_externalCount;
          v11 = v14->m_count-- == 1;
          if ( v11 )
            v14->vfptr->__vecDelDtor((hkDataRefCounted *)&v14->vfptr, 1u);
        }
        else
        {
          `anonymous namespace'::Reader::_popBlock(v9, v8);
          if ( v16 )
          {
            --v16->m_externalCount;
            v11 = v16->m_count-- == 1;
            if ( v11 )
              v16->vfptr->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
          }
          --v14->m_externalCount;
          v11 = v14->m_count-- == 1;
          if ( v11 )
            v14->vfptr->__vecDelDtor((hkDataRefCounted *)&v14->vfptr, 1u);
        }
      }
      else
      {
        v8->m_enum = 1;
        if ( v16 )
        {
          --v16->m_externalCount;
          v11 = v16->m_count-- == 1;
          if ( v11 )
            v16->vfptr->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
        }
        --v14->m_externalCount;
        v11 = v14->m_count-- == 1;
        if ( v11 )
          v14->vfptr->__vecDelDtor((hkDataRefCounted *)&v14->vfptr, 1u);
      }
      return v8;
    }
LABEL_53:
    v8->m_enum = v12;
    return v8;
  }
  if ( v7 == 8 )
  {
    hkXmlStreamParser::getIntAttribute(&this->m_parser, (hkResult *)&value, "size", (int *)&resulta);
    v12 = value;
    if ( value )
      goto LABEL_53;
    v20 = (hkDataArrayImpl *)v5->m_impl;
    arr.m_impl = v20;
    if ( v20 )
    {
      ++v20->m_externalCount;
      ++v20->m_count;
      v20 = arr.m_impl;
    }
    ((void (__fastcall *)(hkDataArrayImpl *, hkSubString *, const char *))v20->vfptr[3].__vecDelDtor)(
      v20,
      &v36,
      v6->m_name);
    v21 = (hkDataArrayImpl *)((__int64 (__fastcall *)(hkDataWorld *, hkDataArray *, const char *, hkDataClass_MemberInfo *))v9->m_world->vfptr[2].__first_virtual_table_function__)(
                               v9->m_world,
                               &arr,
                               v36.m_end,
                               v6);
    v22 = v21;
    v33.m_impl = v21;
    if ( v21 )
    {
      ++v21->m_externalCount;
      ++v21->m_count;
    }
    v21->vfptr[4].__vecDelDtor((hkDataRefCounted *)&v21->vfptr, resulta.m_enum);
    `anonymous namespace'::Reader::_pushBlock(v9);
    hkXmlStreamParser::advance(&v9->m_parser);
    if ( `anonymous namespace'::Reader::_parseArrayItems(v9, &v35, resulta.m_enum, &v33)->m_enum )
    {
      v8->m_enum = 1;
      --v22->m_externalCount;
      v11 = v22->m_count-- == 1;
      if ( v11 )
        v22->vfptr->__vecDelDtor((hkDataRefCounted *)&v22->vfptr, 1u);
      v23 = arr.m_impl;
      if ( arr.m_impl )
      {
        --arr.m_impl->m_externalCount;
        v11 = v23->m_count-- == 1;
        if ( v11 )
          v23->vfptr->__vecDelDtor((hkDataRefCounted *)&v23->vfptr, 1u);
      }
    }
    else
    {
      `anonymous namespace'::Reader::_popBlock(v9, v8);
      --v22->m_externalCount;
      v11 = v22->m_count-- == 1;
      if ( v11 )
        v22->vfptr->__vecDelDtor((hkDataRefCounted *)&v22->vfptr, 1u);
      v24 = arr.m_impl;
      if ( arr.m_impl )
      {
        --arr.m_impl->m_externalCount;
        v11 = v24->m_count-- == 1;
        if ( v11 )
          v24->vfptr->__vecDelDtor((hkDataRefCounted *)&v24->vfptr, 1u);
      }
    }
  }
  else
  {
    switch ( v7 )
    {
      case 2:
        `anonymous namespace'::Reader::_parseInt(this, &resulta, "byte", (__int64 *)&v33);
        v12 = resulta.m_enum;
        if ( resulta.m_enum )
          goto LABEL_53;
        goto LABEL_51;
      case 3:
        `anonymous namespace'::Reader::_parseReal(this, &resulta, "real", (float *)&value);
        v12 = resulta.m_enum;
        if ( resulta.m_enum )
          goto LABEL_53;
        v5->m_impl->vfptr[20].__vecDelDtor((hkDataRefCounted *)v5->m_impl, (unsigned int)v5->m_handle);
        v8->m_enum = 0;
        return v8;
      case 4:
        `anonymous namespace'::Reader::_parseInt(this, &resulta, "int", (__int64 *)&v33);
        v12 = resulta.m_enum;
        if ( resulta.m_enum )
          goto LABEL_53;
LABEL_51:
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataArrayImpl *))v5->m_impl->vfptr[16].__vecDelDtor)(
          v5->m_impl,
          v5->m_handle,
          v33.m_impl);
        v8->m_enum = 0;
        return v8;
      case 5:
        `anonymous namespace'::Reader::_parseString(this, &resulta, (const char **)&v33);
        if ( resulta.m_enum )
          goto LABEL_68;
        ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataArrayImpl *))v5->m_impl->vfptr[21].__vecDelDtor)(
          v5->m_impl,
          v5->m_handle,
          v33.m_impl);
        goto LABEL_67;
      case 6:
        v25 = this->m_world->vfptr;
        v26 = hkTypeManager::Type::getTypeName(minfo->m_type);
        v27 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *, const char *))v25[4].__first_virtual_table_function__)(
                                   v9->m_world,
                                   v26);
        if ( !v27 )
          goto LABEL_68;
        arr.m_impl = 0i64;
        `anonymous namespace'::Reader::_parseAndCreateObject(v9, &resulta, v27, (hkDataObject *)&arr);
        if ( resulta.m_enum )
        {
          v28 = arr.m_impl;
          v8->m_enum = resulta.m_enum;
          if ( v28 )
          {
            --v28->m_externalCount;
            v11 = v28->m_count-- == 1;
            if ( v11 )
              v28->vfptr->__vecDelDtor((hkDataRefCounted *)&v28->vfptr, 1u);
          }
        }
        else
        {
          ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataArrayImpl *))v5->m_impl->vfptr[23].__vecDelDtor)(
            v5->m_impl,
            v5->m_handle,
            arr.m_impl);
          v29 = arr.m_impl;
          if ( arr.m_impl && (--arr.m_impl->m_externalCount, v11 = v29->m_count == 1, --v29->m_count, v11) )
          {
            v29->vfptr->__vecDelDtor((hkDataRefCounted *)&v29->vfptr, 1u);
            v8->m_enum = 0;
          }
          else
          {
LABEL_67:
            v8->m_enum = 0;
          }
        }
        break;
      case 7:
        `anonymous namespace'::Reader::_parseObjectReferenceImpl<hkDataObject_Value>(this, result, valueOut);
        break;
      default:
        goto LABEL_68;
    }
  }
  return v8;
}

// File Line: 917
// RVA: 0xE53F10
char *__fastcall `anonymous namespace'::Reader::_getAttribute(Reader *this, const char *key)
{
  Reader *v2; // rbx
  hkSubString valueOut; // [rsp+20h] [rbp-18h]
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = this;
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
  return `anonymous namespace'::Reader::_getString(v2, &valueOut);
}

// File Line: 936
// RVA: 0xE53FC0
hkBool *__fastcall `anonymous namespace'::Reader::_getBoolAttribute(Reader *this, hkBool *result, const char *key, hkBool defaultValue)
{
  hkBool *v4; // rbx
  hkBool *v5; // rax
  hkSubString valueOut; // [rsp+20h] [rbp-18h]
  hkResult resulta; // [rsp+40h] [rbp+8h]
  char v8; // [rsp+58h] [rbp+20h]

  v8 = defaultValue.m_bool;
  v4 = result;
  valueOut.m_start = 0i64;
  valueOut.m_end = 0i64;
  if ( hkXmlStreamParser::getValue(&this->m_parser, &resulta, key, &valueOut)->m_enum )
    goto LABEL_9;
  if ( hkSubString::operator==(&valueOut, (hkBool *)&resulta, "\"true\"")->m_bool )
  {
    v4->m_bool = 1;
    return v4;
  }
  if ( !hkSubString::operator==(&valueOut, (hkBool *)&resulta, "\"false\"")->m_bool )
  {
LABEL_9:
    v4->m_bool = v8;
    v5 = v4;
  }
  else
  {
    v4->m_bool = 0;
    v5 = v4;
  }
  return v5;
}

// File Line: 957
// RVA: 0xE53F90
hkXmlStreamParser::Token __fastcall `anonymous namespace'::Reader::_skipWhiteSpace(Reader *this)
{
  hkXmlStreamParser::Token result; // eax
  Reader *i; // rbx

  result = this->m_parser.m_token;
  for ( i = this; result == 5; result = hkXmlStreamParser::advance(&i->m_parser) )
    ;
  return result;
}

// File Line: 967
// RVA: 0xE55890
ReferenceInfo *__fastcall `anonymous namespace'::Reader::_findReferenceInfo(Reader *this, const char *key)
{
  return (ReferenceInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap,
                            (unsigned __int64)key,
                            0i64);
}

// File Line: 972
// RVA: 0xE55910
ReferenceInfo *__fastcall `anonymous namespace'::Reader::_requireReferenceInfo(Reader *this, const char *key)
{
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v2; // rsi
  const char *v3; // rdi
  ReferenceInfo *result; // rax
  _QWORD **v5; // rax
  ReferenceInfo *v6; // rbx

  v2 = &this->m_referenceMap.m_map;
  v3 = key;
  result = (ReferenceInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap,
                              (unsigned __int64)key,
                              0i64);
  if ( !result )
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (ReferenceInfo *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 40i64);
    if ( v6 )
    {
      v6->m_object = 0i64;
      v6->m_arrayRefs.m_data = 0i64;
      v6->m_arrayRefs.m_size = 0;
      v6->m_arrayRefs.m_capacityAndFlags = 2147483648;
      v6->m_objectRefs.m_data = 0i64;
      v6->m_objectRefs.m_size = 0;
      v6->m_objectRefs.m_capacityAndFlags = 2147483648;
    }
    else
    {
      v6 = 0i64;
    }
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      v2,
      (unsigned __int64)v3,
      (unsigned __int64)v6);
    result = v6;
  }
  return result;
}

// File Line: 985
// RVA: 0xE558B0
hkResult *__fastcall `anonymous namespace'::Reader::_setReferencedObject(Reader *this, hkResult *result, const char *id, hkDataObject *obj)
{
  hkResult *v4; // rbx
  hkDataObject *v5; // rdi
  ReferenceInfo *v6; // rcx
  hkDataObjectImpl *v8; // rax

  v4 = result;
  v5 = obj;
  v6 = `anonymous namespace'::Reader::_requireReferenceInfo(this, id);
  if ( v6->m_object )
  {
    v4->m_enum = 1;
  }
  else
  {
    v8 = v5->m_impl;
    v4->m_enum = 0;
    v6->m_object = v8;
  }
  return v4;
}

// File Line: 998
// RVA: 0xE553E0
hkResult *__fastcall `anonymous namespace'::Reader::_parseAndCreateObject(Reader *this, hkResult *result, hkDataClassImpl *klassImpl, hkDataObject *objOut)
{
  hkDataObject *v4; // r14
  hkDataClassImpl *v5; // rbx
  hkResult *v6; // rdi
  Reader *v7; // rsi
  char *v8; // rdx
  hkResult *v9; // rax
  char *v10; // rax
  hkDataWorld *v11; // rcx
  const char *v12; // rbp
  hkDataObjectImpl *v13; // rax
  hkDataObjectImpl *v14; // rbx
  hkResultEnum v15; // eax
  hkDataObjectImpl *v16; // rcx
  bool v17; // zf
  hkDataObject obj; // [rsp+20h] [rbp-28h]
  hkDataClassImpl *v19; // [rsp+28h] [rbp-20h]
  hkResult resulta; // [rsp+60h] [rbp+18h]

  v4 = objOut;
  v5 = klassImpl;
  v6 = result;
  v7 = this;
  if ( klassImpl
    || (v8 = `anonymous namespace'::Reader::_getAttribute(this, "type")) != 0i64
    && (v5 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *, char *))v7->m_world->vfptr[4].__first_virtual_table_function__)(
                                  v7->m_world,
                                  v8)) != 0i64 )
  {
    v10 = `anonymous namespace'::Reader::_getAttribute(v7, "id");
    v11 = v7->m_world;
    v19 = v5;
    v12 = v10;
    v13 = (hkDataObjectImpl *)((__int64 (__fastcall *)(hkDataWorld *, hkDataClassImpl **, _QWORD))v11->vfptr[2].__vecDelDtor)(
                                v11,
                                &v19,
                                0i64);
    v14 = v13;
    obj.m_impl = v13;
    if ( v13 )
    {
      ++v13->m_externalCount;
      ++v13->m_count;
    }
    `anonymous namespace'::Reader::_parseObject(v7, &resulta, &obj);
    if ( resulta.m_enum )
    {
      v6->m_enum = resulta.m_enum;
    }
    else if ( v12 && (v15 = `anonymous namespace'::Reader::_setReferencedObject(v7, &resulta, v12, &obj)->m_enum) != 0 )
    {
      v6->m_enum = v15;
    }
    else
    {
      if ( v14 )
      {
        ++v14->m_externalCount;
        ++v14->m_count;
      }
      v16 = v4->m_impl;
      if ( v4->m_impl )
      {
        --v16->m_externalCount;
        v17 = v16->m_count-- == 1;
        if ( v17 )
          v16->vfptr->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
      }
      v4->m_impl = v14;
      v6->m_enum = 0;
    }
    if ( v14 )
    {
      --v14->m_externalCount;
      v17 = v14->m_count-- == 1;
      if ( v17 )
        v14->vfptr->__vecDelDtor((hkDataRefCounted *)&v14->vfptr, 1u);
    }
    v9 = v6;
  }
  else
  {
    v6->m_enum = 1;
    v9 = v6;
  }
  return v9;
}

// File Line: 1043
// RVA: 0xE55530
hkResult *__fastcall `anonymous namespace'::Reader::_parseObject(Reader *this, hkResult *result, hkDataObject *obj)
{
  hkDataObject *v3; // r14
  hkResult *v4; // rdi
  Reader *v5; // rsi
  __int64 v6; // rbx
  char *v7; // rax
  unsigned int v8; // eax
  __int64 v9; // r9
  hkDataObject_Value valueOut; // [rsp+20h] [rbp-48h]
  hkDataClass_MemberInfo minfo; // [rsp+30h] [rbp-38h]
  hkResult resulta; // [rsp+70h] [rbp+8h]

  v3 = obj;
  v4 = result;
  v5 = this;
  `anonymous namespace'::Reader::_pushBlock(this);
  v6 = ((__int64 (*)(void))v3->m_impl->vfptr[2].__vecDelDtor)();
  hkXmlStreamParser::advance(&v5->m_parser);
  while ( `anonymous namespace'::Reader::_skipWhiteSpace(v5) == 1 )
  {
    v7 = `anonymous namespace'::Reader::_getAttribute(v5, "name");
    if ( !v7 )
      goto LABEL_10;
    v8 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 88i64))(v6, v7);
    if ( (v8 & 0x80000000) != 0 )
      goto LABEL_10;
    v9 = *(_QWORD *)v6;
    *(_OWORD *)&minfo.m_name = 0ui64;
    minfo.m_type = 0i64;
    minfo.m_valuePtr = 0i64;
    (*(void (__fastcall **)(__int64, _QWORD, hkDataClass_MemberInfo *))(v9 + 80))(v6, v8, &minfo);
    ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))v3->m_impl->vfptr[3].__vecDelDtor)(
      v3->m_impl,
      &valueOut,
      minfo.m_name);
    `anonymous namespace'::Reader::_parseMemberValue(v5, &resulta, &minfo, &valueOut);
    if ( resulta.m_enum )
    {
      v4->m_enum = resulta.m_enum;
      return v4;
    }
  }
  if ( `anonymous namespace'::Reader::_popBlock(v5, &resulta)->m_enum )
  {
LABEL_10:
    v4->m_enum = 1;
    return v4;
  }
  v4->m_enum = 0;
  return v4;
}

// File Line: 1096
// RVA: 0xE559B0
hkResult *__fastcall `anonymous namespace'::Reader::_fixUpReferences(Reader *this, hkResult *result)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v2; // r15
  hkResult *v3; // r12
  Dummy *v4; // rbp
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rdi
  int v7; // esi
  __int64 v8; // r14
  __int64 v9; // rbx
  bool v10; // zf
  int v11; // ebx
  __int64 v12; // rsi
  hkBool resulta; // [rsp+50h] [rbp+8h]

  v2 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap;
  v3 = result;
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_referenceMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v2, &resulta, v4);
  if ( resulta.m_bool )
  {
    while ( 1 )
    {
      v5 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(v2, v4);
      v6 = v5;
      if ( !*(_QWORD *)v5 )
        break;
      v7 = 0;
      if ( *(_DWORD *)(v5 + 16) > 0 )
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
            v10 = (*(_DWORD *)(v9 + 12))-- == 1;
            if ( v10 )
              (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
          }
          ++v7;
          v8 += 16i64;
        }
        while ( v7 < *(_DWORD *)(v6 + 16) );
      }
      v11 = 0;
      if ( *(_DWORD *)(v6 + 32) > 0 )
      {
        v12 = 0i64;
        do
        {
          (*(void (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)(v12 + *(_QWORD *)(v6 + 24)) + 184i64))(
            *(_QWORD *)(v12 + *(_QWORD *)(v6 + 24)),
            *(_QWORD *)(v12 + *(_QWORD *)(v6 + 24) + 8),
            *(_QWORD *)v6);
          ++v11;
          v12 += 16i64;
        }
        while ( v11 < *(_DWORD *)(v6 + 32) );
      }
      v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(v2, v4);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v2, &resulta, v4);
      if ( !resulta.m_bool )
        goto LABEL_15;
    }
    v3->m_enum = 1;
  }
  else
  {
LABEL_15:
    v3->m_enum = 0;
  }
  return v3;
}

// File Line: 1117
// RVA: 0xE53B30
hkResult *__fastcall `anonymous namespace'::Reader::readHeader(Reader *this, hkResult *result, hkXmlTagfile::Header *out)
{
  hkXmlTagfile::Header *v3; // rsi
  hkResult *v4; // rbx
  Reader *v5; // rdi
  hkSubString *v6; // rax
  hkOstream *v7; // rax
  hkSubString resulta; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]
  hkBool v11; // [rsp+250h] [rbp+8h]

  v3 = out;
  v4 = result;
  v5 = this;
  hkXmlStreamParser::advance(&this->m_parser);
  if ( `anonymous namespace'::Reader::_skipWhiteSpace(v5) == TOKEN_QBLOCK )
    hkXmlStreamParser::advance(&v5->m_parser);
  if ( `anonymous namespace'::Reader::_skipWhiteSpace(v5) != 1 )
    goto LABEL_11;
  v6 = hkXmlStreamParser::getBlockName(&v5->m_parser, &resulta);
  if ( !hkSubString::operator==(v6, &v11, "hktagfile")->m_bool
    || hkXmlStreamParser::getIntAttribute(&v5->m_parser, (hkResult *)&v11, "version", &v3->m_version)->m_enum == 1 )
  {
    goto LABEL_11;
  }
  if ( (unsigned int)(v3->m_version - 1) > 1 )
  {
    hkErrStream::hkErrStream((hkErrStream *)&resulta, &buf, 512);
    v7 = hkOstream::operator<<((hkOstream *)&resulta, "Unrecognised tagfile version ");
    hkOstream::operator<<(v7, v3->m_version, (int)v7);
    hkError::messageWarning(600179583, &buf, "Tagfile\\Xml\\hkXmlTagfileReader.cpp", 1162);
    hkOstream::~hkOstream((hkOstream *)&resulta);
LABEL_11:
    v4->m_enum = 1;
    return v4;
  }
  resulta.m_start = 0i64;
  resulta.m_end = 0i64;
  if ( hkXmlStreamParser::getValue(&v5->m_parser, (hkResult *)&v11, "sdkversion", &resulta)->m_enum == HK_SUCCESS )
    hkStringPtr::set(&v3->m_sdkVersion, resulta.m_start + 1, LODWORD(resulta.m_end) - LODWORD(resulta.m_start) - 2);
  v4->m_enum = 0;
  return v4;
}

// File Line: 1171
// RVA: 0xE53800
hkResult *__fastcall `anonymous namespace'::Reader::parseRoot(Reader *this, hkResult *result, hkDataObject *objOut)
{
  hkDataObject *v3; // r15
  hkResult *v4; // r14
  Reader *v5; // rsi
  int v6; // er9
  hkSubString *v8; // rax
  hkSubString *v9; // rax
  hkDataObjectImpl *v10; // rbx
  const char *v11; // rdi
  bool v12; // zf
  const char *v13; // rcx
  hkDataObjectImpl *v14; // rcx
  hkSubString resulta; // [rsp+20h] [rbp-E0h]
  hkErrStream v16; // [rsp+30h] [rbp-D0h]
  char buf; // [rsp+50h] [rbp-B0h]
  hkBool v18; // [rsp+280h] [rbp+180h]
  int value; // [rsp+298h] [rbp+198h]

  v3 = objOut;
  v4 = result;
  v5 = this;
  hkXmlStreamParser::advance(&this->m_parser);
  if ( `anonymous namespace'::Reader::_skipWhiteSpace(v5) == TOKEN_QBLOCK )
    hkXmlStreamParser::advance(&v5->m_parser);
  if ( `anonymous namespace'::Reader::_skipWhiteSpace(v5) != 1 )
  {
    hkErrStream::hkErrStream(&v16, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v16.vfptr, "Didn't find the root 'hktagfile' block");
    v6 = 1187;
LABEL_5:
    hkError::messageWarning(-18022230, &buf, "Tagfile\\Xml\\hkXmlTagfileReader.cpp", v6);
    hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
    v4->m_enum = 1;
    return v4;
  }
  v8 = hkXmlStreamParser::getBlockName(&v5->m_parser, &resulta);
  if ( !hkSubString::operator==(v8, &v18, "hktagfile")->m_bool )
  {
    hkErrStream::hkErrStream(&v16, &buf, 512);
    hkOstream::operator<<((hkOstream *)&v16.vfptr, "Expecting 'hktagfile' block");
    v6 = 1193;
    goto LABEL_5;
  }
  value = 0;
  hkXmlStreamParser::getIntAttribute(&v5->m_parser, (hkResult *)&v18, "version", &value);
  `anonymous namespace'::Reader::_pushBlock(v5);
  hkXmlStreamParser::advance(&v5->m_parser);
  while ( `anonymous namespace'::Reader::_skipWhiteSpace(v5) == 1 )
  {
    v9 = hkXmlStreamParser::getBlockName(&v5->m_parser, (hkSubString *)&v16);
    if ( !hkSubString::operator==(v9, &v18, "class")->m_bool )
      break;
    `anonymous namespace'::Reader::_parseClassDefinition(v5, (hkResult *)&resulta);
  }
  v10 = 0i64;
  while ( (unsigned int)(`anonymous namespace'::Reader::_skipWhiteSpace(v5) - 1) <= 1 )
  {
    resulta.m_start = 0i64;
    `anonymous namespace'::Reader::_parseAndCreateObject(v5, (hkResult *)&v18, 0i64, (hkDataObject *)&resulta);
    if ( *(_DWORD *)&v18.m_bool == 1 )
    {
      v13 = resulta.m_start;
      v4->m_enum = 1;
      if ( v13 )
      {
        --*((_WORD *)v13 + 5);
        v12 = (*((_DWORD *)v13 + 3))-- == 1;
        if ( v12 )
          (**(void (__fastcall ***)(const char *, signed __int64))v13)(v13, 1i64);
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
        v10->vfptr->__vecDelDtor((hkDataRefCounted *)&v10->vfptr, 1u);
    }
    v10 = (hkDataObjectImpl *)v11;
    if ( v11 )
    {
      --*((_WORD *)v11 + 5);
      v12 = (*((_DWORD *)v11 + 3))-- == 1;
      if ( v12 )
        (**(void (__fastcall ***)(const char *, signed __int64))v11)(v11, 1i64);
    }
  }
  if ( `anonymous namespace'::Reader::_popBlock(v5, (hkResult *)&v18)->m_enum )
  {
    v4->m_enum = 1;
  }
  else if ( `anonymous namespace'::Reader::_skipWhiteSpace(v5) == 7 )
  {
    `anonymous namespace'::Reader::_fixUpReferences(v5, (hkResult *)&v18);
    if ( *(_DWORD *)&v18.m_bool )
    {
      v4->m_enum = *(hkResultEnum *)&v18.m_bool;
    }
    else
    {
      if ( v10 )
      {
        ++v10->m_externalCount;
        ++v10->m_count;
      }
      v14 = v3->m_impl;
      if ( v3->m_impl )
      {
        --v14->m_externalCount;
        v12 = v14->m_count-- == 1;
        if ( v12 )
          v14->vfptr->__vecDelDtor((hkDataRefCounted *)&v14->vfptr, 1u);
      }
      v3->m_impl = v10;
      v4->m_enum = 0;
    }
  }
  else
  {
    v4->m_enum = 1;
  }
LABEL_37:
  if ( v10 )
  {
    --v10->m_externalCount;
    v12 = v10->m_count-- == 1;
    if ( v12 )
      v10->vfptr->__vecDelDtor((hkDataRefCounted *)&v10->vfptr, 1u);
  }
  return v4;
}

// File Line: 1273
// RVA: 0xE532C0
hkDataObject *__fastcall hkXmlTagfileReader::load(hkXmlTagfileReader *this, hkDataObject *result, hkStreamReader *stream, hkDataWorld *world)
{
  hkDataObject *v4; // rbx
  hkDataObjectImpl *v5; // rcx
  bool v6; // zf
  int v7; // eax
  hkDataObject objOut; // [rsp+20h] [rbp-158h]
  hkResult resulta; // [rsp+28h] [rbp-150h]
  Reader v11; // [rsp+30h] [rbp-148h]

  v4 = result;
  `anonymous namespace'::Reader::Reader(&v11, stream, world);
  objOut.m_impl = 0i64;
  `anonymous namespace'::Reader::parseRoot(&v11, &resulta, &objOut);
  v5 = objOut.m_impl;
  if ( resulta.m_enum )
  {
    v4->m_impl = 0i64;
    if ( !v5 )
      goto LABEL_8;
    --v5->m_externalCount;
    v6 = v5->m_count-- == 1;
  }
  else
  {
    v4->m_impl = objOut.m_impl;
    if ( !v5 )
      goto LABEL_8;
    v7 = v5->m_count;
    v5->m_count = v7;
    v6 = v7 == 0;
  }
  if ( v6 )
    v5->vfptr->__vecDelDtor((hkDataRefCounted *)&v5->vfptr, 1u);
LABEL_8:
  `anonymous namespace'::Reader::~Reader(&v11);
  return v4;
}

// File Line: 1287
// RVA: 0xE53360
hkResult *__fastcall hkXmlTagfileReader::readHeader(hkXmlTagfileReader *this, hkResult *result, hkStreamReader *stream, hkXmlTagfile::Header *out)
{
  hkResult *v4; // rdi
  hkXmlTagfile::Header *v5; // rbx
  Reader v7; // [rsp+20h] [rbp-148h]

  v4 = result;
  v5 = out;
  `anonymous namespace'::Reader::Reader(&v7, stream, 0i64);
  `anonymous namespace'::Reader::readHeader(&v7, v4, v5);
  `anonymous namespace'::Reader::~Reader(&v7);
  return v4;
}

