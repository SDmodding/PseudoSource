// File Line: 12
// RVA: 0xCEB110
void __fastcall hkpMoppBvTreeShape::hkpMoppBvTreeShape(hkpMoppBvTreeShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpMoppCode *m_code; // rcx

  hkpBvTreeShape::hkpBvTreeShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkMoppBvTreeShapeBase::`vftable;
  if ( flag.m_finishing )
    this->m_bvTreeType.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMoppBvTreeShape::`vftable;
  this->m_child.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  if ( flag.m_finishing == 1 )
  {
    m_code = this->m_code;
    this->m_type.m_storage = 9;
    this->m_codeInfoCopy = (hkVector4f)m_code->m_info;
    this->m_moppData = m_code->m_data.m_data;
    this->m_moppDataSize = m_code->m_data.m_size;
  }
}

// File Line: 28
// RVA: 0xCEB2D0
hkpShapeContainer *__fastcall hkpMoppBvTreeShape::getContainer(hkpMoppBvTreeShape *this)
{
  return (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))this->m_child.m_childShape->vfptr[7].__vecDelDtor)(this->m_child.m_childShape);
}

