// File Line: 14
// RVA: 0xE1A080
void __fastcall hkpSerializedDisplayRbTransforms::~hkpSerializedDisplayRbTransforms(
        hkpSerializedDisplayRbTransforms *this)
{
  __int64 m_size; // rsi
  __int64 v3; // rbx
  int m_capacityAndFlags; // eax

  m_size = this->m_transforms.m_size;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSerializedDisplayRbTransforms::`vftable;
  if ( m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_transforms.m_data[v3++].m_rb);
      --m_size;
    }
    while ( m_size );
  }
  m_capacityAndFlags = this->m_transforms.m_capacityAndFlags;
  this->m_transforms.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_transforms.m_data,
      80 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_transforms.m_data = 0i64;
  this->m_transforms.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

