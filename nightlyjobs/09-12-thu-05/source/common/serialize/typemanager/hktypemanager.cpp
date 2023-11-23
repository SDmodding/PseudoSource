// File Line: 21
// RVA: 0xE5D8B0
__int64 __fastcall hkTypeManager::Type::getTupleSize(hkTypeManager::Type *this)
{
  if ( this->m_subType == SUB_TYPE_TUPLE )
    return (unsigned int)this->m_extra.m_size;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 26
// RVA: 0xE5D8D0
const char *__fastcall hkTypeManager::Type::getTypeName(hkTypeManager::Type *this)
{
  if ( this->m_subType == SUB_TYPE_CLASS )
    return this->m_extra.m_name;
  else
    return 0i64;
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
    if ( cur->m_subType == SUB_TYPE_CLASS )
    {
      result = (unsigned int)cur ^ (unsigned int)result;
    }
    else if ( cur->m_subType == SUB_TYPE_TUPLE )
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
    return 2062676778;
  return result;
}

// File Line: 72
// RVA: 0xE5DC70
hkBool *__fastcall hkTypeManager::Type::_equals(hkTypeManager::Type *this, hkBool *result, hkTypeManager::Type *rhs)
{
  hkTypeManager::SubType m_subType; // r9d

  m_subType = this->m_subType;
  if ( this->m_subType == rhs->m_subType && this->m_parent == rhs->m_parent )
  {
    if ( m_subType == SUB_TYPE_CLASS )
    {
      result->m_bool = this->m_extra.m_name == rhs->m_extra.m_name;
      return result;
    }
    else
    {
      result->m_bool = m_subType != SUB_TYPE_TUPLE || this->m_extra.m_size == rhs->m_extra.m_size;
      return result;
    }
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
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
  hkTypeManager::Type *v3; // rdi
  const char *v4; // rdx
  hkOstream *v5; // rcx
  const char *TypeName; // rbx
  hkOstream *v7; // rax
  hkOstream *v8; // rax

  if ( cur )
  {
    v3 = cur;
    while ( 2 )
    {
      switch ( v3->m_subType )
      {
        case SUB_TYPE_INVALID:
          v4 = "!";
          v5 = stream;
          goto LABEL_17;
        case SUB_TYPE_VOID:
          v4 = "void";
          v5 = stream;
          goto LABEL_17;
        case SUB_TYPE_BYTE:
          v4 = "byte";
          v5 = stream;
          goto LABEL_17;
        case SUB_TYPE_REAL:
          v4 = "real";
          v5 = stream;
          goto LABEL_17;
        case SUB_TYPE_INT:
          v4 = "int";
          v5 = stream;
          goto LABEL_17;
        case SUB_TYPE_CSTRING:
          v4 = "cstring";
          v5 = stream;
          goto LABEL_17;
        case SUB_TYPE_CLASS:
          if ( hkTypeManager::Type::getTypeName(v3) )
          {
            TypeName = hkTypeManager::Type::getTypeName(v3);
            v7 = hkOstream::operator<<(stream, "class ");
            v4 = TypeName;
LABEL_16:
            v5 = v7;
          }
          else
          {
            v4 = "homogeneous/variant class";
            v5 = stream;
          }
LABEL_17:
          hkOstream::operator<<(v5, v4);
LABEL_18:
          v3 = v3->m_parent;
          if ( !v3 )
            return;
          continue;
        case SUB_TYPE_POINTER:
          v4 = pattern;
          v5 = stream;
          goto LABEL_17;
        case SUB_TYPE_ARRAY:
          v4 = "[]";
          v5 = stream;
          goto LABEL_17;
        case SUB_TYPE_TUPLE:
          v8 = hkOstream::operator<<(stream, "{");
          v7 = hkOstream::operator<<(v8, v3->m_extra.m_size);
          v4 = "}";
          goto LABEL_16;
        default:
          goto LABEL_18;
      }
    }
  }
}

// File Line: 132
// RVA: 0xE5D910
// attributes: thunk
void __fastcall hkTypeManager::Type::asText(hkTypeManager::Type *this, hkOstream *stream)
{
  ?asText@Type@hkTypeManager@@SAXPEBU12@AEAVhkOstream@@@Z(this, stream);
}

// File Line: 137
// RVA: 0xE5D920
hkStringPtr *__fastcall hkTypeManager::Type::asString(hkTypeManager::Type *this, hkStringPtr *result)
{
  int m_size; // ecx
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+20h] [rbp-38h] BYREF
  hkOstream stream; // [rsp+30h] [rbp-28h] BYREF

  buf.m_data = 0i64;
  buf.m_size = 0;
  buf.m_capacityAndFlags = 0x80000000;
  hkOstream::hkOstream(&stream, &buf);
  hkTypeManager::Type::asText(this, &stream);
  m_size = buf.m_size;
  if ( buf.m_size == (buf.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&buf.m_data, 1);
    m_size = buf.m_size;
  }
  buf.m_data[m_size] = 0;
  ++buf.m_size;
  hkStringPtr::hkStringPtr(result, buf.m_data);
  hkOstream::~hkOstream(&stream);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
  return result;
}

// File Line: 149
// RVA: 0xE5DBB0
void __fastcall hkTypeManager::Type::getTypePath(
        hkTypeManager::Type *type,
        hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> *types)
{
  hkTypeManager::Type *v3; // rdi

  v3 = type;
  for ( types->m_size = 0; v3; v3 = v3->m_parent )
  {
    if ( types->m_size == (types->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&types->m_data, 8);
    types->m_data[types->m_size++] = v3;
  }
}

// File Line: 159
// RVA: 0xE5DCD0
hkBool *__fastcall hkTypeManager::Type::_isEqual(hkBool *result, hkTypeManager::Type *a, hkTypeManager::Type *b)
{
  hkTypeManager::Type *i; // rdi
  hkTypeManager::SubType m_subType; // eax
  int TupleSize; // ebx
  bool v8; // zf
  const char *TypeName; // rbx
  const char *v10; // rax
  bool v11; // zf
  char v12; // al

  for ( i = a; i; b = b->m_parent )
  {
    if ( !b )
    {
      v11 = i == 0i64;
      goto LABEL_13;
    }
    m_subType = i->m_subType;
    if ( i->m_subType != b->m_subType )
      goto LABEL_15;
    if ( m_subType == SUB_TYPE_CLASS )
    {
      TypeName = hkTypeManager::Type::getTypeName(i);
      v10 = hkTypeManager::Type::getTypeName(b);
      if ( !TypeName || !v10 )
      {
        result->m_bool = 1;
        return result;
      }
      v8 = (unsigned int)hkString::strCmp(TypeName, v10) == 0;
    }
    else
    {
      if ( m_subType != SUB_TYPE_TUPLE )
        goto LABEL_11;
      TupleSize = hkTypeManager::Type::getTupleSize(i);
      v8 = TupleSize == (unsigned int)hkTypeManager::Type::getTupleSize(b);
    }
    if ( !v8 )
    {
LABEL_15:
      result->m_bool = 0;
      return result;
    }
LABEL_11:
    i = i->m_parent;
  }
  v11 = b == 0i64;
LABEL_13:
  v12 = v11;
  result->m_bool = v12;
  return result;
}

// File Line: 205
// RVA: 0xE5DA00
hkBool *__fastcall hkTypeManager::Type::isEqual(hkTypeManager::Type *this, hkBool *result, hkTypeManager::Type *type)
{
  if ( type == this )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    hkTypeManager::Type::_isEqual(result, this, type);
    return result;
  }
}

// File Line: 222
// RVA: 0xE5F030
void __fastcall hkTypeManager::hkTypeManager(hkTypeManager *this)
{
  hkFreeList::Element **p_m_next; // rbx
  unsigned __int64 m_elementSize; // rdx
  unsigned int v4; // eax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTypeManager::`vftable;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_classMap.m_map,
    0);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&this->m_typeMultiMap.m_map);
  hkFreeList::hkFreeList(&this->m_typeFreeList, 0x18ui64, 8ui64, 0x800ui64, 0i64, 0i64);
  hkString::memSet(this->m_builtInTypes, 0, 0x50u);
  hkTypeManager::_addBuiltIn(this, SUB_TYPE_VOID);
  hkTypeManager::_addBuiltIn(this, SUB_TYPE_INT);
  hkTypeManager::_addBuiltIn(this, SUB_TYPE_REAL);
  hkTypeManager::_addBuiltIn(this, SUB_TYPE_CSTRING);
  hkTypeManager::_addBuiltIn(this, SUB_TYPE_BYTE);
  p_m_next = &this->m_typeFreeList.m_free->m_next;
  if ( p_m_next )
  {
    --this->m_typeFreeList.m_numFreeElements;
    this->m_typeFreeList.m_free = *p_m_next;
  }
  else
  {
    p_m_next = (hkFreeList::Element **)this->m_typeFreeList.m_top;
    if ( (char *)p_m_next < this->m_typeFreeList.m_blockEnd )
    {
      m_elementSize = this->m_typeFreeList.m_elementSize;
      --this->m_typeFreeList.m_numFreeElements;
      this->m_typeFreeList.m_top = (char *)p_m_next + m_elementSize;
    }
    else
    {
      p_m_next = (hkFreeList::Element **)hkFreeList::addSpace(&this->m_typeFreeList);
    }
  }
  *(_DWORD *)p_m_next = 6;
  p_m_next[1] = 0i64;
  p_m_next[2] = 0i64;
  v4 = hkTypeManager::Type::calcHash((hkTypeManager::Type *)p_m_next);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
    &this->m_typeMultiMap.m_map,
    v4,
    (unsigned __int64)p_m_next);
  this->m_homogenousClass = (hkTypeManager::Type *)p_m_next;
}

// File Line: 246
// RVA: 0xE5F180
void __fastcall hkTypeManager::~hkTypeManager(hkTypeManager *this)
{
  hkFreeList *p_m_typeFreeList; // rcx

  p_m_typeFreeList = &this->m_typeFreeList;
  p_m_typeFreeList[-2].m_elementAllocator = (hkMemoryAllocator *)&hkTypeManager::`vftable;
  hkFreeList::freeAllMemory(p_m_typeFreeList);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>(&this->m_typeMultiMap.m_map);
  hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear((hkStorageStringMap<int,hkContainerHeapAllocator> *)&this->m_classMap);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_classMap.m_map);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 250
// RVA: 0xE5F1E0
hkTypeManager::Type *__fastcall hkTypeManager::_addBuiltIn(hkTypeManager *this, hkTypeManager::SubType subType)
{
  __int64 v2; // rbx
  hkTypeManager::Type *result; // rax
  hkTypeManager::Type typeIn; // [rsp+20h] [rbp-28h] BYREF

  v2 = subType;
  typeIn.m_subType = subType;
  typeIn.m_parent = 0i64;
  typeIn.m_extra.m_name = 0i64;
  result = hkTypeManager::_addType(this, &typeIn);
  this->m_builtInTypes[v2] = result;
  return result;
}

// File Line: 263
// RVA: 0xE5F220
hkFreeList::Element **__fastcall hkTypeManager::_addType(hkTypeManager *this, hkTypeManager::Type *typeIn)
{
  unsigned __int64 v4; // rdi
  int Key; // eax
  int m_hashMod; // r15d
  int v7; // ebx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // rbp
  hkTypeManager::Type *val; // rsi
  __int64 v10; // r10
  int v11; // r8d
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v13; // rax
  hkFreeList *p_m_typeFreeList; // rcx
  hkFreeList::Element **p_m_next; // rbx
  unsigned __int64 m_elementSize; // r8
  hkBool result; // [rsp+50h] [rbp+8h] BYREF

  v4 = hkTypeManager::Type::calcHash(typeIn);
  Key = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
          &this->m_typeMultiMap.m_map,
          v4);
  m_hashMod = this->m_typeMultiMap.m_map.m_hashMod;
  v7 = Key;
  if ( Key > m_hashMod )
  {
LABEL_14:
    p_m_typeFreeList = &this->m_typeFreeList;
    p_m_next = &this->m_typeFreeList.m_free->m_next;
    if ( p_m_next )
    {
      --this->m_typeFreeList.m_numFreeElements;
      p_m_typeFreeList->m_free = *p_m_next;
    }
    else
    {
      p_m_next = (hkFreeList::Element **)this->m_typeFreeList.m_top;
      if ( (char *)p_m_next < this->m_typeFreeList.m_blockEnd )
      {
        m_elementSize = this->m_typeFreeList.m_elementSize;
        --this->m_typeFreeList.m_numFreeElements;
        this->m_typeFreeList.m_top = (char *)p_m_next + m_elementSize;
      }
      else
      {
        p_m_next = (hkFreeList::Element **)hkFreeList::addSpace(p_m_typeFreeList);
      }
    }
    *p_m_next = *(hkFreeList::Element **)&typeIn->m_subType;
    p_m_next[1] = (hkFreeList::Element *)typeIn->m_parent;
    p_m_next[2] = (hkFreeList::Element *)typeIn->m_extra.m_name;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
      &this->m_typeMultiMap.m_map,
      v4,
      (unsigned __int64)p_m_next);
    return p_m_next;
  }
  else
  {
    m_elem = this->m_typeMultiMap.m_map.m_elem;
    while ( 1 )
    {
      val = (hkTypeManager::Type *)m_elem[v7].val;
      if ( hkTypeManager::Type::_equals(typeIn, &result, val)->m_bool )
        return (hkFreeList::Element **)val;
      v10 = this->m_typeMultiMap.m_map.m_hashMod;
      v11 = v7 + 1;
      for ( i = v7 + 1; i > v10; i = 0i64 )
LABEL_10:
        v11 = 0;
      v13 = &m_elem[i];
      while ( v13->key != -1i64 )
      {
        if ( v13->key == v4 )
        {
          v7 = v11;
          goto LABEL_13;
        }
        ++i;
        ++v11;
        ++v13;
        if ( i > v10 )
          goto LABEL_10;
      }
      v7 = v10 + 1;
LABEL_13:
      if ( v7 > m_hashMod )
        goto LABEL_14;
    }
  }
}

// File Line: 289
// RVA: 0xE5DFE0
void __fastcall hkTypeManager::findTypesUsingClass(
        hkTypeManager *this,
        hkTypeManager::Type *clsType,
        hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> *types)
{
  int v3; // r10d
  __int64 m_hashMod; // r8
  __int64 v8; // r9
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // rax
  int v10; // ebx
  hkTypeManager::Type *val; // rsi
  __int64 v12; // r8
  int v13; // edx
  __int64 v14; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v15; // rax

  v3 = 0;
  types->m_size = 0;
  m_hashMod = this->m_typeMultiMap.m_map.m_hashMod;
  v8 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = this->m_typeMultiMap.m_map.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v8;
      ++v3;
      ++m_elem;
    }
    while ( v8 <= m_hashMod );
  }
  v10 = v3;
  if ( v3 <= this->m_typeMultiMap.m_map.m_hashMod )
  {
    do
    {
      val = (hkTypeManager::Type *)this->m_typeMultiMap.m_map.m_elem[v10].val;
      if ( hkTypeManager::Type::findTerminal(val) == clsType )
      {
        if ( types->m_size == (types->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&types->m_data, 8);
        types->m_data[types->m_size++] = val;
      }
      v12 = this->m_typeMultiMap.m_map.m_hashMod;
      v13 = v10 + 1;
      v14 = v10 + 1;
      if ( v14 <= v12 )
      {
        v15 = &this->m_typeMultiMap.m_map.m_elem[v13];
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
    while ( v13 <= this->m_typeMultiMap.m_map.m_hashMod );
  }
}

// File Line: 307
// RVA: 0xE5DEC0
void __fastcall hkTypeManager::renameClass(hkTypeManager *this, const char *clsName, char *newName)
{
  hkTypeManager::Type *Class; // rdi
  hkStorageStringMap<hkTypeManager::Type *,hkContainerHeapAllocator> *p_m_classMap; // rbx
  Dummy *Key; // rbp
  char *v9; // rax
  Dummy *v10; // rbp
  char *v11; // rsi
  hkBool result; // [rsp+48h] [rbp+20h] BYREF

  Class = hkTypeManager::getClass(this, clsName);
  if ( Class && !hkTypeManager::getClass(this, newName) )
  {
    p_m_classMap = &this->m_classMap;
    Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_classMap,
            clsName);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_classMap,
      &result,
      Key);
    if ( result.m_bool )
    {
      v9 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&p_m_classMap->m_map, Key);
      hkString::strFree(v9, &hkContainerHeapAllocator::s_alloc);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
        &p_m_classMap->m_map,
        (unsigned __int64)Key);
    }
    v10 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_classMap,
            newName);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_classMap,
      &result,
      v10);
    if ( result.m_bool )
    {
      v11 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&p_m_classMap->m_map, v10);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
        &p_m_classMap->m_map,
        v10,
        (unsigned __int64)Class);
    }
    else
    {
      v11 = hkString::strDup(newName, &hkContainerHeapAllocator::s_alloc);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &p_m_classMap->m_map,
        v11,
        (unsigned __int64)Class);
    }
    Class->m_extra.m_name = v11;
  }
}

// File Line: 329
// RVA: 0xE5E110
void __fastcall hkTypeManager::removeClass(hkTypeManager *this, hkTypeManager::Type *clsType)
{
  __int64 v4; // r14
  const char *TypeName; // r12
  int m_size; // ecx
  int v7; // ebx
  int v8; // esi
  __int64 v9; // rbx
  __int64 v10; // rdi
  unsigned int v11; // eax
  int v12; // edi
  __int64 v13; // rsi
  hkTypeManager::Type *v14; // rbx
  hkStorageStringMap<hkTypeManager::Type *,hkContainerHeapAllocator> *p_m_classMap; // rbx
  Dummy *Key; // rdi
  char *v17; // rax
  hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> types; // [rsp+30h] [rbp-40h] BYREF
  char *array; // [rsp+40h] [rbp-30h] BYREF
  int v20; // [rsp+48h] [rbp-28h]
  int v21; // [rsp+4Ch] [rbp-24h]
  hkResult result; // [rsp+80h] [rbp+10h] BYREF

  v4 = 0i64;
  types.m_data = 0i64;
  TypeName = hkTypeManager::Type::getTypeName(clsType);
  types.m_size = 0;
  types.m_capacityAndFlags = 0x80000000;
  hkTypeManager::findTypesUsingClass(this, clsType, &types);
  m_size = types.m_size;
  array = 0i64;
  v20 = 0;
  v21 = 0x80000000;
  v7 = types.m_size;
  if ( types.m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, types.m_size, 4);
    m_size = types.m_size;
  }
  v20 = v7;
  v8 = 0;
  if ( m_size > 0 )
  {
    v9 = 0i64;
    v10 = 0i64;
    do
    {
      v11 = hkTypeManager::Type::calcHash(types.m_data[v10]);
      ++v8;
      *(_DWORD *)&array[v9] = v11;
      m_size = types.m_size;
      ++v10;
      v9 += 4i64;
    }
    while ( v8 < types.m_size );
  }
  v12 = 0;
  if ( m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = types.m_data[v4];
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
        &this->m_typeMultiMap.m_map,
        &result,
        *(unsigned int *)&array[v13],
        (unsigned __int64)v14);
      ++v12;
      v14->m_subType = SUB_TYPE_INVALID;
      v14->m_parent = 0i64;
      ++v4;
      v13 += 4i64;
    }
    while ( v12 < types.m_size );
  }
  p_m_classMap = &this->m_classMap;
  Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classMap,
          TypeName);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classMap,
    (hkBool *)&result,
    Key);
  if ( LOBYTE(result.m_enum) )
  {
    v17 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&p_m_classMap->m_map, Key);
    hkString::strFree(v17, &hkContainerHeapAllocator::s_alloc);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(&p_m_classMap->m_map, (unsigned __int64)Key);
  }
  v20 = 0;
  if ( v21 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v21);
  array = 0i64;
  types.m_size = 0;
  v21 = 0x80000000;
  if ( types.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      types.m_data,
      8 * types.m_capacityAndFlags);
}

// File Line: 364
// RVA: 0xE5F400
void __fastcall freeListCallback(_DWORD *start, unsigned __int64 size, bool allocated, int pool, const void **param)
{
  if ( allocated && !*start )
  {
    if ( *((_DWORD *)param + 2) == (*((_DWORD *)param + 3) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, param, 8);
    *((_QWORD *)*param + (int)(*((_DWORD *)param + 2))++) = start;
  }
}

// File Line: 377
// RVA: 0xE5E540
void __fastcall hkTypeManager::garbageCollect(hkTypeManager *this)
{
  hkFreeList *p_m_typeFreeList; // rbx
  int v2; // r8d
  __int64 v3; // rcx
  hkFreeList::Element *v4; // rdx
  hkFreeList::Element *m_free; // rax
  char *param; // [rsp+20h] [rbp-18h] BYREF
  int v7; // [rsp+28h] [rbp-10h]
  int v8; // [rsp+2Ch] [rbp-Ch]

  p_m_typeFreeList = &this->m_typeFreeList;
  param = 0i64;
  v7 = 0;
  v8 = 0x80000000;
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
      m_free = p_m_typeFreeList->m_free;
      ++p_m_typeFreeList->m_numFreeElements;
      v4->m_next = m_free;
      p_m_typeFreeList->m_free = v4;
    }
    while ( v2 < v7 );
  }
  hkFreeList::findGarbage(p_m_typeFreeList);
  hkFreeList::freeAllFreeBlocks(p_m_typeFreeList);
  v7 = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, param, 8 * v8);
}

// File Line: 390
// RVA: 0xE5E610
hkTypeManager::Type *__fastcall hkTypeManager::makePointer(hkTypeManager *this, hkTypeManager::Type *parent)
{
  hkTypeManager::Type typeIn; // [rsp+20h] [rbp-28h] BYREF

  typeIn.m_parent = parent;
  typeIn.m_subType = SUB_TYPE_POINTER;
  typeIn.m_extra.m_name = 0i64;
  return hkTypeManager::_addType(this, &typeIn);
}

// File Line: 402
// RVA: 0xE5E640
hkTypeManager::Type *__fastcall hkTypeManager::makeArray(hkTypeManager *this, hkTypeManager::Type *parent)
{
  hkTypeManager::Type typeIn; // [rsp+20h] [rbp-28h] BYREF

  typeIn.m_parent = parent;
  typeIn.m_subType = SUB_TYPE_ARRAY;
  return hkTypeManager::_addType(this, &typeIn);
}

// File Line: 413
// RVA: 0xE5E670
hkTypeManager::Type *__fastcall hkTypeManager::makeTuple(
        hkTypeManager *this,
        hkTypeManager::Type *parent,
        int tupleSize)
{
  hkTypeManager::Type typeIn; // [rsp+20h] [rbp-28h] BYREF

  typeIn.m_parent = parent;
  typeIn.m_subType = SUB_TYPE_TUPLE;
  typeIn.m_extra.m_size = tupleSize;
  return hkTypeManager::_addType(this, &typeIn);
}

// File Line: 426
// RVA: 0xE5F380
hkBool *__fastcall hkTypeManager::_isValidClassName(hkBool *result, const char *name)
{
  unsigned __int8 v3; // al
  __int64 v4; // rcx
  unsigned __int64 v5; // rcx
  const char *v6; // rdx
  __int64 v7; // r9

  if ( name && *name )
  {
    v3 = *name - 65;
    if ( v3 <= 0x39u )
    {
      v4 = 0x3FFFFFF43FFFFFFi64;
      if ( _bittest64(&v4, (char)v3) )
      {
        v5 = *((unsigned __int8 *)name + 1);
        v6 = name + 1;
        if ( !(_BYTE)v5 )
        {
LABEL_11:
          result->m_bool = 1;
          return result;
        }
        v7 = 0x87FFFFFE07FFi64;
        while ( 1 )
        {
          if ( (unsigned __int8)(v5 - 97) > 0x19u )
          {
            LOBYTE(v5) = v5 - 48;
            if ( (unsigned __int8)v5 > 0x2Fu || !_bittest64(&v7, v5) )
              break;
          }
          v5 = *(unsigned __int8 *)++v6;
          if ( !(_BYTE)v5 )
            goto LABEL_11;
        }
      }
    }
    result->m_bool = 0;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 465
// RVA: 0xE5E320
hkTypeManager::Type *__fastcall hkTypeManager::getClass(hkTypeManager *this, const char *clsName)
{
  return (hkTypeManager::Type *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classMap,
                                  clsName,
                                  0i64);
}

// File Line: 470
// RVA: 0xE5DDA0
hkTypeManager::Type *__fastcall hkTypeManager::addClass(hkTypeManager *this, char *clsName)
{
  hkTypeManager::Type *Class; // rax
  hkFreeList::Element **p_m_next; // rbx
  unsigned __int64 m_elementSize; // rcx
  Dummy *Key; // r14
  char *v8; // rbp
  unsigned int v9; // eax
  hkBool result; // [rsp+50h] [rbp+18h] BYREF

  Class = hkTypeManager::getClass(this, clsName);
  if ( !Class )
  {
    p_m_next = &this->m_typeFreeList.m_free->m_next;
    if ( p_m_next )
    {
      --this->m_typeFreeList.m_numFreeElements;
      this->m_typeFreeList.m_free = *p_m_next;
    }
    else
    {
      p_m_next = (hkFreeList::Element **)this->m_typeFreeList.m_top;
      if ( (char *)p_m_next < this->m_typeFreeList.m_blockEnd )
      {
        m_elementSize = this->m_typeFreeList.m_elementSize;
        --this->m_typeFreeList.m_numFreeElements;
        this->m_typeFreeList.m_top = (char *)p_m_next + m_elementSize;
      }
      else
      {
        p_m_next = (hkFreeList::Element **)hkFreeList::addSpace(&this->m_typeFreeList);
      }
    }
    *(_DWORD *)p_m_next = 6;
    p_m_next[1] = 0i64;
    Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classMap,
            clsName);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classMap,
      &result,
      Key);
    if ( result.m_bool )
    {
      v8 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&this->m_classMap.m_map, Key);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
        &this->m_classMap.m_map,
        Key,
        (unsigned __int64)p_m_next);
    }
    else
    {
      v8 = hkString::strDup(clsName, &hkContainerHeapAllocator::s_alloc);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &this->m_classMap.m_map,
        v8,
        (unsigned __int64)p_m_next);
    }
    p_m_next[2] = (hkFreeList::Element *)v8;
    v9 = hkTypeManager::Type::calcHash((hkTypeManager::Type *)p_m_next);
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::insert(
      &this->m_typeMultiMap.m_map,
      v9,
      (unsigned __int64)p_m_next);
    return (hkTypeManager::Type *)p_m_next;
  }
  return Class;
}

// File Line: 493
// RVA: 0xE5E6F0
hkTypeManager::Type *__fastcall hkTypeManager::replaceParent(
        hkTypeManager *this,
        hkTypeManager::Type *typeIn,
        hkTypeManager::Type *parent)
{
  int TupleSize; // eax

  if ( typeIn->m_parent == parent )
    return typeIn;
  if ( typeIn->m_subType == SUB_TYPE_POINTER )
    return hkTypeManager::makePointer(this, parent);
  if ( typeIn->m_subType == SUB_TYPE_ARRAY )
    return hkTypeManager::makeArray(this, parent);
  if ( typeIn->m_subType != SUB_TYPE_TUPLE )
    return 0i64;
  TupleSize = hkTypeManager::Type::getTupleSize(typeIn);
  return hkTypeManager::makeTuple(this, parent, TupleSize);
}

// File Line: 513
// RVA: 0xE5E780
hkTypeManager::Type *__fastcall hkTypeManager::replaceTerminal(
        hkTypeManager *this,
        hkTypeManager::Type *typeIn,
        hkTypeManager::Type *newTerminal)
{
  int v4; // edx
  int v5; // eax
  hkTypeManager::Type *v8; // rbx
  char *v9; // rcx
  __int64 j; // rbx
  hkTypeManager::Type *v11; // rax
  char *array; // [rsp+20h] [rbp-98h] BYREF
  int v14; // [rsp+28h] [rbp-90h]
  int i; // [rsp+2Ch] [rbp-8Ch]
  char v16; // [rsp+30h] [rbp-88h] BYREF

  v4 = 0;
  array = &v16;
  v5 = -2147483632;
  v14 = 0;
  v8 = typeIn;
  for ( i = -2147483632; ; v5 = i )
  {
    if ( v4 == (v5 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
      v4 = v14;
    }
    *(_QWORD *)&array[8 * v4] = v8;
    v4 = ++v14;
    v8 = v8->m_parent;
    if ( !v8 )
      break;
  }
  v9 = array;
  if ( *(hkTypeManager::Type **)&array[8 * v4 - 8] != newTerminal )
  {
    typeIn = newTerminal;
    for ( j = v4 - 1; j >= 0; typeIn = v11 )
    {
      v11 = hkTypeManager::replaceParent(this, *(hkTypeManager::Type **)&v9[8 * j--], typeIn);
      v9 = array;
    }
  }
  v14 = 0;
  if ( i >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v9, 8 * i);
  return typeIn;
}

// File Line: 541
// RVA: 0xE5E6A0
hkTypeManager::Type *__fastcall hkTypeManager::makeArray(hkTypeManager *this, hkTypeManager::SubType subType)
{
  hkTypeManager::Type *v2; // rdx

  v2 = this->m_builtInTypes[subType];
  if ( v2 )
    return hkTypeManager::makeArray(this, v2);
  else
    return 0i64;
}

// File Line: 551
// RVA: 0xE5E6C0
hkTypeManager::Type *__fastcall hkTypeManager::getClassPointer(hkTypeManager *this, char *name)
{
  hkTypeManager::Type *v3; // rax

  v3 = hkTypeManager::addClass(this, name);
  return hkTypeManager::makePointer(this, v3);
}

// File Line: 556
// RVA: 0xE5E340
hkBool *__fastcall hkTypeManager::isOwned(hkTypeManager *this, hkBool *result, hkTypeManager::Type *type)
{
  hkPointerMultiMap<unsigned int,hkTypeManager::Type *> *p_m_typeMultiMap; // r14
  unsigned __int64 v7; // rdi
  int Key; // eax
  int m_hashMod; // ebx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *m_elem; // r10
  __int64 v11; // r11
  int v12; // r8d
  __int64 i; // rcx
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::Pair *v14; // rax

  p_m_typeMultiMap = &this->m_typeMultiMap;
  v7 = hkTypeManager::Type::calcHash(type);
  Key = hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::findKey(
          &p_m_typeMultiMap->m_map,
          v7);
  m_hashMod = this->m_typeMultiMap.m_map.m_hashMod;
  if ( Key > m_hashMod )
  {
LABEL_14:
    result->m_bool = 0;
  }
  else
  {
    m_elem = p_m_typeMultiMap->m_map.m_elem;
    while ( (hkTypeManager::Type *)m_elem[Key].val != type )
    {
      v11 = p_m_typeMultiMap->m_map.m_hashMod;
      v12 = Key + 1;
      for ( i = Key + 1; i > v11; i = 0i64 )
LABEL_10:
        v12 = 0;
      v14 = &m_elem[i];
      while ( v14->key != -1i64 )
      {
        if ( v14->key == v7 )
        {
          Key = v12;
          goto LABEL_13;
        }
        ++i;
        ++v12;
        ++v14;
        if ( i > v11 )
          goto LABEL_10;
      }
      Key = v11 + 1;
LABEL_13:
      if ( Key > m_hashMod )
        goto LABEL_14;
    }
    result->m_bool = 1;
  }
  return result;
}

// File Line: 577
// RVA: 0xE5E420
hkTypeManager::Type *__fastcall hkTypeManager::copyType(hkTypeManager *this, hkTypeManager::Type *type)
{
  hkTypeManager::Type *v2; // rbx
  int m_size; // edx
  hkTypeManager::Type *v5; // rcx
  __int64 m_subType; // rax
  char *TypeName; // rax
  hkTypeManager::Type *v8; // rax
  __int64 i; // rdi
  hkTypeManager::Type *v10; // rax
  hkArray<hkTypeManager::Type *,hkContainerHeapAllocator> types; // [rsp+20h] [rbp-98h] BYREF
  char v13; // [rsp+30h] [rbp-88h] BYREF
  hkBool result; // [rsp+D0h] [rbp+18h] BYREF

  v2 = type;
  if ( !hkTypeManager::isOwned(this, &result, type)->m_bool )
  {
    types.m_size = 0;
    types.m_capacityAndFlags = -2147483632;
    types.m_data = (hkTypeManager::Type **)&v13;
    hkTypeManager::Type::getTypePath(v2, &types);
    m_size = types.m_size;
    v5 = types.m_data[types.m_size - 1];
    m_subType = v5->m_subType;
    if ( (_DWORD)m_subType == 6 )
    {
      TypeName = (char *)hkTypeManager::Type::getTypeName(v5);
      v8 = hkTypeManager::addClass(this, TypeName);
      m_size = types.m_size;
      v2 = v8;
    }
    else
    {
      v2 = this->m_builtInTypes[m_subType];
    }
    if ( v2 )
    {
      for ( i = m_size - 2; i >= 0; v2 = v10 )
        v10 = hkTypeManager::replaceParent(this, types.m_data[i--], v2);
    }
    types.m_size = 0;
    if ( types.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        types.m_data,
        8 * types.m_capacityAndFlags);
  }
  return v2;
}

// File Line: 619
// RVA: 0xE5EB60
void __fastcall hkTypeManager::appendTypeExpression(hkTypeManager::Type *type, hkOstream *stream)
{
  hkTypeManager::Type *v3; // rbx
  const char *v4; // rdx
  hkOstream *v5; // rcx
  const char *TypeName; // rdi
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  unsigned int TupleSize; // edi
  hkOstream *v10; // rax

  if ( type )
  {
    v3 = type;
    do
    {
      switch ( v3->m_subType )
      {
        case SUB_TYPE_INVALID:
          v4 = "!";
          v5 = stream;
          goto LABEL_15;
        case SUB_TYPE_VOID:
          v4 = "v";
          v5 = stream;
          goto LABEL_15;
        case SUB_TYPE_BYTE:
          v4 = "b";
          v5 = stream;
          goto LABEL_15;
        case SUB_TYPE_REAL:
          v4 = "r";
          v5 = stream;
          goto LABEL_15;
        case SUB_TYPE_INT:
          v4 = "i";
          v5 = stream;
          goto LABEL_15;
        case SUB_TYPE_CSTRING:
          v4 = "s";
          v5 = stream;
          goto LABEL_15;
        case SUB_TYPE_CLASS:
          TypeName = hkTypeManager::Type::getTypeName(v3);
          v7 = hkOstream::operator<<(stream, "C");
          v8 = hkOstream::operator<<(v7, TypeName);
          v4 = ";";
          goto LABEL_14;
        case SUB_TYPE_POINTER:
          v4 = pattern;
          v5 = stream;
          goto LABEL_15;
        case SUB_TYPE_ARRAY:
          v4 = "[]";
          v5 = stream;
          goto LABEL_15;
        case SUB_TYPE_TUPLE:
          TupleSize = hkTypeManager::Type::getTupleSize(v3);
          v10 = hkOstream::operator<<(stream, "{");
          v8 = hkOstream::operator<<(v10, TupleSize);
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
  hkTypeManager::Type *result; // rax
  hkTypeManager::Type *v4; // rax
  hkTypeManager::Type *v5; // rax
  char v6; // al
  const char *v7; // rdx
  const char *j; // rdi
  unsigned int v9; // ebx
  int v10; // ebx
  hkTypeManager::Type *v11; // rax
  const char *v12; // r9
  __int64 v13; // r8
  const char *i; // rdx
  unsigned __int64 v15; // rax
  unsigned int v16; // ebx
  char dst[16]; // [rsp+20h] [rbp-98h] BYREF
  char clsName[136]; // [rsp+30h] [rbp-88h] BYREF

  switch ( *typeExpression )
  {
    case !:
      result = this->m_builtInTypes[0];
      break;
    case *:
      v4 = hkTypeManager::parseTypeExpression(this, typeExpression + 1);
      result = hkTypeManager::makePointer(this, v4);
      break;
    case C:
      v12 = typeExpression + 1;
      v13 = 0x87FFFFFE07FFi64;
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
      result = hkTypeManager::addClass(this, clsName);
      break;
    case [:
      v5 = hkTypeManager::parseTypeExpression(this, typeExpression + 2);
      result = hkTypeManager::makeArray(this, v5);
      break;
    case b:
      result = this->m_builtInTypes[2];
      break;
    case i:
      result = this->m_builtInTypes[4];
      break;
    case r:
      result = this->m_builtInTypes[3];
      break;
    case s:
      result = this->m_builtInTypes[5];
      break;
    case v:
      result = this->m_builtInTypes[1];
      break;
    case {:
      v6 = typeExpression[1];
      v7 = typeExpression + 1;
      for ( j = v7; v6 >= 48; v6 = *++j )
      {
        if ( v6 > 57 )
          break;
      }
      v9 = (_DWORD)j - (_DWORD)v7;
      if ( (unsigned int)((_DWORD)j - (_DWORD)v7 - 1) <= 8 && *j == 125 )
      {
        hkString::strNcpy(dst, v7, v9);
        dst[v9] = 0;
        v10 = hkString::atoi(dst, 0);
        v11 = hkTypeManager::parseTypeExpression(this, j + 1);
        result = hkTypeManager::makeTuple(this, v11, v10);
      }
      else
      {
        result = 0i64;
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
hkTypeManager::Type *__fastcall hkTypeManager::getType(
        hkTypeManager *this,
        hkLegacyType::Type type,
        char *className,
        int tupleSize)
{
  char v5; // di
  hkTypeManager::Type *result; // rax
  hkTypeManager::Type *v8; // rax

  v5 = type;
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
        result = hkTypeManager::makePointer(this, v8);
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
      if ( (v5 & 0x10) != 0 )
      {
        result = hkTypeManager::makeArray(this, result);
      }
      else if ( (v5 & 0x20) != 0 )
      {
        result = hkTypeManager::makeTuple(this, result, tupleSize);
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
__int64 __fastcall hkTypeManager::getTerminalLegacyType(hkTypeManager::Type *type, const char **classNameOut)
{
  __int64 result; // rax
  hkTypeManager::Type *m_parent; // rcx
  int TupleSize; // eax

  *classNameOut = 0i64;
  switch ( type->m_subType )
  {
    case SUB_TYPE_BYTE:
      result = 1i64;
      break;
    case SUB_TYPE_REAL:
      result = 3i64;
      break;
    case SUB_TYPE_INT:
      result = 2i64;
      break;
    case SUB_TYPE_CSTRING:
      result = 10i64;
      break;
    case SUB_TYPE_CLASS:
      *classNameOut = hkTypeManager::Type::getTypeName(type);
      result = 9i64;
      break;
    case SUB_TYPE_POINTER:
      m_parent = type->m_parent;
      if ( m_parent->m_subType != SUB_TYPE_CLASS )
        goto $LN1_69;
      *classNameOut = hkTypeManager::Type::getTypeName(m_parent);
      result = 8i64;
      break;
    case SUB_TYPE_TUPLE:
      if ( type->m_parent->m_subType != SUB_TYPE_REAL )
        goto $LN1_69;
      TupleSize = hkTypeManager::Type::getTupleSize(type);
      switch ( TupleSize )
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
__int64 __fastcall hkTypeManager::getLegacyType(hkTypeManager::Type *type, const char **className, int *numTupleOut)
{
  __int32 v5; // ecx

  *className = 0i64;
  *numTupleOut = 0;
  v5 = type->m_subType - 8;
  if ( !v5 )
    return (unsigned int)hkTypeManager::getTerminalLegacyType(type->m_parent, className) | 0x10;
  if ( v5 != 1 || type->m_parent->m_subType == SUB_TYPE_REAL && ((type->m_extra.m_size - 4) & 0xFFFFFFF3) == 0 )
    return hkTypeManager::getTerminalLegacyType(type, className);
  *numTupleOut = hkTypeManager::Type::getTupleSize(type);
  return (unsigned int)hkTypeManager::getTerminalLegacyType(type->m_parent, className) | 0x20;
}

