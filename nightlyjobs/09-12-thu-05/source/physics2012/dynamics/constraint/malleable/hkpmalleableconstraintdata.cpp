// File Line: 20
// RVA: 0xD642B0
void __fastcall hkpMalleableConstraintData::hkpMalleableConstraintData(
        hkpMalleableConstraintData *this,
        hkpConstraintData *constraintData)
{
  hkpConstraintData *m_constraintData; // rcx

  this->m_memSizeAndFlags = -1;
  this->m_constraintData = constraintData;
  this->m_referenceCount = 1;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMalleableConstraintData::`vftable;
  this->m_atoms.m_bridgeAtom.m_type.m_storage = 1;
  m_constraintData = this->m_constraintData;
  this->m_strength = 0.0099999998;
  hkReferencedObject::addReference(m_constraintData);
  hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this);
}

// File Line: 27
// RVA: 0xD64510
void __fastcall hkpMalleableConstraintData::hkpMalleableConstraintData(
        hkpMalleableConstraintData *this,
        hkFinishLoadedObjectFlag f)
{
  hkpConstraintData::hkpConstraintData(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkpMalleableConstraintData::`vftable;
  if ( f.m_finishing )
  {
    hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this->m_atoms.m_bridgeAtom.m_constraintData);
    if ( f.m_finishing )
      hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this);
  }
}

// File Line: 35
// RVA: 0xD64320
void __fastcall hkpMalleableConstraintData::~hkpMalleableConstraintData(hkpMalleableConstraintData *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpMalleableConstraintData::`vftable;
  hkReferencedObject::removeReference(this->m_constraintData);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 41
// RVA: 0xD643C0
void __fastcall hkpMalleableConstraintData::getConstraintInfo(
        hkpMalleableConstraintData *this,
        hkpConstraintData::ConstraintInfo *info)
{
  ((void (__fastcall *)(hkpConstraintData *))this->m_constraintData->vfptr[2].__vecDelDtor)(this->m_constraintData);
  info->m_atoms = &this->m_atoms.m_bridgeAtom;
  info->m_sizeOfAllAtoms = 32;
}

// File Line: 53
// RVA: 0xD644F0
void __fastcall hkpMalleableConstraintData::getRuntimeInfo(
        hkpMalleableConstraintData *this,
        __int64 wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  ((void (__fastcall *)(hkpConstraintData *, __int64, hkpConstraintData::RuntimeInfo *))this->m_constraintData->vfptr[8].__first_virtual_table_function__)(
    this->m_constraintData,
    wantRuntime,
    infoOut);
}

// File Line: 59
// RVA: 0xD64420
void __fastcall hkpMalleableConstraintData::buildJacobian(
        hkpMalleableConstraintData *this,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  __int128 v3; // xmm0
  __int128 v4; // xmm1
  __int128 v5; // xmm2
  __int128 v7; // xmm0
  __int128 v8; // xmm1
  hkpConstraintData *m_constraintData; // rcx
  __int128 v10; // xmm0
  hkSimdFloat32 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  char v14[16]; // [rsp+20h] [rbp-B8h] BYREF
  hkpSimpleContactConstraintAtom *atom; // [rsp+30h] [rbp-A8h]
  int sizeOfAllAtoms; // [rsp+38h] [rbp-A0h]
  int v17; // [rsp+3Ch] [rbp-9Ch]
  hkpConstraintQueryIn ina; // [rsp+40h] [rbp-98h] BYREF

  v3 = *(_OWORD *)&in->m_subStepDeltaTime.m_storage;
  v4 = *(_OWORD *)&in->m_frameInvDeltaTime.m_storage;
  v5 = *(_OWORD *)&in->m_rhsFactor.m_storage;
  v17 = 0;
  *(_OWORD *)&ina.m_subStepDeltaTime.m_storage = v3;
  v7 = *(_OWORD *)&in->m_bodyA.m_storage;
  *(_OWORD *)&ina.m_frameInvDeltaTime.m_storage = v4;
  v8 = *(_OWORD *)&in->m_transformA.m_storage;
  *(_OWORD *)&ina.m_rhsFactor.m_storage = v5;
  *(_OWORD *)&ina.m_bodyA.m_storage = v7;
  *(float *)&v5 = in->m_virtMassFactor.m_storage * this->m_strength;
  m_constraintData = this->m_constraintData;
  v10 = *(_OWORD *)&in->m_tau.m_storage;
  *(_OWORD *)&ina.m_transformA.m_storage = v8;
  v11.m_real = (__m128)in->m_maxConstraintViolationSqrd;
  LODWORD(ina.m_virtMassFactor.m_storage) = v5;
  *(_OWORD *)&ina.m_tau.m_storage = v10;
  v12 = *(_OWORD *)&in->m_constraintInstance.m_storage;
  ina.m_maxConstraintViolationSqrd = (hkSimdFloat32)v11.m_real;
  v13 = *(_OWORD *)&in->m_accumulatorAIndex.m_storage;
  *(_OWORD *)&ina.m_constraintInstance.m_storage = v12;
  *(_OWORD *)&ina.m_accumulatorAIndex.m_storage = v13;
  m_constraintData->vfptr[2].__vecDelDtor(m_constraintData, (unsigned int)v14);
  if ( atom->m_type.m_storage == 29 )
    hkSimpleContactConstraintDataBuildJacobian(atom, &ina, (hkBool)1, out);
  else
    hkSolverBuildJacobianFromAtomsNotContact(atom, sizeOfAllAtoms, &ina, out);
}

// File Line: 70
// RVA: 0xD64360
void __fastcall hkpMalleableConstraintData::setStrength(hkpMalleableConstraintData *this, float tau)
{
  this->m_strength = tau;
}

// File Line: 78
// RVA: 0xD64370
float __fastcall hkpMalleableConstraintData::getStrength(hkpMalleableConstraintData *this)
{
  return this->m_strength;
}

// File Line: 86
// RVA: 0xD64380
hkBool *__fastcall hkpMalleableConstraintData::isValid(hkpMalleableConstraintData *this, hkBool *result)
{
  this->m_constraintData->vfptr[2].__first_virtual_table_function__(this->m_constraintData);
  return result;
}

// File Line: 92
// RVA: 0xD643B0
__int64 __fastcall hkpMalleableConstraintData::getType(hkpMalleableConstraintData *this)
{
  return 13i64;
}

// File Line: 98
// RVA: 0xD64400
hkpConstraintData *__fastcall hkpMalleableConstraintData::getWrappedConstraintData(hkpMalleableConstraintData *this)
{
  return this->m_constraintData;
}

// File Line: 103
// RVA: 0xD64410
hkpConstraintData *__fastcall hkpMalleableConstraintData::getWrappedConstraintData(hkpMalleableConstraintData *this)
{
  return this->m_constraintData;
}

