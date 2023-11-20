// File Line: 43
// RVA: 0xE6B3E0
char *__fastcall hkDeepCopier::deepCopy(const void *dataIn, hkClass *klassIn, hkPointerMap<void const *,void *,hkContainerHeapAllocator> *previousCopies, hkVtableClassRegistry *vtableClassRegistry, hkTypeInfoRegistry *loadedObjectRegistry, hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  hkClass *v6; // rdi
  const void *v7; // rbx
  char *v8; // r12
  hkVtableClassRegistry *v9; // r14
  hkPointerMap<void const *,void *,hkContainerHeapAllocator> *v10; // r13
  int v11; // ecx
  char *v12; // rax
  int v13; // er15
  const void *v14; // rdi
  hkClass *klassOut; // rbx
  __int64 v16; // rsi
  int v17; // edx
  char *v18; // r9
  __int64 v19; // rdi
  void *v20; // rbx
  hkClass *v21; // r14
  void *v22; // rax
  int v23; // ecx
  char *v24; // rax
  int v25; // edi
  hkVtableClassRegistry *v26; // r15
  int v27; // ebx
  hkMemoryAllocator **v28; // rax
  char *v29; // rax
  char *v30; // rsi
  int v31; // er8
  __int64 v32; // rdx
  int v33; // er14
  __int64 v34; // rdi
  char *v35; // rbx
  int v36; // eax
  int v37; // ecx
  int v38; // edi
  __int64 v39; // rbx
  int v40; // er13
  char *v41; // r14
  __int64 v42; // r12
  hkBaseObjectVtbl *v43; // rbx
  hkClass **v44; // rdi
  const char *v45; // rax
  hkBaseObjectVtbl *v46; // rbx
  const char *v47; // rax
  int v48; // ebx
  __int64 v49; // rdi
  char *v50; // r14
  hkVariant *v51; // rax
  char *v53; // [rsp+40h] [rbp-B8h]
  int v54; // [rsp+48h] [rbp-B0h]
  int v55; // [rsp+4Ch] [rbp-ACh]
  char *array; // [rsp+50h] [rbp-A8h]
  int v57; // [rsp+58h] [rbp-A0h]
  int v58; // [rsp+5Ch] [rbp-9Ch]
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+60h] [rbp-98h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v60; // [rsp+70h] [rbp-88h]
  int v61; // [rsp+80h] [rbp-78h]
  int v62; // [rsp+84h] [rbp-74h]
  hkRelocationInfo reloc; // [rsp+88h] [rbp-70h]
  hkOstream dataOut; // [rsp+D8h] [rbp-20h]
  hkObjectCopier v65; // [rsp+F0h] [rbp-8h]
  __int64 v66; // [rsp+110h] [rbp+18h]
  char *retaddr; // [rsp+168h] [rbp+70h]
  hkStructureLayout layoutIn; // [rsp+170h] [rbp+78h]
  hkVtableClassRegistry *v69; // [rsp+180h] [rbp+88h]
  hkVtableClassRegistry *v70; // [rsp+188h] [rbp+90h]

  v70 = vtableClassRegistry;
  v6 = klassIn;
  v7 = dataIn;
  v8 = 0i64;
  v9 = vtableClassRegistry;
  v10 = previousCopies;
  buf.m_data = 0i64;
  buf.m_size = 0;
  buf.m_capacityAndFlags = 2147483648;
  hkOstream::hkOstream(&dataOut, &buf);
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
  array = 0i64;
  v57 = 0;
  v58 = 2147483648;
  v60.m_elem = 0i64;
  v60.m_numElems = 0;
  v60.m_hashMod = -1;
  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
  v11 = v57;
  v12 = &array[16 * v57];
  if ( v12 )
  {
    *(_QWORD *)v12 = v7;
    *((_QWORD *)v12 + 1) = v6;
    v11 = v57;
  }
  v57 = v11 + 1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &v60,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)v7,
    1ui64);
  *(_QWORD *)&v60.m_numElems = 0i64;
  v61 = 0;
  v62 = -1;
  v53 = 0i64;
  v54 = 0;
  v55 = 2147483648;
  hkStructureLayout::hkStructureLayout((hkStructureLayout *)&retaddr, &hkStructureLayout::HostLayoutRules);
  hkStructureLayout::hkStructureLayout(&layoutIn, &hkStructureLayout::HostLayoutRules);
  hkObjectCopier::hkObjectCopier(
    &v65,
    &layoutIn,
    (hkStructureLayout *)&retaddr,
    (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)loadedObjectRegistry);
  v13 = 0;
  if ( v57 > 0 )
  {
    do
    {
      v14 = *(const void **)&array[(_QWORD)v8];
      klassOut = *(hkClass **)&array[(_QWORD)v8 + 8];
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)&v60 + 8),
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        *(_QWORD *)&array[(_QWORD)v8],
        buf.m_size);
      v16 = reloc.m_global.m_size;
      if ( hkClass::hasVtable(klassOut, (hkBool *)&retaddr)->m_bool )
        klassOut = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))v9->vfptr[2].__first_virtual_table_function__)(
                                v9,
                                v14);
      v17 = v54;
      LODWORD(v66) = buf.m_size;
      if ( v54 == (v55 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v53, 24);
        v17 = v54;
      }
      v18 = &v53[24 * v17];
      if ( v18 )
      {
        *(_QWORD *)v18 = v66;
        *((_QWORD *)v18 + 1) = v14;
        *((_QWORD *)v18 + 2) = klassOut;
        v17 = v54;
      }
      v54 = v17 + 1;
      hkObjectCopier::copyObject(&v65, (hkResult *)&layoutIn, v14, klassOut, dataOut.m_writer.m_pntr, klassOut, &reloc);
      if ( (signed int)v16 < reloc.m_global.m_size )
      {
        v19 = v16;
        do
        {
          v20 = reloc.m_global.m_data[v19].m_toAddress;
          if ( v20 )
          {
            v21 = reloc.m_global.m_data[v19].m_toClass;
            if ( v21 )
            {
              if ( v10
                && (v22 = (void *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v10->m_map.m_elem,
                                    (unsigned __int64)reloc.m_global.m_data[v19].m_toAddress,
                                    0i64)) != 0i64 )
              {
                reloc.m_global.m_data[v19].m_toAddress = v22;
              }
              else if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                         &v60,
                                         (unsigned __int64)v20,
                                         0i64) )
              {
                v23 = v57;
                if ( v57 == (v58 & 0x3FFFFFFF) )
                {
                  hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
                  v23 = v57;
                }
                v24 = &array[16 * v23];
                if ( v24 )
                {
                  *(_QWORD *)v24 = v20;
                  *((_QWORD *)v24 + 1) = v21;
                  v23 = v57;
                }
                v57 = v23 + 1;
                hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                  &v60,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  (unsigned __int64)v20,
                  1ui64);
              }
            }
          }
          LODWORD(v16) = v16 + 1;
          ++v19;
        }
        while ( (signed int)v16 < reloc.m_global.m_size );
        v9 = v69;
      }
      ++v13;
      v8 += 16;
    }
    while ( v13 < v57 );
    LODWORD(v8) = 0;
  }
  v25 = buf.m_size;
  if ( buf.m_size )
  {
    v26 = v70;
    v27 = 4;
    if ( v70 )
      v27 = 16 * v54 + 4;
    v28 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = (char *)hkMemoryRouter::easyAlloc(v28[11], v25 + v27);
    v8 = &v29[buf.m_size];
    v30 = v29;
    retaddr = &v29[buf.m_size];
    hkString::memCpy(v29, buf.m_data, buf.m_size);
    v31 = 0;
    if ( reloc.m_local.m_size > 0 )
    {
      v32 = 0i64;
      do
      {
        ++v31;
        ++v32;
        *(_QWORD *)&v30[reloc.m_local.m_data[v32 - 1].m_fromOffset] = &v30[*((signed int *)&reloc.m_local.m_data[v32] - 1)];
      }
      while ( v31 < reloc.m_local.m_size );
    }
    v33 = 0;
    if ( reloc.m_global.m_size > 0 )
    {
      v34 = 0i64;
      do
      {
        v35 = (char *)reloc.m_global.m_data[v34].m_toAddress;
        v36 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)&v60 + 8),
                (unsigned __int64)reloc.m_global.m_data[v34].m_toAddress,
                0xFFFFFFFFFFFFFFFFui64);
        if ( v36 != -1 )
          v35 = &v30[v36];
        ++v33;
        ++v34;
        *(_QWORD *)&v30[reloc.m_global.m_data[v34 - 1].m_fromOffset] = v35;
      }
      while ( v33 < reloc.m_global.m_size );
    }
    v37 = v54;
    if ( v10 )
    {
      v38 = 0;
      if ( v54 > 0 )
      {
        v39 = 0i64;
        do
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v10->m_map.m_elem,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            *(_QWORD *)&v53[v39 + 8],
            (unsigned __int64)&v30[*(signed int *)&v53[v39]]);
          v37 = v54;
          ++v38;
          v39 += 24i64;
        }
        while ( v38 < v54 );
      }
    }
    if ( v26 )
    {
      v40 = 0;
      if ( v37 > 0 )
      {
        v41 = retaddr;
        v42 = 0i64;
        do
        {
          v43 = v26->vfptr;
          v44 = (hkClass **)&v53[v42];
          v45 = hkClass::getName(*(hkClass **)&v53[v42 + 16]);
          ((void (__fastcall *)(hkVtableClassRegistry *, char *, const char *))v43[2].__vecDelDtor)(
            v26,
            &v30[*(signed int *)v44],
            v45);
          v46 = v26->vfptr;
          v47 = hkClass::getName(v44[2]);
          ++v40;
          v42 += 24i64;
          *(_QWORD *)v41 = ((__int64 (__fastcall *)(hkVtableClassRegistry *, const char *))v46[3].__first_virtual_table_function__)(
                             v26,
                             v47);
          v41 += 16;
          *((_QWORD *)v41 - 1) = &v30[*(signed int *)v44];
          v37 = v54;
        }
        while ( v40 < v54 );
        v8 = retaddr;
      }
      v48 = 0;
      if ( v37 > 0 )
      {
        v49 = 0i64;
        do
        {
          v50 = v53;
          v51 = hkClass::getAttribute(*(hkClass **)&v53[v49 + 16], "hk.PostFinish");
          if ( v51 )
            (*(void (__fastcall **)(char *))v51->m_object)(&v30[*(signed int *)&v50[v49]]);
          v37 = v54;
          ++v48;
          v49 += 24i64;
        }
        while ( v48 < v54 );
      }
      *(_DWORD *)&v8[16 * v37] = v37;
      LODWORD(v8) = 0;
    }
    else
    {
      *(_DWORD *)v8 = 0;
      LODWORD(v8) = 0;
    }
  }
  else
  {
    v30 = 0i64;
  }
  hkObjectCopier::~hkObjectCopier(&v65);
  v54 = (signed int)v8;
  if ( v55 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v53,
      24 * (v55 & 0x3FFFFFFF));
  v53 = 0i64;
  v55 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)((char *)&v60 + 8),
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v60.m_numElems);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v60,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v60);
  v57 = (signed int)v8;
  if ( v58 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * v58);
  array = 0i64;
  v58 = 2147483648;
  hkRelocationInfo::~hkRelocationInfo(&reloc);
  hkOstream::~hkOstream(&dataOut);
  buf.m_size = (signed int)v8;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
  return v30;
}

// File Line: 200
// RVA: 0xE6BA80
hkResult *__fastcall hkDeepCopier::freeDeepCopy(hkResult *result, void *data)
{
  hkResult *v2; // r14
  char *v3; // rsi
  hkMemoryAllocator **v4; // rax
  unsigned __int64 v5; // rbx
  int v6; // er8
  __int64 v7; // rdi
  void **v8; // rbx
  hkMemoryAllocator **v9; // rax

  v2 = result;
  v3 = (char *)data;
  v4 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = hkMemoryRouter::getEasyAllocSize(v4[11], v3);
  v6 = *(_DWORD *)&v3[v5 - 4];
  if ( v6 )
  {
    v7 = *(signed int *)&v3[v5 - 4];
    v8 = (void **)&v3[v5 - (16 * v6 + 4)];
    if ( v6 > 0 )
    {
      do
      {
        if ( *v8 )
          hkTypeInfo::cleanupLoadedObject((hkTypeInfo *)*v8, v8[1]);
        v8 += 2;
        --v7;
      }
      while ( v7 );
    }
  }
  v9 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hkMemoryRouter::easyFree(v9[11], v3);
  v2->m_enum = 0;
  return v2;
}

