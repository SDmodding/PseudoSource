// File Line: 43
// RVA: 0xE6B3E0
char *__fastcall hkDeepCopier::deepCopy(
        unsigned __int64 dataIn,
        hkClass *klassIn,
        hkPointerMap<void const *,void *,hkContainerHeapAllocator> *previousCopies,
        hkVtableClassRegistry *vtableClassRegistry,
        hkTypeInfoRegistry *loadedObjectRegistry,
        hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int> flags)
{
  __int64 v8; // r12
  hkVtableClassRegistry *v9; // r14
  int v11; // ecx
  unsigned __int64 *v12; // rax
  int i; // r15d
  const void *v14; // rdi
  hkClass *klassOut; // rbx
  __int64 m_size; // rsi
  int v17; // edx
  char *v18; // r9
  __int64 v19; // rdi
  void *m_toAddress; // rbx
  hkClass *m_toClass; // r14
  void *v22; // rax
  int v23; // ecx
  char *v24; // rax
  int v25; // edi
  hkVtableClassRegistry *v26; // r15
  int v27; // ebx
  hkMemoryAllocator **Value; // rax
  char *v29; // rax
  char *v30; // r12
  char *v31; // rsi
  int v32; // r8d
  __int64 v33; // rdx
  int v34; // r14d
  __int64 v35; // rdi
  char *v36; // rbx
  int v37; // eax
  int v38; // ecx
  int v39; // edi
  __int64 v40; // rbx
  int v41; // r13d
  char *v42; // r14
  __int64 v43; // r12
  hkBaseObjectVtbl *vfptr; // rbx
  hkClass **v45; // rdi
  const char *Name; // rax
  hkBaseObjectVtbl *v47; // rbx
  const char *v48; // rax
  int v49; // ebx
  __int64 v50; // rdi
  char *v51; // r14
  hkVariant *Attribute; // rax
  char *v54; // [rsp+40h] [rbp-B8h] BYREF
  int v55; // [rsp+48h] [rbp-B0h]
  int v56; // [rsp+4Ch] [rbp-ACh]
  char *array; // [rsp+50h] [rbp-A8h] BYREF
  int v58; // [rsp+58h] [rbp-A0h]
  int v59; // [rsp+5Ch] [rbp-9Ch]
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+60h] [rbp-98h] BYREF
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v61; // [rsp+70h] [rbp-88h] BYREF
  int v62; // [rsp+80h] [rbp-78h]
  int v63; // [rsp+84h] [rbp-74h]
  hkRelocationInfo reloc; // [rsp+88h] [rbp-70h] BYREF
  hkOstream dataOut; // [rsp+D8h] [rbp-20h] BYREF
  hkObjectCopier v66; // [rsp+F0h] [rbp-8h] BYREF
  __int64 v67; // [rsp+110h] [rbp+18h]
  char *retaddr; // [rsp+168h] [rbp+70h] BYREF
  hkStructureLayout layoutIn; // [rsp+170h] [rbp+78h] BYREF
  hkVtableClassRegistry *v70; // [rsp+180h] [rbp+88h]
  hkVtableClassRegistry *v71; // [rsp+188h] [rbp+90h]

  v71 = vtableClassRegistry;
  v8 = 0i64;
  v9 = vtableClassRegistry;
  buf.m_data = 0i64;
  buf.m_size = 0;
  buf.m_capacityAndFlags = 0x80000000;
  hkOstream::hkOstream(&dataOut, &buf);
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
  array = 0i64;
  v58 = 0;
  v59 = 0x80000000;
  v61.m_elem = 0i64;
  v61.m_numElems = 0;
  v61.m_hashMod = -1;
  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
  v11 = v58;
  v12 = (unsigned __int64 *)&array[16 * v58];
  if ( v12 )
  {
    *v12 = dataIn;
    v12[1] = (unsigned __int64)klassIn;
    v11 = v58;
  }
  v58 = v11 + 1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    &v61,
    &hkContainerHeapAllocator::s_alloc,
    dataIn,
    1ui64);
  *(_QWORD *)&v61.m_numElems = 0i64;
  v62 = 0;
  v63 = -1;
  v54 = 0i64;
  v55 = 0;
  v56 = 0x80000000;
  hkStructureLayout::hkStructureLayout(
    (hkStructureLayout *)&retaddr,
    (hkStructureLayout *)&hkStructureLayout::HostLayoutRules);
  hkStructureLayout::hkStructureLayout(&layoutIn, (hkStructureLayout *)&hkStructureLayout::HostLayoutRules);
  hkObjectCopier::hkObjectCopier(
    &v66,
    &layoutIn,
    (hkStructureLayout *)&retaddr,
    (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)loadedObjectRegistry);
  for ( i = 0; i < v58; v8 += 16i64 )
  {
    v14 = *(const void **)&array[v8];
    klassOut = *(hkClass **)&array[v8 + 8];
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v61.m_numElems,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)v14,
      buf.m_size);
    m_size = reloc.m_global.m_size;
    if ( hkClass::hasVtable(klassOut, (hkBool *)&retaddr)->m_bool )
      klassOut = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, const void *))v9->vfptr[2].__first_virtual_table_function__)(
                              v9,
                              v14);
    v17 = v55;
    LODWORD(v67) = buf.m_size;
    if ( v55 == (v56 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v54, 24);
      v17 = v55;
    }
    v18 = &v54[24 * v17];
    if ( v18 )
    {
      *(_QWORD *)v18 = v67;
      *((_QWORD *)v18 + 1) = v14;
      *((_QWORD *)v18 + 2) = klassOut;
      v17 = v55;
    }
    v55 = v17 + 1;
    hkObjectCopier::copyObject(&v66, (hkResult *)&layoutIn, v14, klassOut, dataOut.m_writer.m_pntr, klassOut, &reloc);
    if ( (int)m_size < reloc.m_global.m_size )
    {
      v19 = m_size;
      do
      {
        m_toAddress = reloc.m_global.m_data[v19].m_toAddress;
        if ( m_toAddress )
        {
          m_toClass = reloc.m_global.m_data[v19].m_toClass;
          if ( m_toClass )
          {
            if ( previousCopies
              && (v22 = (void *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                  &previousCopies->m_map,
                                  (unsigned __int64)reloc.m_global.m_data[v19].m_toAddress,
                                  0i64)) != 0i64 )
            {
              reloc.m_global.m_data[v19].m_toAddress = v22;
            }
            else if ( !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                       &v61,
                                       (unsigned __int64)m_toAddress,
                                       0i64) )
            {
              v23 = v58;
              if ( v58 == (v59 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
                v23 = v58;
              }
              v24 = &array[16 * v23];
              if ( v24 )
              {
                *(_QWORD *)v24 = m_toAddress;
                *((_QWORD *)v24 + 1) = m_toClass;
                v23 = v58;
              }
              v58 = v23 + 1;
              hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                &v61,
                &hkContainerHeapAllocator::s_alloc,
                (unsigned __int64)m_toAddress,
                1ui64);
            }
          }
        }
        LODWORD(m_size) = m_size + 1;
        ++v19;
      }
      while ( (int)m_size < reloc.m_global.m_size );
      v9 = v70;
    }
    ++i;
  }
  v25 = buf.m_size;
  if ( buf.m_size )
  {
    v26 = v71;
    v27 = 4;
    if ( v71 )
      v27 = 16 * v55 + 4;
    Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v29 = (char *)hkMemoryRouter::easyAlloc(Value[11], v25 + v27);
    v30 = &v29[buf.m_size];
    v31 = v29;
    retaddr = v30;
    hkString::memCpy(v29, buf.m_data, buf.m_size);
    v32 = 0;
    if ( reloc.m_local.m_size > 0 )
    {
      v33 = 0i64;
      do
      {
        ++v32;
        ++v33;
        *(_QWORD *)&v31[reloc.m_local.m_data[v33 - 1].m_fromOffset] = &v31[reloc.m_local.m_data[v33 - 1].m_toOffset];
      }
      while ( v32 < reloc.m_local.m_size );
    }
    v34 = 0;
    if ( reloc.m_global.m_size > 0 )
    {
      v35 = 0i64;
      do
      {
        v36 = (char *)reloc.m_global.m_data[v35].m_toAddress;
        v37 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v61.m_numElems,
                (unsigned __int64)v36,
                0xFFFFFFFFFFFFFFFFui64);
        if ( v37 != -1 )
          v36 = &v31[v37];
        ++v34;
        *(_QWORD *)&v31[reloc.m_global.m_data[v35++].m_fromOffset] = v36;
      }
      while ( v34 < reloc.m_global.m_size );
    }
    v38 = v55;
    if ( previousCopies )
    {
      v39 = 0;
      if ( v55 > 0 )
      {
        v40 = 0i64;
        do
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &previousCopies->m_map,
            &hkContainerHeapAllocator::s_alloc,
            *(_QWORD *)&v54[v40 + 8],
            (unsigned __int64)&v31[*(int *)&v54[v40]]);
          v38 = v55;
          ++v39;
          v40 += 24i64;
        }
        while ( v39 < v55 );
      }
    }
    if ( v26 )
    {
      v41 = 0;
      if ( v38 > 0 )
      {
        v42 = retaddr;
        v43 = 0i64;
        do
        {
          vfptr = v26->vfptr;
          v45 = (hkClass **)&v54[v43];
          Name = hkClass::getName(*(hkClass **)&v54[v43 + 16]);
          ((void (__fastcall *)(hkVtableClassRegistry *, char *, const char *))vfptr[2].__vecDelDtor)(
            v26,
            &v31[*(int *)v45],
            Name);
          v47 = v26->vfptr;
          v48 = hkClass::getName(v45[2]);
          ++v41;
          v43 += 24i64;
          *(_QWORD *)v42 = ((__int64 (__fastcall *)(hkVtableClassRegistry *, const char *))v47[3].__first_virtual_table_function__)(
                             v26,
                             v48);
          v42 += 16;
          *((_QWORD *)v42 - 1) = &v31[*(int *)v45];
          v38 = v55;
        }
        while ( v41 < v55 );
        v30 = retaddr;
      }
      v49 = 0;
      if ( v38 > 0 )
      {
        v50 = 0i64;
        do
        {
          v51 = v54;
          Attribute = hkClass::getAttribute(*(hkClass **)&v54[v50 + 16], "hk.PostFinish");
          if ( Attribute )
            (*(void (__fastcall **)(char *))Attribute->m_object)(&v31[*(int *)&v51[v50]]);
          v38 = v55;
          ++v49;
          v50 += 24i64;
        }
        while ( v49 < v55 );
      }
      *(_DWORD *)&v30[16 * v38] = v38;
    }
    else
    {
      *(_DWORD *)v30 = 0;
    }
  }
  else
  {
    v31 = 0i64;
  }
  hkObjectCopier::~hkObjectCopier(&v66);
  v55 = 0;
  if ( v56 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v54, 24 * (v56 & 0x3FFFFFFF));
  v54 = 0i64;
  v56 = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v61.m_numElems,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v61.m_numElems);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v61,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v61);
  v58 = 0;
  if ( v59 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v59);
  array = 0i64;
  v59 = 0x80000000;
  hkRelocationInfo::~hkRelocationInfo(&reloc);
  hkOstream::~hkOstream(&dataOut);
  buf.m_size = 0;
  if ( buf.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
  return v31;
}    &hkContainerHeapAllocator::s_alloc,
      buf.m_data,
      buf.m_capacityAndFlags & 0x3FFFFFFF);
  return v31;
}

// File Line: 200
// RVA: 0xE6BA80
hkResult *__fastcall hkDeepCopier::freeDeepCopy(hkResult *result, int *data)
{
  hkMemoryAllocator **Value; // rax
  unsigned __int64 EasyAllocSize; // rbx
  int v6; // r8d
  __int64 v7; // rdi
  void **v8; // rbx
  hkMemoryAllocator **v9; // rax

  Value = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  EasyAllocSize = hkMemoryRouter::getEasyAllocSize(Value[11], data);
  v6 = *(int *)((char *)data + EasyAllocSize - 4);
  if ( v6 )
  {
    v7 = *(int *)((char *)data + EasyAllocSize - 4);
    v8 = (void **)((char *)data + EasyAllocSize - (16 * v6 + 4));
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
  hkMemoryRouter::easyFree(v9[11], data);
  result->m_enum = HK_SUCCESS;
  return result;
}

