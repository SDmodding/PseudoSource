// File Line: 232
// RVA: 0x9ACC0
void __fastcall hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>(
        hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this)
{
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    this,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)this);
}

