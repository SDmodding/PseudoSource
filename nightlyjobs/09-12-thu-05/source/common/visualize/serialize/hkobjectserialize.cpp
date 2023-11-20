// File Line: 23
// RVA: 0xE73EA0
__int64 __fastcall hkObjectSerialize::readObject(hkStreamReader *s, void **data, unsigned int *dataSize, hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> *globalFixups, unsigned __int64 *klassID)
{
  void **v5; // r12
  unsigned int *v6; // r15
  hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> *v7; // r14
  hkStreamReader *v8; // rbx
  hkBaseObjectVtbl *v10; // rax
  int v11; // ecx
  int v12; // edi
  int v13; // esi
  __int64 v14; // rdi
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // edi
  int v18; // eax
  int v19; // esi
  signed __int64 v20; // rdi
  int v21; // edi
  hkMemoryAllocator **v22; // rax
  char *v23; // rdi
  hkMemoryAllocator **v24; // rax
  __int64 v25; // rbx
  unsigned int v26; // ecx
  unsigned int v27; // edx
  __int64 v28; // r8
  __int64 v29; // r9
  int v30; // [rsp+30h] [rbp-20h]
  unsigned int v31; // [rsp+34h] [rbp-1Ch]
  __int64 v32; // [rsp+38h] [rbp-18h]
  char *array; // [rsp+40h] [rbp-10h]
  int v34; // [rsp+48h] [rbp-8h]
  int v35; // [rsp+4Ch] [rbp-4h]
  hkResult result; // [rsp+80h] [rbp+30h]

  v5 = data;
  v6 = dataSize;
  v7 = globalFixups;
  v8 = s;
  ((void (__fastcall *)(hkStreamReader *, __int64 *, signed __int64))s->vfptr[2].__vecDelDtor)(s, &v32, 8i64);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                    v8,
                    &result) )
    return 0i64;
  ((void (__fastcall *)(hkStreamReader *, unsigned __int64 *, signed __int64))v8->vfptr[2].__vecDelDtor)(
    v8,
    klassID,
    8i64);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                    v8,
                    &result) )
    return 0i64;
  v10 = v8->vfptr;
  array = 0i64;
  v34 = 0;
  v35 = 2147483648;
  ((void (__fastcall *)(hkStreamReader *, int *, signed __int64))v10[2].__vecDelDtor)(v8, &v30, 4i64);
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                   v8,
                   &result) )
  {
    v11 = v30;
    v12 = v30;
    if ( (v35 & 0x3FFFFFFF) < v30 )
    {
      if ( v30 < 2 * (v35 & 0x3FFFFFFF) )
        v11 = 2 * (v35 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v11, 8);
      v11 = v30;
    }
    v13 = 0;
    v34 = v12;
    if ( v11 )
    {
      while ( 1 )
      {
        v14 = (__int64)&array[8 * v13];
        ((void (__fastcall *)(hkStreamReader *, char *, signed __int64))v8->vfptr[2].__vecDelDtor)(
          v8,
          &array[8 * v13],
          4i64);
        ((void (__fastcall *)(hkStreamReader *, signed __int64, signed __int64))v8->vfptr[2].__vecDelDtor)(
          v8,
          v14 + 4,
          4i64);
        if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                          v8,
                          &result) )
          break;
        if ( ++v13 >= (unsigned int)v30 )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      ((void (__fastcall *)(hkStreamReader *, unsigned int *, signed __int64))v8->vfptr[2].__vecDelDtor)(v8, &v31, 4i64);
      if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                       v8,
                       &result) )
      {
        v15 = v31;
        v16 = v7->m_capacityAndFlags & 0x3FFFFFFF;
        v17 = v31;
        if ( v16 < (signed int)v31 )
        {
          v18 = 2 * v16;
          if ( (signed int)v31 < v18 )
            v15 = v18;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v15, 24);
          v15 = v31;
        }
        v19 = 0;
        v7->m_size = v17;
        if ( v15 )
        {
          while ( 1 )
          {
            v20 = (signed __int64)&v7->m_data[v19];
            ((void (__fastcall *)(hkStreamReader *, signed __int64, signed __int64))v8->vfptr[2].__vecDelDtor)(
              v8,
              v20,
              4i64);
            ((void (__fastcall *)(hkStreamReader *, signed __int64, signed __int64))v8->vfptr[2].__vecDelDtor)(
              v8,
              v20 + 8,
              8i64);
            ((void (__fastcall *)(hkStreamReader *, signed __int64, signed __int64))v8->vfptr[2].__vecDelDtor)(
              v8,
              v20 + 16,
              8i64);
            if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                              v8,
                              &result) )
              break;
            if ( ++v19 >= v31 )
              goto LABEL_20;
          }
        }
        else
        {
LABEL_20:
          ((void (__fastcall *)(hkStreamReader *, unsigned int *, signed __int64))v8->vfptr[2].__vecDelDtor)(
            v8,
            v6,
            4i64);
          if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                           v8,
                           &result) )
          {
            v21 = *v6;
            v22 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v23 = (char *)hkMemoryRouter::easyAlloc(v22[11], v21);
            ((void (__fastcall *)(hkStreamReader *, char *, _QWORD))v8->vfptr[2].__vecDelDtor)(v8, v23, *v6);
            if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))v8->vfptr[1].__first_virtual_table_function__)(
                             v8,
                             &result) )
            {
              v26 = v30;
              v27 = 0;
              if ( v30 )
              {
                v28 = 0i64;
                do
                {
                  v29 = *(signed int *)&array[v28];
                  if ( (signed int)v29 >= 0 )
                  {
                    *(_QWORD *)&v23[v29] = &v23[*(signed int *)&array[v28 + 4]];
                    v26 = v30;
                  }
                  ++v27;
                  v28 += 8i64;
                }
                while ( v27 < v26 );
              }
              v25 = v32;
              *v5 = v23;
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v35);
  return v25;
}

// File Line: 100
// RVA: 0xE74C00
__int64 __fastcall writeData(hkStreamWriter *s, unsigned __int64 dataID, unsigned __int64 classID, void *data, unsigned int dataSize, hkRelocationInfo *reloc, unsigned int endianSwap)
{
  unsigned __int64 v7; // rbx
  hkStreamWriter *v8; // r15
  unsigned __int64 v9; // rdi
  void *v10; // r13
  unsigned int v11; // er12
  unsigned int v12; // edi
  signed int v13; // ebx
  unsigned int v14; // esi
  __int64 v15; // r14
  unsigned int v16; // er14
  int v17; // ebx
  __int64 v18; // rsi
  int v19; // ebx
  unsigned int v20; // ebx
  hkOArchive v22; // [rsp+20h] [rbp-48h]

  v7 = dataID;
  v8 = s;
  v9 = classID;
  v10 = data;
  hkOArchive::hkOArchive(&v22, s, (hkBool)(endianSwap != 0));
  hkOArchive::write64u(&v22, v7);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))v8->vfptr[1].__first_virtual_table_function__)(
                    v8,
                    &endianSwap) )
    goto LABEL_14;
  hkOArchive::write64u(&v22, v9);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))v8->vfptr[1].__first_virtual_table_function__)(
                    v8,
                    &endianSwap) )
    goto LABEL_14;
  v11 = reloc->m_local.m_size;
  hkOArchive::write32u(&v22, reloc->m_local.m_size);
  v12 = 0;
  v13 = 20;
  v14 = 0;
  if ( v11 )
  {
    v15 = 0i64;
    do
    {
      hkOArchive::write32(&v22, reloc->m_local.m_data[v15].m_fromOffset);
      hkOArchive::write32(&v22, reloc->m_local.m_data[v15].m_toOffset);
      if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))v8->vfptr[1].__first_virtual_table_function__)(
                        v8,
                        &endianSwap) )
        goto LABEL_14;
      ++v14;
      v13 += 8;
      ++v15;
    }
    while ( v14 < v11 );
  }
  v16 = reloc->m_global.m_size;
  hkOArchive::write32u(&v22, reloc->m_global.m_size);
  v17 = v13 + 4;
  if ( v16 )
  {
    v18 = 0i64;
    do
    {
      hkOArchive::write32(&v22, reloc->m_global.m_data[v18].m_fromOffset);
      hkOArchive::write64u(&v22, (unsigned __int64)reloc->m_global.m_data[v18].m_toAddress);
      hkOArchive::write64u(&v22, (unsigned __int64)reloc->m_global.m_data[v18].m_toClass);
      if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))v8->vfptr[1].__first_virtual_table_function__)(
                        v8,
                        &endianSwap) )
        goto LABEL_14;
      ++v12;
      v17 += 20;
      ++v18;
    }
    while ( v12 < v16 );
  }
  hkOArchive::write32u(&v22, dataSize);
  if ( !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))v8->vfptr[1].__first_virtual_table_function__)(
                    v8,
                    &endianSwap)
    || (v19 = v17 + 4,
        ((void (__fastcall *)(hkStreamWriter *, void *, _QWORD))v8->vfptr[2].__vecDelDtor)(v8, v10, dataSize),
        !*(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, unsigned int *))v8->vfptr[1].__first_virtual_table_function__)(
                     v8,
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
__int64 __fastcall hkObjectSerialize::writeObject(hkStreamWriter *s, hkStructureLayout *destLayout, unsigned __int64 dataID, const void *data, hkClass *klass, hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> *globalFixups, hkPlatformObjectWriter::Cache *cache, hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  const void *v8; // rbx
  unsigned __int64 v9; // r12
  hkStreamWriter *v10; // r13
  hkStructureLayout *v11; // r14
  __int64 v12; // rdi
  hkClass *v13; // r15
  hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> *v14; // rbx
  int v15; // ecx
  int v16; // er9
  int v17; // eax
  int v18; // eax
  int v19; // esi
  __int64 v20; // rdx
  signed __int64 v21; // r8
  unsigned int v22; // edi
  __int64 v23; // rbx
  _QWORD **v24; // rax
  void *array; // [rsp+40h] [rbp-99h]
  unsigned int dataSize; // [rsp+48h] [rbp-91h]
  int v28; // [rsp+4Ch] [rbp-8Dh]
  hkStreamWriter writer; // [rsp+50h] [rbp-89h]
  void **v30; // [rsp+60h] [rbp-79h]
  hkContainerHeapAllocator::Allocator *v31; // [rsp+68h] [rbp-71h]
  int v32; // [rsp+70h] [rbp-69h]
  int v33; // [rsp+74h] [rbp-65h]
  hkRelocationInfo reloc; // [rsp+80h] [rbp-59h]
  hkPlatformObjectWriter v35; // [rsp+D0h] [rbp-9h]
  hkResult result; // [rsp+128h] [rbp+4Fh]

  v8 = data;
  v9 = dataID;
  v10 = s;
  v11 = destLayout;
  hkPlatformObjectWriter::hkPlatformObjectWriter(&v35, destLayout, cache, flags);
  v12 = 0i64;
  writer.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  array = 0i64;
  v30 = &array;
  dataSize = 0;
  v28 = 2147483648;
  *(_DWORD *)&writer.m_memSizeAndFlags = 0x1FFFF;
  v31 = &hkContainerHeapAllocator::s_alloc;
  v32 = 0;
  v33 = 1;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 1, 1);
  v13 = klass;
  *((_BYTE *)*v30 + *((signed int *)v30 + 2)) = 0;
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
  hkPlatformObjectWriter::writeObject(&v35, &result, &writer, v8, v13, &reloc);
  v14 = globalFixups;
  v15 = reloc.m_global.m_size;
  v16 = reloc.m_global.m_size + globalFixups->m_size;
  v17 = globalFixups->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 < v16 )
  {
    v18 = 2 * v17;
    if ( v16 < v18 )
      v16 = v18;
    hkArrayUtil::_reserve(
      (hkResult *)&globalFixups,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      globalFixups,
      v16,
      24);
    v15 = reloc.m_global.m_size;
  }
  v19 = 0;
  if ( v15 > 0 )
  {
    do
    {
      if ( v14->m_size == (v14->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v14, 24);
      v20 = v14->m_size;
      ++v19;
      ++v12;
      v21 = (signed __int64)&v14->m_data[v20];
      v14->m_size = v20 + 1;
      *(_DWORD *)v21 = reloc.m_global.m_data[v12 - 1].m_fromOffset;
      *(_QWORD *)(v21 + 8) = *((_QWORD *)&reloc.m_global.m_data[v12] - 3);
      *(_QWORD *)(v21 + 16) = *((_QWORD *)&reloc.m_global.m_data[v12] - 2);
    }
    while ( v19 < reloc.m_global.m_size );
  }
  v22 = writeData(
          v10,
          v9,
          (unsigned __int64)v13,
          array,
          dataSize,
          &reloc,
          v11->m_rules.m_littleEndian != hkStructureLayout::HostLayoutRules.m_littleEndian);
  hkRelocationInfo::~hkRelocationInfo(&reloc);
  writer.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
  if ( !v33 )
  {
    v23 = (__int64)v30;
    if ( v30 )
    {
      v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v24[11] + 16i64))(v24[11], v23, 16i64);
    }
  }
  writer.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  dataSize = 0;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v28 & 0x3FFFFFFF);
  array = 0i64;
  v28 = 2147483648;
  hkPlatformObjectWriter::~hkPlatformObjectWriter(&v35);
  return v22;
}

// File Line: 194
// RVA: 0xE741F0
__int64 __fastcall hkObjectSerialize::writeObject(hkDisplaySerializeOStream *s, char preObjectToken, const void *data, hkClass *klass, bool writePacketSize, bool recur, bool writeClass, hkVtableClassRegistry *classRegistry, hkPlatformObjectWriter::Cache *cache, hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  unsigned int v10; // ebx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v12; // [rsp+60h] [rbp-18h]

  v12.m_elem = 0i64;
  v12.m_numElems = 0;
  v12.m_hashMod = -1;
  v10 = hkObjectSerialize::writeObject(
          s,
          preObjectToken,
          data,
          klass,
          (hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *)&v12,
          writePacketSize,
          recur,
          writeClass,
          classRegistry,
          cache,
          flags);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v12,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v12);
  return v10;
}

// File Line: 211
// RVA: 0xE74290
__int64 __fastcall hkObjectSerialize::writeObject(hkDisplaySerializeOStream *outStream, char preObjectToken, const void *data, hkClass *klass, hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *writtenObjects, bool writePacketSize, bool recur, bool writeClass, hkVtableClassRegistry *classRegistry, hkPlatformObjectWriter::Cache *cache, hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  hkClass *v11; // rdi
  const void *v12; // rsi
  hkVtableClassRegistry *v13; // rbx
  __int64 v14; // rax
  hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *v15; // rsi
  int v16; // eax
  bool v17; // zf
  bool v18; // sf
  unsigned __int8 v19; // of
  unsigned __int64 v20; // rax
  hkVtableClassRegistry *v21; // ST40_8
  hkOArchive *v22; // rbx
  unsigned int v23; // esi
  signed int v24; // eax
  int v25; // ecx
  int v26; // ebx
  __int64 v27; // rdi
  hkClass *v28; // r9
  int v29; // eax
  __int64 v30; // rbx
  _QWORD **v31; // rax
  hkStructureLayout destLayout; // [rsp+60h] [rbp-51h]
  void *array; // [rsp+68h] [rbp-49h]
  int nbytes; // [rsp+70h] [rbp-41h]
  int v36; // [rsp+74h] [rbp-3Dh]
  hkArray<hkObjectSerialize::GlobalFixup,hkContainerHeapAllocator> globalFixups; // [rsp+78h] [rbp-39h]
  hkStreamWriter s; // [rsp+88h] [rbp-29h]
  void **v39; // [rsp+98h] [rbp-19h]
  hkContainerHeapAllocator::Allocator *v40; // [rsp+A0h] [rbp-11h]
  int v41; // [rsp+A8h] [rbp-9h]
  int v42; // [rsp+ACh] [rbp-5h]
  hkDisplaySerializeOStream *outStreama; // [rsp+E0h] [rbp+2Fh]
  char v44; // [rsp+E8h] [rbp+37h]
  hkClass *key; // [rsp+F0h] [rbp+3Fh]
  hkBool result; // [rsp+F8h] [rbp+47h]

  key = (hkClass *)data;
  v44 = preObjectToken;
  outStreama = outStream;
  v11 = klass;
  v12 = data;
  hkStructureLayout::hkStructureLayout(&destLayout, &hkStructureLayout::MsvcWin32LayoutRules);
  v13 = classRegistry;
  globalFixups.m_capacityAndFlags = 2147483648;
  if ( !classRegistry )
    v13 = hkSingleton<hkVtableClassRegistry>::s_instance;
  globalFixups.m_data = 0i64;
  globalFixups.m_size = 0;
  classRegistry = v13;
  if ( v13 && hkClass::hasVtable(v11, &result)->m_bool )
  {
    v14 = ((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))v13->vfptr[2].__first_virtual_table_function__)(
            v13,
            v12);
    if ( !v14 )
      v14 = (__int64)v11;
    v11 = (hkClass *)v14;
  }
  v15 = writtenObjects;
  if ( writeClass )
  {
    v16 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&writtenObjects->m_map.m_elem,
                              (unsigned __int64)v11);
    v19 = __OFSUB__(v16, v15->m_map.m_hashMod);
    v17 = v16 == v15->m_map.m_hashMod;
    v18 = v16 - v15->m_map.m_hashMod < 0;
    v20 = (unsigned __int64)key;
    if ( !((unsigned __int8)(v18 ^ v19) | v17) && key != v11 )
    {
      v21 = v13;
      v22 = (hkOArchive *)&outStreama->vfptr;
      hkObjectSerialize::writeObject(outStreama, v44, v11, &hkClassClass, v15, writePacketSize, 1, 1, v21, cache, flags);
      v20 = (unsigned __int64)key;
      goto LABEL_14;
    }
  }
  else
  {
    v20 = (unsigned __int64)key;
  }
  v22 = (hkOArchive *)&outStreama->vfptr;
LABEL_14:
  if ( (signed int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v15->m_map.m_elem,
                     v20) > v15->m_map.m_hashMod )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v15->m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned __int64)key,
      (unsigned __int64)v11);
    s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
    v39 = &array;
    array = 0i64;
    nbytes = 0;
    v41 = 0;
    v36 = 2147483648;
    *(_DWORD *)&s.m_memSizeAndFlags = 0x1FFFF;
    v40 = &hkContainerHeapAllocator::s_alloc;
    v42 = 1;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      1,
      1);
    *((_BYTE *)*v39 + *((signed int *)v39 + 2)) = 0;
    v24 = hkObjectSerialize::writeObject(&s, &destLayout, (unsigned __int64)key, key, v11, &globalFixups, cache, flags);
    if ( v24 != nbytes || v24 < 1 )
    {
      v23 = -1;
    }
    else
    {
      v23 = v24 + 1;
      if ( writePacketSize )
        hkOArchive::write32u(v22, v23);
      hkOArchive::write8u(v22, v44);
      hkOArchive::writeRaw(v22, array, (unsigned int)nbytes);
      if ( recur )
      {
        v25 = globalFixups.m_size;
        v26 = 0;
        if ( globalFixups.m_size > 0 )
        {
          v27 = 0i64;
          do
          {
            v28 = (hkClass *)globalFixups.m_data[v27].toClassID;
            if ( v28 )
            {
              v29 = hkObjectSerialize::writeObject(
                      outStreama,
                      v44,
                      (const void *)globalFixups.m_data[v27].toID,
                      v28,
                      writtenObjects,
                      writePacketSize,
                      1,
                      writeClass,
                      classRegistry,
                      cache,
                      flags);
              v25 = globalFixups.m_size;
              v23 += v29;
            }
            ++v26;
            ++v27;
          }
          while ( v26 < v25 );
        }
      }
    }
    s.vfptr = (hkBaseObjectVtbl *)&hkArrayStreamWriter::`vftable;
    if ( !v42 )
    {
      v30 = (__int64)v39;
      if ( v39 )
      {
        v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v31[11] + 16i64))(v31[11], v30, 16i64);
      }
    }
    s.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    nbytes = 0;
    if ( v36 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        v36 & 0x3FFFFFFF);
    array = 0i64;
    v36 = 2147483648;
  }
  else
  {
    v23 = 0;
  }
  globalFixups.m_size = 0;
  if ( globalFixups.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      globalFixups.m_data,
      24 * (globalFixups.m_capacityAndFlags & 0x3FFFFFFF));
  return v23;
}

// File Line: 286
// RVA: 0xE745E0
void __fastcall hkObjectSerialize::writeObject(hkDisplaySerializeOStream *stream, hkReferencedObject *object, bool writePacketSize, bool writePackfile, hkStructureLayout layout)
{
  hkDisplaySerializeOStream *v5; // rbx
  bool v6; // r14
  bool v7; // r15
  hkReferencedObject *v8; // rdi
  _QWORD *v9; // rax
  _QWORD *v10; // rcx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  hkClass *v15; // rsi
  hkDataObject *v16; // rax
  hkDataObjectImpl *v17; // rcx
  bool v18; // zf
  signed int v19; // edi
  _QWORD *v20; // rax
  unsigned __int64 v21; // rcx
  signed __int64 v22; // rcx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+40h] [rbp-C0h]
  hkBinaryTagfileWriter v28; // [rsp+50h] [rbp-B0h]
  __int64 v29; // [rsp+60h] [rbp-A0h]
  hkDataObject result; // [rsp+68h] [rbp-98h]
  hkResult v31; // [rsp+70h] [rbp-90h]
  hkOstream v32; // [rsp+78h] [rbp-88h]
  hkDataWorldNative v33; // [rsp+90h] [rbp-70h]
  hkTagfileWriter::Options options; // [rsp+2C8h] [rbp+1C8h]

  v5 = stream;
  v6 = writePackfile;
  v7 = writePacketSize;
  v8 = object;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  v11 = v9;
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "Ttwrite obj";
    v12 = __rdtsc();
    v13 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v13 - 8) = v12;
    v11[1] = v13;
  }
  buf.m_data = 0i64;
  buf.m_size = 0;
  buf.m_capacityAndFlags = 2147483648;
  hkOstream::hkOstream(&v32, &buf);
  v14 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)();
  v15 = (hkClass *)(*(__int64 (__fastcall **)(__int64, hkReferencedObject *))(*(_QWORD *)v14 + 40i64))(v14, v8);
  if ( v15 )
  {
    if ( v6 )
    {
      LODWORD(v28.vfptr) = 0;
      hkStructureLayout::hkStructureLayout((hkStructureLayout *)&v28.vfptr + 1);
      HIDWORD(v28.vfptr) = layout;
      v28.m_memSizeAndFlags = 0;
      v29 = 0i64;
      hkSerializeUtil::savePackfile(
        (hkResult *)&options,
        v8,
        v15,
        v32.m_writer.m_pntr,
        (hkPackfileWriter::Options *)&v28,
        0i64,
        0);
    }
    else
    {
      hkDataWorldNative::hkDataWorldNative(&v33, 0);
      hkDataWorldNative::setContents(&v33, v8, v15);
      v28.vfptr = (hkBaseObjectVtbl *)&hkBinaryTagfileWriter::`vftable;
      *(_DWORD *)&v28.m_memSizeAndFlags = 0x1FFFF;
      *(_WORD *)&options.m_verbose.m_bool = 256;
      options.m_writeSerializeIgnored.m_bool = 0;
      v16 = hkDataWorldNative::getContents(&v33, &result);
      hkBinaryTagfileWriter::save(&v28, &v31, v16, v32.m_writer.m_pntr, 0i64, &options);
      v17 = result.m_impl;
      if ( result.m_impl )
      {
        --result.m_impl->m_externalCount;
        v18 = v17->m_count-- == 1;
        if ( v18 )
          v17->vfptr->__vecDelDtor((hkDataRefCounted *)&v17->vfptr, 1u);
      }
      hkDataWorldNative::~hkDataWorldNative(&v33);
    }
    v19 = buf.m_size + 5;
    if ( v7 )
      hkOArchive::write32u((hkOArchive *)&v5->vfptr, v19);
    v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v21 = v20[1];
    if ( v21 < v20[3] )
    {
      v22 = v21 + 16;
      *(_QWORD *)(v22 - 16) = "Mibytes";
      *(float *)(v22 - 8) = (float)v19;
      v20[1] = v22;
    }
    hkOArchive::write8u((hkOArchive *)&v5->vfptr, 64);
    hkOArchive::write32((hkOArchive *)&v5->vfptr, buf.m_size);
    hkOArchive::writeRaw((hkOArchive *)&v5->vfptr, buf.m_data, (unsigned int)buf.m_size);
    v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v24 = (_QWORD *)v23[1];
    if ( (unsigned __int64)v24 < v23[3] )
    {
      *v24 = "Et";
      v25 = __rdtsc();
      v26 = (signed __int64)(v24 + 2);
      *(_DWORD *)(v26 - 8) = v25;
      v23[1] = v26;
    }
  }
  else
  {
    hkErrStream::hkErrStream((hkErrStream *)&v28, &v33, 512);
    hkOstream::operator<<((hkOstream *)&v28, "Class not found");
    hkError::messageWarning(74584894, (const char *)&v33, "Serialize\\hkObjectSerialize.cpp", 318);
    hkOstream::~hkOstream((hkOstream *)&v28);
  }
  hkOstream::~hkOstream(&v32);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 340
// RVA: 0xE748E0
hkReferencedObject *__fastcall hkObjectSerialize::readObject(hkDisplaySerializeIStream *stream, hkSerializeUtil::ErrorDetails *errorDetails)
{
  hkDisplaySerializeIStream *v2; // rdi
  hkSerializeUtil::ErrorDetails *v3; // rsi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  int v8; // ebx
  int v9; // er9
  _QWORD *v10; // rax
  unsigned __int64 v11; // rcx
  signed __int64 v12; // rcx
  hkObjectResource *v13; // r14
  hkReferencedObject *v14; // rsi
  _QWORD *v15; // rax
  __int64 v16; // rdi
  _QWORD *v17; // rbx
  __int64 v18; // rax
  hkClass *v19; // rax
  int v20; // er9
  int v21; // ecx
  _QWORD *v22; // r9
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // rax
  void *buf; // [rsp+30h] [rbp-D0h]
  int v27; // [rsp+38h] [rbp-C8h]
  int v28; // [rsp+3Ch] [rbp-C4h]
  hkErrStream v29; // [rsp+40h] [rbp-C0h]
  __int128 v30; // [rsp+60h] [rbp-A0h]
  __int64 v31; // [rsp+70h] [rbp-90h]
  char description; // [rsp+80h] [rbp-80h]
  int array; // [rsp+2B0h] [rbp+1B0h]

  v2 = stream;
  v3 = errorDetails;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "Ttread obj";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  buf = 0i64;
  v27 = 0;
  v28 = 2147483648;
  hkIArchive::readArrayGeneric((hkIArchive *)&v2->vfptr, &array, 4, 1);
  v8 = array;
  if ( array > 0 )
  {
    v9 = array;
    if ( array < 0 )
      v9 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&array,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &buf,
      v9,
      1);
  }
  v27 = v8;
  hkIArchive::readRaw((hkIArchive *)&v2->vfptr, buf, v8);
  v10 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v11 = v10[1];
  if ( v11 < v10[3] )
  {
    v12 = v11 + 16;
    *(_QWORD *)(v12 - 16) = "Mibytes";
    *(float *)(v12 - 8) = (float)v8;
    v10[1] = v12;
  }
  LODWORD(v30) = 1;
  *((_QWORD *)&v30 + 1) = 0i64;
  v31 = 0i64;
  *(_OWORD *)&v29.vfptr = (unsigned __int64)v30;
  v29.m_writer.m_pntr = 0i64;
  v13 = hkSerializeUtil::loadOnHeap(buf, v27, v3, (hkSerializeUtil::LoadOptions *)&v29);
  v14 = 0i64;
  if ( v13 )
  {
    v15 = (_QWORD *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
    v16 = *v15;
    v17 = v15;
    v18 = ((__int64 (__fastcall *)(hkObjectResource *))v13->vfptr[3].__first_virtual_table_function__)(v13);
    v19 = (hkClass *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(v16 + 32))(v17, v18);
    if ( v19 )
    {
      if ( hkClass::isSuperClass(&hkReferencedObjectClass, (hkBool *)&array, v19)->m_bool )
      {
        v14 = hkResource::getContents<hkReferencedObject>((hkResource *)&v13->vfptr);
        hkReferencedObject::addReference(v14);
        hkReferencedObject::removeReference((hkReferencedObject *)&v13->vfptr);
        goto LABEL_17;
      }
      hkErrStream::hkErrStream(&v29, &description, 512);
      hkOstream::operator<<((hkOstream *)&v29.vfptr, "Object is not a referenced object.  Ignoring");
      v20 = 370;
      v21 = 1339687185;
    }
    else
    {
      hkErrStream::hkErrStream(&v29, &description, 512);
      hkOstream::operator<<((hkOstream *)&v29.vfptr, "Object hkClass not found.  Ignoring.");
      v20 = 375;
      v21 = 1339687186;
    }
    hkError::messageWarning(v21, &description, "Serialize\\hkObjectSerialize.cpp", v20);
    hkOstream::~hkOstream((hkOstream *)&v29.vfptr);
    hkReferencedObject::removeReference((hkReferencedObject *)&v13->vfptr);
  }
  else
  {
    hkErrStream::hkErrStream(&v29, &description, 512);
    hkOstream::operator<<((hkOstream *)&v29.vfptr, "Object could not be read from tagfile.");
    hkError::messageWarning(1339687187, &description, "Serialize\\hkObjectSerialize.cpp", 382);
    hkOstream::~hkOstream((hkOstream *)&v29.vfptr);
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

