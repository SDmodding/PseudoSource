// File Line: 29
// RVA: 0xE5C080
void __fastcall hkVersionPatchManagercreate()
{
  _QWORD **v0; // rax
  hkVersionPatchManager *v1; // rax

  v0 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v1 = (hkVersionPatchManager *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v0[11] + 8i64))(v0[11], 56i64);
  if ( v1 )
    hkVersionPatchManager::hkVersionPatchManager(v1);
}

// File Line: 42
// RVA: 0xE5C000
void __fastcall hkDefaultClassWrapper::hkDefaultClassWrapper(hkDefaultClassWrapper *this, hkClassNameRegistry *nameReg)
{
  hkClassNameRegistry *v2; // rdi
  hkDefaultClassWrapper *v3; // rbx
  hkReferencedObject *v4; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = nameReg;
  this->vfptr = (hkBaseObjectVtbl *)&hkDefaultClassWrapper::`vftable';
  v3 = this;
  this->m_nameReg.m_pntr = 0i64;
  if ( !nameReg )
    v2 = (hkClassNameRegistry *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
  if ( v2 )
    hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
  v4 = (hkReferencedObject *)&v3->m_nameReg.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_nameReg.m_pntr = v2;
}

// File Line: 53
// RVA: 0xE5BF70
hkDataClassDict *__fastcall hkDefaultClassWrapper::wrapClass(hkDefaultClassWrapper *this, hkDataWorld *world, const char *typeName)
{
  hkDataWorldDict *v3; // rbx
  hkDefaultClassWrapper *v4; // rsi
  const char *v5; // rdi
  hkDataClassDict *result; // rax
  hkClass *v7; // rdi
  char v8; // [rsp+38h] [rbp+10h]

  v3 = (hkDataWorldDict *)world;
  v4 = this;
  v5 = typeName;
  result = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataWorld *, const char *))world->vfptr[4].__first_virtual_table_function__)(
                                world,
                                typeName);
  if ( !result )
  {
    v7 = (hkClass *)v4->m_nameReg.m_pntr->vfptr[2].__vecDelDtor(
                      (hkBaseObject *)&v4->m_nameReg.m_pntr->vfptr,
                      (unsigned int)v5);
    if ( v7 && *(_DWORD *)v3->vfptr[3].__vecDelDtor((hkBaseObject *)&v3->vfptr, (unsigned int)&v8) == 1 )
      result = hkDataWorldDict::wrapClass(v3, v7);
    else
      result = 0i64;
  }
  return result;
}

// File Line: 92
// RVA: 0xE5C0C0
__int64 __fastcall walkDependencies(int curIndex, hkArray<int,hkContainerHeapAllocator> *order, hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > *incoming, int counter, hkArray<int,hkContainerHeapAllocator> *pending, hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *patchInfos)
{
  int v6; // esi
  int v7; // edi
  bool v8; // zf
  __int64 v9; // rcx
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > *v10; // rbp
  int i; // eax
  __int64 v12; // rsi
  int v13; // er8
  signed __int64 v15; // [rsp+30h] [rbp-18h]
  __int64 v16; // [rsp+38h] [rbp-10h]
  hkArray<int,hkContainerHeapAllocator> *ordera; // [rsp+58h] [rbp+10h]

  ordera = order;
  v6 = curIndex;
  v7 = counter;
  v8 = order->m_data[curIndex] == -1;
  v9 = curIndex;
  v10 = incoming;
  v16 = v9 * 4;
  if ( !v8 )
    return (unsigned int)counter;
  order->m_data[v9] = -2;
  if ( pending->m_size == (pending->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, pending, 4);
  pending->m_data[pending->m_size++] = v6;
  for ( i = hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::getFirstIndex(v10, v6);
        i != -1;
        i = v10->m_valueChain.m_data[v15].next )
  {
    v12 = v10->m_valueChain.m_data[i].value;
    v15 = i;
    v13 = ordera->m_data[v12];
    if ( v13 == -2 )
    {
      if ( pending->m_size == (pending->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, pending, 4);
      pending->m_data[pending->m_size] = v12;
    }
    else if ( v13 == -1 )
    {
      v7 = walkDependencies(v12, ordera, v10, v7, pending, patchInfos);
    }
  }
  --pending->m_size;
  *(int *)((char *)ordera->m_data + v16) = v7;
  return (unsigned int)(v7 + 1);
}

// File Line: 128
// RVA: 0xE5B1C0
void __fastcall hkVersionPatchManager::UidFromClassVersion::~UidFromClassVersion(hkVersionPatchManager::UidFromClassVersion *this)
{
  hkVersionPatchManager::UidFromClassVersion *v1; // rdi
  Dummy *v2; // rbp
  void *v3; // rbx
  hkMemoryAllocator **v4; // rax
  int v5; // er8
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_cachedNames);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_cachedNames,
    &result,
    v2);
  while ( result.m_bool )
  {
    v3 = (void *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_cachedNames,
                   v2);
    v4 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    hkMemoryRouter::easyFree(v4[11], v3);
    v2 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_cachedNames,
           v2);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_cachedNames,
      &result,
      v2);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_cachedNames.m_map);
  v5 = v1->m_names.m_capacityAndFlags;
  v1->m_names.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_names.m_data,
      8 * v5);
  v1->m_names.m_data = 0i64;
  v1->m_names.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_indexFromName.m_map);
}

// File Line: 136
// RVA: 0xE5B2C0
unsigned __int64 __fastcall hkVersionPatchManager::UidFromClassVersion::get(hkVersionPatchManager::UidFromClassVersion *this, const char *name, int ver)
{
  __int64 v3; // rbp
  hkVersionPatchManager::UidFromClassVersion *v4; // rbx
  const char *v5; // rsi
  unsigned int v6; // edi

  v3 = ver;
  v4 = this;
  v5 = hkVersionPatchManager::UidFromClassVersion::cache(this, name);
  v6 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getOrInsert(
         &v4->m_indexFromName.m_map,
         (unsigned __int64)v5,
         v4->m_names.m_size);
  if ( v6 == v4->m_names.m_size )
  {
    if ( v4->m_names.m_size == (v4->m_names.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_names, 8);
    v4->m_names.m_data[v4->m_names.m_size++] = v5;
  }
  return v6 | (unsigned __int64)(v3 << 32);
}

// File Line: 148
// RVA: 0xE5B360
const char *__fastcall hkVersionPatchManager::UidFromClassVersion::getName(hkVersionPatchManager::UidFromClassVersion *this, unsigned __int64 uid)
{
  return this->m_names.m_data[(signed int)uid];
}

// File Line: 154
// RVA: 0xE5B380
__int64 __fastcall hkVersionPatchManager::UidFromClassVersion::getVersion(hkVersionPatchManager::UidFromClassVersion *this, unsigned __int64 uid)
{
  return HIDWORD(uid);
}

// File Line: 159
// RVA: 0xE5B390
char *__fastcall hkVersionPatchManager::UidFromClassVersion::cache(hkVersionPatchManager::UidFromClassVersion *this, const char *name)
{
  const char *v2; // rdi
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v3; // rsi
  char *v4; // rbx

  v2 = name;
  if ( !name )
    return 0i64;
  v3 = &this->m_cachedNames.m_map;
  v4 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_cachedNames,
                 (unsigned __int64)name,
                 0i64);
  if ( !v4 )
  {
    v4 = hkString::strDup(v2);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      v3,
      (unsigned __int64)v4,
      (unsigned __int64)v4);
  }
  return v4;
}

// File Line: 174
// RVA: 0xE59E30
void __fastcall hkVersionPatchManager::hkVersionPatchManager(hkVersionPatchManager *this)
{
  hkVersionPatchManager *v1; // rbx
  _QWORD **v2; // rax
  __int64 v3; // rdi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkVersionPatchManager::`vftable';
  this->m_patchInfos.m_data = 0i64;
  this->m_patchInfos.m_size = 0;
  this->m_patchInfos.m_capacityAndFlags = 2147483648;
  v1 = this;
  this->m_patchIndexFromUid.m_map.m_elem = 0i64;
  this->m_patchIndexFromUid.m_map.m_numElems = 0;
  this->m_patchIndexFromUid.m_map.m_hashMod = -1;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 64i64);
  if ( v3 )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v3,
      0);
    *(_QWORD *)(v3 + 24) = 0i64;
    *(_DWORD *)(v3 + 32) = 0;
    *(_DWORD *)(v3 + 36) = 2147483648;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)(v3 + 40),
      0);
    v1->m_uidFromClassVersion = (hkVersionPatchManager::UidFromClassVersion *)v3;
  }
  else
  {
    v1->m_uidFromClassVersion = 0i64;
  }
}

// File Line: 179
// RVA: 0xE5AFB0
void __fastcall hkVersionPatchManager::clearPatches(hkVersionPatchManager *this)
{
  hkVersionPatchManager *v1; // rbx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v2; // rcx
  hkVersionPatchManager::UidFromClassVersion *v3; // rdi
  _QWORD **v4; // rax
  _QWORD **v5; // rax
  __int64 v6; // rdi

  v1 = this;
  v2 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_patchIndexFromUid.m_map.m_elem;
  v2[-1].m_numElems = 0;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(v2);
  v3 = v1->m_uidFromClassVersion;
  if ( v3 )
  {
    hkVersionPatchManager::UidFromClassVersion::~UidFromClassVersion(v1->m_uidFromClassVersion);
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkVersionPatchManager::UidFromClassVersion *, signed __int64))(*v4[11] + 16i64))(
      v4[11],
      v3,
      64i64);
  }
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 64i64);
  if ( v6 )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v6,
      0);
    *(_QWORD *)(v6 + 24) = 0i64;
    *(_DWORD *)(v6 + 32) = 0;
    *(_DWORD *)(v6 + 36) = 2147483648;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)(v6 + 40),
      0);
    v1->m_uidFromClassVersion = (hkVersionPatchManager::UidFromClassVersion *)v6;
  }
  else
  {
    v1->m_uidFromClassVersion = 0i64;
  }
}

// File Line: 191
// RVA: 0xE5B080
void __fastcall hkVersionPatchManager::clearProductPatches(hkVersionPatchManager *this, const char *productPrefix)
{
  hkVersionPatchManager *v2; // rbx
  const char *v3; // rbp
  int v4; // eax
  int v5; // edi
  int v6; // er14
  __int64 i; // rsi
  const char *v8; // rdx
  __int64 v9; // rax
  hkVersionPatchManager::UidFromClassVersion *v10; // rdi
  _QWORD **v11; // rax
  _QWORD **v12; // rax
  __int64 v13; // rdi

  v2 = this;
  v3 = productPrefix;
  v4 = hkString::strLen(productPrefix);
  v5 = v2->m_patchInfos.m_size - 1;
  v6 = v4;
  for ( i = v5; i >= 0; --i )
  {
    v8 = v2->m_patchInfos.m_data[i]->newName;
    if ( v8 )
    {
      if ( !hkString::strNcmp(v3, v8, v6) )
      {
        v9 = --v2->m_patchInfos.m_size;
        if ( (_DWORD)v9 != v5 )
          v2->m_patchInfos.m_data[i] = v2->m_patchInfos.m_data[v9];
      }
    }
    --v5;
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_patchIndexFromUid.m_map.m_elem);
  v10 = v2->m_uidFromClassVersion;
  if ( v10 )
  {
    hkVersionPatchManager::UidFromClassVersion::~UidFromClassVersion(v2->m_uidFromClassVersion);
    v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkVersionPatchManager::UidFromClassVersion *, signed __int64))(*v11[11] + 16i64))(
      v11[11],
      v10,
      64i64);
  }
  v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(v12[11], 64i64);
  if ( v13 )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v13,
      0);
    *(_QWORD *)(v13 + 24) = 0i64;
    *(_DWORD *)(v13 + 32) = 0;
    *(_DWORD *)(v13 + 36) = 2147483648;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)(v13 + 40),
      0);
    v2->m_uidFromClassVersion = (hkVersionPatchManager::UidFromClassVersion *)v13;
  }
  else
  {
    v2->m_uidFromClassVersion = 0i64;
  }
}

// File Line: 209
// RVA: 0xE59EF0
void __fastcall hkVersionPatchManager::~hkVersionPatchManager(hkVersionPatchManager *this)
{
  hkVersionPatchManager::UidFromClassVersion *v1; // rbx
  hkVersionPatchManager *v2; // rdi
  _QWORD **v3; // rax
  int v4; // er8

  v1 = this->m_uidFromClassVersion;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkVersionPatchManager::`vftable';
  if ( v1 )
  {
    hkVersionPatchManager::UidFromClassVersion::~UidFromClassVersion(v1);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkVersionPatchManager::UidFromClassVersion *, signed __int64))(*v3[11] + 16i64))(
      v3[11],
      v1,
      64i64);
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_patchIndexFromUid.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v2->m_patchIndexFromUid);
  v4 = v2->m_patchInfos.m_capacityAndFlags;
  v2->m_patchInfos.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_patchInfos.m_data,
      8 * v4);
  v2->m_patchInfos.m_data = 0i64;
  v2->m_patchInfos.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 214
// RVA: 0xE5AEB0
hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *__fastcall hkVersionPatchManager::getPatches(hkVersionPatchManager *this)
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
signed __int64 __fastcall isValidPatch(hkVersionPatchManager::PatchInfo *patch)
{
  if ( patch->oldVersion == -1 )
  {
    if ( patch->oldName || patch->newVersion == -1 || !patch->newName )
      return 0i64;
    return 1i64;
  }
  if ( patch->newVersion != -1 )
  {
    if ( patch->oldName )
      return 1i64;
    return 0i64;
  }
  if ( !patch->oldName )
    return 0i64;
  if ( patch->newName )
    return 0i64;
  return 1i64;
}

// File Line: 278
// RVA: 0xE5AEF0
signed __int64 __fastcall hkVersionPatchManager::findLastPatchIndexForUid(hkVersionPatchManager *this, unsigned __int64 uid, unsigned int allowRenames)
{
  unsigned int v3; // ebp
  hkVersionPatchManager *v4; // rsi
  unsigned int v5; // edi
  hkVersionPatchManager::PatchInfo *v6; // rbx
  const char *v7; // rdx
  unsigned __int64 v8; // rax

  v3 = allowRenames;
  v4 = this;
  v5 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_patchIndexFromUid.m_map.m_elem,
         uid,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v5 == -1 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v6 = v4->m_patchInfos.m_data[v5];
    if ( v6->newVersion == -1 )
      break;
    if ( !v3 )
    {
      v7 = v6->newName;
      if ( v7 )
      {
        if ( (unsigned int)hkString::strCmp(v6->oldName, v7) )
          break;
      }
    }
    v8 = hkVersionPatchManager::UidFromClassVersion::get(v4->m_uidFromClassVersion, v6->newName, v6->newVersion);
    v5 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_patchIndexFromUid.m_map.m_elem,
           v8,
           0xFFFFFFFFFFFFFFFFui64);
    if ( v5 == -1 )
      return 0xFFFFFFFFi64;
  }
  return v5;
}

// File Line: 296
// RVA: 0xE5C280
signed __int64 __fastcall findPatchIndexInDependencies(int indexToFind, int startIndex, hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > *incoming, hkPointerMap<int,int,hkContainerHeapAllocator> *done)
{
  unsigned __int64 v4; // rdi
  int v5; // esi
  hkPointerMap<int,int,hkContainerHeapAllocator> *v6; // rbp
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > *v7; // rbx
  int v8; // eax
  signed __int64 v9; // rdi
  int v10; // edx

  v4 = startIndex;
  v5 = indexToFind;
  v6 = done;
  v7 = incoming;
  if ( (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&done->m_map.m_elem,
                     startIndex) <= done->m_map.m_hashMod )
    return 0i64;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    v4,
    0i64);
  v8 = hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::getFirstIndex(v7, v4);
  if ( v8 == -1 )
    return 0i64;
  while ( 1 )
  {
    v9 = v8;
    v10 = v7->m_valueChain.m_data[v9].value;
    if ( v5 == v10 || findPatchIndexInDependencies(v5, v10, v7, v6) )
      break;
    v8 = v7->m_valueChain.m_data[v9].next;
    if ( v8 == -1 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 317
// RVA: 0xE5A120
hkResult *__fastcall hkVersionPatchManager::recomputePatchDependencies(hkVersionPatchManager *this, hkResult *result)
{
  hkVersionPatchManager::UidFromClassVersion *v2; // r15
  __int64 v3; // r14
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v4; // r13
  hkVersionPatchManager *v5; // r12
  int v6; // ebx
  hkVersionPatchManager::PatchInfo *v7; // rdi
  int v8; // er8
  hkVersionPatchManager::UidFromClassVersion *v9; // rcx
  unsigned __int64 v10; // r14
  const char *v11; // rdx
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // r14
  int v14; // eax
  int v15; // er8
  const char *v16; // rdx
  const void *v17; // rax
  int v18; // er9
  bool v19; // zf
  bool v20; // sf
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v21; // r8
  __int64 v22; // rdx
  __int64 v23; // rsi
  int v24; // er8
  const char *v25; // r12
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v26; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v27; // r13
  int v28; // ebx
  hkResult *v29; // rdi
  hkResult *v30; // r14
  int v32; // eax
  int v33; // eax
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> >::Value *v34; // rcx
  __int64 v35; // rdi
  int v36; // er15
  hkVersionPatchManager::UidFromClassVersion *v37; // r13
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v38; // r12
  __int64 v39; // rax
  unsigned __int64 v40; // rax
  unsigned __int64 v41; // rdi
  int v42; // eax
  int v43; // eax
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> >::Value *v44; // rcx
  __int64 v45; // rdi
  int v46; // edi
  int v47; // er14
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> >::Value *v48; // rcx
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > *v49; // rsi
  signed __int64 v50; // rdi
  int v51; // edx
  signed __int64 v52; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v53; // rax
  int v54; // esi
  int v55; // ebx
  int v56; // eax
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> >::Value *v57; // rcx
  __int64 v58; // rdi
  int v59; // edx
  signed __int64 v60; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v61; // rax
  int v62; // edi
  int v63; // eax
  int v64; // ebx
  __int64 v65; // rcx
  char *v66; // rdi
  int v67; // ebx
  int v68; // eax
  int v69; // ebx
  int v70; // eax
  int v71; // eax
  int v72; // er10
  __int64 v73; // r9
  __int64 v74; // r8
  __int64 v75; // rdi
  int v76; // edi
  __int64 v77; // rbx
  hkVersionPatchManager::PatchInfo *v78; // rcx
  unsigned __int64 v79; // rax
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> > v80; // [rsp+30h] [rbp-D0h]
  hkSerializeMultiMap<void const *,int,hkPointerMap<void const *,int,hkContainerHeapAllocator> > v81; // [rsp+58h] [rbp-A8h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+80h] [rbp-80h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v83; // [rsp+90h] [rbp-70h]
  char *array; // [rsp+A0h] [rbp-60h]
  int v85; // [rsp+A8h] [rbp-58h]
  int v86; // [rsp+ACh] [rbp-54h]
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > v87; // [rsp+B0h] [rbp-50h]
  hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator> > incoming; // [rsp+D8h] [rbp-28h]
  int v89; // [rsp+100h] [rbp+0h]
  hkArray<int,hkContainerHeapAllocator> pending; // [rsp+108h] [rbp+8h]
  hkPointerMap<int,int,hkContainerHeapAllocator> done; // [rsp+118h] [rbp+18h]
  const char *v92; // [rsp+128h] [rbp+28h]
  __int64 v93; // [rsp+130h] [rbp+30h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v94; // [rsp+138h] [rbp+38h]
  hkVersionPatchManager::UidFromClassVersion *v95; // [rsp+140h] [rbp+40h]
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v96; // [rsp+148h] [rbp+48h]
  hkVersionPatchManager *resulta; // [rsp+1B0h] [rbp+B0h]
  hkResult *v98; // [rsp+1B8h] [rbp+B8h]
  int value; // [rsp+1C0h] [rbp+C0h]
  int v100; // [rsp+1C8h] [rbp+C8h]

  v98 = result;
  resulta = this;
  v2 = this->m_uidFromClassVersion;
  v3 = 0i64;
  v4 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_patchIndexFromUid.m_map.m_elem;
  v5 = this;
  v83.m_elem = 0i64;
  v83.m_numElems = 0;
  v83.m_hashMod = -1;
  v94 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_patchIndexFromUid.m_map.m_elem;
  v80.m_valueChain.m_data = 0i64;
  v80.m_valueChain.m_size = 0;
  v80.m_valueChain.m_capacityAndFlags = 2147483648;
  v80.m_indexMap.m_map.m_elem = 0i64;
  v80.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&v80.m_indexMap.m_map.m_hashMod = -1i64;
  v95 = v2;
  v81.m_valueChain.m_data = 0i64;
  v81.m_valueChain.m_size = 0;
  v81.m_valueChain.m_capacityAndFlags = 2147483648;
  v81.m_indexMap.m_map.m_elem = 0i64;
  v81.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&v81.m_indexMap.m_map.m_hashMod = -1i64;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_patchIndexFromUid.m_map.m_elem);
  v6 = 0;
  value = 0;
  if ( v5->m_patchInfos.m_size > 0 )
  {
    while ( 1 )
    {
      v7 = v5->m_patchInfos.m_data[v6];
      if ( !isValidPatch(v7) )
      {
        v30 = v98;
        v98->m_enum = 1;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81.m_indexMap.m_map.m_elem,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
        _((AMD_HD3D *)&v81.m_indexMap);
        goto LABEL_31;
      }
      v8 = v7->oldVersion;
      v9 = v5->m_uidFromClassVersion;
      if ( v8 == -1 )
      {
        v12 = hkVersionPatchManager::UidFromClassVersion::get(v9, v7->newName, v7->newVersion);
        v13 = v12;
        v14 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v83,
                                  v12);
        if ( v14 <= v83.m_hashMod )
        {
LABEL_24:
          v29 = v98;
          v98->m_enum = 1;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81.m_indexMap.m_map.m_elem,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
          _((AMD_HD3D *)&v81.m_indexMap);
LABEL_25:
          v81.m_valueChain.m_size = 0;
          if ( v81.m_valueChain.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v81.m_valueChain.m_data,
              8 * v81.m_valueChain.m_capacityAndFlags);
          v81.m_valueChain.m_data = 0i64;
          v81.m_valueChain.m_capacityAndFlags = 2147483648;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v80.m_indexMap.m_map.m_elem,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
          _((AMD_HD3D *)&v80.m_indexMap);
          v80.m_valueChain.m_size = 0;
          if ( v80.m_valueChain.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              v80.m_valueChain.m_data,
              8 * v80.m_valueChain.m_capacityAndFlags);
          v80.m_valueChain.m_data = 0i64;
LABEL_128:
          v80.m_valueChain.m_capacityAndFlags = 2147483648;
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
            &v83,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
          _((AMD_HD3D *)&v83);
          return v29;
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v83,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v13,
          v6);
      }
      else
      {
        v10 = hkVersionPatchManager::UidFromClassVersion::get(v9, v7->oldName, v8);
        if ( (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                           v4,
                           v10) <= v4->m_hashMod )
          goto LABEL_24;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          v4,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v10,
          v6);
        if ( v7->newVersion == -1 || (v11 = v7->newName) != 0i64 && (unsigned int)hkString::strCmp(v7->oldName, v11) )
          hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::insert(
            &v81,
            v7->oldName,
            &value);
      }
      v15 = v7->newVersion;
      if ( v15 != -1 )
      {
        v16 = v7->newName;
        if ( !v16 )
          v16 = v7->oldName;
        v17 = (const void *)hkVersionPatchManager::UidFromClassVersion::get(v2, v16, v15);
        hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::insert(
          &v80,
          v17,
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
    &v96,
    0);
  v18 = -1;
  v19 = v5->m_patchInfos.m_size == 0;
  v20 = v5->m_patchInfos.m_size < 0;
  v87.m_indexMap.m_map.m_hashMod = -1;
  v87.m_freeChainStart = -1;
  incoming.m_valueChain.m_data = 0i64;
  incoming.m_valueChain.m_size = 0;
  incoming.m_valueChain.m_capacityAndFlags = 2147483648;
  incoming.m_indexMap.m_map.m_elem = 0i64;
  incoming.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&incoming.m_indexMap.m_map.m_hashMod = -1i64;
  v87.m_valueChain.m_data = 0i64;
  v87.m_valueChain.m_size = 0;
  v87.m_valueChain.m_capacityAndFlags = 2147483648;
  v21 = 0i64;
  v87.m_indexMap.m_map.m_elem = 0i64;
  v87.m_indexMap.m_map.m_numElems = 0;
  value = 0;
  if ( v20 || v19 )
  {
LABEL_73:
    v51 = 0;
    v52 = 0i64;
    if ( v18 >= 0 )
    {
      v53 = v21;
      do
      {
        if ( v53->key != -1i64 )
          break;
        ++v52;
        ++v51;
        ++v53;
      }
      while ( v52 <= v18 );
    }
    v54 = v51;
    if ( v51 <= v18 )
    {
      do
      {
        v55 = v21[v54].key;
        v56 = hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::getFirstIndex(
                &v87,
                v21[v54].key);
        if ( v56 != -1 )
        {
          v57 = v87.m_valueChain.m_data;
          do
          {
            done.m_map.m_elem = 0i64;
            done.m_map.m_numElems = 0;
            v58 = v56;
            done.m_map.m_hashMod = -1;
            LODWORD(resulta) = v57[v58].value;
            if ( !findPatchIndexInDependencies(v55, (int)resulta, &incoming, &done) )
              hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(
                &incoming,
                v55,
                (const int *)&resulta);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&done.m_map.m_elem,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
            _((AMD_HD3D *)&done);
            v57 = v87.m_valueChain.m_data;
            v56 = v87.m_valueChain.m_data[v58].next;
          }
          while ( v56 != -1 );
        }
        v21 = v87.m_indexMap.m_map.m_elem;
        v59 = v54 + 1;
        v60 = v54 + 1;
        if ( v60 <= v87.m_indexMap.m_map.m_hashMod )
        {
          v61 = &v87.m_indexMap.m_map.m_elem[v59];
          do
          {
            if ( v61->key != -1i64 )
              break;
            ++v60;
            ++v59;
            ++v61;
          }
          while ( v60 <= v87.m_indexMap.m_map.m_hashMod );
        }
        v54 = v59;
      }
      while ( v59 <= v87.m_indexMap.m_map.m_hashMod );
    }
    a.m_data = 0i64;
    a.m_size = 0;
    a.m_capacityAndFlags = 2147483648;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      &a,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v5->m_patchInfos);
    v62 = a.m_size;
    v63 = 0;
    array = 0i64;
    v85 = 0;
    v86 = 2147483648;
    v64 = a.m_size;
    if ( a.m_size > 0 )
    {
      if ( a.m_size < 0 )
        v62 = 0;
      hkArrayUtil::_reserve(
        (hkResult *)&resulta,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array,
        v62,
        4);
      v62 = a.m_size;
      v63 = v85;
    }
    v65 = v64 - v63;
    if ( v65 > 0 )
    {
      v66 = &array[4 * v63];
      while ( v65 )
      {
        *(_DWORD *)v66 = -1;
        v66 += 4;
        --v65;
      }
      v62 = a.m_size;
    }
    v85 = v64;
    pending.m_data = 0i64;
    pending.m_size = 0;
    v67 = 0;
    pending.m_capacityAndFlags = 2147483648;
    v68 = 0;
    if ( v62 > 0 )
    {
      do
      {
        v68 = walkDependencies(
                v67,
                (hkArray<int,hkContainerHeapAllocator> *)&array,
                &incoming,
                v68,
                &pending,
                (hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *)&a);
        v62 = a.m_size;
        ++v67;
      }
      while ( v67 < a.m_size );
    }
    v69 = v62;
    v70 = v5->m_patchInfos.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v70 < v62 )
    {
      v71 = 2 * v70;
      if ( v62 < v71 )
        v62 = v71;
      hkArrayUtil::_reserve(
        (hkResult *)&resulta,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v5->m_patchInfos,
        v62,
        8);
      v62 = a.m_size;
    }
    v5->m_patchInfos.m_size = v69;
    v72 = 0;
    if ( v62 <= 0 )
    {
LABEL_107:
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(v4);
      v76 = 0;
      if ( v5->m_patchInfos.m_size > 0 )
      {
        v77 = 0i64;
        do
        {
          v78 = v5->m_patchInfos.m_data[v77];
          if ( v78->oldName )
          {
            v79 = hkVersionPatchManager::UidFromClassVersion::get(
                    v5->m_uidFromClassVersion,
                    v78->oldName,
                    v78->oldVersion);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              v4,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v79,
              v76);
          }
          ++v76;
          ++v77;
        }
        while ( v76 < v5->m_patchInfos.m_size );
      }
      v29 = v98;
      v98->m_enum = 0;
    }
    else
    {
      v73 = 0i64;
      v74 = 0i64;
      while ( *(_DWORD *)&array[v74] >= 0 )
      {
        v75 = *(signed int *)&array[v74];
        ++v72;
        v74 += 4i64;
        v5->m_patchInfos.m_data[v75] = *(hkVersionPatchManager::PatchInfo **)((char *)&a.m_data->m_fromOffset + v73);
        v73 += 8i64;
        if ( v72 >= a.m_size )
          goto LABEL_107;
      }
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v5->m_patchInfos,
        &a);
      v29 = v98;
      v98->m_enum = 1;
    }
    pending.m_size = 0;
    if ( pending.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        pending.m_data,
        4 * pending.m_capacityAndFlags);
    v85 = 0;
    pending.m_capacityAndFlags = 2147483648;
    pending.m_data = 0i64;
    if ( v86 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        4 * v86);
    a.m_size = 0;
    v86 = 2147483648;
    array = 0i64;
    if ( a.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        a.m_data,
        8 * a.m_capacityAndFlags);
    a.m_data = 0i64;
    a.m_capacityAndFlags = 2147483648;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v87.m_indexMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v87.m_indexMap);
    v87.m_valueChain.m_size = 0;
    if ( v87.m_valueChain.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v87.m_valueChain.m_data,
        8 * v87.m_valueChain.m_capacityAndFlags);
    v87.m_valueChain.m_data = 0i64;
    v87.m_valueChain.m_capacityAndFlags = 2147483648;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&incoming.m_indexMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&incoming.m_indexMap);
    incoming.m_valueChain.m_size = 0;
    if ( incoming.m_valueChain.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        incoming.m_valueChain.m_data,
        8 * incoming.m_valueChain.m_capacityAndFlags);
    incoming.m_valueChain.m_data = 0i64;
    incoming.m_valueChain.m_capacityAndFlags = 2147483648;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v96);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81.m_indexMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v81.m_indexMap);
    v81.m_valueChain.m_size = 0;
    if ( v81.m_valueChain.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v81.m_valueChain.m_data,
        8 * v81.m_valueChain.m_capacityAndFlags);
    v81.m_valueChain.m_data = 0i64;
    v81.m_valueChain.m_capacityAndFlags = 2147483648;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v80.m_indexMap.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v80.m_indexMap);
    v80.m_valueChain.m_size = 0;
    if ( v80.m_valueChain.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v80.m_valueChain.m_data,
        8 * v80.m_valueChain.m_capacityAndFlags);
    v80.m_valueChain.m_data = 0i64;
    goto LABEL_128;
  }
  v22 = 0i64;
  v93 = 0i64;
  while ( 1 )
  {
    v23 = *(__int64 *)((char *)v5->m_patchInfos.m_data + v22);
    v24 = *(_DWORD *)(v23 + 16);
    v25 = *(const char **)v23;
    v92 = *(const char **)v23;
    if ( v24 == -1 )
    {
      v25 = *(const char **)(v23 + 8);
      v24 = *(_DWORD *)(v23 + 20);
      v92 = v25;
      if ( !v25 || v24 == -1 )
        break;
    }
    v26 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)hkVersionPatchManager::UidFromClassVersion::get(
                                                                                                     v2,
                                                                                                     v25,
                                                                                                     v24);
    v27 = v26;
    done.m_map.m_elem = v26;
    if ( *(_DWORD *)(v23 + 16) == -1 )
    {
      v28 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &v83,
              (unsigned __int64)v26,
              0xFFFFFFFFFFFFFFFFui64);
      v100 = v28;
    }
    else
    {
      v32 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              v94,
              (unsigned __int64)v26,
              0xFFFFFFFFFFFFFFFFui64);
      v28 = v32;
      v100 = v32;
      v33 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v80,
              (unsigned __int64)v27);
      if ( v33 != -1 )
      {
        v34 = v80.m_valueChain.m_data;
        do
        {
          v35 = v33;
          v89 = v34[v33].value;
          hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(&incoming, v28, &v89);
          v34 = v80.m_valueChain.m_data;
          v33 = v80.m_valueChain.m_data[v35].next;
        }
        while ( v33 != -1 );
      }
    }
    v36 = 0;
    if ( *(_DWORD *)(v23 + 32) > 0 )
    {
      v37 = v95;
      v38 = v94;
      do
      {
        v39 = *(_QWORD *)(v23 + 24);
        if ( *(_DWORD *)(v3 + v39) == 7 )
        {
          v40 = hkVersionPatchManager::UidFromClassVersion::get(
                  v37,
                  **(const char ***)(v3 + v39 + 8),
                  *(_DWORD *)(*(_QWORD *)(v3 + v39 + 8) + 8i64));
          v41 = v40;
          v42 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  v38,
                  v40,
                  0xFFFFFFFFFFFFFFFFui64);
          if ( v42 != -1 )
            hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(&incoming, v42, &v100);
          v43 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                  (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v80,
                  v41);
          if ( v43 != -1 )
          {
            v44 = v80.m_valueChain.m_data;
            do
            {
              v45 = v43;
              v89 = v44[v43].value;
              hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(&incoming, v28, &v89);
              v44 = v80.m_valueChain.m_data;
              v43 = v80.m_valueChain.m_data[v45].next;
            }
            while ( v43 != -1 );
          }
        }
        ++v36;
        v3 += 16i64;
      }
      while ( v36 < *(_DWORD *)(v23 + 32) );
      v25 = v92;
      v27 = done.m_map.m_elem;
    }
    if ( *(_DWORD *)(v23 + 16) == -1
      && hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
           (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v81,
           (unsigned __int64)v25) != -1 )
    {
      v46 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v81,
              (unsigned __int64)v25);
      if ( v46 != -1 )
      {
        v47 = hkVersionPatchManager::findLastPatchIndexForUid(resulta, (unsigned __int64)v27, 0);
        if ( v47 == -1 )
        {
          if ( (unsigned int)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                               (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v96,
                               (unsigned __int64)v25,
                               0xFFFFFFFFFFFFFFFFui64) != -1 )
          {
            v29 = v98;
            v98->m_enum = 1;
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v87.m_indexMap.m_map.m_elem,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
            _((AMD_HD3D *)&v87.m_indexMap);
            v87.m_valueChain.m_size = 0;
            if ( v87.m_valueChain.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                v87.m_valueChain.m_data,
                8 * v87.m_valueChain.m_capacityAndFlags);
            v87.m_valueChain.m_data = 0i64;
            v87.m_valueChain.m_capacityAndFlags = 2147483648;
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&incoming.m_indexMap.m_map.m_elem,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
            _((AMD_HD3D *)&incoming.m_indexMap);
            incoming.m_valueChain.m_size = 0;
            if ( incoming.m_valueChain.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                incoming.m_valueChain.m_data,
                8 * incoming.m_valueChain.m_capacityAndFlags);
            incoming.m_valueChain.m_data = 0i64;
            incoming.m_valueChain.m_capacityAndFlags = 2147483648;
            hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v96);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81.m_indexMap.m_map.m_elem,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
            _((AMD_HD3D *)&v81.m_indexMap);
            goto LABEL_25;
          }
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v96, (unsigned __int64)v25, value);
        }
        v48 = v81.m_valueChain.m_data;
        v49 = &incoming;
        if ( v47 != -1 )
          v49 = &v87;
        do
        {
          v50 = v46;
          v100 = v48[v50].value;
          if ( v47 != v100 )
          {
            hkSerializeMultiMap<int,int,hkPointerMap<int,int,hkContainerHeapAllocator>>::insert(v49, v28, &v100);
            v48 = v81.m_valueChain.m_data;
          }
          v46 = v48[v50].next;
        }
        while ( v46 != -1 );
      }
    }
    v5 = resulta;
    v22 = v93 + 8;
    v3 = 0i64;
    ++value;
    v93 += 8i64;
    if ( value >= resulta->m_patchInfos.m_size )
    {
      v18 = v87.m_indexMap.m_map.m_hashMod;
      v21 = v87.m_indexMap.m_map.m_elem;
      v4 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&resulta->m_patchIndexFromUid.m_map.m_elem;
      goto LABEL_73;
    }
    v2 = v95;
  }
  v30 = v98;
  v98->m_enum = 1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v87.m_indexMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v87.m_indexMap);
  v87.m_valueChain.m_size = 0;
  if ( v87.m_valueChain.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v87.m_valueChain.m_data,
      8 * v87.m_valueChain.m_capacityAndFlags);
  v87.m_valueChain.m_data = 0i64;
  v87.m_valueChain.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&incoming.m_indexMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&incoming.m_indexMap);
  incoming.m_valueChain.m_size = 0;
  if ( incoming.m_valueChain.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      incoming.m_valueChain.m_data,
      8 * incoming.m_valueChain.m_capacityAndFlags);
  incoming.m_valueChain.m_data = 0i64;
  incoming.m_valueChain.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v96);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v81.m_indexMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v81.m_indexMap);
LABEL_31:
  v81.m_valueChain.m_size = 0;
  if ( v81.m_valueChain.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v81.m_valueChain.m_data,
      8 * v81.m_valueChain.m_capacityAndFlags);
  v81.m_valueChain.m_data = 0i64;
  v81.m_valueChain.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v80.m_indexMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v80.m_indexMap);
  v80.m_valueChain.m_size = 0;
  if ( v80.m_valueChain.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v80.m_valueChain.m_data,
      8 * v80.m_valueChain.m_capacityAndFlags);
  v80.m_valueChain.m_data = 0i64;
  v80.m_valueChain.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v83,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v83);
  return v30;
}inerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v83);
  return v30;
}

// File Line: 554
// RVA: 0xE5CB00
void __fastcall HeapArray<UidItem>::insert(HeapArray<UidItem> *this, UidItem *e)
{
  __int64 v2; // r11
  int v3; // er10
  UidItem *v4; // rdi
  HeapArray<UidItem> *v5; // rbx
  __int64 v6; // r8
  int v7; // edx
  __m128i *v8; // rcx
  UidItem *v9; // rcx

  v2 = this->m_elems.m_size;
  v3 = 0;
  v4 = e;
  v5 = this;
  v6 = 0i64;
  if ( (signed int)v2 <= 0 )
  {
LABEL_5:
    if ( (_DWORD)v2 == (v5->m_elems.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 16);
    v9 = &v5->m_elems.m_data[v5->m_elems.m_size];
    if ( v9 )
    {
      v9->uid = v4->uid;
      *(_QWORD *)&v9->patchIndex = *(_QWORD *)&v4->patchIndex;
    }
    ++v5->m_elems.m_size;
  }
  else
  {
    v7 = e->patchIndex;
    v8 = (__m128i *)this->m_elems.m_data;
    while ( v7 >= _mm_cvtsi128_si32(_mm_srli_si128(*v8, 8)) )
    {
      ++v6;
      ++v3;
      ++v8;
      if ( v6 >= v2 )
        goto LABEL_5;
    }
    hkArrayBase<hkgpTriangulatorType<hkContainerHeapAllocator,hkgpTriangulatorBase::VertexBase,hkgpTriangulatorBase::TriangleBase,hkaiRuntimeTriangulatorEdgeData,hkgpTriangulatorBase::DenseEdgeDataPolicy<hkaiRuntimeTriangulatorEdgeData,hkContainerHeapAllocator>,-1,1,15,0>::Edge>::_insertAt(
      (hkArrayBase<UidItem> *)&v5->m_elems.m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v3,
      v4);
  }
}

// File Line: 606
// RVA: 0xE5C340
void __fastcall setAllDependeciesToDo(HeapArray<UidItem> *todo, const char *classname, int version, hkDataWorld *worldToUpdate, hkVersionPatchManager *man, hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *idxNewSrcFromUid, hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *patchesDone)
{
  HeapArray<UidItem> *v7; // rbp
  const char *v8; // rbx
  unsigned __int64 v9; // rdi
  __int64 v10; // rax
  int v11; // ebx
  unsigned __int64 v12; // rax
  __int64 v13; // r8
  __int64 v14; // rcx
  UidItem *v15; // rdx
  hkVersionPatchManager *v16; // r8
  hkVersionPatchManager::PatchInfo *v17; // rsi
  int v18; // eax
  __int64 v19; // rbx
  signed __int64 v20; // rdi
  hkVersionPatchManager::PatchInfo::Component *v21; // rax
  UidItem e; // [rsp+40h] [rbp-28h]
  int v23; // [rsp+80h] [rbp+18h]
  hkDataWorld *worldToUpdatea; // [rsp+88h] [rbp+20h]

  worldToUpdatea = worldToUpdate;
  v23 = version;
  v7 = todo;
  v8 = classname;
  v9 = hkVersionPatchManager::getUid(man, classname, version);
  v10 = ((__int64 (__fastcall *)(hkDataWorld *, const char *))worldToUpdatea->vfptr[4].__first_virtual_table_function__)(
          worldToUpdatea,
          v8);
  v11 = -1;
  if ( !v10 || (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v10 + 24i64))(v10) != v23 )
    v11 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&idxNewSrcFromUid->m_map.m_elem,
            v9,
            0xFFFFFFFFFFFFFFFFui64);
  v12 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&patchesDone->m_map.m_elem,
          v9,
          0i64);
  e.uid = v12;
  if ( v11 == -1 || (_DWORD)v12 == 1 )
  {
    v11 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&man->m_patchIndexFromUid.m_map.m_elem,
            v9,
            0xFFFFFFFFFFFFFFFFui64);
    LODWORD(v12) = e.uid;
  }
  e.uid = v9;
  e.patchIndex = v11;
  if ( (_DWORD)v12 != 2 )
  {
    v13 = v7->m_elems.m_size;
    v14 = 0i64;
    if ( v13 <= 0 )
    {
LABEL_12:
      HeapArray<UidItem>::insert(v7, &e);
    }
    else
    {
      v15 = v7->m_elems.m_data;
      while ( v9 != (unsigned __int64)*(_OWORD *)v15 )
      {
        ++v14;
        ++v15;
        if ( v14 >= v13 )
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
        v21 = v17->component;
        if ( v21[v20].type == 7 )
        {
          setAllDependeciesToDo(
            v7,
            *(const char **)v21[v20].patch,
            *((_DWORD *)v21[v20].patch + 2),
            worldToUpdatea,
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
hkResult *__fastcall hkVersionPatchManager::preparePatches(hkVersionPatchManager *this, hkResult *result, hkDataWorld *worldToUpdate, hkVersionPatchManager::ClassWrapper *wrapper, hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *patchInfosOut)
{
  hkBaseObjectVtbl *v5; // rax
  hkResult *v6; // r12
  hkVersionPatchManager *v7; // rdi
  __int64 v8; // r14
  hkVersionPatchManager::ClassWrapper *v9; // r13
  hkDataWorld *v10; // r15
  int v11; // eax
  int v12; // esi
  __int64 v13; // rbx
  __int64 v14; // r15
  int v15; // eax
  int v16; // ecx
  __int64 *v17; // rdx
  __int64 v18; // rax
  bool v19; // zf
  bool v20; // sf
  int v21; // esi
  hkVersionPatchManager::PatchInfo *v22; // rbx
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rbx
  int v25; // eax
  hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *v26; // r12
  int v27; // er8
  int v28; // esi
  __int64 v29; // rbx
  int v30; // eax
  UidItem *v31; // rcx
  int v32; // eax
  unsigned __int64 v33; // rsi
  __int64 v34; // rbx
  int v35; // eax
  UidItem *v36; // rdx
  __int64 v37; // r8
  unsigned __int64 v38; // rax
  unsigned __int64 v39; // r9
  signed __int64 v40; // rbx
  hkVersionPatchManager::PatchInfo *v41; // rsi
  hkVersionPatchManager::PatchInfo *v42; // rcx
  const char *v43; // rdx
  const char *v45; // r14
  int v46; // esi
  __int64 v47; // rax
  __int64 v48; // rbx
  int v49; // eax
  __int64 v50; // rbx
  hkVersionPatchManager::PatchInfo *v51; // r14
  const char *v52; // r13
  const char *v53; // r15
  int v54; // eax
  hkDataClassDict *v55; // rax
  int v56; // eax
  __int64 v57; // rdi
  signed __int64 v58; // rsi
  signed __int64 v59; // r8
  const char *v60; // rdx
  int v61; // ebx
  hkOstream *v62; // rax
  hkOstream *v63; // rax
  hkOstream *v64; // rax
  hkOstream *v65; // rax
  hkOstream *v66; // rax
  hkOstream *v67; // rax
  hkOstream *v68; // rax
  int v69; // er9
  int v70; // ecx
  int v71; // er8
  hkResult *v72; // rbx
  hkOstream *v73; // rax
  hkOstream *v74; // rax
  __int64 v75; // rbx
  hkTypeManager::Type *v76; // rax
  int v77; // esi
  __int64 v78; // rdi
  unsigned __int64 v79; // rbx
  unsigned __int64 v80; // rax
  int v81; // edi
  __int64 v82; // rsi
  __int64 *v83; // rbx
  unsigned __int64 v84; // rax
  __int64 v85; // rax
  unsigned __int64 v86; // rax
  Dummy *v87; // rdi
  hkDataWorld *v88; // rsi
  unsigned __int64 v89; // rax
  hkBaseObjectVtbl *v90; // rbx
  __int64 v91; // rax
  HeapArray<UidItem> todo; // [rsp+40h] [rbp-C0h]
  char *array; // [rsp+50h] [rbp-B0h]
  int v94; // [rsp+58h] [rbp-A8h]
  int v95; // [rsp+5Ch] [rbp-A4h]
  char *v96; // [rsp+60h] [rbp-A0h]
  int numElem; // [rsp+68h] [rbp-98h]
  int v98; // [rsp+6Ch] [rbp-94h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > idxNewSrcFromUid; // [rsp+70h] [rbp-90h]
  hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> patchesDone; // [rsp+80h] [rbp-80h]
  hkErrStream v101; // [rsp+90h] [rbp-70h]
  __int64 v102; // [rsp+A8h] [rbp-58h]
  hkDataClass::Cinfo cinfo; // [rsp+B0h] [rbp-50h]
  hkDataClass parent; // [rsp+D8h] [rbp-28h]
  hkDataWorldDict v105; // [rsp+E0h] [rbp-20h]
  char buf; // [rsp+200h] [rbp+100h]
  hkResult resulta; // [rsp+440h] [rbp+340h]
  hkResult *v108; // [rsp+448h] [rbp+348h]
  hkDataWorld *v109; // [rsp+450h] [rbp+350h]

  v109 = worldToUpdate;
  v108 = result;
  v5 = worldToUpdate->vfptr;
  v6 = result;
  v7 = this;
  v8 = 0i64;
  v9 = wrapper;
  v10 = worldToUpdate;
  v98 = 2147483648;
  v96 = 0i64;
  numElem = 0;
  v5[4].__vecDelDtor((hkBaseObject *)&worldToUpdate->vfptr, (unsigned int)&v96);
  v11 = numElem;
  array = 0i64;
  v94 = 0;
  v95 = 2147483648;
  if ( numElem > 0 )
  {
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, numElem, 16);
    v11 = numElem;
  }
  v12 = 0;
  if ( v11 > 0 )
  {
    do
    {
      v13 = *(_QWORD *)&v96[v8];
      if ( (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v13 + 24i64))(v13) < 0 )
      {
        hkErrStream::hkErrStream(&v101, &buf, 512);
        hkOstream::operator<<(
          (hkOstream *)&v101.vfptr,
          "Intermediate version found in a release build. The asset probably needs to be re-exported");
        if ( (unsigned int)hkError::messageError(1423160934, &buf, "Version\\hkVersionPatchManager.cpp", 758) )
          __debugbreak();
        hkOstream::~hkOstream((hkOstream *)&v101.vfptr);
      }
      else
      {
        v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 16i64))(v13);
        v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 24i64))(v13);
        v16 = v94;
        todo.m_elems.m_size = v15;
        v17 = (__int64 *)&array[16 * v94];
        if ( v17 )
        {
          v18 = *(_QWORD *)&todo.m_elems.m_size;
          *v17 = v14;
          v17[1] = v18;
          v16 = v94;
        }
        v94 = v16 + 1;
      }
      ++v12;
      v8 += 8i64;
    }
    while ( v12 < numElem );
    v10 = v109;
    v8 = 0i64;
  }
  hkDataWorldDict::hkDataWorldDict(&v105);
  v19 = v7->m_patchInfos.m_size == 0;
  v20 = v7->m_patchInfos.m_size < 0;
  idxNewSrcFromUid.m_elem = 0i64;
  idxNewSrcFromUid.m_numElems = 0;
  idxNewSrcFromUid.m_hashMod = -1;
  v21 = 0;
  if ( !v20 && !v19 )
  {
    do
    {
      v22 = *(hkVersionPatchManager::PatchInfo **)((char *)v7->m_patchInfos.m_data + v8);
      if ( !isValidPatch(v22) )
      {
LABEL_36:
        v6->m_enum = 1;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          &idxNewSrcFromUid,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
        _((AMD_HD3D *)&idxNewSrcFromUid);
        hkDataWorldDict::~hkDataWorldDict(&v105);
        v94 = 0;
        if ( v95 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            16 * v95);
        array = 0i64;
        v95 = 2147483648;
        numElem = 0;
        if ( v98 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v96,
            8 * v98);
        return v6;
      }
      if ( v22->oldVersion == -1 )
      {
        v23 = hkVersionPatchManager::UidFromClassVersion::get(v7->m_uidFromClassVersion, v22->newName, v22->newVersion);
        v24 = v23;
        v25 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &idxNewSrcFromUid,
                                  v23);
        if ( v25 <= idxNewSrcFromUid.m_hashMod )
          goto LABEL_36;
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &idxNewSrcFromUid,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v24,
          v21);
      }
      ++v21;
      v8 += 8i64;
    }
    while ( v21 < v7->m_patchInfos.m_size );
    LODWORD(v8) = 0;
  }
  v19 = v94 == 0;
  v20 = v94 < 0;
  v26 = patchInfosOut;
  v27 = 2147483648;
  patchesDone.m_map.m_elem = 0i64;
  patchesDone.m_map.m_numElems = 0;
  patchesDone.m_map.m_hashMod = -1;
  patchInfosOut->m_size = 0;
  todo.m_elems.m_data = 0i64;
  todo.m_elems.m_size = 0;
  todo.m_elems.m_capacityAndFlags = 2147483648;
  v28 = 0;
  if ( v20 || v19 )
  {
LABEL_47:
    todo.m_elems.m_size = v8;
    if ( v27 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        todo.m_elems.m_data,
        16 * v27);
    v49 = v26->m_size - 1;
    v50 = v49;
    v102 = v49;
    if ( v49 >= 0 )
    {
      do
      {
        v51 = v26->m_data[v50];
        v52 = v51->oldName;
        v53 = v51->oldName;
        if ( v51->newName )
          v53 = v51->newName;
        *(_QWORD *)&resulta.m_enum = hkDataWorldDict::findClass(&v105, v53);
        if ( !*(_QWORD *)&resulta.m_enum )
        {
          v54 = v51->oldVersion;
          cinfo.members.m_data = 0i64;
          cinfo.members.m_size = 0;
          cinfo.parent = 0i64;
          cinfo.members.m_capacityAndFlags = 2147483648;
          cinfo.name = v53;
          cinfo.version = v54;
          v55 = hkDataWorldDict::newClass(&v105, &cinfo);
          cinfo.members.m_size = 0;
          *(_QWORD *)&resulta.m_enum = v55;
          if ( cinfo.members.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              cinfo.members.m_data,
              24 * (cinfo.members.m_capacityAndFlags & 0x3FFFFFFF));
        }
        v56 = v51->numComponent - 1;
        v57 = v56;
        if ( v56 >= 0 )
        {
          v58 = v56;
          do
          {
            v59 = (signed __int64)&v51->component[v58];
            switch ( *(_DWORD *)v59 )
            {
              case 1:
                hkDataWorldDict::removeClassMember(&v105, (hkDataClass *)&resulta, **(const char ***)(v59 + 8));
                break;
              case 2:
                v75 = *(_QWORD *)(v59 + 8);
                v76 = hkTypeManager::getType(
                        &v105.m_typeManager,
                        (hkLegacyType::Type)*(_DWORD *)(v75 + 8),
                        *(const char **)(v75 + 16),
                        *(_DWORD *)(v75 + 24));
                hkDataWorldDict::addClassMember(&v105, (hkDataClass *)&resulta, *(const char **)v75, v76, 0i64);
                break;
              case 3:
                hkDataWorldDict::renameClassMember(
                  &v105,
                  (hkDataClass *)&resulta,
                  *(const char **)(*(_QWORD *)(v59 + 8) + 8i64),
                  **(const char ***)(v59 + 8));
                break;
              case 7:
                hkDataWorldDict::findClass(&v105, **(const char ***)(v59 + 8));
                break;
              case 8:
                v60 = **(const char ***)(v59 + 8);
                if ( v60 )
                {
                  parent.m_impl = hkDataWorldDict::findClass(&v105, v60);
                  hkDataWorldDict::setClassParent(&v105, (hkDataClass *)&resulta, &parent);
                }
                else
                {
                  todo.m_elems.m_data = 0i64;
                  hkDataWorldDict::setClassParent(&v105, (hkDataClass *)&resulta, (hkDataClass *)&todo);
                }
                break;
            }
            --v58;
            --v57;
          }
          while ( v57 >= 0 );
          v50 = v102;
        }
        if ( v51->oldVersion == -1 )
        {
          hkDataWorldDict::removeClass(&v105, (hkDataClass *)&resulta);
        }
        else
        {
          if ( v53 != v52 && (unsigned int)hkString::strCmp(v53, v52) )
            hkDataWorldDict::renameClass(&v105, (hkDataClass *)&resulta, v52);
          hkDataWorldDict::setClassVersion(&v105, (hkDataClass *)&resulta, v51->oldVersion);
        }
        v102 = --v50;
      }
      while ( v50 >= 0 );
      LODWORD(v8) = 0;
    }
    todo.m_elems.m_data = 0i64;
    todo.m_elems.m_size = 0;
    todo.m_elems.m_capacityAndFlags = 2147483648;
    hkDataWorldDict::findAllClasses(&v105, (hkArray<hkDataClassImpl *,hkContainerTempAllocator> *)&todo);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v101,
      0);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&cinfo,
      0);
    v77 = v8;
    if ( todo.m_elems.m_size > 0 )
    {
      v78 = 0i64;
      do
      {
        v79 = *(unsigned __int64 *)((char *)&todo.m_elems.m_data->uid + v78);
        v80 = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)v79 + 16i64))(v79);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
          (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v101,
          v80,
          v79);
        ++v77;
        v78 += 8i64;
      }
      while ( v77 < todo.m_elems.m_size );
    }
    v81 = v8;
    if ( numElem > 0 )
    {
      v82 = 0i64;
      do
      {
        v83 = *(__int64 **)&v96[v82];
        v84 = (*(__int64 (__fastcall **)(__int64 *))(*v83 + 16))(v83);
        v19 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v101,
                v84,
                0i64) == 0;
        v85 = *v83;
        if ( v19 )
        {
          (*(void (__fastcall **)(__int64 *))(v85 + 24))(v83);
        }
        else
        {
          v86 = (*(__int64 (__fastcall **)(__int64 *))(v85 + 16))(v83);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
            (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v101,
            &resulta,
            v86);
        }
        ++v81;
        v82 += 8i64;
      }
      while ( v81 < numElem );
    }
    v87 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v101);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v101,
      (hkBool *)&resulta,
      v87);
    if ( LOBYTE(resulta.m_enum) )
    {
      v88 = v109;
      do
      {
        v89 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v101,
                v87);
        v90 = v88->vfptr;
        v91 = (*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)v89 + 16i64))(v89);
        ((void (__fastcall *)(hkDataWorld *, __int64, hkDataWorldDict *))v90[11].__first_virtual_table_function__)(
          v88,
          v91,
          &v105);
        v87 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v101,
                v87);
        hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v101,
          (hkBool *)&resulta,
          v87);
      }
      while ( LOBYTE(resulta.m_enum) );
    }
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>((hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&cinfo);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>((hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v101);
    todo.m_elems.m_size = v8;
    if ( todo.m_elems.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        todo.m_elems.m_data,
        8 * todo.m_elems.m_capacityAndFlags);
    v72 = v108;
    v108->m_enum = 0;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&patchesDone.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&patchesDone);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &idxNewSrcFromUid,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&idxNewSrcFromUid);
    hkDataWorldDict::~hkDataWorldDict(&v105);
    v94 = v8;
    if ( v95 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v95);
    array = 0i64;
    numElem = 0;
    goto LABEL_103;
  }
  v29 = 0i64;
  do
  {
    setAllDependeciesToDo(
      &todo,
      *(const char **)&array[v29],
      *(_DWORD *)&array[v29 + 8],
      v10,
      v7,
      (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&idxNewSrcFromUid,
      &patchesDone);
    ++v28;
    v29 += 16i64;
  }
  while ( v28 < v94 );
  v30 = todo.m_elems.m_size;
  if ( !todo.m_elems.m_size )
  {
LABEL_46:
    v27 = todo.m_elems.m_capacityAndFlags;
    goto LABEL_47;
  }
  while ( 1 )
  {
    v31 = todo.m_elems.m_data;
    v32 = v30 - 1;
    v33 = todo.m_elems.m_data->uid;
    v34 = *(_QWORD *)&todo.m_elems.m_data->patchIndex;
    todo.m_elems.m_size = v32;
    v35 = 16 * v32;
    v36 = todo.m_elems.m_data + 1;
    if ( v35 > 0 )
    {
      v37 = ((unsigned int)(v35 - 1) >> 3) + 1;
      do
      {
        v38 = v36->uid;
        v31 = (UidItem *)((char *)v31 + 8);
        v36 = (UidItem *)((char *)v36 + 8);
        *(_QWORD *)&v31[-1].patchIndex = v38;
        --v37;
      }
      while ( v37 );
    }
    if ( (_DWORD)v34 == -1 || (v39 = 1i64, v7->m_patchInfos.m_data[(signed int)v34]->oldVersion != -1) )
      v39 = 2i64;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&patchesDone.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v33,
      v39);
    if ( (signed int)v34 >= 0 )
    {
      v40 = (signed int)v34;
      v41 = v7->m_patchInfos.m_data[v40];
      if ( v26->m_size == (v26->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v26, 8);
      v26->m_data[v26->m_size++] = v41;
      v42 = v7->m_patchInfos.m_data[v40];
      v43 = v42->newName;
      if ( !v43 )
        v43 = v42->oldName;
      setAllDependeciesToDo(
        &todo,
        v43,
        v42->newVersion,
        v10,
        v7,
        (hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> *)&idxNewSrcFromUid,
        &patchesDone);
      goto LABEL_44;
    }
    v45 = hkVersionPatchManager::getClassName(v7, v33);
    v46 = hkVersionPatchManager::getClassVersion(v7, v33);
    if ( v46 != -1 )
      break;
LABEL_44:
    v30 = todo.m_elems.m_size;
    if ( !todo.m_elems.m_size )
    {
      LODWORD(v8) = 0;
      goto LABEL_46;
    }
  }
  v47 = ((__int64 (__fastcall *)(hkVersionPatchManager::ClassWrapper *, hkDataWorldDict *, const char *))v9->vfptr[1].__first_virtual_table_function__)(
          v9,
          &v105,
          v45);
  v48 = v47;
  if ( v47 )
  {
    if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v47 + 24i64))(v47) != v46 )
    {
      hkErrStream::hkErrStream(&v101, &buf, 512);
      v61 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v48 + 24i64))(v48);
      v62 = hkOstream::operator<<((hkOstream *)&v101.vfptr, "Source contains ");
      v63 = hkOstream::operator<<(v62, v45);
      v64 = hkOstream::operator<<(v63, " version ");
      v65 = hkOstream::operator<<(v64, v46, (int)v64);
      v66 = hkOstream::operator<<(v65, ", but  ");
      v67 = hkOstream::operator<<(v66, v61, (int)v66);
      v68 = hkOstream::operator<<(v67, " is the current version.\n");
      hkOstream::operator<<(v68, "Make sure required patches are registered to update this class.");
      v69 = 849;
      v70 = 1064951217;
      goto LABEL_65;
    }
    goto LABEL_44;
  }
  hkErrStream::hkErrStream(&v101, &buf, 512);
  v73 = hkOstream::operator<<((hkOstream *)&v101.vfptr, "Class ");
  v74 = hkOstream::operator<<(v73, v45);
  hkOstream::operator<<(
    v74,
    " is not registered. If this is a Havok class, make sure the class's product reflection is enabled near where hkProdu"
    "ctFeatures.cxx is included. Otherwise, check your own class registration.");
  v69 = 842;
  v70 = 1064951216;
LABEL_65:
  hkError::messageWarning(v70, &buf, "Version\\hkVersionPatchManager.cpp", v69);
  hkOstream::~hkOstream((hkOstream *)&v101.vfptr);
  v71 = todo.m_elems.m_capacityAndFlags;
  v72 = v108;
  v108->m_enum = 1;
  todo.m_elems.m_size = 0;
  if ( v71 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      todo.m_elems.m_data,
      16 * v71);
  todo.m_elems.m_data = 0i64;
  todo.m_elems.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&patchesDone.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&patchesDone);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &idxNewSrcFromUid,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&idxNewSrcFromUid);
  hkDataWorldDict::~hkDataWorldDict(&v105);
  v94 = 0;
  if ( v95 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v95);
  array = 0i64;
  numElem = 0;
LABEL_103:
  v95 = 2147483648;
  if ( v98 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v96,
      8 * v98);
  return v72;
}

// File Line: 1025
// RVA: 0xE59FB0
hkResult *__fastcall hkVersionPatchManager::applyPatches(hkVersionPatchManager *this, hkResult *result, hkDataWorld *worldToUpdate, hkVersionPatchManager::ClassWrapper *classWrapper)
{
  hkVersionPatchManager *v4; // rdi
  hkResult *v5; // rsi
  hkVersionPatchManager::ClassWrapper *v6; // rbx
  hkDataWorld *v7; // rbp
  hkDefaultClassWrapper *v8; // r9
  hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> patchInfos; // [rsp+30h] [rbp-38h]
  hkDefaultClassWrapper v11; // [rsp+40h] [rbp-28h]
  hkResult resulta; // [rsp+78h] [rbp+10h]

  v4 = this;
  v5 = result;
  v6 = classWrapper;
  v7 = worldToUpdate;
  hkDefaultClassWrapper::hkDefaultClassWrapper(&v11, 0i64);
  v8 = &v11;
  if ( v6 )
    v8 = (hkDefaultClassWrapper *)v6;
  patchInfos.m_capacityAndFlags = 2147483648;
  patchInfos.m_data = 0i64;
  patchInfos.m_size = 0;
  hkVersionPatchManager::preparePatches(v4, v5, v7, (hkVersionPatchManager::ClassWrapper *)&v8->vfptr, &patchInfos);
  if ( v5->m_enum == HK_SUCCESS )
    v5->m_enum = applyPatchesFinally(&resulta, v7, &patchInfos)->m_enum;
  patchInfos.m_size = 0;
  if ( patchInfos.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      patchInfos.m_data,
      8 * patchInfos.m_capacityAndFlags);
  patchInfos.m_data = 0i64;
  patchInfos.m_capacityAndFlags = 2147483648;
  if ( v11.m_nameReg.m_pntr )
    hkReferencedObject::removeReference((hkReferencedObject *)&v11.m_nameReg.m_pntr->vfptr);
  return v5;
}

// File Line: 1046
// RVA: 0xE5AE80
hkResult *__fastcall hkVersionPatchManager::applyPatchesDebug(hkVersionPatchManager *this, hkResult *result, hkDataWorld *worldToUpdate)
{
  hkResult *v3; // rbx

  v3 = result;
  applyPatchesFinally(result, worldToUpdate, &this->m_patchInfos);
  return v3;
}

// File Line: 1053
// RVA: 0xE5C4D0
hkResult *__fastcall applyPatchesFinally(hkResult *result, hkDataWorld *worldToUpdate, hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *patchInfos)
{
  int v3; // edi
  hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *v4; // r13
  hkDataWorld *v5; // rsi
  hkResult *v6; // r12
  int v7; // er12
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
  hkTypeManager::Type *v18; // rax
  void (__fastcall *v19)(__int64 *); // r14
  hkBaseObjectVtbl *v20; // rax
  __int64 v21; // rbx
  __int64 v22; // rcx
  __int64 v23; // rcx
  bool v24; // zf
  __int64 v25; // rax
  hkBaseObjectVtbl *v26; // rax
  __int64 v27; // rbx
  __int64 v28; // rcx
  __int64 v29; // rcx
  int v30; // er8
  int v31; // eax
  int v32; // eax
  __int64 v34; // [rsp+30h] [rbp-59h]
  char *v35; // [rsp+38h] [rbp-51h]
  int v36; // [rsp+40h] [rbp-49h]
  int v37; // [rsp+44h] [rbp-45h]
  char *v38; // [rsp+48h] [rbp-41h]
  int v39; // [rsp+50h] [rbp-39h]
  int v40; // [rsp+54h] [rbp-35h]
  const char *v41; // [rsp+58h] [rbp-31h]
  __int64 v42; // [rsp+60h] [rbp-29h]
  __int64 v43; // [rsp+68h] [rbp-21h]
  __int64 v44; // [rsp+70h] [rbp-19h]
  const char *v45; // [rsp+78h] [rbp-11h]
  int v46; // [rsp+80h] [rbp-9h]
  __int64 v47; // [rsp+88h] [rbp-1h]
  void *v48; // [rsp+90h] [rbp+7h]
  int v49; // [rsp+98h] [rbp+Fh]
  int v50; // [rsp+9Ch] [rbp+13h]
  __int64 v51; // [rsp+A0h] [rbp+17h]
  __int64 v52; // [rsp+A8h] [rbp+1Fh]
  hkResult *v53; // [rsp+F0h] [rbp+67h]
  hkArray<hkVersionPatchManager::PatchInfo const *,hkContainerHeapAllocator> *v54; // [rsp+100h] [rbp+77h]
  int v55; // [rsp+108h] [rbp+7Fh]

  v54 = patchInfos;
  v53 = result;
  v3 = 0;
  v4 = patchInfos;
  v5 = worldToUpdate;
  v6 = result;
  v55 = 0;
  if ( patchInfos->m_size <= 0 )
  {
LABEL_58:
    v6->m_enum = 0;
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
      v41 = *(const char **)(v9 + 8);
    }
    if ( *(_DWORD *)(v9 + 16) == -1 )
      break;
LABEL_9:
    v34 = ((__int64 (__fastcall *)(hkDataWorld *, const char *))v5->vfptr[4].__first_virtual_table_function__)(v5, v10);
    if ( *(_QWORD *)v9 )
    {
      v12 = *(const char **)(v9 + 8);
      if ( v12 )
      {
        if ( (unsigned int)hkString::strCmp(*(const char **)v9, v12) )
        {
          ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD))v5->vfptr[6].__vecDelDtor)(
            v5,
            &v34,
            *(_QWORD *)(v9 + 8));
          v10 = *(const char **)(v9 + 8);
          v41 = *(const char **)(v9 + 8);
        }
      }
    }
    if ( *(_DWORD *)(v9 + 32) > 0 )
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
            v17 = (hkTypeManager *)((__int64 (__fastcall *)(hkDataWorld *))v5->vfptr[5].__first_virtual_table_function__)(v5);
            v18 = hkTypeManager::getType(
                    v17,
                    (hkLegacyType::Type)*(_DWORD *)(v16 + 8),
                    *(const char **)(v16 + 16),
                    *(_DWORD *)(v16 + 24));
            ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD, hkTypeManager::Type *, _QWORD))v5->vfptr[8].__vecDelDtor)(
              v5,
              &v34,
              *(_QWORD *)v16,
              v18,
              *(_QWORD *)(v16 + 32));
            break;
          case 2:
            ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD))v5->vfptr[9].__first_virtual_table_function__)(
              v5,
              &v34,
              **(_QWORD **)(v15 + 8));
            break;
          case 3:
            ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD, _QWORD))v5->vfptr[9].__vecDelDtor)(
              v5,
              &v34,
              **(_QWORD **)(v15 + 8),
              *(_QWORD *)(*(_QWORD *)(v15 + 8) + 8i64));
            break;
          case 4:
            ((void (__fastcall *)(hkDataWorld *, __int64 *, _QWORD, _QWORD))v5->vfptr[8].__first_virtual_table_function__)(
              v5,
              &v34,
              **(_QWORD **)(v15 + 8),
              *(_QWORD *)(*(_QWORD *)(v15 + 8) + 8i64));
            break;
          case 5:
            v19 = *(void (__fastcall **)(__int64 *))(*(_QWORD *)(v15 + 8) + 8i64);
            v20 = v5->vfptr;
            v38 = 0i64;
            v39 = 0;
            v40 = 2147483648;
            ((void (__fastcall *)(hkDataWorld *, const char *, char **))v20[10].__vecDelDtor)(v5, v10, &v38);
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
                    (**(void (__fastcall ***)(__int64, signed __int64))v23)(v23, 1i64);
                }
                ++v13;
                v21 += 8i64;
              }
              while ( v13 < v39 );
            }
            v13 = 0;
            v39 = 0;
            if ( v40 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                v38,
                8 * v40);
            v38 = 0i64;
            v40 = 2147483648;
            break;
          case 6:
            v52 = ((__int64 (__fastcall *)(hkDataWorld *, _QWORD))v5->vfptr[4].__first_virtual_table_function__)(
                    v5,
                    **(_QWORD **)(v15 + 8));
            v26 = v5->vfptr;
            v35 = 0i64;
            v36 = 0;
            v37 = 2147483648;
            ((void (__fastcall *)(hkDataWorld *, const char *, char **))v26[10].__first_virtual_table_function__)(
              v5,
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
                ((void (__fastcall *)(hkDataWorld *, __int64 *, __int64 *))v5->vfptr[11].__vecDelDtor)(v5, &v43, &v52);
                v29 = v43;
                if ( v43 )
                {
                  --*(_WORD *)(v43 + 10);
                  v24 = (*(_DWORD *)(v29 + 12))-- == 1;
                  if ( v24 )
                    (**(void (__fastcall ***)(__int64, signed __int64))v29)(v29, 1i64);
                }
                ++v13;
                v27 += 8i64;
              }
              while ( v13 < v36 );
            }
            v13 = 0;
            v36 = 0;
            if ( v37 >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                v35,
                8 * v37);
            v35 = 0i64;
            v37 = 2147483648;
            break;
          case 8:
            if ( *(_QWORD *)(*(_QWORD *)(v15 + 8) + 8i64) )
              v25 = ((__int64 (__fastcall *)(hkDataWorld *))v5->vfptr[4].__first_virtual_table_function__)(v5);
            else
              v25 = 0i64;
            v51 = v25;
            ((void (__fastcall *)(hkDataWorld *, __int64 *, __int64 *))v5->vfptr[7].__first_virtual_table_function__)(
              v5,
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
      v4 = v54;
    }
    v30 = *(_DWORD *)(v9 + 20);
    if ( v30 == -1 )
    {
      ((void (__fastcall *)(hkDataWorld *, __int64 *))v5->vfptr[6].__first_virtual_table_function__)(v5, &v34);
    }
    else
    {
      v31 = *(_DWORD *)(v9 + 16);
      if ( v31 != -1 && v31 != v30 )
        v5->vfptr[7].__vecDelDtor((hkBaseObject *)&v5->vfptr, (unsigned int)&v34);
    }
    ++v3;
    v8 += 8i64;
    v55 = v3;
    v42 = v8;
    if ( v3 >= v4->m_size )
    {
      v6 = v53;
      goto LABEL_58;
    }
    v7 = 0;
  }
  v46 = *(_DWORD *)(v9 + 20);
  v11 = v5->vfptr;
  v48 = 0i64;
  v49 = 0;
  v50 = 2147483648;
  v45 = v10;
  v47 = 0i64;
  if ( !((__int64 (__fastcall *)(hkDataWorld *, const char *))v11[4].__first_virtual_table_function__)(v5, v10) )
  {
    ((void (__fastcall *)(hkDataWorld *, const char **))v5->vfptr[1].__first_virtual_table_function__)(v5, &v45);
    v49 = 0;
    if ( v50 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v48,
        24 * (v50 & 0x3FFFFFFF));
    goto LABEL_9;
  }
  v6 = v53;
  v32 = v50;
  v49 = 0;
  v53->m_enum = 1;
  if ( v32 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v48,
      24 * (v32 & 0x3FFFFFFF));
  return v6;
}

// File Line: 1213
// RVA: 0xE5A0A0
void __fastcall hkVersionPatchManager::addPatch(hkVersionPatchManager *this, hkVersionPatchManager::PatchInfo *p)
{
  hkVersionPatchManager *v2; // rdi
  hkVersionPatchManager::PatchInfo *v3; // rsi

  v2 = this;
  v3 = p;
  if ( isValidPatch(p) )
  {
    if ( v2->m_patchInfos.m_size == (v2->m_patchInfos.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_patchInfos, 8);
    v2->m_patchInfos.m_data[v2->m_patchInfos.m_size++] = v3;
    hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_patchIndexFromUid.m_map.m_elem);
  }
}

