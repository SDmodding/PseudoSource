// File Line: 78
// RVA: 0xE245C0
void __fastcall hkpConstraintChainInstance::insertEntityAtFront(hkpConstraintChainInstance *this, hkClass *entity)
{
  hkClass *t; // [rsp+38h] [rbp+10h] BYREF

  t = entity;
  hkArrayBase<hkClass *>::_insertAt(
    (hkArrayBase<hkClass *> *)&this->m_chainedEntities,
    &hkContainerHeapAllocator::s_alloc,
    0,
    (hkProcess *const *)&t);
  hkReferencedObject::addReference((hkReferencedObject *)entity);
}

