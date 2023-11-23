// File Line: 14
// RVA: 0xD4DBD0
void __fastcall hkpRotationalConstraintData::hkpRotationalConstraintData(hkpRotationalConstraintData *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRotationalConstraintData::`vftable;
  this->m_atoms.m_rotations.m_type.m_storage = 4;
  this->m_atoms.m_ang.m_type.m_storage = 13;
  this->m_atoms.m_rotations.m_rotationA.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_rotations.m_rotationA.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_rotations.m_rotationA.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col0 = (hkVector4f)transform.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col1 = (hkVector4f)direction.m_quad;
  this->m_atoms.m_rotations.m_rotationB.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  *(_WORD *)&this->m_atoms.m_ang.m_firstConstrainedAxis = 768;
}

// File Line: 23
// RVA: 0xD4DC90
void __fastcall hkpRotationalConstraintData::setInWorldSpace(
        hkpRotationalConstraintData *this,
        hkQuaternionf *bodyARotation,
        hkQuaternionf *bodyBRotation)
{
  hkRotationf::set(&this->m_atoms.m_rotations.m_rotationA, bodyARotation);
  hkRotationf::set(&this->m_atoms.m_rotations.m_rotationB, bodyBRotation);
}

// File Line: 29
// RVA: 0xD4DC60
void __fastcall hkpRotationalConstraintData::setInBodySpace(hkpRotationalConstraintData *this, hkQuaternionf *aTb)
{
  hkRotationf *p_m_rotationB; // rcx

  p_m_rotationB = &this->m_atoms.m_rotations.m_rotationB;
  p_m_rotationB[-1].m_col0 = (hkVector4f)transform.m_quad;
  p_m_rotationB[-1].m_col1 = (hkVector4f)direction.m_quad;
  p_m_rotationB[-1].m_col2 = (hkVector4f)stru_141A71280.m_quad;
  hkRotationf::set(p_m_rotationB, aTb);
}

// File Line: 35
// RVA: 0xD4DD50
void __fastcall hkpRotationalConstraintData::getConstraintInfo(
        hkpRotationalConstraintData *this,
        hkpConstraintData::ConstraintInfo *infoOut)
{
  hkpConstraintData::getConstraintInfoUtil(&this->m_atoms.m_rotations, 0x80u, infoOut);
}

// File Line: 40
// RVA: 0xD4DD70
void __fastcall hkpRotationalConstraintData::getRuntimeInfo(
        hkpRotationalConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  if ( wantRuntime.m_bool )
  {
    infoOut->m_numSolverResults = 3;
    infoOut->m_sizeOfExternalRuntime = 24;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 54
// RVA: 0xD4DCE0
hkBool *__fastcall hkpRotationalConstraintData::isValid(hkpRotationalConstraintData *this, hkBool *result)
{
  if ( hkRotationf::isOrthonormal(&this->m_atoms.m_rotations.m_rotationA, 0.0000099999997)
    && hkRotationf::isOrthonormal(&this->m_atoms.m_rotations.m_rotationB, 0.0000099999997) )
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

// File Line: 59
// RVA: 0xD4DCD0
__int64 __fastcall hkpRotationalConstraintData::getType(hkpRotationalConstraintData *this)
{
  return 16i64;
}

