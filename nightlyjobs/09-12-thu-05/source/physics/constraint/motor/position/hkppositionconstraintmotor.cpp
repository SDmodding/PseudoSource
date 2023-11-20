// File Line: 15
// RVA: 0xD47F90
void __fastcall hkpPositionConstraintMotor::hkpPositionConstraintMotor(hkpPositionConstraintMotor *this, float currentPosition)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPositionConstraintMotor::`vftable;
  this->m_type.m_storage = 1;
  this->m_minForce = -1000000.0;
  this->m_maxForce = 1000000.0;
  this->m_tau = 0.80000001;
  this->m_damping = 1.0;
  this->m_constantRecoveryVelocity = 1.0;
  this->m_proportionalRecoveryVelocity = 2.0;
}

// File Line: 25
// RVA: 0xD47FE0
hkpConstraintMotor *__fastcall hkpPositionConstraintMotor::clone(hkpPositionConstraintMotor *this)
{
  hkpPositionConstraintMotor *v1; // rbx
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
    result->vfptr = (hkBaseObjectVtbl *)&hkpPositionConstraintMotor::`vftable;
    *((float *)&result[1].vfptr + 1) = v4;
    *(float *)&result[1].m_memSizeAndFlags = v1->m_tau;
    *(float *)(&result[1].m_referenceCount + 1) = v1->m_damping;
    *(float *)&result[1].m_type.m_storage = v1->m_proportionalRecoveryVelocity;
    *((_DWORD *)&result[1].m_type + 1) = LODWORD(v1->m_constantRecoveryVelocity);
  }
  return result;
}

