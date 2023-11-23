// File Line: 46
// RVA: 0xE110F0
void __fastcall hkpEaseConstraintsAction::~hkpEaseConstraintsAction(hkpEaseConstraintsAction *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpEaseConstraintsAction::`vftable;
  m_capacityAndFlags = this->m_originalLimits.m_capacityAndFlags;
  this->m_originalLimits.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_originalLimits.m_data,
      4 * m_capacityAndFlags);
  this->m_originalLimits.m_data = 0i64;
  this->m_originalLimits.m_capacityAndFlags = 0x80000000;
  v3 = this->m_originalConstraints.m_capacityAndFlags;
  this->m_originalConstraints.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_originalConstraints.m_data,
      8 * v3);
  this->m_originalConstraints.m_data = 0i64;
  this->m_originalConstraints.m_capacityAndFlags = 0x80000000;
  hkpArrayAction::~hkpArrayAction(this);
}

// File Line: 73
// RVA: 0xE11260
hkBool *__fastcall hkpEaseConstraintsAction::CollectSupportedConstraints::collectConstraint(
        hkpEaseConstraintsAction::CollectSupportedConstraints *this,
        hkBool *result,
        hkpConstraintInstance *constraint)
{
  hkBool resulta; // [rsp+38h] [rbp+10h] BYREF

  if ( hkpConstraintInstance::isEnabled(constraint, &resulta)->m_bool
    && (((unsigned int (__fastcall *)(hkpConstraintData *))constraint->m_data->vfptr[1].__first_virtual_table_function__)(constraint->m_data) == 7
     || ((unsigned int (__fastcall *)(hkpConstraintData *))constraint->m_data->vfptr[1].__first_virtual_table_function__)(constraint->m_data) == 2) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

