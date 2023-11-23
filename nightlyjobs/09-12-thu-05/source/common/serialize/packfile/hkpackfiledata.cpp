// File Line: 27
// RVA: 0xE647C0
void __fastcall hkPackfileData::hkPackfileData(hkPackfileData *this, hkClassNameRegistry *reg)
{
  hkClassNameRegistry *v4; // rcx
  hkClassNameRegistry *v5; // rax
  hkClassNameRegistry *m_pntr; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkPackfileData::`vftable;
  this->m_topLevelObject = 0i64;
  this->m_name = 0i64;
  this->m_trackedObjects.m_map.m_elem = 0i64;
  this->m_trackedObjects.m_map.m_numElems = 0;
  this->m_trackedObjects.m_map.m_hashMod = -1;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_trackedTypes.m_map,
    0);
  this->m_packfileClassRegistry.m_pntr = 0i64;
  this->m_destructorsEnabled = 1;
  this->m_memory.m_data = 0i64;
  this->m_memory.m_size = 0;
  this->m_memory.m_capacityAndFlags = 0x80000000;
  this->m_chunks.m_data = 0i64;
  this->m_chunks.m_size = 0;
  this->m_chunks.m_capacityAndFlags = 0x80000000;
  this->m_exports.m_data = 0i64;
  this->m_exports.m_size = 0;
  this->m_exports.m_capacityAndFlags = 0x80000000;
  this->m_imports.m_data = 0i64;
  this->m_imports.m_size = 0;
  this->m_imports.m_capacityAndFlags = 0x80000000;
  this->m_postFinishObjects.m_data = 0i64;
  this->m_postFinishObjects.m_size = 0;
  this->m_postFinishObjects.m_capacityAndFlags = 0x80000000;
  if ( reg )
  {
    v4 = reg;
  }
  else
  {
    v5 = (hkClassNameRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
    reg = v5;
    if ( !v5 )
      goto LABEL_6;
    v4 = v5;
  }
  hkReferencedObject::addReference(v4);
LABEL_6:
  m_pntr = this->m_packfileClassRegistry.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_packfileClassRegistry.m_pntr = reg;
}

// File Line: 39
// RVA: 0xE64B50
void __fastcall hkPackfileData::callDestructors(hkPackfileData *this)
{
  __int64 m_hashMod; // r8
  int v3; // edx
  __int64 v4; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v6; // edi
  hkTypeInfo *v7; // rax
  __int64 v8; // r8
  int v9; // edx
  __int64 v10; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v11; // rax

  if ( this->m_destructorsEnabled && this->m_trackedTypes.m_map.m_numElems > 0 )
  {
    m_hashMod = this->m_trackedObjects.m_map.m_hashMod;
    v3 = 0;
    v4 = 0i64;
    if ( m_hashMod >= 0 )
    {
      m_elem = this->m_trackedObjects.m_map.m_elem;
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
    if ( v3 <= this->m_trackedObjects.m_map.m_hashMod )
    {
      do
      {
        v7 = (hkTypeInfo *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_trackedTypes,
                             (const char *)this->m_trackedObjects.m_map.m_elem[v6].val,
                             0i64);
        if ( v7 )
          hkTypeInfo::cleanupLoadedObject(v7, (void *)this->m_trackedObjects.m_map.m_elem[v6].key);
        v8 = this->m_trackedObjects.m_map.m_hashMod;
        v9 = v6 + 1;
        v10 = v6 + 1;
        if ( v10 <= v8 )
        {
          v11 = &this->m_trackedObjects.m_map.m_elem[v9];
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
      while ( v9 <= this->m_trackedObjects.m_map.m_hashMod );
    }
  }
  this->m_topLevelObject = 0i64;
  hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&this->m_trackedObjects.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_trackedTypes.m_map);
}

// File Line: 61
// RVA: 0xE648E0
void __fastcall hkPackfileData::~hkPackfileData(hkPackfileData *this)
{
  int v2; // ebp
  __int64 v3; // rsi
  _DWORD *v4; // rdi
  hkMemoryAllocator **Value; // rax
  int v6; // ebp
  __int64 v7; // r14
  hkPackfileData::Chunk *m_data; // rax
  unsigned int numBytes; // edi
  void *pointer; // rsi
  _QWORD **v11; // rax
  char *m_name; // rdi
  hkMemoryAllocator **v13; // rax
  int m_capacityAndFlags; // r8d
  int v15; // r8d
  int v16; // r8d
  int v17; // r8d
  int v18; // r8d
  hkClassNameRegistry *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkPackfileData::`vftable;
  hkPackfileData::callDestructors(this);
  v2 = 0;
  if ( this->m_memory.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_memory.m_data[v3];
      Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      hkMemoryRouter::easyFree(Value[11], v4);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_memory.m_size );
  }
  v6 = 0;
  if ( this->m_chunks.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      m_data = this->m_chunks.m_data;
      numBytes = m_data[v7].numBytes;
      pointer = m_data[v7].pointer;
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v11[11] + 16i64))(v11[11], pointer, numBytes);
      ++v6;
      ++v7;
    }
    while ( v6 < this->m_chunks.m_size );
  }
  m_name = this->m_name;
  v13 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::easyFree(v13[11], m_name);
  m_capacityAndFlags = this->m_postFinishObjects.m_capacityAndFlags;
  this->m_postFinishObjects.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_postFinishObjects.m_data,
      16 * m_capacityAndFlags);
  this->m_postFinishObjects.m_data = 0i64;
  this->m_postFinishObjects.m_capacityAndFlags = 0x80000000;
  v15 = this->m_imports.m_capacityAndFlags;
  this->m_imports.m_size = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_imports.m_data,
      16 * v15);
  this->m_imports.m_data = 0i64;
  this->m_imports.m_capacityAndFlags = 0x80000000;
  v16 = this->m_exports.m_capacityAndFlags;
  this->m_exports.m_size = 0;
  if ( v16 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_exports.m_data,
      16 * v16);
  this->m_exports.m_data = 0i64;
  this->m_exports.m_capacityAndFlags = 0x80000000;
  v17 = this->m_chunks.m_capacityAndFlags;
  this->m_chunks.m_size = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_chunks.m_data,
      16 * v17);
  this->m_chunks.m_data = 0i64;
  this->m_chunks.m_capacityAndFlags = 0x80000000;
  v18 = this->m_memory.m_capacityAndFlags;
  this->m_memory.m_size = 0;
  if ( v18 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_memory.m_data, 8 * v18);
  this->m_memory.m_data = 0i64;
  this->m_memory.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_packfileClassRegistry.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_packfileClassRegistry.m_pntr = 0i64;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_trackedTypes.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_trackedObjects.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_trackedObjects);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 77
// RVA: 0xE64E00
void __fastcall hkPackfileData::setName(hkPackfileData *this, char *n)
{
  char *m_name; // rbx
  hkMemoryAllocator **Value; // rax

  m_name = this->m_name;
  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::easyFree(Value[11], m_name);
  this->m_name = hkString::strDup(n);
}

// File Line: 83
// RVA: 0xE64C50
void __fastcall hkPackfileData::getImportsExports(
        hkPackfileData *this,
        hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut,
        hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut)
{
  int m_size; // ebp
  int v5; // ebx
  int v7; // eax
  int v9; // eax
  int v10; // r9d
  hkResource::Import *m_data; // rcx
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
  int v22; // r9d
  hkResource::Export *v23; // rcx
  char *v24; // r8
  __int64 v25; // rdx
  const char *v26; // rax
  hkResource::Export *v27; // rax
  __int64 v28; // rdx
  signed __int64 v29; // r8
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = this->m_imports.m_size;
  v5 = m_size;
  if ( m_size > impOut->m_size )
    v5 = impOut->m_size;
  v7 = impOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < m_size )
  {
    v9 = 2 * v7;
    v10 = this->m_imports.m_size;
    if ( m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&impOut->m_data, v10, 16);
  }
  m_data = impOut->m_data;
  if ( v5 > 0 )
  {
    v12 = (char *)((char *)this->m_imports.m_data - (char *)m_data);
    v13 = v5;
    do
    {
      v14 = *(const char **)((char *)&m_data->name + (_QWORD)v12);
      ++m_data;
      m_data[-1].name = v14;
      m_data[-1].location = *(void ***)((char *)m_data + (_QWORD)v12 - 8);
      --v13;
    }
    while ( v13 );
  }
  v15 = &impOut->m_data[v5];
  v16 = m_size - v5;
  if ( m_size - v5 > 0 )
  {
    v17 = (char *)this->m_imports.m_data - (char *)impOut->m_data;
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
  impOut->m_size = m_size;
  v18 = this->m_exports.m_size;
  v19 = v18;
  if ( v18 > expOut->m_size )
    v19 = expOut->m_size;
  v20 = expOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < v18 )
  {
    v21 = 2 * v20;
    v22 = this->m_exports.m_size;
    if ( v18 < v21 )
      v22 = v21;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&expOut->m_data, v22, 16);
  }
  v23 = expOut->m_data;
  if ( v19 > 0 )
  {
    v24 = (char *)((char *)this->m_exports.m_data - (char *)v23);
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
  v27 = &expOut->m_data[v19];
  v28 = v18 - v19;
  if ( v18 - v19 > 0 )
  {
    v29 = (char *)this->m_exports.m_data - (char *)expOut->m_data;
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
  expOut->m_size = v18;
}

// File Line: 89
// RVA: 0xE65030
void __fastcall hkPackfileData::addExport(hkPackfileData *this, const char *symbolName, void *object)
{
  hkArray<hkResource::Export,hkContainerHeapAllocator> *p_m_exports; // rbx
  hkResource::Export *v6; // rcx

  p_m_exports = &this->m_exports;
  if ( this->m_exports.m_size == (this->m_exports.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_exports->m_data, 16);
  v6 = &p_m_exports->m_data[p_m_exports->m_size++];
  v6->name = symbolName;
  v6->data = object;
}

// File Line: 96
// RVA: 0xE650A0
void __fastcall hkPackfileData::removeExport(hkPackfileData *this, void *object)
{
  int v4; // r11d
  __int64 v5; // rbx
  __int64 v6; // r10
  hkResource::Export *m_data; // rax
  __int64 v8; // rcx
  __int64 v9; // rdx
  hkResource::Export *v10; // r8
  hkResource::Export *v11; // rax
  signed __int64 v12; // r8
  void *v13; // rcx

  v4 = this->m_exports.m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = v4;
    do
    {
      m_data = this->m_exports.m_data;
      if ( m_data[v6].data == object )
      {
        v8 = --this->m_exports.m_size;
        if ( (_DWORD)v8 != v4 )
        {
          v9 = 2i64;
          v10 = &m_data[v8];
          v11 = &m_data[v6];
          v12 = (char *)v10 - (char *)v11;
          do
          {
            v13 = *(void **)((char *)&v11->name + v12);
            v11 = (hkResource::Export *)((char *)v11 + 8);
            v11[-1].data = v13;
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
  hkArray<hkResource::Import,hkContainerHeapAllocator> *p_m_imports; // rbx
  hkResource::Import *v6; // rcx

  p_m_imports = &this->m_imports;
  if ( this->m_imports.m_size == (this->m_imports.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_imports->m_data, 16);
  v6 = &p_m_imports->m_data[p_m_imports->m_size++];
  v6->name = symbolName;
  v6->location = location;
}

// File Line: 122
// RVA: 0xE651B0
void __fastcall hkPackfileData::removeImport(hkPackfileData *this, void **location)
{
  int v3; // r10d
  __int64 v4; // r9
  void ***i; // rdx
  __int64 v6; // rdx
  hkResource::Import *v7; // rax
  __int64 v8; // r8
  void **v9; // rcx

  v3 = this->m_imports.m_size - 1;
  v4 = v3;
  if ( v3 >= 0 )
  {
    for ( i = &this->m_imports.m_data[v3].location; *i != location; i -= 2 )
    {
      --v3;
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
  hkClass *v5; // rbx
  hkClass *v6; // rax
  hkBool result; // [rsp+40h] [rbp+18h] BYREF

  v5 = (hkClass *)classReg->vfptr[2].__vecDelDtor(classReg, topLevelClassName);
  v6 = (hkClass *)classReg->vfptr[2].__vecDelDtor(classReg, typeName);
  return hkClass::isSuperClass(v6, &result, v5)->m_bool != 0;
}

// File Line: 151
// RVA: 0xE64E60
void *__fastcall hkPackfileData::getContentsPointer(
        hkPackfileData *this,
        const char *typeName,
        hkTypeInfoRegistry *typeRegistry)
{
  void *m_topLevelObject; // rdx
  unsigned __int64 v7; // rax
  hkClassNameRegistry *m_pntr; // rdi
  hkClass *v9; // rbx
  hkClass *v10; // rax
  __int64 m_hashMod; // r8
  int v12; // edx
  char v13; // bl
  __int64 v14; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v16; // edi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v17; // rax
  const char *val; // rbp
  unsigned __int64 v19; // rax
  __int64 v20; // r8
  int v21; // edx
  __int64 v22; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v23; // rax
  hkVariant *m_data; // rdi
  void *m_object; // rbx
  hkVariant *Attribute; // rax
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  m_topLevelObject = this->m_topLevelObject;
  if ( m_topLevelObject )
  {
    v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
           &this->m_trackedObjects.m_map,
           (unsigned __int64)m_topLevelObject,
           0i64);
    if ( !typeName
      || (m_pntr = this->m_packfileClassRegistry.m_pntr,
          v9 = (hkClass *)m_pntr->vfptr[2].__vecDelDtor(m_pntr, v7),
          v10 = (hkClass *)m_pntr->vfptr[2].__vecDelDtor(m_pntr, (unsigned int)typeName),
          hkClass::isSuperClass(v10, &result, v9)->m_bool) )
    {
      if ( hkPackfileData::finishedObjects(this) || !typeRegistry )
        return this->m_topLevelObject;
      m_hashMod = this->m_trackedObjects.m_map.m_hashMod;
      v12 = 0;
      v13 = 0;
      v14 = 0i64;
      if ( m_hashMod >= 0 )
      {
        m_elem = this->m_trackedObjects.m_map.m_elem;
        do
        {
          if ( m_elem->key != -1i64 )
            break;
          ++v14;
          ++v12;
          ++m_elem;
        }
        while ( v14 <= m_hashMod );
      }
      v16 = v12;
      if ( v12 > this->m_trackedObjects.m_map.m_hashMod )
        goto LABEL_20;
      do
      {
        v17 = this->m_trackedObjects.m_map.m_elem;
        val = (const char *)v17[v16].val;
        v19 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, unsigned __int64, const char *))typeRegistry->vfptr[2].__vecDelDtor)(
                typeRegistry,
                v17[v16].key,
                val);
        if ( v19 )
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_trackedTypes.m_map, val, v19);
        else
          v13 = 1;
        v20 = this->m_trackedObjects.m_map.m_hashMod;
        v21 = v16 + 1;
        v22 = v16 + 1;
        if ( v22 <= v20 )
        {
          v23 = &this->m_trackedObjects.m_map.m_elem[v21];
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
      while ( v21 <= this->m_trackedObjects.m_map.m_hashMod );
      if ( !v13 )
      {
LABEL_20:
        m_data = this->m_postFinishObjects.m_data;
        if ( m_data < &m_data[this->m_postFinishObjects.m_size] )
        {
          do
          {
            m_object = m_data->m_object;
            Attribute = hkClass::getAttribute(m_data->m_class, "hk.PostFinish");
            (*(void (__fastcall **)(void *))Attribute->m_object)(m_object);
            ++m_data;
          }
          while ( m_data < &this->m_postFinishObjects.m_data[this->m_postFinishObjects.m_size] );
        }
        return this->m_topLevelObject;
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
  void *m_topLevelObject; // rdx

  m_topLevelObject = this->m_topLevelObject;
  if ( m_topLevelObject )
    return (const char *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                           &this->m_trackedObjects.m_map,
                           (unsigned __int64)m_topLevelObject,
                           0i64);
  else
    return 0i64;
}

// File Line: 227
// RVA: 0xE65250
void __fastcall hkPackfileData::setPackfileClassNameRegistry(hkPackfileData *this, hkClassNameRegistry *classReg)
{
  hkClassNameRegistry *m_pntr; // rcx

  if ( classReg )
    hkReferencedObject::addReference(classReg);
  m_pntr = this->m_packfileClassRegistry.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_packfileClassRegistry.m_pntr = classReg;
}

