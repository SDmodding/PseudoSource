// File Line: 16
// RVA: 0xE5D200
void __fastcall hkPlatformObjectWriter::Cache::Cache(hkPlatformObjectWriter::Cache *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkPlatformObjectWriter::Cache::`vftable;
  this->m_platformClassFromHostClass.m_map.m_hashMod = -1;
  this->m_platformClassFromHostClass.m_map.m_elem = 0i64;
  this->m_platformClassFromHostClass.m_map.m_numElems = 0;
  this->m_platformClassComputed.m_map.m_elem = 0i64;
  this->m_platformClassComputed.m_map.m_numElems = 0;
  this->m_platformClassComputed.m_map.m_hashMod = -1;
  this->m_allocations.m_data = 0i64;
  this->m_allocations.m_size = 0;
  this->m_allocations.m_capacityAndFlags = 0x80000000;
}

// File Line: 20
// RVA: 0xE5D250
void __fastcall hkPlatformObjectWriter::Cache::~Cache(hkPlatformObjectWriter::Cache *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkPlatformObjectWriter::Cache::`vftable;
  if ( this->m_allocations.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkDeepCopier::freeDeepCopy(&result, this->m_allocations.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_allocations.m_size );
  }
  m_capacityAndFlags = this->m_allocations.m_capacityAndFlags;
  this->m_allocations.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_allocations.m_data,
      8 * m_capacityAndFlags);
  this->m_allocations.m_data = 0i64;
  this->m_allocations.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_platformClassComputed.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_platformClassComputed);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_platformClassFromHostClass.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_platformClassFromHostClass);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 28
// RVA: 0xE5D330
hkClass *__fastcall hkPlatformObjectWriter::Cache::get(
        hkPlatformObjectWriter::Cache *this,
        hkClass *klass,
        hkStructureLayout *layout)
{
  hkClass *v7; // rdi
  hkResult result; // [rsp+50h] [rbp+8h] BYREF
  unsigned __int64 out; // [rsp+68h] [rbp+20h] BYREF

  if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
         &this->m_platformClassFromHostClass.m_map,
         &result,
         (unsigned __int64)klass,
         &out)->m_enum == HK_SUCCESS )
    return (hkClass *)out;
  v7 = (hkClass *)hkDeepCopier::deepCopy(klass, &hkClassClass, &this->m_platformClassFromHostClass, 0i64, 0i64, 0);
  if ( this->m_allocations.m_size == (this->m_allocations.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_allocations.m_data, 8);
  this->m_allocations.m_data[this->m_allocations.m_size++] = v7;
  hkStructureLayout::computeMemberOffsetsInplace(layout, v7, &this->m_platformClassComputed, 1u);
  return v7;
}

// File Line: 42
// RVA: 0xE5D400
void __fastcall hkPlatformObjectWriter::hkPlatformObjectWriter(
        hkPlatformObjectWriter *this,
        hkStructureLayout *layout,
        hkPlatformObjectWriter::Cache *cache,
        hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  _QWORD **Value; // rax
  hkPlatformObjectWriter::Cache *v8; // rdi
  hkObjectCopier *v9; // rbp
  hkObjectCopier *v10; // rax
  hkStructureLayout *v11; // rax
  _QWORD **v12; // rax
  hkPlatformObjectWriter::Cache *v13; // rax
  hkPlatformObjectWriter::Cache *v14; // rax
  hkStructureLayout layoutIn; // [rsp+40h] [rbp+8h] BYREF
  hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flagsa; // [rsp+58h] [rbp+20h]

  flagsa.m_storage = flags.m_storage;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkPlatformObjectWriter::`vftable;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = 0i64;
  v9 = (hkObjectCopier *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( v9 )
  {
    hkStructureLayout::hkStructureLayout(&layoutIn, (hkStructureLayout *)&hkStructureLayout::HostLayoutRules);
    hkObjectCopier::hkObjectCopier(v9, &layoutIn, layout, flagsa);
  }
  else
  {
    v10 = 0i64;
  }
  this->m_copier = v10;
  v11 = hkPlatformObjectWriter::getLayout(this);
  if ( v11->m_rules.m_bytesInPointer != hkStructureLayout::HostLayoutRules.m_bytesInPointer
    || v11->m_rules.m_littleEndian != hkStructureLayout::HostLayoutRules.m_littleEndian
    || v11->m_rules.m_reusePaddingOptimization != hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization
    || v11->m_rules.m_emptyBaseClassOptimization != hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization )
  {
    if ( cache )
    {
      hkReferencedObject::addReference(cache);
      this->m_cache = cache;
      return;
    }
    v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkPlatformObjectWriter::Cache *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v12[11] + 8i64))(
                                             v12[11],
                                             64i64);
    if ( v13 )
    {
      hkPlatformObjectWriter::Cache::Cache(v13);
      v8 = v14;
    }
  }
  this->m_cache = v8;
}

// File Line: 66
// RVA: 0xE5D520
void __fastcall hkPlatformObjectWriter::~hkPlatformObjectWriter(hkPlatformObjectWriter *this)
{
  hkPlatformObjectWriter::Cache *m_cache; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkPlatformObjectWriter::`vftable;
  hkReferencedObject::removeReference(this->m_copier);
  m_cache = this->m_cache;
  if ( m_cache )
    hkReferencedObject::removeReference(m_cache);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 77
// RVA: 0xE5D560
hkResult *__fastcall hkPlatformObjectWriter::writeObject(
        hkPlatformObjectWriter *this,
        hkResult *result,
        hkOffsetOnlyStreamWriter *writer,
        hkClass *dataIn,
        hkClass *klass,
        hkRelocationInfo *reloc)
{
  hkPlatformObjectWriter::Cache *m_cache; // rbx
  hkStructureLayout *Layout; // rax
  hkClass *v12; // rsi
  hkClass *v13; // rbp
  hkResultEnum v14; // r14d
  const char *Name; // rax
  hkStructureLayout *v16; // rax
  hkStructureLayout *v17; // rax
  hkClass *v18; // rbx
  int v19; // eax
  hkObjectCopier *m_copier; // rcx
  hkResult *v21; // rax
  hkOffsetOnlyStreamWriter v22; // [rsp+40h] [rbp-98h] BYREF
  hkRelocationInfo v23; // [rsp+60h] [rbp-78h] BYREF
  hkResult resulta; // [rsp+E0h] [rbp+8h] BYREF

  m_cache = this->m_cache;
  if ( m_cache )
  {
    Layout = hkPlatformObjectWriter::getLayout(this);
    v12 = klass;
    v13 = hkPlatformObjectWriter::Cache::get(m_cache, klass, Layout);
  }
  else
  {
    v12 = klass;
    v13 = klass;
  }
  hkOffsetOnlyStreamWriter::hkOffsetOnlyStreamWriter(&v22);
  v14 = HK_SUCCESS;
  if ( this->m_cache )
  {
    Name = hkClass::getName(v13);
    if ( !(unsigned int)hkString::strCmp(Name, "hkClass") )
    {
      v16 = hkPlatformObjectWriter::getLayout(this);
      v13 = hkPlatformObjectWriter::Cache::get(this->m_cache, &hkClassClass, v16);
      v17 = hkPlatformObjectWriter::getLayout(this);
      v18 = hkPlatformObjectWriter::Cache::get(this->m_cache, dataIn, v17);
      v19 = ((__int64 (__fastcall *)(hkOffsetOnlyStreamWriter *))writer->vfptr[4].__vecDelDtor)(writer);
      hkOffsetOnlyStreamWriter::seek(&v22, &resulta, v19, STREAM_NULL);
      m_copier = this->m_copier;
      v23.m_local.m_data = 0i64;
      v23.m_local.m_size = 0;
      v23.m_local.m_capacityAndFlags = 0x80000000;
      v23.m_global.m_data = 0i64;
      v23.m_global.m_size = 0;
      v23.m_global.m_capacityAndFlags = 0x80000000;
      v23.m_finish.m_data = 0i64;
      v23.m_finish.m_size = 0;
      v23.m_finish.m_capacityAndFlags = 0x80000000;
      v23.m_imports.m_data = 0i64;
      v23.m_imports.m_size = 0;
      v23.m_imports.m_capacityAndFlags = 0x80000000;
      v23.m_pool = 0i64;
      ((void (__fastcall *)(hkObjectCopier *, hkResult *, hkClass *, hkClass *, hkOffsetOnlyStreamWriter *, hkClass *, hkRelocationInfo *))m_copier->vfptr[1].__first_virtual_table_function__)(
        m_copier,
        &resulta,
        v18,
        v12,
        writer,
        v13,
        &v23);
      writer = &v22;
      hkRelocationInfo::~hkRelocationInfo(&v23);
    }
  }
  ((void (__fastcall *)(hkObjectCopier *, hkResult *, hkClass *, hkClass *, hkOffsetOnlyStreamWriter *, hkClass *, hkRelocationInfo *))this->m_copier->vfptr[1].__first_virtual_table_function__)(
    this->m_copier,
    &resulta,
    dataIn,
    v12,
    writer,
    v13,
    reloc);
  LOBYTE(v14) = *(_BYTE *)((__int64 (__fastcall *)(hkOffsetOnlyStreamWriter *, hkResult *))writer->vfptr[1].__first_virtual_table_function__)(
                            writer,
                            &resulta) == 0;
  v21 = result;
  result->m_enum = v14;
  return v21;
}

// File Line: 114
// RVA: 0xE5D770
hkResult *__fastcall hkPlatformObjectWriter::writeRaw(
        hkPlatformObjectWriter *this,
        hkResult *result,
        hkStreamWriter *writer,
        const void *data,
        unsigned int dataLen)
{
  bool v6; // zf
  hkResult *v7; // rax

  v6 = ((unsigned int (__fastcall *)(hkStreamWriter *, const void *, _QWORD))writer->vfptr[2].__vecDelDtor)(
         writer,
         data,
         dataLen) == dataLen;
  v7 = result;
  result->m_enum = !v6;
  return v7;
}

// File Line: 121
// RVA: 0xE5D7B0
hkStructureLayout *__fastcall hkPlatformObjectWriter::getLayout(hkPlatformObjectWriter *this)
{
  return &this->m_copier->m_layoutOut;
}

