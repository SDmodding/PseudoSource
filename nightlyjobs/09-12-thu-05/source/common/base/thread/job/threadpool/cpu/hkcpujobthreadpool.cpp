// File Line: 13
// RVA: 0xC65840
void __fastcall hkCpuJobThreadPoolCinfo::hkCpuJobThreadPoolCinfo(hkCpuJobThreadPoolCinfo *this)
{
  hkCpuThreadPoolCinfo::hkCpuThreadPoolCinfo(
    (hkCpuThreadPoolCinfo *)&this->m_workerFunction,
    hkCpuJobThreadPool::workerFunction);
}

// File Line: 17
// RVA: 0xC65870
void __fastcall hkCpuJobThreadPool::hkCpuJobThreadPool(hkCpuJobThreadPool *this, hkCpuJobThreadPoolCinfo *ci)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkCpuJobThreadPool::`vftable;
  hkCpuThreadPool::hkCpuThreadPool(&this->m_threadPool, (hkCpuThreadPoolCinfo *)&ci->m_workerFunction);
}

// File Line: 21
// RVA: 0xC658B0
void __fastcall hkCpuJobThreadPool::processAllJobs(hkCpuJobThreadPool *this, hkJobQueue *queue, __int64 firstJobType_unused)
{
  ((void (__fastcall *)(hkCpuThreadPool *, hkJobQueue *, __int64))this->m_threadPool.vfptr[1].__first_virtual_table_function__)(
    &this->m_threadPool,
    queue,
    firstJobType_unused);
}

// File Line: 32
// RVA: 0xC658F0
__int64 __fastcall hkCpuJobThreadPool::isProcessing(hkCpuJobThreadPool *this)
{
  return ((__int64 (__fastcall *)(hkCpuThreadPool *))this->m_threadPool.vfptr[2].__first_virtual_table_function__)(&this->m_threadPool);
}

// File Line: 38
// RVA: 0xC65950
__int64 __fastcall hkCpuJobThreadPool::getNumThreads(hkCpuJobThreadPool *this)
{
  return ((__int64 (__fastcall *)(hkCpuThreadPool *))this->m_threadPool.vfptr[3].__vecDelDtor)(&this->m_threadPool);
}

// File Line: 44
// RVA: 0xC65970
void __fastcall hkCpuJobThreadPool::setNumThreads(hkCpuJobThreadPool *this, __int64 numThreads)
{
  ((void (__fastcall *)(hkCpuThreadPool *, __int64))this->m_threadPool.vfptr[3].__first_virtual_table_function__)(
    &this->m_threadPool,
    numThreads);
}

// File Line: 50
// RVA: 0xC658D0
void __fastcall hkCpuJobThreadPool::waitForCompletion(hkCpuJobThreadPool *this)
{
  ((void (__fastcall *)(hkCpuThreadPool *))this->m_threadPool.vfptr[2].__vecDelDtor)(&this->m_threadPool);
}

// File Line: 56
// RVA: 0xC65910
void __fastcall hkCpuJobThreadPool::appendTimerData(hkCpuJobThreadPool *this, hkArrayBase<hkTimerData> *timerDataOut, hkMemoryAllocator *alloc)
{
  ((void (__fastcall *)(hkCpuThreadPool *, hkArrayBase<hkTimerData> *, hkMemoryAllocator *))this->m_threadPool.vfptr[4].__vecDelDtor)(
    &this->m_threadPool,
    timerDataOut,
    alloc);
}

// File Line: 62
// RVA: 0xC65930
void __fastcall hkCpuJobThreadPool::clearTimerData(hkCpuJobThreadPool *this)
{
  this->m_threadPool.vfptr[4].__first_virtual_table_function__((hkBaseObject *)&this->m_threadPool);
}

// File Line: 68
// RVA: 0xC65990
void __fastcall hkCpuJobThreadPool::gcThreadMemoryOnNextCompletion(hkCpuJobThreadPool *this)
{
  ((void (__fastcall *)(hkCpuThreadPool *))this->m_threadPool.vfptr[5].__vecDelDtor)(&this->m_threadPool);
}

// File Line: 74
// RVA: 0xC659B0
void __fastcall hkCpuJobThreadPool::workerFunction(void *workLoad)
{
  hkJobQueue::processAllJobs((hkJobQueue *)workLoad, 1);
}

