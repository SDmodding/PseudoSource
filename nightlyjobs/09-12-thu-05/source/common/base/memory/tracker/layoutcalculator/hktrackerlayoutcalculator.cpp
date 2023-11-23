// File Line: 29
// RVA: 0x1304DD0
void __fastcall hkTrackerLayoutCalculator::hkTrackerLayoutCalculator(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeCache *typeCache)
{
  _QWORD **Value; // rax
  __int64 v5; // rax
  hkTrackerLayoutHandler *v6; // rdi
  _QWORD **v7; // rax
  __int64 v8; // rax
  hkTrackerLayoutHandler *v9; // rdi
  _QWORD **v10; // rax
  __int64 v11; // rax
  hkTrackerLayoutHandler *v12; // rdi
  _QWORD **v13; // rax
  __int64 v14; // rax
  hkTrackerLayoutHandler *v15; // rdi
  _QWORD **v16; // rax
  __int64 v17; // rax
  hkTrackerLayoutHandler *v18; // rdi
  _QWORD **v19; // rax
  __int64 v20; // rax
  hkTrackerLayoutHandler *v21; // rdi
  _QWORD **v22; // rax
  __int64 v23; // rax
  hkTrackerLayoutHandler *v24; // rdi
  _QWORD **v25; // rax
  __int64 v26; // rax
  hkTrackerLayoutHandler *v27; // rdi
  _QWORD **v28; // rax
  __int64 v29; // rax
  hkTrackerLayoutHandler *v30; // rdi
  _QWORD **v31; // rax
  __int64 v32; // rax
  hkTrackerLayoutHandler *v33; // rdi
  _QWORD **v34; // rax
  __int64 v35; // rax
  hkTrackerLayoutHandler *v36; // rdi
  _QWORD **v37; // rax
  __int64 v38; // rax
  hkTrackerLayoutHandler *v39; // rdi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerLayoutCalculator::`vftable;
  this->m_layoutMap.m_map.m_elem = 0i64;
  this->m_layoutMap.m_map.m_numElems = 0;
  this->m_layoutMap.m_map.m_hashMod = -1;
  this->m_reportedType.m_map.m_elem = 0i64;
  this->m_reportedType.m_map.m_numElems = 0;
  this->m_reportedType.m_map.m_hashMod = -1;
  if ( typeCache )
    hkReferencedObject::addReference(typeCache);
  this->m_typeCache.m_pntr = typeCache;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_handlers.m_map,
    0);
  this->m_sizeMap.m_map.m_elem = 0i64;
  this->m_sizeMap.m_map.m_numElems = 0;
  this->m_sizeMap.m_map.m_hashMod = -1;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
  v6 = (hkTrackerLayoutHandler *)v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)v5 = &hkTrackerArrayLayoutHandler::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkArrayBase", v6);
  hkTrackerLayoutCalculator::addHandler(this, "hkArray", v6);
  hkTrackerLayoutCalculator::addHandler(this, "hkInplaceArray", v6);
  hkTrackerLayoutCalculator::addHandler(this, "hkSmallArray", v6);
  hkReferencedObject::removeReference(v6);
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v7[11] + 8i64))(v7[11], 16i64);
  v9 = (hkTrackerLayoutHandler *)v8;
  if ( v8 )
  {
    *(_DWORD *)(v8 + 8) = 0x1FFFF;
    *(_QWORD *)v8 = &hkTrackerRefPtrLayoutHandler::`vftable;
  }
  else
  {
    v9 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkRefPtr", v9);
  hkReferencedObject::removeReference(v9);
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 16i64);
  v12 = (hkTrackerLayoutHandler *)v11;
  if ( v11 )
  {
    *(_DWORD *)(v11 + 8) = 0x1FFFF;
    *(_QWORD *)v11 = &hkTrackerStringPtrLayoutHandler::`vftable;
  }
  else
  {
    v12 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkStringPtr", v12);
  hkReferencedObject::removeReference(v12);
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 16i64);
  v15 = (hkTrackerLayoutHandler *)v14;
  if ( v14 )
  {
    *(_DWORD *)(v14 + 8) = 0x1FFFF;
    *(_QWORD *)v14 = &hkTrackerPadSpuLayoutHandler::`vftable;
  }
  else
  {
    v15 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkPadSpu", v15);
  hkReferencedObject::removeReference(v15);
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 16i64);
  v18 = (hkTrackerLayoutHandler *)v17;
  if ( v17 )
  {
    *(_DWORD *)(v17 + 8) = 0x1FFFF;
    *(_QWORD *)v17 = &hkTrackerQueueLayoutHandler::`vftable;
  }
  else
  {
    v18 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkQueue", v18);
  hkReferencedObject::removeReference(v18);
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(v19[11], 16i64);
  v21 = (hkTrackerLayoutHandler *)v20;
  if ( v20 )
  {
    *(_DWORD *)(v20 + 8) = 0x1FFFF;
    *(_QWORD *)v20 = &hkTrackerStringMapLayoutHandler::`vftable;
  }
  else
  {
    v21 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkStringMap", v21);
  hkTrackerLayoutCalculator::addHandler(this, "hkStorageStringMap", v21);
  hkReferencedObject::removeReference(v21);
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v22[11] + 8i64))(v22[11], 16i64);
  v24 = (hkTrackerLayoutHandler *)v23;
  if ( v23 )
  {
    *(_DWORD *)(v23 + 8) = 0x1FFFF;
    *(_QWORD *)v23 = &hkTrackerPointerMapLayoutHandler::`vftable;
  }
  else
  {
    v24 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkPointerMap", v24);
  hkTrackerLayoutCalculator::addHandler(this, "hkPointerMultiMap", v24);
  hkReferencedObject::removeReference(v24);
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v25[11] + 8i64))(v25[11], 16i64);
  v27 = (hkTrackerLayoutHandler *)v26;
  if ( v26 )
  {
    *(_DWORD *)(v26 + 8) = 0x1FFFF;
    *(_QWORD *)v26 = &hkTrackerJobQueueLayoutHandler::`vftable;
  }
  else
  {
    v27 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkJobQueue", v27);
  hkReferencedObject::removeReference(v27);
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v28[11] + 8i64))(v28[11], 16i64);
  v30 = (hkTrackerLayoutHandler *)v29;
  if ( v29 )
  {
    *(_DWORD *)(v29 + 8) = 0x1FFFF;
    *(_QWORD *)v29 = &hkTrackerJobQueueDynamicDataLayoutHandler::`vftable;
  }
  else
  {
    v30 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkJobQueue::DynamicData", v30);
  hkReferencedObject::removeReference(v30);
  v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v31[11] + 8i64))(v31[11], 16i64);
  v33 = (hkTrackerLayoutHandler *)v32;
  if ( v32 )
  {
    *(_DWORD *)(v32 + 8) = 0x1FFFF;
    *(_QWORD *)v32 = &hkTrackerSetLayoutHandler::`vftable;
  }
  else
  {
    v33 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkSet", v33);
  hkReferencedObject::removeReference(v33);
  v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v34[11] + 8i64))(v34[11], 16i64);
  v36 = (hkTrackerLayoutHandler *)v35;
  if ( v35 )
  {
    *(_DWORD *)(v35 + 8) = 0x1FFFF;
    *(_QWORD *)v35 = &hkTrackerFlagsLayoutHandler::`vftable;
  }
  else
  {
    v36 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkFlags", v36);
  hkReferencedObject::removeReference(v36);
  v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v38 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v37[11] + 8i64))(v37[11], 16i64);
  v39 = (hkTrackerLayoutHandler *)v38;
  if ( v38 )
  {
    *(_DWORD *)(v38 + 8) = 0x1FFFF;
    *(_QWORD *)v38 = &hkTrackerEnumLayoutHandler::`vftable;
  }
  else
  {
    v39 = 0i64;
  }
  hkTrackerLayoutCalculator::addHandler(this, "hkEnum", v39);
  hkReferencedObject::removeReference(v39);
}

// File Line: 115
// RVA: 0x13052B0
void __fastcall hkTrackerLayoutCalculator::~hkTrackerLayoutCalculator(hkTrackerLayoutCalculator *this)
{
  hkTrackerTypeTreeCache *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerLayoutCalculator::`vftable;
  hkTrackerLayoutCalculator::clear(this);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_sizeMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_sizeMap);
  hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear((hkStorageStringMap<int,hkContainerHeapAllocator> *)&this->m_handlers);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_handlers.m_map);
  m_pntr = this->m_typeCache.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_typeCache.m_pntr = 0i64;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_reportedType.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_reportedType);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_layoutMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_layoutMap);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 120
// RVA: 0x1304D10
hkBool *__fastcall hkTrackerLayoutCalculator::isDerived(
        hkTrackerLayoutCalculator *this,
        hkBool *result,
        hkSubString *type,
        hkSubString *baseClass)
{
  hkMemoryTracker *Instance; // rsi
  hkMemoryTracker::ClassDefinition *i; // rax
  const char *m_parentTypeName; // rbx
  hkBool resulta; // [rsp+20h] [rbp-18h] BYREF

  if ( hkSubString::operator==(type, &resulta, baseClass)->m_bool )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    Instance = hkMemoryTracker::getInstance();
    for ( i = hkMemoryTracker::findClassDefinition(Instance, type);
          i;
          i = hkMemoryTracker::findClassDefinition(Instance, m_parentTypeName) )
    {
      m_parentTypeName = i->m_parentTypeName;
      if ( !m_parentTypeName )
        break;
      if ( hkSubString::operator==(baseClass, &resulta, i->m_parentTypeName)->m_bool )
      {
        result->m_bool = 1;
        return result;
      }
    }
    result->m_bool = 0;
    return result;
  }
}

// File Line: 149
// RVA: 0x1305460
hkTrackerTypeLayout *__fastcall hkTrackerLayoutCalculator::_createClassLayout(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type)
{
  hkTrackerLayoutCalculator *v3; // r13
  hkMemoryTracker *Instance; // rbp
  hkMemoryTracker::TypeDefinition *TypeDefinition; // rax
  hkMemoryTracker::ClassDefinition *v7; // rdi
  _QWORD **Value; // rax
  __int64 v9; // r12
  unsigned __int16 m_size; // cx
  char m_alignment; // al
  int v12; // ecx
  int v13; // esi
  __int64 v14; // r14
  hkMemoryTracker::Member *v15; // rbp
  __int16 v16; // r15
  hkTrackerTypeTreeNode *v17; // r13
  int v18; // ecx
  __int64 v19; // rdx
  const char *m_parentTypeName; // rdx
  hkMemoryTracker::ClassDefinition *ClassDefinition; // rax
  hkOstream stream; // [rsp+20h] [rbp-158h] BYREF
  char mem[256]; // [rsp+40h] [rbp-138h] BYREF
  int v25; // [rsp+188h] [rbp+10h]
  hkMemoryTracker *v26; // [rsp+190h] [rbp+18h]

  v3 = this;
  if ( ((type->m_type - 16) & 0xFFFFFFFD) != 0 )
    return 0i64;
  Instance = hkMemoryTracker::getInstance();
  v26 = Instance;
  TypeDefinition = hkMemoryTracker::findTypeDefinition(Instance, &type->m_name);
  v7 = (hkMemoryTracker::ClassDefinition *)TypeDefinition;
  if ( !TypeDefinition )
  {
    if ( (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                &v3->m_reportedType.m_map,
                (unsigned __int64)type) > v3->m_reportedType.m_map.m_hashMod )
    {
      hkOstream::hkOstream(&stream, mem, 256, (hkBool)1);
      hkTrackerTypeTreeNode::dumpType(type, &stream);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v3->m_reportedType.m_map,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)type,
        1ui64);
      hkOstream::~hkOstream(&stream);
    }
    return 0i64;
  }
  if ( !TypeDefinition->m_type )
    return 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
  if ( v9 )
  {
    m_size = v7->m_size;
    m_alignment = v7->m_alignment;
    *(_DWORD *)(v9 + 8) = 0x1FFFF;
    *(_QWORD *)(v9 + 16) = type;
    *(_QWORD *)v9 = &hkTrackerTypeLayout::`vftable;
    *(_DWORD *)(v9 + 36) = 0x80000000;
    *(_QWORD *)(v9 + 24) = 0i64;
    *(_DWORD *)(v9 + 32) = 0;
    *(_QWORD *)(v9 + 40) = 0i64;
    *(_DWORD *)(v9 + 48) = 0;
    *(_DWORD *)(v9 + 52) = 0x80000000;
    *(_BYTE *)(v9 + 56) = m_alignment;
    *(_DWORD *)(v9 + 58) = m_size;
  }
  else
  {
    v9 = 0i64;
  }
  if ( v7->m_type == 2 )
  {
    *(_BYTE *)(v9 + 61) = 1;
  }
  else
  {
    v12 = 0;
    *(_BYTE *)(v9 + 60) = v7->m_isVirtual != 0;
    v25 = 0;
    do
    {
      v13 = 0;
      if ( v7->m_numMembers )
      {
        v14 = 0i64;
        do
        {
          v15 = &v7->m_members[v14];
          v16 = v12 + v15->m_offset;
          v17 = hkTrackerTypeTreeParser::parseType(v15->m_typeName, v3->m_typeCache.m_pntr);
          if ( v17 )
          {
            if ( *(_DWORD *)(v9 + 32) == (*(_DWORD *)(v9 + 36) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)(v9 + 24), 32);
            v18 = 0;
            v19 = *(_QWORD *)(v9 + 24) + 32i64 * (int)(*(_DWORD *)(v9 + 32))++;
            if ( (v15->m_flags & 1) != 0 )
              v18 = 1;
            *(_QWORD *)v19 = v17;
            *(_QWORD *)(v19 + 16) = v15->m_name;
            *(_WORD *)(v19 + 8) = v16;
            *(_WORD *)(v19 + 10) = v15->m_memberSize;
            *(_DWORD *)(v19 + 24) = v18;
          }
          v12 = v25;
          v3 = this;
          ++v13;
          ++v14;
        }
        while ( v13 < v7->m_numMembers );
        Instance = v26;
      }
      m_parentTypeName = v7->m_parentTypeName;
      if ( !m_parentTypeName )
        break;
      v25 = v7->m_parentOffset + v12;
      ClassDefinition = hkMemoryTracker::findClassDefinition(Instance, m_parentTypeName);
      v12 = v25;
      v7 = ClassDefinition;
    }
    while ( ClassDefinition );
  }
  return (hkTrackerTypeLayout *)v9;
}

// File Line: 244
// RVA: 0x1304340
void __fastcall hkTrackerLayoutCalculator::clear(hkTrackerLayoutCalculator *this)
{
  Dummy *Iterator; // rdi
  hkReferencedObject *Value; // rax
  Dummy *Next; // rdi
  char *Key; // rax
  __int64 m_hashMod; // r8
  int v7; // edx
  __int64 v8; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v10; // ebx
  __int64 v11; // r9
  int v12; // r8d
  __int64 v13; // rdx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v14; // rax
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
    &result,
    Iterator);
  while ( result.m_bool )
  {
    Value = (hkReferencedObject *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
                                    Iterator);
    hkReferencedObject::removeReference(Value);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
      &result,
      Iterator);
  }
  Next = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
    &result,
    Next);
  while ( result.m_bool )
  {
    Key = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&this->m_handlers.m_map, Next);
    hkString::strFree(Key, &hkContainerHeapAllocator::s_alloc);
    Next = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
             Next);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
      &result,
      Next);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_handlers.m_map);
  m_hashMod = this->m_layoutMap.m_map.m_hashMod;
  v7 = 0;
  v8 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = this->m_layoutMap.m_map.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v8;
      ++v7;
      ++m_elem;
    }
    while ( v8 <= m_hashMod );
  }
  v10 = v7;
  if ( v7 <= this->m_layoutMap.m_map.m_hashMod )
  {
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)this->m_layoutMap.m_map.m_elem[v10].val);
      v11 = this->m_layoutMap.m_map.m_hashMod;
      v12 = v10 + 1;
      v13 = v10 + 1;
      if ( v13 <= v11 )
      {
        v14 = &this->m_layoutMap.m_map.m_elem[v12];
        do
        {
          if ( v14->key != -1i64 )
            break;
          ++v13;
          ++v12;
          ++v14;
        }
        while ( v13 <= v11 );
      }
      v10 = v12;
    }
    while ( v12 <= this->m_layoutMap.m_map.m_hashMod );
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_layoutMap.m_map);
}

// File Line: 268
// RVA: 0x1303D70
void __fastcall hkTrackerLayoutCalculator::addHandler(
        hkTrackerLayoutCalculator *this,
        char *name,
        hkTrackerLayoutHandler *handler)
{
  hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator> *p_m_handlers; // rbx
  Dummy *Key; // rdi
  hkReferencedObject *Value; // rax
  Dummy *v8; // rdi
  char *v9; // rax
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  p_m_handlers = &this->m_handlers;
  Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
          name);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_handlers,
    &result,
    Key);
  if ( result.m_bool )
  {
    Value = (hkReferencedObject *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_handlers,
                                    Key);
    hkReferencedObject::removeReference(Value);
  }
  hkReferencedObject::addReference(handler);
  v8 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_handlers,
         name);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_handlers,
    &result,
    v8);
  if ( result.m_bool )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&p_m_handlers->m_map, v8);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
      &p_m_handlers->m_map,
      v8,
      (unsigned __int64)handler);
  }
  else
  {
    v9 = hkString::strDup(name, &hkContainerHeapAllocator::s_alloc);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &p_m_handlers->m_map,
      v9,
      (unsigned __int64)handler);
  }
}

// File Line: 282
// RVA: 0x1303E50
hkTrackerLayoutHandler *__fastcall hkTrackerLayoutCalculator::getHandler(
        hkTrackerLayoutCalculator *this,
        hkSubString *name)
{
  char *v3; // rcx
  signed int v4; // ebx
  int v6; // r9d
  const char *m_start; // rdx
  hkTrackerLayoutHandler *result; // rax
  hkTrackerLayoutHandler *v9; // rbx
  char *array; // [rsp+30h] [rbp-98h] BYREF
  int v11; // [rsp+38h] [rbp-90h]
  int v12; // [rsp+3Ch] [rbp-8Ch]
  char v13[128]; // [rsp+40h] [rbp-88h] BYREF
  hkResult v14; // [rsp+D0h] [rbp+8h] BYREF

  v3 = v13;
  v4 = LODWORD(name->m_end) - LODWORD(name->m_start);
  v11 = 0;
  array = v13;
  v12 = -2147483520;
  if ( v4 + 1 > 128 )
  {
    v6 = v4 + 1;
    if ( v4 + 1 < 256 )
      v6 = 256;
    hkArrayUtil::_reserve(&v14, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v6, 1);
    v3 = array;
  }
  m_start = name->m_start;
  v11 = v4 + 1;
  hkString::memCpy(v3, m_start, v4);
  array[v4] = 0;
  result = (hkTrackerLayoutHandler *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                       (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
                                       array,
                                       0i64);
  v11 = 0;
  v9 = result;
  if ( v12 >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v12 & 0x3FFFFFFF);
    return v9;
  }
  return result;
}

// File Line: 292
// RVA: 0x1303FC0
void __fastcall hkTrackerLayoutCalculator::setLayout(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type,
        hkTrackerTypeLayout *layout)
{
  int Key; // eax

  Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                        &this->m_layoutMap.m_map,
                        (unsigned __int64)type);
  if ( Key <= this->m_layoutMap.m_map.m_hashMod )
    hkReferencedObject::removeReference((hkReferencedObject *)this->m_layoutMap.m_map.m_elem[Key].val);
  hkReferencedObject::addReference(layout);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_layoutMap.m_map,
    &hkContainerHeapAllocator::s_alloc,
    (unsigned __int64)type,
    (unsigned __int64)layout);
}

// File Line: 309
// RVA: 0x1303F50
hkTrackerTypeLayout *__fastcall hkTrackerLayoutCalculator::getLayout(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type)
{
  hkPointerMap<hkTrackerTypeTreeNode const *,hkTrackerTypeLayout const *,hkContainerHeapAllocator> *p_m_layoutMap; // rsi
  hkTrackerTypeLayout *result; // rax
  hkTrackerTypeLayout *v6; // rbx

  p_m_layoutMap = &this->m_layoutMap;
  result = (hkTrackerTypeLayout *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                    &this->m_layoutMap.m_map,
                                    (unsigned __int64)type,
                                    0i64);
  if ( !result )
  {
    result = hkTrackerLayoutCalculator::_createClassLayout(this, type);
    v6 = result;
    if ( result )
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &p_m_layoutMap->m_map,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)type,
        (unsigned __int64)result);
      return v6;
    }
  }
  return result;
}

// File Line: 323
// RVA: 0x13053E0
unsigned __int64 __fastcall hkTrackerLayoutCalculator::calcBasicSize(hkTrackerTypeTreeNode::Type type)
{
  unsigned __int64 result; // rax

  switch ( type )
  {
    case TYPE_BYTE:
    case TYPE_INT:
    case TYPE_VEC_16:
    case TYPE_NUM_BASIC_TYPES:
    case TYPE_STRUCT|TYPE_VEC_4:
      result = 8i64;
      break;
    case TYPE_VEC_4:
    case TYPE_OBJECT:
    case TYPE_CSTRING|TYPE_VEC_4:
      result = 1i64;
      break;
    case TYPE_VEC_8:
    case TYPE_STRUCT:
      result = 2i64;
      break;
    case TYPE_VEC_12:
    case TYPE_CSTRING:
    case TYPE_OBJECT|TYPE_VEC_4:
      result = 4i64;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 344
// RVA: 0x1305360
unsigned __int64 __fastcall hkTrackerLayoutCalculator::calcBasicAlignment(hkTrackerTypeTreeNode::Type type)
{
  unsigned __int64 result; // rax

  switch ( type )
  {
    case TYPE_BYTE:
    case TYPE_INT:
    case TYPE_VEC_16:
    case TYPE_NUM_BASIC_TYPES:
    case TYPE_STRUCT|TYPE_VEC_4:
      result = 8i64;
      break;
    case TYPE_VEC_4:
    case TYPE_OBJECT:
    case TYPE_CSTRING|TYPE_VEC_4:
      result = 1i64;
      break;
    case TYPE_VEC_8:
    case TYPE_STRUCT:
      result = 2i64;
      break;
    case TYPE_VEC_12:
    case TYPE_CSTRING:
    case TYPE_OBJECT|TYPE_VEC_4:
      result = 4i64;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 365
// RVA: 0x1304B50
hkResult *__fastcall hkTrackerLayoutCalculator::calcTypeInfo(
        hkTrackerLayoutCalculator *this,
        hkResult *result,
        hkTrackerTypeTreeNode *type,
        hkTrackerLayoutTypeInfo *typeInfo)
{
  hkTrackerTypeTreeNode::Type m_type; // ecx
  __int64 m_dimension; // rax
  unsigned __int64 v10; // rcx
  hkTrackerTypeLayout *Layout; // rcx
  hkMemoryTracker *Instance; // rax
  hkMemoryTracker::TypeDefinition *TypeDefinition; // rax
  unsigned __int64 v14; // rax
  hkMemoryTracker *v15; // rax
  unsigned __int64 m_size; // rcx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rbx
  int v19; // eax
  hkResult resulta; // [rsp+40h] [rbp+18h] BYREF

  m_type = type->m_type;
  switch ( type->m_type )
  {
    case TYPE_BYTE:
    case TYPE_INT:
      typeInfo->m_size = hkTrackerLayoutCalculator::calcBasicSize(m_type);
      typeInfo->m_alignment = hkTrackerLayoutCalculator::calcBasicAlignment(type->m_type);
      goto LABEL_3;
    case TYPE_REAL:
      goto $LN12_165;
    case TYPE_ARRAY:
    case TYPE_ARRAY_INT:
      Layout = (hkTrackerTypeLayout *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                        &this->m_layoutMap.m_map,
                                        (unsigned __int64)type,
                                        0i64);
      if ( Layout )
        goto LABEL_10;
      Instance = hkMemoryTracker::getInstance();
      TypeDefinition = hkMemoryTracker::findTypeDefinition(Instance, &type->m_name);
      if ( TypeDefinition && !TypeDefinition->m_type )
      {
LABEL_12:
        m_size = TypeDefinition->m_size;
        result->m_enum = HK_SUCCESS;
        typeInfo->m_size = m_size;
        typeInfo->m_alignment = (unsigned __int8)TypeDefinition->m_alignment;
      }
      else
      {
        Layout = hkTrackerLayoutCalculator::getLayout(this, type);
        if ( Layout )
        {
LABEL_10:
          v14 = Layout->m_size;
          result->m_enum = HK_SUCCESS;
          typeInfo->m_size = v14;
          typeInfo->m_alignment = (unsigned __int8)Layout->m_alignment;
        }
        else
        {
$LN12_165:
          result->m_enum = HK_FAILURE;
        }
      }
      break;
    case TYPE_ARRAY_BYTE:
      v15 = hkMemoryTracker::getInstance();
      TypeDefinition = hkMemoryTracker::findTypeDefinition(v15, &type->m_name);
      if ( TypeDefinition )
        goto LABEL_12;
      goto $LN12_165;
    case TYPE_ARRAY_REAL:
      hkTrackerLayoutCalculator::calcTypeInfo(this, &resulta, type->m_contains, typeInfo);
      if ( resulta.m_enum == HK_FAILURE )
        goto $LN12_165;
      m_dimension = type->m_dimension;
      v10 = typeInfo->m_size;
      result->m_enum = HK_SUCCESS;
      typeInfo->m_size = m_dimension * v10;
      break;
    default:
      v17 = hkTrackerLayoutCalculator::calcBasicSize(m_type);
      typeInfo->m_size = v17;
      v18 = v17;
      v19 = hkTrackerLayoutCalculator::calcBasicAlignment(type->m_type);
      typeInfo->m_alignment = v19;
      if ( !v18 || v19 <= 0 )
        goto $LN12_165;
LABEL_3:
      result->m_enum = HK_SUCCESS;
      break;
  }
  return result;
}

// File Line: 456
// RVA: 0x13040E0
void __fastcall hkTrackerLayoutCalculator::getReferencesRecursive(
        hkTrackerLayoutCalculator *this,
        hkTrackerLayoutBlock *block,
        const void **curData,
        hkTrackerTypeTreeNode *curType,
        hkArrayBase<char *> *newBlocks)
{
  const void **v6; // rbx
  hkTrackerLayoutHandler *Handler; // rax
  hkBaseObjectVtbl *vfptr; // r10
  hkTrackerTypeLayout *Layout; // rax
  int v11; // edi
  __int64 v12; // rbp
  const void *v13; // rdi
  hkArray<void const *,hkContainerHeapAllocator> *p_m_references; // rbx
  hkTrackerTypeTreeNode *m_contains; // rbp
  __int64 m_dimension; // rdi
  char **a; // [rsp+30h] [rbp-28h] BYREF
  int numtoinsert; // [rsp+38h] [rbp-20h]
  int v19; // [rsp+3Ch] [rbp-1Ch]
  hkTrackerTypeLayout *v21; // [rsp+78h] [rbp+20h]
  unsigned __int64 v22; // [rsp+78h] [rbp+20h]

  v6 = curData;
  switch ( curType->m_type )
  {
    case TYPE_BYTE:
    case TYPE_INT:
      if ( curType->m_contains->m_type != TYPE_MASK_BASIC_TYPES )
      {
        v13 = *curData;
        p_m_references = &block->m_references;
        if ( block->m_references.m_size == (block->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&block->m_references.m_data, 8);
        p_m_references->m_data[p_m_references->m_size++] = v13;
      }
      break;
    case TYPE_REAL:
    case TYPE_ARRAY:
    case TYPE_ARRAY_INT:
      Handler = hkTrackerLayoutCalculator::getHandler(this, &curType->m_name);
      if ( Handler )
      {
        vfptr = Handler->vfptr;
        v19 = 0x80000000;
        a = 0i64;
        numtoinsert = 0;
        ((void (__fastcall *)(hkTrackerLayoutHandler *, hkTrackerLayoutBlock *, const void **, hkTrackerTypeTreeNode *, hkTrackerLayoutCalculator *, char ***))vfptr[1].__first_virtual_table_function__)(
          Handler,
          block,
          v6,
          curType,
          this,
          &a);
        hkArrayBase<unsigned __int64>::_append(newBlocks, &hkContainerTempAllocator::s_alloc, a, numtoinsert);
        numtoinsert = 0;
        if ( v19 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, a, 8 * v19);
      }
      else if ( ((curType->m_type - 16) & 0xFFFFFFFD) == 0 )
      {
        Layout = hkTrackerLayoutCalculator::getLayout(this, curType);
        v21 = Layout;
        if ( Layout )
        {
          v11 = 0;
          if ( Layout->m_members.m_size > 0 )
          {
            v12 = 0i64;
            do
            {
              hkTrackerLayoutCalculator::getReferencesRecursive(
                this,
                block,
                (char *)v6 + Layout->m_members.m_data[v12].m_offset,
                Layout->m_members.m_data[v12].m_type,
                (hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *)newBlocks);
              Layout = v21;
              ++v11;
              ++v12;
            }
            while ( v11 < v21->m_members.m_size );
          }
        }
      }
      break;
    case TYPE_ARRAY_REAL:
      m_contains = curType->m_contains;
      m_dimension = (unsigned int)curType->m_dimension;
      v22 = hkTrackerLayoutCalculator::calcTypeSize(this, m_contains);
      if ( (int)m_dimension > 0 )
      {
        do
        {
          hkTrackerLayoutCalculator::getReferencesRecursive(
            this,
            block,
            v6,
            m_contains,
            (hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *)newBlocks);
          v6 = (const void **)((char *)v6 + v22);
          --m_dimension;
        }
        while ( m_dimension );
      }
      break;
    default:
      return;
  }
}

// File Line: 538
// RVA: 0x1304040
void __fastcall hkTrackerLayoutCalculator::getReferences(
        hkTrackerLayoutCalculator *this,
        hkTrackerLayoutBlock *block,
        hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  unsigned __int64 v6; // rax
  char *m_start; // rdi
  int v8; // esi
  unsigned __int64 i; // r15

  if ( block->m_arraySize <= 1 )
  {
    hkTrackerLayoutCalculator::getReferencesRecursive(this, block, block->m_start, block->m_type, newBlocks);
  }
  else
  {
    v6 = hkTrackerLayoutCalculator::calcTypeSize(this, block->m_type);
    m_start = (char *)block->m_start;
    v8 = 0;
    for ( i = v6; v8 < block->m_arraySize; m_start += i )
    {
      hkTrackerLayoutCalculator::getReferencesRecursive(this, block, m_start, block->m_type, newBlocks);
      ++v8;
    }
  }
}

// File Line: 557
// RVA: 0x1305740
__int64 __fastcall hkTrackerLayoutCalculator::_calcTypeSizeFromMember(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type)
{
  hkMemoryTracker *Instance; // rdi
  int v5; // eax
  int v6; // ebx
  int v7; // ecx
  int v8; // r15d
  __int64 v9; // r14
  __int64 v10; // rsi
  int v11; // ebx
  __int64 v12; // rdi
  __int64 v13; // rbp
  __int64 v14; // rbx
  char *array; // [rsp+30h] [rbp-38h] BYREF
  int v17; // [rsp+38h] [rbp-30h]
  int v18; // [rsp+3Ch] [rbp-2Ch]
  hkResult result; // [rsp+80h] [rbp+18h] BYREF

  Instance = hkMemoryTracker::getInstance();
  v5 = Instance->vfptr->getTypeDefinitions(Instance, 0i64);
  v18 = 0x80000000;
  v17 = 0;
  v6 = v5;
  array = 0i64;
  if ( v5 > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v5, 8);
  v17 = v6;
  ((void (__fastcall *)(hkMemoryTracker *))Instance->vfptr->getTypeDefinitions)(Instance);
  v7 = v17;
  v8 = 0;
  if ( v17 <= 0 )
  {
LABEL_12:
    v14 = 0i64;
  }
  else
  {
    v9 = 0i64;
    while ( 1 )
    {
      v10 = *(_QWORD *)&array[v9];
      if ( *(_BYTE *)(v10 + 19) == 1 )
      {
        v11 = 0;
        if ( *(_WORD *)(v10 + 40) )
          break;
      }
LABEL_11:
      ++v8;
      v9 += 8i64;
      if ( v8 >= v7 )
        goto LABEL_12;
    }
    v12 = 0i64;
    while ( 1 )
    {
      v13 = *(_QWORD *)(v10 + 24);
      if ( type == hkTrackerTypeTreeParser::parseType(*(const char **)(v13 + v12 + 8), this->m_typeCache.m_pntr) )
        break;
      ++v11;
      v12 += 32i64;
      if ( v11 >= *(unsigned __int16 *)(v10 + 40) )
      {
        v7 = v17;
        goto LABEL_11;
      }
    }
    v14 = *(unsigned __int16 *)(v13 + v12 + 2);
  }
  v17 = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v18);
  return v14;
}

// File Line: 591
// RVA: 0x1304600
void __fastcall hkTrackerLayoutCalculator::setTypeSize(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type,
        unsigned __int64 size)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &this->m_sizeMap.m_map,
    &hkContainerHeapAllocator::s_alloc,
    (unsigned __int64)type,
    size);
}

// File Line: 596
// RVA: 0x13044D0
unsigned __int64 __fastcall hkTrackerLayoutCalculator::calcTypeSize(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type)
{
  unsigned __int64 v4; // rax
  hkPointerMap<hkTrackerTypeTreeNode const *,unsigned __int64,hkContainerHeapAllocator> *p_m_sizeMap; // rsi
  hkTrackerLayoutHandler *Handler; // rax
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbx
  hkTrackerLayoutTypeInfo typeInfo; // [rsp+20h] [rbp-18h] BYREF
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v4 = hkTrackerLayoutCalculator::calcBasicSize(type->m_type);
  if ( !v4 )
  {
    p_m_sizeMap = &this->m_sizeMap;
    v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           &this->m_sizeMap.m_map,
           (unsigned __int64)type,
           0i64);
    if ( !v4 )
    {
      if ( type->m_type != TYPE_REAL && type->m_type != TYPE_ARRAY && type->m_type != TYPE_ARRAY_INT )
      {
        if ( type->m_type == TYPE_ARRAY_REAL )
          return type->m_dimension * hkTrackerLayoutCalculator::calcTypeSize(this, type->m_contains);
        return 0i64;
      }
      Handler = hkTrackerLayoutCalculator::getHandler(this, &type->m_name);
      if ( Handler )
      {
        v7 = ((__int64 (__fastcall *)(hkTrackerLayoutHandler *, hkTrackerTypeTreeNode *, hkTrackerLayoutCalculator *))Handler->vfptr[2].__vecDelDtor)(
               Handler,
               type,
               this);
        v8 = v7;
      }
      else
      {
        hkTrackerLayoutCalculator::calcTypeInfo(this, &result, type, &typeInfo);
        if ( result.m_enum == HK_SUCCESS )
          return typeInfo.m_size;
        v7 = hkTrackerLayoutCalculator::_calcTypeSizeFromMember(this, type);
        v8 = v7;
        if ( !v7 )
          return 0i64;
      }
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &p_m_sizeMap->m_map,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)type,
        v7);
      return v8;
    }
  }
  return v4;
}

// File Line: 656
// RVA: 0x1304620
void __fastcall hkTrackerLayoutCalculator::calcMembers(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type,
        unsigned __int64 size,
        hkArray<hkTrackerTypeLayout::Member,hkContainerHeapAllocator> *membersOut,
        int baseIndex,
        int flags)
{
  hkTrackerTypeLayout::Member *v9; // rcx
  hkTrackerTypeLayout *Layout; // rax
  hkTrackerTypeLayout *v11; // rbp
  int v12; // edi
  __int64 v13; // rcx
  hkTrackerTypeLayout::Member *v14; // rcx
  unsigned __int64 v15; // rsi
  int v16; // edi
  __int64 v17; // rbp
  hkTrackerTypeTreeNode *typea; // [rsp+30h] [rbp-28h]
  __int64 v20; // [rsp+68h] [rbp+10h]
  int m_dimension; // [rsp+68h] [rbp+10h]
  unsigned __int16 v22; // [rsp+70h] [rbp+18h]

  v22 = size;
  if ( type )
  {
    switch ( type->m_type )
    {
      case TYPE_BYTE:
      case TYPE_INT:
        if ( membersOut->m_size == (membersOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&membersOut->m_data, 32);
        v14 = &membersOut->m_data[membersOut->m_size++];
        v14->m_name = 0i64;
        v14->m_offset = baseIndex;
        v14->m_type = type;
        v14->m_size = 8;
        v14->m_flags = flags;
        break;
      case TYPE_REAL:
      case TYPE_ARRAY:
      case TYPE_ARRAY_INT:
        Layout = hkTrackerLayoutCalculator::getLayout(this, type);
        v11 = Layout;
        if ( Layout )
        {
          v12 = 0;
          if ( Layout->m_members.m_size > 0 )
          {
            v13 = 0i64;
            v20 = 0i64;
            do
            {
              hkTrackerLayoutCalculator::calcMembers(
                this,
                *(hkTrackerTypeTreeNode **)((char *)&v11->m_members.m_data->m_type + v13),
                *(unsigned __int16 *)((char *)&v11->m_members.m_data->m_size + v13),
                membersOut,
                baseIndex + *(unsigned __int16 *)((char *)&v11->m_members.m_data->m_offset + v13),
                flags | *(int *)((char *)&v11->m_members.m_data->m_flags + v13));
              ++v12;
              v13 = v20 + 32;
              v20 += 32i64;
            }
            while ( v12 < v11->m_members.m_size );
          }
        }
        break;
      case TYPE_ARRAY_REAL:
        m_dimension = type->m_dimension;
        typea = type->m_contains;
        v15 = hkTrackerLayoutCalculator::calcTypeSize(this, typea);
        if ( v15 >= 8 )
        {
          v16 = baseIndex;
          if ( m_dimension > 0 )
          {
            v17 = (unsigned int)m_dimension;
            do
            {
              hkTrackerLayoutCalculator::calcMembers(this, typea, v15, membersOut, v16, flags);
              v16 += v15;
              --v17;
            }
            while ( v17 );
          }
        }
        break;
      default:
        return;
    }
  }
  else
  {
    if ( membersOut->m_size == (membersOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&membersOut->m_data, 32);
    v9 = &membersOut->m_data[membersOut->m_size++];
    v9->m_name = 0i64;
    v9->m_offset = baseIndex;
    v9->m_type = 0i64;
    v9->m_size = v22;
    v9->m_flags = flags;
  }
}

// File Line: 728
// RVA: 0x1305AD0
void __fastcall concatMemberName(const char *name, unsigned int memberIndex, hkStringBuf *buf)
{
  const char *i; // rdx

  if ( buf->m_string.m_size - 1 > 0 )
    hkStringBuf::append(buf, ".", -1);
  if ( name )
  {
    for ( i = &name[(int)hkString::strLen(name) - 1]; i >= name; --i )
    {
      if ( *i == 58 )
        break;
    }
    hkStringBuf::append(buf, i + 1, -1);
  }
  else
  {
    hkStringBuf::appendPrintf(buf, "_unknown%i", memberIndex);
  }
}

// File Line: 751
// RVA: 0x1305B80
void __fastcall addName(
        hkStringBuf *baseName,
        hkArray<char,hkContainerHeapAllocator> *buffer,
        hkArray<int,hkContainerHeapAllocator> *namesOffset)
{
  int m_size; // ebp
  int v7; // edi
  __int64 v8; // r14
  int v9; // r9d
  int v10; // eax
  int v11; // eax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = buffer->m_size;
  if ( namesOffset->m_size == (namesOffset->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&namesOffset->m_data, 4);
  namesOffset->m_data[namesOffset->m_size++] = m_size;
  v7 = baseName->m_string.m_size;
  v8 = buffer->m_size;
  v9 = v8 + v7;
  v10 = buffer->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 >= (int)v8 + v7 )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&buffer->m_data, v9, 1);
  }
  buffer->m_size += v7;
  hkString::memCpy(&buffer->m_data[v8], baseName->m_string.m_data, baseName->m_string.m_size - 1);
  buffer->m_data[buffer->m_size - 1] = 0;
}

// File Line: 762
// RVA: 0x13058C0
void __fastcall hkTrackerLayoutCalculator::_calcMemberNames(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type,
        hkStringBuf *baseName,
        hkArray<char,hkContainerHeapAllocator> *buffer,
        hkArray<int,hkContainerHeapAllocator> *namesOffset)
{
  hkTrackerTypeLayout *Layout; // rax
  int v8; // ebp
  __int64 v9; // rcx
  int m_size; // esi
  const char **v11; // rdi
  int m_dimension; // edi
  int v13; // ebp
  int v14; // edi
  hkTrackerTypeTreeNode *typea; // [rsp+30h] [rbp-28h]
  hkTrackerTypeTreeNode *typeb; // [rsp+30h] [rbp-28h]
  __int64 v18; // [rsp+68h] [rbp+10h]
  int v19; // [rsp+68h] [rbp+10h]

  if ( type )
  {
    switch ( type->m_type )
    {
      case TYPE_BYTE:
      case TYPE_INT:
        goto LABEL_2;
      case TYPE_REAL:
      case TYPE_ARRAY:
      case TYPE_ARRAY_INT:
        Layout = hkTrackerLayoutCalculator::getLayout(this, type);
        typea = (hkTrackerTypeTreeNode *)Layout;
        if ( Layout )
        {
          v8 = 0;
          if ( Layout->m_members.m_size > 0 )
          {
            v9 = 0i64;
            v18 = 0i64;
            do
            {
              m_size = baseName->m_string.m_size;
              v11 = (const char **)((char *)Layout->m_members.m_data + v9);
              concatMemberName(v11[2], v8, baseName);
              hkTrackerLayoutCalculator::_calcMemberNames(
                this,
                (hkTrackerTypeTreeNode *)*v11,
                baseName,
                buffer,
                namesOffset);
              hkStringBuf::chompEnd(baseName, baseName->m_string.m_size - m_size);
              Layout = (hkTrackerTypeLayout *)typea;
              v9 = v18 + 32;
              ++v8;
              v18 += 32i64;
            }
            while ( v8 < SLODWORD(typea->m_contains) );
          }
        }
        break;
      case TYPE_ARRAY_REAL:
        m_dimension = type->m_dimension;
        v19 = m_dimension;
        typeb = type->m_contains;
        if ( hkTrackerLayoutCalculator::calcTypeSize(this, typeb) >= 8 )
        {
          v13 = 0;
          if ( m_dimension > 0 )
          {
            do
            {
              v14 = baseName->m_string.m_size;
              hkStringBuf::append(baseName, "[", -1);
              hkStringBuf::appendPrintf(baseName, "%i", (unsigned int)v13);
              hkStringBuf::append(baseName, "]", -1);
              hkTrackerLayoutCalculator::_calcMemberNames(this, typeb, baseName, buffer, namesOffset);
              hkStringBuf::chompEnd(baseName, baseName->m_string.m_size - v14);
              ++v13;
            }
            while ( v13 < v19 );
          }
        }
        break;
      default:
        return;
    }
  }
  else
  {
LABEL_2:
    addName(baseName, buffer, namesOffset);
  }
}

// File Line: 832
// RVA: 0x1304870
void __fastcall hkTrackerLayoutCalculator::calcMemberNames(
        hkTrackerLayoutCalculator *this,
        hkTrackerTypeTreeNode *type,
        hkArray<char,hkContainerHeapAllocator> *buffer,
        hkArray<int,hkContainerHeapAllocator> *namesOffset)
{
  hkStringBuf baseName; // [rsp+30h] [rbp-98h] BYREF

  baseName.m_string.m_capacityAndFlags = -2147483520;
  baseName.m_string.m_size = 1;
  baseName.m_string.m_data = baseName.m_string.m_storage;
  baseName.m_string.m_storage[0] = 0;
  hkTrackerLayoutCalculator::_calcMemberNames(this, type, &baseName, buffer, namesOffset);
  baseName.m_string.m_size = 0;
  if ( baseName.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      baseName.m_string.m_data,
      baseName.m_string.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 839
// RVA: 0x13048F0
void __fastcall hkTrackerLayoutCalculator::flattenTypes(hkTrackerLayoutCalculator *this)
{
  __int64 m_hashMod; // rcx
  int v3; // r8d
  __int64 v4; // rdx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v6; // r14d
  unsigned __int64 val; // rdi
  _QWORD **Value; // rax
  __int64 v9; // rax
  unsigned __int64 v10; // rbx
  unsigned __int16 v11; // r8
  char v12; // dl
  __int64 v13; // rcx
  int v14; // r10d
  __int64 v15; // r8
  __int64 v16; // r9
  __int64 v17; // r8
  int v18; // edx
  __int64 v19; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v20; // rax
  hkArray<int,hkContainerHeapAllocator> namesOffset; // [rsp+30h] [rbp-B8h] BYREF
  char v22; // [rsp+40h] [rbp-A8h] BYREF

  m_hashMod = this->m_layoutMap.m_map.m_hashMod;
  v3 = 0;
  v4 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = this->m_layoutMap.m_map.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v4;
      ++v3;
      ++m_elem;
    }
    while ( v4 <= m_hashMod );
  }
  v6 = v3;
  if ( v3 <= this->m_layoutMap.m_map.m_hashMod )
  {
    do
    {
      val = this->m_layoutMap.m_map.m_elem[v6].val;
      if ( !*(_BYTE *)(val + 61) )
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v9 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
        v10 = v9;
        if ( v9 )
        {
          v11 = *(_WORD *)(val + 58);
          v12 = *(_BYTE *)(val + 56);
          v13 = *(_QWORD *)(val + 16);
          *(_DWORD *)(v9 + 8) = 0x1FFFF;
          *(_QWORD *)(v9 + 16) = v13;
          *(_QWORD *)v9 = &hkTrackerTypeLayout::`vftable;
          *(_QWORD *)(v9 + 24) = 0i64;
          *(_DWORD *)(v9 + 32) = 0;
          *(_DWORD *)(v9 + 36) = 0x80000000;
          *(_QWORD *)(v9 + 40) = 0i64;
          *(_DWORD *)(v9 + 48) = 0;
          *(_DWORD *)(v9 + 52) = 0x80000000;
          *(_BYTE *)(v9 + 56) = v12;
          *(_DWORD *)(v9 + 58) = v11;
        }
        else
        {
          v10 = 0i64;
        }
        *(_BYTE *)(v10 + 60) = *(_BYTE *)(val + 60);
        hkTrackerLayoutCalculator::calcMembers(
          this,
          *(hkTrackerTypeTreeNode **)(val + 16),
          *(unsigned __int16 *)(val + 58),
          (hkArray<hkTrackerTypeLayout::Member,hkContainerHeapAllocator> *)(v10 + 24),
          0,
          0);
        namesOffset.m_size = 0;
        namesOffset.m_capacityAndFlags = -2147483616;
        namesOffset.m_data = (int *)&v22;
        hkTrackerLayoutCalculator::calcMemberNames(
          this,
          *(hkTrackerTypeTreeNode **)(val + 16),
          (hkArray<char,hkContainerHeapAllocator> *)(v10 + 40),
          &namesOffset);
        v14 = 0;
        if ( namesOffset.m_size > 0 )
        {
          v15 = 0i64;
          v16 = 0i64;
          do
          {
            ++v14;
            ++v16;
            v15 += 32i64;
            *(_QWORD *)(v15 + *(_QWORD *)(v10 + 24) - 16) = *(_QWORD *)(v10 + 40) + namesOffset.m_data[v16 - 1];
          }
          while ( v14 < namesOffset.m_size );
        }
        hkReferencedObject::removeReference((hkReferencedObject *)val);
        this->m_layoutMap.m_map.m_elem[v6].val = v10;
        namesOffset.m_size = 0;
        if ( namesOffset.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            namesOffset.m_data,
            4 * namesOffset.m_capacityAndFlags);
      }
      v17 = this->m_layoutMap.m_map.m_hashMod;
      v18 = v6 + 1;
      v19 = v6 + 1;
      if ( v19 <= v17 )
      {
        v20 = &this->m_layoutMap.m_map.m_elem[v18];
        do
        {
          if ( v20->key != -1i64 )
            break;
          ++v19;
          ++v18;
          ++v20;
        }
        while ( v19 <= v17 );
      }
      v6 = v18;
    }
    while ( v18 <= this->m_layoutMap.m_map.m_hashMod );
  }
} }
        while ( v19 <= v17 );
      }
      v6 = v18;
    }
    while ( v18 <= this->m_layoutMa

