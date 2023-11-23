// File Line: 27
// RVA: 0xCEBD60
void __fastcall hkpShapeInfo::~hkpShapeInfo(hkpShapeInfo *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // edi
  hkStringPtr *v4; // rsi
  int v5; // r8d
  hkpShape *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkpShapeInfo::`vftable;
  m_capacityAndFlags = this->m_childTransforms.m_capacityAndFlags;
  this->m_childTransforms.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_childTransforms.m_data,
      m_capacityAndFlags << 6);
  this->m_childTransforms.m_data = 0i64;
  this->m_childTransforms.m_capacityAndFlags = 0x80000000;
  v3 = this->m_childShapeNames.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &this->m_childShapeNames.m_data[v3];
    do
    {
      hkStringPtr::~hkStringPtr(v4--);
      --v3;
    }
    while ( v3 >= 0 );
  }
  v5 = this->m_childShapeNames.m_capacityAndFlags;
  this->m_childShapeNames.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_childShapeNames.m_data,
      8 * v5);
  this->m_childShapeNames.m_data = 0i64;
  this->m_childShapeNames.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_shape.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_shape.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

