// File Line: 14
// RVA: 0xD096C0
__int64 __fastcall hkpShapeContainer::getCollisionFilterInfo(hkpShapeContainer *this, unsigned int key)
{
  return 0i64;
}

// File Line: 19
// RVA: 0xD09670
__int64 __fastcall hkpShapeContainer::getNumChildShapes(hkpShapeContainer *this)
{
  hkpShapeContainer *v1; // rdi
  unsigned int v2; // ebx
  unsigned int i; // eax

  v1 = this;
  v2 = 0;
  for ( i = ((__int64 (*)(void))this->vfptr->getFirstKey)(); i != -1; i = v1->vfptr->getNextKey(v1, i) )
    ++v2;
  return v2;
}

// File Line: 29
// RVA: 0xD096D0
hkpShape *__fastcall hkpSingleShapeContainer::getChildShape(hkpSingleShapeContainer *this, unsigned int key, char (*buffer)[512])
{
  return this->m_childShape;
}

