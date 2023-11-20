// File Line: 27
// RVA: 0xE647C0
void __fastcall hkPackfileData::hkPackfileData(hkPackfileData *this, hkClassNameRegistry *reg)
{
  hkClassNameRegistry *v2; // rdi
  hkPackfileData *v3; // rbx
  hkReferencedObject *v4; // rcx
  __int64 v5; // rax
  hkReferencedObject *v6; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkPackfileData::`vftable';
  this->m_topLevelObject = 0i64;
  this->m_name = 0i64;
  v2 = reg;
  v3 = this;
  this->m_trackedObjects.m_map.m_elem = 0i64;
  this->m_trackedObjects.m_map.m_numElems = 0;
  this->m_trackedObjects.m_map.m_hashMod = -1;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_trackedTypes.m_map,
    0);
  v3->m_packfileClassRegistry.m_pntr = 0i64;
  v3->m_destructorsEnabled = 1;
  v3->m_memory.m_data = 0i64;
  v3->m_memory.m_size = 0;
  v3->m_memory.m_capacityAndFlags = 2147483648;
  v3->m_chunks.m_data = 0i64;
  v3->m_chunks.m_size = 0;
  v3->m_chunks.m_capacityAndFlags = 2147483648;
  v3->m_exports.m_data = 0i64;
  v3->m_exports.m_size = 0;
  v3->m_exports.m_capacityAndFlags = 2147483648;
  v3->m_imports.m_data = 0i64;
  v3->m_imports.m_size = 0;
  v3->m_imports.m_capacityAndFlags = 2147483648;
  v3->m_postFinishObjects.m_data = 0i64;
  v3->m_postFinishObjects.m_size = 0;
  v3->m_postFinishObjects.m_capacityAndFlags = 2147483648;
  if ( v2 )
  {
    v4 = (hkReferencedObject *)&v2->vfptr;
  }
  else
  {
    v5 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
    v2 = (hkClassNameRegistry *)v5;
    if ( !v5 )
      goto LABEL_6;
    v4 = (hkReferencedObject *)v5;
  }
  hkReferencedObject::addReference(v4);
LABEL_6:
  v6 = (hkReferencedObject *)&v3->m_packfileClassRegistry.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v3->m_packfileClassRegistry.m_pntr = v2;
}

// File Line: 39
// RVA: 0xE64B50
void __fastcall hkPackfileData::callDestructors(hkPackfileData *this)
{
  hkPackfileData *v1; // rbx
  __int64 v2; // r8
  int v3; // edx
  __int64 v4; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v5; // rax
  int v6; // edi
  hkTypeInfo *v7; // rax
  __int64 v8; // r8
  int v9; // edx
  __int64 v10; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v11; // rax

  v1 = this;
  if ( this->m_destructorsEnabled && this->m_trackedTypes.m_map.m_numElems > 0 )
  {
    v2 = this->m_trackedObjects.m_map.m_hashMod;
    v3 = 0;
    v4 = 0i64;
    if ( v2 >= 0 )
    {
      v5 = v1->m_trackedObjects.m_map.m_elem;
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
    if ( v3 <= v1->m_trackedObjects.m_map.m_hashMod )
    {
      do
      {
        v7 = (hkTypeInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_trackedTypes,
                             v1->m_trackedObjects.m_map.m_elem[v6].val,
                             0i64);
        if ( v7 )
          hkTypeInfo::cleanupLoadedObject(v7, (void *)v1->m_trackedObjects.m_map.m_elem[v6].key);
        v8 = v1->m_trackedObjects.m_map.m_hashMod;
        v9 = v6 + 1;
        v10 = v6 + 1;
        if ( v10 <= v8 )
        {
          v11 = &v1->m_trackedObjects.m_map.m_elem[v9];
          do
          {
            if ( v11->key != -1i64 )
              break;
            ++v10;
            ++v9;
            ++v11;
          }
          while ( v10 <= v8 );
        }
        v6 = v9;
      }
      while ( v9 <= v1->m_trackedObjects.m_map.m_hashMod );
    }
  }
  v1->m_topLevelObject = 0i64;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_trackedObjects.m_map.m_elem);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&v1->m_trackedTypes.m_map);
}

// File Line: 61
// RVA: 0xE648E0
void __fastcall hkPackfileData::~hkPackfileData(hkPackfileData *this)
{
  hkPackfileData *v1; // rbx
  int v2; // ebp
  __int64 v3; // rsi
  void *v4; // rdi
  hkMemoryAllocator **v5; // rax
  int v6; // ebp
  __int64 v7; // r14
  hkPackfileData::Chunk *v8; // rax
  unsigned int v9; // edi
  void *v10; // rsi
  _QWORD **v11; // rax
  char *v12; // rdi
  hkMemoryAllocator **v13; // rax
  int v14; // er8
  int v15; // er8
  int v16; // er8
  int v17; // er8
  int v18; // er8
  hkReferencedObject *v19; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkPackfileData::`vftable';
  hkPackfileData::callDestructors(this);
  v2 = 0;
  if ( v1->m_memory.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v1->m_memory.m_data[v3];
      v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::easyFree(v5[11], v4);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_memory.m_size );
  }
  v6 = 0;
  if ( v1->m_chunks.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v1->m_chunks.m_data;
      v9 = v8[v7].numBytes;
      v10 = v8[v7].pointer;
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v11[11] + 16i64))(v11[11], v10, v9);
      ++v6;
      ++v7;
    }
    while ( v6 < v1->m_chunks.m_size );
  }
  v12 = v1->m_name;
  v13 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::easyFree(v13[11], v12);
  v14 = v1->m_postFinishObjects.m_capacityAndFlags;
  v1->m_postFinishObjects.m_size = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_postFinishObjects.m_data,
      16 * v14);
  v1->m_postFinishObjects.m_data = 0i64;
  v1->m_postFinishObjects.m_capacityAndFlags = 2147483648;
  v15 = v1->m_imports.m_capacityAndFlags;
  v1->m_imports.m_size = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_imports.m_data,
      16 * v15);
  v1->m_imports.m_data = 0i64;
  v1->m_imports.m_capacityAndFlags = 2147483648;
  v16 = v1->m_exports.m_capacityAndFlags;
  v1->m_exports.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_exports.m_data,
      16 * v16);
  v1->m_exports.m_data = 0i64;
  v1->m_exports.m_capacityAndFlags = 2147483648;
  v17 = v1->m_chunks.m_capacityAndFlags;
  v1->m_chunks.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_chunks.m_data,
      16 * v17);
  v1->m_chunks.m_data = 0i64;
  v1->m_chunks.m_capacityAndFlags = 2147483648;
  v18 = v1->m_memory.m_capacityAndFlags;
  v1->m_memory.m_size = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_memory.m_data,
      8 * v18);
  v1->m_memory.m_data = 0i64;
  v1->m_memory.m_capacityAndFlags = 2147483648;
  v19 = (hkReferencedObject *)&v1->m_packfileClassRegistry.m_pntr->vfptr;
  if ( v19 )
    hkReferencedObject::removeReference(v19);
  v1->m_packfileClassRegistry.m_pntr = 0i64;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_trackedTypes.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v1->m_trackedObjects.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v1->m_trackedObjects);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 77
// RVA: 0xE64E00
void __fastcall hkPackfileData::setName(hkPackfileData *this, const char *n)
{
  char *v2; // rbx
  hkPackfileData *v3; // rsi
  const char *v4; // rdi
  hkMemoryAllocator **v5; // rax

  v2 = this->m_name;
  v3 = this;
  v4 = n;
  v5 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::easyFree(v5[11], v2);
  v3->m_name = hkString::strDup(v4);
}

// File Line: 83
// RVA: 0xE64C50
void __fastcall hkPackfileData::getImportsExports(hkPackfileData *this, hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut, hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut)
{
  int v3; // ebp
  hkArray<hkResource::Export,hkContainerHeapAllocator> *v4; // rsi
  int v5; // ebx
  hkArray<hkResource::Import,hkContainerHeapAllocator> *v6; // rdi
  int v7; // eax
  hkPackfileData *v8; // r14
  int v9; // eax
  int v10; // er9
  hkResource::Import *v11; // rcx
  char *v12; // r8
  __int64 v13; // rdx
  const char *v14; // rax
  hkResource::Import *v15; // rcx
  __int64 v16; // rdx
  signed __int64 v17; // r8
  int v18; // ebx
  int v19; // edi
  int v20; // eax
  int v21; // eax
  int v22; // er9
  hkResource::Export *v23; // rcx
  char *v24; // r8
  __int64 v25; // rdx
  const char *v26; // rax
  hkResource::Export *v27; // rax
  __int64 v28; // rdx
  signed __int64 v29; // r8
  hkResult result; // [rsp+50h] [rbp+8h]

  v3 = this->m_imports.m_size;
  v4 = expOut;
  v5 = this->m_imports.m_size;
  v6 = impOut;
  if ( v3 > impOut->m_size )
    v5 = impOut->m_size;
  v7 = impOut->m_capacityAndFlags & 0x3FFFFFFF;
  v8 = this;
  if ( v7 < v3 )
  {
    v9 = 2 * v7;
    v10 = this->m_imports.m_size;
    if ( v3 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, impOut, v10, 16);
  }
  v11 = v6->m_data;
  if ( v5 > 0 )
  {
    v12 = (char *)((char *)v8->m_imports.m_data - (char *)v11);
    v13 = v5;
    do
    {
      v14 = *(const char **)((char *)&v11->name + (_QWORD)v12);
      ++v11;
      v11[-1].name = v14;
      v11[-1].location = *(void ***)((char *)v11 + (_QWORD)v12 - 8);
      --v13;
    }
    while ( v13 );
  }
  v15 = &v6->m_data[v5];
  v16 = v3 - v5;
  if ( v3 - v5 > 0 )
  {
    v17 = (char *)v8->m_imports.m_data - (char *)v6->m_data;
    do
    {
      if ( v15 )
      {
        v15->name = *(const char **)((char *)&v15->name + v17);
        v15->location = *(void ***)((char *)&v15->location + v17);
      }
      ++v15;
      --v16;
    }
    while ( v16 );
  }
  v6->m_size = v3;
  v18 = v8->m_exports.m_size;
  v19 = v8->m_exports.m_size;
  if ( v18 > v4->m_size )
    v19 = v4->m_size;
  v20 = v4->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < v18 )
  {
    v21 = 2 * v20;
    v22 = v8->m_exports.m_size;
    if ( v18 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, v22, 16);
  }
  v23 = v4->m_data;
  if ( v19 > 0 )
  {
    v24 = (char *)((char *)v8->m_exports.m_data - (char *)v23);
    v25 = v19;
    do
    {
      v26 = *(const char **)((char *)&v23->name + (_QWORD)v24);
      ++v23;
      v23[-1].name = v26;
      v23[-1].data = *(void **)((char *)v23 + (_QWORD)v24 - 8);
      --v25;
    }
    while ( v25 );
  }
  v27 = &v4->m_data[v19];
  v28 = v18 - v19;
  if ( v18 - v19 > 0 )
  {
    v29 = (char *)v8->m_exports.m_data - (char *)v4->m_data;
    do
    {
      if ( v27 )
      {
        v27->name = *(const char **)((char *)&v27->name + v29);
        v27->data = *(void **)((char *)&v27->data + v29);
      }
      ++v27;
      --v28;
    }
    while ( v28 );
  }
  v4->m_size = v18;
}

// File Line: 89
// RVA: 0xE65030
void __fastcall hkPackfileData::addExport(hkPackfileData *this, const char *symbolName, void *object)
{
  hkArray<hkResource::Export,hkContainerHeapAllocator> *v3; // rbx
  const char *v4; // rdi
  const char *v5; // rsi
  const char **v6; // rcx

  v3 = &this->m_exports;
  v4 = (const char *)object;
  v5 = symbolName;
  if ( this->m_exports.m_size == (this->m_exports.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 16);
  v6 = &v3->m_data[v3->m_size++].name;
  *v6 = v5;
  v6[1] = v4;
}

// File Line: 96
// RVA: 0xE650A0
void __fastcall hkPackfileData::removeExport(hkPackfileData *this, void *object)
{
  void *v2; // rdi
  hkPackfileData *v3; // r9
  int v4; // er11
  __int64 v5; // rbx
  signed __int64 v6; // r10
  hkResource::Export *v7; // rax
  __int64 v8; // rcx
  signed __int64 v9; // rdx
  signed __int64 v10; // r8
  signed __int64 v11; // rax
  signed __int64 v12; // r8
  __int64 v13; // rcx

  v2 = object;
  v3 = this;
  v4 = this->m_exports.m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = v4;
    do
    {
      v7 = v3->m_exports.m_data;
      if ( v7[v6].data == v2 )
      {
        v8 = --v3->m_exports.m_size;
        if ( (_DWORD)v8 != v4 )
        {
          v9 = 2i64;
          v10 = (signed __int64)&v7[v8];
          v11 = (signed __int64)&v7[v6];
          v12 = v10 - v11;
          do
          {
            v13 = *(_QWORD *)(v12 + v11);
            v11 += 8i64;
            *(_QWORD *)(v11 - 8) = v13;
            --v9;
          }
          while ( v9 );
        }
      }
      --v4;
      --v6;
      --v5;
    }
    while ( v5 >= 0 );
  }
}

// File Line: 108
// RVA: 0xE65140
void __fastcall hkPackfileData::addImport(hkPackfileData *this, const char *symbolName, void **location)
{
  hkArray<hkResource::Import,hkContainerHeapAllocator> *v3; // rbx
  void **v4; // rdi
  const char *v5; // rsi
  const char **v6; // rcx

  v3 = &this->m_imports;
  v4 = location;
  v5 = symbolName;
  if ( this->m_imports.m_size == (this->m_imports.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 16);
  v6 = &v3->m_data[v3->m_size++].name;
  *v6 = v5;
  v6[1] = (const char *)v4;
}

// File Line: 122
// RVA: 0xE651B0
void __fastcall hkPackfileData::removeImport(hkPackfileData *this, void **location)
{
  void **v2; // r11
  int v3; // er10
  __int64 v4; // r9
  void ***v5; // rdx
  signed __int64 v6; // rdx
  hkResource::Import *v7; // rax
  signed __int64 v8; // r8
  void **v9; // rcx

  v2 = location;
  v3 = this->m_imports.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    v5 = &this->m_imports.m_data[v3].location;
    while ( *v5 != v2 )
    {
      --v3;
      v5 -= 2;
      if ( --v4 < 0 )
        return;
    }
    if ( --this->m_imports.m_size != v3 )
    {
      v6 = 2i64;
      v7 = &this->m_imports.m_data[v3];
      v8 = 16i64 * this->m_imports.m_size - 16i64 * v3;
      do
      {
        v9 = *(void ***)((char *)&v7->name + v8);
        v7 = (hkResource::Import *)((char *)v7 + 8);
        v7[-1].location = v9;
        --v6;
      }
      while ( v6 );
    }
  }
}

// File Line: 135
// RVA: 0xE65290
_BOOL8 __fastcall hkPackfileData::finishedObjects(hkPackfileData *this)
{
  return this->m_trackedTypes.m_map.m_numElems != 0;
}

// File Line: 140
// RVA: 0xE652A0
bool __fastcall baseOrSameClass(const char *typeName, const char *topLevelClassName, hkClassNameRegistry *classReg)
{
  const char *v3; // rdi
  hkClassNameRegistry *v4; // rsi
  hkClass *v5; // rbx
  hkClass *v6; // rax
  hkBool result; // [rsp+40h] [rbp+18h]

  v3 = typeName;
  v4 = classReg;
  v5 = (hkClass *)classReg->vfptr[2].__vecDelDtor((hkBaseObject *)classReg, (unsigned int)topLevelClassName);
  v6 = (hkClass *)v4->vfptr[2].__vecDelDtor((hkBaseObject *)&v4->vfptr, (unsigned int)v3);
  return hkClass::isSuperClass(v6, &result, v5)->m_bool != 0;
}

// File Line: 151
// RVA: 0xE64E60
void *__fastcall hkPackfileData::getContentsPointer(hkPackfileData *this, const char *typeName, hkTypeInfoRegistry *typeRegistry)
{
  const char *v3; // rbp
  void *v4; // rdx
  hkTypeInfoRegistry *v5; // r15
  hkPackfileData *v6; // rsi
  unsigned __int64 v7; // rax
  hkClassNameRegistry *v8; // rdi
  hkClass *v9; // rbx
  hkClass *v10; // rax
  __int64 v11; // r8
  int v12; // edx
  char v13; // bl
  __int64 v14; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v15; // rax
  int v16; // edi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v17; // rax
  unsigned __int64 v18; // rbp
  unsigned __int64 v19; // rax
  __int64 v20; // r8
  int v21; // edx
  __int64 v22; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v23; // rax
  unsigned __int64 v24; // rdi
  __int64 v25; // rbx
  hkVariant *v26; // rax
  hkBool result; // [rsp+40h] [rbp+8h]

  v3 = typeName;
  v4 = this->m_topLevelObject;
  v5 = typeRegistry;
  v6 = this;
  if ( v4 )
  {
    v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_trackedObjects.m_map.m_elem,
           (unsigned __int64)v4,
           0i64);
    if ( !v3
      || (v8 = v6->m_packfileClassRegistry.m_pntr,
          v9 = (hkClass *)v8->vfptr[2].__vecDelDtor((hkBaseObject *)&v6->m_packfileClassRegistry.m_pntr->vfptr, v7),
          v10 = (hkClass *)v8->vfptr[2].__vecDelDtor((hkBaseObject *)&v8->vfptr, (unsigned int)v3),
          hkClass::isSuperClass(v10, &result, v9)->m_bool) )
    {
      if ( hkPackfileData::finishedObjects(v6) || !v5 )
        return v6->m_topLevelObject;
      v11 = v6->m_trackedObjects.m_map.m_hashMod;
      v12 = 0;
      v13 = 0;
      v14 = 0i64;
      if ( v11 >= 0 )
      {
        v15 = v6->m_trackedObjects.m_map.m_elem;
        do
        {
          if ( v15->key != -1i64 )
            break;
          ++v14;
          ++v12;
          ++v15;
        }
        while ( v14 <= v11 );
      }
      v16 = v12;
      if ( v12 > v6->m_trackedObjects.m_map.m_hashMod )
        goto LABEL_26;
      do
      {
        v17 = v6->m_trackedObjects.m_map.m_elem;
        v18 = v17[v16].val;
        v19 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, unsigned __int64, unsigned __int64))v5->vfptr[2].__vecDelDtor)(
                v5,
                v17[v16].key,
                v17[v16].val);
        if ( v19 )
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v6->m_trackedTypes.m_map, v18, v19);
        else
          v13 = 1;
        v20 = v6->m_trackedObjects.m_map.m_hashMod;
        v21 = v16 + 1;
        v22 = v16 + 1;
        if ( v22 <= v20 )
        {
          v23 = &v6->m_trackedObjects.m_map.m_elem[v21];
          do
          {
            if ( v23->key != -1i64 )
              break;
            ++v22;
            ++v21;
            ++v23;
          }
          while ( v22 <= v20 );
        }
        v16 = v21;
      }
      while ( v21 <= v6->m_trackedObjects.m_map.m_hashMod );
      if ( !v13 )
      {
LABEL_26:
        v24 = (unsigned __int64)v6->m_postFinishObjects.m_data;
        if ( v24 < v24 + 16i64 * v6->m_postFinishObjects.m_size )
        {
          do
          {
            v25 = *(_QWORD *)v24;
            v26 = hkClass::getAttribute(*(hkClass **)(v24 + 8), "hk.PostFinish");
            (*(void (__fastcall **)(__int64))v26->m_object)(v25);
            v24 += 16i64;
          }
          while ( (hkVariant *)v24 < &v6->m_postFinishObjects.m_data[v6->m_postFinishObjects.m_size] );
        }
        return v6->m_topLevelObject;
      }
    }
  }
  return 0i64;
}

// File Line: 207
// RVA: 0xE65240
void __fastcall hkPackfileData::setContentsWithName(hkPackfileData *this, void *topLevelObject, const char *typeName)
{
  this->m_topLevelObject = topLevelObject;
}

// File Line: 216
// RVA: 0xE65010
const char *__fastcall hkPackfileData::getContentsTypeName(hkPackfileData *this)
{
  void *v1; // rdx
  const char *result; // rax

  v1 = this->m_topLevelObject;
  if ( v1 )
    result = (const char *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_trackedObjects.m_map.m_elem,
                             (unsigned __int64)v1,
                             0i64);
  else
    result = 0i64;
  return result;
}

// File Line: 227
// RVA: 0xE65250
void __fastcall hkPackfileData::setPackfileClassNameRegistry(hkPackfileData *this, hkClassNameRegistry *classReg)
{
  hkClassNameRegistry *v2; // rbx
  hkPackfileData *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = classReg;
  v3 = this;
  if ( classReg )
    hkReferencedObject::addReference((hkReferencedObject *)&classReg->vfptr);
  v4 = (hkReferencedObject *)&v3->m_packfileClassRegistry.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_packfileClassRegistry.m_pntr = v2;
}

