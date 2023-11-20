// File Line: 14
// RVA: 0xD45370
void __fastcall hkpStiffSpringConstraintData::hkpStiffSpringConstraintData(hkpStiffSpringConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpStiffSpringConstraintData::`vftable';
  this->m_userData = 0i64;
  this->m_atoms.m_pivots.m_type.m_storage = 3;
  this->m_atoms.m_setupStabilization.m_type.m_storage = 23;
  this->m_atoms.m_setupStabilization.m_maxLinImpulse = 3.40282e38;
  this->m_atoms.m_setupStabilization.m_maxAngImpulse = 3.40282e38;
  this->m_atoms.m_setupStabilization.m_maxAngle = 1.8446726e19;
  this->m_atoms.m_spring.m_type.m_storage = 6;
  this->m_atoms.m_pivots.m_translationA = 0i64;
  this->m_atoms.m_pivots.m_translationB = 0i64;
  this->m_atoms.m_setupStabilization.m_enabled.m_bool = 1;
  *(_QWORD *)&this->m_atoms.m_spring.m_length = 0i64;
}

// File Line: 23
// RVA: 0xD45420
void __fastcall hkpStiffSpringConstraintData::getConstraintInfo(hkpStiffSpringConstraintData *this, hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil((hkpConstraintAtom *)&this->m_atoms.m_pivots.m_type, 76, infoOut);
}

// File Line: 29
// RVA: 0xD45440
void __fastcall hkpStiffSpringConstraintData::getRuntimeInfo(hkpStiffSpringConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  if ( wantRuntime.m_bool )
  {
    infoOut->m_numSolverResults = 1;
    infoOut->m_sizeOfExternalRuntime = 8;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 44
// RVA: 0xD453E0
hkBool *__fastcall hkpStiffSpringConstraintData::isValid(hkpStiffSpringConstraintData *this, hkBool *result)
{
  float v2; // xmm1_4
  hkBool *v3; // rax

  v2 = this->m_atoms.m_spring.m_length;
  if ( v2 <= 0.0 || v2 > this->m_atoms.m_spring.m_maxLength )
  {
    result->m_bool = 0;
    v3 = result;
  }
  else
  {
    result->m_bool = 1;
    v3 = result;
  }
  return v3;
}

// File Line: 50
// RVA: 0xD45410
signed __int64 __fastcall hkpStiffSpringConstraintData::getType(hkpStiffSpringConstraintData *this)
{
  return 8i64;
}

