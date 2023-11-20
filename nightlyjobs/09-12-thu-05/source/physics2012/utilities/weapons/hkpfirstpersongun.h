// File Line: 98
// RVA: 0xE0A2D0
void __fastcall hkpFirstPersonGun::~hkpFirstPersonGun(hkpFirstPersonGun *this)
{
  int v1; // esi
  hkpFirstPersonGun *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpFirstPersonGun::`vftable;
  v2 = this;
  if ( this->m_listeners.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_listeners.m_data[v3]->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_listeners.m_size );
  }
  v4 = v2->m_listeners.m_capacityAndFlags;
  v2->m_listeners.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_listeners.m_data,
      8 * v4);
  v2->m_listeners.m_data = 0i64;
  v2->m_listeners.m_capacityAndFlags = 2147483648;
  hkStringPtr::~hkStringPtr(&v2->m_name);
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

