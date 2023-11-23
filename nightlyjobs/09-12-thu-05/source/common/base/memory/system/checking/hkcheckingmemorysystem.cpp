// File Line: 33
// RVA: 0xC5C650
void *__fastcall hkCheckingMemorySystem::AllocatorForwarder::blockAlloc(
        hkCheckingMemorySystem::AllocatorForwarder *this,
        int numBytes)
{
  return hkCheckingMemorySystem::checkedAlloc(this->m_parent, 0, &this->m_context, numBytes);
}

// File Line: 38
// RVA: 0xC5C670
void __fastcall hkCheckingMemorySystem::AllocatorForwarder::blockFree(
        hkCheckingMemorySystem::AllocatorForwarder *this,
        void *p,
        int numBytes)
{
  if ( p )
    hkCheckingMemorySystem::checkedFree(this->m_parent, 0, &this->m_context, p, numBytes);
}

// File Line: 50
// RVA: 0xC5C6A0
void *__fastcall hkCheckingMemorySystem::AllocatorForwarder::bufAlloc(
        hkCheckingMemorySystem::AllocatorForwarder *this,
        int *reqNumInOut)
{
  return hkCheckingMemorySystem::checkedAlloc(this->m_parent, 1u, &this->m_context, *reqNumInOut);
}

// File Line: 55
// RVA: 0xC5C6C0
void __fastcall hkCheckingMemorySystem::AllocatorForwarder::bufFree(
        hkCheckingMemorySystem::AllocatorForwarder *this,
        void *p,
        int num)
{
  hkCheckingMemorySystem::checkedFree(this->m_parent, 1u, &this->m_context, p, num);
}

// File Line: 60
// RVA: 0xC5C6F0
void *__fastcall hkCheckingMemorySystem::AllocatorForwarder::bufRealloc(
        hkCheckingMemorySystem::AllocatorForwarder *this,
        void *pold,
        int oldNum,
        int *reqNumInOut)
{
  void *v8; // rax
  int v9; // r8d
  void *v10; // rdi

  v8 = hkCheckingMemorySystem::checkedAlloc(this->m_parent, 1u, &this->m_context, *reqNumInOut);
  v9 = oldNum;
  if ( *reqNumInOut < oldNum )
    v9 = *reqNumInOut;
  v10 = v8;
  hkMemUtil::memCpy(v8, pold, v9);
  hkCheckingMemorySystem::checkedFree(this->m_parent, 1u, &this->m_context, pold, oldNum);
  return v10;
}

// File Line: 68
// RVA: 0xC5C780
void __fastcall hkCheckingMemorySystem::AllocatorForwarder::getMemoryStatistics(
        hkCheckingMemorySystem::AllocatorForwarder *this,
        hkMemoryAllocator::MemoryStatistics *u)
{
  __int64 m_currentInUse; // r8

  u->m_available = 0i64;
  m_currentInUse = this->m_parent->m_currentInUse;
  u->m_inUse = m_currentInUse;
  u->m_allocated = m_currentInUse;
  u->m_peakInUse = this->m_parent->m_peakInUse;
}

// File Line: 76
// RVA: 0xC5C7B0
__int64 __fastcall hkCheckingMemorySystem::AllocatorForwarder::getAllocatedSize(
        hkCheckingMemorySystem::AllocatorForwarder *this,
        const void *obj,
        unsigned int numBytes)
{
  return numBytes;
}

// File Line: 81
// RVA: 0xC5C7C0
void __fastcall hkCheckingMemorySystem::AllocatorForwarder::resetPeakMemoryStatistics(
        hkCheckingMemorySystem::AllocatorForwarder *this)
{
  this->m_parent->m_peakInUse = this->m_parent->m_currentInUse;
}

// File Line: 97
// RVA: 0xC5C7E0
void __fastcall hkCheckingMemorySystem::hkCheckingMemorySystem(hkCheckingMemorySystem *this)
{
  hkStackTracer *p_m_stackTracer; // rcx
  unsigned __int64 TickCounter; // rax

  p_m_stackTracer = &this->m_stackTracer;
  p_m_stackTracer[-1].vfptr = (hkStackTracerVtbl *)&hkCheckingMemorySystem::`vftable;
  hkStackTracer::hkStackTracer(p_m_stackTracer);
  this->m_callTree.m_nodes.m_data = 0i64;
  this->m_callTree.m_nodes.m_size = 0;
  this->m_callTree.m_nodes.m_capacityAndFlags = 0x80000000;
  this->m_callTree.m_allocator = 0i64;
  *(_QWORD *)&this->m_callTree.m_rootNode = -1i64;
  hkCriticalSection::hkCriticalSection(&this->m_section, 0);
  this->m_baseAllocator = 0i64;
  hkPaddedAllocator::hkPaddedAllocator(&this->m_paddedAllocator);
  hkDelayedFreeAllocator::hkDelayedFreeAllocator(&this->m_delayedFreeAllocator);
  hkRecallAllocator::hkRecallAllocator(&this->m_debugAllocator, 0i64);
  hkStatsAllocator::hkStatsAllocator(&this->m_callTreeAllocator, 0i64);
  this->m_bookmarks.m_data = 0i64;
  this->m_bookmarks.m_size = 0;
  this->m_bookmarks.m_capacityAndFlags = 0x80000000;
  this->m_allocators.m_data = 0i64;
  this->m_allocators.m_size = 0;
  this->m_allocators.m_capacityAndFlags = 0x80000000;
  this->m_checkFlags.m_storage = 30;
  this->m_activePointers.m_elem = 0i64;
  this->m_activePointers.m_numElems = 0;
  this->m_activePointers.m_hashMod = -1;
  this->m_outputFunc = 0i64;
  this->m_outputFuncArg = 0i64;
  hkMemorySystem::FrameInfo::FrameInfo(&this->m_frameInfo, 0);
  hkMemoryRouter::hkMemoryRouter(&this->m_mainRouter);
  TickCounter = hkStopwatch::getTickCounter();
  this->m_sumAllocatedStackMemory = 0i64;
  this->m_timeOfConstruction = TickCounter;
  this->m_allocOrder = 0i64;
}

// File Line: 105
// RVA: 0xC5C910
void __fastcall hkCheckingMemorySystem::init(
        hkCheckingMemorySystem *this,
        hkMemoryAllocator *raw,
        void (__fastcall *output)(const char *, void *),
        void *outputUserData,
        int checks)
{
  hkMemoryAllocator *p_m_delayedFreeAllocator; // rsi

  this->m_outputFunc = output;
  this->m_outputFuncArg = outputUserData;
  this->m_rawAllocator = raw;
  this->m_checkFlags.m_storage = checks;
  p_m_delayedFreeAllocator = raw;
  if ( (checks & 0x10) != 0 )
  {
    p_m_delayedFreeAllocator = &this->m_delayedFreeAllocator;
    hkDelayedFreeAllocator::init(&this->m_delayedFreeAllocator, raw, 0i64);
  }
  if ( (this->m_checkFlags.m_storage & 8) != 0 )
  {
    hkPaddedAllocator::init(&this->m_paddedAllocator, p_m_delayedFreeAllocator, 0i64);
    p_m_delayedFreeAllocator = &this->m_paddedAllocator;
  }
  if ( (this->m_checkFlags.m_storage & 4) != 0 )
  {
    hkStatsAllocator::init(&this->m_callTreeAllocator, raw);
    this->m_callTree.m_allocator = &this->m_callTreeAllocator;
  }
  this->m_baseAllocator = p_m_delayedFreeAllocator;
  hkRecallAllocator::init(&this->m_debugAllocator, raw);
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
  char *v3; // rbx
  char **v4; // rsi
  __int64 v5; // rbp
  int v6; // eax
  int v8; // [rsp+20h] [rbp-48h]
  const char *v9; // [rsp+28h] [rbp-40h] BYREF
  int v10; // [rsp+30h] [rbp-38h]
  const char *v11; // [rsp+38h] [rbp-30h]
  int v12; // [rsp+40h] [rbp-28h]
  const char *v13; // [rsp+48h] [rbp-20h]
  unsigned int m_storage; // [rsp+78h] [rbp+10h]

  m_storage = flags.m_storage;
  v8 = 1;
  v9 = "Heap";
  v10 = 4;
  v11 = "Temp";
  v12 = 8;
  *buf = 0;
  v3 = buf;
  v4 = (char **)&v9;
  v13 = "Solver";
  v5 = 3i64;
  do
  {
    if ( (flags.m_storage & *(_DWORD *)(v4 - 1)) != 0 )
    {
      if ( v3 != buf )
        *v3++ = 124;
      hkString::strCpy(v3, *v4);
      v6 = hkString::strLen(*v4);
      flags.m_storage = m_storage;
      v3 += v6;
    }
    v4 += 2;
    --v5;
  }
  while ( v5 );
  return buf;
}

// File Line: 168
// RVA: 0xC5FBE0
void __fastcall hkCheckingMemorySystem::danger(
        hkCheckingMemorySystem *this,
        const char *message,
        const void *ptr,
        hkCheckingMemorySystem::AllocInfo *info)
{
  double v8; // xmm6_8
  const char *v9; // rax
  int v10; // eax
  int context; // [rsp+20h] [rbp-2B8h]
  char v12[256]; // [rsp+40h] [rbp-298h] BYREF
  char buf[128]; // [rsp+140h] [rbp-198h] BYREF
  unsigned __int64 addrs[34]; // [rsp+1C0h] [rbp-118h] BYREF

  EnterCriticalSection(&this->m_section.m_section);
  v8 = hkStopwatch::secondsFromTicks(info->m_time - this->m_timeOfConstruction);
  v9 = flagsToString(buf, info->m_flags);
  context = info->m_size;
  hkString::snprintf(
    v12,
    256,
    "\nAddress=0x%p size=%i flags=%s thread=%I64u time=%.2f\n",
    ptr,
    context,
    v9,
    info->m_threadId,
    v8);
  this->m_outputFunc(message, this->m_outputFuncArg);
  this->m_outputFunc(v12, this->m_outputFuncArg);
  v10 = hkStackTracer::CallTree::getCallStack(&this->m_callTree, info->m_traceId, addrs, 32);
  hkStackTracer::dumpStackTrace(&this->m_stackTracer, addrs, v10, this->m_outputFunc, this->m_outputFuncArg);
  this->m_outputFunc("-------------------------------------------------------------------\n\n", this->m_outputFuncArg);
  LeaveCriticalSection(&this->m_section.m_section);
}

// File Line: 221
// RVA: 0xC5EAD0
void __fastcall hkCheckingMemorySystem::leakReportByTime(hkCheckingMemorySystem *this)
{
  hkMemoryAllocator *m_rawAllocator; // rdx
  int m_numElems; // edi
  int v4; // edi
  __int64 m_hashMod; // r8
  int v6; // edx
  __int64 v7; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v9; // edi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v10; // rax
  __int64 v11; // rsi
  hkCheckingMemorySystem::AllocInfo *v12; // r12
  unsigned __int64 v13; // r13
  hkCheckingMemorySystem::AllocInfo *v14; // r15
  hkCheckingMemorySystem::AllocInfo *v15; // r14
  __int64 v16; // rcx
  bool v17; // zf
  __int64 v18; // rcx
  unsigned __int64 Key; // rax
  unsigned int inserted; // eax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v21; // rdx
  __int64 val_low; // rax
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v23; // rax
  hkCheckingMemorySystem::AllocInfo *v24; // rdx
  hkCheckingMemorySystem::AllocInfo *v25; // r8
  hkCheckingMemorySystem::AllocInfo *v26; // r9
  hkCheckingMemorySystem::AllocInfo *v27; // r10
  hkCheckingMemorySystem::AllocInfo *v28; // r11
  hkCheckingMemorySystem::AllocInfo *v29; // r14
  hkCheckingMemorySystem::AllocInfo *v30; // rsi
  int v31; // ecx
  hkCheckingMemorySystem::AllocInfo **v32; // rax
  __int64 v33; // rdx
  hkArrayBase<hkCheckingMemorySystem::AllocInfo> *m_allocs; // rax
  unsigned __int64 v35; // rcx
  const void *v36; // r8
  __int64 v37; // r8
  int v38; // edx
  __int64 v39; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v40; // rax
  int v41; // edi
  int v42; // ecx
  __int64 v43; // rdx
  int v44; // r15d
  __int64 v45; // r12
  __int64 v46; // r13
  __int64 v47; // rcx
  int v48; // r8d
  bool v49; // al
  bool v50; // dl
  char *v51; // r14
  char *m_name; // rdi
  allocTimeComparison cmpLess; // [rsp+30h] [rbp-D0h] BYREF
  int v54; // [rsp+38h] [rbp-C8h]
  int v55; // [rsp+3Ch] [rbp-C4h]
  _DWORD *v56; // [rsp+40h] [rbp-C0h] BYREF
  int v57; // [rsp+48h] [rbp-B8h]
  int v58; // [rsp+4Ch] [rbp-B4h]
  _QWORD *array; // [rsp+50h] [rbp-B0h] BYREF
  int v60; // [rsp+58h] [rbp-A8h]
  int v61; // [rsp+5Ch] [rbp-A4h]
  int *pArr; // [rsp+60h] [rbp-A0h] BYREF
  int v63; // [rsp+68h] [rbp-98h]
  int v64; // [rsp+6Ch] [rbp-94h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v65; // [rsp+70h] [rbp-90h] BYREF
  hkCheckingMemorySystem::AllocInfo v66; // [rsp+80h] [rbp-80h] BYREF
  hkStringBuf v67; // [rsp+C0h] [rbp-40h] BYREF
  const void *result; // [rsp+190h] [rbp+90h] BYREF
  hkCheckingMemorySystem::AllocInfo *v69; // [rsp+198h] [rbp+98h]
  __int64 v70; // [rsp+1A0h] [rbp+A0h]

  m_rawAllocator = this->m_rawAllocator;
  `anonymous namespace::SummaryAllocator::s_allocator = m_rawAllocator;
  m_numElems = this->m_activePointers.m_numElems;
  array = 0i64;
  v60 = 0;
  v61 = 0x80000000;
  v4 = m_numElems & 0x7FFFFFFF;
  if ( v4 )
  {
    hkArrayUtil::_reserve((hkResult *)&result, m_rawAllocator, (const void **)&array, v4, 8);
    m_rawAllocator = `anonymous namespace::SummaryAllocator::s_allocator;
  }
  cmpLess.m_allocs = 0i64;
  v54 = 0;
  v55 = 0x80000000;
  if ( v4 > 0 )
  {
    hkArrayUtil::_reserve((hkResult *)&result, m_rawAllocator, (const void **)&cmpLess.m_allocs, v4, 56);
    m_rawAllocator = `anonymous namespace::SummaryAllocator::s_allocator;
  }
  v56 = 0i64;
  v57 = 0;
  v58 = 0x80000000;
  if ( v4 > 0 )
  {
    hkArrayUtil::_reserve((hkResult *)&result, m_rawAllocator, (const void **)&v56, v4, 4);
    m_rawAllocator = `anonymous namespace::SummaryAllocator::s_allocator;
  }
  v65.m_elem = 0i64;
  v65.m_numElems = 0;
  v65.m_hashMod = -1;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::reserve(&v65, m_rawAllocator, v4);
  m_hashMod = this->m_activePointers.m_hashMod;
  v6 = 0;
  v7 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = this->m_activePointers.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v7;
      ++v6;
      ++m_elem;
    }
    while ( v7 <= m_hashMod );
  }
  v9 = v6;
  if ( v6 <= this->m_activePointers.m_hashMod )
  {
    do
    {
      v10 = this->m_activePointers.m_elem;
      v11 = (__int64)v9 << 6;
      v12 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v10->val.m_threadId + v11);
      v13 = *(unsigned __int64 *)((char *)&v10->val.m_allocOrder + v11);
      v14 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v10->val.m_time + v11);
      v15 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v10->val.m_bookmarkIndex + v11);
      result = *(const void **)((char *)&v10->val.m_tagData + v11);
      v66.m_tagData = result;
      v16 = *(_QWORD *)((char *)&v10->val.m_flags.m_storage + v11);
      v66.m_threadId = (unsigned __int64)v12;
      *(_QWORD *)&v66.m_flags.m_storage = v16;
      v17 = HIDWORD(v16) == -1;
      v69 = (hkCheckingMemorySystem::AllocInfo *)v16;
      v18 = *(_QWORD *)((char *)&v10->val.m_size + v11);
      v66.m_allocOrder = v13;
      v66.m_time = (unsigned __int64)v14;
      v70 = v18;
      *(_QWORD *)&v66.m_size = v18;
      *(_QWORD *)&v66.m_bookmarkIndex = v15;
      if ( !v17 || (_DWORD)v15 != -1 )
      {
        Key = hkCheckingMemorySystem::AllocInfo::getKey(&v66);
        inserted = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
                                   &v65,
                                   `anonymous namespace::SummaryAllocator::s_allocator,
                                   Key,
                                   0xFFFFFFFFFFFFFFFFui64);
        v21 = &v65.m_elem[inserted];
        val_low = SLODWORD(v21->val);
        if ( (_DWORD)val_low != -1 )
        {
          v33 = SLODWORD(v21->val);
          ++v56[val_low];
          m_allocs = cmpLess.m_allocs;
          v35 = 7 * v33;
          if ( v14 < (&cmpLess.m_allocs[1].m_data)[7 * v33] )
          {
            v36 = result;
            (&cmpLess.m_allocs->m_data)[v35] = v12;
            *(_QWORD *)((char *)&m_allocs->m_size + v35 * 8) = v13;
            (&m_allocs[1].m_data)[v35] = v14;
            *(_QWORD *)((char *)&m_allocs[1].m_size + v35 * 8) = v36;
            (&m_allocs[2].m_data)[v35] = v69;
            *(_QWORD *)((char *)&m_allocs[2].m_size + v35 * 8) = v70;
            (&m_allocs[3].m_data)[v35] = v15;
            array[v33] = *(unsigned __int64 *)((char *)&this->m_activePointers.m_elem->key + v11);
          }
          goto LABEL_21;
        }
        v21->val = v60;
        v10 = this->m_activePointers.m_elem;
      }
      array[v60] = *(unsigned __int64 *)((char *)&v10->key + v11);
      v23 = this->m_activePointers.m_elem;
      ++v60;
      v24 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v23->val.m_threadId + v11);
      v25 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v23->val.m_allocOrder + v11);
      v26 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v23->val.m_time + v11);
      v27 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v23->val.m_tagData + v11);
      v28 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v23->val.m_flags.m_storage + v11);
      v29 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v23->val.m_size + v11);
      v30 = *(hkCheckingMemorySystem::AllocInfo **)((char *)&v23->val.m_bookmarkIndex + v11);
      v31 = v54;
      v32 = &(&cmpLess.m_allocs->m_data)[7 * v54];
      if ( v32 )
      {
        *v32 = v24;
        v32[1] = v25;
        v32[2] = v26;
        v32[3] = v27;
        v32[4] = v28;
        v32[5] = v29;
        v32[6] = v30;
        v31 = v54;
      }
      v54 = v31 + 1;
      v56[v57++] = 1;
LABEL_21:
      v37 = this->m_activePointers.m_hashMod;
      v38 = v9 + 1;
      v39 = v9 + 1;
      if ( v39 <= v37 )
      {
        v40 = &this->m_activePointers.m_elem[(__int64)v38];
        do
        {
          if ( v40->key != -1i64 )
            break;
          ++v39;
          ++v38;
          ++v40;
        }
        while ( v39 <= v37 );
      }
      v9 = v38;
    }
    while ( v38 <= this->m_activePointers.m_hashMod );
  }
  v41 = v54;
  pArr = 0i64;
  v63 = 0;
  v64 = 0x80000000;
  if ( v54 > 0 )
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      `anonymous namespace::SummaryAllocator::s_allocator,
      (const void **)&pArr,
      v54,
      4);
  v63 = v41;
  v42 = 0;
  if ( v41 > 0 )
  {
    v43 = 0i64;
    do
    {
      pArr[v43++] = v42;
      v41 = v63;
      ++v42;
    }
    while ( v42 < v63 );
  }
  if ( v41 > 1 )
  {
    hkAlgorithm::quickSortRecursive<int,`anonymous namespace::allocTimeComparison>(
      pArr,
      0,
      v41 - 1,
      (allocTimeComparison)&cmpLess);
    v41 = v63;
  }
  v44 = 0;
  if ( v41 > 0 )
  {
    v45 = 0i64;
    while ( 1 )
    {
      v46 = pArr[v45];
      v47 = SLODWORD((&cmpLess.m_allocs[3].m_data)[7 * v46]);
      v48 = v47 + 1;
      v49 = (int)v47 >= 0 && (int)v47 < this->m_bookmarks.m_size;
      v50 = v48 >= 0 && v48 < this->m_bookmarks.m_size;
      if ( v49 )
        break;
      if ( v50 )
      {
        v51 = "(unknown)";
LABEL_47:
        if ( v50 )
          m_name = this->m_bookmarks.m_data[v48].m_name;
        else
          m_name = "(unknown)";
        this->m_outputFunc("Between bookmarks\n[", this->m_outputFuncArg);
        this->m_outputFunc(v51, this->m_outputFuncArg);
        this->m_outputFunc("] and \n[", this->m_outputFuncArg);
        this->m_outputFunc(m_name, this->m_outputFuncArg);
        this->m_outputFunc("]\n", this->m_outputFuncArg);
      }
      v67.m_string.m_capacityAndFlags = -2147483520;
      v67.m_string.m_size = 1;
      v67.m_string.m_data = v67.m_string.m_storage;
      v67.m_string.m_storage[0] = 0;
      hkStringBuf::printf(&v67, "Memory Leaked (%i times with this stack):\n", (unsigned int)v56[v46]);
      hkCheckingMemorySystem::danger(
        this,
        v67.m_string.m_data,
        (const void *)array[v46],
        (hkCheckingMemorySystem::AllocInfo *)cmpLess.m_allocs + v46);
      v67.m_string.m_size = 0;
      if ( v67.m_string.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          v67.m_string.m_data,
          v67.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      ++v44;
      ++v45;
      if ( v44 >= v63 )
        goto LABEL_54;
    }
    v51 = this->m_bookmarks.m_data[v47].m_name;
    goto LABEL_47;
  }
LABEL_54:
  v63 = 0;
  if ( v64 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      pArr,
      4 * v64);
  pArr = 0i64;
  v64 = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v65,
    `anonymous namespace::SummaryAllocator::s_allocator);
  v57 = 0;
  if ( v58 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      v56,
      4 * v58);
  v56 = 0i64;
  v58 = 0x80000000;
  v54 = 0;
  if ( v55 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      cmpLess.m_allocs,
      56 * (v55 & 0x3FFFFFFF));
  cmpLess.m_allocs = 0i64;
  v60 = 0;
  v55 = 0x80000000;
  if ( v61 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      array,
      8 * v61);
}

// File Line: 309
// RVA: 0xC5FDF0
void __fastcall breadthFirstSearch(
        int startIndex,
        hkArrayBase<int> *connectTo,
        hkArrayBase<int> *connectStart,
        hkArrayBase<hkBool> *visited,
        hkArray<int,SummaryAllocator> *owned)
{
  __int64 m_size; // r14
  hkArrayBase<int> *v8; // r11
  int v9; // r10d
  __int64 v10; // r13
  int *m_data; // rdx
  __int64 v12; // rdi
  __int64 v13; // r9
  __int64 v14; // r8
  __int64 v15; // r15
  __int64 v16; // rbp
  __int64 v17; // rsi
  hkArrayBase<int> *v19; // [rsp+70h] [rbp+18h]

  v19 = connectStart;
  m_size = owned->m_size;
  visited->m_data[startIndex].m_bool = 1;
  v8 = connectTo;
  if ( owned->m_size == (owned->m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(`anonymous namespace::SummaryAllocator::s_allocator, (const void **)&owned->m_data, 4);
    connectStart = v19;
    v8 = connectTo;
  }
  owned->m_data[owned->m_size++] = startIndex;
  v9 = owned->m_size;
  if ( (int)m_size < v9 )
  {
    v10 = m_size;
    do
    {
      m_data = connectStart->m_data;
      v12 = 0i64;
      v13 = owned->m_data[v10];
      v14 = connectStart->m_data[v13];
      v15 = (__int64)&v8->m_data[v14];
      v16 = m_data[v13 + 1] - (int)v14;
      if ( m_data[v13 + 1] - (int)v14 > 0 )
      {
        do
        {
          v17 = *(int *)(v15 + 4 * v12);
          if ( !visited->m_data[v17].m_bool )
          {
            visited->m_data[v17].m_bool = 1;
            if ( owned->m_size == (owned->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                `anonymous namespace::SummaryAllocator::s_allocator,
                (const void **)&owned->m_data,
                4);
            owned->m_data[owned->m_size++] = v17;
            v9 = owned->m_size;
          }
          ++v12;
        }
        while ( v12 < v16 );
        v8 = connectTo;
      }
      connectStart = v19;
      LODWORD(m_size) = m_size + 1;
      ++v10;
    }
    while ( (int)m_size < v9 );
  }
}

// File Line: 334
// RVA: 0xC5FF50
void __fastcall setVisited(hkArrayBase<int> *owned, hkArrayBase<hkBool> *visited, hkBool value)
{
  int v3; // r10d
  __int64 v4; // r11
  char m_bool; // [rsp+18h] [rbp+18h]

  v3 = 0;
  m_bool = value.m_bool;
  if ( owned->m_size > 0 )
  {
    v4 = 0i64;
    while ( 1 )
    {
      ++v3;
      visited->m_data[owned->m_data[v4++]] = value;
      if ( v3 >= owned->m_size )
        break;
      value.m_bool = m_bool;
    }
  }
}

// File Line: 361
// RVA: 0xC5FA30
void __fastcall hkCheckingMemorySystem::dumpLeak(
        hkCheckingMemorySystem *this,
        hkArrayBase<int> *owned,
        hkArrayBase<unsigned __int64> *addrs,
        hkArrayBase<hkCheckingMemorySystem::AllocInfo> *allocs)
{
  hkCriticalSection *p_m_section; // rbx
  int v9; // r15d
  __int64 v10; // rbp
  __int64 v11; // rsi
  const void *v12; // rdi
  hkCheckingMemorySystem::AllocInfo *v13; // rsi
  const char *v14; // rax
  __int64 v15; // [rsp+20h] [rbp-158h]
  char buf[128]; // [rsp+40h] [rbp-138h] BYREF
  char v17[128]; // [rsp+C0h] [rbp-B8h] BYREF
  hkCriticalSection *v18; // [rsp+180h] [rbp+8h]

  p_m_section = &this->m_section;
  v18 = &this->m_section;
  EnterCriticalSection(&this->m_section.m_section);
  hkString::snprintf(buf, 128, "ROOT - %d reached", (unsigned int)(owned->m_size - 1));
  hkCheckingMemorySystem::danger(
    this,
    buf,
    (const void *)addrs->m_data[*owned->m_data],
    &allocs->m_data[*owned->m_data]);
  v9 = 1;
  if ( owned->m_size > 1 )
  {
    v10 = 1i64;
    do
    {
      v11 = owned->m_data[v10];
      v12 = (const void *)addrs->m_data[v11];
      v13 = &allocs->m_data[v11];
      v14 = flagsToString(v17, v13->m_flags);
      LODWORD(v15) = v13->m_size;
      hkString::snprintf(
        buf,
        128,
        "REACHED Address=0x%p size=%i flags=%s thread=%i\n",
        v12,
        v15,
        v14,
        v13->m_threadId);
      this->m_outputFunc(buf, this->m_outputFuncArg);
      ++v9;
      ++v10;
    }
    while ( v9 < owned->m_size );
    p_m_section = v18;
  }
  LeaveCriticalSection(&p_m_section->m_section);
}

// File Line: 385
// RVA: 0xC5F180
void __fastcall hkCheckingMemorySystem::leakReportByOwnership(hkCheckingMemorySystem *this)
{
  hkMemoryAllocator *m_rawAllocator; // rdx
  __int64 v2; // r13
  int m_capacityAndFlags; // eax
  hkCheckingMemorySystem *v4; // r15
  bool v5; // zf
  int v6; // esi
  int m_size; // edi
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  __int64 m_hashMod; // r8
  int v12; // edx
  __int64 v13; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v15; // r8d
  __int64 v16; // r9
  __int64 v17; // r10
  __int64 v18; // rdx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v19; // rcx
  hkCheckingMemorySystem::AllocInfo *v20; // rdi
  __int64 v21; // rax
  int v22; // edx
  __int64 v23; // rdi
  __int64 v24; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v25; // rax
  __int64 v26; // rbx
  __int64 v27; // r12
  __int64 v28; // rsi
  hkCheckingMemorySystem::AllocInfo *m_data; // r9
  unsigned __int64 *v30; // r8
  int *v31; // rcx
  __int64 v32; // kr00_8
  unsigned __int64 v33; // r15
  int v34; // r14d
  __int64 v35; // rbx
  __int64 v36; // rsi
  unsigned __int64 v37; // rcx
  int v38; // ecx
  hkBool *v39; // rdi
  int v40; // eax
  unsigned __int64 v41; // rcx
  int v42; // eax
  signed __int64 v43; // rcx
  int v44; // edi
  __int64 v45; // rdx
  int *v46; // rdx
  int v47; // r8d
  int v48; // ebx
  __int64 v49; // rdi
  int v50; // ebx
  int v51; // r14d
  __int64 v52; // rsi
  hkArray<int,SummaryAllocator> owned; // [rsp+30h] [rbp-59h] BYREF
  hkArray<int,SummaryAllocator> v54; // [rsp+40h] [rbp-49h] BYREF
  hkArrayBase<int> connectStart; // [rsp+50h] [rbp-39h] BYREF
  hkArrayBase<int> connectTo; // [rsp+60h] [rbp-29h] BYREF
  hkArrayBase<hkBool> visited; // [rsp+70h] [rbp-19h] BYREF
  hkArrayBase<hkCheckingMemorySystem::AllocInfo> allocs; // [rsp+80h] [rbp-9h] BYREF
  hkArrayBase<unsigned __int64> array[5]; // [rsp+90h] [rbp+7h] BYREF
  hkCheckingMemorySystem *v60; // [rsp+F0h] [rbp+67h] BYREF
  int v61; // [rsp+F8h] [rbp+6Fh]
  __int64 result; // [rsp+100h] [rbp+77h] BYREF
  __int64 v63; // [rsp+108h] [rbp+7Fh]

  v60 = this;
  m_rawAllocator = this->m_rawAllocator;
  v2 = 0i64;
  m_capacityAndFlags = 0x80000000;
  `anonymous namespace::SummaryAllocator::s_allocator = m_rawAllocator;
  v4 = this;
  v5 = (this->m_activePointers.m_numElems & 0x7FFFFFFF) == 0;
  v6 = this->m_activePointers.m_numElems & 0x7FFFFFFF;
  array[0].m_data = 0i64;
  array[0].m_size = 0;
  array[0].m_capacityAndFlags = 0x80000000;
  allocs.m_data = 0i64;
  allocs.m_size = 0;
  v61 = v6;
  allocs.m_capacityAndFlags = 0x80000000;
  connectTo.m_data = 0i64;
  m_size = 0;
  connectTo.m_size = 0;
  connectTo.m_capacityAndFlags = 0x80000000;
  connectStart.m_data = 0i64;
  connectStart.m_size = 0;
  connectStart.m_capacityAndFlags = 0x80000000;
  if ( !v5 )
  {
    hkArrayUtil::_reserve((hkResult *)&result, m_rawAllocator, (const void **)&array[0].m_data, v6, 8);
    m_capacityAndFlags = allocs.m_capacityAndFlags;
    m_size = connectTo.m_size;
  }
  v8 = m_capacityAndFlags & 0x3FFFFFFF;
  array[0].m_size = v6;
  if ( v8 < v6 )
  {
    v9 = 2 * v8;
    v10 = v6;
    if ( v6 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      (hkResult *)&result,
      `anonymous namespace::SummaryAllocator::s_allocator,
      (const void **)&allocs.m_data,
      v10,
      56);
    m_size = connectTo.m_size;
  }
  m_hashMod = v4->m_activePointers.m_hashMod;
  allocs.m_size = v6;
  v12 = 0;
  v13 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = v4->m_activePointers.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v13;
      ++v12;
      ++m_elem;
    }
    while ( v13 <= m_hashMod );
  }
  v15 = v12;
  if ( v12 <= v4->m_activePointers.m_hashMod )
  {
    v16 = 0i64;
    v17 = 0i64;
    do
    {
      v18 = (__int64)v15 << 6;
      array[0].m_data[v17] = *(unsigned __int64 *)((char *)&v4->m_activePointers.m_elem->key + v18);
      v19 = v4->m_activePointers.m_elem;
      v20 = &allocs.m_data[v16];
      v20->m_threadId = *(unsigned __int64 *)((char *)&v19->val.m_threadId + v18);
      v20->m_allocOrder = *(unsigned __int64 *)((char *)&v19->val.m_allocOrder + v18);
      v20->m_time = *(unsigned __int64 *)((char *)&v19->val.m_time + v18);
      v20->m_tagData = *(const void **)((char *)&v19->val.m_tagData + v18);
      *(_QWORD *)&v20->m_flags.m_storage = *(_QWORD *)((char *)&v19->val.m_flags.m_storage + v18);
      *(_QWORD *)&v20->m_size = *(_QWORD *)((char *)&v19->val.m_size + v18);
      v21 = *(_QWORD *)((char *)&v19->val.m_bookmarkIndex + v18);
      v22 = v15 + 1;
      *(_QWORD *)&v20->m_bookmarkIndex = v21;
      v23 = v4->m_activePointers.m_hashMod;
      v24 = v15 + 1;
      if ( v24 <= v23 )
      {
        v25 = &v4->m_activePointers.m_elem[(__int64)v22];
        do
        {
          if ( v25->key != -1i64 )
            break;
          ++v24;
          ++v22;
          ++v25;
        }
        while ( v24 <= v23 );
      }
      v15 = v22;
      ++v17;
      ++v16;
    }
    while ( v22 <= v4->m_activePointers.m_hashMod );
    m_size = connectTo.m_size;
  }
  v26 = 0i64;
  v27 = v6;
  result = 0i64;
  if ( v6 > 0 )
  {
    v28 = 0i64;
    v63 = 0i64;
    do
    {
      if ( connectStart.m_size == (connectStart.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          `anonymous namespace::SummaryAllocator::s_allocator,
          (const void **)&connectStart.m_data,
          4);
      connectStart.m_data[connectStart.m_size++] = m_size;
      m_data = allocs.m_data;
      v30 = array[0].m_data;
      m_size = connectTo.m_size;
      v31 = (int *)array[0].m_data[v26];
      v32 = *(int *)((char *)&allocs.m_data->m_size + v28);
      v54.m_data = v31;
      owned.m_data = (int *)(((BYTE4(v32) & 7) + (int)v32) >> 3);
      if ( (__int64)owned.m_data > 0 )
      {
        do
        {
          v33 = *(_QWORD *)&v31[2 * v2];
          v34 = 0;
          v35 = 0i64;
          v36 = 0i64;
          do
          {
            v37 = v30[v35];
            if ( v33 >= v37 && v33 < v37 + m_data[v36].m_size )
            {
              if ( m_size == (connectTo.m_capacityAndFlags & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(
                  `anonymous namespace::SummaryAllocator::s_allocator,
                  (const void **)&connectTo.m_data,
                  4);
                m_size = connectTo.m_size;
              }
              connectTo.m_data[m_size] = v34;
              v30 = array[0].m_data;
              m_data = allocs.m_data;
              m_size = ++connectTo.m_size;
            }
            ++v35;
            ++v34;
            ++v36;
          }
          while ( v35 < v27 );
          v31 = v54.m_data;
          ++v2;
        }
        while ( v2 < (__int64)owned.m_data );
        v26 = result;
        v28 = v63;
      }
      ++v26;
      v28 += 56i64;
      v2 = 0i64;
      result = v26;
      v63 = v28;
    }
    while ( v26 < v27 );
    v6 = v61;
    v4 = v60;
  }
  if ( connectStart.m_size == (connectStart.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      `anonymous namespace::SummaryAllocator::s_allocator,
      (const void **)&connectStart.m_data,
      4);
  connectStart.m_data[connectStart.m_size++] = m_size;
  v38 = 0;
  visited.m_size = 0;
  visited.m_data = 0i64;
  visited.m_capacityAndFlags = 0x80000000;
  if ( v6 > 0 )
  {
    hkArrayUtil::_reserve(
      (hkResult *)&v60,
      `anonymous namespace::SummaryAllocator::s_allocator,
      (const void **)&visited.m_data,
      v6,
      1);
    v38 = visited.m_size;
  }
  v39 = &visited.m_data[v38];
  v40 = v6 - v38;
  v41 = v6 - v38;
  if ( v40 > 0 )
    memset(v39, 0, v41);
  v42 = 0;
  visited.m_size = v6;
  v54.m_data = 0i64;
  v54.m_capacityAndFlags = 0x80000000;
  v54.m_size = 0;
  if ( v6 > 0 )
  {
    hkArrayUtil::_reserve(
      (hkResult *)&v60,
      `anonymous namespace::SummaryAllocator::s_allocator,
      (const void **)&v54.m_data,
      v6,
      1);
    v42 = v54.m_size;
  }
  v43 = v6 - v42;
  if ( v43 > 0 )
    memset((char *)v54.m_data + v42, 1, v43);
  v54.m_size = v6;
  v44 = 0;
  if ( connectTo.m_size > 0 )
  {
    v45 = 0i64;
    do
    {
      ++v44;
      *((_BYTE *)v54.m_data + connectTo.m_data[v45++]) = 0;
    }
    while ( v44 < connectTo.m_size );
  }
  v46 = 0i64;
  v47 = 0x80000000;
  owned.m_size = 0;
  v48 = 0;
  v49 = 0i64;
  owned.m_data = 0i64;
  owned.m_capacityAndFlags = 0x80000000;
  if ( v27 > 0 )
  {
    do
    {
      if ( *((_BYTE *)v54.m_data + v49) )
      {
        owned.m_size = 0;
        breadthFirstSearch(v48, &connectTo, &connectStart, &visited, &owned);
        hkCheckingMemorySystem::dumpLeak(v4, &owned, array, &allocs);
      }
      ++v49;
      ++v48;
    }
    while ( v49 < v27 );
    v47 = owned.m_capacityAndFlags;
    v46 = owned.m_data;
  }
  owned.m_size = 0;
  if ( v47 >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      v46,
      4 * v47);
  v54.m_size = 0;
  if ( v54.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      v54.m_data,
      v54.m_capacityAndFlags & 0x3FFFFFFF);
  owned.m_data = 0i64;
  owned.m_capacityAndFlags = 0x80000000;
  v54.m_data = 0i64;
  v54.m_size = 0;
  v54.m_capacityAndFlags = 0x80000000;
  while ( 1 )
  {
    v50 = 0;
    v51 = 0;
    v52 = 0i64;
    owned.m_size = 0;
    if ( v27 <= 0 )
      break;
    do
    {
      if ( !visited.m_data[v52].m_bool )
      {
        v54.m_size = 0;
        breadthFirstSearch(v51, &connectTo, &connectStart, &visited, &v54);
        setVisited(&v54, &visited, 0);
        if ( v54.m_size >= v50
          && (v50 != v54.m_size || allocs.m_data[*v54.m_data].m_allocOrder < allocs.m_data[*owned.m_data].m_allocOrder) )
        {
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&owned,
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v54);
          v50 = owned.m_size;
        }
      }
      ++v52;
      ++v51;
    }
    while ( v52 < v27 );
    if ( v50 <= 0 )
      break;
    setVisited(&owned, &visited, (hkBool)1);
    hkCheckingMemorySystem::dumpLeak(v4, &owned, array, &allocs);
  }
  v54.m_size = 0;
  if ( v54.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      v54.m_data,
      4 * v54.m_capacityAndFlags);
  v54.m_data = 0i64;
  v54.m_capacityAndFlags = 0x80000000;
  if ( owned.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      owned.m_data,
      4 * owned.m_capacityAndFlags);
  visited.m_size = 0;
  if ( visited.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      visited.m_data,
      visited.m_capacityAndFlags & 0x3FFFFFFF);
  visited.m_data = 0i64;
  visited.m_capacityAndFlags = 0x80000000;
  connectStart.m_size = 0;
  if ( connectStart.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      connectStart.m_data,
      4 * connectStart.m_capacityAndFlags);
  connectStart.m_data = 0i64;
  connectStart.m_capacityAndFlags = 0x80000000;
  connectTo.m_size = 0;
  if ( connectTo.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      connectTo.m_data,
      4 * connectTo.m_capacityAndFlags);
  connectTo.m_data = 0i64;
  connectTo.m_capacityAndFlags = 0x80000000;
  allocs.m_size = 0;
  if ( allocs.m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      allocs.m_data,
      56 * (allocs.m_capacityAndFlags & 0x3FFFFFFF));
  allocs.m_data = 0i64;
  allocs.m_capacityAndFlags = 0x80000000;
  array[0].m_size = 0;
  if ( array[0].m_capacityAndFlags >= 0 )
    `anonymous namespace::SummaryAllocator::s_allocator->vfptr->bufFree(
      `anonymous namespace::SummaryAllocator::s_allocator,
      array[0].m_data,
      8 * array[0].m_capacityAndFlags);
}

// File Line: 526
// RVA: 0xC5C9F0
hkResult *__fastcall hkCheckingMemorySystem::quit(hkCheckingMemorySystem *this, hkResult *result)
{
  void *m_outputFuncArg; // rdx
  int i; // esi
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_rawAllocator; // rcx
  int v8; // r8d
  hkMemoryAllocator *v9; // rcx

  result->m_enum = HK_SUCCESS;
  EnterCriticalSection(&this->m_section.m_section);
  if ( this->m_allocators.m_size )
    this->m_outputFunc("A thread did not clean up its allocators.\n", this->m_outputFuncArg);
  m_outputFuncArg = this->m_outputFuncArg;
  if ( (this->m_activePointers.m_numElems & 0x7FFFFFFF) != 0 )
  {
    result->m_enum = HK_FAILURE;
    this->m_outputFunc(
      "**************************************************************\n"
      "* BEGIN MEMORY LEAK REPORT                                   *\n"
      "**************************************************************\n",
      m_outputFuncArg);
    hkCheckingMemorySystem::leakReportByTime(this);
    this->m_outputFunc(
      "**************************************************************\n"
      "* END MEMORY LEAK REPORT                                     *\n"
      "**************************************************************\n",
      this->m_outputFuncArg);
  }
  else
  {
    this->m_outputFunc(
      "**************************************************************\n"
      "* NO HAVOK MEMORY LEAKS FOUND                                *\n"
      "**************************************************************\n",
      m_outputFuncArg);
  }
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_activePointers,
    this->m_rawAllocator);
  for ( i = 0; i < this->m_bookmarks.m_size; ++i )
    hkCheckingMemorySystem::Bookmark::clear(&this->m_bookmarks.m_data[i], this->m_rawAllocator);
  m_capacityAndFlags = this->m_bookmarks.m_capacityAndFlags;
  m_rawAllocator = this->m_rawAllocator;
  this->m_bookmarks.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_rawAllocator->vfptr->bufFree(m_rawAllocator, this->m_bookmarks.m_data, 16 * m_capacityAndFlags);
  this->m_bookmarks.m_data = 0i64;
  this->m_bookmarks.m_capacityAndFlags = 0x80000000;
  if ( (this->m_checkFlags.m_storage & 4) != 0 )
    hkStackTracer::CallTree::quit(&this->m_callTree);
  hkPaddedAllocator::quit(&this->m_paddedAllocator);
  hkDelayedFreeAllocator::quit(&this->m_delayedFreeAllocator);
  v8 = this->m_allocators.m_capacityAndFlags;
  v9 = this->m_rawAllocator;
  this->m_allocators.m_size = 0;
  if ( v8 >= 0 )
    v9->vfptr->bufFree(v9, this->m_allocators.m_data, 8 * v8);
  this->m_allocators.m_data = 0i64;
  this->m_allocators.m_capacityAndFlags = 0x80000000;
  this->m_baseAllocator = 0i64;
  LeaveCriticalSection(&this->m_section.m_section);
  return result;
}

// File Line: 587
// RVA: 0xC5EAA0
hkMemoryAllocator *__fastcall hkCheckingMemorySystem::getUncachedLockedHeapAllocator(hkCheckingMemorySystem *this)
{
  return this->m_mainRouter.m_heap;
}

// File Line: 592
// RVA: 0xC5D410
hkResult *__fastcall hkCheckingMemorySystem::getAllocationCallStack(
        hkCheckingMemorySystem *this,
        hkResult *result,
        unsigned __int64 ptr,
        unsigned __int64 *callStack,
        int *stackSize,
        unsigned __int64 *allocSize)
{
  int Key; // eax
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v10; // rdx
  unsigned __int64 m_size; // rcx
  int v12; // edx
  hkStackTracer::CallTree *p_m_callTree; // rcx
  int v14; // eax

  Key = (unsigned int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                        &this->m_activePointers,
                        ptr);
  if ( Key > this->m_activePointers.m_hashMod )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v10 = &this->m_activePointers.m_elem[(__int64)Key];
    m_size = v10->val.m_size;
    v12 = HIDWORD(*(_QWORD *)&v10->val.m_flags.m_storage);
    *allocSize = m_size;
    p_m_callTree = &this->m_callTree;
    if ( callStack )
      v14 = hkStackTracer::CallTree::getCallStack(p_m_callTree, v12, callStack, *stackSize);
    else
      v14 = hkStackTracer::CallTree::getCallStackSize(p_m_callTree, v12);
    result->m_enum = HK_SUCCESS;
    *stackSize = v14;
  }
  return result;
}

// File Line: 616
// RVA: 0xC5D510
void __fastcall hkCheckingMemorySystem::setHeapScrubValues(
        hkCheckingMemorySystem *this,
        unsigned int allocValue,
        unsigned int freeValue)
{
  EnterCriticalSection(&this->m_section.m_section);
  hkPaddedAllocator::setScrubValues(&this->m_paddedAllocator, allocValue, freeValue);
  LeaveCriticalSection(&this->m_section.m_section);
}

// File Line: 623
// RVA: 0xC5F8A0
hkCheckingMemorySystem::AllocatorForwarder *__fastcall hkCheckingMemorySystem::newAllocator(
        hkCheckingMemorySystem *this,
        hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int> flags,
        unsigned __int64 tid)
{
  _QWORD *v5; // rax
  hkCheckingMemorySystem::AllocatorForwarder *v6; // rdi

  EnterCriticalSection(&this->m_section.m_section);
  v5 = (_QWORD *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, __int64))&this->m_rawAllocator->vfptr->__vecDelDtor + 1))(
                   this->m_rawAllocator,
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
  v6->m_parent = this;
  v6->m_context.threadId = tid;
  v6->m_context.flags = flags;
  if ( this->m_allocators.m_size == (this->m_allocators.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_rawAllocator, (const void **)&this->m_allocators.m_data, 8);
  this->m_allocators.m_data[this->m_allocators.m_size++] = v6;
  LeaveCriticalSection(&this->m_section.m_section);
  return v6;
}

// File Line: 635
// RVA: 0xC5F970
void __fastcall hkCheckingMemorySystem::deleteAllocator(hkCheckingMemorySystem *this, hkMemoryAllocator *a)
{
  __int64 m_size; // r9
  int v3; // ebx
  __int64 v5; // r8
  hkCheckingMemorySystem::AllocatorForwarder **m_data; // rcx
  hkMemoryAllocator **v7; // rax
  __int64 v8; // rax

  m_size = this->m_allocators.m_size;
  v3 = 0;
  v5 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    __debugbreak();
  }
  else
  {
    m_data = this->m_allocators.m_data;
    v7 = m_data;
    while ( *v7 != a )
    {
      ++v5;
      ++v3;
      ++v7;
      if ( v5 >= m_size )
        goto LABEL_5;
    }
    ((void (__fastcall *)(hkCheckingMemorySystem::AllocatorForwarder *, _QWORD, __int64))m_data[v3]->vfptr->__vecDelDtor)(
      m_data[v3],
      0i64,
      v5);
    this->m_rawAllocator->vfptr->blockFree(this->m_rawAllocator, this->m_allocators.m_data[v3], 40);
    v8 = --this->m_allocators.m_size;
    if ( (_DWORD)v8 != v3 )
      this->m_allocators.m_data[v3] = this->m_allocators.m_data[v8];
  }
}

// File Line: 651
// RVA: 0xC5CBC0
unsigned __int64 __fastcall hkCheckingMemorySystem::checkedAlloc(
        hkCheckingMemorySystem *this,
        unsigned int isBuf,
        hkCheckingMemorySystem::AllocationContext *context,
        int numBytes)
{
  __int64 v5; // rbp
  unsigned int m_storage; // edx
  int curInUse; // ecx
  bool v9; // cc
  unsigned __int64 v10; // rsi
  hkMemoryAllocator *m_rawAllocator; // rdx
  unsigned __int64 m_peakInUse; // rax
  hkCheckingMemorySystem::AllocInfo v14; // [rsp+20h] [rbp-88h]
  hkCheckingMemorySystem::AllocInfo v15; // [rsp+60h] [rbp-48h] BYREF

  v5 = numBytes;
  EnterCriticalSection(&this->m_section.m_section);
  if ( (int)v5 < 0 )
  {
    this->m_outputFunc("Negative size to allocate\n", this->m_outputFuncArg);
    __debugbreak();
  }
  m_storage = context->flags.m_storage;
  if ( (m_storage & 4) != 0 )
  {
    context->curInUse += v5;
    curInUse = context->curInUse;
    v9 = context->peakInUse <= curInUse;
  }
  else
  {
    if ( (m_storage & 8) == 0 )
      goto LABEL_10;
    v9 = context->peakInUse <= (int)v5;
    curInUse = v5;
  }
  if ( !v9 )
    curInUse = context->peakInUse;
  context->peakInUse = curInUse;
LABEL_10:
  v14.m_flags.m_storage = m_storage;
  *(_QWORD *)&v14.m_size = (unsigned int)v5;
  v14.m_threadId = context->threadId;
  v14.m_allocOrder = this->m_allocOrder;
  this->m_allocOrder = v14.m_allocOrder + 1;
  *(_OWORD *)&v14.m_time = hkStopwatch::getTickCounter();
  v14.m_bookmarkIndex = this->m_bookmarks.m_size - 1;
  v10 = (*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&this->m_baseAllocator->vfptr->__vecDelDtor + 1))(
          this->m_baseAllocator,
          (unsigned int)v5);
  if ( (this->m_checkFlags.m_storage & 4) != 0 )
    v14.m_traceId = hkStackTracer::CallTree::insertCallStack(&this->m_callTree, &this->m_stackTracer);
  else
    v14.m_traceId = -1;
  m_rawAllocator = this->m_rawAllocator;
  v15 = v14;
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::insert(
    &this->m_activePointers,
    m_rawAllocator,
    v10,
    &v15);
  m_peakInUse = this->m_peakInUse;
  this->m_currentInUse += v5;
  if ( this->m_currentInUse > m_peakInUse )
    m_peakInUse = this->m_currentInUse;
  this->m_peakInUse = m_peakInUse;
  LeaveCriticalSection(&this->m_section.m_section);
  return v10;
}

// File Line: 699
// RVA: 0xC5CD40
void __fastcall hkCheckingMemorySystem::checkedFree(
        hkCheckingMemorySystem *this,
        unsigned int isBuf,
        hkCheckingMemorySystem::AllocationContext *context,
        void *p,
        unsigned int numBytes)
{
  Dummy *Key; // r12
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rcx
  __int64 v10; // rdx
  __int64 v11; // r8
  __int64 v12; // r13
  unsigned __int64 v13; // rax
  __int64 v14; // rax
  hkMemoryAllocator *m_baseAllocator; // rcx
  hkCheckingMemorySystem::AllocInfo info; // [rsp+20h] [rbp-78h] BYREF
  unsigned __int64 v17; // [rsp+A0h] [rbp+8h]
  int v18; // [rsp+B0h] [rbp+18h]

  EnterCriticalSection(&this->m_section.m_section);
  if ( (context->flags.m_storage & 4) != 0 )
    context->curInUse -= numBytes;
  if ( p )
  {
    Key = hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
            &this->m_activePointers,
            (unsigned __int64)p);
    if ( (int)Key > this->m_activePointers.m_hashMod )
    {
      this->m_outputFunc("Freeing block not from this allocator", this->m_outputFuncArg);
      __debugbreak();
    }
    m_elem = this->m_activePointers.m_elem;
    v10 = (__int64)(int)Key << 6;
    v11 = *(_QWORD *)((char *)&m_elem->val.m_size + v10);
    v12 = *(_QWORD *)((char *)&m_elem->val.m_flags.m_storage + v10);
    v17 = *(unsigned __int64 *)((char *)&m_elem->val.m_threadId + v10);
    info.m_threadId = v17;
    info.m_allocOrder = *(unsigned __int64 *)((char *)&m_elem->val.m_allocOrder + v10);
    v13 = *(unsigned __int64 *)((char *)&m_elem->val.m_time + v10);
    *(_QWORD *)&info.m_flags.m_storage = v12;
    info.m_time = v13;
    v18 = v11;
    info.m_tagData = *(const void **)((char *)&m_elem->val.m_tagData + v10);
    v14 = *(_QWORD *)((char *)&m_elem->val.m_bookmarkIndex + v10);
    *(_QWORD *)&info.m_size = v11;
    *(_QWORD *)&info.m_bookmarkIndex = v14;
    if ( (_DWORD)v11 != numBytes )
    {
      hkCheckingMemorySystem::danger(this, "Freeing block of incorrect size", p, &info);
      __debugbreak();
    }
    if ( (unsigned int)v12 != context->flags.m_storage )
    {
      hkCheckingMemorySystem::danger(this, "Freeing block with different tag", p, &info);
      __debugbreak();
    }
    if ( (context->flags.m_storage & 4) != 0 && v17 != context->threadId )
    {
      hkCheckingMemorySystem::danger(this, "Freeing block from a different thread", p, &info);
      __debugbreak();
    }
    if ( info.m_locks )
    {
      hkCheckingMemorySystem::danger(this, "Freeing locked block", p, &info);
      __debugbreak();
    }
    if ( (this->m_checkFlags.m_storage & 4) != 0 )
      hkStackTracer::CallTree::releaseCallStack(&this->m_callTree, info.m_traceId);
    hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::remove(
      &this->m_activePointers,
      Key);
    m_baseAllocator = this->m_baseAllocator;
    this->m_currentInUse -= v18;
    m_baseAllocator->vfptr->blockFree(m_baseAllocator, p, numBytes);
  }
  else if ( numBytes )
  {
    this->m_outputFunc("Given nonzero bytes to free with an null address\n", this->m_outputFuncArg);
    __debugbreak();
  }
  LeaveCriticalSection(&this->m_section.m_section);
}

// File Line: 755
// RVA: 0xC5D570
__int64 __fastcall hkCheckingMemorySystem::isOk(hkCheckingMemorySystem *this)
{
  unsigned int v2; // r14d
  __int64 m_hashMod; // r8
  int v4; // edx
  __int64 v5; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v7; // esi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v8; // rdx
  __int64 v9; // rcx
  const void *key; // rbp
  unsigned __int64 m_allocOrder; // rax
  __int64 v12; // r8
  int v13; // edx
  __int64 v14; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v15; // rax
  hkCheckingMemorySystem::AllocInfo info; // [rsp+20h] [rbp-58h] BYREF

  EnterCriticalSection(&this->m_section.m_section);
  v2 = 1;
  if ( (this->m_checkFlags.m_storage & 8) != 0 )
  {
    m_hashMod = this->m_activePointers.m_hashMod;
    v4 = 0;
    v5 = 0i64;
    if ( m_hashMod >= 0 )
    {
      m_elem = this->m_activePointers.m_elem;
      do
      {
        if ( m_elem->key != -1i64 )
          break;
        ++v5;
        ++v4;
        ++m_elem;
      }
      while ( v5 <= m_hashMod );
    }
    v7 = v4;
    if ( v4 <= this->m_activePointers.m_hashMod )
    {
      do
      {
        v8 = &this->m_activePointers.m_elem[(__int64)v7];
        v9 = *(_QWORD *)&v8->val.m_size;
        key = (const void *)v8->key;
        info.m_threadId = v8->val.m_threadId;
        m_allocOrder = v8->val.m_allocOrder;
        *(_QWORD *)&info.m_size = v9;
        info.m_allocOrder = m_allocOrder;
        info.m_time = v8->val.m_time;
        info.m_tagData = v8->val.m_tagData;
        *(_QWORD *)&info.m_flags.m_storage = *(_QWORD *)&v8->val.m_flags.m_storage;
        *(_QWORD *)&info.m_bookmarkIndex = *(_QWORD *)&v8->val.m_bookmarkIndex;
        if ( !hkPaddedAllocator::isOk(&this->m_paddedAllocator, key, v9) )
        {
          hkCheckingMemorySystem::danger(this, "Damaged block:\n", key, &info);
          v2 = 0;
        }
        v12 = this->m_activePointers.m_hashMod;
        v13 = v7 + 1;
        v14 = v7 + 1;
        if ( v14 <= v12 )
        {
          v15 = &this->m_activePointers.m_elem[(__int64)v13];
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
      while ( v13 <= this->m_activePointers.m_hashMod );
    }
  }
  if ( (this->m_checkFlags.m_storage & 0x10) != 0 && !hkDelayedFreeAllocator::isOk(&this->m_delayedFreeAllocator) )
    v2 = 0;
  LeaveCriticalSection(&this->m_section.m_section);
  return v2;
}

// File Line: 785
// RVA: 0xC5CF40
hkResult *__fastcall hkCheckingMemorySystem::getMemorySnapshot(
        hkCheckingMemorySystem *this,
        hkResult *result,
        hkMemorySnapshot *snapshot)
{
  hkCriticalSection *p_m_section; // rbx
  int v6; // r13d
  int v7; // esi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *p_m_activePointers; // r10
  __int64 m_hashMod; // r9
  int v10; // edx
  __int64 v11; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v13; // r12d
  __int64 v14; // r13
  char *v15; // rcx
  bool v16; // zf
  char *v17; // rsi
  __int64 v18; // r15
  char *address; // rcx
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
  hkStackTracer::CallTree::Node *m_data; // r12
  int v36; // r15d
  hkRecallAllocator::Header *m_head; // rsi
  char *v38; // r9
  char *v39; // rax
  int v40; // r15d
  __int64 v41; // rsi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *v42; // r15
  int MemSize; // eax
  int solver; // [rsp+30h] [rbp-D0h]
  int parent; // [rsp+34h] [rbp-CCh]
  int debug; // [rsp+38h] [rbp-C8h]
  hkPaddedAllocator::Allocation resulta; // [rsp+40h] [rbp-C0h] BYREF
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
  unsigned __int64 addrs[134]; // [rsp+D0h] [rbp-30h] BYREF
  int v64; // [rsp+510h] [rbp+410h]
  int id; // [rsp+528h] [rbp+428h]

  p_m_section = &this->m_section;
  EnterCriticalSection(&this->m_section.m_section);
  v6 = hkMemorySnapshot::addProvider(snapshot, "<System>", -1);
  id = v6;
  v7 = v6;
  parent = hkMemorySnapshot::addProvider(snapshot, "hkStatsAllocator(CallTree)", v6);
  v64 = v6;
  if ( (this->m_checkFlags.m_storage & 0x10) != 0 )
  {
    v7 = hkDelayedFreeAllocator::addToSnapshot(&this->m_delayedFreeAllocator, snapshot, v6);
    v64 = v7;
  }
  if ( (this->m_checkFlags.m_storage & 8) != 0 )
  {
    v7 = hkMemorySnapshot::addProvider(snapshot, "hkPaddedAllocator", v7);
    v64 = v7;
  }
  debug = hkMemorySnapshot::addProvider(snapshot, "hkRecallAllocator", v6);
  solver = hkMemorySnapshot::addProvider(snapshot, "hkCheckingMemorySystem", -1);
  hkMemorySnapshot::addParentProvider(snapshot, solver, v7);
  hkMemorySnapshot::addParentProvider(snapshot, solver, parent);
  hkMemorySnapshot::setRouterWiring(snapshot, solver, solver, solver, debug, solver);
  p_m_activePointers = &this->m_activePointers;
  m_hashMod = this->m_activePointers.m_hashMod;
  v10 = 0;
  v11 = 0i64;
  v49 = &this->m_activePointers;
  if ( (int)m_hashMod >= 0 )
  {
    m_elem = p_m_activePointers->m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v11;
      ++v10;
      ++m_elem;
    }
    while ( v11 <= m_hashMod );
  }
  v13 = v10;
  if ( v10 <= (int)m_hashMod )
  {
    do
    {
      v14 = (__int64)v13 << 6;
      v15 = (char *)p_m_activePointers->m_elem + v14;
      v16 = (this->m_checkFlags.m_storage & 8) == 0;
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
        hkMemorySnapshot::addItem(snapshot, id, (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1, v17, v18);
      }
      else
      {
        hkPaddedAllocator::getUnderlyingAllocation(&this->m_paddedAllocator, &resulta, v17, v18);
        hkMemorySnapshot::addItem(
          snapshot,
          id,
          (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1,
          resulta.address,
          resulta.size);
        address = (char *)resulta.address;
        if ( resulta.address != v17 )
        {
          hkMemorySnapshot::addItem(snapshot, v64, 0, resulta.address, (_DWORD)v17 - LODWORD(resulta.address));
          address = (char *)resulta.address;
        }
        v20 = &address[resulta.size];
        v21 = &v17[(int)v18];
        if ( v20 != v21 )
          hkMemorySnapshot::addItem(snapshot, v64, 0, v21, (_DWORD)v20 - (_DWORD)v21);
      }
      v22 = hkMemorySnapshot::addItem(
              snapshot,
              solver,
              (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1,
              v17,
              v18);
      if ( (this->m_checkFlags.m_storage & 4) != 0 )
      {
        v23 = (unsigned __int64 *)((char *)&this->m_activePointers.m_elem->key + v14);
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
        v30 = hkStackTracer::CallTree::getCallStack(&this->m_callTree, v54[1], addrs, 128);
        hkMemorySnapshot::setCallStack(snapshot, v22, addrs, v30);
      }
      p_m_activePointers = &this->m_activePointers;
      v31 = v13 + 1;
      v32 = this->m_activePointers.m_hashMod;
      v33 = v13 + 1;
      if ( v33 <= v32 )
      {
        v34 = &p_m_activePointers->m_elem[(__int64)v31];
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
    while ( v31 <= (int)v32 );
    v6 = id;
    p_m_section = &this->m_section;
  }
  m_data = this->m_callTree.m_nodes.m_data;
  v36 = 24 * (this->m_callTree.m_nodes.m_capacityAndFlags & 0x3FFFFFFF);
  hkMemorySnapshot::addItem(snapshot, parent, (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1, m_data, v36);
  m_head = this->m_debugAllocator.m_head;
  if ( m_head )
  {
    do
    {
      hkMemorySnapshot::addItem(
        snapshot,
        v6,
        (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1,
        m_head,
        m_head->m_requestedSize);
      hkMemorySnapshot::addItem(snapshot, debug, 0, m_head, 16);
      hkMemorySnapshot::addItem(
        snapshot,
        debug,
        (hkEnum<enum hkMemorySnapshot::StatusBits,signed char>)1,
        &m_head[1],
        m_head->m_payloadSize);
      v38 = (char *)&m_head[1] + m_head->m_payloadSize;
      v39 = (char *)m_head + m_head->m_requestedSize;
      if ( v38 != v39 )
        hkMemorySnapshot::addItem(snapshot, debug, 0, v38, (_DWORD)v39 - (_DWORD)v38);
      m_head = m_head->m_next;
    }
    while ( m_head );
    p_m_section = &this->m_section;
  }
  hkMemorySnapshot::addItem(snapshot, solver, 0, m_data, v36);
  hkMemorySnapshot::addItem(snapshot, solver, 0, this->m_allocators.m_data, 8 * this->m_allocators.m_capacityAndFlags);
  v40 = 0;
  if ( this->m_allocators.m_size > 0 )
  {
    v41 = 0i64;
    do
    {
      hkMemorySnapshot::addItem(snapshot, solver, 0, this->m_allocators.m_data[v41], 40);
      ++v40;
      ++v41;
    }
    while ( v40 < this->m_allocators.m_size );
  }
  v42 = v49;
  MemSize = hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::getMemSize(v49);
  hkMemorySnapshot::addItem(snapshot, solver, 0, v42->m_elem, MemSize);
  result->m_enum = HK_SUCCESS;
  LeaveCriticalSection(&p_m_section->m_section);
  return result;
}stem::AllocInfo,hkMapOpe

// File Line: 862
// RVA: 0xC5D810
unsigned __int64 __fastcall hkCheckingMemorySystem::findBaseAddress(
        hkCheckingMemorySystem *this,
        unsigned __int64 pquery,
        int nbytes)
{
  hkCriticalSection *p_m_section; // rbx
  __int64 v5; // r12
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *p_m_activePointers; // r14
  int Key; // eax
  __int64 m_hashMod; // r15
  unsigned __int64 v10; // rdi
  int v11; // ebp
  int i; // esi
  int v13; // eax
  __int64 v14; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v16; // edx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v17; // r9
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v18; // rcx
  __int64 v19; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v20; // rax

  p_m_section = &this->m_section;
  v5 = nbytes;
  EnterCriticalSection(&this->m_section.m_section);
  p_m_activePointers = &this->m_activePointers;
  Key = (unsigned int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                        p_m_activePointers,
                        pquery);
  m_hashMod = p_m_activePointers->m_hashMod;
  if ( Key <= (int)m_hashMod )
  {
    v10 = -1i64;
    if ( (int)v5 <= p_m_activePointers->m_elem[(__int64)Key].val.m_size )
      v10 = pquery;
    goto LABEL_24;
  }
  v10 = (pquery + 15) & 0xFFFFFFFFFFFFFFF0ui64;
  v11 = 0;
  for ( i = 0; i < 50; ++i )
  {
    v10 -= 16i64;
    v13 = (unsigned int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                          p_m_activePointers,
                          v10);
    if ( v13 <= (int)m_hashMod )
    {
      if ( v5 + pquery <= v10 + p_m_activePointers->m_elem[(__int64)v13].val.m_size )
        goto LABEL_24;
      goto LABEL_23;
    }
  }
  v14 = 0i64;
  if ( (int)m_hashMod >= 0 )
  {
    m_elem = p_m_activePointers->m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v14;
      ++v11;
      ++m_elem;
    }
    while ( v14 <= m_hashMod );
  }
  v16 = v11;
  if ( v11 > (int)m_hashMod )
  {
LABEL_23:
    v10 = -1i64;
    goto LABEL_24;
  }
  v17 = p_m_activePointers->m_elem;
  while ( 1 )
  {
    v18 = &v17[(__int64)v16];
    v10 = v18->key;
    if ( v18->key <= pquery && v5 + pquery <= v10 + v18->val.m_size )
      break;
    v19 = ++v16;
    if ( v16 <= m_hashMod )
    {
      v20 = &v17[(__int64)v16];
      do
      {
        if ( v20->key != -1i64 )
          break;
        ++v19;
        ++v16;
        ++v20;
      }
      while ( v19 <= m_hashMod );
    }
    if ( v16 > (int)m_hashMod )
      goto LABEL_23;
  }
LABEL_24:
  LeaveCriticalSection(&p_m_section->m_section);
  return v10;
}

// File Line: 931
// RVA: 0xC5DA40
void __fastcall hkCheckingMemorySystem::lockBaseAddress(hkCheckingMemorySystem *this, unsigned __int64 p)
{
  hkCriticalSection *p_m_section; // rsi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v5; // rdi
  __int64 v6; // rax
  unsigned __int64 m_allocOrder; // r8
  unsigned __int64 m_time; // r9
  const void *m_tagData; // r10
  __int64 v10; // r11
  __int64 v11; // rbx

  p_m_section = &this->m_section;
  EnterCriticalSection(&this->m_section.m_section);
  v5 = &this->m_activePointers.m_elem[(__int64)(int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                                                      &this->m_activePointers,
                                                      p)];
  v6 = *(_QWORD *)&v5->val.m_size;
  m_allocOrder = v5->val.m_allocOrder;
  m_time = v5->val.m_time;
  m_tagData = v5->val.m_tagData;
  v10 = *(_QWORD *)&v5->val.m_flags.m_storage;
  v11 = *(_QWORD *)&v5->val.m_bookmarkIndex;
  v5->val.m_threadId = v5->val.m_threadId;
  v5->val.m_allocOrder = m_allocOrder;
  v5->val.m_time = m_time;
  v5->val.m_tagData = m_tagData;
  *(_QWORD *)&v5->val.m_flags.m_storage = v10;
  *(_QWORD *)&v5->val.m_size = v6 + 0x100000000i64;
  *(_QWORD *)&v5->val.m_bookmarkIndex = v11;
  LeaveCriticalSection(&p_m_section->m_section);
}

// File Line: 943
// RVA: 0xC5DAF0
void __fastcall hkCheckingMemorySystem::unlockBaseAddress(hkCheckingMemorySystem *this, unsigned __int64 p)
{
  hkCriticalSection *p_m_section; // rsi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v5; // rdi
  __int64 v6; // rax
  unsigned __int64 m_allocOrder; // r8
  unsigned __int64 m_time; // r9
  const void *m_tagData; // r10
  __int64 v10; // r11
  __int64 v11; // rbx

  p_m_section = &this->m_section;
  EnterCriticalSection(&this->m_section.m_section);
  v5 = &this->m_activePointers.m_elem[(__int64)(int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                                                      &this->m_activePointers,
                                                      p)];
  v6 = *(_QWORD *)&v5->val.m_size;
  m_allocOrder = v5->val.m_allocOrder;
  m_time = v5->val.m_time;
  m_tagData = v5->val.m_tagData;
  v10 = *(_QWORD *)&v5->val.m_flags.m_storage;
  v11 = *(_QWORD *)&v5->val.m_bookmarkIndex;
  v5->val.m_threadId = v5->val.m_threadId;
  v5->val.m_allocOrder = m_allocOrder;
  v5->val.m_time = m_time;
  v5->val.m_tagData = m_tagData;
  *(_QWORD *)&v5->val.m_flags.m_storage = v10;
  *(_QWORD *)&v5->val.m_size = v6 - 0x100000000i64;
  *(_QWORD *)&v5->val.m_bookmarkIndex = v11;
  LeaveCriticalSection(&p_m_section->m_section);
}

// File Line: 956
// RVA: 0xC5DBA0
void __fastcall hkCheckingMemorySystem::tagAddress(
        hkCheckingMemorySystem *this,
        unsigned __int64 baseAddress,
        const void *data)
{
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v4; // r11
  unsigned __int64 m_allocOrder; // rdx
  unsigned __int64 m_time; // r8
  __int64 v7; // r9
  __int64 v8; // r10
  __int64 v9; // rax

  v4 = &this->m_activePointers.m_elem[(__int64)(int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::findKey(
                                                      &this->m_activePointers,
                                                      baseAddress)];
  m_allocOrder = v4->val.m_allocOrder;
  m_time = v4->val.m_time;
  v7 = *(_QWORD *)&v4->val.m_size;
  v8 = *(_QWORD *)&v4->val.m_bookmarkIndex;
  v9 = *(_QWORD *)&v4->val.m_flags.m_storage;
  v4->val.m_threadId = v4->val.m_threadId;
  v4->val.m_allocOrder = m_allocOrder;
  v4->val.m_time = m_time;
  v4->val.m_tagData = data;
  *(_QWORD *)&v4->val.m_flags.m_storage = v9;
  *(_QWORD *)&v4->val.m_size = v7;
  *(_QWORD *)&v4->val.m_bookmarkIndex = v8;
}

// File Line: 976
// RVA: 0xC5DCE0
hkMemoryRouter *__fastcall hkCheckingMemorySystem::mainInit(
        hkCheckingMemorySystem *this,
        hkMemorySystem::FrameInfo *info,
        hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  this->m_frameInfo = (hkMemorySystem::FrameInfo)info->m_solverBufferSize;
  if ( (flags.m_storage & 1) == 0 )
    return &this->m_mainRouter;
  ((void (__fastcall *)(hkCheckingMemorySystem *, hkMemoryRouter *, const char *, _QWORD))this->vfptr->threadInit)(
    this,
    &this->m_mainRouter,
    "main",
    (unsigned int)flags.m_storage);
  return &this->m_mainRouter;
}

// File Line: 990
// RVA: 0xC5DD30
hkResult *__fastcall hkCheckingMemorySystem::mainQuit(
        hkCheckingMemorySystem *this,
        hkResult *result,
        hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkResult *v5; // rax

  if ( (flags.m_storage & 1) != 0 )
  {
    ((void (__fastcall *)(hkCheckingMemorySystem *, hkMemoryRouter *))this->vfptr->threadQuit)(
      this,
      &this->m_mainRouter);
    hkCheckingMemorySystem::quit(this, result);
    return result;
  }
  else
  {
    v5 = result;
    result->m_enum = HK_SUCCESS;
  }
  return v5;
}

// File Line: 1005
// RVA: 0xC5DD90
void __fastcall hkCheckingMemorySystem::threadInit(
        hkCheckingMemorySystem *this,
        hkMemoryRouter *router,
        const char *name,
        hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  unsigned __int64 MyThreadId; // rax
  char v7; // r8
  unsigned __int64 v8; // rbp
  hkCheckingMemorySystem::AllocatorForwarder *v9; // rax
  hkCheckingMemorySystem::AllocatorForwarder *v10; // rax
  char m_storage; // [rsp+48h] [rbp+20h]

  m_storage = flags.m_storage;
  EnterCriticalSection(&this->m_section.m_section);
  MyThreadId = hkThread::getMyThreadId();
  v7 = m_storage;
  v8 = MyThreadId;
  if ( (m_storage & 1) != 0 )
  {
    v9 = hkCheckingMemorySystem::newAllocator(
           this,
           (hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int>)1,
           MyThreadId);
    v7 = m_storage;
    router->m_heap = v9;
    router->m_debug = &this->m_debugAllocator;
    router->m_temp = 0i64;
    router->m_solver = 0i64;
  }
  if ( (v7 & 2) != 0 )
  {
    v10 = hkCheckingMemorySystem::newAllocator(
            this,
            (hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int>)2,
            v8);
    hkLifoAllocator::init(&router->m_stack, v10, v10, v10);
    router->m_temp = hkCheckingMemorySystem::newAllocator(
                       this,
                       (hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int>)4,
                       v8);
    router->m_solver = hkCheckingMemorySystem::newAllocator(
                         this,
                         (hkFlags<enum hkCheckingMemorySystem::AllocatorBits,unsigned int>)8,
                         v8);
  }
  LeaveCriticalSection(&this->m_section.m_section);
}

// File Line: 1041
// RVA: 0xC5DE70
void __fastcall hkCheckingMemorySystem::threadQuit(
        hkCheckingMemorySystem *this,
        hkMemoryRouter *router,
        hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  char v5; // al
  hkMemoryAllocator *m_solver; // rdx
  hkMemoryAllocator *allocators[5]; // [rsp+20h] [rbp-28h] BYREF
  char m_storage; // [rsp+60h] [rbp+18h]

  m_storage = flags.m_storage;
  EnterCriticalSection(&this->m_section.m_section);
  v5 = m_storage;
  if ( (m_storage & 2) != 0 )
  {
    memset(allocators, 0, 24);
    hkLifoAllocator::quit(&router->m_stack, allocators);
    hkCheckingMemorySystem::deleteAllocator(this, allocators[0]);
    hkCheckingMemorySystem::deleteAllocator(this, router->m_temp);
    m_solver = router->m_solver;
    router->m_temp = 0i64;
    hkCheckingMemorySystem::deleteAllocator(this, m_solver);
    v5 = m_storage;
    router->m_solver = 0i64;
  }
  if ( (v5 & 1) != 0 )
  {
    hkCheckingMemorySystem::deleteAllocator(this, router->m_heap);
    hkMemUtil::memSet(router, 0, 0x80u);
  }
  LeaveCriticalSection(&this->m_section.m_section);
}

// File Line: 1066
// RVA: 0xC5DF40
void __fastcall hkCheckingMemorySystem::getMemoryStatistics(
        hkCheckingMemorySystem *this,
        hkMemorySystem::MemoryStatistics *stats)
{
  int v4; // edi
  hkMemorySystem::MemoryStatistics::Entry *v5; // rbx
  hkMemorySystem::MemoryStatistics::Entry *v6; // rbx
  hkMemorySystem::MemoryStatistics::Entry *v7; // rbx
  hkMemorySystem::MemoryStatistics::Entry *v8; // rbx
  hkMemorySystem::MemoryStatistics::Entry *v9; // rbx
  hkMemorySystem::MemoryStatistics::Entry *v10; // rbx
  hkMemorySystem::MemoryStatistics::Entry *v11; // rbx

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
  stats->m_entries.m_size = 0;
  if ( (stats->m_entries.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&stats->m_entries.m_data, 56);
  v6 = &stats->m_entries.m_data[stats->m_entries.m_size];
  if ( v6 )
  {
    hkStringPtr::hkStringPtr(&v6->m_allocatorName);
    v6->m_allocatorStats.m_allocated = -1i64;
    v6->m_allocatorStats.m_inUse = -1i64;
    v6->m_allocatorStats.m_peakInUse = -1i64;
    v6->m_allocatorStats.m_available = -1i64;
    v6->m_allocatorStats.m_totalAvailable = -1i64;
    v6->m_allocatorStats.m_largestBlock = -1i64;
  }
  v7 = &stats->m_entries.m_data[stats->m_entries.m_size++];
  hkStringPtr::operator=(&v7->m_allocatorName, "System");
  this->m_baseAllocator->vfptr->getMemoryStatistics(this->m_baseAllocator, &v7->m_allocatorStats);
  if ( stats->m_entries.m_size == (stats->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&stats->m_entries.m_data, 56);
  v8 = &stats->m_entries.m_data[stats->m_entries.m_size];
  if ( v8 )
  {
    hkStringPtr::hkStringPtr(&v8->m_allocatorName);
    v8->m_allocatorStats.m_allocated = -1i64;
    v8->m_allocatorStats.m_inUse = -1i64;
    v8->m_allocatorStats.m_peakInUse = -1i64;
    v8->m_allocatorStats.m_available = -1i64;
    v8->m_allocatorStats.m_totalAvailable = -1i64;
    v8->m_allocatorStats.m_largestBlock = -1i64;
  }
  v9 = &stats->m_entries.m_data[stats->m_entries.m_size++];
  hkStringPtr::operator=(&v9->m_allocatorName, "Heap");
  this->m_paddedAllocator.vfptr->getMemoryStatistics(&this->m_paddedAllocator, &v9->m_allocatorStats);
  if ( stats->m_entries.m_size == (stats->m_entries.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&stats->m_entries.m_data, 56);
  v10 = &stats->m_entries.m_data[stats->m_entries.m_size];
  if ( v10 )
  {
    hkStringPtr::hkStringPtr(&v10->m_allocatorName);
    v10->m_allocatorStats.m_allocated = -1i64;
    v10->m_allocatorStats.m_inUse = -1i64;
    v10->m_allocatorStats.m_peakInUse = -1i64;
    v10->m_allocatorStats.m_available = -1i64;
    v10->m_allocatorStats.m_totalAvailable = -1i64;
    v10->m_allocatorStats.m_largestBlock = -1i64;
  }
  v11 = &stats->m_entries.m_data[stats->m_entries.m_size++];
  hkStringPtr::operator=(&v11->m_allocatorName, "Debug");
  this->m_debugAllocator.vfptr->getMemoryStatistics(&this->m_debugAllocator, &v11->m_allocatorStats);
}

// File Line: 1086
// RVA: 0xC5E170
void __fastcall hkCheckingMemorySystem::printStatistics(hkCheckingMemorySystem *this, hkOstream *ostr)
{
  hkCheckingMemorySystem *v2; // r13
  hkOstream *v3; // r12
  int v4; // r15d
  hkMemoryAllocatorVtbl *vfptr; // rax
  unsigned int v6; // r14d
  unsigned int v7; // esi
  unsigned int v8; // edi
  int v9; // edx
  __int64 v10; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *p_m_activePointers; // rax
  __int64 m_hashMod; // r8
  __int64 v13; // r9
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v15; // r11d
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v16; // rsi
  unsigned int v17; // ebx
  __int64 v18; // r13
  unsigned int v19; // r12d
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v20; // rcx
  __int64 v21; // r10
  __int64 v22; // rax
  __int64 v23; // rax
  unsigned int v24; // ecx
  int v25; // edx
  __int64 v26; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v27; // rax
  hkMemoryAllocator *m_rawAllocator; // rcx
  unsigned int v29; // r14d
  int v30; // edi
  hkMemoryAllocatorVtbl *v31; // rax
  int v32; // edi
  __int64 MemSize; // rsi
  unsigned int v34; // edi
  int v35; // esi
  char *v36; // rdx
  __int64 v37; // r8
  int v38; // eax
  int v39; // ecx
  int v40; // eax
  int v41; // ecx
  unsigned int v42; // r13d
  int v43; // r14d
  __int64 v44; // r12
  int v45; // edi
  __int64 v46; // r9
  _RTL_CRITICAL_SECTION *v47; // rbx
  unsigned int v48; // edi
  unsigned int *v49; // r14
  __int64 v50; // r12
  unsigned int v51; // esi
  __int64 v52; // r14
  hkCheckingMemorySystem::AllocatorForwarder *v53; // rsi
  const char *v54; // rax
  __int64 v55; // [rsp+20h] [rbp-E0h]
  __int64 v56; // [rsp+28h] [rbp-D8h]
  unsigned int v57; // [rsp+30h] [rbp-D0h]
  unsigned int v58; // [rsp+34h] [rbp-CCh]
  __int64 dst[6]; // [rsp+38h] [rbp-C8h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [rsp+68h] [rbp-98h]
  __int64 v61; // [rsp+70h] [rbp-90h]
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> > *v62; // [rsp+78h] [rbp-88h]
  unsigned __int64 m_threadId; // [rsp+80h] [rbp-80h] BYREF
  unsigned __int64 m_allocOrder; // [rsp+88h] [rbp-78h]
  unsigned __int64 m_time; // [rsp+90h] [rbp-70h]
  __int64 m_tagData; // [rsp+98h] [rbp-68h]
  __int64 v67; // [rsp+A0h] [rbp-60h]
  __int64 v68; // [rsp+A8h] [rbp-58h]
  __int64 v69; // [rsp+B0h] [rbp-50h]
  __int64 v70[7]; // [rsp+B8h] [rbp-48h] BYREF
  char v71[160]; // [rsp+F0h] [rbp-10h] BYREF
  _DWORD buf[32]; // [rsp+190h] [rbp+90h] BYREF
  int Dst[56]; // [rsp+210h] [rbp+110h] BYREF
  unsigned int v76; // [rsp+318h] [rbp+218h]

  v2 = this;
  v3 = ostr;
  lpCriticalSection = &this->m_section.m_section;
  EnterCriticalSection(&this->m_section.m_section);
  hkOstream::printf(v3, "hkCheckingMemorySystem memory overview:\n=======================================\n");
  memset(Dst, 0, 0xA0ui64);
  memset(v71, 0, sizeof(v71));
  memset(buf, 0, sizeof(buf));
  v4 = 0;
  vfptr = v2->m_debugAllocator.vfptr;
  v61 = 0i64;
  v6 = 0;
  v58 = 0;
  v7 = 0;
  v76 = 0;
  v8 = 0;
  memset(v70, 255, 48);
  vfptr->getMemoryStatistics(&v2->m_debugAllocator, (hkMemoryAllocator::MemoryStatistics *)v70);
  v9 = 0;
  v10 = 0i64;
  v57 = v70[0];
  p_m_activePointers = &v2->m_activePointers;
  m_hashMod = v2->m_activePointers.m_hashMod;
  v62 = &v2->m_activePointers;
  v13 = m_hashMod;
  if ( (int)m_hashMod >= 0 )
  {
    m_elem = p_m_activePointers->m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v10;
      ++v9;
      ++m_elem;
    }
    while ( v10 <= m_hashMod );
    p_m_activePointers = &v2->m_activePointers;
  }
  v15 = v9;
  if ( v9 <= (int)m_hashMod )
  {
    v16 = p_m_activePointers->m_elem;
    v17 = 0;
    v18 = 0i64;
    v19 = 0;
    do
    {
      v20 = &v16[(__int64)v15];
      v21 = *(_QWORD *)&v20->val.m_flags.m_storage;
      m_hashMod = *(_QWORD *)&v20->val.m_size;
      m_threadId = v20->val.m_threadId;
      m_allocOrder = v20->val.m_allocOrder;
      m_time = v20->val.m_time;
      m_tagData = (__int64)v20->val.m_tagData;
      v69 = *(_QWORD *)&v20->val.m_bookmarkIndex;
      if ( (v21 & 1) != 0 )
      {
        v6 += m_hashMod;
        if ( (int)m_hashMod > 640 )
        {
          v23 = 0i64;
          v24 = m_hashMod;
          do
          {
            ++v23;
            v24 >>= 1;
          }
          while ( v24 );
          ++buf[v23];
          v18 += (int)m_hashMod;
        }
        else if ( (_DWORD)m_hashMod )
        {
          v22 = ((int)m_hashMod - 1) / 16;
          ++Dst[v22];
          *(_DWORD *)&v71[4 * v22] += m_hashMod;
        }
        else
        {
          ++Dst[0];
        }
      }
      if ( (v21 & 2) != 0 )
        v17 += m_hashMod;
      if ( (v21 & 4) != 0 )
        v19 += m_hashMod;
      if ( (v21 & 8) != 0 )
        v8 += m_hashMod;
      v25 = v15 + 1;
      v26 = v15 + 1;
      if ( v26 <= v13 )
      {
        v27 = &v16[(__int64)v25];
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
    while ( v25 <= v62->m_hashMod );
    v61 = v18;
    v2 = this;
    v76 = v19;
    v3 = ostr;
    v58 = v6;
    v7 = v17;
  }
  m_rawAllocator = v2->m_rawAllocator;
  m_threadId = -1i64;
  m_allocOrder = -1i64;
  m_time = -1i64;
  m_tagData = -1i64;
  v67 = -1i64;
  v68 = -1i64;
  ((void (__fastcall *)(hkMemoryAllocator *, unsigned __int64 *, __int64, __int64))m_rawAllocator->vfptr->getMemoryStatistics)(
    m_rawAllocator,
    &m_threadId,
    m_hashMod,
    v13);
  hkOstream::printf(v3, "\n    Allocation totals:\n\n");
  hkOstream::printf(v3, "%20i allocated by heap\n", v6);
  hkOstream::printf(v3, "%20i allocated by debug\n", v57);
  hkOstream::printf(v3, "%20i allocated by stack\n", v7);
  hkOstream::printf(v3, "%20i allocated by temp\n", v76);
  hkOstream::printf(v3, "%20i allocated by solver\n", v8);
  v29 = v58 + v57 + v7 + v8 + v76;
  if ( (v2->m_checkFlags.m_storage & 0x10) != 0 )
  {
    memset(dst, 255, sizeof(dst));
    v2->m_delayedFreeAllocator.vfptr->getMemoryStatistics(
      &v2->m_delayedFreeAllocator,
      (hkMemoryAllocator::MemoryStatistics *)dst);
    v30 = LODWORD(dst[0]) - LODWORD(dst[1]);
    hkOstream::printf(v3, "%20i in delayed frees\n", (unsigned int)(LODWORD(dst[0]) - LODWORD(dst[1])));
    v29 += v30;
  }
  if ( (v2->m_checkFlags.m_storage & 8) != 0 )
  {
    v31 = v2->m_paddedAllocator.vfptr;
    memset(dst, 255, sizeof(dst));
    v31->getMemoryStatistics(&v2->m_paddedAllocator, (hkMemoryAllocator::MemoryStatistics *)dst);
    v32 = LODWORD(dst[0]) - LODWORD(dst[1]);
    hkOstream::printf(v3, "%20i in allocation padding\n", (unsigned int)(LODWORD(dst[0]) - LODWORD(dst[1])));
    v29 += v32;
  }
  if ( (v2->m_checkFlags.m_storage & 4) != 0 )
  {
    memset(dst, 255, sizeof(dst));
    v2->m_callTreeAllocator.vfptr->getMemoryStatistics(
      &v2->m_callTreeAllocator,
      (hkMemoryAllocator::MemoryStatistics *)dst);
    hkOstream::printf(v3, "%20i in callstacks\n", dst[0]);
    v29 += LODWORD(dst[0]);
  }
  MemSize = (unsigned int)hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64>>::getMemSize(&v2->m_activePointers);
  hkOstream::printf(v3, "%20i in active pointer map\n", MemSize);
  v34 = 8 * (5 * v2->m_allocators.m_size + (v2->m_allocators.m_capacityAndFlags & 0x3FFFFFFF));
  hkOstream::printf(v3, "%20i in allocator forwarders\n", v34);
  hkOstream::printf(v3, "%20s\n", "-------");
  hkOstream::printf(v3, "%20i computed total\n", v29 + v34 + (_DWORD)MemSize);
  hkOstream::printf(v3, "%20i reported total\n", (unsigned int)m_threadId);
  hkOstream::printf(v3, "\n    Heap small block (<=%i) summary:\n\n", 640i64);
  v35 = 0;
  v36 = &v71[4];
  v37 = 8i64;
  do
  {
    v38 = *((_DWORD *)v36 - 1);
    v39 = *(_DWORD *)v36;
    v36 += 20;
    if ( v35 > v38 )
      v38 = v35;
    v35 = *((_DWORD *)v36 - 2);
    if ( v38 > v39 )
      v39 = v38;
    v40 = *((_DWORD *)v36 - 4);
    if ( v39 > v40 )
      v40 = v39;
    v41 = *((_DWORD *)v36 - 3);
    if ( v40 > v41 )
      v41 = v40;
    if ( v41 > v35 )
      v35 = v41;
    --v37;
  }
  while ( v37 );
  v42 = 0;
  v43 = 16;
  v44 = 0i64;
  do
  {
    memset(dst, 0, 0x29ui64);
    v45 = *(_DWORD *)&v71[v44 * 4];
    hkString::memSet(dst, 62, 40 * v45 / v35);
    v46 = (unsigned int)Dst[v44];
    LODWORD(v55) = (int)v46 * v43 / 1024;
    hkOstream::printf(ostr, "%20i * %6i = %4ik : %s\n", (unsigned int)v43, v46, v55, (const char *)dst);
    v43 += 16;
    v42 += v45;
    ++v44;
  }
  while ( v43 < 656 );
  hkOstream::printf(ostr, "%20s\n", "-------");
  hkOstream::printf(ostr, "%20i bytes total\n", v42);
  hkOstream::printf(ostr, "\n    Heap large block (>%i) summary:\n\n", 640i64);
  v47 = lpCriticalSection;
  v48 = 1024;
  v49 = &buf[10];
  v50 = 22i64;
  do
  {
    v51 = *v49;
    if ( *v49 )
    {
      *(_DWORD *)&v71[12] = -2147483520;
      *(_DWORD *)&v71[8] = 1;
      *(_QWORD *)v71 = &v71[16];
      v71[16] = 0;
      hkStringBuf::printf((hkStringBuf *)v71, "<=%i", v48);
      LODWORD(v55) = (int)(v48 * v51) / 1024;
      hkOstream::printf(ostr, "%20s * %6i = %4ik\n", *(const char **)v71, v51, v55);
      *(_DWORD *)&v71[8] = 0;
      if ( *(int *)&v71[12] >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          *(void **)v71,
          *(_DWORD *)&v71[12] & 0x3FFFFFFF);
    }
    v48 = __ROL4__(v48, 1);
    ++v49;
    --v50;
  }
  while ( v50 );
  hkOstream::printf(ostr, "%20s\n", "-------");
  hkOstream::printf(ostr, "%20i bytes total\n", v61);
  hkOstream::printf(ostr, "\n    Threads summary:\n\n");
  if ( this->m_allocators.m_size > 0 )
  {
    v52 = 0i64;
    do
    {
      v53 = this->m_allocators.m_data[v52];
      if ( (v53->m_context.flags.m_storage & 0xC) != 0 )
      {
        v54 = flagsToString((char *)buf, v53->m_context.flags);
        LODWORD(v56) = v53->m_context.peakInUse;
        hkOstream::printf(ostr, "%10s Thread %I64u, %6s, peak %i\n", &customCaption, v53->m_context.threadId, v54, v56);
      }
      ++v4;
      ++v52;
    }
    while ( v4 < this->m_allocators.m_size );
    v47 = lpCriticalSection;
  }
  LeaveCriticalSection(v47);
}

// File Line: 1260
// RVA: 0xC5EAB0
void __fastcall hkCheckingMemorySystem::getHeapStatistics(
        hkCheckingMemorySystem *this,
        hkMemoryAllocator::MemoryStatistics *stats)
{
  this->m_baseAllocator->vfptr->getMemoryStatistics(this->m_baseAllocator, stats);
}

// File Line: 1265
// RVA: 0xC5E930
void __fastcall hkCheckingMemorySystem::advanceFrame(hkCheckingMemorySystem *this)
{
  __int64 m_hashMod; // r9
  int v3; // r8d
  __int64 v4; // rdx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v6; // edi
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v7; // r8
  __int64 v8; // rcx
  unsigned __int64 m_allocOrder; // rax
  __int64 v10; // r9
  int v11; // edx
  __int64 v12; // rcx
  hkMapBase<unsigned __int64,hkCheckingMemorySystem::AllocInfo,hkMapOperations<unsigned __int64> >::Pair *v13; // rax
  hkCheckingMemorySystem::AllocInfo info; // [rsp+20h] [rbp-48h] BYREF

  EnterCriticalSection(&this->m_section.m_section);
  m_hashMod = this->m_activePointers.m_hashMod;
  v3 = 0;
  v4 = 0i64;
  if ( (int)m_hashMod >= 0 )
  {
    m_elem = this->m_activePointers.m_elem;
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
  if ( v3 <= (int)m_hashMod )
  {
    do
    {
      v7 = &this->m_activePointers.m_elem[(__int64)v6];
      v8 = *(_QWORD *)&v7->val.m_flags.m_storage;
      info.m_threadId = v7->val.m_threadId;
      m_allocOrder = v7->val.m_allocOrder;
      *(_QWORD *)&info.m_flags.m_storage = v8;
      info.m_allocOrder = m_allocOrder;
      info.m_time = v7->val.m_time;
      info.m_tagData = v7->val.m_tagData;
      *(_QWORD *)&info.m_size = *(_QWORD *)&v7->val.m_size;
      *(_QWORD *)&info.m_bookmarkIndex = *(_QWORD *)&v7->val.m_bookmarkIndex;
      if ( (v8 & 4) != 0 )
        hkCheckingMemorySystem::danger(
          this,
          "A temp allocation lived past a frame advance",
          (const void *)v7->key,
          &info);
      v10 = this->m_activePointers.m_hashMod;
      v11 = v6 + 1;
      v12 = v6 + 1;
      if ( v12 <= v10 )
      {
        v13 = &this->m_activePointers.m_elem[(__int64)v11];
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
    while ( v11 <= (int)v10 );
  }
  LeaveCriticalSection(&this->m_section.m_section);
}

// File Line: 1285
// RVA: 0xC5EA60
void __fastcall hkCheckingMemorySystem::garbageCollectShared(hkCheckingMemorySystem *this)
{
  EnterCriticalSection(&this->m_section.m_section);
  ((void (__fastcall *)(hkDelayedFreeAllocator *))this->m_delayedFreeAllocator.vfptr[1].__vecDelDtor)(&this->m_delayedFreeAllocator);
  LeaveCriticalSection(&this->m_section.m_section);
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
  this->m_checkFlags.m_storage &= ~4u;
  this->m_checkFlags.m_storage |= enabled ? 4 : 0;
}

// File Line: 1305
// RVA: 0xC5DC20
void __fastcall hkCheckingMemorySystem::addBookmark(hkCheckingMemorySystem *this, const char *bookmarkName)
{
  hkArrayBase<hkCheckingMemorySystem::Bookmark> *p_m_bookmarks; // rbx
  hkCheckingMemorySystem::Bookmark *v5; // rax

  p_m_bookmarks = &this->m_bookmarks;
  if ( this->m_bookmarks.m_size == (this->m_bookmarks.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_rawAllocator, (const void **)&p_m_bookmarks->m_data, 16);
  v5 = &p_m_bookmarks->m_data[p_m_bookmarks->m_size];
  if ( v5 )
  {
    v5->m_name = 0i64;
    v5->m_time = 0i64;
  }
  hkCheckingMemorySystem::Bookmark::set(
    &p_m_bookmarks->m_data[p_m_bookmarks->m_size++],
    this->m_rawAllocator,
    bookmarkName);
}

// File Line: 1311
// RVA: 0xC5FB90
__int64 __fastcall hkCheckingMemorySystem::findPrecedingBookmark(
        hkCheckingMemorySystem *this,
        unsigned __int64 timeStamp)
{
  __int64 m_size; // r11
  int v3; // r9d
  __int64 v4; // r8
  unsigned __int64 *i; // rax

  m_size = this->m_bookmarks.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (int)m_size <= 0 )
    return (unsigned int)m_size;
  for ( i = &this->m_bookmarks.m_data->m_time; *i <= timeStamp; i += 2 )
  {
    ++v4;
    ++v3;
    if ( v4 >= m_size )
      return (unsigned int)m_size;
  }
  return (unsigned int)(v3 - 1);
}

// File Line: 1325
// RVA: 0xC5D750
void __fastcall hkCheckingMemorySystem::Bookmark::set(
        hkCheckingMemorySystem::Bookmark *this,
        hkMemoryAllocator *alloc,
        const char *name)
{
  unsigned int v6; // ebp
  char *v7; // rax

  v6 = hkString::strLen(name) + 1;
  v7 = (char *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&alloc->vfptr->__vecDelDtor + 1))(alloc, v6);
  this->m_name = v7;
  if ( v7 )
    hkString::memCpy(v7, name, v6);
  this->m_time = hkStopwatch::getTickCounter();
}

// File Line: 1337
// RVA: 0xC5D7C0
void __fastcall hkCheckingMemorySystem::Bookmark::clear(
        hkCheckingMemorySystem::Bookmark *this,
        hkMemoryAllocator *alloc)
{
  char *m_name; // rcx
  int v5; // eax

  m_name = this->m_name;
  if ( m_name )
  {
    v5 = hkString::strLen(m_name);
    alloc->vfptr->blockFree(alloc, this->m_name, v5 + 1);
    this->m_name = 0i64;
  }
}

// File Line: 1348
// RVA: 0xC5D720
unsigned __int64 __fastcall hkCheckingMemorySystem::AllocInfo::getKey(hkCheckingMemorySystem::AllocInfo *this)
{
  unsigned int m_traceId; // edx
  BOOL v2; // r8d

  m_traceId = this->m_traceId;
  v2 = m_traceId == -1;
  if ( m_traceId == -1 )
    m_traceId = this->m_bookmarkIndex;
  return m_traceId | ((unsigned __int64)v2 << 32);
}

