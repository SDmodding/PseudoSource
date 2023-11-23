// File Line: 15
// RVA: 0xD4DD90
void __fastcall hkpSpringDamperConstraintMotor::hkpSpringDamperConstraintMotor(hkpSpringDamperConstraintMotor *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSpringDamperConstraintMotor::`vftable;
  this->m_type.m_storage = 3;
  this->m_springDamping = 0.0;
  this->m_minForce = -1000000.0;
  *(_QWORD *)&this->m_maxForce = 1232348160i64;
}

// File Line: 25
// RVA: 0xD4DDD0
void __fastcall hkpSpringDamperConstraintMotor::hkpSpringDamperConstraintMotor(
        hkpSpringDamperConstraintMotor *this,
        float springConstant,
        float springDamping,
        float maxForce)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSpringDamperConstraintMotor::`vftable;
  this->m_type.m_storage = 3;
  this->m_maxForce = maxForce;
  this->m_springConstant = springConstant;
  this->m_springDamping = springDamping;
  LODWORD(this->m_minForce) = LODWORD(maxForce) ^ _xmm[0];
}

// File Line: 33
// RVA: 0xD4DE20
hkpConstraintMotor *__fastcall hkpSpringDamperConstraintMotor::clone(hkpSpringDamperConstraintMotor *this)
{
  _QWORD **Value; // rax
  hkpConstraintMotor *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpConstraintMotor::`vftable;
    result->m_type.m_storage = this->m_type.m_storage;
    result->vfptr = (hkBaseObjectVtbl *)&hkpLimitedForceConstraintMotor::`vftable;
    *(float *)&result[1].vfptr = this->m_minForce;
    HIDWORD(result[1].vfptr) = LODWORD(this->m_maxForce);
    result->vfptr = (hkBaseObjectVtbl *)&hkpSpringDamperConstraintMotor::`vftable;
    *(float *)&result[1].m_memSizeAndFlags = this->m_springConstant;
    *(float *)(&result[1].m_referenceCount + 1) = this->m_springDamping;
  }
  return result;
}

