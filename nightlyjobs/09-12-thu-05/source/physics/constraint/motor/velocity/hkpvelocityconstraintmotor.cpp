// File Line: 14
// RVA: 0xD4DEA0
hkpConstraintMotor *__fastcall hkpVelocityConstraintMotor::clone(hkpVelocityConstraintMotor *this)
{
  _QWORD **Value; // rax
  hkpConstraintMotor *result; // rax
  float m_maxForce; // ecx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpConstraintMotor::`vftable;
    result->m_type.m_storage = this->m_type.m_storage;
    result->vfptr = (hkBaseObjectVtbl *)&hkpLimitedForceConstraintMotor::`vftable;
    *(float *)&result[1].vfptr = this->m_minForce;
    m_maxForce = this->m_maxForce;
    result->vfptr = (hkBaseObjectVtbl *)&hkpVelocityConstraintMotor::`vftable;
    *((float *)&result[1].vfptr + 1) = m_maxForce;
    *(float *)&result[1].m_memSizeAndFlags = this->m_tau;
    *(float *)(&result[1].m_referenceCount + 1) = this->m_velocityTarget;
    result[1].m_type.m_storage = this->m_useVelocityTargetFromConstraintTargets.m_bool;
  }
  return result;
}

