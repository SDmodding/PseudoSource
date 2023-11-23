// File Line: 16
// RVA: 0xD789B0
void __fastcall hkpConstraintChainInstanceAction::applyAction(
        hkpConstraintChainInstanceAction *this,
        hkStepInfo *stepInfo)
{
  ;
}

// File Line: 22
// RVA: 0xD789C0
hkpAction *__fastcall hkpConstraintChainInstanceAction::clone(
        hkpConstraintChainInstanceAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  return 0i64;
}

// File Line: 28
// RVA: 0xD789D0
void __fastcall hkpConstraintChainInstanceAction::entityRemovedCallback(
        hkpConstraintChainInstanceAction *this,
        hkpEntity *entity)
{
  this->m_constraintInstance->vfptr[2].__vecDelDtor(this->m_constraintInstance, (unsigned int)entity);
}

// File Line: 36
// RVA: 0xD789F0
void __fastcall hkpConstraintChainInstanceAction::getEntities(
        hkpConstraintChainInstanceAction *this,
        hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut)
{
  hkpConstraintChainInstance *m_constraintInstance; // rbx
  __int64 m_size; // rcx
  hkpEntity **m_data; // rax
  __int64 v6; // rdx
  signed __int64 v7; // r8
  hkpEntity *v8; // rcx
  int v9; // [rsp+30h] [rbp+8h] BYREF

  m_constraintInstance = this->m_constraintInstance;
  if ( (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) < m_constraintInstance->m_chainedEntities.m_size )
  {
    if ( entitiesOut->m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        entitiesOut->m_data,
        8 * entitiesOut->m_capacityAndFlags);
    v9 = 8 * m_constraintInstance->m_chainedEntities.m_size;
    entitiesOut->m_data = (hkpEntity **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                          &hkContainerHeapAllocator::s_alloc,
                                          &v9);
    entitiesOut->m_capacityAndFlags = v9 / 8;
  }
  m_size = m_constraintInstance->m_chainedEntities.m_size;
  m_data = entitiesOut->m_data;
  entitiesOut->m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)m_constraintInstance->m_chainedEntities.m_data - (char *)m_data;
    do
    {
      v8 = *(hkpEntity **)((char *)m_data++ + v7);
      *(m_data - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

