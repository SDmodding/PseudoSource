// File Line: 14
// RVA: 0xD4A8B0
void __fastcall hkpPulleyConstraintData::hkpPulleyConstraintData(hkpPulleyConstraintData *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpPulleyConstraintData::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->m_atoms.m_translations.m_type.m_storage = 3;
  this->m_atoms.m_pulley.m_type.m_storage = 20;
  this->m_atoms.m_pulley.m_ropeLength = 0.0;
  this->m_atoms.m_pulley.m_leverageOnBodyB = 1.0;
  this->m_atoms.m_translations.m_translationA = 0i64;
  this->m_atoms.m_translations.m_translationB = 0i64;
  this->m_atoms.m_pulley.m_fixedPivotAinWorld = 0i64;
  this->m_atoms.m_pulley.m_fixedPivotBinWorld = 0i64;
}

// File Line: 24
// RVA: 0xD4A950
void __fastcall hkpPulleyConstraintData::getConstraintInfo(hkpPulleyConstraintData *this, hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil((hkpConstraintAtom *)&this->m_atoms.m_translations.m_type, 112, infoOut);
}

// File Line: 29
// RVA: 0xD4A970
void __fastcall hkpPulleyConstraintData::getRuntimeInfo(hkpPulleyConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
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

// File Line: 43
// RVA: 0xD4A920
hkBool *__fastcall hkpPulleyConstraintData::isValid(hkpPulleyConstraintData *this, hkBool *result)
{
  hkBool *v2; // rax

  if ( this->m_atoms.m_pulley.m_ropeLength <= 0.0 || this->m_atoms.m_pulley.m_leverageOnBodyB <= 0.0 )
  {
    result->m_bool = 0;
    v2 = result;
  }
  else
  {
    result->m_bool = 1;
    v2 = result;
  }
  return v2;
}

// File Line: 48
// RVA: 0xD4A910
signed __int64 __fastcall hkpPulleyConstraintData::getType(hkpPulleyConstraintData *this)
{
  return 15i64;
}

