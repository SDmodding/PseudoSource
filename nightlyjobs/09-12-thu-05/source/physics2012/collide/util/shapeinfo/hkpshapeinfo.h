// File Line: 27
// RVA: 0xCEBD60
void __fastcall hkpShapeInfo::~hkpShapeInfo(hkpShapeInfo *this)
{
  int v1; // er8
  hkpShapeInfo *v2; // rbx
  int v3; // edi
  hkStringPtr *v4; // rsi
  int v5; // er8
  hkReferencedObject *v6; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpShapeInfo::`vftable;
  v1 = this->m_childTransforms.m_capacityAndFlags;
  v2 = this;
  this->m_childTransforms.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_childTransforms.m_data,
      v1 << 6);
  v2->m_childTransforms.m_data = 0i64;
  v2->m_childTransforms.m_capacityAndFlags = 2147483648;
  v3 = v2->m_childShapeNames.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v2->m_childShapeNames.m_data[v3];
    do
    {
      hkStringPtr::~hkStringPtr(v4);
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = v2->m_childShapeNames.m_capacityAndFlags;
  v2->m_childShapeNames.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_childShapeNames.m_data,
      8 * v5);
  v2->m_childShapeNames.m_data = 0i64;
  v2->m_childShapeNames.m_capacityAndFlags = 2147483648;
  v6 = (hkReferencedObject *)&v2->m_shape.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v2->m_shape.m_pntr = 0i64;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

