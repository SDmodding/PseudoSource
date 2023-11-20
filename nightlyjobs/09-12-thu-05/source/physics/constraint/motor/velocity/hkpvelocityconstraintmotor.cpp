// File Line: 14
// RVA: 0xD4DEA0
hkpConstraintMotor *__fastcall hkpVelocityConstraintMotor::clone(hkpVelocityConstraintMotor *this)
{
  hkpVelocityConstraintMotor *v1; // rbx
  _QWORD **v2; // rax
  hkpConstraintMotor *result; // rax
  float v4; // ecx

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 48i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpConstraintMotor::`vftable;
    result->m_type.m_storage = v1->m_type.m_storage;
    result->vfptr = (hkBaseObjectVtbl *)&hkpLimitedForceConstraintMotor::`vftable;
    *(float *)&result[1].vfptr = v1->m_minForce;
    v4 = v1->m_maxForce;
    result->vfptr = (hkBaseObjectVtbl *)&hkpVelocityConstraintMotor::`vftable;
    *((float *)&result[1].vfptr + 1) = v4;
    *(float *)&result[1].m_memSizeAndFlags = v1->m_tau;
    *(float *)(&result[1].m_referenceCount + 1) = v1->m_velocityTarget;
    result[1].m_type.m_storage = v1->m_useVelocityTargetFromConstraintTargets.m_bool;
  }
  return result;
}

