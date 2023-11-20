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
  this->m_allocations.m_capacityAndFlags = 2147483648;
}

// File Line: 20
// RVA: 0xE5D250
void __fastcall hkPlatformObjectWriter::Cache::~Cache(hkPlatformObjectWriter::Cache *this)
{
  int v1; // esi
  hkPlatformObjectWriter::Cache *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8
  hkResult result; // [rsp+30h] [rbp+8h]

  v1 = 0;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkPlatformObjectWriter::Cache::`vftable;
  if ( this->m_allocations.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkDeepCopier::freeDeepCopy(&result, v2->m_allocations.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_allocations.m_size );
  }
  v4 = v2->m_allocations.m_capacityAndFlags;
  v2->m_allocations.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_allocations.m_data,
      8 * v4);
  v2->m_allocations.m_data = 0i64;
  v2->m_allocations.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_platformClassComputed.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v2->m_platformClassComputed);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_platformClassFromHostClass.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v2->m_platformClassFromHostClass);
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 28
// RVA: 0xE5D330
hkClass *__fastcall hkPlatformObjectWriter::Cache::get(hkPlatformObjectWriter::Cache *this, hkClass *klass, hkStructureLayout *layout)
{
  hkStructureLayout *v3; // rbp
  hkClass *v4; // rbx
  hkPlatformObjectWriter::Cache *v5; // rsi
  hkClass *v7; // rdi
  hkResult result; // [rsp+50h] [rbp+8h]
  unsigned __int64 out; // [rsp+68h] [rbp+20h]

  v3 = layout;
  v4 = klass;
  v5 = this;
  if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_platformClassFromHostClass.m_map.m_elem,
         &result,
         (unsigned __int64)klass,
         &out)->m_enum == HK_SUCCESS )
    return (hkClass *)out;
  v7 = (hkClass *)hkDeepCopier::deepCopy(v4, &hkClassClass, &v5->m_platformClassFromHostClass, 0i64, 0i64, 0);
  if ( v5->m_allocations.m_size == (v5->m_allocations.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_allocations, 8);
  v5->m_allocations.m_data[v5->m_allocations.m_size++] = v7;
  hkStructureLayout::computeMemberOffsetsInplace(v3, v7, &v5->m_platformClassComputed, 1u);
  return v7;
}

// File Line: 42
// RVA: 0xE5D400
void __fastcall hkPlatformObjectWriter::hkPlatformObjectWriter(hkPlatformObjectWriter *this, hkStructureLayout *layout, hkPlatformObjectWriter::Cache *cache, hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  hkPlatformObjectWriter *v4; // rbx
  hkPlatformObjectWriter::Cache *v5; // rsi
  hkStructureLayout *v6; // r14
  _QWORD **v7; // rax
  hkPlatformObjectWriter::Cache *v8; // rdi
  hkObjectCopier *v9; // rbp
  hkObjectCopier *v10; // rax
  hkStructureLayout *v11; // rax
  _QWORD **v12; // rax
  hkPlatformObjectWriter::Cache *v13; // rax
  hkPlatformObjectWriter::Cache *v14; // rax
  hkStructureLayout layoutIn; // [rsp+40h] [rbp+8h]
  hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flagsa; // [rsp+58h] [rbp+20h]

  flagsa.m_storage = flags.m_storage;
  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkPlatformObjectWriter::`vftable;
  v5 = cache;
  v6 = layout;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = 0i64;
  v9 = (hkObjectCopier *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 32i64);
  if ( v9 )
  {
    hkStructureLayout::hkStructureLayout(&layoutIn, &hkStructureLayout::HostLayoutRules);
    hkObjectCopier::hkObjectCopier(v9, &layoutIn, v6, flagsa);
  }
  else
  {
    v10 = 0i64;
  }
  v4->m_copier = v10;
  v11 = hkPlatformObjectWriter::getLayout(v4);
  if ( v11->m_rules.m_bytesInPointer != hkStructureLayout::HostLayoutRules.m_bytesInPointer
    || v11->m_rules.m_littleEndian != hkStructureLayout::HostLayoutRules.m_littleEndian
    || v11->m_rules.m_reusePaddingOptimization != hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization
    || v11->m_rules.m_emptyBaseClassOptimization != hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization )
  {
    if ( v5 )
    {
      hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
      v4->m_cache = v5;
      return;
    }
    v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkPlatformObjectWriter::Cache *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(
                                             v12[11],
                                             64i64);
    if ( v13 )
    {
      hkPlatformObjectWriter::Cache::Cache(v13);
      v8 = v14;
    }
  }
  v4->m_cache = v8;
}

// File Line: 66
// RVA: 0xE5D520
void __fastcall hkPlatformObjectWriter::~hkPlatformObjectWriter(hkPlatformObjectWriter *this)
{
  hkPlatformObjectWriter *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkPlatformObjectWriter::`vftable;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_copier->vfptr);
  v2 = (hkReferencedObject *)&v1->m_cache->vfptr;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 77
// RVA: 0xE5D560
hkResult *__fastcall hkPlatformObjectWriter::writeObject(hkPlatformObjectWriter *this, hkResult *result, hkStreamWriter *writer, const void *dataIn, hkClass *klass, hkRelocationInfo *reloc)
{
  hkPlatformObjectWriter::Cache *v6; // rbx
  hkClass *v7; // r13
  hkOffsetOnlyStreamWriter *v8; // r15
  hkResult *v9; // r12
  hkPlatformObjectWriter *v10; // rdi
  hkStructureLayout *v11; // rax
  hkClass *v12; // rsi
  hkClass *v13; // rbp
  hkResultEnum v14; // er14
  const char *v15; // rax
  hkStructureLayout *v16; // rax
  hkStructureLayout *v17; // rax
  hkClass *v18; // rbx
  int v19; // eax
  hkObjectCopier *v20; // rcx
  hkResult *v21; // rax
  hkOffsetOnlyStreamWriter v22; // [rsp+40h] [rbp-98h]
  hkRelocationInfo v23; // [rsp+60h] [rbp-78h]
  hkResult resulta; // [rsp+E0h] [rbp+8h]

  v6 = this->m_cache;
  v7 = (hkClass *)dataIn;
  v8 = (hkOffsetOnlyStreamWriter *)writer;
  v9 = result;
  v10 = this;
  if ( v6 )
  {
    v11 = hkPlatformObjectWriter::getLayout(this);
    v12 = klass;
    v13 = hkPlatformObjectWriter::Cache::get(v6, klass, v11);
  }
  else
  {
    v12 = klass;
    v13 = klass;
  }
  hkOffsetOnlyStreamWriter::hkOffsetOnlyStreamWriter(&v22);
  v14 = 0;
  if ( v10->m_cache )
  {
    v15 = hkClass::getName(v13);
    if ( !(unsigned int)hkString::strCmp(v15, "hkClass") )
    {
      v16 = hkPlatformObjectWriter::getLayout(v10);
      v13 = hkPlatformObjectWriter::Cache::get(v10->m_cache, &hkClassClass, v16);
      v17 = hkPlatformObjectWriter::getLayout(v10);
      v18 = hkPlatformObjectWriter::Cache::get(v10->m_cache, v7, v17);
      v19 = ((__int64 (__fastcall *)(hkOffsetOnlyStreamWriter *))v8->vfptr[4].__vecDelDtor)(v8);
      hkOffsetOnlyStreamWriter::seek(&v22, &resulta, v19, 0);
      v20 = v10->m_copier;
      v23.m_local.m_data = 0i64;
      v23.m_local.m_size = 0;
      v23.m_local.m_capacityAndFlags = 2147483648;
      v23.m_global.m_data = 0i64;
      v23.m_global.m_size = 0;
      v23.m_global.m_capacityAndFlags = 2147483648;
      v23.m_finish.m_data = 0i64;
      v23.m_finish.m_size = 0;
      v23.m_finish.m_capacityAndFlags = 2147483648;
      v23.m_imports.m_data = 0i64;
      v23.m_imports.m_size = 0;
      v23.m_imports.m_capacityAndFlags = 2147483648;
      v23.m_pool = 0i64;
      ((void (__fastcall *)(hkObjectCopier *, hkResult *, hkClass *, hkClass *, hkOffsetOnlyStreamWriter *, hkClass *, hkRelocationInfo *))v20->vfptr[1].__first_virtual_table_function__)(
        v20,
        &resulta,
        v18,
        v12,
        v8,
        v13,
        &v23);
      v8 = &v22;
      hkRelocationInfo::~hkRelocationInfo(&v23);
    }
  }
  ((void (__fastcall *)(hkObjectCopier *, hkResult *, hkClass *, hkClass *, hkOffsetOnlyStreamWriter *, hkClass *, hkRelocationInfo *))v10->m_copier->vfptr[1].__first_virtual_table_function__)(
    v10->m_copier,
    &resulta,
    v7,
    v12,
    v8,
    v13,
    reloc);
  LOBYTE(v14) = *(_BYTE *)((__int64 (__fastcall *)(hkOffsetOnlyStreamWriter *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                            v8,
                            &resulta) == 0;
  v21 = v9;
  v9->m_enum = v14;
  return v21;
}

// File Line: 114
// RVA: 0xE5D770
hkResult *__fastcall hkPlatformObjectWriter::writeRaw(hkPlatformObjectWriter *this, hkResult *result, hkStreamWriter *writer, const void *data, int dataLen)
{
  hkResult *v5; // rdi
  bool v6; // zf
  hkResult *v7; // rax

  v5 = result;
  v6 = ((unsigned int (__fastcall *)(hkStreamWriter *, const void *, _QWORD))writer->vfptr[2].__vecDelDtor)(
         writer,
         data,
         (unsigned int)dataLen) == dataLen;
  v7 = v5;
  v5->m_enum = !v6;
  return v7;
}

// File Line: 121
// RVA: 0xE5D7B0
hkStructureLayout *__fastcall hkPlatformObjectWriter::getLayout(hkPlatformObjectWriter *this)
{
  return &this->m_copier->m_layoutOut;
}

