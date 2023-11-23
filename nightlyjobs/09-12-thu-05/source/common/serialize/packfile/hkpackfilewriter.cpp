// File Line: 34
// RVA: 0xE3DCE0
void __fastcall hkPackfileWriter::hkPackfileWriter(hkPackfileWriter *this, hkPackfileWriter::Options *options)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkPackfileWriter::`vftable;
  this->m_pendingWrites.m_data = 0i64;
  this->m_pendingWrites.m_size = 0;
  this->m_pendingWrites.m_capacityAndFlags = 0x80000000;
  this->m_knownObjects.m_map.m_elem = 0i64;
  this->m_knownObjects.m_map.m_numElems = 0;
  this->m_knownObjects.m_map.m_hashMod = -1;
  this->m_imports.m_map.m_elem = 0i64;
  this->m_imports.m_map.m_numElems = 0;
  this->m_imports.m_map.m_hashMod = -1;
  this->m_exports.m_map.m_elem = 0i64;
  this->m_exports.m_map.m_numElems = 0;
  this->m_exports.m_map.m_hashMod = -1;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_knownClasses.m_map,
    0);
  this->m_replacements.m_map.m_elem = 0i64;
  this->m_replacements.m_map.m_numElems = 0;
  this->m_replacements.m_map.m_hashMod = -1;
  this->m_knownSections.m_data = 0i64;
  this->m_knownSections.m_size = 0;
  this->m_knownSections.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_sectionTagToIndex.m_map,
    0);
  this->m_objectsWithUnregisteredClass.m_data = 0i64;
  this->m_objectsWithUnregisteredClass.m_size = 0;
  *(_QWORD *)&this->m_objectsWithUnregisteredClass.m_capacityAndFlags = 0xFFFFFFFF80000000ui64;
  this->m_contentsClassPWIndex = -1;
  *(_QWORD *)&this->m_numDataInstances = 0i64;
  this->m_sectionOverrideByPointer.m_map.m_elem = 0i64;
  this->m_sectionOverrideByPointer.m_map.m_numElems = 0;
  this->m_sectionOverrideByPointer.m_map.m_hashMod = -1;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_sectionOverrideByType.m_map,
    0);
  this->m_pwIndexesFromReferencedPointer.m_valueChain.m_data = 0i64;
  this->m_pwIndexesFromReferencedPointer.m_valueChain.m_size = 0;
  this->m_pwIndexesFromReferencedPointer.m_valueChain.m_capacityAndFlags = 0x80000000;
  this->m_pwIndexesFromReferencedPointer.m_indexMap.m_map.m_elem = 0i64;
  this->m_pwIndexesFromReferencedPointer.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&this->m_pwIndexesFromReferencedPointer.m_indexMap.m_map.m_hashMod = -1i64;
  this->m_startOptions = *options;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_knownObjects.m_map,
    &hkContainerHeapAllocator::s_alloc,
    (unsigned __int64)&hkClassEnumClass,
    0xFFFFFFFFFFFFFFFFui64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_knownObjects.m_map,
    &hkContainerHeapAllocator::s_alloc,
    (unsigned __int64)&hkClassMemberClass,
    0xFFFFFFFFFFFFFFFFui64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_knownObjects.m_map,
    &hkContainerHeapAllocator::s_alloc,
    (unsigned __int64)&hkClassClass,
    0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 43
// RVA: 0xE3DEA0
void __fastcall hkPackfileWriter::~hkPackfileWriter(hkPackfileWriter *this)
{
  int v2; // ebp
  __int64 v3; // rsi
  char *v4; // rdi
  hkMemoryAllocator **Value; // rax
  int m_capacityAndFlags; // r8d
  int v7; // r8d
  int v8; // r8d
  int v9; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkPackfileWriter::`vftable;
  v2 = 0;
  if ( this->m_knownSections.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_knownSections.m_data[v3];
      Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::easyFree(Value[11], v4);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_knownSections.m_size );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_pwIndexesFromReferencedPointer.m_indexMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_pwIndexesFromReferencedPointer.m_indexMap);
  m_capacityAndFlags = this->m_pwIndexesFromReferencedPointer.m_valueChain.m_capacityAndFlags;
  this->m_pwIndexesFromReferencedPointer.m_valueChain.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_pwIndexesFromReferencedPointer.m_valueChain.m_data,
      8 * m_capacityAndFlags);
  this->m_pwIndexesFromReferencedPointer.m_valueChain.m_data = 0i64;
  this->m_pwIndexesFromReferencedPointer.m_valueChain.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_sectionOverrideByType.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_sectionOverrideByPointer.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_sectionOverrideByPointer);
  v7 = this->m_objectsWithUnregisteredClass.m_capacityAndFlags;
  this->m_objectsWithUnregisteredClass.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_objectsWithUnregisteredClass.m_data,
      16 * v7);
  this->m_objectsWithUnregisteredClass.m_data = 0i64;
  this->m_objectsWithUnregisteredClass.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_sectionTagToIndex.m_map);
  v8 = this->m_knownSections.m_capacityAndFlags;
  this->m_knownSections.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_knownSections.m_data,
      8 * v8);
  this->m_knownSections.m_data = 0i64;
  this->m_knownSections.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_replacements.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_replacements);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_knownClasses.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_exports.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_exports);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_imports.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_imports);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_knownObjects.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_knownObjects);
  v9 = this->m_pendingWrites.m_capacityAndFlags;
  this->m_pendingWrites.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_pendingWrites.m_data,
      40 * (v9 & 0x3FFFFFFF));
  this->m_pendingWrites.m_data = 0i64;
  this->m_pendingWrites.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 52
// RVA: 0xE3E110
void __fastcall hkPackfileWriter::setContentsWithRegistry(
        hkPackfileWriter *this,
        const void *pointer,
        hkClass *klass,
        hkVtableClassRegistry *classRegistry,
        hkPackfileWriter::AddObjectListener *addListener)
{
  hkVtableClassRegistry *v9; // rbx
  hkBool result; // [rsp+50h] [rbp+8h] BYREF

  if ( classRegistry )
    v9 = classRegistry;
  else
    v9 = (hkVtableClassRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  if ( hkClass::hasVtable(klass, &result)->m_bool )
    klass = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))v9->vfptr[2].__first_virtual_table_function__)(
                         v9,
                         pointer);
  hkPackfileWriter::addObject(this, pointer, klass, classRegistry, addListener, hkPackfileWriter::SECTION_TAG_DATA);
  this->m_contentsPtrPWIndex = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                 &this->m_knownObjects.m_map,
                                 (unsigned __int64)pointer,
                                 0xFFFFFFFFFFFFFFFFui64);
  this->m_contentsClassPWIndex = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                   &this->m_knownObjects.m_map,
                                   (unsigned __int64)klass,
                                   0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 69
// RVA: 0xE3E1E0
void __fastcall hkPackfileWriter::setContents(
        hkPackfileWriter *this,
        const void *object,
        hkClass *klass,
        hkPackfileWriter::AddObjectListener *addListen)
{
  hkBaseObjectVtbl *vfptr; // rbx
  __int64 v9; // rax

  vfptr = this->vfptr;
  v9 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  ((void (__fastcall *)(hkPackfileWriter *, const void *, hkClass *, __int64, hkPackfileWriter::AddObjectListener *))vfptr[1].__first_virtual_table_function__)(
    this,
    object,
    klass,
    v9,
    addListen);
}

// File Line: 74
// RVA: 0xE3E250
void __fastcall hkPackfileWriter::addImport(hkPackfileWriter *this, unsigned __int64 object, const char *id)
{
  int v6; // eax

  v6 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &this->m_knownObjects.m_map,
         object,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v6 >= 0 )
    this->m_pendingWrites.m_data[v6].m_sectionIndex = -2;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_knownObjects.m_map,
    &hkContainerHeapAllocator::s_alloc,
    object,
    0xFFFFFFFFFFFFFFFEui64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_imports.m_map,
    &hkContainerHeapAllocator::s_alloc,
    object,
    (unsigned __int64)id);
}

// File Line: 85
// RVA: 0xE3E2E0
void __fastcall hkPackfileWriter::addExport(hkPackfileWriter *this, unsigned __int64 object, const char *id)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_exports.m_map,
    &hkContainerHeapAllocator::s_alloc,
    object,
    (unsigned __int64)id);
}

// File Line: 91
// RVA: 0xE3EB40
__int64 __fastcall hkPackfileWriter::sectionTagToIndex(hkPackfileWriter *this, char *sectionTag)
{
  __int64 v4; // rax
  char *v5; // rax
  int m_size; // esi
  char *v7; // rdi
  hkResult result; // [rsp+40h] [rbp+8h] BYREF
  unsigned __int64 out; // [rsp+50h] [rbp+18h] BYREF

  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_sectionTagToIndex,
         &result,
         sectionTag,
         &out)->m_enum == HK_SUCCESS )
    return (unsigned int)out;
  v5 = hkString::strDup(sectionTag);
  m_size = this->m_knownSections.m_size;
  v7 = v5;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_sectionTagToIndex.m_map, v5, m_size);
  if ( this->m_knownSections.m_size == (this->m_knownSections.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_knownSections.m_data, 8);
  v4 = (unsigned int)m_size;
  this->m_knownSections.m_data[this->m_knownSections.m_size++] = v7;
  return v4;
}

// File Line: 104
// RVA: 0xE3E3D0
unsigned int __fastcall hkPackfileWriter::findSectionFor(
        hkPackfileWriter *this,
        unsigned __int64 pointer,
        hkClass *klass,
        const char *sectionTag)
{
  unsigned int result; // eax
  const char *Name; // rax
  hkClass *Parent; // rax
  const char *v10; // rax

  result = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
             &this->m_sectionOverrideByPointer.m_map,
             pointer,
             0xFFFFFFFFui64);
  if ( result == -1 )
  {
    Name = hkClass::getName(klass);
    result = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
               (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_sectionOverrideByType,
               Name,
               0xFFFFFFFFui64);
    if ( result == -1 )
    {
      while ( 1 )
      {
        Parent = hkClass::getParent(klass);
        klass = Parent;
        if ( !Parent )
          break;
        v10 = hkClass::getName(Parent);
        result = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_sectionOverrideByType,
                   v10,
                   0xFFFFFFFFui64);
        if ( result != -1 )
          return result;
      }
      return hkPackfileWriter::sectionTagToIndex(this, sectionTag);
    }
  }
  return result;
}

// File Line: 133
// RVA: 0xE3EC00
hkClass *__fastcall getExactClass(const void *instance, hkClass *base, hkVtableClassRegistry *reg)
{
  hkBool result; // [rsp+48h] [rbp+20h] BYREF

  if ( !hkClass::hasVtable(base, &result)->m_bool )
    return base;
  if ( reg )
    return (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))reg->vfptr[2].__first_virtual_table_function__)(
                        reg,
                        instance);
  return 0i64;
}

// File Line: 142
// RVA: 0xE3E8C0
void __fastcall hkPackfileWriter::addPendingWrite(
        hkPackfileWriter *this,
        const void *pointer,
        hkClass *klass,
        unsigned __int64 pointerIn,
        hkClass *klassIn,
        const char *sectionTag)
{
  hkPackfileWriter::PendingWrite *v10; // rdx
  unsigned __int64 v11; // [rsp+40h] [rbp-28h]

  v11 = hkPackfileWriter::findSectionFor(this, pointerIn, klassIn, sectionTag) | 0xFFFFFFFF00000000ui64;
  if ( this->m_pendingWrites.m_size == (this->m_pendingWrites.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_pendingWrites.m_data, 40);
  v10 = &this->m_pendingWrites.m_data[this->m_pendingWrites.m_size];
  if ( v10 )
  {
    v10->m_pointer = pointer;
    v10->m_klass = klass;
    v10->m_origPointer = (const void *)pointerIn;
    v10->m_origClass = klassIn;
    *(_QWORD *)&v10->m_sectionIndex = v11;
  }
  ++this->m_pendingWrites.m_size;
  this->m_numClassInstances += klass == &hkClassClass;
  this->m_numDataInstances += klass != &hkClassClass;
}

// File Line: 157
// RVA: 0xE3EC80
void __fastcall chasePointers(
        const void *pointer,
        hkClass *klass,
        hkRelocationInfo *reloc,
        hkBool writeSerializeIgnore)
{
  hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> v7; // r9d
  hkStructureLayout layout; // [rsp+30h] [rbp-48h] BYREF
  hkResult result; // [rsp+34h] [rbp-44h] BYREF
  hkOffsetOnlyStreamWriter v10; // [rsp+38h] [rbp-40h] BYREF
  hkPlatformObjectWriter v11; // [rsp+50h] [rbp-28h] BYREF

  hkStructureLayout::hkStructureLayout(&layout);
  v7.m_storage = 0;
  if ( !writeSerializeIgnore.m_bool )
    v7.m_storage = 2;
  hkPlatformObjectWriter::hkPlatformObjectWriter(&v11, &layout, 0i64, v7);
  hkOffsetOnlyStreamWriter::hkOffsetOnlyStreamWriter(&v10);
  hkPlatformObjectWriter::writeObject(&v11, &result, &v10, pointer, klass, reloc);
  v10.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  hkPlatformObjectWriter::~hkPlatformObjectWriter(&v11);
}

// File Line: 173
// RVA: 0xE3E9B0
__int64 __fastcall hkPackfileWriter::notDuplicateMetaData(hkPackfileWriter *this, hkClass *pointer, hkClass *klass)
{
  const char *Name; // rax
  const char *v6; // rax
  hkClass *v7; // rax
  unsigned __int64 v8; // rsi
  unsigned int Signature; // ebx
  const char *v10; // rbx
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  int v13; // eax
  const char *v15; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h] BYREF
  char buf[520]; // [rsp+40h] [rbp-208h] BYREF

  Name = hkClass::getName(klass);
  if ( (unsigned int)hkString::strCmp(Name, "hkClass") )
    return 1i64;
  v6 = hkClass::getName(pointer);
  v7 = (hkClass *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_knownClasses,
                    v6,
                    0i64);
  v8 = (unsigned __int64)v7;
  if ( v7 )
  {
    Signature = hkClass::getSignature(v7, 0);
    if ( hkClass::getSignature(pointer, 0) != Signature )
    {
      hkErrStream::hkErrStream(&v16, buf, 512);
      v10 = hkClass::getName(pointer);
      v11 = hkOstream::operator<<(&v16, "Conflicting metadata found for class ");
      v12 = hkOstream::operator<<(v11, v10);
      hkOstream::operator<<(
        v12,
        ". Perhaps you have called setContents on data which has not been updated to the current version.");
      if ( (unsigned int)hkError::messageError(0x2518721Cu, buf, "Packfile\\hkPackfileWriter.cpp", 184) )
        __debugbreak();
      hkOstream::~hkOstream(&v16);
    }
    v13 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            &this->m_knownObjects.m_map,
            v8,
            0xFFFFFFFFFFFFFFFFui64);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &this->m_knownObjects.m_map,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)pointer,
      v13);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &this->m_replacements.m_map,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)pointer,
      v8);
    return 0i64;
  }
  else
  {
    v15 = hkClass::getName(pointer);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &this->m_knownClasses.m_map,
      v15,
      (unsigned __int64)pointer);
    return 1i64;
  }
}

// File Line: 200
// RVA: 0xE3E490
void __fastcall hkPackfileWriter::addObject(
        hkPackfileWriter *this,
        void *pointerIn,
        hkClass *klassIn,
        hkVtableClassRegistry *classRegistry,
        hkPackfileWriter::AddObjectListener *addListener,
        const char *sectionTag)
{
  hkClass *ExactClass; // rax
  void *v9; // rdx
  void *v10; // rdx
  char m_bool; // r9
  int v12; // esi
  __int64 v13; // rcx
  void *v14; // rbx
  unsigned int v15; // eax
  unsigned int v16; // eax
  const char *Name; // rbx
  hkOstream *v18; // rax
  hkOstream *v19; // rax
  hkOstream *v20; // rax
  hkOstream *v21; // rax
  hkArray<hkVariant,hkContainerHeapAllocator> *p_m_objectsWithUnregisteredClass; // rdi
  hkVariant *v23; // rax
  hkClass *v24; // rcx
  void *pointer; // [rsp+30h] [rbp-D0h] BYREF
  hkClass *klass; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v27; // [rsp+40h] [rbp-C0h]
  hkRelocationInfo reloc; // [rsp+50h] [rbp-B0h] BYREF
  hkErrStream v29; // [rsp+A0h] [rbp-60h] BYREF
  char buf[528]; // [rsp+C0h] [rbp-40h] BYREF
  hkClass *base; // [rsp+2E0h] [rbp+1E0h] BYREF
  hkVtableClassRegistry *reg; // [rsp+2F8h] [rbp+1F8h]

  reg = classRegistry;
  base = klassIn;
  if ( (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
              &this->m_knownObjects.m_map,
              (unsigned __int64)pointerIn) > this->m_knownObjects.m_map.m_hashMod )
  {
    ExactClass = getExactClass(pointerIn, base, reg);
    if ( ExactClass )
    {
      v9 = pointerIn;
      klass = ExactClass;
      pointer = pointerIn;
      if ( addListener )
      {
        ((void (__fastcall *)(hkPackfileWriter::AddObjectListener *, void **, hkClass **))addListener->vfptr[1].__first_virtual_table_function__)(
          addListener,
          &pointer,
          &klass);
        v9 = pointer;
        ExactClass = klass;
      }
      if ( v9 )
      {
        if ( hkPackfileWriter::notDuplicateMetaData(this, v9, ExactClass)
          && (pointerIn == pointer
           || (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                     &this->m_knownObjects.m_map,
                     (unsigned __int64)pointer) > this->m_knownObjects.m_map.m_hashMod) )
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &this->m_knownObjects.m_map,
            &hkContainerHeapAllocator::s_alloc,
            (unsigned __int64)pointerIn,
            this->m_pendingWrites.m_size);
          v10 = pointer;
          if ( pointer != pointerIn )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &this->m_knownObjects.m_map,
              &hkContainerHeapAllocator::s_alloc,
              (unsigned __int64)pointer,
              this->m_pendingWrites.m_size);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &this->m_replacements.m_map,
              &hkContainerHeapAllocator::s_alloc,
              (unsigned __int64)pointer,
              (unsigned __int64)pointerIn);
            v10 = pointer;
          }
          hkPackfileWriter::addPendingWrite(this, v10, klass, pointerIn, base, sectionTag);
          m_bool = this->m_startOptions.m_writeSerializedFalse.m_bool;
          v12 = 0;
          reloc.m_local.m_data = 0i64;
          reloc.m_local.m_size = 0;
          reloc.m_local.m_capacityAndFlags = 0x80000000;
          reloc.m_global.m_data = 0i64;
          reloc.m_global.m_size = 0;
          reloc.m_global.m_capacityAndFlags = 0x80000000;
          reloc.m_finish.m_data = 0i64;
          reloc.m_finish.m_size = 0;
          reloc.m_finish.m_capacityAndFlags = 0x80000000;
          reloc.m_imports.m_data = 0i64;
          reloc.m_imports.m_size = 0;
          reloc.m_imports.m_capacityAndFlags = 0x80000000;
          reloc.m_pool = 0i64;
          chasePointers(pointer, klass, &reloc, (hkBool)m_bool);
          if ( reloc.m_global.m_size > 0 )
          {
            v13 = 0i64;
            v27 = 0i64;
            do
            {
              v14 = *(void **)((char *)&reloc.m_global.m_data->m_toAddress + v13);
              base = *(hkClass **)((char *)&reloc.m_global.m_data->m_toClass + v13);
              if ( base && v14 )
              {
                if ( *(unsigned int *)((char *)&reloc.m_global.m_data->m_related + v13)
                  && (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                            &this->m_sectionOverrideByPointer.m_map,
                            (unsigned __int64)v14) > this->m_sectionOverrideByPointer.m_map.m_hashMod )
                {
                  v15 = hkPackfileWriter::sectionTagToIndex(this, sectionTag);
                  v16 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                          &this->m_sectionOverrideByPointer.m_map,
                          (unsigned __int64)pointer,
                          v15);
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                    &this->m_sectionOverrideByPointer.m_map,
                    &hkContainerHeapAllocator::s_alloc,
                    (unsigned __int64)v14,
                    v16);
                }
                hkPackfileWriter::addObject(this, v14, base, reg, addListener, sectionTag);
                if ( pointer != v14 )
                {
                  LODWORD(base) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                    &this->m_knownObjects.m_map,
                                    (unsigned __int64)v14,
                                    0xFFFFFFFFFFFFFFFFui64);
                  if ( (_DWORD)base != -1 )
                    hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::insert(
                      &this->m_pwIndexesFromReferencedPointer,
                      pointer,
                      (const int *)&base);
                }
                v13 = v27;
              }
              v13 += 32i64;
              ++v12;
              v27 = v13;
            }
            while ( v12 < reloc.m_global.m_size );
          }
          hkPackfileWriter::addObject(this, klass, &hkClassClass, reg, addListener, hkPackfileWriter::SECTION_TAG_TYPES);
          hkRelocationInfo::~hkRelocationInfo(&reloc);
        }
      }
      else
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &this->m_knownObjects.m_map,
          &hkContainerHeapAllocator::s_alloc,
          (unsigned __int64)pointerIn,
          0xFFFFFFFFFFFFFFFFui64);
      }
    }
    else
    {
      hkErrStream::hkErrStream(&v29, buf, 512);
      Name = hkClass::getName(base);
      v18 = hkOstream::operator<<(&v29, "Found an un-registered class derived from ");
      v19 = hkOstream::operator<<(v18, Name);
      v20 = hkOstream::operator<<(v19, ". Derived class will not be serialized unless added to class registry.\n");
      v21 = hkOstream::operator<<(v20, "All saved pointers to this object will be set to NULL.\n");
      hkOstream::operator<<(
        v21,
        "Saved file will not generate warnings (or asserts) on load but NULL pointers may cause runtime crashes.");
      hkError::messageWarning(0xABBAABBA, buf, "Packfile\\hkPackfileWriter.cpp", 275);
      hkOstream::~hkOstream(&v29);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &this->m_knownObjects.m_map,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)pointerIn,
        0xFFFFFFFFFFFFFFFFui64);
      p_m_objectsWithUnregisteredClass = &this->m_objectsWithUnregisteredClass;
      if ( p_m_objectsWithUnregisteredClass->m_size == (p_m_objectsWithUnregisteredClass->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&p_m_objectsWithUnregisteredClass->m_data,
          16);
      v23 = &p_m_objectsWithUnregisteredClass->m_data[p_m_objectsWithUnregisteredClass->m_size];
      if ( v23 )
      {
        v24 = base;
        v23->m_object = pointerIn;
        v23->m_class = v24;
      }
      ++p_m_objectsWithUnregisteredClass->m_size;
    }
  }
}

// File Line: 285
// RVA: 0xE3E300
// attributes: thunk
void __fastcall hkPackfileWriter::addSection(hkPackfileWriter *this, const char *sectionTag)
{
  hkPackfileWriter::sectionTagToIndex(this, sectionTag);
}

// File Line: 290
// RVA: 0xE3E310
void __fastcall hkPackfileWriter::setSectionForPointer(
        hkPackfileWriter *this,
        unsigned __int64 ptr,
        const char *sectionTag)
{
  unsigned int v5; // eax

  v5 = hkPackfileWriter::sectionTagToIndex(this, sectionTag);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_sectionOverrideByPointer.m_map,
    &hkContainerHeapAllocator::s_alloc,
    ptr,
    v5);
}

// File Line: 295
// RVA: 0xE3E360
void __fastcall hkPackfileWriter::setSectionForClass(hkPackfileWriter *this, hkClass *k, const char *sectionTag)
{
  unsigned int v5; // ebx
  const char *Name; // rax

  v5 = hkPackfileWriter::sectionTagToIndex(this, sectionTag);
  Name = hkClass::getName(k);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_sectionOverrideByType.m_map,
    Name,
    v5);
}

// File Line: 300
// RVA: 0xE3E3B0
void __fastcall hkPackfileWriter::getCurrentVersion(char *buf, int bufLen)
{
  hkString::snprintf(buf, bufLen, "%s", "hk_2013.2.0-r1");
}

