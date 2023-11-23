// File Line: 29
// RVA: 0xD7AD60
void __fastcall hkpStiffSpringChainData::hkpStiffSpringChainData(hkpStiffSpringChainData *this)
{
  hkpBridgeAtoms *p_m_atoms; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_userData = 0i64;
  p_m_atoms = &this->m_atoms;
  *(_QWORD *)&p_m_atoms[-1].m_bridgeAtom.m_type.m_storage = &hkpStiffSpringChainData::`vftable;
  p_m_atoms->m_bridgeAtom.m_type.m_storage = 1;
  this->m_infos.m_data = 0i64;
  this->m_infos.m_size = 0;
  this->m_infos.m_capacityAndFlags = 0x80000000;
  this->m_tau = 0.60000002;
  this->m_damping = 1.0;
  this->m_cfm = 0.000000011920929;
  hkpBridgeConstraintAtom::init(&p_m_atoms->m_bridgeAtom, this);
}

// File Line: 34
// RVA: 0xD7B360
void __fastcall hkpStiffSpringChainData::hkpStiffSpringChainData(
        hkpStiffSpringChainData *this,
        hkFinishLoadedObjectFlag f)
{
  hkpConstraintData::hkpConstraintData(this, f);
  this->vfptr = (hkBaseObjectVtbl *)&hkpStiffSpringChainData::`vftable;
  if ( f.m_finishing )
  {
    hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this->m_atoms.m_bridgeAtom.m_constraintData);
    if ( f.m_finishing )
      hkpBridgeConstraintAtom::init(&this->m_atoms.m_bridgeAtom, this);
  }
}

// File Line: 43
// RVA: 0xD7ADD0
void __fastcall hkpStiffSpringChainData::~hkpStiffSpringChainData(hkpStiffSpringChainData *this)
{
  int m_capacityAndFlags; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkpStiffSpringChainData::`vftable;
  m_capacityAndFlags = this->m_infos.m_capacityAndFlags;
  this->m_infos.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_infos.m_data,
      48 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_infos.m_data = 0i64;
  this->m_infos.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 47
// RVA: 0xD7AE40
__int64 __fastcall hkpStiffSpringChainData::getType(hkpStiffSpringChainData *this)
{
  return 100i64;
}

// File Line: 53
// RVA: 0xD7AE50
void __fastcall hkpStiffSpringChainData::addConstraintInfoInBodySpace(
        hkpStiffSpringChainData *this,
        hkVector4f *pivotInA,
        hkVector4f *pivotInB,
        float springLength)
{
  hkArray<hkpStiffSpringChainData::ConstraintInfo,hkContainerHeapAllocator> *p_m_infos; // rbx
  __int64 m_size; // rcx
  __int64 v8; // rdx
  __m128 m_quad; // xmm1

  p_m_infos = &this->m_infos;
  if ( this->m_infos.m_size == (this->m_infos.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_infos->m_data, 48);
  m_size = p_m_infos->m_size;
  p_m_infos->m_size = m_size + 1;
  v8 = (__int64)&p_m_infos->m_data[m_size];
  *(hkVector4f *)v8 = (hkVector4f)pivotInA->m_quad;
  m_quad = pivotInB->m_quad;
  *(float *)(v8 + 32) = springLength;
  *(__m128 *)(v8 + 16) = m_quad;
}

// File Line: 62
// RVA: 0xD7B2F0
void __fastcall hkpStiffSpringChainData::getConstraintInfo(
        hkpStiffSpringChainData *this,
        hkpConstraintData::ConstraintInfo *info)
{
  int m_size; // ecx

  info->m_sizeOfSchemas = 32;
  info->m_sizeOfAllAtoms = 32;
  info->m_atoms = &this->m_atoms.m_bridgeAtom;
  *(_QWORD *)&info->m_numSolverResults = 0i64;
  info->m_maxSizeOfSchema = 0;
  m_size = this->m_infos.m_size;
  info->m_numSolverResults = m_size;
  info->m_numSolverElemTemps = m_size;
  info->m_sizeOfSchemas = ((80 * m_size + 67) & 0xFFFFFFF0) + 32;
}

// File Line: 84
// RVA: 0xD7B330
void __fastcall hkpStiffSpringChainData::getRuntimeInfo(
        hkpStiffSpringChainData *this,
        hkBool wantRuntime,
        hkpConstraintData::RuntimeInfo *infoOut)
{
  int m_size; // eax

  if ( wantRuntime.m_bool )
  {
    m_size = this->m_infos.m_size;
    infoOut->m_numSolverResults = m_size;
    infoOut->m_sizeOfExternalRuntime = 8 * m_size;
  }
  else
  {
    *infoOut = 0i64;
  }
}

// File Line: 104
// RVA: 0xD7AEE0
void __fastcall hkpStiffSpringChainData::buildJacobian(
        hkpStiffSpringChainData *this,
        hkpStiffSpringChainData *inNotValid,
        hkpConstraintQueryOut *out)
{
  hkpConstraintQueryOut *v3; // r13
  hkpStiffSpringChainData *v4; // rsi
  hkpStiffSpringChainData *v5; // rbx
  __int64 v6; // r12
  hkReferencedObject v7; // xmm0
  __int128 v8; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  hkReferencedObject v11; // xmm0
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  __int128 v14; // xmm1
  unsigned __int64 m_userData; // r15
  __int64 *v16; // rax
  int v17; // r14d
  __int64 v18; // rcx
  __int64 v19; // rax
  hkpVelocityAccumulator *accumBase; // rdi
  hkTransformf *v21; // rax
  hkpJacobianSchema *m_storage; // rcx
  hkp1Lin2AngJacobian *jacobiansEnd; // rax
  __int64 v24; // r10
  hkp1Lin2AngJacobian *v25; // r13
  __m128 *p_m_quad; // rcx
  int v27; // r8d
  __int64 v28; // r14
  int v29; // ebx
  int v30; // ebx
  int *v31; // r9
  hkpStiffSpringChainData::ConstraintInfo *m_data; // rdx
  __m128 v33; // xmm1
  __m128 v34; // xmm1
  hkVector4f v35; // xmm2
  __m128 v36; // xmm5
  __m128 v37; // xmm1
  __m128 v38; // xmm4
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm1
  __m128 v42; // xmm0
  __int64 v43; // [rsp+50h] [rbp-A8h]
  hkp1Lin2AngJacobian *v44; // [rsp+58h] [rbp-A0h]
  __int64 v45; // [rsp+60h] [rbp-98h]
  hkpConstraintQueryIn in; // [rsp+70h] [rbp-88h] BYREF
  int v47; // [rsp+100h] [rbp+8h]
  int v48; // [rsp+104h] [rbp+Ch]
  int v49; // [rsp+108h] [rbp+10h] BYREF
  hkp1dLinearBilateralConstraintInfo info; // [rsp+188h] [rbp+90h] BYREF
  hkpStiffSpringChainData *retaddr; // [rsp+238h] [rbp+140h]
  int v54; // [rsp+250h] [rbp+158h]

  v3 = out;
  v4 = inNotValid;
  v5 = this;
  ((void (__fastcall *)(hkpStiffSpringChainData *, hkpConstraintQueryOut *, struct hkpConstraintRuntime *, __int64))v4[1].m_atoms.m_bridgeAtom.m_buildJacobianFunc)(
    v4,
    out,
    out->m_constraintRuntime.m_storage,
    8i64);
  v48 = -2147483616;
  v6 = 0i64;
  v7 = v4->hkReferencedObject;
  v8 = *(_OWORD *)&v4->m_userData;
  v47 = 0;
  *(hkReferencedObject *)&in.m_subStepDeltaTime.m_storage = v7;
  v9 = *(_OWORD *)&v4->m_atoms.m_bridgeAtom.m_type.m_storage;
  *(_OWORD *)&in.m_subStepInvDeltaTime.m_storage = v8;
  in.m_beginConstraints = (void (__fastcall *)(hkpConstraintQueryIn *, hkpConstraintQueryOut *, hkpSolverResults *, int))&v49;
  v10 = *(_OWORD *)&v4->m_atoms.m_bridgeAtom.m_constraintData;
  *(_OWORD *)&in.m_invNumStepsTimesMicroSteps.m_storage = v9;
  *(hkArray<hkpStiffSpringChainData::ConstraintInfo,hkContainerHeapAllocator> *)&in.m_bodyB.m_storage = v4->m_infos;
  v11 = v4[1].hkReferencedObject;
  *(_OWORD *)&in.m_frictionRhsFactor.m_storage = v10;
  v12 = *(_OWORD *)&v4->m_tau;
  *(hkReferencedObject *)(&in.m_damping + 1) = v11;
  v13 = *(_OWORD *)&v4[1].m_atoms.m_bridgeAtom.m_type.m_storage;
  *(_OWORD *)&in.m_transformB.m_storage = v12;
  v14 = *(_OWORD *)&v4[1].m_userData;
  *(_OWORD *)&in.m_violatedConstraints.m_storage = v13;
  v3->m_constraintRuntime.m_storage = 0i64;
  m_userData = v4[1].m_userData;
  in.m_constraintInstance.m_storage = (hkpConstraintInstance *)*((_QWORD *)&v14 + 1);
  in.m_maxConstraintViolationSqrd.m_real.m128_u64[1] = 0i64;
  v16 = *(__int64 **)(m_userData + 112);
  v17 = *(_DWORD *)(m_userData + 120) - 1;
  v54 = v17;
  v18 = *v16;
  v19 = *(unsigned int *)(*v16 + 240);
  accumBase = (hkpVelocityAccumulator *)((char *)v4->m_atoms.m_bridgeAtom.m_constraintData
                                       - *(_DWORD *)(*(_QWORD *)(m_userData + 40) + 240i64));
  v47 = 1;
  LODWORD(in.hkpConstraintQueryStepInfo::m_maxConstraintViolationSqrd.m_storage) = (_DWORD)FLOAT_1_0;
  in.m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)accumBase + v19);
  v49 = v19;
  v21 = (hkTransformf *)(v18 + 368);
  m_storage = v3->m_jacobianSchemas.m_storage;
  in.m_transformA.m_storage = v21;
  in.m_invNumStepsTimesMicroSteps.m_storage = in.m_subStepInvDeltaTime.m_storage;
  jacobiansEnd = hkJacobianStiffSpringChainSchema_getJacobians(m_storage);
  v45 = v17;
  if ( v17 > 0 )
  {
    v24 = 0i64;
    v25 = jacobiansEnd;
    v43 = 0i64;
    do
    {
      p_m_quad = &in.m_transformA.m_storage->m_rotation.m_col0.m_quad;
      v27 = v47;
      *(_QWORD *)&in.m_frictionRhsFactor.m_storage = in.m_bodyA.m_storage;
      in.m_bodyB.m_storage = (hkpVelocityAccumulator *)in.m_transformA.m_storage;
      v28 = *(_QWORD *)(*(_QWORD *)(m_userData + 112) + 8 * v6 + 8);
      v29 = (_DWORD)accumBase + *(_DWORD *)(v28 + 240);
      in.m_bodyA.m_storage = (hkpVelocityAccumulator *)((char *)accumBase + *(unsigned int *)(v28 + 240));
      v30 = v29 - (_DWORD)accumBase;
      if ( v47 == (v48 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&in.m_beginConstraints, 4);
        p_m_quad = (__m128 *)in.m_bodyB.m_storage;
        v27 = v47;
        v24 = v43;
      }
      v31 = (int *)((char *)in.m_beginConstraints + 4 * v27);
      if ( v31 )
      {
        *v31 = v30;
        p_m_quad = (__m128 *)in.m_bodyB.m_storage;
        v27 = v47;
      }
      m_data = retaddr->m_infos.m_data;
      v47 = v27 + 1;
      in.m_transformA.m_storage = (hkTransformf *)(v28 + 368);
      v33 = *(__m128 *)((char *)&m_data->m_pivotInA.m_quad + v24);
      info.m_pivotA.m_quad = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(_mm_shuffle_ps(v33, v33, 85), p_m_quad[1]),
                                   _mm_mul_ps(_mm_shuffle_ps(v33, v33, 0), *p_m_quad)),
                                 _mm_mul_ps(_mm_shuffle_ps(v33, v33, 170), p_m_quad[2])),
                               p_m_quad[3]);
      v34 = *(__m128 *)((char *)&m_data->m_pivotInB.m_quad + v24);
      v35.m_quad = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), *(__m128 *)(v28 + 384)),
                         _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), *(__m128 *)(v28 + 368))),
                       _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), *(__m128 *)(v28 + 400))),
                     *(__m128 *)(v28 + 416));
      v36 = _mm_sub_ps(info.m_pivotA.m_quad, v35.m_quad);
      info.m_pivotB = (hkVector4f)v35.m_quad;
      v37 = _mm_mul_ps(v36, v36);
      v38 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
              _mm_shuffle_ps(v37, v37, 170));
      v39 = _mm_rsqrt_ps(v38);
      v40 = _mm_andnot_ps(
              _mm_cmple_ps(v38, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                _mm_mul_ps(v39, *(__m128 *)_xmm)));
      v41 = _mm_mul_ps(v40, v38);
      v42 = _mm_cmplt_ps((__m128)0i64, v41);
      info.m_constrainedDofW.m_quad = _mm_or_ps(
                                        _mm_and_ps(_mm_mul_ps(v36, v40), v42),
                                        _mm_andnot_ps(v42, transform.m_quad));
      hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(
        &info,
        &in,
        v25,
        *(float *)((char *)&m_data->m_springLength + v24) - fmax(v41.m128_f32[0], 0.0));
      ++v6;
      v24 = v43 + 48;
      ++v25;
      v43 += 48i64;
    }
    while ( v6 < v45 );
    v4 = this;
    v5 = retaddr;
    v17 = v54;
    v44 = v25;
    v3 = (hkpConstraintQueryOut *)inNotValid;
    jacobiansEnd = v44;
  }
  hkStiffSpringChainBuildJacobian(
    v17,
    v5->m_tau,
    v5->m_damping,
    v5->m_cfm,
    (hkpVelocityAccumulatorOffset *)in.m_beginConstraints,
    accumBase,
    jacobiansEnd,
    (hkpConstraintQueryIn *)v4,
    v3);
  v47 = 0;
  if ( v48 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, in.m_beginConstraints, 4 * v48);
}tor::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, in.m_beginConstraints, 4 * v48);
}

