// File Line: 14
// RVA: 0xE1A080
void __fastcall hkpSerializedDisplayRbTransforms::~hkpSerializedDisplayRbTransforms(hkpSerializedDisplayRbTransforms *this)
{
  __int64 v1; // rsi
  hkpSerializedDisplayRbTransforms *v2; // rdi
  __int64 v3; // rbx
  int v4; // eax

  v1 = this->m_transforms.m_size;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSerializedDisplayRbTransforms::`vftable';
  if ( v1 > 0 )
  {
    v3 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_transforms.m_data[v3].m_rb->vfptr);
      ++v3;
      --v1;
    }
    while ( v1 );
  }
  v4 = v2->m_transforms.m_capacityAndFlags;
  v2->m_transforms.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_transforms.m_data,
      80 * (v4 & 0x3FFFFFFF));
  v2->m_transforms.m_data = 0i64;
  v2->m_transforms.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

