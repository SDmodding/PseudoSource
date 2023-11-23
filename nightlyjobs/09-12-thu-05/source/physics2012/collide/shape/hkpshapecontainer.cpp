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
  unsigned int v2; // ebx
  unsigned int i; // eax

  v2 = 0;
  for ( i = this->vfptr->getFirstKey(this); i != -1; i = this->vfptr->getNextKey(this, i) )
    ++v2;
  return v2;
}

// File Line: 29
// RVA: 0xD096D0
hkpShape *__fastcall hkpSingleShapeContainer::getChildShape(
        hkpSingleShapeContainer *this,
        unsigned int key,
        char (*buffer)[512])
{
  return this->m_childShape;
}

