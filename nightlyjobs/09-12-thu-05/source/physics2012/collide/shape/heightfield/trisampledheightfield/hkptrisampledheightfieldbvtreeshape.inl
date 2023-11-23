// File Line: 19
// RVA: 0xCF9FD0
hkpShapeContainer *__fastcall hkpTriSampledHeightFieldBvTreeShape::getContainer(
        hkpTriSampledHeightFieldBvTreeShape *this)
{
  return (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))this->m_childContainer.m_childShape->vfptr[7].__vecDelDtor)(this->m_childContainer.m_childShape);
}

