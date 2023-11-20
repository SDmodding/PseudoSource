// File Line: 46
// RVA: 0xE110F0
void __fastcall hkpEaseConstraintsAction::~hkpEaseConstraintsAction(hkpEaseConstraintsAction *this)
{
  hkpEaseConstraintsAction *v1; // rbx
  int v2; // er8
  int v3; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEaseConstraintsAction::`vftable;
  v2 = this->m_originalLimits.m_capacityAndFlags;
  this->m_originalLimits.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_originalLimits.m_data,
      4 * v2);
  v1->m_originalLimits.m_data = 0i64;
  v1->m_originalLimits.m_capacityAndFlags = 2147483648;
  v3 = v1->m_originalConstraints.m_capacityAndFlags;
  v1->m_originalConstraints.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_originalConstraints.m_data,
      8 * v3);
  v1->m_originalConstraints.m_data = 0i64;
  v1->m_originalConstraints.m_capacityAndFlags = 2147483648;
  hkpArrayAction::~hkpArrayAction((hkpArrayAction *)&v1->vfptr);
}

// File Line: 73
// RVA: 0xE11260
hkBool *__fastcall hkpEaseConstraintsAction::CollectSupportedConstraints::collectConstraint(hkpEaseConstraintsAction::CollectSupportedConstraints *this, hkBool *result, hkpConstraintInstance *constraint)
{
  hkBool *v3; // rbx
  hkpConstraintInstance *v4; // rdi
  hkBool *v5; // rax
  hkBool resulta; // [rsp+38h] [rbp+10h]

  v3 = result;
  v4 = constraint;
  if ( hkpConstraintInstance::isEnabled(constraint, &resulta)->m_bool
    && (((unsigned int (*)(void))v4->m_data->vfptr[1].__first_virtual_table_function__)() == 7
     || ((unsigned int (*)(void))v4->m_data->vfptr[1].__first_virtual_table_function__)() == 2) )
  {
    v3->m_bool = 1;
    v5 = v3;
  }
  else
  {
    v3->m_bool = 0;
    v5 = v3;
  }
  return v5;
}

