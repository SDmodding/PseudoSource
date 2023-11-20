// File Line: 31
// RVA: 0xD971B0
void __fastcall hkpDeferredConstraintOwner::addConstraintToCriticalLockedIsland(hkpDeferredConstraintOwner *this, hkpConstraintInstance *constraint)
{
  ++this->m_constraintAddRemoveCounter.m_storage;
  this->m_constraintForCommand.m_storage = constraint;
}

// File Line: 42
// RVA: 0xD971C0
void __fastcall hkpDeferredConstraintOwner::removeConstraintFromCriticalLockedIsland(hkpDeferredConstraintOwner *this, hkpConstraintInstance *constraint)
{
  --this->m_constraintAddRemoveCounter.m_storage;
  this->m_constraintForCommand.m_storage = constraint;
}

// File Line: 53
// RVA: 0xD97190
void __fastcall hkpDeferredConstraintOwner::addCallbackRequest(hkpDeferredConstraintOwner *this, hkpConstraintInstance *constraint, int request)
{
  hkConstraintInternal *v3; // rax

  v3 = constraint->m_internal;
  if ( v3 )
    v3->m_callbackRequest |= request;
  else
    this->m_callbackRequestForAddConstraint.m_storage |= request;
}

