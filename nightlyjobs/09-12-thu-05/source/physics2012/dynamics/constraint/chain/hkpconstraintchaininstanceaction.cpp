// File Line: 16
// RVA: 0xD789B0
void __fastcall hkpConstraintChainInstanceAction::applyAction(hkpConstraintChainInstanceAction *this, hkStepInfo *stepInfo)
{
  ;
}

// File Line: 22
// RVA: 0xD789C0
hkpAction *__fastcall hkpConstraintChainInstanceAction::clone(hkpConstraintChainInstanceAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *newEntities, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  return 0i64;
}

// File Line: 28
// RVA: 0xD789D0
void __fastcall hkpConstraintChainInstanceAction::entityRemovedCallback(hkpConstraintChainInstanceAction *this, hkpEntity *entity)
{
  this->m_constraintInstance->vfptr[2].__vecDelDtor((hkBaseObject *)this->m_constraintInstance, (unsigned int)entity);
}

// File Line: 36
// RVA: 0xD789F0
void __fastcall hkpConstraintChainInstanceAction::getEntities(hkpConstraintChainInstanceAction *this, hkArray<hkpEntity *,hkContainerHeapAllocator> *entitiesOut)
{
  hkpConstraintChainInstance *v2; // rbx
  hkArray<hkpEntity *,hkContainerHeapAllocator> *v3; // rdi
  __int64 v4; // rcx
  hkpEntity **v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkpEntity *v8; // rcx
  int v9; // [rsp+30h] [rbp+8h]

  v2 = this->m_constraintInstance;
  v3 = entitiesOut;
  if ( (entitiesOut->m_capacityAndFlags & 0x3FFFFFFF) < v2->m_chainedEntities.m_size )
  {
    if ( entitiesOut->m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        entitiesOut->m_data,
        8 * entitiesOut->m_capacityAndFlags);
    v9 = 8 * v2->m_chainedEntities.m_size;
    v3->m_data = (hkpEntity **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                 &v9);
    v3->m_capacityAndFlags = v9 / 8;
  }
  v4 = v2->m_chainedEntities.m_size;
  v5 = v3->m_data;
  v3->m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v2->m_chainedEntities.m_data - (char *)v5);
    do
    {
      v8 = *(hkpEntity **)((char *)v5 + (_QWORD)v7);
      ++v5;
      *(v5 - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

