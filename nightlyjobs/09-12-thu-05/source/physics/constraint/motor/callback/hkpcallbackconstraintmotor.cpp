// File Line: 16
// RVA: 0xD4B2E0
void __fastcall hkpCallbackConstraintMotor::hkpCallbackConstraintMotor(hkpCallbackConstraintMotor *this, hkpCallbackConstraintMotor::CallbackType callbackType, void (__fastcall *callbackFunc)(hkpCallbackConstraintMotor *, hkpConstraintMotorInput *, hkpConstraintMotorOutput *))
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCallbackConstraintMotor::`vftable;
  this->m_callbackType.m_storage = callbackType;
  this->m_type.m_storage = 4;
  this->m_minForce = -1000000.0;
  this->m_maxForce = 1000000.0;
  this->m_callbackFunc = callbackFunc;
}

// File Line: 23
// RVA: 0xD4B320
hkpConstraintMotor *__fastcall hkpCallbackConstraintMotor::clone(hkpCallbackConstraintMotor *this)
{
  hkpCallbackConstraintMotor *v1; // rbx
  _QWORD **v2; // rax
  hkpConstraintMotor *result; // rax
  float v4; // ecx

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpConstraintMotor *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 72i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpConstraintMotor::`vftable;
    result->m_type.m_storage = v1->m_type.m_storage;
    result->vfptr = (hkBaseObjectVtbl *)&hkpLimitedForceConstraintMotor::`vftable;
    *(float *)&result[1].vfptr = v1->m_minForce;
    v4 = v1->m_maxForce;
    result->vfptr = (hkBaseObjectVtbl *)&hkpCallbackConstraintMotor::`vftable;
    *((float *)&result[1].vfptr + 1) = v4;
    *(_QWORD *)&result[1].m_memSizeAndFlags = v1->m_callbackFunc;
    *(_DWORD *)&result[1].m_type.m_storage = v1->m_callbackType.m_storage;
    result[2].vfptr = (hkBaseObjectVtbl *)v1->m_userData0;
    *(_QWORD *)&result[2].m_memSizeAndFlags = v1->m_userData1;
    *(_QWORD *)&result[2].m_type.m_storage = v1->m_userData2;
  }
  return result;
}

