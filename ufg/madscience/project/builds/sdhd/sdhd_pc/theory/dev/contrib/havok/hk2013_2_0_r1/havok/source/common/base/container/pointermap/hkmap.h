// File Line: 232
// RVA: 0x9ACC0
void __fastcall hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>::~hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator>(hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator> *this)
{
  hkMap<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>,hkContainerHeapAllocator> *v1; // rbx

  v1 = this;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)v1);
}

