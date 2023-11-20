// File Line: 34
// RVA: 0xE3DCE0
void __fastcall hkPackfileWriter::hkPackfileWriter(hkPackfileWriter *this, hkPackfileWriter::Options *options)
{
  hkPackfileWriter::Options *v2; // rbx
  hkPackfileWriter *v3; // rsi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkPackfileWriter::`vftable;
  this->m_pendingWrites.m_data = 0i64;
  this->m_pendingWrites.m_size = 0;
  this->m_pendingWrites.m_capacityAndFlags = 2147483648;
  this->m_knownObjects.m_map.m_elem = 0i64;
  this->m_knownObjects.m_map.m_numElems = 0;
  this->m_knownObjects.m_map.m_hashMod = -1;
  this->m_imports.m_map.m_elem = 0i64;
  this->m_imports.m_map.m_numElems = 0;
  this->m_imports.m_map.m_hashMod = -1;
  v2 = options;
  this->m_exports.m_map.m_elem = 0i64;
  this->m_exports.m_map.m_numElems = 0;
  this->m_exports.m_map.m_hashMod = -1;
  v3 = this;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_knownClasses.m_map,
    0);
  v3->m_replacements.m_map.m_elem = 0i64;
  v3->m_replacements.m_map.m_numElems = 0;
  v3->m_replacements.m_map.m_hashMod = -1;
  v3->m_knownSections.m_data = 0i64;
  v3->m_knownSections.m_size = 0;
  v3->m_knownSections.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v3->m_sectionTagToIndex.m_map,
    0);
  v3->m_objectsWithUnregisteredClass.m_data = 0i64;
  v3->m_objectsWithUnregisteredClass.m_size = 0;
  *(_QWORD *)&v3->m_objectsWithUnregisteredClass.m_capacityAndFlags = -2147483648i64;
  v3->m_contentsClassPWIndex = -1;
  *(_QWORD *)&v3->m_numDataInstances = 0i64;
  v3->m_sectionOverrideByPointer.m_map.m_elem = 0i64;
  v3->m_sectionOverrideByPointer.m_map.m_numElems = 0;
  v3->m_sectionOverrideByPointer.m_map.m_hashMod = -1;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v3->m_sectionOverrideByType.m_map,
    0);
  v3->m_pwIndexesFromReferencedPointer.m_valueChain.m_data = 0i64;
  v3->m_pwIndexesFromReferencedPointer.m_valueChain.m_size = 0;
  v3->m_pwIndexesFromReferencedPointer.m_valueChain.m_capacityAndFlags = 2147483648;
  v3->m_pwIndexesFromReferencedPointer.m_indexMap.m_map.m_elem = 0i64;
  v3->m_pwIndexesFromReferencedPointer.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&v3->m_pwIndexesFromReferencedPointer.m_indexMap.m_map.m_hashMod = -1i64;
  *(_QWORD *)&v3->m_startOptions.m_userTag = *(_QWORD *)&v2->m_userTag;
  *(_QWORD *)&v3->m_startOptions.m_writeMetaInfo.m_bool = *(_QWORD *)&v2->m_writeMetaInfo.m_bool;
  v3->m_startOptions.m_contentsVersion = v2->m_contentsVersion;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_knownObjects.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)&hkClassEnumClass,
    0xFFFFFFFFFFFFFFFFui64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_knownObjects.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)&hkClassMemberClass,
    0xFFFFFFFFFFFFFFFFui64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_knownObjects.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)&hkClassClass,
    0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 43
// RVA: 0xE3DEA0
void __fastcall hkPackfileWriter::~hkPackfileWriter(hkPackfileWriter *this)
{
  hkPackfileWriter *v1; // rbx
  int v2; // ebp
  __int64 v3; // rsi
  char *v4; // rdi
  hkMemoryAllocator **v5; // rax
  int v6; // er8
  int v7; // er8
  int v8; // er8
  int v9; // eax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkPackfileWriter::`vftable;
  v2 = 0;
  if ( this->m_knownSections.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->m_knownSections.m_data[v3];
      v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::easyFree(v5[11], v4);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_knownSections.m_size );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_pwIndexesFromReferencedPointer.m_indexMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_pwIndexesFromReferencedPointer.m_indexMap);
  v6 = v1->m_pwIndexesFromReferencedPointer.m_valueChain.m_capacityAndFlags;
  v1->m_pwIndexesFromReferencedPointer.m_valueChain.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_pwIndexesFromReferencedPointer.m_valueChain.m_data,
      8 * v6);
  v1->m_pwIndexesFromReferencedPointer.m_valueChain.m_data = 0i64;
  v1->m_pwIndexesFromReferencedPointer.m_valueChain.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_sectionOverrideByType.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_sectionOverrideByPointer.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_sectionOverrideByPointer);
  v7 = v1->m_objectsWithUnregisteredClass.m_capacityAndFlags;
  v1->m_objectsWithUnregisteredClass.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_objectsWithUnregisteredClass.m_data,
      16 * v7);
  v1->m_objectsWithUnregisteredClass.m_data = 0i64;
  v1->m_objectsWithUnregisteredClass.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_sectionTagToIndex.m_map);
  v8 = v1->m_knownSections.m_capacityAndFlags;
  v1->m_knownSections.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_knownSections.m_data,
      8 * v8);
  v1->m_knownSections.m_data = 0i64;
  v1->m_knownSections.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_replacements.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_replacements);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_knownClasses.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_exports.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_exports);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_imports.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_imports);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_knownObjects.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_knownObjects);
  v9 = v1->m_pendingWrites.m_capacityAndFlags;
  v1->m_pendingWrites.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_pendingWrites.m_data,
      40 * (v9 & 0x3FFFFFFF));
  v1->m_pendingWrites.m_data = 0i64;
  v1->m_pendingWrites.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 52
// RVA: 0xE3E110
void __fastcall hkPackfileWriter::setContentsWithRegistry(hkPackfileWriter *this, const void *pointer, hkClass *klass, hkVtableClassRegistry *classRegistry, hkPackfileWriter::AddObjectListener *addListener)
{
  hkVtableClassRegistry *v5; // rsi
  hkClass *v6; // rdi
  const void *v7; // rbp
  hkPackfileWriter *v8; // r14
  hkVtableClassRegistry *v9; // rbx
  hkBool result; // [rsp+50h] [rbp+8h]

  v5 = classRegistry;
  v6 = klass;
  v7 = pointer;
  v8 = this;
  if ( classRegistry )
    v9 = classRegistry;
  else
    v9 = (hkVtableClassRegistry *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)();
  if ( hkClass::hasVtable(v6, &result)->m_bool )
    v6 = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))v9->vfptr[2].__first_virtual_table_function__)(
                      v9,
                      v7);
  hkPackfileWriter::addObject(v8, v7, v6, v5, addListener, hkPackfileWriter::SECTION_TAG_DATA);
  v8->m_contentsPtrPWIndex = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                               (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_knownObjects.m_map.m_elem,
                               (unsigned __int64)v7,
                               0xFFFFFFFFFFFFFFFFui64);
  v8->m_contentsClassPWIndex = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                 (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v8->m_knownObjects.m_map.m_elem,
                                 (unsigned __int64)v6,
                                 0xFFFFFFFFFFFFFFFFui64);
}

// File Line: 69
// RVA: 0xE3E1E0
void __fastcall hkPackfileWriter::setContents(hkPackfileWriter *this, const void *object, hkClass *klass, hkPackfileWriter::AddObjectListener *addListen)
{
  hkPackfileWriter *v4; // r14
  hkPackfileWriter::AddObjectListener *v5; // rdi
  hkBaseObjectVtbl *v6; // rbx
  hkClass *v7; // rsi
  const void *v8; // rbp
  __int64 v9; // rax

  v4 = this;
  v5 = addListen;
  v6 = this->vfptr;
  v7 = klass;
  v8 = object;
  v9 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)();
  ((void (__fastcall *)(hkPackfileWriter *, const void *, hkClass *, __int64, hkPackfileWriter::AddObjectListener *))v6[1].__first_virtual_table_function__)(
    v4,
    v8,
    v7,
    v9,
    v5);
}

// File Line: 74
// RVA: 0xE3E250
void __fastcall hkPackfileWriter::addImport(hkPackfileWriter *this, const void *object, const char *id)
{
  const char *v3; // rbp
  hkPackfileWriter *v4; // rbx
  const void *v5; // rdi
  int v6; // eax

  v3 = id;
  v4 = this;
  v5 = object;
  v6 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_knownObjects.m_map.m_elem,
         (unsigned __int64)object,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v6 >= 0 )
    v4->m_pendingWrites.m_data[v6].m_sectionIndex = -2;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_knownObjects.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)v5,
    0xFFFFFFFFFFFFFFFEui64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_imports.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)v5,
    (unsigned __int64)v3);
}

// File Line: 85
// RVA: 0xE3E2E0
void __fastcall hkPackfileWriter::addExport(hkPackfileWriter *this, const void *object, const char *id)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_exports.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)object,
    (unsigned __int64)id);
}

// File Line: 91
// RVA: 0xE3EB40
__int64 __fastcall hkPackfileWriter::sectionTagToIndex(hkPackfileWriter *this, const char *sectionTag)
{
  const char *v2; // rdi
  hkPackfileWriter *v3; // rbx
  __int64 v4; // rax
  char *v5; // rax
  unsigned int v6; // esi
  char *v7; // rdi
  hkResult result; // [rsp+40h] [rbp+8h]
  unsigned __int64 out; // [rsp+50h] [rbp+18h]

  v2 = sectionTag;
  v3 = this;
  if ( hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::get(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_sectionTagToIndex,
         &result,
         (unsigned __int64)sectionTag,
         &out)->m_enum == HK_SUCCESS )
    return (unsigned int)out;
  v5 = hkString::strDup(v2);
  v6 = v3->m_knownSections.m_size;
  v7 = v5;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &v3->m_sectionTagToIndex.m_map,
    (unsigned __int64)v5,
    v3->m_knownSections.m_size);
  if ( v3->m_knownSections.m_size == (v3->m_knownSections.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_knownSections, 8);
  v4 = v6;
  v3->m_knownSections.m_data[v3->m_knownSections.m_size++] = v7;
  return v4;
}

// File Line: 104
// RVA: 0xE3E3D0
unsigned int __fastcall hkPackfileWriter::findSectionFor(hkPackfileWriter *this, const void *pointer, hkClass *klass, const char *sectionTag)
{
  hkClass *v4; // rbx
  hkPackfileWriter *v5; // rsi
  const char *v6; // rbp
  unsigned int result; // eax
  const char *v8; // rax
  hkClass *v9; // rax
  const char *v10; // rax

  v4 = klass;
  v5 = this;
  v6 = sectionTag;
  result = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_sectionOverrideByPointer.m_map.m_elem,
             (unsigned __int64)pointer,
             0xFFFFFFFFui64);
  if ( result == -1 )
  {
    v8 = hkClass::getName(v4);
    result = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
               (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5->m_sectionOverrideByType,
               (unsigned __int64)v8,
               0xFFFFFFFFui64);
    if ( result == -1 )
    {
      while ( 1 )
      {
        v9 = hkClass::getParent(v4);
        v4 = v9;
        if ( !v9 )
          break;
        v10 = hkClass::getName(v9);
        result = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5->m_sectionOverrideByType,
                   (unsigned __int64)v10,
                   0xFFFFFFFFui64);
        if ( result != -1 )
          return result;
      }
      result = hkPackfileWriter::sectionTagToIndex(v5, v6);
    }
  }
  return result;
}

// File Line: 133
// RVA: 0xE3EC00
hkClass *__fastcall getExactClass(const void *instance, hkClass *base, hkVtableClassRegistry *reg)
{
  hkClass *v3; // rdi
  const void *v4; // rsi
  hkVtableClassRegistry *v5; // rbx
  hkBool result; // [rsp+48h] [rbp+20h]

  v3 = base;
  v4 = instance;
  v5 = reg;
  if ( !hkClass::hasVtable(base, &result)->m_bool )
    return v3;
  if ( v5 )
    return (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))v5->vfptr[2].__first_virtual_table_function__)(
                        v5,
                        v4);
  return 0i64;
}

// File Line: 142
// RVA: 0xE3E8C0
void __fastcall hkPackfileWriter::addPendingWrite(hkPackfileWriter *this, const void *pointer, hkClass *klass, const void *pointerIn, hkClass *klassIn, const char *sectionTag)
{
  const void *v6; // rbp
  hkClass *v7; // rsi
  const void *v8; // r15
  hkPackfileWriter *v9; // rdi
  hkPackfileWriter::PendingWrite *v10; // rdx
  unsigned __int64 v11; // [rsp+40h] [rbp-28h]

  v6 = pointerIn;
  v7 = klass;
  v8 = pointer;
  v9 = this;
  v11 = __PAIR__(-1, hkPackfileWriter::findSectionFor(this, pointerIn, klassIn, sectionTag));
  if ( v9->m_pendingWrites.m_size == (v9->m_pendingWrites.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_pendingWrites, 40);
  v10 = &v9->m_pendingWrites.m_data[v9->m_pendingWrites.m_size];
  if ( v10 )
  {
    v10->m_pointer = v8;
    v10->m_klass = v7;
    v10->m_origPointer = v6;
    v10->m_origClass = klassIn;
    *(_QWORD *)&v10->m_sectionIndex = v11;
  }
  ++v9->m_pendingWrites.m_size;
  v9->m_numClassInstances += v7 == &hkClassClass;
  v9->m_numDataInstances += v7 != &hkClassClass;
}

// File Line: 157
// RVA: 0xE3EC80
void __fastcall chasePointers(const void *pointer, hkClass *klass, hkRelocationInfo *reloc, hkBool writeSerializeIgnore)
{
  const void *v4; // rsi
  hkRelocationInfo *v5; // rbx
  hkClass *v6; // rdi
  hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> v7; // er9
  hkStructureLayout layout; // [rsp+30h] [rbp-48h]
  hkResult result; // [rsp+34h] [rbp-44h]
  hkOffsetOnlyStreamWriter v10; // [rsp+38h] [rbp-40h]
  hkPlatformObjectWriter v11; // [rsp+50h] [rbp-28h]
  char v12; // [rsp+98h] [rbp+20h]

  v12 = writeSerializeIgnore.m_bool;
  v4 = pointer;
  v5 = reloc;
  v6 = klass;
  hkStructureLayout::hkStructureLayout(&layout);
  v7.m_storage = 0;
  if ( !v12 )
    v7.m_storage = 2;
  hkPlatformObjectWriter::hkPlatformObjectWriter(&v11, &layout, 0i64, v7);
  hkOffsetOnlyStreamWriter::hkOffsetOnlyStreamWriter(&v10);
  hkPlatformObjectWriter::writeObject(&v11, &result, (hkStreamWriter *)&v10.vfptr, v4, v6, v5);
  v10.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  hkPlatformObjectWriter::~hkPlatformObjectWriter(&v11);
}

// File Line: 173
// RVA: 0xE3E9B0
signed __int64 __fastcall hkPackfileWriter::notDuplicateMetaData(hkPackfileWriter *this, const void *pointer, hkClass *klass)
{
  hkPackfileWriter *v3; // rbp
  hkClass *v4; // rdi
  const char *v5; // rax
  const char *v6; // rax
  hkClass *v7; // rax
  unsigned __int64 v8; // rsi
  unsigned int v9; // ebx
  const char *v10; // rbx
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  int v13; // eax
  signed __int64 result; // rax
  const char *v15; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v3 = this;
  v4 = (hkClass *)pointer;
  v5 = hkClass::getName(klass);
  if ( (unsigned int)hkString::strCmp(v5, "hkClass") )
    return 1i64;
  v6 = hkClass::getName(v4);
  v7 = (hkClass *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_knownClasses,
                    (unsigned __int64)v6,
                    0i64);
  v8 = (unsigned __int64)v7;
  if ( v7 )
  {
    v9 = hkClass::getSignature(v7, 0);
    if ( hkClass::getSignature(v4, 0) != v9 )
    {
      hkErrStream::hkErrStream(&v16, &buf, 512);
      v10 = hkClass::getName(v4);
      v11 = hkOstream::operator<<((hkOstream *)&v16.vfptr, "Conflicting metadata found for class ");
      v12 = hkOstream::operator<<(v11, v10);
      hkOstream::operator<<(
        v12,
        ". Perhaps you have called setContents on data which has not been updated to the current version.");
      if ( (unsigned int)hkError::messageError(622359068, &buf, "Packfile\\hkPackfileWriter.cpp", 184) )
        __debugbreak();
      hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
    }
    v13 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_knownObjects.m_map.m_elem,
            v8,
            0xFFFFFFFFFFFFFFFFui64);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_knownObjects.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned __int64)v4,
      v13);
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_replacements.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned __int64)v4,
      v8);
    result = 0i64;
  }
  else
  {
    v15 = hkClass::getName(v4);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &v3->m_knownClasses.m_map,
      (unsigned __int64)v15,
      (unsigned __int64)v4);
    result = 1i64;
  }
  return result;
}

// File Line: 200
// RVA: 0xE3E490
void __fastcall hkPackfileWriter::addObject(hkPackfileWriter *this, const void *pointerIn, hkClass *klassIn, hkVtableClassRegistry *classRegistry, hkPackfileWriter::AddObjectListener *addListener, const char *sectionTag)
{
  hkPackfileWriter *v6; // rdi
  void *v7; // rsi
  hkClass *v8; // rax
  void *v9; // rdx
  void *v10; // rdx
  hkBool v11; // r9
  int v12; // esi
  __int64 v13; // rcx
  void *v14; // rbx
  unsigned int v15; // eax
  unsigned int v16; // eax
  const char *v17; // rbx
  hkOstream *v18; // rax
  hkOstream *v19; // rax
  hkOstream *v20; // rax
  hkOstream *v21; // rax
  hkArray<hkVariant,hkContainerHeapAllocator> *v22; // rdi
  hkVariant *v23; // rax
  hkClass *v24; // rcx
  void *pointer; // [rsp+30h] [rbp-D0h]
  hkClass *klass; // [rsp+38h] [rbp-C8h]
  __int64 v27; // [rsp+40h] [rbp-C0h]
  hkRelocationInfo reloc; // [rsp+50h] [rbp-B0h]
  hkErrStream v29; // [rsp+A0h] [rbp-60h]
  char buf; // [rsp+C0h] [rbp-40h]
  hkClass *base; // [rsp+2E0h] [rbp+1E0h]
  hkVtableClassRegistry *reg; // [rsp+2F8h] [rbp+1F8h]

  reg = classRegistry;
  v6 = this;
  base = klassIn;
  v7 = (void *)pointerIn;
  if ( (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_knownObjects.m_map.m_elem,
                     (unsigned __int64)pointerIn) > this->m_knownObjects.m_map.m_hashMod )
  {
    v8 = getExactClass(v7, base, reg);
    if ( v8 )
    {
      v9 = v7;
      klass = v8;
      pointer = v7;
      if ( addListener )
      {
        ((void (__fastcall *)(hkPackfileWriter::AddObjectListener *, void **, hkClass **))addListener->vfptr[1].__first_virtual_table_function__)(
          addListener,
          &pointer,
          &klass);
        v9 = pointer;
        v8 = klass;
      }
      if ( v9 )
      {
        if ( hkPackfileWriter::notDuplicateMetaData(v6, v9, v8)
          && (v7 == pointer
           || (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_knownObjects.m_map.m_elem,
                            (unsigned __int64)pointer) > v6->m_knownObjects.m_map.m_hashMod) )
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_knownObjects.m_map.m_elem,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (unsigned __int64)v7,
            v6->m_pendingWrites.m_size);
          v10 = pointer;
          if ( pointer != v7 )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_knownObjects.m_map.m_elem,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (unsigned __int64)pointer,
              v6->m_pendingWrites.m_size);
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_replacements.m_map.m_elem,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              (unsigned __int64)pointer,
              (unsigned __int64)v7);
            v10 = pointer;
          }
          hkPackfileWriter::addPendingWrite(v6, v10, klass, v7, base, sectionTag);
          v11.m_bool = v6->m_startOptions.m_writeSerializedFalse.m_bool;
          v12 = 0;
          reloc.m_local.m_data = 0i64;
          reloc.m_local.m_size = 0;
          reloc.m_local.m_capacityAndFlags = 2147483648;
          reloc.m_global.m_data = 0i64;
          reloc.m_global.m_size = 0;
          reloc.m_global.m_capacityAndFlags = 2147483648;
          reloc.m_finish.m_data = 0i64;
          reloc.m_finish.m_size = 0;
          reloc.m_finish.m_capacityAndFlags = 2147483648;
          reloc.m_imports.m_data = 0i64;
          reloc.m_imports.m_size = 0;
          reloc.m_imports.m_capacityAndFlags = 2147483648;
          reloc.m_pool = 0i64;
          chasePointers(pointer, klass, &reloc, v11);
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
                  && (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                   (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_sectionOverrideByPointer.m_map.m_elem,
                                   (unsigned __int64)v14) > v6->m_sectionOverrideByPointer.m_map.m_hashMod )
                {
                  v15 = hkPackfileWriter::sectionTagToIndex(v6, sectionTag);
                  v16 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_sectionOverrideByPointer.m_map.m_elem,
                          (unsigned __int64)pointer,
                          v15);
                  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_sectionOverrideByPointer.m_map.m_elem,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    (unsigned __int64)v14,
                    v16);
                }
                hkPackfileWriter::addObject(v6, v14, base, reg, addListener, sectionTag);
                if ( pointer != v14 )
                {
                  LODWORD(base) = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_knownObjects.m_map.m_elem,
                                    (unsigned __int64)v14,
                                    0xFFFFFFFFFFFFFFFFui64);
                  if ( (_DWORD)base != -1 )
                    hkSerializeMultiMap<char const *,int,hkPointerMap<char const *,int,hkContainerHeapAllocator>>::insert(
                      &v6->m_pwIndexesFromReferencedPointer,
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
          hkPackfileWriter::addObject(v6, klass, &hkClassClass, reg, addListener, hkPackfileWriter::SECTION_TAG_TYPES);
          hkRelocationInfo::~hkRelocationInfo(&reloc);
        }
      }
      else
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_knownObjects.m_map.m_elem,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (unsigned __int64)v7,
          0xFFFFFFFFFFFFFFFFui64);
      }
    }
    else
    {
      hkErrStream::hkErrStream(&v29, &buf, 512);
      v17 = hkClass::getName(base);
      v18 = hkOstream::operator<<((hkOstream *)&v29.vfptr, "Found an un-registered class derived from ");
      v19 = hkOstream::operator<<(v18, v17);
      v20 = hkOstream::operator<<(v19, ". Derived class will not be serialized unless added to class registry.\n");
      v21 = hkOstream::operator<<(v20, "All saved pointers to this object will be set to NULL.\n");
      hkOstream::operator<<(
        v21,
        "Saved file will not generate warnings (or asserts) on load but NULL pointers may cause runtime crashes.");
      hkError::messageWarning(-1413829702, &buf, "Packfile\\hkPackfileWriter.cpp", 275);
      hkOstream::~hkOstream((hkOstream *)&v29.vfptr);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_knownObjects.m_map.m_elem,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v7,
        0xFFFFFFFFFFFFFFFFui64);
      v22 = &v6->m_objectsWithUnregisteredClass;
      if ( v22->m_size == (v22->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v22, 16);
      v23 = &v22->m_data[v22->m_size];
      if ( v23 )
      {
        v24 = base;
        v23->m_object = v7;
        v23->m_class = v24;
      }
      ++v22->m_size;
    }
  }
}

// File Line: 285
// RVA: 0xE3E300
void __fastcall hkPackfileWriter::addSection(hkPackfileWriter *this, const char *sectionTag)
{
  hkPackfileWriter::sectionTagToIndex(this, sectionTag);
}

// File Line: 290
// RVA: 0xE3E310
void __fastcall hkPackfileWriter::setSectionForPointer(hkPackfileWriter *this, const void *ptr, const char *sectionTag)
{
  const void *v3; // rdi
  hkPackfileWriter *v4; // rbx
  unsigned int v5; // eax

  v3 = ptr;
  v4 = this;
  v5 = hkPackfileWriter::sectionTagToIndex(this, sectionTag);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_sectionOverrideByPointer.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)v3,
    v5);
}

// File Line: 295
// RVA: 0xE3E360
void __fastcall hkPackfileWriter::setSectionForClass(hkPackfileWriter *this, hkClass *k, const char *sectionTag)
{
  hkClass *v3; // rdi
  hkPackfileWriter *v4; // rsi
  unsigned int v5; // ebx
  const char *v6; // rax

  v3 = k;
  v4 = this;
  v5 = hkPackfileWriter::sectionTagToIndex(this, sectionTag);
  v6 = hkClass::getName(v3);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &v4->m_sectionOverrideByType.m_map,
    (unsigned __int64)v6,
    v5);
}

// File Line: 300
// RVA: 0xE3E3B0
void __fastcall hkPackfileWriter::getCurrentVersion(char *buf, int bufLen)
{
  hkString::snprintf(buf, bufLen, "%s", "hk_2013.2.0-r1");
}

