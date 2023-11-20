// File Line: 33
// RVA: 0xC5C650
void *__fastcall hkCheckingMemorySystem::AllocatorForwarder::blockAlloc(hkCheckingMemorySystem::AllocatorForwarder *this, int numBytes)
{
  return hkCheckingMemorySystem::checkedAlloc(this->m_parent, 0, &this->m_context, numBytes);
}

// File Line: 38
// RVA: 0xC5C670
void __fastcall hkCheckingMemorySystem::AllocatorForwarder::blockFree(hkCheckingMemorySystem::AllocatorForwarder *this, void *p, int numBytes)
{
  if ( p )
    hkCheckingMemorySystem::checkedFree(this->m_parent, 0, &this->m_context, p, numBytes);
}

// File Line: 50
// RVA: 0xC5C6A0
void *__fastcall hkCheckingMemorySystem::AllocatorForwarder::bufAlloc(hkCheckingMemorySystem::AllocatorForwarder *this, int *reqNumInOut)
{
  return hkCheckingMemorySystem::checkedAlloc(this->m_parent, 1u, &this->m_context, *reqNumInOut);
}

// File Line: 55
// RVA: 0xC5C6C0
void __fastcall hkCheckingMemorySystem::AllocatorForwarder::bufFree(hkCheckingMemorySystem::AllocatorForwarder *this, void *p, int num)
{
  hkCheckingMemorySystem::checkedFree(this->m_parent, 1u, &this->m_context, p, num);
}

// File Line: 60
// RVA: 0xC5C6F0
void *__fastcall hkCheckingMemorySystem::AllocatorForwarder::bufRealloc(hkCheckingMemorySystem::AllocatorForwarder *this, void *pold, int oldNum, int *reqNumInOut)
{
  int numBytes; // ebp
  int *v5; // rbx
  hkCheckingMemorySystem::AllocatorForwarder *v6; // r15
  void *v7; // r14
  void *v8; // rax
  int v9; // er8
  void *v10; // rdi

  numBytes = oldNum;
  v5 = reqNumInOut;
  v6 = this;
  v7 = pold;
  v8 = hkCheckingMemorySystem::checkedAlloc(this->m_parent, 1u, &this->m_context, *reqNumInOut);
  v9 = numBytes;
  if ( *v5 < numBytes )
    v9 = *v5;
  v10 = v8;
  hkMemUtil::memCpy(v8, v7, v9);
  hkCheckingMemorySystem::checkedFree(v6->m_parent, 1u, &v6->m_context, v7, numBytes);
  return v10;
}

// File Line: 68
// RVA: 0xC5C780
void __fastcall hkCheckingMemorySystem::AllocatorForwarder::getMemoryStatistics(hkCheckingMemorySystem::AllocatorForwarder *this, hkMemoryAllocator::MemoryStatistics *u)
{
  __int64 v2; // r8

  u->m_available = 0i64;
  v2 = this->m_parent->m_currentInUse;
  u->m_inUse = v2;
  u->m_allocated = v2;
  u->m_peakInUse = this->m_parent->m_peakInUse;
}

// File Line: 76
// RVA: 0xC5C7B0
__int64 __fastcall hkCheckingMemorySystem::AllocatorForwarder::getAllocatedSize(hkCheckingMemorySystem::AllocatorForwarder *this, const void *obj, int numBytes)
{
  return (unsigned int)numBytes;
}

// File Line: 81
// RVA: 0xC5C7C0
void __fastcall hkCheckingMemorySystem::AllocatorForwarder::resetPeakMemoryStatistics(hkCheckingMemorySystem::AllocatorForwarder *this)
{
  this->m_parent->m_peakInUse = this->m_parent->m_currentInUse;
}

// File Line: 97
// RVA: 0xC5C7E0
void __fastcall hkCheckingMemorySystem::hkCheckingMemorySystem(hkCheckingMemorySystem *this)
{
  hkCheckingMemorySystem *v1; // rbx
  hkStackTracer *v2; // rcx
  unsigned __int64 v3; // rax

  v1 = this;
  v2 = &this->m_stackTracer;
  v2[-1].vfptr = (hkStackTracerVtbl *)&hkCheckingMemorySystem::`vftable;
  hkStackTracer::hkStackTracer(v2);
  v1->m_callTree.m_nodes.m_data = 0i64;
  v1->m_callTree.m_nodes.m_size = 0;
  v1->m_callTree.m_nodes.m_capacityAndFlags = 2147483648;
  v1->m_callTree.m_allocator = 0i64;
  *(_QWORD *)&v1->m_callTree.m_rootNode = -1i64;
  hkCriticalSection::hkCriticalSection(&v1->m_section, 0);
  v1->m_baseAllocator = 0i64;
  hkPaddedAllocator::hkPaddedAllocator(&v1->m_paddedAllocator);
  hkDelayedFreeAllocator::hkDelayedFreeAllocator(&v1->m_delayedFreeAllocator);
  hkRecallAllocator::hkRecallAllocator(&v1->m_debugAllocator, 0i64);
  hkStatsAllocator::hkStatsAllocator(&v1->m_callTreeAllocator, 0i64);
  v1->m_bookmarks.m_data = 0i64;
  v1->m_bookmarks.m_size = 0;
  v1->m_bookmarks.m_capacityAndFlags = 2147483648;
  v1->m_allocators.m_data = 0i64;
  v1->m_allocators.m_size = 0;
  v1->m_allocators.m_capacityAndFlags = 2147483648;
  v1->m_checkFlags.m_storage = 30;
  v1->m_activePointers.m_elem = 0i64;
  v1->m_activePointers.m_numElems = 0;
  v1->m_activePointers.m_hashMod = -1;
  v1->m_outputFunc = 0i64;
  v1->m_outputFuncArg = 0i64;
  hkMemorySystem::FrameInfo::FrameInfo(&v1->m_frameInfo, 0);
  hkMemoryRouter::hkMemoryRouter(&v1->m_mainRouter);
  v3 = hkStopwatch::getTickCounter();
  v1->m_sumAllocatedStackMemory = 0i64;
  v1->m_timeOfConstruction = v3;
  v1->m_allocOrder = 0i64;
}

// File Line: 105
// RVA: 0xC5C910
void __fastcall hkCheckingMemorySystem::init(hkCheckingMemorySystem *this, hkMemoryAllocator *raw, void (__fastcall *output)(const char *, void *), void *outputUserData, hkCheckingMemorySystem::CheckBits checks)
{
  hkMemoryAllocator *v5; // rbp
  hkCheckingMemorySystem *v6; // rdi
  hkMemoryAllocator *v7; // rsi

  v5 = raw;
  v6 = this;
  this->m_outputFunc = output;
  this->m_outputFuncArg = outputUserData;
  this->m_rawAllocator = raw;
  this->m_checkFlags.m_storage = checks;
  v7 = raw;
  if ( checks & 0x10 )
  {
    v7 = (hkMemoryAllocator *)&this->m_delayedFreeAllocator.vfptr;
    hkDelayedFreeAllocator::init(&this->m_delayedFreeAllocator, raw, 0i64);
  }
  if ( v6->m_checkFlags.m_storage & 8 )
  {
    hkPaddedAllocator::init(&v6->m_paddedAllocator, v7, 0i64);
    v7 = (hkMemoryAllocator *)&v6->m_paddedAllocator.vfptr;
  }
  if ( v6->m_checkFlags.m_storage & 4 )
  {
    hkStatsAllocator::init(&v6->m_callTreeAllocator, v5);
    v6->m_callTree.m_allocator = (hkMemoryAllocator *)&v6->m_callTreeAllocator.vfptr;
  }
  v6->m_baseAllocator = v7;
  hkRecallAllocator::init(&v6->m_debugAllocator, v5);
}

// File Line: 132
// RVA: 0xC5C9D0
hkBool *__fastcall hkCheckingMemorySystem::isInit(hkCheckingMemorySystem *this, hkBool *result)
{
  result->m_bool = this->m_baseAllocator != 0i64;
  return result;
}

// File Line: 137
// RVA: 0xC5FD30
char *__fastcall flagsToString(char *buf, hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int> flags)
{
  char *v2; // r14
  char *v3; // rbx
  const char **v4; // rsi
  signed __int64 v5; // rbp
  int v6; // eax
  int v8; // [rsp+20h] [rbp-48h]
  const char *v9; // [rsp+28h] [rbp-40h]
  int v10; // [rsp+30h] [rbp-38h]
  const char *v11; // [rsp+38h] [rbp-30h]
  int v12; // [rsp+40h] [rbp-28h]
  const char *v13; // [rsp+48h] [rbp-20h]
  unsigned int v14; // [rsp+78h] [rbp+10h]

  v14 = flags.m_storage;
  v2 = buf;
  v8 = 1;
  v9 = "Heap";
  v10 = 4;
  v11 = "Temp";
  v12 = 8;
  *buf = 0;
  v3 = buf;
  v4 = &v9;
  v13 = "Solver";
  v5 = 3i64;
  do
  {
    if ( flags.m_storage & *(_DWORD *)(v4 - 1) )
    {
      if ( v3 != v2 )
        *v3++ = 124;
      hkString::strCpy(v3, *v4);
      v6 = hkString::strLen(*v4);
      flags.m_storage = v14;
      v3 += v6;
    }
    v4 += 2;
    --v5;
  }
  while ( v5 );
  return v2;
}

// File Line: 168
// RVA: 0xC5FBE0
void __fastcall hkCheckingMemorySystem::danger(hkCheckingMemorySystem *this, const char *message, const void *ptr, hkCheckingMemorySystem::AllocInfo *info)
{
  hkCheckingMemorySystem *v4; // r14
  hkCheckingMemorySystem::AllocInfo *v5; // rsi
  const void *v6; // rbx
  const char *v7; // rdi
  double v8; // xmm6_8
  const char *v9; // rax
  int v10; // eax
  void *context; // [rsp+20h] [rbp-2B8h]
  char v12; // [rsp+40h] [rbp-298h]
  char buf; // [rsp+140h] [rbp-198h]
  unsigned __int64 addrs; // [rsp+1C0h] [rbp-118h]

  v4 = this;
  v5 = info;
  v6 = ptr;
  v7 = message;
  EnterCriticalSection(&this->m_section.m_section);
  v8 = hkStopwatch::secondsFromTicks(v5->m_time - v4->m_timeOfConstruction);
  v9 = flagsToString(&buf, v5->m_flags);
  LODWORD(context) = v5->m_size;
  hkString::snprintf(
    &v12,
    256,
    "\nAddress=0x%p size=%i flags=%s thread=%I64u time=%.2f\n",
    v6,
    context,
    v9,
    v5->m_threadId,
    v8);
  v4->m_outputFunc(v7, v4->m_outputFuncArg);
  v4->m_outputFunc(&v12, v4->m_outputFuncArg);
  v10 = hkStackTracer::CallTree::getCallStack(&v4->m_callTree, v5->m_traceId, &addrs, 32);
  hkStackTracer::dumpStackTrace(&v4->m_stackTracer, &addrs, v10, v4->m_outputFunc, v4->m_outputFuncArg);
  v4->m_outputFunc("-------------------------------------------------------------------\n\n", v4->m_outputFuncArg);
  LeaveCriticalSection(&v4->m_section.m_section);
}

// File Line: 221
// RVA: 0xC5EAD0
void __fastcall hkCheckingMemorySystem::leakReportByTime(hkCheckingMemorySystem *this)
{
  hkMemoryAllocator *v1; // rdx
  int v2; // edi
  hkCheckingMemorySystem *v3; // rbx
  int v4; // edi
  int v5; // er9
  int v6; // er9
  int v7; // er9
  __int64 v8; // r8
  int v9; // edx
  __int64 v10; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v11; // rax
  int v12; // edi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v13; // rax
  signed __int64 v14; // rsi
  hkCheckingMemorySystem::AllocInfo *v15; // r12
  unsigned __int64 v16; // r13
  hkCheckingMemorySystem::AllocInfo *v17; // r15
  hkCheckingMemorySystem::AllocInfo *v18; // r14
  __int64 v19; // rcx
  bool v20; // zf
  __int64 v21; // rcx
  unsigned __int64 v22; // rax
  int v23; // eax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v24; // rdx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v25; // rax
  hkCheckingMemorySystem::AllocInfo *v26; // rdx
  hkCheckingMemorySystem::AllocInfo *v27; // r8
  hkCheckingMemorySystem::AllocInfo *v28; // r9
  hkCheckingMemorySystem::AllocInfo *v29; // r10
  hkCheckingMemorySystem::AllocInfo *v30; // r11
  hkCheckingMemorySystem::AllocInfo *v31; // r14
  hkCheckingMemorySystem::AllocInfo *v32; // rsi
  int v33; // ecx
  hkCheckingMemorySystem::AllocInfo **v34; // rax
  __int64 v35; // rdx
  hkArrayBase<hkCheckingMemorySystem::AllocInfo> *v36; // rax
  unsigned __int64 v37; // rcx
  __int64 v38; // r8
  __int64 v39; // r8
  int v40; // edx
  __int64 v41; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v42; // rax
  signed int v43; // edi
  int v44; // er9
  int v45; // ecx
  __int64 v46; // rdx
  int v47; // er15
  __int64 v48; // r12
  __int64 v49; // r13
  __int64 v50; // rcx
  int v51; // er8
  bool v52; // al
  char v53; // dl
  const char *v54; // r14
  const char *v55; // rdi
  allocTimeComparison cmpLess; // [rsp+30h] [rbp-D0h]
  int v57; // [rsp+38h] [rbp-C8h]
  int v58; // [rsp+3Ch] [rbp-C4h]
  _DWORD *v59; // [rsp+40h] [rbp-C0h]
  int v60; // [rsp+48h] [rbp-B8h]
  int v61; // [rsp+4Ch] [rbp-B4h]
  _QWORD *array; // [rsp+50h] [rbp-B0h]
  int v63; // [rsp+58h] [rbp-A8h]
  int v64; // [rsp+5Ch] [rbp-A4h]
  int *pArr; // [rsp+60h] [rbp-A0h]
  int v66; // [rsp+68h] [rbp-98h]
  int v67; // [rsp+6Ch] [rbp-94h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v68; // [rsp+70h] [rbp-90h]
  hkCheckingMemorySystem::AllocInfo v69; // [rsp+80h] [rbp-80h]
  hkStringBuf v70; // [rsp+C0h] [rbp-40h]
  hkResult result; // [rsp+190h] [rbp+90h]
  hkCheckingMemorySystem::AllocInfo *v72; // [rsp+198h] [rbp+98h]
  __int64 v73; // [rsp+1A0h] [rbp+A0h]

  v1 = this->m_rawAllocator;
  `anonymous namespace::SummaryAllocator::s_allocator = this->m_rawAllocator;
  v2 = this->m_activePointers.m_numElems;
  v3 = this;
  array = 0i64;
  v63 = 0;
  v64 = 2147483648;
  v4 = v2 & 0x7FFFFFFF;
  if ( v4 > 0 )
  {
    v5 = v4;
    if ( v4 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&result, v1, &array, v5, 8);
    v1 = `anonymous namespace::SummaryAllocator::s_allocator;
  }
  cmpLess.m_allocs = 0i64;
  v57 = 0;
  v58 = 2147483648;
  if ( v4 > 0 )
  {
    v6 = v4;
    if ( v4 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(&result, v1, &cmpLess, v6, 56);
    v1 = `anonymous namespace::SummaryAllocator::s_allocator;
  }
  v59 = 0i64;
  v60 = 0;
  v61 = 2147483648;
  if ( v4 > 0 )
  {
    v7 = v4;
    if ( v4 < 0 )
      v7 = 0;
    hkArrayUtil::_reserve(&result, v1, &v59, v7, 4);
    v1 = `anonymous namespace::SummaryAllocator::s_allocator;
  }
  v68.m_elem = 0i64;
  v68.m_numElems = 0;
  v68.m_hashMod = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(&v68, v1, v4);
  v8 = v3->m_activePointers.m_hashMod;
  v9 = 0;
  v10 = 0i64;
  if ( v8 >= 0 )
  {
    v11 = v3->m_activePointers.m_elem;
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
  v12 = v9;
  if ( v9 <= v3->m_activePointers.m_hashMod )
  {
    do
    {
      v13 = v3->m_activePointers.m_elem;
      v14 = (signed __int64)v12 << 6;
      v15 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v13->val.m_threadId + v14);
      v16 = *(unsigned __int64 *)((char *)&v13->val.m_allocOrder + v14);
      v17 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v13->val.m_time + v14);
      v18 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v13->val.m_bookmarkIndex + v14);
      *(_QWORD *)&result.m_enum = *(const void **)((char *)&v13->val.m_tagData + v14);
      v69.m_tagData = *(const void **)&result.m_enum;
      v19 = *(_QWORD *)((char *)&v13->val.m_flags.m_storage + v14);
      v69.m_threadId = (unsigned __int64)v15;
      *(_QWORD *)&v69.m_flags.m_storage = v19;
      v20 = HIDWORD(v19) == -1;
      v72 = (hkCheckingMemorySystem::AllocInfo *)v19;
      v21 = *(_QWORD *)((char *)&v13->val.m_size + v14);
      v69.m_allocOrder = v16;
      v69.m_time = (unsigned __int64)v17;
      v73 = v21;
      *(_QWORD *)&v69.m_size = v21;
      *(_QWORD *)&v69.m_bookmarkIndex = v18;
      if ( !v20 || (_DWORD)v18 != -1 )
      {
        v22 = hkCheckingMemorySystem::AllocInfo::getKey(&v69);
        v23 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
                                  &v68,
                                  `anonymous namespace::SummaryAllocator::s_allocator,
                                  v22,
                                  0xFFFFFFFFFFFFFFFFui64);
        v24 = &v68.m_elem[v23];
        if ( LODWORD(v24->val) != -1 )
        {
          v35 = SLODWORD(v24->val);
          ++v59[v35];
          v36 = cmpLess.m_allocs;
          v37 = 7 * v35;
          if ( v17 < (&cmpLess.m_allocs[1].m_data)[7 * v35] )
          {
            v38 = *(_QWORD *)&result.m_enum;
            (&cmpLess.m_allocs->m_data)[v37] = v15;
            *(_QWORD *)((char *)&v36->m_size + v37 * 8) = v16;
            (&v36[1].m_data)[v37] = v17;
            *(_QWORD *)((char *)&v36[1].m_size + v37 * 8) = v38;
            (&v36[2].m_data)[v37] = v72;
            *(_QWORD *)((char *)&v36[2].m_size + v37 * 8) = v73;
            (&v36[3].m_data)[v37] = v18;
            array[v35] = *(unsigned __int64 *)((char *)&v3->m_activePointers.m_elem->key + v14);
          }
          goto LABEL_27;
        }
        v24->val = v63;
        v13 = v3->m_activePointers.m_elem;
      }
      array[v63] = *(unsigned __int64 *)((char *)&v13->key + v14);
      v25 = v3->m_activePointers.m_elem;
      ++v63;
      v26 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v25->val.m_threadId + v14);
      v27 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v25->val.m_allocOrder + v14);
      v28 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v25->val.m_time + v14);
      v29 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v25->val.m_tagData + v14);
      v30 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v25->val.m_flags.m_storage + v14);
      v31 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v25->val.m_size + v14);
      v32 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v25->val.m_bookmarkIndex + v14);
      v33 = v57;
      v34 = &(&cmpLess.m_allocs->m_data)[7 * v57];
      if ( v34 )
      {
        *v34 = v26;
        v34[1] = v27;
        v34[2] = v28;
        v34[3] = v29;
        v34[4] = v30;
        v34[5] = v31;
        v34[6] = v32;
        v33 = v57;
      }
      v57 = v33 + 1;
      v59[v60++] = 1;
LABEL_27:
      v39 = v3->m_activePointers.m_hashMod;
      v40 = v12 + 1;
      v41 = v12 + 1;
      if ( v41 <= v39 )
      {
        v42 = &v3->m_activePointers.m_elem[(signed __int64)v40];
        do
        {
          if ( v42->key != -1i64 )
            break;
          ++v41;
          ++v40;
          ++v42;
        }
        while ( v41 <= v39 );
      }
      v12 = v40;
    }
    while ( v40 <= v3->m_activePointers.m_hashMod );
  }
  v43 = v57;
  pArr = 0i64;
  v66 = 0;
  v67 = 2147483648;
  if ( v57 > 0 )
  {
    v44 = v57;
    if ( v57 < 0 )
      v44 = 0;
    hkArrayUtil::_reserve(&result, `anonymous namespace::SummaryAllocator::s_allocator, &pArr, v44, 4);
  }
  v66 = v43;
  v45 = 0;
  if ( v43 > 0 )
  {
    v46 = 0i64;
    do
    {
      ++v46;
      pArr[v46 - 1] = v45;
      v43 = v66;
      ++v45;
    }
    while ( v45 < v66 );
  }
  if ( v43 > 1 )
  {
    hkAlgorithm::quickSortRecursive<int,`anonymous namespace::allocTimeComparison>(
      pArr,
      0,
      v43 - 1,
      (allocTimeComparison)&cmpLess);
    v43 = v66;
  }
  v47 = 0;
  if ( v43 > 0 )
  {
    v48 = 0i64;
    while ( 1 )
    {
      v49 = pArr[v48];
      v50 = SLODWORD((&cmpLess.m_allocs[3].m_data)[7 * v49]);
      v51 = v50 + 1;
      v52 = (signed int)v50 >= 0 && (signed int)v50 < v3->m_bookmarks.m_size;
      v53 = v51 < 0 || v51 >= v3->m_bookmarks.m_size ? 0 : 1;
      if ( v52 )
        break;
      if ( v53 )
      {
        v54 = "(unknown)";
LABEL_55:
        if ( v53 )
          v55 = v3->m_bookmarks.m_data[v51].m_name;
        else
          v55 = "(unknown)";
        v3->m_outputFunc("Between bookmarks\n[", v3->m_outputFuncArg);
        v3->m_outputFunc(v54, v3->m_outputFuncArg);
        v3->m_outputFunc("] and \n[", v3->m_outputFuncArg);
        v3->m_outputFunc(v55, v3->m_outputFuncArg);
        v3->m_outputFunc("]\n", v3->m_outputFuncArg);
      }
      v70.m_string.m_capacityAndFlags = -2147483520;
      v70.m_string.m_size = 1;
      v70.m_string.m_data = v70.m_string.m_storage;
      v70.m_string.m_storage[0] = 0;
      hkStringBuf::printf(&v70, "Memory Leaked (%i times with this stack):\n", (unsigned int)v59[v49]);
      hkCheckingMemorySystem::danger(
        v3,
        v70.m_string.m_data,
        (const void *)array[v49],
        (hkCheckingMemorySystem::AllocInfo *)cmpLess.m_allocs + v49);
      v70.m_string.m_size = 0;
      if ( v70.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v70.m_string.m_data,
          v70.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      ++v47;
      ++v48;
      if ( v47 >= v66 )
        goto LABEL_62;
    }
    v54 = v3->m_bookmarks.m_data[v50].m_name;
    goto LABEL_55;
  }
LABEL_62:
  v66 = 0;
  if ( v67 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      pArr,
      4 * v67);
  pArr = 0i64;
  v67 = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v68,
    `anonymous namespace::SummaryAllocator::s_allocator);
  v60 = 0;
  if ( v61 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      v59,
      4 * v61);
  v59 = 0i64;
  v61 = 2147483648;
  v57 = 0;
  if ( v58 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      cmpLess.m_allocs,
      56 * (v58 & 0x3FFFFFFF));
  cmpLess.m_allocs = 0i64;
  v63 = 0;
  v58 = 2147483648;
  if ( v64 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      array,
      8 * v64);
}

// File Line: 309
// RVA: 0xC5FDF0
void __fastcall breadthFirstSearch(int startIndex, hkArrayBase<int> *connectTo, hkArrayBase<int> *connectStart, hkArrayBase<hkBool> *visited, hkArray<int,SummaryAllocator> *owned)
{
  int v5; // edi
  __int64 v6; // r14
  hkArrayBase<hkBool> *v7; // r12
  hkArrayBase<int> *v8; // r11
  int v9; // er10
  __int64 v10; // r13
  int *v11; // rdx
  __int64 v12; // rdi
  __int64 v13; // r9
  __int64 v14; // r8
  signed __int64 v15; // r15
  __int64 v16; // rbp
  __int64 v17; // rsi
  hkArrayBase<int> *v18; // [rsp+68h] [rbp+10h]
  hkArrayBase<int> *v19; // [rsp+70h] [rbp+18h]

  v19 = connectStart;
  v18 = connectTo;
  v5 = startIndex;
  v6 = owned->m_size;
  visited->m_data[startIndex].m_bool = 1;
  v7 = visited;
  v8 = connectTo;
  if ( owned->m_size == (owned->m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(`anonymous namespace::SummaryAllocator::s_allocator, owned, 4);
    connectStart = v19;
    v8 = v18;
  }
  owned->m_data[owned->m_size++] = v5;
  v9 = owned->m_size;
  if ( (signed int)v6 < v9 )
  {
    v10 = v6;
    do
    {
      v11 = connectStart->m_data;
      v12 = 0i64;
      v13 = owned->m_data[v10];
      v14 = connectStart->m_data[v13];
      v15 = (signed __int64)&v8->m_data[v14];
      v16 = v11[v13 + 1] - (signed int)v14;
      if ( v11[v13 + 1] - (signed int)v14 > 0 )
      {
        do
        {
          v17 = *(signed int *)(v15 + 4 * v12);
          if ( !v7->m_data[v17].m_bool )
          {
            v7->m_data[v17].m_bool = 1;
            if ( owned->m_size == (owned->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(`anonymous namespace::SummaryAllocator::s_allocator, owned, 4);
            owned->m_data[owned->m_size++] = v17;
            v9 = owned->m_size;
          }
          ++v12;
        }
        while ( v12 < v16 );
        v8 = v18;
      }
      connectStart = v19;
      LODWORD(v6) = v6 + 1;
      ++v10;
    }
    while ( (signed int)v6 < v9 );
  }
}

// File Line: 334
// RVA: 0xC5FF50
void __fastcall setVisited(hkArrayBase<int> *owned, hkArrayBase<hkBool> *visited, hkBool value)
{
  int v3; // er10
  __int64 v4; // r11
  char v5; // [rsp+18h] [rbp+18h]

  v3 = 0;
  v5 = value.m_bool;
  if ( owned->m_size > 0 )
  {
    v4 = 0i64;
    while ( 1 )
    {
      ++v3;
      ++v4;
      visited->m_data[owned->m_data[v4 - 1]] = value;
      if ( v3 >= owned->m_size )
        break;
      value.m_bool = v5;
    }
  }
}

// File Line: 361
// RVA: 0xC5FA30
void __fastcall hkCheckingMemorySystem::dumpLeak(hkCheckingMemorySystem *this, hkArrayBase<int> *owned, hkArrayBase<unsigned __int64> *addrs, hkArrayBase<hkCheckingMemorySystem::AllocInfo> *allocs)
{
  _RTL_CRITICAL_SECTION *v4; // rbx
  hkCheckingMemorySystem *v5; // r13
  hkArrayBase<hkCheckingMemorySystem::AllocInfo> *v6; // r12
  hkArrayBase<unsigned __int64> *v7; // rdi
  hkArrayBase<int> *v8; // r14
  signed int v9; // er15
  signed __int64 v10; // rbp
  __int64 v11; // rsi
  unsigned __int64 v12; // rdi
  signed __int64 v13; // rsi
  const char *v14; // rax
  __int64 v15; // [rsp+20h] [rbp-158h]
  char buf; // [rsp+40h] [rbp-138h]
  char v17; // [rsp+C0h] [rbp-B8h]
  hkCriticalSection *v18; // [rsp+180h] [rbp+8h]
  hkArrayBase<unsigned __int64> *v19; // [rsp+190h] [rbp+18h]

  v19 = addrs;
  v4 = &this->m_section.m_section;
  v5 = this;
  v6 = allocs;
  v7 = addrs;
  v8 = owned;
  v18 = &this->m_section;
  EnterCriticalSection(&this->m_section.m_section);
  hkString::snprintf(&buf, 128, "ROOT - %d reached", (unsigned int)(v8->m_size - 1));
  hkCheckingMemorySystem::danger(v5, &buf, (const void *)v7->m_data[*v8->m_data], &v6->m_data[*v8->m_data]);
  v9 = 1;
  if ( v8->m_size > 1 )
  {
    v10 = 1i64;
    do
    {
      v11 = v8->m_data[v10];
      v12 = v19->m_data[v11];
      v13 = (signed __int64)&v6->m_data[v11];
      v14 = flagsToString(&v17, *(hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int> *)(v13 + 32));
      LODWORD(v15) = *(_DWORD *)(v13 + 40);
      hkString::snprintf(
        &buf,
        128,
        "REACHED Address=0x%p size=%i flags=%s thread=%i\n",
        v12,
        v15,
        v14,
        *(_QWORD *)v13);
      v5->m_outputFunc(&buf, v5->m_outputFuncArg);
      ++v9;
      ++v10;
    }
    while ( v9 < v8->m_size );
    v4 = &v18->m_section;
  }
  LeaveCriticalSection(v4);
}

// File Line: 385
// RVA: 0xC5F180
void __fastcall hkCheckingMemorySystem::leakReportByOwnership(hkCheckingMemorySystem *this)
{
  hkMemoryAllocator *v1; // rdx
  __int64 v2; // r13
  int v3; // eax
  hkCheckingMemorySystem *v4; // r15
  bool v5; // zf
  bool v6; // sf
  int v7; // esi
  int v8; // edi
  int v9; // er9
  int v10; // eax
  int v11; // eax
  int v12; // er9
  __int64 v13; // r8
  int v14; // edx
  __int64 v15; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v16; // rax
  int v17; // er8
  __int64 v18; // r9
  __int64 v19; // r10
  signed __int64 v20; // rdx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v21; // rcx
  hkCheckingMemorySystem::AllocInfo *v22; // rdi
  __int64 v23; // rax
  int v24; // edx
  __int64 v25; // rdi
  __int64 v26; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v27; // rax
  __int64 v28; // rbx
  __int64 v29; // r12
  __int64 v30; // rsi
  hkCheckingMemorySystem::AllocInfo *v31; // r9
  _QWORD *v32; // r8
  int *v33; // rcx
  int v34; // eax
  unsigned __int64 v35; // r15
  int v36; // er14
  __int64 v37; // rbx
  __int64 v38; // rsi
  unsigned __int64 v39; // rcx
  int v40; // ecx
  int v41; // er9
  hkBool *v42; // rdi
  int v43; // eax
  unsigned __int64 v44; // rcx
  int v45; // eax
  int v46; // er9
  signed __int64 v47; // rcx
  int v48; // edi
  __int64 v49; // rdx
  int *v50; // rdx
  int v51; // er8
  int v52; // ebx
  __int64 v53; // rdi
  int v54; // ebx
  int v55; // er14
  __int64 v56; // rsi
  hkArray<int,SummaryAllocator> owned; // [rsp+30h] [rbp-59h]
  hkArray<int,SummaryAllocator> v58; // [rsp+40h] [rbp-49h]
  hkArrayBase<int> connectStart; // [rsp+50h] [rbp-39h]
  hkArrayBase<int> connectTo; // [rsp+60h] [rbp-29h]
  hkArrayBase<hkBool> visited; // [rsp+70h] [rbp-19h]
  hkArrayBase<hkCheckingMemorySystem::AllocInfo> allocs; // [rsp+80h] [rbp-9h]
  char *array; // [rsp+90h] [rbp+7h]
  int v64; // [rsp+98h] [rbp+Fh]
  int v65; // [rsp+9Ch] [rbp+13h]
  hkCheckingMemorySystem *v66; // [rsp+F0h] [rbp+67h]
  int v67; // [rsp+F8h] [rbp+6Fh]
  hkResult result; // [rsp+100h] [rbp+77h]
  __int64 v69; // [rsp+108h] [rbp+7Fh]

  v66 = this;
  v1 = this->m_rawAllocator;
  v2 = 0i64;
  v3 = 2147483648;
  `anonymous namespace::SummaryAllocator::s_allocator = this->m_rawAllocator;
  v4 = this;
  v5 = (this->m_activePointers.m_numElems & 0x7FFFFFFF) == 0;
  v6 = (this->m_activePointers.m_numElems & 0x7FFFFFFF) < 0;
  v7 = this->m_activePointers.m_numElems & 0x7FFFFFFF;
  array = 0i64;
  v64 = 0;
  v65 = 2147483648;
  allocs.m_data = 0i64;
  allocs.m_size = 0;
  v67 = v7;
  allocs.m_capacityAndFlags = 2147483648;
  connectTo.m_data = 0i64;
  v8 = 0;
  connectTo.m_size = 0;
  connectTo.m_capacityAndFlags = 2147483648;
  connectStart.m_data = 0i64;
  connectStart.m_size = 0;
  connectStart.m_capacityAndFlags = 2147483648;
  if ( !v6 && !v5 )
  {
    v9 = v7;
    if ( v7 < 0 )
      v9 = 0;
    hkArrayUtil::_reserve(&result, v1, &array, v9, 8);
    v3 = allocs.m_capacityAndFlags;
    v8 = connectTo.m_size;
  }
  v10 = v3 & 0x3FFFFFFF;
  v64 = v7;
  if ( v10 < v7 )
  {
    v11 = 2 * v10;
    v12 = v7;
    if ( v7 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, `anonymous namespace::SummaryAllocator::s_allocator, &allocs, v12, 56);
    v8 = connectTo.m_size;
  }
  v13 = v4->m_activePointers.m_hashMod;
  allocs.m_size = v7;
  v14 = 0;
  v15 = 0i64;
  if ( v13 >= 0 )
  {
    v16 = v4->m_activePointers.m_elem;
    do
    {
      if ( v16->key != -1i64 )
        break;
      ++v15;
      ++v14;
      ++v16;
    }
    while ( v15 <= v13 );
  }
  v17 = v14;
  if ( v14 <= v4->m_activePointers.m_hashMod )
  {
    v18 = 0i64;
    v19 = 0i64;
    do
    {
      v20 = (signed __int64)v17 << 6;
      *(_QWORD *)&array[v19] = *(unsigned __int64 *)((char *)&v4->m_activePointers.m_elem->key + v20);
      v21 = v4->m_activePointers.m_elem;
      v22 = &allocs.m_data[v18];
      v22->m_threadId = *(unsigned __int64 *)((char *)&v21->val.m_threadId + v20);
      v22->m_allocOrder = *(unsigned __int64 *)((char *)&v21->val.m_allocOrder + v20);
      v22->m_time = *(unsigned __int64 *)((char *)&v21->val.m_time + v20);
      v22->m_tagData = *(const void **)((char *)&v21->val.m_tagData + v20);
      *(_QWORD *)&v22->m_flags.m_storage = *(_QWORD *)((char *)&v21->val.m_flags.m_storage + v20);
      *(_QWORD *)&v22->m_size = *(_QWORD *)((char *)&v21->val.m_size + v20);
      v23 = *(_QWORD *)((char *)&v21->val.m_bookmarkIndex + v20);
      v24 = v17 + 1;
      *(_QWORD *)&v22->m_bookmarkIndex = v23;
      v25 = v4->m_activePointers.m_hashMod;
      v26 = v17 + 1;
      if ( v26 <= v25 )
      {
        v27 = &v4->m_activePointers.m_elem[(signed __int64)v24];
        do
        {
          if ( v27->key != -1i64 )
            break;
          ++v26;
          ++v24;
          ++v27;
        }
        while ( v26 <= v25 );
      }
      v17 = v24;
      v19 += 8i64;
      ++v18;
    }
    while ( v24 <= v4->m_activePointers.m_hashMod );
    v8 = connectTo.m_size;
  }
  v28 = 0i64;
  v29 = v7;
  *(_QWORD *)&result.m_enum = 0i64;
  if ( v7 > 0 )
  {
    v30 = 0i64;
    v69 = 0i64;
    do
    {
      if ( connectStart.m_size == (connectStart.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(`anonymous namespace::SummaryAllocator::s_allocator, &connectStart, 4);
      connectStart.m_data[connectStart.m_size] = v8;
      ++connectStart.m_size;
      v31 = allocs.m_data;
      v32 = array;
      v8 = connectTo.m_size;
      v33 = *(int **)&array[8 * v28];
      v34 = *(int *)((char *)&allocs.m_data->m_size + v30);
      v58.m_data = *(int **)&array[8 * v28];
      owned.m_data = (int *)(v34 / 8);
      if ( (_QWORD)owned.m_data > 0i64 )
      {
        do
        {
          v35 = *(_QWORD *)&v33[2 * v2];
          v36 = 0;
          v37 = 0i64;
          v38 = 0i64;
          do
          {
            v39 = v32[v37];
            if ( v35 >= v39 && v35 < v39 + v31[v38].m_size )
            {
              if ( v8 == (connectTo.m_capacityAndFlags & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(`anonymous namespace::SummaryAllocator::s_allocator, &connectTo, 4);
                v8 = connectTo.m_size;
              }
              connectTo.m_data[v8] = v36;
              v32 = array;
              v31 = allocs.m_data;
              v8 = connectTo.m_size++ + 1;
            }
            ++v37;
            ++v36;
            ++v38;
          }
          while ( v37 < v29 );
          v33 = v58.m_data;
          ++v2;
        }
        while ( v2 < (_QWORD)owned.m_data );
        v28 = *(_QWORD *)&result.m_enum;
        v30 = v69;
      }
      ++v28;
      v30 += 56i64;
      v2 = 0i64;
      *(_QWORD *)&result.m_enum = v28;
      v69 = v30;
    }
    while ( v28 < v29 );
    v7 = v67;
    v4 = v66;
  }
  if ( connectStart.m_size == (connectStart.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(`anonymous namespace::SummaryAllocator::s_allocator, &connectStart, 4);
  connectStart.m_data[connectStart.m_size] = v8;
  ++connectStart.m_size;
  v40 = 0;
  visited.m_size = 0;
  visited.m_data = 0i64;
  visited.m_capacityAndFlags = 2147483648;
  if ( v7 > 0 )
  {
    v41 = v7;
    if ( v7 < 0 )
      v41 = v2;
    hkArrayUtil::_reserve((hkResult *)&v66, `anonymous namespace::SummaryAllocator::s_allocator, &visited, v41, 1);
    v40 = visited.m_size;
  }
  v42 = &visited.m_data[v40];
  v43 = v7 - v40;
  v44 = v7 - v40;
  if ( v43 > 0 )
    memset(v42, 0, v44);
  v45 = 0;
  visited.m_size = v7;
  v58.m_data = 0i64;
  v58.m_capacityAndFlags = 2147483648;
  v58.m_size = 0;
  if ( v7 > 0 )
  {
    v46 = v7;
    if ( v7 < 0 )
      v46 = v2;
    hkArrayUtil::_reserve((hkResult *)&v66, `anonymous namespace::SummaryAllocator::s_allocator, &v58, v46, 1);
    v45 = v58.m_size;
  }
  v47 = v7 - v45;
  if ( v47 > 0 )
    memset((char *)v58.m_data + v45, 1, v47);
  v58.m_size = v7;
  v48 = v2;
  if ( connectTo.m_size > 0 )
  {
    v49 = 0i64;
    do
    {
      ++v48;
      ++v49;
      *((_BYTE *)v58.m_data + connectTo.m_data[v49 - 1]) = 0;
    }
    while ( v48 < connectTo.m_size );
  }
  v50 = 0i64;
  v51 = 2147483648;
  owned.m_size = 0;
  v52 = 0;
  v53 = 0i64;
  owned.m_data = 0i64;
  owned.m_capacityAndFlags = 2147483648;
  if ( v29 > 0 )
  {
    do
    {
      if ( *((_BYTE *)v58.m_data + v53) )
      {
        owned.m_size = 0;
        breadthFirstSearch(v52, &connectTo, &connectStart, &visited, &owned);
        hkCheckingMemorySystem::dumpLeak(
          v4,
          (hkArrayBase<int> *)&owned.m_data,
          (hkArrayBase<unsigned __int64> *)&array,
          &allocs);
      }
      ++v53;
      ++v52;
    }
    while ( v53 < v29 );
    v51 = owned.m_capacityAndFlags;
    v50 = owned.m_data;
  }
  owned.m_size = v2;
  if ( v51 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      v50,
      4 * v51);
  v58.m_size = v2;
  if ( v58.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      v58.m_data,
      v58.m_capacityAndFlags & 0x3FFFFFFF);
  owned.m_data = 0i64;
  owned.m_capacityAndFlags = 2147483648;
  v58.m_data = 0i64;
  v58.m_size = 0;
  v58.m_capacityAndFlags = 2147483648;
  while ( 1 )
  {
    v54 = 0;
    v55 = 0;
    v56 = 0i64;
    owned.m_size = 0;
    if ( v29 <= 0 )
      break;
    do
    {
      if ( !visited.m_data[v56].m_bool )
      {
        v58.m_size = 0;
        breadthFirstSearch(v55, &connectTo, &connectStart, &visited, &v58);
        setVisited((hkArrayBase<int> *)&v58.m_data, &visited, 0);
        if ( v58.m_size >= v54
          && (v54 != v58.m_size || allocs.m_data[*v58.m_data].m_allocOrder < allocs.m_data[*owned.m_data].m_allocOrder) )
        {
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&owned,
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v58);
          v54 = owned.m_size;
        }
      }
      ++v56;
      ++v55;
    }
    while ( v56 < v29 );
    if ( v54 <= 0 )
      break;
    setVisited((hkArrayBase<int> *)&owned.m_data, &visited, (hkBool)1);
    hkCheckingMemorySystem::dumpLeak(
      v4,
      (hkArrayBase<int> *)&owned.m_data,
      (hkArrayBase<unsigned __int64> *)&array,
      &allocs);
  }
  v58.m_size = v2;
  if ( v58.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      v58.m_data,
      4 * v58.m_capacityAndFlags);
  v58.m_data = 0i64;
  v58.m_capacityAndFlags = 2147483648;
  if ( owned.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      owned.m_data,
      4 * owned.m_capacityAndFlags);
  visited.m_size = v2;
  if ( visited.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      visited.m_data,
      visited.m_capacityAndFlags & 0x3FFFFFFF);
  visited.m_data = 0i64;
  visited.m_capacityAndFlags = 2147483648;
  connectStart.m_size = 0;
  if ( connectStart.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      connectStart.m_data,
      4 * connectStart.m_capacityAndFlags);
  connectStart.m_data = 0i64;
  connectStart.m_capacityAndFlags = 2147483648;
  connectTo.m_size = 0;
  if ( connectTo.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      connectTo.m_data,
      4 * connectTo.m_capacityAndFlags);
  connectTo.m_data = 0i64;
  connectTo.m_capacityAndFlags = 2147483648;
  allocs.m_size = 0;
  if ( allocs.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      allocs.m_data,
      56 * (allocs.m_capacityAndFlags & 0x3FFFFFFF));
  allocs.m_data = 0i64;
  allocs.m_capacityAndFlags = 2147483648;
  v64 = 0;
  if ( v65 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      array,
      8 * v65);
}

// File Line: 526
// RVA: 0xC5C9F0
hkResult *__fastcall hkCheckingMemorySystem::quit(hkCheckingMemorySystem *this, hkResult *result)
{
  hkCheckingMemorySystem *v2; // rdi
  hkResult *v3; // r14
  void *v4; // rdx
  int i; // esi
  int v6; // er8
  hkMemoryAllocator *v7; // rcx
  int v8; // er8
  hkMemoryAllocator *v9; // rcx

  v2 = this;
  result->m_enum = 0;
  v3 = result;
  EnterCriticalSection(&this->m_section.m_section);
  if ( v2->m_allocators.m_size )
    v2->m_outputFunc("A thread did not clean up its allocators.\n", v2->m_outputFuncArg);
  v4 = v2->m_outputFuncArg;
  if ( v2->m_activePointers.m_numElems & 0x7FFFFFFF )
  {
    v3->m_enum = 1;
    v2->m_outputFunc(
      "**************************************************************\n"
      "* BEGIN MEMORY LEAK REPORT                                   *\n"
      "**************************************************************\n",
      v4);
    hkCheckingMemorySystem::leakReportByTime(v2);
    v2->m_outputFunc(
      "**************************************************************\n"
      "* END MEMORY LEAK REPORT                                     *\n"
      "**************************************************************\n",
      v2->m_outputFuncArg);
  }
  else
  {
    v2->m_outputFunc(
      "**************************************************************\n"
      "* NO HAVOK MEMORY LEAKS FOUND                                *\n"
      "**************************************************************\n",
      v4);
  }
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v2->m_activePointers,
    v2->m_rawAllocator);
  for ( i = 0; i < v2->m_bookmarks.m_size; ++i )
    hkCheckingMemorySystem::Bookmark::clear(&v2->m_bookmarks.m_data[i], v2->m_rawAllocator);
  v6 = v2->m_bookmarks.m_capacityAndFlags;
  v7 = v2->m_rawAllocator;
  v2->m_bookmarks.m_size = 0;
  if ( v6 >= 0 )
    v7->vfptr->bufFree(v7, v2->m_bookmarks.m_data, 16 * v6);
  v2->m_bookmarks.m_data = 0i64;
  v2->m_bookmarks.m_capacityAndFlags = 2147483648;
  if ( v2->m_checkFlags.m_storage & 4 )
    hkStackTracer::CallTree::quit(&v2->m_callTree);
  hkPaddedAllocator::quit(&v2->m_paddedAllocator);
  hkDelayedFreeAllocator::quit(&v2->m_delayedFreeAllocator);
  v8 = v2->m_allocators.m_capacityAndFlags;
  v9 = v2->m_rawAllocator;
  v2->m_allocators.m_size = 0;
  if ( v8 >= 0 )
    v9->vfptr->bufFree(v9, v2->m_allocators.m_data, 8 * v8);
  v2->m_allocators.m_data = 0i64;
  v2->m_allocators.m_capacityAndFlags = 2147483648;
  v2->m_baseAllocator = 0i64;
  LeaveCriticalSection(&v2->m_section.m_section);
  return v3;
}

// File Line: 587
// RVA: 0xC5EAA0
hkMemoryAllocator *__fastcall hkCheckingMemorySystem::getUncachedLockedHeapAllocator(hkCheckingMemorySystem *this)
{
  return this->m_mainRouter.m_heap;
}

// File Line: 592
// RVA: 0xC5D410
hkResult *__fastcall hkCheckingMemorySystem::getAllocationCallStack(hkCheckingMemorySystem *this, hkResult *result, const void *ptr, unsigned __int64 *callStack, int *stackSize, unsigned __int64 *allocSize)
{
  hkResult *v6; // rdi
  hkCheckingMemorySystem *v7; // rbx
  unsigned __int64 *v8; // rbp
  int v9; // eax
  signed __int64 v10; // rdx
  unsigned __int64 v11; // rcx
  __int64 v12; // ST20_8
  __int64 v13; // ST28_8
  __int64 v14; // ST30_8
  __int64 v15; // ST38_8
  __int64 v16; // rax
  int v17; // edx
  hkStackTracer::CallTree *v18; // rcx
  int v19; // eax

  v6 = result;
  v7 = this;
  v8 = callStack;
  v9 = (unsigned __int64)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                           &this->m_activePointers,
                           (unsigned __int64)ptr);
  if ( v9 > v7->m_activePointers.m_hashMod )
  {
    v6->m_enum = 1;
  }
  else
  {
    v10 = (signed __int64)&v7->m_activePointers.m_elem[(signed __int64)v9];
    v11 = *(signed int *)(v10 + 48);
    v12 = *(_QWORD *)(v10 + 8);
    v13 = *(_QWORD *)(v10 + 16);
    v14 = *(_QWORD *)(v10 + 24);
    v15 = *(_QWORD *)(v10 + 32);
    v16 = *(_QWORD *)(v10 + 56);
    v17 = *(_QWORD *)(v10 + 40) >> 32;
    *allocSize = v11;
    v18 = &v7->m_callTree;
    if ( v8 )
      v19 = hkStackTracer::CallTree::getCallStack(v18, v17, v8, *stackSize);
    else
      v19 = hkStackTracer::CallTree::getCallStackSize(v18, v17);
    v6->m_enum = 0;
    *stackSize = v19;
  }
  return v6;
}

// File Line: 616
// RVA: 0xC5D510
void __fastcall hkCheckingMemorySystem::setHeapScrubValues(hkCheckingMemorySystem *this, unsigned int allocValue, unsigned int freeValue)
{
  hkCheckingMemorySystem *v3; // rbx
  unsigned int v4; // esi
  unsigned int v5; // ebp

  v3 = this;
  v4 = freeValue;
  v5 = allocValue;
  EnterCriticalSection(&this->m_section.m_section);
  hkPaddedAllocator::setScrubValues(&v3->m_paddedAllocator, v5, v4);
  LeaveCriticalSection(&v3->m_section.m_section);
}

// File Line: 623
// RVA: 0xC5F8A0
hkCheckingMemorySystem::AllocatorForwarder *__fastcall hkCheckingMemorySystem::newAllocator(hkCheckingMemorySystem *this, hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int> flags, unsigned __int64 tid)
{
  hkCheckingMemorySystem *v3; // rbp
  unsigned __int64 v4; // rsi
  _QWORD *v5; // rax
  hkCheckingMemorySystem::AllocatorForwarder *v6; // rdi
  unsigned int v8; // [rsp+38h] [rbp+10h]

  v8 = flags.m_storage;
  v3 = this;
  v4 = tid;
  EnterCriticalSection(&this->m_section.m_section);
  v5 = (_QWORD *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, signed __int64))&v3->m_rawAllocator->vfptr->__vecDelDtor
                  + 1))(
                   v3->m_rawAllocator,
                   40i64);
  v6 = (hkCheckingMemorySystem::AllocatorForwarder *)v5;
  if ( v5 )
  {
    *v5 = &hkCheckingMemorySystem::AllocatorForwarder::`vftable;
    v5[1] = 0i64;
    v5[2] = 0i64;
    *(_QWORD *)((char *)v5 + 28) = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v6->m_parent = v3;
  v6->m_context.threadId = v4;
  v6->m_context.flags.m_storage = v8;
  if ( v3->m_allocators.m_size == (v3->m_allocators.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(v3->m_rawAllocator, &v3->m_allocators, 8);
  v3->m_allocators.m_data[v3->m_allocators.m_size++] = v6;
  LeaveCriticalSection(&v3->m_section.m_section);
  return v6;
}

// File Line: 635
// RVA: 0xC5F970
void __fastcall hkCheckingMemorySystem::deleteAllocator(hkCheckingMemorySystem *this, hkMemoryAllocator *a)
{
  __int64 v2; // r9
  int v3; // ebx
  hkCheckingMemorySystem *v4; // rdi
  __int64 v5; // r8
  hkCheckingMemorySystem::AllocatorForwarder **v6; // rcx
  hkMemoryAllocator **v7; // rax
  signed __int64 v8; // rsi
  __int64 v9; // rax

  v2 = this->m_allocators.m_size;
  v3 = 0;
  v4 = this;
  v5 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    __debugbreak();
  }
  else
  {
    v6 = this->m_allocators.m_data;
    v7 = (hkMemoryAllocator **)v6;
    while ( *v7 != a )
    {
      ++v5;
      ++v3;
      ++v7;
      if ( v5 >= v2 )
        goto LABEL_5;
    }
    v8 = v3;
    ((void (__fastcall *)(hkCheckingMemorySystem::AllocatorForwarder *, _QWORD, __int64))v6[v8]->vfptr->__vecDelDtor)(
      v6[v8],
      0i64,
      v5);
    v4->m_rawAllocator->vfptr->blockFree(v4->m_rawAllocator, v4->m_allocators.m_data[v8], 40);
    v9 = --v4->m_allocators.m_size;
    if ( (_DWORD)v9 != v3 )
      v4->m_allocators.m_data[v8] = v4->m_allocators.m_data[v9];
  }
}

// File Line: 651
// RVA: 0xC5CBC0
unsigned __int64 __fastcall hkCheckingMemorySystem::checkedAlloc(hkCheckingMemorySystem *this, unsigned int isBuf, hkCheckingMemorySystem::AllocationContext *context, int numBytes)
{
  hkCheckingMemorySystem *v4; // rdi
  __int64 v5; // rbp
  hkCheckingMemorySystem::AllocationContext *v6; // rsi
  unsigned int v7; // edx
  int v8; // ecx
  bool v9; // zf
  bool v10; // sf
  unsigned __int8 v11; // of
  unsigned __int64 v12; // rsi
  hkMemoryAllocator *v13; // rdx
  unsigned __int64 v14; // rax
  __int128 v16; // [rsp+20h] [rbp-88h]
  __int128 v17; // [rsp+30h] [rbp-78h]
  __int128 v18; // [rsp+40h] [rbp-68h]
  __int64 v19; // [rsp+50h] [rbp-58h]
  __int128 v20; // [rsp+60h] [rbp-48h]
  __int128 v21; // [rsp+70h] [rbp-38h]
  __int128 v22; // [rsp+80h] [rbp-28h]
  __int64 v23; // [rsp+90h] [rbp-18h]

  v4 = this;
  v5 = numBytes;
  v6 = context;
  EnterCriticalSection(&this->m_section.m_section);
  if ( (signed int)v5 < 0 )
  {
    v4->m_outputFunc("Negative size to allocate\n", v4->m_outputFuncArg);
    __debugbreak();
  }
  v7 = v6->flags.m_storage;
  if ( v7 & 4 )
  {
    v6->curInUse += v5;
    v8 = v6->curInUse;
    v11 = __OFSUB__(v6->peakInUse, v8);
    v9 = v6->peakInUse == v8;
    v10 = v6->peakInUse - v8 < 0;
  }
  else
  {
    if ( !(v7 & 8) )
      goto LABEL_10;
    v11 = __OFSUB__(v6->peakInUse, (_DWORD)v5);
    v9 = v6->peakInUse == (_DWORD)v5;
    v10 = v6->peakInUse - (signed int)v5 < 0;
    v8 = v5;
  }
  if ( !((unsigned __int8)(v10 ^ v11) | v9) )
    v8 = v6->peakInUse;
  v6->peakInUse = v8;
LABEL_10:
  LODWORD(v18) = v7;
  *((_QWORD *)&v18 + 1) = (unsigned int)v5;
  *(_QWORD *)&v16 = v6->threadId;
  *((_QWORD *)&v17 + 1) = 0i64;
  *((_QWORD *)&v16 + 1) = v4->m_allocOrder;
  v4->m_allocOrder = *((_QWORD *)&v16 + 1) + 1i64;
  *(_QWORD *)&v17 = hkStopwatch::getTickCounter();
  LODWORD(v19) = v4->m_bookmarks.m_size - 1;
  v12 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&v4->m_baseAllocator->vfptr->__vecDelDtor + 1))(
          v4->m_baseAllocator,
          (unsigned int)v5);
  if ( v4->m_checkFlags.m_storage & 4 )
    DWORD1(v18) = hkStackTracer::CallTree::insertCallStack(&v4->m_callTree, &v4->m_stackTracer);
  else
    DWORD1(v18) = -1;
  v13 = v4->m_rawAllocator;
  v20 = v16;
  v21 = v17;
  v22 = v18;
  v23 = v19;
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::insert(
    &v4->m_activePointers,
    v13,
    v12,
    (hkCheckingMemorySystem::AllocInfo *)&v20);
  v14 = v4->m_peakInUse;
  v4->m_currentInUse += v5;
  if ( v4->m_currentInUse > v14 )
    v14 = v4->m_currentInUse;
  v4->m_peakInUse = v14;
  LeaveCriticalSection(&v4->m_section.m_section);
  return v12;
}

// File Line: 699
// RVA: 0xC5CD40
void __fastcall hkCheckingMemorySystem::checkedFree(hkCheckingMemorySystem *this, unsigned int isBuf, hkCheckingMemorySystem::AllocationContext *context, void *p, int numBytes)
{
  hkCheckingMemorySystem *v5; // rdi
  void *v6; // rbp
  hkCheckingMemorySystem::AllocationContext *v7; // rsi
  Dummy *v8; // r12
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v9; // rcx
  signed __int64 v10; // rdx
  __int64 v11; // r8
  __int64 v12; // r13
  unsigned __int64 v13; // rax
  __int64 v14; // rax
  hkMemoryAllocator *v15; // rcx
  hkCheckingMemorySystem::AllocInfo info; // [rsp+20h] [rbp-78h]
  __int64 v17; // [rsp+A0h] [rbp+8h]
  __int64 v18; // [rsp+B0h] [rbp+18h]

  v5 = this;
  v6 = p;
  v7 = context;
  EnterCriticalSection(&this->m_section.m_section);
  if ( v7->flags.m_storage & 4 )
    v7->curInUse -= numBytes;
  if ( v6 )
  {
    v8 = hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
           &v5->m_activePointers,
           (unsigned __int64)v6);
    if ( (signed int)v8 > v5->m_activePointers.m_hashMod )
    {
      v5->m_outputFunc("Freeing block not from this allocator", v5->m_outputFuncArg);
      __debugbreak();
    }
    v9 = v5->m_activePointers.m_elem;
    v10 = (signed __int64)(signed int)v8 << 6;
    v11 = *(_QWORD *)((char *)&v9->val.m_size + v10);
    v12 = *(_QWORD *)((char *)&v9->val.m_flags.m_storage + v10);
    v17 = *(unsigned __int64 *)((char *)&v9->val.m_threadId + v10);
    info.m_threadId = *(unsigned __int64 *)((char *)&v9->val.m_threadId + v10);
    info.m_allocOrder = *(unsigned __int64 *)((char *)&v9->val.m_allocOrder + v10);
    v13 = *(unsigned __int64 *)((char *)&v9->val.m_time + v10);
    *(_QWORD *)&info.m_flags.m_storage = v12;
    info.m_time = v13;
    v18 = v11;
    info.m_tagData = *(const void **)((char *)&v9->val.m_tagData + v10);
    v14 = *(_QWORD *)((char *)&v9->val.m_bookmarkIndex + v10);
    *(_QWORD *)&info.m_size = v11;
    *(_QWORD *)&info.m_bookmarkIndex = v14;
    if ( (_DWORD)v11 != numBytes )
    {
      hkCheckingMemorySystem::danger(v5, "Freeing block of incorrect size", v6, &info);
      __debugbreak();
    }
    if ( (_DWORD)v12 != v7->flags.m_storage )
    {
      hkCheckingMemorySystem::danger(v5, "Freeing block with different tag", v6, &info);
      __debugbreak();
    }
    if ( v7->flags.m_storage & 4 && v17 != v7->threadId )
    {
      hkCheckingMemorySystem::danger(v5, "Freeing block from a different thread", v6, &info);
      __debugbreak();
    }
    if ( info.m_locks )
    {
      hkCheckingMemorySystem::danger(v5, "Freeing locked block", v6, &info);
      __debugbreak();
    }
    if ( v5->m_checkFlags.m_storage & 4 )
      hkStackTracer::CallTree::releaseCallStack(&v5->m_callTree, info.m_traceId);
    hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::remove(
      &v5->m_activePointers,
      v8);
    v15 = v5->m_baseAllocator;
    v5->m_currentInUse -= (signed int)v18;
    v15->vfptr->blockFree(v15, v6, numBytes);
  }
  else if ( numBytes )
  {
    v5->m_outputFunc("Given nonzero bytes to free with an null address\n", v5->m_outputFuncArg);
    __debugbreak();
  }
  LeaveCriticalSection(&v5->m_section.m_section);
}

// File Line: 755
// RVA: 0xC5D570
__int64 __fastcall hkCheckingMemorySystem::isOk(hkCheckingMemorySystem *this)
{
  hkCheckingMemorySystem *v1; // rdi
  unsigned int v2; // er14
  __int64 v3; // r8
  int v4; // edx
  __int64 v5; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v6; // rax
  int v7; // esi
  signed __int64 v8; // rdx
  __int64 v9; // rcx
  const void *v10; // rbp
  unsigned __int64 v11; // rax
  __int64 v12; // r8
  int v13; // edx
  __int64 v14; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v15; // rax
  hkCheckingMemorySystem::AllocInfo info; // [rsp+20h] [rbp-58h]

  v1 = this;
  EnterCriticalSection(&this->m_section.m_section);
  v2 = 1;
  if ( v1->m_checkFlags.m_storage & 8 )
  {
    v3 = v1->m_activePointers.m_hashMod;
    v4 = 0;
    v5 = 0i64;
    if ( v3 >= 0 )
    {
      v6 = v1->m_activePointers.m_elem;
      do
      {
        if ( v6->key != -1i64 )
          break;
        ++v5;
        ++v4;
        ++v6;
      }
      while ( v5 <= v3 );
    }
    v7 = v4;
    if ( v4 <= v1->m_activePointers.m_hashMod )
    {
      do
      {
        v8 = (signed __int64)&v1->m_activePointers.m_elem[(signed __int64)v7];
        v9 = *(_QWORD *)(v8 + 48);
        v10 = *(const void **)v8;
        info.m_threadId = *(_QWORD *)(v8 + 8);
        v11 = *(_QWORD *)(v8 + 16);
        *(_QWORD *)&info.m_size = v9;
        info.m_allocOrder = v11;
        info.m_time = *(_QWORD *)(v8 + 24);
        info.m_tagData = *(const void **)(v8 + 32);
        *(_QWORD *)&info.m_flags.m_storage = *(_QWORD *)(v8 + 40);
        *(_QWORD *)&info.m_bookmarkIndex = *(_QWORD *)(v8 + 56);
        if ( !hkPaddedAllocator::isOk(&v1->m_paddedAllocator, v10, v9) )
        {
          hkCheckingMemorySystem::danger(v1, "Damaged block:\n", v10, &info);
          v2 = 0;
        }
        v12 = v1->m_activePointers.m_hashMod;
        v13 = v7 + 1;
        v14 = v7 + 1;
        if ( v14 <= v12 )
        {
          v15 = &v1->m_activePointers.m_elem[(signed __int64)v13];
          do
          {
            if ( v15->key != -1i64 )
              break;
            ++v14;
            ++v13;
            ++v15;
          }
          while ( v14 <= v12 );
        }
        v7 = v13;
      }
      while ( v13 <= v1->m_activePointers.m_hashMod );
    }
  }
  if ( v1->m_checkFlags.m_storage & 0x10 && !hkDelayedFreeAllocator::isOk(&v1->m_delayedFreeAllocator) )
    v2 = 0;
  LeaveCriticalSection(&v1->m_section.m_section);
  return v2;
}

// File Line: 785
// RVA: 0xC5CF40
hkResult *__fastcall hkCheckingMemorySystem::getMemorySnapshot(hkCheckingMemorySystem *this, hkResult *result, hkMemorySnapshot *snapshot)
{
  _RTL_CRITICAL_SECTION *v3; // rbx
  hkCheckingMemorySystem *v4; // r14
  hkMemorySnapshot *v5; // rdi
  int v6; // er13
  int v7; // esi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *v8; // r10
  __int64 v9; // r9
  signed int v10; // edx
  __int64 v11; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v12; // rax
  signed int v13; // er12
  signed __int64 v14; // r13
  char *v15; // rcx
  bool v16; // zf
  char *v17; // rsi
  __int64 v18; // r15
  char *v19; // rcx
  char *v20; // rax
  char *v21; // r9
  int v22; // esi
  _QWORD *v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // rcx
  __int64 v29; // rax
  int v30; // eax
  int v31; // edx
  __int64 v32; // r9
  __int64 v33; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v34; // rax
  hkStackTracer::CallTree::Node *v35; // r12
  int v36; // er15
  int *v37; // rsi
  char *v38; // r9
  char *v39; // rax
  int v40; // er15
  __int64 v41; // rsi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *v42; // r15
  int v43; // eax
  int solver; // [rsp+30h] [rbp-D0h]
  int parent; // [rsp+34h] [rbp-CCh]
  int debug; // [rsp+38h] [rbp-C8h]
  hkPaddedAllocator::Allocation resulta; // [rsp+40h] [rbp-C0h]
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *v49; // [rsp+50h] [rbp-B0h]
  __int64 v50; // [rsp+58h] [rbp-A8h]
  __int64 v51; // [rsp+60h] [rbp-A0h]
  __int64 v52; // [rsp+68h] [rbp-98h]
  __int64 v53; // [rsp+70h] [rbp-90h]
  int v54[2]; // [rsp+78h] [rbp-88h]
  __int64 v55; // [rsp+80h] [rbp-80h]
  __int64 v56; // [rsp+88h] [rbp-78h]
  __int64 v57; // [rsp+90h] [rbp-70h]
  __int64 v58; // [rsp+98h] [rbp-68h]
  __int64 v59; // [rsp+A0h] [rbp-60h]
  __int64 v60; // [rsp+A8h] [rbp-58h]
  __int64 v61; // [rsp+B0h] [rbp-50h]
  __int64 v62; // [rsp+C0h] [rbp-40h]
  unsigned __int64 addrs; // [rsp+D0h] [rbp-30h]
  int v64; // [rsp+510h] [rbp+410h]
  hkResult *v65; // [rsp+518h] [rbp+418h]
  int id; // [rsp+528h] [rbp+428h]

  v65 = result;
  v3 = &this->m_section.m_section;
  v4 = this;
  v5 = snapshot;
  EnterCriticalSection(&this->m_section.m_section);
  v6 = hkMemorySnapshot::addProvider(v5, "<System>", -1);
  id = v6;
  v7 = v6;
  parent = hkMemorySnapshot::addProvider(v5, "hkStatsAllocator(CallTree)", v6);
  v64 = v6;
  if ( v4->m_checkFlags.m_storage & 0x10 )
  {
    v7 = hkDelayedFreeAllocator::addToSnapshot(&v4->m_delayedFreeAllocator, v5, v6);
    v64 = v7;
  }
  if ( v4->m_checkFlags.m_storage & 8 )
  {
    v7 = hkMemorySnapshot::addProvider(v5, "hkPaddedAllocator", v7);
    v64 = v7;
  }
  debug = hkMemorySnapshot::addProvider(v5, "hkRecallAllocator", v6);
  solver = hkMemorySnapshot::addProvider(v5, "hkCheckingMemorySystem", -1);
  hkMemorySnapshot::addParentProvider(v5, solver, v7);
  hkMemorySnapshot::addParentProvider(v5, solver, parent);
  hkMemorySnapshot::setRouterWiring(v5, solver, solver, solver, debug, solver);
  v8 = &v4->m_activePointers;
  v9 = v4->m_activePointers.m_hashMod;
  v10 = 0;
  v11 = 0i64;
  v49 = &v4->m_activePointers;
  if ( (signed int)v9 >= 0 )
  {
    v12 = v8->m_elem;
    do
    {
      if ( v12->key != -1i64 )
        break;
      ++v11;
      ++v10;
      ++v12;
    }
    while ( v11 <= v9 );
  }
  v13 = v10;
  if ( v10 <= (signed int)v9 )
  {
    do
    {
      v14 = (signed __int64)v13 << 6;
      v15 = (char *)v8->m_elem + v14;
      v16 = (v4->m_checkFlags.m_storage & 8) == 0;
      v17 = *(char **)v15;
      v18 = *((_QWORD *)v15 + 6);
      v57 = *((_QWORD *)v15 + 1);
      v58 = *((_QWORD *)v15 + 2);
      v59 = *((_QWORD *)v15 + 3);
      v60 = *((_QWORD *)v15 + 4);
      v61 = *((_QWORD *)v15 + 5);
      v62 = *((_QWORD *)v15 + 7);
      if ( v16 )
      {
        hkMemorySnapshot::addItem(v5, id, (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1, v17, v18);
      }
      else
      {
        hkPaddedAllocator::getUnderlyingAllocation(&v4->m_paddedAllocator, &resulta, v17, v18);
        hkMemorySnapshot::addItem(
          v5,
          id,
          (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1,
          resulta.address,
          resulta.size);
        v19 = (char *)resulta.address;
        if ( resulta.address != v17 )
        {
          hkMemorySnapshot::addItem(v5, v64, 0, resulta.address, (_DWORD)v17 - LODWORD(resulta.address));
          v19 = (char *)resulta.address;
        }
        v20 = &v19[resulta.size];
        v21 = &v17[(signed int)v18];
        if ( v20 != v21 )
          hkMemorySnapshot::addItem(v5, v64, 0, v21, (_DWORD)v20 - (_DWORD)v21);
      }
      v22 = hkMemorySnapshot::addItem(v5, solver, (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1, v17, v18);
      if ( v4->m_checkFlags.m_storage & 4 )
      {
        v23 = (unsigned __int64 *)((char *)&v4->m_activePointers.m_elem->key + v14);
        v24 = v23[1];
        v53 = v23[4];
        v25 = v23[5];
        v50 = v24;
        v26 = v23[2];
        *(_QWORD *)v54 = v25;
        v27 = v23[6];
        v51 = v26;
        v28 = v23[3];
        v55 = v27;
        v29 = v23[7];
        v52 = v28;
        v56 = v29;
        v30 = hkStackTracer::CallTree::getCallStack(&v4->m_callTree, v54[1], &addrs, 128);
        hkMemorySnapshot::setCallStack(v5, v22, &addrs, v30);
      }
      v8 = &v4->m_activePointers;
      v31 = v13 + 1;
      v32 = v4->m_activePointers.m_hashMod;
      v33 = v13 + 1;
      if ( v33 <= v32 )
      {
        v34 = &v8->m_elem[(signed __int64)v31];
        do
        {
          if ( v34->key != -1i64 )
            break;
          ++v33;
          ++v31;
          ++v34;
        }
        while ( v33 <= v32 );
      }
      v13 = v31;
    }
    while ( v31 <= (signed int)v32 );
    v6 = id;
    v3 = &v4->m_section.m_section;
  }
  v35 = v4->m_callTree.m_nodes.m_data;
  v36 = 24 * (v4->m_callTree.m_nodes.m_capacityAndFlags & 0x3FFFFFFF);
  hkMemorySnapshot::addItem(
    v5,
    parent,
    (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1,
    v4->m_callTree.m_nodes.m_data,
    v36);
  v37 = (int *)v4->m_debugAllocator.m_head;
  if ( v37 )
  {
    do
    {
      hkMemorySnapshot::addItem(v5, v6, (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1, v37, v37[2]);
      hkMemorySnapshot::addItem(v5, debug, 0, v37, 16);
      hkMemorySnapshot::addItem(v5, debug, (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1, v37 + 4, v37[3]);
      v38 = (char *)v37 + v37[3] + 16;
      v39 = (char *)v37 + v37[2];
      if ( v38 != v39 )
        hkMemorySnapshot::addItem(v5, debug, 0, v38, (_DWORD)v39 - (_DWORD)v38);
      v37 = *(int **)v37;
    }
    while ( v37 );
    v3 = &v4->m_section.m_section;
  }
  hkMemorySnapshot::addItem(v5, solver, 0, v35, v36);
  hkMemorySnapshot::addItem(v5, solver, 0, v4->m_allocators.m_data, 8 * v4->m_allocators.m_capacityAndFlags);
  v40 = 0;
  if ( v4->m_allocators.m_size > 0 )
  {
    v41 = 0i64;
    do
    {
      hkMemorySnapshot::addItem(v5, solver, 0, v4->m_allocators.m_data[v41], 40);
      ++v40;
      ++v41;
    }
    while ( v40 < v4->m_allocators.m_size );
  }
  v42 = v49;
  v43 = hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::getMemSize(v49);
  hkMemorySnapshot::addItem(v5, solver, 0, v42->m_elem, v43);
  v65->m_enum = 0;
  LeaveCriticalSection(v3);
  return v65;
}

// File Line: 862
// RVA: 0xC5D810
signed __int64 __fastcall hkCheckingMemorySystem::findBaseAddress(hkCheckingMemorySystem *this, const void *pquery, int nbytes)
{
  _RTL_CRITICAL_SECTION *v3; // rbx
  hkCheckingMemorySystem *v4; // r14
  __int64 v5; // r12
  const void *v6; // r13
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *v7; // r14
  signed int v8; // eax
  signed __int64 v9; // r15
  signed __int64 v10; // rdi
  signed __int64 v11; // rdx
  __int64 v12; // ST20_8
  __int64 v13; // ST28_8
  __int64 v14; // ST30_8
  __int64 v15; // ST38_8
  __int64 v16; // ST40_8
  __int64 v17; // ST50_8
  signed int v18; // ebp
  signed int v19; // esi
  signed int v20; // eax
  signed __int64 v21; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v22; // rax
  signed int v23; // edx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v24; // r9
  signed __int64 v25; // rcx
  __int64 v26; // ST20_8
  __int64 v27; // ST28_8
  __int64 v28; // ST30_8
  __int64 v29; // ST38_8
  __int64 v30; // ST40_8
  __int64 v31; // ST50_8
  signed __int64 v32; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v33; // rax
  signed __int64 v34; // rdx
  __int64 v35; // ST20_8
  __int64 v36; // ST28_8
  __int64 v37; // ST30_8
  __int64 v38; // ST38_8
  __int64 v39; // ST40_8
  __int64 v40; // ST50_8

  v3 = &this->m_section.m_section;
  v4 = this;
  v5 = nbytes;
  v6 = pquery;
  EnterCriticalSection(&this->m_section.m_section);
  v7 = &v4->m_activePointers;
  v8 = (unsigned __int64)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                           v7,
                           (unsigned __int64)v6);
  v9 = v7->m_hashMod;
  if ( v8 <= (signed int)v9 )
  {
    v10 = -1i64;
    v11 = (signed __int64)&v7->m_elem[(signed __int64)v8];
    v12 = *(_QWORD *)(v11 + 8);
    if ( (signed int)v5 <= *(_DWORD *)(v11 + 48) )
      v10 = (signed __int64)v6;
    v13 = *(_QWORD *)(v11 + 16);
    v14 = *(_QWORD *)(v11 + 24);
    v15 = *(_QWORD *)(v11 + 32);
    v16 = *(_QWORD *)(v11 + 40);
    v17 = *(_QWORD *)(v11 + 56);
    goto LABEL_24;
  }
  v10 = ((unsigned __int64)v6 + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v18 = 0;
  v19 = 0;
  do
  {
    v10 -= 16i64;
    v20 = (unsigned __int64)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                              v7,
                              v10);
    if ( v20 <= (signed int)v9 )
    {
      v34 = (signed __int64)&v7->m_elem[(signed __int64)v20];
      v35 = *(_QWORD *)(v34 + 8);
      v36 = *(_QWORD *)(v34 + 16);
      v37 = *(_QWORD *)(v34 + 24);
      v38 = *(_QWORD *)(v34 + 32);
      v39 = *(_QWORD *)(v34 + 40);
      v40 = *(_QWORD *)(v34 + 56);
      if ( (unsigned __int64)v6 + v5 <= v10 + *(signed int *)(v34 + 48) )
        goto LABEL_24;
      goto LABEL_23;
    }
    ++v19;
  }
  while ( v19 < 50 );
  v21 = 0i64;
  if ( (signed int)v9 >= 0 )
  {
    v22 = v7->m_elem;
    do
    {
      if ( v22->key != -1i64 )
        break;
      ++v21;
      ++v18;
      ++v22;
    }
    while ( v21 <= v9 );
  }
  v23 = v18;
  if ( v18 > (signed int)v9 )
  {
LABEL_23:
    v10 = -1i64;
    goto LABEL_24;
  }
  v24 = v7->m_elem;
  while ( 1 )
  {
    v25 = (signed __int64)&v24[(signed __int64)v23];
    v10 = *(_QWORD *)v25;
    if ( *(_QWORD *)v25 <= (unsigned __int64)v6 )
    {
      v26 = *(_QWORD *)(v25 + 8);
      v27 = *(_QWORD *)(v25 + 16);
      v28 = *(_QWORD *)(v25 + 24);
      v29 = *(_QWORD *)(v25 + 32);
      v30 = *(_QWORD *)(v25 + 40);
      v31 = *(_QWORD *)(v25 + 56);
      if ( (unsigned __int64)v6 + v5 <= v10 + *(signed int *)(v25 + 48) )
        break;
    }
    v32 = ++v23;
    if ( v23 <= v9 )
    {
      v33 = &v24[(signed __int64)v23];
      do
      {
        if ( v33->key != -1i64 )
          break;
        ++v32;
        ++v23;
        ++v33;
      }
      while ( v32 <= v9 );
    }
    if ( v23 > (signed int)v9 )
      goto LABEL_23;
  }
LABEL_24:
  LeaveCriticalSection(v3);
  return v10;
}

// File Line: 931
// RVA: 0xC5DA40
void __fastcall hkCheckingMemorySystem::lockBaseAddress(hkCheckingMemorySystem *this, const void *p)
{
  _RTL_CRITICAL_SECTION *v2; // rsi
  hkCheckingMemorySystem *v3; // rbx
  const void *v4; // rdi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v5; // rdi
  __int64 v6; // rax
  unsigned __int64 v7; // r8
  unsigned __int64 v8; // r9
  const void *v9; // r10
  __int64 v10; // r11
  __int64 v11; // rbx

  v2 = &this->m_section.m_section;
  v3 = this;
  v4 = p;
  EnterCriticalSection(&this->m_section.m_section);
  v5 = &v3->m_activePointers.m_elem[(signed __int64)(signed int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                                                                  &v3->m_activePointers,
                                                                  (unsigned __int64)v4)];
  v6 = *(_QWORD *)&v5->val.m_size;
  v7 = v5->val.m_allocOrder;
  v8 = v5->val.m_time;
  v9 = v5->val.m_tagData;
  v10 = *(_QWORD *)&v5->val.m_flags.m_storage;
  v11 = *(_QWORD *)&v5->val.m_bookmarkIndex;
  v5->val.m_threadId = v5->val.m_threadId;
  v5->val.m_allocOrder = v7;
  v5->val.m_time = v8;
  v5->val.m_tagData = v9;
  *(_QWORD *)&v5->val.m_flags.m_storage = v10;
  *(_QWORD *)&v5->val.m_size = v6 + 0x100000000i64;
  *(_QWORD *)&v5->val.m_bookmarkIndex = v11;
  LeaveCriticalSection(v2);
}

// File Line: 943
// RVA: 0xC5DAF0
void __fastcall hkCheckingMemorySystem::unlockBaseAddress(hkCheckingMemorySystem *this, const void *p)
{
  _RTL_CRITICAL_SECTION *v2; // rsi
  hkCheckingMemorySystem *v3; // rbx
  const void *v4; // rdi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v5; // rdi
  __int64 v6; // rax
  unsigned __int64 v7; // r8
  unsigned __int64 v8; // r9
  const void *v9; // r10
  __int64 v10; // r11
  __int64 v11; // rbx

  v2 = &this->m_section.m_section;
  v3 = this;
  v4 = p;
  EnterCriticalSection(&this->m_section.m_section);
  v5 = &v3->m_activePointers.m_elem[(signed __int64)(signed int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                                                                  &v3->m_activePointers,
                                                                  (unsigned __int64)v4)];
  v6 = *(_QWORD *)&v5->val.m_size;
  v7 = v5->val.m_allocOrder;
  v8 = v5->val.m_time;
  v9 = v5->val.m_tagData;
  v10 = *(_QWORD *)&v5->val.m_flags.m_storage;
  v11 = *(_QWORD *)&v5->val.m_bookmarkIndex;
  v5->val.m_threadId = v5->val.m_threadId;
  v5->val.m_allocOrder = v7;
  v5->val.m_time = v8;
  v5->val.m_tagData = v9;
  *(_QWORD *)&v5->val.m_flags.m_storage = v10;
  *(_QWORD *)&v5->val.m_size = v6 - 0x100000000i64;
  *(_QWORD *)&v5->val.m_bookmarkIndex = v11;
  LeaveCriticalSection(v2);
}

// File Line: 956
// RVA: 0xC5DBA0
void __fastcall hkCheckingMemorySystem::tagAddress(hkCheckingMemorySystem *this, const void *baseAddress, const void *data)
{
  const void *v3; // rdi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v4; // r11
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // r8
  __int64 v7; // r9
  __int64 v8; // r10
  const void *v9; // ST38_8
  __int64 v10; // rax

  v3 = data;
  v4 = &this->m_activePointers.m_elem[(signed __int64)(signed int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                                                                    &this->m_activePointers,
                                                                    (unsigned __int64)baseAddress)];
  v5 = v4->val.m_allocOrder;
  v6 = v4->val.m_time;
  v7 = *(_QWORD *)&v4->val.m_size;
  v8 = *(_QWORD *)&v4->val.m_bookmarkIndex;
  v9 = v4->val.m_tagData;
  v10 = *(_QWORD *)&v4->val.m_flags.m_storage;
  v4->val.m_threadId = v4->val.m_threadId;
  v4->val.m_allocOrder = v5;
  v4->val.m_time = v6;
  v4->val.m_tagData = v3;
  *(_QWORD *)&v4->val.m_flags.m_storage = v10;
  *(_QWORD *)&v4->val.m_size = v7;
  *(_QWORD *)&v4->val.m_bookmarkIndex = v8;
}

// File Line: 976
// RVA: 0xC5DCE0
hkMemoryRouter *__fastcall hkCheckingMemorySystem::mainInit(hkCheckingMemorySystem *this, hkMemorySystem::FrameInfo *info, hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkCheckingMemorySystem *v3; // rbx

  v3 = this;
  this->m_frameInfo = (hkMemorySystem::FrameInfo)info->m_solverBufferSize;
  if ( !(flags.m_storage & 1) )
    return &this->m_mainRouter;
  ((void (__fastcall *)(hkCheckingMemorySystem *, hkMemoryRouter *, const char *, _QWORD))this->vfptr->threadInit)(
    this,
    &this->m_mainRouter,
    "main",
    (unsigned int)flags.m_storage);
  return &v3->m_mainRouter;
}

// File Line: 990
// RVA: 0xC5DD30
hkResult *__fastcall hkCheckingMemorySystem::mainQuit(hkCheckingMemorySystem *this, hkResult *result, hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkResult *v3; // rbx
  hkCheckingMemorySystem *v4; // rdi
  hkResult *v5; // rax

  v3 = result;
  v4 = this;
  if ( flags.m_storage & 1 )
  {
    ((void (__fastcall *)(hkCheckingMemorySystem *, hkMemoryRouter *))this->vfptr->threadQuit)(
      this,
      &this->m_mainRouter);
    hkCheckingMemorySystem::quit(v4, v3);
    v5 = v3;
  }
  else
  {
    v5 = result;
    result->m_enum = 0;
  }
  return v5;
}

// File Line: 1005
// RVA: 0xC5DD90
void __fastcall hkCheckingMemorySystem::threadInit(hkCheckingMemorySystem *this, hkMemoryRouter *router, const char *name, hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkCheckingMemorySystem *v4; // rsi
  hkMemoryRouter *v5; // rdi
  unsigned __int64 v6; // rax
  char v7; // r8
  unsigned __int64 v8; // rbp
  hkCheckingMemorySystem::AllocatorForwarder *v9; // rax
  hkCheckingMemorySystem::AllocatorForwarder *v10; // rax
  int v11; // [rsp+48h] [rbp+20h]

  v11 = flags.m_storage;
  v4 = this;
  v5 = router;
  EnterCriticalSection(&this->m_section.m_section);
  v6 = hkThread::getMyThreadId();
  v7 = v11;
  v8 = v6;
  if ( v11 & 1 )
  {
    v9 = hkCheckingMemorySystem::newAllocator(
           v4,
           (hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int>)1,
           v6);
    v7 = v11;
    v5->m_heap = (hkMemoryAllocator *)&v9->vfptr;
    v5->m_debug = (hkMemoryAllocator *)&v4->m_debugAllocator.vfptr;
    v5->m_temp = 0i64;
    v5->m_solver = 0i64;
  }
  if ( v7 & 2 )
  {
    v10 = hkCheckingMemorySystem::newAllocator(
            v4,
            (hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int>)2,
            v8);
    hkLifoAllocator::init(
      &v5->m_stack,
      (hkMemoryAllocator *)&v10->vfptr,
      (hkMemoryAllocator *)&v10->vfptr,
      (hkMemoryAllocator *)&v10->vfptr);
    v5->m_temp = (hkMemoryAllocator *)hkCheckingMemorySystem::newAllocator(
                                        v4,
                                        (hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int>)4,
                                        v8);
    v5->m_solver = (hkMemoryAllocator *)hkCheckingMemorySystem::newAllocator(
                                          v4,
                                          (hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int>)8,
                                          v8);
  }
  LeaveCriticalSection(&v4->m_section.m_section);
}

// File Line: 1041
// RVA: 0xC5DE70
void __fastcall hkCheckingMemorySystem::threadQuit(hkCheckingMemorySystem *this, hkMemoryRouter *router, hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkCheckingMemorySystem *v3; // rsi
  hkMemoryRouter *v4; // rdi
  char v5; // al
  hkMemoryAllocator *v6; // rdx
  __int128 allocators; // [rsp+20h] [rbp-28h]
  __int64 v8; // [rsp+30h] [rbp-18h]
  int v9; // [rsp+60h] [rbp+18h]

  v9 = flags.m_storage;
  v3 = this;
  v4 = router;
  EnterCriticalSection(&this->m_section.m_section);
  v5 = v9;
  if ( v9 & 2 )
  {
    allocators = 0ui64;
    v8 = 0i64;
    hkLifoAllocator::quit(&v4->m_stack, (hkMemoryAllocator **)&allocators);
    hkCheckingMemorySystem::deleteAllocator(v3, (hkMemoryAllocator *)allocators);
    hkCheckingMemorySystem::deleteAllocator(v3, v4->m_temp);
    v6 = v4->m_solver;
    v4->m_temp = 0i64;
    hkCheckingMemorySystem::deleteAllocator(v3, v6);
    v5 = v9;
    v4->m_solver = 0i64;
  }
  if ( v5 & 1 )
  {
    hkCheckingMemorySystem::deleteAllocator(v3, v4->m_heap);
    hkMemUtil::memSet(v4, 0, 128);
  }
  LeaveCriticalSection(&v3->m_section.m_section);
}

// File Line: 1066
// RVA: 0xC5DF40
void __fastcall hkCheckingMemorySystem::getMemoryStatistics(hkCheckingMemorySystem *this, hkMemorySystem::MemoryStatistics *stats)
{
  hkMemorySystem::MemoryStatistics *v2; // rsi
  hkCheckingMemorySystem *v3; // rbp
  int v4; // edi
  hkMemorySystem::MemoryStatistics::Entry *v5; // rbx
  hkStringPtr *v6; // rbx
  signed __int64 v7; // rbx
  hkStringPtr *v8; // rcx
  hkStringPtr *v9; // rbx
  signed __int64 v10; // rbx
  hkStringPtr *v11; // rcx
  hkStringPtr *v12; // rbx
  signed __int64 v13; // rbx
  hkStringPtr *v14; // rcx

  v2 = stats;
  v3 = this;
  v4 = stats->m_entries.m_size - 1;
  if ( v4 >= 0 )
  {
    v5 = &stats->m_entries.m_data[v4];
    do
    {
      hkStringPtr::~hkStringPtr(&v5->m_allocatorName);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v2->m_entries.m_size = 0;
  if ( !(v2->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 56);
  v6 = &v2->m_entries.m_data[v2->m_entries.m_size].m_allocatorName;
  if ( v6 )
  {
    hkStringPtr::hkStringPtr(v6);
    v6[1].m_stringAndFlag = (const char *)-1i64;
    v6[2].m_stringAndFlag = (const char *)-1i64;
    v6[3].m_stringAndFlag = (const char *)-1i64;
    v6[4].m_stringAndFlag = (const char *)-1i64;
    v6[5].m_stringAndFlag = (const char *)-1i64;
    v6[6].m_stringAndFlag = (const char *)-1i64;
  }
  v7 = (signed __int64)&v2->m_entries.m_data[v2->m_entries.m_size];
  v8 = &v2->m_entries.m_data[v2->m_entries.m_size++].m_allocatorName;
  hkStringPtr::operator=(v8, "System");
  v3->m_baseAllocator->vfptr->getMemoryStatistics(v3->m_baseAllocator, (hkMemoryAllocator::MemoryStatistics *)(v7 + 8));
  if ( v2->m_entries.m_size == (v2->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 56);
  v9 = &v2->m_entries.m_data[v2->m_entries.m_size].m_allocatorName;
  if ( v9 )
  {
    hkStringPtr::hkStringPtr(v9);
    v9[1].m_stringAndFlag = (const char *)-1i64;
    v9[2].m_stringAndFlag = (const char *)-1i64;
    v9[3].m_stringAndFlag = (const char *)-1i64;
    v9[4].m_stringAndFlag = (const char *)-1i64;
    v9[5].m_stringAndFlag = (const char *)-1i64;
    v9[6].m_stringAndFlag = (const char *)-1i64;
  }
  v10 = (signed __int64)&v2->m_entries.m_data[v2->m_entries.m_size];
  v11 = &v2->m_entries.m_data[v2->m_entries.m_size++].m_allocatorName;
  hkStringPtr::operator=(v11, "Heap");
  v3->m_paddedAllocator.vfptr->getMemoryStatistics(
    (hkMemoryAllocator *)&v3->m_paddedAllocator.vfptr,
    (hkMemoryAllocator::MemoryStatistics *)(v10 + 8));
  if ( v2->m_entries.m_size == (v2->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 56);
  v12 = &v2->m_entries.m_data[v2->m_entries.m_size].m_allocatorName;
  if ( v12 )
  {
    hkStringPtr::hkStringPtr(v12);
    v12[1].m_stringAndFlag = (const char *)-1i64;
    v12[2].m_stringAndFlag = (const char *)-1i64;
    v12[3].m_stringAndFlag = (const char *)-1i64;
    v12[4].m_stringAndFlag = (const char *)-1i64;
    v12[5].m_stringAndFlag = (const char *)-1i64;
    v12[6].m_stringAndFlag = (const char *)-1i64;
  }
  v13 = (signed __int64)&v2->m_entries.m_data[v2->m_entries.m_size];
  v14 = &v2->m_entries.m_data[v2->m_entries.m_size++].m_allocatorName;
  hkStringPtr::operator=(v14, "Debug");
  v3->m_debugAllocator.vfptr->getMemoryStatistics(
    (hkMemoryAllocator *)&v3->m_debugAllocator.vfptr,
    (hkMemoryAllocator::MemoryStatistics *)(v13 + 8));
}

// File Line: 1086
// RVA: 0xC5E170
void __fastcall hkCheckingMemorySystem::printStatistics(hkCheckingMemorySystem *this, hkOstream *ostr)
{
  hkCheckingMemorySystem *v2; // r13
  hkOstream *v3; // r12
  int v4; // er15
  hkMemoryAllocatorVtbl *v5; // rax
  unsigned int v6; // er14
  unsigned int v7; // esi
  unsigned int v8; // edi
  signed int v9; // edx
  __int64 v10; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *v11; // rax
  __int64 v12; // r8
  __int64 v13; // r9
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v14; // rax
  signed int v15; // er11
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v16; // rsi
  unsigned int v17; // ebx
  __int64 v18; // r13
  unsigned int v19; // er12
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v20; // rcx
  __int64 v21; // r10
  __int64 v22; // rax
  __int64 v23; // rax
  unsigned int i; // ecx
  int v25; // edx
  __int64 v26; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v27; // rax
  hkMemoryAllocator *v28; // rcx
  int v29; // er14
  hkMemoryAllocatorVtbl *v30; // rax
  int v31; // edi
  hkMemoryAllocatorVtbl *v32; // rax
  int v33; // edi
  hkMemoryAllocatorVtbl *v34; // rax
  __int64 v35; // rsi
  unsigned int v36; // edi
  int v37; // esi
  int *v38; // rdx
  signed __int64 v39; // r8
  int v40; // eax
  int v41; // ecx
  int v42; // eax
  int v43; // ecx
  unsigned int v44; // er13
  signed int v45; // er14
  __int64 v46; // r12
  int v47; // edi
  int v48; // ST20_4
  _RTL_CRITICAL_SECTION *v49; // rbx
  unsigned int v50; // edi
  char *v51; // r14
  signed __int64 v52; // r12
  unsigned int v53; // esi
  __int64 v54; // r14
  hkCheckingMemorySystem::AllocatorForwarder *v55; // rsi
  const char *v56; // rax
  __int64 v57; // [rsp+20h] [rbp-E0h]
  __int64 *v58; // [rsp+28h] [rbp-D8h]
  __int64 v59; // [rsp+30h] [rbp-D0h]
  __int64 dst; // [rsp+38h] [rbp-C8h]
  __int64 v61; // [rsp+40h] [rbp-C0h]
  __int64 v62; // [rsp+48h] [rbp-B8h]
  __int64 v63; // [rsp+50h] [rbp-B0h]
  __int64 v64; // [rsp+58h] [rbp-A8h]
  __int64 v65; // [rsp+60h] [rbp-A0h]
  LPCRITICAL_SECTION lpCriticalSection; // [rsp+68h] [rbp-98h]
  __int64 v67; // [rsp+70h] [rbp-90h]
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *v68; // [rsp+78h] [rbp-88h]
  unsigned __int64 v69; // [rsp+80h] [rbp-80h]
  unsigned __int64 v70; // [rsp+88h] [rbp-78h]
  unsigned __int64 v71; // [rsp+90h] [rbp-70h]
  const void *v72; // [rsp+98h] [rbp-68h]
  __int64 v73; // [rsp+A0h] [rbp-60h]
  __int64 v74; // [rsp+A8h] [rbp-58h]
  __int64 v75; // [rsp+B0h] [rbp-50h]
  __int64 v76; // [rsp+B8h] [rbp-48h]
  __int64 v77; // [rsp+C0h] [rbp-40h]
  __int64 v78; // [rsp+C8h] [rbp-38h]
  __int64 v79; // [rsp+D0h] [rbp-30h]
  __int64 v80; // [rsp+D8h] [rbp-28h]
  __int64 v81; // [rsp+E0h] [rbp-20h]
  hkStringBuf v82; // [rsp+F0h] [rbp-10h]
  char buf[4]; // [rsp+190h] [rbp+90h]
  char v84; // [rsp+1B8h] [rbp+B8h]
  int Dst[56]; // [rsp+210h] [rbp+110h]
  hkCheckingMemorySystem *v86; // [rsp+300h] [rbp+200h]
  hkOstream *v87; // [rsp+308h] [rbp+208h]
  unsigned int v88; // [rsp+318h] [rbp+218h]

  v87 = ostr;
  v86 = this;
  v2 = this;
  v3 = ostr;
  lpCriticalSection = &this->m_section.m_section;
  EnterCriticalSection(&this->m_section.m_section);
  hkOstream::printf(v3, "hkCheckingMemorySystem memory overview:\n=======================================\n");
  memset(Dst, 0, 0xA0ui64);
  memset(&v82, 0, 0xA0ui64);
  memset(buf, 0, 0x80ui64);
  v4 = 0;
  v5 = v2->m_debugAllocator.vfptr;
  v67 = 0i64;
  v6 = 0;
  v7 = 0;
  v88 = 0;
  v8 = 0;
  v76 = -1i64;
  v77 = -1i64;
  v78 = -1i64;
  v79 = -1i64;
  v80 = -1i64;
  v81 = -1i64;
  v5->getMemoryStatistics((hkMemoryAllocator *)&v2->m_debugAllocator.vfptr, (hkMemoryAllocator::MemoryStatistics *)&v76);
  v9 = 0;
  v10 = 0i64;
  v59 = (unsigned int)v76;
  v11 = &v2->m_activePointers;
  v12 = v2->m_activePointers.m_hashMod;
  v68 = &v2->m_activePointers;
  v13 = v12;
  if ( (signed int)v12 >= 0 )
  {
    v14 = v11->m_elem;
    do
    {
      if ( v14->key != -1i64 )
        break;
      ++v10;
      ++v9;
      ++v14;
    }
    while ( v10 <= v12 );
    v11 = &v2->m_activePointers;
  }
  v15 = v9;
  if ( v9 <= (signed int)v12 )
  {
    v16 = v11->m_elem;
    v17 = 0;
    v18 = 0i64;
    v19 = 0;
    do
    {
      v20 = &v16[(signed __int64)v15];
      v21 = *(_QWORD *)&v20->val.m_flags.m_storage;
      v12 = *(_QWORD *)&v20->val.m_size;
      v69 = v20->val.m_threadId;
      v70 = v20->val.m_allocOrder;
      v71 = v20->val.m_time;
      v72 = v20->val.m_tagData;
      v75 = *(_QWORD *)&v20->val.m_bookmarkIndex;
      if ( v21 & 1 )
      {
        v6 += v12;
        if ( (signed int)v12 > 640 )
        {
          v23 = 0i64;
          for ( i = v12; i; i >>= 1 )
            ++v23;
          ++*(_DWORD *)&buf[4 * v23];
          v18 += (signed int)v12;
        }
        else if ( (_DWORD)v12 )
        {
          v22 = ((signed int)v12 - 1) / 16;
          ++Dst[v22];
          *((_DWORD *)&v82.m_string.m_data + v22) += v12;
        }
        else
        {
          ++Dst[0];
        }
      }
      if ( v21 & 2 )
        v17 += v12;
      if ( v21 & 4 )
        v19 += v12;
      if ( v21 & 8 )
        v8 += v12;
      v25 = v15 + 1;
      v26 = v15 + 1;
      if ( v26 <= v13 )
      {
        v27 = &v16[(signed __int64)v25];
        do
        {
          if ( v27->key != -1i64 )
            break;
          ++v26;
          ++v25;
          ++v27;
        }
        while ( v26 <= v13 );
      }
      v15 = v25;
    }
    while ( v25 <= v68->m_hashMod );
    v67 = v18;
    v2 = v86;
    v88 = v19;
    v3 = v87;
    HIDWORD(v59) = v6;
    v7 = v17;
  }
  v28 = v2->m_rawAllocator;
  v69 = -1i64;
  v70 = -1i64;
  v71 = -1i64;
  v72 = (const void *)-1i64;
  v73 = -1i64;
  v74 = -1i64;
  ((void (__fastcall *)(hkMemoryAllocator *, unsigned __int64 *, __int64, __int64))v28->vfptr->getMemoryStatistics)(
    v28,
    &v69,
    v12,
    v13);
  hkOstream::printf(v3, "\n    Allocation totals:\n\n");
  hkOstream::printf(v3, "%20i allocated by heap\n", v6);
  hkOstream::printf(v3, "%20i allocated by debug\n", (unsigned int)v59);
  hkOstream::printf(v3, "%20i allocated by stack\n", v7);
  hkOstream::printf(v3, "%20i allocated by temp\n", v88);
  hkOstream::printf(v3, "%20i allocated by solver\n", v8);
  v29 = HIDWORD(v59) + v59 + v7 + v8 + v88;
  if ( v2->m_checkFlags.m_storage & 0x10 )
  {
    dst = -1i64;
    v30 = v2->m_delayedFreeAllocator.vfptr;
    v61 = -1i64;
    v62 = -1i64;
    v63 = -1i64;
    v64 = -1i64;
    v65 = -1i64;
    v30->getMemoryStatistics(
      (hkMemoryAllocator *)&v2->m_delayedFreeAllocator.vfptr,
      (hkMemoryAllocator::MemoryStatistics *)&dst);
    v31 = dst - v61;
    hkOstream::printf(v3, "%20i in delayed frees\n", (unsigned int)(dst - v61));
    v29 += v31;
  }
  if ( v2->m_checkFlags.m_storage & 8 )
  {
    v32 = v2->m_paddedAllocator.vfptr;
    dst = -1i64;
    v61 = -1i64;
    v62 = -1i64;
    v63 = -1i64;
    v64 = -1i64;
    v65 = -1i64;
    v32->getMemoryStatistics(
      (hkMemoryAllocator *)&v2->m_paddedAllocator.vfptr,
      (hkMemoryAllocator::MemoryStatistics *)&dst);
    v33 = dst - v61;
    hkOstream::printf(v3, "%20i in allocation padding\n", (unsigned int)(dst - v61));
    v29 += v33;
  }
  if ( v2->m_checkFlags.m_storage & 4 )
  {
    dst = -1i64;
    v34 = v2->m_callTreeAllocator.vfptr;
    v61 = -1i64;
    v62 = -1i64;
    v63 = -1i64;
    v64 = -1i64;
    v65 = -1i64;
    v34->getMemoryStatistics(
      (hkMemoryAllocator *)&v2->m_callTreeAllocator.vfptr,
      (hkMemoryAllocator::MemoryStatistics *)&dst);
    hkOstream::printf(v3, "%20i in callstacks\n", dst);
    v29 += dst;
  }
  v35 = (unsigned int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::getMemSize(&v2->m_activePointers);
  hkOstream::printf(v3, "%20i in active pointer map\n", v35);
  v36 = 8 * (5 * v2->m_allocators.m_size + (v2->m_allocators.m_capacityAndFlags & 0x3FFFFFFF));
  hkOstream::printf(v3, "%20i in allocator forwarders\n", v36);
  hkOstream::printf(v3, "%20s\n", "-------");
  hkOstream::printf(v3, "%20i computed total\n", v29 + v36 + (unsigned int)v35);
  hkOstream::printf(v3, "%20i reported total\n", (unsigned int)v69);
  hkOstream::printf(v3, "\n    Heap small block (<=%i) summary:\n\n", 640i64);
  v37 = 0;
  v38 = (int *)((char *)&v82.m_string.m_data + 4);
  v39 = 8i64;
  do
  {
    v40 = *(v38 - 1);
    v41 = *v38;
    v38 += 5;
    if ( v37 > v40 )
      v40 = v37;
    v37 = *(v38 - 2);
    if ( v40 > v41 )
      v41 = v40;
    v42 = *(v38 - 4);
    if ( v41 > v42 )
      v42 = v41;
    v43 = *(v38 - 3);
    if ( v42 > v43 )
      v43 = v42;
    if ( v43 > v37 )
      v37 = v43;
    --v39;
  }
  while ( v39 );
  v44 = 0;
  v45 = 16;
  v46 = 0i64;
  do
  {
    memset(&dst, 0, 0x29ui64);
    v47 = *(_DWORD *)((char *)&v82.m_string.m_data + v46 * 4);
    hkString::memSet(&dst, 62, 40 * v47 / v37);
    v58 = &dst;
    v48 = Dst[v46] * v45 / 1024;
    hkOstream::printf(v87, "%20i * %6i = %4ik : %s\n", (unsigned int)v45);
    v45 += 16;
    v44 += v47;
    ++v46;
  }
  while ( v45 < 656 );
  hkOstream::printf(v87, "%20s\n", "-------");
  hkOstream::printf(v87, "%20i bytes total\n", v44);
  hkOstream::printf(v87, "\n    Heap large block (>%i) summary:\n\n", 640i64);
  v49 = lpCriticalSection;
  v50 = 1024;
  v51 = &v84;
  v52 = 22i64;
  do
  {
    v53 = *(_DWORD *)v51;
    if ( *(_DWORD *)v51 )
    {
      v82.m_string.m_capacityAndFlags = -2147483520;
      v82.m_string.m_size = 1;
      v82.m_string.m_data = v82.m_string.m_storage;
      v82.m_string.m_storage[0] = 0;
      hkStringBuf::printf(&v82, "<=%i", v50);
      LODWORD(v57) = (signed int)(v50 * v53) / 1024;
      hkOstream::printf(v87, "%20s * %6i = %4ik\n", v82.m_string.m_data, v53, v57);
      v82.m_string.m_size = 0;
      if ( v82.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v82.m_string.m_data,
          v82.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    }
    v50 = __ROL4__(v50, 1);
    v51 += 4;
    --v52;
  }
  while ( v52 );
  hkOstream::printf(v87, "%20s\n", "-------");
  hkOstream::printf(v87, "%20i bytes total\n", v67);
  hkOstream::printf(v87, "\n    Threads summary:\n\n");
  if ( v86->m_allocators.m_size > 0 )
  {
    v54 = 0i64;
    do
    {
      v55 = v86->m_allocators.m_data[v54];
      if ( v55->m_context.flags.m_storage & 0xC )
      {
        v56 = flagsToString(buf, v55->m_context.flags);
        LODWORD(v58) = v55->m_context.peakInUse;
        hkOstream::printf(
          v87,
          "%10s Thread %I64u, %6s, peak %i\n",
          &customWorldMapCaption,
          v55->m_context.threadId,
          v56,
          v58);
      }
      ++v4;
      ++v54;
    }
    while ( v4 < v86->m_allocators.m_size );
    v49 = lpCriticalSection;
  }
  LeaveCriticalSection(v49);
}

// File Line: 1260
// RVA: 0xC5EAB0
void __fastcall hkCheckingMemorySystem::getHeapStatistics(hkCheckingMemorySystem *this, hkMemoryAllocator::MemoryStatistics *stats)
{
  this->m_baseAllocator->vfptr->getMemoryStatistics(this->m_baseAllocator, stats);
}

// File Line: 1265
// RVA: 0xC5E930
void __fastcall hkCheckingMemorySystem::advanceFrame(hkCheckingMemorySystem *this)
{
  hkCheckingMemorySystem *v1; // rsi
  __int64 v2; // r9
  signed int v3; // er8
  __int64 v4; // rdx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v5; // rax
  signed int v6; // edi
  signed __int64 v7; // r8
  __int64 v8; // rcx
  unsigned __int64 v9; // rax
  __int64 v10; // r9
  int v11; // edx
  __int64 v12; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v13; // rax
  hkCheckingMemorySystem::AllocInfo info; // [rsp+20h] [rbp-48h]

  v1 = this;
  EnterCriticalSection(&this->m_section.m_section);
  v2 = v1->m_activePointers.m_hashMod;
  v3 = 0;
  v4 = 0i64;
  if ( (signed int)v2 >= 0 )
  {
    v5 = v1->m_activePointers.m_elem;
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
  if ( v3 <= (signed int)v2 )
  {
    do
    {
      v7 = (signed __int64)&v1->m_activePointers.m_elem[(signed __int64)v6];
      v8 = *(_QWORD *)(v7 + 40);
      info.m_threadId = *(_QWORD *)(v7 + 8);
      v9 = *(_QWORD *)(v7 + 16);
      *(_QWORD *)&info.m_flags.m_storage = v8;
      info.m_allocOrder = v9;
      info.m_time = *(_QWORD *)(v7 + 24);
      info.m_tagData = *(const void **)(v7 + 32);
      *(_QWORD *)&info.m_size = *(_QWORD *)(v7 + 48);
      *(_QWORD *)&info.m_bookmarkIndex = *(_QWORD *)(v7 + 56);
      if ( v8 & 4 )
        hkCheckingMemorySystem::danger(v1, "A temp allocation lived past a frame advance", *(const void **)v7, &info);
      v10 = v1->m_activePointers.m_hashMod;
      v11 = v6 + 1;
      v12 = v6 + 1;
      if ( v12 <= v10 )
      {
        v13 = &v1->m_activePointers.m_elem[(signed __int64)v11];
        do
        {
          if ( v13->key != -1i64 )
            break;
          ++v12;
          ++v11;
          ++v13;
        }
        while ( v12 <= v10 );
      }
      v6 = v11;
    }
    while ( v11 <= (signed int)v10 );
  }
  LeaveCriticalSection(&v1->m_section.m_section);
}

// File Line: 1285
// RVA: 0xC5EA60
void __fastcall hkCheckingMemorySystem::garbageCollectShared(hkCheckingMemorySystem *this)
{
  hkCheckingMemorySystem *v1; // rbx

  v1 = this;
  EnterCriticalSection(&this->m_section.m_section);
  ((void (*)(void))v1->m_delayedFreeAllocator.vfptr[1].__vecDelDtor)();
  LeaveCriticalSection(&v1->m_section.m_section);
}

// File Line: 1295
// RVA: 0xC5DCB0
__int64 __fastcall hkCheckingMemorySystem::isCheckCallstackEnabled(hkCheckingMemorySystem *this)
{
  return this->m_checkFlags.m_storage & 4;
}

// File Line: 1300
// RVA: 0xC5DCC0
void __fastcall hkCheckingMemorySystem::setCheckCallstackEnabled(hkCheckingMemorySystem *this, bool enabled)
{
  this->m_checkFlags.m_storage &= 0xFFFFFFFB;
  this->m_checkFlags.m_storage |= enabled != 0 ? 4 : 0;
}

// File Line: 1305
// RVA: 0xC5DC20
void __fastcall hkCheckingMemorySystem::addBookmark(hkCheckingMemorySystem *this, const char *bookmarkName)
{
  signed int *v2; // rbx
  const char *v3; // rsi
  hkCheckingMemorySystem *v4; // rdi
  _QWORD *v5; // rax

  v2 = (signed int *)&this->m_bookmarks;
  v3 = bookmarkName;
  v4 = this;
  if ( this->m_bookmarks.m_size == (this->m_bookmarks.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_rawAllocator, v2, 16);
  v5 = (_QWORD *)(*(_QWORD *)v2 + 16i64 * v2[2]);
  if ( v5 )
  {
    *v5 = 0i64;
    v5[1] = 0i64;
  }
  hkCheckingMemorySystem::Bookmark::set(
    (hkCheckingMemorySystem::Bookmark *)(*(_QWORD *)v2 + 16i64 * (++v2[2] - 1)),
    v4->m_rawAllocator,
    v3);
}

// File Line: 1311
// RVA: 0xC5FB90
__int64 __fastcall hkCheckingMemorySystem::findPrecedingBookmark(hkCheckingMemorySystem *this, unsigned __int64 timeStamp)
{
  __int64 v2; // r11
  int v3; // er9
  __int64 v4; // r8
  unsigned __int64 *v5; // rax

  v2 = this->m_bookmarks.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (signed int)v2 <= 0 )
    return (unsigned int)v2;
  v5 = &this->m_bookmarks.m_data->m_time;
  while ( *v5 <= timeStamp )
  {
    ++v4;
    ++v3;
    v5 += 2;
    if ( v4 >= v2 )
      return (unsigned int)v2;
  }
  return (unsigned int)(v3 - 1);
}

// File Line: 1325
// RVA: 0xC5D750
void __fastcall hkCheckingMemorySystem::Bookmark::set(hkCheckingMemorySystem::Bookmark *this, hkMemoryAllocator *alloc, const char *name)
{
  hkCheckingMemorySystem::Bookmark *v3; // rdi
  const char *v4; // rsi
  hkMemoryAllocator *v5; // rbx
  unsigned int v6; // ebp
  char *v7; // rax

  v3 = this;
  v4 = name;
  v5 = alloc;
  v6 = (unsigned __int64)hkString::strLen(name) + 1;
  v7 = (char *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&v5->vfptr->__vecDelDtor + 1))(v5, v6);
  v3->m_name = v7;
  if ( v7 )
    hkString::memCpy(v7, v4, v6);
  v3->m_time = hkStopwatch::getTickCounter();
}

// File Line: 1337
// RVA: 0xC5D7C0
void __fastcall hkCheckingMemorySystem::Bookmark::clear(hkCheckingMemorySystem::Bookmark *this, hkMemoryAllocator *alloc)
{
  hkCheckingMemorySystem::Bookmark *v2; // rbx
  char *v3; // rcx
  hkMemoryAllocator *v4; // rdi
  int v5; // eax

  v2 = this;
  v3 = this->m_name;
  v4 = alloc;
  if ( v3 )
  {
    v5 = hkString::strLen(v3);
    v4->vfptr->blockFree(v4, v2->m_name, v5 + 1);
    v2->m_name = 0i64;
  }
}

// File Line: 1348
// RVA: 0xC5D720
unsigned __int64 __fastcall hkCheckingMemorySystem::AllocInfo::getKey(hkCheckingMemorySystem::AllocInfo *this)
{
  unsigned int v1; // edx
  BOOL v2; // er8

  v1 = this->m_traceId;
  v2 = v1 == -1;
  if ( v1 == -1 )
    v1 = this->m_bookmarkIndex;
  return v1 | ((unsigned __int64)(unsigned int)v2 << 32);
}

