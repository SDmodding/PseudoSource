// File Line: 23
// RVA: 0xE73EA0
__int64 __fastcall hkObjectSerialize::readObject(
        hkStreamReader *s,
        void **data,
        unsigned int *dataSize,
        hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> *globalFixups,
        unsigned __int64 *klassID)
{
  hkBaseObjectVtbl *vfptr; // rax
  int v11; // ecx
  int v12; // edi
  int v13; // esi
  char *v14; // rdi
  int v15; // ecx
  int v16; // eax
  int v17; // edi
  int v18; // eax
  int v19; // esi
  hkObjectSerialize::GlobalFixup *v20; // rdi
  int v21; // edi
  hkMemoryAllocator **Value; // rax
  char *v23; // rdi
  hkMemoryAllocator **v24; // rax
  __int64 v25; // rbx
  unsigned int v26; // ecx
  unsigned int v27; // edx
  __int64 v28; // r8
  __int64 v29; // r9
  int v30; // [rsp+30h] [rbp-20h] BYREF
  unsigned int v31; // [rsp+34h] [rbp-1Ch] BYREF
  __int64 v32; // [rsp+38h] [rbp-18h] BYREF
  char *array; // [rsp+40h] [rbp-10h] BYREF
  int v34; // [rsp+48h] [rbp-8h]
  int v35; // [rsp+4Ch] [rbp-4h]
  hkResult result; // [rsp+80h] [rbp+30h] BYREF

  ((void (__fastcall *)(hkStreamReader *, __int64 *, __int64))s->vfptr[2].__vecDelDtor)(s, &v32, 8i64);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))s->vfptr[1].__first_virtual_table_function__)(
                    s,
                    &result) )
    return 0i64;
  ((void (__fastcall *)(hkStreamReader *, unsigned __int64 *, __int64))s->vfptr[2].__vecDelDtor)(s, klassID, 8i64);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))s->vfptr[1].__first_virtual_table_function__)(
                    s,
                    &result) )
    return 0i64;
  vfptr = s->vfptr;
  array = 0i64;
  v34 = 0;
  v35 = 0x80000000;
  ((void (__fastcall *)(hkStreamReader *, int *, __int64))vfptr[2].__vecDelDtor)(s, &v30, 4i64);
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))s->vfptr[1].__first_virtual_table_function__)(
                   s,
                   &result) )
  {
    v11 = v30;
    v12 = v30;
    if ( (v35 & 0x3FFFFFFF) < v30 )
    {
      if ( v30 < 2 * (v35 & 0x3FFFFFFF) )
        v11 = 2 * (v35 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v11, 8);
      v11 = v30;
    }
    v13 = 0;
    v34 = v12;
    if ( v11 )
    {
      while ( 1 )
      {
        v14 = &array[8 * v13];
        ((void (__fastcall *)(hkStreamReader *, char *, __int64))s->vfptr[2].__vecDelDtor)(s, v14, 4i64);
        ((void (__fastcall *)(hkStreamReader *, char *, __int64))s->vfptr[2].__vecDelDtor)(s, v14 + 4, 4i64);
        if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))s->vfptr[1].__first_virtual_table_function__)(
                          s,
                          &result) )
          break;
        if ( ++v13 >= (unsigned int)v30 )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      ((void (__fastcall *)(hkStreamReader *, unsigned int *, __int64))s->vfptr[2].__vecDelDtor)(s, &v31, 4i64);
      if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))s->vfptr[1].__first_virtual_table_function__)(
                       s,
                       &result) )
      {
        v15 = v31;
        v16 = globalFixups->m_capacityAndFlags & 0x3FFFFFFF;
        v17 = v31;
        if ( v16 < (int)v31 )
        {
          v18 = 2 * v16;
          if ( (int)v31 < v18 )
            v15 = v18;
          hkArrayUtil::_reserve(
            &result,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&globalFixups->m_data,
            v15,
            24);
          v15 = v31;
        }
        v19 = 0;
        globalFixups->m_size = v17;
        if ( v15 )
        {
          while ( 1 )
          {
            v20 = &globalFixups->m_data[v19];
            ((void (__fastcall *)(hkStreamReader *, hkObjectSerialize::GlobalFixup *, __int64))s->vfptr[2].__vecDelDtor)(
              s,
              v20,
              4i64);
            ((void (__fastcall *)(hkStreamReader *, unsigned __int64 *, __int64))s->vfptr[2].__vecDelDtor)(
              s,
              &v20->toID,
              8i64);
            ((void (__fastcall *)(hkStreamReader *, unsigned __int64 *, __int64))s->vfptr[2].__vecDelDtor)(
              s,
              &v20->toClassID,
              8i64);
            if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))s->vfptr[1].__first_virtual_table_function__)(
                              s,
                              &result) )
              break;
            if ( ++v19 >= v31 )
              goto LABEL_20;
          }
        }
        else
        {
LABEL_20:
          ((void (__fastcall *)(hkStreamReader *, unsigned int *, __int64))s->vfptr[2].__vecDelDtor)(s, dataSize, 4i64);
          if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))s->vfptr[1].__first_virtual_table_function__)(
                           s,
                           &result) )
          {
            v21 = *dataSize;
            Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v23 = (char *)hkMemoryRouter::easyAlloc(Value[11], v21);
            ((void (__fastcall *)(hkStreamReader *, char *, _QWORD))s->vfptr[2].__vecDelDtor)(s, v23, *dataSize);
            if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))s->vfptr[1].__first_virtual_table_function__)(
                             s,
                             &result) )
            {
              v26 = v30;
              v27 = 0;
              if ( v30 )
              {
                v28 = 0i64;
                do
                {
                  v29 = *(int *)&array[v28];
                  if ( (int)v29 >= 0 )
                  {
                    *(_QWORD *)&v23[v29] = &v23[*(int *)&array[v28 + 4]];
                    v26 = v30;
                  }
                  ++v27;
                  v28 += 8i64;
                }
                while ( v27 < v26 );
              }
              v25 = v32;
              *data = v23;
              goto LABEL_24;
            }
            v24 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            hkMemoryRouter::easyFree(v24[11], v23);
          }
        }
      }
    }
  }
  v25 = 0i64;
LABEL_24:
  v34 = 0;
  if ( v35 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v35);
  return v25;
}

// File Line: 100
// RVA: 0xE74C00
__int64 __fastcall writeData(
        hkStreamWriter *s,
        __int64 dataID,
        __int64 classID,
        void *data,
        unsigned int dataSize,
        hkRelocationInfo *reloc,
        unsigned int endianSwap)
{
  unsigned int m_size; // r12d
  unsigned int v12; // edi
  int v13; // ebx
  unsigned int v14; // esi
  __int64 v15; // r14
  unsigned int v16; // r14d
  int v17; // ebx
  __int64 v18; // rsi
  int v19; // ebx
  unsigned int v20; // ebx
  hkOArchive v22; // [rsp+20h] [rbp-48h] BYREF

  hkOArchive::hkOArchive(&v22, s, (hkBool)(endianSwap != 0));
  hkOArchive::write64u(&v22, dataID);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))s->vfptr[1].__first_virtual_table_function__)(
                    s,
                    &endianSwap) )
    goto LABEL_14;
  hkOArchive::write64u(&v22, classID);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))s->vfptr[1].__first_virtual_table_function__)(
                    s,
                    &endianSwap) )
    goto LABEL_14;
  m_size = reloc->m_local.m_size;
  hkOArchive::write32u(&v22, m_size);
  v12 = 0;
  v13 = 20;
  v14 = 0;
  if ( m_size )
  {
    v15 = 0i64;
    do
    {
      hkOArchive::write32(&v22, reloc->m_local.m_data[v15].m_fromOffset);
      hkOArchive::write32(&v22, reloc->m_local.m_data[v15].m_toOffset);
      if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))s->vfptr[1].__first_virtual_table_function__)(
                        s,
                        &endianSwap) )
        goto LABEL_14;
      ++v14;
      v13 += 8;
      ++v15;
    }
    while ( v14 < m_size );
  }
  v16 = reloc->m_global.m_size;
  hkOArchive::write32u(&v22, v16);
  v17 = v13 + 4;
  if ( v16 )
  {
    v18 = 0i64;
    do
    {
      hkOArchive::write32(&v22, reloc->m_global.m_data[v18].m_fromOffset);
      hkOArchive::write64u(&v22, (__int64)reloc->m_global.m_data[v18].m_toAddress);
      hkOArchive::write64u(&v22, (__int64)reloc->m_global.m_data[v18].m_toClass);
      if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))s->vfptr[1].__first_virtual_table_function__)(
                        s,
                        &endianSwap) )
        goto LABEL_14;
      ++v12;
      v17 += 20;
      ++v18;
    }
    while ( v12 < v16 );
  }
  hkOArchive::write32u(&v22, dataSize);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))s->vfptr[1].__first_virtual_table_function__)(
                    s,
                    &endianSwap)
    || (v19 = v17 + 4,
        ((void (__fastcall *)(hkStreamWriter *, void *, _QWORD))s->vfptr[2].__vecDelDtor)(s, data, dataSize),
        !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))s->vfptr[1].__first_virtual_table_function__)(
                     s,
                     &endianSwap)) )
  {
LABEL_14:
    v20 = -1;
    goto LABEL_15;
  }
  v20 = dataSize + v19;
LABEL_15:
  hkOArchive::~hkOArchive(&v22);
  return v20;
}

// File Line: 157
// RVA: 0xE73BE0
__int64 __fastcall hkObjectSerialize::writeObject(
        hkStreamWriter *s,
        hkStructureLayout *destLayout,
        unsigned __int64 dataID,
        hkClass *data,
        hkClass *klass,
        hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> *globalFixups,
        hkPlatformObjectWriter::Cache *cache,
        hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  __int64 v12; // rdi
  hkClass *v13; // r15
  hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> *v14; // rbx
  int m_size; // ecx
  int v16; // r9d
  int v17; // eax
  int v18; // eax
  int v19; // esi
  __int64 v20; // rdx
  __int64 v21; // r8
  unsigned int v22; // edi
  __int64 v23; // rbx
  _QWORD **Value; // rax
  void *array; // [rsp+40h] [rbp-99h] BYREF
  unsigned int dataSize; // [rsp+48h] [rbp-91h]
  int v28; // [rsp+4Ch] [rbp-8Dh]
  hkOffsetOnlyStreamWriter writer; // [rsp+50h] [rbp-89h] BYREF
  hkContainerHeapAllocator::Allocator *v30; // [rsp+68h] [rbp-71h]
  int v31; // [rsp+70h] [rbp-69h]
  int v32; // [rsp+74h] [rbp-65h]
  hkRelocationInfo reloc; // [rsp+80h] [rbp-59h] BYREF
  hkPlatformObjectWriter v34; // [rsp+D0h] [rbp-9h] BYREF
  hkResult result; // [rsp+128h] [rbp+4Fh] BYREF

  hkPlatformObjectWriter::hkPlatformObjectWriter(&v34, destLayout, cache, flags);
  v12 = 0i64;
  writer.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  array = 0i64;
  *(_QWORD *)&writer.m_offset = &array;
  dataSize = 0;
  v28 = 0x80000000;
  *(_DWORD *)&writer.m_memSizeAndFlags = 0x1FFFF;
  v30 = &hkContainerHeapAllocator::s_alloc;
  v31 = 0;
  v32 = 1;
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, 1, 1);
  v13 = klass;
  *(_BYTE *)(*(int *)(*(_QWORD *)&writer.m_offset + 8i64) + **(_QWORD **)&writer.m_offset) = 0;
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
  hkPlatformObjectWriter::writeObject(&v34, &result, &writer, data, v13, &reloc);
  v14 = globalFixups;
  m_size = reloc.m_global.m_size;
  v16 = reloc.m_global.m_size + globalFixups->m_size;
  v17 = globalFixups->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v16 )
  {
    v18 = 2 * v17;
    if ( v16 < v18 )
      v16 = v18;
    hkArrayUtil::_reserve(
      (hkResult *)&globalFixups,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&globalFixups->m_data,
      v16,
      24);
    m_size = reloc.m_global.m_size;
  }
  v19 = 0;
  if ( m_size > 0 )
  {
    do
    {
      if ( v14->m_size == (v14->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v14->m_data, 24);
      v20 = v14->m_size;
      ++v19;
      ++v12;
      v21 = (__int64)&v14->m_data[v20];
      v14->m_size = v20 + 1;
      *(_DWORD *)v21 = reloc.m_global.m_data[v12 - 1].m_fromOffset;
      *(_QWORD *)(v21 + 8) = reloc.m_global.m_data[v12 - 1].m_toAddress;
      *(_QWORD *)(v21 + 16) = reloc.m_global.m_data[v12 - 1].m_toClass;
    }
    while ( v19 < reloc.m_global.m_size );
  }
  v22 = writeData(
          s,
          dataID,
          (unsigned __int64)v13,
          array,
          dataSize,
          &reloc,
          destLayout->m_rules.m_littleEndian != hkStructureLayout::HostLayoutRules.m_littleEndian);
  hkRelocationInfo::~hkRelocationInfo(&reloc);
  writer.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  if ( !v32 )
  {
    v23 = *(_QWORD *)&writer.m_offset;
    if ( *(_QWORD *)&writer.m_offset )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*Value[11] + 16i64))(Value[11], v23, 16i64);
    }
  }
  writer.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  dataSize = 0;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v28 & 0x3FFFFFFF);
  array = 0i64;
  v28 = 0x80000000;
  hkPlatformObjectWriter::~hkPlatformObjectWriter(&v34);
  return v22;
}

// File Line: 194
// RVA: 0xE741F0
__int64 __fastcall hkObjectSerialize::writeObject(
        hkDisplaySerializeOStream *s,
        char preObjectToken,
        const void *data,
        hkClass *klass,
        bool writePacketSize,
        bool recur,
        bool writeClass,
        hkVtableClassRegistry *classRegistry,
        hkPlatformObjectWriter::Cache *cache,
        hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  unsigned int v10; // ebx
  _BYTE v12[24]; // [rsp+60h] [rbp-18h] BYREF

  *(_QWORD *)v12 = 0i64;
  *(_DWORD *)&v12[8] = 0;
  *(_DWORD *)&v12[12] = -1;
  v10 = hkObjectSerialize::writeObject(
          s,
          preObjectToken,
          data,
          klass,
          (hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *)v12,
          writePacketSize,
          recur,
          writeClass,
          classRegistry,
          cache,
          flags);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v12,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)v12);
  return v10;
}

// File Line: 211
// RVA: 0xE74290
__int64 __fastcall hkObjectSerialize::writeObject(
        hkDisplaySerializeOStream *outStream,
        char preObjectToken,
        hkClass *data,
        hkClass *klass,
        hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *writtenObjects,
        bool writePacketSize,
        bool recur,
        bool writeClass,
        hkVtableClassRegistry *classRegistry,
        hkPlatformObjectWriter::Cache *cache,
        hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  hkVtableClassRegistry *v13; // rbx
  hkClass *v14; // rax
  hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *v15; // rsi
  bool v16; // cc
  hkClass *v17; // rax
  hkDisplaySerializeOStream *v18; // rbx
  unsigned int v19; // esi
  int v20; // eax
  int m_size; // ecx
  int v22; // ebx
  __int64 v23; // rdi
  hkClass *toClassID; // r9
  int v25; // eax
  __int64 v26; // rbx
  _QWORD **Value; // rax
  hkVtableClassRegistry *v29; // [rsp+40h] [rbp-71h]
  hkStructureLayout destLayout; // [rsp+60h] [rbp-51h] BYREF
  void *array; // [rsp+68h] [rbp-49h] BYREF
  int nbytes; // [rsp+70h] [rbp-41h]
  int v33; // [rsp+74h] [rbp-3Dh]
  hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> globalFixups; // [rsp+78h] [rbp-39h] BYREF
  hkStreamWriter s; // [rsp+88h] [rbp-29h] BYREF
  void **p_array; // [rsp+98h] [rbp-19h]
  hkContainerHeapAllocator::Allocator *v37; // [rsp+A0h] [rbp-11h]
  int v38; // [rsp+A8h] [rbp-9h]
  int v39; // [rsp+ACh] [rbp-5h]
  hkResult result; // [rsp+F8h] [rbp+47h] BYREF

  hkStructureLayout::hkStructureLayout(&destLayout, (hkStructureLayout *)&hkStructureLayout::MsvcWin32LayoutRules);
  v13 = classRegistry;
  globalFixups.m_capacityAndFlags = 0x80000000;
  if ( !classRegistry )
    v13 = hkSingleton<hkVtableClassRegistry>::s_instance;
  globalFixups.m_data = 0i64;
  globalFixups.m_size = 0;
  classRegistry = v13;
  if ( v13 && hkClass::hasVtable(klass, (hkBool *)&result)->m_bool )
  {
    v14 = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, hkClass *))v13->vfptr[2].__first_virtual_table_function__)(
                       v13,
                       data);
    if ( !v14 )
      v14 = klass;
    klass = v14;
  }
  v15 = writtenObjects;
  if ( writeClass )
  {
    v16 = (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                 &writtenObjects->m_map,
                 (unsigned __int64)klass) <= v15->m_map.m_hashMod;
    v17 = data;
    if ( !v16 && data != klass )
    {
      v29 = v13;
      v18 = outStream;
      hkObjectSerialize::writeObject(
        outStream,
        preObjectToken,
        klass,
        &hkClassClass,
        v15,
        writePacketSize,
        1,
        1,
        v29,
        cache,
        flags);
      v17 = data;
      goto LABEL_14;
    }
  }
  else
  {
    v17 = data;
  }
  v18 = outStream;
LABEL_14:
  if ( (int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
              &v15->m_map,
              (unsigned __int64)v17) > v15->m_map.m_hashMod )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &v15->m_map,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)data,
      (unsigned __int64)klass);
    s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
    p_array = &array;
    array = 0i64;
    nbytes = 0;
    v38 = 0;
    v33 = 0x80000000;
    *(_DWORD *)&s.m_memSizeAndFlags = 0x1FFFF;
    v37 = &hkContainerHeapAllocator::s_alloc;
    v39 = 1;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, 1, 1);
    *((_BYTE *)*p_array + *((int *)p_array + 2)) = 0;
    v20 = hkObjectSerialize::writeObject(
            &s,
            &destLayout,
            (unsigned __int64)data,
            data,
            klass,
            &globalFixups,
            cache,
            flags);
    if ( v20 == nbytes && v20 >= 1 )
    {
      v19 = v20 + 1;
      if ( writePacketSize )
        hkOArchive::write32u(v18, v19);
      hkOArchive::write8u(v18, preObjectToken);
      hkOArchive::writeRaw(v18, array, (unsigned int)nbytes);
      if ( recur )
      {
        m_size = globalFixups.m_size;
        v22 = 0;
        if ( globalFixups.m_size > 0 )
        {
          v23 = 0i64;
          do
          {
            toClassID = (hkClass *)globalFixups.m_data[v23].toClassID;
            if ( toClassID )
            {
              v25 = hkObjectSerialize::writeObject(
                      outStream,
                      preObjectToken,
                      (const void *)globalFixups.m_data[v23].toID,
                      toClassID,
                      writtenObjects,
                      writePacketSize,
                      1,
                      writeClass,
                      classRegistry,
                      cache,
                      flags);
              m_size = globalFixups.m_size;
              v19 += v25;
            }
            ++v22;
            ++v23;
          }
          while ( v22 < m_size );
        }
      }
    }
    else
    {
      v19 = -1;
    }
    s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
    if ( !v39 )
    {
      v26 = (__int64)p_array;
      if ( p_array )
      {
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, __int64))(*Value[11] + 16i64))(Value[11], v26, 16i64);
      }
    }
    s.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    nbytes = 0;
    if ( v33 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v33 & 0x3FFFFFFF);
    array = 0i64;
    v33 = 0x80000000;
  }
  else
  {
    v19 = 0;
  }
  globalFixups.m_size = 0;
  if ( globalFixups.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      globalFixups.m_data,
      24 * (globalFixups.m_capacityAndFlags & 0x3FFFFFFF));
  return v19;
}

// File Line: 286
// RVA: 0xE745E0
void __fastcall hkObjectSerialize::writeObject(
        hkDisplaySerializeOStream *stream,
        hkReferencedObject *object,
        bool writePacketSize,
        bool writePackfile,
        hkStructureLayout layout)
{
  _QWORD *Value; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  _QWORD *v13; // rcx
  __int64 v14; // rax
  hkClass *v15; // rsi
  hkDataObject *Contents; // rax
  hkDataObjectImpl *m_impl; // rcx
  signed int v19; // edi
  _QWORD *v20; // rax
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rcx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+40h] [rbp-C0h] BYREF
  hkOstream v28; // [rsp+50h] [rbp-B0h] BYREF
  hkDataObject result; // [rsp+68h] [rbp-98h] BYREF
  hkResult v30; // [rsp+70h] [rbp-90h] BYREF
  hkOstream v31; // [rsp+78h] [rbp-88h] BYREF
  hkDataWorldNative v32; // [rsp+90h] [rbp-70h] BYREF
  hkResult options; // [rsp+2C8h] [rbp+1C8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  v11 = Value;
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "Ttwrite obj";
    v12 = __rdtsc();
    v13 = v10 + 2;
    *((_DWORD *)v13 - 2) = v12;
    v11[1] = v13;
  }
  buf.m_data = 0i64;
  buf.m_size = 0;
  buf.m_capacityAndFlags = 0x80000000;
  hkOstream::hkOstream(&v31, &buf);
  v14 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v15 = (hkClass *)(*(__int64 (__fastcall **)(__int64, hkReferencedObject *))(*(_QWORD *)v14 + 40i64))(v14, object);
  if ( v15 )
  {
    if ( writePackfile )
    {
      LODWORD(v28.vfptr) = 0;
      hkStructureLayout::hkStructureLayout((hkStructureLayout *)&v28.vfptr + 1);
      HIDWORD(v28.vfptr) = layout;
      v28.m_memSizeAndFlags = 0;
      v28.m_writer.m_pntr = 0i64;
      hkSerializeUtil::savePackfile(
        &options,
        object,
        v15,
        v31.m_writer.m_pntr,
        (hkPackfileWriter::Options *)&v28,
        0i64,
        0);
    }
    else
    {
      hkDataWorldNative::hkDataWorldNative(&v32, 0);
      hkDataWorldNative::setContents(&v32, object, v15);
      v28.vfptr = (hkBaseObjectVtbl *)&hkBinaryTagfileWriter::`vftable;
      *(_DWORD *)&v28.m_memSizeAndFlags = 0x1FFFF;
      LOWORD(options.m_enum) = 256;
      BYTE2(options.m_enum) = 0;
      Contents = hkDataWorldNative::getContents(&v32, &result);
      hkBinaryTagfileWriter::save(
        (hkBinaryTagfileWriter *)&v28,
        &v30,
        Contents,
        v31.m_writer.m_pntr,
        0i64,
        (hkTagfileWriter::Options *)&options);
      m_impl = result.m_impl;
      if ( result.m_impl )
      {
        --result.m_impl->m_externalCount;
        if ( m_impl->m_count-- == 1 )
          m_impl->vfptr->__vecDelDtor(m_impl, 1u);
      }
      hkDataWorldNative::~hkDataWorldNative(&v32);
    }
    v19 = buf.m_size + 5;
    if ( writePacketSize )
      hkOArchive::write32u(stream, v19);
    v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v21 = v20[1];
    if ( v21 < v20[3] )
    {
      v22 = v21 + 16;
      *(_QWORD *)(v22 - 16) = "Mibytes";
      *(float *)(v22 - 8) = (float)v19;
      v20[1] = v22;
    }
    hkOArchive::write8u(stream, 64);
    hkOArchive::write32(stream, buf.m_size);
    hkOArchive::writeRaw(stream, buf.m_data, (unsigned int)buf.m_size);
    v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v24 = (_QWORD *)v23[1];
    if ( (unsigned __int64)v24 < v23[3] )
    {
      *v24 = "Et";
      v25 = __rdtsc();
      v26 = v24 + 2;
      *((_DWORD *)v26 - 2) = v25;
      v23[1] = v26;
    }
  }
  else
  {
    hkErrStream::hkErrStream((hkErrStream *)&v28, (char *)&v32, 512);
    hkOstream::operator<<(&v28, "Class not found");
    hkError::messageWarning(0x472133Eu, (const char *)&v32, "Serialize\\hkObjectSerialize.cpp", 318);
    hkOstream::~hkOstream(&v28);
  }
  hkOstream::~hkOstream(&v31);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 340
// RVA: 0xE748E0
hkReferencedObject *__fastcall hkObjectSerialize::readObject(
        hkDisplaySerializeIStream *stream,
        hkSerializeUtil::ErrorDetails *errorDetails)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  int m_enum; // ebx
  int v9; // r9d
  _QWORD *v10; // rax
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rcx
  hkObjectResource *v13; // r14
  hkReferencedObject *v14; // rsi
  _QWORD *v15; // rax
  __int64 v16; // rdi
  _QWORD *v17; // rbx
  __int64 v18; // rax
  hkClass *v19; // rax
  int v20; // r9d
  unsigned int v21; // ecx
  _QWORD *v22; // r9
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // rax
  void *buf; // [rsp+30h] [rbp-D0h] BYREF
  int v27; // [rsp+38h] [rbp-C8h]
  int v28; // [rsp+3Ch] [rbp-C4h]
  hkErrStream v29; // [rsp+40h] [rbp-C0h] BYREF
  unsigned __int64 v30; // [rsp+60h] [rbp-A0h]
  __int64 v31; // [rsp+68h] [rbp-98h]
  __int64 v32; // [rsp+70h] [rbp-90h]
  char description[512]; // [rsp+80h] [rbp-80h] BYREF
  hkResult array; // [rsp+2B0h] [rbp+1B0h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "Ttread obj";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  buf = 0i64;
  v27 = 0;
  v28 = 0x80000000;
  hkIArchive::readArrayGeneric(stream, &array, 4, 1);
  m_enum = array.m_enum;
  if ( array.m_enum > HK_SUCCESS )
  {
    v9 = array.m_enum;
    if ( array.m_enum < HK_SUCCESS )
      v9 = 0;
    hkArrayUtil::_reserve(&array, &hkContainerHeapAllocator::s_alloc, (const void **)&buf, v9, 1);
  }
  v27 = m_enum;
  hkIArchive::readRaw(stream, buf, m_enum);
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = v10[1];
  if ( v11 < v10[3] )
  {
    v12 = v11 + 16;
    *(_QWORD *)(v12 - 16) = "Mibytes";
    *(float *)(v12 - 8) = (float)m_enum;
    v10[1] = v12;
  }
  LODWORD(v30) = 1;
  v31 = 0i64;
  v32 = 0i64;
  v29.hkReferencedObject = (hkReferencedObject)v30;
  v29.m_writer.m_pntr = 0i64;
  v13 = hkSerializeUtil::loadOnHeap(buf, v27, errorDetails, (hkSerializeUtil::LoadOptions *)&v29);
  v14 = 0i64;
  if ( v13 )
  {
    v15 = (_QWORD *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
    v16 = *v15;
    v17 = v15;
    v18 = ((__int64 (__fastcall *)(hkObjectResource *))v13->vfptr[3].__first_virtual_table_function__)(v13);
    v19 = (hkClass *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(v16 + 32))(v17, v18);
    if ( v19 )
    {
      if ( hkClass::isSuperClass(&hkReferencedObjectClass, (hkBool *)&array, v19)->m_bool )
      {
        v14 = hkResource::getContents<hkReferencedObject>(v13);
        hkReferencedObject::addReference(v14);
        hkReferencedObject::removeReference(v13);
        goto LABEL_17;
      }
      hkErrStream::hkErrStream(&v29, description, 512);
      hkOstream::operator<<(&v29, "Object is not a referenced object.  Ignoring");
      v20 = 370;
      v21 = 1339687185;
    }
    else
    {
      hkErrStream::hkErrStream(&v29, description, 512);
      hkOstream::operator<<(&v29, "Object hkClass not found.  Ignoring.");
      v20 = 375;
      v21 = 1339687186;
    }
    hkError::messageWarning(v21, description, "Serialize\\hkObjectSerialize.cpp", v20);
    hkOstream::~hkOstream(&v29);
    hkReferencedObject::removeReference(v13);
  }
  else
  {
    hkErrStream::hkErrStream(&v29, description, 512);
    hkOstream::operator<<(&v29, "Object could not be read from tagfile.");
    hkError::messageWarning(0x4FDA0113u, description, "Serialize\\hkObjectSerialize.cpp", 382);
    hkOstream::~hkOstream(&v29);
  }
LABEL_17:
  v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v23 = v22[1];
  if ( v23 < v22[3] )
  {
    *(_QWORD *)v23 = "Et";
    v24 = __rdtsc();
    *(_DWORD *)(v23 + 8) = v24;
    v22[1] = v23 + 16;
  }
  v27 = 0;
  if ( v28 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, void *, _QWORD, _QWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      buf,
      v28 & 0x3FFFFFFF,
      v22);
  return v14;
}

