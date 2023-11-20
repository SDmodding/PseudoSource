// File Line: 13
// RVA: 0xE0B9D0
void __fastcall hkpSerializedDisplayMarkerList::~hkpSerializedDisplayMarkerList(hkpSerializedDisplayMarkerList *this)
{
  int v1; // esi
  hkpSerializedDisplayMarkerList *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8

  v1 = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSerializedDisplayMarkerList::`vftable;
  v2 = this;
  if ( this->m_markers.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_markers.m_data[v3]->vfptr);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_markers.m_size );
  }
  v4 = v2->m_markers.m_capacityAndFlags;
  v2->m_markers.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_markers.m_data,
      8 * v4);
  v2->m_markers.m_data = 0i64;
  v2->m_markers.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

