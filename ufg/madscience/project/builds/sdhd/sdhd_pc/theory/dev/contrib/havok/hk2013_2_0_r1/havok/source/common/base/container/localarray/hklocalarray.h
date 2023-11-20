// File Line: 54
// RVA: 0x9AB10
void __fastcall __1__hkLocalArray_UFixup__1__ForcePose_Ragdoll_UFG__QEAAXPEBVhkaSkeleton__PEAVhkaPose__AEAVhkQsTransformf___N_Z___QEAA_XZ(hkLocalArray<`UFG::Ragdoll::ForcePose'::`2'::Fixup> *this)
{
  hkLocalArray<`UFG::Ragdoll::ForcePose'::`2'::Fixup> *v1; // rdi
  struct UFG::Ragdoll::ForcePose::__l2::Fixup *v2; // rsi
  int v3; // ebx
  hkLifoAllocator *v4; // rcx
  signed int v5; // ebx
  int v6; // er8
  int v7; // er8

  v1 = this;
  v2 = this->m_localMemory;
  if ( v2 == this->m_data )
    this->m_size = 0;
  v3 = this->m_initialCapacity;
  v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (112 * v3 + 127) & 0xFFFFFF80;
  v6 = (v5 + 15) & 0xFFFFFFF0;
  if ( v5 > v4->m_slabSize || (char *)v2 + v6 != v4->m_cur || v4->m_firstNonLifoEnd == v2 )
    hkLifoAllocator::slowBlockFree(v4, v2, v6);
  else
    v4->m_cur = v2;
  v1->m_size = 0;
  v7 = v1->m_capacityAndFlags;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_data,
      112 * (v7 & 0x3FFFFFFF));
  v1->m_capacityAndFlags = 2147483648;
  v1->m_data = 0i64;
}

