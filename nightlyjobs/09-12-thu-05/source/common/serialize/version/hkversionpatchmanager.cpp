// File Line: 29
// RVA: 0xE5C080
void __fastcall hkVersionPatchManagercreate()
{
  _QWORD **Value; // rax
  hkVersionPatchManager *v1; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v1 = (hkVersionPatchManager *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 56i64);
  if ( v1 )
    hkVersionPatchManager::hkVersionPatchManager(v1);
}

// File Line: 42
// RVA: 0xE5C000
void __fastcall hkDefaultClassWrapper::hkDefaultClassWrapper(hkDefaultClassWrapper *this, hkClassNameRegistry *nameReg)
{
  hkClassNameRegistry *v2; // rdi
  hkClassNameRegistry *m_pntr; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = nameReg;
  this->vfptr = (hkBaseObjectVtbl *)&hkDefaultClassWrapper::`vftable;
  this->m_nameReg.m_pntr = 0i64;
  if ( !nameReg )
    v2 = (hkClassNameRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  if ( v2 )
    hkReferencedObject::addReference(v2);
  m_pntr = this->m_nameReg.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_nameReg.m_pntr = v2;
}

// File Line: 53
// RVA: 0xE5BF70
hkDataClassDict *__fastcall hkDefaultClassWrapper::wrapClass(
        hkDefaultClassWrapper *this,
        hkDataWorldDict *world,
        const char *typeName)
{
  hkDataClassDict *result; // rax
  hkClass *v7; // rdi
  char v8; // [rsp+38h] [rbp+10h] BYREF

  result = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))world->vfptr[4].__first_virtual_table_function__)(
                                world,
                                typeName);
  if ( !result )
  {
    v7 = (hkClass *)this->m_nameReg.m_pntr->vfptr[2].__vecDelDtor(this->m_nameReg.m_pntr, typeName);
    if ( v7 && *(_DWORD *)world->vfptr[3].__vecDelDtor(world, &v8) == 1 )
      return hkDataWorldDict::wrapClass(world, v7);
    else
      return 0i64;
  }
  return result;
}

// File Line: 92
// RVA: 0xE5C0C0
__int64 __fastcall walkDependencies(
        int curIndex,
        hkArray<int,hkContainerHeapAllocator> *order,
        hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > *incoming,
        unsigned int counter,
        hkArray<int,hkContainerHeapAllocator> *pending,
        hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *patchInfos)
{
  int v7; // edi
  bool v8; // zf
  __int64 v9; // rcx
  int i; // eax
  __int64 value; // rsi
  int v13; // r8d
  __int64 v15; // [rsp+30h] [rbp-18h]
  __int64 v16; // [rsp+38h] [rbp-10h]

  v7 = counter;
  v8 = order->m_data[curIndex] == -1;
  v9 = curIndex;
  v16 = v9 * 4;
  if ( !v8 )
    return counter;
  order->m_data[v9] = -2;
  if ( pending->m_size == (pending->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pending->m_data, 4);
  pending->m_data[pending->m_size++] = curIndex;
  for ( i = hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::getFirstIndex(
              incoming,
              curIndex); i != -1; i = incoming->m_valueChain.m_data[v15].next )
  {
    value = incoming->m_valueChain.m_data[i].value;
    v15 = i;
    v13 = order->m_data[value];
    if ( v13 == -2 )
    {
      if ( pending->m_size == (pending->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pending->m_data, 4);
      pending->m_data[pending->m_size] = value;
    }
    else if ( v13 == -1 )
    {
      v7 = walkDependencies(value, order, incoming, v7, pending, patchInfos);
    }
  }
  --pending->m_size;
  *(int *)((char *)order->m_data + v16) = v7;
  return (unsigned int)(v7 + 1);
}

// File Line: 128
// RVA: 0xE5B1C0
void __fastcall hkVersionPatchManager::UidFromClassVersion::~UidFromClassVersion(
        hkVersionPatchManager::UidFromClassVersion *this)
{
  Dummy *Iterator; // rbp
  _DWORD *Value; // rbx
  hkMemoryAllocator **v4; // rax
  int m_capacityAndFlags; // r8d
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_cachedNames);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_cachedNames,
    &result,
    Iterator);
  while ( result.m_bool )
  {
    Value = (_DWORD *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_cachedNames,
                        Iterator);
    v4 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(v4[11], Value);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_cachedNames,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_cachedNames,
      &result,
      Iterator);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_cachedNames.m_map);
  m_capacityAndFlags = this->m_names.m_capacityAndFlags;
  this->m_names.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_names.m_data,
      8 * m_capacityAndFlags);
  this->m_names.m_data = 0i64;
  this->m_names.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_indexFromName.m_map);
}

// File Line: 136
// RVA: 0xE5B2C0
unsigned __int64 __fastcall hkVersionPatchManager::UidFromClassVersion::get(
        hkVersionPatchManager::UidFromClassVersion *this,
        const char *name,
        int ver)
{
  __int64 v3; // rbp
  const char *v5; // rsi
  unsigned int v6; // edi

  v3 = ver;
  v5 = hkVersionPatchManager::UidFromClassVersion::cache(this, name);
  v6 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getOrInsert(
         &this->m_indexFromName.m_map,
         v5,
         this->m_names.m_size);
  if ( v6 == this->m_names.m_size )
  {
    if ( this->m_names.m_size == (this->m_names.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_names.m_data, 8);
    this->m_names.m_data[this->m_names.m_size++] = v5;
  }
  return v6 | (unsigned __int64)(v3 << 32);
}

// File Line: 148
// RVA: 0xE5B360
const char *__fastcall hkVersionPatchManager::UidFromClassVersion::getName(
        hkVersionPatchManager::UidFromClassVersion *this,
        unsigned __int64 uid)
{
  return this->m_names.m_data[(int)uid];
}

// File Line: 154
// RVA: 0xE5B380
__int64 __fastcall hkVersionPatchManager::UidFromClassVersion::getVersion(
        hkVersionPatchManager::UidFromClassVersion *this,
        unsigned __int64 uid)
{
  return HIDWORD(uid);
}

// File Line: 159
// RVA: 0xE5B390
const char *__fastcall hkVersionPatchManager::UidFromClassVersion::cache(
        hkVersionPatchManager::UidFromClassVersion *this,
        char *name)
{
  hkStringMap<char *,hkContainerHeapAllocator> *p_m_cachedNames; // rsi
  const char *v4; // rbx

  if ( !name )
    return 0i64;
  p_m_cachedNames = &this->m_cachedNames;
  v4 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                       (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_cachedNames,
                       name,
                       0i64);
  if ( !v4 )
  {
    v4 = hkString::strDup(name);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &p_m_cachedNames->m_map,
      v4,
      (unsigned __int64)v4);
  }
  return v4;
}

// File Line: 174
// RVA: 0xE59E30
void __fastcall hkVersionPatchManager::hkVersionPatchManager(hkVersionPatchManager *this)
{
  _QWORD **Value; // rax
  hkVersionPatchManager::UidFromClassVersion *v3; // rdi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkVersionPatchManager::`vftable;
  this->m_patchInfos.m_data = 0i64;
  this->m_patchInfos.m_size = 0;
  this->m_patchInfos.m_capacityAndFlags = 0x80000000;
  this->m_patchIndexFromUid.m_map.m_elem = 0i64;
  this->m_patchIndexFromUid.m_map.m_numElems = 0;
  this->m_patchIndexFromUid.m_map.m_hashMod = -1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkVersionPatchManager::UidFromClassVersion *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                                       Value[11],
                                                       64i64);
  if ( v3 )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &v3->m_indexFromName.m_map,
      0);
    v3->m_names.m_data = 0i64;
    v3->m_names.m_size = 0;
    v3->m_names.m_capacityAndFlags = 0x80000000;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &v3->m_cachedNames.m_map,
      0);
    this->m_uidFromClassVersion = v3;
  }
  else
  {
    this->m_uidFromClassVersion = 0i64;
  }
}

// File Line: 179
// RVA: 0xE5AFB0
void __fastcall hkVersionPatchManager::clearPatches(hkVersionPatchManager *this)
{
  hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *p_m_patchIndexFromUid; // rcx
  hkVersionPatchManager::UidFromClassVersion *m_uidFromClassVersion; // rdi
  _QWORD **Value; // rax
  _QWORD **v5; // rax
  hkVersionPatchManager::UidFromClassVersion *v6; // rdi

  p_m_patchIndexFromUid = &this->m_patchIndexFromUid;
  p_m_patchIndexFromUid[-1].m_map.m_numElems = 0;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&p_m_patchIndexFromUid->m_map);
  m_uidFromClassVersion = this->m_uidFromClassVersion;
  if ( m_uidFromClassVersion )
  {
    hkVersionPatchManager::UidFromClassVersion::~UidFromClassVersion(this->m_uidFromClassVersion);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkVersionPatchManager::UidFromClassVersion *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_uidFromClassVersion,
      64i64);
  }
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkVersionPatchManager::UidFromClassVersion *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v5[11] + 8i64))(
                                                       v5[11],
                                                       64i64);
  if ( v6 )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &v6->m_indexFromName.m_map,
      0);
    v6->m_names.m_data = 0i64;
    v6->m_names.m_size = 0;
    v6->m_names.m_capacityAndFlags = 0x80000000;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &v6->m_cachedNames.m_map,
      0);
    this->m_uidFromClassVersion = v6;
  }
  else
  {
    this->m_uidFromClassVersion = 0i64;
  }
}

// File Line: 191
// RVA: 0xE5B080
void __fastcall hkVersionPatchManager::clearProductPatches(hkVersionPatchManager *this, const char *productPrefix)
{
  unsigned int v4; // eax
  int v5; // edi
  unsigned int v6; // r14d
  __int64 i; // rsi
  const char *newName; // rdx
  __int64 v9; // rax
  hkVersionPatchManager::UidFromClassVersion *m_uidFromClassVersion; // rdi
  _QWORD **Value; // rax
  _QWORD **v12; // rax
  hkVersionPatchManager::UidFromClassVersion *v13; // rdi

  v4 = hkString::strLen(productPrefix);
  v5 = this->m_patchInfos.m_size - 1;
  v6 = v4;
  for ( i = v5; i >= 0; --i )
  {
    newName = this->m_patchInfos.m_data[i]->newName;
    if ( newName )
    {
      if ( !hkString::strNcmp(productPrefix, newName, v6) )
      {
        v9 = --this->m_patchInfos.m_size;
        if ( (_DWORD)v9 != v5 )
          this->m_patchInfos.m_data[i] = this->m_patchInfos.m_data[v9];
      }
    }
    --v5;
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_patchIndexFromUid.m_map);
  m_uidFromClassVersion = this->m_uidFromClassVersion;
  if ( m_uidFromClassVersion )
  {
    hkVersionPatchManager::UidFromClassVersion::~UidFromClassVersion(this->m_uidFromClassVersion);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkVersionPatchManager::UidFromClassVersion *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_uidFromClassVersion,
      64i64);
  }
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (hkVersionPatchManager::UidFromClassVersion *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v12[11] + 8i64))(
                                                        v12[11],
                                                        64i64);
  if ( v13 )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &v13->m_indexFromName.m_map,
      0);
    v13->m_names.m_data = 0i64;
    v13->m_names.m_size = 0;
    v13->m_names.m_capacityAndFlags = 0x80000000;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &v13->m_cachedNames.m_map,
      0);
    this->m_uidFromClassVersion = v13;
  }
  else
  {
    this->m_uidFromClassVersion = 0i64;
  }
}

// File Line: 209
// RVA: 0xE59EF0
void __fastcall hkVersionPatchManager::~hkVersionPatchManager(hkVersionPatchManager *this)
{
  hkVersionPatchManager::UidFromClassVersion *m_uidFromClassVersion; // rbx
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d

  m_uidFromClassVersion = this->m_uidFromClassVersion;
  this->vfptr = (hkBaseObjectVtbl *)&hkVersionPatchManager::`vftable;
  if ( m_uidFromClassVersion )
  {
    hkVersionPatchManager::UidFromClassVersion::~UidFromClassVersion(m_uidFromClassVersion);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkVersionPatchManager::UidFromClassVersion *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_uidFromClassVersion,
      64i64);
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_patchIndexFromUid.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_patchIndexFromUid);
  m_capacityAndFlags = this->m_patchInfos.m_capacityAndFlags;
  this->m_patchInfos.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_patchInfos.m_data,
      8 * m_capacityAndFlags);
  this->m_patchInfos.m_data = 0i64;
  this->m_patchInfos.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 214
// RVA: 0xE5AEB0
hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *__fastcall hkVersionPatchManager::getPatches(
        hkVersionPatchManager *this)
{
  return &this->m_patchInfos;
}

// File Line: 219
// RVA: 0xE5AEC0
unsigned __int64 __fastcall hkVersionPatchManager::getUid(hkVersionPatchManager *this, const char *name, int ver)
{
  return hkVersionPatchManager::UidFromClassVersion::get(this->m_uidFromClassVersion, name, ver);
}

// File Line: 224
// RVA: 0xE5AED0
const char *__fastcall hkVersionPatchManager::getClassName(hkVersionPatchManager *this, unsigned __int64 uid)
{
  return hkVersionPatchManager::UidFromClassVersion::getName(this->m_uidFromClassVersion, uid);
}

// File Line: 229
// RVA: 0xE5AEE0
int __fastcall hkVersionPatchManager::getClassVersion(hkVersionPatchManager *this, unsigned __int64 uid)
{
  return hkVersionPatchManager::UidFromClassVersion::getVersion(this->m_uidFromClassVersion, uid);
}

// File Line: 234
// RVA: 0xE5C230
_BOOL8 __fastcall isValidPatch(hkVersionPatchManager::PatchInfo *patch)
{
  if ( patch->oldVersion == -1 )
    return !patch->oldName && patch->newVersion != -1 && patch->newName;
  if ( patch->newVersion != -1 )
    return patch->oldName != 0;
  if ( !patch->oldName )
    return 0i64;
  return !patch->newName;
}

// File Line: 278
// RVA: 0xE5AEF0
__int64 __fastcall hkVersionPatchManager::findLastPatchIndexForUid(
        hkVersionPatchManager *this,
        unsigned __int64 uid,
        unsigned int allowRenames)
{
  unsigned int v5; // edi
  hkVersionPatchManager::PatchInfo *v6; // rbx
  const char *newName; // rdx
  unsigned __int64 v8; // rax

  v5 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &this->m_patchIndexFromUid.m_map,
         uid,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v5 == -1 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v6 = this->m_patchInfos.m_data[v5];
    if ( v6->newVersion == -1 )
      break;
    if ( !allowRenames )
    {
      newName = v6->newName;
      if ( newName )
      {
        if ( (unsigned int)hkString::strCmp(v6->oldName, newName) )
          break;
      }
    }
    v8 = hkVersionPatchManager::UidFromClassVersion::get(this->m_uidFromClassVersion, v6->newName, v6->newVersion);
    v5 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           &this->m_patchIndexFromUid.m_map,
           v8,
           0xFFFFFFFFFFFFFFFFui64);
    if ( v5 == -1 )
      return 0xFFFFFFFFi64;
  }
  return v5;
}

// File Line: 296
// RVA: 0xE5C280
__int64 __fastcall findPatchIndexInDependencies(
        int indexToFind,
        int startIndex,
        hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > *incoming,
        hkPointerMap<int,int,hkContainerHeapAllocator> *done)
{
  unsigned __int64 v4; // rdi
  int FirstIndex; // eax
  __int64 v9; // rdi
  int value; // edx

  v4 = startIndex;
  if ( (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
              &done->m_map,
              startIndex) <= done->m_map.m_hashMod )
    return 0i64;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &done->m_map,
    &hkContainerHeapAllocator::s_alloc,
    v4,
    0i64);
  FirstIndex = hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::getFirstIndex(incoming, v4);
  if ( FirstIndex == -1 )
    return 0i64;
  while ( 1 )
  {
    v9 = FirstIndex;
    value = incoming->m_valueChain.m_data[v9].value;
    if ( indexToFind == value || findPatchIndexInDependencies(indexToFind, value, incoming, done) )
      break;
    FirstIndex = incoming->m_valueChain.m_data[v9].next;
    if ( FirstIndex == -1 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 317
// RVA: 0xE5A120
hkResult *__fastcall hkVersionPatchManager::recomputePatchDependencies(hkVersionPatchManager *this, hkResult *result)
{
  hkVersionPatchManager::UidFromClassVersion *m_uidFromClassVersion; // r15
  __int64 v3; // r14
  hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *p_m_patchIndexFromUid; // r13
  hkVersionPatchManager *v5; // r12
  int v6; // ebx
  hkVersionPatchManager::PatchInfo *v7; // rdi
  int oldVersion; // r8d
  hkVersionPatchManager::UidFromClassVersion *v9; // rcx
  unsigned __int64 v10; // r14
  const char *newName; // rdx
  unsigned __int64 v12; // r14
  int Key; // eax
  int newVersion; // r8d
  const char *oldName; // rdx
  const void *v16; // rax
  int m_hashMod; // r9d
  bool v18; // cc
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // r8
  IAmdDxExt *v20; // rdx
  __int64 v21; // rsi
  int v22; // r8d
  IAmdDxExtQuadBufferStereo *mStereo; // r12
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // r13
  int v26; // ebx
  hkResult *v27; // rdi
  hkResult *v28; // r14
  int next; // eax
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> >::Value *v31; // rcx
  __int64 v32; // rdi
  int v33; // r15d
  hkVersionPatchManager::UidFromClassVersion *v34; // r13
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v35; // r12
  __int64 v36; // rax
  unsigned __int64 v37; // rdi
  int v38; // eax
  int v39; // eax
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> >::Value *v40; // rcx
  __int64 v41; // rdi
  int v42; // edi
  int LastPatchIndexForUid; // r14d
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> >::Value *v44; // rcx
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > *p_incoming; // rsi
  __int64 v46; // rdi
  int v47; // edx
  __int64 v48; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v49; // rax
  int v50; // esi
  int v51; // ebx
  int FirstIndex; // eax
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> >::Value *m_data; // rcx
  __int64 v54; // rdi
  int v55; // edx
  __int64 v56; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v57; // rax
  int m_size; // edi
  int mExtension; // eax
  int v60; // ebx
  __int64 v61; // rcx
  _DWORD *v62; // rdi
  int v63; // ebx
  int v64; // eax
  int v65; // ebx
  int v66; // eax
  int v67; // eax
  int v68; // r10d
  __int64 v69; // r9
  __int64 v70; // r8
  __int64 v71; // rdi
  int v72; // edi
  __int64 v73; // rbx
  hkVersionPatchManager::PatchInfo *v74; // rcx
  unsigned __int64 v75; // rax
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> > v76; // [rsp+30h] [rbp-D0h] BYREF
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> > v77; // [rsp+58h] [rbp-A8h] BYREF
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+80h] [rbp-80h] BYREF
  AMD_HD3D v79; // [rsp+90h] [rbp-70h] BYREF
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > v80; // [rsp+B0h] [rbp-50h] BYREF
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > incoming; // [rsp+D8h] [rbp-28h] BYREF
  int v82; // [rsp+100h] [rbp+0h] BYREF
  hkArray<int,hkContainerHeapAllocator> pending; // [rsp+108h] [rbp+8h] BYREF
  AMD_HD3D done; // [rsp+118h] [rbp+18h] BYREF
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *p_m_map; // [rsp+138h] [rbp+38h]
  hkVersionPatchManager::UidFromClassVersion *v86; // [rsp+140h] [rbp+40h]
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v87; // [rsp+148h] [rbp+48h] BYREF
  hkVersionPatchManager *resulta; // [rsp+1B0h] [rbp+B0h] BYREF
  hkResult *v89; // [rsp+1B8h] [rbp+B8h]
  int value; // [rsp+1C0h] [rbp+C0h] BYREF
  int v91; // [rsp+1C8h] [rbp+C8h] BYREF

  v89 = result;
  resulta = this;
  m_uidFromClassVersion = this->m_uidFromClassVersion;
  v3 = 0i64;
  p_m_patchIndexFromUid = &this->m_patchIndexFromUid;
  v5 = this;
  *(_QWORD *)&v79.mEnableStereo = 0i64;
  v79.mWidth = 0;
  v79.mHeight = -1;
  p_m_map = &this->m_patchIndexFromUid.m_map;
  v76.m_valueChain.m_data = 0i64;
  v76.m_valueChain.m_size = 0;
  v76.m_valueChain.m_capacityAndFlags = 0x80000000;
  v76.m_indexMap.m_map.m_elem = 0i64;
  v76.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&v76.m_indexMap.m_map.m_hashMod = -1i64;
  v86 = m_uidFromClassVersion;
  v77.m_valueChain.m_data = 0i64;
  v77.m_valueChain.m_size = 0;
  v77.m_valueChain.m_capacityAndFlags = 0x80000000;
  v77.m_indexMap.m_map.m_elem = 0i64;
  v77.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&v77.m_indexMap.m_map.m_hashMod = -1i64;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_patchIndexFromUid.m_map);
  v6 = 0;
  value = 0;
  if ( v5->m_patchInfos.m_size > 0 )
  {
    while ( 1 )
    {
      v7 = v5->m_patchInfos.m_data[v6];
      if ( !isValidPatch(v7) )
      {
        v28 = v89;
        v89->m_enum = HK_FAILURE;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          &v77.m_indexMap.m_map,
          &hkContainerHeapAllocator::s_alloc);
        _((AMD_HD3D *)&v77.m_indexMap);
        goto LABEL_31;
      }
      oldVersion = v7->oldVersion;
      v9 = v5->m_uidFromClassVersion;
      if ( oldVersion == -1 )
      {
        v12 = hkVersionPatchManager::UidFromClassVersion::get(v9, v7->newName, v7->newVersion);
        Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v79,
                              v12);
        if ( Key <= (int)v79.mHeight )
        {
LABEL_24:
          v27 = v89;
          v89->m_enum = HK_FAILURE;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
            &v77.m_indexMap.m_map,
            &hkContainerHeapAllocator::s_alloc);
          _((AMD_HD3D *)&v77.m_indexMap);
LABEL_25:
          v77.m_valueChain.m_size = 0;
          if ( v77.m_valueChain.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v77.m_valueChain.m_data,
              8 * v77.m_valueChain.m_capacityAndFlags);
          v77.m_valueChain.m_data = 0i64;
          v77.m_valueChain.m_capacityAndFlags = 0x80000000;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
            &v76.m_indexMap.m_map,
            &hkContainerHeapAllocator::s_alloc);
          _((AMD_HD3D *)&v76.m_indexMap);
          v76.m_valueChain.m_size = 0;
          if ( v76.m_valueChain.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              v76.m_valueChain.m_data,
              8 * v76.m_valueChain.m_capacityAndFlags);
          v76.m_valueChain.m_data = 0i64;
LABEL_126:
          v76.m_valueChain.m_capacityAndFlags = 0x80000000;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v79,
            &hkContainerHeapAllocator::s_alloc);
          _(&v79);
          return v27;
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v79,
          &hkContainerHeapAllocator::s_alloc,
          v12,
          v6);
      }
      else
      {
        v10 = hkVersionPatchManager::UidFromClassVersion::get(v9, v7->oldName, oldVersion);
        if ( (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                    &p_m_patchIndexFromUid->m_map,
                    v10) <= p_m_patchIndexFromUid->m_map.m_hashMod )
          goto LABEL_24;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &p_m_patchIndexFromUid->m_map,
          &hkContainerHeapAllocator::s_alloc,
          v10,
          v6);
        if ( v7->newVersion == -1
          || (newName = v7->newName) != 0i64 && (unsigned int)hkString::strCmp(v7->oldName, newName) )
        {
          hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::insert(
            &v77,
            v7->oldName,
            &value);
        }
      }
      newVersion = v7->newVersion;
      if ( newVersion != -1 )
      {
        oldName = v7->newName;
        if ( !oldName )
          oldName = v7->oldName;
        v16 = (const void *)hkVersionPatchManager::UidFromClassVersion::get(m_uidFromClassVersion, oldName, newVersion);
        hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::insert(
          &v76,
          v16,
          &value);
      }
      value = ++v6;
      if ( v6 >= v5->m_patchInfos.m_size )
      {
        v3 = 0i64;
        break;
      }
    }
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v87,
    0);
  m_hashMod = -1;
  v18 = v5->m_patchInfos.m_size <= 0;
  v80.m_indexMap.m_map.m_hashMod = -1;
  v80.m_freeChainStart = -1;
  incoming.m_valueChain.m_data = 0i64;
  incoming.m_valueChain.m_size = 0;
  incoming.m_valueChain.m_capacityAndFlags = 0x80000000;
  incoming.m_indexMap.m_map.m_elem = 0i64;
  incoming.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&incoming.m_indexMap.m_map.m_hashMod = -1i64;
  v80.m_valueChain.m_data = 0i64;
  v80.m_valueChain.m_size = 0;
  v80.m_valueChain.m_capacityAndFlags = 0x80000000;
  m_elem = 0i64;
  v80.m_indexMap.m_map.m_elem = 0i64;
  v80.m_indexMap.m_map.m_numElems = 0;
  value = 0;
  if ( v18 )
  {
LABEL_73:
    v47 = 0;
    v48 = 0i64;
    if ( m_hashMod >= 0 )
    {
      v49 = m_elem;
      do
      {
        if ( v49->key != -1i64 )
          break;
        ++v48;
        ++v47;
        ++v49;
      }
      while ( v48 <= m_hashMod );
    }
    v50 = v47;
    if ( v47 <= m_hashMod )
    {
      do
      {
        v51 = m_elem[v50].key;
        FirstIndex = hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::getFirstIndex(
                       &v80,
                       v51);
        if ( FirstIndex != -1 )
        {
          m_data = v80.m_valueChain.m_data;
          do
          {
            *(_QWORD *)&done.mEnableStereo = 0i64;
            done.mWidth = 0;
            v54 = FirstIndex;
            done.mHeight = -1;
            LODWORD(resulta) = m_data[v54].value;
            if ( !findPatchIndexInDependencies(
                    v51,
                    (int)resulta,
                    &incoming,
                    (hkPointerMap<int,int,hkContainerHeapAllocator> *)&done) )
              hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(
                &incoming,
                v51,
                (const int *)&resulta);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&done,
              &hkContainerHeapAllocator::s_alloc);
            _(&done);
            m_data = v80.m_valueChain.m_data;
            FirstIndex = v80.m_valueChain.m_data[v54].next;
          }
          while ( FirstIndex != -1 );
        }
        m_elem = v80.m_indexMap.m_map.m_elem;
        v55 = v50 + 1;
        v56 = v50 + 1;
        if ( v56 <= v80.m_indexMap.m_map.m_hashMod )
        {
          v57 = &v80.m_indexMap.m_map.m_elem[v55];
          do
          {
            if ( v57->key != -1i64 )
              break;
            ++v56;
            ++v55;
            ++v57;
          }
          while ( v56 <= v80.m_indexMap.m_map.m_hashMod );
        }
        v50 = v55;
      }
      while ( v55 <= v80.m_indexMap.m_map.m_hashMod );
    }
    a.m_data = 0i64;
    a.m_size = 0;
    a.m_capacityAndFlags = 0x80000000;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      &a,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v5->m_patchInfos);
    m_size = a.m_size;
    mExtension = 0;
    v79.mStereo = 0i64;
    v79.mExtension = (IAmdDxExt *)0x8000000000000000i64;
    v60 = a.m_size;
    if ( a.m_size > 0 )
    {
      hkArrayUtil::_reserve(
        (hkResult *)&resulta,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v79.mStereo,
        a.m_size,
        4);
      m_size = a.m_size;
      mExtension = (int)v79.mExtension;
    }
    v61 = v60 - mExtension;
    if ( v61 > 0 )
    {
      v62 = (_DWORD *)v79.mStereo + mExtension;
      while ( v61 )
      {
        *v62++ = -1;
        --v61;
      }
      m_size = a.m_size;
    }
    LODWORD(v79.mExtension) = v60;
    pending.m_data = 0i64;
    pending.m_size = 0;
    v63 = 0;
    pending.m_capacityAndFlags = 0x80000000;
    v64 = 0;
    if ( m_size > 0 )
    {
      do
      {
        v64 = walkDependencies(
                v63,
                (hkArray<int,hkContainerHeapAllocator> *)&v79.mStereo,
                &incoming,
                v64,
                &pending,
                (hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *)&a);
        m_size = a.m_size;
        ++v63;
      }
      while ( v63 < a.m_size );
    }
    v65 = m_size;
    v66 = v5->m_patchInfos.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v66 < m_size )
    {
      v67 = 2 * v66;
      if ( m_size < v67 )
        m_size = v67;
      hkArrayUtil::_reserve(
        (hkResult *)&resulta,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v5->m_patchInfos.m_data,
        m_size,
        8);
      m_size = a.m_size;
    }
    v5->m_patchInfos.m_size = v65;
    v68 = 0;
    if ( m_size <= 0 )
    {
LABEL_105:
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&p_m_patchIndexFromUid->m_map);
      v72 = 0;
      if ( v5->m_patchInfos.m_size > 0 )
      {
        v73 = 0i64;
        do
        {
          v74 = v5->m_patchInfos.m_data[v73];
          if ( v74->oldName )
          {
            v75 = hkVersionPatchManager::UidFromClassVersion::get(
                    v5->m_uidFromClassVersion,
                    v74->oldName,
                    v74->oldVersion);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &p_m_patchIndexFromUid->m_map,
              &hkContainerHeapAllocator::s_alloc,
              v75,
              v72);
          }
          ++v72;
          ++v73;
        }
        while ( v72 < v5->m_patchInfos.m_size );
      }
      v27 = v89;
      v89->m_enum = HK_SUCCESS;
    }
    else
    {
      v69 = 0i64;
      v70 = 0i64;
      while ( *(int *)((char *)&v79.mStereo->vfptr + v70) >= 0 )
      {
        v71 = *(int *)((char *)&v79.mStereo->vfptr + v70);
        ++v68;
        v70 += 4i64;
        v5->m_patchInfos.m_data[v71] = *(hkVersionPatchManager::PatchInfo **)((char *)&a.m_data->m_fromOffset + v69);
        v69 += 8i64;
        if ( v68 >= a.m_size )
          goto LABEL_105;
      }
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v5->m_patchInfos,
        &a);
      v27 = v89;
      v89->m_enum = HK_FAILURE;
    }
    pending.m_size = 0;
    if ( pending.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        pending.m_data,
        4 * pending.m_capacityAndFlags);
    LODWORD(v79.mExtension) = 0;
    pending.m_capacityAndFlags = 0x80000000;
    pending.m_data = 0i64;
    if ( SHIDWORD(v79.mExtension) >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v79.mStereo,
        4 * HIDWORD(v79.mExtension));
    a.m_size = 0;
    HIDWORD(v79.mExtension) = 0x80000000;
    v79.mStereo = 0i64;
    if ( a.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        a.m_data,
        8 * a.m_capacityAndFlags);
    a.m_data = 0i64;
    a.m_capacityAndFlags = 0x80000000;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v80.m_indexMap.m_map,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&v80.m_indexMap);
    v80.m_valueChain.m_size = 0;
    if ( v80.m_valueChain.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v80.m_valueChain.m_data,
        8 * v80.m_valueChain.m_capacityAndFlags);
    v80.m_valueChain.m_data = 0i64;
    v80.m_valueChain.m_capacityAndFlags = 0x80000000;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &incoming.m_indexMap.m_map,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&incoming.m_indexMap);
    incoming.m_valueChain.m_size = 0;
    if ( incoming.m_valueChain.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        incoming.m_valueChain.m_data,
        8 * incoming.m_valueChain.m_capacityAndFlags);
    incoming.m_valueChain.m_data = 0i64;
    incoming.m_valueChain.m_capacityAndFlags = 0x80000000;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v87);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v77.m_indexMap.m_map,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&v77.m_indexMap);
    v77.m_valueChain.m_size = 0;
    if ( v77.m_valueChain.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v77.m_valueChain.m_data,
        8 * v77.m_valueChain.m_capacityAndFlags);
    v77.m_valueChain.m_data = 0i64;
    v77.m_valueChain.m_capacityAndFlags = 0x80000000;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v76.m_indexMap.m_map,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&v76.m_indexMap);
    v76.m_valueChain.m_size = 0;
    if ( v76.m_valueChain.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        v76.m_valueChain.m_data,
        8 * v76.m_valueChain.m_capacityAndFlags);
    v76.m_valueChain.m_data = 0i64;
    goto LABEL_126;
  }
  v20 = 0i64;
  done.mExtension = 0i64;
  while ( 1 )
  {
    v21 = *(__int64 *)((char *)&v20->vfptr + (unsigned __int64)v5->m_patchInfos.m_data);
    v22 = *(_DWORD *)(v21 + 16);
    mStereo = *(IAmdDxExtQuadBufferStereo **)v21;
    done.mStereo = *(IAmdDxExtQuadBufferStereo **)v21;
    if ( v22 == -1 )
    {
      mStereo = *(IAmdDxExtQuadBufferStereo **)(v21 + 8);
      v22 = *(_DWORD *)(v21 + 20);
      done.mStereo = mStereo;
      if ( !mStereo || v22 == -1 )
        break;
    }
    v24 = hkVersionPatchManager::UidFromClassVersion::get(m_uidFromClassVersion, (const char *)mStereo, v22);
    v25 = v24;
    *(_QWORD *)&done.mEnableStereo = v24;
    if ( *(_DWORD *)(v21 + 16) == -1 )
    {
      v26 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v79,
              v24,
              0xFFFFFFFFFFFFFFFFui64);
      v91 = v26;
    }
    else
    {
      v26 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              p_m_map,
              v24,
              0xFFFFFFFFFFFFFFFFui64);
      v91 = v26;
      next = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
               (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v76,
               v25);
      if ( next != -1 )
      {
        v31 = v76.m_valueChain.m_data;
        do
        {
          v32 = next;
          v82 = v31[v32].value;
          hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(&incoming, v26, &v82);
          v31 = v76.m_valueChain.m_data;
          next = v76.m_valueChain.m_data[v32].next;
        }
        while ( next != -1 );
      }
    }
    v33 = 0;
    if ( *(int *)(v21 + 32) > 0 )
    {
      v34 = v86;
      v35 = p_m_map;
      do
      {
        v36 = *(_QWORD *)(v21 + 24);
        if ( *(_DWORD *)(v3 + v36) == 7 )
        {
          v37 = hkVersionPatchManager::UidFromClassVersion::get(
                  v34,
                  **(const char ***)(v3 + v36 + 8),
                  *(_DWORD *)(*(_QWORD *)(v3 + v36 + 8) + 8i64));
          v38 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  v35,
                  v37,
                  0xFFFFFFFFFFFFFFFFui64);
          if ( v38 != -1 )
            hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(&incoming, v38, &v91);
          v39 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                  (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v76,
                  v37);
          if ( v39 != -1 )
          {
            v40 = v76.m_valueChain.m_data;
            do
            {
              v41 = v39;
              v82 = v40[v41].value;
              hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(&incoming, v26, &v82);
              v40 = v76.m_valueChain.m_data;
              v39 = v76.m_valueChain.m_data[v41].next;
            }
            while ( v39 != -1 );
          }
        }
        ++v33;
        v3 += 16i64;
      }
      while ( v33 < *(_DWORD *)(v21 + 32) );
      mStereo = done.mStereo;
      v25 = *(_QWORD *)&done.mEnableStereo;
    }
    if ( *(_DWORD *)(v21 + 16) == -1
      && hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
           (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v77,
           (unsigned __int64)mStereo) != -1 )
    {
      v42 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v77,
              (unsigned __int64)mStereo);
      if ( v42 != -1 )
      {
        LastPatchIndexForUid = hkVersionPatchManager::findLastPatchIndexForUid(resulta, v25, 0);
        if ( LastPatchIndexForUid == -1 )
        {
          if ( (unsigned int)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                               (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v87,
                               (const char *)mStereo,
                               0xFFFFFFFFFFFFFFFFui64) != -1 )
          {
            v27 = v89;
            v89->m_enum = HK_FAILURE;
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              &v80.m_indexMap.m_map,
              &hkContainerHeapAllocator::s_alloc);
            _((AMD_HD3D *)&v80.m_indexMap);
            v80.m_valueChain.m_size = 0;
            if ( v80.m_valueChain.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                v80.m_valueChain.m_data,
                8 * v80.m_valueChain.m_capacityAndFlags);
            v80.m_valueChain.m_data = 0i64;
            v80.m_valueChain.m_capacityAndFlags = 0x80000000;
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              &incoming.m_indexMap.m_map,
              &hkContainerHeapAllocator::s_alloc);
            _((AMD_HD3D *)&incoming.m_indexMap);
            incoming.m_valueChain.m_size = 0;
            if ( incoming.m_valueChain.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                incoming.m_valueChain.m_data,
                8 * incoming.m_valueChain.m_capacityAndFlags);
            incoming.m_valueChain.m_data = 0i64;
            incoming.m_valueChain.m_capacityAndFlags = 0x80000000;
            hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v87);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              &v77.m_indexMap.m_map,
              &hkContainerHeapAllocator::s_alloc);
            _((AMD_HD3D *)&v77.m_indexMap);
            goto LABEL_25;
          }
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v87, (const char *)mStereo, value);
        }
        v44 = v77.m_valueChain.m_data;
        p_incoming = &incoming;
        if ( LastPatchIndexForUid != -1 )
          p_incoming = &v80;
        do
        {
          v46 = v42;
          v91 = v44[v46].value;
          if ( LastPatchIndexForUid != v91 )
          {
            hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(p_incoming, v26, &v91);
            v44 = v77.m_valueChain.m_data;
          }
          v42 = v44[v46].next;
        }
        while ( v42 != -1 );
      }
    }
    v5 = resulta;
    v20 = done.mExtension + 1;
    v3 = 0i64;
    ++value;
    ++done.mExtension;
    if ( value >= resulta->m_patchInfos.m_size )
    {
      m_hashMod = v80.m_indexMap.m_map.m_hashMod;
      m_elem = v80.m_indexMap.m_map.m_elem;
      p_m_patchIndexFromUid = &resulta->m_patchIndexFromUid;
      goto LABEL_73;
    }
    m_uidFromClassVersion = v86;
  }
  v28 = v89;
  v89->m_enum = HK_FAILURE;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v80.m_indexMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v80.m_indexMap);
  v80.m_valueChain.m_size = 0;
  if ( v80.m_valueChain.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v80.m_valueChain.m_data,
      8 * v80.m_valueChain.m_capacityAndFlags);
  v80.m_valueChain.m_data = 0i64;
  v80.m_valueChain.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &incoming.m_indexMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&incoming.m_indexMap);
  incoming.m_valueChain.m_size = 0;
  if ( incoming.m_valueChain.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      incoming.m_valueChain.m_data,
      8 * incoming.m_valueChain.m_capacityAndFlags);
  incoming.m_valueChain.m_data = 0i64;
  incoming.m_valueChain.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v87);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v77.m_indexMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v77.m_indexMap);
LABEL_31:
  v77.m_valueChain.m_size = 0;
  if ( v77.m_valueChain.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v77.m_valueChain.m_data,
      8 * v77.m_valueChain.m_capacityAndFlags);
  v77.m_valueChain.m_data = 0i64;
  v77.m_valueChain.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v76.m_indexMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v76.m_indexMap);
  v76.m_valueChain.m_size = 0;
  if ( v76.m_valueChain.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v76.m_valueChain.m_data,
      8 * v76.m_valueChain.m_capacityAndFlags);
  v76.m_valueChain.m_data = 0i64;
  v76.m_valueChain.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v79,
    &hkContainerHeapAllocator::s_alloc);
  _(&v79);
  return v28;
}

// File Line: 554
// RVA: 0xE5CB00
void __fastcall HeapArray<UidItem>::insert(HeapArray<UidItem> *this, UidItem *e)
{
  __int64 m_size; // r11
  int v3; // r10d
  __int64 v6; // r8
  int patchIndex; // edx
  __m128i *m_data; // rcx
  UidItem *v9; // rcx

  m_size = this->m_elems.m_size;
  v3 = 0;
  v6 = 0i64;
  if ( (int)m_size <= 0 )
  {
LABEL_5:
    if ( (_DWORD)m_size == (this->m_elems.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_elems.m_data, 16);
    v9 = &this->m_elems.m_data[this->m_elems.m_size];
    if ( v9 )
    {
      v9->uid = e->uid;
      *(_QWORD *)&v9->patchIndex = *(_QWORD *)&e->patchIndex;
    }
    ++this->m_elems.m_size;
  }
  else
  {
    patchIndex = e->patchIndex;
    m_data = (__m128i *)this->m_elems.m_data;
    while ( patchIndex >= _mm_cvtsi128_si32(_mm_srli_si128(*m_data, 8)) )
    {
      ++v6;
      ++v3;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
    hkArrayBase<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge>::_insertAt(
      &this->m_elems,
      &hkContainerHeapAllocator::s_alloc,
      v3,
      e);
  }
}

// File Line: 606
// RVA: 0xE5C340
void __fastcall setAllDependeciesToDo(
        HeapArray<UidItem> *todo,
        const char *classname,
        int version,
        hkDataWorld *worldToUpdate,
        hkVersionPatchManager *man,
        hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *idxNewSrcFromUid,
        hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *patchesDone)
{
  unsigned __int64 Uid; // rdi
  __int64 v10; // rax
  int v11; // ebx
  unsigned __int64 v12; // rax
  __int64 m_size; // r8
  __int64 v14; // rcx
  UidItem *m_data; // rdx
  hkVersionPatchManager *v16; // r8
  hkVersionPatchManager::PatchInfo *v17; // rsi
  int v18; // eax
  __int64 v19; // rbx
  __int64 v20; // rdi
  hkVersionPatchManager::PatchInfo::Component *component; // rax
  UidItem e; // [rsp+40h] [rbp-28h] BYREF

  Uid = hkVersionPatchManager::getUid(man, classname, version);
  v10 = ((__int64 (__fastcall *)(hkDataWorld *, const char *))worldToUpdate->vfptr[4].__first_virtual_table_function__)(
          worldToUpdate,
          classname);
  v11 = -1;
  if ( !v10 || (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v10 + 24i64))(v10) != version )
    v11 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            &idxNewSrcFromUid->m_map,
            Uid,
            0xFFFFFFFFFFFFFFFFui64);
  v12 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          &patchesDone->m_map,
          Uid,
          0i64);
  e.uid = v12;
  if ( v11 == -1 || (_DWORD)v12 == 1 )
  {
    v11 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            &man->m_patchIndexFromUid.m_map,
            Uid,
            0xFFFFFFFFFFFFFFFFui64);
    LODWORD(v12) = e.uid;
  }
  e.uid = Uid;
  e.patchIndex = v11;
  if ( (_DWORD)v12 != 2 )
  {
    m_size = todo->m_elems.m_size;
    v14 = 0i64;
    if ( m_size <= 0 )
    {
LABEL_12:
      HeapArray<UidItem>::insert(todo, &e);
    }
    else
    {
      m_data = todo->m_elems.m_data;
      while ( Uid != m_data->uid )
      {
        ++v14;
        ++m_data;
        if ( v14 >= m_size )
          goto LABEL_12;
      }
    }
  }
  if ( v11 >= 0 )
  {
    v16 = man;
    v17 = man->m_patchInfos.m_data[v11];
    v18 = v17->numComponent - 1;
    v19 = v18;
    if ( v18 >= 0 )
    {
      v20 = v18;
      do
      {
        component = v17->component;
        if ( component[v20].type == PATCH_DEPENDS )
        {
          setAllDependeciesToDo(
            todo,
            *(const char **)component[v20].patch,
            *((_DWORD *)component[v20].patch + 2),
            worldToUpdate,
            v16,
            idxNewSrcFromUid,
            patchesDone);
          v16 = man;
        }
        --v20;
        --v19;
      }
      while ( v19 >= 0 );
    }
  }
}

// File Line: 737
// RVA: 0xE5B400
hkResult *__fastcall hkVersionPatchManager::preparePatches(
        hkVersionPatchManager *this,
        hkResult *result,
        hkDataWorld *worldToUpdate,
        hkVersionPatchManager::ClassWrapper *wrapper,
        hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *patchInfosOut)
{
  hkBaseObjectVtbl *vfptr; // rax
  __int64 v8; // r14
  hkDataWorld *v10; // r15
  int v11; // eax
  int v12; // esi
  __int64 v13; // rbx
  __int64 v14; // r15
  int v15; // eax
  int v16; // ecx
  __int64 *v17; // rdx
  __int64 v18; // rax
  bool v19; // cc
  int v20; // esi
  hkVersionPatchManager::PatchInfo *v21; // rbx
  unsigned __int64 v22; // rbx
  int Key; // eax
  hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *v24; // r12
  int m_capacityAndFlags; // r8d
  int v26; // esi
  __int64 v27; // rbx
  int m_size; // eax
  UidItem *m_data; // rcx
  unsigned __int64 uid; // rsi
  __int64 v31; // rbx
  int v32; // eax
  UidItem *v33; // rdx
  __int64 v34; // r8
  unsigned __int64 v35; // rax
  unsigned __int64 v36; // r9
  __int64 v37; // rbx
  hkVersionPatchManager::PatchInfo *v38; // rsi
  hkVersionPatchManager::PatchInfo *v39; // rcx
  const char *v40; // rdx
  const char *ClassName; // r14
  unsigned int ClassVersion; // esi
  __int64 v44; // rax
  __int64 v45; // rbx
  int v46; // eax
  __int64 v47; // rbx
  hkVersionPatchManager::PatchInfo *v48; // r14
  const char *oldName; // r13
  const char *newName; // r15
  int oldVersion; // eax
  hkDataClassDict *v52; // rax
  int v53; // eax
  __int64 v54; // rdi
  __int64 v55; // rsi
  __int64 v56; // r8
  const char *v57; // rdx
  unsigned int v58; // ebx
  hkOstream *v59; // rax
  hkOstream *v60; // rax
  hkOstream *v61; // rax
  hkOstream *v62; // rax
  hkOstream *v63; // rax
  hkOstream *v64; // rax
  hkOstream *v65; // rax
  int v66; // r9d
  unsigned int v67; // ecx
  int v68; // r8d
  hkResult *v69; // rbx
  hkOstream *v70; // rax
  hkOstream *v71; // rax
  __int64 v72; // rbx
  hkTypeManager::Type *Type; // rax
  int v74; // esi
  __int64 v75; // rdi
  unsigned __int64 v76; // rbx
  const char *v77; // rax
  int v78; // edi
  __int64 v79; // rsi
  __int64 *v80; // rbx
  const char *v81; // rax
  bool v82; // zf
  __int64 v83; // rax
  const char *v84; // rax
  Dummy *Iterator; // rdi
  hkDataWorld *v86; // rsi
  unsigned __int64 Value; // rax
  hkBaseObjectVtbl *v88; // rbx
  __int64 v89; // rax
  HeapArray<UidItem> todo; // [rsp+40h] [rbp-C0h] BYREF
  char *array; // [rsp+50h] [rbp-B0h] BYREF
  int v92; // [rsp+58h] [rbp-A8h]
  int v93; // [rsp+5Ch] [rbp-A4h]
  char *v94; // [rsp+60h] [rbp-A0h] BYREF
  int numElem; // [rsp+68h] [rbp-98h]
  int v96; // [rsp+6Ch] [rbp-94h]
  AMD_HD3D idxNewSrcFromUid; // [rsp+70h] [rbp-90h] BYREF
  hkErrStream v98; // [rsp+90h] [rbp-70h] BYREF
  __int64 i; // [rsp+A8h] [rbp-58h]
  hkDataClass::Cinfo cinfo; // [rsp+B0h] [rbp-50h] BYREF
  hkDataClass parent; // [rsp+D8h] [rbp-28h] BYREF
  hkDataWorldDict v102; // [rsp+E0h] [rbp-20h] BYREF
  char buf[560]; // [rsp+200h] [rbp+100h] BYREF
  hkDataClass resulta; // [rsp+440h] [rbp+340h] BYREF
  hkResult *v105; // [rsp+448h] [rbp+348h]
  hkDataWorld *v106; // [rsp+450h] [rbp+350h]

  v106 = worldToUpdate;
  v105 = result;
  vfptr = worldToUpdate->vfptr;
  v8 = 0i64;
  v10 = worldToUpdate;
  v96 = 0x80000000;
  v94 = 0i64;
  numElem = 0;
  vfptr[4].__vecDelDtor(worldToUpdate, (unsigned int)&v94);
  v11 = numElem;
  array = 0i64;
  v92 = 0;
  v93 = 0x80000000;
  if ( numElem > 0 )
  {
    hkArrayUtil::_reserve((hkResult *)&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&array, numElem, 16);
    v11 = numElem;
  }
  v12 = 0;
  if ( v11 > 0 )
  {
    do
    {
      v13 = *(_QWORD *)&v94[v8 * 8];
      if ( (*(int (__fastcall **)(__int64))(*(_QWORD *)v13 + 24i64))(v13) < 0 )
      {
        hkErrStream::hkErrStream(&v98, buf, 512);
        hkOstream::operator<<(
          &v98,
          "Intermediate version found in a release build. The asset probably needs to be re-exported");
        if ( (unsigned int)hkError::messageError(0x54D3B666u, buf, "Version\\hkVersionPatchManager.cpp", 758) )
          __debugbreak();
        hkOstream::~hkOstream(&v98);
      }
      else
      {
        v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 16i64))(v13);
        v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 24i64))(v13);
        v16 = v92;
        todo.m_elems.m_size = v15;
        v17 = (__int64 *)&array[16 * v92];
        if ( v17 )
        {
          v18 = *(_QWORD *)&todo.m_elems.m_size;
          *v17 = v14;
          v17[1] = v18;
          v16 = v92;
        }
        v92 = v16 + 1;
      }
      ++v12;
      ++v8;
    }
    while ( v12 < numElem );
    v10 = v106;
    v8 = 0i64;
  }
  hkDataWorldDict::hkDataWorldDict(&v102);
  v19 = this->m_patchInfos.m_size <= 0;
  *(_QWORD *)&idxNewSrcFromUid.mEnableStereo = 0i64;
  idxNewSrcFromUid.mWidth = 0;
  idxNewSrcFromUid.mHeight = -1;
  v20 = 0;
  if ( !v19 )
  {
    do
    {
      v21 = this->m_patchInfos.m_data[v8];
      if ( !isValidPatch(v21) )
      {
LABEL_35:
        result->m_enum = HK_FAILURE;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid,
          &hkContainerHeapAllocator::s_alloc);
        _(&idxNewSrcFromUid);
        hkDataWorldDict::~hkDataWorldDict(&v102);
        v92 = 0;
        if ( v93 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v93);
        array = 0i64;
        v93 = 0x80000000;
        numElem = 0;
        if ( v96 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v94, 8 * v96);
        return result;
      }
      if ( v21->oldVersion == -1 )
      {
        v22 = hkVersionPatchManager::UidFromClassVersion::get(
                this->m_uidFromClassVersion,
                v21->newName,
                v21->newVersion);
        Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid,
                              v22);
        if ( Key <= (int)idxNewSrcFromUid.mHeight )
          goto LABEL_35;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid,
          &hkContainerHeapAllocator::s_alloc,
          v22,
          v20);
      }
      ++v20;
      ++v8;
    }
    while ( v20 < this->m_patchInfos.m_size );
  }
  v19 = v92 <= 0;
  v24 = patchInfosOut;
  m_capacityAndFlags = 0x80000000;
  idxNewSrcFromUid.mStereo = 0i64;
  idxNewSrcFromUid.mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
  patchInfosOut->m_size = 0;
  todo.m_elems.m_data = 0i64;
  todo.m_elems.m_size = 0;
  todo.m_elems.m_capacityAndFlags = 0x80000000;
  v26 = 0;
  if ( v19 )
  {
LABEL_45:
    todo.m_elems.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        todo.m_elems.m_data,
        16 * m_capacityAndFlags);
    v46 = v24->m_size - 1;
    v47 = v46;
    for ( i = v46; v47 >= 0; i = --v47 )
    {
      v48 = v24->m_data[v47];
      oldName = v48->oldName;
      newName = v48->oldName;
      if ( v48->newName )
        newName = v48->newName;
      resulta.m_impl = hkDataWorldDict::findClass(&v102, newName);
      if ( !resulta.m_impl )
      {
        oldVersion = v48->oldVersion;
        memset(&cinfo.parent, 0, 20);
        cinfo.members.m_capacityAndFlags = 0x80000000;
        cinfo.name = newName;
        cinfo.version = oldVersion;
        v52 = hkDataWorldDict::newClass(&v102, &cinfo);
        cinfo.members.m_size = 0;
        resulta.m_impl = v52;
        if ( cinfo.members.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            cinfo.members.m_data,
            24 * (cinfo.members.m_capacityAndFlags & 0x3FFFFFFF));
      }
      v53 = v48->numComponent - 1;
      v54 = v53;
      if ( v53 >= 0 )
      {
        v55 = v53;
        do
        {
          v56 = (__int64)&v48->component[v55];
          switch ( *(_DWORD *)v56 )
          {
            case 1:
              hkDataWorldDict::removeClassMember(&v102, &resulta, **(char ***)(v56 + 8));
              break;
            case 2:
              v72 = *(_QWORD *)(v56 + 8);
              Type = hkTypeManager::getType(
                       &v102.m_typeManager,
                       (hkLegacyType::Type)*(_DWORD *)(v72 + 8),
                       *(const char **)(v72 + 16),
                       *(_DWORD *)(v72 + 24));
              hkDataWorldDict::addClassMember(&v102, &resulta, *(char **)v72, Type, 0i64);
              break;
            case 3:
              hkDataWorldDict::renameClassMember(
                &v102,
                &resulta,
                *(char **)(*(_QWORD *)(v56 + 8) + 8i64),
                **(char ***)(v56 + 8));
              break;
            case 7:
              hkDataWorldDict::findClass(&v102, **(const char ***)(v56 + 8));
              break;
            case 8:
              v57 = **(const char ***)(v56 + 8);
              if ( v57 )
              {
                parent.m_impl = hkDataWorldDict::findClass(&v102, v57);
                hkDataWorldDict::setClassParent(&v102, &resulta, &parent);
              }
              else
              {
                todo.m_elems.m_data = 0i64;
                hkDataWorldDict::setClassParent(&v102, &resulta, (hkDataClass *)&todo);
              }
              break;
          }
          --v55;
          --v54;
        }
        while ( v54 >= 0 );
        v47 = i;
      }
      if ( v48->oldVersion == -1 )
      {
        hkDataWorldDict::removeClass(&v102, &resulta);
      }
      else
      {
        if ( newName != oldName && (unsigned int)hkString::strCmp(newName, oldName) )
          hkDataWorldDict::renameClass(&v102, &resulta, oldName);
        hkDataWorldDict::setClassVersion(&v102, &resulta, v48->oldVersion);
      }
    }
    todo.m_elems.m_data = 0i64;
    todo.m_elems.m_size = 0;
    todo.m_elems.m_capacityAndFlags = 0x80000000;
    hkDataWorldDict::findAllClasses(&v102, (hkArray<hkDataClassImpl *,hkContainerTempAllocator> *)&todo);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v98,
      0);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&cinfo,
      0);
    v74 = 0;
    if ( todo.m_elems.m_size > 0 )
    {
      v75 = 0i64;
      do
      {
        v76 = *(unsigned __int64 *)((char *)&todo.m_elems.m_data->uid + v75);
        v77 = (const char *)(*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)v76 + 16i64))(v76);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
          (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v98,
          v77,
          v76);
        ++v74;
        v75 += 8i64;
      }
      while ( v74 < todo.m_elems.m_size );
    }
    v78 = 0;
    if ( numElem > 0 )
    {
      v79 = 0i64;
      do
      {
        v80 = *(__int64 **)&v94[v79];
        v81 = (const char *)(*(__int64 (__fastcall **)(__int64 *))(*v80 + 16))(v80);
        v82 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v98,
                v81,
                0i64) == 0;
        v83 = *v80;
        if ( v82 )
        {
          (*(void (__fastcall **)(__int64 *))(v83 + 24))(v80);
        }
        else
        {
          v84 = (const char *)(*(__int64 (__fastcall **)(__int64 *))(v83 + 16))(v80);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
            (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v98,
            (hkResult *)&resulta,
            v84);
        }
        ++v78;
        v79 += 8i64;
      }
      while ( v78 < numElem );
    }
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v98);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v98,
      (hkBool *)&resulta,
      Iterator);
    if ( LOBYTE(resulta.m_impl) )
    {
      v86 = v106;
      do
      {
        Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v98,
                  Iterator);
        v88 = v86->vfptr;
        v89 = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)Value + 16i64))(Value);
        ((void (__fastcall *)(hkDataWorld *, __int64, hkDataWorldDict *))v88[11].__first_virtual_table_function__)(
          v86,
          v89,
          &v102);
        Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                     (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v98,
                     Iterator);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v98,
          (hkBool *)&resulta,
          Iterator);
      }
      while ( LOBYTE(resulta.m_impl) );
    }
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>((hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&cinfo);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>((hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v98);
    todo.m_elems.m_size = 0;
    if ( todo.m_elems.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        todo.m_elems.m_data,
        8 * todo.m_elems.m_capacityAndFlags);
    v69 = v105;
    v105->m_enum = HK_SUCCESS;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid.mStereo,
      &hkContainerHeapAllocator::s_alloc);
    _((AMD_HD3D *)&idxNewSrcFromUid.mStereo);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid,
      &hkContainerHeapAllocator::s_alloc);
    _(&idxNewSrcFromUid);
    hkDataWorldDict::~hkDataWorldDict(&v102);
    v92 = 0;
    if ( v93 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v93);
    array = 0i64;
    numElem = 0;
    goto LABEL_100;
  }
  v27 = 0i64;
  do
  {
    setAllDependeciesToDo(
      &todo,
      *(const char **)&array[v27],
      *(_DWORD *)&array[v27 + 8],
      v10,
      this,
      (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&idxNewSrcFromUid,
      (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&idxNewSrcFromUid.mStereo);
    ++v26;
    v27 += 16i64;
  }
  while ( v26 < v92 );
  m_size = todo.m_elems.m_size;
  if ( !todo.m_elems.m_size )
  {
LABEL_44:
    m_capacityAndFlags = todo.m_elems.m_capacityAndFlags;
    goto LABEL_45;
  }
  while ( 1 )
  {
    m_data = todo.m_elems.m_data;
    uid = todo.m_elems.m_data->uid;
    v31 = *(_QWORD *)&todo.m_elems.m_data->patchIndex;
    todo.m_elems.m_size = m_size - 1;
    v32 = 16 * (m_size - 1);
    v33 = todo.m_elems.m_data + 1;
    if ( v32 > 0 )
    {
      v34 = ((unsigned int)(v32 - 1) >> 3) + 1;
      do
      {
        v35 = v33->uid;
        m_data = (UidItem *)((char *)m_data + 8);
        v33 = (UidItem *)((char *)v33 + 8);
        *(_QWORD *)&m_data[-1].patchIndex = v35;
        --v34;
      }
      while ( v34 );
    }
    if ( (_DWORD)v31 == -1 || (v36 = 1i64, this->m_patchInfos.m_data[(int)v31]->oldVersion != -1) )
      v36 = 2i64;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid.mStereo,
      &hkContainerHeapAllocator::s_alloc,
      uid,
      v36);
    if ( (int)v31 >= 0 )
    {
      v37 = (int)v31;
      v38 = this->m_patchInfos.m_data[v37];
      if ( v24->m_size == (v24->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v24->m_data, 8);
      v24->m_data[v24->m_size++] = v38;
      v39 = this->m_patchInfos.m_data[v37];
      v40 = v39->newName;
      if ( !v40 )
        v40 = v39->oldName;
      setAllDependeciesToDo(
        &todo,
        v40,
        v39->newVersion,
        v10,
        this,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&idxNewSrcFromUid,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&idxNewSrcFromUid.mStereo);
      goto LABEL_43;
    }
    ClassName = hkVersionPatchManager::getClassName(this, uid);
    ClassVersion = hkVersionPatchManager::getClassVersion(this, uid);
    if ( ClassVersion != -1 )
      break;
LABEL_43:
    m_size = todo.m_elems.m_size;
    if ( !todo.m_elems.m_size )
      goto LABEL_44;
  }
  v44 = ((__int64 (__fastcall *)(hkVersionPatchManager::ClassWrapper *, hkDataWorldDict *, const char *))wrapper->vfptr[1].__first_virtual_table_function__)(
          wrapper,
          &v102,
          ClassName);
  v45 = v44;
  if ( v44 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v44 + 24i64))(v44) != ClassVersion )
    {
      hkErrStream::hkErrStream(&v98, buf, 512);
      v58 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v45 + 24i64))(v45);
      v59 = hkOstream::operator<<(&v98, "Source contains ");
      v60 = hkOstream::operator<<(v59, ClassName);
      v61 = hkOstream::operator<<(v60, " version ");
      v62 = hkOstream::operator<<(v61, ClassVersion);
      v63 = hkOstream::operator<<(v62, ", but  ");
      v64 = hkOstream::operator<<(v63, v58);
      v65 = hkOstream::operator<<(v64, " is the current version.\n");
      hkOstream::operator<<(v65, "Make sure required patches are registered to update this class.");
      v66 = 849;
      v67 = 1064951217;
      goto LABEL_63;
    }
    goto LABEL_43;
  }
  hkErrStream::hkErrStream(&v98, buf, 512);
  v70 = hkOstream::operator<<(&v98, "Class ");
  v71 = hkOstream::operator<<(v70, ClassName);
  hkOstream::operator<<(
    v71,
    " is not registered. If this is a Havok class, make sure the classs product reflection is enabled near where hkProdu"
    "ctFeatures.cxx is included. Otherwise, check your own class registration.");
  v66 = 842;
  v67 = 1064951216;
LABEL_63:
  hkError::messageWarning(v67, buf, "Version\\hkVersionPatchManager.cpp", v66);
  hkOstream::~hkOstream(&v98);
  v68 = todo.m_elems.m_capacityAndFlags;
  v69 = v105;
  v105->m_enum = HK_FAILURE;
  todo.m_elems.m_size = 0;
  if ( v68 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, todo.m_elems.m_data, 16 * v68);
  todo.m_elems.m_data = 0i64;
  todo.m_elems.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid.mStereo,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&idxNewSrcFromUid.mStereo);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid,
    &hkContainerHeapAllocator::s_alloc);
  _(&idxNewSrcFromUid);
  hkDataWorldDict::~hkDataWorldDict(&v102);
  v92 = 0;
  if ( v93 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v93);
  array = 0i64;
  numElem = 0;
LABEL_100:
  v93 = 0x80000000;
  if ( v96 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v94, 8 * v96);
  return v69;
}

// File Line: 1025
// RVA: 0xE59FB0
hkResult *__fastcall hkVersionPatchManager::applyPatches(
        hkVersionPatchManager *this,
        hkResult *result,
        hkDataWorld *worldToUpdate,
        hkDefaultClassWrapper *classWrapper)
{
  hkDefaultClassWrapper *v8; // r9
  hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> patchInfos; // [rsp+30h] [rbp-38h] BYREF
  hkDefaultClassWrapper v11; // [rsp+40h] [rbp-28h] BYREF
  hkResult resulta; // [rsp+78h] [rbp+10h] BYREF

  hkDefaultClassWrapper::hkDefaultClassWrapper(&v11, 0i64);
  v8 = &v11;
  if ( classWrapper )
    v8 = classWrapper;
  patchInfos.m_capacityAndFlags = 0x80000000;
  patchInfos.m_data = 0i64;
  patchInfos.m_size = 0;
  hkVersionPatchManager::preparePatches(this, result, worldToUpdate, v8, &patchInfos);
  if ( result->m_enum == HK_SUCCESS )
    result->m_enum = applyPatchesFinally(&resulta, worldToUpdate, &patchInfos)->m_enum;
  patchInfos.m_size = 0;
  if ( patchInfos.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      patchInfos.m_data,
      8 * patchInfos.m_capacityAndFlags);
  patchInfos.m_data = 0i64;
  patchInfos.m_capacityAndFlags = 0x80000000;
  if ( v11.m_nameReg.m_pntr )
    hkReferencedObject::removeReference(v11.m_nameReg.m_pntr);
  return result;
}

// File Line: 1046
// RVA: 0xE5AE80
hkResult *__fastcall hkVersionPatchManager::applyPatchesDebug(
        hkVersionPatchManager *this,
        hkResult *result,
        hkDataWorld *worldToUpdate)
{
  applyPatchesFinally(result, worldToUpdate, &this->m_patchInfos);
  return result;
}

// File Line: 1053
// RVA: 0xE5C4D0
hkResult *__fastcall applyPatchesFinally(
        hkResult *result,
        hkDataWorld *worldToUpdate,
        hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *patchInfos)
{
  int v3; // edi
  hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *v4; // r13
  hkResult *v6; // r12
  int v7; // r12d
  __int64 v8; // r14
  __int64 v9; // r15
  const char *v10; // rbx
  hkBaseObjectVtbl *v11; // rax
  const char *v12; // rdx
  int v13; // edi
  __int64 v14; // r13
  __int64 v15; // rdx
  __int64 v16; // rbx
  hkTypeManager *v17; // rax
  hkTypeManager::Type *Type; // rax
  void (__fastcall *v19)(__int64 *); // r14
  hkBaseObjectVtbl *vfptr; // rax
  __int64 v21; // rbx
  __int64 v22; // rcx
  __int64 v23; // rcx
  bool v24; // zf
  __int64 v25; // rax
  hkBaseObjectVtbl *v26; // rax
  __int64 v27; // rbx
  __int64 v28; // rcx
  __int64 v29; // rcx
  int v30; // r8d
  int v31; // eax
  int v32; // eax
  __int64 v34; // [rsp+30h] [rbp-59h] BYREF
  char *v35; // [rsp+38h] [rbp-51h] BYREF
  int v36; // [rsp+40h] [rbp-49h]
  int v37; // [rsp+44h] [rbp-45h]
  char *v38; // [rsp+48h] [rbp-41h] BYREF
  int v39; // [rsp+50h] [rbp-39h]
  int v40; // [rsp+54h] [rbp-35h]
  const char *v41; // [rsp+58h] [rbp-31h]
  __int64 v42; // [rsp+60h] [rbp-29h]
  __int64 v43; // [rsp+68h] [rbp-21h] BYREF
  __int64 v44; // [rsp+70h] [rbp-19h] BYREF
  const char *v45; // [rsp+78h] [rbp-11h] BYREF
  int v46; // [rsp+80h] [rbp-9h]
  __int64 v47; // [rsp+88h] [rbp-1h]
  void *v48; // [rsp+90h] [rbp+7h]
  int v49; // [rsp+98h] [rbp+Fh]
  int v50; // [rsp+9Ch] [rbp+13h]
  __int64 v51; // [rsp+A0h] [rbp+17h] BYREF
  __int64 v52[7]; // [rsp+A8h] [rbp+1Fh] BYREF
  int v55; // [rsp+108h] [rbp+7Fh]

  v3 = 0;
  v4 = patchInfos;
  v6 = result;
  v55 = 0;
  if ( patchInfos->m_size <= 0 )
  {
LABEL_58:
    v6->m_enum = HK_SUCCESS;
    return v6;
  }
  v7 = 0;
  v8 = 0i64;
  v42 = 0i64;
  while ( 1 )
  {
    v9 = *(__int64 *)((char *)v4->m_data + v8);
    v10 = *(const char **)v9;
    v41 = v10;
    if ( !v10 )
    {
      v10 = *(const char **)(v9 + 8);
      v41 = v10;
    }
    if ( *(_DWORD *)(v9 + 16) == -1 )
      break;
LABEL_9:
    v34 = ((__int64 (__fastcall *)(hkDataWorld *, const char *))worldToUpdate->vfptr[4].__first_virtual_table_function__)(
            worldToUpdate,
            v10);
    if ( *(_QWORD *)v9 )
    {
      v12 = *(const char **)(v9 + 8);
      if ( v12 )
      {
        if ( (unsigned int)hkString::strCmp(*(const char **)v9, v12) )
        {
          ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD))worldToUpdate->vfptr[6].__vecDelDtor)(
            worldToUpdate,
            &v34,
            *(_QWORD *)(v9 + 8));
          v10 = *(const char **)(v9 + 8);
          v41 = v10;
        }
      }
    }
    if ( *(int *)(v9 + 32) > 0 )
    {
      v13 = 0;
      v14 = 0i64;
      do
      {
        v15 = v14 + *(_QWORD *)(v9 + 24);
        switch ( *(_DWORD *)v15 )
        {
          case 1:
            v16 = *(_QWORD *)(v15 + 8);
            v17 = (hkTypeManager *)((__int64 (__fastcall *)(hkDataWorld *))worldToUpdate->vfptr[5].__first_virtual_table_function__)(worldToUpdate);
            Type = hkTypeManager::getType(
                     v17,
                     (hkLegacyType::Type)*(_DWORD *)(v16 + 8),
                     *(const char **)(v16 + 16),
                     *(_DWORD *)(v16 + 24));
            ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD, hkTypeManager::Type *, _QWORD))worldToUpdate->vfptr[8].__vecDelDtor)(
              worldToUpdate,
              &v34,
              *(_QWORD *)v16,
              Type,
              *(_QWORD *)(v16 + 32));
            break;
          case 2:
            ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD))worldToUpdate->vfptr[9].__first_virtual_table_function__)(
              worldToUpdate,
              &v34,
              **(_QWORD **)(v15 + 8));
            break;
          case 3:
            ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD, _QWORD))worldToUpdate->vfptr[9].__vecDelDtor)(
              worldToUpdate,
              &v34,
              **(_QWORD **)(v15 + 8),
              *(_QWORD *)(*(_QWORD *)(v15 + 8) + 8i64));
            break;
          case 4:
            ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD, _QWORD))worldToUpdate->vfptr[8].__first_virtual_table_function__)(
              worldToUpdate,
              &v34,
              **(_QWORD **)(v15 + 8),
              *(_QWORD *)(*(_QWORD *)(v15 + 8) + 8i64));
            break;
          case 5:
            v19 = *(void (__fastcall **)(__int64 *))(*(_QWORD *)(v15 + 8) + 8i64);
            vfptr = worldToUpdate->vfptr;
            v38 = 0i64;
            v39 = 0;
            v40 = 0x80000000;
            ((void (__fastcall *)(hkDataWorld *, const char *, char **))vfptr[10].__vecDelDtor)(
              worldToUpdate,
              v10,
              &v38);
            if ( v39 > 0 )
            {
              v21 = 0i64;
              do
              {
                v22 = *(_QWORD *)&v38[v21];
                v44 = v22;
                if ( v22 )
                {
                  ++*(_WORD *)(v22 + 10);
                  ++*(_DWORD *)(v22 + 12);
                }
                v19(&v44);
                v23 = v44;
                if ( v44 )
                {
                  --*(_WORD *)(v44 + 10);
                  v24 = (*(_DWORD *)(v23 + 12))-- == 1;
                  if ( v24 )
                    (**(void (__fastcall ***)(__int64, __int64))v23)(v23, 1i64);
                }
                ++v13;
                v21 += 8i64;
              }
              while ( v13 < v39 );
            }
            v13 = 0;
            v39 = 0;
            if ( v40 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v38, 8 * v40);
            v38 = 0i64;
            v40 = 0x80000000;
            break;
          case 6:
            v52[0] = ((__int64 (__fastcall *)(hkDataWorld *, _QWORD))worldToUpdate->vfptr[4].__first_virtual_table_function__)(
                       worldToUpdate,
                       **(_QWORD **)(v15 + 8));
            v26 = worldToUpdate->vfptr;
            v35 = 0i64;
            v36 = 0;
            v37 = 0x80000000;
            ((void (__fastcall *)(hkDataWorld *, const char *, char **))v26[10].__first_virtual_table_function__)(
              worldToUpdate,
              v10,
              &v35);
            if ( v36 > 0 )
            {
              v27 = 0i64;
              do
              {
                v28 = *(_QWORD *)&v35[v27];
                v43 = v28;
                if ( v28 )
                {
                  ++*(_WORD *)(v28 + 10);
                  ++*(_DWORD *)(v28 + 12);
                }
                ((void (__fastcall *)(hkDataWorld *, __int64 *, __int64 *))worldToUpdate->vfptr[11].__vecDelDtor)(
                  worldToUpdate,
                  &v43,
                  v52);
                v29 = v43;
                if ( v43 )
                {
                  --*(_WORD *)(v43 + 10);
                  v24 = (*(_DWORD *)(v29 + 12))-- == 1;
                  if ( v24 )
                    (**(void (__fastcall ***)(__int64, __int64))v29)(v29, 1i64);
                }
                ++v13;
                v27 += 8i64;
              }
              while ( v13 < v36 );
            }
            v13 = 0;
            v36 = 0;
            if ( v37 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v35, 8 * v37);
            v35 = 0i64;
            v37 = 0x80000000;
            break;
          case 8:
            if ( *(_QWORD *)(*(_QWORD *)(v15 + 8) + 8i64) )
              v25 = ((__int64 (__fastcall *)(hkDataWorld *))worldToUpdate->vfptr[4].__first_virtual_table_function__)(worldToUpdate);
            else
              v25 = 0i64;
            v51 = v25;
            ((void (__fastcall *)(hkDataWorld *, __int64 *, __int64 *))worldToUpdate->vfptr[7].__first_virtual_table_function__)(
              worldToUpdate,
              &v34,
              &v51);
            break;
          default:
            break;
        }
        v10 = v41;
        ++v7;
        v14 += 16i64;
      }
      while ( v7 < *(_DWORD *)(v9 + 32) );
      v3 = v55;
      v8 = v42;
      v4 = patchInfos;
    }
    v30 = *(_DWORD *)(v9 + 20);
    if ( v30 == -1 )
    {
      ((void (__fastcall *)(hkDataWorld *, __int64 *))worldToUpdate->vfptr[6].__first_virtual_table_function__)(
        worldToUpdate,
        &v34);
    }
    else
    {
      v31 = *(_DWORD *)(v9 + 16);
      if ( v31 != -1 && v31 != v30 )
        worldToUpdate->vfptr[7].__vecDelDtor(worldToUpdate, (unsigned int)&v34);
    }
    ++v3;
    v8 += 8i64;
    v55 = v3;
    v42 = v8;
    if ( v3 >= v4->m_size )
    {
      v6 = result;
      goto LABEL_58;
    }
    v7 = 0;
  }
  v46 = *(_DWORD *)(v9 + 20);
  v11 = worldToUpdate->vfptr;
  v48 = 0i64;
  v49 = 0;
  v50 = 0x80000000;
  v45 = v10;
  v47 = 0i64;
  if ( !((__int64 (__fastcall *)(hkDataWorld *, const char *))v11[4].__first_virtual_table_function__)(
          worldToUpdate,
          v10) )
  {
    ((void (__fastcall *)(hkDataWorld *, const char **))worldToUpdate->vfptr[1].__first_virtual_table_function__)(
      worldToUpdate,
      &v45);
    v49 = 0;
    if ( v50 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v48, 24 * (v50 & 0x3FFFFFFF));
    goto LABEL_9;
  }
  v6 = result;
  v32 = v50;
  v49 = 0;
  result->m_enum = HK_FAILURE;
  if ( v32 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v48, 24 * (v32 & 0x3FFFFFFF));
  return v6;
}

// File Line: 1213
// RVA: 0xE5A0A0
void __fastcall hkVersionPatchManager::addPatch(hkVersionPatchManager *this, hkVersionPatchManager::PatchInfo *p)
{
  if ( isValidPatch(p) )
  {
    if ( this->m_patchInfos.m_size == (this->m_patchInfos.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_patchInfos.m_data, 8);
    this->m_patchInfos.m_data[this->m_patchInfos.m_size++] = p;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_patchIndexFromUid.m_map);
  }
}

