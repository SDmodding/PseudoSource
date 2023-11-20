// File Line: 13
// RVA: 0xB335C0
void __fastcall hkaAnimationPreviewColorContainer::hkaAnimationPreviewColorContainer(hkaAnimationPreviewColorContainer *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaAnimationPreviewColorContainer::`vftable';
  this->m_previewColor.m_capacityAndFlags = 2147483648;
  this->m_previewColor.m_data = 0i64;
  this->m_previewColor.m_size = 0;
}

// File Line: 17
// RVA: 0xB335F0
void __fastcall hkaAnimationPreviewColorContainer::~hkaAnimationPreviewColorContainer(hkaAnimationPreviewColorContainer *this)
{
  hkaAnimationPreviewColorContainer *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaAnimationPreviewColorContainer::`vftable';
  v2 = this->m_previewColor.m_capacityAndFlags;
  this->m_previewColor.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_previewColor.m_data,
      4 * v2);
  v1->m_previewColor.m_data = 0i64;
  v1->m_previewColor.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 21
// RVA: 0xB33660
void __fastcall hkaAnimationPreviewColorContainer::newPreviewColor(hkaAnimationPreviewColorContainer *this, unsigned int color)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *v2; // rbx
  unsigned int v3; // edi

  v2 = &this->m_previewColor;
  v3 = color;
  if ( this->m_previewColor.m_size == (this->m_previewColor.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 4);
  v2->m_data[v2->m_size++] = v3;
}

