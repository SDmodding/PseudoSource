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
hkBool *__fastcall hkDefaultMemoryTracker::ClassAlloc::operator==(
        hkDefaultMemoryTracker::ClassAlloc *this,
        hkBool *result,
        hkDefaultMemoryTracker::ClassAlloc *rhs)
{
  const char *m_typeName; // rdx
  const char *v6; // rcx
  bool v9; // al

  m_typeName = rhs->m_typeName;
  v6 = this->m_typeName;
  if ( v6 == rhs->m_typeName || v6 && m_typeName && !(unsigned int)hkString::strCmp(v6, m_typeName) )
  {
    v9 = this->m_size == rhs->m_size && this->m_ptr == rhs->m_ptr && this->m_flags == rhs->m_flags;
    result->m_bool = v9;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 66
// RVA: 0x1306910
void __fastcall hkDefaultMemoryTracker::hkDefaultMemoryTracker(
        hkDefaultMemoryTracker *this,
        hkMemoryAllocator *allocator)
{
  hkMemoryTracker::TypeDefinition *v3; // rbx
  __int64 v4; // rsi

  this->vfptr = (hkMemoryTrackerVtbl *)&hkDefaultMemoryTracker::`vftable;
  this->m_deletedMap.m_map.m_elem = 0i64;
  this->m_deletedMap.m_map.m_numElems = 0;
  this->m_deletedMap.m_map.m_hashMod = -1;
  this->m_createdMap.m_map.m_elem = 0i64;
  this->m_createdMap.m_map.m_numElems = 0;
  this->m_createdMap.m_map.m_hashMod = -1;
  hkFreeList::hkFreeList(&this->m_classAllocFreeList, 0x20ui64, 8ui64, 0x1000ui64, allocator, 0i64);
  this->m_classAllocMap.m_map.m_elem = 0i64;
  this->m_classAllocMap.m_map.m_numElems = 0;
  this->m_classAllocMap.m_map.m_hashMod = -1;
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>(
    &this->m_nameTypeMap.m_map,
    0);
  hkCriticalSection::hkCriticalSection(&this->m_criticalSection, 0);
  v3 = s_defaultTypes;
  v4 = 27i64;
  do
  {
    hkDefaultMemoryTracker::addTypeDefinition(this, v3++);
    --v4;
  }
  while ( v4 );
  this->m_assertOnRemove = 0i64;
  this->m_trackingEnabled.m_bool = 0;
}

// File Line: 102
// RVA: 0x13069F0
hkFreeList::Element **__fastcall hkDefaultMemoryTracker::_addClassAlloc(
        hkDefaultMemoryTracker *this,
        hkFreeList::Element *typeName,
        hkFreeList::Element *size,
        unsigned __int64 ptr,
        int flags)
{
  hkFreeList::Element **p_m_next; // rbx
  unsigned __int64 m_elementSize; // rcx

  if ( !ptr )
    return 0i64;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  p_m_next = &this->m_classAllocFreeList.m_free->m_next;
  if ( p_m_next )
  {
    --this->m_classAllocFreeList.m_numFreeElements;
    this->m_classAllocFreeList.m_free = *p_m_next;
  }
  else
  {
    p_m_next = (hkFreeList::Element **)this->m_classAllocFreeList.m_top;
    if ( (char *)p_m_next < this->m_classAllocFreeList.m_blockEnd )
    {
      m_elementSize = this->m_classAllocFreeList.m_elementSize;
      --this->m_classAllocFreeList.m_numFreeElements;
      this->m_classAllocFreeList.m_top = (char *)p_m_next + m_elementSize;
    }
    else
    {
      p_m_next = (hkFreeList::Element **)hkFreeList::addSpace(&this->m_classAllocFreeList);
    }
  }
  *p_m_next = typeName;
  p_m_next[1] = size;
  p_m_next[2] = (hkFreeList::Element *)ptr;
  *((_DWORD *)p_m_next + 6) = flags;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_classAllocMap.m_map,
    hkDefaultMemoryTrackerAllocator::s_allocator,
    ptr,
    (unsigned __int64)p_m_next);
  if ( this->m_trackingEnabled.m_bool )
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &this->m_createdMap.m_map,
      hkDefaultMemoryTrackerAllocator::s_allocator,
      ptr,
      (unsigned __int64)p_m_next);
  LeaveCriticalSection(&this->m_criticalSection.m_section);
  return p_m_next;
}

// File Line: 153
// RVA: 0x1306AF0
void __fastcall hkDefaultMemoryTracker::_removeClassAlloc(hkDefaultMemoryTracker *this, unsigned __int64 ptr)
{
  __int64 Key; // rax
  hkFreeList::Element *val; // rbx
  hkFreeList::Element *m_free; // rdx
  Dummy *v7; // rax

  if ( ptr )
  {
    EnterCriticalSection(&this->m_criticalSection.m_section);
    Key = (__int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                     &this->m_classAllocMap.m_map,
                     ptr);
    if ( (int)Key <= this->m_classAllocMap.m_map.m_hashMod )
    {
      val = (hkFreeList::Element *)this->m_classAllocMap.m_map.m_elem[(int)Key].val;
      m_free = this->m_classAllocFreeList.m_free;
      ++this->m_classAllocFreeList.m_numFreeElements;
      val->m_next = m_free;
      this->m_classAllocFreeList.m_free = val;
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
        &this->m_classAllocMap.m_map,
        Key);
      if ( val == (hkFreeList::Element *)this->m_assertOnRemove )
        this->m_assertOnRemove = 0i64;
    }
    if ( this->m_trackingEnabled.m_bool )
    {
      v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
             &this->m_createdMap.m_map,
             ptr);
      if ( (int)v7 > this->m_createdMap.m_map.m_hashMod )
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &this->m_deletedMap.m_map,
          hkDefaultMemoryTrackerAllocator::s_allocator,
          ptr,
          1ui64);
      else
        hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
          &this->m_createdMap.m_map,
          (__int64)v7);
    }
    LeaveCriticalSection(&this->m_criticalSection.m_section);
  }
}

// File Line: 209
// RVA: 0x13068E0
void __fastcall hkDefaultMemoryTracker::clearTrackingHistory(hkDefaultMemoryTracker *this)
{
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_deletedMap.m_map);
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_createdMap.m_map);
}

// File Line: 215
// RVA: 0x1306830
hkDefaultMemoryTracker::ClassAlloc *__fastcall hkDefaultMemoryTracker::findClassAlloc(
        hkDefaultMemoryTracker *this,
        unsigned __int64 ptr)
{
  hkCriticalSection *p_m_criticalSection; // rsi
  unsigned __int64 v5; // rbx

  p_m_criticalSection = &this->m_criticalSection;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v5 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &this->m_classAllocMap.m_map,
         ptr,
         0i64);
  LeaveCriticalSection(&p_m_criticalSection->m_section);
  return (hkDefaultMemoryTracker::ClassAlloc *)v5;
}

// File Line: 225
// RVA: 0x1306890
void __fastcall hkDefaultMemoryTracker::setAssertRemoveAlloc(
        hkDefaultMemoryTracker *this,
        hkDefaultMemoryTracker::ClassAlloc *alloc)
{
  EnterCriticalSection(&this->m_criticalSection.m_section);
  this->m_assertOnRemove = alloc;
  LeaveCriticalSection(&this->m_criticalSection.m_section);
}

// File Line: 239
// RVA: 0x1306590
void __fastcall hkDefaultMemoryTracker::onNewReferencedObject(
        hkDefaultMemoryTracker *this,
        const char *typeName,
        unsigned __int64 size,
        void *ptr)
{
  hkDefaultMemoryTracker::_addClassAlloc(this, typeName, size, ptr, 1);
}

// File Line: 244
// RVA: 0x13065B0
// attributes: thunk
void __fastcall hkDefaultMemoryTracker::onDeleteReferencedObject(hkDefaultMemoryTracker *this, void *ptr)
{
  hkDefaultMemoryTracker::_removeClassAlloc(this, ptr);
}

// File Line: 250
// RVA: 0x13065C0
void __fastcall hkDefaultMemoryTracker::onNewObject(
        hkDefaultMemoryTracker *this,
        const char *typeName,
        unsigned __int64 size,
        void *ptr)
{
  hkDefaultMemoryTracker::_addClassAlloc(this, typeName, size, ptr, 0);
}

// File Line: 255
// RVA: 0x13065E0
// attributes: thunk
void __fastcall hkDefaultMemoryTracker::onDeleteObject(hkDefaultMemoryTracker *this, void *ptr)
{
  hkDefaultMemoryTracker::_removeClassAlloc(this, ptr);
}

// File Line: 260
// RVA: 0x13065F0
void __fastcall hkDefaultMemoryTracker::onNewRaw(
        hkDefaultMemoryTracker *this,
        const char *name,
        unsigned __int64 size,
        void *ptr)
{
  hkDefaultMemoryTracker::_addClassAlloc(this, name, size, ptr, 0);
}

// File Line: 265
// RVA: 0x1306610
// attributes: thunk
void __fastcall hkDefaultMemoryTracker::onDeleteRaw(hkDefaultMemoryTracker *this, void *ptr)
{
  hkDefaultMemoryTracker::_removeClassAlloc(this, ptr);
}

// File Line: 270
// RVA: 0x1306620
void __fastcall hkDefaultMemoryTracker::addTypeDefinition(
        hkDefaultMemoryTracker *this,
        hkMemoryTracker::TypeDefinition *defIn)
{
  EnterCriticalSection(&this->m_criticalSection.m_section);
  if ( !this->vfptr->findTypeDefinition(this, defIn->m_typeName) )
    hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::insert(
      &this->m_nameTypeMap.m_map,
      (unsigned __int64)defIn->m_typeName,
      (unsigned __int64)defIn);
  LeaveCriticalSection(&this->m_criticalSection.m_section);
}

// File Line: 283
// RVA: 0x1306690
void __fastcall hkDefaultMemoryTracker::clearTypeDefinitions(hkDefaultMemoryTracker *this)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> other; // [rsp+20h] [rbp-28h] BYREF

  EnterCriticalSection(&this->m_criticalSection.m_section);
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>(
    &other,
    0);
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::swap(&this->m_nameTypeMap.m_map, &other);
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::~hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>(&other);
  LeaveCriticalSection(&this->m_criticalSection.m_section);
}

// File Line: 289
// RVA: 0x1306700
hkMemoryTracker::TypeDefinition *__fastcall hkDefaultMemoryTracker::findTypeDefinition(
        hkDefaultMemoryTracker *this,
        const char *typeName)
{
  hkCriticalSection *p_m_criticalSection; // rsi
  unsigned __int64 v5; // rbx

  p_m_criticalSection = &this->m_criticalSection;
  EnterCriticalSection(&this->m_criticalSection.m_section);
  v5 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
         &this->m_nameTypeMap.m_map,
         typeName,
         0i64);
  LeaveCriticalSection(&p_m_criticalSection->m_section);
  return (hkMemoryTracker::TypeDefinition *)v5;
}

// File Line: 295
// RVA: 0x1306760
unsigned __int64 __fastcall hkDefaultMemoryTracker::getTypeDefinitions(
        hkDefaultMemoryTracker *this,
        hkMemoryTracker::TypeDefinition **typeDefinitions)
{
  hkMemoryTracker::TypeDefinition **v2; // rdi
  Dummy *Iterator; // rsi
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  v2 = typeDefinitions;
  if ( !typeDefinitions )
    return this->m_nameTypeMap.m_map.m_numElems;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(&this->m_nameTypeMap.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    &this->m_nameTypeMap.m_map,
    &result,
    Iterator);
  while ( result.m_bool )
  {
    *v2++ = (hkMemoryTracker::TypeDefinition *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                                 &this->m_nameTypeMap.m_map,
                                                 Iterator);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 &this->m_nameTypeMap.m_map,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      &this->m_nameTypeMap.m_map,
      &result,
      Iterator);
  }
  return this->m_nameTypeMap.m_map.m_numElems;
}

