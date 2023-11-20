// File Line: 29
// RVA: 0x1304DD0
void __fastcall hkTrackerLayoutCalculator::hkTrackerLayoutCalculator(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeCache *typeCache)
{
  hkTrackerTypeTreeCache *v2; // rdi
  hkTrackerLayoutCalculator *v3; // rbx
  _QWORD **v4; // rax
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
  v2 = typeCache;
  v3 = this;
  this->m_reportedType.m_map.m_elem = 0i64;
  this->m_reportedType.m_map.m_numElems = 0;
  this->m_reportedType.m_map.m_hashMod = -1;
  if ( typeCache )
    hkReferencedObject::addReference((hkReferencedObject *)&typeCache->vfptr);
  v3->m_typeCache.m_pntr = v2;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v3->m_handlers.m_map,
    0);
  v3->m_sizeMap.m_map.m_elem = 0i64;
  v3->m_sizeMap.m_map.m_numElems = 0;
  v3->m_sizeMap.m_map.m_hashMod = -1;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkArrayBase", v6);
  hkTrackerLayoutCalculator::addHandler(v3, "hkArray", v6);
  hkTrackerLayoutCalculator::addHandler(v3, "hkInplaceArray", v6);
  hkTrackerLayoutCalculator::addHandler(v3, "hkSmallArray", v6);
  hkReferencedObject::removeReference((hkReferencedObject *)&v6->vfptr);
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkRefPtr", v9);
  hkReferencedObject::removeReference((hkReferencedObject *)&v9->vfptr);
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkStringPtr", v12);
  hkReferencedObject::removeReference((hkReferencedObject *)&v12->vfptr);
  v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkPadSpu", v15);
  hkReferencedObject::removeReference((hkReferencedObject *)&v15->vfptr);
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkQueue", v18);
  hkReferencedObject::removeReference((hkReferencedObject *)&v18->vfptr);
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkStringMap", v21);
  hkTrackerLayoutCalculator::addHandler(v3, "hkStorageStringMap", v21);
  hkReferencedObject::removeReference((hkReferencedObject *)&v21->vfptr);
  v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(v22[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkPointerMap", v24);
  hkTrackerLayoutCalculator::addHandler(v3, "hkPointerMultiMap", v24);
  hkReferencedObject::removeReference((hkReferencedObject *)&v24->vfptr);
  v25 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v26 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v25[11] + 8i64))(v25[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkJobQueue", v27);
  hkReferencedObject::removeReference((hkReferencedObject *)&v27->vfptr);
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(v28[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkJobQueue::DynamicData", v30);
  hkReferencedObject::removeReference((hkReferencedObject *)&v30->vfptr);
  v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v32 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v31[11] + 8i64))(v31[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkSet", v33);
  hkReferencedObject::removeReference((hkReferencedObject *)&v33->vfptr);
  v34 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v34[11] + 8i64))(v34[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkFlags", v36);
  hkReferencedObject::removeReference((hkReferencedObject *)&v36->vfptr);
  v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v38 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v37[11] + 8i64))(v37[11], 16i64);
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
  hkTrackerLayoutCalculator::addHandler(v3, "hkEnum", v39);
  hkReferencedObject::removeReference((hkReferencedObject *)&v39->vfptr);
}

// File Line: 115
// RVA: 0x13052B0
void __fastcall hkTrackerLayoutCalculator::~hkTrackerLayoutCalculator(hkTrackerLayoutCalculator *this)
{
  hkTrackerLayoutCalculator *v1; // rdi
  hkReferencedObject *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkTrackerLayoutCalculator::`vftable;
  hkTrackerLayoutCalculator::clear(this);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_sizeMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_sizeMap);
  hkStorageStringMap<hkTrackerLayoutHandler *,hkContainerHeapAllocator>::clear((hkStorageStringMap<int,hkContainerHeapAllocator> *)&v1->m_handlers);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_handlers.m_map);
  v2 = (hkReferencedObject *)&v1->m_typeCache.m_pntr->vfptr;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v1->m_typeCache.m_pntr = 0i64;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_reportedType.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_reportedType);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_layoutMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_layoutMap);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 120
// RVA: 0x1304D10
hkBool *__fastcall hkTrackerLayoutCalculator::isDerived(hkTrackerLayoutCalculator *this, hkBool *result, hkSubString *type, hkSubString *baseClass)
{
  hkSubString *v4; // rbx
  hkBool *v5; // rdi
  hkSubString *v6; // rbp
  hkBool *v7; // rax
  hkMemoryTracker *v8; // rax
  hkMemoryTracker *v9; // rsi
  hkMemoryTracker::ClassDefinition *i; // rax
  const char *v11; // rbx
  hkBool resulta; // [rsp+20h] [rbp-18h]

  v4 = type;
  v5 = result;
  v6 = baseClass;
  if ( hkSubString::operator==(type, &resulta, baseClass)->m_bool )
  {
    v5->m_bool = 1;
    v7 = v5;
  }
  else
  {
    v8 = hkMemoryTracker::getInstance();
    v9 = v8;
    for ( i = hkMemoryTracker::findClassDefinition(v8, v4); i; i = hkMemoryTracker::findClassDefinition(v9, v11) )
    {
      v11 = i->m_parentTypeName;
      if ( !v11 )
        break;
      if ( hkSubString::operator==(v6, &resulta, i->m_parentTypeName)->m_bool )
      {
        v5->m_bool = 1;
        goto LABEL_8;
      }
    }
    v5->m_bool = 0;
LABEL_8:
    v7 = v5;
  }
  return v7;
}

// File Line: 149
// RVA: 0x1305460
hkTrackerTypeLayout *__fastcall hkTrackerLayoutCalculator::_createClassLayout(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type)
{
  hkTrackerTypeTreeNode *v2; // rbx
  hkTrackerLayoutCalculator *v3; // r13
  hkMemoryTracker *v5; // rax
  hkMemoryTracker *v6; // rbp
  hkMemoryTracker::TypeDefinition *v7; // rax
  hkMemoryTracker::ClassDefinition *v8; // rdi
  _QWORD **v9; // rax
  __int64 v10; // r12
  unsigned __int16 v11; // cx
  char v12; // al
  int v13; // ecx
  signed int v14; // esi
  __int64 v15; // r14
  hkMemoryTracker::Member *v16; // rbp
  __int16 v17; // r15
  hkTrackerTypeTreeNode *v18; // r13
  signed int v19; // ecx
  signed __int64 v20; // rdx
  const char *v21; // rdx
  hkMemoryTracker::ClassDefinition *v22; // rax
  hkOstream stream; // [rsp+20h] [rbp-158h]
  char mem; // [rsp+40h] [rbp-138h]
  hkTrackerLayoutCalculator *v25; // [rsp+180h] [rbp+8h]
  int v26; // [rsp+188h] [rbp+10h]
  hkMemoryTracker *v27; // [rsp+190h] [rbp+18h]

  v25 = this;
  v2 = type;
  v3 = this;
  if ( (type->m_type - 16) & 0xFFFFFFFD )
    return 0i64;
  v5 = hkMemoryTracker::getInstance();
  v6 = v5;
  v27 = v5;
  v7 = hkMemoryTracker::findTypeDefinition(v5, &v2->m_name);
  v8 = (hkMemoryTracker::ClassDefinition *)v7;
  if ( !v7 )
  {
    if ( (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                       (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_reportedType.m_map.m_elem,
                       (unsigned __int64)v2) > v3->m_reportedType.m_map.m_hashMod )
    {
      hkOstream::hkOstream(&stream, &mem, 256, (hkBool)1);
      hkTrackerTypeTreeNode::dumpType(v2, &stream);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_reportedType.m_map.m_elem,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v2,
        (unsigned int)((_DWORD)v8 + 1));
      hkOstream::~hkOstream(&stream);
    }
    return 0i64;
  }
  if ( !v7->m_type )
    return 0i64;
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 64i64);
  if ( v10 )
  {
    v11 = v8->m_size;
    v12 = v8->m_alignment;
    *(_DWORD *)(v10 + 8) = 0x1FFFF;
    *(_QWORD *)(v10 + 16) = v2;
    *(_QWORD *)v10 = &hkTrackerTypeLayout::`vftable;
    *(_DWORD *)(v10 + 36) = 2147483648;
    *(_QWORD *)(v10 + 24) = 0i64;
    *(_DWORD *)(v10 + 32) = 0;
    *(_QWORD *)(v10 + 40) = 0i64;
    *(_DWORD *)(v10 + 48) = 0;
    *(_DWORD *)(v10 + 52) = 2147483648;
    *(_BYTE *)(v10 + 56) = v12;
    *(_DWORD *)(v10 + 58) = v11;
  }
  else
  {
    v10 = 0i64;
  }
  if ( v8->m_type == 2 )
  {
    *(_BYTE *)(v10 + 61) = 1;
  }
  else
  {
    v13 = 0;
    *(_BYTE *)(v10 + 60) = v8->m_isVirtual != 0;
    v26 = 0;
    do
    {
      v14 = 0;
      if ( v8->m_numMembers > 0u )
      {
        v15 = 0i64;
        do
        {
          v16 = &v8->m_members[v15];
          v17 = v13 + v16->m_offset;
          v18 = hkTrackerTypeTreeParser::parseType(v16->m_typeName, v3->m_typeCache.m_pntr);
          if ( v18 )
          {
            if ( *(_DWORD *)(v10 + 32) == (*(_DWORD *)(v10 + 36) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                (void *)(v10 + 24),
                32);
            v19 = 0;
            v20 = *(_QWORD *)(v10 + 24) + 32i64 * (signed int)(*(_DWORD *)(v10 + 32))++;
            if ( v16->m_flags & 1 )
              v19 = 1;
            *(_QWORD *)v20 = v18;
            *(_QWORD *)(v20 + 16) = v16->m_name;
            *(_WORD *)(v20 + 8) = v17;
            *(_WORD *)(v20 + 10) = v16->m_memberSize;
            *(_DWORD *)(v20 + 24) = v19;
          }
          v13 = v26;
          v3 = v25;
          ++v14;
          ++v15;
        }
        while ( v14 < v8->m_numMembers );
        v6 = v27;
      }
      v21 = v8->m_parentTypeName;
      if ( !v21 )
        break;
      v26 = v8->m_parentOffset + v13;
      v22 = hkMemoryTracker::findClassDefinition(v6, v21);
      v13 = v26;
      v8 = v22;
    }
    while ( v22 );
  }
  return (hkTrackerTypeLayout *)v10;
}

// File Line: 244
// RVA: 0x1304340
void __fastcall hkTrackerLayoutCalculator::clear(hkTrackerLayoutCalculator *this)
{
  hkTrackerLayoutCalculator *v1; // rsi
  Dummy *v2; // rdi
  hkReferencedObject *v3; // rax
  Dummy *v4; // rdi
  char *v5; // rax
  __int64 v6; // r8
  int v7; // edx
  __int64 v8; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v9; // rax
  int v10; // ebx
  __int64 v11; // r9
  int v12; // er8
  __int64 v13; // rdx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v14; // rax
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_handlers,
    &result,
    v2);
  while ( result.m_bool )
  {
    v3 = (hkReferencedObject *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_handlers,
                                 v2);
    hkReferencedObject::removeReference(v3);
    v2 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_handlers,
           v2);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_handlers,
      &result,
      v2);
  }
  v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_handlers);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_handlers,
    &result,
    v4);
  while ( result.m_bool )
  {
    v5 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&v1->m_handlers.m_map, v4);
    hkString::strFree(v5, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_handlers,
           v4);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_handlers,
      &result,
      v4);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&v1->m_handlers.m_map);
  v6 = v1->m_layoutMap.m_map.m_hashMod;
  v7 = 0;
  v8 = 0i64;
  if ( v6 >= 0 )
  {
    v9 = v1->m_layoutMap.m_map.m_elem;
    do
    {
      if ( v9->key != -1i64 )
        break;
      ++v8;
      ++v7;
      ++v9;
    }
    while ( v8 <= v6 );
  }
  v10 = v7;
  if ( v7 <= v1->m_layoutMap.m_map.m_hashMod )
  {
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)v1->m_layoutMap.m_map.m_elem[v10].val);
      v11 = v1->m_layoutMap.m_map.m_hashMod;
      v12 = v10 + 1;
      v13 = v10 + 1;
      if ( v13 <= v11 )
      {
        v14 = &v1->m_layoutMap.m_map.m_elem[v12];
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
    while ( v12 <= v1->m_layoutMap.m_map.m_hashMod );
  }
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_layoutMap.m_map.m_elem);
}

// File Line: 268
// RVA: 0x1303D70
void __fastcall hkTrackerLayoutCalculator::addHandler(hkTrackerLayoutCalculator *this, const char *name, hkTrackerLayoutHandler *handler)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v3; // rbx
  hkTrackerLayoutHandler *v4; // rsi
  const char *v5; // rbp
  Dummy *v6; // rdi
  hkReferencedObject *v7; // rax
  Dummy *v8; // rdi
  char *v9; // rax
  hkBool result; // [rsp+30h] [rbp+8h]

  v3 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers;
  v4 = handler;
  v5 = name;
  v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_handlers,
         (unsigned __int64)name);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v3, &result, v6);
  if ( result.m_bool )
  {
    v7 = (hkReferencedObject *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(v3, v6);
    hkReferencedObject::removeReference(v7);
  }
  hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v8 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(v3, (unsigned __int64)v5);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v3, &result, v8);
  if ( result.m_bool )
  {
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v3,
      v8);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::setValue(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v3,
      v8,
      (unsigned __int64)v4);
  }
  else
  {
    v9 = hkString::strDup(v5, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)v3,
      (unsigned __int64)v9,
      (unsigned __int64)v4);
  }
}

// File Line: 282
// RVA: 0x1303E50
hkTrackerLayoutHandler *__fastcall hkTrackerLayoutCalculator::getHandler(hkTrackerLayoutCalculator *this, hkSubString *name)
{
  hkTrackerLayoutCalculator *v2; // rbp
  char *v3; // rcx
  int v4; // ebx
  hkSubString *v5; // rsi
  int v6; // er9
  const char *v7; // rdx
  hkTrackerLayoutHandler *result; // rax
  hkTrackerLayoutHandler *v9; // rbx
  char *array; // [rsp+30h] [rbp-98h]
  int v11; // [rsp+38h] [rbp-90h]
  int v12; // [rsp+3Ch] [rbp-8Ch]
  char v13; // [rsp+40h] [rbp-88h]
  __int64 v14; // [rsp+D0h] [rbp+8h]

  v2 = this;
  v3 = &v13;
  v4 = LODWORD(name->m_end) - LODWORD(name->m_start);
  v5 = name;
  v11 = 0;
  array = &v13;
  v12 = -2147483520;
  if ( v4 + 1 > 128 )
  {
    v6 = v4 + 1;
    if ( v4 + 1 < 256 )
      v6 = 256;
    hkArrayUtil::_reserve(
      (hkResult *)&v14,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v6,
      1);
    v3 = array;
  }
  v7 = v5->m_start;
  v11 = v4 + 1;
  hkString::memCpy(v3, v7, v4);
  array[v4] = 0;
  result = (hkTrackerLayoutHandler *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                       (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_handlers,
                                       (unsigned __int64)array,
                                       0i64);
  v11 = 0;
  v9 = result;
  if ( v12 >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v12 & 0x3FFFFFFF);
    result = v9;
  }
  return result;
}

// File Line: 292
// RVA: 0x1303FC0
void __fastcall hkTrackerLayoutCalculator::setLayout(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type, hkTrackerTypeLayout *layout)
{
  hkTrackerLayoutCalculator *v3; // rbx
  hkTrackerTypeLayout *v4; // rsi
  hkTrackerTypeTreeNode *v5; // rbp
  int v6; // eax

  v3 = this;
  v4 = layout;
  v5 = type;
  v6 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_layoutMap.m_map.m_elem,
                           (unsigned __int64)type);
  if ( v6 <= v3->m_layoutMap.m_map.m_hashMod )
    hkReferencedObject::removeReference((hkReferencedObject *)v3->m_layoutMap.m_map.m_elem[v6].val);
  hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_layoutMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)v5,
    (unsigned __int64)v4);
}

// File Line: 309
// RVA: 0x1303F50
hkTrackerTypeLayout *__fastcall hkTrackerLayoutCalculator::getLayout(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v2; // rsi
  hkTrackerLayoutCalculator *v3; // rbx
  hkTrackerTypeTreeNode *v4; // rdi
  hkTrackerTypeLayout *result; // rax
  hkTrackerTypeLayout *v6; // rbx

  v2 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_layoutMap.m_map.m_elem;
  v3 = this;
  v4 = type;
  result = (hkTrackerTypeLayout *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_layoutMap.m_map.m_elem,
                                    (unsigned __int64)type,
                                    0i64);
  if ( !result )
  {
    result = hkTrackerLayoutCalculator::_createClassLayout(v3, v4);
    v6 = result;
    if ( result )
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        v2,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v4,
        (unsigned __int64)result);
      result = v6;
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
    case 1:
    case 2:
    case 7:
    case 11:
    case 13:
      result = 8i64;
      break;
    case 4:
    case 8:
    case 14:
      result = 1i64;
      break;
    case 5:
    case 9:
      result = 2i64;
      break;
    case 6:
    case 10:
    case 12:
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
    case 1:
    case 2:
    case 7:
    case 11:
    case 13:
      result = 8i64;
      break;
    case 4:
    case 8:
    case 14:
      result = 1i64;
      break;
    case 5:
    case 9:
      result = 2i64;
      break;
    case 6:
    case 10:
    case 12:
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
hkResult *__fastcall hkTrackerLayoutCalculator::calcTypeInfo(hkTrackerLayoutCalculator *this, hkResult *result, hkTrackerTypeTreeNode *type, hkTrackerLayoutTypeInfo *typeInfo)
{
  hkTrackerLayoutCalculator *v4; // rbx
  hkTrackerTypeTreeNode::Type v5; // ecx
  hkTrackerLayoutTypeInfo *v6; // rsi
  hkTrackerTypeTreeNode *v7; // rbp
  hkResult *v8; // rdi
  __int64 v9; // rax
  unsigned __int64 v10; // rcx
  hkTrackerTypeLayout *v11; // rcx
  hkMemoryTracker *v12; // rax
  hkMemoryTracker::TypeDefinition *v13; // rax
  unsigned __int64 v14; // rax
  hkMemoryTracker *v15; // rax
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rbx
  int v19; // eax
  hkResult resulta; // [rsp+40h] [rbp+18h]

  v4 = this;
  v5 = type->m_type;
  v6 = typeInfo;
  v7 = type;
  v8 = result;
  switch ( type->m_type )
  {
    case 1:
    case 2:
      typeInfo->m_size = hkTrackerLayoutCalculator::calcBasicSize(v5);
      v6->m_alignment = hkTrackerLayoutCalculator::calcBasicAlignment(v7->m_type);
      goto LABEL_3;
    case 3:
      goto $LN12_165;
    case 0x10:
    case 0x12:
      v11 = (hkTrackerTypeLayout *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_layoutMap.m_map.m_elem,
                                     (unsigned __int64)type,
                                     0i64);
      if ( v11 )
        goto LABEL_10;
      v12 = hkMemoryTracker::getInstance();
      v13 = hkMemoryTracker::findTypeDefinition(v12, &v7->m_name);
      if ( v13 && !v13->m_type )
        goto LABEL_12;
      v11 = hkTrackerLayoutCalculator::getLayout(v4, v7);
      if ( !v11 )
        goto $LN12_165;
LABEL_10:
      v14 = v11->m_size;
      v8->m_enum = 0;
      v6->m_size = v14;
      v6->m_alignment = (unsigned __int8)v11->m_alignment;
      return v8;
    case 0x11:
      v15 = hkMemoryTracker::getInstance();
      v13 = hkMemoryTracker::findTypeDefinition(v15, &v7->m_name);
      if ( !v13 )
        goto $LN12_165;
LABEL_12:
      v16 = v13->m_size;
      v8->m_enum = 0;
      v6->m_size = v16;
      v6->m_alignment = (unsigned __int8)v13->m_alignment;
      return v8;
    case 0x13:
      hkTrackerLayoutCalculator::calcTypeInfo(v4, &resulta, type->m_contains, typeInfo);
      if ( resulta.m_enum == 1 )
        goto $LN12_165;
      v9 = v7->m_dimension;
      v10 = v6->m_size;
      v8->m_enum = 0;
      v6->m_size = v9 * v10;
      break;
    default:
      v17 = hkTrackerLayoutCalculator::calcBasicSize(v5);
      v6->m_size = v17;
      v18 = v17;
      v19 = hkTrackerLayoutCalculator::calcBasicAlignment(v7->m_type);
      v6->m_alignment = v19;
      if ( v18 && v19 > 0 )
LABEL_3:
        v8->m_enum = 0;
      else
$LN12_165:
        v8->m_enum = 1;
      break;
  }
  return v8;
}

// File Line: 456
// RVA: 0x13040E0
void __fastcall hkTrackerLayoutCalculator::getReferencesRecursive(hkTrackerLayoutCalculator *this, hkTrackerLayoutBlock *block, const void *curData, hkTrackerTypeTreeNode *curType, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkTrackerTypeTreeNode *v5; // rbp
  char *v6; // rbx
  hkTrackerLayoutCalculator *v7; // rsi
  hkTrackerLayoutHandler *v8; // rax
  hkBaseObjectVtbl *v9; // r10
  hkTrackerTypeLayout *v10; // rax
  int v11; // edi
  __int64 v12; // rbp
  const void *v13; // rdi
  hkArray<void const *,hkContainerHeapAllocator> *v14; // rbx
  hkTrackerTypeTreeNode *v15; // rbp
  __int64 v16; // rdi
  char **a; // [rsp+30h] [rbp-28h]
  int numtoinsert; // [rsp+38h] [rbp-20h]
  int v19; // [rsp+3Ch] [rbp-1Ch]
  hkTrackerLayoutBlock *blocka; // [rsp+68h] [rbp+10h]
  hkTrackerTypeLayout *v21; // [rsp+78h] [rbp+20h]
  unsigned __int64 v22; // [rsp+78h] [rbp+20h]

  blocka = block;
  v5 = curType;
  v6 = (char *)curData;
  v7 = this;
  switch ( curType->m_type )
  {
    case 1:
    case 2:
      if ( curType->m_contains->m_type != 15 )
      {
        v13 = *(const void **)curData;
        v14 = &block->m_references;
        if ( block->m_references.m_size == (block->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &block->m_references,
            8);
        v14->m_data[v14->m_size++] = v13;
      }
      break;
    case 3:
    case 0x10:
    case 0x12:
      v8 = hkTrackerLayoutCalculator::getHandler(this, &curType->m_name);
      if ( v8 )
      {
        v9 = v8->vfptr;
        v19 = 2147483648;
        a = 0i64;
        numtoinsert = 0;
        ((void (__fastcall *)(hkTrackerLayoutHandler *, hkTrackerLayoutBlock *, char *, hkTrackerTypeTreeNode *, hkTrackerLayoutCalculator *, char ***))v9[1].__first_virtual_table_function__)(
          v8,
          blocka,
          v6,
          v5,
          v7,
          &a);
        hkArrayBase<unsigned __int64>::_append(
          (hkArrayBase<char *> *)newBlocks,
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
          a,
          numtoinsert);
        numtoinsert = 0;
        if ( v19 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            a,
            8 * v19);
      }
      else if ( !((v5->m_type - 16) & 0xFFFFFFFD) )
      {
        v10 = hkTrackerLayoutCalculator::getLayout(v7, v5);
        v21 = v10;
        if ( v10 )
        {
          v11 = 0;
          if ( v10->m_members.m_size > 0 )
          {
            v12 = 0i64;
            do
            {
              hkTrackerLayoutCalculator::getReferencesRecursive(
                v7,
                blocka,
                &v6[v10->m_members.m_data[v12].m_offset],
                v10->m_members.m_data[v12].m_type,
                newBlocks);
              v10 = v21;
              ++v11;
              ++v12;
            }
            while ( v11 < v21->m_members.m_size );
          }
        }
      }
      break;
    case 0x13:
      v15 = curType->m_contains;
      v16 = (unsigned int)curType->m_dimension;
      v22 = hkTrackerLayoutCalculator::calcTypeSize(this, curType->m_contains);
      if ( (signed int)v16 > 0 )
      {
        do
        {
          hkTrackerLayoutCalculator::getReferencesRecursive(v7, blocka, v6, v15, newBlocks);
          v6 += v22;
          --v16;
        }
        while ( v16 );
      }
      break;
    default:
      return;
  }
}

// File Line: 538
// RVA: 0x1304040
void __fastcall hkTrackerLayoutCalculator::getReferences(hkTrackerLayoutCalculator *this, hkTrackerLayoutBlock *block, hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *newBlocks)
{
  hkArray<hkTrackerLayoutBlock const *,hkContainerTempAllocator> *v3; // r14
  hkTrackerLayoutBlock *v4; // rbx
  hkTrackerLayoutCalculator *v5; // rbp
  unsigned __int64 v6; // rax
  char *v7; // rdi
  int v8; // esi
  unsigned __int64 i; // r15

  v3 = newBlocks;
  v4 = block;
  v5 = this;
  if ( block->m_arraySize <= 1 )
  {
    hkTrackerLayoutCalculator::getReferencesRecursive(this, block, block->m_start, block->m_type, newBlocks);
  }
  else
  {
    v6 = hkTrackerLayoutCalculator::calcTypeSize(this, block->m_type);
    v7 = (char *)v4->m_start;
    v8 = 0;
    for ( i = v6; v8 < v4->m_arraySize; v7 += i )
    {
      hkTrackerLayoutCalculator::getReferencesRecursive(v5, v4, v7, v4->m_type, v3);
      ++v8;
    }
  }
}

// File Line: 557
// RVA: 0x1305740
__int64 __fastcall hkTrackerLayoutCalculator::_calcTypeSizeFromMember(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type)
{
  hkTrackerTypeTreeNode *v2; // r12
  hkTrackerLayoutCalculator *v3; // r13
  hkMemoryTracker *v4; // rax
  hkMemoryTracker *v5; // rdi
  int v6; // eax
  int v7; // ebx
  int v8; // er9
  int v9; // ecx
  int v10; // er15
  __int64 v11; // r14
  __int64 v12; // rsi
  signed int v13; // ebx
  __int64 v14; // rdi
  __int64 v15; // rbp
  __int64 v16; // rbx
  char *array; // [rsp+30h] [rbp-38h]
  int v19; // [rsp+38h] [rbp-30h]
  int v20; // [rsp+3Ch] [rbp-2Ch]
  hkResult result; // [rsp+80h] [rbp+18h]

  v2 = type;
  v3 = this;
  v4 = hkMemoryTracker::getInstance();
  v5 = v4;
  v6 = v4->vfptr->getTypeDefinitions(v4, 0i64);
  v20 = 2147483648;
  v19 = 0;
  v7 = v6;
  array = 0i64;
  if ( v6 > 0 )
  {
    v8 = v6;
    if ( v6 < 0 )
      v8 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v8, 8);
  }
  v19 = v7;
  ((void (__fastcall *)(hkMemoryTracker *))v5->vfptr->getTypeDefinitions)(v5);
  v9 = v19;
  v10 = 0;
  if ( v19 <= 0 )
  {
LABEL_14:
    v16 = 0i64;
  }
  else
  {
    v11 = 0i64;
    while ( 1 )
    {
      v12 = *(_QWORD *)&array[v11];
      if ( *(_BYTE *)(v12 + 19) == 1 )
      {
        v13 = 0;
        if ( *(_WORD *)(v12 + 40) > 0u )
          break;
      }
LABEL_13:
      ++v10;
      v11 += 8i64;
      if ( v10 >= v9 )
        goto LABEL_14;
    }
    v14 = 0i64;
    while ( 1 )
    {
      v15 = *(_QWORD *)(v12 + 24);
      if ( v2 == hkTrackerTypeTreeParser::parseType(*(const char **)(v15 + v14 + 8), v3->m_typeCache.m_pntr) )
        break;
      ++v13;
      v14 += 32i64;
      if ( v13 >= *(unsigned __int16 *)(v12 + 40) )
      {
        v9 = v19;
        goto LABEL_13;
      }
    }
    v16 = *(unsigned __int16 *)(v15 + v14 + 2);
  }
  v19 = 0;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v20);
  return v16;
}

// File Line: 591
// RVA: 0x1304600
void __fastcall hkTrackerLayoutCalculator::setTypeSize(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type, unsigned __int64 size)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_sizeMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)type,
    size);
}

// File Line: 596
// RVA: 0x13044D0
unsigned __int64 __fastcall hkTrackerLayoutCalculator::calcTypeSize(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type)
{
  hkTrackerLayoutCalculator *v2; // rbx
  hkTrackerTypeTreeNode *v3; // rdi
  unsigned __int64 v4; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rsi
  hkTrackerLayoutHandler *v6; // rax
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbx
  hkTrackerLayoutTypeInfo typeInfo; // [rsp+20h] [rbp-18h]
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = type;
  v4 = hkTrackerLayoutCalculator::calcBasicSize(type->m_type);
  if ( !v4 )
  {
    v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_sizeMap.m_map.m_elem;
    v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_sizeMap.m_map.m_elem,
           (unsigned __int64)v3,
           0i64);
    if ( !v4 )
    {
      if ( v3->m_type != 3 && v3->m_type != 16 && v3->m_type != 18 )
      {
        if ( v3->m_type == 19 )
          return v3->m_dimension * hkTrackerLayoutCalculator::calcTypeSize(v2, v3->m_contains);
        return 0i64;
      }
      v6 = hkTrackerLayoutCalculator::getHandler(v2, &v3->m_name);
      if ( v6 )
      {
        v7 = ((__int64 (__fastcall *)(hkTrackerLayoutHandler *, hkTrackerTypeTreeNode *, hkTrackerLayoutCalculator *))v6->vfptr[2].__vecDelDtor)(
               v6,
               v3,
               v2);
        v8 = v7;
      }
      else
      {
        hkTrackerLayoutCalculator::calcTypeInfo(v2, &result, v3, &typeInfo);
        if ( result.m_enum == HK_SUCCESS )
          return typeInfo.m_size;
        v7 = hkTrackerLayoutCalculator::_calcTypeSizeFromMember(v2, v3);
        v8 = v7;
        if ( !v7 )
          return 0i64;
      }
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        v5,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v3,
        v7);
      return v8;
    }
  }
  return v4;
}

// File Line: 656
// RVA: 0x1304620
void __fastcall hkTrackerLayoutCalculator::calcMembers(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type, unsigned __int64 size, hkArray<hkTrackerTypeLayout::Member,hkContainerHeapAllocator> *membersOut, int baseIndex, int flags)
{
  hkArray<hkTrackerTypeLayout::Member,hkContainerHeapAllocator> *v6; // rbx
  hkTrackerTypeTreeNode *v7; // rbp
  hkTrackerLayoutCalculator *v8; // rsi
  signed __int64 v9; // rcx
  hkTrackerTypeLayout *v10; // rax
  hkTrackerTypeLayout *v11; // rbp
  int v12; // edi
  signed __int64 v13; // rcx
  signed __int64 v14; // rcx
  unsigned __int64 v15; // rsi
  int v16; // edi
  __int64 v17; // rbp
  hkTrackerTypeTreeNode *typea; // [rsp+30h] [rbp-28h]
  hkTrackerLayoutCalculator *v19; // [rsp+60h] [rbp+8h]
  __int64 v20; // [rsp+68h] [rbp+10h]
  int v21; // [rsp+68h] [rbp+10h]
  unsigned __int64 v22; // [rsp+70h] [rbp+18h]

  v22 = size;
  v19 = this;
  v6 = membersOut;
  v7 = type;
  v8 = this;
  if ( type )
  {
    switch ( type->m_type )
    {
      case 1:
      case 2:
        if ( membersOut->m_size == (membersOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, membersOut, 32);
        v14 = (signed __int64)&v6->m_data[v6->m_size++];
        *(_QWORD *)(v14 + 16) = 0i64;
        *(_WORD *)(v14 + 8) = baseIndex;
        *(_QWORD *)v14 = v7;
        *(_WORD *)(v14 + 10) = 8;
        *(_DWORD *)(v14 + 24) = flags;
        break;
      case 3:
      case 0x10:
      case 0x12:
        v10 = hkTrackerLayoutCalculator::getLayout(this, type);
        v11 = v10;
        if ( v10 )
        {
          v12 = 0;
          if ( v10->m_members.m_size > 0 )
          {
            v13 = 0i64;
            v20 = 0i64;
            do
            {
              hkTrackerLayoutCalculator::calcMembers(
                v8,
                *(hkTrackerTypeTreeNode **)((char *)&v11->m_members.m_data->m_type + v13),
                *(unsigned __int16 *)((char *)&v11->m_members.m_data->m_size + v13),
                v6,
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
      case 0x13:
        v21 = type->m_dimension;
        typea = type->m_contains;
        v15 = hkTrackerLayoutCalculator::calcTypeSize(this, type->m_contains);
        if ( v15 >= 8 )
        {
          v16 = baseIndex;
          if ( v21 > 0 )
          {
            v17 = (unsigned int)v21;
            do
            {
              hkTrackerLayoutCalculator::calcMembers(v19, typea, v15, v6, v16, flags);
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
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, membersOut, 32);
    v9 = (signed __int64)&v6->m_data[v6->m_size++];
    *(_QWORD *)(v9 + 16) = 0i64;
    *(_WORD *)(v9 + 8) = baseIndex;
    *(_QWORD *)v9 = 0i64;
    *(_WORD *)(v9 + 10) = v22;
    *(_DWORD *)(v9 + 24) = flags;
  }
}

// File Line: 728
// RVA: 0x1305AD0
void __fastcall concatMemberName(const char *name, int memberIndex, hkStringBuf *buf)
{
  hkStringBuf *v3; // rdi
  unsigned int v4; // esi
  const char *v5; // rbx
  unsigned __int64 i; // rdx

  v3 = buf;
  v4 = memberIndex;
  v5 = name;
  if ( buf->m_string.m_size - 1 > 0 )
    hkStringBuf::append(buf, ".", -1);
  if ( v5 )
  {
    for ( i = (unsigned __int64)&v5[(signed int)hkString::strLen(v5) - 1]; i >= (unsigned __int64)v5; --i )
    {
      if ( *(_BYTE *)i == 58 )
        break;
    }
    hkStringBuf::append(v3, (const char *)(i + 1), -1);
  }
  else
  {
    hkStringBuf::appendPrintf(v3, "_unknown%i", v4);
  }
}

// File Line: 751
// RVA: 0x1305B80
void __fastcall addName(hkStringBuf *baseName, hkArray<char,hkContainerHeapAllocator> *buffer, hkArray<int,hkContainerHeapAllocator> *namesOffset)
{
  int v3; // ebp
  hkArray<int,hkContainerHeapAllocator> *v4; // rdi
  hkArray<char,hkContainerHeapAllocator> *v5; // rbx
  hkStringBuf *v6; // rsi
  int v7; // edi
  __int64 v8; // r14
  int v9; // er9
  int v10; // eax
  int v11; // eax
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = buffer->m_size;
  v4 = namesOffset;
  v5 = buffer;
  v6 = baseName;
  if ( namesOffset->m_size == (namesOffset->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, namesOffset, 4);
  v4->m_data[v4->m_size++] = v3;
  v7 = v6->m_string.m_size;
  v8 = v5->m_size;
  v9 = v8 + v7;
  v10 = v5->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 >= (signed int)v8 + v7 )
  {
    result.m_enum = 0;
  }
  else
  {
    v11 = 2 * v10;
    if ( v9 < v11 )
      v9 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v9, 1);
  }
  v5->m_size += v7;
  hkString::memCpy(&v5->m_data[v8], v6->m_string.m_data, v6->m_string.m_size - 1);
  v5->m_data[v5->m_size - 1] = 0;
}

// File Line: 762
// RVA: 0x13058C0
void __fastcall hkTrackerLayoutCalculator::_calcMemberNames(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type, hkStringBuf *baseName, hkArray<char,hkContainerHeapAllocator> *buffer, hkArray<int,hkContainerHeapAllocator> *namesOffset)
{
  hkStringBuf *v5; // rbx
  hkArray<char,hkContainerHeapAllocator> *v6; // rsi
  hkTrackerTypeLayout *v7; // rax
  int v8; // ebp
  signed __int64 v9; // rcx
  int v10; // esi
  const char **v11; // rdi
  int v12; // edi
  int v13; // ebp
  int v14; // edi
  hkTrackerTypeTreeNode *typea; // [rsp+30h] [rbp-28h]
  hkTrackerTypeTreeNode *typeb; // [rsp+30h] [rbp-28h]
  hkTrackerLayoutCalculator *v17; // [rsp+60h] [rbp+8h]
  __int64 v18; // [rsp+68h] [rbp+10h]
  int v19; // [rsp+68h] [rbp+10h]
  hkArray<char,hkContainerHeapAllocator> *buffera; // [rsp+78h] [rbp+20h]

  buffera = buffer;
  v17 = this;
  v5 = baseName;
  v6 = buffer;
  if ( type )
  {
    switch ( type->m_type )
    {
      case 1:
      case 2:
        addName(baseName, buffer, namesOffset);
        break;
      case 3:
      case 0x10:
      case 0x12:
        v7 = hkTrackerLayoutCalculator::getLayout(this, type);
        typea = (hkTrackerTypeTreeNode *)v7;
        if ( v7 )
        {
          v8 = 0;
          if ( v7->m_members.m_size > 0 )
          {
            v9 = 0i64;
            v18 = 0i64;
            do
            {
              v10 = v5->m_string.m_size;
              v11 = (const char **)((char *)v7->m_members.m_data + v9);
              concatMemberName(v11[2], v8, v5);
              hkTrackerLayoutCalculator::_calcMemberNames(v17, (hkTrackerTypeTreeNode *)*v11, v5, buffera, namesOffset);
              hkStringBuf::chompEnd(v5, v5->m_string.m_size - v10);
              v7 = (hkTrackerTypeLayout *)typea;
              v9 = v18 + 32;
              ++v8;
              v18 += 32i64;
            }
            while ( v8 < SLODWORD(typea->m_contains) );
          }
        }
        break;
      case 0x13:
        v12 = type->m_dimension;
        v19 = type->m_dimension;
        typeb = type->m_contains;
        if ( hkTrackerLayoutCalculator::calcTypeSize(this, typeb) >= 8 )
        {
          v13 = 0;
          if ( v12 > 0 )
          {
            do
            {
              v14 = v5->m_string.m_size;
              hkStringBuf::append(v5, "[", -1);
              hkStringBuf::appendPrintf(v5, "%i", (unsigned int)v13);
              hkStringBuf::append(v5, "]", -1);
              hkTrackerLayoutCalculator::_calcMemberNames(v17, typeb, v5, v6, namesOffset);
              hkStringBuf::chompEnd(v5, v5->m_string.m_size - v14);
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
    addName(baseName, buffer, namesOffset);
  }
}

// File Line: 832
// RVA: 0x1304870
void __fastcall hkTrackerLayoutCalculator::calcMemberNames(hkTrackerLayoutCalculator *this, hkTrackerTypeTreeNode *type, hkArray<char,hkContainerHeapAllocator> *buffer, hkArray<int,hkContainerHeapAllocator> *namesOffset)
{
  hkStringBuf baseName; // [rsp+30h] [rbp-98h]

  baseName.m_string.m_capacityAndFlags = -2147483520;
  baseName.m_string.m_size = 1;
  baseName.m_string.m_data = baseName.m_string.m_storage;
  baseName.m_string.m_storage[0] = 0;
  hkTrackerLayoutCalculator::_calcMemberNames(this, type, &baseName, buffer, namesOffset);
  baseName.m_string.m_size = 0;
  if ( baseName.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      baseName.m_string.m_data,
      baseName.m_string.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 839
// RVA: 0x13048F0
void __fastcall hkTrackerLayoutCalculator::flattenTypes(hkTrackerLayoutCalculator *this)
{
  hkTrackerLayoutCalculator *v1; // rsi
  __int64 v2; // rcx
  int v3; // er8
  __int64 v4; // rdx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v5; // rax
  int v6; // er14
  unsigned __int64 v7; // rdi
  _QWORD **v8; // rax
  __int64 v9; // rax
  __int64 v10; // rbx
  unsigned __int16 v11; // r8
  char v12; // dl
  __int64 v13; // rcx
  int v14; // er10
  __int64 v15; // r8
  __int64 v16; // r9
  __int64 v17; // r8
  int v18; // edx
  __int64 v19; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v20; // rax
  hkArray<int,hkContainerHeapAllocator> namesOffset; // [rsp+30h] [rbp-B8h]
  char v22; // [rsp+40h] [rbp-A8h]

  v1 = this;
  v2 = this->m_layoutMap.m_map.m_hashMod;
  v3 = 0;
  v4 = 0i64;
  if ( v2 >= 0 )
  {
    v5 = v1->m_layoutMap.m_map.m_elem;
    do
    {
      if ( v5->key != -1i64 )
        break;
      ++v4;
      ++v3;
      ++v5;
    }
    while ( v4 <= v2 );
  }
  v6 = v3;
  if ( v3 <= v1->m_layoutMap.m_map.m_hashMod )
  {
    do
    {
      v7 = v1->m_layoutMap.m_map.m_elem[v6].val;
      if ( !*(_BYTE *)(v7 + 61) )
      {
        v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v9 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 64i64);
        v10 = v9;
        if ( v9 )
        {
          v11 = *(_WORD *)(v7 + 58);
          v12 = *(_BYTE *)(v7 + 56);
          v13 = *(_QWORD *)(v7 + 16);
          *(_DWORD *)(v9 + 8) = 0x1FFFF;
          *(_QWORD *)(v9 + 16) = v13;
          *(_QWORD *)v9 = &hkTrackerTypeLayout::`vftable;
          *(_QWORD *)(v9 + 24) = 0i64;
          *(_DWORD *)(v9 + 32) = 0;
          *(_DWORD *)(v9 + 36) = 2147483648;
          *(_QWORD *)(v9 + 40) = 0i64;
          *(_DWORD *)(v9 + 48) = 0;
          *(_DWORD *)(v9 + 52) = 2147483648;
          *(_BYTE *)(v9 + 56) = v12;
          *(_DWORD *)(v9 + 58) = v11;
        }
        else
        {
          v10 = 0i64;
        }
        *(_BYTE *)(v10 + 60) = *(_BYTE *)(v7 + 60);
        hkTrackerLayoutCalculator::calcMembers(
          v1,
          *(hkTrackerTypeTreeNode **)(v7 + 16),
          *(unsigned __int16 *)(v7 + 58),
          (hkArray<hkTrackerTypeLayout::Member,hkContainerHeapAllocator> *)(v10 + 24),
          0,
          0);
        namesOffset.m_size = 0;
        namesOffset.m_capacityAndFlags = -2147483616;
        namesOffset.m_data = (int *)&v22;
        hkTrackerLayoutCalculator::calcMemberNames(
          v1,
          *(hkTrackerTypeTreeNode **)(v7 + 16),
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
        hkReferencedObject::removeReference((hkReferencedObject *)v7);
        v1->m_layoutMap.m_map.m_elem[v6].val = v10;
        namesOffset.m_size = 0;
        if ( namesOffset.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            namesOffset.m_data,
            4 * namesOffset.m_capacityAndFlags);
      }
      v17 = v1->m_layoutMap.m_map.m_hashMod;
      v18 = v6 + 1;
      v19 = v6 + 1;
      if ( v19 <= v17 )
      {
        v20 = &v1->m_layoutMap.m_map.m_elem[v18];
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
    while ( v18 <= v1->m_layoutMap.m_map.m_hashMod );
  }
}     }
        while ( v19 <= v17 );
      }
      v6 = v18;
    }
    while ( v18 <= v1->m_layoutMap.m_map.m_hashMod );
 

