// File Line: 78
// RVA: 0xE245C0
void __fastcall hkpConstraintChainInstance::insertEntityAtFront(hkpConstraintChainInstance *this, hkpEntity *entity)
{
  hkpEntity *v2; // rbx
  hkClass *t; // [rsp+38h] [rbp+10h]

  t = (hkClass *)entity;
  v2 = entity;
  hkArrayBase<hkClass *>::_insertAt(
    (hkArrayBase<hkClass *> *)&this->m_chainedEntities,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    0,
    &t);
  hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
}

