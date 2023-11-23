// File Line: 26
// RVA: 0xD63C70
void __fastcall hkpBreakableConstraintData::hkpBreakableConstraintData(
        hkpBreakableConstraintData *this,
        hkpConstraintData *constraintData)
{
  __int64 v3; // rdx
  unsigned __int16 v4; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int16 v5; // [rsp+34h] [rbp+Ch]

  this->m_memSizeAndFlags = -1;
  this->m_userData = 0i64;
  this->m_referenceCount = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableConstraintData::`vftable;
  this->m_atoms.m_bridgeAtom.m_type.m_storage = 1;
  this->m_constraintData = constraintData;
  this->m_solverResultLimit = 10.0;
  *(_WORD *)&this->m_removeWhenBroken.m_bool = 0;
  hkReferencedObject::addReference(constraintData);
  LOBYTE(v3) = 1;
  ((void (__fastcall *)(hkpConstraintData *, __int64, unsigned __int16 *))this->m_constraintData->vfptr[8].__first_virtual_table_function__)(
    this->m_constraintData,
    v3,
    &v4);
  this->m_childRuntimeSize = v4;
  this->m_childNumSolverResults = v5;
  hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this);
}

// File Line: 39
// RVA: 0xD641F0
void __fastcall hkpBreakableConstraintData::hkpBreakableConstraintData(
        hkpBreakableConstraintData *this,
        hkFinishLoadedObjectFlag f)
{
  hkpConstraintData::hkpConstraintData(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableConstraintData::`vftable;
  if ( f.m_finishing )
  {
    hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this->m_atoms.m_bridgeAtom.m_constraintData);
    if ( f.m_finishing )
      hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this);
  }
}

// File Line: 48
// RVA: 0xD63D10
void __fastcall hkpBreakableConstraintData::~hkpBreakableConstraintData(hkpBreakableConstraintData *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableConstraintData::`vftable;
  hkReferencedObject::removeReference(this->m_constraintData);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 53
// RVA: 0xD64000
void __fastcall hkpBreakableConstraintData::buildJacobianCallback(
        hkpBreakableConstraintData *this,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  struct hkpConstraintRuntime *m_storage; // rbx
  __int64 m_childNumSolverResults; // rbp
  char *v5; // rsi
  __m128 v8; // xmm3
  struct hkpConstraintRuntime *v9; // rax
  __int64 v10; // rcx
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  __m128 v13; // xmm6
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  hkpVelocityAccumulator *v16; // rax
  hkpVelocityAccumulator *v17; // rcx
  __m128 v18; // xmm1
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __int64 i; // rax

  m_storage = out->m_constraintRuntime.m_storage;
  m_childNumSolverResults = this->m_childNumSolverResults;
  v5 = (char *)m_storage + this->m_childRuntimeSize;
  if ( !*v5 )
  {
    v8 = 0i64;
    if ( this->m_childNumSolverResults )
    {
      v9 = out->m_constraintRuntime.m_storage;
      v10 = this->m_childNumSolverResults;
      do
      {
        v11 = (__m128)*(unsigned int *)v9;
        v9 = (struct hkpConstraintRuntime *)((char *)v9 + 8);
        v12 = _mm_shuffle_ps(v11, v11, 0);
        v8 = _mm_add_ps(v8, _mm_mul_ps(v12, v12));
        --v10;
      }
      while ( v10 );
    }
    v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_solverResultLimit), (__m128)LODWORD(this->m_solverResultLimit), 0);
    if ( v8.m128_f32[0] > (float)(v13.m128_f32[0] * v13.m128_f32[0]) )
    {
      v14 = _mm_rsqrt_ps(v8);
      v15 = _mm_andnot_ps(
              _mm_cmple_ps(v8, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v8), v14)),
                  _mm_mul_ps(*(__m128 *)_xmm, v14)),
                v8));
      hkpBreakableConstraintData::setBroken(this, in->m_constraintInstance.m_storage, (hkBool)1, v15.m128_f32[0]);
      if ( this->m_revertBackVelocityOnBreak.m_bool )
      {
        v16 = in->m_bodyA.m_storage;
        v17 = in->m_bodyB.m_storage;
        v18 = _mm_rcp_ps(v15);
        v19 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v15)), v18), v13);
        v20 = _mm_movelh_ps((__m128)*(unsigned __int64 *)(v5 + 4), (__m128)*((unsigned int *)v5 + 3));
        v21 = _mm_movelh_ps((__m128)*((unsigned __int64 *)v5 + 2), (__m128)*((unsigned int *)v5 + 6));
        v22 = _mm_movelh_ps((__m128)*(unsigned __int64 *)(v5 + 28), (__m128)*((unsigned int *)v5 + 9));
        v23 = _mm_movelh_ps((__m128)*((unsigned __int64 *)v5 + 5), (__m128)*((unsigned int *)v5 + 12));
        v16->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16->m_linearVel.m_quad, v20), v19), v20);
        v17->m_linearVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17->m_linearVel.m_quad, v21), v19), v21);
        v16->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16->m_angularVel.m_quad, v22), v19), v22);
        v17->m_angularVel.m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17->m_angularVel.m_quad, v23), v19), v23);
      }
    }
  }
  for ( i = 0i64; i < m_childNumSolverResults; ++i )
    *((_DWORD *)m_storage + 2 * i) = 0;
}

// File Line: 104
// RVA: 0xD63D50
void __fastcall hkpBreakableConstraintData::setBroken(
        hkpBreakableConstraintData *this,
        hkpConstraintInstance *instance,
        hkBool broken,
        float currentForce)
{
  hkBool *v4; // r10
  hkConstraintInternal *m_internal; // rax
  hkpConstraintOwner *m_owner; // rax
  hkpWorld *vfptr; // rbx
  float m_solverResultLimit; // xmm0_4
  hkpConstraintBrokenEvent event; // [rsp+20h] [rbp-38h] BYREF

  v4 = (hkBool *)instance->m_internal->m_runtime + this->m_childRuntimeSize;
  if ( (broken.m_bool != 0) != (v4->m_bool != 0) )
  {
    v4->m_bool = broken.m_bool;
    m_internal = instance->m_internal;
    if ( broken.m_bool )
      m_internal->m_callbackRequest &= ~4u;
    else
      m_internal->m_callbackRequest |= 4u;
    m_owner = instance->m_owner;
    event.m_constraintInstance = instance;
    event.m_eventSourceDetails = 0i64;
    vfptr = (hkpWorld *)m_owner[1].vfptr;
    event.m_world = vfptr;
    event.m_eventSource = &hkpBreakableConstraintDataClass;
    if ( broken.m_bool )
    {
      m_solverResultLimit = this->m_solverResultLimit;
      event.m_actualImpulse = currentForce;
      event.m_impulseLimit = m_solverResultLimit;
      if ( instance->m_listeners.m_size )
        hkpConstraintCallbackUtil::fireConstraintBroken(&event);
      hkpWorldCallbackUtil::fireConstraintBroken(vfptr, &event);
    }
    else
    {
      if ( instance->m_listeners.m_size )
        hkpConstraintCallbackUtil::fireConstraintRepaired((hkpConstraintRepairedEvent *)&event);
      hkpWorldCallbackUtil::fireConstraintRepaired(vfptr, (hkpConstraintRepairedEvent *)&event);
    }
  }
}

// File Line: 154
// RVA: 0xD63ED0
void __fastcall hkpBreakableConstraintData::buildJacobian(
        hkpBreakableConstraintData *this,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  char *v5; // rdx
  hkpVelocityAccumulator *m_storage; // rax
  hkpVelocityAccumulator *v8; // r9
  __m128 m_quad; // xmm1
  char v10[16]; // [rsp+20h] [rbp-28h] BYREF
  hkpSimpleContactConstraintAtom *atom; // [rsp+30h] [rbp-18h]
  int sizeOfAllAtoms; // [rsp+38h] [rbp-10h]
  int v13; // [rsp+3Ch] [rbp-Ch]
  hkBool result; // [rsp+50h] [rbp+8h] BYREF

  v5 = (char *)out->m_constraintRuntime.m_storage + this->m_childRuntimeSize;
  if ( *v5 )
  {
    hkpBreakableConstraintData::buildNopJacobian(this, in, out);
    if ( this->m_removeWhenBroken.m_bool )
      hkpWorld::removeConstraint(
        in->m_constraintInstance.m_storage->m_entities[0]->m_world,
        &result,
        in->m_constraintInstance.m_storage);
  }
  else
  {
    m_storage = in->m_bodyA.m_storage;
    v8 = in->m_bodyB.m_storage;
    *(_QWORD *)(v5 + 4) = m_storage->m_linearVel.m_quad.m128_u64[0];
    *((_DWORD *)v5 + 3) = _mm_movehl_ps(m_storage->m_linearVel.m_quad, m_storage->m_linearVel.m_quad).m128_u32[0];
    *((_QWORD *)v5 + 2) = v8->m_linearVel.m_quad.m128_u64[0];
    *((_DWORD *)v5 + 6) = _mm_movehl_ps(v8->m_linearVel.m_quad, v8->m_linearVel.m_quad).m128_u32[0];
    *(_QWORD *)(v5 + 28) = m_storage->m_angularVel.m_quad.m128_u64[0];
    *((_DWORD *)v5 + 9) = _mm_movehl_ps(m_storage->m_angularVel.m_quad, m_storage->m_angularVel.m_quad).m128_u32[0];
    *((_QWORD *)v5 + 5) = v8->m_angularVel.m_quad.m128_u64[0];
    m_quad = v8->m_angularVel.m_quad;
    v13 = 0;
    *((_DWORD *)v5 + 12) = _mm_movehl_ps(m_quad, m_quad).m128_u32[0];
    this->m_constraintData->vfptr[2].__vecDelDtor(this->m_constraintData, (unsigned int)v10);
    if ( atom->m_type.m_storage == 29 )
      hkSimpleContactConstraintDataBuildJacobian(atom, in, (hkBool)1, out);
    else
      hkSolverBuildJacobianFromAtomsNotContact(atom, sizeOfAllAtoms, in, out);
  }
}

// File Line: 190
// RVA: 0xD63EA0
void __fastcall hkpBreakableConstraintData::buildNopJacobian(
        hkpBreakableConstraintData *this,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  in->m_beginConstraints(in, out, 0i64, 8);
}

// File Line: 198
// RVA: 0xD641B0
void __fastcall hkpBreakableConstraintData::getConstraintInfo(
        hkpBreakableConstraintData *this,
        hkpConstraintData::ConstraintInfo *info)
{
  ((void (__fastcall *)(hkpConstraintData *))this->m_constraintData->vfptr[2].__vecDelDtor)(this->m_constraintData);
  info->m_atoms = &this->m_atoms.m_bridgeAtom;
  info->m_sizeOfAllAtoms = 32;
}

// File Line: 206
// RVA: 0xD63E80
void __fastcall hkpBreakableConstraintData::getRuntimeInfo(
        hkpBreakableConstraintData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = this->m_childNumSolverResults;
  infoOut->m_sizeOfExternalRuntime = this->m_childRuntimeSize + 52;
}

// File Line: 212
// RVA: 0xD63E40
hkBool *__fastcall hkpBreakableConstraintData::isValid(hkpBreakableConstraintData *this, hkBool *result)
{
  this->m_constraintData->vfptr[2].__first_virtual_table_function__(this->m_constraintData);
  return result;
}

// File Line: 218
// RVA: 0xD63E70
__int64 __fastcall hkpBreakableConstraintData::getType(hkpBreakableConstraintData *this)
{
  return 12i64;
}

