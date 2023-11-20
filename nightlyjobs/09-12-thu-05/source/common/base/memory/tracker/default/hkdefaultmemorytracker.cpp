// File Line: 16
// RVA: 0x15DF3C0
void dynamic_initializer_for__hkDefaultMemoryTrackerClass__()
{
  hkClass::hkClass(
    &hkDefaultMemoryTrackerClass,
    "hkDefaultMemoryTracker",
    &hkReferencedObjectClass,
    248,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 44
// RVA: 0x1306500
hkBool *__fastcall hkDefaultMemoryTracker::ClassAlloc::operator==(hkDefaultMemoryTracker::ClassAlloc *this, hkBool *result, hkDefaultMemoryTracker::ClassAlloc *rhs)
{
  hkBool *v3; // rbx
  const char *v4; // rdx
  hkDefaultMemoryTracker::ClassAlloc *v5; // rsi
  const char *v6; // rcx
  hkDefaultMemoryTracker::ClassAlloc *v7; // rdi
  hkBool *v8; // rax
  bool v9; // al

  v3 = result;
  v4 = rhs->m_typeName;
  v5 = this;
  v6 = this->m_typeName;
  v7 = rhs;
  if ( v6 == rhs->m_typeName || v6 && v4 && !(unsigned int)hkString::strCmp(v6, v4) )
  {
    v9 = v5->m_size == v7->m_size && v5->m_ptr == v7->m_ptr && v5->m_flags == v7->m_flags;
    v3->m_bool = v9;
    v8 = v3;
  }
  else
  {
    v3->m_bool = 0;
    v8 = v3;
  }
  return v8;
}

// File Line: 66
// RVA: 0x1306910
void __fastcall hkDefaultMemoryTracker::hkDefaultMemoryTracker(hkDefaultMemoryTracker *this, hkMemoryAllocator *allocator)
{
  hkDefaultMemoryTracker *v2; // rdi
  hkMemoryTracker::TypeDefinition *v3; // rbx
  signed __int64 v4; // rsi

  v2 = this;
  this->vfptr = (hkMemoryTrackerVtbl *)&hkDefaultMemoryTracker::`vftable';
  this->m_deletedMap.m_map.m_elem = 0i64;
  this->m_deletedMap.m_map.m_numElems = 0;
  this->m_deletedMap.m_map.m_hashMod = -1;
  this->m_createdMap.m_map.m_elem = 0i64;
  this->m_createdMap.m_map.m_numElems = 0;
  this->m_createdMap.m_map.m_hashMod = -1;
  hkFreeList::hkFreeList(&this->m_classAllocFreeList, 0x20ui64, 8ui64, 0x1000ui64, allocator, 0i64);
  v2->m_classAllocMap.m_map.m_elem = 0i64;
  v2->m_classAllocMap.m_map.m_numElems = 0;
  v2->m_classAllocMap.m_map.m_hashMod = -1;
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>(
    &v2->m_nameTypeMap.m_map,
    0);
  hkCriticalSection::hkCriticalSection(&v2->m_criticalSection, 0);
  v3 = s_defaultTypes;
  v4 = 27i64;
  do
  {
    hkDefaultMemoryTracker::addTypeDefinition(v2, v3);
    ++v3;
    --v4;
  }
  while ( v4 );
  v2->m_assertOnRemove = 0i64;
  v2->m_trackingEnabled.m_bool = 0;
}

// File Line: 102
// RVA: 0x13069F0
hkDefaultMemoryTracker::ClassAlloc *__fastcall hkDefaultMemoryTracker::_addClassAlloc(hkDefaultMemoryTracker *this, const char *typeName, unsigned __int64 size, void *ptr, int flags)
{
  void *v5; // rsi
  unsigned __int64 v6; // r14
  const char *v7; // r15
  hkDefaultMemoryTracker *v8; // rdi
  char *v10; // rbx
  unsigned __int64 v11; // rcx

  v5 = ptr;
  v6 = size;
  v7 = typeName;
  v8 = this;
  if ( !ptr )
    return 0i64;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v10 = (char *)v8->m_classAllocFreeList.m_free;
  if ( v10 )
  {
    --v8->m_classAllocFreeList.m_numFreeElements;
    v8->m_classAllocFreeList.m_free = *(hkFreeList::Element **)v10;
  }
  else
  {
    v10 = v8->m_classAllocFreeList.m_top;
    if ( v10 < v8->m_classAllocFreeList.m_blockEnd )
    {
      v11 = v8->m_classAllocFreeList.m_elementSize;
      --v8->m_classAllocFreeList.m_numFreeElements;
      v8->m_classAllocFreeList.m_top = &v10[v11];
    }
    else
    {
      v10 = hkFreeList::addSpace(&v8->m_classAllocFreeList);
    }
  }
  *(_QWORD *)v10 = v7;
  *((_QWORD *)v10 + 1) = v6;
  *((_QWORD *)v10 + 2) = v5;
  *((_DWORD *)v10 + 6) = flags;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_classAllocMap.m_map.m_elem,
    hkDefaultMemoryTrackerAllocator::s_allocator,
    (unsigned __int64)v5,
    (unsigned __int64)v10);
  if ( v8->m_trackingEnabled.m_bool )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_createdMap.m_map.m_elem,
      hkDefaultMemoryTrackerAllocator::s_allocator,
      (unsigned __int64)v5,
      (unsigned __int64)v10);
  LeaveCriticalSection(&v8->m_criticalSection.m_section);
  return (hkDefaultMemoryTracker::ClassAlloc *)v10;
}

// File Line: 153
// RVA: 0x1306AF0
void __fastcall hkDefaultMemoryTracker::_removeClassAlloc(hkDefaultMemoryTracker *this, void *ptr)
{
  hkDefaultMemoryTracker *v2; // rdi
  void *v3; // rsi
  Dummy *v4; // rax
  hkFreeList::Element *v5; // rbx
  hkFreeList::Element *v6; // rdx
  Dummy *v7; // rax

  if ( ptr )
  {
    v2 = this;
    v3 = ptr;
    EnterCriticalSection(&this->m_criticalSection.m_section);
    v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_classAllocMap.m_map.m_elem,
           (unsigned __int64)v3);
    if ( (signed int)v4 <= v2->m_classAllocMap.m_map.m_hashMod )
    {
      v5 = (hkFreeList::Element *)v2->m_classAllocMap.m_map.m_elem[(signed int)v4].val;
      v6 = v2->m_classAllocFreeList.m_free;
      ++v2->m_classAllocFreeList.m_numFreeElements;
      v5->m_next = v6;
      v2->m_classAllocFreeList.m_free = v5;
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_classAllocMap.m_map.m_elem,
        v4);
      if ( v5 == (hkFreeList::Element *)v2->m_assertOnRemove )
        v2->m_assertOnRemove = 0i64;
    }
    if ( v2->m_trackingEnabled.m_bool )
    {
      v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_createdMap.m_map.m_elem,
             (unsigned __int64)v3);
      if ( (signed int)v7 > v2->m_createdMap.m_map.m_hashMod )
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_deletedMap.m_map.m_elem,
          hkDefaultMemoryTrackerAllocator::s_allocator,
          (unsigned __int64)v3,
          1ui64);
      else
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_createdMap.m_map.m_elem,
          v7);
    }
    LeaveCriticalSection(&v2->m_criticalSection.m_section);
  }
}

// File Line: 209
// RVA: 0x13068E0
void __fastcall hkDefaultMemoryTracker::clearTrackingHistory(hkDefaultMemoryTracker *this)
{
  hkDefaultMemoryTracker *v1; // rbx

  v1 = this;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_deletedMap.m_map.m_elem);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_createdMap.m_map.m_elem);
}

// File Line: 215
// RVA: 0x1306830
hkDefaultMemoryTracker::ClassAlloc *__fastcall hkDefaultMemoryTracker::findClassAlloc(hkDefaultMemoryTracker *this, void *ptr)
{
  _RTL_CRITICAL_SECTION *v2; // rsi
  hkDefaultMemoryTracker *v3; // rbx
  void *v4; // rdi
  unsigned __int64 v5; // rbx

  v2 = &this->m_criticalSection.m_section;
  v3 = this;
  v4 = ptr;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v5 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_classAllocMap.m_map.m_elem,
         (unsigned __int64)v4,
         0i64);
  LeaveCriticalSection(v2);
  return (hkDefaultMemoryTracker::ClassAlloc *)v5;
}

// File Line: 225
// RVA: 0x1306890
void __fastcall hkDefaultMemoryTracker::setAssertRemoveAlloc(hkDefaultMemoryTracker *this, hkDefaultMemoryTracker::ClassAlloc *alloc)
{
  hkDefaultMemoryTracker *v2; // rdi
  hkDefaultMemoryTracker::ClassAlloc *v3; // rsi

  v2 = this;
  v3 = alloc;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v2->m_assertOnRemove = v3;
  LeaveCriticalSection(&v2->m_criticalSection.m_section);
}

// File Line: 239
// RVA: 0x1306590
void __fastcall hkDefaultMemoryTracker::onNewReferencedObject(hkDefaultMemoryTracker *this, const char *typeName, unsigned __int64 size, void *ptr)
{
  hkDefaultMemoryTracker::_addClassAlloc(this, typeName, size, ptr, 1);
}

// File Line: 244
// RVA: 0x13065B0
void __fastcall hkDefaultMemoryTracker::onDeleteReferencedObject(hkDefaultMemoryTracker *this, void *ptr)
{
  hkDefaultMemoryTracker::_removeClassAlloc(this, ptr);
}

// File Line: 250
// RVA: 0x13065C0
void __fastcall hkDefaultMemoryTracker::onNewObject(hkDefaultMemoryTracker *this, const char *typeName, unsigned __int64 size, void *ptr)
{
  hkDefaultMemoryTracker::_addClassAlloc(this, typeName, size, ptr, 0);
}

// File Line: 255
// RVA: 0x13065E0
void __fastcall hkDefaultMemoryTracker::onDeleteObject(hkDefaultMemoryTracker *this, void *ptr)
{
  hkDefaultMemoryTracker::_removeClassAlloc(this, ptr);
}

// File Line: 260
// RVA: 0x13065F0
void __fastcall hkDefaultMemoryTracker::onNewRaw(hkDefaultMemoryTracker *this, const char *name, unsigned __int64 size, void *ptr)
{
  hkDefaultMemoryTracker::_addClassAlloc(this, name, size, ptr, 0);
}

// File Line: 265
// RVA: 0x1306610
void __fastcall hkDefaultMemoryTracker::onDeleteRaw(hkDefaultMemoryTracker *this, void *ptr)
{
  hkDefaultMemoryTracker::_removeClassAlloc(this, ptr);
}

// File Line: 270
// RVA: 0x1306620
void __fastcall hkDefaultMemoryTracker::addTypeDefinition(hkDefaultMemoryTracker *this, hkMemoryTracker::TypeDefinition *defIn)
{
  hkDefaultMemoryTracker *v2; // rsi
  unsigned __int64 *v3; // rdi

  v2 = this;
  v3 = (unsigned __int64 *)defIn;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  if ( !(__int64)v2->vfptr->findTypeDefinition((hkMemoryTracker *)&v2->vfptr, (const char *)*v3) )
    hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::insert(
      &v2->m_nameTypeMap.m_map,
      *v3,
      (unsigned __int64)v3);
  LeaveCriticalSection(&v2->m_criticalSection.m_section);
}

// File Line: 283
// RVA: 0x1306690
void __fastcall hkDefaultMemoryTracker::clearTypeDefinitions(hkDefaultMemoryTracker *this)
{
  hkDefaultMemoryTracker *v1; // rbx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> other; // [rsp+20h] [rbp-28h]

  v1 = this;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>(
    &other,
    0);
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::swap(&v1->m_nameTypeMap.m_map, &other);
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::~hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>(&other);
  LeaveCriticalSection(&v1->m_criticalSection.m_section);
}

// File Line: 289
// RVA: 0x1306700
hkMemoryTracker::TypeDefinition *__fastcall hkDefaultMemoryTracker::findTypeDefinition(hkDefaultMemoryTracker *this, const char *typeName)
{
  _RTL_CRITICAL_SECTION *v2; // rsi
  hkDefaultMemoryTracker *v3; // rbx
  const char *v4; // rdi
  unsigned __int64 v5; // rbx

  v2 = &this->m_criticalSection.m_section;
  v3 = this;
  v4 = typeName;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v5 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
         &v3->m_nameTypeMap.m_map,
         (unsigned __int64)v4,
         0i64);
  LeaveCriticalSection(v2);
  return (hkMemoryTracker::TypeDefinition *)v5;
}

// File Line: 295
// RVA: 0x1306760
unsigned __int64 __fastcall hkDefaultMemoryTracker::getTypeDefinitions(hkDefaultMemoryTracker *this, hkMemoryTracker::TypeDefinition **typeDefinitions)
{
  hkMemoryTracker::TypeDefinition **v2; // rdi
  hkDefaultMemoryTracker *v3; // rbp
  Dummy *v4; // rsi
  hkBool result; // [rsp+30h] [rbp+8h]

  v2 = typeDefinitions;
  v3 = this;
  if ( !typeDefinitions )
    return this->m_nameTypeMap.m_map.m_numElems;
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(&this->m_nameTypeMap.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(&v3->m_nameTypeMap.m_map, &result, v4);
  while ( result.m_bool )
  {
    *v2 = (hkMemoryTracker::TypeDefinition *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                               &v3->m_nameTypeMap.m_map,
                                               v4);
    ++v2;
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(&v3->m_nameTypeMap.m_map, v4);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(&v3->m_nameTypeMap.m_map, &result, v4);
  }
  return v3->m_nameTypeMap.m_map.m_numElems;
}

