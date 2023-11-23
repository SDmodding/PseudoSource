// File Line: 16
// RVA: 0x1301500
void __fastcall writeModuleInfo(const char *text, hkOstream *context)
{
  hkOstream *v3; // rax
  hkOstream *v4; // rax

  v3 = hkOstream::operator<<(context, "Module( str=r");
  v4 = hkOstream::operator<<(v3, text);
  hkOstream::operator<<(v4, " )\n");
}

// File Line: 32
// RVA: 0x1301540
void __fastcall writeStackTrace(const char *text, int *context)
{
  unsigned __int64 v4; // rdi
  int IndexOf; // eax
  hkOstream *v6; // rcx
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkSubString texta; // [rsp+20h] [rbp-18h] BYREF

  v4 = *(_QWORD *)(**((_QWORD **)context + 1) + 8i64 * context[4]);
  IndexOf = hkString::lastIndexOf(text, 10);
  v6 = *(hkOstream **)context;
  texta.m_start = text;
  texta.m_end = &text[IndexOf];
  v7 = hkOstream::operator<<(v6, "Location( loc=");
  v8 = hkOstream::operator<<(v7, v4);
  v9 = hkOstream::operator<<(v8, ", str=r\"\"\"");
  v10 = operator<<(v9, &texta);
  hkOstream::operator<<(v10, "\"\"\" )\n");
  ++context[4];
}

// File Line: 42
// RVA: 0x13015E0
void __fastcall writeMemorySystemStats(hkTrackerScanSnapshot *scanSnapshot, hkOstream *stream)
{
  const char *MemorySystemStatistics; // rax
  const char *v4; // rbx
  char *i; // rdi

  MemorySystemStatistics = hkTrackerScanSnapshot::getMemorySystemStatistics(scanSnapshot);
  v4 = MemorySystemStatistics;
  if ( MemorySystemStatistics )
  {
    for ( i = hkString::strChr(MemorySystemStatistics, 10); i; i = hkString::strChr(i + 1, 10) )
    {
      hkOstream::operator<<(stream, "Statistics( str=");
      hkOstream::write(stream, v4, (unsigned int)((_DWORD)i - (_DWORD)v4));
      hkOstream::operator<<(stream, " )\n");
      v4 = i + 1;
    }
  }
}

// File Line: 58
// RVA: 0x1300B80
void __fastcall hkVdbStreamReportUtil::generateReport(hkTrackerScanSnapshot *scanSnapshot, hkOstream *stream)
{
  __int64 v2; // r14
  hkStackTracer::CallTree *p_m_callTree; // rsi
  unsigned __int64 SystemTime; // rdi
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  int v9; // r15d
  __int64 v10; // r12
  hkMemorySnapshot::Provider *v11; // rsi
  int v12; // edi
  int v13; // r12d
  __int64 v14; // r15
  hkMemorySnapshot::Allocation *v15; // r14
  int m_traceId; // edx
  int v17; // eax
  int v18; // edi
  int v19; // r9d
  int v20; // edx
  hkOstream *v21; // rax
  hkOstream *v22; // rax
  __int64 v23; // rdi
  int i; // esi
  __int64 v25; // r8
  int v26; // r12d
  __int64 v27; // r15
  hkTrackerScanSnapshot::Block *v28; // rsi
  hkTrackerTypeTreeNode *m_type; // r14
  signed int v30; // edi
  hkOstream *v31; // rax
  hkOstream *v32; // rax
  hkOstream *v33; // rax
  hkOstream *v34; // rax
  hkOstream *v35; // rax
  hkOstream *v36; // rax
  hkOstream *v37; // rax
  hkOstream *v38; // rax
  hkOstream *v39; // rax
  hkOstream *v40; // rax
  int v41; // r8d
  __int64 v42; // r9
  __int64 v43; // r10
  int v44; // edx
  __int64 v45; // rcx
  _QWORD *v46; // rax
  int v47; // edi
  unsigned __int64 v48; // rsi
  int v49; // edx
  __int64 v50; // rcx
  _QWORD *v51; // rax
  bool v52; // cc
  int v53; // edi
  __int64 v54; // rsi
  int v55; // r12d
  int v56; // edi
  int v57; // r8d
  __int64 v58; // r15
  hkTrackerScanSnapshot::Block **m_data; // rax
  __int64 v60; // rcx
  unsigned __int64 *v61; // rsi
  int v62; // r14d
  int v63; // edx
  hkOstream *v64; // rax
  hkOstream *v65; // rax
  int v66; // edi
  __int64 v67; // rsi
  int v68; // ecx
  __int64 sizeElem; // [rsp+20h] [rbp-69h]
  __int64 v70; // [rsp+28h] [rbp-61h]
  unsigned __int64 *array; // [rsp+40h] [rbp-49h] BYREF
  int v72; // [rsp+48h] [rbp-41h]
  int v73; // [rsp+4Ch] [rbp-3Dh]
  AMD_HD3D v74; // [rsp+50h] [rbp-39h] BYREF
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > context; // [rsp+70h] [rbp-19h] BYREF
  int v76; // [rsp+80h] [rbp-9h]
  AMD_HD3D v77[2]; // [rsp+88h] [rbp-1h] BYREF
  __int64 result; // [rsp+F0h] [rbp+67h] BYREF
  hkStackTracer v79; // [rsp+100h] [rbp+77h] BYREF
  unsigned __int64 out; // [rsp+108h] [rbp+7Fh] BYREF

  v2 = 0i64;
  v74.mHeight = -1;
  v74.mStereo = 0i64;
  v74.mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
  *(_QWORD *)&v74.mEnableStereo = 0i64;
  v74.mWidth = 0;
  v77[0].mStereo = 0i64;
  v77[0].mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
  *(_QWORD *)&v77[0].mEnableStereo = 0i64;
  v77[0].mWidth = 0;
  v77[0].mHeight = -1;
  hkStackTracer::hkStackTracer(&v79);
  p_m_callTree = &scanSnapshot->m_rawSnapshot.m_callTree;
  if ( scanSnapshot->m_blocks.m_size
    && hkStackTracer::CallTree::isEmpty(&scanSnapshot->m_rawSnapshot.m_callTree, (hkBool *)&result)->m_bool )
  {
    hkOstream::operator<<(
      stream,
      "#NOTE: Could not retrieve stack information. Are you using the hkCheckingMemorySystem?\n#\n");
  }
  hkOstream::operator<<(stream, "#V <integer> - Version number\n");
  hkOstream::operator<<(stream, "#Date(ts=<timestamp>) - Date of capture\n");
  hkOstream::operator<<(
    stream,
    "#Module(mod=<platform-dependent module/symbol identifier string>) - Module information\n");
  hkOstream::operator<<(stream, "#Statistics(str=<string>) - Raw memory system Statistics\n");
  hkOstream::operator<<(
    stream,
    "#Provider(id=<provider id>, name=<name>, parIds=[<parent>*]) - Hierarchy of providers (allocators)\n");
  hkOstream::operator<<(
    stream,
    "#Router(temp=<provider id>, stack=<provider id>, heap=<provider id>, debug=<provider id>, solver=<provider id>) - Me"
    "mory router wiring\n");
  hkOstream::operator<<(
    stream,
    "#Allocation(addr=<address>, size=<size>, provId=<provider id>, status=<status>, callstackId=<callstack id>) - Allocation report\n");
  hkOstream::operator<<(stream, "#Type(id=<type id>, name=<type name>) - Block type definition\n");
  hkOstream::operator<<(
    stream,
    "#Block(id=<block id>, typeId=<type id>, addr=<address>, size=<size>) - Tracker block report\n");
  hkOstream::operator<<(
    stream,
    "#References(blockId=<block id>, refIds=[<owned block id>+]) - Blocks referenced by a given block\n");
  hkOstream::operator<<(
    stream,
    "#Callstack(id=<callstack id>, locations=[<location>+]) - Callstack declaration for a specific address\n");
  hkOstream::operator<<(stream, "#Location(loc=<location>, str=<string name>) - Program location\n");
  hkOstream::operator<<(stream, "V 1\n");
  SystemTime = hkGetSystemTime();
  v7 = hkOstream::operator<<(stream, "Date( ts=");
  v8 = hkOstream::operator<<(v7, SystemTime);
  hkOstream::operator<<(v8, " )\n");
  hkStackTracer::getModuleInfo(&v79, writeModuleInfo, stream);
  writeMemorySystemStats(scanSnapshot, stream);
  v9 = 0;
  if ( scanSnapshot->m_rawSnapshot.m_providers.m_size > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = &scanSnapshot->m_rawSnapshot.m_providers.m_data[v10];
      hkOstream::printf(stream, "Provider( id=%i, name=%s, parIds=[", (unsigned int)v9, v11->m_name);
      v12 = 0;
      if ( v11->m_parentIndices.m_size > 0 )
      {
        do
        {
          hkOstream::printf(stream, "%i", *(unsigned int *)((char *)v11->m_parentIndices.m_data + v2));
          if ( v12 != v11->m_parentIndices.m_size - 1 )
            hkOstream::operator<<(stream, 44);
          ++v12;
          v2 += 4i64;
        }
        while ( v12 < v11->m_parentIndices.m_size );
        v2 = 0i64;
      }
      hkOstream::printf(stream, "] )\n");
      ++v9;
      ++v10;
    }
    while ( v9 < scanSnapshot->m_rawSnapshot.m_providers.m_size );
    p_m_callTree = &scanSnapshot->m_rawSnapshot.m_callTree;
  }
  hkOstream::printf(
    stream,
    "Router( temp=%i, stack=%i, heap=%i, debug=%i, solver=%i )\n",
    (unsigned int)scanSnapshot->m_rawSnapshot.m_routerWiring[0],
    (unsigned int)scanSnapshot->m_rawSnapshot.m_routerWiring[1],
    scanSnapshot->m_rawSnapshot.m_routerWiring[2],
    scanSnapshot->m_rawSnapshot.m_routerWiring[3],
    scanSnapshot->m_rawSnapshot.m_routerWiring[4]);
  v13 = 0;
  if ( scanSnapshot->m_rawSnapshot.m_allocations.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = &scanSnapshot->m_rawSnapshot.m_allocations.m_data[v14];
      if ( v15->m_traceId != -1
        && !(unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v77,
                            v15->m_traceId,
                            0i64) )
      {
        m_traceId = v15->m_traceId;
        array = 0i64;
        v72 = 0;
        v73 = 0x80000000;
        v17 = hkStackTracer::CallTree::getCallStackSize(p_m_callTree, m_traceId);
        v18 = v17;
        if ( (v73 & 0x3FFFFFFF) >= v17 )
        {
          LODWORD(result) = 0;
        }
        else
        {
          v19 = v17;
          if ( v17 < 2 * (v73 & 0x3FFFFFFF) )
            v19 = 2 * (v73 & 0x3FFFFFFF);
          hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v19, 8);
        }
        v20 = v15->m_traceId;
        v72 = v18;
        hkStackTracer::CallTree::getCallStack(p_m_callTree, v20, array, v18);
        v21 = hkOstream::operator<<(stream, "Callstack( id=");
        v22 = hkOstream::operator<<(v21, v15->m_traceId);
        hkOstream::operator<<(v22, ", locations=[");
        v23 = 0i64;
        for ( i = 0; i < v72; ++v23 )
        {
          hkOstream::operator<<(stream, array[v23]);
          if ( i != v72 - 1 )
            hkOstream::operator<<(stream, 44);
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v74,
            &hkContainerHeapAllocator::s_alloc,
            array[v23],
            0i64);
          ++i;
        }
        hkOstream::operator<<(stream, "] )\n");
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v77,
          &hkContainerHeapAllocator::s_alloc,
          v15->m_traceId,
          1ui64);
        v72 = 0;
        if ( v73 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v73);
        array = 0i64;
        v73 = 0x80000000;
      }
      LODWORD(v70) = v15->m_status.m_storage;
      LODWORD(sizeElem) = v15->m_sourceId;
      hkOstream::printf(
        stream,
        "Allocation( addr=0x%p, size=%i, provId=%i, status=%i",
        v15->m_start,
        (unsigned int)v15->m_size,
        sizeElem,
        v70);
      v25 = (unsigned int)v15->m_traceId;
      if ( (_DWORD)v25 != -1 )
        hkOstream::printf(stream, ", callstackId=%i", v25);
      hkOstream::operator<<(stream, " )\n");
      ++v13;
      ++v14;
      p_m_callTree = &scanSnapshot->m_rawSnapshot.m_callTree;
    }
    while ( v13 < scanSnapshot->m_rawSnapshot.m_allocations.m_size );
    v2 = 0i64;
  }
  v26 = 0;
  if ( scanSnapshot->m_blocks.m_size > 0 )
  {
    v27 = 0i64;
    do
    {
      v28 = scanSnapshot->m_blocks.m_data[v27];
      m_type = v28->m_type;
      if ( hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::get(
             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v74.mStereo,
             (hkResult *)&result,
             (unsigned __int64)v28->m_type,
             &out)->m_enum )
      {
        v30 = (__int64)v74.mExtension & 0x7FFFFFFF;
        v31 = hkOstream::operator<<(stream, "Type( id=");
        v32 = hkOstream::operator<<(v31, v30);
        hkOstream::operator<<(v32, ", name=");
        hkTrackerTypeTreeNode::dumpType(v28->m_type, stream);
        hkOstream::operator<<(stream, " )\n");
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v74.mStereo,
          &hkContainerHeapAllocator::s_alloc,
          (unsigned __int64)m_type,
          v30);
      }
      else
      {
        v30 = out;
      }
      v33 = hkOstream::operator<<(stream, "Block( id=");
      v34 = hkOstream::operator<<(v33, v26);
      v35 = hkOstream::operator<<(v34, ", typeId=");
      v36 = hkOstream::operator<<(v35, v30);
      v37 = hkOstream::operator<<(v36, ", addr=0x");
      v38 = hkOstream::operator<<(v37, v28->m_start);
      v39 = hkOstream::operator<<(v38, ", size=");
      v40 = hkOstream::operator<<(v39, v28->m_size);
      hkOstream::operator<<(v40, " )\n");
      ++v26;
      ++v27;
    }
    while ( v26 < scanSnapshot->m_blocks.m_size );
    v2 = 0i64;
  }
  array = 0i64;
  v41 = 0;
  v72 = 0;
  v73 = 0x80000000;
  v42 = v74.mWidth & 0x7FFFFFFF;
  if ( (v74.mWidth & 0x7FFFFFFF) != 0 )
  {
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v42, 8);
    v41 = v72;
  }
  v43 = *(_QWORD *)&v74.mEnableStereo;
  v44 = 0;
  v45 = 0i64;
  if ( (v74.mHeight & 0x80000000) == 0 )
  {
    v46 = *(_QWORD **)&v74.mEnableStereo;
    do
    {
      if ( *v46 != -1i64 )
        break;
      ++v45;
      ++v44;
      v46 += 2;
    }
    while ( v45 <= (int)v74.mHeight );
  }
  v47 = v44;
  if ( v44 <= (int)v74.mHeight )
  {
    do
    {
      v48 = *(_QWORD *)(v43 + 16i64 * v47);
      if ( v41 == (v73 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
        v41 = v72;
      }
      v49 = v47 + 1;
      array[v41] = v48;
      v43 = *(_QWORD *)&v74.mEnableStereo;
      v41 = v72 + 1;
      v50 = v47 + 1;
      ++v72;
      if ( v50 <= (int)v74.mHeight )
      {
        v51 = (_QWORD *)(*(_QWORD *)&v74.mEnableStereo + 16i64 * v49);
        do
        {
          if ( *v51 != -1i64 )
            break;
          ++v50;
          ++v49;
          v51 += 2;
        }
        while ( v50 <= (int)v74.mHeight );
      }
      v47 = v49;
    }
    while ( v49 <= (int)v74.mHeight );
  }
  if ( v41 )
  {
    *(_QWORD *)&context.m_numElems = &array;
    context.m_elem = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *)stream;
    v76 = 0;
    hkStackTracer::dumpStackTrace(&v79, array, v41, writeStackTrace, &context);
  }
  v72 = 0;
  if ( v73 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64 *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      (unsigned int)(8 * v73),
      v42);
  v52 = scanSnapshot->m_blocks.m_size <= 0;
  context.m_elem = 0i64;
  *(_QWORD *)&context.m_numElems = 0xFFFFFFFF00000000ui64;
  v53 = 0;
  if ( !v52 )
  {
    v54 = 0i64;
    do
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &context,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)scanSnapshot->m_blocks.m_data[v54++],
        v53++);
    while ( v53 < scanSnapshot->m_blocks.m_size );
  }
  v55 = 0;
  if ( scanSnapshot->m_blocks.m_size > 0 )
  {
    result = 0i64;
    v56 = 0;
    do
    {
      v57 = 0x80000000;
      v58 = *(__int64 *)((char *)scanSnapshot->m_blocks.m_data + v2);
      m_data = scanSnapshot->m_references.m_data;
      v60 = *(int *)(v58 + 28);
      array = 0i64;
      v72 = 0;
      v73 = 0x80000000;
      v61 = (unsigned __int64 *)&m_data[v60];
      if ( *(int *)(v58 + 32) > 0 )
      {
        do
        {
          v62 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                  &context,
                  *v61,
                  0xFFFFFFFFFFFFFFFFui64);
          if ( v62 != -1 )
          {
            v63 = v72;
            if ( v72 == (v73 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 4);
              v63 = v72;
            }
            *((_DWORD *)array + v63) = v62;
            ++v72;
          }
          ++v56;
          ++v61;
        }
        while ( v56 < *(_DWORD *)(v58 + 32) );
        if ( v72 )
        {
          v64 = hkOstream::operator<<(stream, "References( blockId=");
          v65 = hkOstream::operator<<(v64, v55);
          hkOstream::operator<<(v65, ", refIds=[");
          v66 = 0;
          if ( v72 > 0 )
          {
            v67 = 0i64;
            do
            {
              hkOstream::operator<<(stream, *(_DWORD *)((char *)array + v67));
              v68 = v72;
              if ( v66 != v72 - 1 )
              {
                hkOstream::operator<<(stream, 44);
                v68 = v72;
              }
              ++v66;
              v67 += 4i64;
            }
            while ( v66 < v68 );
          }
          hkOstream::operator<<(stream, "] )\n");
        }
        v2 = result;
        v57 = v73;
      }
      v56 = 0;
      v72 = 0;
      if ( v57 >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64 *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          array,
          (unsigned int)(4 * v57),
          v42);
      v2 += 8i64;
      ++v55;
      array = 0i64;
      v73 = 0x80000000;
      result = v2;
    }
    while ( v55 < scanSnapshot->m_blocks.m_size );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &context,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&context);
  hkStackTracer::~hkStackTracer(&v79);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v77,
    &hkContainerHeapAllocator::s_alloc);
  _(v77);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v77[0].mStereo,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v77[0].mStereo);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v74,
    &hkContainerHeapAllocator::s_alloc);
  _(&v74);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v74.mStereo,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v74.mStereo);
}

