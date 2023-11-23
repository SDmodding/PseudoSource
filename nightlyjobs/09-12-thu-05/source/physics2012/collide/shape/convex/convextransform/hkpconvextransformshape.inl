// File Line: 68
// RVA: 0xCF1BF0
__int64 __fastcall hkpConvexTranslateShape::getNumCollisionSpheres(hkpConvexTransformShape *this)
{
  return ((__int64 (__fastcall *)(hkpShape *))this->m_childShape.m_childShape->vfptr[5].__first_virtual_table_function__)(this->m_childShape.m_childShape);
}

