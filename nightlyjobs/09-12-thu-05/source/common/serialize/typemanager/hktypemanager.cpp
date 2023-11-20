// File Line: 21
// RVA: 0xE5D8B0
signed __int64 __fastcall hkTypeManager::Type::getTupleSize(hkTypeManager::Type *this)
{
  signed __int64 result; // rax

  if ( this->m_subType == 9 )
    result = (unsigned int)this->m_extra.m_size;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 26
// RVA: 0xE5D8D0
const char *__fastcall hkTypeManager::Type::getTypeName(hkTypeManager::Type *this)
{
  const char *result; // rax

  if ( this->m_subType == 6 )
    result = this->m_extra.m_name;
  else
    result = 0i64;
  return result;
}

// File Line: 31
// RVA: 0xE5DC20
__int64 __fastcall hkTypeManager::Type::_calcHash(hkTypeManager::Type *cur)
{
  __int64 result; // rax

  LODWORD(result) = 0;
  do
  {
    result = (unsigned int)(-1640531535 * cur->m_subType) ^ __ROL4__(result, 1);
    if ( cur->m_subType == 6 )
    {
      result = (unsigned int)cur ^ (unsigned int)result;
    }
    else if ( cur->m_subType == 9 )
    {
      result = cur->m_extra.m_size ^ (unsigned int)result;
    }
    cur = cur->m_parent;
  }
  while ( cur );
  return result;
}

// File Line: 65
// RVA: 0xE5D8F0
unsigned int __fastcall hkTypeManager::Type::calcHash(hkTypeManager::Type *this)
{
  unsigned int result; // eax

  result = hkTypeManager::Type::_calcHash(this);
  if ( result == -1 )
    result = 2062676778;
  return result;
}

// File Line: 72
// RVA: 0xE5DC70
hkBool *__fastcall hkTypeManager::Type::_equals(hkTypeManager::Type *this, hkBool *result, hkTypeManager::Type *rhs)
{
  hkTypeManager::SubType v3; // er9
  hkBool *v4; // rax

  v3 = this->m_subType;
  if ( this->m_subType != rhs->m_subType || this->m_parent != rhs->m_parent )
  {
    result->m_bool = 0;
    v4 = result;
  }
  else if ( v3 == 6 )
  {
    result->m_bool = this->m_extra.m_name == rhs->m_extra.m_name;
    v4 = result;
  }
  else
  {
    if ( v3 == 9 )
      result->m_bool = this->m_extra.m_size == rhs->m_extra.m_size;
    else
      result->m_bool = 1;
    v4 = result;
  }
  return v4;
}

// File Line: 88
// RVA: 0xE5D880
hkTypeManager::Type *__fastcall hkTypeManager::Type::findTerminal(hkTypeManager::Type *this)
{
  hkTypeManager::Type *i; // rax

  for ( i = this->m_parent; i; i = i->m_parent )
    this = i;
  return this;
}

// File Line: 98
// RVA: 0xE5DA40
void __fastcall hkTypeManager::Type::asText(hkTypeManager::Type *cur, hkOstream *stream)
{
  hkOstream *v2; // rsi
  hkTypeManager::Type *v3; // rdi
  const char *v4; // rdx
  hkOstream *v5; // rcx
  const char *v6; // rbx
  hkOstream *v7; // rax
  hkOstream *v8; // rax

  if ( cur )
  {
    v2 = stream;
    v3 = cur;
    do
    {
      switch ( v3->m_subType )
      {
        case 0:
          v4 = "!";
          v5 = v2;
          goto LABEL_17;
        case 1:
          v4 = "void";
          v5 = v2;
          goto LABEL_17;
        case 2:
          v4 = "byte";
          v5 = v2;
          goto LABEL_17;
        case 3:
          v4 = "real";
          v5 = v2;
          goto LABEL_17;
        case 4:
          v4 = "int";
          v5 = v2;
          goto LABEL_17;
        case 5:
          v4 = "cstring";
          v5 = v2;
          goto LABEL_17;
        case 6:
          if ( hkTypeManager::Type::getTypeName(v3) )
          {
            v6 = hkTypeManager::Type::getTypeName(v3);
            v7 = hkOstream::operator<<(v2, "class ");
            v4 = v6;
LABEL_16:
            v5 = v7;
          }
          else
          {
            v4 = "homogeneous/variant class";
            v5 = v2;
          }
LABEL_17:
          hkOstream::operator<<(v5, v4);
          break;
        case 7:
          v4 = pattern;
          v5 = v2;
          goto LABEL_17;
        case 8:
          v4 = "[]";
          v5 = v2;
          goto LABEL_17;
        case 9:
          v8 = hkOstream::operator<<(v2, "{");
          v7 = hkOstream::operator<<(v8, v3->m_extra.m_size, (int)v8);
          v4 = "}";
          goto LABEL_16;
        default:
          break;
      }
      v3 = v3->m_parent;
    }
    while ( v3 );
  }
}

// File Line: 132
// RVA: 0xE5D910
void __fastcall hkTypeManager::Type::asText(hkTypeManager::Type *this, hkOstream *stream)
{
  hkTypeManager::Type::asText(this, stream);
}

// File Line: 137
// RVA: 0xE5D920
hkStringPtr *__fastcall hkTypeManager::Type::asString(hkTypeManager::Type *this, hkStringPtr *result)
{
  hkStringPtr *v2; // rdi
  hkTypeManager::Type *v3; // rbx
  int v4; // ecx
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+20h] [rbp-38h]
  hkOstream stream; // [rsp+30h] [rbp-28h]

  v2 = result;
  v3 = this;
  buf.m_data = 0i64;
  buf.m_size = 0;
  buf.m_capacityAndFlags = 2147483648;
  hkOstream::hkOstream(&stream, &buf);
  hkTypeManager::Type::asText(v3, &stream);
  v4 = buf.m_size;
  if ( buf.m_size == (buf.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &buf, 1);
    v4 = buf.m_size;
  }
  buf.m_data[v4] = 0;
  ++buf.m_size;
  hkStringPtr::hkStringPtr(v2, buf.m_data);
  hkOstream::~hkOstream(&stream);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
  return v2;
}

// File Line: 149
// RVA: 0xE5DBB0
void __fastcall hkTypeManager::Type::getTypePath(hkTypeManager::Type *type, hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> *types)
{
  hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> *v2; // rbx
  hkTypeManager::Type *v3; // rdi

  v2 = types;
  v3 = type;
  for ( types->m_size = 0; v3; v3 = v3->m_parent )
  {
    if ( v2->m_size == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
    v2->m_data[v2->m_size++] = v3;
  }
}

// File Line: 159
// RVA: 0xE5DCD0
hkBool *__fastcall hkTypeManager::Type::_isEqual(hkBool *result, hkTypeManager::Type *a, hkTypeManager::Type *b)
{
  hkTypeManager::Type *v3; // rsi
  hkTypeManager::Type *v4; // rdi
  hkBool *i; // r14
  hkTypeManager::SubType v6; // eax
  int v7; // ebx
  bool v8; // zf
  const char *v9; // rbx
  const char *v10; // rax
  bool v11; // zf
  char v12; // al

  v3 = b;
  v4 = a;
  for ( i = result; v4; v3 = v3->m_parent )
  {
    if ( !v3 )
    {
      v11 = v4 == 0i64;
      goto LABEL_13;
    }
    v6 = v4->m_subType;
    if ( v4->m_subType != v3->m_subType )
      goto LABEL_15;
    if ( v6 == 6 )
    {
      v9 = hkTypeManager::Type::getTypeName(v4);
      v10 = hkTypeManager::Type::getTypeName(v3);
      if ( !v9 || !v10 )
      {
        i->m_bool = 1;
        return i;
      }
      v8 = (unsigned int)hkString::strCmp(v9, v10) == 0;
    }
    else
    {
      if ( v6 != 9 )
        goto LABEL_11;
      v7 = hkTypeManager::Type::getTupleSize(v4);
      v8 = v7 == (unsigned int)hkTypeManager::Type::getTupleSize(v3);
    }
    if ( !v8 )
    {
LABEL_15:
      i->m_bool = 0;
      return i;
    }
LABEL_11:
    v4 = v4->m_parent;
  }
  v11 = v3 == 0i64;
LABEL_13:
  v12 = v11 != 0;
  i->m_bool = v12;
  return i;
}

// File Line: 205
// RVA: 0xE5DA00
hkBool *__fastcall hkTypeManager::Type::isEqual(hkTypeManager::Type *this, hkBool *result, hkTypeManager::Type *type)
{
  hkBool *v3; // rbx
  hkBool *v4; // rax

  v3 = result;
  if ( type == this )
  {
    result->m_bool = 1;
    v4 = result;
  }
  else
  {
    hkTypeManager::Type::_isEqual(result, this, type);
    v4 = v3;
  }
  return v4;
}

// File Line: 222
// RVA: 0xE5F030
void __fastcall hkTypeManager::hkTypeManager(hkTypeManager *this)
{
  hkTypeManager *v1; // rsi
  hkTypeManager::Type *v2; // rbx
  unsigned __int64 v3; // rdx
  unsigned int v4; // eax

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTypeManager::`vftable;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_classMap.m_map,
    0);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v1->m_typeMultiMap.m_map);
  hkFreeList::hkFreeList(&v1->m_typeFreeList, 0x18ui64, 8ui64, 0x800ui64, 0i64, 0i64);
  hkString::memSet(v1->m_builtInTypes, 0, 80);
  hkTypeManager::_addBuiltIn(v1, SUB_TYPE_VOID);
  hkTypeManager::_addBuiltIn(v1, SUB_TYPE_INT);
  hkTypeManager::_addBuiltIn(v1, SUB_TYPE_REAL);
  hkTypeManager::_addBuiltIn(v1, SUB_TYPE_CSTRING);
  hkTypeManager::_addBuiltIn(v1, SUB_TYPE_BYTE);
  v2 = (hkTypeManager::Type *)v1->m_typeFreeList.m_free;
  if ( v1->m_typeFreeList.m_free )
  {
    --v1->m_typeFreeList.m_numFreeElements;
    v1->m_typeFreeList.m_free = *(hkFreeList::Element **)&v2->m_subType;
  }
  else
  {
    v2 = (hkTypeManager::Type *)v1->m_typeFreeList.m_top;
    if ( (char *)v2 < v1->m_typeFreeList.m_blockEnd )
    {
      v3 = v1->m_typeFreeList.m_elementSize;
      --v1->m_typeFreeList.m_numFreeElements;
      v1->m_typeFreeList.m_top = (char *)v2 + v3;
    }
    else
    {
      v2 = (hkTypeManager::Type *)hkFreeList::addSpace(&v1->m_typeFreeList);
    }
  }
  v2->m_subType = 6;
  v2->m_parent = 0i64;
  v2->m_extra.m_name = 0i64;
  v4 = hkTypeManager::Type::calcHash(v2);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
    &v1->m_typeMultiMap.m_map,
    v4,
    (unsigned __int64)v2);
  v1->m_homogenousClass = v2;
}

// File Line: 246
// RVA: 0xE5F180
void __fastcall hkTypeManager::~hkTypeManager(hkTypeManager *this)
{
  hkTypeManager *v1; // rdi
  hkFreeList *v2; // rcx

  v1 = this;
  v2 = &this->m_typeFreeList;
  v2[-2].m_elementAllocator = (hkMemoryAllocator *)&hkTypeManager::`vftable;
  hkFreeList::freeAllMemory(v2);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&v1->m_typeMultiMap.m_map);
  hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear((hkStorageStringMap<int,hkContainerHeapAllocator> *)&v1->m_classMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_classMap.m_map);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 250
// RVA: 0xE5F1E0
hkTypeManager::Type *__fastcall hkTypeManager::_addBuiltIn(hkTypeManager *this, hkTypeManager::SubType subType)
{
  __int64 v2; // rbx
  hkTypeManager *v3; // rdi
  hkTypeManager::Type *result; // rax
  hkTypeManager::Type typeIn; // [rsp+20h] [rbp-28h]

  v2 = subType;
  v3 = this;
  typeIn.m_subType = subType;
  typeIn.m_parent = 0i64;
  typeIn.m_extra.m_name = 0i64;
  result = hkTypeManager::_addType(this, &typeIn);
  v3->m_builtInTypes[v2] = result;
  return result;
}

// File Line: 263
// RVA: 0xE5F220
hkTypeManager::Type *__fastcall hkTypeManager::_addType(hkTypeManager *this, hkTypeManager::Type *typeIn)
{
  hkTypeManager *v2; // r13
  hkTypeManager::Type *v3; // r12
  unsigned int v4; // eax
  unsigned __int64 v5; // rdi
  int v6; // eax
  int v7; // er15
  int v8; // ebx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v9; // rbp
  hkTypeManager::Type *v10; // rsi
  __int64 v11; // r10
  int v12; // er8
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v14; // rax
  hkFreeList *v15; // rcx
  hkTypeManager::Type *v16; // rbx
  hkTypeManager::Type *v17; // rax
  unsigned __int64 v18; // r8
  hkBool result; // [rsp+50h] [rbp+8h]

  v2 = this;
  v3 = typeIn;
  v4 = hkTypeManager::Type::calcHash(typeIn);
  v5 = v4;
  v6 = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
         &v2->m_typeMultiMap.m_map,
         v4);
  v7 = v2->m_typeMultiMap.m_map.m_hashMod;
  v8 = v6;
  if ( v6 > v7 )
  {
LABEL_14:
    v15 = &v2->m_typeFreeList;
    v16 = (hkTypeManager::Type *)v2->m_typeFreeList.m_free;
    if ( v16 )
    {
      --v2->m_typeFreeList.m_numFreeElements;
      v15->m_free = *(hkFreeList::Element **)&v16->m_subType;
    }
    else
    {
      v16 = (hkTypeManager::Type *)v2->m_typeFreeList.m_top;
      if ( (char *)v16 < v2->m_typeFreeList.m_blockEnd )
      {
        v18 = v2->m_typeFreeList.m_elementSize;
        --v2->m_typeFreeList.m_numFreeElements;
        v2->m_typeFreeList.m_top = (char *)v16 + v18;
      }
      else
      {
        v16 = (hkTypeManager::Type *)hkFreeList::addSpace(v15);
      }
    }
    *(_QWORD *)&v16->m_subType = *(_QWORD *)&v3->m_subType;
    v16->m_parent = v3->m_parent;
    v16->m_extra.m_name = v3->m_extra.m_name;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
      &v2->m_typeMultiMap.m_map,
      v5,
      (unsigned __int64)v16);
    v17 = v16;
  }
  else
  {
    v9 = v2->m_typeMultiMap.m_map.m_elem;
    while ( 1 )
    {
      v10 = (hkTypeManager::Type *)v9[v8].val;
      if ( hkTypeManager::Type::_equals(v3, &result, (hkTypeManager::Type *)v9[v8].val)->m_bool )
        break;
      v11 = v2->m_typeMultiMap.m_map.m_hashMod;
      v12 = v8 + 1;
      for ( i = v8 + 1; i > v11; i = 0i64 )
LABEL_10:
        v12 = 0;
      v14 = &v9[i];
      while ( v14->key != -1i64 )
      {
        if ( v14->key == v5 )
        {
          v8 = v12;
          goto LABEL_13;
        }
        ++i;
        ++v12;
        ++v14;
        if ( i > v11 )
          goto LABEL_10;
      }
      v8 = v11 + 1;
LABEL_13:
      if ( v8 > v7 )
        goto LABEL_14;
    }
    v17 = v10;
  }
  return v17;
}

// File Line: 289
// RVA: 0xE5DFE0
void __fastcall hkTypeManager::findTypesUsingClass(hkTypeManager *this, hkTypeManager::Type *clsType, hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> *types)
{
  int v3; // er10
  hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> *v4; // rdi
  hkTypeManager::Type *v5; // r14
  __int64 v6; // r8
  hkTypeManager *v7; // rbp
  __int64 v8; // r9
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v9; // rax
  int v10; // ebx
  hkTypeManager::Type *v11; // rsi
  __int64 v12; // r8
  int v13; // edx
  __int64 v14; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v15; // rax

  v3 = 0;
  v4 = types;
  v5 = clsType;
  types->m_size = 0;
  v6 = this->m_typeMultiMap.m_map.m_hashMod;
  v7 = this;
  v8 = 0i64;
  if ( v6 >= 0 )
  {
    v9 = this->m_typeMultiMap.m_map.m_elem;
    do
    {
      if ( v9->key != -1i64 )
        break;
      ++v8;
      ++v3;
      ++v9;
    }
    while ( v8 <= v6 );
  }
  v10 = v3;
  if ( v3 <= this->m_typeMultiMap.m_map.m_hashMod )
  {
    do
    {
      v11 = (hkTypeManager::Type *)v7->m_typeMultiMap.m_map.m_elem[v10].val;
      if ( hkTypeManager::Type::findTerminal(v11) == v5 )
      {
        if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
        v4->m_data[v4->m_size++] = v11;
      }
      v12 = v7->m_typeMultiMap.m_map.m_hashMod;
      v13 = v10 + 1;
      v14 = v10 + 1;
      if ( v14 <= v12 )
      {
        v15 = &v7->m_typeMultiMap.m_map.m_elem[v13];
        do
        {
          if ( v15->key != -1i64 )
            break;
          ++v14;
          ++v13;
          ++v15;
        }
        while ( v14 <= v12 );
      }
      v10 = v13;
    }
    while ( v13 <= v7->m_typeMultiMap.m_map.m_hashMod );
  }
}

// File Line: 307
// RVA: 0xE5DEC0
void __fastcall hkTypeManager::renameClass(hkTypeManager *this, const char *clsName, const char *newName)
{
  const char *v3; // rsi
  const char *v4; // rbp
  hkTypeManager *v5; // rbx
  hkTypeManager::Type *v6; // rdi
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v7; // rbx
  Dummy *v8; // rbp
  char *v9; // rax
  Dummy *v10; // rbp
  char *v11; // rsi
  hkBool result; // [rsp+48h] [rbp+20h]

  v3 = newName;
  v4 = clsName;
  v5 = this;
  v6 = hkTypeManager::getClass(this, clsName);
  if ( v6 && !hkTypeManager::getClass(v5, v3) )
  {
    v7 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5->m_classMap;
    v8 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(v7, (unsigned __int64)v4);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v7, &result, v8);
    if ( result.m_bool )
    {
      v9 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                     (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v7,
                     v8);
      hkString::strFree(v9, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
        (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v7,
        v8);
    }
    v10 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(v7, (unsigned __int64)v3);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v7, &result, v10);
    if ( result.m_bool )
    {
      v11 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v7,
                      v10);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
        (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v7,
        v10,
        (unsigned __int64)v6);
    }
    else
    {
      v11 = hkString::strDup(v3, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v7,
        (unsigned __int64)v11,
        (unsigned __int64)v6);
    }
    v6->m_extra.m_name = v11;
  }
}

// File Line: 329
// RVA: 0xE5E110
void __fastcall hkTypeManager::removeClass(hkTypeManager *this, hkTypeManager::Type *clsType)
{
  hkTypeManager *v2; // r13
  hkTypeManager::Type *v3; // rbx
  __int64 v4; // r14
  const char *v5; // r12
  int v6; // ecx
  int v7; // ebx
  int v8; // esi
  __int64 v9; // rbx
  __int64 v10; // rdi
  unsigned int v11; // eax
  int v12; // edi
  __int64 v13; // rsi
  __int64 v14; // rbx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v15; // rbx
  Dummy *v16; // rdi
  char *v17; // rax
  hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> types; // [rsp+30h] [rbp-40h]
  char *array; // [rsp+40h] [rbp-30h]
  int v20; // [rsp+48h] [rbp-28h]
  int v21; // [rsp+4Ch] [rbp-24h]
  hkResult result; // [rsp+80h] [rbp+10h]

  v2 = this;
  v3 = clsType;
  v4 = 0i64;
  types.m_data = 0i64;
  v5 = hkTypeManager::Type::getTypeName(clsType);
  types.m_size = 0;
  types.m_capacityAndFlags = 2147483648;
  hkTypeManager::findTypesUsingClass(v2, v3, &types);
  v6 = types.m_size;
  array = 0i64;
  v20 = 0;
  v21 = 2147483648;
  v7 = types.m_size;
  if ( types.m_size > 0 )
  {
    if ( types.m_size < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v6, 4);
    v6 = types.m_size;
  }
  v20 = v7;
  v8 = 0;
  if ( v6 > 0 )
  {
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      v11 = hkTypeManager::Type::calcHash(types.m_data[v10]);
      ++v8;
      *(_DWORD *)&array[v9] = v11;
      v6 = types.m_size;
      ++v10;
      v9 += 4i64;
    }
    while ( v8 < types.m_size );
  }
  v12 = 0;
  if ( v6 > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = *(__int64 *)((char *)types.m_data + v4);
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
        &v2->m_typeMultiMap.m_map,
        &result,
        *(unsigned int *)&array[v13],
        *(unsigned __int64 *)((char *)types.m_data + v4));
      ++v12;
      *(_DWORD *)v14 = 0;
      *(_QWORD *)(v14 + 8) = 0i64;
      v4 += 8i64;
      v13 += 4i64;
    }
    while ( v12 < types.m_size );
    LODWORD(v4) = 0;
  }
  v15 = &v2->m_classMap.m_map;
  v16 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classMap,
          (unsigned __int64)v5);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classMap,
    (hkBool *)&result,
    v16);
  if ( LOBYTE(result.m_enum) )
  {
    v17 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(v15, v16);
    hkString::strFree(v17, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(v15, v16);
  }
  v20 = v4;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v21);
  array = 0i64;
  types.m_size = 0;
  v21 = 2147483648;
  if ( types.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      types.m_data,
      8 * types.m_capacityAndFlags);
}

// File Line: 364
// RVA: 0xE5F400
void __fastcall freeListCallback(void *start, unsigned __int64 size, bool allocated, int pool, void *param)
{
  void *v5; // rdi

  if ( allocated )
  {
    v5 = start;
    if ( !*(_DWORD *)start )
    {
      if ( *((_DWORD *)param + 2) == (*((_DWORD *)param + 3) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, param, 8);
      *(_QWORD *)(*(_QWORD *)param + 8i64 * (signed int)(*((_DWORD *)param + 2))++) = v5;
    }
  }
}

// File Line: 377
// RVA: 0xE5E540
void __fastcall hkTypeManager::garbageCollect(hkTypeManager *this)
{
  hkFreeList *v1; // rbx
  int v2; // er8
  __int64 v3; // rcx
  hkFreeList::Element *v4; // rdx
  hkFreeList::Element *v5; // rax
  char *param; // [rsp+20h] [rbp-18h]
  int v7; // [rsp+28h] [rbp-10h]
  int v8; // [rsp+2Ch] [rbp-Ch]

  v1 = &this->m_typeFreeList;
  param = 0i64;
  v7 = 0;
  v8 = 2147483648;
  hkFreeList::walkMemory(&this->m_typeFreeList, freeListCallback, 0, &param);
  v2 = 0;
  if ( v7 > 0 )
  {
    v3 = 0i64;
    do
    {
      ++v2;
      v3 += 8i64;
      v4 = *(hkFreeList::Element **)&param[v3 - 8];
      v5 = v1->m_free;
      ++v1->m_numFreeElements;
      v4->m_next = v5;
      v1->m_free = v4;
    }
    while ( v2 < v7 );
  }
  hkFreeList::findGarbage(v1);
  hkFreeList::freeAllFreeBlocks(v1);
  v7 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      param,
      8 * v8);
}

// File Line: 390
// RVA: 0xE5E610
hkTypeManager::Type *__fastcall hkTypeManager::makePointer(hkTypeManager *this, hkTypeManager::Type *parent)
{
  hkTypeManager::Type typeIn; // [rsp+20h] [rbp-28h]

  typeIn.m_parent = parent;
  typeIn.m_subType = 7;
  typeIn.m_extra.m_name = 0i64;
  return hkTypeManager::_addType(this, &typeIn);
}

// File Line: 402
// RVA: 0xE5E640
hkTypeManager::Type *__fastcall hkTypeManager::makeArray(hkTypeManager *this, hkTypeManager::Type *parent)
{
  hkTypeManager::Type typeIn; // [rsp+20h] [rbp-28h]

  typeIn.m_parent = parent;
  typeIn.m_subType = 8;
  return hkTypeManager::_addType(this, &typeIn);
}

// File Line: 413
// RVA: 0xE5E670
hkTypeManager::Type *__fastcall hkTypeManager::makeTuple(hkTypeManager *this, hkTypeManager::Type *parent, int tupleSize)
{
  hkTypeManager::Type typeIn; // [rsp+20h] [rbp-28h]

  typeIn.m_parent = parent;
  typeIn.m_subType = 9;
  typeIn.m_extra.m_size = tupleSize;
  return hkTypeManager::_addType(this, &typeIn);
}

// File Line: 426
// RVA: 0xE5F380
hkBool *__fastcall hkTypeManager::_isValidClassName(hkBool *result, const char *name)
{
  hkBool *v2; // r8
  unsigned __int8 v3; // al
  signed __int64 v4; // rcx
  unsigned __int64 v5; // rcx
  const char *v6; // rdx
  signed __int64 v7; // r9
  hkBool *v8; // rax

  v2 = result;
  if ( name && *name )
  {
    v3 = *name - 65;
    if ( v3 <= 0x39u )
    {
      v4 = 288230372997595135i64;
      if ( _bittest64(&v4, (char)v3) )
      {
        v5 = *((unsigned __int8 *)name + 1);
        v6 = name + 1;
        if ( !(_BYTE)v5 )
        {
LABEL_11:
          v2->m_bool = 1;
          return v2;
        }
        v7 = 149533581248511i64;
        while ( 1 )
        {
          if ( (unsigned __int8)(v5 - 97) > 0x19u )
          {
            LOBYTE(v5) = v5 - 48;
            if ( (unsigned __int8)v5 > 0x2Fu || !_bittest64(&v7, v5) )
              break;
          }
          v5 = *((unsigned __int8 *)v6++ + 1);
          if ( !(_BYTE)v5 )
            goto LABEL_11;
        }
      }
    }
    v2->m_bool = 0;
    v8 = v2;
  }
  else
  {
    result->m_bool = 0;
    v8 = result;
  }
  return v8;
}

// File Line: 465
// RVA: 0xE5E320
hkTypeManager::Type *__fastcall hkTypeManager::getClass(hkTypeManager *this, const char *clsName)
{
  return (hkTypeManager::Type *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classMap,
                                  (unsigned __int64)clsName,
                                  0i64);
}

// File Line: 470
// RVA: 0xE5DDA0
hkTypeManager::Type *__fastcall hkTypeManager::addClass(hkTypeManager *this, const char *clsName)
{
  const char *v2; // rbp
  hkTypeManager *v3; // rdi
  hkTypeManager::Type *v4; // rax
  hkTypeManager::Type *v5; // rbx
  unsigned __int64 v6; // rcx
  Dummy *v7; // r14
  char *v8; // rbp
  unsigned int v9; // eax
  hkBool result; // [rsp+50h] [rbp+18h]

  v2 = clsName;
  v3 = this;
  v4 = hkTypeManager::getClass(this, clsName);
  if ( !v4 )
  {
    v5 = (hkTypeManager::Type *)v3->m_typeFreeList.m_free;
    if ( v5 )
    {
      --v3->m_typeFreeList.m_numFreeElements;
      v3->m_typeFreeList.m_free = *(hkFreeList::Element **)&v5->m_subType;
    }
    else
    {
      v5 = (hkTypeManager::Type *)v3->m_typeFreeList.m_top;
      if ( (char *)v5 < v3->m_typeFreeList.m_blockEnd )
      {
        v6 = v3->m_typeFreeList.m_elementSize;
        --v3->m_typeFreeList.m_numFreeElements;
        v3->m_typeFreeList.m_top = (char *)v5 + v6;
      }
      else
      {
        v5 = (hkTypeManager::Type *)hkFreeList::addSpace(&v3->m_typeFreeList);
      }
    }
    v5->m_subType = 6;
    v5->m_parent = 0i64;
    v7 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_classMap,
           (unsigned __int64)v2);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_classMap,
      &result,
      v7);
    if ( result.m_bool )
    {
      v8 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&v3->m_classMap.m_map, v7);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
        &v3->m_classMap.m_map,
        v7,
        (unsigned __int64)v5);
    }
    else
    {
      v8 = hkString::strDup(v2, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v3->m_classMap.m_map,
        (unsigned __int64)v8,
        (unsigned __int64)v5);
    }
    v5->m_extra.m_name = v8;
    v9 = hkTypeManager::Type::calcHash(v5);
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
      &v3->m_typeMultiMap.m_map,
      v9,
      (unsigned __int64)v5);
    v4 = v5;
  }
  return v4;
}

// File Line: 493
// RVA: 0xE5E6F0
hkTypeManager::Type *__fastcall hkTypeManager::replaceParent(hkTypeManager *this, hkTypeManager::Type *typeIn, hkTypeManager::Type *parent)
{
  hkTypeManager::Type *v3; // rbx
  hkTypeManager *v4; // rdi
  int v6; // eax

  v3 = parent;
  v4 = this;
  if ( typeIn->m_parent == parent )
    return typeIn;
  if ( typeIn->m_subType == 7 )
    return hkTypeManager::makePointer(this, parent);
  if ( typeIn->m_subType == 8 )
    return hkTypeManager::makeArray(this, parent);
  if ( typeIn->m_subType != 9 )
    return 0i64;
  v6 = hkTypeManager::Type::getTupleSize(typeIn);
  return hkTypeManager::makeTuple(v4, v3, v6);
}

// File Line: 513
// RVA: 0xE5E780
hkTypeManager::Type *__fastcall hkTypeManager::replaceTerminal(hkTypeManager *this, hkTypeManager::Type *typeIn, hkTypeManager::Type *newTerminal)
{
  hkTypeManager::Type *v3; // rdi
  int v4; // edx
  signed int v5; // eax
  hkTypeManager::Type *v6; // rsi
  hkTypeManager *v7; // rbp
  hkTypeManager::Type *v8; // rbx
  char *v9; // rcx
  __int64 j; // rbx
  hkTypeManager::Type *v11; // rax
  char *array; // [rsp+20h] [rbp-98h]
  int v14; // [rsp+28h] [rbp-90h]
  int i; // [rsp+2Ch] [rbp-8Ch]
  char v16; // [rsp+30h] [rbp-88h]

  v3 = typeIn;
  v4 = 0;
  array = &v16;
  v5 = -2147483632;
  v6 = newTerminal;
  v7 = this;
  v14 = 0;
  v8 = v3;
  for ( i = -2147483632; ; v5 = i )
  {
    if ( v4 == (v5 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
      v4 = v14;
    }
    *(_QWORD *)&array[8 * v4] = v8;
    v4 = v14++ + 1;
    v8 = v8->m_parent;
    if ( !v8 )
      break;
  }
  v9 = array;
  if ( *(hkTypeManager::Type **)&array[8 * v4 - 8] != v6 )
  {
    v3 = v6;
    for ( j = v4 - 1; j >= 0; v3 = v11 )
    {
      v11 = hkTypeManager::replaceParent(v7, *(hkTypeManager::Type **)&v9[8 * j--], v3);
      v9 = array;
    }
  }
  v14 = 0;
  if ( i >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc, v9, 8 * i);
  return v3;
}

// File Line: 541
// RVA: 0xE5E6A0
hkTypeManager::Type *__fastcall hkTypeManager::makeArray(hkTypeManager *this, hkTypeManager::SubType subType)
{
  hkTypeManager::Type *v2; // rdx
  hkTypeManager::Type *result; // rax

  v2 = this->m_builtInTypes[subType];
  if ( v2 )
    result = hkTypeManager::makeArray(this, v2);
  else
    result = 0i64;
  return result;
}

// File Line: 551
// RVA: 0xE5E6C0
hkTypeManager::Type *__fastcall hkTypeManager::getClassPointer(hkTypeManager *this, const char *name)
{
  hkTypeManager *v2; // rbx
  hkTypeManager::Type *v3; // rax

  v2 = this;
  v3 = hkTypeManager::addClass(this, name);
  return hkTypeManager::makePointer(v2, v3);
}

// File Line: 556
// RVA: 0xE5E340
hkBool *__fastcall hkTypeManager::isOwned(hkTypeManager *this, hkBool *result, hkTypeManager::Type *type)
{
  hkTypeManager *v3; // rbx
  hkTypeManager::Type *v4; // rbp
  hkBool *v5; // rsi
  unsigned int v6; // eax
  signed __int64 v7; // r14
  __int64 v8; // rdi
  int v9; // eax
  int v10; // ebx
  __int64 v11; // r10
  __int64 v12; // r11
  int v13; // er8
  __int64 i; // rcx
  _QWORD *v15; // rax

  v3 = this;
  v4 = type;
  v5 = result;
  v6 = hkTypeManager::Type::calcHash(type);
  v7 = (signed __int64)&v3->m_typeMultiMap;
  v8 = v6;
  v9 = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
         &v3->m_typeMultiMap.m_map,
         v6);
  v10 = v3->m_typeMultiMap.m_map.m_hashMod;
  if ( v9 > v10 )
  {
LABEL_14:
    v5->m_bool = 0;
  }
  else
  {
    v11 = *(_QWORD *)v7;
    while ( *(hkTypeManager::Type **)(v11 + 16i64 * v9 + 8) != v4 )
    {
      v12 = *(signed int *)(v7 + 12);
      v13 = v9 + 1;
      for ( i = v9 + 1; i > v12; i = 0i64 )
LABEL_10:
        v13 = 0;
      v15 = (_QWORD *)(v11 + 16 * i);
      while ( *v15 != -1i64 )
      {
        if ( *v15 == v8 )
        {
          v9 = v13;
          goto LABEL_13;
        }
        ++i;
        ++v13;
        v15 += 2;
        if ( i > v12 )
          goto LABEL_10;
      }
      v9 = v12 + 1;
LABEL_13:
      if ( v9 > v10 )
        goto LABEL_14;
    }
    v5->m_bool = 1;
  }
  return v5;
}

// File Line: 577
// RVA: 0xE5E420
hkTypeManager::Type *__fastcall hkTypeManager::copyType(hkTypeManager *this, hkTypeManager::Type *type)
{
  hkTypeManager::Type *v2; // rbx
  hkTypeManager *v3; // rsi
  int v4; // edx
  hkTypeManager::Type *v5; // rcx
  __int64 v6; // rax
  const char *v7; // rax
  hkTypeManager::Type *v8; // rax
  __int64 i; // rdi
  hkTypeManager::Type *v10; // rax
  hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> types; // [rsp+20h] [rbp-98h]
  char v13; // [rsp+30h] [rbp-88h]
  hkBool result; // [rsp+D0h] [rbp+18h]

  v2 = type;
  v3 = this;
  if ( !hkTypeManager::isOwned(this, &result, type)->m_bool )
  {
    types.m_size = 0;
    types.m_capacityAndFlags = -2147483632;
    types.m_data = (hkTypeManager::Type **)&v13;
    hkTypeManager::Type::getTypePath(v2, &types);
    v4 = types.m_size;
    v5 = types.m_data[types.m_size - 1];
    v6 = v5->m_subType;
    if ( (_DWORD)v6 == 6 )
    {
      v7 = hkTypeManager::Type::getTypeName(v5);
      v8 = hkTypeManager::addClass(v3, v7);
      v4 = types.m_size;
      v2 = v8;
    }
    else
    {
      v2 = v3->m_builtInTypes[v6];
    }
    if ( v2 )
    {
      for ( i = v4 - 2; i >= 0; v2 = v10 )
        v10 = hkTypeManager::replaceParent(v3, types.m_data[i--], v2);
    }
    types.m_size = 0;
    if ( types.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        types.m_data,
        8 * types.m_capacityAndFlags);
  }
  return v2;
}

// File Line: 619
// RVA: 0xE5EB60
void __fastcall hkTypeManager::appendTypeExpression(hkTypeManager::Type *type, hkOstream *stream)
{
  hkOstream *v2; // rsi
  hkTypeManager::Type *v3; // rbx
  const char *v4; // rdx
  hkOstream *v5; // rcx
  const char *v6; // rdi
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  int v9; // edi
  hkOstream *v10; // rax

  if ( type )
  {
    v2 = stream;
    v3 = type;
    do
    {
      switch ( v3->m_subType )
      {
        case 0:
          v4 = "!";
          v5 = v2;
          goto LABEL_15;
        case 1:
          v4 = "v";
          v5 = v2;
          goto LABEL_15;
        case 2:
          v4 = "b";
          v5 = v2;
          goto LABEL_15;
        case 3:
          v4 = "r";
          v5 = v2;
          goto LABEL_15;
        case 4:
          v4 = "i";
          v5 = v2;
          goto LABEL_15;
        case 5:
          v4 = "s";
          v5 = v2;
          goto LABEL_15;
        case 6:
          v6 = hkTypeManager::Type::getTypeName(v3);
          v7 = hkOstream::operator<<(v2, "C");
          v8 = hkOstream::operator<<(v7, v6);
          v4 = ";";
          goto LABEL_14;
        case 7:
          v4 = pattern;
          v5 = v2;
          goto LABEL_15;
        case 8:
          v4 = "[]";
          v5 = v2;
          goto LABEL_15;
        case 9:
          v9 = hkTypeManager::Type::getTupleSize(v3);
          v10 = hkOstream::operator<<(v2, "{");
          v8 = hkOstream::operator<<(v10, v9, (int)v10);
          v4 = "}";
LABEL_14:
          v5 = v8;
LABEL_15:
          hkOstream::operator<<(v5, v4);
          break;
        default:
          break;
      }
      v3 = v3->m_parent;
    }
    while ( v3 );
  }
}

// File Line: 642
// RVA: 0xE5E8A0
hkTypeManager::Type *__fastcall hkTypeManager::parseTypeExpression(hkTypeManager *this, const char *typeExpression)
{
  hkTypeManager *v2; // rsi
  hkTypeManager::Type *result; // rax
  hkTypeManager::Type *v4; // rax
  hkTypeManager::Type *v5; // rax
  char v6; // al
  const char *v7; // rdx
  const char *j; // rdi
  int v9; // ebx
  int v10; // ebx
  hkTypeManager::Type *v11; // rax
  const char *v12; // r9
  signed __int64 v13; // r8
  const char *i; // rdx
  unsigned __int64 v15; // rax
  int v16; // ebx
  char dst[16]; // [rsp+20h] [rbp-98h]
  char clsName[136]; // [rsp+30h] [rbp-88h]

  v2 = this;
  switch ( *typeExpression )
  {
    case 33:
      result = this->m_builtInTypes[0];
      break;
    case 42:
      v4 = hkTypeManager::parseTypeExpression(this, typeExpression + 1);
      result = hkTypeManager::makePointer(v2, v4);
      break;
    case 67:
      v12 = typeExpression + 1;
      v13 = 149533581248511i64;
      for ( i = typeExpression + 1; ; ++i )
      {
        v15 = *(unsigned __int8 *)i;
        if ( (unsigned __int8)(v15 - 97) > 0x19u )
        {
          LOBYTE(v15) = v15 - 48;
          if ( (unsigned __int8)v15 > 0x2Fu || !_bittest64(&v13, v15) )
            break;
        }
      }
      v16 = (_DWORD)i - (_DWORD)v12;
      if ( (unsigned int)((_DWORD)i - (_DWORD)v12 - 1) > 0x7E || *i != 59 )
        goto LABEL_26;
      hkString::strNcpy(clsName, v12, v16);
      clsName[v16] = 0;
      result = hkTypeManager::addClass(v2, clsName);
      break;
    case 91:
      v5 = hkTypeManager::parseTypeExpression(this, typeExpression + 2);
      result = hkTypeManager::makeArray(v2, v5);
      break;
    case 98:
      result = this->m_builtInTypes[2];
      break;
    case 105:
      result = this->m_builtInTypes[4];
      break;
    case 114:
      result = this->m_builtInTypes[3];
      break;
    case 115:
      result = this->m_builtInTypes[5];
      break;
    case 118:
      result = this->m_builtInTypes[1];
      break;
    case 123:
      v6 = typeExpression[1];
      v7 = typeExpression + 1;
      for ( j = v7; v6 >= 48; v6 = (j++)[1] )
      {
        if ( v6 > 57 )
          break;
      }
      v9 = (_DWORD)j - (_DWORD)v7;
      if ( (unsigned int)((_DWORD)j - (_DWORD)v7 - 1) > 8 || *j != 125 )
      {
        result = 0i64;
      }
      else
      {
        hkString::strNcpy(dst, v7, v9);
        dst[v9] = 0;
        v10 = hkString::atoi(dst, 0);
        v11 = hkTypeManager::parseTypeExpression(v2, j + 1);
        result = hkTypeManager::makeTuple(v2, v11, v10);
      }
      break;
    default:
LABEL_26:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 725
// RVA: 0xE5ECD0
hkTypeManager::Type *__fastcall hkTypeManager::getType(hkTypeManager *this, hkLegacyType::Type type, const char *className, int tupleSize)
{
  int v4; // esi
  char v5; // di
  hkTypeManager *v6; // rbx
  hkTypeManager::Type *result; // rax
  hkTypeManager::Type *v8; // rax

  v4 = tupleSize;
  v5 = type;
  v6 = this;
  switch ( type & 0xF )
  {
    case 0:
      result = this->m_builtInTypes[1];
      goto LABEL_17;
    case 1:
      result = this->m_builtInTypes[2];
      goto LABEL_17;
    case 2:
      result = this->m_builtInTypes[4];
      goto LABEL_17;
    case 3:
      result = this->m_builtInTypes[3];
      goto LABEL_17;
    case 4:
      result = hkTypeManager::makeTuple(this, this->m_builtInTypes[3], 4);
      goto LABEL_17;
    case 5:
      result = hkTypeManager::makeTuple(this, this->m_builtInTypes[3], 8);
      goto LABEL_17;
    case 6:
      result = hkTypeManager::makeTuple(this, this->m_builtInTypes[3], 12);
      goto LABEL_17;
    case 7:
      result = hkTypeManager::makeTuple(this, this->m_builtInTypes[3], 16);
      goto LABEL_17;
    case 8:
      if ( className )
      {
        v8 = hkTypeManager::addClass(this, className);
        result = hkTypeManager::makePointer(v6, v8);
      }
      else
      {
        result = hkTypeManager::makePointer(this, this->m_homogenousClass);
      }
      goto LABEL_17;
    case 9:
      if ( className )
        result = hkTypeManager::addClass(this, className);
      else
        result = this->m_homogenousClass;
      goto LABEL_17;
    case 0xA:
      result = this->m_builtInTypes[5];
LABEL_17:
      if ( !result )
        goto LABEL_22;
      if ( v5 & 0x10 )
      {
        result = hkTypeManager::makeArray(v6, result);
      }
      else if ( v5 & 0x20 )
      {
        result = hkTypeManager::makeTuple(v6, result, v4);
      }
      break;
    default:
LABEL_22:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 804
// RVA: 0xE5EE60
signed __int64 __fastcall hkTypeManager::getTerminalLegacyType(hkTypeManager::Type *type, const char **classNameOut)
{
  signed __int64 result; // rax
  hkTypeManager::Type *v3; // rcx
  int v4; // eax

  *classNameOut = 0i64;
  switch ( type->m_subType )
  {
    case 2:
      result = 1i64;
      break;
    case 3:
      result = 3i64;
      break;
    case 4:
      result = 2i64;
      break;
    case 5:
      result = 10i64;
      break;
    case 6:
      *classNameOut = hkTypeManager::Type::getTypeName(type);
      result = 9i64;
      break;
    case 7:
      v3 = type->m_parent;
      if ( v3->m_subType != 6 )
        goto $LN1_69;
      *classNameOut = hkTypeManager::Type::getTypeName(v3);
      result = 8i64;
      break;
    case 9:
      if ( type->m_parent->m_subType != 3 )
        goto $LN1_69;
      v4 = hkTypeManager::Type::getTupleSize(type);
      switch ( v4 )
      {
        case 4:
          result = 4i64;
          break;
        case 8:
          result = 5i64;
          break;
        case 12:
          result = 6i64;
          break;
        case 16:
          result = 7i64;
          break;
        default:
          goto $LN1_69;
      }
      break;
    default:
$LN1_69:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 853
// RVA: 0xE5EF80
signed __int64 __fastcall hkTypeManager::getLegacyType(hkTypeManager::Type *type, const char **className, int *numTupleOut)
{
  hkTypeManager::Type *v3; // rbx
  const char **v4; // rdi
  __int32 v5; // ecx

  v3 = type;
  *className = 0i64;
  *numTupleOut = 0;
  v4 = className;
  v5 = type->m_subType - 8;
  if ( !v5 )
    return (unsigned int)hkTypeManager::getTerminalLegacyType(v3->m_parent, className) | 0x10;
  if ( v5 != 1 || v3->m_parent->m_subType == 3 && !((v3->m_extra.m_size - 4) & 0xFFFFFFF3) )
    return hkTypeManager::getTerminalLegacyType(v3, className);
  *numTupleOut = hkTypeManager::Type::getTupleSize(v3);
  return (unsigned int)hkTypeManager::getTerminalLegacyType(v3->m_parent, v4) | 0x20;
}

