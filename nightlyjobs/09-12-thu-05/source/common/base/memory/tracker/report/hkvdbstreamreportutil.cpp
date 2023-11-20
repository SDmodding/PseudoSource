// File Line: 16
// RVA: 0x1301500
void __fastcall writeModuleInfo(const char *text, void *context)
{
  const char *v2; // rbx
  hkOstream *v3; // rax
  hkOstream *v4; // rax

  v2 = text;
  v3 = hkOstream::operator<<((hkOstream *)context, "Module( str=r");
  v4 = hkOstream::operator<<(v3, v2);
  hkOstream::operator<<(v4, " )\n");
}

// File Line: 32
// RVA: 0x1301540
void __fastcall writeStackTrace(const char *text, void *context)
{
  hkOstream **v2; // rsi
  const char *v3; // rbx
  unsigned __int64 v4; // rdi
  int v5; // eax
  hkOstream *v6; // rcx
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkSubString texta; // [rsp+20h] [rbp-18h]

  v2 = (hkOstream **)context;
  v3 = text;
  v4 = *(_QWORD *)(**((_QWORD **)context + 1) + 8i64 * *((signed int *)context + 4));
  v5 = hkString::lastIndexOf(text, 10);
  v6 = *v2;
  texta.m_start = v3;
  texta.m_end = &v3[v5];
  v7 = hkOstream::operator<<(v6, "Location( loc=");
  v8 = hkOstream::operator<<(v7, v4, (int)v7);
  v9 = hkOstream::operator<<(v8, ", str=r\"\"\"");
  v10 = operator<<(v9, &texta);
  hkOstream::operator<<(v10, "\"\"\" )\n");
  ++*((_DWORD *)v2 + 4);
}

// File Line: 42
// RVA: 0x13015E0
void __fastcall writeMemorySystemStats(hkTrackerScanSnapshot *scanSnapshot, hkOstream *stream)
{
  hkOstream *v2; // rsi
  const char *v3; // rax
  const char *v4; // rbx
  char *i; // rdi

  v2 = stream;
  v3 = hkTrackerScanSnapshot::getMemorySystemStatistics(scanSnapshot);
  v4 = v3;
  if ( v3 )
  {
    for ( i = hkString::strChr(v3, 10); i; i = hkString::strChr(i + 1, 10) )
    {
      hkOstream::operator<<(v2, "Statistics( str=");
      hkOstream::write(v2, v4, (unsigned int)((_DWORD)i - (_DWORD)v4));
      hkOstream::operator<<(v2, " )\n");
      v4 = i + 1;
    }
  }
}

// File Line: 58
// RVA: 0x1300B80
void __fastcall hkVdbStreamReportUtil::generateReport(hkTrackerScanSnapshot *scanSnapshot, hkOstream *stream)
{
  __int64 v2; // r14
  hkTrackerScanSnapshot *v3; // r13
  hkOstream *v4; // rbx
  hkStackTracer::CallTree *v5; // rsi
  unsigned __int64 v6; // rdi
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  int v9; // eax
  int v10; // er15
  __int64 v11; // r12
  hkMemorySnapshot::Provider *v12; // rsi
  int v13; // eax
  int v14; // edi
  int *v15; // rax
  __int64 v16; // r8
  __int64 v17; // r9
  __int64 v18; // r8
  int v19; // er12
  __int64 v20; // r15
  hkMemorySnapshot::Allocation *v21; // r14
  int v22; // edx
  int v23; // eax
  unsigned int v24; // edi
  int v25; // er9
  int v26; // edx
  hkOstream *v27; // rax
  hkOstream *v28; // rax
  int v29; // eax
  __int64 v30; // rdi
  int v31; // esi
  __int64 v32; // r9
  const void *v33; // r8
  int v34; // eax
  int v35; // er12
  __int64 v36; // r15
  hkTrackerScanSnapshot::Block *v37; // rsi
  hkTrackerTypeTreeNode *v38; // r14
  int v39; // edi
  hkOstream *v40; // rax
  hkOstream *v41; // rax
  hkOstream *v42; // rax
  hkOstream *v43; // rax
  hkOstream *v44; // rax
  hkOstream *v45; // rax
  hkOstream *v46; // rax
  hkOstream *v47; // rax
  hkOstream *v48; // rax
  hkOstream *v49; // rax
  int v50; // er8
  __int64 v51; // r9
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v52; // r10
  int v53; // edx
  signed __int64 v54; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v55; // rax
  int v56; // edi
  unsigned __int64 v57; // rsi
  int v58; // edx
  signed __int64 v59; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v60; // rax
  bool v61; // zf
  bool v62; // sf
  int v63; // edi
  __int64 v64; // rsi
  int v65; // er12
  int v66; // edi
  signed int v67; // er8
  __int64 v68; // r15
  hkTrackerScanSnapshot::Block **v69; // rax
  __int64 v70; // rcx
  unsigned __int64 *v71; // rsi
  int v72; // er14
  int v73; // edx
  hkOstream *v74; // rax
  hkOstream *v75; // rax
  int v76; // edi
  __int64 v77; // rsi
  int v78; // ecx
  __int64 sizeElem; // [rsp+20h] [rbp-69h]
  __int64 sizeElema; // [rsp+20h] [rbp-69h]
  __int64 v81; // [rsp+28h] [rbp-61h]
  __int64 v82; // [rsp+28h] [rbp-61h]
  __int64 v83[2]; // [rsp+30h] [rbp-59h]
  unsigned __int64 *array; // [rsp+40h] [rbp-49h]
  int v85; // [rsp+48h] [rbp-41h]
  int v86; // [rsp+4Ch] [rbp-3Dh]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v87; // [rsp+50h] [rbp-39h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v88; // [rsp+60h] [rbp-29h]
  hkOstream *context; // [rsp+70h] [rbp-19h]
  unsigned __int64 **v90; // [rsp+78h] [rbp-11h]
  int v91; // [rsp+80h] [rbp-9h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v92; // [rsp+88h] [rbp-1h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v93; // [rsp+98h] [rbp+Fh]
  hkBool result; // [rsp+F0h] [rbp+67h]
  hkStackTracer v95; // [rsp+100h] [rbp+77h]
  unsigned __int64 out; // [rsp+108h] [rbp+7Fh]

  v2 = 0i64;
  v3 = scanSnapshot;
  v4 = stream;
  v88.m_hashMod = -1;
  v87.m_hashMod = -1;
  v88.m_elem = 0i64;
  v88.m_numElems = 0;
  v87.m_elem = 0i64;
  v87.m_numElems = 0;
  v93.m_elem = 0i64;
  v93.m_numElems = 0;
  v93.m_hashMod = -1;
  v92.m_elem = 0i64;
  v92.m_numElems = 0;
  v92.m_hashMod = -1;
  hkStackTracer::hkStackTracer(&v95);
  v5 = &v3->m_rawSnapshot.m_callTree;
  if ( v3->m_blocks.m_size && hkStackTracer::CallTree::isEmpty(&v3->m_rawSnapshot.m_callTree, &result)->m_bool )
    hkOstream::operator<<(
      v4,
      "#NOTE: Could not retrieve stack information. Are you using the hkCheckingMemorySystem?\n#\n");
  hkOstream::operator<<(v4, "#V <integer> - Version number\n");
  hkOstream::operator<<(v4, "#Date(ts=<timestamp>) - Date of capture\n");
  hkOstream::operator<<(v4, "#Module(mod=<platform-dependent module/symbol identifier string>) - Module information\n");
  hkOstream::operator<<(v4, "#Statistics(str=<string>) - Raw memory system Statistics\n");
  hkOstream::operator<<(
    v4,
    "#Provider(id=<provider id>, name=<name>, parIds=[<parent>*]) - Hierarchy of providers (allocators)\n");
  hkOstream::operator<<(
    v4,
    "#Router(temp=<provider id>, stack=<provider id>, heap=<provider id>, debug=<provider id>, solver=<provider id>) - Me"
    "mory router wiring\n");
  hkOstream::operator<<(
    v4,
    "#Allocation(addr=<address>, size=<size>, provId=<provider id>, status=<status>, callstackId=<callstack id>) - Allocation report\n");
  hkOstream::operator<<(v4, "#Type(id=<type id>, name=<type name>) - Block type definition\n");
  hkOstream::operator<<(
    v4,
    "#Block(id=<block id>, typeId=<type id>, addr=<address>, size=<size>) - Tracker block report\n");
  hkOstream::operator<<(
    v4,
    "#References(blockId=<block id>, refIds=[<owned block id>+]) - Blocks referenced by a given block\n");
  hkOstream::operator<<(
    v4,
    "#Callstack(id=<callstack id>, locations=[<location>+]) - Callstack declaration for a specific address\n");
  hkOstream::operator<<(v4, "#Location(loc=<location>, str=<string name>) - Program location\n");
  hkOstream::operator<<(v4, "V 1\n");
  v6 = hkGetSystemTime();
  v7 = hkOstream::operator<<(v4, "Date( ts=");
  v8 = hkOstream::operator<<(v7, v6, (int)v7);
  hkOstream::operator<<(v8, " )\n");
  hkStackTracer::getModuleInfo(&v95, writeModuleInfo, v4);
  writeMemorySystemStats(v3, v4);
  v10 = 0;
  if ( v3->m_rawSnapshot.m_providers.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = &v3->m_rawSnapshot.m_providers.m_data[v11];
      hkOstream::printf(v4, "Provider( id=%i, name=%s, parIds=[", v9);
      v14 = v2;
      if ( v12->m_parentIndices.m_size > 0 )
      {
        do
        {
          v15 = v12->m_parentIndices.m_data;
          v16 = *(unsigned int *)((char *)v15 + v2);
          hkOstream::printf(v4, "%i", (int)v15);
          v13 = v12->m_parentIndices.m_size - 1;
          if ( v14 != v13 )
            v13 = (unsigned __int64)hkOstream::operator<<(v4, 44);
          ++v14;
          v2 += 4i64;
        }
        while ( v14 < v12->m_parentIndices.m_size );
        v2 = 0i64;
      }
      hkOstream::printf(v4, "] )\n", v13);
      ++v10;
      ++v11;
    }
    while ( v10 < v3->m_rawSnapshot.m_providers.m_size );
    v5 = &v3->m_rawSnapshot.m_callTree;
  }
  v17 = (unsigned int)v3->m_rawSnapshot.m_routerWiring[1];
  v18 = (unsigned int)v3->m_rawSnapshot.m_routerWiring[0];
  LODWORD(v83[0]) = v3->m_rawSnapshot.m_routerWiring[4];
  LODWORD(v81) = v3->m_rawSnapshot.m_routerWiring[3];
  LODWORD(sizeElem) = v3->m_rawSnapshot.m_routerWiring[2];
  hkOstream::printf(
    v4,
    "Router( temp=%i, stack=%i, heap=%i, debug=%i, solver=%i )\n",
    v3->m_rawSnapshot.m_routerWiring[2],
    sizeElem,
    v81,
    v83[0]);
  v19 = v2;
  if ( v3->m_rawSnapshot.m_allocations.m_size > 0 )
  {
    v20 = 0i64;
    do
    {
      v21 = &v3->m_rawSnapshot.m_allocations.m_data[v20];
      if ( v21->m_traceId != -1
        && !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            &v92,
                            v21->m_traceId,
                            0i64) )
      {
        v22 = v21->m_traceId;
        array = 0i64;
        v85 = 0;
        v86 = 2147483648;
        v23 = hkStackTracer::CallTree::getCallStackSize(v5, v22);
        v24 = v23;
        if ( (v86 & 0x3FFFFFFF) >= v23 )
        {
          *(_DWORD *)&result.m_bool = 0;
        }
        else
        {
          v25 = v23;
          if ( v23 < 2 * (v86 & 0x3FFFFFFF) )
            v25 = 2 * (v86 & 0x3FFFFFFF);
          hkArrayUtil::_reserve(
            (hkResult *)&result,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &array,
            v25,
            8);
        }
        v26 = v21->m_traceId;
        v85 = v24;
        hkStackTracer::CallTree::getCallStack(v5, v26, array, v24);
        v27 = hkOstream::operator<<(v4, "Callstack( id=");
        v28 = hkOstream::operator<<(v27, v21->m_traceId, (int)v27);
        v29 = (unsigned __int64)hkOstream::operator<<(v28, ", locations=[");
        v30 = 0i64;
        v31 = 0;
        if ( v85 > 0 )
        {
          do
          {
            hkOstream::operator<<(v4, *(unsigned __int64 *)((char *)array + v30), v29);
            if ( v31 != v85 - 1 )
              hkOstream::operator<<(v4, 44);
            v29 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
                    &v87,
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    *(unsigned __int64 *)((char *)array + v30),
                    0i64);
            ++v31;
            v30 += 8i64;
          }
          while ( v31 < v85 );
          LODWORD(v30) = 0;
        }
        hkOstream::operator<<(v4, "] )\n");
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v92,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v21->m_traceId,
          1ui64);
        v85 = v30;
        if ( v86 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            8 * v86);
        array = 0i64;
        v86 = 2147483648;
      }
      v32 = (unsigned int)v21->m_size;
      v33 = v21->m_start;
      LODWORD(v82) = v21->m_status.m_storage;
      LODWORD(sizeElema) = v21->m_sourceId;
      hkOstream::printf(v4, "Allocation( addr=0x%p, size=%i, provId=%i, status=%i", v21->m_sourceId, sizeElema, v82);
      if ( v21->m_traceId != -1 )
        hkOstream::printf(v4, ", callstackId=%i", v34);
      hkOstream::operator<<(v4, " )\n");
      ++v19;
      ++v20;
      v5 = &v3->m_rawSnapshot.m_callTree;
    }
    while ( v19 < v3->m_rawSnapshot.m_allocations.m_size );
    v2 = 0i64;
  }
  v35 = v2;
  if ( v3->m_blocks.m_size > 0 )
  {
    v36 = 0i64;
    do
    {
      v37 = v3->m_blocks.m_data[v36];
      v38 = v37->m_type;
      if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
             &v88,
             (hkResult *)&result,
             (unsigned __int64)v37->m_type,
             &out)->m_enum )
      {
        v39 = v88.m_numElems & 0x7FFFFFFF;
        v40 = hkOstream::operator<<(v4, "Type( id=");
        v41 = hkOstream::operator<<(v40, v39, (int)v40);
        hkOstream::operator<<(v41, ", name=");
        hkTrackerTypeTreeNode::dumpType(v37->m_type, v4);
        hkOstream::operator<<(v4, " )\n");
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          &v88,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          (unsigned __int64)v38,
          v39);
      }
      else
      {
        v39 = out;
      }
      v42 = hkOstream::operator<<(v4, "Block( id=");
      v43 = hkOstream::operator<<(v42, v35, (int)v42);
      v44 = hkOstream::operator<<(v43, ", typeId=");
      v45 = hkOstream::operator<<(v44, v39, (int)v44);
      v46 = hkOstream::operator<<(v45, ", addr=0x");
      v47 = hkOstream::operator<<(v46, v37->m_start, (int)v46);
      v48 = hkOstream::operator<<(v47, ", size=");
      v49 = hkOstream::operator<<(v48, v37->m_size, (int)v48);
      hkOstream::operator<<(v49, " )\n");
      ++v35;
      ++v36;
    }
    while ( v35 < v3->m_blocks.m_size );
    v2 = 0i64;
  }
  array = 0i64;
  v50 = 0;
  v85 = 0;
  v86 = 2147483648;
  v51 = v87.m_numElems & 0x7FFFFFFF;
  if ( (v87.m_numElems & 0x7FFFFFFF) > 0 )
  {
    if ( (signed int)v51 < 0 )
      LODWORD(v51) = v2;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v51,
      8);
    v50 = v85;
  }
  v52 = v87.m_elem;
  v53 = 0;
  v54 = 0i64;
  if ( v87.m_hashMod >= 0 )
  {
    v55 = v87.m_elem;
    do
    {
      if ( v55->key != -1i64 )
        break;
      ++v54;
      ++v53;
      ++v55;
    }
    while ( v54 <= v87.m_hashMod );
  }
  v56 = v53;
  if ( v53 <= v87.m_hashMod )
  {
    do
    {
      v57 = v52[v56].key;
      if ( v50 == (v86 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v50 = v85;
      }
      v58 = v56 + 1;
      array[v50] = v57;
      v52 = v87.m_elem;
      v50 = v85 + 1;
      v59 = v56 + 1;
      ++v85;
      if ( v59 <= v87.m_hashMod )
      {
        v60 = &v87.m_elem[v58];
        do
        {
          if ( v60->key != -1i64 )
            break;
          ++v59;
          ++v58;
          ++v60;
        }
        while ( v59 <= v87.m_hashMod );
      }
      v56 = v58;
    }
    while ( v58 <= v87.m_hashMod );
  }
  if ( v50 )
  {
    v90 = &array;
    context = v4;
    v91 = 0;
    hkStackTracer::dumpStackTrace(&v95, array, v50, writeStackTrace, &context);
  }
  v85 = v2;
  if ( v86 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64 *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(8 * v86),
      v51);
  v61 = v3->m_blocks.m_size == 0;
  v62 = v3->m_blocks.m_size < 0;
  context = 0i64;
  v90 = (unsigned __int64 **)-4294967296i64;
  v63 = 0;
  if ( !v62 && !v61 )
  {
    v64 = 0i64;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&context,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v3->m_blocks.m_data[v64],
        v63++);
      ++v64;
    }
    while ( v63 < v3->m_blocks.m_size );
  }
  v65 = v2;
  if ( v3->m_blocks.m_size > 0 )
  {
    *(_QWORD *)&result.m_bool = 0i64;
    v66 = 0;
    do
    {
      v67 = 2147483648;
      v68 = *(__int64 *)((char *)v3->m_blocks.m_data + v2);
      v69 = v3->m_references.m_data;
      v70 = *(signed int *)(v68 + 28);
      array = 0i64;
      v85 = 0;
      v86 = 2147483648;
      v71 = (unsigned __int64 *)&v69[v70];
      if ( *(_DWORD *)(v68 + 32) > 0 )
      {
        do
        {
          v72 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&context,
                  *v71,
                  0xFFFFFFFFFFFFFFFFui64);
          if ( v72 != -1 )
          {
            v73 = v85;
            if ( v85 == (v86 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
              v73 = v85;
            }
            *((_DWORD *)array + v73) = v72;
            ++v85;
          }
          ++v66;
          ++v71;
        }
        while ( v66 < *(_DWORD *)(v68 + 32) );
        if ( v85 )
        {
          v74 = hkOstream::operator<<(v4, "References( blockId=");
          v75 = hkOstream::operator<<(v74, v65, (int)v74);
          hkOstream::operator<<(v75, ", refIds=[");
          v76 = 0;
          if ( v85 > 0 )
          {
            v77 = 0i64;
            do
            {
              hkOstream::operator<<(v4, *(_DWORD *)((char *)array + v77), (int)array);
              v78 = v85;
              if ( v76 != v85 - 1 )
              {
                hkOstream::operator<<(v4, 44);
                v78 = v85;
              }
              ++v76;
              v77 += 4i64;
            }
            while ( v76 < v78 );
          }
          hkOstream::operator<<(v4, "] )\n");
        }
        v2 = *(_QWORD *)&result.m_bool;
        v67 = v86;
      }
      v66 = 0;
      v85 = 0;
      if ( v67 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64 *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          array,
          (unsigned int)(4 * v67),
          v51);
      v2 += 8i64;
      ++v65;
      array = 0i64;
      v86 = 2147483648;
      *(_QWORD *)&result.m_bool = v2;
    }
    while ( v65 < v3->m_blocks.m_size );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&context,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&context);
  hkStackTracer::~hkStackTracer(&v95);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v92,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v92);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v93,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v93);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v87,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v87);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v88,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v88);
}

