// File Line: 13
// RVA: 0xB335C0
void __fastcall hkaAnimationPreviewColorContainer::hkaAnimationPreviewColorContainer(
        hkaAnimationPreviewColorContainer *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaAnimationPreviewColorContainer::`vftable;
  this->m_previewColor.m_capacityAndFlags = 0x80000000;
  this->m_previewColor.m_data = 0i64;
  this->m_previewColor.m_size = 0;
}

// File Line: 17
// RVA: 0xB335F0
void __fastcall hkaAnimationPreviewColorContainer::~hkaAnimationPreviewColorContainer(
        hkaAnimationPreviewColorContainer *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkaAnimationPreviewColorContainer::`vftable;
  m_capacityAndFlags = this->m_previewColor.m_capacityAndFlags;
  this->m_previewColor.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_previewColor.m_data,
      4 * m_capacityAndFlags);
  this->m_previewColor.m_data = 0i64;
  this->m_previewColor.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 21
// RVA: 0xB33660
void __fastcall hkaAnimationPreviewColorContainer::newPreviewColor(
        hkaAnimationPreviewColorContainer *this,
        unsigned int color)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *p_m_previewColor; // rbx

  p_m_previewColor = &this->m_previewColor;
  if ( this->m_previewColor.m_size == (this->m_previewColor.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_previewColor, 4);
  p_m_previewColor->m_data[p_m_previewColor->m_size++] = color;
}

