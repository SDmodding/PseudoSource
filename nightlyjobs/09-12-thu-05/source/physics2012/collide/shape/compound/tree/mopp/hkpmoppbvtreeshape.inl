// File Line: 12
// RVA: 0xCEB110
void __fastcall hkpMoppBvTreeShape::hkpMoppBvTreeShape(hkpMoppBvTreeShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpMoppBvTreeShape *v2; // rbx
  hkpMoppCode *v3; // rcx
  int v4; // [rsp+38h] [rbp+10h]

  v4 = flag.m_finishing;
  v2 = this;
  hkpBvTreeShape::hkpBvTreeShape((hkpBvTreeShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkMoppBvTreeShapeBase::`vftable;
  if ( v4 )
    v2->m_bvTreeType.m_storage = 0;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpMoppBvTreeShape::`vftable;
  v2->m_child.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  if ( v4 == 1 )
  {
    v3 = v2->m_code;
    v2->m_type.m_storage = 9;
    v2->m_codeInfoCopy = (hkVector4f)v3->m_info;
    v2->m_moppData = v3->m_data.m_data;
    v2->m_moppDataSize = v3->m_data.m_size;
  }
}

// File Line: 28
// RVA: 0xCEB2D0
hkpShapeContainer *__fastcall hkpMoppBvTreeShape::getContainer(hkpMoppBvTreeShape *this)
{
  return (hkpShapeContainer *)((__int64 (*)(void))this->m_child.m_childShape->vfptr[7].__vecDelDtor)();
}

