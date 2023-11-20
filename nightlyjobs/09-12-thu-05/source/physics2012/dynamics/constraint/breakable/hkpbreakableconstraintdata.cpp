// File Line: 26
// RVA: 0xD63C70
void __fastcall hkpBreakableConstraintData::hkpBreakableConstraintData(hkpBreakableConstraintData *this, hkpConstraintData *constraintData)
{
  hkpBreakableConstraintData *v2; // rdi
  __int64 v3; // rdx
  unsigned __int16 v4; // [rsp+30h] [rbp+8h]
  unsigned __int16 v5; // [rsp+34h] [rbp+Ch]

  v2 = this;
  this->m_memSizeAndFlags = -1;
  this->m_userData = 0i64;
  this->m_referenceCount = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableConstraintData::`vftable';
  this->m_atoms.m_bridgeAtom.m_type.m_storage = 1;
  this->m_constraintData = constraintData;
  this->m_solverResultLimit = 10.0;
  *(_WORD *)&this->m_removeWhenBroken.m_bool = 0;
  hkReferencedObject::addReference((hkReferencedObject *)&constraintData->vfptr);
  LOBYTE(v3) = 1;
  ((void (__fastcall *)(hkpConstraintData *, __int64, unsigned __int16 *))v2->m_constraintData->vfptr[8].__first_virtual_table_function__)(
    v2->m_constraintData,
    v3,
    &v4);
  v2->m_childRuntimeSize = v4;
  v2->m_childNumSolverResults = v5;
  hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, (hkpConstraintData *)&v2->vfptr);
}

// File Line: 39
// RVA: 0xD641F0
void __fastcall hkpBreakableConstraintData::hkpBreakableConstraintData(hkpBreakableConstraintData *this, hkFinishLoadedObjectFlag f)
{
  hkpBreakableConstraintData *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = f.m_finishing;
  v2 = this;
  hkpConstraintData::hkpConstraintData((hkpConstraintData *)&this->vfptr, f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpBreakableConstraintData::`vftable';
  if ( v3 )
  {
    hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, v2->m_atoms.m_bridgeAtom.m_constraintData);
    if ( v3 )
      hkpBridgeConstraintAtom::init(&v2->m_atoms.m_bridgeAtom, (hkpConstraintData *)&v2->vfptr);
  }
}

// File Line: 48
// RVA: 0xD63D10
void __fastcall hkpBreakableConstraintData::~hkpBreakableConstraintData(hkpBreakableConstraintData *this)
{
  hkpBreakableConstraintData *v1; // rbx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableConstraintData::`vftable';
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_constraintData->vfptr);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 53
// RVA: 0xD64000
void __fastcall hkpBreakableConstraintData::buildJacobianCallback(hkpBreakableConstraintData *this, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  struct hkpConstraintRuntime *v3; // rbx
  __int64 v4; // rbp
  char *v5; // rsi
  hkpBreakableConstraintData *v6; // rdi
  hkpConstraintQueryIn *v7; // r14
  __m128 v8; // xmm3
  struct hkpConstraintRuntime *v9; // rax
  __int64 v10; // rcx
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  __m128 v13; // xmm6
  __m128 v14; // xmm1
  __m128 v15; // xmm7
  __m128 *v16; // rax
  __m128 *v17; // rcx
  __m128 v18; // xmm1
  __m128 v19; // xmm5
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __int64 i; // rax

  v3 = out->m_constraintRuntime.m_storage;
  v4 = this->m_childNumSolverResults;
  v5 = (char *)v3 + this->m_childRuntimeSize;
  v6 = this;
  v7 = in;
  if ( !*v5 )
  {
    v8 = 0i64;
    if ( (signed int)v4 > 0 )
    {
      v9 = out->m_constraintRuntime.m_storage;
      v10 = (unsigned int)v4;
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
    v13 = _mm_shuffle_ps((__m128)LODWORD(v6->m_solverResultLimit), (__m128)LODWORD(v6->m_solverResultLimit), 0);
    if ( v8.m128_f32[0] > (float)(v13.m128_f32[0] * v13.m128_f32[0]) )
    {
      v14 = _mm_rsqrt_ps(v8);
      v15 = _mm_andnot_ps(
              _mm_cmpleps(v8, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v8), v14)),
                  _mm_mul_ps(*(__m128 *)_xmm, v14)),
                v8));
      hkpBreakableConstraintData::setBroken(v6, in->m_constraintInstance.m_storage, (hkBool)1, v15.m128_f32[0]);
      if ( v6->m_revertBackVelocityOnBreak.m_bool )
      {
        v16 = (__m128 *)v7->m_bodyA.m_storage;
        v17 = (__m128 *)v7->m_bodyB.m_storage;
        v18 = _mm_rcp_ps(v15);
        v19 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v18, v15)), v18), v13);
        v20 = _mm_movelh_ps((__m128)*(unsigned __int64 *)(v5 + 4), (__m128)*((unsigned int *)v5 + 3));
        v21 = _mm_movelh_ps((__m128)*((unsigned __int64 *)v5 + 2), (__m128)*((unsigned int *)v5 + 6));
        v22 = _mm_movelh_ps((__m128)*(unsigned __int64 *)(v5 + 28), (__m128)*((unsigned int *)v5 + 9));
        v23 = _mm_movelh_ps((__m128)*((unsigned __int64 *)v5 + 5), (__m128)*((unsigned int *)v5 + 12));
        v16[1] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16[1], v20), v19), v20);
        v17[1] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17[1], v21), v19), v21);
        v16[2] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16[2], v22), v19), v22);
        v17[2] = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v17[2], v23), v19), v23);
      }
    }
  }
  for ( i = 0i64; i < v4; ++i )
    *((_DWORD *)v3 + 2 * i) = 0;
}

// File Line: 104
// RVA: 0xD63D50
void __fastcall hkpBreakableConstraintData::setBroken(hkpBreakableConstraintData *this, hkpConstraintInstance *instance, hkBool broken, float currentForce)
{
  hkBool *v4; // r10
  hkConstraintInternal *v5; // rax
  hkpConstraintOwner *v6; // rax
  hkpWorld *v7; // rbx
  float v8; // xmm0_4
  hkpConstraintBrokenEvent event; // [rsp+20h] [rbp-38h]

  v4 = (hkBool *)instance->m_internal->m_runtime + this->m_childRuntimeSize;
  if ( (broken.m_bool != 0) != (v4->m_bool != 0) )
  {
    v4->m_bool = broken.m_bool;
    v5 = instance->m_internal;
    if ( broken.m_bool )
      v5->m_callbackRequest &= 0xFBu;
    else
      v5->m_callbackRequest |= 4u;
    v6 = instance->m_owner;
    event.m_constraintInstance = instance;
    event.m_eventSourceDetails = 0i64;
    v7 = (hkpWorld *)v6[1].vfptr;
    event.m_world = (hkpWorld *)v6[1].vfptr;
    event.m_eventSource = &hkpBreakableConstraintDataClass;
    if ( broken.m_bool )
    {
      v8 = this->m_solverResultLimit;
      event.m_actualImpulse = currentForce;
      event.m_impulseLimit = v8;
      if ( instance->m_listeners.m_size )
        hkpConstraintCallbackUtil::fireConstraintBroken(&event);
      hkpWorldCallbackUtil::fireConstraintBroken(v7, &event);
    }
    else
    {
      if ( instance->m_listeners.m_size )
        hkpConstraintCallbackUtil::fireConstraintRepaired((hkpConstraintRepairedEvent *)&event);
      hkpWorldCallbackUtil::fireConstraintRepaired(v7, (hkpConstraintRepairedEvent *)&event);
    }
  }
}

// File Line: 154
// RVA: 0xD63ED0
void __fastcall hkpBreakableConstraintData::buildJacobian(hkpBreakableConstraintData *this, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  hkpConstraintQueryIn *v3; // rbx
  hkpConstraintQueryOut *v4; // rdi
  char *v5; // rdx
  hkpBreakableConstraintData *v6; // rsi
  __m128 *v7; // rax
  hkpVelocityAccumulator *v8; // r9
  __m128 v9; // xmm1
  char v10; // [rsp+20h] [rbp-28h]
  hkpSimpleContactConstraintAtom *atom; // [rsp+30h] [rbp-18h]
  int sizeOfAllAtoms; // [rsp+38h] [rbp-10h]
  int v13; // [rsp+3Ch] [rbp-Ch]
  hkBool result; // [rsp+50h] [rbp+8h]

  v3 = in;
  v4 = out;
  v5 = (char *)out->m_constraintRuntime.m_storage + this->m_childRuntimeSize;
  v6 = this;
  if ( *v5 )
  {
    hkpBreakableConstraintData::buildNopJacobian(this, v3, out);
    if ( v6->m_removeWhenBroken.m_bool )
      hkpWorld::removeConstraint(
        v3->m_constraintInstance.m_storage->m_entities[0]->m_world,
        &result,
        v3->m_constraintInstance.m_storage);
  }
  else
  {
    v7 = (__m128 *)v3->m_bodyA.m_storage;
    v8 = v3->m_bodyB.m_storage;
    *(_QWORD *)(v5 + 4) = v7[1];
    *((_DWORD *)v5 + 3) = (unsigned __int128)_mm_movehl_ps(v7[1], v7[1]);
    *((_QWORD *)v5 + 2) = v8->m_linearVel;
    *((_DWORD *)v5 + 6) = (unsigned __int128)_mm_movehl_ps(v8->m_linearVel.m_quad, v8->m_linearVel.m_quad);
    *(_QWORD *)(v5 + 28) = v7[2];
    *((_DWORD *)v5 + 9) = (unsigned __int128)_mm_movehl_ps(v7[2], v7[2]);
    *((_QWORD *)v5 + 5) = v8->m_angularVel;
    v9 = v8->m_angularVel.m_quad;
    v13 = 0;
    *((_DWORD *)v5 + 12) = (unsigned __int128)_mm_movehl_ps(v9, v9);
    this->m_constraintData->vfptr[2].__vecDelDtor((hkBaseObject *)this->m_constraintData, (unsigned int)&v10);
    if ( atom->m_type.m_storage == 29 )
      hkSimpleContactConstraintDataBuildJacobian(atom, v3, (hkBool)1, v4);
    else
      hkSolverBuildJacobianFromAtomsNotContact((hkpConstraintAtom *)&atom->m_type, sizeOfAllAtoms, v3, v4);
  }
}

// File Line: 190
// RVA: 0xD63EA0
void __fastcall hkpBreakableConstraintData::buildNopJacobian(hkpBreakableConstraintData *this, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  in->m_beginConstraints(in, out, 0i64, 8);
}

// File Line: 198
// RVA: 0xD641B0
void __fastcall hkpBreakableConstraintData::getConstraintInfo(hkpBreakableConstraintData *this, hkpConstraintData::ConstraintInfo *info)
{
  hkpBreakableConstraintData *v2; // rbx
  hkpConstraintData::ConstraintInfo *v3; // rdi

  v2 = this;
  v3 = info;
  ((void (*)(void))this->m_constraintData->vfptr[2].__vecDelDtor)();
  v3->m_atoms = (hkpConstraintAtom *)&v2->m_atoms.m_bridgeAtom.m_type;
  v3->m_sizeOfAllAtoms = 32;
}

// File Line: 206
// RVA: 0xD63E80
void __fastcall hkpBreakableConstraintData::getRuntimeInfo(hkpBreakableConstraintData *this, hkBool wantRuntime, hkpConstraintData::RuntimeInfo *infoOut)
{
  infoOut->m_numSolverResults = this->m_childNumSolverResults;
  infoOut->m_sizeOfExternalRuntime = this->m_childRuntimeSize + 52;
}

// File Line: 212
// RVA: 0xD63E40
hkBool *__fastcall hkpBreakableConstraintData::isValid(hkpBreakableConstraintData *this, hkBool *result)
{
  hkBool *v2; // rbx

  v2 = result;
  ((void (*)(void))this->m_constraintData->vfptr[2].__first_virtual_table_function__)();
  return v2;
}

// File Line: 218
// RVA: 0xD63E70
signed __int64 __fastcall hkpBreakableConstraintData::getType(hkpBreakableConstraintData *this)
{
  return 12i64;
}

